#include "D2ItemTypes.h"

#include "D2DrlgMaps.h"

#include "D2DrlgTiles.h"

#include "D2TxtTables.h"

#include "D2LevelIds.h"

#include "D2Unicode.h"

#include "D2StateIds.h"

#include "D2SkillIds.h"

#include "D2StatIds.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Records.h"

#include "D2Skills.h"

#include "D2LevelTxt.h"

#include "D2Drlg.h"

#include "D2Path.h"

#include "D2Txt.h"

#include "D2PlayerModes.h"

#include "D2MonModes.h"

#include "D2PathFind.h"
#include "D2MissileData.h"
#include "D2DrlgOutdoor.h"

#define LVLSUB_UNUSED_INVALID -1

#define PATH_CURRENT_ROOM_INVALID 2

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define STAT_TOHIT 19

#define MONSTATS2FLAGINDEX_REVIVE 8

#define MONSTATS2FLAGINDEX_ISATT 9

#define MONSTATS2FLAGINDEX_SMALL 10

#define PATH_UNKNOWN_FLAG_0x00020 0x20

#define PATH_UNKNOWN_FLAG_0x00040 0x40

#define STAT_ENERGY 1

#define STAT_DEXTERITY 2

#define STAT_VITALITY 3

#define STAT_LEVEL 12

#define SKILLSFLAGINDEX_INGAME 10

#define MONSTATS2FLAGINDEX_CORPSESEL 7

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2TCExShortStrc;

struct D2SkillsTxt;

struct D2SkillListStrc;

struct D2MissileDataStrc;

struct D2CoordStrc;

union D2FP32_16;

struct D2MissilesTxt;

struct D2DrlgCoordStrc;

struct D2DrlgOutdoorInfoStrc;


struct D2SkillCalcStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct R0052E0F0;

struct R00601DC0;

struct D2SkillsTxt00643D00Strc;

struct D2Skill00643D00Strc;

struct D2Owner00643D00Strc;

struct Obj00644340;

struct Obj0063D650;

struct D2StatesTxt;

struct D2StatStrc;

struct D2StaticPathStrc;

struct D2SkillFormulaCtxStrc;

struct D2CharStatsTxt;

struct D2SkillStrc;

struct D2PathPointStrc;

struct D2DynamicPathStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2DrlgGridStrc;

struct D2DrlgLevelStrc;

struct D2SkillDescTxt;

struct D2InventoryStrc;



extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern int gnPathResetPrecisionX; // 0x006EB7C8

extern int gnPathResetPrecisionY; // 0x006EB7CC

extern const int gaPathHeuristicTable[]; // 0x006F1698

extern const int gaIdaStar_PointCacheHashMaskX[]; // 0x006F1998

extern const int gaIdaStar_PointCacheHashMaskY[]; // 0x006F1B98

int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused); // 0x0064C2C0

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FC60

void __fastcall PATH_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70

void __fastcall DRLGTILESUB_ApplySubstitutionBorder(D2UnkOutdoorStrc* pOutdoor); // 0x00670750

void __fastcall DRLGOUTDOORS_AlterAdjacentPresetGridCells(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674160

void __fastcall DRLGOUTDOORS_SetBlankGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741A0

unsigned int __fastcall DRLGOUTDOORS_TestGridCellNonLvlLink(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741E0

int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nId, int nOffset, char nFlags); // 0x00674230

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0

struct D2SkillCalcStrc
{
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc* pUnit); // 0x004DC0B0

int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker); // 0x00622560

int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit); // 0x00622D00

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY); // 0x00643290

int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel); // 0x00646460

int __fastcall SKILLS_CalcSpecialParamCallback(int nParamId, void* pUserData); // 0x00646BE0

int __stdcall MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned char nParamId, int nMissileId, int nLevel); // 0x0064B340

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00646D60

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

struct R00601DC0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_00601DC0_IsOpen();
};

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

extern const int gnShapeShiftedModeTable[]; // 0x006EB348

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0

D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* pUnit); // 0x00620150

int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit); // 0x0063A770

int __stdcall SKILLS_GetRequiredLevelBasedOnCurrent(D2UnitStrc* pUnit, int nSkillId); // 0x00644750

struct D2SkillsTxt00643D00Strc
{
    short nSkillId;
    unsigned char unk_02[0x11];
    unsigned char nValue13;
};

struct D2Skill00643D00Strc
{
    D2SkillsTxt00643D00Strc* pSkillsTxt;
};

struct D2Owner00643D00Strc
{
    int bMonster;
    int nMonsterId;
};

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

struct Obj00644340 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwValue08;
};

struct Obj0063D650 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwValue08; };

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

int __fastcall SKILLS_GetBaseSkillLevelById(D2UnitStrc* pUnit, int nSkillId); // 0x006447B0

int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit); // 0x00621F60

typedef unsigned int size_t;

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __stdcall SKILLS_GetPassiveState(int nSkillId); // 0x00643690

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

extern const int gnShapeshiftMonModes[]; // 0x006EB308

int __stdcall D2Common_11014_ConvertShapeShiftedMode(int nArrayIndex, int nMonsterId); // 0x00645190

D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990

int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A710

int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

int __stdcall ITEMS_CheckType(int nItemType, int nItemTypeToCheck); // 0x00629B50

int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pStat, int nArraySize); // 0x006261D0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

struct D2SkillFormulaCtxStrc { D2UnitStrc* pUnit; int nSkillId; int nSkillLevel; };

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId); // 0x00647110

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" const char gszSkillsSourceFile;

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

void __stdcall SKILLS_UpdateChargedSkill(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bFreeMemory); // 0x00647320

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit); // 0x00644150

int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830

static int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00644180

int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit); // 0x00623C60

static int __fastcall SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage); // 0x00644C90

inline int SKILLS_EvaluateSkillFormulaInl(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel);

typedef int BOOL;

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0

int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit); // 0x0063A510

inline D2SkillStrc* __fastcall SKILLS_GetSkillInl(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, int* pIsLeftHand); // 0x0063C9B0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2TCExShortStrc* gpChestTreasureClasses[45]; // 0x0096C5F4

static BOOL __stdcall SKILLS_IsItemAllowedForSkill(D2UnitStrc* pItem, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nType); // 0x00643D90

static BOOL __stdcall SKILLS_CheckSkillDelay(D2SkillStrc* pSkill, D2UnitStrc* pUnit); // 0x006478F0

int __stdcall COMPOSIT_IsWeaponBowOrXBow(D2UnitStrc* pUnit); // 0x0064F460

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625E60

int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage); // 0x00644B70

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

static D2UnitStrc* __stdcall SKILLS_GetOtherHandItem(int nBodyLoc, D2InventoryStrc* pInventory);

static BOOL __stdcall SKILLS_CheckWeaponTypes(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static BOOL D2Common_SKILLS_CheckShapeRestriction_6FDB1380(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static BOOL D2Common_SKILLMANA_CheckStartStat_6FDB1400(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static BOOL D2Common_SKILLMANA_CheckStat_6FDB0F50(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static BOOL SKILLS_CheckSkillQuantity(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static BOOL SKILLS_HasChargesLeft(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3);

void __stdcall sub_006460C0_Empty(int nUnused);

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3);

void __stdcall sub_006460E0_Empty(int nUnused);

int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0063A510

static int __stdcall SKILLS_IsPointOutsideTown(int nX, int nY, D2UnitStrc* pUnit); // 0x00645C60

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

struct D2ItemsTxt;

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

int __stdcall D2Common_11034(int nSkillLevel, int nSkillId); // 0x00645B70

int __fastcall MISSILE_GetSkillMissileRange(int nSkillId, int nLevel); // 0x004CC7C0

int __stdcall D2Common_11035(int nSkillLevel, int nSkillId); // 0x00645BC0

int __fastcall SKILLDESC_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0

int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId); // 0x00645C10

int __fastcall SKILLS_GetSkillParam7Formula(int nSkillId, int nSkillLevel); // 0x00643580

int __stdcall D2Common_11033(int nLevel, int nParam1, int nParam2); // 0x00645B20

int __fastcall SKILLS_GetFirstSkillParam(int nSkillId); // 0x004C9460

int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20

int __fastcall SKILLDESC_GetSkillParamThree(int nSkillId); // 0x004EFC50

int __fastcall SKILLDESC_GetSkillParamFour(int nSkillId); // 0x004EFC80

int __fastcall SKILLDESC_GetSkillParamFive(int nSkillId); // 0x004E6C70

int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId); // 0x004F4110

int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644D50

int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644E40

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a4); // 0x00644F20

int __stdcall D2Common_11032(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nType); // 0x00647E00

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100

int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

int __stdcall MISSILE_GetElementalLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0

static D2SkillStrc* SKILLS_GetHighestLevelSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId);

int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY);

int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage);

static int __stdcall SKILLS_GetKickDamage(D2UnitStrc* pUnit, int bMin);

int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage);

int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

// build: symbol ?SKILLS_ScaleUpDirection@* 0x004C5390
void __fastcall SKILLS_ScaleUpDirection(int* pX, int* pY)
{
    int nDistance = *pX * *pX + *pY * *pY;
    if (nDistance < 4)
    {
        *pX <<= 2;
        *pY <<= 2;
        nDistance = *pX * *pX + *pY * *pY;
    }

    if (nDistance < 16)
    {
        *pX <<= 1;
        *pY <<= 1;
    }
}

int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

int __stdcall OBJECTS_SpawnNothing(int nArg)
{
    return 1;
}

bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x00643340
void __stdcall DUNGEON_ClientTileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 2 * nY + nX;
    *pY = 2 * nY - nX;

    if (*pX < 0)
    {
        *pX = *pX / 160 - 1;
    }
    else
    {
        *pX /= 160;
    }

    if (*pY < 0)
    {
        *pY = *pY / 160 - 1;
    }
    else
    {
        *pY /= 160;
    }
}

// 0x00643400
void __stdcall DUNGEON_ClientSubileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 2 * nY + nX;
    *pY = 2 * nY - nX;

    if (*pX < 0)
    {
        *pX = (*pX / 32) - 1;
    }
    else
    {
        *pX /= 32;
    }

    if (*pY < 0)
    {
        *pY = (*pY / 32) - 1;
    }
    else
    {
        *pY /= 32;
    }
}

inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x00643470
void __stdcall DUNGEON_GameToClientSubtileDrawPositionCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 16 * (nX - nY);
    *pY = 8 * (nX + nY);
    *pX -= 16;
    *pY += 16;
}

// 0x006434A0
void __stdcall DUNGEON_ConvertTileToSubtileCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = nX * 5;
    *pY = nY * 5;
}

// 0x006434C0
void __stdcall DUNGEON_ConvertSubtileToTileCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = nX / 5;
    if (nX < 0)
    {
        *pX = nX / 5 - 1;
    }
    *pY = nY / 5;
    if (nY < 0)
    {
        *pY = nY / 5 - 1;
    }
}

// 0x00643510
void __stdcall DUNGEON_ClientToGameSubtileCoords(int* pX, int* pY)
{
    const int nX = *pX;
    const int nY = *pY;

    *pX = (2 * nY + nX) >> 5;
    *pY = (2 * nY - nX) >> 5;
}

// 0x00643540
void __stdcall DUNGEON_ClientToGameCoords(int* pX, int* pY)
{
    const int nX = *pX;
    const int nY = *pY;

    *pX = 2 * nY + nX;
    *pY = 2 * nY - nX;
}

static inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

#define COORD_INDEX 0
#define SUBTILE_COUNT_PER_TILE 5
// 0x00643560
void __stdcall SKILLS_GameTileToSubtileCoords(int* pX, int* pY)
{
    pX[COORD_INDEX] *= SUBTILE_COUNT_PER_TILE;
    pY[COORD_INDEX] *= SUBTILE_COUNT_PER_TILE;
}

// 0x00643580
int __fastcall SKILLS_GetSkillParam7Formula(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[6] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[7];
}

// 0x006435C0
int __cdecl SKILLS_GetPassiveSkillCount()
{
    return sgptDataTables->nPassiveSkills;
}

// 0x006435D0
short __fastcall SKILLS_GetPassiveSkillId(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nPassiveSkills)
    {
        return sgptDataTables->pPassiveSkills[nIndex];
    }
    return -1;
}

// 0x00643600
int __cdecl sub_00643600_ReturnZero()
{
    return 0;
}

// 0x00643610
void __stdcall sub_00643610_Nop(int nUnused)
{
}

inline void* UNITS_GetMemoryPool(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pMemoryPool;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x00643620
static D2StatListStrc* __stdcall SKILLS_GetOrRemoveStateStatList(D2UnitStrc* pUnit, int nState, int nSkillLevel)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);

    if (nSkillLevel)
    {
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(UNITS_GetMemoryPool(pUnit), 0, 0, sub_0044BE50(pUnit), UNITS_GetUnitId(pUnit));
            STATLIST_SetState(pStatList, nState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }

        return pStatList;
    }

    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    return 0;
}

