#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2StateIds.h"
#include "D2Records.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2SkillIds.h"
#include "D2SoundEnvironTxt.h"
#include "D2MonTypeTxt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SoundEnvironTxtStrc;

struct Unicode;

struct D2ItemStatCostTxt;

struct D2CharStatsTxt;

struct D2MonStatsTxt;

struct D2MonTypeTxt;

struct D2SkillsTxt;

struct D2CombinedStatStrc;

struct D2CombinedStatsStrc;

struct D2CombinedStatIdStrc;

struct D2FileIndexTextStrc;

extern D2DrlgActStrc* gpAct; // 0x007A0634

int __cdecl sub_004DF870(); // 0x004DF870

int __cdecl UNITMODE_GetPlayerLevelId(); // 0x00481780

D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920

void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

void __fastcall SOUNDINST_RefreshHintsInRangeA(int nGroupA, int nGroupB); // 0x004BA950

void __fastcall SOUNDINST_RefreshHintsInRangeB(int nGroupA, int nGroupB); // 0x004BA9D0

void __fastcall SOUNDINST_SetValue(int nKey, int nValue); // 0x004B9B50

int __fastcall sub_004B9B20(int nHandle); // 0x004B9B20

void __fastcall sub_004BA840(int nHandle); // 0x004BA840

int __fastcall sub_004E40A0(int nRange); // 0x004E40A0

extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100

static void SKILLDESC_AddEnvironSoundRefs(int nIndex); // 0x004E4240


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0

D2MonTypeTxt* __fastcall SKILLDESC_GetMonTypeTxtRecord(int nMonType); // 0x004E4640

void __fastcall TEXT_AppendUndeadDamageBonus(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused); // 0x004E48B0

unsigned short __fastcall SKILLDESC_GetSkillDescStringId(int nId, int nIndex); // 0x004E6CE0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

extern D2CombinedStatIdStrc gaCombinedStatIds[]; // 0x0072CDD0

extern D2FileIndexTextStrc gaFileIndexText[]; // 0x0072D6C0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static int __stdcall SKILLDESC_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId); // 0x004E4C50

int __stdcall SKILLDESC_IsStatGroupUniform(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nValue, D2ItemStatCostTxt* pRecord, int* pIsSame); // 0x004E4CE0


D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

int __fastcall SKILLDESC_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004E8FE0

int gnEnvironLevelId; // 0x007C8C7C

int gnEnvironSoundHandle; // 0x007C8C80

int gnWeatherSoundHandle; // 0x007C8C84

int gnEnvironSoundId; // 0x007C8C88

int gnWeatherSoundId; // 0x007C8C8C

int gnEnvironAmbientId; // 0x007C8C90

unsigned int gnAmbientDelay; // 0x007C8C94

unsigned int gnAmbientTick; // 0x007C8C98

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" const char gszFmtRange[];                                                                // 0x006D9D70

// build: symbol ?gnScreenHeight@* 0x00711470
// build: symbol ?gnPanelOffsetX@* 0x007A2858
extern int gnPanelOffsetX; // 0x007A2858

// build: symbol ?gnPanelOffsetY@* 0x007A285C
extern int gnPanelOffsetY; // 0x007A285C

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __cdecl SKILLDESC_SumProgressiveBonus(); // 0x004E6FF0

int __stdcall STATES_CheckStateMaskDamBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A380

int __stdcall STATES_CheckStateMaskDamRedOnUnit(D2UnitStrc* pUnit); // 0x0063A3A0

int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0

int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId); // 0x00626070

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery);            // 0x00644D50

int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery);            // 0x00644E40

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem);

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                        // 0x004A89D0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem);                                          // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem);                                         // 0x006298A0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

int __fastcall SKILLDESC_WeaponDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004E9610

int __fastcall SKILLDESC_ThrowDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004EA4A0

void __fastcall SKILLDESC_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA010

struct D2SkillDescTxt;

struct D2UnitStrc;

struct D2DataTablesStrc;

extern "C" const char gszFmtRangeKK[]; // 0x006DBEAC

extern "C" const char gszFmtRangeK[]; // 0x006DBEB8

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

int __stdcall SKILLDESC_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor); // 0x004E7120

unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0

int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100

int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

static void __fastcall SKILLDESC_DrawDamageRange(int nMin, int nMax, int nColor, int nY, int nLeft, int nRight); // 0x004E96E0

int __fastcall GAME_GetUnitClassId(D2UnitStrc*); // 0x00451F60

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*, int, int); // 0x006439B0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

int __stdcall SKILLDESC_AddElemRange(Unicode* wszText, int nMin, unsigned short nString, int nMax, int nElemType); // 0x004EC140

static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel); // 0x004EC220

static void __stdcall SKILLDESC_DrawWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, SKILLWEAPONFN pfnEvaluate, int nBonus, int nAdd, int nLeft, int nY, int nRight, int bElemDamage);

void __fastcall SKILLDESC_DrawDualWieldLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA170

void __fastcall SKILLDESC_DrawDualWieldLineNoElem(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA240

void __fastcall SKILLDESC_DrawWeaponDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawWeaponStatDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawOtherHandDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

int gbHasClassSkill; // 0x007C8CA0

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
#include "D2Client.h"
#include "D2MonsterIds.h"

extern "C" __declspec(dllimport)
int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

void __stdcall SKILLDESC_GetElemDamage(D2UnitStrc*, int*, int*, int*, D2SkillsTxt*, int); // 0x004E72D0

static int __stdcall sub_004E86F0_GetWeaponDamage(int*, int*, int*, int, D2SkillStrc*, int, D2UnitStrc*, int, D2UnitStrc*, int); // 0x004E86F0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

extern const D2ElemDamageStatsStrc gaElemDamageStats[4];                                          // 0x006DBEF4

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillTextPositionStrc { int nLeft, nY, nRight; };

typedef void (__fastcall* SKILLDAMAGEFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int, int, int);

typedef void (__fastcall* SKILLDESCFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int*, int*, int*, int*);

extern SKILLDAMAGEFN gpfnSkillDamageFuncs[]; // 0x0072D768

extern SKILLDESCFN gpfnSkillDescFuncs[]; // 0x0072D7F8

extern D2SkillTextPositionStrc gaSkillTextPositions[]; // 0x0072D840

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
extern "C" const char gszFormatD[]; // 0x006D57BC

extern const char gszSkillDescFile_006DBF24[]; // 0x006DBF24

void __fastcall GAME_StrToUpper(Unicode*); // 0x00452180

int __fastcall TEXT_SplitAtNewline(Unicode*, Unicode**); // 0x004A7660

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc*, D2SkillStrc*); // 0x004D9FC0

static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue); // 0x004E9940

#define TP gaSkillTextPositions

#define DRAW_SKILL_TEXT(i, text) TEXT_DrawCenteredText(TP[i].nLeft + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY + TP[i].nY - 480, TP[i].nRight + gnPanelOffsetX, text, 0)

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2MissileStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900

void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern const unsigned char gbSkillFlagMask_006CE270; // 0x006CE270

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

extern int gnChargedBoltTurnEvery; // 0x0072D98C

extern int gnChargedBoltTurnBase; // 0x0072D990

extern const int gaCurvingPathOffsetY[]; // 0x006DC1E8

extern const int gaCurvingPathOffsetX[]; // 0x006DC208

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pPath, int nPoints); // 0x00648790

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nFrame); // 0x0064A330

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40

int __stdcall SKILLDESC_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel); // 0x004EC280

static int __stdcall SKILLDESC_EvaluateForEachWeapon(int* pValue1, int* pValue2, int* pColor1, int* pValue3, int* pValue4, int* pColor2, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nBonus, D2UnitStrc* pUnit, int nAdd);

void __fastcall SKILLDESC_DrawWeaponAndSkillDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

static int SKILLDESC_AppendSkillDescStrLong(Unicode* wszOut, int nSkillId);

extern "C" const char szFmtPlusDec_006DBE9C[]; // 0x006DBE9C

extern "C" const char szFmtDec_006DBE94[]; // 0x006DBE94

__declspec(noinline) static int __stdcall SKILLDESC_FormatSignedInt(Unicode* wszText, int bPrefixSign, int nValue);

__declspec(noinline) static int __stdcall SKILLDESC_FormatSignedDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction);

static int SKILLDESC_FormatIntOrDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction);

static unsigned short SKILLDESC_GetSkillDescStrLong(int nSkillId);

static void __stdcall SKILLDESC_ApplyFireMasteryBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2); // 0x004E6EA0

static void __stdcall SKILLDESC_ApplyLightningMasteryBonus(int* pValue1, int* pValue2, D2SkillsTxt* pSkillsTxt); // 0x004E6F00

static unsigned short SKILLDESC_GetETypeDamageStr(int nEType);

static int SKILLDESC_GetETypeColor(int nEType); // 0x004E6FB0

static int __stdcall SKILLDESC_AppendFrameRange(Unicode* wszOut, unsigned short wStr, int nMinFrames, int nMaxFrames); // 0x004E7650

static int __stdcall SKILLDESC_AppendScaledRange(Unicode* wszOut, unsigned short wStr1, unsigned short wStr2, int nMaxValue, int nMultiplier, int nMinValue); // 0x004E77A0

static int __stdcall SKILLDESC_AppendFormattedValue(int nValue, unsigned short wStr, Unicode* wszOut); // 0x004E7930

static int __stdcall SKILLDESC_AppendLabelValue(unsigned short wStr, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E79E0

static int __stdcall SKILLDESC_AppendScaledValue(unsigned short wStr1, unsigned short wStr2, int nMultiplier, Unicode* wszOut, int bPrefixSign, int nValue); // 0x004E7A90

static int __stdcall SKILLDESC_AppendLabelDecimal(unsigned short wStr, Unicode* wszOut, int bPrefixSign, int nValue, int nFraction);

static int __stdcall SKILLDESC_AppendValueLabel(unsigned short wStr, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E7C30

static int __stdcall SKILLDESC_AppendValueTwoLabels(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E7CE0

static int __stdcall SKILLDESC_AppendValueCountLabel(int nStr1, int nStr2, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E7DB0

static int __stdcall SKILLDESC_AppendLabelValueLabel(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E7E70

static int __stdcall SKILLDESC_AppendLabelRangeLabel(Unicode* wszOut, int bPrefixSign, unsigned short wStr2, unsigned short wStr1, int nMin, int nMax); // 0x004E7F40

static int __stdcall SKILLDESC_AppendLabelsRange(Unicode* wszOut, int bPrefixSign, unsigned short wStr1, unsigned short wStr2, int nMin, int nMax); // 0x004E8020

static int __stdcall SKILLDESC_AppendLabelRange(Unicode* wszOut, int bSeparator, int bPrefixSign, unsigned short wStr, int nMin, int nMax); // 0x004E80F0

static int __stdcall SKILLDESC_AppendLabelValueLabels(unsigned short wStr1, unsigned short wStr2, unsigned short wStr3, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E81C0

static int __stdcall SKILLDESC_AppendManaValue(int nValue, Unicode* wszOut);

static void SKILLDESC_AddElementalStatDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, unsigned char nType); // 0x004E8D90

static int __stdcall SKILLDESC_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill);

static D2UnitStrc* SKILLDESC_MergeOtherHandWeapon(D2UnitStrc* pUnit); // 0x004E9260

static int __stdcall SKILLDESC_AttackRatingForEachWeapon(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pValue3, int* pValue4, D2SkillStrc* pSkill, int nLevel);

void __fastcall SKILLDESC_DescAttackRating(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4);

void __fastcall SKILLDESC_DescAttackRatingOffhand(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4);

static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill, D2UnitStrc* pItem, int nRatio); // 0x004E9660

void __fastcall sub_004EA4A0(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, int nBonus, int nAdd, int nParam, int nSrcDam, int nItem); // 0x004EA4A0

extern const char gszFmtOne_006D57BC[]; // 0x006D57BC

int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0

int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId); // 0x006461D0

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

D2UnitStrc* sub_004E9300_MergeWeaponPair(D2UnitStrc* pUnit); // 0x004E9300

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __fastcall GAME_GetLadderFlag(); // 0x0044DCA0

static int __stdcall SKILLDESC_AddSummonDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, D2SkillsTxt* pSkillsTxt); // 0x004ECCF0

static int __stdcall SKILLDESC_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel);


short __stdcall sub_00629860_GetStrengthFactor(D2UnitStrc* pItem);

short __stdcall sub_006298A0_GetDexterityFactor(D2UnitStrc* pItem);



void __fastcall SKILLDESC_DrawPhysWeaponElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EAE70

void __stdcall SKILLDESC_AddSummonLife(Unicode* wszText, int nPercent, int nBonus, int nMonsterId); // 0x004EC090


int __stdcall SKILLDESC_AddPhysDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nBonus, int nPercent, int nSkillLevel); // 0x004EC2E0

int SKILLDESC_AddToHit(int nSkillLevel, int nSkillId, D2UnitStrc* pUnit, Unicode* wszText); // 0x004EC510

int __stdcall SKILLDESC_AddElemRatePerSecond(unsigned short nString, int nMin, int nMax, Unicode* wszText); // 0x004EC540


int __stdcall SKILLDESC_AddValueLine(unsigned short nStringAfter, int bPlus, int bPercent, int nValue, unsigned short nStringBefore, Unicode* wszText); // 0x004EC7E0

int __stdcall SKILLDESC_AddDecimalLine(unsigned short nStringAfter, int bPlus, int bPercent, int nWhole, int nFraction, unsigned short nStringBefore, Unicode* wszText); // 0x004EC900

int __stdcall SKILLDESC_AddValueOverTime(unsigned short nStringAfter, int nValue, int bPlus, int nCount, unsigned short nStringBefore, Unicode* wszText); // 0x004ECA00

int SKILLDESC_AddTextPair(unsigned short nString1, unsigned short nString2, Unicode* wszText); // 0x004ECB10

int __stdcall SKILLDESC_AddValueAfterText(unsigned short nStringAfter, int bPlus, int bPercent, int nValue, unsigned short nStringBefore, Unicode* wszText); // 0x004ECB80

int __stdcall SKILLDESC_AddFormattedText(int nValue, unsigned short nString, Unicode* wszText); // 0x004ECC80

int SKILLDESC_AddNextLevelParam(int nSkillLevel, int nSkillId, Unicode* wszText); // 0x004ED0D0

