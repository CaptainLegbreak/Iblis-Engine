#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
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
#include "D2LevelTxt.h"
#include "D2CommonApi2.h"

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





void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0





void __fastcall sub_004BA840_StopSound(int nHandle); // 0x004BA840

int __fastcall sub_004E40A0_RollPlayerSeed(int nRange); // 0x004E40A0

extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100

static void SKILLDESC_AddEnvironSoundRefs(int nIndex); // 0x004E4240


extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80


extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0


void __fastcall TEXT_AppendUndeadDamageBonus(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused); // 0x004E48B0




Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0










extern int gnTextOffset1; // 0x0072D8D4
extern int gnTextOffset2; // 0x0072D8D0
extern char gbTextOffsetInit; // 0x007C8C9C
extern char gbSkillRefreshInit; // 0x007C8CA4
extern D2CombinedStatIdStrc gaCombinedStatIds[]; // 0x0072CDD0

extern D2FileIndexTextStrc gaFileIndexText[]; // 0x0072D6C0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static int __stdcall SKILLDESC_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId); // 0x004E4C50





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

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520


void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870








typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem);





int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360




int __fastcall SKILLDESC_WeaponDamageCallback(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004E9610



struct D2SkillDescTxt;

struct D2UnitStrc;

struct D2DataTablesStrc;

extern "C" const char gszFmtRangeKK[]; // 0x006DBEAC

extern "C" const char gszFmtRangeK[]; // 0x006DBEB8


int __stdcall SKILLDESC_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor); // 0x004E7120




static void __fastcall SKILLDESC_DrawDamageRange(int nMin, int nMax, int nColor, int nY, int nLeft, int nRight); // 0x004E96E0

int __fastcall GAME_GetUnitClassId(D2UnitStrc*); // 0x00451F60



int __stdcall SKILLDESC_AddElemRange(Unicode* wszText, int nMin, unsigned short nString, int nMax, int nElemType); // 0x004EC140

static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel); // 0x004EC220

static void __stdcall SKILLDESC_DrawWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, SKILLWEAPONFN pfnEvaluate, int nBonus, int nAdd, int nLeft, int nY, int nRight, int bElemDamage);

void __fastcall SKILLDESC_DrawDualWieldLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA170

void __fastcall SKILLDESC_DrawDualWieldLineNoElem(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA240
void __fastcall SKILLDESC_DrawWeaponDamageWithParam(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EB940

void __fastcall SKILLDESC_DrawWeaponDamageLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawWeaponStatDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawOtherHandDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

void __fastcall SKILLDESC_DrawSkillWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

int gbHasClassSkill; // 0x007C8CA0

#include "D2Client.h"
#include "D2MonsterIds.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"

extern "C" __declspec(dllimport)
int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468


static int __stdcall sub_004E86F0_GetWeaponDamage(int*, int*, int*, int, D2SkillStrc*, int, D2UnitStrc*, int, D2UnitStrc*, int); // 0x004E86F0


extern const D2ElemDamageStatsStrc gaElemDamageStats[4];                                          // 0x006DBEF4

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillTextPositionStrc { int nLeft, nY, nRight; };

typedef void (__fastcall* SKILLDAMAGEFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int, int, int);

typedef void (__fastcall* SKILLDESCFN)(D2UnitStrc*, D2SkillStrc*, D2SkillsTxt*, int, int*, int*, int*, int*);

extern SKILLDAMAGEFN gpfnSkillDamageFuncs[]; // 0x0072D768

extern SKILLDESCFN gpfnSkillDescFuncs[]; // 0x0072D7F8

extern D2SkillTextPositionStrc gaSkillTextPositions[]; // 0x0072D840

extern "C" const char gszFormatD[]; // 0x006D57BC

extern const char gszSkillDescFile[]; // 0x006DBF24

void __fastcall GAME_StrToUpper(Unicode*); // 0x00452180

int __fastcall TEXT_SplitAtNewline(Unicode*, Unicode**); // 0x004A7660

extern "C" int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc*, D2SkillStrc*); // 0x004D9FC0

static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue); // 0x004E9940

#define TP gaSkillTextPositions

#define DRAW_SKILL_TEXT(i, text) TEXT_DrawCenteredText(TP[i].nLeft + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY + TP[i].nY - 480, TP[i].nRight + gnPanelOffsetX, text, 0)

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2MissileStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390




D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540





void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern const unsigned char gbSkillFlagMask_006CE270; // 0x006CE270

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

extern int gnChargedBoltTurnEvery; // 0x0072D98C

extern int gnChargedBoltTurnBase; // 0x0072D990

extern const int gaCurvingPathOffsetY[]; // 0x006DC1E8

extern const int gaCurvingPathOffsetX[]; // 0x006DC208

int __stdcall SKILLDESC_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel); // 0x004EC280

static int __stdcall SKILLDESC_EvaluateForEachWeapon(int* pValue1, int* pValue2, int* pColor1, int* pValue3, int* pValue4, int* pColor2, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nBonus, D2UnitStrc* pUnit, int nAdd);

void __fastcall SKILLDESC_DrawWeaponAndSkillDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight);

static int SKILLDESC_AppendSkillDescStrLong(Unicode* wszOut, int nSkillId);



// noinline: the original calls this; without it the compiler expands it into 0x004E7A90.
__declspec(noinline) static int __stdcall SKILLDESC_FormatSignedInt(Unicode* wszText, int bPrefixSign, int nValue);

// noinline: the original calls this; without it the compiler expands it into 0x004E7A90, 0x004E85C0.
__declspec(noinline) static int __stdcall SKILLDESC_FormatSignedDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction);

static int SKILLDESC_FormatIntOrDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction);

static unsigned short SKILLDESC_GetSkillDescStrLong(int nSkillId);

static void __stdcall SKILLDESC_ApplyFireMasteryBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2); // 0x004E6EA0

static void __stdcall SKILLDESC_ApplyLightningMasteryBonus(int* pValue1, int* pValue2, D2SkillsTxt* pSkillsTxt); // 0x004E6F00

static unsigned short SKILLDESC_GetETypeDamageStr(int nEType);

static int SKILLDESC_GetETypeColor(int nEType); // 0x004E6FB0

static int __stdcall SKILLDESC_AppendFrameRange(Unicode* wszOut, unsigned short wStr, int nMinFrames, int nMaxFrames); // 0x004E7650

static int __stdcall SKILLDESC_AppendScaledRange(Unicode* wszOut, unsigned short wStr1, unsigned short wStr2, int nMaxValue, int nMultiplier, int nMinValue); // 0x004E77A0

static int __stdcall SKILLDESC_AppendFormattedValue(Unicode* wszOut, int nValue, unsigned short wStr); // 0x004E7930

static int __stdcall SKILLDESC_AppendLabelValue(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign); // 0x004E79E0

static int __stdcall SKILLDESC_AppendScaledValue(unsigned short wStr1, unsigned short wStr2, int nMultiplier, Unicode* wszOut, int bPrefixSign, int nValue); // 0x004E7A90

static int __stdcall SKILLDESC_AppendLabelDecimal(unsigned short wStr, Unicode* wszOut, int bPrefixSign, int nValue, int nFraction);

static int __stdcall SKILLDESC_AppendValueLabel(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign); // 0x004E7C30

static int __stdcall SKILLDESC_AppendValueTwoLabels(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E7CE0

static int __stdcall SKILLDESC_AppendValueCountLabel(int nStr1, int nStr2, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E7DB0

static int __stdcall SKILLDESC_AppendLabelValueLabel(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E7E70

static int __stdcall SKILLDESC_AppendLabelRangeLabel(unsigned short wStr1, unsigned short wStr2, Unicode* wszOut, int bPrefixSign, int nMin, int nMax); // 0x004E7F40

static int __stdcall SKILLDESC_AppendLabelsRange(Unicode* wszOut, int bPrefixSign, unsigned short wStr1, unsigned short wStr2, int nMin, int nMax); // 0x004E8020

static int __stdcall SKILLDESC_AppendLabelRange(unsigned short wStr, Unicode* wszOut, int bSeparator, int nMin, int nMax, int bPrefixSign); // 0x004E80F0

static int __stdcall SKILLDESC_AppendLabelValueLabels(unsigned short wStr1, unsigned short wStr2, unsigned short wStr3, int bPrefixSign, Unicode* wszOut, int nValue); // 0x004E81C0

static int __stdcall SKILLDESC_AppendManaValue(int nValue, Unicode* wszOut);

static void SKILLDESC_AddElementalStatDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, unsigned char nType); // 0x004E8D90

static int __stdcall SKILLDESC_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill);

static D2UnitStrc* SKILLDESC_MergeOtherHandWeapon(D2UnitStrc* pUnit); // 0x004E9260

static int __stdcall SKILLDESC_AttackRatingForEachWeapon(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pValue3, int* pValue4, D2SkillStrc* pSkill, int nLevel);

void __fastcall SKILLDESC_DescAttackRating(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4);

void __fastcall SKILLDESC_DescAttackRatingOffhand(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4);

static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nRatio, D2SkillStrc* pSkill, D2UnitStrc* pItem); // 0x004E9660

