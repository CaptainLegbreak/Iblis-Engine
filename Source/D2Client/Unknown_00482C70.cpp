#include "D2LanguageNames.h"
#include "D2ClientUi.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2StormTypes.h"
#include "D2ClientTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Primitives.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Win32Types.h"
#include "D2ItemTypes.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
#include "D2CelContext.h"
#include "D2Path.h"
#include "D2TxtItems.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2SetsTxt.h"
#include "D2MsgRecord.h"
#include "D2ClientUiRecords.h"
#include "D2Packets.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi.h"

#include <D2UnitData.h>
#include "StormApi.h"
#include "D2GfxApi.h"
#include "D2WinApi.h"
#include "FogApi2.h"
#include "D2WinApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct D2CelFileStrc;

struct Unicode;

struct D2MonsterDataStrc;

struct D2ClientNotifyStrc;

struct D2ItemStatCostTxt;


struct D2StaticPathStrc;

struct D2InventoryGridInfoStrc;

struct SMSGHANDLER_PARAMS;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2ItemsTxt;

struct D2AuxLevelEntryStrc;

struct D2UnitGfxDataStrc;



extern int gbRightClickConsumed; // 0x007A0670

extern int gbPopupDismissed; // 0x007A5254


extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09



void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290








D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10







void __cdecl sub_0048A730(); // 0x0048A730


void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg); // 0x004A1770


void __fastcall sub_004DC2B0(void* pResource); // 0x004DC2B0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0



void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280


extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gbGameServerReady; // 0x007A0618


extern int gbLeavingGame; // 0x007A0620



extern int gdwGlobal_007BB5DC; // 0x007BB5DC

extern unsigned char gnGlobal_007BB5E0; // 0x007BB5E0


extern int gnRecipeScrollColor; // 0x007BCEA4



extern int gdwGlobal_007BF23F; // 0x007BF23F




extern unsigned char gaTable_007C0EA4[]; // 0x007C0EA4

extern int gbQuestIntroFlagsReady; // 0x007C0ECC


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910


int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

void __stdcall sub_Z12_EmitUse(int nMin, int nMax, int bModified);

void __stdcall sub_Z12_EmitUse1(int nValue);

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260





void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall sub_00480930(int nType, int nUnitId); // 0x00480930

void __cdecl sub_004B90B0(); // 0x004B90B0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00


extern int gnStashObjectId; // 0x00721E54

extern int gnButtonCount; // 0x00722160






extern "C" { int gbTradeFlag; } // 0x007BCE28


extern void* gpCel_007BCE8C; // 0x007BCE8C


extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78

extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40

extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88


void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3); // 0x004786D0


void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt); // 0x0049FF90


int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall sub_0062A0A0(D2UnitStrc* pItem); // 0x0062A0A0




int __fastcall NPCMENU_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

void __cdecl sub_K04_EmitUse(int nValue);



extern "C" unsigned int gValue_007A065C;

extern "C" unsigned int gValue_007A0660;

extern "C" unsigned int gValue_007A0664;

extern "C" unsigned int gValue_007A6ABC;

extern "C" unsigned int gValue_007A6ADC;

extern "C" unsigned int gValue_007A6AE0;

extern "C" unsigned int gValue_007A6AF0;

extern "C" unsigned int gValue_00712F44;

extern "C" unsigned int gValue_00712F48;

extern "C" unsigned int gValue_007BB5D8;

extern "C" unsigned int gValue_007BB5E8;

extern "C" unsigned int gValue_007BCBF0; // 0x007BCBF0

extern "C" unsigned int gValue_007BCE2C; // 0x007BCE2C

extern "C" unsigned short gValue_007BB5E4;

extern "C" const unsigned char gColorTable_00971740[];




extern unsigned char gColor;

extern int gScreenHeight;

extern int gScreenWidth;

extern unsigned int gUiState; // 0x007BCBF0

extern void* gResourceA;

extern void* gResourceB;

void __cdecl InitializePalette();

int __stdcall ReleaseResource(void* resource);

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0





void __stdcall sub_Z12_EmitUse2(int nValue1, int nValue2);



void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

