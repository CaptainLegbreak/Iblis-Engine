#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2ClientGame.h"
#include "D2Records.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2Drlg.h"
#include "D2Constants.h"
#include "D2DrlgMaps.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"
#include "D2ClientGfx.h"
#include "D2ClientTypes.h"
#include "D2LevelIds.h"
#include "D2SoundEnvironTxt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2GfxLightStrc;

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2MissilesTxt;

struct D2StatesTxt;

struct D2MissileStrc;

struct D2UnitSfxNodeStrc;

struct D2SetItemsTxt;

union D2SeedStrc;

struct D2CltUnitEventStrc;

struct D2CltRateStrc;

struct D2CltMissileFindArgStrc;

struct D2CltMissileModeStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2CoordStrc;

struct D2ItemsTxt;

struct D2PathPointStrc;

struct D2ScatterRateStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390

void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern const int gaEffectRingOffsetY[16]; // 0x006DAF08

extern const int gaEffectRingOffsetX[16]; // 0x006DAF48

extern int gnScreenWidth; // 0x0071146C

extern void* gpGlobal_007A0634; // 0x007A0634

extern unsigned int gdwFadeTick; // 0x007C89CC

int __cdecl sub_0044DB00(); // 0x0044DB00

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall sub_00474470_ReleaseLight(D2GfxLightStrc* pLight); // 0x00474470

int __fastcall SOUNDHDR_GetGroupStart(int nId); // 0x00481890

unsigned char __fastcall SOUNDHDR_GetGroupSize(int nId); // 0x004818C0

int __fastcall TEXT_TestQuestCondition(int nCondition); // 0x004A4180

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __cdecl SOUNDINST_IsSpeechPlaying(); // 0x004B9C20

int __fastcall SOUNDINST_GetSoundIdByHandle(void* pKey); // 0x004B9CA0

void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790

int __fastcall SKILLS_CallStartSkill(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode); // 0x004C6660

int __fastcall SKILLS_DoClientSkill(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode); // 0x004C6680

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nId); // 0x004CB9C0

D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

int __cdecl sub_004DF880(); // 0x004DF880

int __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pItem, int nArg1, int nArg2, int nArg3, int nProp, int nArg5, int nArg6, int nArg7); // 0x004E60A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2GfxLightStrc* __stdcall UNITS_ResetLightMap(D2UnitStrc* pUnit); // 0x00621150

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

void __fastcall MISSILE_SpawnPeriodicMissile(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile, int nFrame, int nCount); // 0x004CE850

void __fastcall MISSILE_DispatchSubMissileSpawn(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile, int nFrame); // 0x004CECC0

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

int __fastcall CUNIT_IsPetSkillTarget(D2UnitStrc* unit, D2UnitStrc* target); // 0x00464EC0

int __fastcall CUNIT_IsTargetBlocked(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00464F70

struct D2CltRateStrc
{
    int nThreshold;
    int nRate;
    int nValue;
};

extern const D2CltRateStrc gaCltRateTable[6]; // 0x006DB848

extern const int gaQuadOffsetY[4]; // 0x006DB7D0

extern const int gaQuadOffsetX[4]; // 0x006DB7E0

extern const int gaCltDoRingOffsetY[64]; // 0x006DB5D0

extern const int gaCltDoRingOffsetX[64]; // 0x006DB6D0

void __fastcall MISSILE_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CEF50

void __fastcall MISSILE_CltDoRandomTrail(D2UnitStrc* pMissile); // 0x004D3630

void __fastcall MISSILE_CltDoSeekTarget(D2UnitStrc* pMissile); // 0x004D37F0

void __fastcall MISSILE_CltDoOwnerStep(D2UnitStrc* pMissile); // 0x004D3070

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile); // 0x0064A780

void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nState); // 0x0063A7B0

D2UnitStrc* __stdcall INVENTORY_GetCompositItem(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063C050

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY); // 0x00650C20

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall GFXUTIL_GetMotionFirstParam(D2UnitStrc* pUnit); // 0x004DA320

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection); // 0x006488A0

int __stdcall sub_0064A3E0_GetMissileClassId(D2UnitStrc* pMissile); // 0x0064A3E0

int __stdcall sub_0064A510_GetSubMissile(D2UnitStrc* pMissile); // 0x0064A510

int __stdcall sub_0064A570_GetSubMissileCount(D2UnitStrc* pMissile); // 0x0064A570

int __stdcall GFXUTIL_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int __fastcall SKILLS_ScatterRequestsAroundTarget(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel); // 0x004C7700

void __fastcall MISSILE_SpawnRingAround(D2UnitStrc* pMissile, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CE140

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

struct D2CltMissileFindArgStrc
{
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    D2MissilesTxt* pMissilesTxtRecord;
};

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

struct D2CltMissileModeStrc
{
    D2UnitFindCallback pfUnitFindCallback;
    int nCollisionMask;
};

extern D2CltMissileModeStrc gaCltMissileModes[]; // 0x0072A350

int __stdcall sub_0064A640(D2UnitStrc* pMissile); // 0x0064A640

int __stdcall GFXUTIL_TestMotionFlags(D2UnitStrc* pUnit); // 0x004DA6B0

void __stdcall D2COMMON_10375_UNITS_SetFrameNonRate(D2UnitStrc* pUnit, int nRate, int nFailRate); // 0x00621330

int __cdecl GAME_GetPathFrame(); // 0x0044DB10

void __stdcall sub_00650840(D2UnitStrc* pUnit, int nValue); // 0x00650840

unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0

int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc** ppPathPoints); // 0x00648F40

D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0

extern int gnAutomapWidth; // 0x007A5220

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810

void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930

D2UnitStrc* __fastcall MISSILE_SpawnAtRandomUnitInRange(D2UnitStrc* pMissile, int nArg1, int nArg2, int nMissile); // 0x004CE320

void __fastcall MISSILE_InitCltParamMotion(D2UnitStrc* pMissile); // 0x004CE420

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

extern const D2CltRateStrc gaCltRateJitter[4]; // 0x006DB890

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pUnit); // 0x0064A210

extern "C" int __stdcall sub_0064A280(D2UnitStrc* pUnit); // 0x0064A280

extern "C" int __stdcall sub_0064A380(D2UnitStrc* pUnit); // 0x0064A380

extern "C" int __stdcall MISSILE_targetValue(D2UnitStrc* pMissile); // 0x0064A780

struct D2ScatterRateStrc
{
    int nFrames;
    int nRateA;
    int nRateB;
};

extern const D2ScatterRateStrc gaScatterRates[4]; // 0x006DB8CC

typedef void (__fastcall* D2CltDoFunc)(D2UnitStrc* pMissile);

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern D2CltDoFunc gpfnCltDoFuncs[]; // 0x0072A398

int __fastcall DLIGHTMAP_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350

void __fastcall DLIGHTMAP_SetLightSize(D2GfxLightStrc* pLight, int nSize); // 0x00474290

int __fastcall ROSTERPETS_FindRosterIndex(int nUnitId); // 0x00479150

enum
{
    CLTDO_TIMING_FRAME = 150,
    CLTDO_TIMING_ARG = 25,
    CLTDO_TIMING_LENGTH = 4000,
    CLTDO_SOUND_FRAME = 50,
    CLTDO_SOUND_ID = 0x121E,
    CLTDO_SLOW_FRAME = 8,
    CLTDO_FAST_FRAME = 0x23,
    CLTDO_SLOW_FLAG = 0x100,
};

typedef char cc_M439_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

typedef char cc_M338_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

void __fastcall MISSILE_SpawnFollowUp(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3);             // 0x004CE050

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall SKILLS_CreateSpiralMissiles(int nCount, D2MissileStrc* pMissileParams); // 0x004C71F0

void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused); // 0x004CCCC0

extern const int gaCltHitRingOffsetY[8];                                                                 // 0x006DAF88

extern const int gaCltHitRingOffsetX[8];                                                                 // 0x006DAFA8

void __stdcall GFXUTIL_SetMotionParams(D2UnitStrc* pUnit, int nParam0, int nParam1);                   // 0x004DA2F0

void __fastcall GFXUTIL_ClearMotionFlagTwo(D2UnitStrc* pMissile);                                                         // 0x004DA340

void __fastcall GFXUTIL_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0

void __fastcall sub_004E2ED0_VolleyCallback(D2UnitStrc* pMissile);                                          // 0x004E2ED0

struct D2RequestStrc;

struct D2MissileScanArgStrc;

struct D2SpawnOffsetMissileView;

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    D2UnitStrc* pOtherUnit;
    int unk0x0C;
    int nArg0;
    int nArg1;
    int nArg2;
    int nArg5;
    int nArg6;
    int nArg7;
    int unk0x28;
    int nArg3;
    int nArg4;
    int unk0x34[8];
    void* pfCallback;
    int nIndex;
};

D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540

int __stdcall sub_006488C0_PathGetX(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall sub_00648900_PathGetY(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pPath, int bClear); // 0x00649030

struct D2MissileScanArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pMissile;
    int nSkillId;
    int nSkillLevel;
    int nMaxHits;
    int nSubMissile;
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

int __fastcall SKILLS_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40

int __fastcall MISSILE_HitScanCallback(void* pArg, D2UnitStrc* pUnit); // 0x004CFFA0

extern "C" int __stdcall MISSILE_GetMissileTargetStatus(D2UnitStrc* pMissile); // 0x0064A730

struct D2SpawnOffsetMissileView
{
    void __thiscall SKILLS_SpawnOffsetMissile(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x004D16C0
};

void __cdecl GFXUTIL_DrawFadeBox(); // 0x004DC000

struct D2CltHitPatternStrc
{
    int nCount;
    int aIndex[4];
};

extern const int gaCltHitOffsetX[8];                                                               // 0x006DAFC8

extern const int gaCltHitOffsetY[8];                                                               // 0x006DAFE8

extern const D2CltHitPatternStrc gaCltHitPatterns[3];                                              // 0x006DB008

void __fastcall MISSILE_SpawnMissilesInRange(D2UnitStrc* pUnit, const int* pArg, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004CDDB0

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections);                            // 0x00649EF0

extern const int gaCollisionBurstMissiles[]; // 0x0072A33C

void __fastcall MISSILE_InitMotion(D2UnitStrc* pMissile);                                              // 0x004CE4B0

D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile);                                             // 0x0064A3B0

unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                 // 0x00650E50

extern "C" const char gszMissileFile_006DAEF4[]; // 0x006DAEF4

void __stdcall GFXUTIL_ReplaceMotionFlag1With8(D2UnitStrc* pUnit); // 0x004DA690

void __fastcall MISSILE_CltDoFallingSpawn(D2UnitStrc* pMissile); // 0x004D66E0

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }
    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

void __fastcall MISSILE_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nOuterStep, int nInnerStep, int nLoops); // 0x004CEFE0

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
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

void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0

void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0

static inline unsigned __int64 SEED_RollRandomNumber64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static inline unsigned __int64 SEED_RollNextHL_Inline(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

D2UnitStrc* __fastcall SKILLS_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

void __stdcall MISSILE_SetOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x0064A400

extern const int gaRing5OffsetX[]; // 0x006DB0EC

extern const int gaRing5OffsetY[]; // 0x006DB0D8

extern const int gaRing18OffsetX[]; // 0x006DB090

extern const int gaRing18OffsetY[]; // 0x006DB048

#define UNIT_ALIGNMENT_GOOD 2

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

inline int UNITS_IsValidTargetInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 3) & 1;
    return bResult;
}

inline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 2) & 1;
    return bResult;
}

void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall PATH_AllocDynamicPath(int nArg1, int nArg2, int nArg3, int nArg4, D2UnitStrc* pUnit, int nArg6); // 0x00649D00

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648C30

// 0x004CC800
static int __stdcall MISSILE_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
{
    if (!pRoom)
    {
        return 0;
    }

    if (nOffsetX * nOffsetX + nOffsetY * nOffsetY > nMaxDistanceSq)
    {
        return 0;
    }

    D2CoordStrc begin;
    begin.nX = nX;
    begin.nY = nY;
    D2CoordStrc end;
    end.nX = nX + nOffsetX;
    end.nY = nY + nOffsetY;
    return !COLLISION_RayTrace(pRoom, &begin, &end, 4);
}

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

struct D2StormPhaseStrc { int nFrameLimit,nPeriod,bSpawn; };

extern D2StormPhaseStrc gaBaalStormPhases[5]; // 0x006DB908

int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc*); // 0x0064A380

D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc*,int,int); // 0x0065A620

static inline int MISSILE_RollInRange(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMin < nMax)
    {
        return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
    }

    return nMin;
}

struct D2StatListStrc;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

typedef int (__fastcall* CLTHITFUNC)(D2UnitStrc* pMissile, D2UnitStrc* pTarget);

extern "C" unsigned char gbChargeMissileMask_006CE270;                                                     // 0x006CE270

extern int gnCltHitFuncCount;                                                                      // 0x0072A504

extern CLTHITFUNC gpfnCltHitFuncs[];                                                                // 0x0072A508

void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00

void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId);                               // 0x004CA900

void __fastcall MISSILE_StatRemoveToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004CD380

int __stdcall GFXUTIL_GetMotionAX(D2UnitStrc* pUnit);                                             // 0x004DA110

int __stdcall GFXUTIL_GetMotionAY(D2UnitStrc* pUnit);                                             // 0x004DA130

void __stdcall GFXUTIL_SetMotionFlag1(D2UnitStrc* pUnit);                                              // 0x004DA640

int __fastcall CUNITEVENT_RunCltUnitEvents(int nType, D2UnitStrc* pUnit, D2UnitStrc* pOther, int nArg);   // 0x004DC210

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

int __stdcall sub_0064A3E0(D2UnitStrc* pMissile);                                                         // 0x0064A3E0

int __stdcall MISSILE_CheckUnitIfOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit);                           // 0x0064A470

static inline int UNITS_TestFlagBit(D2UnitStrc* pUnit, int nBit)
{
    if (pUnit)
    {
        return (pUnit->dwFlags >> nBit) & 1;
    }
    return 0;
}

extern D2DataTablesStrc* sgptDataTables_00744304; // 0x00744304

extern const unsigned char gbFlagMask_006CE270; // 0x006CE270

static int MISSILE_UseCharge(D2UnitStrc* pUnit); // 0x004CD310

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode);  // 0x00466730

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

void __fastcall MONSTER_RunUModMissileCallbacks(D2UnitStrc* pUnit, void* pArg);                                                // 0x004ADE80

void __fastcall sub_004BA840(void* pUnitSfx);                                                                 // 0x004BA840

void __fastcall ITEM_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY);                      // 0x004C51E0

D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(void* pAct, int nX, int nY);                             // 0x00619DA0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, void* pGame);       // 0x00626D40

static void __stdcall MISSILE_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile); // 0x004CD420

struct D2MissileScanStateStrc;

static D2UnitStrc* __stdcall MISSILE_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile); // 0x004CE530

void __fastcall sub_004B9A00_PlayOverlay(int nOverlay, D2UnitStrc* pOwner, int nDelay, int nArg3, int nArg4); // 0x004B9A00

void __fastcall MISSILE_SpawnScatterMissiles(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSound, int nLevel); // 0x004CE650

struct D2MissileScanStateStrc
{
    int unk0x00;
    int nHits;
    D2MissileScanArgStrc* pScanArg;
};

int __fastcall MISSILE_CreateCallbackMissile(void* pArgument, D2UnitStrc* pUnit); // 0x004CFD70

int __stdcall sub_0064A730_GetTargetX(D2UnitStrc* pUnit); // 0x0064A730

int __stdcall sub_0064A780_GetTargetY(D2UnitStrc* pUnit); // 0x0064A780

extern int gaMissileFanTargetX[]; // 0x006DB100

extern int gaMissileFanTargetY[]; // 0x006DB120

void __stdcall PATH_SetMaxVelocity(D2DynamicPathStrc* pDynamicPath, int nMaxVelocity); // 0x006486D0

void __stdcall PATH_SetAcceleration(D2DynamicPathStrc* pDynamicPath, int nAcceleration); // 0x00648700

void __stdcall PATH_SetTargetPos(D2DynamicPathStrc* pDynamicPath, unsigned short nX, unsigned short nY); // 0x00648AD0

void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pTargetUnit); // 0x00648B90

void __stdcall MISSILE_SetMissileLevel(D2UnitStrc* pMissile, int nSkillLevel); // 0x0064A1E0

#define SUBMISSILE_ID 375

int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

int __stdcall sub_0064A3B0(D2UnitStrc* pMissile);                                                         // 0x0064A3B0

struct D2CltSpreadStrc
{
    int nOffsetX;
    int nOffsetY;
    unsigned char nDirection;
    char pad0x09[3];
};

extern const D2CltSpreadStrc gaCltSpread[7];                                                       // 0x006DB7F0

int __stdcall sub_0064A210_GetSkillLevel(D2UnitStrc* pUnit);                                                // 0x0064A210

int __stdcall sub_0064A280_GetSkill(D2UnitStrc* pUnit);                                                     // 0x0064A280

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordLow(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int SKILLS_GetLevelBasedParam(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordLow(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }

    return (nLevel - 1) * pSkillsTxtRecord->dwParam[3] + pSkillsTxtRecord->dwParam[2];
}

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __fastcall SKILLSBAR_RotateUnitDirection(D2UnitStrc* pUnit, int nArg, int bForward); // 0x004C9060

#define UNITFLAGEX_0x40000 0x40000

#define PATHTYPE_CHARGEDBOLT 10

struct D2TimedHintEntryStrc;

struct D2MonSoundsTxt;

struct D2UnitSndPlayerStrc;

struct D2UnitSndObjectStrc;

struct D2SuperUniquesTxt;

struct D2MonStatsTxt;

struct D2DirRateStrc;

struct D2TimedHintNodeStrc;

struct D2DrlgCoordsStrc;

struct D2TileLibraryEntryStrc;

struct D2SoundEnvironTxtStrc;

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

void __cdecl VIEW_ClearGlobals(); // 0x00476AF0

static inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}


inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordInline(D2UnitStrc* pItem)
{
    int nFileIndex = ITEMS_GetFileIndex(pItem);
    if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nFileIndex];
    }

    return 0;
}

inline int UNITS_IsAsyncInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 21) & 1;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

static inline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    return (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nMissileId] : 0;
}

static inline D2MissilesTxt* CLTMISS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// 0x004CC870
void __fastcall MISSILE_InitFromOwner(D2UnitStrc* pMissile, int nInitArg)
{
    D2UnitStrc* pOwner = (D2UnitStrc*)nInitArg;
    if (!pMissile)
        return;

    D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pOwner)
        return;

    int nOffset = 0;
    if (pMissilesTxtRecord->dwCltParam[1] > 0)
        nOffset = SEED_RollLimitedRandomNumber(&pOwner->pSeed, pMissilesTxtRecord->dwCltParam[1]) - pMissilesTxtRecord->dwCltParam[1] / 2;

    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nOffset);
    PATH_SetDirection(pMissile->pDynamicPath, PATH_GetDirection(pOwner->pDynamicPath));
    D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
    pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nAnimLen) << 8;
}

// 0x004CC950
static int MISSILE_GetSubMissileCount(D2MissilesTxt* pMissilesTxt, int nFrame)
{
    if (nFrame < 30)
    {
        return 1;
    }

    if (nFrame < 85)
    {
        return (nFrame - 15) / 4;
    }

    const int nRange = pMissilesTxt->wRange;
    const int nStart = nRange - 50;
    if (nFrame < nStart)
    {
        return 12;
    }

    if (nFrame < nRange)
    {
        return 12 - (nFrame - nStart) / 4;
    }

    return 1;
}

static D2MissilesTxt* GetMissilesTxtRecord_Inline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nId];
    return 0;
}

static D2MissilesTxt* GetUnitMissilesTxt_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    return GetMissilesTxtRecord_Inline(pUnit->dwClassId);
}

static int GetUnitXPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nXPos;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int GetUnitYPosition_Inline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->nYPos;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004CCA00
static void __stdcall MISSILE_SteerMissile(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = GetUnitMissilesTxt_Inline(pUnit);
    if (!pTxt)
        return;
    if (pTarget && CUNIT_IsDeadOrDying(pTarget))
        pTarget = 0;
    const int nFrames = (MISSILE_GetLevel(pUnit) - 1) * pTxt->wLevRange + pTxt->wRange;
    MISSILE_SetTotalFrames(pUnit, nFrames);
    MISSILE_SetCurrentFrame(pUnit, nFrames);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nDistance;
    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
        MISSILE_SetTargetX(pUnit, 5);
        nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);
    }
    else
    {
        const unsigned int dwOffset = MISSILE_GetTargetY(pUnit);
        const short nOffsetX = (short)dwOffset;
        const short nOffsetY = (short)(dwOffset >> 16);
        const int nX = nOffsetX + GetUnitXPosition_Inline(pUnit);
        const int nY = nOffsetY + GetUnitYPosition_Inline(pUnit);
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        MISSILE_SetTargetX(pUnit, 6);
        nDistance = UNITS_GetDistanceToCoordinates(pUnit, nX, nY);
    }
    if (nDistance < 0x19)
        D2Common_10142(pPath, pUnit, 0);
}

// 0x004CCB50
static int MISSILE_SeekTarget(D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = GetUnitMissilesTxt_Inline(pUnit);
    if (!pTxt)
        return 1;
    const int nRange = pTxt->dwParam[1];
    if (MISSILE_GetTargetX(pUnit) & 4)
        return 1;
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
    if (!pOwner)
        return 1;
    MISSILE_SteerMissile(sub_004C5EB0_FindDestination(pOwner, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nRange, 3, -1, 0), pUnit);
    return 0;
}

// 0x004CCBE0
int __fastcall MISSILE_UpdateGuidedMissile(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
    if (!pOwner || CUNIT_IsDeadOrDying(pOwner))
        return 1;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        return 1;
    const int nFlags = MISSILE_GetTargetX(pUnit);
    if (!pTarget && (nFlags & 4))
        return 1;
    if (nFlags & 1)
    {
        if (pTarget && pTarget != PATH_GetTargetUnit(pPath))
            return 0;
    }
    else if (nFlags & 2)
    {
        if (sub_0064A380_GetRemainingFrames(pUnit) <= 0)
            return MISSILE_SeekTarget(pUnit) != 0;
        return ((unsigned char)nFlags >> 2) & 1;
    }
    return 1;
}

// 0x004CCD20
int __fastcall MISSILE_CltHitSpiral(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
        return 1;
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
        return 1;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.nX = CLIENTS_GetUnitX(pMissile);
    tParams.nY = CLIENTS_GetUnitY(pMissile);
    tParams.pOwner = pOwner;
    tParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.pInitFunc = MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc;
    int nCount = (MISSILE_GetLevel(pMissile) - 1) * pMissilesTxtRecord->dwCltHitPar[1] + pMissilesTxtRecord->dwCltHitPar[0];
    if (nCount <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nSkillLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
            return 1;
        nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
        if (nCount < 1)
            nCount = 1;
    }
    SKILLS_CreateSpiralMissiles(nCount, &tParams);
    return 1;
}

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}

// 0x004CCE40
int __fastcall MISSILE_CltHitSpiralGrid(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pMissilesTxtRecord->dwCltHitPar[0] <= 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 3;
    tMissileParams.nX = CLIENTS_GetUnitX(pMissile);
    tMissileParams.nY = CLIENTS_GetUnitY(pMissile);
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    if (pMissilesTxtRecord->dwCltHitPar[1])
    {
        tMissileParams.pInitFunc = (MissileInitFunc)sub_004E2ED0_VolleyCallback;
    }
    SKILLS_CreateSpiralMissiles(pMissilesTxtRecord->dwCltHitPar[0], &tMissileParams);
    return 1;
}

