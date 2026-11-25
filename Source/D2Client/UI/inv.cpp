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
#include "D2MultiTypes.h"

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

struct D2RC4Strc;

struct D2ClientSlotObjStrc;

struct D2ClientSlotHolderStrc;

struct D2ClientRecordStrc;

struct D2ClientStringListStrc;

struct D2ItemStatCostTxt;

struct D2StaticPathStrc;

struct D2InventoryGridInfoStrc;

struct RangeNode;

struct LookupNode;

struct ColorView;

union PackedWord;

struct SMSGHANDLER_PARAMS;

struct D2UnitStrc;

struct D2ClientServiceStrc;

struct D2DataTablesStrc;

struct D2ItemsTxt;

struct D2AuxLevelEntryStrc;

struct D2GfxDataStrc;

extern void* ghDbgHelp; // 0x0098A680

extern int gbRightClickConsumed; // 0x007A0670

extern int gbPopupDismissed; // 0x007A5254

static D2UnitStrc* gpHoverItem; // 0x007BCBF4

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

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void ApplyKeystream(unsigned char* pData, unsigned int nSize);
};

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    int (__fastcall* pfnCall)(int nArg1, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
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

struct D2ClientStringListStrc
{
    Unicode* pStrings[6];
    unsigned short nCount;
    unsigned char f_1A[4];
    unsigned char unk0x1E[8];
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

static int gbHoverInGrid; // 0x007BCBE4

extern int gnRecipeScrollColor; // 0x007BCEA4

// build: symbol ??__EgwszRecipeScrollText@@YAXXZ 0x006CABF0
Unicode gwszRecipeScrollText[4096]; // 0x007BCEA8

extern unsigned char gbTextHoverSet; // 0x007BF23A

extern int gdwGlobal_007BF23F; // 0x007BF23F

extern int gaHotkeySkills[16]; // 0x007C06C8

extern int gaHotkeyOwners[16]; // 0x007C0768

extern int gaHotkeyLeft[16]; // 0x007C07B8

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

int gnInvMouseX;                                                                                      // 0x007BCA4C

int gnInvMouseY;                                                                                      // 0x007BCBD8

static int gbHoverInBodyLoc; // 0x007BCBE8

static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8

static unsigned char gnSelectedTab; // 0x007BCC04

extern "C" { int gbTradeFlag; } // 0x007BCE28

static int gbInvGoldButtonDown; // 0x007BCE30

extern void* gpCel_007BCE8C; // 0x007BCE8C

static int gbPanelButtonClicked;                                                                                      // 0x007BCE9C

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

unsigned char gnMaxTab;                                                                            // 0x007BCC05

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

int gbBuySellPressed;                                                                                      // 0x007BCEA0

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

int gdwGlobal_007BC974; // 0x007BC974

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

unsigned int gdwSoundTick; // 0x007BC9BC

extern unsigned int gdwCacheUsed;                                                                  // 0x007BC9D0

#define gnGlobal_007BCAA0 (gtPlayerInvRect.nLeft)

#define gnGlobal_007BCAA4 (gtPlayerInvRect.nRight)

#define gnGlobal_007BCAA8 (gtPlayerInvRect.nTop)

#define gnGlobal_007BCAAC (gtPlayerInvRect.nBottom)

#define gnGlobal_007BCA34 (gtTradePage2Grid.nGridLeft)

#define gnGlobal_007BCA38 (gtTradePage2Grid.nGridRight)

#define gnGlobal_007BCA3C (gtTradePage2Grid.nGridTop)

#define gnGlobal_007BCA40 (gtTradePage2Grid.nGridBottom)

D2InventoryGridInfoStrc gtTradePage1Grid;                                                                     // 0x007BCB18

#define gnGlobal_007BCB74 (gtCubeGrid.nGridLeft)

#define gnGlobal_007BCB78 (gtCubeGrid.nGridRight)

#define gnGlobal_007BCB7C (gtCubeGrid.nGridTop)

#define gnGlobal_007BCB80 (gtCubeGrid.nGridBottom)

int gbNpcUiRecordsLoaded; // 0x007BCBE0

int gdwNpcPanelDelayTick;                                                                                      // 0x007BCC08

unsigned char gabSlots[4];                                                                         // 0x007BEFB4

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

static unsigned char INV_GetFlagIndex(unsigned char nFlags);

D2InvRectStrc gtBankRect; // 0x007BCA68

D2InvRectStrc gtBigBankRect; // 0x007BCAF4

D2InvRectStrc gtCubeRect; // 0x007BCB30

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2SetItemsTxt;

struct D2InvCompGridStrc;

struct D2ItemFormulaRecordStrc;

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

D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58

D2InvRectStrc gtNpcInvRect; // 0x007BCBB0

struct D2ItemFormulaRecordStrc
{
    char unk0x00[0x9E];
    short nStat;
    char unk0xA0[0x04];
    unsigned int nCalc;
    char unk0xA8[0x0C];
    unsigned char nDescType;
    char unk0xB5;
    unsigned short wStringId;
};

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

static int gnHoverBodyLoc; // 0x007BCC20

static int gnSelectedShopButtonKey; // 0x007BCC44

static int gbGoldButtonDisabled; // 0x007BCE2C

static int gbStashGoldButtonDown; // 0x007BCE34

static int gbStashButtonDown; // 0x007BCE38

static int gbStashButtonClicked; // 0x007BCE3C

static int gnGlobal_007BCE94; // 0x007BCE94

void __cdecl sub_004972B0_InitializePalette(); // 0x004972B0

unsigned int gnQuestTimerValue; // 0x007BCC14

unsigned long gdwQuestTimerTicks; // 0x007BCC18

int gnSentBytes; // 0x007A6AF8

int gnSentPackets; // 0x007A6B00

int gnChatDrawCount; // 0x007BB5EC

D2ClientServiceStrc* gpService; // 0x007BC998

int gdwGlobal_007BEEFC; // 0x007BEEFC

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

unsigned char gbFlag_007BCC06; // 0x007BCC06

D2NpcButtonStrc gaNpcButtons[4]; // 0x007BC9E0

int gdwTradeCheckTick; // 0x007BCA48

D2CelFileStrc* gpTradePanelCel; // 0x007BCB04

int gnInvPanelMode; // 0x007BCBF0

int gbQuestTimerActive; // 0x007BCC10

D2CelFileStrc* gpHoradricCel; // 0x007BCC1C

void* gpGoldButtonCel; // 0x007BCC34

int gnSelectedShopButton; // 0x007BCC40

static int gbCubeItemClicked; // 0x007BCC50

int gbCubeClosed; // 0x007BCC54

void* gpCelInvArmor; // 0x007BCE68

void* gpCelInvBelt; // 0x007BCE6C

void* gpCelInvBoots; // 0x007BCE70

void* gpCelInvHelmGlove; // 0x007BCE74

void* gpCelInvRingAmulet; // 0x007BCE78

void* gpCelInvWeapons; // 0x007BCE7C

void* gpCelTradeBtn; // 0x007BCE80

void* gpCelInvChar6Tab; // 0x007BCE84

void* gpCelNpcInv; // 0x007BCE88

static int gbPanelButtonDown; // 0x007BCE90

void __cdecl INV_SetupPanelButtons();

int gnGlobal_007BCAF0; // 0x007BCAF0

int gbTradeAcceptedSelf; // 0x007BCD34

int gbTradeAcceptedOther; // 0x007BCE14

static int gbTradeAccepted; // 0x007BCE18

static int gbTradeCancelClicked; // 0x007BCE1C

static int gbTradeAcceptButtonDown; // 0x007BCE20

static int gbTradeCancelButtonDown; // 0x007BCE24

D2CelFileStrc* gpBuySellTabsCel; // 0x007BCC24

D2CelFileStrc* gpMiniConvertCel; // 0x007BCC28

D2CelFileStrc* gpShopInvChar6TabCel; // 0x007BCC38

void* gapHirelingIcons[7]; // 0x007BEEB0

unsigned int gButtonA; // 0x007BCE30

unsigned int gButtonB; // 0x007BCE34

unsigned int gPressedFrame; // 0x007BCE38

unsigned int gButtonLatch; // 0x007BCE3C

void* gArchiveA; // 0x007BCC2C

void* gArchiveB; // 0x007BCC3C

static int gbCubeButtonDown; // 0x007BCE40

static int gbCubeButtonClicked; // 0x007BCE44

static int gbCubeCloseButtonDown; // 0x007BCE48

static int gbCubeCloseClicked; // 0x007BCE4C

void* gUiArchive; // 0x007BCC30

unsigned char gabInvHighlightColors; // 0x007BCAD8

unsigned char gbGlobal_007BCAD9; // 0x007BCAD9

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

static int gbNpcTradeClicked; // 0x007BCBEC

static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0

static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage);

D2InvRectStrc gtPlayerInvRect;                                                                            // 0x007BCAA0

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

D2InventoryGridInfoStrc gtTradePage2Grid;        // 0x007BCA30

D2InventoryGridInfoStrc gtCubeGrid;        // 0x007BCB70

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

D2InventoryGridInfoStrc gtHirelingInvGrid; // 0x007BCBC0

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

extern int gnAutomapHeight; // 0x007A521C

extern unsigned char gabGridColors_007BCAD8[]; // 0x007BCAD8

struct D2CharStatsTxt;

struct D2UnitInvView;

struct D2DifficultyLevelsTxt;

struct D2MercStatLineStrc;

struct D2ElemDamageStrc;

struct D2SetsTxt;

extern int gbWeaponSwitch; // 0x007BCC4C

int __stdcall ITEMS_GetAmmoType(D2UnitStrc*); // 0x0062E6F0

int __stdcall ITEMS_GetQuiverType(D2UnitStrc*); // 0x0062E740

struct D2UnitInvView
{
    char unk0x00[0x60];
    D2InventoryStrc* pInventory;
};

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

D2InventoryGridInfoStrc gtTrophyCaseGrid; // 0x007BCA50

D2InventoryGridInfoStrc gtGuildVaultGrid; // 0x007BCAB0

D2InvRectStrc gtTradePage2Rect; // 0x007BCA90

D2InvRectStrc gtTrophyCaseRect; // 0x007BCAC8

D2InvRectStrc gtTradePage1Rect; // 0x007BCAE0

D2InvRectStrc gtHirelingInvRect; // 0x007BCB08

D2InvRectStrc gtGuildVaultRect; // 0x007BCBA0

int gbUiRecordsLoaded; // 0x007BCBDC

int gnBeltUiRecordRow; // 0x007A5218

int gnLoadedUiRecordRow; // 0x007BEEA8

void __stdcall sub_0065C180_2(int nInventoryTxtId, int bHigherRes, D2InvRectStrc* pInvRect); // 0x0065C180

void __stdcall sub_0065C1F0_2(int nInventoryTxtId, int bHigherRes, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0

void __stdcall sub_0065C270_2(int nInventoryTxtId, int bHigherRes, D2InvCompGridStrc* pInvCompGrid, int nComponent); // 0x0065C270

void __stdcall INV_DrawRecipeScroll(); // 0x0048BC10

static void __stdcall INV_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText);

static int __stdcall INV_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage);

static int sub_00483B40_IsInRect(int nX, int nY);

static int sub_00483BF0_IsInRect(int nX, int nY);

#define LOBYTE(w) ((unsigned char)(((unsigned long)(w)) & 0xFF))
#define HIBYTE(w) ((unsigned char)((((unsigned long)(w)) >> 8) & 0xFF))
struct D2ClientPacket67Strc;
struct D2ConfigStrc;

struct D2CacheStatsStrc
{
    unsigned int nFloorSize;
    int unk0x04;
    int nFloorMisses;
    unsigned int nSubtileSize;
    int unk0x10;
    int nSubtileMisses;
    unsigned int nSprite1Size;
    unsigned int nSprite2Size;
    unsigned int nSprite3Size;
    int unk0x24[3];
    int nSprite1Misses;
    int nSprite2Misses;
    int nSprite3Misses;
    int unk0x3C[3];
    int nSprite1Accesses;
    int nSprite2Accesses;
    int nSprite3Accesses;
};

struct D2ClientPacket67Strc
{
    unsigned char nHeader;
    char szName[16];
    unsigned char nGameType;
    unsigned char nClass;
    unsigned char nByte13;
    unsigned char nByte14;
    char szCharName[16];
    unsigned char aWord[2];
    unsigned char aFlags[4];
    unsigned char nByte2B;
    unsigned char nByte2C;
    unsigned char f_2D;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern unsigned char gnCharClass; // 0x007A0522
extern "C" __declspec(dllimport) int __stdcall ReadProcessMemory(void* hProcess, const void* pBaseAddress, void* pBuffer, unsigned long nSize, unsigned long* pBytesRead); // 0x006CC350
unsigned int __cdecl sub_0044CE70(); // 0x0044CE70

unsigned int gdwEncodedName0; // 0x007A04E8

unsigned int gdwEncodedName1; // 0x007A04EC

unsigned int gdwEncodedOffset; // 0x007A04F0

unsigned long gdwLastCheckTick; // 0x007BB3B0

struct D2SendPacket6BStrc
{
    unsigned char nHeader;
};

// 0x0044BFF0
int __cdecl INV_IsRightClickConsumed()
{
    return gbRightClickConsumed != 0;
}

// 0x004521C0
Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit)
{
    if (pText->wChar)
    {
        unsigned short wszBufferBuf[0x400];
        Unicode* wszBuffer = (Unicode*)wszBufferBuf;
        wszBuffer[0].wChar = 0;
        for (int i = 1; i < 0x400; i++)
        {
            wszBuffer[i].wChar = 0;
        }
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        unsigned short wszDigitBuf[3];
        Unicode* wszDigit = (Unicode*)wszDigitBuf;
        wszDigit[0].wChar = 0;
        wszDigit[1].wChar = 0;
        wszDigit[2].wChar = 0;
        char szDigit[4];
        wsprintfA(szDigit, "%c", (char)(nDigit + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_00526700(wszBuffer, pText);
        sub_005267E0(pText, wszBuffer);
    }
    return pText;
}

// 0x00454970
extern "C" int __cdecl INV_GetScreenHeightMinusPanel()
{
    return gnScreenHeight - 49;
}

extern "C" { int gnFlag_007C02EC; } // 0x007C02EC

// 0x00477CA0
void __fastcall sub_00477CA0_SendPacket67(const char* szName)
{
    D2ClientPacket67Strc tPacket;
    tPacket.nHeader = 0x67;
    SStrCopy(tPacket.szName, szName, 0x7FFFFFFF);
    switch (gdwGlobal_007A0610)
    {
    case 0:
        tPacket.nGameType = 3;
        break;
    case 6:
        tPacket.nGameType = 1;
        break;
    case 8:
        tPacket.nGameType = 2;
        break;
    default:
        tPacket.nGameType = 0;
        break;
    }
    if (CHAT_HasClassOverride())
        tPacket.nClass = sub_0047AA20_GetClassOverride();
    else
        tPacket.nClass = gnCharClass;
    tPacket.f_2D = STRTABLE_GetLanguage();
    if (!gpClientConfig->dwFlags209)
    {
        gpClientConfig->dwFlags209 = 4;
        gpClientConfig->dwFlags209 |= 0x100000;
    }
    memcpy(tPacket.aWord, gpClientConfig->aWord207, sizeof(tPacket.aWord));
    memcpy(tPacket.aFlags, gpClientConfig->aState209, sizeof(tPacket.aFlags));
    tPacket.nByte13 = gpClientConfig->nArenaTemplate;
    tPacket.nByte2B = gpClientConfig->unk0x20E;
    tPacket.nByte2C = gpClientConfig->unk0x20F;
    tPacket.nByte14 = gpClientConfig->nByte210;
    SStrCopy(tPacket.szCharName, gszClientCharName, 0x7FFFFFFF);
// build: symbol ?CLIENT_Send@* 0x0052AE50
    CLIENT_Send(sizeof(tPacket), 0, &tPacket);
    gnSentBytes += sizeof(tPacket);
    gnSentPackets += 1;
}

// 0x00477DA0
void __cdecl sub_00477DA0()
{
    D2SendPacket6BStrc tPacket;
    tPacket.nHeader = 0x6B;
    CLIENT_Send(sizeof(D2SendPacket6BStrc), 0, &tPacket);
    gnSentBytes += sizeof(D2SendPacket6BStrc);
    gnSentPackets += 1;
}

// 0x00477DD0
void __cdecl sub_00477DD0()
{
    int aPacket[4];
    unsigned int aName[3];
    unsigned short wLow;
    unsigned short wHigh;

    aName[0] = gdwEncodedName0 * 0x470E31C1;
    aName[1] = gdwEncodedName1 * 0x470E31C1;
    const unsigned int nOffset = gdwEncodedOffset * 0x470E31C1;
    ((char*)aName)[8] = 0;

    unsigned int nValue;
    if ((char)aName[0])
    {
        nValue = 0xCCCCCCCC;
        char* hModule = (char*)GetModuleHandleA((const char*)aName);
        if (hModule)
        {
            char* pAddress = hModule + nOffset;
            if (ReadProcessMemory(GetCurrentProcess(), pAddress, &wLow, 2, 0))
            {
                if (ReadProcessMemory(GetCurrentProcess(), pAddress + 0x20, &wHigh, 2, 0))
                {
                    // __assume: keeps the bytes collecting in nValue's own register, as the original does; no plain form found
                    nValue = !hModule ? 0 : HIBYTE(wHigh);
                    __assume(nValue != 0x80000000);
                    nValue <<= 8;
                    __assume(nValue != 0x80000000);
                    nValue |= LOBYTE(wHigh);
                    __assume(nValue != 0x80000000);
                    nValue <<= 8;
                    __assume(nValue != 0x80000000);
                    nValue |= HIBYTE(wLow);
                    __assume(nValue != 0x80000000);
                    nValue <<= 8;
                    __assume(nValue != 0xFFFFFFFF);
                    nValue |= LOBYTE(wLow);
                }
            }
        }
    }
    else
    {
        nValue = 0;
    }

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastCheckTick >= 5000)
    {
        gdwLastCheckTick = dwTick;
        char* pPacket = (char*)aPacket;
        pPacket[0] = 0x6D;
        *(unsigned long*)(pPacket + 1) = GetTickCount();
        *(unsigned int*)(pPacket + 5) = sub_0044CE70() >> 1;
        *(unsigned int*)(pPacket + 9) = nValue * 0xB640DE41;
        CLIENT_Send(13, 0, aPacket);
        gnSentBytes += 13;
        gnSentPackets += 1;
    }
}

// 0x00477EE0
void __cdecl INV_SendLeaveGame()
{
    unsigned char nHeader = 0x69;
// build: symbol ?CLIENT_Send@* 0x0052AE50
    CLIENT_Send(1, 0, &nHeader);
    gnSentBytes += 1;
    gnSentPackets += 1;
    if (gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1 && gdwGlobal_007A0610 != 6 && gdwGlobal_007A0610 != 7
        && gdwGlobal_007A0610 != 8 && gdwGlobal_007A0610 != 9)
    {
        gbLeavingGame = 1;
        gbPositionalSound = 0;
        gbGameServerReady = 0;
    }
    if (gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 7)
    {
        D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
        if (pNotify)
            pNotify->pfnNotify();
    }
}

struct D2ClientInterfaceStrc
{
    char unk0x00[0x5C];
    int (__cdecl* pfnGetVersion)();
};

// 0x00477F70
void __fastcall INV_SendGameLogon(int nServerToken, int nServerHash)
{
    D2GameLogonPacketStrc tPacket;
    tPacket.nHeader = 0x68;
    *(int*)tPacket.nServerHash = nServerHash;
    *(short*)tPacket.nServerToken = (short)nServerToken;
    *(int*)tPacket.nVersion = sub_0044D540_GetClientInterface()->pfnGetVersion();
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    *(unsigned int*)tPacket.nKey1 = FOG_IsExpansion() ? 0xED5DCC50 : 0x2185EDD6;
    *(unsigned int*)tPacket.nKey2 = 0x91A519B6;
    tPacket.nLanguage = STRTABLE_GetLanguage();
    tPacket.nClass = CHAT_HasClassOverride() ? sub_0047AA20_GetClassOverride() : gnCharClass_007A0522;
    SStrCopy(tPacket.szName, gszClientCharName, 0x7FFFFFFF);
// build: symbol ?CLIENT_Send@* 0x0052AE50
    CLIENT_Send(sizeof(D2GameLogonPacketStrc), 0, &tPacket);
    gnSentBytes += sizeof(D2GameLogonPacketStrc);
    gnSentPackets += 1;
}

// 0x00478010
void __cdecl sub_00478010()
{
    unsigned char nHeader = 0x6A;
    CLIENT_Send(1, 0, &nHeader);
    gnSentBytes += 1;
    gnSentPackets += 1;
}

// 0x004834A0
const Unicode* __fastcall INV_SkipBracketTag(const Unicode* pString)
{
    int n = sub_00526800(pString);
    for (; n > 0; --n)
    {
        if (pString[n].wChar == ']')
        {
            break;
        }
    }
    if (pString[n].wChar == ']' && n >= 3 && pString[n - 3].wChar == '[')
    {
        return &pString[n + 1];
    }
    return pString;
}

// 0x004834E0
void __fastcall INV_ReplaceToken(Unicode* pText, int nIndex, const Unicode* pInsert)
{
    Unicode wszBuffer[400];
    const int nDigit = nIndex + '0';
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength - 1; ++i)
    {
        if (pText[i].wChar == '%' && pText[i + 1].wChar == nDigit)
        {
            sub_00526700(wszBuffer, pInsert);
            const Unicode* pEnd = &wszBuffer[sub_00526800(wszBuffer) - 1];
            const int bSpace = pEnd->wChar == ' ';
            Unicode* pDest = pText;
            const Unicode* pRest;
            if (!(bSpace && pDest[i + 2].wChar == ' '))
            {
                pRest = &pDest[i + 2];
                sub_00526700(wszBuffer, pRest);
            }
            else
            {
                pRest = &pDest[i + 3];
                sub_00526700(wszBuffer, pRest);
            }
            sub_005267E0(pDest, wszBuffer);
            return;
        }
        wszBuffer[i] = pText[i];
    }
}