extern D2InvCompGridStrc gaBodyLocRects[11]; // 0x007BCD38



void __stdcall sub_00467FA0(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0




extern "C" int gnLightmapRenderMode; // 0x00712CCC

extern "C" int gbSkillPointsHighlight; // 0x007C0C3C

extern "C" unsigned char gbFlag_007BC9D4; // 0x007BC9D4

extern "C" unsigned char gbFlag_007BC9D8; // 0x007BC9D8

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __stdcall sub_00483E40(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40


int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

typedef void (__fastcall *UnitCallback)(D2UnitStrc*);

extern unsigned int gSelectionState; // 0x007BCC50

extern unsigned char gPaletteA;

extern unsigned char gPaletteB;

extern unsigned char gPaletteC;

extern unsigned char gPaletteD;

void __fastcall CUNIT_ForEachObject(UnitCallback callback); // 0x004649D0

void __fastcall sub_00489DA0(D2UnitStrc* unit); // 0x00489DA0

unsigned int __stdcall PaletteColor(unsigned int red, unsigned int green, unsigned int blue);

void __fastcall sub_00478600(unsigned char command, unsigned short value, unsigned int word2, unsigned int word3); // 0x00478600

static void INV_DrawUnitEquippedItems(D2UnitStrc* pUnit); // 0x0048B540

struct D2AuxLevelEntryStrc
{
    int nType;
    const char* szFile;
    char bLocalized;
    char bFormat;
    char unk0x0A[2];
};

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

int __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20



extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern D2AuxLevelEntryStrc gaAuxLevelEntries[]; // 0x00721D98

static void __stdcall INV_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified);

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall sub_004521C0_SetTextColor(Unicode* pText, int nColor); // 0x004521C0




int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80







extern D2CelFileStrc* gpGoldButtonCel_007BCC34; // 0x007BCC34

extern int gbGoldButtonDown_007BCE30; // 0x007BCE30

extern int gbGoldButtonDown_007BCE34; // 0x007BCE34

extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC

static int __stdcall INV_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight); // 0x00486820



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" size_t __cdecl strlen(const char* szString);


Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern); // 0x00526940



void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60

int __fastcall sub_004A7660_SplitAtNewLine(Unicode* wszText, Unicode** ppSecond); // 0x004A7660


const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB); // 0x0046A530

extern D2CelFileStrc* gpBankCel; // 0x007BCC2C

extern D2CelFileStrc* gpTradeStashCel; // 0x007BCC3C

extern D2CelFileStrc* gpSuperTransmogrifierCel; // 0x007BCC30

extern D2PanelLabelStrc gaPanelLabels[12]; // 0x006D9AE8

extern void* gpBtnCel; // 0x007BEF7C

extern void* gpCellFile_007BEF78; // 0x007BEF78

extern void* gpCellFile_007BEF10; // 0x007BEF10

extern void* gpCellFile_007BEF2C; // 0x007BEF2C

extern void* gpCellFile_007BEF20; // 0x007BEF20

extern D2HirelingIconRecordStrc* gpHirelingRecords_007BEEAC; // 0x007BEEAC




void __fastcall SOUNDHDR_ReleaseCacheEntry(int nId);                                                    // 0x004823E0

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg);                                          // 0x004873A0




int __fastcall sub_004DF9D0_CheckCacheEntry(int nId);                                                       // 0x004DF9D0

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480




void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90



extern int gnCacheEntries_007BC9A4;                                                                         // 0x007BC9A4

extern D2ClientCacheNodeStrc* gpCacheList;                                                         // 0x007BC9B8


extern unsigned int gdwCacheUsed;                                                                  // 0x007BC9D0

#define gnGlobal_007BCAA0 (gtPlayerInvRect.nLeft)

#define gnGlobal_007BCAA4 (gtPlayerInvRect.nRight)

#define gnGlobal_007BCAA8 (gtPlayerInvRect.nTop)

#define gnGlobal_007BCAAC (gtPlayerInvRect.nBottom)

#define gnGlobal_007BCA34 (gtTradePage2Grid.nGridLeft)

#define gnGlobal_007BCA38 (gtTradePage2Grid.nGridRight)

#define gnGlobal_007BCA3C (gtTradePage2Grid.nGridTop)

