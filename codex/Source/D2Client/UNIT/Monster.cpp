#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Txt.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"
#include "D2Structs.h"
#include "D2SkillIds.h"
#include "D2Unicode.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define STAT_LEVEL 12

#define STAT_ARMORCLASS_VS_HTH 33

#define H12_OFFSET(s, m) ((unsigned int)&((s*)0)->m)

struct D2GfxLightStrc;

struct Unicode;

struct D2HirelingInfoStrc;

struct D2HirelingTxt;

struct D2MonStats2Txt;

struct D2MonStatsTxt;

struct D2MonsterDataStrc;

struct D2MonCmdRecordStrc;

struct D2MissileStrc;

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2DirectionArgStrc;

struct D2ClientStringListStrc;

struct D2CoordStrc;

struct D2HirelingInitStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2MonStatsInitStrc;

struct D2MonAnimRecStrc;

struct D2HirelingInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int nSeed;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __cdecl SELECT_GetHoverClassId(); // 0x00466DD0

int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

int __stdcall INV_GetTableByte(int nUnused, int nIndex); // 0x004B92E0

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930

D2HirelingTxt* __stdcall DATATBLS_GetHirelingTxtRecordFromIdAndLevel(int bExpansion, int nId, int nLevel); // 0x006562F0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName); // 0x0063E810

void __fastcall ITEM_RefreshUnitEquipment(D2UnitStrc* pUnit); // 0x004C1C10

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

float __stdcall GFXUTIL_VectorLengthSquared(float fX, float fY); // 0x004E4160

extern D2DrlgActStrc* gpAct; // 0x007A0634

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg); // 0x00466CB0

void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10

void __fastcall DLIGHTMAP_ReleaseLight(D2GfxLightStrc* pLight); // 0x004743D0

void __stdcall MONSTER_RunUModCallbacks(D2UnitStrc* pUnit, void* pArg, int nMode); // 0x004ADD90

void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40

D2GfxLightStrc* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* pValue); // 0x00643A00

void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460

void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

extern unsigned int gdwBitMasks[]; // 0x006CE268

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610

void __fastcall UNITMODE_RecacheUnitPath(D2UnitStrc* pUnit); // 0x00480490

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

typedef unsigned int DWORD;

typedef char H12_check_unit_a[(H12_OFFSET(D2UnitStrc, dwAnimMode) == 0x10 && H12_OFFSET(D2UnitStrc, pSeed) == 0x20) ? 1 : -1];

typedef char H12_check_unit_b[(H12_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C && H12_OFFSET(D2UnitStrc, nActionFrame) == 0x4E) ? 1 : -1];

typedef char H12_check_unit_c[(H12_OFFSET(D2UnitStrc, dwFlags) == 0xC4 && H12_OFFSET(D2UnitStrc, nSeqCurrentFramePrecise) == 0x44) ? 1 : -1];

typedef char H12_check_txt_a[(H12_OFFSET(D2MonStatsTxt, nSplClientEnd) == 0x1A7 && H12_OFFSET(D2MonStats2Txt, nInfernoRollback) == 0x10A) ? 1 : -1];

typedef char H12_check_txt_b[(sizeof(D2SkillsTxt) == 0x23C && H12_OFFSET(D2DataTablesStrc, nSkillsTxtRecordCount) == 0xBA0) ? 1 : -1];

typedef char H12_check_txt_c[(H12_OFFSET(D2DataTablesStrc, pSkillsTxt) == 0xB98 && sizeof(D2MissileStrc) == 0x5C) ? 1 : -1];

typedef char H12_check_unit_d[(H12_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8) ? 1 : -1];

typedef char H12_check_misc[(H12_OFFSET(D2MissileStrc, nSkillLevel) == 0x30 && sizeof(D2MonAnimRecStrc) == 12) ? 1 : -1];

extern D2MonAnimRecStrc gaMonAnimRecords[]; // 0x00725220

extern D2MonAnimRecStrc gaMonAnimRecordsMoving[]; // 0x007252E0

extern D2MonAnimRecStrc gtDiabloAnimRecord; // 0x00725328

extern D2MonAnimRecStrc gtBaalAnimRecord; // 0x00725334

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask); // 0x00463720

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730

void __fastcall MONSTER_RunUModFrameCallbacks(D2UnitStrc* pUnit); // 0x004ADE60

void __stdcall MONSTER_SpawnQuillRatMissiles(D2UnitStrc* pUnit, int nMissile, int nX, int nY); // 0x004AF1B0

int __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit); // 0x004C68F0

void __fastcall SKILLS_RunStateActiveFuncs(D2UnitStrc* pUnit); // 0x004C72F0

void __fastcall UNITSND_UpdateModeSound(D2UnitStrc* pUnit); // 0x004CB460

D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall sub_00641530(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00641530

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall PATH_SetPathingFlag(D2DynamicPathStrc* pPath, int nArg); // 0x00648750

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0

typedef char I07_check_unit_a[(I07_OFFSET(D2UnitStrc, pSeed) == 0x20 && I07_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C) ? 1 : -1];

typedef char I07_check_unit_b[(I07_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8 && I07_OFFSET(D2StaticPathStrc, nYPos) == 0x10) ? 1 : -1];

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, D2DirectionArgStrc tDirection); // 0x006488A0

extern const int gaBloodOffsetY[]; // 0x006DA5F0

extern const int gaBloodOffsetX[]; // 0x006DA610

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0

void __stdcall GFXUTIL_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690

void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0



extern int gbGambleShop; // 0x007C0DB0

extern int gdwGlobal_007C0E54; // 0x007C0E54

extern int gdwSecondaryTradeGold; // 0x007C0E78

extern int gdwPrimaryTradeGold; // 0x007C0E68

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

extern D2ClientStringListStrc gtStringList; // 0x007C0D9A

extern D2UnitStrc* gpNpcPlayerUnit; // 0x007C0DD4

extern unsigned short gwGlobal_007C0DD8; // 0x007C0DD8

void __stdcall sub_M103_EmitSink(int nValue);

typedef char I20_check_unit_a[(I20_OFFSET(D2UnitStrc, dwAnimMode) == 0x10 && I20_OFFSET(D2UnitStrc, pSeed) == 0x20) ? 1 : -1];

typedef char I20_check_unit_b[(I20_OFFSET(D2UnitStrc, pDynamicPath) == 0x2C && I20_OFFSET(D2UnitStrc, nActionFrame) == 0x4E) ? 1 : -1];

typedef char I20_check_unit_c[(I20_OFFSET(D2UnitStrc, dwFlags) == 0xC4 && I20_OFFSET(D2UnitStrc, nSeqCurrentFramePrecise) == 0x44) ? 1 : -1];

typedef char I20_check_txt_a[(I20_OFFSET(D2MonStatsTxt, nSplClientEnd) == 0x1A7 && I20_OFFSET(D2MonStats2Txt, nInfernoRollback) == 0x10A) ? 1 : -1];

typedef char I20_check_txt_b[(sizeof(D2SkillsTxt) == 0x23C && I20_OFFSET(D2DataTablesStrc, nSkillsTxtRecordCount) == 0xBA0) ? 1 : -1];

typedef char I20_check_txt_c[(I20_OFFSET(D2DataTablesStrc, pSkillsTxt) == 0xB98 && sizeof(D2MissileStrc) == 0x5C) ? 1 : -1];

typedef char I20_check_unit_d[(I20_OFFSET(D2UnitStrc, dwFlagEx) == 0xC8) ? 1 : -1];

typedef char I20_check_misc[(I20_OFFSET(D2MissileStrc, nSkillLevel) == 0x30 && sizeof(D2MonAnimRecStrc) == 12) ? 1 : -1];

int __stdcall MONSTERS_IsSandLeaper(D2UnitStrc* pMonster, int bAlwaysReturnFalse); // 0x0063E8D0

static D2MonAnimRecStrc* MONSTER_GetAnimRecord(D2UnitStrc* pUnit); // 0x004AF400

static void MONSTER_HandleSkillEvent(D2UnitStrc* pUnit); // 0x004AF2E0

static void MONSTER_ReplaySequence(D2UnitStrc* pUnit); // 0x004AFB60

static int MONSTER_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord); // 0x004AFBC0

static void MONSTER_CreateDeathMissiles(D2UnitStrc* pUnit); // 0x004AFC10

static inline void MONSTER_SetNpcMenuState(int nState); // 0x004B17D0

static inline void MONSTER_SetNpcMenuUnit(D2UnitStrc* pUnit); // 0x004B17E0

static inline void MONSTER_SetNpcMenuValue(unsigned short wValue); // 0x004B17F0

static inline bool MONSTER_IsStringUnused(unsigned short wString); // 0x004B1800


struct D2RoomStrc;

struct D2DifficultyLevelsTxt;

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall MONSTER_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags); // 0x004AE0A0

void __fastcall MONSTER_SetMonsterLight(D2UnitStrc* pUnit); // 0x004AE210

void __fastcall PLAYERLIST_InitGfxData(D2UnitStrc* pUnit); // 0x004DC510

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame); // 0x00626D40

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

static void MONSTER_HandleMonsterEvent(D2UnitStrc* pUnit, int nEvent); // 0x004AE4F0

extern const char gszMonsterFile_006DA5C8[]; // 0x006DA5C8

void __stdcall MONSTERS_ApplyClassicScaling(D2UnitStrc*, int, unsigned char); // 0x0063EEF0

void __stdcall PATH_AllocDynamicPath(void*, D2RoomStrc*, int, int, D2UnitStrc*, int); // 0x00649D00

int __stdcall MONSTERS_IsDead(D2UnitStrc*); // 0x0063EA40

void __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc*, int); // 0x00649560

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc*, int); // 0x00648C30

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int); // 0x00611D30

void __stdcall SKILLS_SetSkillMode(D2SkillStrc*, int); // 0x00644340

void __stdcall sub_0063EBC0(D2UnitStrc*, int); // 0x0063EBC0

int __fastcall sub_0046C140_TestMonModeFlag(int, int); // 0x0046C140

int __fastcall MONSTER_CheckMonsterFacing(D2UnitStrc*, D2UnitStrc*, int, int); // 0x004AE7B0

int __fastcall GFXUTIL_ForEachUnitInAdjacentRooms(D2UnitStrc*, int, int, int (__fastcall*)(D2UnitStrc*,D2UnitStrc*,int,int)); // 0x0046C570

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

void __fastcall MONSTER_UpdateMonsterClient(D2UnitStrc* pUnit); // 0x004B13A0


extern "C" { Unicode gwszNameSeparator[1]; }                                                                // 0x007C0C58

int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit);                                             // 0x004AE380

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0

extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800

struct D2SeqModeStrc;

struct D2SeqModeStrc
{
    int unk0x00;
    int nMode;
};

