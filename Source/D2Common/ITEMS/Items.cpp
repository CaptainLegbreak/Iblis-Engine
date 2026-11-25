#include "D2ItemTypes.h"
#define STATEMASK_BLUE 18
#include "D2CmpTileRecord.h"
#include "D2GameTypes.h"
#include "D2DrlgMaps.h"
#include "D2CmpTypes.h"
#include "D2LRUNode.h"

#include "D2MonsterIds.h"

#include "D2LevelIds.h"

#include "D2Common.h"

#include "D2ItemModes.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Records.h"

#include "D2ItemsWorld.h"

#include "D2LevelTxt.h"

#include "D2GameRecords.h"

#include "D2TxtTables.h"

#include "D2Primitives.h"

#include "D2TxtItems.h"

#include "D2Txt.h"

#include "D2Path.h"
#include "D2SetsTxt.h"
#include "D2InventoryPair.h"

#define STAT_ITEM_INDESCTRUCTIBLE 152

#define IFLAG_IDENTIFIED 0x00000010

#define NODEPAGE_STORAGE 1

#define NODEPAGE_EQUIP 3

#define INVPAGE_CUBE 3

#define INVPAGE_NULL 255

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

#define IFLAG_ETHEREAL 0x00400000

#define BODYLOC_NONE 0

#define STATEMASK_CURSE 11

#define UNITFLAGEX_ISSHAPESHIFTED_BIT 3

#define STAT_ITEM_NUMSOCKETS 194

#define IFLAG_ISEAR 0x00010000

#define IFLAG_COMPACTSAVE_LOWQUALITY 0x02200000

#define STAT_QUANTITY 0x46

#define STAT_ITEM_THROWABLE 0x7D

#define BODYLOC_SWRARM 11

#define BODYLOC_SWLARM 12

#define ITEMVERSION 0x60

#define IFLAG_NOSELL 0x00001000

#define NUMBER_OF_PLAYERCLASSES 7

#define WEAPONCLASS_HTH 0

#define STAT_DEXTERITY 2

#define STAT_LEVEL 12

struct D2InventoryStrc;

struct D2ItemDataStrc;

struct D2ItemsTxt;

struct D2BooksTxt;

union D2SeedStrc;

struct D2RunesTxt;

struct D2RuneDataTbl;

struct Data00627DF0;

struct Unit00627DF0;

struct Data00627EA0;

struct Unit00627EA0;

struct Data00627EF0;

struct Unit00627EF0;

struct Data00627F50;

struct Unit00627F50;

struct Data00627FB0;

struct Unit00627FB0;

struct Data00627FE0;

struct Unit00627FE0;

struct Data00628040;

struct Unit00628040;

struct Data00628070;

struct Unit00628070;

struct Data00628140;

struct Unit00628140;

struct Data00628250;

struct Unit00628250;

struct D2ItemSaveStrc;

struct Data00629EA0;

struct Unit00629EA0;

struct D2StatesTxt;

struct D2MagicAffixTxt;

struct D2UniqueItemsTxt;

struct D2SetItemsTxt;

struct D2GemsTxt;

struct D2ItemStatCostTxt;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2BitBufferStrc;

struct D2ItemTypesTxt;

struct D2WeaponClassCodeStrc;

struct D2StatStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId); // 0x00628700

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0

int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem); // 0x0063AAF0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

extern D2RuneDataTbl sgtRuneWordsTblDesc; // 0x0096CA98

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

int __fastcall ITEMS_SerializeItem(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bSaveItemInv, int bGamble); // 0x006312B0

int __stdcall STATLIST_CheckState(D2UnitStrc* pUnit, int nState); // 0x00625B70

struct Data00627DF0
{
    unsigned char bUnknown00[0x10];
    unsigned int dwValue10;
};

struct Unit00627DF0
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00627DF0* pData;
};

struct Data00627EA0
{
    unsigned int dwValue00;
};

struct Unit00627EA0
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00627EA0* pData;
};

struct Data00627EF0
{
    unsigned char bUnknown00[0x38];
    unsigned short wValues38[1];
};

struct Unit00627EF0
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00627EF0* pData;
};

struct Data00627F50
{
    unsigned char bUnknown00[0x36];
    unsigned short wValue36;
};

struct Unit00627F50
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00627F50* pData;
};

struct Data00627FB0
{
    unsigned char bUnknown00[0x3E];
    unsigned short wValues3E[1];
};

struct Unit00627FB0
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00627FB0* pData;
};

struct Data00627FE0
{
    unsigned char bUnknown00[0x32];
    unsigned short wValue32;
};

struct Unit00627FE0
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00627FE0* pData;
};

struct Data00628040
{
    unsigned char bUnknown00[0x34];
    unsigned short wValue34;
};

struct Unit00628040
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00628040* pData;
};

struct Data00628070
{
    unsigned char bUnknown00[0x34];
    unsigned short wValue34;
};

struct Unit00628070
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00628070* pData;
};

struct Data00628140
{
    unsigned char bUnknown00[0x14];
    unsigned int dwFlags14;
};

struct Unit00628140
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00628140* pData;
};

struct Data00628250
{
    unsigned char bUnknown00[0x45];
    char cValue45;
};

struct Unit00628250
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00628250* pData;
};

int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode); // 0x00633680

struct Data00629EA0
{
    unsigned char bUnknown00[0x1C];
    unsigned int dwValue1C;
    unsigned int dwValue20;
};

struct Unit00629EA0
{
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwUnknown10;
    Data00629EA0* pData;
};

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex); // 0x00483440

D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStat, int nLayer); // 0x00625500

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

int __fastcall sub_0062B5B0(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062B5B0

unsigned int __stdcall ITEMS_GetWeaponClassCode(D2UnitStrc* pItem); // 0x00628500

void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, D2InventoryStrc* pInventory, char* szPath, int* pWeaponClassCode, int a8, int a9); // 0x0064F5B0

int __stdcall DATATBLS_GetAnimDataInfo(char* szPath, int* pOutLength, int* pOutAnimSpeed, int* pOutFirstFrameTagged); // 0x0066AA80

int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave, unsigned int dwVersion); // 0x0062AE20

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pPlayer, int bEquipping, int* a4, int* a5, int* a6); // 0x0062EAF0

unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit); // 0x00625BB0

unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit); // 0x00625BE0

extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);

unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* pItem); // 0x006287D0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

extern char* gpszDefaultString; // 0x007446E4

static int ITEMS_IsPlainQuality(int nQuality);

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem);

static void __stdcall ITEMS_SetDefenseOrDamage(D2UnitStrc* pItem, int nStat);

struct D2WeaponClassCodeStrc
{
    unsigned int dwCode;
    int nWeaponClassId;
};

extern D2WeaponClassCodeStrc gWeaponClassTable[]; // 0x007446A0

extern unsigned int gnWeaponClassTableCount; // 0x007446E0

int __stdcall ITEMS_IsNotQuestItemByItemId(int nItemId); // 0x00629D40

int __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C560

int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062BA60

inline int ITEMS_CheckItemFlagData_Inl(D2UnitStrc* pItem, unsigned int dwFlag);

unsigned int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

#define LEVEL_LOW 25

#define LEVEL_HIGH 40

int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem);

unsigned char __stdcall ITEMS_GetAllowedGemSocketsFromItemId(int nItemId);

typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];

struct D2MonLvlTxt
{
    char unk0x00[0x78];
};

typedef char check_states_size[(sizeof(D2StatesTxt) == 0x3C) ? 1 : -1];

typedef char check_monlvl_size[(sizeof(D2MonLvlTxt) == 0x78) ? 1 : -1];

typedef char check_skills_size[(sizeof(D2SkillsTxt) == 0x23C) ? 1 : -1];

typedef char check_charstats_size[(sizeof(D2CharStatsTxt) == 0xC4) ? 1 : -1];

typedef char check_pettype_size[(sizeof(D2PetTypeTxt) == 0xE0) ? 1 : -1];

typedef char check_itemtypes_size[(sizeof(D2ItemTypesTxt) == 0xE4) ? 1 : -1];

#define STAT_DURABILITY 72

#define NUM_BODYLOC 13

struct D2GameStrc;

int __stdcall ITEMS_CheckBitField1Flag1(int nItemId); // 0x00629C80

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930

int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840

int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem); // 0x0062A8D0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem); // 0x0062E660

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2NpcTxt
{
    int dwNpc;
    int dwSellMult;
    int dwBuyMult;
    int dwRepMult;
    int dwQuestFlag[3];
    int dwQuestSellMult[3];
    int dwQuestBuyMult[3];
    int dwQuestRepMult[3];
    int nMaxBuy[3];
};

unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo);                               // 0x00627EC0

unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc* pItem);                                             // 0x00627F20

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo);                               // 0x00627F80

unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem);                                               // 0x00628110

unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0

int __fastcall ITEMS_CalculateAdditionalCostsForChargedSkills(D2UnitStrc* pItem, int nBaseCost);                         // 0x00628D30

void __fastcall ITEMS_CalculateAdditionalCostsForBonusStats(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor); // 0x00628E70

int __stdcall STATLIST_GetFullStatsDataFromUnit(D2UnitStrc* pUnit, D2StatStrc* pStatBuffer, int nBufferSize); // 0x00625C30

int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                        // 0x00625560

int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem);                                              // 0x0062A0F0

unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670

int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem);                                                        // 0x0062C060

int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740

D2NpcTxt* __stdcall DATATBLS_GetNpcTxtRecord(unsigned int dwNpcId); // 0x00656900

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

static void __stdcall ITEMS_CalculateAdditionalCostsForSocketables(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost); // 0x006292F0

static void __stdcall ITEMS_CalculateAdditionalCostsForItemSkill(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor); // 0x0062EDD0

int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30

struct D2TimeModStrc
{
    int nPeriodOfDay;
    int nMin;
    int nMax;
};

#define ITEMS_ADD_BONUS_COSTS(nMult, nAdd, nValue, nBuyDiv)                                        \
    if (*pSellCost * (nValue) > 0xFFFF && (nMult))                                          \
    {                                                                                       \
        nSell += *pSellCost * (nValue) / 1024 * (nMult) + (nAdd);                           \
        nBuy += *pBuyCost * (nValue) / (nBuyDiv) * (nMult) + (nAdd);                          \
        tLoop.nRep += *pRepCost * (nValue) / 1024 * (nMult) + (nAdd);                             \
    }                                                                                       \
    else                                                                                    \
    {                                                                                       \
        nSell += (nMult) * *pSellCost * (nValue) / 1024 + (nAdd);                           \
        nBuy += *pBuyCost * (nMult) * (nValue) / (nBuyDiv) + (nAdd);                          \
        tLoop.nRep += *pRepCost * (nMult) * (nValue) / 1024 + (nAdd);                             \
    }

int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem);

#define STAT_MINDAMAGE 21

#define STAT_MAXDAMAGE 22

#define STAT_SECONDARY_MINDAMAGE 23

#define STAT_SECONDARY_MAXDAMAGE 24

#define STAT_ITEM_THROW_MINDAMAGE 159

#define STAT_ITEM_THROW_MAXDAMAGE 160

#define ITEMS_QUALITY_INLINE(p) (((p) && (p)->dwUnitType == UNIT_ITEM && (p)->pItemData) ? (p)->pItemData->dwQualityNo : ITEMQUAL_NORMAL)

int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType); // 0x00629A90

int __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

#define IFLAG_COMPACTSAVE 0x200000

struct D2CoordStrc;

struct D2StaticPathStrc;

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __stdcall ITEMS_GetRealmData(D2UnitStrc* pItem, int* pRealmData0, int* pRealmData1); // 0x00629E40

void __stdcall ITEMS_SerializeItemComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bGamble); // 0x0062FFF0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

static void __stdcall ITEMS_WriteBitsToBitstream(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits); // 0x0062AF50

D2ItemStatCostTxt* __fastcall PLAYER_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x00625790

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0

int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize); // 0x00625C90

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem);                                          // 0x00627FE0

unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem);                                          // 0x00628040

static int __stdcall sub_0062A900_GetSocketedItemCount(D2UnitStrc* pItem);                                  // 0x0062A900

const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem);                             // 0x0062BED0

unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem);                                       // 0x0062E8D0

D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables();                                          // 0x00633ED0

#define ITEMS_WriteBitsInl(nBits, nData, pBuffer) ITEMS_WriteBitsRevInl(pBuffer, nData, nBits)

#define ITEMS_WriteBitsCall(nBits, nData, pBuffer) ITEMS_WriteBitsCallInl(pBuffer, nData, nBits)

static void __stdcall ITEMS_SerializeItemCompact(int bServer, D2UnitStrc* pItem, D2BitBufferStrc* pBuffer); // 0x0062AF80

static int ITEMS_HasSocketedItem(D2UnitStrc* pItem);

int __stdcall ITEMS_IsSocketable(D2UnitStrc* pItem);

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50

void* __fastcall GFXUTIL_GetNextRosterInfo(D2UnitStrc* pUnit);                                         // 0x004DC0B0

void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX);                                          // 0x00620470

void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY);                                          // 0x006204C0

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                       // 0x006252D0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

int __fastcall STATLIST_HasSkillDesc(int nSkillId);                                                     // 0x00627AF0

void __stdcall sub_00627EF0(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo);                    // 0x00627EF0

void __stdcall sub_00627FB0(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo);                    // 0x00627FB0

void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix);                           // 0x00628010

void __stdcall sub_00628070(D2UnitStrc* pItem, unsigned short nSuffix);                                   // 0x00628070

void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0

void __stdcall ITEMS_SetRealmData(D2UnitStrc* pItem, int nRealmData0, int nRealmData1);                         // 0x00629EA0

void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat);                          // 0x0062A6C0

static void __stdcall ITEMS_ReadStatFromItemBitstream(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, D2ItemStatCostTxt* pItemStatCostTxtRecord, int nStatId, unsigned int dwVersion, int n109); // 0x0062AC80

void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets);                                    // 0x0062BE00

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

void __stdcall D2Common_10844_ITEMMODS_First(int nValue, int* pSkillId, int* pSkillValue);                  // 0x0065C7A0

void __stdcall D2Common_10846(int nValue, int* p1, int* p2, int* p3, int* p4);                              // 0x0065C7D0

void __stdcall D2Common_10845(int nValue, int* pSkillId, int* pSkillLevel, int* pChance);                   // 0x0065CB10

void __stdcall D2Common_10848(int nValue, int* pClass, int* pTab, int* pLevel);             // 0x0065CB60

static int __stdcall ITEMS_GetGambleCost(D2UnitStrc* pItem, int nLevel);                             // 0x00629370

int __fastcall ITEMS_CalculateTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType);

#define D2_NORETURN __declspec(noreturn)

#define Min(a,b) ((a) < (b) ? (a) : (b))

#define Max(a,b) ((a) > (b) ? (a) : (b))

struct D2SkillsTxt;

unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc*); // 0x00627F20

int __stdcall DATATBLS_GetMaxLevel(int); // 0x00611830

int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc*, unsigned int); // 0x00463720

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50

static int __fastcall ITEMS_ApplyAffixLevelRequirement(D2MagicAffixTxt*, D2UnitStrc*, int);

typedef int BOOL;

extern "C" const char gszItemsSourceFile[]; // 0x006E1150

static int ITEMS_GetSocketedItemCount(D2UnitStrc* pItem);

#define IFLAG_NEWITEM 0x00080000

#define IFLAG_UNK_GAMBLE 0x02000000

struct D2TimeModStrc;

void __stdcall ITEMS_AssignSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo); // 0x00627FB0

int __stdcall ITEMS_DecodeItemBitstreamComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, int bGamble, int* pSocketedItems, unsigned int dwVersion); // 0x0062CBE0

static int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion);

typedef char check_D2RunesTxt_size[sizeof(D2RunesTxt) == 0x120 ? 1 : -1];

D2RuneDataTbl* __fastcall DATATBLS_GetRuneDataTables(); // 0x00639CB0

static int ITEMS_IsQuantityRepairable(D2UnitStrc* pItem); // 0x0062E5D0

unsigned char* __stdcall ITEMS_GetColor(D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pColor, int nTransType);

static unsigned char ITEMS_PackTransformColor(int nTransform, int nColor);

static void __stdcall ITEMS_GetBonusStatFromSockets(int nStatId, int* pValue, D2UnitStrc* pItem);

#define STATEMASK_BOSSSTAYDEATH 15

void __stdcall STATLIST_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00625A70

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

#define STATEMASK_ACTIVE 5

#define STATEMASK_REMHIT 6

#define STATEMASK_DAMBLUE 7

#define STATEMASK_DAMRED 8

#define STATEMASK_ATTBLUE 9

#define STATEMASK_ATTRED 10

#define STATEMASK_ARMBLUE 19

#define STATEMASK_RFBLUE 20

#define STATEMASK_RCBLUE 21

#define STATEMASK_RLBLUE 22

#define STATEMASK_RPBLUE 23

#define STATEMASK_RFRED 26

#define STATEMASK_RCRED 27

#define STATEMASK_RLRED 28

#define STATEMASK_RPRED 29

#define STATEMASK_EXP 30

#define STATEMASK_SHATTER 31

#define STATEMASK_LIFE 32

#define STATEMASK_UDEAD 33

#define STATEMASK_GREEN 34

#define STATEMASK_CURABLE 12

#define STATEMASK_RESTRICT 17

#define STATEMASK_ARMRED 25

#define INVENTORY_SIGNATURE 0x01020304

struct D2ItemExtraDataStrc;

struct D2InventoryPairStrc;

struct D2InventoryGridStrc;

void __stdcall STATES_UpdateGfxFlagsWithMask(D2UnitStrc* pUnit, unsigned int* pMask); // 0x0063A180


extern "C" int __fastcall sub_0045ADF0_GetX(D2UnitStrc* pItem);

extern "C" int __fastcall sub_0045AE20_GetY(D2UnitStrc* pItem);

extern "C" void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szSource, int nLine); // 0x006286C0

extern "C" void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nCell); // 0x00629ED0

extern "C" void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x006277F0

extern "C" const char gszInventorySource_006EA918;

// 0x00627C90
void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = (D2ItemDataStrc*)sub_0040B430(pMemPool, sizeof(D2ItemDataStrc), ".\\ITEMS\\Items.cpp", 210, 0);
        D2_ASSERT(pItemData, 213);
        memset(pItemData, 0, sizeof(D2ItemDataStrc));
        pItemData->dwOwnerGUID = -1;
        pItem->pItemData = pItemData;
    }
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline unsigned int ITEMS_TestItemFlag(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline unsigned char ITEMS_GetInvPage(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nInvPage;
    }

    return INVPAGE_NULL;
}

// 0x00627D00
void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        INVENTORY_RemoveItem(pItem);
        if (pItem->pItemData)
        {
            FOG_FreeServerMemory(pMemPool, pItem->pItemData, ".\\ITEMS\\Items.cpp", 266, 0);
        }
    }
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x00627D40
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nBodyLoc;
    }

    return BODYLOC_NONE;
}

// 0x00627D70
void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nBodyLoc = nBodyLoc;
    }
}

// 0x00627D90
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return &pItemData->pSeed;
    }

    return 0;
}

// 0x00627DC0
void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        SEED_InitSeed(&pItemData->pSeed);
    }
}

// 0x00627DF0
extern "C" __declspec(dllexport) unsigned int __stdcall ITEMS_GetItemStartSeed(Unit00627DF0* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwValue10;
    }
    return 0;
}

// 0x00627E20
void __stdcall ITEMS_SetItemStartSeed(D2UnitStrc* pItem, int nSeed)
{
    D2_ASSERT(pItem, 391);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 392);
    D2_ASSERT(pItem->pItemData, 395);
    pItem->pItemData->dwInitSeed = nSeed;
}

// 0x00627E70
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return ITEMQUAL_NORMAL;
}

// 0x00627EA0
extern "C" __declspec(dllexport) void __stdcall ITEMS_SetItemQuality(Unit00627EA0* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->dwValue00 = dwValue;
    }
}

// 0x00627EC0
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wMagicPrefix[nPrefixNo];
    }

    return 0;
}

// 0x00627EF0
extern "C" __declspec(dllexport) void __stdcall sub_00627EF0(Unit00627EF0* pUnit, unsigned short wValue, int nIndex) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValues38[nIndex] = wValue;
    }
}

// 0x00627F20
unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wAutoAffix;
    }

    return 0;
}

// 0x00627F50
extern "C" __declspec(dllexport) void __stdcall ITEMS_SetAutoAffix(Unit00627F50* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValue36 = wValue;
    }
}

// 0x00627F80
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wMagicSuffix[nSuffixNo];
    }

    return 0;
}

// 0x00627FB0
extern "C" __declspec(dllexport) void __stdcall sub_00627FB0(Unit00627FB0* pUnit, unsigned short wValue, int nIndex) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValues3E[nIndex] = wValue;
    }
}

// 0x00627FE0
extern "C" __declspec(dllexport) unsigned short __stdcall ITEMS_GetRarePrefixIndex(Unit00627FE0* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue32;
    }
    return 0;
}

// 0x00628010
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->wRarePrefix = nPrefix;
    }
}

// 0x00628040
extern "C" __declspec(dllexport) unsigned short __stdcall ITEMS_GetRareSuffixIndex(Unit00628040* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->wValue34;
    }
    return 0;
}

// 0x00628070
extern "C" __declspec(dllexport) void __stdcall sub_00628070(Unit00628070* pUnit, unsigned short wValue) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        pUnit->pData->wValue34 = wValue;
    }
}

// 0x006280A0
__declspec(noinline) unsigned int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

// 0x006280D0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (bSet)
        {
            pItemData->dwItemFlags |= dwFlag;
        }
        else
        {
            pItemData->dwItemFlags &= ~dwFlag;
        }
    }
}

// 0x00628110
unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->dwItemFlags;
    return 0;
}

// 0x00628140
extern "C" __declspec(dllexport) unsigned int __stdcall ITEMS_CheckItemCMDFlag(Unit00628140* pUnit, unsigned int dwMask) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->dwFlags14 & dwMask;
    }
    return 0;
}

// 0x00628170
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (bSet)
        {
            pItemData->dwCommandFlags |= nFlag;
        }
        else
        {
            pItemData->dwCommandFlags &= ~nFlag;
        }
    }
}

// 0x006281B0
unsigned int __stdcall ITEMS_GetItemCMDFlags(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwCommandFlags;
    }

    return 0;
}

// 0x006281E0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        if (pItemData->dwItemLevel < 1)
        {
            pItemData->dwItemLevel = 1;
        }
        return pItemData->dwItemLevel;
    }

    return 1;
}

inline D2ItemDataStrc* ITEMS_GetItemDataByType(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return (nType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline unsigned int ITEMS_CheckItemFlagInline(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataByType(pItem))
        return pItemData->dwItemFlags & dwFlag;

    return 0;
}

// 0x00628220
void __stdcall ITEMS_SetItemLevel(D2UnitStrc* pItem, int nItemLevel)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataByType(pItem))
    {
        if (nItemLevel < 1)
            nItemLevel = 1;
        pItemData->dwItemLevel = nItemLevel;
    }
}

// 0x00628250
extern "C" __declspec(dllexport) char __stdcall ITEMS_GetInventoryPage(Unit00628250* pUnit) {
    if (pUnit && pUnit->nType == 4 && pUnit->pData) {
        return pUnit->pData->cValue45;
    }
    return -1;
}

// 0x00628280
void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nInvPage = nPage;
    }
}

// 0x006282A0
unsigned char __stdcall ITEMS_GetCellOverlap(D2UnitStrc* pItem) {
 if(D2ItemDataStrc* pItemData=ITEMS_GetItemData(pItem)) return pItemData->nCellOverlap;
 return 0xFF;
}

// 0x006282D0
void __stdcall ITEMS_SetCellOverlap(D2UnitStrc* pItem, int nCellOverlap)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nCellOverlap = nCellOverlap;
    }
}

// 0x006282F0
unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nItemCell;
    }

    return 0xFF;
}

// 0x00628320
void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, int nItemCell)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nItemCell = nItemCell;
    }
}

// 0x00628340
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->szPlayerName;
    }

    return 0;
}

// 0x00628370
void __stdcall ITEMS_SetEarName(D2UnitStrc* pItem, char* szName)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    D2ItemDataStrc* pItemData = pItem->pItemData;
    if (!pItemData)
    {
        return;
    }

    strcpy(pItemData->szPlayerName, szName);
}

// 0x006283A0
unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nEarLvl;
    }

    return 1;
}