#define gnGlobal_007BCA40 (gtTradePage2Grid.nGridBottom)


#define gnGlobal_007BCB74 (gtCubeGrid.nGridLeft)

#define gnGlobal_007BCB78 (gtCubeGrid.nGridRight)

#define gnGlobal_007BCB7C (gtCubeGrid.nGridTop)

#define gnGlobal_007BCB80 (gtCubeGrid.nGridBottom)




#define gnGlobal_007BCA68 (gtBankRect.nLeft)

#define gnGlobal_007BCA6C (gtBankRect.nRight)

#define gnGlobal_007BCA74 (gtBankRect.nBottom)

#define gnGlobal_007BCA7C (gtBigBankGrid.nGridLeft)

#define gnGlobal_007BCA80 (gtBigBankGrid.nGridRight)

#define gnGlobal_007BCA84 (gtBigBankGrid.nGridTop)

#define gnGlobal_007BCA88 (gtBigBankGrid.nGridBottom)

#define gnGlobal_007BCAF4 (gtBigBankRect.nLeft)

#define gnGlobal_007BCAF8 (gtBigBankRect.nRight)

#define gnGlobal_007BCB00 (gtBigBankRect.nBottom)

#define gnGlobal_007BCB44 (gtBankGrid.nGridLeft)

#define gnGlobal_007BCB48 (gtBankGrid.nGridRight)

#define gnGlobal_007BCB4C (gtBankGrid.nGridTop)

#define gnGlobal_007BCB50 (gtBankGrid.nGridBottom)

struct D2InvRectStrc;

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258







char gbCinematicStop; // 0x007BC9D4

char gbCinematicWide; // 0x007BC9D6

char gbCinematicBusy; // 0x007BC9D7

char gbCinematicChain; // 0x007BC9D8

static unsigned char INV_GetFlagIndex(unsigned char nFlags);

extern D2InvRectStrc gtBankRect; // 0x007BCA68

extern D2InvRectStrc gtBigBankRect; // 0x007BCAF4


#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2SetItemsTxt;

struct D2InvCompGridStrc;

extern const D2CoordStrc gSocketLayouts[][6]; // 0x006D91E8








void __fastcall sub_004B9070(int nArg); // 0x004B9070




int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

void __stdcall INV_DrawItemSockets(D2UnitStrc* item, D2InventoryGridInfoStrc* grid, int x, int y); // 0x00483E40

void __fastcall SKILLDESC_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6850

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

int __stdcall sub_0063B9D0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, int* pOutX, int* pOutY, unsigned char nPage); // 0x0063B9D0


extern "C" const char gszCmnItemsH[]; // 0x006D9B90

extern "C" const char gszInvCpp[]; // 0x006D9BC0

extern int gnDialogState; // 0x00721E34

extern unsigned char gabInvHighlightColors[5]; // 0x007BCAD8

extern D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58





static void __stdcall INV_GetPlacementCell(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY);


static void INV_SetBuyButton(int nButton); // 0x00487E20

static void INV_SetSellButton(int nButton); // 0x00487E60

static void INV_ClearButton(int nButton); // 0x00487EA0

extern D2CelFileStrc* gpTorsoCell_007BCE68; // 0x007BCE68

extern D2CelFileStrc* gpHeadCell_007BCE74; // 0x007BCE74

extern D2CelFileStrc* gpArmCell_007BCE7C; // 0x007BCE7C

extern int gnRectHeadLeft; // 0x007BCD4C

extern int gnRectHeadBottom; // 0x007BCD58

extern int gnRectTorsoLeft; // 0x007BCD74

extern int gnRectTorsoBottom; // 0x007BCD80

extern int gnRectRArmLeft; // 0x007BCD88

extern int gnRectRArmBottom; // 0x007BCD94

extern int gnRectLArmLeft; // 0x007BCD9C

extern int gnRectLArmBottom; // 0x007BCDA8

extern D2CoordStrc gtOffsetTorso; // 0x007220B0
extern D2CoordStrc gtOffsetHead; // 0x007220C8
extern D2CoordStrc gtOffsetRArm; // 0x007220F0
extern D2CoordStrc gtOffsetLArm; // 0x007220F8