// 0x004835B0
void __cdecl INV_LoadUiRecords()
{
    if (gnBeltUiRecordRow != gnLoadedUiRecordRow)
    {
        gnLoadedUiRecordRow = gnBeltUiRecordRow;
        gbUiRecordsLoaded = 0;
        gbNpcUiRecordsLoaded = 0;
    }

    if (!gbUiRecordsLoaded)
    {
        const int nClass = sub_00621050(sub_00463DD0_GetPlayerUnit(), 0, GAME_IsExpansion());
        sub_0065C180_2(nClass, gnBeltUiRecordRow, &gtPlayerInvRect);
        sub_0065C1F0_2(nClass, gnBeltUiRecordRow, &gtPlayerInvGrid);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[4], 0);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[3], 1);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[5], 2);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[1], 3);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[2], 4);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[6], 5);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[7], 6);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[8], 7);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[9], 8);
        sub_0065C270_2(nClass, gnBeltUiRecordRow, &gaCompGrids[10], 9);
        sub_0065C180_2(13, gnBeltUiRecordRow, &gtHirelingInvRect);
        sub_0065C1F0_2(13, gnBeltUiRecordRow, &gtHirelingInvGrid);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[4], 0);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[3], 1);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[5], 2);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[1], 3);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[2], 4);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[6], 5);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[7], 6);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[8], 7);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[9], 8);
        sub_0065C270_2(13, gnBeltUiRecordRow, &gaBodyLocRects[10], 9);
        sub_0065C180_2(6, gnBeltUiRecordRow, &gtTradePage1Rect);
        sub_0065C1F0_2(6, gnBeltUiRecordRow, &gtTradePage1Grid);
        sub_0065C180_2(7, gnBeltUiRecordRow, &gtTradePage2Rect);
        sub_0065C1F0_2(7, gnBeltUiRecordRow, &gtTradePage2Grid);
        sub_0065C180_2(8, gnBeltUiRecordRow, &gtBankRect);
        sub_0065C1F0_2(8, gnBeltUiRecordRow, &gtBankGrid);
        sub_0065C180_2(12, gnBeltUiRecordRow, &gtBigBankRect);
        sub_0065C1F0_2(12, gnBeltUiRecordRow, &gtBigBankGrid);
        sub_0065C180_2(9, gnBeltUiRecordRow, &gtCubeRect);
        sub_0065C1F0_2(9, gnBeltUiRecordRow, &gtCubeGrid);
        sub_0065C180_2(10, gnBeltUiRecordRow, &gtGuildVaultRect);
        sub_0065C1F0_2(10, gnBeltUiRecordRow, &gtGuildVaultGrid);
        sub_0065C180_2(11, gnBeltUiRecordRow, &gtTrophyCaseRect);
        sub_0065C1F0_2(11, gnBeltUiRecordRow, &gtTrophyCaseGrid);
        gbUiRecordsLoaded = 1;
    }

    int nUnitId;
    if (!gbNpcUiRecordsLoaded && gnInvPanelMode && NPCMENU_GetInteractNpcId(&nUnitId))
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
        if (pUnit)
        {
            const int nClass = sub_00621050(pUnit, 0, GAME_IsExpansion());
            sub_0065C180_2(nClass, gnBeltUiRecordRow, &gtNpcInvRect);
            sub_0065C1F0_2(nClass, gnBeltUiRecordRow, &gtNpcInvGrid);
            gbNpcUiRecordsLoaded = 1;
        }
    }
}

// 0x00483960
void __cdecl INV_InitColorTable()
{
    gabColors_007BCAD8[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabColors_007BCAD8[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabColors_007BCAD8[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabColors_007BCAD8[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
    gabColors_007BCAD8[4] = D2Win_10034_MixRGB(0x80, 0x40, 0x40);
}

// 0x004839D0
static void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nY, unsigned char nWidth, unsigned char nHeight, int nColor)
{
    for (int nRow = nY; nRow < nY + nHeight; ++nRow)
    {
        for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
        {
            const int nLeft = pGrid->nGridBoxWidth * nColumn + pGrid->nGridLeft;
            const int nTop = pGrid->nGridBoxHeight * nRow + pGrid->nGridTop;
            if (nLeft >= 0 && nLeft < gnAutomapWidth && nTop >= 0 && nTop < gnAutomapHeight)
            {
                AUTOMAP_DrawFramedBox(nLeft, nTop, pGrid->nGridBoxWidth, pGrid->nGridBoxHeight, gabGridColors_007BCAD8[nColor], 0);
            }
        }
    }
}

// 0x00483A70
static void INV_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor)
{
    if (nColor == 2)
    {
        return;
    }
    const int nLeft = pCompGrid->rect.nLeft;
    const int nTop = pCompGrid->rect.nTop;
    if (nLeft >= 0 && nLeft < gnAutomapWidth && nTop >= 0 && nTop < gnAutomapHeight)
    {
        AUTOMAP_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[nColor], 0);
    }
}

// 0x00483AE0
static int INV_IsInTradeOtherGrid(int nX, int nY)
{
    if (nX > gnGlobal_007BCB1C && nX < gnGlobal_007BCB20 && nY >= gnGlobal_007BCB24 && nY <= gnGlobal_007BCB28)
    {
        return 1;
    }
    return 0;
}

// 0x00483B10
static int INV_IsInTradeGrid(int nX, int nY)
{
    if (nX > gnGlobal_007BCA34 && nX < gnGlobal_007BCA38 && nY >= gnGlobal_007BCA3C && nY <= gnGlobal_007BCA40)
    {
        return 1;
    }
    return 0;
}

// 0x00483B40
static int sub_00483B40_IsInRect(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nX > gnGlobal_007BCA7C && nX <= gnGlobal_007BCA80 && nY >= gnGlobal_007BCA84 && nY <= gnGlobal_007BCA88)
        {
            return 1;
        }
        return 0;
    }

    if (nX > gnGlobal_007BCB44 && nX <= gnGlobal_007BCB48 && nY >= gnGlobal_007BCB4C && nY <= gnGlobal_007BCB50)
    {
        return 1;
    }
    return 0;
}

// 0x00483BA0
static int sub_00483BA0_IsInRect(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nX >= gnGlobal_007BCAF4 && nX < gnGlobal_007BCAF8 && nY >= 0 && nY <= gnGlobal_007BCB00)
        {
            return 1;
        }
        return 0;
    }

    if (nX >= gnGlobal_007BCA68 && nX < gnGlobal_007BCA6C && nY >= 0 && nY <= gnGlobal_007BCA74)
    {
        return 1;
    }
    return 0;
}

// 0x00483BF0
static int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

int __cdecl sub_E04_Emit_00483AE0(int nX, int nY)
{
    return INV_IsInTradeOtherGrid(nX, nY);
}

int __cdecl sub_E04_Emit_00483B10(int nX, int nY)
{
    return INV_IsInTradeGrid(nX, nY);
}

int __cdecl sub_E04_Emit_00483B40(int nX, int nY)
{
    return sub_00483B40_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483BA0(int nX, int nY)
{
    return sub_00483BA0_IsInRect(nX, nY);
}

int __cdecl sub_E04_Emit_00483BF0(int nX, int nY)
{
    return sub_00483BF0_IsInRect(nX, nY);
}

// 0x00483C20
static int INV_IsInSidePanelRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB30 && nX < gnGlobal_007BCB34 && nY >= 0 && nY <= gnGlobal_007BCB3C)
    {
        return 1;
    }
    return 0;
}

struct D2ClientTextDataStrc;

// 0x00483C50
static void __stdcall INV_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem)
{
    if (nPage == 0xFF)
    {
        return;
    }
    D2UnitStrc* pOther = 0;
    if (!pCursorItem || !gbHoverInGrid)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
    if (gnHoverCellX < 0 || gnHoverCellY < 0)
    {
        return;
    }
    if (gnInvPanelMode == 1 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    if (gnInvPanelMode == 0x13 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    int nOutX;
    int nOutY;
    if (sub_0063B9D0(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &nOutX, &nOutY, nPage))
    {
        INV_DrawGridCells(pGrid, gnHoverCellX, gnHoverCellY, nWidth, nHeight, 1);
        return;
    }
    else
    {
        if (!INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 1)
            && (!pOther || DATATBLS_GetItemsTxtRecord(!pOther ? -1 : pOther->dwClassId)->dwCode != 0x20786F62))
        {
            INV_DrawGridCells(pGrid, gnHoverCellX, gnHoverCellY, nWidth, nHeight, 0);
            return;
        }
        unsigned char nOtherWidth;
        unsigned char nOtherHeight;
        ITEMS_GetDimensions(pOther, &nOtherWidth, &nOtherHeight, gszCmnItemsH, 0x6DC);
        INV_DrawGridCells(pGrid, CLIENTS_GetUnitX(pOther), CLIENTS_GetUnitY(pOther), nOtherWidth, nOtherHeight, 3);
    }
}

// 0x00483E10
int __cdecl INV_IsNpcStateIdle()
{
    if (gnInvPanelMode == 0 || gnInvPanelMode == 1 || gnInvPanelMode == 3 || gnInvPanelMode == 2 || gnInvPanelMode == 4)
    {
        return 1;
    }
    return 0;
}

// 0x00483E40
void __stdcall INV_DrawItemSockets(D2UnitStrc* item, D2InventoryGridInfoStrc* grid, int x, int y)
{
    if (!ITEMS_CheckItemFlag(item, 0x10, 1120, ".\\UI\\inv.cpp"))
        return;
    unsigned char width, height;
    D2InventoryStrc* pInventory = item->pInventory;
    D2UnitStrc* socketItem = INVENTORY_GetFirstItem(pInventory);
    ITEMS_GetDimensions(item, &width, &height, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 1756);
    const unsigned char socketCount = ITEMS_GetSockets(item);
    const D2CoordStrc* offsets = gSocketLayouts[(2 * socketCount + width) * 4 + height - 13];
    for (unsigned int i = 0; i < ITEMS_GetSockets(item); ++i)
    {
        int drawX = (offsets[i].nX - 1) * grid->nGridBoxWidth / 2 + x;
        int drawY = (offsets[i].nY + 1) * grid->nGridBoxHeight / 2 + y;
        D2CelContextStrc context;
        memset(&context, 0, sizeof(context));
        context.pCellFile = gpCellFile_007BEF14;
        context.nDirection = 0;
        context.nFrame = 0;
        sub_004F6480(&context, drawX - 1, drawY, -1, 0, 0);
        if (socketItem)
        {
            D2UnitStrc* checked = INVENTORY_UnitIsItem(socketItem);
            GFX_DrawItemCel(checked, drawX, drawY - grid->nGridBoxHeight);
            socketItem = INVENTORY_GetNextItem(socketItem);
        }
    }
}

// 0x00483F80
static int INV_IsUnusableQuestBook(D2ItemsTxt* pItemsTxt)
{
    const int nCode = pItemsTxt->dwCode;
    if (nCode == 0x20737361)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 9, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x207A7978)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x14, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x20327274)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 8) || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 7))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00483FF0
void __stdcall INV_DrawUnitInventory(D2UnitStrc* pUnit)
{
    INV_LoadUiRecords();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2InventoryGridInfoStrc* pGrid;
    const int nType = !pUnit ? 6 : pUnit->dwUnitType;
    switch (nType)
    {
    case 1:
        pGrid = &gtNpcInvGrid;
        break;
    case 0:
        switch (gnSelectedTab)
        {
        case 1:
            pGrid = &gtTradePage1Grid;
            break;
        case 2:
            pGrid = &gtTradePage2Grid;
            break;
        case 4:
            pGrid = GAME_IsExpansion() ? &gtBigBankGrid : &gtBankGrid;
            break;
        case 3:
            pGrid = &gtCubeGrid;
            break;
        default:
            pGrid = &gtPlayerInvGrid;
            break;
        }
        break;
    default:
        return;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, gnSelectedTab, GAME_IsExpansion());
    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory);
    while (pNode)
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (!pItem || INVENTORY_GetItemNodePage(pNode) != 1)
        {
            goto Next;
        }
        int nX;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pItem->pStaticPath->nXPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nX = PATH_GetXPosition(pItem->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        int nY;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pItem->pStaticPath->nYPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nY = PATH_GetYPosition(pItem->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
        if (ITEMS_GetInvPage(pItem) != gnSelectedTab)
        {
            pNode = INVENTORY_GetNextItem(pNode);
            continue;
        }
        if (pItem == gpHoverItem && gbHoverInGrid)
        {
            if (sub_00468830() != 8 || ITEMS_GetTransmogrify(gpHoverItem))
            {
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 1);
            }
            else
            {
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 0);
            }
            GFX_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            if (ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0 && ITEMS_CheckItemFlag(pItem, 0x800, 0x51C, gszInvCpp))
            {
                INV_DrawItemSockets(pItem, pGrid, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            }
            goto Next;
        }
        if (ITEMS_CheckRequirements(pItem, pPlayer, 0, 0, 0, 0) && !ITEMS_CheckItemFlag(pItem, 4, 0x53D, gszInvCpp)
            && !ITEM_IsItemActionBlocked(pItem) && ITEMS_CanBeEquipped(pItem))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x541, gszInvCpp))
            {
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 4);
            }
            else
            {
                const int nClassId = pItem->dwClassId;
                D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nClassId);
                int nColor = 2;
                if (pItemsTxt->nQuest && INV_IsUnusableQuestBook(pItemsTxt))
                {
                    nColor = 0;
                }
                INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, nColor);
            }
        }
        else
        {
            INV_DrawGridCells(pGrid, nX, nY, nWidth, nHeight, 0);
        }
        GFX_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
    Next:
        pNode = INVENTORY_GetNextItem(pNode);
    }
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pPlayer->pInventory);
    if (!pCursorItem)
    {
        return;
    }
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    switch (gnInvPanelMode)
    {
    case 0xB:
        if (gnSelectedTab == 1)
        {
            return;
        }
        if (gnSelectedTab == 2)
        {
            if (!INV_IsInTradeGrid(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!INV_IsInPlayerInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xC:
    case 0xD:
        if (gnSelectedTab == 4)
        {
            if (!sub_00483B40_IsInRect(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!INV_IsInPlayerInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xE:
        if (gnSelectedTab == 3)
        {
            if (!sub_00483BF0_IsInRect(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!INV_IsInPlayerInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    }
    INV_DrawCursorPlacement(pInventory, pGrid, nRecord, gnSelectedTab, pCursorItem);
}

// 0x004843E0
static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gnInvPanelMode == 0xA || gnInvPanelMode == 0xB)
    {
        return 0;
    }
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }
    if (ITEMS_GetMaxSockets(pItem) <= 0)
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    return INVENTORY_GetItemCount(pInventory) < ITEMS_GetSockets(pItem);
}

// 0x004844A0
static void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory)
{
    if (gnInvPanelMode == 1 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    if (sub_00468730() < gnScreenWidth / 2)
    {
        gnHoverBodyLoc = 0;
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (!pCursorItem || !gbHoverInBodyLoc)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
    if (ITEMS_CheckBodyLocation(pCursorItem, gnHoverBodyLoc) && ITEMS_CheckRequirements(pCursorItem, sub_00463DD0_GetPlayerUnit(), 0, 0, 0, 0))
    {
        INV_DrawSlotFrame(&gaCompGrids[gnHoverBodyLoc], 1);
    }
    else if (INV_CanSocketInto(INVENTORY_GetItemFromBodyLoc(pInventory, gnHoverBodyLoc), pCursorItem))
    {
        INV_DrawSlotFrame(&gaCompGrids[gnHoverBodyLoc], 1);
    }
    else
    {
        INV_DrawSlotFrame(&gaCompGrids[gnHoverBodyLoc], 0);
    }
}

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

// 0x004845A0
void __cdecl INV_DrawEquippedItems()
{
    unsigned char nWidth,nHeight;
    D2UnitStrc* pItem;
    D2UnitStrc* pOther;
    int nBodyLoc;
    int nOffsetX=0;
    int nOffsetY=0;
    if(GAME_IsExpansion() && gbWeaponSwitch)
    {
        nOffsetX=4;
        nOffsetY=-4;
    }
    D2UnitStrc* pPlayer=sub_00463DD0_GetPlayerUnit();
    D2InventoryStrc* pInventory=pPlayer->pInventory;
    UNITS_GetInventoryRecordId(pPlayer,0,GAME_IsExpansion());
    INV_LoadUiRecords();
    for(nBodyLoc=0;nBodyLoc<11;++nBodyLoc)
    {
        pOther=0;
        pItem=INVENTORY_GetItemFromBodyLoc(pInventory,nBodyLoc);
        if(!pItem)continue;
        ITEMS_GetDimensions(pItem,&nWidth,&nHeight,gszCmnItemsH,0x6DC);
        int bDualWield=INVENTORY_GetWieldType(pPlayer,pInventory)==2;
        switch(nBodyLoc)
        {
        case 5:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,4);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                GFX_DrawItemCel(pItem,gaCompGrids[4].rect.nLeft+((gaCompGrids[5].nWidth-gtPlayerInvGrid.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids[4].rect.nTop+((gaCompGrids[5].nHeight-gtPlayerInvGrid.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids[4]);
            }
            break;
        case 4:
            pOther=INVENTORY_GetItemFromBodyLoc(pInventory,5);
            if(bDualWield && !ITEMS_GetQuiverType(pOther) && !ITEMS_GetQuiverType(pItem))
            {
                GFX_DrawItemCel(pItem,gaCompGrids[5].rect.nLeft+((gaCompGrids[4].nWidth-gtPlayerInvGrid.nGridBoxWidth*nWidth)>>1)+nOffsetX,
                    gaCompGrids[5].rect.nTop+((gaCompGrids[4].nHeight-gtPlayerInvGrid.nGridBoxHeight*nHeight)>>1)+nOffsetY);
                sub_004845A0_DrawOtherHandFrame(&gaCompGrids[5]);
            }
            break;
        }
        int nX=gaCompGrids[nBodyLoc].rect.nLeft+((gaCompGrids[nBodyLoc].nWidth-gtPlayerInvGrid.nGridBoxWidth*nWidth)>>1);
        int nY=gaCompGrids[nBodyLoc].rect.nTop+((gaCompGrids[nBodyLoc].nHeight-gtPlayerInvGrid.nGridBoxHeight*nHeight)>>1);
        switch(nBodyLoc)
        {
        case 8:nX+=2;
        case 2:case 6:case 7:case 10:nY-=2;break;
        case 3:nX+=3;break;
        case 9:nX+=2;nY-=4;break;
        case 4:case 5:nX+=nOffsetX;nY+=nOffsetY;break;
        }
        if(pItem==gpHoverItem && gbHoverInBodyLoc)
        {
            if(sub_00468830()==8)INV_DrawSlotFrame(&gaCompGrids[nBodyLoc],0);
            else INV_DrawSlotFrame(&gaCompGrids[nBodyLoc],1); // 0x00483A70
            GFX_DrawItemCel(pItem,nX,nY);
            if(ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem)>0 && ITEMS_CheckItemFlag(pItem,0x800,0x673,gszInvCpp))
                INV_DrawItemSockets(pItem,&gtPlayerInvGrid,nX,nY);
        }
        else
        {
            if (pOther || (!ITEMS_GetAmmoType(pItem) && !ITEMS_GetQuiverType(pItem)))
            {
                if (ITEMS_CheckRequirements(pItem,pPlayer,0,0,0,0) && !ITEM_IsItemActionBlocked(pItem) && ITEMS_CanBeEquipped(pItem))
                {
                    if(!ITEMS_CheckItemFlag(pItem,0x10,0x682,gszInvCpp))INV_DrawSlotFrame(&gaCompGrids[nBodyLoc],4);
                }
                else
                {
                    INV_DrawSlotFrame(&gaCompGrids[nBodyLoc],0);
                }
            }
            else
            {
                INV_DrawSlotFrame(&gaCompGrids[nBodyLoc],0);
            }
            GFX_DrawItemCel(pItem,nX,nY);
        }
    }
    INV_DrawBodyLocPlacement(pInventory);
}

// 0x00484A70
static const Unicode* INV_GetClassNameText(unsigned int nClass)
{
    if (nClass < 7)
    {
        switch (nClass)
        {
        case 0:
            return D2LANG_GetStringFromTblIndex(0xFAB);
        case 1:
            return D2LANG_GetStringFromTblIndex(0xFAA);
        case 2:
            return D2LANG_GetStringFromTblIndex(0xFA9);
        case 3:
            return D2LANG_GetStringFromTblIndex(0xFA8);
        case 4:
            return D2LANG_GetStringFromTblIndex(0xFA7);
        case 5:
            return D2LANG_GetStringFromTblIndex(0x2771);
        case 6:
            return D2LANG_GetStringFromTblIndex(0x2772);
        }

        return 0;
    }

    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x69C);
    exit(-1);
}

// 0x00484B10
static void __stdcall INV_AppendEtherealSocketed(D2UnitStrc* pItem, Unicode* pText)
{
    int bEthereal = 0;
    Unicode wszLabel[16];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_00526F20(wszLabel, &gszEmptyAssertText, 15);
    sub_005267E0(pText, wszLabel);
    if (ITEMS_CheckItemFlag(pItem, 0x400000, 0x6C1, ".\\UI\\inv.cpp"))
    {
        sub_00526F20(wszLabel, "Ethereal", 15);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x58D9));
        bEthereal = 1;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x800, 0x6C9, ".\\UI\\inv.cpp"))
    {
        if (bEthereal)
        {
            sub_00526F20(wszLabel, ", ", 15);
            sub_00526700(pText, wszLabel);
        }
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD7D));
        Unicode wszNumber[10];
        char szNumber[10];
        const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
        SStrPrintf(szNumber, 10, "(%i)", ITEMS_GetSockets(pItem));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
        return;
    }
    if (bEthereal)
    {
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00484C90
static int INV_FormatEarName(D2UnitStrc* pItem, Unicode* pText)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x6EA, ".\\UI\\inv.cpp"))
    {
        const int nQuality = ITEMS_GetItemQuality(pItem);
        if (nQuality >= 5 && nQuality <= 9)
        {
            return 0;
        }

        Unicode wszName[0x200];
        Unicode wszFormatted[0x200];
        Unicode::win2Unicode(wszName, ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(wszFormatted, wszName, pText, 0x200, STRTABLE_GetLanguage());
        Unicode::strcpy(pText, wszFormatted);
        return 1;
    }

    return 0;
}

// 0x00484D30
static int __stdcall INV_FormatEarNameTo(D2UnitStrc* pItem, Unicode* pOut, const Unicode* pFormat)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x70B, ".\\UI\\inv.cpp"))
    {
        Unicode wszName[0x200];
        Unicode::win2Unicode(wszName, ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(pOut, wszName, pFormat, 0x200, STRTABLE_GetLanguage());
        return 1;
    }

    return 0;
}

