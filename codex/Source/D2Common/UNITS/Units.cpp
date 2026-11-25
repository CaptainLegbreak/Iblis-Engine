#include "D2ObjectIds.h"
#include "D2Records.h"
#include "D2TxtItems.h"
#include "D2Skills.h"
#include "D2TxtTables.h"
#include "D2Unicode.h"

#include "D2ItemTypes.h"

#include "D2StateIds.h"

#include "D2MonsterIds.h"

#include "D2StatIds.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Path.h"

#include "D2Txt.h"

#include "D2GameObjs.h"

#include "D2UnitData.h"

#include "D2AnimData.h"

#include "D2PlayerModes.h"

#include "D2MonModes.h"

#define FP16_SHIFT 16

#define OBJSUBCLASS_SHRINE 0x01

#define SKILLSFLAGINDEX_USEATTACKRATE 3

#define MONSTATS2FLAGINDEX_SOFT 0xC

struct D2SkillListStrc;

struct D2WaypointDataStrc;

struct D2PlayerDataStrc;

struct D2MonsterDataStrc;

struct D2InventoryStrc;

struct D2CoordStrc;

struct D2StaticPathStrc;

struct D2ObjectsTxt;

struct D2ObjectDataStrc;

struct D2ItemsTxt;

struct D2SkillsTxt;

struct D2AnimUnkStrc;

struct D2ValueRecordStrc;

struct D2MonStats2Txt;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char gszUnitsSourceFile; // 0x006E8E10

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910

void __stdcall STATLIST_FreeStatListEx(D2UnitStrc* pUnit); // 0x00626D10

void __stdcall SKILLS_FreeSkillList(D2UnitStrc* pUnit); // 0x00643A60

int __stdcall PATH_GetPrecisionX(D2DynamicPathStrc* pPath); // 0x00648940

int __stdcall PATH_GetPrecisionY(D2DynamicPathStrc* pPath); // 0x00648970

int __stdcall PATH_GetClientCoordX(D2DynamicPathStrc* pPath); // 0x006489C0

int __stdcall PATH_GetClientCoordY(D2DynamicPathStrc* pPath); // 0x006489D0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __fastcall PATH_SetClientCoordX(D2DynamicPathStrc* pPath, int nX); // 0x006489E0

void __fastcall PATH_SetClientCoordY(D2DynamicPathStrc* pPath, int nY); // 0x006489F0

void __stdcall PATH_SetRoom(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pRoom); // 0x00648A90

void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pPath, int* pUnitType, int* pUnitGUID); // 0x00648BB0

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

D2SkillStrc* __fastcall SKILLS_GetLeftSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643930

D2SkillStrc* __fastcall SKILLS_GetRightSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643960

D2SkillStrc* __fastcall SKILLS_GetUsedSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x006439A0

int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2); // 0x0064FDC0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490

void __stdcall WAYPOINTS_FreeWaypointData(void* pMemPool, D2WaypointDataStrc* pData); // 0x00660FD0

void __fastcall sub_0066A260_PlayerDataFreeHook(D2UnitStrc* pUnit); // 0x0066A260

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __fastcall SKILLS_SetUsedSkillInSkillList(D2SkillListStrc* pSkillList, D2SkillStrc* pUsedSkill); // 0x00643990

extern struct D2DataTablesStrc* sgptDataTables; // 0x00744304

struct D2AnimUnkStrc
{
    int bCanUseVelocityModifierByPassiveSkill;
    int bCanUseVelocityModifier;
    int bCanUseSkillAttackRate;
    int bCanUseAttackRate;
    int bAllowAnimSpeed;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2AnimUnkStrc gaPlayerModesAnimModulators[]; // 0x006E8A00

extern D2AnimUnkStrc gaMonModesAnimModulators[]; // 0x006E8B90

extern D2AnimUnkStrc gaMonModesAnimModulatorsExpansion[]; // 0x006E8CD0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0


extern void __stdcall STATLIST_FreeStatListEx(D2UnitStrc*); // 0x00626D10

extern void __stdcall SKILLS_FreeSkillList(D2UnitStrc*); // 0x00643A60

extern void __fastcall sub_0040B480_FreePool(void*,void*,const char*,int,int);

struct D2ValueRecordStrc
{
    int nValues[5];
};

extern const D2ValueRecordStrc gTable_006E8B90[]; // 0x006E8B90

extern const D2ValueRecordStrc gTable_006E8CD0[]; // 0x006E8CD0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

extern "C" void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, unsigned int dwState); // 0x006252D0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0

int __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc*, D2UnitStrc**, int*, int*); // 0x0063C9B0

unsigned char __stdcall ITEMS_GetMeleeRange(D2UnitStrc*); // 0x006288D0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, D2InventoryStrc*, int*, int, int); // 0x0064F380

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

int __stdcall PATH_GetNewDirection(D2DynamicPathStrc* pDynamicPath); // 0x00648810

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

D2UnitStrc* __stdcall INVENTORY_GetCompositItem(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063C050

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720

D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2); // 0x00623990

unsigned char __stdcall ITEMS_GetHitClassFromItem(D2UnitStrc* pItem); // 0x0062A180

#define SIZE_PLAYER 2

#define SIZE_ITEM 1

#define UNITFLAG_DOUPDATE 0x00000001

#define MONSTATSFLAGINDEX_SWITCHAI 16

struct D2AnimSeqTxt;

struct D2MissilesTxt;

struct D2AnimDataRecordStrc;

struct D2MonStatsTxt;

struct D2CharStatsTxt;

struct D2InventoryRecordMapStrc;

struct D2AnimModeModulatorStrc;

struct D2AnimModeStatBasePercentageStrc;

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0

int __fastcall UNITS_GetCollisionMask(D2UnitStrc* pUnit); // 0x006209D0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

D2UnitStrc* __stdcall INVENTORY_GetSecondaryWeapon(D2InventoryStrc* pInventory); // 0x0063BF90

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0

unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pItem); // 0x00628660

int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0

enum
{
    INVPAGE_EQUIP = 1,
    INVPAGE_TRADE = 2,
    INVPAGE_CUBE = 3,
    INVPAGE_STASH = 4,
};

enum
{
    INVENTORYRECORD_MONSTER = 5,
    INVENTORYRECORD_TRADE_PAGE_1 = 6,
    INVENTORYRECORD_TRADE_PAGE_2 = 7,
    INVENTORYRECORD_BANK_PAGE_1 = 8,
    INVENTORYRECORD_TRANSMOGRIFY_BOX_PAGE_1 = 9,
    INVENTORYRECORD_GUILD_VAULT_PAGE_1 = 10,
    INVENTORYRECORD_TROPHY_CASE_PAGE_1 = 11,
    INVENTORYRECORD_BIG_BANK_PAGE_1 = 12,
};

enum
{
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};

enum
{
    COMPOSIT_RIGHTHAND = 7,
};

struct D2InventoryRecordMapStrc
{
    int nClassId;
    int nRecord;
};

extern D2InventoryRecordMapStrc gaInventoryRecordMap[]; // 0x00744544

extern unsigned int gnInventoryRecordMapCount; // 0x0074457C

extern unsigned int gdwNoBlockItemCodes[]; // 0x00744580

extern unsigned int gnNoBlockItemCodeCount; // 0x00744584

unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent); // 0x00664860

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

int __stdcall UNITS_GetMeleeRange(D2UnitStrc* pUnit); // 0x00622870

int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0

void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt* pMonSeqTxt, int nTargetFramePoint, int nCurrentFramePoint, int* pMode, int* pFrame, int* pDirection, int* pEvent); // 0x00663410

D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit); // 0x006633B0

int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit); // 0x006633D0

int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit); // 0x006633F0

int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit); // 0x00623B10

struct D2AnimModeModulatorStrc
{
    int bCanUseVelocityModifierByPassiveSkill;
    int bCanUseVelocityModifier;
    int bCanUseSkillAttackRate;
    int bCanUseAttackRate;
    int bAllowAnimSpeed;
};

struct D2AnimModeStatBasePercentageStrc
{
    int bHasBasePercentage;
    int nBasePercentage;
    int nStatId;
};

extern D2AnimModeModulatorStrc gaPlayerModesAnimModulators_006E8A00[]; // 0x006E8A00

extern D2AnimModeModulatorStrc gaMonModesAnimModulators_006E8B90[]; // 0x006E8B90

extern D2AnimModeModulatorStrc gaMonModesAnimModulatorsExpansion_006E8CD0[]; // 0x006E8CD0

extern D2AnimModeStatBasePercentageStrc gaAnimModeStatBasePercentage[]; // 0x006E8E24

int __fastcall UNITS_CanAnimModeUseAttackRate(int nAnimMode, int nUnitType, D2UnitStrc* pUnit, int nClassId); // 0x00621580

void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int bSet); // 0x00623C80

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

unsigned int __stdcall D2Common_11043(D2UnitStrc* pUnit); // 0x00646170

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760

void __stdcall D2Common_10534(D2UnitStrc* pUnit); // 0x00625A00

int __stdcall D2Common_10531_SetStatInStatListLayer0(D2StatListStrc* pStatList, int nStatId, int nValue, int nUnused); // 0x00627810

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem); // 0x00629FE0

void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit); // 0x006272E0

int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390

static int __stdcall UNITS_CanAnimModeUseVelocityModifier(int nUnitType, int nAnimMode, D2UnitStrc* pUnit, int nClassId);

static void __stdcall UNITS_StoreOwnerInfo(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId);

void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId);

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);

#define COLLIDE_WALL 0x1

#define COLLIDE_MISSILE_BARRIER 0x4

#define COLLIDE_ITEM 0x200

#define COLLIDE_OBJECT 0x400

#define COLLIDE_MASK_DOOR_BLOCK_VIS 0x806

#define OBJSUBCLASS_TOWNPORTAL 0x4

#define DEX_BASE 7

#define DEX_MUL 5

int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pPath); // 0x00648C10

unsigned int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#pragma function(memset)

struct D2BitBufferStrc;

struct D2RosterInfoStrc;

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

D2RosterInfoStrc* __fastcall GFXUTIL_GetNextRosterInfo(D2RosterInfoStrc* pRosterInfo); // 0x004DC0B0

int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nLevelId);                                               // 0x0061AE30

D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool);                                         // 0x0065C430

D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool);                                  // 0x00660F30

void __stdcall sub_0066A250(int nUnused);

struct D2SkillStrc;

struct D2TimerArgStrc;

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __stdcall UNITS_IsInMovingMode(D2UnitStrc* pUnit);                                                      // 0x00622D00

#pragma intrinsic(memset)

#define STRCOPY_MAX 0x7FFFFFFF

int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A770

#define MONSTATS2FLAGINDEX_CORPSESEL 7

#define MONSTATS2FLAGINDEX_DEADCOL 19

static int __stdcall UNITS_AnimModeAllowsAnimSpeed(int nUnitType, int nAnimMode, int nClassId);

static int UNITS_GetAnimStatBasePercentage(D2UnitStrc* pUnit, int nStat);

static int UNITS_IsSeqAnimSpeedModulatedByFCR(int nUnitType, int nAnimMode, D2UnitStrc* pUnit);

static inline unsigned int DATATBLS_CheckMonStatsFlag_Inl(D2MonStatsTxt* pMonStatsTxtRecord);

#define UNITFLAGEX_HASINV 0x1

#define UNITFLAGEX_UPDATEINV 0x2

#define UNITFLAGEX_STORELASTATTACKER 0x20000

#define MONSTATS2_SOFT 12

struct D2GfxLightStrc;

struct D2ShrinesTxt;

D2AnimDataRecordStrc* __fastcall DATATBLS_GetAnimDataRecord(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory); // 0x0066A9B0

int __stdcall PATH_IsCurrentRoomInvalid(D2DynamicPathStrc* pPath); // 0x00648B30

void __stdcall PATH_SetCurrentRoomInvalid(D2DynamicPathStrc* pPath, int a2); // 0x00648B40

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0

enum
{
    UNIT_TYPES = 6,
    MONSTATSFLAGINDEX_NOSHLDBLOCK = 26,
};

int __fastcall UNITS_CanMonsterBlock(D2UnitStrc* pUnit); // 0x006225F0

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

union D2SeedStrc;

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit); // 0x00649400

int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560

int __stdcall COLLISION_RayTrace(D2ActiveRoomStrc* pRoom, D2CoordStrc* pBegin, D2CoordStrc* pEnd, int nCollisionMask); // 0x0064E260

void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit); // 0x00621260

void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x00623F50

int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit); // 0x0063A400

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

static void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId);

static int UNITS_GetBaseAnimSpeed(int nUnitType, int nClassId, int nAnimMode);

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

static __declspec(noinline) int __stdcall sub_00622920_TestCollision(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask);

extern int gaClassesWeaponFrameBonus[][7]; // 0x006E8E60

void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit);

int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);

int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask);

int __stdcall UNITS_TestCollisionBetweenInteractingUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask);