void __cdecl sub_004972B0_InitializePalette(); // 0x004972B0









extern char gszClientCharName[];                                                                         // 0x007A05C4

void INV_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor); // 0x00483A70


int __cdecl INV_GetPanelY(); // 0x00486B00


void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg); // 0x00486E60




void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId); // 0x004844A0

int __cdecl sub_E05_Emit_00486860(); // 0x00486860

int __cdecl sub_E05_Emit_00489FB0(int nX, int nY); // 0x00489FB0






















void __cdecl INV_SetupPanelButtons(); // 0x00487ED0

























extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __stdcall sub_00403040_ConstructVector(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnCtor)(void*)); // 0x00403040

void __fastcall NPCMENU_ClearUnicode(void* pChar);                                                     // 0x0042F530


D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

Unicode* __fastcall sub_00452170_ReturnText(Unicode* pText);                                                           // 0x00452170



const Unicode* __fastcall INV_SkipBracketTag(const Unicode* pString); // 0x004834A0

void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...); // 0x0048BE80



int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70


unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffix);                                 // 0x00627F80

unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem);                                          // 0x00627FE0

unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem);                                          // 0x00628040


unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0




int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

extern int gbHoverPlayerItem; // 0x00721E38

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey);










void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_GetSockets(D2UnitStrc* hItem); // 0x006299B0






int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0




static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0

static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage);

extern D2InvRectStrc gtPlayerInvRect;                                                                            // 0x007BCAA0

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

extern D2InventoryGridInfoStrc gtTradePage2Grid;        // 0x007BCA30

extern D2InventoryGridInfoStrc gtCubeGrid;        // 0x007BCB70








void __cdecl sub_0048A730_SwapWeapons(); // 0x0048A730

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

typedef int (__fastcall *D2BodyClickFn)(D2UnitStrc*,D2InventoryStrc*,int);

extern D2BodyClickFn gaBodyClick[]; // 0x00721E58

static void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight, int nColor); // 0x004839D0


static int INV_IsOverWeaponSwapTab(int nX, int nY); // 0x00486860

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0

static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX); // 0x00486E60


int __stdcall sub_0062C0B0_GetItemTypeClass(D2UnitStrc* pItem);

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0



void __stdcall INV_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid); // 0x00487000


Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit);   // 0x004521C0




enum D2C_UIvars
{
    UI_GAME = 0x00,
    UI_INVENTORY = 0x01,
    UI_STATSCREEN = 0x02,
    UI_MINISKILL = 0x03,
    UI_SKILLTREE = 0x04,
    UI_CHATBOX = 0x05,
    UI_NEWSTATS = 0x06,
    UI_NEWSKILLS = 0x07,
    UI_NPCMENU = 0x08,
    UI_ESCMENU = 0x09,
    UI_AUTOMAP = 0x0A,
    UI_CONFIG = 0x0B,
    UI_NPCSHOP = 0x0C,
    UI_HOLDALT = 0x0D,
    UI_ANVIL = 0x0E,
    UI_QUESTSCREEN = 0x0F,
    UI_INISCROLL = 0x10,
    UI_QUESTLOG = 0x11,
    UI_UNKNOWN18 = 0x12,
    UI_HIRICONS = 0x13,
    UI_WAYPOINT = 0x14,
    UI_MINIPANEL = 0x15,
    UI_PARTYSCREEN = 0x16,
    UI_MPTRADE = 0x17,
    UI_MSGLOG = 0x18,
    UI_STASH = 0x19,
    UI_CUBE = 0x1A,
    UI_STEEGSTONE = 0x1B,
    UI_GUILDVAULT = 0x1C,
    UI_UNKNOWN29 = 0x1D,
    UI_UNKNOWN30 = 0x1E,
    UI_BELTROWS = 0x1F,
    UI_UNKNOWN32 = 0x20,
    UI_HELPSCREEN = 0x21,
    UI_HELPBUTTON = 0x22,
    UI_HIREICONS = 0x23,
    UI_MERCINV = 0x24,
    UI_RECIPESCROLL = 0x25
};

