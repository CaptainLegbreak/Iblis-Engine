#include "D2ItemTypes.h"

#include "D2Win32Base.h"

#include "D2StormLink.h"

#include "D2CmpCache.h"

#include "D2Drlg.h"

#include "D2DrlgRooms.h"

#include "D2DrlgTiles.h"

#include "D2Win32Types.h"

#include "D2Path.h"

#include "D2Skills.h"

#include "D2TxtTables.h"

#include "D2Unicode.h"

#include "D2StateIds.h"

#include "D2StatIds.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2Records.h"

#include "D2TxtItems.h"

#include "D2LevelTxt.h"

#include "D2GameRecords.h"

#include "D2ItemsWorld.h"
#include "D2SetsTxt.h"

#pragma intrinsic(_ReadWriteBarrier)

#define IM_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAXIMUM(a,b) (((a)>(b))?(a):(b))

#define MINIMUM(a,b) (((a)<(b))?(a):(b))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

union D2SeedStrc;

struct D2PropertyStrc;

struct D2ItemsTxt;

struct D2RunesTxt;

struct D2DataTablesStrc;

struct D2UnitStrc;

struct D2ItemStatCostTxt;

struct D2StatListStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

D2StatListStrc* __stdcall sub_00625790_UnitFindStatList(D2UnitStrc* pUnit, int nState, int nFlag);

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax); // 0x0065E9E0

int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState); // 0x0065EA50

static int ITEMMODS_IsPercentArmorOrDamageStat(int nStatId);

enum { MAX_DURABILITY = 73, DURABILITY = 72 };

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

int __stdcall STATLIST_GetBaseStatValueByLayer(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x006254E0

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId);

enum { SOCKET_FLAG = 0x800 };

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062BED0

void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10); // 0x0065FD70

D2ItemsTxt* __fastcall ITEMMODS_GetItemsTxtRecordFromUnitOrItem(D2UnitStrc* pUnit, D2UnitStrc* pItem);

static int __stdcall ITEMMODS_AddRolledStatEx(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int a7, int nState, int fStatList);

static void __stdcall ITEMMODS_SetItemBaseStats(D2UnitStrc* pItem, int nStatId);

static void ITEMMODS_ShiftStatValue(int nStatId, int* pValue);

static inline int ITEMMODS_RollPropertyValueA(D2UnitStrc* pItem, int nMin, int nMax);

static inline int ITEMMODS_RollPropertyValueB(D2UnitStrc* pItem, int nMin, int nMax);

static int __stdcall ITEMMODS_AddValueStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList);

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __fastcall ITEMMODS_PropertyFunc06(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065EE80

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0

int __stdcall SKILLS_GetRequiredLevel(int nSkillId); // 0x00644710

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

static D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter);

static int __stdcall ITEMMODS_AddValueStatForceBase(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList);

extern "C" void _ReadWriteBarrier(void);

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag);          // 0x00625790

static D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter);

struct D2PropertiesTxt;

struct D2MagicAffixTxt;

struct D2RareAffixTxt;

struct D2QualityItemsTxt;

struct D2ItemTypeCheckStrc;

struct D2GradeModsStrc;

struct D2GemsTxt;

struct D2UniqueItemsTxt;

struct D2SetItemsTxt;

struct D2PropertyAssignStrc;

struct D2PropertiesTxt
{
    unsigned short wProp;
    unsigned char nSet[7];
    char unk0x09;
    unsigned short wVal[7];
    unsigned char nFunc[7];
    char unk0x1F;
    unsigned short wStat[7];
};

struct D2RareAffixTxt
{
    char unk0x00[0x0E];
    unsigned short wVersion;
    short wIType[7];
    short wEType[4];
};

struct D2QualityItemsTxt
{
    unsigned char nArmor;
    unsigned char nWeapon;
    unsigned char nShield;
    unsigned char nScepter;
    unsigned char nWand;
    unsigned char nStaff;
    unsigned char nBow;
    unsigned char nBoots;
    unsigned char nGloves;
    unsigned char nBelt;
};

struct D2ItemTypeCheckStrc
{
    unsigned char bItemType;
    int nItemType;
};

typedef int(__fastcall* PROPERTYASSIGNFN)(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

extern int gnPropertyFunctionCount; // 0x00745B54

extern PROPERTYASSIGNFN gpfPropertyFunctions[]; // 0x007462F8

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets); // 0x0062BE00

int __fastcall ITEMMODS_PropertyFunc05(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11); // 0x0065ECF0

struct D2GradeModsStrc
{
    char pad0x00[0xC];
    D2PropertyStrc pProperties[12];
};

typedef int (__fastcall* ITEMMODS_PROPERTYFN)(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatlist, D2UnitStrc* a9);

struct D2PropertyAssignStrc
{
    ITEMMODS_PROPERTYFN pfAssign;
    int nStatId;
};

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nUniqueItemId); // 0x00483470

D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex); // 0x00483440

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* pItem); // 0x0065E4D0

extern D2PropertyAssignStrc gaPropertyAssignTable[]; // 0x00745B58