void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pCommand); // 0x004AFF60

void __stdcall UNITS_StopSequence(D2UnitStrc* pUnit); // 0x00623E00

enum { CASE_BOUND = 0x100 };

static void MONSTER_HandleAttackEvent(D2UnitStrc* pUnit); // 0x004AF6A0

int __fastcall UNITS_CanSwitchAI(int nMonsterId); // 0x00623470

int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wFlag); // 0x004AC7E0

extern D2MonCmdRecordStrc gaMonCmdRecords[];                                                        // 0x006DA4D8

int __cdecl GAME_GetLeftClickState();                                                                                 // 0x0044BF00

int __cdecl GAME_GetRightClickState();                                                                                 // 0x0044BF10

void __cdecl GAME_ResetMouseState();                                                                                // 0x0044DA40

void __fastcall AUTOMAP_SetUnitFlag(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x00457460

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit);                                                             // 0x00463860

void __fastcall CUNIT_SetTargetByGUID(D2UnitStrc* pUnit, int nUnitType, unsigned int nUnitId); // 0x004643F0

void __fastcall CUNIT_UpdateAttackableFlag(D2UnitStrc* pUnit);                                       // 0x004647D0

void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit);                                                // 0x00464810

void __fastcall CUNIT_SetDrawDelay(D2UnitStrc* pUnit);                                               // 0x00464C90

void __fastcall CUNIT_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg);                // 0x00464E50

void __fastcall CUNIT_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg);                        // 0x00465BF0

void __cdecl SELECT_ClearSelection();                                                                                // 0x00466FE0

D2UnitStrc* __cdecl SELECT_GetSelectedUnit();                                                             // 0x00467A10

void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

void __fastcall GFX_RemoveOverlays(D2UnitStrc* pUnit);                                             // 0x0046F170

int __fastcall sub_004804A0_SetPathTargetPos(D2UnitStrc* pUnit, int nX, int nY);                           // 0x004804A0

void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nMode, int nTargetX, int nTargetY); // 0x004804E0

int __fastcall UNITMODE_SetPathTargetUnit(D2UnitStrc* pUnit, int nUnitType, int nUnitGUID);            // 0x00480780

void __fastcall UNITMODE_SetModeOverlay(D2UnitStrc* pUnit, int nMode);                                  // 0x00480D20

void __fastcall UNITMODE_SetUnitModeNoOverlay(D2UnitStrc* pUnit, int nMode);                            // 0x00480EC0

void __fastcall sub_004AC840(D2UnitStrc* pUnit, int nFlag);                                                 // 0x004AC840

void __fastcall MONSTER_RunUModCommandCallbacks(D2UnitStrc* pUnit);                                                            // 0x004ADE40

void __fastcall MONSTER_RunUModUpdateCallbacks(D2UnitStrc* pUnit);                                                            // 0x004ADE50

void __fastcall MONSTER_RunUModHitCallbacks(D2UnitStrc* pUnit);                                                            // 0x004ADE70

void __fastcall MONSTER_SpawnBloodMissiles(D2UnitStrc* pUnit, int nArg1, int nArg2);                   // 0x004AF890

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);          // 0x004B9A00

D2UnitStrc* __fastcall AUTOMAP_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4); // 0x004C5420

void __fastcall SKILLS_StartSkillOnUnit(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand);              // 0x004C6EB0

void __fastcall SKILLS_StartSkillAtPos(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand);                                // 0x004C6F40

int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit);                                          // 0x004DA0F0

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill);                              // 0x00620210

void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit);                                       // 0x006272E0

int __stdcall STATES_CheckStateMaskShatterOnUnit(D2UnitStrc* pUnit);                                       // 0x0063A6F0

int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                          // 0x00643860

void __stdcall PATH_ClearPathingFlagAndPoints(D2DynamicPathStrc* pDynamicPath);                                // 0x00648730

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType);                                           // 0x00648CF0

void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath);                                   // 0x00648DC0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70

void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                         // 0x00649970

void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int bForGameLogic);                             // 0x00649F70

void __stdcall PATH_AddCollisionFootprintForOptionalUnit(D2UnitStrc* pUnit);                                // 0x0064A0E0

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath);                                   // 0x00650590

static void MONSTER_RefreshMonsterMode(D2UnitStrc* pUnit);                                             // 0x004AE1D0

static void MONSTER_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode);                              // 0x004AFCE0

static void MONSTER_UpdateFrame(D2UnitStrc* pUnit); // 0x004AF4C0

static void MONSTER_HandleAttackEvent(D2UnitStrc* pUnit);

static void MONSTER_CastRandomCurse(D2UnitStrc* pUnit); // 0x004AE400

int gpEventUnit; // 0x007C0C5C

int gdwGlobal_007C0E5C; // 0x007C0E5C

void* __cdecl sub_004E03B0(); // 0x004E03B0

void* __cdecl sub_004E03E0(); // 0x004E03E0

void* __cdecl sub_004E0410(); // 0x004E0410

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline int sub_n5b_Distance(int nDelta);
static inline int sub_n5b_IsTypeFlag1(D2UnitStrc* pUnit);
static inline D2MonStatsTxt* sub_n5b_GetMonStatsTxtRecord(int nMonsterId);
static inline D2MonStats2Txt* sub_n5b_GetMonStats2TxtRecord(int nMonsterId);
static __forceinline void sub_b1_WalkTo(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand, int nMode);


static D2MonsterDataStrc* CLIENT_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

#pragma pack(push, 1)

struct D2ClientPacket7Strc
{
    unsigned char nHeader;
    int dwUnitId;
    unsigned short f_5;
};

#pragma pack(pop)

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

void __fastcall MONSTER_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId); // 0x004ADEA0

static inline D2MonStatsTxt* CLIENT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004AE0A0
void __fastcall MONSTER_SetClientFlags(D2UnitStrc* pUnit, unsigned short wFlags)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nClientFlags = wFlags;
            pMonsterData->pMonstatsTxt = CLIENT_GetMonStatsTxtRecord(pUnit->dwClassId);
        }
    }
}

// 0x004AE0E0
void __fastcall MONSTER_FreeMonsterName(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->wszMonName)
        {
// build: symbol ?gszMonsterSourceFile@* 0x006DA5C8
            FOG_Free(pMonsterData->wszMonName, gszMonsterSourceFile, 0x66, 0);
            pMonsterData->wszMonName = 0;
        }
    }
}

// 0x004AE110
extern "C" __declspec(dllexport) unsigned int* __fastcall MONSTER_GetMonInteractPtr(D2UnitStrc* pUnit) {
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData) {
        return 0;
    }
    return (unsigned int*)&pMonsterData->pMonInteract;
}

static inline D2MonsterDataStrc* CLIENT_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x004AE130
int __fastcall MONSTER_GetOwnerGUID(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return -1;
    }

    return pMonsterData->nOwnerGUID;
}

// 0x004AE150
extern "C" __declspec(dllexport) void __fastcall MONSTER_SetOwnerGUID(D2UnitStrc* pUnit, int nValue) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        pUnit->pMonsterData->nOwnerGUID = nValue;
    }
}

// 0x004AE170
extern "C" __declspec(dllexport) int* __fastcall MONSTER_GetAiValuePtr(D2UnitStrc* pUnit) {
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData) {
        return 0;
    }
    return &pMonsterData->nAiValue;
}

// 0x004AE190
void __fastcall MONSTER_SetMinionSpawnClassId(D2UnitStrc* pUnit, int nValue)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nMinionSpawnClassId = nValue;
    }
}

// 0x004AE1B0
int __fastcall MONSTER_GetMinionSpawnClassId(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterDataInline(pUnit);
    if (!pMonsterData)
    {
        return -1;
    }

    return pMonsterData->nMinionSpawnClassId;
}

// 0x004AE1D0
static __declspec(noinline) void MONSTER_RefreshMonsterMode(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const unsigned int nMode = pUnit->dwAnimMode;
        if (nMode < 0x10 && nMode && nMode != 0xC)
        {
            sub_00465BF0(pUnit, 0);
            UNITMODE_RecacheUnitPath(pUnit);
            UNITMODE_SetUnitMode(pUnit, 1);
        }
    }
}

// 0x004AE210
void __fastcall MONSTER_SetMonsterLight(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    unsigned char nLight = MONSTERS_GetMaximalLightRadius(pUnit);
    if (nLight < pMonStats2TxtRecord->nLightRadius)
    {
        nLight = pMonStats2TxtRecord->nLightRadius;
    }

    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_DENOFEVIL && INV_GetTableByte(0, 1) && !sub_00451F30_TestUnitFlag(pUnit, 0x200000)
        && pMonStatsTxtRecord->nAlign != 1 && pMonStatsTxtRecord->nAlign != 2)
    {
        nLight = 3;
    }
    else if (!nLight)
    {
        return;
    }

    D2GfxLightStrc* pLight = DLIGHTMAP_MakeLightEntry(pUnit, 0, nLight, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    if (pUnit->pLight)
    {
        CUNIT_FreeLight(pUnit);
    }

    pUnit->pLight = pLight;
    sub_00464CF0(pUnit, nLight);
}

// 0x004AE320
int __fastcall MONSTER_IsChampionMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x04);
    return 0;
}

// 0x004AE340
int __fastcall MONSTER_IsGhostlyMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x40);
    return 0;
}

// 0x004AE360
int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x08);
    return 0;
}

// 0x004AE380
int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x10);
    return 0;
}

// 0x004AE3A0
int __fastcall MONSTER_IsSuperUniqueMonster(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return sub_004AC7E0_CheckMonTypeFlag(pUnit, 0x02);
    return 0;
}

// 0x004AE3C0
void __fastcall MONSTER_OwnerMissileHit(D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
    if (pOwner)
    {
        D2_ASSERT(pOwner->dwUnitType == UNIT_MISSILE, 353);
// build: symbol ?MISSILE_CltMissileHit@* 0x004D2D70
        MISSILE_CltMissileHit(pOwner, 0, 0);
    }
}

static inline unsigned int sub_H12_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* sub_H12_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int sub_H12_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static inline int sub_H12_UnitX(D2UnitStrc* pUnit)
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

static inline int sub_H12_UnitY(D2UnitStrc* pUnit)
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

// 0x004AE400
static void MONSTER_CastRandomCurse(D2UnitStrc* pUnit)
{
    const int nIndex = sub_H12_SeedStep(&pUnit->pSeed) % 5;
    D2_ASSERT(nIndex < 5, 0x174);

// build: symbol ?gaRandomCurseSkills@* 0x006DA5DC
    const int nSkill = gaRandomCurseSkills[nIndex];
    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, nSkill, sub_H12_UnitX(pUnit), sub_H12_UnitY(pUnit), 0, 1);
    if (pMissile)
    {
        UNITS_StoreOwner(pMissile, pUnit);
        UNITS_StoreOwner(pUnit, pMissile);
        PARTICLE_ResetGfxMotion(pMissile);
        sub_004DA620(pMissile, 1);
        pMissile->dwFlagEx |= 0x40000;
    }
}