// 0x00484DB0
static void __stdcall INV_AppendQuantity(D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
// build: symbol ?gszFormatLd@* 0x006D9BE8
        SStrPrintf(szNumber, 10, gszFormatLd, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
    }
}

// 0x00484E90
static void __stdcall INV_AppendDurability(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
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
        SStrPrintf(szNumber, 10, szFmtInt_006D6454, STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0));
        sub_00526700(pText, pColorStart);
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD87));
        sub_00526700(pText, pColorStart);
        SStrPrintf(szNumber, 10, szFmtInt_006D6454, STATLIST_GetMaxDurabilityFromUnit(pItem));
        sub_00526F20(wszNumber, szNumber, 9);
        if (bBonus)
        {
            INV_PrefixColorCode(wszNumber, 3);
        }
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00484FF0
static void __stdcall INV_AppendLabeledNumber(int nValue, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD8D));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

// 0x004850A0
static void __stdcall INV_AppendReqStr(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqStr + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD82));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

// 0x00485170
static void __stdcall INV_AppendReqDex(D2ItemsTxt* pItemsTxt, int nBonus, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    const int nValue = pItemsTxt->wReqDex + nBonus;
    if (nValue <= 0)
    {
        pText->wChar = 0;
        return;
    }
    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD83));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nValue);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

const Unicode* __fastcall sub_A15_Emit_00484A70(const unsigned char* pClass)
{
    return INV_GetClassNameText(*pClass);
}

// 0x00485240
static void __stdcall INV_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified)
{
    *pnMin = 1;
    *pnMax = 2;
    if (!pUnit || !pItem)
        return;
    int nStatNotDynamic = 0;
    D2UnitStrc* pOwner = STATLIST_GetOwner(gpOwnerSource_007BCBF4, &nStatNotDynamic);
    const int bOwner = pOwner != 0;
    if (pOwner && pOwner != pUnit)
        pUnit = pOwner;
    STATLIST_MergeStatLists(pUnit, pItem, 1);
    const int nMin = STATLIST_UnitGetStatValue(pItem, nStatMin, 0);
    int nMax = STATLIST_UnitGetStatValue(pItem, nStatMax, 0);
    if (!bOwner)
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    else
        STATLIST_MergeStatLists(pUnit, pItem, nStatNotDynamic);
    const int nBaseMin = STATLIST_GetUnitBaseStat(pItem, nStatMin, 0);
    const int nBaseMax = STATLIST_GetUnitBaseStat(pItem, nStatMax, 0);
    if (nBaseMin < nMin || nBaseMax < nMax)
        *pbModified = 1;
    if (nMax <= nMin)
        nMax = nMin;
    const int nByTimeMax = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_MAXDAMAGE_BYTIME, 0);
    if (nByTimeMax && sgptDataTables->nItemStatCostTxtRecordCount > 0x110 && &sgptDataTables->pItemStatCostTxt[0x110] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nAdd = ITEMMODS_GetByTimeAdjustment(nByTimeMax, nPeriod, nBaseTime, 0, 0, 0);
        nMax += nAdd;
        if (nAdd)
            *pbModified = 1;
    }
    const int nByTimePct = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_MAXDAMAGE_PERCENT_BYTIME, 0);
    if (nByTimePct && sgptDataTables->nItemStatCostTxtRecordCount > 0x111 && &sgptDataTables->pItemStatCostTxt[0x111] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nPct = ITEMMODS_GetByTimeAdjustment(nByTimePct, nPeriod, nBaseTime, 0, 0, 0);
        nMax += DATATBLS_ApplyRatio(nMax, nPct, 100);
        if (nPct)
            *pbModified = 1;
    }
    *pnMin = nMin;
    *pnMax = nMax;
}

// 0x00485410
void __stdcall INV_BuildItemDamageText(D2UnitStrc* pItem, Unicode* pBuffer)
{
    unsigned short wszValueBuf[256];
    Unicode* wszValue = (Unicode*)wszValueBuf;
    char szValue[256];
    int bModified;
    int nMax;
    int nMin;

    for (int i = 0; i < sizeof(wszValueBuf) / sizeof(wszValue[0]); ++i)
        wszValue[i].wChar = 0;
    const Unicode* wszSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* wszNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();

    if (ITEMSIsA(pItem, 0x26))
    {
        int nElemMin;
        nMin = ITEMS_GetMissileType(pItem);
        unsigned short wszTextBuf[256];
        Unicode* wszText = (Unicode*)wszTextBuf;
        for (int i = 0; i < sizeof(wszTextBuf) / sizeof(wszText[0]); ++i)
            wszText[i].wChar = 0;
        int nColor = 0;
        nElemMin = MISSILE_GetMinElemDamage(0, pPlayer, nMin, 1);
        nMax = MISSILE_GetMaxElemDamage(0, pPlayer, nMin, 1);
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);

        switch (MISSILE_GetElemTypeFromMissileId(nMin))
        {
        case 5:
        {
            nColor = 2;
            int nLength = MISSILE_GetElementalLength(0, pPlayer, nMin, 1) / 25;
            if (nLength <= 0)
                nLength = 1;
            nElemMin /= nLength;
            nMax /= nLength;
            break;
        }
        case 4:
            nColor = 3;
            break;
        case 1:
            nColor = 1;
            break;
        case 2:
            nColor = 4;
            break;
        }

        nElemMin += MISSILE_GetMinDamage(0, pPlayer, nMin, 1);
        int nElemMax = nMax + MISSILE_GetMaxDamage(0, pPlayer, nMin, 1);
        nElemMin >>= 8;
        nElemMax >>= 8;
        if (nElemMax <= nElemMin)
            nElemMax = nElemMin;

        SStrPrintf(szValue, sizeof(szValue), "%i", nElemMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        if (nElemMin != nElemMax)
        {
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
            SStrPrintf(szValue, sizeof(szValue), "%i", nElemMax);
            sub_00526F20(wszValue, szValue, 9);
            sub_004521C0_SetTextColor(wszValue, nColor);
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, wszValue);
        }
        sub_00526700(wszText, wszNewLine);
        sub_005267E0(pBuffer, wszText);
        return;
    }

    bModified = 0;
    if (ITEMS_Is1Or2Handed(pPlayer, pItem))
    {
        unsigned short wszTwoHandBuf[128];
        Unicode* wszTwoHand = (Unicode*)wszTwoHandBuf;
        unsigned short wszOneHandBuf[128];
        Unicode* wszOneHand = (Unicode*)wszOneHandBuf;

        INV_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszTwoHandBuf) / sizeof(wszTwoHand[0]); ++i)
            wszTwoHand[i].wChar = 0;
        sub_005267E0(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD8A));
        sub_00526700(wszTwoHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszNewLine);

        INV_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszOneHandBuf) / sizeof(wszOneHand[0]); ++i)
            wszOneHand[i].wChar = 0;
        sub_005267E0(wszOneHand, D2LANG_GetStringFromTblIndex(0xD89));
        sub_00526700(wszOneHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszNewLine);

        sub_004521C0_SetTextColor(wszTwoHand, 0);
        sub_004521C0_SetTextColor(wszOneHand, 0);
        sub_005267E0(pBuffer, wszTwoHand);
        sub_00526700(pBuffer, wszOneHand);
    }
    else
    {
        unsigned short nString;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            INV_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
            nString = 0xD8A;
        }
        else
        {
            INV_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
            nString = 0xD89;
        }
        if (nMax <= nMin + 1)
            nMax = nMin + 1;

        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(nString));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszNewLine);
    }

    bModified = 0;
    if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MINDAMAGE_PERCENT, 0) || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MAXDAMAGE_PERCENT, 0)
        || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MINDAMAGE, 0) || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0))
        bModified = 1;

    if (ITEMS_CheckIfThrowable(pItem))
    {
        unsigned short wszTextBuf[256];
        Unicode* wszText = (Unicode*)wszTextBuf;
        for (int i = 0; i < sizeof(wszTextBuf) / sizeof(wszText[0]); ++i)
            wszText[i].wChar = 0;
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);
        INV_GetItemDamageRange(pItem, pPlayer, 0x9F, 0xA0, &nMin, &nMax, &bModified);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        const int nColor = bModified ? 3 : 0;
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszNewLine);
        sub_00526700(pBuffer, wszText);
    }
}

// 0x00485BE0
static void __stdcall INV_AppendBlockChance(Unicode* pText, D2ItemsTxt* pItemsTxt, D2UnitStrc* pItem)
{
    int nBlock = STATLIST_UnitGetStatValue(pItem, STAT_TOBLOCK, 0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        const int nClass = pPlayer->dwClassId;
        D2CharStatsTxt* pCharStats = (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClass] : 0;
        nBlock += pCharStats->nBlockFactor;
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, SKILL_HOLYSHIELD);
        if (pSkill && STATES_CheckState(pPlayer, STATE_HOLYSHIELD))
        {
            const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            nBlock += D2COMMON_11036_GetMonCurseResistanceSubtraction(nLevel, SKILL_HOLYSHIELD);
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
    Unicode wszBlock[32];
    char szBlock[32];
    Unicode wszText[256];
    SStrPrintf(szBlock, 32, "%d%%\n", nBlock);
    sub_00526F20(wszBlock, szBlock, 32);
    if (nBlock > pItemsTxt->nBlock)
    {
        INV_PrefixColorCode(wszBlock, 3);
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x2B0A));
    INV_PrefixColorCode(wszText, 0);
    sub_005267E0(pText, wszText);
    sub_00526700(pText, wszBlock);
}

// 0x00485D40
static void __stdcall INV_AppendThrowDamage(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    int nMin = pItemsTxt->nMinDam;
    int nMax = pItemsTxt->nMaxDam;
    int nStringId;
    if (ITEMSIsA(pItem, 0x33))
    {
        nStringId = 0xD8C;
        D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
        void* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_HOLYSHIELD);
        if (pSkill && STATES_CheckState(pUnit, STATE_HOLYSHIELD))
        {
            const int nLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
            nMin += SKILLS_GetMinPhysDamage(pUnit, SKILL_HOLYSHIELD, nLevel, 1) >> 8;
            nMax += SKILLS_GetMaxPhysDamage(pUnit, SKILL_HOLYSHIELD, nLevel, 1) >> 8;
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
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nMin);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xD88));
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nMax);
    sub_00526F20(wszNumber, szNumber, 9);
    sub_00526700(pText, pColorStart);
    sub_00526700(pText, wszNumber);
    sub_00526700(pText, pColorEnd);
}

// 0x00485EE0
void __stdcall INV_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText)
{
    if (!pUnit)
    {
        return;
    }

    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);

    int nStatNotDynamic = 0;
    D2UnitStrc* pOwner = STATLIST_GetOwner(gpHoverItem, &nStatNotDynamic);
    const int bHasOwner = pOwner != 0;
    if (pOwner && pUnit != pOwner)
    {
        pUnit = pOwner;
    }

    STATLIST_MergeStatLists(pUnit, gpHoverItem, 1);
    int nDefense = STATLIST_GetDefenseFromUnit(gpHoverItem);
    if (!bHasOwner)
    {
        STATLIST_ExpireUnitStatlist(pUnit, gpHoverItem);
    }
    else
    {
        STATLIST_MergeStatLists(pOwner, gpHoverItem, nStatNotDynamic);
    }

    int bModified = 0;
    if (STATLIST_GetUnitBaseStat(pItem, 0x1F, 0) != nDefense)
    {
        bModified = 1;
    }

    int nByTime = STATLIST_UnitGetStatValue(pItem, 0x10C, 0);
    if (nByTime && 0x10C < sgptDataTables->nItemStatCostTxtRecordCount && &sgptDataTables->pItemStatCostTxt[0x10C] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nAdd = ITEMMODS_GetByTimeAdjustment(nByTime, nPeriod, nBaseTime, 0, 0, 0);
        nDefense += nAdd;
        if (nAdd)
        {
            bModified = 1;
        }
    }

    nByTime = STATLIST_UnitGetStatValue(pItem, 0x10D, 0);
    if (nByTime && 0x10D < sgptDataTables->nItemStatCostTxtRecordCount && &sgptDataTables->pItemStatCostTxt[0x10D] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nPercent = ITEMMODS_GetByTimeAdjustment(nByTime, nPeriod, nBaseTime, 0, 0, 0);
        nDefense += DATATBLS_ApplyRatio(nDefense, nPercent, 100);
        if (nPercent)
        {
            bModified = 1;
        }
    }

    sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD85));
    Unicode::strcat(pText, pColorStart);
    SStrPrintf(szNumber, 10, szFmtInt_006D6454, nDefense);
    Unicode::win2Unicode(wszNumber, szNumber, 9);
    if (bModified)
    {
        INV_PrefixColorCode(wszNumber, 3);
    }

    Unicode::strcat(pText, wszNumber);
    Unicode::strcat(pText, pColorEnd);
}

// 0x00486100
static void __stdcall INV_AppendStackQuantity(D2UnitStrc* pItem, Unicode* pText)
{
    Unicode wszNumber[10];
    char szNumber[10];
    const Unicode* pColorStart = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0 || ITEMS_GetTotalMaxStack(pItem) > 0)
    {
        sub_005267E0(pText, D2LANG_GetStringFromTblIndex(0xD86));
        SStrPrintf(szNumber, 10, gszFormatLd, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0));
        sub_00526F20(wszNumber, szNumber, 9);
        sub_00526700(pText, pColorStart);
        sub_00526700(pText, wszNumber);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x004861D0
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
    Unicode wszText[256];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(gaSpeedNames[nSpeed].nString));
    if (bBonus)
    {
        INV_PrefixColorCode(wszText, 3);
    }
    sub_00526700(pText, wszText);
    sub_00526700(pText, pColorEnd);
}

int __fastcall sub_A15_Emit_00484C90(Unicode* pText, D2UnitStrc* pItem)
{
    return INV_FormatEarName(pItem, pText);
}

int __fastcall sub_A15_Emit_00484D30(Unicode* pOut, const Unicode* pFormat, D2UnitStrc* pItem)
{
    return INV_FormatEarNameTo(pItem, pOut, pFormat);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00486370
static void __stdcall INV_AppendItemFormulaText(D2UnitStrc* pItem, D2ItemFormulaRecordStrc* pRecord, Unicode* pBuffer)
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
        char szValue[10];
        Unicode wszValue[10];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        switch (pRecord->nStat)
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
// build: symbol ?gszFormatLd@* 0x006D9BE8
        SStrPrintf(szValue, 10, gszFormatLd, nValue);
        sub_00526F20_ToUnicode(wszValue, szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 3:
    {
        char szValue[10];
        Unicode wszValue[10];
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(pRecord->wStringId));
        SStrPrintf(szValue, 10, gszFormatLd, nValue);
        sub_00526F20_ToUnicode(wszValue, szValue, 9);
        sub_00526700(pBuffer, pSeparator);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }

    case 4:
    {
        int nValue = ITEMMODS_EvaluateItemFormula(pPlayer, pItem, pRecord->nCalc);
        Unicode wszText[0x200];
        sub_005269D0(0x200, wszText, D2LANG_GetStringFromTblIndex(pRecord->wStringId), nValue);
        sub_00526700(pBuffer, wszText);
        sub_00526700(pBuffer, pLineEnd);
        break;
    }
    }
}

// 0x004865D0
static void INV_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMSIsA(gpHoverItem, 0x35), 0xC43);
    sub_004E6850_BuildSocketFillerText(gpHoverItem, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

void __stdcall sub_Z12_EmitDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    int nMin, nMax, bModified;
    INV_GetItemDamageRange(pItem, pUnit, 0x1F, 0x20, &nMin, &nMax, &bModified);
    sub_Z12_EmitUse(nMin, nMax, bModified);
}

// 0x00486640
static inline void INV_AppendStringLine(Unicode* pText)
{
    const Unicode* pFirst = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pSecond = D2LANG_GetStringFromTblIndex(0x4FD6);
    sub_00526700(pText, pSecond);
    sub_00526700(pText, pFirst);
}

// 0x00486670
static void __stdcall INV_AppendSocketedGemLetters(Unicode* pText, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return;
    }
    Unicode wszLetter[6];
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
                    sub_00526320_ToUnicode(wszLetter, pGemsTxtRecord->szLetter, 6);
                    sub_00526700(pText, wszLetter);
                }
            }
        }
    }
    if (bAny)
    {
// build: symbol ?gszQuote@* 0x006D9BF4
        sub_00526320_ToUnicode(wszLetter, gszQuote, 5);
        sub_00526700(pText, wszLetter);
        sub_00526700(pText, pColorEnd);
    }
}

// 0x00486770
static D2UnitStrc* INV_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, ".\\UI\\inv.cpp"))
        {
            const unsigned char nPage = ITEMS_GetInvPage(pItem);
            if (nPage == 0 || nPage == 3 || nPage == 4 || nPage == 0xFF)
            {
                const int nNodePage = INVENTORY_GetItemNodePage(pNode);
                if (nNodePage == 1 || nNodePage == 3 || nNodePage == 4)
                {
                    const int nFileIndex = ITEMS_GetFileIndex(pItem);
                    D2SetItemsTxt* pSetItemsTxt = (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nFileIndex] : 0;
                    if (pSetItemsTxt && pSetItemsTxt->wSetItemId == nSetItemId)
                    {
                        return pItem;
                    }
                }
            }
        }
    }
    return 0;
}

void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId)
{
    for (int i = 0; i < 11; ++i)
    {
        INVENTORY_GetItemFromBodyLoc(pInventory, i);
    }
    INV_DrawBodyLocPlacement(pInventory);
    INV_AppendBookCharges(pText);
    INV_FindSetItem(pInventory, nSetItemId);
}

int __cdecl sub_E05_Emit_00489FB0(int nX, int nY)
{
    return INV_IsOverButtonC(nX, nY);
}

// 0x00486820
static int __stdcall INV_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

// 0x00486860
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

// 0x004868B0
void __cdecl INV_LoadInvPanelCels()
{
    gpCelInvArmor = GAME_LoadUiCelFile("Panel\\inv_armor");
    gpCelInvBelt = GAME_LoadUiCelFile("Panel\\inv_belt");
    gpCelInvBoots = GAME_LoadUiCelFile("Panel\\inv_boots");
    gpCelInvHelmGlove = GAME_LoadUiCelFile("Panel\\inv_helm_glove");
    gpCelInvRingAmulet = GAME_LoadUiCelFile("Panel\\inv_ring_amulet");
    gpCelInvWeapons = GAME_LoadUiCelFile("Panel\\inv_weapons");
    gpCelTradeBtn = GAME_LoadUiCelFile("Panel\\tradebtn");
    gpGoldButtonCel = GAME_LoadUiCelFile("Panel\\goldcoinbtn");
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        gpCelInvChar6Tab = GAME_LoadUiCelFile("Panel\\invchar6Tab");
        gbWeaponSwitch = 0;
        gpCelNpcInv = GAME_LoadUiCelFile("Panel\\NPCInv");
    }
    else
    {
        gpCelInvChar6Tab = 0;
        gbWeaponSwitch = 0;
        gpCelNpcInv = 0;
    }
}

// 0x00486980
void __cdecl INV_FreeInvPanelCels()
{
    if (gpHoradricCel)
    {
        ARCHIVE_FreeClientCellFile(gpHoradricCel);
        gpHoradricCel = 0;
    }
    if (gpCelInvArmor)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvArmor);
        gpCelInvArmor = 0;
    }
    if (gpCelInvBelt)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvBelt);
        gpCelInvBelt = 0;
    }
    if (gpCelInvBoots)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvBoots);
        gpCelInvBoots = 0;
    }
    if (gpCelInvHelmGlove)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvHelmGlove);
        gpCelInvHelmGlove = 0;
    }
    if (gpCelInvRingAmulet)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvRingAmulet);
        gpCelInvRingAmulet = 0;
    }
    if (gpCelInvWeapons)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvWeapons);
        gpCelInvWeapons = 0;
    }
    if (gpCelTradeBtn)
    {
        ARCHIVE_FreeClientCellFile(gpCelTradeBtn);
        gpCelTradeBtn = 0;
    }
    if (gpGoldButtonCel)
    {
        ARCHIVE_FreeClientCellFile(gpGoldButtonCel);
        gpGoldButtonCel = 0;
    }
    if (FOG_IsExpansion() && GAME_IsExpansion() && gpCelInvChar6Tab)
    {
        ARCHIVE_FreeClientCellFile(gpCelInvChar6Tab);
        gpCelInvChar6Tab = 0;
    }
    if (gpCelNpcInv)
    {
        ARCHIVE_FreeClientCellFile(gpCelNpcInv);
        gpCelNpcInv = 0;
    }
    if (gpCel_007BCE8C)
    {
        ARCHIVE_FreeClientCellFile(gpCel_007BCE8C);
        gpCel_007BCE8C = 0;
    }
    gpCelInvArmor = 0;
    gpCelInvBelt = 0;
    gpCelInvBoots = 0;
    gpCelInvHelmGlove = 0;
    gpCelInvRingAmulet = 0;
    gpCelInvWeapons = 0;
    gpCelTradeBtn = 0;
    gpGoldButtonCel = 0;
}

void __fastcall sub_M112_Emit_00486640(Unicode* pText)
{
    INV_AppendStringLine(pText);
}

// 0x00486AD0
void __cdecl INV_ToggleFlag()
{
    gbFlag_007BCC06 = gbFlag_007BCC06 == 0;
}

// 0x00486AE0
int __cdecl INV_GetPanelX()
{
    if (!GAME_IsExpansion())
    {
        return gnPanelOffsetX + 0x113;
    }
    return gnPanelOffsetX + 0x110;
}

// 0x00486B00
int __cdecl INV_GetPanelY()
{
    if (!GAME_IsExpansion())
    {
        return gnScreenHeight + gnPanelOffsetY - 0x41;
    }
    return gnScreenHeight + gnPanelOffsetY - 0x40;
}

// 0x00486B30
int __cdecl INV_IsTradeStateInteractive()
{
    switch (gnInvPanelMode)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
        return 0;
    }
    return 0;
}

// 0x00486B80
int __cdecl INV_IsNpcStateB()
{
    switch (gnInvPanelMode)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
    case 0x11:
        return 0;
    }
    return 0;
}

void __stdcall sub_Q05_Emit_00486370(D2ItemFormulaRecordStrc* pRecord, Unicode* pOut)
{
    Unicode wszBuffer[0x400];
    INV_AppendItemFormulaText(gpHoverItem, pRecord, wszBuffer);
    sub_005267E0(pOut, wszBuffer);
}