// 0x004CCF40
static int __stdcall MISSILE_CanMissileHitUnit(D2UnitStrc* pUnit, D2UnitStrc* pMissile, D2UnitStrc* pOwner, D2MissilesTxt* pMissilesTxtRecord)
{
    if (!UNITS_IsValidTargetInline(pUnit))
        return 0;

    if (!UNITS_CanBeAttackedInline(pUnit))
        return 0;

    if (pMissilesTxtRecord->nNextHit && STATES_CheckState(pUnit, STATE_JUSTHIT))
        return 0;

    if (MISSILE_CheckUnitIfOwner(pMissile, pUnit))
        return 0;

    if (pOwner && !CUNIT_IsHostileTo(pOwner, pUnit) && !pMissilesTxtRecord->nCollideFriend)
        return 0;

    return 1;
}

// 0x004CCFB0
int __fastcall MISSILE_CltCanCollideWithMonster(D2UnitStrc* pUnit, D2CltMissileFindArgStrc* pArg)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        return 0;

    return MISSILE_CanMissileHitUnit(pUnit, pArg->pMissile, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x004CCFE0
int __fastcall MISSILE_CltCanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, D2CltMissileFindArgStrc* pArg)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
        return 1;

    if (nUnitType != UNIT_PLAYER)
        return 0;

    return MISSILE_CanMissileHitUnit(pUnit, pArg->pMissile, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x004CD020
int __fastcall MISSILE_CltCanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, D2CltMissileFindArgStrc* pArg)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_PLAYER && nUnitType != UNIT_MONSTER)
        return 0;

    return MISSILE_CanMissileHitUnit(pUnit, pArg->pMissile, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x004CD050
int __fastcall MISSILE_CltCanMissileDestroy(D2UnitStrc* pUnit, void* pArgument)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pUnit->dwClassId);
    if (!pMissilesTxtRecord || !(pMissilesTxtRecord->nMissileFlags[4 >> 3] & gdwBitMasks[4 & 7]))
    {
        return 0;
    }

    return 1;
}

// 0x004CD0A0
void __fastcall MISSILE_InitMissileUnit(D2UnitStrc* pMissile, int nArg, int nTargetX, int nTargetY, int nUnused)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    MISSILE_AllocMissileData(pMissile);
    UNITS_ChangeAnimMode(pMissile, pMissilesTxtRecord->nCollideType);
    PATH_AllocDynamicPath(0, nArg, nTargetX, nTargetY, pMissile, 1);

    D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
    if (pMissilesTxtRecord->nCollision)
    {
        PATH_SetFootprintCollisionMask(pDynamicPath, 0x40);
    }
    else
    {
        PATH_SetFootprintCollisionMask(pDynamicPath, 0);
    }
    PATH_SetMoveTestCollisionMask(pDynamicPath, gaCltMissileModes[pMissilesTxtRecord->nCollideType].nCollisionMask);

    if (pMissilesTxtRecord->nMissileFlags[0] & gnBitMasks_006CE268[4])
    {
        pMissile->dwFlags |= 4;
    }
    else
    {
        pMissile->dwFlags &= ~4;
    }

    pMissile->dwFlags = (pMissile->dwFlags & ~0xA) | 0x20;
}


// 0x004CD380
void __fastcall MISSILE_StatRemoveToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0

extern "C" int __stdcall sub_0064A300(D2UnitStrc* pUnit); // 0x0064A300

void __fastcall DLIGHTMAP_ResetLightSize(D2GfxLightStrc* pLight, int nSize); // 0x004742D0

void* __fastcall UNITSND_GetLinkFirst(D2UnitStrc* pUnit); // 0x004CA990

#define UNIT_INVALID 6

struct D2GfxEntryStrc;

struct D2CltMissileSpawnArgStrc;

extern D2DrlgActStrc* gpAct; // 0x007A0634

void __stdcall MISSTREAM_FreeMissileStream(D2UnitStrc* pMissile); // 0x00663D90

void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile); // 0x0064A150

void __stdcall PARTICLE_FreeGfxMotion(D2UnitStrc* pUnit); // 0x004DA080

void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit); // 0x0046EC10

void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460

void __fastcall MISSILE_CreateBurstAt(D2UnitStrc* pMissile, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CED60

void __fastcall PLRSKILLS_SkillSeqDoBackward(D2UnitStrc* pUnit, int nArg); // 0x004D85C0

D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

D2GfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10

struct D2CltMissileSpawnArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkill;
    int nSkillLevel;
    int nMaxCount;
    int nMissile;
};

int __fastcall MISSILE_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790

void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000

int __fastcall MISSILE_CreateMissileFan(D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissile, int nSkill, int nSkillLevel, int nStep); // 0x004D01D0

extern const int gaHitRing64OffsetY[64]; // 0x006DB140

extern const int gaHitRing64OffsetX[64]; // 0x006DB240

extern const int gaRingOffsetY_006DB340[64]; // 0x006DB340

extern const int gaRingOffsetX_006DB440[64]; // 0x006DB440

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

extern "C" void __stdcall sub_006488A0(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x006488A0

#define TEST_OFFSET 0

#define LIGHT_LIMIT 60

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);

void __fastcall SOUNDINST_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce); // 0x004BA790

struct D2OwnerStrc_004CA990;

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask);         // 0x0064CB30

#define SPAWN_FLAGS 0x2001

#define COLLISION_MASK 0x45

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290

// 0x004CD170
void __fastcall MISSILE_FreeMissileUnit(D2UnitStrc* pMissile)
{
    MISSTREAM_FreeMissileStream(pMissile);
    MISSILE_FreeMissileData(pMissile);
    PARTICLE_FreeGfxMotion(pMissile);
    GFX_FreeGfxData(pMissile);
    if (gpAct)
    {
        D2Common_10228(pMissile);
        UNITROOM_RemoveUnitFromRoom(pMissile);
    }
    PATH_FreeDynamicPath(0, pMissile->pDynamicPath);
    pMissile->pDynamicPath = 0;
}

// 0x004CD1C0
static void MISSILE_FlickerLight(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissile->nSeqCurrentFramePrecise & 0x300)
        return;
    D2GfxLightStrc* pLight = pMissile->pLight;
    if (!pLight)
        return;
    if (DLIGHTMAP_GetLightSize(pLight) < pMissilesTxtRecord->nLight)
        return;
    const int nRadius = pMissilesTxtRecord->nLight + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nFlicker);
    DLIGHTMAP_SetLightSize(pLight, nRadius);
}

// 0x004CE4B0
void __fastcall MISSILE_InitMotion(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->dwCltParam[1] > 0)
    {
        GFXUTIL_SetMotionVectorA(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[0]);
        GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -pMissilesTxtRecord->dwCltParam[1], 1);
        const int nFrames = pMissilesTxtRecord->dwCltParam[0] / pMissilesTxtRecord->dwCltParam[1];
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }
}

// 0x004CE650
void __fastcall MISSILE_SpawnScatterMissiles(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nCount)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(nMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nRange = 7 * nCount;
    const int nMissiles = nRange > 8 ? 8 : nRange;
    for (int i = 0; i < nMissiles; ++i)
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.pOwner = pOwner;
        tParams.pOrigin = pUnit;
        tParams.nSkill = MISSILE_GetSkill(pUnit);
        tParams.nSkillLevel = MISSILE_GetLevel(pUnit);
        tParams.nMissile = nMissile;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tParams);
        if (pMissile)
        {
            const int nX = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, nRange) - nRange / 2;
            const int nY = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, nRange) - nRange / 2;
            const int nZ = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, pMissilesTxtRecord->dwCltParam[1]);
            PARTICLE_ResetGfxMotion(pMissile);
            GFXUTIL_SetMotionVectorA(pMissile, nX, nY, pMissilesTxtRecord->dwCltParam[0]);
            GFXUTIL_SetMotionVectorB(pMissile, 0, 0, nZ, 1);
            sub_004DA250(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[2], 1);
        }
    }
}

// 0x004CED20
void __fastcall MISSILE_SubmitWithDirection(D2UnitStrc* pMissile, int nMissile)
{
    D2UnitStrc* pNew = MISSILE_SubmitOwnerRequest(pMissile, nMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNew)
    {
        PATH_SetDirection(pNew->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
    }
}

// 0x004CEF50
void __fastcall MISSILE_SpawnBurst(D2UnitStrc* pMissile, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult)
{
    MISSILE_CreateBurstAt(pMissile, CLIENTS_GetUnitXInline(pMissile), CLIENTS_GetUnitYInline(pMissile), nCount, nMissile, nSkill, nLevel, nPerStep, nMult);
}

// 0x004CF250
int __fastcall MISSILE_CltHitSubMissileBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    MISSILE_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], MISSILE_FIREEXPLOSION2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwCltHitPar[1], 1);
    return 1;
}

// 0x004CF2B0
int __fastcall MISSILE_CltHitEffect(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const short nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
        if (nSubMissile >= 0)
        {
            MISSILE_AddMissileEffect(pMissile, nSubMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->dwCltHitPar[2]);
        }
    }
    return 1;
}

// 0x004CF300
int __fastcall MISSILE_CltHitTwoSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    MISSILE_SubmitOwnerRequest(pMissile, (short)pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if ((short)pMissilesTxtRecord->wCltHitSubMissile[1] < 0)
    {
        return 1;
    }

    int nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[1];
    if ((short)pMissilesTxtRecord->wCltHitSubMissile[2] > (short)pMissilesTxtRecord->wCltHitSubMissile[1])
    {
        nSubMissile = MISSILE_RollRange(&pMissile->pSeed, (short)pMissilesTxtRecord->wCltHitSubMissile[1], (short)pMissilesTxtRecord->wCltHitSubMissile[2]);
    }

    D2UnitStrc* pSubMissile = MISSILE_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pSubMissile)
    {
        CUNIT_MarkUnitDead(pSubMissile);
    }
    return 1;
}

// 0x004CFC80
int __fastcall MISSILE_CltHitRandomSubMissile(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && (short)pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        int nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
        if ((short)pMissilesTxtRecord->wCltHitSubMissile[1] > (short)pMissilesTxtRecord->wCltHitSubMissile[0])
        {
            const int nMax = (short)pMissilesTxtRecord->wCltHitSubMissile[1];
            if (nSubMissile < nMax)
            {
                nSubMissile += ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nSubMissile + 1);
            }
        }

        MISSILE_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }
    return 1;
}

// 0x004CFD00
int __fastcall MISSILE_CltHitOwnerRequest(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    MISSILE_SubmitOwnerRequest(pMissile, (short)pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    return 0;
}

inline int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
}

// 0x004D02E0
int __fastcall MISSILE_CltHitForward(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        if (!pUnit)
        {
            pUnit = pMissile;
        }

        int nCount = pMissilesTxtRecord->dwCltHitPar[0];
        if (nCount < 1)
        {
            nCount = 1;
        }

        MISSILE_CreateMissileFan(pOwner, pUnit, pMissilesTxtRecord->wCltHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nCount);
        return 1;
    }

    return 1;
}

// 0x004D04D0
int __fastcall sub_004D04D0_HitRing64(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 2;
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];

            int nStep = pMissilesTxtRecord->dwCltHitPar[0];
            if (nStep < 1)
            {
                nStep = 1;
            }

            for (int i = 0; i < 64; i += nStep)
            {
                tMissileParams.nTargetX = gaHitRing64OffsetX[i];
                tMissileParams.nTargetY = gaHitRing64OffsetY[i];
                D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&tMissileParams);
                if (pSubMissile)
                {
                    MISSILE_SetTargetX(pSubMissile, gaHitRing64OffsetX[i]);
                    MISSILE_SetTargetY(pSubMissile, gaHitRing64OffsetY[i]);
                }
            }
        }

        return 1;
    }

    return 1;
}

// 0x004D05E0
int __fastcall sub_004D05E0_HitRing64(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 2;
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];

            int nStep = pMissilesTxtRecord->dwCltHitPar[0];
            if (nStep < 1)
            {
                nStep = 1;
            }

            for (int i = 0; i < 64; i += nStep)
            {
                tMissileParams.nTargetX = gaRingOffsetX_006DB440[i];
                tMissileParams.nTargetY = gaRingOffsetY_006DB340[i];
                D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&tMissileParams);
                if (pSubMissile)
                {
                    MISSILE_SetTargetX(pSubMissile, gaRingOffsetX_006DB440[i]);
                    MISSILE_SetTargetY(pSubMissile, gaRingOffsetY_006DB340[i]);
                }
            }
        }

        return 1;
    }

    return 1;
}

// 0x004D07E0
int __fastcall MISSILE_CltHitScatter(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        if (!pOwner)
        {
            return 1;
        }

        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0x102;
            tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
            tMissileParams.pOwner = pOwner;
            tMissileParams.pOrigin = pMissile;
            tMissileParams.nSkill = sub_0064A280(pMissile);

            const int nSpread = pMissilesTxtRecord->dwCltHitPar[0] < 3 ? 3 : pMissilesTxtRecord->dwCltHitPar[0];
            const int nCount = MISSILE_GetMissileTargetStatus(pMissile);
            for (int i = 0; i < nCount; ++i)
            {
                tMissileParams.nSkillLevel = SEED_RollRandomNumber(&pMissile->pSeed) % 5 + 1;
                const int nOffsetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
                tMissileParams.nTargetX = nOffsetX;
                const int nOffsetY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
                tMissileParams.nTargetY = nOffsetY;
                if (!nOffsetX && !nOffsetY)
                {
                    tMissileParams.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, nSpread) + 1;
                }
                MISSILE_CreateClientMissile(&tMissileParams);
            }
        }

        return 1;
    }

    return 1;
}

// 0x004D09E0
int __fastcall MISSILE_CltHitSubMissileOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2UnitStrc* pSubMissile = MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pSubMissile)
        {
            D2DynamicPathStrc* pPath = pSubMissile->pDynamicPath;
            sub_006488A0(pPath, PATH_GetDirection(pMissile->pDynamicPath));
            D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
            MISSILE_SetTargetX(pSubMissile, MISSILE_GetMissileTargetStatus(pMissile));
        }

        return 1;
    }

    return 1;
}

// 0x004D0B90
static void __stdcall MISSILE_SpawnHitBurst(int nCount, int nVelocity, int nGate, int nRingMissile, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    const int nSkill = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    D2MissileStrc tParams;
    if (nGate >= 0)
    {
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x524;
        tParams.pOwner = pOwner;
        tParams.pOrigin = pMissile;
        tParams.nMissile = MISSILE_MOLTENBOULDER_FLYINGROCKS;
        tParams.nVelocity = nVelocity;
        tParams.nSkill = nSkill;
        tParams.nSkillLevel = nLevel;
        const int nSpread = 2 * nCount;
        for (int i = 0; i < nCount; ++i)
        {
            const int nTargetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nSpread + 1) - nSpread + nX;
            const int nTargetY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nSpread + 1) - nSpread + nY;
            if (UNITS_GetDistanceToCoordinates(pMissile, nTargetX, nTargetY) > 3)
            {
                tParams.nTargetX = nTargetX;
                tParams.nTargetY = nTargetY;
                MISSILE_CreateClientMissile(&tParams);
            }
        }
    }
    if (nRingMissile >= 0)
    {
        for (int i = 0; i < 18; ++i)
        {
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 1;
            tParams.pOwner = pOwner;
// build: symbol ?gaHitRingX@* 0x006DB540
            tParams.nX = gaHitRingX[i] + nX;
// build: symbol ?gaHitRingY@* 0x006DB588
            tParams.nY = gaHitRingY[i] + nY;
            tParams.nSkill = nSkill;
            tParams.nSkillLevel = nLevel;
            tParams.nMissile = nRingMissile;
            MISSILE_CreateClientMissile(&tParams);
        }
    }
}

// 0x004D0DB0
int __fastcall MISSILE_CltHitParamBurst(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    MISSILE_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[0], pMissilesTxtRecord->wCltHitSubMissile[1], pMissile);
    return 1;
}

static inline int sub_CanHitUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    return MONSTERREGION_CheckMonStats2Flag(nClassId, 0xB);
}

// 0x004D0E00
int __fastcall MISSILE_CltHitBurstSub(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (sub_CanHitUnit(pHitUnit))
    {
        if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
        {
            MISSILE_SubmitMissileRequest(CUNIT_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltHitSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
        }

        MISSILE_SpawnHitBurst(pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1], pMissilesTxtRecord->wCltHitSubMissile[1], pMissilesTxtRecord->wCltHitSubMissile[2], pMissile);
        return 1;
    }

    return 0;
}

// 0x004D2190
static void __stdcall MISSILE_SpawnRandomBolt(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int aOffsetX[4] = { 1, 0, -1, 0 };
    int aOffsetY[4] = { 0, 1, 0, -1 };

    const unsigned int nZ = SEED_RollRandomNumber(&pMissile->pSeed) % 125;
    const int nDirection = SEED_RollRandomNumber(&pMissile->pSeed) & 3;
    const int nUnitX = UNITS_GetUnitXPosition(pMissile);
    const int nUnitY = UNITS_GetUnitYPosition(pMissile);
    const int nX = nUnitX + aOffsetX[nDirection];
    const int nY = nUnitY + aOffsetY[nDirection];
    const int nDiffY = nY - nUnitY;
    const int nDiffX = nX - nUnitX;

    int nMissile;
    switch (SEED_RollRandomNumber(&pMissile->pSeed) % 30)
    {
    case 0:
        nMissile = MISSILE_NEHLITHAKDEBRIS1;
        break;
    case 1:
        nMissile = MISSILE_NEHLITHAKDEBRIS2;
        break;
    case 2:
        nMissile = MISSILE_NEHLITHAKDEBRIS3;
        break;
    case 3:
        nMissile = MISSILE_NEHLITHAKDEBRIS4;
        break;
    default:
        nMissile = MISSILE_NEHLITHAKSWOOSH;
        break;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 3;
    tParams.pOwner = pOwner;
    tParams.nMissile = nMissile;
    tParams.nX = nX;
    tParams.nY = nY;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nTargetX = nDiffY;
    tParams.nTargetY = -nDiffX;

    D2UnitStrc* pNewMissile = MISSILE_CreateClientMissile(&tParams);
    if (pNewMissile)
    {
        GFXUTIL_SetMotionVectorA(pNewMissile, 0, 0, nZ);
        MISSILE_SetTargetX(pNewMissile, UNITS_GetUnitXPosition(pMissile));
        MISSILE_SetTargetY(pNewMissile, UNITS_GetUnitYPosition(pMissile));
    }
}

// 0x004D2400
static void __stdcall MISSILE_SpawnRandomShard(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.pOwner = pOwner;

    int nTargetX = 20 - SEED_RollRandomNumber(&pMissile->pSeed) % 40;
    tParams.dwFlags = 2;
    tParams.pOrigin = pMissile;
    tParams.nTargetX = nTargetX;
    const int nTargetY = 20 - SEED_RollRandomNumber(&pMissile->pSeed) % 40;
    tParams.nTargetY = nTargetY;
    tParams.nMissile = MISSILE_BRDEATHLIGHTNINGBOLT;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (!nTargetX && !nTargetY)
    {
        nTargetX = SEED_RollRandomNumber(&pMissile->pSeed) % 19 + 1;
        tParams.nTargetX = nTargetX;
    }

    D2UnitStrc* pNewMissile = MISSILE_CreateClientMissile(&tParams);
    if (pNewMissile)
    {
        MISSILE_SetTargetX(pNewMissile, nTargetX);
        MISSILE_SetTargetY(pNewMissile, nTargetY);
        GFXUTIL_SetMotionVectorA(pNewMissile, 0, 0, -10);
    }
}

// 0x004D2520
static void __stdcall MISSILE_SpawnBaalBolt(D2UnitStrc* pMissile, int nX, int nY)
{
    if (COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), nX, nY, 3, 1))
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x2001;
    tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tParams.nMissile = SEED_RollRandomNumber(&pMissile->pSeed) % 3 + 0x27B;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = nX;
    tParams.nY = nY;

    D2UnitStrc* pNewMissile = MISSILE_CreateClientMissile(&tParams);
    if (pNewMissile)
    {
        GFXUTIL_SetMotionVectorA(pNewMissile, 0, 0, 0xFA);
        GFXUTIL_SetMotionVectorB(pNewMissile, 0, 0, -10, 1);
        MISSILE_SetTotalFrames(pNewMissile, 0x19);
        MISSILE_SetCurrentFrame(pNewMissile, 0x19);
        sub_0064A690_SetMissileAnimSpeed(pNewMissile, 0x80);
    }
}

static inline unsigned __int64 SEED_RollNext64(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static inline unsigned __int64 SEED_RollNextHL(D2SeedStrc* pSeed, unsigned __int64 lPrev)
{
    const unsigned __int64 lSeed = (unsigned __int64)(unsigned int)(lPrev >> 32) + (unsigned __int64)(unsigned int)lPrev * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned __int64 SEED_RollHL64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int MISSILE_CltDoBaalStorm(D2SeedStrc* pSeed)
{
    const unsigned int nLowSeed = pSeed->nLowSeed;
    const unsigned int nHighSeed = pSeed->nHighSeed;
    const unsigned __int64 lSeed = nHighSeed + 0x6AC690C5i64 * nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// 0x004D2610
void __fastcall MISSILE_CltDoBaalStorm(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    int bInRange = 0;
    int nLevelId = 0;
    if (pOwner)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOwner));
    }
    switch (nLevelId)
    {
    case LEVEL_THRONEOFDESTRUCTION:
    case LEVEL_THEWORLDSTONECHAMBER:
        bInRange = 1;
        break;
    }
    if (!pOwner || !bInRange)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
    UNITS_UpdateFrame(pMissile);

    if (!MISSILE_GetTargetX(pMissile) || !(SEED_RollRandomNumber(&pMissile->pSeed) & 0x3F))
    {
        sub_00476A80_StartTiming(6, 2000, 3000, 2000);
        MISSILE_SetTargetX(pMissile, 1);
    }

    unsigned __int64 lSeed = SEED_RollHL64(&pMissile->pSeed);
    if (!((unsigned int)lSeed % 10))
    {
        lSeed = SEED_RollNextHL(&pMissile->pSeed, lSeed);
        const unsigned int nRollX = (unsigned int)lSeed;
        lSeed = SEED_RollNextHL(&pMissile->pSeed, lSeed);
        const unsigned int nRollY = (unsigned int)lSeed;
        const int nX = CLIENTS_GetUnitX(pMissile) + nRollX % 60 - 30;
        const int nY = CLIENTS_GetUnitY(pMissile) + nRollY % 60 - 30;
        MISSILE_SpawnBaalBolt(pMissile, nX, nY);
    }
}

// 0x004D2760
int __fastcall MISSILE_CltDoEightWaySpawn(D2UnitStrc* pMissile)
{
    const int nXOffsets[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    const int nYOffsets[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    MISSILE_SubmitOwnerRequest(pMissile, 0x58, 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));

    for (int i = 0; i < 8; ++i)
    {
        const int nPosX = nXOffsets[i] + nX;
        const int nPosY = nYOffsets[i] + nY;
        D2UnitStrc* pChild = MISSILE_SubmitOwnerRequest(pMissile, 0x59, 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pChild)
        {
            D2Common_10216(pChild->pDynamicPath, nPosX, nPosY, 0);
        }

        D2UnitStrc* pNew = MISSILE_SubmitOwnerRequest(pMissile, 0x1A1, nPosX, nPosY, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pNew)
        {
            int nFrames = sub_0064A300(pNew);
            nFrames -= SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, nFrames / 2);
            MISSILE_SetTotalFrames(pNew, nFrames);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
// build: symbol ?gszMissileSourceFile@* 0x006DAEF4
            PATH_SetVelocity(pPath, SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, PATH_GetVelocity(pPath)), gszMissileSourceFile, 0x1A6B);
            GFXUTIL_SetBallistic(pNew, 0x1E, nFrames);
        }
    }

    return 1;
}

