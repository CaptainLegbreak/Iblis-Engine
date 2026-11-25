#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2UnitData.h"
#include "D2LanguageNames.h"

#define UNITFLAG_SKSRVDOFUNC 0x40

#define AURAFILTER_DOUBLESWING 0x20003

#define TIMERQUEUE_CURSESTATE 1

#define LINE_WHIRLWIND_ANIMRATE 903

#define STAT_MODIFIERLIST_SKILL 350

#define STAT_MODIFIERLIST_LEVEL 351

#define STAT_SKILL_FRENZY 169

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

struct Obj00648690;

struct Obj006487D0;

union D2SeedStrc;

struct D2PathPointStrc;

struct D2SkillsTxt;

struct D2CurseStrc;

struct D2StaticPathStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2DamageStrc;

struct D2CoordStrc;

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50

int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* pUnit, int a2); // 0x005544B0

int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nState, int a3); // 0x0056C740

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

int __fastcall SKILLS_StartBasicAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0056E230

int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit); // 0x0056E5B0

D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

void __fastcall SUNITMSG_QueueSkillStop(D2UnitStrc* pUnit, int nSkillId); // 0x00571B70

void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

void __fastcall SKILLS_ApplyPassiveStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0

void __fastcall SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005D8EF0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int a3); // 0x00622C40

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nFlags); // 0x00644660

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

extern "C" void __stdcall PATH_SetVelocity(Obj00648690* pObj, int nValue, int nUnused3, int nUnused4); // 0x00648690

extern "C" unsigned int __stdcall PATH_GetPathPoints(Obj006487D0* pObj, unsigned int** ppOut); // 0x006487D0

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pPath, int nMask); // 0x00648CE0

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064EA90

int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill); // 0x00644530

D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc* pUnit); // 0x00535BC0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void __fastcall D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553DC0

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0

int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill); // 0x00644500

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pPath, int nMask); // 0x00648C30

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nFrame, int a5, int a6); // 0x005417D0

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

extern "C" void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, unsigned int dwValue); // 0x006252D0

extern "C" void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0

extern "C" void __stdcall STATLIST_SetListExpireFrame(D2StatListStrc* pStatList, int nValue); // 0x006260B0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall MONSTERMODE_AllocateTargetCombat(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x005A5490

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

static int __stdcall SKILLS_GetWhirlwindHitCount(D2GameStrc* pGame, D2SkillStrc* pSkill, D2UnitStrc* pUnit);

static int __stdcall SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY, int nSkillId);

static int __stdcall SKILLS_CanLeapToPosition(D2UnitStrc* pUnit, int nX, int nY, int nSkillId);

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit);

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit);

struct D2MonStatsTxtRun;

struct D2CharStatsTxtRun;

D2MonStatsTxtRun* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

D2CharStatsTxtRun* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClassId); // 0x004833E0

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nSkillId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps); // 0x00649070

static int __stdcall SKILLS_Leap(D2GameStrc* pGame, D2SkillStrc* pSkill, D2UnitStrc* pUnit);

static int __stdcall SKILLS_StartMonsterLeapAttack(D2GameStrc* pGame, D2UnitStrc* pTarget, D2SkillStrc* pSkill, D2UnitStrc* pUnit);

int __fastcall SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

#define SKILL_FLAG 0x40

#define TARGET_FILTER 0x20003

int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit);                                                             // 0x0056E510

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0

void __fastcall PLRMODE_HandleDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310

void __fastcall PLRMODE_BreakDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380

int __fastcall SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8C70

int __fastcall SKILLS_RollFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D8B10

static int __stdcall SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static int __stdcall SKILLS_ApplySandLeaperKnockback(D2GameStrc* pGame, int nX, int nY, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

struct D2ActiveRoomStrc;

struct D2SkillStrc;

int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY); // 0x00645CA0

void __fastcall SKILLS_StunMonster(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nDelay); // 0x00570420

int __fastcall SKILLS_CanUseWeaponAmmo(D2UnitStrc* pUnit); // 0x0056C4E0

void __fastcall sub_6FC7D260(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int a4);

int __fastcall SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

static D2UnitStrc* __stdcall SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static int __stdcall SKILLS_ApplyLeapAttackDamage(D2GameStrc* pGame, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit);

int __fastcall SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

#include "D2Constants.h"

enum D2C_U04BashConstants
{
    DAMAGERESULTFLAG_SUCCESSFULHIT = 1,
    STATLIST_FILTER_4 = 4,
};

D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget);               // 0x0057D690

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005D7EA0
int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    sub_6FD15470(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel));

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (pDamage)
    {
        pDamage->dwPhysDamage += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) << 8;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, STATLIST_FILTER_4, 0, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 1;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
    }

    STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);

    return 1;
}

