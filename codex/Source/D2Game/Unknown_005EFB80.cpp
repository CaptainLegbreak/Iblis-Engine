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
// build: symbol _gaszLanguageNames 0x00741D90

struct D2MonStatsTxt;

struct D2LevelsTxt;

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0

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

void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190

int __fastcall AITACTICS_ChangeModeAndTargetCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x005DDFC0

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90

int __fastcall AITACTICS_WalkToTargetUnitWithFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, unsigned char nFlag); // 0x005DEC80

int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20

D2AiCmdStrc* __fastcall AIGENERAL_SetCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EFA0

unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

#define AI_GetParam(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

struct D2FallenShamanAiCallbackArgStrc;

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

struct D2FallenShamanAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nDistance;
    int nMaxDistance;
    int unk0x10[6];
};

int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc* pUnit); // 0x0058EE80

void __fastcall AITACTICS_SetVelocity(D2UnitStrc* pUnit, int a2, int nVel, unsigned char a4); // 0x005DE190

int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

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

void __fastcall AITACTICS_ScheduleEarlierAiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                           // 0x005DE130

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730

int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc* pUnit);                                         // 0x0058F710

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

int __fastcall AITACTICS_WalkToTargetWithPathType13(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nFlags); // 0x005DED40

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);               // 0x00620C10

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870

int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesOneStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode); // 0x005DE440

int __fastcall AITACTICS_WalkAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0

int __fastcall AIUTIL_HasClearMissilePath(D2UnitStrc* pUnit, D2UnitStrc* pTarget);             // 0x005DD290

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);

#pragma intrinsic(memcpy)

struct D2SkillStrc;

struct D2DynamicPathStrc;

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*,int,int); // 0x00552F60

void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc*,D2PlayerCountBonusStrc*,D2ActiveRoomStrc*,D2UnitStrc*); // 0x00573930

int __fastcall sub_005FD470(D2GameStrc*,D2UnitStrc*,int,D2UnitStrc*,int,int); // 0x005FD470

struct D2SkillListStrc;

int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);   // 0x005DED20

int __fastcall AITACTICS_RunAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DF140

int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask);      // 0x00622AA0

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

struct D2StatListStrc;

#define AI_ROLL_PERCENT(pSeed) ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100))

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

int __fastcall AITACTICS_WalkToTargetWithRandomPathType(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int bDeleteAiEventCallback); // 0x005DF7D0

int __fastcall sub_6FC68350(int, D2ActiveRoomStrc*, int, int, int); // 0x005FD350

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed);

D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange); // 0x005DDC30

#define MINIMUM(a,b) ((a) < (b) ? (a) : (b))

#pragma pack(push,1)

#pragma pack(pop)

struct Obj00648AD0;

struct D2PlayerDataStrc;

struct D2MonStats2Txt;

struct D2PetInfoStrc;

int __fastcall AITACTICS_UseSequenceSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTargetUnit, int nX, int nY); // 0x005DE000

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

void __fastcall AIGENERAL_FreeCurrentAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058ED10

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0

#define MON_FLAG 9

#define ATTACK_MODE 4

#define WALK_CHANCE 20

#define WALK_DISTANCE 3

#define IDLE_FRAMES 10

struct D2AiControlStrc;

struct D2MissilesTxt;

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

enum D2C_M80TotemAi
{
    TOTEM_AI_PARAM_WALK_AWAY_CHANCE_PCT = 0,
    TOTEM_AI_PARAM_IGNORE_TARGET_CHANCE_PCT = 1,
    TOTEM_AI_PARAM_TELEPORT_TO_OWNER_DISTANCE = 2,
    TOTEM_AI_PARAM_FOLLOW_OWNER_DISTANCE = 3,
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall AITHINK_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2EB0

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

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

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms); // 0x00619790

enum D2C_M197ZakarumPriestAi
{
    ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT = 1,
    ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT = 2,
    ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT = 3,
    ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER = 4,
    ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE = 5,
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F7240

int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80

int __fastcall AITHINK_TryRestoreGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005F2FC0

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

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

void __fastcall ACT2Q5_OnSummonerActivated(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059C330

int __fastcall sub_005DEFE0_AiEscape(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback);

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

D2UnitStrc* __fastcall AITHINK_TargetCallback_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F1380

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);   // 0x0056DEB0

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

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

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

int __fastcall AITACTICS_RunToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEFB0

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

void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType);               // 0x0058F090

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

enum D2C_M394IzualAi
{
    IZUAL_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT = 1,
    IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT = 2,
    IZUAL_AI_PARAM_NOVA_IN_MELEE_CHANCE_PCT = 3,
    IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS = 4,
    IZUAL_AI_PARAM_NUM_SWINGS = 5,
};

void __fastcall ACT4Q1_OnIzualActivated(D2GameStrc* pGame);                                                 // 0x005B4390

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

typedef bool (__fastcall* MAPAIACTIONFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam, D2MapAIPathPositionStrc* pPosition);

struct D2MonRegDataStrc;

struct D2MonsterRegionStrc;

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** pMonReg, int nLevelId); // 0x00547BB0

#define GRISWOLD_WALK_FLAGS 7

struct Control;

struct MonStats;

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

#define PATHTYPE_TOWARD 2

#define AI_GetParamValue(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])

struct D2TargetNodeStrc;

enum D2C_AncientBarb1AIParams
{
    ANCIENTBARB1_AI_PARAM_WHIRLWIND_DISTANCE = 0,
    ANCIENTBARB1_AI_PARAM_WHIRLWIND_CHANCE_PCT = 1,
    ANCIENTBARB1_AI_PARAM_ATTACK_CHANCE_PCT = 2,
    ANCIENTBARB1_AI_PARAM_SKILL_REACH = 3,
};

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

int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent);                       // 0x005415A0

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

struct D2UnitFindArgStrc;

struct Target005F6630;

struct Obj005F6630;

struct D2Record5F6E20Strc;

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef int(__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit);

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0

void __fastcall AIGENERAL_SetAiControlParam(D2UnitStrc* pMonster, int nIndex, int nParamValue); // 0x0058EC00

int __fastcall AITACTICS_ChangeModeAndTargetCoordinatesNoStep(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nMode); // 0x005DE490

int __fastcall AITHINK_UnitFindCallback_Willowisp(D2UnitStrc* pUnit); // 0x005F3960

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetListExpireFrame(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, UNITFINDTEST pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

struct Target005F6630
{
    unsigned char bUnknown00[0x14];
    unsigned int dwValue14;
    unsigned int dwValue18;
};

struct Obj005F6630
{
    unsigned char bUnknown00[0xA8];
    unsigned int dwValueA8;
};

struct D2Record5F6E20Strc
{
    char unk0x00[0x32];
    short nMax;
    short nCurrent;
};

enum D2C_M172FetishShamanAi
{
    FETISHSHAMAN_AI_PARAM_HEAL_CHANCE_PCT = 0,
    FETISHSHAMAN_AI_PARAM_HEAL_CAPABILITY = 1,
    FETISHSHAMAN_AI_PARAM_HEAL_RANGE = 2,
    FETISHSHAMAN_AI_PARAM_CIRCLE_CHANCE_PCT = 3,
    FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE = 4,
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F99A0

struct D2RoomCoordListStrc;

typedef void (__fastcall* PetIterateCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

void __stdcall INVENTORY_GetDirectionDelta(unsigned char, unsigned int*, unsigned int*); // 0x0063E7E0

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500

struct D2VileMotherAiCallbackArgStrc
{
    int nLastInClass;
    int nMaxDistance;
    int nCounter;
    int unk0x0C[7];
};

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

int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nNoInChain);                             // 0x0054DA60

int __fastcall AITHINK_VileMotherTrySpawnInDirection(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonStatsTxt* pMonStatsTxt); // 0x005F9E30

int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId);                // 0x006510C0

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

int __fastcall sub_005DE4E0_MoveAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a4, int a5, int a6); // 0x005DE4E0

D2UnitStrc* __fastcall AITHINK_TargetCallback_Vulture(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F30F0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

int __fastcall sub_005DF7D0_Maneuver(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x005DF7D0

D2UnitStrc* __fastcall AITHINK_TargetCallback_SandRaider(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*); // 0x005F06B0

void __fastcall ACT2Q1_OnRadamentActivated(D2GameStrc*,D2UnitStrc*); // 0x00599420

D2UnitStrc* __fastcall AITHINK_TargetCallback_GreaterMummy(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,void*); // 0x005F2A00

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc*, int); // 0x006488A0

extern const unsigned char gnGargoyleTrapDirectionMap[]; // 0x006E3540

extern const unsigned char gnGargoyleTrapDirectionAxis[]; // 0x006E353C

struct D2CoordListStrc;

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

enum D2C_P11AiConstants
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};

int __fastcall AITHINK_GetTrapArrowVariant(D2GameStrc* pGame, D2UnitStrc* pUnit);                     // 0x005FB650

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

struct D2RegurgitatorAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unk0x08[8];
};

D2UnitStrc* __fastcall AITHINK_TargetCallback_Regurgitator(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005FA690

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

D2UnitStrc* __fastcall AITHINK_TargetCallback_OblivionKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005FAE40

D2UnitStrc* __fastcall AITHINK_TargetCallback_Mephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005F7700

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

D2UnitStrc* __fastcall AITHINK_FindTargetForMephisto(D2GameStrc*,D2UnitStrc*,D2MonStatsTxt*,D2UnitStrc*); // 0x005F77C0

inline int CLIENTS_GetUnitXInline_005E17E0(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline_005E17E0(D2UnitStrc* pUnit)
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

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00

static __forceinline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

static inline int MONSTERS_ValidateMonsterIdInline_005EFB80(int nMonsterId)
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

static inline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int AI_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int AI_RollPercentageInline(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
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

static inline int AI_RollPercentage_005EFB80(D2UnitStrc* pUnit)
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

static int AI_RollPercentage_005F4850(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static int AI_RollPercentage_005F1800(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static inline unsigned __int64 RollSeed_005EFE20(D2UnitStrc* pUnit)
{
 const unsigned __int64 lSeed=pUnit->pSeed.nHighSeed+0x6AC690C5i64*pUnit->pSeed.nLowSeed;
 pUnit->pSeed.lSeed=lSeed;return lSeed;
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

#define CMD_ID 4

#define DURATION 20

#define INTERVAL 10

// 0x005F06B0
D2UnitStrc* __fastcall AITHINK_TargetCallback_SandRaider(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2SandRaiderAiCallbackArgStrc* pArg = (D2SandRaiderAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget || !pTarget || pTarget->dwUnitType != UNIT_MONSTER || STATLIST_GetUnitAlignment(pTarget) != 0 || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance >= pArg->nDistance)
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005F3960
int __fastcall AITHINK_UnitFindCallback_Willowisp(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwUnitType : UNIT_INVALID) != 1)
    {
        return 0;
    }

    if (MONSTERS_IsDead(pUnit))
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline_005EFB80(CUNIT_GetMonsterBaseId(pUnit)) != 0x76)
    {
        return 0;
    }

    return 1;
}

// 0x005F6630
extern "C" __declspec(dllexport) void __fastcall AITHINK_InitializeSpawnTimerAndCount(Obj005F6630* pObj, int nUnusedEdx, Target005F6630** ppTarget) {
    Target005F6630* pTarget = *ppTarget;
    pTarget->dwValue14 = pObj->dwValueA8;
    pTarget->dwValue18 = 0;
}

// 0x005F7240
D2UnitStrc* __fastcall AITHINK_TargetCallback_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2ZakarumPriestAiCallbackArgStrc* pArg = (D2ZakarumPriestAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_GOOD || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    switch (CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pTarget)))
    {
    case MONSTER_ZEALOT1:
    case MONSTER_CANTOR1:
        break;

    default:
        return 0;
    }

    if (AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pTarget);
    if (nLifePercentage > 60)
    {
        return 0;
    }

    if (pArg->nMaxLifePercentage <= 0)
    {
        pArg->nMaxLifePercentage = 0x7FFFFFFF;
    }

    ++pArg->nCounter;

    if (nLifePercentage < pArg->nMaxLifePercentage)
    {
        pArg->pTarget = pTarget;
    }

    return 0;
}

// 0x005F77C0
D2UnitStrc* __fastcall AITHINK_FindTargetForMephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pFallbackTarget)
{
    D2MephistoAiCallbackArgStrc arg = {};
    arg.nClosestDistanceSquared = 0x7FFFFFFF;
    arg.nLowestLife = 0x7FFFFFFF;
    arg.nClosestPlayerActorDistanceSquared = 0x7FFFFFFF;

    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Mephisto, 1);

    if (arg.pLowestLifeTarget && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxtRecord, 1))
    {
        return arg.pLowestLifeTarget;
    }

    if (arg.pClosestTargetForPlayerActor && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxtRecord, 2))
    {
        return arg.pLowestLifeTarget;
    }

    return pFallbackTarget;
}

// 0x005F81C0
void __fastcall AITHINK_Fn146_UberMephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
}

// 0x005F9950
void __fastcall AITHINK_FetishShamanClearInfernoAndResetAi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005FAE40
D2UnitStrc* __fastcall AITHINK_TargetCallback_OblivionKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2OblivionKnightAiCallbackArgStrc* pArg = (D2OblivionKnightAiCallbackArgStrc*)pCallbackArg;

    if (pTarget == pUnit)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || MONSTERS_IsDead(pTarget) || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE))
    {
        return 0;
    }

    if (MONSTERS_ValidateMonsterIdInline(CUNIT_GetMonsterBaseId(pTarget)) != MONSTER_DOOMKNIGHT1)
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->nMaxDistanceSquared || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

    if (nDistance < pArg->nClosestDistanceSquared)
    {
        pArg->pClosestDoomKnight = pTarget;
        pArg->nClosestDistanceSquared = nDistance;
    }

    if (nDistance < pArg->nClosestWoundedDistanceSquared && UNITS_GetCurrentLifePercentage(pTarget) < 40)
    {
        pArg->pClosestWoundedDoomKnight = pTarget;
        pArg->nClosestWoundedDistanceSquared = nDistance;
    }

    return 0;
}

// 0x005F1380
D2UnitStrc* __fastcall AITHINK_TargetCallback_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FallenShamanAiCallbackArgStrc* pArg = (D2FallenShamanAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nClassId = MONSTERS_ValidateMonsterIdInline(CUNIT_GetMonsterBaseId(pTarget));
    if ((nClassId != MONSTER_FALLEN1 && nClassId != MONSTER_FALLENSHAMAN1)
        || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL
        || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE)
        || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    const int nMode = pTarget ? pTarget->dwAnimMode : 0;
    if (nMode != MONMODE_DEAD || STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->nMaxDistance || MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE | MONTYPEFLAG_CHAMPION))
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    ++pArg->nCounter;
    return 0;
}

// 0x005F2A00
D2UnitStrc* __fastcall AITHINK_TargetCallback_GreaterMummy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2GreaterMummyAiCallbackArgStrc* pArg = (D2GreaterMummyAiCallbackArgStrc*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || pUnit == pTarget || !STATLIST_AreUnitsAligned(pUnit, pTarget) || STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_GOOD || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE) || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (pArg->bRadament)
    {
        if (!MONSTERS_IsUndead(pTarget))
        {
            return 0;
        }
    }
    else
    {
        if (!(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_LUNDEAD >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_LUNDEAD & 7]))
        {
            return 0;
        }
    }

    if (!pArg->bNormal && MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE) || AITHINK_GetSquaredDistance(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    ++pArg->nCounter;
    if (pTarget->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        pArg->pReviveTarget = pTarget;
        ++pArg->nHealReviveCounter;
        return 0;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
    if (STATLIST_GetMaxLifeFromUnit(pTarget) != nHitpoints && pTarget->dwAnimMode != MONMODE_DEATH)
    {
        pArg->pHealTarget = pTarget;
        ++pArg->nHealReviveCounter;
    }

    return 0;
}

// 0x005F99A0
D2UnitStrc* __fastcall AITHINK_TargetCallback_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FetishShamanAiCallbackArgStrc* pArg = (D2FetishShamanAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE) || STATES_CheckStateMaskUdeadOnUnit(pTarget))
    {
        return 0;
    }

    if (!pArg->nHealCapability && AIGENERAL_GetMinionOwner(pTarget) != pUnit)
    {
        return 0;
    }

    const int nClassId = CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pTarget));
    if ((nClassId == MONSTER_FETISH1 || nClassId == MONSTER_FETISHBLOW1 && pArg->nHealCapability != 1)
        && STATLIST_GetUnitAlignment(pTarget) == UNIT_ALIGNMENT_EVIL
        && (pArg->nHealCapability >= 3 || !MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE | MONTYPEFLAG_CHAMPION)))
    {
        const int nDistanceSquared = AITHINK_GetSquaredDistance(pUnit, pTarget);
        if (nDistanceSquared <= pArg->nMaxSearchRangeSquared)
        {
            if (pTarget->dwAnimMode != MONMODE_DEAD)
            {
                ++pArg->nAliveTargets;

                if (nDistanceSquared < pArg->nSquaredDistanceToClosestAliveTarget)
                {
                    pArg->pClosestAliveTarget = pTarget;
                    pArg->nSquaredDistanceToClosestAliveTarget = nDistanceSquared;
                }
            }
            else
            {
                if (nDistanceSquared < pArg->nSquaredDistanceToClosestDeadTarget)
                {
                    pArg->pClosestDeadTarget = pTarget;
                    pArg->nSquaredDistanceToClosestDeadTarget = nDistanceSquared;
                }
            }
        }
    }

    return 0;
}

