#include "D2ObjectIds.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2MonModes.h"
#include "D2PlayerModes.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2ItemsWorld.h"
#include "D2Drlg.h"
#include "D2GameObjs.h"
#include "D2GameAux.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2GameRecords.h"
#include "D2LanguageNames.h"
#include "D2AiCallbackArgs.h"

struct D2MonStatsTxt;

struct D2LevelsTxt;

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0

int __fastcall AIUTIL_HasClearApproachToTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005DC640

D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

struct D2GameStrc;

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2AiParamStrc;

struct D2SkillsTxt;

struct D2StaticPathStrc;

struct D2MonsterDataStrc;

struct D2MapAIPathPositionStrc;

struct D2AiCmdStrc;

union D2SeedStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void __fastcall MONSTERMODE_SetVelocityParams(D2AiParamStrc* pAiParam, int a2, int nVel, unsigned char a4); // 0x005A6260

void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190

int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90

int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20

void __fastcall sub_005F6630_InitAiParamsFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005F6630

D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0

D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0

bool __fastcall AITHINK_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam); // 0x005E6800

unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __fastcall sub_0045C390_SeedRollLimited(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall AITHINK_AssasinSentryHasLostTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int bDecreaseParam); // 0x005EA2B0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill); // 0x00644360

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID); // 0x00574A20

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall sub_005EABF0(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pUnit, int nSkillId, D2Unk005EAD50ArgStrc* pArg); // 0x005EABF0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId); // 0x00645040

int __stdcall SKILLS_GetShiftedManaCosts(int nSkillId, int nSkillLevel); // 0x006459F0

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

struct D2ModeChangeStrc;

enum
{
    UNIT_ALIGNMENT_EVIL = 0,
    UNIT_ALIGNMENT_GOOD = 2,
};

enum
{
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
};

enum
{
    MONTYPEFLAG_UNIQUE = 0x08,
    MONTYPEFLAG_CHAMPION = 0x04,
};

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall AITHINK_IsTargetKillableByShadowMaster(D2UnitStrc* a1, D2UnitStrc* a2); // 0x005EB650

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId); // 0x005EAB20

int __fastcall AITHINK_GetShadowMasterSkillLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nParam, int nSkillId); // 0x005EB420

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc* pUnit); // 0x00535BC0

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit); // 0x0058EE80

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190

int __fastcall AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nX, unsigned int nY); // 0x005DEE50

int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070

int __fastcall AIUTIL_IsGettingHit(D2UnitStrc* pUnit); // 0x005DD2B0

struct D2ActiveRoomStrc;

enum D2C_F42AiConstants
{

    AISPECIALSTATE_NONE = 0,
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_AITHINK = 2,

    UNITFLAG_NOTC = 0x00020000,
    UNITFLAG_NOXP = 0x04000000,

    STATE_BAALTOSTAIRS_INVIS = 0x92,
    MONSTATSFLAGINDEX_LUNDEAD = 11,
};

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

bool __fastcall AITHINK_ExecuteNpcAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);       // 0x005E6AE0

bool __fastcall AITHINK_ExecuteMapAiAction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E7080

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

void __fastcall AIGENERAL_FreeMinionList(D2UnitStrc* pUnit);                                                // 0x0058F160

void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* a2, void* a3, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*)); // 0x0058F380

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730

void __fastcall AITHINK_MinionCallback_CheckDead(D2UnitStrc* pUnit, void* a2, void* a3);                                        // 0x005E5710

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270

int __fastcall AITACTICS_WalkToTargetWithPathType13(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                // 0x00622C40

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730

D2UnitStrc* __fastcall AITACTICS_FindTargetOrIdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DE890

int __fastcall AITACTICS_RunToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED00

int __fastcall AITACTICS_WalkToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);       // 0x005DECA0

int __fastcall AITACTICS_WalkAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0

int __fastcall AITHINK_TryPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0

unsigned int __fastcall sub_005DC380(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                  // 0x005DC380

void __fastcall ACT5Q6_OpenWorldStoneChamber(D2GameStrc* pGame);                                            // 0x0058E600

int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00645460

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

void __stdcall sub_0063EE10_GetMonsterDirectionDelta(D2UnitStrc* pUnit, int* pX, int* pY);                  // 0x0063EE10

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

int __fastcall SUNITINACTIVE_IsDeadMonsterAt(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nIndex); // 0x005429B0

D2UnitStrc* __fastcall AITHINK_TargetCallback_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EF5E0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc* pUnit, int nX, int nY);             // 0x005DC480

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit);                                               // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

int __fastcall AIUTIL_HasClearMissilePath(D2UnitStrc* pUnit, D2UnitStrc* pTarget);             // 0x005DD290

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);

#pragma intrinsic(memcpy)

struct D2SkillStrc;

struct D2DynamicPathStrc;

extern const char gszAiThink4Source[]; // 0x006E3500

int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc*); // 0x005353F0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60

void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc*,D2PlayerCountBonusStrc*,D2ActiveRoomStrc*,D2UnitStrc*); // 0x00573930

unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*,D2UnitStrc*); // 0x005DC380

int __fastcall sub_005DD290_CheckAttack(D2UnitStrc*,D2UnitStrc*); // 0x005DD290

int __fastcall sub_005FD470(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005FD470

unsigned int __stdcall sub_006417F0_GetDistance(D2UnitStrc*,int,int); // 0x006417F0

int __stdcall PATH_GetY(D2DynamicPathStrc*); // 0x00648900

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

struct D2SkillListStrc;

extern "C" const char szAiThink4File[];                                                                     // 0x006E3500

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0

D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit);                           // 0x0055B7E0

int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);   // 0x005DED20

int __fastcall AITACTICS_RunAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DF140

D2UnitStrc* __fastcall AITHINK_TargetCallback_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005EB6D0

int __fastcall AITHINK_IsStateGroupActive(D2UnitStrc* pUnit, int nState);                              // 0x005EB7F0

int __fastcall AITHINK_UseShadowMasterSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int bCombat, D2UnitStrc* pTarget, int nX, int nY, D2AiTickParamStrc* pAiTickParam); // 0x005EB8B0

int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

int __stdcall STATES_CheckStateMaskPgsvOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A2B0

D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill);                                            // 0x006438F0

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList);                      // 0x00643910

enum D2C_ShadowMasterConstants
{
    COLLIDE_MISSILE_BARRIER = 4,
    SKILLSFLAGINDEX_PROGRESSIVE = 2,

    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_FREEZE = 12,

};

int __fastcall sub_005DC480_GetDistance(D2UnitStrc*,int,int); // 0x005DC480

struct D2StatListStrc;

#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))

int __fastcall ACT3Q7_GetWandererCoordinates(D2GameStrc* game,D2UnitStrc* unit,D2CoordStrc* coords); // 0x005BD0D0

void __fastcall ACT3Q7_CreateVileDogSpawnTimer(D2GameStrc* game,D2UnitStrc* unit); // 0x005BD4A0

int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc* game,D2UnitStrc* unit,int x,int y); // 0x005DED90

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

enum D2C_M81OverseerAi
{
    OVERSEER_AI_PARAM_RALLY_SPELL_TIMER = 0,
    OVERSEER_AI_PARAM_HEAL_CHANCE_PCT = 1,
    OVERSEER_AI_PARAM_WHIP_CHANCE_PCT = 2,
    OVERSEER_AI_PARAM_COMFORT_DISTANCE = 3,
    OVERSEER_AI_PARAM_COMFORT_ZONE = 4,
    OVERSEER_AI_PARAM_ATTACK_CHANCE_PCT = 5,
    OVERSEER_AI_PARAM_ATTACK_2_OR_1_CHANCE_PCT = 6,
};

void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00587900

int __fastcall AIUTIL_CheckIfMonsterUsesSkill(D2UnitStrc* pUnit, int nSkillId); // 0x005DD2D0

D2UnitStrc* __fastcall AITACTICS_GetTargetMinion(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DE830

int __fastcall AITACTICS_WalkToTargetWithRandomPathType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

D2UnitStrc* __fastcall AITHINK_TargetCallback_Overseer_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E26D0

extern const char gszAiThink4File[]; // 0x006E3500

void __fastcall ACT5Q4_OnNihlathakActivated(D2GameStrc*, D2UnitStrc*); // 0x0058BC40

void __fastcall AITACTICS_UseSkillInRange(D2UnitStrc* pUnit, int nRange, int nSkillId, int nMode); // 0x005DF850

D2UnitStrc* __fastcall SKILLS_FindCorpseNearTarget(D2UnitStrc*, D2UnitStrc*, int, int); // 0x0056E390

int __fastcall sub_6FC68350(int, D2ActiveRoomStrc*, int, int, int); // 0x005FD350

int __stdcall D2Common_11063(D2ActiveRoomStrc*, int); // 0x0063EC70

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed);

int __fastcall MISSILE_GetSkillMissileRange(int nSkillId, int nSkillLevel);                                   // 0x004CC7C0

D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30

#define MINIMUM(a,b) ((a) < (b) ? (a) : (b))

#pragma pack(push,1)

struct D2Packet8A
{
    unsigned char header;
    unsigned char type;
    int guid;
};

#pragma pack(pop)

int __fastcall ACT5Q2_FindPortal(D2GameStrc*,D2UnitStrc*,D2UnitStrc**); // 0x00588D60

int __fastcall ACT5Q2_CheckWussieCounters(D2GameStrc*,D2UnitStrc*); // 0x00588830

void __fastcall ACT5Q2_UpdateWussieCounters(D2GameStrc*,int,D2UnitStrc*); // 0x00588880

void __stdcall PATH_ClearPathingFlagAndPoints(D2DynamicPathStrc*); // 0x00648730

D2UnitStrc* __fastcall AITACTICS_FindNearbyPlayerOrSelf(D2GameStrc*,D2UnitStrc*,int*); // 0x005DDF20

int __fastcall ACT5Q2_IsMonsterNearby(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00588E10

void __fastcall ACT5Q2_SpawnRescuePortal(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x005888D0

void __fastcall TARGETS_InsertUnitNode(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990

void __fastcall ACT5Q2_OnWussieActivated(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00588DD0

extern const char gszAiThink4[]; // 0x006E3500

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0

void __fastcall sub_0053DFF0(D2ClientStrc*,D2Packet8A*); // 0x0053DFF0

struct Obj00648AD0;

struct D2PlayerDataStrc;

struct D2MonStats2Txt;

struct D2PetInfoStrc;

int __fastcall sub_005FD350_SpawnNearby(int nMonsterId, D2ActiveRoomStrc* pRoom, int nX, int nY, int a5); // 0x005FD350

int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000

D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E1720

void __fastcall AITHINK_UpdateSiegeMountPartner(D2UnitStrc* pUnit, D2UnitStrc* pTower); // 0x005E17E0

D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E2B70

void __fastcall AITHINK_MeleePet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E4830

void __fastcall AITHINK_UpdateNecroPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E4AC0

bool __fastcall AITHINK_SelectGenericSpawnClass(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pClassId); // 0x005E6020

bool __fastcall AITHINK_MapAiAction_WalkToPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition); // 0x005E6DE0

extern "C" const int gnDesertTurretIndices[64]; // 0x006E33E0

extern "C" const D2CoordStrc gaDesertTurretOffsets[8]; // 0x006E33A0

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

extern "C" void __stdcall PATH_SetTargetPos(Obj00648AD0* pObj, unsigned short wA, unsigned short wB); // 0x00648AD0

void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058ED10

int __fastcall PLAYERPETS_GetTotalPetCount(D2UnitStrc*); // 0x00574F40

int __stdcall D2Common_10095(D2ActiveRoomStrc*, int, int); // 0x0061B130

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10

unsigned int __stdcall PATH_GetFinalTargetX(D2DynamicPathStrc*); // 0x00648A20

unsigned int __stdcall PATH_GetFinalTargetY(D2DynamicPathStrc*); // 0x00648A30

D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc*, int); // 0x00574BD0

void __fastcall AITHINK_SelectHirelingAction(D2GameStrc*, D2UnitStrc*, int, int, D2UnitStrc*, D2SeedStrc*); // 0x005E4D30

int __fastcall ACT2Q4_IsHaremBlockerObjectOpened(D2GameStrc* pGame); // 0x0059AEC0

int __fastcall ACT2Q4_HasGuardMovedToEndPosition(D2GameStrc* pGame); // 0x0059B8B0

int __fastcall ACT2Q4_GetGuardCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord); // 0x0059B8F0

bool __fastcall AITHINK_HandleNpcProximityAndInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E68F0

D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0

void __fastcall AITHINK_Fn062_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);

void __fastcall AITHINK_SpecialState08_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam);

#define MON_FLAG 9

#define ATTACK_MODE 4

#define WALK_CHANCE 20

#define WALK_DISTANCE 3

#define IDLE_FRAMES 10

struct D2AiControlStrc;

struct D2MissilesTxt;

int __fastcall SKILLDESC_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

int __fastcall AITACTICS_WalkAroundTargetWithScaledDistance(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nScale); // 0x005DE6F0

int __fastcall AITHINK_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2); // 0x005ECBC0

void __fastcall AITHINK_Fn108_SpiritWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005ECEE0

void __fastcall AITHINK_Fn108_Fenris(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005ED2A0

enum D2C_M80TotemAi
{
    TOTEM_AI_PARAM_WALK_AWAY_CHANCE_PCT = 0,
    TOTEM_AI_PARAM_IGNORE_TARGET_CHANCE_PCT = 1,
    TOTEM_AI_PARAM_TELEPORT_TO_OWNER_DISTANCE = 2,
    TOTEM_AI_PARAM_FOLLOW_OWNER_DISTANCE = 3,
};

D2UnitStrc* __fastcall AITACTICS_FindTargetInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nMaxDistance); // 0x005DDE50

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

enum D2C_M230FallenAi
{
    FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT = 0,
    FALLEN_AI_PARAM_APPROACH_DISTANCE = 1,
    FALLEN_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT = 3,
};

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

extern "C" D2AiCmdStrc* __fastcall sub_0058EE80(D2UnitStrc* pUnit); // 0x0058EE80

int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530

enum D2C_M197ZakarumPriestAi
{
    ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT = 1,
    ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT = 2,
    ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT = 3,
    ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER = 4,
    ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE = 5,
};

int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80

enum D2C_SummonerAIParams
{
    SUMMONER_AI_PARAM_CAST_CHANCE_PCT = 0,
    SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT = 1,
    SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT = 2,
    SUMMONER_AI_PARAM_NOVA_TIMER = 3,
    SUMMONER_AI_PARAM_FIREWALL_TIMER = 4,
    SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT = 5,
    SUMMONER_AI_PARAM_NOVA_DISTANCE = 6,
    SUMMONER_AI_PARAM_MISSILE_DISTANCE = 7,
};

enum D2C_AiThink005F12A0
{
    AI_PARAM_WALK_CHANCE_PCT = 0,
    AI_PARAM_IDLE_FRAMES = 1,
    AI_PARAM_ATTACK_CHANCE_PCT = 2,
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00

enum D2C_M86FallenShamanAi
{
    FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT = 0,
    FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT = 1,
    FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT = 2,
    FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE = 3,
    FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE = 4,
};

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags);          // 0x005701B0

enum D2C_SuccubusAIParams
{
    SUCCUBUS_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    SUCCUBUS_AI_PARAM_APPROACH_CHANCE_PCT = 1,
    SUCCUBUS_AI_PARAM_CURSE_CHANCE_PCT = 2,
    SUCCUBUS_AI_PARAM_CURSE_RANGE = 3,
    SUCCUBUS_AI_PARAM_MELEE_STALL_DURATION = 4,
    SUCCUBUS_AI_PARAM_RANGED_STALL_DURATION = 5,
    SUCCUBUS_AI_PARAM_CURSE_LEVEL = 6,
    SUCCUBUS_AI_PARAM_CURSE2_LEVEL = 7,
};

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);                // 0x00625760

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D60

enum D2C_M236SuccubusWitchAi
{
    SUCCUBUSWITCH_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    SUCCUBUSWITCH_AI_PARAM_APPROACH_CHANCE_PCT = 1,
    SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT = 2,
    SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE = 3,
    SUCCUBUSWITCH_AI_PARAM_SHOOT_CHANCE_PCT = 4,
    SUCCUBUSWITCH_AI_PARAM_STALL_DURATION = 5,
    SUCCUBUSWITCH_AI_PARAM_AMPLIFY_DAMAGE_TARGET_HP_PCT = 6,
    SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT = 7,
};

int __fastcall AITACTICS_WalkToTargetCoordinatesNoSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEF30

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

int __fastcall ACT1Q4_UpdateCainPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005944B0

int __fastcall ACT5Q3_InitializeDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A940

void __fastcall ACT5Q3_OnDrehyaRescued(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A980

int gnNpcWalkSequenceCounter; // 0x0088CADC

int __fastcall AIUTIL_GetLifePercentage(D2UnitStrc* pUnit); // 0x005DD280

int __fastcall AITACTICS_WalkToTargetWithRandomPathType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nSteps, int a5); // 0x005DF7D0

enum D2C_ScarabAIParams
{
    SCARAB_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    SCARAB_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 1,
    SCARAB_AI_PARAM_STALL_DURATION = 2,
    SCARAB_AI_PARAM_JAB_CHANCE_PCT = 3,
    SCARAB_AI_PARAM_COMMAND_CHANCE_PCT = 4,
};

enum D2C_MummyAIParams
{
    MUMMY_AI_PARAM_AWAKE_DISTANCE = 0,
    MUMMY_AI_PARAM_APPROACH_CHANCE_PCT = 1,
    MUMMY_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    MUMMY_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
    MUMMY_AI_PARAM_STALL_DURATION = 4,
};

enum D2C_M86CorruptLancerAi
{
    CORRUPTLANCER_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    CORRUPTLANCER_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    CORRUPTLANCER_AI_PARAM_STALL_DURATION = 2,
    CORRUPTLANCER_AI_PARAM_RUN_CHANCE_PCT = 3,
    CORRUPTLANCER_AI_PARAM_ALWAYS_RUN_DISTANCE = 4,
    CORRUPTLANCER_AI_PARAM_USE_SKILL_1_CHANCE_PCT = 5,
    CORRUPTLANCER_AI_PARAM_USE_SKILL_2_CHANCE_PCT = 6,
    CORRUPTLANCER_AI_PARAM_USE_SKILL_3_CHANCE_PCT = 7,
};

enum D2C_M80SkeletonBowAi
{
    SKELETONBOW_AI_PARAM_SHOOT_CHANCE_PCT = 0,
    SKELETONBOW_AI_PARAM_STALL_DURATION = 1,
    SKELETONBOW_AI_PARAM_APPROACH_CHANCE_PCT = 2,
    SKELETONBOW_AI_PARAM_WALK_STEPS = 3,
    SKELETONBOW_AI_PARAM_TARGET_DISTANCE = 4,
};

int __fastcall D2GAME_AICORE_Escape_6FCD0560(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nMaxDistance, int bDeleteAiEventCallback); // 0x005DE6D0

enum D2C_M80FlyingScimitarAi
{
    FLYINGSCIMITAR_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    FLYINGSCIMITAR_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    FLYINGSCIMITAR_AI_PARAM_STALL_DURATION = 2,
    FLYINGSCIMITAR_AI_PARAM_CIRCLE_CHANCE_PCT = 3,
};

enum D2C_M150ZakarumZealotAi
{
    ACT_III = 2,
    QUESTSTATEFLAG_A3Q5 = 0x15,
    COLLIDE_MISSILE = 0x40,
    ZAKARUMZEALOT_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    ZAKARUMZEALOT_AI_PARAM_ATTACK2_CHANCE_PCT = 1,
    ZAKARUMZEALOT_AI_PARAM_HURT_PCT = 2,
    ZAKARUMZEALOT_AI_PARAM_RUN_CHANCE_PCT = 3,
};

enum D2C_M394IzualAi
{
    IZUAL_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT = 1,
    IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT = 2,
    IZUAL_AI_PARAM_NOVA_IN_MELEE_CHANCE_PCT = 3,
    IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS = 4,
    IZUAL_AI_PARAM_NUM_SWINGS = 5,
};

enum D2C_M144UberIzualAi
{
    COLLIDE_MASK_BARRIER = 6,
};

enum D2C_M388TentacleAi
{
    DEFAULT_FRAMES_PER_SECOND = 25,
    TENTACLE_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    TENTACLE_AI_PARAM_SUBMERGE_CHANCE_PCT = 1,
    TENTACLE_AI_PARAM_SUBMERGE_DURATION_SECONDS = 2,
    TENTACLE_AI_PARAM_EMERGE_DURATION_SECONDS = 3,
    TENTACLE_AI_PARAM_STALL_DURATION = 4,
    TENTACLE_AI_PARAM_ACTIVE_DISTANCE = 5,
};

#define AI_RollChance(pGame, pSeed, pMonStatsTxt, nParamId) ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, nParamId))

enum D2C_M80SkeletonMageAi
{
    SKELETONMAGE_AI_PARAM_SHOOT_CHANCE_PCT = 0,
    SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE = 1,
    SKELETONMAGE_AI_PARAM_APPROACH_CHANCE_PCT = 2,
    SKELETONMAGE_AI_PARAM_TOO_CLOSE_DISTANCE = 3,
    SKELETONMAGE_AI_PARAM_WALK_AWAY_CHANCE_PCT = 4,
    SKELETONMAGE_AI_PARAM_FIRE_DIST = 5,
    SKELETONMAGE_AI_PARAM_CIRCLE_CHANCE_PCT = 6,
    SKELETONMAGE_AI_PARAM_STALL_DURATION = 7,
};

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

int __fastcall MONSTERAI_IsInteractingWith(D2MonsterInteractStrc* pMonInteract, D2UnitStrc* pUnit); // 0x00572DE0

bool __fastcall AITHINK_ReturnToHomeIfTooFar(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, unsigned int nMaxDistance); // 0x005E6860

typedef bool (__fastcall* MAPAIACTIONFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition);

extern MAPAIACTIONFN gpfnMapAiActions[7]; // 0x00741D74

int __fastcall ACT3Q3_GetAltarCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord); // 0x005B9CA0

void __fastcall ACT3Q3_SetAltarMode(D2GameStrc* pGame); // 0x005B9CD0

int __fastcall ACT2Q4_IsJerhynPalaceActivated(D2GameStrc* pGame); // 0x0059F570

void __fastcall ACT2Q4_GetAndUpdatePalaceNpcState(D2GameStrc* pGame, D2UnitStrc* pUnit, int* a3, int* pIdle); // 0x0059F580

int __fastcall ACT2Q4_IsGuardMoving(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059B6E0

int __fastcall ACT3Q4_GoldenBirdBroughtToAlkor(D2GameStrc* pGame); // 0x005BAD20

void __fastcall ACT3Q4_ResetAlkor(D2GameStrc* pGame); // 0x005BAD40

int __fastcall ACT1Q4_GetCainPortalInTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00594360

void __fastcall ACT1Q4_OnCainInTownActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005945F0

void __fastcall ACT5Q4_AnyaOpenPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058BC80

void __fastcall ACT2Q6_AttachCompletionSoundToPlayers(D2GameStrc* pGame); // 0x0059C750

int __fastcall ACT2Q6_IsInRangeOfTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059DF50

int __fastcall ACT4Q1_IsAnyPlayerInRangeOfIzualGhost(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B43F0

void __fastcall ACT4Q1_AttachCompletionSoundToPlayers(D2GameStrc* pGame); // 0x005B4440

int __fastcall AITHINK_StopIfNotInteracting(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005E7350

void __fastcall AITHINK_Fn121_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005E2BD0

void __fastcall AITHINK_Fn137_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EFA90

struct D2MonRegDataStrc;

struct D2MonsterRegionStrc;

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210

int __fastcall AITACTICS_RunToTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x005DEDE0

int __fastcall AITHINK_UseSkillAtMapAiPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick); // 0x005E5B70

int __fastcall sub_00573520_GetLevelIdFromUnit(D2UnitStrc* pUnit); // 0x00573520

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** pMonReg, int nLevelId); // 0x00547BB0

#define GRISWOLD_WALK_FLAGS 7

struct Control;

struct MonStats;

struct Tick;

enum D2C_MegademonAIParams
{
    MEGADEMON_AI_PARAM_INFERNO_RANGED_CHANCE_PCT = 0,
    MEGADEMON_AI_PARAM_INFERNO_MELEE_CHANCE_PCT = 1,
    MEGADEMON_AI_PARAM_SWING_MELEE_CHANCE_PCT = 2,
    MEGADEMON_AI_PARAM_APPROACH_CHANCE_PCT = 3,
    MEGADEMON_AI_PARAM_CIRCLE_MELEE_CHANCE_PCT = 4,
    MEGADEMON_AI_PARAM_INFERNO_TIMER = 5,
};


struct Control
{
    char controlPad[0x18];
    int params[2];
};

struct MonStats
{
    char statsPad[0x170];
    short skills[8];
};

struct Tick
{
    Control* control;
    char pad4[0x18];
    MonStats* stats;
};

extern const int skill_choices[2][2]; // 0x006E34E0

Skill* __fastcall sub_006439B0(D2UnitStrc*,int,int); // 0x006439B0

#define PATHTYPE_TOWARD 2

#define AI_GetParamValue(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

struct D2TargetNodeStrc;

int __fastcall ACT5Q5_IsNotActivatable(D2GameStrc* pGame); // 0x0058CF90

int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiCmdStrc* pArgs); // 0x005E8530

extern "C" void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget); // 0x00648B90

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nType); // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

int __fastcall AITHINK_AreUnitsInSameLevel(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005EEB10

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

enum D2C_AncientBarb1AIParams
{
    ANCIENTBARB1_AI_PARAM_WHIRLWIND_DISTANCE = 0,
    ANCIENTBARB1_AI_PARAM_WHIRLWIND_CHANCE_PCT = 1,
    ANCIENTBARB1_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    ANCIENTBARB1_AI_PARAM_SKILL_REACH = 3,
};

void __fastcall AITHINK_AncientBarb1SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EEB70

void __fastcall AITHINK_AncientBarb2SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EEDA0

void __fastcall AITHINK_AncientBarb3SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EF010

int __fastcall EXCEPTIONS_ReleaseSymbols(int nArg); // 0x0040C720

void __fastcall CMDTBL_ResetKeyConfig(int nArg); // 0x00469A60

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

extern void* gpKeyConfigSliderCel; // 0x007C02BC

enum D2C_AiThink005F0A20
{
    AI_PARAM_ESCAPE_CHANCE_PCT = 0,
};

enum D2C_SandLeaperAIParams
{
    SANDLEAPER_AI_PARAM_LEAP_CHANCE_PCT = 0,
    SANDLEAPER_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    SANDLEAPER_AI_PARAM_APPROACH_CHANCE_PCT = 2,
    SANDLEAPER_AI_PARAM_CIRCLE_CHANCE_PCT = 3,
};

enum D2C_M188FetishBlowgunAi
{
    FETISHBLOWGUN_AI_PARAM_STAY_IN_RANGE = 0,
    FETISHBLOWGUN_AI_PARAM_RUN_AWAY_CHANCE_PCT = 1,
};

enum D2C_M230QuillRatAi
{
    QUILLRAT_AI_PARAM_ACTIVATE_DISTANCE = 0,
    QUILLRAT_AI_PARAM_SHOOT_CHANCE_PCT = 1,
    QUILLRAT_AI_PARAM_WALK_DISTANCE = 3,
};

enum D2C_M144SandMaggotAi
{
    SANDMAGGOT_AI_PARAM_LAY_CHANCE_PCT = 0,
    SANDMAGGOT_AI_PARAM_SPIT_CHANCE_PCT = 1,
    SANDMAGGOT_AI_PARAM_NUMBER_OF_EGGS = 2,
    SANDMAGGOT_AI_PARAM_MELEE_CHANCE_PCT = 3,
    SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME = 4,
};

enum D2C_M75ThornHulkConstants
{
    EVENTTYPE_ENDANIM = 1,
};

enum D2C_M408CorruptArcherAi
{
    CORRUPTARCHER_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    CORRUPTARCHER_AI_PARAM_SHOOT_CHANCE_PCT = 1,
    CORRUPTARCHER_AI_PARAM_STALL_DURATION = 2,
    CORRUPTARCHER_AI_PARAM_RUN_CHANCE_PCT = 3,
    CORRUPTARCHER_AI_PARAM_ALWAYS_RUN_DISTANCE = 4,
    CORRUPTARCHER_AI_PARAM_USE_SKILL_2_CHANCE_PCT = 5,
    CORRUPTARCHER_AI_PARAM_USE_SKILL_3_CHANCE_PCT = 6,
    CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE = 7,
};

enum D2C_M144BatDemonAi
{
    BATDEMON_AI_PARAM_HURT_PCT = 0,
    BATDEMON_AI_PARAM_DISENGAGE_ON_HIT_CHANCE_PCT = 1,
    BATDEMON_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    BATDEMON_AI_PARAM_LIGHTNING_OR_ATTACK_1_CHANCE_PCT = 3,
    BATDEMON_AI_PARAM_REGEN_ROOSTED = 4,
};

enum D2C_BaboonAIParams
{
    BABOON_AI_PARAM_HURT_PCT = 0,
    BABOON_AI_PARAM_CIRCLE_CHANCE_PCT = 1,
    BABOON_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
    BABOON_AI_PARAM_REGEN_BONUS = 4,
};

enum D2C_M86ReanimatedHordeAi
{
    UNITFLAG_ISVALIDTARGET = 0x00000008,
    REANIMATEDHORDE_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    REANIMATEDHORDE_AI_PARAM_MELEE_STALL_DURATION = 1,
    REANIMATEDHORDE_AI_PARAM_CHARGE_RANGE = 2,
    REANIMATEDHORDE_AI_PARAM_CHARGE_CHANCE_PCT = 3,
    REANIMATEDHORDE_AI_PARAM_FOLLOW_CHANCE_PCT = 4,
    REANIMATEDHORDE_AI_PARAM_WALK_FORWARD_CHANCE_PCT = 5,
    REANIMATEDHORDE_AI_PARAM_RANGED_STALL_DURATION = 6,
};

int __fastcall AITHINK_SpawnNpcPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pTick); // 0x005E77A0

void __fastcall ACT5Q3_UpdateStatusOnActivate(D2GameStrc* pGame); // 0x0058AA10

int __fastcall ACT1Q4_GetCainPortalOutsideTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoords); // 0x00594450

int __fastcall ACT5Q3_GetDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoords); // 0x0058A8D0

