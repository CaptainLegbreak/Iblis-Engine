#include "D2LanguageNames.h"
#include "D2ClientUi.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2StormTypes.h"
#include "D2ClientTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
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

#include <D2UnitData.h>

struct D2ClientInterfaceStrc;

struct D2LowQualityItemsTxt;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct D2CelFileStrc;

struct Unicode;

struct D2MonsterDataStrc;

struct D2ClientNotifyStrc;

struct D2ClientNodeStrc;

struct D2RosterSubStrc;

struct D2RosterEntryStrc;

struct D2ClientSlotObjStrc;

struct D2ClientSlotHolderStrc;

struct D2ClientRecordStrc;

struct D2ItemStatCostTxt;


struct D2StaticPathStrc;

struct D2InventoryGridInfoStrc;

struct RangeNode;

struct LookupNode;

struct ColorView;

union PackedWord;

struct SMSGHANDLER_PARAMS;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2ItemsTxt;

struct D2AuxLevelEntryStrc;

struct D2GfxDataStrc;



extern void* ghDbgHelp; // 0x0098A680

extern int gbRightClickConsumed; // 0x007A0670

extern int gbPopupDismissed; // 0x007A5254


struct D2ClientNodeStrc
{
    char unk0x00[0x08];
    int nId;
    char unk0x0C[0x08];
    int nValueA;
    int nValueB;
    char unk0x1C[0x14];
    D2ClientNodeStrc* pNext;
};

struct D2RosterSubStrc
{
    int nUnk0x00;
    D2RosterSubStrc* pNext;
};

struct D2RosterEntryStrc
{
    char unk0x00[0x34];
    void* pResource;
    D2RosterSubStrc* pSubList;
    char unk0x3C[0x44];
    D2RosterEntryStrc* pNext;
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

struct D2ClientSlotHolderStrc
{
    char unk0x00[0x0C];
    D2ClientSlotObjStrc* pObj;
};

struct D2ClientRecordStrc
{
    unsigned char nId;
    unsigned char nType;
    unsigned char nFlag;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_5;
    unsigned char nValue3;
    unsigned char nUnk0x07;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290


void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __cdecl sub_00468F00(); // 0x00468F00

void __fastcall MSG_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600

void __cdecl WARDENCLIENT_ActivatePendingModule(); // 0x00480230

void __cdecl sub_0048A730(); // 0x0048A730

void __cdecl HIREABLES_CloseHelpUi(); // 0x00494FC0

void __fastcall sub_0049EB10_PostRecord(D2ClientRecordStrc* pRecord); // 0x0049EB10

void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg); // 0x004A1770

void __cdecl sub_004B8CB0(); // 0x004B8CB0

void __fastcall sub_004DC2B0(void* pResource); // 0x004DC2B0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

extern int gnScreenWidth; // 0x0071146C

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gbGameServerReady; // 0x007A0618

extern int gbPositionalSound; // 0x007A061C

extern int gbLeavingGame; // 0x007A0620

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern D2ClientNodeStrc* gpNodeList_007BB5BC; // 0x007BB5BC

extern D2RosterEntryStrc* gpRosterListA_007BB5C0; // 0x007BB5C0

extern int gdwGlobal_007BB5DC; // 0x007BB5DC

extern unsigned char gnGlobal_007BB5E0; // 0x007BB5E0

extern D2ClientSlotHolderStrc* gpSlotHolder; // 0x007BC990


extern int gnRecipeScrollColor; // 0x007BCEA4


extern unsigned char gbTextHoverSet; // 0x007BF23A

extern int gdwGlobal_007BF23F; // 0x007BF23F

extern int gaHotkeySkills[16]; // 0x007C06C8

extern int gaHotkeyOwners[16]; // 0x007C0768

extern int gaHotkeyLeft[16]; // 0x007C07B8

extern unsigned char gaTable_007C0EA4[]; // 0x007C0EA4

extern int gbQuestIntroFlagsReady; // 0x007C0ECC

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

void __stdcall sub_Z12_EmitUse(int nMin, int nMax, int bModified);

void __stdcall sub_Z12_EmitUse1(int nValue);

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

D2CelFileStrc* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0

int __cdecl sub_00468830(); // 0x00468830

void __fastcall MSG_SendHeaderOnly(char nValue); // 0x00478590

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall sub_00480930(int nType, int nUnitId); // 0x00480930

void __cdecl sub_004B90B0(); // 0x004B90B0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

extern int gnStashObjectId; // 0x00721E54

extern int gnButtonCount; // 0x00722160






extern "C" { int gbTradeFlag; } // 0x007BCE28


extern void* gpCel_007BCE8C; // 0x007BCE8C


extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78

extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40

extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88

void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680

void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3); // 0x004786D0