// 0x004D2990
static void __stdcall MISSILE_SpawnAtFreeSpot(D2UnitStrc* pOwner, int nX, int nY, D2UnitStrc* pMissile)
{
    int bRetry = 1;
    int nTries = 0;
    if (!pMissile || !pOwner)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
        return;
    while (bRetry && nTries < 4)
    {
        const int nOffsetX = 17 - SEED_RollRandomNumber(&pMissile->pSeed) % 34;
        const int nOffsetY = 17 - SEED_RollRandomNumber(&pMissile->pSeed) % 34;
        if (nOffsetX < -1 || nOffsetX > 1 || nOffsetY < -1)
        {
            if (!COLLISION_CheckMask(pRoom, nX + nOffsetX, nY + nOffsetY, 4))
            {
                nX += nOffsetX;
                nY += nOffsetY;
                bRetry = 0;
            }
        }
        ++nTries;
    }
    if (bRetry)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    tParams.pOwner = pOwner;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = nX;
    tParams.nMissile = MISSILE_ANYASTEAMVENT;
    tParams.nY = nY;
    MISSILE_CreateClientMissile(&tParams);
    tParams.nMissile = MISSILE_ANYASTEAM;
    MISSILE_CreateClientMissile(&tParams);
}

// 0x004D2C10
int __fastcall MISSILE_CltHitSubMissile(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            const short nSubMissile = (short)pMissilesTxtRecord->wCltHitSubMissile[0];
            if (nSubMissile >= 0)
            {
                int nPar = pMissilesTxtRecord->dwCltHitPar[0];
                if (nPar < 1)
                {
                    nPar = 1;
                }

                MISSILE_AddMissileEffect(pMissile, nSubMissile, nPar, 2, 0);
            }
        }
    }

    return 1;
}

// 0x004D2C70
void __fastcall MISSILE_CltDoMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    if (pMissilesTxtRecord->nFlicker)
        MISSILE_FlickerLight(pMissile);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
        pRoom = sub_00463740_FindRoomAtPoint(0, UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile));
    if (!(pMissilesTxtRecord->nMissileFlags[10 >> 3] & gdwBitMasks[10 & 7]) && DUNGEON_IsRoomInTown(pRoom))
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    const short nCltDoFunc = pMissilesTxtRecord->wCltDoFunc;
// build: symbol ?gnCltDoFuncs@* 0x0072A34C
    if (nCltDoFunc > 0 && nCltDoFunc < gnCltDoFuncs)
        gpfnCltDoFuncs[nCltDoFunc](pMissile);
}

// 0x004D33E0
void __fastcall MISSILE_CltDoOnScreen(D2UnitStrc* pMissile)
{
    if (UNITS_IsAtEndOfFrameCycle(pMissile))
    {
        CUNIT_MarkUnitDead(pMissile);
// build: symbol ?gszMissileSourceFile@* 0x006DAEF4
        PATH_SetVelocity(pMissile->pDynamicPath, 0, gszMissileSourceFile, 0x7F);
    }

    int nX = UNITS_GetClientCoordX(pMissile) - PLAYER_GetScreenOffsetX();
    if (nX >= 0 && nX <= gnAutomapWidth)
    {
        int nY = UNITS_GetClientCoordY(pMissile) - PLAYER_GetScreenOffsetY();
        if (nY >= 0 && nY <= gnAutomapHeight_007A521C + 0x40)
        {
            MISSILE_SetCurrentFrame(pMissile, 0x80);
            MISSILE_CltDoCommon(pMissile);
            return;
        }
    }

    MISSILE_CltMissileHit(pMissile, 0, 0);
}

// 0x004CE050
void __fastcall MISSILE_SpawnFollowUp(D2UnitStrc* pMissile, int nMissile, int nRange, int bFlag)
{
    if (!PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 5;
    if (nRange > 0)
    {
        tParams.nRange = nRange;
        tParams.dwFlags = 0x8005;
    }
    if (bFlag > 0)
        tParams.dwFlags |= 8;
    tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tParams.pOrigin = pMissile;
    tParams.nMissile = nMissile;
    tParams.nX = UNITS_GetUnitXPosition(pMissile);
    tParams.nY = UNITS_GetUnitYPosition(pMissile);
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    tParams.nSkillLevel = nLevel;
    tParams.nLoops = 2 * nLevel - 2;
    MISSILE_CreateClientMissile(&tParams);
}

// 0x004CE420
void __fastcall MISSILE_InitCltParamMotion(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nSpeed = MAX(pMissilesTxtRecord->dwCltParam[1], 1);
    const int nRange = nSpeed > pMissilesTxtRecord->dwCltParam[0] ? nSpeed : pMissilesTxtRecord->dwCltParam[0];
    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nRange);
    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -nSpeed, 1);
    const int nFrames = nRange / nSpeed;
    MISSILE_SetTotalFrames(pMissile, nFrames);
    MISSILE_SetCurrentFrame(pMissile, nFrames);
}

// 0x004CEFE0
void __fastcall MISSILE_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nOuterStep, int nInnerStep, int nLoops)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    if (!nMissile)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x17;
    if (nLoops > 0)
    {
        missileParams.dwFlags = 0x1F;
        missileParams.nLoops = nLoops;
    }

    missileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nMissile = nMissile;
    missileParams.nX = UNITS_GetUnitXPosition(pMissile);
    missileParams.nY = UNITS_GetUnitYPosition(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    int nStep = nInnerStep < 1 ? 1 : nInnerStep;
    for (int i = 0; i < 16; i += nStep)
    {
        missileParams.nTargetX = gaEffectRingOffsetX[i];
        missileParams.nTargetY = gaEffectRingOffsetY[i];
        MISSILE_CreateClientMissile(&missileParams);
    }

    if (nOuterStep > 0)
    {
        missileParams.nVelocity = pMissilesTxtRecord->dwParam[1] << 7;
        for (int i = 1; i < 16; i += nOuterStep)
        {
            missileParams.nTargetX = gaEffectRingOffsetX[i];
            missileParams.nTargetY = gaEffectRingOffsetY[i];
            MISSILE_CreateClientMissile(&missileParams);
        }
    }
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX(pUnit->pDynamicPath) : 0;
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

    return pUnit->pDynamicPath ? sub_00648900_PathGetY(pUnit->pDynamicPath) : 0;
}

// 0x004CF150
int __fastcall MISSILE_CltHitRing(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 2;
    tMissileParams.pOwner = pOwner;
    tMissileParams.pOrigin = pMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    int nStep = pMissilesTxtRecord->dwCltHitPar[0];
    if (nStep < 1)
    {
        nStep = 1;
    }

    for (int i = 0; i < 8; i += nStep)
    {
        tMissileParams.nTargetX = gaCltHitRingOffsetX[i];
        tMissileParams.nTargetY = gaCltHitRingOffsetY[i];
        D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pSubMissile)
        {
            MISSILE_SetTargetX(pSubMissile, gaCltHitRingOffsetX[i]);
            MISSILE_SetTargetY(pSubMissile, gaCltHitRingOffsetY[i]);
        }
    }
    return 1;
}