int __fastcall ACT5Q3_IsDrehyaNotRescued(D2GameStrc* pGame); // 0x0058A9F0

int __fastcall ACT1Q4_SpawnCainPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005943B0

int __fastcall ACT5Q3_SpawnDrehyaPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A820

struct D2UnitFindArgStrc;

enum D2C_BruteAIParams
{
    BRUTE_AI_PARAM_CIRCLE_CHANCE_PCT = 1,
    BRUTE_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    BRUTE_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT = 3,
};

enum D2C_M80SkeletonAi
{
    SKELETON_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    SKELETON_AI_PARAM_STALL_TIME = 1,
    SKELETON_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    SKELETON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
};

enum D2C_MosquitoAIParams
{
    MOSQUITO_AI_PARAM_MIN_SUCK_LOOP = 0,
    MOSQUITO_AI_PARAM_SUCK_LOOP_RNG = 1,
    MOSQUITO_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    MOSQUITO_AI_PARAM_SUCK_OR_ATTACK_CHANCE_PCT = 3,
    MOSQUITO_AI_PARAM_MAX_AMBIENT_LOOP = 4,
};

typedef int(__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit);

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

enum D2C_M172FetishShamanAi
{
    FETISHSHAMAN_AI_PARAM_HEAL_CHANCE_PCT = 0,
    FETISHSHAMAN_AI_PARAM_HEAL_CAPABILITY = 1,
    FETISHSHAMAN_AI_PARAM_HEAL_RANGE = 2,
    FETISHSHAMAN_AI_PARAM_CIRCLE_CHANCE_PCT = 3,
    FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE = 4,
};

struct D2RoomCoordListStrc;

extern const unsigned char gnPetDirections[8]; // 0x006E34F8

int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc*, D2ActiveRoomStrc*, D2RoomCoordListStrc*, int, int*, int*, int); // 0x0054DC40

typedef void (__fastcall* PetIterateCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

void __fastcall PLAYERPETS_IteratePets(D2GameStrc*, D2UnitStrc*, PetIterateCallback, void*); // 0x00574DE0

D2AiParamStrc* __fastcall sub_005A6190_GetAiParam(D2UnitStrc*); // 0x005A6190

int __fastcall AITACTICS_RunToTargetCoordinatesDeleteAiEvent(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DEEB0

int __fastcall AITACTICS_WanderToTarget(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF400

void __fastcall AITHINK_CountNearbyPets(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*); // 0x005E3900

D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc*, int, int); // 0x0061AD30

void __stdcall INVENTORY_GetDirectionDelta(unsigned char, unsigned int*, unsigned int*); // 0x0063E7E0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc*); // 0x0064C040

int __fastcall AITACTICS_RunCloseToTargetUnit(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF680

enum D2C_VileMotherAIParams
{
    VILEMOTHER_AI_PARAM_MAX_SPAWN = 0,
    VILEMOTHER_AI_PARAM_MAX_AT_ONCE = 1,
    VILEMOTHER_AI_PARAM_SPAWN_CHANCE_PCT = 2,
    VILEMOTHER_AI_PARAM_ATTACK_CHANCE_PCT = 3,
    VILEMOTHER_AI_PARAM_APPROACH_CHANCE_PCT = 4,
    VILEMOTHER_AI_PARAM_CIRCLE_CHANCE_PCT = 5,
    VILEMOTHER_AI_PARAM_STALL_DURATION = 6,
};

enum D2C_M81AbyssKnightAi
{
    ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_HP_PCT = 0,
    ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_CHANCE_PCT = 1,
    ABYSSKNIGHT_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    ABYSSKNIGHT_AI_PARAM_MELEE_STALL_DURATION = 3,
    ABYSSKNIGHT_AI_PARAM_NO_FIRE_DISTANCE = 4,
    ABYSSKNIGHT_AI_PARAM_FIRE_RECOVERY = 5,
    ABYSSKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT = 6,
    ABYSSKNIGHT_AI_PARAM_ACTIVE_DISTANCE = 7,
};

enum D2C_M84QuillMotherAi
{
    QUILLMOTHER_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    QUILLMOTHER_AI_PARAM_APPROACH_CHANCE_PCT = 1,
    QUILLMOTHER_AI_PARAM_MELEE_STALL_DURATION = 2,
    QUILLMOTHER_AI_PARAM_IDLE_STALL_DURATION = 3,
};

extern const unsigned char gnGargoyleTrapDirectionMap[]; // 0x006E3540

extern const unsigned char gnGargoyleTrapDirectionAxis[]; // 0x006E353C

struct D2CoordListStrc;

extern D2DataTablesStrc* gpDataTables; // 0x00744304

extern const unsigned char gnPetMoveDirections[]; // 0x006E34F0

int __fastcall sub_0054DC40_FindSpawnCoordinates(D2GameStrc*, D2ActiveRoomStrc*, D2CoordListStrc*, int, int*, int*, int); // 0x0054DC40

D2AiControlStrc* __fastcall sub_005A6190_GetAiControl(D2UnitStrc*); // 0x005A6190

void __fastcall sub_005A6260_SetAiControl(D2AiControlStrc*, int, int, int); // 0x005A6260

D2CoordListStrc* __stdcall sub_0061AD30_GetCoordList(D2ActiveRoomStrc*,int,int); // 0x0061AD30

D2CoordListStrc* __stdcall sub_0061B130_GetCoordList(D2ActiveRoomStrc*,int,int); // 0x0061B130

int __stdcall PATH_GetX(D2DynamicPathStrc*); // 0x00648A20

#define SKILLSFLAGINDEX_AURA 5

enum D2C_M80PantherJavelinAi
{
    PANTHERJAVELIN_AI_PARAM_APPROACH_CHANCE_PCT = 0,
    PANTHERJAVELIN_AI_PARAM_THROW_CHANCE_PCT = 1,
    PANTHERJAVELIN_AI_PARAM_GROUP_DISTANCE = 2,
    PANTHERJAVELIN_AI_PARAM_WALK_AWAY_CHANCE_PCT = 3,
    PANTHERJAVELIN_AI_PARAM_STALL_DURATION = 4,
    PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE = 5,
};

enum D2C_M80SiegeBeastAi
{
    SIEGEBEAST_AI_PARAM_CALL_IMP_DISTANCE = 0,
    SIEGEBEAST_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    SIEGEBEAST_AI_PARAM_STAMP_MELEE_CHANCE_PCT = 2,
    SIEGEBEAST_AI_PARAM_MELEE_STALL_DURATION = 3,
    SIEGEBEAST_AI_PARAM_STOMP_RANGED_CHANCE_PCT = 4,
    SIEGEBEAST_AI_PARAM_CHARGE_CHANCE_PCT = 5,
    SIEGEBEAST_AI_PARAM_CHARGE_VELOCITY = 6,
};

#define AI_MAX(a, b) ((a) > (b) ? (a) : (b))

#define AI_MIN(a, b) ((a) < (b) ? (a) : (b))

void __fastcall MONSTERAI_ClearTargetOverride(D2UnitStrc* pUnit);                                           // 0x00573120

enum D2C_P11AiConstants
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};

int __fastcall sub_005541B0_IsDead(D2UnitStrc* pUnit); // 0x005541B0

D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nRange); // 0x005D2F80

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

void __fastcall sub_005DEC80_Walk(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSteps); // 0x005DEC80

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

#define ROLL() ((int)SEED_RollLimitedRandomNumber(pSeed, 100))


enum D2C_CorruptRogueAIParams
{
    CORRUPTROGUE_AI_PARAM_APPROACH = 0,
    CORRUPTROGUE_AI_PARAM_STALL_DURATION = 1,
    CORRUPTROGUE_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    CORRUPTROGUE_AI_PARAM_RUN_VELOCITY = 3,
    CORRUPTROGUE_AI_PARAM_RUN_CHANCE_PCT = 4,
};

enum D2C_M408OblivionKnightAi
{
    OBLIVIONKNIGHT_AI_PARAM_FLEE_RANGE = 0,
    OBLIVIONKNIGHT_AI_PARAM_ENGAGE_RANGE = 1,
    OBLIVIONKNIGHT_AI_PARAM_CURSE_TIMER = 2,
    OBLIVIONKNIGHT_AI_PARAM_CURSE_CHANCE_PCT = 3,
    OBLIVIONKNIGHT_AI_PARAM_SHOOT_CHANCE_PCT = 4,
    OBLIVIONKNIGHT_AI_PARAM_BONESPIRIT_CHANCE_PCT = 5,
    OBLIVIONKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT = 6,
    OBLIVIONKNIGHT_AI_PARAM_APPROACH_DISTANCE = 7,
};

enum D2C_M422FingerMageAi
{
    FINGERMAGE_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    FINGERMAGE_AI_PARAM_CAST_CHANCE_PCT = 1,
    FINGERMAGE_AI_PARAM_FLEE_LIFE_PCT = 2,
    FINGERMAGE_AI_PARAM_ESCAPE_LIFE_PCT = 3,
    FINGERMAGE_AI_PARAM_CAST_RANGE = 4,
    FINGERMAGE_AI_PARAM_FLEE_TICKS = 5,
    FINGERMAGE_AI_PARAM_APPROACH_RANGE = 6,
    FINGERMAGE_AI_PARAM_IDLE_FRAMES = 7,
};

extern D2CoordStrc gaHighPriestSkillOffsets[]; // 0x006E337C

D2UnitStrc* __fastcall AITHINK_TargetCallback_HighPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005E0430

static D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

inline void AITHINK_IdleInline_005E17E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

inline short AI_GetParamValue_005E17E0(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00

static D2SkillsTxt* AITHINK_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static D2MonStatsTxt* AITHINK_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

inline int ValidateMonsterId(int nId)
{
    if (nId < 0 || nId >= gpDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nId;
}

// 0x005E0160
void __fastcall AITHINK_Fn082_InvisoSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
        pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
    if (nDistance <= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pAiControl->dwAiParam[1] <= 0)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return;
        }
        if (pAiControl->dwAiParam[0] <= pGame->dwGameFrame)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            int nMonsterId = D2Common_11063(pRoom, ValidateMonsterId(96));
            int nX;
            int nY;
            if (MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nMonsterId, &nX, &nY, 0))
            {
                if (D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, 2, 0x42))
                {
                    --pAiControl->dwAiParam[1];
                    pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
                }
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

static inline int MONSTERS_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

// 0x005E0260
void __fastcall AITHINK_Fn083_MosquitoNest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->nTargetDistance <= AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        if (pAiControl->dwAiParam[1] > AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            if (pUnit)
            {
                pUnit->dwFlags |= UNITFLAG_NOTC;
            }

            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[0]
            && sub_005FD350_SpawnNearby(MONSTERS_ValidateMonsterId(MONSTER_SUCKERNEST1), UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, 2);
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005E0390
void __fastcall AITHINK_InitializeBoneWallLifetime(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->nSkill[0] > 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = AITHINK_GetSkillsTxtRecordInline(pMonStatsTxtRecord->nSkill[0]);
        pAiControl->dwAiParam[0] = (!pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[1]) + pGame->dwGameFrame;
    }
}

// 0x005E0400
void __fastcall AITHINK_Fn084_BoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (pAiTickParam->pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005E0430
D2UnitStrc* __fastcall AITHINK_TargetCallback_HighPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2HighPriestAiCallbackArgStrc* pArg = (D2HighPriestAiCallbackArgStrc*)pCallbackArg;
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || MONSTERS_IsDead(pTarget) || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pTarget);
    if (nLifePercentage > 75 || nLifePercentage >= pArg->nLifePercentage)
    {
        return 0;
    }

    pArg->nLifePercentage = nLifePercentage;
    pArg->pTarget = pTarget;
    return 0;
}

// 0x005E0490
void __fastcall AITHINK_Fn085_HighPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0]) {
        if (bCombat) {
            if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 0)) {
                pAiControl->dwAiParam[0] = 1;
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 6, 1);
            return;
        }
        if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1]
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1)) {
            D2HighPriestAiCallbackArgStrc tArg;
            tArg.pTarget = 0;
            tArg.nLifePercentage = 75;
            tArg.nMaxDistance = 2500;
            AIUTIL_FindTargetWithCallback(pGame, pUnit, &tArg, AITHINK_TargetCallback_HighPriest, 1);
            if (tArg.pTarget) {
                pAiControl->dwAiParam[1] = AI_PARAM(pGame, pMonStatsTxt, 2) + pGame->dwGameFrame;
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], tArg.pTarget, 0, 0);
                return;
            }
        }
        if (pMonStatsTxt->nSkill[0] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nDistance < AI_PARAM(pGame, pMonStatsTxt, 7)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 3)) {
            int nIndex = sub_00472210_SeedRollMasked(pSeed, 4);
            int nX = CLIENTS_GetUnitX(pTarget) + gaHighPriestSkillOffsets[nIndex].nX;
            int nY = CLIENTS_GetUnitY(pTarget) + gaHighPriestSkillOffsets[nIndex].nY;
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + 100;
            return;
        }
        if (AI_PARAM(pGame, pMonStatsTxt, 4) > 0 && pMonStatsTxt->wMissiles[2] > 0) {
            D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pMonStatsTxt->wMissiles[2]);
            if (pMissilesTxtRecord && nDistance < pMissilesTxtRecord->wRange - 2 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 4)) {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, pTarget);
                return;
            }
        }
        if (AI_ROLL_PERCENT(pSeed) < 80) {
            if (nDistance > AI_PARAM(pGame, pMonStatsTxt, 7)) {
                AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 6);
                return;
            }
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
            return;
        }
    }
    pAiControl->dwAiParam[0] = 1;
    if (bCombat) {
        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 6)) {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, pTarget);
            return;
        }
        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 5)) {
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 6, 1);
            pAiControl->dwAiParam[0] = 0;
            return;
        }
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 90) {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (nDistance < 6 && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 6)) {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, pTarget);
        return;
    }
    if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 5)) {
        pAiControl->dwAiParam[0] = 0;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (AI_ROLL_PERCENT(pSeed) < 70) {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_WalkCloseToUnit(pGame, pUnit, 12);
}

static short AITHINK_GetParam_Desert(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
}

static inline int GetXInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int GetYInl_Desert(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E0980
void __fastcall AITHINK_Fn094_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
        pAiControl->dwAiParam[2] = 0;
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (nTargetDistance > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 3))
    {
        if (pAiControl->dwAiParam[1] > 0)
        {
            --pAiControl->dwAiParam[1];
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    const int nTargetX = GetXInl_Desert(pTarget);
    const int nTargetY = GetYInl_Desert(pTarget);
    const int nUnitX = GetXInl_Desert(pUnit);
    const int nUnitY = GetYInl_Desert(pUnit);
    const int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pUnit, nTargetX, nTargetY);
    const int nIndex1 = pAiControl->dwAiParam[2] % 8;
    const int nIndex2 = INVENTORY_GetEightWayDirection(nDirection) % 8;
    pAiControl->dwAiParam[2] = gnDesertTurretIndices[nIndex1 + 8 * nIndex2];

    const int nSpread = AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 4);
    const int nX = nUnitX + nSpread * gaDesertTurretOffsets[pAiControl->dwAiParam[2]].nX;
    const int nY = nUnitY + nSpread * gaDesertTurretOffsets[pAiControl->dwAiParam[2]].nY;

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);

    if (pMonStatsTxt->nSkill[0] >= 0 && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, nX, nY)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nX, nY);
        PATH_SetTargetPos((Obj00648AD0*)pUnit->pDynamicPath, nX, nY);

        ++pAiControl->dwAiParam[1];

        if (pAiControl->dwAiParam[1] > AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 1))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 2);
            pAiControl->dwAiParam[1] = 0;
        }
        else
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AITHINK_GetParam_Desert(pGame, pMonStatsTxt, 0);
        }
        return;
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        --pAiControl->dwAiParam[1];
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static inline unsigned int SEED_RollPercentage(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const uint64_t lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed % 100;
}

static inline int SEED_RollPercentage_005E0C80(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005E0C80
void __fastcall AITHINK_Fn089_Megademon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    int nSkillLevel = 0;
    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pMonStatsTxt->nSkill[0], -1);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        }
    }

    if (nSkillLevel <= 0)
    {
        nSkillLevel = 1;
    }

    const int bInferno = STATES_CheckState(pUnit, STATE_INFERNO);
    if (pMonStatsTxt->nSkill[0] >= 0 && !bCombat && nTargetDistance < nSkillLevel && !bInferno)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            const int nDifficulty = pGame->nDifficulty;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < pMonStatsTxt->wAiParam[MEGADEMON_AI_PARAM_INFERNO_RANGED_CHANCE_PCT][nDifficulty])
            {
                pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[MEGADEMON_AI_PARAM_INFERNO_TIMER][nDifficulty];
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }
        }
    }
    else
    {
        if (bInferno)
        {
            STATES_ToggleState(pUnit, STATE_INFERNO, 0);
        }

        if (bCombat)
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[0]
                && SEED_RollPercentage_005E0C80(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_INFERNO_MELEE_CHANCE_PCT))
            {
                pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_INFERNO_TIMER);
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }

            if (SEED_RollPercentage_005E0C80(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_SWING_MELEE_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            if (SEED_RollPercentage_005E0C80(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_CIRCLE_MELEE_CHANCE_PCT))
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }
    }

    if (SEED_RollPercentage_005E0C80(pSeed) < AI_GetParam(pGame, pMonStatsTxt, MEGADEMON_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E0F60
void __fastcall AITHINK_Fn093_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[1])
    {
        pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[3][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[1][pGame->nDifficulty];
        }
    }
    else
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        --pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] <= 0)
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[0][pGame->nDifficulty];
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[4][pGame->nDifficulty];
        }
        else
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[5][pGame->nDifficulty];
        }
    }
}

static inline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1080
void __fastcall AITHINK_Fn095_PantherJavelin(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2UnitStrc* pTargetUnit = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);

    if (nDistance < 8 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTickTarget, 16, 1);
        return;
    }

    if (nDistance > AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE) - 6 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTickTarget, 4);
        return;
    }

    if (!pTargetUnit || nDistance >= AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_DISTANCE))
    {
        D2PantherAiCallbackArgStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;

        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Panther, 1);

        if (arg.pTarget && arg.nDistance > AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_GROUP_DISTANCE))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, arg.pTarget, 7);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_STALL_DURATION));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_THROW_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTargetUnit);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PANTHERJAVELIN_AI_PARAM_STALL_DURATION));
}

static inline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E1250
void __fastcall AITHINK_Fn096_FetishBlowgun(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2AiCmdStrc* pCurrentAiCmd = (D2AiCmdStrc*)sub_0058EE80(pUnit);
    if (pCurrentAiCmd)
    {
        if (pCurrentAiCmd->nCmdParam[0] == 1)
        {
            D2UnitStrc* pCmdTarget = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[2], pCurrentAiCmd->nCmdParam[1]);
            if (pCmdTarget)
            {
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pCmdTarget);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }

        if (pCurrentAiCmd->nCmdParam[0] == 14)
        {
            D2UnitStrc* pCmdTarget = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[2], pCurrentAiCmd->nCmdParam[1]);
            if (pCmdTarget)
            {
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
                AITACTICS_SetAiParam(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCmdTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }

        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }

    if (!bCombat)
    {
        if (nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, FETISHBLOWGUN_AI_PARAM_STAY_IN_RANGE))
        {
            AITACTICS_SetAiParam(pUnit, 0, 50, 0);
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTarget, 6);
            return;
        }

        if (nTargetDistance >= 6)
        {
            goto LSelectTarget;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHBLOWGUN_AI_PARAM_RUN_AWAY_CHANCE_PCT))
    {
        pAiControl->dwAiParam[0] = 2;
    }

LSelectTarget:
    int nDistance;
    D2UnitStrc* pSelected = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

    switch (pAiControl->dwAiParam[0])
    {
    case 0:
        ++pAiControl->dwAiParam[1];
        if (pAiControl->dwAiParam[1] > (int)(AI_RollSeed(pSeed) % 3 + 3))
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = 0;
        }

        if (pSelected)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pSelected);
        }
        else
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
        }
        return;

    case 1:
        pAiControl->dwAiParam[0] = 0;
        pAiControl->dwAiParam[1] = 0;
        AITACTICS_SetAiParam(pUnit, 0, 50, 0);
        if (!AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 1))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        }
        return;

    case 2:
        if (nTargetDistance > 12)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) >= 20 || !AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 1))
            {
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
        else
        {
            AITACTICS_SetAiParam(pUnit, 2, 50, 0);
            if (!AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 14, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pSelected);
                pAiControl->dwAiParam[0] = 0;
                pAiControl->dwAiParam[1] = 0;
            }
        }
        return;

    default:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
}

// 0x005E1540
void __fastcall AITHINK_Fn114_ReanimatedHorde(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pUnit)
    {
        pUnit->dwFlags |= (UNITFLAG_ISVALIDTARGET | UNITFLAG_CANBEATTACKED | UNITFLAG_TARGETABLE);
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[1] >= 0 && AIUTIL_HasClearApproachToTarget(pUnit, pTarget)
        && nDistance < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_CHARGE_RANGE) && nDistance > 5
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_CHARGE_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_FOLLOW_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_WALK_FORWARD_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 4, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, REANIMATEDHORDE_AI_PARAM_RANGED_STALL_DURATION));
}

// 0x005E1720
D2UnitStrc* __fastcall AITHINK_TargetCallback_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2SiegeBeastTowerAiCallbackArgStrc* pArg = (D2SiegeBeastTowerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nImp = MONSTERS_ValidateMonsterIdInline(MONSTER_IMP1);
    if (CUNIT_GetMonsterBaseId(pTarget) != nImp)
    {
        return 0;
    }

    if (!STATLIST_AreUnitsAligned(pUnit, pTarget))
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (SUNIT_GetOwner(pGame, pUnit))
    {
        return 0;
    }

    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pTarget);
    if (pAiControl->dwAiParam[0] != -1)
    {
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    return pTarget;
}

// 0x005E17E0
void __fastcall AITHINK_UpdateSiegeMountPartner(D2UnitStrc* pUnit, D2UnitStrc* pBeast)
{
    D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnitInline(pUnit);
    if (pBeast)
    {
        D2UnitStrc* pCurrent = SUNIT_GetServerUnit(SUNIT_GetGameFromUnit(pUnit), UNIT_MONSTER, pAiControl->dwAiParam[0]);
        if (!pCurrent || AITHINK_GetSquaredDistance(pUnit, pBeast) <= AITHINK_GetSquaredDistance(pUnit, pCurrent))
        {
            pAiControl->dwAiParam[0] = pBeast->dwUnitId;
        }
    }
    else
    {
        pAiControl->dwAiParam[0] = -1;
    }
}

// 0x005E1860
void __fastcall AITHINK_Fn113_SiegeTower(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        if (pTarget)
        {
            D2SiegeBeastTowerAiCallbackArgStrc arg;
            arg.nMaxDistance = 400;
            arg.unk0x04 = 0;
            D2UnitStrc* pBeast = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_SiegeBeast, 1);
            if (pBeast)
            {
                AITHINK_UpdateSiegeMountPartner(pBeast, pUnit);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[0][pGame->nDifficulty]);
}

// 0x005E1900
void __fastcall AITHINK_Fn115_SiegeBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (MONSTERS_IsDead(pUnit))
    {
        return;
    }

    if (!pOwner && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
    {
        D2SiegeBeastTowerAiCallbackArgStrc arg;
        arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CALL_IMP_DISTANCE) * AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CALL_IMP_DISTANCE);
        D2UnitStrc* pTower = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_SiegeBeast, 1);
        if (pTower)
        {
            AITHINK_UpdateSiegeMountPartner(pTower, pUnit);
        }
    }

    if (bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_STAMP_MELEE_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
            return;
        }

        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTickTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < SKILLDESC_GetSkillParamFive(pMonStatsTxt->nSkill[0])
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_STOMP_RANGED_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
        return;
    }

    if (AIUTIL_HasClearApproachToTarget(pUnit, pTickTarget) && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CHARGE_CHANCE_PCT))
    {
        AITACTICS_SetAiParam(pUnit, 0, AI_MIN(AI_MAX(AI_PARAM(pGame, pMonStatsTxt, SIEGEBEAST_AI_PARAM_CHARGE_VELOCITY), 0), 127), 0);
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, 12, 0);
        return;
    }

    D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, 12, 0);
}

// 0x005E1B60
void __fastcall AITHINK_Fn116_Minion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStats = pAiTickParam->pMonstatsTxt;
    int bForced = 0;

    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentAiCmd)
    {
        if (pCurrentAiCmd->nCmdParam[0] == 1 && pCurrentAiCmd->nCmdParam[3] > pGame->dwGameFrame)
        {
            D2UnitStrc* pTargetUnit = SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[1], pCurrentAiCmd->nCmdParam[2]);
            if (pTargetUnit && !SUNIT_IsDead(pTargetUnit))
            {
                bForced = 1;
                if (pTarget != pTargetUnit)
                {
                    pTarget = pTargetUnit;
                    DRLG_UnitEdgeDistance(pUnit, pTargetUnit);
                    bCombat = UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0);
                }
            }
            else
            {
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            }
        }
        else
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }

    if (bCombat)
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[0][pGame->nDifficulty])
        {
            if ((int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[1][pGame->nDifficulty])
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][pGame->nDifficulty]);
        }
    }
    else
    {
        if (bForced || (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < pMonStats->wAiParam[2][pGame->nDifficulty])
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[3][pGame->nDifficulty]);
        }
    }
}

// 0x005E1D30
void __fastcall AITHINK_Fn117_SuicideMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (pAiControl->dwAiParam[0] && pGame->dwGameFrame > pAiControl->dwAiParam[0])
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 0, pTarget);
        return;
    }

    if (!pAiControl->dwAiParam[0])
    {
        if (bCombat)
        {
            pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, 4) + pGame->dwGameFrame;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
            return;
        }
        else
        {
            const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
            pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
            if ((int)((unsigned int)lSeed % 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

// 0x005E1E00
void __fastcall AITHINK_Fn118_Succubus(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20) && nDistance < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE_RANGE)
        && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[0] > 0 && UNITS_GetCurrentLifePercentage(pTarget) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE_LEVEL))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[1] > 0 && UNITS_GetCurrentLifePercentage(pUnit) <= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE2_LEVEL))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[2] > 0)
        {
            if (STATLIST_GetMaxLifeFromUnit(pTarget) > STATLIST_GetMaxManaFromUnit(pTarget) || !pTarget || pTarget->dwUnitType != UNIT_PLAYER)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] > 0 && pTarget && pTarget->dwUnitType == UNIT_PLAYER)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            return;
        }
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[4] > 0 && AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE2_LEVEL) > 0)
    {
        D2UnitStrc* pFoundTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
        if (pFoundTarget && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_CURSE2_LEVEL))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pFoundTarget, 0, 0);
            return;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUS_AI_PARAM_RANGED_STALL_DURATION));
}

// 0x005E2120
void __fastcall AITHINK_Fn119_SuccubusWitch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pTarget && !STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20) && nDistance < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE)
        && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[0] > 0 && UNITS_GetCurrentLifePercentage(pTarget) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_AMPLIFY_DAMAGE_TARGET_HP_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[1] > 0 && UNITS_GetCurrentLifePercentage(pUnit) <= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[2] > 0)
        {
            if (STATLIST_GetMaxLifeFromUnit(pTarget) > STATLIST_GetMaxManaFromUnit(pTarget) || pTarget->dwUnitType != UNIT_PLAYER)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] > 0 && pTarget->dwUnitType == UNIT_PLAYER)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            return;
        }
    }

    if (bCombat)
    {
        if (AI_ROLL_PERCENT(pSeed) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT)
            || !AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE), 1))
        {
            if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_STALL_DURATION));
            }
        }
    }
    else
    {
        if (pMonStatsTxt->nSkill[4] >= 0 && AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT) > 0
            && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            D2UnitStrc* pSkillTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
            if (pSkillTarget && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WEAKEN_MY_HP_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pSkillTarget, 0, 0);
                return;
            }
        }

        if (nDistance >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE)
            || AI_ROLL_PERCENT(pSeed) >= AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_WALK_AWAY_CHANCE_PCT)
            || !AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_COMFORT_DISTANCE), 1))
        {
            if (pMonStatsTxt->nSkill[4] < 0)
            {
                D2UnitStrc* pSkillTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
                if (pSkillTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_SHOOT_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pSkillTarget);
                    return;
                }
            }

            if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_APPROACH_CHANCE_PCT))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            }
            else
            {
                if (AI_ROLL_PERCENT(pSeed) >= 50 || !AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 1))
                {
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SUCCUBUSWITCH_AI_PARAM_STALL_DURATION));
                }
            }
        }
    }
}

static int AI_RollPercentage(D2UnitStrc* pUnit)
{
    return (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100;
}

static int AI_RollPercentage_005EFE20(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static __forceinline int AI_RollPercentage_005F0CD0(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static int AI_RollPercentage_005E2610(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005E2610
void __fastcall AITHINK_SpecialState14_AttackOrApproach(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage_005E2610(pUnit) < 95)
        {
            const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
            pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
            pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }
    }
    else
    {
        if (AI_RollPercentage_005E2610(pUnit) < 89)
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E26D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Overseer_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2NihlathakOverseerAiCallbackArgStrc* pArg = (D2NihlathakOverseerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(CUNIT_GetMonsterBaseId(pTarget)) != MONSTER_MINION1 || MONSTERS_IsDead(pTarget) || SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) || STATES_CheckState(pTarget, STATE_BLOODLUST))
    {
        return 0;
    }

    ++pArg->nCounter;

    if (!pArg->pTarget && AITHINK_GetSquaredDistance(pUnit, pTarget) <= pArg->nMaxDistance && UNITS_GetCurrentLifePercentage(pTarget) < pArg->nMaxLifePercentage)
    {
        pArg->pTarget = pTarget;
    }

    if (!pArg->pDistantTarget && AITHINK_GetSquaredDistance(pUnit, pTarget) <= pArg->nDistantMaxDistance && !MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE))
    {
        pArg->pDistantTarget = pTarget;
    }

    return 0;
}

// 0x005E27A0
void __fastcall AITHINK_Fn120_Overseer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nTargetDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    ACT5Q1_OnSiegeBossActivated(pGame, pUnit);

    D2UnitStrc* pMinion = AITACTICS_GetTargetMinion(pGame, pUnit);
    if (pMonStatsTxt->nSkill[0] >= 0 && AIUTIL_IsGettingHit(pUnit) && pGame->dwGameFrame > pAiControl->dwAiParam[0]
        && pMinion && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[0]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pMinion, 0, 0);
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_RALLY_SPELL_TIMER);
        return;
    }

    if (bCombat && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_ATTACK_2_OR_1_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    D2NihlathakOverseerAiCallbackArgStrc arg;
    arg.nMaxDistance = 576;
    arg.nDistantMaxDistance = 400;
    arg.nMaxLifePercentage = 50;
    arg.pTarget = 0;
    arg.pDistantTarget = 0;
    arg.nCounter = 0;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Overseer_Nihlathak, 1);

    D2UnitStrc* pHealTarget = arg.pTarget;
    D2UnitStrc* pDistantTarget = arg.pDistantTarget;
    int nCounter = arg.nCounter;

    if (pMonStatsTxt->nSkill[1] >= 0 && pHealTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_HEAL_CHANCE_PCT) && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[1]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pHealTarget, 0, 0);
        return;
    }

    if (pMonStatsTxt->nSkill[2] && pDistantTarget && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_WHIP_CHANCE_PCT)
        && STATLIST_GetUnitAlignment(pUnit) != UNIT_ALIGNMENT_GOOD && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[2]))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pDistantTarget, 0, 0);
        return;
    }

    if (nCounter)
    {
        if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE) - AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_ZONE))
        {
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE) - nTargetDistance, 0);
            return;
        }

        if (nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_ZONE) + AI_PARAM(pGame, pMonStatsTxt, OVERSEER_AI_PARAM_COMFORT_DISTANCE))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 5, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (AI_ROLL_PERCENT(pSeed) < 60)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E2B70