// 0x005D80C0
int __fastcall SKILLS_SrvSt33_FindPotion_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nResult = D2COMMON_11018(pTarget);
    if (!nResult || !STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
    {
        return nResult;
    }

    return 0;
}

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
extern int gnPotionTableMax; // 0x00741B54
extern int gaPotionTable[][3]; // 0x00741B58

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005D8100
static int __stdcall SKILLS_GetFindItemPotion(D2UnitStrc* pUnit, D2GameStrc* pGame, int nSkillId)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (nAct < 0 || nAct >= 5)
    {
        return 0;
    }

    const int nIndex = nAct + 5 * pGame->nDifficulty;
    int nType = 0;
    const int nChance = SEED_RollRandomNumber(&pUnit->pSeed) % 100;

    const int nParam3 = SKILLDESC_GetSkillParamThree(nSkillId);
    if (nChance < nParam3)
    {
        nType = 1;
    }
    else if (nChance < nParam3 + SKILLDESC_GetSkillParamFour(nSkillId))
    {
        nType = 2;
    }

    if (nIndex > gnPotionTableMax)
    {
        return 0;
    }

    return gaPotionTable[nIndex][nType];
}

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x0056DAB0

static inline int SKILLS_IsUnlootedCorpse(D2UnitStrc* pTarget)
{
    return pTarget && D2COMMON_11018(pTarget) && !STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT);
}

// 0x005D81C0
int __fastcall SKILLS_SrvDo069_FindPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!SKILLS_IsUnlootedCorpse(pTarget))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 118, 1);
    UNITROOM_RefreshUnit(pTarget);

    const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
    {
        const int dwCode = SKILLS_GetFindItemPotion(pUnit, pGame, nSkillId);
        OBJMODE_DropItemWithCodeAndQuality(pGame, pTarget, dwCode, 2);
    }

    return 1;
}

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

// 0x005D8290
int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nExpireFrame = pGame->dwGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(a2, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(a2, pStatList, 1);
        STATES_ToggleState(a2, pSkillsTxtRecord->nAuraState, 1);
    }

    STATES_ToggleGfxStateFlag(a2, pSkillsTxtRecord->nAuraState, 1);
    D2COMMON_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, a2, 12, nExpireFrame, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    sub_6FD14C30(a2);
    return 1;
}

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0

void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400

int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290

// 0x005D83E0
int __fastcall SKILLS_SrvDo068_BasicShout(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    SKILLS_CreateMissileRing(pGame, pUnit, pUnit, nMissileId, nSkillId, nSkillLevel, 0);
    SKILLS_ApplyWarcryStats(pGame, pUnit, pUnit, nSkillId, nSkillLevel);
    return 1;
}

// 0x005D8470
int __fastcall SKILLS_SrvDo070_DoubleSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (((pUnit->dwSeqFrame >> 8) % 2) == 0)
    {
        SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(pGame, pUnit, nSkillId, nSkillLevel);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        return 1;
    }

    pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

    const int nAuraRange = sub_6FD15460(pUnit);
    const int nTargetGUID = pTarget->dwUnitId;
    pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nAuraRange, AURAFILTER_DOUBLESWING, nTargetGUID, 0);
    if (!pTarget)
    {
        return 0;
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);

    SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(pGame, pUnit, nSkillId, nSkillLevel);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    return 1;
}

int __fastcall SKILLS_CanSwitchAi(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0

void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090

// 0x005D8510
int __fastcall SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    if (!SKILLS_CanSwitchAi(pUnit, 12))
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    int nOwnerGUID;
    int nOwnerType;
    AIGENERAL_GetOwnerData(pUnit, &nOwnerGUID, &nOwnerType);

    if (nOwnerGUID != -1 && nOwnerType == 0)
    {
        return 0;
    }

    return 1;
}

void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                          // 0x005DD330
int __fastcall SKILLS_AuraCallback_ApplyCurse(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs); // 0x005C35C0
int __fastcall SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005D8510
D2UnitStrc* __fastcall SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAuraRange, int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*)); // 0x0056BBC0
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                    // 0x00554200
extern const unsigned int gdwBitMasks[32]; // 0x006CE268







// 0x005D8570
int __fastcall SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || !SKILLS_Callback_FindTargetForTaunt(pGame, pTarget) || !SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        pTarget = SKILLS_FindAuraTarget(pGame, pUnit, 20, SKILLS_Callback_FindTargetForTaunt);
    }

    if (!pTarget)
    {
        return 0;
    }

    const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);

    D2UnkNecSkillStrc curseData;
    memset(&curseData, 0, sizeof(curseData));
    curseData.pUnit = pUnit;
    curseData.nDuration = nDuration;
    curseData.pGame = pGame;
    curseData.bResetAi = 1;
    curseData.nSkillId = nSkillId;
    curseData.nSkillLevel = nSkillLevel;
    curseData.bUpdateAnimRate = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] < 0 || pSkillsTxtRecord->wAuraStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            curseData.nAuraStat[i] = -1;
            break;
        }

