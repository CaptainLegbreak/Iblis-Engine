#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"
#include "D2Client.h"
#include "D2CelContext.h"
#include "D2LevelTxt.h"
#include "D2StormTypes.h"
#include "D2ClientUiRecords.h"

struct D2SkillStrc;

struct D2UnitStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

#pragma intrinsic(memset)

struct D2InventoryStrc;



struct UBuf
{
    unsigned int d;

    UBuf() : d(0)
    {
    }
};

struct UNum10
{
    unsigned short w0, w1, w2, w3, w4, w5, w6, w7, w8, w9;

    UNum10() : w0(0), w1(0), w2(0), w3(0), w4(0), w5(0), w6(0), w7(0), w8(0), w9(0)
    {
    }
};

#define W(x) ((Unicode*)(x))

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...);         // 0x00413A40

void __stdcall sub_00403040_VectorCtor(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnCtor)(void*)); // 0x00403040

void __fastcall sub_0042F530_UnicodeCtor(void* pThis);                                                      // 0x0042F530

int __cdecl FOG_IsExpansion();                                                                 // 0x00408F20

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0

Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit);                               // 0x004521C0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0

int __cdecl sub_00468730();                                                                                 // 0x00468730

int __cdecl sub_00468740();                                                                                 // 0x00468740

int __cdecl sub_00468830();                                                                                 // 0x00468830

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB);                                                     // 0x00469AA0

const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB);                                         // 0x0046A530

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

int __stdcall sub_00485410_AppendDamage(D2UnitStrc* pItem, Unicode* pText);                                // 0x00485410

void __stdcall INV_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText);            // 0x00485EE0

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);                            // 0x0048C060

void __cdecl INV_DrawBookTooltip();                                                               // 0x0048CFF0

void __fastcall INV_DrawSetItemTooltip(D2UnitStrc* pUnit);                                         // 0x0048D1D0

void __cdecl INV_DrawTransmogrifyTooltip();                                                            // 0x0048DB80

int __cdecl HIREABLES_AreBeltRowsShown();                                                                                 // 0x004979E0

int __cdecl NPCMENU_IsAnyDialogOpen();                                                                                 // 0x004B34A0

int __cdecl NPCMENU_IsGambleShop();                                                                                 // 0x004B3500

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength);        // 0x004B2AD0

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra); // 0x004E6410

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength);                            // 0x004E6850

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

unsigned int __fastcall sub_00526800(const Unicode* pString);                                             // 0x00526800

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);         // 0x00625500

int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);                                         // 0x00625E00

int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2);                                     // 0x00625E60

int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2);                                     // 0x00625EF0

int __stdcall STATLIST_GetDefenseFromUnit(D2UnitStrc* pUnit);                                               // 0x00626020

int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc);       // 0x00627C20

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem);                                                    // 0x006295B0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem);                                                       // 0x00629930

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue);                              // 0x0062A5D0

int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue);                              // 0x0062A620

int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem);                             // 0x0062A710

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400

int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit);                       // 0x0062BA60

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80

int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem);                                                  // 0x0062C060

int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem);                                             // 0x0062C0B0

int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem);                                                       // 0x0062E740

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);   // 0x0063AD50

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, void* pSkill, int bBonus);                            // 0x006442A0

int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId);                    // 0x00645C10

int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage);            // 0x00647BC0

int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage);            // 0x00647D00

extern "C" const char gszFormatLd[];                                                                 // 0x006D9BE8

extern "C" const char szFmtInt_006D6454[];                                                                  // 0x006D6454

extern "C" const char gszQuote[];                                                                   // 0x006D9BF4

int gnPanelOffsetX;                                                                                      // 0x007A2858

int gnPanelOffsetY;                                                                                      // 0x007A285C

extern int gnScreenWidth;                                                                               // 0x0071146C

extern int gbHoverPlayerItem;                                                                               // 0x00721E38

extern int gnHoverTopX;                                                                               // 0x00721E3C

extern int gnHoverTopY;                                                                               // 0x00721E40

extern int gnHoverBottomX;                                                                               // 0x00721E44

extern int gnHoverBottomY;                                                                               // 0x00721E48

extern D2SpeedNameStrc gaSpeedNames[6];                                                            // 0x00721E88

extern D2ItemTypeNameStrc gaItemTypeNames[15];                                                     // 0x00721EB0

extern int gaSpeedTable[][5];                                                                      // 0x00721F10

extern int gaClassSpeedOffsets[][2];                                                               // 0x00722078

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int gbHoverInGrid;                                                                                     // 0x007BCBE4

extern int gbHoverInBodyLoc;                                                                              // 0x007BCBE8

static int gnInvPanelMode;                                                                              // 0x007BCBF0

D2UnitStrc* gpHoverItem;                                                                             // 0x007BCBF4

D2InvCompGridStrc gaCompGrids[11];                                                                 // 0x007BCC58

static void __stdcall INV_AppendEtherealSocketed(D2UnitStrc* pItem, Unicode* pText);              // 0x00484B10

static void __stdcall INV_AppendQuantity(D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem, Unicode* pText); // 0x00484DB0

static void __stdcall INV_AppendDurability(D2UnitStrc* pItem, Unicode* pText);                    // 0x00484E90

static void __stdcall INV_AppendLabeledNumber(int nValue, Unicode* pText);                           // 0x00484FF0

static void __stdcall INV_AppendReqStr(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText);        // 0x004850A0

static void __stdcall INV_AppendReqDex(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText);        // 0x00485170

static void __stdcall INV_AppendBlockChance(Unicode* pText, D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem); // 0x00485BE0

static void __stdcall INV_AppendThrowDamage(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, Unicode* pText); // 0x00485D40

static void __stdcall INV_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText);                 // 0x00486100

static void __stdcall INV_AppendAttackSpeed(Unicode* pText, D2UnitStrc* pItem);                   // 0x004861D0

static void __stdcall INV_AppendItemFormulaText(D2UnitStrc* pItem, D2ItemsTxt* pRecord, Unicode* pBuffer); // 0x00486370

static void INV_AppendBookCharges(Unicode* pText);                                                 // 0x004865D0

static void __stdcall INV_AppendSocketedGemLetters(Unicode* pText, D2UnitStrc* pItem);            // 0x00486670

static int INV_IsOverWeaponSwapTab(int nX, int nY);                                                // 0x00486860

static void __stdcall INV_AppendShopPriceText(const Unicode* pSource, Unicode* pText);              // 0x0048CEA0

struct D2CelFileStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30

D2CelFileStrc* __cdecl GAME_GetBuySellButtonCells(); // 0x00454600

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

int __cdecl CUNIT_IsPlayerDeadOrMissing();                                                                    // 0x00463DF0

void __fastcall MSG_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3);               // 0x00478600

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel);                                                                   // 0x00478A00

char* __fastcall ROSTER_GetUnitName(D2UnitStrc* pUnit); // 0x0047A210

void __cdecl INV_LoadUiRecords();                                                                  // 0x004835B0

void __stdcall INV_DrawUnitInventory(D2UnitStrc* pPlayer);                                             // 0x00483FF0

void __cdecl INV_DrawEquippedItems();                                                                                // 0x004845A0

int __cdecl INV_GetPanelX(); // 0x00486AE0

int __stdcall INV_GetPanelY();                                                                     // 0x00486B00

void __stdcall INV_SelectItemPageTab(unsigned char nTab);                                          // 0x00487A10

void __fastcall INV_DrawGold(int nArg);                                                                     // 0x00488100

void __cdecl INV_DrawNpcShopPanel();                                                                                // 0x00488400

void __cdecl INV_DrawButtonHoverText();                                                            // 0x004886C0

void __stdcall INV_DrawItemTooltip(D2UnitStrc* pUnit, int bOther);                                   // 0x0048DD90

int __fastcall NPCMENU_GetInteractNpcId(int* pLow);                                                         // 0x004B3230

const Unicode* __cdecl MONSTER_GetTradePartnerName();                                                                      // 0x004B9060

int __cdecl MONSTER_GetSecondaryTradeGold();                                                                                 // 0x004B90F0

int __cdecl MONSTER_GetPrimaryTradeGold();                                                                                 // 0x004B9100

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nPaletteShift); // 0x004F64B0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc* pUnit);                                                            // 0x00623460

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);              // 0x0063BDE0

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340

extern D2CoordStrc gtOffsetTorso; // 0x007220B0
extern D2CoordStrc gtOffsetBelt; // 0x007220B8
extern D2CoordStrc gtOffsetFeet; // 0x007220C0
extern D2CoordStrc gtOffsetHead; // 0x007220C8
extern D2CoordStrc gtOffsetGloves; // 0x007220D0
extern D2CoordStrc gtOffsetNeck; // 0x007220D8
extern D2CoordStrc gtOffsetLRing; // 0x007220E0
extern D2CoordStrc gtOffsetRRing; // 0x007220E8
extern D2CoordStrc gtOffsetRArm; // 0x007220F0
extern D2CoordStrc gtOffsetLArm; // 0x007220F8
extern D2CoordStrc gtOffsetRArmTab; // 0x00722100
extern D2CoordStrc gtOffsetLArmTab; // 0x00722108

static D2CelFileStrc* gpTradePanelCel;                                                                           // 0x007BCB04

static unsigned char gnSelectedTab;                                                                // 0x007BCC04