// 0x004D3460
void __fastcall MISSILE_CltDoFollowUp(D2UnitStrc* pMissile)
{
    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        const int nMissileId = pMissile->dwClassId;
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
        {
            MISSILE_SpawnFollowUp(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, MISSILE_EvaluateMissileFormula(pMissile, CUNIT_GetOwnerUnit(pMissile), pMissilesTxtRecord->dwCltCalc, nMissileId, sub_0064A210(pMissile)));
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D34E0
void __fastcall MISSILE_CltDoParamCall(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    MISSILE_SpawnRingAround(pMissile, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->wCltSubMissile[0]);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3540
void __fastcall MISSILE_CltDoSubLoop(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nFrame = pMissile->nSeqCurrentFramePrecise >> 8;
    if (nFrame == pMissilesTxtRecord->nSubStart - 1)
    {
        pMissile->nSeqCurrentFramePrecise = (ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nSubStop - pMissilesTxtRecord->nSubStart) + nFrame) << 8;
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    if (sub_0064A380(pMissile) == pMissilesTxtRecord->nSubStart)
    {
        const int nNewFrame = pMissilesTxtRecord->nSubStart - 3;
        pMissile->nSeqCurrentFramePrecise = (nNewFrame < 0 ? 0 : nNewFrame) << 8;
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    if (sub_0064A380(pMissile) < pMissilesTxtRecord->nSubStart)
    {
        nFrame -= 2;
        pMissile->nSeqCurrentFramePrecise = (nFrame < 0 ? 0 : nFrame) << 8;
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004CD390
void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (pMissilesTxtRecord && (short)pMissilesTxtRecord->wTravelSound >= 0)
    {
        void* pUnitSfx = UNITSND_FindUnitSfxInRange(pMissile, (short)pMissilesTxtRecord->wTravelSound);
        if (pUnitSfx)
        {
            sub_004BA790_ReleaseUnitSfx(pUnitSfx, pMissile, 0);
        }
    }

    D2GfxLightStrc* pLight = UNITS_ResetLightMap(pMissile);
    if (pLight)
    {
        sub_00474470_ReleaseLight(pLight);
    }

    if (UNITS_IsAsyncInline(pMissile))
    {
        sub_00465F00_RemoveClientUnit(pMissile->dwUnitId, pMissile->dwUnitType);
    }
    else
    {
        CUNIT_RemoveClientSideUnit(pMissile->dwUnitId, pMissile->dwUnitType);
    }
}

// 0x004CDBA0
D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = CUNIT_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x20;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nArg5;
    tRequest.nArg6 = nArg6;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004D39C0
void __fastcall MISSILE_CltDoLightGrow(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nParam0 = pMissilesTxtRecord->dwCltParam[0] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[0];
    const int nParam1 = pMissilesTxtRecord->dwCltParam[1] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[1];
    const int nVelocityZ = nParam1 * nParam0;
    const int nParam2 = pMissilesTxtRecord->dwCltParam[2] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[2];
    const int nVelocityX = nParam2 * nParam0;

    int nSteps = SKILLS_EvaluateSkillFormula(CUNIT_GetOwnerUnit(pMissile), pSkillsTxtRecord->dwCalc[0], nSkillId, MISSILE_GetLevel(pMissile));
    nSteps = D2_MIN(D2_MAX(nSteps, 1), 0x3C);

    const int nInterval = 0x3C / nSteps;
    D2GfxLightStrc* pLight = pMissile->pLight;
    const int nLightSize = pLight ? DLIGHTMAP_GetLightSize(pLight) : 0;
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!((nFrames + 1) % nInterval) && nLightSize < nSteps && pLight)
        DLIGHTMAP_ResetLightSize(pLight, nLightSize + 1);

    if (!nFrames)
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 1;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nX = CLIENTS_GetUnitX(pMissile);
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&tParams);
        if (pSubMissile)
        {
            GFXUTIL_SetMotionVectorA(pSubMissile, -nVelocityX, 0, nVelocityZ);
            GFXUTIL_SetMotionVectorB(pSubMissile, nParam2, 0, -nParam1, 1);
        }

        if (pMissilesTxtRecord->wCltSubMissile[1] > 0)
        {
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            pSubMissile = MISSILE_CreateClientMissile(&tParams);
            if (pSubMissile)
            {
                GFXUTIL_SetMotionVectorA(pSubMissile, -nVelocityX, 0, nVelocityZ);
                GFXUTIL_SetMotionVectorB(pSubMissile, nParam2, 0, -nParam1, 1);
            }
        }
    }

    if (nFrames == nParam0 - 2)
    {
        void* pHint = UNITSND_GetLinkFirst(pMissile);
        if (pHint)
            sub_004BA790_ReleaseUnitSfx(pHint, pMissile, 1);

        if (pMissilesTxtRecord->wProgSound > 0)
            sub_004B9A00(pMissilesTxtRecord->wProgSound, pMissile, 0, 0, 0);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D49F0
void __fastcall MISSILE_CltDoWeave(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        if (pMissilesTxtRecord->wCltSubMissile[0] >= 0 && PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
        {
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            tParams.pInitFunc = (MissileInitFunc)sub_004CC870_SubMissileCallback;
            tParams.nInitArg = (int)pMissile;
            D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
            if (pNew)
                GFXUTIL_SetMotionVectorA(pNew, 0, 0, GFXUTIL_GetMotionAZ(pMissile));
        }

        int nPeriod = pMissilesTxtRecord->dwCltParam[0];
        if (nPeriod < 1)
            nPeriod = 1;
        if (!(sub_0064A3B0_GetElapsedFrames(pMissile) % nPeriod))
        {
            const int nA = MISSILE_GetTargetX(pMissile);
            const int nB = MISSILE_GetTargetY(pMissile);
            int nOffsetX;
            int nOffsetY;
            if (SEED_RollRandomNumber(&pMissile->pSeed) & 1)
            {
                nOffsetX = nA - nB;
                nOffsetY = nB + nA;
            }
            else
            {
                nOffsetX = nB + nA;
                nOffsetY = nB - nA;
            }
            nOffsetX = 3 * nOffsetX / 4;
            nOffsetY = 3 * nOffsetY / 4;
            if (nOffsetX || nOffsetY)
            {
                D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
                D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
            }
            MISSILE_SetTargetX(pMissile, nOffsetX);
            MISSILE_SetTargetY(pMissile, nOffsetY);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5090
void __fastcall MISSILE_CltDoTurn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        if (pMissilesTxtRecord->wCltSubMissile[0] > 0 && PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
        {
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            MISSILE_CreateClientMissile(&tParams);
        }

        int nPeriod = pMissilesTxtRecord->dwCltParam[0];
        if (nPeriod < 1)
            nPeriod = 1;
        if (!(sub_0064A3B0_GetElapsedFrames(pMissile) % nPeriod))
        {
            const int nA = MISSILE_GetTargetX(pMissile);
            const int nB = MISSILE_GetTargetY(pMissile);
            int nOffsetX;
            int nOffsetY;
            switch (SEED_RollRandomNumber(&pMissile->pSeed) & 3)
            {
            case 0:
                nOffsetX = nA - nB;
                nOffsetY = nB + nA;
                nOffsetX = 3 * nOffsetX / 4;
                nOffsetY = 3 * nOffsetY / 4;
                break;
            case 2:
                nOffsetX = nB + nA;
                nOffsetY = nB - nA;
                nOffsetX = 3 * nOffsetX / 4;
                nOffsetY = 3 * nOffsetY / 4;
                break;
            default:
                nOffsetX = nA;
                nOffsetY = nB;
                break;
            }
            D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
            D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
            MISSILE_SetTargetX(pMissile, nOffsetX);
            MISSILE_SetTargetY(pMissile, nOffsetY);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D55C0
void __fastcall MISSILE_CltDoOwnerSkill(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        if (pOwner)
        {
            D2SkillStrc* pSkill = UNITS_GetUsedSkill(pOwner);
// build: symbol ?gszMissileSourceFile@* 0x006DAEF4
            if (pSkill && SKILLS_GetSkillIdFromSkill(pSkill, gszMissileSourceFile, 2285) == MISSILE_GetSkill(pMissile))
            {
                if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
                {
                    MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
                }

                D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
                MISSILE_CltDoCommon(pMissile);
                return;
            }
        }
    }

    sub_00465F00_RemoveClientUnit(UNITS_GetUnitIdInline(pMissile), UNITS_GetUnitTypeInline(pMissile));
}

// 0x004D5710
void __fastcall MISSILE_CltDoPerpendicular(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0 && pMissile->pDynamicPath)
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        if (sub_0064A3B0_GetElapsedFrames(pMissile) < 2)
        {
            int nDX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath) - nX;
            int nDY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath) - nY;
            MISSILE_SetTargetX(pMissile, -nDY);
            MISSILE_SetTargetY(pMissile, nDX);
        }

        if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
        {
            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0xB;
            tMissileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
            tMissileParams.nX = nX;
            tMissileParams.nY = nY;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            tMissileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];
            tMissileParams.nTargetX = MISSILE_GetTargetX(pMissile);
            tMissileParams.nTargetY = MISSILE_GetTargetY(pMissile);
            MISSILE_CreateClientMissile(&tMissileParams);
            tMissileParams.nTargetX = -MISSILE_GetTargetX(pMissile);
            tMissileParams.nTargetY = -MISSILE_GetTargetY(pMissile);
            MISSILE_CreateClientMissile(&tMissileParams);
        }

        MISSILE_CltDoCommon(pMissile);
        return;
    }

    sub_00465F00_RemoveClientUnit(UNITS_GetUnitIdInline(pMissile), UNITS_GetUnitTypeInline(pMissile));
}

// 0x004D59E0
void __fastcall MISSILE_CltDoSeededSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pRecord || pRecord->wCltSubMissile[0] < 0) {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner) {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom) {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    int nSkill = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkill = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
    if (!pSkill) {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    int nLevel = MISSILE_GetLevel(pMissile);
    int nRange = SKILLS_EvaluateSkillFormula(CUNIT_GetOwnerUnit(pMissile),pSkill->dwCalc[0],nSkill,nLevel);
    int nPeriod = SKILLS_EvaluateSkillFormula(CUNIT_GetOwnerUnit(pMissile),pSkill->dwCalc[1],nSkill,nLevel);
    if (nPeriod < 1) nPeriod = 1;
    int nElapsed = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nElapsed % nPeriod != 0) {
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        SEED_InitLowSeed(pSeed,CLIENTS_GetUnitX(pMissile)+nElapsed);
        --nRange;
        int nDoubleRange = 2*nRange;
        int nX = ITEMS_RollLimitedRandomNumber(pSeed,nDoubleRange)-nRange;
        nX += CLIENTS_GetUnitX(pMissile);
        int nY = ITEMS_RollLimitedRandomNumber(pSeed,nDoubleRange)-nRange;
        nY += CLIENTS_GetUnitY(pMissile);
        if (!COLLISION_CheckMask(pRoom,nX,nY,COLLISION_MASK)) {
            D2MissileStrc params;
            memset(&params,0,sizeof(params));
            params.dwFlags = SPAWN_FLAGS;
            params.pOwner = pOwner;
            params.nSkill = MISSILE_GetSkill(pMissile);
            params.nSkillLevel = MISSILE_GetLevel(pMissile);
            params.nMissile = pRecord->wCltSubMissile[0];
            params.nX = nX;
            params.nY = nY;
            D2UnitStrc* pSub = MISSILE_CreateClientMissile(&params);
            if (pSub) CUNIT_MarkUnitDead(pSub);
            if (pRecord->wCltSubMissile[1] >= 0) {
                params.nMissile = pRecord->wCltSubMissile[1];
                MISSILE_CreateClientMissile(&params);
            }
        }
    }
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5C10
void __fastcall MISSILE_CltDoVolcano(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwCltParam[1];
    if (nAuraRange <= 0)
    {
        const int nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        nAuraRange = (nCalc >= 1) ? nCalc : 1;
    }

    int nFrames = pMissilesTxtRecord->dwCltParam[0];
    if (nFrames <= 0)
    {
        nFrames = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nFrames < 1)
        {
            nFrames = 1;
        }
    }

    const int nRemainingFrames = MISSILE_GetRemainingFrames(pMissile);
    if (nRemainingFrames > pMissilesTxtRecord->dwCltParam[2] && nRemainingFrames < pMissilesTxtRecord->dwCltParam[3] && !(nRemainingFrames % nFrames))
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        SEED_InitLowSeed(pSeed, MISSILE_GetTargetX(pMissile));
        int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        nX += CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile) + SEED_RollLimitedRandomNumber(pSeed, 2 * nAuraRange + 1) - nAuraRange;
        MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
        MISSILE_SubmitOffsetRequest(pMissile, pMissilesTxtRecord->wCltSubMissile[0], 0, 0, nX, nY, MISSILE_GetSkill(pMissile), nLevel, pMissilesTxtRecord->dwCltParam[4]);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004CDC30
D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = CUNIT_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        {
            return 0;
        }
    }

    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    if (!nRange)
    {
        nRange = 30;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x521;
    tRequest.pUnit = pOwner;
    tRequest.nArg1 = CLIENTS_GetUnitX(pUnit) + nOffsetX;
    tRequest.nArg2 = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg7 = nRange;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

// 0x004D37F0
void __fastcall MISSILE_CltDoSeekTarget(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pMissile)))
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (MISSILE_GetTargetX(pMissile) & 1)
    {
        GFX_RefreshPathTarget(pMissile);
        D2UnitStrc* pTarget = PATH_GetTargetUnit(pMissile->pDynamicPath);
        if (pTarget && (CUNIT_IsDeadOrDying(pTarget) || (pOwner && !CUNIT_IsHostileTo(pOwner, pTarget))))
        {
            pTarget = 0;
        }

        int nRate = pMissilesTxtRecord->dwCltParam[0];
        if (nRate <= 0)
        {
            nRate = 5;
        }

        if (pTarget && !(sub_0064A3B0_GetElapsedFrames(pMissile) % nRate))
        {
            const int nDistance = DRLG_UnitEdgeDistance(pMissile, pTarget);
            if (nDistance >= 4 && nDistance <= 0x18)
            {
                D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D38D0
void __fastcall MISSILE_CltDoTimedSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) >= pMissilesTxtRecord->nCanDestroy && PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        missileParams.nX = CLIENTS_GetUnitX(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        int nLoops = pMissilesTxtRecord->dwCltParam[0];
        missileParams.nLoops = nLoops < 1 ? 1 : nLoops;
        missileParams.pInitFunc = (MissileInitFunc)sub_004CC870_SubMissileCallback;
        missileParams.nInitArg = (int)pMissile;
        MISSILE_CreateClientMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3C40
void __fastcall MISSILE_CltDoRangeSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nMissile = pMissilesTxtRecord->wCltSubMissile[0];
    if (nMissile < pMissilesTxtRecord->wCltSubMissile[1])
    {
        nMissile += ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->wCltSubMissile[1] - nMissile + 1);
    }

    int nLevel = MISSILE_GetLevel(pMissile);
    nLevel /= MAX(pMissilesTxtRecord->dwCltParam[2], 1);
    int nCount = pMissilesTxtRecord->dwCltParam[0] + MAX(nLevel, 2);
    int nRange = MAX(pMissilesTxtRecord->dwCltParam[1] - nLevel, 3);
    D2UnitStrc* pNew = MISSILE_SpawnAtRandomUnitInRange(pMissile, nCount, nRange, nMissile);
    if (pNew)
    {
        MISSILE_InitCltParamMotion(pNew);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3D00
void __fastcall MISSILE_CltDoFrameEndFree(D2UnitStrc* pMissile)
{
    if (UNITS_IsAtEndOfFrameCycle(pMissile))
    {
        CUNIT_MarkUnitDead(pMissile);
        CUNIT_FreeLight(pMissile);
    }
    else
    {
        MISSILE_CltDoCommon(pMissile);
    }
}

// 0x004D3D30
void __fastcall MISSILE_CltDoTiming(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->dwCltParam[0] <= 0 || pMissilesTxtRecord->dwCltParam[1] <= 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (!sub_0064A3B0_GetElapsedFrames(pMissile))
    {
        int nFrames = pMissilesTxtRecord->dwCltParam[1];
        int nThird = nFrames / 3;
        int nOuter = nThird * 25000 / 25;
        int nInner = (nFrames - 2 * nThird) * 25000 / 25;
        sub_00476A80_StartTiming(pMissilesTxtRecord->dwCltParam[0], nOuter, nInner, nOuter);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3E00
void __fastcall MISSILE_CltDoTimedRequests(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[0])
    {
        MISSILE_SubmitMissileRequest(CUNIT_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    if (pMissilesTxtRecord->wCltSubMissile[1] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[1])
    {
        MISSILE_SubmitMissileRequest(CUNIT_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[1], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    if (pMissilesTxtRecord->wCltSubMissile[2] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[2])
    {
        MISSILE_SubmitMissileRequest(CUNIT_GetOwnerUnit(pMissile), pMissilesTxtRecord->wCltSubMissile[2], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4040
void __fastcall MISSILE_CltDoHoming(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pMissile);
    if (!pTarget)
    {
        pTarget = CUNIT_GetPathTargetUnit(pOwner);
        if (!pTarget)
        {
            MISSILE_CltDoCommon(pMissile);
            return;
        }
    }

    int nRate = pMissilesTxtRecord->dwCltParam[2];
    if (nRate <= 0)
    {
        nRate = 5;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate == 0 && DRLG_UnitEdgeDistance(pMissile, pTarget) <= pMissilesTxtRecord->dwCltParam[3])
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        int nTargetX = CLIENTS_GetUnitX(pTarget);
        int nTargetY = CLIENTS_GetUnitY(pTarget);
        int nStep = pMissilesTxtRecord->dwCltParam[4];
        if (nStep < 1)
        {
            nStep = 1;
        }

        int nOffsetX = 0;
        int nOffsetY = 0;
        if (nTargetX > nX)
        {
            nOffsetX = nStep;
        }
        else if (nTargetX < nX)
        {
            nOffsetX = -nStep;
        }

        if (nTargetY > nY)
        {
            nOffsetY = nStep;
        }
        else if (nTargetY < nY)
        {
            nOffsetY = -nStep;
        }

        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
    }

    MISSILE_CltDoCommon(pMissile);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < sgptDataTables->nSkillsTxtRecordCount && nSkillId >= 0)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x004D4180
void __fastcall MISSILE_CltDoHomingSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nTargetX = MISSILE_GetTargetX(pMissile);
    if (nTargetX <= -pMissilesTxtRecord->dwCltParam[1])
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (nTargetX <= 0)
    {
        MISSILE_SetTargetX(pMissile, nTargetX - 1);
    }

    if (!PATH_GetVelocity(pMissile->pDynamicPath))
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    D2UnitStrc* pTarget = PATH_GetTargetUnit(pMissile->pDynamicPath);
    if (!pTarget)
    {
        pTarget = CUNIT_GetPathTargetUnit(pOwner);
    }

    int nRate = pMissilesTxtRecord->dwCltParam[2];
    if (nRate <= 0)
    {
        nRate = 5;
    }

    if (pTarget && !(sub_0064A380_GetRemainingFrames(pMissile) % nRate) && nTargetX > 0
        && DRLG_UnitEdgeDistance(pMissile, pTarget) < pMissilesTxtRecord->dwCltParam[3])
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);
        int nTargetUnitX = CLIENTS_GetUnitX(pTarget);
        int nTargetUnitY = CLIENTS_GetUnitY(pTarget);
        int nStep = pMissilesTxtRecord->dwCltParam[4] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[4];

        int nDeltaX = 0;
        int nDeltaY = 0;
        if (nTargetUnitX > nX)
        {
            nDeltaX = nStep;
        }
        else if (nTargetUnitX < nX)
        {
            nDeltaX = -nStep;
        }

        if (nTargetUnitY > nY)
        {
            nDeltaY = nStep;
        }
        else if (nTargetUnitY < nY)
        {
            nDeltaY = -nStep;
        }

        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nDeltaX, CLIENTS_GetUnitY(pMissile) + nDeltaY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        int nPeriod = pMissilesTxtRecord->dwCltParam[0] > 1 ? pMissilesTxtRecord->dwCltParam[0] : 1;
        if (!(sub_0064A380_GetRemainingFrames(pMissile) % nPeriod) && nTargetX > 0)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 5;
            missileParams.nX = CLIENTS_GetUnitX(pMissile);
            missileParams.nY = CLIENTS_GetUnitY(pMissile);
            missileParams.nRange = MISSILE_GetTotalFrames(pMissile) - 1;
            missileParams.nVelocity = 0;
            missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            missileParams.pOwner = pOwner;
            missileParams.nSkill = MISSILE_GetSkill(pMissile);
            missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&missileParams);
            if (pSubMissile)
            {
                MISSILE_SetTargetX(pSubMissile, 0);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D43A0
void __fastcall MISSILE_CltDoRandomSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0 || !CUNIT_GetOwnerUnit(pMissile))
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        if (SEED_RollLimitedRandomNumber(&pMissile->pSeed, 4))
            tParams.dwFlags = 0x4021;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nX = CLIENTS_GetUnitX(pMissile);
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nTargetX = CLIENTS_GetUnitX(pMissile);
        tParams.nTargetY = CLIENTS_GetUnitY(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        MISSILE_CreateClientMissile(&tParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D44B0
void __fastcall MISSILE_CltDoBurst(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nSubMissile = sub_0064A510_GetSubMissile(pMissile);
    if (!nSubMissile)
    {
        nSubMissile = pMissilesTxtRecord->wCltSubMissile[0];
    }

    if (nSubMissile < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nCount = sub_0064A570_GetSubMissileCount(pMissile);
    if (nCount <= 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) < pMissilesTxtRecord->dwCltParam[0] && sub_0064A3B0_GetElapsedFrames(pMissile) % 3 == 0)
    {
        int nPerStep = nCount > 4 ? nCount / 2 : nCount;
        int nMult = nCount > 4 ? 2 : 1;
        MISSILE_SpawnBurst(pMissile, nCount, nSubMissile, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nPerStep, nMult);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4590
void __fastcall MISSILE_CltDoCopySubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0 && sub_0064A3B0_GetElapsedFrames(pMissile) >= pMissilesTxtRecord->nCanDestroy && PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        int nX = CLIENTS_GetUnitX(pMissile);
        int nY = CLIENTS_GetUnitY(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];

        D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&missileParams);
        if (pSubMissile)
        {
            PATH_SetDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
            PATH_SetPrecisionX(pSubMissile->pDynamicPath, UNITS_GetPrecisionX(pMissile));
            PATH_SetPrecisionY(pSubMissile->pDynamicPath, UNITS_GetPrecisionY(pMissile));
            GFXUTIL_SetMotionVectorA(pSubMissile, 0, 0, GFXUTIL_GetMotionAZ(pMissile));
        }

        MISSILE_CltDoCommon(pMissile);
        return;
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D46D0
void __fastcall MISSILE_CltDoRing(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    int nRate = pMissilesTxtRecord->dwCltParam[0] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[0];
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate <= 0)
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        int nIndex = MISSILE_GetTargetX(pMissile) % 64;
        if (nIndex < 0)
        {
            nIndex = -nIndex;
        }

        missileParams.nTargetX = gaCltDoRingOffsetX[nIndex];
        missileParams.nTargetY = gaCltDoRingOffsetY[nIndex];
        MISSILE_SetTargetX(pMissile, (pMissilesTxtRecord->dwCltParam[1] + nIndex) % 64);
        MISSILE_CreateClientMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4B80
void __fastcall MISSILE_CltDoFrameFloor(D2UnitStrc* pMissile)
{
    if (sub_0064A380_GetRemainingFrames(pMissile) < 100)
    {
        MISSILE_SetCurrentFrame(pMissile, 500);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4BB0
void __fastcall MISSILE_CltDoObjectSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    const int nParam = pMissilesTxtRecord->dwCltParam[0];
    const int nEnd = nParam + 0x7D;
    if (nFrames < pMissilesTxtRecord->wRange - nParam && nFrames > nParam && pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        D2UnitStrc* pNew = MISSILE_SpawnAtRandomUnitInRange(pMissile, pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->wCltSubMissile[0]);
        if (pNew)
        {
            MISSILE_InitMotion(pNew);
        }
    }

    if (nFrames < nEnd && nFrames > nParam)
    {
        D2UnitStrc* pUnit = UNITS_GetRoom(pMissile)->pUnitFirst;
        do
        {
            if (!pUnit)
                break;
            if (pUnit->dwUnitType == UNIT_OBJECT && (unsigned int)pUnit->dwClassId >= 0x11 && (unsigned int)pUnit->dwClassId < 0x16)
            {
                if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
                {
                    const int nLevel = MISSILE_GetLevel(pMissile);
                    D2UnitStrc* pNew = (D2UnitStrc*)MISSILE_SubmitMissileRequest(pOwner, pMissilesTxtRecord->wCltSubMissile[0], CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), MISSILE_GetSkill(pMissile), nLevel);
                    if (pNew)
                    {
                        MISSILE_InitMotion(pNew);
                    }
                }

                if (pMissilesTxtRecord->wCltSubMissile[1] > 0 && !(nFrames % 8))
                {
                    int nTargetId = MISSILE_GetTargetX(pMissile);
                    D2UnitStrc* pTarget = nTargetId ? CUNIT_FindClientUnit(nTargetId, 2) : 0;
                    if (!pTarget)
                    {
                        MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                    }
                    else
                    {
                        D2MissileStrc tMissile;
                        memset(&tMissile, 0, sizeof(tMissile));
                        tMissile.dwFlags = 0x421;
                        tMissile.pOwner = pOwner;
                        tMissile.nX = CLIENTS_GetUnitX(pUnit);
                        tMissile.nY = CLIENTS_GetUnitY(pUnit);
                        tMissile.nSkill = MISSILE_GetSkill(pMissile);
                        tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);
                        tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                        tMissile.nTargetX = CLIENTS_GetUnitX(pTarget);
                        tMissile.nTargetY = CLIENTS_GetUnitY(pTarget);
                        MISSILE_CreateClientMissile(&tMissile);
                        if (!SEED_RollLimitedRandomNumber(&pTarget->pSeed, 4))
                        {
                            MISSILE_SetTargetX(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
                        }
                    }
                }
            }
            pUnit = pUnit->ptRoomNext;
        } while (pUnit);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5200
void __fastcall MISSILE_CltDoOwnerQuad(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwCltParam[0])
    {
        int nX = CLIENTS_GetUnitX(pOwner);
        int nY = CLIENTS_GetUnitY(pOwner);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x2001;
        missileParams.pOwner = pOwner;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        for (int i = 0; i < 4; ++i)
        {
            missileParams.nX = gaQuadOffsetX[i] + nX;
            missileParams.nY = gaQuadOffsetY[i] + nY;
            MISSILE_CreateClientMissile(&missileParams);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

inline unsigned int SEED_RollLimitedRandomNumber_004D1EC0(D2SeedStrc* pSeed, int nMax)
{
    if (nMax > 0)
    {
        const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        pSeed->nLowSeed = (unsigned int)lSeed;
        if ((nMax - 1) & nMax)
        {
            return (unsigned int)lSeed % nMax;
        }
        return (unsigned int)lSeed & (nMax - 1);
    }
    return 0;
}

inline int UNITS_GetClassId_004D1EC0(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x004D5470
void __fastcall MISSILE_CltDoScatterSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames == pMissilesTxtRecord->dwCltParam[0])
    {
        MISSILE_SetTargetY(pMissile, 1);
    }

    if (MISSILE_GetTargetY(pMissile))
    {
        const int nRate = pMissilesTxtRecord->dwCltParam[1] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[1];
        if (!(nFrames % nRate))
        {
            D2SeedStrc* pSeed = &pMissile->pSeed;
            const int nRange = pMissilesTxtRecord->dwCltParam[2];
            const int nOffsetX = ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;
            const int nOffsetY = ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;

            D2MissileStrc tMissileParams;
            memset(&tMissileParams, 0, sizeof(tMissileParams));
            tMissileParams.dwFlags = 0x21;
            tMissileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
            tMissileParams.nX = CLIENTS_GetUnitX(pMissile);
            tMissileParams.nY = CLIENTS_GetUnitY(pMissile);
            tMissileParams.nTargetX = CLIENTS_GetUnitX(pMissile) + nOffsetX;
            tMissileParams.nTargetY = CLIENTS_GetUnitY(pMissile) + nOffsetY;
            tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
            tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tMissileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            MISSILE_CreateClientMissile(&tMissileParams);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D56B0
void __fastcall MISSILE_CltDoParamCallSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    MISSILE_SpawnRingAround(pMissile, pMissilesTxtRecord->dwCltParam[0], pMissilesTxtRecord->dwCltParam[1], pMissilesTxtRecord->dwCltParam[2], pMissilesTxtRecord->wCltSubMissile[0]);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5880
void __fastcall MISSILE_CltDoPathSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || !pMissilesTxtRecord->wCltSubMissile[0])
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 9;
        missileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        missileParams.nX = CLIENTS_GetUnitX(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nLoops = pMissilesTxtRecord->dwCltParam[0];
        MISSILE_CreateClientMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5950
void __fastcall MISSILE_CltDoProgSound(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (pMissilesTxtRecord->wProgSound > 0)
    {
        int nOldValue = MISSILE_GetTargetX(pMissile);
        int nNewValue = GFXUTIL_GetMotionFirstParam(pMissile);
        if (nOldValue && nOldValue != nNewValue)
        {
            sub_004B9A00(pMissilesTxtRecord->wProgSound, pMissile, 0, 0, 0);
        }

        MISSILE_SetTargetX(pMissile, nNewValue);
    }

    MISSILE_CltDoRandomTrail(pMissile);
}

// 0x004D5BA0
void __fastcall MISSILE_CltDoPeriodicSub(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    int nRate = pMissilesTxtRecord->dwCltParam[0];
    if (nRate < 1)
    {
        nRate = 1;
    }

    if (!(nFrames % nRate))
    {
        sub_004CED20(pMissile, pMissilesTxtRecord->wCltSubMissile[0]);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D6540
void __fastcall MISSILE_CltDoTimedSound(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    if (nFrames == CLTDO_TIMING_FRAME)
    {
        sub_00476A80_StartTiming(CLTDO_TIMING_ARG, 0, CLTDO_TIMING_LENGTH, 0);
    }
    else if (nFrames == CLTDO_SOUND_FRAME)
    {
        sub_004B9A00(CLTDO_SOUND_ID, 0, 0, 0, 0);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D6590
void __fastcall MISSILE_CltDoAnimSpeedSteps(D2UnitStrc* pMissile)
{
    switch (sub_0064A3B0_GetElapsedFrames(pMissile))
    {
    case CLTDO_SLOW_FRAME:
        sub_004DA250(pMissile, 0, 0, CLTDO_SLOW_FLAG, 0);
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed >> 1);
        break;

    case CLTDO_FAST_FRAME:
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed * 2);
        break;
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D65E0
void __fastcall MISSILE_CltDoOffsetMissileTimer(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    int nCounter = MISSILE_GetTargetY(pMissile);
    if (!nCounter)
    {
        const int nUnitId = MISSILE_GetTargetX(pMissile);
        ((D2SpawnOffsetMissileView*)nUnitId)->SKILLS_SpawnOffsetMissile(pMissile, pOwner);
        nCounter = (unsigned int)SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10;
    }

    --nCounter;
    MISSILE_SetTargetY(pMissile, nCounter);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004CF3C0
int __fastcall MISSILE_CltHitUnit(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pMissilesTxtRecord->dwCltHitPar[0] && pOwner && (CUNIT_IsPetSkillTarget(pOwner, pUnit) || CUNIT_IsTargetBlocked(pOwner, pUnit)))
    {
        if (pMissilesTxtRecord->wProgOverlay > 0)
        {
            GFX_AddUnitOverlay(pUnit, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
            return 1;
        }

        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pMissilesTxtRecord->dwCltHitPar[1])
        {
            return 0;
        }
        break;

    case UNIT_MONSTER:
        switch (pMissilesTxtRecord->dwCltHitPar[1])
        {
        case 2:
            if (!MONSTERS_IsDemon(pUnit))
            {
                return 0;
            }
            break;

        default:
            if (!MONSTERS_IsUndead(pUnit))
            {
                return 0;
            }
            break;
        }
        break;

    default:
        return 0;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        D2MissileStrc tMissile;
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.pOwner = pOwner;
        tMissile.pOrigin = pMissile;
        tMissile.nSkill = MISSILE_GetSkill(pMissile);
        tMissile.nSkillLevel = MISSILE_GetLevel(pMissile);
        tMissile.nMissile = MISSILE_TEETHEXPLODE;
        MISSILE_CreateClientMissile(&tMissile);
    }

    return 1;
}

// 0x004CF500
int __fastcall MISSILE_CltHitSpawnSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int aSubMissiles[3];
    int nCount = 0;
    for (nCount = 0; nCount < 3; ++nCount)
    {
        const short nSubMissile = pMissilesTxtRecord->wCltHitSubMissile[nCount];
        if (nSubMissile < 0)
        {
            break;
        }
        aSubMissiles[nCount] = nSubMissile;
    }

    if (nCount <= 0)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[0];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(CUNIT_GetOwnerUnit(pMissile), pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nMissileId = pMissile->dwClassId;
    int nRange = MISSILE_EvaluateMissileFormula(pMissile, CUNIT_GetOwnerUnit(pMissile), pMissilesTxtRecord->dwHitCalc, nMissileId, nLevel);
    if (nRange <= 0)
    {
        nRange = pMissilesTxtRecord->wRange + pMissilesTxtRecord->wLevRange * (nLevel - 1);
    }

    MISSILE_SpawnMissilesInRange(pMissile, aSubMissiles, nCount, nParam, nRange, pMissilesTxtRecord->dwCltHitPar[1]);
    return 1;
}

// 0x004CF640
int __fastcall MISSILE_CltHitPatternSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] < 0)
    {
        return 1;
    }

    const unsigned int nPattern = SEED_RollRandomNumber(&pMissile->pSeed) % 3;
    const int nOffset = SEED_RollRandomNumber(&pMissile->pSeed) & 7;
    for (int i = 0; i < gaCltHitPatterns[nPattern].nCount; ++i)
    {
        const int nIndex = (gaCltHitPatterns[nPattern].aIndex[i] + nOffset) & 7;
        D2UnitStrc* pSubMissile = MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[1], 0, 0, sub_0064A280(pMissile), sub_0064A210(pMissile));
        if (pSubMissile)
        {
            D2Common_10216(pSubMissile->pDynamicPath, gaCltHitOffsetX[nIndex] + nX, gaCltHitOffsetY[nIndex] + nY, 0);
        }
    }

    return 1;
}

// 0x004D0060
int __fastcall MISSILE_CltHitScanArea(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (!CUNIT_FindClientUnit(MISSILE_targetValue(pMissile), MISSILE_GetMissileTargetStatus(pMissile)))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }

    int nFlags = pSkillsTxtRecord->dwAuraFilter;
    if (nFlags)
    {
        nFlags = 0xA683;
    }

    D2MissileScanArgStrc tArg;
    tArg.pOwner = pOwner;
    tArg.pMissile = pMissile;
    tArg.nSkillId = nSkillId;
    tArg.nSkillLevel = nSkillLevel;
    tArg.nSubMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    SKILLS_ScanArea(pOwner, nX, nY, nRange, nFlags, MISSILE_HitScanCallback, &tArg, 0);
    return 1;
}

// 0x004D06F0
int __fastcall MISSILE_CltHitSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], 0, 0, nSkill, nSkillLevel);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        MISSILE_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->wCltHitSubMissile[1], nSkill, nSkillLevel, pMissilesTxtRecord->dwCltHitPar[1], 1);
    }

    if (pUnit)
    {
        GFX_AddUnitOverlay(pUnit, 0x97, 2, 0, 0, 0, 0, 0);
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner && pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        GFX_AddUnitOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
    }
    return 1;
}

// 0x004D0920
int __fastcall MISSILE_CltHitCollisionBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    if (!COLLISION_CheckMaskWithSize(UNITS_GetRoom(pMissile), UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile), 3, 1))
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            MISSILE_SpawnMissilesInRange(pMissile, gaCollisionBurstMissiles, 3, pMissilesTxtRecord->dwParam[0], 0x19, 0x4B);
        }
    }

    return 1;
}

// 0x004D0A80
int __fastcall MISSILE_CltHitBurst(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    int nCount = pMissilesTxtRecord->dwCltHitPar[0] + (nSkillLevel - 1) * pMissilesTxtRecord->dwCltHitPar[1];
    if (nCount <= 0)
    {
        const int nSkill = MISSILE_GetSkill(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkill, nSkillLevel);
        if (nCount < 1)
        {
            nCount = 1;
        }
    }

    SKILLS_ScatterRequestsAroundTarget(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0], nCount, nCount / 4, MISSILE_GetSkill(pMissile), nSkillLevel);
    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        MISSILE_SubmitOwnerRequest(pMissile, pMissilesTxtRecord->wCltHitSubMissile[1], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }
    return 1;
}

// 0x004D0FF0
int __fastcall MISSILE_CltHitCreateSubMissile(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (!pUnit)
    {
        sub_004CED20(pMissile, pMissilesTxtRecord->wCltHitSubMissile[0]);
        return 1;
    }

    return 0;
}

// 0x004D1040
int __fastcall MISSILE_CltHitTripleSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        MISSILE_CreateClientMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        MISSILE_CreateClientMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[2] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[2];
        MISSILE_CreateClientMissile(&missileParams);
    }

    return 1;
}

// 0x004D1110
int __fastcall MISSILE_CltHitSubMissileDir(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;

    D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&missileParams);
    if (pSubMissile)
    {
        PATH_SetDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
    }

    return 1;
}

// 0x004D11D0
int __fastcall MISSILE_CltHitBurstNoUnit(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pHitUnit)
    {
        return 0;
    }

    MISSILE_SpawnBurst(pMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->wCltHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwCltHitPar[1], 1);
    return 1;
}

// 0x004D1240
int __fastcall MISSILE_CltHitSubMissilesWithMotion(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        MISSILE_CreateClientMissile(&missileParams);
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&missileParams);
        if (pSubMissile)
        {
            GFXUTIL_SetMotionVectorA(pSubMissile, 0, 0, pMissilesTxtRecord->dwCltHitPar[0]);
        }
    }

    return 1;
}

// 0x004CD2D0
static int MISSILE_GetFrameDelay(int nFrames)
{
    if (nFrames < 0x96)
        return 0x14;
    if (nFrames < 0xC8)
        return 0xF;
    if (nFrames < 0xE1)
        return 0xA;
    return nFrames < 0x177 ? 5 : 0x19;
}

// 0x004D1FA0
static void __stdcall MISSILE_SpawnBehindOwner(int nMissileId, D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int nDirX = 0;
    int nDirY = 0;
    sub_0063EE10_GetMonsterDirectionDelta(pOwner, &nDirX, &nDirY);
    D2_ASSERT(nDirX || nDirY, 0x1850);
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    tParams.pOwner = pOwner;
    tParams.nMissile = nMissileId;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nX = UNITS_GetUnitXPosition(pMissile) + SEED_RollRandomNumber(&pMissile->pSeed) % 20 - 10;
    tParams.nY = UNITS_GetUnitYPosition(pMissile) + SEED_RollRandomNumber(&pMissile->pSeed) % 20 - 10;
    D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
    if (!pNew)
        return;
    D2_ASSERT(SKILLS_GetMissilesTxtRecord(nMissileId)->wRange == 25, 0x1861);
    int nScreenX = nDirX * -25;
    int nScreenY = nDirY * -25;
    int nOffsetX = nDirX;
    int nOffsetY = nDirY;
    DUNGEON_GameSubtileToClientCoords(&nScreenX, &nScreenY);
    DUNGEON_GameSubtileToClientCoords(&nOffsetX, &nOffsetY);
    GFXUTIL_SetMotionVectorA(pNew, nScreenX, nScreenY, 0x190);
    GFXUTIL_SetMotionVectorB(pNew, nOffsetX, nOffsetY, -0x10, 1);
    GFXUTIL_UpdateMotion(pNew);
}

