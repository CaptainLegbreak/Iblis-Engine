#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2GameObjs.h"
#include "D2GameRecords.h"
#include "D2Skills.h"
#include "D2Primitives.h"
#include "FogApi.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define MONSTATSFLAGINDEX_NOAURA 27


#define DAMAGERESULTFLAG_SUCCESSFULHIT 1


#define STATE_BLOODMANA 114

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


#define SKILLSFLAGINDEX_AURA 5

#define SKILLSFLAGINDEX_PERIODIC 6

#define EVENTTYPE_PERIODICSTATS 9

struct D2PoolSystemStrc;
struct D2SkillListStrc;

struct D2UnitFindArgStrc;

struct D2StaticPathStrc;

struct D2DrlgCoordsStrc;

struct D2AuraCallbackStrc;

struct D2SkillsTxt;

struct D2_6FD106F0_Strc;

struct D2AuraNextTargetArgsStrc;

struct D2MonStatsTxt;

struct D2CharStatsTxt;

struct D2StatesTxt;


struct D2PetTypeTxt;

struct D2ObjectDataStrc;

struct D2MonsterDataStrc;

struct D2MissilesTxt;


struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DamageStrc;

struct D2DataTablesStrc;

struct D2MissileStrc;

struct D2UnitFindDataStrc;

struct D2ItemDropStrc;

union D2SeedStrc;

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740


int __fastcall SKILLS_ConsumeItemQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0056C310


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0

D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bSkipCheck); // 0x0056EE90

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0

void __fastcall SKILLS_ApplyWeaponBonusToMissile(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon); // 0x0056C600


int __fastcall SKILLS_ExecuteSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyCosts, int bSkipSkillCheck, int bItemEffect); // 0x0056F7F0

int __fastcall SKILLS_SchedulePeriodicStat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventKey, int nSkillId, int nSkillLevel, int bUseRightSkill); // 0x0056CE70


struct D2_6FD106F0_Strc
{
    D2UnitStrc* pUnit;
    int nDistance;
    int nX;
    int nY;
    int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*);
};

struct D2AuraNextTargetArgsStrc
{
    D2UnitStrc* pNextTarget;
    unsigned int nNextGUID;
    D2UnitStrc* pWrapTarget;
    unsigned int nWrapGUID;
    unsigned int nPreviousGUID;
    int nTargetCount;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall D2GAME_SKILLS_BloodMana(D2UnitStrc* pUnit, int nManaCost); // 0x005D2B60

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const int gnMissilePatternSignX[4]; // 0x006E1510

extern const int gnMissilePatternSignY[4]; // 0x006E14E4

extern const int gnMissilePatternOffsets1[7]; // 0x006E14F4

extern const int gnMissilePatternOffsets2[7]; // 0x006E14C8

extern const int gnMissilePatternXOffsets[8]; // 0x006E14A8

extern const int gnMissilePatternYOffsets[8]; // 0x006E1488

void __fastcall FOG_FreeServerMemory(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480


void __fastcall SUNIT_RewindAnimationByPercentage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x00553B10

int __fastcall AIUTIL_CanUnitSwitchAi(D2UnitStrc* pUnit, int nArg); // 0x005DD480

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150


void __fastcall AIGENERAL_DetachOwnedMinions(D2UnitStrc* pUnit); // 0x0058F260


typedef int (__stdcall* FARPROC)();


extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

void __stdcall UNITFINDS_InitializeUnitFindData(D2PoolSystemStrc* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950

typedef void (__fastcall* SKILLS_AREAEFFECTFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel, int nParam);

extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int petType); // 0x00478A20


typedef char H15_CheckSkillsTxtSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char H15_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];

typedef char H15_CheckSkillsCount[(int)&((D2DataTablesStrc*)0)->nSkillsTxtRecordCount == 0xBA0 ? 1 : -1];

enum
{
    UNITFLAG_TARGETABLE = 0x00000002,
    SKILLSFLAGINDEX_INTOWN = 8,
    SKILLSFLAGINDEX_TARGETABLEONLY = 20,
    SKILLSFLAGINDEX_TARGETCORPSE = 24,
    SKILLSFLAGINDEX_TARGETALLY = 26,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268



int __fastcall QUESTS_PortalCheck(D2GameStrc* pGame, D2CoordStrc* pCoord, int nLevel, D2ActiveRoomStrc** ppRoom); // 0x00545830

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230

void __fastcall SUNIT_LinkPortalCoordinates(D2UnitStrc* pFirst, D2UnitStrc* pSecond); // 0x00553590

int __fastcall SKILLS_SchedulePeriodicSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bUseRightSkill); // 0x0056CDA0



typedef int (__fastcall *SkillCallback)(D2GameStrc*, D2UnitStrc*, int, int);

extern const SkillCallback gpSkillCallbacks_007322B0[]; // 0x007322B0

extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId); // 0x00452040

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

static void __stdcall D2GAME_SKILLS_SetDelay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay); // 0x0056EF90


void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0


void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0


#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

struct D2SkillStrc;

struct D2StatListStrc;




static int __stdcall SKILLS_ConsumeItemSkillCharge(D2GameStrc*, D2SkillStrc*, int, D2UnitStrc*);


#define SKILLSRVDO_SHAPESHIFT 116


#define SKILLSFLAGINDEX_IMMEDIATE 15

int __fastcall D2GAME_RollElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

struct D2CurseStrc;

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0


extern "C" const char gszSkillsSourceFile; // 0x006DAB88

static void __stdcall SKILLS_StartAssignedAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId);


enum D2C_ElemTypes
{
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

extern const int gnRandomElemTypes[4]; // 0x006E1278

typedef void (__fastcall* CurseCallbackFunc)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int);

typedef char SkillsRecordSize[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef int (__fastcall* SkillStartFunc)(D2GameStrc*, D2UnitStrc*, int, int);

extern SkillStartFunc gpfnSkillSrvStartFunctions[]; // 0x00732140

int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit); // 0x0056C160


static int __stdcall SKILLS_CheckUsedSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId);


#define SKILLSRVDOFN_COUNT 191

#define EVENTFN_COUNT 50

#define EVENTTYPE_AITHINK 2

#define UNITFLAG_NOTC 0x00020000

#define UNITFLAG_ISREVIVE 0x80000000

struct D2PortalFlagsStrc;

struct D2SummonArgStrc;

struct D2ModeChangeStrc;

struct D2PetTypeSkillListStrc
{
    char unk0x00[0xBC];
    int nSkillCount;
    short wSkillIds[15];
    unsigned short unk0xDE;
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

typedef int (__fastcall* SkillDoFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int a6, int a7);

typedef int (__fastcall* UNITFINDTEST)(D2UnitStrc* pUnit, D2UnitFindArgStrc* pUnitFindArg);

extern SkillDoFunc gpfnSkillSrvDoFunctions[SKILLSRVDOFN_COUNT]; // 0x007322B0

extern const D2UnitEventCallbackFunction gpfnSkillEventCallbacks[EVENTFN_COUNT]; // 0x007325B0

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0

int __fastcall SKILLS_AuraCallback_ApplyAreaDamage(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BA90

int __fastcall SKILLS_AuraCallback_FindClosestTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BB20

int __fastcall SKILLS_AuraCallback_CountTargets(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BC70

int __fastcall SKILLS_AuraCallback_FindNextTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x0056BCD0

int __fastcall SKILLS_UnitFindTest_Corpse(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg); // 0x0056E370




int __stdcall D2GAME_Transmogrify(D2UnitStrc* pItem); // 0x00563FE0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380


D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int nEventKey); // 0x005C0AD0

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

D2UnitStrc* __fastcall D2GAME_CreateLinkPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel); // 0x0056CF40

struct D2PortalFlagsStrc
{
    unsigned char nFlags;
};

unsigned int __fastcall SUNIT_GetTrackedSummonGUID(D2UnitStrc* hUnit); // 0x00554070

void __fastcall SUNIT_SetTrackedSummonGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00554040


D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


#define UNITFLAG_SKSRVDOFUNC 0x00000040


unsigned int __stdcall sub_006417F0(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0


int __fastcall SKILLS_DrainTargetDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel); // 0x0056C2D0



typedef int (__fastcall* SKILLDOFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

typedef int (__fastcall* SKILLSTARTFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern SKILLSTARTFUNC gpfnSkillSrvStartFunctions[];                                                    // 0x00732140

D2MissilesTxt* __fastcall sub_0046ACE0_GetMissilesTxtRecord(int nMissileId);                          // 0x0046ACE0


#define EVENTTYPE_REMOVESTATE 12

#define SKILLSFLAGINDEX_DECQUANT 0

#define SKILLSFLAGINDEX_LOB 1

#define SKILLSFLAGINDEX2_USEMANAONDO (32 + 5)

#define SKILLS_CHECK_FLAG(pRecord, nIndex) ((pRecord)->nFlags[(nIndex) >> 3] & gdwBitMasks[(nIndex) & 7])

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

#define MONTYPEFLAG_UNIQUE 8

#define EVENTTYPE_REMOVESTATE 0x0C

#define UNITFLAG_DOUPDATE 1

#define D2_MIN(a,b) ((a)<(b)?(a):(b))

#define D2_MAX(a,b) ((a)>(b)?(a):(b))

struct D2ServerCallbacks;


int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);



typedef void (__fastcall* LevelCallback)(unsigned int, int);

struct D2ServerCallbacks
{
    char unk_00[44];
    LevelCallback levelUp;
};

extern D2ServerCallbacks* gpServerCallbacks; // 0x00883D50

extern const unsigned int gdwInvBitMasks[]; // 0x006CE2E8






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

static inline int SKILLS_IsInRangeY(int nY, int nDistance, const D2DrlgCoordsStrc& drlgCoords)
{
    return nY + nDistance >= drlgCoords.nSubtileY || nY - nDistance <= drlgCoords.nSubtileY + drlgCoords.nSubtileHeight;
}

// 0x0056B6C0
void __fastcall SKILLS_ClampVitalsAndUpdateAnimRate(D2UnitStrc* pUnit)
{
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) > nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) > nMaxMana)
    {
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) > nMaxStamina)
    {
        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
    }

    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 267);
}

struct D2UnkCallRecordStrc;

struct D2UnkCallRecordStrc
{
    void* pArg1;
    void* pArg2;
    int nZero;
    int nArg4;
};

// 0x0056B740
int __fastcall SKILLS_ApplyAuraToSelf(void* pArg1, void* pArg2, int (__fastcall* pfnCallback)(D2UnkCallRecordStrc*), int nArg4)
{
    D2UnkCallRecordStrc record;
    record.pArg1 = pArg1;
    record.pArg2 = pArg2;
    record.nArg4 = nArg4;
    record.nZero = 0;
    return pfnCallback(&record);
}

// 0x0056B770
static int SKILLS_IsRoomInRange(D2ActiveRoomStrc* pRoom, int nX, int nY, int nDistance)
{
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    if (nX + nDistance >= drlgCoords.nSubtileX)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    if (nX - nDistance <= drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        return SKILLS_IsInRangeY(nY, nDistance, drlgCoords);
    }
    return 0;
}

// 0x0056B7E0
void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int (__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine)
{
    if (!pGame || !pUnit || !pCallback || nAuraRange <= 0)
    {
        return;
    }

    D2ActiveRoomStrc* pCurrentRoom = UNITS_GetRoom(pUnit);
    if (!pCurrentRoom)
    {
        return;
    }

    if (!nX || !nY)
    {
        nX = CLIENTS_GetUnitX(pUnit);
        nY = CLIENTS_GetUnitY(pUnit);
    }

    if (!nAuraFilter)
    {
        nAuraFilter = 0x583;
    }

    D2AuraCallbackStrc auraCallback;
    auraCallback.pArgs = pCallbackArgs;
    auraCallback.pGame = pGame;
    auraCallback.pOwner = pUnit;
    auraCallback.nCounter = 0;
    const int nAuraRangeSq = nAuraRange * nAuraRange;

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pCurrentRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if (!(nAuraFilter & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (SKILLS_IsRoomInRange(ppRoomList[i], nX, nY, nAuraRange))
            {
                D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst;
                while (pTarget)
                {
                    D2UnitStrc* pNextTarget = pTarget->ptRoomNext;
                    if (pTarget != pUnit && nAuraRangeSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(pTarget), UNITS_GetUnitYPosition(pTarget)) && SKILLS_CheckAuraTarget(pUnit, pTarget, nAuraFilter))
                    {
                        if (!bCheckMonAuraFlag || pTarget->dwUnitType != UNIT_MONSTER || !MONSTERUNIQUE_CheckMonStatsFlag(pTarget->dwClassId, MONSTATSFLAGINDEX_NOAURA))
                        {
                            if (pCallback(&auraCallback, pTarget))
                            {
                                auraCallback.nCounter += 1;
                            }
                        }
                    }
                    pTarget = pNextTarget;
                }
            }
        }
    }
}

// 0x0056B9C0
void __fastcall SKILLS_ApplyDamageToTarget(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused)
{
    if (!pAttacker)
    {
        return;
    }

    if (!pUnit)
    {
        return;
    }

    if (pAttacker->dwUnitType == UNIT_MISSILE)
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pAttacker);
        if (pOwner)
        {
            pAttacker = pOwner;
        }
    }

    if ((pDamage->wResultFlags == 0) & 1)
    {
        return;
    }

    const int nBlockFlags = SUNITDMG_ApplyBlockOrDodge(pGame, pAttacker, pUnit, 1, 0);
    if (nBlockFlags & 2)
    {
        pDamage->wResultFlags |= 0x100;
    }

    if (nBlockFlags & 4)
    {
        pDamage->wResultFlags |= 0x80;
    }

    if (nBlockFlags & 0x10)
    {
        pDamage->wResultFlags |= 0x8000;
    }

    if (nBlockFlags & 1)
    {
        pDamage->wResultFlags |= 0x10;
    }

    if (nBlockFlags)
    {
        pDamage->wResultFlags &= ~DAMAGERESULTFLAG_SUCCESSFULHIT;
    }

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT && !STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        pDamage->wResultFlags |= 4;
    }

    D2GAME_MONSTER_ApplyCriticalDamage(pAttacker, pUnit, pDamage);

    if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, pDamage);
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, pDamage);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0056BA90
int __fastcall SKILLS_AuraCallback_ApplyAreaDamage(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageStrc damage = *(D2DamageStrc*)pAuraCallback->pArgs;
    SKILLS_ApplyDamageToTarget(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0);
    return 1;
}

// 0x0056BAD0
int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter)
{
    if (!nAuraFilter)
    {
        nAuraFilter = 0x8583;
    }

    if (pUnit)
    {
        SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter, SKILLS_AuraCallback_ApplyAreaDamage, pDamage, 0, ".\\SKILLS\\Skills.cpp", 539);
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

// 0x0056BB20
int __fastcall SKILLS_AuraCallback_FindClosestTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2_6FD106F0_Strc* pArgs = (D2_6FD106F0_Strc*)pAuraCallback->pArgs;

    if (!pArgs->pCallback || pArgs->pCallback(pAuraCallback->pGame, pUnit))
    {
        const int nXDiff = CLIENTS_GetUnitXInline(pUnit) - pArgs->nX;
        const int nYDiff = CLIENTS_GetUnitYInline(pUnit) - pArgs->nY;

        const int nDistance = nXDiff * nXDiff + nYDiff * nYDiff;
        if (nDistance < pArgs->nDistance)
        {
            pArgs->nDistance = nDistance;
            pArgs->pUnit = pUnit;
        }

        return 1;
    }

    return 0;
}

// 0x0056BBC0
D2UnitStrc* __fastcall SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAuraRange, int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*))
{
    D2_6FD106F0_Strc arg;
    arg.pUnit = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.nX = CLIENTS_GetUnitXInline(pUnit);
    arg.nY = CLIENTS_GetUnitYInline(pUnit);
    arg.pCallback = pCallback;

    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, 0x8783, SKILLS_AuraCallback_FindClosestTarget, &arg, 0, ".\\SKILLS\\Skills.cpp", 696);

    return arg.pUnit;
}

// 0x0056BC70
int __fastcall SKILLS_AuraCallback_CountTargets(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    ++*(int*)pAuraCallback->pArgs;
    return 1;
}

// 0x0056BC80
int __fastcall SKILLS_CountAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter)
{
    int nSkillId = 0;

    SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter | 0xA783, SKILLS_AuraCallback_CountTargets, &nSkillId, 0, ".\\SKILLS\\Skills.cpp", 736);

    return nSkillId;
}

// 0x0056BCD0
int __fastcall SKILLS_AuraCallback_FindNextTarget(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2AuraNextTargetArgsStrc* pArgs = (D2AuraNextTargetArgsStrc*)pAuraCallback->pArgs;

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;

    if ((unsigned int)nUnitGUID <= pArgs->nPreviousGUID || (unsigned int)nUnitGUID >= pArgs->nNextGUID)
    {
        if ((unsigned int)nUnitGUID <= pArgs->nWrapGUID)
        {
            pArgs->nWrapGUID = nUnitGUID;
            pArgs->pWrapTarget = pUnit;
        }
        ++pArgs->nTargetCount;
    }
    else
    {
        pArgs->nNextGUID = nUnitGUID;
        pArgs->pNextTarget = pUnit;
        ++pArgs->nTargetCount;
    }

    return 1;
}