// build: symbol ?PLAYER_GetItemStatCostTxtRecord@* 0x0045C4F0
        D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pSkillsTxtRecord->wAuraStat[i]);
        if (!pItemStatCostTxtRecord)
        {
            break;
        }

        if (pItemStatCostTxtRecord->nItemStatFlags[9 >> 3] & gdwBitMasks[9 & 7])
        {
            curseData.bUpdateAnimRate = 1;
        }

        curseData.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        curseData.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
    }

    curseData.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    SKILLS_AuraCallback_ApplyCurse(pTarget, &curseData);

    D2AiControlStrc* pAiControl = (pTarget->dwUnitType == UNIT_MONSTER && pTarget->pMonsterData) ? pTarget->pMonsterData->pAiControl : 0;
    AITHINK_SetAiControlParams(pAiControl, -666, -666, -666);
    AIUTIL_SetOwnerGUIDAndType(pTarget, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 2, 0);
    EVENT_SetEvent(pGame, pTarget, 2, pGame->dwGameFrame + 1, 0, 0);
    UNITS_SetTargetUnitForDynamicUnit(pTarget, pUnit);
    return 1;
}

// 0x005D8760
int __fastcall SKILLS_SrvSt34_FindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2COMMON_11019(pTarget) != 0;
}

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall MONSTERMODE_DropTreasureForFindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nUnused); // 0x005A8000

// 0x005D8780
int __fastcall SKILLS_SrvDoStageRoll(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!D2COMMON_11019(pTarget))
    {
        return 0;
    }

    if (STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 0x76, 1);
    UNITROOM_RefreshUnit(pTarget);

    const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) >= nChance)
    {
        return 0;
    }

    const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
    int nStage = 1;
    int nLow = 0;
    int nHigh = 0;
    for (int i = 0; i < 4; ++i)
    {
        nHigh += pSkillsTxtRecord->dwParam[i];
        if (nRoll >= nLow && nRoll < nHigh)
        {
            nStage = i + 1;
        }
        nLow += pSkillsTxtRecord->dwParam[i];
    }

    MONSTERMODE_DropTreasureForFindItem(pGame, pTarget, pUnit, nStage);
    return 1;
}

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0

D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

// 0x005D88B0
int __fastcall SKILLS_SrvDo074_DoubleThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pItem = PLAYER_GetWeaponForSkill(pUnit);
    if (!pItem)
    {
        return 0;
    }

    const int nMissileId = ITEMS_GetMissileType(pItem);
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pMissile;
    if (ITEMSIsA(pItem, 38))
    {
        pMissile = SKILLS_CreateMissileFromOrigin(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    if (pMissile)
    {
        STATLIST_AddUnitStat(pMissile, 19, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
        const int nDamagePercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        STATLIST_AddUnitStat(pMissile, 25, nDamagePercent, 0);
    }

    return 1;
}

struct D2MonStats2Txt;

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

// 0x005D89B0
int __fastcall SKILLS_SrvDo075_GrimWard(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!D2COMMON_11018(pTarget))
    {
        return 0;
    }

    D2CoordStrc coords;
    coords.nX = CLIENTS_GetUnitX(pTarget);
    coords.nY = CLIENTS_GetUnitY(pTarget);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, coords.nX, coords.nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!COLLISION_GetFreeCoordinates(pRoom, &coords, 2, 0x1000, 1))
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nFlags[11 >> 3] & gdwBitMasks[11 & 7])
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileC;
    }
    else if (pMonStats2TxtRecord->nFlags[10 >> 3] & gdwBitMasks[10 & 7])
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileB;
    }

    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 1;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = coords.nX;
    missileParams.nY = coords.nY;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    STATES_ToggleState(pTarget, 104, 1);
    STATES_ToggleState(pTarget, 118, 1);
    UNITROOM_RefreshUnit(pTarget);
    return 1;
}

struct Skills { char pad0[0x12E]; unsigned short resultFlags; unsigned hitFlags,hitClass; unsigned calc[4]; char pad148[0x5D]; unsigned char srcDamage; char pad1A6[0x36]; unsigned char element; char pad1DD[0x5F]; };

struct Tables { char pad0[0xB98]; Skills* skills; void* linker; int skillCount; };

void __stdcall UNITS_SetTargetUnitForDynamicUnit(Unit*,Unit*);  // 0x00620C10

int __stdcall SKILLS_GetToHitFactor(Unit*,int,int);  // 0x006449F0

int __stdcall sub_00646CA0(Unit*,unsigned,int,int);  // 0x00646CA0

void __fastcall D2GAME_RollElementalDamage_6FD14DD0(Unit*,D2DamageStrc*,int,int);  // 0x0056E0C0

void __fastcall SUNITDMG_AllocCombat(Game*,Unit*,Unit*,D2DamageStrc*,unsigned char);  // 0x0057DBF0

void __fastcall SUNITDMG_DrainItemDurability(Game*,Unit*,Unit*,int);  // 0x0057D4F0

void __stdcall SKILLS_SetParam1(Skill*,int);  // 0x00644560

inline Skills* GetSkills(int id) { if(id>=0 && id<tables->skillCount) return &tables->skills[id]; return 0; }
enum { DEFAULT_SRC = 0x80 };