static int __stdcall UNITS_UpdateSequenceFrame(D2UnitStrc* pUnit, int nPrevFrame);

void __stdcall UNITS_SetAnimActionFrame(D2UnitStrc* pUnit, int nFrame);

// 0x00620100
unsigned char __stdcall UNITS_GetDirection(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 955);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        return pUnit->pStaticPath->nDirection;

    default:
        return PATH_GetDirection(pUnit->pDynamicPath);
    }
}

// 0x00620150
D2SkillStrc* __stdcall UNITS_GetStartSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1592);
    return SKILLS_GetFirstSkillFromSkillList(hUnit->pSkills);
}

inline D2AnimSeqTxt* UNITS_GetAnimSeq(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pAnimSeq;
    }

    return 0;
}

inline int UNITS_GetPositionX(D2UnitStrc* pUnit)
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

inline int UNITS_GetPositionY(D2UnitStrc* pUnit)
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

// 0x00620190
D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1601);
    return SKILLS_GetLeftSkillFromSkillList(hUnit->pSkills);
}

// 0x006201D0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1610);
    return SKILLS_GetRightSkillFromSkillList(hUnit->pSkills);
}

// 0x00620210
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* hUnit, D2SkillStrc* pUsedSkill)
{
    D2_ASSERT(hUnit, 1619);
    SKILLS_SetUsedSkillInSkillList(hUnit->pSkills, pUsedSkill);
}

// 0x00620250
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 1628);
    return SKILLS_GetUsedSkillFromSkillList(hUnit->pSkills);
}

// 0x00620290
D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType)
{
    D2UnitStrc* pUnit = (D2UnitStrc*)sub_0040B430(pMemPool, 0xF4, ".\\UNITS\\Units.cpp", 1646, 0);
    memset(pUnit, 0, 0xF4);

    pUnit->dwUnitType = nUnitType;
    pUnit->pMemoryPool = pMemPool;

    switch (nUnitType)
    {
    case UNIT_MONSTER:
        pUnit->pMonsterData = (D2MonsterDataStrc*)sub_0040B430(pMemPool, 0x60, ".\\UNITS\\Units.cpp", 1659, 0);
        memset(pUnit->pMonsterData, 0, 0x60);
        break;
    }

    return pUnit;
}

// 0x00620300
void __stdcall UNITS_FreeUnit(D2UnitStrc* unit)
{
    if (unit) {
        STATLIST_FreeStatListEx(unit);
        SKILLS_FreeSkillList(unit);
        unsigned typeDelta=(unsigned)unit->dwUnitType-1u;
        if (!typeDelta) {
            sub_0040B480_FreePool((unit == 0 ? 0 : unit->pMemoryPool),unit->pMonsterData,".\\UNITS\\Units.cpp",0x69a,(int)typeDelta);
        }
        unit->dwUnitType=6;
        unit->dwUnitId=-1;
        sub_0040B480_FreePool((unit == 0 ? 0 : unit->pMemoryPool),unit,".\\UNITS\\Units.cpp",0x6a4,0);
    }
}

// 0x00620360
void __fastcall UNITS_SetTileUnitCoords(D2UnitStrc* pUnit, int nX, int nY, int nUnk0x14, int nUnk0x18)
{
    D2_ASSERT(pUnit, 1711);
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 1713);

    D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
    pStaticPath->tGameCoords.nX = nX;
    pStaticPath->tGameCoords.nY = nY;
    *(int*)&pStaticPath->unk0x14[0] = nUnk0x14;
    *(int*)&pStaticPath->unk0x14[4] = nUnk0x18;
}

// 0x006203B0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1732);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->tGameCoords.nX << FP16_SHIFT;

    default:
        return PATH_GetPrecisionX(ptUnit->pDynamicPath);
    }
}

// 0x00620410
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1754);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->tGameCoords.nY << FP16_SHIFT;

    default:
        return PATH_GetPrecisionY(ptUnit->pDynamicPath);
    }
}

// 0x00620470
void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* ptUnit, int nX)
{
    D2_ASSERT(ptUnit, 1775);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        ptUnit->pStaticPath->tGameCoords.nX = nX;
        break;

    default:
        D2_ASSERT(0, 1786);
    }
}

// 0x006204C0
void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* ptUnit, int nY)
{
    D2_ASSERT(ptUnit, 1798);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        ptUnit->pStaticPath->tGameCoords.nY = nY;
        break;

    default:
        D2_ASSERT(0, 1809);
    }
}

// 0x00620510
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            return SIZE_PLAYER;

        case UNIT_MONSTER:
            if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId))
            {
                return pMonStats2TxtRecord->nSizeX;
            }
            return 0;

        case UNIT_OBJECT:
            return pUnit->pObjectData->pObjectTxt->dwSizeX;

        case UNIT_ITEM:
            return SIZE_ITEM;

        case UNIT_MISSILE:
            if (D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pUnit->dwClassId))
            {
                return pMissilesTxtRecord->nSize;
            }
            return 0;

        case UNIT_TILE:
            return 0;

        default:
            return 0;
        }
    }

    return 0;
}

// 0x006205A0
int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1867);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return SIZE_PLAYER;

    case UNIT_MONSTER:
        if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(ptUnit->dwClassId))
        {
            return pMonStats2TxtRecord->nSizeY;
        }
        return 0;

    case UNIT_OBJECT:
        return ptUnit->pObjectData->pObjectTxt->dwSizeY;

    case UNIT_ITEM:
        return SIZE_ITEM;

    case UNIT_MISSILE:
        if (D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(ptUnit->dwClassId))
        {
            return pMissilesTxtRecord->nSize;
        }
        return 0;

    case UNIT_TILE:
        return 0;

    default:
        return 0;
    }
}

// 0x00620650
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1909);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->nTargetX;

    default:
        return PATH_GetClientCoordX(ptUnit->pDynamicPath);
    }
}

// 0x006206B0
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1930);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->nTargetY;

    default:
        return PATH_GetClientCoordY(ptUnit->pDynamicPath);
    }
}

// 0x00620710
int __stdcall UNITS_GetAbsoluteXDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nX1;
    int nX2;

    switch (pUnit1->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX1 = pUnit1->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit1->pDynamicPath)
        {
            nX1 = PATH_GetXPosition(pUnit1->pDynamicPath);
        }
        else
        {
            nX1 = 0;
        }
        break;
    }

    switch (pUnit2->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX2 = pUnit2->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit2->pDynamicPath)
        {
            nX2 = PATH_GetXPosition(pUnit2->pDynamicPath);
        }
        else
        {
            nX2 = 0;
        }
        break;
    }

    int nDistance = nX1 - nX2;
    if (nDistance < 0)
    {
        nDistance = -nDistance;
    }

    return nDistance;
}

// 0x00620780
int __stdcall UNITS_GetAbsoluteYDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    int nY1;
    int nY2;

    switch (pUnit1->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY1 = pUnit1->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit1->pDynamicPath)
        {
            nY1 = PATH_GetYPosition(pUnit1->pDynamicPath);
        }
        else
        {
            nY1 = 0;
        }
        break;
    }

    switch (pUnit2->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY2 = pUnit2->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit2->pDynamicPath)
        {
            nY2 = PATH_GetYPosition(pUnit2->pDynamicPath);
        }
        else
        {
            nY2 = 0;
        }
        break;
    }

    int nDistance = nY1 - nY2;
    if (nDistance < 0)
    {
        nDistance = -nDistance;
    }

    return nDistance;
}

// 0x006207F0
void __stdcall UNITS_SetTargetX(D2UnitStrc* ptUnit, int nTargetX)
{
    D2_ASSERT(ptUnit, 1970);

    PATH_SetClientCoordX(ptUnit->pDynamicPath, nTargetX);
}

// 0x00620830
void __stdcall UNITS_SetTargetY(D2UnitStrc* ptUnit, int nTargetY)
{
    D2_ASSERT(ptUnit, 1982);

    PATH_SetClientCoordY(ptUnit->pDynamicPath, nTargetY);
}

// 0x00620870
void __stdcall UNITS_GetCoords(D2UnitStrc* ptUnit, D2CoordStrc* pCoord)
{
    D2_ASSERT(ptUnit, 1994);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        {
            D2StaticPathStrc* pStaticPath = ptUnit->pStaticPath;
            pCoord->nX = pStaticPath->tGameCoords.nX;
            pCoord->nY = pStaticPath->tGameCoords.nY;
        }
        break;

    default:
        if (ptUnit->pDynamicPath)
        {
            pCoord->nX = PATH_GetXPosition(ptUnit->pDynamicPath);
            pCoord->nY = PATH_GetYPosition(ptUnit->pDynamicPath);
        }
        else
        {
            pCoord->nX = 0;
            pCoord->nY = 0;
        }
        break;
    }
}

// 0x00620900
void __stdcall UNITS_GetClientCoords(D2UnitStrc* ptUnit, D2CoordStrc* pClientCoords)
{
    D2_ASSERT(ptUnit, 2023);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        {
            D2StaticPathStrc* pStaticPath = ptUnit->pStaticPath;
            pClientCoords->nX = pStaticPath->nTargetX;
            pClientCoords->nY = pStaticPath->nTargetY;
        }
        break;

    default:
        pClientCoords->nX = PATH_GetClientCoordX(ptUnit->pDynamicPath);
        pClientCoords->nY = PATH_GetClientCoordY(ptUnit->pDynamicPath);
        break;
    }
}

// 0x00620980
void __fastcall UNITS_SetTileUnitTargetCoords(D2UnitStrc* pUnit, int nClientX, int nClientY)
{
    D2_ASSERT(pUnit, 2047);
    D2_ASSERT(pUnit->dwUnitType == UNIT_TILE, 2049);

    D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
    pStaticPath->nTargetX = nClientX;
    pStaticPath->nTargetY = nClientY;
}

// 0x006209D0
int __fastcall UNITS_GetCollisionMask(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 2062);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
        if (ptUnit->pObjectData->pObjectTxt->nIsDoor)
        {
            if (ptUnit->pObjectData->pObjectTxt->nBlocksVis)
            {
                return COLLIDE_MASK_DOOR_BLOCK_VIS;
            }
            else if (ptUnit->pObjectData->pObjectTxt->nBlockMissile)
            {
                return COLLIDE_DOOR | COLLIDE_MISSILE_BARRIER;
            }
            else
            {
                return COLLIDE_OBJECT;
            }
        }
        else
        {
            if (ptUnit->pObjectData->pObjectTxt->nSubClass & OBJSUBCLASS_TOWNPORTAL)
            {
                return COLLIDE_CORPSE;
            }
            else if (ptUnit->pObjectData->pObjectTxt->nBlockMissile)
            {
                return COLLIDE_OBJECT | COLLIDE_MISSILE_BARRIER;
            }
            else
            {
                return COLLIDE_OBJECT;
            }
        }

    case UNIT_ITEM:
        return COLLIDE_ITEM;

    case UNIT_TILE:
        return COLLIDE_WALL;

    default:
        return PATH_GetFootprintCollisionMask(ptUnit->pDynamicPath);
    }
}

// 0x00620A70
void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* hUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(hUnit, 2129);
    const int nSizeX = UNITS_GetUnitSizeX(hUnit);
    const int nSizeY = UNITS_GetUnitSizeY(hUnit);
    if (nSizeX && nSizeY)
    {
        COLLISION_SetMaskWithSizeXY(pRoom, nX, nY, nSizeX, nSizeY, UNITS_GetCollisionMask(hUnit));
    }
}

// 0x00620AE0
void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* ptUnit, D2ActiveRoomStrc* pRoom, D2CoordStrc tCoord)
{
    D2_ASSERT(ptUnit, 0x866);
    D2StaticPathStrc* pPath = ptUnit->pStaticPath;
    pPath->nXPos = tCoord.nX;
    pPath->nYPos = tCoord.nY;
    pPath->nDirection = 0;
    pPath->pRoom = pRoom;
    int nConvX = tCoord.nX;
    int nConvY = tCoord.nY;
    DUNGEON_GameSubtileToClientCoords(&nConvX, &nConvY);
    pPath->nTargetX = nConvX;
    pPath->nTargetY = nConvY;
}

// 0x00620B50
void __stdcall UNITS_ResetRoom(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 2173);

    switch (hUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        hUnit->pStaticPath->pRoom = 0;
        break;

    default:
        if (hUnit->pDynamicPath)
        {
            PATH_SetRoom(hUnit->pDynamicPath, 0);
        }
        break;
    }
}

D2ActiveRoomStrc* __stdcall PATH_GetRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648A80
inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00620BB0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 2198);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ptUnit->pStaticPath->pRoom;
    default:
        if (ptUnit->pDynamicPath)
        {
            return PATH_GetRoom(ptUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00620C10
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* ptUnit, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(ptUnit, 2220);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER) || (ptUnit->dwUnitType == UNIT_MISSILE), 2222);
    PATH_SetTargetUnit(ptUnit->pDynamicPath, pTargetUnit);
}