static inline unsigned __int64 sub_I07_SeedRoll(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x004AE4F0
static void MONSTER_HandleMonsterEvent(D2UnitStrc* pUnit, int nEvent)
{
    switch (nEvent)
    {
    case 0x14B:
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer)
        {
            UNITS_SetTargetUnitForDynamicUnit(pUnit, pPlayer);
            sub_00465BF0(pUnit, 0);
        }
        break;
    }
    case 0x9D:
    case 0x9E:
    case 0x13F:
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        break;
    case 0x96:
        gpEventUnit_007C0C5C = pUnit;
        break;
    case 0x158:
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        D2DirectionArgStrc tDirection;
        tDirection.nDirection = sub_I07_SeedRoll(&pPlayer->pSeed) & 0x3F;
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 1);
        sub_006488A0_SetDirection(pPath, tDirection);
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
        break;
    }
    case 0x1F1:
    case 0x1F2:
    case 0x1F3:
    case 0x1F4:
        MONSTER_CastRandomCurse(pUnit);
        break;
    case 0x19D:
    {
        D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, 0x188, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        if (pMissile)
        {
            UNITS_StoreOwner(pMissile, pUnit);
        }
        break;
    }
    case 0x23A:
        MISSILE_SubmitMissileRequest(pUnit, 0x265, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        break;
    }
}

static D2MonStatsTxt* FACING_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int FACING_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = FACING_GetMonStatsTxtRecordInline(nClassId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nClassId;
}

// 0x004AE7B0
int __fastcall MONSTER_CheckMonsterFacing(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nArg3, int nArg4)
{
    const int nUnitType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return 0;
    }

    const int nBaseId = FACING_GetBaseIdInline(pTarget->dwClassId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != MONSTER_VILEMOTHER1)
    {
        return 0;
    }

    if (DRLG_UnitEdgeDistance(pUnit, pTarget) > 1)
    {
        return 0;
    }

    const unsigned char nDirection = PATH_GetDirection(pTarget->pDynamicPath);
    unsigned char aDirections[8] = { 6, 7, 0, 1, 2, 3, 4, 5 };
    const unsigned char nNewDirection = aDirections[INVENTORY_GetEightWayDirection(nDirection)];
    int nOffsetX;
    int nOffsetY;
    INVENTORY_GetDirectionDelta(nNewDirection, &nOffsetX, &nOffsetY);
    const int nX = CLIENTS_GetUnitX(pTarget) + 3 * nOffsetX;
    const int nY = CLIENTS_GetUnitY(pTarget) + 3 * nOffsetY;
    if (nX == CLIENTS_GetUnitX(pUnit) && nY == CLIENTS_GetUnitY(pUnit))
    {
        return nDirection;
    }

    return 0;
}

static inline D2MonStatsTxt* sub_F4B0_GetMonStatsTxt(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nId];
    }

    return 0;
}

static inline D2MonStats2Txt* sub_F4B0_GetMonStats2TxtFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = sub_F4B0_GetMonStatsTxt(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        const int nId = pMonStatsTxtRecord->wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }

    return 0;
}

static inline unsigned int MONSTERS_GetFlagInline(D2UnitStrc* pUnit, int nFlag)
{
    D2MonStatsTxt* pRecord=sub_F4B0_GetMonStatsTxt(pUnit->dwClassId);
    if (pRecord) return pRecord->nMonStatsFlags[nFlag>>3]&gdwBitMasks[nFlag&7];
    return 0;
}

static inline int MONSTERS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pRecord=sub_F4B0_GetMonStatsTxt(nClassId);
    if (!pRecord) return nClassId;
    return pRecord->nBaseId;
}

static __forceinline int MONSTERS_GetUnitBaseIdInline(D2UnitStrc* pUnit)
{
    if(pUnit->dwUnitType==UNIT_MONSTER)
    {
        int nId=MONSTERS_GetBaseIdInline(pUnit->dwClassId);
        if(nId>=0 && nId<sgptDataTables->nMonStatsTxtRecordCount) return nId;
    }
    return -1;
}

// 0x004AE8D0
void __fastcall MONSTER_InitMonster(D2UnitStrc* pUnit, D2RoomStrc* pRoom, int nX, int nY, int nClassId, int nMode)
{
    D2MonStatsTxt* pMonStats = sub_F4B0_GetMonStatsTxt(nClassId);
    if (!pMonStats) return;
    D2MonStats2Txt* pMonStats2 = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (!pMonStats2) return;
    int nDifficulty = GAME_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 0x1F0);
    STATLIST_AllocStatListEx(pUnit,0,0,0);
    STATLIST_SetUnitStat(pUnit,STAT_LEVEL,pMonStats->nLevel[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_ATTACKRATE,100,0);
    STATLIST_SetUnitStat(pUnit,STAT_VELOCITYPERCENT,75,0);
    STATLIST_SetUnitStat(pUnit,STAT_OTHER_ANIMRATE,100,0);
    STATLIST_SetUnitStat(pUnit,STAT_DAMAGERESIST,pMonStats->wResDm[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_MAGICRESIST,pMonStats->wResMa[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_FIRERESIST,pMonStats->wResFi[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_LIGHTRESIST,pMonStats->wResLi[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_COLDRESIST,pMonStats->wResCo[nDifficulty],0);
    STATLIST_SetUnitStat(pUnit,STAT_POISONRESIST,pMonStats->wResPo[nDifficulty],0);
    MONSTERS_ApplyClassicScaling(pUnit,GAME_IsExpansion(),GAME_GetDifficulty());
    STATLIST_SetUnitStat(pUnit,STAT_MAXHP,0x6400,0);
    STATLIST_SetUnitStat(pUnit,STAT_HITPOINTS,0x6400,0);
    PATH_AllocDynamicPath(0,pRoom,nX,nY,pUnit,1);
    D2DynamicPathStrc* pPath=pUnit->pDynamicPath;
    PATH_SetVelocity(pPath,pMonStats->nVelocity<<8,gszMonsterFile_006DA5C8,0x208);
    if (!pUnit->pInventory && ((pMonStats->nMonStatsFlags[1]&gdwBitMasks[1]) || nClassId==0x123 || nClassId==0x165 || nClassId==0x1A1 || nClassId==0x1A2))
        pUnit->pInventory=INVENTORY_AllocInventory(0,pUnit);
    UNITS_ChangeAnimMode(pUnit,nMode);
    if (MONSTERS_IsDead(pUnit) && !(pMonStats2->nFlags[2]&gdwBitMasks[3]))
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit,1);
        sub_00649190_SetPathMode(pUnit,5);
        PATH_SetFootprintCollisionMask(pUnit->pDynamicPath,0x8000);
    }
    pUnit->nSeqCurrentFramePrecise=ITEMS_RollLimitedRandomNumber(&pUnit->pSeed,pUnit->dwFrameCountPrecise);
    if(pMonStats2->nFlags[0]&gdwBitMasks[3]) pUnit->dwFlags|=2; else pUnit->dwFlags&=~2;
    if(!(pMonStats2->nFlags[1]&gdwBitMasks[6])) pUnit->dwFlags|=0x20; else pUnit->dwFlags&=~0x20;
    pUnit->dwFlags|=8;
    if(pMonStats2->nFlags[1]&gdwBitMasks[1]) pUnit->dwFlags|=4; else pUnit->dwFlags&=~4;
    MONSTER_SetClientFlags(pUnit,0);
    MONSTER_HandleMonsterEvent(pUnit,nClassId);
    MONSTER_SetMonsterLight(pUnit);
    pUnit->pSkills=SKILLS_AllocSkillList(0);
    sub_004AD020_RefreshMonster(pUnit);
    D2DifficultyLevelsTxt* pDiff=DATATBLS_GetDifficultyLevelsTxtRecord(nDifficulty);
    int nSkillBonus=pDiff->dwMonsterSkillBonus;
    for (int i=0;i<8;++i)
    {
        if(pMonStats->nSkill[i]>=0 && pMonStats->nSkLvl[i]>0)
        {
            SKILLS_AssignSkill(pUnit,pMonStats->nSkill[i],pMonStats->nSkLvl[i]+nSkillBonus,1,gszMonsterFile_006DA5C8,0x23F);
            SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit,pMonStats->nSkill[i]),(char)pMonStats->nSkillMode[i]);
        }
    }
    sub_0063EBC0(pUnit,nSkillBonus);
    if(MONSTERS_GetFlagInline(pUnit,8)) return;
    D2DirectionArgStrc tDirection; tDirection.nDirection=0;
    int nBaseId=MONSTERS_GetUnitBaseIdInline(pUnit);
    if(sub_0046C140_TestMonModeFlag(pUnit->dwClassId,2)) tDirection.nDirection=sub_I07_SeedRoll(&pUnit->pSeed)&0x3F;
    if(nBaseId==MONSTER_MUMMY1) tDirection.nDirection=7;
    else if(nBaseId==MONSTER_VILECHILD1) tDirection.nDirection=GFXUTIL_ForEachUnitInAdjacentRooms(pUnit,0,0,MONSTER_CheckMonsterFacing);
    if(nClassId==0x15F) tDirection.nDirection=0x18;
    else if(nClassId==0x160) tDirection.nDirection=0;
    else if(nClassId==0x161) tDirection.nDirection=0x28;
    else if(nClassId==0x165 || nClassId==0x158) tDirection.nDirection=0;
    sub_006488A0_SetDirection(pPath,tDirection);
}

// 0x004AED30
void __fastcall MONSTER_FreeClientUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    GFX_FreeGfxData(pUnit);
    CUNIT_RemoveInventoryUnits(pUnit, 1);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;

    if (gpAct)
    {
        D2Common_10228(pUnit);
        UNITROOM_RemoveUnitFromRoom(pUnit);
        CUNIT_FreeLight(pUnit);
    }

    PATH_FreeDynamicPath(0, pUnit->pDynamicPath);
    pUnit->pDynamicPath = 0;

    D2GfxLightStrc* pResource = D2Common_10958(pUnit, 0);
    if (pResource)
    {
        DLIGHTMAP_ReleaseLight(pResource);
    }

    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->wszMonName)
        {
            FOG_Free(pMonsterData->wszMonName, gszMonsterSourceFile, 102, 0);
            pMonsterData->wszMonName = 0;
        }
    }
}