// 0x00486BD0
static void __stdcall INV_GetPlacementCell(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY)
{
    D2_ASSERT(pItem, 0x14E8);

    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);

    unsigned int nCelWidth;
    unsigned int nCelHeight;
    sub_004DBEA0(pItem, 0, 0, &nCelWidth, &nCelHeight);

    if (!(nWidth % 2))
    {
        nCellX = (nCelWidth / 4 - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
    }

    if (nWidth == pGrid->nGridX)
    {
        nCellX = pGrid->nGridX >> 1;
    }

    if (!(nHeight % 2))
    {
        nCellY = (nCelHeight / 4 - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
    }

    if (nHeight == pGrid->nGridY)
    {
        nCellY = pGrid->nGridY >> 1;
    }

    *pCellX = nCellX;
    *pCellY = nCellY;

    if (nWidth > 1)
    {
        nWidth >>= 1;
        *pCellX = D2_MAX(0, *pCellX - nWidth);
    }

    if (nHeight > 1)
    {
        nHeight >>= 1;
        *pCellY = D2_MAX(0, *pCellY - nHeight);
    }
}

// 0x00486D10
int __cdecl INV_CheckTradeClickDelay()
{
    if (!GAME_GetConnectionType() || GAME_GetConnectionType() == 1)
    {
        return 1;
    }
    if (sub_004B9180())
    {
        sub_004B90B0();
        return 0;
    }
    if (GetTickCount() - gdwTradeCheckTick > 0xFA)
    {
        gdwTradeCheckTick = GetTickCount();
        return 1;
    }
    return 0;
}

// 0x00486D70
int __cdecl INV_IsNotState11()
{
    return gnInvPanelMode != 0xB;
}

// 0x00486D80
int __cdecl INV_IsState1Or2()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2)
    {
        return 1;
    }
    return 0;
}

// 0x00486DA0
static int INV_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return 0;
    }
    if (nY >= gnScreenHeight + gnPanelOffsetY - 0x57 && nY <= gnScreenHeight + gnPanelOffsetY - 0x45
        && nX >= gnScreenWidth - gnPanelOffsetX - 0xED && nX <= gnScreenWidth - gnPanelOffsetX - 0xD9)
    {
        return 1;
    }
    return 0;
}

// 0x00486E10
int __fastcall INV_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnScreenWidth - gnPanelOffsetX - 0x12E || nX > gnScreenWidth - gnPanelOffsetX - 0x10E)
    {
        return 0;
    }
    if (nY < gnScreenHeight + gnPanelOffsetY - 0x60 || nY > gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 0;
    }
    return 1;
}

// 0x00486E60
static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        return;
    }
    if (nY > gnScreenHeight - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
    }
    if (sub_0045AE90() == 3 && gnInvPanelMode == 0 && nX < gnScreenWidth / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg)
{
    INV_ClickOutsidePanel(pMsg->nYpos, pMsg, pMsg->nXpos);
}

// 0x00486EF0
void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        if (INV_IsInNpcPanelRect(nX, nY))
        {
            UI_SetUIVar(1, 1, 0);
            return;
        }
        INVENTORY_GetCursorItem(pInventory);
    }
    if (gbInvGoldButtonDown && !gnInvPanelMode)
    {
        gbInvGoldButtonDown = 0;
        if (INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(1);
        }
    }
    GAME_ResetMouseButtons();
    if (INV_IsInPlayerInvRect(nX, nY) && !AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00487000
static void __stdcall INV_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid)
{
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    if (pCursorItem)
    {
        unsigned char nWidth;
        unsigned char nHeight;
        unsigned int nPixelWidth;
        unsigned int nPixelHeight;
        ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        sub_004DBEA0(pCursorItem, 0, 0, &nPixelWidth, &nPixelHeight);
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
        if (nWidth > 1)
        {
            nCellX -= nWidth / 2;
            if (nCellX < 0)
            {
                nCellX = 0;
            }
            if (nWidth + nCellX > pGrid->nGridX)
            {
                return;
            }
        }
        if (nHeight > 1)
        {
            nCellY -= nHeight / 2;
            if (nCellY < 0)
            {
                nCellY = 0;
            }
            if (nHeight + nCellY > pGrid->nGridY)
            {
                return;
            }
        }
        gnHoverCellY = nCellY;
        gnHoverCellX = nCellX;
        gbHoverInGrid = 1;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        return;
    }

    int nOutX;
    int nOutY;
    D2UnitStrc* pItem = INVENTORY_GetItemFromInventoryPage(pInventory, nCellX, nCellY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        gbHoverInGrid = 1;
        if (pItem == gpLastHoverItem)
        {
            return;
        }
        unsigned char nItemWidth;
        unsigned char nItemHeight;
        ITEMS_GetDimensions(pItem, &nItemWidth, &nItemHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        const int nItemX = CLIENTS_GetUnitX(pItem);
        const int nItemY = CLIENTS_GetUnitY(pItem);
        const int nLeft = nItemWidth * pGrid->nGridBoxWidth / 2 + pGrid->nGridBoxWidth * nItemX + pGrid->nGridLeft;
        const int nBoxHeight = pGrid->nGridBoxHeight;
        const int nGridTop = pGrid->nGridTop;
        gnHoverTopX = nLeft;
        gnHoverBottomX = nLeft;
        gpHoverItem = pItem;
        gpLastHoverItem = pItem;
        gnHoverTopY = nBoxHeight * nItemY + nGridTop;
        gnHoverBottomY = nBoxHeight * (nItemY + nItemHeight) + nGridTop;
        return;
    }
    gbHoverInGrid = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

// 0x00487230
static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gnHoverCellX = -1;
        gnHoverCellY = -1;
        gnHoverBodyLoc = nBodyLoc;
        gbHoverInBodyLoc = 1;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        return;
    }
    const int bTwoHanded = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, nBodyLoc);
    if ((nBodyLoc == 4 || nBodyLoc == 5) && bTwoHanded)
    {
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!pOther)
        {
            pOther = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 5);
        }
        if (pOther && pItem && !ITEMSIsA(pOther, 0x23) && !ITEMSIsA(pItem, 0x23)
            && !ITEMSIsA(pOther, 0x1B) && !ITEMSIsA(pItem, 0x1B))
        {
            pItem = pOther;
        }
        if (pOther && !pItem && gnInvPanelMode == 4)
        {
            pItem = pOther;
        }
    }
    if (pItem)
    {
        gbHoverInBodyLoc = 1;
        if (pItem == gpLastHoverItem)
        {
            return;
        }
        const int nLeft = (gaCompGrids[nBodyLoc].rect.nRight + gaCompGrids[nBodyLoc].rect.nLeft) / 2;
        gnHoverTopX = nLeft;
        gnHoverBottomX = nLeft;
        gpHoverItem = pItem;
        gpLastHoverItem = pItem;
        gnHoverTopY = gaCompGrids[nBodyLoc].rect.nTop;
        gnHoverBottomY = gaCompGrids[nBodyLoc].rect.nBottom;
        return;
    }
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

// 0x004873A0
void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        pMsg->bReturn = 0;
        return;
    }
    if (!gnDialogState)
    {
        pMsg->bReturn = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    int bHandled = 0;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && INV_IsInPlayerInvRect(nX, nY))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        int nBodyLoc = 0;
        if (nX >= gtPlayerInvGrid.nGridLeft && nX <= gtPlayerInvGrid.nGridRight && nY >= gtPlayerInvGrid.nGridTop && nY <= gtPlayerInvGrid.nGridBottom)
        {
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 0, &gtPlayerInvGrid);
            gnHoverBodyLoc = 0;
            gbHoverPlayerItem = 1;
            return;
        }
        for (; nBodyLoc < 11; ++nBodyLoc)
        {
            if (nX >= gaCompGrids[nBodyLoc].rect.nLeft && nX <= gaCompGrids[nBodyLoc].rect.nRight && nY >= gaCompGrids[nBodyLoc].rect.nTop && nY <= gaCompGrids[nBodyLoc].rect.nBottom)
            {
                INV_UpdateBodyLocHover(nBodyLoc, pPlayer, pInventory);
                gbHoverPlayerItem = 1;
                return;
            }
        }
        gnHoverBodyLoc = 0;
        pMsg->bReturn = 0;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xB)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (INV_IsInTradeOtherGrid(nX, nY))
        {
            gnSelectedTab = 1;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 1, &gtTradePage1Grid);
            bHandled = 1;
        }
        else if (INV_IsInTradeGrid(nX, nY))
        {
            gnSelectedTab = 2;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 2, &gtTradePage2Grid);
            bHandled = 1;
        }
        gnSelectedTab = nOldTab;
        if (!bHandled)
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xC)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483B40_IsInRect(nX, nY))
        {
            gnSelectedTab = 4;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            if (GAME_IsExpansion())
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBigBankGrid);
            }
            else
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBankGrid);
            }
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xE)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483BF0_IsInRect(nX, nY))
        {
            gnSelectedTab = 3;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 3, &gtCubeGrid);
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (GAME_GetUIVarState(0x24))
    {
        pMsg->bReturn = 0;
        return;
    }
    pMsg->bReturn = 0;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
    gbHoverPlayerItem = 0;
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

// 0x00487740
static int __stdcall INV_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
{
    int nOutX;
    int nOutY;
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
    unsigned int nGridX;
    unsigned int nGridY;
    if (!nPage)
    {
        nGridX = (nX - gtPlayerInvGrid.nGridLeft) / gtPlayerInvGrid.nGridBoxWidth;
        nGridY = (nY - gtPlayerInvGrid.nGridTop) / gtPlayerInvGrid.nGridBoxHeight;
    }
    else if (GAME_IsExpansion())
    {
        nGridX = (nX - gtBigBankGrid.nGridLeft) / gtBigBankGrid.nGridBoxWidth;
        nGridY = (nY - gtBigBankGrid.nGridTop) / gtBigBankGrid.nGridBoxHeight;
    }
    else
    {
        nGridX = (nX - gtBankGrid.nGridLeft) / gtBankGrid.nGridBoxWidth;
        nGridY = (nY - gtBankGrid.nGridTop) / gtBankGrid.nGridBoxHeight;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && sub_0062A0A0(pItem))
        {
            if (!ITEM_IsItemActionBlocked(pItem))
            {
                MSG_SendDword(0x4C, pItem->dwUnitId);
                ITEM_SetUninterruptableState(pItem);
                return 1;
            }
        }
        else if (ITEMS_CheckIfUseable(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
            {
                if (GAME_GetUIVarState(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gbCubeItemClicked = 1;
                }

                sub_004786D0_SendPacket(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                ITEM_SetUninterruptableState(pItem);
                sub_004B9A00(ITEM_GetItemUseSound(pItem), 0, 0, 0, 0);
                gbHoverInGrid = 0;
                return 1;
            }
        }
        else if (ITEMS_GetUniqueColumnFromItemsTxt(pItem))
        {
            D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            const int nCode = pTxt->dwCode;
            if (nCode == 0x20737274 || nCode == 0x20736B62 || nCode == 0x20646B62)
            {
                TEXT_OpenTextData(pItem, pTxt);
            }
            return 1;
        }
    }

    return 0;
}

// 0x00487990
void __cdecl INV_ResetHover()
{
    gnHoverTopX = -1;
    gnHoverTopY = -1;
    gnHoverBottomX = -1;
    gnHoverBottomY = -1;
    gnHoverCellX = -1;
    gnHoverCellY = -1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

// 0x00487A10
void __stdcall INV_SelectItemPageTab(unsigned char nTab)
{
    if (nTab >= 5)
    {
        nTab = 0;
    }
    if (gdwNpcPanelDelayTick)
    {
        return;
    }
    int nUnitId;
    if (!NPCMENU_GetInteractNpcId(&nUnitId))
    {
        return;
    }
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    int anCounts[5] = {};
    for (; pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        const unsigned char nPage = ITEMS_GetInvPage(INVENTORY_UnitIsItem(pItem));
        if (nPage < 5)
        {
            ++anCounts[nPage];
        }
    }

    int nTries = 0;
    gnSelectedTab = nTab;
// build: symbol ?gnNpcTabCount@* 0x00722158
    for (int i = 0; i < gnNpcTabCount; ++i)
    {
        *(int*)gaNpcTabStates[i].bSelected = 0;
        *(int*)gaNpcTabStates[i].bEnabled = anCounts[i] != 0;
    }

    if (!anCounts[nTab])
    {
        do
        {
            ++gnSelectedTab;
            ++nTries;
            if (gnSelectedTab > gnMaxTab || gnSelectedTab == 0xFF)
            {
                gnSelectedTab = 0;
            }
            if (anCounts[gnSelectedTab])
            {
                break;
            }
        }
        while (nTries < 4);
    }
    *(int*)gaNpcTabStates[gnSelectedTab].bSelected = 1;
}

// 0x00487B30
void __cdecl INV_ResetNpcState()
{
    gnInvPanelMode = 0;
    gnSelectedTab = 0;
    gbInvGoldButtonDown = 0;
    gnInvMouseX = 0;
    gnInvMouseY = 0;
    if (gpTradePanelCel)
    {
        ARCHIVE_FreeClientCellFile(gpTradePanelCel);
        gpTradePanelCel = 0;
    }
    gdwTradeCheckTick = 0;
}

extern "C" { int gRequest; } // 0x007BCC0C

// 0x00487B70
void __cdecl INV_SetRequest()
{
    gRequest = 1;
}

// 0x00487B80
void __cdecl INV_SetNpcStateTrade()
{
    gnSelectedTab = 0;
    gnInvPanelMode = 0x13;
}

int __stdcall sub_H19_Emit_00487740(D2UnitStrc* pPlayer, int nX, int nY)
{
    return INV_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
}

// 0x00487BA0
static void __stdcall INV_ForwardTradeClick(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!NPCMENU_HandleTradeClick((D2UnitStrc*)nArg1, (D2UnitStrc*)nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gnInvPanelMode = 5;
    CURSOR_SetCursorItemState(0);
}

// 0x00487BE0
int __cdecl INV_ResetNpcButtons()
{
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    return 1;
}

// 0x00487C20
void __cdecl INV_ResetNpcButtonsFromPending()
{
    if (gnInvPanelMode == 5)
    {
        gaNpcButtons[0].bActive = 0;
        gaNpcButtons[1].bActive = 0;
        gaNpcButtons[2].bActive = 0;
        gaNpcButtons[3].bActive = 0;
        gnInvPanelMode = 1;
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    }
}

// 0x00487C60
void __cdecl INV_AdvancePendingNpcState()
{
    D2_ASSERT(gnInvPanelMode == 5, 0x1EA1);
    gnInvPanelMode = 6;
}

// 0x00487CC0
void __cdecl INV_SelectFirstButton()
{
    gnSelectedShopButton = -1;
    for (int i = 0; i < gnButtonCount; ++i)
    {
        if (gaNpcButtons[i].bActive)
        {
            gnSelectedShopButton = i;
            break;
        }
    }
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

// 0x00487D30
void __cdecl INV_SetNpcStateMenuReturn()
{
    gnInvPanelMode = 7;
}

// 0x00487D40
void __cdecl INV_ResetButtonsFromMenuReturn()
{
    D2_ASSERT(gnInvPanelMode == 7, 0x1ED3);
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

void __cdecl sub_K04_EmitForward(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    INV_ForwardTradeClick(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7);
    sub_K04_EmitUse(nArg7);
}

// 0x00487DA0
static void INV_SetRepairAllButton(int nButton)
{
    gaNpcButtons[nButton].nTextId = 0x276F;
    gaNpcButtons[nButton].nMode = 1;
    gaNpcButtons[nButton].nArg = 8;
    gaNpcButtons[nButton].nKey = 0x12;
    gaNpcButtons[nButton].nId = 1;
}

// 0x00487DE0
static void INV_SetRepairButton(int nButton)
{
    gaNpcButtons[nButton].nTextId = 0xD0A;
    gaNpcButtons[nButton].nMode = 4;
    gaNpcButtons[nButton].nArg = 1;
    gaNpcButtons[nButton].nKey = 6;
    gaNpcButtons[nButton].nId = 1;
}

void __cdecl sub_M214_Emit_00487ED0()
{
    INV_SetRepairButton(2);
    INV_SetRepairAllButton(3);
}

// 0x00487E20
static void INV_SetBuyButton(int nButton)
{
    gaNpcButtons[nButton].nTextId = 0xD07;
    gaNpcButtons[nButton].nMode = 2;
    gaNpcButtons[nButton].nArg = 3;
    gaNpcButtons[nButton].nKey = 2;
    gaNpcButtons[nButton].nId = 1;
}

// 0x00487E60
static void INV_SetSellButton(int nButton)
{
    gaNpcButtons[nButton].nTextId = 0xD08;
    gaNpcButtons[nButton].nMode = 3;
    gaNpcButtons[nButton].nArg = 4;
    gaNpcButtons[nButton].nKey = 4;
    gaNpcButtons[nButton].nId = 1;
}

// 0x00487EA0
static __declspec(noinline) void INV_ClearButton(int nButton)
{
    gaNpcButtons[nButton].nTextId = 0;
    gaNpcButtons[nButton].nMode = 1;
    gaNpcButtons[nButton].nArg = 1;
    gaNpcButtons[nButton].nKey = 0;
    gaNpcButtons[nButton].nId = 0;
}

void __stdcall sub_00486BD0_Emit(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY)
{
    INV_GetPlacementCell(pItem, pGrid, nX, nY, pCellX, pCellY);
}

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

// 0x00487ED0
void __cdecl INV_SetupPanelButtons()
{
    const int bValue = NPCMENU_IsGambleShop();
    int nUnitId;
    if (!NPCMENU_GetInteractNpcId(&nUnitId))
        return;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pUnit)
        return;
    int bButton3Set = 0;
    if (bValue)
    {
        gnMaxTab = 1;
        INV_SetBuyButton(0);
        INV_SetSellButton(1);
        gaNpcButtons[2].nTextId = 0;
        gaNpcButtons[2].nMode = 1;
        gaNpcButtons[2].nArg = 1;
        gaNpcButtons[2].nKey = 0;
        gaNpcButtons[2].nId = 0;
    }
    else
    {
        switch (UNITS_GetWeaponClass(pUnit))
        {
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
            gnMaxTab = 3;
            INV_SetBuyButton(0);
            INV_SetSellButton(1);
            INV_ClearButton(2);
            break;

        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            gnMaxTab = 3;
            INV_SetBuyButton(0);
            INV_SetSellButton(1);
            gaNpcButtons[2].nTextId = 0xD0A;
            gaNpcButtons[2].nMode = 4;
            gaNpcButtons[2].nArg = 1;
            gaNpcButtons[2].nKey = 6;
            gaNpcButtons[2].nId = 1;
            gaNpcButtons[3].nTextId = 0x276F;
            gaNpcButtons[3].nMode = 1;
            gaNpcButtons[3].nArg = 8;
            gaNpcButtons[3].nKey = 0x12;
            gnButtonCount = 4;
            bButton3Set = 1;
            break;

        default:
            gnButtonCount = 0;
            return;
        }
    }

    if (!bButton3Set)
    {
        gaNpcButtons[3].nTextId = 0x1030;
        gaNpcButtons[3].nMode = 9;
        gaNpcButtons[3].nKey = 0xA;
        gnButtonCount = 4;
    }

    gaNpcButtons[3].nId = 1;
// build: symbol ?gnButtonRow@* 0x0072215C
    gnButtonRow = 3;
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
}

// 0x004880F0
void __cdecl INV_ClearClickPos()
{
    gnInvMouseX = 0;
    gnInvMouseY = 0;
}

// 0x00488100
void __fastcall INV_DrawGold(int nType)
{
    int nOldFont = D2Win_10127_SetFont(1);
    D2CelContextStrc tData = {};
    tData.nDirection = 0;

    int nGold;
    int nTextX;
    int nTextY;
    int nIconX;
    int nIconY;
    int nFrame;
    switch (nType)
    {
    case 0:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLDBANK, 0);
        nTextX = gnPanelOffsetX + 0xA5;
        if (GAME_IsExpansion())
        {
            nTextY = gnScreenHeight + gnPanelOffsetY - 0x1B8;
            nIconY = gnScreenHeight + gnPanelOffsetY - 0x1B6;
        }
        else
        {
            nTextY = gnScreenHeight + gnPanelOffsetY - 0xF4;
            nIconY = gnScreenHeight + gnPanelOffsetY - 0xF2;
        }
        nIconX = gnPanelOffsetX + 0x49;
        nFrame = gbGoldButtonDown_007BCE34 != 0;
        if (GAME_IsExpansion())
        {
            if (INV_IsMouseInBox(gnPanelOffsetX + 0x49, gnScreenHeight + gnPanelOffsetY - 0x1B6, 0x14, 0x12))
            {
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x101C), gnPanelOffsetX + 0x35, gnScreenHeight + gnPanelOffsetY - 0x1CA, 0, 0);
            }
        }
        else
        {
            if (INV_IsMouseInBox(gnPanelOffsetX + 0x49, gnScreenHeight + gnPanelOffsetY - 0xF2, 0x14, 0x12))
            {
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x101C), gnPanelOffsetX + 0x35, gnScreenHeight + gnPanelOffsetY - 0x106, 0, 0);
            }
        }
        break;

    case 1:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
        nTextX = gnScreenWidth - gnPanelOffsetX - 0xD4;
        nTextY = gnScreenHeight + gnPanelOffsetY - 0x48;
        nIconY = gnScreenHeight + gnPanelOffsetY - 0x45;
        nIconX = gnScreenWidth - gnPanelOffsetX - 0xED;
        nFrame = gbGoldButtonDown_007BCE30 != 0;
        break;

    default:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLDBANK, 0);
        nTextX = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xCF3)) + gnPanelOffsetX + 0x15;
        nTextY = gnScreenHeight + gnPanelOffsetY - 0x6A;
        nIconX = 0;
        nIconY = 0;
        nFrame = 0;
        break;
    }

    if (nType != 3)
    {
        Unicode wszGold[20] = {};
        char szGold[20];
        SStrPrintf(szGold, 20, szFmtD_006D57BC, nGold);
        sub_00526F20(wszGold, szGold, 19);
        if (nType == 2)
        {
            nTextX = gnPanelOffsetX - D2Win_10121_GetTextWidth(wszGold) + 0xC6;
        }
        D2Win_10117_DrawText(wszGold, nTextX, nTextY, 0, 0);
    }

    switch (nType)
    {
    case 0:
        if (gbGoldButtonDown_007BCE34)
        {
            ++nIconY;
        }
        nIconX += 2;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    case 1:
        if (gbGoldButtonDown_007BCE30)
        {
            ++nIconY;
        }
        nIconX += 1;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    default:
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xCF3), gnPanelOffsetX + 0x15, nTextY, 0, 0);
        break;
    }

    D2Win_10127_SetFont(nOldFont);
}