// 0x006283D0
void __stdcall ITEMS_SetEarLevel(D2UnitStrc* pItem, unsigned char nLevel)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nEarLvl = nLevel;
    }
}

// 0x006283F0
unsigned char __stdcall ITEMS_GetVarGfxIndex(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->nInvGfxIdx;
    }

    return 0;
}

// 0x00628420
void __stdcall ITEMS_SetVarGfxIndex(D2UnitStrc* pItem, unsigned char nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        pItemData->nInvGfxIdx = nIndex;
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

// build: symbol @GAME_GetStatesTxtRecord@* 0x00452040
extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }

    return 0;
}

extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// build: symbol @MISSILES_GetMonLvlTxtRecord@* 0x005A0000
extern "C" D2MonLvlTxt* __fastcall MISSILES_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// build: symbol @SKILLS_GetSkillsTxtParam7@* 0x005C8BC0
extern "C" int __fastcall SKILLS_GetSkillsTxtParam7(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[6];
}

// 0x00628440
extern "C" int __stdcall ITEMS_GetAmmoTypeFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wShoots;
}

inline int ITEMS_CheckTypeEquivalenceFromLUT(unsigned int* pEquivalenceLUT, int nItemType)
{
    return pEquivalenceLUT[nItemType >> 5] & gdwBitMasks[nItemType & 0x1F];
}

inline unsigned int* ITEMS_TypeEquivalenceLUT(int nItemTypeLUT)
{
    return &sgptDataTables->pItemTypesEquivalenceLUTs[nItemTypeLUT * sgptDataTables->nItemTypesIndex];
}

// 0x00628480
int __stdcall ITEMS_GetQuiverTypeFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->wQuiver;
}

// 0x006284C0
unsigned int __stdcall ITEMS_GetAutoStackFromItemType(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->nAutoStack;
}

// 0x00628500
unsigned int __stdcall ITEMS_GetWeaponClassCode(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord)
        {
            return pItemsTxtRecord->dwWeapClass;
        }
    }

    return 0;
}

// 0x00628530
unsigned int __stdcall ITEMS_Get2HandWeaponClassCode(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1544);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1545);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1548);
    return pItemsTxtRecord->dwWeapClass2Hand;
}

// 0x00628590
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1562);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1563);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1566);
    return pItemsTxtRecord->dwCode;
}

// 0x006285F0
unsigned int __stdcall ITEMS_GetAltGfx(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1575);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1576);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1579);
    if (pItemsTxtRecord->dwAltCode2)
    {
        return pItemsTxtRecord->dwAltCode2;
    }
    else
    {
        return pItemsTxtRecord->dwCode;
    }
}

// 0x00628660
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1588);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1589);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1592);
    return pItemsTxtRecord->nComponent;
}

// 0x006286C0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId))
        {
            *pWidth = pItemsTxtRecord->nInvWidth;
            *pHeight = pItemsTxtRecord->nInvHeight;
        }
    }
}

// 0x00628740
unsigned char __stdcall ITEMS_GetItemQlvl(const D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1686);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1687);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 1690);
    return pItemsTxtRecord->nLevel;
}

// 0x006287A0
extern "C" __declspec(dllexport) unsigned int __stdcall ITEMS_CheckIfFlagIsSet(unsigned int dwA, unsigned int dwB) {
    return dwA & dwB;
}

// 0x006287B0
void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet)
{
    if (bSet)
    {
        *pFlags |= nFlag;
    }
    else
    {
        *pFlags &= ~nFlag;
    }
}

// 0x0062A360
int __stdcall D2COMMON_11079_Return0(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0062BA60
int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    return sub_0062B5B0(pItem, pUnit);
}

// 0x0062BA80
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nThrowable;
        }
    }

    return 0;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwClassId;
    }
    return -1;
}

// 0x0062B400
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1661);

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    return ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
}

// 0x00628700
unsigned int __stdcall ITEMS_GetItemTypeFromItemId(unsigned int dwItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(dwItemId);

    D2_ASSERT(pItemsTxtRecord, 1677);

    return pItemsTxtRecord->wType[0];
}

// 0x006287D0
unsigned int __stdcall ITEMS_GetNormalCode(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 1943);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 1944);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    if (pItemsTxtRecord->dwNormCode)
    {
        return pItemsTxtRecord->dwNormCode;
    }
    else
    {
        return pItemsTxtRecord->dwCode;
    }
}

// 0x00628830
static int __fastcall ITEMS_ApplyAffixLevelRequirement(D2MagicAffixTxt* record, D2UnitStrc* player, int required)
{
    if (!record)
        return required;
    if (record->characterClass != 255 && player && record->characterClass == UNITS_GetWeaponClass(player))
    {
        if (required <= record->classLevelReq)
            required = record->classLevelReq;
    }
    else
    {
        if (required <= record->levelReq)
            required = record->levelReq;
    }
    return required;
}

// 0x00628860
int __stdcall ITEMS_CheckItemTypeIfThrowable(int nItemType)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(nItemType);
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    return pItemTypesTxtRecord->nThrowable;
}

// 0x006288A0
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->wMissileType;
    }

    return -1;
}

// 0x006288D0
unsigned char __stdcall ITEMS_GetMeleeRange(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->nRangeAdder;
    }

    return 0;
}

// 0x00628900
int __stdcall ITEMS_CheckWeaponClassByItemId(int nItemId, int nWeapClass)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 2283);

    return pItemsTxtRecord->dwWeapClass == nWeapClass;
}

// 0x00628950
int __stdcall ITEMS_CheckWeaponClass(D2UnitStrc* pItem, int nWeapClass)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        int nItemId = pItem->dwClassId;
        return ITEMS_CheckWeaponClassByItemId(nItemId, nWeapClass);
    }

    return 0;
}

// 0x00628980
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHandedByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 2310);

    return pItemsTxtRecord->n2Handed;
}

// calling-convention shim (not game code)
int __fastcall sub_00628830_Shim(D2UnitStrc* item, D2UnitStrc* player)
{
    D2MagicAffixTxt* prefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(item, 0));
    D2MagicAffixTxt* suffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(item, 0));
    D2MagicAffixTxt* automatic = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix(item));
    int required = ITEMS_ApplyAffixLevelRequirement(prefix, player, 0);
    required = ITEMS_ApplyAffixLevelRequirement(suffix, player, required);
    required = ITEMS_ApplyAffixLevelRequirement(automatic, player, required);
    return required;
}

// 0x006289C0
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckWeaponIfTwoHandedByItemId(pItem->dwClassId);
    }

    return 0;
}

// 0x006289F0
unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 2338);
        return pItemsTxtRecord->nStackable;
    }

    return 0;
}

// 0x0062BAD0
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nBeltable;
        }
    }

    return 0;
}

// 0x00628A40
int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    static int gdwHealthPotionCodes[] = { 0x20317068, 0x20327068, 0x20337068, 0x20347068, 0x20357068 };  // 0x00744684
    extern unsigned int gnHealthPotionCodeCount; // 0x00744698
    static int gdwManaPotionCodes[] = { 0x2031706D, 0x2032706D, 0x2033706D, 0x2034706D, 0x2035706D };    // 0x0074466C
    extern unsigned int gnManaPotionCodeCount; // 0x00744680
    static int gdwRejuvPotionCodes[] = { 0x206C7672, 0x20737672 };                                       // 0x00744660
    extern unsigned int gnRejuvPotionCodeCount; // 0x00744668

    if (pItem1 && pItem2)
    {
        const int nClassId1 = pItem1->dwClassId;
        const int nClassId2 = pItem2->dwClassId;
        if (nClassId1 == nClassId2)
        {
            return 1;
        }

        {
        D2ItemsTxt* pItemsTxtRecord1 = DATATBLS_GetItemsTxtRecord(nClassId1);
        D2ItemsTxt* pItemsTxtRecord2 = DATATBLS_GetItemsTxtRecord(nClassId2);
        int bPotion1;
        int bPotion2;

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < gnHealthPotionCodeCount; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == gdwHealthPotionCodes[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == gdwHealthPotionCodes[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < gnManaPotionCodeCount; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == gdwManaPotionCodes[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == gdwManaPotionCodes[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }

        bPotion1 = 0;
        bPotion2 = 0;
        for (unsigned int i = 0; i < gnRejuvPotionCodeCount; ++i)
        {
            if (!bPotion1 && pItemsTxtRecord1->dwCode == gdwRejuvPotionCodes[i])
            {
                bPotion1 = 1;
            }
            if (!bPotion2 && pItemsTxtRecord2->dwCode == gdwRejuvPotionCodes[i])
            {
                bPotion2 = 1;
            }
            if (bPotion1 && bPotion2)
            {
                return 1;
            }
        }
        }
        return 0;
    }

    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x00628BA0
int __stdcall ITEMS_CheckIfAutoBeltable(D2InventoryStrc* pInventory, D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0x9A6);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 0x9A7);
    int nClassId = hItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    D2_ASSERT(pItemsTxtRecord, 0x9A9);
    if (pItemsTxtRecord->nAutoBelt || INVENTORY_HasSimilarPotionInBelt(pInventory, hItem) != -1) { return 1; }
    return 0;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    return 0;
}

// 0x00628C20
int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 2500);

        return pItemsTxtRecord->bFlag0x11D;
    }

    return 0;
}

// 0x00628C70
int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 2509);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 2510);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 2513);
    return pItemsTxtRecord->nUnique;
}

// 0x00628CD0
int __stdcall ITEMS_IsQuestItem(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 2522);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 2523);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 2526);
    return pItemsTxtRecord->nQuest;
}

// 0x00628D30
int __fastcall ITEMS_CalculateAdditionalCostsForChargedSkills(D2UnitStrc* pItem, int nBaseCost)
{
    D2StatStrc pStat[64];

    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, pStat, 64);
    int nCost = 0;
    int i = 0;
    if (nStats > 0)
    {
        do
        {
            const int nLayer = pStat[i].nLayer;
            const int nSkillId = nLayer >> sgptDataTables->nStuff;
            const int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
            const int nMaxCharges = pStat[i].nValue >> 8;
            const int nCharges = pStat[i].nValue & 0xFF;
            if (nCharges < nMaxCharges)
            {
                D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inl(nSkillId);
                if (pSkillsTxtRecord)
                {
                    int nChargeCost;
                    if ((nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost > 0xFFFF && pSkillsTxtRecord->nCostMult)
                    {
                        nChargeCost = (nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost / 1024 * pSkillsTxtRecord->nCostMult;
                        nChargeCost += pSkillsTxtRecord->nCostAdd;
                    }
                    else
                    {
                        nChargeCost = pSkillsTxtRecord->nCostMult * (nSkillLevel + 2 * (pSkillsTxtRecord->wReqLevel / 6) + 2) * nBaseCost / 1024;
                        nChargeCost += pSkillsTxtRecord->nCostAdd;
                    }
                    nCost += (nMaxCharges - nCharges) * nChargeCost / nMaxCharges;
                }
            }
            ++i;
        }
        while (i < nStats);
    }

    return nCost;
}

// 0x00628E70
void __fastcall ITEMS_CalculateAdditionalCostsForBonusStats(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor)
{
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    D2StatStrc pStat[511];
    D2TimeModStrc tTimeMod;
    int nStatId = 0;
    int nValue = 0;
    int nStats = 0;
    int nBuy = 0;
    int nSell = 0;
    struct
    {
        int i;
        int nRep;
    } tLoop;
    tLoop.nRep = 0;

    nStats = STATLIST_GetFullStatsDataFromUnit(pItem, pStat, 511);
    for (tLoop.i = 0; tLoop.i < nStats; ++tLoop.i)
    {
        nStatId = pStat[tLoop.i].nStat;
        nValue = STATLIST_GetUnitStatBonus(pItem, nStatId, pStat[tLoop.i].nLayer);
        if (nValue)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
            if (pItemStatCostTxtRecord)
            {
                if (pItemStatCostTxtRecord->nValShift)
                    nValue >>= pItemStatCostTxtRecord->nValShift;

                switch (pItemStatCostTxtRecord->nEncode)
                {
                case 1:
                {
                    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInl(pStat[tLoop.i].nLayer);
                    if (pSkillsTxtRecord)
                    {
                        ITEMS_ADD_BONUS_COSTS(pSkillsTxtRecord->nCostMult, pSkillsTxtRecord->nCostAdd, nValue, 4096);
                    }
                    break;
                }
                case 2:
                case 3:
                {
                    const int nLayer = pStat[tLoop.i].nLayer;
                    const int nSkillId = nLayer >> sgptDataTables->nStuff;
                    const int nLevel = nLayer & sgptDataTables->nShiftedStuff;
                    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInl(nSkillId);
                    ITEMS_ADD_BONUS_COSTS(pSkillsTxtRecord->nCostMult, pSkillsTxtRecord->nCostAdd, nLevel, 4096);
                    break;
                }
                case 4:
                {
                    ITEMMODS_GetByTimeAdjustment(nValue, 0, 0, &tTimeMod.nPeriodOfDay, &tTimeMod.nMin, &tTimeMod.nMax);
                    const int nAverage = (tTimeMod.nMax + tTimeMod.nMin) / 2;
                    ITEMS_ADD_BONUS_COSTS(pItemStatCostTxtRecord->dwMultiply, pItemStatCostTxtRecord->dwAdd, nAverage, 1024);
                    break;
                }
                default:
                    ITEMS_ADD_BONUS_COSTS(pItemStatCostTxtRecord->dwMultiply, pItemStatCostTxtRecord->dwAdd, nValue, 1024);
                    break;
                }
            }
        }
    }

    *pSellCost += nSell / nDivisor;
    *pBuyCost += nBuy / nDivisor;
    *pRepCost += tLoop.nRep / nDivisor;
}

// 0x006292F0
static void __stdcall ITEMS_CalculateAdditionalCostsForSocketables(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost)
{
    int nSellCost = 0;
    int nBuyCost = 0;
    int nRepCost = 0;
    if (pItem->pInventory)
    {
        D2UnitStrc* pSocketable = INVENTORY_GetFirstItem(pItem->pInventory);
        while (pSocketable)
        {
            D2UnitStrc* pSocketItem = INVENTORY_UnitIsItem(pSocketable);
            pSocketable = INVENTORY_GetNextItem(pSocketable);
            if (pSocketItem)
            {
                const int nClassId = pSocketItem->dwClassId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                const int nSocketableCost = pItemsTxtRecord->dwCost / 2;
                nSellCost += nSocketableCost;
                nBuyCost += nSocketableCost;
                nRepCost += nSocketableCost;
            }
        }
        *pSellCost += nSellCost;
        *pBuyCost += nBuyCost;
        *pRepCost += nRepCost;
    }
}

// 0x00629370
static int __stdcall ITEMS_GetGambleCost(int nLevel, D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(DATATBLS_GetItemIdFromItemCode(ITEMS_GetNormalCode(pItem)));
    D2_ASSERT(pItemsTxtRecord, 2842);

    const unsigned int dwUberCode = pItemsTxtRecord->dwUberCode;
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUberItemId = 0;
    int nUltraItemId = 0;
    int nUberChance = 0;
    int nUltraChance = 0;
    int nUberCost = 0;
    int nUltraCost = 0;

    if (pItemsTxtRecord->dwCode == ' nir' || pItemsTxtRecord->dwCode == ' uma')
    {
        return pItemsTxtRecord->dwGambleCost;
    }

    const int nStack = pItemsTxtRecord->dwMaxStack + pItemsTxtRecord->dwMinStack;
    int nCount = nStack / 2;
    if (nCount < 1)
    {
        nCount = 1;
    }

    const int nBaseCost = nCount * pItemsTxtRecord->dwCost;
    const int nItemLevel = pItemsTxtRecord->nLevel;

    if (dwUberCode && pItemsTxtRecord->dwUberCode != '   0')
    {
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            nUberChance = 100 * (nLevel - pUberItemsTxtRecord->nLevel) / 2 + 1;
            if (nUberChance < 0)
            {
                nUberChance = 0;
            }
            nUberCost = pUberItemsTxtRecord->dwCost;
        }
    }

    if (dwUltraCode && pItemsTxtRecord->dwUltraCode != '   0')
    {
        D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
        if (pUltraItemsTxtRecord)
        {
            nUltraChance = 100 * (nLevel - pUltraItemsTxtRecord->nLevel) / 4 + 1;
            if (nUltraChance < 0)
            {
                nUltraChance = 0;
            }
            nUltraCost = pUltraItemsTxtRecord->dwCost;
        }
    }

    const int nBase = (nUberChance * nUberCost + nUltraChance * nUltraCost + nBaseCost * (10000 - nUltraChance - nUberChance)) / 10000;
    if (nLevel <= 5)
    {
        nLevel = 5;
    }

    return ((2 * nLevel + 1) / 3 + 20) * (nBase + (250 * (nLevel + ((nItemLevel - 45) < 0 ? 0 : (nItemLevel - 45)) - nItemLevel / 2)) / 3) / 15;
}

// 0x00629570
int __stdcall ITEMS_GetMaxStack(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3407);

    return pItemsTxtRecord->dwMaxStack;
}

// 0x006295B0
int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3418);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 3419);

    int nMaxStack = ITEMS_GetMaxStack(hItem->dwClassId) + STATLIST_UnitGetStatValue(hItem, 254, 0);
    if (nMaxStack >= 511)
    {
        nMaxStack = 511;
    }

    return nMaxStack;
}

// 0x00629620
int __stdcall ITEMS_GetSpawnStackFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3436);

    return pItemsTxtRecord->dwSpawnStack;
}

// 0x00629660
int __stdcall ITEMS_GetSpawnStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3451);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 3452);

    return ITEMS_GetSpawnStackFromItemId(pItem->dwClassId);
}

// 0x006296B0
int __stdcall ITEMS_GetMinStackFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3466);

    return pItemsTxtRecord->dwMinStack;
}

// 0x006296F0
int __stdcall ITEMS_GetMinStack(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3475);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 3476);

    return ITEMS_GetMinStackFromItemId(pItem->dwClassId);
}

// 0x00629740
int __stdcall ITEMS_CheckBitField1Flag8(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3485);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 3486);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3488);
    return pItemsTxtRecord->dwBitField1 & 8;
}

// 0x006297A0
unsigned char __stdcall ITEMS_GetDurWarnCount(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3523);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 3524);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3526);
    return pItemsTxtRecord->nDurWarning;
}

// 0x0062A0F0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwQualityNo >= ITEMQUAL_MAGIC && pItem->pItemData->dwQualityNo <= ITEMQUAL_TEMPERED;
    }

    return 0;
}

// 0x0062BBD0
int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nStaffMods;
        }
    }

    return 7;
}

// 0x00629800
unsigned char __stdcall ITEMS_GetQtyWarnCount(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3535);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 3536);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 3538);
    return pItemsTxtRecord->nQuantityWarning;
}

// 0x00629860
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord && pItemsTxtRecord->nStrBonus != 1)
        {
            return pItemsTxtRecord->nStrBonus;
        }
    }

    return 100;
}

// 0x006298A0
short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord && pItemsTxtRecord->nDexBonus != 1)
        {
            return pItemsTxtRecord->nDexBonus;
        }
    }

    return 100;
}

// 0x006298E0
int __stdcall ITEMS_CheckIfSocketableByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    return pItemsTxtRecord->nHasInv;
}

// 0x00629900
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckIfSocketableByItemId(pItem->dwClassId);
    }

    return 0;
}

// 0x00629930
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (pItemsTxtRecord && !pItemsTxtRecord->nNoDurability && pItemsTxtRecord->nDurability > 0 && STATLIST_GetMaxDurabilityFromUnit(pItem))
        {
            return STATLIST_UnitGetStatValue(pItem, STAT_ITEM_INDESCTRUCTIBLE, 0) <= 0;
        }
    }

    return 0;
}

// 0x00629990
unsigned char __stdcall ITEMS_GetAllowedGemSocketsFromItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    return pItemsTxtRecord->nGemSockets;
}

// 0x0062BC20
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pType = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (!pType)
            return 0;
        int nSockets = ITEMS_GetAllowedGemSocketsFromItemId(pItem->dwClassId);
        int nLevel = ITEMS_GetItemLevel(pItem);
        int nTypeSockets;
        if (nLevel <= LEVEL_LOW)
            nTypeSockets = pType->nMaxSock1;
        else if (nLevel <= LEVEL_HIGH)
            nTypeSockets = pType->nMaxSock25;
        else
            nTypeSockets = pType->nMaxSock40;
        if (nSockets >= nTypeSockets)
            nSockets = nTypeSockets;
        return (unsigned char)nSockets;
    }
    return 0;
}

// 0x006299B0
int __stdcall ITEMS_GetSockets(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0xEA6);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 0xEA7);
    return STATLIST_UnitGetStatValue(hItem, STAT_ITEM_NUMSOCKETS, 0);
}

// 0x00629A00
int __stdcall ITEMS_GetGemApplyTypeFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 3880);

    return pItemsTxtRecord->nGemApplyType;
}

// 0x00629A40
int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 3901);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 3902);

    return ITEMS_GetGemApplyTypeFromItemId(pItem->dwClassId);
}

// 0x0062BEB0
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem)
{
    return ITEMSIsA(pItem, ITEMTYPE_SOCKET_FILLER);
}

// 0x0062C060
int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nClass < 7;
        }
    }

    return 0;
}

// 0x0062C0B0
int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord && pItemTypesTxtRecord->nClass < 7)
        {
            return pItemTypesTxtRecord->nClass;
        }
    }

    return 7;
}

// 0x00629B50
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2)
{
    if (nItemType1 >= 0 && nItemType1 < sgptDataTables->nItemTypesTxtRecordCount && nItemType2 >= 0 && nItemType2 < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return ITEMS_CheckTypeEquivalenceFromLUT(ITEMS_TypeEquivalenceLUT(nItemType1), nItemType2);
    }

    return FALSE;
}

// 0x00629BB0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType)
{
    if (!pItem)
    {
        return 0;
    }

    if (nItemType < 0 || nItemType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    const int nClassId = pItem->dwClassId;
    const int nType = ITEMS_GetItemTypeFromItemId(nClassId);
    if (sgptDataTables->pItemTypesEquivalenceLUTs[nType * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F])
    {
        return 1;
    }

    const int nItemsTxtClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemsTxtClassId);
    if (pItemsTxtRecord && pItemsTxtRecord->wType[1] > 0 && pItemsTxtRecord->wType[1] < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return sgptDataTables->pItemTypesEquivalenceLUTs[pItemsTxtRecord->wType[1] * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F];
    }

    return 0;
}

// 0x00629C80
int __stdcall ITEMS_CheckBitField1Flag1(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4160);

    return pItemsTxtRecord->dwBitField1 & 1;
}

// 0x00629CC0
int __stdcall ITEMS_IsMetalItem(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4170);

    return pItemsTxtRecord->dwBitField1 & 2;
}

// 0x00629D00
int __stdcall ITEMS_CheckBitField1Flag4(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4180);

    return pItemsTxtRecord->dwBitField1 & 4;
}

// 0x00629D40
int __stdcall ITEMS_IsNotQuestItemByItemId(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4190);

    return pItemsTxtRecord->nQuest < 1 && pItemsTxtRecord->wType[0] != ITEMTYPE_QUEST;
}

// 0x00629DA0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4208);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4209);
    D2_ASSERT(pItem->pItemData, 4211);
    return pItem->pItemData->dwFileIndex;
}

// 0x00629DF0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex)
{
    D2_ASSERT(pItem, 4220);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4221);
    D2_ASSERT(pItem->pItemData, 4223);
    pItem->pItemData->dwFileIndex = dwFileIndex;
}

// 0x00629E40
void __stdcall ITEMS_GetRealmData(D2UnitStrc* pItem, int* pRealmData0, int* pRealmData1)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            *pRealmData0 = 0;
            *pRealmData1 = 0;
            return;
        }

        *pRealmData0 = pItemData->dwRealmData[0];
        *pRealmData1 = pItemData->dwRealmData[1];
        return;
    }

    *pRealmData0 = 0;
    *pRealmData1 = 0;
}

// 0x00629EA0
extern "C" __declspec(dllexport) void __stdcall ITEMS_SetRealmData(Unit00629EA0* pUnit, unsigned int dwFirst, unsigned int dwSecond) {
    if (pUnit && pUnit->nType == 4) {
        Data00629EA0* pData = pUnit->pData;
        if (pData) {
            pData->dwValue1C = dwFirst;
            pData->dwValue20 = dwSecond;
        }
    }
}

