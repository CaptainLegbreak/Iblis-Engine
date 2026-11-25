#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Records.h"
#include "D2AnimData.h"
#include "D2WinSplitText.h"
#include "D2FogSystemInfo.h"
#include "D2ClientBallistic.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

// Row numbers in WeaponClass.txt (hth, bow, 1hs, 1ht, stf, 2hs, 2ht, xbw, ...).
enum D2C_WeaponClassRows
{
    WEAPONCLASS_XBW = 7,
};

struct D2MissilesTxt;

struct D2GfxLightStrc;

struct R0052E0F0;

struct R00601DC0;

struct D2MissileStrc;

struct D2FogSystemInfoStrc;

struct D2PacketUnitRecordStrc;

struct D2AreaScanFindStrc;

struct D2SkillsTxt;

struct D2MonStats2Txt;

union D2SeedStrc;

struct D2MonStatsTxt;

struct D2ClientSkillArgsStrc;

struct D2PathDirectionStrc;

struct D2StaticPathStrc;

struct D2CltMissileModeStrc;


struct D2BallisticStrc;

struct D2DrlgCoordsStrc;

struct D2ActiveRoomViewStrc;

struct D2AreaScanStrc;

struct D2StatesTxt;

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

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2FogSystemInfoStrc* __cdecl FOG_GetSystemInfo(); // 0x00407360

void __fastcall SOUNDHDR_SetCacheMax(unsigned int nSize); // 0x00481840

void __stdcall D2CMPTileCacheInit(void* pMemPool, int nArg); // 0x005FE120

void __stdcall D2CMPSpriteCacheInit(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize); // 0x005FFD40

void __fastcall GFX_InitGfxTables(int nSize); // 0x00470200

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall sub_004C52E0(D2UnitStrc* pUnit, int* pTargetX, int* pTargetY); // 0x004C52E0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

#pragma pack(push, 1)

struct D2PacketUnitRecordStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitId;
};

#pragma pack(pop)

struct D2AreaScanFindStrc
{
    D2UnitStrc* pFirst;
    unsigned int nBest;
    D2UnitStrc* pSecond;
    unsigned int nArgA;
    unsigned int nArgB;
    int nOut;
};

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall ITEM_ClearUninterruptableState(D2UnitStrc* pItem); // 0x004C2180

int __fastcall SKILLS_CanThrow(D2UnitStrc* pUnit); // 0x004C54F0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

int __fastcall MISSILE_DoSkillWithTempTarget(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x004CA060

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

int __fastcall GFX_DrawUnit(D2UnitStrc* pUnit, unsigned int dwColor, int nX, int nY, int nArg, int bOverlay); // 0x00471EC0

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall UNITS_IsSoftMonster(D2UnitStrc* pUnit); // 0x00621F60

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625500

int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem); // 0x006288A0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern int gaLevelVisited[]; // 0x007C78B8

extern int gnGlobal_007C88B8; // 0x007C88B8

extern int gnGlobal_007C88BC; // 0x007C88BC

extern int gnGlobal_007C88C0; // 0x007C88C0

extern int gnGlobal_007C88C4; // 0x007C88C4

extern int gnGlobal_007C88C8; // 0x007C88C8

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius); // 0x00474290

void* __stdcall D2Common_10958(D2UnitStrc* pUnit, void* pValue); // 0x00643A00

void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0

int __fastcall ROSTERPETS_FindRosterIndex(int nUnitId); // 0x00479150

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __fastcall SKILLS_DoClientSkill(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode); // 0x004C6680

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __fastcall SKILLS_HandleMoveSkillEnd(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004C7890

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall UNITS_GetMeleeRange(D2UnitStrc* pUnit); // 0x00622870

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900

void __fastcall sub_004BA840(void* pUnitSfx); // 0x004BA840

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

typedef int (__fastcall* CLIENTSKILLSTARTFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern CLIENTSKILLSTARTFN gpfnClientSkillStartFuncs[]; // 0x00727A90

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall CUNIT_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464F70

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70

int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall UNITSND_GetDirectionRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA4C0

unsigned int __fastcall UNITSND_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, D2PathDirectionStrc tDirection); // 0x00648820

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

struct D2CltMissileModeStrc
{
    D2UnitFindCallback pfUnitFindCallback;
    int nCollisionMask;
};


extern const int gaSpiralOuterY[7]; // 0x006DADC0

extern const int gaSpiralOuterX[7]; // 0x006DADE0

extern const int gaSpiralOuterB[7]; // 0x006DAE00

extern const int gaSpiralInnerY[4]; // 0x006DAE1C

extern const int gaSpiralOuterA[7]; // 0x006DAE2C

extern const int gaSpiralInnerX[4]; // 0x006DAE48


extern D2CltMissileModeStrc gaCltMissileModes[]; // 0x0072A350

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5); // 0x004DA200

D2BallisticStrc* __fastcall sub_0046F060(D2UnitStrc* pUnit); // 0x0046F060

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648C30

void __stdcall PATH_AllocDynamicPath(int nArg1, int nArg2, int nArg3, int nArg4, D2UnitStrc* pUnit, int nArg6); // 0x00649D00

void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

int __fastcall SKILLS_IsAlliedUnit(D2UnitStrc* pUnitA, D2UnitStrc* pUnitB); // 0x004C5910

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster); // 0x0063EDC0

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730


struct D2ActiveRoomViewStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2AreaScanStrc
{
    D2UnitStrc* pUnit;
    int nCount;
    void* pArg;
};

typedef int (__fastcall* AREASCANFN)(D2AreaScanStrc* pScan, D2UnitStrc* pUnit);

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag); // 0x00457490

int __fastcall SKILLS_CanScanUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags); // 0x004C5960

static int sub_004C5BD0_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius); // 0x004C5BD0

typedef int (__fastcall* CLIENTSKILLDOFN)(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern CLIENTSKILLDOFN gpfnClientSkillDoFuncs[]; // 0x00727BA8

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0

void __fastcall SKILLS_SetMissileDirection(D2UnitStrc* pMissile, int nDirection); // 0x004C7470

extern "C" int __stdcall sub_006492A0(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __fastcall SKILLS_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40

int __fastcall SKILLS_ScanCountCallback(D2AreaScanStrc* pScan, D2UnitStrc* pUnit); // 0x004C5E20

extern const int gaRingTargetY[64]; // 0x006DABC0

extern const int gaRingTargetX[64]; // 0x006DACC0

struct D2PetTypeTxt;

struct D2SkillDescTxt;

int __fastcall sub_00479150_GetOwnerId(int nUnitId); // 0x00479150

int __fastcall ROSTER_GetPetType(int nUnitId); // 0x00479180

void __fastcall SKILLS_EndCharge(D2UnitStrc* pUnit, int nSkillId); // 0x004CA000

void __fastcall SKILLSBAR_ResetLeapCollision(D2UnitStrc* pUnit); // 0x004C8B80

void __fastcall SKILLS_EndLoopSoundSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004C9420

extern "C" const char gszSkillsCppFile[]; // 0x006DAB88

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0

int __stdcall SKILLS_IsEnhanceable(int nSkillId); // 0x00645FB0

void __stdcall D2Common_11031(D2UnitStrc* pUnit, int nSkillId, int nBonus); // 0x00647B20

#define SKILLSFLAGINDEX_LOB 1

#define SKILLSFLAGINDEX_PRGSTACK 7

typedef int (__fastcall* ClientSkillDo)(D2UnitStrc*,int,int);

extern int gnClientDoCount; // 0x00727DB0

extern ClientSkillDo gaClientDo[]; // 0x00727BA8

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

D2UnitStrc* __fastcall SKILLS_FireMissileAtTarget(int,D2UnitStrc*,int,int,int,int,int,int); // 0x004C57B0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*,unsigned int,int,int); // 0x00646CA0

int __cdecl sub_0044DA90(); // 0x0044DA90

void __fastcall GAME_SetSkillDelayUntil(int); // 0x0044CE40

D2UnitStrc* __fastcall AUTOMAP_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4); // 0x004C5420

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

int __fastcall SKILLS_StartSkillAtPos(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs); // 0x004C6F40

static int SKILLS_GetAttackMode(D2UnitStrc* pUnit); // 0x004C5710

static int SKILLS_CheckSkillTarget(D2UnitStrc* pUnit, int nSkillId); // 0x004C58A0

static void __stdcall SKILLS_SwapDualWieldSkill(D2ClientSkillArgsStrc* pArgs, D2UnitStrc* pUnit); // 0x004C6DE0

int __fastcall SKILLS_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs); // 0x004C6EB0