int __stdcall SKILLDESC_AddSeconds(unsigned short nString, int bPlus, int nFrames, Unicode* wszText); // 0x004EDB30

static void SKILLDESC_AddEnvironSoundRefs(int nIndex)
{
    int nId = nIndex * 4 + 0xA9C;
    for (int i = 3; i; --i)
    {
        sub_004822B0(nId, 1);
        sub_004822B0(nId + 0x18, 1);
        nId += 0x30;
    }
}

static inline float GetEnvironVolume_Inline()
{
    return sub_00473C40() ? sub_00473C80() : 0.0f;
}

#define MINIMUM(a,b) (((a) < (b)) ? (a) : (b))

#define MASK_DECREMENT 1

static inline int Absolute(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

static inline D2SkillDescTxt* SKILLTREE_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
    {
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    }
    return 0;
}

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

static inline D2SkillsTxt* sub_004F21B0_GetSkillsTxtRecord(int nSkillId)
{
	if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
	{
		return &sgptDataTables->pSkillsTxt[nSkillId];
	}
	return 0;
}


// 0x004E4200
float __cdecl SKILLDESC_GetFloatIfEnabled()
{
    if (!sub_00473C40())
    {
        return 0.0f;
    }

    return sub_00473C80();
}


D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

void __fastcall SKILLS_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent); // 0x004C76D0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

// 0x004EDA80
int __fastcall SKILLDESC_CallSkillDescFunc(D2UnitStrc* pUnit, int bLeft)
{
    if (!pUnit)
    {
        return 0;
    }

    D2SkillStrc* pSkill;
    if (bLeft)
    {
        pSkill = UNITS_GetLeftSkill(pUnit);
    }
    else
    {
        pSkill = UNITS_GetRightSkill(pUnit);
    }

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return 0;
    }

    int nValue1 = 0;
    int nValue2;
    int nValue3 = 0;
    int nValue4;
    if (pSkillDescTxt->wDescFunc < 72 && gpfnSkillDescFuncs[pSkillDescTxt->wDescFunc])
    {
        const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
        gpfnSkillDescFuncs[pSkillDescTxt->wDescFunc](pUnit, pSkill, pSkillsTxt, nLevel, &nValue1, &nValue2, &nValue3, &nValue4);
    }

    return nValue1;
}

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

// 0x004F2010
int __fastcall SKILLDESC_CanTargetHostile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget))
        && (unsigned int)pTarget->dwUnitType <= 1)
    {
        return CUNIT_IsHostileTo(pUnit, pTarget) != 0;
    }

    return 0;
}

// 0x004F2160
int __fastcall SKILLDESC_DecrementParam(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!CUNIT_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    const int nParam = SKILLS_GetParam1(pSkill) - 1;
    if (nParam > 0)
    {
        SKILLS_SetParam1(pSkill, nParam);
        SKILLS_ScaleFramePrecise(pUnit, 100);
    }

    return 1;
}

// 0x004F21B0
int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId)
{
	D2SkillsTxt* pSkillsTxtRecord = sub_004F21B0_GetSkillsTxtRecord(nSkillId);
	if (!pSkillsTxtRecord)
	{
		return -1;
	}

	if (pSkillsTxtRecord->nFlags[0] & gbSkillFlagMask_006CE270)
	{
		if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
			&& pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
		{
			D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
			if (pStatList)
			{
				int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
				nIndex = D2_MIN(D2_MAX(nIndex, 1), 3);
				return pSkillsTxtRecord->wCltMissile[nIndex];
			}
		}
	}

	return pSkillsTxtRecord->wCltMissile[1];
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0

// 0x004E2F40
int __fastcall SKILLDESC_VolleyAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pInitFunc = SKILLDESC_InitCappedChargedPath;
    if (!ITEM_GetTargetPosition(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nInitArg = i;
        MISSILE_CreateClientMissile(&tMissileParams);
    }
    return 1;
}

// 0x004E3AB0
void __fastcall SKILLDESC_CreateBlazeMissile(D2UnitStrc* pUnit)
{
    if (!pUnit->pDynamicPath || !PATH_HasEnteredNewSubtile(pUnit->pDynamicPath))
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_BLAZE);
    if (!pStatList)
    {
        return;
    }

    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    if (nSkillLevel < 0)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return;
    }

    const int nCltMissile = pSkillsTxt->wCltMissileA;
    if (nCltMissile < 0 || nCltMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = pSkillsTxt->wCltMissileA;

    if (pSkillsTxt->wCltMissileB >= 0)
    {
        if (pSkillsTxt->wCltMissileC >= 0)
        {
            switch (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3))
            {
            case 0:
                tMissile.nMissile = pSkillsTxt->wCltMissileB;
                break;

            case 1:
                tMissile.nMissile = pSkillsTxt->wCltMissileC;
                break;
            }
        }
        else if (!SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
        {
            tMissile.nMissile = pSkillsTxt->wCltMissileB;
        }
    }

    MISSILE_CreateClientMissile(&tMissile);
}

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __fastcall sub_00472C50(int nArg); // 0x00472C50

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200


// 0x004E3C50
int __fastcall SKILLDESC_MissileAtTargetUnit(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget && pUnit)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.pOwner = pUnit;
        tMissileParams.dwFlags = 1;
        tMissileParams.nX = CLIENTS_GetUnitX(pTarget);
        tMissileParams.nY = CLIENTS_GetUnitY(pTarget);
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nMissile = nMissile;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            GFXUTIL_SetMotionVectorA(pMissile, 0, 0, 0x118);
            GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -0x28, 1);
        }

        sub_00472C50(0);
        const short nOverlay = pSkillsTxtRecord->wPrgOverlay;
        if (nOverlay > 0)
        {
            GFX_AddUnitOverlay(pTarget, nOverlay, 2, 0, 0, 0, 0, 0);
        }

        return 1;
    }

    return 0;
}

// 0x004E4180
int __fastcall sub_004E4180(int nFrame, int nOffset, int nStepLength)
{
    int nFrameMod;
    int nOffsetMod;
    const int nMask = nStepLength - MASK_DECREMENT;
    if (!(nStepLength & nMask))
    {
        nFrameMod = nFrame & nMask;
        nOffsetMod = nOffset & nMask;
    }
    else
    {
        nFrameMod = nFrame % nStepLength;
        nOffsetMod = nOffset % nStepLength;
    }
    const int nDirect = Absolute(nOffsetMod - nFrameMod);
    const int nForward = Absolute(nOffsetMod - nFrameMod - nStepLength);
    const int nBackward = Absolute(nFrameMod - nOffsetMod - nStepLength);
    return MINIMUM(MINIMUM(nDirect, nForward), nBackward);
}

void __fastcall GFXUTIL_ApplySoundEnviron(int nEnvironId); // 0x004DF6C0

// 0x004E42E0
void __fastcall SKILLDESC_UpdateEnvironSounds(unsigned int dwTick)
{
    if (!sub_004DF870())
        return;
    const int nLevelId = UNITMODE_GetPlayerLevelId();
    if (!nLevelId)
        return;
    int nSound = 0;
    int nAmbient = 0;
    int nVolume = 0;
    int bNight;
    switch (ENVIRONMENT_GetCycleIndexFromAct(gpAct))
    {
    case 1:
    case 2:
    case 3:
        bNight = 0;
        break;
    default:
        bNight = 1;
        break;
    }
    const int nEnviron = sub_004817A0_GetPlayerSoundEnviron();
    D2SoundEnvironTxtStrc* pEnv = SOUNDHDR_GetSoundEnvironTxtRecord(nEnviron);
    if (pEnv)
    {
        if (bNight)
        {
            nAmbient = pEnv->nNightEvent;
            nSound = pEnv->nNightAmbience;
        }
        else
        {
            nAmbient = pEnv->nDayEvent;
            nSound = pEnv->nDayAmbience;
        }
    }
    int nSecond = sub_00473C40() ? 0x40 : 0;
    if (GetEnvironVolume_Inline() != 0.0f)
    {
        const float fVolume = !sub_00473C40() ? 0.0f : sub_00473C80();
        nVolume = (int)(fVolume * 255.0);
    }
    if (nSound != gnEnvironSoundId)
    {
        int bCross = 0;
        if (nSound == pEnv->nDayAmbience && gnEnvironSoundId == pEnv->nNightAmbience)
            bCross = 1;
        if (nSound == pEnv->nNightAmbience && gnEnvironSoundId == pEnv->nDayAmbience)
            bCross = 1;
        if (bCross)
        {
            SOUNDINST_ArmHint(gnEnvironSoundHandle, 0, 0, 0xFA);
        }
        else
        {
            SOUNDINST_RefreshHintsInRangeA(nSound, nSecond);
            SOUNDINST_RefreshHintsInRangeB(nAmbient, 0);
        }
        if (nSound != gnEnvironSoundId)
        {
            if (nSound)
            {
                gnEnvironSoundHandle = sub_004B9A00(nSound, 0, 0, 0, 0);
                if (bCross)
                {
                    SOUNDINST_SetValue(gnEnvironSoundHandle, 0);
                    SOUNDINST_ArmHint(gnEnvironSoundHandle, 0xFF, 0, 0xFA);
                }
                gnEnvironSoundId = nSound;
            }
            else
            {
                gnEnvironSoundHandle = 0;
                gnEnvironSoundId = 0;
            }
        }
    }
    if (nSecond)
    {
        if (nVolume && !gnWeatherSoundHandle)
        {
            gnWeatherSoundHandle = sub_004B9A00(gnWeatherSoundId, 0, 0, 0, 0);
            if (gnWeatherSoundHandle)
                SOUNDINST_SetValue(gnWeatherSoundHandle, nVolume);
        }
        if (gnWeatherSoundHandle)
        {
            const int nCurrent = sub_004B9B20(gnWeatherSoundHandle);
            int nNext;
            if (nVolume > nCurrent)
                nNext = nVolume < nCurrent + 6 ? nVolume : nCurrent + 6;
            else
                nNext = nVolume > nCurrent - 6 ? nVolume : nCurrent - 6;
            if (nNext)
            {
                SOUNDINST_SetValue(gnWeatherSoundHandle, nNext);
            }
            else
            {
                sub_004BA840(gnWeatherSoundHandle);
                gnWeatherSoundHandle = 0;
            }
        }
        gnWeatherSoundId = nSecond;
    }
    else
    {
        sub_004BA840(gnWeatherSoundHandle);
        gnWeatherSoundHandle = 0;
        gnWeatherSoundId = 0;
    }
    GFXUTIL_ApplySoundEnviron(nEnviron);
    if (nAmbient)
    {
        if (nAmbient != gnEnvironAmbientId)
        {
            gnAmbientDelay = sub_004E4120(pEnv->nEventDelay / 3) + pEnv->nEventDelay;
            gnAmbientTick = dwTick - sub_004E40A0(gnAmbientDelay);
            gnEnvironAmbientId = nAmbient;
        }
        if (dwTick - gnAmbientTick >= gnAmbientDelay)
        {
            const int nHandle = sub_004B9A00(gnEnvironAmbientId, 0, 0, 0, 0);
            if (nHandle)
            {
                const int nSign = sub_004E40A0(2) ? 1 : -1;
                const int nPan = SKILLDESC_RandomInRange(0x1C2, 0x2EE) * nSign;
                const int nPanVolume = sub_004E4120(0x64);
// build: symbol ?SOUNDINST_MoveSound@* 0x004B99A0
                SOUNDINST_MoveSound(nHandle, nPan, nPanVolume, 0);
                gnAmbientTick = dwTick;
                gnAmbientDelay = sub_004E4120(pEnv->nEventDelay / 3) + pEnv->nEventDelay;
            }
        }
    }
    if (nLevelId != gnEnvironLevelId)
    {
        const int nEntryA = pEnv->nMaterial1;
        const int nEntryB = pEnv->nMaterial2;
        for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
            sub_00482370(nId);
        if (nEntryA)
            SKILLDESC_AddEnvironSoundRefs(nEntryA);
        if (nEntryB)
            SKILLDESC_AddEnvironSoundRefs(nEntryB);
        gnEnvironLevelId = nLevelId;
    }
}

static void __stdcall sub_004E49C0_CollectCombinedStats(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2CombinedStatsStrc* pCombined)
{
    memset(pCombined, 0, sizeof(D2CombinedStatsStrc));

// build: symbol ?gnCombinedStatCount@* 0x0072CDCC
    for (int i = 0; i < gnCombinedStatCount; ++i)
    {
        const int nStatId = gaCombinedStatIds[i].nStatId;
        if (nStatId == -1)
            continue;

        switch (nStatId)
        {
        case 48:
            pCombined->tFire.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 49:
            pCombined->tFire.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 50:
            pCombined->tLightning.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 51:
            pCombined->tLightning.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 52:
            pCombined->tMagic.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 53:
            pCombined->tMagic.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 54:
            pCombined->tCold.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 55:
            pCombined->tCold.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 57:
            pCombined->tPoison.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 58:
            pCombined->tPoison.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 59:
            pCombined->tPoison.nLength = STATLIST_GetStatValue(pStatList, nStatId, 0);
            pCombined->tPoison.nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            break;
        case 21:
            pCombined->tDamage.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            if (!pCombined->tDamage.nMin)
                pCombined->tDamage.nMin = STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MINDAMAGE, 0);
            break;
        case 22:
            pCombined->tDamage.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            if (!pCombined->tDamage.nMax)
                pCombined->tDamage.nMax = STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MAXDAMAGE, 0);
            break;
        case 18:
            pCombined->tDamagePercent.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 17:
            pCombined->tDamagePercent.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        }
    }

    if (pCombined->tDamage.nMin > 0 && pCombined->tDamage.nMax > 0)
        pCombined->tDamage.bCombined = 1;
    if (pCombined->tDamagePercent.nMin > 0 && pCombined->tDamagePercent.nMax > 0)
        pCombined->tDamagePercent.bCombined = 1;
    if (pCombined->tCold.nMin > 0 && pCombined->tCold.nMax > 0)
        pCombined->tCold.bCombined = 1;
    if (pCombined->tLightning.nMin > 0 && pCombined->tLightning.nMax > 0)
        pCombined->tLightning.bCombined = 1;
    if (pCombined->tFire.nMin > 0 && pCombined->tFire.nMax > 0)
        pCombined->tFire.bCombined = 1;
    if (pCombined->tPoison.nMin > 0 && pCombined->tPoison.nMax > 0)
        pCombined->tPoison.bCombined = 1;
    if (pCombined->tMagic.nMin > 0 && pCombined->tMagic.nMax > 0)
        pCombined->tMagic.bCombined = 1;
}

