#include "D2MissileIds.h"
#include "D2SkillIds.h"
#include "D2Game.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2GameAux.h"

struct MissileRecord;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2SkillsTxt;
struct MonsterData;
struct Skills;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit); // 0x0056DFA0
void __fastcall SKILLS_ClampVitalsAndUpdateAnimRate(D2UnitStrc* pUnit); // 0x0056B6C0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

struct Unit
{
    int type;
    int classId;
    char pad8[0xC];
    MonsterData* monster;
    char pad18[0xAC];
    unsigned int flags;
};
Unit* __stdcall sub_00553540(Game*, Unit*); // 0x00553540
void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(Game*, Unit*, Unit*); // 0x0057C9F0
int __fastcall SKILLS_GetMonFrenzySequenceFrame(Unit*); // 0x005CDD30
int __fastcall SKILLS_StartSkill(Game*, Unit*, int, int, int); // 0x0056F640
int __fastcall SKILLS_RollMonFrenzyDamage(Game*, Unit*, Unit*, int, int); // 0x005CDDD0
int __stdcall SKILLS_GetParam1(Skill*); // 0x006444A0
int __fastcall SKILLS_ApplyFrenzyStats(Game*, Unit*, int, int); // 0x005D8C70

enum { UNIT_FLAG = 0x40 };

struct MonsterData { char pad0[0xE]; unsigned char variant; };

struct Skills { char pad0[4]; unsigned char flags[4]; char pad8[0x40]; short missile; char pad4A[0x1F2]; };

struct Tables { char pad0[0xB6C]; int missileCount; char padB70[0x28]; Skills* skills; void* linker; int skillCount; };
extern unsigned bitMasks[]; // 0x006CE268
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
Unit* __fastcall SKILLS_CreateMissileFromOrigin(Game*,int,Unit*,int,int,int,int,int,int,int); // 0x0056EE90
Unit* __fastcall SKILLS_CreateMissileAtOffset(Game*,int,Unit*,int,int,int,int,int,int,int); // 0x0056ECB0


typedef char D2SkillsTxtSizeCheck[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char D2UnkNecSkillStrcSizeCheck[sizeof(D2UnkNecSkillStrc) == 0x68 ? 1 : -1];

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __fastcall SKILLS_IterateTargetsAroundTarget(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs); // 0x0056E780
int __fastcall sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs); // 0x005C35C0

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*, int, int); // 0x00463740
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc*); // 0x00620BB0
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char); // 0x0063E7A0
void __stdcall INVENTORY_GetDirectionDelta(unsigned char, int*, int*); // 0x0063E7E0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
unsigned char __stdcall PATH_GetNewDirection(D2DynamicPathStrc*); // 0x00648810
int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc*); // 0x006505C0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005CDF10
int __fastcall sub_005CDF10(Game* game, Unit* unit, int skillId, int skillLevel)
{
    Skill* skill = sub_00620250(unit);
    if (!skill) return 0;
    Unit* target = sub_00553540(game, unit);
    if (!target) return 0;
    SUNITDMG_FreeAttackerDefenderCombatList(game, unit, target);
    if (unit) unit->flags |= UNIT_FLAG;
    if (SKILLS_GetMonFrenzySequenceFrame(unit)) SKILLS_StartSkill(game, unit, skillId, skillLevel, 0);
    SKILLS_RollMonFrenzyDamage(game, unit, target, skillId, skillLevel);
    if (SKILLS_GetParam1(skill)) SKILLS_ApplyFrenzyStats(game, unit, skillId, skillLevel);
    return 1;
}

inline Skills* GetSkills(int id) { if(id>=0 && id<tables->skillCount) return &tables->skills[id]; return 0; }

__forceinline unsigned char GetVariant(Unit* unit)
{
    if(unit && unit->type==1 && unit->monster) return unit->monster->variant;
    return 0;
}

// 0x005CDFB0
int __fastcall sub_005CDFB0(Game* game,Unit* unit,int id,int level)
{
    Skills* record=GetSkills(id);
    if(!record) return 0;
    if(!sub_00553540(game,unit)) return 0;
    int missile=record->missile;
    if(missile<0 || missile>=tables->missileCount) return 0;
    missile+=GetVariant(unit);
    if(missile>=tables->missileCount) return 0;
    if(!sub_0046ACE0(missile)) return 0;
    if(unit) unit->flags|=UNIT_FLAG;
    if(record->flags[0]&bitMasks[1]) SKILLS_CreateMissileFromOrigin(game,missile,unit,id,level,0,0,0,0,0);
    else SKILLS_CreateMissileAtOffset(game,missile,unit,id,level,0,0,0,0,0); // 0x0056ECB0
    return 1;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

struct D2MissilesTxt;

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