void __fastcall sub_004EA4A0(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, int nBonus, int nAdd, int nParam, int nSrcDam, int nItem); // 0x004EA4A0

extern const char gszFmtOne_006D57BC[]; // 0x006D57BC

int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0



D2UnitStrc* sub_004E9300_MergeWeaponPair(D2UnitStrc* pUnit); // 0x004E9300


int __fastcall GAME_GetLadderFlag(); // 0x0044DCA0

static int __stdcall SKILLDESC_AddSummonDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, D2SkillsTxt* pSkillsTxt); // 0x004ECCF0

static int __stdcall SKILLDESC_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel);


short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem);

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem);


















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




static inline D2SkillsTxt* sub_004F21B0_GetSkillsTxtRecord(int nSkillId)
{
	if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
	{
		return &sgptDataTables->pSkillsTxt[nSkillId];
	}
	return 0;
}



struct D2ElemDamageStatsStrc;

extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC




struct D2MissilesTxt;


void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

int __fastcall SPELLSEL_GetSkillMaxLevel(int); // 0x004AA8B0

void __fastcall sub_004521C0_SetTextColor(Unicode*,int); // 0x004521C0

Unicode* __fastcall INV_PrefixColorCode(Unicode*, int); // 0x004521C0

void* __cdecl sub_00681EF0_Memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern const int gaLobVelocityBonus[5]; // 0x006DBF38




void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
void __fastcall SKILLDESC_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EA010
void __fastcall SKILLDESC_ThrowDamageCallback(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem); // 0x004EA4A0
void __fastcall SKILLDESC_DrawThrowAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EAAA0
static void __stdcall SKILLDESC_AddSummonLife(Unicode* wszText, int nMonsterId, int nPercent, int nBonus); // 0x004EC090
static int __stdcall SKILLDESC_AddPhysDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nBonus, int nSkillLevel, int nPercent); // 0x004EC2E0
static int SKILLDESC_AddToHit(Unicode* wszText, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004EC510
static int __stdcall SKILLDESC_AddElemRatePerSecond(unsigned short nString, Unicode* wszText, int nMin, int nMax); // 0x004EC540
static int __stdcall SKILLDESC_AddValueLine(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nValue); // 0x004EC7E0
static int __stdcall SKILLDESC_AddDecimalLine(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nWhole, int nFraction); // 0x004EC900
static int __stdcall SKILLDESC_AddValueOverTime(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int nValue, int bPlus, int nCount); // 0x004ECA00
static int SKILLDESC_AddTextPair(Unicode* wszText, unsigned short nString1, unsigned short nString2); // 0x004ECB10
static int __stdcall SKILLDESC_AddValueAfterText(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nValue); // 0x004ECB80
static int __stdcall SKILLDESC_AddFormattedText(Unicode* wszText, int nValue, unsigned short nString); // 0x004ECC80
static int SKILLDESC_AddNextLevelParam(int nSkillId, int nSkillLevel, Unicode* wszText); // 0x004ED0D0
static int __stdcall SKILLDESC_AddSeconds(int nFrames, unsigned short nString, int bPlus, Unicode* wszText); // 0x004EDB30
static int SKILLDESC_AddSecondsPlus(unsigned short nString, int nFrames, Unicode* wszText); // 0x004EDC30
static int __stdcall SKILLDESC_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004EDC40
int __fastcall SKILLDESC_CltDoLobMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004EFDF0
int __fastcall SKILLDESC_CltDoLaunchMissileAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004F0050

static int __stdcall sub_004EDDD0_AddAttackInfo(Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillLevel); // 0x004EDDD0


void __fastcall NPCMENU_ClearUnicode(Unicode* pChar);                                                  // 0x0042F530

void __stdcall sub_00403040_VectorConstructor(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnConstructor)(Unicode*)); // 0x00403040








#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2GfxLightStrc;

struct D2MonStats2Txt;

extern const unsigned int gdwBitMasks[32]; // 0x006CE268


int __fastcall SKILLDESC_AddSkillLine(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nManaValue, int nLine, int nLevelBonus); // 0x004EDEA0


int __stdcall SKILLDESC_FormatSignedInt(Unicode* wszText, int bPrefixSign, int nValue); // 0x004E73E0

int __stdcall SKILLDESC_FormatSignedDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction); // 0x004E7430
static void __stdcall SKILLDESC_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel); // 0x004E72D0


#define LEVELV (*(volatile int*)&nSkillLevel)
void __fastcall SKILLDESC_DrawPhysWeaponElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EAE70
static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel); // 0x004EC6F0
int __stdcall SKILLDESC_AddSummonDamageBonus(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel); // 0x004ED150

// 0x004E4200
float __cdecl SKILLDESC_GetFloatIfEnabled()
{
    if (!sub_00473C40())
    {
        return 0.0f;
    }

    return sub_00473C80();
}


// 0x004E4220
void __cdecl SKILLDESC_ClearEnvironSoundRefs()
{
    for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
    {
        SOUNDHDR_ClearVariantRefs(nId);
    }
}


// 0x004E4240
static void SKILLDESC_AddEnvironSoundRefs(int nIndex)
{
    int nId = nIndex * 4 + 0xA9C;
    for (int i = 3; i; --i)
    {
        SOUNDHDR_AddVariantRefs(nId, 1);
        SOUNDHDR_AddVariantRefs(nId + 0x18, 1);
        nId += 0x30;
    }
}

// 0x004E4280
extern "C" void __cdecl sub_004E4280_ResetEnvironSounds()
{
    gnEnvironLevelId = 0;
    gnEnvironAmbientId = 0;
    gnAmbientDelay = 0;
    gnAmbientTick = 0;
    if (gnEnvironSoundHandle)
    {
        sub_004BA840_StopSound(gnEnvironSoundHandle);
        gnEnvironSoundHandle = 0;
    }

    gnEnvironSoundId = 0;
    if (gnWeatherSoundHandle)
    {
        sub_004BA840_StopSound(gnWeatherSoundHandle);
        gnWeatherSoundHandle = 0;
    }

    gnWeatherSoundId = 0;
}

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

        sub_00472C50_StartLightning(0);
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
int __fastcall sub_004E4180_GetCyclicDistance(int nFrame, int nOffset, int nStepLength)
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


// 0x004E41E0
int __cdecl SKILLDESC_IsOutsideDayCycle()
{
    const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct);
    return nCycle < 1 || nCycle > 3;
}

// 0x004E42E0
void __fastcall SKILLDESC_UpdateEnvironSounds(unsigned int dwTick)
{
    if (!sub_004DF870_IsSoundSystemInit())
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
    const int nEnviron = UNITMODE_GetPlayerSoundEnviron();
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
            const int nCurrent = sub_004B9B20_GetValue(gnWeatherSoundHandle);
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
                sub_004BA840_StopSound(gnWeatherSoundHandle);
                gnWeatherSoundHandle = 0;
            }
        }
        gnWeatherSoundId = nSecond;
    }
    else
    {
        sub_004BA840_StopSound(gnWeatherSoundHandle);
        gnWeatherSoundHandle = 0;
        gnWeatherSoundId = 0;
    }
    GFXUTIL_ApplySoundEnviron(nEnviron);
    if (nAmbient)
    {
        if (nAmbient != gnEnvironAmbientId)
        {
            gnAmbientDelay = sub_004E4120(pEnv->nEventDelay / 3) + pEnv->nEventDelay;
            gnAmbientTick = dwTick - sub_004E40A0_RollPlayerSeed(gnAmbientDelay);
            gnEnvironAmbientId = nAmbient;
        }
        if (dwTick - gnAmbientTick >= gnAmbientDelay)
        {
            const int nHandle = sub_004B9A00(gnEnvironAmbientId, 0, 0, 0, 0);
            if (nHandle)
            {
                const int nSign = sub_004E40A0_RollPlayerSeed(2) ? 1 : -1;
                const int nPan = SKILLDESC_RandomInRange(0x1C2, 0x2EE) * nSign;
                const int nPanVolume = sub_004E4120(0x64);
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
            SOUNDHDR_ClearVariantRefs(nId);
        if (nEntryA)
            SKILLDESC_AddEnvironSoundRefs(nEntryA);
        if (nEntryB)
            SKILLDESC_AddEnvironSoundRefs(nEntryB);
        gnEnvironLevelId = nLevelId;
    }
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004E6C50
int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }
    return -1;
}

// 0x004E6C70
int __fastcall SKILLDESC_GetSkillParamFive(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4];
}

// 0x004E6CA0
int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel)
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

    return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
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


// 0x004E6D40
static unsigned short SKILLDESC_GetSkillDescStrName(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrName;
}

unsigned short __stdcall sub_M125_Emit_004E6D40(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return SKILLDESC_GetSkillDescStrName(nSkillId);
}

// 0x004E6D90
static unsigned short SKILLDESC_GetSkillDescStrShort(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrShort;
}