int __fastcall ITEMMODS_PropertyFunc08(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc09(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc10(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc15(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc16(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc17(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc21(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc36(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc22(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc12(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

#define STAT_POISONMAXDAM 58

#define STAT_POISON_COUNT 326

void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0

extern int gaItemFileIndices[]; // 0x0074638C

extern int gnItemFileIndexCount; // 0x007463A4

extern "C" const char gszItemModsSourceFile[]; // 0x006EDB78

#define STAT_ITEM_INDESTRUCTIBLE 152

struct D2SkillsTxt;

void __stdcall sub_00627150(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

int __fastcall ITEMMODS_AssignByTimeStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0

int __fastcall ITEMMODS_AssignRangeStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignRolledStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignRolledStatForceBase(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignAllSkills(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_PropertyFunc01(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc02(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc03(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc04(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

int __fastcall ITEMMODS_PropertyFunc13(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11);

static void ITEMMODS_ShiftStatValue(int nStatId, int* pValue);

static int __stdcall ITEMMODS_AddRolledStatEx(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int a7, int nState, int fStatList);

static void __stdcall ITEMMODS_SetItemBaseStats(D2UnitStrc* pItem, int nStatId);

static int __stdcall ITEMMODS_AddValueStatEx(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int a7, int nState, int fStatList);

int __fastcall ITEMMODS_AssignLayerStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignDamagePercent(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignAllResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignAllMaxResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignMinDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignMaxDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

int __fastcall ITEMMODS_AssignStatPair(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9);

static void __stdcall ITEMMODS_DispatchPropertyAssign(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a11);

void __fastcall ITEMMODS_UpdateFullSetBoni(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState);

void __stdcall ITEMMODS_AddCraftPropertyList(D2UnitStrc* pItem, D2PropertyStrc* pProperty, int nUnused);

void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType);

// 0x0065C5D0
int __cdecl ITEMMODS_GetPropertiesTxtRecordCount()
{
    return sgptDataTables->nPropertiesTxtRecordCount;
}


union D2SeedStrc;

struct D2InventoryStrc;

struct sub_M415_EmitArgs;

struct D2PropertyStrc;

struct D2MagicAffixTxt;

struct D2GradeModsStrc;

struct D2GemsTxt;

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90

unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct sub_M415_EmitArgs
{
    int nPad0;
    int nPad4;
    int nPad8;
    int nMin;
    int nMax;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


void __stdcall sub_C01_EmitSink(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a11);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag); // 0x00625730

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit); // 0x00627220


// 0x0065C5E0
static inline int sub_0065C5E0_RollItemRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

// 0x0065C620
static inline int sub_0065C620_RollItemRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

int __stdcall sub_M415_EmitRoll_0065C5E0(D2UnitStrc* pItem, sub_M415_EmitArgs* pArgs, int nBias)
{
    return sub_0065C5E0_RollItemRange(pItem, pArgs->nMin, pArgs->nMax) + nBias;
}

int __stdcall sub_M415_EmitRoll_0065C620(D2UnitStrc* pItem, sub_M415_EmitArgs* pArgs, int nBias)
{
    return sub_0065C620_RollItemRange(pItem, pArgs->nMin, pArgs->nMax) + nBias;
}

// 0x0065C660
static const D2PropertyStrc* ITEMMODS_GetAffixProperty(const D2MagicAffixTxt* pMods, int nMod)
{
    D2_ASSERT(pMods, 0x79);
    if ((unsigned int)nMod < 3)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x7A);
    return 0;
}

// 0x0065C6A0
static const D2PropertyStrc* ITEMMODS_GetGradeProperty(const D2GradeModsStrc* pMods, int nMod)
{
    if ((unsigned int)nMod < 12)
    {
        return &pMods->pProperties[nMod];
    }

    D2_ASSERT(0, 0x81);
    return 0;
}

// 0x0065C6D0
static const D2PropertyStrc* ITEMMODS_GetGemProperty(const D2GemsTxt* pMods, int nPropSet, int nMod)
{
    const D2PropertyStrc* pProperties[3];
    pProperties[0] = pMods->pProperties[0];
    pProperties[1] = pMods->pProperties[1];
    pProperties[2] = pMods->pProperties[2];
    D2_ASSERT((unsigned int)nPropSet < 3, 0x8F);
    if ((unsigned int)nMod < 3)
    {
        return &pProperties[nPropSet][nMod];
    }

    D2_ASSERT(0, 0x90);
    return 0;
}

// 0x0065C730
static const D2PropertyStrc* ITEMMODS_GetModsProperty(int nType, const void* pMods, int nMod, int nPropSet)
{
    switch (nType)
    {
    case 0:
        return ITEMMODS_GetAffixProperty((const D2MagicAffixTxt*)pMods, nMod);
    case 1:
        return ITEMMODS_GetGradeProperty((const D2GradeModsStrc*)pMods, nMod);
    case 2:
        return ITEMMODS_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 5:
        return ITEMMODS_GetGemProperty((const D2GemsTxt*)pMods, nPropSet, nMod);
    case 3:
    case 4:
        return 0;
    case 6:
    case 7:
        return (const D2PropertyStrc*)pMods;
    default:
        D2_ASSERT(0, 0xAF);
        return 0;
    }
}


// 0x0065C7A0
void __stdcall D2Common_10844_ITEMMODS_First(int nDataBits, int* pLayer, int* pValue)
{
    *pLayer = nDataBits & 511;
    *pValue = (nDataBits >> 9) & 31;
}

// 0x0065C7D0
void __stdcall D2Common_10846(int nDataBits, int* a2, int* a3, int* a4, int* a5)
{
    *a2 = nDataBits & 511;
    *a3 = (nDataBits >> 9) & 31;
    *a4 = (nDataBits >> 14) & 255;
    *a5 = (nDataBits >> 22) & 255;
}

D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag); // 0x00625730
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit); // 0x00627220

// 0x0065C820
int __stdcall ITEMMODS_GetItemCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int* pValue, D2StatListStrc** ppStatList)
{
    if (pValue)
    {
        *pValue = 0;
    }

    if (ppStatList)
    {
        *ppStatList = 0;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != 4)
    {
        return 0;
    }

    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || nSkillLevel <= 0 || nSkillLevel > 63)
    {
        return 0;
    }

    const int nLayer = (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff);

    for (D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pItem, 0x40); pStatList; pStatList = STATLIST_GetStatListFromFlag(pStatList, 0x40))
    {
        const int nValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nLayer);
        if (nValue)
        {
            if (pValue)
            {
                *pValue = nValue & 0xFF;
            }

            if (ppStatList)
            {
                *ppStatList = pStatList;
            }

            return 1;
        }
    }

    if (pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            if (ITEMMODS_GetItemCharges(pSocketed, nSkillId, nSkillLevel, pValue, ppStatList))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x0065C940
int __stdcall ITEMMODS_UpdateItemWithSkillCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != 4)
    {
        return 0;
    }

    const int nLayer = (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff);

    for (D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pItem, 0x40); pStatList; pStatList = STATLIST_GetStatListFromFlag(pStatList, 0x40))
    {
        int nValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nLayer);
        if (nValue)
        {
            nValue >>= 8;
            if (nValue > 0 && nValue <= 255)
            {
                nCharges = nCharges > 0 ? nCharges : 0;
                if (nCharges >= nValue)
                {
                    nCharges = nValue;
                }
                STATLIST_SetBaseStat2(pStatList, STAT_ITEM_CHARGED_SKILL, (nValue << 8) + (nCharges & 0xFF), nLayer, pItem);
                return 1;
            }
            return 0;
        }
    }

    if (pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            if (ITEMMODS_UpdateItemWithSkillCharges(pSocketed, nSkillId, nSkillLevel, nCharges))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x0065CA30
int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax)
{
    int nTempItemModPeriodOfDay = nAmount & 3;
    int nTempItemModMin = ((nAmount >> 2) & 0x3FF) - 0x100;
    int nTempItemModMax = ((nAmount >> 12) & 0x3FF) - 0x100;

    if (pItemModPeriodOfDay)
    {
        *pItemModPeriodOfDay = nTempItemModPeriodOfDay;
    }

    if (pItemModMin)
    {
        *pItemModMin = nTempItemModMin;
    }

    if (pItemModMax)
    {
        *pItemModMax = nTempItemModMax;
    }

    int nTimeDiff = nBaseTime - (nTempItemModPeriodOfDay * 90);
    if (nTimeDiff < 0)
    {
        nTimeDiff = -nTimeDiff;
    }

    int nRoundedTimeDiff = ((nTimeDiff + 7) / 15) * 15;

    int nClampedTimeDiff = nRoundedTimeDiff > 0 ? nRoundedTimeDiff : 0;
    if (nClampedTimeDiff >= (360 - 1))
    {
        nClampedTimeDiff = (360 - 1);
    }

    if (nClampedTimeDiff > 180)
    {
        nClampedTimeDiff = 360 - nClampedTimeDiff;
    }

    return nTempItemModMax - (((nTempItemModMax - nTempItemModMin) * nClampedTimeDiff) / 180);
}

// 0x0065CB00
int __stdcall D2Common_10849(int a1, int a2)
{
    return a1 + (a2 << 9);
}

// 0x0065CB10
void __stdcall D2Common_10845(int nDataBits, int* a2, int* a3, int* a4)
{
    *a2 = nDataBits & 511;
    *a3 = (nDataBits >> 9) & 31;
    *a4 = (nDataBits >> 14) & 127;
}

// 0x0065CB40
int __stdcall D2Common_10850(int a1, int a2, int a3)
{
    return a1 + ((a2 + 32 * a3) << 9);
}

// 0x0065CB60
void __stdcall D2Common_10848(int nDataBits, int* pClass, int* pTab, int* pLevel)
{
    IM_ASSERT(pClass && pTab && pLevel, 426);

    int nClassTab = nDataBits & 31;
    *pClass = nClassTab / 3;
    *pTab = nClassTab % 3;
    *pLevel = (nDataBits >> 5) & 31;
}

// 0x0065CBD0
int __stdcall D2Common_10851(int a1, int a2, int a3)
{
    return a2 + 3 * a1 + 32 * a3;
}

// 0x0065CBF0
static D2StatListStrc* __stdcall ITEMMODS_GetOrCreateStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState, int fFilter)
{
    D2StatListStrc* hStatsList;

    if (pUnit)
    {
        hStatsList = sub_00625790_UnitFindStatList(pUnit, nState, fFilter);
        if (!hStatsList)
        {
            int nUnitGUID = pUnit->dwUnitId;
            void* pMemPool = pUnit->pMemoryPool;
            hStatsList = STATLIST_AllocStatList(pMemPool, fFilter, 0, 4, nUnitGUID);
            D2COMMON_10475_PostStatToStatList(pUnit, hStatsList, 1);
            STATLIST_SetState(hStatsList, nState);
        }
    }
    else
    {
        hStatsList = sub_00625790_UnitFindStatList(pItem, nState, fFilter);
        if (!hStatsList)
        {
            hStatsList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, fFilter, 0, 4, !pItem ? -1 : pItem->dwUnitId);
            D2COMMON_10475_PostStatToStatList(pItem, hStatsList, 1);
            STATLIST_SetState(hStatsList, nState);
        }
    }

    D2_ASSERT(hStatsList, 513);
    return hStatsList;
}

int __fastcall sub_0065E070_AddStatTriple(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    int nLayer = pProperty->nLayer;
    const int nStatId1 = nStatId + 1;
    const int nStatId2 = nStatId + 2;
    ITEMMODS_ShiftStatValue(nStatId, &nMin);
    ITEMMODS_ShiftStatValue(nStatId1, &nMax);
    ITEMMODS_ShiftStatValue(nStatId2, &nLayer);
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(pStatList, 1197);
    if (nApplyType)
    {
        nMin = -STATLIST_GetStatValue(pStatList, nStatId, 0);
        nMax = -STATLIST_GetStatValue(pStatList, nStatId1, 0);
        nLayer = -STATLIST_GetStatValue(pStatList, nStatId2, 0);
    }
    STATLIST_AddStat(pStatList, nStatId, nMin, 0);
    STATLIST_AddStat(pStatList, nStatId1, nMax, 0);
    STATLIST_AddStat(pStatList, nStatId2, nLayer, 0);
    if (nStatId == 57)
    {
        STATLIST_AddStat(pStatList, STAT_POISON_COUNT, 1, 0);
    }
    return 1;
}

static inline int IsStatInRange(int nStatId, int nMin, int nMax)
{
    if (nStatId < nMin)
        return 0;
    if (nStatId > nMax)
        return 0;
    return 1;
}

// 0x0065CCA0
static int ITEMMODS_IsPercentArmorOrDamageStat(int nStatId)
{
    if (IsStatInRange(nStatId, 16, 18))
        return 1;
    return 0;
}

// 0x0065CCC0
static void __stdcall ITEMMODS_SetItemBaseStats(D2UnitStrc* pItem, int nStatId)
{
    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (pItemsTxtRecord)
    {
        switch (nStatId)
        {
        case 16:
        case 31:
            if (ITEMSIsA(pItem, 50) && pItemsTxtRecord->dwMaxAc)
            {
                int nValue = STATLIST_GetUnitBaseStat(pItem, STAT_ARMORCLASS, 0) + 1;
                if (nValue <= pItemsTxtRecord->dwMaxAc)
                {
                    nValue = pItemsTxtRecord->dwMaxAc + 1;
                }

                STATLIST_SetUnitStat(pItem, STAT_ARMORCLASS, nValue, 0);
            }
            break;

        case 17:
        case 22:
            if (ITEMSIsA(pItem, 45))
            {
                if (pItemsTxtRecord->nMaxDam)
                {
                    STATLIST_SetUnitStat(pItem, STAT_MAXDAMAGE, pItemsTxtRecord->nMaxDam, 0);
                }

                if (pItemsTxtRecord->n2HandMaxDam)
                {
                    STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MAXDAMAGE, pItemsTxtRecord->n2HandMaxDam, 0);
                }

                if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMaxMisDam)
                {
                    STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MAXDAMAGE, pItemsTxtRecord->nMaxMisDam, 0);
                }
            }
            break;

        case 18:
        case 21:
            if (ITEMSIsA(pItem, 45))
            {
                if (pItemsTxtRecord->nMinDam)
                {
                    STATLIST_SetUnitStat(pItem, STAT_MINDAMAGE, pItemsTxtRecord->nMinDam, 0);
                }

                if (pItemsTxtRecord->n2HandMinDam)
                {
                    STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MINDAMAGE, pItemsTxtRecord->n2HandMinDam, 0);
                }

                if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMinMisDam)
                {
                    STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MINDAMAGE, pItemsTxtRecord->nMinMisDam, 0);
                }
            }
            break;

        default:
            return;
        }
    }
}