D2UnitStrc* __fastcall AITHINK_TargetCallback_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2MinionSpawnerAiCallbackArgStrc* pArg = (D2MinionSpawnerAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    switch (MONSTERS_ValidateMonsterIdInline(CUNIT_GetMonsterBaseId(pTarget)))
    {
    case MONSTER_MINION1:
    case MONSTER_SUICIDEMINION1:
        if (STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_EVIL)
        {
            ++pArg->nMinions;
        }
        break;
    }

    return 0;
}

static inline unsigned int SEED_RollRandomNumber_005E0C80(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x005E2BD0
void __fastcall AITHINK_Fn121_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        return;
    }

    if (pAiTickParam->nTargetDistance > pMonStatsTxt->wAiParam[3][pGame->nDifficulty])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    if (pGame->dwGameFrame < pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    D2MinionSpawnerAiCallbackArgStrc arg;
    arg.nMinions = 0;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_MinionSpawner, 1);
    if (pMonStatsTxt->nSkill[0] >= 0 && arg.nMinions < pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + pMonStatsTxt->wAiParam[2][pGame->nDifficulty];
        ++pAiControl->dwAiParam[1];
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
}

// 0x005E2CD0
void __fastcall AITHINK_InitializeMountedImpSkills(void* game,D2UnitStrc* unit,Tick* tick)
{
    int choice=SEED_RollRandomNumber_005E0C80(&unit->pSeed)&1;
    for (int i=0;i<2;++i) {
        choice=(choice+1)%2;
        if (sub_006439B0(unit,tick->stats->skills[skill_choices[choice][0]],-1)) {
            tick->control->params[0]=skill_choices[choice][0];
            tick->control->params[1]=skill_choices[choice][1];
            return;
        }
    }
    tick->control->params[0]=0;
    tick->control->params[1]=0;
}

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit_005E0160(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) return pUnit->pMonsterData->pAiControl;
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

// 0x005E2D80
void __fastcall AITHINK_SpecialState16_MountedImp(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (STATES_CheckState(pUnit, STATE_ATTACHED) && pOwner)
    {
        D2MonStatsTxt* pRecords[2] = { MONSTERMODE_GetMonStatsTxtRecord(492), MONSTERMODE_GetMonStatsTxtRecord(493) };
        D2SeedStrc* pSeed = &pUnit->pSeed;
        if (nTargetDistance <= 24 && !SUNIT_IsDead(pOwner) && !STATLIST_GetUnitAlignment(pOwner) && pAiControl->dwAiParam[1])
        {
            if (nTargetDistance < pRecords[1]->wAiParam[1][pGame->nDifficulty]
                && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < pRecords[1]->wAiParam[2][pGame->nDifficulty])
            {
                const int nSkillIndex = pAiTickParam->pAiControl->dwAiParam[1];
                const int bScatter = pAiTickParam->pAiControl->dwAiParam[2];
                CLIENTS_GetUnitX(pTarget);
                CLIENTS_GetUnitY(pTarget);
                if (bScatter)
                {
                    SEED_RollLimitedRandomNumber(pSeed, 2 * pRecords[1]->wAiParam[3][pGame->nDifficulty]);
                    SEED_RollLimitedRandomNumber(pSeed, 2 * pRecords[1]->wAiParam[3][pGame->nDifficulty]);
                }
                if (pRecords[0]->nSkill[nSkillIndex] >= 0)
                {
                    AITACTICS_UseSkill(pGame, pUnit, pRecords[0]->nSkillMode[nSkillIndex], pRecords[0]->nSkill[nSkillIndex], pTarget, 0, 0);
                    return;
                }
            }
            else if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, pTarget);
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }
        AITACTICS_UseSkillInRange(pUnit, pRecords[0]->wAiParam[1][pGame->nDifficulty], pRecords[0]->nSkill[0], (signed char)pRecords[0]->nSkillMode[0]);
        AIGENERAL_GetAiControlFromUnit_005E0160(pUnit)->dwAiParam[0] = -1;
        return;
    }
    AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit_005E0160(pUnit), 0);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005E2FD0
void __fastcall AITHINK_InitializeImpMountTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[0] = -1;
}

// 0x005E2FF0
void __fastcall AITHINK_Fn122_Imp(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2MonStatsTxt* pRecords[4] = { MONSTERMODE_GetMonStatsTxtRecord(492), MONSTERMODE_GetMonStatsTxtRecord(493), MONSTERMODE_GetMonStatsTxtRecord(494), MONSTERMODE_GetMonStatsTxtRecord(495) };
    if (pAiControl->dwAiParam[0] != -1 && !STATLIST_GetUnitAlignment(pUnit))
    {
        const int nOtherId = pAiControl->dwAiParam[0];
        D2UnitStrc* pOther = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nOtherId);
        if (!pOther || SUNIT_IsDead(pOther) || SUNIT_GetOwner(pGame, pOther) || STATLIST_GetUnitAlignment(pOther))
        {
            AIGENERAL_GetAiControlFromUnitInline(pUnit)->dwAiParam[0] = -1;
        }
        else
        {
            if (AITHINK_GetSquaredDistance(pUnit, pOther) > AI_PARAM(pGame, pRecords[1], 0) * AI_PARAM(pGame, pRecords[1], 0))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pOther, 0);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pOther, 0, 0);
                return;
            }
        }
    }

    if (bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && AIUTIL_GetLifePercentage(pUnit) < AI_PARAM(pGame, pRecords[0], 0))
        {
            AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pRecords[0], 1), pMonStatsTxt->nSkill[0], (signed char)pMonStatsTxt->nSkillMode[0]);
            return;
        }

        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pRecords[2], 1) && AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 5, 1))
        {
            return;
        }
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pRecords[0], 2))
    {
        AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pRecords[0], 1), pMonStatsTxt->nSkill[0], (signed char)pMonStatsTxt->nSkillMode[0]);
        return;
    }

    if (nDistance < AI_PARAM(pGame, pRecords[2], 0) && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pRecords[2], 1))
    {
        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 5, 0);
        return;
    }

    if (pMonStatsTxt->nSkill[3] >= 0)
    {
        D2UnitStrc* pSelected = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
        if (pSelected)
        {
            if (nDistance < AI_PARAM(pGame, pRecords[2], 2))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pRecords[2], 3))
                {
                    AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pSelected, 0, 0);
                    return;
                }
            }
            else if (nDistance < AI_PARAM(pGame, pRecords[3], 2))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pRecords[3], 3))
                {
                    AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pSelected, 0, 0);
                    return;
                }
            }
        }
    }

    if (AI_ROLL_PERCENT(pSeed) < 33)
    {
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 4);
        return;
    }

    if (AI_ROLL_PERCENT(pSeed) < 20)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static int AI_RollPercentage_005E0C80(D2UnitStrc* pUnit)
{
    return SEED_RollRandomNumber_005E0C80(&pUnit->pSeed) % 100;
}

// 0x005E34C0
void __fastcall AITHINK_Fn123_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (AI_RollPercentage_005E0C80(pUnit) < pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

static inline unsigned int SEED_RollRandomNumber_005E3530(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005E3530
void __fastcall AITHINK_Fn124_FrozenHorror(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nSkillLevel = 0;

    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        }
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < (nSkillLevel < 0 ? 0 : nSkillLevel)
        && (int)(SEED_RollRandomNumber_005E3530(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 2)
        && !STATES_CheckState(pUnit, STATE_INFERNO))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, 12, 0);
    }

    if (bCombat)
    {
        if ((int)(SEED_RollRandomNumber_005E3530(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
        return;
    }

    if ((int)(SEED_RollRandomNumber_005E3530(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

static inline unsigned int SEED_RollPercentageAgain(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const uint64_t lSeed = nHighSeed + 0x6AC690C5ui64 * nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed % 100;
}

// 0x005E36F0
void __fastcall AITHINK_Fn125_BloodLord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned int nLowSeed;
    unsigned int nHighSeed;
    if (bCombat)
    {
        if ((int)SEED_RollPercentage(pSeed, nLowSeed, nHighSeed) < AI_GetParamValue(pGame, pMonStatsTxtRecord, 0))
        {
            if ((int)SEED_RollPercentageAgain(pSeed, nLowSeed, nHighSeed) < AI_GetParamValue(pGame, pMonStatsTxtRecord, 2))
            {
                AITACTICS_UseSkill(pGame, pUnit, 5, pMonStatsTxtRecord->nSkill[0], pTarget, 0, 0);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParamValue(pGame, pMonStatsTxtRecord, 3));
        return;
    }
    else
    {
        if ((int)SEED_RollPercentage(pSeed, nLowSeed, nHighSeed) < AI_GetParamValue(pGame, pMonStatsTxtRecord, 1))
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParamValue(pGame, pMonStatsTxtRecord, 3));
    }
}

// 0x005E3840
void __fastcall AITHINK_Fn097_Spirit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
        return;
    }

    if (bCombat)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E3890
void __fastcall AITHINK_Fn098_Smith(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    nLifePercentage = nLifePercentage < 0 ? 0 : (nLifePercentage > 100 ? 100 : nLifePercentage);
    AITACTICS_SetAiParam(pUnit, 0, (100 - nLifePercentage) >> 1, 0);
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}

// 0x005E3900
void __fastcall AITHINK_CountNearbyPets(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2PetMoveStrc* pArg = (D2PetMoveStrc*)pCallbackArg;
    if (pArg->pUnit == pTarget)
    {
        return;
    }

    if ((int)AIUTIL_GetDistanceToCoordinates_FullUnitSize(pArg->pUnit, pTarget) > 1)
    {
        return;
    }

    pArg->nCounter += 1;
    pArg->pTarget = pTarget;
}

// 0x005E3930
int __fastcall AITHINK_PetMove(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nMode, int bRun, int nVelocity, int nDistance)
{
    D2SeedStrc* pSeed = &pPet->pSeed;
    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    const int nPlayerMode = pPlayer->dwAnimMode;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    const int nOwnerX = PATH_GetX(pPath);
    const int nOwnerY = PATH_GetFinalTargetY(pPath);
    switch (nMode)
    {
    case 0:
    {
        unsigned char nDirection = UNITS_GetDirectionToCoords(pPlayer,nOwnerX,nOwnerY);
        nDirection = INVENTORY_GetEightWayDirection(nDirection);
        D2CoordListStrc* pCoords = sub_0061B130_GetCoordList(UNITS_GetRoom(pPlayer),CLIENTS_GetUnitX(pPlayer),CLIENTS_GetUnitY(pPlayer));
        for (int i=0;i<8;++i)
        {
            int nDeltaX, nDeltaY;
            INVENTORY_GetDirectionDelta(gnPetMoveDirections[nDirection],(unsigned int*)&nDeltaX,(unsigned int*)&nDeltaY);
            const int nX=nOwnerX+8*nDeltaX;
            const int nY=nOwnerY+8*nDeltaY;
            if (sub_0061B130_GetCoordList(UNITS_GetRoom(pPlayer),nX,nY)==pCoords)
            {
                AITACTICS_SetAiParam(pPet,0,nVelocity,40);
                if (bRun)
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                else
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
            }
            nDirection=(nDirection+1)&7;
        }
        D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
        AITACTICS_WanderToTarget(pGame,pPet,pPlayer,4);
        return 1;
    }
    case 1:
    {
        if (nPlayerMode==2)
        {
            AITACTICS_SetAiParam(pPet,0,0,100);
            AITACTICS_WalkToTargetCoordinates(pGame,pPet,nOwnerX,nOwnerY);
            return 1;
        }
        int nVel=nVelocity ? nVelocity : SEED_RollLimitedRandomNumber(pSeed,15)+50;
        unsigned char nTrail=pPlayerData->nPositionHistoryIndex;
        D2AiControlStrc* pAi=sub_005A6190_GetAiControl(pPet);
        int bChanged=0;
        for (int i=0;i<20;++i)
        {
            if (!nTrail) nTrail=19; else --nTrail;
            const int nX=pPlayerData->pPositionHistory[nTrail].nX;
            const int nY=pPlayerData->pPositionHistory[nTrail].nY;
            if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pPet,nX,nY)>5)
            {
                AITACTICS_SetAiParam(pPet,0,nVel,100);
                if (bRun)
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                else
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
                AITACTICS_SetAiParam(pPet,15,nVel,100);
                if (bRun)
                {
                    if (AITACTICS_RunToTargetCoordinates(pGame,pPet,nX,nY)) return 1;
                }
                else
                {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                }
                D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
                if (!bChanged)
                {
                    bChanged=1;
                    sub_005A6260_SetAiControl(pAi,1,nVel,100);
                    if (bRun)
                    {
                        if (AITACTICS_RunToTargetCoordinates(pGame,pPet,nX,nY)) return 1;
                    }
                    else
                    {
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame,pPet,nX,nY)) return 1;
                    }
                    D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
                }
            }
        }
        int nDist=AIUTIL_GetDistanceToCoordinates_FullUnitSize(pPet,pPlayer)>>2;
        if (nDist<4) nDist=4;
        AITACTICS_SetAiParam(pPet,0,15,0);
        AITACTICS_WanderToTarget(pGame,pPet,pPlayer,nDist);
        return 1;
    }
    case 2:
        if ((int)SEED_RollLimitedRandomNumber(pSeed,100)<10)
        {
            if (AITACTICS_WanderToTarget(pGame,pPet,pPlayer,(unsigned char)SEED_RollLimitedRandomNumber(pSeed,3)+3)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            AITACTICS_SetAiParam(pPet,0,0,40);
            AITACTICS_WalkToTargetCoordinates(pGame,pPet,nOwnerX,nOwnerY);
            return 1;
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame,pPet,15);
            return 1;
        }
    case 3:
    {
        D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
        D2CoordListStrc* pCoords=sub_0061AD30_GetCoordList(pRoom,CLIENTS_GetUnitX(pPlayer),CLIENTS_GetUnitY(pPlayer));
        int nX;
        int nY;
        int nClass=363>=gpDataTables->nMonStatsTxtRecordCount ? -1 : 363;
        if (!sub_0054DC40_FindSpawnCoordinates(pGame,pRoom,pCoords,nClass,&nX,&nY,0)) return 0;
        D2ActiveRoomStrc* pNewRoom=sub_00463740_FindRoomAtPoint(pRoom,nX,nY);
        if (!pNewRoom || !SUNIT_TeleportUnit(pGame,pPet,pNewRoom,nX,nY,0,0)) return 0;
        UNITROOM_RefreshUnit(pPet);
        if (pPet) pPet->dwFlagEx|=0x10000;
        AITACTICS_IdleInNeutralMode(pGame,pPet,5);
        return 1;
    }
    case 4:
    {
        D2PetMoveStrc tArg;
        tArg.pUnit=pPet;
        tArg.nCounter=0;
        PLAYERPETS_IteratePets(pGame,pPlayer,AITHINK_CountNearbyPets,&tArg);
        if (tArg.nCounter>=1)
        {
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            if (AITACTICS_WalkAwayFromTarget(pGame,pPet,pPlayer,nDistance,1)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
            AITACTICS_WanderToTarget(pGame,pPet,pPlayer,nDistance);
            return 1;
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame,pPet,15);
            return 1;
        }
    }
    case 5:
        AITACTICS_SetAiParam(pPet,7,0,0);
        if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame,pPet,pPlayer,nDistance)) return 1;
        D2GAME_EVENTS_Delete_6FC34840(pGame,pPet,2,0);
        if (AITACTICS_WalkAwayFromTarget(pGame,pPet,pPlayer,nDistance,1)) return 1;
        AITACTICS_SetAiParam(pPet,0,0,40);
        AITACTICS_WalkToTargetCoordinates(pGame,pPet,nOwnerX,nOwnerY);
        return 1;
    }
    return 0;
}

static inline int GetMonsterId(int nId) {
    if (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount) return -1;
    return nId;
}

static inline int GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005E3EA0
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nMove, int bRun, int nVelocity, int nRange)
{
    D2UnitStrc* pUnit = pPet;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    int nMode = pOwner->dwAnimMode;
    unsigned int nTargetX = 0;
    unsigned int nTargetY = 0;
    D2PlayerDataStrc* pData = UNITS_GetPlayerData(pOwner);
    int nLastX = (int)PATH_GetFinalTargetX(pPath);
    int nLastY = (int)PATH_GetFinalTargetY(pPath);
    int nX = GetUnitX(pUnit);
    int nY = GetUnitY(pUnit);
    int nOwnerX = GetUnitX(pOwner);
    int nOwnerY = GetUnitY(pOwner);
    switch (nMove) {
    case 0:
        {
            unsigned char nDirection = UNITS_GetDirectionToCoords(pOwner, nLastX, nLastY);
            nDirection = INVENTORY_GetEightWayDirection(nDirection);
            int nCollision = D2Common_10095(UNITS_GetRoom(pOwner), CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
            for (int i = 0; i < 8; ++i) {
                unsigned int nOffsetX;
                unsigned int nOffsetY;
                INVENTORY_GetDirectionDelta(gnPetDirections[nDirection], &nOffsetX, &nOffsetY);
                nTargetX = nLastX + 8 * nOffsetX;
                nTargetY = nLastY + 8 * nOffsetY;
                if (D2Common_10095(UNITS_GetRoom(pOwner), nTargetX, nTargetY) == nCollision) {
                    AITACTICS_SetAiParam(pUnit, 0, nVelocity, 40);
                    if (bRun) {
                        if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                        if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nTargetX) / 2, (nY + nTargetY) / 2)) return 1;
                    } else {
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nTargetX) / 2, (nY + nTargetY) / 2)) return 1;
                    }
                }
                nDirection = (nDirection + 1) & 7;
            }
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, 4)) return 1;
            if (bRun && AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nOwnerX) / 2, (nY + nOwnerY) / 2)) return 1;
            if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nOwnerX) / 2, (nY + nOwnerY) / 2)) return 1;
            return AITACTICS_WalkToTargetCoordinates(pGame, pUnit, nOwnerX, nOwnerY);
        }
    case 1:
        {
            if (nMode == 2) {
                AITACTICS_SetAiParam(pUnit, 0, 0, 100);
                if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nLastX, nLastY)) return 1;
                if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, (nX + nLastX) / 2, (nY + nLastY) / 2)) return 1;
            }
            int nSpeed;
            if (nVelocity) nSpeed = nVelocity;
            else nSpeed = SEED_RollLimitedRandomNumber(pSeed, 40) + 40;
            unsigned char nIndex = pData->nPositionHistoryIndex;
            D2AiParamStrc* pAiParam = sub_005A6190_GetAiParam(pUnit);
            int bChanged = 0;
            for (int i = 0; i < 20; ++i) {
                if (!nIndex) nIndex = 19;
                else --nIndex;
                int nTargetY;
                int nTargetX = pData->pPositionHistory[nIndex].nX;
                nTargetY = pData->pPositionHistory[nIndex].nY;
                if (!nTargetX || !nTargetY || (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY) <= 5) continue;
                AITACTICS_SetAiParam(pUnit, 0, nSpeed, 100);
                if (bRun) {
                    if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, nTargetX, nTargetY)) return 1;
                } else {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                }
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                AITACTICS_SetAiParam(pUnit, 15, nSpeed, 100);
                if (bRun) {
                    if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                } else {
                    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                }
                if (!bChanged) {
                    bChanged = 1;
                    MONSTERMODE_SetVelocityParams(pAiParam, 1, nSpeed, 100);
                    if (bRun) {
                        if (AITACTICS_RunToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                    } else {
                        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX, nTargetY)) return 1;
                    }
                }
            }
            int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner) / 4;
            if (nDistance < 4) nDistance = 4;
            AITACTICS_SetAiParam(pUnit, 0, 15, 0);
            if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, nDistance)) return 1;
            break;
        }
    case 2:
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 10) {
            if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, SEED_RollLimitedRandomNumber(pSeed, 3) + 3)) return 1;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            AITACTICS_SetAiParam(pUnit, 0, 0, 40);
            if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nLastX, nLastY)) return 1;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return 1;
    case 3:
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
            D2RoomCoordListStrc* pCoords = D2Common_10096(pRoom, CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
            int nSpawnX;
            int nSpawnY;
            if (!MONSTERREGION_FindSpawnLocation(pGame, pRoom, pCoords, GetMonsterId(363), &nSpawnX, &nSpawnY, 0)) break;
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, nSpawnX, nSpawnY);
            if (!pRoom) break;
            if (!SUNIT_TeleportUnit(pGame, pUnit, pRoom, nSpawnX, nSpawnY, 0, 0)) break;
            UNITROOM_RefreshUnit(pUnit);
            pUnit->dwFlagEx |= 0x10000;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return 1;
        }
    case 4:
        {
            D2PetMoveStrc args;
            args.pUnit = pUnit;
            args.nCounter = 0;
            PLAYERPETS_IteratePets(pGame, pOwner, AITHINK_CountNearbyPets, &args);
            if (args.nCounter >= 1) {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pOwner, nRange, 1)) return 1;
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                if (AITACTICS_WanderToTarget(pGame, pUnit, pOwner, nRange)) return 1;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return 1;
        }
    case 5:
        AITACTICS_SetAiParam(pUnit, 7, 0, 0);
        if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, nRange)) return 1;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pOwner, nRange, 1)) return 1;
        AITACTICS_SetAiParam(pUnit, 0, 0, 40);
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nLastX, nLastY)) return 1;
        break;
    }
    return 0;
}

// 0x005E45D0
int __fastcall AITHINK_TryPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int bCombat, D2AiTickParamStrc* pAiTickParam, int bSkipIdle, int nRange)
{
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nMode = pOwner->dwAnimMode;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOwner);
    int nOwnerCollision;
    int nUnitCollision;
    int nFirstX;
    int nFirstY;
    unsigned int nLastX;
    unsigned int nLastY;
    int nMove;
    nRange += PLAYERPETS_GetTotalPetCount(pOwner) >> 1;
    if (nRange > 36) nRange = 36;
    if (nDistance <= 1 && nMode == 1 && !bCombat)
        return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 5, 0, 0, nRange);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (nDistance > 80)
            return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, nRange);
        goto ReturnZero;
    }
    nOwnerCollision = D2Common_10095(UNITS_GetRoom(pOwner), GetUnitX(pOwner), GetUnitY(pOwner));
    nUnitCollision = D2Common_10095(UNITS_GetRoom(pUnit), GetUnitX(pUnit), GetUnitY(pUnit));
    nFirstX = D2COMMON_10175_PathGetFirstPointX(pPath);
    nFirstY = D2COMMON_10176_PathGetFirstPointY(pPath);
    nLastX = PATH_GetFinalTargetX(pPath);
    nLastY = PATH_GetFinalTargetY(pPath);
    nMove = 2;
    if (nMode == 2 || nMode == 6 || nMode == 3) nMove = 0;
    if (nFirstX != nLastX && nFirstY != nLastY) nMove = 0;
    if (nOwnerCollision != nUnitCollision) nMove = 1;
    if (nDistance > nRange) nMove = 1;
    if (nDistance > 50) nMove = 3;
    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pPlayerData->nSkillCooldown148, pPlayerData->nSkillCooldown14C) < 28)
    {
        if ((nMove == 1 && nDistance < 30) || nMove == 2) nMove = 4;
    }
    if (bSkipIdle && nMove == 2)
    {
ReturnZero:
        return 0;
    }
    return D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, nMove, 0, 0, nRange);
}

static inline int UNITS_TestIgnoreTargetFlag(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 30) & 1;
    return bResult;
}

// 0x005E4830
void __fastcall AITHINK_MeleePet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pOldOwner = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pOldOwner)
            {
                D2GAME_AI_PetMove_6FCE2BA0(pGame, pOldOwner, pUnit, 3, 0, 0, 0);
                return;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    pAiControl->dwAiParam[2] = pOwner->dwUnitId;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nOwnerDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nOwnerDistance > 50)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }
    int nVelocity;
    if (pMonStatsTxt->nVelocity > 0)
    {
        nVelocity = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100;
        if (nVelocity >= 100)
            nVelocity = 100;
    }
    else
        nVelocity = 100;
    if (nOwnerDistance > 28)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, nVelocity, 0);
        return;
    }
    int nOwnerTargetDistance;
    int bOwnerCombat;
    D2UnitStrc* pOwnerTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nOwnerTargetDistance, &bOwnerCombat);
    if (pOwnerTarget && UNITS_TestIgnoreTargetFlag(pOwnerTarget))
        pOwnerTarget = 0;
    int nTargetDistance;
    int bCombat;
    D2UnitStrc* pTarget = AITACTICS_FindTargetInRange(pGame, pUnit, pAiControl, &nTargetDistance, &bCombat, 24);
    if (!pTarget || nTargetDistance > 6)
    {
        pTarget = 0;
        if (pOwnerTarget)
        {
            nTargetDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwnerTarget);
            if (nTargetDistance < 36)
                pTarget = pOwnerTarget;
        }
    }
    if (!AIUTIL_HasClearApproachToTarget(pUnit, pTarget))
        pTarget = 0;
    int nResult;
    if ((int)(AI_RollUnitSeed(pUnit) % 100) < 15)
        nResult = AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 1, 8);
    else
        nResult = AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 7);
    if (nResult)
        return;
    if (pTarget && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        AITACTICS_WanderToTarget(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!pTarget)
    {
        AITACTICS_WanderToTarget(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 80)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITACTICS_SetAiParam(pUnit, 0, 0, 12);
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005E4AC0
void __fastcall AITHINK_UpdateNecroPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pPlayer)
            {
                D2GAME_AI_PetMove_6FCE2BA0(pGame, pPlayer, pUnit, 3, 0, 0, 0);
                return;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    pAiControl->dwAiParam[2] = !pOwner ? -1 : pOwner->dwUnitId;
    AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nOwnerDistance;
    int bOwnerCombat;
    D2UnitStrc* pOwnerTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nOwnerDistance, &bOwnerCombat);
    if (pOwnerTarget && UNITS_TestIgnoreTargetFlag(pOwnerTarget))
        pOwnerTarget = 0;
    int nDistance;
    int bCombat;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (!pTarget || nDistance > 15)
    {
        pTarget = 0;
        if (pOwnerTarget && !UNITS_TestCollisionWithUnit(pUnit, pOwnerTarget, 4))
        {
            nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwnerTarget);
            if (nDistance < 20) pTarget = pOwnerTarget;
        }
    }
    int nResult;
    if ((int)(AI_RollUnitSeed(pUnit) % 100) < 15)
        nResult = AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 1, 8);
    else
        nResult = AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 7);
    if (nResult)
        return;
    if (pTarget && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        AITACTICS_WanderToTarget(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!pTarget)
    {
        AITACTICS_WanderToTarget(pGame, pUnit, pOwner, 4);
        return;
    }
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 80)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 75)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005E4CF0
void __fastcall AITHINK_Fn067_NecroPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    if (pAiTickParam->pAiControl->dwAiParam[0] != 0)
    {
        AITHINK_UpdateNecroPet(pGame, pUnit, pAiTickParam);
    }
    else
    {
        AITHINK_MeleePet(pGame, pUnit, pAiTickParam);
    }
}

static inline unsigned int SEED_RollRandomNumber_005E1080(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_005E1080(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber_005E1080(pSeed) % nMax;
    }

    return SEED_RollRandomNumber_005E1080(pSeed) & (nMax - 1);
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord_005E1080(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_005E1080(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int MONSTERS_GetValidMonsterId(int nMonsterId)
{
    if (nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x005E4D30
void __fastcall AITHINK_SelectHirelingAction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nHirelingId, D2UnitStrc* pTarget, D2SeedStrc* pSeed)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord_005E1080(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    int nChance = pHirelingTxtRecord->dwDefaultChance;
    int nLevelDiff = nLevel - pHirelingTxtRecord->nHirelingLevel;
    if (nLevelDiff < 0)
    {
        nLevelDiff = 0;
    }

    int nSkillChances[6];
    for (int i = 0; i < 6; ++i)
    {
        if (pHirelingTxtRecord->dwSkill[i] <= 0 || pHirelingTxtRecord->dwSkill[i] >= sgptDataTables->nSkillsTxtRecordCount)
        {
            break;
        }

        const int nSkillId = pHirelingTxtRecord->dwSkill[i];

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_005E1080(nSkillId);
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        nSkillChances[i] = 0;

        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (!pSkill || SKILLS_GetSkillLevel(pUnit, pSkill, 1) <= 0)
        {
            continue;
        }

        if (pSkillsTxtRecord->nAiType == 1 && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
            && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            continue;
        }

        if (nSkillId == SKILL_INFERNO)
        {
            pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pTarget && DRLG_UnitEdgeDistance(pUnit, pTarget) > SKILLS_GetSkillLevel(pUnit, pSkill, 1) / 2 + 4)
            {
                continue;
            }
        }

        nChance += pHirelingTxtRecord->dwChance[i] + nLevelDiff * pHirelingTxtRecord->dwChancePerLvl[i] / 4;
        nSkillChances[i] = nChance;
    }

    const int nRoll = SEED_RollLimitedRandomNumber_005E1080(pSeed, nChance + 1);

    if (nRoll >= pHirelingTxtRecord->dwDefaultChance)
    {
        int i = 0;
        while (nRoll > nSkillChances[i] && i < 6)
        {
            ++i;
        }

        if (i < 6)
        {
            const int nSkillId = pHirelingTxtRecord->dwSkill[i];
            if (nSkillId > 0)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_005E1080(nSkillId);
                if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, nSkillId, -1);
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                    return;
                }

                AITACTICS_UseSkill(pGame, pUnit, pHirelingTxtRecord->nMode[i], nSkillId, pTarget, 0, 0);
                return;
            }
        }
    }

    switch (MONSTERS_GetValidMonsterId(nMonsterId))
    {
    case MONSTER_ROGUEHIRE:
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[0], pMonStatsTxtRecord->nSkill[0], pTarget, 0, 0);
        return;

    case MONSTER_ACT2HIRE:
    case MONSTER_ACT3HIRE:
    case MONSTER_ACT5HIRE1:
    case MONSTER_ACT5HIRE2:
        if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        break;

    default:
        break;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}