static inline int AI_RollPercentage_005F02C0(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005EFB80
void __fastcall AITHINK_Fn007_Brute(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage_005EFB80(pUnit) < AI_GetParam(pGame, pMonStatsTxt, BRUTE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if (AI_RollPercentage_005EFB80(pUnit) < AI_GetParam(pGame, pMonStatsTxt, BRUTE_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            return;
        }

        if (AI_RollPercentage_005EFB80(pUnit) < AI_GetParam(pGame, pMonStatsTxt, BRUTE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    int nLife = UNITS_GetCurrentLifePercentage(pUnit);
    if (nLife < 40)
    {
        nLife = 40;
    }
    else if (nLife > 100)
    {
        nLife = 100;
    }

    AITACTICS_SetAiParam(pUnit, 0, 100 - nLife, 0);
    AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
}

// 0x005EFCF0
void __fastcall AITHINK_Fn002_Skeleton(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_STALL_TIME));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 4 | 2 | 1);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETON_AI_PARAM_STALL_TIME));
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005EFE20
void __fastcall AITHINK_Fn003_Zombie(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;

    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage_005EFE20(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 3))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        }
        return;
    }

    int nParam1 = AI_GetParam(pGame, pMonStatsTxt, 1);
    int nParam0 = AI_GetParam(pGame, pMonStatsTxt, 0);
    if (AIUTIL_IsGettingHit(pUnit))
        goto lApproach;
    if (nDistance < nParam1 && AI_RollPercentage_005EFE20(pUnit) < nParam0)
        goto lApproach;

    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_BURIALGROUNDS)
    {
lApproach:
        AITACTICS_SetAiParam(pUnit, 0, 100, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x005EFF50
void __fastcall AITHINK_Fn004_Bighead(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bInMeleeRange;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (!bCombat && AIUTIL_IsGettingHit(pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
        return;
    }

    if (AIUTIL_GetLifePercentage(pUnit) >= AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        if (nTargetDistance < 15 && AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nTargetDistance, &bInMeleeRange)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
    }
    else
    {
        if (nTargetDistance < 3)
        {
            AITACTICS_SetAiParam(pUnit, 0, 50, 0);
            if (!AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 5, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            }
        }
        else
        {
            if (nTargetDistance > 15)
            {
                AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 6);
                return;
            }

            if (AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nTargetDistance, &bInMeleeRange)
                && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 3))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) >= AI_PARAM(pGame, pMonStatsTxt, 1))
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
            else
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
            }
        }
    }
}

// 0x005F00E0
void __fastcall AITHINK_Fn005_BloodHawk(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int bCombat = pAiTickParam->bCombat;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (pAiControl->dwAiParam[0] == 1 && bCombat)
    {
        pAiControl->dwAiParam[0] = 0;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    pAiControl->dwAiParam[0] = 0;

    if (bCombat)
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 2))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_SetAiParam(pUnit, 0, AI_GetParam(pGame, pMonStatsTxt, 3), 0);
        if (!AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 4, 1))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_SetAiParam(pUnit, 0, AI_GetParam(pGame, pMonStatsTxt, 4), nTargetDistance);
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }

    if (nTargetDistance > 3)
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_SetAiParam(pUnit, 0, -50, 0);
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
        }
        else
        {
            AITACTICS_SetAiParam(pUnit, 0, 0, 0);
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
        }
        return;
    }

    AITACTICS_SetAiParam(pUnit, 0, AI_GetParam(pGame, pMonStatsTxt, 3), 0);
    if (!AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 4, 1))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
    }
}

// 0x005F0700
void __fastcall AITHINK_Fn008_SandRaider(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
    {
        STATES_ToggleState(pUnit,90,0);
        STATES_ToggleState(pUnit,91,0);
        pAiControl->dwAiParam[1] = 0;
    }
    ++pAiControl->dwAiParam[0];
    int nDelay = AI_PARAM(pGame, pMonStatsTxt, 4);
    if (pAiControl->dwAiParam[0] == nDelay)
    {
        switch(AI_PARAM(pGame, pMonStatsTxt, 5))
        {
        default: UNITS_SetOverlay(pUnit,46,0); break;
        case 1: UNITS_SetOverlay(pUnit,150,0); break;
        }
        AITACTICS_IdleInNeutralMode(pGame,pUnit,pMonStatsTxt->nAIdel[pGame->nDifficulty]+1);
        return;
    }
    if (pAiControl->dwAiParam[0] > nDelay)
    {
        switch(AI_PARAM(pGame, pMonStatsTxt, 5))
        {
        default: STATES_ToggleState(pUnit,91,1); break;
        case 1: STATES_ToggleState(pUnit,90,1); break;
        }
        pAiControl->dwAiParam[1] = 1;
    }
    if (pAiControl->dwAiParam[2] < 7 && AIUTIL_GetLifePercentage(pUnit) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        D2SandRaiderAiCallbackArgStrc args;
        args.pTarget = 0;
        args.nDistance = 0x7FFFFFFF;
        AIUTIL_FindTargetWithCallback(pGame,pUnit,&args,AITHINK_TargetCallback_SandRaider,1);
        if(args.pTarget)
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame,pUnit,args.pTarget,0);
            return;
        }
        ++pAiControl->dwAiParam[2];
    }
    if (nDistance > 4 && !pAiControl->dwAiParam[1] && (int)(AI_RollSeed(pSeed)%100) < AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        sub_005DF7D0_Maneuver(pGame,pUnit,pTarget,0,0);
        return;
    }
    if(bCombat)
    {
        if(pAiControl->dwAiParam[1]==1 && pMonStatsTxt->nSkill[0]>=0)
        {
            AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[0],pMonStatsTxt->nSkill[0],pTarget,0,0);
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
            return;
        }
        if((int)(AI_RollSeed(pSeed)%100) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            if((int)SEED_RollLimitedRandomNumber(pSeed,100) < AI_PARAM(pGame, pMonStatsTxt, 6))
                AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,5,pTarget);
            else
                AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,4,pTarget);
            return;
        }
    }
    else if(pAiControl->dwAiParam[1] || (int)(AI_RollSeed(pSeed)%100) < AI_PARAM(pGame, pMonStatsTxt, 3))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame,pUnit,pTarget,0);
        return;
    }
    nDelay = AI_PARAM(pGame, pMonStatsTxt, 4);
    nDistance = 24-nDelay;
    if(nDistance<6) nDistance=6;
    if(pAiControl->dwAiParam[0]>nDelay+nDistance)
    {
        pAiControl->dwAiParam[0] = 0;
        pAiControl->dwAiParam[1] = 0;
    }
    AITACTICS_IdleInNeutralMode(pGame,pUnit,15);
}

// 0x005F0A20
void __fastcall AITHINK_Fn009_Wraith(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ESCAPE_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 12, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
}

// 0x005F0B00
void __fastcall AITHINK_Fn010_CorruptRogue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2PlayerCountBonusStrc playerCountBonus;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    MONSTER_GetPlayerCountBonus(pGame, &playerCountBonus, UNITS_GetRoom(pUnit), pUnit);

    if (nTargetDistance > 20 - 3 * playerCountBonus.nDifficulty)
    {
        AITACTICS_SetAiParam(pUnit, 13, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_RUN_VELOCITY), 0);
        AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, 3);
        return;
    }

    if (bCombat)
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_STALL_DURATION));
        }
        return;
    }

    if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_APPROACH))
    {
        if (AI_RollPercentageInline(pUnit) < AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_RUN_CHANCE_PCT))
        {
            AITACTICS_SetAiParam(pUnit, 13, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_RUN_VELOCITY), 0);
            AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, 3);
            return;
        }
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, CORRUPTROGUE_AI_PARAM_STALL_DURATION));
}

// 0x005F0CD0
void __fastcall AITHINK_Fn011_Baboon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nVel;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);

    if (pMonStatsTxt->nVelocity <= 0)
    {
        goto zero_vel;
    }
    nVel = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity;
    if (nVel < 100)
    {
zero_vel:
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

    if (pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[1] = 0;
        --pAiControl->dwAiParam[0];

        if (!pAiControl->dwAiParam[0] || nLifePercentage > 75)
        {
            const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0) - pAiControl->dwAiParam[2];
            STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nValue, 0);
        }

        if (!bCombat)
        {
            if (nLifePercentage > 75)
            {
                pAiControl->dwAiParam[0] = 0;
                AITACTICS_SetAiParam(pUnit, 13, nVel, 0);
                AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
                return;
            }
        }
        else if (AI_RollPercentage_005F0CD0(pSeed) < 33)
        {
            if (AI_RollPercentage_005F0CD0(pSeed) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (nTargetDistance >= 24 && !AIUTIL_IsGettingHit(pUnit))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 33)
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return;
        }

        AITACTICS_SetAiParam(pUnit, 2, nVel, 0);

        if (!AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 15, 1))
        {
            if (bCombat)
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                    return;
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                return;
            }

            AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        }
        return;
    }

    if (!bCombat)
    {
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
        return;
    }

    if (AIUTIL_IsGettingHit(pUnit))
    {
        if (nLifePercentage < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_HURT_PCT) && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            pAiControl->dwAiParam[0] = SEED_RollLimitedRandomNumber(pSeed, 5) + 2;

            const int nHpRegen = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0);
            if (nHpRegen)
            {
                pAiControl->dwAiParam[2] = (nHpRegen * AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_REGEN_BONUS)) / 8;
                STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nHpRegen + pAiControl->dwAiParam[2], 0);
            }
            else
            {
                pAiControl->dwAiParam[2] = 0;
            }

            AITACTICS_SetAiParam(pUnit, 2, nVel, 0);
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 15, 0);
            return;
        }

        if (pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 20)
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
            pAiControl->dwAiParam[1] = 0;
            return;
        }
    }

    if (!pAiControl->dwAiParam[1] || AI_RollPercentage_005F0CD0(pSeed) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        pAiControl->dwAiParam[1] = 1;
        if (AI_RollPercentage_005F0CD0(pSeed) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        return;
    }

    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, BABOON_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
        pAiControl->dwAiParam[1] = 0;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005F12A0
void __fastcall AITHINK_Fn012_019_Goatman_Swarm(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_WALK_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
}

// 0x005F1750
void __fastcall AITHINK_SpecialFn015_SandMaggot(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiCmdStrc* pAiCmd = AIGENERAL_SetCurrentAiCommand(pGame, pUnit, 14, 0);
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiCmd->nCmdParam[4] == 1 && pMonStatsTxt->nSkill[0] >= 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], SUNIT_GetTargetUnit(pGame, pUnit), 0, 0);
        AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 30);
        pAiCmd->nCmdParam[4] = 0;
        return;
    }

    const int nParam = pAiControl->dwAiParam[2];
    AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, pAiControl->nAiSpecialState);
    pAiControl->dwAiParam[2] = nParam;
    AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 1);
}

// 0x005F22B0
void __fastcall AITHINK_Fn018_PantherWoman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
        return;
    }

    if (!bCombat && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_SetAiParam(pUnit, 0, 75, 0);
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
        return;
    }

    D2PantherAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_Panther, 1);

    D2UnitStrc* pPanther = arg.pTarget;
    if (pPanther && arg.nDistance > AI_PARAM(pGame, pMonStatsTxt, 2) * AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        AITACTICS_SetAiParam(pUnit, 0, 75, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pPanther, 7);
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < 25)
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

// 0x005F2460
void __fastcall sub_005F2460_AiThink(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_WALK_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, AI_PARAM_IDLE_FRAMES));
}

// 0x005F3730
void __fastcall AITHINK_Fn024_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage_005EFB80(pUnit) < AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_ATTACK_CHANCE_PCT) || !pAiControl->dwAiParam[1])
        {
            ++pAiControl->dwAiParam[1];

            if (pMonStatsTxt->nSkill[0] >= 0 && AI_RollPercentage_005EFB80(pUnit) < AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_SUCK_OR_ATTACK_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }

        if (AI_RollPercentage_005EFB80(pUnit) > 20)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        pAiControl->dwAiParam[1] = 0;
    }

    if (pAiControl->dwAiParam[0] == 0)
    {
        AITACTICS_SetAiParam(pUnit, 13, 100, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
    }
    else if (pAiControl->dwAiParam[0] == 1)
    {
        AITACTICS_SetAiParam(pUnit, 0, 50, 0);
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);

        ++pAiControl->dwAiParam[1];

        if (pAiControl->dwAiParam[1] > AI_GetParam(pGame, pMonStatsTxt, MOSQUITO_AI_PARAM_MAX_AMBIENT_LOOP))
        {
            pAiControl->dwAiParam[0] = 0;
            pAiControl->dwAiParam[1] = 0;
        }
    }
    else if (pAiControl->dwAiParam[0] == 2)
    {
        AITACTICS_SetAiParam(pUnit, 2, 100, 0);
        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 10, 1);
        pAiControl->dwAiParam[0] = 1;
        pAiControl->dwAiParam[1] = 0;
    }
    else
    {
        pAiControl->dwAiParam[0] = 0;
        pAiControl->dwAiParam[1] = 0;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005F4510
void __fastcall AITHINK_Fn026_Arach(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);

    if (pAiControl->dwAiParam[0] == 1)
    {
        pAiControl->dwAiParam[1] = 0;

        if (nLifePercentage > 75)
        {
            pAiControl->dwAiParam[0] = 0;

            if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
            {
                pAiControl->dwAiParam[0] = 2;
                AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 0);
                return;
            }

            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 0);
            return;
        }

        if (bCombat && AI_PARAM(pGame, pMonStatsTxt, 0) > 25 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0) - 25)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 3) || AIUTIL_IsGettingHit(pUnit))
        {
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        pAiControl->dwAiParam[0] = 0;
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 12, 0);
        return;
    }

    if (bCombat)
    {
        pAiControl->dwAiParam[0] = 2;

        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (nLifePercentage < AI_PARAM(pGame, pMonStatsTxt, 4))
        {
            pAiControl->dwAiParam[0] = 1;

            if (pMonStatsTxt->nSkill[0] < 0 || STATES_CheckState(pUnit, STATE_SPIDERLAY))
            {
                AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 8, 0);
                return;
            }

            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, 0, 0);
            return;
        }

        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    if (!AIUTIL_IsGettingHit(pUnit) && pAiControl->dwAiParam[1] != 1)
    {
        ++pAiControl->dwAiParam[2];

        if (pAiControl->dwAiParam[2] > 20)
        {
            pAiControl->dwAiParam[2] = 0;
        }

        pAiControl->dwAiParam[1] = 0;

        if (pAiControl->dwAiParam[2] != 1 || (int)SEED_RollLimitedRandomNumber(pSeed, 100) >= AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 20)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            return;
        }

        pAiControl->dwAiParam[1] = 1;
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 0);
        return;
    }

    pAiControl->dwAiParam[1] = 1;
    AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 0);
}

// 0x005F4A70
void __fastcall AITHINK_Fn028_Vampire(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    int nDistance = pTick->nTargetDistance;
    int bCombat = pTick->bCombat;
    D2UnitStrc* pTarget = pTick->pTarget;
    D2MonStatsTxt* pStats = pTick->pMonstatsTxt;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nFlags = AI_PARAM(pGame, pStats, 4);
    const int bAttack = nFlags & 1;
    const int bSkill1 = nFlags & 2;
    const int bSkill2 = nFlags & 4;
    if (pAi->dwAiParam[2] > 0) --pAi->dwAiParam[2];
    int nNewDistance;
    D2UnitStrc* pNewTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nNewDistance, 0);
    if (AIUTIL_IsGettingHit(pUnit)) {
        if (!pAi->dwAiParam[0]) pAi->dwAiParam[0] = 1;
        if (nDistance < 30 && nDistance > pAi->dwAiParam[1]) pAi->dwAiParam[1] = nDistance;
        if (bCombat) {
            if (AI_ROLL_PERCENT(pSeed) <= 30 && bAttack)
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pTarget, 0, 0);
                else AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pTarget, 0, 0);
            }
            else AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
    }
    const int nLife = UNITS_GetCurrentLifePercentage(pUnit);
    if (pAi->dwAiParam[0] == 2) {
        if (nLife >= 75) {
            pAi->dwAiParam[0] = 1;
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
        if (nDistance < 14 || nDistance <= pAi->dwAiParam[1]) {
            int nVelocity = 0;
            if (pStats->nVelocity > 0) nVelocity = 100 * pStats->nRun / pStats->nVelocity - 100;
            nVelocity = nVelocity <= 0 ? 0 : nVelocity;
            nVelocity = nVelocity >= 120 ? 120 : nVelocity;
            AITACTICS_SetAiParam(pUnit, 0, nVelocity, 0);
            if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 8, 1)) return;
        }
        if (nDistance < AI_PARAM(pGame, pStats, 2) && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 1)) {
            if (bSkill1 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[1], pStats->nSkill[1], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bSkill2 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[2], pStats->nSkill[2], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bAttack && pNewTarget && nNewDistance <= 20) { if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) { AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pNewTarget, 0, 0); return; } AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pNewTarget, 0, 0); return; }
            else sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }
    if (nLife < 33) {
        pAi->dwAiParam[0] = 2;
        if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 8, 0)) return;
    }
    if (bCombat) {
        pAi->dwAiParam[0] = 1;
        if (AI_ROLL_PERCENT(pSeed) < AI_PARAM(pGame, pStats, 0)) {
            if (!bAttack || !pNewTarget || (int)SEED_RollLimitedRandomNumber(pSeed, 100) > 30) {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            if (nNewDistance <= 20) { { if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) { AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pNewTarget, 0, 0); return; } AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pNewTarget, 0, 0); return; } return; }
        }
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 33) sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (nDistance < AI_PARAM(pGame, pStats, 2)) {
        pAi->dwAiParam[0] = 1;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 1)) {
            if (bSkill1 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[1], pStats->nSkill[1], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bSkill2 && pAi->dwAiParam[2] <= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pStats, 3)) {
                AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[2], pStats->nSkill[2], pTarget, 0, 0);
                pAi->dwAiParam[2] = 11;
                return;
            }
            if (bAttack && pNewTarget && nNewDistance <= 20) {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 75) { if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) { AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[0], pStats->nSkill[0], pNewTarget, 0, 0); return; } AITACTICS_UseSkill(pGame, pUnit, pStats->nSkillMode[3], pStats->nSkill[3], pNewTarget, 0, 0); return; }
                else sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
            } else AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
        if (nDistance > 20) { AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7); return; }
        if (nDistance < 9 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) {
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 8, 0);
            return;
        }
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50) sub_6FCD0E80(pGame, pUnit, pTarget, 4, 0);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pAi->dwAiParam[0] == 1) { AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7); return; }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005F4FD0
void __fastcall AITHINK_BatDemon_HandleSpecialAiState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pUnit && pUnit->dwAnimMode == MONMODE_SKILL4)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_Idle(pGame, pUnit, 1);
        return;
    }

    if (pAiControl->dwAiParam[0] == 4)
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL3, 0);
        return;
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, pAiControl->nAiSpecialState);
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