// 0x004D6660
void __fastcall MISSILE_CltDoClearFrameWithOwner(D2UnitStrc* pMissile)
{
    if (CUNIT_GetOwnerUnit(pMissile))
    {
        pMissile->nSeqCurrentFramePrecise = 0;
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D6FA0
void __fastcall MISSILE_CltDoLinked(D2UnitStrc* pMissile)
{
    D2SeedStrc* pSeed = &pMissile->pSeed;
    int nPrevState = MISSILE_targetValue(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    D2UnitStrc* pLinked = CUNIT_FindServerSideUnit(MISSILE_GetMissileTargetStatus(pMissile), 3);
    if (pLinked)
    {
        int nState = MISSILE_GetMissileTargetStatus(pLinked);
        int nDistance = DRLG_UnitEdgeDistance(pMissile, pLinked);
        int nMin = MAX(1, (int)((unsigned int)SEED_RollRandomNumberInline(pSeed) % 5));

        if (nPrevState != nState && nState > 1)
        {
            MISSILE_SetTargetY(pMissile, nState);
            switch (nState)
            {
            case 4:
                GFXUTIL_ReplaceMotionFlag1With8(pMissile);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 20, 1);
                GFXUTIL_SetMotionVectorC(pMissile, 0, 0, 400, 0);
                GFXUTIL_SetMotionFlagMask(pMissile, 1);
                D2Common_10142(pPath, pMissile, 0);
                MISSILE_CltDoCommon(pMissile);
                return;

            case 3:
                GFXUTIL_ReplaceMotionFlag1With8(pMissile);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -6, 1);
                GFXUTIL_SetMotionVectorC(pMissile, 0, 0, SEED_RollLimitedRandomNumber(pSeed, 40), 0);
                GFXUTIL_SetMotionFlagMask(pMissile, 0);
                D2Common_10142(pPath, pMissile, 0);
                MISSILE_CltDoCommon(pMissile);
                return;

            case 2:
// build: symbol ?gszMissileSourceFile@* 0x006DAEF4
                PATH_SetVelocity(pPath, 0, gszMissileSourceFile, 6004);
                GFXUTIL_ReplaceMotionFlag1With8(pMissile);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 6, 1);
                GFXUTIL_SetMotionVectorC(pMissile, 0, 0, SEED_RollLimitedRandomNumber(pSeed, 40) + 170, 0);
                GFXUTIL_SetMotionFlagMask(pMissile, 1);
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pLinked), CLIENTS_GetUnitY(pLinked));
                PATH_SetVelocity(pPath, 0x300, gszMissileSourceFile, 6012);
                D2Common_10142(pPath, pMissile, 0);
                MISSILE_CltDoCommon(pMissile);
                return;
            }
        }
        else if (nDistance < nMin && !nPrevState)
        {
            MISSILE_SetTargetY(pMissile, 1);
            GFXUTIL_ReplaceMotionFlag1With8(pMissile);
            GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 1, 1);
            MISSILE_CltDoCommon(pMissile);
            return;
        }
        else if (nPrevState == 1)
        {
            int nDiffX = -CLIENTS_GetUnitX(pLinked) + CLIENTS_GetUnitX(pMissile);
            int nDiffY = -CLIENTS_GetUnitY(pLinked) + CLIENTS_GetUnitY(pMissile);
            if (nDiffX || nDiffY)
            {
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pMissile) - nDiffY, CLIENTS_GetUnitY(pMissile) + nDiffX);
                PATH_SetVelocity(pPath, 0xA00, gszMissileSourceFile, 6046);
                D2Common_10142(pPath, pMissile, 0);
            }
        }
        else if (nPrevState == 3)
        {
            D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pLinked), CLIENTS_GetUnitY(pLinked));
            PATH_SetVelocity(pPath, 0x200, gszMissileSourceFile, 6055);
            D2Common_10142(pPath, pMissile, 0);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D1BD0
int __fastcall MISSILE_CltHitScatterNoUnit(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, MISSILE_targetValue(pMissile));
    const int nCount = MISSILE_GetTargetX(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x21;
    tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tParams.nX = nX;
    tParams.nY = nY;
    tParams.nMissile = MISSILE_RADAMENTHOLYBOLT;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    for (int i = 0; i < nCount; ++i)
    {
        unsigned __int64 lSeed = SEED_RollRandomNumber64(pSeed);
        const int nTargetX = (unsigned int)lSeed % 20 - 10 + nX;
        lSeed = SEED_RollNextHL_Inline(pSeed, lSeed);
        const int nTargetY = (unsigned int)lSeed % 20 - 10 + nY;

        tParams.nTargetX = nTargetX;
        tParams.nTargetY = nTargetY;
        if (nTargetX == nX && nTargetY == nY)
        {
            --i;
            continue;
        }

        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
        if (pNew)
        {
            SKILLDESC_InitCappedChargedPath(pNew, nTargetX);
        }
    }

    return 1;
}

// 0x004D3F10
void __fastcall MISSILE_ClientMissileDo(D2UnitStrc* pMissile)
{
    struct { int nValue1; int nLevel; D2UnitStrc* pOwner; int nRange; } tLocal;
    D2MissilesTxt* pMissilesTxt;
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxt = &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }
    else
    {
        pMissilesTxt = 0;
    }
    if (!pMissilesTxt || pMissilesTxt->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    int nMin = pMissilesTxt->wCltSubMissile[0];
    tLocal.nRange = nMin;
    if (nMin < pMissilesTxt->wCltSubMissile[1])
    {
        tLocal.nRange = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxt->wCltSubMissile[1] - nMin + 1) + nMin;
    }

    int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxt;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    else
    {
        pSkillsTxt = 0;
    }
    if (!pSkillsTxt)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    tLocal.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tLocal.nLevel = MISSILE_GetLevel(pMissile);
    tLocal.nValue1 = SKILLS_EvaluateSkillFormula(tLocal.pOwner, pSkillsTxt->dwCalc[0], nSkillId, tLocal.nLevel);
    int nValue2 = SKILLS_EvaluateSkillFormula(tLocal.pOwner, pSkillsTxt->dwCalc[1], nSkillId, tLocal.nLevel);
    if (nValue2 && tLocal.nValue1 > 0)
    {
        D2UnitStrc* pTarget = MISSILE_SpawnAtRandomUnitInRange(pMissile, tLocal.nValue1, nValue2, tLocal.nRange);
        if (pTarget)
        {
            MISSILE_InitCltParamMotion(pTarget);
        }
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    MISSILE_CltDoDefault(pMissile);
}

// 0x004D72C0
void __fastcall MISSILE_CltDoPeriodicSpawn(D2UnitStrc* pMissile)
{
    if (!(sub_0064A380_GetRemainingFrames(pMissile) % 4))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x2521;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nMissile = MISSILE_QUEENDEATHGLOB;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        const int nX = UNITS_GetUnitXPosition(pMissile);
        tParams.nX = nX;
        const int nY = UNITS_GetUnitYPosition(pMissile);
        tParams.nY = nY;
        tParams.nTargetX = nX - SEED_RollRandomNumber(&pMissile->pSeed) % 12;
        tParams.nTargetY = SEED_RollRandomNumber(&pMissile->pSeed) % 13 + nY - 6;
        MISSILE_CreateClientMissile(&tParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D7690
void __fastcall MISSILE_CltDoOwnerSpawner(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    int nValue = MISSILE_GetTargetX(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    if (!nValue)
    {
        if (SEED_RollRandomNumber(&pMissile->pSeed) & 1)
            MISSILE_SpawnBehindOwner(MISSILE_CATAPULT_COLD_BALL, pOwner, pMissile);
        else
            MISSILE_SpawnBehindOwner(MISSILE_CATAPULT_METEOR_BALL, pOwner, pMissile);
        nValue = MISSILE_GetFrameDelay(sub_0064A3B0_GetElapsedFrames(pMissile));
    }
    MISSILE_SetTargetX(pMissile, nValue - 1);
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D7710
void __fastcall MISSILE_CltDoSpawner(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pOwner)
    {
        MISSILE_SpawnRandomBolt(pOwner, pMissile);
        MISSILE_SpawnRandomBolt(pOwner, pMissile);

        if (nFrames > 60 && !(nFrames % 20))
        {
            MISSILE_SpawnRandomShard(pOwner, pMissile);
        }

        if (nFrames == 25)
        {
            int nY = UNITS_GetUnitYPosition(pMissile);
            int nX = UNITS_GetUnitXPosition(pMissile);
            MISSILE_SubmitMissileRequest(pOwner, 0x26A, nX + 2, nY + 2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
            nY = UNITS_GetUnitYPosition(pMissile);
            nX = UNITS_GetUnitXPosition(pMissile);
            MISSILE_SubmitMissileRequest(pOwner, 0x269, nX + 2, nY + 2, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D7E00
void __fastcall MISSILE_CltDoStateTarget(D2UnitStrc* pMissile)
{
    D2UnitStrc* pStateUnit;
    D2SeedStrc* pSeed = &pMissile->pSeed;
    const int nState = MISSILE_GetTargetY(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    unsigned int const tArg1 = MISSILE_GetTargetX(pMissile);
    pStateUnit = CUNIT_FindServerSideUnit(tArg1, 3);
    if (pStateUnit)
    {
        const int nNewState = MISSILE_GetTargetX(pStateUnit);
        if (nState != nNewState && nNewState >= 2 && !SEED_RollLimitedRandomNumber(pSeed, 25))
        {
            MISSILE_SetTargetY(pMissile, nNewState);
            switch (nNewState)
            {
            case 2:
                PATH_SetVelocity(pPath, 0xF00, gszMissileFile_006DAEF4, 0x19DB);
                D2COMMON_10170_PathSetTargetPos(pPath, 0x3B1F, 0x170C);
                D2Common_10142(pPath, pMissile, 0);
                break;
            }
        }
        else if (nState == 0)
        {
            if (!(SEED_RollRandomNumber(pSeed) % 10))
            {
                MISSILE_SetTargetY(pMissile, 1);
                GFXUTIL_ReplaceMotionFlag1With8(pMissile);
                PATH_SetVelocity(pPath, 0xF00, gszMissileFile_006DAEF4, 0x19E6);
                if (SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 1, 1);
                    MISSILE_CltDoCommon(pMissile);
                    return;
                }
            }
        }
        else if (nState == 1)
        {
            int nDX = CLIENTS_GetUnitX(pMissile) - CLIENTS_GetUnitX(pStateUnit);
            int nDY = CLIENTS_GetUnitY(pMissile) - CLIENTS_GetUnitY(pStateUnit);
            if (pMissile->dwUnitId & 2)
            {
                nDX = -nDX;
                nDY = -nDY;
            }
            if (nDX || nDY)
            {
                D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pMissile) - nDY, CLIENTS_GetUnitY(pMissile) + nDX);
                D2Common_10142(pPath, pMissile, 0);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D7FC0
void __fastcall MISSILE_CltDoZRange(D2UnitStrc* pMissile)
{
    const int nMin = -MISSILE_GetTargetX(pMissile);
    const int nMax = MISSILE_GetTargetY(pMissile);
    const int nZ = GFXUTIL_GetMotionAZ(pMissile);
    if (nZ >= nMin && nZ <= nMax)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    MISSILE_CltDoDefault(pMissile);
}

// 0x004D8000
void __fastcall MISSILE_CltDoEruption(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (nFrame < 110)
    {
        int nCount;
        if (!nFrame)
        {
            MISSILE_SubmitMissileRequest(pOwner, 0x214, nX, nY, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
            nCount = nFrame + 8;
        }
        else if (nFrame < 50)
        {
            nCount = 8;
        }
        else
        {
            nCount = nFrame < 80 ? 5 : 1;
        }
        for (int i = 0; i < nCount; ++i)
        {
            const int nLevel = MISSILE_GetLevel(pMissile);
            const int nSkill = MISSILE_GetSkill(pMissile);
            if (pOwner)
            {
                D2MissileStrc tParams;
                memset(&tParams, 0, sizeof(tParams));
                tParams.pOwner = pOwner;
                tParams.dwFlags = 1;
                tParams.nX = nX + 2;
                tParams.nY = nY + 2;
                tParams.nSkill = nSkill;
                tParams.nSkillLevel = nLevel;
                tParams.nMissile = MISSILE_ANYASTEAM1;
                D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
                if (pNew)
                {
                    const unsigned int nRoll1 = SEED_RollRandomNumber(&pMissile->pSeed);
                    const unsigned int nRoll2 = SEED_RollRandomNumber(&pMissile->pSeed);
                    const unsigned int nRoll3 = SEED_RollRandomNumber(&pMissile->pSeed);
                    GFXUTIL_SetMotionVectorA(pNew, 50 - nRoll1 % 100, 50 - nRoll2 % 100, 0);
                    GFXUTIL_SetMotionVectorB(pNew, 0, 0, (nRoll3 & 7) + 2, 1);
                }
            }
        }
    }
    if (nFrame == 5)
        sub_00476A80_StartTiming(nFrame - 2, 0x258, 0xFA0, 0xBB8);
    if (nFrame < 200 && !(nFrame % 7))
        MISSILE_SpawnAtFreeSpot(pOwner, nX, nY, pMissile);
    MISSILE_CltDoCommon(pMissile);
}


// 0x004CE530
static D2UnitStrc* __stdcall MISSILE_SpawnSubMissile(D2UnitStrc* pOwner, int nMissile, int nSpread, D2UnitStrc* pMissile)
{
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 2;
    tMissile.nMissile = nMissile;
    tMissile.pOwner = pOwner;
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = sub_0064A280(pMissile);
    tMissile.nSkillLevel = sub_0064A210(pMissile);

    tMissile.nTargetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
    const int nY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
    tMissile.nTargetY = nY;
    if (!tMissile.nTargetX && !nY)
    {
        tMissile.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, nSpread - 1) + 1;
    }

    const int nX = tMissile.nTargetX;

    D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissile);
    if (pNew)
    {
        MISSILE_SetTargetX(pNew, nX);
        MISSILE_SetTargetY(pNew, nY);
    }

    return pNew;
}

// 0x004D5310
void __fastcall MISSILE_CltDoSubMissiles(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxt = pMissile ? DATATBLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pMissilesTxt)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pMissilesTxt->wCltSubMissile[0] > 0 && nFrame > 10)
    {
        MISSILE_SpawnPeriodicMissile(pOwner, pMissile, pMissilesTxt->wCltSubMissile[0], nFrame, MISSILE_GetSubMissileCount(pMissilesTxt, nFrame));
    }

    const int nPeriod = pMissilesTxt->dwCltParam[0] < 1 ? 1 : pMissilesTxt->dwCltParam[0];
    if (pMissilesTxt->wCltSubMissile[1] > 0 && !(nFrame % nPeriod))
    {
        MISSILE_SpawnSubMissile(pOwner, pMissilesTxt->wCltSubMissile[1], 0x14, pMissile);
    }

    const int nParam = pMissilesTxt->dwCltParam[1];
    if (nParam > 0 && nFrame == 90)
    {
        const int nA = nParam / 3;
        const int nTimeA = nA * 25000 / 25;
        const int nTimeB = (nParam - 2 * nA) * 25000 / 25;
        sub_00476A80_StartTiming(8, nTimeA, nTimeB, nTimeA);
    }

    if (pMissilesTxt->wCltSubMissile[2] > 0 && (unsigned int)(nFrame - 0x74) <= 0xC6)
    {
        MISSILE_DispatchSubMissileSpawn(pOwner, pMissile, pMissilesTxt->wCltSubMissile[2], nFrame);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5DD0
void __fastcall MISSILE_CltDoTimedBurst(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrame = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (pMissilesTxtRecord->wCltSubMissile[0] >= 0 && nFrame == pMissilesTxtRecord->dwCltParam[0])
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        tParams.dwFlags = 0x2001;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nX = nX;
        tParams.nY = nY;
        MISSILE_CreateClientMissile(&tParams);
        const int nRange = pMissilesTxtRecord->dwCltParam[3];
        for (int i = 0; i < pMissilesTxtRecord->dwCltParam[2]; ++i)
        {
            tParams.nX = nX - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);
            tParams.nY = nY - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);
            MISSILE_CreateClientMissile(&tParams);
        }
    }

    if (pMissilesTxtRecord->wCltSubMissile[1] >= 0 && nFrame == pMissilesTxtRecord->dwCltParam[1])
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        if (pOwner)
        {
            pOwner->dwFlagEx |= 0x40000;
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 0x2000;
            tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
            if (pNew && pMissilesTxtRecord->wProgSound > 0)
                sub_004B9A00(pMissilesTxtRecord->wProgSound, pNew, 0, 0, 0);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D5F80
void __fastcall MISSILE_CltDoMirrorPair(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        int nTargetX = MISSILE_GetTargetX(pMissile);
        int nTargetY = MISSILE_GetTargetY(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
        MISSILE_CreateClientMissile(&missileParams);
        missileParams.nTargetX = -nTargetX;
        missileParams.nTargetY = -nTargetY;
        MISSILE_CreateClientMissile(&missileParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D6080
void __fastcall MISSILE_CltDoOwnerSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        MISSILE_CreateClientMissile(&missileParams);
    }

    MISSILE_CltDoSeekTarget(pMissile);
}

// 0x004D62B0
void __fastcall MISSILE_CltDoOwnerTarget(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    MISSILE_CltDoOwnerStep(pMissile);

    int nX;
    int nY;
    if (ITEM_GetTargetPosition(pOwner, &nX, &nY))
    {
        int nCount = MISSILE_GetTargetY(pMissile);
        if (nCount < MISSILE_GetTargetX(pMissile))
        {
            MISSILE_SetTargetY(pMissile, nCount + 1);
        }

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x20;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pOwner;
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];

        D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&missileParams);
        if (pSubMissile)
        {
            PATH_SetType(pSubMissile->pDynamicPath, 0xE);
            D2Common_10142(pSubMissile->pDynamicPath, pSubMissile, 0);
        }

        MISSILE_SetTargetY(pMissile, 0);
        MISSILE_CltDoCommon(pMissile);
    }
}


// 0x004E1090
int __fastcall MISSILE_SkillDoClearTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam2(pSkill);
    int nY = SKILLS_GetParam3(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, 0);
    SKILLS_SetParam3(pSkill, 0);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    COLLISION_ResetMaskWithPattern(pRoom, nX, nY, 1, 0x100);
    return 1;
}

// 0x004E18F0
int __fastcall MISSILE_SkillStartCltCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    return 1;
}

// 0x004E27C0
int __fastcall MISSILE_SkillStartSpawnRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pMissileA = sub_004C5470_CreateMissileToTarget(pUnit, MISSILE_HELLMETEORDOWN, nSkillId, nSkillLevel);
    D2UnitStrc* pMissileB = sub_004C5470_CreateMissileToTarget(pUnit, MISSILE_HELLMETEORBALL, nSkillId, nSkillLevel);
    D2UnitStrc* pRequestA = MISSILE_SubmitMissileRequest(pUnit, 0x14F, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestB = MISSILE_SubmitMissileRequest(pUnit, 0x151, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestC = MISSILE_SubmitMissileRequest(pUnit, 0x14E, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);
    D2UnitStrc* pRequestD = MISSILE_SubmitMissileRequest(pUnit, 0x14D, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), nSkillId, nSkillLevel);

    if (pRequestA)
    {
        GFXUTIL_SetMotionVectorB(pRequestA, 0, 0, 15, 1);
    }

    if (pRequestB)
    {
        GFXUTIL_SetMotionVectorB(pRequestB, 0, 0, 15, 1);
    }

    if (pMissileA)
    {
        GFXUTIL_SetMotionVectorA(pMissileA, 0, 0, 0x15F9);
        GFXUTIL_SetMotionVectorB(pMissileA, 0, 0, -25, 1);
    }

    if (pMissileB)
    {
        GFXUTIL_SetMotionVectorA(pMissileB, 0, 0, 0x15F9);
        GFXUTIL_SetMotionVectorB(pMissileB, 0, 0, -25, 1);
    }

    if (pRequestC)
    {
        sub_00621780_SetMissileArg(pRequestD, 0x80);
        sub_00621780_SetMissileArg(pRequestC, 0x80);
    }

    return 1;
}

// 0x004E3350
int __fastcall MISSILE_CheckTargetInRange(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    nRange *= nRange;
    if (PATH_ComputeSquaredDistance(CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), CLIENTS_GetUnitXInline(pTarget), CLIENTS_GetUnitYInline(pTarget)) > nRange)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            return 0;
        }

        pRoom = UNITS_GetRoom(pTarget);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            return 0;
        }

        if (!CUNIT_IsHostileTo(pUnit, pTarget))
        {
            return 0;
        }
        break;
    }
    }

    return 1;
}

inline int MISSILE_GetApproxOffsetLengthInline(int nX, int nY)
{
    int nAbsX = nX < 0 ? -nX : nX;
    int nAbsY = nY < 0 ? -nY : nY;
    if (nX >= nY)
        return (nAbsX + 2 * nAbsY) >> 1;
    return (nAbsY + 2 * nAbsX) >> 1;
}

// 0x004D19D0
static void __stdcall MISSILE_SpawnFragmentRing(int nTargetUnitId, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(MISSILE_HFFRAGMENT1);
    int aOffsetX[14] = { -4, 2, 4, -3, -2, 3, 5, -3, -5, 5, -6, -1, 0, 6 };
    int aOffsetY[14] = { 6, 4, -4, -2, 1, 7, 0, 3, -4, -3, 4, -5, 5, -3 };
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
        return;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x8102;
    tParams.nMissile = MISSILE_HFFRAGMENT1;
    tParams.pOwner = pOwner;
    tParams.pOrigin = pMissile;
    tParams.nSkill = sub_0064A280(pMissile);
    tParams.nSkillLevel = sub_0064A210(pMissile);
    for (int i = 0; i < 14; ++i)
    {
        const int nX = aOffsetX[i];
        const int nY = aOffsetY[i];
        tParams.nTargetX = nX;
        tParams.nTargetY = nY;
        tParams.nRange = pMissilesTxtRecord->wRange * MISSILE_GetApproxOffsetLengthInline(nX, nY) / 6;
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, nTargetUnitId);
            MISSILE_SetTargetY(pNew, SEED_RollRandomNumber(&pMissile->pSeed) % 35 + 10);
        }
    }
}