static int __stdcall SKILLS_StartClientSkill(int nOwnerGUID, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId); // 0x004C6140

int __fastcall SKILLS_CallStartSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID); // 0x004C6660

int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem); // 0x0062A310

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0

int __fastcall SKILLS_FindEventFrame(D2UnitStrc* pUnit); // 0x004C9D70

void __fastcall UNITSND_PlayAttackSound(D2UnitStrc* pUnit, int nMode, int nArg); // 0x004CB6A0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

D2UnitStrc* __fastcall SKILLS_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900

bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}

int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, int nDirection);                          // 0x006488A0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

// 0x00457300
void __fastcall SKILLS_InitGfxCaches(void* pMemPool, int bCelPool)
{
    D2FogSystemInfoStrc* pInfo = FOG_GetSystemInfo();
    D2_ASSERT(pInfo, 0x30);
    if (pInfo->dwTotalPhys < 0x167D000)
    {
        LOGMANAGER_WriteLogLine("This machine doesn't have enough physical memory (> %.2f MB) for minimal performance!", (float)pInfo->dwTotalPhys / 1048576.0);
        exit(-1);
    }
    unsigned int nSize = pInfo->dwTotalPhys - 0xB00000;
    unsigned int nCacheSize = nSize * 10 / 100;
    nCacheSize = D2_MIN(D2_MAX(nCacheSize, 0x300000u), 0x500000u);
    SOUNDHDR_SetCacheMax(nCacheSize);
    unsigned int nRest = nSize - nCacheSize;
    if (bCelPool)
    {
        nRest -= 0x600000;
        D2CMPTileCacheInit(pMemPool, 0x600000);
    }
    nRest -= 0x200000;
    unsigned int nMaxSize = D2_MIN(D2_MAX(nRest / 3, 0x1800000u), 0x4000000u);
    D2CMPSpriteCacheInit(pMemPool, nMaxSize, 0x7D000, nSize);
    GFX_InitGfxTables(0x200000);
}

// 0x004C51B0
void __fastcall SKILLS_ClearUnitActionState(D2PacketUnitRecordStrc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        ITEM_ClearUninterruptableState(pUnit);
    }
}

int __stdcall OBJECTS_SpawnNothing(int nArg)
{
    return 1;
}

int __stdcall SKILLS_Return1(int nArg)
{
    return 1;
}

int __stdcall sub_00646260_AlwaysOne(int nArg)
{
    return 1;
}

int __stdcall sub_00646270_AlwaysOne(int nArg)
{
    return 1;
}

int __fastcall SKILLS_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall MISSILE_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

int __fastcall SKILLS_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __fastcall MISSILE_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x004C5390
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

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004C54F0
int __fastcall SKILLS_CanThrow(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 1;
    }
    D2UnitStrc* pWeapon = sub_00623990_GetWeapon(pUnit, 0);
    int bNoAmmo = 1;
    if (!pWeapon)
    {
        return 1;
    }
    if (ITEMS_GetAmmoType(pWeapon))
    {
        bNoAmmo = 0;
        if (!SKILLS_GetSkillIdFromSkill(UNITS_GetUsedSkill(pUnit), ".\\SKILLS\\Skills.cpp", 0xB6)
            && STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_MAGICARROW, 0))
        {
            return 1;
        }
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pItem && (!bNoAmmo || pItem == pWeapon)
        && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pItem);
    }
    pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pItem && (!bNoAmmo || pItem == pWeapon)
        && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem) || STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0)))
    {
        return ITEMS_CanItemBeUsedForThrowSkill(pItem);
    }
    return 0;
}

// 0x004C5620
void __stdcall SKILLS_SetSpeedToTarget(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    int nTargetX;
    int nTargetY;
    if (ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
        if (nDistance < 1)
        {
            nDistance = 1;
        }
        UNITS_SetAnimationSpeed(pMissile, 0xA00 / nDistance);
        MISSILE_SetCurrentFrame(pMissile, nDistance + 2);
        pMissile->nSeqCurrentFramePrecise = 0x200;
    }
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

static inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004C5680
void __fastcall SKILLS_AttachMissileLight(D2UnitStrc* pUnit, int nMissileId)
{
    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecordInline(nMissileId);
    if (pMissilesTxt->nLight)
    {
        D2GfxLightStrc* pLight = DLIGHTMAP_MakeLightEntry(pUnit, 1, 1, 0xFF, pMissilesTxt->nRGB[0], pMissilesTxt->nRGB[1], pMissilesTxt->nRGB[2]);
        sub_00474290(pLight, pMissilesTxt->nLight);
        void* pOld = D2Common_10958(pUnit, pLight);
        if (pOld)
            DLIGHTMAP_ReleaseLight(pOld);
    }
}

static inline D2SkillsTxt* SKILLCLT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return NULL;
}

static inline D2MonStatsTxt* SKILLCLT_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

static inline unsigned int SKILLCLT_RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned char SKILLCLT_GetUnitTypeByte(D2UnitStrc* pUnit)
{
    return pUnit->dwUnitType;
}

static inline int SKILLCLT_GetUnitType(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

static __forceinline void SKILLCLT_SetCastState(D2UnitStrc* pUnit)
{
    if (pUnit && (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER))
    {
        UNITMODE_SetUnitMode(pUnit, 1);
    }
}

// 0x004C5710
static int SKILLS_GetAttackMode(D2UnitStrc* pUnit)
{
    int nMode = 7;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    int bRandom = 1;
    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
        if (pMonStats2TxtRecord->nType == 2)
        {
            nMode = 8;
            bRandom = 0;
        }
        if (pMonStats2TxtRecord->nType == 1)
        {
            bRandom = 0;
        }
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        nMode = 7;
        bRandom = 0;
    }

    D2UnitStrc* pWeapon;
    int nBodyLoc;
    int bIsLeftHand;
    if (!INVENTORY_GetEquippedWeapon(pUnit->pInventory, &pWeapon, &nBodyLoc, &bIsLeftHand))
    {
        return 7;
    }

    if (bRandom)
    {
        const char nRoll = SKILLCLT_RollSeed(&pUnit->pSeed) & 0x3F;
        if (nRoll < 0x20)
        {
            return 8;
        }
    }

    return nMode;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

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

// 0x004C57B0
D2UnitStrc* __fastcall SKILLS_FireMissileAtTarget(int nMissile, D2UnitStrc* pUnit, int nSkill, int nSkillLevel, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = UNITS_GetUnitXPosition(pUnit) + nOffsetX;
    tMissileParams.nY = UNITS_GetUnitYPosition(pUnit) + nOffsetY;
    tMissileParams.nSkill = nSkill;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    if (nTargetX && nTargetY)
    {
        tMissileParams.nTargetX = nTargetX;
        tMissileParams.nTargetY = nTargetY;
    }
    else if (!sub_004C52E0(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    if (!tMissileParams.nTargetX || !tMissileParams.nTargetY)
    {
        return 0;
    }

    return MISSILE_CreateClientMissile(&tMissileParams);
}

// 0x004C58A0
static int SKILLS_CheckSkillTarget(D2UnitStrc* pUnit, int nSkillId)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 21))
    {
        const int nType = pTarget->dwUnitType;
        if (nType == 1 && pTarget->dwAnimMode == 12)
        {
            return BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 24) != 0;
        }

        if (nType == 0)
        {
            return 1;
        }
    }

    return 1;
}

// 0x004C5910
int __fastcall SKILLS_IsAlliedUnit(D2UnitStrc* pUnitA, D2UnitStrc* pUnitB)
{
    int nUnitIdB;
    if (!pUnitB)
    {
        nUnitIdB = -1;
    }
    else
    {
        nUnitIdB = pUnitB->dwUnitId;
        if (pUnitB->dwUnitType == UNIT_MONSTER)
        {
            nUnitIdB = ROSTERPETS_FindRosterIndex(nUnitIdB);
            if (nUnitIdB == -1)
                return 0;
        }
    }
    return sub_0047A520(!pUnitA ? -1 : pUnitA->dwUnitId, nUnitIdB) != 0;
}