// 0x005F5A20
void __fastcall AITHINK_Fn035_CorruptArcher(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
    if (!pTarget)
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < 50)
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTickTarget, 3, 0);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (!bCombat && AIUTIL_IsGettingHit(pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (nDistance < 6 && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_RUN_CHANCE_PCT))
    {
        AITACTICS_SetAiParam(pUnit, 0, 100, 0);
        if (AITACTICS_RunAwayFromTarget(pGame, pUnit, pTarget, 12, 1))
        {
            return;
        }
    }

    if (AI_GetParam(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE) > 0 && nDistance > AI_GetParam(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE)
        && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_SetAiParam(pUnit, 0, 10, 0);
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_WALK_TOW_DISTANCE));
        return;
    }

    if (nDistance > AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_ALWAYS_RUN_DISTANCE))
    {
        AITACTICS_SetAiParam(pUnit, 0, 100, 0);
        AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_ALWAYS_RUN_DISTANCE));
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[1] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_USE_SKILL_2_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_USE_SKILL_3_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTARCHER_AI_PARAM_STALL_DURATION));
}

static inline int CLIENTS_GetUnitXInline_005F02C0(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYInline_005F02C0(D2UnitStrc* pUnit)
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

// 0x005F5D50
void __fastcall AITHINK_Fn036_CorruptLancer(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pAiTickParam->nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_ALWAYS_RUN_DISTANCE))
    {
        PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);
        AITACTICS_SetAiParam(pUnit, 13, 100, 0);
        AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, pAiTickParam->pMonstats2Txt->nSteps);
        pAiControl->dwAiParam[0] = 1;
        return;
    }

    if (bCombat)
    {
        if (!pAiControl->dwAiParam[0] && !((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_ATTACK_CHANCE_PCT)))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_STALL_DURATION));
            return;
        }

        pAiControl->dwAiParam[0] = 0;

        if (pMonStatsTxt->nSkill[0] >= 0 && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_USE_SKILL_1_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        }
        else if (pMonStatsTxt->nSkill[1] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_USE_SKILL_2_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        }
        else if (pMonStatsTxt->nSkill[2] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_USE_SKILL_3_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        PATH_SetStepNum(pUnit->pDynamicPath, pAiTickParam->pMonstats2Txt->nSteps);

        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_RUN_CHANCE_PCT))
        {
            AITACTICS_SetAiParam(pUnit, 13, 100, 0);
            AITACTICS_RunToTargetUnitWithSteps(pGame, pUnit, pTarget, pAiTickParam->pMonstats2Txt->nSteps);
            return;
        }

        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 3);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, CORRUPTLANCER_AI_PARAM_STALL_DURATION));
}

// 0x005F6070
void __fastcall AITHINK_Fn037_SkeletonBow(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (AIUTIL_IsGettingHit(pUnit))
    {
        D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
        if (pTarget)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
    }

    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
    if (pTarget && nDistance < 20)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if ((int)(AI_RollUnitSeed(pUnit) % 100) < 20)
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTickTarget, 3, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_STALL_DURATION));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTickTarget, AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_WALK_STEPS), AI_PARAM(pGame, pMonStatsTxt, SKELETONBOW_AI_PARAM_TARGET_DISTANCE));
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
}

// 0x005F6220
void __fastcall AITHINK_Fn038_MaggotLarva(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->bCombat)
    {
        if (pAiControl->dwAiParam[0] || AI_RollPercentage(pUnit) >= AI_GetParam(pGame, pMonStatsTxt, 0))
        {
            pAiControl->dwAiParam[0] = 0;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        }
        else
        {
            pAiControl->dwAiParam[0] = 1;
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    pAiControl->dwAiParam[0] = 0;
    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 2))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 1);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 3));
}

// 0x005F6530
void __fastcall AITHINK_Fn040_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pMonStatsTxt->nSkill[0] >= 0 && pAiControl->dwAiParam[0] != 1 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 0));
        pAiControl->dwAiParam[0] = 1;
        return;
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        SUNITDMG_KillMonster(pGame, pUnit, SUNIT_GetTargetUnit(pGame, pUnit), 1);
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 0));
}

// 0x005F6650
void __fastcall AITHINK_Fn043_FoulCrowNest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiTickParam->nTargetDistance > 20)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
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

    if (pMonStatsTxt->nSkill[0] >= 0 && nDiff >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        pAiControl->dwAiParam[0] = pGame->dwGameFrame;
        const int nMonsterId = MONSTER_CROWNEST1 >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : MONSTER_CROWNEST1;
        if (sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 10 + 20);
}

// 0x005F67B0
void __fastcall AITHINK_Fn044_Duriel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pMonStatsTxt->nSkill[3] >= 0 && !UNITS_GetRightSkill(pUnit))
    {
        D2GAME_SetSkills_6FD14C60(pUnit, pMonStatsTxt->nSkill[3], AI_GetParam(pGame, pMonStatsTxt, 0), 1);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, pMonStatsTxt->nSkill[3], -1);
    }

    if (bCombat)
    {
        if (pMonStatsTxt->nSkill[2] >= 0 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
        }
        else if (pMonStatsTxt->nSkill[1] >= 0 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 2))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        }
        else if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 3))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        }
        else
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        }
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 4))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
    }
    else
    {
        AITACTICS_SetAiParam(pUnit, 13, 0, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
    }
}

// 0x005F6A10
void __fastcall AITHINK_Fn045_Sarcophagus(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->nTargetDistance > 25)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    if (pAiControl->dwAiParam[1] > pMonStatsTxt->wAiParam[2][pGame->nDifficulty])
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

    if (pMonStatsTxt->nSkill[0] >= 0 && nDiff >= pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        const int nMonsterId = MONSTER_SARCOPHAGUS >= sgptDataTables->nMonStatsTxtRecordCount ? -1 : MONSTER_SARCOPHAGUS;
        if (sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0))
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame;
            ++pAiControl->dwAiParam[1];
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 10 + 20);
}

// 0x005F6B70
void __fastcall AITHINK_Fn046_ElementalBeast(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nState = pAiTickParam->pAiControl->dwAiParam[0];

    if (nState == 2)
    {
        SUNITDMG_KillMonster(pGame, pUnit, pTarget, 1);
        return;
    }

    if (!nState)
    {
        if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 1) || AIUTIL_IsGettingHit(pUnit))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
            pAiControl->dwAiParam[0] = 1;
            return;
        }
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        if (!bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                return;
            }

            AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL1, pTarget);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + 1, 0, 0);
        pAiControl->dwAiParam[0] = 2;
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 2));
}

// 0x005F6CA0
void __fastcall AITHINK_Fn047_FlyingScimitar(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (pAiTickParam->bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FLYINGSCIMITAR_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FLYINGSCIMITAR_AI_PARAM_CIRCLE_CHANCE_PCT))
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 2, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, FLYINGSCIMITAR_AI_PARAM_STALL_DURATION));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FLYINGSCIMITAR_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 8, 1);
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FLYINGSCIMITAR_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, FLYINGSCIMITAR_AI_PARAM_STALL_DURATION));
}

// 0x005F30F0
D2UnitStrc* __fastcall AITHINK_TargetCallback_Vulture(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2VultureAiCallbackArgStrc* pArg = (D2VultureAiCallbackArgStrc*)pCallbackArg;
    if (pTarget && (pTarget->dwUnitType == UNIT_MONSTER || pTarget->dwUnitType == UNIT_PLAYER) && pUnit != pTarget && !MONSTERS_IsDead(pTarget))
    {
        const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
        if (nDistance <= pArg->nDistance)
        {
            const int nHitpoints = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
            if (nHitpoints <= STATLIST_GetMaxLifeFromUnit(pTarget) / 100 * pArg->nLifePercentage)
            {
                pArg->pTarget = pTarget;
                pArg->nDistance = nDistance;
            }
        }
    }

    return 0;
}

// 0x005F6E20
int __fastcall AITHINK_GetPercentOverMax(D2Record5F6E20Strc* pRecord)
{
    int nResult = 0;
    const short nMax = pRecord->nMax;
    if (nMax > 0)
    {
        nResult = pRecord->nCurrent * 100 / nMax - 100;
        nResult = nResult > 0 ? nResult : 0;
        if (nResult >= 120)
        {
            nResult = 120;
        }
    }

    return nResult;
}

// 0x005F6E60
void __fastcall AITHINK_Fn048_ZakarumZealot(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nVel = 0;
    if (pMonStatsTxt->nVelocity > 0)
    {
        const int nRatio = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity;
        const int nDiff = nRatio - 100;
        nVel = nDiff > 0 ? nDiff : 0;
        if (nVel >= 120)
            nVel = 120;
    }
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    D2UnitStrc* pPlayer = pTarget;
    if (pTarget)
    {
        if (pTarget->dwUnitType == UNIT_MONSTER)
        {
            int nOwnerGUID;
            int nOwnerType;
            AIGENERAL_GetOwnerData(pTarget, &nOwnerGUID, &nOwnerType);
            if (nOwnerType == UNIT_PLAYER)
                pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
        }
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == ACT_III)
        {
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, 0))
            {
                AITACTICS_SetAiParam(pUnit, 0, nVel, 0);
                if (!AITACTICS_RunAwayFromTarget(pGame, pUnit, pTarget, 8, 1))
                    AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
                return;
            }
        }
    }
    if (AIUTIL_IsGettingHit(pUnit))
    {
        if (!pAiControl->dwAiParam[1] && nLifePercentage < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_HURT_PCT))
        {
            pAiControl->dwAiParam[0] = 0;
            AITACTICS_SetAiParam(pUnit, 0, nVel, 0);
            if (AITACTICS_RunAwayFromTarget(pGame, pUnit, pTarget, 8, 1))
                return;
            pAiControl->dwAiParam[1] = 5;
        }
        if (COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), COLLIDE_MISSILE))
        {
            if (bCombat)
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
                return;
            }
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }
    }
    if (pAiControl->dwAiParam[1])
        --pAiControl->dwAiParam[1];
    if (bCombat)
    {
        if (pAiControl->dwAiParam[0])
        {
            if (!((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_ATTACK_CHANCE_PCT)))
            {
                pAiControl->dwAiParam[0] = 0;
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 80)
                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                else
                    AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
                return;
            }
        }
        pAiControl->dwAiParam[0] = 1;
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_ATTACK2_CHANCE_PCT))
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        else
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }
    pAiControl->dwAiParam[0] = 0;
    if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMZEALOT_AI_PARAM_RUN_CHANCE_PCT))
    {
        AITACTICS_SetAiParam(pUnit, 0, nVel, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}

// 0x005F72D0
void __fastcall AITHINK_Fn049_ZakarumPriest(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    if (bCombat || AIUTIL_IsGettingHit(pUnit))
    {
        if (pMonStatsTxt->nSkill[2] >= 0 && nLifePercentage < 33 && pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + 4 * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);

            int nTargetX;
            int nShift = 0;
            int nX = CLIENTS_GetUnitX(pUnit);
            int nY = CLIENTS_GetUnitY(pUnit);
            nTargetX = CLIENTS_GetUnitX(pTarget);
            int nTargetY = CLIENTS_GetUnitY(pTarget);
            if (bCombat)
            {
                nShift = 2;
            }

            nTargetX = ((nTargetX - nX) << nShift) + nTargetX;
            nTargetY = ((nTargetY - nY) << nShift) + nTargetY;

            if (sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], 0, nTargetX, nTargetY);
                return;
            }
        }

        if (bCombat && (int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            return;
        }
    }

    D2ZakarumPriestAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nCounter = 0;
    arg.nMaxLifePercentage = 0x7FFFFFFF;
    arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE) * AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_HEAL_RANGE);
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_ZakarumPriest, 1);

    if (pMonStatsTxt->nSkill[0] >= 0 && arg.pTarget && (int)(AI_RollSeed(pSeed) % 100) < 25)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], arg.pTarget, 0, 0);
        return;
    }

    if (AIUTIL_HasClearMissilePath(pUnit, pTarget))
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_CAST_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
                return;
            }

            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_LIGHTNING_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
                pAiControl->dwAiParam[2] = pGame->dwGameFrame + 20;
                return;
            }
        }
    }
    else
    {
        if ((int)(AI_RollSeed(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_ATTACK_CHANCE_PCT) && pMonStatsTxt->nSkill[3] >= 0
            && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_BLIZZARD_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, 0, 0);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, ZAKARUMPRIEST_AI_PARAM_SPELL_TIMER);
            return;
        }
    }

    if ((int)(AI_RollSeed(pSeed) % 100) < 30)
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
    }
}

// 0x005F7700
D2UnitStrc* __fastcall AITHINK_TargetCallback_Mephisto(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2MephistoAiCallbackArgStrc* pArg = (D2MephistoAiCallbackArgStrc*)pCallbackArg;
    if (pUnit == pTarget || SUNIT_IsDead(pTarget) || !pTarget || !UNIT_HasFlag(pTarget, UNITFLAG_CANBEATTACKED) || !SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > 1024)
    {
        return 0;
    }

    ++pArg->nCounter;
    if (nDistance <= 225)
    {
        ++pArg->nCloseTargetCount;
    }

    if (nDistance < pArg->nClosestDistanceSquared)
    {
        pArg->pClosestTarget = pTarget;
        pArg->nClosestDistanceSquared = nDistance;
    }

    const int nLife = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0) >> 8;
    if (nLife < pArg->nLowestLife)
    {
        pArg->pLowestLifeTarget = pTarget;
        pArg->nLowestLife = nLife;
    }

    if (nDistance < pArg->nClosestPlayerActorDistanceSquared && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pArg->pClosestTargetForPlayerActor = pTarget;
        pArg->nClosestPlayerActorDistanceSquared = nDistance;
    }

    return 0;
}