int __cdecl INV_CheckTradeClickDelay(); // 0x00486D10

void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt); // 0x0049FF90

int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pItem); // 0x004C2240

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall sub_0062A0A0(D2UnitStrc* pItem); // 0x0062A0A0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __fastcall NPCMENU_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

void __cdecl sub_K04_EmitUse(int nValue);

int __cdecl NPCMENU_IsGambleShop(); // 0x004B3500


struct RangeNode
{
    char gap00[0x204];
    unsigned int start;
    unsigned int size;
    RangeNode* next;
};

struct LookupNode
{
    char gap00[0x8];
    unsigned int key;
    char gapAfterKey[0x10];
    unsigned int value;
    char gapAfterValue[0x10];
    LookupNode* next;
};

struct ColorView
{
    char gap00[0x10];
    unsigned int color;
};

union PackedWord
{
    unsigned int word;
    struct Bytes
    {
        unsigned char low;
        unsigned char high;
        unsigned char third;
        unsigned char fourth;
    } bytes;
};

typedef char packed_word_size[sizeof(PackedWord)==4?1:-1];

typedef char packed_high_lane[OFFSET(PackedWord::Bytes,high)==1?1:-1];

typedef char RangeNode_start[OFFSET(RangeNode,start)==0x204?1:-1];

typedef char RangeNode_size[OFFSET(RangeNode,size)==0x208?1:-1];

typedef char RangeNode_next[OFFSET(RangeNode,next)==0x20C?1:-1];

typedef char LookupNode_key[OFFSET(LookupNode,key)==0x8?1:-1];

typedef char LookupNode_value[OFFSET(LookupNode,value)==0x1C?1:-1];

typedef char LookupNode_next[OFFSET(LookupNode,next)==0x30?1:-1];

typedef char ColorView_color[OFFSET(ColorView,color)==0x10?1:-1];

extern "C" LookupNode* gLookupHead_007BB5BC;

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

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

extern unsigned char gColor;

extern int gScreenHeight;

extern int gScreenWidth;

extern unsigned int gUiState; // 0x007BCBF0

extern void* gResourceA;

extern void* gResourceB;

void __cdecl InitializePalette();

void __fastcall D2GFX_DrawBox(int x, int y, int width, int height, int color, int mode); // 0x004F6300

int __stdcall ReleaseResource(void* resource);

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __fastcall ROSTERPETS_GetHirelingClassId(int nUnitId); // 0x00479120

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0

void __stdcall sub_Z12_EmitUse2(int nValue1, int nValue2);

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, unsigned char nColor, int nFlags); // 0x0046EFD0

extern D2InvCompGridStrc gaBodyLocRects[11]; // 0x007BCD38

extern int gnAutomapWidth; // 0x007A5220

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20

void __stdcall sub_00467FA0(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0

int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60

void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0


extern "C" int gnLightmapRenderMode; // 0x00712CCC

extern "C" int gbSkillPointsHighlight; // 0x007C0C3C

extern "C" unsigned char gbFlag_007BC9D4; // 0x007BC9D4

extern "C" unsigned char gbFlag_007BC9D8; // 0x007BC9D8

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __stdcall sub_00483E40(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40

void __fastcall INV_DrawMercEquipHighlights(D2UnitStrc* pUnit); // 0x0048B3F0

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

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C360

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern D2AuxLevelEntryStrc gaAuxLevelEntries[]; // 0x00721D98

static void __stdcall INV_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified);

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall sub_004521C0_SetTextColor(Unicode* pText, int nColor); // 0x004521C0

int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560

int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem); // 0x006288A0

int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0062A1E0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20

int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0

unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0

int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100

int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