struct D2ActiveRoomStrc;

struct D2UnitStrc;

static __forceinline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x004C5960
int __fastcall SKILLS_CanScanUnit(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nFlags)
{
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    switch (nType)
    {
    case 0:
    {
        if (!(nFlags & 1))
        {
            return 0;
        }
        const int nMode = pTarget->dwAnimMode;
        if (nFlags & 0x1000)
        {
            if (nMode != 0x11)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x11 || nMode == 0)
            {
                return 0;
            }
        }
        break;
    }
    case 1:
    {
        if (!(nFlags & 2))
        {
            return 0;
        }
        const int nMode = pTarget->dwAnimMode;
        if (nFlags & 0x1000)
        {
            if (nMode != 0x0C)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x0C || nMode == 0)
            {
                return 0;
            }
        }

        if (nFlags & 4 && !MONSTERS_IsUndead(pTarget)
            || nFlags & 0x4000 && MONSTERS_IsBoss(0, pTarget)
            || nFlags & 0x40000 && MONSTERS_IsPrimeEvil(pTarget))
        {
            return 0;
        }
        break;
    }
    case 2:
    {
        if (!(nFlags & 0x10))
        {
            return 0;
        }
        break;
    }
    case 3:
    {
        if (!(nFlags & 8))
        {
            return 0;
        }
        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pTarget->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[0] & gdwBitMasks[1])
        {
            return 0;
        }
        break;
    }
    case 4:
    {
        if (!(nFlags & 0x20))
        {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }

    if (nFlags & 0x80 && !UNIT_HasFlag(pTarget, 4))
    {
        return 0;
    }
    if (nFlags & 0x400 && !UNIT_HasFlag(pTarget, 8))
    {
        return 0;
    }
    if (nFlags & 0x100 && DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    if (nFlags & 0x10000)
    {
        if (!SKILLS_IsAlliedUnit(pUnit, pTarget))
        {
            return 0;
        }
        if (pTarget->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
            if (!pMonStatsTxtRecord || pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
            {
                return 0;
            }
        }
    }
    if (nFlags & 0x8000 && !CUNIT_IsHostileTo(pUnit, pTarget))
    {
        return 0;
    }
    if (nFlags & 0x20000 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }
    if (nFlags & 0x80000 && STATES_CheckState(pTarget, STATE_JUSTHIT))
    {
        return 0;
    }

    if (nFlags & 0x200)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || !UNITS_GetRoom(pTarget))
        {
            return 0;
        }
        D2CoordStrc coords;
        coords.nX = CLIENTS_GetUnitX(pUnit);
        coords.nY = CLIENTS_GetUnitY(pUnit);
        D2CoordStrc targetCoords;
        targetCoords.nX = CLIENTS_GetUnitX(pTarget);
        targetCoords.nY = CLIENTS_GetUnitY(pTarget);
        if (COLLISION_RayTrace(pRoom, &coords, &targetCoords, 4))
        {
            return 0;
        }
    }
    return 1;
}

static inline int U04_IsNearRoomY(const D2DrlgCoordsStrc* pCoords, int nY, int nRadius)
{
    return nY + nRadius >= pCoords->nSubtileY || nY - nRadius <= pCoords->nSubtileHeight + pCoords->nSubtileY;
}

// 0x004C5BD0
static int SKILLS_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (nX + nRadius >= tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    if (nX - nRadius <= tCoords.nSubtileWidth + tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    return 0;
}

int __fastcall sub_U04_Emit_00641930(D2ActiveRoomStrc** ppRooms, int nCount, int nX, int nY)
{
    for (int i = 0; i < nCount; ++i)
    {
        if (SKILLS_IsPointNearRoom(ppRooms[i], nX, nY, 2))
        {
            return i;
        }
    }
    return -1;
}

static int sub_004C5BD0_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (nX + nRadius >= tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    if (nX - nRadius <= tCoords.nSubtileWidth + tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    return 0;
}

static inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x004C5C40
void __fastcall SKILLS_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType)
{
    if (!pUnit || !pfCallback)
    {
        return;
    }

    if (!nRange)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (!nX || !nY)
    {
        nX = CLIENTS_GetUnitX(pUnit);
        nY = CLIENTS_GetUnitY(pUnit);
    }

    if (!nFlags)
    {
        nFlags = 0x583;
    }

    D2AreaScanStrc tScan;
    tScan.pArg = pArg;
    tScan.pUnit = pUnit;
    tScan.nCount = 0;
    const int nRangeSq = nRange * nRange;

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if ((nFlags & 0x2000) && DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            continue;
        }

        if (!sub_004C5BD0_IsPointNearRoom(ppRoomList[i], nX, nY, nRange))
        {
            continue;
        }

        D2UnitStrc* pTarget = ((D2ActiveRoomViewStrc*)ppRoomList[i])->pUnitFirst;
        while (pTarget)
        {
            D2UnitStrc* pNext = pTarget->ptRoomNext;
            if (pTarget != pUnit
                && nRangeSq >= PATH_ComputeSquaredDistance(nX, nY, UNITS_GetXPositionInline(pTarget), UNITS_GetYPositionInline(pTarget))
                && SKILLS_CanScanUnit(pUnit, pTarget, nFlags)
                && (!bCheckType || pTarget->dwUnitType != UNIT_MONSTER || !MONSTERUNIQUE_CheckMonStatsFlag(pTarget->dwClassId, 0x1B))
                && pfCallback(&tScan, pTarget))
            {
                ++tScan.nCount;
            }
            pTarget = pNext;
        }
    }
}

// 0x004C5E20
int __fastcall SKILLS_ScanCountCallback(D2AreaScanStrc* pScan, D2UnitStrc* pUnit)
{
    *(int*)pScan->pArg += 1;
    return 1;
}

// 0x004C5E30
int __fastcall SKILLS_ScanCount(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags)
{
    int nResult = 0;
    SKILLS_ScanArea(pUnit, nX, nY, nRange, nFlags | 0xA783, SKILLS_ScanCountCallback, &nResult, 0);
    return nResult;
}

// 0x004C5E70
int __fastcall SKILLS_ScanFindCallback(D2AreaScanStrc* pScan, D2UnitStrc* pUnit)
{
    D2AreaScanFindStrc* pFind = (D2AreaScanFindStrc*)pScan->pArg;
    const unsigned int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    if (nUnitId > pFind->nArgB && nUnitId < pFind->nBest)
    {
        pFind->nOut += 1;
        pFind->nBest = nUnitId;
        pFind->pFirst = pUnit;
        return 1;
    }
    if (nUnitId <= pFind->nArgA)
    {
        pFind->nArgA = nUnitId;
        pFind->pSecond = pUnit;
    }
    pFind->nOut += 1;
    return 1;
}

struct Unicode;

class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};

// 0x004C5EB0
int __fastcall SKILLS_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, int nArg, int* pOut)
{
    D2AreaScanFindStrc tFind = { 0, -1, 0, nArg, nArg, 0 };

    if (!nFlags)
    {
        nFlags = 0x583;
    }

    SKILLS_ScanArea(pUnit, nX, nY, nRange, nFlags | 0xA280, SKILLS_ScanFindCallback, &tFind, 0);

    D2UnitStrc* pResult = tFind.pFirst;
    if (!pResult)
    {
        pResult = tFind.pSecond;
    }

    if (pOut)
    {
        *pOut = tFind.nOut;
    }

    return (int)pResult;
}

// 0x004C5F30
int __fastcall SKILLS_CheckWeaponStart(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        if (!SKILLS_CanThrow(pUnit))
        {
            return 0;
        }
    }
    else
    {
        D2UnitStrc* pWeapon = sub_00623990_GetWeapon(pUnit, 0);
        if (pWeapon && ITEMSIsA(pWeapon, 0x26))
        {
            return 0;
        }
    }
    return 1;
}

// 0x004C5F70
int __fastcall SKILLS_CheckThrowStart(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_CanThrow(pUnit))
    {
        return 0;
    }
    return sub_00623990_GetWeapon(pUnit, 0) != 0;
}