// 0x00488890
int __cdecl INV_IsNpcShopState()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3 || gnInvPanelMode == 4
        || gnInvPanelMode == 9)
    {
        return 1;
    }

    return 0;
}

// 0x004888C0
int __cdecl INV_CanUseCursor()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 4 || gnInvPanelMode == 3)
    {
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        if (INVENTORY_GetCursorItem(pInventory))
        {
            return 0;
        }
        const int nMode = sub_00468830();
        if (nMode == 7 || nMode == 1 || nMode == 4)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00488910
void __stdcall INV_ResetShopCursorMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if ((gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3 || gnInvPanelMode == 4 || gnInvPanelMode == 9)
        && !UI_GetUIVarUnchecked(5))
    {
        gbNpcUiRecordsLoaded = 0;
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory));
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gbPanelButtonClicked = 0;
        NPCMENU_CloseNpcShop();
        gnInvMouseX = 0;
        gnInvMouseY = 0;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        gnHoverTopX = -1;
        gnHoverTopY = -1;
        gnHoverBottomX = -1;
        gnHoverBottomY = -1;
        gnHoverCellX = -1;
        gnHoverCellY = -1;
    }
}

// 0x004889D0
void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0 || gnInvPanelMode == 1 || gnInvPanelMode == 3 || gnInvPanelMode == 2 || gnInvPanelMode == 4)
    {
        const int nY = pMsg->nYpos;
        const int nX = pMsg->nXpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (CURSOR_GetCursorItem() && nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
        {
            return;
        }
        int nUnitId;
        if (gnInvPanelMode && NPCMENU_GetInteractNpcId(&nUnitId))
        {
            D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
            if (pUnit)
            {
                D2InventoryStrc* pInventory = pUnit->pInventory;
                if (nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
                {
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    if (nX >= gtNpcInvGrid.nGridLeft && nX <= gtNpcInvGrid.nGridRight && nY >= gtNpcInvGrid.nGridTop && nY <= gtNpcInvGrid.nGridBottom)
                    {
                        INV_UpdateGridHover(pUnit, pInventory, 0, nX, nY, gnSelectedTab, &gtNpcInvGrid);
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        gbHoverPlayerItem = 0;
                        return;
                    }
                }
            }
        }
        INV_UpdateInventoryHover(pMsg);
    }
}

// 0x00488DF0
void __stdcall INV_ConsumeMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00488E10
static void INV_SelectButtonByKey(int nKey)
{
    gaNpcButtons[0].bActive = gaNpcButtons[0].nKey == nKey;
    gaNpcButtons[1].bActive = gaNpcButtons[1].nKey == nKey;
    gaNpcButtons[2].bActive = gaNpcButtons[2].nKey == nKey;
    gaNpcButtons[3].bActive = gaNpcButtons[3].nKey == nKey;
}

// 0x00488E70
void __stdcall INV_OpenChatKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (UI_GetUIVarUnchecked(5) || NPCMENU_IsAnyDialogOpen())
    {
        return;
    }
    if (!(pMsg->lParam & 0x40000000))
    {
        UI_SetUIVar(5, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00488EC0
void __stdcall INV_ShopKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if ((gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3 || gnInvPanelMode == 4
        || gnInvPanelMode == 9) && !(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 1;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00488F10
void __cdecl INV_RestoreSelectedShopButton()
{
    if (!INV_CanUseCursor())
    {
        return;
    }
    INV_ResetNpcButtons();
    if (gnSelectedShopButton >= 0 && gnSelectedShopButton < gnButtonCount && gaNpcButtons[gnSelectedShopButton].nTextId != 0x276F)
    {
        INV_SelectButtonByKey(gnSelectedShopButtonKey);
        gnInvPanelMode = gaNpcButtons[gnSelectedShopButton].nMode;
        sub_00468040(gaNpcButtons[gnSelectedShopButton].nArg, 0);
    }
    int nUnitId;
    if (NPCMENU_GetInteractNpcId(&nUnitId))
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
        if (pUnit)
        {
            const int nX = sub_00468730();
            const int nY = sub_00468740();
            if (nX >= gtNpcInvGrid.nGridLeft && nX <= gtNpcInvGrid.nGridRight && nY >= gtNpcInvGrid.nGridTop && nY <= gtNpcInvGrid.nGridBottom)
            {
                INV_UpdateGridHover(pUnit, pUnit->pInventory, 0, nX, nY, gnSelectedTab, &gtNpcInvGrid);
                gbHoverPlayerItem = 0;
            }
        }
    }
}

// 0x00489060
int __stdcall INV_InvRectClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if (nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
    {
        INV_UpdateInventoryHover(pMsg);
        return 1;
    }
    return 0;
}

// 0x00489190
int __fastcall INV_ClickNpcPanel(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (INV_IsInNpcPanelRect(nX, nY))
    {
        gbPanelButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

// 0x00489220
void __cdecl INV_LoadShopPanelCels()
{
    char szPath[0x104];
    if (!gpBuySellTabsCel)
    {
// build: symbol ?gszDataGlobal@* 0x006D4118
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\buyselltabs", gszDataGlobal);
        gpBuySellTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpMiniConvertCel)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\miniconvert", gszDataGlobal);
        gpMiniConvertCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpShopInvChar6TabCel && FOG_IsExpansion() && GAME_IsExpansion())
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\invchar6tab", gszDataGlobal);
        gpShopInvChar6TabCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

// 0x004892F0
void __cdecl INV_FreeNpcCels()
{
    if (gpTradePanelCel)
    {
        ARCHIVE_FreeClientCellFile(gpTradePanelCel);
        gpTradePanelCel = 0;
    }
    if (gpBuySellTabsCel)
    {
        ARCHIVE_FreeClientCellFile(gpBuySellTabsCel);
        gpBuySellTabsCel = 0;
    }
    if (gpMiniConvertCel)
    {
        ARCHIVE_FreeClientCellFile(gpMiniConvertCel);
        gpMiniConvertCel = 0;
    }
    if (GAME_IsExpansion() && gpShopInvChar6TabCel)
    {
        ARCHIVE_FreeClientCellFile(gpShopInvChar6TabCel);
        gpShopInvChar6TabCel = 0;
    }
}

// 0x00489360
void __fastcall INV_SetTradePanelOpen(int bOpen)
{
    char szPath[0x104];
    if (gbTradeAcceptedSelf || gbTradeAcceptedOther)
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    gbTradeAcceptedSelf = 0;
    gbTradeAcceptedOther = 0;
    gbInvGoldButtonDown = 0;
    if (bOpen)
    {
        gdwTradeCheckTick = 0;
        gnInvPanelMode = 0xB;
        PLAYER_SetPanelSlide(3);
        if (!gpTradePanelCel)
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\trade", gszDataGlobal);
            gpTradePanelCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }
    else
    {
        gnInvPanelMode = 0xA;
        PLAYER_SetPanelSlide(0);
    }
    gbPanelButtonClicked = 0;
    gbTradeAccepted = 0;
    gbTradeCancelClicked = 0;
    gbTradeAcceptButtonDown = 0;
    gbTradeCancelButtonDown = 0;
}

// 0x00489430
static int INV_IsOverTradeButtonLeft(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0xDF && nX < gnPanelOffsetX + 0xFF
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

// 0x00489480
static int INV_IsOverTradeButtonRight(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x133
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

// 0x00489580
void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xB)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        sub_004B8CB0();
        return;
    }
    if (!INV_IsInTradeGrid(nX, nY))
    {
        if (INV_IsOverTradeButtonLeft(nX, nY))
        {
            if (gbTradeAccepted && gbTradeAcceptButtonDown)
            {
                sub_004B9070(0);
            }
            gbPanelButtonClicked = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (INV_IsOverTradeButtonRight(nX, nY))
        {
            if (gbTradeCancelClicked && gbTradeCancelButtonDown)
            {
                sub_004B8CB0();
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbPanelButtonClicked = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
        {
            gbTradeAcceptButtonDown = 0;
            gbTradeAccepted = 0;
            gbPanelButtonClicked = 0;
            gbTradeCancelClicked = 0;
            return;
        }
        if (INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(2);
        }
        if (gbPanelButtonClicked)
        {
            const int bFlag = gbTradeAcceptButtonDown;
            gbPanelButtonClicked = 0;
            if (bFlag)
            {
                if (gbTradeAccepted == 1)
                {
                    gbTradeAccepted = 0;
                    sub_004B90B0_SendState();
                }
            }
            else if (gbTradeCancelButtonDown && gbTradeCancelClicked)
            {
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gbTradeAccepted)
    {
        sub_004B90B0_SendState();
    }
    gbPanelButtonClicked = 0;
    gbTradeCancelClicked = 0;
    gbTradeAccepted = 0;
}

// 0x00489770
void __stdcall INV_TradeBlockMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x004897A0
void __stdcall INV_TradeCancelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!UI_GetUIVarUnchecked(5))
            sub_004B8CB0();
    }
}

// 0x004897E0
void __fastcall INV_UpdateTradeAcceptSound(int bFirst, int bSecond)
{
    if ((gbTradeAcceptedSelf || gbTradeAcceptedOther) && (!bFirst || !bSecond))
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    else if ((!gbTradeAcceptedSelf && bFirst) || (bSecond && !gbTradeAcceptedOther))
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    gbTradeAcceptedSelf = bFirst;
    gbTradeAcceptedOther = bSecond;
}

// 0x00489840
int __cdecl INV_IsInvPanelTradeMode()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3)
    {
        return 1;
    }

    return 0;
}

// 0x00489860
int __cdecl INV_IsSellMode()
{
    return gnInvPanelMode == 4;
}

// build: symbol @EXCEPTIONS_FindModuleByAddress@* 0x0040BCB0
extern "C" RangeNode* __fastcall EXCEPTIONS_FindModuleByAddress(unsigned int address, RangeNode* node)
{
    while (node)
    {
        unsigned int start = node->start;
        if (address >= start && address < start + node->size)
            return node;
        node = node->next;
    }
    return 0;
}

extern "C" void __fastcall sub_00468040_SetMode(unsigned int value, unsigned int alternate)
{
    unsigned int result = alternate != 0;
    gValue_007A6ABC = 0;
    gValue_007A6ADC = 0x6;
    gValue_007A6AE0 = value;
    gValue_007A6AF0 = result + 0x7;
}

extern "C" unsigned int __fastcall sub_00479080_FindListValue(unsigned int key)
{
    LookupNode* node = gLookupHead_007BB5BC;
    while (node)
    {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return 0;
}

// build: symbol _CHAT_ResetChatHistory 0x0047BD30
extern "C" void __cdecl CHAT_ResetChatHistory()
{
    gValue_00712F44 = 0x7;
    gValue_00712F48 = 0x7;
    gValue_007BB5D8 = 0;
    gValue_007BB5E4 = 0;
    gValue_007BB5E8 = 0;
}

// 0x00489880
extern "C" void __cdecl INV_ReturnToStashState()
{
    bool transition = gValue_007BCBF0 == 0xD;
    gValue_007BCE2C = 0;
    if (transition)
        gValue_007BCBF0 = 0xC;
}

// 0x00489920
static int INV_IsOverCloseButton(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nY >= gnScreenHeight + gnPanelOffsetY - 0x1C7 && nY <= gnScreenHeight + gnPanelOffsetY - 0x1B6
            && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
        {
            return 1;
        }
    }
    else if (nY >= gnScreenHeight + gnPanelOffsetY - 0x103 && nY <= gnScreenHeight + gnPanelOffsetY - 0xF2
        && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
    {
        return 1;
    }
    return 0;
}

// 0x00489980
static int INV_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > INV_GetPanelX() && nX < INV_GetPanelX() + 0x28
        && nY > INV_GetPanelY() - 0x23 && nY < INV_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

// 0x00489A10
void __cdecl INV_CloseStashAndNotify()
{
    UI_SetUIVar(0x19, 1, 0);
    MSG_SendShorts(0x4F, 0x12, 0, 0);
}

// 0x00489A30
void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xC || gnInvPanelMode == 0xD)
    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (INV_IsInPlayerInvRect(nX, nY) || sub_00483B40_IsInRect(nX, nY))
        {
            INV_UpdateInventoryHover(pMsg);
            return;
        }
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        D2Win_10129_DrawFramedText(0, -1, -1, 0, 0);
    }
}

// 0x00489AC0
void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xC && gnInvPanelMode != 0xD)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if ((!HIREABLES_AreBeltRowsShown() || !AUTOMAP_IsCursorOverMiniPanelButton(pMsg)) && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        UI_SetUIVar(0x19, 1, 0);
        return;
    }
    if (INV_IsOverTransmuteButton(nX, nY))
    {
        if (gbStashButtonDown)
        {
            gbStashButtonDown = 0;
            UI_SetUIVar(0x19, 1, 0);
            MSG_SendShorts(0x4F, 0x12, 0, 0);
        }
        gbStashButtonClicked = 0;
        gbPanelButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gbStashButtonDown = 0;
    gbStashButtonClicked = 0;
    if (!HIREABLES_AreBeltRowsShown() && INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(3);
    }
    if (INV_IsOverCloseButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(4);
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    gbStashGoldButtonDown = 0;
    gbInvGoldButtonDown = 0;
    if (gbPanelButtonClicked)
    {
        const int bFlag = gbTradeAcceptButtonDown;
        gbPanelButtonClicked = 0;
        if (bFlag)
        {
            if (gbTradeAccepted == 1)
            {
                gbTradeAccepted = 0;
            }
        }
        else if (gbStashButtonClicked && gbStashButtonDown)
        {
            gbStashButtonDown = 0;
        }
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gbPanelButtonClicked = 0;
    gbStashButtonDown = 0;
    gbTradeAccepted = 0;
}

// 0x00489CE0
void __stdcall INV_StashCloseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xC)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!UI_GetUIVarUnchecked(5))
        {
            UI_SetUIVar(0x19, 1, 0);
            MSG_SendShorts(0x4F, 0x12, 0, 0);
            gnHoverTopX = -1;
            gnHoverTopY = -1;
            gnHoverBottomX = -1;
            gnHoverBottomY = -1;
            gnHoverCellX = -1;
            gnHoverCellY = -1;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
    }
}

// 0x00489D70
void __stdcall INV_KeyNoRepeatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00489DA0
void __fastcall INV_RecordStashUnitId(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwClassId : -1) != 267)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
    if (!pPlayerRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pPlayerRoom)) == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
    {
        gnStashObjectId = pUnit->dwUnitId;
    }
}

void __cdecl sub_J08_Emit_0048B540(D2UnitStrc* pUnit)
{
    sub_0048B0A0(pUnit);
    INV_DrawUnitEquippedItems(pUnit);
    INV_DrawMercEquipHighlights(pUnit);
}

// 0x00489E00
void __cdecl INV_OpenStashPanel()
{
    if (UI_SetUIVar(25, 0, 0))
    {
        gSelectionState = 0;
        CUNIT_ForEachObject(sub_00489DA0);
        gUiState = 12;
        GAME_ResetMouseState();
        gButtonA = 0;
        gButtonB = 0;
        gPressedFrame = 0;
        gButtonLatch = 0;
    }
}

// 0x00489E50
void __cdecl INV_LoadStashPanelCels()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpBankCel)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\bank", gszDataGlobal);
        gpBankCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        if (FOG_IsExpansion())
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\TradeStash", gszDataGlobal);
            gpTradeStashCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }
}

// 0x00489EE0
void __cdecl INV_CloseStashPanel()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        UI_SetUIVar(25, 1, 0);
        sub_00478600(79, 18, 0, 0);
    }
    if (gArchiveA)
    {
        ARCHIVE_FreeClientCellFile(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        ARCHIVE_FreeClientCellFile(gArchiveB);
        gArchiveB = 0;
    }
}

// 0x00489F50
void __cdecl INV_ResetStashPanel()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        UI_SetUIVar(25, 1, 0);
    }
    if (gArchiveA)
    {
        ARCHIVE_FreeClientCellFile(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        ARCHIVE_FreeClientCellFile(gArchiveB);
        gArchiveB = 0;
    }
}

// 0x00489FB0
static int INV_IsOverButtonC(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x13B
        && nY > gnScreenHeight + gnPanelOffsetY - 0x64 && nY < gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        return 1;
    }
    return 0;
}

int __fastcall sub_E19_Emit_00487000(D2UnitStrc* pPlayer, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid)
{
    INV_UpdateGridHover(pPlayer, pPlayer->pInventory, pCursorItem, nX, nY, nPage, pGrid);
    return gnHoverTopX + gnHoverTopY + gnHoverBottomX + gnHoverBottomY + gnHoverCellX + gnHoverCellY
        + gbHoverInGrid + (gpHoverItem == gpLastHoverItem);
}

// 0x0048A000
static int INV_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x90 && nX < gnPanelOffsetX + 0xB8
        && nY > gnScreenHeight + gnPanelOffsetY - 0xDF && nY < gnScreenHeight + gnPanelOffsetY - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x0048A050
void __cdecl INV_CloseCubePanel()
{
    gbQuestTimerActive = 0;
    UI_SetUIVar(0x1A, 1, 0);
    if (!gbCubeClosed)
    {
        MSG_SendShorts(0x4F, 0x17, 0, 0);
        gbCubeClosed = 1;
    }
    if (gbCubeItemClicked)
    {
        if (CUNIT_FindClientUnit(gnStashObjectId, 2))
        {
            sub_00480930(2, gnStashObjectId);
        }
        gbCubeItemClicked = 0;
    }
}

// 0x0048A0D0
void __cdecl INV_SendTransmute()
{
    MSG_SendShorts(0x4F, 0x18, 0, 0);
}

static inline int InRect(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX < nRight && nY >= nTop && nY <= nBottom;
}

// 0x0048A0F0
void __stdcall INV_CubeMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xE)
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if (InRect(nX, nY, gnGlobal_007BCAA0, gnGlobal_007BCAA4, gnGlobal_007BCAA8, gnGlobal_007BCAAC)
        || InRect(nX, nY, gnGlobal_007BCB74, gnGlobal_007BCB78, gnGlobal_007BCB7C, gnGlobal_007BCB80))
    {
        INV_UpdateInventoryHover(pMsg);
    }
    else
    {
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        D2Win_10129_DrawFramedText(0, -1, -1, 0, 0);
    }
}

// 0x0048A190
void __stdcall INV_CubeClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xE)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!HIREABLES_AreBeltRowsShown() && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        UI_SetUIVar(0x1A, 1, 0);
        return;
    }
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x13B
        && nY > gnScreenHeight + gnPanelOffsetY - 0x64 && nY < gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        if (gbCubeButtonDown)
        {
            gbCubeButtonDown = 0;
            INV_CloseCubePanel();
        }
        gbPanelButtonClicked = 0;
        gbCubeButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverCubeButton(nX, nY))
    {
        if (gbCubeCloseButtonDown)
        {
            gbCubeCloseButtonDown = 0;
            MSG_SendShorts(0x4F, 0x18, 0, 0);
        }
        gbCubeCloseClicked = 0;
        gbPanelButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gbCubeButtonDown = 0;
    gbCubeButtonClicked = 0;
    gbCubeCloseButtonDown = 0;
    gbCubeCloseClicked = 0;
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbTradeAcceptButtonDown = 0;
        gbCubeButtonClicked = 0;
        gbCubeCloseClicked = 0;
        return;
    }
    if (INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(1);
    }
    gbInvGoldButtonDown = 0;
    if (gbPanelButtonClicked)
    {
        const int bFlag = gbTradeAcceptButtonDown;
        gbPanelButtonClicked = 0;
        if (bFlag)
        {
            if (gbTradeAccepted)
                gbTradeAccepted = 0;
        }
        else if (gbCubeButtonClicked)
        {
            if (gbCubeButtonDown)
                gbCubeButtonDown = 0;
        }
        else if (gbCubeCloseClicked && gbCubeCloseButtonDown)
        {
            gbCubeCloseButtonDown = 0;
        }
        gbTradeAcceptButtonDown = 0;
        gbCubeCloseClicked = 0;
        gbCubeButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gbPanelButtonClicked = 0;
    gbCubeButtonDown = 0;
    gbCubeCloseButtonDown = 0;
    gbTradeAccepted = 0;
}

// 0x0048A3B0
void __stdcall INV_CubeBlockMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0048A3E0
void __stdcall INV_CubeCloseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!GAME_GetUIVarState(1))
        {
            gnHoverTopX = -1;
            gnHoverTopY = -1;
            gnHoverBottomX = -1;
            gnHoverBottomY = -1;
            gnHoverCellX = -1;
            gnHoverCellY = -1;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        if (!UI_GetUIVarUnchecked(5))
            INV_CloseCubePanel();
    }
}

// 0x0048A460
void __cdecl INV_OpenCubePanel()
{
    if (UI_SetUIVar(0x1A, 0, 0))
    {
        gbCubeClosed = 0;
        gnInvPanelMode = 0xE;
        GAME_ResetMouseState();
        gbInvGoldButtonDown = 0;
        gbCubeButtonDown = 0;
        gbCubeButtonClicked = 0;
        gbCubeCloseButtonDown = 0;
        gbCubeCloseClicked = 0;
    }
}

// 0x0048A4B0
void __cdecl INV_LoadCubePanelCel()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpSuperTransmogrifierCel)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\supertransmogrifier", gszDataGlobal);
        gpSuperTransmogrifierCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

void __cdecl sub_00494EB0_DrawUiRectangle()
{
    InitializePalette();
    D2GFX_DrawBox(0, 0, gScreenWidth, gScreenHeight - 49, gColor, 1);
}

// 0x0048A500
void __cdecl INV_ShutdownCubePanel()
{
    if (gUiState == 14)
    {
        gUiState = 0;
        INV_CloseCubePanel();
    }
    if (gUiArchive)
    {
        ARCHIVE_FreeClientCellFile(gUiArchive);
        gUiArchive = 0;
    }
}