// 0x00643690
int __stdcall SKILLS_GetPassiveState(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nPassiveState <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->nPassiveState;
}

// 0x006436E0
int __fastcall SKILLS_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x006436F0
int __fastcall SKILLS_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

// 0x00643700
int __fastcall DUNGEON_SkillCalcGetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }
    D2SeedStrc* pSeed = &pSkillCalc->pUnit->pSeed;
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
}

// 0x00643740
int __fastcall SKILLS_CalcMissileParamCallback(int nMissileId, int nParamId, int nUnused, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }

    return MISSILE_GetSpecialParamValue(0, pSkillCalc->pUnit, nParamId, nMissileId, pSkillCalc->nSkillLevel);
}

// 0x00643770
int __fastcall SKILLS_ItemCalcStatParamCallback(int nStatId, int nType, int nUnused, void* pUserData)
{
    D2ItemCalcStrc* pItemCalc = (D2ItemCalcStrc*)pUserData;
    if (pItemCalc && pItemCalc->pUnit && nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        if (nStatId == STAT_TOHIT)
        {
            return UNITS_GetAttackRate(pItemCalc->pUnit);
        }

        switch (nType)
        {
        case 1:
            return STATLIST_GetUnitBaseStat(pItemCalc->pUnit, nStatId, 0);
        case 2:
            return STATLIST_UnitGetItemStatOrSkillStatValue(pItemCalc->pUnit, nStatId, 0);
        default:
            return STATLIST_UnitGetStatValue(pItemCalc->pUnit, nStatId, 0);
        }
    }

    return 0;
}

inline short DATATBLS_GetPassiveSkillId(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nPassiveSkills)
    {
        return sgptDataTables->pPassiveSkills[nIndex];
    }

    return -1;
}

// 0x006437E0
static inline D2SkillStrc* SKILLS_GetSkillByIdAndOwner(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (!pUnit->pSkills)
    {
        return 0;
    }

    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    if (!pSkill)
    {
        return 0;
    }

    while (pSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
        {
            break;
        }
        pSkill = pSkill->pNextSkill;
    }
    return pSkill;
}

// Nothing in the game calls 0x6437E0; this caller keeps its out-of-line copy.
D2SkillStrc* __stdcall sub_M113_Emit_006437E0(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    return SKILLS_GetSkillByIdAndOwner(pUnit, nSkillId, nOwnerGUID);
}

// 0x00643810
static D2SkillStrc* SKILLS_GetHighestLevelSkillFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit->pSkills)
    {
        return 0;
    }

    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    D2SkillStrc* pHighestLevelSkill = 0;
    for (; pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && !pSkill->bExcludeFromHighestLevelLookup && (!pHighestLevelSkill
            || pSkill->nOwnerGUID == -1 || pHighestLevelSkill->nOwnerGUID != -1 && pSkill->nSkillLevel > pHighestLevelSkill->nSkillLevel))
        {
            pHighestLevelSkill = pSkill;
        }
    }

    return pHighestLevelSkill;
}

// 0x00643860
int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (pUnit && pSkill)
    {
        return pSkill->dwSkillMode;
    }
    return 0;
}

// 0x00643880
int __stdcall SKILLS_Return1(int nArg)
{
    return 1;
}

// 0x00643890
int __stdcall SKILLS_GetRange(D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    if (!pSkill->pSkillsTxt)
    {
        return 0;
    }

    return pSkill->pSkillsTxt->nAuraTargetState;
}

// 0x006438B0
D2SkillListStrc* __stdcall SKILLS_AllocSkillList(void* pMemPool)
{
    D2SkillListStrc* pSkillList = (D2SkillListStrc*)sub_0040B430(pMemPool, sizeof(D2SkillListStrc), ".\\SKILLS\\Skills.cpp", 895, 0);
    memset(pSkillList, 0x00, sizeof(D2SkillListStrc));
    pSkillList->pMemPool = pMemPool;
    return pSkillList;
}

// 0x006438F0
D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill)
{
    if (!pSkill)
        return 0;
    return pSkill->pNextSkill;
}

// 0x00643910
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    if (!pSkillList)
        return 0;
    return pSkillList->pFirstSkill;
}

// 0x00643930
D2SkillStrc* __fastcall SKILLS_GetLeftSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    D2_ASSERT(pSkillList, 0x3E9);
    return pSkillList->pLeftSkill;
}

// 0x00643960
D2SkillStrc* __fastcall SKILLS_GetRightSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    D2_ASSERT(pSkillList, 0x40E);
    return pSkillList->pRightSkill;
}

// 0x00643990
void __fastcall SKILLS_SetUsedSkillInSkillList(D2SkillListStrc* pSkillList, D2SkillStrc* pUsedSkill)
{
    if (pSkillList)
    {
        pSkillList->pUsedSkill = pUsedSkill;
    }
}

// 0x006439A0
D2SkillStrc* __fastcall SKILLS_GetUsedSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    if (!pSkillList)
    {
        return 0;
    }

    return pSkillList->pUsedSkill;
}

// 0x006439B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (!pUnit->pSkills)
        return 0;
    D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill;
    if (!pSkill)
        return 0;
    while (pSkill)
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            break;
        pSkill = pSkill->pNextSkill;
    }
    return pSkill;
}

// 0x006439F0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId)
{
    return SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
}

// 0x00643A00
void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* pValue)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillListStrc* pSkillList = pUnit->pSkills;
    if (!pSkillList)
    {
        return 0;
    }

    void* pResult = pSkillList->unk0x14;
    pSkillList->unk0x14 = pValue;
    return pResult;
}

// 0x00643A30
void* __stdcall D2Common_10959(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pSkills)
    {
        return 0;
    }

    return pUnit->pSkills->unk0x14;
}

// 0x00643A60
void __stdcall SKILLS_FreeSkillList(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2SkillListStrc* pSkillList = pUnit->pSkills;
        if (pSkillList)
        {
            D2SkillStrc* pSkill = pSkillList->pFirstSkill;
            while (pSkill)
            {
                D2SkillStrc* pNextSkill = pSkill->pNextSkill;
                sub_0040B480(sub_004DC0B0_GetUnitMemoryPool(pUnit), pSkill, ".\\SKILLS\\Skills.cpp", 1285, 0);
                pSkill = pNextSkill;
            }

            sub_0040B480(pUnit->pMemoryPool, pSkillList, ".\\SKILLS\\Skills.cpp", 1288, 0);
            pUnit->pSkills = 0;
        }
    }
}

// 0x00643AD0
int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* hSkill)
{
    D2_ASSERT(hSkill, 1591);

    return hSkill->nOwnerGUID;
}

// 0x00643B00
int __stdcall SKILLS_GetSkillInfo(D2SkillStrc* hSkill, int* pOwnerGUID, int* pSkillId, int* pSkillLevel, int* pCharges)
{
    D2_ASSERT(hSkill, 0x641);

    if (hSkill->nOwnerGUID == -1)
    {
        return 0;
    }

    if (pOwnerGUID)
    {
        *pOwnerGUID = hSkill->nOwnerGUID;
    }
    if (pSkillId)
    {
        *pSkillId = hSkill->pSkillsTxt->nSkillId;
    }
    if (pSkillLevel)
    {
        *pSkillLevel = hSkill->nSkillLevel;
    }
    if (pCharges)
    {
        *pCharges = hSkill->nCharges;
    }

    return 1;
}

// 0x00643B70
int __stdcall SKILLS_SetCharges(D2SkillStrc* hSkill, int nCharges)
{
    D2_ASSERT(hSkill, 1623);

    if (hSkill->nOwnerGUID == D2UnitInvalidGUID)
    {
        return 0;
    }
    else
    {
        hSkill->bExcludeFromHighestLevelLookup = 1;
        hSkill->nCharges = nCharges;
        return 1;
    }
}

// 0x00643BC0
void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    D2_ASSERT(pSkillsTxtRecord, 0x668);

    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    int bSkillFound = 0;
    if (pSkill)
    {
        while (pSkill)
        {
            if (bSkillFound)
            {
                break;
            }

            if (pSkill->pSkillsTxt == pSkillsTxtRecord && pSkill->nOwnerGUID == nOwnerGUID)
            {
                bSkillFound = 1;
            }
            else
            {
                pSkill = pSkill->pNextSkill;
            }
        }

        if (bSkillFound)
        {
            pUnit->pSkills->pLeftSkill = pSkill;
        }
    }
}

// 0x00643C50
void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    D2_ASSERT(pSkillsTxtRecord, 0x67F);

    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    int bSkillFound = 0;
    if (pSkill)
    {
        while (pSkill)
        {
            if (bSkillFound)
            {
                break;
            }

            if (pSkill->pSkillsTxt == pSkillsTxtRecord && pSkill->nOwnerGUID == nOwnerGUID)
            {
                bSkillFound = 1;
            }
            else
            {
                pSkill = pSkill->pNextSkill;
            }
        }

        if (bSkillFound)
        {
            pUnit->pSkills->pRightSkill = pSkill;
        }
    }
}

// 0x00643CE0
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine)
{
    if (!pSkill)
    {
        return 0;
    }

    return pSkill->pSkillsTxt->nSkillId;
}

// 0x00643D00
int __fastcall SKILLS_GetSeqNumFromSkill(D2Owner00643D00Strc* pOwner, D2Skill00643D00Strc* pSkill)
{
    if (!pOwner || !pSkill)
    {
        return 0;
    }
    const int bMonster = pOwner ? pOwner->bMonster : 6;
    const int nMonsterId = pOwner->nMonsterId;
    if (!bMonster)
    {
        return pSkill->pSkillsTxt->nValue13;
    }
    const int nSkillId = pSkill->pSkillsTxt->nSkillId;
    if (nSkillId == SKILL_DIABPRISON)
    {
        return 0;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] == nSkillId)
        {
            return pMonStatsTxtRecord->nSkillLevel[i];
        }
    }
    return 0;
}

// 0x00643D60
static D2UnitStrc* __stdcall SKILLS_GetOtherHandItem(int nBodyLoc, D2InventoryStrc* pInventory)
{
    if (nBodyLoc == 5)
    {
        return INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    }

    return INVENTORY_GetItemFromBodyLoc(pInventory, 5);
}

// 0x00643D90
static BOOL __stdcall SKILLS_IsItemAllowedForSkill(D2UnitStrc* pItem, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nType)
{
    if (!pItem)
    {
        if (pSkillsTxtRecord->nETypeA[2 * nType] <= 0 && pSkillsTxtRecord->nITypeA[3 * nType] <= 0)
        {
            return TRUE;
        }

        if ((pSkillsTxtRecord->nITypeA[0] == 0x2D || pSkillsTxtRecord->nITypeA[0] == 0x2E || pSkillsTxtRecord->nITypeA[0] == 0x43)
            && pSkillsTxtRecord->nITypeB[0] <= 0 && !ITEMSIsA(0, 0x2D) && !ITEMSIsA(pUnit, 0x2D))
        {
            return TRUE;
        }

        if (pSkillsTxtRecord->nITypeA[0] == 0x43 && pSkillsTxtRecord->nITypeB[0] <= 0 && !ITEMSIsA(0, 0x2D) && !ITEMSIsA(pUnit, 0x2D))
        {
            return TRUE;
        }

        return FALSE;
    }

    int i = 0;
    short* pEType = &pSkillsTxtRecord->nETypeA[2 * nType];
    for (; i < 2; ++i)
    {
        if (*pEType <= 0)
        {
            break;
        }

        if (ITEMSIsA(pItem, *pEType))
        {
            return FALSE;
        }

        ++pEType;
    }

    i = 0;
    short* pIType = &pSkillsTxtRecord->nITypeA[3 * nType];
    for (; i < 3; ++i)
    {
        if (*pIType <= 0)
        {
            return i == 0;
        }

        if (ITEMSIsA(pItem, *pIType))
        {
            if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x810, ".\\SKILLS\\Skills.cpp") || ITEMS_CheckItemFlag(pItem, 0x100, 0x811, ".\\SKILLS\\Skills.cpp"))
            {
                return pSkillsTxtRecord->nSkillId == 0;
            }

            if (ITEMS_GetAmmoType(pItem))
            {
                if (SKILLS_HasFlag(pSkillsTxtRecord, 16))
                {
                    return TRUE;
                }

                if (!pSkillsTxtRecord->nSkillId && STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_MAGICARROW, 0))
                {
                    return TRUE;
                }

                if (!pUnit || !ITEMSIsA(pUnit, ITEMS_GetAmmoType(pItem)))
                {
                    return FALSE;
                }

                if (!pSkillsTxtRecord->nSkillId && STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_MAGICARROW, 0))
                {
                    return TRUE;
                }

                if (!ITEMS_GetTotalMaxStack(pUnit))
                {
                    return TRUE;
                }

                if (STATLIST_UnitGetStatValue(pUnit, STAT_QUANTITY, 0) <= 0)
                {
                    return FALSE;
                }
            }

            return TRUE;
        }

        ++pIType;
    }

    return FALSE;
}