unsigned short __stdcall sub_M125_Emit_004E6D90(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return SKILLDESC_GetSkillDescStrShort(nSkillId);
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

// 0x004E6E30
static unsigned short sub_004E6E30_GetSkillDescAltStr(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    D2SkillDescTxt* pSkillDescTxtRecord = 0;
    if (pSkillsTxtRecord)
    {
        const int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        pSkillDescTxtRecord = (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount) ? &sgptDataTables->pSkillDescTxt[nSkillDesc] : 0;
    }

    if (!pSkillDescTxtRecord)
        return 0x1506;

    return pSkillDescTxtRecord->wStrAlt;
}

// 0x004E6E80
static int SKILLDESC_ApplyAiCurseDivisor(int nValue)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(GAME_GetDifficulty());
    const int nDivisor = pDifficultyLevelsTxt->dwAiCurseDivisor;
    if (nDivisor > 0)
        nValue /= nDivisor;
    return nValue;
}

int __stdcall sub_M125_Emit_004E6E80(int nUnused1, int nUnused2, int nUnused3, int nValue)
{
    return SKILLDESC_ApplyAiCurseDivisor(nValue);
}

int sub_H14_Emit_004E83B0(Unicode* wszOut, int nSkillId)
{
    return SKILLDESC_AppendSkillDescStrLong(wszOut, nSkillId);
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

// 0x004E6FF0
int __cdecl SKILLDESC_SumProgressiveBonus()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return 0;
    }

    int nSum = 0;
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (!STATES_CheckState(pPlayer, sgptDataTables->pProgressiveStates[i]))
        {
            continue;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, sgptDataTables->pProgressiveStates[i]);
        if (!pStatList)
        {
            continue;
        }

        const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            continue;
        }

        D2SkillsTxt* pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        const int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
        if (nSkillLevel <= 0 || pSkillsTxtRecord->nPrgDamage != 1)
        {
            continue;
        }

        if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            continue;
        }

        const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        if (nValue > 0)
        {
            nSum += SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel) * nValue;
        }
    }

    return nSum;
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
// noinline: the original calls this; without it the compiler expands it into 0x004E7A90.
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
// noinline: the original calls this; without it the compiler expands it into 0x004E7A90, 0x004E85C0.
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

extern "C" void __stdcall sub_K07_EmitB(Unicode* wszText, int bPrefixSign, int nMin, int nMinFrac, int nMax, int nMaxFrac)
{
    SKILLDESC_FormatDecimalRange(wszText, bPrefixSign, nMin, nMinFrac, nMax, nMaxFrac);
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

// 0x004E7900
static int SKILLDESC_AppendStringLine(wchar_t* wszOut, unsigned short wStr)
{
    sub_00526700((Unicode*)wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700((Unicode*)wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

void __stdcall sub_M24_Emit_004E7900(wchar_t* wszOut, unsigned short wStr, int nOther)
{
    if (nOther)
        SKILLDESC_AppendStringLine(wszOut, wStr);
}

// 0x004E7930
static int __stdcall SKILLDESC_AppendFormattedValue(Unicode* wszOut, int nValue, unsigned short wStr)
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

    sub_005269D0_FormatText(256, wszText, D2LANG_GetStringFromTblIndex(wStr), nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszOut, wszText);
    return 1;
}

// 0x004E79E0
static int __stdcall SKILLDESC_AppendLabelValue(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign)
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
static int __stdcall SKILLDESC_AppendValueLabel(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign)
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
    sub_00526700((Unicode*)wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700((Unicode*)wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
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
static int __stdcall SKILLDESC_AppendLabelRangeLabel(unsigned short wStr1, unsigned short wStr2, Unicode* wszOut, int bPrefixSign, int nMin, int nMax)
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
static int __stdcall SKILLDESC_AppendLabelRange(unsigned short wStr, Unicode* wszOut, int bSeparator, int nMin, int nMax, int bPrefixSign)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValue(wszOut, wStr, nMin, bPrefixSign);

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

// 0x004E85C0
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

    nSkillId = pSkillDescTxt->wStrMana;
    const int nLevelMana = pSkillsTxt->wLevelMana;
    const int nLevelCost = nLevelMana << pSkillsTxt->nManaShift;
    int nCost = ((nLevel - 1) * nLevelMana + nMana) << pSkillsTxt->nManaShift;
    const int nMinCost = pSkillsTxt->wMinMana << 8;
    if (nMinCost > nCost)
        nCost = nMinCost;

    if (pSkillsTxt->nManaShift == 8 || nLevelCost > 0x100 || nCost > 0x1900)
        return SKILLDESC_AppendLabelValue(wszOut, (unsigned short)nSkillId, nCost >> 8, 0);

    if (nMultiplier <= 10)
        return SKILLDESC_AppendLabelDecimal((unsigned short)nSkillId, wszOut, 0, nCost / 256, nCost % 256 * 10 / 256);

    return SKILLDESC_AppendScaledValue((unsigned short)nSkillId, 0x1506, nMultiplier, wszOut, 0, nCost);
}

static inline int SDPHYS_TestFlag(const unsigned char* pFlags, int nBit)
{
    return pFlags[nBit >> 3] & gdwBitMasks_006CE268[nBit & 7];
}

// 0x004E86F0
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
        DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
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
    if (SDPHYS_TestFlag(pSkillsTxt->nFlags, 3))
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


// 0x004E9000
void __fastcall sub_004E9000_SkillDescAttackRatingMain(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    D2UnitStrc* pItem = 0;
    if (pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    *pValue1 = 0;
    *pValue2 = 0;
    SKILLDESC_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}

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

// 0x004E9160
static int __stdcall SKILLDESC_GetAttackRateValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == ITEMTYPE_MISSILE_POTION)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = 0;
    if (STATES_CheckState(pUnit, STATE_THROWINGMASTERY))
        nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);

    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_TOHIT_PERCENT, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    *pValue1 += *pValue1 * nBonus / 100;

    *pValue2 = 0;
    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
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

static __forceinline D2UnitStrc* sub_P03_MergeLeftWeaponOnly(D2UnitStrc* pUnit, D2UnitStrc* pWeapon)
{
    if (ITEMS_CanBeEquipped(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    return pWeapon;
}

// 0x004E9300
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
    if (!pOther || pOther == pWeapon)
        return sub_P03_MergeLeftWeaponOnly(pUnit, pWeapon);

    if (!ITEMSIsA(pOther, 45))
        return sub_P03_MergeLeftWeaponOnly(pUnit, pWeapon);

    if (!ITEMS_CanBeEquipped(pWeapon) || !ITEMS_CanBeEquipped(pOther))
        return sub_P03_MergeLeftWeaponOnly(pUnit, pWeapon);

    STATLIST_MergeStatLists(pUnit, pOther, 0);
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

// 0x004E9590
void __fastcall SKILLDESC_DescAttackRate(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    *pValue1 = 0;
    *pValue2 = 0;
    SKILLDESC_GetAttackRateValues(pUnit, 0, pValue1, pValue2, nLevel, pSkill);
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
static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, int nRatio, D2SkillStrc* pSkill, D2UnitStrc* pItem)
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

// 0x004E9870
void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2)
{
    D2Win_10127_SetFont(6);
    if (!gbTextOffsetInit)
    {
        if (STRTABLE_GetLanguage() >= 6 && STRTABLE_GetLanguage() <= 9)
        {
            gnTextOffset1 = -7;
        }
        else
        {
            gnTextOffset1 = -6;
        }

        gbTextOffsetInit = 1;
    }

    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + gnTextOffset1 + nY - 480, gnPanelOffsetX + nRight, wszText1, nColor1);
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnTextOffset2 + gnScreenHeight + gnPanelOffsetY + nY - 480, gnPanelOffsetX + nRight, wszText2, nColor2);
}

// 0x004E9940
static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    Unicode wszText[32];
    char szText[32];
    wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (nValue < 1000)
    {
        D2Win_10127_SetFont(1);
    }
    else
    {
        D2Win_10127_SetFont(0);
    }
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + nY - 480,
                            gnPanelOffsetX + nRight, wszText, nColor);
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
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nWeaponMin, &nWeaponMax, &nWeaponColor, pSkillsTxt->nSrcDam, pSkill, 0);
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
    if (!pItem || !ITEMS_CheckIfThrowable(pItem))
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


extern "C" unsigned short __stdcall sub_D05_Emit_4E6F60(int n) { return SKILLDESC_GetETypeDamageStr(n); }

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
    SKILLDESC_GetElemDamage(pUnit, &nDamage[0], &nDamage[1], &nType, pSkillsTxt, nLevel);
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
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt->nSrcDam, pSkill, 0);
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
    SKILLDESC_DrawWeaponDamage(pUnit, pSkill, pSkillsTxt, nSkillLevel, (SKILLWEAPONFN)SKILLDESC_ThrowDamageCallback, nBonus, 0, nLeft, nY, nRight, 1);
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
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt->nSrcDam, pSkill, 0);
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
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt->nSrcDam, pSkill, 0);

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