int __stdcall MISSILE_GetElementalLength(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

extern D2CelFileStrc* gpGoldButtonCel_007BCC34; // 0x007BCC34

extern int gbGoldButtonDown_007BCE30; // 0x007BCE30

extern int gbGoldButtonDown_007BCE34; // 0x007BCE34

extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC

static int __stdcall INV_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight); // 0x00486820



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" size_t __cdecl strlen(const char* szString);

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

void __fastcall PLAYER_SetPanelSlide(int nMode); // 0x0045AEA0

Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern); // 0x00526940

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60

int __fastcall sub_004A7660_SplitAtNewLine(Unicode* wszText, Unicode** ppSecond); // 0x004A7660

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

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


int __cdecl sub_00402A80_IsDbgHelpLoaded(); // 0x00402A80

struct D2ClientCacheEntryStrc
{
    unsigned char unk0x00[0x4C];
    unsigned char bLocked;
    unsigned char unk0x4D[0x2F];
    unsigned char dwLastUse[4];
    unsigned char unk0x80[0x0A];
    unsigned char nRefCount[4];
};

struct D2ClientStateStrc
{
    char unk0x00[0x11D];
    unsigned char bFlag0x11D;
    char unk0x11E[0x0B];
    unsigned char bFlag0x129;
    unsigned char bFlag0x12A;
};

int __cdecl ROSTER_IsAnyoneHostile();                                                                                 // 0x0047A560

void __fastcall SOUNDHDR_ReleaseCacheEntry(int nId);                                                    // 0x004823E0

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg);                                          // 0x004873A0

void __cdecl INV_ResetHover();                                                                     // 0x00487990

void __fastcall sub_0049FF90_Close(int nArg, D2ClientStateStrc* pState);                                    // 0x0049FF90

int __cdecl NPCMENU_IsAnyDialogOpen();                                                                                 // 0x004B34A0

void __cdecl NPCMENU_CloseNpcShop();                                                                                // 0x004B3ED0

int __fastcall sub_004DF9D0_CheckCacheEntry(int nId);                                                       // 0x004DF9D0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit);                       // 0x00648B90

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);                // 0x00649970

extern D2ClientTabStrc gaNpcTabStates[];                                                                   // 0x0072211A

extern D2ClientCacheEntryStrc* sgptSoundHeaderTable;                                                     // 0x007BC9A0

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

void __fastcall SOUNDHDR_UpdateCache(unsigned int nTick); // 0x00482B40

void __fastcall sub_004BA020(unsigned int nTick); // 0x004BA020

void __fastcall sub_004DCAA0_UpdateLevelSong(unsigned int nTick); // 0x004DCAA0

int __cdecl sub_004DF870(); // 0x004DF870

void __cdecl sub_004DF890(); // 0x004DF890

void __fastcall SKILLDESC_UpdateEnvironSounds(unsigned int nTick); // 0x004E42E0

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

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80


void __fastcall UI_OpenGoldPanel(int nMode); // 0x00454150

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall sub_00468040(int nArg, int nArg2); // 0x00468040

void __fastcall MSG_SendDwords3(unsigned char nHeader, unsigned int nArg1, unsigned int nArg2, unsigned int nArg3); // 0x004786D0

void __fastcall sub_004B9070(int nArg); // 0x004B9070

int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem); // 0x00628C20

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem); // 0x00628C70

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

void __stdcall INV_DrawItemSockets(D2UnitStrc* item, D2InventoryGridInfoStrc* grid, int x, int y); // 0x00483E40

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6850

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

int __stdcall sub_0063B9D0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, int* pOutX, int* pOutY, unsigned char nPage); // 0x0063B9D0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

extern "C" const char gszCmnItemsH[]; // 0x006D9B90

extern "C" const char gszInvCpp[]; // 0x006D9BC0

extern int gnDialogState; // 0x00721E34

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58


int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc); // 0x00627C20

int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc* pPlayer, int nValue); // 0x0062A5D0

int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc* pPlayer, int nValue); // 0x0062A620

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

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0








void __cdecl sub_004972B0_InitializePalette(); // 0x004972B0








D2ClientInterfaceStrc* __cdecl sub_0044D540_GetClientInterface();                                           // 0x0044D540

int __cdecl CHAT_HasClassOverride();                                                                // 0x0047AA30