// 0x00643F80
static BOOL __stdcall SKILLS_CheckWeaponTypes(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return FALSE;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;
    if (!pSkillsTxtRecord)
    {
        return FALSE;
    }

    if (pSkillsTxtRecord->nETypeA[0] <= 0 && pSkillsTxtRecord->nITypeA[0] <= 0)
    {
        return 1;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return FALSE;
    }

    D2UnitStrc* pRightHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pSkillsTxtRecord->nSkillId == SKILL_LEFTHANDTHROW || pSkillsTxtRecord->nSkillId == SKILL_LEFTHANDSWING)
    {
        D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pInventory);
        if (pItem == pRightHandItem)
        {
            pRightHandItem = 0;
        }
        else if (pItem == pLeftHandItem)
        {
            pLeftHandItem = 0;
        }
    }

    if (SKILLS_IsItemAllowedForSkill(pRightHandItem, pLeftHandItem, pSkillsTxtRecord, 0))
    {
        return SKILLS_IsItemAllowedForSkill(pLeftHandItem, pRightHandItem, pSkillsTxtRecord, 1);
    }

    if (SKILLS_IsItemAllowedForSkill(pRightHandItem, pLeftHandItem, pSkillsTxtRecord, 1))
    {
        return SKILLS_IsItemAllowedForSkill(pLeftHandItem, pRightHandItem, pSkillsTxtRecord, 0);
    }

    return FALSE;
}

// 0x00644060
static BOOL D2Common_SKILLS_CheckShapeRestriction_6FDB1380(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
    {
        return FALSE;
    }

    D2SkillsTxt* pSkillsTxt = pSkill->pSkillsTxt;
    if (!pSkillsTxt)
    {
        return FALSE;
    }

    switch (pSkillsTxt->nRestrict)
    {
    case 0:
        return !STATES_CheckStateMaskRestrictOnUnit(pUnit);

    case 1:
        return TRUE;

    case 2:
        break;

    default:
        return TRUE;
    }

    if (!STATES_CheckStateMaskRestrictOnUnit(pUnit))
    {
        return FALSE;
    }

    for (int i = 0; i < 3; ++i)
    {
        const int nState = pSkillsTxt->nState[i];
        if (nState < 0)
        {
            return FALSE;
        }

        if (STATES_CheckState(pUnit, nState))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x006440F0
static BOOL D2Common_SKILLMANA_CheckStartStat_6FDB1400(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER || pSkill->pSkillsTxt->wStartMana <= 0
        || STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >= (int)pSkill->pSkillsTxt->wStartMana << 8 || STATES_CheckState(pUnit, STATE_INFERNO))
    {
        return 1;
    }

    return FALSE;
}

// 0x00644140
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    return pSkill->pSkillsTxt;
}

// 0x00644150
int __stdcall SKILLS_GetShrineSkillLevelBonus(D2UnitStrc* pUnit)
{
    int nBonus = 0;
    if (STATES_CheckState(pUnit, STATE_SHRINE_SKILL))
    {
        nBonus += 2;
    }

    return nBonus;
}

// 0x00644180
static int __stdcall SKILLS_GetBonusSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill || !pSkill->pSkillsTxt)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;

    int nSkillId = pSkillsTxtRecord->nSkillId;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    int nSkillLevel = pSkill->nLevelBonus;
    nSkillLevel += SKILLS_GetShrineSkillLevelBonus(pUnit);
    nSkillLevel += STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_ALLSKILLS, (unsigned short)0);

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nClassId = pUnit->dwClassId;
        if (pSkillsTxtRecord->nCharClass == nClassId)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_ADDCLASSSKILLS, (unsigned short)nClassId);

            D2SkillDescTxt* pSkillDescTxtRecord = sub_004A89D0(nSkillId);
            if (pSkillDescTxtRecord->nSkillPage)
            {
                const int nTab = (!pUnit ? -1 : pUnit->dwClassId) * 8 + pSkillDescTxtRecord->nSkillPage - 1;
                nSkillLevel += STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_ADDSKILL_TAB, (unsigned short)nTab);
            }

            int nBonus = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_NONCLASSSKILL, (unsigned short)nSkillId);
            if (nBonus > 3)
            {
                nBonus = 3;
            }
            nSkillLevel += nBonus;
        }
        else
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_NONCLASSSKILL, (unsigned short)nSkillId);
        }
    }
    else
    {
        if (pSkill->nSkillLevel <= 0)
        {
            nSkillLevel += STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_NONCLASSSKILL, (unsigned short)nSkillId);
        }
        else
        {
            int nBonus = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_NONCLASSSKILL, (unsigned short)nSkillId);
            if (nBonus)
            {
                if (nBonus > 3)
                {
                    nBonus = 3;
                }
                nSkillLevel += nBonus;
            }
        }
    }

    const unsigned char nEType = pSkillsTxtRecord->nEType;
    if (nEType > 0)
    {
        nSkillLevel += STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_ELEMSKILL, (unsigned short)nEType);
    }

    return nSkillLevel + STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_SINGLESKILL, (unsigned short)nSkillId);
}

// @ref 0x00644180
// 0x006442A0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus)
{
    int nSkillLevel = 0;
    int nMaxLevel = 0;

    if (pUnit && pSkill)
    {
        nSkillLevel = pSkill->nSkillLevel;
        if (bBonus && pSkill->nOwnerGUID == -1)
        {
            nSkillLevel += SKILLS_GetBonusSkillLevel(pUnit, pSkill);
        }

        nSkillLevel = D2_MAX(nSkillLevel, 0);
        return D2_MIN(nSkillLevel, DATATBLS_GetMaxLevel(0));
    }

    return 0;
}

// 0x00644300
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
        if (pSkill && pSkill->nOwnerGUID == -1)
        {
            return SKILLS_GetBonusSkillLevel(pUnit, pSkill);
        }
    }

    return 0;
}

// 0x00644340
extern "C" __declspec(dllexport) void __stdcall SKILLS_SetSkillMode(Obj00644340* pObj, unsigned int dwValue) {
    if (pObj && dwValue <= 0x20) {
        pObj->dwValue08 = dwValue;
    }
}

// 0x00644360
extern "C" __declspec(dllexport) unsigned int __stdcall SKILLS_GetSkillMode(Obj0063D650* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue08;
}

// 0x00644380
int __stdcall D2Common_10969(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 2595);

    return ptSkill->unk0x10[0];
}

// 0x006443B0
void __stdcall D2Common_10970(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 2604);

    ptSkill->unk0x10[0] = nValue;
}

// 0x006443F0
int __stdcall D2Common_10971(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 2613);

    return ptSkill->unk0x10[1];
}

// 0x00644420
void __stdcall D2Common_10972(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 2622);

    ptSkill->unk0x10[1] = nValue;
}

// 0x00644460
void __stdcall D2Common_10973(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 2631);

    ptSkill->unk0x10[0] = 0;
    ptSkill->unk0x10[1] = 0;
}

// 0x006444A0
int __stdcall SKILLS_GetParam1(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 2642);

    return ptSkill->nXpos;
}

// 0x006444D0
int __stdcall SKILLS_GetParam2(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 2651);

    return ptSkill->nYpos;
}

// 0x00644500
int __stdcall SKILLS_GetParam3(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 2660);

    return ptSkill->nPar3;
}

// 0x00644530
int __stdcall SKILLS_GetParam4(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 2669);

    return ptSkill->nPar4;
}

// 0x00644560
void __stdcall SKILLS_SetParam1(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 2678);

    ptSkill->nXpos = nValue;
}

// 0x006445A0
void __stdcall SKILLS_SetParam2(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 2687);

    ptSkill->nYpos = nValue;
}

// 0x006445E0
void __stdcall SKILLS_SetParam3(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 2696);

    ptSkill->nPar3 = nValue;
}

// 0x00644620
void __stdcall SKILLS_SetParam4(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 2705);

    ptSkill->nPar4 = nValue;
}

// 0x00644660
void __stdcall SKILLS_SetFlags(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 2714);

    ptSkill->dwFlags = nValue;
}

static inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord_ForceInl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x006446A0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill)
{
    if (pSkill)
    {
        return pSkill->dwFlags;
    }

    return 0;
}

// 0x006446C0
static int SKILLS_UnitHasSkillsTxtRecord(D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord)
{
    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    D2_ASSERT(pSkill, 2736);

    while (pSkill)
    {
        if (pSkill->pSkillsTxt == pSkillsTxtRecord)
        {
            return 1;
        }

        pSkill = pSkill->pNextSkill;
    }

    return 0;
}

// 0x00644710
int __stdcall SKILLS_GetRequiredLevel(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0x7FFFFFFF;
    }

    return pSkillsTxtRecord->wReqLevel;
}

// 0x00644750
int __stdcall SKILLS_GetRequiredLevelBasedOnCurrent(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0x7FFFFFFF;
    }

    int nRequiredLevel = pSkillsTxtRecord->wReqLevel;
    D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
    if (pSkill)
    {
        nRequiredLevel += pSkill->nSkillLevel;
    }

    return nRequiredLevel;
}

// 0x006447B0
int __fastcall SKILLS_GetBaseSkillLevelById(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
    if (!pSkill)
    {
        return 0;
    }

    return pSkill->nSkillLevel;
}

// 0x006447D0
int __stdcall SKILLS_CheckRequiredSkills(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (SKILLS_GetRequiredLevelBasedOnCurrent(pUnit, nSkillId) > nLevel)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nReqSkill[0] < 0)
    {
        if (SKILLS_GetRequiredLevelBasedOnCurrent(pUnit, nSkillId) > nLevel)
        {
            return 0;
        }
    }
    else
    {
        D2SkillsTxt* pReqSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord_ForceInl(pSkillsTxtRecord->nReqSkill[0]);
        if (!pReqSkillsTxtRecord)
        {
            return 0;
        }

        if (!SKILLS_UnitHasSkillsTxtRecord(pUnit, pReqSkillsTxtRecord))
        {
            return 0;
        }

        if (!pUnit)
        {
            return 0;
        }

        D2SkillStrc* pSkill = SKILLS_GetSkill(pUnit, pSkillsTxtRecord->nReqSkill[0], -1);
        if (!pSkill || pSkill->nSkillLevel <= 0)
        {
            return 0;
        }
    }

    if (pSkillsTxtRecord->nReqSkill[1] >= 0)
    {
        D2SkillsTxt* pReqSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(pSkillsTxtRecord->nReqSkill[1]);
        if (!pReqSkillsTxtRecord)
        {
            return 0;
        }

        if (!SKILLS_UnitHasSkillsTxtRecord(pUnit, pReqSkillsTxtRecord))
        {
            return 0;
        }

        if (SKILLS_GetBaseSkillLevelById(pUnit, pSkillsTxtRecord->nReqSkill[1]) <= 0)
        {
            return 0;
        }
    }

    if (pSkillsTxtRecord->nReqSkill[2] >= 0)
    {
        D2SkillsTxt* pReqSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(pSkillsTxtRecord->nReqSkill[2]);
        if (!pReqSkillsTxtRecord)
        {
            return 0;
        }

        if (!SKILLS_UnitHasSkillsTxtRecord(pUnit, pReqSkillsTxtRecord))
        {
            return 0;
        }

        if (SKILLS_GetBaseSkillLevelById(pUnit, pSkillsTxtRecord->nReqSkill[2]) <= 0)
        {
            return 0;
        }
    }

    return 1;
}

// 0x00644920
int __stdcall SKILLS_CheckRequiredAttributes(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INGAME >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INGAME & 7]))
    {
        return 0;
    }

    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (SKILLS_GetRequiredLevelBasedOnCurrent(pUnit, nSkillId) > nUnitLevel)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wReqStr > STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0))
    {
        return 0;
    }

    if (pSkillsTxtRecord->wReqDex > STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0))
    {
        return 0;
    }

    if (pSkillsTxtRecord->wReqInt > STATLIST_UnitGetStatValue(pUnit, STAT_ENERGY, 0))
    {
        return 0;
    }

    return pSkillsTxtRecord->wReqVit <= STATLIST_UnitGetStatValue(pUnit, STAT_VITALITY, 0);
}