// 0x005F78B0
void __fastcall AITHINK_Fn050_Mephisto(D2GameStrc* game,D2UnitStrc* unit,D2AiTickParamStrc* tick)
{
    const int distance=tick->nTargetDistance;
    const int combat=tick->bCombat;
    D2UnitStrc* target=tick->pTarget;
    D2SeedStrc* seed=&unit->pSeed;
    D2AiControlStrc* control=tick->pAiControl;
    D2MonStatsTxt* stats=tick->pMonstatsTxt;
    int life=UNITS_GetCurrentLifePercentage(unit);
    int injury=(100-life)/5;
    if(injury<0) injury=0;
    int state=control->dwAiParam[2];
    if(combat) {
        if(AI_ROLL_PERCENT(seed)>AI_PARAM(game, stats, 0)) state=3;
        else {
            state=2;
            control->dwAiParam[0]=(unsigned int)SEED_RollRandomNumber(seed)%3+3;
        }
    }
    else {
        if(distance>20) state=4;
        else {
        L0:
            if(state==0) {
                if(life<=20 && distance<5 && AI_ROLL_PERCENT(seed)<40) state=1;
                else if(AI_ROLL_PERCENT(seed)<50+injury) {
                    state=2;
                    control->dwAiParam[0]=(unsigned int)SEED_RollRandomNumber(seed)%3+3;
                }
                else {
                    if(state) goto L0;
                    goto Fallback;
                }
            }
        }
    }
    switch(state) {
    case 0:
        state=4;
        AITACTICS_IdleInNeutralMode(game,unit,5);
        break;
    case 1:
        state=0;
        AITACTICS_SetVelocity(unit,0,50,0);
        if(AITACTICS_WalkAwayFromTarget(game,unit,target,8,1)) break;
        if(combat) {
            AITACTICS_UseSkill(game,unit,stats->nSkillMode[2],stats->nSkill[2],target,0,0);
            break;
        }

    case 2:
        if(--control->dwAiParam[0]==0) state=0;
        if(control->dwAiParam[1]) {
            ++control->dwAiParam[1];
            target=AITHINK_FindTargetForMephisto(game,unit,stats,target);
            int count=0;
            int i=0;
            short* skills=stats->nSkill;
            short* skill=skills;
            for(;i<8;++i) {
                if(*skill<0) break;
                ++count;
                ++skill;
            }
            if(count>0) {
                int percent=100/count;
                int roll=AI_ROLL_PERCENT(seed);
                int blocked=0;
                if(game->nDifficulty>0 && target && UNITS_TestCollisionWithUnit(unit,target,4)) blocked=1;
                if(game->nDifficulty>0 && (blocked || distance>30)) AITACTICS_UseSkill(game,unit,stats->nSkillMode[5],stats->nSkill[5],target,0,0);
                else if(distance<15 && roll<percent && game->nDifficulty>0) AITACTICS_UseSkill(game,unit,stats->nSkillMode[4],stats->nSkill[4],target,0,0);
                else if(roll<2*percent) AITACTICS_UseSkill(game,unit,stats->nSkillMode[3],stats->nSkill[3],target,0,0);
                else if(roll<3*percent) AITACTICS_UseSkill(game,unit,stats->nSkillMode[1],stats->nSkill[1],target,0,0);
                else AITACTICS_UseSkill(game,unit,stats->nSkillMode[0],skills[0],target,0,0);
            }
            else AITACTICS_WalkCloseToUnit(game,unit,6);
            if(AI_ROLL_PERCENT(seed)<50-injury) control->dwAiParam[1]=0;
        }
        else {
            control->dwAiParam[1]=2;
            if(!AITACTICS_WalkToTargetWithRandomPathType(game,unit,target,3,1)) AITACTICS_WalkCloseToUnit(game,unit,12);
        }
        break;
    case 3:
        state=0;
        if((int)SEED_RollLimitedRandomNumber(seed,100)<80+injury) {
            if((int)SEED_RollLimitedRandomNumber(seed,100)<80-injury) AITACTICS_ChangeModeAndTargetUnit(game,unit,4,target);
            else AITACTICS_UseSkill(game,unit,stats->nSkillMode[2],stats->nSkill[2],target,0,0);
        }
        else {
            AITACTICS_SetVelocity(unit,0,50,0);
            if(!AITACTICS_WalkToTargetWithRandomPathType(game,unit,target,3,1)) AITACTICS_WalkCloseToUnit(game,unit,12);
        }
        break;
    case 4:
        state=0;
        AITACTICS_SetVelocity(unit,0,50,0);
        if(!D2GAME_AICORE_WalkToOwner_6FCD0B60(game,unit,target,6)) {
            D2GAME_EVENTS_Delete_6FC34840(game,unit,2,0);
            if(!D2GAME_AICORE_Escape_6FCD0560(game,unit,target,12,6)) AITACTICS_WalkCloseToUnit(game,unit,12);
        }
        break;
    default:
    Fallback:
        state=0;
        if(AI_ROLL_PERCENT(seed)<65) {
            if(AI_ROLL_PERCENT(seed)<65 || distance>5) AITACTICS_WalkToTargetWithRandomPathType(game,unit,target,4,0);
            else {
                AITACTICS_SetVelocity(unit,0,0,4);
                AITACTICS_WalkToTargetUnitWithFlags(game,unit,target,7);
            }
        }
        else AITACTICS_IdleInNeutralMode(game,unit,10);
        break;
    }
    control->dwAiParam[2]=state;
}

enum D2C_J11AiConstants
{
    LEVEL_AI_TRAPARROW_RANDOM = 40,
    UNITFLAG_J11_SPAWNED = 0x4000000,
    STATE_J11_SPAWNED = 184,
};

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x005F7F10
void __fastcall AITHINK_SpawnUberMephistoMinion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    const int nX = UNITS_GetUnitXPosition(pUnit);
    const int nY = UNITS_GetUnitYPosition(pUnit);
    int nMonsterIds[8] = { 725, 725, 726, 726, 727, 728, 729, 730 };
    int nModes[8] = { 8, 8, 8, 8, 8, 8, 8, 8 };
    const int nIndex = (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) & 7;
    D2UnitStrc* pMonster;
    if (pOwner)
    {
        pMonster = MONSTERSPAWN_SpawnAtUnit(pGame, pOwner, nMonsterIds[nIndex], nModes[nIndex], 4, 0);
    }
    else
    {
        pMonster = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nMonsterIds[nIndex], nModes[nIndex], 4, 0);
    }
    if (pMonster)
    {
        pMonster->dwFlags |= UNITFLAG_J11_SPAWNED;
        STATES_ToggleState(pMonster, STATE_J11_SPAWNED, 1);
    }
}

// 0x005F81D0
void __fastcall AITHINK_SpecialFn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
	D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
	const int nAiSpecialState = pAiControl->nAiSpecialState;
	D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

	if (nAiSpecialState != 10 && nAiSpecialState != 11)
	{
		const short nSkillId = pMonStatsTxt->nSkill[0];
		if (nSkillId >= 0 && pAiControl->dwAiParam[2] >= 2)
		{
			AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pAiTickParam->pTarget, 0, 0);
			pAiControl->dwAiParam[2] = 1;
			AITHINK_RemoveGroundCollision(pGame, pUnit);
			return;
		}

		AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
		AITACTICS_Idle(pGame, pUnit, 1);
		return;
	}

	AITHINK_ExecuteAiFn(pGame, pUnit, pAiControl, nAiSpecialState);
	AITACTICS_Idle(pGame, pUnit, 1);
}

// 0x005F85C0
void __fastcall AITHINK_Fn053_Summoner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!pAiControl->dwAiParam[0])
    {
        ACT2Q5_OnSummonerActivated(pGame, pUnit);
        pAiControl->dwAiParam[0] = 1;
    }

    if (nTargetDistance < 5 && AI_RollPercentage_005F02C0(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WALK_AWAY_CHANCE_PCT))
    {
        sub_005DEFE0_AiEscape(pGame, pUnit, pTarget, 6, 0);
    }

    int bUseColdSkill = STATLIST_UnitGetStatValue(pTarget, 39, 0) >= STATLIST_UnitGetStatValue(pTarget, 43, 0);

    const int nX = CLIENTS_GetUnitXInline_005F02C0(pTarget);
    const int nY = CLIENTS_GetUnitYInline_005F02C0(pTarget);

    if (AI_RollPercentage_005F02C0(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_CAST_CHANCE_PCT))
    {
        if (pMonStatsTxt->nSkill[4] >= 0 && AI_RollPercentage_005F02C0(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_WEAKEN_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }

        int nDistance;
        D2UnitStrc* pMissileTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

        if (AI_RollPercentage_005F02C0(pUnit) > AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_PREF_ELEMENT_CHANCE_PCT))
        {
            bUseColdSkill = (bUseColdSkill == 0);
        }

        if (bUseColdSkill)
        {
            if (pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
            {
                pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pMissileTarget, nX, nY);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[3] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[2])
        {
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_FIREWALL_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0 && pMissileTarget && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_MISSILE_DISTANCE))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pMissileTarget, nX, nY);
            return;
        }

        if (!bUseColdSkill && pMonStatsTxt->nSkill[1] >= 0 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_DISTANCE))
        {
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SUMMONER_AI_PARAM_NOVA_TIMER);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, nX, nY);
            return;
        }

        if (pMonStatsTxt->nSkill[4] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[4], pMonStatsTxt->nSkill[4], pTarget, nX, nY);
            return;
        }
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
}

// 0x005F8F80
void __fastcall AITHINK_Fn056_Tentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    const int nOwnerMode = pOwner->dwAnimMode;
    if (nOwnerMode == MONMODE_DEAD && AI_RollPercentage(pUnit) < 40)
    {
        SUNITDMG_KillMonster(pGame, pUnit, SUNIT_GetTargetUnit(pGame, pOwner), 1);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[2])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 8);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + DEFAULT_FRAMES_PER_SECOND * AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_SUBMERGE_DURATION_SECONDS);
        pAiControl->dwAiParam[2] = 1;
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && pAiControl->dwAiParam[2] == 2 && pGame->dwGameFrame > pAiControl->dwAiParam[1])
    {
        if (nTargetDistance > AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_ACTIVE_DISTANCE)
            || !bCombat && AI_RollChance(pGame, pSeed, pMonStatsTxt, TENTACLE_AI_PARAM_SUBMERGE_CHANCE_PCT)
            || nOwnerMode == MONMODE_SEQUENCE && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 50)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 8);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + DEFAULT_FRAMES_PER_SECOND * AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_SUBMERGE_DURATION_SECONDS);
            pAiControl->dwAiParam[2] = 1;
            return;
        }
    }

    if (pMonStatsTxt->nSkill[1] >= 0 && pAiControl->dwAiParam[2] == 1 && pGame->dwGameFrame > pAiControl->dwAiParam[1]
        && (bCombat || nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_ACTIVE_DISTANCE) || nOwnerMode != MONMODE_SEQUENCE && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 5))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + DEFAULT_FRAMES_PER_SECOND * AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_EMERGE_DURATION_SECONDS);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_STALL_DURATION));
        return;
    }

    if (bCombat && AI_RollChance(pGame, pSeed, pMonStatsTxt, TENTACLE_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, TENTACLE_AI_PARAM_STALL_DURATION));
}

// 0x005F9270
void __fastcall AITHINK_Fn057_TentacleHead(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[2])
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 8);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 2);
        pAiControl->dwAiParam[2] = 1;
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && pAiControl->dwAiParam[2] == 2 && pGame->dwGameFrame > pAiControl->dwAiParam[1])
    {
        if (nDistance > AI_GetParam(pGame, pMonStatsTxt, 5) || !bCombat && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_GetParam(pGame, pMonStatsTxt, 1))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 20);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 2);
            pAiControl->dwAiParam[2] = 1;
            return;
        }
    }

    if (pMonStatsTxt->nSkill[1] >= 0 && pAiControl->dwAiParam[2] == 1 && pGame->dwGameFrame > pAiControl->dwAiParam[1] && (bCombat || nDistance < AI_GetParam(pGame, pMonStatsTxt, 5)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + 25 * AI_GetParam(pGame, pMonStatsTxt, 3);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 4));
        return;
    }

    D2UnitStrc* pNewTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
    if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pNewTarget);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 4));
}

// 0x005F96C0
void __fastcall AITHINK_Fn064_SkeletonMage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2UnitStrc* pTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
    if (pTarget)
    {
        if (nDistance > AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_CHANCE_PCT))
        {
            AITACTICS_SetAiParam(pUnit, 0, 10, 0);
            AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE));
            return;
        }

        if (nDistance <= AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_TOO_CLOSE_DISTANCE) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_WALK_AWAY_CHANCE_PCT))
        {
            AITACTICS_SetAiParam(pUnit, 0, 25, 0);
            if (!AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 5, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTickTarget);
            }
            return;
        }

        if (nDistance < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_FIRE_DIST) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
    }

    if (nDistance > AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE) && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_SetAiParam(pUnit, 0, 10, 0);
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTickTarget, AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_APPROACH_DISTANCE));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTickTarget, 4, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SKELETONMAGE_AI_PARAM_STALL_DURATION));
}

// 0x005F9CF0
void __fastcall AITHINK_Fn066_SandMaggotQueen(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[2])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25 * AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[2] = 0;
        return;
    }

    if (!pAiControl->dwAiParam[1] && pAiControl->dwAiParam[0] < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        AITACTICS_ChangeModeAndTargetCoordinatesOneStep(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 8);
        AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[1] = 1;
        return;
    }

    if (pAiControl->dwAiParam[1])
    {
        int nSpawnMode;
        int nMonsterId;
        int nX;
        int nY;
        MONSTERS_GetMinionSpawnInfo(pUnit, &nMonsterId, &nX, &nY, &nSpawnMode, 0, AIGENERAL_GetMinionSpawnClassId);
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        if (pRoom)
        {
            D2UnitStrc* pSandMaggot = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nSpawnMode, 2, 66);
            if (pSandMaggot)
            {
                pSandMaggot->dwFlags |= UNITFLAG_NOXP;
                ++pAiControl->dwAiParam[0];
            }
        }

        AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        pAiControl->dwAiParam[1] = 0;
        pAiControl->dwAiParam[2] = 1;
    }
}

// 0x005F9E30
int __fastcall AITHINK_VileMotherTrySpawnInDirection(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonStatsTxt* pMonStatsTxt)
{
    unsigned char nIndex = UNITS_GetDirectionToCoords(pUnit, CLIENTS_GetUnitXInline_005E17E0(pTarget), CLIENTS_GetUnitYInline_005E17E0(pTarget));
    nIndex = INVENTORY_GetEightWayDirection(nIndex);
    const unsigned char nIndices[8] = { 6, 4, 2, 2, 2, 0, 6, 6 };

    for (int i = 0; i < 8; ++i)
    {
        nIndex = nIndex % 8;

        int nX;
        int nY;
        INVENTORY_GetDirectionDelta(nIndices[nIndex], (unsigned int*)&nX, (unsigned int*)&nY);

        const int nFinalX = 3 * nX + CLIENTS_GetUnitXInline_005E17E0(pUnit);
        const int nFinalY = 3 * nY + CLIENTS_GetUnitYInline_005E17E0(pUnit);
        const int nMonsterId = SKILLDESC_ValidateMonsterId(MONSTER_VILEMOTHER1);
        if (pMonStatsTxt->nSkill[0] >= 0 && sub_6FC68350(nMonsterId, UNITS_GetRoom(pUnit), nFinalX, nFinalY, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nFinalX, nFinalY);
            return 1;
        }

        ++nIndex;
    }

    return 0;
}

// 0x005FA380
void __fastcall AITHINK_Fn070_FingerMage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    int nVel = 0;

    if (pMonStatsTxt->nVelocity > 0)
    {
        const int nExcess = 100 * pMonStatsTxt->nRun / pMonStatsTxt->nVelocity - 100;
        nVel = nExcess > 0 ? nExcess : 0;
        if (nVel >= 120)
        {
            nVel = 120;
        }
    }

    if (AIUTIL_IsGettingHit(pUnit))
    {
        pAiControl->dwAiParam[0] = 0;

        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_RANGE))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        ++pAiControl->dwAiParam[1];

        if (nLifePercentage > AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_FLEE_LIFE_PCT) || (int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 25 || pAiControl->dwAiParam[1] > AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_FLEE_TICKS))
        {
            pAiControl->dwAiParam[0] = 0;
        }
        else if (nDistance < 14)
        {
            AITACTICS_SetAiParam(pUnit, 0, nVel, 0);
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 14, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    if (!AIGENERAL_GetMinionOwner(pUnit) && nLifePercentage < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_ESCAPE_LIFE_PCT))
    {
        pAiControl->dwAiParam[0] = 1;
        pAiControl->dwAiParam[1] = 0;
        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 9, 0);
        return;
    }

    if (bCombat)
    {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        if (pMonStatsTxt->nSkill[0] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, MONMODE_ATTACK2, 0);
        return;
    }

    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_RANGE))
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_CAST_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (STATES_CheckState(pTarget, STATE_FINGERMAGECURSE))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_IDLE_FRAMES));
        return;
    }

    if (nDistance >= AI_PARAM(pGame, pMonStatsTxt, FINGERMAGE_AI_PARAM_APPROACH_RANGE))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }

    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}

enum
{
    UNITFLAG_ISMERC = 0x00000200,
    MONSTATS2FLAGINDEX_SOFT = 12,
};

// 0x005FA690
D2UnitStrc* __fastcall AITHINK_TargetCallback_Regurgitator(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2RegurgitatorAiCallbackArgStrc* pArg = (D2RegurgitatorAiCallbackArgStrc*)pCallbackArg;

    if (pUnit == pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER || UNIT_HasFlag(pTarget, UNITFLAG_ISMERC) || !UNIT_HasFlag(pTarget, UNITFLAG_TARGETABLE))
    {
        return 0;
    }

    if (!MONSTERS_IsDead(pTarget) || STATES_CheckStateMaskUdeadOnUnit(pTarget) || STATLIST_GetUnitAlignment(pTarget) != UNIT_ALIGNMENT_EVIL)
    {
        return 0;
    }

// build: symbol ?MONSTERREGION_CheckMonStats2Flag@* 0x004638A0
    if (!MONSTERREGION_CheckMonStats2Flag(pTarget->dwClassId, MONSTATS2FLAGINDEX_SOFT))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance > pArg->nDistance)
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005FAA90
void __fastcall AITHINK_Fn072_DoomKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->bCombat)
    {
        if (AI_ROLL_PERCENT(&pUnit->pSeed) < AI_PARAM(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        return;
    }

    if (AI_ROLL_PERCENT(&pUnit->pSeed) < AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

// 0x005FAB80
void __fastcall AITHINK_Fn073_AbyssKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nTargetDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nLifePct = UNITS_GetCurrentLifePercentage(pUnit);

    if (pMonStatsTxt->nSkill[1] >= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(pMonStatsTxt->nSkill[1]);
        if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState)
            && nLifePct < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_HP_PCT)
            && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_BONE_ARMOR_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], 0, 0, 0);
            return;
        }
    }

    if (bCombat)
    {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_NO_FIRE_DISTANCE) && pAiControl->dwAiParam[0] <= 0)
    {
        pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_FIRE_RECOVERY);
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && !pAiControl->dwAiParam[0] && (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData || pUnit->pMonsterData->nComponent[10] < 4u))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_FIRE_RECOVERY);
        return;
    }

    if (pAiControl->dwAiParam[0] > 0)
    {
        --pAiControl->dwAiParam[0];
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_SetVelocity(pUnit, 2, 0, ((unsigned int)SEED_RollRandomNumber(pSeed) & 1) + 6);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, ABYSSKNIGHT_AI_PARAM_ACTIVE_DISTANCE))
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