static unsigned long gdwGlobal_007BCC08;                                                                    // 0x007BCC08

static int gnGlobal_007BCC0C;                                                                               // 0x007BCC0C

static int gbQuestTimerActive;                                                                     // 0x007BCC10

static unsigned int gnQuestTimerValue;                                                             // 0x007BCC14

static unsigned long gdwQuestTimerTicks;                                                           // 0x007BCC18

static D2CelFileStrc* gpHoradricCel;                                                                        // 0x007BCC1C

static D2CelFileStrc* gpMiniConvertCel;                                                                           // 0x007BCC28

static D2CelFileStrc* gpBankCel;                                                                           // 0x007BCC2C

static D2CelFileStrc* gpSuperTransmogrifierCel;                                                                           // 0x007BCC30

static D2CelFileStrc* gpTradeStashCel;                                                                           // 0x007BCC3C

static int gbWeaponSwitch;                                                                               // 0x007BCC4C

#define gnGlobal_007BCC6C (gaCompGrids[1].rect.nLeft)

#define gnGlobal_007BCC78 (gaCompGrids[1].rect.nBottom)

#define gnGlobal_007BCC80 (gaCompGrids[2].rect.nLeft)

#define gnGlobal_007BCC8C (gaCompGrids[2].rect.nBottom)

#define gnGlobal_007BCC94 (gaCompGrids[3].rect.nLeft)

#define gnGlobal_007BCCA0 (gaCompGrids[3].rect.nBottom)

#define gnGlobal_007BCCA8 (gaCompGrids[4].rect.nLeft)

#define gnGlobal_007BCCB4 (gaCompGrids[4].rect.nBottom)

#define gnGlobal_007BCCBC (gaCompGrids[5].rect.nLeft)

#define gnGlobal_007BCCC8 (gaCompGrids[5].rect.nBottom)

#define gnGlobal_007BCCD0 (gaCompGrids[6].rect.nLeft)

#define gnGlobal_007BCCDC (gaCompGrids[6].rect.nBottom)

#define gnGlobal_007BCCE4 (gaCompGrids[7].rect.nLeft)

#define gnGlobal_007BCCF0 (gaCompGrids[7].rect.nBottom)

#define gnGlobal_007BCCF8 (gaCompGrids[8].rect.nLeft)

#define gnGlobal_007BCD04 (gaCompGrids[8].rect.nBottom)

#define gnGlobal_007BCD0C (gaCompGrids[9].rect.nLeft)

#define gnGlobal_007BCD18 (gaCompGrids[9].rect.nBottom)

#define gnGlobal_007BCD20 (gaCompGrids[10].rect.nLeft)

#define gnGlobal_007BCD2C (gaCompGrids[10].rect.nBottom)

static int gbTradeAcceptedSelf;                                                                               // 0x007BCD34

static int gbTradeAcceptedOther;                                                                               // 0x007BCE14

static int gbTradeAccepted;                                                                               // 0x007BCE18

static int gbTradeCancelClicked;                                                                               // 0x007BCE1C

static int gbTradeFlag;                                                                                 // 0x007BCE28

static int gbStashButtonDown;                                                                               // 0x007BCE38

static int gbCubeButtonDown;                                                                               // 0x007BCE40

static int gbCubeCloseButtonDown;                                                                               // 0x007BCE48

static void* gpCelInvArmor;                                                                        // 0x007BCE68

static void* gpCelInvBelt;                                                                         // 0x007BCE6C

static void* gpCelInvBoots;                                                                        // 0x007BCE70

static void* gpCelInvHelmGlove;                                                                    // 0x007BCE74

static void* gpCelInvRingAmulet;                                                                   // 0x007BCE78

static void* gpCelInvWeapons;                                                                      // 0x007BCE7C

static void* gpCelInvChar6Tab;                                                                     // 0x007BCE84

static int gbPanelButtonDown;                                                                               // 0x007BCE90

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct Unicode;

struct D2DifficultyLevelsTxt;

struct D2MercStatLineStrc;

struct D2ElemDamageStrc;

struct D2BodyLocRectStrc;

struct D2InventoryGridInfoStrc;

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0

int __fastcall INV_IsInNpcPanelRect(int nX, int nY); // 0x00486E10

void __stdcall INV_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg); // 0x004912A0

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

static int INV_IsInTradeGrid(int nX, int nY); // 0x00483B10

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0

static int INV_IsOverTradeButtonLeft(int nX, int nY); // 0x00489430

static int INV_IsOverTradeButtonRight(int nX, int nY); // 0x00489480

extern int gnPanelX_007A2858; // 0x007A2858

extern int gnPanelY_007A285C; // 0x007A285C

extern int gnGlobal_007BCA34; // 0x007BCA34

extern int gnGlobal_007BCA38; // 0x007BCA38

extern int gnGlobal_007BCA3C; // 0x007BCA3C

extern int gnGlobal_007BCA40; // 0x007BCA40

static int gnInvMouseX; // 0x007BCA4C

extern int gnGlobal_007BCAA0; // 0x007BCAA0

extern int gnGlobal_007BCAA4; // 0x007BCAA4

extern int gnGlobal_007BCAA8; // 0x007BCAA8

extern int gnGlobal_007BCAAC; // 0x007BCAAC

static int gnInvMouseY; // 0x007BCBD8

extern int gnGlobal_007BCBF0; // 0x007BCBF0

extern int gbTradeAcceptButtonDown; // 0x007BCE20

extern int gbTradeCancelButtonDown; // 0x007BCE24

extern int gbInvGoldButtonDown; // 0x007BCE30

extern int gnGlobal_007BCE90; // 0x007BCE90

extern int gbPanelButtonClicked; // 0x007BCE9C

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __fastcall ROSTER_GetPetLife(int nUnitId); // 0x00479080

void __stdcall INV_DrawUnitName(D2UnitStrc* pUnit); // 0x0048A7D0

void __cdecl INV_DrawPanelLabels(); // 0x0048A890

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __stdcall D2LANG_FormatInt(Unicode* pOut, int nValue, int nSize); // 0x00525FB0

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

extern D2MercStatLineStrc gaMercStatLines[12]; // 0x007221A8

static void INV_DrawMercStats(D2UnitStrc* pUnit); // 0x0048A990

struct D2BodyLocRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x12[2];
};

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __stdcall INV_DrawItemSockets(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40

void __fastcall INV_DrawMercEquipHighlights(D2UnitStrc* pUnit); // 0x0048B3F0

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

extern D2BodyLocRectStrc gaBodyLocRects[11]; // 0x007BCD38

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int nIndex); // 0x00478F20


extern D2CelFileStrc* gpMercPanelCells_007BCE88; // 0x007BCE88

extern int gbBuySellPressed_007BCEA0; // 0x007BCEA0

D2InventoryGridInfoStrc gtHirelingInvGrid; // 0x007BCBC0

static void __stdcall INV_AppendEtherealSocketed(D2UnitStrc* pItem, Unicode* pText)
{
    int bEthereal = 0;
    unsigned int wszLabel[8];
    memset(wszLabel, 0, sizeof(wszLabel));
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_00526F20(W(wszLabel), &gszEmptyAssertText, 15);
    sub_005267E0(pText, W(wszLabel));
    if (ITEMS_CheckItemFlag(pItem, 0x400000, 0x6C1, ".\\UI\\inv.cpp"))
    {
        sub_00526F20(W(wszLabel), "Ethereal", 15);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x58D9));
        bEthereal = 1;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x800, 0x6C9, ".\\UI\\inv.cpp"))
    {
        if (bEthereal)
        {
            sub_00526F20(W(wszLabel), ", ", 15);
            sub_00526700(pText, W(wszLabel));
        }
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD7D));
        UNum10 wszNumber;
        unsigned int szNumber[3];
        const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
        SStrPrintf((char*)szNumber, 10, "(%i)", ITEMS_GetSockets(pItem));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
        return;
    }
    if (bEthereal)
    {
        sub_00526700(pText, pColorEnd);
    }
}

static void __stdcall INV_AppendQuantity(D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf((char*)szNumber, 10, gszFormatLd, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
    }
}

static void __stdcall INV_AppendDurability(D2UnitStrc* pItem, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (ITEMS_HasDurability(pItem) && STATLIST_GetMaxDurabilityFromUnit(pItem) > 0 && !ITEMS_CheckIfThrowable(pItem))
    {
        int bBonus = 0;
        if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MAXDURABILITY_PERCENT, 0))
        {
            bBonus = 1;
        }
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD81));
        SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0));
        sub_00526700(pText, pColorStart);
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD87));
        sub_00526700(pText, pColorStart);
        SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, STATLIST_GetMaxDurabilityFromUnit(pItem));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        if (bBonus)
        {
            INV_PrefixColorCode(W(&wszNumber), 3);
        }
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
    }
}

static void __stdcall INV_AppendLabeledNumber(int nValue, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD8D));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

static void __stdcall INV_AppendReqStr(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqStr + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD82));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

static void __stdcall INV_AppendReqDex(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqDex + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD83));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