// 0x0056BD10
D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int nPreviousTargetGUID, int* pTargetCount)
{
    D2AuraNextTargetArgsStrc args;
    args.nWrapGUID = nPreviousTargetGUID;
    args.nPreviousGUID = nPreviousTargetGUID;
    args.pNextTarget = 0;
    args.nNextGUID = -1;
    args.pWrapTarget = 0;
    args.nTargetCount = 0;
    SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter | 0xA783, SKILLS_AuraCallback_FindNextTarget, &args, 0, ".\\SKILLS\\Skills.cpp", 803);

    D2UnitStrc* pResult = args.pNextTarget;
    if (!pResult)
    {
        pResult = args.pWrapTarget;
    }

    if (pTargetCount)
    {
        *pTargetCount = args.nTargetCount;
    }

    return pResult;
}

// 0x0056BD90
void __fastcall SKILLS_UpdatePetLimitForSkill(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if ((signed char)pSkillsTxtRecord->nPetType <= 0 || (signed char)pSkillsTxtRecord->nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    D2PetTypeSkillListStrc* pPetTypeTxtRecord = (D2PetTypeSkillListStrc*)sub_00478A20_GetPetTypeTxtRecord((signed char)pSkillsTxtRecord->nPetType);
    if (!pPetTypeTxtRecord)
    {
        return;
    }

    int nMax = 0;
    for (int i = 0; i < pPetTypeTxtRecord->nSkillCount; ++i)
    {
        const int nPetSkillId = pPetTypeTxtRecord->wSkillIds[i];
        D2SkillsTxt* pPetSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nPetSkillId);
        if (pPetSkillsTxtRecord)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, nPetSkillId);
            if (pSkill)
            {
                const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
                int nPetMax = 0;
                if (nLevel > 0)
                {
                    nPetMax = SKILLS_EvaluateSkillFormula(pPlayer, pPetSkillsTxtRecord->dwPetMax, nPetSkillId, nLevel);
                    if (nPetMax < 1)
                    {
                        nPetMax = 1;
                    }
                }

                if (nPetMax > nMax)
                {
                    nMax = nPetMax;
                }
            }
        }
    }

    PLAYERPETS_SetPetLimit(pGame, pPlayer, (signed char)pSkillsTxtRecord->nPetType, nMax);
}

// 0x0056BEC0
static int __stdcall SKILLS_ConsumeItemSkillCharge(D2GameStrc* pGame, D2SkillStrc* pSkill, int nOwnerGUID, D2UnitStrc* pPlayer)
{
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nOwnerGUID);
    if (!pItem) return 0;
    int nChargeSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 898);
    int nChargeSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);
    int nCharges = 0;
    D2StatListStrc* pStatList = 0;
    if (!ITEMMODS_GetItemCharges(pItem, nChargeSkillId, nChargeSkillLevel, &nCharges, &pStatList) || nCharges <= 0)
        return 0;
    nChargeSkillId = (nChargeSkillId << sgptDataTables->nStuff) + (nChargeSkillLevel & sgptDataTables->nShiftedStuff);
    const int nStatValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nChargeSkillId);
    if (!nStatValue) return 0;
    const int nMaxCharges = nStatValue >> 8;
    --nCharges;
    if (nMaxCharges <= 0 || nMaxCharges > 255) return 0;
    nCharges = D2_MIN(D2_MAX(nCharges, 0), nMaxCharges);
    nChargeSkillLevel = (nCharges & 0xFF) + (nMaxCharges << 8);
    STATLIST_SetBaseStat2(pStatList, STAT_ITEM_CHARGED_SKILL, nChargeSkillLevel, nChargeSkillId, pItem);
    D2GAME_PACKETS_SendPacket0x3E(UnitGetClient(pPlayer, ".\\SKILLS\\Skills.cpp", 933), pItem, 1, STAT_ITEM_CHARGED_SKILL, nChargeSkillLevel, nChargeSkillId);
    return 1;
}

static inline int SKILLS_IsPlayerInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

// 0x0056BFE0
int __fastcall SKILLS_ConsumeSkillMana(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_IsPlayerInline(pPlayer))
    {
        return 1;
    }
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 955) == nSkillId)
    {
        const int nOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pSkill);
        if (nOwnerGUID != -1)
        {
            return SKILLS_ConsumeItemSkillCharge(pGame, pSkill, nOwnerGUID, pPlayer);
        }
    }
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (!pSkillsTxtRecord->wMana && !pSkillsTxtRecord->wLevelMana)
    {
        return 0;
    }
    const int nLevelBonus = nSkillLevel - 1 < 0 ? 0 : nSkillLevel - 1;
    int nManaCost = (pSkillsTxtRecord->wMana + nLevelBonus * pSkillsTxtRecord->wLevelMana) << pSkillsTxtRecord->nManaShift;
    const int nMinManaCost = pSkillsTxtRecord->wMinMana << 8;
    if (nMinManaCost > nManaCost)
    {
        nManaCost = nMinManaCost;
    }
    if (STATES_CheckState(pPlayer, STATE_BLOOD_MANA))
    {
        return D2GAME_SKILLS_BloodMana(pPlayer, nManaCost);
    }
    if (STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }
    STATLIST_AddUnitStat(pPlayer, STAT_MANA, -nManaCost, 0);
    return 1;
}

// 0x0056C110
int __fastcall D2GAME_SKILLMANA_AuraConsume(D2UnitStrc* pUnit, int nManaCost)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    if (STATES_CheckState(pUnit, STATE_BLOODMANA))
    {
        return D2GAME_SKILLS_BloodMana(pUnit, nManaCost);
    }

    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < nManaCost)
    {
        return 0;
    }

    STATLIST_AddUnitStat(pUnit, STAT_MANA, -nManaCost, 0);
    return 1;
}

// 0x0056C160
int __fastcall SKILLS_HasManaOrChargesForUsedSkill(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        return pSkill->nCharges > 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1) - 1;
    if (nSkillLevel < 0)
    {
        nSkillLevel = 0;
    }

    const int nManaCost = (pSkillsTxtRecord->wMana + nSkillLevel * pSkillsTxtRecord->wLevelMana) << (unsigned char)pSkillsTxtRecord->nManaShift;
    if (pSkillsTxtRecord->wSrvDoFunc == SKILLSRVDO_SHAPESHIFT && STATES_IsUnitShapeShifted(pUnit))
    {
        return 1;
    }

    return STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >= nManaCost;
}

static inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClassId];
    }

    return 0;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline int MONSTERS_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }

    return nMonsterId;
}

// 0x0056C210
D2UnitFindDataStrc* __fastcall SKILLS_AllocUnitSearch(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY)
{
    D2UnitFindDataStrc* pUnitFindData = (D2UnitFindDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2UnitFindDataStrc), ".\\SKILLS\\Skills.cpp", 1099, 0);

    D2UnitFindArgStrc unitFindArg = {};
    unitFindArg.nFlags = 0x583;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nX = nX;
    unitFindArg.nY = nY;
    unitFindArg.nSize = nSize;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, pUnitFindData, pRoom, nX, nY, nSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(pUnitFindData);

    return pUnitFindData;
}

// 0x0056C2A0
void __fastcall SKILLS_FreeUnitSearch(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData)
{
    UNITFINDS_FreeUnitFindData(pUnitFindData);
    FOG_FreeServerMemory(pGame->pMemoryPool, pUnitFindData, ".\\SKILLS\\Skills.cpp", 0x465, 0);
}

// 0x0056C2D0
int __fastcall SKILLS_DrainTargetDurability(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x0056C310
int __fastcall SKILLS_ConsumeItemQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pItem)
    {
        int bNoQuantity = 0;
        int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) - 1;
        if (nQuantity < 0)
        {
            bNoQuantity = 1;
            nQuantity = 0;
        }

        STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nQuantity, 0);
        ITEMS_ScheduleQuantityReplenishment(pGame, pItem);

        D2GAME_PACKETS_SendPacket0x3E(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 1350), pItem, 1, STAT_QUANTITY, nQuantity, 0);

        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) != nMaxDurability)
        {
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);
            D2GAME_PACKETS_SendPacket0x3E(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 1356), pItem, 1, STAT_DURABILITY, nMaxDurability, 0);
        }

        PLRMODE_HandleDepletedWeapons(pGame, pUnit);

        if (!bNoQuantity)
        {
            return nQuantity + 1;
        }
    }

    return 0;
}

// 0x0056C3F0
int __fastcall SKILLS_ConsumeWeaponOrAmmoQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pUnit);
        int bNoBow = 1;

        if (ITEMSIsA(pWeapon, ITEMTYPE_BOW) || ITEMSIsA(pWeapon, ITEMTYPE_CROSSBOW))
        {
            bNoBow = 0;
        }

        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return SKILLS_ConsumeItemQuantity(pGame, pUnit, pItem);
        }

        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        if (pItem && (!bNoBow || pItem == pWeapon) && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
        {
            return SKILLS_ConsumeItemQuantity(pGame, pUnit, pItem);
        }
    }

    return 0;
}

// 0x0056C4E0
int __fastcall SKILLS_CanUseWeaponAmmo(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pUnit);
    if (!pWeapon)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int bNoAmmoItem = 1;
    if (ITEMS_GetAmmoType(pWeapon))
    {
        bNoAmmoItem = 0;
        if (!SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 1600) && STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_MAGICARROW, 0))
        {
            return 1;
        }
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    if (pRightArmItem && (!bNoAmmoItem || pRightArmItem == pWeapon) && (ITEMS_CheckIfStackable(pRightArmItem) || ITEMS_CheckIfThrowable(pRightArmItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pRightArmItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pRightArmItem);
    }

    D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
    if (pLeftArmItem && (!bNoAmmoItem || pLeftArmItem == pWeapon) && (ITEMS_CheckIfStackable(pLeftArmItem) || ITEMS_CheckIfThrowable(pLeftArmItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pLeftArmItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pLeftArmItem);
    }

    return 0;
}

// 0x0056C600
void __fastcall SKILLS_ApplyWeaponBonusToMissile(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pWeapon)
{
    if (pUnit && pMissile && pWeapon)
    {
        const int nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
        const int nToHitBonus = D2Common_11024(pUnit, pWeapon, 0, 0, 0);
        STATLIST_SetUnitStat(pMissile, STAT_TOHIT, nToHitBonus + nToHit, 0);
        const int nDamageBonus = D2Common_11024(pUnit, pWeapon, 0, 1, 0);
        STATLIST_AddUnitStat(pMissile, STAT_DAMAGEPERCENT, nDamageBonus, 0);
    }
}

struct D2ClientStrc;

// 0x0056C670
static D2UnitStrc* __stdcall SKILLS_GetOtherHandItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (nBodyLoc == BODYLOC_LARM)
    {
        return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    }
    return INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
}

// 0x0056C6A0
void __fastcall SKILLS_HandleTransmogrify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit)
    {
        pUnit->dwFlagEx &= 0xFFFFFFBF;
    }

    if (pItem && D2GAME_Transmogrify(pItem))
    {
        SUNIT_AttachSound(pUnit, 4, pUnit);
    }

    D2GAME_PACKETS_SendPacket0x3F(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 1711), 0, 0xFF, 1, 0, 0xFFFF);
}

static inline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline int GetClassId(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

// 0x0056C700
int __fastcall D2GAME_CheckSkillIfUnitsClassSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
            return pSkillsTxtRecord->nCharClass == GetClassId(pUnit);
    }
    return 0;
}

static inline D2StatesTxt* STATES_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x0056E780
int __fastcall SKILLS_IterateTargetsAroundTarget(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs)
{
    if (!pCallback)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    const int nDistanceSq = nDistance * nDistance;
    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (int i = 0; i < nNumRooms; ++i)
    {
        if (!(nFlags & 0x2000) || !DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            if (SKILLS_IsRoomInRange(ppRoomList[i], nX, nY, nDistance))
            {
                for (D2UnitStrc* j = ppRoomList[i]->pUnitFirst; j; j = j->ptRoomNext)
                {
                    if (nDistanceSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetUnitXPosition(j), UNITS_GetUnitYPosition(j)) && SKILLS_CheckAuraTarget(pUnit, j, nFlags))
                    {
                        pCallback(j, pArgs);
                    }
                }
            }
        }
    }

    return 1;
}

inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0056E900
void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 1157);
        SKILLS_RefreshPassiveSkills(pUnit);

        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
        }
    }
}

// 0x0056DE40
void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit)
{
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
    }
}

// 0x0056DE70
D2SkillStrc* __fastcall SKILLS_AddSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_AddSkill(pUnit, nSkillId);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
    return pSkill;
}

// 0x00570360
void __fastcall SKILLS_ResetSkillsAndRefundPoints(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    const int nClassId = pUnit->dwClassId;
    const int nSkillCount = SKILLS_GetPlayerSkillCount(nClassId);
    int nSkillPoints = 0;
    for (int i = 0; i < nSkillCount; ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
        if (pSkill)
        {
            nSkillPoints += SKILLS_GetSkillLevel(pUnit, pSkill, 0);
            D2GAME_SetSkills(pUnit, nSkillId, 0, 1);
            D2GAME_PACKETS_SendPacket0x21_UpdateSkills(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 4257), pUnit, nSkillId, 0, 1);
        }
    }

    STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nSkillPoints, 0);
    D2GAME_UpdatePlayerVitals(pGame, pUnit);
    D2GAME_UpdatePlayerItems(pGame, pUnit, 1);
}

static inline unsigned int sub_0056CBA0_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

static inline int sub_0056CBA0_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x0056DEB0
void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, bRemove, ".\\SKILLS\\Skills.cpp", 4394);
        SKILLS_RefreshPassiveSkills(pUnit);
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
        }
    }
}

// 0x0056DF10
void __fastcall SKILLS_RemoveSkillAndRefresh(D2UnitStrc* pUnit, int nSkillId)
{
    SKILLS_RemoveSkill(pUnit, nSkillId, ".\\SKILLS\\Skills.cpp", 4405);
    SKILLS_RefreshPassiveSkills(pUnit);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_H15(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int UNIT_HasFlag_H15(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056DF50
int __fastcall SKILLS_IsActiveSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4416) == nSkillId)
        return 1;
    pSkill = UNITS_GetLeftSkill(pUnit);
    if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 4419) == nSkillId)
        return 1;
    return 0;
}

inline int SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPerDelay, nSkillId, nSkillLevel);
    if (nDelay <= 5)
    {
        nDelay = 5;
    }

    return (pGame->dwGameFrame + nDelay - 1) / nDelay * nDelay + 1;
}

// 0x0056EDE0
D2UnitStrc* __fastcall D2GAME_CreateMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!nX && !nY)
    {
        D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY);
        if (!nX && !nY)
        {
            return 0;
        }
    }

    if (sub_006417F0(pUnit, nX, nY) > 100)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nMissile = nMissileId;

    return MISSILES_CreateMissileFromParams(pGame, &missileParams);
}

// 0x0056EF90
static void __stdcall D2GAME_SKILLS_SetDelay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDelay)
{
    const int nExpireFrame = nDelay + pGame->dwGameFrame;
    if (pUnit && !pUnit->dwUnitType && nDelay)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_SKILLDELAY);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            if (!pStatList)
            {
                return;
            }

            STATLIST_SetState(pStatList, STATE_SKILLDELAY);
            STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATES_ToggleState(pUnit, 0x79, 1);
        }

        D2COMMON_10476(pStatList, nExpireFrame);
        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
    }
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x0056F020
void __fastcall SKILLS_ApplySkillDelay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nSkillDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDelay, nSkillId, nSkillLevel);
        if (nSkillDelay > 0)
        {
            D2GAME_SKILLS_SetDelay(pGame, pUnit, nSkillDelay);
        }
    }
}

// 0x0056C740
int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nStateId, int bIncludeState)
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
        if (i != nStateId || bIncludeState)
        {
            if ((short)STATES_GetStatesTxtRecordInline(i)->wGroup == nGroup && STATES_CheckState(pUnit, i))
            {
                nResult = 1;
                STATES_ToggleState(pUnit, i, 0);

                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, i);
                if (pStatList)
                {
                    D2Common_10474(pUnit, pStatList);
                    STATLIST_FreeStatList(pStatList);
                }
            }
        }
    }

    return nResult;
}

// 0x0056C840
void __fastcall SKILLS_SetElementalDurationFromSkill(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    switch (pSkillsTxtRecord->nEType)
    {
    case ELEMTYPE_COLD:
        pDamage->dwColdLen = nLength;
        break;
    case ELEMTYPE_POIS:
        pDamage->dwPoisLen = nLength;
        break;
    case ELEMTYPE_STUN:
        pDamage->dwStunLen = nLength;
        break;
    case ELEMTYPE_BURN:
        pDamage->dwBurnLen = nLength;
        break;
    case ELEMTYPE_FREEZE:
        pDamage->dwFrzLen = nLength;
        break;
    }
}