extern char gszClientCharName[];                                                                         // 0x007A05C4

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

void INV_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor); // 0x00483A70

int __cdecl INV_GetPanelX();

int __cdecl INV_GetPanelY();

int __fastcall INV_IsInNpcPanelRect(int nX, int nY); // 0x00486E10

void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg); // 0x00486E60

int __cdecl INV_ResetNpcButtons(); // 0x00487BE0

int __cdecl INV_CanUseCursor(); // 0x004888C0

void __cdecl INV_RestoreSelectedShopButton(); // 0x00488F10

void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId); // 0x004844A0

int __cdecl sub_E05_Emit_00486860(); // 0x00486860

int __cdecl sub_E05_Emit_00489FB0(int nX, int nY); // 0x00489FB0






















void __cdecl INV_SetupPanelButtons();

























extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __stdcall sub_00403040_ConstructVector(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnCtor)(void*)); // 0x00403040

void __fastcall NPCMENU_ClearUnicode(void* pChar);                                                     // 0x0042F530

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nSize, const char* szFormat, ...);             // 0x00413A40

unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80

Unicode* __fastcall sub_00452170(Unicode* pText);                                                           // 0x00452170

D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440

D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470

const Unicode* __fastcall INV_SkipBracketTag(const Unicode* pString); // 0x004834A0

void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...);                          // 0x0048BE80

int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150

void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefix);                                 // 0x00627EC0

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffix);                                 // 0x00627F80

unsigned short __stdcall ITEMS_GetRarePrefixId(D2UnitStrc* pItem);                                          // 0x00627FE0

unsigned short __stdcall ITEMS_GetRareSuffixId(D2UnitStrc* pItem);                                          // 0x00628040

char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem);                                                        // 0x00628340

unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem);                                               // 0x006283A0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                         // 0x0062B400

D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex);                                     // 0x00633EE0

D2RareAffixTxt* __stdcall DATATBLS_GetRareAffixTxtRecord(int nId);                                          // 0x00634260

D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nId);                              // 0x006375C0

unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);                                          // 0x0063CD60

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

extern int gbHoverPlayerItem; // 0x00721E38

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey);

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

D2UnitStrc* __cdecl CURSOR_GetCursorItem(); // 0x004680A0

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall MSG_SendFourDwords(char nCommand, int nArg0, int nArg1, int nArg2, int nArg3); // 0x00478700

void __cdecl SPELLSEL_UpdateSkillIcons(); // 0x004A9DF0

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230

void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pItem); // 0x004C21F0

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130

unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850

int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0

int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0

int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10


static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0

static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage);

extern D2InvRectStrc gtPlayerInvRect;                                                                            // 0x007BCAA0

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

extern D2InventoryGridInfoStrc gtTradePage2Grid;        // 0x007BCA30

extern D2InventoryGridInfoStrc gtCubeGrid;        // 0x007BCB70

int __cdecl GAME_IsExitPending(); // 0x0044DA30

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __cdecl INV_LoadUiRecords(); // 0x004835B0

int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0

int __cdecl sub_0045AE90(); // 0x0045AE90

void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS*); // 0x00498DC0

void __cdecl sub_0048A730_SwapWeapons(); // 0x0048A730

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

typedef int (__fastcall *D2BodyClickFn)(D2UnitStrc*,D2InventoryStrc*,int);

extern D2BodyClickFn gaBodyClick[]; // 0x00721E58

static void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight, int nColor); // 0x004839D0

int __fastcall INV_IsInPlayerInvRect(int nX, int nY); // 0x00483AB0

static int INV_IsOverWeaponSwapTab(int nX, int nY); // 0x00486860

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0

static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX); // 0x00486E60

int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck);  // 0x0063DE60

int __stdcall sub_0062C0B0_GetItemTypeClass(D2UnitStrc* pItem);

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0



void __stdcall INV_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid);

void __cdecl INV_CloseCubePanel(); // 0x0048A050

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit);   // 0x004521C0

int __stdcall STATLIST_GetDefenseFromUnit(D2UnitStrc* pUnit); // 0x00626020


int __stdcall INV_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom);                    // 0x0048A790

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

void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg);

static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory);

void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);

static void INV_SelectButtonByKey(int nKey);