// 0x00629ED0
void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID)
{
    D2_ASSERT(pItem, 4284);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4285);
    D2_ASSERT(pItem->pItemData, 4287);
    pItem->pItemData->dwOwnerGUID = nOwnerGUID;
}

int __stdcall sub_M88_Emit_0062A2F0(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if (!ITEMS_IsPlainQuality(ITEMS_GetItemQuality(pItem1)))
        return 0;
    if (!ITEMS_IsPlainQuality(ITEMS_GetItemQuality(pItem2)))
        return 0;
    return 1;
}

inline int ITEMS_CheckIfSocketable_Inl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId))
        {
            return pItemsTxtRecord->nHasInv;
        }
    }

    return 0;
}

inline unsigned int ITEMS_CheckItemFlag_Inl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData_Inl(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline int ITEMS_GetItemQuality_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

inline unsigned short ITEMS_GetPrefixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicPrefix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetSuffixId_Inl(D2UnitStrc* pItem, int nIndex)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wMagicSuffix[nIndex];
    }

    return 0;
}

inline unsigned short ITEMS_GetAutoAffix_Inl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData_Inl(pItem))
    {
        return pItemData->wAutoAffix;
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecord_Inl(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

// 0x0062BB20
int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 3500);
    const int nType = hItem ? hItem->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nType == UNIT_ITEM, 3501);

    unsigned char nSpellIcon = 0;
    if (ITEMSIsA(hItem, ITEMTYPE_SCROLL) || ITEMSIsA(hItem, ITEMTYPE_BOOK))
    {
        unsigned short wBookId = 0;
        if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(hItem))
        {
            wBookId = pItemData->wMagicSuffix[0];
        }
        else
        {
            wBookId = 0;
        }

        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(wBookId);
        if (!pBooksTxtRecord)
        {
            return -1;
        }

        nSpellIcon = pBooksTxtRecord->nSpellIcon;
    }
    else
    {
        const int nClassId = hItem->dwClassId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
        D2_ASSERT(pItemsTxtRecord, 3512);
        nSpellIcon = pItemsTxtRecord->nSpellIcon;
    }

    return nSpellIcon;
}

inline int ITEMS_GetItemType_Inl(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1661);

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != 4)
    {
        return 0;
    }

    return ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
}

inline int UNITS_IsExpansion_Inl(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx >> 25) & 1;
    }

    return 0;
}

// 0x00629F20
int __stdcall ITEMS_GetOwnerId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4295);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4296);
    D2_ASSERT(pItem->pItemData, 4298);
    return pItem->pItemData->dwOwnerGUID;
}

// 0x00629F70
int __stdcall ITEMS_IsClassValidByItemId(int nItemId)
{
    D2ItemTypesTxt* pItemTypesTxtRecord = 0;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pItemsTxtRecord, 1677);

    pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(pItemsTxtRecord->wType[0]);
    if (!pItemTypesTxtRecord)
    {
        return FALSE;
    }

    return pItemTypesTxtRecord->nClass < NUMBER_OF_PLAYERCLASSES;
}

// 0x00629FE0
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem)
{
    int nItemId = 0;
    if (!pItem)
    {
        nItemId = -1;
    }
    else
    {
        nItemId = pItem->dwClassId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pItemsTxtRecord, 4421);

    unsigned int nCounter = 0;
    while (nCounter < gnWeaponClassTableCount)
    {
        if (pItemsTxtRecord->dwWeapClass == gWeaponClassTable[nCounter].dwCode)
        {
            return (unsigned short)gWeaponClassTable[nCounter].nWeaponClassId;
        }

        ++nCounter;
    }

    return WEAPONCLASS_HTH;
}

inline int ITEMS_GetItemQualityInline(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return 2;
}

// 0x0062A060
unsigned int __stdcall ITEMS_GetTransmogrifyFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    D2_ASSERT(pItemsTxtRecord, 4437);

    return pItemsTxtRecord->nTransmogrify != 0;
}


static inline int UNITS_GetUnitTypeOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x0062A370
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem)
{
    if (!pPlayer || UNITS_GetUnitTypeOrInvalid_Inline(pSetItem) != UNIT_ITEM)
    {
        return 0;
    }

    if (ITEMS_GetItemQuality_Inl(pSetItem) != ITEMQUAL_SET)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pSetItem));
    if (!pSetItemsTxtRecord)
    {
        return 0;
    }
// build: symbol ?DATATBLS_GetSetsTxtRecord@* 0x00483410
    if (!DATATBLS_GetSetsTxtRecord(pSetItemsTxtRecord->nSetId))
    {
        return 0;
    }

    unsigned int nMask = 0;
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        if (INVENTORY_GetItemNodePage(pNode) == 3)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
            if (pItem && pItem->dwUnitType == UNIT_ITEM && (bDontIgnoreInputItem || pItem != pSetItem)
                && ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET
                && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x144E, gszItemsSourceFile)
                && !ITEMS_CheckItemFlag(pItem, 0x100, 0x144F, gszItemsSourceFile))
            {
                D2SetItemsTxt* pRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pRecord && pRecord->nSetId == pSetItemsTxtRecord->nSetId)
                {
                    nMask |= 1 << (unsigned char)pRecord->nSetItems;
                }
            }
        }
    }

    return nMask;
}

inline int ITEMS_CanBeEquippedInline(D2UnitStrc* pItem)
{
    if (pItem)
        return !ITEMS_CheckItemFlagInline(pItem, IFLAG_BROKEN) && !ITEMS_CheckItemFlagInline(pItem, IFLAG_NOEQUIP);

    return FALSE;
}

// 0x0062B4D0
int __stdcall ITEMS_GetQuestFromItemId(int nItemId)
{
    struct D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);

    if (!ITEMS_CheckItemTypeIdByItemId(nItemId, ITEMTYPE_ANY_ARMOR) && !ITEMS_CheckItemTypeIdByItemId(nItemId, ITEMTYPE_WEAPON))
    {
        return 0;
    }

    if (pItemsTxtRecord->dwUberCode != pItemsTxtRecord->dwCode && pItemsTxtRecord->dwUltraCode != pItemsTxtRecord->dwCode)
    {
        return 0;
    }

    struct D2ItemsTxt* pRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2_ASSERT(pRecord, 1677);
    if (pRecord->wType[0] == 38)
    {
        return 0;
    }

    return !pItemsTxtRecord->nQuest;
}

// 0x0062B560
int __stdcall ITEMS_GetQuest(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1932);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 1933);

    return ITEMS_GetQuestFromItemId(pItem->dwClassId);
}

// 0x00629A90
int __stdcall ITEMS_CheckItemTypeIdByItemId(int nItemId, int nItemType)
{
    if (nItemType < 0 || nItemType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nType = ITEMS_GetItemTypeFromItemId(nItemId);
    if (nType < 0 || nType >= sgptDataTables->nItemTypesTxtRecordCount)
    {
        return 0;
    }

    if (sgptDataTables->pItemTypesEquivalenceLUTs[nType * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F])
    {
        return 1;
    }

    const int nType2 = pItemsTxtRecord->wType[1];
    if (nType2 && nType2 < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return sgptDataTables->pItemTypesEquivalenceLUTs[nType2 * sgptDataTables->nItemTypesIndex + (nItemType >> 5)] & gdwBitMasks[nItemType & 0x1F];
    }

    return 0;
}

// 0x0062A0A0
unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 4450);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 4451);

    return ITEMS_GetTransmogrifyFromItemId(pItem->dwClassId);
}

// 0x0062A130
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem)
{
    if (!pItem || !ITEMS_CheckItemFlagData_Inl(pItem, IFLAG_NOSELL))
    {
        if (ITEMS_IsNotQuestItemByItemId(!pItem ? -1 : pItem->dwClassId))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062A180
unsigned char __stdcall ITEMS_GetHitClassFromItem(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0x118F);
    D2_ASSERT(hItem->dwUnitType == UNIT_ITEM, 0x1190);

    const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1192);
    return pItemsTxtRecord->nHitClass;
}

// 0x0062A1E0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* hPlayer, D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 4507);
    D2_ASSERT(hPlayer, 4509);

    if (hPlayer->dwUnitType == UNIT_PLAYER && hPlayer->dwClassId == PCLASS_BARBARIAN)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(hItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 4517);

        if (pItemsTxtRecord->n1or2Handed)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062A250
static unsigned char ITEMS_PackTransformColor(int nTransform, int nColor)
{
    if (nTransform <= 0 || nTransform >= 9 || nColor < 0 || nColor >= 0x15)
    {
        return 0;
    }

    unsigned char nPacked = nColor & 0x1F;
    nPacked += nTransform << 5;
    return nPacked;
}

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordFromItem_Inl(D2UnitStrc* pItem)
{
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_ITEM && ITEMS_GetItemQualityInline(pItem) == ITEMQUAL_SET)
    {
        const int nFileIndex = ITEMS_GetFileIndex(pItem);
        if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
        {
            return &sgptDataTables->pSetItemsTxt[nFileIndex];
        }
    }

    return 0;
}

// 0x0062A270
static int ITEMS_HasSocketedItem(D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    for (D2UnitStrc* pSocket = INVENTORY_GetFirstItem(pInventory); pSocket; pSocket = INVENTORY_GetNextItem(pSocket))
    {
        if (INVENTORY_UnitIsItem(pSocket))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0062A2B0
static int ITEMS_GetCompactSave(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x12E0);
    return pItemsTxtRecord->nCompactSave;
}

static inline int ITEMS_CheckIfSocketableByItemIdForceInl(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }

    return 0;
}

static inline int ITEMS_CheckIfSocketableForceInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return ITEMS_CheckIfSocketableByItemIdForceInl(pItem->dwClassId);
    }

    return 0;
}

// 0x0062A2F0
static int ITEMS_IsPlainQuality(int nQuality)
{
    switch (nQuality)
    {
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 0;
    }
    return 1;
}

// 0x0062C850
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if ((!pItem1 ? -1 : pItem1->dwClassId) != (!pItem2 ? -1 : pItem2->dwClassId))
    {
        return 0;
    }

    if (ITEMS_QUALITY_INLINE(pItem1) != ITEMS_QUALITY_INLINE(pItem2))
    {
        return 0;
    }

    if (ITEMS_GetFileIndex(pItem1) != ITEMS_GetFileIndex(pItem2)
        || !ITEMS_CheckIfStackable(pItem1)
        || ITEMS_IsEthereal(pItem1) != ITEMS_IsEthereal(pItem2)
        || !ITEMS_IsPlainQuality(ITEMS_GetItemQuality(pItem1))
        || !ITEMS_IsPlainQuality(ITEMS_GetItemQuality(pItem2))
        || STATLIST_UnitGetStatValue(pItem1, STAT_MINDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_MINDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_MAXDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_MAXDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_SECONDARY_MINDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_SECONDARY_MINDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_SECONDARY_MAXDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_SECONDARY_MAXDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_ITEM_THROW_MINDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_ITEM_THROW_MINDAMAGE, 0)
        || STATLIST_UnitGetStatValue(pItem1, STAT_ITEM_THROW_MAXDAMAGE, 0) != STATLIST_UnitGetStatValue(pItem2, STAT_ITEM_THROW_MAXDAMAGE, 0)
        || (unsigned char)ITEMS_GetSockets(pItem1) > 0
        || (unsigned char)ITEMS_GetSockets(pItem2) > 0)
    {
        return 0;
    }

    return 1;
}

inline void ITEMS_SetItemFlag_Inline(D2UnitStrc* pItem, unsigned int dwFlag, int bSet)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            if (bSet)
                pItemData->dwItemFlags |= dwFlag;
            else
                pItemData->dwItemFlags &= ~dwFlag;
        }
    }
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

inline void ITEMS_SetItemFlags(D2UnitStrc* pItem, unsigned int dwFlags)
{
    if (pItem)
    {
        switch (pItem->dwUnitType)
        {
        case UNIT_ITEM:
            if (pItem->pItemData)
                pItem->pItemData->dwItemFlags = dwFlags;
            break;
        }
    }
}

inline unsigned int ITEMS_GetItemFlags_Inline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->dwItemFlags;
    return 0;
}

inline void ITEMS_SetItemLevel_Inline(D2UnitStrc* pItem, int nItemLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwItemLevel = nItemLevel;
}

inline void ITEMS_SetMagicPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wMagicPrefix[nIndex] = nPrefix;
}

inline void ITEMS_SetMagicSuffix(D2UnitStrc* pItem, unsigned short nSuffix, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wMagicSuffix[nIndex] = nSuffix;
}

inline void ITEMS_SetRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wRarePrefix = nPrefix;
}

inline void ITEMS_SetRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->wRareSuffix = nSuffix;
}

inline void ITEMS_SetBodyLoc(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nBodyLoc = nBodyLoc;
}

inline void ITEMS_SetInvPage_Inline(D2UnitStrc* pItem, char nInvPage)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nInvPage = nInvPage;
}

inline void ITEMS_SetEarLevel_Inline(D2UnitStrc* pItem, unsigned char nLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->nEarLvl = nLevel;
}

inline char* ITEMS_GetEarName_Inline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        return pItem->pItemData->szPlayerName;
    return 0;
}

static inline D2ItemStatCostTxt* DATATBLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

static inline unsigned int BITMANIP_ReadInl(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00411020_ReadBits(pBuffer, nBits);
}

static inline int ITEMS_ReadQuestItemDifficultyForceInl(D2BitBufferStrc* pBuffer, D2ItemStatCostTxt* pRecord)
{
    return (BITMANIP_ReadInl(pBuffer, pRecord->nSaveBits) - pRecord->dwSaveAdd) << pRecord->nValShift;
}

// 0x0062C9F0
static void __stdcall ITEMS_SetDefenseOrDamage(D2UnitStrc* pItem, int nStat)
{
    int nItemId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
    if (!pItemsTxtRecord)
        return;

    switch (nStat)
    {
    case 16:
    case 31:
        if (ITEMSIsA(pItem, 50) && pItemsTxtRecord->dwMaxAc)
        {
            int nArmor = STATLIST_GetUnitBaseStat(pItem, 31, 0) + 1;
            if (nArmor <= pItemsTxtRecord->dwMaxAc)
                nArmor = pItemsTxtRecord->dwMaxAc + 1;
            STATLIST_SetUnitStat(pItem, 31, nArmor, 0);
        }
        break;
    case 17:
    case 22:
        if (ITEMSIsA(pItem, 45))
        {
            const int nMax = STATLIST_GetUnitBaseStat(pItem, 22, 0);
            if (pItemsTxtRecord->nMaxDam && nMax < pItemsTxtRecord->nMaxDam)
                STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
            const int nMax2 = STATLIST_GetUnitBaseStat(pItem, 24, 0);
            if (pItemsTxtRecord->n2HandMaxDam && nMax2 < pItemsTxtRecord->n2HandMaxDam)
                STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
            const int nMaxMis = STATLIST_GetUnitBaseStat(pItem, 160, 0);
            if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMaxMisDam && nMaxMis < pItemsTxtRecord->nMaxMisDam)
                STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
        }
        break;
    case 18:
    case 21:
        if (ITEMSIsA(pItem, 45))
        {
            const int nMin = STATLIST_GetUnitBaseStat(pItem, 21, 0);
            if (pItemsTxtRecord->nMinDam && nMin < pItemsTxtRecord->nMinDam)
                STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
            const int nMin2 = STATLIST_GetUnitBaseStat(pItem, 23, 0);
            if (pItemsTxtRecord->n2HandMinDam && nMin2 < pItemsTxtRecord->n2HandMinDam)
                STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);
            const int nMinMis = STATLIST_GetUnitBaseStat(pItem, 159, 0);
            if (ITEMS_CheckIfThrowable(pItem) && pItemsTxtRecord->nMinMisDam && nMinMis < pItemsTxtRecord->nMinMisDam)
                STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
        }
        break;
    default:
        break;
    }
}

int __stdcall sub_M231_Emit_00629370(D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    return ITEMS_GetGambleCost(STATLIST_UnitGetStatValue(pPlayer, 12, 0), pItem);
}

// 0x0062A310
int __stdcall ITEMS_CanItemBeUsedForThrowSkill(D2UnitStrc* pItem)
{
    if (pItem)
    {
        if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
        {
            return TRUE;
        }

        if (STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROWABLE, 0))
        {
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 0, 0);
            return TRUE;
        }

        if (ITEMS_GetTotalMaxStack(pItem) <= 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0062A490
D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem)
{
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_ITEM && ITEMS_GetItemQualityInline(pItem) == ITEMQUAL_SET)
    {
        const int nFileIndex = ITEMS_GetFileIndex(pItem);
        if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
        {
            return &sgptDataTables->pSetItemsTxt[nFileIndex];
        }
    }

    return 0;
}

// 0x0062A4E0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem)
{
    if (pItem)
        return !ITEMS_CheckItemFlagInline(pItem, IFLAG_BROKEN) && !ITEMS_CheckItemFlagInline(pItem, IFLAG_NOEQUIP);

    return FALSE;
}

static inline void ITEMS_WriteBitsCoreInl(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    if (nBits != 32)
    {
        nData = D2_MIN(D2_MAX(nData, 0u), (1u << nBits) - 1);
    }

    BITMANIP_Write(pBuffer, nData, nBits);
}

static __forceinline void ITEMS_WriteBitsRevInl(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    ITEMS_WriteBitsCoreInl(pBuffer, nData, nBits);
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

inline unsigned int ITEMS_GetItemFlagsInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    return pItemData ? pItemData->dwItemFlags : 0;
}

inline unsigned char ITEMS_GetBodyLocationInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nBodyLoc;
    }
    return 0;
}

inline char ITEMS_GetInvPageInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nInvPage;
    }
    return -1;
}

inline unsigned char ITEMS_GetEarLevelInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nEarLvl;
    }
    return 1;
}

inline char* ITEMS_GetEarNameInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    return pItemData ? pItemData->szPlayerName : 0;
}

inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordInl(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static inline int ITEMS_IsOnGroundForceInl(D2UnitStrc* pItem)
{
    if (pItem && (pItem->dwAnimMode == IMODE_ONGROUND || pItem->dwAnimMode == IMODE_DROPPING))
    {
        return 1;
    }
    return 0;
}

static inline int ITEMS_GetQuestItemDifficultyValueForceInl(D2UnitStrc* pItem, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    return (STATLIST_UnitGetStatValue(pItem, STAT_QUESTITEMDIFFICULTY, 0) >> pItemStatCostTxtRecord->nValShift) + pItemStatCostTxtRecord->dwSaveAdd;
}

// 0x0062A530
int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nUnidItems = 0;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pInventoryItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMS_TestItemFlag(pInventoryItem, IFLAG_IDENTIFIED))
        {
            continue;
        }

        const int nNodePage = INVENTORY_GetItemNodePage(pItem);
        if (nNodePage == NODEPAGE_STORAGE)
        {
            if (ITEMS_GetInvPage(pInventoryItem) == INVPAGE_INVENTORY || ITEMS_GetInvPage(pInventoryItem) == INVPAGE_CUBE)
            {
                ++nUnidItems;
            }
        }
        else if (nNodePage == NODEPAGE_EQUIP)
        {
            ++nUnidItems;
        }
    }

    return nUnidItems;
}

// 0x0062A5D0
int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue)
{
    int nResult = nValue;

    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        nResult = 2 * nValue;
    }
    else
    {
        switch (pPlayer->dwClassId)
        {
        case PCLASS_AMAZON:
        case PCLASS_PALADIN:
        case PCLASS_ASSASSIN:
            nResult = nValue + (nValue >> 1);
            break;
        case PCLASS_BARBARIAN:
            nResult = 2 * nValue;
            break;
        }
    }

    return nResult;
}

// 0x0062A620
int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue)
{
    int nResult = nValue;

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        switch (pPlayer->dwClassId)
        {
        case PCLASS_SORCERESS:
        case PCLASS_NECROMANCER:
        case PCLASS_DRUID:
            nResult = 2 * nValue;
            break;
        case PCLASS_AMAZON:
        case PCLASS_PALADIN:
        case PCLASS_ASSASSIN:
            nResult = nValue + (nValue >> 1);
            break;
        }
    }

    return nResult;
}

inline int ITEMS_CheckIfSocketableByItemIdInl(int nItemId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (pItemsTxtRecord)
    {
        return pItemsTxtRecord->nHasInv;
    }
    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemDataInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

inline int ITEMS_CheckItemFlagInl(D2UnitStrc* pItem, unsigned int nFlag)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataInl(pItem);
    if (pItemData)
    {
        return pItemData->dwItemFlags & nFlag;
    }
    return 0;
}

// 0x0062A670
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 5380);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 5381);
    D2_ASSERT(pItem->pItemData, 5383);
    return pItem->pItemData->wItemFormat;
}

// 0x0062A6C0
void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat)
{
    D2_ASSERT(pItem, 5391);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 5392);
    D2_ASSERT(pItem->pItemData, 5394);
    pItem->pItemData->wItemFormat = nItemFormat;
}

// 0x0062A710
int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* hItem)
{
    D2_ASSERT((hItem ? hItem->dwUnitType : UNIT_INVALID) == UNIT_ITEM, 0x151D);
    D2_ASSERT(ITEMSIsA(hItem, 0x2D), 0x151E);
    D2_ASSERT(pUnit, 0x151F);

    char szPath[8];
    int nLength = 0;
    int nAnimSpeed = 0;
    int nFirstFrame = 0;
    int nWeaponClassCode = ITEMS_GetWeaponClassCode(hItem);

    D2Common_10884_COMPOSIT_unk(pUnit, !pUnit ? -1 : pUnit->dwClassId, 7, !pUnit ? 6 : pUnit->dwUnitType, pUnit->pInventory, szPath, &nWeaponClassCode, 0, 0);
    if (!DATATBLS_GetAnimDataInfo(szPath, &nLength, &nAnimSpeed, &nFirstFrame))
    {
        return 0x2D;
    }

    D2_ASSERT(nLength, 0x1538);

    int nSpeed = STATLIST_UnitGetItemStatOrSkillStatValue(hItem, 0x5D, 0) + 100;
    nSpeed += STATLIST_UnitGetStatValue(hItem, 0x44, 0);
    return (nLength << 8) / (nAnimSpeed * nSpeed / 100);
}

// 0x0062A840
int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills)
{
    D2StatStrc pStat[64];

    if (pHasChargedSkills)
    {
        *pHasChargedSkills = 1;
    }

    int bResult = 0;
    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, pStat, 64);
    if (nStats > 0)
    {
        bResult = 1;

        if (pHasChargedSkills)
        {
            for (int i = 0; i < nStats; ++i)
            {
                if ((pStat[i].nValue & 0xFF) < (pStat[i].nValue >> 8))
                {
                    *pHasChargedSkills = 0;
                    break;
                }
            }
        }
    }

    return bResult;
}


// 0x0062A8D0
int __stdcall ITEMS_IsEthereal(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & IFLAG_ETHEREAL;
    }

    return 0;
}

// 0x0062A900
static int ITEMS_GetSocketedItemCount(D2UnitStrc* pItem)
{
    int nSocketedItems = 0;
    if (!ITEMS_CheckIfSocketableForceInl(pItem))
    {
        return 0;
    }

    if (!pItem->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pItem->pInventory);
    if (!pInventoryItem)
    {
        return 0;
    }

    do
    {
        ++nSocketedItems;
        pInventoryItem = INVENTORY_GetNextItem(pInventoryItem);
    }
    while (pInventoryItem);

    return nSocketedItems;
}

// 0x0062A960
static inline unsigned int ITEMS_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00411020_ReadBits(pBuffer, nBits);
}