// 0x00620C70
int __stdcall UNITS_GetTargetTypeFromDynamicUnit(D2UnitStrc* ptUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2_ASSERT(ptUnit, 2233);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER) || (ptUnit->dwUnitType == UNIT_MISSILE), 2235);

    PATH_GetTargetTypeAndGUID(ptUnit->pDynamicPath, &nUnitType, &nUnitGUID);
    return nUnitType;
}

// 0x00620CD0
int __stdcall UNITS_GetTargetGUIDFromDynamicUnit(D2UnitStrc* ptUnit)
{
    int nUnitType;
    int nUnitGUID;
    D2_ASSERT(ptUnit, 2250);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER) || (ptUnit->dwUnitType == UNIT_MISSILE), 2252);

    PATH_GetTargetTypeAndGUID(ptUnit->pDynamicPath, &nUnitType, &nUnitGUID);
    return nUnitGUID;
}

// 0x00620D30
void __stdcall UNITS_SetTargetUnitForPlayerOrMonster(D2UnitStrc* ptUnit, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(ptUnit, 2268);
    D2_ASSERT((ptUnit->dwUnitType == UNIT_PLAYER) || (ptUnit->dwUnitType == UNIT_MONSTER), 2270);

    PATH_SetTargetUnit(ptUnit->pDynamicPath, pTargetUnit);
}

// 0x00620D80
void __stdcall UNITS_SetMonsterAnimSpeed(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    switch (pUnit->dwUnitType)
    {
    case UNIT_MONSTER:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = 0;
        if (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
        }
        if (!pMonStatsTxtRecord)
        {
            pUnit->wAnimSpeed = 0;
            return;
        }
        if (!pUnit->pStatListEx)
        {
            pUnit->wAnimSpeed = pMonStatsTxtRecord->nWalkAnimSpeed;
            return;
        }
        const int nVelocityPercent = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
        const short nBaseAnimSpeed = (pUnit->dwAnimMode == 15) ? pMonStatsTxtRecord->nRunAnimSpeed : pMonStatsTxtRecord->nWalkAnimSpeed;
        int nAnimSpeed = nBaseAnimSpeed * nVelocityPercent / 100;
        nAnimSpeed = nAnimSpeed > 0 ? nAnimSpeed : 0;
        if (nAnimSpeed >= 0x7FFF)
        {
            nAnimSpeed = 0x7FFF;
        }
        pUnit->wAnimSpeed = nAnimSpeed;
        break;
    }
    }
}

// 0x00620E40
void __stdcall UNITS_GetRunAndWalkSpeedForPlayer(int nUnused, int nCharId, int* pWalkSpeed, int* pRunSpeed)
{
    D2CharStatsTxt* pCharStatsTxtRecord = (nCharId >= 0 && nCharId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nCharId] : 0;
    *pWalkSpeed = pCharStatsTxtRecord->nWalkSpeed;
    *pRunSpeed = pCharStatsTxtRecord->nRunSpeed;
}

// 0x00620E80
static void UNITS_CharacterStartRunningOrKnockback(D2UnitStrc* pUnit, int nClassId)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    D2CharStatsTxt* pCharStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClassId] : 0;
    const int nWalkSpeed = pCharStatsTxtRecord->nWalkSpeed;
    if (nWalkSpeed)
    {
        STATLIST_SetStatValue(pStatList, 0x43, 100 * pCharStatsTxtRecord->nRunSpeed / nWalkSpeed - 100, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

// 0x00620F00
void __stdcall UNITS_SetAnimData(D2UnitStrc* ptUnit, int nUnitType, int nClassId, int nMode)
{
    D2_ASSERT(ptUnit, 2358);
    ptUnit->pAnimData = DATATBLS_GetAnimDataRecord(ptUnit, nClassId, nMode, nUnitType, ptUnit->pInventory);
}

// 0x00620F50
int __stdcall UNITS_IsCurrentRoomInvalid(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 2540);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        return ptUnit->pStaticPath->bRoomNeedsUpdate;

    default:
        return PATH_IsCurrentRoomInvalid(ptUnit->pDynamicPath);
    }
}

// 0x00620FA0
void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* ptUnit, int a2)
{
    D2_ASSERT(ptUnit, 2558);

    switch (ptUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        ptUnit->pStaticPath->bRoomNeedsUpdate = a2 != 0;
        return;

    default:
        PATH_SetCurrentRoomInvalid(ptUnit->pDynamicPath, a2);
        return;
    }
}

// 0x00621000
void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag)
{
    if (bSetFlag)
    {
        UNITROOM_RefreshUnit(pUnit);
    }

    if (pUnit)
    {
        if (bSetFlag)
        {
            pUnit->dwFlagEx |= UNITFLAGEX_HASINV;
        }
        else
        {
            pUnit->dwFlagEx &= ~UNITFLAGEX_HASINV;
            return;
        }
    }

    if (bSetFlag && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pUnit->dwFlagEx |= UNITFLAGEX_UPDATEINV;
    }
}


// 0x00621050
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD)
{
    D2_ASSERT(hUnit, 2607);

    int nRet = -1;
    switch (hUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        switch ((unsigned char)nInvPage)
        {
        case INVPAGE_EQUIP:
            return INVENTORYRECORD_TRADE_PAGE_1;

        case INVPAGE_TRADE:
            return INVENTORYRECORD_TRADE_PAGE_2;

        case INVPAGE_STASH:
            return bLoD != 0 ? INVENTORYRECORD_BIG_BANK_PAGE_1 : INVENTORYRECORD_BANK_PAGE_1;

        case INVPAGE_CUBE:
            return INVENTORYRECORD_TRANSMOGRIFY_BOX_PAGE_1;

        default:
        {
            const int nClassId = hUnit->dwClassId;
            for (unsigned int i = 0; i < gnInventoryRecordMapCount; ++i)
            {
                if (nClassId == gaInventoryRecordMap[i].nClassId)
                {
                    nRet = gaInventoryRecordMap[i].nRecord;
                    break;
                }
            }
            break;
        }
        }
        break;

    case UNIT_MONSTER:
        return INVENTORYRECORD_MONSTER;

    case UNIT_OBJECT:
        switch (hUnit->dwClassId)
        {
        case OBJECT_GUILD_VAULT:
            return INVENTORYRECORD_GUILD_VAULT_PAGE_1;

        case OBJECT_TROPHY_CASE:
            return INVENTORYRECORD_TROPHY_CASE_PAGE_1;

        default:
            return -1;
        }
    }

    return nRet;
}

// 0x00621150
D2GfxLightStrc* __stdcall UNITS_ResetLightMap(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 2669);

    D2GfxLightStrc* pLight = ptUnit->pLight;
    ptUnit->pLight = 0;

    return pLight;
}

// 0x00621190
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (UNITS_GetAnimSeq(pUnit))
    {
        return pUnit->dwSeqMode;
    }

    return pUnit->dwAnimMode;
}

// 0x006211C0
void __stdcall UNITS_SetAnimOrSeqMode(D2UnitStrc* ptUnit, int nAnimMode)
{
    D2_ASSERT(ptUnit, 2706);

    if (UNITS_GetAnimSeq(ptUnit))
    {
        ptUnit->dwSeqMode = nAnimMode;
    }
    else
    {
        ptUnit->dwAnimMode = nAnimMode;
    }
}

struct D2StatListStrc;

struct D2UnitStrc;

// 0x00621210
static int __stdcall UNITS_UpdateSequenceFrame(D2UnitStrc* pUnit, int nPrevFrame)
{
    const int nOldMode = pUnit->dwSeqMode;
    int nFrame;
    int nDirection;
    int nEvent;
    DATATBLS_ComputeSequenceAnimation(pUnit->pAnimSeq, pUnit->dwSeqFrame, nPrevFrame, &nPrevFrame, &nFrame, &nDirection, &nEvent);
    pUnit->nSeqCurrentFramePrecise = nFrame << 8;
    pUnit->dwSeqMode = nPrevFrame;
    pUnit->nActionFrame = nEvent;
    return nPrevFrame != nOldMode;
}

// 0x00621260
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->pAnimSeq = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
        if (pUnit->pAnimSeq)
        {
            pUnit->dwSeqFrameCount = DATATBLS_GetSeqFramePointsCount(pUnit);
            pUnit->dwSeqFrame = 0;
            pUnit->dwSeqSpeed = 0x100;
            pUnit->dwFrameCountPrecise = DATATBLS_GetSeqFrameCount(pUnit) << 8;
            UNITS_UpdateSequenceFrame(pUnit, 0);
            pUnit->dwFlags |= 0x4000;
        }
    }
}

// 0x006212C0
void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* ptUnit, int nFrame)
{
    D2_ASSERT(ptUnit, 2766);

    ptUnit->dwSeqFrame = (nFrame << 8) + (ptUnit->dwSeqFrame & 0xFF);
}

// 0x00621310
void __stdcall UNITS_UpdateFrame(D2UnitStrc* pUnit)
{
    pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

    if (pUnit->nSeqCurrentFramePrecise >= pUnit->dwFrameCountPrecise)
    {
        pUnit->nSeqCurrentFramePrecise -= pUnit->dwFrameCountPrecise;
    }
}

// 0x00621330
void __stdcall D2COMMON_10375_UNITS_SetFrameNonRate(D2UnitStrc* pUnit, int nRate, int nFailRate)
{
    nFailRate <<= 8;
    pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

    if (pUnit->nSeqCurrentFramePrecise >= nFailRate)
    {
        pUnit->nSeqCurrentFramePrecise -= nFailRate - (nRate << 8);
    }
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nCharId)
{
    if (nCharId >= 0 && nCharId < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nCharId];
    }

    return 0;
}

static inline int UNITS_IsAnimModeBlocking_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 9;
        break;
    case 1:
        nMode = 6;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static inline int UNITS_IsAnimModeGetHit_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 4;
        break;
    case 1:
        nMode = 3;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static inline int UNITS_IsAnimModeKnockBack_Inl(int nUnitType, int nAnimMode)
{
    int nMode;
    switch (nUnitType)
    {
    case 0:
        nMode = 0x13;
        break;
    case 1:
        nMode = 0xD;
        break;
    default:
        return 0;
    }

    return nAnimMode == nMode;
}

static __forceinline void UNITS_SetAnimationSpeed_Inl(D2UnitStrc* pUnit, int nSpeed)
{
    int nAnimSpeed = nSpeed > 0 ? nSpeed : 0;
    if (nAnimSpeed >= 0x7FFF)
    {
        nAnimSpeed = 0x7FFF;
    }

    pUnit->wAnimSpeed = (short)nAnimSpeed;
}

// 0x00621360
static int __stdcall UNITS_GetBaseVelocity(int nUnitType, int nClassId)
{
    switch (nUnitType)
    {
    case 0:
        return DATATBLS_GetCharStatsTxtRecord_Inl(nClassId)->nWalkSpeed << 8;
    case 1:
        return DATATBLS_GetMonStatsTxtRecord_Inl(nClassId)->nVelocity << 8;
    }

    return 0;
}

// 0x006213D0
static int UNITS_GetBaseAnimSpeed(int nUnitType, int nClassId, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        return nAnimMode == 3 ? 0x65 : 0xD5;
    case 1:
    {
        const D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nClassId);
        if (nAnimMode != 0xF)
        {
            return pMonStatsTxtRecord->nWalkAnimSpeed;
        }

        return pMonStatsTxtRecord->nRunAnimSpeed;
    }
    }

    return 0;
}

// 0x00621420
static const D2ValueRecordStrc* __stdcall UNITS_GetMonModeAnimModulator(int nIndex, int nValue)
{
    if (nValue < 0x19A)
        return &gTable_006E8B90[nIndex];
    return &gTable_006E8CD0[nIndex];
}

// calling-convention shim (not game code)
int __stdcall sub_K14_EmitGetRecordForValue(int nIndex, int nValue)
{
    return UNITS_GetMonModeAnimModulator(nIndex, nValue)->nValues[0] + UNITS_GetMonModeAnimModulator(nIndex + 1, nValue)->nValues[1];
}

// 0x00621450
static inline int UNITS_IsAnimModeKnockBack(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0x13)
            return 1;
        break;
    case 1:
        if (nAnimMode == 0x0D)
            return 1;
        break;
    }
    return 0;
}

// 0x00621480
static inline int UNITS_IsWalkOrRunMode(int nAnimMode)
{
    switch (nAnimMode)
    {
    case 2:
    case 0x0F:
        return 1;
    }
    return 0;
}

static inline int UNITS_IsWalkOrRunMode_Inl(int nAnimMode)
{
    switch (nAnimMode)
    {
    case 2:
    case 0xF:
        return 1;
    }

    return 0;
}