// 0x004AEDD0
void __fastcall MONSTER_ChangeMonsterClass(D2UnitStrc* pUnit, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = sub_F4B0_GetMonStatsTxt(nClassId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = sub_F4B0_GetMonStats2TxtFromMonsterId(nClassId);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    GFX_FreeGfxData(pUnit);
    CUNIT_RemoveInventoryUnits(pUnit, 0);
    INVENTORY_FreeInventory(pUnit->pInventory);
    pUnit->pInventory = 0;
    CUNIT_FreeLight(pUnit);
    D2GfxLightStrc* pLight = D2Common_10958(pUnit, 0);
    if (pLight)
    {
        DLIGHTMAP_ReleaseLight(pLight);
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->pAiParam)
        {
            FOG_Free(pMonsterData->pAiParam, ".\\UNIT\\Monster.cpp", 0x66, 0);
            pMonsterData->pAiParam = 0;
        }
    }

    pUnit->nPaletteIndex = 0;
    pUnit->dwClassId = nClassId;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return;
    }

    PATH_SetVelocity(pPath, pMonStatsTxtRecord->nVelocity << 8, ".\\UNIT\\Monster.cpp", 0x2B8);
    sub_00649FF0(pUnit, 0);
    if ((pMonStatsTxtRecord->nMonStatsFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !pUnit->pInventory)
    {
        pUnit->pInventory = INVENTORY_AllocInventory(0, pUnit);
    }

    STATLIST_AllocStatListEx(pUnit, 0, 0, 0);
    STATLIST_SetUnitStat(pUnit, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_OTHER_ANIMRATE, 100, 0);
    const int nDifficulty = GAME_GetDifficulty();
    STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, pMonStatsTxtRecord->wResDm[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAGICRESIST, pMonStatsTxtRecord->wResMa[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, pMonStatsTxtRecord->wResFi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, pMonStatsTxtRecord->wResLi[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, pMonStatsTxtRecord->wResCo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_POISONRESIST, pMonStatsTxtRecord->wResPo[nDifficulty], 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, 0x8000, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0x8000, 0);
    UNITS_ChangeAnimMode(pUnit, 1);
    pUnit->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pUnit->dwFrameCountPrecise);

    if (pMonStats2TxtRecord->nFlags[3 >> 3] & gdwBitMasks[3 & 7])
    {
        pUnit->dwFlags |= 2;
    }
    else
    {
        pUnit->dwFlags &= ~2;
    }

    pUnit->dwFlagEx &= ~0x40000;
    if (!(pMonStats2TxtRecord->nFlags[14 >> 3] & gdwBitMasks[14 & 7]))
    {
        pUnit->dwFlags |= 0x20;
    }
    else
    {
        pUnit->dwFlags &= ~0x20;
    }

    pUnit->dwFlags |= 8;
    if (pMonStats2TxtRecord->nFlags[9 >> 3] & gdwBitMasks[9 & 7])
    {
        pUnit->dwFlags |= 4;
    }
    else
    {
        pUnit->dwFlags &= ~4;
    }

    MONSTER_SetClientFlags(pUnit, 0);
    MONSTER_HandleMonsterEvent(pUnit, nClassId);
    MONSTER_SetMonsterLight(pUnit);
    sub_004AD020_RefreshMonster(pUnit);
    pUnit->pSkills = SKILLS_AllocSkillList(0);
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] >= 0)
        {
            SKILLS_AssignSkill(pUnit, pMonStatsTxtRecord->nSkill[i], pMonStatsTxtRecord->nSkLvl[i], 0, ".\\UNIT\\Monster.cpp", 0x2EA);
        }
    }

    if (!(pMonStatsTxtRecord->nMonStatsFlags[8 >> 3] & gdwBitMasks[8 & 7]))
    {
        PATH_SetDirection(pPath, (unsigned int)sub_I07_SeedRoll(&pUnit->pSeed) & 0x3F);
    }

    PLAYERLIST_InitGfxData(pUnit);
    int nMode = 2;
    if (pMonStatsTxtRecord->nMode4D < 8)
    {
        nMode = pMonStatsTxtRecord->nMode4D + 2;
    }

    const int nId = (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount) ? pUnit->dwClassId : -1;
    switch (nId)
    {
    case 0x9C:
    case 0xD3:
    case 0xF2:
    case 0xF3:
        switch (GAME_GetDifficulty())
        {
        case 0:
            nMode = 2;
            break;

        case 1:
            nMode = 3;
            break;

        case 2:
            nMode = 4;
            break;
        }
        break;

    case 0x14D:
        nMode = 5;
        break;

    case 0x20F:
        GFX_AddUnitOverlay(pUnit, 0xE3, 5, 0, 0, 0, 0, 0);
        break;
    }

    if (nMode >= 8)
    {
        nMode = 2;
    }

    sub_00463E20_SetUnitFlagA(pUnit, nMode);
    sub_00463E80_SetUnitFlagB(pUnit, nMode);
}

static __forceinline D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline int GetBaseId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }
    return pMonStatsTxtRecord->nBaseId;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004AF1B0
void __stdcall MONSTER_SpawnQuillRatMissiles(D2UnitStrc* pUnit, int nMissile, int nX, int nY)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != 1)
    {
        return;
    }

    const int nBaseId = GetBaseId(pUnit->dwClassId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != MONSTER_QUILLRAT1)
    {
        return;
    }
    else
    {

        D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return;
        }

        int nOffsetX = 5;
        int nOffsetY = 5;
        D2SeedStrc tSeed;
        SEED_InitSeed(&tSeed);
        SEED_InitLowSeed(&tSeed, 'SEIS');
        tSeed.nHighSeed = pUnit->dwUnitId;

        for (int nCount = pMonStatsTxtRecord->wAiParam[2][GAME_GetDifficulty()]; nCount > 0; --nCount)
        {
            if (SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetX = -nOffsetX;
            }

            if (SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetY = -nOffsetY;
            }

            MISSILE_SubmitOwnerRequest(pUnit, nMissile, nX + nOffsetX, nY + nOffsetY, 0, 1);
        }
    }
}

// 0x004AF2E0
static void MONSTER_HandleSkillEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    const int nMissile = D2Common_11050(pUnit, 1);
    if (nMissile == -1)
    {
        return;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x20;
    switch (nMissile)
    {
    case MISSILE_MUMMY1:
    case MISSILE_MUMMY2:
    case MISSILE_MUMMY3:
    case MISSILE_MUMMY4:
        tMissile.dwFlags = 0x34;
        tMissile.nVelocity = 2;
        break;
    }
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nSkillLevel = 1;

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!pPath)
        {
            return;
        }
        tMissile.nTargetX = D2COMMON_10175_PathGetFirstPointX(pPath);
        tMissile.nTargetY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        tMissile.nTargetX = CLIENTS_GetUnitX(pTarget);
        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
    }

    if (nMissile == MISSILE_PANTHERPOTORANGE || nMissile == MISSILE_PANTHERPOTGREEN)
    {
        if (pTarget)
        {
            MISSILE_SubmitOffsetRequest(pUnit, nMissile, 0, 0, 0, 0, 0, 1, 0);
        }
    }
    else if (nMissile == MISSILE_CATAPULTCHARGEDBALL_ON)
    {
        sub_004AE3C0(pUnit);
        MONSTER_CastRandomCurse(pUnit);
    }
    else
    {
        MISSILE_CreateClientMissile(&tMissile);
    }

    MONSTER_SpawnQuillRatMissiles(pUnit, nMissile, tMissile.nTargetX, tMissile.nTargetY);
}

void __fastcall sub_M103_Emit_004B1000(D2UnitStrc* pItem, int nArg)
{
    if (MONSTER_IsStringUnused((unsigned short)nArg))
    {
        sub_M103_EmitSink(1);
    }
    MONSTER_SetNpcMenuState(nArg);
    MONSTER_SetNpcMenuUnit(pItem);
    MONSTER_SetNpcMenuValue((unsigned short)nArg);
}

static inline unsigned int sub_J20_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* sub_J20_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline unsigned int sub_J20_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }

    return 0;
}

static inline int sub_J20_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static inline int sub_J20_UnitX(D2UnitStrc* pUnit)
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

static inline int sub_J20_UnitY(D2UnitStrc* pUnit)
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

// 0x004AF400
static D2MonAnimRecStrc* MONSTER_GetAnimRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return 0;
    }

    if (pUnit->dwClassId == 0xF3 && nMode == 0xB || pUnit->dwClassId == 0x14D && nMode == 0xB)
    {
        return &gtDiabloAnimRecord;
    }

    if (pUnit->dwClassId == 0x21F && nMode == 0xA || pUnit->dwClassId == 0x220 && nMode == 0xA || pUnit->dwClassId == 0x23A && nMode == 0xA)
    {
        return &gtBaalAnimRecord;
    }

    D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
    if (!pMonStats2Txt)
    {
        return 0;
    }

    if (pMonStats2Txt->nModeEnabledWhenMovingFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
    {
        return &gaMonAnimRecordsMoving[nMode];
    }

    if (!nMode && MONSTERS_IsSandLeaper(pUnit, nMode))
    {
        return &gaMonAnimRecordsMoving[0];
    }

    return &gaMonAnimRecords[pUnit->dwAnimMode];
}

// 0x004AF4C0
static void MONSTER_UpdateFrame(D2UnitStrc* pUnit)
{
    D2MonStats2Txt* pMonStats2Txt;

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = sub_J20_GetSkillsTxt(SKILLS_GetSkillIdFromSkill(pSkill, gszMonsterSourceFile, 0x3B5));
    if (!pSkillsTxt)
    {
        return;
    }

    int nFlags = SKILLS_GetFlags(pSkill);
    int bCheckFrame = 1;
    if ((nFlags & 1) && sub_004807C0(pUnit))
    {
        if (pSkillsTxt->wSrvDoFunc != 0x43)
        {
            nFlags |= 2;
            SKILLS_SetFlags(pSkill, nFlags);
        }
        SKILLS_DoUsedSkill(pUnit);
        bCheckFrame = 0;
    }

    const int nActionFrame = pUnit->nActionFrame;
    if (nActionFrame != 4)
    {
        if (!bCheckFrame || sub_00451F30_TestUnitFlag(pUnit, 0x40) || nActionFrame != 1 && nActionFrame != 2 && nActionFrame != 3)
        {
            switch (pSkillsTxt->wSrvDoFunc)
            {
            case 0x5F:
            {
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
                if (!pMonStats2Txt)
                {
                    return;
                }

                SKILLS_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise >> 8) > pMonStats2Txt->nInfernoAnim)
                {
                    pUnit->nSeqCurrentFramePrecise = pMonStats2Txt->nInfernoRollback << 8;
                }
                return;
            }

            case 0x7E:
                SKILLS_DoUsedSkill(pUnit);
                if ((pUnit->nSeqCurrentFramePrecise & ~0xFF) >= 0xC00)
                {
                    pUnit->nSeqCurrentFramePrecise = 0x800;
                }
                return;

            case 0x98:
            {
                pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
                if (pMonStats2Txt && STATES_CheckState(pUnit, STATE_INFERNO))
                {
                    const int nFrame = pUnit->nSeqCurrentFramePrecise >> 8;
                    if (nFrame >= pMonStats2Txt->nInfernoAnim)
                    {
                        SKILLS_DoUsedSkill(pUnit);
                    }

                    if (nFrame >= pMonStats2Txt->nInfernoRollback)
                    {
                        pUnit->nSeqCurrentFramePrecise = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 4) + pMonStats2Txt->nInfernoRollback - 4) << 8;
                    }
                }
                return;
            }
            }
            return;
        }
    }

    SKILLS_DoUsedSkill(pUnit);
}