enum DrawMode
{
    DRAWMODE_TRANS25,
    DRAWMODE_TRANS50,
    DRAWMODE_TRANS75,
    DRAWMODE_MODULATE,
    DRAWMODE_BURN,
    DRAWMODE_NORMAL,
    DRAWMODE_TRANSHIGHLIGHT,
    DRAWMODE_HIGHLIGHT
};

extern struct D2CelFileStrc* gpRecipeScrollCel;                                                  // 0x007BCE8C

static int INV_IsUnusableQuestBook(D2ItemsTxt* pItemsTxt); // 0x00483F80

void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg); // 0x00486EF0

static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory);

void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004889D0

static void INV_SelectButtonByKey(int nKey);

static int INV_IsOverTradeButtonLeft(int nX, int nY);

static int INV_IsOverTradeButtonRight(int nX, int nY);

void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489580

static int INV_IsOverCloseButton(int nX, int nY); // 0x00489920

static int INV_IsOverTransmuteButton(int nX, int nY); // 0x00489980

void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489A30

void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489AC0

static int INV_IsOverButtonC(int nX, int nY); // 0x00489FB0

static void INV_AppendBookCharges(Unicode* pText);

static D2UnitStrc* INV_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId); // 0x00486770

static void __stdcall INV_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem); // 0x00483C50

static void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory);

void __stdcall INV_DrawUnitInventory(D2UnitStrc* pUnit); // 0x00483FF0

void __stdcall INV_TradeMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004894D0

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C






void __cdecl sub_00477DD0(); // 0x00477DD0






extern "C" const char gszRes640x146[]; // 0x006D4214

extern "C" const char gszRes640x292[]; // 0x006D421C

extern int gnAuxLevelEntries; // 0x00721D94


char gbCinematicPlaying; // 0x007BC9D5

extern int gnAutomapHeight; // 0x007A521C


struct D2CharStatsTxt;



struct D2DifficultyLevelsTxt;

struct D2MercStatLineStrc;

struct D2ElemDamageStrc;

struct D2SetsTxt;

extern int gbWeaponSwitch; // 0x007BCC4C








extern D2SpeedNameStrc gaSpeedNames[6]; // 0x00721E88

extern D2ItemTypeNameStrc gaItemTypeNames[15]; // 0x00721EB0

extern int gaSpeedTable[][5]; // 0x00721F10

extern int gaClassSpeedOffsets[][2]; // 0x00722078


int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60










int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

extern D2MercStatLineStrc gaMercStatLines[12]; // 0x007221A8

static void INV_DrawMercStats(D2UnitStrc* pUnit); // 0x0048A990


int __stdcall sub_00485410_AppendDamage(D2UnitStrc* pItem, Unicode* pText); // 0x00485410

void __stdcall INV_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText); // 0x00485EE0

void __fastcall SKILLDESC_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra); // 0x004E6410

void __fastcall WARDENCLIENT_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6560

void __fastcall MISSILE_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6680







int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

#define gnGlobal_007BCB5C (gtNpcInvGrid.nGridLeft)

#define gnGlobal_007BCB60 (gtNpcInvGrid.nGridRight)

#define gnGlobal_007BCB64 (gtNpcInvGrid.nGridTop)

#define gnGlobal_007BCB68 (gtNpcInvGrid.nGridBottom)

void __stdcall INV_GridClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004917C0











void __stdcall sub_0065C180_2(int nInventoryTxtId, int bHigherRes, D2InvRectStrc* pInvRect); // 0x0065C180

void __stdcall sub_0065C1F0_2(int nInventoryTxtId, int bHigherRes, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0

void __stdcall sub_0065C270_2(int nInventoryTxtId, int bHigherRes, D2InvCompGridStrc* pInvCompGrid, int nComponent); // 0x0065C270


void __stdcall INV_DrawRecipeScroll(); // 0x0048BC10

static void __stdcall INV_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText);

static int __stdcall INV_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage);

static int INV_IsInStashRect(int nX, int nY); // 0x00483B40

static int INV_IsInCubeRect(int nX, int nY); // 0x00483BF0





extern "C" { int gnFlag_007C02EC; } // 0x007C02EC




