static inline D2PetTypeTxt* DATATBLS_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

// 0x004C5FA0
int __fastcall SKILLS_CheckPetTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if ((!pTarget ? 6 : pTarget->dwUnitType) != UNIT_MONSTER)
    {
        return 0;
    }

    const int nOwnerId = sub_00479150_GetOwnerId(!pTarget ? -1 : pTarget->dwUnitId);
    if (nOwnerId != (!pUnit ? -1 : pUnit->dwUnitId))
    {
        return 0;
    }

    D2PetTypeTxt* pPetTypeTxtRecord = DATATBLS_GetPetTypeTxtRecord(ROSTER_GetPetType(!pTarget ? -1 : pTarget->dwUnitId));
    if (!pPetTypeTxtRecord)
    {
        return 0;
    }

    return (pPetTypeTxtRecord->nPetFlags[3 >> 3] & gdwBitMasks[3 & 7]) != 0;
}

// 0x004C6020
int __stdcall sub_004C6020_AlwaysOne(int nArg)
{
    return 1;
}

struct D2CellNodeStrc;

void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x004E4050

int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue); // 0x00645F00

// 0x004C6030
int __fastcall SKILLS_UseBowOrCallTarget(D2UnitStrc* pUnit, int nArg2, int nArg3)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (COMPOSIT_IsWeaponBowOrXBow(pUnit))
    {
        const int nValue = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nArg3);
        if (nValue != -1)
        {
            AUTOMAP_RequestAtTarget(pUnit, nValue, nArg2, nArg3);
        }
    }
    else
    {
        sub_004E4050_Nothing(pUnit, CUNIT_GetPathTargetUnit(pUnit));
    }

    return 1;
}

// 0x004C60A0
int __fastcall SKILLS_ThrowWeapon(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    int nX;
    int nY;
    D2UnitStrc* pItem;
    int nMissile;

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    pItem = sub_00623990_GetWeapon(pUnit, 0);
    if (!pItem)
    {
        return 0;
    }

    nMissile = ITEMS_GetMissileType(pItem);
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_MISSILE_POTION)
    {
        ITEM_GetTargetPosition(pUnit, &nX, &nY);
        MISSILE_SubmitOffsetRequest(pUnit, nMissile, 0, 0, nX, nY, nSkillId, 1, 0);
        return 1;
    }

    sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, 1);
    return 1;
}

// 0x004C6140
static int __stdcall SKILLS_StartClientSkill(int nOwnerGUID, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nLineOfSight)
    {
        int nX;
        int nY;
        if (ITEM_GetTargetPosition(pUnit, &nX, &nY))
        {
        int nCollisionMask;
        switch (pSkillsTxtRecord->nLineOfSight)
        {
        case 1:
            nCollisionMask = 4;
            break;
        case 2:
            nCollisionMask = 0x1C09;
            break;
        case 3:
            nCollisionMask = 0x180;
            break;
        case 4:
            nCollisionMask = 0x804;
            break;
        case 5:
            nCollisionMask = 0x805;
            break;
        default:
            return 0;
        }

        if (!sub_00645950_CheckTargetPos(nX, nY, pUnit, nCollisionMask))
        {
            return 0;
        }
        }
    }

    if (!SKILLS_CheckSkillTarget(pUnit, nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0x504) != nSkillId)
    {
        pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
        if (!pSkill)
        {
            SKILLS_AddSkill(pUnit, nSkillId);
            pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
            if (pSkill && pUnit == sub_00463DD0_GetPlayerUnit() && nOwnerGUID == -1)
            {
                SKILLS_SetFlags(pSkill, 8);
            }

            const int nMaxLevel = SPELLSEL_GetSkillMaxLevel(nSkillId);
            if (nSkillLevel > nMaxLevel)
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x513);
                sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
            }
            else
            {
                SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x518);
            }

            if (!pSkill)
            {
                return 0;
            }
        }

        UNITS_SetUsedSkill(pUnit, pSkill);
    }

    if (nOwnerGUID != -1)
    {
        int nItemOwnerGUID;
        int nItemSkillId;
        int nCharges;
        if (!SKILLS_GetSkillInfo(pSkill, &nItemOwnerGUID, &nItemSkillId, &nSkillLevel, &nCharges) || !nCharges)
        {
            return 0;
        }
    }

    if (pUnit != sub_00463DD0_GetPlayerUnit())
    {
        const int nMaxLevel = SPELLSEL_GetSkillMaxLevel(nSkillId);
        if (nSkillLevel > nMaxLevel)
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nMaxLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53A);
            sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nSkillLevel - nMaxLevel);
        }
        else
        {
            SKILLS_AssignSkill(pUnit, nSkillId, nSkillLevel, 0, ".\\SKILLS\\Skills.cpp", 0x53F);
        }
    }
    else
    {
        nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget && !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 26) && CUNIT_IsTargetBlocked(pUnit, pTarget))
    {
        return 0;
    }

    if (!BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 8) && DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        UNITS_SetUsedSkill(pUnit, NULL);
        int aArgs[7] = {};
        sub_00480C10_UnitEvent(7, pUnit, aArgs, 0);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            UNITSND_PlayPlayerSpeech(pUnit, 0x18);
        }
        return 0;
    }

    int nMode;
    if (pUnit && !SKILLCLT_GetUnitTypeByte(pUnit) && !nSkillId)
    {
        nMode = SKILLS_GetAttackMode(pUnit);
    }
    else
    {
        nMode = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
    }

    if (nMode)
    {
        UNITMODE_SetUnitMode(pUnit, nMode);
    }
    else if (!STATES_CheckState(pUnit, STATE_INFERNO) || !BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 11))
    {
        SKILLCLT_SetCastState(pUnit);
    }

    int nResult = 1;
    const short nStartFunc = pSkillsTxtRecord->wStartFunc;
// build: symbol ?gnClientSkillStartFuncs@* 0x00727A8C
    if (nStartFunc >= 0 && nStartFunc < gnClientSkillStartFuncs && gpfnClientSkillStartFuncs[nStartFunc])
    {
        nResult = gpfnClientSkillStartFuncs[nStartFunc](pUnit, nSkillId, nSkillLevel);
        if (!nResult)
        {
            UNITS_SetUsedSkill(pUnit, NULL);
            SKILLCLT_SetCastState(pUnit);
            if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 12))
            {
                goto Done;
            }
        }
    }

    short nSound;
    nSound = pSkillsTxtRecord->wStSound;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemStartSound > 0)
    {
        nSound = pSkillsTxtRecord->wItemStartSound;
    }

    if (nSound > 0)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = UNITS_GetHitClass(pUnit);
            UNITSND_GetAnimRate(pUnit, nDirection);
            const int nDelay = UNITSND_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nSound, pUnit, 0, 0, 0);
        }
    }

    if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 14))
    {
        const int nSoundId = UNITSND_GetDirectionRate(pUnit, UNITS_GetHitClass(pUnit));
        if (nSoundId)
        {
            const int nDirection = UNITS_GetHitClass(pUnit);
            UNITSND_GetAnimRate(pUnit, nDirection);
            const int nRate = UNITSND_GetAnimRate(pUnit, nDirection);
            sub_004B9A00(nSoundId, pUnit, nRate, 0, 0);
        }
    }

    short nClassSound;
    nClassSound = pSkillsTxtRecord->wStartSoundClass;
    if ((nOwnerGUID == -1 || pSkillsTxtRecord->wItemStartSound <= 0) && nClassSound > 0 && (!pUnit ? 6 : pUnit->dwUnitType) == 0 && (!pUnit ? -1 : pUnit->dwClassId) == (unsigned char)pSkillsTxtRecord->nCharClass)
    {
        if (BITARRAY_CHECK(pSkillsTxtRecord->nFlags, 13))
        {
            const int nDirection = UNITS_GetHitClass(pUnit);
            UNITSND_GetAnimRate(pUnit, nDirection);
            const int nDelay = UNITSND_GetAnimRate(pUnit, nDirection) - 3;
            sub_004B9A00(nClassSound, pUnit, nDelay, 0, 0);
        }
        else
        {
            sub_004B9A00(nClassSound, pUnit, 0, 0, 0);
        }
    }

    int nOverlay;
    nOverlay = pSkillsTxtRecord->wCastOverlay;
    if (nOwnerGUID != -1 && pSkillsTxtRecord->wItemCastOverlay > 0)
    {
        nOverlay = pSkillsTxtRecord->wItemCastOverlay;
    }

    if (nOverlay > 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount && !sub_0046E100(pUnit, nOverlay))
    {
        GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    }