static int __stdcall SKILLDESC_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId)
{
    if (pRecord->nOp >= 2 && pRecord->nOp <= 5)
    {
        const int nOpBase = pRecord->wOpBase;
        D2ItemStatCostTxt* pBase = (nOpBase >= 0 && nOpBase < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[nOpBase] : 0;
        if (!pBase)
            return 0;

        nValue = (STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), nOpBase, 0) >> pBase->nValShift) * nValue >> pRecord->nOpParam;
    }

    nValue >>= pRecord->nValShift;
    if (nStatId == 122 && pUnit && pUnit->dwUnitType == UNIT_ITEM && ITEMSIsA(pUnit, 57))
        nValue += 50;

    return nValue;
}

int __stdcall SKILLDESC_IsStatGroupUniform(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nValue, D2ItemStatCostTxt* pRecord, int* pIsSame)
{
    if (!pRecord->wDescGrp)
        return 0;

    for (int i = sgptDataTables->nItemStatCostTxtRecordCount - 1; i >= 0; --i)
    {
        D2ItemStatCostTxt* pOther = (i >= 0 && i < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[i] : 0;
        if (!pOther)
            return 0;

        if (pRecord->wDescGrp == pOther->wDescGrp)
        {
            *pIsSame = i == nStatId;
            const int nStat = STATLIST_GetStatValue(pStatList, i, 0);
            if (nValue != SKILLDESC_GetStatDisplayValue(nStat, pOther, pUnit, i))
                return 0;
        }
    }

    return 1;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
static int __stdcall sub_004E5A20_BuildCombinedStatText(int nStatId, Unicode* pOut, D2CombinedStatsStrc* pCombined)
{
    Unicode wszText[256];
    memset(wszText, 0, sizeof(wszText));

    int bAppend = 0;
    switch (nStatId)
    {
    case 49:
        return pCombined->tFire.bCombined;
    case 55:
        return pCombined->tCold.bCombined;
    case 51:
        return pCombined->tLightning.bCombined;
    case 53:
        return pCombined->tMagic.bCombined;
    case 58:
    case 59:
        return pCombined->tPoison.bCombined;
    case 17:
        return pCombined->tDamagePercent.bCombined;
    case 48:
        if (!pCombined->tFire.bCombined)
            return 0;
        if (pCombined->tFire.nMin >= pCombined->tFire.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1C), pCombined->tFire.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1D), pCombined->tFire.nMin, pCombined->tFire.nMax);
        bAppend = 1;
        break;
    case 54:
        if (!pCombined->tCold.bCombined)
            return 0;
        if (pCombined->tCold.nMin >= pCombined->tCold.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1E), pCombined->tCold.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1F), pCombined->tCold.nMin, pCombined->tCold.nMax);
        bAppend = 1;
        break;
    case 50:
        if (!pCombined->tLightning.bCombined)
            return 0;
        if (pCombined->tLightning.nMin >= pCombined->tLightning.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE20), pCombined->tLightning.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE21), pCombined->tLightning.nMin, pCombined->tLightning.nMax);
        bAppend = 1;
        break;
    case 52:
        if (!pCombined->tMagic.bCombined)
            return 0;
        if (pCombined->tMagic.nMin >= pCombined->tMagic.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE22), pCombined->tMagic.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE23), pCombined->tMagic.nMin, pCombined->tMagic.nMax);
        bAppend = 1;
        break;
    case 57:
        if (!pCombined->tPoison.bCombined)
            return 0;
        if (pCombined->tPoison.nCount <= 0)
            pCombined->tPoison.nCount = 1;
        pCombined->tPoison.nLength /= pCombined->tPoison.nCount;
        pCombined->tPoison.nMin = (pCombined->tPoison.nMin * pCombined->tPoison.nLength + 0x80) >> 8;
        pCombined->tPoison.nMax = (pCombined->tPoison.nMax * pCombined->tPoison.nLength + 0x80) >> 8;
        if (pCombined->tPoison.nMin >= pCombined->tPoison.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE24), pCombined->tPoison.nMax, pCombined->tPoison.nLength / 25);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE25), pCombined->tPoison.nMin, pCombined->tPoison.nMax, pCombined->tPoison.nLength / 25);
        bAppend = 1;
        break;
    case 24:
        if (pCombined->tDamage.bShown)
            return 1;
        return pCombined->tDamage.bCombined;
    case 21:
    case 22:
    case 23:
        if (!pCombined->tDamage.bShown)
        {
            if (!pCombined->tDamage.bCombined)
                return 0;
            if (pCombined->tDamage.nMin >= pCombined->tDamage.nMax)
            {
                pCombined->tDamage.bShown = 0;
                pCombined->tDamage.bCombined = 0;
                return 0;
            }
            pCombined->tDamage.bShown = 1;
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE27), pCombined->tDamage.nMin, pCombined->tDamage.nMax);
        }
        bAppend = 1;
        break;
    case 18:
    {
        const Unicode* pPercent = D2LANG_GetStringFromTblIndex(0xFA1);
        const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
        const Unicode* pPlus = D2LANG_GetStringFromTblIndex(0xFA2);
        Unicode wszNumber[10];
        char szNumber[10];
        SStrPrintf(szNumber, 10, gszFormatI, pCombined->tDamagePercent.nMin);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (!pCombined->tDamagePercent.bCombined)
            return 0;

        sub_005267E0(wszText, pPlus);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, pPercent);
        sub_00526700(wszText, pSpace);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2727));
        bAppend = 1;
        break;
    }
    }

    if (bAppend)
        sub_00526700(pOut, wszText);

    return bAppend;
}


static D2SkillsTxt* sub_H14_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static D2SkillDescTxt* sub_H14_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    return 0;
}

// 0x004E6CE0
unsigned short __fastcall SKILLDESC_GetSkillDescStringId(int skillId, int stringIndex)
{
    D2SkillsTxt* skill = SKILLS_GetSkillsTxtRecord(skillId);
    D2SkillDescTxt* description = 0;
    if (skill)
    {
        description = SKILLTREE_GetSkillDescTxtRecord(skill->wSkillDesc);
    }
    if (!description)
    {
        return static_cast<unsigned short>(0x1506);
    }
    return (&description->wStrName)[stringIndex];
}


// 0x004E6DE0
static unsigned short SKILLDESC_GetSkillDescStrLong(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);

    if (!pSkillDescTxt)
        return 0x1506;

    return pSkillDescTxt->wStrLong;
}

int sub_H14_Emit_004E83B0(Unicode* wszOut, int nSkillId)
{
    return SKILLDESC_AppendSkillDescStrLong(wszOut, nSkillId);
}

static D2SkillsTxt* sub_D05_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004E6EA0
static void __stdcall SKILLDESC_ApplyFireMasteryBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 1)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

// 0x004E6F00
static void __stdcall SKILLDESC_ApplyLightningMasteryBonus(int* pValue1, int* pValue2, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 2)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

// 0x004E6F60
static unsigned short SKILLDESC_GetETypeDamageStr(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 0x10A1;
    case 2:
        return 0x10A3;
    case 4:
        return 0x10A2;
    case 3:
        return 0x10C3;
    case 5:
        return 0x10A4;
    case 6:
        return 0xDC4;
    }
    return 0;
}

// 0x004E6FB0
static int SKILLDESC_GetETypeColor(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 1;
    case 2:
        return 9;
    case 3:
    case 4:
        return 3;
    case 5:
        return 2;
    }
    return 0;
}

// 0x004E7120
int __stdcall SKILLDESC_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor)
{
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
            if (pStatList)
            {
                int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
                    if (pSkillsTxt)
                    {
                        int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
                        if (nSkillLevel > 0)
                        {
                            short nStatId = pSkillsTxt->wAuraStat[0];
                            if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
                            {
                                int nCharges = STATLIST_GetStatValue(pStatList, nStatId, 0);
                                if (nCharges > 0)
                                {
                                    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
                                    if (!pSkillDescTxt)
                                    {
                                        *pMinDamage += SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
                                        *pMaxDamage += SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
                                    }
                                    else
                                    {
                                        const int nIndex = D2_MIN(D2_MAX(nCharges, 1), 3);

                                        *pMinDamage += SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMin[nIndex - 1], nSkillId, nSkillLevel);
                                        *pMaxDamage += SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMax[nIndex - 1], nSkillId, nSkillLevel);
                                        const unsigned char* pElem = pSkillDescTxt->nPrgDamElem;
                                        if (pElem[nIndex - 1] > 0 && pElem[nIndex - 1] < 13)
                                            *pColor = SKILLDESC_GetETypeColor(pElem[nIndex - 1]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

// 0x004E73E0
static __declspec(noinline) int __stdcall SKILLDESC_FormatSignedInt(Unicode* wszText, int bPrefixSign, int nValue)
{
    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

// 0x004E7430
static __declspec(noinline) int __stdcall SKILLDESC_FormatSignedDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction)
{
    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d.%d", nValue, nFraction);
    else
        wsprintfA(szText, "%d.%d", nValue, nFraction);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

// 0x004E7480
static int SKILLDESC_FormatIntOrDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction)
{
    if (!nValue && !nFraction)
        return 0;
    if (nFraction)
        return SKILLDESC_FormatSignedDecimal(wszText, bPrefixSign, nValue, nFraction);
    return SKILLDESC_FormatSignedInt(wszText, bPrefixSign, nValue);
}

static void __stdcall SKILLDESC_FormatDamageRange(int bPrefixSign, Unicode* wszText, int bUseFormat, int nMinDamage, int nMaxDamage); // 0x004E74A0

// 0x004E74A0
static void __stdcall SKILLDESC_FormatDamageRange(int bPrefixSign, Unicode* wszText, int bUseFormat, int nMinDamage, int nMaxDamage)
{
    char szText[32];
    if (bUseFormat && (nMinDamage >= 10000 || nMaxDamage >= 10000))
    {
        if (!(nMinDamage < 10000))
// build: symbol ?gszPlus@* 0x006DBEC4
            wsprintfA(szText, "%s%dK-%dK", bPrefixSign ? gszPlus : &gszEmptyAssertText, (nMinDamage + 500) / 1000, (nMaxDamage + 500) / 1000);
        else
            wsprintfA(szText, "%s%d-%dK", bPrefixSign ? gszPlus : &gszEmptyAssertText, nMinDamage, (nMaxDamage + 500) / 1000);
    }
    else if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMinDamage, nMaxDamage);
    else
        wsprintfA(szText, gszFmtRange, nMinDamage, nMaxDamage);
    sub_00526320_ToUnicode(wszText, szText, 32);
}

// 0x004E75B0
static int SKILLDESC_FormatValueOrRange(Unicode* wszText, int bPrefixSign, int nMin, int nMax)
{
    if (nMin == nMax)
    {
        char szText[32];
        if (bPrefixSign && nMin >= 0)
            wsprintfA(szText, "+%d", nMin);
        else
            wsprintfA(szText, gszFormatD, nMin);
        sub_00526320_ToUnicode(wszText, szText, 32);
        return 1;
    }
    SKILLDESC_FormatDamageRange(bPrefixSign, wszText, 1, nMin, nMax);
    return 1;
}

extern "C" int __stdcall sub_Z13_EmitA(Unicode* p, int a, int b, int c)
{
    return SKILLDESC_FormatValueOrRange(p, a, b, c);
}

// 0x004E7610
static void __stdcall SKILLDESC_FormatDecimalRange(Unicode* wszText, int bPrefixSign, int nMin, int nMinFrac, int nMax, int nMaxFrac)
{
    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, "+%d.%d-%d.%d", nMin, nMinFrac, nMax, nMaxFrac);
    else
        wsprintfA(szText, "%d.%d-%d.%d", nMin, nMinFrac, nMax, nMaxFrac);
    sub_00526320_ToUnicode(wszText, szText, 32);
}

extern "C" void __stdcall sub_K07_EmitB(Unicode* p, int b, int a1, int a2, int a3, int a4)
{
    SKILLDESC_FormatDecimalRange(p, b, a1, a2, a3, a4);
}

// 0x004E7650
static int __stdcall SKILLDESC_AppendFrameRange(Unicode* wszOut, unsigned short wStr, int nMinFrames, int nMaxFrames)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int nMin = nMinFrames / 25;
    int nMinFraction = nMinFrames % 25 * 10 / 25;
    int nMax = nMaxFrames / 25;
    int nMaxFraction = nMaxFrames % 25 * 10 / 25;
    if (!nMin && !nMinFraction && !nMax)
        return 0;

    char szText[32];
    if (nMinFraction || nMaxFraction)
        wsprintfA(szText, "%d.%d-%d.%d", nMin, nMinFraction, nMax, nMaxFraction);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10AC));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E77A0
static int __stdcall SKILLDESC_AppendScaledRange(Unicode* wszOut, unsigned short wStr1, unsigned short wStr2, int nMaxValue, int nMultiplier, int nMinValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int nMin = nMinValue / 256;
    int nMinFraction = nMinValue % 256 * nMultiplier / 256;
    int nMax = nMaxValue / 256;
    int nMaxFraction = nMaxValue % 256 * nMultiplier / 256;
    if (!nMin && !nMax && !nMinFraction && !nMaxFraction)
        return 0;

    char szText[32];
    if (nMinFraction || nMaxFraction)
        wsprintfA(szText, "%d.%d-%d.%d", nMin, nMinFraction, nMax, nMaxFraction);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7930
static int __stdcall SKILLDESC_AppendFormattedValue(int nValue, unsigned short wStr, Unicode* wszOut)
{
    Unicode wszText[256];
    for (int i = 0; i < 256; ++i)
        wszText[i] = 0;

    if (wStr == 0x1506)
    {
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x1506));
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
        return 1;
    }

    sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(wStr), nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszOut, wszText);
    return 1;
}