// 0x0065CE40
static void ITEMMODS_ShiftStatValue(int nStatId, int* pValue)
{
    switch (nStatId)
    {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 216:
    case 217:
        *pValue <<= 8;
        break;

    case 57:
    case 58:
        break;

    default:
        return;
    }
}

// 0x0065CF40
static int __stdcall ITEMMODS_AddRolledStatEx(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int a7, int nState, int fStatList)
{
    int nValue;
    if (a7)
    {
        nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
    }
    else
    {
        nValue = ITEMMODS_RollPropertyValueA(pItem, pProperty->nMin, pProperty->nMax);
        if (nType != 1)
        {
            goto skip_base;
        }
    }
    ITEMMODS_SetItemBaseStats(pItem, nStatId);
skip_base:

    if (!nValue)
    {
        return 0;
    }

    ITEMMODS_ShiftStatValue(nStatId, &nValue);
    D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(hStatsList, 669);
    if (nApplyType)
    {
        nValue = -STATLIST_GetStatValue(hStatsList, nStatId, 0);
    }
    STATLIST_AddStat(hStatsList, nStatId, nValue, 0);
    if (nStatId == 58)
    {
        STATLIST_AddStat(hStatsList, STAT_POISON_COUNT, 1, 0);
    }
    return 1;
}

// 0x0065D070
static __declspec(noinline) int __stdcall ITEMMODS_AddValueStatEx(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int a7, int nState, int fStatList)
{
    if (a7 || nType == 1)
    {
        ITEMMODS_SetItemBaseStats(pItem, nStatId);
    }
    if (!nValue)
    {
        return 0;
    }
    ITEMMODS_ShiftStatValue(nStatId, &nValue);
    D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(hStatsList, 709);
    if (nApplyType)
    {
        nValue = -STATLIST_GetStatValue(hStatsList, nStatId, 0);
    }
    STATLIST_AddStat(hStatsList, nStatId, nValue, 0);
    return 1;
}

// 0x0065D110
int __fastcall ITEMMODS_AssignLayerStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 738);
    int nValue = ptProperty->nLayer;
    if (!nValue)
    {
        return 0;
    }
    if (nStatId >= 16 && nStatId <= 18 || nType == 1)
    {
        ITEMMODS_SetItemBaseStats(pItem, nStatId);
    }
    ITEMMODS_ShiftStatValue(nStatId, &nValue);
    D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(hStatsList, 752);
    if (nApplyType)
    {
        nValue = -STATLIST_GetStatValue(hStatsList, nStatId, 0);
    }
    STATLIST_AddStat(hStatsList, nStatId, nValue, 0);
    return 1;
}

// 0x0065D1C0
int __fastcall ITEMMODS_AssignRolledStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, pProperty, nStatId, nApplyType, 0, nState, fStatList);
}

// 0x0065D1F0
static int __stdcall ITEMMODS_AddValueStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, nStatId, nApplyType, 0, nState, fStatList);
}

inline const D2PropertiesTxt* DATATBLS_GetPropertiesTxtRecord(int nProperty)
{
    if (nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
    {
        return &sgptDataTables->pPropertiesTxt[nProperty];
    }

    return 0;
}

// 0x0065E600
static inline int ITEMMODS_GetSetItemsCountFromMask(unsigned int nMask)
{
    if (nMask >= 0x40)
        return 0;
// build: symbol ?gnSetItemsCount@* 0x006EDA40
    return gnSetItemsCount[nMask];
}

static inline int ITEMMODS_RollPropertyValueA(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

static inline int ITEMMODS_RollPropertyValueB(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMin == nMax)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    int nPossibleRolls;
    if (ITEMS_GetItemFormat(pItem) < 1)
    {
        nPossibleRolls = nMax - nMin;
    }
    else
    {
        nPossibleRolls = nMax - nMin + 1;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
}

int __fastcall IsPercentStatContext(const int* pStatId)
{
    return ITEMMODS_IsPercentArmorOrDamageStat(*pStatId);
}

// 0x0065E4D0
void __stdcall ITEMMODS_ApplyEthereality(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1798);

    ITEMS_SetItemFlag(hItem, 0x400000, 1);

    if (ITEMSIsA(hItem, 45))
    {
        STATLIST_SetUnitStat(hItem, STAT_MINDAMAGE, 3 * STATLIST_GetUnitBaseStat(hItem, STAT_MINDAMAGE, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, STAT_MAXDAMAGE, 3 * STATLIST_GetUnitBaseStat(hItem, STAT_MAXDAMAGE, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, STAT_SECONDARY_MINDAMAGE, 3 * STATLIST_GetUnitBaseStat(hItem, STAT_SECONDARY_MINDAMAGE, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, STAT_SECONDARY_MAXDAMAGE, 3 * STATLIST_GetUnitBaseStat(hItem, STAT_SECONDARY_MAXDAMAGE, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, STAT_ITEM_THROW_MINDAMAGE, 3 * STATLIST_GetUnitBaseStat(hItem, STAT_ITEM_THROW_MINDAMAGE, 0) / 2, 0);
        STATLIST_SetUnitStat(hItem, STAT_ITEM_THROW_MAXDAMAGE, 3 * STATLIST_GetUnitBaseStat(hItem, STAT_ITEM_THROW_MAXDAMAGE, 0) / 2, 0);
    }
    else
    {
        STATLIST_SetUnitStat(hItem, STAT_ARMORCLASS, 3 * STATLIST_GetUnitBaseStat(hItem, STAT_ARMORCLASS, 0) / 2, 0);
    }
}

// 0x0065D220
int __fastcall ITEMMODS_AssignSockets(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 786);

    ITEMS_SetItemFlag(pItem, 0x800, 1);
    ITEMS_AddSockets(pItem, ptProperty->nLayer);

    return 1;
}

// 0x0065D270
int __fastcall ITEMMODS_AssignIndestructible(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2UnitStrc* pTarget = a9;
    if (!pTarget || pTarget->dwUnitType != UNIT_ITEM)
    {
        pTarget = pItem;
    }

    STATLIST_SetUnitStat(pTarget, MAX_DURABILITY, 0, 0);
    STATLIST_SetUnitStat(pTarget, DURABILITY, 0, 0);
    return 1;
}

// 0x0065D2B0
int __fastcall ITEMMODS_AssignRolledStatForceBase(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, pProperty, nStatId, nApplyType, 1, nState, fStatList);
}

// 0x0065D2E0
static int __stdcall ITEMMODS_AddValueStatForceBase(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue, int nStatId, int nApplyType, int nState, int fStatList)
{
    return ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, nStatId, nApplyType, 1, nState, fStatList);
}

// 0x0065D310
int __fastcall ITEMMODS_AssignAllResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(ptProperty, 841);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, ptProperty->nMin, ptProperty->nMax);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 39, nApplyType, nState, fStatList);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 41, nApplyType, nState, fStatList);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 43, nApplyType, nState, fStatList);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 45, nApplyType, nState, fStatList);
    }
    else
    {
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 39, nApplyType, 0, nState, fStatList);
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 41, nApplyType, 0, nState, fStatList);
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 43, nApplyType, 0, nState, fStatList);
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 45, nApplyType, 0, nState, fStatList);
    }
    return nStatId;
}