// 0x004EB940
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
    D2SkillsTxt* pRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pRecord ? 0 : pRecord->dwParam[4];
    nMin += nParam * nMin / 100;
    nMax += nParam * nMax / 100;
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
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

    return SKILLDESC_AddElemRatePerSecond(nString, wszText, nMinRate, nMaxRate);
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

    return SKILLDESC_AddElemRatePerSecond(nString, wszText, nMin, nMax);
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
        wsprintfA(szText, gszFmtPlusDecimal, nWhole, nFraction);
    }
    else
    {
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
        return SKILLDESC_AppendLabelValue(wszText, nString, nMin, bPlus);
    }

    Unicode wszNumber[32];
    char szNumber[32];
    if (bPlus)
    {
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

// 0x004EC280
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

// 0x004ED570
void __fastcall SKILLDESC_DrawSkillPanel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot)
{
    int nValue1, nValue2, nColor1, nColor2;
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt) return;
    int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x1588);
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
    switch (sub_004D9FC0_GetSkillUseState(pUnit, pSkill))
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
            sub_005269D0_FormatText(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFDF), wszName);
        else
            sub_005269D0_FormatText(200, wszDescription, D2LANG_GetStringFromTblIndex(0xFE1), wszName);
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


// 0x004EDA20
void __fastcall SKILLDESC_RefreshSkills(D2UnitStrc* pUnit)
{
    if (!gbSkillRefreshInit)
    {
        if (STRTABLE_GetLanguage() >= 6 && STRTABLE_GetLanguage() <= 9)
        {
            gaSkillTextPositions[0].nY -= 1;
            gaSkillTextPositions[6].nY -= 1;
        }

        gbSkillRefreshInit = 1;
    }

    if (pUnit)
    {
        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        SKILLDESC_DrawSkillPanel(pUnit, pSkill, 0);
        pSkill = UNITS_GetRightSkill(pUnit);
        SKILLDESC_DrawSkillPanel(pUnit, pSkill, 6);
    }
}

struct D2RequestStrc;

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    D2UnitStrc* pOtherUnit;
    int unk0x0C;
    int nMissile;
    int nX;
    int nY;
    int nTargetX;
    int nTargetY;
    int nGfxArg;
    int nVelocity;
    int nSkill;
    int nSkillLevel;
    int unk0x34[8];
    void* pfCallback;
    int nIndex;
};

D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540


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
        D2UnitStrc* pMissile = AUTOMAP_RequestAtTarget(pUnit, nArg0, nArg3, nArg4);
        if (pMissile)
        {
            if (bClearPathFlag)
            {
                D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
            }

            UNITS_SetAnimationSpeed(pMissile, nMissileArg);
        }
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x21;
    tRequest.pUnit = pUnit;
    tRequest.nX = UNITS_GetXPositionInline(pUnit);
    tRequest.nY = UNITS_GetYPositionInline(pUnit);
    tRequest.nTargetX = nTargetX;
    tRequest.nTargetY = nTargetY;
    tRequest.nSkill = nArg3;
    tRequest.nSkillLevel = nArg4;
    tRequest.nMissile = nArg0;
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

            UNITS_SetAnimationSpeed(pMissile, nMissileArg);
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

// 0x004F29F0
int __fastcall SKILLDESC_CltDoMissileScatterAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    int nX;
    int nY;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        nX = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
    }
    else if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    SKILLDESC_MissileScatter(pUnit, nX, nMissile, nX, nY, nCount, nSkillId, nSkillLevel);
    return 1;
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

static int __stdcall sub_004EDCA0_AddElemDamageOverTime(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    SKILLDESC_AddSeconds(nLength, 0x2B0E, 0, wszText);
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





D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0




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



static __forceinline int ApplyPercentChecked(int nValue, int nPercent)
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

int __fastcall sub_M214_Emit_004EDEA0(Unicode* wszText, unsigned short nString, int nFrames)
{
    return SKILLDESC_AddSecondsPlus(nString, nFrames, wszText);
}

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return pRecord;
}

static inline D2SkillDescTxt* CLIENT_GetSkillDescTxtRecord(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}

static inline D2SkillsTxt* GetSkillsRecord(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline D2SkillDescTxt* GetSkillDescription(int nSkillId) {
    D2SkillsTxt* pRecord = GetSkillsRecord(nSkillId);
    if (pRecord) {
        int nDesc = pRecord->wSkillDesc;
        if (nDesc >= 0 && nDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return &sgptDataTables->pSkillDescTxt[nDesc];
    }
    return 0;
}

static inline int GetMaximumSkillLevel(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) {
        int nLevel = sgptDataTables->pSkillsTxt[nSkillId].nMaxLevel;
        if (nLevel > 0) return nLevel;
    }
    return 20;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static inline unsigned int SEED_RollLobSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline void sub_004F0050_LaunchMotion(D2UnitStrc* pMissile, int nHeight, int nVelocity)
{
    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nHeight);
    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, nVelocity, 1);
    GFXUTIL_UpdateMotion(pMissile);
}

static inline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}

static inline int GetUnitClass(D2UnitStrc* unit)
{
    return !unit ? -1 : unit->dwClassId;
}


// 0x004EA010
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
    const int nLevel = nSkillLevel;
    int& nBonus = nSkillLevel;
    nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98C), nLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98D), nLevel);
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, nAdd, pSkill, 0x80, 0, 0, pUnit, nBonus);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    D2SkillsTxt* const pTxt = pSkillsTxt;
    if (pTxt->nSrcDam != 0x80)
    {
        int& nSrcDam = *(int*)&pSkillsTxt;
        nSrcDam = pTxt->nSrcDam;
        nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
        nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    }

    nMin += SKILLS_GetMinPhysDamage(pUnit, pTxt->nSkillId, nLevel, 0) >> 8;
    nMax += SKILLS_GetMaxPhysDamage(pUnit, pTxt->nSkillId, nLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pTxt->nSkillId, nLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pTxt->nSkillId, nLevel, 1) >> 8;
    SKILLDESC_DrawDamageRange(nMin, nMax, nColor, nY, nLeft, nRight);
}


// 0x004EA4A0
void __fastcall SKILLDESC_ThrowDamageCallback(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem)
{
    *pMin=0;
    *pMax=0;
    if (!pSkill) return;
    if (!pItem) {
        if (!pUnit->pInventory) return;
        pItem=INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        if (!pItem) return;
    }
    if (!ITEMS_CheckIfThrowable(pItem)) return;
    if (ITEMSIsA(pItem,38)) {
        int nMissile=ITEMS_GetMissileType(pItem);
        *pColor=0;
        int nMin=MISSILE_GetMinDamage(0,pUnit,nMissile,1);
        nMin+=MISSILE_GetMinElemDamage(0,pUnit,nMissile,1);
        int nMax=MISSILE_GetMaxDamage(0,pUnit,nMissile,1);
        nMax+=MISSILE_GetMaxElemDamage(0,pUnit,nMissile,1);
        switch (MISSILE_GetElemTypeFromMissileId(nMissile)) {
        case 5: {
            *pColor=2;
            int nLength=MISSILE_GetElementalLength(0,pUnit,nMissile,1)/25;
            if(nLength<=0)nLength=1;
            nMin/=nLength;
            nMax/=nLength;
            break;
        }
        case 4: *pColor=3; break;
        case 1: *pColor=1; break;
        case 2: *pColor=4; break;
        }
        nMin>>=8;
        nMax>>=8;
        if(nMax<=nMin)nMax=nMin;
        *pMin=nMin;
        *pMax=nMax;
        return;
    }
    int nStatBonus=0;
    int nFactor=ITEMS_GetStrengthBonus(pItem);
    if(nFactor)nStatBonus=STATLIST_UnitGetStatValue(pUnit,STAT_STRENGTH,0)*nFactor/100;
    nFactor=ITEMS_GetDexBonus(pItem);
    if(nFactor)nStatBonus+=STATLIST_UnitGetStatValue(pUnit,STAT_DEXTERITY,0)*nFactor/100;
    *pMin=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_THROW_MINDAMAGE,0);
    *pMax=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_THROW_MAXDAMAGE,0);
    nStatBonus+=STATLIST_UnitGetStatValue(pUnit,STAT_DAMAGEPERCENT,0);
    int nMinPercent=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_MINDAMAGE_PERCENT,0);
    int nMaxPercent=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_MAXDAMAGE_PERCENT,0);
    if(nStatBonus<=-90)nStatBonus=-90;
    *pMin+=*pMin*(nMinPercent+nStatBonus)/100;
    *pMax+=*pMax*(nMaxPercent+nStatBonus)/100;
    int nSkillBonus=nBonus;
    if(STATES_CheckState(pUnit,STATE_THROWINGMASTERY))nSkillBonus+=SKILLS_GetWeaponMasteryBonus(pUnit,pItem,pSkill,1);
    *pMin+=DATATBLS_ApplyRatio(*pMin,nSkillBonus,100);
    *pMax+=DATATBLS_ApplyRatio(*pMax,nSkillBonus,100);
    if(*pMax<*pMin)*pMax=*pMin;
    {
        int nElemMin=0;
        int nElemMax=0;
        sub_004E89A0(pUnit,&nElemMin,&nElemMax,pColor,pSkill);
        if(nElemMax<nElemMin)nElemMax=nElemMin;
        *pMin+=nElemMin;
        *pMax+=nElemMax;
    }
}