static int INV_IsOverTradeButtonLeft(int nX, int nY);

static int INV_IsOverTradeButtonRight(int nX, int nY);

void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg);

static int INV_IsOverCloseButton(int nX, int nY); // 0x00489920

static int INV_IsOverTransmuteButton(int nX, int nY); // 0x00489980

void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);

void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg);

static int INV_IsOverButtonC(int nX, int nY); // 0x00489FB0

static void INV_AppendBookCharges(Unicode* pText);

static D2UnitStrc* INV_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId); // 0x00486770

static void __stdcall INV_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem); // 0x00483C50

static void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory);

void __stdcall INV_DrawUnitInventory(D2UnitStrc* pUnit);

void __stdcall INV_TradeMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004894D0

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

void __fastcall INV_UpdateAuxBattleNetAddress(int nIndex); // 0x00482CA0

int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion); // 0x004FAD10

int __fastcall D2Win_10177(unsigned char nAct); // 0x004FB480

void __fastcall PLAYER_SetCinematicExpansion(int bExpansion); // 0x00460480

int __cdecl sub_00460500_RunPopup(); // 0x00460500

int __cdecl sub_00460680_RunOkCancel(); // 0x00460680

int __cdecl sub_004605A0_RunPopup(); // 0x004605A0

void __cdecl sub_00477DD0(); // 0x00477DD0

void __cdecl sub_00481830(); // 0x00481830

void __cdecl GFXUTIL_ClearFadeTimer(); // 0x004DC0A0

void __fastcall GAME_SetPlayCinematic(int nValue); // 0x0044D530

void __cdecl GAME_SetCinematicPlayed(); // 0x0044D510

void __cdecl GAME_ExitForCinematic(); // 0x0044DD60

extern "C" const char gszRes640x146[]; // 0x006D4214

extern "C" const char gszRes640x292[]; // 0x006D421C

extern int gnAuxLevelEntries; // 0x00721D94


char gbCinematicPlaying; // 0x007BC9D5

extern int gnAutomapHeight; // 0x007A521C

extern unsigned char gabGridColors_007BCAD8[]; // 0x007BCAD8

struct D2CharStatsTxt;



struct D2DifficultyLevelsTxt;

struct D2MercStatLineStrc;

struct D2ElemDamageStrc;

struct D2SetsTxt;

extern int gbWeaponSwitch; // 0x007BCC4C

int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0

int __stdcall ITEMS_GetQuiverType(D2UnitStrc*); // 0x0062E740



int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, void* pSkill, int bBonus); // 0x006442A0

int __stdcall ITEMS_GetWeaponAttackSpeed(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A710

int __stdcall D2COMMON_11036_GetMonCurseResistanceSubtraction(int nLevel, int nSkillId); // 0x00645C10

extern D2SpeedNameStrc gaSpeedNames[6]; // 0x00721E88

extern D2ItemTypeNameStrc gaItemTypeNames[15]; // 0x00721EB0

extern int gaSpeedTable[][5]; // 0x00721F10

extern int gaClassSpeedOffsets[][2]; // 0x00722078

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __fastcall ROSTER_GetPetLife(int nUnitId); // 0x00479080

void __stdcall INV_DrawUnitName(D2UnitStrc* pUnit); // 0x0048A7D0

void __cdecl INV_DrawPanelLabels(); // 0x0048A890

void __stdcall D2LANG_FormatInt(Unicode* pOut, int nValue, int nSize); // 0x00525FB0

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

extern D2MercStatLineStrc gaMercStatLines[12]; // 0x007221A8

static void INV_DrawMercStats(D2UnitStrc* pUnit); // 0x0048A990

D2SetsTxt* __fastcall DATATBLS_GetSetsTxtRecord(int nSetId); // 0x00483410

int __stdcall sub_00485410_AppendDamage(D2UnitStrc* pItem, Unicode* pText); // 0x00485410

void __stdcall INV_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText); // 0x00485EE0

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra); // 0x004E6410

void __fastcall WARDENCLIENT_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6560

void __fastcall MISSILE_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6680

int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625E60

int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pItem, int a2); // 0x00625EF0

int __stdcall STATLIST_GetDefenseFromUnit(D2UnitStrc* pUnit); // 0x00626020