static void __stdcall INV_AppendThrowDamage(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    int nMin = pItemsTxt->nMinDam;
    int nMax = pItemsTxt->nMaxDam;
    int nStringId;
    if (ITEMSIsA(pItem, 0x33))
    {
        nStringId = 0xD8C;
        D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, 0x75);
        if (pSkill && STATES_CheckState(pUnit, 0x65))
        {
            const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            nMin += SKILLS_GetMinPhysDamage(pUnit, 0x75, nLevel, 1) >> 8;
            nMax += SKILLS_GetMaxPhysDamage(pUnit, 0x75, nLevel, 1) >> 8;
        }
    }
    else
    {
        if (!ITEMSIsA(pItem, 0xF))
        {
            return;
        }
        nStringId = 0x5516;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(nStringId));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nMin);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD88));
    SStrPrintf((char*)szNumber, 10, szFmtInt_006D6454, nMax);
    sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, W(&wszNumber));
    sub_00526700(pText, pColorEnd);
}

static void __stdcall INV_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText)
{
    UNum10 wszNumber;
    unsigned int szNumber[3];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf((char*)szNumber, 10, gszFormatLd, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(W(&wszNumber), (char*)szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, W(&wszNumber));
        sub_00526700(pText, pColorEnd);
    }
}

static void __stdcall INV_AppendBlockChance(Unicode* pText, D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem)
{
    int nBlock = STATLIST_UnitGetStatValue(pItem, STAT_TOBLOCK, 0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        const int nClass = pPlayer->dwClassId;
        D2CharStatsTxt* pCharStats = (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClass] : 0;
        nBlock += pCharStats->nBlockFactor;
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, 0x75);
        if (pSkill && STATES_CheckState(pPlayer, 0x65))
        {
            const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            nBlock += D2COMMON_11036_GetMonCurseResistanceSubtraction(nLevel, 0x75);
        }
        if (nBlock > 0x4B)
        {
            nBlock = 0x4B;
        }
    }
    if (!nBlock)
    {
        return;
    }
    UBuf wszBlock[16];
    unsigned int szBlock[8];
    UBuf wszText[128];
    SStrPrintf((char*)szBlock, 32, "%d%%\n", nBlock);
    sub_00526F20(W(wszBlock), (char*)szBlock, 32);
    if (nBlock > pItemsTxt->nBlock)
    {
        INV_PrefixColorCode(W(wszBlock), 3);
    }
    sub_005267E0(W(wszText), D2LANG_GetStringFromTblIndex(0x2B0A));
    INV_PrefixColorCode(W(wszText), 0);
    sub_005267E0(pText, W(wszText));
    sub_00526700(pText, W(wszBlock));
}

static void __stdcall INV_AppendAttackSpeed(Unicode* pText, D2UnitStrc* pItem)
{
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pColorAlt = D2LANG_GetStringFromTblIndex(0xF9C);
    D2UnitStrc* pStoredUnit = sub_00463DE0_GetPlayerUnit();
    const int nAttackSpeed = ITEMS_GetWeaponAttackSpeed(pStoredUnit, pItem);
    int bBonus = 0;
    if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_FASTERATTACKRATE, 0))
    {
        bBonus = 1;
    }
    int nSpeed;
    if (nAttackSpeed >= 0x1C)
    {
        nSpeed = 5;
    }
    else if (nAttackSpeed < 10)
    {
        nSpeed = 1;
    }
    else
    {
        D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
        const int bMissile = (ITEMSIsA(pItem, 0x23) || ITEMSIsA(pItem, 0x1B)) ? 1 : 0;
        const int nClass = !pUnit ? -1 : pUnit->dwClassId;
        nSpeed = gaSpeedTable[nAttackSpeed - 10][gaClassSpeedOffsets[nClass][bMissile]];
    }
    int nFound = -1;
    for (int i = 0; i < 15; ++i)
    {
        if (ITEMSIsA(pItem, gaItemTypeNames[i].nItemType))
        {
            nFound = i;
            break;
        }
    }
    if (nFound >= 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(gaItemTypeNames[nFound].nString));
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, pColorAlt);
        sub_00526700(pText, pColorStart);
    }
    UBuf wszText[128];
    sub_005267E0(W(wszText), D2LANG_GetStringFromTblIndex(gaSpeedNames[nSpeed].nString));
    if (bBonus)
    {
        INV_PrefixColorCode(W(wszText), 3);
    }
    sub_00526700(pText, W(wszText));
    sub_00526700(pText, pColorEnd);
}

static void __stdcall INV_AppendItemFormulaText(D2UnitStrc* pItem, D2ItemsTxt* pRecord, Unicode* pBuffer)
{
    if (!pItem || !pRecord || !pRecord->nDescType)
    {
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || pRecord->wStringId == 0x1506)
    {
        return;
    }

    const Unicode* pSeparator = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pLineEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    switch (pRecord->nDescType)
    {
    case 1:
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        sub_00526700(pBuffer, pLineEnd);
        break;

    case 2:
    {
        unsigned int szValue[3];
        unsigned int wszValue[5];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->dwCalc[0]);
        switch (pRecord->wStat[0])
        {
        case 6:
        case 74:
            nValue = ITEMS_GetBonusLifeBasedOnClass(pPlayer, nValue);
            break;
        case 8:
        case 26:
            nValue = ITEMS_GetBonusManaBasedOnClass(pPlayer, nValue);
            break;
        }
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf((char*)szValue, 10, gszFormatLd, nValue);
        sub_00526F20(W(wszValue), (char*)szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, W(wszValue));
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 3:
    {
        unsigned int szValue[3];
        unsigned int wszValue[5];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->dwCalc[0]);
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf((char*)szValue, 10, gszFormatLd, nValue);
        sub_00526F20(W(wszValue), (char*)szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, W(wszValue));
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 4:
    {
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->dwCalc[0]);
        unsigned int wszText[0x100];
        sub_005269D0(0x200, W(wszText), D2LANG_GetStringFromTblIndex(pRecord->wStringId), nValue);
        sub_00526700(pBuffer, W(wszText));
        sub_00526700(pBuffer, pLineEnd);
        break;
    }
    }
}

static void INV_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMSIsA(gpHoverItem, 0x35), 0xC43);
    sub_004E6850_BuildSocketFillerText(gpHoverItem, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

static void __stdcall INV_AppendSocketedGemLetters(Unicode* pText, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return;
    }
    unsigned int wszLetter[3];
    int bAny = 0;
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pGem = INVENTORY_UnitIsItem(pNode);
        if (!pGem)
        {
            break;
        }
        if (ITEMSIsA(pGem, 0x4A))
        {
            const int nClassId = pGem->dwClassId;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
            const int nGemOffset = pItemsTxtRecord->dwGemOffset;
            if (nGemOffset > 0)
            {
                D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(nGemOffset);
                if (pGemsTxtRecord)
                {
                    if (!bAny)
                    {
                        bAny = 1;
                        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x501A));
                    }
                    sub_00526320_ToUnicode(W(wszLetter), pGemsTxtRecord->szLetter, 6);
                    sub_00526700(pText, W(wszLetter));
                }
            }
        }
    }
    if (bAny)
    {
        sub_00526320_ToUnicode(W(wszLetter), gszQuote, 5);
        sub_00526700(pText, W(wszLetter));
        sub_00526700(pText, pColorEnd);
    }
}

static int __stdcall INV_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