// 0x0062A970
static int __stdcall ITEMS_DecodeItemBitstreamCompact(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, unsigned int dwVersion)
{
    ITEMS_SetItemFormat(pItem, (unsigned short)sub_00411020_ReadBits(pBuffer, 10));

    const int nAnimMode = sub_00411020_ReadBits(pBuffer, 3);
    if (nAnimMode == 3 || nAnimMode == 5)
    {
        UNITS_SetXForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 16));
        UNITS_SetYForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 16));
    }
    else
    {
        ITEMS_SetBodyLoc(pItem, (unsigned char)sub_00411020_ReadBits(pBuffer, 4));
        UNITS_SetXForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 4));
        UNITS_SetYForStaticUnit(pItem, sub_00411020_ReadBits(pBuffer, 4));
        ITEMS_SetInvPage_Inline(pItem, (char)(sub_00411020_ReadBits(pBuffer, 3) - 1));
    }
    UNITS_ChangeAnimMode(pItem, nAnimMode);

    if (ITEMS_GetItemFlags_Inline(pItem) & IFLAG_ISEAR)
    {
        char* szName = ITEMS_GetEarName_Inline(pItem);
        ITEMS_SetFileIndex(pItem, sub_00411020_ReadBits(pBuffer, 3));
        ITEMS_SetEarLevel_Inline(pItem, (unsigned char)sub_00411020_ReadBits(pBuffer, 7));
        do
        {
            *szName = (char)sub_00411020_ReadBits(pBuffer, 7);
        }
        while (*szName++);
    }
    else
    {
        const unsigned int dwCode = sub_00411020_ReadBits(pBuffer, 32);
        const int nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
        if (pItem)
            pItem->dwClassId = nClassId;

        if (ITEMSIsA(pItem, 4))
        {
            if (sub_00411020_ReadBits(pBuffer, 1))
                STATLIST_SetUnitStat(pItem, 14, sub_00411020_ReadBits(pBuffer, 32), 0);
            else
                STATLIST_SetUnitStat(pItem, 14, sub_00411020_ReadBits(pBuffer, 12), 0);
        }

        if (ITEMSIsA(pItem, 22))
        {
            if (dwCode == ' cst')
                ITEMS_SetMagicSuffix(pItem, 0, 0);
            else if (dwCode == ' csi')
                ITEMS_AssignSuffix(pItem, 1, 0);
        }
    }

    if (dwVersion > 0x5C)
    {
        int nItemId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(ITEMS_GetBaseCode(pItem), &nItemId);
        if (!pItemsTxtRecord)
            return -1;

        if (pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck)
        {
            D2ItemStatCostTxt* pRecord = DATATBLS_GetItemStatCostTxtRecord(356);
            if (!pRecord)
            {
                FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1607);
                exit(-1);
            }
            const int nValue = ITEMS_ReadQuestItemDifficultyForceInl(pBuffer, pRecord);
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, 0, 0x40);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(!pItem ? 0 : pItem->pMemoryPool, 0x40, 0, 4, !pItem ? -1 : pItem->dwUnitId);
                D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            }
            STATLIST_SetStat(pStatList, 356, nValue, 0);
        }
    }

    if (bCheckForHeader && dwVersion > 0x56 && sub_00411020_ReadBits(pBuffer, 1))
    {
        const int nFirst = sub_00411020_ReadBits(pBuffer, 32);
        ITEMS_SetRealmData(pItem, nFirst, sub_00411020_ReadBits(pBuffer, 32));
        if (dwVersion > 0x5D)
            sub_00411020_ReadBits(pBuffer, 32);
    }

    pItem->dwInitSeed = 0;
    SEED_InitLowSeed(&pItem->pSeed, 0);
    ITEMS_SetItemLevel_Inline(pItem, 1);
    if (pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwQualityNo = 2;
    return 1;
}

// 0x0062AC80
static __declspec(noinline) void __stdcall ITEMS_ReadStatFromItemBitstream(D2BitBufferStrc* pBuffer, D2StatListStrc* pStatList, D2ItemStatCostTxt* pItemStatCostTxtRecord, int nStatId, unsigned int dwVersion, int n109)
{
    int nParamBits = (&pItemStatCostTxtRecord->nSaveParamBits)[n109];
    int nSaveBits = (&pItemStatCostTxtRecord->nSaveBits)[n109];
    int nSaveAdd = (&pItemStatCostTxtRecord->dwSaveAdd)[n109];
    int nParam = 0;

    switch (nStatId)
    {
    case 23:
        if (dwVersion <= 89)
            nSaveBits = 5;
        break;
    case 24:
        if (dwVersion <= 89)
            nSaveBits = 6;
        break;
    case 74:
        if (dwVersion <= 89)
        {
            nSaveBits = 5;
            nSaveAdd = 10;
        }
        break;
    case 79:
        if (dwVersion <= 89)
        {
            nSaveBits = 8;
            nSaveAdd = 20;
        }
        break;
    case 80:
        if (dwVersion <= 89)
        {
            nSaveBits = 7;
            nSaveAdd = 20;
        }
        break;
    case 93:
    case 96:
    case 99:
    case 102:
    case 105:
        if (dwVersion <= 87)
            nSaveBits = 6;
        break;
    case 92:
    case 94:
        if (dwVersion < 93)
            nStatId = 93;
        break;
    case 95:
    case 97:
        if (dwVersion < 93)
            nStatId = 96;
        break;
    case 98:
    case 100:
        if (dwVersion < 93)
            nStatId = 99;
        break;
    case 101:
    case 103:
        if (dwVersion < 93)
            nStatId = 102;
        break;
    case 104:
    case 106:
        if (dwVersion < 93)
            nStatId = 105;
        break;
    default:
        break;
    }

    if (nParamBits > 0)
        nParam = (unsigned short)sub_00411020_ReadBits(pBuffer, nParamBits);

    const unsigned int nValue = sub_00411020_ReadBits(pBuffer, nSaveBits);
    STATLIST_SetStat(pStatList, nStatId, (nValue - nSaveAdd) << pItemStatCostTxtRecord->nValShift, nParam);
}

// calling-convention shim (not game code)
int __fastcall sub_0062A900_Shim(D2UnitStrc* pItem)
{
    return ITEMS_GetSocketedItemCount(pItem) + 1;
}

static inline void GetDimensions(D2UnitStrc* item, unsigned char* width, unsigned char* height, const char* file, int line) {
    *width = 0;
    *height = 0;
    if (item && item->dwUnitType == UNIT_ITEM) {
        D2ItemsTxt* txt = DATATBLS_GetItemsTxtRecord(!item ? -1 : item->dwClassId);
        if (txt) { *width = txt->nInvWidth; *height = txt->nInvHeight; }
    }
}

static inline D2ItemDataStrc* GetData(D2UnitStrc* item) {
    return (item && item->dwUnitType == UNIT_ITEM && item->pItemData) ? item->pItemData : 0;
}

static inline unsigned int GetQuality(D2UnitStrc* item) {
    const int type = item ? item->dwUnitType : UNIT_INVALID;
    D2ItemDataStrc* data = (type == 4 && item->pItemData) ? item->pItemData : 0;
    return data ? data->dwQualityNo : 2;
}

// 0x0062BCB0
void __stdcall sub_0062BCB0_AddSockets(D2UnitStrc* item, int sockets) {
    const int type = item ? item->dwUnitType : UNIT_INVALID;
    if (type != 4) return;
    int maximum = 6;
    unsigned char width = 0, height = 0;
    GetDimensions(item, &width, &height, 0, 0);
    int area = height * width;
    if (area <= 6) maximum = area;
    if (!area) return;
    switch (GetQuality(item)) {
    case 5: case 7: {
        int existing = STATLIST_UnitGetStatValue(item, 194, 0);
        if (existing > 0) sockets = existing;
        else maximum = Min(maximum, 1);
        break;
    }
    case 6: maximum = Min(maximum, 2); break;
    case 4: maximum = Min(maximum, 4); break;
    case 8: case 9: maximum = Min(maximum, 3); break;
    }
    maximum = Min(maximum, ITEMS_GetMaxSockets(item));
    sockets = Min(Max(sockets, 1), maximum);
    if (sockets > 0) {
        if (D2ItemDataStrc* data = GetData(item)) data->dwItemFlags |= 0x800;
        STATLIST_SetUnitStat(item, 194, sockets, 0);
    }
}

static void ITEMS_GetDimensionsInl(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight)
{
    *pWidth = 0;
    *pHeight = 0;

    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        const D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (pItemsTxtRecord)
        {
            *pWidth = pItemsTxtRecord->nInvWidth;
            *pHeight = pItemsTxtRecord->nInvHeight;
        }
    }
}

static void ITEMS_SetOrRemoveFlagInl(unsigned int* pFlags, unsigned int nFlag, int bSet)
{
    if (bSet)
    {
        *pFlags |= nFlag;
    }
    else
    {
        *pFlags &= ~nFlag;
    }
}

static void ITEMS_SetItemFlagInl(D2UnitStrc* pItem, unsigned int dwFlag, int bSet)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        ITEMS_SetOrRemoveFlagInl(&pItem->pItemData->dwItemFlags, dwFlag, bSet);
    }
}

// 0x0062BE00
void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets)
{
    if (pItem && (!pItem ? 6 : pItem->dwUnitType) == 4)
    {
        int nMaxSockets = 6;
        unsigned char nWidth = 0;
        unsigned char nHeight = 0;
        ITEMS_GetDimensionsInl(pItem, &nWidth, &nHeight);

        const int nArea = nHeight * nWidth;
        if (nArea <= 6)
        {
            nMaxSockets = nArea;
            if (nArea <= 0)
                return;
        }

        {
            if (nMaxSockets >= ITEMS_GetMaxSockets(pItem))
            {
                nMaxSockets = ITEMS_GetMaxSockets(pItem);
            }

            if (nSockets <= 1)
            {
                nSockets = 1;
            }

            if (nSockets >= nMaxSockets)
            {
                nSockets = nMaxSockets;
            }

            ITEMS_SetItemFlagInl(pItem, 0x800, 1);
            STATLIST_SetUnitStat(pItem, 194, nSockets, 0);
        }
    }
}

// 0x0062AE20
int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, int dwVersion)
{
    D2BitBufferStrc pBuffer;
    BITMANIP_Initialize(&pBuffer, pBitstream, nSize);

    if (bCheckForHeader && BITMANIP_ReadSigned(&pBuffer, 16) != 'MJ')
        return 0;

    unsigned int dwFlags = sub_00411020_ReadBits(&pBuffer, 32);
    pItemSave->dwFlags = dwFlags;
    sub_00411020_ReadBits(&pBuffer, 10);
    pItemSave->bMode = (unsigned char)sub_00411020_ReadBits(&pBuffer, 3);
    if (pItemSave->bMode == IMODE_ONGROUND || pItemSave->bMode == IMODE_DROPPING)
    {
        pItemSave->nX = (unsigned short)sub_00411020_ReadBits(&pBuffer, 16);
        pItemSave->nY = (unsigned short)sub_00411020_ReadBits(&pBuffer, 16);
    }
    else
    {
        pItemSave->nBodyloc = (unsigned char)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nX = (unsigned short)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nY = (unsigned short)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nStorePage = (unsigned char)sub_00411020_ReadBits(&pBuffer, 3) - 1;
    }

    if (dwFlags & IFLAG_ISEAR)
    {
        pItemSave->nClassId = DATATBLS_GetItemIdFromItemCode(' rae');
    }
    else
    {
        unsigned int dwCode = sub_00411020_ReadBits(&pBuffer, 32);
        if (dwVersion <= 0x5C && dwCode == ' cen')
            dwCode = ' gen';
        pItemSave->nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
    }

    int nItemFileIndex = 0;
    if (!(dwFlags & IFLAG_COMPACTSAVE_LOWQUALITY))
        nItemFileIndex = sub_00411020_ReadBits(&pBuffer, 3);
    pItemSave->nItemFileIndex = nItemFileIndex;

    return 1;
}

static int ITEMS_IsMagSetRarUniCrfOrTmp_Inline(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == 4 && pItem->pItemData)
    {
        switch (pItem->pItemData->dwQualityNo)
        {
        case ITEMQUAL_MAGIC:
        case ITEMQUAL_SET:
        case ITEMQUAL_RARE:
        case ITEMQUAL_UNIQUE:
        case ITEMQUAL_CRAFT:
        case ITEMQUAL_TEMPERED:
            return 1;
        default:
            return 0;
        }
    }
    return 0;
}

static inline int ITEMS_IsOfType(D2UnitStrc* pItem, int nItemType)
{
    return ITEMSIsA(pItem, nItemType);
}

// 0x0062BED0
const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc* pItem)
{
    int nRuneItemIds[6];

    if (!pItem)
    {
        return 0;
    }

    if (ITEMS_IsMagSetRarUniCrfOrTmp_Inline(pItem))
    {
        return 0;
    }

    if (DATATBLS_GetItemsTxtRecord(UNITS_GetWeaponClass(pItem))->nQuest)
    {
        return 0;
    }

    if (!pItem->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pSocketFiller = INVENTORY_GetFirstItem(pItem->pInventory);
    if (!pSocketFiller)
    {
        return 0;
    }

    int nSocketedItems = 0;
    while (pSocketFiller)
    {
        D2UnitStrc* pRune = INVENTORY_UnitIsItem(pSocketFiller);
        if (!pRune)
        {
            return 0;
        }

        nRuneItemIds[nSocketedItems++] = pRune->dwClassId;
        pSocketFiller = INVENTORY_GetNextItem(pSocketFiller);
    }

    const int nSockets = (unsigned char)ITEMS_GetSockets(pItem);
    if (nSockets != nSocketedItems)
    {
        return 0;
    }

    D2RuneDataTbl* pRuneDataTbl = DATATBLS_GetRuneDataTables();
    if (!pRuneDataTbl)
    {
        return 0;
    }

    for (int i = 0; i < pRuneDataTbl->nRunesTxtRecordCount; ++i)
    {
        D2RunesTxt* pRunesTxtRecord = &pRuneDataTbl->pRunesTxt[i];
        if (pRunesTxtRecord->nComplete)
        {
            int nRuneCounter = 0;
            bool bMatch = true;

            while (nRuneCounter < 6 && pRunesTxtRecord->nRune[nRuneCounter] > 0)
            {
                if (nSocketedItems < nRuneCounter || nRuneItemIds[nRuneCounter] != pRunesTxtRecord->nRune[nRuneCounter])
                {
                    bMatch = false;
                    break;
                }

                ++nRuneCounter;
            }

            if (bMatch && nRuneCounter >= nSockets)
            {
                bool isItemTypeIgnored = false;
                for (int nETypeCounter = 0; nETypeCounter < 3 && pRunesTxtRecord->wEType[nETypeCounter]; ++nETypeCounter)
                {
                    if (ITEMSIsA(pItem, pRunesTxtRecord->wEType[nETypeCounter]))
                    {
                        isItemTypeIgnored = true;
                        break;
                    }
                }

                if (!isItemTypeIgnored)
                {
                    for (int nITypeCounter = 0; nITypeCounter < 6 && pRunesTxtRecord->wIType[nITypeCounter]; ++nITypeCounter)
                    {
                        if (ITEMSIsA(pItem, pRunesTxtRecord->wIType[nITypeCounter]))
                        {
                            return pRunesTxtRecord;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// 0x0062AF50
static __declspec(noinline) void __stdcall ITEMS_WriteBitsToBitstream(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    if (nBits != 32)
    {
        nData = D2_MIN(D2_MAX(nData, 0u), (1u << nBits) - 1);
    }

    BITMANIP_Write(pBuffer, nData, nBits);
}

// 0x0062AF80
static void __stdcall ITEMS_SerializeItemCompact(int bServer, D2UnitStrc* pItem, D2BitBufferStrc* pBuffer)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 7244);

    ITEMS_WriteBitsInl(10, ITEMS_GetItemFormat(pItem), pBuffer);
    ITEMS_WriteBitsInl(3, !pItem ? 0 : pItem->dwAnimMode, pBuffer);

    if (!ITEMS_IsOnGroundForceInl(pItem))
    {
        ITEMS_WriteBitsInl(4, ITEMS_GetBodyLocationInl(pItem), pBuffer);
        ITEMS_WriteBitsInl(4, D2_MIN(D2_MAX(CLIENTS_GetUnitX(pItem), 0u), 15u), pBuffer);
        ITEMS_WriteBitsInl(4, D2_MIN(D2_MAX(CLIENTS_GetUnitY(pItem), 0u), 15u), pBuffer);
        ITEMS_WriteBitsInl(3, (char)(ITEMS_GetInvPageInl(pItem) + 1), pBuffer);
    }
    else
    {
        ITEMS_WriteBitsInl(16, UNITS_GetXPositionForceInl(pItem), pBuffer);
        ITEMS_WriteBitsInl(16, UNITS_GetYPositionForceInl(pItem), pBuffer);
    }

    if (ITEMS_GetItemFlagsInl(pItem) & IFLAG_ISEAR)
    {
        char* szName = ITEMS_GetEarNameInl(pItem);
        ITEMS_WriteBitsInl(3, ITEMS_GetFileIndex(pItem), pBuffer);
        ITEMS_WriteBitsInl(7, ITEMS_GetEarLevelInl(pItem), pBuffer);
        do
        {
            ITEMS_WriteBitsInl(7, *szName, pBuffer);
        }
        while (*szName++);
    }
    else
    {
        ITEMS_WriteBitsInl(32, ITEMS_GetBaseCode(pItem), pBuffer);

        if (ITEMSIsA(pItem, ITEMTYPE_GOLD))
        {
            const int nGold = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
            ITEMS_WriteBitsInl(1, nGold >= 4096, pBuffer);
            ITEMS_WriteBitsToBitstream(pBuffer, nGold, (((nGold < 4096) - 1) & 20) + 12);
        }
    }

    if (pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck)
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordInl(STAT_QUESTITEMDIFFICULTY);
        D2_ASSERT(pItemStatCostTxtRecord, 7290);

        const int nValue = ITEMS_GetQuestItemDifficultyValueForceInl(pItem, pItemStatCostTxtRecord);
        ITEMS_WriteBitsToBitstream(pBuffer, nValue, pItemStatCostTxtRecord->nSaveBits);
    }

    if (bServer)
    {
        int nRealmData0 = 0;
        int nRealmData1 = 0;
        ITEMS_GetRealmData(pItem, &nRealmData0, &nRealmData1);
        const int nRealm1 = nRealmData1;
        if (nRealm1)
        {
            ITEMS_WriteBitsInl(1, 1, pBuffer);
            ITEMS_WriteBitsInl(32, nRealmData0, pBuffer);
            ITEMS_WriteBitsInl(32, nRealm1, pBuffer);
            ITEMS_WriteBitsInl(32, 0, pBuffer);
        }
        else
        {
            ITEMS_WriteBitsInl(1, 0, pBuffer);
        }
    }
}

inline int ITEMS_CheckIfSocketableAlt_Inl(D2UnitStrc* pItem)
{
    if (pItem && (!pItem ? 6 : pItem->dwUnitType) == 4)
    {
        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            return pItemsTxtRecord->nHasInv;
        }
    }

    return 0;
}

// 0x0062C100
unsigned char* __stdcall ITEMS_GetColor(D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pColor, int nTransType)
{
    D2MagicAffixTxt* pMagicAffixTxtRecord;
    int i;

    if (pItem)
    {
        if (pPlayer)
        {
            for (int i = 0; i < sgptDataTables->nColourStates; ++i)
            {
                const short nState = sgptDataTables->pColourStates[i];
                if (STATES_CheckState(pPlayer, nState))
                {
                    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord_Inl(nState);
                    if (pStatesTxtRecord && pStatesTxtRecord->nItemTrans < 0x15 && ITEMSIsA(pItem, pStatesTxtRecord->wItemType))
                    {
                        if (D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(GAME_GetUnitClassId(pItem)))
                        {
                            return D2CMPPalShiftGetTransform(pItemsTxtRecord->nTransform, pStatesTxtRecord->nItemTrans);
                        }
                    }
                }
            }
        }

        switch (ITEMS_GetItemQuality_Inl(pItem))
        {
        case 4:
        case 6:
            i = 0;
            do
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                    *pColor = ITEMS_PackTransformColor(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

                    if (nTransType)
                    {
                        return D2CMPPalShiftGetTransform(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return D2CMPPalShiftGetTransform(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);

            i = 0;
            do
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId_Inl(pItem, i));
                if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
                {
                    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                    *pColor = ITEMS_PackTransformColor(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

                    if (nTransType)
                    {
                        return D2CMPPalShiftGetTransform(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
                    }

                    return D2CMPPalShiftGetTransform(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
                }
                ++i;
            }
            while (i < 3);
            break;

        case 7:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
            if (!pItemsTxtRecord)
            {
                return 0;
            }

            if (ITEMS_GetFileIndex(pItem) < 0)
            {
                return 0;
            }

            D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (!pUniqueItemsTxtRecord)
            {
                return 0;
            }

            if (nTransType)
            {
                if (pUniqueItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                int const nUniqueColor = pUniqueItemsTxtRecord->nChrTransform;
                *pColor = ITEMS_PackTransformColor(pItemsTxtRecord->nTransform, nUniqueColor);
                int const nInventoryTransform = pItemsTxtRecord->nInvTrans;
                return D2CMPPalShiftGetTransform(nInventoryTransform, pUniqueItemsTxtRecord->nInvTransform);
            }

            if (pUniqueItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = ITEMS_PackTransformColor(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
            return D2CMPPalShiftGetTransform(pItemsTxtRecord->nTransform, pUniqueItemsTxtRecord->nChrTransform);
        }
        case 5:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            if (!pItemsTxtRecord)
            {
                return 0;
            }

            D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (!pSetItemsTxtRecord)
            {
                return 0;
            }

            if (nTransType)
            {
                if (pSetItemsTxtRecord->nInvTransform < 0)
                {
                    return 0;
                }

                int const nTransform = pItemsTxtRecord->nTransform;
                int const nSetColor = pSetItemsTxtRecord->nChrTransform;
                *pColor = ITEMS_PackTransformColor(nTransform, nSetColor);
                return D2CMPPalShiftGetTransform(pItemsTxtRecord->nInvTrans, pSetItemsTxtRecord->nInvTransform);
            }

            if (pSetItemsTxtRecord->nChrTransform < 0)
            {
                return 0;
            }

            *pColor = ITEMS_PackTransformColor(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
            return D2CMPPalShiftGetTransform(pItemsTxtRecord->nTransform, pSetItemsTxtRecord->nChrTransform);
        }
        default:
            if (ITEMS_CheckIfSocketableAlt_Inl(pItem) && ITEMS_GetMaxSockets(pItem) > 0 && ITEMS_CheckItemFlag_Inl(pItem, 0x800))
            {
                D2InventoryStrc* pInventory = pItem->pInventory;
                D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pInventory);
                if (pInventoryItem)
                {
                    pInventoryItem = INVENTORY_UnitIsItem(pInventoryItem);
                    if (pInventoryItem && ITEMSIsA(pInventoryItem, 0x14))
                    {
                        D2ItemsTxt* pGemItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pInventoryItem ? -1 : pInventoryItem->dwClassId);
                        D2_ASSERT(pGemItemsTxtRecord, 0x1271);

                        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pGemItemsTxtRecord->dwGemOffset);
                        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
                        *pColor = ITEMS_PackTransformColor(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                        if (nTransType)
                        {
                            return D2CMPPalShiftGetTransform(pItemsTxtRecord->nInvTrans, pGemsTxtRecord->nTransform);
                        }

                        return D2CMPPalShiftGetTransform(pItemsTxtRecord->nTransform, pGemsTxtRecord->nTransform);
                    }
                }
            }
            break;
        }

        pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix_Inl(pItem));
        if (pMagicAffixTxtRecord && pMagicAffixTxtRecord->nTransformColor != 0xFF)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            *pColor = ITEMS_PackTransformColor(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);

            if (nTransType)
            {
                return D2CMPPalShiftGetTransform(pItemsTxtRecord->nInvTrans, pMagicAffixTxtRecord->nTransformColor);
            }

            return D2CMPPalShiftGetTransform(pItemsTxtRecord->nTransform, pMagicAffixTxtRecord->nTransformColor);
        }
    }

    return 0;
}

inline int UNITS_IsExpansionChecked_Inl(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const unsigned int flags = pUnit ? pUnit->dwFlagEx : 0;
        return (flags >> 25) & 1;
    }

    return 0;
}

// 0x0062C590
int __stdcall ITEMS_CanBeImbued(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType_Inl(pItem) == 4 || ITEMS_CheckItemFlag_Inl(pItem, 0x1000))
    {
        return 0;
    }

    const int nItemId = pItem->dwClassId;
    if (!ITEMS_CheckBitField1Flag1(nItemId))
    {
        return 0;
    }

    if (!UNITS_IsExpansionChecked_Inl(pItem) && ITEMS_CheckIfThrowable(pItem))
    {
        return 0;
    }

    if (DATATBLS_GetItemsTxtRecord(nItemId)->nQuest && ITEMS_GetBaseCode(pItem) != ' gel')
    {
        return 0;
    }

    if (ITEMS_HasSocketedItem(pItem))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlag(pItem, 0x800, 4807, ".\\ITEMS\\Items.cpp"))
    {
        return 0;
    }

    const int nQuality = ITEMS_GetItemQuality(pItem);
    if (nQuality == 5 || nQuality == 4 || nQuality == 6 || nQuality == 8 || nQuality == 7 || nQuality == 9)
    {
        return 0;
    }

    return 1;
}

static inline D2ItemDataStrc* sub_T03_GetItemData(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
        return pItem->pItemData;
    return 0;
}

static inline int sub_T03_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = sub_T03_GetItemData(pItem))
        return pItemData->dwItemFlags & dwFlag;
    return 0;
}

static inline int sub_T03_GetClassId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// 0x0062C6A0
int __stdcall ITEMS_IsPersonalizable(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0x67D);

    const int nUnitType = hItem ? hItem->dwUnitType : UNIT_INVALID;
    if (!(nUnitType == 4 && ITEMS_GetItemTypeFromItemId(hItem->dwClassId) == 4)
        && !sub_T03_CheckItemFlag(hItem, 0x1000)
        && ITEMS_GetItemType(hItem) != ITEMTYPE_PLAYER_BODY_PART
        && ITEMS_GetItemType(hItem) != ITEMTYPE_BOW_QUIVER
        && ITEMS_GetItemType(hItem) != ITEMTYPE_CROSSBOW_QUIVER
        && !ITEMS_CheckItemFlag(hItem, 0x100, 0x12F7, ".\\ITEMS\\Items.cpp")
        && !(ITEMS_GetItemFlags(hItem) & 0x1000000)
        && !ITEMS_GetCompactSave(hItem))
    {
        return DATATBLS_GetItemsTxtRecord(sub_T03_GetClassId(hItem))->nNameable != 0;
    }
    return 0;
}