// 0x004AF6A0
static void MONSTER_HandleAttackEvent(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    const unsigned int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    const int nId = sub_00463860_GetMonsterId(pUnit);
    const int nMonsterId = (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) ? nId : -1;

    if (nMode == 0xD && nMonsterId != MONSTER_SANDLEAPER1)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath)
        {
            sub_00650590(pPath);
            PATH_SetPathingFlag(pPath, 0);
            sub_00648DC0(pPath);
            UNITMODE_SetUnitMode(pUnit, 3);
        }
        return;
    }

    if (CUNIT_GetPathTargetUnit(pUnit))
    {
        sub_00465BF0(pUnit, 0);
    }

    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if (pMonStatsTxt->nSplClientEnd)
    {
        switch (sub_J20_GetAnimMode(pUnit))
        {
        case 8:
            if (nMonsterId == MONSTER_VULTURE1)
            {
                return;
            }
        case 5:
        case 9:
            if (nMonsterId == MONSTER_TRAPPEDSOUL1 || nMonsterId == MONSTER_TRAPPEDSOUL2)
            {
                UNITMODE_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 10:
            if (nMonsterId == MONSTER_BATDEMON1)
            {
                UNITMODE_SetUnitMode(pUnit, 0xB);
                sub_00624390(pUnit);
                return;
            }
            break;

        case 11:
            if (nMonsterId == MONSTER_BATDEMON1)
            {
                return;
            }
            break;

        case 2:
            if (nMonsterId == MONSTER_ICEGLOBE || nMonsterId == MONSTER_WILLOWISP1)
            {
                return;
            }
            break;

        case 4:
            if (nMonsterId == MONSTER_TRAPPEDSOUL1 || nMonsterId == MONSTER_TRAPPEDSOUL2)
            {
                UNITMODE_SetUnitMode(pUnit, 8);
                sub_00624390(pUnit);
                return;
            }
            if (nMonsterId == MONSTER_CATAPULT1)
            {
                sub_004AE3C0(pUnit);
                MONSTER_CastRandomCurse(pUnit);
            }
            break;

        case 14:
            if (nMonsterId == MONSTER_FROGDEMON1)
            {
                return;
            }
            break;

        case 12:
            if (nMonsterId == MONSTER_MAGGOTQUEEN1)
            {
                return;
            }
            break;
        }
    }

    if (sub_J20_HasUnitFlagBit(pUnit))
    {
        UNITMODE_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
        return;
    }

    if (!sub_00463720_TestUnitFlagEx(pUnit, 0x2000))
    {
        UNITMODE_SetUnitMode(pUnit, 1);
        sub_00624390(pUnit);
    }
}

static inline unsigned int sub_M165_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int sub_M165_RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return sub_M165_SeedStep(pSeed) % nMax;
    }

    return sub_M165_SeedStep(pSeed) & (nMax - 1);
}

static inline D2MonStats2Txt* sub_M165_GetMonStats2Txt(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            const int nMonStatsEx = sgptDataTables->pMonStatsTxt[pUnit->dwClassId].wMonStatsEx;
            if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
            {
                return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
            }
        }
    }

    return 0;
}

static inline int sub_M165_UnitX(D2UnitStrc* pUnit)
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

static inline int sub_M165_UnitY(D2UnitStrc* pUnit)
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

// 0x004AF890
void __fastcall MONSTER_SpawnBloodMissiles(D2UnitStrc* pUnit, int nDefaultCount, int bRandomChance)
{
    if (bRandomChance && sub_M165_SeedStep(&pUnit->pSeed) % 25)
    {
        return;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_GETHIT && sub_M165_SeedStep(&pUnit->pSeed) % 3)
    {
        return;
    }

    int nCount = nDefaultCount;
    const int nExtraBlood = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_EXTRABLOOD, 0);
    if (nExtraBlood)
    {
        nCount = nExtraBlood;
    }

    D2MonStats2Txt* pMonStats2Txt = sub_M165_GetMonStats2Txt(pUnit);
    if (!pMonStats2Txt || pMonStats2Txt->nBleed <= 0)
    {
        return;
    }

    for (int i = 0; i < nCount; ++i)
    {
        int nDirection;
        if (PATH_GetVelocity(pUnit->pDynamicPath))
        {
            const int nUnitDirection = UNITS_GetDirection(pUnit) >> 3;
            nDirection = (nUnitDirection + sub_M165_SeedStep(&pUnit->pSeed) % 7 - 3) & 7;
        }
        else
        {
            nDirection = sub_M165_RollLimited(&pUnit->pSeed, 8);
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        int nDir = nDirection;
        const int nLastDirection = (nDirection - 1) & 7;
        int nX;
        int nY;
        if (nDir == nLastDirection)
        {
            return;
        }

        do
        {
            nX = gaBloodOffsetX[nDir] + sub_M165_UnitX(pUnit);
            nY = gaBloodOffsetY[nDir] + sub_M165_UnitY(pUnit);
            if (!COLLISION_CheckMask(pRoom, nX, nY, 1))
            {
                goto SPAWN_BLOOD;
            }

            nDir = (nDir + 1) & 7;
        }
        while (nDir != nLastDirection);

        return;

SPAWN_BLOOD:
        MISSILE_SubmitOwnerRequest(pUnit, 0x12 + sub_M165_RollLimited(&pUnit->pSeed, 2 * pMonStats2Txt->nBleed), nX, nY, 0, 1);
    }
}

// 0x004AFB60
static void MONSTER_ReplaySequence(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pSequenceRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    const int nCount = DATATBLS_GetSeqFramePointsCount(pUnit) >> 8;
    for (int i = 0; i < nCount; ++i)
    {
        int nMode;
        int nFrame;
        int nDirection;
        int nEvent;
        DATATBLS_ComputeSequenceAnimation(pSequenceRecord, i << 8, i << 8, &nMode, &nFrame, &nDirection, &nEvent);
        pUnit->dwAnimMode = nMode;
        GFX_RefreshUnitGfx(pUnit, 0);
    }
}

// 0x004AFBC0
static int MONSTER_HasMonStatsFlag(D2UnitStrc* pUnit, D2MonCmdRecordStrc* pRecord)
{
    if (!pUnit || !pRecord)
        return 0;

    if (pRecord->bSet)
    {
        const int nIndex = pRecord->nIndex;
        if (nIndex < 0x10)
        {
            D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
            if (pMonStats2Txt)
                return pMonStats2Txt->nModeEnabledWhenMovingFlags[nIndex >> 3] & gdwBitMasks[nIndex & 7];
        }
    }
    return 0;
}

// 0x004AFC10
static void MONSTER_CreateDeathMissiles(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return;

    D2MissileStrc tMissile;
    if (STATES_CheckState(pUnit, STATE_UBERMINION) && !STATES_CheckState(pUnit, STATE_FREEZE))
    {
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2020;
        tMissile.pOwner = pUnit;
        tMissile.pOrigin = pUnit;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = MISSILE_SUICIDEFIREEXPLODE;
        MISSILE_CreateClientMissile(&tMissile);
        tMissile.nMissile = MISSILE_SUICIDECORPSEEXPLODE;
        MISSILE_CreateClientMissile(&tMissile);
        return;
    }

    const int nMissile = (unsigned char)UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId)->nType + 0x10F;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x2020;
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nSkillLevel = 1;
    tMissile.nMissile = nMissile;
    MISSILE_CreateClientMissile(&tMissile);
    tMissile.nMissile = MISSILE_ICEBREAKSMOKE;
    MISSILE_CreateClientMissile(&tMissile);
}

static inline int sub_J10_UnitX(D2UnitStrc* pUnit)
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

static inline int sub_J10_UnitY(D2UnitStrc* pUnit)
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

// 0x004AFCE0
static void MONSTER_UpdateCollisionForMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode == 12)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~14;
        }
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_ResetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 5);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0);
        if (sub_004DA0F0_GetUnitGfxOffsetZ(pUnit))
        {
            return;
        }
        PARTICLE_ResetGfxMotion(pUnit);
        GFXUTIL_ReplaceMotionFlag1With8(pUnit);
        GFXUTIL_SetMotionFlagMask(pUnit, 1);
        GFXUTIL_SetMotionVectorB(pUnit, 0, 0, 2, 1);
        GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 0xA0, 0);
    }
    else if (nMode == 14 || nMode == 10)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 14;
        }
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x1000);
        COLLISION_SetMask(UNITS_GetRoom(pUnit), sub_J10_UnitX(pUnit), sub_J10_UnitY(pUnit), 0x100);
        sub_00649190_SetPathMode(pUnit, 1);
        PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x3C01);
        if (!sub_004DA0F0_GetUnitGfxOffsetZ(pUnit))
        {
            return;
        }
        GFXUTIL_ReplaceMotionFlag1With8(pUnit);
        GFXUTIL_SetMotionFlagMask(pUnit, 0);
        GFXUTIL_SetMotionVectorB(pUnit, 0, 0, -8, 1);
        GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 0, 0);
    }
}

int __fastcall MONSTER_HandleSequenceStop(D2UnitStrc* pUnit, D2SeqModeStrc* pMode); // 0x004B1280