// 0x005D8B10
int __fastcall SKILLS_RollFrenzyDamage(Game* game,Unit* unit,Unit* target,int id,int level)
{
    Skills* record=GetSkills(id);
    if(!record) return 0;
    if(!target) return 0;
    UNITS_SetTargetUnitForDynamicUnit(unit,target);
    D2DamageStrc damage;
    memset(&damage,0,sizeof(damage));
    damage.wResultFlags=sub_0057EC10(game,unit,target,SKILLS_GetToHitFactor(unit,id,level),0);
    if(damage.wResultFlags&1) {
        damage.wResultFlags |= record->resultFlags;
        damage.dwHitFlags |= record->hitFlags;
        if(record->hitClass) damage.dwHitClass=record->hitClass;
        damage.dwEnDmgPct=sub_00646CA0(unit,record->calc[0],id,level);
        if(record->element>0) {
            damage.dwConvPct=sub_00646CA0(unit,record->calc[3],id,level);
            if(damage.dwConvPct>0) damage.nConvType=record->element;
        }
        D2GAME_RollElementalDamage_6FD14DD0(unit,&damage,id,level);
    }
    unsigned char source=record->srcDamage;
    if(!source) source=DEFAULT_SRC;
    SUNITDMG_AllocCombat(game,unit,target,&damage,source);
    SUNITDMG_DrainItemDurability(game,unit,target,0);
    Skill* skill=sub_00620250(unit);
    if(skill) {
        if(damage.wResultFlags&1) SKILLS_SetParam1(skill,1);
        else SKILLS_SetParam1(skill,0); // 0x00644560
    }
    return 1;
}

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

// 0x005D8C70
int __fastcall SKILLS_ApplyFrenzyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!SKILLS_GetParam1(pSkill))
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        const int nExpireFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel) + pGame->dwGameFrame;
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            if (!pStatList)
            {
                return 0;
            }

            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
            STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
            STATLIST_SetStatIfListIsValid(pStatList, STAT_SKILL_FRENZY, 0, 0);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
        }

        STATLIST_SetListExpireFrame(pStatList, nExpireFrame);
        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
        STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);
        int nValue = STATLIST_GetStatValue(pStatList, STAT_SKILL_FRENZY, 0) + 1;
        if (nValue > nSkillLevel)
        {
            nValue = nSkillLevel;
        }

        STATLIST_SetStatIfListIsValid(pStatList, STAT_SKILL_FRENZY, nValue, 0);
        SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nValue);
    }

    return 1;
}


// 0x005D8E00
int __fastcall SKILLS_SrvDo009_Frenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget) return 0;
    if (((pUnit->dwSeqFrame >> 8) % 2) == 0)
    {
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        SUNITDMG_FreeAttackerDefenderCombatList(pGame, pUnit, pTarget);
        PLRMODE_HandleDepletedWeapons(pGame, pUnit);
        PLRMODE_BreakDepletedWeapons(pGame, pUnit);
        SKILLS_ApplyFrenzyStats(pGame, pUnit, nSkillId, nSkillLevel);
        return SKILLS_RollFrenzyDamage(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    }
    pUnit->dwFlags |= SKILL_FLAG;
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    PLRMODE_HandleDepletedWeapons(pGame, pUnit);
    PLRMODE_BreakDepletedWeapons(pGame, pUnit);
    SKILLS_ApplyFrenzyStats(pGame, pUnit, nSkillId, nSkillLevel);
    const int nAuraRange = SKILLS_GetMeleeSearchRange(pUnit);
    const int nTargetGUID = pTarget->dwUnitId;
    pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nAuraRange, TARGET_FILTER, nTargetGUID, 0);
    return SKILLS_RollFrenzyDamage(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
}

// 0x005D8EF0
void __fastcall SKILLS_CurseStateCallback_Whirlwind(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, TIMERQUEUE_CURSESTATE, nState);

    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillBar.cpp", LINE_WHIRLWIND_ANIMRATE);
        sub_6FD14C30(pUnit);
    }
}