// 0x006214A0
static int __stdcall UNITS_CanAnimModeUseVelocityModifier(int nUnitType, int nAnimMode, D2UnitStrc* pUnit, int nClassId)
{
    D2AnimModeModulatorStrc* pAnimModeModulators;
    switch (nUnitType)
    {
    case 0:
        pAnimModeModulators = &gaPlayerModesAnimModulators_006E8A00[nAnimMode];
        break;
    case 1:
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nClassId))
        {
            if (DATATBLS_CheckMonStatsFlag_Inl(pMonStatsTxtRecord))
            {
                return UNITS_IsWalkOrRunMode_Inl(nAnimMode);
            }
        }

        if (nClassId < 0x19A)
        {
            pAnimModeModulators = &gaMonModesAnimModulators_006E8B90[nAnimMode];
        }
        else
        {
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion_006E8CD0[nAnimMode];
        }
        break;
    default:
        D2_ASSERT(nUnitType == 0 || nUnitType == 1, 0xBD2);
        return 0;
    }

    if (pAnimModeModulators->bCanUseVelocityModifier)
    {
        return 1;
    }

    if (pAnimModeModulators->bCanUseVelocityModifierByPassiveSkill)
    {
        if (D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit))
        {
            const int nFlags = SKILLS_GetFlags(pUsedSkill);
            if (!(nFlags & 1) || (nFlags & 0x1000))
            {
                return 0;
            }

            return 1;
        }
    }

    return 0;
}

// 0x00621580
int __fastcall UNITS_CanAnimModeUseAttackRate(int nAnimMode, int nUnitType, D2UnitStrc* pUnit, int nClassId)
{
    D2AnimUnkStrc* pAnimModeModulators = 0;
    switch (nUnitType)
    {
    case UNIT_PLAYER:
        pAnimModeModulators = &gaPlayerModesAnimModulators[nAnimMode];
        break;

    case UNIT_MONSTER:
        if (nClassId < MONSTER_FIRST_EXPANSION)
            pAnimModeModulators = &gaMonModesAnimModulators[nAnimMode];
        else
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion[nAnimMode];
        break;

    default:
        D2_ASSERT((nUnitType == UNIT_PLAYER) || (nUnitType == UNIT_MONSTER), 3055);
        return FALSE;
    }

    if (pAnimModeModulators->bCanUseAttackRate)
        return TRUE;

    if (!pAnimModeModulators->bCanUseSkillAttackRate)
        return FALSE;

    D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
    if (!pUsedSkill)
        return FALSE;

    return sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\UNITS\\Units.cpp", 3066))->nFlags[2] & gdwBitMasks[SKILLSFLAGINDEX_USEATTACKRATE];
}

static inline unsigned int DATATBLS_CheckMonStatsFlag_Inl(D2MonStatsTxt* pMonStatsTxtRecord)
{
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0];
    }

    return 0;
}

// 0x00621630
static int __stdcall UNITS_AnimModeAllowsAnimSpeed(int nUnitType, int nAnimMode, int nClassId)
{
    switch (nUnitType)
    {
    case 0:
        return gaPlayerModesAnimModulators_006E8A00[nAnimMode].bAllowAnimSpeed;
    case 1:
    {
        D2AnimModeModulatorStrc* pAnimModeModulators;
        if (nClassId < 0x19A)
        {
            pAnimModeModulators = &gaMonModesAnimModulators_006E8B90[nAnimMode];
        }
        else
        {
            pAnimModeModulators = &gaMonModesAnimModulatorsExpansion_006E8CD0[nAnimMode];
        }

        return pAnimModeModulators->bAllowAnimSpeed;
    }
    }

    return 0;
}

// 0x00621680
static inline int UNITS_IsAnimModeGetHit(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 4)
            return 1;
        break;
    case 1:
        if (nAnimMode == 3)
            return 1;
        break;
    }
    return 0;
}

int __stdcall sub_M110_Emit_00621450(int nUnitType, int nAnimMode)
{
    if (UNITS_IsAnimModeKnockBack(nUnitType, nAnimMode))
        return 7;
    if (UNITS_IsAnimModeGetHit(nUnitType, nAnimMode))
        return 9;
    return UNITS_IsWalkOrRunMode(nAnimMode);
}

// 0x006216B0
static inline int UNITS_IsAnimModeBlock(int nMode, int nValue)
{
    switch (nMode)
    {
    case 0:
        if (nValue == 9)
        {
            return 1;
        }
        break;
    case 1:
        if (nValue == 6)
        {
            return 1;
        }
        break;
    }
    return 0;
}

// 0x006216E0
static int UNITS_IsSeqAnimSpeedModulatedByFCR(int nUnitType, int nAnimMode, D2UnitStrc* pUnit)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0xA)
        {
            return 1;
        }

        if (nAnimMode == 0x12 && pUnit)
        {
            if (D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit))
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\UNITS\\Units.cpp", 0xC48));
                if (pSkillsTxtRecord && pSkillsTxtRecord->nSeqTrans == 0xA)
                {
                    return 1;
                }
            }
        }

        break;
    case 1:
        if (nAnimMode == 7)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00621740
static int UNITS_GetAnimStatBasePercentage(D2UnitStrc* pUnit, int nStat)
{
    const int nValue = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, gaAnimModeStatBasePercentage[nStat].nStatId, 0);
    switch (gaAnimModeStatBasePercentage[nStat].bHasBasePercentage)
    {
    case 1:
        if (nValue)
        {
            return nValue * gaAnimModeStatBasePercentage[nStat].nBasePercentage / (nValue + gaAnimModeStatBasePercentage[nStat].nBasePercentage);
        }
        break;
    }

    return nValue;
}

// 0x00621780
void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed)
{
    nSpeed = nSpeed > 0 ? nSpeed : 0;
    pUnit->wAnimSpeed = nSpeed < 0x7FFF ? nSpeed : 0x7FFF;
}

// 0x006217C0
int __stdcall UNITS_IsAtEndOfFrameCycle(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3457);

    if (ptUnit->pAnimSeq)
    {
        return ptUnit->dwFrameCountPrecise <= 0;
    }
    else
    {
        return ptUnit->nSeqCurrentFramePrecise + ptUnit->wAnimSpeed >= ptUnit->dwFrameCountPrecise;
    }
}

// 0x00621810
void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* ptUnit, int* pFrameNo, int* pFrameCount)
{
    D2_ASSERT(ptUnit, 3471);

    if (ptUnit->dwUnitType == UNIT_OBJECT)
    {
        *pFrameNo = ptUnit->nSeqCurrentFramePrecise >> 8;
        *pFrameCount = ptUnit->pObjectData->pObjectTxt->dwFrameCnt[ptUnit->dwAnimMode];
    }
    else
    {
        *pFrameNo = ptUnit->nSeqCurrentFramePrecise >> 8;
        *pFrameCount = ptUnit->dwFrameCountPrecise >> 8;
    }
}

int __fastcall sub_M119_Emit_006216B0(int nMode, int nValue, int nOther)
{
    return UNITS_IsAnimModeBlock(nMode, nOther) + nValue;
}

// 0x00621870
void __stdcall UNITS_GetFrameMetrics(D2UnitStrc* pUnit, int* pFrame, int* pFrameCount)
{
    if (!pUnit)
    {
        *pFrame = 0;
        *pFrameCount = 0;
        return;
    }

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        *pFrame = pUnit->nSeqCurrentFramePrecise;
        *pFrameCount = pUnit->pObjectData->pObjectTxt->dwFrameCnt[pUnit->dwAnimMode];
        return;
    }

    *pFrame = pUnit->nSeqCurrentFramePrecise;
    *pFrameCount = pUnit->dwFrameCountPrecise;
}

// 0x006218D0
void __stdcall UNITS_SetAnimActionFrame(D2UnitStrc* pUnit, int nFrame)
{
    if (pUnit && pUnit->pAnimData && nFrame < 144)
    {
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 1)
        {
            pUnit->nActionFrame = 1;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 2)
        {
            pUnit->nActionFrame = 2;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 3)
        {
            pUnit->nActionFrame = 3;
        }
        if (pUnit->pAnimData->pFrameFlags[nFrame] == 4)
        {
            pUnit->nActionFrame = 4;
        }
    }
}

// 0x00621920
int __stdcall UNITS_GetEventFrameInfo(D2UnitStrc* ptUnit, int nFrame)
{
    if (!ptUnit)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xDCC);
        exit(-1);
    }
    if (nFrame >= 144)
        return 0;

    int bSequence = 0;
    switch (ptUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (ptUnit->dwAnimMode == PLRMODE_SEQUENCE)
            bSequence = 1;
    case UNIT_MONSTER:
        if (ptUnit->dwAnimMode == MONMODE_SEQUENCE)
            break;
        if (bSequence)
            break;
    default:
        return ptUnit->pAnimData->pFrameFlags[nFrame];
    }
    int nMode;
    int nSequenceFrame;
    int nDirection;
    int nEvent;
    D2AnimSeqTxt* pSequence = DATATBLS_GetMonSeqTxtRecordFromUnit(ptUnit);
    DATATBLS_ComputeSequenceAnimation(pSequence, nFrame << 8, nFrame << 8, &nMode, &nSequenceFrame, &nDirection, &nEvent);
    return nEvent;
}

// 0x006219C0
int __stdcall UNITS_HasCollision(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pObjectTxt->nHasCollision[pUnit->dwAnimMode];
    }

    return TRUE;
}

// 0x006219F0
D2SkillStrc* __stdcall UNITS_GetSkillFromSkillId(D2UnitStrc* hUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);

    D2_ASSERT(pSkillsTxtRecord, 3579);
    D2_ASSERT(hUnit, 1592);

    for (D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(hUnit->pSkills); pSkill; pSkill = pSkill->pNextSkill)
    {
        if (pSkill->pSkillsTxt == pSkillsTxtRecord)
        {
            return pSkill;
        }
    }
    return 0;
}

// 0x00621A70
int __stdcall UnitIsDoor(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3600);

    if (ptUnit->dwUnitType == UNIT_OBJECT)
    {
        return ptUnit->pObjectData->pObjectTxt->nIsDoor;
    }

    return FALSE;
}

// 0x00621AC0
bool __fastcall UNITS_CheckIfObjectOrientationIs1(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit->dwUnitType == UNIT_OBJECT, 3614);

    return ptUnit->pObjectData->pObjectTxt->nSide == 1;
}

// 0x00621B00
int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT && pUnit->pObjectData->pObjectTxt->nSubClass & OBJSUBCLASS_SHRINE)
    {
        return TRUE;
    }

    return FALSE;
}

// 0x00621B30
D2ObjectsTxt* __stdcall UNITS_GetObjectTxtRecordFromObject(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 3644);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pObjectTxt;
    }

    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 3651);
    exit(-1);
}

// 0x00621B70
D2ShrinesTxt* __stdcall UNITS_GetShrineTxtRecordFromObject(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 3662);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        return pUnit->pObjectData->pShrineTxt;
    }

    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 3669);
    exit(-1);
}

// 0x00621BB0
void __stdcall UNITS_SetShrineTxtRecordInObjectData(D2UnitStrc* pUnit, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2_ASSERT(pUnit, 3680);

    if (pUnit->dwUnitType == UNIT_OBJECT)
    {
        pUnit->pObjectData->pShrineTxt = pShrinesTxtRecord;
        return;
    }

    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 3687);
    exit(-1);
}

// 0x00621C00
void __stdcall UNITS_UpdateDirectionAndSpeed(D2UnitStrc* pUnit, int nX, int nY)
{
    if (pUnit->pDynamicPath)
    {
        D2Common_10216(pUnit->pDynamicPath, nX, nY, 0);
    }
}

static inline int sub_T03_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitType;
}

static inline int sub_T03_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

static inline void* sub_M442_GetMemPool(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->pMemoryPool;
}

// 0x00621C30
static void __stdcall UNITS_StoreOwnerInfo(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    D2StatListStrc* pStatList = 0;

    if (pUnit)
    {
        pUnit->dwOwnerType = nOwnerType;
        pUnit->dwOwnerGUID = nOwnerId;

        if (pUnit->pStatListEx)
        {
            STATES_ToggleState(pUnit, 0x62, 1);
            pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_SOURCEUNIT);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(sub_M442_GetMemPool(pUnit), 0, 0, sub_T03_GetUnitType(pUnit), sub_T03_GetUnitId(pUnit));
                if (!pStatList)
                    return;

                STATLIST_SetState(pStatList, 0x62);
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
            }

            STATLIST_SetStatIfListIsValid(pStatList, STAT_SOURCE_UNIT_TYPE, nOwnerType, 0);
            STATLIST_SetStatIfListIsValid(pStatList, STAT_SOURCE_UNIT_ID, nOwnerId, 0);
        }

        pUnit->dwFlagEx |= 0x400;
    }
}

int __stdcall sub_O05_Emit_006214A0(D2UnitStrc* pUnit, int nUnitType, int nAnimMode, int nClassId)
{
    if (UNITS_CanAnimModeUseVelocityModifier(nUnitType, nAnimMode, pUnit, nClassId))
    {
        return nClassId;
    }
    return 0;
}