// 0x004AFF60
void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pCommand)
{
    int nMonId;
    D2MonStats2Txt* pMonStats2Txt;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pUnit->dwAnimMode == 0xD)
    {
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_ResetToPreviousType(pPath);
    }

    if (!CUNIT_IsDeadOrDying(pUnit))
    {
        PATH_AddCollisionFootprintForOptionalUnit(pUnit);
    }
    else if (nCommand != 8 && nCommand != 9)
    {
        sub_00649FF0(pUnit, 0);
        MONSTER_SetMonsterLight(pUnit);
        pUnit->dwFlagEx &= ~0x40000;
    }

    int bUpdateVelocity = 0;
    if (nCommand != 0x13 && nCommand != 0x16 && nCommand != 0x15 && pCommand)
    {
        bUpdateVelocity = 1;
        if (pCommand->nPathValue > 0)
        {
            PATH_SetType(pPath, pCommand->nPathValue);
            if (nCommand == 0x14)
            {
                PATH_SetNewDistance(pPath, (unsigned char)pCommand->nPathByte);
                PATH_SetStepNum(pPath, (unsigned char)pCommand->nZero);
            }
        }
        UNITS_SetUsedSkill(pUnit, 0);
        MONSTER_RunUModCommandCallbacks(pUnit);
    }

    if (!sub_n5b_GetMonStatsTxtRecord(pUnit->dwClassId))
        return;

    pMonStats2Txt = sub_n5b_GetMonStats2TxtRecord(pUnit->dwClassId);
    if (!pMonStats2Txt)
        return;

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
    if (nBaseId >= 0 && nBaseId < nMonStatsCount)
        nMonId = nBaseId;
    else
        nMonId = -1;

    int nValue;
    D2MonCmdRecordStrc* pRecord = &gaMonCmdRecords[nCommand];
    switch (nCommand)
    {
    case 1:
    case 0x17:
        D2_ASSERT(pCommand, 0x6E2);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 1);
        if (sub_004AE080(pUnit, 1) || !sub_004804A0_SetPathTargetPos(pUnit, pCommand->nX, pCommand->nY))
        {
            MONSTER_RefreshMonsterMode(pUnit);
            break;
        }

        if (nCommand == 1)
            UNITMODE_SetUnitMode(pUnit, 2);
        else
            UNITMODE_SetUnitMode(pUnit, 0xF);
        break;

    case 0:
    case 0x18:
    {
        D2_ASSERT(pCommand, 0x6F7);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 1);
        nValue = pCommand->nX;
        CUNIT_SetTargetByGUID(pUnit, nValue, pCommand->nY);
        if (sub_004AE080(pUnit, 1) || !UNITMODE_SetPathTargetUnit(pUnit, nValue, pCommand->nY))
        {
            MONSTER_RefreshMonsterMode(pUnit);
            break;
        }

        if (nCommand == 0)
            UNITMODE_SetUnitMode(pUnit, 2);
        else
            UNITMODE_SetUnitMode(pUnit, 0xF);
        break;
    }

    case 5:
    case 0xA:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x1B:
    case 0x1D:
    {
        D2_ASSERT(pCommand, 0x70F);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        nValue = pCommand->nX;
        if (nMonId == MONSTER_ICEGLOBE)
            break;

        CUNIT_SetTargetByGUID(pUnit, nValue, pCommand->nY);
        if (nMonId == MONSTER_FINGERMAGE1 && nCommand == 0xA)
        {
            D2UnitStrc* pTargetUnit = CUNIT_GetPathTargetUnit(pUnit);
            CUNIT_SetOverlayWithSound(pTargetUnit, 0xA9, 0);
        }

        CUNIT_SetPathTargetToTargetUnit(pUnit, 0);
        if (nMonId == MONSTER_VULTURE1)
            MONSTER_UpdateCollisionForMode(pUnit, nCommand);
        else if (nMonId == MONSTER_CHARSI && nCommand == 0xD)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x38);

        if ((!pUnit ? -1 : pUnit->dwClassId) == 0x195 && nCommand == 0xD)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);

        if (pUnit->dwClassId == 0x195 && nCommand == 0xF)
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x30);

        if (nMonId == MONSTER_WARRIV1)
        {
            if (nCommand == 0xD)
                D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0x34);
        }
        else if (nMonId == MONSTER_FARA && nCommand == 0xD)
        {
            D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 4);
        }

        UNITMODE_SetUnitMode(pUnit, pRecord->nIndex);
        if (MONSTER_HasMonStatsFlag(pUnit, pRecord))
            UNITMODE_SetPathTargetUnit(pUnit, nValue, pCommand->nY);
        break;
    }

    case 4:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x11:
    case 0x1A:
    case 0x1C:
        D2_ASSERT(pCommand, 0x741);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        if ((pCommand->nX || pCommand->nY)
            && (pCommand->nX != CLIENTS_GetUnitX(pUnit) || pCommand->nY != CLIENTS_GetUnitY(pUnit)))
        {
            UNITS_UpdateDirectionAndSpeed(pUnit, pCommand->nX, pCommand->nY);
        }

        UNITMODE_SetUnitMode(pUnit, pRecord->nIndex);
        if (MONSTER_HasMonStatsFlag(pUnit, pRecord))
            sub_004804A0_SetPathTargetPos(pUnit, pCommand->nX, pCommand->nY);

        if (nMonId == MONSTER_VULTURE1)
            MONSTER_UpdateCollisionForMode(pUnit, nCommand);
        break;

    case 6:
    {
        if (!pCommand)
            break;

        sub_004AC840(pUnit, pCommand->nZero & 0x80);
        pCommand->nZero &= 0x7F;
        if (pCommand->nZero > 1)
            ++pCommand->nZero;

        int bBlood = 1;
        if (pCommand->nZero)
        {
            const int nOldValue = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
            if (nOldValue == pCommand->nZero)
                bBlood = 0;
            else
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nZero << 8, 0);
        }

        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        pUnit->dwLastHitClass = pCommand->nParam18;
        PATH_RecacheRoomIfNeeded(pPath);
        UNITMODE_SetUnitMode(pUnit, 3);
        if (bBlood)
            MONSTER_SpawnBloodMissiles(pUnit, 1, 0);

        CUNIT_SetDrawDelay(pUnit);
        MONSTER_RunUModHitCallbacks(pUnit);
        break;
    }

    case 0x13:
        D2_ASSERT(pCommand, 0x781);
        sub_004AC840(pUnit, pCommand->nY & 0x80);
        pCommand->nY &= 0x7F;
        if (pCommand->nY > 1)
            ++pCommand->nY;

        if (pCommand->nY)
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nY << 8, 0);

        pUnit->dwLastHitClass = pCommand->nX;
        MONSTER_SpawnBloodMissiles(pUnit, 1, 1);
        CUNIT_SetDrawDelay(pUnit);
        UNITMODE_SetModeOverlay(pUnit, 0xD);
        sub_004CC5B0_RequestMode(pUnit, 0xD, 1);
        MONSTER_RunUModHitCallbacks(pUnit);
        break;

    case 0x14:
        D2_ASSERT(pCommand, 0x79A);
        if (pCommand->nPathByte)
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nPathByte << 8, 0);

        pUnit->dwLastHitClass = pCommand->nParam18;
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        PATH_RecacheRoomIfNeeded(pPath);
        PATH_SetType(pPath, 0xB);
        D2COMMON_10190_PATH_SetDistance(pPath, (unsigned char)pCommand->nZero);
        D2COMMON_10170_PathSetTargetPos(pPath, (unsigned short)pCommand->nX, (unsigned short)pCommand->nY);
        D2Common_10142(pPath, pUnit, 0);
        UNITMODE_SetUnitMode(pUnit, 0xD);
        break;

    case 0x12:
        D2_ASSERT(pCommand, 0x7B0);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        PATH_RecacheRoomIfNeeded(pPath);
        CUNIT_SetTargetByGUID(pUnit, pCommand->nX, pCommand->nY);
        CUNIT_SetPathTargetToTargetUnit(pUnit, 0);
        UNITMODE_SetUnitMode(pUnit, 6);
        break;

    case 8:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        pUnit->dwLastHitClass = pCommand->nParam18;
        if (SELECT_GetSelectedUnit() == pUnit)
        {
            if (!(GAME_GetLeftClickState() & 8) && !(GAME_GetRightClickState() & 8))
            {
                SELECT_ClearSelection();
            }
            else
            {
                GAME_ResetMouseState();
                SELECT_RefreshHoverUnit(0);
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
        if (STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags &= ~2;
            pUnit->dwFlags |= 0x20;
        }

        if (STATES_CheckStateMaskShatterOnUnit(pUnit))
        {
            MONSTER_CreateDeathMissiles(pUnit);
            pUnit->dwLastHitClass = (pUnit->dwLastHitClass & 0xF) | 0xA0;
        }

        if (!(pMonStats2Txt->nFlags[2] & gdwBitMasks[3]))
            PATH_SetUnitDeadCollision(pUnit, 0);

        nValue = pUnit->dwClassId;
        D2MonStatsTxt* pDeadMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nValue);
        if (!pDeadMonStatsTxt)
            return;

        switch (pDeadMonStatsTxt->nSplEndDeath)
        {
        case 1:
            if (pDeadMonStatsTxt->wMinion[0] >= 0 && pDeadMonStatsTxt->wMinion[0] < sgptDataTables->nMonStatsTxtRecordCount)
            {
                D2UnitStrc* pSpawned = CUNIT_SpawnPresetUnit(nValue, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, 0);
                if (pSpawned)
                    pSpawned->dwFlags &= ~2;

                pSpawned->dwLastHitClass = pUnit->dwLastHitClass;
                UNITMODE_SetUnitMode(pSpawned, 0);
                sub_004AEDD0(pUnit, pDeadMonStatsTxt->wMinion[0]);
            }
            break;
        }

        switch (nMonId)
        {
        case MONSTER_THORNHULK1:
            CUNIT_SetOverlayWithSound(pUnit, 0x4F, 0);
        SET_NEUTRAL_MODE:
            UNITMODE_SetUnitMode(pUnit, 0);
        CLEAR_LIGHT:
            pUnit->dwFlags &= ~2;
            CUNIT_FreeLight(pUnit);
            break;

        case MONSTER_MAGGOTEGG1:
            if (pUnit->dwAnimMode == 0xE)
            {
                UNITMODE_SetUnitModeNoOverlay(pUnit, 0);
                pUnit->dwFlags &= ~2;
                pUnit->nSeqCurrentFramePrecise = 0xE00;
                CUNIT_FreeLight(pUnit);
            }
            else
            {
                UNITMODE_SetUnitMode(pUnit, 0);
                pUnit->dwFlags &= ~2;
                CUNIT_FreeLight(pUnit);
            }
            break;

        case MONSTER_CANTOR1:
            CUNIT_SetOverlayWithSound(pUnit, 0x4E, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_FROGDEMON1:
            CUNIT_SetOverlayWithSound(pUnit, 0x52, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_VULTURE1:
            CUNIT_SetOverlayWithSound(pUnit, 0x92, 0);
            UNITMODE_SetUnitMode(pUnit, 0);
            if (!PARTICLE_GetGfxClientZ(pUnit))
                goto CLEAR_LIGHT;

            GFXUTIL_ReplaceMotionFlag1With8(pUnit);
            GFXUTIL_SetMotionFlagMask(pUnit, 0);
            GFXUTIL_SetMotionVectorB(pUnit, 0, 0, -0x10, 1);
            GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 0, 0);
            pUnit->dwFlags &= ~2;
            CUNIT_FreeLight(pUnit);
            break;

        case MONSTER_TENTACLE1:
        case MONSTER_TENTACLEHEAD1:
            CUNIT_SetOverlayWithSound(pUnit, 0x9D, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_DOPPLEZON:
            AUTOMAP_RequestAtTarget(pUnit, 0x148, 0, 1);
            goto SET_NEUTRAL_MODE;

        case MONSTER_HYDRA1:
        case MONSTER_HYDRA2:
        case MONSTER_HYDRA3:
            GFX_RemoveOverlays(pUnit);
            CUNIT_SetOverlayWithSound(pUnit, (!pUnit ? -1 : pUnit->dwClassId) - 0xAD, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_MAGGOTQUEEN1:
        {
            D2MonCommandStrc tCommand = {};
            tCommand.nX = 0xD8;
            tCommand.nArg = 1;
            MONSTER_HandleMonsterCommand(0x15, pUnit, &tCommand);
            pUnit->dwFlags &= ~2;
            CUNIT_FreeLight(pUnit);
            break;
        }

        case MONSTER_WILLOWISP1:
            CUNIT_SetOverlayWithSound(pUnit, 0xB8, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_DOOMKNIGHT1:
        case MONSTER_DOOMKNIGHT2:
        case MONSTER_DOOMKNIGHT3:
            CUNIT_SetOverlayWithSound(pUnit, 0xBB, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_BONEFETISH1:
            CUNIT_SetOverlayWithSound(pUnit, 0xBC, 0);
            CUNIT_SetOverlayWithSound(pUnit, 0xBD, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_SHADOWWARRIOR:
        case MONSTER_SHADOWMASTER:
            CUNIT_SetOverlayWithSound(pUnit, 0x10F, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_MEGADEMON1:
        case MONSTER_VENOMLORD:
            CUNIT_SetOverlayWithSound(pUnit, 0xB9, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_MINION1:
        {
            unsigned char nDirection = UNITS_GetDirection(pUnit);
            switch (INVENTORY_GetEightWayDirection(nDirection) % 4)
            {
            case 0:
                sub_004B9A00(0x51C, pUnit, 0, 0, 0);
                break;
            case 1:
                sub_004B9A00(0x51F, pUnit, 0, 0, 0);
                break;
            case 2:
                sub_004B9A00(0x522, pUnit, 0, 0, 0);
                break;
            case 3:
                sub_004B9A00(0x525, pUnit, 0, 0, 0);
                break;
            }
            UNITMODE_SetUnitMode(pUnit, 0);
            pUnit->dwFlags &= ~2;
            CUNIT_FreeLight(pUnit);
            break;
        }

        case MONSTER_SUICIDEMINION1:
            CUNIT_SetOverlayWithSound(pUnit, 0xCC, 0);
            sub_004B9A00(0x973, pUnit, 0, 0, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_PLAGUEPOPPY:
        case MONSTER_CYCLEOFLIFE:
        case MONSTER_VINECREATURE:
            MISSILE_SubmitMissileRequest(pUnit, 0x1D6, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
            UNITMODE_SetUnitMode(pUnit, 0);
            sub_004B9A00(0x316, pUnit, 0, 0, 0);
            pUnit->dwFlags &= ~2;
            CUNIT_FreeLight(pUnit);
            break;

        case MONSTER_CATAPULT1:
        {
            int nOverlay;
            switch (pUnit->dwClassId)
            {
            case 0x1F1:
            case 0x1F3:
                nOverlay = 0xE1;
                break;
            case 0x1F2:
                nOverlay = 0xE2;
                break;
            default:
                goto SET_NEUTRAL_MODE;
            }
            CUNIT_SetOverlayWithSound(pUnit, nOverlay, 0);
            goto SET_NEUTRAL_MODE;
        }

        case MONSTER_SUCCUBUS1:
        case MONSTER_SUCCUBUSWITCH1:
            CUNIT_SetOverlayWithSound(pUnit, 0xE5, 0);
            goto SET_NEUTRAL_MODE;

        case MONSTER_SIEGEBEAST1:
        {
            D2DynamicPathStrc* pDeadPath = pPath;
            D2COMMON_10160_PathUpdateDirection(pDeadPath, (PATH_GetDirection(pDeadPath) + 0x20) % 0x40);
            goto SET_NEUTRAL_MODE;
        }

        case MONSTER_BAALCLONE:
            MISSILE_SubmitMissileRequest(pUnit, 0x266, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
        case MONSTER_BAALCRABSTAIRS:
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags |= 0x20;
            UNITMODE_SetUnitMode(pUnit, 0xC);
            pUnit->dwFlags &= ~2;
            CUNIT_FreeLight(pUnit);
            break;

        default:
            goto SET_NEUTRAL_MODE;
        }
        break;
    }

    case 9:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (!(pMonStats2Txt->nFlags[2] & gdwBitMasks[3]))
            PATH_SetUnitDeadCollision(pUnit, 0);

        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 0, 0);
        if (CUNIT_GetPathTargetUnit(pPlayer) == pUnit)
            UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);

        if (nMonId == MONSTER_MAGGOTQUEEN1 && pUnit->dwAnimMode == 0xE)
        {
            UNITS_SetUsedSkill(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_QUEENDEATH));
        }
        else
        {
            UNITMODE_SetUnitMode(pUnit, 0xC);
            CUNIT_MarkUnitDead(pUnit);
        }

        if (pUnit->dwClassId != 0xD3 && nMonId != MONSTER_CATAPULT1 && nMonId != MONSTER_SHADOWWARRIOR && nMonId != MONSTER_SHADOWMASTER)
            GFX_RemoveOverlays(pUnit);

        if (nMonId == MONSTER_BARRICADETOWER)
            CUNIT_MarkUnitDead(MISSILE_SubmitMissileRequest(pUnit, 0x1A8, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1));

        switch (nMonId)
        {
        case MONSTER_BONEWALL:
        case MONSTER_BAALCRABSTAIRS:
        case MONSTER_BAALCLONE:
            pUnit->dwFlagEx |= 0x40000;
            break;
        }

        pUnit->dwFlags &= ~2;
        pUnit->dwFlags |= 0x20;
        if (STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            pUnit->dwFlagEx |= 0x40000;
            pUnit->dwFlags &= ~4;
            pUnit->dwFlags |= 0x20;
        }

        CUNIT_FreeLight(pUnit);
        break;
    }

    case 7:
    {
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        if (pCommand && pCommand->nZero)
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pCommand->nZero << 8, 0);

        if (sub_00451F30_TestUnitFlag(pUnit, 0x200))
            pUnit->dwFlags |= 2;
        else
            AUTOMAP_SetUnitFlag(pUnit, 2, pMonStats2Txt->nFlags[0] & gdwBitMasks[3]);

        AUTOMAP_SetUnitFlag(pUnit, 0x20, !(pMonStats2Txt->nFlags[1] & gdwBitMasks[6]));
        CUNIT_UpdateAttackableFlag(pUnit);
        if (!pCommand)
        {
            MONSTER_RefreshMonsterMode(pUnit);
            break;
        }

        UNITMODE_SetPosition(pUnit, (unsigned short)pCommand->nX, (unsigned short)pCommand->nY, 0, 0, 0);
        if (sub_n5b_Distance(CLIENTS_GetUnitX(pUnit) - pCommand->nX) <= 1 && sub_n5b_Distance(CLIENTS_GetUnitY(pUnit) - pCommand->nY) <= 1)
        {
            MONSTER_RefreshMonsterMode(pUnit);
            break;
        }

        sub_b1_WalkTo(pUnit, pCommand, 2);
        break;
    }

    case 0x16:
    {
        D2_ASSERT(pCommand, 0x911);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        nValue = pCommand->nX;
        SKILLS_AssignSkill(pUnit, nValue, pCommand->nArg, 0, gszMonsterSourceFile, 0x914);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nValue);
        UNITS_SetUsedSkill(pUnit, pSkill);
        nValue = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
        if (nValue == 0xE)
            MONSTER_ReplaySequence(pUnit);

        pCommand->nY = -1;
        UNITMODE_SetUnitMode(pUnit, nValue);
        SKILLS_StartSkillOnUnit(pUnit, pCommand);
        break;
    }

    case 0x15:
    {
        D2_ASSERT(pCommand, 0x924);
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        nValue = pCommand->nX;
        SKILLS_AssignSkill(pUnit, nValue, pCommand->nArg, 0, gszMonsterSourceFile, 0x929);
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nValue);
        UNITS_SetUsedSkill(pUnit, pSkill);
        nValue = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
        if (nValue == 0xE)
            MONSTER_ReplaySequence(pUnit);

        pCommand->nY = -1;
        UNITMODE_SetUnitMode(pUnit, nValue);
        SKILLS_StartSkillAtPos(pUnit, pCommand);
        break;
    }

    default:
        D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
        MONSTER_RefreshMonsterMode(pUnit);
        break;
    }

    if (bUpdateVelocity && pCommand && pCommand->nArg)
    {
        const int nVelocity = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
        if (nVelocity != pCommand->nArg)
        {
            STATLIST_DeactivateTemporaryStates(pUnit);
            STATLIST_AddUnitStat(pUnit, STAT_VELOCITYPERCENT, pCommand->nArg - nVelocity, 0);
            UnitUpdateAnimRateAndVel(pUnit, gszMonsterSourceFile, 0x946);
        }
    }

    MONSTER_RunUModUpdateCallbacks(pUnit);
    if (sub_n5b_IsTypeFlag1(pUnit))
    {
        if (pUnit->dwAnimMode != 1)
            MONSTER_RefreshMonsterMode(pUnit);

        if (pPath)
            PATH_ClearPathingFlagAndPoints(pPath);
    }
}

static inline unsigned int sub_I20_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* sub_I20_GetSkillsTxt(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int sub_I20_HasUnitFlagBit(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 0x15) & 1;
    }
    return bResult;
}

static inline int sub_I20_UnitX(D2UnitStrc* pUnit)
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

static inline int sub_I20_UnitY(D2UnitStrc* pUnit)
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


// 0x004B1020
int __cdecl MONSTER_GetEventUnit()
{
    return gpEventUnit;
}

// 0x004B1030
D2UnitStrc* __fastcall MONSTER_GetLinkedPlayer(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nOwnerGUID != -1)
    {
        return CUNIT_FindClientUnit(pUnit->pMonsterData->nOwnerGUID, 0);
    }
    return 0;
}