// 0x004D6680
void __fastcall MISSILE_CltDoObjectRing(D2UnitStrc* pMissile)
{
    const int nTargetUnitId = MISSILE_GetTargetX(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (!CUNIT_FindClientUnit(nTargetUnitId, 2))
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    if (nFrames == 10)
    {
        MISSILE_SpawnFragmentRing(nTargetUnitId, pMissile);
        sub_00476A80_StartTiming(nFrames - 6, nFrames + 0x46, 0x50, 0x190);
    }
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D6C00
void __fastcall MISSILE_CltDoRateTable(D2UnitStrc* pMissile)
{
    int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);

    int i = 0;
    for (i = 0; i < 5; ++i)
    {
        if (nRemaining > gaCltRateTable[i].nThreshold)
        {
            break;
        }
    }

    if (nRemaining % gaCltRateTable[i].nRate == 0)
    {
        int nY = UNITS_GetUnitYPosition(pMissile);
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nLevel = MISSILE_GetLevel(pMissile);
        int nSkill = MISSILE_GetSkill(pMissile);
        if (pOwner)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 1;
            missileParams.pOwner = pOwner;
            missileParams.nX = nX;
            missileParams.nY = nY;
            missileParams.nSkill = nSkill;
            missileParams.nSkillLevel = nLevel;
            missileParams.nMissile = MISSILE_RADAMENTHANDOFGOD;

            D2UnitStrc* pNewMissile = MISSILE_CreateClientMissile(&missileParams);
            if (pNewMissile)
            {
                MISSILE_SetTargetX(pNewMissile, gaCltRateTable[i].nValue);
                MISSILE_SetTargetY(pNewMissile, nRemaining);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

static inline unsigned int SEED_RollUnitSeedInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004D6D40
void __fastcall MISSILE_CltDoRateJitterSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380(pMissile);

    int i = 0;
    for (i = 0; i < 4; ++i)
    {
        if (nRemaining > gaCltRateJitter[i].nThreshold)
        {
            break;
        }
    }

    if (nRemaining % gaCltRateJitter[i].nRate == 0)
    {
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nY = UNITS_GetUnitYPosition(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        missileParams.nMissile = MISSILE_TAINTEDSUNFLASH;
        sub_0064A280(pMissile);
        missileParams.nSkill = sub_0064A280(pMissile);
        missileParams.nSkillLevel = sub_0064A210(pMissile);

        for (int j = 0; j < gaCltRateJitter[i].nValue; ++j)
        {
            int nOffsetX = (int)(SEED_RollUnitSeedInline(pMissile) % 10) - 5;
            if ((nOffsetX < 0 ? -nOffsetX : nOffsetX) < 2)
                nOffsetX = 5;

            int nOffsetY = (int)(SEED_RollUnitSeedInline(pMissile) % 10) - 5;
            if ((nOffsetY < 0 ? -nOffsetY : nOffsetY) < 2)
                nOffsetY = 5;

            missileParams.nX = nX + 2 * nOffsetX;
            missileParams.nY = nY + 2 * nOffsetY;
            D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&missileParams);
            if (pSubMissile)
                MISSILE_SetTargetX(pSubMissile, GAME_GetUnitGUID(pMissile));
        }
    }

    if (nRemaining < 0x19)
        MISSILE_SetTargetX(pMissile, 3);
    else if (nRemaining < 0x4B)
        MISSILE_SetTargetX(pMissile, 2);

    if (nRemaining <= 1)
    {
        D2UnitStrc* pTarget = CUNIT_FindClientUnit(MISSILE_targetValue(pMissile), 2);
        if (pTarget)
        {
            GFX_AddUnitOverlay(pTarget, 0xB6, 3, 0, 0, 0, 0, 0);
            if (!pTarget->pLight)
                pTarget->pLight = DLIGHTMAP_MakeLightEntry(pTarget, 2, 0x3C, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

static inline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x004D7400
void __fastcall MISSILE_CltDoScatterRate(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A380_GetRemainingFrames(pMissile);
    if (nFrames == 325)
    {
        sub_00476A80_StartTiming(0x14, 0, 6000, 0);
    }

    int nIndex = 0;
    while (nIndex < 4 && nFrames <= gaScatterRates[nIndex].nFrames)
    {
        ++nIndex;
    }

    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);
    if (!(nFrames % gaScatterRates[nIndex].nRateA))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x2001;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nMissile = MISSILE_EXPLODINGARROWEXP;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2SeedStrc* pSeed = &pMissile->pSeed;
        D2SeedStrc tSeed;
        const int nOffsetX = SEED_RollFromInline(pSeed, &tSeed) % 40 - 20;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pSeed->nHighSeed = tSeed.nHighSeed;
        pSeed->nLowSeed = tSeed.nLowSeed;
        const int nOffsetY = nRoll % 40 - 20;
        tParams.nX = nX + nOffsetX;
        tParams.nY = nY + nOffsetY;
        MISSILE_CreateClientMissile(&tParams);
    }

    if (!(nFrames % gaScatterRates[nIndex].nRateB))
    {
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x2001;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nMissile = MISSILE_DURIELDEATHROCK;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2SeedStrc* pSeed = &pMissile->pSeed;
        D2SeedStrc tSeed;
        const int nOffsetX = SEED_RollFromInline(pSeed, &tSeed) % 40 - 20;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pSeed->nHighSeed = tSeed.nHighSeed;
        pSeed->nLowSeed = tSeed.nLowSeed;
        const int nOffsetY = nRoll % 40 - 20;
        tParams.nX = nX + nOffsetX;
        tParams.nY = nY + nOffsetY;
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
        if (pNew)
        {
            GFXUTIL_SetMotionVectorA(pNew, 0, 0, 150);
            GFXUTIL_SetMotionVectorB(pNew, 0, 0, -10, 1);
            MISSILE_SetTotalFrames(pNew, 15);
            MISSILE_SetCurrentFrame(pNew, 15);
            sub_0064A690_SetMissileAnimSpeed(pNew, 0x80);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}


// 0x004E34E0
int __fastcall MISSILE_StartMissileEffect(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissile, nSkillLevel);
    nVelocity += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    SKILLS_StartUnitEffect(pUnit, pUnit, nMissile, -1, nSkillId, nSkillLevel, nVelocity);
    return 1;
}

// 0x004D14A0
int __fastcall MISSILE_CltHitFollowUp(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    int nFollowUp = -1;
    switch (sub_0064A3E0_GetMissileClassId(pMissile))
    {
    case 0x110:
        nFollowUp = 0x158;
        break;

    case 0x111:
    case 0x112:
    case 0x1A1:
        nFollowUp = 0x159;
        break;
    }

    D2UnitStrc* pNewMissile = MISSILE_SubmitMissileRequest(CUNIT_GetOwnerUnit(pMissile), nFollowUp, UNITS_GetUnitXPosition(pMissile), UNITS_GetUnitYPosition(pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNewMissile)
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2DynamicPathStrc* pNewPath = pNewMissile->pDynamicPath;
        PATH_SetDirection(pNewPath, PATH_GetDirection(pPath));
        sub_00621780_SetMissileArg(pNewMissile, 0x80);
    }

    return 1;
}

// 0x004D1D70
int __fastcall MISSILE_CltHitLinkMissile(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_FindServerSideUnit(MISSILE_GetTargetX(pMissile), 3);
    if (pTarget)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0xA021;
        tMissileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tMissileParams.nMissile = MISSILE_TAINTEDSUNBALL;
        tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
        tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tMissileParams.nRange = sub_0064A380_GetRemainingFrames(pTarget);
        tMissileParams.nX = UNITS_GetUnitXPosition(pMissile);
        tMissileParams.nY = UNITS_GetUnitYPosition(pMissile);
        tMissileParams.nTargetX = UNITS_GetUnitXPosition(pTarget);
        tMissileParams.nTargetY = UNITS_GetUnitYPosition(pTarget);
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissileParams);
        if (pNew)
        {
            MISSILE_SetTargetX(pNew, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }

    return 1;
}

// 0x004D1EC0
int __fastcall MISSILE_CltHitRolledRequest(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    D2SeedStrc* pSeed = &pMissile->pSeed;
    if ((int)SEED_RollLimitedRandomNumber_004D1EC0(pSeed, 2) > 0)
    {
        return 1;
    }

    const int nMissile = UNITS_GetClassId_004D1EC0(pMissile) + SEED_RollLimitedRandomNumber_004D1EC0(pSeed, 2) + 1;
    D2UnitStrc* pNew = MISSILE_SubmitOwnerRequest(pMissile, nMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    if (pNew)
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2DynamicPathStrc* pNewPath = pNew->pDynamicPath;
        PATH_SetDirection(pNewPath, PATH_GetDirection(pPath));
        D2COMMON_10203_PATH_SetRotateFlag(pNewPath, 0);
    }

    return 1;
}

// 0x004CD240
int __fastcall MISSILE_IsOwnersPet(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (pOwner->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nRosterId = ROSTERPETS_FindRosterIndex(pUnit->dwUnitId);
    const int nOwnerId = !pOwner ? -1 : pOwner->dwUnitId;
    return nRosterId == nOwnerId;
}

// 0x004CD290
static inline void MISSILE_ApplyAnimSpeedSteps(D2UnitStrc* pMissile, int nFrame)
{
    switch (nFrame)
    {
    case CLTDO_SLOW_FRAME:
        sub_004DA250(pMissile, 0, 0, CLTDO_SLOW_FLAG, 0);
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed >> 1);
        break;

    case CLTDO_FAST_FRAME:
        sub_00621780_SetMissileArg(pMissile, pMissile->wAnimSpeed * 2);
        break;
    }
}

// 0x004D1F50
int __fastcall MISSILE_CltHitSpawnRequest(D2UnitStrc* pMissile, D2UnitStrc* pHitUnit)
{
    if (pHitUnit)
    {
        return 0;
    }

    SKILLS_ScatterRequestsAroundTarget(pMissile, MISSILE_DURIELDEATHDEBRIS, 3, 6, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    MISSILE_SubmitOwnerRequest(pMissile, 0x16E, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    return 1;
}

// 0x004D1890
int __fastcall MISSILE_SpawnHellfireFragments(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord;
    if (sgptDataTables->nMissilesTxtRecordCount<=0x175) pRecord=0;
    else pRecord=&sgptDataTables->pMissilesTxt[0x175];
    D2UnitStrc* pOwner=CUNIT_GetOwnerUnit(pMissile);
    if (pOwner) {
        D2MissileStrc tParams;
        memset(&tParams,0,sizeof(tParams));
        tParams.dwFlags=0x8005;
        tParams.pOwner=pOwner;
        tParams.nMissile=MISSILE_HFFRAGMENT3;
        tParams.nSkill=MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel=MISSILE_GetLevel(pMissile);
        tParams.nVelocity=0;
        tParams.nRange=pRecord->wRange;
        tParams.nX=UNITS_GetUnitXPosition(pMissile);
        tParams.nY=UNITS_GetUnitYPosition(pMissile);
        D2UnitStrc* pNew=MISSILE_CreateClientMissile(&tParams);
        if(pNew) {
            MISSILE_SetTargetX(pNew,MISSILE_GetTargetX(pMissile));
            MISSILE_SetTargetY(pNew,SEED_RollRandomNumber(&pMissile->pSeed)%35+10);
        }
    }
    return 1;
}

// 0x004D0EB0
int __fastcall MISSILE_CltHitLob(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tMissileParams.nX = UNITS_GetUnitXPosition(pMissile);
    tMissileParams.nY = UNITS_GetUnitYPosition(pMissile);
    tMissileParams.nSkill = MISSILE_GetSkill(pMissile);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissileParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tMissileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath);
    tMissileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath);

    D2UnitStrc* pSubMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (!pSubMissile)
    {
        return 1;
    }

    GFXUTIL_SetMotionParams(pSubMissile, pMissilesTxtRecord->dwCltHitPar[0], pMissilesTxtRecord->dwCltHitPar[1]);
    GFXUTIL_SetBallistic(pSubMissile, 0, pMissilesTxtRecord->dwCltHitPar[2]);
    GFXUTIL_ClearMotionFlagTwo(pSubMissile);
    return 1;
}

// 0x004D2AF0
int __fastcall MISSILE_CltDoScatterHit(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSeed = CLIENTS_GetUnitX(pMissile);
    SEED_InitLowSeed(&pMissile->pSeed, nSeed);
    const int nRange = pMissilesTxtRecord->dwCltHitPar[0] < 1 ? 1 : pMissilesTxtRecord->dwCltHitPar[0];
    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);
    const int nTargetX = nX - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);
    const int nTargetY = nY - nRange + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1);

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x20;
    tParams.pOwner = pOwner;
    tParams.pOrigin = pMissile;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    tParams.nTargetX = nTargetX;
    tParams.nTargetY = nTargetY;
    MISSILE_CreateClientMissile(&tParams);
    return 1;
}

// 0x004D30C0
void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile)
{
    if (!pMissile)
        return;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
        return;
    int bRepeat = 0;
    switch (gdwGlobal_007A0610)
    {
    case 0:
    case 1:
    case 6:
    case 8:
        if (CUNIT_GetOwnerUnit(pMissile) == sub_00463DD0_GetPlayerUnit())
            bRepeat = 1;
        break;
    }
    D2CltMissileFindArgStrc tFindArg;
    for (;;)
    {
        const int bActive = sub_0064A380_GetRemainingFrames(pMissile) <= sub_0064A640(pMissile);
        if (bActive && sub_0064A3B0_GetElapsedFrames(pMissile) > pMissilesTxtRecord->nCanDestroy)
            pMissile->dwFlagEx &= ~0x40000;
        if (!GFXUTIL_TestMotionFlags(pMissile))
        {
            MISSILE_CltMissileHit(pMissile, 0, 1);
            return;
        }
        if (bActive)
        {
            if (!pMissilesTxtRecord->nLoopAnim)
            {
                if (!sub_006217C0(pMissile))
                    UNITS_UpdateFrame(pMissile);
            }
            else
            {
                if (pMissilesTxtRecord->nSubLoop)
                {
                    const int nSubStop = pMissilesTxtRecord->nSubStop;
                    if (sub_0064A380_GetRemainingFrames(pMissile) <= pMissilesTxtRecord->nAnimLen - nSubStop + 1)
                        UNITS_UpdateFrame(pMissile);
                    else
                        D2COMMON_10375_UNITS_SetFrameNonRate(pMissile, pMissilesTxtRecord->nSubStart, nSubStop);
                }
                else
                {
                    UNITS_UpdateFrame(pMissile);
                }
            }
        }
        D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
        if (PATH_GetVelocity(pDynamicPath))
            sub_00650840(pMissile, GAME_GetPathFrame());
        MISSILE_SetCurrentFrame(pMissile, sub_0064A380_GetRemainingFrames(pMissile) - 1);
        if (sub_0064A380_GetRemainingFrames(pMissile) <= 0)
        {
            MISSILE_CltMissileHit(pMissile, 0, 0);
            return;
        }
        if (!bActive)
            return;
        if (pMissilesTxtRecord->nCltSrcTown > 0)
        {
            D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
            D2ActiveRoomStrc* pOwnerRoom;
            if (!pOwner || ((pOwnerRoom = UNITS_GetRoom(pOwner)) != 0 && DUNGEON_IsRoomInTown(pOwnerRoom)))
            {
                const int nFrame = pMissilesTxtRecord->nCltSrcTown;
                if (sub_0064A380_GetRemainingFrames(pMissile) >= nFrame)
                {
                    MISSILE_SetCurrentFrame(pMissile, nFrame);
                    if (!pMissilesTxtRecord->nLoopAnim)
                    {
                        const int nDelta = pMissilesTxtRecord->nAnimLen - pMissilesTxtRecord->nCltSrcTown;
                        if (nDelta > 0)
                            pMissile->nSeqCurrentFramePrecise = nDelta << 8;
                    }
                }
            }
        }
        const int nMissileMode = sub_00451F70_GetUnitMode(pMissile);
        if (!nMissileMode)
            return;
        const unsigned short nCollisionFlags = D2Common_10201(pDynamicPath);
        if (nCollisionFlags & 5)
        {
            MISSILE_CltMissileHit(pMissile, 0, 1);
            return;
        }
        if (nMissileMode == 6)
            return;
        tFindArg.pMissile = pMissile;
        tFindArg.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tFindArg.pMissilesTxtRecord = pMissilesTxtRecord;
        if (pMissilesTxtRecord->nClientCol && nCollisionFlags)
        {
            D2PathPointStrc* pPathPoints;
            const int nPathPoints = D2COMMON_10198_PathGetSaveStep(pDynamicPath, &pPathPoints);
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
            for (int i = 0; i < nPathPoints; ++i)
            {
                D2UnitStrc* pTarget = D2Common_10407(pRoom, pPathPoints[i].X, pPathPoints[i].Y, gaCltMissileModes[nMissileMode].pfUnitFindCallback, &tFindArg, UNITS_GetUnitSizeX(pMissile));
                if (pTarget && !CUNIT_IsDeadOrDying(pTarget))
                {
                    MISSILE_CltMissileHit(pMissile, pTarget, 0);
                    return;
                }
            }
        }
        if (!bRepeat)
            return;
        if (sub_0064A3B0_GetElapsedFrames(pMissile) != 1)
            return;
        if (!PATH_GetVelocity(pDynamicPath))
            return;
        bRepeat = 0;
    }
}

// 0x004CDD10
D2UnitStrc* __fastcall MISSILE_SubmitTargetRequest(D2UnitStrc* pUnit, int nArg0, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = pUnit;
    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        pOwner = CUNIT_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return 0;
        }
    }

    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pOwner, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x420;
    tRequest.pUnit = pOwner;
    tRequest.pOtherUnit = pUnit;
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

void __fastcall sub_M130_Emit_004CD290(D2UnitStrc* pMissile)
{
    MISSILE_ApplyAnimSpeedSteps(pMissile, sub_0064A3B0_GetElapsedFrames(pMissile));
}


// 0x004CDDB0
void __fastcall MISSILE_SpawnMissilesInRange(D2UnitStrc* pUnit, const int* pMissiles, int nMissiles, int nRange, int nOffset, int nChance)
{
    if (!UNITS_GetRoom(pUnit))
    {
        return;
    }

    int i = 0;
    int j = 0;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed)
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 1;
    if (nOffset)
    {
        tParams.dwFlags = 0x8001;
    }
    tParams.pOwner = CUNIT_GetOwnerUnit(pUnit);
    tParams.nSkill = sub_0064A280(pUnit);
    tParams.nSkillLevel = sub_0064A210(pUnit);

    const int nX = UNITS_GetUnitXPosition(pUnit);
    const int nY = UNITS_GetUnitYPosition(pUnit);
    const int nRangeSq = nRange * nRange;
    for (i = -nRange; i <= nRange; ++i)
    {
        for (j = -nRange; j <= nRange; ++j)
        {
            if (!MISSILE_CheckDistanceAndLineOfSight(nRangeSq, nX + i, nY + j, UNITS_GetRoom(pUnit), i, j))
            {
                continue;
            }

            D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pUnit), nX + i, nY + j);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
            {
                continue;
            }

            if (nOffset)
            {
                tParams.nRange = SEED_RollRandomNumber(pSeed) % 25 + nOffset - 12;
            }
            tParams.nX = nX + i;
            tParams.nY = nY + j;
            tParams.nMissile = pMissiles[SEED_RollLimitedRandomNumberInline(pSeed, nMissiles)];
            const int nRoll = SEED_RollRandomNumber(pSeed) % 100;
            if (nRoll < nChance)
            {
                MISSILE_CreateClientMissile(&tParams);
            }
        }
    }
}

// 0x004CF800
int __fastcall MISSILE_CltHitChain(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pPrevious;
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    if (pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        GFX_AddUnitOverlay(pUnit, pMissilesTxtRecord->wProgOverlay, 2, 0, 0, 0, 0, 0);
    }

    const int nParam = MISSILE_GetTargetX(pMissile);
    if (nParam <= 1)
    {
        return 1;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        const int nSkillId = sub_0064A280(pMissile);
        const int nLevel = sub_0064A210(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    pPrevious = pUnit;
    pUnit = SKILLS_ScanFindUnit(pOwner, nX, nY, nRange, 0x88583, !pUnit ? -1 : pUnit->dwUnitId, 0);
    if (!pUnit)
    {
        return 1;
    }

    if (pUnit == pPrevious)
    {
        return 1;
    }

    D2MissileStrc tMissileParams = {};
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pOwner;
    tMissileParams.pTarget = pUnit;
    tMissileParams.nMissile = pMissile->dwClassId;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nTargetX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nTargetY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = sub_0064A280(pMissile);
    tMissileParams.nSkillLevel = sub_0064A210(pMissile);

    D2UnitStrc* pChain = MISSILE_CreateClientMissile(&tMissileParams);
    if (pChain)
    {
        MISSILE_SetTargetX(pChain, nParam - 1);
        MISSILE_SetOwner(pChain, pPrevious);
    }

    return 1;
}

static inline void RotateOffsets(int* pX,int* pY)
{
    const int nOldX=*pX;
    const int nNegY=-*pY;
    __assume(nNegY != (-2147483647 - 1));
    *pX=(nNegY+nOldX)/2;
    *pY=(nOldX+*pY)/2;
}

// 0x004D47F0
void __fastcall MISSILE_CltDoPeriodicRetarget(D2UnitStrc* pMissile)
{
    int nOffsetX = 0;
    int nOffsetY = 0;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nPeriod = MAX(pMissilesTxtRecord->dwCltParam[1], 1);

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < pMissilesTxtRecord->dwCltParam[0] && !(nFrames % nPeriod))
    {
        nOffsetX = MISSILE_GetTargetX(pMissile);
        nOffsetY = MISSILE_GetTargetY(pMissile);
        RotateOffsets(&nOffsetX,&nOffsetY);
        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nOffsetX, CLIENTS_GetUnitY(pMissile) + nOffsetY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        MISSILE_SetTargetX(pMissile, nOffsetX);
        MISSILE_SetTargetY(pMissile, nOffsetY);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004CEA00
void __fastcall MISSILE_SpawnMissileInRadius(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissile, int nRadius)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (!UNITS_GetRoom(pUnit))
    {
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > nMissile)
    {
        nMissile = MISSILE_RollInRange(&pUnit->pSeed, nMissile, pMissilesTxtRecord->wCltSubMissile[0]);
        pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissile);
        if (!pMissilesTxtRecord)
        {
            return;
        }
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pOwner;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = MISSILE_GetSkill(pUnit);
    tMissileParams.nSkillLevel = MISSILE_GetLevel(pUnit);

    const int nRadiusSq = nRadius * nRadius;
    int nTries = 0;
    while (nTries < 4)
    {
        ++nTries;

        int nX = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, 2 * nRadius + 1) - nRadius;
        int nY = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, 2 * nRadius + 1) - nRadius;
        if (nX * nX + nY * nY > nRadiusSq)
        {
            continue;
        }

        nX += UNITS_GetUnitXPosition(pUnit);
        nY += UNITS_GetUnitYPosition(pUnit);

        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        if (!pRoom || COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, 0, 1))
        {
            continue;
        }

        tMissileParams.nX = nX;
        tMissileParams.nY = nY;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            PARTICLE_ResetGfxMotion(pMissile);
            if (nRadius == 6)
            {
                GFXUTIL_SetMotionVectorA(pMissile, 0, 0, 2 * pMissilesTxtRecord->dwCltParam[0]);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 2 * -pMissilesTxtRecord->dwCltParam[1], 1);
            }
            else
            {
                GFXUTIL_SetMotionVectorA(pMissile, 0, 0, pMissilesTxtRecord->dwCltParam[0]);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -pMissilesTxtRecord->dwCltParam[1], 1);
            }
            return;
        }
    }
}

// 0x004CECC0
void __fastcall MISSILE_DispatchSubMissileSpawn(D2UnitStrc* pOwner, D2UnitStrc* pMissile, int nMissile, int nFrame)
{
    if ((unsigned int)(nFrame - 0xC9) <= 0x17)
    {
        MISSILE_SpawnMissileInRadius(pOwner, pMissile, nMissile, 6);
        MISSILE_SpawnMissileInRadius(pOwner, pMissile, nMissile, 6);
        return;
    }

    if (!(nFrame % 4))
    {
        MISSILE_SpawnMissileInRadius(pOwner, pMissile, nMissile, 0x14);
    }
}

static inline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
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