// 0x0065D4B0
int __fastcall ITEMMODS_AssignAllMaxResist(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(ptProperty, 868);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, ptProperty->nMin, ptProperty->nMax);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 40, nApplyType, nState, fStatList);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 42, nApplyType, nState, fStatList);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 44, nApplyType, nState, fStatList);
        ITEMMODS_AddValueStat(nType, pUnit, pItem, nValue, 46, nApplyType, nState, fStatList);
    }
    else
    {
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 40, nApplyType, 0, nState, fStatList);
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 42, nApplyType, 0, nState, fStatList);
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 44, nApplyType, 0, nState, fStatList);
        ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 46, nApplyType, 0, nState, fStatList);
    }
    return nStatId;
}

// 0x0065D650
int __fastcall ITEMMODS_AssignMinDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 891);
    const int nValue = ITEMMODS_RollPropertyValueB(pItem, ptProperty->nMin, ptProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = ITEMMODS_GetItemsTxtRecordFromUnitOrItem(pUnit, pItem);
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMinDam || !pItemsTxtRecord->n2HandMinDam)
    {
        ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, 21, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMinDam || !pItemsTxtRecord->nMinDam)
    {
        ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, 23, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, 159, nApplyType, 0, nState, fStatList);
    }
    return 1;
}

// 0x0065D7D0
int __fastcall ITEMMODS_AssignMaxDamage(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty, 919);
    const int nValue = ITEMMODS_RollPropertyValueB(pItem, ptProperty->nMin, ptProperty->nMax);
    D2ItemsTxt* pItemsTxtRecord = ITEMMODS_GetItemsTxtRecordFromUnitOrItem(pUnit, pItem);
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
    {
        ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, 22, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMinDam)
    {
        ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, 24, nApplyType, 0, nState, fStatList);
    }
    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        ITEMMODS_AddValueStatEx(nType, pUnit, pItem, nValue, 160, nApplyType, 0, nState, fStatList);
    }
    return 1;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (!(nSkillId >= 0))
        return 0;
    if (!(nSkillId < sgptDataTables->nSkillsTxtRecordCount))
        return 0;
    return &sgptDataTables->pSkillsTxt[nSkillId];
}

// 0x0065D950
int __fastcall ITEMMODS_AssignDamagePercent(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2_ASSERT(ptProperty, 949);
        const int nValue = ITEMMODS_RollPropertyValueA(pItem, ptProperty->nMin, ptProperty->nMax);
        D2ItemsTxt* pItemsTxtRecord = ITEMMODS_GetItemsTxtRecordFromUnitOrItem(pUnit, pItem);
        D2_ASSERT(pItemsTxtRecord, 960);
        unsigned char nMaxDam8 = pItemsTxtRecord->n2HandMaxDam;
        if (nMaxDam8 <= pItemsTxtRecord->nMaxDam)
        {
            nMaxDam8 = pItemsTxtRecord->nMaxDam;
        }
        const int nMaxDam = nMaxDam8;
        if (ITEMSIsA(pItem, 45) && nMaxDam + (nValue * nMaxDam) / 100 <= nMaxDam)
        {
            if (pItemsTxtRecord->nMinDam)
            {
                ITEMMODS_AddValueStat(nType, pUnit, pItem, 1, 22, nApplyType, nState, fStatList);
            }
            if (pItemsTxtRecord->n2HandMinDam)
            {
                ITEMMODS_AddValueStat(nType, pUnit, pItem, 1, 24, nApplyType, nState, fStatList);
            }
            if (ITEMS_CheckIfThrowable(pItem))
            {
                ITEMMODS_AddValueStat(nType, pUnit, pItem, 1, 160, nApplyType, nState, fStatList);
            }
            return nStatId;
        }
        ITEMMODS_AddValueStatForceBase(nType, pUnit, pItem, nValue, 17, nApplyType, nState, fStatList);
        ITEMMODS_AddValueStatForceBase(nType, pUnit, pItem, nValue, 18, nApplyType, nState, fStatList);
        return nStatId;
    }
    ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 17, nApplyType, 1, nState, fStatList);
    ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, ptProperty, 18, nApplyType, 1, nState, fStatList);
    return nStatId;
}

// 0x0065DB90
int __fastcall ITEMMODS_AssignAllSkills(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    ITEMMODS_AddRolledStatEx(nType, pUnit, pItem, pProperty, 127, nApplyType, 0, nState, fStatList);
    return nStatId;
}

// 0x0065DBC0
int __fastcall ITEMMODS_AssignChargedSkill(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nSkillId = pProperty->nLayer;
    if (SKILLS_GetSkillsTxtRecord(nSkillId))
    {

    int nSkillLevel = pProperty->nMax;
    if (!nSkillLevel)
    {
        nSkillLevel = (ITEMS_GetItemLevel(pItem) - SKILLS_GetRequiredLevel(nSkillId)) / 4 + 1;
        nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), SPELLSEL_GetSkillMaxLevel(nSkillId));
    }
    else if (nSkillLevel < 0)
    {
        const int nRequiredLevel = SKILLS_GetRequiredLevel(nSkillId);
        int nRange = 99 - nRequiredLevel;
        if (nRange < 1)
        {
            nRange = 1;
        }

        int nDivisor = -(nRange / nSkillLevel);
        if (nDivisor < 1)
        {
            nDivisor = 1;
        }

        nSkillLevel = (ITEMS_GetItemLevel(pItem) - nRequiredLevel) / nDivisor;
        if (nSkillLevel <= 0)
        {
            nSkillLevel = 1;
        }
    }

    int nCharges = pProperty->nMin;
    if (!nCharges)
    {
        nCharges = 5;
    }
    else if (nCharges < 0)
    {
        nCharges = -nCharges;
        nCharges += nCharges * nSkillLevel / 8;
    }

    nCharges = D2_MIN(D2_MAX(nCharges, 1), 255);

    const int nCurrent = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nCharges - (nCharges / 8)) + (nCharges / 8) + 1;
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    sub_00627150(pStatList, nStatId, (nCurrent & 0xFF) + (nCharges << 8), (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff));
    return 1;
    }

    return 0;
}

// 0x0065DE40
int __fastcall ITEMMODS_AssignStatPair(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;
    const int nStatId1 = nStatId + 1;
    ITEMMODS_ShiftStatValue(nStatId, &nMin);
    ITEMMODS_ShiftStatValue(nStatId1, &nMax);
    if (nStatId == 21)
    {
        int nClassId;
        if (pUnit && pUnit->dwUnitType == UNIT_ITEM)
        {
            nClassId = pUnit->dwClassId;
        }
        else
        {
            nClassId = !pItem ? -1 : pItem->dwClassId;
        }
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
        if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
        {
            ITEMMODS_AddValueStat(nType, pUnit, pItem, nMin, 21, nApplyType, nState, fStatList);
            ITEMMODS_AddValueStat(nType, pUnit, pItem, nMax, 22, nApplyType, nState, fStatList);
        }
        if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMinDam)
        {
            ITEMMODS_AddValueStat(nType, pUnit, pItem, nMin, 23, nApplyType, nState, fStatList);
            ITEMMODS_AddValueStat(nType, pUnit, pItem, nMax, 24, nApplyType, nState, fStatList);
        }
        if (ITEMS_CheckIfThrowable(pItem))
        {
            ITEMMODS_AddValueStat(nType, pUnit, pItem, nMin, 159, nApplyType, nState, fStatList);
            ITEMMODS_AddValueStat(nType, pUnit, pItem, nMax, 160, nApplyType, nState, fStatList);
        }
    }
    else
    {
        D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
        D2_ASSERT(hStatsList, 1157);
        if (nApplyType)
        {
            nMin = -STATLIST_GetStatValue(hStatsList, nStatId, 0);
            nMax = -STATLIST_GetStatValue(hStatsList, nStatId1, 0);
        }
        STATLIST_AddStat(hStatsList, nStatId, nMin, 0);
        STATLIST_AddStat(hStatsList, nStatId1, nMax, 0);
        if (nStatId == 57)
        {
            STATLIST_AddStat(hStatsList, STAT_POISON_COUNT, 1, 0);
        }
    }
    return 1;
}