static int INV_IsOverWeaponSwapTab(int nX, int nY)
{
    if (nX >= gaCompGrids[5].rect.nLeft && nX <= gaCompGrids[5].rect.nRight && nY >= gaCompGrids[5].rect.nTop - 0x18 && nY < gaCompGrids[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids[4].rect.nLeft && nX <= gaCompGrids[4].rect.nRight && nY >= gaCompGrids[4].rect.nTop - 0x18 && nY < gaCompGrids[4].rect.nTop)
    {
        return 1;
    }
    return 0;
}

static void __stdcall INV_AppendShopPriceText(const Unicode* pSource, Unicode* pText)
{
    unsigned int wszName[0x20];
    memset(wszName, 0, sizeof(wszName));
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, pSource);
    if (gnInvPanelMode == 4 && ITEMS_CheckItemFlag(gpHoverItem, 0x400000, 0xCCC, ".\\UI\\inv.cpp"))
    {
        unsigned int wszLabel[0x40];
        sub_005267E0(W(wszLabel), D2LANG_GetStringFromTblIndex(0x58DA));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(W(wszLabel), 1));
    }

    int nSetIndex;
    if (NPCMENU_GetTradeCostText(gpHoverItem, gbHoverPlayerItem, &nSetIndex, W(wszName), 0x40))
    {
        if (W(wszName)[0].wChar)
        {
            sub_00526700(pText, pColorEnd);
        }
        sub_00526700(pText, W(wszName));
        return;
    }

    if (gnInvPanelMode != 4)
    {
        unsigned int wszLabel[0x20];
        sub_005267E0(W(wszLabel), D2LANG_GetStringFromTblIndex(0xD05));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(W(wszLabel), 1));
    }
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x0048DD90
void __stdcall INV_DrawItemTooltip(D2UnitStrc* pUnit, int nFlag)
{
    UBuf wszText[0x200];
    UBuf wszTooltip[0x200];
    UBuf wszBookCharges[0x100];
    UBuf wszMisc[0x80];
    UBuf wszGems[0x80];
    UBuf wszDurability[0x80];
    UBuf wszLevelReq[0x80];
    UBuf wszReqStr[0x80];
    UBuf wszReqDex[0x80];
    UBuf wszDamage[0x80];
    UBuf wszBlock[0x80];
    UBuf wszThrowDamage[0x80];
    UBuf wszDefense[0x80];
    UBuf wszUnidentified[0x80];
    UBuf wszClassReq[0x80];
    UBuf wszEthSock[0x80];
    UBuf wszFormula[0x80];
    UBuf wszAttackSpeed[0x200];
    int nPopupArg = 0;
    UBuf wszName[0x200];
    UBuf wszProps[0x800];
    int nColor = 0;
    int bRedLevel = 0;
    int bRedStr = 0;
    int bRedDex = 0;
    int bRedClass = 0;
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2UnitStrc* pPlayer = pUnit;
    if (nFlag && sub_00463DD0_GetPlayerUnit())
    {
        pPlayer = sub_00463DD0_GetPlayerUnit();
    }

    const int bHoverBlocked = HIREABLES_AreBeltRowsShown();
    if (!bHoverBlocked)
    {
        if (GAME_GetUIVarState(0x24))
        {
            if (INV_IsMouseInBox(gnPanelOffsetX + 0x110, gnScreenHeight + gnPanelOffsetY - 0x3F, 0x20, 0x20))
            {
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnPanelOffsetX + 0x11F, gnPanelOffsetY + gnScreenHeight - 0x62, 0, 1);
            }
        }

        if (GAME_GetUIVarState(1) || GAME_GetUIVarState(0x17) || GAME_GetUIVarState(0x19) || GAME_GetUIVarState(0xC) || GAME_GetUIVarState(0xE) || GAME_GetUIVarState(0x1A))
        {
            if (INV_IsMouseInBox(gnScreenWidth - gnPanelOffsetX - 0x12E, gnScreenHeight + gnPanelOffsetY - 0x40, 0x20, 0x20))
            {
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnScreenWidth - gnPanelOffsetX - 0x11F, gnScreenHeight + (gnPanelOffsetY - 0x63), 0, 1);
            }

            if (INV_IsMouseInBox(gnScreenWidth - gnPanelOffsetX - 0xED, gnPanelOffsetY + gnScreenHeight - 0x45, 0x14, 0x12) && !NPCMENU_IsAnyDialogOpen())
            {
                int nStr = 0x101D;
                switch (gnInvPanelMode)
                {
                case 1:
                    nStr = 0x1003;
                    break;
                case 12:
                case 13:
                case 15:
                    nStr = 0x101E;
                    break;
                case 11:
                    nStr = 0x1021;
                    break;
                }
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(nStr), gnScreenWidth - gnPanelOffsetX - 0xDE, gnScreenHeight + (gnPanelOffsetY - 0x59), 0, 1);
            }

            if (FOG_IsExpansion() && GAME_IsExpansion() && INV_IsOverWeaponSwapTab(sub_00468730(), sub_00468740()))
            {
                unsigned int wszSwap[0x100];
                sub_00403040_VectorCtor(wszSwap, 2, 0x200, sub_0042F530_UnicodeCtor);
                sub_005267E0(W(wszSwap), D2LANG_GetStringFromTblIndex(0x58C6));
                if (CUNIT_GetHotkeyBinding(0x2C, 1) != 0xFFFF)
                {
                    sub_00526700(W(wszSwap), D2LANG_GetStringFromTblIndex(0xF9D));
                    sub_00526700(W(wszSwap), CMDTBL_GetKeyName(0x2C, 1));
                }
                else if (CUNIT_GetHotkeyBinding(0x2C, 0) != 0xFFFF)
                {
                    sub_00526700(W(wszSwap), D2LANG_GetStringFromTblIndex(0xF9D));
                    sub_00526700(W(wszSwap), CMDTBL_GetKeyName(0x2C, 0));
                }
                int nOffset = 0x170;
                if (sub_00468730() > gnPanelOffsetX + 0x1F4)
                {
                    nOffset = 0x258;
                }
                D2Win_10129_DrawFramedText(W(wszSwap), nOffset + gnPanelOffsetX, 0x15 - gnPanelOffsetY, 0, 1);
            }
        }
    }

    if ((gbHoverInBodyLoc || gbHoverInGrid) && gpHoverItem)
    {
        if (pUnit->pInventory && !INVENTORY_GetCursorItem(pUnit->pInventory))
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!GAME_GetUIVarState(0x17) && pInventory && gpHoverItem && !INVENTORY_CompareWithItemsParentInventory(pInventory, gpHoverItem))
            {
                return;
            }

            int nWidth;
            int nHeight;
            if (gbHoverInGrid && !gbHoverPlayerItem && NPCMENU_IsGambleShop() && (unsigned int)(gnInvPanelMode - 1) <= 8)
            {
                INV_BuildItemName(gpHoverItem, W(wszName), 0x80);
                sub_005267E0(W(wszUnidentified), D2LANG_GetStringFromTblIndex(0xD7F));
                sub_00526700(W(wszUnidentified), pColorEnd);
                sub_00526700(W(wszText), W(wszUnidentified));
                switch (ITEMS_GetItemType(gpHoverItem))
                {
                case 0x3C:
                case 0x55:
                case 0x56:
                case 0x57:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA5));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x3D:
                case 0x47:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA9));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x3E:
                case 0x45:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA7));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x3F:
                case 0x46:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA8));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x40:
                case 0x44:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AA6));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x41:
                case 0x43:
                case 0x58:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AAB));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                case 0x42:
                case 0x48:
                case 0x49:
                    sub_00526700(W(wszText), D2LANG_GetStringFromTblIndex(0x2AAA));
                    sub_00526700(W(wszText), pColorEnd);
                    break;
                }
                sub_00526700(W(wszText), W(wszName));
                INV_PrefixColorCode(W(wszText), 0);
                INV_AppendShopPriceText(W(wszText), W(wszTooltip));
                D2Win_10131_GetTextDimensions(W(wszTooltip), &nWidth, &nHeight);
                if (gnHoverTopY - nHeight > 0)
                {
                    D2Win_10129_DrawFramedText(W(wszTooltip), gnHoverTopX, gnHoverTopY, 0, 1);
                }
                else
                {
                    D2Win_10129_DrawFramedText(W(wszTooltip), gnHoverBottomX, gnHoverBottomY + nHeight, 0, 1);
                }
                return;
            }

            const int nQuality = ITEMS_GetItemQuality(gpHoverItem);
            if (sub_00468830() == 8 || ITEMS_GetTransmogrify(gpHoverItem))
            {
                INV_DrawTransmogrifyTooltip();
                return;
            }
            if (nQuality == 5 && ITEMS_CheckItemFlag(gpHoverItem, 0x10, 0xF9F, ".\\UI\\inv.cpp"))
            {
                INV_DrawSetItemTooltip(pUnit);
                return;
            }
            if (ITEMS_GetItemType(gpHoverItem) == 0x12)
            {
                INV_DrawBookTooltip();
                return;
            }

            const int nClass = ITEMS_GetClassOfClassSpecificItem(gpHoverItem);
            if (nClass != 7)
            {
                sub_00526700(W(wszClassReq), D2LANG_GetStringFromTblIndex(nClass + 0x2AA5));
                sub_00526700(W(wszClassReq), pColorEnd);
                if (UNITS_GetWeaponClass(pPlayer) != nClass)
                {
                    bRedClass = 1;
                }
            }

            D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId);
            D2_ASSERT(pItemsTxt, 0xFC2);

            if (ITEMS_GetQuiverType(gpHoverItem))
            {
                INV_AppendQuantity(pItemsTxt, gpHoverItem, W(wszText));
            }
            else
            {
                INV_AppendDurability(gpHoverItem, W(wszDurability));
            }

            int bStr;
            int bDex;
            ITEMS_CheckRequirements(gpHoverItem, pPlayer, 0, &bStr, &bDex, &nFlag);
            if (ITEMS_CheckItemFlag(gpHoverItem, 0x10, 0xFD6, ".\\UI\\inv.cpp"))
            {
                const int nLevelReq = ITEMS_GetLevelRequirement(gpHoverItem, pPlayer);
                if (nLevelReq > 1)
                {
                    if (!nFlag)
                    {
                        bRedLevel = 1;
                    }
                    INV_AppendLabeledNumber(nLevelReq, W(wszLevelReq));
                }
            }
            if (ITEMSIsA(gpHoverItem, 0x35))
            {
                INV_AppendBookCharges(W(wszBookCharges));
            }
            if (ITEMS_CheckIfSocketable(gpHoverItem))
            {
                INV_AppendSocketedGemLetters(W(wszGems), gpHoverItem);
            }
            if (ITEMSIsA(gpHoverItem, 0xD))
            {
                const Unicode* pColorEnd2 = D2LANG_GetStringFromTblIndex(0xF9E);
                sub_00526700(W(wszMisc), D2LANG_GetStringFromTblIndex(0x4FD6));
                sub_00526700(W(wszMisc), pColorEnd2);
            }

            if (ITEMSIsA(gpHoverItem, 0x2D) || ITEMSIsA(gpHoverItem, 0x32))
            {
                INV_AppendEtherealSocketed(gpHoverItem, W(wszEthSock));
                int nStrBonus = 0;
                int nDexBonus = 0;
                const int nPercent = STATLIST_UnitGetItemStatOrSkillStatValue(gpHoverItem, STAT_ITEM_REQ_PERCENT, 0);
                if (nPercent)
                {
                    nStrBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqStr, nPercent, 100);
                    nDexBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqDex, nPercent, 100);
                }
                if (ITEMS_CheckItemFlag(gpHoverItem, 0x400000, 0xFFA, ".\\UI\\inv.cpp"))
                {
                    nStrBonus -= 10;
                    nDexBonus -= 10;
                }
                if (pItemsTxt->wReqDex > 0)
                {
                    if (!bDex)
                    {
                        bRedDex = 1;
                    }
                    INV_AppendReqDex(pItemsTxt, nDexBonus, W(wszReqDex));
                }
                if (pItemsTxt->wReqStr > 0)
                {
                    if (!bStr)
                    {
                        bRedStr = 1;
                    }
                    INV_AppendReqStr(pItemsTxt, nStrBonus, W(wszReqStr));
                }
                if (ITEMSIsA(gpHoverItem, 0x2D))
                {
                    if (STATLIST_GetMinDamageFromUnit(gpHoverItem, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(gpHoverItem, 0) >= 0)
                    {
                        sub_00485410_AppendDamage(gpHoverItem, W(wszDamage));
                    }
                    INV_AppendAttackSpeed(W(wszAttackSpeed), gpHoverItem);
                }
                if (ITEMSIsA(gpHoverItem, 0x33))
                {
                    if (pPlayer && pPlayer->dwClassId == 3 && (!ITEMS_IsClassValid(gpHoverItem) || ITEMS_GetClassOfClassSpecificItem(gpHoverItem) == 3))
                    {
                        INV_AppendThrowDamage(gpHoverItem, pItemsTxt, W(wszThrowDamage));
                    }
                    INV_AppendBlockChance(W(wszBlock), pItemsTxt, gpHoverItem);
                }
                else if (ITEMSIsA(gpHoverItem, 0xF) && pPlayer && pPlayer->dwClassId == 6)
                {
                    INV_AppendThrowDamage(gpHoverItem, pItemsTxt, W(wszThrowDamage));
                }
                if (ITEMSIsA(gpHoverItem, 0x32) && STATLIST_GetDefenseFromUnit(gpHoverItem) > 0)
                {
                    INV_AppendDefense(pPlayer, gpHoverItem, W(wszDefense));
                }
            }

            switch (nQuality)
            {
            case 7:
                nColor = 4;
                break;
            case 4:
                nColor = 3;
                break;
            case 6:
                nColor = 9;
                break;
            case 8:
                nColor = 8;
                break;
            case 9:
                nColor = 10;
                break;
            case 5:
                nColor = 2;
                break;
            default:
                if (ITEMS_CheckItemFlag(gpHoverItem, 0x800, 0x1050, ".\\UI\\inv.cpp"))
                {
                    nColor = 5;
                }
                else if (ITEMS_CheckItemFlag(gpHoverItem, 0x400000, 0x1054, ".\\UI\\inv.cpp"))
                {
                    nColor = 5;
                }
                break;
            }

            if (!ITEMS_CheckItemFlag(gpHoverItem, 0x10, 0x105D, ".\\UI\\inv.cpp") && (unsigned int)(gnInvPanelMode - 1) <= 8 && !gbHoverPlayerItem)
            {
                nColor = 0;
            }

            if (ITEMS_CheckItemFlag(gpHoverItem, 0x10, 0x1069, ".\\UI\\inv.cpp"))
            {
                if (!ITEMS_CheckItemFlag(gpHoverItem, 0x800, 0x106C, ".\\UI\\inv.cpp"))
                {
                    INV_AppendStackQuantity(gpHoverItem, W(wszFormula));
                }
                sub_004E6410_BuildPropText(gpHoverItem, W(wszProps), 0x1000, 1, 0);
            }
            else
            {
                sub_005267E0(W(wszUnidentified), D2LANG_GetStringFromTblIndex(0xD7F));
                sub_00526700(W(wszUnidentified), pColorEnd);
            }
            INV_AppendItemFormulaText(gpHoverItem, pItemsTxt, W(wszFormula));
            INV_BuildItemName(gpHoverItem, W(wszName), 0x100);
            sub_005267E0(W(wszText), INV_PrefixColorCode(W(wszEthSock), 3));

            const unsigned int dwCode = pItemsTxt->dwCode;
            if (dwCode == 0x20686563 || dwCode == 0x20746562 || dwCode == 0x20736574 || dwCode == 0x20646566
                || dwCode == 0x20616F74 || dwCode == 0x206E6864 || dwCode == 0x20796562 || dwCode == 0x2072626D
                || dwCode == 0x20316B70 || dwCode == 0x20326B70 || dwCode == 0x20336B70
                || ITEMSIsA(gpHoverItem, 0x4A))
            {
                nColor = 8;
            }

            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszProps), 3));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszUnidentified), 1));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszAttackSpeed), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszLevelReq), bRedLevel));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszReqStr), bRedStr));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszReqDex), bRedDex));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszClassReq), bRedClass));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszDurability), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszBookCharges), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszMisc), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszFormula), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszDamage), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszThrowDamage), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszBlock), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszDefense), 0));
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszGems), 4));
            if (ITEMS_CheckItemFlag(gpHoverItem, 0x100, 0x10A7, ".\\UI\\inv.cpp"))
            {
                nColor = 1;
            }
            sub_00526700(W(wszText), INV_PrefixColorCode(W(wszName), nColor));

            if (gnInvPanelMode && (unsigned int)(gnInvPanelMode - 1) <= 8)
            {
                INV_AppendShopPriceText(W(wszText), W(wszTooltip));
            }
            else
            {
                sub_005267E0(W(wszTooltip), W(wszText));
            }

            if (pItemsTxt->nQuest && pItemsTxt->dwCode != 0x2067656C)
            {
                if (!gnInvPanelMode && (!gpHoverItem || !gpHoverItem->dwAnimMode))
                {
                    if (pItemsTxt->dwCode == 0x20646B62)
                    {
                        sub_005267E0(W(wszText), W(wszTooltip));
                        sub_005267E0(W(wszTooltip), D2LANG_GetStringFromTblIndex(0x89D));
                        sub_00526700(W(wszTooltip), pColorEnd);
                        sub_00526700(W(wszTooltip), W(wszText));
                    }
                    else if (pItemsTxt->dwCode == 0x20786F62)
                    {
                        sub_005267E0(W(wszText), W(wszTooltip));
                        sub_005267E0(W(wszTooltip), D2LANG_GetStringFromTblIndex(0x89C));
                        sub_00526700(W(wszTooltip), pColorEnd);
                        sub_00526700(W(wszTooltip), W(wszText));
                    }
                }
                nPopupArg = 4;
                INV_PrefixColorCode(W(wszTooltip), nPopupArg);
            }
            sub_00452170(W(wszTooltip));
            if (sub_00526800(W(wszTooltip)) >= 0x3FF)
            {
                W(wszTooltip)[0x3FF].wChar = 0;
            }
            D2Win_10131_GetTextDimensions(W(wszTooltip), &nWidth, &nHeight);
            if (gnHoverTopY - nHeight > 0)
            {
                D2Win_10129_DrawFramedText(W(wszTooltip), gnHoverTopX, gnHoverTopY, nPopupArg, 1);
            }
            else
            {
                D2Win_10129_DrawFramedText(W(wszTooltip), gnHoverBottomX, gnHoverBottomY + nHeight, nPopupArg, 1);
            }
        }
    }
}