// 0x004B1050
int __fastcall MONSTER_GetMonsterOwnerGuid(D2UnitStrc* pUnit, char* pNotFound, int* pValue)
{
    *pNotFound = 1;
    *pValue = -1;
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nOwnerGUID != -1)
    {
        *pValue = pUnit->pMonsterData->nOwnerGUID;
        *pNotFound = 0;
        return 1;
    }
    return 0;
}


// 0x004B1090
void __fastcall MONSTER_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo)
{
    if (!pUnit || !pInfo)
    {
        return;
    }

    pUnit->dwFlags |= 0x202;
    const int nAct = MONSTERS_GetActFromHirelingTxt(GAME_IsExpansion(), 0, pInfo->f_0);
    const int nDifficulty = GAME_GetDifficulty();
    D2HirelingInitStrc hirelingInit;
    if (!MONSTERS_HirelingInit(GAME_IsExpansion(), sub_00463DD0_GetPlayerUnit(), pInfo->nSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    const int nLevel = hirelingInit.nLevel;
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(GAME_IsExpansion(), hirelingInit.nId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;
    if (nLevelUps < 0)
    {
        nLevelUps = 0;
    }

    for (int i = 0; i < 6; ++i)
    {
        const int nSkillId = pHirelingTxtRecord->dwSkill[i];
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            break;
        }

        int nSkillLevel = (pHirelingTxtRecord->nSLvlPerLvl[i] * nLevelUps >> 5) + pHirelingTxtRecord->nLevel[i];
        if (nSkillLevel >= 32)
        {
            nSkillLevel = 32;
        }

        const int nMode = pHirelingTxtRecord->nMode[i];
        SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, gszMonsterSourceFile, 2504);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), nMode);
    }

    unsigned short wNameId = pInfo->f_0;
    if (wNameId == 0x421)
    {
        wNameId = 0x2B0D;
    }

    MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(wNameId));
    ITEM_RefreshUnitEquipment(pUnit);
}