// 0x0056C8E0
void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nLength, int* pResistStatId, int* pElementalType)
{
    if (nElementalType == ELEMTYPE_RAND)
    {
        nElementalType = gnRandomElemTypes[ITEMS_RollRandomNumber(&pUnit->pSeed) & 3];
        if (nLength <= 0)
        {
            nLength = 50;
        }

        if (pElementalType)
        {
            *pElementalType = nElementalType;
        }
    }

    int nResStatId = -1;
    switch (nElementalType)
    {
    case ELEMTYPE_FIRE:
        pDamage->dwFireDamage += nDamage;
        pDamage->dwHitClass = 0x20;
        nResStatId = STAT_FIRERESIST;
        break;

    case ELEMTYPE_LTNG:
        pDamage->dwLtngDamage += nDamage;
        pDamage->dwHitClass = 0x40;
        nResStatId = STAT_LIGHTRESIST;
        break;

    case ELEMTYPE_MAGIC:
        pDamage->dwMagDamage += nDamage;
        nResStatId = STAT_MAGICRESIST;
        break;

    case ELEMTYPE_COLD:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwColdLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    case ELEMTYPE_POIS:
        pDamage->dwPoisDamage += nDamage;
        pDamage->dwPoisLen = nLength;
        pDamage->dwHitClass = 0x50;
        nResStatId = STAT_POISONRESIST;
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
        pDamage->dwStunLen += nDamage + nLength;
        pDamage->dwHitClass = 0x60;
        break;

    case ELEMTYPE_BURN:
        pDamage->dwBurnDamage += nDamage;
        pDamage->dwBurnLen = nLength;
        break;

    case ELEMTYPE_FREEZE:
        pDamage->dwColdDamage += nDamage;
        pDamage->dwFrzLen = nLength;
        pDamage->dwHitClass = 0x30;
        nResStatId = STAT_COLDRESIST;
        break;

    default:
        pDamage->dwPhysDamage += nDamage;
        break;
    }

    if (pResistStatId)
    {
        *pResistStatId = nResStatId;
    }
}

// 0x0056CA40
int __fastcall SKILLS_SrvSt01_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    pUnit->nSeqCurrentFramePrecise = UNITS_GetFrameBonus(pUnit) << 8;
    if (STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return SKILLS_AllocTransformSkillCombat(pGame, pUnit, nSkillLevel);
    }

    if (!COMPOSIT_IsWeaponBowOrXBow(pUnit) || SKILLS_CanUseWeaponAmmo(pUnit))
    {
        return 1;
    }

    PLRMODE_HandleDepletedWeapons(pGame, pUnit);
    PLRMODE_BreakDepletedWeapons(pGame, pUnit);
    return 0;
}

// 0x0056CAB0
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

// 0x0056CAF0
int __fastcall SKILLS_SrvSt02_Kick(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = 9;
    damage.dwHitFlags = 2;
    damage.dwPhysDamage = pSkillsTxtRecord->dwMinDam << pSkillsTxtRecord->nToHitShift;
    damage.dwHitClass = 1;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    return 1;
}

// 0x0056CBA0
int __fastcall SKILLS_SrvSt03_Unsummon(D2GameStrc* game, D2UnitStrc* unit, int skillId, int skillLevel)
{
    D2UnitStrc* target = SUNIT_GetTargetUnit(game, unit);
    if (!target)
        return 0;
    if (sub_0056CBA0_GetUnitType(target) != 1)
        return 0;
    if (!unit)
        return 0;
    if (unit->dwUnitType != UNIT_PLAYER)
        return 0;
    if (AIGENERAL_GetMinionOwner(target) != unit)
        return 0;
    D2PetTypeTxt* petType = sub_00478A20_GetPetTypeTxtRecord(PLAYERPETS_GetPetTypeFromPetGUID(unit, target->dwUnitId));
    if (!petType)
        return 0;
    if (!(petType->nPetFlags[0] & gdwBitMasks[3]))
        return 0;
    D2SkillStrc* skill = UNITS_GetUsedSkill(unit);
    if (!skill)
        return 0;
    SKILLS_SetParam1(skill, sub_0056CBA0_GetUnitId(target));
    return 1;
}

static inline SkillCallback GetSkillCallback(short nIndex)
{
    if (nIndex < 0)
        return 0;
    if (nIndex >= 191)
        return 0;
    return gpSkillCallbacks_007322B0[nIndex];
}

// 0x0056CC20
int __fastcall SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;

    PLAYERPETS_RemovePet(pGame, pUnit, SKILLS_GetParam1(pSkill), 1);
    return 1;
}

// 0x0056CC60
static int __stdcall SKILLS_CheckUsedSkillTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETABLEONLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETABLEONLY & 7])
    {
        if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) && !SUNIT_CanPetBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId) && !SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTarget, nSkillId))
        {
            return 0;
        }
    }

    if (!UNIT_HasFlag_H15(pTarget, UNITFLAG_TARGETABLE))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
    }
    else
    {
        if (pTarget->dwUnitType == UNIT_MONSTER && pTarget->dwAnimMode == MONMODE_DEAD)
        {
            if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7]))
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
        else
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETCORPSE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETCORPSE & 7])
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
            }
        }
    }

    return 1;
}

static inline int UNITS_HasBeenDeletedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx >> 8) & 1;
}

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

// 0x0056FAF0
int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xBFF);
    if (!SKILLS_CheckUsedSkillTarget(pGame, pUnit, nSkillId))
    {
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
        }
        return 0;
    }

    int nOwnerGUID;
    int nInfoSkillId;
    int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nCharges;
    if (SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, &nInfoSkillId, &nSkillLevel, &nCharges) && !nCharges)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_H15(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit && !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]) && SUNIT_CanAllyBeTargetedBySkill(pGame, pUnit, pTargetUnit, nSkillId))
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]))
    {
        if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            int nType = UNIT_INVALID;
            if (pUnit)
            {
                nType = pUnit->dwUnitType;
            }
            switch (nType)
            {
            case UNIT_PLAYER:
                PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                break;
            case UNIT_MONSTER:
                return 0;
            }
            return 0;
        }
    }

    const int nResult = SKILLS_StartSkill(pGame, pUnit, nSkillId, nSkillLevel, 0);
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && !nResult)
    {
        PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
    }
    return nResult;
}

// 0x0056CDA0
int __fastcall SKILLS_SchedulePeriodicSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bUseRightSkill)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7] || pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
        if (bUseRightSkill)
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, -1, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nSkillId);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

inline int I12_SummonGetUnitX(D2UnitStrc* pUnit)
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

inline int I12_SummonGetUnitY(D2UnitStrc* pUnit)
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

// 0x0056CE70
int __fastcall SKILLS_SchedulePeriodicStat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventKey, int nSkillId, int nSkillLevel, int bUseRightSkill)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PERIODIC >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PERIODIC & 7] || pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        const int nExpireFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
        if (bUseRightSkill)
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSKILLS, nExpireFrame, -1, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_PERIODICSTATS, nEventKey);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_PERIODICSTATS, nExpireFrame, nEventKey, nSkillId);
        }

        return 1;
    }

    return 0;
}

// 0x0056FC50
void __fastcall SKILLS_ExecuteUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 3235);
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        SKILLS_ExecuteSkill(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
        SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillId, nSkillLevel, 0);
    }
}

// 0x0056D2C0
int __fastcall D2GAME_GetXAndYFromTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
    else
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pDynamicPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pDynamicPath);
    }

    return *pX && *pY;
}

// 0x0056ECB0
D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity)
{
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX + UNITS_GetUnitXPosition(pUnit);
    missileParams.nY = nY + UNITS_GetUnitYPosition(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    if (nTargetX && nTargetY)
    {
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
    }
    else if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    if (missileParams.nTargetX && missileParams.nTargetY)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            const int nToHit = STATLIST_UnitGetStatValue(pUnit, STAT_TOHIT, 0);
            if (nToHit)
            {
                missileParams.nAttBonus = nToHit;
                missileParams.dwFlags |= 0x1000;
            }
        }

        if (!bCheckItemQuantity || pUnit->dwUnitType || SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit) > 0)
        {
            return MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }
    return 0;
}

// 0x0056EE90
D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bSkipCheck)
{
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x420;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = nX + UNITS_GetUnitXPosition(pUnit);
    missileParams.nY = nY + UNITS_GetUnitYPosition(pUnit);
    missileParams.nMissile = nMissileId;

    if (nTargetX && nTargetY)
    {
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
    }
    else if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    if (!bSkipCheck || pUnit->dwUnitType != UNIT_PLAYER || SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit) > 0)
    {
        return MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
    return 0;
}

// 0x0056F070
int __fastcall SKILLS_SrvDo001_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2UnitStrc* pWeapon = PLAYER_GetWeaponForSkill(pUnit);
    if (pWeapon && ITEMS_GetItemType(pWeapon) == ITEMTYPE_MISSILE_POTION)
    {
        return 0;
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        const int nItemType = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
        if (nItemType != ITEMTYPE_BOW)
        {
            SKILLS_CreateMissileAtOffset(pGame, nItemType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
        }
        else
        {
            SKILLS_CreateMissileAtOffset(pGame, ITEMTYPE_BOW, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        }
        return 1;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage = {};
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, STATLIST_UnitGetStatValue(pUnit, STAT_PROGRESSIVE_TOHIT, 0), 0);
    damage.dwHitFlags |= 2;
    SKILLS_ApplyProgressivePhysicalDamageBonus(pUnit, &damage);
    SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, 128);
    SKILLS_ApplyProgressiveLeechAndElementalDamage(pUnit, &damage);
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);

    if (STATES_CheckStateMaskOnUnit(pUnit, 38))
    {
        return SKILLS_DrainTargetDurability(pGame, pUnit, nSkillLevel);
    }

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (pDamage)
    {
        SKILLS_ReleaseProgressiveCharges(pGame, pUnit, pDamage);
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x0056F460
int __fastcall SKILLS_SrvDo003_Throw(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (!bIsLeftHandItem)
        {
            pWeapon = SKILLS_GetOtherHandItem(pInventory, nBodyLoc);
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_THROWABLE, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMSIsA(pWeapon, 38))
    {
        pMissile = SKILLS_CreateMissileFromOrigin(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    SKILLS_ApplyWeaponBonusToMissile(pUnit, pMissile, pWeapon);
    return 1;
}

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x0056F550
int __fastcall SKILLS_SrvDo005_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pWeapon = 0;
    int nBodyLoc;
    int bIsLeftHandItem;
    if (INVENTORY_GetEquippedWeapon(pInventory, &pWeapon, &nBodyLoc, &bIsLeftHandItem))
    {
        if (bIsLeftHandItem)
        {
            pWeapon = SKILLS_GetOtherHandItem(pInventory, nBodyLoc);
        }

        if (!ITEMS_CheckIfThrowable(pWeapon) && !STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_THROWABLE, 0))
        {
            return 0;
        }
    }

    if (!pWeapon)
    {
        return 0;
    }

    pUnit->dwFlags |= 0x40;
    const int nMissileType = ITEMS_GetMissileType(pWeapon);

    D2UnitStrc* pMissile;
    if (ITEMSIsA(pWeapon, 38))
    {
        pMissile = SKILLS_CreateMissileFromOrigin(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }
    else
    {
        pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileType, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
    }

    SKILLS_ApplyWeaponBonusToMissile(pUnit, pMissile, pWeapon);
    return 1;
}

// 0x0056F7F0
int __fastcall SKILLS_ExecuteSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyCosts, int bSkipSkillCheck, int bItemEffect)
{
    if (!pGame || !pUnit)
    {
        return 0;
    }

    int nResult = 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int bLivingUnit;
    if (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER)
    {
        bLivingUnit = 1;
        D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
        if (pUsedSkill && !(SKILLS_GetFlags(pUsedSkill) & 1) && !SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_INTOWN))
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
            {
                UNITS_SetUsedSkill(pUnit, 0);

                if (pUnit->dwUnitType == UNIT_PLAYER)
                {
                    PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, PLRMODE_TOWNNEUTRAL, 0, 0, 1);
                }

                return 0;
            }
        }

        if (!bSkipSkillCheck && (!pUsedSkill || SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\SKILLS\\Skills.cpp", 2887) != nSkillId || SKILLS_GetSkillLevel(pUnit, pUsedSkill, 1) <= 0))
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
            if (!pSkill || SKILLS_GetSkillLevel(pUnit, pSkill, 1) <= 0)
            {
                return 0;
            }
        }
    }
    else
    {
        bLivingUnit = 0;
    }

    if (pSkillsTxtRecord->wSrvDoFunc < 0 || pSkillsTxtRecord->wSrvDoFunc >= 191
        || bLivingUnit && SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX2_USEMANAONDO) && !SKILLS_HasManaOrChargesForUsedSkill(pUnit))
    {
        return 0;
    }

    int nDoFunc = pSkillsTxtRecord->wSrvDoFunc;
    if (bItemEffect && bSkipSkillCheck && pSkillsTxtRecord->wItemEffect > 1)
    {
        nDoFunc = pSkillsTxtRecord->wItemEffect;
    }

    SKILLDOFUNC pDoFunc = gpfnSkillSrvDoFunctions[nDoFunc];
    if (pDoFunc)
    {
        nResult = pDoFunc(pGame, pUnit, nSkillId, nSkillLevel);
    }

    if (pSkillsTxtRecord->wSrvMissile >= 0 && sub_0046ACE0_GetMissilesTxtRecord(pSkillsTxtRecord->wSrvMissile))
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

        int nX = 0;
        int nY = 0;
        int nTargetX = 0;
        int nTargetY = 0;
        if (bSkipSkillCheck && bItemEffect)
        {
            D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY);
            if (nX && nY)
            {
                nTargetX = nX;
                nTargetY = nY;
                nX -= CLIENTS_GetUnitX(pUnit);
                nY -= CLIENTS_GetUnitY(pUnit);
                nTargetX += nX;
                nTargetY += nY;
            }
        }

        if (SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_LOB))
        {
            SKILLS_CreateMissileFromOrigin(pGame, pSkillsTxtRecord->wSrvMissile, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, 0);
        }
        else
        {
            SKILLS_CreateMissileAtOffset(pGame, pSkillsTxtRecord->wSrvMissile, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, 0);
        }

        nResult = 1;
    }

    if (!nResult)
    {
        return 0;
    }

    if (bApplyCosts)
    {
        if (bLivingUnit)
        {
            if (!gpfnSkillSrvStartFunctions[pSkillsTxtRecord->wSrvStartFunc] || SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX2_USEMANAONDO))
            {
                SKILLS_ConsumeSkillMana(pGame, pUnit, nSkillId, nSkillLevel);
            }

            if (SKILLS_CHECK_FLAG(pSkillsTxtRecord, SKILLSFLAGINDEX_DECQUANT))
            {
                SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit);
            }
        }

        const int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwDelay, nSkillId, nSkillLevel);
        if (nDelay > 0 && pUnit->dwUnitType == UNIT_PLAYER)
        {
            if (pSkillsTxtRecord->nAnim == PLRMODE_SEQUENCE)
            {
                if (!(pUnit->dwSeqFrame & 0xFFFFFF00))
                {
                    D2GAME_SKILLS_SetDelay(pGame, pUnit, nDelay);
                }
            }
            else
            {
                D2GAME_SKILLS_SetDelay(pGame, pUnit, nDelay);
            }
        }
    }

    return nResult;
}

// 0x0056FCB0
void __fastcall SKILLS_EventCallback_PeriodicSkillAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillIdArg, int nUnused)
{
    if (nSkillIdArg == -1)
    {
        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        if (pSkill)
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0xCBB);
            const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord && pSkillsTxtRecord->nFlags[5 >> 3] & gdwBitMasks[5 & 7] && !SUNIT_IsDead(pUnit))
            {
                SKILLS_ExecuteSkill(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
                SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillId, nSkillLevel, 1);
                return;
            }
        }

        D2GAME_EVENTS_Delete(pGame, pUnit, 8, -1);
    }
    else if (nSkillIdArg > 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillIdArg);
        if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        if (!STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, 8, nSkillIdArg);
            return;
        }

        const int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
        if (SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillIdArg) && nSkillIdArg == STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0))
        {
            SKILLS_ExecuteSkill(pGame, pUnit, nSkillIdArg, nSkillLevel, 1, 0, 0);
            SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillIdArg, nSkillLevel, 0);
        }
        else
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, 8, nSkillIdArg);
        }
    }
}