int __stdcall ITEMS_IsImbueable(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType_Inl(pItem) == 4 || ITEMS_CheckItemFlag_Inl(pItem, 0x1000))
    {
        return 0;
    }

    const int nItemId = pItem->dwClassId;
    if (!ITEMS_CheckBitField1Flag1(nItemId))
    {
        return 0;
    }

    if (!UNITS_IsExpansion_Inl(pItem) && ITEMS_CheckIfThrowable(pItem))
    {
        return 0;
    }

    if (DATATBLS_GetItemsTxtRecord(nItemId)->nQuest && ITEMS_GetBaseCode(pItem) != ' gel')
    {
        return 0;
    }

    if (ITEMS_HasSocketedItem(pItem))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlag(pItem, 0x800, 4807, ".\\ITEMS\\Items.cpp"))
    {
        return 0;
    }

    const int nQuality = ITEMS_GetItemQuality(pItem);
    if (nQuality == 5 || nQuality == 4 || nQuality == 6 || nQuality == 8 || nQuality == 7 || nQuality == 9)
    {
        return 0;
    }

    return 1;
}

// 0x0062C770
int __stdcall ITEMS_IsSocketable(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType_Inl(pItem) != 4 && !ITEMS_CheckItemFlag_Inl(pItem, 0x1000))
    {
        const int nItemId = pItem->dwClassId;
        if (!DATATBLS_GetItemsTxtRecord(nItemId)->nQuest || ITEMS_GetBaseCode(pItem) == ' gel')
        {
            if (!ITEMS_CheckItemFlag_Inl(pItem, 0x100) && !ITEMS_HasSocketedItem(pItem) && !ITEMS_CheckItemFlag(pItem, 0x800, 4907, ".\\ITEMS\\Items.cpp"))
            {
                if (ITEMS_GetMaxSockets(pItem))
                {
                    return !(unsigned char)ITEMS_GetSockets(pItem);
                }
            }
        }
    }

    return 0;
}

// 0x0062B3A0
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem)
{
    if (D2SetItemsTxt* pSetItemsTxtRecord = ITEMS_GetSetItemsTxtRecordFromItem_Inl(pItem))
    {
        return pSetItemsTxtRecord->nSetItems;
    }

    return -1;
}


// 0x0062B450
static void __stdcall ITEMS_GetBonusStatFromSockets(int nStatId, int* pValue, D2UnitStrc* pItem)
{
    *pValue = 0;
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (ITEMS_CheckIfSocketableByItemIdInl(pItem->dwClassId))
        {
                D2InventoryStrc* pInventory = pItem->pInventory;
            for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
            {
                D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
                if (sub_00451F70_GetUnitMode(pItem) == IMODE_EQUIP)
                {
                    *pValue += STATLIST_UnitGetStatValue(pSocketed, nStatId, 0);
                }
            }
        }
    }
}

static inline D2SkillsTxt* __fastcall DATATBLS_GetSkillsTxtRecordInl(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

int __fastcall STATLIST_HasSkillDesc(int nSkillId)
{
    if (D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordInl(nSkillId))
    {
        int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return 1;
    }
    return 0;
}

static inline void ITEMS_SetBodyLocInl(D2UnitStrc* pItem, unsigned char nBodyLoc)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nBodyLoc = nBodyLoc;
    }
}

static inline void ITEMS_SetInvPageInl(D2UnitStrc* pItem, char nInvPage)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nInvPage = nInvPage;
    }
}

static inline void ITEMS_SetItemLevelInl(D2UnitStrc* pItem, int nItemLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        if (nItemLevel < 1)
        {
            nItemLevel = 1;
        }
        pItem->pItemData->dwItemLevel = nItemLevel;
    }
}

static inline void ITEMS_SetItemQualityForceInl(D2UnitStrc* pItem, int nQuality)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->dwQualityNo = nQuality;
    }
}

static inline int ITEMS_GetItemQualityForceInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwQualityNo;
    }
    return ITEMQUAL_NORMAL;
}

static inline void ITEMS_SetInvGfxIndexInl(D2UnitStrc* pItem, unsigned char nInvGfxIdx)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nInvGfxIdx = nInvGfxIdx;
    }
}

static inline void ITEMS_SetAutoAffixInl(D2UnitStrc* pItem, unsigned short nAutoAffix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->wAutoAffix = nAutoAffix;
    }
}

static inline void ITEMS_SetMagicPrefixInl(D2UnitStrc* pItem, int nIndex, int nPrefix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->wMagicPrefix[nIndex] = nPrefix;
    }
}

static inline void ITEMS_SetMagicSuffixInl(D2UnitStrc* pItem, int nIndex, int nSuffix)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->wMagicSuffix[nIndex] = nSuffix;
    }
}

static inline void ITEMS_SetEarLevelInl(D2UnitStrc* pItem, unsigned char nEarLevel)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->nEarLvl = nEarLevel;
    }
}

static inline int UNITS_GetClassIdInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static inline D2ItemStatCostTxt* ITEMS_GetRecF3(int nStatId)
{
    if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

static inline D2ItemDataStrc* ITEMS_GetItemDataForceInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

static inline unsigned int ITEMS_GetItemFlagsForceInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataForceInl(pItem);
    return pItemData ? pItemData->dwItemFlags : 0;
}

static inline char* ITEMS_GetEarNameForceInl(D2UnitStrc* pItem)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataForceInl(pItem);
    return pItemData ? pItemData->szPlayerName : 0;
}

static __forceinline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordRangeInl(int nStatId)
{
    if (nStatId < sgptDataTables->nItemStatCostTxtRecordCount && nStatId >= 0)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0062CBE0
static int __stdcall ITEMS_DecodeItemBitstreamComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bCheckForHeader, int bGamble, int* pSocketedItems, unsigned int dwVersion)
{
    int bError = 0;
    int nStatLists;
    int nSetItemMask;
    int nTabLevel;
    int nSkillValue;
    unsigned int dwCode;
    int v237, v238, nSkillId, v240, v241, v242, v243, v244, v245, v246, v247, v248, v249, v250, v251, v252;
    int nLastStatId;
    D2ItemStatCostTxt* pItemStatCostTxtRecord;
    D2ItemsTxt* pItemsTxtRecord;
    D2StatListStrc* pStatList;
    char* szName;
    char szChar;
    int nValue;
    int nBits;
    int nStatId;

    ITEMS_SetItemFormat(pItem, BITMANIP_ReadInl(pBuffer, 10));

    const int nAnimMode = BITMANIP_ReadInl(pBuffer, 3);
    if (nAnimMode != IMODE_ONGROUND && nAnimMode != IMODE_DROPPING)
    {
        ITEMS_SetBodyLocInl(pItem, BITMANIP_ReadInl(pBuffer, 4));
        UNITS_SetXForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 4));
        UNITS_SetYForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 4));
        ITEMS_SetInvPageInl(pItem, BITMANIP_ReadInl(pBuffer, 3) - 1);
    }
    else
    {
        UNITS_SetXForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 16));
        UNITS_SetYForStaticUnit(pItem, BITMANIP_ReadInl(pBuffer, 16));
    }

    UNITS_ChangeAnimMode(pItem, nAnimMode);

    dwCode = BITMANIP_ReadInl(pBuffer, 32);
    const int nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
    if (nClassId >= 0 && pItem)
    {
        pItem->dwClassId = nClassId;
    }

    if (bGamble)
    {
        ITEMS_SetItemLevelInl(pItem, 1);
        ITEMS_SetItemQualityForceInl(pItem, ITEMQUAL_INFERIOR);
        return 1;
    }

    const int nSocketedItems = BITMANIP_ReadInl(pBuffer, 3);
    if (pSocketedItems)
    {
        *pSocketedItems = nSocketedItems;
    }

    if (bCheckForHeader)
    {
        pItem->dwInitSeed = BITMANIP_ReadInl(pBuffer, 32);
        SEED_InitLowSeed(&pItem->pSeed, pItem->dwInitSeed);
    }

    int nItemLevel = BITMANIP_ReadInl(pBuffer, 7);
    if (nItemLevel < 0)
    {
        nItemLevel = 1;
    }
    ITEMS_SetItemLevelInl(pItem, nItemLevel);

    ITEMS_SetItemQualityForceInl(pItem, BITMANIP_ReadInl(pBuffer, 4));

    if (BITMANIP_ReadInl(pBuffer, 1))
    {
        ITEMS_SetInvGfxIndexInl(pItem, BITMANIP_ReadInl(pBuffer, 3));
    }

    D2MagicAffixDataTbl* pMagicAffixDataTbl = DATATBLS_GetMagicAffixDataTables();
    int nMagicPrefixOffset = pMagicAffixDataTbl->pMagicPrefix - pMagicAffixDataTbl->pMagicAffixTxt;
    int nAutoMagicOffset = pMagicAffixDataTbl->pAutoMagic - pMagicAffixDataTbl->pMagicAffixTxt;

    switch (dwVersion)
    {
    case 72:
    case 73:
    case 80:
    case 81:
    case 82:
        nMagicPrefixOffset -= 661;
        nAutoMagicOffset -= 1262;
        break;
    case 83:
    case 84:
        nMagicPrefixOffset -= 674;
        nAutoMagicOffset -= 1265;
        break;
    case 85:
    case 86:
    case 87:
        nMagicPrefixOffset -= 675;
        nAutoMagicOffset -= 1266;
        break;
    case 88:
        nMagicPrefixOffset -= 729;
        nAutoMagicOffset -= 1440;
        break;
    default:
        break;
    }

    if (BITMANIP_ReadInl(pBuffer, 1))
    {
        unsigned short nAutoAffix = BITMANIP_ReadInl(pBuffer, 11);
        if (dwVersion <= 88)
        {
            nAutoAffix = 0;
        }
        else
        {
            if (dwVersion <= 89)
            {
                ++nAutoAffix;
            }

            if (nAutoAffix > 0)
            {
                nAutoAffix += nAutoMagicOffset;
            }
        }
        ITEMS_SetAutoAffixInl(pItem, nAutoAffix);
    }
    else
    {
        ITEMS_SetAutoAffixInl(pItem, 0);
    }

    switch (ITEMS_GetItemQualityForceInl(pItem))
    {
    case 1:
    case 3:
        ITEMS_SetFileIndex(pItem, BITMANIP_ReadInl(pBuffer, 3));
        break;

    case 2:
        if (ITEMSIsA(pItem, 13))
        {
            if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
            {
                if (BITMANIP_ReadInl(pBuffer, 1))
                {
                    unsigned short nPrefix = BITMANIP_ReadInl(pBuffer, 11);
                    if (nPrefix > 0)
                    {
                        nPrefix += nMagicPrefixOffset;
                    }
                    sub_00627EF0(pItem, nPrefix, 0);
                }
                else
                {
                    sub_00627FB0(pItem, BITMANIP_ReadInl(pBuffer, 11), 0);
                }
            }
        }

        if (ITEMSIsA(pItem, 40) && !ITEMSIsA(pItem, 7))
        {
            ITEMS_SetFileIndex(pItem, BITMANIP_ReadInl(pBuffer, 10));
        }

        if (ITEMSIsA(pItem, 22) || ITEMSIsA(pItem, 18))
        {
            sub_00627FB0(pItem, BITMANIP_ReadInl(pBuffer, 5), 0);
        }
        break;

    case 6:
    case 8:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_AssignRarePrefix(pItem, BITMANIP_ReadInl(pBuffer, 8));
            sub_00628070(pItem, BITMANIP_ReadInl(pBuffer, 8));
        }

        for (int i = 0; i < 3; ++i)
        {
            if (BITMANIP_ReadInl(pBuffer, 1))
            {
                unsigned short nPrefix = BITMANIP_ReadInl(pBuffer, 11);
                if (dwVersion <= 89)
                {
                    ++nPrefix;
                }

                if (nPrefix > 0)
                {
                    nPrefix += nMagicPrefixOffset;
                }
                ITEMS_SetMagicPrefixInl(pItem, i, nPrefix);
            }
            else
            {
                ITEMS_SetMagicPrefixInl(pItem, i, 0);
            }

            if (BITMANIP_ReadInl(pBuffer, 1))
            {
                unsigned short nSuffix = BITMANIP_ReadInl(pBuffer, 11);
                if (dwVersion <= 89)
                {
                    ++nSuffix;
                }
                ITEMS_SetMagicSuffixInl(pItem, i, nSuffix);
            }
            else
            {
                ITEMS_SetMagicSuffixInl(pItem, i, 0);
            }
        }
        break;

    case 9:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_AssignRarePrefix(pItem, BITMANIP_ReadInl(pBuffer, 8));
            sub_00628070(pItem, BITMANIP_ReadInl(pBuffer, 8));
        }
        break;

    case 4:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            unsigned short nPrefix = BITMANIP_ReadInl(pBuffer, 11);
            if (nPrefix > 0)
            {
                nPrefix += nMagicPrefixOffset;
            }
            sub_00627EF0(pItem, nPrefix, 0);

            unsigned short nSuffix = BITMANIP_ReadInl(pBuffer, 11);
            sub_00627FB0(pItem, nSuffix, 0);
        }
        break;

    case 7:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            int nFileIndex = BITMANIP_ReadInl(pBuffer, 12);
            if (nFileIndex < 0)
            {
                nFileIndex = -1;
            }
            if (nFileIndex >= sgptDataTables->nUniqueItemsTxtRecordCount)
            {
                nFileIndex = -1;
            }
            ITEMS_SetFileIndex(pItem, nFileIndex);
        }
        break;

    case 5:
        if (bCheckForHeader || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            const int nSetRecordId = BITMANIP_ReadInl(pBuffer, 12);
            if (dwVersion <= 92)
            {
                D2SetsTxt* pSetsTxtRecord = DATATBLS_GetSetsTxtRecord(nSetRecordId);
                if (pSetsTxtRecord)
                {
                    int nIndex = -1;
                    for (int i = 0; i < pSetsTxtRecord->nSetItems; ++i)
                    {
                        if (pSetsTxtRecord->pSetItem[i]->dwItemCode == dwCode)
                        {
                            nIndex = i;
                            break;
                        }
                    }

                    if (nIndex < 0)
                    {
                        bError = 1;
                    }
                    else
                    {
                        ITEMS_SetFileIndex(pItem, pSetsTxtRecord->pSetItem[nIndex]->wSetItemId);
                    }
                }
                else
                {
                    bError = 1;
                }
            }
            else
            {
                D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(nSetRecordId);
                if (pSetItemsTxtRecord)
                {
                    ITEMS_SetFileIndex(pItem, pSetItemsTxtRecord->wSetItemId);
                }
                else
                {
                    bError = 1;
                }
            }
        }
        break;

    default:
        bError = 1;
        break;
    }

    int bRuneword = 0;
    if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_RUNEWORD)
    {
        bRuneword = 1;
        ITEMS_SetMagicPrefixInl(pItem, 0, BITMANIP_ReadInl(pBuffer, 16));
    }

    if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_ISEAR)
    {
        szName = ITEMS_GetEarNameForceInl(pItem);
        ITEMS_SetFileIndex(pItem, BITMANIP_ReadInl(pBuffer, 3));
        ITEMS_SetEarLevelInl(pItem, BITMANIP_ReadInl(pBuffer, 7));
        do
        {
            szChar = (char)BITMANIP_ReadInl(pBuffer, 7);
            *szName++ = szChar;
        }
        while (szChar);
    }
    else if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_PERSONALIZED)
    {
        szName = ITEMS_GetEarNameForceInl(pItem);
        do
        {
            szChar = (char)BITMANIP_ReadInl(pBuffer, 7);
            *szName++ = szChar;
        }
        while (szChar);
    }

    if (bCheckForHeader && dwVersion > 86 && BITMANIP_ReadInl(pBuffer, 1))
    {
        const int nRealmData0 = BITMANIP_ReadInl(pBuffer, 32);
        const int nRealmData1 = BITMANIP_ReadInl(pBuffer, 32);
        if (dwVersion > 93)
        {
            BITMANIP_ReadInl(pBuffer, 32);
        }
        ITEMS_SetRealmData(pItem, nRealmData0, nRealmData1);
    }

    int b109 = 0;
    if (dwVersion < 93)
    {
        b109 = 1;
    }

    if (ITEMSIsA(pItem, 50))
    {
        pItemStatCostTxtRecord = ITEMS_GetRecF3(31);
        nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
        STATLIST_SetUnitStat(pItem, 31, nValue, 0);

        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInl(pItem));
        D2_ASSERT(pItemsTxtRecord, 6326);

        STATLIST_SetUnitStat(pItem, 20, pItemsTxtRecord->nBlock, 0);
        STATLIST_SetUnitStat(pItem, 67, -pItemsTxtRecord->dwSpeed, 0);

        pItemStatCostTxtRecord = ITEMS_GetRecF3(73);
        nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
        STATLIST_SetUnitStat(pItem, 73, nValue, 0);

        if (nValue)
        {
            pItemStatCostTxtRecord = ITEMS_GetRecF3(72);
            nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
            if (dwVersion <= 95)
            {
                nBits = 8;
            }

            nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
            STATLIST_SetUnitStat(pItem, 72, nValue, 0);
        }
    }
    else if (ITEMSIsA(pItem, 45))
    {
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInl(pItem));
        D2_ASSERT(pItemsTxtRecord, 6349);

        STATLIST_SetUnitStat(pItem, 68, -pItemsTxtRecord->dwSpeed, 0);

        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_INFERIOR)
        {
            if (pItemsTxtRecord->nMaxDam)
            {
                nValue = 3 * pItemsTxtRecord->nMaxDam / 4;
                if (nValue < 2)
                {
                    nValue = 2;
                }
                STATLIST_SetUnitStat(pItem, 22, nValue, 0);
            }

            if (pItemsTxtRecord->nMinDam)
            {
                nValue = 3 * pItemsTxtRecord->nMinDam / 4;
                if (nValue < 1)
                {
                    nValue = 1;
                }
                STATLIST_SetUnitStat(pItem, 21, nValue, 0);
            }

            if (pItemsTxtRecord->n2HandMaxDam)
            {
                nValue = 3 * pItemsTxtRecord->n2HandMaxDam / 4;
                if (nValue < 2)
                {
                    nValue = 2;
                }
                STATLIST_SetUnitStat(pItem, 24, nValue, 0);
            }

            if (pItemsTxtRecord->n2HandMinDam)
            {
                nValue = 3 * pItemsTxtRecord->n2HandMinDam / 4;
                if (nValue < 1)
                {
                    nValue = 1;
                }
                STATLIST_SetUnitStat(pItem, 23, nValue, 0);
            }

            if (pItemsTxtRecord->nMaxMisDam)
            {
                nValue = 3 * pItemsTxtRecord->nMinMisDam / 4;
                if (nValue < 1)
                {
                    nValue = 1;
                }
                STATLIST_SetUnitStat(pItem, 159, nValue, 0);

                nValue = 3 * pItemsTxtRecord->nMaxMisDam / 4;
                if (nValue < 2)
                {
                    nValue = 2;
                }
                STATLIST_SetUnitStat(pItem, 160, nValue, 0);
            }
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 22, pItemsTxtRecord->nMaxDam, 0);
            STATLIST_SetUnitStat(pItem, 21, pItemsTxtRecord->nMinDam, 0);
            STATLIST_SetUnitStat(pItem, 24, pItemsTxtRecord->n2HandMaxDam, 0);
            STATLIST_SetUnitStat(pItem, 23, pItemsTxtRecord->n2HandMinDam, 0);

            if (pItemsTxtRecord->nMaxMisDam)
            {
                STATLIST_SetUnitStat(pItem, 159, pItemsTxtRecord->nMinMisDam, 0);
                STATLIST_SetUnitStat(pItem, 160, pItemsTxtRecord->nMaxMisDam, 0);
            }
        }

        if (ITEMS_IsEthereal(pItem))
        {
            STATLIST_SetUnitStat(pItem, 21, 3 * STATLIST_GetUnitBaseStat(pItem, 21, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 22, 3 * STATLIST_GetUnitBaseStat(pItem, 22, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 23, 3 * STATLIST_GetUnitBaseStat(pItem, 23, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 24, 3 * STATLIST_GetUnitBaseStat(pItem, 24, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 159, 3 * STATLIST_GetUnitBaseStat(pItem, 159, 0) / 2, 0);
            STATLIST_SetUnitStat(pItem, 160, 3 * STATLIST_GetUnitBaseStat(pItem, 160, 0) / 2, 0);
        }

        pItemStatCostTxtRecord = ITEMS_GetRecF3(73);
        nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
        STATLIST_SetUnitStat(pItem, 73, nValue, 0);

        if (nValue)
        {
            pItemStatCostTxtRecord = ITEMS_GetRecF3(72);
            nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
            if (dwVersion <= 95)
            {
                nBits = 8;
            }

            nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
            STATLIST_SetUnitStat(pItem, 72, nValue, 0);
        }
    }
    else if (ITEMSIsA(pItem, 4))
    {
        if (BITMANIP_ReadInl(pBuffer, 1))
        {
            STATLIST_SetUnitStat(pItem, 14, BITMANIP_ReadInl(pBuffer, 32), 0);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 14, BITMANIP_ReadInl(pBuffer, 12), 0);
        }
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        if (dwVersion <= 80)
        {
            STATLIST_SetUnitStat(pItem, 70, BITMANIP_ReadInl(pBuffer, 8), 0);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, 70, BITMANIP_ReadInl(pBuffer, 9), 0);
        }
    }

    if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_SOCKETED)
    {
        pItemStatCostTxtRecord = ITEMS_GetRecF3(194);
        ITEMS_AddSockets(pItem, BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]));
    }

    if (bCheckForHeader || ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_IDENTIFIED)
    {

    nStatLists = 0;
    nSetItemMask = 0;
    if (dwVersion > 84 && ITEMS_GetItemQualityForceInl(pItem) == ITEMQUAL_SET)
    {
        nStatLists = 5;
        nSetItemMask = BITMANIP_ReadInl(pBuffer, 5);
    }

    if (bRuneword)
    {
        ++nStatLists;
    }

    for (int nCounter = -1; nCounter < nStatLists; ++nCounter)
    {
        int nState;
        int nFlag;
        if (nCounter < 0)
        {
            nState = 0;
            nFlag = 0x40;
        }
        else if (bRuneword && nCounter == nStatLists - 1)
        {
            nState = 171;
            nFlag = 0x40;
        }
        else if (nSetItemMask & (1 << nCounter))
        {
// build: symbol ?gnItemSetStatesBySetIndex@* 0x006E90B8
            nState = gnItemSetStatesBySetIndex[nCounter];
            nFlag = 0x2040;
        }
        else
        {
            continue;
        }

        pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, nState, nFlag);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(GFXUTIL_GetNextRosterInfo(pItem), nFlag, 0, UNIT_ITEM, GAME_GetUnitGUID(pItem));
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
            STATLIST_SetState(pStatList, nState);
        }

        nLastStatId = -1;
        nStatId = BITMANIP_ReadInl(pBuffer, 9);
        if (nStatId != 511)
        {
        do
        {
            if (!nStatId && !nLastStatId)
            {
                bError = 1;
                break;
            }

            nLastStatId = nStatId;

            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(nStatId);
            if (!pItemStatCostTxtRecord)
            {
                break;
            }

            switch (nStatId)
            {
            case 0:
            case 2:
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, nStatId, nValue, 0);
                break;

            case 3:
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 3, nValue, 0);

                if (dwVersion <= 85)
                {
                    pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(7);
                    nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                    STATLIST_SetStatIfListIsValid(pStatList, 7, nValue << 8, 0);
                }
                break;

            case 1:
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 1, nValue, 0);

                if (dwVersion <= 85)
                {
                    pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(9);
                    nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                    STATLIST_SetStatIfListIsValid(pStatList, 9, nValue, 0);
                }
                break;

            case 17:
                ITEMS_SetDefenseOrDamage(pItem, 17);

                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 17, nValue, 0);

                ITEMS_SetDefenseOrDamage(pItem, 18);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(18);
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 18, nValue, 0);
                break;

            case 48:
                nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
                if (dwVersion <= 81)
                {
                    nBits = 6;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 48, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(49);
                nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 49, nValue, 0);
                break;

            case 50:
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 50, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(51);
                nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 51, nValue, 0);
                break;

            case 52:
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 52, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(53);
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 53, nValue, 0);
                break;

            case 54:
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 54, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(55);
                nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 55, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(56);
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 56, nValue, 0);
                break;

            case 57:
                nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
                if (dwVersion <= 81)
                {
                    nBits = 7;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 57, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(58);
                nBits = (&pItemStatCostTxtRecord->nSaveBits)[b109];
                if (dwVersion <= 81)
                {
                    nBits = 8;
                }

                nValue = BITMANIP_ReadInl(pBuffer, nBits) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 58, nValue, 0);

                pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordRangeInl(59);
                nValue = BITMANIP_ReadInl(pBuffer, (&pItemStatCostTxtRecord->nSaveBits)[b109]) - (&pItemStatCostTxtRecord->dwSaveAdd)[b109];
                STATLIST_SetStatIfListIsValid(pStatList, 59, nValue, 0);
                STATLIST_SetStatIfListIsValid(pStatList, 326, 1, 0);
                break;

            case 134:
                if (dwVersion <= 89)
                {
                    BITMANIP_ReadInl(pBuffer, 16);
                    STATLIST_SetStatIfListIsValid(pStatList, 134, 1, 0);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 134, dwVersion, b109);
                }
                break;

            case 83:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    STATLIST_SetStatValue(pStatList, 83, nValue, 0);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 83, dwVersion, b109);
                }
                break;

            case 84:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    STATLIST_SetStatValue(pStatList, 83, nValue, 3);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 84, dwVersion, b109);
                }
                break;

            case 85:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    STATLIST_SetStatValue(pStatList, 83, nValue, 2);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 85, dwVersion, b109);
                }
                break;

            case 86:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    STATLIST_SetStatValue(pStatList, 83, nValue, 1);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 86, dwVersion, b109);
                }
                break;

            case 87:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    STATLIST_SetStatValue(pStatList, 83, nValue, 4);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 87, dwVersion, b109);
                }
                break;

            case 179:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    STATLIST_SetStatValue(pStatList, 83, nValue, 5);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 179, dwVersion, b109);
                }
                break;

            case 180:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 3);
                    STATLIST_SetStatValue(pStatList, 83, nValue, 6);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 180, dwVersion, b109);
                }
                break;

            case 188:
            case 189:
            case 190:
            case 191:
            case 192:
            case 193:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 10);
                    D2Common_10848(nValue, &v238, &v237, &nTabLevel);
                    if (nTabLevel > 7)
                    {
                        nTabLevel = 7;
                    }
                    STATLIST_SetStatValue(pStatList, 188, nTabLevel, v237 + 8 * v238);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 126:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 4);
                    STATLIST_SetStatValue(pStatList, 126, nValue, 1);
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, 126, dwVersion, b109);
                }
                break;

            case 107:
            case 108:
            case 109:
            case 181:
            case 182:
            case 183:
            case 184:
            case 185:
            case 186:
            case 187:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 14);
                    D2Common_10844_ITEMMODS_First(nValue, &nSkillId, &nSkillValue);

                    int nMax = 7;
                    D2ItemStatCostTxt* pSingleSkillTxtRecord = PLAYER_GetItemStatCostTxtRecord(107);
                    if (pSingleSkillTxtRecord)
                    {
                        nMax = (1 << pSingleSkillTxtRecord->nSaveBits) - 1;
                    }

                    if (nSkillValue > 0 && nSkillValue <= nMax)
                    {
                        if (STATLIST_HasSkillDesc(nSkillId))
                        {
                            STATLIST_SetStatValue(pStatList, 107, nSkillValue, nSkillId);
                        }
                    }
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 195:
            case 196:
            case 197:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 21);
                    D2Common_10845(nValue, &v241, &v240, &v242);
                    STATLIST_SetStatValue(pStatList, 195, v242, (v240 & 0x3F) + ((unsigned short)v241 << 6));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 198:
            case 199:
            case 200:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 21);
                    D2Common_10845(nValue, &v244, &v243, &v245);
                    STATLIST_SetStatValue(pStatList, 198, v245, (v243 & 0x3F) + ((unsigned short)v244 << 6));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 201:
            case 202:
            case 203:
                if (dwVersion <= 92)
                {
                    nValue = BITMANIP_ReadInl(pBuffer, 21);
                    D2Common_10845(nValue, &v247, &v246, &v248);
                    STATLIST_SetStatValue(pStatList, 201, v248, (v246 & 0x3F) + ((unsigned short)v247 << 6));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            case 204:
            case 205:
            case 206:
            case 207:
            case 208:
            case 209:
            case 210:
            case 211:
            case 212:
            case 213:
                if (dwVersion <= 92)
                {
                    if (dwVersion <= 73)
                    {
                        nValue = BITMANIP_ReadInl(pBuffer, 29);
                    }
                    else
                    {
                        nValue = BITMANIP_ReadInl(pBuffer, 30);
                    }
                    D2Common_10846(nValue, &v249, &v250, &v251, &v252);
                    STATLIST_SetStatValue(pStatList, 204, (v251 & 0xFF) + (v252 << 8), (v250 & (unsigned short)sgptDataTables->nShiftedStuff) + ((unsigned short)v249 << sgptDataTables->nStuff));
                }
                else
                {
                    ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                }
                break;

            default:
                ITEMS_ReadStatFromItemBitstream(pBuffer, pStatList, pItemStatCostTxtRecord, nStatId, dwVersion, b109);
                break;
            }
        }
        while ((nStatId = BITMANIP_ReadInl(pBuffer, 9)) != 511);
        }

        if (dwVersion <= 92)
        {
            const int nValue = STATLIST_GetStatValue(pStatList, 83, 0);
            if (nValue > 0)
            {
                if (nValue == STATLIST_GetStatValue(pStatList, 83, 1) && nValue == STATLIST_GetStatValue(pStatList, 83, 2)
                    && nValue == STATLIST_GetStatValue(pStatList, 83, 3) && nValue == STATLIST_GetStatValue(pStatList, 83, 4))
                {
                    for (int i = 0; i < 7; ++i)
                    {
                        STATLIST_SetStatIfListIsValid(pStatList, 83, 0, i);
                    }

                    STATLIST_SetStatIfListIsValid(pStatList, 127, nValue, 0);
                }
            }
        }
    }

    }

    return 2 * (bError == 0) - 1;
}