// 0x004EAAA0
void __fastcall SKILLDESC_DrawThrowAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nElemMin;
    int nElemMax;
    int nElemColor;
    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    SKILLDESC_ThrowDamageCallback(pUnit, &nMin, &nMax, &nColor, 0, 0, pSkill, 0, 0);
    nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 128);
    nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 128);

    nElemMin = 0;
    nElemMax = 0;
    nElemColor = 0;
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

    Unicode wszText1[32];
    char szText[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
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
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nElemMin == nElemMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nElemMin);
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


// 0x004EC090
static void __stdcall SKILLDESC_AddSummonLife(Unicode* wszText, int nMonsterId, int nPercent, int nBonus)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = &sgptDataTables->pMonStatsTxt[nMonsterId];
    if (!pMonStatsTxt)
    {
        return;
    }

    const int nDifficulty = GAME_GetDifficulty();
    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    if (!DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxt->nLevel[nDifficulty], 1, &monStatsInit))
    {
        return;
    }

    int nLife = (monStatsInit.nMinHP + monStatsInit.nMaxHP) / 2;
    nLife += nLife * nPercent / 100 + nBonus;
    if (nLife)
    {
        SKILLDESC_AppendLabelValue(wszText, 0x10C6, nLife, 0);
    }
}


// 0x004EC2E0
static int __stdcall SKILLDESC_AddPhysDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nBonus, int nSkillLevel, int nPercent)
{
    Unicode wszNumber[32];
    char szNumber[32];
    int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    nMin += ApplyPercentChecked(nMin, nPercent) + nBonus;
    nMax += ApplyPercentChecked(nMax, nPercent) + nBonus;
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin != nMax)
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 0)
    {
        wsprintfA(szNumber, "+%d", nMin);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10A0));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}


// 0x004EC510
static int SKILLDESC_AddToHit(Unicode* wszText, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (!nToHit)
    {
        return 0;
    }

    return sub_004E7E70_AddValueTwoTexts(0x10A6, 0x10B3, 1, nToHit, wszText);
}


// 0x004EC540
static int __stdcall SKILLDESC_AddElemRatePerSecond(unsigned short nString, Unicode* wszText, int nMin, int nMax)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin == nMax)
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nMin);
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


// 0x004EC7E0
static int __stdcall SKILLDESC_AddValueLine(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nValue)
{
    if (!nValue)
    {
        return 0;
    }

    Unicode wszNumber[32];
    char szNumber[32];
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, "+%d", nValue);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    if (nStringBefore != 0x1506)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    }
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}


// 0x004EC900
static int __stdcall SKILLDESC_AddDecimalLine(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nWhole, int nFraction)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nWhole && !nFraction)
    {
        return 0;
    }

    Unicode wszNumber[32];
    sub_004E7430_FormatDecimal(wszNumber, bPlus, nWhole, nFraction);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}


// 0x004ECA00
static int __stdcall SKILLDESC_AddValueOverTime(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int nValue, int bPlus, int nCount)
{
    if (nStringBefore != 0x1506 && nValue && nCount > 0)
    {
    char szNumber[32];
    Unicode wszNumber[32];
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_004E73E0_FormatValue(wszNumber, bPlus, nValue);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
    wsprintfA(szNumber, szFmtD_006D57BC, nCount);
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
    }

    return 0;
}


// 0x004ECB10
static int SKILLDESC_AddTextPair(Unicode* wszText, unsigned short nString1, unsigned short nString2)
{
    if (nString1 != 0x1506 && nString2 != 0x1506)
    {
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString1));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
    }

    return 0;
}


// 0x004ECB80
static int __stdcall SKILLDESC_AddValueAfterText(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nValue)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nValue)
    {
        return 0;
    }

    Unicode wszNumber[32];
    sub_004E73E0_FormatValue(wszNumber, bPlus, nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}


// 0x004ECC80
static int __stdcall SKILLDESC_AddFormattedText(Unicode* wszText, int nValue, unsigned short nString)
{
    if (nString == 0x1506)
    {
        return 0;
    }

    Unicode wszLine[0x100];
    sub_005269D0_FormatText(0x100, wszLine, D2LANG_GetStringFromTblIndex(nString), nValue);
    sub_00526700(wszText, wszLine);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}


// 0x004ED0D0
static int SKILLDESC_AddNextLevelParam(int nSkillId, int nSkillLevel, Unicode* wszText)
{
    if (nSkillLevel > 1)
    {
        sub_004E7C30_AddValueTextAfter(0x10D5, 0, SkillParam_0D0(nSkillId, nSkillLevel - 1), wszText);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x110D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}


// 0x004EDB30
static int __stdcall SKILLDESC_AddSeconds(int nFrames, unsigned short nString, int bPlus, Unicode* wszText)
{
    Unicode wszNumber[32];
    const int nSeconds = nFrames / 25;
    const int nTenths = nFrames % 25 * 10 / 25;
    if (!nSeconds && !nTenths)
    {
        return 0;
    }

    if (nTenths)
    {
        sub_004E7430_FormatDecimal(wszNumber, bPlus, nSeconds, nTenths);
    }
    else
    {
        sub_004E73E0_FormatValue(wszNumber, bPlus, nSeconds);
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nSeconds == 1 && !nTenths ? 0x10AB : 0x10AC));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}



// 0x004EDC30
static int SKILLDESC_AddSecondsPlus(unsigned short nString, int nFrames, Unicode* wszText)
{
    return SKILLDESC_AddSeconds(nFrames, nString, 1, wszText);
}


// 0x004EDC40
static int __stdcall SKILLDESC_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    if (nLength)
    {
        unsigned short nString;
        switch (pSkillsTxt->nEType)
        {
        case 5:
            nString = 0x10AA;
            break;
        case 4:
            nString = 0x10A9;
            break;
        default:
            return 0;
        }

        return SKILLDESC_AddSeconds(nLength, nString, 0, wszText);
    }

    return 0;
}


// 0x004EEF00
void __fastcall SKILLDESC_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int nHeight;
    int nWidth;
    char szNumber[32];
    if(!pUnit)return;
    D2SkillsTxt* pSkillsTxt=CLIENT_GetSkillsTxtRecord(nSkillId);
    if(!pSkillsTxt)return;
    D2SkillStrc* pBonusSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bGranted;
    if(pBonusSkill){
        if(SKILLS_GetSkillLevel(pUnit,pBonusSkill,1) && !SKILLS_GetSkillLevel(pUnit,pBonusSkill,0))bGranted=1;
        else bGranted=0;
    } else bGranted=0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText,D2LANG_GetStringFromTblIndex(0x109C));
    D2SkillStrc* pSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bMaxed;
    if(pSkill && SKILLS_GetSkillLevel(pUnit,pSkill,0)>=SPELLSEL_GetSkillMaxLevel(nSkillId))bMaxed=1;
    else bMaxed=0;
    int bFound=0;
    for(int i=16;i>=10;--i)
        if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bFound=1;
    if(bFound)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    if(!bMaxed)
    {
        int bNext=0;
        for(int i=0;i<6;++i)
            if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bNext=1;
        if(bNext)
        {
            int nPrefixId=0x109D;
            if(!nSkillLevel)nPrefixId=0x10AD;
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(nPrefixId));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    if(nSkillLevel>0)
    {
        int bCurrent=0;
        for(int i=0;i<6;++i)
            if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel,nArg,i,0))bCurrent=1;
        if(bCurrent)
        {
            wsprintfA(szNumber,gszFormatD,nSkillLevel);
            sub_00526320_ToUnicode(wszNumber,szNumber,32);
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x109E));
            sub_00526700(wszText,wszNumber);
            if(bGranted)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1112));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    int bSynergy=0;
    for(int i=6;i<10;++i)
        if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bSynergy=1;
    if(bSynergy)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    D2SkillDescTxt* pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrLong));
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    Unicode wszName[1024];
    pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_005267E0(wszName,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrName));
    sub_004521C0_SetTextColor(wszName,2);
    sub_00526700(wszText,wszName);
    if(bGranted)
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1113));
    }
    if(!SKILLDESC_HasClassSkill(pUnit))
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText,&nWidth,&nHeight);
    D2Win_10129_DrawFramedText(wszText,nX-24,nHeight+nY+3,0,0);
}