// 0x00482C70
static unsigned char INV_GetFlagIndex(unsigned char nFlags)
{
    if (nFlags & 0x01)
        return 7;
    if (nFlags & 0x80)
        return 6;
    if (nFlags & 0x10)
        return 5;
    if (nFlags & 0x08)
        return 4;
    if (nFlags & 0x40)
        return 3;
    if (nFlags & 0x04)
        return 2;
    return 1;
}

int __fastcall sub_00482C70_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += INV_GetFlagIndex(pFlags[i]);
    return nSum;
}

// 0x00482CA0
void __fastcall INV_UpdateAuxBattleNetAddress(int nIndex)
{
    const int nType = gaAuxLevelEntries[nIndex].nType;
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d = 0x22;
    unsigned char nLevel;
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        sscanf(szAddress, "%d.%d.%d.%d", &a, &b, &c, &d);
        const unsigned char nLow = d;
        if (nLow & 1)
            nLevel = 7;
        else if (nLow & 0x80)
            nLevel = 6;
        else if (nLow & 0x10)
            nLevel = 5;
        else if (nLow & 0x08)
            nLevel = 4;
        else if (nLow & 0x40)
            nLevel = 3;
        else
            nLevel = (nLow & 4) ? 2 : 1;
    }
    else
    {
        nLevel = 0x22;
    }

    unsigned char nNeeded;
    switch (nType)
    {
    case 2:
        nNeeded = 2;
        break;
    case 3:
        nNeeded = 3;
        break;
    case 4:
        nNeeded = 4;
        break;
    case 5:
    case 6:
        nNeeded = 5;
        break;
    case 7:
        nNeeded = 7;
        break;
    default:
        nNeeded = 1;
        break;
    }

    if (nNeeded > nLevel)
    {
        int nValue;
        switch (nNeeded)
        {
        case 7:
            nValue = 0x23;
            break;
        case 5:
            nValue = 0xB2;
            break;
        case 4:
            nValue = 0x2A;
            break;
        case 3:
            nValue = 0x62;
            break;
        case 2:
            nValue = 0x26;
            break;
        default:
            nValue = 0x22;
            break;
        }
        d = nValue;
        sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, d);
        SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    }
}

// 0x00482E00
static int INV_ArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    SFileCloseFile(hFile);
    return 1;
}

// 0x00482E30
static void INV_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
    STRTABLE_GetLanguageInfoField(szLang, 0);
    sprintf(szOut, szFormat, gszDataLocal, szLang, szFile);
    if (INV_ArchiveFilePresent(szOut))
        return;
    if (STRTABLE_GetLanguage())
    {
        sprintf(szOut, szFormat, gszDataLocal, "ENG", szFile);
        INV_ArchiveFilePresent(szOut);
    }
    else
    {
        sprintf(szOut, szFormat, gszDataLocal, "CHI", szFile);
        INV_ArchiveFilePresent(szOut);
    }
}