// 0x006449F0
int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        unsigned int nCalc = pSkillsTxtRecord->dwToHitCalc;
        if (nCalc != -1)
        {
            return SKILLS_EvaluateSkillFormulaInl(pUnit, nCalc, nSkillId, nSkillLevel);
        }

        return pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit;
    }
}

// 0x00644AA0
int __stdcall SKILLS_GetHighestSkillLevelById(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit)
    {
        return SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId), 1);
    }

    return 0;
}

// 0x00644B10
int __stdcall SKILLS_GetManaCosts(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
}

// 0x00644B70
int __fastcall SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage)
{
    if (nLevel > 1 && pLevelDamage)
    {
        if (nLevel > 28)
        {
            return 7 * *pLevelDamage + pLevelDamage[4] * (nLevel - 28) + 6 * (pLevelDamage[2] + pLevelDamage[3]) + 8 * pLevelDamage[1];
        }
        else if (nLevel > 22)
        {
            return 7 * *pLevelDamage + pLevelDamage[3] * (nLevel - 22) + 6 * pLevelDamage[2] + 8 * pLevelDamage[1];
        }
        else if (nLevel > 16)
        {
            return 7 * *pLevelDamage + pLevelDamage[2] * (nLevel - 16) + 8 * pLevelDamage[1];
        }
        else if (nLevel > 8)
        {
            return 7 * *pLevelDamage + pLevelDamage[1] * (nLevel - 8);
        }
        else
        {
            return *pLevelDamage * (nLevel - 1);
        }
    }

    return 0;
}

// 0x00644C20
static int __stdcall SKILLS_GetKickDamage(D2UnitStrc* pUnit, int bMin)
{
    int nDamage;

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        nDamage = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) + STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) - 20;
    }
    else
    {
        nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    }

    if (nDamage < 1)
    {
        nDamage = 1;
    }

    if (bMin)
    {
        return nDamage / 4 << 8;
    }

    return nDamage / 3 << 8;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00644C90
static int __fastcall SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
    int nPercentage = 0;

    switch (nElemType)
    {
    case 1:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 2:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 4:
    case 12:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_COLD_MASTERY, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    case 5:
        nPercentage = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
        if (nPercentage)
        {
            return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
        }
        break;

    default:
        break;
    }

    return 0;
}

inline int SKILLS_ApplyMasteryInl(D2UnitStrc* pUnit, int nStatId, int nSrcDamage)
{
    int nPercentage = STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
    if (!nPercentage)
    {
        return 0;
    }

    return DATATBLS_ApplyRatio(nSrcDamage, nPercentage, 100);
}

// 0x00644D50
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        int nDamage = (pSkillsTxtRecord->dwEMin + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwEMinLev)) << pSkillsTxtRecord->nToHitShift;

        if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1 && (nDamage > 256 || pSkillsTxtRecord->dwEMinLev[0]))
        {
            int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

            if (nBonus)
            {
                nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
            }
        }

        if (bApplyMastery && pUnit)
        {
            nDamage += SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
        }

        return nDamage;
    }
}

// 0x00644E40
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        int nDamage = (pSkillsTxtRecord->dwEMax + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwEMaxLev)) << pSkillsTxtRecord->nToHitShift;

        if (pSkillsTxtRecord->dwEDmgSymPerCalc != -1)
        {
            int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwEDmgSymPerCalc, nSkillId, nSkillLevel);

            if (nBonus)
            {
                nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
            }
        }

        if (bApplyMastery && pUnit)
        {
            nDamage += SKILLS_CalculateMasteryBonus(pUnit, pSkillsTxtRecord->nEType, nDamage);
        }

        return nDamage;
    }
}

__forceinline int SKILLS_EvaluateSkillFormulaInl(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    D2SkillCalcStrc pSkillCalc;

    if (!sgptDataTables->pSkillsCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nSkillsCodeSize)
    {
        return 0;
    }

    pSkillCalc.pUnit = pUnit;
    pSkillCalc.nSkillId = nSkillId;
    pSkillCalc.nSkillLevel = nSkillLevel;

    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pSkillsCode[nCalc], sgptDataTables->nSkillsCodeSize - nCalc, SKILLS_CalcSpecialParamCallback, gpSkillsCalcFunctions, gnSkillsCalcFunctions, &pSkillCalc);
}

// 0x00644F20
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    int nLevelLength = 0;

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    if (nSkillLevel > 16)
    {
        nLevelLength = (nSkillLevel - 16) * pSkillsTxtRecord->dwELevLen[2] + 8 * pSkillsTxtRecord->dwELevLen[1] + 7 * pSkillsTxtRecord->dwELevLen[0];
    }
    else if (nSkillLevel > 8)
    {
        nLevelLength = (nSkillLevel - 8) * pSkillsTxtRecord->dwELevLen[1] + 7 * pSkillsTxtRecord->dwELevLen[0];
    }
    else
    {
        nLevelLength = (nSkillLevel - 1) * pSkillsTxtRecord->dwELevLen[0];
    }

    int nLength = pSkillsTxtRecord->dwELen + nLevelLength;

    if (pSkillsTxtRecord->dwELenSymPerCalc != -1)
    {
        const int nBonus = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwELenSymPerCalc, nSkillId, nSkillLevel);
        if (nBonus)
        {
            nLength += DATATBLS_ApplyRatio(nLength, nBonus, 100);
        }
    }

    return nLength;
}

// 0x00645030
int __stdcall sub_00645030_AlwaysZero(int nUnused)
{
    return 0;
}

// 0x00645040
int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (pSkillsTxtRecord && pSkillsTxtRecord->nCharClass >= 0)
    {
        return pSkillsTxtRecord->nCharClass;
    }

    return 7;
}

// 0x00645080
int __stdcall SKILLS_IsPlayerClassSkill(int nSkillId, int* pPlayerClass)
{
    SKILLS_ASSERT(pPlayerClass, 3449);

    *pPlayerClass = SKILLS_GetClassIdFromSkillId(nSkillId);
    return *pPlayerClass != 7;
}

// 0x006450F0
int __stdcall SKILLS_GetQuantity(D2SkillStrc* ptSkill)
{
    SKILLS_ASSERT(ptSkill, 3492);

    return ptSkill->nQuantity;
}

// 0x00645120
void __stdcall SKILLS_SetQuantity(D2SkillStrc* ptSkill, int nValue)
{
    SKILLS_ASSERT(ptSkill, 3501);

    ptSkill->nQuantity = nValue;
}

// 0x00645160
static int __stdcall SKILLS_ConvertShapeshiftMonMode(int nMode, int nClass)
{
    return (nClass == 6 && nMode == 4) ? 12 : gnShapeshiftMonModes[nMode];
}

// 0x00645190
int __stdcall D2Common_11014_ConvertShapeShiftedMode(int nArrayIndex, int nMonsterId)
{
    int nMode = gnShapeShiftedModeTable[nArrayIndex];

    while (1)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
        const unsigned int nModeFlag = pMonStats2TxtRecord ? (pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7]) : 0;
        if (nModeFlag)
        {
            return nMode;
        }

        switch (nMode)
        {
        case MONMODE_NEUTRAL:
            return nMode;
        case MONMODE_RUN:
            nMode = MONMODE_WALK;
            continue;
        case MONMODE_SKILL2:
        case MONMODE_SKILL3:
        case MONMODE_SKILL4:
            nMode = MONMODE_SKILL1;
            continue;
        case MONMODE_ATTACK2:
        case MONMODE_CAST:
            nMode = MONMODE_ATTACK1;
            continue;
        case MONMODE_BLOCK:
            nMode = MONMODE_GETHIT;
            continue;
        default:
            nMode = MONMODE_NEUTRAL;
            continue;
        }
    }
}

int __stdcall sub_K15_Emit6(int* p, int n)
{
    return SKILLS_ConvertShapeshiftMonMode(p[0], n) + SKILLS_ConvertShapeshiftMonMode(p[n], p[2]);
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInl(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x00645270
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine)
{
    if (!STATES_IsUnitShapeShiftedInl(pUnit))
    {
        return;
    }

    for (int nCounter = 0; nCounter < sgptDataTables->nTransformStates; ++nCounter)
    {
        const short nState = sgptDataTables->pTransformStates[nCounter];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInl(nState);
            if (pStatesTxtRecord)
            {
                switch (pStatesTxtRecord->nGfxType)
                {
                case 2:
                {
                    *pType = 0;
                    const int nClass = pStatesTxtRecord->wGfxClass;
                    *pClass = nClass;

                    if (pUnit->dwUnitType == UNIT_MONSTER)
                    {
                        const int nMode = *pMode;
                        *pMode = (nClass == 6 && nMode == 4) ? 12 : gnShapeshiftMonModes[nMode];
                    }
                    return;
                }

                case 1:
                {
                    *pType = 1;
                    const int nMonsterId = pStatesTxtRecord->wGfxClass;
                    *pClass = nMonsterId;

                    if (pUnit->dwUnitType == UNIT_PLAYER)
                    {
                        *pMode = D2Common_11014_ConvertShapeShiftedMode(*pMode, nMonsterId);
                    }
                    return;
                }
                }
            }
        }
    }
}

// 0x00645390
void __stdcall D2Common_11015(D2UnitStrc* pUnit, int a2, int nSkillId)
{
    D2SkillStrc* ptSkill = SKILLS_GetSkillInl(pUnit, nSkillId, -1);
    int nPosition;
    if (a2)
    {
        const int nType = pUnit->dwUnitType;
        const int nId = pUnit->dwUnitId;
        _ReadWriteBarrier();
        nPosition = (nType << 16) + nId;
    }
    else
    {
        const int nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        const int nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
        nPosition = nX + 3 * nY;
    }

    D2_ASSERT(ptSkill, 0xA52);

    if (ptSkill->nXpos == nPosition)
    {
        const unsigned int nYpos = ptSkill->nYpos + 7;
        ptSkill->nXpos = nPosition;
        _ReadWriteBarrier();
        ptSkill->nYpos = nYpos;
    }
    else
    {
        _ReadWriteBarrier();
        ptSkill->nYpos = nPosition;
        ptSkill->nXpos = nPosition;
    }

    SEED_InitLowSeed(&pUnit->pSeed, ptSkill->nYpos);
}

// 0x00645460
int __stdcall D2Common_11016(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    if (!pSkill->pSkillsTxt)
    {
        return 0;
    }

    int nRange = pSkill->pSkillsTxt->nAuraTargetState;
    if (nRange != 3)
    {
        return nRange;
    }

    nRange = (COMPOSIT_IsWeaponBowOrXBow(pUnit) != 0) + 1;
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && nRange != 1 && STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return 1;
    }

    return nRange;
}

// 0x006454C0
static int __stdcall SKILLS_IsSelectableCorpse(int bDying, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (!(pUnit->dwAnimMode == MONMODE_DEAD || bDying && pUnit->dwAnimMode == MONMODE_DEATH))
    {
        return 0;
    }

    if (STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        return 0;
    }

    return MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, 7) != 0;
}

// 0x00645510
int __stdcall D2COMMON_11017_CheckUnitIfConsumeable(D2UnitStrc* pUnit, int a2)
{
    int nClassId;
    int bCorpseSelectable = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && (pUnit->dwAnimMode == MONMODE_DEAD || a2 && pUnit->dwAnimMode == MONMODE_DEATH) && !STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        nClassId = pUnit->dwClassId;
        bCorpseSelectable = MONSTERREGION_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_CORPSESEL);
    }

    if (!bCorpseSelectable)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    return pMonStatsTxtRecord->nVelocity != 0;
}

int __fastcall sub_G02_Emit_006454C0(D2UnitStrc* pUnit, int nMode)
{
    if (SKILLS_IsSelectableCorpse(nMode, pUnit))
    {
        return STATES_CheckStateMaskUdeadOnUnit(pUnit);
    }
    return SKILLS_IsSelectableCorpse(0, pUnit);
}

static inline int CORPSE_CanUnitCorpseBeSelected(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit))
    {
        if (MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL))
            return 1;
    }
    return 0;
}

// 0x00645590
int __stdcall D2COMMON_11018(D2UnitStrc* pUnit)
{
    if (!CORPSE_CanUnitCorpseBeSelected(pUnit))
        return 0;
    return UNITS_IsSoftMonster(pUnit) != 0;
}

// 0x006455E0
int __stdcall D2COMMON_11019(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int bCorpseSelectable = (nUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit)) ? MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL) : 0;
    if (!bCorpseSelectable)
    {
        return 0;
    }

    return 1;
}

inline int UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPositionForceInl(D2UnitStrc* pUnit)
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

// build: symbol ?gaPathDeltaTable@* 0x006F1E28