// 0x005E5050
void __fastcall AITHINK_HirelingCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, D2UnitStrc* pOwner, D2UnitStrc* pTarget, D2SeedStrc* pSeed, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nChance;
    if (nMonsterId == MONSTER_ACT2HIRE || nMonsterId > 559 && nMonsterId <= 561)
        nChance = 98;
    else
    {
        const int nBaseChance = pAiControl->dwAiParam[0] + 40;
        nChance = nBaseChance + 2 * STATLIST_UnitGetStatValue(pUnit, 12, 0);
        if (nChance >= 95) nChance = 95;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pOwner, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pPetInfo)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    const int nHirelingId = pPetInfo->nHirelingId;
    int bAction = 0;
    if ((int)(RollSeed(pSeed) % 100) < nChance)
    {
        bAction = 1;
        pAiControl->dwAiParam[0] = 0;
    }
    else
        pAiControl->dwAiParam[0] += 10;
    if (!pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (nDistance < 4 && (int)(RollSeed(pSeed) % 100) < 50)
        {
            if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 4)) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 4, 1)) return;
        }
        else if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    if (nDistance < 3 && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        if (!bAction)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITHINK_SelectHirelingAction(pGame, pUnit, nMonsterId, nHirelingId, pTarget, pSeed);
        return;
    }
    PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);
    AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, pTarget, 1);
}

// 0x005E5270
int __stdcall sub_005E5270(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x005E5280
void __fastcall sub_005E5280_AiSpecialState04(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005E5710
void __fastcall AITHINK_MinionCallback_CheckDead(D2UnitStrc* pUnit, void* a2, void* a3)
{
    if (!pUnit || MONSTERS_IsDead(pUnit))
    {
        *(int*)a2 = 1;
    }
}

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005E5730
void __fastcall AITHINK_InitializeFormationOffsets(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    D2_ASSERT(pOwner, 3607);

    const int nOwnerX = CLIENTS_GetUnitXInline(pOwner);
    const int nOwnerY = CLIENTS_GetUnitYInline(pOwner);
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = nX - nOwnerX;
    pAiControl->dwAiParam[1] = nY - nOwnerY;
    if (pOwner == pUnit)
    {
        pAiControl->dwAiParam[2] = (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100;
    }
}

static inline unsigned __int64 Roll(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = nSeed;
    return nSeed;
}

static inline unsigned int Roll_005E6320(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}

static inline int AI_RollPercentage_005E5870(D2UnitStrc* pUnit)
{
    return (unsigned int)Roll(&pUnit->pSeed) % 100;
}

// 0x005E5870
void __fastcall AITHINK_Formation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiCmdStrc cmd;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2AiCmdStrc* pCurrentCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentCmd && pCurrentCmd->nCmdParam[0] == 8)
    {
        AIGENERAL_FreeMinionList(pUnit);
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    int bAnyDead = 0;
    AIGENERAL_ExecuteCallbackOnMinions(pUnit, &bAnyDead, 0, AITHINK_MinionCallback_CheckDead);
    if (!AIUTIL_IsGettingHit(pUnit) && !bAnyDead)
    {
        if (AIGENERAL_GetMinionOwner(pUnit) == pUnit)
        {
            if (AI_RollPercentage_005E5870(pUnit) < 30)
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                return;
            }
            int nPhase = pAiControl->dwAiParam[2] + 1;
            if (nPhase >= 100) nPhase = 0;
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            int nOffset = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 10);
            if (nPhase < 25)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX += nOffset; nY -= 5;
            }
            if (nPhase >= 25 && nPhase < 50)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX += 5; nY += nOffset;
            }
            if (nPhase >= 50 && nPhase < 75)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX += nOffset; nY += 5;
            }
            if (nPhase >= 75)
            {
                if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2)) nOffset = -nOffset;
                nX -= 5; nY += nOffset;
            }
            if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX, nY))
            {
                cmd.nCmdParam[0] = 2;
                cmd.nCmdParam[1] = nX;
                cmd.nCmdParam[2] = nY;
                AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &cmd);
            }
            else
            {
                nPhase += 25;
            }
            pAiControl->dwAiParam[2] = nPhase;
            return;
        }
        if (!pCurrentCmd)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }
        int nX = pCurrentCmd->nCmdParam[1] + pAiControl->dwAiParam[0];
        int nY = pCurrentCmd->nCmdParam[2] + pAiControl->dwAiParam[1];
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        AITACTICS_WalkToTargetCoordinates(pGame, pUnit, nX, nY);
        return;
    }
    cmd.nCmdParam[0] = 8;
    AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &cmd);
    AIGENERAL_FreeMinionList(pUnit);
    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, 0);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E5AC0
void __fastcall AITHINK_Fn090_Griswold(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage_005E0C80(pUnit) < 80)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
    }
    else
    {
        if (AI_RollPercentage_005E0C80(pUnit) < 50)
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, GRISWOLD_WALK_FLAGS);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E5B70
int __fastcall AITHINK_UseSkillAtMapAiPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MapAIStrc* pMapAi = pAiControl->pMapAi;
    if (pMapAi && pAiControl->dwAiParam[0] < pMapAi->nPathNodes)
    {
        if (pUnit)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = AITHINK_GetMonStatsTxtRecordInline(pUnit->dwClassId);
            if (pMonStatsTxtRecord)
            {
                const int nSkillId = pMonStatsTxtRecord->nSkill[0];
                if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, nSkillId, 0, pMapAi->pPosition[pAiControl->dwAiParam[0]].nX, pMapAi->pPosition[pAiControl->dwAiParam[0]].nY);
                    ++pAiControl->dwAiParam[0];
                    pAiControl->dwAiParam[1] = pGame->dwGameFrame;
                    return 1;
                }
            }
        }
    }
    else
    {
        int nFrameDiff = pGame->dwGameFrame - pAiControl->dwAiParam[1];
        if (nFrameDiff < 0)
        {
            nFrameDiff = -nFrameDiff;
        }

        if (nFrameDiff > 700)
        {
            pAiControl->dwAiParam[0] = 0;
        }
    }

    return 0;
}

static inline int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; }
}

static inline int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; default: return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; }
}

static inline D2AiParamStrc* GetAiParam(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData ? pUnit->pMonsterData->pAiParam : 0;
}

// 0x005E5C50
void __fastcall AITHINK_SpecialState13_Countess(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    if (!pMonStats) return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom) return;
    D2UnitStrc* pTarget = pTick->pTarget;
    int nDistance = pTick->nTargetDistance;
    int bCombat = pTick->bCombat;
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pCmd)
    {
        D2AiCmdStrc cmd;
        cmd.nCmdParam[0] = 10;
        cmd.nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
        cmd.nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &cmd);
        pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }
    if (!pCmd->nCmdParam[1] || !pCmd->nCmdParam[2])
    {
        pCmd->nCmdParam[1] = GetX(pUnit);
        pCmd->nCmdParam[2] = GetY(pUnit);
    }
    int nRegion = D2Common_10095(pRoom, pCmd->nCmdParam[1], pCmd->nCmdParam[2]);
    if (nRegion != D2Common_10095(pRoom, GetX(pUnit), GetY(pUnit)))
    {
        MONSTERMODE_SetVelocityParams(GetAiParam(pUnit), 1, 0, 0);
        if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    if (nRegion != D2Common_10095(pRoom, GetX(pTarget), GetY(pTarget)))
    {
        if (CLIENTS_GetUnitX(pUnit) == pCmd->nCmdParam[1] && CLIENTS_GetUnitY(pUnit) == pCmd->nCmdParam[2])
        {
            if (nDistance < 25 && AITHINK_UseSkillAtMapAiPosition(pGame, pUnit, pTick)) return;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        MONSTERMODE_SetVelocityParams(GetAiParam(pUnit), 1, 0, 0);
        if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 40)
    {
        MONSTERMODE_SetVelocityParams(GetAiParam(pUnit), 1, 0, 0);
        if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    if (AITHINK_UseSkillAtMapAiPosition(pGame, pUnit, pTick)) return;
    int nDifficulty = pGame->nDifficulty;
    int nRoll = (int)SEED_RollLimitedRandomNumber(pSeed, 100);
    if (bCombat)
    {
        if (nRoll < pMonStats->wAiParam[2][nDifficulty] + 10)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][nDifficulty]);
        return;
    }
    if (nRoll < pMonStats->wAiParam[0][nDifficulty])
    {
        AITACTICS_SetAiParam(pUnit, 0, 100, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStats->wAiParam[1][nDifficulty]);
}

static inline unsigned int SEED_RollRandomNumber_005E5870(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (nMax & (nMax - 1))
    {
        return SEED_RollRandomNumber_005E5870(pSeed) % nMax;
    }

    return SEED_RollRandomNumber_005E5870(pSeed) & (nMax - 1);
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_005E5870(int nMonsterId)
{
    if (!(nMonsterId >= 0))
        return 0;
    if (!(nMonsterId < sgptDataTables->nMonStatsTxtRecordCount))
        return 0;
    return &sgptDataTables->pMonStatsTxt[nMonsterId];
}

static inline unsigned int TestMonStatsFlag_005E5870(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_005E5870(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x005E6020
bool __fastcall AITHINK_SelectGenericSpawnClass(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pClassId)
{
    *pClassId = 453 >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : 453;

    int const nLevelId = sub_00573520_GetLevelIdFromUnit(pUnit);
    D2MonsterRegionStrc* pMonRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, nLevelId);
    const int nMonsterId = pMonRegion->pMonData[SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, pMonRegion->nMonCount)].nMonHcIdx;
    if (TestMonStatsFlag_005E5870(nMonsterId, 21))
    {
        *pClassId = nMonsterId;
        return true;
    }

    for (int i = 0; i < pMonRegion->nMonCount; ++i)
    {
        const int nId = pMonRegion->pMonData[i].nMonHcIdx;
        if (TestMonStatsFlag_005E5870(nId, 21))
        {
            *pClassId = nId;
            return true;
        }
    }

    *pClassId = 496 >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : 496;
    return true;
}

// 0x005E6190
void __fastcall AITHINK_InitializeGenericSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    sub_005F6630_InitAiParamsFrame(pGame, pUnit, pAiTickParam);
    pAiTickParam->pAiControl->nMinionSpawnClassId = -1;
}

// 0x005E61B0
void __fastcall AITHINK_Fn129_GenericSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->nMinionSpawnClassId == -1 && !AITHINK_SelectGenericSpawnClass(pGame, pUnit, &pAiControl->nMinionSpawnClassId))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (nTargetDistance > 20)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    if (pAiControl->dwAiParam[1] >= pMonStatsTxt->wAiParam[2][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    int nDiff = pGame->dwGameFrame - pAiControl->dwAiParam[0];
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        const int nMonsterId = MONSTER_EVILHUT >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : MONSTER_EVILHUT;
        if (sub_005FD350_SpawnNearby(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSequenceSkill(pGame, pUnit, SKILL_NEST, pTarget, 0, 0);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005E6300
void __fastcall AITHINK_ResetBloodRavenReturnState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[2] = 0;
}

// 0x005E6320
void __fastcall AITHINK_Fn059_BloodRaven(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2UnitStrc* pTarget = pTick->pTarget;
    int nDistance = pTick->nTargetDistance;
    int bCombat = pTick->bCombat;
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pCmd) {
        D2AiCmdStrc cmd;
        cmd.nCmdParam[0] = 10;
        cmd.nCmdParam[1] = GetX(pUnit);
        cmd.nCmdParam[2] = GetY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &cmd);
        pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }
    int nHomeDistance = 0;
    D2AiControlStrc* pAi = pTick->pAiControl;
    if (pCmd) {
        nHomeDistance = AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pCmd->nCmdParam[1], pCmd->nCmdParam[2]);
        if (nDistance > 45) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 5); return; }
        if (nHomeDistance >= 50 || (unsigned int)AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 50) {
            pAi->dwAiParam[2] = 1;
            AITACTICS_SetAiParam(pUnit, 7, 100, 0);
            if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        }
        if (pAi->dwAiParam[2] && (unsigned int)AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 5) {
            AITACTICS_SetAiParam(pUnit, 7, 100, 0);
            if (AITACTICS_RunToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) return;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        }
        pAi->dwAiParam[2] = 0;
    }
    if (nDistance > 20 && nHomeDistance < 50) {
        nDistance >>= 1;
        if (nDistance < 12) nDistance = 12;
        AITACTICS_SetAiParam(pUnit, 7, 100, 0);
        if (AITACTICS_RunCloseToTargetUnit(pGame, pUnit, pTarget, nDistance)) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nMax = 2 * pGame->nDifficulty + 8;
    pAi->dwAiParam[0] += 3;
    if (pMonStats->nSkill[0] >= 0 && !bCombat && pAi->dwAiParam[1] < nMax
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < pAi->dwAiParam[0]) {
        nDistance = SEED_RollLimitedRandomNumber(pSeed, 15) + 5;
        int nX, nY;
        if (sub_00472210_SeedRollMasked(pSeed, 2)) { nX = nDistance; nY = ITEMS_RollLimitedRandomNumber(pSeed, nDistance); }
        else { nX = ITEMS_RollLimitedRandomNumber(pSeed, nDistance); nY = nDistance; }
        if (sub_00472210_SeedRollMasked(pSeed, 2)) nX = -nX;
        if (sub_00472210_SeedRollMasked(pSeed, 2)) nY = -nY;
        AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], 0, CLIENTS_GetUnitX(pTarget) + nX, CLIENTS_GetUnitY(pTarget) + nY);
        ++pAi->dwAiParam[1];
        pAi->dwAiParam[0] = 0;
        return;
    }
    if (nDistance > 5) {
        if ((int)(Roll_005E6320(pSeed) % 100) < 5 && nHomeDistance < 50) {
            AITACTICS_SetAiParam(pUnit, 7, 100, 0);
            AITACTICS_RunCloseToTargetUnit(pGame, pUnit, pTarget, 12);
            return;
        }
        int nNewDistance, bNewCombat;
        D2UnitStrc* pNewTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nNewDistance, &bNewCombat);
        if (pNewTarget && !AIUTIL_IsGettingHit(pUnit) && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 80) {
            const int nChance = 10 * (pGame->nDifficulty + 4);
            if (pMonStats->nSkill[1] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < nChance) {
                AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[1], pMonStats->nSkill[1], pNewTarget, 0, 0);
                return;
            }
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pNewTarget);
            return;
        }
        AITACTICS_SetAiParam(pUnit, 0, 50, 0);
        if (AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 1)) return;
    }
    if ((int)(Roll_005E6320(pSeed) % 100) < 30 && nDistance < 12) {
        AITACTICS_SetAiParam(pUnit, 7, 100, 0);
        if (AITACTICS_RunAwayFromTarget(pGame, pUnit, pTarget, 12 - nDistance, 0)) return;
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    }
    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
}

// 0x005E6800
bool __fastcall AITHINK_InitHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
    if (pAiCmd && !pAiCmd->nCmdParam[1] && !pAiCmd->nCmdParam[2])
    {
        pAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
        pAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return true;
    }

    return false;
}

// 0x005E6860
bool __fastcall AITHINK_ReturnToHomeIfTooFar(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, unsigned int nMaxDistance)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pAiCmd)
    {
        return AITHINK_InitHomeCommand(pGame, pUnit, pAiTickParam);
    }

    if (AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]) > nMaxDistance)
    {
        D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pCurrentAiCmd)
        {
            pCurrentAiCmd->nCmdParam[1] = pAiCmd->nCmdParam[1];
            pCurrentAiCmd->nCmdParam[2] = pAiCmd->nCmdParam[2];
            pCurrentAiCmd->nCmdParam[3] = 12;
            pCurrentAiCmd->nCmdParam[4] = 10;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return true;
    }

    return false;
}

// 0x005E68F0
bool __fastcall AITHINK_HandleNpcProximityAndInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCloseToTarget = 0;
    D2UnitStrc* pTarget = AITACTICS_FindNearbyPlayerOrSelf(pGame, pUnit, &bCloseToTarget);
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonsterInteractStrc* pMonInteract = nType == UNIT_MONSTER && pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0;
    if (!pMonInteract)
    {
        return false;
    }

    int bInteracting = MONSTERAI_IsInteractingWith(pMonInteract, pTarget);
    if (pTarget && pTarget->dwUnitType == UNIT_PLAYER && PLAYER_IsBusy(pTarget) == 1)
    {
        bInteracting = 1;
    }

    const int bHasInteractUnit = MONSTERAI_HasInteractUnit(pMonInteract);
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (bHasInteractUnit || bInteracting || pAiControl->dwAiParam[0] > 0)
    {
        if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]) > 2 && pAiControl->dwAiParam[0] > 36)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]);
        }
        else if (pAiControl->dwAiParam[0] > 0)
        {
            if (pUnit->pDynamicPath)
            {
                PATH_ClearPathingFlagAndPoints(pUnit->pDynamicPath);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
        }

        if (pAiControl->dwAiParam[0] < 0)
        {
            pAiControl->dwAiParam[0] = 0;
        }
        else
        {
            --pAiControl->dwAiParam[0];
        }

        return true;
    }

    if (!pTarget || pTarget == pUnit)
    {
        return false;
    }

    if (nDistance >= 3 && nDistance <= 23)
    {
        if (AITHINK_ReturnToHomeIfTooFar(pGame, pUnit, pAiTickParam, 16))
        {
            return true;
        }

        AITACTICS_SetAiParam(pUnit, 1, 0, 0);
        if (nDistance >= 5)
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 3, 2);
        }
        else
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, nDistance - 2, 2);
        }

        return true;
    }

    PATH_ClearPathingFlagAndPoints(pUnit->pDynamicPath);
    if (!pAiControl->dwAiParam[1])
    {
        pAiControl->dwAiParam[1] = 60;
        if (pTarget->dwUnitType == UNIT_PLAYER)
        {
            SUNIT_AttachSound(pUnit, 18, pTarget);
        }
    }
    else
    {
        if (pAiControl->dwAiParam[1] < 0)
        {
            pAiControl->dwAiParam[1] = 0;
        }

        if (pAiControl->dwAiParam[1] > 0)
        {
            --pAiControl->dwAiParam[1];
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
    return true;
}

static inline int AITHINK_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x005E6AE0
bool __fastcall AITHINK_ExecuteNpcAiCommands(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 4, 0);
    if (pAiCmd && pAiCmd->nCmdParam[3] > 0)
    {
        if (pAiCmd->nCmdParam[1] && pAiCmd->nCmdParam[2] && (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]) > 3)
        {
            if ((gnNpcWalkSequenceCounter % 4) == 0)
            {
                AITACTICS_SetAiParam(pUnit, 5, 0, 0);
                AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]);
            }
            else
            {
                AITACTICS_SetAiParam(pUnit, 1, 0, 0);
                AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]);
            }

            ++gnNpcWalkSequenceCounter;
            --pAiCmd->nCmdParam[3];
            return 1;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiCmd->nCmdParam[4]);
        --pAiCmd->nCmdParam[3];
        return 1;
    }

    pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 5, 0);
    if (pAiCmd)
    {
        if (pAiCmd->nCmdParam[1] > 0)
        {
            if ((pAiCmd->nCmdParam[1] % 2) != 0)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, pAiCmd->nCmdParam[2]);
                --pAiCmd->nCmdParam[1];
                return 1;
            }

            if (pAiCmd->nCmdParam[3] > 0)
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiCmd->nCmdParam[4]);
                --pAiCmd->nCmdParam[1];
                --pAiCmd->nCmdParam[3];
                return 1;
            }

            --pAiCmd->nCmdParam[1];
        }
        else
        {
            if (pAiCmd->nCmdParam[3] > 0)
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiCmd->nCmdParam[4]);
                --pAiCmd->nCmdParam[3];
                return 1;
            }
        }
    }

    pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 7, 0);
    if (!pAiCmd || !pAiCmd->nCmdParam[1])
    {
        return 0;
    }

    if (pAiCmd->nCmdParam[1] != 8 && pAiCmd->nCmdParam[1] != 9 && pAiCmd->nCmdParam[1] != 10 && pAiCmd->nCmdParam[1] != 11)
    {
        pAiCmd->nCmdParam[1] = 0;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
        return 1;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[2], pAiCmd->nCmdParam[3]);
    if (nDistance > 0)
    {
        if (pAiCmd->nCmdParam[4] > 0)
        {
            AITACTICS_SetAiParam(pUnit, 7, 0, 0);

            if (!AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pAiCmd->nCmdParam[2], pAiCmd->nCmdParam[3]))
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            }

            --pAiCmd->nCmdParam[4];
            return 1;
        }

        if (nDistance > 1)
        {
            pAiCmd->nCmdParam[1] = 0;
        }
    }

    {
        if (pUnit)
        {
            if (pUnit->dwClassId == 154)
            {
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x38);
            }
            if (AITHINK_GetClassIdInline(pUnit) == 155)
            {
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);
            }
            if (pUnit->dwClassId == 178)
            {
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 4);
            }
            if (pUnit->dwClassId == 405)
            {
                if (pAiCmd->nCmdParam[1] == 8)
                {
                    D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);
                }
                if (pAiCmd->nCmdParam[1] == 9)
                {
                    D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x30);
                }
            }
            if (pUnit->dwClassId == 511 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) > 4)
            {
                pAiCmd->nCmdParam[1] = 0;
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
                return 1;
            }
        }

        if (pAiCmd->nCmdParam[1])
        {
            int nAnimMode;
            if (!pUnit)
            {
                nAnimMode = 0;
            }
            else
            {
                nAnimMode = pUnit->dwAnimMode;
            }

            if (nAnimMode == pAiCmd->nCmdParam[1])
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, pAiCmd->nCmdParam[1], pUnit);
                pAiCmd->nCmdParam[1] = 0;
            }
            return 1;
        }

        if (pUnit && pUnit->dwClassId == 178 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 66)
        {
            pAiCmd->nCmdParam[1] = 8;
        }

        return 0;
    }

}

// 0x005E6DE0
bool __fastcall AITHINK_MapAiAction_WalkToPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY && AIUTIL_GetDistanceToCoordinates(pUnit, pPosition->nX, pPosition->nY) > 0)
    {
        AITACTICS_SetAiParam(pUnit, 7, 0, 0);
        AITACTICS_WalkToTargetCoordinatesNoSteps(pGame, pUnit, pPosition->nX, pPosition->nY);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
        bResult = true;
    }

    return bResult;
}

#define CMD_ID 4

#define DURATION 20

#define INTERVAL 10

// 0x005E6E80
bool __fastcall AITHINK_MapAiAction_WalkToPositionOrWait(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = AITHINK_MapAiAction_WalkToPosition(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, CMD_ID, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = DURATION;
            pAiCmd->nCmdParam[4] = INTERVAL;
        }
    }
    return bResult;
}

// 0x005E6EF0
bool __fastcall AITHINK_MapAiAction_ForwardWalkToPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    return AITHINK_MapAiAction_WalkToPosition(pGame, pUnit, pAiTickParam, pPosition);
}

// 0x005E6F00
bool __fastcall AITHINK_MapAiAction_QueueSkill1(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = AITHINK_MapAiAction_WalkToPosition(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_TestMonModeFlag(pUnit->dwClassId, MONMODE_SKILL1) ? MONMODE_SKILL1 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}

// 0x005E6FC0
bool __fastcall AITHINK_MapAiAction_QueueSkill2(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition)
{
    bool bResult = false;
    if (pUnit && pPosition && pPosition->nX && pPosition->nY)
    {
        bResult = AITHINK_MapAiAction_WalkToPosition(pGame, pUnit, pAiTickParam, pPosition);
        D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 7, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = sub_0046C140_TestMonModeFlag(pUnit->dwClassId, MONMODE_SKILL2) ? MONMODE_SKILL2 : MONMODE_NEUTRAL;
            pAiCmd->nCmdParam[2] = pPosition->nX;
            pAiCmd->nCmdParam[3] = pPosition->nY;
            pAiCmd->nCmdParam[4] = 4;
        }

        pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 4, 0);
        if (pAiCmd)
        {
            pAiCmd->nCmdParam[1] = pPosition->nX;
            pAiCmd->nCmdParam[2] = pPosition->nY;
            pAiCmd->nCmdParam[3] = 12;
            pAiCmd->nCmdParam[4] = 10;
        }
    }

    return bResult;
}

inline D2MonsterInteractStrc* AITHINK_GetMonInteractInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

inline void AITHINK_IdleInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames)
{
    if (!nFrames)
    {
        nFrames = 1;
    }
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrames + pGame->dwGameFrame, 0, 0);
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
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

static inline D2MonsterInteractStrc* GetMonInteract(D2UnitStrc* pUnit)
{
    D2MonsterInteractStrc* p;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            if (pUnit->pMonsterData)
                p = pUnit->pMonsterData->pMonInteract;
            else
                p = 0;
        }
        else
            p = 0;
    }
    else
        p = 0;
    return p;
}

static inline int AI_GetAnimMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005E7080
bool __fastcall AITHINK_ExecuteMapAiAction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    bool bResult = false;
    D2MapAIStrc* pMapAi = pAiTickParam->pAiControl->pMapAi;
    if (pMapAi && AI_RollPercentage(pUnit) < 66)
    {
        if (!pMapAi->nPathNodes)
        {
            return false;
        }

        D2MapAIPathPositionStrc* pPosition = &pMapAi->pPosition[ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMapAi->nPathNodes)];
        if (pPosition->nMapAIAction < 0 || pPosition->nMapAIAction >= 7)
        {
            return false;
        }

        MAPAIACTIONFN pfAction = gpfnMapAiActions[pPosition->nMapAIAction];
        if (pfAction)
        {
            bResult = pfAction(pGame, pUnit, pAiTickParam, pPosition);
        }
    }

    return bResult;
}

// 0x005E7130
void __fastcall AITHINK_Fn032_Npc(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2CoordStrc coord;
    int a3;
    int a4;

    if (AITHINK_InitHomeCommand(pGame, pUnit, pAiTickParam))
    {
        return;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    switch (nClassId)
    {
    case MONSTER_ORMUS:
    {
        if (ACT3Q3_GetAltarCoordinates(pGame, &coord))
        {
            if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, coord.nX, coord.nY) > 3)
            {
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coord.nX, coord.nY);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
                ACT3Q3_SetAltarMode(pGame);
            }
            return;
        }
        break;
    }
    case MONSTER_JERHYN:
    {
        if (!ACT2Q4_IsJerhynPalaceActivated(pGame))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
            return;
        }

        ACT2Q4_GetAndUpdatePalaceNpcState(pGame, pUnit, &a3, &a4);
        if (a4)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        }

        if (!a3)
        {
            return;
        }

        if (ACT2Q4_IsGuardMoving(pGame, pUnit))
        {
            D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 10, 0);
            if (pAiCmd)
            {
                pAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit) + 9;
                pAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
                return;
            }
        }
        break;
    }
    case MONSTER_ALKOR:
    {
        if (ACT3Q4_GoldenBirdBroughtToAlkor(pGame))
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
            ACT3Q4_ResetAlkor(pGame);
            return;
        }
        break;
    }
    case MONSTER_CAIN5:
    {
        if (ACT1Q4_GetCainPortalInTownCoordinates(pGame, pUnit, &coord))
        {
            if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, coord.nX, coord.nY) > 2)
            {
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coord.nX, coord.nY);
                return;
            }

            ACT1Q4_OnCainInTownActivated(pGame, pUnit);
        }
        break;
    }
    case MONSTER_DREHYA:
    {
        ACT5Q4_AnyaOpenPortal(pGame, pUnit);
        break;
    }
    default:
        break;
    }

    if (!AITHINK_HandleNpcProximityAndInteraction(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteNpcAiCommands(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteMapAiAction(pGame, pUnit, pAiTickParam))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
    }
}

// 0x005E7350
int __fastcall AITHINK_StopIfNotInteracting(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2MonsterInteractStrc* pMonInteract = (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->pMonInteract : 0;
    if (!MONSTERAI_HasInteractUnit(pMonInteract))
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    return 0;
}

static inline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline unsigned int CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
    }
    return 0;
}

// 0x005E73A0
void __fastcall AITHINK_Fn054_NpcStationary(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCloseToTarget = 0;
    D2UnitStrc* pTarget = AITACTICS_FindNearbyPlayerOrSelf(pGame, pUnit, &bCloseToTarget);
    if (pTarget && pTarget != pUnit)
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
        D2MonsterInteractStrc* pMonInteract = pUnit ? (pUnit->dwUnitType == UNIT_MONSTER ? (pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0) : 0) : 0;
        if (pTarget->dwUnitType == UNIT_PLAYER && PLAYER_IsBusy(pTarget) == 1)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        if (MONSTERAI_HasInteractUnit(pMonInteract))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
        if (nDistance < 24)
        {
            if (!pAiControl->dwAiParam[1])
            {
                pAiControl->dwAiParam[1] = 60;
                if (pTarget->dwUnitType == UNIT_PLAYER)
                {
                    SUNIT_AttachSound(pUnit, 18, pTarget);
                }
            }
            else
            {
                --pAiControl->dwAiParam[1];
            }
        }
        else
        {
            if (pAiControl->dwAiParam[1] <= 0)
            {
                pAiControl->dwAiParam[1] = 60;
            }
            --pAiControl->dwAiParam[1];
        }
    }
    else if (pUnit)
    {
        if (pUnit->dwClassId == 0xFB)
        {
            if (ACT2Q6_IsInRangeOfTyrael(pGame, pUnit) && AITHINK_StopIfNotInteracting(pGame, pUnit))
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
                ACT2Q6_AttachCompletionSoundToPlayers(pGame);
                return;
            }
        }
        else if (pUnit->dwClassId == 0x196)
        {
            if (ACT4Q1_IsAnyPlayerInRangeOfIzualGhost(pGame, pUnit) && AITHINK_StopIfNotInteracting(pGame, pUnit))
            {
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
                ACT4Q1_AttachCompletionSoundToPlayers(pGame);
                return;
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005E7540
void __fastcall AITHINK_Fn041_Towner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!AITHINK_InitHomeCommand(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteNpcAiCommands(pGame, pUnit, pAiTickParam) && !AITHINK_ExecuteMapAiAction(pGame, pUnit, pAiTickParam))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 12);
    }
}