static __forceinline unsigned int SEED_RollLimitedRandomNumberForceInl(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberInline(pSeed) % nMax;
    }

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x004D7930
void __fastcall MISSILE_CltDoBaalStormMissile(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner=CUNIT_GetOwnerUnit(pMissile);
    if(!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }
    int nFrames=MISSILE_GetCurrentFrame(pMissile);
    int nPhase;
    for(nPhase=0;nPhase<4;++nPhase)
    {
        if(nFrames>gaBaalStormPhases[nPhase].nFrameLimit)break;
    }
    if(!(nFrames%gaBaalStormPhases[nPhase].nPeriod) && gaBaalStormPhases[nPhase].bSpawn)
    {
        SEED_RollRandomNumber(&pMissile->pSeed);
        D2MissileStrc tParams;
        memset(&tParams,0,sizeof(tParams));
        tParams.pOwner=pOwner;
        tParams.nTargetX=SEED_RollRandomNumber(&pMissile->pSeed)%40-20;
        int nTargetY=SEED_RollRandomNumber(&pMissile->pSeed)%40-20;
        tParams.dwFlags=2;
        tParams.pOrigin=pMissile;
        tParams.nTargetY=nTargetY;
        tParams.nMissile=MISSILE_BAALFX_SPIRIT_1;
        tParams.nSkill=MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel=MISSILE_GetLevel(pMissile);
        D2UnitStrc* pNewMissile=MISSILE_CreateClientMissile(&tParams);
        if(pNewMissile)MISSILE_SetTargetX(pNewMissile,!pMissile ? -1 : pMissile->dwUnitId);
    }
    if(nFrames<210)MISSILE_SetTargetX(pMissile,2);
    else MISSILE_SetTargetX(pMissile,1);
    switch(nFrames)
    {
    case 450:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        MISSILE_SubmitMissileRequest(pOwner,631,nX+1,nY+1,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    case 425:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        MISSILE_SubmitMissileRequest(pOwner,632,nX,nY,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    case 375:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        MISSILE_SubmitMissileRequest(pOwner,633,nX,nY,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    case 325:
    {
        int nY=UNITS_GetUnitYPosition(pMissile);
        int nX=UNITS_GetUnitXPosition(pMissile);
        MISSILE_SubmitMissileRequest(pOwner,634,nX,nY,MISSILE_GetSkill(pMissile),MISSILE_GetLevel(pMissile));
        break;
    }
    }
    if(MISSILE_GetTargetY(pMissile))
    {
        D2UnitStrc* pTarget=UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pMissile),1,521);
        if(pTarget)
        {
            const unsigned __int64 lSeed1=(unsigned __int64)pMissile->pSeed.nHighSeed+(unsigned __int64)pMissile->pSeed.nLowSeed*0x6AC690C5;
            int nOffsetX=(unsigned int)lSeed1%10-5;
            const unsigned __int64 lSeed2=(lSeed1>>32)+(unsigned __int64)(unsigned int)lSeed1*0x6AC690C5;
            pMissile->pSeed.nHighSeed=(unsigned int)(lSeed2>>32);
            pMissile->pSeed.nLowSeed=(unsigned int)lSeed2;
            int nOffsetY=(unsigned int)lSeed2%10-5;
            int nX=UNITS_GetUnitXPosition(pTarget)+nOffsetX;
            int nY=UNITS_GetUnitYPosition(pTarget)+nOffsetY;
            MISSILE_SpawnBaalBolt(pMissile, nX, nY);
        }
    }
    MISSILE_CltDoCommon(pMissile);
}

// 0x004D2D70
D2UnitStrc* __fastcall MISSILE_CltMissileHit(D2UnitStrc* pMissile, D2UnitStrc* pTarget, int bArg)
{
    const int nMissileId = pMissile ? pMissile->dwClassId : -1;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    const int nSubMissile = (short)pMissilesTxtRecord->wExplosionMissile;
    D2UnitStrc* pSubMissile;
    int nResult = 3;
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    pSubMissile = 0;
    if (pMissile)
    {
        if (pTarget)
        {
            if (pMissilesTxtRecord->nNextHit && STATES_CheckState(pTarget, STATE_JUSTHIT))
                return 0;

            if (MISSILE_CheckUnitIfOwner(pMissile, pTarget))
                return 0;

            MISSILE_SetOwner(pMissile, pTarget);
            if (!UNITS_TestFlagBit(pTarget, 2))
                return 0;

            if (pOwner && !CUNIT_IsHostileTo(pOwner, pTarget) && !pMissilesTxtRecord->nCollideFriend)
                return 0;
        }

        if (pOwner && pTarget && (pMissilesTxtRecord->nMissileFlags[0] & gbChargeMissileMask_006CE270) && (unsigned int)pOwner->dwUnitType <= 1)
        {
            if (STATES_CheckState(pOwner, STATE_PIERCE) || STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_PIERCE, 0))
                nResult = MISSILE_UseCharge(pMissile);
        }

        if ((pTarget || bArg || pMissilesTxtRecord->nAlwaysExplode) && (nResult & 2))
        {
            if (pMissilesTxtRecord->nNextHit && pTarget)
            {
                const int nId = pTarget->dwUnitId;
                const int nType = pTarget->dwUnitType;
                D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 2, pMissilesTxtRecord->nNextDelay, nType, nId);
                if (pStatList)
                {
                    STATLIST_SetState(pStatList, STATE_JUSTHIT);
                    STATLIST_SetStatRemoveCallback(pStatList, MISSILE_StatRemoveToggleStateOff);
                    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
                    STATES_ToggleState(pTarget, 0x56, 1);
                }
            }

            CUNITEVENT_RunCltUnitEvents(0, pTarget, pMissile, 0);

            const short nCltHitFunc = pMissilesTxtRecord->wCltHitFunc;
            if (nCltHitFunc > 0 && nCltHitFunc < gnCltHitFuncCount && gpfnCltHitFuncs[nCltHitFunc])
            {
                if (!gpfnCltHitFuncs[nCltHitFunc](pMissile, pTarget))
                    return 0;
            }

            const short nHitSound = pMissilesTxtRecord->wHitSound;
            if (nHitSound >= 0)
                sub_004B9A00(nHitSound, pMissile, 0, 0, 0);

            if ((short)pMissilesTxtRecord->wExplosionMissile >= 0 && nSubMissile != -1)
            {
                pSubMissile = MISSILE_SubmitOwnerRequest(pMissile, nSubMissile, 0, 0, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
                if (pSubMissile)
                {
                    GFXUTIL_SetMotionVectorA(pSubMissile, GFXUTIL_GetMotionAX(pMissile), GFXUTIL_GetMotionAY(pMissile), GFXUTIL_GetMotionAZ(pMissile));
                    GFXUTIL_SetMotionFlag1(pSubMissile);
                    GFXUTIL_ReplaceMotionFlag1With8(pSubMissile);
                    if (pSubMissile->dwClassId != 0x92)
                        D2COMMON_10160_PathUpdateDirection(pSubMissile->pDynamicPath, PATH_GetDirection(pMissile->pDynamicPath));
                    else
                        D2COMMON_10160_PathUpdateDirection(pSubMissile->pDynamicPath, (unsigned char)SEED_RollLimitedRandomNumber(&pSubMissile->pSeed, 0x40));
                }
            }
        }

        if (pTarget && !pMissilesTxtRecord->nCollideKill)
            return 0;

        const short nProgSfx = pMissilesTxtRecord->wTravelSound;
        if (nProgSfx >= 0)
        {
            void* pUnitSfx = UNITSND_FindUnitSfxInRange(pMissile, nProgSfx);
            if (pUnitSfx)
                sub_004BA790_ReleaseUnitSfx(pUnitSfx, pMissile, 0);
        }

        D2GfxLightStrc* pLight = UNITS_ResetLightMap(pMissile);
        if (pLight)
            sub_00474470_ReleaseLight(pLight);

        if (nResult & 1)
        {
            const int bFlag = UNITS_TestFlagBit(pMissile, 0x15);
            const int nUnitType = pMissile->dwUnitType;
            const int nUnitId = pMissile->dwUnitId;
            if (bFlag)
            {
                CUNIT_RemoveServerSideUnit(nUnitId, nUnitType);
            }
            else
            {
                CUNIT_RemoveClientSideUnit(nUnitId, nUnitType);
            }
        }

        return pSubMissile;
    }

    return 0;
}

// 0x004CD310
static int MISSILE_UseCharge(D2UnitStrc* pUnit)
{
	int nResult = 3;
	D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(sub_0064A3E0(pUnit));

	if (!(pMissilesTxtRecord->nMissileFlags[0] & gbFlagMask_006CE270))
	    return nResult;
		const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_PIERCE_IDX, 0);
		if (nValue)
		{
			nResult = 2;
			STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, nValue - 1, 0);
		}

	return nResult;
}

static inline int MISSILE_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
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

static inline unsigned int sub_004CD420_RollSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004CD420
static void __stdcall MISSILE_RollPierce(D2UnitStrc* pOwner, D2UnitStrc* pMissile)
{
    int nPierce = 0;
    if (pOwner && pOwner->dwUnitType != UNIT_PLAYER && pOwner->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(MISSILE_GetClassId(pMissile));
    if (!(pMissilesTxtRecord->nMissileFlags[2 >> 3] & gdwBitMasks[2 & 7]))
    {
        return;
    }

    int nChance = STATLIST_UnitGetStatValue(pOwner, STAT_SKILL_PIERCE, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_PIERCE, 0);
    if (!nChance)
    {
        return;
    }

    D2SeedStrc tSeed;
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && sub_00463DD0_GetPlayerUnit() != pOwner)
    {
        nChance = 100;
        SEED_InitLowSeed(&tSeed, 0);
    }
    else
    {
        SEED_InitLowSeed(&tSeed, STATLIST_GetUnitBaseStat(pOwner, STAT_PIERCE_IDX, 0));
    }

    for (;;)
    {
        const int nRoll = nPierce < 4 ? (int)(sub_004CD420_RollSeed(&tSeed) % 100) : nChance;
        if (nRoll >= nChance)
        {
            break;
        }

        ++nPierce;
    }

    STATLIST_SetUnitStat(pMissile, STAT_PIERCE_IDX, nPierce, 0);
}

// 0x004CD540
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissileParams->nMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nX = 0;
    int nY = 0;
    if (pMissileParams->dwFlags & 1)
    {
        nX = pMissileParams->nX;
        nY = pMissileParams->nY;
    }
    else
    {
        if (!pMissileParams->pOrigin)
        {
            return 0;
        }

        nX = CLIENTS_GetUnitX(pMissileParams->pOrigin);
        nY = CLIENTS_GetUnitY(pMissileParams->pOrigin);
    }

    if (pMissileParams->pOwner)
    {
        if (!COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pMissileParams->pOwner), nX, nY)
            && !DUNGEON_FindRoomBySubtileCoordinates(gpGlobal_007A0634, nX, nY))
        {
            return 0;
        }
    }
    else
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && !COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pPlayer), nX, nY)
            && !DUNGEON_FindRoomBySubtileCoordinates(gpGlobal_007A0634, nX, nY))
        {
            return 0;
        }
    }

    int nTargetX;
    int nTargetY;
    if (pMissileParams->dwFlags & 2)
    {
        nTargetX = pMissileParams->nTargetX + nX;
        nTargetY = pMissileParams->nTargetY + nY;
    }
    else if (pMissileParams->dwFlags & 0x20)
    {
        nTargetX = pMissileParams->nTargetX;
        nTargetY = pMissileParams->nTargetY;
    }
    else
    {
        nTargetX = nX;
        nTargetY = nY;
    }

    int nVelocity = (pMissileParams->dwFlags & 4)
        ? ((pMissileParams->dwFlags & 0x10) ? pMissileParams->nVelocity : pMissileParams->nVelocity << 8)
        : (pMissilesTxtRecord->nVel + (pMissilesTxtRecord->nVelLev * pMissileParams->nSkillLevel) / 8) << 8;

    int nVelocityPercent = 100;
    if (pMissileParams->pOwner && (pMissilesTxtRecord->nMissileFlags[3 >> 3] & gdwBitMasks[3 & 7])
        && STATES_CheckState(pMissileParams->pOwner, STATE_SLOWMISSILES))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pMissileParams->pOwner, STATE_SLOWMISSILES);
        if (pStatList)
        {
            nVelocityPercent = STATLIST_GetStatValue(pStatList, STAT_SKILL_HANDOFATHENA, 0);
            nVelocity = DATATBLS_ApplyRatio(nVelocity, nVelocityPercent, 100);
        }
    }

    if (nVelocity)
    {
        nVelocity = MISSILE_ApplyRatio(nVelocity, 75, 100);
    }

    D2UnitStrc* pTarget = pMissileParams->pTarget;
    if (nVelocity)
    {
        if (pMissileParams->pOwner && !pTarget)
        {
            if (nTargetX == nX && nTargetY == nY)
            {
                ITEM_GetAdjacentPosition(pMissileParams->pOwner, &nTargetX, &nTargetY);
            }
        }
        else if (pTarget && pMissileParams->pOwner && pTarget != pMissileParams->pOwner
            && CLIENTS_GetUnitX(pTarget) == CLIENTS_GetUnitX(pMissileParams->pOwner)
            && CLIENTS_GetUnitY(pTarget) == CLIENTS_GetUnitY(pMissileParams->pOwner))
        {
            ITEM_GetAdjacentPosition(pMissileParams->pOwner, &nTargetX, &nTargetY);
            pTarget = 0;
        }

        int nDestX = nTargetX;
        int nDestY = nTargetY;
        if (pTarget)
        {
            nDestX = CLIENTS_GetUnitX(pTarget);
            nDestY = CLIENTS_GetUnitY(pTarget);
        }

        const int nXDiff = nDestX - nX;
        if (D2_ABS(nXDiff) >= 100)
        {
            return 0;
        }

        const int nYDiff = nDestY - nY;
        if (D2_ABS(nYDiff) >= 100)
        {
            return 0;
        }
    }

    D2UnitStrc* pMissile = CUNIT_SpawnPresetUnit(pMissileParams->nMissile, nX, nY, 3, 0);
    if (!pMissile)
    {
        return 0;
    }

    UNITS_SetAnimStartFrame(pMissile);
    STATLIST_AllocStatListEx(pMissile, 0, 0, 0);
    pMissile->dwFrameCountPrecise = pMissilesTxtRecord->nAnimLen << 8;
    MISSILE_SetAnimSpeed(pMissile, pMissilesTxtRecord->nAnimSpeed << 4);

    int nRange;
    if (pMissileParams->dwFlags & 0x8000)
    {
        nRange = pMissileParams->nRange;
    }
    else
    {
        nRange = pMissilesTxtRecord->wRange + pMissileParams->nSkillLevel * pMissilesTxtRecord->wLevRange;
        if (pMissileParams->dwFlags & 8 && pMissilesTxtRecord->nSubLoop)
        {
            nRange += pMissileParams->nLoops * (pMissilesTxtRecord->nSubStop - pMissilesTxtRecord->nSubStart);
        }

        if (nVelocityPercent && nVelocityPercent != 100)
        {
            nRange += DATATBLS_ApplyRatio(nRange, 100, nVelocityPercent);
        }
    }

    if (pMissileParams->dwFlags & 0x200)
    {
        nRange -= pMissileParams->nFrame;
        pMissile->nSeqCurrentFramePrecise = pMissileParams->nFrame << 8;
    }

    MISSILE_SetTotalFrames(pMissile, nRange);
    MISSILE_SetCurrentFrame(pMissile, nRange);

    if (pMissileParams->dwFlags & 0x800)
    {
        nRange -= pMissileParams->nActivateFrame;
    }
    else
    {
        nRange -= pMissilesTxtRecord->nActivate;
    }
    MISSILE_SetActivateFrame(pMissile, nRange);

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        sub_00465F00_RemoveClientUnit(pMissile->dwUnitId, pMissile->dwUnitType);
        return 0;
    }

    PATH_SetVelocity(pPath, 0, ".\\UNIT\\Missile.cpp", 7924);

    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pPath, nTargetX, nTargetY);
    }

    if (nVelocity)
    {
        PATH_SetVelocity(pPath, nVelocity, ".\\UNIT\\Missile.cpp", 7935);
        D2Common_10142(pPath, pMissile, 0);
    }

    if (pMissilesTxtRecord->nCanDestroy)
    {
        pMissile->dwFlagEx |= 0x40000;
    }

    MISSILE_SetOwner(pMissile, pMissileParams->pOwner);
    PATH_SetAcceleration(pPath, pMissilesTxtRecord->wAccel);
    PATH_SetMaxVelocity(pPath, pMissilesTxtRecord->nMaxVel << 8);

    if (pMissileParams->dwFlags & 0x2000)
    {
        PATH_SetDirection(pMissile->pDynamicPath, SEED_RollLimitedRandomNumber(&pMissile->pSeed, 0x40));
    }

    PARTICLE_ResetGfxMotion(pMissile);
    GFXUTIL_ReplaceMotionFlag1With8(pMissile);

    if (pMissileParams->dwFlags & 0x400)
    {
        unsigned int nDistance = UNITS_GetDistanceToCoordinates(pMissile, nTargetX, nTargetY);
        if (!nDistance)
        {
            nDistance = 1;
        }

        unsigned int nStep = nVelocity << 4;
        if (nStep)
        {
            const int nFrames = (nDistance << 16) / nStep;
            MISSILE_SetCurrentFrame(pMissile, nFrames);
            MISSILE_SetTotalFrames(pMissile, nFrames);
        }
    }

    if (pMissileParams->dwFlags & 0x100)
    {
        GFXUTIL_SetBallistic(pMissile, pMissileParams->nGfxArg, MISSILE_GetTotalFrames(pMissile));
        GFXUTIL_UpdateMotion(pMissile);
        PATH_SetDirection(pPath, (unsigned char)(nTargetX + nTargetY) & ~0xC0);
        D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
    }

    MISSILE_SetSkill(pMissile, pMissileParams->nSkill);
    MISSILE_SetLevel(pMissile, pMissileParams->nSkillLevel);

    if (pMissileParams->pOwner)
    {
        UNITS_StoreOwner(pMissile, pMissileParams->pOwner);
        MISSILE_RollPierce(pMissileParams->pOwner, pMissile);
    }

    pMissile->dwFlags &= ~8;

// build: symbol ?gbMissileLights@* 0x0072A348
    if (gbMissileLights && !(pMissileParams->dwFlags & 0x4000))
    {
        if (pMissilesTxtRecord->nLight || (unsigned char)pMissileParams->nLightRadius)
        {
            CUNIT_FreeLight(pMissile);
            pMissile->pLight = DLIGHTMAP_MakeLightEntry(pMissile, 1, pMissilesTxtRecord->nLight, 0xFF,
                pMissilesTxtRecord->nRed, pMissilesTxtRecord->nGreen, pMissilesTxtRecord->nBlue);
        }
    }
    else
    {
        CUNIT_FreeLight(pMissile);
    }

    if (pMissileParams->pInitFunc)
    {
        pMissileParams->pInitFunc(pMissile, pMissileParams->nInitArg);
    }

    if (pMissilesTxtRecord->wTravelSound)
    {
        const int nSound = (short)pMissilesTxtRecord->wTravelSound;
        if (nSound)
        {
            sub_004B9A00(nSound, pMissile, 0, 0, 0);
            if (pMissileParams->pOwner)
            {
                void* pUnitSfx = UNITSND_FindUnitSfxInRange(pMissileParams->pOwner, 0x13A);
                if (pUnitSfx)
                {
                    sub_004BA840(pUnitSfx);
                }
            }
        }
    }

    if (pMissileParams->pOwner)
    {
        MONSTER_RunUModMissileCallbacks(pMissileParams->pOwner, pMissile);
    }

    return pMissile;
}

// 0x004CDB40
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB)
{
    if (!pUnit)
    {
        return 0;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 1;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = nX;
    tRequest.nArg2 = nY;
    tRequest.nArg3 = nA;
    tRequest.nArg4 = nB;
    tRequest.nArg0 = nRequest;
    return sub_004CD540_HandleRequest(&tRequest);
}


// 0x004CE140
void __fastcall MISSILE_SpawnRingAround(D2UnitStrc* pMissile, int nChance, int nCount, int nRange, int nMissile)
{
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    if (sub_0064A380_GetRemainingFrames(pMissile) && ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nChance) > 0)
    {
        return;
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x20;
    tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tParams.pOrigin = pMissile;
    tParams.nSkill = sub_0064A280(pMissile);
    tParams.nSkillLevel = sub_0064A210(pMissile);
    tParams.nMissile = nMissile;

    int nOffsetX = 0;
    int nOffsetY = 0;
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);

    for (int i = 0; i < nCount; ++i)
    {
        nOffsetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
        nOffsetY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
        nOffsetX += nOffsetX < 0 ? -nRange : nRange;
        nOffsetY += nOffsetY < 0 ? -nRange : nRange;
        tParams.nTargetX = nOffsetX + nX;
        tParams.nTargetY = nOffsetY + nY;
        MISSILE_CreateClientMissile(&tParams);
    }
}

// 0x004CE320
D2UnitStrc* __fastcall MISSILE_SpawnAtRandomUnitInRange(D2UnitStrc* pMissile, int nRange, int nFrequency, int nMissileId)
{
    if (nFrequency <= 0)
    {
        return 0;
    }

    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrequency)
    {
        return 0;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
    {
        return 0;
    }

    SEED_InitLowSeed(&pMissile->pSeed, CLIENTS_GetUnitX(pMissile) + sub_0064A3B0_GetElapsedFrames(pMissile));

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2003;
    tMissileParams.pOwner = pOwner;
    tMissileParams.nSkill = sub_0064A280(pMissile);
    tMissileParams.nSkillLevel = sub_0064A210(pMissile);
    tMissileParams.nMissile = nMissileId;

    --nRange;
    const int nOffsetX = nRange - ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange);
    const int nOffsetY = nRange - ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange);
    const int nX = CLIENTS_GetUnitX(pMissile) + nOffsetX;
    tMissileParams.nX = nX;
    const int nY = CLIENTS_GetUnitY(pMissile) + nOffsetY;
    tMissileParams.nY = nY;

    if (COLLISION_CheckMask(pRoom, nX, nY, 4))
    {
        return 0;
    }

    return MISSILE_CreateClientMissile(&tMissileParams);
}

static inline int UNITS_GetXPosition(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPosition(D2UnitStrc* pUnit)
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

static inline int RollOffset(D2UnitStrc* pUnit, int nRange)
{
    return ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRange / 2;
}

// 0x004CE850
void __fastcall MISSILE_SpawnPeriodicMissile(D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nMissileId, int nFrame, int nLevel)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTable->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTable->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        MISSILE_SpawnScatterMissiles(pOwner, pUnit, pMissilesTxtRecord->wCltSubMissile[0], nLevel);
    }

    if (pMissilesTxtRecord->wProgSound > 0 && nFrame == 315)
    {
        sub_004B9A00_PlayOverlay(pMissilesTxtRecord->wProgSound, pOwner, 0, 0, 0);
    }

    if (nFrame % 2 != 0)
    {
        return;
    }

    if (nLevel < 3 && nFrame % 16 != 0)
    {
        return;
    }

    int nRange = 4;
    if (nLevel < 3)
    {
        nRange = 1;
    }
    else if (nLevel < 6)
    {
        nRange = 2;
    }
    else if (nLevel < 9)
    {
        nRange = 3;
    }

    int nOffsetX = 0;
    int nOffsetY = 0;
    if (nRange > 1)
    {
        nOffsetX = RollOffset(pUnit, nRange);
        nOffsetY = RollOffset(pUnit, nRange);
    }

    D2MissileStrc missile;
    memset(&missile, 0, sizeof(missile));
    missile.dwFlags = 1;
    missile.pOwner = pOwner;
    missile.nSkill = sub_0064A280(pUnit);
    missile.nSkillLevel = sub_0064A210(pUnit);
    missile.nMissile = nMissileId;
    missile.nX = UNITS_GetXPosition(pUnit) + nOffsetX;
    missile.nY = UNITS_GetYPosition(pUnit) + nOffsetY;
    MISSILE_CreateClientMissile(&missile);
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x004CED60
void __fastcall MISSILE_CreateBurstAt(D2UnitStrc* pUnit, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissile);

    D2UnitStrc* pOwner = pUnit;
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        pOwner = CUNIT_GetOwnerUnit(pUnit);
        if (!pOwner)
        {
            return;
        }
    }

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x01;
    tParams.dwFlags |= 0x200;
    if (pMissilesTxtRecord->nRandFrames)
    {
        tParams.dwFlags |= 0x200;
    }
    tParams.pOwner = pOwner;
    tParams.nSkill = nSkill;
    tParams.nMissile = nMissile;
    tParams.nSkillLevel = nLevel;

    const int nRadiusSq = nCount * nCount;
    const int nStart = -nCount;
    for (int nOffsetY = nStart; nOffsetY <= nCount; nOffsetY += nMult)
    {
        const int nOffsetYSq = nOffsetY * nOffsetY;
        for (int nOffsetX = -nCount; nOffsetX <= nCount; nOffsetX += nMult)
        {
            if (nOffsetX * nOffsetX + nOffsetYSq <= nRadiusSq && SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, nPerStep) <= 0)
            {
                tParams.nX = nOffsetX + nX;
                tParams.nY = nOffsetY + nY;
                if (pMissilesTxtRecord->nRandFrames)
                {
                    tParams.nFrame = SEED_RollLimitedRandomNumberInline(&pUnit->pSeed, pMissilesTxtRecord->nRandFrames);
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
                if (COLLISION_GetRoomBySubTileCoordinates(pRoom, tParams.nX, tParams.nY))
                {
                    MISSILE_CreateClientMissile(&tParams);
                }
            }
        }
    }
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