unsigned int __fastcall sub_M111_Emit_0062A960(D2BitBufferStrc* pBuffer, int nBits)
{
    return ITEMS_ReadBits(pBuffer, nBits) + 1;
}

inline int ITEMS_CheckItemFlagData_Inl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwItemFlags & dwFlag;
    }

    return 0;
}

// 0x0062E6F0
int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->wShoots;
        }
    }

    return 0;
}

inline void ITEMS_ClearItemFlags(D2UnitStrc* pItem)
{
    const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
    if (nUnitType == UNIT_ITEM && pItem->pItemData)
        pItem->pItemData->dwItemFlags = 0;
}

// 0x0062E740
int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->wQuiver;
        }
    }

    return 0;
}

inline D2ItemTypesTxt* DATATBLS_GetItemTypesTxtRecordInl(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }
    return 0;
}

inline int ITEMS_GetItemTypeInl(D2UnitStrc* pItem)
{
    return !pItem || pItem->dwUnitType != UNIT_ITEM ? 0 : ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
}

// 0x0062E790
unsigned int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->nAutoStack;
        }
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemDataTypeInl(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return nType == UNIT_ITEM ? pItem->pItemData : 0;
}

inline int ITEMS_CheckItemFlagLineInl(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile)
{
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataTypeInl(pItem);
    if (pItemData)
    {
        return pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

// 0x0062E660
int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem)
{
    if (!ITEMS_CheckItemFlagLineInl(pItem, IFLAG_IDENTIFIED, 0, 0) || ITEMS_CheckItemFlagLineInl(pItem, IFLAG_ETHEREAL, 0, 0))
    {
        return 0;
    }

    int bHasChargedSkills;
    if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills)
    {
        return 1;
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = sub_00555C90_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
    if (!pItemTypesTxtRecord || !pItemTypesTxtRecord->nRepair)
    {
        return 0;
    }

    if (ITEMS_IsQuantityRepairable(pItem))
    {
        return 1;
    }

    return ITEMS_HasDurability(pItem) != 0;
}

// 0x0062E7E0
unsigned int __stdcall ITEMS_GetReload(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        if (D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem)))
        {
            return pItemTypesTxtRecord->nReload;
        }
    }

    return 0;
}

// 0x0062E830
unsigned int __stdcall ITEMS_GetReEquip(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nReEquip;
        }
    }

    return 0;
}

// 0x0062E880
unsigned char __stdcall ITEMS_GetStorePage(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord && pItemTypesTxtRecord->nStorePage != 0xFF)
        {
            return pItemTypesTxtRecord->nStorePage;
        }
    }

    return 0xFF;
}

// 0x0062E8D0
unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nVarInvGfx;
        }
    }

    return 0;
}

// 0x0062E920
char* __stdcall ITEMS_GetVarInvGfxString(D2UnitStrc* pItem, int nId)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            nId = D2_MIN(D2_MAX(nId, 0), pItemTypesTxtRecord->nVarInvGfx - 1);

            return pItemTypesTxtRecord->szInvGfx[nId];
        }
    }

    return gpszDefaultString;
}

// 0x0062E990
int __stdcall ITEMS_CanBeRare(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nRare;
        }
    }

    return 0;
}

// 0x0062E9E0
int __stdcall ITEMS_CanBeMagic(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nMagic;
        }
    }

    return 0;
}

// 0x0062EA30
int __stdcall ITEMS_CanBeNormal(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (pItemTypesTxtRecord)
        {
            return pItemTypesTxtRecord->nNormal;
        }
    }

    return 1;
}

// 0x0062EA80
void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
        if (!pItemTypesTxtRecord)
        {
            *pBodyLoc1 = 0;
            *pBodyLoc2 = 0;
            return;
        }

        *pBodyLoc1 = pItemTypesTxtRecord->nBodyLoc1;
        *pBodyLoc2 = pItemTypesTxtRecord->nBodyLoc2;
        return;
    }

    *pBodyLoc1 = 0;
    *pBodyLoc2 = 0;
}

// 0x0062ED50
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM)
    {
        unsigned char nBodyLoc1 = 0;
        unsigned char nBodyLoc2 = 0;
        ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

        if (nBodyLoc1 == nBodyLoc || nBodyLoc2 == nBodyLoc
            || (nBodyLoc == BODYLOC_SWRARM || nBodyLoc == BODYLOC_SWLARM) && (nBodyLoc1 == BODYLOC_RARM || nBodyLoc2 == BODYLOC_RARM || nBodyLoc1 == BODYLOC_LARM || nBodyLoc2 == BODYLOC_LARM))
        {
            return 1;
        }
    }

    return 0;
}

// 0x0062EDD0
static void __stdcall ITEMS_CalculateAdditionalCostsForItemSkill(D2UnitStrc* pItem, int* pSellCost, int* pBuyCost, int* pRepCost, unsigned int nDivisor)
{
    D2StatStrc pStat[64];
    if (ITEMS_GetStaffMods(pItem) != 7)
    {
        unsigned int nSell = 0;
        unsigned int nBuy = 0;
        unsigned int nRep = 0;
        const int nStats = STATLIST_CopyStats(pItem, 107, pStat, 64);

        for (int i = 0; i < nStats; ++i)
        {
            const int nSkillId = pStat[i].nLayer;
            const int nValue = pStat[i].nValue;
            D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
            if (pSkillsTxtRecord)
            {
                    const int nFactor = 2 * nValue - 1;
                    if (*pSellCost > 65535 && pSkillsTxtRecord->nCostMult)
                    {
                        nSell += nFactor * (pSkillsTxtRecord->nCostAdd + *pSellCost * (pSkillsTxtRecord->nCostMult / 1024));
                        nBuy += nFactor * (pSkillsTxtRecord->nCostAdd + *pBuyCost * (pSkillsTxtRecord->nCostMult / 4096));
                        nRep += nFactor * (pSkillsTxtRecord->nCostAdd + *pRepCost * (pSkillsTxtRecord->nCostMult / 1024));
                    }
                    else
                    {
                        nSell += nFactor * (pSkillsTxtRecord->nCostAdd + pSkillsTxtRecord->nCostMult * *pSellCost / 1024);
                        nBuy += nFactor * (pSkillsTxtRecord->nCostAdd + pSkillsTxtRecord->nCostMult * *pBuyCost / 4096);
                        nRep += nFactor * (pSkillsTxtRecord->nCostAdd + pSkillsTxtRecord->nCostMult * *pRepCost / 1024);
                    }
            }
        }

        *pSellCost += nSell / nDivisor;
        *pBuyCost += nBuy / nDivisor;
        *pRepCost += nRep / nDivisor;
    }
}

// 0x0062EFB0
int __fastcall ITEMS_CalculateTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* hItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType)
{
    int nSellCost;
    int nBuyCost;
    int nRepCost;
    int nDivisor;

    if (!pPlayer || (hItem ? hItem->dwUnitType : UNIT_INVALID) != UNIT_ITEM)
    {
        return 0x7FFFFFFF;
    }

    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, 12, 0);

    if (nTransactionType == 3 && !ITEMS_IsRepairable(hItem))
    {
        return 0;
    }

    if (ITEMS_CheckItemFlagInl(hItem, 0x20000))
    {
        return 1;
    }

    const int nClassId = hItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);

    int nQuantity = STATLIST_UnitGetStatValue(hItem, 70, 0);
    if (nQuantity <= 0)
    {
        nQuantity = 1;
    }

    int nReducePricePct = STATLIST_UnitGetStatValue(pPlayer, 87, 0);
    if (nReducePricePct >= 99)
    {
        nReducePricePct = 99;
    }

    if (nTransactionType == 2)
    {
        if (ITEMS_GetItemFormat(hItem) >= 1)
        {
            int nCost = ITEMS_GetGambleCost(nLevel, hItem);
            if (nReducePricePct)
            {
                nCost -= DATATBLS_ApplyRatio(nCost, nReducePricePct, 100);
            }
            return nCost;
        }

        const unsigned int dwNormalCode = ITEMS_GetNormalCode(hItem);
        return DATATBLS_GetItemsTxtRecord(DATATBLS_GetItemIdFromItemCode(dwNormalCode))->dwGambleCost;
    }

    nRepCost = 0;
    nDivisor = 1;

    if (ITEMS_GetItemFlags(hItem) & 0x10000)
    {
        nSellCost = ITEMS_GetEarLevel(hItem) * pItemsTxtRecord->dwCost;
        nBuyCost = nSellCost;
    }
    else if (ITEMSIsA(hItem, 40))
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(ITEMS_GetFileIndex(hItem));
        nSellCost = pItemsTxtRecord->dwCost + (pMonStatsTxtRecord ? 8 * pMonStatsTxtRecord->nLevel[nDifficulty] : 0);
        nBuyCost = nSellCost;
    }
    else if (ITEMSIsA(hItem, 18))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(hItem, 0));
        D2_ASSERT(pBooksTxtRecord, 3002);

        nSellCost = pBooksTxtRecord->dwCostPerCharge * nQuantity + pItemsTxtRecord->dwCost;
        nBuyCost = nSellCost;
    }
    else if (ITEMS_GetQuiverType(hItem))
    {
        nSellCost = pItemsTxtRecord->dwCost * nQuantity / 1024;
        nBuyCost = nSellCost;
        nRepCost = ITEMS_GetTotalMaxStack(hItem) * pItemsTxtRecord->dwCost / 1024;
    }
    else if (ITEMS_CheckIfStackable(hItem))
    {
        nSellCost = pItemsTxtRecord->dwCost;
        nBuyCost = nSellCost;
        nRepCost = nSellCost;

        nDivisor = ITEMS_GetTotalMaxStack(hItem) > 1 ? ITEMS_GetTotalMaxStack(hItem) : 1;
    }
    else
    {
        nSellCost = pItemsTxtRecord->dwCost;
        nRepCost = nSellCost;
        nBuyCost = nSellCost;
    }

    if (ITEMSIsA(hItem, 50))
    {
        const int nArmorClass = STATLIST_GetUnitBaseStat(hItem, 31, 0);
        if (pItemsTxtRecord->dwMaxAc - pItemsTxtRecord->dwMinAc + 1 != 0 && pItemsTxtRecord->dwMaxAc)
        {
            nSellCost = pItemsTxtRecord->dwCost * nArmorClass / pItemsTxtRecord->dwMaxAc;
            nBuyCost = pItemsTxtRecord->dwCost * nArmorClass / pItemsTxtRecord->dwMaxAc;
            nRepCost = pItemsTxtRecord->dwCost * nArmorClass / pItemsTxtRecord->dwMaxAc;
        }
    }

    const int bIdentified = ITEMS_CheckItemFlag(hItem, 0x10, 3044, ".\\ITEMS\\Items.cpp");
    const int bMagic = ITEMS_IsMagSetRarUniCrfOrTmp(hItem);
    const int nQuality = ITEMS_GetItemQuality(hItem);

    if (!bMagic)
    {
        ITEMS_CalculateAdditionalCostsForItemSkill(hItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
    }

    if (bIdentified)
    {
        int nSell = 0;
        int nBuy = 0;
        int nRep = 0;
        D2MagicAffixTxt* pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix(hItem));
        if (pMagicAffixTxtRecord)
        {
            if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
            {
                nSell = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                nBuy = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                nRep = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
            }
            else
            {
                nSell = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                nBuy = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                nRep = pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
            }
        }

        switch (nQuality)
        {
        case 6:
        case 8:
            for (int i = 0; i < 3; ++i)
            {
                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(hItem, i));
                if (pMagicAffixTxtRecord)
                {
                    if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                    }
                    else
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                    }
                }

                pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(hItem, i));
                if (pMagicAffixTxtRecord)
                {
                    if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                    }
                    else
                    {
                        nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                        nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                        nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                    }
                }
            }

            ITEMS_CalculateAdditionalCostsForBonusStats(hItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
            break;

        case 7:
            if (ITEMS_GetFileIndex(hItem) >= 0)
            {
                D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(hItem));
                if (pUniqueItemsTxtRecord)
                {
                    if (nSellCost > 65535 && pUniqueItemsTxtRecord->dwCostMult)
                    {
                        nSell += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * (nSellCost / 1024);
                        nBuy += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * (nBuyCost / 1024);
                        nRep += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * (nRepCost / 1024);
                    }
                    else
                    {
                        nSell += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * nSellCost / 1024;
                        nBuy += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * nBuyCost / 1024;
                        nRep += pUniqueItemsTxtRecord->dwCostAdd + pUniqueItemsTxtRecord->dwCostMult * nRepCost / 1024;
                    }
                    break;
                }
            }

        case 4:
            pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(hItem, 0));
            if (pMagicAffixTxtRecord)
            {
                if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                }
                else
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                }
            }

            pMagicAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(hItem, 0));
            if (pMagicAffixTxtRecord)
            {
                if (nSellCost > 65535 && pMagicAffixTxtRecord->dwMultiply)
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nSellCost / 1024);
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nBuyCost / 1024);
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * (nRepCost / 1024);
                }
                else
                {
                    nSell += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nSellCost / 1024;
                    nBuy += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nBuyCost / 1024;
                    nRep += pMagicAffixTxtRecord->dwAdd + pMagicAffixTxtRecord->dwMultiply * nRepCost / 1024;
                }
            }
            ITEMS_CalculateAdditionalCostsForBonusStats(hItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
            break;

        case 5:
        {
            D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(hItem));
            if (pSetItemsTxtRecord)
            {
                if (nSellCost > 65535 && pSetItemsTxtRecord->dwCostMult)
                {
                    nSell += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * (nSellCost / 1024);
                    nBuy += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * (nBuyCost / 1024);
                    nRep += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * (nRepCost / 1024);
                }
                else
                {
                    nSell += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * nSellCost / 1024;
                    nBuy += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * nBuyCost / 1024;
                    nRep += pSetItemsTxtRecord->dwCostAdd + pSetItemsTxtRecord->dwCostMult * nRepCost / 1024;
                }
            }
            break;
        }

        case 1:
            nSell = nSellCost / -2;
            nBuy = nBuyCost / -2;
            nRep = nRepCost / -2;
            break;

        case 3:
        case 9:
            ITEMS_CalculateAdditionalCostsForBonusStats(hItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
            break;

        }

        nSellCost += nSell / nDivisor;
        nBuyCost += nBuy / nDivisor;
        nRepCost += nRep / nDivisor;

        if (bMagic)
        {
            ITEMS_CalculateAdditionalCostsForItemSkill(hItem, &nSellCost, &nBuyCost, &nRepCost, nDivisor);
        }
    }

    ITEMS_CalculateAdditionalCostsForSocketables(hItem, &nSellCost, &nBuyCost, &nRepCost);

    if (ITEMS_CheckItemFlag(hItem, 0x400000, 3235, ".\\ITEMS\\Items.cpp"))
    {
        nBuyCost /= 4;
    }

    if (ITEMS_IsClassValid(hItem))
    {
        nBuyCost /= 4;
    }

    switch (nTransactionType)
    {
    case 1:
        if (ITEMS_IsEthereal(hItem) && ITEMS_HasDurability(hItem))
        {
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(hItem);
            const int nDurability = STATLIST_UnitGetStatValue(hItem, 72, 0);
            if (nMaxDurability && nDurability <= 0)
            {
                nBuyCost = 0;
            }
        }
        break;

    case 3:
        if (!ITEMS_GetQuiverType(hItem) && !ITEMS_CheckIfThrowable(hItem) && ITEMS_HasDurability(hItem))
        {
            const int nDurability = STATLIST_UnitGetStatValue(hItem, 72, 0);
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(hItem);
            if (nMaxDurability && nDurability < nMaxDurability)
            {
                if (STATLIST_UnitGetStatValue(hItem, 252, 0))
                {
                    if (nDurability >= nMaxDurability - 1)
                    {
                        nRepCost = 0;
                    }
                    else
                    {
                        nRepCost = (nMaxDurability - 1) * nRepCost / nMaxDurability;
                    }
                }
                else
                {
                    nRepCost = (nMaxDurability - nDurability) * nRepCost / nMaxDurability;
                }
            }
            else
            {
                nRepCost = 0;
            }
        }
        break;
    }

    D2NpcTxt* pNpcTxtRecord = DATATBLS_GetNpcTxtRecord(nVendorId);
    D2_ASSERT(pNpcTxtRecord, 3292);

    if (nSellCost > 65535 && pNpcTxtRecord->dwSellMult)
    {
        nSellCost = nSellCost / 1024 * pNpcTxtRecord->dwSellMult;
    }
    else
    {
        nSellCost = pNpcTxtRecord->dwSellMult * nSellCost / 1024;
    }

    if (nBuyCost > 65535 && pNpcTxtRecord->dwSellMult)
    {
        nBuyCost = nBuyCost / 1024 * pNpcTxtRecord->dwBuyMult;
    }
    else
    {
        nBuyCost = pNpcTxtRecord->dwBuyMult * nBuyCost / 1024;
    }

    if (nRepCost > 65535 && pNpcTxtRecord->dwRepMult)
    {
        nRepCost = nRepCost / 1024 * pNpcTxtRecord->dwRepMult;
    }
    else
    {
        nRepCost = pNpcTxtRecord->dwRepMult * nRepCost / 1024;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (pNpcTxtRecord->dwQuestFlag[i] && (QUESTRECORD_GetQuestState(pQuestFlags, pNpcTxtRecord->dwQuestFlag[i], 0) == 1
                                              || QUESTRECORD_GetQuestState(pQuestFlags, pNpcTxtRecord->dwQuestFlag[i], 1) == 1))
        {
            if (nSellCost > 65535 && pNpcTxtRecord->dwQuestSellMult[i])
            {
                nSellCost = nSellCost / 1024 * pNpcTxtRecord->dwQuestSellMult[i];
            }
            else
            {
                nSellCost = pNpcTxtRecord->dwQuestSellMult[i] * nSellCost / 1024;
            }

            if (nBuyCost > 65535 && pNpcTxtRecord->dwQuestBuyMult[i])
            {
                nBuyCost = nBuyCost / 1024 * pNpcTxtRecord->dwQuestBuyMult[i];
            }
            else
            {
                nBuyCost = pNpcTxtRecord->dwQuestBuyMult[i] * nBuyCost / 1024;
            }

            if (nRepCost > 65535 && pNpcTxtRecord->dwQuestRepMult[i])
            {
                nRepCost = nRepCost / 1024 * pNpcTxtRecord->dwQuestRepMult[i];
            }
            else
            {
                nRepCost = pNpcTxtRecord->dwQuestRepMult[i] * nRepCost / 1024;
            }
        }
    }

    if (!ITEMSIsA(hItem, 18) && !ITEMS_GetQuiverType(hItem))
    {
        nSellCost = nSellCost * nQuantity;

        if (ITEMS_CheckIfStackable(hItem) && ITEMS_IsRepairable(hItem))
        {
            const int nMaxStack = ITEMS_GetTotalMaxStack(hItem);
            if (nQuantity <= nMaxStack && nQuantity < nMaxStack && !STATLIST_UnitGetStatValue(hItem, 253, 0))
            {
                nRepCost *= nMaxStack - nQuantity;
            }
            else
            {
                nRepCost = 0;
            }

            nBuyCost = nMaxStack * nBuyCost - nRepCost;
        }
        else
        {
            nBuyCost = nBuyCost * nQuantity;
        }
    }

    if (nTransactionType == 3 && !ITEMS_IsEthereal(hItem))
    {
        nRepCost += ITEMS_CalculateAdditionalCostsForChargedSkills(hItem, 10000);
    }

    const int* pMaxBuy = pNpcTxtRecord->nMaxBuy;
    if (nBuyCost > pMaxBuy[nDifficulty])
    {
        nBuyCost = pMaxBuy[nDifficulty];
    }

    switch (nTransactionType)
    {
    case 1:
        return nBuyCost < 1 ? 1 : nBuyCost;

    case 3:
        if (nReducePricePct)
        {
            nRepCost -= DATATBLS_ApplyRatio(nRepCost, nReducePricePct, 100);
        }
        return nRepCost < 1 ? 1 : nRepCost;

    default:
        if (nReducePricePct)
        {
            nSellCost -= DATATBLS_ApplyRatio(nSellCost, nReducePricePct, 100);
        }
        return nSellCost < 1 ? 1 : nSellCost;
    }
}