__declspec(noinline) void __fastcall CUNIT_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg)
{
    if (!pUnit)
        return;

    if (nArg > 0)
        GFX_AddUnitOverlay(pUnit, nOverlay, 1, 0, nArg, 0, 0, 0);
    else
        GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);

    switch (nOverlay)
    {
    case 0x97:
        sub_004B9A00(0x18C, pUnit, 0, 0, 0);
        break;
    case 0x98:
        sub_004B9A00(0x18D, pUnit, 0, 0, 0);
        break;
    }
}

static inline int sub_n5b_IsClassId(D2UnitStrc* pUnit, int nClassId)
{
    return pUnit->dwClassId == nClassId;
}

static inline int sub_n5b_Distance(int nDelta)
{
    if (nDelta < 0)
        nDelta = -nDelta;
    return nDelta;
}

static inline int sub_n5b_IsTypeFlag1(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        return pUnit->pMonsterData->nClientFlags & 1;
    return 0;
}

static inline D2MonStatsTxt* sub_n5b_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline D2MonStats2Txt* sub_n5b_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_n5b_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
            return pUnit->dwClassId;
        return pMonStatsTxtRecord->nBaseId;
    }
    return -1;
}

static inline int sub_n5b_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return nMonsterId;
    return -1;
}

static __forceinline void sub_b1_WalkTo(D2UnitStrc* pUnit, D2MonCommandStrc* pCommand, int nMode)
{
    if (sub_004AE080(pUnit, 1) || !sub_004804A0_SetPathTargetPos(pUnit, pCommand->nX, pCommand->nY)
        || STATES_CheckState(pUnit, STATE_ATTACHED) || !sub_0046C140_TestMonModeFlag(pUnit->dwClassId, nMode))
    {
        MONSTER_RefreshMonsterMode(pUnit);
        return;
    }

    UNITMODE_SetUnitMode(pUnit, nMode);
}

// 0x004B11F0
int __fastcall MONSTER_IsConvertible(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return 0;
    if (!UNITS_CanSwitchAI(pUnit->dwClassId))
        return 0;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (sub_004AC7E0(pUnit, 8))
            return 0;
        if (pUnit->dwUnitType == UNIT_MONSTER && sub_004AC7E0(pUnit, 2))
            return 0;
    }
    return 1;
}

// 0x004B1240
void __fastcall MONSTER_SetMinionSpawnClass(D2ClientPacket7Strc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, 1);
    if (pUnit)
    {
        const unsigned short wClassId = pPacket->f_5;
        const int nClassId = wClassId == 0xFFFF ? -1 : wClassId;
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->nMinionSpawnClassId = nClassId;
        }
    }
}


static D2MonStatsTxt* MONSTATS_GetRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2MonStatsTxt* MONSTATS_GetUnitRecord(D2UnitStrc* pUnit, int nType)
{
    if (pUnit && nType == UNIT_MONSTER)
    {
        return MONSTATS_GetRecord(pUnit->dwClassId);
    }

    return 0;
}

// 0x004B1280
int __fastcall MONSTER_HandleSequenceStop(D2UnitStrc* pUnit, D2SeqModeStrc* pMode)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nType = pUnit->dwUnitType;

    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetUnitRecord(pUnit, nType);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        switch (pMonStatsTxtRecord->nSplEndDeath)
        {
        case 1:
            if (!pUnit->dwAnimMode && UNITS_IsAtEndOfFrameCycle(pUnit))
            {
                D2MonCommandStrc tCommand = {};
                MONSTER_HandleMonsterCommand(9, pUnit, &tCommand);
            }
            break;
        }
    }

    int nResult = 0;
    switch (pMode->nMode)
    {
    case 0:
        UNITS_StopSequence(pUnit);
        break;

    case 1:
        nResult = UNITS_IsAtEndOfFrameCycle(pUnit);
        if (!nResult)
        {
            UNITS_StopSequence(pUnit);
        }
        break;

    case 2:
        if (!UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            UNITS_StopSequence(pUnit);
            break;
        }

        pUnit->nSeqCurrentFramePrecise = pUnit->dwFrameCountPrecise - 0x100;
        pUnit->wAnimSpeed = 0;
        if (!pUnit->dwAnimMode)
        {
            pUnit->dwFlags |= 0x20;
        }
        break;

    case 3:
        pUnit->nSeqCurrentFramePrecise = 0x100;
        pUnit->wAnimSpeed = 0;
        break;
    }

    return nResult;
}

// 0x004B13A0
void __fastcall MONSTER_UpdateMonsterClient(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    if (STATES_CheckState(pUnit, STATE_FREEZE) && !CUNIT_IsDeadOrDying(pUnit))
    {
        return;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode >= 0x10)
    {
        return;
    }

    D2MonAnimRecStrc* pRecord = MONSTER_GetAnimRecord(pUnit);
    if (!pRecord)
    {
        return;
    }

    MONSTER_UpdateFrame(pUnit);

    int bResult = 0;
    switch (pRecord->nType)
    {
    case 1:
        bResult = sub_004807C0(pUnit);
        break;
    }

    if (nMode == 1 && !sub_004AE080(pUnit, nMode))
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath && PATH_GetTargetUnit(pPath))
        {
            int nUnitType;
            int nUnitGUID;
            PATH_GetTargetTypeAndGUID(pPath, &nUnitType, &nUnitGUID);
            D2UnitStrc* pTarget = CUNIT_FindClientUnit(nUnitGUID, nUnitType);
            PATH_SetTargetUnit(pPath, pTarget);
            if (pTarget)
            {
                D2Common_10213(pUnit);
            }
        }
        else
        {
            D2Common_10213(pUnit);
        }
    }

    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(nClassId);
    if (!pMonStatsTxt)
    {
        return;
    }

    if ((pMonStatsTxt->nMonStatsFlags[9 >> 3] & gdwBitMasks[9 & 7]) && !MONSTERREGION_CheckMonStats2Flag(nClassId, 0xD)
        && pUnit->dwAnimMode == 1 && !sub_00451F30_TestUnitFlag(pUnit, 0x200)
        && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && (unsigned int)sub_00641530(pUnit, pPlayer) < 7)
        {
            D2SeedStrc* pSeed = &pUnit->pSeed;
            if (pSeed && (int)SEED_RollLimitedRandomNumber(pSeed, 0x64) < 0xA)
            {
                D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
                if (pPath)
                {
                    D2Common_10216(pPath, CLIENTS_GetUnitX(pPlayer), CLIENTS_GetUnitY(pPlayer), 0);
                }
            }
        }
    }

    const int nRet = sub_004B1280(pUnit, pRecord);
    int bAttack = 0;
    switch (pRecord->nAction)
    {
    case 1:
        bAttack = bResult;
        break;

    case 2:
    case 3:
        bAttack = nRet;
        break;

    case 4:
        if (bResult && sub_006217C0(pUnit))
        {
            bAttack = 1;
        }
        break;
    }

    MONSTER_HandleSkillEvent(pUnit);
    MONSTER_RunUModFrameCallbacks(pUnit);
    if (pUnit->pDynamicPath)
    {
        D2COMMON_10193_PATH_AdjustDirection(pUnit->pDynamicPath);
    }

    if (bAttack)
    {
        MONSTER_HandleAttackEvent(pUnit);
    }

    if (!pUnit->dwAnimMode && pUnit->dwClassId == 0x210 && sub_00451F30_TestUnitFlag(pUnit, 1))
    {
        pUnit->dwFlags &= ~1;
        CUNIT_SpawnPresetUnit(0x1DE, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 2, 0);
    }

    if (sub_0063A340(pUnit))
    {
        SKILLS_RunStateActiveFuncs(pUnit);
    }

    UNITSND_UpdateModeSound(pUnit);
    sub_004CAF60(pUnit);
}

// 0x004B15F0
Unicode Unicode::toLower() const
{
// build: symbol ?gaCaseTable@* 0x00730778
    return Unicode(wChar < CASE_BOUND ? gaCaseTable[wChar] : wChar);
}


// 0x004B17D0
static inline void MONSTER_SetNpcMenuState(int nState)
{
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    gnNpcMenuState = nState;
}

// 0x004B17E0
static inline void MONSTER_SetNpcMenuUnit(D2UnitStrc* pUnit)
{
    gpNpcPlayerUnit = pUnit;
}

// 0x004B17F0
static inline void MONSTER_SetNpcMenuValue(unsigned short wValue)
{
    gwGlobal_007C0DD8 = wValue;
}

// 0x004B1800
static inline bool MONSTER_IsStringUnused(unsigned short wString)
{
    for (int i = 0; i < gtStringList.wCount; ++i)
    {
        if (gtStringList.awStrings[i] == wString)
        {
            return false;
        }
    }
    return true;
}


// 0x004B1D50
void __cdecl MONSTER_CloseNpcResource()
{
    if (gpRes_007C0D6B)
    {
        DIALOG_DestroyDialog(gpRes_007C0D6B);
        gpRes_007C0D6B = 0;
    }
}

// 0x004B1DC0
int __cdecl sub_004B1DC0()
{
    return 0;
}





// 0x004BF9B0
int __cdecl sub_004BF9B0()
{
    return 0;
}

// 0x004E4040
void __stdcall sub_004E4040(int nUnused1)
{
}

#include "gen/data/Source/D2Client/UNIT/Monster.inc"