// 0x00646460
int __stdcall SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, int nParamId, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordInl(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    int nIndex;
    int nMissileId;
    int nResult;
    const int nParam = (unsigned char)nParamId;
    switch (nParam)
    {
    case 0:
        nResult = SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel);
        break;
    case 1:
        nResult = D2Common_11034(nSkillLevel, nSkillId);
        break;
    case 2:
        nResult = MISSILE_GetSkillMissileRange(nSkillId, nSkillLevel);
        break;
    case 3:
        nResult = D2Common_11035(nSkillLevel, nSkillId);
        break;
    case 4:
        nResult = SKILLDESC_GetSummonLevel(nSkillId, nSkillLevel);
        break;
    case 5:
        nResult = D2COMMON_11036_GetMonCurseResistanceSubtraction(nSkillLevel, nSkillId);
        break;
    case 6:
        nResult = SKILLS_GetSkillParam7Formula(nSkillId, nSkillLevel);
        break;
    case 7:
        nResult = D2Common_11033(nSkillLevel, pSkillsTxtRecord->dwParam[6], pSkillsTxtRecord->dwParam[7]);
        break;
    case 8:
        nResult = SKILLS_GetFirstSkillParam(nSkillId);
        break;
    case 9:
        nResult = SKILLDESC_GetSkillParamTwo(nSkillId);
        break;
    case 10:
        nResult = SKILLDESC_GetSkillParamThree(nSkillId);
        break;
    case 11:
        nResult = SKILLDESC_GetSkillParamFour(nSkillId);
        break;
    case 12:
        nResult = SKILLDESC_GetSkillParamFive(nSkillId);
        break;
    case 13:
        nResult = SKILLDESC_GetSkillParamSix(nSkillId);
        break;
    case 14:
        nResult = pSkillsTxtRecord->dwParam[6];
        break;
    case 15:
        nResult = pSkillsTxtRecord->dwParam[7];
        break;
    case 16:
        nResult = nSkillLevel;
        break;
    case 17:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
        break;
    case 18:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
        break;
    case 19:
        nResult = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 20:
        nResult = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
        break;
    case 21:
        if (nSkillLevel > 0)
        {
            nResult = ((pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift) >> 8;
            break;
        }
        nResult = 0;
        break;
    case 22:
        if (nSkillLevel > 0)
        {
            nResult = ((25 * (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) / 2) << pSkillsTxtRecord->nManaShift) >> 8;
            break;
        }
        nResult = 0;
        break;
    case 23:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 24:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 25:
        nResult = D2Common_11032(pUnit, nSkillId, nSkillLevel, 2);
        break;
    case 26:
    case 29:
    case 32:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 26) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
                break;
            }
        }
        nResult = 0;
        break;
    case 27:
    case 30:
    case 33:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 27) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
                break;
            }
        }
        nResult = 0;
        break;
    case 28:
    case 31:
    case 34:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 28) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetElementalLength(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 35:
    case 36:
    case 37:
    {
        pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        if (pSkillDescTxtRecord)
        {
            D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pSkillDescTxtRecord->wDescMissile[nParam - 35]);
            if (pMissilesTxtRecord)
            {
                nResult = pMissilesTxtRecord->wRange + nSkillLevel * pMissilesTxtRecord->wLevRange;
                break;
            }
        }
        nResult = 0;
        break;
    }
    case 38:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 39:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 0);
        break;
    case 40:
        if (pUnit)
        {
            nResult = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
            break;
        }
        nResult = 0;
        break;
    case 41:
        if (pUnit)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
            if (pSkill)
            {
                nResult = SKILLS_GetSkillLevel(pUnit, pSkill, 0);
                break;
            }
        }
        nResult = 0;
        break;
    case 42:
        if (nSkillLevel > 0)
        {
            nResult = (pSkillsTxtRecord->wMana + (nSkillLevel - 1) * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
            break;
        }
        nResult = 0;
        break;
    case 43:
    case 45:
    case 47:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 43) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 44:
    case 46:
    case 48:
        if (nSkillLevel > 0)
        {
            nIndex = (nParam - 44) / 3;
            pSkillDescTxtRecord = sub_004A89D0_SkillDescRec(nSkillId);
        }
        if (pSkillDescTxtRecord)
        {
            nMissileId = pSkillDescTxtRecord->wDescMissile[nIndex];
            if (sub_0046ACE0(nMissileId))
            {
                nResult = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel);
                break;
            }
        }
        nResult = 0;
        break;
    case 49:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        break;
    case 50:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        break;
    case 51:
        nResult = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 52:
        nResult = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 53:
        nResult = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        break;
    case 54:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
        break;
    case 55:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        break;
    case 56:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        break;
    case 57:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        break;
    case 58:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
        break;
    case 59:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        break;
    case 60:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], nSkillId, nSkillLevel);
        break;
    case 61:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
        break;
    case 62:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[2], nSkillId, nSkillLevel);
        break;
    case 63:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[3], nSkillId, nSkillLevel);
        break;
    case 64:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[4], nSkillId, nSkillLevel);
        break;
    case 65:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwAuraStatCalc[5], nSkillId, nSkillLevel);
        break;
    case 66:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[0], nSkillId, nSkillLevel);
        break;
    case 67:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[1], nSkillId, nSkillLevel);
        break;
    case 68:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[2], nSkillId, nSkillLevel);
        break;
    case 69:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[3], nSkillId, nSkillLevel);
        break;
    case 70:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPassiveCalc[4], nSkillId, nSkillLevel);
        break;
    case 71:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
        break;
    case 72:
        nResult = SKILLS_EvaluateSkillFormulaInl(pUnit, pSkillsTxtRecord->dwSkPoints, nSkillId, nSkillLevel);
        break;
    default:
        nResult = 0;
        break;
    }

    return nResult;
}

// 0x00646BE0
int __fastcall SKILLS_CalcSpecialParamCallback(int nParamId, void* pUserData)
{
    if (!pUserData) return 0;
    D2SkillFormulaCtxStrc* pContext = (D2SkillFormulaCtxStrc*)pUserData;
    return SKILLS_GetSpecialParamValue(pContext->pUnit, nParamId, pContext->nSkillId, pContext->nSkillLevel);
}

// 0x00646C00
int __fastcall SKILLS_CalcOtherSkillParamCallback(int nSkillId, int nParamId, int nUnused, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }

    int nSkillLevel = 0;
    if (pSkillCalc->pUnit)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pSkillCalc->pUnit, nSkillId);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pSkillCalc->pUnit, pSkill, 1);
        }
    }

    return SKILLS_GetSpecialParamValue(pSkillCalc->pUnit, nParamId, nSkillId, nSkillLevel);
}

// 0x00646C60
int __fastcall SKILLS_CalcNestedParamCallback(int nSkillId, int a2, int a3, void* pUserData)
{
    D2SkillCalcStrc* pSkillCalc = (D2SkillCalcStrc*)pUserData;
    if (!pSkillCalc)
    {
        return 0;
    }

    return SKILLS_GetSpecialParamValue(pSkillCalc->pUnit, a3, nSkillId, SKILLS_GetSpecialParamValue(pSkillCalc->pUnit, a2, pSkillCalc->nSkillId, pSkillCalc->nSkillLevel));
}

// 0x00646CA0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    return SKILLS_EvaluateSkillFormulaInl(pUnit, nCalc, nSkillId, nSkillLevel);
}

// 0x00646D00
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel)
{
    D2SkillCalcStrc pSkillCalc;

    if (!sgptDataTables->pSkillDescCode)
    {
        return 0;
    }

    if (nCalc >= sgptDataTables->nSkillDescCodeSize)
    {
        return 0;
    }

    pSkillCalc.pUnit = pUnit;
    pSkillCalc.nSkillId = nSkillId;
    pSkillCalc.nSkillLevel = nSkillLevel;

    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pSkillDescCode[nCalc], sgptDataTables->nSkillDescCodeSize - nCalc, SKILLS_CalcSpecialParamCallback, gpSkillsCalcFunctions, gnSkillsCalcFunctions, &pSkillCalc);
}

// 0x00646D60
void __stdcall SKILLS_RefreshSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordInl(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    short nPassiveState = pSkillsTxtRecord->nPassiveState;
    if (nPassiveState <= 0 || nPassiveState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);
    if (!pSkill)
    {
        D2StatListStrc* pOldStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nPassiveState);
        if (pOldStatList)
        {
            D2Common_10474(pUnit, pOldStatList);
            STATLIST_FreeStatList(pOldStatList);
        }
        return;
    }

    if (pSkillsTxtRecord->nAuraState > 0 && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        int const tArg3 = pSkillsTxtRecord->nPassiveState;
        D2StatListStrc* pOldStatList = STATLIST_GetStatListFromUnitAndState(pUnit, tArg3);
        if (pOldStatList)
        {
            D2Common_10474(pUnit, pOldStatList);
            STATLIST_FreeStatList(pOldStatList);
        }
        return;
    }

    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    D2StatListStrc* pStatList = SKILLS_GetOrRemoveStateStatList(pUnit, pSkillsTxtRecord->nPassiveState, nSkillLevel);
    if (!pStatList || STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0) == nSkillLevel)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxtRecord->nPassiveStat[i] < 0 || pSkillsTxtRecord->nPassiveStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            break;
        }

        int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nPassiveIType <= 0)
        {
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, 0);
        }
        else
        {
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, pSkillsTxtRecord->nPassiveIType);
        }
    }

    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nPassiveState, 1);
}

// 0x00646F20
void __stdcall SKILLS_RefreshPassiveSkills(D2UnitStrc* pUnit)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    D2SkillStrc* pSkill = 0;
    int nSkillId = 0;
    short nPassiveState = 0;
    int nPassiveSkills = sgptDataTables->nPassiveSkills;

    for (int i = 0; i < nPassiveSkills; ++i)
    {
        nSkillId = DATATBLS_GetPassiveSkillId(i);

        pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            nPassiveState = pSkillsTxtRecord->nPassiveState;
            if (nPassiveState > 0)
            {
                pSkill = SKILLS_GetHighestLevelSkillFromSkillId(pUnit, nSkillId);

                if (pSkill && STATES_CheckState(pUnit, nPassiveState))
                {
                    SKILLS_RefreshSkill(pUnit, nSkillId);
                }
            }
        }
    }
}

// 0x00646FD0
static void __stdcall sSkillsRemoveSkill(int nSkillId, int bDecrementAndCheckSkillLevel, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillListStrc* pSkillList = pUnit->pSkills;
    if (!pSkillList)
    {
        return;
    }

    D2SkillStrc* pSkill = pSkillList->pFirstSkill;
    if (!pSkill)
    {
        return;
    }

    if (const int nState = SKILLS_GetPassiveState(nSkillId))
    {
        STATES_ToggleState(pUnit, nState, 0);
    }

    if (const D2SkillStrc* pLeftSkill = pSkillList->pLeftSkill)
    {
        if (nSkillId == pLeftSkill->pSkillsTxt->nSkillId && pLeftSkill->nOwnerGUID == -1)
        {
            SKILLS_SetLeftActiveSkill(pUnit, SKILL_ATTACK, -1);
        }
    }

    if (const D2SkillStrc* pRightSkill = pSkillList->pRightSkill)
    {
        if (nSkillId == pRightSkill->pSkillsTxt->nSkillId && pRightSkill->nOwnerGUID == -1)
        {
            SKILLS_SetRightActiveSkill(pUnit, SKILL_ATTACK, -1);
        }
    }

    if (const D2SkillStrc* pUsedSkill = pSkillList->pUsedSkill)
    {
        if (nSkillId == pUsedSkill->pSkillsTxt->nSkillId && pUsedSkill->nOwnerGUID == -1)
        {
            pSkillList->pUsedSkill = 0;
        }
    }

    D2SkillStrc* pPreviousSkill = 0;
    do
    {
        if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == -1)
        {
            if (!bDecrementAndCheckSkillLevel || --pSkill->nSkillLevel <= 0)
            {
                if (pPreviousSkill)
                {
                    pPreviousSkill->pNextSkill = pSkill->pNextSkill;
                }
                else
                {
                    pSkillList->pFirstSkill = pSkill->pNextSkill;
                }

                FOG_FreePool(pUnit->pMemoryPool, pSkill, ".\\SKILLS\\Skills.cpp", 0x4AC, 0);
            }

            SKILLS_RefreshSkill(pUnit, nSkillId);
            return;
        }

        pPreviousSkill = pSkill;
        pSkill = pSkill->pNextSkill;
    }
    while (pSkill);

    SKILLS_RefreshSkill(pUnit, nSkillId);
}

// 0x006470F0
void __stdcall SKILLS_RemoveSkill(D2UnitStrc* pUnit, int nSkillId, const char* szFile, int nLine)
{
    sSkillsRemoveSkill(nSkillId, 1, pUnit);
}