// 0x00621CC0
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId)
{
    UNITS_StoreOwnerInfo(pUnit, nOwnerType, nOwnerId);
}

// 0x00621CE0
void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    D2StatListStrc* pStatList = 0;

    if (pOwner)
    {
        UNITS_StoreOwnerInfo(pUnit, sub_T03_GetUnitType(pOwner), sub_T03_GetUnitId(pOwner));
    }
    else
    {
        if (pUnit)
        {
            pUnit->dwOwnerType = 0;
            pUnit->dwOwnerGUID = 0;

            if (pUnit->pStatListEx)
            {
                STATES_ToggleState(pUnit, 0x62, 0);

                pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_SOURCEUNIT);
                if (pStatList)
                {
                    D2Common_10474(pUnit, pStatList);
                    STATLIST_FreeStatList(pStatList);
                }
            }

            pUnit->dwFlagEx &= ~0x400;
        }
    }
}

// 0x00621D50
void __stdcall UNITS_StoreLastAttacker(D2UnitStrc* ptUnit, D2UnitStrc* pKiller)
{
    D2_ASSERT(ptUnit, 3815);

    if (pKiller)
    {
        ptUnit->dwKillerType = pKiller->dwUnitType;
        ptUnit->dwKillerGUID = pKiller->dwUnitId;
        ptUnit->dwFlagEx |= UNITFLAGEX_STORELASTATTACKER;
    }
    else
    {
        ptUnit->dwKillerType = 0;
        ptUnit->dwKillerGUID = 0;
        ptUnit->dwFlagEx &= ~UNITFLAGEX_STORELASTATTACKER;
    }
}

// 0x00621DC0
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY)
{
    const int nX = UNITS_GetPositionX(pUnit);
    const int nY = UNITS_GetPositionY(pUnit);

    return PATH_ComputeDirection(nX, nY, nNewX, nNewY);
}

// 0x00621E40
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x80);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0x80, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }
        D2Common_10534(pUnit);
        D2Common_10531_SetStatInStatListLayer0(pStatList, 0xB2, (unsigned short)nOverlay, nUnused);
        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x00621ED0
int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit)
{
    D2_ASSERT((pUnit ? pUnit->dwUnitType : UNIT_INVALID) == UNIT_ITEM, 3872);

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pUnit->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3876);

    return pItemsTxtRecord->nBelt;
}

// 0x00621F20
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit)
{
    const int nHp = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    if (const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8)
    {
        return (100 * nHp) / nMaxHp;
    }

    return 0;
}

// 0x00621F60
int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    const int nClassId = pUnit->dwClassId;
    return MONSTERREGION_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_SOFT) != 0;
}

// 0x00621F90
void __stdcall UNITS_AllocPlayerData(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3919);
    D2_ASSERT(!ptUnit->pPlayerData, 3921);

    ptUnit->pPlayerData = (D2PlayerDataStrc*)FOG_AllocPool(ptUnit->pMemoryPool, sizeof(D2PlayerDataStrc), ".\\UNITS\\Units.cpp", 3922, 0);
    memset(ptUnit->pPlayerData, 0x00, sizeof(D2PlayerDataStrc));
    ptUnit->pPlayerData->szName[0] = 0;

    for (int i = 0; i < 3; ++i)
    {
        D2BitBufferStrc* const pQuestRecord = QUESTRECORD_AllocRecord(GFXUTIL_GetNextRosterInfo((D2RosterInfoStrc*)ptUnit));
        // volatile: stands in for the reload of pPlayerData after the call (the original indexes it as [loop + record])
        (*(D2PlayerDataStrc* volatile*)&ptUnit->pPlayerData)->pQuestData[i] = pQuestRecord;
        ptUnit->pPlayerData->pWaypointData[i] = WAYPOINTS_AllocWaypointData(GFXUTIL_GetNextRosterInfo((D2RosterInfoStrc*)ptUnit));
    }

    ptUnit->pPlayerData->nPortalFlags = DUNGEON_GetPortalFlagFromLevelId(1);
    ptUnit->pPlayerData->bBusy = 0;
    sub_0066A250((int)ptUnit);
}

// 0x00622060
void __stdcall UNITS_FreePlayerData(void* pMemPool, D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 3947);
    D2_ASSERT(ptUnit->pPlayerData, 3949);

    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_FreeRecord(pMemPool, ptUnit->pPlayerData->pQuestData[i]);
        WAYPOINTS_FreeWaypointData(pMemPool, ptUnit->pPlayerData->pWaypointData[i]);
    }

    sub_0066A260_PlayerDataFreeHook(ptUnit);

    FOG_FreeServerMemory(pMemPool, ptUnit->pPlayerData, ".\\UNITS\\Units.cpp", 3958, 0);
    ptUnit->pPlayerData = 0;
}

inline D2PlayerDataStrc* UNITS_GetPlayerData_Inl(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x006220F0
unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* ptUnit, char* szName)
{
    D2_ASSERT(ptUnit, 0xF97);
    D2_ASSERT(ptUnit->pPlayerData, 0xF99);
    D2_ASSERT(ptUnit->dwUnitType == UNIT_PLAYER, 0xF9A);

    return SStrCopy(ptUnit->pPlayerData->szName, szName, 0x7FFFFFFF);
}

// 0x00622150
char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4005);
    D2_ASSERT(pUnit->pPlayerData, 4007);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4008);

    return pUnit->pPlayerData->szName;
}

// 0x006221A0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4020);

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4022);

    return pUnit->pPlayerData;
}

// 0x006221E0
void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags)
{
    D2_ASSERT(pUnit, 4031);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4032);

    pUnit->pPlayerData->nPortalFlags = nPortalFlags;
}

// 0x00622230
int __stdcall UNITS_GetPlayerPortalFlags(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4041);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 4042);

    return pUnit->pPlayerData->nPortalFlags;
}

// 0x00622270
unsigned int __stdcall UNITS_GetNameOffsetFromObject(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 4051);

    if (ptUnit->dwUnitType == UNIT_OBJECT)
    {
        return ptUnit->pObjectData->pObjectTxt->dwNameOffset;
    }

    return 0;
}

// 0x006222C0
unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 4068);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4069);
    return pUnit->pObjectData->nPortalFlags;
}

// 0x00622300
void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag)
{
    D2_ASSERT(pUnit, 4079);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4080);
    pUnit->pObjectData->nPortalFlags = nPortalFlag;
}

// 0x00622350
int __stdcall UNITS_CheckObjectPortalFlag(D2UnitStrc* pUnit, unsigned char nFlag)
{
    D2_ASSERT(pUnit, 4090);
    D2_ASSERT(pUnit->dwUnitType == UNIT_OBJECT, 4091);

    return (nFlag & pUnit->pObjectData->nPortalFlags) != 0;
}

// 0x006223A0
int __stdcall UNITS_GetOverlayHeight(D2UnitStrc* pUnit)
{
    switch (!pUnit ? UNIT_INVALID : pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return 1;

    case UNIT_MONSTER:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return 0;
        }

        return pMonStats2TxtRecord->nOverlayHeight - 1;
    }
    }

    return 0;
}

// 0x006223F0
int __stdcall UNITS_GetDefense(D2UnitStrc* pUnit)
{
    int nDefense = STATLIST_UnitGetStatValue(pUnit, STAT_ARMORCLASS, 0);
    nDefense += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) / 4;
    int nArmorPercent = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_SKILL_ARMOR_PERCENT, 0);
    nArmorPercent += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_ARMOR_PERCENT, 0);

    if (STATES_CheckState(pUnit, STATE_HOLYSHIELD))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HOLYSHIELD);
        if (pStatList)
        {
            const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
            const int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
            if (nSkillId > 0 && nSkillLevel > 0)
            {
                D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (pSkillsTxtRecord)
                {
                    D2UnitStrc* pShieldItem = 0;
                    INVENTORY_GetEquippedShield(pUnit->pInventory, &pShieldItem);
                    if (pShieldItem)
                    {
                        nArmorPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                    }
                }
            }
        }
    }

    if (nDefense > 0)
    {
        nDefense += nDefense * nArmorPercent / 100;
    }
    else
    {
        nDefense += nDefense * nArmorPercent / -100;
    }

    const int nArmorOverridePercent = STATLIST_UnitGetStatValue(pUnit, STAT_ARMOR_OVERRIDE_PERCENT, 0);
    if (nArmorOverridePercent)
    {
        nDefense += DATATBLS_ApplyRatio(nDefense, nArmorOverridePercent, 100);
    }
    return nDefense;
}

// 0x00622520
static int UNITS_GetCharStatsToHitFactor(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord_Inl(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    return pCharStatsTxtRecord->dwToHitFactor;
}

// calling-convention shim (not game code)
int __stdcall sub_00622520_Shim(D2UnitStrc* pUnit)
{
    return UNITS_GetCharStatsToHitFactor(pUnit);
}

static inline D2CharStatsTxt* UNITS_GetCharStatsTxtRecord(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        return &sgptDataTables->pCharStatsTxt[nClassId];
    return 0;
}

static inline int UNITS_GetToHitFactor(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = UNITS_GetCharStatsTxtRecord(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    return pCharStatsTxtRecord->dwToHitFactor;
}

// 0x006238C0
int __stdcall UNITS_GetNewDirection(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 3715);

    const int nX = UNITS_GetPositionX(hUnit);
    if (D2COMMON_10175_PathGetFirstPointX(hUnit->pDynamicPath) == nX)
    {
        const int nY = UNITS_GetPositionY(hUnit);
        if (D2COMMON_10176_PathGetFirstPointY(hUnit->pDynamicPath) == nY)
        {
            return PATH_GetNewDirection(hUnit->pDynamicPath);
        }
    }

    return UNITS_GetDirectionToCoords(hUnit, D2COMMON_10175_PathGetFirstPointX(hUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(hUnit->pDynamicPath));
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static inline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

inline unsigned char MONSTERS_GetComponentInline(D2UnitStrc* pUnit, int nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[nComponent];
    }
    return 0;
}

// 0x00623990
D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2)
{
    D2UnitStrc* pItem;
    int nBodyLoc;
    int bIsLeftHandItem;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    INVENTORY_GetEquippedWeapon(pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem);

    if (UNITS_CanDualWield(pUnit))
    {
        D2SkillStrc* pSkill = SKILLS_GetUsedSkillFromSkillList(pUnit->pSkills);
        if (!pSkill)
        {
            return pItem;
        }
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (!pSkillsTxtRecord)
        {
            return pItem;
        }

        D2UnitStrc* pWeapon = 0;
        switch (pSkillsTxtRecord->nWeapSel)
        {
        case 1:
            pWeapon = INVENTORY_GetCompositItem(pInventory, 6);
            break;

        case 2:
        {
            const int nFlags = SKILLS_GetFlags(pSkill) & 0x2000;
            pWeapon = INVENTORY_GetCompositItem(pInventory, 5);
            D2UnitStrc* pHandItem = INVENTORY_GetCompositItem(pInventory, 6);
            if (!pWeapon || !ITEMSIsA(pWeapon, 45) || pHandItem && ITEMSIsA(pHandItem, 45) && nFlags)
            {
                pWeapon = pHandItem;
            }
            break;
        }

        case 3:
        {
            const int nFrame = pUnit->dwSeqFrame >> 8;
            int bOther;
            if (sub_00463720_TestUnitFlagEx(pUnit, 0x4000000))
            {
                bOther = nFrame % 2;
            }
            else
            {
                bOther = nFrame > 5;
            }

            if (nFrame && (!a2 || bOther))
            {
                pWeapon = INVENTORY_GetCompositItem(pInventory, 6);
            }
            else
            {
                pWeapon = INVENTORY_GetCompositItem(pInventory, 5);
            }
            break;
        }

        case 4:
            pItem = 0;
            break;

        default:
            pWeapon = INVENTORY_GetCompositItem(pInventory, 5);
            if (!pWeapon || !ITEMSIsA(pWeapon, 45))
            {
                pWeapon = INVENTORY_GetCompositItem(pInventory, 6);
            }
            break;
        }

        if (ITEMSIsA(pWeapon, 45) && sub_0062A4E0_TestItem(pWeapon))
        {
            return pWeapon;
        }
        return pItem;
    }
    return pItem;
}

static inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_TYPES;
    }
    return pUnit->dwUnitType;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline int MONSTERS_HasNoShieldBlockFlagInline(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NOSHLDBLOCK >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NOSHLDBLOCK & 7];
}

static inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecordInline(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00622560
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker)
{
    const int bValid = pAttacker && pAttacker->dwUnitType == UNIT_PLAYER;
    D2_ASSERT(bValid, 0x107F);

    int nAttackRate = STATLIST_UnitGetStatValue(pAttacker, STAT_TOHIT, 0);
    int nDexterity = STATLIST_UnitGetStatValue(pAttacker, STAT_DEXTERITY, 0);
    nDexterity -= 7;
    nAttackRate += 5 * nDexterity;

    return nAttackRate + UNITS_GetToHitFactor(pAttacker);
}