// 0x005D8F50
int __fastcall SKILLS_SrvSt38_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        SUNITMSG_QueueSkillStop(pUnit, nSkillId);
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        SUNITMSG_QueueSkillStop(pUnit, nSkillId);
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        return 0;
    }

    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            SUNITMSG_QueueSkillStop(pUnit, nSkillId);
            return SKILLS_StartBasicAttack(pGame, pUnit, pTarget);
        }
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }

    const int bPlayer = nUnitType == 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        SUNITMSG_QueueSkillStop(pUnit, nSkillId);
        return 0;
    }

    {
        const int nMask = bPlayer ? 0x1C09 : 0x3C01;
        PATH_SetMoveTestCollisionMask(pPath, 0xC01);
        PATH_SetType(pPath, 7);

        if (!D2Common_10142(pPath, pUnit, 0))
        {
            SUNITMSG_QueueSkillStop(pUnit, nSkillId);
            PATH_SetMoveTestCollisionMask(pPath, nMask);
            return 0;
        }

        PATH_SetVelocity((Obj00648690*)pPath, SKILLS_GetBaseWalkVelocity(pUnit), (int)".\\SKILLS\\SkillBar.cpp", 985);
        PATH_SetMoveTestCollisionMask(pPath, 0x401);

        D2PathPointStrc* ppPathPoints;
        const int nPathPoints = PATH_GetPathPoints((Obj006487D0*)pPath, (unsigned int**)&ppPathPoints);
        if (nPathPoints <= 0)
        {
            SUNITMSG_QueueSkillStop(pUnit, nSkillId);
            PATH_SetMoveTestCollisionMask(pPath, nMask);
            return 0;
        }

        nX = ppPathPoints[nPathPoints - 1].X;
        nY = ppPathPoints[nPathPoints - 1].Y;
    }

    COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), bPlayer ? 0x80 : 0x100);
    SUNIT_SetUninterruptable(pUnit, 1);
    STATES_ToggleState(pUnit, STATE_SKILL_MOVE, 1);

    SKILLS_SetFlags(pSkill, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    SKILLS_SetParam3(pSkill, -1);
    SKILLS_SetParam4(pSkill, 0);

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
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
    curse.pStateRemoveCallback = SKILLS_CurseStateCallback_Whirlwind;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    SKILLS_ApplyPassiveStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    if (pSkillsTxtRecord->wAuraEvent[0] >= 0)
    {
        SUNITEVENT_Unregister(pGame, pUnit, 1, pSkillsTxtRecord->nAuraState);

        for (int i = 0; i < 3; ++i)
        {
            if (pSkillsTxtRecord->wAuraEvent[i] < 0)
            {
                break;
            }

            SKILLS_RegisterUnitEvent(pGame, pUnit, pSkillsTxtRecord->wAuraEvent[i], nSkillId, nSkillLevel, pSkillsTxtRecord->wAuraEventFunc[i], 1, pSkillsTxtRecord->nAuraState);
        }
    }

    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);
    return 1;
}

// 0x005D92D0
static int SKILLS_IsDualWieldingMeleeWeapons(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

// build: symbol ?INVENTORY_GetCompositItem@* 0x0063C050
    D2UnitStrc* pLeftHandWeapon = INVENTORY_GetCompositItem(pInventory, 6);
    D2UnitStrc* pRightHandWeapon = INVENTORY_GetCompositItem(pInventory, 5);
    if (pLeftHandWeapon && ITEMSIsA(pLeftHandWeapon, 0x2E) && pRightHandWeapon && ITEMSIsA(pRightHandWeapon, 0x2E))
    {
        return 1;
    }

    return 0;
}

// 0x005D9320
static int __stdcall SKILLS_GetWhirlwindHitCount(D2GameStrc* pGame, D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        if ((unsigned int)lSeed & 1)
            return 0;
        return 1;
    }

    if (!pGame->bExpansion)
    {
        return 1;
    }

    int nFrame = SKILLS_GetParam4(pSkill);
    if (!nFrame)
    {
        SKILLS_SetParam4(pSkill, pGame->dwGameFrame + 4);
        return 1;
    }

    if (pGame->dwGameFrame < nFrame)
    {
        return 0;
    }

    int nCount = 1;
    int nDuration = 0;
    D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pUnit);
    if (!pWeapon)
    {
        nDuration = 10;
    }
    else
    {
        const int nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pUnit, pWeapon);
        if (nAttackSpeed < 12)
        {
            nDuration = 4;
        }
        else if (nAttackSpeed < 15)
        {
            nDuration = 6;
        }
        else if (nAttackSpeed < 18)
        {
            nDuration = 8;
        }
        else if (nAttackSpeed < 20)
        {
            nDuration = 10;
        }
        else if (nAttackSpeed < 23)
        {
            nDuration = 12;
        }
        else if (nAttackSpeed < 26)
        {
            nDuration = 14;
        }
        else
        {
            nDuration = 16;
        }
    }

    if (SKILLS_IsDualWieldingMeleeWeapons(pUnit))
    {
        nCount = 2;
    }

    nFrame += nDuration;
    if (nFrame < pGame->dwGameFrame)
    {
        nFrame = pGame->dwGameFrame + nDuration;
    }

    SKILLS_SetParam4(pSkill, nFrame);
    return nCount;
}

// 0x005D9460
int __fastcall SKILLS_RemoveWhirlwindStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSkillId, int nX, int nY)
{
    SKILLS_SetFlags(pSkill, 0);
    SUNIT_SetUninterruptable(pUnit, 0);
    SUNITMSG_QueueSkillStop(pUnit, nSkillId);

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }

    const int bPlayer = nUnitType == 0;
    const int nFootprintMask = bPlayer ? 0x80 : 0x100;
    const int nMoveMask = bPlayer ? 0x1C09 : 0x3C01;
    if (nX && nY)
    {
        COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nFootprintMask);
    }

    PATH_SetFootprintCollisionMask(pPath, nFootprintMask);
    PATH_SetMoveTestCollisionMask(pPath, nMoveMask);

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 0);
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (pStatList)
        {
            D2Common_10474(pUnit, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
    }

    return 1;
}