// 0x0056FE40
void __fastcall SKILLS_EventCallback_ItemAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 9, nEventCustomId);
        return;
    }

    if (SUNIT_IsDead(pUnit))
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 9, nEventCustomId);
        return;
    }

    const int nAura = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_AURA, nSkillId);
    if (nAura <= 0)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 9, nEventCustomId);
        return;
    }

    SKILLS_ExecuteSkill(pGame, pUnit, nSkillId, nAura, 1, 1, 0);
    SKILLS_SchedulePeriodicStat(pGame, pUnit, nEventCustomId, nSkillId, nAura, 0);
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x0056FF10
static void __stdcall SKILLS_StartAssignedAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
    {
        if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
        {
            D2SkillStrc* pHighestLevelSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
            if (pHighestLevelSkill)
            {
                const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, pHighestLevelSkill, 1);
                if (nSkillLevel > 0)
                {
                    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_IMMEDIATE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_IMMEDIATE & 7])
                    {
                        SKILLS_ExecuteSkill(pGame, pUnit, nSkillId, nSkillLevel, 1, 0, 0);
                    }
                    else
                    {
                        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);

                        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
                        if (!pStatList)
                        {
                            pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
                        }

                        if (pStatList)
                        {
                            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
                            STATLIST_SetSkillId(pStatList, nSkillId);
                            STATLIST_SetSkillLevel(pStatList, nSkillLevel);
                            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
                            STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
                        }
                    }

                    SKILLS_SchedulePeriodicSkill(pGame, pUnit, nSkillId, nSkillLevel, 1);
                }
            }
        }
    }
}

// 0x00570080
int __fastcall SKILLS_TryIncreaseSkillLevel(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        int nRequiredSkillPoints = 1;
        if (pSkillsTxtRecord->dwSkPoints != -1)
        {
            int nSkillLevel = 0;

            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pSkill)
            {
                nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            }

            nRequiredSkillPoints = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwSkPoints, nSkillId, nSkillLevel);
        }

        if (STATLIST_GetUnitBaseStat(pUnit, STAT_SKILLPTS, 0) >= nRequiredSkillPoints)
        {
            STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, -nRequiredSkillPoints, 0);

            D2SkillStrc* pSkill = SKILLS_AddSkill(pUnit, nSkillId);
            SKILLS_RefreshPassiveSkills(pUnit);

            if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
            {
                PLAYERPETS_UpdatePetLimits(SUNIT_GetGameFromUnit(pUnit), pUnit);
            }

            if (!pSkill)
            {
                STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nRequiredSkillPoints, 0);
            }
            else
            {
                const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 0);
                D2GAME_PACKETS_SendPacket0x21_UpdateSkills(UnitGetClient(pUnit, ".\\SKILLS\\Skills.cpp", 3443), pUnit, nSkillId, nLevel, 0);

                const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
                if (nPassiveState)
                {
                    STATES_ToggleState(pUnit, nPassiveState, 1);
                }

                SKILLS_RefreshSkill(pUnit, nSkillId);
                return 1;
            }
        }
    }

    return 0;
}

// 0x0056CF40
D2UnitStrc* __fastcall D2GAME_CreateLinkPortal(D2GameStrc* pGame, int nUnused, D2UnitStrc* pPortal, int nDestLevel, int nSourceLevel)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nDestLevel);
    int nX;
    int nY;
    D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nDestLevel, 11, &nX, &nY, 3);
    D2ActiveRoomStrc* pDestinationRoom = pRoom;

    GAME_ActivateRoom(pGame, pRoom);

    if (!pRoom)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPortal), 2, !pPortal ? -1 : pPortal->dwUnitId);
        SUNIT_RemoveUnit(pGame, pPortal);
        return 0;
    }

    D2CoordStrc coords;
    coords.nX = nX;
    coords.nY = nY;

    if (QUESTS_PortalCheck(pGame, &coords, nSourceLevel, &pRoom))
    {
        pRoom = sub_00463740_FindRoomAtPoint(pRoom, coords.nX, coords.nY);
    }

    if (!pRoom)
    {
        pRoom = pDestinationRoom;
        coords.nX = nX;
        coords.nY = nY;
    }

    pRoom = COLLISION_GetFreeCoordinatesEx(pRoom, &coords, 3, 0xBE11u, 5);
    if (!pRoom)
    {
        pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nDestLevel, 11, &nX, &nY, 3);
        if (!pRoom)
        {
            pRoom = pDestinationRoom;
            D2_ASSERT(pDestinationRoom, 0xE08);
        }
    }

    nX = coords.nX;
    nY = coords.nY;

    D2UnitStrc* pLinkPortal = SUNIT_AllocUnitData(2, !pPortal ? -1 : pPortal->dwClassId, coords.nX, coords.nY, pGame, pRoom, 1, 2, 0);
    if (!pLinkPortal)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPortal), 2, !pPortal ? -1 : pPortal->dwUnitId);
        SUNIT_RemoveUnit(pGame, pPortal);
        return 0;
    }

    const int eLevelIdLocal = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal));
    D2_ASSERT(eLevelIdLocal <= 255, 0xE2B);

    pLinkPortal->pObjectData->InteractType = eLevelIdLocal;
    const unsigned char nPortalFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, nPortalFlags);
    UNITS_ChangeAnimMode(pLinkPortal, 2);
    SUNIT_LinkPortalCoordinates(pPortal, pLinkPortal);
    UNITS_StoreOwner(pPortal, pLinkPortal);
    UNITS_StoreOwner(pLinkPortal, pPortal);

    return pLinkPortal;
}

// 0x0056D130
int __fastcall D2GAME_CreatePortalObject(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* hRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm)
{
    D2_ASSERT(hRoom, 0xE42);

    if (ppSourceUnit)
    {
        *ppSourceUnit = 0;
    }

    if (pUnit && DUNGEON_IsRoomInTown(hRoom))
    {
        if ((nDestLevel != LEVEL_MOOMOOFARM && nDestLevel != LEVEL_PANDEMONIUMFINALE && nDestLevel != LEVEL_PANDEMONIUMRUN1 && nDestLevel != LEVEL_PANDEMONIUMRUN2 && nDestLevel != LEVEL_PANDEMONIUMRUN3) || nObjectId != OBJECT_PERMANENT_TOWN_PORTAL)
        {
            SUNIT_AttachSound(pUnit, 0x18, pUnit);
            return 0;
        }
    }

    const unsigned char bAct = DRLG_GetActNoFromLevelId(nDestLevel);
    const int nSourceLevel = DUNGEON_GetLevelIdFromRoom(hRoom);

    D2_ASSERT(bAct == DRLG_GetActNoFromLevelId(nSourceLevel), 0xE5C);

    D2CoordStrc coords;
    coords.nX = nX;
    coords.nY = nY;

    if (!bPerm)
    {
        if (!COLLISION_GetFreeCoordinatesWithField(hRoom, &coords, &coords, 3, 0x3E01, 0xC01, 0))
        {
            return 0;
        }
    }

    const int nTargetX = coords.nX;
    const int nTargetY = coords.nY;

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(hRoom, nTargetX, nTargetY);
    if (!pTargetRoom)
    {
        return 0;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(2, nObjectId, nTargetX, nTargetY, pGame, pTargetRoom, 1, 1, 0);
    if (ppSourceUnit)
    {
        *ppSourceUnit = pPortal;
    }

    UNITS_ChangeAnimMode(pPortal, 1);

    D2UnitStrc* pLinkPortal = D2GAME_CreateLinkPortal(pGame, pUnit, pPortal, nDestLevel, nSourceLevel);
    if (!pLinkPortal)
    {
        return 0;
    }

    D2PortalFlagsStrc portalFlags;
    portalFlags.nFlags = UNITS_GetObjectPortalFlags(pLinkPortal) | 3;
    UNITS_SetObjectPortalFlags(pLinkPortal, portalFlags.nFlags);
    DUNGEON_ToggleHasPortalFlag(pTargetRoom, 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pLinkPortal), 0);
    return 1;
}

// 0x0056D370
void __fastcall SKILLS_EnlargeVector(int* pX, int* pY)
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

// 0x0056D3B0
void __fastcall SKILLS_MakeShortPerpendicularVector(int* pX, int* pY)
{
    int nX = *pY;
    int nY = -*pX;
    while (nX * nX + nY * nY > 3)
    {
        nX /= 2;
        nY /= 2;
    }

    *pX = nX;
    *pY = nY;
}

// 0x0056D400
void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity)
{
    static const int xOffsets[64] = // 0x006E1288
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24,
        -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5,
        8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] = // 0x006E1388
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11,
        8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27,
        -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = CLIENTS_GetUnitXInline(pOrigin);
    missileParams.nY = CLIENTS_GetUnitYInline(pOrigin);
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pOwner;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;

    if (nVelocity)
    {
        missileParams.nVelocity = nVelocity;
        missileParams.dwFlags |= 4;
    }

    for (int i = 0; i < 64; ++i)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
}

// 0x0056D4E0
void __fastcall SKILLS_CreateMissilePattern(D2GameStrc* pGame, int nMissiles, D2MissileStrc* pMissileParams)
{
    D2_ASSERT((nMissiles - 1) / 5 <= 7, 0xF0D);

    pMissileParams->nTargetX = 14;
    pMissileParams->nTargetY = -14;
    MISSILES_CreateMissileFromParams(pGame, pMissileParams);

    int nSubMissiles = nMissiles - 1;
    for (int j = 0; j < 7 && nSubMissiles; ++j)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (nSubMissiles <= 0)
            {
                break;
            }

            pMissileParams->nTargetX = gnMissilePatternOffsets1[j] * gnMissilePatternSignX[i];
            pMissileParams->nTargetY = gnMissilePatternOffsets2[j] * gnMissilePatternSignY[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);

            pMissileParams->nTargetX = gnMissilePatternOffsets2[j] * gnMissilePatternSignX[i];
            pMissileParams->nTargetY = gnMissilePatternOffsets1[j] * gnMissilePatternSignY[i];
            MISSILES_CreateMissileFromParams(pGame, pMissileParams);
            nSubMissiles -= 2;
        }

        pMissileParams->nTargetX = gnMissilePatternXOffsets[j];
        pMissileParams->nTargetY = gnMissilePatternYOffsets[j];
        MISSILES_CreateMissileFromParams(pGame, pMissileParams);
        nSubMissiles -= 1;
    }
}

// 0x0056D5F0
int __fastcall SKILLS_SpawnItemInFreeHand(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        int nBodyLoc;
        int bEquip = 0;
        if (!pRightArmItem && !pLeftArmItem)
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pRightArmItem && pLeftArmItem && !ITEMS_CheckWeaponIfTwoHanded(pLeftArmItem) && !ITEMSIsA(pLeftArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_RARM;
            bEquip = 1;
        }
        else if (!pLeftArmItem && pRightArmItem && !ITEMS_CheckWeaponIfTwoHanded(pRightArmItem) && !ITEMSIsA(pRightArmItem, ITEMTYPE_WEAPON))
        {
            nBodyLoc = BODYLOC_LARM;
            bEquip = 1;
        }

        if (bEquip)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = pUnit;
            itemDrop.pGame = pGame;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = DATATBLS_GetItemIdFromItemCode(dwItemCode);
            D2_ASSERT(itemDrop.nId != -1, 0xF4C);

            itemDrop.nSpawnType = 4;
            itemDrop.nX = 0;
            itemDrop.nY = 0;
            itemDrop.pRoom = 0;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            D2UnitStrc* pNewItem = D2GAME_CreateItemEx(pGame, &itemDrop, 0);
            D2_ASSERT(pNewItem, 0xF55);

            {
                int nUnused;
                ITEMMODE_EquipCursorItem(pGame, pUnit, pNewItem->dwUnitId, nBodyLoc, 0, &nUnused);
            }
            return 1;
        }
    }

    return 0;
}

// 0x0056D790
void __fastcall SKILLS_EventCallback_ActiveState(D2GameStrc* game, D2UnitStrc* unit, int skill, int level)
{
    if (skill <= 0)
        return;
    if (skill >= sgptDataTables->nSkillsTxtRecordCount)
        return;
    D2SkillsTxt* record = &sgptDataTables->pSkillsTxt[skill];
    if (!record)
        return;
    const short state = record->nAuraState;
    if (state < 0)
        return;
    if (state >= sgptDataTables->nStatesTxtRecordCount)
        return;
    D2StatesTxt* states = GAME_GetStatesTxtRecord(state);
    if (!states)
        return;
    SkillCallback callback = GetSkillCallback(states->callback);
    if (!callback)
        return;
    callback(game, unit, skill, level);
}

// 0x0056D810
void __fastcall SKILLS_ExecuteServerDoFunction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel)
{
    if (nDoFunc >= 0 && nDoFunc < SKILLSRVDOFN_COUNT && gpfnSkillSrvDoFunctions[nDoFunc])
    {
        gpfnSkillSrvDoFunctions[nDoFunc](pGame, pUnit, nSkillId, nSkillLevel);
    }
}

// 0x0056D840
static void SKILLS_RemoveTrackedSummon(D2GameStrc* pGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 4008);

    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, SUNIT_GetTrackedSummonGUID(hUnit));
    if (pPet)
    {
        if (UNITS_HasBeenDeletedInline(pPet))
        {
            SUNIT_RemoveUnit(pGame, pPet);
            SUNIT_SetTrackedSummonGUID(hUnit, -1);
            return;
        }

        pPet->dwFlags |= 0x4000000u;

        SUNITDMG_KillMonster(pGame, pPet, hUnit, 1);
    }

    SUNIT_SetTrackedSummonGUID(hUnit, -1);
}

// 0x0056D8D0
static void __stdcall SKILLS_RegisterSummonedPet(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg, D2UnitStrc* pPet)
{
    if (!(pSummonArg->dwFlags & 8) && pPet)
    {
        pPet->dwFlags |= UNITFLAG_ISREVIVE;
    }

    if (pSummonArg->dwFlags & 2)
    {
        SKILLS_RemoveTrackedSummon(pGame, pSummonArg->pOwner);
        SUNIT_SetTrackedSummonGUID(pSummonArg->pOwner, !pPet ? -1 : pPet->dwUnitId);
    }

    int nPetMax = pSummonArg->nPetMax;
    if (nPetMax < 1)
    {
        nPetMax = 1;
    }
    PLAYERPETS_AddSummonedPet(pGame, pSummonArg->pOwner, pPet, pSummonArg->nPetType, nPetMax);
}

// 0x0056D940
D2UnitStrc* __fastcall D2GAME_SummonPet(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg)
{
    int nX;
    int nY;
    if (pSummonArg->dwFlags & 1)
    {
        nX = pSummonArg->pPosition.nX;
        nY = pSummonArg->pPosition.nY;
    }
    else
    {
        D2GAME_GetXAndYFromTargetUnit(pGame, pSummonArg->pOwner, &nX, &nY);
    }

    D2ActiveRoomStrc* pOwnerRoom = UNITS_GetRoom(pSummonArg->pOwner);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(pOwnerRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    D2UnitStrc* hPet = D2GAME_SpawnMonster(pGame, pRoom, nX, nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, -1, 66);
    if (!hPet)
    {
        if (pSummonArg->dwFlags & 4)
        {
            return 0;
        }

        hPet = D2GAME_SpawnMonster(pGame, pRoom, nX, nY, pSummonArg->nHcIdx, pSummonArg->nMonMode, 4, 66);
        if (!hPet)
        {
            return 0;
        }
    }

    SKILLS_RegisterSummonedPet(pGame, pSummonArg, hPet);

    if (hPet)
    {
        hPet->dwFlags |= UNITFLAG_NOTC;
    }

    D2UnitStrc* pOwner = pSummonArg->pOwner;
    int nOwnerType = UNIT_INVALID;
    if (pOwner)
    {
        nOwnerType = pOwner->dwUnitType;
    }
    AIGENERAL_SetOwnerData(pGame, hPet, !pOwner ? -1 : pOwner->dwUnitId, nOwnerType, 0, 0);

    D2_ASSERT(!STATES_CheckState(hPet, STATE_UNINTERRUPTABLE), 4108);

    AITHINK_ExecuteAiFn(pGame, hPet, AIGENERAL_GetAiControlFromUnit(hPet), pSummonArg->nAiSpecialState);
    MONSTER_UpdateAiCallbackEvent(pGame, hPet);
    D2GAME_EVENTS_Delete(pGame, hPet, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, hPet, EVENTTYPE_AITHINK, pGame->dwGameFrame + 25, 0, 0);

    return hPet;
}

// 0x0056DAB0
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality)
{
    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    if (nItemId != -1)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pUnit, &pCoord);

        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop = {};
            itemDrop.pUnit = pUnit;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pGame;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = nItemId;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.nQuality = nItemQuality;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            return D2GAME_CreateItemEx(pGame, &itemDrop, 0);
        }
    }

    return 0;
}

// 0x0056DBC0
void __fastcall SKILLS_ApplyCurseAroundTarget(D2GameStrc* pGame, int nFlags, D2UnitStrc* pUnit, int nSkillLevel, int nRange, CurseCallbackFunc pfCurse)
{
    D2_ASSERT(pfCurse, 0x1047);
    int nX;
    int nY;
    if (D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        D2UnitFindArgStrc findArg = {};
        findArg.nFlags = nFlags;
        findArg.pUnit = pUnit;
        findArg.nX = nX;
        findArg.nY = nY;
        findArg.nSize = nRange;
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        if (pRoom)
        {
            D2UnitFindDataStrc findData;
            UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &findData, pRoom, nX, nY, nRange, 0, &findArg);
            UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&findData);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pfCurse), 0x1061);
            for (int i = 0; i < findData.nIndex; ++i)
                pfCurse(pGame, pUnit, findData.pUnitsArray[i], nSkillLevel);
            UNITFINDS_FreeUnitFindData(&findData);
        }
    }
}