// 0x006225F0
int __fastcall UNITS_CanMonsterBlock(D2UnitStrc* pUnit)
{
    switch (MONSTERS_ValidateMonsterIdInline(UNITS_GetClassIdInline(pUnit)))
    {
    case MONSTER_DIABLO:
    case MONSTER_DOOMKNIGHT1:
    case MONSTER_DIABLOCLONE:
        return 1;

    case MONSTER_ACT3HIRE:
        return 0;

    default:
        break;
    }

    const unsigned int dwCode = D2Common_11069(pUnit, COMPOSIT_RIGHTHAND, MONSTERS_GetComponentInline(pUnit, COMPOSIT_RIGHTHAND));
    if (!dwCode)
    {
        return 0;
    }

    for (unsigned int i = 0; i < gnNoBlockItemCodeCount; ++i)
    {
        if (dwCode == gdwNoBlockItemCodes[i])
        {
            return 0;
        }
    }

    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    if (pItemsTxtRecord && pItemsTxtRecord->wType[0] == ITEMTYPE_SHIELD)
    {
        return 1;
    }

    return 0;
}

// 0x00622720
int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int bExpansion)
{
    int nBlockChance = 0;

    switch (UNITS_GetUnitTypeInline(pUnit))
    {
    case UNIT_PLAYER:
        if (INVENTORY_GetEquippedShield(pUnit->pInventory, 0))
        {
            nBlockChance = STATLIST_UnitGetStatValue(pUnit, STAT_TOBLOCK, 0);
            nBlockChance += DATATBLS_GetCharStatsTxtRecordInline(pUnit->dwClassId)->nBlockFactor;
            if (bExpansion)
            {
                const int nDexterity = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
                int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
                if (nLevel <= 1)
                {
                    nLevel = 1;
                }
                nBlockChance = nBlockChance * (nDexterity - 15) / (2 * nLevel);
            }
        }
        break;

    case UNIT_MONSTER:
        if (MONSTERS_HasNoShieldBlockFlagInline(UNITS_GetClassIdInline(pUnit)) || UNITS_CanMonsterBlock(pUnit))
        {
            nBlockChance = STATLIST_UnitGetStatValue(pUnit, STAT_TOBLOCK, 0);
        }
        break;
    }

    if (nBlockChance < 75)
    {
        return nBlockChance;
    }
    return 75;
}

// 0x00622830
D2UnitStrc* __stdcall UNITS_GetEquippedWeaponFromMonster(D2UnitStrc* pMonster)
{
    D2UnitStrc* pItem;
    int bIsLeftHandItem;
    int nBodyLoc;

    const int nType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    if (!pMonster->pInventory)
    {
        return 0;
    }

    return INVENTORY_GetEquippedWeapon(pMonster->pInventory, &pItem, &nBodyLoc, &bIsLeftHandItem) ? pItem : 0;
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

// 0x00622870
int __stdcall UNITS_GetMeleeRange(D2UnitStrc* hUnit)
{
    if (!hUnit) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x11be); exit(-1); }
    int range;
    switch (hUnit->dwUnitType) {
    case UNIT_MONSTER: {
        D2MonStats2Txt* record = UNITS_GetMonStats2TxtRecordFromMonsterId(hUnit->dwClassId);
        if (!record) goto fail;
        range = record->nSteps;
        if (range == 255) {
            int weaponClass;
            COMPOSIT_GetWeaponClassId(hUnit, hUnit->pInventory, &weaponClass, -1, 1);
            return weaponClass == 6 ? 2 : 0;
        }
        break;
    }
    case UNIT_PLAYER: {
        D2UnitStrc* weapon;
        int type, flags;
        if (!INVENTORY_GetEquippedWeapon(hUnit->pInventory, &weapon, &type, &flags)) {
fail:
            return 0;
        }
        range = ITEMS_GetMeleeRange(weapon);
        break;
    }
    default:
        goto fail;
    }
    return range;
}

static int __stdcall sub_00622920_TestCollision(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask)
{
    COLLISION_RayTrace((D2ActiveRoomStrc*)nSize2, (D2CoordStrc*)nX1, (D2CoordStrc*)nX2, 0);
    return COLLISION_RayTrace(pRoom, (D2CoordStrc*)nY1, (D2CoordStrc*)nSize1, nY2 + nCollisionMask);
}

// 0x00622920
static int __fastcall UNITS_TestCollision(int nX1, int nY1, int nSize1, int nX2, int nY2, int nSize2, D2ActiveRoomStrc* pRoom, int nCollisionMask)
{
    D2CoordStrc tBegin;
    D2CoordStrc tEnd;
    int nBeginX = nX1;
    int nBeginY = nY1;
    int nEndX = nX2;
    int nEndY = nY2;
    int nXDiff;
    int nYDiff;

    const int nBeginSize = (nSize1 < 3) ? nSize1 : 2;
    const int nEndSize = (nSize2 < 3) ? nSize2 : 2;

    int nDX = nX2 - nX1;
    if (nDX < 0)
    {
        nXDiff = -nDX;
    }
    else
    {
        nXDiff = nDX;
    }

    int nDY = nY2 - nY1;
    if (nDY < 0)
    {
        nYDiff = -nDY;
    }
    else
    {
        nYDiff = nDY;
    }

    if (nXDiff + nYDiff < nBeginSize + nEndSize)
    {
        return 0;
    }

    if (nBeginSize || nEndSize)
    {
        if (nXDiff >= nYDiff)
        {
            if (nX2 > nX1)
            {
                nBeginX += nBeginSize;
                nEndX -= nEndSize;
            }
            else
            {
                nBeginX -= nBeginSize;
                nEndX += nEndSize;
            }
        }

        if (nYDiff >= nXDiff)
        {
            if (nY2 > nY1)
            {
                nBeginY += nBeginSize;
                nEndY -= nEndSize;
            }
            else
            {
                nBeginY -= nBeginSize;
                nEndY += nEndSize;
            }
        }
    }

    tBegin.nX = nBeginX;
    tBegin.nY = nBeginY;
    tEnd.nX = nEndX;
    tEnd.nY = nEndY;
    return COLLISION_RayTrace(pRoom, &tBegin, &tEnd, nCollisionMask);
}

// 0x006229F0
int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask)
{
    if (!pUnit)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nUnitX = UNITS_GetXPositionForceInl(pUnit);
    const int nUnitY = UNITS_GetYPositionForceInl(pUnit);
    const int nUnitSize = UNITS_GetUnitSizeX(pUnit);
    return UNITS_TestCollision(nUnitX, nUnitY, nUnitSize, nX, nY, 2, pRoom, nCollisionMask);
}

// 0x00622AA0
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask)
{
    if (!pUnit1) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1290); exit(-1); }
    if (!pUnit2) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1291); exit(-1); }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit1);
    if (!pRoom)
    {
        return 0;
    }

    const int nX1 = CLIENTS_GetUnitX(pUnit1);
    const int nY1 = CLIENTS_GetUnitY(pUnit1);
    const int nSize1 = UNITS_GetUnitSizeX(pUnit1);
    const int nX2 = CLIENTS_GetUnitX(pUnit2);
    const int nY2 = CLIENTS_GetUnitY(pUnit2);
    const int nSize2 = UNITS_GetUnitSizeX(pUnit2);
    return sub_00622920_TestCollision(nX1, nY1, nSize1, nX2, nY2, nSize2, pRoom, nCollisionMask);
}

inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

// 0x00624690
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || pUnit->dwUnitType == UNIT_TILE)
        return 0;
    if (pUnit->dwAnimMode != nMode)
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwAnimMode = nMode;
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
        STATLIST_DeactivateTemporaryStates(pUnit);
        UNITS_SetAnimStartFrame(pUnit);
        return 1;
    }
    if (!(pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_NEUTRAL))
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
    }
    return 0;
}

// 0x00622B50
int __stdcall UNITS_TestCollisionBetweenInteractingUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask)
{
    if (!pUnit1 || !pUnit2)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit1);
    if (!pRoom)
    {
        return 0;
    }

    const int nX1 = CLIENTS_GetUnitX(pUnit1);
    const int nY1 = CLIENTS_GetUnitY(pUnit1);
    const int nX2 = CLIENTS_GetUnitX(pUnit2);
    const int nY2 = CLIENTS_GetUnitY(pUnit2);
    int bRemoved1 = 0;
    int bRemoved2 = 0;
    if (UNITS_GetCollisionMask(pUnit1) & nCollisionMask)
    {
        bRemoved1 = PATH_RemoveCollisionFootprintForUnit(pUnit1, 0);
    }

    if (UNITS_GetCollisionMask(pUnit2) & nCollisionMask)
    {
        bRemoved2 = PATH_RemoveCollisionFootprintForUnit(pUnit2, 0);
    }

    const int nResult = UNITS_TestCollision(nX1, nY1, UNITS_GetUnitSizeX(pUnit1), nX2, nY2, UNITS_GetUnitSizeX(pUnit2), pRoom, nCollisionMask);
    if (bRemoved1)
    {
        PATH_AddCollisionFootprintForUnit(pUnit1);
    }

    if (bRemoved2)
    {
        PATH_AddCollisionFootprintForUnit(pUnit2);
    }

    return nResult;
}

// 0x00622C40
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus)
{
    if (pUnit2 && pUnit1)
    {
        const int nType = pUnit2 ? pUnit2->dwUnitType : UNIT_INVALID;
        if (nType == UNIT_MONSTER)
        {
// build: symbol ?CUNIT_GetMonsterBaseId@* 0x00463860
            switch (MONSTERS_ValidateMonsterIdInline(CUNIT_GetMonsterBaseId(pUnit2)))
            {
            case MONSTER_TENTACLE1:
            case MONSTER_TENTACLEHEAD1:
            {
                const int nDistance = D2Common_10399(pUnit1, pUnit2);
                if (UNITS_GetMeleeRange(pUnit1) + 8 > nDistance)
                {
                    return 1;
                }
                break;
            }
            }
        }

        const int nRange = UNITS_GetMeleeRange(pUnit1) + nRangeBonus + 1;
        const int nDistance = D2Common_10399(pUnit1, pUnit2);
        if (nDistance > 0 && nRange < nDistance)
        {
            return 0;
        }

        if (nDistance <= 0)
        {
            return 1;
        }

        return UNITS_TestCollisionWithUnit(pUnit1, pUnit2, COLLIDE_MASK_PLAYER_FLYING) == 0;
    }

    return 0;
}

// 0x00622D00
int __stdcall UNITS_IsInMovingMode(D2UnitStrc* hUnit)
{
    if (!hUnit)
    {
        return 0;
    }

    switch (hUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        switch ((unsigned int)UNITS_GetAnimOrSeqMode(hUnit))
        {
        case PLRMODE_WALK:
        case PLRMODE_RUN:
        case PLRMODE_TOWNWALK:
            return 1;

        default:
            return 0;
        }

    case UNIT_MONSTER:
        switch (UNITS_GetAnimModeInline(hUnit))
        {
        case MONMODE_WALK:
        case MONMODE_RUN:
            return 1;

        case MONMODE_SKILL1:
        case MONMODE_SKILL2:
            return MONSTERS_GetBaseIdFromMonsterId(CUNIT_GetMonsterBaseId(hUnit)) == MONSTER_VULTURE1;

        default:
            return 0;
        }

    case UNIT_MISSILE:
        D2_ASSERT(hUnit->dwUnitType != UNIT_MISSILE, 4901);
        return 0;

    default:
        return 0;
    }
}

// 0x00622DC0
int __stdcall UNITS_IsInMovingModeEx(D2UnitStrc* pUnit)
{
    return UNITS_IsInMovingMode(pUnit) != 0;
}

// 0x00623C20
int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            if (D2UnitStrc* pItem = D2Common_10434(pUnit, 0))
                return ITEMS_GetHitClassFromItem(pItem);
            else
                return 1;
        }
        else if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            if (D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId))
                return pMonStats2TxtRecord->nHitClass;
        }
    }
    return 0;
}

// 0x00623C60
int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (D2UnitStrc* pItem = D2Common_10434(pUnit, 1))
        return ITEMS_GetWeaponClassId(pItem);
    return 0;
}

// 0x00623C80
void __stdcall UNITS_MergeDualWieldWeaponStatLists(D2UnitStrc* pUnit, int a2)
{
    if (!UNITS_CanDualWield(pUnit))
    {
        return;
    }
    D2UnitStrc* pWeapon = D2Common_10434(pUnit, a2);
    D2UnitStrc* pPrimaryWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    if (!pWeapon)
    {
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 1);
        }
    }
    else if (pWeapon == pPrimaryWeapon)
    {
        D2UnitStrc* pSecondaryWeapon = INVENTORY_GetSecondaryWeapon(pUnit->pInventory);
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 1);
        }
        if (pSecondaryWeapon && STATLIST_GetOwner(pSecondaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pSecondaryWeapon, 0);
        }
    }
    else
    {
        if (STATLIST_GetOwner(pWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, 1);
        }
        if (pPrimaryWeapon && STATLIST_GetOwner(pPrimaryWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pPrimaryWeapon, 0);
        }
    }
}