// build: symbol ?INV_IsOverButtonC@* 0x00489FB0
static int INV_IsOverButtonC(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x13B
        && nY > gnScreenHeight + gnPanelOffsetY - 0x64 && nY < gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?INV_IsOverCubeButton@* 0x0048A000
static int INV_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x90 && nX < gnPanelOffsetX + 0xB8
        && nY > gnScreenHeight + gnPanelOffsetY - 0xDF && nY < gnScreenHeight + gnPanelOffsetY - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x0048EDF0
void __cdecl INV_DrawInventoryPanel()
{
    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    if (gnInvPanelMode == 10)
    {
        return;
    }

    if (gnInvPanelMode >= 1 && gnInvPanelMode <= 9)
    {
        if (GetTickCount() > gdwGlobal_007BCC08)
        {
            gdwGlobal_007BCC08 = 0;
        }
        int nTick;
        if (gnGlobal_007BCC0C == 1 && !gdwGlobal_007BCC08 && NPCMENU_GetInteractNpcId(&nTick))
        {
            INV_SelectItemPageTab(gnSelectedTab);
            gnGlobal_007BCC0C = 0;
        }
        INV_DrawNpcShopPanel();
        INV_DrawGold(2);
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;

    switch (gnInvPanelMode)
    {
    case 14:
        if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
        {
            if (gpSuperTransmogrifierCel)
            {
                tContext.pCellFile = gpSuperTransmogrifierCel;
                tContext.nFrame = 0;
                TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
                tContext.nFrame = 1;
                TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
                tContext.nFrame = 2;
                TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
                tContext.nFrame = 3;
                TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
            }

            const unsigned char nOldTab = gnSelectedTab;
            if (!gbQuestTimerActive || gnQuestTimerValue >= 14)
            {
                gnSelectedTab = 3;
                INV_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
                gnSelectedTab = nOldTab;
            }

            tContext.pCellFile = GAME_GetBuySellButtonCells();
            tContext.nFrame = gbCubeButtonDown + 10;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x113, gnScreenHeight + gnPanelOffsetY - 0x41, -1, 5, 0);

            tContext.pCellFile = gpMiniConvertCel;
            tContext.nFrame = gbCubeCloseButtonDown;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x90, gnScreenHeight + gnPanelOffsetY - 0xBC, -1, 5, 0);

            if (gbQuestTimerActive)
            {
                const unsigned long dwTick = GetTickCount();
                if (dwTick - gdwQuestTimerTicks > 70)
                {
                    gdwQuestTimerTicks = dwTick;
                    if (++gnQuestTimerValue >= 30)
                    {
                        gbQuestTimerActive = 0;
                        if (gpHoradricCel)
                        {
                            ARCHIVE_FreeClientCellFile(gpHoradricCel);
                            gpHoradricCel = 0;
                        }
                        goto timer_done;
                    }
                }
                tContext.pCellFile = gpHoradricCel;
                tContext.nFrame = gnQuestTimerValue;
                TEXTURE_CelDraw(&tContext, gnScreenWidth / 2, gnScreenHeight / 2 - 1, -1, 3, 0);
            }
timer_done:
            D2Win_10127_SetFont(1);

            if (INV_IsOverButtonC(nMouseX, nMouseY))
            {
                const Unicode* wszText = D2LANG_GetStringFromTblIndex(0x1030);
                D2Win_10129_DrawFramedText(wszText, gnPanelOffsetX - D2Win_10121_GetTextWidth(wszText) / 2 + 0x121, gnScreenHeight + gnPanelOffsetY - 0x64, 0, 0);
            }
            else if (INV_IsOverCubeButton(nMouseX, nMouseY))
            {
                const Unicode* wszText = D2LANG_GetStringFromTblIndex(0xD0D);
                D2Win_10129_DrawFramedText(wszText, gnPanelOffsetX - D2Win_10121_GetTextWidth(wszText) / 2 + 0x9E, gnScreenHeight + gnPanelOffsetY - 0xDF, 0, 0);
            }
        }
        else
        {
            UI_SetUIVar(0x1A, 1, 0);
            MSG_SendShorts(0x4F, 0x17, 0, 0);
            return;
        }
        break;

    case 12:
    case 13:
    {
        if (gpBankCel)
        {
            if (GAME_IsExpansion())
            {
                tContext.pCellFile = gpTradeStashCel;
            }
            else
            {
                tContext.pCellFile = gpBankCel;
            }
            tContext.nFrame = 0;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
            tContext.nFrame = 1;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
            tContext.nFrame = 2;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
            tContext.nFrame = 3;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
        }

        const int nGoldLimit = UNITS_GetStashGoldLimit(sub_00463DD0_GetPlayerUnit());
        Unicode wszGold[100];
        sub_005269D0(100, wszGold, D2LANG_GetStringFromTblIndex(0xFD3), nGoldLimit);
        if (GAME_IsExpansion())
        {
            D2Win_10117_DrawText(wszGold, gnPanelOffsetX + 0x4E, gnScreenHeight + gnPanelOffsetY - 0x19F, 0, 0);
        }
        else
        {
            D2Win_10117_DrawText(wszGold, gnPanelOffsetX + 0x4E, gnScreenHeight + gnPanelOffsetY - 0xDB, 0, 0);
        }

        const unsigned char nOldTab = gnSelectedTab;
        gnSelectedTab = 4;
        INV_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
        gnSelectedTab = nOldTab;

        tContext.pCellFile = GAME_GetBuySellButtonCells();
        tContext.nFrame = gbStashButtonDown + 10;
        const int nButtonX = !GAME_IsExpansion() ? gnPanelOffsetX + 0x113 : gnPanelOffsetX + 0x110;
        TEXTURE_CelDraw(&tContext, nButtonX, INV_GetPanelY(), -1, 5, 0);

        INV_DrawGold(0);
        const int nCursorX = sub_00468730();
        const int nCursorY = sub_00468740();
        const int nLeft = !GAME_IsExpansion() ? gnPanelOffsetX + 0x113 : gnPanelOffsetX + 0x110;
        if (nCursorX >= nLeft && nCursorX <= INV_GetPanelX() + 0x28
            && nCursorY >= INV_GetPanelY() - 0x23 && nCursorY <= INV_GetPanelY() + 5)
        {
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(0x1030);
            D2Win_10129_DrawFramedText(wszText, INV_GetPanelX() - D2Win_10121_GetTextWidth(wszText) / 2 + 12, INV_GetPanelY() - 0x23, 0, 0);
        }
        break;
    }
    }

    tContext.pCellFile = gpCellFile_007BEF64;
    tContext.nFrame = 4;
    TEXTURE_CelDraw(&tContext, gnScreenWidth - gnPanelOffsetX - 0x140, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tContext.nFrame = 5;
    TEXTURE_CelDraw(&tContext, gnScreenWidth - gnPanelOffsetX - 0x40, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tContext.nFrame = 6;
    TEXTURE_CelDraw(&tContext, gnScreenWidth - gnPanelOffsetX - 0x140, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
    tContext.nFrame = 7;
    TEXTURE_CelDraw(&tContext, gnScreenWidth - gnPanelOffsetX - 0x40, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);

    INV_LoadUiRecords();

    if (gbWeaponSwitch && FOG_IsExpansion() && GAME_IsExpansion())
    {
        tContext.pCellFile = gpCelInvChar6Tab;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gtOffsetLArmTab.nX, gnGlobal_007BCCC8 + gtOffsetLArmTab.nY, -1, 5, 0);
        tContext.pCellFile = gpCelInvChar6Tab;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gtOffsetRArmTab.nX, gnGlobal_007BCCB4 + gtOffsetRArmTab.nY, -1, 5, 0);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2InventoryStrc* pInventory = pPlayer->pInventory;

    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 3))
    {
        tContext.pCellFile = gpCelInvArmor;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCC94 + gtOffsetTorso.nX, gnGlobal_007BCCA0 + gtOffsetTorso.nY, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 8))
    {
        tContext.pCellFile = gpCelInvBelt;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCF8 + gtOffsetBelt.nX, gnGlobal_007BCD04 + gtOffsetBelt.nY, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 9))
    {
        tContext.pCellFile = gpCelInvBoots;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCD0C + gtOffsetFeet.nX, gnGlobal_007BCD18 + gtOffsetFeet.nY, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 1))
    {
        tContext.pCellFile = gpCelInvHelmGlove;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCC6C + gtOffsetHead.nX, gnGlobal_007BCC78 + gtOffsetHead.nY, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 10))
    {
        tContext.pCellFile = gpCelInvHelmGlove;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCD20 + gtOffsetGloves.nX, gnGlobal_007BCD2C + gtOffsetGloves.nY, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 2))
    {
        tContext.pCellFile = gpCelInvRingAmulet;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCC80 + gtOffsetNeck.nX, gnGlobal_007BCC8C + gtOffsetNeck.nY, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 6))
    {
        tContext.pCellFile = gpCelInvRingAmulet;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCD0 + gtOffsetRRing.nX, gnGlobal_007BCCDC + gtOffsetRRing.nY, -1, 5, 0);
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 7))
    {
        tContext.pCellFile = gpCelInvRingAmulet;
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnGlobal_007BCCE4 + gtOffsetLRing.nX, gnGlobal_007BCCF0 + gtOffsetLRing.nY, -1, 5, 0);
    }

    int nOffsetX = 0;
    int nOffsetY = 0;
    if (GAME_IsExpansion() && gbWeaponSwitch)
    {
        nOffsetX = 4;
        nOffsetY = -4;
    }
    const int bRightHand = (int)INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    const int bLeftHand = (int)INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    const int bTwoHanded = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;

    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 5))
    {
        tContext.pCellFile = gpCelInvWeapons;
        tContext.nFrame = 0;
        if (bRightHand)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gtOffsetLArm.nX + nOffsetX, gnGlobal_007BCCC8 + gtOffsetLArm.nY + nOffsetY, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gtOffsetLArm.nX + nOffsetX, gnGlobal_007BCCC8 + gtOffsetLArm.nY + nOffsetY, -1, 5, 0);
        }
    }
    if (!INVENTORY_GetItemFromBodyLoc(pInventory, 4))
    {
        tContext.pCellFile = gpCelInvWeapons;
        tContext.nFrame = 0;
        if (bLeftHand)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gtOffsetRArm.nX + nOffsetX, gnGlobal_007BCCB4 + gtOffsetRArm.nY + nOffsetY, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gtOffsetRArm.nX + nOffsetX, gnGlobal_007BCCB4 + gtOffsetRArm.nY + nOffsetY, -1, 5, 0);
        }
    }

    tContext.pCellFile = gpCelInvWeapons;
    tContext.nFrame = 0;
    if (bRightHand && bLeftHand)
    {
        if (!bTwoHanded)
        {
            if (!INVENTORY_GetItemFromBodyLoc(pInventory, 5))
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gtOffsetLArm.nX, gnGlobal_007BCCC8 + gtOffsetLArm.nY, -1, 5, 0);
            }
            if (!INVENTORY_GetItemFromBodyLoc(pInventory, 4))
            {
                TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gtOffsetRArm.nX, gnGlobal_007BCCB4 + gtOffsetRArm.nY, -1, 5, 0);
            }
        }
    }
    else if (!bRightHand && bLeftHand)
    {
        if (!INVENTORY_GetItemFromBodyLoc(pInventory, 5))
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCBC + gtOffsetLArm.nX, gnGlobal_007BCCC8 + gtOffsetLArm.nY, -1, 5, 0);
        }
    }
    else if (bRightHand && !bLeftHand)
    {
        if (!INVENTORY_GetItemFromBodyLoc(pInventory, 4))
        {
            TEXTURE_CelDraw(&tContext, gnGlobal_007BCCA8 + gtOffsetRArm.nX, gnGlobal_007BCCB4 + gtOffsetRArm.nY, -1, 5, 0);
        }
    }

    if (gnInvPanelMode == 11 && gpTradePanelCel)
    {
        tContext.pCellFile = gpTradePanelCel;
        tContext.nFrame = 0;
        TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tContext.nFrame = 1;
        TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tContext.nFrame = 2;
        TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
        tContext.nFrame = 3;
        TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);

        tContext.pCellFile = GAME_GetBuySellButtonCells();
        if (gbTradeAcceptedOther)
        {
            tContext.nFrame = 17;
            TEXTURE_CelDrawColor(&tContext, gnPanelOffsetX + 0x113, gnScreenHeight + gnPanelOffsetY - 0x116, -1, 5, 2);
        }
        else
        {
            tContext.nFrame = 16;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x113, gnScreenHeight + gnPanelOffsetY - 0x116, -1, 5, 0);
        }

        if (gbTradeFlag)
        {
            tContext.nFrame = 16;
            TEXTURE_CelDrawColor(&tContext, gnPanelOffsetX + 0xDF, gnScreenHeight + gnPanelOffsetY - 0x40, -1, 5, 1);
        }
        else if (!gbTradeAcceptedSelf && !gbTradeAccepted)
        {
            tContext.nFrame = 16;
            TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0xDF, gnScreenHeight + gnPanelOffsetY - 0x40, -1, 5, 0);
        }
        else
        {
            tContext.nFrame = 17;
            TEXTURE_CelDrawColor(&tContext, gnPanelOffsetX + 0xDF, gnScreenHeight + gnPanelOffsetY - 0x40, -1, 5, 2);
        }

        int nFrame = 10;
        if (gbTradeCancelClicked == 1)
        {
            nFrame = 11;
        }
        tContext.nFrame = nFrame;
        TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x113, gnScreenHeight + gnPanelOffsetY - 0x40, -1, 5, 0);

        const unsigned char nOldTab = gnSelectedTab;
        gnSelectedTab = 1;
        INV_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
        gnSelectedTab = 2;
        INV_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
        gnSelectedTab = nOldTab;
        D2Win_10127_SetFont(1);

        Unicode wszName[0x17];
        D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
        if (pUnit)
        {
            const char* szName = ROSTER_GetUnitName(pUnit);
            if (szName)
            {
                Unicode::win2Unicode(wszName, szName, 0x17);
            }
        }

        Unicode wszText[0x17];
        sub_005267E0(wszText, MONSTER_GetTradePartnerName());
        int nLength = sub_00526800(wszText);
        while (D2Win_10121_GetTextWidth(wszText) > 0x70)
        {
            wszText[nLength].wChar = 0;
            --nLength;
        }
        D2Win_10117_DrawText(wszText, gnPanelOffsetX + 0x19, 0x1B - gnPanelOffsetY, 0, 0);

        sub_005267E0(wszText, wszName);
        nLength = sub_00526800(wszText);
        while (D2Win_10121_GetTextWidth(wszText) > 0x70)
        {
            wszText[nLength].wChar = 0;
            --nLength;
        }
        D2Win_10117_DrawText(wszText, gnPanelOffsetX + 0x19, 0xF2 - gnPanelOffsetY, 0, 0);

        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x8A7), gnPanelOffsetX - D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0x8A7)) / 2 + 0xBB, 0x1B - gnPanelOffsetY, 0, 0);

        Unicode wszNumber[0x0F];
        int aNumber[4];
        char* szNumber = (char*)aNumber;
        SStrPrintf(szNumber, 0x0F, "%d", MONSTER_GetSecondaryTradeGold());
        Unicode::win2Unicode(wszNumber, szNumber, 0x0F);
        D2Win_10117_DrawText(wszNumber, gnPanelOffsetX - D2Win_10121_GetTextWidth(wszNumber) + 0x124, 0x1B - gnPanelOffsetY, 0, 0);

        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x8A7), gnPanelOffsetX - D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0x8A7)) / 2 + 0xBB, 0xF2 - gnPanelOffsetY, 0, 0);

        SStrPrintf(szNumber, 0x0F, "%d", MONSTER_GetPrimaryTradeGold());
        Unicode::win2Unicode(wszNumber, szNumber, 0x0F);
        D2Win_10117_DrawText(wszNumber, gnPanelOffsetX - D2Win_10121_GetTextWidth(wszNumber) + 0x124, 0xF2 - gnPanelOffsetY, 0, 0);
    }

    const unsigned char nOldTab = gnSelectedTab;
    gnSelectedTab = 0;
    INV_DrawUnitInventory(sub_00463DD0_GetPlayerUnit());
    gnSelectedTab = nOldTab;

    INV_DrawEquippedItems();
    if (gnInvPanelMode >= 1 && gnInvPanelMode <= 9)
    {
        INV_DrawButtonHoverText();
    }
    INV_DrawGold(1);

    tContext.pCellFile = GAME_GetBuySellButtonCells();
    tContext.nFrame = (gbPanelButtonDown != 0) + 10;
    TEXTURE_CelDraw(&tContext, gnScreenWidth - gnPanelOffsetX - 0x12E, gnScreenHeight + gnPanelOffsetY - 0x40, -1, 5, 0);

    D2UnitStrc* pPanelUnit = sub_00463DD0_GetPlayerUnit();
    int bOther = 0;
    if (gnInvPanelMode >= 1 && gnInvPanelMode <= 9 && nMouseX < gnScreenWidth / 2)
    {
        int nUnitId;
        if (NPCMENU_GetInteractNpcId(&nUnitId))
        {
            D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
            if (pUnit)
            {
                pPanelUnit = pUnit;
                bOther = 1;
            }
        }
    }
    INV_DrawItemTooltip(pPanelUnit, bOther);
}