// 0x004EF410
void __fastcall SKILLDESC_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int bFound;
    int nHeight;
    int nWidth;
    char szNumber[32];
    if (!pUnit) return;
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt) return;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    D2SkillStrc* pBonusSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    int bBonusOnly;
    if (pBonusSkill) {
        if (SKILLS_GetSkillLevel(pUnit, pBonusSkill, 1) && !SKILLS_GetSkillLevel(pUnit, pBonusSkill, 0))
            bBonusOnly = 1;
        else bBonusOnly = 0;
    } else bBonusOnly = 0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x109c));
    bFound = 0;
    for (int i = 16; i >= 10; --i) {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel + 1, nArg, i, 1))
            bFound = 1;
    }
    if (bFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    int bCurrentFound = 0;
    for (int i = 0; i < 6; ++i) {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bCurrentFound = 1;
    }
    if (bCurrentFound) {
        if (nSkillLevel <= 0) {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10ad));
        } else {
            wsprintfA(szNumber, gszFormatD, nSkillLevel);
            sub_00526320_ToUnicode(wszNumber, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x109e));
            sub_00526700(wszText, wszNumber);
        }
        if (bBonusOnly) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1112));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    }
    int bRemainingFound = 0;
    for (int i = 6; i < 10; ++i) {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bRemainingFound = 1;
    }
    if (bRemainingFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0) >= GetMaximumSkillLevel(nSkillId)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1111));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    } else {
        int nRequired = pSkillsTxt->wReqLevel + nSkillLevel;
        Unicode wszRequired[32];
        if (nRequired) {
            wsprintfA(szNumber, gszFormatD, nRequired);
            sub_00526320_ToUnicode(wszRequired, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105b));
            sub_00526700(wszText, wszRequired);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        }
    }
    D2SkillDescTxt* pDescription = GetSkillDescription(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrLong));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    Unicode wszName[256];
    pDescription = GetSkillDescription(nSkillId);
    sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrName));
    INV_PrefixColorCode(wszName, 2);
    sub_00526700(wszText, wszName);
    if (bBonusOnly) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1113));
    }
    if (!SKILLDESC_HasClassSkill(pUnit)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    D2Win_10129_DrawFramedText(wszText, nX, nHeight + nY + 3, 1, 0);
}


// 0x004EFDF0
int __fastcall SKILLDESC_CltDoLobMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc tMissileParams;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMissile = pSkillsTxtRecord->wCltMissileA;
        D2MissilesTxt* pMissilesTxtRecord;
        int nMissilesCount;
        if (nMissile >= 0 && nMissile < (nMissilesCount = sgptDataTables->nMissilesTxtRecordCount)
            && (pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile]) != 0)
        {
            int nAltMissile = pSkillsTxtRecord->wCltMissileB;
            if (nAltMissile < 0 || nAltMissile >= nMissilesCount)
            {
                nAltMissile = -1;
            }

            D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
            if (pTarget)
            {
                D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
                CUNIT_SetPathTargetToTargetUnit(pUnit, 1);
            }

            int nTargetX;
            int nTargetY;
            if (ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
            {
                if (!pTarget)
                {
                    UNITS_UpdateDirectionAndSpeed(pUnit, nTargetX, nTargetY);
                }

                sub_00681EF0_Memset(&tMissileParams, 0, sizeof(tMissileParams));
                tMissileParams.dwFlags = 0x25;
                tMissileParams.pOwner = pUnit;
                tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
                tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
                tMissileParams.nSkill = nSkillId;
                tMissileParams.nSkillLevel = nSkillLevel;
                tMissileParams.nTargetX = nTargetX;
                tMissileParams.nTargetY = nTargetY;

                const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel) + GFXUTIL_GetMotionAZ(pUnit);
                const int nFrames = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + pMissilesTxtRecord->dwParam[1];
                int nSpeed = pMissilesTxtRecord->nAnimLen << 8;
                int nFall = -2 * nHeight;
                if (nFrames)
                {
                    nSpeed /= nFrames;
                    nFall /= nFrames;
                }

                D2SeedStrc* pSeed = &pUnit->pSeed;
                tMissileParams.nMissile = nMissile;
                if (nAltMissile > 0 && SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    tMissileParams.nMissile = nAltMissile;
                }

                tMissileParams.nVelocity = pMissilesTxtRecord->nVel + gaLobVelocityBonus[SEED_RollLobSeed(pSeed) % 5];

                D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
                if (pMissile)
                {
                    PATH_SetNewDistance(pMissile->pDynamicPath, nFrames);
                    UNITS_SetAnimationSpeed(pMissile, nSpeed);
                    MISSILE_SetTotalFrames(pMissile, nFrames);
                    MISSILE_SetCurrentFrame(pMissile, nFrames);
                    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nHeight);
                    GFXUTIL_UpdateMotion(pMissile);
                    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, nFall, 1);
                }

                return 1;
            }
        }
    }

    return 0;
}


// 0x004F0050
int __fastcall SKILLDESC_CltDoLaunchMissileAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pMissile = MISSILE_SubmitTargetRequest(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    const int nFrames = MISSILE_GetTotalFrames(pMissile);
    const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + GFXUTIL_GetMotionAZ(pUnit);
    sub_004F0050_LaunchMotion(pMissile, nHeight, nFrames ? -(nHeight / nFrames) : -(nHeight / 2));
    return 1;
}


// 0x004F0F10
int __fastcall SKILLDESC_IsVineBeastMissile(D2UnitStrc* unit, void* unused)
{
    if (GetUnitType(unit) != 3)
        return 0;
    return GetUnitClass(unit) == 468;
}

static inline D2SkillsTxt* CLIENT_LookupSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2SkillDescTxt* CLIENT_LookupSkillDescTxtRecord(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_LookupSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}


// 0x004EDDD0
static int __stdcall sub_004EDDD0_AddAttackInfo(Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillLevel)
{
    if (GAME_IsExpansion())
    {
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, 0, nSkillLevel, 0);
        SKILLDESC_AddToHit(wszText, pUnit, nSkillId, nSkillLevel);
        return 1;
    }

    int nMin = 0;
    int nMax = 0;
    int nType;
    SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nType, pSkillsTxt, nSkillLevel);
    sub_004E80F0_AddRangeText(wszText, 0, nMin, nMax, 0x10A0, 0);
    return 1;
}


// 0x004EF990
void __fastcall sub_004EF990_SetSkillPopUpText(D2UnitStrc* pUnit, int nSkillId, int nArg3, int nArg4, int nArg5, int nX, int nY)
{
    int bFound;
    int nHeight;
    int nWidth;
    char szNumber[32];

    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = CLIENT_LookupSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return;
    }

    Unicode wszText[1024];
    Unicode wszNumber[32];

    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x109C));

    bFound = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nArg3, nArg4, i, nArg5))
        {
            bFound = 1;
        }
    }

    if (bFound)
    {
        wsprintfA(szNumber, gszFormatD, nArg3);
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x109E));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }

    if (!nSkillId && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwClassId == 6)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x5722));
    }

    D2SkillDescTxt* pSkillDescTxt = CLIENT_LookupSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pSkillDescTxt ? 0x1506 : pSkillDescTxt->wStrShort));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));

    pSkillDescTxt = CLIENT_LookupSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pSkillDescTxt ? 0x1506 : pSkillDescTxt->wStrName));

    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    D2Win_10129_DrawFramedText(wszText, nX, nHeight + nY + 3, nArg5, 0);
}

// 0x004EFC20
int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[1];
}

// 0x004EFC50
int __fastcall SKILLDESC_GetSkillParamThree(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[2];
}

// 0x004EFC80
int __fastcall SKILLDESC_GetSkillParamFour(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

// 0x004EFCB0
int __fastcall SKILLDESC_GetSummonLevel(int nSkillId, int nSkillLevel)
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

    return pSkillsTxtRecord->dwParam[4] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5];
}

// 0x004EFCF0
int __fastcall SKILLDESC_CltDoTurnedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 2;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nTargetX = nX - CLIENTS_GetUnitX(pUnit);
    tMissileParams.nTargetY = nY - CLIENTS_GetUnitY(pUnit);
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -tMissileParams.nTargetY);
    MISSILE_SetTargetY(pMissile, tMissileParams.nTargetX);
    return 1;
}

static __forceinline void AppendString(Unicode* wszText, unsigned short nString)
{
    if (nString != 0x1506)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    }
}