// 0x004CFD70
int __fastcall MISSILE_CreateCallbackMissile(void* pArgument, D2UnitStrc* pUnit)
{
    D2MissileScanStateStrc* pState = (D2MissileScanStateStrc*)pArgument;
    D2MissileScanArgStrc* pScanArg = pState->pScanArg;
    if (pState->nHits >= pScanArg->nMaxHits)
    {
        return 0;
    }

    D2MissileStrc tMissileParams = {};
    tMissileParams.pOwner = pScanArg->pOwner;
    tMissileParams.pOrigin = pScanArg->pMissile;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.nSkill = pScanArg->nSkillId;
    tMissileParams.nSkillLevel = pScanArg->nSkillLevel;
    tMissileParams.nMissile = pScanArg->nSubMissile;
    tMissileParams.nTargetX = UNITS_GetXPositionForceInl(pUnit);
    tMissileParams.nTargetY = UNITS_GetYPositionForceInl(pUnit);
    MISSILE_CreateClientMissile(&tMissileParams);
    return 1;
}

// 0x004D4F20
void __fastcall MISSILE_CltDoSubMissileTimers(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    const int nSpread = pMissilesTxtRecord->dwCltParam[2];
    if (pMissilesTxtRecord->wCltSubMissile[0] > 0)
    {
        int nTimer = MISSILE_GetTargetX(pMissile);
        if (nTimer <= 0)
        {
            MISSILE_SpawnSubMissile(pOwner, pMissilesTxtRecord->wCltSubMissile[0], nSpread, pMissile);
            nTimer = pMissilesTxtRecord->dwCltParam[0];
        }

        MISSILE_SetTargetX(pMissile, nTimer - 1);
    }

    if (pMissilesTxtRecord->wCltSubMissile[1] > 0)
    {
        int nTimer = MISSILE_GetTargetY(pMissile);
        if (nTimer <= 0)
        {
            D2MissileStrc tMissile;
            memset(&tMissile, 0, sizeof(tMissile));
            tMissile.dwFlags = 0x102;
            tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            tMissile.pOwner = pOwner;
            tMissile.pOrigin = pMissile;
            tMissile.nSkill = MISSILE_GetSkill(pMissile);
            tMissile.nSkillLevel = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 5) + 1;
            tMissile.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
            tMissile.nTargetY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nSpread + 1) - nSpread;
            if (!tMissile.nTargetX && !tMissile.nTargetY)
            {
                tMissile.nTargetX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, nSpread - 1) + 1;
            }

            D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissile);
            if (pNew)
            {
                MISSILE_SetTargetX(pNew, SEED_RollLimitedRandomNumber(&pMissile->pSeed, 5));
            }

            nTimer = pMissilesTxtRecord->dwCltParam[1];
        }

        MISSILE_SetTargetY(pMissile, nTimer - 1);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D3070
void __fastcall MISSILE_CltDoOwnerStep(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }
    if ((unsigned int)pOwner->dwUnitType <= UNIT_MONSTER && CUNIT_IsDeadOrDying(pOwner))
    {
        MISSILE_CltMissileHit(pMissile, 0, 0);
        return;
    }
    D2Common_10235_PATH_UpdateRiderPath(pMissile, pOwner);
    UNITS_UpdateFrame(pMissile);
}

// 0x004CFE30
int __fastcall MISSILE_ScanAreaCreateMissiles(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltHitSubMissile[0] < 0)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwCltHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwCltHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    int nFlags = pSkillsTxtRecord->dwAuraFilter;
    if (!nFlags)
    {
        nFlags = 0xA783;
    }

    D2MissileScanArgStrc tArg;
    tArg.pOwner = pOwner;
    tArg.pMissile = pMissile;
    tArg.nSkillId = nSkillId;
    tArg.nSkillLevel = nSkillLevel;
    tArg.nMaxHits = nParam;
    tArg.nSubMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
    SKILLS_ScanArea(pOwner, nX, nY, nRange, nFlags, MISSILE_CreateCallbackMissile, &tArg, 1);

    return 1;
}

static inline D2MissilesTxt* GetMissileRecord(int id) {
 if(id>=0 && id<sgptDataTables->nMissilesTxtRecordCount)
  return &sgptDataTables->pMissilesTxt[id];
 return 0;
}

static inline D2SkillsTxt* GetSkillRecord(int id) {
 if(id>=0 && id<sgptDataTables->nSkillsTxtRecordCount)
  return &sgptDataTables->pSkillsTxt[id];
 return 0;
}

// 0x004CFFA0
int __fastcall MISSILE_HitScanCallback(void* pArgument, D2UnitStrc* pUnit)
{
    D2MissileScanStateStrc* pState = (D2MissileScanStateStrc*)pArgument;
    D2MissileScanArgStrc* pScanArg = pState->pScanArg;
    if (pState->nHits >= pScanArg->nMaxHits)
    {
        return 0;
    }

    D2MissileStrc tMissileParams = {};
    tMissileParams.pOwner = pScanArg->pOwner;
    tMissileParams.pOrigin = pScanArg->pMissile;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.nSkill = pScanArg->nSkillId;
    tMissileParams.nSkillLevel = pScanArg->nSkillLevel;
    tMissileParams.nMissile = pScanArg->nSubMissile;
    tMissileParams.nTargetX = UNITS_GetXPositionForceInl(pUnit);
    tMissileParams.nTargetY = UNITS_GetYPositionForceInl(pUnit);
    MISSILE_CreateClientMissile(&tMissileParams);
    return 1;
}

// 0x004D01D0
int __fastcall MISSILE_CreateMissileFan(D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissile, int nSkill, int nSkillLevel, int nStep)
{
    D2MissilesTxt* pMissilesTxt = DATATBLS_GetMissilesTxtRecord(nMissile);
    if (!pMissilesTxt)
    {
        return 0;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x1F;
    tMissile.pOwner = pOwner;
    tMissile.pOrigin = pOrigin;
    tMissile.nMissile = nMissile;
    tMissile.nX = UNITS_GetUnitXPosition(pOrigin);
    tMissile.nY = UNITS_GetUnitYPosition(pOrigin);
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nSkill = nSkill;
    tMissile.nLoops = nSkillLevel - 1;
    tMissile.nVelocity = pMissilesTxt->dwParam[0] << 7;

    for (int i = 0; i < 8; i += nStep)
    {
        tMissile.nTargetX = gaMissileFanTargetX[i];
        tMissile.nTargetY = gaMissileFanTargetY[i];
        MISSILE_CreateClientMissile(&tMissile);
    }

    return 1;
}

// 0x004D0380
int __fastcall MISSILE_CreateChildMissile(D2UnitStrc* unit)
{
 D2MissilesTxt* missile=GetMissileRecord(unit ? unit->dwClassId : -1);
 if(!missile || missile->wCltHitSubMissile[0]<0)return 1;
 D2UnitStrc* owner=CUNIT_GetOwnerUnit(unit);
 if(!owner)return 1;
 int skillId=MISSILE_GetSkill(unit);
 int level=MISSILE_GetLevel(unit);
 D2SkillsTxt* skill=GetSkillRecord(skillId);
 if(!skill)return 1;
 int range=missile->dwCltHitPar[0];
 if(!range) {
  range=SKILLS_EvaluateSkillFormula(owner,skill->dwCalc[0],skillId,level);
  if(range<5)range=5;
 }
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.pOwner=owner;
 params.dwFlags=1;
 params.nMissile=missile->wCltHitSubMissile[0];
 params.nSkill=level;
 params.nSkillLevel=level;
 params.nX=CLIENTS_GetUnitX(unit);
 params.nY=CLIENTS_GetUnitY(unit);
 if(range>0) {params.dwFlags=0x8001;params.nRange=range;}
 D2UnitStrc* child=MISSILE_CreateClientMissile(&params);
 if(child) PATH_SetDirection(child->pDynamicPath,PATH_GetDirection(unit->pDynamicPath));
 return 1;
}

// 0x004D1820
int __fastcall MISSILE_SpawnOwnerSubMissile(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        D2MissileStrc params;
        memset(&params, 0, sizeof(params));
        params.pOwner = pOwner;
        params.pOrigin = pMissile;
        params.nMissile = SUBMISSILE_ID;
        params.nSkill = MISSILE_GetSkill(pMissile);
        params.nSkillLevel = MISSILE_GetLevel(pMissile);
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&params);
        if (pNew)
            MISSILE_SetTargetX(pNew, MISSILE_GetTargetX(pMissile));
    }
    return 1;
}

// 0x004CC910
static int MISSILE_GetSpawnDelay(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < 125)
        return 25;
    if (nFrames < 175)
        return 10;
    return nFrames < 300 ? 3 : 15;
}

// 0x004D48B0
void __fastcall MISSILE_CltDoDelayedSpawn(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner)
    {
        int nTimer = MISSILE_GetTargetX(pMissile);
        if (!nTimer)
        {
            D2MissileStrc missileParams;
            memset(&missileParams, 0, sizeof(missileParams));
            missileParams.dwFlags = 2;
            missileParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
            missileParams.nSkill = MISSILE_GetSkill(pMissile);
            missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            missileParams.pOwner = pOwner;
            missileParams.pOrigin = pOwner;
            int nX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - pMissilesTxtRecord->dwCltParam[0];
            missileParams.nTargetX = nX;
            const int* pRange = &pMissilesTxtRecord->dwCltParam[0];
            int nY = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - *pRange;
            missileParams.nTargetY = nY;
            if (!nX && !nY)
            {
                nX = SEED_RollLimitedRandomNumber(&pMissile->pSeed, *pRange) + 1;
                missileParams.nTargetX = nX;
            }
            D2UnitStrc* pNewMissile = MISSILE_CreateClientMissile(&missileParams);
            if (pNewMissile)
            {
                MISSILE_SetTargetX(pNewMissile, nX);
                MISSILE_SetTargetY(pNewMissile, nY);
            }
            nTimer = MISSILE_GetSpawnDelay(pMissile);
        }
        MISSILE_SetTargetX(pMissile, nTimer - 1);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D4DC0
void __fastcall MISSILE_CltDoPickSubMissile(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && pMissilesTxtRecord->wCltSubMissile[0] >= 0)
    {
        const int nFrequency = pMissilesTxtRecord->dwCltParam[2] < 1 ? 1 : pMissilesTxtRecord->dwCltParam[2];
        if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrequency)
        {
            MISSILE_CltDoCommon(pMissile);
            return;
        }

        const int nOffsetX = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - pMissilesTxtRecord->dwCltParam[0];
        const int nOffsetY = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[0] + 1) - pMissilesTxtRecord->dwCltParam[0];
        const int nX = CLIENTS_GetUnitX(pMissile) + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[1] + 1) - pMissilesTxtRecord->dwCltParam[1];
        const int nY = CLIENTS_GetUnitY(pMissile) + ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, 2 * pMissilesTxtRecord->dwCltParam[1] + 1) - pMissilesTxtRecord->dwCltParam[1];

        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nX = nX;
        tParams.nY = nY;
        tParams.nTargetX = nX + nOffsetX;
        tParams.nTargetY = nY + nOffsetY;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        MISSILE_CreateClientMissile(&tParams);

        MISSILE_CltDoCommon(pMissile);
    }
    else
    {
        MISSILE_CltDoDefault(pMissile);
    }
}

static inline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004D63E0
void __fastcall MISSILE_CltDoZigZag(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nUpdateInterval = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0(pMissile) % nUpdateInterval)
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    if (!pSeed)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    SEED_InitLowSeed(pSeed, MISSILE_GetMissileTargetStatus(pMissile));

    const unsigned int nPackedOffset = MISSILE_targetValue(pMissile);
    const int nPreviousOffsetX = (short)nPackedOffset;
    const int nPreviousOffsetY = (short)(nPackedOffset >> 16);

    int nSignedOffsetX;
    int nSignedOffsetY;
    if (SEED_RollRandomNumber(pSeed) & 1)
    {
        nSignedOffsetX = nPreviousOffsetX;
        nSignedOffsetY = -nPreviousOffsetY;
    }
    else
    {
        nSignedOffsetX = -nPreviousOffsetX;
        nSignedOffsetY = nPreviousOffsetY;
    }

    int nNextOffsetX = (nSignedOffsetY + 4 * nPreviousOffsetX) / 4;
    int nNextOffsetY = (nSignedOffsetX + 4 * nPreviousOffsetY) / 4;
    if (!nNextOffsetX)
    {
        nNextOffsetX = 1;
    }

    if (!nNextOffsetY)
    {
        nNextOffsetY = 1;
    }

    PATH_SetTargetPos(pMissile->pDynamicPath, nNextOffsetX + CLIENTS_GetUnitX(pMissile), nNextOffsetY + CLIENTS_GetUnitY(pMissile));
    D2Common_10142(pMissile->pDynamicPath, pMissile, 0);

    MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
    const unsigned short nPackedOffsetX = (unsigned short)nNextOffsetX;
    const unsigned short nPackedOffsetY = (unsigned short)nNextOffsetY;
    MISSILE_SetTargetY(pMissile, nPackedOffsetX + (nPackedOffsetY << 16));

    MISSILE_CltDoCommon(pMissile);
}

static inline unsigned int SEED_RollUnitSeedWideInline(D2UnitStrc* pUnit)
{
    unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.lSeed = lSeed;

    return (unsigned int)lSeed;
}

// 0x004D6820
void __fastcall MISSILE_CltDoSpreadSpawn(D2UnitStrc* pMissile)
{
    D2MissileStrc missileParams;
    D2UnitStrc* pNew;
    int nY;
    int nX;

    const int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);

    if (nRemaining == 0x96)
    {
        sub_00476A80_StartTiming(0x19, 0, 0xFA0, 0);
    }

    for (int i = 0; i < 7; ++i)
    {
        const D2CltSpreadStrc* pSpread = &gaCltSpread[i];
        const int nFrame = 0x145 - 0x19 * i;
        if (nRemaining > nFrame)
        {
            break;
        }

        if (nRemaining == nFrame)
        {
            nY = UNITS_GetUnitYPosition(pMissile);
            nX = UNITS_GetUnitXPosition(pMissile);
            int nSkillLevel = sub_0064A210_GetSkillLevel(pMissile);
            int nSkill = sub_0064A280_GetSkill(pMissile);
            if (pOwner)
            {
                memset(&missileParams, 0, sizeof(missileParams));
                missileParams.dwFlags = 1;
                missileParams.pOwner = pOwner;
                missileParams.nX = pSpread->nOffsetX + nX;
                missileParams.nY = pSpread->nOffsetY + nY;
                missileParams.nSkill = nSkill;
                missileParams.nSkillLevel = nSkillLevel;
                missileParams.nMissile = MISSILE_HORADRICLIGHT;
                pNew = MISSILE_CreateClientMissile(&missileParams);
                if (pNew)
                {
                    PATH_SetDirection(pNew->pDynamicPath, pSpread->nDirection);
                    MISSILE_SetTotalFrames(pNew, nRemaining);
                    MISSILE_SetCurrentFrame(pNew, nRemaining);
                }
            }
        }
    }

    if (nRemaining < 0xA5 && !(nRemaining % 2))
    {
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pOwner;
        missileParams.nX = UNITS_GetUnitXPosition(pMissile);
        missileParams.nY = UNITS_GetUnitYPosition(pMissile);
        missileParams.nTargetX = UNITS_GetUnitXPosition(pMissile) - 13;
        missileParams.nTargetY = UNITS_GetUnitYPosition(pMissile) + 3;
        missileParams.nSkill = sub_0064A280_GetSkill(pMissile);
        missileParams.nSkillLevel = sub_0064A210_GetSkillLevel(pMissile);
        missileParams.nMissile = MISSILE_HORADRICLIGHTNING;
        pNew = MISSILE_CreateClientMissile(&missileParams);
        if (pNew)
        {
            GFXUTIL_SetMotionVectorA(pNew, 0, 0, 0x46);
            GFXUTIL_SetMotionVectorB(pNew, 0, 0, -1, 1);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            PATH_SetDirection(pPath, 0x15);
            D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
        }
    }

    if (nRemaining < 0x96)
    {
        const int nX2 = UNITS_GetUnitXPosition(pMissile) - 13;
        const int nY2 = UNITS_GetUnitYPosition(pMissile) + 3;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pOwner;
        missileParams.nX = nX2;
        missileParams.nY = nY2;
        missileParams.nTargetX = nX2 + (int)(SEED_RollUnitSeedInline(pMissile) % 5) + 1;
        missileParams.nTargetY = nY2 + (int)(SEED_RollUnitSeedWideInline(pMissile) % 10) - 5;
        missileParams.nSkill = sub_0064A280_GetSkill(pMissile);
        missileParams.nSkillLevel = sub_0064A210_GetSkillLevel(pMissile);
        missileParams.nMissile = MISSILE_DUST;
        pNew = MISSILE_CreateClientMissile(&missileParams);
        if (pNew)
        {
            UNITS_SetAnimationSpeed(pNew, 0x40);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

static inline int GetX(D2UnitStrc* pUnit)
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

static inline int GetY(D2UnitStrc* pUnit)
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

// 0x004D7880
void __fastcall MISSILE_CltDoRotateTarget(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nDiffY = 0;
    const int nX = GetX(pUnit);
    const int nY = GetY(pUnit);
    const int nDiffX = nX - sub_0064A730_GetTargetX(pUnit);
    nDiffY = nY - sub_0064A780_GetTargetY(pUnit);
    D2COMMON_10170_PathSetTargetPos(pPath, nX + nDiffY, nY - nDiffX);
    D2Common_10142(pPath, pUnit, 0);
    MISSILE_CltDoCommon(pUnit);
}

// 0x004CF9B0
int __fastcall MISSILE_CltHitRingSubMissiles(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkill = sub_0064A280(pMissile);
    const int nLevel = sub_0064A210(pMissile);
    if (!DATATBLS_GetSkillsTxtRecordLow(nSkill))
    {
        return 1;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    const int nX = UNITS_GetUnitXPosition(pMissile);
    const int nY = UNITS_GetUnitYPosition(pMissile);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pOwner;
    tMissile.dwFlags = 0x4001;
    tMissile.nSkill = nSkill;
    tMissile.nSkillLevel = nLevel;
    if (pMissilesTxtRecord->wCltHitSubMissile[0] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[0];
        const int nCount = pMissilesTxtRecord->dwCltHitPar[0];
        for (int i = 0; i < nCount; ++i)
        {
            tMissile.nX = nX + gaRing5OffsetX[i % 5];
            tMissile.nY = nY + gaRing5OffsetY[i % 5];
            MISSILE_CreateClientMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[1] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[1];
        tMissile.dwFlags = 0x8001;
        tMissile.nRange = SKILLS_GetLevelBasedParam(nSkill, nLevel);
        tMissile.nX = nX;
        tMissile.nY = nY;
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissile);
        if (pNew && pNew->pLight)
        {
            DLIGHTMAP_ResetLightSize(pNew->pLight, 0xC);
        }
    }

    tMissile.dwFlags = 0xC001;
    int nIndex = 0;
    if (pMissilesTxtRecord->wCltHitSubMissile[2] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[2];
        nIndex = pMissilesTxtRecord->dwCltHitPar[1];
        for (int i = 0; i < nIndex; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX[i % 18];
            tMissile.nY = nY + gaRing18OffsetY[i % 18];
            MISSILE_CreateClientMissile(&tMissile);
        }
    }

    if (pMissilesTxtRecord->wCltHitSubMissile[3] >= 0)
    {
        tMissile.nMissile = pMissilesTxtRecord->wCltHitSubMissile[3];
        const int nEnd = nIndex + pMissilesTxtRecord->dwCltHitPar[2];
        for (int i = nIndex; i < nEnd; ++i)
        {
            tMissile.nX = nX + gaRing18OffsetX[i % 18];
            tMissile.nY = nY + gaRing18OffsetY[i % 18];
            MISSILE_CreateClientMissile(&tMissile);
        }
    }

    return 1;
}

// 0x004D8260
void __fastcall MISSILE_CltDoMissileSpray(D2UnitStrc* pMissile)
{
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames - nFrames / 3 * 3 == 0)
    {
        D2SeedStrc* pSeed = &pMissile->pSeed;
        D2SeedStrc tSeed;
        const int nOffsetX = SEED_RollFromInline(pSeed, &tSeed) % 20 - 10;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pSeed->nHighSeed = tSeed.nHighSeed;
        pSeed->nLowSeed = tSeed.nLowSeed;
        const int nOffsetY = nRoll % 20 - 10;
        const int nX = UNITS_GetUnitXPosition(pMissile) + (SEED_RollRandomNumber(&pMissile->pSeed) & 1) - 1;
        const int nY = UNITS_GetUnitYPosition(pMissile) + (SEED_RollRandomNumber(&pMissile->pSeed) & 1) - 1;

        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
        tParams.nX = nX;
        tParams.nY = nY;
        tParams.nTargetX = nX + nOffsetX;
        tParams.nTargetY = nY + nOffsetY;
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = MISSILE_ANCIENT_DEATH_CLOUD;
        MISSILE_CreateClientMissile(&tParams);
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D8400
void __fastcall MISSILE_CltDoRotateTargetPoint(D2UnitStrc* pMissile)
{
    if (!(sub_0064A3B0(pMissile) % 2))
    {
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        int nX = UNITS_GetUnitXPosition(pMissile);
        int nY = UNITS_GetUnitYPosition(pMissile);
        int nDX = nX - MISSILE_GetMissileTargetStatus(pMissile);
        int nDY = nY - MISSILE_targetValue(pMissile);
        PATH_SetTargetPos(pPath, nX + nDY, nY - nDX);
        D2Common_10142(pPath, pMissile, 0);
    }
    MISSILE_CltDoCommon(pMissile);
}

// 0x004CC7C0
int __fastcall MISSILE_GetSkillMissileRange(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxt = DATATBLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    if (nLevel <= 0)
        return 0;
    return pSkillsTxt->dwParam[2] + (nLevel - 1) * pSkillsTxt->dwParam[3];
}

// 0x004CCF20
void __fastcall MISSILE_SetMissileLights(int nValue)
{
// build: symbol ?gbMissileLights@* 0x0072A348
    gbMissileLights = nValue;
}

// 0x004CCF30
int __cdecl MISSILE_GetMissileLights()
{
// build: symbol ?gbMissileLights@* 0x0072A348
    return gbMissileLights;
}

int __stdcall sub_M119_Emit_004CC800(D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY, int nMaxDistanceSq, int nX, int nY)
{
    return MISSILE_CheckDistanceAndLineOfSight(nMaxDistanceSq, nX, nY, pRoom, nOffsetX, nOffsetY);
}

// 0x004CC790
int __fastcall MISSILE_RollRange(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMin >= nMax)
        return nMin;

    return ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1) + nMin;
}

// 0x004CC9A0
int __fastcall MISSILE_CltHitProgOverlay(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit && pMissile)
    {
        D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (pMissilesTxtRecord)
        {
            const short nOverlay = pMissilesTxtRecord->wProgOverlay;
            if (nOverlay > 0)
                GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
        }
    }
    return 1;
}

// 0x004CCCA0
int __fastcall MISSILE_CltHitFlagOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner)
        pOwner->dwFlagEx |= UNITFLAGEX_0x40000;
    return 1;
}

// 0x004CCCC0
void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused)
{
    if (!pMissile)
        return;

    const int nRange = MISSILE_GetTotalFrames(pMissile) > 255 ? 255 : MISSILE_GetTotalFrames(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, D2COMMON_10175_PathGetFirstPointX(pPath));
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nRange);
    D2Common_10142(pPath, pMissile, 0);
}

// 0x004CCF00
int __fastcall MISSILE_CltHitClearGlobals(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        VIEW_ClearGlobals();
        return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/UNIT/Missile.inc"