// 0x00647280
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine)
{
    D2SkillStrc* pSkill;
    if (!nSkillLevel)
    {
        if (bRemove)
        {
            sSkillsRemoveSkill(nSkillId, 0, pUnit);
        }
        else
        {
            pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (!pSkill)
            {
                SKILLS_AddSkill(pUnit, nSkillId);
                pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                if (!pSkill)
                {
                    return;
                }
            }
            pSkill->nSkillLevel = 0;
        }
    }
    else
    {
        pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (pSkill || (pSkill = SKILLS_AddSkill(pUnit, nSkillId)) != 0)
        {
            pSkill->nSkillLevel = nSkillLevel;
        }
    }
    SKILLS_RefreshSkill(pUnit, nSkillId);
}

// 0x00647530
void __stdcall D2Common_10954(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bFreeMemory)
{
    SKILLS_UpdateChargedSkill(pUnit, nOwnerGUID, nSkillId, nSkillLevel, nCharges, bFreeMemory);
}

// 0x00647540
static BOOL D2Common_SKILLMANA_CheckStat_6FDB0F50(D2UnitStrc* pUnit, D2SkillStrc* hSkill)
{
    D2_ASSERT(hSkill, 0x637);

    if (hSkill->nOwnerGUID != -1)
    {
        return hSkill->nCharges > 0;
    }

    D2SkillsTxt* pSkillsTxt = hSkill->pSkillsTxt;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, hSkill, 1) - 1;
    D2_ASSERT(pSkillsTxt, 0x6EE);
    if (nSkillLevel < 0)
    {
        nSkillLevel = 0;
    }

    const int nRequiredMana = (pSkillsTxt->wMana + nSkillLevel * pSkillsTxt->wLevelMana) << pSkillsTxt->nManaShift;
    if (STATES_CheckState(pUnit, STATE_BLOOD_MANA))
    {
        return STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >= nRequiredMana;
    }

    if (pSkillsTxt->wSrvDoFunc == 0x74 && STATES_IsUnitShapeShifted(pUnit))
    {
        return 1;
    }

    return STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >= nRequiredMana;
}

// 0x00647840
static BOOL SKILLS_HasChargesLeft(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
    {
        return FALSE;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 1;
    }

    if (pSkill->nOwnerGUID == -1)
    {
        return 1;
    }

    const int nSkillId = pSkill->pSkillsTxt->nSkillId;
    const int nLayer = (nSkillId << 6) + (SKILLS_GetSkillLevel(pUnit, pSkill, FALSE) & 0x3F);
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pChargedItem = INVENTORY_UnitIsItem(pItem);
        if (pChargedItem && pChargedItem->dwUnitId == pSkill->nOwnerGUID)
        {
            return (STATLIST_UnitGetStatValue(pChargedItem, STAT_ITEM_CHARGED_SKILL, nLayer) & 0xFF) > 0;
        }
    }

    return 1;
}

// 0x00647960
int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* ptSkill)
{
    D2_ASSERT(ptSkill, 0x8E9);

    if (!ptSkill->pSkillsTxt || !SKILLS_HasFlag(ptSkill->pSkillsTxt, 10))
    {
        return 3;
    }

    if (!SKILLS_GetSkillLevel(pUnit, ptSkill, 1))
    {
        return 7;
    }

    if (SKILLS_HasFlag(ptSkill->pSkillsTxt, 5))
    {
        return 6;
    }

    if (SKILLS_HasFlag(ptSkill->pSkillsTxt, 4))
    {
        return 5;
    }

    if (!SKILLS_CheckSkillQuantity(pUnit, ptSkill))
    {
        return 2;
    }

    if (!SKILLS_CheckWeaponTypes(pUnit, ptSkill))
    {
        return 2;
    }

    if (!D2Common_SKILLMANA_CheckStat_6FDB0F50(pUnit, ptSkill))
    {
        return 1;
    }

    if (!D2Common_SKILLS_CheckShapeRestriction_6FDB1380(pUnit, ptSkill))
    {
        return 4;
    }

    if (!D2Common_SKILLMANA_CheckStartStat_6FDB1400(pUnit, ptSkill))
    {
        return 1;
    }

    if (!SKILLS_HasChargesLeft(pUnit, ptSkill))
    {
        return 2;
    }

    return SKILLS_CheckSkillDelay(ptSkill, pUnit) ? 0 : 8;
}

// 0x00647AA0
void __stdcall D2Common_11030(D2UnitStrc* pUnit, int nSkillId, int nLevelBonus)
{
    D2SkillStrc* pSkill = 0;

    if (pUnit)
    {
        pSkill = SKILLS_GetSkill(pUnit, nSkillId, -1);
        if (!pSkill)
        {
            if (nLevelBonus <= 0)
            {
                return;
            }

            pSkill = SKILLS_AddSkill(pUnit, nSkillId);
            if (!pSkill)
            {
                return;
            }

            D2SkillStrc* pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
            if (!pAssigned)
            {
                SKILLS_AddSkill(pUnit, nSkillId);
                pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
            }

            if (pAssigned)
            {
                pAssigned->nSkillLevel = 0;
                SKILLS_RefreshSkill(pUnit, nSkillId);
            }
        }

        if (pSkill->nOwnerGUID == -1)
        {
            pSkill->nLevelBonus = nLevelBonus;
            SKILLS_RefreshSkill(pUnit, nSkillId);
        }
    }
}

// 0x00645630
int __stdcall D2Common_11020(D2UnitStrc* pUnit)
{
    if (!CORPSE_CanUnitCorpseBeSelected(pUnit))
        return 0;
    return UNITS_IsSoftMonster(pUnit) != 0;
}

// 0x00645680
int __stdcall D2COMMON_11021(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int bCorpseSelectable = (nUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit)) ? MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL) : 0;
    if (!bCorpseSelectable)
    {
        return 0;
    }

    return 1;
}

// 0x006456D0
int __stdcall SKILLS_CanUnitCorpseBeSelected(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int bCorpseSelectable = (nUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD && !STATES_CheckStateMaskUdeadOnUnit(pUnit)) ? MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_CORPSESEL) : 0;
    if (!bCorpseSelectable)
    {
        return 0;
    }

    return 1;
}

// 0x00645720
int __stdcall D2Common_11024(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType, int* pHasThrowBonus)
{
    int nStatId = 0;
    D2StatStrc pStat[32];

    if (pHasThrowBonus)
    {
        *pHasThrowBonus = 0;
    }

    if (!pSkill)
    {
        pSkill = UNITS_GetUsedSkill(pUnit);
        if (!pSkill)
        {
            return 0;
        }
    }

    if (!ITEMS_CheckIfThrowable(pItem) || !pSkill)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = pSkill->pSkillsTxt;
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], ITEMTYPE_THROWN_WEAPON)
        || pSkillsTxtRecord->nAuraTargetState != 2)
    {
        return 0;
    }

    switch (nType)
    {
    case 0:
        nStatId = 345;
        break;
    case 1:
        nStatId = 346;
        break;
    case 2:
        nStatId = 347;
        break;
    default:
        return 0;
    }

    int nCount = STATLIST_CopyStats(pUnit, nStatId, pStat, 32);
    int nValue = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMSIsA(pItem, pStat[i].nLayer) && pStat[i].nValue > nValue)
        {
            nValue = pStat[i].nValue;
        }
    }

    if (pHasThrowBonus)
    {
        *pHasThrowBonus = 1;
    }

    return nValue;
}

static __forceinline void SKILLS_RemoveChargedSkill(D2UnitStrc* pUnit, D2SkillListStrc* pSkillList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nOwnerGUID)
{
    D2SkillStrc* pLeftSkill = pSkillList->pLeftSkill;
    D2SkillStrc* pRightSkill = pSkillList->pRightSkill;
    const int nRightSkillId = pRightSkill->pSkillsTxt->nSkillId;
    const int nLeftSkillId = pLeftSkill->pSkillsTxt->nSkillId;
    if (nSkillId == nLeftSkillId && pLeftSkill->nOwnerGUID == nOwnerGUID)
    {
        SKILLS_SetLeftActiveSkill(pUnit, SKILL_ATTACK, -1);
    }

    if (nSkillId == nRightSkillId && pRightSkill->nOwnerGUID == nOwnerGUID)
    {
        SKILLS_SetRightActiveSkill(pUnit, SKILL_ATTACK, -1);
    }

    if (pSkillList->pUsedSkill && nSkillId == pSkillList->pUsedSkill->pSkillsTxt->nSkillId)
    {
        pSkillList->pUsedSkill = 0;
    }

    D2SkillStrc* pPreviousSkill = 0;
    D2SkillStrc* pSkill = pSkillList->pFirstSkill;
    while (pSkill && (pSkill->nOwnerGUID != nOwnerGUID || pSkill->pSkillsTxt != pSkillsTxtRecord))
    {
        pPreviousSkill = pSkill;
        pSkill = pSkill->pNextSkill;
    }

    if (pSkill)
    {
        if (pPreviousSkill)
        {
            pPreviousSkill->pNextSkill = pSkill->pNextSkill;
        }
        else
        {
            pSkillList->pFirstSkill = pSkill->pNextSkill;
        }

        FOG_FreePool(pUnit->pMemoryPool, pSkill, ".\\SKILLS\\Skills.cpp", 1511, 0);
    }
}

// 0x00647320
void __stdcall SKILLS_UpdateChargedSkill(D2UnitStrc* pUnit, int nOwnerGUID, int nSkillId, int nSkillLevel, int nCharges, int bRemove)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    D2SkillListStrc* pSkillList = pUnit->pSkills;
    if (!pSkillList)
    {
        return;
    }

    if (bRemove)
    {
        SKILLS_RemoveChargedSkill(pUnit, pSkillList, pSkillsTxtRecord, nSkillId, nOwnerGUID);
        return;
    }

    D2SkillStrc* pPreviousSkill = 0;
    D2SkillStrc* pFoundSkill = pSkillList->pFirstSkill;
    while (pFoundSkill && (pFoundSkill->nOwnerGUID != nOwnerGUID || pFoundSkill->pSkillsTxt != pSkillsTxtRecord))
    {
        pPreviousSkill = pFoundSkill;
        pFoundSkill = pFoundSkill->pNextSkill;
    }

    if (pFoundSkill)
    {
        pFoundSkill->nSkillLevel = nSkillLevel;
        pFoundSkill->bExcludeFromHighestLevelLookup = 1;
        pFoundSkill->nCharges = nCharges;
        return;
    }

    D2SkillStrc* pSkill = (D2SkillStrc*)FOG_AllocPool(pSkillList->pMemPool, sizeof(D2SkillStrc), ".\\SKILLS\\Skills.cpp", 1534, 0);
    memset(pSkill, 0x00, sizeof(D2SkillStrc));
    pSkill->pSkillsTxt = pSkillsTxtRecord;
    switch ((signed char)pSkillsTxtRecord->nAnim)
    {
    case 7:
        pSkill->dwSkillMode = (signed char)pSkillsTxtRecord->nAnim;
        break;

    case 8:
        pSkill->dwSkillMode = (signed char)pSkillsTxtRecord->nAnim;
        break;

    case 10:
        pSkill->dwSkillMode = (signed char)pSkillsTxtRecord->nAnim;
        break;

    case 11:
        pSkill->dwSkillMode = (signed char)pSkillsTxtRecord->nAnim;
        break;

    case 18:
        pSkill->dwSkillMode = (signed char)pSkillsTxtRecord->nAnim;
        break;

    default:
        pSkill->dwSkillMode = 10;
        break;
    }

    pSkill->nSkillLevel = nSkillLevel;
    pSkill->bExcludeFromHighestLevelLookup = 1;
    pSkill->nCharges = nCharges;
    pSkill->nOwnerGUID = nOwnerGUID;
    pSkill->pNextSkill = 0;
    if (pPreviousSkill)
    {
        pPreviousSkill->pNextSkill = pSkill;
    }
    else
    {
        pSkillList->pFirstSkill = pSkill;
    }
}