Done:
    if (nResult && pSkillsTxtRecord->wAuraFunc > 0)
    {
        sub_004C5680_StartAura(pUnit, pSkillsTxtRecord->wAuraFunc);
    }

    return nResult;
}

// 0x004C6660
int __fastcall SKILLS_CallStartSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID)
{
    return SKILLS_StartClientSkill(nOwnerGUID, nSkillLevel, pUnit, nSkillId);
}

// build: symbol ?ITEM_GetAdjacentPosition@* 0x004C51E0
void __fastcall ITEM_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    const int nDirection = UNITS_GetDirection(pUnit) >> 3;
    int aOffsetX[8] = { 0, -1, -2, -1, 0, 1, 2, 1 };
    int aOffsetY[8] = { 2, 1, 0, -1, -2, -1, 0, 1 };

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
    *pX = aOffsetX[nDirection] + nX;

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
    *pY = aOffsetY[nDirection] + nY;
}

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    int nY;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        int nX;
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pTarget->pStaticPath->tGameCoords.nX;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nX = PATH_GetXPosition(pTarget->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        *pX = nX;

        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pTarget->pStaticPath->tGameCoords.nY;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nY = PATH_GetYPosition(pTarget->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
    }
    else
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    *pY = nY;

    if (!*pX || !nY)
    {
        ITEM_GetAdjacentPosition(pUnit, pX, pY);
    }
    return 1;
}

static inline D2SkillsTxt* GetSkillRecord(int id)
{if(id>=0 && id<sgptDataTables->nSkillsTxtRecordCount)return &sgptDataTables->pSkillsTxt[id];return 0;}

// 0x004C6680
int __fastcall SKILLS_DoClientSkill(D2UnitStrc* unit,int skillId,int skillLevel,int mode)
{
 D2SkillsTxt* skill=GetSkillRecord(skillId);
 if(!skill)return 0;
 if(skill->clientDo<0 || skill->clientDo>=gnClientDoCount)return 0;
 int result=0;
 if(skill->wAuraFunc>0){
  int x=0,y=0,targetX=0,targetY=0;
  if(mode){
   ITEM_GetTargetPosition(unit,&x,&y);
   if(x && y){
    targetX=x;targetY=y;
    x-=CLIENTS_GetUnitX(unit);
    y-=CLIENTS_GetUnitY(unit);
    targetX+=x;targetY+=y;
   }
  }
  D2UnitStrc* missile;
  if(skill->nFlags[0] & (unsigned char)gdwBitMasks[1])
   missile=MISSILE_SubmitOffsetRequest(unit,skill->wAuraFunc,x,y,targetX,targetY,skillId,skillLevel,0);
  else missile=SKILLS_FireMissileAtTarget(skill->wAuraFunc,unit,skillId,skillLevel,x,y,targetX,targetY);
  if(missile)result=1;
  if(unit)unit->dwFlags|=0x40;
 }
 int index=skill->clientDo;
 if(mode && skill->clientDoSecondary>1)index=skill->clientDoSecondary;
 if(index>=0 && index<gnClientDoCount && gaClientDo[index]){
  if(gaClientDo[index](unit,skillId,skillLevel))result=1;
 }else{
  if(unit)unit->dwFlags|=0x40;
  result=1;
 }
 void* resource=D2Common_10958(unit,0);
 if(resource)DLIGHTMAP_ReleaseLight(resource);
 if(!result)return 0;
 if(skill->wDoSound>0)sub_004B9A00(skill->wDoSound,unit,0,0,0);
 if(skill->wTgtSound>0){
  D2UnitStrc* target=CUNIT_GetPathTargetUnit(unit);
  if(target)sub_004B9A00(skill->wTgtSound,target,0,0,0);
 }
 if(skill->wTgtOverlay>0){
  D2UnitStrc* target=CUNIT_GetPathTargetUnit(unit);
  if(target)GFX_AddUnitOverlay(target,skill->wTgtOverlay,2,0,0,0,0,0);
 }
 int delay=SKILLS_EvaluateSkillFormula(unit,skill->dwDelay,skillId,skillLevel);
 if(delay>0 && sub_00463DD0_GetPlayerUnit()==unit){
  if(delay>12)delay=12;
  if(skill->nAnim!=18 || !(unit->dwSeqFrame & 0xffffff00))
   GAME_SetSkillDelayUntil(sub_0044DA90()+delay);
 }
 return 1;
}

// 0x004C68F0
int __fastcall SKILLS_DoUsedSkill(D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 0x697);
    int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    return SKILLS_DoClientSkill(pUnit, nSkillId, nLevel, 0);
}

// 0x004C6930
void __fastcall SKILLS_DoSkillPrgFunc(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, unsigned char nMode)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nOldValue = pUnit->dwInitSeed;
    int nTargetX;
    int nTargetY;
    const int bHasTargetPos = ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY);
    D2UnitStrc* pOldTarget = CUNIT_GetPathTargetUnit(pUnit);

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        pUnit->dwInitSeed = nMode;
    }
    else if (nX && nY)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
        pUnit->dwInitSeed = nMode;
    }

    if (nX && !nY)
    {
        pUnit->dwInitSeed = nX;
    }

    const short nFunc = pSkillsTxtRecord->wCltPrgFunc[0];
// build: symbol ?gnClientSkillDoFuncs@* 0x00727DB0
    if (nFunc >= 0 && nFunc < gnClientSkillDoFuncs && gpfnClientSkillDoFuncs[nFunc]
        && gpfnClientSkillDoFuncs[nFunc](pUnit, nSkillId, nSkillLevel))
    {
        if (pSkillsTxtRecord->wDoSound > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wDoSound, pUnit, 0, 0, 0);
        }

        if (pSkillsTxtRecord->wTgtSound > 0)
        {
            D2UnitStrc* pCurrentTarget = CUNIT_GetPathTargetUnit(pUnit);
            if (pCurrentTarget)
            {
                sub_004B9A00(pSkillsTxtRecord->wTgtSound, pCurrentTarget, 0, 0, 0);
            }
        }

        if (pSkillsTxtRecord->wTgtOverlay > 0)
        {
            D2UnitStrc* pCurrentTarget = CUNIT_GetPathTargetUnit(pUnit);
            if (pCurrentTarget)
            {
                GFX_AddUnitOverlay(pCurrentTarget, pSkillsTxtRecord->wTgtOverlay, 2, 0, 0, 0, 0, 0);
            }
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    if (bHasTargetPos && !pOldTarget)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nTargetX, nTargetY);
    }

    pUnit->dwInitSeed = nOldValue;
}