// 0x004E79E0
static int __stdcall SKILLDESC_AppendLabelValue(unsigned short wStr, int bPrefixSign, Unicode* wszOut, int nValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7A90
static int __stdcall SKILLDESC_AppendScaledValue(unsigned short wStr1, unsigned short wStr2, int nMultiplier, Unicode* wszOut, int bPrefixSign, int nValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    SKILLDESC_FormatIntOrDecimal(wszText, bPrefixSign, nValue / 256, nValue % 256 * nMultiplier / 256);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7B90
static int __stdcall SKILLDESC_AppendLabelDecimal(unsigned short wStr, Unicode* wszOut, int bPrefixSign, int nValue, int nFraction)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue && nFraction <= 0)
        return 0;

    SKILLDESC_FormatIntOrDecimal(wszText, bPrefixSign, nValue, nFraction);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7C30
static int __stdcall SKILLDESC_AppendValueLabel(unsigned short wStr, int bPrefixSign, Unicode* wszOut, int nValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7CE0
static int __stdcall SKILLDESC_AppendValueTwoLabels(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7DB0
static int __stdcall SKILLDESC_AppendValueCountLabel(int nStr1, int nStr2, int bPrefixSign, Unicode* wszOut, int nValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(nValue == 1 ? nStr1 : nStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7E70
static int __stdcall SKILLDESC_AppendLabelValueLabel(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7F40
static int __stdcall SKILLDESC_AppendLabelRangeLabel(Unicode* wszOut, int bPrefixSign, unsigned short wStr2, unsigned short wStr1, int nMin, int nMax)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValueLabel(wStr1, wStr2, 0, wszOut, nMin);

    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMin, nMax);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E8020
static int __stdcall SKILLDESC_AppendLabelsRange(Unicode* wszOut, int bPrefixSign, unsigned short wStr1, unsigned short wStr2, int nMin, int nMax)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValueLabel(wStr1, wStr2, 0, wszOut, nMin);

    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMin, nMax);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E80F0
static int __stdcall SKILLDESC_AppendLabelRange(Unicode* wszOut, int bSeparator, int bPrefixSign, unsigned short wStr, int nMin, int nMax)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValue(wStr, bPrefixSign, wszOut, nMin);

    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    char szText[32];
    if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMin, nMax);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    if (bSeparator)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E81C0
static int __stdcall SKILLDESC_AppendLabelValueLabels(unsigned short wStr1, unsigned short wStr2, unsigned short wStr3, int bPrefixSign, Unicode* wszOut, int nValue)
{
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    char szText[32];
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr3));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall SKILLDESC_AppendSecondsTwentieths(unsigned short wStr, Unicode* wszOut, int nValue); // 0x004E82A0

// 0x004E82A0
static int __stdcall SKILLDESC_AppendSecondsTwentieths(unsigned short wStr, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    const int nTenths = nValue * 20 / 3;
    const int nFraction = nTenths % 10;
    int nWhole = nTenths / 10;
    if (nWhole < 1)
        nWhole = 1;
    if (nWhole || nFraction)
    {
        int szText_[8]; char* const szText = (char*)szText_;
        if (nFraction)
            wsprintfA(szText, "%d.%d", nWhole, nFraction);
        else
            wsprintfA(szText, gszFormatD, nWhole);
        sub_00526320_ToUnicode(wszText, szText, 32);
    }
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    if (nWhole == 1)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10C0));
    else
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10B6));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

int __fastcall sub_Emit_004E82A0(Unicode* wszOut, int nValue, int nStr)
{
    if (!wszOut)
        return 0;
    return SKILLDESC_AppendSecondsTwentieths((unsigned short)nStr, wszOut, nValue);
}

// 0x004E83B0
static int SKILLDESC_AppendSkillDescStrLong(Unicode* wszOut, int nSkillId)
{
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStrLong(nSkillId)));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall SKILLDESC_AppendSecondsTenths(unsigned short wStr, Unicode* wszOut, int nValue); // 0x004E83E0

// 0x004E83E0
static int __stdcall SKILLDESC_AppendSecondsTenths(unsigned short wStr, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    const int nTenths = nValue * 10 / 3;
    const int nFraction = nTenths % 10;
    int nWhole = nTenths / 10;
    if (nWhole < 1)
        nWhole = 1;
    if (nWhole || nFraction)
    {
        int szText_[8]; char* const szText = (char*)szText_;
        if (nFraction)
            wsprintfA(szText, "%d.%d", nWhole, nFraction);
        else
            wsprintfA(szText, gszFormatD, nWhole);
        sub_00526320_ToUnicode(wszText, szText, 32);
    }
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    if (nWhole == 1)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10C0));
    else
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10B6));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

int __fastcall sub_Emit_004E83E0(Unicode* wszOut, int nValue, int nStr)
{
    if (!wszOut)
        return 0;
    return SKILLDESC_AppendSecondsTenths((unsigned short)nStr, wszOut, nValue);
}

// 0x004E84F0
static int __stdcall SKILLDESC_AppendManaValue(int nValue, Unicode* wszOut)
{
    const Unicode* wszStr1 = D2LANG_GetStringFromTblIndex(0x5300);
    const Unicode* wszStr2 = D2LANG_GetStringFromTblIndex(0x5304);
    const Unicode* wszStr3 = D2LANG_GetStringFromTblIndex(0x5305);
    const Unicode* wszStr4 = D2LANG_GetStringFromTblIndex(0xF9B);
    Unicode wszText[16];
    for (int i = 0; i < 16; ++i)
        wszText[i] = 0;

    char szText[32];
    wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszStr2);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, wszStr4);
    sub_00526700(wszOut, wszStr1);
    sub_00526700(wszOut, wszStr3);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E85C0_AppendManaCost(Unicode* wszOut, int nSkillId, int nLevel, int nMultiplier, D2SkillsTxt* pSkillsTxt, int nValue)
{
    short nMana = pSkillsTxt->wMana;
    if (!nMana && !pSkillsTxt->wLevelMana)
        return 0;

    if (nValue)
        return SKILLDESC_AppendManaValue(nValue, wszOut);

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
        return 0;

    unsigned short wStr = pSkillDescTxt->wStrMana;
    int nCost = ((nLevel - 1) * pSkillsTxt->wLevelMana + nMana) << pSkillsTxt->nManaShift;
    int nMinCost = pSkillsTxt->wMinMana << 8;
    if (nMinCost > nCost)
        nCost = nMinCost;

    if (pSkillsTxt->nManaShift == 8 || pSkillsTxt->wLevelMana << pSkillsTxt->nManaShift > 0x100 || nCost > 0x1900)
        return SKILLDESC_AppendLabelValue(wStr, 0, wszOut, nCost >> 8);

    if (nMultiplier > 10)
        return SKILLDESC_AppendScaledValue(wStr, 0x1506, nMultiplier, wszOut, 0, nCost);

    return SKILLDESC_AppendLabelDecimal(wStr, wszOut, 0, nCost / 256, nCost % 256 * 10 / 256);
}

// 0x004E8D90
static void SKILLDESC_AddElementalStatDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, unsigned char nType)
{
    switch (nType)
    {
    case 1:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMAXDAM, 0);
        break;
    case 2:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMAXDAM, 0);
        break;
    case 4:
    case 12:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMAXDAM, 0);
        break;
    case 3:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMAXDAM, 0);
        break;
    case 5:
    {
        int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (nCount <= 1)
                nCount = 1;
            nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
        }
        int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
        *pMinDamage += nMin * nLength >> 8;
        *pMaxDamage += nMax * nLength >> 8;
        break;
    }
    }
}

// 0x004E8EC0
static int __stdcall SKILLDESC_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue2 = 0;
    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == ITEMTYPE_MISSILE_POTION)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);
    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_TOHIT_PERCENT, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    if (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        int nProgressive = STATLIST_UnitGetStatValue(pUnit, STAT_PROGRESSIVE_TOHIT, 0);
        if (nProgressive)
        {
            nBonus += nProgressive;
            *pValue2 = 3;
        }
    }
    *pValue1 += *pValue1 * nBonus / 100;

    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
}

// 0x004E8FE0
int __fastcall SKILLDESC_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem)
{
    return SKILLDESC_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nAdd, pSkill);
}

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0

// 0x004E9040
void __fastcall PLRSKILLS_DescAttackRating(D2UnitStrc* pUnit, void* pArg, D2SkillsTxt* pSkillsTxtRecord, int nSkillLevel, int* pValue, int* pColor, int nArg5, int nArg6)
{
    D2UnitStrc* pWeapon = 0;
    if (pUnit->pInventory)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    *pValue = 0;
    *pColor = 0;
    if (!pArg)
    {
        return;
    }

    if (pWeapon)
    {
        int bStatNotDynamic = 0;
        D2UnitStrc* pOwner = STATLIST_GetOwner(pWeapon, &bStatNotDynamic);
        STATLIST_MergeStatLists(pUnit, pWeapon, 0);
        *pValue = UNITS_GetAttackRate(pUnit);
        if (pOwner)
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, bStatNotDynamic);
        }
        else
        {
            STATLIST_ExpireUnitStatlist(pUnit, pWeapon);
        }
    }
    else
    {
        *pValue = UNITS_GetAttackRate(pUnit);
    }

    int nToHit = STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_TOHIT_PERCENT, 0);
    nToHit += SKILLS_GetToHitFactor(pUnit, pSkillsTxtRecord->nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[3])
    {
        const int nBonus = STATLIST_UnitGetStatValue(pUnit, STAT_PROGRESSIVE_TOHIT, 0);
        if (nBonus)
        {
            nToHit += nBonus;
            *pColor = 3;
        }
    }

    *pValue += *pValue * nToHit / 100;
    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }

    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
    {
        *pColor = 1;
    }
}

// 0x004E9260
static D2UnitStrc* SKILLDESC_MergeOtherHandWeapon(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (!pOther || pOther == pWeapon)
        return 0;

    if (!ITEMSIsA(pOther, 45))
        return 0;

    if (!ITEMS_CanBeEquipped(pWeapon) || !ITEMS_CanBeEquipped(pOther))
        return 0;

    if (STATLIST_GetOwner(pWeapon, 0))
        STATLIST_MergeStatLists(pUnit, pWeapon, 0);
    if (STATLIST_GetOwner(pOther, 0))
        STATLIST_MergeStatLists(pUnit, pOther, 1);
    return pOther;
}

static D2UnitStrc* sub_004E9300_MergeWeaponPair(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (pOther && pOther != pWeapon)
    {
        if (ITEMSIsA(pOther, 45))
        {
            if (ITEMS_CanBeEquipped(pWeapon) && ITEMS_CanBeEquipped(pOther))
            {
                STATLIST_MergeStatLists(pUnit, pOther, 0);
                STATLIST_MergeStatLists(pUnit, pWeapon, 1);
                return pWeapon;
            }
        }
    }

    if (ITEMS_CanBeEquipped(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    return pWeapon;
}

// 0x004E93A0
static int __stdcall SKILLDESC_EvaluateForEachWeapon(int* pValue1, int* pValue2, int* pColor1, int* pValue3, int* pValue4, int* pColor2, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nBonus, D2UnitStrc* pUnit, int nAdd)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (!ITEMS_CanBeEquipped(pRight) || ITEMSIsA(pRight, 0x26))
        pRight = 0;

    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (!ITEMS_CanBeEquipped(pLeft) || ITEMSIsA(pLeft, 0x26))
        pLeft = 0;

    if (pRight && pLeft)
    {
        D2UnitStrc* pItem = SKILLDESC_MergeOtherHandWeapon(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue3, pValue4, pColor2, nBonus, nAdd, pSkill, 0, pItem);
        }
        else
        {
            *pValue3 = 0;
            *pValue4 = 0;
        }

        pItem = sub_004E9300_MergeWeaponPair(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue1, pValue2, pColor1, nBonus, nAdd, pSkill, 0, pItem);
        }
        else
        {
            *pValue1 = 0;
            *pValue2 = 0;
        }
        return 1;
    }

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (pWeapon && ITEMS_CanBeEquipped(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    pfnEvaluate(pUnit, pValue1, pValue2, pColor1, nBonus, nAdd, pSkill, 0, 0);
    return 1;
}

// 0x004E94E0
static int __stdcall SKILLDESC_AttackRatingForEachWeapon(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pValue3, int* pValue4, D2SkillStrc* pSkill, int nLevel)
{
    return SKILLDESC_EvaluateForEachWeapon(pValue1, pValue2, 0, pValue3, pValue4, 0, pSkill, SKILLDESC_AttackRatingCallback, 0, pUnit, nLevel);
}

// 0x004E9510
void __fastcall SKILLDESC_DescAttackRating(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    if (UNITS_CanDualWield(pUnit))
    {
        SKILLDESC_AttackRatingForEachWeapon(pUnit, pValue1, pValue2, pValue3, pValue4, pSkill, nLevel);
        return;
    }

    D2UnitStrc* pItem = 0;
    if (pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    *pValue1 = 0;
    *pValue2 = 0;
    SKILLDESC_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}

// 0x004E95C0
void __fastcall SKILLDESC_DescAttackRatingOffhand(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    SKILLDESC_AttackRatingForEachWeapon(pUnit, pValue1, pValue2, pValue3, pValue4, pSkill, nLevel);
    *pValue1 = *pValue3;
    *pValue2 = *pValue4;
    *pValue3 = 0;
    *pValue4 = 0;
}

// 0x004E9610
int __fastcall SKILLDESC_WeaponDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem)
{
    sub_004E86F0_GetWeaponDamage(pMinDamage, pMaxDamage, pColor, nAdd, pSkill, nSrcDam, pItem, 0, pUnit, nBonus);
    return sub_004E89A0_GetElementalDamage(pUnit, pMinDamage, pMaxDamage, pColor, pSkill);
}

// 0x004E9660
static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill, D2UnitStrc* pItem, int nRatio)
{
    if (!nRatio)
        return;

    int nMin = 0;
    int nMax = 0;
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, pColor, 0, pSkill, 128, pItem, 0, pUnit, 0);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, pColor, pSkill);
    *pMinDamage += nMin * nRatio / 128;
    *pMaxDamage += nMax * nRatio / 128;
}

static inline int sub_I05_ETypeColor(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 1;
    case 2:
        return 9;
    case 3:
    case 4:
        return 3;
    case 5:
        return 2;
    }
    return 0;
}

static void __stdcall SKILLDESC_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    int nMin;
    int nMax;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        *pType = 2;
        nMin = nLength * SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }

    if (pType)
    {
        const int nColor = sub_I05_ETypeColor(pSkillsTxt->nEType);
        if (nColor)
        {
            *pType = nColor;
        }
    }

    *pMin += nMin;
    *pMax += nMax;
}