// 0x005FAF00
void __fastcall AITHINK_Fn074_OblivionKnight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTickTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2OblivionKnightAiCallbackArgStrc arg;
    int nDistance;

    arg.pClosestDoomKnight = 0;
    arg.pClosestWoundedDoomKnight = 0;
    arg.nMaxDistanceSquared = 2500;
    arg.nClosestDistanceSquared = 0x7FFFFFFF;
    arg.nClosestWoundedDistanceSquared = 0x7FFFFFFF;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_OblivionKnight, 1);

    D2UnitStrc* pAllyTarget = arg.pClosestDoomKnight;

    if (nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_FLEE_RANGE))
    {
        if (pMonStatsTxt->nSkill[3] > 0)
        {
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(pMonStatsTxt->nSkill[3]);
            if (pSkillsTxtRecord && pSkillsTxtRecord->wAuraTargetState > 0 && !STATES_CheckState(pTickTarget, pSkillsTxtRecord->wAuraTargetState))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[3], pMonStatsTxt->nSkill[3], pTickTarget, 0, 0);
                pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_CURSE_TIMER);
                return;
            }
        }

        if (pAllyTarget)
        {
            if (AITHINK_GetSquaredDistance(pAllyTarget, pTickTarget) > nTargetDistance * nTargetDistance && AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pAllyTarget, 4))
            {
                return;
            }
        }

        AITACTICS_SetAiParam(pUnit, 2, 50, 0);

        if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTickTarget, 10, 1))
        {
            return;
        }

        if (pMonStatsTxt->nSkill[2] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTickTarget, 0, 0);
            return;
        }
    }

    D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);
    if (pTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_ENGAGE_RANGE))
    {
        if (pMonStatsTxt->nSkill[5] > 0 && pGame->dwGameFrame > pAiControl->dwAiParam[0] && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_CURSE_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[5], pMonStatsTxt->nSkill[5], pTickTarget, 0, 0);
            pAiControl->dwAiParam[0] = pGame->dwGameFrame + AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_CURSE_TIMER);
            return;
        }

        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[2] >= 0 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_BONESPIRIT_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
                return;
            }

            if (pMonStatsTxt->nSkill[0] >= 0)
            {
                if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData || pUnit->pMonsterData->nComponent[10] < 4u)
                {
                    AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                    return;
                }
            }
        }
    }

    if (nTargetDistance > AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_APPROACH_DISTANCE))
    {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, OBLIVIONKNIGHT_AI_PARAM_APPROACH_CHANCE_PCT))
        {
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTickTarget, 6);
            return;
        }
    }

    if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < 70)
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTickTarget, 3, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005FB6C0
void __fastcall AITHINK_Fn078_TrapRightArrow(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, 0) || nDistance > AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
        return;
    }

    D2CoordStrc unitCoords;
    UNITS_GetCoords(pUnit, &unitCoords);
    D2CoordStrc targetCoords;
    UNITS_GetCoords(pTarget, &targetCoords);

    int nDiff = unitCoords.nX - targetCoords.nX;
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff > 2 || pGame->dwGameFrame <= pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
        return;
    }

    pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, 2) + pGame->dwGameFrame;
    switch (AITHINK_GetTrapArrowVariant(pGame, pUnit))
    {
    case 1:
        break;
    default:
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        pAiControl->dwAiParam[2] = AI_PARAM(pGame, pMonStatsTxt, 3) + pGame->dwGameFrame;
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
}

// 0x005FB7E0
void __fastcall AITHINK_Fn079_TrapLeftArrow(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, 0) || nDistance > AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
        return;
    }

    D2CoordStrc unitCoords;
    UNITS_GetCoords(pUnit, &unitCoords);
    D2CoordStrc targetCoords;
    UNITS_GetCoords(pTarget, &targetCoords);

    int nDiff = unitCoords.nY - targetCoords.nY;
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }

    if (nDiff > 2 || pGame->dwGameFrame <= pAiControl->dwAiParam[0])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
        return;
    }

    pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, 2) + pGame->dwGameFrame;
    switch (AITHINK_GetTrapArrowVariant(pGame, pUnit))
    {
    case 1:
        break;
    default:
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0)
    {
        pAiControl->dwAiParam[2] = AI_PARAM(pGame, pMonStatsTxt, 3) + pGame->dwGameFrame;
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 30);
}

// 0x005FB900
void __fastcall AITHINK_Fn080_092_TrapPoison_TrapNova(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (nTargetDistance > pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    const short nSkillId = pMonStatsTxt->nSkill[0];
    if (nSkillId >= 0 && pAiControl->dwAiParam[1] == 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pTarget, 0, 0);
        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 1;
        return;
    }
    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
}

// 0x005FB9B0
void __fastcall AITHINK_Fn092_TrapNova(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pTarget)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (nTargetDistance > pMonStatsTxt->wAiParam[0][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[1][pGame->nDifficulty])
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x20000;
        }
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
        return;
    }
    const short nSkillId = pMonStatsTxt->nSkill[0];
    if (nSkillId >= 0 && pAiControl->dwAiParam[1] == 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, pTarget, 0, 0);
        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 1;
        return;
    }
    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[2][pGame->nDifficulty]);
}

// 0x005FBA60
void __fastcall AITHINK_Fn087_TrapMelee(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->bCombat)
    {
        if (AI_RollPercentage(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 40);
}

static inline unsigned int AI_RollUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F02C0
void __fastcall AITHINK_Fn006_Fallen(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pUnit)
    {
        return;
    }

    const int nAnimMode = pUnit->dwAnimMode;
    if (nAnimMode == MONMODE_DEATH || nAnimMode == MONMODE_DEAD)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (; nNumRooms; ++ppRoomList, --nNumRooms)
    {
        const int* pDeadGUID = (*ppRoomList)->nLastDeadGUIDs;
        for (int i = 0; i < 4; ++i, ++pDeadGUID)
        {
            D2UnitStrc* pCorpse = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, *pDeadGUID);
            if (pCorpse && pCorpse->dwAnimMode == MONMODE_DEATH && (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCorpse, nX, nY) < 15)
            {
                pAiControl->dwAiParam[0] = 1;
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                AITACTICS_SetAiParam(pUnit, 0, 50, 0);

                if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pAiTickParam->pTarget, 12, 1))
                {
                    if ((int)(AI_RollUnit(pUnit) % 20) < 1)
                    {
                        SUNIT_AttachSound(pUnit, 17, 0);
                    }

                    return;
                }

                nNumRooms = 1;
                break;
            }
        }
    }

    if (nAnimMode != MONMODE_NEUTRAL)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    D2AiCmdStrc* pCurrentAiCmd = sub_0058EE80(pUnit);
    if (!pCurrentAiCmd)
    {
        if (!bCombat && AIUTIL_IsGettingHit(pUnit))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        if (nDistance < 15 && AIGENERAL_GetMinionOwner(pUnit) == pUnit && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_COMMAND_ATTACK_CHANCE_PCT))
        {
            D2AiCmdStrc aiCmd;
            aiCmd.nCmdParam[0] = 1;
            AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
            AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
            return;
        }

        if (bCombat)
        {
            if (!pAiControl->dwAiParam[0])
            {
                if (!((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT)))
                {
                    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
                    {
                        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, pTarget);
                        return;
                    }

                    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
                    return;
                }
            }

            pAiControl->dwAiParam[0] = 0;
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (nDistance > AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_APPROACH_DISTANCE))
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 30)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pCurrentAiCmd->nCmdParam[0] == 1)
    {
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, FALLEN_AI_PARAM_ATTACK1_OR_2_CHANCE_PCT))
                {
                    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                    return;
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        if (!AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0))
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        }
    }
    else
    {
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005F1140
void __fastcall AITHINK_Fn014_QuillRat(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    D2AiCmdStrc* pCurrentAiCmd = sub_0058EE80(pUnit);
    if (pCurrentAiCmd)
    {
        if (SUNIT_GetServerUnit(pGame, pCurrentAiCmd->nCmdParam[1], pCurrentAiCmd->nCmdParam[2]))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            return;
        }

        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }

    if (bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (AIUTIL_IsGettingHit(pUnit))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
        return;
    }

    if (nDistance < AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_ACTIVATE_DISTANCE))
    {
        if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_SHOOT_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, (unsigned char)AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_WALK_DISTANCE), 1))
        {
            return;
        }

        if (nDistance < 4)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }
    }

    unsigned char nWalkDist;
    if (AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_WALK_DISTANCE) < 3)
    {
        nWalkDist = 3;
    }
    else
    {
        nWalkDist = (unsigned char)AI_PARAM(pGame, pMonStatsTxt, QUILLRAT_AI_PARAM_WALK_DISTANCE);
    }

    AITACTICS_WalkCloseToUnit(pGame, pUnit, nWalkDist);
}

// 0x005F1440
void __fastcall AITHINK_Fn013_FallenShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->bCombat && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    D2FallenShamanAiCallbackArgStrc arg;
    arg.pTarget = 0;
    arg.nCounter = 0;
    arg.nMaxDistance = AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE) * AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_DISTANCE);

    if (!MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE) || MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_CHAMPION))
    {
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 9);
    }
    else
    {
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_FallenShaman, 1);
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
    }

    D2UnitStrc* pResurrectTarget = arg.pTarget;
    if (pResurrectTarget && arg.nCounter && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_RESURRECT_AND_COMMAND_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], arg.pTarget, 0, 0))
    {
        AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[0], pResurrectTarget, 0, 0);
        return;
    }

    if (pTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE) && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        return;
    }

    D2UnitStrc* pNearTarget = sub_6FCF2CC0(pGame, pUnit, &nDistance, 0);
    if (pNearTarget && nDistance < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_DISTANCE) && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_SHOOT_CHANCE_PCT))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pNearTarget, 0, 0);
        return;
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FALLENSHAMAN_AI_PARAM_MELEE_AND_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

static __forceinline bool AI_RollChanceLimited(D2GameStrc* pGame, D2SeedStrc* pSeed, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
    return nRoll < AI_GetParam(pGame, pMonStatsTxt, nParamId);
}

static __forceinline bool AI_RollChanceLimited_005F4850(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
    return nRoll < AI_GetParam(pGame, pMonStatsTxt, nParamId);
}

static inline bool AI_RollLimitedBelow(D2SeedStrc* pSeed, int nChance)
{
    const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
    return nRoll < nChance;
}

// 0x005F1800
void __fastcall AITHINK_Fn015_SandMaggot(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    int nDistance;
    D2UnitStrc* pNearest = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, 0);

    if (pAiControl->dwAiParam[0] < 3 && !pTarget && (!pNearest || nDistance > 10) && pGame->dwGameFrame > pAiControl->dwAiParam[1] && pMonStatsTxt->nSkill[1] >= 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], 0, 0, 0);
        AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 30);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME);
        pAiControl->dwAiParam[0] = 3;
        return;
    }

    if ((pTarget || pNearest && nDistance < 16) && pAiControl->dwAiParam[0] == 3)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[1] && pMonStatsTxt->nSkill[0] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 25);
            pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME);
            pAiControl->dwAiParam[0] = 1;
            return;
        }
    }

    if (pAiControl->dwAiParam[0] == 3)
    {
        AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 20);
        return;
    }

    if (AIUTIL_GetLifePercentage(pUnit) < 25 && pMonStatsTxt->nSkill[1] >= 0 && nDistance < 7 && pGame->dwGameFrame > pAiControl->dwAiParam[1]
        && AI_RollLimitedBelow(pSeed, 20))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
        AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 30);
        pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MIN_UP_DOWN_TIME);
        pAiControl->dwAiParam[0] = 3;
        return;
    }

    if (bCombat && AI_RollPercentage_005F1800(pUnit) < AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_MELEE_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (pNearest && nDistance < 15 && AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, SANDMAGGOT_AI_PARAM_SPIT_CHANCE_PCT))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pNearest);
        return;
    }

    if (AI_RollPercentage_005F1800(pUnit) < 20)
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 0);
        return;
    }

    if (pAiControl->dwAiParam[2] >= AI_GetParam(pGame, pMonStatsTxt, SANDMAGGOT_AI_PARAM_NUMBER_OF_EGGS)
        || !AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, SANDMAGGOT_AI_PARAM_LAY_CHANCE_PCT))
    {
        AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 12);
        return;
    }

    if (pAiControl->dwAiParam[0] == 2 && pMonStatsTxt->nSkill[2] >= 0)
    {
        ++pAiControl->dwAiParam[2];
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], pTarget, 0, 0);
        AITACTICS_ScheduleEarlierAiThink(pGame, pUnit, 20);
        return;
    }

    AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 0);
    pAiControl->dwAiParam[0] = 2;
}

static int AI_RollPercentage_005F1B60(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static short AI_GetParam_005F1B60(D2GameStrc* pGame, D2MonStatsTxt* pMonStatsTxt, int nParamId)
{
    return pMonStatsTxt->wAiParam[nParamId][pGame->nDifficulty];
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

// 0x005F1B60
void __fastcall AITHINK_Fn016_ClawViper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->pAiControl->dwAiParam[0])
    {
        switch (AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 0);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 0);
            break;
        }
    }

    if (bCombat)
    {
        if (AI_RollPercentage_005F1B60(pUnit) < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if (AI_RollPercentage_005F1B60(pUnit) < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_DISTANCE)
        && AI_RollPercentage_005F1B60(pUnit) < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);

        switch (AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 1);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 1);
            break;
        }

        pAiTickParam->pAiControl->dwAiParam[0] = 1;
        return;
    }

    if (AI_RollPercentage_005F1B60(pUnit) < 50)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
}

static __forceinline int AI_RollPercentage_005F1DE0(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F1DE0
void __fastcall AITHINK_Fn142_ClawViperEx(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pAiTickParam->pAiControl->dwAiParam[0])
    {
        switch (AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 0);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 0);
            break;
        }
    }

    if (bCombat)
    {
        if (AI_RollPercentage_005F1DE0(pUnit) < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (nTargetDistance < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPEREX_AI_PARAM_SHOOT_DISTANCE))
    {
        if (AI_RollPercentage_005F1DE0(pUnit) < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
        {
            if (pAiTickParam->pAiControl->dwAiParam[1] < pGame->dwGameFrame)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                pAiTickParam->pAiControl->dwAiParam[1] = pGame->dwGameFrame + AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPEREX_AI_PARAM_SHOOT_TIMER);
                return;
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
            return;
        }
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_DISTANCE)
        && AI_RollPercentage_005F1DE0(pUnit) < AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);

        switch (AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_CHARGE_COLOR))
        {
        case 0:
            break;
        case 2:
            STATES_ToggleState(pUnit, STATE_RED, 1);
            break;
        default:
            STATES_ToggleState(pUnit, STATE_BLUE, 1);
            break;
        }

        pAiTickParam->pAiControl->dwAiParam[0] = 1;
        return;
    }

    if (AI_RollPercentage_005F1DE0(pUnit) < 50)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam_005F1B60(pGame, pMonStatsTxt, CLAWVIPER_AI_PARAM_STALL_DURATION));
}

static inline unsigned int AI_RollSeedUnit(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F20A0
void __fastcall AITHINK_Fn017_SandLeaper(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < 5
        && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_LEAP_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[0], pTarget, 0, 0))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    else
    {
        if (nDistance > 10)
        {
            AITACTICS_SetAiParam(pUnit, 0, 75, 0);
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTarget, 5);
            return;
        }

        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_APPROACH_CHANCE_PCT))
        {
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
            return;
        }

        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SANDLEAPER_AI_PARAM_CIRCLE_CHANCE_PCT))
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005F2540
void __fastcall AITHINK_Fn020_Scarab(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (!pCurrentAiCmd && nDistance < 20 && AIGENERAL_GetMinionOwner(pUnit) == pUnit
        && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_COMMAND_CHANCE_PCT))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
        pCurrentAiCmd = &aiCmd;
    }

    if (pCurrentAiCmd && pCurrentAiCmd->nCmdParam[0] == 1)
    {
        if (bCombat && pMonStatsTxt->nSkill[0] >= 0)
        {
            AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        }
        else
        {
            AITACTICS_SetAiParam(pUnit, 2, 100, 0);
            if (!AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0))
            {
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
            }
        }
        return;
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            if (pMonStatsTxt->nSkill[0] >= 0 && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_JAB_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }

            if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
                return;
            }

            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, SCARAB_AI_PARAM_STALL_DURATION));
        return;
    }

    if (!pAiControl->dwAiParam[0])
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 0, 0);
        pAiControl->dwAiParam[0] = 1;
        return;
    }

    AITACTICS_SetAiParam(pUnit, 2, 0, 4);
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);

    if ((int)(AI_RollSeedUnit(pUnit) % 100) > 10)
    {
        pAiControl->dwAiParam[0] = 0;
    }
}

// 0x005F4850
void __fastcall AITHINK_Fn027_ThornHulk(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiTickParam->bCombat || !pTarget)
    {
        pAiControl->dwAiParam[0] = 0;
        AITACTICS_WalkToTargetWithPathType13(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pAiControl->dwAiParam[0] > 0)
    {
        AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK2, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        const int nEventFrame = EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_ENDANIM);
        if (nEventFrame > pGame->dwGameFrame)
        {
            AITACTICS_Idle(pGame, pUnit, nEventFrame + AI_GetParam(pGame, pMonStatsTxt, 4) - pGame->dwGameFrame);
        }

        --pAiControl->dwAiParam[0];
        if (pAiControl->dwAiParam[0] <= 0)
        {
            pAiControl->dwAiParam[1] = 3;
        }
        return;
    }

    if (AI_RollPercentage_005F4850(pUnit) < AI_GetParam(pGame, pMonStatsTxt, 0))
    {
        if (pAiControl->dwAiParam[1] > 0 || !AI_RollChanceLimited_005F4850(pGame, pUnit, pMonStatsTxt, 3))
        {
            --pAiControl->dwAiParam[1];
            if (AI_RollChanceLimited_005F4850(pGame, pUnit, pMonStatsTxt, 1))
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
            AITACTICS_UseSkill(pGame, pUnit, MONMODE_ATTACK2, pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            const int nEventFrame = EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_ENDANIM);
            if (nEventFrame > pGame->dwGameFrame)
            {
                AITACTICS_Idle(pGame, pUnit, nEventFrame + AI_GetParam(pGame, pMonStatsTxt, 4) - pGame->dwGameFrame);
            }

            pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 5);
        }
        return;
    }

    if (AI_RollChanceLimited_005F4850(pGame, pUnit, pMonStatsTxt, 2))
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, MONMODE_ATTACK1, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