// 0x004C6AC0
void __fastcall SKILLS_DoSkill(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, int nCharges)
{
    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 0, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wAuraStat[0], nCharges, 0);
    }

    int nTargetX;
    int nTargetY;
    const int bHasTargetPos = ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY);
    D2UnitStrc* pOldTarget = CUNIT_GetPathTargetUnit(pUnit);

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }
    else if (nX && nY)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    }

    const int nOldValue = pUnit->dwInitSeed;
    if (nX && !nY)
    {
        pUnit->dwInitSeed = nX;
    }

    --nCharges;
    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PRGSTACK >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PRGSTACK & 7])
    {
        for (int i = 0; i < nCharges; ++i)
        {
            if (gpfnClientSkillDoFuncs[pSkillsTxtRecord->wCltPrgFunc[i]])
            {
                STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wAuraStat[0], i + 1, 0);
                gpfnClientSkillDoFuncs[pSkillsTxtRecord->wCltPrgFunc[i]](pUnit, nSkillId, nSkillLevel);
            }
        }

        STATLIST_SetStatIfListIsValid(pStatList, pSkillsTxtRecord->wAuraStat[0], nCharges + 1, 0);
    }

    const short nFunc = pSkillsTxtRecord->wCltPrgFunc[nCharges];
    if (nFunc >= 0 && nFunc < gnClientSkillDoFuncs)
    {
        if (pSkillsTxtRecord->wAuraFunc > 0)
        {
            if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_LOB >> 3] & gdwBitMasks[SKILLSFLAGINDEX_LOB & 7])
            {
                int nMissileX;
                int nMissileY;
                ITEM_GetTargetPosition(pUnit, &nMissileX, &nMissileY);
                MISSILE_SubmitOffsetRequest(pUnit, pSkillsTxtRecord->wAuraFunc, 0, 0, nMissileX, nMissileY, nSkillId, nSkillLevel, 0);
            }
            else
            {
                AUTOMAP_RequestAtTarget(pUnit, pSkillsTxtRecord->wAuraFunc, nSkillId, nSkillLevel);
            }

            pUnit->dwFlags |= 0x40;
        }

        if (gpfnClientSkillDoFuncs[pSkillsTxtRecord->wCltPrgFunc[nCharges]])
        {
            if (gpfnClientSkillDoFuncs[pSkillsTxtRecord->wCltPrgFunc[nCharges]](pUnit, nSkillId, nSkillLevel))
            {
                if (pSkillsTxtRecord->wDoSound > 0)
                {
                    sub_004B9A00(pSkillsTxtRecord->wDoSound, pUnit, 0, 0, 0);
                }

                if (pSkillsTxtRecord->wTgtSound > 0)
                {
                    D2UnitStrc* pCurrentTarget = CUNIT_GetPathTargetUnit(pUnit);
                    if (pCurrentTarget)
                    {
                        sub_004B9A00(pSkillsTxtRecord->wTgtSound, pCurrentTarget, 0, 0, 0);
                    }
                }

                if (pSkillsTxtRecord->wTgtOverlay > 0)
                {
                    D2UnitStrc* pCurrentTarget = CUNIT_GetPathTargetUnit(pUnit);
                    if (pCurrentTarget)
                    {
                        GFX_AddUnitOverlay(pCurrentTarget, pSkillsTxtRecord->wTgtOverlay, 2, 0, 0, 0, 0, 0);
                    }
                }
            }
        }
        else
        {
            pUnit->dwFlags |= 0x40;
        }
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    if (bHasTargetPos)
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nTargetX, nTargetY);
    }

    if (nX && !nY)
    {
        pUnit->dwInitSeed = nOldValue;
    }
}

// 0x004C6DE0
static void __stdcall SKILLS_SwapDualWieldSkill(D2ClientSkillArgsStrc* pArgs, D2UnitStrc* pUnit)
{
    if (pArgs->nSkillId != 0)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightHand = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pRightHand && (!ITEMS_CanBeEquipped(pRightHand) || ITEMS_GetItemType(pRightHand) == ITEMTYPE_MISSILE_POTION))
    {
        pRightHand = NULL;
    }

    D2UnitStrc* pLeftHand = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pLeftHand && (!ITEMS_CanBeEquipped(pLeftHand) || ITEMS_GetItemType(pLeftHand) == ITEMTYPE_MISSILE_POTION))
    {
        pLeftHand = NULL;
    }

    if (ITEMSIsA(pRightHand, 0x2D) && ITEMSIsA(pLeftHand, 0x2D))
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
        if (!SKILLS_GetParam4(pSkill))
        {
            pArgs->nSkillId = 5;
            SKILLS_SetParam4(pSkill, 5);
            pSkill = SKILLS_GetSkillById(pUnit, SKILL_LEFTHANDSWING, -1);
        }
        else
        {
            SKILLS_SetParam4(pSkill, 0);
        }

        UNITS_SetUsedSkill(pUnit, pSkill);
    }
}

// 0x004C6EB0
int __fastcall SKILLS_StartSkillOnUnit(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    if (UNITS_CanDualWield(pUnit) && (!pUnit || pUnit->dwUnitType != UNIT_MONSTER))
    {
        SKILLS_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2UnitStrc* pTarget = CUNIT_FindClientUnit(pArgs->nArg2, pArgs->nArg1);
    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        sub_00465BF0(pUnit, 0);
        return SKILLS_StartClientSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
    }

    sub_00480C10_UnitEvent(7, pUnit, NULL, 0);
    sub_006248E0_Log(1, 2, 4, 0x40, ".\\SKILLS\\Skills.cpp", 0x7C2, "StartsStartSkillID - Invalid Target");
    return 0;
}

// 0x004C6F40
int __fastcall SKILLS_StartSkillAtPos(D2UnitStrc* pUnit, D2ClientSkillArgsStrc* pArgs)
{
    const int nX = pArgs->nArg1;
    const int nY = pArgs->nArg2;
    if (UNITS_CanDualWield(pUnit))
    {
        SKILLS_SwapDualWieldSkill(pArgs, pUnit);
    }

    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    sub_00621C00_SetTargetPos(pUnit, nX, nY);
    D2MonStatsTxt* pMonStatsTxtRecord = NULL;
    const int nType = pUnit->dwUnitType;
    if (nType == 1)
    {
        pMonStatsTxtRecord = SKILLCLT_GetMonStatsTxtRecord(pUnit->dwClassId);
    }
    else if (nType == 0)
    {
        pMonStatsTxtRecord = NULL;
    }

    if (pMonStatsTxtRecord && pMonStatsTxtRecord->dwCode == 0x20204250)
    {
        D2PathDirectionStrc tDirection;
        tDirection.nDirection = (PATH_GetNewDirection(pUnit->pDynamicPath) + 0x38) % 64;
        D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, tDirection);
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, NULL);
    return SKILLS_StartClientSkill(pArgs->nOwnerGUID, pArgs->nSkillLevel, pUnit, pArgs->nSkillId);
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004C7000
static void __stdcall SKILLS_SpawnRing(D2MissileStrc* pAltParams, D2MissileStrc* pParams)
{
    if (pAltParams)
    {
        for (int i = 0; i < 64; ++i)
        {
            if (SEED_RollRandomNumber(&pParams->pOwner->pSeed) % 6)
            {
                pParams->nTargetX = gaRingTargetX[i];
                pParams->nTargetY = gaRingTargetY[i];
                MISSILE_CreateClientMissile(pParams);
            }
            else
            {
                pAltParams->nTargetX = gaRingTargetX[i];
                pAltParams->nTargetY = gaRingTargetY[i];
                MISSILE_CreateClientMissile(pAltParams);
            }
        }
    }
    else
    {
        for (int i = 0; i < 64; ++i)
        {
            pParams->nTargetX = gaRingTargetX[i];
            pParams->nTargetY = gaRingTargetY[i];
            if (pParams->nMissile == MISSILE_DIABFIRE)
                pParams->dwFlags ^= 0x4000;
            MISSILE_CreateClientMissile(pParams);
        }
    }
}

// 0x004C70D0
void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nAltMissile,
    int nSkill, int nSkillLevel, int nVelocity)
{
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.nX = UNITS_GetUnitXPosition(pUnit);
    tParams.nY = UNITS_GetUnitYPosition(pUnit);
    tParams.nMissile = nMissile;
    tParams.pOwner = pOwner;
    tParams.nSkill = nSkill;
    tParams.nSkillLevel = nSkillLevel;
    if (nVelocity)
    {
        tParams.dwFlags |= 4;
        tParams.nVelocity = nVelocity;
    }
    if (nAltMissile == -1)
    {
        SKILLS_SpawnRing(0, &tParams);
        return;
    }
    D2MissileStrc tAltParams = tParams;
    tAltParams.nMissile = nAltMissile;
    SKILLS_SpawnRing(&tAltParams, &tParams);
}