// 0x00647640
static BOOL SKILLS_CheckSkillQuantity(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2UnitStrc* pItem;
    int nBodyLoc;
    BOOL bIsLeftHandItem;
    BOOL bContinue;

    if (!pUnit || !pSkill)
    {
        return FALSE;
    }

    D2SkillsTxt* pSkillsTxt = pSkill->pSkillsTxt;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pSkillsTxt && SKILLS_HasFlag(pSkillsTxt, 36))
    {
        BOOL bResult = FALSE;
        if (pInventory)
        {
            bResult = pSkill->nQuantity > 0;
        }

        return bResult;
    }

    switch (pSkillsTxt->nSkillId)
    {
    case SKILL_THROW:
        bContinue = FALSE;
        if (!pInventory)
        {
            return FALSE;
        }

        if (UNITS_CanDualWield(pUnit))
        {
            if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem))
            {
                if (!bIsLeftHandItem)
                {
                    pItem = SKILLS_GetOtherHandItem(nBodyLoc, pInventory);
                }

                if (pItem)
                {
                    bContinue = ITEMS_CheckIfThrowable(pItem);
                    if (!bContinue)
                    {
                        bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0);
                    }
                }
            }
        }
        else
        {
            if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem) && bIsLeftHandItem)
            {
                bContinue = ITEMS_CheckIfThrowable(pItem);
                if (!bContinue)
                {
                    bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0);
                }
            }
        }

        return bContinue;

    case SKILL_LEFTHANDTHROW:
        bContinue = FALSE;
        if (!pInventory)
        {
            return FALSE;
        }

        if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem))
        {
            if (bIsLeftHandItem)
            {
                D2UnitStrc* pOtherItem = SKILLS_GetOtherHandItem(nBodyLoc, pInventory);
                if (pOtherItem)
                {
                    bContinue = ITEMS_CheckIfThrowable(pOtherItem);
                    if (!bContinue)
                    {
                        bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pOtherItem, STAT_ITEM_THROWABLE, 0);
                    }
                }
            }
            else
            {
                bContinue = ITEMS_CheckIfThrowable(pItem);
                if (!bContinue)
                {
                    bContinue = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0);
                }
            }
        }

        return bContinue;

    case SKILL_LEFTHANDSWING:
        if (!pInventory || !UNITS_CanDualWield(pUnit))
        {
            return FALSE;
        }

        bContinue = FALSE;
        if (INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem))
        {
            if (bIsLeftHandItem)
            {
                D2UnitStrc* pOtherItem = SKILLS_GetOtherHandItem(nBodyLoc, pInventory);
                if (pOtherItem)
                {
                    bContinue = ITEMSIsA(pOtherItem, 0x2D);
                }
            }
            else
            {
                bContinue = ITEMSIsA(pItem, 0x2D);
            }
        }

        return bContinue;
    }

    return 1;
}

static inline BOOL U04_IsPlayerUnit(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

// 0x006478F0
static BOOL __stdcall SKILLS_CheckSkillDelay(D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    if (!U04_IsPlayerUnit(pUnit))
    {
        return 1;
    }

    if (!STATES_CheckState(pUnit, STATE_SKILLDELAY))
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxt = pSkill ? pSkill->pSkillsTxt : 0;
    if (!pSkillsTxt)
    {
        return 1;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwDelay, nSkillId, SKILLS_GetSkillLevel(pUnit, pSkill, 1)) <= 0;
}

// 0x00647BC0
int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 9))
    {
        int nDamage;
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            nDamage = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) + STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) - 20;
        }
        else
        {
            nDamage = 3 * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        }

        if (nDamage < 1)
        {
            nDamage = 1;
        }

        return nDamage / 4 << 8;
    }

    int nDamage = 0;
    if (pSkillsTxtRecord->nSrcDam && bAddWeaponDamage)
    {
        D2UnitStrc* pItem = D2Common_10434(pUnit, 0);
        int nWeaponDamage;
        if (pItem)
        {
            if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
                nWeaponDamage = STATLIST_GetMinDamageFromUnit(pItem, 1);
            else
                nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
        }
        else
        {
            nWeaponDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
        }
        nDamage = (nWeaponDamage * pSkillsTxtRecord->nSrcDam) / 128;
    }

    nDamage += pSkillsTxtRecord->dwMinDam + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwMinLvlDam);

    if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
    {
        const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);
        if (nBonus)
        {
            nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
        }
    }

    return nDamage << pSkillsTxtRecord->nToHitShift;
}

// 0x00647D00
int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordInl(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    int nDamage = 0;
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 9))
        {
            return SKILLS_GetKickDamage(pUnit, nDamage);
        }
        else
        {
            D2UnitStrc* const pSource = pUnit;
            if (pSkillsTxtRecord->nSrcDam && bAddWeaponDamage)
            {
                D2UnitStrc* pItem = D2Common_10434(pSource, 0);
                int nWeaponDamage = 0;
                if (pItem)
                {
                    if (INVENTORY_GetWieldType(pSource, pSource->pInventory) == 2)
                    {
                        nWeaponDamage = STATLIST_GetMaxDamageFromUnit(pItem, 24);
                    }
                    else
                    {
                        nWeaponDamage = STATLIST_UnitGetStatValue(pSource, STAT_MAXDAMAGE, 0);
                    }
                }
                else
                {
                    nWeaponDamage = STATLIST_UnitGetStatValue(pSource, STAT_MAXDAMAGE, 0);
                }
                nDamage = (nWeaponDamage * pSkillsTxtRecord->nSrcDam) / 128;
            }

            nDamage += pSkillsTxtRecord->dwMaxDam + SKILLS_CalculateDamageBonusByLevel(nSkillLevel, pSkillsTxtRecord->dwMaxLvlDam);

            if (pSkillsTxtRecord->dwDmgSymPerCalc != -1)
            {
                int nBonus = SKILLS_EvaluateSkillFormula(pSource, pSkillsTxtRecord->dwDmgSymPerCalc, nSkillId, nSkillLevel);

                if (nBonus)
                {
                    nDamage += DATATBLS_ApplyRatio(nDamage, nBonus, 100);
                }
            }

            return nDamage << pSkillsTxtRecord->nToHitShift;
        }
    }
}

static inline D2SkillStrc* SKILLS_GetSkillForceInl(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    D2SkillStrc* pSkill;
    if (pUnit->pSkills)
    {
        for (pSkill = pUnit->pSkills->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
        {
            if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            {
                goto found;
            }
        }
    }

    pSkill = 0;
found:
    return pSkill;
}

// 0x00647EE0
void __stdcall SKILLS_InitSkillList(D2UnitStrc* pUnit)
{
    D2CharStatsTxt* pCharStatsTxtRecord = 0;
    int nClass = 0;

    if (SKILLS_GetSkillInl(pUnit, SKILL_ATTACK, -1) == 0)
    {
        nClass = pUnit->dwClassId;
        if (nClass < 0 || nClass >= sgptDataTables->nCharStatsTxtRecordCount)
        {
            return;
        }

        pCharStatsTxtRecord = &sgptDataTables->pCharStatsTxt[nClass];
        if (!pCharStatsTxtRecord)
        {
            return;
        }

        SKILLS_AddSkill(pUnit, SKILL_ATTACK);

        for (int i = 0; i < 10; ++i)
        {
            short nSkillId = pCharStatsTxtRecord->nBaseSkill[i];
            if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
            {
                SKILLS_AddSkill(pUnit, nSkillId);
            }
        }
    }

    if (UNITS_GetLeftSkill(pUnit) == 0)
    {
        SKILLS_SetLeftActiveSkill(pUnit, SKILL_ATTACK, -1);
    }

    if (UNITS_GetRightSkill(pUnit) == 0)
    {
        SKILLS_SetRightActiveSkill(pUnit, SKILL_ATTACK, -1);
    }
}

// 0x00647110
D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
    if (nPassiveState)
    {
        STATES_ToggleState(pUnit, nPassiveState, 1);
    }

    D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit);
    while (pSkill && (pSkill->pSkillsTxt != pSkillsTxtRecord || pSkill->nOwnerGUID != -1))
    {
        pSkill = pSkill->pNextSkill;
    }

    if (!pSkill)
    {
        D2SkillListStrc* pSkillList = pUnit->pSkills;
        if (!pSkillList)
        {
            return 0;
        }

        pSkill = (D2SkillStrc*)sub_0040B430(pSkillList->pMemPool, sizeof(D2SkillStrc), ".\\SKILLS\\Skills.cpp", 1337, 0);
        memset(pSkill, 0x00, sizeof(D2SkillStrc));
        pSkill->pSkillsTxt = pSkillsTxtRecord;

        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            pSkill->dwSkillMode = (signed char)pSkillsTxtRecord->nMonAnim;
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwClassId == 6 && nSkillId == SKILL_LEFTHANDSWING)
        {
            pSkill->dwSkillMode = 16;
        }
        else
        {
            pSkill->dwSkillMode = (signed char)pSkillsTxtRecord->nAnim;
        }

        pSkill->nSkillLevel = 1;
        pSkill->nOwnerGUID = -1;
        pSkill->pNextSkill = 0;

        D2SkillStrc* pPreviousSkill = pSkillList->pFirstSkill;
        if (pPreviousSkill)
        {
            while (pPreviousSkill->pNextSkill)
            {
                pPreviousSkill = pPreviousSkill->pNextSkill;
            }
            pPreviousSkill->pNextSkill = pSkill;
        }
        else
        {
            pSkillList->pFirstSkill = pSkill;
        }

        SKILLS_RefreshSkill(pUnit, nSkillId);
        return pSkill;
    }

    const int nSkillLevel = pSkill->nSkillLevel;
// build: symbol ?SPELLSEL_GetSkillMaxLevel@* 0x004AA8B0
    if (nSkillLevel < SPELLSEL_GetSkillMaxLevel(nSkillId) || pUnit->dwUnitType == UNIT_MONSTER)
    {
        pSkill->nSkillLevel = nSkillLevel + 1;
    }

    SKILLS_RefreshSkill(pUnit, nSkillId);
    return pSkill;
}

inline D2SkillStrc* __fastcall SKILLS_GetSkillInl(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (pUnit->pSkills)
    {
        for (D2SkillStrc* pSkill = pUnit->pSkills->pFirstSkill; pSkill; pSkill = pSkill->pNextSkill)
        {
            if (pSkill->pSkillsTxt->nSkillId == nSkillId && pSkill->nOwnerGUID == nOwnerGUID)
            {
                return pSkill;
            }
        }
    }

    return 0;
}

// 0x00647B20
void __stdcall D2Common_11031(D2UnitStrc* pUnit, int nSkillId, int a3)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillForceInl(pUnit, nSkillId, -1);

    if (!pSkill)
    {
        if (a3 <= 0)
        {
            return;
        }

        pSkill = SKILLS_AddSkill(pUnit, nSkillId);
        if (!pSkill)
        {
            return;
        }

        D2SkillStrc* pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
        if (!pAssigned)
        {
            SKILLS_AddSkill(pUnit, nSkillId);
            pAssigned = SKILLS_GetSkill(pUnit, nSkillId, -1);
        }

        if (pAssigned)
        {
            pAssigned->nSkillLevel = 0;
            SKILLS_RefreshSkill(pUnit, nSkillId);
        }
    }

    if (pSkill->nOwnerGUID == -1)
    {
        pSkill->nLevelBonus += a3;
        if (pSkill->nLevelBonus < 0)
        {
            pSkill->nLevelBonus = 0;
        }
    }
}

// 0x00647E00
int __stdcall D2Common_11032(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nType)
{
    unsigned short nThrowStatId = 0;
    unsigned short nMeleeStatId = 0;
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    {
        switch (nType)
        {
        case 0:
            nMeleeStatId = 342;
            nThrowStatId = 345;
            break;
        case 1:
            nMeleeStatId = 343;
            nThrowStatId = 346;
            break;
        case 2:
            nMeleeStatId = 344;
            nThrowStatId = 347;
            break;
        default:
            return 0;
        }

        int i = 0;
        for (i = 0; i < 5; ++i)
        {
            if (pSkillsTxtRecord->nPassiveStat[i] == nMeleeStatId || pSkillsTxtRecord->nPassiveStat[i] == nThrowStatId)
            {
                break;
            }
        }

        if (i >= 5)
        {
            return 0;
        }

        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
    }
}

// 0x00645830
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType)
{
    int nStatId = 0;
    D2StatStrc pStat[32];

    if (pUnit && pItem)
    {
        if (!pSkill)
        {
            pSkill = UNITS_GetUsedSkill(pUnit);
        }

        int bHasThrowBonus = 0;
        int nThrowBonus = D2Common_11024(pUnit, pItem, pSkill, nType, &bHasThrowBonus);
        if (bHasThrowBonus)
        {
            return nThrowBonus;
        }

        switch (nType)
        {
        case 0:
            nStatId = 342;
            break;
        case 1:
            nStatId = 343;
            break;
        case 2:
            nStatId = 344;
            break;
        default:
            return 0;
        }

        int nCount = STATLIST_CopyStats(pUnit, nStatId, pStat, 32);
        int nValue = 0;
        for (int i = 0; i < nCount; ++i)
        {
            if (ITEMSIsA(pItem, pStat[i].nLayer) && pStat[i].nValue > nValue)
            {
                nValue = pStat[i].nValue;
            }
        }

        return nValue;
    }

    return 0;
}