// 0x0048A540
void __fastcall INV_QuestCodeUpdate(int nCode)
{
    char szPath[0x104];
    D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
    if (nCode == 0x20747368)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 10, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 10, 11);
    }
    else if (nCode == 0x20326671)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 18, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 18, 11);
    }
    gbQuestTimerActive = 1;
    gnQuestTimerValue = 0;
    gdwQuestTimerTicks = GetTickCount();
    if (!gpHoradricCel)
    {
        SStrPrintf(szPath, 0x104, "%s\\ui\\menu\\horadric", gszDataGlobal);
        gpHoradricCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

// 0x0048A600
void __cdecl INV_FreeHoradricCel()
{
    if (gpHoradricCel)
    {
        ARCHIVE_FreeClientCellFile(gpHoradricCel);
        gpHoradricCel = 0;
    }
    gbQuestTimerActive = 0;
    gnQuestTimerValue = 0;
    gdwQuestTimerTicks = 0;
}

// 0x0048A630
void __cdecl INV_EnterNpcMenuState()
{
    gnInvPanelMode = 1;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    D2ClientRecordStrc tRecord;
    tRecord.nId = 0x5A;
    tRecord.nFlag = 1;
    *(int*)&tRecord.nValue0 = 0;
    tRecord.nType = 0x0E;
    sub_0049EB10_PostRecord(&tRecord);
}

// 0x0048A680
void __cdecl INV_ClearPanelPage()
{
    gnGlobal_007BCAF0 = 0;
}

// 0x0048A690
int __cdecl INV_HasHoverItem()
{
    return gpHoverItem != 0;
}

// 0x0048A6A0
void __cdecl INV_ResetNpcCursor()
{
    gbPanelButtonClicked = 0;
    gnInvPanelMode = 0;
    gnInvMouseX = 0;
    gnInvMouseY = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || !INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        CURSOR_SetCursorItemState(0);
    }
}

// 0x0048A6E0
extern "C" void __cdecl INV_SetTradeFlag()
{
    gbTradeFlag = 1;
}

// 0x0048A6F0
void __cdecl INV_ClearTradeFlag()
{
    gbTradeFlag = 0;
}

// build: symbol ?GRID_UnlockCDKeys@* 0x005239C0
void __cdecl GRID_UnlockCDKeys()
{
    if (gResourceA)
    {
        ReleaseResource(gResourceA);
        gResourceA = 0;
    }
    if (gResourceB)
    {
        ReleaseResource(gResourceB);
        gResourceB = 0;
    }
}

// 0x0048A700
void __cdecl INV_ToggleWeaponSwitch()
{
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        gbWeaponSwitch = !gbWeaponSwitch;
    }
}

// 0x0048A730
void __cdecl INV_ResetEquipSounds()
{
    if (!FOG_IsExpansion() || !GAME_IsExpansion())
    {
        return;
    }
    sub_004B9A00(1, 0, 0, 0, 0);
    MSG_SendHeaderOnly(0x60);
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pItem)
    {
        ITEM_SetUninterruptableState(pItem);
    }
    pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pItem)
    {
        ITEM_SetUninterruptableState(pItem);
    }
}

// 0x0048A790
int __stdcall INV_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

// 0x0048A7D0
void __stdcall INV_DrawUnitName(D2UnitStrc* pUnit)
{
    unsigned short wszNameBuf[32];
    Unicode* wszName = (Unicode*)wszNameBuf;
    for (int i = 0; i < 32; ++i)
    {
        wszName[i].wChar = 0;
    }
    const int nOldFont = D2Win_10127_SetFont(6);
    Unicode::strncpy(wszName, CUNIT_GetUnitName(pUnit), 32);
    wszName[31].wChar = 0;
    Unicode* pEnd = &wszName[31];
    while (D2Win_10121_GetTextWidth(wszName) > 0xA0)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    D2Win_10117_DrawText(wszName, gnPanelOffsetX + 0xF, 0xD6 - gnPanelOffsetY, 0, 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x0048A890
void __cdecl INV_DrawPanelLabels()
{
    const int nOldFont = D2Win_10127_SetFont(6);
    for (int i = 0; i < sizeof(gaPanelLabels) / sizeof(gaPanelLabels[0]); ++i)
    {
        unsigned short wszTextBuf[100];
        Unicode* wszText = (Unicode*)wszTextBuf;
        for (int j = 0; j < 100; ++j)
        {
            wszText[j].wChar = 0;
        }
        Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(gaPanelLabels[i].nString), 99);
        wszText[99].wChar = 0;
        const int nLeft = gaPanelLabels[i].nX + gnPanelOffsetX;
        const int nRight = gaPanelLabels[i].nX2 + gnPanelOffsetX;
        const int nY = gaPanelLabels[i].nY - gnPanelOffsetY;
        Unicode* pSecond;
        if (sub_004A7660_SplitAtNewLine(wszText, &pSecond))
        {
            TEXT_DrawCenteredText(nLeft, nY - 4, nRight, wszText, 0);
            TEXT_DrawCenteredText(nLeft, nY + 4, nRight, pSecond, 0);
        }
        else if (nRight)
        {
            TEXT_DrawCenteredText(nLeft, nY, nRight, wszText, 0);
        }
        else
        {
            D2Win_10117_DrawText(wszText, nLeft, nY, 0, 0);
        }
    }
    D2Win_10127_SetFont(nOldFont);
}

void __stdcall sub_E05_Emit_Tooltip(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxt, int nValue, Unicode* pText)
{
    INV_AppendEtherealSocketed(pItem, pText);
    INV_AppendQuantity(pItemsTxt, pItem, pText + 0x100);
    INV_AppendDurability(pItem, pText + 0x200);
    INV_AppendLabeledNumber(nValue, pText + 0x300);
    INV_AppendReqStr(pItemsTxt, nValue, pText + 0x400);
    INV_AppendReqDex(pItemsTxt, nValue, pText + 0x500);
    INV_AppendThrowDamage(pItem, pItemsTxt, pText + 0x600);
    INV_AppendStackQuantity(pItem, pText + 0x700);
    INV_AppendBlockChance(pText + 0x800, pItemsTxt, pItem);
    INV_AppendAttackSpeed(pText + 0x900, pItem);
}

struct D2SkillStrc;

// 0x0048A990
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

        const int nLeft = gaMercStatLines[i].nLeft + gnPanelOffsetX;
        const int nRight = gaMercStatLines[i].nRight + gnPanelOffsetX;
        int nY = gaMercStatLines[i].nY - gnPanelOffsetY - 2;

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

// 0x0048B0A0
void __stdcall INV_DrawMercEmptyBodyLocs(D2UnitStrc* pUnit)
{
    D2CelContextStrc tGfx;
    memset(&tGfx, 0, sizeof(tGfx));

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory || !INVENTORY_GetItemFromBodyLoc(pInventory, 3))
    {
        tGfx.pCellFile = gpTorsoCell_007BCE68;
        tGfx.nFrame = 0;
        TEXTURE_CelDraw(&tGfx, gnRectTorsoLeft + gtOffsetTorso.nX, gnRectTorsoBottom + gtOffsetTorso.nY, -1, 5, 0);
    }

    if (!pInventory || !INVENTORY_GetItemFromBodyLoc(pInventory, 1))
    {
        tGfx.pCellFile = gpHeadCell_007BCE74;
        tGfx.nFrame = 1;
        TEXTURE_CelDraw(&tGfx, gnRectHeadLeft + gtOffsetHead.nX, gnRectHeadBottom + gtOffsetHead.nY, -1, 5, 0);
    }

    D2UnitStrc* pRightItem = pInventory ? INVENTORY_GetItemFromBodyLoc(pInventory, 4) : 0;
    D2UnitStrc* pLeftItem = pInventory ? INVENTORY_GetItemFromBodyLoc(pInventory, 5) : 0;
    int bTwoHanded = pInventory ? INVENTORY_GetWieldType(pUnit, pInventory) == 2 : 0;

    if (!pLeftItem)
    {
        tGfx.pCellFile = gpArmCell_007BCE7C;
        tGfx.nFrame = 0;
        if (pRightItem)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tGfx, gnRectLArmLeft + gtOffsetLArm.nX, gnRectLArmBottom + gtOffsetLArm.nY, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tGfx, gnRectLArmLeft + gtOffsetLArm.nX, gnRectLArmBottom + gtOffsetLArm.nY, -1, 5, 0);
        }
    }

    if (!pRightItem)
    {
        tGfx.pCellFile = gpArmCell_007BCE7C;
        tGfx.nFrame = 0;
        if (pLeftItem)
        {
            if (!bTwoHanded)
            {
                TEXTURE_CelDraw(&tGfx, gnRectRArmLeft + gtOffsetRArm.nX, gnRectRArmBottom + gtOffsetRArm.nY, -1, 5, 0);
            }
        }
        else
        {
            TEXTURE_CelDraw(&tGfx, gnRectRArmLeft + gtOffsetRArm.nX, gnRectRArmBottom + gtOffsetRArm.nY, -1, 5, 0);
        }
    }
}

// 0x0048B290
static int __stdcall INV_CanMercEquipItem(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pbSlotMatch)
{
    *pbSlotMatch = 0;
    if (!GAME_IsExpansion())
        return 0;
    int bResult = 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x302C, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x302F, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMSIsA(pItem, 3) || ITEMSIsA(pItem, 0x25))
    {
        bResult = 1;
        *pbSlotMatch = bResult;
    }
    switch (ROSTERPETS_GetHirelingClassId(!pUnit ? -1 : pUnit->dwUnitId))
    {
    case 0x10F:
        if (ITEMSIsA(pItem, 0x1B))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x152:
        if (ITEMSIsA(pItem, 0x21) || ITEMSIsA(pItem, 0x22))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x167:
        if (ITEMSIsA(pItem, 2))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x230:
        if (ITEMSIsA(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x231:
        if (ITEMSIsA(pItem, 0x1E))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    }
    if (bResult && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
        bResult = 0;
    return bResult;
}

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

// 0x0048B3F0
void __fastcall INV_DrawMercEquipHighlights(D2UnitStrc* pUnit)
{
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory);
    if (!pCursorItem)
        return;
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects[i].rect.nLeft > 0 && IsCursorInRectInline(gaBodyLocRects[i].rect.nLeft, gaBodyLocRects[i].rect.nTop, gaBodyLocRects[i].rect.nRight, gaBodyLocRects[i].rect.nBottom))
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            int bMatch;
            if (ITEMS_CheckBodyLocation(pCursorItem, i) && INV_CanMercEquipItem(pUnit, pCursorItem, &bMatch) && ITEMS_CheckRequirements(pCursorItem, pUnit, 0, 0, 0, 0))
                DrawBodyLocRectInline(&gaBodyLocRects[i], gbGlobal_007BCAD9);
            else
                DrawBodyLocRectInline(&gaBodyLocRects[i], gabInvHighlightColors);
        }
    }
}

// 0x0048B540
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
            const int nX = gaBodyLocRects[i].rect.nLeft
                + (gaBodyLocRects[i].nWidth - nWidth * gtHirelingInvGrid.nGridBoxWidth) / 2;
            const int nY = gaBodyLocRects[i].rect.nTop
                + (gaBodyLocRects[i].nHeight - nHeight * gtHirelingInvGrid.nGridBoxWidth) / 2;
            sub_0046EE80_DrawCursorItem(pItem, nX, nY);
            if (gpHoverItem == pItem && ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0
                && ITEMS_CheckItemFlag(pItem, 0x800, 0x30C8, ".\\UI\\inv.cpp"))
            {
                sub_00483E40(pItem, &gtHirelingInvGrid, nX, nY);
            }
        }
    }
}

// 0x0048B640
D2UnitStrc* __cdecl INV_GetMercUnit()
{
    const int nPetId = ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pMerc = CUNIT_FindClientUnit(nPetId, 1);
        if (pMerc)
        {
            return pMerc;
        }
    }
    UI_SetUIVar(0x24, 2, 0);
    return 0;
}

// 0x0048B680
void __stdcall INV_MercPanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    if (!CUNIT_FindClientUnit(nPetId, 1))
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    pMsg->bReturn = 0;
    if (!IsCursorInRectInline(0, 0, gnScreenWidth / 2, gnScreenHeight - 0x31))
    {
        return;
    }

    if (IsCursorInRectInline(gnPanelOffsetX + 0x110, gnPanelOffsetY + gnScreenHeight - 0x5F, gnPanelOffsetX + 0x130, gnPanelOffsetY + gnScreenHeight - 0x3F))
    {
        gbBuySellPressed = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

static inline int INV_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x0048B7C0
void __stdcall INV_MercInvClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
    if (!pPet)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    pMsg->bReturn = 0;
    sub_00467FA0(pMsg);
    gbBuySellPressed = 0;
    if (!IsCursorInRectInline(0, 0, gnScreenWidth / 2, gnScreenHeight - 0x31))
    {
        return;
    }

    if (IsCursorInRectInline(gnPanelOffsetX + 0x110, gnPanelOffsetY + gnScreenHeight - 0x5F, gnPanelOffsetX + 0x130, gnPanelOffsetY + gnScreenHeight - 0x3F))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory);
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects[i].rect.nLeft > 0 && IsCursorInRectInline(gaBodyLocRects[i].rect.nLeft, gaBodyLocRects[i].rect.nTop, gaBodyLocRects[i].rect.nRight, gaBodyLocRects[i].rect.nBottom))
        {
            if (pCursorItem)
            {
                int bSlotMatch = 0;
                if (ITEMS_CheckBodyLocation(pCursorItem, i) && ITEMS_CheckRequirements(pCursorItem, pPet, 0, 0, 0, 0) && INV_CanMercEquipItem(pPet, pCursorItem, &bSlotMatch))
                {
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    MSG_SendWord(0x61, 0);
                }
                else if (ITEMS_CheckBodyLocation(pCursorItem, i) && INV_CanMercEquipItem(pPet, pCursorItem, &bSlotMatch) && bSlotMatch)
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x56);
                }
                else
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x55);
                }

                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }

            if (pPet->pInventory)
            {
                D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPet->pInventory, i);
                if (pItem)
                {
                    ITEM_SetUninterruptableState(pItem);
                    MSG_SendWord(0x61, i);
                    gbHoverInGrid = 0;
                    gbHoverInBodyLoc = 0;
                    gpHoverItem = 0;
                }
            }
        }
    }

    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0048BA50
void __stdcall INV_MercPanelHoverMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
    if (!pPet)
    {
        UI_SetUIVar(0x24, 2, 0);
        return;
    }

    pMsg->bReturn = 0;
    if (!IsCursorInRectInline(0, 0, gnScreenWidth / 2, gnScreenHeight - 0x31))
    {
        return;
    }

    if (gbBuySellPressed && !INV_IsCursorInRect(gnPanelOffsetX + 0x110, gnPanelOffsetY + gnScreenHeight - 0x5F, gnPanelOffsetX + 0x130, gnPanelOffsetY + gnScreenHeight - 0x3F))
    {
        gbBuySellPressed = 0;
    }

    D2InventoryStrc* pInventory = pPet->pInventory;
    if (!pInventory)
    {
        return;
    }

    INV_ResetHover();
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return;
    }

    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects[i].rect.nLeft > 0 && INV_IsCursorInRect(gaBodyLocRects[i].rect.nLeft, gaBodyLocRects[i].rect.nTop, gaBodyLocRects[i].rect.nRight, gaBodyLocRects[i].rect.nBottom))
        {
            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
            if (pItem)
            {
                gbHoverInBodyLoc = 1;
                if (pItem != gpLastHoverItem)
                {
                    gpHoverItem = pItem;
                    gnHoverTopX = (gaBodyLocRects[i].rect.nLeft + gaBodyLocRects[i].rect.nRight) / 2;
                    gnHoverBottomX = gnHoverTopX;
                    gnHoverTopY = gaBodyLocRects[i].rect.nTop;
                    gnHoverBottomY = gaBodyLocRects[i].rect.nBottom;
                    gpLastHoverItem = pItem;
                }
            }
        }
    }
}

// 0x0048BBE0
void __fastcall INV_OpenRecipeScroll(const Unicode* wszName, int nUnused, int nArg)
{
    sub_005267E0(gwszRecipeScrollText, wszName);
    gnRecipeScrollColor = nArg;
    UI_SetUIVar(0x25, 0, 0);
}

// 0x0048BD80
void __stdcall INV_CloseRecipeScrollClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMaxY = gnScreenHeight - 0x31;
    const int nHalfWidth = gnScreenWidth / 2;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= 0 && nX <= nHalfWidth && nY >= 0 && nY <= nMaxY)
    {
        UI_SetUIVar(0x25, 1, 0);
        GAME_ResetMouseButtons();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0048BE00
void __fastcall INV_CutBracketToken(Unicode* pString, const Unicode* pToken)
{
    Unicode wszOpen[2] = { '[', 0 };
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    Unicode* pFound = sub_00526940_UnicodeStrStr(pString, pToken);
    if (pFound)
    {
        pFound += 4;
        const int nLength = sub_00526800(pFound);
        Unicode::strncpy(wszText, pFound, nLength - sub_00526800(sub_00526940_UnicodeStrStr(pFound, wszOpen)));
        sub_005267E0(pString, wszText);
    }
}

void __fastcall sub_Z12_EmitCanHirelingEquipItem(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bMatch;
    const int bCan = INV_CanMercEquipItem(pUnit, pItem, &bMatch);
    sub_Z12_EmitUse2(bCan, bMatch);
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

#pragma pack(push, 1)

struct D2LevelTextStrc
{
    char c00;
    int n01;
    int n05;
    int n09;
    int n0D;
    char c11;
};

#pragma pack(pop)

#define WSZ(a) ((Unicode*)(a))

#define SZ(a) ((char*)(a))

struct D2BitBufferStrc;

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048C060
void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pOut, int nMaxLen)
{
    if (pItem)
    {
        D2ItemsTxt* pItemsTxt;
        const Unicode* pStrF9B;
        const Unicode* pNewLine;
        int nItemType;
        int nLen;

        Unicode aPrefix[0x200];
        Unicode aSuffix[0x200];
        Unicode aLine[0x200];

        pStrF9B = D2LANG_GetStringFromTblIndex(0xF9B);
        pNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
        nLen = 0;
        pItemsTxt = DATATBLS_GetItemsTxtRecord(UNITS_GetWeaponClass(pItem));
        D2_ASSERT(pItemsTxt, 0x732);

        nItemType = ITEMS_GetItemType(pItem);
        if (ITEMS_CheckItemFlag(pItem, 0x4000000, 0x735, ".\\UI\\inv.cpp"))
        {
            Unicode aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(WSZ(aPrefix), INV_SkipBracketTag(WSZ(aName)));
            sub_00526700(WSZ(aPrefix), pNewLine);
            const Unicode* pRuneName = D2LANG_GetStringFromTblIndex(ITEMS_GetPrefixId(pItem, 0));
            if (pRuneName)
            {
                sub_005267E0(WSZ(aSuffix), pRuneName);
            }
            else
            {
                sub_005267E0(WSZ(aSuffix), pStrF9B);
            }
            sub_00526700(WSZ(aLine), WSZ(aSuffix));
            INV_PrefixColorCode(WSZ(aLine), 4);
            sub_00526700(pOut, WSZ(aPrefix));
            sub_00526700(pOut, WSZ(aLine));
        }
        else if (ITEMS_CheckItemFlag(pItem, 0x10, 0x748, ".\\UI\\inv.cpp"))
        {
            switch (ITEMS_GetItemQuality(pItem))
            {
            case ITEMQUAL_INFERIOR:
            {
                D2LowQualityItemsTxt* pLowQuality = DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pLowQuality)
                {
                    INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B0), D2LANG_GetStringFromTblIndex(pLowQuality->wTblId), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                }
                break;
            }
            case ITEMQUAL_NORMAL:
            {
                if (!ITEMSIsA(pItem, 0x16) && !ITEMSIsA(pItem, 0x12))
                {
                    if (ITEMSIsA(pItem, 7))
                    {
                        char szLevel[18] = { 0 };
                        Unicode aEarName[0x100];
                        Unicode aLevelText[3];
                        SStrPrintf(szLevel, 3, "%d", ITEMS_GetEarLevel(pItem));
                        sub_00526F20(WSZ(aLevelText), szLevel, 3);
                        Unicode aUnused[0x100];
                        char aName[20];
                        strcpy(SZ(aName), ITEMS_GetEarName(pItem));
                        sub_00526F20(WSZ(aEarName), SZ(aName), 0x100);
                        if (ITEMS_CheckItemFlag(pItem, 0x8000, 0x775, ".\\UI\\inv.cpp"))
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x1406));
                            sub_00526700(pOut, pNewLine);
                            sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        else
                        {
                            sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0x102D));
                            sub_00526700(pOut, pStrF9B);
                        }
                        sub_00526700(pOut, WSZ(aLevelText));
                        sub_00526700(pOut, pNewLine);
                        sub_00526700(pOut, INV_GetClassNameText(ITEMS_GetFileIndex(pItem)));
                        sub_00526700(pOut, pNewLine);
                        Unicode aText[100] = { 0 };
                        Unicode aFormat[0x200];
                        sub_005267E0(WSZ(aFormat), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                        sub_005272B0_FormatText(WSZ(aText), WSZ(aEarName), WSZ(aFormat), 100, STRTABLE_GetLanguage());
                        sub_00526700(pOut, WSZ(aText));
                    }
                    else if (ITEMSIsA(pItem, 0x28))
                    {
                        D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(ITEMS_GetFileIndex(pItem));
                        INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B4), D2LANG_GetStringFromTblIndex(pMonStatsTxt->wNameStr), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                    }
                    else
                    {
                        D2InventoryStrc* pInventory = pItem->pInventory;
                        if (ITEMS_CheckItemFlag(pItem, 0x800, 0x799, ".\\UI\\inv.cpp") && pInventory && INVENTORY_GetItemCount(pInventory))
                        {
                            INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B3), D2LANG_GetStringFromTblIndex(0x6C0), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                        }
                        else
                        {
                            Unicode aName[0x200];
                            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                            sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                        }
                    }
                }
                else
                {
                    switch (ITEMS_GetSuffixId(pItem, 0))
                    {
                    case 0:
                    {
                        int nString = 0x897;
                        if (nItemType != ITEMTYPE_BOOK)
                        {
                            nString = 0x898;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    case 1:
                    {
                        int nString = 0x899;
                        if (nItemType != ITEMTYPE_BOOK)
                        {
                            nString = 0x89A;
                        }
                        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(nString));
                    }
                        break;
                    }
                }
                break;
            }
            case ITEMQUAL_SUPERIOR:
                INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6AF), D2LANG_GetStringFromTblIndex(0x6BF), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), 0);
                break;
            case ITEMQUAL_RARE:
            case ITEMQUAL_CRAFT:
            case ITEMQUAL_TEMPERED:
            {
                D2RareAffixTxt* pRarePrefix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRarePrefixId(pItem));
                D2RareAffixTxt* pRareSuffix = DATATBLS_GetRareAffixTxtRecord(ITEMS_GetRareSuffixId(pItem));
                if (pRarePrefix)
                {
                    if (pRarePrefix->wStringId)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pRarePrefix->wStringId));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRarePrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pRareSuffix)
                {
                    if (pRareSuffix->wStringId)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pRareSuffix->wStringId));
                        }
                    }
                    else
                    {
                        Unicode aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pRareSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        nLen += sub_00526800(WSZ(aTemp));
                        if (pRarePrefix)
                        {
                            sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                        }
                        else
                        {
                            sub_005267E0(WSZ(aSuffix), WSZ(aTemp));
                        }
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x822);
                D2_ASSERT(nLen < nMaxLen, 0x822);

                Unicode aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                sub_005267E0(WSZ(aLine), INV_SkipBracketTag(WSZ(aName)));
                sub_00526700(WSZ(aLine), pNewLine);
                Unicode aFormat[200] = { 0 };
                INV_FormatArgs(WSZ(aFormat), D2LANG_GetStringFromTblIndex(0x6B6), WSZ(aPrefix), WSZ(aSuffix), 0);
                Unicode aEar[0x200];
                if (INV_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aFormat)))
                {
                    sub_00526700(WSZ(aLine), WSZ(aEar));
                }
                else
                {
                    sub_00526700(WSZ(aLine), WSZ(aFormat));
                }
                sub_00526700(pOut, WSZ(aLine));
                break;
            }
            case ITEMQUAL_UNIQUE:
            {
                Unicode aName[0x200];
                sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                if (ITEMS_GetFileIndex(pItem) < 0)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    break;
                }
                D2UniqueItemsTxt* pUniqueItemsTxt = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (!pUniqueItemsTxt)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    break;
                }
                if (!pItemsTxt->nSkipName)
                {
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                }
                Unicode aEar[0x200];
                if (INV_FormatEarNameTo(pItem, WSZ(aEar), INV_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex))))
                {
                    sub_00526700(pOut, WSZ(aEar));
                }
                else
                {
                    sub_00526700(pOut, INV_SkipBracketTag((Unicode*)D2LANG_GetStringFromTblIndex(pUniqueItemsTxt->wTblIndex)));
                }
                break;
            }
            case ITEMQUAL_SET:
            {
                D2SetItemsTxt* pSetItemsTxt = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
                if (pSetItemsTxt)
                {
                    Unicode aName[0x200];
                    sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
                    sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
                    sub_00526700(pOut, pNewLine);
                    if (pSetItemsTxt->wTblIndex)
                    {
                        Unicode aEar[0x200];
                        Unicode aSetName[0x200];
                        sub_005267E0(WSZ(aSetName), D2LANG_GetStringFromTblIndex(pSetItemsTxt->wTblIndex));
                        if (INV_FormatEarNameTo(pItem, WSZ(aEar), WSZ(aSetName)))
                        {
                            sub_00526700(pOut, WSZ(aEar));
                        }
                        else
                        {
                            Unicode aText[100] = { 0 };
                            INV_FormatArgs(WSZ(aText), D2LANG_GetStringFromTblIndex(0x2769), WSZ(aSetName), 0);
                            sub_00526700(pOut, WSZ(aText));
                        }
                    }
                }
                break;
            }
            case ITEMQUAL_MAGIC:
            {
                D2MagicAffixTxt* pPrefix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, 0));
                D2MagicAffixTxt* pSuffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, 0));
                if (pPrefix)
                {
                    if (pPrefix->wTblIndex)
                    {
                        nLen = sub_00526800(D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                        sub_005267E0(WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pPrefix->wTblIndex));
                    }
                    else
                    {
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pPrefix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen = strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aPrefix), SZ(aBuffer), 0x200);
                    }
                }
                else
                {
                    WSZ(aPrefix)->wChar = 0;
                }

                if (pSuffix)
                {
                    if (pSuffix->wTblIndex)
                    {
                        nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                        sub_00526700(WSZ(aSuffix), D2LANG_GetStringFromTblIndex(pSuffix->wTblIndex));
                    }
                    else
                    {
                        Unicode aTemp[0x200];
                        char aBuffer[0x200];
                        strcpy(SZ(aBuffer), "(");
                        strcat(SZ(aBuffer), pSuffix->szName);
                        strcat(SZ(aBuffer), ")");
                        nLen += strlen(SZ(aBuffer));
                        sub_00526320_ToUnicode(WSZ(aTemp), SZ(aBuffer), 0x200);
                        sub_00526700(WSZ(aSuffix), WSZ(aTemp));
                    }
                }
                else
                {
                    WSZ(aSuffix)->wChar = 0;
                }

                nLen += sub_00526800(D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr)) + 3;
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                D2_ASSERT(nLen < nMaxLen, 0x8C5);
                INV_FormatArgs(pOut, D2LANG_GetStringFromTblIndex(0x6B2), WSZ(aPrefix), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr), WSZ(aSuffix), 0);
                break;
            }
            default:
                FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x8CE);
                exit(-1);
            }
        }
        else
        {
            Unicode aName[0x200];
            sub_005267E0(WSZ(aName), D2LANG_GetStringFromTblIndex(pItemsTxt->wNameStr));
            sub_005267E0(pOut, INV_SkipBracketTag(WSZ(aName)));
        }

        INV_FormatEarName(pItem, pOut);
        sub_00452170(pOut);
        if (pItemsTxt->nQuest)
        {
            if (pItemsTxt->nQuestDiffCheck && STATLIST_UnitGetStatValue(pItem, STAT_QUESTITEMDIFFICULTY, 0) < GAME_GetDifficulty())
            {
                INV_PrefixColorCode(pOut, 1);
            }
            else if (pItemsTxt->dwCode != 0x2067656C)
            {
                INV_PrefixColorCode(pOut, 4);
            }
        }
    }
}