// 0x0065E070
int __fastcall ITEMMODS_AssignStatTriple(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{

    const int nMinValue = (nStatId == (int)pProperty) ? pProperty->nMin : pProperty->nMin;
    int nMin = nMinValue;
    const int nMaxValue = pProperty->nMax;
    int nLayer = pProperty->nLayer;
    int nMax = nStatId ? nMaxValue : nMaxValue;
    _ReadWriteBarrier();
    const int nStatId1 = nStatId + 1;
    const int nStatId2 = nStatId + 2;
    ITEMMODS_ShiftStatValue(nStatId, &nMin);
    ITEMMODS_ShiftStatValue(nStatId1, &nMax);
    ITEMMODS_ShiftStatValue(nStatId2, &nLayer);

    D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(hStatsList, 1197);
    if (nApplyType)
    {
        nMin = -STATLIST_GetStatValue(hStatsList, nStatId, 0);
        nMax = -STATLIST_GetStatValue(hStatsList, nStatId1, 0);
        nLayer = -STATLIST_GetStatValue(hStatsList, nStatId2, 0);
    }
    STATLIST_AddStat(hStatsList, nStatId, nMin, 0);
    STATLIST_AddStat(hStatsList, nStatId1, nMax, 0);
    STATLIST_AddStat(hStatsList, nStatId2, nLayer, 0);
    if (nStatId == 57)
    {
        STATLIST_AddStat(hStatsList, STAT_POISON_COUNT, 1, 0);
    }
    return 1;
}

// 0x0065E170
int __fastcall ITEMMODS_AssignSingleSkill(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nPropertyId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    if (!pProperty)
    {
        return 0;
    }

    int nValue;
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;

    if (nMin == nMax)
    {
        nValue = nMin;
    }
    else
    {
        if (nMax < nMin)
        {
            const int nTemp = nMax;
            nMax = nMin;
            nMin = nTemp;
        }

        int nPossibleRolls;
        if (ITEMS_GetItemFormat(pItem) < 1)
        {
            nPossibleRolls = nMax - nMin;
        }
        else
        {
            nPossibleRolls = nMax - nMin + 1;
        }

        nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    if (nApplyType)
    {
        nValue = -STATLIST_GetBaseStatValueByLayer(pStatList, 107, nSkillId);
    }

    STATLIST_AddStat(pStatList, STAT_ITEM_SINGLESKILL, nValue, nSkillId);
    return 1;
}

// 0x0065E230
int __fastcall ITEMMODS_AssignElemSkill(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nValue;
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;

    if (nMin == nMax)
    {
        nValue = nMin;
    }
    else
    {
        if (nMax < nMin)
        {
            const int nTemp = nMax;
            nMax = nMin;
            nMin = nTemp;
        }

        int nPossibleRolls;
        if (ITEMS_GetItemFormat(pItem) < 1)
        {
            nPossibleRolls = nMax - nMin;
        }
        else
        {
            nPossibleRolls = nMax - nMin + 1;
        }

        nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    if (!nValue)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    if (nApplyType)
    {
        nValue = -STATLIST_GetBaseStatValueByLayer(pStatList, 126, 1);
    }

    STATLIST_AddStat(pStatList, STAT_ITEM_ELEMSKILL, nValue, 1);
    return 1;
}

// 0x0065E2D0
int __fastcall ITEMMODS_AssignClassSkills(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nPropertyId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    int nValue;
    int nMin = pProperty->nMin;
    int nMax = pProperty->nMax;

    if (nMin == nMax)
    {
        nValue = nMin;
    }
    else
    {
        if (nMax < nMin)
        {
            const int nTemp = nMax;
            nMax = nMin;
            nMin = nTemp;
        }

        int nPossibleRolls;
        if (ITEMS_GetItemFormat(pItem) < 1)
        {
            nPossibleRolls = nMax - nMin;
        }
        else
        {
            nPossibleRolls = nMax - nMin + 1;
        }

        nValue = nMin + ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nPossibleRolls);
    }

    if (!nValue)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    int nClass = 0;
    switch (nPropertyId)
    {
    case 83:
        nClass = 0;
        break;
    case 84:
        nClass = 1;
        break;
    case 85:
        nClass = 2;
        break;
    case 86:
        nClass = 3;
        break;
    case 87:
        nClass = 4;
        break;
    case 179:
        nClass = 5;
        break;
    case 180:
        nClass = 6;
        break;
    }

    if (nApplyType)
    {
        nValue = -STATLIST_GetBaseStatValueByLayer(pStatList, 83, nClass);
    }

    STATLIST_AddStat(pStatList, STAT_ITEM_ADDCLASSSKILLS, nValue, nClass);
    return 1;
}

// 0x0065E440
int __fastcall ITEMMODS_AssignNothing(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    return 1;
}

// 0x0065E450
int __fastcall ITEMMODS_AssignRangeStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    const int nMin = ITEMMODS_RollPropertyValueB(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddValueStat(nType, pUnit, pItem, nMin, nStatId, nApplyType, nState, fStatList);
}

// 0x0065DD80
int __fastcall ITEMMODS_AssignByTimeStat(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* ptProperty, int nStatId, int nApplyType, int nState, int fStatList, D2UnitStrc* a9)
{
    D2_ASSERT(ptProperty->nMin <= ptProperty->nMax, 0x444);
    int nPeriod = ptProperty->nLayer;
    int nMin = ptProperty->nMin + 256;
    int nMax = ptProperty->nMax + 256;
    D2StatListStrc* hStatsList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    D2_ASSERT(hStatsList, 0x44A);
    D2_ASSERT(nPeriod >= 0 && nPeriod <= 3, 0x44C);
    D2_ASSERT(nMin >= 0 && nMin < (1 << 10), 0x44D);
    D2_ASSERT(nMax >= 0 && nMax < (1 << 10), 0x44E);
    STATLIST_SetStat(hStatsList, nStatId, nPeriod + 4 * (nMin + (nMax << 10)), 0);
    return 1;
}

int __fastcall sub_M115_Emit_0065E600(unsigned int nMask)
{
    return ITEMMODS_GetSetItemsCountFromMask(nMask);
}

// 0x0065E610
void __stdcall ITEMMODS_Nop(int a1, int a2, int a3)
{
}

// 0x0065E620
int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc* pItem, const D2MagicAffixTxt* pMagicAffixTxtRecord)
{
    if (ITEMS_GetItemFormat(pItem) < 100 && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem)))
    {
        return 0;
    }

    if (!(ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0))
    {
        const int nProperty = pMagicAffixTxtRecord->pProperties[0].nProperty;
        if (nProperty >= 0)
        {
            const D2PropertiesTxt* pPropertiesTxtRecord = DATATBLS_GetPropertiesTxtRecord(nProperty);
            if (!pPropertiesTxtRecord || pPropertiesTxtRecord->wStat[0] == 194)
            {
                return 0;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pMagicAffixTxtRecord->wEType[i] <= 0)
        {
            break;
        }

        if (ITEMSIsA(pItem, pMagicAffixTxtRecord->wEType[i]))
        {
            return 0;
        }
    }

    for (int i = 0; i < 7; ++i)
    {
        if (pMagicAffixTxtRecord->wIType[i] <= 0)
        {
            break;
        }

        if (ITEMSIsA(pItem, pMagicAffixTxtRecord->wIType[i]))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0065E710
int __stdcall ITEMMODS_CanItemHaveRareAffix(D2UnitStrc* pItem, const D2RareAffixTxt* pRareAffixTxtRecord)
{
    if (ITEMS_GetItemFormat(pItem) < 100 && (ITEMS_CheckIfStackable(pItem) || ITEMS_CheckIfThrowable(pItem)))
    {
        return 0;
    }

    if (pRareAffixTxtRecord->wVersion >= 100 && ITEMS_GetItemFormat(pItem) < 100)
    {
        return 0;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (pRareAffixTxtRecord->wEType[i] <= 0)
        {
            break;
        }

        if (ITEMSIsA(pItem, pRareAffixTxtRecord->wEType[i]))
        {
            return 0;
        }
    }

    for (int i = 0; i < 7; ++i)
    {
        if (pRareAffixTxtRecord->wIType[i] <= 0)
        {
            break;
        }

        if (ITEMSIsA(pItem, pRareAffixTxtRecord->wIType[i]))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0065E7D0
int __stdcall ITEMMODS_CanItemBeHighQuality(D2UnitStrc* pItem, const D2QualityItemsTxt* pQualityItemsTxtRecord)
{
    D2ItemTypeCheckStrc pItemTypeCheck[9] =
    {
        { pQualityItemsTxtRecord->nShield, 2 },
        { pQualityItemsTxtRecord->nScepter, 24 },
        { pQualityItemsTxtRecord->nWand, 25 },
        { pQualityItemsTxtRecord->nStaff, 26 },
        { pQualityItemsTxtRecord->nBow, 27 },
        { pQualityItemsTxtRecord->nBow, 35 },
        { pQualityItemsTxtRecord->nBoots, 15 },
        { pQualityItemsTxtRecord->nGloves, 16 },
        { pQualityItemsTxtRecord->nBelt, 19 },
    };

    const int nItemType = ITEMS_GetItemType(pItem);

    if (pQualityItemsTxtRecord->nWeapon && ITEMSIsA(pItem, 45) && nItemType != ITEMTYPE_STAFF && nItemType != ITEMTYPE_BOW && nItemType != ITEMTYPE_CROSSBOW && nItemType != ITEMTYPE_SCEPTER && nItemType != ITEMTYPE_WAND)
    {
        return 1;
    }

    if (pQualityItemsTxtRecord->nArmor && ITEMSIsA(pItem, 50) && nItemType != ITEMTYPE_SHIELD && nItemType != ITEMTYPE_BOOTS && nItemType != ITEMTYPE_GLOVES && nItemType != ITEMTYPE_BELT)
    {
        return 1;
    }

    for (unsigned int i = 0; i < sizeof(pItemTypeCheck) / sizeof(pItemTypeCheck[0]); ++i)
    {
        if (nItemType == pItemTypeCheck[i].nItemType && pItemTypeCheck[i].bItemType)
        {
            return 1;
        }
    }

    return 0;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
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

// 0x0065E8E0
void __stdcall ITEMMODS_SetRandomElixirFileIndex(D2UnitStrc* pItem)
{
    const int nCount = gnItemFileIndexCount;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
    const int nIndex = SEED_RollLimitedRandomNumber_Inline(pSeed, nCount);
    ITEMS_SetFileIndex(pItem, gaItemFileIndices[nIndex]);

    const int nFileIndex = gaItemFileIndices[nIndex];
    int nValue;
    if (nFileIndex == 9)
    {
        nValue = ((SEED_RollRandomNumber(ITEMS_GetItemSeed(pItem)) & 3) + 1) << 8;
    }
    else if (nFileIndex == 7)
    {
        nValue = ((SEED_RollRandomNumber(ITEMS_GetItemSeed(pItem)) & 3) + 1) << 8;
    }
    else
    {
        nValue = 1;
    }
    STATLIST_SetUnitStat(pItem, STAT_VALUE, nValue, 0);
}

// 0x0065E9B0
D2ItemsTxt* __fastcall ITEMMODS_GetItemsTxtRecordFromUnitOrItem(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit && pUnit->dwUnitType == UNIT_ITEM)
    {
        return DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
    }
    return DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
}

// 0x0065E9E0
int __fastcall ITEMMODS_RollRandomValueInRange(D2UnitStrc* pItem, int nMin, int nMax)
{
    if (nMax == nMin)
    {
        return nMin;
    }
    if (nMax < nMin)
    {
        const int nTemp = nMax;
        nMax = nMin;
        nMin = nTemp;
    }
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);
        if (nMin >= nMax)
        {
            return nMin;
        }
        return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
    }
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nMax - nMin + 1);
}

// 0x0065EA50
int __fastcall ITEMMODS_AddPropertyToItemStatList(D2UnitStrc* pItem, int fStatList, D2UnitStrc* pUnit, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!nValue)
    {
        return 0;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    if (nSet)
    {
        const unsigned char nShift = pItemStatCostTxtRecord->nValShift;
        // volatile: the original reads nValue from its stack slot here
        STATLIST_SetStatIfListIsValid(pStatList, nStatId, (*(int volatile*)&nValue) << nShift, nLayer);

        if (nStatId == STAT_POISONMAXDAM && !STATLIST_GetStatValue(pStatList, STAT_POISON_COUNT, 0))
        {
            STATLIST_SetStatIfListIsValid(pStatList, STAT_POISON_COUNT, 1, 0);
        }
    }
    else
    {
        STATLIST_AddStat(pStatList, nStatId, nValue << pItemStatCostTxtRecord->nValShift, nLayer);

        if (nStatId == STAT_POISONMAXDAM)
        {
            STATLIST_AddStat(pStatList, STAT_POISON_COUNT, 1, 0);
        }
    }

    return nValue;
}

// 0x0065EB30
int __fastcall ITEMMODS_PropertyFunc01(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM && nType == 1)
    {
        ITEMMODS_SetItemBaseStats(pItem, nStatId);
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065EBA0
int __fastcall ITEMMODS_PropertyFunc02(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        ITEMMODS_SetItemBaseStats(pItem, nStatId);
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065EC10
int __fastcall ITEMMODS_PropertyFunc03(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM && nType == 1)
    {
        ITEMMODS_SetItemBaseStats(pItem, nStatId);
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065EC80
int __fastcall ITEMMODS_PropertyFunc04(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        ITEMMODS_SetItemBaseStats(pItem, nStatId);
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065ECF0
int __fastcall ITEMMODS_PropertyFunc05(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != 4)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = ITEMMODS_GetItemsTxtRecordFromUnitOrItem(pUnit, pItem);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    int nStatValue;
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMinDam || !pItemsTxtRecord->n2HandMinDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMinDam > 0)
        {
            if (pItemsTxtRecord->nMinDam + nValue <= 0)
            {
                nStatValue = 1 - pItemsTxtRecord->nMinDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 21, 0, nStatValue, nState);
        }
    }

    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMinDam || !pItemsTxtRecord->nMinDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->n2HandMinDam > 0)
        {
            if (pItemsTxtRecord->n2HandMinDam + nValue <= 0)
            {
                nStatValue = 1 - pItemsTxtRecord->n2HandMinDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 23, 0, nStatValue, nState);
        }
    }

    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMinMisDam > 0)
        {
            if (pItemsTxtRecord->nMinMisDam + nValue <= 0)
            {
                nStatValue = 1 - pItemsTxtRecord->nMinMisDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 159, 0, nStatValue, nState);
        }
    }

    return nValue;
}