static inline int SEED_RollPercentageHalves(D2SeedStrc* pSeed, unsigned int& nLowSeed, unsigned int& nHighSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    nHighSeed = (unsigned int)(lSeed >> 32);
    nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = nHighSeed;
    pSeed->nLowSeed = nLowSeed;
    return nLowSeed % 100;
}

static inline int SEED_RollPercentageFrom(D2SeedStrc* pSeed, unsigned int nLowSeed, unsigned int nHighSeed)
{
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F2850
void __fastcall AITHINK_Fn021_Mummy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (AIUTIL_IsGettingHit(pUnit) && !bCombat)
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (nDistance > pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_AWAKE_DISTANCE][pGame->nDifficulty])
    {
        if (AI_RollPercentage(pUnit) < pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_APPROACH_CHANCE_PCT][pGame->nDifficulty])
        {
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 3);
        }
        else
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_STALL_DURATION][pGame->nDifficulty]);
        }
        return;
    }

    if (bCombat)
    {
        unsigned int nLowSeed;
        unsigned int nHighSeed;
        if (SEED_RollPercentageHalves(&pUnit->pSeed, nLowSeed, nHighSeed) < pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_ATTACK_CHANCE_PCT][pGame->nDifficulty])
        {
            if (SEED_RollPercentageFrom(&pUnit->pSeed, nLowSeed, nHighSeed) < pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_ATTACK_1_OR_2_CHANCE_PCT][pGame->nDifficulty])
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
            }
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[MUMMY_AI_PARAM_STALL_DURATION][pGame->nDifficulty]);
    }

    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
}

// 0x005F5040
void __fastcall AITHINK_Fn029_BatDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nLifePercentage = UNITS_GetCurrentLifePercentage(pUnit);
    const int nAiState = pAiControl->dwAiParam[0];

    if (nAiState && nAiState != 4)
    {
        if (nAiState == 1)
        {
            if (pAiControl->dwAiParam[1] > 1 && (bCombat || nTargetDistance < 7 || AIUTIL_IsGettingHit(pUnit) || nTargetDistance < 14 && nLifePercentage > 50))
            {
                if (pAiControl->dwAiParam[2])
                {
                    const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0) - pAiControl->dwAiParam[2];
                    STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nValue, 0);
                }

                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL2, 0);
                AITACTICS_Idle(pGame, pUnit, 6);
                pAiControl->dwAiParam[0] = 3;
            }
            else
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL4, 0);
                if (!pAiControl->dwAiParam[1])
                {
                    AITACTICS_Idle(pGame, pUnit, 10);
                }
                else
                {
                    AITACTICS_Idle(pGame, pUnit, 15);
                }

                ++pAiControl->dwAiParam[1];
            }
        }
        else if (nAiState == 2)
        {
            if (nLifePercentage < AI_GetParam(pGame, pMonStatsTxt, BATDEMON_AI_PARAM_HURT_PCT) && AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 15, 0))
            {
                pAiControl->dwAiParam[0] = 4;
            }
            else if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 33)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                pAiControl->dwAiParam[0] = 3;
            }
            else if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 15)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
        else if (nAiState == 3)
        {
            if (nLifePercentage < AI_GetParam(pGame, pMonStatsTxt, BATDEMON_AI_PARAM_HURT_PCT) && AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 15, 0))
            {
                pAiControl->dwAiParam[0] = 4;
            }
            else if (!bCombat)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            }
            else if (pAiControl->dwAiParam[1] > 0)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK2, pTarget);
                pAiControl->dwAiParam[1] = 0;
            }
            else if (AIUTIL_IsGettingHit(pUnit) && AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, BATDEMON_AI_PARAM_DISENGAGE_ON_HIT_CHANCE_PCT)
                && AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 12, 0))
            {
                pAiControl->dwAiParam[0] = 2;
            }
            else if (AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, BATDEMON_AI_PARAM_ATTACK_CHANCE_PCT))
            {
                if (AI_RollChanceLimited(pGame, pSeed, pMonStatsTxt, BATDEMON_AI_PARAM_LIGHTNING_OR_ATTACK_1_CHANCE_PCT))
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
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            }
        }
        else
        {
            if (nTargetDistance < 15)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
                pAiControl->dwAiParam[0] = 3;
            }
            else
            {
                pAiControl->dwAiParam[0] = 4;
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
            }
        }
    }
    else
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_SKILL3, 0);
        AITACTICS_Idle(pGame, pUnit, 8);
        pAiControl->dwAiParam[0] = 1;
        pAiControl->dwAiParam[1] = 0;

        const int nHpRegen = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0);
        if (nHpRegen)
        {
            pAiControl->dwAiParam[2] = (nHpRegen * AI_GetParam(pGame, pMonStatsTxt, BATDEMON_AI_PARAM_REGEN_ROOSTED)) / 8;
            STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, nHpRegen + pAiControl->dwAiParam[2], 0);
        }
        else
        {
            pAiControl->dwAiParam[2] = 0;
        }
    }
}

static inline int MonsterId(int nId) { if (nId<0 || nId>=sgptDataTables->nMonStatsTxtRecordCount) return -1; return nId; }

static inline int UnitClassId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwClassId; }

// 0x005F2B10
void __fastcall AITHINK_Fn022_GreaterMummy(D2GameStrc* pGame,D2UnitStrc* pUnit,D2AiTickParamStrc* pAiTickParam)
{
 int nDistance=pAiTickParam->nTargetDistance;
 D2UnitStrc* pTarget=pAiTickParam->pTarget;
 D2MonStatsTxt* pMonStatsTxt=pAiTickParam->pMonstatsTxt;
 if(pAiTickParam->bCombat && (int)((unsigned int)RollSeed_005EFE20(pUnit)%100)<AI_PARAM(pGame, pMonStatsTxt, 0))
 {
  AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,4,pTarget); return;
 }
 if(nDistance<5 && (int)((unsigned int)RollSeed_005EFE20(pUnit)%100)<AI_PARAM(pGame, pMonStatsTxt, 0))
 {
  AITACTICS_ChangeModeAndTargetUnit(pGame,pUnit,5,pTarget); return;
 }
 D2GreaterMummyAiCallbackArgStrc args;
 args.pReviveTarget=0;args.pHealTarget=0;args.nHealReviveCounter=0;args.nCounter=0;
 int nRange=AI_PARAM(pGame, pMonStatsTxt, 4);args.nMaxDistance=nRange*nRange;args.bRadament=0;args.bNormal=0;
 if(UnitClassId(pUnit)==MonsterId(229))
 {
  ACT2Q1_OnRadamentActivated(pGame,pUnit);
  args.nMaxDistance=(AI_PARAM(pGame, pMonStatsTxt, 4)+10)*(AI_PARAM(pGame, pMonStatsTxt, 4)+10);args.bRadament=1;
  if(!pGame->nDifficulty) args.bNormal=1;
 }
 AIUTIL_FindTargetWithCallback(pGame,pUnit,&args,AITHINK_TargetCallback_GreaterMummy,1);
 D2UnitStrc* pActionTarget=args.pHealTarget;
 if(pMonStatsTxt->nSkill[1]>=0 && pActionTarget && (int)((unsigned int)RollSeed_005EFE20(pUnit)%100)<AI_PARAM(pGame, pMonStatsTxt, 2))
 {
  UNITS_SetTargetUnitForDynamicUnit(pUnit,args.pHealTarget);
  AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[1],pMonStatsTxt->nSkill[1],pActionTarget,0,0); return;
 }
 pActionTarget=args.pReviveTarget;
 if(pActionTarget && (int)((unsigned int)RollSeed_005EFE20(pUnit)%100)<AI_PARAM(pGame, pMonStatsTxt, 1) && sub_005FD470(pGame,pUnit,pMonStatsTxt->nSkill[0],args.pReviveTarget,0,0))
 {
  UNITS_SetTargetUnitForDynamicUnit(pUnit,pActionTarget);
  AITACTICS_UseSequenceSkill(pGame,pUnit,pMonStatsTxt->nSkill[0],pActionTarget,0,0); return;
 }
 if(pMonStatsTxt->nSkill[2]>=0 && (int)((unsigned int)RollSeed_005EFE20(pUnit)%100)<AI_PARAM(pGame, pMonStatsTxt, 3))
 {
  pActionTarget=AIUTIL_SelectAiTargetWithCollisionCheck(pGame,pUnit,&nDistance,0);
  if(pActionTarget)
  {
   AITACTICS_UseSkill(pGame,pUnit,pMonStatsTxt->nSkillMode[2],pMonStatsTxt->nSkill[2],pActionTarget,0,0); return;
  }
 }
 if(args.nCounter<=0)
 {
  AITACTICS_SetAiParam(pUnit,0,50,0);
  AITACTICS_WalkToTargetUnitWithSteps(pGame,pUnit,pTarget,3); return;
 }
 if((int)((unsigned int)RollSeed_005EFE20(pUnit)%100)<50)
  sub_005DF7D0_Maneuver(pGame,pUnit,pTarget,3,0);
 else
  AITACTICS_IdleInNeutralMode(pGame,pUnit,6);
}

void __stdcall COLLISION_ResetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);          // 0x0064CBE0

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0

// 0x005F2EB0
void __fastcall AITHINK_RemoveGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    COLLISION_ResetMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0x1000);
    COLLISION_ResetMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0x100);
    sub_00649190_SetPathMode(pUnit, 5);
    PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
    AITACTICS_Idle(pGame, pUnit, 12);
}

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180

// 0x005F2FC0
int __fastcall AITHINK_TryRestoreGroundCollision(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0xE;
    }

    if (PATH_GetUnitCollisionPattern(pUnit) != 1)
    {
        if (!SUNIT_TeleportUnit(pGame, pUnit, UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 0))
        {
            return 0;
        }

        COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 1, 0x100);
        sub_00649190_SetPathMode(pUnit, 1);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x3C01);
        AITACTICS_Idle(pGame, pUnit, 12);
        return 1;
    }

    return 0;
}

// 0x005FA010
void __fastcall AITHINK_Fn068_VileMother(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    const int nMonstersInChain = DATATBLS_GetMonsterChainInfo(nClassId, 0, 0);
    const int nLastInClass = SKILLS_GetMonsterClassFromChain(sgptDataTables->nMonStatsTxtRecordCount <= MONSTER_VILECHILD1 ? -1 : MONSTER_VILECHILD1, nMonstersInChain);

    if (pAiControl->dwAiParam[0] < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_MAX_SPAWN) && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL
        && (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_SPAWN_CHANCE_PCT))
    {
        D2VileMotherAiCallbackArgStrc arg;
        arg.nLastInClass = nLastInClass;
        arg.nMaxDistance = 25;
        arg.nCounter = 0;
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 12);

        if (arg.nCounter < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_MAX_AT_ONCE) && AITHINK_VileMotherTrySpawnInDirection(pGame, pUnit, pTarget, pMonStatsTxt))
        {
            ++pAiControl->dwAiParam[0];
            return;
        }
    }

    if (bCombat)
    {
        if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_STALL_DURATION));
        return;
    }

    if (pAiControl->dwAiParam[0] >= AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_MAX_SPAWN) || (int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if ((int)(AI_RollSeedUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, VILEMOTHER_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}

enum D2C_VileDogAIParams
{
    VILEDOG_AI_PARAM_ATTACK_CHANCE_PCT = 0,
    VILEDOG_AI_PARAM_STALL_DURATION = 1,
    VILEDOG_AI_PARAM_APPROACH_CHANCE_PCT = 2,
};

// 0x005FA280
void __fastcall AITHINK_Fn069_VileDog(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (!pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    if (bCombat)
    {
        if (AI_ROLL_PERCENT(&pUnit->pSeed) < AI_PARAM(pGame, pMonStatsTxt, VILEDOG_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, VILEDOG_AI_PARAM_STALL_DURATION));
        return;
    }

    if (AI_ROLL_PERCENT(&pUnit->pSeed) < AI_PARAM(pGame, pMonStatsTxt, VILEDOG_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static __forceinline int CLIENTS_GetUnitXInline_005F3170(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; }
}

static __forceinline int CLIENTS_GetUnitYInline_005F3170(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; default: return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; }
}

// 0x005F3170
void __fastcall AITHINK_Fn023_Vulture(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int nDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    int nState = pAiControl->dwAiParam[0];
    if (!pTarget) {
        if (nState < 1) { AITACTICS_Idle(pGame, pUnit, 12); return; }
        if (AITHINK_TryRestoreGroundCollision(pGame, pUnit)) {
            sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pUnit, 9, 2, 3);
            AITACTICS_Idle(pGame, pUnit, 12);
            pAiControl->dwAiParam[0] = -1;
            return;
        }
    }
    int bFar = AITHINK_GetSquaredDistance(pUnit, pTarget) > 144;
    if (pTarget) {
        if (UNITS_GetRoom(pTarget) != UNITS_GetRoom(pUnit) && bFar) {
            if (nState >= 1) {
                if (AITHINK_TryRestoreGroundCollision(pGame, pUnit)) {
                    sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pUnit, 9, 2, 3);
                    AITACTICS_Idle(pGame, pUnit, 12);
                    pAiControl->dwAiParam[0] = -1;
                    return;
                }
            }
            else { D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 9, 0); return; }
        }
    }
    if (!nState && !AIGENERAL_GetMinionOwner(pUnit) && pTarget && bFar && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 60) {
        AITHINK_RemoveGroundCollision(pGame, pUnit);
        pAiControl->dwAiParam[0] = sub_00472210_SeedRollMasked(pSeed, 8) + 24;
        sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pTarget, 8, 8, 8);
        AITACTICS_Idle(pGame, pUnit, 12);
        return;
    }
    D2VultureAiCallbackArgStrc tArg;
    tArg.pTarget = 0;
    tArg.nDistance = 121;
    tArg.nLifePercentage = AI_PARAM(pGame, pMonStatsTxt, 2);
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &tArg, AITHINK_TargetCallback_Vulture, 1);
    if (nState > 1) {
        if (tArg.pTarget) goto SUCCESS;
        if (nDistance < 6 && (int)SEED_RollLimitedRandomNumber(pSeed, 100) < 15) {
SUCCESS:
            pAiControl->dwAiParam[0] = 1;
            nState = 1;
            goto RESTORE_TARGET;
        }
        else {
            AITHINK_RemoveGroundCollision(pGame, pUnit);
            int nX = CLIENTS_GetUnitXInline_005F3170(pUnit);
            int nY = CLIENTS_GetUnitYInline_005F3170(pUnit);
            if (pAiControl->dwAiParam[1] && pAiControl->dwAiParam[2] && (unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2]) > 1) {
                D2CoordStrc tCoord;
                tCoord.nX = pAiControl->dwAiParam[1]; tCoord.nY = pAiControl->dwAiParam[2];
                if (pTarget && COLLISION_GetFreeCoordinates(UNITS_GetRoom(pTarget), &tCoord, UNITS_GetUnitSizeX(pUnit), 0xFFFF, 1)) {
                    pAiControl->dwAiParam[1] = tCoord.nX; pAiControl->dwAiParam[2] = tCoord.nY;
                }
                else if (COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0xFFFF, 1)) {
                    pAiControl->dwAiParam[1] = tCoord.nX; pAiControl->dwAiParam[2] = tCoord.nY;
                }
                --pAiControl->dwAiParam[0];
                AITACTICS_SetVelocity(pUnit, 7, 0, 0);
                AITACTICS_ChangeModeAndTargetCoordinatesOneStep(pGame, pUnit, pAiControl->dwAiParam[1], pAiControl->dwAiParam[2], 8);
                AITACTICS_Idle(pGame, pUnit, 12);
                return;
            }
            int nRadius = nState + 8;
            int nTargetX = CLIENTS_GetUnitXInline_005F3170(pTarget);
            int nMoveX = nTargetX - nRadius + ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRadius);
            int nTargetY = CLIENTS_GetUnitYInline_005F3170(pTarget);
            int nMoveY = nTargetY - nRadius + ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRadius);
            int nThreshold = nRadius << 1;
            if (nThreshold < 12) nThreshold = 12;
            else if (nThreshold > 36) nThreshold = 36;
            while ((int)AIUTIL_GetDistanceToCoordinates(pUnit, nMoveX, nMoveY) < nThreshold) {
                if (nMoveX < nX) --nMoveX; else if (nMoveX > nX) ++nMoveX;
                if (nMoveY < nY) --nMoveY; else if (nMoveY > nY) ++nMoveY;
                if (nMoveX == nX && nMoveY == nY) { ++nMoveX; ++nMoveY; }
            }
            pAiControl->dwAiParam[1] = nMoveX; pAiControl->dwAiParam[2] = nMoveY;
            AITACTICS_SetVelocity(pUnit, 1, 0, 0);
            AITACTICS_ChangeModeAndTargetCoordinatesOneStep(pGame, pUnit, nMoveX, nMoveY, 8);
            AITACTICS_Idle(pGame, pUnit, 12);
            --pAiControl->dwAiParam[0];
            return;
        }
    }
    else if (nState >= 1) {
RESTORE_TARGET:
        if (AITHINK_TryRestoreGroundCollision(pGame, pUnit)) {
            sub_005DE4E0_MoveAwayFromTarget(pGame, pUnit, pTarget, 9, 2, 3);
            AITACTICS_Idle(pGame, pUnit, 12);
            pAiControl->dwAiParam[0] = -1;
            return;
        }
        pAiControl->dwAiParam[0] = 8;
        AITACTICS_Idle(pGame, pUnit, 12);
    }
    if (bCombat) {
        if ((int)((unsigned int)SEED_RollRandomNumber(pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0)) AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        else AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
        return;
    }
    if (nState != -1) {
        const int nDifficulty = pGame->nDifficulty;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) >= pMonStatsTxt->wAiParam[4][nDifficulty]) {
            AITACTICS_Idle(pGame, pUnit, pMonStatsTxt->wAiParam[1][nDifficulty]);
            return;
        }
    }
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 3)) AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 0);
    else D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 9, 0);
    pAiControl->dwAiParam[0] = 0;
    AITACTICS_Idle(pGame, pUnit, 12);
}