// 0x004EDEA0
int __fastcall SKILLDESC_AddSkillLine(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nManaValue, int nLine, int nLevelBonus)
{
    int nCalcA;
    int nCalcB;
    int nStringB;
    int nStringA;
    D2MissilesTxt* pMissilesTxt;
    int nMissileId;
    int nFrames;
    int szNumber_[8]; char* const szNumber = (char*)szNumber_;
    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    int wszLine_[128]; Unicode* const wszLine = (Unicode*)wszLine_;
    int wszMessage_[50]; Unicode* const wszMessage = (Unicode*)wszMessage_;

    if (!pSkillsTxt)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
    {
        return 0;
    }

    nCalcA = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcA[nLine], nSkillId, nSkillLevel);
    nCalcB = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcB[nLine], nSkillId, nSkillLevel);
    nStringA = pSkillDescTxt->wDescTextA[nLine];
    nStringB = pSkillDescTxt->wDescTextB[nLine];
    switch (pSkillDescTxt->nDescLine[nLine])
    {
    case 1:
        sub_004E85C0_AppendManaCost(wszText, nSkillId, nSkillLevel, nCalcA, pSkillsTxt, nManaValue);
        break;

    case 2:
        SKILLDESC_AppendLabelValueLabel(nStringA, nStringB, 1, wszText, nCalcA);
        break;

    case 3:
        SKILLDESC_AppendLabelValueLabel(nStringA, nStringB, 0, wszText, nCalcA);
        break;

    case 4:
        SKILLDESC_AppendLabelValue(wszText, nStringA, nCalcA, 1);
        break;

    case 5:
        SKILLDESC_AppendLabelValue(wszText, nStringA, nCalcA, 0);
        break;

    case 6:
        SKILLDESC_AppendValueLabel(wszText, nStringA, nCalcA, 1);
        break;

    case 7:
        SKILLDESC_AppendValueLabel(wszText, nStringA, nCalcA, 0);
        break;

    case 8:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddToHit(wszText, pUnit, nSkillId, nSkillLevel);
        break;

    case 9:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, nCalcB, nSkillLevel, nCalcA);
        break;

    case 10:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        break;

    case 11:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
        break;

    case 12:
        AppendString(wszText, nStringB);
        SKILLDESC_AddSeconds(nCalcA, nStringA, 0, wszText);
        break;

    case 13:
        SKILLDESC_AddSummonLife(wszText, pSkillsTxt->wSummon, nCalcA, nCalcB);
        break;

    case 14:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        sub_004EDCA0_AddElemDamageOverTime(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel);
        break;

    case 15:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 16:
        SKILLDESC_AppendFrameRange(wszText, 0x10B0, nCalcA, nCalcB);
        break;

    case 17:
        AppendString(wszText, nStringB);
        SKILLDESC_AppendLabelRangeLabel(nStringA, 0x10BE, wszText, 0, nCalcA, nCalcB);
        break;

    case 18:
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(nStringA));
        {
            const int nLevel = nCalcA;
            if (nLevel > 0)
            {
                INV_PrefixColorCode(wszLine, nLevel);
            }
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 19:
        AppendString(wszText, nStringB);
        SKILLDESC_AppendSecondsTwentieths(nStringA, wszText, nCalcA);
        break;

    case 20:
        SKILLDESC_AppendLabelValueLabels(nStringA, 0x10B3, nStringB, 1, wszText, nCalcA);
        break;

    case 21:
        SKILLDESC_AppendLabelValueLabels(nStringA, 0x10B3, nStringB, 0, wszText, nCalcA);
        break;

    case 22:
        SKILLDESC_AddMissileElemRate(pUnit, wszText, pSkillsTxt, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        break;

    case 23:
        nMissileId = pSkillDescTxt->wDescMissile[0];
        pMissilesTxt = sub_0046ACE0_GetMissilesTxtRecord(nMissileId);
        if (!pMissilesTxt)
        {
            return 0;
        }
        nFrames = pMissilesTxt->wLevRange * nSkillLevel + pMissilesTxt->wRange;
        SKILLDESC_AddSeconds(nFrames, nStringA, 0, wszText);
        break;

    case 24:
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        break;

    case 25:
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(nStringA));
        if ((unsigned short)nStringB != 0x1506)
        {
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(nStringB));
        }
        {
            const int nLevel = nCalcA;
            if (nLevel > 0)
            {
                INV_PrefixColorCode(wszLine, nLevel);
            }
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 26:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemRateByType(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
        break;

    case 27:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemRate(pUnit, wszText, nSkillId, nSkillLevel);
        break;

    case 28:
    {
        D2MissilesTxt* pMissilesTxt = sub_0046ACE0_GetMissilesTxtRecord(pSkillDescTxt->wDescMissile[0]);
        if (!pMissilesTxt)
        {
            return 0;
        }
        SKILLDESC_AppendSecondsTwentieths(0x10AE, wszText, pMissilesTxt->dwParam[0]);
        break;
    }

    case 29:
    {
        D2MissilesTxt* pMissilesTxt = sub_0046ACE0_GetMissilesTxtRecord(pSkillDescTxt->wDescMissile[0]);
        if (!pMissilesTxt)
        {
            return 0;
        }
        SKILLDESC_AppendValueLabel(wszText, 0x10B6, (pMissilesTxt->wLevRange * (nSkillLevel - 1) + pMissilesTxt->wRange) * 2 / 3, 0);
        break;
    }

    case 30:
        pMissilesTxt = sub_0046ACE0_GetMissilesTxtRecord(pSkillDescTxt->wDescMissile[0]);
        if (!pMissilesTxt)
        {
            return 0;
        }
        nMissileId = pMissilesTxt->wSubMissile[0];
        pMissilesTxt = sub_0046ACE0_GetMissilesTxtRecord(nMissileId);
        if (!pMissilesTxt)
        {
            return 0;
        }
        nFrames = pMissilesTxt->wLevRange * nSkillLevel + pMissilesTxt->wRange;
        SKILLDESC_AddSeconds(nFrames, nStringA, 0, wszText);
        break;

    case 31:
    {
        D2DifficultyLevelsTxt* pDifficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(GAME_GetDifficulty());
        const int nDivisor = pDifficultyLevelsTxt->dwAiCurseDivisor;
        SKILLDESC_AddSeconds(nDivisor > 0 ? nCalcA / nDivisor : nCalcA, nStringA, 0, wszText);
        break;
    }

    case 32:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        SKILLDESC_AppendLabelValueLabel(nStringB, 0x10B3, 1, wszText, nCalcA);
        break;

    case 33:
        if (nSkillLevel > 1)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        }
        break;

    case 34:
        SKILLDESC_AddSummonDamageBonus(pUnit, wszText, nSkillId, pSkillsTxt, nSkillLevel);
        break;

    case 35:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00403040_VectorConstructor(wszNumber, 2, 0x20, NPCMENU_ClearUnicode);
        wsprintfA(szNumber, gszFmtRange, nCalcA, nCalcB);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 36:
        SKILLDESC_AppendValueCountLabel(nStringA, nStringB, 0, wszText, nCalcA);
        break;

    case 37:
        SKILLDESC_AppendSecondsTenths(nStringA, wszText, nCalcA);
        break;

    case 38:
        SKILLDESC_AppendLabelRangeLabel(nStringA, nStringB, wszText, 0, nCalcA, nCalcB);
        break;

    case 39:
        SKILLDESC_AddSummonDamage(pUnit, wszText, nSkillId, nSkillLevel, pSkillsTxt);
        break;

    case 40:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005269D0_FormatText(0x100, wszLine, D2LANG_GetStringFromTblIndex(nStringA), D2LANG_GetStringFromTblIndex(nStringB));
        if (nCalcA > 0)
        {
            INV_PrefixColorCode(wszLine, nCalcA);
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 41:
        SKILLDESC_AddMonsterDamage(wszText, pSkillsTxt, nCalcA, nCalcB);
        break;

    case 42:
        SKILLDESC_AddDecimalLine(wszText, nStringA, nStringB, 1, 0, nCalcA, nCalcB);
        break;

    case 43:
        SKILLDESC_AppendScaledRange(wszText, nStringA, nStringB, nCalcB, 10, nCalcA);
        break;

    case 44:
        SKILLDESC_AppendScaledRange(wszText, nStringA, nStringB, nCalcB, 100, nCalcA);
        break;

    case 45:
        SKILLDESC_AddNextLevelParam(nSkillId, nSkillLevel, wszText);
        break;

    case 46:
        if (!nCalcB)
        {
            return 0;
        }
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005269D0_FormatText(0x100, wszLine, D2LANG_GetStringFromTblIndex(nStringA), D2LANG_GetStringFromTblIndex(nStringB));
        if (nCalcA > 0)
        {
            INV_PrefixColorCode(wszLine, nCalcA);
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 47:
        SKILLDESC_AppendLabelRange(nStringA, wszText, 0, nCalcA, nCalcB, 0);
        break;

    case 48:
        sub_004EDDD0_AddAttackInfo(wszText, nSkillId, pSkillsTxt, pUnit, nSkillLevel);
        break;

    case 49:
    {
        const int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        const int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        SKILLDESC_AppendLabelRange(nStringA, wszText, 1, nMin, nMax, 1);
        break;
    }

    case 50:
        SKILLDESC_AddMissileElemDamage(pUnit, wszText, nStringA, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        break;

    case 51:
        SKILLDESC_AppendFormattedValue(wszText, nCalcA, nStringA);
        break;

    case 52:
        SKILLDESC_AppendLabelRangeLabel(nStringA, nStringB, wszText, 1, nCalcA, nCalcB);
        break;

    case 53:
        TEXT_DrawHintText(sub_004A9A90_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 54:
        TEXT_DrawHintText(sub_004A9AE0_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 55:
        TEXT_DrawHintText(sub_004A9B30_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 56:
        TEXT_DrawHintText(sub_004A9B80_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 57:
        SKILLDESC_AddSeconds(nCalcA, nStringA, 1, wszText);
        break;

    case 58:
        SKILLDESC_AppendLabelsRange(wszText, 1, nStringA, nStringB, nCalcA, nCalcB);
        break;

    case 59:
        AppendString(wszText, nStringB);
        SKILLDESC_AddElemRange(wszText, nCalcA, nStringA, nCalcB, pSkillsTxt->nEType);
        break;

    case 60:
        if (!nCalcB)
        {
            nCalcB = 10;
        }
        SKILLDESC_AppendScaledValue(nStringA, nStringB, nCalcB, wszText, 1, nCalcA);
        break;

    case 61:
        if (!nCalcB)
        {
            nCalcB = 10;
        }
        SKILLDESC_AppendScaledValue(nStringA, nStringB, nCalcB, wszText, 0, nCalcA);
        break;

    case 62:
        SKILLDESC_AppendLabelsRange(wszText, 0, nStringA, nStringB, nCalcA, nCalcB);
        break;

    case 63:
        SKILLDESC_AddValueLine(wszText, nStringA, nStringB, 1, 1, nCalcA);
        break;

    case 64:
        SKILLDESC_AddValueOverTime(wszText, nStringA, nStringB, nCalcA, 1, nCalcB);
        break;

    case 65:
        SKILLDESC_AddTextPair(wszText, nStringA, nStringB);
        break;

    case 66:
        SKILLDESC_AddFormattedText(wszText, nCalcA, nStringA);
        break;

    case 67:
        SKILLDESC_AddValueLine(wszText, nStringA, nStringB, 1, 0, nCalcA);
        break;

    case 68:
        SKILLDESC_AppendValueTwoLabels(nStringA, nStringB, 0, wszText, nCalcA);
        break;

    case 69:
        SKILLDESC_AddValueAfterText(wszText, nStringA, nStringB, 0, 0, nCalcA);
        break;

    case 70:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        SKILLDESC_AppendLabelValue(wszText, nStringB, nCalcA, 1);
        break;

    case 71:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        if ((unsigned short)nStringB == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszMessage, 2, 0x64, NPCMENU_ClearUnicode);
        sub_005269D0_FormatText(0x64, wszMessage, D2LANG_GetStringFromTblIndex(nStringB), nCalcA);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, wszMessage);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 72:
        if (!nCalcA)
        {
            return 0;
        }
        if (nCalcB <= 0)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszNumber, 2, 0x20, NPCMENU_ClearUnicode);
        SKILLDESC_FormatSignedInt(wszNumber, 1, nCalcA);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
        wsprintfA(szNumber, gszFormatD, nCalcB);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 73:
        if (!nCalcA)
        {
            return 0;
        }
        if (nCalcB <= 0)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszNumber, 2, 0x20, NPCMENU_ClearUnicode);
        wsprintfA(szNumber, gszFormatD, nCalcA);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
        wsprintfA(szNumber, gszFormatD, nCalcB);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 74:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszMessage, 2, 0x64, NPCMENU_ClearUnicode);
        sub_005269D0_FormatText(0x64, wszMessage, D2LANG_GetStringFromTblIndex(nStringA), nCalcA);
        sub_00526700(wszText, wszMessage);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 75:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszMessage, 2, 0x64, NPCMENU_ClearUnicode);
        sub_005269D0_FormatText(0x64, wszMessage, D2LANG_GetStringFromTblIndex(nStringA), nCalcA, nCalcB);
        sub_00526700(wszText, wszMessage);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    default:
        return 0;
    }

    return 1;
}


// 0x004E72D0
static void __stdcall SKILLDESC_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    int nMin;
    int nMax;
    if (pSkillsTxt->nEType == 5)
    {
        int& nRawMin = nMin;
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        *pType = 2;
        nRawMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        nMin = nLength * nRawMin >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }

    if (pType)
    {
        const int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
        if (nColor)
            *pType = nColor;
    }

    *pMin += nMin;
    *pMax += nMax;
}