// 0x0048CEA0
static void __stdcall INV_AppendShopPriceText(const Unicode* pSource, Unicode* pText)
{
    Unicode wszName[0x40] = { 0 };
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    sub_005267E0(pText, pSource);
    if (gnInvPanelMode == 4 && ITEMS_CheckItemFlag(gpHoverItem, 0x400000, 0xCCC, ".\\UI\\inv.cpp"))
    {
        Unicode wszLabel[0x80];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0x58DA));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(wszLabel, 1));
    }

    int nSetIndex;
    if (NPCMENU_GetTradeCostText(gpHoverItem, gbHoverPlayerItem, &nSetIndex, wszName, 0x40))
    {
        if (wszName[0].wChar)
        {
            sub_00526700(pText, pColorEnd);
        }
        sub_00526700(pText, wszName);
        return;
    }

    if (gnInvPanelMode != 4)
    {
        Unicode wszLabel[0x40];
        sub_005267E0(wszLabel, D2LANG_GetStringFromTblIndex(0xD05));
        sub_00526700(pText, pColorEnd);
        sub_00526700(pText, INV_PrefixColorCode(wszLabel, 1));
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048CFF0
void __cdecl INV_DrawBookTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(gpHoverItem && ITEMS_GetItemType(gpHoverItem) == ITEMTYPE_BOOK, 0xCF1);
    D2_ASSERT(DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId), 0xCF5);

    INV_AppendStackQuantity(gpHoverItem, wszText);
    if (gnInvPanelMode == 0)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89B));
        sub_00526700(wszText, pColorEnd);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x89E));
        sub_00526700(wszText, pColorEnd);
    }

    Unicode wszLine[0x80];
    INV_BuildItemName(gpHoverItem, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400];
    if (gnInvPanelMode >= 1 && gnInvPanelMode <= 9)
    {
        INV_AppendShopPriceText(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnHoverTopY - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverTopX, gnHoverTopY, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverBottomX, gnHoverBottomY + nHeight, 0, 0);
    }
}

void __cdecl sub_19F4_Emit_0048A990(D2UnitStrc* pUnit)
{
    INV_DrawUnitName(pUnit);
    INV_DrawPanelLabels();
    INV_DrawMercStats(pUnit);
    sub_0048B0A0(pUnit);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048D1D0
void __fastcall INV_DrawSetItemTooltip(D2UnitStrc* pUnit)
{
    Unicode wszText[1024];
    Unicode wszPopup[2048];
    Unicode wszName[256];
    Unicode wszSetName[256];
    Unicode wszDurability[256];
    Unicode wszLevelReq[256];
    Unicode wszStrReq[256];
    Unicode wszDexReq[256];
    Unicode wszDamage[256];
    Unicode wszBlock[256];
    Unicode wszThrow[256];
    Unicode wszDefense[256];
    Unicode wszStats[1024];
    Unicode wszSpeed[256];
    Unicode wszSetItems[512];
    Unicode wszProps[1024];
    Unicode wszSetProps[512];
    Unicode wszStateProps[512];
    Unicode wszClass[256];
    int bLevelRed = 0;
    int bStrRed = 0;
    int bDexRed = 0;
    int bClassRed = 0;

    const Unicode* pNewline = D2LANG_GetStringFromTblIndex(0xF9E);

    D2UnitStrc* pPlayer = pUnit;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pUnit))
        pPlayer = sub_00463DD0_GetPlayerUnit();

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!gbHoverInBodyLoc && !gbHoverInGrid)
        return;
    if (!gpHoverItem)
        return;
    if (INVENTORY_GetCursorItem(pInventory))
        return;

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0xD56);

    D2SetItemsTxt* pSetItemsTxt = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(gpHoverItem));
    if (!pSetItemsTxt)
        return;

    D2SetsTxt* pSetsTxt = DATATBLS_GetSetsTxtRecord(pSetItemsTxt->nSetId);
    if (!pSetsTxt)
        return;

    sub_005267E0(wszSetName, D2LANG_GetStringFromTblIndex(pSetsTxt->wStringId));
    sub_00526700(wszSetName, pNewline);

    int bStrength;
    int bDexterity;
    int bLevel;
    ITEMS_CheckRequirements(gpHoverItem, pPlayer, 0, &bStrength, &bDexterity, &bLevel);

    INV_AppendDurability(gpHoverItem, wszDurability);

    const int nLevelReq = ITEMS_GetLevelRequirement(gpHoverItem, pPlayer);
    if (nLevelReq > 1)
    {
        if (!bLevel)
            bLevelRed = 1;
        INV_AppendLabeledNumber(nLevelReq, wszLevelReq);
    }

    if (ITEMSIsA(gpHoverItem, 0x2D) || ITEMSIsA(gpHoverItem, 0x32))
    {
        int nStrBonus = 0;
        int nDexBonus = 0;
        const int nPercent = STATLIST_UnitGetItemStatOrSkillStatValue(gpHoverItem, STAT_ITEM_REQ_PERCENT, 0);
        if (nPercent)
        {
            nStrBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqStr, nPercent, 100);
            nDexBonus = DATATBLS_ApplyRatio(pItemsTxt->wReqDex, nPercent, 100);
        }

        if (ITEMS_CheckItemFlag(gpHoverItem, 0x400000, 0xD88, ".\\UI\\inv.cpp"))
        {
            nStrBonus -= 10;
            nDexBonus -= 10;
        }

        if (pItemsTxt->wReqStr > 0)
        {
            if (!bStrength)
                bStrRed = 1;
            INV_AppendReqStr(pItemsTxt, nStrBonus, wszStrReq);
        }

        if (pItemsTxt->wReqDex > 0)
        {
            if (!bDexterity)
                bDexRed = 1;
            INV_AppendReqDex(pItemsTxt, nDexBonus, wszDexReq);
        }
    }

    sub_005267E0(wszStats, INV_PrefixColorCode(wszLevelReq, bLevelRed));
    sub_00526700(wszStats, INV_PrefixColorCode(wszStrReq, bStrRed));
    sub_00526700(wszStats, INV_PrefixColorCode(wszDexReq, bDexRed));

    const int nClass = ITEMS_GetClassOfClassSpecificItem(gpHoverItem);
    if (nClass != 7)
    {
        sub_00526700(wszClass, D2LANG_GetStringFromTblIndex(nClass + 0x2AA5));
        sub_00526700(wszClass, pNewline);
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->dwClassId != nClass)
            bClassRed = 1;
        sub_00526700(wszStats, INV_PrefixColorCode(wszClass, bClassRed));
    }

    sub_00526700(wszStats, INV_PrefixColorCode(wszDurability, 0));

    if (ITEMSIsA(gpHoverItem, 0x2D))
    {
        INV_AppendAttackSpeed(wszSpeed, gpHoverItem);
        INV_PrefixColorCode(wszSpeed, 0);
        sub_00526700(wszStats, wszSpeed);

        if (STATLIST_GetMinDamageFromUnit(gpHoverItem, 0) >= 0 && STATLIST_GetMaxDamageFromUnit(gpHoverItem, 0) >= 0)
        {
            sub_00485410_AppendDamage(gpHoverItem, wszDamage);
            INV_PrefixColorCode(wszDamage, 0);
            sub_00526700(wszStats, wszDamage);
        }
    }

    if (ITEMSIsA(gpHoverItem, 0x33))
    {
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            const int nPlayerClass = pPlayer->dwClassId;
            if (nPlayerClass == 3 && (!ITEMS_IsClassValid(gpHoverItem) || ITEMS_GetClassOfClassSpecificItem(gpHoverItem) == nPlayerClass))
            {
                INV_AppendThrowDamage(gpHoverItem, pItemsTxt, wszThrow);
                INV_PrefixColorCode(wszThrow, 0);
                sub_00526700(wszStats, wszThrow);
            }
        }

        INV_AppendBlockChance(wszBlock, pItemsTxt, gpHoverItem);
        INV_PrefixColorCode(wszBlock, 0);
        sub_00526700(wszStats, wszBlock);
    }

    if (ITEMSIsA(gpHoverItem, 0x32) && STATLIST_GetDefenseFromUnit(gpHoverItem) > 0)
    {
        INV_AppendDefense(pPlayer, gpHoverItem, wszDefense);
        INV_PrefixColorCode(wszDefense, 0);
        sub_00526700(wszStats, wszDefense);
    }

    INV_BuildItemName(gpHoverItem, wszName, 0x100);
    if (ITEMS_CheckItemFlag(gpHoverItem, 0x100, 0xDDB, ".\\UI\\inv.cpp"))
    {
        INV_PrefixColorCode(wszName, 1);
    }
    else
    {
        INV_PrefixColorCode(wszName, 2);
    }
    sub_00526700(wszStats, wszName);

    wszProps[0].wChar = 0;
    if (ITEMS_CheckItemFlag(gpHoverItem, 0x800, 0xDE4, ".\\UI\\inv.cpp"))
    {
        Unicode wszSockets[300];
        INV_AppendEtherealSocketed(gpHoverItem, wszSockets);
        sub_005267E0(wszProps, wszSockets);
    }

    sub_004E6410_BuildPropText(gpHoverItem, wszProps, 0x400, 1, 0);

    wszSetProps[0].wChar = 0;
    WARDENCLIENT_SetItemPropTexts(pPlayer, gpHoverItem, wszSetProps, 0x200);

    wszStateProps[0].wChar = 0;
    if (gpHoverItem && gpHoverItem->dwAnimMode == 1)
        MISSILE_AddSetStatePropText(pPlayer, gpHoverItem, wszStateProps, 0x200);

    for (int i = 0; i < pSetsTxt->nSetItems; ++i)
    {
        D2SetItemsTxt* pSetItem = pSetsTxt->pSetItem[i];
        if (!pSetItem)
            break;

        D2UnitStrc* pFound = INV_FindSetItem(pInventory, pSetItem->wSetItemId);
        if (pSetItem->wTblIndex)
        {
            INV_FormatArgs(wszText, D2LANG_GetStringFromTblIndex(0x2769), D2LANG_GetStringFromTblIndex(pSetItem->wTblIndex), 0);
            sub_00526700(wszText, pNewline);
        }

        if (pFound)
            INV_PrefixColorCode(wszText, 2);
        else
            INV_PrefixColorCode(wszText, 1);
        sub_00526700(wszSetItems, wszText);
    }

    sub_005267E0(wszText, INV_PrefixColorCode(wszSetItems, 2));
    sub_00526700(wszText, INV_PrefixColorCode(wszSetName, 4));
    if (wszStateProps[0].wChar)
    {
        sub_00526700(wszText, pNewline);
        sub_00526700(wszText, INV_PrefixColorCode(wszStateProps, 4));
    }
    sub_00526700(wszText, pNewline);
    if (wszSetProps[0].wChar)
        sub_00526700(wszText, INV_PrefixColorCode(wszSetProps, 2));
    sub_00526700(wszText, INV_PrefixColorCode(wszProps, 3));
    sub_00526700(wszText, wszStats);

    if (gnInvPanelMode)
    {
        switch (gnInvPanelMode)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        {
            Unicode wszCost[64];
            int nCost;
            if (NPCMENU_GetTradeCostText(gpHoverItem, gbHoverPlayerItem, &nCost, wszCost, 0x40))
            {
                sub_005267E0(wszPopup, wszText);
                if (wszCost[0].wChar)
                    sub_00526700(wszPopup, pNewline);
                sub_00526700(wszPopup, wszCost);
            }
            else
            {
                sub_005267E0(wszPopup, wszText);
                if (gnInvPanelMode != 4)
                {
                    Unicode wszNote[64];
                    sub_005267E0(wszNote, D2LANG_GetStringFromTblIndex(0xD05));
                    sub_00526700(wszPopup, pNewline);
                    sub_00526700(wszPopup, INV_PrefixColorCode(wszNote, 1));
                }
            }
            break;
        }
        default:
            sub_005267E0(wszPopup, wszText);
            break;
        }
    }
    else
    {
        sub_005267E0(wszPopup, wszText);
    }

    sub_00452170(wszPopup);
    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszPopup, &nWidth, &nHeight);
    if (gnHoverTopY - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszPopup, gnHoverTopX, gnHoverTopY, 0, 1);
        return;
    }

    D2Win_10129_DrawFramedText(wszPopup, gnHoverBottomX, nHeight + gnHoverBottomY, 0, 1);
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048DB80
void __cdecl INV_DrawTransmogrifyTooltip()
{
    Unicode wszText[0x400];
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    if (!ITEMS_GetTransmogrify(gpHoverItem))
    {
        return;
    }

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!gpHoverItem ? -1 : gpHoverItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0xE61);
    int nItemId = 0;
    D2ItemsTxt* pBaseTxt = DATATBLS_GetItemRecordFromItemCode(pItemsTxt->dwTransmogrifyType, &nItemId);
    D2_ASSERT(pBaseTxt, 0xE64);

    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(pBaseTxt->wNameStr));
    sub_00526700(wszText, pColorEnd);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x150B));
    sub_00526700(wszText, pColorEnd);

    Unicode wszLine[0x80];
    INV_BuildItemName(gpHoverItem, wszLine, 0x80);
    sub_00452170(wszLine);
    sub_00526700(wszText, wszLine);

    Unicode wszTooltip[0x400] = { 0 };
    if ((unsigned int)(gnInvPanelMode - 1) <= 8)
    {
        INV_AppendShopPriceText(wszText, wszTooltip);
    }
    else
    {
        sub_005267E0(wszTooltip, wszText);
    }
    sub_00452170(wszTooltip);

    int nWidth;
    int nHeight;
    D2Win_10131_GetTextDimensions(wszTooltip, &nWidth, &nHeight);
    if (gnHoverTopY - nHeight > 0)
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverTopX, gnHoverTopY, 0, 0);
    }
    else
    {
        D2Win_10129_DrawFramedText(wszTooltip, gnHoverBottomX, gnHoverBottomY + nHeight, 0, 0);
    }
}

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