// 0x004C71F0
void __fastcall SKILLS_CreateSpiralMissiles(int nCount, D2MissileStrc* pMissileParams)
{
    D2_ASSERT((nCount - 1) / 5 <= 7, 0x848);

    pMissileParams->nTargetX = 14;
    pMissileParams->nTargetY = -14;
    MISSILE_CreateClientMissile(pMissileParams);

    int nRemaining = nCount - 1;
    for (int i = 0; i < 7; i++)
    {
        if (!nRemaining)
        {
            break;
        }

        for (int j = 0; j < 4 && nRemaining > 0; j++)
        {
            pMissileParams->nTargetX = gaSpiralInnerX[j] * gaSpiralOuterA[i];
            pMissileParams->nTargetY = gaSpiralInnerY[j] * gaSpiralOuterB[i];
            MISSILE_CreateClientMissile(pMissileParams);
            pMissileParams->nTargetX = gaSpiralInnerX[j] * gaSpiralOuterB[i];
            pMissileParams->nTargetY = gaSpiralInnerY[j] * gaSpiralOuterA[i];
            MISSILE_CreateClientMissile(pMissileParams);
            nRemaining -= 2;
        }

        pMissileParams->nTargetX = gaSpiralOuterX[i];
        pMissileParams->nTargetY = gaSpiralOuterY[i];
        MISSILE_CreateClientMissile(pMissileParams);
        nRemaining -= 1;
    }
}

inline D2StatesTxt* SKILLS_GetStatesTxtRecord(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x004C72F0
void __fastcall SKILLS_RunStateActiveFuncs(D2UnitStrc* pUnit)
{
    if (!sub_0063A340(pUnit))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nActionStates; ++i)
    {
        const short nState = sgptDataTables->pActionStates[i];
        if (STATES_CheckState(pUnit, nState))
        {
            D2StatesTxt* pStatesTxtRecord = SKILLS_GetStatesTxtRecord(nState);
            if (pStatesTxtRecord && pStatesTxtRecord->wCltActiveFunc >= 0 && pStatesTxtRecord->wCltActiveFunc < gnClientSkillDoFuncs
                && gpfnClientSkillDoFuncs[pStatesTxtRecord->wCltActiveFunc])
            {
                int nA = 0;
                int nB = 1;
                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
                if (pStatList)
                {
                    nA = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                    nB = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
                }
                gpfnClientSkillDoFuncs[pStatesTxtRecord->wCltActiveFunc](pUnit, nA, nB);
            }
        }
    }
}

// 0x004C7400
D2UnitStrc* __fastcall SKILLS_CreateTargetedMissile(D2UnitStrc* pUnit, int nMissile, int nSkill, int nSkillLevel,
    int nTargetX, int nTargetY)
{
    D2UnitStrc* pResult;
    if ((nTargetX && nTargetY) || (pResult = sub_004C52E0(pUnit, &nTargetX, &nTargetY)) != 0)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 1;
        tMissileParams.pOwner = pUnit;
        tMissileParams.nX = nTargetX;
        tMissileParams.nY = nTargetY;
        tMissileParams.nSkill = nSkill;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        pResult = MISSILE_CreateClientMissile(&tMissileParams);
    }
    return pResult;
}

// 0x004C7470
void __fastcall SKILLS_SetMissileDirection(D2UnitStrc* pMissile, int nDirection)
{
    sub_006488A0_SetDirection(pMissile->pDynamicPath, nDirection);
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x004C7480
void __fastcall SKILLS_SpawnMissileRing(D2UnitStrc* pUnit, D2MissileStrc* pMissileParams, int nRange, int nCount)
{
    int nDirection = SEED_RollRandomNumber(&pUnit->pSeed) & 3;
    const int nX = pMissileParams->nX;
    const int nY = pMissileParams->nY;
    for (int i = 0; i < nCount; ++i)
    {
        int nOffsetX;
        int nOffsetY;
        switch (nDirection)
        {
        case 0:
            nOffsetX = -16;
            nOffsetY = -16;
            break;
        case 1:
            nOffsetX = -16;
            nOffsetY = 16;
            break;
        case 2:
            nOffsetX = 16;
            nOffsetY = 16;
            break;
        case 3:
            nOffsetX = 16;
            nOffsetY = -16;
            break;
        default:
            nOffsetX = 0;
            nOffsetY = 0;
            break;
        }

        nDirection = (nDirection + 1) % 4;
        pMissileParams->nX = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, 2 * nRange) - nRange + nX;
        pMissileParams->nY = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, 2 * nRange) - nRange + nY;
        pMissileParams->nTargetX = pMissileParams->nX + nOffsetX;
        pMissileParams->nTargetY = pMissileParams->nY + nOffsetY;
        pMissileParams->pInitFunc = SKILLS_SetMissileDirection;
        pMissileParams->nInitArg = nDirection << 4;
        MISSILE_CreateClientMissile(pMissileParams);
    }
}

// 0x004C7630
int __fastcall SKILLS_RaiseTargetUnitEvent(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    int args[7];
    memset(args, 0, sizeof(args));
    args[0] = 0;
    args[1] = -1;
    int nType = 6;
    if (pTarget)
    {
        nType = pTarget->dwUnitType;
    }
    args[2] = nType;
    int nId;
    if (!pTarget)
    {
        nId = -1;
    }
    else
    {
        nId = pTarget->dwUnitId;
    }
    args[3] = nId;
    args[4] = 1;
    sub_00480C10_UnitEvent(0x16, pUnit, args, 1);
    return 1;
}

// 0x004C76A0
int __fastcall VIEW_GetWeaponClassMask(D2UnitStrc* pUnit)
{
    int nWeaponClassId = 0;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClassId, -1, 1);
    return nWeaponClassId == WEAPONCLASS_XBW ? 0x1F : 0;
}


// 0x004C76D0
void __fastcall SKILLS_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent)
{
    pUnit->nSeqCurrentFramePrecise = (pUnit->nSeqCurrentFramePrecise >> 8) * (100 - nPercent) / 100 << 8;
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

// 0x004C7700
int __fastcall SKILLS_ScatterRequestsAroundTarget(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pMissile, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, nTargetX);
    for (int i = 0; i < nCount; ++i)
    {
        const int nX = SEED_RollLimitedRandomNumberInline(pSeed, 2 * nRange) - nRange + nTargetX;
        const int nY = SEED_RollLimitedRandomNumberInline(pSeed, 2 * nRange) - nRange + nTargetY;
        if (sub_006492A0(CLIENTS_GetUnitXInline(pMissile), CLIENTS_GetUnitYInline(pMissile), nX, nY) >= 4)
        {
            MISSILE_SubmitOffsetRequest(pMissile, nMissile, 0, 0, nX, nY, nSkill, nSkillLevel, 0);
        }
    }

    return 1;
}

// 0x004C7950
void __fastcall SKILLS_AttachMoveSkillEndList(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 6, 0x32, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_HandleMoveSkillEnd);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }
}

// 0x004C7890
void __fastcall SKILLS_HandleMoveSkillEnd(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;
    if (STATES_CheckState(pUnit, STATE_SKILL_MOVE))
        return;
    if (SKILLS_GetFlags(pSkill) & 2)
        return;
    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\Skills.cpp", 2365);
    D2SkillsTxt* pSkillsTxt = GetSkillRecord(nSkillId);
    if (!pSkillsTxt)
        return;
    switch (pSkillsTxt->wSrvDoFunc)
    {
    case 67:
        SKILLS_EndCharge(pUnit, nSkillId);
        break;
    case 77:
    case 78:
        SKILLSBAR_ResetLeapCollision(pUnit);
        break;
    case 76:
        SKILLS_EndLoopSoundSkill(pUnit, nSkillId);
        break;
    }
}

static inline D2SkillDescTxt* SKILLCLT_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
    {
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    }
    return 0;
}

static inline D2SkillDescTxt* sub_004C7990_GetSkillDescFromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return SKILLCLT_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
}

// 0x004C7990
void __fastcall SKILLS_ApplySkillLevelBonus(D2UnitStrc* pUnit, int nA, int nB, unsigned char nC)
{
    D2_ASSERT(pUnit, 2410);
    D2_ASSERT(nA, 2411);
    D2_ASSERT(pUnit->pSkills, 2413);

    int nSkillId;
    D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pUnit->pSkills);
    while (pSkill)
    {
        D2SkillStrc* pNextSkill = SKILLS_GetNextSkill(pSkill);
        D2SkillsTxt* pSkillsTxtRecord = SKILLCLT_GetSkillsTxtRecord(nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillsCppFile, 2420));
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        D2SkillDescTxt* pSkillDescTxtRecord = sub_004C7990_GetSkillDescFromSkillId(nSkillId);
        if (!pSkillDescTxtRecord)
        {
            continue;
        }

        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 0 && SKILLS_IsEnhanceable(nSkillId)
            && (!nB || pSkillsTxtRecord->nEType == nB)
            && (nC == 4 || pSkillDescTxtRecord->nSkillPage == nC + 1)
            && SKILLS_GetOwnerGUIDFromSkill(pSkill) == -1)
        {
            D2Common_11031(pUnit, nSkillId, nA);

            D2SkillStrc* pUnitSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pUnitSkill && !SKILLS_GetSkillLevel(pUnit, pUnitSkill, 1))
            {
                SKILLS_RemoveSkill(pUnit, nSkillId, gszSkillsCppFile, 2465);
            }
        }

        pSkill = pNextSkill;
    }

    SKILLS_RefreshPassiveSkills(pUnit);
}