static __forceinline int ApplyPercentRef_150(const int& nValue, int nPercent)
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



// 0x004EAE70
void __fastcall SKILLDESC_DrawPhysWeaponElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    int nMin = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, &nColor, nSrcDam, pSkill, 0);
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


// 0x004EC6F0
static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    return SKILLDESC_AddElemRatePerSecond(0x10A1, wszText, nMin, nMax);
}


// 0x004ED150
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
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, LEVELV);
        }
        if (pSkillsTxt->wAuraStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, LEVELV);
            nMin += nDamage;
            nMax += nDamage;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxt->nPassiveStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, LEVELV);
        }
        if (pSkillsTxt->nPassiveStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, LEVELV);
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
        nMin += ApplyPercentRef_150(nMin, nPercent);
        nMax += ApplyPercentChecked(nMax, nPercent);
    }

    SKILLDESC_AddElemRange(wszText, nMin, 0x10A0, nMax, 0);
    return 1;
}







// 0x004ED3F0
void __stdcall TEXT_DrawHintText(int nArg1, int nStringIndex)
{
    Unicode wszText[100];
    sub_005269D0_FormatText(100, wszText, D2LANG_GetStringFromTblIndex(0x1058), nArg1);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    D2Win_10129_DrawFramedText(wszText, gnScreenWidth - 0x80, gnScreenHeight - 0x34, 0, 1);
}

extern "C" void __cdecl SKILLDESC_DrawThrowAndElemDamage(); // 0x004EAAA0
extern "C" void __cdecl SKILLSMON_DescIfRecord(); // 0x004EC040

#pragma pack(push, 1)
struct d2data_006DBF4C_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0072D724_t
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
    unsigned char b16[4];
};
#pragma pack(pop)

extern "C" const struct d2data_006DBF4C_t gData_006DBF4C; // 0x006DBF4C
extern "C" struct d2data_0072D724_t gData_0072D724; // 0x0072D724

extern "C" const struct d2data_006DBF4C_t gData_006DBF4C = {
    { 0x00 }
}; // 0x006DBF4C

extern const unsigned short gawPeriodOfDayStr[4] = { 0x52F3, 0x52F5, 0x52F2, 0x52F4 }; // 0x006DBD88

extern unsigned int gnFileIndexTextCount = 6; // 0x0072D720

extern "C" struct d2data_0072D724_t gData_0072D724 = {
    { 0x00 },
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
    { 0x10 }
}; // 0x0072D724

extern "C" const char gszSkillDescFile[19] = ".\\UI\\SkillDesc.cpp"; // 0x006DBF24

extern SKILLDAMAGEFN gpfnSkillDamageFuncs[36] = {
    0, (SKILLDAMAGEFN)&SKILLDESC_DrawDualWieldLine, (SKILLDAMAGEFN)&SKILLDESC_DrawKickBaseDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawSkillDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawOtherHandDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawWeaponPhysElemDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawWeaponAndSkillDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawSkillWeaponLine, (SKILLDAMAGEFN)&SKILLDESC_DrawElemDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawElementalDamageLine, (SKILLDAMAGEFN)&SKILLDESC_DrawThrowDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawMasteryWeaponDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawBoostedElemDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawSkillWeaponDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawWeaponDamageWithParam, (SKILLDAMAGEFN)&SKILLDESC_DrawKickDamage,
    (SKILLDAMAGEFN)&SKILLDESC_DrawKickDamagePercent, (SKILLDAMAGEFN)&SKILLDESC_DrawDescWeaponAndElemDamage, (SKILLDAMAGEFN)&SKILLSMON_DescIfRecord, (SKILLDAMAGEFN)&SKILLDESC_DrawWeaponDamageLine, (SKILLDAMAGEFN)&SKILLDESC_DrawDualWieldLineNoElem, (SKILLDAMAGEFN)&SKILLDESC_DrawWeaponStatDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawThrowAndElemDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawWeaponAndElemDamage, (SKILLDAMAGEFN)&SKILLDESC_DrawPhysWeaponElemDamage
}; // 0x0072D768

extern D2SkillTextPositionStrc gaSkillTextPositions[12] = {
    { 162, 93, 258 },
    { 162, 101, 258 },
    { 263, 98, 307 },
    { 162, 160, 270 },
    { 162, 163, 270 },
    { 270, 160, 310 },
    { 162, 117, 258 },
    { 162, 125, 258 },
    { 263, 122, 307 },
    { 162, 184, 270 },
    { 162, 187, 270 },
    { 270, 184, 310 }
}; // 0x0072D840

extern const int gaLobVelocityBonus[5] = { -2, -1, 0, 1, 2 }; // 0x006DBF38

extern const int gaSprayOffsetX[8] = { 7, 5, 0, -5, -7, -5, 0, 5 }; // 0x006DBFA8

extern const int gaSprayOffsetY[8] = { 0, 5, 7, 5, 0, -5, -7, -5 }; // 0x006DBFC8

extern const int gaCurvingPathOffsetY[8] = { 0, 2, 2, 2, 0, -2, -2, -2 }; // 0x006DC1E8

extern const int gaCurvingPathOffsetX[8] = { 2, 2, 0, -2, -2, -2, 0, 2 }; // 0x006DC208

extern int gnChargedBoltTurnEvery = 15; // 0x0072D98C

extern int gnChargedBoltTurnBase = 2; // 0x0072D990