// 0x005D9580
int __fastcall SKILLS_SrvDo076_Whirlwind(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        SKILLS_RemoveWhirlwindStats(pGame, pUnit, pSkill, nSkillId, nX, nY);
        return 0;
    }

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if ((nSkillFlags & 3) == 3)
    {
        SKILLS_RemoveWhirlwindStats(pGame, pUnit, pSkill, nSkillId, nX, nY);
        return 1;
    }

    if (!(nSkillFlags & 1) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 3);
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, 0);
        pUnit->dwFrameCountPrecise = 0x400;
    }

    int nCount = SKILLS_GetWhirlwindHitCount(pGame, pSkill, pUnit);
    for (int i = 0; i < nCount; ++i)
    {
        const int nParam3 = SKILLS_GetParam3(pSkill);
        D2UnitStrc* pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, 5, 3, nParam3, 0);
        if (!pTarget)
        {
            SKILLS_SetParam3(pSkill, -1);
            nCount = 0;
        }
        else
        {
            SKILLS_SetParam3(pSkill, !pTarget ? -1 : pTarget->dwUnitId);

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

                damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
            }

            unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
            if (!pSkillsTxtRecord->nSrcDam)
            {
                nSrcDam = 0x80;
            }

            SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
            SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        }

        int nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 0x2000)
        {
            nFlags &= ~0x2000;
        }
        else
        {
            nFlags |= 0x2000;
        }

        SKILLS_SetFlags(pSkill, nFlags);
    }

    return 1;
}

// 0x005D97F0
int __fastcall SKILLS_SrvSt39_Berserk(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    const int nGameFrame = pGame->dwGameFrame;
    int nFrame = nGameFrame + SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nFrame <= nGameFrame)
    {
        nFrame = nGameFrame + 10;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const unsigned int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 1;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    STATLIST_SetListExpireFrame(pStatList, nFrame);
    EVENT_SetEvent(pGame, pUnit, 0xC, nFrame, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    return 1;
}

// 0x005D9A10
static int __stdcall SKILLS_FindLeapTargetPosition(D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);

    int nDistance = DRLG_GetDistanceToXY(pUnit, *pX, *pY);
    if (nDistance <= 1)
    {
        nDistance = 1;
    }

    if (nDistance > nAuraRange)
    {
        const int nOffsetX = *pX - nUnitX;
        const int nOffsetY = *pY - nUnitY;
        *pX = nUnitX + nOffsetX * nAuraRange / nDistance;
        *pY = nUnitY + nOffsetY * nAuraRange / nDistance;
    }

    int nY = *pY;
    int nDiffY = nY - nUnitY;
    int nX;
    int nDiffX;
    D2CoordStrc coords;
    int nCounter;
    nDiffY = D2_MIN(D2_MAX(nDiffY, -2), 2);
    nX = *pX;
    nDiffX = nUnitX - nX;
    nDiffX = D2_MIN(D2_MAX(nDiffX, -2), 2);
    coords.nX = nX;
    coords.nY = nY;
    nCounter = 3;
    while (nCounter)
    {
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), coords.nX, coords.nY);
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &coords, UNITS_GetUnitSizeX(pUnit), 0x1C09, 1);
        nX = coords.nX;
        nY = coords.nY;
        if (pRoom && !COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x1C09) && sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0x804) && DRLG_GetDistanceToXY(pUnit, nX, nY) <= nAuraRange)
        {
            *pX = nX;
            *pY = nY;
            return 1;
        }

        --nCounter;

        if (nCounter == 2)
        {
            coords.nX = *pX + nDiffY;
            coords.nY = *pY + nDiffX;
        }
        else if (nCounter == 1)
        {
            coords.nX = *pX - nDiffY;
            coords.nY = *pY - nDiffX;
        }
    }

    return 0;
}

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005D9C80
static int __stdcall SKILLS_StartMonsterLeapAttack(D2GameStrc* pGame, D2UnitStrc* pTarget, D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    if (!pTarget || !pSkill)
    {
        return 0;
    }

    sub_6FC627B0(pUnit, 4);
    MONSTERMODE_AllocateTargetCombat(pUnit, pGame);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
    SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    return 1;
}

// 0x005D9CE0
static int __stdcall SKILLS_CanLeapToPosition(D2UnitStrc* pUnit, int nX, int nY, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    return 1;
}