// 0x00645910
int __stdcall D2Common_11025(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int a6)
{
    D2CoordStrc pCoords1;
    D2CoordStrc pCoords2;

    pCoords1.nX = nX1;
    pCoords1.nY = nY1;
    pCoords2.nX = nX2;
    pCoords2.nY = nY2;

    return COLLISION_RayTrace(pRoom, &pCoords1, &pCoords2, a6) == 0;
}

// 0x00645950
int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nColMask)
{
    int nUnitY = UNITS_GetYPositionInl(pUnit);
    int nUnitX = UNITS_GetXPositionInl(pUnit);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2CoordStrc pCoords1;
    D2CoordStrc pCoords2;

    pCoords1.nX = nX;
    pCoords1.nY = nY;
    pCoords2.nX = nUnitX;
    pCoords2.nY = nUnitY;

    return COLLISION_RayTrace(pRoom, &pCoords1, &pCoords2, nColMask) == 0;
}

// 0x006459F0
int __stdcall SKILLS_GetShiftedManaCosts(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* ptSkill = DATATBLS_GetSkillsTxtRecord(nSkillId);
    SKILLS_ASSERT(ptSkill, 4108);

    int nMana = ((ptSkill->wMana + (nSkillLevel - 1) * ptSkill->wLevelMana) << ptSkill->nManaShift) >> 8;
    if (nMana < 0)
    {
        nMana = 0;
    }

    return nMana;
}

// 0x00645A70
int __stdcall D2Common_11028(int nLevel)
{
    return 20 * (5 * nLevel + 5) / (nLevel + 8);
}

// 0x00645A90
int __fastcall SKILLS_GetDiminishingValue(int nLevel, int nMin, int nMax)
{
    int nValue = nMin + (nMax - nMin) * (110 * nLevel / (nLevel + 6)) / 100;
    int nPrevValue = nMin + (nMax - nMin) * (110 * (nLevel - 1) / (nLevel - 1 + 6)) / 100;

    if (nValue <= nPrevValue + 1)
    {
        return SKILLS_GetDiminishingValue(nLevel - 1, nMin, nMax) + 1;
    }

    if (nValue > nMax)
    {
        nValue = nMax;
    }

    return nValue;
}

// 0x00645B20
int __stdcall D2Common_11033(int nLevel, int nParam, int nMax)
{
    int nValue = nParam + (nMax - nParam) * (110 * nLevel / (nLevel + 6)) / 100;

    if (nValue > nMax)
    {
        nValue = nMax;
    }

    return nValue;
}

int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A470

// 0x00645B70
int __stdcall D2Common_11034(int nLevel, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return D2Common_11033(nLevel, pSkillsTxtRecord->dwParam[0], pSkillsTxtRecord->dwParam[1]);
}

// 0x00645BC0
int __stdcall D2Common_11035(int nLevel, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return D2Common_11033(nLevel, pSkillsTxtRecord->dwParam[2], pSkillsTxtRecord->dwParam[3]);
}

// 0x00645C10
int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return D2Common_11033(nLevel, pSkillsTxtRecord->dwParam[4], pSkillsTxtRecord->dwParam[5]);
}

// 0x00645C60
static int __stdcall SKILLS_IsPointOutsideTown(int nX, int nY, D2UnitStrc* pUnit)
{
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

    return !DUNGEON_IsRoomInTown(pRoom);
}

// 0x00645CA0
int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY)
{
    struct { int n; } tX2 = {}, tY2 = {};

    if (pUnit2 && UNITS_IsInMeleeRange(pUnit1, pUnit2, 0))
    {
        return 0;
    }

    const int nX1 = UNITS_GetXPositionForceInl(pUnit1);
    const int nY1 = UNITS_GetYPositionForceInl(pUnit1);

    if (pUnit2)
    {
        tX2.n = UNITS_GetXPositionForceInl(pUnit2);
        tY2.n = UNITS_GetYPositionForceInl(pUnit2);
    }
    else
    {
        tX2.n = D2COMMON_10175_PathGetFirstPointX(pUnit1->pDynamicPath);
        tY2.n = D2COMMON_10176_PathGetFirstPointY(pUnit1->pDynamicPath);
    }

    const int nDivisor = DRLG_GetDistanceToXY(pUnit1, tX2.n, tY2.n);
    if (!nDivisor)
    {
        return 0;
    }

    int nX = tX2.n + 2 * (tX2.n - nX1) / nDivisor;
    int nY = tY2.n + 2 * (tY2.n - nY1) / nDivisor;

    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pUnit1);
    D2_ASSERT(hRoom, 4286);

    const int nPattern = PATH_GetUnitCollisionPattern(pUnit1);
    if (COLLISION_CheckAnyCollisionWithPattern(hRoom, nX, nY, nPattern, COLLIDE_MASK_PLAYER_PATH))
    {
        D2CoordStrc tCoord;
        tCoord.nX = tX2.n;
        tCoord.nY = tY2.n;
        hRoom = COLLISION_GetFreeCoordinates(hRoom, &tCoord, UNITS_GetUnitSizeX(pUnit1), COLLIDE_MASK_PLAYER_PATH, 0);
        if (!hRoom)
        {
            return 0;
        }
        nX = tCoord.nX;
        nY = tCoord.nY;
    }

    if (!sub_00645910_TestLine(UNITS_GetXPositionForceInl(pUnit1), UNITS_GetYPositionForceInl(pUnit1), nX, nY, hRoom, COLLIDE_MASK_LINE))
    {
        return 0;
    }

    *pX = nX;
    *pY = nY;
    return SKILLS_IsPointOutsideTown(nX, nY, pUnit1) != 0;
}

// 0x00645F00
int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue)
{
    int nWeaponClass = 0;
    int nValue = 0;

    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_MAGICARROW, 0);
        if (nValue > 0)
        {
            if (pValue)
            {
                *pValue = nValue;
            }
            return 27;
        }

        nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_EXPLOSIVEARROW, 0);
        if (nValue > 0)
        {
            if (pValue)
            {
                *pValue = nValue;
            }
            return 41;
        }

        return 0;
    }
    else
    {
        nWeaponClass = UNITS_GetWeaponClass(pUnit);
        if (nWeaponClass == 1)
        {
            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_MAGICARROW, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 27;
            }

            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_EXPLOSIVEARROW, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 41;
            }

            return 0;
        }
        else if (nWeaponClass == 7)
        {
            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_MAGICARROW, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 27;
            }

            nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_EXPLOSIVEARROW, 0);
            if (nValue > 0)
            {
                if (pValue)
                {
                    *pValue = nValue;
                }
                return 41;
            }

            return 31;
        }

        return -1;
    }
}

int __stdcall PATH_ComputeDirectionFromPreciseCoords_6FDAC760(unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY); // 0x0064FE10

// 0x00645FB0
int __stdcall SKILLS_IsEnhanceable(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 17);
}

// 0x00645FF0
int __stdcall sub_00645FF0_AlwaysZero(int nUnused)
{
    return 0;
}

// 0x00646000
int __stdcall SKILLS_Return0(int nUnused)
{
    return 0;
}

// 0x00646010
void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

// 0x00646020
int __stdcall SKILLS_RemoveTransformStatesFromShapeshiftedUnit(D2UnitStrc* pUnit)
{
    if (!STATES_IsUnitShapeShifted(pUnit))
    {
        return 0;
    }

    for (int i = 0; i < sgptDataTables->nTransformStates; ++i)
    {
        short nState = sgptDataTables->pTransformStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            STATES_ToggleState(pUnit, nState, 0);
        }
    }

    return 1;
}

// 0x006460B0
extern "C" void __stdcall sub_006460B0(unsigned arg0,unsigned arg1,unsigned arg2) {}

// 0x006460C0
void __stdcall sub_006460C0_Empty(int nUnused)
{
}

// 0x006460D0
void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

// 0x006460E0
void __stdcall sub_006460E0_Empty(int nUnused)
{
}

// 0x006460F0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition)
{
    if (nClassId >= 0 && nClassId < 7)
    {
        if (nPosition >= 0 && nPosition < sgptDataTables->nClassSkillCount[nClassId])
        {
            return sgptDataTables->nClassSkillList[nPosition + nClassId * sgptDataTables->nHighestClassSkillCount];
        }

        return -1;
    }

    return -1;
}

// 0x00646140
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId)
{
    if (nClassId >= 0 && nClassId < 7)
    {
        return sgptDataTables->nClassSkillCount[nClassId];
    }

    return 0;
}

// 0x00646170
unsigned int __stdcall D2Common_11043(D2UnitStrc* pUnit)
{
    D2UnitStrc* pItem = 0;
    int nAttackSpeed;

    int bShapeShifted = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        bShapeShifted = STATES_IsUnitShapeShifted(pUnit);
    }

    if (!bShapeShifted)
    {
        return 0;
    }

    nAttackSpeed = 19;
    pItem = D2Common_10434(pUnit, 0);
    if (pItem)
    {
        nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pUnit, pItem);
        if (nAttackSpeed <= 0)
        {
            return 0;
        }
    }

    return (pUnit->dwFrameCountPrecise & ~0xFF) / nAttackSpeed;
}

// 0x006461D0
int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId)
{
    if (!STATES_CheckState(pUnit, STATE_CONCENTRATION))
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONCENTRATION);
    if (!pStatList)
    {
        return 0;
    }

    int nDamagePercent = STATLIST_GetStatValue(pStatList, STAT_DAMAGEPERCENT, 0);
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    int nParam;
    if (!pSkillsTxtRecord)
    {
        nParam = 0;
    }
    else
    {
        nParam = pSkillsTxtRecord->dwParam[0];
    }

    return nDamagePercent * nParam / 8;
}

// 0x00646260
int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646270
int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00646280
void __stdcall SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent)
{
    if (!pUnit)
    {
        return;
    }

    const int nKickDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_KICKDAMAGE, 0);
    *pMinDamage += nKickDamage;
    *pMaxDamage += nKickDamage;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    int nValue;
    D2UnitStrc* pLeftHand = INVENTORY_GetLeftHandWeapon(pInventory);
    D2UnitStrc* pOtherHand = 0;
    if (pLeftHand)
    {
        nValue = ITEMS_GetBodyLocation(pLeftHand);
        pOtherHand = INVENTORY_GetItemFromBodyLoc(pInventory, (nValue == 4) + 4);
    }

    if (ITEMSIsA(pLeftHand, 0x2D) && ITEMS_CanBeEquipped(pLeftHand) && STATLIST_GetOwner(pLeftHand, 0))
    {
        STATLIST_MergeStatLists(pUnit, pLeftHand, 0);
    }
    else
    {
        pLeftHand = 0;
    }

    if (pOtherHand && pOtherHand != pLeftHand && ITEMSIsA(pOtherHand, 0x2D) && ITEMS_CanBeEquipped(pOtherHand) && STATLIST_GetOwner(pOtherHand, 0))
    {
        STATLIST_MergeStatLists(pUnit, pOtherHand, 0);
    }

    D2UnitStrc* pBoots = INVENTORY_GetItemFromBodyLoc(pInventory, 9);
    if (pBoots && pBoots->dwUnitType == UNIT_ITEM)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pBoots ? -1 : pBoots->dwClassId);
        if (pItemsTxtRecord)
        {
            int nMin = nKickDamage + pItemsTxtRecord->nMinDam;
            int nMax = nKickDamage + pItemsTxtRecord->nMaxDam;
            int nBonus = 0;
            nValue = ITEMS_GetStrengthBonus(pBoots);
            if (nValue)
            {
                nBonus = DATATBLS_ApplyRatio(STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0), nValue, 100);
            }

            nValue = ITEMS_GetDexBonus(pBoots);
            if (nValue)
            {
                nBonus += DATATBLS_ApplyRatio(STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0), nValue, 100);
            }

            nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
            if (nBonus <= -90)
            {
                nBonus = -90;
            }

            const int nPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
            if (nMin >= nMax)
            {
                nMax = nMin;
            }

            *pDamagePercent += nPercent + nBonus;
            *pMinDamage += nMin;
            *pMaxDamage += nMax;
        }
    }

    if (pLeftHand)
    {
        STATLIST_MergeStatLists(pUnit, pLeftHand, 1);
    }
}

// 0x0064EFE0
void __fastcall SKILLS_FixThrowWeaponClassCode(unsigned int* pWeaponClassCode, int nUnused, int nMode)
{
    if (nMode == PLRMODE_THROW)
    {
        if (*pWeaponClassCode != ' sh1' && *pWeaponClassCode != ' th1' && *pWeaponClassCode != ' sj1' && *pWeaponClassCode != ' tj1' && *pWeaponClassCode != ' ss1' && *pWeaponClassCode != ' ts1')
        {
            *pWeaponClassCode = ' hth';
        }
    }
}

#include "gen/data/Source/D2Common/SKILLS/Skills.inc"