// 0x005E8140
void __fastcall D2GAME_AI_SpecialState11(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!STATES_CheckState(pUnit, STATE_TERROR))
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
        AITHINK_IdleInline_005E17E0(pGame, pUnit, 1);
        return;
    }

    int nParam = pAiControl->dwAiParam[0];
    if (!nParam)
    {
        nParam = 30;
    }

    if (nDistance > nParam)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    int nVel = 0;
    if (pMonStatsTxtRecord->nVelocity > 0)
    {
        nVel = 100 * pMonStatsTxtRecord->nRun / pMonStatsTxtRecord->nVelocity;
    }

    if (nVel < 100)
    {
        nVel = 0;
    }
    else
    {
        nVel -= 100;
        if (nVel > 120)
        {
            nVel = 120;
        }
    }

    if (!pAiControl->dwAiParam[2])
    {
        pAiControl->dwAiParam[2] = 1;
        MONSTERAI_ClearTargetOverride(pUnit);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
        AITACTICS_SetAiParam(pUnit, 2, nVel, 0);
        if (sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_RUN))
        {
            AITACTICS_RunAwayFromTarget(pGame, pUnit, pTarget, 30, 0);
            return;
        }

        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 30, 0);
        return;
    }

// build: symbol ?MONSTERUNIQUE_CheckMonStatsFlag@* 0x00457490
    if (bCombat && !MONSTERUNIQUE_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, MONSTATSFLAGINDEX_INTERACT) && sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_ATTACK1))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_SetAiParam(pUnit, 2, nVel, 0);
    int bResult;
    if (sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, MONMODE_RUN))
    {
        bResult = AITACTICS_RunAwayFromTarget(pGame, pUnit, pTarget, 30, 1);
    }
    else
    {
        bResult = AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 30, 1);
    }

    if (!bResult)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
    }
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_005EC8C0(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}

static inline int sub_0045ADF0(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return pUnit->pStaticPath->nXPos;}
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath):0;
}

static inline int sub_0045AE20(D2UnitStrc* pUnit)
{
    switch(pUnit->dwUnitType)
    {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return pUnit->pStaticPath->nYPos;}
    return pUnit->pDynamicPath ? PATH_GetY(pUnit->pDynamicPath):0;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollRandomNumber_005EEB70(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollBounded(D2SeedStrc* pSeed,int nMax)
{
    unsigned int nResult=0;
    if(nMax>0)
    {
        if((nMax-1)&nMax) nResult=(unsigned int)SEED_RollRandomNumber(pSeed)%nMax;
        else nResult=SEED_RollRandomNumber(pSeed)&(nMax-1);
    }
    return nResult;
}

static __forceinline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    }

    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

// 0x005EB490
void __fastcall AITHINK_InitializeShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = 0;
    pAiControl->dwAiParam[1] = 0;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    const int nParam = pAiControl->dwAiParam[2];

    if (!SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1))
    {
        SKILLS_AssignSkill(pUnit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 3054);
    }

    SKILLS_SetLeftActiveSkill(pUnit, SKILL_ATTACK, -1);
    SKILLS_SetRightActiveSkill(pUnit, SKILL_ATTACK, -1);

// build: symbol ?GAME_GetUnitClassId@* 0x00451F60
    for (int i = 0; i < SKILLS_GetPlayerSkillCount(GAME_GetUnitClassId(pOwner)); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(GAME_GetUnitClassId(pOwner), i);

        if (AITHINK_ShadowMasterCheckTargetPetType(pGame, pOwner, pUnit, nSkillId))
        {
            SKILLS_GetSkillById(pUnit, nSkillId, -1);
            const int nLevel = AITHINK_GetShadowMasterSkillLevel(pGame, pUnit, pOwner, nParam, nSkillId);
            SKILLS_AssignSkill(pUnit, nSkillId, nLevel, 0, ".\\Ai\\AiThink4.cpp", 3069);
        }
    }
}

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0)
    {
        return 0;
    }

    return sub_0046ACE0(nMissileId);
}

static __forceinline D2StatListStrc* GetAuraStateStatList(D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord)
{
    if (pSkillsTxtRecord->nAuraState > 0 && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    }

    return 0;
}

static inline int AI_ClampChance(int nChance)
{
    if (nChance > 5 && nChance < 100)
    {
        return nChance;
    }

    if (nChance <= 5)
    {
        return 5;
    }

    return 100;
}

enum D2C_J11AiConstants
{
    LEVEL_AI_TRAPARROW_RANDOM = 40,
    UNITFLAG_J11_SPAWNED = 0x4000000,
    STATE_J11_SPAWNED = 184,
};

static inline int CLIENTS_GetUnitXInline_Totem(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYInline_Totem(D2UnitStrc* pUnit)
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

enum
{
    UNITFLAG_ISMERC = 0x00000200,
    MONSTATS2FLAGINDEX_SOFT = 12,
};

// 0x005E7590
void __fastcall AITHINK_Fn081_JarJar(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (AITHINK_InitHomeCommand(pGame, pUnit, pAiTickParam))
    {
        return;
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!ACT2Q4_HasGuardMovedToEndPosition(pGame))
    {
        D2CoordStrc coords;
        coords.nX = pAiCmd->nCmdParam[1];
        coords.nY = pAiCmd->nCmdParam[2];

        int bFree = 1;
        if (ACT2Q4_GetGuardCoordinates(pGame, &coords))
        {
            bFree = 0;
        }

        if (pAiCmd->nCmdParam[4] < pGame->dwGameFrame && pGame->dwGameFrame - pAiCmd->nCmdParam[4] < 200)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }

        if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, coords.nX, coords.nY) > 1)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coords.nX, coords.nY);
            pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            return;
        }

        if (bFree)
        {
            if (AITHINK_HandleNpcProximityAndInteraction(pGame, pUnit, pAiTickParam))
            {
                pAiCmd->nCmdParam[4] = pGame->dwGameFrame;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        }
        return;
    }

    if (pAiCmd)
    {
        int bCloseToTarget;
        D2UnitStrc* pOwner = AITACTICS_FindNearbyPlayerOrSelf(pGame, pUnit, &bCloseToTarget);
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
        if (ACT2Q4_IsHaremBlockerObjectOpened(pGame) && (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 2)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3) > 7)
        {
            AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2] - 3);
            return;
        }

        if (!AITHINK_HandleNpcProximityAndInteraction(pGame, pUnit, pAiTickParam) && pOwner && pOwner != pUnit)
        {
            if (pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (nDistance < 12)
                {
                    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 100)
                    {
                        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, 2);
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            }

            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 1000) < 50)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
            }
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 120);
}

// 0x005E77A0
int __fastcall AITHINK_SpawnNpcPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pAiTickParam)
{
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 3, 0);

    if (!pCurrentAiCmd || pCurrentAiCmd->nCmdParam[1] || pCurrentAiCmd->nCmdParam[2])
    {
        return 0;
    }

    pCurrentAiCmd->nCmdParam[1] = CLIENTS_GetUnitX(pUnit) + 3;
    pCurrentAiCmd->nCmdParam[2] = CLIENTS_GetUnitY(pUnit) + 3;

    int (__fastcall* pfUpdatePortalCoordinates)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_UpdateCainPortalCoordinates;
    void (__fastcall* pfSpawnPortal)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_SpawnCainPortalInTown;
    if (pUnit && pUnit->dwClassId == MONSTER_DREHYAICED)
    {
        pfUpdatePortalCoordinates = ACT5Q3_InitializeDrehyaPortalCoordinates;
        pfSpawnPortal = ACT5Q3_OnDrehyaRescued;
    }

    if (!pfUpdatePortalCoordinates(pGame, pUnit))
    {
        pfSpawnPortal(pGame, pUnit);
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEAD, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
    }

    pCurrentAiCmd->nCmdParam[3] = 1;
    pCurrentAiCmd->nCmdParam[4] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
    return 1;
}

// 0x005E7880
void __fastcall AITHINK_Fn031_NpcOutOfTown(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    bool bDrehya = false;
    if (pUnit && pUnit->dwClassId == MONSTER_DREHYAICED)
        bDrehya = true;
    if (AITHINK_SpawnNpcPortal(pGame, pUnit, pTick))
        return;
    if (bDrehya)
        ACT5Q3_UpdateStatusOnActivate(pGame);
    if (MONSTERAI_HasInteractUnit(GetMonInteract(pUnit)))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
        return;
    }
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 3, 0);
    if (pUnit && pUnit->dwAnimMode == MONMODE_DEAD)
        return;
    AITHINK_HandleNpcProximityAndInteraction(pGame, pUnit, pTick);
    if (pCmd)
    {
        if (pCmd->nCmdParam[3] >= 2)
        {
            pCmd->nCmdParam[3] += 1;
            int (__fastcall* pfGetCoords)(D2GameStrc*, D2UnitStrc*, D2CoordStrc*) = ACT1Q4_GetCainPortalOutsideTownCoordinates;
            void (__fastcall* pfSpawnPortal)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_SpawnCainPortalInTown;
            if (bDrehya)
            {
                pfGetCoords = ACT5Q3_GetDrehyaPortalCoordinates;
                pfSpawnPortal = ACT5Q3_OnDrehyaRescued;
            }
            D2CoordStrc coords;
            if (pfGetCoords(pGame, pUnit, &coords))
            {
                if (pCmd->nCmdParam[3] < 8 && (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, coords.nX, coords.nY) > 0)
                {
                    AITACTICS_WalkToTargetCoordinates(pGame, pUnit, coords.nX, coords.nY);
                    return;
                }
                pfSpawnPortal(pGame, pUnit);
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEAD, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
                return;
            }
        }
        else
        {
            if ((int)(unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]) > 1 && pCmd->nCmdParam[4] <= 5)
            {
                pCmd->nCmdParam[4] += 1;
                if (bDrehya && ACT5Q3_IsDrehyaNotRescued(pGame))
                {
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
                    pCmd->nCmdParam[4] = 0;
                    return;
                }
                AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2]);
                return;
            }
            if (pCmd->nCmdParam[3] == 1)
            {
                int (__fastcall* pfSpawnPortal)(D2GameStrc*, D2UnitStrc*) = ACT1Q4_SpawnCainPortalOutsideTown;
                if (bDrehya)
                    pfSpawnPortal = ACT5Q3_SpawnDrehyaPortalOutsideTown;
                if (!pfSpawnPortal(pGame, pUnit))
                {
                    pCmd->nCmdParam[3] = 1;
                    pCmd->nCmdParam[4] = 1;
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
                    return;
                }
                pCmd->nCmdParam[3] = 2;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }
    AITHINK_SpawnNpcPortal(pGame, pUnit, pTick);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
}

// 0x005E7AC0
void __fastcall AITHINK_Fn060_GoodNpcRanged(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (!pUnit)
    {
        goto idle_short;
    }

    if (pUnit->dwAnimMode != 1)
    {
idle_short:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int nDistance;
        int bInMeleeRange;
        D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, &bInMeleeRange);
        if (pTarget && nDistance < 20)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
            {
                if (pUnit->dwClassId == 271)
                {
                    AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                    return;
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
            {
                sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
            return;
        }
    }

    if (AI_ROLL_PERCENT(pSeed) < 20)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005E7C10
void __fastcall AITHINK_SpecialState06_HireableNonPlayerOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (AI_GetAnimMode(pUnit) != 1)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int nDistance;
        int bCombat;
        D2UnitStrc* pTarget = sub_6FCF2110(pGame, pUnit, pAiTickParam->pAiControl, &nDistance, &bCombat);
        if (pTarget)
        {
            const int nRand = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (bCombat)
            {
                if (nRand < 80)
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                    return;
                }

                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                return;
            }

            if (nRand < 30)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 20)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E7D30
int __fastcall AITHINK_IsInTownOrRoomless(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 1;
    }

    return DUNGEON_IsRoomInTown(pRoom) != 0;
}

// 0x005E7D60
void __fastcall AITHINK_Fn062_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// 0x005E7DC0
void __fastcall AITHINK_SpecialState08_TownRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bCombat);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
    }
}

// 0x005E7E20
void __fastcall AITHINK_Fn058_Navi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (MONSTERAI_HasInteractUnit(AITHINK_GetMonInteractInline(pUnit)))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    int bCloseToTarget;
    D2UnitStrc* pPlayer = AITACTICS_FindNearbyPlayerOrSelf(pGame, pUnit, &bCloseToTarget);
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && !PLAYER_IsBusy(pPlayer) && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) && bCloseToTarget)
    {
        D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
        if (!pAiControl->dwAiParam[1])
        {
            pAiControl->dwAiParam[1] = 60;

            if (pPlayer->dwUnitType == UNIT_PLAYER)
            {
                SUNIT_AttachSound(pUnit, 18, pPlayer);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
                return;
            }
        }
        else
        {
            if (pAiControl->dwAiParam[1] < 0)
            {
                pAiControl->dwAiParam[1] = 0;
            }

            if (pAiControl->dwAiParam[1] > 0)
            {
                --pAiControl->dwAiParam[1];
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
        return;
    }

    int bInMeleeRange;
    int nDistance;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (pTarget && nDistance < 25)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 50);
}

// 0x005E7F50
void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (UNITS_GetRoom(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
    }
}

// 0x005E7F80
void __fastcall D2GAME_AI_SpecialState09_6FCE7C40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCurrentAiCmd && pCurrentAiCmd->nCmdParam[0] == 8)
    {
        AIGENERAL_FreeMinionList(pUnit);
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
    }
    else
    {
        int nCount = 0;
        AIGENERAL_ExecuteCallbackOnMinions(pUnit, &nCount, 0, AITHINK_MinionCallback_CheckDead);
        if (AIUTIL_IsGettingHit(pUnit) || nCount || nDistance < 20)
        {
            D2AiCmdStrc aiCmd;
            aiCmd.nCmdParam[0] = 8;
            AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
            AIGENERAL_FreeMinionList(pUnit);
            AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, AISPECIALSTATE_NONE);
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E8020
void __fastcall AITHINK_SpecialState10_17_DimVision(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2UnitStrc* pTarget = pTick->pTarget;
    if (pTick->bCombat && !CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, MON_FLAG)
        && sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, ATTACK_MODE))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, ATTACK_MODE, pTarget);
        return;
    }
    if (AI_RollPercentage(pUnit) < WALK_CHANCE)
        AITACTICS_WalkCloseToUnit(pGame, pUnit, WALK_DISTANCE);
    else
        AITACTICS_IdleInNeutralMode(pGame, pUnit, IDLE_FRAMES);
}

// 0x005E80E0
void __fastcall D2GAME_AI_SpecialState11_SetTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
        sub_6FC61E30(pUnit, 1, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    case UNIT_MONSTER:
        sub_6FC61E30(pUnit, 2, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    case UNIT_MISSILE:
        sub_6FC61E30(pUnit, 4, !pTarget ? -1 : pTarget->dwUnitId);
        break;
    }
}

// 0x005E8340
void __fastcall D2GAME_AI_SpecialState12_6FCE81B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit_Inline(pUnit), AISPECIALSTATE_NONE);
        AITHINK_IdleInline(pGame, pUnit, 1);
        return;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
        return;
    }

    int bCombat = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    if (bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    int nDistance;
    D2UnitStrc* pTargetUnit = AITACTICS_FindTargetOrIdleInNeutralMode(pGame, pUnit, pAiTickParam->pAiControl, &nDistance, &bCombat);
    if (pTargetUnit && bCombat)
    {
        pAiControl->dwAiParam[0] = 0;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTargetUnit);
        return;
    }

    pAiControl->dwAiParam[0] = 1;
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
}

// 0x005E8480
void __fastcall AITHINK_ResetAiAndPreserveHomeCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam1 = 0;
    int nParam2 = 0;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (pCurrentAiCmd)
    {
        nParam1 = pCurrentAiCmd->nCmdParam[1];
        nParam2 = pCurrentAiCmd->nCmdParam[2];
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);

    if (!AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0) && nParam1 && nParam2)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = nParam1;
        aiCmd.nCmdParam[2] = nParam2;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005E8530
int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiCmdStrc* pArgs)
{
    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);

    int nDistanceWeight = 0;
    if (pArgs && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pArgs->nCmdParam[1], pArgs->nCmdParam[2]) > 85 && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pArgs->nCmdParam[1], pArgs->nCmdParam[2]) < 85)
    {
        nDistanceWeight = 100;
    }

    const int nDamageResist = STATLIST_UnitGetStatValue(pTarget, STAT_DAMAGERESIST, 0);
    const int nFireResist = STATLIST_UnitGetStatValue(pTarget, STAT_FIRERESIST, 0);
    const int nLightningResist = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTRESIST, 0);
    const int nMagicResist = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICRESIST, 0);
    const int nColdResist = !bInMeleeRange ? 0 : STATLIST_UnitGetStatValue(pTarget, STAT_COLDRESIST, 0);
    const int nResistWeight = (nFireResist + nColdResist + nLightningResist + 4 * (nDamageResist + 2 * nMagicResist)) / 15;

    const int nMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAXDAMAGE, 0);
    const int nFireMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_FIREMAXDAM, 0);
    const int nLightningMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTMAXDAM, 0);
    const int nMagicMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICMAXDAM, 0);
    const int nColdMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_COLDMAXDAM, 0);
    const int nPoisonMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_POISONMAXDAM, 0) >> 8;
    const int nDamageWeight = (nMaxDamage + nFireMaxDamage + nLightningMaxDamage + nMagicMaxDamage + nColdMaxDamage + nPoisonMaxDamage) / 2;

    const int nColdStateWeight = STATES_CheckState(pTarget, STATE_COLD) ? 100 : 0;
    const int nLifePercentageWeight = UNITS_GetCurrentLifePercentage(pTarget) < 20 ? 100 : 0;

    int nLeftSkillLevel;
    int nRightSkillLevel;
    unsigned char nLeftSkillAttackRank;
    unsigned char nRightSkillAttackRank;
    nLeftSkillLevel = nRightSkillLevel = 0;
    nLeftSkillAttackRank = nRightSkillAttackRank = 0;

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pTarget);
    if (pLeftSkill)
    {
        nLeftSkillLevel = SKILLS_GetSkillLevel(pTarget, pLeftSkill, 1);
        nLeftSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\Ai\\AiThink4.cpp", 0x225))->nAttackRank;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pTarget);
    if (pRightSkill)
    {
        nRightSkillLevel = SKILLS_GetSkillLevel(pTarget, pRightSkill, 1);
        nRightSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\Ai\\AiThink4.cpp", 0x22B))->nAttackRank;
    }

    const int nAttackRankWeight = (nLeftSkillLevel * nLeftSkillAttackRank + nRightSkillLevel * nRightSkillAttackRank) / 4;

    int nCollisionRangeWeight = 0;
    if (bInMeleeRange)
    {
        nCollisionRangeWeight = 100;
    }
    else if (AIUTIL_HasClearMissilePath(pUnit, pTarget))
    {
        nCollisionRangeWeight = 75;
    }

    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pTarget->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        if (pMonStatsTxtRecord->nThreat <= 1)
        {
            return 0;
        }
    }

    int nTotalScore = (nResistWeight + 5 * (nCollisionRangeWeight + nDistanceWeight) + 2 * (nDamageWeight + nAttackRankWeight + 2 * nColdStateWeight) + 3 * nLifePercentageWeight) / 22;
    if (!nTotalScore)
    {
        nTotalScore = 1;
    }

    return nTotalScore;
}

// 0x005E8810
int __fastcall AITHINK_RollDiabloAction(D2AiControlStrc* pAi,D2UnitStrc* pUnit,D2UnitStrc* pTarget,unsigned int nDistance,int nTargets,D2AiCmdStrc* pInfo)
{
    if(pAi->dwAiParam[0]) return pAi->dwAiParam[0];
    if(!pTarget)
    {
        if(COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit),sub_0045ADF0(pUnit),sub_0045AE20(pUnit),2,64)) return 16;
        return (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed)%1000)<1 ? 4:11;
    }
    D2GameStrc* pGame=SUNIT_GetGameFromUnit(pTarget);
    if(!pGame)pGame=SUNIT_GetGameFromUnit(pUnit);
    D2UnitStrc* pPortal=0;
    int bPortal=0;
    if((!pTarget ? 6:pTarget->dwUnitType)==0)
    {
        pPortal=SUNIT_GetServerUnit(pGame,2,PLAYER_GetUniqueIdFromPlayerData(pTarget));
        if(pPortal && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal))==LEVEL_CHAOSSANCTUM)
            if(sub_006417F0_GetDistance(pPortal,pInfo->nCmdParam[1],pInfo->nCmdParam[2])<85)bPortal=1;
    }
    int bDangerousSkill=0;
    D2SkillStrc* pSkill=UNITS_GetLeftSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,639);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    pSkill=UNITS_GetRightSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,646);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    int bVeryFar=0;
    int bFar=0;
    if(pInfo)
    {
        int nDist=sub_005DC480_GetDistance(pTarget,pInfo->nCmdParam[1],pInfo->nCmdParam[2]);
        if(nDist>85)bFar=1;
        if(nDist>105)bVeryFar=1;
    }
    int bMelee=UNITS_IsInMeleeRange(pUnit,pTarget,0);
    int bAttack=sub_005DD290_CheckAttack(pUnit,pTarget);
    int nFireRes=STATLIST_UnitGetStatValue(pTarget,39,0);
    int nColdRes=STATLIST_UnitGetStatValue(pTarget,41,0);
    int nWeights[17];
    int bInitialized=0;
    if(bMelee)
    {
        int nInitial[17]={0,0,40,70,0,40,24,40,15,0,0,0,0,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(UNITS_GetCurrentLifePercentage(pTarget)<20)nWeights[2]=50;
        if(STATES_CheckState(pTarget,STATE_COLD)){nWeights[7]=0;nWeights[8]=0;}
        if(nFireRes>nColdRes)nWeights[6]-=10;
        if(nFireRes<nColdRes)nWeights[6]+=10;
        if(!bAttack){nWeights[5]=0;nWeights[6]=0;}
        if(bPortal)nWeights[15]=10;
        bInitialized=1;
    }
    if(!bAttack)
    {
        if(!bInitialized)
        {
            int nInitial[17]={0,0,0,0,5,0,25,0,25,40,0,0,25,0,0,0,0};
            memcpy(nWeights,nInitial,sizeof(nWeights));
            if(nTargets<2){nWeights[6]=0;nWeights[1]=25;nWeights[8]-=5;nWeights[9]=0;}
            if(bDangerousSkill && !bFar)nWeights[13]=15;
            else if(bFar)
            {
                nWeights[1]=0;nWeights[12]=15;nWeights[13]=25;
                if(!nWeights[9])nWeights[9]=20;
                if(nTargets<2)nWeights[9]-=5;
            }
            if(bVeryFar)nWeights[14]=60;
            if(bPortal)nWeights[15]=20;
        }
    }
    else if(!bInitialized)
    {
        int nInitial[17]={0,0,0,0,0,25,25,0,15,20,10,0,20,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit,pTarget)>25){nWeights[10]=20;nWeights[5]=0;nWeights[8]-=5;}
        if(nFireRes>nColdRes){nWeights[6]-=10;nWeights[8]-=10;}
        if(nFireRes<nColdRes){nWeights[6]+=10;nWeights[8]+=10;}
        if(nTargets<2)nWeights[6]-=10;
        if(nTargets>3)nWeights[6]+=5;
        if(nDistance>60)nWeights[9]+=10;
        D2PlayerCountBonusStrc tBonus;
        MONSTER_GetPlayerCountBonus(pGame,&tBonus,UNITS_GetRoom(pUnit),pUnit);
        if(nTargets<2 && tBonus.nDifficulty<2)nWeights[9]=0;
        if(bDangerousSkill && !bFar){nWeights[6]+=10;nWeights[10]=30;nWeights[13]=15;}
        else if(bFar)
        {
            nWeights[1]=0;nWeights[12]=10;nWeights[10]=0;nWeights[13]=15;
            if(!nWeights[9])nWeights[9]=10;
        }
        if(bVeryFar){nWeights[9]=20;nWeights[14]=60;}
        if(bPortal)nWeights[15]=15;
    }
    if(sub_005FD470(pGame,pUnit,SKILL_DIABPRISON,pTarget,0,0))nWeights[9]=0;
    if(nWeights[15] && pPortal && !sub_005FD470(pGame,pUnit,SKILL_DIABPRISON,pPortal,0,0))nWeights[15]=0;
    int* pWeight=nWeights;
    int nTotal=0;
    for(int n=17;n;--n)nTotal+=*pWeight++;
    int nRoll=SEED_RollBounded(&pUnit->pSeed,nTotal);
    int nSum=0;
    pWeight=nWeights;
    for(int i=0;i<17;++i,++pWeight)
    {
        nSum+=*pWeight;
        if(nRoll<nSum)return i;
    }
    return 11;
}

// 0x005E8EB0
int __fastcall AITHINK_CullPotentialTargetsForDiablo(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2_ASSERT(pUnit, 876);
    D2_ASSERT(pTarget, 877);

    if (pUnit->nAct != pTarget->nAct)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTarget, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)) < 1020;
}

// 0x005E9750
int __fastcall AITHINK_RollUberDiabloAction(D2AiControlStrc* pAi,D2UnitStrc* pUnit,D2UnitStrc* pTarget,unsigned int nDistance,int nTargets,D2AiCmdStrc* pInfo)
{
    if(pAi->dwAiParam[0]) return pAi->dwAiParam[0];
    if(!pTarget)
    {
        if(COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit),sub_0045ADF0(pUnit),sub_0045AE20(pUnit),2,64)) return 16;
        return (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed)%1000)<1 ? 4:11;
    }
    D2GameStrc* pGame=SUNIT_GetGameFromUnit(pTarget);
    if(!pGame)pGame=SUNIT_GetGameFromUnit(pUnit);
    D2UnitStrc* pPortal=0;
    int bPortal=0;
    if((!pTarget ? 6:pTarget->dwUnitType)==0)
    {
        pPortal=SUNIT_GetServerUnit(pGame,2,PLAYER_GetUniqueIdFromPlayerData(pTarget));
        if(pPortal && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal))==LEVEL_CHAOSSANCTUM)
            if(sub_006417F0_GetDistance(pPortal,pInfo->nCmdParam[1],pInfo->nCmdParam[2])<85)bPortal=1;
    }
    int bDangerousSkill=0;
    D2SkillStrc* pSkill=UNITS_GetLeftSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,1356);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    pSkill=UNITS_GetRightSkill(pTarget);
    if(pSkill)
    {
        int nSkill=SKILLS_GetSkillIdFromSkill(pSkill,gszAiThink4Source,1363);
        if(nSkill==59 || nSkill==56)bDangerousSkill=1;
        if(nSkill==51) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>3)bDangerousSkill=1;}
        else if(nSkill==27) {if(SKILLS_GetSkillLevel(pTarget,pSkill,1)>7)bDangerousSkill=1;}
    }
    int bFar=0;
    int bVeryFar=0;
    if(pInfo)
    {
        int nDist=AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget,pUnit);
        if(nDist>85)bFar=1;
        if(nDist>105)bVeryFar=1;
    }
    int bMelee=UNITS_IsInMeleeRange(pUnit,pTarget,0);
    int bAttack=sub_005DD290_CheckAttack(pUnit,pTarget);
    int nFireRes=STATLIST_UnitGetStatValue(pTarget,39,0);
    int nColdRes=STATLIST_UnitGetStatValue(pTarget,41,0);
    int nWeights[17];
    int bInitialized=0;
    if(bMelee)
    {
        int nInitial[17]={0,0,40,70,0,75,24,40,15,0,0,0,0,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(UNITS_GetCurrentLifePercentage(pTarget)<20)nWeights[2]=50;
        if(STATES_CheckState(pTarget,STATE_COLD)){nWeights[7]=0;nWeights[8]=0;}
        if(nFireRes>nColdRes)nWeights[6]-=10;
        if(nFireRes<nColdRes)nWeights[6]+=10;
        if(!bAttack){nWeights[5]=0;nWeights[6]=0;}
        if(bPortal)nWeights[15]=10;
        bInitialized=1;
    }
    if(!bAttack)
    {
        if(!bInitialized)
        {
            int nInitial[17]={0,0,0,0,5,0,25,0,25,40,0,0,25,0,0,0,0};
            memcpy(nWeights,nInitial,sizeof(nWeights));
            if(nTargets<2){nWeights[6]=0;nWeights[1]=25;nWeights[8]-=5;nWeights[9]=0;}
            if(bDangerousSkill && !bFar)nWeights[13]=15;
            else if(bFar)
            {
                nWeights[1]=60;nWeights[12]=15;nWeights[13]=25;
                if(!nWeights[9])nWeights[9]=20;
                if(nTargets<2)nWeights[9]-=5;
            }
            if(bVeryFar)nWeights[1]=60;
            if(bPortal)nWeights[15]=20;
        }
    }
    else if(!bInitialized)
    {
        int nInitial[17]={0,0,0,0,0,5,25,0,15,20,10,0,20,0,0,0,0};
        memcpy(nWeights,nInitial,sizeof(nWeights));
        if(AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit,pTarget)>25){nWeights[10]=20;nWeights[5]=0;nWeights[8]-=5;}
        if(nFireRes>nColdRes){nWeights[6]-=10;nWeights[8]-=10;}
        if(nFireRes<nColdRes){nWeights[6]+=10;nWeights[8]+=10;}
        if(nTargets<2)nWeights[6]-=10;
        if(nTargets>3)nWeights[6]+=5;
        if(nDistance>60)nWeights[9]+=10;
        D2PlayerCountBonusStrc tBonus;
        MONSTER_GetPlayerCountBonus(pGame,&tBonus,UNITS_GetRoom(pUnit),pUnit);
        if(nTargets<2 && tBonus.nDifficulty<2)nWeights[9]=0;
        if(bDangerousSkill && !bFar){nWeights[6]+=10;nWeights[10]=30;nWeights[13]=15;}
        else if(bFar)
        {
            nWeights[1]=50;nWeights[10]=0;nWeights[13]=15;
            if(!nWeights[9])nWeights[9]=10;
        }
        if(bVeryFar){nWeights[9]=20;nWeights[1]=60;}
        if(bPortal)nWeights[15]=15;
    }
    if(sub_005FD470(pGame,pUnit,SKILL_DIABPRISON,pTarget,0,0))nWeights[9]=0;
    if(nWeights[15] && pPortal && !sub_005FD470(pGame,pUnit,SKILL_DIABPRISON,pPortal,0,0))nWeights[15]=0;
    int* pWeight=nWeights;
    int nTotal=0;
    for(int n=17;n;--n)nTotal+=*pWeight++;
    int nRoll=SEED_RollBounded(&pUnit->pSeed,nTotal);
    int nSum=0;
    pWeight=nWeights;
    for(int i=0;i<17;++i,++pWeight)
    {
        nSum+=*pWeight;
        if(nRoll<nSum)return i;
    }
    return 11;
}