static inline int UNITS_GetUnitXInline(D2UnitStrc* pUnit)
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

static inline int UNITS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005F39B0
void __fastcall AITHINK_Fn025_Willowisp(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    int nApproachOffsets[7][4][2] =
    {
        { { -10, -3 }, { 1, -5 }, { 6, 0 }, { 4, 10 } },
        { { -9, -2 }, { -6, -11 }, { -2, -5 }, { 6, 1 } },
        { { 0, 13 }, { -12, 0 }, { 7, 5 }, { -3, -11 } },
        { { -15, -3 }, { -6, -3 }, { -4, -5 }, { -6, -13 } },
        { { -12, -2 }, { -6, 2 }, { -5, 5 }, { 1, 11 } },
        { { -13, -6 }, { -8, -11 }, { -7, 0 }, { 1, 8 } },
        { { -5, -8 }, { -8, 1 }, { 1, -6 }, { 6, 9 } },
    };
    int nCastOffsets[7][4][2] =
    {
        { { 1, -5 }, { 6, 0 }, { 4, 10 }, { -10, -3 } },
        { { 1, 8 }, { -9, -2 }, { -5, 4 }, { 1, 8 } },
        { { -12, 0 }, { 7, 5 }, { -3, -11 }, { 11, -2 } },
        { { 7, 9 }, { -15, -3 }, { -6, -13 }, { 9, 7 } },
        { { -5, -7 }, { -5, -7 }, { 9, 0 }, { -12, -2 } },
        { { -8, -11 }, { -2, -6 }, { -2, -6 }, { -13, -6 } },
        { { -8, 1 }, { 1, -6 }, { 6, 9 }, { 0, 0 } },
    };
    int nCircleApproachOffsets[5][2] = { { -5, -5 }, { 3, -5 }, { 6, 3 }, { 3, 6 }, { -5, 3 } };
    int nCircleCastOffsets[5][2] = { { 6, 3 }, { 3, 6 }, { -5, 3 }, { -5, -5 }, { 3, -5 } };

    if (pTarget && pGame->dwGameFrame > pAiControl->dwAiParam[2] && AITHINK_GetSquaredDistance(pUnit, pTarget) < 1024
        && pAiControl->dwAiParam[0] < 4 && (int)SEED_RollLimitedRandomNumber(pSeed, 1000) <= pGame->nDifficulty + 2)
    {
        pAiControl->dwAiParam[0] = 4;
    }

    if (pAiControl->dwAiParam[0] == 4)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nX = UNITS_GetUnitXInline(pUnit);
        const int nY = UNITS_GetUnitYInline(pUnit);

        D2UnitFindArgStrc unitFindArg;
        memset(&unitFindArg, 0, sizeof(unitFindArg));
        unitFindArg.nX = nX;
        unitFindArg.nY = nY;
        unitFindArg.nFlags = 0x583;
        unitFindArg.nSize = 32;

        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, 32, AITHINK_UnitFindCallback_Willowisp, &unitFindArg);
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        if (unitFindData.nIndex == 4)
        {
            for (int i = 0; i < 4; ++i)
            {
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 1, 6);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 2, 0);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 3, i + 1);
                AITACTICS_IdleInNeutralMode(pGame, unitFindData.pUnitsArray[i], 337 - pGame->dwGameFrame % 337);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return;
        }

        if (unitFindData.nIndex == 5)
        {
            for (int i = 0; i < 5; ++i)
            {
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 1, 5);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 2, 0);
                AIGENERAL_SetAiControlParam(unitFindData.pUnitsArray[i], 3, i + 1);
                AITACTICS_IdleInNeutralMode(pGame, unitFindData.pUnitsArray[i], 337 - pGame->dwGameFrame % 337);
            }

            AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
        UNITFINDS_FreeUnitFindData(&unitFindData);
        return;
    }

    if (pAiControl->dwAiParam[0] >= 6)
    {
        if (pAiControl->dwAiParam[2] > 4)
        {
            pAiControl->dwAiParam[0] = 2;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pTarget) + nApproachOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0];
        const int nY = CLIENTS_GetUnitY(pTarget) + nApproachOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1];
        if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, nX, nY) > 3)
        {
            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 34)
            {
                AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
                return;
            }

            AITACTICS_ChangeModeAndTargetCoordinatesNoStep(pGame, pUnit, nX, nY, 2);
            return;
        }

        if (pGame->dwGameFrame % 67)
        {
            goto lIdleS6Test;
        }

        if (pAiControl->dwAiParam[1] < 3)
        {
            if (!nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0] && !nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1])
            {
                ++pAiControl->dwAiParam[1];
                goto lIdleS6Zero;
            }

            const int nCastX = CLIENTS_GetUnitX(pTarget) + nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][0];
            const int nCastY = CLIENTS_GetUnitY(pTarget) + nCastOffsets[pAiControl->dwAiParam[0] - 6][pAiControl->dwAiParam[2] - 1][1];
            AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 7, nCastX, nCastY);
            ++pAiControl->dwAiParam[1];
            return;
        }

        ++pAiControl->dwAiParam[0];
        pAiControl->dwAiParam[1] = 0;
        if (pAiControl->dwAiParam[0] - 6 > 6)
        {
            pAiControl->dwAiParam[0] = 2;
            pAiControl->dwAiParam[2] = pGame->dwGameFrame + 1800;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);

        if (pTarget && pTarget->dwUnitType == UNIT_PLAYER && !SUNIT_IsDead(pTarget))
        {
            const int nExpireFrame = pGame->dwGameFrame + 1728000;
            D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
            if (pStatList)
            {
                STATLIST_SetStatIfListIsValid(pStatList, STAT_ITEM_MAGICBONUS, 50 * (pGame->nDifficulty + 1), 0);
                STATLIST_SetListExpireFrame(pStatList, nExpireFrame);
                EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
                D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
            }
        }
        return;
    }

    if (pAiControl->dwAiParam[0] == 5)
    {
        if (pAiControl->dwAiParam[2] > 5)
        {
            pAiControl->dwAiParam[0] = 2;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }

        {
            const int nX = nCircleApproachOffsets[pAiControl->dwAiParam[2] - 1][0] + CLIENTS_GetUnitX(pTarget);
            const int nY = nCircleApproachOffsets[pAiControl->dwAiParam[2] - 1][1] + CLIENTS_GetUnitY(pTarget);
            if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, nX, nY) > 3)
            {
                if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 34)
                {
                    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
                    return;
                }

                AITACTICS_ChangeModeAndTargetCoordinatesNoStep(pGame, pUnit, nX, nY, 2);
                return;
            }
        }

        if (pGame->dwGameFrame % 67)
        {
            goto lIdleS5Test;
        }

        if (pAiControl->dwAiParam[1] < 3)
        {
            if (!nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][0] && !nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][1])
            {
                ++pAiControl->dwAiParam[1];
                goto lIdleS5Zero;
            }

            {
                const int nCastX = CLIENTS_GetUnitX(pTarget) + nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][0];
                const int nCastY = CLIENTS_GetUnitY(pTarget) + nCircleCastOffsets[pAiControl->dwAiParam[2] - 1][1];
                AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 7, nCastX, nCastY);
            }
            ++pAiControl->dwAiParam[1];
            return;
        }

        pAiControl->dwAiParam[0] = 2;
        pAiControl->dwAiParam[2] = pGame->dwGameFrame + 1800;
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
        return;

lIdleS6Test:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS6Zero:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS5Test:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 67 - pGame->dwGameFrame % 67);
        return;
lIdleS5Zero:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 337 - pGame->dwGameFrame % 337);
        return;
    }

    if (pAiControl->dwAiParam[0] == 1)
    {
        if (pAiControl->dwAiParam[1] <= 0)
        {
            if (bCombat)
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, 0);
                pAiControl->dwAiParam[0] = 3;
                return;
            }

            if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 8, 0);
                pAiControl->dwAiParam[0] = 2;
                return;
            }
        }

        --pAiControl->dwAiParam[1];
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
        {
            pAiControl->dwAiParam[0] = 1;
            AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
            return;
        }

        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 6);
        return;
    }

    if (!bCombat && (pAiControl->dwAiParam[0] == 2 || (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 0)))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 7, pTarget);
        pAiControl->dwAiParam[0] = 0;
        return;
    }

    if (bCombat && (pAiControl->dwAiParam[0] == 3 || (int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 1)))
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        pAiControl->dwAiParam[0] = 0;
        return;
    }

    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < AI_PARAM(pGame, pMonStatsTxt, 2))
    {
        pAiControl->dwAiParam[0] = 1;
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        pAiControl->dwAiParam[1] = 3;
        return;
    }

    pAiControl->dwAiParam[0] = 1;
    AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
    pAiControl->dwAiParam[1] = 3;
}

// 0x005F56D0
void __fastcall AITHINK_Fn033_HellMeteor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pMonStatsTxt->nSkill[0] >= 0 && (int)((unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) % 100) < AI_PARAM(pGame, pMonStatsTxt, 0))
    {
        const int nX = UNITS_GetUnitXInline(pUnit) + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 2)) - AI_PARAM(pGame, pMonStatsTxt, 2);
        const int nY = UNITS_GetUnitYInline(pUnit) + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * AI_PARAM(pGame, pMonStatsTxt, 2)) - AI_PARAM(pGame, pMonStatsTxt, 2);
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], 0, nX, nY);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 1));
}

static __forceinline int RollPercentage(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed % 100;
}

// 0x005F53E0
void __fastcall AITHINK_Fn030_Fetish(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    D2SeedStrc* const pUnitSeed = &pUnit->pSeed;
    const int nTargetDistance = pTick->nTargetDistance;
    const int bCombat = pTick->bCombat;
    D2UnitStrc* pTarget = pTick->pTarget;
    D2MonStatsTxt* pRecord = pTick->pMonstatsTxt;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2AiCmdStrc* pCmd = AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    if (pCmd)
    {
        if (pCmd->nCmdParam[0] == 1)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                AITACTICS_SetAiParam(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        if (pCmd->nCmdParam[0] == 14)
        {
            D2UnitStrc* pCommandTarget = SUNIT_GetServerUnit(pGame, pCmd->nCmdParam[2], pCmd->nCmdParam[1]);
            if (pCommandTarget)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
                AITACTICS_SetAiParam(pUnit, 13, 50, 0);
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pCommandTarget, 0);
                AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
                return;
            }
        }
        AIGENERAL_FreeCurrentAiCommand(pGame, pUnit);
    }
    const int nLife = UNITS_GetCurrentLifePercentage(pTarget);
    switch (pAi->dwAiParam[0])
    {
    case 2:
        if (nTargetDistance > 12)
        {
            ++pAi->dwAiParam[1];
            if (pAi->dwAiParam[1] > 1)
            {
                pAi->dwAiParam[0] = 0;
                pAi->dwAiParam[1] = 0;
            }
            if (RollPercentage(pUnitSeed) < 20)
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        AITACTICS_SetAiParam(pUnit, 2, 50, 0);
        if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 14, 1))
            return;
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        break;
    case 1:
        ++pAi->dwAiParam[1];
        if (pAi->dwAiParam[1] > AI_GetParam(pGame, pRecord, 2) && nLife > AI_GetParam(pGame, pRecord, 3))
        {
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = 0;
            AITACTICS_SetAiParam(pUnit, 2, 50, 0);
            AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 14, 1);
            return;
        }
        if (bCombat)
        {
            if ((int)SEED_RollLimitedRandomNumber(pUnitSeed, 100) < pRecord->wAiParam[0][pGame->nDifficulty])
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
            else
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pRecord->wAiParam[1][pGame->nDifficulty]);
            return;
        }
        AITACTICS_SetAiParam(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    case 0:
        if (bCombat)
        {
            pAi->dwAiParam[1] = 0;
            pAi->dwAiParam[0] = 1;
            if (RollPercentage(pUnitSeed) < AI_GetParam(pGame, pRecord, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_GetParam(pGame, pRecord, 1));
                return;
            }
        }
        AITACTICS_SetAiParam(pUnit, 13, 50, 0);
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

static int AI_RollSeedPercentage(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

// 0x005F5830
void __fastcall AITHINK_Fn034_Andariel(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (pAiTickParam->bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && AI_RollSeedPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    if (AI_RollSeedPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }

    if (AI_RollSeedPercentage(pSeed) < AI_GetParam(pGame, pMonStatsTxt, 2))
    {
        if (pMonStatsTxt->nSkill[0] >= 0)
        {
            const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (nRoll < AI_GetParam(pGame, pMonStatsTxt, 3))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
                return;
            }
        }

        if (pMonStatsTxt->nSkill[1] >= 0)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }
    }

    AITACTICS_SetAiParam(pUnit, 1, 0, 0);
    AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
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

// 0x005F6340
void __fastcall AITHINK_Fn039_PinHead(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    if (pAiTickParam->bCombat)
    {
        if (pAiControl->dwAiParam[0] && !((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PINHEAD_AI_PARAM_ATTACK_CHANCE_PCT)))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PINHEAD_AI_PARAM_ATTACK_STALL_DURATION));
            return;
        }

        pAiControl->dwAiParam[0] = 1;

        if (pMonStatsTxt->nSkill[0] >= 0 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PINHEAD_AI_PARAM_SMITE_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && (int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PINHEAD_AI_PARAM_SKILL2_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pTarget, 0, 0);
            return;
        }

        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        return;
    }

    pAiControl->dwAiParam[0] = 0;

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, PINHEAD_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, PINHEAD_AI_PARAM_IDLE_STALL_DURATION));
}

enum D2C_J07AiConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 0xE,
    MONSTATSFLAGINDEX_BYTE1_BIT0 = 0,
    MONSTATSFLAGINDEX_BYTE1_BIT7 = 7,
};

struct D2StatesTxt;

static inline int CLIENTS_GetUnitX_005F0A20(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitY_005F0A20(D2UnitStrc* pUnit)
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

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005F8010
D2UnitStrc* __fastcall AITHINK_GetTargetForUberMinion(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = 0;
    D2TargetNodeStrc** ppNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pNode = *ppNode;
    const int nX = CLIENTS_GetUnitX_005F0A20(pUnit);
    const int nY = CLIENTS_GetUnitY_005F0A20(pUnit);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    for (int i = 0; i < 8; ++i)
    {
        if (pNode)
        {
            D2UnitStrc* pPlayer = pNode->hUnit;
            if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer)) == nLevelId
                && !SUNIT_IsDead(pPlayer)
                && (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pPlayer, nX, nY) < 1020)
            {
                D2_ASSERT(pPlayer && pPlayer->dwUnitType == UNIT_PLAYER, 5117);
                const int nClassChance[7] = { 35, 40, 30, 20, 0, 25, 10 };
                const int nClass = pPlayer->dwClassId;
                const unsigned int nRoll = ITEMS_RollRandomNumber(&pUnit->pSeed);
                if (nClassChance[nClass] + (int)(nRoll % 20) > -1)
                {
                    pTarget = pPlayer;
                }
            }
        }
        pNode = *++ppNode;
    }
    return pTarget;
}

static inline int CLIENTS_GetUnitX_FrogDemon(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitY_FrogDemon(D2UnitStrc* pUnit)
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

// 0x005F8260
void __fastcall AITHINK_Fn052_FrogDemon(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;

    if (pAiControl->dwAiParam[2] == 0)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance > 12)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pAiTickParam->pTarget, 0, 0);
            AITACTICS_Idle(pGame, pUnit, 8);
            pAiControl->dwAiParam[2] = 1;
            AITHINK_RemoveGroundCollision(pGame, pUnit);
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            goto Emerge;
        }

        if (!COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX_FrogDemon(pUnit), CLIENTS_GetUnitY_FrogDemon(pUnit), 0xC01))
        {
            pAiControl->dwAiParam[2] = 2;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 12);
        return;
    }

    if (pAiControl->dwAiParam[2] == 1)
    {
        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 7) && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        if (pMonStatsTxt->nSkill[1] >= 0 && nTargetDistance < 20 && pAiControl->dwAiParam[1] > 64 && AITHINK_TryRestoreGroundCollision(pGame, pUnit))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
            pAiControl->dwAiParam[2] = 2;
            return;
        }

        AITHINK_RemoveGroundCollision(pGame, pUnit);
        AITACTICS_Idle(pGame, pUnit, 24);
        ++pAiControl->dwAiParam[1];
        pAiControl->dwAiParam[2] = 1;
        return;