// 0x0048FFE0
static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage)
{
    int nResult = 0;
    if (nPage == 0xFF)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion());
    int nGridX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nGridY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    int nOutX;
    int nOutY;

    if (sub_00468830() == 6)
    {
        D2UnitStrc* pCursor = CURSOR_GetCursorItem();
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pCursor && pHit)
        {
            nResult = 1;
            if (!ITEM_IsItemActionBlocked(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && INV_CheckTradeClickDelay())
                {
                    MSG_SendTwoDwords(0x27, !pHit ? -1 : pHit->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
                    ITEM_SetUninterruptableState(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (sub_00468830() == 8)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            nResult = 1;
            if (!ITEM_IsItemActionBlocked(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && INV_CheckTradeClickDelay())
                {
                    MSG_SendDword(0x4C, pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (!pCursorItem)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            const int bIsPlayer = pUnit == sub_00463DD0_GetPlayerUnit();
            if (INV_IsTradeStateInteractive() && bIsPlayer == 1)
            {
                if (!ITEM_IsItemActionBlocked(pHit) && INV_CheckTradeClickDelay())
                {
                    if (GetAsyncKeyState(0x11) & 0x8000)
                    {
                        int nNpcId;
                        if (NPCMENU_GetInteractNpcId(&nNpcId))
                        {
                            D2UnitStrc* pNpc = CUNIT_FindClientUnit(nNpcId, 1);
                            if (pNpc)
                            {
                                if (ITEMS_IsNotQuestItem(pHit))
                                {
                                    const int nCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pHit, GAME_GetDifficulty(), MONSTER_GetQuestFlags(), !pNpc ? -1 : pNpc->dwClassId, 1);
                                    MSG_SendFourDwords(0x33, !pNpc ? -1 : pNpc->dwUnitId, !pHit ? -1 : pHit->dwUnitId, !pHit ? -1 : pHit->dwAnimMode, nCost);
                                }
                                else
                                {
                                    UNITSND_PlayPlayerSpeech(pUnit, 0x13);
                                }
                            }
                        }
                    }
                    else if ((nFlags & 4) && ITEMS_CheckIfBeltable(pHit) && !ITEMS_GetInvPage(pHit))
                    {
                        MSG_SendDword(0x63, pHit->dwUnitId);
                        sub_004B9A00(0xEB, 0, 0, 0, 0);
                    }
                    else
                    {
                        MSG_SendDword(0x19, pHit->dwUnitId);
                        gbNpcTradeClicked = 1;
                    }
                    nResult = 1;
                    ITEM_SetUninterruptableState(pHit);
                }
            }
            else if (gnInvPanelMode < 0x13)
            {
                INV_ForwardTradeClick((int)pUnit, (int)pHit, bIsPlayer, nX, nY, 0, 0);
            }
        }
    }
    else
    {
        D2UnitStrc* pHit;
        unsigned int nCount;
        INVENTORY_CanItemBePlaced(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pHit, &nCount, nPage);
        D2UnitStrc* pOther = 0;
        int bPlace = 1;
        if (nCount > 1)
        {
            D2UnitStrc* pBox = 0;
            INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pBox, nPage, 1);
            if (pBox && DATATBLS_GetItemsTxtRecord((!pBox ? -1 : pBox->dwClassId))->dwCode == 0x20786F62)
            {
                pHit = pBox;
                goto LBL_CUBE;
            }
        }

        if (pHit && nCount == 1)
        {
            if (ITEMS_AreStackablesEqual(pCursorItem, pHit))
            {
                if (!ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != 0xB && nPage != 2)
                {
                    MSG_SendTwoDwords(0x21, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
            }
            else if (gnHoverCellX >= 0 && gnHoverCellY >= 0)
            {
                if (INV_CanSocketInto(pHit, pCursorItem) && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
                {
                    MSG_SendTwoDwords(0x28, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (ITEMSIsA(pCursorItem, 0x16) && ITEMSIsA(pHit, 0x12)
                    && ITEMS_GetSuffixId(pCursorItem, 0) == ITEMS_GetSuffixId(pHit, 0)
                    && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != 0xB)
                {
                    SPELLSEL_UpdateSkillIcons();
                    MSG_SendTwoDwords(0x29, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (DATATBLS_GetItemsTxtRecord(!pHit ? -1 : pHit->dwClassId)->dwCode == 0x20786F62)
                {
LBL_CUBE:
                    if (!ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
                    {
                        int nFreeX;
                        int nFreeY;
                        const int nCubeRecord = UNITS_GetInventoryRecordId(pUnit, 3, GAME_IsExpansion());
                        if (INVENTORY_GetFreePosition(pInventory, pCursorItem, nCubeRecord, &nFreeX, &nFreeY, 3))
                        {
                            MSG_SendTwoDwords(0x2A, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                            ITEM_SetUninterruptableState(pCursorItem);
                            sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                            nResult = 1;
                        }
                        else
                        {
                            UNITSND_PlayPlayerSpeech(pUnit, 0x13);
                        }
                        goto LBL_DONE;
                    }
                }

                if (bPlace && INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 0)
                    && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && nPage != 2)
                {
                    MSG_SendFourDwords(0x1F, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pOther ? -1 : pOther->dwUnitId, gnHoverCellX, gnHoverCellY);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
LBL_DONE:
                ;
            }
        }
        else
        {
            if (nPage == 3)
            {
                D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord((!pCursorItem ? -1 : pCursorItem->dwClassId));
                D2_ASSERT(pTxt, 0x163A);
                if (pTxt->dwCode == 0x20786F62)
                {
                    return 1;
                }
            }

            int nCellX;
            int nCellY;
            sub_00486BD0_GetItemCell(nX, nY, &nCellX, &nCellY, pCursorItem, pGrid);
            D2UnitStrc* pExchange;
            unsigned int nExchangeCount;
            if (INVENTORY_CanItemBePlaced(pInventory, pCursorItem, nCellX, nCellY, nRecord, &pExchange, &nExchangeCount, nPage)
                && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
            {
                MSG_SendFourDwords(0x18, (!pCursorItem ? -1 : pCursorItem->dwUnitId), nCellX, nCellY, nPage);
                ITEM_SetUninterruptableState(pCursorItem);
                sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                nResult = 1;
            }
        }
    }
    return nResult;
}

int __stdcall sub_19F4_Emit_0048FFE0(D2UnitStrc* pUnit, unsigned int nX, unsigned int nY, int nFlags)
{
    return INV_ClickInvGrid(pUnit, pUnit->pInventory, nX, nY, nFlags, &gtPlayerInvGrid, gnSelectedTab);
}

// 0x00483AB0
int __fastcall INV_IsInPlayerInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

#define MV(x) (x)

#define PACKET(x) (x)

// 0x00490780
int __fastcall sub_00490780(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int nBodyLoc)
{
    int nResult = 0;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, MV(5));
    D2UnitStrc* pSelected = INVENTORY_GetItemFromBodyLoc(pInventory, MV(4));
    if (sub_00468830() == MV(6))
    {
        D2UnitStrc* pCursor = CURSOR_GetCursorItem();
        if (pCursor && pSelected && !ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x27), !pSelected ? -1 : pSelected->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
            ITEM_SetUninterruptableState(pSelected);
            nResult = 1;
        }
    }
    else if (sub_00468830() == MV(8))
    {
        if (pSelected && !ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
        {
            MSG_SendDword(PACKET(0x4C), !pSelected ? -1 : pSelected->dwUnitId);
            ITEM_SetUninterruptableState(pSelected);
            nResult = 1;
        }
    }
    switch (D2Common_10299(pPlayer, nBodyLoc, pItem, 0))
    {
    case 0:
        if (pItem)
        {
            if (D2Common_10299(pPlayer, nBodyLoc, pItem, 1))
            {
                const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
                if (nClass == MV(7) || nClass == (!pPlayer ? -1 : pPlayer->dwClassId))
                {
                    UNITSND_PlayPlayerSpeech(pPlayer, MV(0x14));
                    return 1;
                }
            }
            UNITSND_PlayPlayerSpeech(pPlayer, MV(0x13));
        }
        return 1;
    case 1:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1A), !pItem ? -1 : pItem->dwUnitId, MV(4));
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 2:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pOther) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1B), !pItem ? -1 : pItem->dwUnitId, MV(4));
            ITEM_SetUninterruptableState(pOther);
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 3:
        if (INV_IsNpcStateB())
        {
            if (!ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
            {
                MSG_SendWord(PACKET(0x1C), MV(4));
                ITEM_SetUninterruptableState(pSelected);
                gbNpcTradeClicked = 1;
                nResult = 1;
            }
        }
        else if (gnInvPanelMode < MV(0x13))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pSelected, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        break;
    case 4:
        if (gnInvPanelMode == MV(4))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pOther, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        else if (!ITEM_IsItemActionBlocked(pOther) && INV_CheckTradeClickDelay())
        {
            MSG_SendWord(PACKET(0x1C), MV(5));
            ITEM_SetUninterruptableState(pOther);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 5:
        if (!ITEM_IsItemActionBlocked(pSelected) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1D), !pItem ? -1 : pItem->dwUnitId, MV(4));
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 7:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pSelected) && !ITEM_IsItemActionBlocked(pOther) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1E), !pItem ? -1 : pItem->dwUnitId, MV(4));
            ITEM_SetUninterruptableState(pItem);
            ITEM_SetUninterruptableState(pSelected);
            ITEM_SetUninterruptableState(pOther);
            nResult = 1;
        }
        break;
    case 6:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != MV(0xB))
        {
            MSG_SendTwoDwords(PACKET(0x21), !pItem ? -1 : pItem->dwUnitId, !pSelected ? -1 : pSelected->dwUnitId);
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    }
    return nResult;
}

// 0x00490BA0
int __fastcall sub_00490BA0(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int nBodyLoc)
{
    int nResult = 0;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, MV(5));
    D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, MV(4));
    if (sub_00468830() == MV(6))
    {
        D2UnitStrc* pCursor = CURSOR_GetCursorItem();
        if (pCursor && pLeft && !ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x27), !pLeft ? -1 : pLeft->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
            ITEM_SetUninterruptableState(pLeft);
            nResult = 1;
        }
    }
    else if (sub_00468830() == MV(8))
    {
        if (pLeft && !ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            MSG_SendDword(PACKET(0x4C), !pLeft ? -1 : pLeft->dwUnitId);
            ITEM_SetUninterruptableState(pLeft);
            nResult = 1;
        }
    }
    switch (D2Common_10299(pPlayer, nBodyLoc, pItem, 0))
    {
    case 0:
        if (pItem)
        {
            if (D2Common_10299(pPlayer, nBodyLoc, pItem, 1))
            {
                const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
                if (nClass == MV(7) || nClass == (!pPlayer ? -1 : pPlayer->dwClassId))
                {
                    UNITSND_PlayPlayerSpeech(pPlayer, MV(0x14));
                    return 1;
                }
            }
            UNITSND_PlayPlayerSpeech(pPlayer, MV(0x13));
        }
        return 1;
    case 1:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1A), !pItem ? -1 : pItem->dwUnitId, MV(5));
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 2:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pRight) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1B), !pItem ? -1 : pItem->dwUnitId, MV(5));
            ITEM_SetUninterruptableState(pRight);
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 3:
        if (INV_IsNpcStateB())
        {
            if (!ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
            {
                MSG_SendWord(PACKET(0x1C), MV(5));
                ITEM_SetUninterruptableState(pLeft);
                gbNpcTradeClicked = 1;
                nResult = 1;
            }
        }
        else if (gnInvPanelMode < MV(0x13))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pLeft, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        break;
    case 4:
        if (gnInvPanelMode == MV(4))
        {
            INV_ForwardTradeClick((int)pPlayer, (int)pRight, 1, gnInvMouseX, gnInvMouseY, 0, 0);
        }
        else if (!ITEM_IsItemActionBlocked(pRight) && INV_CheckTradeClickDelay())
        {
            MSG_SendWord(PACKET(0x1C), MV(4));
            ITEM_SetUninterruptableState(pRight);
            gbNpcTradeClicked = 1;
            nResult = 1;
        }
        break;
    case 5:
        if (!ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1D), !pItem ? -1 : pItem->dwUnitId, MV(5));
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    case 7:
        if (!ITEM_IsItemActionBlocked(pItem) && !ITEM_IsItemActionBlocked(pRight) && !ITEM_IsItemActionBlocked(pLeft) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(PACKET(0x1E), !pItem ? -1 : pItem->dwUnitId, MV(5));
            ITEM_SetUninterruptableState(pItem);
            ITEM_SetUninterruptableState(pRight);
            ITEM_SetUninterruptableState(pLeft);
            nResult = 1;
        }
        break;
    case 6:
        if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != MV(0xB))
        {
            MSG_SendTwoDwords(PACKET(0x21), !pItem ? -1 : pItem->dwUnitId, !pLeft ? -1 : pLeft->dwUnitId);
            ITEM_SetUninterruptableState(pItem);
            sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
            nResult = 1;
        }
        break;
    }
    return nResult;
}

// 0x00490FC0
int __fastcall sub_00490FC0(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int nBodyLoc)
{
    int nResult = 0;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (sub_00468830() == MV(6))
    {
        pPlayer = CURSOR_GetCursorItem();
        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        if (pPlayer && pItem && !ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            MSG_SendTwoDwords(MV(0x27), pItem->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId);
            ITEM_SetUninterruptableState(pItem);
            nResult = 1;
        }
    }
    else if (sub_00468830() == MV(8))
    {
        pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        if (pItem && !ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
        {
            MSG_SendDword(MV(0x4C), pItem->dwUnitId);
            ITEM_SetUninterruptableState(pItem);
            nResult = 1;
        }
    }
    else
    {
        switch (D2Common_10299(pPlayer, nBodyLoc, pItem, 0))
        {
        case 0:
            if (pItem)
            {
                if (D2Common_10299(pPlayer, nBodyLoc, pItem, 1))
                {
                    const int nClass = sub_0062C0B0_GetItemTypeClass(pItem);
                    if (nClass == MV(7) || nClass == (!pPlayer ? -1 : pPlayer->dwClassId))
                    {
                        UNITSND_PlayPlayerSpeech(pPlayer, MV(0x14));
                        return 1;
                    }
                }
                UNITSND_PlayPlayerSpeech(pPlayer, MV(0x13));
            }
            return 1;
        case 1:
            if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
            {
                MSG_SendTwoDwords(MV(0x1A), !pItem ? -1 : pItem->dwUnitId, (unsigned short)nBodyLoc);
                ITEM_SetUninterruptableState(pItem);
                sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
                gbNpcTradeClicked = 1;
                nResult = 1;
            }
            break;
        case 3:
            if (INV_IsNpcStateB())
            {
                if (INV_CheckTradeClickDelay())
                {
                    MSG_SendWord(MV(0x1C), nBodyLoc);
                    gbNpcTradeClicked = 1;
                    nResult = 1;
                }
            }
            else if (gnInvPanelMode < MV(0x13))
            {
                pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
                INV_ForwardTradeClick((int)pPlayer, (int)pItem, 1, gnInvMouseX, gnInvMouseY, 0, 0);
            }
            break;
        case 5:
            if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
            {
                MSG_SendTwoDwords(MV(0x1D), !pItem ? -1 : pItem->dwUnitId, (unsigned short)nBodyLoc);
                ITEM_SetUninterruptableState(pItem);
                sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
                nResult = 1;
            }
            break;
        }
    }
    return nResult;
}

// 0x004912A0
void __stdcall INV_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if(GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing()) {
        pMsg->bReturn=0;
        return;
    }
    const int y=pMsg->nYpos;
    const int x=pMsg->nXpos;
    if(x>gnScreenWidth) {
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* inventory=player->pInventory;
    int handled=0;
    if(!HIREABLES_AreBeltRowsShown()) {
        if(INV_IsOverGoldButton(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==11 || gnInvPanelMode==12 || gnInvPanelMode==15)) {
            gbInvGoldButtonDown=1;
            sub_004B9A00(4,0,0,0,0);
        }
        if(INV_IsInNpcPanelRect(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==19)) {
            gbPanelButtonDown=1;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    if(!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && INV_IsInPlayerInvRect(x,y)) {
        if(INV_IsInNpcPanelRect(x,y)) {
            gbPanelButtonDown=1;
            UI_SetUIVar(1,1,0);
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        pMsg->bReturn=1;
        pMsg->lResult=0;
        int result=0;
        if(x>=gtPlayerInvGrid.nGridLeft && x<=gtPlayerInvGrid.nGridRight && y>=gtPlayerInvGrid.nGridTop && y<=gtPlayerInvGrid.nGridBottom) {
            result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtPlayerInvGrid,0);
            handled=1;
        }
        else {
            int bodyloc=0;
            for(;bodyloc<11;++bodyloc) {
                if(x>=gaCompGrids[bodyloc].rect.nLeft && x<=gaCompGrids[bodyloc].rect.nRight && y>=gaCompGrids[bodyloc].rect.nTop && y<=gaCompGrids[bodyloc].rect.nBottom) goto BODY_FOUND;
            }
            goto AFTER_BODY;
BODY_FOUND:
            {
                D2UnitStrc* cursor=INVENTORY_GetCursorItem(inventory);
                if(sub_00468830()==6 || sub_00468830()==8) {
USE_BODY_ACTION:
                    result=gaBodyClick[bodyloc](player,inventory,bodyloc);
                    handled=1;
                }
                else {
                    D2UnitStrc* bodyItem=INVENTORY_GetItemFromBodyLoc(inventory,bodyloc);
                    if(!INV_CanSocketInto(bodyItem,cursor)) goto USE_BODY_ACTION;
                    if(!ITEM_IsItemActionBlocked(cursor) && INV_CheckTradeClickDelay()) {
                        MSG_SendTwoDwords(0x28,!cursor?-1:cursor->dwUnitId,!bodyItem?-1:bodyItem->dwUnitId);
                        ITEM_SetUninterruptableState(cursor);
                        sub_004B9A00(ITEM_GetDropSound(bodyItem),0,0,0,0);
                        handled=1;
                    }
                    result=0;
                }
            }
AFTER_BODY:
            if(!handled && GAME_IsExpansion() && INV_IsOverWeaponSwapTab(x,y)) {
                pMsg->bReturn=1;
                sub_0048A730_SwapWeapons();
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        pMsg->lResult=0;
        pMsg->bReturn=1;
        if(!result) {
            if(sub_00468830()==6) UI_CancelCursorItemUse();
            else if(sub_00468830()==8) MSG_SendDword(0x4C,-1);
        }
        sub_00420290_BreakHandlerChain(pMsg);
        gbHoverInGrid=0;
        gbHoverInBodyLoc=0;
        gpHoverItem=0;
        gpLastHoverItem=0;
        if(!handled) INV_ClickOutsidePanel(y,pMsg,x);
        return;
    }
    switch(gnInvPanelMode) {
    case 14:
        if(x>=gtCubeGrid.nGridLeft && x<=gtCubeGrid.nGridRight && y>=gtCubeGrid.nGridTop && y<=gtCubeGrid.nGridBottom) {
            INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtCubeGrid,3);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        break;
    case 12:
        {
            int left,right,top,bottom;
            if(GAME_IsExpansion()) {
                left=gtBigBankGrid.nGridLeft;right=gtBigBankGrid.nGridRight;top=gtBigBankGrid.nGridTop;bottom=gtBigBankGrid.nGridBottom;
            }
            else {
                left=gtBankGrid.nGridLeft;right=gtBankGrid.nGridRight;top=gtBankGrid.nGridTop;bottom=gtBankGrid.nGridBottom;
            }
            if(x>=left && x<=right && y>=top && y<=bottom) {
                if(GAME_IsExpansion()) INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBigBankGrid,4);
                else INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBankGrid,4);
                pMsg->lResult=0;
                pMsg->bReturn=1;
                gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        break;
    case 11:
        if(x>=gtTradePage2Grid.nGridLeft && x<=gtTradePage2Grid.nGridRight && y>=gtTradePage2Grid.nGridTop && y<=gtTradePage2Grid.nGridBottom) {
            int result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtTradePage2Grid,2);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            if(result) sub_004B90B0_SendState();
            return;
        }
        break;
    }
    pMsg->bReturn=0;
    INV_ClickOutsidePanel(y,pMsg,x);
}

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

// 0x00491AD0
void __stdcall INV_InventoryClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (GAME_IsExitPending() || !pPlayer || CUNIT_IsPlayerDeadOrMissing())
    {
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if (nX >= gtPlayerInvGrid.nGridLeft && nX <= gtPlayerInvGrid.nGridRight && nY >= gtPlayerInvGrid.nGridTop && nY <= gtPlayerInvGrid.nGridBottom)
    {
        INV_GridClickMsg(pMsg);
        return;
    }

    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        return;
    }

    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
    }
    else if (sub_00468830() == 8)
    {
        MSG_SendDword(0x4C, -1);
    }
    else if (!INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        if (gnInvPanelMode == 1 || gnInvPanelMode == 2)
        {
            if (nX >= 0 && nX <= gnGlobal_007BCAA0 && nY >= 0 && nY <= gnGlobal_007BCAAC)
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
                if (nX >= gnGlobal_007BCB5C && nX <= gnGlobal_007BCB60 && nY >= gnGlobal_007BCB64 && nY <= gnGlobal_007BCB68 && gpHoverItem)
                {
                    int nUnitId;
                    if (!NPCMENU_GetInteractNpcId(&nUnitId))
                    {
                        INV_ResetNpcButtons();
                    }
                    else
                    {
                        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
                        if (!pUnit)
                        {
                            INV_ResetNpcButtons();
                        }
                        else
                        {
                            const unsigned int nParam = pMsg->wParam;
                            if (gpHoverItem && NPCMENU_HandleTradeClick(pUnit, gpHoverItem, 0, nX, nY, nParam, 1, 0))
                            {
                                CURSOR_SetCursorItemState(0);
                            }
                        }
                    }
                }
                else if (INV_CanUseCursor())
                {
                    INV_ResetNpcButtons();
                }
            }
        }
        else if (gnInvPanelMode == 0xE)
        {
            if (sub_00483BF0_IsInRect(nX, nY))
            {
                UNITSND_PlayPlayerSpeech(pPlayer, 0x13);
            }
        }
        else if (gnInvPanelMode == 0xC && sub_00483B40_IsInRect(nX, nY))
        {
            if (INV_IsInPlayerInvRect(nX, nY))
            {
                INV_GridClickMsg(pMsg);
            }
            else if (sub_00483B40_IsInRect(nX, nY))
            {
                INV_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
            }
            else
            {
                UNITSND_PlayPlayerSpeech(pPlayer, 0x13);
            }
        }
        else if (INV_IsModeInRange(gnInvPanelMode))
        {
            INV_ResetNpcButtons();
        }
    }
    else
    {
        switch (gnInvPanelMode)
        {
        case 2:
        case 3:
        case 4:
            INV_ResetNpcButtons();
            break;
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00492770
void __stdcall INV_WeaponSwapKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExpansion())
    {
        if (!(pMsg->lParam & 0x40000000) && !UI_GetUIVarUnchecked(5))
            sub_0048A730();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
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

void __cdecl sub_00495410_DrawHelpText(); // 0x00495410

void __cdecl sub_00495DC0_DrawHelpText(); // 0x00495DC0

// 0x00497C50
void __stdcall INV_DrawWarningIcon(int nFrame)
{
    int nX = gnScreenWidth - 0x37;
    int nY = 0x9B;
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (!gabSlots[i])
        {
            gabSlots[i] = 1;
            nX -= 0x28 * i;
            break;
        }
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BEF24;
    tContext.nDirection = 0;
    tContext.nFrame = nFrame;
    if (GAME_GetUIVarState(0xA))
    {
        if (ROSTER_IsAnyoneHostile())
        {
            nY = 0xC6;
        }
        nY += 0x1E;
    }
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x00498A20
int __fastcall INV_CheckState(int nUnused, D2ClientStateStrc* pState, D2UnitStrc* pUnit, int nArg2)
{
    D2_ASSERT(pState, 2621);
    if (pState->bFlag0x129 == 1 || pState->bFlag0x12A == 1)
    {
        sub_0049FF90_Close(nArg2, pState);
        return 0;
    }
    if (pState->bFlag0x11D == 1)
    {
        return 1;
    }
    UNITSND_PlayPlayerSpeech(pUnit, 0x14);
    return 0;
}

extern D2SkillIconStateStrc gtHotkeySlots;                                                      // 0x007C0300

extern int gbSkillSelectRight;                                                                               // 0x007C07FC

void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw); // 0x004AA3A0

int __cdecl sub_M133_Emit_00483C20(int nX, int nY)
{
    return INV_IsInSidePanelRect(nX, nY);
}

void __stdcall sub_P09_Emit_00486670(Unicode* pText)
{
    INV_AppendSocketedGemLetters(pText, gpHoverItem);
}

#include "gen/data/Source/D2Client/UI/inv.inc"