static __declspec(noinline) int INV_IsInTradeGrid(int nX, int nY)
{
    if (nX > gnGlobal_007BCA34 && nX < gnGlobal_007BCA38 && nY >= gnGlobal_007BCA3C && nY <= gnGlobal_007BCA40)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return 0;
    }
    if (nY >= gnScreenHeight + gnPanelY_007A285C - 0x57 && nY <= gnScreenHeight + gnPanelY_007A285C - 0x45
        && nX >= gnScreenWidth - gnPanelX_007A2858 - 0xED && nX <= gnScreenWidth - gnPanelX_007A2858 - 0xD9)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverTradeButtonLeft(int nX, int nY)
{
    if (nX > gnPanelX_007A2858 + 0xDF && nX < gnPanelX_007A2858 + 0xFF
        && nY > gnScreenHeight + gnPanelY_007A285C - 0x60 && nY < gnScreenHeight + gnPanelY_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverTradeButtonRight(int nX, int nY)
{
    if (nX > gnPanelX_007A2858 + 0x113 && nX < gnPanelX_007A2858 + 0x133
        && nY > gnScreenHeight + gnPanelY_007A285C - 0x60 && nY < gnScreenHeight + gnPanelY_007A285C - 0x40)
    {
        return 1;
    }
    return 0;
}



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


// 0x004922A0
int __stdcall WARDENCLIENT_HandlePanelAreaClick(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
    {
        INV_HandlePanelClick(pMsg);
        return 1;
    }
    return 0;
}

// 0x00492310
void __stdcall INV_OnStashButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnGlobal_007BCBF0 != 0xB)
        return;
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && INV_IsInNpcPanelRect(nX, nY))
    {
        gnGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
        return;
    if ((nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4
        && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
        || INV_IsInTradeGrid(nX, nY))
    {
        INV_HandlePanelClick(pMsg);
        return;
    }
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        gbTradeAcceptButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbTradeCancelClicked = 0;
        sub_004B90B0_SendState();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverTradeButtonLeft(nX, nY))
    {
        gbTradeAcceptButtonDown = 1;
        if (gbTradeAccepted == 1)
        {
            gbTradeAccepted = 0;
            sub_004B90B0_SendState();
        }
        else
        {
            gbTradeAccepted = 1;
            gbPanelButtonClicked = 1;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverTradeButtonRight(nX, nY))
    {
        gbTradeCancelButtonDown = 1;
        gbTradeCancelClicked = 1;
        gbPanelButtonClicked = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverGoldButton(nX, nY))
    {
        gbInvGoldButtonDown = 1;
        gbTradeAcceptButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbTradeCancelClicked = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
    }
    else if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbTradeCancelClicked = 0;
        gbTradeAcceptButtonDown = 0;
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gbTradeCancelButtonDown = 0;
    gbTradeAcceptButtonDown = 0;
}

static void INV_DrawMercStats(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    const int nOldFont = D2Win_10127_SetFont(0);
    for (unsigned int i = 0; i < 12; ++i)
    {
        int nColor = 0;
        Unicode wszText[0x80];
        char szText[0x80];
        for (int k = 0; k < 0x80; k++)
            wszText[k].wChar = 0;
        int nValue = STATLIST_UnitGetStatValue(pUnit, gaMercStatLines[i].nStatId, 0);
        const int nBase = STATLIST_GetUnitBaseStat(pUnit, gaMercStatLines[i].nStatId, 0);
        if (nValue > nBase)
        {
            nColor = 3;
        }
        else if (nValue < nBase)
        {
            nColor = 1;
        }

        const int nLeft = gaMercStatLines[i].nLeft + gnPanelX_007A2858;
        const int nRight = gaMercStatLines[i].nRight + gnPanelX_007A2858;
        int nY = gaMercStatLines[i].nY - gnPanelY_007A285C - 2;

        switch (gaMercStatLines[i].nStatId)
        {
        case 6:
        {
            const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
            int nLife = ROSTER_GetPetLife(GAME_GetUnitGUID(pUnit)) * nMaxLife / 100;
            if (!CUNIT_IsDeadOrDying(pUnit) && nLife < 0)
            {
                nLife = 1;
            }
            SStrPrintf(szText, 0x80, "%d / %d", nLife, nMaxLife);
            sub_00526320_ToUnicode(wszText, szText, 0x80);
            if ((STATLIST_GetUnitBaseStat(pUnit, STAT_MAXHP, 0) >> 8) < nMaxLife)
            {
                nColor = 3;
            }
            break;
        }
        case 0x15:
        {
            D2UnitStrc* pWeapon = 0;
            int nFlat = 0;
            int nPercent = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
            const int nMinPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
            const int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
            if (nMinPercent + nPercent > 0)
            {
                nColor = 3;
            }
            else if (nMinPercent + nPercent < 0)
            {
                nColor = 1;
            }

            if (pUnit->pInventory)
            {
                pWeapon = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, 4);
            }

            int nMaxDamage = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
            if (pWeapon)
            {
                if (ITEMS_CheckWeaponIfTwoHanded(pWeapon))
                {
                    nValue -= STATLIST_UnitGetStatValue(pWeapon, STAT_MINDAMAGE, 0);
                    nMaxDamage -= STATLIST_UnitGetStatValue(pWeapon, STAT_MAXDAMAGE, 0);
                    nValue += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
                    nMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
                }

                nFlat = ITEMS_GetStrengthBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) * nFlat / 100;
                }

                nFlat = ITEMS_GetDexBonus(pWeapon);
                if (nFlat)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) * nFlat / 100;
                }

                nPercent += SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, 0, 1);
                nFlat = STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_NORMALDAMAGE, 0);
            }
            else
            {
                if (GAME_GetUnitClassId(pUnit) == 0x10F)
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0);
                }
                else
                {
                    nPercent += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
                }
            }

            if (nPercent <= -90)
            {
                nPercent = -90;
            }

            int nMin = (nMinPercent + nPercent + 100) * nValue / 100 + nFlat;
            int nMax = (nMaxPercent + nPercent + 100) * nMaxDamage / 100 + nFlat;

            const D2ElemDamageStrc aElem[4] =
            {
                { 0x30, 0x31, 1 },
                { 0x32, 0x33, 9 },
                { 0x34, 0x35, 3 },
                { 0x36, 0x37, 3 },
            };
            for (int k = 0; k < 4; ++k)
            {
                nValue = STATLIST_UnitGetStatValue(pUnit, aElem[k].nMinStat, 0);
                const int nElemMax = STATLIST_UnitGetStatValue(pUnit, aElem[k].f_4, 0);
                if (nValue || nElemMax)
                {
                    nColor = aElem[k].nColor;
                }
                nMin += nValue;
                nMax += nElemMax;
            }

            nValue = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
            nFlat = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
            if (nValue || nFlat)
            {
                int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
                if (nLength <= 0)
                {
                    int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
                    if (nCount < 1)
                    {
                        nCount = 1;
                    }
                    nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
                }
                nMin += (nLength * nValue) >> 8;
                nColor = 2;
                nMax += (nLength * nFlat) >> 8;
            }

            SStrPrintf(szText, 0x80, "%d-%d", nMin, nMax);
            sub_00526320_ToUnicode(wszText, szText, 0x80);
            break;
        }
        case 0x1F:
        {
            const int nDefense = UNITS_GetDefense(pUnit);
            if (STATES_CheckStateMaskArmBlueOnUnit(pUnit))
            {
                nColor = 3;
            }
            D2LANG_FormatInt(wszText, nDefense, 0x80);
            break;
        }
        case 0x27:
        case 0x29:
        case 0x2B:
        case 0x2D:
        {
            D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(GAME_GetDifficulty());
            int nMaxResist = 0;
            switch (gaMercStatLines[i].nStatId)
            {
            case 0x27:
                if (STATES_CheckStateMaskRFBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRFRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXFIRERESIST, 0);
                break;
            case 0x29:
                if (STATES_CheckStateMaskRLBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRLRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXLIGHTRESIST, 0);
                break;
            case 0x2B:
                if (STATES_CheckStateMaskRCBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRCRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXCOLDRESIST, 0);
                break;
            case 0x2D:
                if (STATES_CheckStateMaskRPBlueOnUnit(pUnit))
                {
                    nColor = 3;
                }
                if (STATES_CheckStateMaskRPRedOnUnit(pUnit))
                {
                    nColor = 1;
                }
                nMaxResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAXPOISONRESIST, 0);
                break;
            }

            if (GAME_IsExpansion())
            {
                nValue += pDifficulty->dwResistPenalty;
            }
            else
            {
                switch (GAME_GetDifficulty())
                {
                case 1:
                    nValue -= 20;
                    break;
                case 2:
                    nValue -= 50;
                    break;
                }
            }

            nMaxResist = D2_MIN(nMaxResist + 75, 95);
            nValue = D2_MIN(D2_MAX(nValue, -100), nMaxResist);
            if (nValue >= nMaxResist)
            {
                nValue = nMaxResist;
                nColor = 4;
            }
            else if (nValue < 0)
            {
                nColor = 1;
            }
            D2LANG_FormatInt(wszText, nValue, 0x80);
            break;
        }
        default:
            D2LANG_FormatInt(wszText, nValue, 0x80);
            break;
        }

        D2Win_10127_SetFont(0);
        int nWidth = 0;
        int nHeight = 0;
        D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
        if (gaMercStatLines[i].nMaxWidth && nWidth > gaMercStatLines[i].nMaxWidth)
        {
            D2Win_10127_SetFont(6);
            ++nY;
        }

        if (!gaMercStatLines[i].nLeft)
        {
            D2Win_10117_DrawText(wszText, nRight - D2Win_10121_GetTextWidth(wszText), nY, nColor, 0);
        }
        else if (!gaMercStatLines[i].nRight)
        {
            D2Win_10117_DrawText(wszText, nLeft, nY, nColor, 0);
        }
        else
        {
            TEXT_DrawCenteredText(nLeft, nY, nRight, wszText, nColor);
        }
    }
    D2Win_10127_SetFont(nOldFont);
}