// 0x00482EF0
void __fastcall INV_PlayCinematic(int nIndex)
{
    int nMode;
    int bPlayed;
    int bLoaded;
    int bExpansion;
    char szName[0x104];
    char szFile[0x104];

    D2_ASSERT(nIndex < gnAuxLevelEntries, 0xEF);
    gbCinematicBusy = 1;
    INV_UpdateAuxBattleNetAddress(nIndex);
    if (gbCinematicPlaying)
        return;

    if (nIndex >= gnAuxLevelEntries)
    {
        MSG_SendHeaderOnly(0x48);
        gbCinematicBusy = 0;
        return;
    }

    nMode = 0;
    if (gaAuxLevelEntries[nIndex].bFormat)
    {
        if (gbCinematicWide)
        {
            sprintf(szName, gaAuxLevelEntries[nIndex].szFile, gszRes640x292);
        }
        else
        {
            nMode = 2;
            sprintf(szName, gaAuxLevelEntries[nIndex].szFile, gszRes640x146);
        }
    }
    else
    {
        strcpy(szName, gaAuxLevelEntries[nIndex].szFile);
    }

    UNITMODE_StopAllSounds();
    sub_004DCA30();
    ARCHIVE_UnloadExpansionArchives();

    bExpansion = 0;
    bPlayed = bLoaded = 0;
    if (nIndex == 7)
    {
        bExpansion = 1;
        char szPath[0x104];
        FOG_GetInstallPath(szPath, 0x104);
        strcat(szPath, "d2game.dll");
        void* hFile = CreateFileA(szPath, 0, 1, 0, 3, 0x80, 0);
        if (hFile != (void*)-1)
        {
            CloseHandle(hFile);
        }
        else
        {
            GAME_SetPlayCinematic(0);
            goto lMissing;
        }
    }
    else if (nIndex == 6)
    {
        bExpansion = 1;
    }

    PLAYER_SetCinematicExpansion(bExpansion);
    if (ARCHIVE_LoadVideoArchives(bExpansion ? (void*)sub_00460500_RunPopup : (void*)sub_00460680_RunOkCancel, 0, bExpansion))
    {
        bLoaded = 1;
        if (gaAuxLevelEntries[nIndex].bLocalized)
            INV_BuildLocalizedVideoPath(szFile, "%s\\video\\%s\\%s", szName);
        else
            sprintf(szFile, "%s\\video\\%s", gszDataGlobal, szName);

        gbCinematicPlaying = 1;
        GFXUTIL_ClearFadeTimer();
        UI_SetUIVar(0x12, 0, 0);
        if (D2Win_10003())
        {
            if (gbCinematicStop)
                WINDOW_OpenSmackCutscene(szFile, nMode, 0);
            else
                WINDOW_OpenSmackCutscene(szFile, nMode, (void*)sub_00477DD0);
            bPlayed = 1;
        }

        if (nIndex != 5 || !gbCinematicChain)
        {
            D2Win_10004(D2GFX_GetResolutionMode());
            UI_SetUIVar(0x12, 1, 0);
            gbCinematicPlaying = 0;
        }
    }

    if (gbCinematicChain)
    {
        if (bLoaded)
            ARCHIVE_UnloadExpansionArchives();
        if (bPlayed)
            D2Win_10004(D2GFX_GetResolutionMode());

        PLAYER_SetCinematicExpansion(1);
        if (ARCHIVE_LoadVideoArchives((void*)sub_00460500_RunPopup, 0, 1))
        {
            nIndex = 6;
            if (gbCinematicWide)
            {
                sprintf(szName, gaAuxLevelEntries[nIndex].szFile, gszRes640x292);
            }
            else
            {
                nMode = 2;
                sprintf(szName, gaAuxLevelEntries[nIndex].szFile, gszRes640x146);
            }

            if (gaAuxLevelEntries[nIndex].bLocalized)
                INV_BuildLocalizedVideoPath(szFile, "%s\\video\\%s\\%s", szName);
            else
                sprintf(szFile, "%s\\video\\%s", gszDataGlobal, szName);

            if (D2Win_10003())
            {
                WINDOW_OpenSmackCutscene(szFile, nMode, (void*)sub_00477DD0);
                INV_UpdateAuxBattleNetAddress(nIndex);
            }
        }

        D2Win_10004(D2GFX_GetResolutionMode());
        UI_SetUIVar(0x12, 1, 0);
        gbCinematicPlaying = 0;
        gbCinematicChain = 0;
        D2Win_10177(4);
    }

    MSG_SendHeaderOnly(0x48);
    if (gbCinematicStop)
    {
        gbCinematicStop = 0;
        GAME_ExitForCinematic();
    }
    else if (nIndex == 7)
    {
lMissing:
        GAME_SetPlayCinematic(0);
        gbCinematicStop = 0;
        GAME_SetCinematicPlayed();
        GAME_ExitForCinematic();
    }

    ARCHIVE_UnloadExpansionArchives();
    ARCHIVE_LoadExpansionArchives(sub_00460500_RunPopup, sub_004605A0_RunPopup, 0, gpClientConfig);
    gbCinematicBusy = 0;
}

// 0x00483300
extern "C" void __cdecl INV_StopCinematic()
{
    gbFlag_007BC9D4 = 1;
}

// 0x00483310
void __cdecl INV_ResetCinematicFlags()
{
    gbCinematicStop = 0;
    gbCinematicWide = !sub_0040EB10();
    gbCinematicChain = 0;
    gbCinematicBusy = 0;
}