// 0x005E9DD0
void __fastcall AITHINK_SpawnUberDiabloMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget)
    {
        MONSTERSPAWN_SpawnAtUnit(pGame, pTarget, MONSTER_DEMONHOLE, MONMODE_NEUTRAL, 4, 64);
    }
}

// 0x005E9DF0
void __fastcall AITHINK_Fn147_UberDiablo(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
}

// 0x005E9E00
void __fastcall AITHINK_Fn042_Vendor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (AI_RollPercentage(pUnit) < 20)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_SKILL1, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
}

// 0x005E9E60
void __fastcall AITHINK_Fn086_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if ( pAiTickParam->nTargetDistance < 25 && AI_RollPercentage(pUnit) < 60)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005E9F10
void __fastcall AITHINK_Fn099_TrappedSoul(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2CoordStrc unitCoord;
    D2CoordStrc targetCoord;

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }

    UNITS_GetCoords(pUnit, &unitCoord);

    if (pTarget && nDistance < 5)
    {
        if (!pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = 1;
            pAiControl->dwAiParam[1] = pGame->dwGameFrame;
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
            return;
        }

        if (bCombat && pGame->dwGameFrame > pAiControl->dwAiParam[1])
        {
            UNITS_GetCoords(pTarget, &targetCoord);

            if ((unsigned int)unitCoord.nX >= (unsigned int)targetCoord.nX && (unsigned int)unitCoord.nY <= (unsigned int)targetCoord.nY)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 35;
                return;
            }

            if ((unsigned int)unitCoord.nX <= (unsigned int)targetCoord.nX && (unsigned int)unitCoord.nY >= (unsigned int)targetCoord.nY)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 35;
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 5;
            }
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        }
    }
    else
    {
        if (pAiControl->dwAiParam[0])
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        }
    }
}

// 0x005EA080
void __fastcall AITHINK_Fn088_7TIllusion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[1] == 1)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_NOTC;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
        return;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_ATTACK1, UNITS_GetUnitXPositionInline(pUnit) - 10, UNITS_GetUnitYPositionInline(pUnit));
    pAiControl->dwAiParam[1] = 1;
}

// 0x005EA130
void __fastcall AITHINK_Fn091_DarkWanderer(D2GameStrc* game,D2UnitStrc* unit,D2AiTickParamStrc* tick)
{
 D2AiControlStrc* control=tick->pAiControl;
 D2UnitStrc* target=tick->pTarget;
 int distance=tick->nTargetDistance;
 D2CoordStrc coords;
 if(!ACT3Q7_GetWandererCoordinates(game,unit,&coords)) {
  AITACTICS_IdleInNeutralMode(game,unit,10);return;
 }
 if(!control->dwAiParam[0]) {
  control->dwAiParam[0]=1;control->dwAiParam[1]=0;control->dwAiParam[2]=0;
 }
 if(!target) {AITACTICS_IdleInNeutralMode(game,unit,10);return;}
 if(distance<20) {
  int nState=control->dwAiParam[0];
  {
  if(nState==1) {
   AITACTICS_WalkToTargetCoordinates(game,unit,coords.nX,coords.nY);
   control->dwAiParam[0]=2;return;
  }
  else if(nState==2) {
   if((unsigned int)AIUTIL_GetDistanceToCoordinates(unit,coords.nX,coords.nY)<2) {
    if(unit) unit->dwFlags|=0x20000;
    AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
    ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
   }
   if(control->dwAiParam[1]<3) {
    ++control->dwAiParam[1];
    AITACTICS_SetAiParam(unit,1,0,0);
    AITACTICS_WalkToTargetCoordinates(game,unit,coords.nX,coords.nY);return;
   }
   if(unit) unit->dwFlags|=0x20000;
   AITACTICS_ChangeModeAndTargetCoordinates(game,unit,0,0,0);
   ACT3Q7_CreateVileDogSpawnTimer(game,unit);return;
  }
  else { AITACTICS_IdleInNeutralMode(game,unit,40); return; }
 }
 }
 AITACTICS_IdleInNeutralMode(game,unit,40);
}

// 0x005EA290
void __fastcall AITHINK_InitializeAssassinSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = pGame->dwGameFrame;
    pAiControl->dwAiParam[1] = -1;
}

enum D2C_ClawViperAIParams
{
    CLAWVIPER_AI_PARAM_CHARGE_CHANCE_PCT = 0,
    CLAWVIPER_AI_PARAM_CHARGE_DISTANCE = 1,
    CLAWVIPER_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    CLAWVIPER_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT = 3,
    CLAWVIPER_AI_PARAM_STALL_DURATION = 4,
    CLAWVIPER_AI_PARAM_CHARGE_COLOR = 5,
    CLAWVIPEREX_AI_PARAM_SHOOT_DISTANCE = 6,
    CLAWVIPEREX_AI_PARAM_SHOOT_TIMER = 7,
};

enum D2C_VileDogAIParams
{
    VILEDOG_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    VILEDOG_AI_PARAM_STALL_DURATION = 1,
    VILEDOG_AI_PARAM_APPROACH_CHANCE_PCT = 2,
};

// 0x005EA2B0
int __fastcall AITHINK_AssasinSentryHasLostTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, int bDecreaseParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return 1;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[1] < 0)
    {
        const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
        if (!pSkill)
        {
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
            return 1;
        }

        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        D2AiControlStrc* pAiControlSet = pAiTickParam->pAiControl;
        pAiControlSet->dwAiParam[1] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[1] > 0)
    {
        if (bDecreaseParam)
        {
            pAiControl->dwAiParam[1] -= 1;
        }
        return 0;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
    return 1;
}

// 0x005EA3D0
void __fastcall AITHINK_Fn101_AssassinSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nActiveDistance = pMonStatsTxt->wAiParam[3][pGame->nDifficulty];
    const int nSkillId = pMonStatsTxt->nSkill[0];
    if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 0))
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, 12, 0);
    }

    int nDistance;
    int bInMeleeRange;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (!pTarget || nDistance >= nActiveDistance)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
        return;
    }

    const int nDifficulty = pGame->nDifficulty;
    if (sub_0045C390_SeedRollLimited(&pUnit->pSeed, 100) < pMonStatsTxt->wAiParam[0][nDifficulty])
    {
        if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pSkill), nSkillId, pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][nDifficulty]);
}

// 0x005EA510
void __fastcall AITHINK_InitializeBladeCreeper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = -1;
    pAiControl->dwAiParam[1] = 1;
    pAiControl->dwAiParam[2] = 0;
}

// 0x005EA540
void __fastcall AITHINK_Fn102_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nSkillId = pAiTickParam->pMonstatsTxt->nSkill[0];
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    if (pAiControl->dwAiParam[0] < 0)
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    if (pAiControl->dwAiParam[0] < pGame->dwGameFrame)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }

    if (!pAiControl->dwAiParam[2])
    {
        if (pSkillsTxtRecord->wSrvMissileA >= 0 && pSkillsTxtRecord->wSrvMissileA < sgptDataTables->nMissilesTxtRecordCount)
        {
            D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
            if (!pOwner)
            {
                pOwner = pUnit;
            }

            D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pGame, pOwner, nSkillId, nSkillLevel, pSkillsTxtRecord->wSrvMissileA, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            if (pMissile)
            {
                UNITS_StoreOwner(pMissile, pUnit);
                const int nAttackRate = UNITS_GetAttackRate(pOwner);
                STATLIST_AddUnitStat(pUnit, STAT_TOHIT, nAttackRate, 0);

                int nToHitPercent = STATLIST_UnitGetStatValue(pOwner, STAT_ITEM_TOHIT_PERCENT, 0);
                D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pOwner);
                if (pWeapon)
                {
                    nToHitPercent += SKILLS_GetWeaponMasteryBonus(pOwner, pWeapon, 0, 0);
                }

                STATLIST_AddUnitStat(pUnit, STAT_ITEM_TOHIT_PERCENT, nToHitPercent, 0);
            }

            pAiControl->dwAiParam[2] = 1;
        }
    }

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (!pAiCmd)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 3);
        return;
    }

    AITACTICS_SetVelocity(pUnit, 15, 0, 20);

    if (pAiControl->dwAiParam[1])
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }
    }
    else
    {
        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]))
        {
            return;
        }

        pAiControl->dwAiParam[1] = (pAiControl->dwAiParam[1] == 0);

        if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pAiCmd->nCmdParam[3], pAiCmd->nCmdParam[4]))
        {
            return;
        }
    }

    D2UnitStrc* pWalkOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pWalkOwner, 5))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
    }
}

// 0x005EA7A0
void __fastcall AITHINK_Fn103_InvisoPet(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);

    int nParam = AI_GetParam(pGame, pMonStatsTxt, 0);
    const int nAnimMode = !pOwner ? 0 : pOwner->dwAnimMode;

    const int bOwnerGetHit = nAnimMode == 3;
    if (bOwnerGetHit)
    {
        nParam /= 2;
    }

    if (pAiControl->dwAiParam[0] >= pGame->dwGameFrame && !bOwnerGetHit && !AIUTIL_IsGettingHit(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }

    const int nX = CLIENTS_GetUnitXInline(pOwner) + SEED_RollLimitedRandomNumber_Inline(&pUnit->pSeed, 2 * nParam) - nParam;
    const int nY = CLIENTS_GetUnitYInline(pOwner) + SEED_RollLimitedRandomNumber_Inline(&pUnit->pSeed, 2 * nParam) - nParam;

    AITACTICS_UseSkill(pGame, pUnit, 9, SKILL_TELEPORT2, 0, nX, nY);
    pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, 1);
}

// 0x005EA980
void __fastcall AITHINK_Fn104_DeathSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt;
    int nSkillId;
    D2SkillStrc* pSkill;
    int nSkillLevel;
    D2UnitStrc* pTarget;
    int nDistance;
    int bInMeleeRange;
    D2UnitStrc* pSkillTarget;
    int nLastTarget;
    int nRange;

    if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 0))
    {
        return;
    }

    pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    nSkillId = pMonStatsTxt->nSkill[0];
    pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return;
    }

    nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    if (nSkillLevel <= 0)
    {
        return;
    }

    pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, &bInMeleeRange);
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
        return;
    }

    pSkillTarget = SKILLS_FindCorpseNearTarget(pUnit, pTarget, nSkillId, nSkillLevel);
    nLastTarget = pAiTickParam->pAiControl->dwAiParam[0];
    nRange = MISSILE_GetSkillMissileRange(nSkillId, nSkillLevel) / 2;
    if (pSkillTarget && (!pSkillTarget ? -1 : pSkillTarget->dwUnitId) != nLastTarget && DRLG_UnitEdgeDistance(pTarget, pSkillTarget) < nRange)
    {
        if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        pAiTickParam->pAiControl->dwAiParam[0] = !pSkillTarget ? -1 : pSkillTarget->dwUnitId;
        AITACTICS_UseSkill(pGame, pUnit, 9, nSkillId, pSkillTarget, 0, 0);
        return;
    }

    if (nDistance < pMonStatsTxt->wAiParam[3][pGame->nDifficulty] && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStatsTxt->wAiParam[2][pGame->nDifficulty])
    {
        if (AITHINK_AssasinSentryHasLostTarget(pGame, pUnit, pAiTickParam, 1))
        {
            return;
        }

        AITACTICS_UseSkill(pGame, pUnit, 14, pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[1][pGame->nDifficulty]);
}

// 0x005EAB20
int __fastcall AITHINK_ShadowMasterCheckTargetPetType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const short nSummonId = pSkillsTxtRecord->wSummon;
    if (!nSummonId)
    {
        return 1;
    }

    const int nTargetClassId = !pTarget ? -1 : pTarget->dwClassId;
    if ((short)pSkillsTxtRecord->wSummon == (unsigned short)nTargetClassId)
    {
        return 0;
    }

    const int nPetType = (signed char)pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount || !pUnit)
    {
        return 1;
    }

    return PLAYERPETS_GetPetTypeFromPetGUID(pUnit, !pTarget ? -1 : pTarget->dwUnitId) != nPetType;
}

// 0x005EABF0
int __fastcall AITHINK_ShadowMasterCanUseSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, D2AiTickParamStrc* pAiTick)
{
    int bCombat = pAiTick->bCombat;
    D2UnitStrc* pTarget = pAiTick->pTarget;
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkills || !AITHINK_ShadowMasterCheckTargetPetType(pGame, pOwner, pUnit, nSkillId)) return 0;
    if (bCombat)
    {
        if (pSkills->nAiType != 4 && pSkills->nAiType != 13) return 0;
    }
    else
    {
        if (pSkills->nAiType == 4 || pSkills->nAiType == 13) return 0;
    }
    if (pSkills->nAiType == 1 && pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
    if (!pTarget)
    {
        switch (pSkills->nAiType)
        {
        case 2: case 4: case 5: case 11: case 12: case 13: return 0;
        }
    }
    if (pSkills->nAiType == 2)
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState)) return 0;
        if (pSkills->wAuraTargetState > 0 && STATES_CheckState(pTarget, pSkills->wAuraTargetState)) return 0;
    }
    if (pSkills->nFlags[0] & (unsigned char)gdwBitMasks[2])
    {
        if (pSkills->nAuraState > 0 && STATES_CheckState(pUnit, pSkills->nAuraState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkills->nAuraState);
            if (pStatList && STATLIST_GetStatValue(pStatList, pSkills->wAuraStat[0], 0) >= 3) return 0;
        }
    }
    return 1;
}

// 0x005EAD50
int __fastcall AITHINK_ShadowWarriorCheckUseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillStrc* pSkill, int nSkillId, int nUnused, D2Unk005EAD50ArgStrc* pArg)
{
    if (pSkill && pTarget && pArg)
    {
        D2Unk005EAD50CounterStrc* pCounter = pArg->pCounter;
        if (pCounter)
        {
            const int nClassId = pTarget->dwClassId;
            if (SKILLS_GetClassIdFromSkillId(nSkillId) != nClassId)
            {
                return 0;
            }

            if (!sub_005EABF0(pGame, pTarget, pUnit, nSkillId, pArg))
            {
                return 0;
            }

            const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            if (!nSkillId)
            {
                return 1;
            }

            const int nValue = SKILLS_GetShiftedManaCosts(nSkillId, nSkillLevel);
            D2SeedStrc* pSeed = &pUnit->pSeed;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) > 100 - nValue * 160 / 100)
            {
                return 0;
            }

            if (pCounter->nFrame > pGame->dwGameFrame)
            {
                return 0;
            }

            D2Unk005EAD50LimitsStrc* pLimits = pArg->pLimits;
            const int nMin = D2_MIN(D2_MAX(pLimits->nMin, 1), 128);
            const int nMax = D2_MIN(D2_MAX(pLimits->nMax, 1), 256);
            if (pCounter->nValue < nMin || pCounter->nValue > 32 * nMax)
            {
                pCounter->nValue = nMin;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, pCounter->nValue) > (int)SEED_RollLimitedRandomNumber(pSeed, 100))
            {
                return 0;
            }

            pCounter->nValue += (320 - pCounter->nBase) * nValue / (pCounter->nBase + 100);
            return 1;
        }
    }

    return 0;
}

// 0x005EAF00
int __fastcall AITHINK_GetShadowWarriorSkillLevel(D2GameStrc* pGame, D2UnitStrc* pOwner, D2SkillStrc* pSkill, D2AiTickParamStrc* pAiTickParam)
{
    int nSkillLevel = 1;
    if (pOwner)
    {
        nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    const int nLevel = pAiTickParam->pAiControl->dwAiParam[2] / 3 + nSkillLevel / 2;
    return nLevel > 1 ? nLevel : 1;
}

// 0x005EAF50
void __fastcall AITHINK_InitializeShadowWarrior(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }
}

enum D2C_M84PinHeadAi
{
    PINHEAD_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    PINHEAD_AI_PARAM_ATTACK_STALL_DURATION = 1,
    PINHEAD_AI_PARAM_APPROACH_CHANCE_PCT = 2,
    PINHEAD_AI_PARAM_IDLE_STALL_DURATION = 3,
    PINHEAD_AI_PARAM_SMITE_CHANCE_PCT = 4,
    PINHEAD_AI_PARAM_SKILL2_CHANCE_PCT = 5,
};

// 0x005EAFA0
void __fastcall AITHINK_Fn105_ShadowWarrior(D2GameStrc* game, D2UnitStrc* unit, D2AiTickParamStrc* tick)
{
    D2MonStatsTxt* stats = tick->pMonstatsTxt;
    D2UnitStrc* target = tick->pTarget;
    int combat = tick->bCombat;
    int distance = tick->nTargetDistance;
    D2GAME_EVENTS_Delete_6FC34840(game, unit, 2, 0);
    D2UnitStrc* owner = AIGENERAL_GetMinionOwner(unit);
    if (!owner) { AITACTICS_IdleInNeutralMode(game, unit, 100); return; }
    int limit = MINIMUM(MAXIMUM(tick->pMonstatsTxt->wAiParam[7][2], 1), 256);
    tick->pAiControl->dwAiParam[1] -= stats->wAiParam[3][game->nDifficulty] + 1;
    if (tick->pAiControl->dwAiParam[1] < 0 || tick->pAiControl->dwAiParam[1] > 64 * limit) tick->pAiControl->dwAiParam[1] = 0;
    int ownerDistance = DRLG_UnitEdgeDistance(unit, owner);
    if (distance > stats->wAiParam[0][game->nDifficulty] || ownerDistance > stats->wAiParam[1][game->nDifficulty]) target = 0;
    if (AITHINK_TryPetFollowOwner(game, unit, target, owner, combat, tick, 0, 6)) return;
    if (!target) goto idle;
    {
    D2SkillStrc* ownerRight = UNITS_GetRightSkill(owner);
    D2SkillStrc* ownerLeft = UNITS_GetLeftSkill(owner);
    if (!ownerRight || !ownerLeft) goto idle;
    int rightId = SKILLS_GetSkillIdFromSkill(ownerRight, ".\\Ai\\AiThink4.cpp", 0xB53);
    int leftId = SKILLS_GetSkillIdFromSkill(ownerLeft, ".\\Ai\\AiThink4.cpp", 0xB54);
    int rightLevel = AITHINK_GetShadowWarriorSkillLevel((D2GameStrc*)unit, owner, ownerRight, tick);
    int leftLevel = AITHINK_GetShadowWarriorSkillLevel((D2GameStrc*)unit, owner, ownerLeft, tick);
    SKILLS_AssignSkill(unit, rightId, rightLevel, 0, ".\\Ai\\AiThink4.cpp", 0xB59);
    SKILLS_AssignSkill(unit, leftId, leftLevel, 0, ".\\Ai\\AiThink4.cpp", 0xB5A);
    D2SkillStrc* right = SKILLS_GetSkillById(unit, rightId, -1);
    D2SkillStrc* left = SKILLS_GetSkillById(unit, leftId, -1);
    if (!right || !left) goto idle;
    D2SkillStrc* selected = right;
    if (SEED_RollLimitedRandomNumber(&unit->pSeed, 2)) selected = left;
    int skillId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB66);
    int count = MAXIMUM(tick->pAiControl->dwAiParam[2], 1);
    int chance = stats->wAiParam[2][game->nDifficulty] - 2 * count;
    chance = MINIMUM(MAXIMUM(chance, 5), 100);
    if (combat && (int)SEED_RollLimitedRandomNumber(&unit->pSeed, 100) < chance) {
        selected = SKILLS_GetSkillById(unit, SKILL_ATTACK, -1);
        skillId = 0;
    }
    if (!AITHINK_ShadowWarriorCheckUseSkill(game, unit, owner, selected, skillId, combat, (D2Unk005EAD50ArgStrc*)tick)) {
        selected = selected == left ? right : left;
        int alternativeId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB79);
        if (!AITHINK_ShadowWarriorCheckUseSkill(game, unit, owner, selected, alternativeId, combat, (D2Unk005EAD50ArgStrc*)tick)) {
            selected = SKILLS_GetSkillById(unit, SKILL_ATTACK, -1);
            if (!selected) {
                SKILLS_AssignSkill(unit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 0xB81);
                selected = SKILLS_GetSkillById(unit, SKILL_ATTACK, -1);
            }
        }
    }
    if (!selected) goto idle;
    skillId = SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB8F);
    if (D2Common_11016(unit, selected) == 1) {
        if (combat) {
            AITACTICS_UseSkill(game, unit, SKILLS_GetSkillMode(selected), SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xB96), target, 0, 0);
            D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(skillId);
            int level = SKILLS_GetSkillLevel(unit, selected, 1);
            if (level <= 1) level = 1;
            tick->pAiControl->dwAiParam[0] = SKILLS_EvaluateSkillFormula(unit, record->dwDelay, skillId, level) / 3 + game->dwGameFrame + 18;
            return;
        }
        AITACTICS_RunToTargetUnit(game, unit, target);
        return;
    }
    AITACTICS_UseSkill(game, unit, SKILLS_GetSkillMode(selected), SKILLS_GetSkillIdFromSkill(selected, ".\\Ai\\AiThink4.cpp", 0xBA8), target, 0, 0);
    D2SkillsTxt* record = sub_0045C4B0_GetSkillsTxtRecord(skillId);
    int level = SKILLS_GetSkillLevel(unit, selected, 1);
    if (level <= 1) level = 1;
    tick->pAiControl->dwAiParam[0] = SKILLS_EvaluateSkillFormula(unit, record->dwDelay, skillId, level) / 3 + game->dwGameFrame + 18;
    return;
    }
idle:
    AITACTICS_IdleInNeutralMode(game, unit, 25);
}

// 0x005EB420
int __fastcall AITHINK_GetShadowMasterSkillLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nParam, int nSkillId)
{
    int nSkillLevel = 1;
    if (pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pOwner, nSkillId, -1);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pOwner, pSkill, 0);
        }
    }

    const int nLevel = nSkillLevel / 2 + nParam / 2;
    if (nLevel > 1 && nLevel < 24)
    {
        return nLevel;
    }
    if (nLevel <= 1)
    {
        return 1;
    }
    return 24;
}

// 0x005EB5C0
void __fastcall AITHINK_InitializeShadowMasterAttackSkills(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[2] = 1;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pAiTickParam->pMonstatsTxt->wAiParam[7][0]);
    if (pSkill)
    {
        pAiControl->dwAiParam[2] = SKILLS_GetSkillLevel(pOwner, pSkill, 1);
    }

    if (!SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1))
    {
        SKILLS_AssignSkill(pUnit, 0, 1, 0, ".\\Ai\\AiThink4.cpp", 3101);
    }

    SKILLS_SetLeftActiveSkill(pUnit, SKILL_ATTACK, -1);
    SKILLS_SetRightActiveSkill(pUnit, SKILL_ATTACK, -1);
}

enum D2C_J07AiConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 0xE,
    MONSTATSFLAGINDEX_BYTE1_BIT0 = 0,
    MONSTATSFLAGINDEX_BYTE1_BIT7 = 7,
};

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

// 0x005EB650
int __fastcall AITHINK_IsTargetKillableByShadowMaster(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[MONSTATSFLAGINDEX_BYTE1_BIT0])
    {
        return 0;
    }

    if (!(pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[MONSTATSFLAGINDEX_BYTE1_BIT7]))
    {
        return 0;
    }

    if (pTarget->dwUnitType == UNIT_PLAYER)
    {
        return 1;
    }

    if (MONSTERS_IsBoss(0, pTarget))
    {
        return 1;
    }

    if (MONSTERS_IsPrimeEvil(pTarget))
    {
        return 1;
    }

    return MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE_CHAMPION) != 0;
}

// 0x005EB6D0
D2UnitStrc* __fastcall AITHINK_TargetCallback_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2ShadowMasterAiCallbackArgStrc* pArg = (D2ShadowMasterAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget || SUNIT_IsDead(pTarget) || !pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && STATLIST_AreUnitsAligned(pUnit, pTarget))
    {
        const int nClassId = MONSTERS_ValidateMonsterIdInline(CUNIT_GetMonsterBaseId(pTarget));
        switch (nClassId)
        {
        case MONSTER_WAKEOFDESTRUCTION:
        case MONSTER_CHARGEBOLTSENTRY:
        case MONSTER_LIGHTNINGSENTRY:
        case MONSTER_BLADECREEPER:
        case MONSTER_INFERNOSENTRY:
        case MONSTER_DEATHSENTRY:
            ++pArg->nSentryCount;
            return 0;

        default:
            break;
        }
    }

    if (!UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || !SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (pArg->pOwner)
    {
        const int nDistance = AITHINK_GetSquaredDistance(pArg->pOwner, pTarget);

        if (nDistance <= 100)
        {
            ++pArg->nTargetsNearOwner;
        }

        if (nDistance < pArg->nClosestToOwnerDistanceSquared)
        {
            pArg->pClosestTargetToOwner = pTarget;
            pArg->nClosestToOwnerDistanceSquared = nDistance;
        }
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance <= 1024)
    {
        ++pArg->nTargetCount;

        if (nDistance <= 100)
        {
            ++pArg->nCloseTargetCount;
        }

        if (nDistance < pArg->nClosestDistanceSquared)
        {
            pArg->pClosestTarget = pTarget;
            pArg->nClosestDistanceSquared = nDistance;
        }

        if (AITHINK_IsTargetKillableByShadowMaster(pUnit, pTarget))
        {
            pArg->pKillableTarget = pTarget;
        }
    }

    return 0;
}

struct D2StatesTxt;

static inline D2StatesTxt* STATES_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x005EB7F0
int __fastcall AITHINK_IsStateGroupActive(D2UnitStrc* pUnit, int nStateId)
{
    D2StatesTxt* pStatesTxtRecord = STATES_GetStatesTxtRecordInline(nStateId);
    if (!pStatesTxtRecord || !pStatesTxtRecord->wGroup)
    {
        return 0;
    }

    int nResult = 0;
    const int nGroup = (short)pStatesTxtRecord->wGroup;
    const int nCount = sgptDataTables->nStatesTxtRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (i != nStateId)
        {
            if ((short)STATES_GetStatesTxtRecordInline(i)->wGroup == nGroup && STATES_CheckState(pUnit, i))
            {
                nResult = 1;
            }
        }
    }

    return nResult;
}

// 0x005EB8B0
int __fastcall AITHINK_UseShadowMasterSkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int bCombat, D2UnitStrc* pTarget, int nX, int nY, D2AiTickParamStrc* pAiTickParam)
{
    if (pTarget && (pTarget == pOwner || pTarget == pUnit))
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (!pSkill)
    {
        return 0;
    }

    if (pTarget && (!UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit))))
    {
        return 0;
    }

    if (D2Common_11016(pUnit, pSkill) == 1 && !bCombat)
    {
        return AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, pTarget, 4);
    }

    return AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pSkill), nSkillId, pTarget, nX, nY);
}