inline D2ItemsTxt* ITEMS_GetItemsTxtRecordInl(D2UnitStrc* pItem)
{
    return DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
}

// 0x0062EAF0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* pStrength, int* pDexterity, int* pLevel)
{
    int nStrSocketBonus;
    int nBaseReqDex;
    int bIdentified;

    if (pStrength)
    {
        *pStrength = FALSE;
    }
    if (pDexterity)
    {
        *pDexterity = 0;
    }
    if (pLevel)
    {
        *pLevel = 0;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    D2ItemsTxt* pItemsTxtRecord = nType == UNIT_ITEM ? ITEMS_GetItemsTxtRecordInl(pItem) : 0;
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int bStrReqMet = TRUE;
    int bDexReqMet = TRUE;
    int bLevelReqMet = TRUE;
    if (pItem->dwUnitType == UNIT_ITEM)
    {
        const D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            bIdentified = pItemData->dwItemFlags & IFLAG_IDENTIFIED;
        }
        else
        {
            bIdentified = FALSE;
        }
    }
    else
    {
        bIdentified = FALSE;
    }
    const int nBaseReqStr = pItemsTxtRecord->wReqStr;
    nBaseReqDex = pItemsTxtRecord->wReqDex;

    int nReqStrBonus = 0;
    int nReqDexBonus = 0;
    if (const int nReqPctBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_REQ_PERCENT, 0))
    {
        nReqStrBonus = DATATBLS_ApplyRatio(nBaseReqStr, nReqPctBonus, 100);
        nReqDexBonus = DATATBLS_ApplyRatio(nBaseReqDex, nReqPctBonus, 100);
    }

    if (ITEMS_CheckItemFlagInl(pItem, IFLAG_ETHEREAL))
    {
        nReqStrBonus -= 10;
        nReqDexBonus -= 10;
    }

    const int nStrength = STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    if (nStrength <= 0)
    {
        bStrReqMet = 0;
    }
    else
    {
        const int nReqStr = nBaseReqStr + nReqStrBonus;
        if (nStrength < nReqStr)
        {
            bStrReqMet = 0;
        }
        else if (bEquipping && STATLIST_GetOwner(pItem, 0))
        {
            nStrSocketBonus = 0;
            ITEMS_GetBonusStatFromSockets(STAT_STRENGTH, &nStrSocketBonus, pItem);
            const int nAdjusted = nStrength - nStrSocketBonus;
            if (nAdjusted <= 0)
            {
                bStrReqMet = 0;
            }
            else if (nAdjusted < nReqStr)
            {
                bStrReqMet = 0;
            }
        }
    }

    const int nDexterity = STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
    if (nDexterity <= 0)
    {
        bDexReqMet = 0;
    }
    else
    {
        const int nReqDex = nBaseReqDex + nReqDexBonus;
        if (nDexterity < nReqDex)
        {
            bDexReqMet = 0;
        }
        else if (bEquipping)
        {
            int nSocketBonus = 0;
            ITEMS_GetBonusStatFromSockets(STAT_DEXTERITY, &nSocketBonus, pItem);
            const int nAdjusted = nDexterity - nSocketBonus;
            if (nAdjusted <= 0)
            {
                bDexReqMet = 0;
            }
            if (nAdjusted < nReqDex)
            {
                bDexReqMet = 0;
            }
        }
    }

    const int nLevelReq = sub_0062B5B0(pItem, pUnit);
    if (nLevelReq != -1 && STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0) < nLevelReq)
    {
        bLevelReqMet = 0;
    }

    if (pStrength)
    {
        *pStrength = bStrReqMet;
    }
    if (pDexterity)
    {
        *pDexterity = bDexReqMet;
    }
    if (pLevel)
    {
        *pLevel = bLevelReqMet;
    }

    if (bStrReqMet && bDexReqMet && bLevelReqMet && bIdentified)
    {
        if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) <= 0)
        {
            return 0;
        }

        const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
        if (nClass == PCLASS_INVALID)
        {
            return 1;
        }

        if (!pUnit)
        {
            return 0;
        }

        const int nUnitType = pUnit->dwUnitType;
        if (pUnit->dwUnitType == UNIT_MONSTER && nClass == PCLASS_BARBARIAN)
        {
            const int nMonsterId = MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId);
            if (nMonsterId >= MONSTER_ACT5HIRE1 && nMonsterId <= MONSTER_ACT5HIRE2)
            {
                return 1;
            }
        }

        if (nUnitType == UNIT_PLAYER && nClass == pUnit->dwClassId)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0062FDC0
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode)
{
    return sub_0062EFB0_GetRepairCost(pUnit, pItem, nDifficulty, pQuestFlags, nNpcId, nMode);
}

// 0x0062FDF0
int __stdcall ITEMS_IsBodyItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        unsigned char nBodyLoc1 = 0;
        unsigned char nBodyLoc2 = 0;
        ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

        if (nBodyLoc1 || nBodyLoc2)
        {
            D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecord(ITEMS_GetItemType(pItem));
            if (pItemTypesTxtRecord)
            {
                return pItemTypesTxtRecord->nBody;
            }
        }
    }

    return FALSE;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x0062FE60
int __stdcall ITEMS_GetAllRepairCosts(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void (__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*))
{
    if (!pUnit)
    {
        return 0;
    }

    int nTotal = 0;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    for (int i = 0; i < NUM_BODYLOC; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (!pItem)
        {
            continue;
        }

        int bRepair = 0;
        if (ITEMS_IsRepairable(pItem) && ITEMS_HasDurability(pItem))
        {
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
            const int nDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
            if (nMaxDurability && nDurability != nMaxDurability)
            {
                bRepair = 1;
            }
        }

        if (ITEMS_IsQuantityRepairable(pItem))
        {
            const int nMaxQuantity = ITEMS_GetTotalMaxStack(pItem);
            if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < nMaxQuantity)
            {
                bRepair = 1;
            }
        }

        int bHasChargedSkills = 0;
        if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills || bRepair)
        {
            nTotal += sub_0062EFB0_GetRepairCost(pUnit, pItem, nDifficulty, pQuestFlags, nNpcId, 3);
            if (pfCallback)
            {
                pfCallback(pGame, pItem, pUnit);
            }
        }
    }

    return nTotal;
}

// 0x0062FF70
int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    if (!ITEMS_CanBeEquippedInline(pItem))
        return FALSE;

    if (!ITEMSIsA(pItem, ITEMTYPE_CHARM))
        return FALSE;

    D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem);
    if (!pItemData)
        return FALSE;

    if (pItemData->nInvPage != INVPAGE_INVENTORY)
        return FALSE;

    return ITEMS_CheckRequirements(pItem, pPlayer, FALSE, 0, 0, 0) != 0;
}

// 0x006313E0
int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bServer, int bSaveItemInv, int bGamble)
{
    D2BitBufferStrc pBuffer;

    BITMANIP_Initialize(&pBuffer, pBitstream, nSize);

    ITEMS_SerializeItem(pItem, &pBuffer, bServer, bSaveItemInv, bGamble);

    if (pBuffer.bFull)
    {
        return 0;
    }
    else
    {
        return BITMANIP_GetSize(&pBuffer);
    }
}

// 0x0062E410
int __stdcall ITEMS_GetCompactItemDataFromBitstreamDefault(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave)
{
    return ITEMS_GetCompactItemDataFromBitstream(pBitstream, nSize, bCheckForHeader, pItemSave, ITEMVERSION);
}

// 0x0062E430
int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail)
{
    D2BitBufferStrc tBuffer;
    int bGamble = 0;

    BITMANIP_Initialize(&tBuffer, pBitstream, nSize);
    if (bCheckForHeader && BITMANIP_ReadSigned(&tBuffer, 16) != 0x4D4A)
    {
        *pFail = 1;
        return 0;
    }

    *pFail = 0;

    unsigned int dwItemFlags = sub_00411020_ReadBits(&tBuffer, 32);
    if (dwItemFlags & IFLAG_UNK_GAMBLE)
    {
        bGamble = 1;
        dwItemFlags &= ~IFLAG_UNK_GAMBLE;
    }

    ITEMS_ClearItemFlags(pItem);
    ITEMS_SetItemFlag_Inline(pItem, dwItemFlags, 1);
    ITEMS_SetItemFlag_Inline(pItem, IFLAG_NEWITEM, 0);
    ITEMS_SetItemLevel_Inline(pItem, 1);
    ITEMS_SetMagicPrefix(pItem, 0, 0);
    ITEMS_SetMagicSuffix(pItem, 0, 0);
    ITEMS_SetMagicPrefix(pItem, 0, 1);
    ITEMS_SetMagicSuffix(pItem, 0, 1);
    ITEMS_SetMagicPrefix(pItem, 0, 2);
    ITEMS_SetMagicSuffix(pItem, 0, 2);
    ITEMS_SetRarePrefix(pItem, 0);
    ITEMS_SetRareSuffix(pItem, 0);

    if (dwItemFlags & IFLAG_COMPACTSAVE)
    {
        const int nResult = ITEMS_DecodeItemBitstreamCompact(pItem, &tBuffer, bCheckForHeader, dwVersion);
        if (pSocketedItemCount)
            *pSocketedItemCount = 0;
        if (nResult <= 0)
            *pFail = 1;
    }
    else
    {
        if (ITEMS_DecodeItemBitstreamComplete(pItem, &tBuffer, bCheckForHeader, bGamble, pSocketedItemCount, dwVersion) <= 0)
            *pFail = 1;
    }

    return BITMANIP_GetSize(&tBuffer);
}

static inline unsigned int ITEMS_CheckItemFlagForceInl(D2UnitStrc* pItem, unsigned int dwFlag)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->dwItemFlags & dwFlag;
    }
    return 0;
}

static inline int ITEMS_GetItemQualityInl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataForceInl(pItem))
    {
        return pItemData->dwQualityNo;
    }
    return ITEMQUAL_NORMAL;
}

static inline D2ItemDataStrc* ITEMS_GetItemDataTypedInl(D2UnitStrc* pItem)
{
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_ITEM)
    {
        return pItem->pItemData;
    }
    return 0;
}

static inline int ITEMS_GetItemQualityTypedInl(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemDataTypedInl(pItem))
    {
        return pItemData->dwQualityNo;
    }
    return ITEMQUAL_NORMAL;
}

static inline void ITEMS_SetItemQualityInl(D2UnitStrc* pItem, int nQuality)
{
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_ITEM && pItem->pItemData)
    {
        pItem->pItemData->dwQualityNo = nQuality;
    }
}

static inline int ITEMS_GetItemLevelInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            return 1;
        }

        if (pItemData->dwItemLevel < 1)
        {
            pItemData->dwItemLevel = 1;
        }
        return pItemData->dwItemLevel;
    }
    return 1;
}

static inline unsigned char ITEMS_GetBodyLocationForceInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nBodyLoc;
    }
    return 0;
}

static inline unsigned char ITEMS_GetInvPageByteInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            return 0xFF;
        }
        return pItemData->nInvPage;
    }
    return 0xFF;
}

static inline unsigned char ITEMS_GetInvGfxIndexInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->nInvGfxIdx;
    }
    return 0;
}

static inline unsigned short ITEMS_GetAutoAffixInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->wAutoAffix;
    }
    return 0;
}

static inline unsigned short ITEMS_GetMagicPrefixInl(D2UnitStrc* pItem, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            return pItemData->wMagicPrefix[nIndex];
        }
    }
    return 0;
}

static inline unsigned short ITEMS_GetMagicSuffixInl(D2UnitStrc* pItem, int nIndex)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (pItemData)
        {
            return pItemData->wMagicSuffix[nIndex];
        }
    }
    return 0;
}

static inline unsigned char ITEMS_GetEarLevelForceInl(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        D2ItemDataStrc* pItemData = pItem->pItemData;
        if (!pItemData)
        {
            return 1;
        }
        return pItemData->nEarLvl;
    }
    return 1;
}

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordConstInl(int nStatId)
{
    if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }
    return &sgptDataTables->pItemStatCostTxt[nStatId];
}

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecordForceInl(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static inline unsigned short ITEMS_GetRunewordStringIdInl(D2UnitStrc* pItem)
{
    const D2RunesTxt* pRunesTxtRecord = ITEMS_GetRunesTxtRecordFromItem(pItem);
    return pRunesTxtRecord ? pRunesTxtRecord->wStringId : 0xFFFF;
}

unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->wRarePrefix;
    }
    return 0;
}

unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return pItem->pItemData->wRareSuffix;
    }
    return 0;
}

static int __stdcall sub_0062A900_GetSocketedItemCount(D2UnitStrc* pItem)
{
    int nCount = 0;

    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pItem->pInventory;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    if (!pItemsTxtRecord || !pItemsTxtRecord->nHasInv || !pInventory)
    {
        return 0;
    }

    for (D2UnitStrc* pChild = INVENTORY_GetFirstItem(pInventory); pChild; pChild = INVENTORY_GetNextItem(pChild))
    {
        ++nCount;
    }

    return nCount;
}

static inline void ITEMS_WriteBitsCallInl(D2BitBufferStrc* pBuffer, unsigned int nData, int nBits)
{
    ITEMS_WriteBitsToBitstream(pBuffer, nData, nBits);
}

static inline unsigned short ITEMS_GetItemFormatInl(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 5380);
    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nUnitType == UNIT_ITEM, 5381);
    D2ItemDataStrc* pItemData = ITEMS_GetItemDataForceInl(pItem);
    D2_ASSERT(pItemData, 5383);
    return pItemData->wItemFormat;
}