// 0x0065EE80
int __fastcall ITEMMODS_PropertyFunc06(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != 4)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = ITEMMODS_GetItemsTxtRecordFromUnitOrItem(pUnit, pItem);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    int nStatValue;
    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->nMaxDam || !pItemsTxtRecord->n2HandMaxDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMaxDam > 0)
        {
            if (pItemsTxtRecord->nMaxDam + nValue <= 0)
            {
                nStatValue = -pItemsTxtRecord->nMaxDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 22, 0, nStatValue, nState);
        }
    }

    if (!ITEMSIsA(pItem, 45) || pItemsTxtRecord->n2HandMaxDam || !pItemsTxtRecord->nMaxDam)
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->n2HandMaxDam > 0)
        {
            if (pItemsTxtRecord->n2HandMaxDam + nValue <= 0)
            {
                nStatValue = -pItemsTxtRecord->n2HandMaxDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 24, 0, nStatValue, nState);
        }
    }

    if (!ITEMSIsA(pItem, 45) || ITEMS_CheckIfThrowable(pItem))
    {
        nStatValue = nValue;
        if (pItemsTxtRecord->nMaxMisDam > 0)
        {
            if (pItemsTxtRecord->nMaxMisDam + nValue <= 0)
            {
                nStatValue = -pItemsTxtRecord->nMaxMisDam;
            }
        }

        if (nStatValue)
        {
            ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 160, 0, nStatValue, nState);
        }
    }

    return nValue;
}

// 0x0065F010
int __fastcall ITEMMODS_PropertyFunc07(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    const int nItemUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nItemUnitType != 4)
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 18, 0, nValue, nState);
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 17, 0, nValue, nState);
        return 1;
    }

    int nClassId;
    if (pUnit && pUnit->dwUnitType == UNIT_ITEM)
    {
        nClassId = pUnit->dwClassId;
    }
    else
    {
        nClassId = pItem->dwClassId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int nItemId;
    D2ItemsTxt* pBaseRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (pBaseRecord && ITEMSIsA(pItem, 45))
    {
        if (pBaseRecord->nMinDam)
        {
            STATLIST_SetUnitStat(pItem, STAT_MINDAMAGE, pBaseRecord->nMinDam, 0);
        }

        if (pBaseRecord->n2HandMinDam)
        {
            STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MINDAMAGE, pBaseRecord->n2HandMinDam, 0);
        }

        if (ITEMS_CheckIfThrowable(pItem) && pBaseRecord->nMinMisDam)
        {
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MINDAMAGE, pBaseRecord->nMinMisDam, 0);
        }
    }

    pBaseRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (pBaseRecord && ITEMSIsA(pItem, 45))
    {
        if (pBaseRecord->nMaxDam)
        {
            STATLIST_SetUnitStat(pItem, STAT_MAXDAMAGE, pBaseRecord->nMaxDam, 0);
        }

        if (pBaseRecord->n2HandMaxDam)
        {
            STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MAXDAMAGE, pBaseRecord->n2HandMaxDam, 0);
        }

        if (ITEMS_CheckIfThrowable(pItem) && pBaseRecord->nMaxMisDam)
        {
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MAXDAMAGE, pBaseRecord->nMaxMisDam, 0);
        }
    }

    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);

    unsigned char nMax = pItemsTxtRecord->n2HandMaxDam;
    if (nMax <= pItemsTxtRecord->nMaxDam)
    {
        nMax = pItemsTxtRecord->nMaxDam;
    }

    const int nMaxDamage = nMax;
    if (ITEMSIsA(pItem, 45) && nMaxDamage + DATATBLS_ApplyRatio(nMaxDamage, nValue, 100) <= nMaxDamage)
    {
        return ITEMMODS_PropertyFunc06(nType, pUnit, pItem, pProperty, nSet, nStatId, 0, 1, nState, fStatList, a11);
    }

    ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 18, 0, nValue, nState);
    ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, 17, 0, nValue, nState);
    return nValue;
}