// 0x005EB970
void __fastcall AITHINK_Fn106_143_ShadowMaster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int bCombat = pAiTickParam->bCombat;
    int nTargetDistance = pAiTickParam->nTargetDistance;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SkillListStrc* pSkillList = pUnit->pSkills;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!pSkillList)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 100);
        return;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    if (pOwner)
    {
        const int nOwnerDistance = AITHINK_GetSquaredDistance(pUnit, pOwner);
        if (nOwnerDistance > pMonStatsTxt->wAiParam[1][2] * pMonStatsTxt->wAiParam[1][2]
            && AITHINK_TryPetFollowOwner(pGame, pUnit, 0, pOwner, bCombat, pAiTickParam, 0, 6))
        {
            return;
        }
    }

    if (pAiControl->dwAiParam[0] > 0)
    {
        D2UnitStrc* pCurrentTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pCurrentTarget)
        {
            pTarget = pCurrentTarget;
        }

        if (!pTarget)
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
        }
        else
        {
            --pAiControl->dwAiParam[0];
            if (AITHINK_UseShadowMasterSkill(pGame, pOwner, pUnit, pAiControl->dwAiParam[1], bCombat, pTarget, 0, 0, pAiTickParam))
            {
                return;
            }
        }
    }

    if (nTargetDistance > pMonStatsTxt->wAiParam[1][1])
    {
        pTarget = 0;
    }

    if (!pTarget)
    {
        for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pSkillList); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szAiThink4File, 3443);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                switch (pSkillsTxtRecord->nAiType)
                {
                case 1:
                    if (pSkillsTxtRecord->nAiType == 1 && pSkillsTxtRecord->nAuraState > 0 && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (!AITHINK_IsStateGroupActive(pUnit, pSkillsTxtRecord->nAuraState) || (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 4)
                        {
                            if ((int)(SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 100) < 60)
                            {
                                D2SkillStrc* pUseSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                                if (pUseSkill)
                                {
                                    int nResult;
                                    if (D2Common_11016(pUnit, pUseSkill) == 1)
                                    {
                                        if (!bCombat)
                                        {
                                            nResult = AITACTICS_RunToTargetUnitWithFlags(pGame, pUnit, 0, 4);
                                        }
                                        else
                                        {
                                            nResult = AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pUseSkill), nSkillId, 0, 0, 0);
                                        }
                                    }
                                    else
                                    {
                                        nResult = AITACTICS_UseSkill(pGame, pUnit, SKILLS_GetSkillMode(pUseSkill), nSkillId, 0, 0, 0);
                                    }

                                    if (nResult)
                                    {
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    break;

                case 6:
                    if (!UNITS_GetLeftSkill(pUnit) && (int)(SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 100) < 20)
                    {
                        SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                    }
                    break;
                }
            }
        }
    }

    D2UnitStrc* pOwnerTarget = 0;
    if (pOwner)
    {
        pOwnerTarget = SUNIT_GetTargetUnit(pGame, pOwner);
        if (pOwnerTarget)
        {
            if (!SUNIT_IsDead(pOwnerTarget) && SUNIT_AreUnitsHostile(pGame, pUnit, pOwnerTarget))
            {
                pTarget = pOwnerTarget;
            }
            else
            {
                pOwnerTarget = 0;
            }
        }

        if (AITHINK_GetSquaredDistance(pUnit, pOwner) <= 144 && AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
        {
            return;
        }
    }

    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int nParam = pAiTickParam->pAiControl->dwAiParam[2];
    if (nParam <= 1)
    {
        nParam = 1;
    }

    int nChance = pMonStatsTxt->wAiParam[2][pGame->nDifficulty] - 2 * nParam;
    nChance = AI_ClampChance(nChance);

    if (!bCombat || (int)SEED_RollLimitedRandomNumber(pSeed, 100) >= nChance
        || !AITHINK_UseShadowMasterSkill(pGame, pOwner, pUnit, 0, bCombat, pTarget, 0, 0, pAiTickParam))
    {

        D2ShadowMasterAiCallbackArgStrc arg = {};
        arg.pOwner = pOwner;
        arg.nClosestDistanceSquared = 0x7FFFFFFF;
        arg.nClosestToOwnerDistanceSquared = 0x7FFFFFFF;
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_ShadowMaster, 1);

        if (!bCombat)
        {
            if (pOwnerTarget)
            {
                pTarget = pOwnerTarget;
            }
            else if (arg.pClosestTargetToOwner)
            {
                pTarget = arg.pClosestTargetToOwner;
            }
            else if (arg.pKillableTarget)
            {
                D2UnitStrc* pArg24 = arg.pKillableTarget;
                if (AITHINK_GetSquaredDistance(pUnit, pArg24) < 1024)
                {
                    pTarget = pArg24;
                }
            }

            if (!AITHINK_IsTargetKillableByShadowMaster(pUnit, pTarget))
            {
                D2UnitStrc* pTargetOwner = AIGENERAL_GetMinionOwner(pTarget);
                if (pTargetOwner && !SUNIT_IsDead(pTargetOwner) && AITHINK_GetSquaredDistance(pUnit, pTargetOwner) < 1024)
                {
                    pTarget = pTargetOwner;
                }
            }
        }

        const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
        const int nDistanceToTarget = AITHINK_GetSquaredDistance(pUnit, pTarget);

        int bProgressiveState;
        if (pMonStatsTxt->wAiParam[0][2] > 0 && STATES_CheckStateMaskPgsvOnUnit(pUnit))
        {
            bProgressiveState = 1;
        }
        else
        {
            bProgressiveState = 0;
        }

        const int bNotColliding = UNITS_TestCollisionWithUnit(pUnit, pTarget, COLLIDE_MISSILE_BARRIER) == 0;

        D2UnitStrc* pArg10 = arg.pClosestTargetToOwner;
        const int nArg20 = arg.nSentryCount;
        const int nArg1C = arg.nTargetCount;

        const int nArg0C = *(volatile int*)&arg.nCloseTargetCount; // volatile only fixes where the original loads this field (before 0x08 and 0x18)
        const int nArg08 = arg.nClosestDistanceSquared;
        const int nArg18 = arg.nTargetsNearOwner;

        if (nArg0C > 3)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 32) < 2 * nArg0C)
            {
                if (pOwner && AITHINK_GetSquaredDistance(pUnit, pOwner) > 36)
                {
                    AITACTICS_RunToTargetUnit(pGame, pUnit, pOwner);
                    return;
                }

                if (AITACTICS_RunAwayFromTarget(pGame, pUnit, pTarget, 8, 1))
                {
                    return;
                }
            }
        }

        int nAuraStatBonus = 0;

        D2ShadowMasterSkillStrc shadowMasterSkills[48];
        shadowMasterSkills[0].nSkillId = 0;
        shadowMasterSkills[0].nChance = 0;
        shadowMasterSkills[0].pTarget = pTarget;
        shadowMasterSkills[0].nX = 0;
        shadowMasterSkills[0].nY = 0;

        int nCounter = 1;
        const int nRandomPick = pMonStatsTxt->wAiParam[1][0];

        for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pSkillList); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, szAiThink4File, 3645);
            int nResistance = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                D2UnitStrc* pSkillTarget = pTarget;
                int nCurrentValue = 0;
                int nTemp = pSkillsTxtRecord->wAiBonus;
                nTemp += pSkillsTxtRecord->wReqLevel / 4 + nResistance;
                nResistance = 0;

                switch (pSkillsTxtRecord->nEType)
                {
                case ELEMTYPE_NONE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_DAMAGERESIST, 0);
                    break;

                case ELEMTYPE_FIRE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_FIRERESIST, 0);
                    break;

                case ELEMTYPE_LTNG:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTRESIST, 0);
                    break;

                case ELEMTYPE_COLD:
                case ELEMTYPE_FREEZE:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_COLDRESIST, 0);
                    break;

                case ELEMTYPE_POIS:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_POISONRESIST, 0);
                    break;

                case ELEMTYPE_MAGIC:
                    nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICRESIST, 0);
                    break;
                }

                nTemp += nResistance / -10;

                switch (pSkillsTxtRecord->nAiType)
                {
                case 1:
                    if (pSkillsTxtRecord->nAuraState <= 0 || STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (nArg08 <= 25)
                        {
                            nTemp -= 6;
                        }

                        if (AITHINK_IsStateGroupActive(pUnit, pSkillsTxtRecord->nAuraState))
                        {
                            nTemp -= 10;
                        }
                        else
                        {
                            nTemp += 10;
                        }

                        nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                        pSkillTarget = pUnit;
                    }
                    break;

                case 2:
                    if (pSkillsTxtRecord->nAuraState <= 0 || !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
                    {
                        if (pSkillsTxtRecord->wAuraTargetState <= 0 || !STATES_CheckState(pTarget, pSkillsTxtRecord->wAuraTargetState))
                        {
                            if (nArg08 <= 25)
                            {
                                nTemp -= 10;
                            }

                            nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                        }
                    }
                    break;

                case 3:
                    if (nArg20 > 5)
                    {
                        nTemp += -2 * nArg20;
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 7;
                    }

                    if (nArg1C < 3)
                    {
                        nTemp -= 10;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick) + 3 * (nArg1C - 3);
                    break;

                case 4:
                    if (nDistanceToTarget > pMonStatsTxt->wAiParam[0][0] * pMonStatsTxt->wAiParam[0][0])
                    {
                        nTemp -= 10;
                    }

                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (bCombat || nDistanceToTarget <= 25)
                    {
                        nTemp += 10;
                    }

                    if (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE])
                    {
                        if (D2StatListStrc* pStatList = GetAuraStateStatList(pUnit, pSkillsTxtRecord))
                        {
                            const int nAuraStatValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                            nAuraStatBonus += nAuraStatValue;
                            if (nAuraStatValue >= 3)
                            {
                                break;
                            }
                        }

                        nTemp += pMonStatsTxt->wAiParam[0][2];
                    }
                    else if (pMonStatsTxt->wAiParam[0][2] > 0 && !bProgressiveState)
                    {
                        nTemp -= 10;
                    }
                    else
                    {
                        nTemp += 4 * nAuraStatBonus + 3;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;

                case 5:
                    if (!bNotColliding)
                    {
                        break;
                    }

                    if (pSkillsTxtRecord->wSrvMissile < 0)
                    {
                        if (D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pSkillsTxtRecord->wSrvMissileA))
                        {
                            if (nDistanceToTarget >= (pMissilesTxtRecord->wRange - 1) * (pMissilesTxtRecord->wRange - 1))
                            {
                                break;
                            }
                        }
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (nDistanceToTarget <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (bProgressiveState)
                    {
                        nTemp -= 5;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;

                case 6:
                    if (!UNITS_GetLeftSkill(pUnit))
                    {
                        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 20)
                        {
                            SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                        }
                    }
                    else
                    {
                        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 6)
                        {
                            SKILLS_SetLeftActiveSkill(pUnit, nSkillId, -1);
                        }
                    }
                    break;

                case 7:
                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage > 66)
                    {
                        nCurrentValue = 0;
                        break;
                    }

                    pSkillTarget = 0;
                    if (!pOwner)
                    {
                        SEED_RollLimitedRandomNumber(pSeed, 40);
                        CLIENTS_GetUnitX(pUnit);
                        SEED_RollLimitedRandomNumber(pSeed, 40);
                        CLIENTS_GetUnitX(pUnit);
                    }
                    else
                    {
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitX(pTarget);
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitX(pTarget);
                        CLIENTS_GetUnitX(pOwner);
                        CLIENTS_GetUnitY(pOwner);
                    }

                    nCurrentValue += 10;
                    if (nLifePercentage < 45)
                    {
                        nCurrentValue += 10;
                    }
                    break;

                case 8:
                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage > 66)
                    {
                        nCurrentValue = 0;
                        break;
                    }

                    pSkillTarget = pUnit;
                    nCurrentValue *= 2;
                    if (nLifePercentage < 45)
                    {
                        nCurrentValue *= 2;
                    }
                    break;

                case 11:
                    if (!bNotColliding)
                    {
                        break;
                    }

                    if (pSkillsTxtRecord->wSrvMissile < 0)
                    {
                        if (D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pSkillsTxtRecord->wSrvMissileA))
                        {
                            if (nDistanceToTarget >= (pMissilesTxtRecord->wRange - 1) * (pMissilesTxtRecord->wRange - 1))
                            {
                                break;
                            }
                        }
                    }

                    if (nArg08 <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (nDistanceToTarget <= 25)
                    {
                        nTemp -= 5;
                    }

                    if (bProgressiveState)
                    {
                        nTemp -= 5;
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick) + 3 * nArg1C;
                    break;

                case 12:
                    if (GAME_GetUnitTypeOrInvalid(pTarget) == UNIT_MONSTER)
                    {
                        D2MonStatsTxt* pTargetMonStatsTxt = sub_0055B7E0_GetMonStatsTxtFromUnit(pTarget);
                        if (!pTargetMonStatsTxt || pTargetMonStatsTxt->nDrain[pGame->nDifficulty] < 25)
                        {
                            break;
                        }
                    }

                    if (nDistanceToTarget > pMonStatsTxt->wAiParam[0][0] * pMonStatsTxt->wAiParam[0][0])
                    {
                        nTemp -= 10;
                    }

                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (bCombat || nDistanceToTarget <= 25)
                    {
                        nTemp += 10;
                    }

                    if (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE])
                    {
                        if (D2StatListStrc* pStatList = GetAuraStateStatList(pUnit, pSkillsTxtRecord))
                        {
                            const int nAuraStatValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                            nAuraStatBonus += nAuraStatValue;
                            if (nAuraStatValue >= 3)
                            {
                                break;
                            }
                        }
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    if (nLifePercentage < 75)
                    {
                        nCurrentValue += 8;
                    }

                    if (nLifePercentage < 50)
                    {
                        nCurrentValue += 12;
                    }
                    break;

                case 13:
                    nTemp += pMonStatsTxt->wAiParam[0][1];

                    if (pMonStatsTxt->wAiParam[0][2] > 0 && !bProgressiveState)
                    {
                        nTemp -= 5;
                    }
                    else
                    {
                        nTemp += nAuraStatBonus;
                    }

                    if ((nLifePercentage < 50 || nArg0C > 3) && pArg10 && nArg18 < 4 && AITHINK_GetSquaredDistance(pUnit, pArg10) > 25)
                    {
                        nTemp += 20;
                        pSkillTarget = pArg10;
                    }
                    else
                    {
                        if (nDistanceToTarget < 25)
                        {
                            break;
                        }

                        if (nDistanceToTarget > 324)
                        {
                            nTemp += 10;
                        }
                    }

                    nCurrentValue = nTemp + SEED_RollLimitedRandomNumber(pSeed, nRandomPick);
                    break;
                }

                if (nCurrentValue > shadowMasterSkills[nCounter - 1].nChance)
                {
                    shadowMasterSkills[nCounter].nSkillId = nSkillId;
                    shadowMasterSkills[nCounter].pTarget = pSkillTarget;
                    shadowMasterSkills[nCounter].nChance = nCurrentValue;
                    shadowMasterSkills[nCounter].nX = 0;
                    shadowMasterSkills[nCounter].nY = 0;
                    ++nCounter;
                }
            }
        }

        while (nCounter)
        {
            --nCounter;

            if (SEED_RollRandomNumber_Inline(&pUnit->pSeed) & 3)
            {
                D2UnitStrc* pPickTarget = shadowMasterSkills[nCounter].pTarget;
                const int nPickSkillId = shadowMasterSkills[nCounter].nSkillId;
                const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pPickTarget, 0);
                if (AITHINK_UseShadowMasterSkill(pGame, pOwner, pUnit, nPickSkillId, bInMeleeRange, pPickTarget, shadowMasterSkills[nCounter].nX, shadowMasterSkills[nCounter].nY, pAiTickParam))
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nPickSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->wSrvDoFunc == 19)
                    {
                        pAiControl->dwAiParam[1] = nPickSkillId;
                        pAiControl->dwAiParam[0] = 25;
                    }
                    return;
                }
            }
        }

        if (pTarget)
        {
            const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
            if (AITHINK_UseShadowMasterSkill(pGame, pOwner, pUnit, 0, bInMeleeRange, pTarget, 0, 0, pAiTickParam))
            {
                return;
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}

// 0x005EC6A0
void __fastcall AITHINK_InitializeVineState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    pAiTickParam->pAiControl->dwAiParam[0] = 0;
}

// 0x005EC8C0
void __fastcall AITHINK_Fn111_CycleOfLife(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pTick->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner) return;
    D2UnitStrc* pTarget = 0;
    int bReachable = 0;
    int bUseSkill;
    int nDistance = 0;
    int nRange;
    D2UnitStrc* pCombatTarget = pTick->pTarget;
    int bCombat = pTick->bCombat;
    bUseSkill = 1;
    if (DRLG_UnitEdgeDistance(pUnit, pOwner) >= AI_PARAM(pGame, pMonStats, 4))
    {
        if (sub_005E3EA0(pGame, pOwner, pUnit, 3, 0, 0, 6)) return;
    }
    if (pCombatTarget && sub_005541B0_IsDead(pCombatTarget))
    {
        pCombatTarget = 0;
        bCombat = 0;
    }
    if (pMonStats->nSkill[0] > 0)
    {
        D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord_005EC8C0(pMonStats->nSkill[0]);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStats->nSkill[0]);
        if (pSkills && pSkill)
        {
            nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwAuraRangeCalc, pMonStats->nSkill[0], SKILLS_GetSkillLevel(pUnit, pSkill, 1));
            nRange = D2_MIN(D2_MAX(nRange, 5), 50);
            pTarget = SKILLS_FindUseableCorpse(pGame, pUnit, pOwner, nRange);
            if (pTarget) nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);
        }
    }
    if (nDistance >= AI_PARAM(pGame, pMonStats, 1))
        pTarget = 0;
    else if (pTarget)
        bReachable = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    if (sub_005E45D0_PetFollow(pGame, pUnit, pTarget, pOwner, bReachable, pTick, 0, 6)) return;
    int nClass;
    if (!pUnit) nClass = -1;
    else nClass = pUnit->dwClassId;
    int nCurrent;
    int nMaximum;
    switch (nClass)
    {
    case 426:
        nCurrent = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
        nMaximum = STATLIST_GetMaxLifeFromUnit(pOwner);
        if (nCurrent >= nMaximum) bUseSkill = 0;
        break;
    case 427:
        nCurrent = STATLIST_UnitGetStatValue(pOwner, STAT_MANA, 0);
        nMaximum = STATLIST_GetMaxManaFromUnit(pOwner);
        if (nCurrent >= nMaximum) bUseSkill = 0;
        break;
    }
    if (pTarget && bReachable && bUseSkill)
    {
        if (pAiControl->dwAiParam[1] + AI_PARAM(pGame, pMonStats, 0) < pGame->dwGameFrame)
        {
            AITACTICS_UseSkill(pGame, pUnit, 8, pMonStats->nSkill[0], pTarget, 0, 0);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame;
            return;
        }
    }
    if (bCombat && pCombatTarget)
    {
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 25)
        {
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pCombatTarget, (unsigned char)AI_PARAM(pGame, pMonStats, 3), 0);
            return;
        }
    }
    if (pTarget) sub_005DEC80_Walk(pGame, pUnit, pTarget, 7);
    else AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStats, 2));
}

// 0x005ECB70
void __fastcall AITHINK_InitializeRaven(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    pAiControl->dwAiParam[0] = -1;
    pAiControl->dwAiParam[1] = pMonStatsTxt->wAiParam[2][pGame->nDifficulty] + 1;
    pAiControl->dwAiParam[2] = SEED_RollRandomNumber_005E0C80(&pUnit->pSeed) & 1;
}

// 0x005ECBC0
int __fastcall AITHINK_RavenWalkToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char a4, int a2)
{
    AITACTICS_SetVelocity(pUnit, a2, 0, a4);
    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_WALK, &modeChange);
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.pTargetUnit = pTarget;
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

// 0x005ECC10
void __fastcall AITHINK_Fn107_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (!pMonStatsTxt)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    if (pAiControl->dwAiParam[0] == -1)
    {
        pAiControl->dwAiParam[0] = 3;
        if (pMonStatsTxt->nSkill[0] >= 0)
        {
            const int nSkillLevel = SKILLS_GetSkillLevel(pOwner, SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, pMonStatsTxt->nSkill[0]), 1);
            pAiControl->dwAiParam[0] = SKILLDESC_GetSummonLevel(pMonStatsTxt->nSkill[0], nSkillLevel);
        }
    }
    else if (pAiControl->dwAiParam[0] == 0)
    {
        SUNITDMG_KillMonster(pGame, pUnit, pUnit, 1);
        return;
    }

    const int nOwnerDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nOwnerDistance > 50)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }

    int nVel;
    if (pMonStatsTxt->nVelocity <= 0)
    {
        nVel = 100;
    }
    else
    {
        nVel = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100;
        if (nVel >= 100)
        {
            nVel = 100;
        }
    }

    if (nOwnerDistance > 28)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, nVel, 0);
        return;
    }

    int nDist;
    int bFoundCombat;
    D2UnitStrc* pFound = sub_6FCF2110(pGame, pOwner, pAiTickParam->pAiControl, &nDist, &bFoundCombat);
    if (pFound)
    {
        nDist = DRLG_UnitEdgeDistance(pUnit, pFound);
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int nAverageDistance = (AI_PARAM(pGame, pMonStatsTxt, 1) + AI_PARAM(pGame, pMonStatsTxt, 0)) / 2;

    if (pTarget && pAiControl->dwAiParam[1] < pGame->dwGameFrame)
    {
        const int nDifficulty = pGame->nDifficulty;
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStatsTxt->wAiParam[3][nDifficulty]
            && nTargetDistance < pMonStatsTxt->wAiParam[4][nDifficulty])
        {
            if (bCombat)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + 10 * AI_PARAM(pGame, pMonStatsTxt, 2);
                --pAiControl->dwAiParam[0];
            }
            else
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            }
            return;
        }
    }

    int bFailed;
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }
    else if (nOwnerDistance < AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }
    else if (pAiControl->dwAiParam[2] ? AITHINK_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 5) : AITHINK_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 6))
    {
        return;
    }
    else
    {
        pAiControl->dwAiParam[2] = pAiControl->dwAiParam[2] == 0;
        if (pAiControl->dwAiParam[2] ? AITHINK_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 5) : AITHINK_RavenWalkToUnit(pGame, pUnit, pOwner, 4, 6))
        {
            return;
        }

        bFailed = !AITACTICS_WalkAroundTargetWithScaledDistance(pGame, pUnit, pAiTickParam->pAiControl, pOwner, nAverageDistance);
    }

    if (bFailed)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 1, 0, 0, 0);
    }
}

// 0x005ECEE0
void __fastcall AITHINK_Fn108_SpiritWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pTick->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pPlayer && pMonStats->nSkill[0] >= 0)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], 0, CLIENTS_GetUnitX(pPlayer), CLIENTS_GetUnitY(pPlayer));
                EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 6, 0, 0);
                AITACTICS_Idle(pGame, pUnit, 8);
                return;
            }
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    pAiControl->dwAiParam[2] = !pOwner ? -1 : pOwner->dwUnitId;
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!sub_005E45D0_PetFollow(pGame, pUnit, 0, pOwner, 0, pTick, 0, 6))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 33);
        }
        return;
    }

    const int nRange = AI_PARAM(pGame, pMonStats, 3);
    int nDistance;
    int bCombat;
    D2UnitStrc* pTarget = AITACTICS_FindTargetInRange(pGame, pUnit, pAiControl, &nDistance, &bCombat, nRange);
    int nOwnerDistance;
    int bOwnerCombat;
    D2UnitStrc* pOwnerTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nOwnerDistance, &bOwnerCombat);
    if (pTarget && !AIUTIL_HasClearApproachToTarget(pUnit, pTarget))
    {
        pTarget = 0;
    }

    if (!pTarget && pOwnerTarget)
    {
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwnerTarget);
        if (nDistance < nRange && !AIUTIL_HasClearApproachToTarget(pUnit, pOwnerTarget))
        {
            pTarget = pOwnerTarget;
        }
    }

    int nVelocity;
    if (pMonStats->nVelocity <= 0 || (nVelocity = pMonStats->nRun * 100 / pMonStats->nVelocity - 100) >= 100)
    {
        nVelocity = 100;
    }

    const int nOwnerDistance2 = DRLG_UnitEdgeDistance(pOwner, pUnit);
    if (pMonStats->nSkill[0] >= 0 && nOwnerDistance2 > 50)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], 0, CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 4, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 10);
        return;
    }

    if (nOwnerDistance2 > AI_PARAM(pGame, pMonStats, 4))
    {
        if (sub_005E3EA0(pGame, pOwner, pUnit, 0, 1, 100, 0))
        {
            return;
        }
    }

    const int nOwnerMode = pOwner->dwAnimMode;
    if (nOwnerDistance2 > AI_PARAM(pGame, pMonStats, 2))
    {
        if (nOwnerMode == 2 || nOwnerMode == 6)
        {
            if (sub_005E3EA0(pGame, pOwner, pUnit, 0, 0, 0, 0))
            {
                return;
            }
        }

        if (nOwnerMode == 3)
        {
            if (sub_005E3EA0(pGame, pOwner, pUnit, 0, 1, 100, 0))
            {
                return;
            }
        }
    }

    if (sub_005E45D0_PetFollow(pGame, pUnit, pTarget, pOwner, bCombat, pTick, 1, 6))
    {
        return;
    }

    if (pTarget)
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStats, 0));
            return;
        }

        if (DRLG_UnitEdgeDistance(pOwner, pTarget) < nRange)
        {
            AITACTICS_SetAiParam(pUnit, 0, nVelocity, 0);
            AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
            return;
        }

        if (nOwnerDistance2 > 10)
        {
            D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pOwner, 8, 6);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStats, 1))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 10);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005ED710
void __fastcall AITHINK_Fn108_DruidWolf(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (pUnit && pUnit->dwClassId == 420)
    {
        AITHINK_Fn108_SpiritWolf(pGame, pUnit, pAiTickParam);
        return;
    }
    AITHINK_Fn108_Fenris(pGame, pUnit, pAiTickParam);
}

// 0x005ED730
void __fastcall AITHINK_Fn112_DruidBear(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pPlayer)
            {
                D2GAME_AI_PetMove_6FCE2BA0(pGame, pPlayer, pUnit, 3, 0, 0, 0);
                return;
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    pAiControl->dwAiParam[2] = !pOwner ? -1 : pOwner->dwUnitId;

    int nOwnerAnimMode;
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    nOwnerAnimMode = pOwner->dwAnimMode;
    int nVel;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (nDistance > 50)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }

    nVel = pMonStatsTxt->nVelocity > 0 ? 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100 : 100;
    if (nVel >= 100)
    {
        nVel = 100;
    }

    if (nDistance > 28)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 100, 0);
        return;
    }

    if (nDistance > 18)
    {
        if (nOwnerAnimMode == 2 || nOwnerAnimMode == 6)
        {
            if (D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0))
            {
                return;
            }
        }

        if (nOwnerAnimMode == 3 && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 100, 0))
        {
            return;
        }
    }

    int nTemp1;
    int nTemp2;
    int nTargetDistance;
    int bCombat;
    D2UnitStrc* pPotentialTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nTemp1, &nTemp2);
    D2UnitStrc* pTarget = AITACTICS_FindTargetInRange(pGame, pUnit, pAiControl, &nTargetDistance, &bCombat, 28);
    if (pTarget && !AIUTIL_HasClearApproachToTarget(pUnit, pTarget))
    {
        pTarget = 0;
    }

    if (!pTarget && pPotentialTarget)
    {
        nTargetDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pPotentialTarget);
        if (nTargetDistance < 28 && AIUTIL_HasClearApproachToTarget(pUnit, pPotentialTarget))
        {
            pTarget = pPotentialTarget;
        }
    }

    if (bCombat)
    {
        if (pTarget)
        {
            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 0));
            }
            return;
        }
    }
    else if (pTarget)
    {
        if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_SetAiParam(pUnit, 0, nVel, 40);
        }

        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    if (nDistance > 16)
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}

// 0x005ED9E0
void __fastcall AITHINK_Fn109_Totem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance;
    int bCombat;
    D2UnitStrc* pTarget = AITACTICS_FindTargetInRange(pGame, pUnit, pAiControl, &nDistance, &bCombat, 24);
    if (bCombat && pTarget && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_WALK_AWAY_CHANCE_PCT) && AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 6, 1))
    {
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_IGNORE_TARGET_CHANCE_PCT))
    {
        pTarget = 0;
        bCombat = 0;
    }

    const int nOwnerDistance = DRLG_UnitEdgeDistance(pUnit, pOwner);
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_TELEPORT_TO_OWNER_DISTANCE))
    {
        if (SUNIT_TeleportUnit(pGame, pUnit, UNITS_GetRoom(pOwner), CLIENTS_GetUnitXInline_Totem(pOwner), CLIENTS_GetUnitYInline_Totem(pOwner), 0, 0))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            return;
        }
    }

    const int nOwnerAnimMode = pOwner->dwAnimMode;
    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxt, TOTEM_AI_PARAM_FOLLOW_OWNER_DISTANCE))
    {
        if (((nOwnerAnimMode == PLRMODE_WALK || nOwnerAnimMode == PLRMODE_TOWNWALK) && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0))
            || (nOwnerAnimMode == PLRMODE_RUN && D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 60, 0)))
        {
            return;
        }
    }

    if (AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 0, 6))
    {
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005EDC00
void __fastcall AITHINK_SetSecondaryAiParams(D2GameStrc* pGame, D2AiControlStrc* pAiControl, int nParam1, int nParam2)
{
    D2_ASSERT(pAiControl, 0x13B6);
    pAiControl->dwAiParam[1] = nParam1;
    pAiControl->dwAiParam[2] = nParam2;
}

// 0x005EDC40
void __stdcall sub_005EDC40(int nUnused1)
{
}

static inline unsigned int SEED_RollNext_005EDC50(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed;
}

static inline unsigned int SEED_RollAgain_005EDC50(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed;
}

// 0x005EDC50
void __fastcall sub_005EDC50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nStep = -30;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pUnit->dwNodeIndex == 11)
    {
        TARGETS_InsertUnitNode(pGame, pUnit, 0, 8);
    }

    if (pTarget)
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            AITACTICS_Idle(pGame, pUnit, AI_GetParamValue(pGame, pMonStatsTxt, 0));
            return;
        }

        if (nDistance < AI_GetParamValue(pGame, pMonStatsTxt, 2) && (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_GetParamValue(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_SetVelocity(pUnit, 0, 100, 0);
            AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
            return;
        }
    }

    const int nX = GetUnitX(pUnit);
    const int nY = GetUnitY(pUnit);

    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned int nLowSeed, nHighSeed;
    unsigned int nRandX = SEED_RollNext_005EDC50(pSeed, nLowSeed, nHighSeed);
    unsigned int nRandY = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 40, nY + nRandY % 20 - 10))
    {
        return;
    }

    const int bDirection = SEED_RollNext_005EDC50(pSeed, nLowSeed, nHighSeed) & 1;
    nRandX = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    nRandY = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    if (AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 10, nStep * (bDirection ? 1 : -1) + nRandY % 20 + nY - 10))
    {
        return;
    }

    nRandX = SEED_RollNext_005EDC50(pSeed, nLowSeed, nHighSeed);
    nRandY = SEED_RollAgain_005EDC50(pSeed, nLowSeed, nHighSeed);
    if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nX + nRandX % 20 - 10, nStep * (!bDirection ? 1 : -1) + nRandY % 20 + nY - 10))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}

// 0x005EDF70
int __fastcall AITHINK_FindDeadMonsterBehind(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 5147);

    D2DrlgCoordsStrc coords;
    DUNGEON_GetRoomCoordinates(pRoom, &coords);
    int nX = coords.nSubtileX;
    int nY = coords.nSubtileY;
    int nDirX = 0;
    int nDirY = 0;
    sub_0063EE10_GetMonsterDirectionDelta(pUnit, &nDirX, &nDirY);
    nDirX = -nDirX;
    nDirY = -nDirY;
    int bResult = 0;
    const int nIndex = (!pUnit ? -1 : pUnit->dwClassId) - 19;
    for (int i = 0; !bResult && i < 3; ++i)
    {
        nX += coords.nSubtileWidth * nDirX;
        nY += coords.nSubtileHeight * nDirY;
        bResult = SUNITINACTIVE_IsDeadMonsterAt(pGame, pRoom, nX, nY, nIndex);
    }
    return bResult;
}

extern const int gnCatapultSkills[5]; // 0x006E3514

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, int nUnitSize, unsigned int nMask, int nFieldSize); // 0x0064E7E0