// 0x0062FFF0
static void __stdcall ITEMS_SerializeItemComplete(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bGamble)
{
    D2StatStrc aStats[511];
    int anValues[511];
    int bInvalidQuality = 0;

    ITEMS_WriteBitsInl(10, ITEMS_GetItemFormatInl(pItem), pBuffer);
    ITEMS_WriteBitsInl(3, pItem->dwAnimMode, pBuffer);

    if (pItem->dwAnimMode != IMODE_ONGROUND && pItem->dwAnimMode != IMODE_DROPPING)
    {
        ITEMS_WriteBitsInl(4, ITEMS_GetBodyLocationForceInl(pItem), pBuffer);
        ITEMS_WriteBitsInl(4, (((UNITS_GetXPositionForceInl(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitX(pItem) : 0u) < 15u) ? ((CLIENTS_GetUnitX(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitX(pItem) : 0u) : 15u, pBuffer);
        ITEMS_WriteBitsInl(4, (((UNITS_GetYPositionForceInl(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitY(pItem) : 0u) < 15u) ? ((CLIENTS_GetUnitY(pItem) > 0u) ? (unsigned int)CLIENTS_GetUnitY(pItem) : 0u) : 15u, pBuffer);
        ITEMS_WriteBitsInl(3, (char)(ITEMS_GetInvPageByteInl(pItem) + 1), pBuffer);
    }
    else
    {
        ITEMS_WriteBitsInl(16, UNITS_GetXPositionForceInl(pItem), pBuffer);
        ITEMS_WriteBitsInl(16, UNITS_GetYPositionForceInl(pItem), pBuffer);
    }

    if (bGamble)
    {
        ITEMS_WriteBitsInl(32, ITEMS_GetNormalCode(pItem), pBuffer);
        return;
    }

    ITEMS_WriteBitsInl(32, ITEMS_GetBaseCode(pItem), pBuffer);
    ITEMS_WriteBitsInl(3, sub_0062A900_GetSocketedItemCount(pItem), pBuffer);

    if (bServer)
    {
        ITEMS_WriteBitsInl(32, pItem->dwInitSeed, pBuffer);
    }

    ITEMS_WriteBitsInl(7, D2_MIN(ITEMS_GetItemLevelInl(pItem), 99), pBuffer);
    ITEMS_WriteBitsInl(4, ITEMS_GetItemQualityInl(pItem), pBuffer);

    ITEMS_WriteBitsInl(1, ITEMS_GetVarInvGfxCount(pItem) != 0, pBuffer);
    if (ITEMS_GetVarInvGfxCount(pItem))
    {
        ITEMS_WriteBitsInl(3, ITEMS_GetInvGfxIndexInl(pItem), pBuffer);
    }

    D2MagicAffixDataTbl* pMagicAffixDataTbl = DATATBLS_GetMagicAffixDataTables();
    const int nPrefixOffset = pMagicAffixDataTbl->pMagicPrefix - pMagicAffixDataTbl->pMagicAffixTxt;
    const int nAutoAffixOffset = pMagicAffixDataTbl->pAutoMagic - pMagicAffixDataTbl->pMagicAffixTxt;

    unsigned short nAutoAffix = ITEMS_GetAutoAffixInl(pItem);
    if (nAutoAffix > nAutoAffixOffset)
    {
        nAutoAffix -= nAutoAffixOffset;
    }

    ITEMS_WriteBitsInl(1, nAutoAffix != 0, pBuffer);
    if (nAutoAffix)
    {
        ITEMS_WriteBitsInl(11, nAutoAffix, pBuffer);
    }

    switch (ITEMS_GetItemQualityTypedInl(pItem))
    {
    case ITEMQUAL_INFERIOR:
        ITEMS_WriteBitsInl(3, ITEMS_GetFileIndex(pItem), pBuffer);
        break;

    case ITEMQUAL_SUPERIOR:
        ITEMS_WriteBitsInl(3, ITEMS_GetFileIndex(pItem), pBuffer);
        break;

    case ITEMQUAL_RARE:
    case ITEMQUAL_CRAFT:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_WriteBitsInl(8, ITEMS_GetRarePrefixId(pItem), pBuffer);
            ITEMS_WriteBitsInl(8, ITEMS_GetRareSuffixId(pItem), pBuffer);
        }

        for (int i = 0; i < 3; ++i)
        {
            unsigned short nPrefix = ITEMS_GetMagicPrefixInl(pItem, i);
            if (nPrefix > nPrefixOffset)
            {
                nPrefix -= nPrefixOffset;
            }

            if (nPrefix)
            {
                ITEMS_WriteBitsInl(1, 1, pBuffer);
                ITEMS_WriteBitsInl(11, nPrefix, pBuffer);
            }
            else
            {
                ITEMS_WriteBitsInl(1, 0, pBuffer);
            }

            const unsigned short nSuffix = ITEMS_GetMagicSuffixInl(pItem, i);
            if (nSuffix)
            {
                ITEMS_WriteBitsInl(1, 1, pBuffer);
                ITEMS_WriteBitsInl(11, nSuffix, pBuffer);
            }
            else
            {
                ITEMS_WriteBitsInl(1, 0, pBuffer);
            }
        }
        break;

    case ITEMQUAL_TEMPERED:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            ITEMS_WriteBitsInl(8, ITEMS_GetRarePrefixId(pItem), pBuffer);
            ITEMS_WriteBitsInl(8, ITEMS_GetRareSuffixId(pItem), pBuffer);
        }
        break;

    case ITEMQUAL_MAGIC:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            unsigned short nPrefix = ITEMS_GetPrefixId(pItem, 0);
            const unsigned short nSuffix = ITEMS_GetSuffixId(pItem, 0);
            if (nPrefix > nPrefixOffset)
            {
                nPrefix -= nPrefixOffset;
            }

            ITEMS_WriteBitsInl(11, nPrefix, pBuffer);
            ITEMS_WriteBitsInl(11, nSuffix, pBuffer);
        }
        break;

    case ITEMQUAL_SET:
    case ITEMQUAL_UNIQUE:
        if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
        {
            int nFileIndex = ITEMS_GetFileIndex(pItem);
            if (nFileIndex < 0)
            {
                nFileIndex = 0xFFF;
            }

            ITEMS_WriteBitsInl(12, nFileIndex, pBuffer);
        }
        break;

    default:
        if (ITEMS_GetItemQualityTypedInl(pItem) != ITEMQUAL_NORMAL)
        {
            ITEMS_SetItemQualityInl(pItem, ITEMQUAL_NORMAL);
            bInvalidQuality = 1;
        }

        if (ITEMSIsA(pItem, 13))
        {
            if (bServer || ITEMS_GetItemFlags(pItem) & IFLAG_IDENTIFIED)
            {
                unsigned short nPrefix = ITEMS_GetMagicPrefixInl(pItem, 0);
                if (nPrefix > nPrefixOffset)
                {
                    nPrefix -= nPrefixOffset;
                }

                ITEMS_WriteBitsInl(1, nPrefix != 0, pBuffer);
                if (nPrefix)
                {
                    ITEMS_WriteBitsInl(11, nPrefix, pBuffer);
                }
                else
                {
                    ITEMS_WriteBitsInl(11, ITEMS_GetSuffixId(pItem, 0), pBuffer);
                }
            }
        }

        if (ITEMSIsA(pItem, 40) && !ITEMSIsA(pItem, 7))
        {
            ITEMS_WriteBitsInl(10, ITEMS_GetFileIndex(pItem), pBuffer);
        }

        if (ITEMSIsA(pItem, 22) || ITEMSIsA(pItem, 18))
        {
            ITEMS_WriteBitsInl(5, ITEMS_GetMagicSuffixInl(pItem, 0), pBuffer);
        }
        break;
    }

    if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_RUNEWORD)
    {
        ITEMS_WriteBitsInl(16, ITEMS_GetRunewordStringIdInl(pItem), pBuffer);
    }

    if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_ISEAR)
    {
        char* szName = ITEMS_GetEarNameForceInl(pItem);
        ITEMS_WriteBitsInl(3, ITEMS_GetFileIndex(pItem), pBuffer);
        ITEMS_WriteBitsInl(7, ITEMS_GetEarLevelForceInl(pItem), pBuffer);
        do
        {
            ITEMS_WriteBitsInl(7, *szName, pBuffer);
        }
        while (*szName++);
    }
    else if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_PERSONALIZED)
    {
        char* szName = ITEMS_GetEarNameForceInl(pItem);
        do
        {
            ITEMS_WriteBitsInl(7, *szName, pBuffer);
        }
        while (*szName++);
    }

    if (bServer)
    {
        int nRealmData0 = 0;
        int nRealmData1 = 0;
        ITEMS_GetRealmData(pItem, &nRealmData0, &nRealmData1);
        const int nRealm1 = nRealmData1;
        if (nRealm1)
        {
            ITEMS_WriteBitsInl(1, 1, pBuffer);
            ITEMS_WriteBitsInl(32, nRealmData0, pBuffer);
            ITEMS_WriteBitsInl(32, nRealm1, pBuffer);
            ITEMS_WriteBitsInl(32, 0, pBuffer);
        }
        else
        {
            ITEMS_WriteBitsInl(1, 0, pBuffer);
        }
    }

    if (ITEMSIsA(pItem, 50))
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(31);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, STATLIST_GetUnitBaseStat(pItem, 31, 0) + pItemStatCostTxtRecord->dwSaveAdd, pBuffer);

        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(73);
        const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, 73, 0);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nMaxDurability, pBuffer);
        if (nMaxDurability)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(72);
            ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, STATLIST_UnitGetStatValue(pItem, 72, 0) + pItemStatCostTxtRecord->dwSaveAdd, pBuffer);
        }
    }
    else if (ITEMSIsA(pItem, 45))
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(73);
        const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, 73, 0);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nMaxDurability, pBuffer);
        if (nMaxDurability)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(72);
            ITEMS_WriteBitsToBitstream(pBuffer, STATLIST_UnitGetStatValue(pItem, 72, 0) + pItemStatCostTxtRecord->dwSaveAdd, pItemStatCostTxtRecord->nSaveBits);
        }
    }
    else if (ITEMSIsA(pItem, ITEMTYPE_GOLD))
    {
        const int nGold = STATLIST_UnitGetStatValue(pItem, 14, 0);
        ITEMS_WriteBitsInl(1, nGold >= 4096, pBuffer);
        ITEMS_WriteBitsToBitstream(pBuffer, nGold, (((nGold < 4096) - 1) & 20) + 12);
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        ITEMS_WriteBitsInl(9, STATLIST_UnitGetStatValue(pItem, 70, 0), pBuffer);
    }

    if (ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_SOCKETED)
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecordConstInl(194);
        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, STATLIST_GetUnitBaseStat(pItem, 194, 0), pBuffer);
    }

    if (!bServer && !(ITEMS_GetItemFlagsForceInl(pItem) & IFLAG_IDENTIFIED))
    {
        return;
    }

    int nStatLists = 0;
    const int nItemType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nItemType == UNIT_ITEM && ITEMS_GetItemQualityInl(pItem) == ITEMQUAL_SET)
    {
        int nSetMask = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStatesBySetIndex[i], 0x2040)
                || STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStatesBySetIndex[i], 0x40))
            {
                if (pBuffer)
                {
                    nSetMask += 1 << i;
                    nStatLists = i + 1;
                }
                else
                {
                    nSetMask += 1 << i;
                    nStatLists = i + 1;
                }
            }
        }

        ITEMS_WriteBitsInl(5, nSetMask, pBuffer);
    }

    int bRuneword = 0;
    if (ITEMS_CheckItemFlagForceInl(pItem, IFLAG_RUNEWORD))
    {
        ++nStatLists;
        bRuneword = 1;
    }

    for (int nIndex = -1; nIndex < nStatLists; ++nIndex)
    {
        D2StatListStrc* pStatList = 0;
        if (nIndex < 0)
        {
            pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        }
        else if (bRuneword && nIndex == nStatLists - 1)
        {
            pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, 171, 0x40);
        }
        else
        {
            pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStatesBySetIndex[nIndex], 0x2040);
            if (!pStatList)
            {
                pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, gnItemSetStatesBySetIndex[nIndex], 0x40);
            }
        }

        if (pStatList && !bInvalidQuality)
        {
            memset(anValues, 0, sizeof(anValues));
            const int nStats = STATLIST_GetBaseStatsData(pStatList, aStats, 511);
            for (int i = 0; i < nStats; ++i)
            {
                const int nStatId = (unsigned int)aStats[i].nPackedValue >> 16;
                const unsigned short nLayer = (unsigned short)aStats[i].nPackedValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord;
                if (nStats > 1)
                {
                    if (nStatId < 0)
                    {
                        goto L_NO_RECORD;
                    }
                }
                else
                {
                    if (nStatId < 0)
                    {
                        goto L_NO_RECORD;
                    }
                }
                if (nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
                }
                else
                {
L_NO_RECORD:
                    pItemStatCostTxtRecord = 0;
                }
                if (!pItemStatCostTxtRecord->nSaveBits)
                {
                    continue;
                }

                const int nValue = aStats[i].nValue >> pItemStatCostTxtRecord->nValShift;
                if (!nValue || !(nValue - anValues[nStatId]))
                {
                    continue;
                }

                ITEMS_WriteBitsInl(9, nStatId, pBuffer);

                if (nStatId <= 48)
                {
                    if (nStatId != 48)
                    {
                        if (nStatId == 17)
                        {
                    ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = PLAYER_GetItemStatCostTxtRecord(18);
                    anValues[18] = STATLIST_GetStatValue(pStatList, 18, 0);
                    ITEMS_WriteBitsInl(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[18], pBuffer);
                        }
                        else
                        {
                    if (pItemStatCostTxtRecord->nSaveParamBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveParamBits, nLayer, pBuffer);
                    }

                    if (pItemStatCostTxtRecord->nSaveBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    }
                        }
                    }
                    else
                    {
                    ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = PLAYER_GetItemStatCostTxtRecord(49);
                    anValues[49] = STATLIST_GetStatValue(pStatList, 49, 0);
                    ITEMS_WriteBitsInl(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[49], pBuffer);
                    }
                }
                else
                {
                switch (nStatId)
                {
                case 50:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = PLAYER_GetItemStatCostTxtRecord(51);
                    anValues[51] = STATLIST_GetStatValue(pStatList, 51, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[51], pBuffer);
                    break;
                }
                case 52:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = PLAYER_GetItemStatCostTxtRecord(53);
                    anValues[53] = STATLIST_GetStatValue(pStatList, 53, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[53], pBuffer);
                    break;
                }
                case 54:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = PLAYER_GetItemStatCostTxtRecord(55);
                    anValues[55] = STATLIST_GetStatValue(pStatList, 55, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[55], pBuffer);
                    pNextRecord = PLAYER_GetItemStatCostTxtRecord(56);
                    anValues[56] = STATLIST_GetStatValue(pStatList, 56, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[56], pBuffer);
                    break;
                }
                case 57:
                {
                    ITEMS_WriteBitsCall(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    D2ItemStatCostTxt* pNextRecord = PLAYER_GetItemStatCostTxtRecord(58);
                    anValues[58] = STATLIST_GetStatValue(pStatList, 58, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[58], pBuffer);
                    pNextRecord = PLAYER_GetItemStatCostTxtRecord(59);
                    anValues[59] = STATLIST_GetStatValue(pStatList, 59, 0);
                    ITEMS_WriteBitsCall(pNextRecord->nSaveBits, pNextRecord->dwSaveAdd + anValues[59], pBuffer);
                    break;
                }
                case 326:
                    break;

                default:
                    if (pItemStatCostTxtRecord->nSaveParamBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveParamBits, nLayer, pBuffer);
                    }

                    if (pItemStatCostTxtRecord->nSaveBits > 0)
                    {
                        ITEMS_WriteBitsInl(pItemStatCostTxtRecord->nSaveBits, pItemStatCostTxtRecord->dwSaveAdd + nValue, pBuffer);
                    }
                    break;
                }
                }

            }
        }

        if (nIndex < 0 || pStatList || bRuneword)
        {
            ITEMS_WriteBitsInl(9, 0x1FF, pBuffer);
        }
    }
}

// 0x006312B0
int __fastcall ITEMS_SerializeItem(D2UnitStrc* pItem, D2BitBufferStrc* pBuffer, int bServer, int bSaveItemInv, int bGamble)
{
    unsigned int nItemFlags = ITEMS_GetItemFlagsInl(pItem);
    nItemFlags = nItemFlags & ~IFLAG_INIT | IFLAG_JUSTSAVED;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 4832);

    if (pItemsTxtRecord->nCompactSave)
    {
        nItemFlags |= IFLAG_COMPACTSAVE;
    }

    if (bGamble)
    {
        nItemFlags = nItemFlags & ~IFLAG_ETHEREAL | IFLAG_LOWQUALITY;
    }

    if (bServer)
    {
        BITMANIP_Write(pBuffer, 'MJ', 16);
    }
    else if (!(nItemFlags & IFLAG_IDENTIFIED))
    {
        nItemFlags &= ~IFLAG_SOCKETED;
    }
    BITMANIP_Write(pBuffer, nItemFlags, 32);

    if (nItemFlags & IFLAG_COMPACTSAVE)
    {
        ITEMS_SerializeItemCompact(bServer, pItem, pBuffer);
    }
    else
    {
        ITEMS_SerializeItemComplete(pItem, pBuffer, bServer, bGamble);
    }

    if (!bGamble && bSaveItemInv && pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pChild = INVENTORY_UnitIsItem(i);
            BITMANIP_GoToNextByte(pBuffer);
            ITEMS_SerializeItem(pChild, pBuffer, bServer, bSaveItemInv, 0);
        }
    }

    return BITMANIP_GetSize(pBuffer);
}

// 0x0062E5D0
static int ITEMS_IsQuantityRepairable(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 1661);

    int nItemType;
    if (pItem->dwUnitType != UNIT_ITEM)
    {
        nItemType = 0;
    }
    else
    {
        nItemType = ITEMS_GetItemTypeFromItemId(pItem->dwClassId);
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = DATATBLS_GetItemTypesTxtRecordInl(nItemType);
    if (pItemTypesTxtRecord && pItemTypesTxtRecord->nRepair && ITEMS_CheckIfThrowable(pItem) && ITEMS_CheckIfStackable(pItem) && !ITEMS_IsEthereal(pItem))
    {
        return 1;
    }
    return 0;
}

// 0x00639D60
D2RunesTxt* __stdcall DATATBLS_GetRunesTxtRecord(int nRunewordId)
{
    D2_ASSERT(nRunewordId > 0 && nRunewordId < sgtRuneWordsTblDesc.nRunesTxtRecordCount, 2418);
    return &sgtRuneWordsTblDesc.pRunesTxt[nRunewordId];
}

// 0x00639DB0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        STATLIST_ToggleState(pUnit, nState, bSet);
        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x00639DF0
__declspec(noinline) int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
        case UNIT_MONSTER:
        case UNIT_MISSILE:
            if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
            {
                return STATLIST_CheckState(pUnit, nState);
            }
            break;
        }
    }

    return 0;
}

// 0x00639E30
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
    if (pGfxFlags && nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (bSet)
        {
            pGfxFlags[nState >> 5] |= gdwBitMasks[nState & 31];
        }
        else
        {
            pGfxFlags[nState >> 5] &= gdwInvBitMasks[nState & 31];
        }
        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x00639E90
int __stdcall STATES_CheckGfxStateFlag(D2UnitStrc* pUnit, int nState)
{
    unsigned int* pGfxFlags = 0;

    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
        if (pGfxFlags)
        {
            return pGfxFlags[nState >> 5] & gdwBitMasks[nState & 31];
        }
    }

    return 0;
}

// 0x00639EE0
void __stdcall STATES_ClearGfxStateFlags(D2UnitStrc* pUnit)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);

    if (pGfxFlags)
    {
        memset(pGfxFlags, 0x00, sizeof(unsigned int) * ((sgptDataTables->nStatesTxtRecordCount + 31) / 32));
    }
}

// 0x00639F20
int __stdcall STATES_IsAnyGfxStateFlagSet(D2UnitStrc* pUnit)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);

    if (pGfxFlags)
    {
        for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
        {
            if (pGfxFlags[i])
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00639F70
unsigned int* __stdcall STATES_GetGfxStateFlags(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 153);

    return D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(hUnit);
}

// 0x00639FB0
void __stdcall STATES_UpdateStayDeathFlags(D2UnitStrc* pUnit, int bIsBoss)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);

    if (pGfxFlags && pStatFlags)
    {
        const int nCount = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
        if (bIsBoss)
        {
            for (int i = 0; i < nCount; ++i)
            {
                pGfxFlags[i] |= pStatFlags[i] & ~sgptDataTables->fStateMasks[STATEMASK_BOSSSTAYDEATH][i];
                pStatFlags[i] &= sgptDataTables->fStateMasks[STATEMASK_BOSSSTAYDEATH][i];
            }
        }
        else if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            for (int i = 0; i < nCount; ++i)
            {
                pGfxFlags[i] |= pStatFlags[i] & ~sgptDataTables->fStateMasks[STATEMASK_PLRSTAYDEATH][i];
                pStatFlags[i] &= sgptDataTables->fStateMasks[STATEMASK_PLRSTAYDEATH][i];
            }
        }
        else
        {
            for (int i = 0; i < nCount; ++i)
            {
                pGfxFlags[i] |= pStatFlags[i] & ~sgptDataTables->fStateMasks[STATEMASK_MONSTAYDEATH][i];
                pStatFlags[i] &= sgptDataTables->fStateMasks[STATEMASK_MONSTAYDEATH][i];
            }
        }

        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x0063A100
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc* pUnit)
{
    return D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);
}

// 0x0063A110
int __fastcall STATES_GetNumberOfStateFlags()
{
    return (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
}

// 0x0063A130
static int STATES_CheckStateMaskFlagsOnUnit(D2UnitStrc* pUnit, const unsigned int* pStateMask)
{
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);
    if (!pStatFlags)
    {
        return 0;
    }

    for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
    {
        if (pStatFlags[i] & pStateMask[i])
        {
            return 1;
        }
    }

    return 0;
}

// 0x0063A180
void __stdcall STATES_UpdateGfxFlagsWithMask(D2UnitStrc* pUnit, unsigned int* pMask)
{
    unsigned int* pGfxFlags = D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(pUnit);
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags_6FDB8A90(pUnit);

    if (pGfxFlags && pStatFlags)
    {
        for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
        {
            pGfxFlags[i] |= pMask[i] & pStatFlags[i];
            pStatFlags[i] &= ~pMask[i];
        }

        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x0063A210
int __stdcall STATES_CheckStateMaskAuraByStateId(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[STATEMASK_AURA][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

// 0x0063A250
int __stdcall STATES_CheckStateMaskAuraOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_AURA]);
}

// 0x0063A270
int __stdcall STATES_CheckStateMaskPgsvByStateId(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[STATEMASK_PGSV][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

// 0x0063A2B0
int __stdcall STATES_CheckStateMaskPgsvOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_PGSV]);
}

// 0x0063A2D0
void __stdcall STATES_UpdatePgsvFlags(D2UnitStrc* pUnit)
{
    STATES_UpdateGfxFlagsWithMask(pUnit, sgptDataTables->fStateMasks[STATEMASK_PGSV]);
}

// 0x0063A2F0
int __stdcall STATES_CheckStateMaskHideByStateId(int nState)
{
    return sgptDataTables->fStateMasks[STATEMASK_HIDE][nState >> 5] & gdwBitMasks[nState & 31];
}

// 0x0063A320
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_HIDE]);
}

// 0x0063A340
int __stdcall STATES_CheckStateMaskActiveOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ACTIVE]);
}

// 0x0063A360
int __stdcall STATES_CheckStateMaskRemHitOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_REMHIT]);
}

// 0x0063A380
int __stdcall STATES_CheckStateMaskDamBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_DAMBLUE]);
}

// 0x0063A3A0
int __stdcall STATES_CheckStateMaskDamRedOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_DAMRED]);
}

// 0x0063A3C0
int __stdcall STATES_CheckStateMaskAttBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ATTBLUE]);
}

// 0x0063A3E0
int __stdcall STATES_CheckStateMaskAttRedOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ATTRED]);
}

// 0x0063A400
int __stdcall STATES_IsUnitShapeShifted(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> UNITFLAGEX_ISSHAPESHIFTED_BIT) & 1;
}

// 0x0063A420
int __stdcall STATES_CheckStateMaskCurseByStateId(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[STATEMASK_CURSE][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}



inline int __fastcall STATES_CheckStateMaskByStateId(int nState, int nStateMask)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return sgptDataTables->fStateMasks[nStateMask][nState >> 5] & gdwBitMasks[nState & 31];
    }

    return 0;
}

// 0x0063A460
int __stdcall STATES_CheckStateMaskCurableByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_CURABLE);
}

// 0x0063A4A0
int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (nUnitType == UNIT_MONSTER)
        {
            return sgptDataTables->fStateMasks[STATEMASK_MONSTAYDEATH][nState >> 5] & gdwBitMasks[nState & 31];
        }
        else
        {
            return sgptDataTables->fStateMasks[STATEMASK_PLRSTAYDEATH][nState >> 5] & gdwBitMasks[nState & 31];
        }
    }

    return 0;
}

// 0x0063A510
int __fastcall STATES_CheckStateMaskRestrictOnUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RESTRICT]);
}

// 0x0063A530
int __stdcall STATES_CheckStateMaskBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_BLUE]);
}

// 0x0063A550
int __stdcall STATES_CheckStateMaskArmBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ARMBLUE]);
}

// 0x0063A570
int __stdcall STATES_CheckStateMaskRFBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RFBLUE]);
}

// 0x0063A590
int __stdcall STATES_CheckStateMaskRCBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RCBLUE]);
}

// 0x0063A5B0
int __stdcall STATES_CheckStateMaskRLBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RLBLUE]);
}

// 0x0063A5D0
int __stdcall STATES_CheckStateMaskRPBlueOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RPBLUE]);
}

// 0x0063A5F0
int __stdcall STATES_CheckStateMaskArmRedOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_ARMRED]);
}

// 0x0063A610
int __stdcall STATES_CheckStateMaskRFRedOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RFRED]);
}

// 0x0063A630
int __stdcall STATES_CheckStateMaskRCRedOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RCRED]);
}

// 0x0063A650
int __stdcall STATES_CheckStateMaskRLRedOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RLRED]);
}

// 0x0063A670
int __stdcall STATES_CheckStateMaskRPRedOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_RPRED]);
}

// 0x0063A690
int __stdcall STATES_CheckStateMaskExpOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_EXP]);
}

// 0x0063A6B0
int __stdcall STATES_CheckStateMaskExpByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_EXP);
}

// 0x0063A6F0
int __stdcall STATES_CheckStateMaskShatterOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_SHATTER]);
}

// 0x0063A710
int __stdcall STATES_CheckStateMaskShatterByStateId(int nState)
{
    return STATES_CheckStateMaskByStateId(nState, STATEMASK_SHATTER);
}

// 0x0063A750
int __stdcall STATES_CheckStateMaskLifeOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_LIFE]);
}

// 0x0063A770
int __stdcall STATES_CheckStateMaskUdeadOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_UDEAD]);
}

// 0x0063A790
int __stdcall STATES_CheckStateMaskGreenOnUnit(D2UnitStrc* pUnit)
{
    return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[STATEMASK_GREEN]);
}

// 0x0063A7B0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask)
{
    if (pUnit && nStateMask >= 0 && nStateMask < 40)
    {
        return STATES_CheckStateMaskFlagsOnUnit(pUnit, sgptDataTables->fStateMasks[nStateMask]);
    }

    return 0;
}

// 0x0063A7E0
static inline D2ItemExtraDataStrc* ITEMS_GetExtraDataFromItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }
    return 0;
}

static void __cdecl INVENTORY_UnlinkItem(D2InventoryPairStrc* pPair, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = ITEMS_GetExtraDataFromItem(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousItem)
    {
        if (pPair->pFirstItem == pItem)
        {
            pPair->pFirstItem = pExtra->pNextItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = ITEMS_GetExtraDataFromItem(pExtra->pPreviousItem);
        if (pPrevious)
        {
            pPrevious->pNextItem = pExtra->pNextItem;
        }
    }
    if (!pExtra->pNextItem)
    {
        if (pPair->pLastItem == pItem)
        {
            pPair->pLastItem = pExtra->pPreviousItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = ITEMS_GetExtraDataFromItem(pExtra->pNextItem);
        if (pNext)
        {
            pNext->pPreviousItem = pExtra->pPreviousItem;
        }
    }
    pExtra->pNextItem = 0;
    pExtra->pPreviousItem = 0;
}

static void __stdcall INVENTORY_UnlinkGridItem(D2InventoryGridStrc* pGrid, int bMultiCell, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = ITEMS_GetExtraDataFromItem(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousGridItem)
    {
        if (pGrid->pItem == pItem)
        {
            pGrid->pItem = pExtra->pNextGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = ITEMS_GetExtraDataFromItem(pExtra->pPreviousGridItem);
        if (pPrevious)
        {
            pPrevious->pNextGridItem = pExtra->pNextGridItem;
        }
    }
    if (!pExtra->pNextGridItem)
    {
        if (pGrid->pLastItem == pItem)
        {
            pGrid->pLastItem = pExtra->pPreviousGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = ITEMS_GetExtraDataFromItem(pExtra->pNextGridItem);
        if (pNext)
        {
            pNext->pPreviousGridItem = pExtra->pPreviousGridItem;
        }
    }
    if (pGrid->ppItems)
    {
        if (bMultiCell)
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, &gszInventorySource_006EA918, SIZE_LINE);
            for (int nRow = nY; nRow < nY + nHeight; ++nRow)
            {
                D2UnitStrc** ppRow = pGrid->ppItems + nRow * pGrid->nGridWidth;
                for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
                {
                    ppRow[nColumn] = 0;
                }
            }
        }
        else
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            pGrid->ppItems[nX + nY * pGrid->nGridWidth] = 0;
        }
    }
    pExtra->pNextGridItem = 0;
    pExtra->pPreviousGridItem = 0;
    pExtra->nNodePos = 0;
}

int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType == 4)
    {
        D2ItemExtraDataStrc* pExtra = ITEMS_GetExtraDataFromItem(pItem);
        if (!pExtra)
        {
            return 0;
        }
        D2InventoryStrc* pInventory = pExtra->pParentInv;
        if (!pInventory)
        {
            return 0;
        }
        if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        {
            return 0;
        }
        if (pExtra->nNodePos > 0)
        {
            const int nGrid = pExtra->nNodePos - 1;
            if (pInventory->nGridCount > nGrid)
            {
                INVENTORY_UnlinkGridItem(&pInventory->pGrids[nGrid], nGrid >= 1, pItem);
            }
        }
        if (pInventory->pCursorItem == pItem)
        {
            pInventory->pCursorItem = 0;
        }
        else
        {
            INVENTORY_UnlinkItem((D2InventoryPairStrc*)&pInventory->pFirstItem, pItem);
            --pInventory->dwItemCount;
        }
        pExtra->pParentInv = 0;
        pExtra->nNodePos = 0;
        pExtra->nNodePosOther = 0;
        ITEMS_SetOwnerId(pItem, -1);
        if (pInventory->pOwner)
        {
            STATLIST_ExpireUnitStatlist(pInventory->pOwner, pItem);
        }
        if (pInventory->dwLeftItemGUID == (!pItem ? -1 : pItem->dwUnitId))
        {
            pInventory->dwLeftItemGUID = -1;
        }
    return 1;
    }
    return 0;
}

void __cdecl sub_00405A50_Nop()
{
}

void __cdecl sub_00405A60_Nop()
{
}

// 0x0063A800
void __cdecl ITEMS_Nop()
{
}

void __cdecl sub_004DF920_Nop()
{
}

void __cdecl sub_004DF930_Nop()
{
}

void __cdecl OBJECTS_InitFunction70_Unused()
{
}

#include "gen/data/Source/D2Common/ITEMS/Items.inc"