// 0x0056DCC0
void __fastcall SKILLS_ApplyAreaEffect(D2GameStrc* pGame, D2EffectStrc* pEffect)
{
    D2_ASSERT(pEffect, 4280);
    D2_ASSERT(pEffect->pfAreaEffect, 4281);

    int nParam = pEffect->nParam;
    if (!nParam)
    {
        nParam = SKILLDESC_GetSkillParamByLevel(pEffect->nSkillId, pEffect->nSkillLevel);
    }

    D2UnitFindArgStrc unitFindArg = {};
    unitFindArg.nFlags = pEffect->nFlags;
    unitFindArg.pUnit = pEffect->pUnit;
    unitFindArg.nX = pEffect->nX;
    unitFindArg.nY = pEffect->nY;
    unitFindArg.nSize = nParam;

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pEffect->pUnit), pEffect->nX, pEffect->nY);
    if (pRoom)
    {
        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, pEffect->nX, pEffect->nY, nParam, 0, &unitFindArg);
        unitFindData.nFlags = pEffect->nFlags;
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        D2_ASSERT(!IsBadCodePtr((FARPROC)pEffect->pfAreaEffect), 4315);

        for (int i = 0; i < unitFindData.nIndex; ++i)
        {
            ((SKILLS_AREAEFFECTFN)pEffect->pfAreaEffect)(pGame, pEffect->pUnit, unitFindData.pUnitsArray[i], pEffect->nSkillLevel, pEffect->unk0x1C);
        }

        UNITFINDS_FreeUnitFindData(&unitFindData);
    }
}

struct D2Unk0056DCC0Strc;

struct D2Unk0056DCC0Strc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    void* pUnk0x20;
};

void __fastcall SKILLS_ApplyAreaEffect(D2GameStrc* pGame, D2Unk0056DCC0Strc* pRecord); // 0x0056DCC0

// 0x0056DDE0
void __fastcall SKILLS_ApplyAreaEffectAtCoordinates(D2GameStrc* pGame, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, void* pArg8)
{
    D2Unk0056DCC0Strc record = {};
    record.nUnk0x00 = nArg2;
    record.f_C = nArg3;
    record.f_10 = nArg4;
    record.nUnk0x04 = nArg5;
    record.nUnk0x08 = nArg6;
    record.nUnk0x18 = nArg7;
    record.pUnk0x20 = pArg8;
    SKILLS_ApplyAreaEffect(pGame, &record);
}

// 0x0056DFA0
void __fastcall D2GAME_RefreshPassiveSkills(D2UnitStrc* pUnit)
{
    if (pUnit->pSkills)
    {
        for (D2SkillStrc* i = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills); i; i = SKILLS_GetNextSkill(i))
        {
            const int nSkillId = SKILLS_GetSkillIdFromSkill(i, ".\\SKILLS\\Skills.cpp", 0x1153);
            const int nPassiveState = SKILLS_GetPassiveState(nSkillId);
            if (nPassiveState > 0)
            {
                STATES_ToggleState(pUnit, nPassiveState, 1);
                SKILLS_RefreshSkill(pUnit, nSkillId);
            }
        }
    }
}

// 0x0056E000
static void __stdcall SKILLS_FillMonSkillInfo(D2UnitStrc* pOwner, int nSkillId, D2MonSkillInfoStrc* pMonSkillInfo)
{
    const int nSkillLevel = SKILLS_GetHighestSkillLevelById(pOwner, nSkillId);
    pMonSkillInfo->nMinDamage = SKILLS_GetMinPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nMaxDamage = SKILLS_GetMaxPhysDamage(pOwner, nSkillId, nSkillLevel, 1) >> 8;
    pMonSkillInfo->nToHit = SKILLS_GetToHitFactor(pOwner, nSkillId, nSkillLevel);
}

// 0x0056E050
void __fastcall SKILLS_FillMinionSkillDamage(D2UnitStrc* pUnit, int nUnused, D2MonSkillInfoStrc* pMonSkillInfo)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wSkillDamage > 0 && pMonStatsTxtRecord->wSkillDamage <= sgptDataTables->nSkillsTxtRecordCount)
            {
                SKILLS_FillMonSkillInfo(pOwner, pMonStatsTxtRecord->wSkillDamage, pMonSkillInfo);
            }
        }
    }
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
        return &sgptDataTables->pStatesTxt[nState];
    return 0;
}

// 0x0056E970
D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse)
{
    D2UnitStrc* pTarget = pCurse->pTarget;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pTarget);
    const int nState = pCurse->nState;
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
    if (!pStatesTxtRecord)
        return 0;
    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pTarget->dwClassId >= 0 && pTarget->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pTarget->dwClassId];
        }
        if (!pMonStatsTxtRecord || (pMonStatsTxtRecord->nMonStatsFlags[1] & (unsigned char)gdwBitMasks[0]))
            return 0;
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (!pMonStats2TxtRecord || !(pMonStats2TxtRecord->nFlags[1] & (unsigned char)gdwBitMasks[1]))
            return 0;
    }
    const int bCurse = STATES_CheckStateMaskCurseByStateId(nState);
    if (bCurse)
    {
        const int nResistance = STATLIST_UnitGetStatValue(pTarget, STAT_CURSE_RESISTANCE, 0);
        if (nResistance >= 100)
            return 0;
        if (nResistance)
        {
            const int nDuration = pCurse->nDuration;
            pCurse->nDuration = nDuration - DATATBLS_ApplyRatio(nDuration, nResistance, 100);
        }
        if (STATES_CheckState(pTarget, STATE_ATTRACT))
            return 0;
    }
    unsigned int nFlags = 0;
    D2StatListStrc* pStatList;
    if (bCurse)
    {
        nFlags = 0x20;
        pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x20);
    }
    else
        pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, nState);
    if (pStatList)
    {
        if (STATLIST_GetState(pStatList) == pCurse->nState && pCurse->nSkill == (int)STATLIST_GetSkillId(pStatList))
        {
            const int nSkillLevel = STATLIST_GetSkillLevel(pStatList);
            if (pCurse->nSkillLevel == nSkillLevel)
            {
                if (pCurse->nDuration)
                {
                    const int nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
                    STATLIST_SetExpireFrame(pStatList, nExpireFrame);
                    EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
                }
                return pStatList;
            }
            if (pCurse->nSkillLevel < nSkillLevel)
                return 0;
        }
        D2Common_10474(pTarget, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    UNITROOM_RefreshUnit(pTarget);
    STATES_ToggleState(pTarget, nState, 1);
    int nExpireFrame = 0;
    if (pCurse->nDuration)
    {
        nExpireFrame = pGame->dwGameFrame + pCurse->nDuration;
        nFlags |= 2;
        EVENT_SetEvent(pGame, pCurse->pTarget, 12, nExpireFrame, 0, 0);
    }
    if (STATES_CheckStateMaskExpByStateId(nState))
        nFlags |= 0x800;
    if (pStatesTxtRecord->nStateFlags[0] & (unsigned char)gdwBitMasks[1])
        nFlags |= 8;
    pStatList = STATLIST_AllocStatList(!pTarget ? 0 : pTarget->pMemoryPool, nFlags, nExpireFrame, !pCurse->pUnit ? 6 : pCurse->pUnit->dwUnitType, !pCurse->pUnit ? -1 : pCurse->pUnit->dwUnitId);
    STATLIST_SetState(pStatList, nState);
    STATLIST_SetSkillId(pStatList, pCurse->nSkill);
    STATLIST_SetSkillLevel(pStatList, pCurse->nSkillLevel);
    if (pCurse->nStat != -1)
        STATLIST_SetStat(pStatList, pCurse->nStat, pCurse->nStatValue, 0);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    if (!pCurse->pStateRemoveCallback)
    {
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        return pStatList;
    }
    STATLIST_SetStatRemoveCallback(pStatList, pCurse->pStateRemoveCallback);
    return pStatList;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x0056EBE0
void __fastcall SKILLS_ApplyStateFromSkillParams(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nStatId, int nState, StatListRemoveCallback pfRemoveStatCallback)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);

    D2CurseStrc tCurse = {};
    tCurse.pUnit = pUnit;
    tCurse.nDuration = pSkillsTxtRecord->dwParam[1] * nSkillLevel;
    tCurse.nSkillLevel = nSkillLevel;
    tCurse.pTarget = pTarget;
    tCurse.nStatValue = (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[2] + pSkillsTxtRecord->dwParam[0];
    tCurse.nSkill = nSkillId;
    tCurse.nStat = nStatId;
    tCurse.nState = nState;
    tCurse.pStateRemoveCallback = pfRemoveStatCallback;
    D2_ASSERT(!pfRemoveStatCallback || !IsBadCodePtr((FARPROC)pfRemoveStatCallback), 0x52B);
    SKILLS_ApplyStateEffect(&tCurse);
}

// 0x0056F640
int __fastcall SKILLS_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bSkipMana)
{
    if (!pGame || !pUnit || !UNITS_GetRoom(pUnit))
        return 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    if (!bSkipMana && !SKILLS_HasManaOrChargesForUsedSkill(pUnit))
        return 0;
    if (!(pSkillsTxtRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            UNITS_SetUsedSkill(pUnit, 0);
            if ((!pUnit ? 6 : pUnit->dwUnitType) == 0)
                PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, 5, 0, 0, 1);
            return 0;
        }
    }
    int nX;
    int nY;
    if (pSkillsTxtRecord->nLineOfSight && D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1: nCollisionMask = 4; break;
        case 2: nCollisionMask = 0x1C09; break;
        case 3: nCollisionMask = 0x180; break;
        case 4: nCollisionMask = 0x804; break;
        case 5: nCollisionMask = 0x805; break;
        default: return 0;
        }
        if (!D2Common_11026(nX, nY, pUnit, nCollisionMask))
            return 0;
    }
    if (pSkillsTxtRecord->wSrvStartFunc < 0 || pSkillsTxtRecord->wSrvStartFunc >= 91)
        return 0;
    SkillStartFunc pStart = gpfnSkillSrvStartFunctions[pSkillsTxtRecord->wSrvStartFunc];
    int nResult;
    if (!pStart)
    {
        nResult = 1;
    }
    else
    {
        nResult = pStart(pGame, pUnit, nSkillId, nSkillLevel);
        if (nResult && !(pSkillsTxtRecord->nFlags[4] & gdwBitMasks[5]) && !bSkipMana)
            SKILLS_ConsumeSkillMana(pGame, pUnit, nSkillId, nSkillLevel);
    }
    if (nResult && (pSkillsTxtRecord->nFlags[0] & gdwBitMasks[6]))
        D2GAME_EVENTS_Delete(pGame, pUnit, 8, 0);
    return nResult;
}

// 0x005701B0
void __fastcall D2GAME_AssignSkill(D2UnitStrc* pUnit, int bLeftSkill, int nSkillId, int nFlags)
{
    if (nSkillId == SKILL_LEFTHANDSWING)
    {
        return;
    }

    if (!bLeftSkill && STATES_CheckState(pUnit, STATE_NOMANAREGEN))
    {
        STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nFlags);
    if (!pSkill)
    {
        return;
    }

    D2SkillStrc* pRightSkill = 0;
    if (bLeftSkill)
    {
        SKILLS_SetLeftActiveSkill(pUnit, nSkillId, nFlags);
    }
    else
    {
        pRightSkill = UNITS_GetRightSkill(pUnit);
        SKILLS_SetRightActiveSkill(pUnit, nSkillId, nFlags);
    }

    nFlags = -1;
    SKILLS_GetSkillInfo(pSkill, &nFlags, 0, 0, 0);
    if ((!pUnit ? UNIT_INVALID : pUnit->dwUnitType) == UNIT_PLAYER)
    {
        D2GAME_PACKETS_SendPacket0x23(UnitGetClient(pUnit, &gszSkillsSourceFile, 3499), (!pUnit ? UNIT_INVALID : pUnit->dwUnitType), !pUnit ? -1 : pUnit->dwUnitId, bLeftSkill, nSkillId, nFlags);
    }

    if (!bLeftSkill)
    {
        if (pRightSkill)
        {
            D2SkillsTxt* pRightSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, &gszSkillsSourceFile, 3507));
            if (pRightSkillsTxtRecord && pRightSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
            {
                if (pRightSkillsTxtRecord->nAuraState >= 0 || pRightSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pRightSkillsTxtRecord->nAuraState);
                    if (pStatList)
                    {
                        D2Common_10474(pUnit, pStatList);
                        STATLIST_FreeStatList(pStatList);
                    }

                    STATES_ToggleState(pUnit, pRightSkillsTxtRecord->nAuraState, 0);
                }

                D2GAME_EVENTS_Delete(SUNIT_GetGameFromUnit(pUnit), pUnit, EVENTTYPE_PERIODICSKILLS, -1);
            }
        }

        if (SKILLS_GetSkillsTxtRecordForceInline(nSkillId)->nFlags[SKILLSFLAGINDEX_AURA >> 3] & gdwBitMasks[SKILLSFLAGINDEX_AURA & 7])
        {
            SKILLS_StartAssignedAura(SUNIT_GetGameFromUnit(pUnit), pUnit, nSkillId);
        }
    }
}

// 0x0056E0C0
int __fastcall D2GAME_RollElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;

    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    const int nMinDamage = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMaxDamage = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nDamage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage;
    SKILLS_AddElementalDamage(pUnit, pDamage, pSkillsTxtRecord->nEType, nDamage, nLength, 0, 0);
    return nDamage;
}

// 0x0056E170
void __fastcall D2GAME_RollPhysicalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMinDamage = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
        const int nMaxDamage = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
        const int nDamage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage;
        pDamage->dwPhysDamage += nDamage;
    }
}

// 0x0056E1E0
int __fastcall SKILLS_GetCrossbowClassFlag(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClassId, -1, 1);
    return nWeaponClassId == 7 ? 0x1F : 0;
}


// 0x00570420
void __fastcall SKILLS_StunMonster(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nDelay)
{
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && !MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE) && !MONSTERS_IsBoss(0, pUnit))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nDelay);
        int nFrame = pGame->dwGameFrame;
        if (!pStatList)
        {
            const int nUnitGUID = pUnit->dwUnitId;
            const int nUnitType = pUnit->dwUnitType;
            nFrame += 100;
            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nFrame, nUnitType, nUnitGUID);
            if (pStatList)
            {
                EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
                STATLIST_SetState(pStatList, STATE_STUNNED);
                STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                STATES_ToggleState(pUnit, STATE_STUNNED, 1);
            }
        }
        else
        {
            nFrame += nDelay;
            D2COMMON_10476(pStatList, nFrame);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nFrame, 0, 0);
        }

        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_NEUTRAL, &modeChange);
        D2GAME_ModeChange(pGame, &modeChange, 1);
        pUnit->dwFlags &= ~UNITFLAG_DOUPDATE;
    }
}

static inline int sub_0056F1F0_DrainTargetItemDurability(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x0056F1F0
int __fastcall SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget;

    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            return 0;
        }

        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (!pDamage)
        {
            return 1;
        }

        if (pDamage->wResultFlags & 1)
        {
            UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
        }
    }

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget)
        {
            return 0;
        }

        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (!pDamage)
        {
            return 1;
        }

        if (pDamage->wResultFlags & 1)
        {
            const int nFormula = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
            const int nLength = nFormula < 1 ? 1 : nFormula;

            const int nExpireFrame = pGame->dwGameFrame + nLength;
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
                if (!pStatList)
                {
                    return 1;
                }
            }

            EVENT_SetEvent(pGame, pTarget, 0xC, nExpireFrame, 0, 0);
            STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
            STATLIST_SetState(pStatList, pSkillsTxtRecord->wAuraTargetState);
            D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
            STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
            SKILLS_ApplyAuraStatsToStatList(pTarget, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
        }
    }

    if (pSkillsTxtRecord->nAuraState > 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

            pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 4u, 0, nUnitType, nUnitGUID);
            if (!pStatList)
            {
                return 1;
            }

            STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        }

        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
        SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return sub_0056F1F0_DrainTargetItemDurability(pGame, pUnit);
}

// 0x00570530
void __fastcall SKILLS_StatRemoveCallback_ResetAiAndRefresh(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == 1)
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnitInline(pUnit), 0);
    }

    SKILLS_RemoveStateAndRefreshPassives(pUnit, nState, pStatList);
}

// 0x0056E210
void __fastcall SKILLS_RewindUnitAnimation(D2UnitStrc* pUnit, int nArg)
{
    SUNIT_RewindAnimationByPercentage(SUNIT_GetGameFromUnit(pUnit), pUnit, nArg);
}