// 0x005EE040
void __fastcall AITHINK_Fn126_CatapultSpotter(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if ((!pAiControl->dwAiParam[2] || AI_RollPercentage_005F0CD0(pSeed) < 3) && AITHINK_FindDeadMonsterBehind(pGame, pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 0, pTarget);
        return;
    }
    if (!pAiControl->dwAiParam[2]) pAiControl->dwAiParam[2] = 1;
    if (AI_PARAM(pGame, pMonStatsTxt, 1) - pGame->dwGameFrame + pAiControl->dwAiParam[2] <= 0)
    {
        if (pTarget && AI_RollPercentage_005F0CD0(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            int nSkill;
            if (pAiControl->dwAiParam[1] <= 0)
            {
                nSkill = SEED_RollLimitedRandomNumber(pSeed, 5);
                pAiControl->dwAiParam[0] = nSkill;
                pAiControl->dwAiParam[1] = AI_PARAM(pGame, pMonStatsTxt, 4);
            }
            else
            {
                nSkill = pAiControl->dwAiParam[0];
                --pAiControl->dwAiParam[1];
            }
            D2CoordStrc coords;
            coords.nX = CLIENTS_GetUnitX(pTarget) + SEED_RollLimitedRandomNumber(pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 3)) - AI_PARAM(pGame, pMonStatsTxt, 3);
            coords.nY = CLIENTS_GetUnitY(pTarget) + SEED_RollLimitedRandomNumber(pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 3)) - AI_PARAM(pGame, pMonStatsTxt, 3);
            if (COLLISION_GetFreeCoordinatesEx(UNITS_GetRoom(pUnit), &coords, 2, 0x805, 3))
            {
                AITACTICS_UseSkill(pGame, pUnit, 4, gnCatapultSkills[nSkill], 0, coords.nX, coords.nY);
                pAiControl->dwAiParam[2] = pGame->dwGameFrame;
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

// 0x005EE260
void __fastcall AITHINK_Fn130_DeathMauler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pStats = pTick->pMonstatsTxt;
    D2UnitStrc* pTarget = pTick->pTarget;
    int nTargetDistance = pTick->nTargetDistance;
    if (pTick->bCombat)
    {
        if (AI_RollPercentage_005EFE20(pUnit) < AI_GetParam(pGame, pStats, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        }
        return;
    }
    else
    {
        if (pStats->nSkill[0] >= 0 && nTargetDistance < AI_GetParam(pGame, pStats, 2)
            && AI_RollPercentage_005EFE20(pUnit) < AI_GetParam(pGame, pStats, 3))
        {
            AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pTarget, 0, 0);
            return;
        }
        if (AI_RollPercentage_005EFE20(pUnit) < AI_GetParam(pGame, pStats, 1))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005EE3C0
void __fastcall AITHINK_Fn131_Wussie(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pPortal = 0;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (ACT5Q2_FindPortal(pGame,pUnit,&pPortal))
    {
        if (pPortal && (ACT5Q2_CheckWussieCounters(pGame,pUnit) || (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit,CLIENTS_GetUnitX(pPortal),CLIENTS_GetUnitY(pPortal)) < 4))
        {
            ACT5Q2_UpdateWussieCounters(pGame,0,pUnit);
            PATH_ClearPathingFlagAndPoints(pUnit->pDynamicPath);
            sub_00540E60(pGame,pUnit,2,0);
            const int nUnitId = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit),nUnitType,nUnitId);
            UNITS_FreeCollisionPath(pUnit);
            UNITROOM_RemoveUnitFromRoom(pUnit);
            SUNIT_RemoveUnit(pGame,pUnit);
            return;
        }
        if (pPortal)
        {
            if ((int)(SEED_RollRandomNumber_Inline(pSeed) % 100) < 70)
                AITACTICS_WalkToTargetUnitWithFlags(pGame,pUnit,pPortal,7);
            else if ((int)SEED_RollLimitedRandomNumber(pSeed,100) < 10)
                AITACTICS_WalkCloseToUnit(pGame,pUnit,4);
            else
                AITACTICS_IdleInNeutralMode(pGame,pUnit,10);
            return;
        }
    }
    else
    {
        int bCloseToTarget = 0;
        D2UnitStrc* pPlayer = AITACTICS_FindNearbyPlayerOrSelf(pGame,pUnit,&bCloseToTarget);
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            if (ACT5Q2_IsMonsterNearby(pGame,pPlayer,pUnit))
            {
                ACT5Q2_SpawnRescuePortal(pGame,pPlayer,pUnit);
                if (pUnit->dwNodeIndex == 11)
                {
                    TARGETS_InsertUnitNode(pGame,pUnit,0,8);
                    AITACTICS_IdleInNeutralMode(pGame,pUnit,25);
                    return;
                }
            }
            else
            {
                ACT5Q2_OnWussieActivated(pGame,pPlayer,pUnit);
                if ((int)SEED_RollLimitedRandomNumber(pSeed,1000) < 100)
                {
                    D2Packet8A packet;
                    packet.header = 0x8A;
                    packet.type = 1;
                    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
                    packet.guid = nUnitGUID;
                    sub_0053DFF0(UnitGetClient(pPlayer,gszAiThink4,0x14FF),&packet);
                }
            }
        }
    }
    AITACTICS_IdleInNeutralMode(pGame,pUnit,25);
}

// 0x005EE5C0
void __stdcall sub_005EE5C0(int nUnused1)
{
}

// 0x005EE5D0
void __fastcall AITHINK_Fn128_Nihlathak(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2SkillStrc* pSkill;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    ACT5Q4_OnNihlathakActivated(pGame, pUnit);
    if (STATES_CheckState(pUnit, STATE_INFERNO))
        STATES_ToggleState(pUnit, 12, 0);
    if (!pTarget)
    {
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
        if (pSkill && AIUTIL_IsGettingHit(pUnit))
        {
            AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pMonStatsTxt, 1), SKILLS_GetSkillIdFromSkill(pSkill, gszAiThink4File, 0x1537), SKILLS_GetSkillMode(pSkill));
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }
    pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]);
    if (pSkill && bCombat && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_UseSkillInRange(pUnit, AI_PARAM(pGame, pMonStatsTxt, 1), SKILLS_GetSkillIdFromSkill(pSkill, gszAiThink4File, 0x1544), SKILLS_GetSkillMode(pSkill));
        return;
    }
    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 4) && AI_ROLL_PERCENT(pSeed) < 40)
    {
        if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 5, 1))
            return;
    }
    if (pMonStatsTxt->nSkill[2] > 0)
    {
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[2]);
        if (pSkill && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            D2UnitStrc* pSkillTarget = SKILLS_FindCorpseNearTarget(pUnit, pTarget, pMonStatsTxt->nSkill[2], SKILLS_GetSkillLevel(pUnit, pSkill, 1));
            if (pSkillTarget && AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pSkillTarget, 0, 0))
                return;
        }
    }
    if (pMonStatsTxt->nSkill[3] > 0 && SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[3]) && AI_ROLL_PERCENT(pSeed) < 60 && nTargetDistance < 14)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
        return;
    }
    if (pMonStatsTxt->nSkill[1] > 0 && AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pMonStatsTxt, 3) && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[1]))
    {
        D2NihlathakOverseerAiCallbackArgStrc arg;
        arg.nMaxDistance = 0;
        arg.nDistantMaxDistance = 625;
        arg.nMaxLifePercentage = 50;
        arg.pTarget = 0;
        arg.pDistantTarget = 0;
        arg.nCounter = 0;
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Overseer_Nihlathak, 1);
        if (arg.pDistantTarget)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], arg.pDistantTarget, 0, 0);
            return;
        }
        if (pMonStatsTxt->nSkill[4] > 0)
        {
            const int nMonsterId = MONSTERS_ValidateMonsterId(MONSTER_EVILHUT);
            if (sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
            {
                pAiTickParam->pAiControl->nMinionSpawnClassId = D2Common_11063(UNITS_GetRoom(pUnit), MONSTERS_ValidateMonsterId(MONSTER_MINION1));
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, 0, 0);
                return;
            }
        }
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
        return;
    }
    if (pMonStatsTxt->nSkill[3] > 0 && SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[3]) && nTargetDistance < 14)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
        return;
    }
    if (AI_ROLL_PERCENT(pSeed) < 60)
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
}

int __fastcall ACT5Q5_GetPortalCount(D2GameStrc* pGame); // 0x0058CFB0

int __fastcall ACT5Q5_IsActivatable(D2GameStrc* pGame); // 0x0058CFE0

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

// 0x005EEAA0
void __fastcall AITHINK_Fn132_AncientStatue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!ACT5Q5_IsActivatable(pGame) || ACT5Q5_GetPortalCount(pGame) || STATES_CheckState(pUnit, STATE_INVIS))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pUnit), 0);
    AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, SKILL_MINIONSPAWNER, 0, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
}

// 0x005EEB10
int __fastcall AITHINK_AreUnitsInSameLevel(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2_ASSERT(pUnit, 0x15CA);
    D2_ASSERT(pTarget, 0x15CB);

    return DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget));
}

// 0x005E8F20
D2UnitStrc* __fastcall AIBAAL_GetTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pMax, int* pCount, D2AiCmdStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*))
{
    D2_ASSERT(pfCull, 890);

    UNITS_GetRoom(pUnit);

    D2UnitStrc* pTarget = 0;
    int nCount = 0;
    int nMax = 0;
    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pTargetNode = *ppTargetNode;
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    const unsigned char nAct = pUnit->nAct;

    for (int i = 0; i < 8; ++i)
    {
        if (pTargetNode)
        {
            D2_ASSERT(pTargetNode->hUnit && pTargetNode->hUnit->dwUnitType == UNIT_PLAYER, 917);
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
                else
                {
                    nCurrent = 0;
                }

                while (1)
                {
                    if (nMax < nCurrent)
                    {
                        nMax = nCurrent;
                        pTarget = pTargetUnit;
                    }

                    pTargetNode = pTargetNode->pNext;
                    ++nCount;

                    if (!pTargetNode)
                    {
                        break;
                    }

                    pTargetUnit = pTargetNode->hUnit;
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
            }
        }

        pTargetNode = *++ppTargetNode;
    }

    while (pTargetNode)
    {
        D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
            if (nMax < nCurrent)
            {
                nMax = nCurrent;
                pTarget = pTargetUnit;
            }
            ++nCount;
        }

        pTargetNode = pTargetNode->pNext;
    }

    pTargetNode = ppTargetNode[1];

    D2UnitStrc* pTemp = 0;
    int nTemp = 0;
    if (pTargetNode)
    {
        do
        {
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                if (nTemp < nCurrent)
                {
                    nTemp = nCurrent;
                    pTemp = pTargetUnit;
                }
            }

            pTargetNode = pTargetNode->pNext;
        }
        while (pTargetNode);

        if (pTemp && AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTemp, nX, nY) < 5 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetPathTarget(pPath, pTarget);
            PATH_SetType(pPath, PATHTYPE_TOWARD);
            D2Common_10142(pPath, pUnit, 0);

            if (!PATH_GetNumberOfPathPoints(pPath))
            {
                pTarget = pTemp;
                nMax = nTemp;
            }
        }
    }

    *pCount = nCount;
    *pMax = nMax;

    return pTarget;
}

int __fastcall sub_005E8810_SelectAction(D2AiControlStrc*, D2UnitStrc*, D2UnitStrc*, int, int, D2AiCmdStrc*); // 0x005E8810

inline D2SkillsTxt* GetSkill(int nId) {
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}

// 0x005E9170
void __fastcall AITHINK_Fn051_Diablo(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pStats = pTick->pMonstatsTxt;
    D2AiCmdStrc* pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pCmd) {
        D2AiCmdStrc cmd;
        cmd.nCmdParam[0] = 10;
        cmd.nCmdParam[1] = GetX(pUnit);
        cmd.nCmdParam[2] = GetY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &cmd);
        pCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }
    D2UnitStrc* pTarget;
    D2AiControlStrc* pAi;
    int nAction;
    {
        int nMax;
        int nCount;
        pTarget = AIBAAL_GetTarget(pGame, pUnit, &nMax, &nCount, pCmd, AITHINK_CullPotentialTargetsForDiablo);
        pAi = pTick->pAiControl;
        nAction = sub_005E8810_SelectAction(pAi, pUnit, pTarget, nMax, nCount, pCmd);
    }
    if (nAction != 5 && pStats->nSkill[7] >= 0) {
        D2SkillsTxt* pSkill = GetSkill(pStats->nSkill[7]);
        if (pSkill && pSkill->nAuraState >= 0 && !STATES_CheckState(pUnit, pSkill->nAuraState)) {
            if (AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[7], pStats->nSkill[7], pTarget, 0, 0)) {
                pAi->dwAiParam[0] = 0;
                return;
            }
        }
    }
    int bKeepAction = 0;
    switch (nAction) {
    case 1:
        AITACTICS_SetAiParam(pUnit, 0, 20, 0);
        AITACTICS_WalkToTargetCoordinates(pGame, pUnit, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
        break;
    case 2: AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget); break;
    case 3: AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget); break;
    case 4: AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 11, pTarget); break;
    case 5:
        if (pStats->nSkill[0] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        if (STATES_CheckState(pUnit, STATE_INFERNO)) {
            STATES_ToggleState(pUnit, 12, 0);
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
            break;
        }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pTarget, 0, 0);
        bKeepAction = 1;
        break;
    case 6:
        if (pStats->nSkill[2] >= 0) AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[2], pStats->nSkill[2], pTarget, 0, 0);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
        break;
    case 7:
        if (pStats->nSkill[1] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[1], pStats->nSkill[1], pTarget, 0, 0);
        break;
    case 8:
        if (pStats->nSkill[3] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pTarget, 0, 0);
        break;
    case 13:
        if (pStats->nSkill[5] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[5], pStats->nSkill[5], pTarget, 0, 0);
        break;
    case 9:
        if (pStats->nSkill[6] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[6], pStats->nSkill[6], pTarget, 0, 0);
        break;
    case 10:
        if (pStats->nSkill[4] < 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
        AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[4], pStats->nSkill[4], pTarget, 0, 0);
        break;
    case 12: AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0); break; // 0x005DF7D0
    case 14:
        AITACTICS_SetAiParam(pUnit, 0, 50, 100);
        if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, pCmd->nCmdParam[1], pCmd->nCmdParam[2])) {
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            int nTargetX = pCmd->nCmdParam[1];
            int nTargetY = pCmd->nCmdParam[2];
            int nDistance = AIUTIL_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
            int nDirectionX = 0;
            int nDirectionY = 0;
            if (nX < nTargetX) nDirectionX = -1;
            if (nX > nTargetX) nDirectionX = 1;
            if (nY < nTargetY) nDirectionY = -1;
            if (nY > nTargetY) nDirectionY = 1;
            AITACTICS_SetAiParam(pUnit, 0, 50, 100);
            if (!AITACTICS_WalkToTargetCoordinatesDeleteAiEvent(pGame, pUnit, nTargetX + (nDistance >> 1) * nDirectionX, nTargetY + (nDistance >> 1) * nDirectionY)) {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
            }
        }
        break;
    case 15:
        {
            if ((pTarget ? pTarget->dwUnitType : UNIT_INVALID) != 0) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 3); break; }
            int nObjectId = PLAYER_GetUniqueIdFromPlayerData(pTarget);
            if (!SUNIT_GetServerUnit(pGame, 2, nObjectId)) { AITACTICS_IdleInNeutralMode(pGame, pUnit, 2); break; }
            if (pStats->nSkill[6] >= 0) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[6], pStats->nSkill[6], 0, nObjectId, 2);
                break;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 2);
        }
        break;
    case 16:
        AITACTICS_SetAiParam(pUnit, 0, 20, 0);
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        break;
    default:
        {
            int nDelay = 12;
            switch (pGame->nDifficulty) { case 1: nDelay = 8; break; case 2: nDelay = 4; break; }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, nDelay);
        }
        break;
    }
    if (!bKeepAction) pAi->dwAiParam[0] = 0;
    else pAi->dwAiParam[0] = nAction;
}

// 0x005EEB70
void __fastcall AITHINK_AncientBarb1SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (ACT5Q5_IsNotActivatable(pGame) || STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (!pTarget)
    {
        int nTemp1;
        int nTemp2;
        pTarget = AIBAAL_GetTarget(pGame, pUnit, &nTemp1, &nTemp2, 0, AITHINK_AreUnitsInSameLevel);
        if (!pTarget)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            return;
        }
    }

    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    const int nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);

    const int bUseSkill = (pMonStatsTxt->nSkill[0] > 0 && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[0])
        && nDistance < AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_WHIRLWIND_DISTANCE)
        && AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_WHIRLWIND_CHANCE_PCT) > (int)SEED_RollLimitedRandomNumber(pSeed, 100));

    if (!bUseSkill)
    {
        if (bInMeleeRange)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if (SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                }
                else
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                }
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
            }
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
            AITACTICS_Idle(pGame, pUnit, 10);
        }
        return;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    int nXDiff = nTargetX - CLIENTS_GetUnitX(pUnit);
    int nYDiff = nTargetY - CLIENTS_GetUnitY(pUnit);

    const int nDist = DRLG_GetDistanceToXY(pUnit, nTargetX, nTargetY);
    const int nScale = nDist ? nDist : 1;

    nXDiff = nXDiff * AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_SKILL_REACH) / nScale;
    nYDiff = nYDiff * AI_GetParamValue(pGame, pMonStatsTxt, ANCIENTBARB1_AI_PARAM_SKILL_REACH) / nScale;

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, (char)pMonStatsTxt->nSkillMode[0], &modeChange);
    UNITS_SetUsedSkill(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, pMonStatsTxt->nSkill[0]));
    PATH_SetStepNum(pUnit->pDynamicPath, 1);
    modeChange.nX = nXDiff + nTargetX;
    modeChange.nY = nYDiff + nTargetY;
    modeChange.nEventFlag = 100;
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 0);
}

// 0x005EF010
void __fastcall AITHINK_AncientBarb3SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (ACT5Q5_IsNotActivatable(pGame))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int nMax;
    int bInMeleeRange;
    D2UnitStrc* pTarget = AIBAAL_GetTarget(pGame, pUnit, &nMax, &bInMeleeRange, 0, AITHINK_AreUnitsInSameLevel);
    if (pTarget)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
        const int nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);

        if (pMonStatsTxt->nSkill[0] > 0 && nDistance < AI_PARAM(pGame, pMonStatsTxt, 0)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1)
            && AIUTIL_CheckIfMonsterUsesSkill(pUnit, pMonStatsTxt->nSkill[0]))
        {
            AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (bInMeleeRange)
        {
            const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
            pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
            if ((int)((unsigned int)lSeed % 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                if (SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                }
                else
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                }
                return;
            }
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
            AITACTICS_Idle(pGame, pUnit, 10);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005EF1A0
void __fastcall AITHINK_Fn133_Ancient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    switch (!pUnit ? -1 : pUnit->dwClassId)
    {
    case MONSTER_ANCIENTBARB1:
        AITHINK_AncientBarb1SkillHandler(pGame, pUnit, pAiTickParam);
        return;

    case MONSTER_ANCIENTBARB2:
        AITHINK_AncientBarb2SkillHandler(pGame, pUnit, pAiTickParam);
        return;

    case MONSTER_ANCIENTBARB3:
        AITHINK_AncientBarb3SkillHandler(pGame, pUnit, pAiTickParam);
        return;

    default:
        return;
    }
}

// 0x0040D530
int __cdecl EXCEPTIONS_ReleaseAllSymbols()
{
    return EXCEPTIONS_ReleaseSymbols(1);
}

// 0x004A5010
void __cdecl TEXT_ResetKeyConfigDefaults()
{
    CMDTBL_ResetKeyConfig(0);
}

// 0x004A51E0
void __cdecl TEXT_FreeTextSliderCel()
{
    if (gpKeyConfigSliderCel)
    {
        ARCHIVE_FreeClientCellFile(gpKeyConfigSliderCel);
        gpKeyConfigSliderCel = 0;
    }
}

// 0x005EF1E0
int __fastcall AITHINK_BaalThroneCheckAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}

// 0x005EF1F0
void __fastcall AITHINK_BaalThroneSetAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag, int bSet)
{
    if (bSet)
    {
        pAiTickParam->pAiControl->dwAiParam[1] |= nFlag;
    }
    else
    {
        pAiTickParam->pAiControl->dwAiParam[1] &= ~nFlag;
    }
}

// 0x005EF210
void __fastcall AITHINK_BaalThroneSpawnMinions(D2UnitStrc* pUnit, int nSuperUnique, D2AiTickParamStrc* pAiTickParam)
{
    SKILLS_AssignSkill(pUnit, SKILL_BAALMONSTERSPAWN, 1, 0, ".\\Ai\\AiThink4.cpp", 0x1700);
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_BAALMONSTERSPAWN);
    D2_ASSERT(pSkill, 0x1702);
    SKILLS_SetParam1(pSkill, nSuperUnique);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }

    AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL3, SKILL_BAALMONSTERSPAWN, 0, nX, nY + 13);
    ++pAiTickParam->pAiControl->dwAiParam[0];
    pAiTickParam->pAiControl->dwAiParam[2] = pGame->dwGameFrame + 100;
    AITHINK_BaalThroneSetAiParamFlag(pAiTickParam, 2, 1);
    AITHINK_BaalThroneSetAiParamFlag(pAiTickParam, 1, 0);
}

// 0x005EF310
void __stdcall sub_005EF310(int nUnused1)
{
}

struct D2SuperUniquesTxt;

extern const int gnBaalThroneSuperUniqueIds[]; // 0x006E3528

void __fastcall sub_00553380_SetUnitFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00553380

void __fastcall SUNITMSG_QueueMonsterPrecache(D2UnitStrc* pUnit, int nClass); // 0x00571C00

int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClass, int nMode); // 0x00574370

int __fastcall OBJMODE_GetSuperUniqueId(unsigned int nIndex); // 0x00586B30

D2UnitStrc* __fastcall sub_005DD0B0_FindTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, void* pCallback, int nCallbackId); // 0x005DD0B0

void __stdcall STATLIST_SetState(D2StatListStrc* pList, int nState); // 0x006252D0

void __stdcall sub_00626E10(D2UnitStrc* pUnit, D2StatListStrc* pList, int bReset); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pList, int nStat, int nValue, int nLayer); // 0x00627150

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUnique); // 0x006556E0

static inline int BAALTHRONE_GetSuperUniqueClass(int nSuperUnique)
{
    D2SuperUniquesTxt* pSuperUnique = DATATBLS_GetSuperUniquesTxtRecord(nSuperUnique);
    if (!pSuperUnique)
    {
        return -1;
    }
    return pSuperUnique->dwClass;
}

// 0x005EF320
void __fastcall AITHINK_Fn134_BaalThrone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2MonStatsTxt* pMonStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pTick->pAiControl;
    if (!pMonStats)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pGame->dwGameFrame < pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pGame->dwGameFrame - pAiControl->dwAiParam[2]);
        return;
    }
    D2BaalThroneAiCallbackArgStrc arg;
    int nWave = pAiControl->dwAiParam[0];
    arg.pTarget1 = 0;
    arg.nDistance2 = 64;
    arg.pTarget2 = 0;
    arg.nDistance1 = 64;
    sub_005DD0B0_FindTarget(pGame, pUnit, &arg, 0, 3);
    if (!arg.pTarget2)
    {
        if (!(pTick->pAiControl->dwAiParam[1] & 1))
        {
            if ((unsigned int)nWave <= 4)
            {
                nWave = BAALTHRONE_GetSuperUniqueClass(OBJMODE_GetSuperUniqueId(gnBaalThroneSuperUniqueIds[nWave]));
                if (nWave < 0) return;
                SUNITMSG_QueueMonsterPrecache(pUnit, nWave);
                switch (nWave)
                {
                case 62: SUNITMSG_QueueMonsterPrecache(pUnit, 23); break;
                case 105: SUNITMSG_QueueMonsterPrecache(pUnit, 381); break;
                }
            }
            AITACTICS_UseSkill(pGame, pUnit, 10, SKILL_BAALCORPSEEXPLODE, pUnit, 0, 0);
            pTick->pAiControl->dwAiParam[1] |= 1;
            pTick->pAiControl->dwAiParam[2] = pGame->dwGameFrame + 250;
            sub_00553380_SetUnitFlag(pUnit, 16, 0);
            return;
        }
        if (nWave >= 5)
        {
            MONSTER_Reinitialize(pGame, pUnit, 559, 1);
            AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
            STATES_ToggleState(pUnit, 142, 1);
            D2StatListStrc* pList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0,
                !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            if (pList)
            {
                sub_00626E10(pUnit, pList, 1);
                STATLIST_SetState(pList, STATE_CHANGECLASS);
                STATLIST_SetStat(pList, STAT_SHORTPARAM1, 559, 0);
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }
        int nSuperUnique = DATATBLS_MapSuperUniqueId(2, OBJMODE_GetSuperUniqueId(gnBaalThroneSuperUniqueIds[nWave]));
        AITHINK_BaalThroneSpawnMinions(pUnit, nSuperUnique, pTick);
        return;
    }
    D2UnitStrc* pTarget = pTick->pTarget;
    if (pMonStats->nSkill[0] > 0 && pTarget)
    {
        D2SkillsTxt* pSkills = sub_0045C4B0_GetSkillsTxtRecord(pMonStats->nSkill[0]);
        if (pSkills)
        {
            if (pSkills->nAuraState >= 0 && pSkills->nAuraState < sgptDataTables->nStatesTxtRecordCount && STATES_CheckState(pUnit, pSkills->nAuraState)) goto Idle;
            if (pSkills->wAuraTargetState >= 0 && pSkills->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount && STATES_CheckState(pTarget, pSkills->wAuraTargetState)) goto Idle;
            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pMonStats->wAiParam[0][pGame->nDifficulty])
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], pTarget, 0, 0);
                return;
            }
        }
    }
Idle:
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

// 0x005EF5E0
D2UnitStrc* __fastcall AITHINK_TargetCallback_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2BaalToStairsAiCallbackArgStrc* pArg = (D2BaalToStairsAiCallbackArgStrc*)pCallbackArg;

    if (pTarget && pTarget->dwUnitType == UNIT_OBJECT && pTarget->dwClassId == OBJECT_BAALS_PORTAL_WORLDSTONECHAMBER)
    {
        return DRLG_UnitEdgeDistance(pTarget, pUnit) <= pArg->nMaxDistance ? pTarget : 0;
    }

    return 0;
}

enum D2C_AiThink4_005FB5B0Constants
{
    TRAPMISSILE_AI_PARAM_DELAY = 2,
    TRAPMISSILE_AI_PARAM_DISTANCE = 0,
    TRAPMISSILE_AI_PARAM_NUM_TO_SHOOT = 1,
};

// 0x005EF620
void __fastcall AITHINK_Fn138_BaalToStairs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2BaalToStairsAiCallbackArgStrc arg;
    arg.unk0x00 = 0;
    arg.nMaxDistance = 25;
    D2UnitStrc* pTarget = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_BaalToStairs, 1);
    if (pTarget)
    {
        if (DRLG_UnitEdgeDistance(pUnit, pTarget) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            ACT5Q6_OpenWorldStoneChamber(pGame);
            STATES_ToggleState(pUnit, STATE_BAALTOSTAIRS_INVIS, 1);
            D2Common_10153(pUnit->pDynamicPath);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit), pUnit->dwUnitType, pUnit->dwUnitId);
            UNITS_FreeCollisionPath(pUnit);
            UNITROOM_RemoveUnitFromRoom(pUnit);
            SUNIT_RemoveUnit(pGame, pUnit);
            return;
        }

        AITACTICS_SetAiParam(pUnit, 1, 0, 0);
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

// 0x005EF710
void __fastcall AITHINK_Fn136_BaalTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int bIsTargetNeutral = 0;
    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
        bIsTargetNeutral = pTarget->dwAnimMode == PLRMODE_NEUTRAL;
        break;
    case UNIT_MONSTER:
        bIsTargetNeutral = pTarget->dwAnimMode == MONMODE_NEUTRAL;
        break;
    }

    int bTaunt = 0;
    if (bIsTargetNeutral)
    {
        ++pAiTickParam->pAiControl->dwAiParam[0];
        bTaunt = pAiTickParam->pAiControl->dwAiParam[0] > AI_GetParamValue(pGame, pMonStatsTxt, 1);
    }

    if (!bIsTargetNeutral || bTaunt)
    {
        pAiTickParam->pAiControl->dwAiParam[0] = 0;
        if (bTaunt)
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK1, SKILL_BAALTAUNT, pTarget, 0, 0);
            return;
        }
    }

    if ((nDistance <= AI_GetParamValue(pGame, pMonStatsTxt, 2) || !SUNIT_TeleportUnit(pGame, pUnit, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0, 0))
        && nDistance > AI_GetParamValue(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
    }
}

// 0x005EF820
void __fastcall AITHINK_Fn139_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pAiTickParam->pAiControl->dwAiParam[2])
    {
        const int nDuration = AI_PARAM(pGame, pMonStatsTxt, 2);
        const int nFrames = 25 * ((int)SEED_RollLimitedRandomNumber(pSeed, nDuration) + nDuration);
        pAiTickParam->pAiControl->dwAiParam[2] = pGame->dwGameFrame + nFrames;
    }

    if (pGame->dwGameFrame > pAiTickParam->pAiControl->dwAiParam[2])
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    if (bCombat && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

// 0x005EF910
void __fastcall AITHINK_Fn141_BaalMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (pTarget && pAiTickParam->bCombat)
    {
        if ((int)(SEED_RollRandomNumber_005EEB70(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
        }
    }
    else
    {
        if ((int)(SEED_RollRandomNumber_005EEB70(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pTarget);
        }
    }

    AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

// 0x005EFA50
D2UnitStrc* __fastcall AITHINK_TargetCallback_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    if (!sub_6FD01910(pUnit, pTarget))
    {
        return 0;
    }

    return sub_005DC380(pUnit, pTarget) <= 25 ? pTarget : 0;
}

// 0x005EFA90
void __fastcall AITHINK_Fn137_PutridDefiler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nDistance = pAiTickParam->nTargetDistance;
    if (pTarget && pAiTickParam->bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    D2PutridDefilerAiCallbackArgStrc arg;
    arg.unk0x00 = 0;
    arg.nMaxDistance = 25;
    D2UnitStrc* pVictim = AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_PutridDefiler, 1);
    if (pVictim)
    {
        if (UNITS_IsInMeleeRange(pUnit, pVictim, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_SKILL1, SKILL_IMPREGNATE, pVictim, 0, 0);
        }
        else
        {
            AITACTICS_WalkToTargetUnit(pGame, pUnit, pVictim);
        }
        return;
    }

    if (nDistance < AI_GetParamValue_005E17E0(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, AI_GetParamValue_005E17E0(pGame, pMonStatsTxt, 1), 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
}

#include "gen/data/Source/D2Game/Ai/AiThink4.inc"