// 0x004E96E0
static void __fastcall SKILLDESC_DrawDamageRange(int nMin, int nMax, int nColor, int nY, int nLeft, int nRight)
{
    if (nMin >= nMax)
    {
        nMax = nMin + 1;
    }

    Unicode wszText[32];
    char szText[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, gszFormatD, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText, szText, 32);
    int nWidth = 0;
    int nHeight = 0;
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    nWidth = nWidth * 11 / 7;
    if (nWidth > nRight - nLeft)
    {
        D2Win_10127_SetFont(6);
        --nY;
    }
    else
    {
        D2Win_10127_SetFont(1);
    }
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + nY - 480, gnPanelOffsetX + nRight, wszText, nColor);
}

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
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

int __fastcall sub_H14_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nCalcA, int nCalcB, int nLine, unsigned short nStringA, short nMissileId)
{
    switch (nLine)
    {
    case 2:
        SKILLDESC_AddElemRange(wszText, nCalcA, nStringA, nCalcB, pSkillsTxt->nEType);
        return 1;
    case 3:
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        return 1;
    case 4:
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        return 1;
    case 5:
        SKILLDESC_AddMissileElemDamage(pUnit, wszText, nStringA, nMissileId, nSkillLevel);
        return 1;
    }
    return 0;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004E99F0
static void __stdcall SKILLDESC_DrawWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, SKILLWEAPONFN pfnEvaluate, int nBonus, int nAdd, int nLeft, int nY, int nRight, int bElemDamage)
{
    if (!pSkill || !pSkillsTxt || !pfnEvaluate)
    {
        return;
    }

    int nElemMin = 0;
    int nElemMax = 0;
    int nColor1 = 0;
    int nColor2 = 0;
    if (bElemDamage)
    {
        SKILLDESC_GetElemDamage(pUnit, &nElemMin, &nElemMax, &nColor1, pSkillsTxt, nSkillLevel);
    }
    nColor2 = nColor1;

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nMin1 = 0;
    int nMax1 = 0;
    int nMin2 = 0;
    int nMax2 = 0;
    SKILLDESC_EvaluateForEachWeapon(&nMin1, &nMax1, &nColor1, &nMin2, &nMax2, &nColor2, pSkill, pfnEvaluate, nBonus, pUnit, nAdd);
    if (nMin1 && nMax1)
    {
        nMin1 = nMin1 * nSrcDam / 128 + nElemMin;
        nMax1 = nMax1 * nSrcDam / 128 + nElemMax;
    }
    if (nMin2 && nMax2)
    {
        nMin2 = nMin2 * nSrcDam / 128 + nElemMin;
        nMax2 = nMax2 * nSrcDam / 128 + nElemMax;
    }

    if (!nMin1 && !nMax1)
    {
        SKILLDESC_DrawDamageRange(nMin2, nMax2, nColor2, nY, nLeft, nRight);
        return;
    }

    if (!nMin2 && !nMax2)
    {
        SKILLDESC_DrawDamageRange(nMin1, nMax1, nColor1, nY, nLeft, nRight);
        return;
    }

    Unicode wszText1[32];
    char szText[32];
    if (nMin1 == nMax1)
    {
        wsprintfA(szText, gszFormatD, nMin1);
    }
    else if (nMin1 < 10000 && nMax1 < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin1, nMax1);
    }
    else if (nMin1 >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin1 + 500) / 1000, (nMax1 + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin1, (nMax1 + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nMin2 == nMax2)
    {
        wsprintfA(szText, gszFormatD, nMin2);
    }
    else if (nMin2 < 10000 && nMax2 < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin2, nMax2);
    }
    else if (nMin2 >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin2 + 500) / 1000, (nMax2 + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin2, (nMax2 + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nColor1, nColor2);
}

void __fastcall sub_H14_Emit_004E9510(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    if (UNITS_CanDualWield(pUnit))
    {
        SKILLDESC_AttackRatingForEachWeapon(pUnit, pValue1, pValue2, pValue3, pValue4, pSkill, nLevel);
        return;
    }

    SKILLDESC_EvaluateForEachWeapon(pValue1, pValue2, 0, pValue3, pValue4, 0, pSkill, SKILLDESC_AttackRatingCallback, 0, pUnit, nLevel);
}

static int __stdcall sub_004E86F0_GetWeaponDamage(int* pMinDamage, int* pMaxDamage, int* pColor, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem, int bStatBonus, D2UnitStrc* pUnit, int nBonus)
{
    if (!pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!pItem)
        pItem = INVENTORY_GetLeftHandWeapon(pInventory);

    int nMin;
    int nMax;
    if (pItem)
    {
        DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (bStatBonus)
        {
            nMin = D2Common_11248(pUnit, pItem, 0x15);
            nMax = D2Common_11248(pUnit, pItem, 0x16);
        }
        else if (INVENTORY_GetWieldType(pUnit, pInventory) != 2)
        {
            nMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
        }
        else
        {
            nMin = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
        }
    }
    else
    {
        nMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0) + 1;
        nMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0) + 2;
    }

    if (!nSrcDam)
        nSrcDam = pSkillsTxt->nSrcDam;

    if (nSrcDam != 128)
    {
        nMin = nMin * nSrcDam / 128;
        nMax = nMax * nSrcDam / 128;
    }

    if (nSrcDam)
    {
        if (nMin < 1)
            nMin = 1;
        *pMinDamage += nMin;
        if (nMax < 2)
            nMax = 2;
        *pMaxDamage += nMax;
    }

    nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
    nBonus += SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 1);
    int nMinPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
    int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
    if (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        int nProgressive = SKILLDESC_SumProgressiveBonus();
        if (nProgressive)
        {
            nBonus += nProgressive;
            *pColor = 3;
        }
    }

    int nDamage = 0;
    if (pItem)
    {
        int nFactor = ITEMS_GetStrengthBonus(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) * nFactor / 100;
        nFactor = ITEMS_GetDexBonus(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) * nFactor / 100;
        nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_NORMALDAMAGE, 0);
    }
    else
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
        *pColor = 3;
    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
        *pColor = 1;

    if (nBonus <= -90)
        nBonus = -90;

    *pMinDamage = (nMinPercent + nBonus + 100) * *pMinDamage / 100 + nDamage + nAdd;
    *pMaxDamage = (nMaxPercent + nBonus + 100) * *pMaxDamage / 100 + nDamage + nAdd;
    return 1;
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004E9D20
void __fastcall SKILLDESC_DrawWeaponAndSkillDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nWeaponMin = 0;
    int nWeaponMax = 0;
    int nWeaponColor = 0;
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nWeaponMin, &nWeaponMax, &nWeaponColor, pSkill, 0, pSkillsTxt->nSrcDam);
    const int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    int nMin = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    SKILLDESC_AddElementalStatDamage(pUnit, &nMin, &nMax, pSkillsTxt->nEType);

    if (!nWeaponMin && !nWeaponMax)
    {
        SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nWeaponMin, nWeaponMax, nWeaponColor, nY, nLeft, nRight);
        return;
    }

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, gszFormatD, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, gszFormatD, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

// 0x004EA170
void __fastcall SKILLDESC_DrawDualWieldLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    if (UNITS_CanDualWield(pUnit))
    {
// build: symbol ?gszSkillDescFile@* 0x006DBF24
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9B8), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9B9), nSkillLevel);
        SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 1);
        return;
    }

    SKILLDESC_DrawSkillWeaponLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

// 0x004EA240
void __fastcall SKILLDESC_DrawDualWieldLineNoElem(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    if (UNITS_CanDualWield(pUnit))
    {
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9DD), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x9DE), nSkillLevel);
        SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 0);
        return;
    }

    SKILLDESC_DrawSkillWeaponLine(pUnit, pSkill, pSkillsTxt, nSkillLevel, nLeft, nY, nRight);
}

// 0x004EA310
void __fastcall SKILLDESC_DrawWeaponDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    if (UNITS_CanDualWield(pUnit))
    {
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA02), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA03), nSkillLevel);
        SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_WeaponDamageCallback, nBonus, nAdd, nLeft, nY, nRight, 1);
    }
    else
    {
        int nMin = 0;
        int nMax = 0;
        int nColor = 0;
        const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA0C), nSkillLevel);
        const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xA0D), nSkillLevel);
        SKILLDESC_WeaponDamageCallback(pUnit, &nMin, &nMax, &nColor, nBonus, nAdd, pSkill, 0, 0);
        SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
    }
}

// 0x004EA450
void __fastcall SKILLDESC_DrawKickBaseDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nDamage = pSkillsTxt->dwMinDam << (pSkillsTxt->nToHitShift - 8);
    nDamage += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_KICKDAMAGE, 0);
    SKILLDESC_DrawDamageRange(nDamage, nDamage, 0, nY, nLeft, nRight);
}

static D2SkillsTxt* sub_I05_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
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

static inline void AddPoisonDamage_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
{
    int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
    int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
    if (nMax)
    {
        int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
        if (nMastery)
        {
            nMin += ApplyRatio_Inline(nMin, nMastery, 100);
            nMax += ApplyRatio_Inline(nMax, nMastery, 100);
        }

        int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (nCount <= 1)
            {
                nCount = 1;
            }
            nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
        }

        nMax = nLength * nMax >> 8;
        nMin = nLength * nMin >> 8;
        *pColor = 2;
        *pMinDamage += nMin;
        *pMaxDamage += nMax;
    }
    else
    {
    }
}

static inline void AddPoisonDamageAndClamp_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
{
    AddPoisonDamage_Inline(pUnit, pMaxDamage, pMinDamage, pColor);

    if (*pMaxDamage > 0)
    {
        *pMinDamage = *pMinDamage < 1 ? 1 : *pMinDamage;
        *pMaxDamage = D2_MAX(*pMinDamage + 1, *pMaxDamage);
    }
}

int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill)
{
    for (int i = 0; i < 4; ++i)
    {
        int nMin = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMinStat, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMaxStat, 0);
        if (gaElemDamageStats[i].nMasteryStat != -1)
        {
            int nMastery = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMasteryStat, 0);
            if (nMastery)
            {
                nMin += ApplyRatio_Inline(nMin, nMastery, 100);
                nMax += ApplyRatio_Inline(nMax, nMastery, 100);
            }
        }

        if (nMin >= nMax)
        {
            nMin = nMax;
        }

        *pMinDamage += nMin;
        *pMaxDamage += nMax;
        if (nMin || nMax)
        {
// build: symbol ?gaElemDamageColors@* 0x006DBEE4
            *pColor = gaElemDamageColors[i];
        }
    }

    AddPoisonDamageAndClamp_Inline(pUnit, pMaxDamage, pMinDamage, pColor);

    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7]))
        {
            SKILLDESC_AddProgressiveDamage(pUnit, pMinDamage, pMaxDamage, pColor);
        }
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }

    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
    {
        *pColor = 1;
    }

    return 1;
}


// 0x004EA790
void __fastcall SKILLDESC_DrawWeaponStatDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nColor = 0;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pItem || !sub_0062BA80_CheckItem(pItem))
    {
        return;
    }

    int nBonus = 0;
    int nFactor = ITEMS_GetStrengthBonus(pItem);
    if (nFactor)
    {
        nBonus = STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) * nFactor / 100;
    }
    nFactor = ITEMS_GetDexBonus(pItem);
    if (nFactor)
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) * nFactor / 100;
    }

    int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_THROW_MINDAMAGE, 0);
    int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_THROW_MAXDAMAGE, 0);
    nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
    const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
    const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
    if (nBonus <= -90)
    {
        nBonus = -90;
    }
    nMin += (nMinPercent + nBonus) * nMin / 100;
    nMax += (nMaxPercent + nBonus) * nMax / 100;

    int nMastery = 0;
    if (STATES_CheckState(pUnit, STATE_THROWINGMASTERY))
    {
        nMastery = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 1);
    }
    nMin += DATATBLS_ApplyRatio(nMin, nMastery, 100);
    nMax += DATATBLS_ApplyRatio(nMax, nMastery, 100);
    SKILLDESC_AddElementalStatDamage(pUnit, &nMin, &nMax, pSkillsTxt->nEType);
    if (nMax < nMin)
    {
        nMax = nMin;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
    nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);
    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}

extern "C" int __stdcall sub_D05_Emit_4E7650(Unicode* p, unsigned short w, int a, int b) { return SKILLDESC_AppendFrameRange(p, w, a, b); }

extern "C" int __stdcall sub_D05_Emit_4E77A0(Unicode* p, unsigned short w1, unsigned short w2, int a, int m, int b) { return SKILLDESC_AppendScaledRange(p, w1, w2, a, m, b); }

extern "C" int __stdcall sub_D05_Emit_4E7930(int n, unsigned short w, Unicode* p) { return SKILLDESC_AppendFormattedValue(n, w, p); }