// 0x0056E230
int __fastcall SKILLS_StartBasicAttack(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2UnitStrc* hTarget)
{
    D2_ASSERT(pUnit, 4625);
    D2_ASSERT(hTarget, 4626);
    D2_ASSERT(ptGame, 4627);

    SUNIT_SetCombatMode(ptGame, pUnit, 1);
    UNITS_SetUsedSkill(pUnit, 0);

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        StartModeID(ptGame, pUnit, pSkill, PLRMODE_ATTACK1, !hTarget ? UNIT_INVALID : hTarget->dwUnitType, !hTarget ? -1 : hTarget->dwUnitId, 1);
        break;

    case UNIT_MONSTER:
    {
        D2ModeChangeStrc tModeChange;
        MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_ATTACK1, &tModeChange);
        tModeChange.pTargetUnit = hTarget;
        D2GAME_ModeChange(ptGame, &tModeChange, 1);
        break;
    }
    }

    return 1;
}

// 0x0056E2F0
int __fastcall SKILLS_CanSwitchAi(D2UnitStrc* pUnit, int nAiSpecialState)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_IMP1 && STATES_CheckState(pUnit, STATE_ATTACHED))
        {
            return 0;
        }
    }

    return AIUTIL_CanUnitSwitchAi(pUnit, nAiSpecialState) != 0;
}

// 0x0056E370
int __fastcall SKILLS_UnitFindTest_Corpse(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg)
{
    if (D2COMMON_11021(pUnit))
    {
        return UNITFINDS_TestUnit(pUnit, pArg);
    }

    return 0;
}

// 0x0056E390
D2UnitStrc* __fastcall SKILLS_FindCorpseNearTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    if (pUnit && nSkillLevel > 0 && pTarget)
    {
        const int nX = CLIENTS_GetUnitX(pTarget);
        const int nY = CLIENTS_GetUnitY(pTarget);

        D2UnitFindArgStrc unitFindArg = {};
        unitFindArg.nFlags = 0x1002;
        unitFindArg.nX = nX;
        unitFindArg.nY = nY;
        unitFindArg.nSize = 10;

        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);

        D2UnitFindDataStrc unitFindData;
        UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, UNITS_GetRoom(pTarget), nX, nY, 10, SKILLS_UnitFindTest_Corpse, &unitFindArg);
        UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

        D2UnitStrc* pResult = 0;
        if (unitFindData.nIndex)
        {
            pResult = *unitFindData.pUnitsArray;
        }

        UNITFINDS_FreeUnitFindData(&unitFindData);
        return pResult;
    }

    return 0;
}

// 0x0056E450
int __fastcall SKILLS_IsMissileTargetPositionClear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    nMissileId = 0;
    int nY = 0;
    D2_ASSERT(pMissilesTxtRecord, 4737);

    if (pRoom)
    {
        D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nMissileId, &nY);
        if (nMissileId && nY)
        {
            return !COLLISION_CheckMaskWithSizeXY(pRoom, nMissileId, nY, pMissilesTxtRecord->nSize, pMissilesTxtRecord->nSize, 5);
        }
    }
    return 0;
}

// 0x0056E510
int __fastcall SKILLS_GetMeleeSearchRange(D2UnitStrc* pUnit)
{
    return UNITS_GetMeleeRange(pUnit) + 4;
}

// 0x0056E520
void __fastcall SKILLS_ApplyAttackRateModifier(D2UnitStrc* pUnit, int nAttackRate)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 4, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, STAT_ATTACKRATE, nAttackRate, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 0x12AB);
    }
}

// 0x0056E580
void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_MONSTER)
    {
        if (pOwner == pUnit)
        {
            AIGENERAL_DetachOwnedMinions(pUnit);
        }
        else
        {
            AIGENERAL_FreeMinionList(pUnit);
        }
    }
}

// 0x0056E5B0
int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord(pUnit->dwClassId);
            if (pCharStatsTxtRecord)
            {
                return pCharStatsTxtRecord->nWalkSpeed << 8;
            }
        }
        else if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxtRecord)
            {
                return pMonStatsTxtRecord->nVelocity << 8;
            }
        }
    }

    return 0x600;
}


int __stdcall MONSTERS_GetSpawnMode_XY(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0063EA70

// 0x0056E620
int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    int nMonsterId = MONSTERS_GetSpawnMode_XY(pUnit, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7);
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    nMonsterId = AIGENERAL_GetMinionSpawnClassId(pUnit);
    if (nMonsterId > 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x0056E680
unsigned short __fastcall SKILLS_SetDamageResultFlagsFromSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int nRangeOffset)
{
    if (!(pSkillsTxtRecord->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT))
    {
        pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), nRangeOffset);
        if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            pDamage->wResultFlags |= pSkillsTxtRecord->wResultFlags;
        }
    }
    else
    {
        pDamage->wResultFlags = pSkillsTxtRecord->wResultFlags;
    }

    return pDamage->wResultFlags;
}

// 0x0056E6F0
unsigned short __fastcall SKILLS_SetDamageResultFlags(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned short wResultFlags, int nToHitFactor, D2DamageStrc* pDamage, int nRangeOffset)
{
    if (!(wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT))
    {
        pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pOwner, pUnit, nToHitFactor, nRangeOffset);
        if (pDamage->wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            pDamage->wResultFlags |= wResultFlags;
        }
    }
    else
    {
        pDamage->wResultFlags = wResultFlags;
    }

    return pDamage->wResultFlags;
}

// 0x0056E740
D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nParam1, int nParam2, int nEventFunc, int nEventGroup, int nEventKey)
{
    if (nEventFunc >= 0 && nEventFunc < EVENTFN_COUNT && gpfnSkillEventCallbacks[nEventFunc])
    {
        return SUNITEVENT_Register(pGame, pUnit, nUnitEventType, nParam1, nParam2, gpfnSkillEventCallbacks[nEventFunc], nEventGroup, nEventKey);
    }

    return 0;
}