Emerge:
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], pUnit, 0, 0);
        pAiControl->dwAiParam[2] = 2;
        return;
    }

    {
        if (!pTarget)
        {
            AITACTICS_Idle(pGame, pUnit, 32);
            return;
        }

        if (bCombat)
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 1))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 0))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 2))
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (nTargetDistance < AI_GetParam(pGame, pMonStatsTxt, 5))
        {
            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 4))
            {
                AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
            {
                AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
                return;
            }

            AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 6));
            return;
        }

        if (AI_RollChance(pGame, pSeed, pMonStatsTxt, 3))
        {
            AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 3, 0);
            return;
        }

        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, 4);
        return;
    }
}

static inline int AI_GetUnitX(D2UnitStrc* pUnit)
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

static inline int AI_GetUnitY(D2UnitStrc* pUnit)
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

// 0x005F89B0
void __fastcall AITHINK_Fn055_Izual(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nX = AI_GetUnitX(pTarget);
    const int nY = AI_GetUnitY(pTarget);

    if (!pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        ACT4Q1_OnIzualActivated(pGame);
    }

    if (pAiControl->dwAiParam[1])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiControl->dwAiParam[1]);
        pAiControl->dwAiParam[1] = 0;
        return;
    }

    if (!bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < 10)
        {
            if (pAiControl->dwAiParam[2] > 0)
            {
                AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
                return;
            }

            if (AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT))
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
                pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS);
                pAiControl->dwAiParam[2] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_NUM_SWINGS);
                return;
            }
        }

        if (pAiControl->dwAiParam[2] <= 0 && (int)(ITEMS_RollRandomNumber(pSeed) % 100) >= AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT))
        {
            if (nTargetDistance > 10)
            {
                D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 6, 9);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAIdel[pGame->nDifficulty]);
            }
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pAiControl->dwAiParam[2] <= 0 && (int)(ITEMS_RollRandomNumber(pSeed) % 100) >= AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        pAiControl->dwAiParam[2] = 0;
        if (pMonStatsTxt->nSkill[0] < 0 || !AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_NOVA_IN_MELEE_CHANCE_PCT))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAIdel[pGame->nDifficulty]);
        }
        else
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
            pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS);
            pAiControl->dwAiParam[2] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_NUM_SWINGS);
        }
        return;
    }

    if (pAiControl->dwAiParam[2] > 0)
    {
        --pAiControl->dwAiParam[2];
    }

    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
}

// 0x005F8C80
void __fastcall AITHINK_Fn144_UberIzual(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nX = AI_GetUnitX(pTarget);
    const int nY = AI_GetUnitY(pTarget);

    if (pMonStatsTxt->nSkill[1] >= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(pMonStatsTxt->nSkill[1]);
        if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[1], pMonStatsTxt->nSkill[1], 0, 0, 0);
            return;
        }
    }

    if (UNITS_TestCollisionWithUnit(pUnit, pTarget, COLLIDE_MASK_BARRIER))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[2], pMonStatsTxt->nSkill[2], 0, nX, nY);
        return;
    }

    if (pAiControl->dwAiParam[1])
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiControl->dwAiParam[1]);
        pAiControl->dwAiParam[1] = 0;
        return;
    }

    if (!bCombat)
    {
        if (pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < 10 && pAiControl->dwAiParam[2] <= 0 && AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_NOVA_AT_RANGE_CHANCE_PCT))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
            pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS);
            pAiControl->dwAiParam[2] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_NUM_SWINGS);
            return;
        }

        if (pAiControl->dwAiParam[2] <= 0 && !AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_ENGAGE_CHANCE_PCT))
        {
            if (nTargetDistance > 10)
            {
                D2GAME_AICORE_Escape_6FCD0560(pGame, pUnit, pTarget, 6, 9);
            }
            else
            {
                AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAIdel[pGame->nDifficulty]);
            }
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (pAiControl->dwAiParam[2] <= 0 && !AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_ATTACK_CHANCE_PCT))
    {
        pAiControl->dwAiParam[2] = 0;
        if (pMonStatsTxt->nSkill[0] < 0 || !AI_RollChance(pGame, pSeed, pMonStatsTxt, IZUAL_AI_PARAM_NOVA_IN_MELEE_CHANCE_PCT))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->nAIdel[pGame->nDifficulty]);
        }
        else
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, nX, nY);
            pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_POST_NOVA_DOLDRUMS);
            pAiControl->dwAiParam[2] = AI_GetParam(pGame, pMonStatsTxt, IZUAL_AI_PARAM_NUM_SWINGS);
        }
        return;
    }

    if (pAiControl->dwAiParam[2] > 0)
    {
        --pAiControl->dwAiParam[2];
    }

    AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
}

static int AI_RollPercentage_005F9490(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed % 100;
}

static inline int ABS_VALUE(int n) { return n < 0 ? -n : n; }

// 0x005F9490
void __fastcall AITHINK_Fn063_GargoyleTrap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (pAiControl->dwAiParam[0] > 0)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, pAiControl->dwAiParam[0]);
        pAiControl->dwAiParam[0] = 0;
        return;
    }
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    const int nTargetX = CLIENTS_GetUnitXInline(pTarget);
    const int nTargetY = CLIENTS_GetUnitYInline(pTarget);
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    int nX = nTargetX;
    int nY = nTargetY;
    if (ABS_VALUE(nTargetX - nUnitX) < ABS_VALUE(nTargetY - nUnitY))
    {
        nX = nUnitX;
    }
    else
    {
        nY = nUnitY;
    }
    const unsigned char nDirection = UNITS_GetDirectionToCoords(pUnit, nX, nY);
    sub_006488A0_SetDirection(pUnit->pDynamicPath, gnGargoyleTrapDirectionAxis[gnGargoyleTrapDirectionMap[nDirection]]);
    if ((ABS_VALUE(nTargetX - nUnitX) < 6 || ABS_VALUE(nTargetY - nUnitY) < 6)
        && pMonStatsTxt->nSkill[0] >= 0 && nTargetDistance < AI_PARAM(pGame, pMonStatsTxt, 0) && AI_RollPercentage_005F9490(pUnit) < AI_PARAM(pGame, pMonStatsTxt, 1))
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        pAiControl->dwAiParam[0] = AI_PARAM(pGame, pMonStatsTxt, 2);
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, 3));
}

static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_TYPES_COUNT;
    }
    return pUnit->dwUnitType;
}

// 0x005F9A80
void __fastcall AITHINK_Fn065_FetishShaman(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    int nSkillLevel;
    D2SkillStrc* pSkill;

    if (pMonStatsTxt->nSkill[0] < 0
        || !(pSkill = SKILLS_GetSkillById(pUnit, pMonStatsTxt->nSkill[0], -1))
        || (nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1)) <= 0)
    {
        nSkillLevel = 1;
    }

    if (pMonStatsTxt->nSkill[0] >= 0 && nDistance < nSkillLevel && !STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        aiCmd.nCmdParam[1] = sub_00451F50(pTarget);
        aiCmd.nCmdParam[2] = sub_0044BE50(pTarget);
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], pMonStatsTxt->nSkill[0], pTarget, 0, 0);
        return;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    D2FetishShamanAiCallbackArgStrc arg;
    arg.pClosestDeadTarget = 0;
    arg.nSquaredDistanceToClosestDeadTarget = 0x7FFFFFFF;
    arg.nMaxSearchRangeSquared = AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE) * AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_SEARCH_RANGE);
    arg.pClosestAliveTarget = 0;
    arg.nSquaredDistanceToClosestAliveTarget = 0x7FFFFFFF;
    arg.nAliveTargets = 0;
    arg.nHealCapability = AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_CAPABILITY);
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, AITHINK_TargetCallback_FetishShaman, 1);

    D2UnitStrc* pDeadTarget = arg.pClosestDeadTarget;
    if (pDeadTarget && (int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_CHANCE_PCT)
        && sub_005FD470(pGame, pUnit, pMonStatsTxt->nSkill[2], arg.pClosestDeadTarget, 0, 0))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 14;
        aiCmd.nCmdParam[1] = pDeadTarget->dwUnitId;
        aiCmd.nCmdParam[2] = 1;
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);

        if (arg.nSquaredDistanceToClosestDeadTarget > AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_HEAL_RANGE))
        {
            D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pDeadTarget, 10);
        }
        else
        {
            AITACTICS_UseSequenceSkill(pGame, pUnit, pMonStatsTxt->nSkill[2], pDeadTarget, 0, 0);
        }
        return;
    }

    if ((int)(AI_RollUnit(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, FETISHSHAMAN_AI_PARAM_CIRCLE_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 4, 0);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
    }
}

// 0x005FA710
void __fastcall AITHINK_Fn071_Regurgitator(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    D2MonStatsTxt* pMonStats = pAiTickParam->pMonstatsTxt;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    D2UnitStrc* pCorpse;
    D2AiControlStrc* pAi = pAiTickParam->pAiControl;
    if (pAi->dwAiParam[0] == 5)
    {
        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 16, 1);
        pAi->dwAiParam[0] = 0;
        return;
    }
    if (pAi->dwAiParam[0] == 2)
    {
        pCorpse = SUNIT_GetServerUnit(pGame, 1, pAi->dwAiParam[1]);
        if (pCorpse && pCorpse->dwAnimMode == 12)
        {
            if (AITHINK_GetSquaredDistance(pUnit, pCorpse) > 4)
            {
                if (pAi->dwAiParam[2] < 6)
                {
                    AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
                    ++pAi->dwAiParam[2];
                }
                else
                {
                    pAi->dwAiParam[0] = 0;
                    pAi->dwAiParam[1] = 0;
                    pAi->dwAiParam[2] = 0;
                    AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
                    return;
                }
            }
            pAi->dwAiParam[0] = 3;
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            return;
        }
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        pAi->dwAiParam[2] = 0;
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }
    if (pAi->dwAiParam[0] == 3)
    {
        pCorpse = SUNIT_GetServerUnit(pGame, 1, pAi->dwAiParam[1]);
        if (pMonStats->nSkill[0] >= 0 && pCorpse && pCorpse->dwAnimMode == 12)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStats->nSkillMode[0], pMonStats->nSkill[0], pCorpse, 0, 0);
            pAi->dwAiParam[0] = 4;
            return;
        }
        pAi->dwAiParam[0] = 0;
        pAi->dwAiParam[1] = 0;
        pAi->dwAiParam[2] = 0;
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }
    if (pAi->dwAiParam[0] == 4)
    {
        if (!bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
            pAi->dwAiParam[0] = 5;
            return;
        }
        AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, 8, 1);
        return;
    }
    D2RegurgitatorAiCallbackArgStrc args;
    args.pTarget = 0;
    const int nDistance = AI_PARAM(pGame, pMonStats, 5);
    args.nDistance = nDistance * nDistance;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &args, AITHINK_TargetCallback_Regurgitator, 1);
    pCorpse = args.pTarget;
    if (pAi->dwAiParam[0] == 1)
    {
        if (pCorpse)
        {
            pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
            if (AITHINK_GetSquaredDistance(pUnit, pCorpse) > 2)
            {
                AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
                pAi->dwAiParam[0] = 2;
                pAi->dwAiParam[2] = 0;
                return;
            }
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
            pAi->dwAiParam[0] = 3;
            pAi->dwAiParam[2] = 0;
            return;
        }
        if (ROLL() < 20)
        {
            pAi->dwAiParam[0] = 0;
            pAi->dwAiParam[1] = 0;
            pAi->dwAiParam[2] = 0;
            return;
        }
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 8);
        return;
    }
    if (pCorpse)
    {
        if (AITHINK_GetSquaredDistance(pUnit, pCorpse) < 9 && ROLL() < AI_PARAM(pGame, pMonStats, 1))
        {
            AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
            pAi->dwAiParam[2] = 0;
            return;
        }
        if (ROLL() < AI_PARAM(pGame, pMonStats, 4))
        {
            AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
            pAi->dwAiParam[0] = 2;
            pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
            pAi->dwAiParam[2] = 0;
            return;
        }
    }
    int nRoll = ROLL();
    int nDifficulty = pGame->nDifficulty;
    if (bCombat)
    {
        if (nRoll < pMonStats->wAiParam[0][nDifficulty]) AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        else AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
        return;
    }
    if (nRoll < pMonStats->wAiParam[2][nDifficulty])
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 0);
        return;
    }
    if (pCorpse && ROLL() < AI_PARAM(pGame, pMonStats, 3))
    {
        AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pCorpse, 1);
        pAi->dwAiParam[0] = 2;
        pAi->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
        pAi->dwAiParam[2] = 0;
        return;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 8);
}

struct D2SuperUniquesTxt;

inline int UNITS_GetUnitGUID_005FB2A0(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x005FB2A0
void __fastcall AITHINK_Fn075_QuillMother(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    const int bCombat = pAiTickParam->bCombat;
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (AIUTIL_IsGettingHit(pUnit))
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 1;
        int nType = UNIT_TYPES_COUNT;
        if (pTarget)
        {
            nType = pTarget->dwUnitType;
        }
        aiCmd.nCmdParam[1] = nType;
        aiCmd.nCmdParam[2] = UNITS_GetUnitGUID_005FB2A0(pTarget);
        AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);

        if (bCombat)
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    if (bCombat)
    {
        if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, QUILLMOTHER_AI_PARAM_ATTACK_CHANCE_PCT))
        {
            AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
            return;
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, QUILLMOTHER_AI_PARAM_MELEE_STALL_DURATION));
        return;
    }

    if ((int)(AI_RollUnitSeed(pUnit) % 100) < AI_PARAM(pGame, pMonStatsTxt, QUILLMOTHER_AI_PARAM_APPROACH_CHANCE_PCT))
    {
        AITACTICS_WalkToTargetUnitWithFlags(pGame, pUnit, pTarget, 7);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxt, QUILLMOTHER_AI_PARAM_IDLE_STALL_DURATION));
}

static int UNITS_GetAnimMode_FB410(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005FB410
void __fastcall AITHINK_Fn076_EvilHole(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nMode = UNITS_GetAnimMode_FB410(pUnit);

    if (pAiControl->dwAiParam[0] <= 0)
    {
        pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;
        pAiControl->dwAiParam[1] = AI_GetParam(pGame, pMonStatsTxt, 0);
    }

    if (nMode == 1)
    {
        if (nDistance > 5)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 10, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 10)
    {
        AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 11, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 20);
        return;
    }

    if (nMode == 11 && pAiControl->dwAiParam[1] > 0)
    {
        if (pGame->dwGameFrame > pAiControl->dwAiParam[0])
        {
            pAiControl->dwAiParam[0] = AI_GetParam(pGame, pMonStatsTxt, 1) + pGame->dwGameFrame;

            int nMonsterId;
            int nX;
            int nY;
            int nAnimMode;
            MONSTERS_GetMinionSpawnInfo(pUnit, &nMonsterId, &nX, &nY, &nAnimMode, 0, 0);

            D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
            if (pRoom)
            {
                D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, 2, 0x42);
                if (pMonster)
                {
                    --pAiControl->dwAiParam[1];
                    pMonster->dwFlags |= 0x4020000;

                    if (pUnit && pUnit->dwClassId == 0x2C7)
                    {
                        STATES_ToggleState(pMonster, 0xB8, 1);
                        UNITS_SetOverlay(pMonster, 0xCA, 0);
                    }
                }
            }
        }

        AITACTICS_Idle(pGame, pUnit, AI_GetParam(pGame, pMonStatsTxt, 1));
        return;
    }

    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, 0, 0, 0);
}

static inline void AITHINK_DieInline(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }
    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
}

enum D2C_AiThink4_005FB5B0Constants
{
    TRAPMISSILE_AI_PARAM_DELAY = 2,
    TRAPMISSILE_AI_PARAM_DISTANCE = 0,
    TRAPMISSILE_AI_PARAM_NUM_TO_SHOOT = 1,
};

// 0x005FB5B0
void __fastcall AITHINK_Fn077_TrapMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    const int nTargetDistance = pAiTickParam->nTargetDistance;
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;

    if (!pTarget)
    {
        AITHINK_DieInline(pGame, pUnit);
        return;
    }

    if (nTargetDistance > pMonStatsTxt->wAiParam[TRAPMISSILE_AI_PARAM_DISTANCE][pGame->nDifficulty])
    {
        AITHINK_DieInline(pGame, pUnit);
        return;
    }

    if (pAiControl->dwAiParam[0] >= pMonStatsTxt->wAiParam[TRAPMISSILE_AI_PARAM_NUM_TO_SHOOT][pGame->nDifficulty])
    {
        AITHINK_DieInline(pGame, pUnit);
        return;
    }

    if (!pAiControl->dwAiParam[1])
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget);
        pAiControl->dwAiParam[0] += 1;
        pAiControl->dwAiParam[1] = 1;
        return;
    }

    pAiControl->dwAiParam[1] = 0;
    AITACTICS_IdleInNeutralMode(pGame, pUnit, pMonStatsTxt->wAiParam[TRAPMISSILE_AI_PARAM_DELAY][pGame->nDifficulty]);
}

// 0x005FB650
int __fastcall AITHINK_GetTrapArrowVariant(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, nLevelId);
    if (pMonsterRegion->nTrapVariant < 0)
    {
        if (nLevelId < LEVEL_AI_TRAPARROW_RANDOM)
        {
            pMonsterRegion->nTrapVariant = 0;
        }
        else
        {
            pMonsterRegion->nTrapVariant = OBJECTS_RollRandomNumber(&pUnit->pSeed, 0, 3);
        }
    }
    return pMonsterRegion->nTrapVariant;
}

#include "gen/data/Source/D2Game/Unknown_005EFB80.inc"