// 0x0065F2B0
int __fastcall ITEMMODS_PropertyFunc08(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
}

// 0x0065F310
int __fastcall ITEMMODS_PropertyFunc09(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
        if (!nMin)
        {
            return 0;
        }
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nSkillId, nMin, nState);
    }

    return 0;
}

// 0x0065F390
int __fastcall ITEMMODS_PropertyFunc24(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!nValue)
    {
        nValue = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    }

    const int nPropertyLayer = pProperty->nLayer;
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nPropertyLayer, nValue, nState);
}

// 0x0065F3F0
int __fastcall ITEMMODS_PropertyFunc10(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nMin = nValue;
    if (!nValue)
    {
        nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
        if (!nMin)
        {
            return 0;
        }
    }

    const int nSkillLayer = pProperty->nLayer % 3 + 8 * (pProperty->nLayer / 3);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nSkillLayer, nMin, nState);
}

// Skill-on-event property: chance (default 5) and a skill level derived from the item level when the level is 0 or negative.
// 0x0065F470
int __fastcall ITEMMODS_PropertyFunc11(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        int nChance = pProperty->nMin;
        if (nChance <= 0)
        {
            nChance = 5;
        }

        nValue = pProperty->nMax;
        if (nValue == 0)
        {
            const int nRequiredLevel = SKILLS_GetRequiredLevel(nSkillId);
            nValue = (ITEMS_GetItemLevel(pItem) - nRequiredLevel) / 4 + 1;
            nValue = D2_MIN(D2_MAX(nValue, 1), SPELLSEL_GetSkillMaxLevel(nSkillId));
        }
        else if (nValue < 0)
        {
            // not original source: the identical arms only shape register use
            const int nRequiredLevel = (unsigned char)nValue ? SKILLS_GetRequiredLevel(nSkillId) : SKILLS_GetRequiredLevel(nSkillId);
            int nDivisor = 99 - nRequiredLevel;
            if (nDivisor < 1)
            {
                nDivisor = 1;
            }

            nDivisor = -(nDivisor / nValue);
            if (nDivisor < 1)
            {
                nDivisor = 1;
            }

            nValue = (ITEMS_GetItemLevel(pItem) - nRequiredLevel) / nDivisor;
            if (nValue <= 0)
            {
                nValue = 1;
            }
        }

        return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, (nSkillId << 6) + (nValue & 0x3F), nChance, nState);
    }

    return 0;
}

// 0x0065F590
int __fastcall ITEMMODS_PropertyFunc14(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    int nLimit = 6;
    unsigned char nWidth = 0;
    unsigned char nHeight = 0;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    const int nArea = nWidth * nHeight;
    nLimit = MINIMUM(nLimit, nArea);
    if (nLimit <= 0)
    {
        return 0;
    }

    nLimit = MINIMUM(nLimit, ITEMS_GetMaxSockets(pItem));
    int nSockets = nValue;
    if (nSockets <= 0)
    {
        nSockets = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
        if (nSockets <= 0)
        {
            nSockets = pProperty->nLayer;
        }
    }

    nSockets = MINIMUM(MAXIMUM(nSockets, 1), nLimit);
    if (nSockets <= 0)
    {
        return 0;
    }

    ITEMS_SetItemFlag(pItem, SOCKET_FLAG, 1);
    STATLIST_SetUnitStat(pItem, STAT_ITEM_NUMSOCKETS, nSockets, 0);
    return nSockets;
}

// 0x0065F6A0
int __fastcall ITEMMODS_PropertyFunc19(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!pItem)
    {
        return 0;
    }
    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    const int nSkillId = pProperty->nLayer;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || !sub_0045C4B0_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    int nSkillLevel = pProperty->nMax;
    if (nSkillLevel == 0)
    {
        nSkillLevel = (ITEMS_GetItemLevel(pItem) - (SKILLS_GetRequiredLevel(nSkillId))) / 4 + 1;
        nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, 1), SPELLSEL_GetSkillMaxLevel(nSkillId));
    }
    else if (nSkillLevel < 0)
    {
        const int nRequiredLevel = SKILLS_GetRequiredLevel(nSkillId);
        int nDivisor = 99 - nRequiredLevel;
        if (nDivisor < 1)
        {
            nDivisor = 1;
        }

        nDivisor = -(nDivisor / nSkillLevel);
        if (nDivisor < 1)
        {
            nDivisor = 1;
        }

        nSkillLevel = (ITEMS_GetItemLevel(pItem) - nRequiredLevel) / nDivisor;
        if (nSkillLevel <= 0)
        {
            nSkillLevel = 1;
        }
    }

    int nCharges = pProperty->nMin;
    if (nCharges == 0)
    {
        nCharges = 5;
    }
    else if (nCharges < 0)
    {
        nCharges = -nCharges;
        nCharges += nCharges * nSkillLevel / 8;
    }

    nCharges = D2_MIN(D2_MAX(nCharges, 1), 255);

    const int nCurrentCharges = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nCharges - nCharges / 8) + nCharges / 8 + 1;
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    STATLIST_SetStatIfListIsValid(pStatList, nStatId, (nCurrentCharges & 0xFF) + (nCharges << 8), (unsigned short)((nSkillId << sgptDataTables->nStuff) + (sgptDataTables->nShiftedStuff & nSkillLevel)));
    return nCharges;
}

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

// 0x0065F870
int __fastcall ITEMMODS_PropertyFunc18(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    if (!ITEMS_GetItemStatCostTxtRecord(nStatId))
    {
        return 0;
    }

    int nPropLayer = pProperty->nLayer;
    int nMin = pProperty->nMin + 256;
    int nMax = pProperty->nMax + 256;
    nPropLayer = D2_MIN(D2_MAX(nPropLayer, 0), 3);
    nMin = D2_MIN(D2_MAX(nMin, 0), 1023);
    nMax = D2_MIN(D2_MAX(nMax, 0), 1023);

    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetStatIfListIsValid(pStatList, nStatId, nPropLayer + 4 * (nMin + (nMax << 10)), 0);
    return nMax;
}

// 0x0065F960
int __fastcall ITEMMODS_PropertyFunc15(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = pProperty->nMin;
    if (nStatId == 21)
    {
        ITEMMODS_PropertyFunc05(nType, pUnit, pItem, pProperty, nSet, 21, 0, nMin, nState, fStatList, a11);
    }
    else
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
    }

    return nMin;
}

// 0x0065F9D0
int __fastcall ITEMMODS_PropertyFunc16(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMax = pProperty->nMax;
    if (nStatId == 22)
    {
        ITEMMODS_PropertyFunc06(nType, pUnit, pItem, pProperty, nSet, 22, 0, nMax, nState, fStatList, a11);
    }
    else
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMax, nState);
    }

    return nMax;
}

// 0x0065FA40
int __fastcall ITEMMODS_PropertyFunc17(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    int nTemp = pProperty->nLayer;
    if (!nTemp)
    {
        nTemp = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
        if (!nTemp)
        {
            return 0;
        }
    }

    if (nStatId == 22)
    {
        ITEMMODS_PropertyFunc06(nType, pUnit, pItem, pProperty, nSet, 22, 0, nTemp, nState, fStatList, a11);
    }
    else
    {
        ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nTemp, nState);
    }

    return nTemp;
}

static inline D2ItemStatCostTxt* DATATBLS_GetItemStatCostTxtRecordInline(int nStatId)
{
    D2ItemStatCostTxt* pRecord = 0;
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        pRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return pRecord;
}

// 0x0065FAE0
int __fastcall ITEMMODS_PropertyFunc20(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if ((pItem ? pItem->dwUnitType : UNIT_INVALID) != UNIT_ITEM)
        return 0;
    if (!pProperty)
        return 0;
    if (!DATATBLS_GetItemStatCostTxtRecordInline(STAT_ITEM_INDESTRUCTIBLE))
        return 0;
    D2StatListStrc* pStatList = ITEMMODS_GetOrCreateStatList(pUnit, pItem, nState, fStatList);
    if (!pStatList)
        return 0;
    STATLIST_AddStat(pStatList, STAT_ITEM_INDESTRUCTIBLE, 1, 0);
    return 1;
}

// 0x0065FB50
int __fastcall ITEMMODS_PropertyFunc21(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nLayer, nMin, nState);
}

// 0x0065FBA0
int __fastcall ITEMMODS_PropertyFunc36(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nMin, (short)nLayer, nState);
}

// 0x0065FBF0
int __fastcall ITEMMODS_PropertyFunc22(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, (unsigned short)pProperty->nLayer, nMin, nState);
}

// 0x0065FC40
int __fastcall ITEMMODS_PropertyFunc12(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty)
    {
        return 0;
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    return ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, nMin, pProperty->nLayer, nState);
}