extern "C" int __stdcall sub_D05_Emit_4E79E0(unsigned short w, int b, Unicode* p, int n) { return SKILLDESC_AppendLabelValue(w, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7A90(unsigned short w1, unsigned short w2, int m, Unicode* p, int b, int n) { return SKILLDESC_AppendScaledValue(w1, w2, m, p, b, n); }

extern "C" int __stdcall sub_D05_Emit_4E7C30(unsigned short w, int b, Unicode* p, int n) { return SKILLDESC_AppendValueLabel(w, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7CE0(unsigned short w1, unsigned short w2, int b, Unicode* p, int n) { return SKILLDESC_AppendValueTwoLabels(w1, w2, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7DB0(unsigned short w1, unsigned short w2, int b, Unicode* p, int n) { return SKILLDESC_AppendValueCountLabel(w1, w2, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7E70(unsigned short w1, unsigned short w2, int b, Unicode* p, int n) { return SKILLDESC_AppendLabelValueLabel(w1, w2, b, p, n); }

extern "C" int __stdcall sub_D05_Emit_4E7F40(Unicode* p, int b, unsigned short w2, unsigned short w1, int a, int c) { return SKILLDESC_AppendLabelRangeLabel(p, b, w2, w1, a, c); }

extern "C" int __stdcall sub_D05_Emit_4E8020(Unicode* p, int b, unsigned short w2, unsigned short w1, int a, int c) { return SKILLDESC_AppendLabelsRange(p, b, w1, w2, a, c); }

extern "C" int __stdcall sub_D05_Emit_4E80F0(Unicode* p, int f, int b, unsigned short w, int a, int c) { return SKILLDESC_AppendLabelRange(p, f, b, w, a, c); }

extern "C" int __stdcall sub_D05_Emit_4E81C0(unsigned short w1, unsigned short w2, unsigned short w3, int b, Unicode* p, int n) { return SKILLDESC_AppendLabelValueLabels(w1, w2, w3, b, p, n); }


extern "C" int __stdcall sub_D05_Emit_4E85C0(Unicode* p, int s, int l, int m, D2SkillsTxt* t, int v) { return sub_004E85C0_AppendManaCost(p, s, l, m, t, v); }

extern "C" void __stdcall sub_D05_Emit_4E6EA0(int* a, int* b, D2SkillsTxt* t) { SKILLDESC_ApplyFireMasteryBonus(a, t, b); }

extern "C" void __stdcall sub_D05_Emit_4E6F00(int* a, int* b, D2SkillsTxt* t) { SKILLDESC_ApplyLightningMasteryBonus(a, b, t); }

extern "C" unsigned short __stdcall sub_D05_Emit_4E6F60(int n) { return SKILLDESC_GetETypeDamageStr(n); }

extern "C" void __stdcall sub_D05_Emit_4E8D90(D2UnitStrc* u, int* a, int* b, unsigned char t) { SKILLDESC_AddElementalStatDamage(u, a, b, t); }

extern "C" void __stdcall sub_D05_Emit_4E9660(D2UnitStrc* u, int* a, int* b, D2UnitStrc* i, int* c, D2SkillStrc* k, int r) { SKILLDESC_AddScaledWeaponDamage(u, a, b, c, k, i, r); }

static void __stdcall SKILLDESC_GetElemDamage(D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nLevel, int* pMin, int* pMax, int* pType)
{
    int nMin;
    int nMax;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nLevel, 1);
        *pType = 2;
        nMin = (nLength * SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1)) >> 8;
        nMax = (SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1) * nLength) >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1) >> 8;
    }

    if (pType)
    {
        switch (pSkillsTxt->nEType)
        {
        case 1:
            *pType = 1;
            break;
        case 2:
            *pType = 9;
            break;
        case 3:
        case 4:
            *pType = 3;
            break;
        case 5:
            *pType = 2;
            break;
        }
    }

    *pMin += nMin;
    *pMax += nMax;
}

// 0x004EA990
void __fastcall SKILLDESC_DrawSkillDamage(D2UnitStrc* pUnit, int nParam, D2SkillsTxt* pSkillsTxt, int nLevel, int nLeft, int nY, int nRight)
{
    if (!nParam || !pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nDamage[2];
    int nType = 0;
    sub_004EA4A0(pUnit, &nDamage[0], &nDamage[1], &nType, 0, 0, nParam, 0, 0);
    nDamage[0] = nDamage[0] * nSrcDam / 128;
    nDamage[1] = nDamage[1] * nSrcDam / 128;
    SKILLDESC_GetElemDamage(pSkillsTxt, pUnit, nLevel, &nDamage[0], &nDamage[1], &nType);
    SKILLDESC_DrawDamageRange(nDamage[0], nDamage[1], nType, nY, nLeft, nRight);
}

// 0x004EAA30
void __fastcall SKILLDESC_DrawOtherHandDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    D2UnitStrc* pItem = SKILLDESC_MergeOtherHandWeapon(pUnit);
    if (!pItem)
    {
        return;
    }

    SKILLDESC_ThrowDamageCallback(pUnit, &nMin, &nMax, &nColor, 0, 0, pSkill, 0, pItem);
    sub_004E9300_MergeWeaponPair(pUnit);
    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}

// 0x004EAD60
void __fastcall SKILLDESC_DrawWeaponPhysElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkill, 0, pSkillsTxt->nSrcDam);
    nMin += SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMax += SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }
    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}

// 0x004EAF90
void __fastcall SKILLDESC_DrawWeaponAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nWeaponMinOutput = 0;
    int nWeaponMaxOutput = 0;
    int nWeaponColor = 0;
    sub_004E86F0_GetWeaponDamage(&nWeaponMinOutput, &nWeaponMaxOutput, &nWeaponColor, 0, pSkill, 0x80, 0, 0, pUnit, 0);
    sub_004E89A0_GetElementalDamage(pUnit, &nWeaponMinOutput, &nWeaponMaxOutput, &nWeaponColor, pSkill);

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);

    if (!nWeaponMinOutput && !nWeaponMaxOutput)
    {
        SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nWeaponMinOutput, nWeaponMaxOutput, nWeaponColor, nY, nLeft, nRight);
        return;
    }

    int nWeaponMin = nWeaponMinOutput;
    int nWeaponMax = nWeaponMaxOutput;

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, gszFormatD, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, gszFormatD, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

// 0x004EB240
void __fastcall SKILLDESC_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], pSkillsTxt->nSkillId, nSkillLevel);
    SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, SKILLDESC_ThrowDamageCallback, nBonus, 0, nLeft, nY, nRight, 1);
}

// 0x004EB290
void __fastcall SKILLDESC_DrawElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDesc = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDesc)
    {
        return;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    // volatile: the volatile read keeps the original's esi/edi assignment; no plain form found
    const int nLevel = *(volatile int*)&nSkillLevel;
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nLevel, 1);
    const int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);

// build: symbol ?gszSkillDescFile@* 0x006DBF24
    int nFrames = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDesc->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 3114), nLevel);
    if (!nFrames)
    {
        nFrames = 1;
    }

    int nDivisor = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDesc->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 3119), nLevel);
    if (!nDivisor)
    {
        nDivisor = 1;
    }

    SKILLDESC_DrawDamageRange((nFrames * nMin * 25 / nDivisor) >> 8, (nFrames * nMax * 25 / nDivisor) >> 8, nColor, nY, nLeft, nRight);
}


// 0x004EB390
void __fastcall SKILLDESC_DrawElementalDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
        return;

    if (!pSkillsTxt)
        return;

    const int nShift = pSkillsTxt->nToHitShift;
    int nMinElem = pSkillsTxt->dwMinDam << nShift;
    int nMaxElem = pSkillsTxt->dwMaxDam << nShift;
    nMinElem += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
    nMaxElem += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
    int& nColor = nSkillLevel;
    nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    int nMin = nMinElem * 75 >> 8;
    int nMax = nMaxElem * 75 >> 8;
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkill, 0, pSkillsTxt->nSrcDam);
    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}

// 0x004EB460
void __fastcall SKILLDESC_DrawThrowDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2UnitStrc* pItem;
    if (!INVENTORY_GetEquippedShield(pUnit->pInventory, &pItem))
    {
        return;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    int nMin = pItemsTxtRecord->nMinDam;
    int nMax = pItemsTxtRecord->nMaxDam;
    D2SkillStrc* pThrowSkill = SKILLS_GetSkillById(pUnit, SKILL_HOLYSHIELD, -1);
    if (pThrowSkill && STATES_CheckState(pUnit, STATE_HOLYSHIELD))
    {
        const int nLevel = SKILLS_GetSkillLevel(pUnit, pThrowSkill, 1);
        nMin += SKILLS_GetMinPhysDamage(pUnit, SKILL_HOLYSHIELD, nLevel, 1) >> 8;
        nMax += SKILLS_GetMaxPhysDamage(pUnit, SKILL_HOLYSHIELD, nLevel, 1) >> 8;
    }

    int nColor = 0;
// build: symbol ?MISSILE_GetSkillMissileRange@* 0x004CC7C0
    int nBonus = MISSILE_GetSkillMissileRange(pSkillsTxt->nSkillId, nSkillLevel);
    int nFactor = ITEMS_GetStrengthBonus(pItem);
    if (nFactor)
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, 0, 0) * nFactor / 100;
    }
    nFactor = ITEMS_GetDexBonus(pItem);
    if (nFactor)
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, 2, 0) * nFactor / 100;
    }

    nBonus += STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
    const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, 0x12, 0);
    const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, 0x11, 0);
    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
    {
        nColor = 3;
    }
    const int nDrawColor = STATES_CheckStateMaskDamRedOnUnit(pUnit) ? 1 : nColor;
    if (nBonus <= -90)
    {
        nBonus = -90;
    }

    SKILLDESC_DrawDamageRange(nMin + (nBonus * nMin + nMinPercent) / 100, nMax + (nBonus * nMax + nMaxPercent) / 100, nDrawColor, nY, nLeft, nRight);
}


// 0x004EB640
void __fastcall SKILLDESC_DrawMasteryWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    int nWeaponMin;
    int nWeaponMax;
    int nMin;
    int nMax;
    int nColor;

    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    nMin = 0;
    nMax = 0;
    nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkill, 0, pSkillsTxt->nSrcDam);

    if (D2Common_10434(pUnit, 1))
    {
        if (INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
        {
            nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
            nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
        }
        else
        {
            nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
            nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
        }
    }
    else
    {
        nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
        nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    }

    if (nWeaponMin <= 1)
    {
        nWeaponMin = 1;
    }
    if (nWeaponMax <= 2)
    {
        nWeaponMax = 2;
    }
    if (nWeaponMax < nWeaponMin)
        {
            nWeaponMax = nWeaponMin;
        }

    const int nSkillId = pSkillsTxt->nSkillId;
    int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_COLD_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[2], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    if (!nColor)
    {
        nColor = 3;
    }
    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}

// 0x004EB830
void __fastcall SKILLDESC_DrawBoostedElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    if (GAME_IsExpansion())
    {
        int nMin = 0;
        int nMax = 0;
        int nColor = 0;
        SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);
        const int nBonus = SKILLS_GetConcentrationDamageBonus(pUnit, pSkillsTxt->nSkillId);
        nMin += nMin * nBonus / 100;
        nMax += nMax * nBonus / 100;
        SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
    }
    else
    {
        int nMin = 0;
        int nMax = 0;
        int nColor = 0;
        SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);
        int nPercent = STATLIST_UnitGetStatValue(pUnit, 0x19, 0);
        if (nPercent <= -90)
        {
            nPercent = -90;
        }
        nMin += nMin * nPercent / 100;
        nMax += nMax * nPercent / 100;
        SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
    }
}


void __fastcall SKILLDESC_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98C), nSkillLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98D), nSkillLevel);
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, nAdd, pSkill, 0x80, 0, 0, pUnit, nBonus);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    if (pSkillsTxt->nSrcDam != 0x80)
    {
        const int nSrcDam = pSkillsTxt->nSrcDam;
        nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
        nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    }

    nMin += SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMax += SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}

// 0x004EBA30
void __fastcall SKILLDESC_DrawKickDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nColor = 0;
    const int nSkillId = pSkillsTxt->nSkillId;
    const int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    const int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    int nBonus = SKILLDESC_SumProgressiveBonus();
    nBonus += SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel);
    if (nBonus)
    {
        nColor = 3;
    }

    int nKickMin = 0;
    int nKickMax = 0;
    int nPercent = nBonus;
    SKILLS_CalculateKickDamage(pUnit, &nKickMin, &nKickMax, &nPercent);
    nKickMin += nMin + DATATBLS_ApplyRatio(nKickMin, nPercent, 100) + DATATBLS_ApplyRatio(nMin, nBonus, 100);
    nKickMax += nMax + DATATBLS_ApplyRatio(nKickMax, nPercent, 100) + DATATBLS_ApplyRatio(nMax, nBonus, 100);

    {
        int nElemMin = 0;
        int nElemMax = 0;
        SKILLDESC_AddProgressiveDamage(pUnit, &nElemMin, &nElemMax, &nColor);
        nKickMin += nElemMin;
        nKickMax += nElemMax;
    }
    SKILLDESC_DrawDamageRange(nKickMin, nKickMax, nColor, nY, nLeft, nRight);
}

// 0x004EBB50
void __fastcall SKILLDESC_DrawKickDamagePercent(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    const int nMinPhys = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    const int nMaxPhys = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    const int nBonus = SKILLDESC_SumProgressiveBonus();
    int nMin = 0;
    int nMax = 0;
    int nDamagePercent = nBonus;
    SKILLS_CalculateKickDamage(pUnit, &nMin, &nMax, &nDamagePercent);
    nMin += DATATBLS_ApplyRatio(nMin, nDamagePercent, 100) + nMinPhys + DATATBLS_ApplyRatio(nMinPhys, nBonus, 100);
    nMax += DATATBLS_ApplyRatio(nMax, nDamagePercent, 100) + nMaxPhys + DATATBLS_ApplyRatio(nMaxPhys, nBonus, 100);

    const int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    nMin += DATATBLS_ApplyRatio(nMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nMax, nPercent, 100);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pOther = 0;
        if (pWeapon)
        {
            int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
            pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
        }

        if (ITEMSIsA(pWeapon, 45) && ITEMS_CanBeEquipped(pWeapon) && STATLIST_GetOwner(pWeapon, 0))
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, 0);
        }
        else
        {
            pWeapon = 0;
        }

        if (pOther && pOther != pWeapon && ITEMSIsA(pOther, 45) && ITEMS_CanBeEquipped(pOther) && STATLIST_GetOwner(pOther, 0))
        {
            STATLIST_MergeStatLists(pUnit, pOther, 0);
        }

        sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
        if (pWeapon)
        {
            STATLIST_MergeStatLists(pUnit, pWeapon, 1);
        }
    }

    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}

// 0x004EBD50
void __fastcall SKILLDESC_DrawDescWeaponAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], nSkillId, nSkillLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], nSkillId, nSkillLevel);
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, nAdd, pSkill, 0x80, 0, 0, pUnit, nBonus);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);

    int nElemMin = 0;
    int nElemMax = 0;
    int nElemColor = 0;
    SKILLDESC_GetElemDamage(pUnit, &nElemMin, &nElemMax, &nElemColor, pSkillsTxt, nSkillLevel);

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nElemMin, nElemMax, nElemColor, nY, nLeft, nRight);
        return;
    }

    if (!nElemMin && !nElemMax)
    {
        SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
        return;
    }

    const int nWeaponMin = nMin;
    const int nWeaponMax = nMax;

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, gszFormatD, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nElemMin == nElemMax)
    {
        wsprintfA(szText, gszFormatD, nElemMin);
    }
    else if (nElemMin < 10000 && nElemMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nElemMin, nElemMax);
    }
    else if (nElemMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nElemMin + 500) / 1000, (nElemMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nElemMin, (nElemMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nColor, nElemColor);
}