// 0x00483340
extern "C" void __cdecl INV_ChainCinematic()
{
    gbFlag_007BC9D8 = 1;
}

// 0x00483350
unsigned char __cdecl INV_IsCinematicBusy()
{
    return gbCinematicBusy;
}





















struct D2ClientTextDataStrc;

































































extern "C" { int gRequest; } // 0x007BCC0C



















static int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}








































































struct D2SkillStrc;














struct D2InventoryStrc;


#pragma intrinsic(memset, strcpy, strcat, strlen)

#define WSZ(a) ((Unicode*)(a))

#define SZ(a) ((char*)(a))

struct D2BitBufferStrc;







static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid)
{
    D2_ASSERT(pItem, 0x14E8);
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned int nPixelWidth;
    unsigned int nPixelHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    sub_004DBEA0(pItem, 0, 0, &nPixelWidth, &nPixelHeight);
    if (nWidth % 2 == 0)
    {
        nCellX = ((nPixelWidth >> 2) - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
    }
    if (nWidth == pGrid->nGridX)
    {
        nCellX = pGrid->nGridX / 2;
    }
    if (nHeight % 2 == 0)
    {
        nCellY = ((nPixelHeight >> 2) - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
    }
    if (nHeight == pGrid->nGridY)
    {
        nCellY = pGrid->nGridY / 2;
    }
    *pOutX = nCellX;
    *pOutY = nCellY;
    if (nWidth > 1)
    {
        const int n = *pOutX - nWidth / 2;
        *pOutX = n < 0 ? 0 : n;
    }
    if (nHeight > 1)
    {
        const int n = *pOutY - nHeight / 2;
        *pOutY = n < 0 ? 0 : n;
    }
}




#define MV(x) (x)

#define PACKET(x) (x)















extern int gbHelpUiOpened;                                                                         // 0x007BEF00














extern D2SkillIconStateStrc gtHotkeySlots;                                                      // 0x007C0300

extern int gbSkillSelectRight;                                                                               // 0x007C07FC













#pragma pack(push, 1)
struct d2data_00721D98_t
{
    unsigned char b0[4];
    const void* p1;
    unsigned char b2[8];
    const void* p3;
    unsigned char b4[8];
    const void* p5;
    unsigned char b6[8];
    const void* p7;
    unsigned char b8[8];
    const void* p9;
    unsigned char b10[8];
    const void* p11;
    unsigned char b12[8];
    const void* p13;
    unsigned char b14[8];
    const void* p15;
    unsigned char b16[4];
};
#pragma pack(pop)

extern "C" struct d2data_00721D98_t gData_00721D98; // 0x00721D98

extern "C" const char gszRes640x146[8] = "640x146"; // 0x006D4214

extern "C" const char gszRes640x292[8] = "640x292"; // 0x006D421C

extern int gnAuxLevelEntries = 8; // 0x00721D94

extern "C" struct d2data_00721D98_t gData_00721D98 = {
    { 0x00 },
    (const void*)"d2_promo.bik",
    { 0x00, 0x00, 0x00, 0x00, 0x01 },
    (const void*)"d2intro%s.bik",
    { 0x01, 0x01, 0x00, 0x00, 0x02 },
    (const void*)"ACT02START%s.BIK",
    { 0x01, 0x01, 0x00, 0x00, 0x03 },
    (const void*)"ACT03START%s.BIK",
    { 0x01, 0x01, 0x00, 0x00, 0x04 },
    (const void*)"ACT04START%s.BIK",
    { 0x01, 0x01, 0x00, 0x00, 0x05 },
    (const void*)"ACT04END%s.BIK",
    { 0x01, 0x01, 0x00, 0x00, 0x06 },
    (const void*)"D2X_INTRO_%s.BIK",
    { 0x01, 0x01, 0x00, 0x00, 0x07 },
    (const void*)"D2X_OUT_%s.BIK",
    { 0x01, 0x01 }
}; // 0x00721D98
#pragma comment(linker, "/alternatename:?gaAuxLevelEntries@@3PAUD2AuxLevelEntryStrc@@A=_gData_00721D98")