// 0x0065FC90
int __fastcall ITEMMODS_PropertyFunc13(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (!pProperty || !pItem)
    {
        return 0;
    }

    if (pItem->dwUnitType == UNIT_ITEM && nType == 1)
    {
        ITEMMODS_SetItemBaseStats(pItem, nStatId);
    }

    const int nMin = ITEMMODS_RollRandomValueInRange(pItem, pProperty->nMin, pProperty->nMax);
    const int nResult = ITEMMODS_AddPropertyToItemStatList(pItem, fStatList, pUnit, pProperty, nSet, nStatId, 0, nMin, nState);
    if (nResult)
    {
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability > 0)
        {
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);
        }

        return nResult;
    }

    return 0;
}

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930

int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem); // 0x0062A8D0

// 0x0065FD20
int __fastcall ITEMMODS_PropertyFunc23(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const D2PropertyStrc* pProperty, int nSet, short nStatId, int nLayer, int nValue, int nState, int fStatList, D2UnitStrc* a11)
{
    if (pProperty && pItem && pItem->dwUnitType == UNIT_ITEM && !ITEMS_IsEthereal(pItem) && ITEMS_HasDurability(pItem))
    {
        ITEMMODS_ApplyEthereality(pItem);
        return 1;
    }

    return 0;
}

// 0x0065FE10
static void __stdcall ITEMMODS_DispatchPropertyAssign(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, int nApplyType, const D2PropertyStrc* ptProperty, int nState, int fStatlist, D2UnitStrc* a11)
{
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        D2COMMON_11292_ItemAssignProperty(nType, pUnit, pItem, pMods, nIndex, nPropSet, ptProperty, nState, fStatlist, a11);
    }
    else
    {
        D2_ASSERT(ptProperty, 0x66D);

        const int nProperty = ptProperty->nProperty;
        if (nProperty != -1 && nProperty >= 0 && nProperty < sgptDataTables->nPropertiesTxtRecordCount)
        {
            ITEMMODS_PROPERTYFN pfAssign = gaPropertyAssignTable[nProperty].pfAssign;
            if (pfAssign)
            {
                pfAssign(nType, pUnit, pItem, ptProperty, gaPropertyAssignTable[nProperty].nStatId, nApplyType, nState, fStatlist, a11);
            }
        }
    }
}

// 0x0065FD70
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10)
{
    if (pProperty)
    {
        const D2PropertiesTxt* pPropertiesTxtRecord = DATATBLS_GetPropertiesTxtRecord(pProperty->nProperty);
        if (pPropertiesTxtRecord)
        {
            int nFirstValue = 0;
            for (int i = 0; i < 7; ++i)
            {
                if (pPropertiesTxtRecord->nFunc[i] >= gnPropertyFunctionCount)
                {
                    break;
                }

                PROPERTYASSIGNFN pfAssign = gpfPropertyFunctions[pPropertiesTxtRecord->nFunc[i]];
                if (!pfAssign)
                {
                    break;
                }

                const int nResult = pfAssign(nType, pUnit, pItem, pProperty, pPropertiesTxtRecord->nSet[i], pPropertiesTxtRecord->wStat[i], pPropertiesTxtRecord->wVal[i], nFirstValue, nState, fStatlist, a10);
                if (!i)
                {
                    nFirstValue = nResult;
                }
            }
        }
    }
}

static inline int SetItemFlag(const D2SetItemsTxt* pRecord, int nIndex)
{
    if (!pRecord->nAddFunc)
        return 0x40;
// build: symbol ?gnSetItemStatlistFlags@* 0x006EDB5C
    return gnSetItemStatlistFlags[nIndex];
}

static inline int SetItemState(const D2SetItemsTxt* pRecord, int nIndex)
{
    if (!pRecord->nAddFunc)
        return 0;
// build: symbol ?gnSetItemStates@* 0x006EDB40
    return gnSetItemStates[nIndex];
}

// 0x0065FEC0
void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType)
{
    int nProperties = 0;
    switch (nType)
    {
    case 0:
    case 2:
    case 5:
        nProperties = 3;
        break;

    case 1:
        nProperties = 2;
        break;

    case 3:
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxtRecord)
            {
                for (int i = 0; i < 12; ++i)
                {
                    ITEMMODS_DispatchPropertyAssign(3, 0, pItem, 0, 0, 0, nApplyType, &pUniqueItemsTxtRecord->pProperties[i], 0, 0x40, 0);
                }
                return;
            }
        }
        break;

    case 4:
    {
        D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (!pSetItemsTxtRecord)
        {
            return;
        }

        if (!ITEMS_GetItemFormat(pItem))
        {
            for (int i = 0; i < 2; ++i)
            {
                ITEMMODS_DispatchPropertyAssign(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pProperties[i], 0, 0x40, 0);
            }
            return;
        }

        for (int i = 0; i < 9; ++i)
        {
            ITEMMODS_DispatchPropertyAssign(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pProperties[i], 0, 0x40, 0);
        }

        for (int i = 0; i < 10; ++i)
        {
            const int nIndex = i / 2 + 2;
            const int nFlag = SetItemFlag(pSetItemsTxtRecord, nIndex);
            const int nState = SetItemState(pSetItemsTxtRecord, nIndex);
            ITEMMODS_DispatchPropertyAssign(4, 0, pItem, 0, 0, 0, nApplyType, &pSetItemsTxtRecord->pPartialBoni[i], nState, nFlag, 0);
        }
        return;
    }
    }

    for (int nMod = 0; nMod < nProperties; ++nMod)
    {
        const D2PropertyStrc* pProperty = ITEMMODS_GetModsProperty(nType, pMods, nMod, nPropSet);
        if (!pProperty || pProperty->nProperty < 0)
        {
            break;
        }

        ITEMMODS_DispatchPropertyAssign(nType, 0, pItem, pMods, nMod, nPropSet, nApplyType, pProperty, 0, 0x40, a2);
    }
}

// 0x006600A0
int __stdcall ITEMMODS_UpdateRuneword(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused)
{
    const D2RunesTxt* pRunesTxtRecord = ITEMS_GetRunesTxtRecordFromItem(pUnit);
    if (!pRunesTxtRecord)
    {
        return 0;
    }

    if (sub_00625790_UnitFindStatList(pUnit, STATE_RUNEWORD, 0x40))
    {
        return 0;
    }

    ITEMS_SetItemFlag(pUnit, 0x4000000, 1);

    for (int i = 0; i < 7; ++i)
    {
        const D2PropertyStrc* pProperty = &pRunesTxtRecord->pProperties[i];
        if (pProperty->nProperty < 0)
        {
            break;
        }

        D2COMMON_11292_ItemAssignProperty(6, pUnit, pItem, 0, i, 0, pProperty, STATE_RUNEWORD, 0x40, 0);
    }

    return 1;
}

// 0x00660120
void __fastcall ITEMMODS_UpdateFullSetBoni(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState)
{
    if (!nState)
    {
        return;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == 4 && ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxtRecord)
        {
// build: symbol ?DATATBLS_GetSetsTxtRecord@* 0x00483410
            D2SetsTxt* pSetsTxtRecord = DATATBLS_GetSetsTxtRecord(pSetItemsTxtRecord->nSetId);
            if (pSetsTxtRecord)
            {
                const unsigned int nMask = ITEMS_GetSetItemsMask(pUnit, pItem, 1);
                int nItems;
                if (nMask >= 0x40)
                {
                    nItems = 0;
                }
                else
                {
                    nItems = gnSetItemsCount[nMask];
                }

                const int nCount = nItems < pSetsTxtRecord->nSetItems - 1 ? nItems : pSetsTxtRecord->nSetItems - 1;
                for (int i = 0; i < 2 * (nCount - 1); ++i)
                {
                    const D2PropertyStrc* pProperty = &pSetsTxtRecord->pBoni2[i];
                    if (pProperty->nProperty >= 0)
                    {
                        ITEMMODS_DispatchPropertyAssign(4, pUnit, pItem, 0, i, 0, 0, pProperty, nState, 0, 0);
                    }
                }

                if (nItems >= pSetsTxtRecord->nSetItems)
                {
                    for (int i = 0; i < 8; ++i)
                    {
                        const D2PropertyStrc* pProperty = &pSetsTxtRecord->pFBoni[i];
                        if (pProperty->nProperty < 0)
                        {
                            break;
                        }

                        ITEMMODS_DispatchPropertyAssign(4, pUnit, pItem, 0, i, 0, 0, pProperty, nState, 0, 0);
                    }
                }
            }
        }
    }
}

// 0x00660240
void __stdcall ITEMMODS_AddCraftPropertyList(D2UnitStrc* pItem, D2PropertyStrc* pProperty, int nUnused)
{
    if (pItem)
    {
        ITEMMODS_DispatchPropertyAssign(7, 0, pItem, pProperty, 0, 0, 0, pProperty, 0, 0x40, 0);
        if (ITEMS_CheckItemFlag(pItem, 0x400000, 0x858, ".\\ITEMS\\ItemMods.cpp"))
        {
            ITEMMODS_ApplyEthereality(pItem);
        }
    }
}

#include "gen/data/Source/D2Common/ITEMS/ItemMods.inc"