extern "C" void __cdecl SKILLS_SrvSt05_Jab(); // 0x005DA8F0
extern "C" void __cdecl SKILLS_SrvSt06_PowerStrike_ChargedStrike(); // 0x005DA940
extern "C" void __cdecl SKILLS_SrvSt08_Strafe(); // 0x005DACD0
extern "C" void __cdecl SKILLS_SrvSt10_LightningStrike(); // 0x005DB020
extern "C" void __cdecl SKILLS_SrvSt11_Inferno_ArcticBlast(); // 0x005C8FA0
extern "C" void __cdecl SKILLS_SrvSt12_Telekinesis_DragonFlight(); // 0x005C9030
extern "C" void __cdecl SKILLS_SrvSt13_ThunderStorm(); // 0x005C91C0
extern "C" void __cdecl SKILLS_SrvSt14_Hydra(); // 0x005C9220
extern "C" void __cdecl SKILLS_SrvSt15_RaiseSkeleton_Mage(); // 0x005C3070
extern "C" void __cdecl SKILLS_SrvSt16_PoisonDagger(); // 0x005C30A0
extern "C" void __cdecl SKILLS_SrvSt17_Poison_CorpseExplosion(); // 0x005C31C0
extern "C" void __cdecl SKILLS_SrvSt18_Attract(); // 0x005C3260
extern "C" void __cdecl SKILLS_SrvSt19_BonePrison(); // 0x005C3270
extern "C" void __cdecl SKILLS_SrvSt20_IronGolem(); // 0x005C32A0
extern "C" void __cdecl SKILLS_SrvSt21_Revive(); // 0x005C3350
extern "C" void __cdecl SKILLS_SrvSt22_PsychicHammer(); // 0x005D30F0
extern "C" void __cdecl SKILLS_SrvSt23_AssasinChargeStrikes(); // 0x005D32F0
extern "C" void __cdecl SKILLS_SrvSt24_DragonTalon(); // 0x005D5970
extern "C" void __cdecl SKILLS_SrvSt25_64_DragonClaw_MonFrenzy(); // 0x005D6330
extern "C" void __cdecl SKILLS_SrvSt26_BladeFury(); // 0x005D69D0
extern "C" void __cdecl SKILLS_SrvSt28_BladeShield(); // 0x005D7A00
extern "C" void __cdecl SKILLS_SrvSt29_Sacrifice(); // 0x005CE790
extern "C" void __cdecl SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(); // 0x005D7EA0
extern "C" void __cdecl SKILLS_SrvSt33_FindPotion_GrimWard(); // 0x005D80C0
extern "C" void __cdecl SKILLS_SrvSt34_FindItem(); // 0x005D8760
extern "C" void __cdecl SKILLS_SrvSt36_HolyShield(); // 0x005D0180
extern "C" void __cdecl SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(); // 0x005DAF40
extern "C" void __cdecl SKILLS_SrvSt38_Whirlwind(); // 0x005D8F50
extern "C" void __cdecl SKILLS_SrvSt39_Berserk(); // 0x005D97F0
extern "C" void __cdecl SKILLS_SrvSt40_Leap(); // 0x005D9D50
extern "C" void __cdecl SKILLS_SrvSt41_LeapAttack(); // 0x005DA540
extern "C" void __cdecl SKILLS_SrvSt42_FireHit(); // 0x005CAE40
extern "C" void __cdecl SKILLS_SrvSt43_MaggotEgg(); // 0x005CAF80
extern "C" void __cdecl SKILLS_SrvSt45_MaggotDown(); // 0x005CB270
extern "C" void __cdecl SKILLS_SrvSt46_AndrialSpray(); // 0x005CB4D0
extern "C" void __cdecl SKILLS_SrvSt48_SwarmMove(); // 0x005CBBF0
extern "C" void __cdecl SKILLS_SrvSt49_Nest_EvilHutSpawner(); // 0x005CBD10
extern "C" void __cdecl SKILLS_SrvSt50_QuickStrike(); // 0x005CBF30
extern "C" void __cdecl SKILLS_SrvSt51_Submerge(); // 0x005CC1D0
extern "C" void __cdecl SKILLS_SrvSt53_MonInferno(); // 0x005CC240
extern "C" void __cdecl SKILLS_SrvSt54_DiabRun(); // 0x005CD2C0
extern "C" void __cdecl SKILLS_SrvSt56_FeralRage_Maul(); // 0x005C7690
extern "C" void __cdecl SKILLS_SrvSt57_Rabies(); // 0x005C79E0
extern "C" void __cdecl SKILLS_SrvSt59_ImpInferno(); // 0x005D1280
extern "C" void __cdecl SKILLS_SrvSt60_SuckBlood(); // 0x005D1570
extern "C" void __cdecl SKILLS_SrvSt62_MinionSpawner(); // 0x005D2420
extern "C" void __cdecl SKILLS_SrvSt63_Corpse_VineCycler(); // 0x005D2A10
extern "C" void __cdecl sub_0056CAB0(); // 0x0056CAB0
extern "C" void __cdecl SKILLS_SrvSt58_FireClaws(); // 0x005C7E00
extern "C" void __cdecl sub_005CB730(); // 0x005CB730
extern "C" void __cdecl SKILLS_SrvSt52_Emerge(); // 0x005CC220
extern "C" void __cdecl SKILLS_SrvSt31_Charge(); // 0x005CF6B0
extern "C" void __cdecl SKILLS_SrvSt35_Vengeance(); // 0x005CFE10
extern "C" void __cdecl SKILLS_SrvSt61_SelfResurrect(); // 0x005D1BF0
extern "C" void __cdecl sub_005D7090(); // 0x005D7090
extern "C" void __cdecl sub_005DA8B0(); // 0x005DA8B0
extern "C" void __cdecl SKILLS_SrvSt07_Impale(); // 0x005DAB40
extern "C" void __cdecl SKILLS_SrvSt09_Fend(); // 0x005DAE30
extern "C" void __cdecl SKILLS_SrvSt44_MaggotUp(); // 0x005CB170
extern "C" void __cdecl SKILLS_SrvSt55_Mosquito(); // 0x005CD910
extern "C" void __cdecl SKILLITEM_EventFunc06_AttackerTakesDamage(); // 0x005BF670
extern "C" void __cdecl SKILLITEM_EventFunc08_Howl(); // 0x005BFA10
extern "C" void __cdecl SKILLITEM_EventFunc10_AttackerTakesLightDamage(); // 0x005BF720
extern "C" void __cdecl SKILLITEM_EventFunc11_ApplyFireDamage(); // 0x005BF7D0
extern "C" void __cdecl SKILLITEM_EventFunc12_ApplyColdDamage(); // 0x005BF880
extern "C" void __cdecl SKILLITEM_EventFunc15_OpenWounds(); // 0x005BFE60
extern "C" void __cdecl SKILLITEM_EventFunc16_CrushingBlow(); // 0x005BFFC0
extern "C" void __cdecl SKILLITEM_EventFunc18_HealAfterDemonKill(); // 0x005C0260
extern "C" void __cdecl SKILLITEM_EventFunc19_Slow(); // 0x005C0310
extern "C" void __cdecl SKILLITEM_EventFunc20_SkillOnAttackHitKill(); // 0x005C0470
extern "C" void __cdecl SKILLITEM_EventFunc21_SkillOnGetHit(); // 0x005C05A0
extern "C" void __cdecl SKILLITEM_EventFunc28_HealAfterKill(); // 0x005C01D0
extern "C" void __cdecl SKILLITEM_EventFunc29_RestInPeace(); // 0x005C0770
extern "C" void __cdecl SKILLITEM_EventFunc30_SkillOnDeathLevelup(); // 0x005C0670
extern "C" void __cdecl SKILLS_EventFunc01_ChillingArmor(); // 0x005CAB40
extern "C" void __cdecl SKILLS_EventFunc02_FrozenArmor(); // 0x005CAC50
extern "C" void __cdecl SKILLS_EventFunc03_ShiverArmor(); // 0x005CAD40
extern "C" void __cdecl SKILLS_EventFunc04_ReflectPhysicalDamage(); // 0x005C5F50
extern "C" void __cdecl SKILLS_EventFunc24_EnergyShield(); // 0x005CA6C0
extern "C" void __cdecl SKILLS_EventFunc27_Slow(); // 0x005C6760
extern "C" void __cdecl SKILLITEM_EventFunc07_Knockback(); // 0x005BF960
extern "C" void __cdecl sub_005BFAA0(); // 0x005BFAA0
extern "C" void __cdecl SKILLITEM_EventFunc13_DamageToMana(); // 0x005BFBB0
extern "C" void __cdecl SKILLITEM_EventFunc14_Freeze(); // 0x005BFC60
extern "C" void __cdecl SKILLITEM_EventFunc17_ManaAfterKill(); // 0x005C0130
extern "C" void __cdecl SKILLITEM_EventFunc31_Reanimate(); // 0x005C09E0
extern "C" void __cdecl SKILLS_EventFunc05_LifeTap(); // 0x005C61E0
extern "C" void __cdecl SKILLS_EventFunc22_AbsorbPhysicalDamage(); // 0x005C6370
extern "C" void __cdecl sub_005C6530(); // 0x005C6530
extern "C" void __cdecl SKILLS_EventFunc26_ShareDamageWithOwner(); // 0x005C6690
extern "C" void __cdecl SKILLS_EventFunc25_AbsorbElementalDamage(); // 0x005C87A0
extern "C" void __cdecl SKILLS_SrvDo001_Attack_LeftHandSwing(); // 0x0056F070
extern "C" void __cdecl SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(); // 0x0056F1F0
extern "C" void __cdecl SKILLS_SrvDo003_Throw(); // 0x0056F460
extern "C" void __cdecl SKILLS_SrvDo004_Unsummon(); // 0x0056CC20
extern "C" void __cdecl SKILLS_SrvDo005_LeftHandThrow(); // 0x0056F550
extern "C" void __cdecl SKILLS_SrvDo007_Jab(); // 0x005DB2D0
extern "C" void __cdecl SKILLS_SrvDo011_ChargedStrike(); // 0x005DB850
extern "C" void __cdecl SKILLS_SrvDo016_Valkyrie(); // 0x005DC1E0
extern "C" void __cdecl SKILLS_SrvDo017_ChargedBolt_BoltSentry(); // 0x005C9300
extern "C" void __cdecl SKILLS_SrvDo018_DefensiveBuff(); // 0x005C9480
extern "C" void __cdecl SKILLS_SrvDo019_Inferno_ArcticBlast(); // 0x005C9640
extern "C" void __cdecl SKILLS_SrvDo020_StaticField(); // 0x005C9800
extern "C" void __cdecl SKILLS_SrvDo022_NovaAttack(); // 0x005C9B50
extern "C" void __cdecl SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(); // 0x005C9C10
extern "C" void __cdecl SKILLS_SrvDo025_Enchant(); // 0x005CA030
extern "C" void __cdecl SKILLS_SrvDo026_ChainLightning(); // 0x005CA1B0
extern "C" void __cdecl SKILLS_SrvDo027_Teleport(); // 0x005CA360
extern "C" void __cdecl SKILLS_SrvDo029_ThunderStorm(); // 0x005CA4D0
extern "C" void __cdecl SKILLS_SrvDo030_Curse(); // 0x005C37C0
extern "C" void __cdecl SKILLS_SrvDo032_PoisonDagger(); // 0x005C4CD0
extern "C" void __cdecl SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2(); // 0x005D4DB0
extern "C" void __cdecl SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1(); // 0x005D5010
extern "C" void __cdecl SKILLS_SrvDo043_ShockField(); // 0x005D5D70
extern "C" void __cdecl SKILLS_SrvDo048_BladeFury(); // 0x005D68A0
extern "C" void __cdecl SKILLS_SrvDo053_Unused(); // 0x005D7B60
extern "C" void __cdecl SKILLS_SrvDo054_BladeShield(); // 0x005D7E10
extern "C" void __cdecl SKILLS_SrvDo056_Golem(); // 0x005C5100
extern "C" void __cdecl SKILLS_SrvDo058_Revive(); // 0x005C56C0
extern "C" void __cdecl SKILLS_SrvDo059_Attract(); // 0x005C3B90
extern "C" void __cdecl SKILLS_SrvDo061_Confuse(); // 0x005C3F20
extern "C" void __cdecl SKILLS_SrvDo063_PoisonExplosion(); // 0x005C5E60
extern "C" void __cdecl SKILLS_SrvDo064_Sacrifice(); // 0x005CE8E0
extern "C" void __cdecl SKILLS_SrvDo065_BasicAura(); // 0x005CF010
extern "C" void __cdecl SKILLS_SrvDo068_BasicShout(); // 0x005D83E0
extern "C" void __cdecl SKILLS_SrvDo069_FindPotion(); // 0x005D81C0
extern "C" void __cdecl SKILLS_SrvDo070_DoubleSwing(); // 0x005D8470
extern "C" void __cdecl SKILLS_SrvDo071_Taunt(); // 0x005D8570
extern "C" void __cdecl SKILLS_SrvDo073_BlessedHammer(); // 0x005D0040
extern "C" void __cdecl SKILLS_SrvDo076_Whirlwind(); // 0x005D9580
extern "C" void __cdecl SKILLS_SrvDo077_Leap(); // 0x005DA370
extern "C" void __cdecl SKILLS_SrvDo078_LeapAttack(); // 0x005DA7E0
extern "C" void __cdecl SKILLS_SrvDo081_HolyFreeze(); // 0x005D0920
extern "C" void __cdecl SKILLS_SrvDo083_FireHit(); // 0x005CAF30
extern "C" void __cdecl SKILLS_SrvDo084_MaggotEgg(); // 0x005CAFA0
extern "C" void __cdecl SKILLS_SrvDo085_UnholyBolt_ShamanFire(); // 0x005CB0C0
extern "C" void __cdecl SKILLS_SrvDo086_MaggotDown(); // 0x005CB300
extern "C" void __cdecl SKILLS_SrvDo087_MaggotLay(); // 0x005CB3C0
extern "C" void __cdecl SKILLS_SrvDo088_AndrialSpray(); // 0x005CB580
extern "C" void __cdecl SKILLS_SrvDo089_Jump(); // 0x005CB940
extern "C" void __cdecl SKILLS_SrvDo090_SwarmMove(); // 0x005CBC80
extern "C" void __cdecl SKILLS_SrvDo091_Nest_EvilHutSpawner(); // 0x005CBE00
extern "C" void __cdecl SKILLS_SrvDo092_QuickStrike(); // 0x005CBF90
extern "C" void __cdecl SKILLS_SrvDo094_Submerge(); // 0x005CC1F0
extern "C" void __cdecl SKILLS_SrvDo095_MonInferno(); // 0x005CC4E0
extern "C" void __cdecl SKILLS_SrvDo096_ZakarumHeal_Bestow(); // 0x005CC840
extern "C" void __cdecl SKILLS_SrvDo097_Resurrect(); // 0x005CCB10
extern "C" void __cdecl SKILLS_SrvDo098_MonTeleport(); // 0x005CCC80
extern "C" void __cdecl SKILLS_SrvDo101_FingerMageSpider(); // 0x005CCFA0
extern "C" void __cdecl SKILLS_SrvDo102_DiabWall(); // 0x005CD1C0
extern "C" void __cdecl SKILLS_SrvDo103_DiabRun(); // 0x005CD380
extern "C" void __cdecl SKILLS_SrvDo104_DiabPrison(); // 0x005CD5D0
extern "C" void __cdecl SKILLS_SrvDo105_DesertTurret(); // 0x005CD6A0
extern "C" void __cdecl SKILLS_SrvDo106_ArcaneTower(); // 0x005CD870
extern "C" void __cdecl SKILLS_SrvDo110_Hireable_RogueMissile(); // 0x005CE1B0
extern "C" void __cdecl SKILLS_SrvDo111_FetishAura(); // 0x005CE670
extern "C" void __cdecl SKILLS_SrvDo112_MonCurseCast(); // 0x005CE2B0
extern "C" void __cdecl SKILLS_SrvDo113_Scroll_Book(); // 0x005BF3D0
extern "C" void __cdecl SKILLS_SrvDo114_Raven(); // 0x005C6910
extern "C" void __cdecl SKILLS_SrvDo115_Vines(); // 0x005C6A80
extern "C" void __cdecl SKILLS_SrvDo116_Wearwolf_Wearbear(); // 0x005C6EC0
extern "C" void __cdecl SKILLS_SrvDo117_Firestorm(); // 0x005C7160
extern "C" void __cdecl SKILLS_SrvDo118_Twister_Tornado(); // 0x005C72F0
extern "C" void __cdecl SKILLS_SrvDo119_DruidSummon(); // 0x005C7390
extern "C" void __cdecl SKILLS_SrvDo120_FeralRage_Maul(); // 0x005C77C0
extern "C" void __cdecl SKILLS_SrvDo121_Rabies(); // 0x005C8AD0
extern "C" void __cdecl SKILLS_SrvDo122_Hunger(); // 0x005C7F10
extern "C" void __cdecl SKILLS_SrvDo125_WakeOfDestruction(); // 0x005D1170
extern "C" void __cdecl SKILLS_SrvDo126_ImpInferno(); // 0x005D1350
extern "C" void __cdecl SKILLS_SrvDo128_CryHelp(); // 0x005D1800
extern "C" void __cdecl SKILLS_SrvDo129_ImpTeleport(); // 0x005D1AB0
extern "C" void __cdecl SKILLS_SrvDo132_ImpFireMissile(); // 0x005D2090
extern "C" void __cdecl SKILLS_SrvDo136_DeathMaul(); // 0x005D25B0
extern "C" void __cdecl SKILLS_SrvDo138_Unused(); // 0x005D27B0
extern "C" void __cdecl SKILLS_SrvDo142_Unused(); // 0x005D7CE0
extern "C" void __cdecl SKILLS_SrvDo145_PeriodicAreaDamage(); // 0x005C8380
extern "C" void __cdecl SKILLS_SrvDo147_Unused(); // 0x005D2B20
extern "C" void __cdecl SKILLS_SrvDo149_NecromageMissile(); // 0x005CE0B0
extern "C" void __cdecl SKILLS_SrvDo150_Smite(); // 0x005CE9F0
extern "C" void __cdecl SKILLS_SrvDo151_Unused(); // 0x005CA260
extern "C" void __cdecl SKILLS_SrvDo152_DiabLight(); // 0x005CC690
extern "C" void __cdecl sub_005C4B00(); // 0x005C4B00
extern "C" void __cdecl SKILLS_ExplodeCorpse(); // 0x005C4DF0
extern "C" void __cdecl SKILLS_SrvDo057_IronGolem(); // 0x005C5250
extern "C" void __cdecl sub_005C58B0(); // 0x005C58B0
extern "C" void __cdecl sub_005C5D00(); // 0x005C5D00
extern "C" void __cdecl SKILLS_SrvDo123_Volcano(); // 0x005C8080
extern "C" void __cdecl SKILLS_SrvDo124_Armageddon_Hurricane(); // 0x005C8190
extern "C" void __cdecl SKILLS_SrvDo146_PeriodicRandomMissile(); // 0x005C8520
extern "C" void __cdecl SKILLS_SrvDo021_Telekinesis(); // 0x005C98F0
extern "C" void __cdecl sub_005C9EA0(); // 0x005C9EA0
extern "C" void __cdecl SKILLS_SrvDo144_Hydra(); // 0x005CA910
extern "C" void __cdecl sub_005CC050(); // 0x005CC050
extern "C" void __cdecl sub_005CCE80(); // 0x005CCE80
extern "C" void __cdecl SKILLS_SrvDo107_Mosquito(); // 0x005CDA00
extern "C" void __cdecl sub_005CDC10(); // 0x005CDC10
extern "C" void __cdecl SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction(); // 0x005CF3A0
extern "C" void __cdecl sub_005CF900(); // 0x005CF900
extern "C" void __cdecl sub_005D0350(); // 0x005D0350
extern "C" void __cdecl SKILLS_SrvDo080_FistOfTheHeavens(); // 0x005D0670
extern "C" void __cdecl SKILLS_SrvDo082_Redemption(); // 0x005D0E90
extern "C" void __cdecl SKILLS_SrvDo127_SuckBlood(); // 0x005D16A0
extern "C" void __cdecl SKILLS_SrvDo130_VineAttack(); // 0x005D1CD0
extern "C" void __cdecl SKILLS_SrvDo131_OverseerWhip(); // 0x005D1F70
extern "C" void __cdecl sub_005D3140(); // 0x005D3140
extern "C" void __cdecl sub_005D8780(); // 0x005D8780
extern "C" void __cdecl SKILLS_SrvDo009_Frenzy(); // 0x005D8E00
extern "C" void __cdecl sub_005DBC60(); // 0x005DBC60
extern "C" void __cdecl SKILLS_SrvDo099_PrimePoisonNova(); // 0x005CCD10
extern "C" void __cdecl SKILLS_SrvDo014_LightningStrike(); // 0x005DBE50
extern "C" void __cdecl SKILLS_SrvDo006_InnerSight_SlowMissiles(); // 0x005DB1C0
extern "C" void __cdecl SKILLS_SrvDo010_GuidedArrow_BoneSpirit(); // 0x005DB6D0
extern "C" void __cdecl SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(); // 0x005D3490
extern "C" void __cdecl SKILLS_SrvDo035_FistsOfFire_ClawsOfThunder_BladesOfIce(); // 0x005D35D0
extern "C" void __cdecl SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3(); // 0x005D4E70
extern "C" void __cdecl SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2(); // 0x005D3E80
extern "C" void __cdecl SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3(); // 0x005D3F90
extern "C" void __cdecl SKILLS_SrvDo041_RoyalStrike_ProgressiveFn3(); // 0x005D5080
extern "C" void __cdecl SKILLS_SrvDo042_DragonTalon(); // 0x005D5A30
extern "C" void __cdecl SKILLS_SrvDo044_BladeSentinel(); // 0x005D6020
extern "C" void __cdecl SKILLS_SrvDo045_Sentry(); // 0x005D6170
extern "C" void __cdecl SKILLS_SrvDo046_DragonClaw(); // 0x005D6340
extern "C" void __cdecl SKILLS_SrvDo047_CloakOfShadows(); // 0x005D6630
extern "C" void __cdecl SKILLS_SrvDo049_ShadowWarrior_Master(); // 0x005D6E70
extern "C" void __cdecl SKILLS_SrvDo050_DragonTail(); // 0x005D7180
extern "C" void __cdecl SKILLS_SrvDo051_MindBlast(); // 0x005D76E0
extern "C" void __cdecl SKILLS_SrvDo052_DragonFlight(); // 0x005D7850
extern "C" void __cdecl SKILLS_SrvDo074_DoubleThrow(); // 0x005D88B0
extern "C" void __cdecl SKILLS_SrvDo075_GrimWard(); // 0x005D89B0
extern "C" void __cdecl SKILLS_SrvDo133_Impregnate(); // 0x005D2250
extern "C" void __cdecl SKILLS_SrvDo134_SiegeBeastStomp(); // 0x005D2320
extern "C" void __cdecl SKILLS_SrvDo135_MinionSpawner(); // 0x005D2490
extern "C" void __cdecl SKILLS_SrvDo137_FenrisRage(); // 0x005D26F0
extern "C" void __cdecl SKILLS_SrvDo139_BaalColdMissiles(); // 0x005D2940
extern "C" void __cdecl SKILLS_SrvDo140_BaalTentacle(); // 0x005D2C20
extern "C" void __cdecl SKILLS_SrvDo141_BaalCorpseExplode(); // 0x005D2E80
extern "C" void __cdecl SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn(); // 0x005D4F40
extern "C" void __cdecl SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(); // 0x005CA3E0
extern "C" void __cdecl SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave(); // 0x005DB410
extern "C" void __cdecl SKILLS_SrvDo012_Strafe(); // 0x005DBA40
extern "C" void __cdecl SKILLS_SrvDo015_Dopplezon(); // 0x005DC000
extern "C" void __cdecl SKILLS_HasTarget(); // 0x005CDF00
extern "C" void __cdecl SKILLS_SrvDo109_MonFrenzy(); // 0x005CDF10
extern "C" void __cdecl SKILLS_SrvDo148_DoomKnightMissile(); // 0x005CDFB0

#pragma pack(push, 1)
struct d2data_00732100_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
    unsigned char b15[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007325B0_t
{
    unsigned char b0[4];
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
    const void* p15;
    const void* p16;
    const void* p17;
    const void* p18;
    const void* p19;
    const void* p20;
    const void* p21;
    const void* p22;
    const void* p23;
    const void* p24;
    const void* p25;
    const void* p26;
    const void* p27;
    const void* p28;
    const void* p29;
    const void* p30;
    const void* p31;
    unsigned char b32[72];
};
#pragma pack(pop)

extern "C" struct d2data_00732100_t gData_00732100; // 0x00732100
extern "C" struct d2data_007325B0_t gData_007325B0; // 0x007325B0
extern "C" SkillDoFunc gData_007322B0[192]; // 0x007322B0

extern "C" struct d2data_00732100_t gData_00732100 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14",
    { 0x00 }
}; // 0x00732100

extern const int gnMissilePatternYOffsets[8] = { 0, 0, 20, -20, 14, 14, -14, -14 }; // 0x006E1488

extern const int gnMissilePatternXOffsets[8] = { 20, -20, 0, 0, 14, -14, -14, 14 }; // 0x006E14A8

extern const int gnMissilePatternOffsets2[7] = { 8, 2, 11, 4, 13, 6, 9 }; // 0x006E14C8

extern const int gnMissilePatternSignY[4] = { -1, -1, 1, 1 }; // 0x006E14E4

extern const int gnMissilePatternOffsets1[7] = { 18, 20, 17, 20, 15, 19, 18 }; // 0x006E14F4

extern const int gnMissilePatternSignX[4] = { -1, 1, 1, -1 }; // 0x006E1510

extern "C" struct d2data_007325B0_t gData_007325B0 = {
    { 0x00 },
    (const void*)(unsigned int)&SKILLS_EventFunc01_ChillingArmor,
    (const void*)(unsigned int)&SKILLS_EventFunc02_FrozenArmor,
    (const void*)(unsigned int)&SKILLS_EventFunc03_ShiverArmor,
    (const void*)(unsigned int)&SKILLS_EventFunc04_ReflectPhysicalDamage,
    (const void*)(unsigned int)&SKILLS_EventFunc05_LifeTap,
    (const void*)(unsigned int)&SKILLITEM_EventFunc06_AttackerTakesDamage,
    (const void*)(unsigned int)&SKILLITEM_EventFunc07_Knockback,
    (const void*)(unsigned int)&SKILLITEM_EventFunc08_Howl,
    (const void*)(unsigned int)&sub_005BFAA0,
    (const void*)(unsigned int)&SKILLITEM_EventFunc10_AttackerTakesLightDamage,
    (const void*)(unsigned int)&SKILLITEM_EventFunc11_ApplyFireDamage,
    (const void*)(unsigned int)&SKILLITEM_EventFunc12_ApplyColdDamage,
    (const void*)(unsigned int)&SKILLITEM_EventFunc13_DamageToMana,
    (const void*)(unsigned int)&SKILLITEM_EventFunc14_Freeze,
    (const void*)(unsigned int)&SKILLITEM_EventFunc15_OpenWounds,
    (const void*)(unsigned int)&SKILLITEM_EventFunc16_CrushingBlow,
    (const void*)(unsigned int)&SKILLITEM_EventFunc17_ManaAfterKill,
    (const void*)(unsigned int)&SKILLITEM_EventFunc18_HealAfterDemonKill,
    (const void*)(unsigned int)&SKILLITEM_EventFunc19_Slow,
    (const void*)(unsigned int)&SKILLITEM_EventFunc20_SkillOnAttackHitKill,
    (const void*)(unsigned int)&SKILLITEM_EventFunc21_SkillOnGetHit,
    (const void*)(unsigned int)&SKILLS_EventFunc22_AbsorbPhysicalDamage,
    (const void*)(unsigned int)&sub_005C6530,
    (const void*)(unsigned int)&SKILLS_EventFunc24_EnergyShield,
    (const void*)(unsigned int)&SKILLS_EventFunc25_AbsorbElementalDamage,
    (const void*)(unsigned int)&SKILLS_EventFunc26_ShareDamageWithOwner,
    (const void*)(unsigned int)&SKILLS_EventFunc27_Slow,
    (const void*)(unsigned int)&SKILLITEM_EventFunc28_HealAfterKill,
    (const void*)(unsigned int)&SKILLITEM_EventFunc29_RestInPeace,
    (const void*)(unsigned int)&SKILLITEM_EventFunc30_SkillOnDeathLevelup,
    (const void*)(unsigned int)&SKILLITEM_EventFunc31_Reanimate,
    { 0x00 }
}; // 0x007325B0
#pragma comment(linker, "/alternatename:?gpfnSkillEventCallbacks@@3QBQ6IHPAUD2GameStrc@@HPAUD2UnitStrc@@1PAUD2DamageStrc@@HH@ZB=_gData_007325B0")