static unsigned short sub_004E6F60_GetElemDamageText(int nElemType)
{
    switch (nElemType)
    {
    case 1:
        return 0x10A1;
    case 2:
        return 0x10A3;
    case 4:
        return 0x10A2;
    case 3:
        return 0x10C3;
    case 5:
        return 0x10A4;
    case 6:
        return 0xDC4;
    }
    return 0;
}

// 0x004EC140
static int __stdcall SKILLDESC_AddElemRange(Unicode* wszText, int nMin, unsigned short nString, int nMax, int nElemType)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nString)
    {
        nString = sub_004E6F60_GetElemDamageText(nElemType);
        if (!nString)
        {
            return 0;
        }
    }

    if ((nMin || nMax) && nMin != nMax)
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC220
static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(wszText, nMin >> 8, nString, nMax >> 8, pSkillsTxt->nEType);
}

// build: symbol ?SKILLDESC_AddElemRatePerSecond@* 0x004EC540
static int __stdcall SKILLDESC_AddElemRatePerSecond(unsigned short nString, int nMin, int nMax, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin == nMax)
    {
        wsprintfA(szNumber, gszFormatD, nMin);
    }
    else
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10E2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10BE));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC620
static int __stdcall SKILLDESC_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel)
{
    int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int* const pMax = &nMax;
    SKILLDESC_ApplyFireMasteryBonus(&nMin, pSkillsTxt, pMax);
    SKILLDESC_ApplyLightningMasteryBonus(&nMin, pMax, pSkillsTxt);
    const int nMinRate = nMin >> 8;
    const int nMaxRate = nMax >> 8;
    unsigned short nString;
    switch (MISSILE_GetElemTypeFromMissileId(nMissileId))
    {
    case 2:
        nString = 0x10A3;
        break;
    case 4:
        nString = 0x10A2;
        break;
    case 3:
        nString = 0x10C3;
        break;
    case 5:
        nString = 0x10A4;
        break;
    case 6:
        nString = 0xDC4;
        break;
    case 1:
        nString = 0x10A1;
        break;
    default:
        nString = 0x10A1;
        break;
    }

    return SKILLDESC_AddElemRatePerSecond(nString, nMinRate, nMaxRate, wszText);
}

static void __stdcall sub_004E6EA0_ApplyFireMastery(int* pMin, int* pMax, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 1)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nMastery)
        {
            const int nMin = *pMin;
            *pMin = DATATBLS_ApplyRatio(nMin, nMastery, 100) + nMin;
            const int nMax = *pMax;
            *pMax = DATATBLS_ApplyRatio(nMax, nMastery, 100) + nMax;
        }
    }
}

static void __stdcall sub_004E6F00_ApplyLightningMastery(int* pMin, int* pMax, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 2)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nMastery)
        {
            const int nMin = *pMin;
            *pMin = DATATBLS_ApplyRatio(nMin, nMastery, 100) + nMin;
            const int nMax = *pMax;
            *pMax = DATATBLS_ApplyRatio(nMax, nMastery, 100) + nMax;
        }
    }
}

// build: symbol ?SKILLDESC_AddSkillElemRate@* 0x004EC6F0
static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    return SKILLDESC_AddElemRatePerSecond(0x10A1, nMin, nMax, wszText);
}

// 0x004EC740
static int __stdcall SKILLDESC_AddSkillElemRateByType(Unicode* wszText, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    nMin = nMin * 0x19 >> 8;
    nMax = nMax * 0x19 >> 8;
    unsigned short nString;
    switch (pSkillsTxt->nEType)
    {
    case 2:
        nString = 0x10A3;
        break;
    case 4:
        nString = 0x10A2;
        break;
    case 3:
        nString = 0x10C3;
        break;
    case 5:
        nString = 0x10A4;
        break;
    case 6:
        nString = 0xDC4;
        break;
    case 1:
        nString = 0x10A1;
        break;
    default:
        nString = 0x10A1;
        break;
    }

    return SKILLDESC_AddElemRatePerSecond(nString, nMin, nMax, wszText);
}

int __fastcall sub_H14_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nLine, short nMissileId)
{
    switch (nLine)
    {
    case 1:
        SKILLDESC_AddMissileElemRate(pUnit, wszText, pSkillsTxt, nMissileId, nSkillLevel);
        return 1;
    case 2:
        SKILLDESC_AddSkillElemRate(pUnit, wszText, nSkillId, nSkillLevel);
        return 1;
    case 3:
        SKILLDESC_AddSkillElemRateByType(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
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

static __forceinline int ApplyPercent_CF0(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}

// 0x004ECCF0
static int __stdcall SKILLDESC_AddSummonDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, D2SkillsTxt* pSkillsTxt)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(pSkillsTxt->wSummon, GAME_GetLadderFlag(), GAME_GetDifficulty(), pMonStatsTxt->nLevel[GAME_GetDifficulty()], 8, &monStatsInit);
    int nMin = monStatsInit.nA1MinD;
    int nMax = monStatsInit.nA1MaxD;
    int nPercent = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxt->wAuraStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxt->nPassiveStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
    }

    if (nPercent)
    {
        if (nPercent <= -90)
        {
            nPercent = -90;
        }
        nMin += ApplyPercent_CF0(nMin, nPercent);
        nMax += ApplyPercent_CF0(nMax, nPercent);
    }

    SKILLDESC_AddElemRange(wszText, nMin, 0x10A0, nMax, 0);
    return 1;
}

static inline int ApplyPercent_2E0(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}

static inline int ApplyPercent_150(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}

static inline int IsSingleValue(int nMin, int nMax)
{
    if (!nMin)
    {
        return !nMax;
    }
    return nMin == nMax;
}

static int __stdcall sub_004E73E0_FormatValue(Unicode* pDest, int bPlus, int nValue)
{
    char szText[32];
    if (bPlus && nValue >= 0)
    {
// build: symbol ?gszFmtPlusD@* 0x006DBE90
        wsprintfA(szText, gszFmtPlusD, nValue);
    }
    else
    {
        wsprintfA(szText, gszFormatD, nValue);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

static int __stdcall sub_004E7430_FormatDecimal(Unicode* pDest, int bPlus, int nWhole, int nFraction)
{
    char szText[32];
    if (bPlus && nWhole >= 0)
    {
// build: symbol ?gszFmtPlusDecimal@* 0x006DBE9C
        wsprintfA(szText, gszFmtPlusDecimal, nWhole, nFraction);
    }
    else
    {
// build: symbol ?gszFmtDecimal@* 0x006DBE94
        wsprintfA(szText, gszFmtDecimal, nWhole, nFraction);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

static int __stdcall sub_004E7C30_AddValueTextAfter(unsigned short nString, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, gszFmtPlusD, nValue);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E7E70_AddValueTwoTexts(unsigned short nString1, unsigned short nString2, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, gszFmtPlusD, nValue);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString1));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E80F0_AddRangeText(Unicode* wszText, int bSeparator, int nMin, int nMax, unsigned short nString, int bPlus)
{
    if (nMin == nMax)
    {
        return SKILLDESC_AppendLabelValue(nString, bPlus, wszText, nMin);
    }

    Unicode wszNumber[32];
    char szNumber[32];
    if (bPlus)
    {
// build: symbol ?gszFmtPlusRange@* 0x006DBEA4
        wsprintfA(szNumber, gszFmtPlusRange, nMin, nMax);
    }
    else
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    if (bSeparator)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    }
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall SKILLDESC_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel)
{
    const int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    const int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(wszText, nMin, nString, nMax, MISSILE_GetElemTypeFromMissileId(nMissileId));
}

// 0x004ECF50
int __stdcall SKILLDESC_AddMonsterDamage(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nBonusMin, int nBonusMax)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    const int nDifficulty = GAME_GetDifficulty();
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    const int nMonsterId = sgptDataTables->nMonStatsTxtRecordCount <= 0x124 ? -1 : 0x124;
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxt->nLevel[nDifficulty], 8, &monStatsInit);
    const int nMin = monStatsInit.nA1MinD + nBonusMin;
    const int nMax = monStatsInit.nA1MaxD + nBonusMax;
    const int nElemType = pSkillsTxt->nEType;
    Unicode wszNumber[32];
    char szNumber[32];
    const unsigned short nString = sub_004E6F60_GetElemDamageText(nElemType);
    if (nString)
    {
        if ((nMin || nMax) && nMin != nMax)
        {
            wsprintfA(szNumber, gszFmtRange, nMin, nMax);
        }
        else
        {
            wsprintfA(szNumber, gszFormatD, nMin);
        }
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

int __fastcall sub_M346_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLine, short nMissileId)
{
    if (nLine == 7)
    {
        SKILLDESC_AddMissileElemRate(pUnit, wszText, pSkillsTxt, nMissileId, nSkillLevel);
        return 3;
    }
    return 5;
}

static inline D2SkillsTxt* GetSkillsRecord(D2DataTablesStrc* pTables, int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < pTables->nSkillsTxtRecordCount)
        return &pTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004ED480
int __stdcall SKILLDESC_HasClassSkill(D2UnitStrc* pUnit)
{
    int nSkillId = 0;
    if (gbHasClassSkill)
        return 1;
    D2DataTablesStrc* pTables = sgptDataTables;
    for (; nSkillId < pTables->nSkillsTxtRecordCount; ++nSkillId)
    {
        D2SkillsTxt* pRecord = GetSkillsRecord(pTables, nSkillId);
        if (pRecord && (unsigned char)pRecord->nCharClass == (unsigned char)GAME_GetUnitClassId(pUnit))
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0))
            {
                gbHasClassSkill = 1;
                return 1;
            }
            pTables = sgptDataTables;
        }
    }
    return 0;
}

// 0x004ED530
static inline int SKILLDESC_HasOnlyBonusLevels(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 1) && !SKILLS_GetSkillLevel(pUnit, pSkill, 0))
    {
        return 1;
    }
    return 0;
}

int __fastcall sub_M119_Emit_004ED530(D2UnitStrc* pUnit, int nSkillId)
{
    return SKILLDESC_HasOnlyBonusLevels(pUnit, nSkillId);
}

void __fastcall SKILLDESC_DrawWeaponDamageWithParam(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, 0, pSkill, 0, 0, 0, pUnit, 0);
    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xD40);
    D2SkillsTxt* pRecord = sub_I05_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pRecord ? 0 : pRecord->dwParam[4];
    nMin += nParam * nMin / 100;
    nMax += nParam * nMax / 100;
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

static unsigned short sub_004E6E30_GetSkillDescAltStr(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    if (pSkillsTxtRecord)
    {
        const int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        pSkillDescTxtRecord = (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount) ? &sgptDataTables->pSkillDescTxt[nSkillDesc] : 0;
    }
    if (!pSkillDescTxtRecord) return 0x1506;
    return pSkillDescTxtRecord->wStrAlt;
}

static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    Unicode wszText[32];
    char szText[32];
    wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (nValue < 1000) D2Win_10127_SetFont(1);
    else D2Win_10127_SetFont(0); // 0x00502EF0
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + nY - 480, gnPanelOffsetX + nRight, wszText, nColor);
}

// 0x004ED570
void __fastcall SKILLDESC_DrawSkillPanel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot)
{
    int nValue1, nValue2, nColor1, nColor2;
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt) return;
    int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile_006DBF24, 0x1588);
    D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pDesc) return;
    D2Win_10127_SetFont(6);
    Unicode wszName[32];
    sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(sub_004E6E30_GetSkillDescAltStr(nSkillId)));
    GAME_StrToUpper(wszName);
    int nIndex = nSlot;
    DRAW_SKILL_TEXT(nIndex, wszName);
    int bDamage = 0;
    int bDescription = 0;
    switch (sub_004D9FC0(pUnit, pSkill))
    {
    case 0: case 1: case 6: case 8:
        bDamage = 1;
        bDescription = 1;
        break;
    }
    if (pDesc->wDescDam >= 144 || !gpfnSkillDamageFuncs[pDesc->wDescDam]) bDamage = 0;
    if (pDesc->wDescFunc >= 72 || !gpfnSkillDescFuncs[pDesc->wDescFunc]) bDescription = 0;
    ++nIndex;
    if (bDamage)
        DRAW_SKILL_TEXT(nIndex, D2LANG_GetStringFromTblIndex(0xFDD));
    ++nIndex;
    if (bDamage)
        gpfnSkillDamageFuncs[pDesc->wDescDam](pUnit, pSkill, pSkillsTxt, nLevel, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight);
    if (!bDescription)
        return;
    Unicode wszDescription[200];
    nValue1 = 0;
    nValue2 = 0;
    nColor1 = 0;
    nColor2 = 0;
    gpfnSkillDescFuncs[pDesc->wDescFunc](pUnit, pSkill, pSkillsTxt, nLevel, &nValue1, &nColor1, &nValue2, &nColor2);
    ++nIndex;
    if (nValue1 || nValue2)
    {
        D2Win_10127_SetFont(6);
        if (nSkillId)
            sub_005269D0(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFDF), wszName);
        else
            sub_005269D0(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFE1), wszName);
        wszDescription[199].wChar = 0;
        Unicode* pNext;
        if (TEXT_SplitAtNewline(wszDescription, &pNext))
        {
            TEXT_DrawCenteredText(TP[nIndex].nLeft + gnPanelOffsetX, gnPanelOffsetY + gnScreenHeight + TP[nIndex].nY - 484, TP[nIndex].nRight + gnPanelOffsetX, wszDescription, 0);
            TEXT_DrawCenteredText(TP[nIndex].nLeft + gnPanelOffsetX, gnPanelOffsetY + gnScreenHeight + TP[nIndex].nY - 476, TP[nIndex].nRight + gnPanelOffsetX, pNext, 0);
        }
        else
            DRAW_SKILL_TEXT(nIndex, wszName);
    }
    nIndex += 2;
    if (nValue2)
    {
        Unicode wszValue1[32];
        Unicode wszValue2[32];
        char szValue[32];
        wsprintfA(szValue, gszFormatD, nValue1);
        sub_00526320_ToUnicode(wszValue1, szValue, 32);
        wsprintfA(szValue, gszFormatD, nValue2);
        sub_00526320_ToUnicode(wszValue2, szValue, 32);
        SKILLDESC_DrawTwoTexts(wszValue1, wszValue2, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight, nColor1, nColor2);
    }
    else if (nValue1)
        sub_004E9940_DrawNumberCentered(nColor1, TP[nIndex].nLeft, TP[nIndex].nY, TP[nIndex].nRight, nValue1);
}