// 0x00622DE0
unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit)
{
    const unsigned int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const unsigned int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const unsigned int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);

    unsigned int nShiftedLifeDifference = 0;
    unsigned int nShiftedManaDifference = 0;

    if (nMaxLife > nLife)
    {
        nShiftedLifeDifference = (nMaxLife - nLife) >> 8;
    }

    if (nMaxMana > nMana)
    {
        nShiftedManaDifference = (nMaxMana - nMana) >> 8;
    }

    if (nShiftedLifeDifference || nShiftedManaDifference)
    {
        return (nShiftedLifeDifference + nShiftedManaDifference) * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) >> 2;
    }

    return 0;
}

// 0x00622E70
unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit)
{
    return 10000 * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
}

// 0x00622E90
void __stdcall sub_00622E90_Nop(D2UnitStrc* pUnit, int a2)
{
}

// 0x00623D60
unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 5 || nBodyLoc == 4)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!sub_0062A4E0_TestItem(pRightHandItem))
        {
            pRightHandItem = 0;
        }
        D2UnitStrc* pLeftHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (!sub_0062A4E0_TestItem(pLeftHandItem))
        {
            pLeftHandItem = 0;
        }
        if (pRightHandItem && pLeftHandItem && !ITEMS_CheckWeaponIfTwoHanded(pRightHandItem) && !ITEMS_CheckWeaponIfTwoHanded(pLeftHandItem)
            && UNITS_CanDualWield(pUnit) && pItem != INVENTORY_GetLeftHandWeapon(pInventory))
        {
            return 6;
        }
    }
    return ITEMS_GetComponent(pItem);
}

// 0x00622EA0
void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x13F6);

        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        pPlayerData->nRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x13FA);
        pPlayerData->nRightSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622F10
void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1405);

        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        pPlayerData->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1409);
        pPlayerData->nLeftSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622F80
void __stdcall UNITS_InitSwitchRightSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1414);

        D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
        pPlayerData->nSwitchRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1419);
        pPlayerData->nSwitchRightSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00622FF0
void __stdcall UNITS_InitSwitchLeftSkill(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1424);

        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        pPlayerData->nSwitchLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNITS\\Units.cpp", 0x1429);
        pPlayerData->nSwitchLeftSkillFlags = SKILLS_GetOwnerGUIDFromSkill(pSkill);
    }
}

// 0x00623060
void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pRightSkillId, int* pRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pRightSkillId = 0;
        *pRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1438);

        *pRightSkillId = pPlayerData->nRightSkillId;
        *pRightSkillFlags = pPlayerData->nRightSkillFlags;
    }
}

// 0x006230C0
void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pLeftSkillId, int* pLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pLeftSkillId = 0;
        *pLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1449);

        *pLeftSkillId = pPlayerData->nLeftSkillId;
        *pLeftSkillFlags = pPlayerData->nLeftSkillFlags;
    }
}

// 0x00623120
void __stdcall UNITS_GetSwitchRightSkillDataResetRightSkill(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchRightSkillId = 0;
        *pSwitchRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x145A);

        *pSwitchRightSkillId = pPlayerData->nSwitchRightSkillId;
        *pSwitchRightSkillFlags = pPlayerData->nSwitchRightSkillFlags;

        pPlayerData->nRightSkillId = 0;
        pPlayerData->nRightSkillFlags = -1;
        pPlayerData->nWeaponGUID = -1;
        pPlayerData->unk0x94 = 0;
    }
}

// 0x006231A0
void __stdcall UNITS_GetSwitchLeftSkillDataResetLeftSkill(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchLeftSkillId = 0;
        *pSwitchLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1470);

        *pSwitchLeftSkillId = pPlayerData->nSwitchLeftSkillId;
        *pSwitchLeftSkillFlags = pPlayerData->nSwitchLeftSkillFlags;

        pPlayerData->nLeftSkillId = 0;
        pPlayerData->nLeftSkillFlags = -1;
        pPlayerData->nWeaponGUID = -1;
        pPlayerData->unk0x94 = 0;
    }
}

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetXPosition(pUnit->pDynamicPath);
        return 0;
    }
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
            return PATH_GetYPosition(pUnit->pDynamicPath);
        return 0;
    }
}

// 0x00623830
void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit)
{
    int nY = UNITS_GetYPositionInline(pUnit);
    int nX = UNITS_GetXPositionInline(pUnit);
    COLLISION_ResetMaskWithSizeXY(UNITS_GetRoom(pUnit), nX, nY, UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
}

// 0x00623220
void __stdcall UNITS_GetSwitchLeftSkillData(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchLeftSkillId = 0;
        *pSwitchLeftSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1487);

        *pSwitchLeftSkillId = pPlayerData->nSwitchLeftSkillId;
        *pSwitchLeftSkillFlags = pPlayerData->nSwitchLeftSkillFlags;
    }
}

// 0x00623290
void __stdcall UNITS_GetSwitchRightSkillData(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        *pSwitchRightSkillId = 0;
        *pSwitchRightSkillFlags = -1;
    }
    else
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 0x1499);

        *pSwitchRightSkillId = pPlayerData->nSwitchRightSkillId;
        *pSwitchRightSkillFlags = pPlayerData->nSwitchRightSkillFlags;
    }
}

// 0x00623300
void __stdcall UNITS_SetSwitchLeftSkill(D2UnitStrc* pUnit, int nSwitchLeftSkillId, int nSwitchLeftSkillFlags)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 5288);

        pPlayerData->nSwitchLeftSkillId = nSwitchLeftSkillId;
        pPlayerData->nSwitchLeftSkillFlags = nSwitchLeftSkillFlags;
    }
}

// 0x00623350
void __stdcall UNITS_SetSwitchRightSkill(D2UnitStrc* pUnit, int nSwitchRightSkillId, int nSwitchRightSkillFlags)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 5303);

        pPlayerData->nSwitchRightSkillId = nSwitchRightSkillId;
        pPlayerData->nSwitchRightSkillFlags = nSwitchRightSkillFlags;
    }
}

// 0x006233A0
void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* hWeapon)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData_Inl(pUnit);
        D2_ASSERT(pPlayerData, 5317);

        if (hWeapon)
        {
            D2_ASSERT(hWeapon->dwUnitType == UNIT_ITEM, 5321);

            pPlayerData->nWeaponGUID = hWeapon->dwUnitId;
        }
        else
        {
            pPlayerData->nWeaponGUID = 0;
        }
    }
}

// 0x00623410
int __stdcall UNITS_GetWeaponGUID(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 4020);
    D2_ASSERT(ptUnit->dwUnitType == UNIT_PLAYER, 4022);
    D2_ASSERT(ptUnit->pPlayerData, 5335);

    return ptUnit->pPlayerData->nWeaponGUID;
}

// 0x00623460
extern "C" __declspec(dllexport) int __stdcall UNITS_GetStashGoldLimit(int nUnused) {
    return 2500000;
}

// 0x00623470
int __fastcall UNITS_CanSwitchAI(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
        return 0;
    if (!sub_0046C140_TestMonModeFlag(nMonsterId, MONMODE_WALK))
        return 0;
    if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7])
        return 0;
    return (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_SWITCHAI >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_SWITCHAI & 7]) != 0;
}

// 0x006234C0
void __fastcall UNITS_SetTimerArg(D2UnitStrc* pUnit, D2TimerArgStrc* pTimerArg)
{
    D2_ASSERT(pUnit, 5387);

    pUnit->pTimerArg = pTimerArg;
}

// 0x006234F0
D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 5395);

    return pUnit->pTimerArg;
}

static inline int UNITS_GetUnitType_Inl(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 6;
    return pUnit->dwUnitType;
}

static inline int UNITS_GetClassId_Inl(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

static inline int UNITS_GetAnimMode_Inl(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return pUnit->dwAnimMode;
}

// 0x00623B10
int __stdcall UNITS_GetFrameBonus(D2UnitStrc* pUnit)
{
    int nUnitType = UNITS_GetUnitType_Inl(pUnit);
    int nClassId = UNITS_GetClassId_Inl(pUnit);
    int nAnimMode = UNITS_GetAnimMode_Inl(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nAnimMode, ".\\UNITS\\Units.cpp", 0x118A);

    if (nUnitType != 0)
        return 0;

    switch (nAnimMode)
    {
    case 7:
    case 8:
    {
        D2UnitStrc* pWeapon = D2Common_10434(pUnit, 1);
        unsigned short nWeaponClass = 0;
        if (pWeapon)
            nWeaponClass = ITEMS_GetWeaponClassId(pWeapon);
        return gaClassesWeaponFrameBonus[nWeaponClass][nClassId];
    }
    case 15:
    case 16:
        if (UNITS_CanDualWield(pUnit))
        {
            D2UnitStrc* pWeapon = D2Common_10434(pUnit, 1);
            unsigned short nWeaponClass = 0;
            if (pWeapon)
                nWeaponClass = ITEMS_GetWeaponClassId(pWeapon);
            return gaClassesWeaponFrameBonus[nWeaponClass][nClassId];
        }
        break;
    }

    return 0;
}

// 0x00623520
void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit)
{
    if (!pUnit->pStaticPath)
    {
        pUnit->pStaticPath = (D2StaticPathStrc*)sub_0040B430(pUnit->pMemoryPool, sizeof(D2StaticPathStrc), ".\\UNITS\\Units.cpp", 5406, 0);
        memset(pUnit->pStaticPath, 0x00, sizeof(D2StaticPathStrc));
    }
}

// 0x00623570
void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit)
{
    if (pUnit->pStaticPath)
    {
        FOG_FreeServerMemory(pUnit->pMemoryPool, pUnit->pStaticPath, ".\\UNITS\\Units.cpp", 5419, 0);
    }
}

// 0x006235A0
int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        switch (nClassId)
        {
        case PCLASS_BARBARIAN:
        case PCLASS_ASSASSIN:
            return TRUE;
        }
        return FALSE;

    case UNIT_MONSTER:
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            switch (nClassId)
            {
            case MONSTER_SHADOWWARRIOR:
            case MONSTER_SHADOWMASTER:
                return TRUE;
            }
        }
        return FALSE;
    }

    return FALSE;
}

// 0x00623600
int __stdcall UNITS_IsCorpseUseable(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    if (pUnit->dwAnimMode != MONMODE_DEAD)
        return 0;

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2TxtRecord)
        return 0;

    if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_DEADCOL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_DEADCOL & 7])
        return 0;

    if (!(pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_CORPSESEL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_CORPSESEL & 7]))
        return 0;

    return STATES_CheckStateMaskUdeadOnUnit(pUnit) == 0;
}

static inline void StopSequence_SetActionFrame(D2UnitStrc* pUnit, int nFrame)
{
    D2AnimDataRecordStrc* pAnimData = pUnit->pAnimData;
    if (pAnimData && nFrame < 144)
    {
        if (pAnimData->pFrameFlags[nFrame] == 1)
        {
            pUnit->nActionFrame = 1;
        }
        if (pAnimData->pFrameFlags[nFrame] == 2)
        {
            pUnit->nActionFrame = 2;
        }
        if (pAnimData->pFrameFlags[nFrame] == 3)
        {
            pUnit->nActionFrame = 3;
        }
        if (pAnimData->pFrameFlags[nFrame] == 4)
        {
            pUnit->nActionFrame = 4;
        }
    }
}

// 0x00623E00
void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit)
{
    pUnit->nActionFrame = 0;

    if (pUnit->pAnimSeq)
    {
        const int nOldFrame = pUnit->dwSeqFrame;
        pUnit->dwFlags &= ~0x4000;
        pUnit->dwSeqFrame += pUnit->dwSeqSpeed;
        if (pUnit->dwSeqFrame >= pUnit->dwSeqFrameCount)
            pUnit->dwSeqFrame -= pUnit->dwSeqFrameCount;
        pUnit->dwFrameCountPrecise -= pUnit->dwSeqSpeed;
        if (UNITS_UpdateSequenceFrame(pUnit, nOldFrame))
            pUnit->dwFlags |= 0x4000;
    }
    else
    {
        int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
        if (pUnit->wAnimSpeed >= 0x100)
            nFrame++;

        pUnit->nSeqCurrentFramePrecise += pUnit->wAnimSpeed;

        while (pUnit->nSeqCurrentFramePrecise >= pUnit->dwFrameCountPrecise)
        {
            for (int i = nFrame; i < pUnit->dwFrameCountPrecise >> 8; i++)
            {
                StopSequence_SetActionFrame(pUnit, i);
            }
            nFrame = 0;
            pUnit->nSeqCurrentFramePrecise -= pUnit->dwFrameCountPrecise;
            pUnit->nSeqCurrentFramePrecise += UNITS_GetFrameBonus(pUnit) << 8;
        }

        const int nLastFrameReached = pUnit->nSeqCurrentFramePrecise >> 8;
        for (int i = nFrame; i <= nLastFrameReached; i++)
        {
            StopSequence_SetActionFrame(pUnit, i);
        }
    }
}