extern const int gnRandomElemTypes[4] = { 1, 2, 4, 5 }; // 0x006E1278

extern SkillStartFunc gpfnSkillSrvStartFunctions[92] = {
    0, (SkillStartFunc)&SKILLS_SrvSt01_Attack_LeftHandSwing, (SkillStartFunc)&SKILLS_SrvSt02_Kick, (SkillStartFunc)&SKILLS_SrvSt03_Unsummon, (SkillStartFunc)&sub_005DA8B0, (SkillStartFunc)&SKILLS_SrvSt05_Jab, (SkillStartFunc)&SKILLS_SrvSt06_PowerStrike_ChargedStrike, (SkillStartFunc)&SKILLS_SrvSt07_Impale, (SkillStartFunc)&SKILLS_SrvSt08_Strafe, (SkillStartFunc)&SKILLS_SrvSt09_Fend, (SkillStartFunc)&SKILLS_SrvSt10_LightningStrike, (SkillStartFunc)&SKILLS_SrvSt11_Inferno_ArcticBlast, (SkillStartFunc)&SKILLS_SrvSt12_Telekinesis_DragonFlight, (SkillStartFunc)&SKILLS_SrvSt13_ThunderStorm, (SkillStartFunc)&SKILLS_SrvSt14_Hydra, (SkillStartFunc)&SKILLS_SrvSt15_RaiseSkeleton_Mage,
    (SkillStartFunc)&SKILLS_SrvSt16_PoisonDagger, (SkillStartFunc)&SKILLS_SrvSt17_Poison_CorpseExplosion, (SkillStartFunc)&SKILLS_SrvSt18_Attract, (SkillStartFunc)&SKILLS_SrvSt19_BonePrison, (SkillStartFunc)&SKILLS_SrvSt20_IronGolem, (SkillStartFunc)&SKILLS_SrvSt21_Revive, (SkillStartFunc)&SKILLS_SrvSt22_PsychicHammer, (SkillStartFunc)&SKILLS_SrvSt23_AssasinChargeStrikes, (SkillStartFunc)&SKILLS_SrvSt24_DragonTalon, (SkillStartFunc)&SKILLS_SrvSt25_64_DragonClaw_MonFrenzy, (SkillStartFunc)&SKILLS_SrvSt26_BladeFury, (SkillStartFunc)&sub_005D7090, (SkillStartFunc)&SKILLS_SrvSt28_BladeShield, (SkillStartFunc)&SKILLS_SrvSt29_Sacrifice, 0, (SkillStartFunc)&SKILLS_SrvSt31_Charge,
    (SkillStartFunc)&SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite, (SkillStartFunc)&SKILLS_SrvSt33_FindPotion_GrimWard, (SkillStartFunc)&SKILLS_SrvSt34_FindItem, (SkillStartFunc)&SKILLS_SrvSt35_Vengeance, (SkillStartFunc)&SKILLS_SrvSt36_HolyShield, (SkillStartFunc)&SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy, (SkillStartFunc)&SKILLS_SrvSt38_Whirlwind, (SkillStartFunc)&SKILLS_SrvSt39_Berserk, (SkillStartFunc)&SKILLS_SrvSt40_Leap, (SkillStartFunc)&SKILLS_SrvSt41_LeapAttack, (SkillStartFunc)&SKILLS_SrvSt42_FireHit, (SkillStartFunc)&SKILLS_SrvSt43_MaggotEgg, (SkillStartFunc)&SKILLS_SrvSt44_MaggotUp, (SkillStartFunc)&SKILLS_SrvSt45_MaggotDown, (SkillStartFunc)&SKILLS_SrvSt46_AndrialSpray, (SkillStartFunc)&sub_005CB730,
    (SkillStartFunc)&SKILLS_SrvSt48_SwarmMove, (SkillStartFunc)&SKILLS_SrvSt49_Nest_EvilHutSpawner, (SkillStartFunc)&SKILLS_SrvSt50_QuickStrike, (SkillStartFunc)&SKILLS_SrvSt51_Submerge, (SkillStartFunc)&SKILLS_SrvSt52_Emerge, (SkillStartFunc)&SKILLS_SrvSt53_MonInferno, (SkillStartFunc)&SKILLS_SrvSt54_DiabRun, (SkillStartFunc)&SKILLS_SrvSt55_Mosquito, (SkillStartFunc)&SKILLS_SrvSt56_FeralRage_Maul, (SkillStartFunc)&SKILLS_SrvSt57_Rabies, (SkillStartFunc)&SKILLS_SrvSt58_FireClaws, (SkillStartFunc)&SKILLS_SrvSt59_ImpInferno, (SkillStartFunc)&SKILLS_SrvSt60_SuckBlood, (SkillStartFunc)&SKILLS_SrvSt61_SelfResurrect, (SkillStartFunc)&SKILLS_SrvSt62_MinionSpawner, (SkillStartFunc)&SKILLS_SrvSt63_Corpse_VineCycler,
    (SkillStartFunc)&SKILLS_HasTarget, (SkillStartFunc)&sub_0056CAB0
}; // 0x00732140

extern "C" SkillDoFunc gData_007322B0[192] = {
    0, (SkillDoFunc)&SKILLS_SrvDo001_Attack_LeftHandSwing, (SkillDoFunc)&SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws, (SkillDoFunc)&SKILLS_SrvDo003_Throw, (SkillDoFunc)&SKILLS_SrvDo004_Unsummon, (SkillDoFunc)&SKILLS_SrvDo005_LeftHandThrow, (SkillDoFunc)&SKILLS_SrvDo006_InnerSight_SlowMissiles, (SkillDoFunc)&SKILLS_SrvDo007_Jab, (SkillDoFunc)&SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave, (SkillDoFunc)&SKILLS_SrvDo009_Frenzy, (SkillDoFunc)&SKILLS_SrvDo010_GuidedArrow_BoneSpirit, (SkillDoFunc)&SKILLS_SrvDo011_ChargedStrike, (SkillDoFunc)&SKILLS_SrvDo012_Strafe, (SkillDoFunc)&sub_005DBC60, (SkillDoFunc)&SKILLS_SrvDo014_LightningStrike, (SkillDoFunc)&SKILLS_SrvDo015_Dopplezon,
    (SkillDoFunc)&SKILLS_SrvDo016_Valkyrie, (SkillDoFunc)&SKILLS_SrvDo017_ChargedBolt_BoltSentry, (SkillDoFunc)&SKILLS_SrvDo018_DefensiveBuff, (SkillDoFunc)&SKILLS_SrvDo019_Inferno_ArcticBlast, (SkillDoFunc)&SKILLS_SrvDo020_StaticField, (SkillDoFunc)&SKILLS_SrvDo021_Telekinesis, (SkillDoFunc)&SKILLS_SrvDo022_NovaAttack, (SkillDoFunc)&SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay, (SkillDoFunc)&sub_005C9EA0, (SkillDoFunc)&SKILLS_SrvDo025_Enchant, (SkillDoFunc)&SKILLS_SrvDo026_ChainLightning, (SkillDoFunc)&SKILLS_SrvDo027_Teleport, (SkillDoFunc)&SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult, (SkillDoFunc)&SKILLS_SrvDo029_ThunderStorm, (SkillDoFunc)&SKILLS_SrvDo030_Curse, (SkillDoFunc)&sub_005C4B00,
    (SkillDoFunc)&SKILLS_SrvDo032_PoisonDagger, (SkillDoFunc)&sub_005D3140, (SkillDoFunc)&SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike, (SkillDoFunc)&SKILLS_SrvDo035_FistsOfFire_ClawsOfThunder_BladesOfIce, (SkillDoFunc)&SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2, (SkillDoFunc)&SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3, (SkillDoFunc)&SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2, (SkillDoFunc)&SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3, (SkillDoFunc)&SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1, (SkillDoFunc)&SKILLS_SrvDo041_RoyalStrike_ProgressiveFn3, (SkillDoFunc)&SKILLS_SrvDo042_DragonTalon, (SkillDoFunc)&SKILLS_SrvDo043_ShockField, (SkillDoFunc)&SKILLS_SrvDo044_BladeSentinel, (SkillDoFunc)&SKILLS_SrvDo045_Sentry, (SkillDoFunc)&SKILLS_SrvDo046_DragonClaw, (SkillDoFunc)&SKILLS_SrvDo047_CloakOfShadows,
    (SkillDoFunc)&SKILLS_SrvDo048_BladeFury, (SkillDoFunc)&SKILLS_SrvDo049_ShadowWarrior_Master, (SkillDoFunc)&SKILLS_SrvDo050_DragonTail, (SkillDoFunc)&SKILLS_SrvDo051_MindBlast, (SkillDoFunc)&SKILLS_SrvDo052_DragonFlight, (SkillDoFunc)&SKILLS_SrvDo053_Unused, (SkillDoFunc)&SKILLS_SrvDo054_BladeShield, (SkillDoFunc)&SKILLS_ExplodeCorpse, (SkillDoFunc)&SKILLS_SrvDo056_Golem, (SkillDoFunc)&SKILLS_SrvDo057_IronGolem, (SkillDoFunc)&SKILLS_SrvDo058_Revive, (SkillDoFunc)&SKILLS_SrvDo059_Attract, (SkillDoFunc)&sub_005C58B0, (SkillDoFunc)&SKILLS_SrvDo061_Confuse, (SkillDoFunc)&sub_005C5D00, (SkillDoFunc)&SKILLS_SrvDo063_PoisonExplosion,
    (SkillDoFunc)&SKILLS_SrvDo064_Sacrifice, (SkillDoFunc)&SKILLS_SrvDo065_BasicAura, (SkillDoFunc)&SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction, (SkillDoFunc)&sub_005CF900, (SkillDoFunc)&SKILLS_SrvDo068_BasicShout, (SkillDoFunc)&SKILLS_SrvDo069_FindPotion, (SkillDoFunc)&SKILLS_SrvDo070_DoubleSwing, (SkillDoFunc)&SKILLS_SrvDo071_Taunt, (SkillDoFunc)&sub_005D8780, (SkillDoFunc)&SKILLS_SrvDo073_BlessedHammer, (SkillDoFunc)&SKILLS_SrvDo074_DoubleThrow, (SkillDoFunc)&SKILLS_SrvDo075_GrimWard, (SkillDoFunc)&SKILLS_SrvDo076_Whirlwind, (SkillDoFunc)&SKILLS_SrvDo077_Leap, (SkillDoFunc)&SKILLS_SrvDo078_LeapAttack, (SkillDoFunc)&sub_005D0350,
    (SkillDoFunc)&SKILLS_SrvDo080_FistOfTheHeavens, (SkillDoFunc)&SKILLS_SrvDo081_HolyFreeze, (SkillDoFunc)&SKILLS_SrvDo082_Redemption, (SkillDoFunc)&SKILLS_SrvDo083_FireHit, (SkillDoFunc)&SKILLS_SrvDo084_MaggotEgg, (SkillDoFunc)&SKILLS_SrvDo085_UnholyBolt_ShamanFire, (SkillDoFunc)&SKILLS_SrvDo086_MaggotDown, (SkillDoFunc)&SKILLS_SrvDo087_MaggotLay, (SkillDoFunc)&SKILLS_SrvDo088_AndrialSpray, (SkillDoFunc)&SKILLS_SrvDo089_Jump, (SkillDoFunc)&SKILLS_SrvDo090_SwarmMove, (SkillDoFunc)&SKILLS_SrvDo091_Nest_EvilHutSpawner, (SkillDoFunc)&SKILLS_SrvDo092_QuickStrike, (SkillDoFunc)&sub_005CC050, (SkillDoFunc)&SKILLS_SrvDo094_Submerge, (SkillDoFunc)&SKILLS_SrvDo095_MonInferno,
    (SkillDoFunc)&SKILLS_SrvDo096_ZakarumHeal_Bestow, (SkillDoFunc)&SKILLS_SrvDo097_Resurrect, (SkillDoFunc)&SKILLS_SrvDo098_MonTeleport, (SkillDoFunc)&SKILLS_SrvDo099_PrimePoisonNova, (SkillDoFunc)&sub_005CCE80, (SkillDoFunc)&SKILLS_SrvDo101_FingerMageSpider, (SkillDoFunc)&SKILLS_SrvDo102_DiabWall, (SkillDoFunc)&SKILLS_SrvDo103_DiabRun, (SkillDoFunc)&SKILLS_SrvDo104_DiabPrison, (SkillDoFunc)&SKILLS_SrvDo105_DesertTurret, (SkillDoFunc)&SKILLS_SrvDo106_ArcaneTower, (SkillDoFunc)&SKILLS_SrvDo107_Mosquito, (SkillDoFunc)&sub_005CDC10, (SkillDoFunc)&SKILLS_SrvDo109_MonFrenzy, (SkillDoFunc)&SKILLS_SrvDo110_Hireable_RogueMissile, (SkillDoFunc)&SKILLS_SrvDo111_FetishAura,
    (SkillDoFunc)&SKILLS_SrvDo112_MonCurseCast, (SkillDoFunc)&SKILLS_SrvDo113_Scroll_Book, (SkillDoFunc)&SKILLS_SrvDo114_Raven, (SkillDoFunc)&SKILLS_SrvDo115_Vines, (SkillDoFunc)&SKILLS_SrvDo116_Wearwolf_Wearbear, (SkillDoFunc)&SKILLS_SrvDo117_Firestorm, (SkillDoFunc)&SKILLS_SrvDo118_Twister_Tornado, (SkillDoFunc)&SKILLS_SrvDo119_DruidSummon, (SkillDoFunc)&SKILLS_SrvDo120_FeralRage_Maul, (SkillDoFunc)&SKILLS_SrvDo121_Rabies, (SkillDoFunc)&SKILLS_SrvDo122_Hunger, (SkillDoFunc)&SKILLS_SrvDo123_Volcano, (SkillDoFunc)&SKILLS_SrvDo124_Armageddon_Hurricane, (SkillDoFunc)&SKILLS_SrvDo125_WakeOfDestruction, (SkillDoFunc)&SKILLS_SrvDo126_ImpInferno, (SkillDoFunc)&SKILLS_SrvDo127_SuckBlood,
    (SkillDoFunc)&SKILLS_SrvDo128_CryHelp, (SkillDoFunc)&SKILLS_SrvDo129_ImpTeleport, (SkillDoFunc)&SKILLS_SrvDo130_VineAttack, (SkillDoFunc)&SKILLS_SrvDo131_OverseerWhip, (SkillDoFunc)&SKILLS_SrvDo132_ImpFireMissile, (SkillDoFunc)&SKILLS_SrvDo133_Impregnate, (SkillDoFunc)&SKILLS_SrvDo134_SiegeBeastStomp, (SkillDoFunc)&SKILLS_SrvDo135_MinionSpawner, (SkillDoFunc)&SKILLS_SrvDo136_DeathMaul, (SkillDoFunc)&SKILLS_SrvDo137_FenrisRage, (SkillDoFunc)&SKILLS_SrvDo138_Unused, (SkillDoFunc)&SKILLS_SrvDo139_BaalColdMissiles, (SkillDoFunc)&SKILLS_SrvDo140_BaalTentacle, (SkillDoFunc)&SKILLS_SrvDo141_BaalCorpseExplode, (SkillDoFunc)&SKILLS_SrvDo142_Unused, (SkillDoFunc)&SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn,
    (SkillDoFunc)&SKILLS_SrvDo144_Hydra, (SkillDoFunc)&SKILLS_SrvDo145_PeriodicAreaDamage, (SkillDoFunc)&SKILLS_SrvDo146_PeriodicRandomMissile, (SkillDoFunc)&SKILLS_SrvDo147_Unused, (SkillDoFunc)&SKILLS_SrvDo148_DoomKnightMissile, (SkillDoFunc)&SKILLS_SrvDo149_NecromageMissile, (SkillDoFunc)&SKILLS_SrvDo150_Smite, (SkillDoFunc)&SKILLS_SrvDo151_Unused, (SkillDoFunc)&SKILLS_SrvDo152_DiabLight
}; // 0x007322B0
#pragma comment(linker, "/alternatename:?gpfnSkillSrvDoFunctions@@3PAP6IHPAUD2GameStrc@@PAUD2UnitStrc@@HH@ZA=_gData_007322B0")