static inline unsigned int SEED_RollRandomNumber_Spray(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Spray(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static inline int CLIENTS_GetUnitX_Spray(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitY_Spray(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    default:
        if (pUnit->pDynamicPath)
            nResult = PATH_GetYPosition(pUnit->pDynamicPath);
        else
            nResult = 0;
        break;
    }
    return nResult;
}

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

struct D2RequestStrc;

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

void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pPath, int bClear); // 0x00649030

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

// 0x004F16F0
int __fastcall SKILLDESC_CreateMissileVolley(D2UnitStrc* pUnit, int nCount, int nArg0, int nArg3, int nArg4, int nMissileArg, int bFirst, int bClearPathFlag)
{
    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (bFirst)
    {
        --nCount;
        D2UnitStrc* pMissile = sub_004C5420_CreateFirstMissile(pUnit, nArg0, nArg3, nArg4);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x21;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = UNITS_GetXPositionInline(pUnit);
    tRequest.nArg2 = UNITS_GetYPositionInline(pUnit);
    tRequest.nArg5 = nTargetX;
    tRequest.nArg6 = nTargetY;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    tRequest.pfCallback = SKILLDESC_InitCappedChargedPath;
    if (bClearPathFlag)
    {
        tRequest.nType |= 0x2000;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tRequest.nIndex = i;
        D2UnitStrc* pMissile = sub_004CD540_HandleRequest(&tRequest);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
            }

            sub_00621780_SetMissileArg(pMissile, nMissileArg);
        }
    }

    return 1;
}



static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
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

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x004F23E0
int __fastcall SKILLDESC_IsAuraStateOff(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        return !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState);
    }

    return 0;
}

// 0x004F2440
void __fastcall SKILLDESC_ToggleStateOff(D2UnitStrc* pUnit, int nState, int nSkillLevel)
{
    STATES_ToggleState(pUnit, nState, 0);
}

// 0x004F2870
int __fastcall SKILLDESC_IsTargetPlayerOrMonster(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType == UNIT_MONSTER || pTarget->dwUnitType == UNIT_PLAYER)
    {
        return 1;
    }

    return 0;
}

// 0x004F28A0
void __fastcall SKILLDESC_MissileScatter(D2UnitStrc* pUnit, int nSeed, int nMissile, int nX, int nY, int nRadius, int nSkillId, int nSkillLevel)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nSeed);

    const int nRadiusSq = nRadius * nRadius;
    const int nRange = 2 * nRadius;

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 1;
    tMissile.pOwner = pUnit;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    for (int i = 0; i < nRadiusSq; ++i)
    {
        const int nOffsetX = nRadius - SEED_RollLimitedRandomNumberInline(&tSeed, nRange);
        const int nOffsetY = nRadius - SEED_RollLimitedRandomNumberInline(&tSeed, nRange);
        if (nOffsetX * nOffsetX + nOffsetY * nOffsetY <= nRadiusSq)
        {
            tMissile.nX = nX + nOffsetX;
            tMissile.nY = nY + nOffsetY;
            if (sub_00463740_FindRoomAtPoint(pRoom, tMissile.nX, tMissile.nY))
            {
                MISSILE_CreateClientMissile(&tMissile);
            }
        }
    }
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

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->nXPos;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->nYPos;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x004F2AC0
void __fastcall SKILLDESC_MissileInit(D2UnitStrc* pMissile, int nSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 0x4E)
    {
        nFrames = 0x4D;
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }

    D2DynamicPathStrc* pDynamicPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, nSeed);
    PATH_SetType(pDynamicPath, 10);
    PATH_SetNewDistance(pDynamicPath, nFrames);
    D2Common_10142(pDynamicPath, pMissile, 0);
}


// 0x004F2BE0
void __fastcall SKILLDESC_InitCurvingMissilePath(D2UnitStrc* pMissile, int nInitSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 78)
    {
        nFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2SeedStrc* const pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, nInitSeed);
    PATH_SetType(pPath, 10);
    PATH_SetNewDistance(pPath, nFrames);

    D2PathPointStrc* pPathPoints;
    PATH_GetPathPoints(pPath, &pPathPoints);

    int nX = CLIENTS_GetUnitXInline(pMissile);
    int nY = CLIENTS_GetUnitYInline(pMissile);
    int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pMissile, D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath));

    D2SeedStrc tSeed;
    int nSign = (SEED_RollFromInline(pSeed, &tSeed) & 1) ? 1 : -1;
    const unsigned int nRoll = SEED_RollLowInline(&tSeed);
    pSeed->nHighSeed = tSeed.nHighSeed;
    pSeed->nLowSeed = tSeed.nLowSeed;
    // volatile: the original reads the turn base from memory inside each sum
    int nStep = nRoll % 3 + *(volatile int*)&gnChargedBoltTurnBase;
    for (int i = 0; i < nFrames; ++i)
    {
        nDirection += nSign * nStep;
        const unsigned char nIndex = INVENTORY_GetEightWayDirection(nDirection & 63);
        nX += gaCurvingPathOffsetX[nIndex];
        nY += gaCurvingPathOffsetY[nIndex];
        pPathPoints[i].X = nX;
        pPathPoints[i].Y = nY;

        if (!(i % gnChargedBoltTurnEvery))
        {
            nSign = -nSign;
            nStep = SEED_RollRandomNumber(pSeed) % 3 + *(volatile int*)&gnChargedBoltTurnBase;
        }
    }

    PATH_SetNumberOfPathPoints(pPath, nFrames);
}

int __fastcall sub_leg345d_Emit_004ECCF0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel)
{
    SKILLDESC_AddSummonDamage(pUnit, wszText, nSkillId, nSkillLevel, pSkillsTxt);
    return 1;
}

static inline D2SkillsTxt* SkillsTxtRecord_0D0(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int SkillParam_0D0(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxt = SkillsTxtRecord_0D0(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }
    return pSkillsTxt->dwParam[0] + (nLevel - 1) * pSkillsTxt->dwParam[1];
}

// build: symbol ?SKILLDESC_AddSummonDamageBonus@* 0x004ED150
int __stdcall SKILLDESC_AddSummonDamageBonus(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(pSkillsTxt->wSummon, GAME_GetLadderFlag(), GAME_GetDifficulty(), pMonStatsTxt->nLevel[GAME_GetDifficulty()], 8, &monStatsInit);
    int nMin = monStatsInit.nA1MinD;
    int nMax = monStatsInit.nA1MaxD;
    int nPercent = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxt->wAuraStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
        if (pSkillsTxt->wAuraStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            nMin += nDamage;
            nMax += nDamage;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxt->nPassiveStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
        if (pSkillsTxt->nPassiveStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
            nMin += nDamage;
            nMax += nDamage;
        }
    }

    if (nPercent)
    {
        if (nPercent <= -90)
        {
            nPercent = -90;
        }
        nMin += ApplyPercent_150(nMin, nPercent);
        nMax += ApplyPercent_150(nMax, nPercent);
    }

    SKILLDESC_AddElemRange(wszText, nMin, 0x10A0, nMax, 0);
    return 1;
}

// build: symbol ?SKILLDESC_AddElemDuration@* 0x004EDC40
static int __stdcall SKILLDESC_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId, D2UnitStrc* pUnit)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    if (nLength)
    {
        switch (pSkillsTxt->nEType)
        {
        case 5:
            return SKILLDESC_AddSeconds(0x10AA, 0, nLength, wszText);
        case 4:
            return SKILLDESC_AddSeconds(0x10A9, 0, nLength, wszText);
        }
    }
    return 0;
}

static int __stdcall sub_004EDCA0_AddElemDamageOverTime(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    SKILLDESC_AddSeconds(0x2B0E, 0, nLength, wszText);
    const int nElemType = pSkillsTxt->nEType;
    Unicode wszNumber[32];
    char szNumber[32];
    const unsigned short nString = sub_004E6F60_GetElemDamageText(nElemType);
    if (nString)
    {
        if (IsSingleValue(nMin, nMax))
        {
            wsprintfA(szNumber, gszFormatD, nMin);
        }
        else
        {
            wsprintfA(szNumber, gszFmtRange, nMin, nMax);
        }
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

static int __stdcall sub_004EDDD0_AddAttackInfo(Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, D2UnitStrc* pUnit)
{
    if (GAME_IsExpansion())
    {
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, 0, 0, nSkillLevel);
        SKILLDESC_AddToHit(nSkillLevel, nSkillId, pUnit, wszText);
        return 1;
    }

    int nMin = 0;
    int nMax = 0;
    int nType;
    SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nType, pSkillsTxt, nSkillLevel);
    sub_004E80F0_AddRangeText(wszText, 0, nMin, nMax, 0x10A0, 0);
    return 1;
}

int __fastcall sub_D06_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nArg4, int nLine, int nArg5)
{
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
    {
        return 0;
    }

    const int nCalcA = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcA[nLine], nSkillId, nSkillLevel);
    const int nCalcB = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcB[nLine], nSkillId, nSkillLevel);
    const unsigned short nStringA = pSkillDescTxt->wDescTextA[nLine];
    const unsigned short nStringB = pSkillDescTxt->wDescTextB[nLine];
    switch (pSkillDescTxt->nDescLine[nLine])
    {
    case 1:
        SKILLDESC_AddSummonLife(wszText, nCalcA, nCalcB, pSkillsTxt->wSummon);
        return 1;
    case 2:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddElemRange(wszText, nCalcA, nStringA, nCalcB, pSkillsTxt->nEType);
        return 1;
    case 3:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        return 1;
    case 4:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        return 1;
    case 5:
        SKILLDESC_AddMissileElemDamage(pUnit, wszText, nStringA, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        return 1;
    case 6:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, nCalcB, nCalcA, nSkillLevel);
        return 1;
    case 7:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddToHit(nSkillLevel, nSkillId, pUnit, wszText);
        return 1;
    case 8:
        SKILLDESC_AddMissileElemRate(pUnit, wszText, pSkillsTxt, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        return 1;
    case 9:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemRate(pUnit, wszText, nSkillId, nSkillLevel);
        return 1;
    case 10:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemRateByType(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
        return 1;
    case 11:
        SKILLDESC_AddValueLine(nStringB, 1, 1, nCalcA, nStringA, wszText);
        return 1;
    case 12:
        SKILLDESC_AddValueLine(nStringB, 1, 0, nCalcA, nStringA, wszText);
        return 1;
    case 13:
        SKILLDESC_AddDecimalLine(nStringB, 1, 0, nCalcA, nCalcB, nStringA, wszText);
        return 1;
    case 14:
        SKILLDESC_AddValueOverTime(nStringB, nCalcA, 1, nCalcB, nStringA, wszText);
        return 1;
    case 15:
        SKILLDESC_AddTextPair(nStringA, nStringB, wszText);
        return 1;
    case 16:
        SKILLDESC_AddValueAfterText(nStringB, 0, 0, nCalcA, nStringA, wszText);
        return 1;
    case 17:
        SKILLDESC_AddFormattedText(nCalcA, nStringA, wszText);
        return 1;
    case 18:
        SKILLDESC_AddSummonDamage(pUnit, wszText, nSkillId, nSkillLevel, pSkillsTxt);
        return 1;
    case 19:
        SKILLDESC_AddMonsterDamage(wszText, pSkillsTxt, nCalcA, nCalcB);
        return 1;
    case 20:
        SKILLDESC_AddNextLevelParam(nSkillLevel, nSkillId, wszText);
        return 1;
    case 21:
        SKILLDESC_AddSummonDamageBonus(pUnit, wszText, nSkillId, pSkillsTxt, nSkillLevel);
        return 1;
    case 22:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSeconds(nStringA, 0, nCalcA, wszText);
        return 1;
    case 23:
        SKILLDESC_AddSeconds(nStringA, 1, nCalcA, wszText);
        return 1;
    case 24:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        return 1;
    case 25:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }

        return 1;
    case 26:
        sub_004EDDD0_AddAttackInfo(wszText, nSkillId, pSkillsTxt, nSkillLevel, pUnit);
        return 1;
    case 27:
        sub_004E7E70_AddValueTwoTexts(nStringA, nStringB, 1, nCalcA, wszText);
        return 1;
    case 28:
        SKILLDESC_AppendLabelValue(nStringA, 1, wszText, nCalcA);
        return 1;
    case 29:
        sub_004E7C30_AddValueTextAfter(nStringA, 1, nCalcA, wszText);
        return 1;
    case 30:
        sub_004E80F0_AddRangeText(wszText, 1, nCalcA, nCalcB, nStringA, 1);
        return 1;
    }
    return 0;
}

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId); // 0x004F4110

int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit); // 0x00623C60

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F4A30
int __fastcall SKILLDESC_CltDoChargedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nCharges = SKILLS_GetParam1(pSkill);
    if (nCharges <= 0)
    {
        return 0;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    const int nUnitGUID = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = CUNIT_FindClientUnit(nUnitGUID, SKILLS_GetParam2(pSkill));
    if (!pTarget)
    {
        pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 3, nUnitGUID, 0);
    }

    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }

    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wCltMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxtRecord->wCltMissileB >= 0)
    {
        nMissileId = pSkillsTxtRecord->wCltMissileB;
    }

    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissileId;
    tMissileParams.nTargetX = nTargetX;
    tMissileParams.nTargetY = nTargetY;
    MISSILE_CreateClientMissile(&tMissileParams);

    --nCharges;
    SKILLS_SetParam1(pSkill, nCharges);
    if (nCharges > 0)
    {
        D2UnitStrc* pNext = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 3, pTarget ? pTarget->dwUnitId : -1, 0);
        if (!pNext)
        {
            return 0;
        }

        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pNext), CLIENTS_GetUnitY(pNext), 0);
        int nUnitType = -1;
        if (pNext)
        {
            nUnitType = pNext->dwUnitType;
        }
        SKILLS_SetParam2(pSkill, nUnitType);
        int nNextGUID;
        if (!pNext)
        {
            nNextGUID = -1;
        }
        else
        {
            nNextGUID = pNext->dwUnitId;
        }
        SKILLS_SetParam3(pSkill, nNextGUID);
        SKILLS_ScaleFramePrecise(pUnit, SKILLDESC_GetSkillParamSix(nSkillId));
    }

    return 1;
}



static D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline_J03(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int MONSTERS_GetBaseIdInline_J03(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline_J03(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nMonsterId;
}


#include "gen/data/Source/D2Client/UI/SkillDesc.inc"