// 0x005D9D50
int __fastcall SKILLS_SrvSt40_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }

    const int bIsMonster = nUnitType == 1;

    int nX;
    int nY;
    D2CoordStrc coords;

    if (bIsMonster)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
            {
                UNITS_SetUsedSkill(pUnit, 0);
                return 0;
            }

            SKILLS_SetParam4(pSkill, -1);
        }
        else
        {
            SKILLS_StartMonsterLeapAttack(pGame, pTarget, pSkill, pUnit);
            if (SUNIT_IsDead(pUnit))
            {
                return 0;
            }

            nX = CLIENTS_GetUnitX(pTarget);
            nY = CLIENTS_GetUnitY(pTarget);
            nX = 2 * nX - CLIENTS_GetUnitX(pUnit);
            nY = 2 * nY - CLIENTS_GetUnitY(pUnit);
        }

        coords.nX = nX;
        coords.nY = nY;
        if (!COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &coords, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            return 0;
        }

        nX = coords.nX;
        nY = coords.nY;
    }
    else
    {
        if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }

        if (!SKILLS_CanLeapToPosition(pUnit, nX, nY, nSkillId))
        {
            return 0;
        }

        if (!SKILLS_FindLeapTargetPosition(pUnit, nSkillLevel, &nX, &nY, nSkillId))
        {
            return 0;
        }
    }

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
    SUNIT_SetUninterruptable(pUnit, 1);
    STATES_ToggleState(pUnit, 0x12, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);

    if (bIsMonster)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget)
        {
            SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }

    SKILLS_SetFlags(pSkill, 0x80);
    return 1;
}

static inline int sub_I16_IsMonster(D2UnitStrc* pUnit)
{
    return pUnit->dwUnitType == UNIT_MONSTER;
}

// 0x005D9F70
static int __stdcall SKILLS_SetVelocityForLeap(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2SkillStrc* pSkillRead = pSkill;
    SKILLS_SetFlags(pSkillRead, 0x1101);
    PATH_SetMoveTestCollisionMask(pPath, 0);
    PATH_SetFootprintCollisionMask(pPath, 0);

    const int nX = SKILLS_GetParam1(pSkillRead);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    PATH_SetType(pPath, 9);

    int nVelocity;
    if ((!pUnit ? 6 : pUnit->dwUnitType) == 1)
    {
        D2MonStatsTxtRun* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        nVelocity = pMonStatsTxtRecord->nRun << 8;
    }
    else
    {
        nVelocity = sub_004833E0_GetCharStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nRunSpeed << 8;
    }

    PATH_SetVelocity(pPath, nVelocity, ".\\SKILLS\\SkillBar.cpp", 0x6C2);
    D2Common_10142(pPath, pUnit, 0);
    return 1;
}

static inline D2SkillsTxt* sub_I16_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int sub_I16_GetUnitX(D2UnitStrc* pUnit)
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

// 0x005DA020
static int __stdcall SKILLS_ApplySandLeaperKnockback(D2GameStrc* pGame, int nX, int nY, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam4(pSkill));
    if (!pTarget)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 1);
    UNITS_SetAnimationFrame(pUnit, 12);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    PATH_RecacheRoomIfNeeded(pPath);
    PATH_SetNewDistance(pPath, 5);
    PATH_SetStepNum(pPath, 1);
    PATH_SetTargetUnit(pPath, 0);

    nX = 3 * nX - 2 * CLIENTS_GetUnitX(pTarget);
    nY = 3 * nY - 2 * CLIENTS_GetUnitY(pTarget);
    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (pTargetRoom && DUNGEON_IsRoomInTown(pTargetRoom))
    {
        return 0;
    }

    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    PATH_SetType(pPath, 8);
    D2COMMON_10190_PATH_SetDistance(pPath, 5);
    D2Common_10142(pPath, pUnit, 0);
    return 1;
}

// 0x005DA120
static int __stdcall SKILLS_Leap(D2GameStrc* pGame, D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nBaseId;
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);

    const int nType = (pUnit ? pUnit->dwUnitType : UNIT_INVALID);
    const int bMonster = nType == 1;
    int nId = -1;
    if (bMonster)
    {
        nId = CUNIT_GetMonsterBaseId(pUnit);
    }

    nBaseId = (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount) ? -1 : nId;

    if (sub_I16_GetUnitX(pUnit) == nX && CLIENTS_GetUnitY(pUnit) == nY)
    {
        if (bMonster)
        {
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
            PATH_SetFootprintCollisionMask(pPath, 0x100);
            PATH_SetMoveTestCollisionMask(pPath, 0x3C01);
            PATH_SetType(pPath, 2);

            if (nBaseId == MONSTER_SANDLEAPER1)
            {
                SKILLS_ApplySandLeaperKnockback(pGame, nX, nY, pUnit, pSkill);
            }
            else
            {
                SKILLS_SetFlags(pSkill, 0x200);
                pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) - 0x100;
            }
        }
        else
        {
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
            PATH_SetFootprintCollisionMask(pPath, 0x80);
            PATH_SetMoveTestCollisionMask(pPath, 0x1C09);
            PATH_SetType(pPath, 7);
            SKILLS_SetFlags(pSkill, 0x200);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
            EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 1, 0, 0);
        }

        SUNIT_SetUninterruptable(pUnit, 0);
        SUNITMSG_QueueSkillStop(pUnit, SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillBar.cpp", 0x737));
        return 1;
    }

    if (bMonster)
    {
        const int nBase = nBaseId;
        int nAnimFrame = 0;
        if (nBase == 0x4E)
        {
            nAnimFrame = 8;
        }
        else if (nBase == 0x21C)
        {
            nAnimFrame = (unsigned int)DRLG_GetDistanceToXY(pUnit, nX, nY) < 2 ? 12 : 10;
        }

        UNITS_SetAnimationFrame(pUnit, nAnimFrame);
        pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
        return 0;
    }

    D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 10);
    return 0;
}