static inline int UNITS_IsAnimModeBlockingCase_Inl(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 9) return 1;
        break;
    case 1:
        if (nAnimMode == 6) return 1;
        break;
    }
    return 0;
}

static inline int UNITS_IsAnimModeGetHitCase_Inl(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 4) return 1;
        break;
    case 1:
        if (nAnimMode == 3) return 1;
        break;
    }
    return 0;
}

static inline int UNITS_IsAnimModeKnockBackCase_Inl(int nUnitType, int nAnimMode)
{
    switch (nUnitType)
    {
    case 0:
        if (nAnimMode == 0x13) return 1;
        break;
    case 1:
        if (nAnimMode == 0xD) return 1;
        break;
    }
    return 0;
}

// 0x00623F50
void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine)
{
    if (!pUnit)
    {
        return;
    }

    int nUnitType = pUnit->dwUnitType;
    if (nUnitType >= 5)
    {
        return;
    }

    if (nUnitType == 4)
    {
        return;
    }

    int nClassId = pUnit->dwClassId;
    int nAnimMode = pUnit->dwAnimMode;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nAnimMode, ".\\UNITS\\Units.cpp", 0xCB9);
    sub_00620F00(pUnit, nUnitType, nClassId, nAnimMode);
    D2AnimDataRecordStrc* pAnimData = pUnit->pAnimData;

    if (UNITS_IsSeqAnimSpeedModulatedByFCR(nUnitType, nAnimMode, pUnit))
    {
        int nRate = UNITS_GetAnimStatBasePercentage(pUnit, 2) + 0x64;
        if (nRate > 0xAF)
        {
            nRate = 0xAF;
        }

        UNITS_SetAnimationSpeed_Inl(pUnit, nRate * pAnimData->dwAnimSpeed / 100);
        pUnit->dwSeqSpeed = pUnit->wAnimSpeed;
        return;
    }

    if (UNITS_IsAnimModeBlockingCase_Inl(nUnitType, nAnimMode))
    {
        const int nFasterBlockRate = UNITS_GetAnimStatBasePercentage(pUnit, 3);
        int nBlockRateBonus = 0x32;
        if (STATES_CheckState(pUnit, STATE_HOLYSHIELD))
        {
            nBlockRateBonus = 0x64;
        }

        nBlockRateBonus += nFasterBlockRate;
        UNITS_SetAnimationSpeed_Inl(pUnit, D2_MAX(1u, pAnimData->dwAnimSpeed * nBlockRateBonus / 100));
        return;
    }

    if (UNITS_IsAnimModeGetHitCase_Inl(nUnitType, nAnimMode))
    {
        const int nRate = UNITS_GetAnimStatBasePercentage(pUnit, 1) + 0x32;
        UNITS_SetAnimationSpeed_Inl(pUnit, nRate * pAnimData->dwAnimSpeed / 100);
        return;
    }

    if (UNITS_IsAnimModeKnockBackCase_Inl(nUnitType, nAnimMode))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, UNITS_GetBaseAnimSpeed(nUnitType, nClassId, nAnimMode));
        PATH_SetVelocity(pUnit->pDynamicPath, 0x1000, ".\\UNITS\\Units.cpp", 0xCE9);
        return;
    }

    if (UNITS_CanAnimModeUseVelocityModifier(nUnitType, nAnimMode, pUnit, nClassId))
    {
        if (pUnit->pDynamicPath)
        {
            const int nFasterMoveVelocity = UNITS_GetAnimStatBasePercentage(pUnit, 4);
            int nVelocityPercent = nFasterMoveVelocity + STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
            if (nVelocityPercent < 0x19)
            {
                nVelocityPercent = 0x19;
            }

            UNITS_SetAnimationSpeed_Inl(pUnit, nVelocityPercent * UNITS_GetBaseAnimSpeed(nUnitType, nClassId, nAnimMode) / 100);
            PATH_SetVelocity(pUnit->pDynamicPath, nVelocityPercent * UNITS_GetBaseVelocity(nUnitType, nClassId) / 100, ".\\UNITS\\Units.cpp", 0xD0A);
        }
        return;
    }

    if (UNITS_CanAnimModeUseAttackRate(nAnimMode, nUnitType, pUnit, nClassId))
    {
        UNITS_MergeDualWieldWeaponStatLists(pUnit, 1);
        const int nFasterAttackRate = UNITS_GetAnimStatBasePercentage(pUnit, 0);
        int nRate = nFasterAttackRate + STATLIST_UnitGetStatValue(pUnit, STAT_ATTACKRATE, 0);
        if (UNITS_CanDualWield(pUnit))
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            if (!sub_0062A4E0_TestItem(pRightWeapon))
            {
                pRightWeapon = 0;
            }

            D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            if (!sub_0062A4E0_TestItem(pLeftWeapon))
            {
                pLeftWeapon = 0;
            }

            if (ITEMSIsA(pRightWeapon, 0x2D) && ITEMSIsA(pLeftWeapon, 0x2D))
            {
                const int nRightAttackRate = STATLIST_UnitGetStatValue(pRightWeapon, STAT_ATTACKRATE, 0);
                const int nLeftAttackRate = STATLIST_UnitGetStatValue(pLeftWeapon, STAT_ATTACKRATE, 0);
                nRate += (nRightAttackRate + nLeftAttackRate) / 2 - nRightAttackRate;
            }
        }

        if (!pUnit->dwUnitType && pUnit->dwAnimMode == 0x12)
        {
            nRate -= 0x1E;
        }

        if (nRate < 0xF)
        {
            nRate = 0xF;
        }
        else if (nRate > 0xAF)
        {
            nRate = 0xAF;
        }

        unsigned int nBaseSpeed = 0;
        if (STATES_CheckStateMaskOnUnit(pUnit, 0x26))
        {
            nBaseSpeed = D2Common_11043(pUnit);
        }

        if (!nBaseSpeed)
        {
            nBaseSpeed = pAnimData->dwAnimSpeed;
        }

        int nAnimSpeed = nRate * nBaseSpeed / 100;
        nAnimSpeed = nAnimSpeed > 0 ? nAnimSpeed : 0;
        if (nAnimSpeed >= 0x7FFF)
        {
            nAnimSpeed = 0x7FFF;
        }

        pUnit->dwSeqSpeed = (short)nAnimSpeed;
        pUnit->wAnimSpeed = (short)nAnimSpeed;
        return;
    }

    if (UNITS_AnimModeAllowsAnimSpeed(nUnitType, nAnimMode, nClassId))
    {
        UNITS_SetAnimationSpeed_Inl(pUnit, pAnimData->dwAnimSpeed);
        return;
    }

    int nOtherAnimRate = STATLIST_UnitGetStatValue(pUnit, STAT_OTHER_ANIMRATE, 0);
    if (nOtherAnimRate < 0xF)
    {
        nOtherAnimRate = 0xF;
    }
    else if (nOtherAnimRate > 0xAF)
    {
        nOtherAnimRate = 0xAF;
    }

    UNITS_SetAnimationSpeed_Inl(pUnit, nOtherAnimRate * pAnimData->dwAnimSpeed / 100);
}

static inline int UNITS_ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
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

// 0x00624390
int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0x951);

    ptUnit->nActionFrame = 0;
    ptUnit->nSeqCurrentFramePrecise = UNITS_GetFrameBonus(ptUnit) << 8;

    int nUnitType = ptUnit->dwUnitType;
    int nMode = ptUnit->dwAnimMode;
    int nClassId = ptUnit->dwClassId;
    D2COMMON_11013_ConvertMode(ptUnit, &nUnitType, &nClassId, &nMode, ".\\UNITS\\Units.cpp", 0x958);

    switch (nUnitType)
    {
    case 0:
        if (nMode == 3 || nMode == 0x13)
        {
            UNITS_CharacterStartRunningOrKnockback(ptUnit, nClassId);
        }

        if (nMode == 0x12)
        {
            UNITS_InitializeSequence(ptUnit);
            UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x967);
            return 1;
        }

        ptUnit->pAnimSeq = 0;
        UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x96A);
        ptUnit->dwFrameCountPrecise = ptUnit->pAnimData->dwFrames << 8;
        return 1;

    case 1:
        if (ptUnit->dwUnitType == UNIT_PLAYER && STATES_IsUnitShapeShifted(ptUnit))
        {
            switch (nMode)
            {
            case 0xD:
            case 0xF:
                UNITS_CharacterStartRunningOrKnockback(ptUnit, ptUnit->dwClassId);
                break;
            }
        }

        if (nMode == 0xE)
        {
            UNITS_InitializeSequence(ptUnit);
            UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x97E);
            return 1;
        }

        UnitUpdateAnimRateAndVel(ptUnit, ".\\UNITS\\Units.cpp", 0x980);
        ptUnit->pAnimSeq = 0;
        ptUnit->dwFrameCountPrecise = ptUnit->pAnimData->dwFrames << 8;
        return 1;

    case 2:
    {
        const int nNewMode = nMode;
        D2_ASSERT(nNewMode < 8, 0x98A);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(ptUnit->dwClassId);
        ptUnit->dwFrameCountPrecise = pObjectsTxtRecord->dwFrameCnt[nNewMode];
        const int nStartFrame = pObjectsTxtRecord->nStart[nNewMode] << 8;
        short nAnimSpeed = pObjectsTxtRecord->nFrameDelta[nNewMode];
        ptUnit->nSeqCurrentFramePrecise = nStartFrame;
        if (pObjectsTxtRecord->nSync)
        {
            ptUnit->wAnimSpeed = nAnimSpeed;
            return 1;
        }

        int nSpeed = ITEMS_RollLimitedRandomNumber(&ptUnit->pSeed, nAnimSpeed >> 3) + nAnimSpeed - (short)(nAnimSpeed >> 4);
        nSpeed = nSpeed <= 0 ? 0 : nSpeed;
        if (nSpeed >= 0x7FFF)
        {
            nSpeed = 0x7FFF;
        }
        ptUnit->wAnimSpeed = nSpeed;
        return 1;
    }

    case 4:
        switch (nMode)
        {
        case 5:
            ptUnit->wAnimSpeed = 0x100;
            ptUnit->dwFrameCountPrecise = 0x1100;
            return 1;

        case 3:
            ptUnit->wAnimSpeed = 0;
            ptUnit->dwFrameCountPrecise = 0x1100;
            ptUnit->nSeqCurrentFramePrecise = 0x1000;
            return 1;
        }
        break;

    case 3:
    {
        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(ptUnit->dwClassId);
        if (!pMissilesTxtRecord)
        {
            return 0;
        }

        ptUnit->wAnimSpeed = UNITS_ApplyRatio_Inline(256, pMissilesTxtRecord->nAnimLen_2, 1024);
        ptUnit->dwFrameCountPrecise = pMissilesTxtRecord->nAnimLen << 8;
        break;
    }
    }

    return 1;
}

// 0x00623660
int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    int nX1 = 0;
    int nY1 = 0;
    int nX2 = 0;
    int nY2 = 0;
    int nX = 0;
    int nY = 0;
    int nSizeX2 = 0;
    int nSizeY2 = 0;

    const int nObjectType = pObject ? pObject->dwUnitType : UNIT_INVALID;
    if (nObjectType != 2)
    {
        return 0;
    }

    if ((unsigned int)D2Common_10399(pUnit, pObject) <= 0)
    {
        return 1;
    }

    nX1 = UNITS_GetXPositionInline(pUnit);
    nY1 = UNITS_GetYPositionInline(pUnit);

    nX2 = UNITS_GetXPositionInline(pObject);
    nY2 = UNITS_GetYPositionInline(pObject);

    nSizeX2 = UNITS_GetUnitSizeX(pObject);
    nSizeY2 = UNITS_GetUnitSizeY(pObject);

    nX = nX2 - nSizeX2 / 2;
    nY = nY2 - nSizeY2 / 2;

    if (nSizeX2 >= 1 && nSizeY2 >= 1)
    {
        if (nX1 >= nX - 2 && nX1 <= nSizeX2 + nX + 2 && nY1 >= nY - 2 && nY1 <= nSizeY2 + nY + 2)
        {
            if ((unsigned int)UNITS_GetUnitSizeX(pUnit) > 2)
            {
                return 1;
            }

            if (nY1 < nY - 1)
            {
                return nX1 >= nX - 1 && nX1 <= nSizeX2 + nX + 1;
            }

            return nY1 <= nSizeY2 + nY + 1 || (nX1 >= nX - 1 && nX1 <= nSizeX2 + nX + 1);
        }

        return 0;
    }

    return nX1 >= nX - 1 && nX1 <= nX + 1 && nY1 >= nY - 1 && nY1 <= nY + 1;
}

#include "gen/data/Source/D2Common/UNITS/Units.inc"