// 0x004C7B20
int __fastcall SKILLS_IsTargetPosClear(D2UnitStrc* pUnit, int nMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    int nTargetX = 0;
    int nTargetY = 0;

    D2_ASSERT(pMissilesTxtRecord, 0x9BF);

    if (!pRoom)
    {
        return 0;
    }

    sub_004C52E0(pUnit, &nTargetX, &nTargetY);
    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    return !COLLISION_CheckMaskWithSizeXY(pRoom, nTargetX, nTargetY, pMissilesTxtRecord->nSize, pMissilesTxtRecord->nSize, 5);
}

// 0x004C7BD0
int __fastcall SKILLS_GetExtendedMeleeRange(D2UnitStrc* pUnit)
{
    return UNITS_GetMeleeRange(pUnit) + 4;
}

// 0x004C7BE0
void __fastcall SKILLS_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 4, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (pStatList)
    {
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, STAT_ATTACKRATE, nValue, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\Skills.cpp", 0x9E5);
    }
}

extern void* gpfnClientStateEvents[2]; // 0x00727DB4

int __fastcall sub_004DC110(void* pArg1, int nArg2, int nArg3, int nArg4, void* pfnCallback, int nArg6, int nArg7); // 0x004DC110

// 0x004C7C40
int __fastcall SKILLS_CallClientStateEvent(void* pArg1, int nArg2, int nArg3, int nArg4, unsigned int nIndex, int nArg6, int nArg7)
{
    if (nIndex <= 1)
    {
        void* pfnCallback = gpfnClientStateEvents[nIndex];
        if (pfnCallback)
        {
            return sub_004DC110(pArg1, nArg2, nArg3, nArg4, pfnCallback, nArg6, nArg7);
        }
    }

    return 0;
}

// 0x004C7C80
int __cdecl SKILLS_GetMissilesTxtRecordCount()
{
    return sgptDataTables->nMissilesTxtRecordCount;
}

// 0x004C7C90
int __fastcall SKILLS_TestTarget11018(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2COMMON_11018(pTarget) != 0;
}

// 0x004C7CB0
int __fastcall SKILLS_BurstTargetCorpse(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    sub_004AF890(pTarget, 5, 0);
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

// 0x004C7CF0
int __fastcall SKILLS_EvaluateClientSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    SKILLS_ApplyClientSkillCalc(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    return 1;
}

// 0x004C7D50
int __fastcall SKILLS_LeapToTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if ((pUnit->dwSeqFrame & ~0xFF) < 0x600)
    {
        sub_004B9A00(UNITSND_GetDirectionRate(pUnit, UNITS_GetHitClass(pUnit)), pUnit, 4, 0, 0);
        D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
        if (pTarget && pUnit->pDynamicPath)
        {
            D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        }
        return 1;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    int nUnitId = -1;
    if (pTarget)
    {
        nUnitId = pTarget->dwUnitId;
    }
    D2UnitStrc* pDest = sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 0, nUnitId, 0);
    if (pDest && pUnit->pDynamicPath)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pDest), CLIENTS_GetUnitY(pDest), 0);
    }
    return 1;
}

// 0x004C7E10
int __fastcall SKILLS_FireWeaponMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pItem = sub_00623990_GetWeapon(pUnit, 1);
    if (!pItem)
    {
        return 0;
    }

    ITEMS_CheckIfThrowable(pItem);
    if ((pUnit->dwSeqFrame & ~0xFF) >= 0x900)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!ITEMS_CheckIfThrowable(pItem) && STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0))
    {
        return 0;
    }

    const int nMissile = ITEMS_GetMissileType(pItem);
    if (nMissile <= 0)
    {
        return 0;
    }

    if (nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (ITEMSIsA(pItem, 0x26))
    {
        if (!MISSILE_SubmitOffsetRequest(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0))
        {
            return 0;
        }
    }
    else
    {
        sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
    }
    return 1;
}

// 0x004C7EE0
int __fastcall SKILLS_TestTarget11019(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return D2COMMON_11019(pTarget) != 0;
}

// 0x004C7F00
int __fastcall SKILLS_BurstSoftTargetCorpse(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!UNITS_IsSoftMonster(pTarget))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    sub_004AF890(pTarget, 5, 0);
    return 1;
}

// 0x004C7F50
int __fastcall SKILLS_SpawnPairAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!UNITS_IsSoftMonster(pTarget))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2CoordStrc tCoord;
    tCoord.nX = CLIENTS_GetUnitX(pTarget);
    tCoord.nY = CLIENTS_GetUnitY(pTarget);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, tCoord.nX, tCoord.nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!COLLISION_GetFreeCoordinates(pRoom, &tCoord, 2, 0x1000, 1))
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nFlags[1] & gnBitMasks_006CE268[3])
    {
        nMissile = pSkillsTxtRecord->wCltMissileC;
    }
    else if (pMonStats2TxtRecord->nFlags[1] & gnBitMasks_006CE268[2])
    {
        nMissile = pSkillsTxtRecord->wCltMissileB;
    }

    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x2001;
        tMissileParams.pOwner = pUnit;
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        tMissileParams.nX = tCoord.nX;
        tMissileParams.nY = tCoord.nY;
        MISSILE_CreateClientMissile(&tMissileParams);
        tMissileParams.nMissile = MISSILE_CORPSEEXPLOSION;
        MISSILE_CreateClientMissile(&tMissileParams);
        return 1;
    }

    return 0;
}

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall D2Common_11025(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

inline int UNITS_GetXInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYInline(D2UnitStrc* pUnit)
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

static inline D2UnitStrc* sub_004C9D50_FindDestinationById(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 3, nUnitId, 0);
}

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970


static inline int sub_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static inline int sub_GetUnitGUIDChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

D2UnitStrc* __fastcall sub_M109_Emit_004C9D50(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C9D50_FindDestinationById(pUnit, nUnitId + 1);
}

// 0x004D16C0
void __fastcall SKILLS_SpawnOffsetMissile(int nUnitId, int nUnused, D2UnitStrc* pMissile, D2UnitStrc* pOwner)
{
    D2UnitStrc* pFound = CUNIT_FindClientUnit(nUnitId, 2);
    if (!pFound)
    {
        return;
    }

    const int nOffsetX = UNITS_GetUnitXPosition(pMissile) - UNITS_GetUnitXPosition(pFound);
    const int nOffsetY = UNITS_GetUnitYPosition(pMissile) - UNITS_GetUnitYPosition(pFound);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pOwner;
    tMissileParams.pOrigin = pMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissileParams.nMissile = MISSILE_HFSPIRIT1;

    D2UnitStrc* pNewMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pNewMissile)
    {
        sub_004DA000(pNewMissile);
        GFXUTIL_SetMotionVectorA(pNewMissile, 0, 0, 0);
        GFXUTIL_SetMotionVectorB(pNewMissile, 0, 0, 2, 1);
        sub_004DA250(pNewMissile, 0, 0, 0, 1);
        MISSILE_SetTargetX(pNewMissile, nOffsetX);
        MISSILE_SetTargetY(pNewMissile, nOffsetY);
    }
}

int __fastcall MISSILE_SkillStartAtTargetPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004C95E0

int __fastcall sub_004C96D0(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004C96D0

int __fastcall SKILLS_CltDoCharge(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004C9DB0

int __fastcall sub_004CA030_TickEvent(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004CA030

#include "gen/data/Source/D2Client/SKILLS/Skills.inc"