// build: symbol ?INV_DrawUnitEquippedItems@* 0x0048B540
static void INV_DrawUnitEquippedItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    for (int i = 0; i < 11; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem)
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            const int nX = gaBodyLocRects[i].nLeft
                + (gaBodyLocRects[i].nWidth - nWidth * gtHirelingInvGrid.nGridBoxWidth) / 2;
            const int nY = gaBodyLocRects[i].nTop
                + (gaBodyLocRects[i].nHeight - nHeight * gtHirelingInvGrid.nGridBoxWidth) / 2;
            GFX_DrawItemCel(pItem, nX, nY);
            if (gpHoverItem == pItem && ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0
                && ITEMS_CheckItemFlag(pItem, 0x800, 0x30C8, ".\\UI\\inv.cpp"))
            {
                INV_DrawItemSockets(pItem, &gtHirelingInvGrid, nX, nY);
            }
        }
    }
}

// 0x004929F0
void __cdecl INV_DrawMercPanel()
{
    if (!GAME_IsExpansion())
    {
        return;
    }

    const int nPetId = ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if ((unsigned int)nPetId == 0xFFFFFFFF)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pMerc = CUNIT_FindClientUnit(nPetId, 1);
    if (!pMerc)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    INV_LoadUiRecords();

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpMercPanelCells_007BCE88;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858, gnScreenHeight + gnPanelY_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 1;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858 + 0x100, gnScreenHeight + gnPanelY_007A285C - 0xE0, -1, 5, 0);
    tContext.nFrame = 2;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858, gnScreenHeight + gnPanelY_007A285C - 0x30, -1, 5, 0);
    tContext.nFrame = 3;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858 + 0x100, gnScreenHeight + gnPanelY_007A285C - 0x30, -1, 5, 0);

    tContext.pCellFile = GAME_GetBuySellButtonCells();
    tContext.nFrame = (gbBuySellPressed_007BCEA0 != 0) + 10;
    TEXTURE_CelDraw(&tContext, gnPanelX_007A2858 + 0x110, gnScreenHeight + gnPanelY_007A285C - 0x3F, -1, 5, 0);

    INV_DrawUnitName(pMerc);
    INV_DrawPanelLabels();
    INV_DrawMercStats(pMerc);
    sub_0048B0A0(pMerc);
    INV_DrawUnitEquippedItems(pMerc);
    INV_DrawMercEquipHighlights(pMerc);
    INV_DrawItemTooltip(pMerc, 0);
}

#include "gen/data/Source/D2Client/UI/inv_0048DD90.inc"