int __stdcall ITEMS_GetLevelRequirement(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x0062BA60

int __stdcall ITEMS_IsClassValid(D2UnitStrc* pItem); // 0x0062C060

int __stdcall ITEMS_GetClassOfClassSpecificItem(D2UnitStrc* pItem); // 0x0062C0B0

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

static int sub_00483B40_IsInRect(int nX, int nY);

static int sub_00483BF0_IsInRect(int nX, int nY);





extern "C" { int gnFlag_007C02EC; } // 0x007C02EC






struct D2ClientInterfaceStrc
{
    char unk0x00[0x5C];
    int (__cdecl* pfnGetVersion)();
};















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
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
    STRTABLE_GetLanguageInfoField(szLang, 0);
// build: symbol ?gszDataLocal@* 0x006D41A8
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

    sub_00481830();
    sub_004DCA30();
    sub_004FAD70();

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
// build: symbol ?gszDataGlobal@* 0x006D4118
            sprintf(szFile, "%s\\video\\%s", gszDataGlobal, szName);

        gbCinematicPlaying = 1;
        GFXUTIL_ClearFadeTimer();
        UI_SetUIVar(0x12, 0, 0);
// build: symbol ?D2Win_10003@* 0x004F9050
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
            sub_004FAD70();
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

    sub_004FAD70();
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








static __forceinline void sub_004845A0_DrawOtherHandFrame(D2InvCompGridStrc* pCompGrid)
{
    const int nLeft = pCompGrid->rect.nLeft;
    if (nLeft >= 0 && nLeft < gnAutomapWidth)
    {
        const int nTop = pCompGrid->rect.nTop;
        if (nTop >= 0 && nTop < gnAutomapHeight)
        {
            AUTOMAP_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[0], 0);
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





extern "C" { int gRequest; } // 0x007BCC0C



















// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    int nClassId = -1;
    if (pUnit)
    {
        nClassId = pUnit->dwClassId;
    }
    return nClassId;
}

















































static inline int InRect(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX < nRight && nY >= nTop && nY <= nBottom;
}
























struct D2SkillStrc;




static __forceinline int IsCursorInRectInline(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

static __forceinline void DrawBodyLocRectInline(D2InvCompGridStrc* pRect, int nColor)
{
    const int nX = pRect->rect.nLeft;
    const int nY = pRect->rect.nTop;
    if (nX >= 0 && nX < gnAutomapWidth && nY >= 0 && nY < gnAutomapHeight)
        AUTOMAP_DrawFramedBox(nX, nY, pRect->nWidth, pRect->nHeight, nColor, 0);
}





static inline int INV_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}







struct D2InventoryStrc;

struct D2LowQualityItemsTxt
{
    char szName[0x20];
    unsigned short wTblId;
};

struct D2RareAffixTxt
{
    char unk0x00[0x0C];
    unsigned short wStringId;
    char unk0x0E[0x18];
    char szName[0x20];
};

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





static inline int INV_IsModeInRange(int nMode)
{
    if (nMode < 2)
    {
        return 0;
    }
    if (nMode > 4)
    {
        return 0;
    }
    return 1;
}





static int __fastcall GetCenteredXInline(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    nWidth /= 2;
    return nX - nWidth;
}

void __cdecl VIEW_DrawHelpFrameLowRes();                                                                  // 0x004943B0

void __cdecl VIEW_DrawHelpFrameHighRes();                                                                  // 0x004944F0

void __cdecl ROSTERPETS_DrawHelpColumn();                                                                     // 0x00494620

void __cdecl VIEW_DrawHelpLinesLowRes();                                                               // 0x00494680

void __cdecl VIEW_DrawHelpLinesHighRes();                                                               // 0x00494A00

void __cdecl VIEW_DrawHelpPanelCel();                                                                   // 0x00494E40

extern int gbHelpUiOpened;                                                                         // 0x007BEF00

static int __fastcall GetCenteredX_Inl(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    nWidth /= 2;
    return nX - nWidth;
}














extern D2SkillIconStateStrc gtHotkeySlots;                                                      // 0x007C0300

extern int gbSkillSelectRight;                                                                               // 0x007C07FC

void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0












#include "gen/data/Source/D2Client/Unknown_00482C70.inc"