static inline int sub_M392_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

// 0x005DA370
int __fastcall SKILLS_SrvDo077_Leap(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = sub_I16_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);

    const int bMonster = sub_M392_GetUnitType(pUnit) == 1;

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (SKILLS_Leap(pGame, pSkill, pUnit) && !bMonster)
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags = 9;
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
            SKILLS_ApplyAreaDamage(pGame, pUnit, 0, 0, nDamage, &damage, 0);
        }
    }
    else
    {
        if (nSkillFlags & 0x80)
        {
            return SKILLS_SetVelocityForLeap(pGame, pUnit, pSkill);
        }

        if (!bMonster)
        {
            SKILLS_SetFlags(pSkill, 0);
        }
    }

    return 1;
}

// 0x005DA490
static D2UnitStrc* __stdcall SKILLS_FindLeapAttackTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        pTarget = 0;
    }

    if (!pTarget)
    {
        const int nUnitType = SKILLS_GetParam3(pSkill);
        const int nUnitGUID = SKILLS_GetParam4(pSkill);
        if (nUnitType != 6)
        {
            pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        }

        if (!pTarget)
        {
            const int nRange = sub_6FD15460(pUnit);
            pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 0x20003, -1, 0);
        }
    }

    if (pTarget)
    {
        SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
        SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    }
    else
    {
        SKILLS_SetParam3(pSkill, 6);
    }

    return pTarget;
}

// 0x005DA540
int __fastcall SKILLS_SrvSt41_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);

    int nX;
    int nY;
    if (!SKILLS_CheckIfCanLeapTo(pUnit, pTarget, &nX, &nY))
    {
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            SKILLS_StartBasicAttack(pGame, pUnit, pTarget);
            return 1;
        }

        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nPattern = PATH_GetUnitCollisionPattern(pUnit);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, nPattern, 0x80);

    SUNIT_SetUninterruptable(pUnit, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);

    if (pTarget)
    {
        SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
        SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    }
    else
    {
        SKILLS_SetParam3(pSkill, 6);
    }

    SKILLS_SetFlags(pSkill, 0x1080);
    STATES_ToggleState(pUnit, 0x12, 1);

    if (pTarget && STATES_CheckState(pTarget, STATE_UNINTERRUPTABLE))
    {
        SKILLS_StunMonster(pGame, pUnit, pTarget, 100);
    }

    return 1;
}

// 0x005DA660
static int __stdcall SKILLS_ApplyLeapAttackDamage(D2GameStrc* pGame, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    D2SkillsTxt* pSkillsTxtRecord = sub_I16_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pDefender = SKILLS_FindLeapAttackTarget(pGame, pUnit, pSkill);
    if (!pDefender)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pDefender, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & 1)
    {
        damage.wResultFlags |= 8;
        damage.dwHitClass = sub_00623C20(pUnit);
        damage.dwHitFlags |= 0x20;
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);

        unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
        if (!nSrcDam)
        {
            nSrcDam = 0x80;
        }

        SUNITDMG_AllocCombat(pGame, pUnit, pDefender, &damage, nSrcDam);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pDefender, 0);

        if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
        {
            UNITS_SetOverlay(pDefender, pSkillsTxtRecord->wSrvOverlay, 0);
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, STATE_STUNNED);
        if (pStatList)
        {
            D2Common_10474(pDefender, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
    }

    return 1;
}

// 0x005DA7E0
int __fastcall SKILLS_SrvDo078_LeapAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (SKILLS_Leap(pGame, pSkill, pUnit))
        {
            if (!SKILLS_FindLeapAttackTarget(pGame, pUnit, pSkill))
            {
                D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
                EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 4, 0, 0);
                return 0;
            }

            D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, 16);
        }

        return 1;
    }

    if (nSkillFlags & 0x80)
    {
        return SKILLS_SetVelocityForLeap(pGame, pUnit, pSkill);
    }

    if (SKILLS_GetFlags(pSkill) & 0x200)
    {
        return SKILLS_ApplyLeapAttackDamage(pGame, nSkillId, nSkillLevel, pUnit);
    }

    SKILLS_SetFlags(pSkill, 0x1000);
    return 1;
}

// 0x005DA8B0
int __fastcall SKILLS_SrvSt65_Throw_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_CanUseWeaponAmmo(pUnit))
    {
        PLRMODE_HandleDepletedWeapons(pGame, pUnit);
        PLRMODE_BreakDepletedWeapons(pGame, pUnit);
        return 0;
    }

    return 1;
}

int __fastcall SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;

    sub_6FC7D260(pGame, pUnit, SKILLS_GetParam1(pSkill), 1);
    return 1;
}

#include "gen/data/Source/D2Game/SKILLS/SkillBar.inc"
