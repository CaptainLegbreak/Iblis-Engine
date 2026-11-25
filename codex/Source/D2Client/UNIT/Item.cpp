#include "D2StateIds.h"
#include "D2ClientUi.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2TxtItems.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2DataTbls.h"
#include "D2GameObjs.h"
#include "D2ClientGfx.h"
#include "D2ItemsWorld.h"
#include "D2ClientSound.h"
#include "D2UnitEventArgs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define ITEMQUAL_SET 5

#define ITEMQUAL_UNIQUE 7

struct D2ActInfoStrc;

struct D2TileStrc;

struct D2GemsTxt;

struct D2UnitTargetStrc;

struct D2StaticPathStrc;

struct D2ObjectDataStrc;

struct D2GSPacketSrv9C;

struct D2SkillsTxt;

struct D2UnitEventArgsStrc;


struct D2PanelGfxStrc;

struct D2TimedHintStrc;

struct D2CellNodeStrc;

struct D2CellGridViewStrc;

struct D2AddressInfoStrc;

struct D2AddressQueryStrc;

struct D2SlotObjectStrc;

struct D2SlotStrc;

struct D2SkillStateStrc;

struct D2GSPacketSrv7DStrc;

struct D2UniqueItemsTxt;

struct D2SetItemsTxt;

struct D2PacketRecord8Strc;

struct D2PacketRecord13Strc;

struct D2GSPacketSrv42Strc;

struct D2PacketRecord11Strc;

struct D2CoordStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2GfxMotionStrc;

struct D2CellPosStrc;

struct D2GridCellStrc;

struct D2ItemsTxt;

struct D2ItemSaveStrc;

struct D2GSPacketSrv9D;

struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

int __fastcall sub_00480C10_DispatchUnitEvent(int nEvent, D2UnitStrc* pUnit, D2UnitEventArgsStrc* pArgs, int nArg); // 0x00480C10

void __fastcall ITEM_ClearUninterruptableState(D2UnitStrc* pItem); // 0x004C2180

D2UnitStrc* __fastcall AUTOMAP_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4); // 0x004C5420

void __fastcall SKILLS_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue); // 0x004C7BE0

void __fastcall sub_004E4050_Nothing(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x004E4050

unsigned char __stdcall UNITS_GetObjectPortalFlags(D2UnitStrc* pUnit); // 0x006222C0

void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag); // 0x00622300

unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110

int __stdcall sub_006287A0_TestFlags(unsigned int dwFlags, unsigned int dwMask); // 0x006287A0

int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue); // 0x00645F00

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

struct D2PanelGfxStrc
{
    int unk0x00[15];
    int f_3C;
    int unk0x40[2];
};

struct D2TimedHintStrc
{
    int bActive;
    void* pOwner;
    int nEndTickA;
    int bActive2;
    int nArgE;
    int nEndTickF;
    int nArgG;
    int nEndTickC;
};

struct D2AddressInfoStrc
{
    short nUnk0x00;
    short f_2;
    int nMagic;
    int nUnk0x08;
    short f_C;
    short nVersion;
    int f_10;
};

struct D2AddressQueryStrc
{
    char unk0x00[0x50];
    char bFamilyMatch;
    char unk0x51[0x1B];
    int nSocket;
    int nParam;
    int nResult;
    int nParamOut;
    char unk0x7C[0x05];
    char f_81;
    char unk0x82[0x04];
    char nState[4];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" const char gszGfxUtilSourceFile[]; // 0x006DB974

extern int gnUseItemDialogState; // 0x007C5474

extern int gnAnvilItemId; // 0x007C5480

extern void* gpfnClientStateEvents[2]; // 0x00727DB4

extern int gnCurrentSongId; // 0x007C89D8

extern int gdwSongPositionTick; // 0x007C89E0

extern D2TimedHintStrc gtTimedHint; // 0x007C89E4

extern void* gpGlobal_007A0634; // 0x007A0634

int __cdecl sub_0044DB00(); // 0x0044DB00

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

int __cdecl sub_004817F0(); // 0x004817F0

int __cdecl sub_00481810(); // 0x00481810

int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820

D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860

int __fastcall sub_004B9590(void* pEntry); // 0x004B9590

void* __fastcall sub_004B9610(int nId); // 0x004B9610

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __cdecl USEITEM_DrawUseItemPanel(); // 0x004BFDD0

int __fastcall sub_004DBB50(D2PanelGfxStrc* pGfx, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5, int* pOut, int nArg7, int nArg8); // 0x004DBB50

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

int __fastcall sub_004DC110(void* pArg1, int nArg2, int nArg3, int nArg4, void* pfnCallback, int nArg6, int nArg7); // 0x004DC110

int __fastcall D2SOUNDSMP_ReadWaveHeader(int nSocket, int* pParam, D2AddressInfoStrc* pInfo); // 0x00516760

int __stdcall sub_006001F0(D2PanelGfxStrc* pGfx, int nArg2, int nArg3); // 0x006001F0

D2TileStrc* __stdcall DUNGEON_GetTileDataFromAct(void* pAct); // 0x00619720

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall sub_006275B0(D2UnitStrc* pUnit); // 0x006275B0

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x006277F0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit, D2SkillStrc* skill); // 0x004D9FC0

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0

int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

#pragma pack(push, 1)

struct D2GSPacketSrv7DStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
    int dwItemId;
    int dwAction;
    int bSet;
};

#pragma pack(pop)

void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280

void __fastcall GFX_RequeuePlayerMode(D2UnitStrc* pUnit); // 0x0046F950

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610

void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60

int __fastcall ITEMMODE_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x004C10E0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

unsigned char __stdcall UNITS_GetItemComponentId(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00623D60

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem); // 0x00629A40

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D1D0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0

int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

#pragma pack(push, 1)

struct D2PacketRecord8Strc
{
    unsigned char nHeader;
    unsigned char nCursor;
    unsigned int dwItemId;
    unsigned short nSkill;
};

struct D2PacketRecord13Strc
{
    unsigned char nHeader;
    unsigned int nItemGUID;
    unsigned int dwFlag;
    unsigned int bSet;
};

struct D2GSPacketSrv42Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};

#pragma pack(pop)

short gwRightHandWeaponClass;                                                                                    // 0x007C78A8

short gwLeftHandWeaponClass;                                                                                    // 0x007C78AC

extern int gaCursorKind[]; // 0x00727A40

extern unsigned int gnCursorKindCount; // 0x00727A48

void __fastcall sub_004B29E0(int nUnitId); // 0x004B29E0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall sub_00468010(D2UnitStrc* pItem, int nCursor); // 0x00468010

extern "C" int gnTable_00727A28[5]; // 0x00727A28

extern "C" unsigned int gnTableCount; // 0x00727A3C

extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0

void __stdcall sub_0063BE30_Return(int nUnused1, int nUnused2);

int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C110

int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory); // 0x0063E0B0

extern "C" const char szItemCppFile[];

#pragma pack(push, 1)

struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02[1];
    unsigned int dwUnitId;
    unsigned char unk0x07[4];
};

#pragma pack(pop)

static void ITEM_RefreshEquippedItems(D2UnitStrc* pUnit); // 0x004C1350

#pragma pack(push, 1)

struct D2GSPacketSrv9D
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char pBitstream[244];
};

#pragma pack(pop)

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __cdecl UI_SendMouseMove(); // 0x00453B00

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680

void __cdecl INV_ResetHover(); // 0x00487990

void __fastcall sub_004B2A00(int nUnitId); // 0x004B2A00

void __fastcall sub_004B2A40(int nUnitId); // 0x004B2A40

void __fastcall ITEM_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bArg); // 0x004C1910

int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_GetCompactItemDataFromBitstreamDefault(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410

void __stdcall ITEM_HandleItemToBody(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave); // 0x004C35F0

void __fastcall sub_004B2640(D2UnitStrc* pUnit); // 0x004B2640

void __fastcall NPCMENU_ResetHoverForItem(int nUnitId); // 0x004B2A80

int __cdecl NPCMENU_IsNpcMenuActive(); // 0x004B2E20

int __fastcall NPCMENU_GetInteractNpcId(int* pLow); // 0x004B3230

void __fastcall VIEW_SetBeltSlotValue(int nX, int nArg); // 0x00498D50

void __cdecl VIEW_ResetBeltHover(); // 0x00498D60

void __fastcall sub_004B2A60(int nUnitId); // 0x004B2A60

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define D2_ASSERT_LINE(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static void __stdcall ITEM_ApplyItemStats(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce); // 0x004C0D20

D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag); // 0x00625730

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit); // 0x00627220

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfnCallback); // 0x00625CE0

void __fastcall SKILLDESC_ToggleStateOffCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004C21E0


D2UnitStrc* __fastcall CUNIT_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0

struct D2MonCommandStrc;

#define NULL 0

struct D2InventoryStrc;

static void ITEM_RestoreSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState); // 0x004C1200

static void __stdcall ITEM_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x004C1290

struct D2GameStrc;

void __fastcall SOUNDINST_SetValue(int nKey, int nValue);                                            // 0x004B9B50

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);        // 0x00620A70

void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit);                                                  // 0x00623830

int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame);  // 0x00626D40

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem);                                                   // 0x00629900

unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pItem);                                         // 0x00629FE0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner);                    // 0x0063ABD0

int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);                           // 0x0064C350

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit);                                                      // 0x0064C450


void __fastcall INV_QuestCodeUpdate(int nCode); // 0x0048A540

static void __stdcall ITEM_PlaceItemAt(unsigned short nY, unsigned char nPage, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned short nX); // 0x004C2970

static D2UnitStrc* __stdcall ITEM_CreateWorldItem(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave); // 0x004C0F20

static D2UnitStrc* __stdcall ITEM_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave); // 0x004C0FF0

static void ITEM_SaveSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState); // 0x004C1160

static int ITEM_GetDropSoundAndDelay(D2UnitStrc* pItem, int* pDelay); // 0x004C16D0

static void ITEM_PlayDropSound(D2UnitStrc* pItem); // 0x004C18B0

static void ITEM_StoreHandWeaponClass(D2UnitStrc* pItem, unsigned char nType); // 0x004C1C20


void __fastcall GFX_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue);                        // 0x0046F020

void __fastcall sub_004B2A20(int nUnitId);                                                                  // 0x004B2A20

void __fastcall sub_004B3C00(int nUnitId);                                                                  // 0x004B3C00

int __fastcall ITEM_PlaceBodyItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);    // 0x004C1C50

void __fastcall WINMAIN_SetExitApplication(int nValue);                                                          // 0x0044B880

void __fastcall GAME_SetCinematicExit(int nValue);                                                          // 0x0044C860

void __cdecl GAME_RequestExit();                                                                                // 0x0044D520

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390


void __fastcall ITEM_HandleIndirectSwapBodyItem(D2GSPacketSrv9D* pPacket); // 0x004C3070

static void __stdcall ITEM_PlaceItem(D2UnitStrc* pItem, unsigned short nX, unsigned short nY, int nMode, int bFindRoom, unsigned char nPage); // 0x004C2540

int __fastcall sub_004D9FC0_GetSkillUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill);


static void __stdcall ITEM_RemoveBodyItem(D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x004C1C90

void __fastcall ITEM_HandleItemOnGround(D2GSPacketSrv9C* pPacket); // 0x004C2810

void __fastcall ITEM_HandleEquipItem(D2GSPacketSrv9D* pPacket); // 0x004C2E90

static void __stdcall ITEM_SwapBodyItem(D2ItemSaveStrc* pItemSave, D2GSPacketSrv9D* pPacket); // 0x004C3980

void __fastcall ITEM_HandleWeaponSwitch(D2GSPacketSrv9D* pPacket); // 0x004C3B00

void __fastcall ITEM_HandleAutoUnequip(D2GSPacketSrv9D* pPacket); // 0x004C4740

void __fastcall ITEM_HandleGridItemToBody(D2GSPacketSrv9D* pPacket); // 0x004C4AA0

D2UnitStrc* __fastcall ITEM_HandleBodyGridSwap(D2GSPacketSrv9D* pPacket); // 0x004C4C70


static void __stdcall ITEM_ReattachItemComponent(int nMode, int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem);

void __fastcall ITEM_HandleItemStatePacket(D2GSPacketSrv7DStrc* pPacket);


int __fastcall ITEM_SetChargedSkill(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges); // 0x004C1E40

void __fastcall ITEM_HandleItemToCursor(D2GSPacketSrv9C* pPacket);

void __fastcall ITEM_HandleOwnedItemToCursor(D2GSPacketSrv9D* pPacket);

void __fastcall ITEM_HandleGroundToCursor(D2GSPacketSrv9C* pPacket);

void __fastcall ITEM_HandleDropToGround(D2GSPacketSrv9C* pPacket);

void __fastcall sub_004C2C80_ItemFromStorage9D(D2GSPacketSrv9D* pPacket); // 0x004C2C80

static void __stdcall ITEM_HandleItemFromBody(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave);

void __fastcall ITEM_HandleSwapBodyItem(D2GSPacketSrv9D* pPacket);

void __fastcall ITEM_HandleItemToStorage(D2GSPacketSrv9C* pPacket);

void __fastcall ITEM_HandleShopItem(D2GSPacketSrv9C* pPacket);

void __fastcall ITEM_HandlePutInBelt(D2GSPacketSrv9C* pPacket);

void __fastcall ITEM_HandleRemoveFromBelt(D2GSPacketSrv9C* pPacket);

void __fastcall ITEM_HandleItemToSocket(D2GSPacketSrv9D* pPacket);

static void ITEM_CursorItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave);

static void __stdcall ITEM_BeltItemToCursor(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave);

void __fastcall ITEM_HandleCursorBeltSwap(D2GSPacketSrv9C* pPacket); // 0x004C40D0

static void __stdcall ITEM_MoveItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave);

void __stdcall ITEM_MoveItemFromBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave);

void __fastcall ITEM_HandleBeltSwap(D2GSPacketSrv9C* pPacket); // 0x004C45C0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit);                                                // 0x0046EC10

void __fastcall CUNIT_RemoveInventoryUnits(D2UnitStrc* pUnit, int nArg);                             // 0x00466CB0

void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory);                                        // 0x0063AC40

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

int __stdcall UNITROOM_IsUnitInRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit);                            // 0x0064C260

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit);                                              // 0x0064C370


static inline int GetUnitType(D2UnitStrc* p)
{
    if (p)
    {
        return p->dwUnitType;
    }
    return 6;
}

static inline D2InventoryStrc* GetInventory(D2UnitStrc* p)
{
    if (p)
    {
        return p->pInventory;
    }
    return 0;
}

// 0x004C0D20
static void __stdcall ITEM_ApplyItemStats(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce)
{
    D2ItemsTxt* pItemsTxtRecord;
    D2GemsTxt* pGemsTxtRecord;

    if (!pUnit)
    {
        return;
    }

    if (ITEMSIsA(pItem, 0x14))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x30);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x32);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x34);
        ITEMMODS_AssignProperty(2, NULL, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        D2_ASSERT(GetUnitType(pUnit) == 4, 0x3A);
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x3C);
        pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(pItemsTxtRecord->dwGemOffset);
        D2_ASSERT(pGemsTxtRecord, 0x3E);
        ITEMMODS_AssignProperty(5, pUnit, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x48, ".\\UNIT\\Item.cpp"))
    {
        return;
    }

    if (GetUnitType(pUnit) == 0)
    {
        D2UnitStrc* pLeftHand = INVENTORY_GetLeftHandWeapon(GetInventory(pUnit));
        if (UNITS_CanDualWield(pUnit))
        {
            int bType = 1;
            if (pLeftHand && pItem != pLeftHand && ITEMSIsA(pItem, 0x2D))
            {
                bType = 0;
            }

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0x64, ".\\UNIT\\Item.cpp") && !bForce)
            {
                return;
            }

            STATLIST_MergeStatLists(pUnit, pItem, bType);
            return;
        }
    }

    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x70, ".\\UNIT\\Item.cpp") && !bForce)
    {
        return;
    }

    STATLIST_MergeStatLists(pUnit, pItem, 1);
}

// 0x004C0EC0
void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp)
{
    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp") || bForce)
    {
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    }

    if (bClamp)
    {
        sub_006275B0(pUnit);
    }
}

// 0x004C0F20
static D2UnitStrc* __stdcall ITEM_CreateWorldItem(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nPacketSize - 8;
    if (!pItemSave)
    {
        ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = CUNIT_AllocClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    int nFail;
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &nFail);
    if (nFail)
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        return 0;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xD8, ".\\UNIT\\Item.cpp"))
            MSG_SendDword(0x37, pPacket->nItemId);
    }
    return pItem;
}

// 0x004C0FF0
static D2UnitStrc* __stdcall ITEM_CreateOwnedItem(unsigned short nX, unsigned short nY, int bNotify, D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2ItemSaveStrc tItemSave;
    const int nSize = pPacket->nPacketSize - 0x0D;
    if (!pItemSave)
    {
        ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, nSize, 0, &tItemSave);
        pItemSave = &tItemSave;
    }

    D2UnitStrc* pItem = CUNIT_AllocClientUnit(pPacket->nItemId, pItemSave->nClassId, nX, nY, 4, pItemSave->bMode);
    int nFail;
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &nFail);
    if (nFail)
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        return 0;
    }

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 2))
    {
        ITEMS_SetItemFlag(pItem, 2, 0);
        if (bNotify && !ITEMS_CheckItemFlag(pItem, 0x10, 0xFE, ".\\UNIT\\Item.cpp"))
            MSG_SendDword(0x37, pPacket->nItemId);
    }
    return pItem;
}

struct D2SkillStrc;

// 0x004C10C0
int __fastcall ITEM_IsSkillStateUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (sub_004D9FC0(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }
    return 1;
}

// 0x004C10E0
int __fastcall ITEMMODE_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bResult = ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0);
    if (bResult && ITEMS_GetQuiverType(pItem))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pOtherArmItem == pItem)
        {
            pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        }

        if (!pOtherArmItem || !ITEMSIsA(pOtherArmItem, ITEMS_GetQuiverType(pItem)))
        {
            bResult = 0;
        }
    }

    return bResult;
}

// 0x004C1160
static void ITEM_SaveSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState)
{
    pState->nLife = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    pState->nMana = STATLIST_UnitGetStatValue(pUnit, 8, 0);
    pState->nStamina = STATLIST_UnitGetStatValue(pUnit, 0x0A, 0);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pState->nLeftOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\UNIT\\Item.cpp", 0x155);
    }
    else
    {
        pState->nLeftOwnerGUID = -1;
        pState->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pState->nRightOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\UNIT\\Item.cpp", 0x161);
    }
    else
    {
        pState->nRightOwnerGUID = -1;
        pState->nRightSkillId = 0;
    }
}

// 0x004C1200
static void ITEM_RestoreSkillState(D2UnitStrc* pUnit, D2SkillStateStrc* pState)
{
    if (pState->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit))
        {
            switch (sub_004D9FC0_GetSkillUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetLeftActiveSkill(pUnit, pState->nLeftSkillId, pState->nLeftOwnerGUID);
                break;
            }
        }
    }

    if (pState->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit))
        {
            switch (sub_004D9FC0_GetSkillUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;
            default:
                SKILLS_SetRightActiveSkill(pUnit, pState->nRightSkillId, pState->nRightOwnerGUID);
                break;
            }
        }
    }
}

// 0x004C1290
static void __stdcall ITEM_AttachItem(int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem || !pUnit->pInventory)
        return;

    INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
    if (pUnit->dwUnitType == UNIT_PLAYER)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
    GFX_ClearGfxBytes(pUnit, nComponent);
}

// 0x004C12F0
static void __stdcall ITEM_ReattachItemComponent(int nMode, int nComponent, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pUnit || !pItem)
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0x0B || nBodyLoc == 0x0C)
        return;

    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    GFX_ClearGfxBytes(pUnit, nComponent);
    if (nMode == 1 && !STATLIST_GetOwner(pItem, NULL))
        ITEM_ApplyItemStats(pItem, pUnit, 1);

    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static inline void ITEM_RemoveItemStats(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (pUnit->dwUnitType == UNIT_PLAYER)
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp");
    STATLIST_ExpireUnitStatlist(pUnit, pItem);
}

static inline int sub_H18_UnitFlag9(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

// 0x004C1350
static void ITEM_RefreshEquippedItems(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (sub_0044BE50(pUnit) && !sub_H18_UnitFlag9(pUnit))
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    D2SkillStateStrc tState;
    int bChanged = 0;
    ITEM_SaveSkillState(pUnit, &tState);

    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (pItem && INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit)
            && !STATLIST_GetOwner(pItem, NULL) && ITEMMODE_CheckEquipRequirements(pUnit, pItem))
        {
            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            ITEM_ApplyItemStats(pItem, pUnit, 0);
        }
    }

    for (int i = 0; i < 0x0B; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (!pItem)
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x203, ".\\UNIT\\Item.cpp") && !STATLIST_GetOwner(pItem, NULL))
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x208, ".\\UNIT\\Item.cpp") && !STATLIST_GetOwner(pItem, NULL))
            continue;

        if (ITEMMODE_CheckEquipRequirements(pUnit, pItem))
            continue;

        ITEMS_SetItemFlag(pItem, 0x4000, 1);
        const int nComponent = UNITS_GetItemComponentId(pUnit, pItem);
        ITEM_AttachItem(nComponent, pUnit, pItem);
        bChanged = 1;
    }

    int nTries = 100;
    int bMore;
    do
    {
        bMore = 0;
        for (int i = 0; i < 0x0B; ++i)
        {
            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
            if (!pItem)
                continue;

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0x226, ".\\UNIT\\Item.cpp"))
                continue;

            if (!ITEMS_CheckItemFlag(pItem, 0x4000, 0x22A, ".\\UNIT\\Item.cpp") && STATLIST_GetOwner(pItem, NULL))
                continue;

            if (!ITEMMODE_CheckEquipRequirements(pUnit, pItem))
                continue;

            ITEMS_SetItemFlag(pItem, 0x4000, 0);
            ITEM_ReattachItemComponent(pItem->dwAnimMode, UNITS_GetItemComponentId(pUnit, pItem), pUnit, pItem);
            bMore = 1;
            bChanged = 1;
        }
    }
    while (bMore && nTries--);

    for (int i = 0; i < 0x0B; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem && ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && !ITEMS_CheckItemFlag(pItem, 0x100, 0x247, ".\\UNIT\\Item.cpp")
            && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x248, ".\\UNIT\\Item.cpp"))
        {
            ITEM_RemoveItemStats(pUnit, pItem);
            ITEM_ApplyItemStats(pItem, pUnit, 0);
        }
    }

    ITEM_RestoreSkillState(pUnit, &tState);
    if (bChanged)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            GFX_RequeuePlayerMode(pUnit);
            GFX_RefreshUnitGfx(pUnit, 0);
        }
        else
        {
            MONSTER_HandleMonsterCommand(7, pUnit, NULL);
        }
    }
}

// 0x004C16C0
static void sub_004C16C0_RefreshUnitItems(D2UnitStrc* pUnit)
{
    ITEM_RefreshEquippedItems(pUnit);
}

static inline D2UniqueItemsTxt* ITEM_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    return 0;
}

static inline D2SetItemsTxt* ITEM_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
        return &sgptDataTables->pSetItemsTxt[nIndex];
    return 0;
}

// 0x004C16D0
static int ITEM_GetDropSoundAndDelay(D2UnitStrc* pItem, int* pDelay)
{
    int nSound = 0;
    if (pDelay)
        *pDelay = 0x0C;

    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxt && pItemsTxt->wDropSound > nSound)
    {
        if (pDelay && pItemsTxt->nDropSfxFrame > 0)
            *pDelay = pItemsTxt->nDropSfxFrame;
        nSound = pItemsTxt->wDropSound;
    }

    if (ITEMS_GetItemQuality(pItem) == 7)
    {
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxt = ITEM_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxt && pUniqueItemsTxt->wDropSound > 0)
            {
                if (pDelay && pUniqueItemsTxt->nDropSfxFrame > 0)
                    *pDelay = pUniqueItemsTxt->nDropSfxFrame;
                nSound = pUniqueItemsTxt->wDropSound;
            }
        }
    }
    else if (ITEMS_GetItemQuality(pItem) == 5)
    {
        D2SetItemsTxt* pSetItemsTxt = ITEM_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxt && pSetItemsTxt->wDropSound > 0)
        {
            if (pDelay && pSetItemsTxt->nDropSfxFrame > 0)
                *pDelay = pSetItemsTxt->nDropSfxFrame;
            nSound = pSetItemsTxt->wDropSound;
        }
    }
    return nSound;
}

// 0x004C17F0
static int ITEM_ResolveItemUseSound(D2UnitStrc* pItem)
{
    int nSound = 0;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxtRecord && pItemsTxtRecord->wDropSound > 0)
        nSound = pItemsTxtRecord->wUseSound;

    if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE)
    {
        const int nIndex = ITEMS_GetFileIndex(pItem);
        D2UniqueItemsTxt* pRecord = (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount) ? &sgptDataTables->pUniqueItemsTxt[nIndex] : 0;
        if (pRecord && pRecord->wDropSound > 0)
            nSound = pRecord->wUseSound;
    }
    else if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        const int nIndex = ITEMS_GetFileIndex(pItem);
        D2SetItemsTxt* pRecord = (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nIndex] : 0;
        if (pRecord && pRecord->wDropSound > 0)
            nSound = pRecord->wUseSound;
    }

    return nSound;
}

// 0x004C18B0
static void ITEM_PlayDropSound(D2UnitStrc* pItem)
{
    int nDelay = 0x0C;
    const int nSound = ITEM_GetDropSoundAndDelay(pItem, &nDelay);
    sub_004B9A00(0xD8, pItem, 0, 0, 0);
    if (nSound > 0)
    {
        const int nHandle = sub_004B9A00(nSound, pItem, nDelay, 0, 0);
        if (nHandle)
            SOUNDINST_SetValue(nHandle, 0xB4);
    }
}

// 0x004C1910
void __fastcall ITEM_SetItemMode(D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int bInit)
{
    if (nMode >= 7)
        return;

    const int nCurrentMode = pItem->dwAnimMode;
    if ((nCurrentMode == 5 || nCurrentMode == 3) && nMode != 5 && nMode != 3)
        UNITS_FreeCollisionPath(pItem);

    pItem->dwAnimMode = nMode;
    UNITROOM_UpdatePath(pItem);
    switch (pItem->dwAnimMode)
    {
    case 5:
        UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pItem, pRoom);
        pItem->dwFlags &= ~2;
        UNITS_SetAnimStartFrame(pItem);
        ITEM_PlayDropSound(pItem);
        break;

    case 3:
        UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
        UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(pItem, pRoom);
        pItem->dwFlags |= 2;
        UNITS_SetAnimStartFrame(pItem);
        break;

    case 4:
        sub_004B9A00(0xEB, 0, 0, 0, 0);
    case 0:
    case 1:
    case 2:
    case 6:
        pItem->dwFlags &= ~2;
        break;

    default:
        return;
    }

    pItem->dwFlags &= ~4;
    pItem->dwFlags &= ~0x08;
    pItem->dwFlags |= 0x20;
    if (!bInit)
        return;

    ITEMS_SetItemFlag(pItem, 0x10, 1);
    STATLIST_AllocStatListEx(pItem, 0, 0, 0);
    unsigned int nId = pItem->dwUnitId;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(0, 0x40, 0, 4, nId);
    D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
    if (ITEMS_CheckIfSocketable(pItem) && !pItem->pInventory)
        INVENTORY_AllocInventory(0, pItem);
}

// 0x004C1A70
void __fastcall ITEM_ReleaseItemUnit(D2UnitStrc* pUnit)
{
    GFX_FreeGfxData(pUnit);
    if (ITEMS_CheckIfSocketable(pUnit))
    {
        CUNIT_RemoveInventoryUnits(pUnit, 0);
        INVENTORY_FreeInventory(pUnit->pInventory);
        pUnit->pInventory = 0;
    }

    if (gpGlobal_007A0634)
    {
        UNITS_FreeCollisionPath(pUnit);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (UNITROOM_IsUnitInRoom(pRoom, pUnit))
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
    }
}

// 0x004C1AD0
void __fastcall ITEM_UpdateItemAnim(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x348);
    switch (pUnit->dwAnimMode)
    {
    case 5:
        if (UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            pUnit->dwAnimMode = 3;
            break;
        }

        UNITS_UpdateFrame(pUnit);
        return;

    case 3:
        pUnit->dwFlags |= 2;
        if (sub_0046E100(pUnit, 0x46))
        {
            return;
        }
        break;

    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
        pUnit->dwFlags &= ~2;
        return;

    default:
        D2_ASSERT(0, 0x362);
    }

    GFX_AddUnitOverlay(pUnit, 0x46, 6, 8, 0, 0, 8, 0);
}


// 0x004C1B80
void __fastcall ITEM_HandleItemCommand(int nEvent, D2UnitStrc* pUnit, int bSet, int nMode)
{
    switch (nEvent)
    {
    case 2:
        UNITS_ChangeAnimMode(pUnit, nMode);
        if (pUnit)
        {
            if (bSet)
            {
                pUnit->dwFlags |= 2;
            }
            else
            {
                pUnit->dwFlags &= ~2;
            }
        }
        break;
    }
}

// 0x004C1BC0
void __fastcall ITEM_RefreshUnitItemsFromPacket(D2PacketRecord11Strc* pPacket, int nArg)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
        sub_004C16C0_RefreshUnitItems(pUnit);
}

// 0x004C1BE0
static void sub_004C1BE0_RefreshUnitItems(D2UnitStrc* pUnit)
{
    ITEM_RefreshEquippedItems(pUnit);
}

// 0x004C1BF0
void __fastcall ITEM_RefreshUnitItemsFromRecord(D2PacketRecord11Strc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
        sub_004C1BE0_RefreshUnitItems(pUnit);
}

// 0x004C1C10
void __fastcall ITEM_RefreshUnitEquipment(D2UnitStrc* pUnit)
{
    ITEM_RefreshEquippedItems(pUnit);
}

// 0x004C1C20
static void ITEM_StoreHandWeaponClass(D2UnitStrc* pItem, unsigned char nType)
{
    const int nWeaponClass = ITEMS_GetWeaponClassId(pItem);
    if (nType == 4)
        gwRightHandWeaponClass = nWeaponClass;
    else if (nType == 5)
        gwLeftHandWeaponClass = nWeaponClass;
}

// 0x004C1C50
int __fastcall ITEM_PlaceBodyItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc)
{
    if (!pItem)
    {
        return 0;
    }

    if (INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc))
    {
        sub_0063BE30(pInventory, nBodyLoc);
    }

    return sub_0063BDB0(pInventory, pItem, nBodyLoc) != 0;
}

// 0x004C1C90
static void __stdcall ITEM_RemoveBodyItem(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 4 || nBodyLoc == 5)
    {
        INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
        GFX_ClearGfxBytes(pUnit, UNITS_GetItemComponentId(pUnit, pItem));
        INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, nBodyLoc);
    }

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (pRemoved)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        }

        if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
        }

        sub_0063BE30(pInventory, nBodyLoc);
    }

    CUNIT_RemoveClientSideUnit(!pItem ? -1 : pItem->dwUnitId, !pItem ? 6 : pItem->dwUnitType);
}

static inline D2UniqueItemsTxt* ITEMS_GetUniqueItemsTxtRecordInline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nUniqueItemsTxtRecordCount)
        return &sgptDataTables->pUniqueItemsTxt[nId];
    return 0;
}

static inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordInline(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSetItemsTxtRecordCount)
        return &sgptDataTables->pSetItemsTxt[nId];
    return 0;
}

// 0x004C1D60
int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem)
{
    int nSound = 0;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxt && pItemsTxt->wDropSound > 0)
        nSound = pItemsTxt->wDropSound;

    if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE)
    {
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxt = ITEMS_GetUniqueItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxt && pUniqueItemsTxt->wDropSound > 0)
                nSound = pUniqueItemsTxt->wDropSound;
        }
    }
    else if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxt && pSetItemsTxt->wDropSound > 0)
            nSound = pSetItemsTxt->wDropSound;
    }
    return nSound;
}

// 0x004C1E20
int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem)
{
    return ITEM_ResolveItemUseSound(pItem);
}

// 0x004C1E30
void __cdecl ITEM_ResetWeaponClasses()
{
    gwRightHandWeaponClass = 0;
    gwLeftHandWeaponClass = 0;
}

void __stdcall sub_004C0D20_CallerA(int nArg, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    ITEM_ApplyItemStats(pItem, pUnit, 0);
    ITEMS_UpdateSets(pUnit, pItem, nArg, nArg);
    ITEM_ApplyItemStats(pItem, pUnit, nArg);
    ITEMS_UpdateSets(pUnit, pItem, nArg, 0);
}

// 0x004C1E40
int __fastcall ITEM_SetChargedSkill(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges)
{
    const int nLayer = (nSkillId << sgptDataTables->nStuff) + (nSkillLevel & sgptDataTables->nShiftedStuff);

    for (D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pItem, 0x40); pStatList; pStatList = STATLIST_GetStatListFromFlag(pStatList, 0x40))
    {
        int nValue = STATLIST_GetStatValue(pStatList, STAT_ITEM_CHARGED_SKILL, nLayer);
        if (nValue)
        {
            nValue >>= 8;
            if (nValue > 0 && nValue <= 255)
            {
                nCharges = D2_MIN(D2_MAX(nCharges, 0), nValue);
                STATLIST_SetBaseStat2(pStatList, STAT_ITEM_CHARGED_SKILL, (nValue << 8) + (nCharges & 0xFF), nLayer, pItem);
                return 1;
            }
            return 0;
        }
    }

    D2InventoryStrc* pInventory = pItem->pInventory;
    if (pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            if (ITEM_SetChargedSkill(pSocketed, nSkillId, nSkillLevel, nCharges))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x004C1F30
void __fastcall ITEM_UpdateItemStat(unsigned int nA, unsigned char nB, unsigned int nC, unsigned int nD, unsigned short nE)
{
    D2UnitStrc* pItem = CUNIT_FindClientUnit(nA, 4);
    if (!pItem)
        return;

    if (nC == 0xCC)
    {
        if (sub_00463DD0_GetPlayerUnit())
            ITEM_SetChargedSkill(pItem, nE >> sgptDataTables->nStuff, nE & sgptDataTables->nShiftedStuff, nD & 0xFF);
        return;
    }

    if (nB == 1)
        STATLIST_SetUnitStat(pItem, nC, nD, 0);

    if (!sub_00463DD0_GetPlayerUnit())
        return;

    if (nC != 0x46)
    {
        ITEM_RefreshEquippedItems(sub_00463DD0_GetPlayerUnit());
        return;
    }

    if ((int)nD <= 0)
        return;

    if (sub_006280A0(pItem, 4, 0xA38, (unsigned int)".\\UNIT\\Item.cpp"))
        ITEMS_SetItemFlag(pItem, 4, 0);

    if (sub_006280A0(pItem, 0x4000, 0xA3C, (unsigned int)".\\UNIT\\Item.cpp"))
        ITEMS_SetItemFlag(pItem, 0x4000, 0);
}

// 0x004C2020
void __fastcall ITEM_SetItemFlagFromPacket(D2PacketRecord13Strc* pPacket)
{
    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemGUID, 4);
    if (pItem)
        ITEMS_SetItemFlag(pItem, pPacket->dwFlag, pPacket->bSet);
}

// 0x004C2050
void __fastcall ITEM_ClearCursorItemFromPacket(D2GSPacketSrv42Strc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitGUID, pPacket->nUnitType);
    if (!pUnit)
        return;
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (!pItem)
        return;
    int nItemId = pItem->dwUnitId;
    INVENTORY_SetCursorItem(pInventory, 0);
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    CUNIT_RemoveClientSideUnit(nItemId, pItem->dwUnitType);
    sub_004B29E0(nItemId);
}

// 0x004C20B0
void __fastcall ITEM_HandleItemToCursor(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0xB0C);

    if (CUNIT_FindClientUnit(pPacket->nItemId, 4))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
    }

    D2UnitStrc* pItem = ITEM_CreateWorldItem(0, 0, 0, pPacket, &tItemSave);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0xB13);

    INVENTORY_SetCursorItem(pInventory, pItem);
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

// 0x004C2150
int __fastcall ITEM_FindInTable(int nValue)
{
    for (unsigned int i = 0; i < gnTableCount; ++i)
    {
        if (nValue == gnTable_00727A28[i])
            return 4;
    }
    return 3;
}

// 0x004C2180
void __fastcall ITEM_ClearUninterruptableState(D2UnitStrc* hItem)
{
    D2_ASSERT(hItem, 0xCC2);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(hItem, STATE_UNINTERRUPTABLE);
    if (pStatList)
    {
        STATES_ToggleState(hItem, 0x36, 0);
        D2Common_10474(hItem, pStatList);
        STATLIST_FreeStatList(pStatList);
        UnitUpdateAnimRateAndVel(hItem, ".\\UNIT\\Item.cpp", 0xCCA);
    }
}

// 0x004C21E0
void __fastcall SKILLDESC_ToggleStateOffCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

// 0x004C21F0
void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_UNINTERRUPTABLE);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 2, 0x0C, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        STATLIST_SetState(pStatList, STATE_UNINTERRUPTABLE);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLDESC_ToggleStateOffCallback);
    }
    else
    {
        STATLIST_SetState(pStatList, STATE_UNINTERRUPTABLE);
    }
}

// 0x004C2240
int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pUnit)
{
    if (STATLIST_GetStatListFromUnitAndFlag(pUnit, 2))
        return 1;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer && STATES_CheckState(pPlayer, STATE_UNINTERRUPTABLE))
        return 1;
    return 0;
}

// 0x004C2270
void __fastcall ITEM_HandleItemStatePacket(D2GSPacketSrv7DStrc* pPacket)
{
    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->dwItemId, 4);
    if (!pItem)
        return;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    const int nComponent = UNITS_GetItemComponentId(pUnit, pItem);
    const int nMode = pItem->dwAnimMode;
    if (pPacket->dwAction == 0x100)
    {
        ITEMS_SetItemFlag(pItem, 0x100, pPacket->bSet);
        GFX_RequeuePlayerMode(pUnit);
        ITEM_AttachItem(nComponent, pUnit, pItem);
        GFX_RefreshUnitGfx(pUnit, 0);
        ITEMS_UpdateSets(pUnit, pItem, 1, 1);
        ITEM_RefreshEquippedItems(pUnit);
    }
    else if (pPacket->dwAction == 0x200)
    {
        ITEMS_SetItemFlag(pItem, 0x100, 0);
        ITEM_ReattachItemComponent(nMode, nComponent, pUnit, pItem);
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
        ITEM_RefreshEquippedItems(pUnit);
    }
}

// 0x004C2340
void __fastcall ITEM_HandleOwnedItemToCursor(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
    D2UnitStrc* pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0xD35);

    STATLIST_SetUnitStat(pItem, 0x46, 1, 0);
    D2InventoryStrc* pInventory = pUnit->pInventory;
    INVENTORY_SetCursorItem(pInventory, pItem);
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
}

// 0x004C23E0
void __fastcall ITEM_RemoveEquippedItems(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;

    D2UnitStrc* pNext;
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = pNext)
    {
        pNext = INVENTORY_GetNextItem(pNode);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        D2_ASSERT(pItem, 0xD4F);

        if (INVENTORY_GetItemNodePage(pNode) == 3 || (INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit)))
        {
            GFX_RequeuePlayerMode(pUnit);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved, 0xD5A);
            D2_ASSERT(pRemoved == pItem, 0xD5B);

            if (INVENTORY_GetItemNodePage(pNode) == 3)
                sub_0063BE30_Return((int)pInventory, INVENTORY_GetBodyLocFromEquippedItem(pInventory, pItem));

            ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
            if (pUnit->dwUnitType == UNIT_PLAYER)
                INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

            if (!sub_006280A0(pRemoved, 0x100, 0x96, (unsigned int)".\\UNIT\\Item.cpp"))
                STATLIST_ExpireUnitStatlist(pUnit, pRemoved);

            ITEM_RefreshEquippedItems(pUnit);
        }
    }

    INVENTORY_RemoveAllItems(pInventory);
}

// 0x004C2530
int __cdecl sub_004C2530()
{
    return 0;
}


// 0x004C2540
static void __stdcall ITEM_PlaceItem(D2UnitStrc* pItem, unsigned short nX, unsigned short nY, int nMode, int bFindRoom, unsigned char nPage)
{
    D2_ASSERT(pItem, 0xAC);

    D2ActiveRoomStrc* pRoom = NULL;
    if (bFindRoom && (nX || nY))
    {
        pRoom = sub_00465420_FindRoomAt(nX, nY);
    }

    ITEM_SetItemMode(pItem, pRoom, nX, nY, nMode, 0);
    ITEMS_SetInvPage(pItem, nPage);
}

// 0x004C25B0
void __fastcall ITEM_HandleAddToGround(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 8, 0, &tItemSave);

    D2UnitStrc* pItem = ITEM_CreateWorldItem(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0x384);

    ITEM_ClearUninterruptableState(pItem);
    if (pItem->dwAnimMode == 3 && ITEMS_CheckItemFlag(pItem, 0x2000, 0x388, ".\\UNIT\\Item.cpp"))
    {
        UNITS_ChangeAnimMode(pItem, 5);
        ITEM_PlayDropSound(pItem);
    }
}

// 0x004C2650
void __fastcall ITEM_HandleGroundToCursor(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (tItemSave.bMode == 4)
    {
        D2_ASSERT(!CUNIT_FindClientUnit(pPacket->nItemId, 4), 0x3A0);

        D2UnitStrc* pItem = ITEM_CreateWorldItem(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(pItem, 0x3A2);

        INVENTORY_SetCursorItem(pInventory, pItem);
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        ITEM_ClearUninterruptableState(pItem);
    }
}

// 0x004C26F0
void __fastcall ITEM_HandleDropToGround(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pItem)
    {
        D2InventoryStrc* pInventory = pPlayer->pInventory;
        D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
        if (pCursorItem && pCursorItem == pItem)
        {
            INVENTORY_SetCursorItem(pInventory, NULL);
            CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }

        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = ITEM_CreateWorldItem(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
        }
    }
    else
    {
        pItem = ITEM_CreateWorldItem(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    }

    D2_ASSERT(pItem, 0x3CF);
    ITEM_ClearUninterruptableState(pItem);
    ITEM_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, 5, 1, tItemSave.nStorePage);
}

// 0x004C2810
void __fastcall ITEM_HandleItemOnGround(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pItem)
    {
        switch (pItem->dwAnimMode)
        {
        case 0:
            D2_ASSERT(0, 0x3FD);
            break;

        case 1:
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            D2_ASSERT(pPlayer, 0x3E9);

            D2InventoryStrc* pInventory = pPlayer->pInventory;
            GFX_RequeuePlayerMode(pPlayer);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            GFX_ClearGfxBytes(pPlayer, UNITS_GetItemComponentId(pPlayer, pItem));

            const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
            INVENTORY_GetSecondWieldingWeapon(pPlayer, pInventory, &pItem, nBodyLoc);

            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            if (pRemoved)
            {
                sub_0063BE30(pInventory, nBodyLoc);
                if (pPlayer->dwUnitType == UNIT_PLAYER)
                {
                    INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                }

                if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
                {
                    STATLIST_ExpireUnitStatlist(pPlayer, pRemoved);
                }
            }

            ITEM_RefreshEquippedItems(pPlayer);
            GFX_RefreshUnitGfx(pPlayer, 0);
            break;
        }
        }

        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
    }

    pItem = ITEM_CreateWorldItem(tItemSave.nX, tItemSave.nY, 0, pPacket, &tItemSave);
    D2_ASSERT(pItem, 0x405);
    ITEM_ClearUninterruptableState(pItem);
}

static inline int ITEMPKT_GetUnitX(D2UnitStrc* pUnit)
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

static inline int ITEMPKT_GetUnitY(D2UnitStrc* pUnit)
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

// 0x004C2970
static void __stdcall ITEM_PlaceItemAt(unsigned short nY, unsigned char nPage, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned short nX)
{
    UNITS_SetXForStaticUnit(pItem, nX);
    UNITS_SetYForStaticUnit(pItem, nY);

    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 0x413);

    if (!INVENTORY_PlaceItemInSocket(hInventory, pItem, 1))
    {
        return;
    }

    if (!sub_0063BCC0_PlaceItem(hInventory, pItem, ITEMPKT_GetUnitX(pItem), ITEMPKT_GetUnitY(pItem), UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion()), 1, nPage))
    {
        return;
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (nPage == 1)
        {
            sub_004B9A00(ITEM_GetDropSound(pItem), NULL, 0, 0, 0);
        }
        else
        {
            INVENTORY_SetCursorItem(hInventory, NULL);
            CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(hInventory));
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage == 3)
    {
        const int nClassId = pItem->dwClassId;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
        if (pItemsTxtRecord->dwCode == 0x20747368 || pItemsTxtRecord->dwCode == 0x20326671)
        {
            INV_QuestCodeUpdate(pItemsTxtRecord->dwCode);
        }
    }
}

static inline unsigned int ITEMPKT_GetItemCode(D2UnitStrc* pItem)
{
    return DATATBLS_GetItemsTxtRecord(pItem->dwClassId)->dwCode;
}

// 0x004C2AD0
void __fastcall ITEM_HandleItemToStorage(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pItem)
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            if (INVENTORY_RemoveItemFromInventory(pPlayer->pInventory, pItem))
            {
                const unsigned char nPage = ITEMS_GetInvPage(pItem);
                const int nRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
                INVENTORY_Return(".\\UNIT\\Item.cpp", 0x456, pPlayer->pInventory, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), nRecordId, 1, nPage);
                INV_ResetHover();
                if (pPlayer->dwUnitType == UNIT_PLAYER)
                {
                    INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
                }

                if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
                {
                    STATLIST_ExpireUnitStatlist(pPlayer, pItem);
                }
            }

            CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = ITEM_CreateWorldItem(0, 0, 0, pPacket, &tItemSave);
            if (!pItem)
            {
                return;
            }
        }
        else
        {
            ITEM_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, tItemSave.bMode, 0, tItemSave.nStorePage);
            ITEMS_SetItemFlag(pItem, -1, 0);
            ITEMS_SetItemFlag(pItem, tItemSave.dwFlags, 1);
        }
    }
    else
    {
        pItem = ITEM_CreateWorldItem(0, 0, 1, pPacket, &tItemSave);
    }

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    ITEM_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pPlayer, pItem, tItemSave.nX);
    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        ITEM_ApplyItemStats(pItem, pPlayer, 0);
    }

    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pItem);
    sub_004B2A40(!pItem ? -1 : pItem->dwUnitId);
}

// 0x004C2C80
void __fastcall ITEM_HandleItemFromStorage(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 13, 0, &tItemSave);

    D2UnitStrc* pOwner = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pOwner)
    {
        return;
    }

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (!pItem)
    {
        if (tItemSave.nStorePage == 1)
        {
            sub_00463DD0_GetPlayerUnit();
        }
        return;
    }

    D2InventoryStrc* pInventory = pOwner->pInventory;
    D2_ASSERT_LINE(pInventory, 1207);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        if (tItemSave.nStorePage == 2)
        {
            sub_00463DD0_GetPlayerUnit();
        }
        return;
    }
    D2_ASSERT_LINE(pRemoved == pItem, 1227);

    unsigned char nPage = ITEMS_GetInvPage(pItem);
    int bLoD = GAME_IsExpansion();
    int nInventoryRecordId = UNITS_GetInventoryRecordId(pOwner, nPage, bLoD);
    INVENTORY_Return(".\\UNIT\\Item.cpp", 1231, pInventory, tItemSave.nX, tItemSave.nY, nInventoryRecordId, 1, nPage);
    INV_ResetHover();

    if (pOwner->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pOwner->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 150, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pOwner, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT_LINE(pItem, 1245);
        }
        else
        {
            ITEM_PlaceItem(pItem, tItemSave.nX, tItemSave.nX, tItemSave.bMode, 0, tItemSave.nStorePage);
        }

        ITEMS_SetInvPage(pItem, 0xFF);
        INVENTORY_SetCursorItem(pInventory, pItem);
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        ITEM_ClearUninterruptableState(pItem);
    }
    else
    {
        CUNIT_RemoveClientSideUnit(pItem->dwUnitId, 4);
        if (pOwner == sub_00463DD0_GetPlayerUnit())
        {
            if (tItemSave.nStorePage == 1)
            {
                sub_004B9A00(1, 0, 0, 0, 0);
            }
            else
            {
                CURSOR_SetCursorItemState(0);
            }
        }
    }

    if (pOwner == sub_00463DD0_GetPlayerUnit())
    {
        sub_004B2A00(pItem->dwUnitId);
    }
}

// 0x004C2E90
void __fastcall ITEM_HandleEquipItem(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pItem)
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            ITEM_RemoveBodyItem(pItem, pUnit);
            pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
        }
        else
        {
            ITEM_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
        }
    }
    else
    {
        pItem = ITEM_CreateOwnedItem(0, 0, pUnit == pPlayer, pPacket, &tItemSave);
    }

    if (pItem)
    {
        ITEMS_SetBodyLocation(pItem, tItemSave.nBodyloc);
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    int nPage = 3;
    if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
    {
        return;
    }

    if (!ITEM_PlaceBodyItem(pInventory, pItem, tItemSave.nBodyloc))
    {
        return;
    }

    GFX_RequeuePlayerMode(pUnit);
    if (nPage == 3)
    {
        INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
    }

    GFX_FillGfxEntries(pUnit, 0);
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
        break;

    default:
        return;
    }

    const unsigned char nComponent = pPacket->nComponent;
    if (nComponent == 0 || nComponent == 1)
    {
        GFX_ClearGfxBytes(pUnit, nComponent);
    }

    GFX_RefreshUnitGfx(pUnit, 0);
    if (pUnit == pPlayer)
    {
        ITEM_StoreHandWeaponClass(pItem, tItemSave.nBodyloc);
        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 8))
        {
            INVENTORY_SetCursorItem(pInventory, NULL);
            CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }
    }

    if (tItemSave.nBodyloc < 0x0B)
    {
        ITEM_ApplyItemStats(pItem, pUnit, 0);
    }

    ITEM_RefreshEquippedItems(pUnit);
    ITEM_RefreshEquippedItems(pUnit);
    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pItem);
    sub_004B3C00(!pItem ? -1 : pItem->dwUnitId);
}

static inline int ITEMPKT_UnitFlag9(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

// 0x004C3070
void __fastcall ITEM_HandleIndirectSwapBodyItem(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    GFX_RequeuePlayerMode(pUnit);

    int nOtherLoc;
    switch (tItemSave.nBodyloc)
    {
    case 5:
        nOtherLoc = 4;
        break;

    case 4:
        nOtherLoc = 5;
        break;

    case 0x0C:
        nOtherLoc = 4;
        break;

    case 0x0B:
        nOtherLoc = 5;
        break;

    default:
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherLoc);
    D2_ASSERT(pItem, 0x5EF);

    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    GFX_ClearGfxBytes(pUnit, UNITS_GetItemComponentId(pUnit, pItem));
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, nOtherLoc);

    int bRemoved = 0;
    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (pRemoved && pRemoved == pItem)
    {
        bRemoved = 1;

        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        }

        if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
        }

        sub_0063BE30(pInventory, nOtherLoc);
        GFX_RefreshUnitGfx(pUnit, 0);

        if (pUnit == pPlayer)
        {
            INV_ResetHover();
            if (tItemSave.nBodyloc == 4)
            {
                gwRightHandWeaponClass = 0;
            }
            else if (tItemSave.nBodyloc == 5)
            {
                gwLeftHandWeaponClass = 0;
            }

            ITEM_PlaceItem(pItem, 0, 0, 4, 0, tItemSave.nStorePage);
            ITEMS_SetBodyLocation(pItem, 0);
            INVENTORY_SetCursorItem(pInventory, pItem);
            CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        }
    }

    D2_ASSERT(bRemoved, 0x5F7);

    ITEM_ClearUninterruptableState(pItem);

    D2UnitStrc* pNewItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pNewItem)
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
            pNewItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(pNewItem, 0x618);
        }
        else
        {
            ITEM_PlaceItem(pNewItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
        }
    }
    else
    {
        pNewItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
    }

    ITEMS_SetBodyLocation(pNewItem, tItemSave.nBodyloc);

    int nPage = 3;
    if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pNewItem, nPage))
    {
        return;
    }

    if (!ITEM_PlaceBodyItem(pInventory, pNewItem, tItemSave.nBodyloc))
    {
        return;
    }

    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pNewItem);
    GFX_FillGfxEntries(pUnit, 0);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
        break;

    default:
        D2_ASSERT(0, 0x641);
        break;
    }

    const unsigned char nComponent = pPacket->nComponent;
    if (nComponent == 0 || nComponent == 1)
    {
        GFX_ClearGfxBytes(pUnit, nComponent);
    }

    GFX_RefreshUnitGfx(pUnit, 0);
    ITEM_StoreHandWeaponClass(pNewItem, tItemSave.nBodyloc);
    ITEM_ApplyItemStats(pNewItem, pUnit, 0);
    ITEM_RefreshEquippedItems(pUnit);
    ITEM_RefreshEquippedItems(pUnit);
    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pNewItem);
}

// 0x004C3380
void __fastcall ITEM_HandleUnequipItem(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int bToCursor = 0;
    D2InventoryStrc* pInventory;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    pInventory = pUnit->pInventory;
    D2_ASSERT(pUnit->pInventory, 0x65C);

    D2UnitStrc* hItem = INVENTORY_GetItemFromBodyLoc(pInventory, tItemSave.nBodyloc);
    if (!hItem)
    {
        return;
    }

    GFX_RequeuePlayerMode(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, hItem);
    GFX_ClearGfxBytes(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &hItem, tItemSave.nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, hItem);
    sub_0063BE30(pInventory, tItemSave.nBodyloc);
    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    ITEM_RefreshEquippedItems(pUnit);
    GFX_RefreshUnitGfx(pUnit, 0);

    if (pUnit == pPlayer)
    {
        sub_004B2A20(!hItem ? -1 : hItem->dwUnitId);
        INV_ResetHover();
        if (tItemSave.nBodyloc == 4)
        {
            gwRightHandWeaponClass = 0;
        }
        else if (tItemSave.nBodyloc == 5)
        {
            gwLeftHandWeaponClass = 0;
        }

        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
        {
            if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
            {
                CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
                hItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
                D2_ASSERT(hItem, 0x67E);
            }
            else
            {
                ITEM_PlaceItem(hItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
            }

            ITEMS_SetBodyLocation(hItem, 0);
            INVENTORY_SetCursorItem(pInventory, hItem);
            CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
            ITEM_RefreshEquippedItems(pUnit);
            ITEM_RefreshEquippedItems(pUnit);
            bToCursor = 1;
        }
        else
        {
            CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        }
    }
    else if (CUNIT_FindClientUnit(pPacket->nItemId, 4))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
    }

    if (bToCursor && hItem)
    {
        ITEM_ClearUninterruptableState(hItem);
        if (ITEMS_CheckItemFlag(hItem, 0x4000, 0x69C, ".\\UNIT\\Item.cpp"))
        {
            ITEMS_SetItemFlag(hItem, 0x4000, 0);
        }
    }
}

// 0x004C35F0
void __stdcall ITEM_HandleItemToBody(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x6B0);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x6B7);
    }
    else
    {
        ITEM_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    ITEMS_SetBodyLocation(pItem, pItemSave->nBodyloc);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x6BE);

    int nPage = 3;
    if (pItemSave->nBodyloc == 0x0B || pItemSave->nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
    {
        return;
    }

    if (!ITEM_PlaceBodyItem(pInventory, pItem, pItemSave->nBodyloc))
    {
        return;
    }

    GFX_RequeuePlayerMode(pUnit);
    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
    GFX_FillGfxEntries(pUnit, 0);
    ITEM_ApplyItemStats(pItem, pUnit, 0);
    ITEM_RefreshEquippedItems(pUnit);
    ITEM_RefreshEquippedItems(pUnit);
    ITEM_StoreHandWeaponClass(pItem, pItemSave->nBodyloc);
    GFX_RefreshUnitGfx(pUnit, 0);
    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pItem);
}

// 0x004C3760
static void __stdcall ITEM_HandleItemFromBody(D2GSPacketSrv9D* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x6ED);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x6EF);

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, pItemSave->nBodyloc);
    GFX_RequeuePlayerMode(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    GFX_ClearGfxBytes(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, pItemSave->nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x6F7);
    D2_ASSERT(pRemoved == pItem, 0x6F8);

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    sub_0063BE30(pInventory, pItemSave->nBodyloc);

    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, pItemSave);
            D2_ASSERT(pItem, 0x703);
        }
    }
    else
    {
        ITEM_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        INV_ResetHover();
        ITEMS_SetBodyLocation(pItem, 0);
        INVENTORY_SetCursorItem(pInventory, pItem);
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        ITEM_ClearUninterruptableState(pItem);
    }
}

// 0x004C3920
void __fastcall ITEM_HandleSwapBodyItem(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);
    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x40))
    {
        ITEM_HandleItemToBody(pPacket, &tItemSave);
        return;
    }

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x80))
    {
        ITEM_HandleItemFromBody(pPacket, &tItemSave);
    }
}

// 0x004C3980
static void __stdcall ITEM_SwapBodyItem(D2ItemSaveStrc* pItemSave, D2GSPacketSrv9D* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x750);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x753);
    D2_ASSERT(sub_006287A0_TestFlags(pItemSave->dwFlags, 1), 0x755);

    GFX_RequeuePlayerMode(pUnit);

    D2UnitStrc* pOldItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pOldItem)
    {
        ITEM_RemoveBodyItem(pOldItem, pUnit);
    }

    D2UnitStrc* pBodyItem = INVENTORY_GetItemFromBodyLoc(pInventory, pItemSave->nBodyloc);
    if (pBodyItem)
    {
        ITEM_RemoveBodyItem(pBodyItem, pUnit);
    }

    D2UnitStrc* pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, pItemSave);
    D2_ASSERT(pItem, 0x765);

    ITEMS_SetBodyLocation(pItem, pItemSave->nBodyloc);

    int nPage = 3;
    if (pItemSave->nBodyloc == 0x0B || pItemSave->nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
    {
        return;
    }

    if (!sub_0063BDB0(pInventory, pItem, pItemSave->nBodyloc))
    {
        return;
    }

    if (pItemSave->nBodyloc != 4 && pItemSave->nBodyloc != 5)
    {
        ITEM_RefreshEquippedItems(pUnit);
        ITEM_RefreshEquippedItems(pUnit);
    }
    else
    {
        INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
        GFX_FillGfxEntries(pUnit, 0);
        ITEM_ApplyItemStats(pItem, pUnit, 0);
        ITEM_RefreshEquippedItems(pUnit);
        ITEM_RefreshEquippedItems(pUnit);
        ITEM_StoreHandWeaponClass(pItem, pItemSave->nBodyloc);
        GFX_RefreshUnitGfx(pUnit, 0);
    }

    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pItem);
}

// 0x004C3B00
void __fastcall ITEM_HandleWeaponSwitch(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);
    ITEM_SwapBodyItem(&tItemSave, pPacket);
}

// 0x004C3B30
void __fastcall ITEM_UpdateItemFromPacket(D2GSPacketSrv9C* pPacket)
{
    int bFail;
    const int nSize = pPacket->nPacketSize - 8;
    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, UNIT_ITEM);
    ITEMS_DecodeItemFromBitstream(pItem, pPacket->pBitstream, nSize, 0, 0, 0x60, &bFail);
    if (bFail)
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, UNIT_ITEM);
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x7B3);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x7B6);

    if (!sub_006287A0_TestFlags(ITEMS_GetItemFlags(pItem), 8))
    {
        INVENTORY_SetCursorItem(pInventory, 0);
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem)
    {
        ITEM_ClearUninterruptableState(pCursorItem);
    }
}

// 0x004C3C00
void __fastcall ITEM_HandleShopItem(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    int nUnitId;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    if (!NPCMENU_GetInteractNpcId(&nUnitId))
    {
        return;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pPacket->nAction == 0x0C)
    {
        if (!pItem)
        {
            return;
        }

        if (NPCMENU_IsNpcMenuActive())
        {
            INV_ResetHover();
        }

        if (!INVENTORY_RemoveItemFromInventory(pInventory, pItem))
        {
            return;
        }

        const unsigned char nPage = ITEMS_GetInvPage(pItem);
        if (nPage == 0xFF)
        {
            return;
        }

        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0x81B, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, nPage);
        UI_SendMouseMove();
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        NPCMENU_ResetHoverForItem(pPacket->nItemId);
        return;
    }

    if (tItemSave.nStorePage == 0xFF)
    {
        return;
    }

    if (!pItem)
    {
        pItem = ITEM_CreateWorldItem(0, 0, 0, pPacket, &tItemSave);
        ITEMS_SetInvPage(pItem, tItemSave.nStorePage);
    }
    else
    {
        INVENTORY_CompareWithItemsParentInventory(pInventory, pItem);
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = ITEM_CreateWorldItem(0, 0, 0, pPacket, &tItemSave);
            if (!pItem)
            {
                return;
            }

            if (tItemSave.nStorePage != ITEMS_GetInvPage(pItem))
            {
                return;
            }
        }
        else
        {
            ITEM_PlaceItem(pItem, 0, 0, 0, 0, tItemSave.nStorePage);
        }
    }

    ITEMS_SetInvPage(pItem, tItemSave.nStorePage);

    int nX;
    int nY;
    if (!sub_0063B9D0_PlaceItemAt(pInventory, pItem, tItemSave.nX, tItemSave.nY, UNITS_GetInventoryRecordId(pUnit, tItemSave.nStorePage, GAME_IsExpansion()), &nX, &nY, tItemSave.nStorePage))
    {
        return;
    }

    ITEM_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pUnit, pItem, tItemSave.nX);
    sub_004B2640(pUnit);
    ITEM_ClearUninterruptableState(pItem);
}

void __fastcall sub_004C2C80_ItemFromStorage9D(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (!pItem)
    {
        if (tItemSave.nStorePage == 1)
        {
            sub_00463DD0_GetPlayerUnit();
        }
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0x4B7);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        if (tItemSave.nStorePage == 2)
        {
            sub_00463DD0_GetPlayerUnit();
        }
        return;
    }

    D2_ASSERT(pRemoved == pItem, 0x4CB);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion());
    INVENTORY_Return(".\\UNIT\\Item.cpp", 0x4CF, pInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, nPage);
    INV_ResetHover();
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
        {
            CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
            pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(pItem, 0x4DD);
        }
        else
        {
            ITEM_PlaceItem(pItem, tItemSave.nX, tItemSave.nX, tItemSave.bMode, 0, tItemSave.nStorePage);
        }

        ITEMS_SetInvPage(pItem, 0xFF);
        INVENTORY_SetCursorItem(pInventory, pItem);
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        ITEM_ClearUninterruptableState(pItem);
    }
    else
    {
        CUNIT_RemoveClientSideUnit(pItem->dwUnitId, 4);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            if (tItemSave.nStorePage == 1)
            {
                sub_004B9A00(1, NULL, 0, 0, 0);
            }
            else
            {
                CURSOR_SetCursorItemState(NULL);
            }
        }
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        sub_004B2A00(pItem->dwUnitId);
    }
}

// 0x004C3E00
static void ITEM_CursorItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x86C);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = ITEM_CreateWorldItem(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x874);
    }
    else
    {
        ITEM_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x87C);

    UNITS_SetXForStaticUnit(pItem, pItemSave->nX);
    UNITS_SetYForStaticUnit(pItem, pItemSave->nY);
    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        return;
    }

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    if (pItemSave->nStorePage == 0xFF)
    {
        return;
    }

    D2_ASSERT(sub_0063BCC0_PlaceItem(pInventory, pItem, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion()), 1, nPage), 0x892);

    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        ITEM_ApplyItemStats(pItem, pPlayer, 0);
    }

    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pItem);
}

// 0x004C3F60
static void __stdcall ITEM_BeltItemToCursor(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x8A6);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x8AB);

    if (pPlayer->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x8B0);
    D2_ASSERT(pRemoved == pItem, 0x8B1);

    const int nRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
    INVENTORY_Return(".\\UNIT\\Item.cpp", 0x8B4, pInventory, pItemSave->nX, pItemSave->nY, nRecordId, 1, nPage);
    INV_ResetHover();
    if (sub_006287A0_TestFlags(pItemSave->dwFlags, 1))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        pItem = ITEM_CreateWorldItem(0, 0, 0, pPacket, pItemSave);
        D2_ASSERT(pItem, 0x8BB);
    }
    else
    {
        ITEM_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    }

    INVENTORY_SetCursorItem(pInventory, pItem);
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    ITEM_ClearUninterruptableState(pItem);
}

// 0x004C40D0
void __fastcall ITEM_HandleCursorBeltSwap(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    const int nMode = pItem->dwAnimMode;
    if (nMode == 0)
    {
        ITEM_BeltItemToCursor(pPacket, &tItemSave);
    }
    else if (nMode == 4)
    {
        ITEM_CursorItemToBelt(pPacket, &tItemSave);
    }
}

// 0x004C4130
void __fastcall ITEM_HandlePutInBelt(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x8EF);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pItem)
    {
        ITEM_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }
    else
    {
        pItem = ITEM_CreateWorldItem(0, 0, 1, pPacket, &tItemSave);
    }

    UNITS_SetXForStaticUnit(pItem, tItemSave.nX);
    UNITS_SetYForStaticUnit(pItem, tItemSave.nY);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x8FF);

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
    {
        INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, CLIENTS_GetUnitX(pItem));
    }

    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        ITEM_ApplyItemStats(pItem, pPlayer, 0);
    }

    if (tItemSave.dwFlags & 0x400)
    {
        ITEMS_SetItemFlag(pItem, 0x400, 1);
    }

    INVENTORY_SetCursorItem(pInventory, NULL);
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    VIEW_SetBeltSlotValue(ITEMPKT_GetUnitX(pItem), 1);
    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pItem);
    sub_004B2A60(pItem->dwUnitId);
}

// 0x004C42A0
void __fastcall ITEM_HandleRemoveFromBelt(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x92C);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x931);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    if (!pRemoved)
    {
        return;
    }

    D2_ASSERT(pRemoved == pItem, 0x93A);

// build: symbol ?D2COMMON_10267_Return@* 0x0063C550
    D2COMMON_10267_Return(pInventory, tItemSave.nX);
    VIEW_ResetBeltHover();
    VIEW_SetBeltSlotValue(tItemSave.nX, 0);
    if (pPlayer->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 0x20))
    {
        ITEM_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
        INVENTORY_SetCursorItem(pInventory, pItem);
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        ITEM_ClearUninterruptableState(pItem);
    }
    else
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        CURSOR_SetCursorItemState(NULL);
    }
}

// 0x004C43E0
static void __stdcall ITEM_MoveItemToBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x957);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    ITEM_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x963);

    UNITS_SetXForStaticUnit(pItem, pItemSave->nX);
    UNITS_SetYForStaticUnit(pItem, pItemSave->nY);
    if (ITEMSIsA(pItem, 0x0D))
    {
        ITEM_ApplyItemStats(pItem, pPlayer, 0);
    }

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
    {
        D2_ASSERT(INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, CLIENTS_GetUnitX(pItem)), 0x970);
    }

    UI_SendMouseMove();
    ITEM_ClearUninterruptableState(pItem);
}

// 0x004C44D0
void __stdcall ITEM_MoveItemFromBelt(D2GSPacketSrv9C* pPacket, D2ItemSaveStrc* pItemSave)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2_ASSERT(pInventory, 0x98D);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0x98F);
    D2_ASSERT(pRemoved == pItem, 0x990);

    if (pPlayer->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pPlayer->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pPlayer, pItem);
    }

    D2COMMON_10267_Return(pInventory, pItemSave->nX);
    ITEM_PlaceItem(pItem, 0, 0, pItemSave->bMode, 0, pItemSave->nStorePage);
    INVENTORY_SetCursorItem(pInventory, pItem);
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    ITEM_ClearUninterruptableState(pItem);
}

// 0x004C45C0
void __fastcall ITEM_HandleBeltSwap(D2GSPacketSrv9C* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x08, 0, &tItemSave);

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (!pItem)
    {
        return;
    }

    const int nMode = pItem->dwAnimMode;
    if (nMode == 2)
    {
        ITEM_MoveItemFromBelt(pPacket, &tItemSave);
    }
    else if (nMode == 4)
    {
        ITEM_MoveItemToBelt(pPacket, &tItemSave);
    }
}

// 0x004C4620
void __fastcall ITEM_HandleUseStackableItem(D2PacketRecord8Strc* pPacket)
{
    if (pPacket->nSkill != 0xFFFF)
    {
        for (unsigned int i = 0; i < gnCursorKindCount; ++i)
        {
            if (pPacket->nCursor == gaCursorKind[i] && !UI_GetUIVarUnchecked(1))
            {
                UI_SetUIVar(1, 0, 0);
                break;
            }
        }
        D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->dwItemId, 4);
        if (pItem)
            sub_00468010(pItem, pPacket->nCursor);
        return;
    }

    if (pPacket->nCursor == 0xFF)
    {
        D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->dwItemId, 4);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, 4, 0);
            ITEM_ClearUninterruptableState(pItem);
        }
        CURSOR_SetCursorItemState(0);
        return;
    }

    for (unsigned int i = 0; i < gnCursorKindCount; ++i)
    {
        if (pPacket->nCursor == gaCursorKind[i] && !UI_GetUIVarUnchecked(1))
            UI_SetUIVar(1, 0, 0);
    }
    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->dwItemId, 4);
    if (pItem)
    {
        ITEMS_SetItemFlag(pItem, 4, 1);
        sub_00468010(pItem, pPacket->nCursor);
    }
}

// 0x004C4740
void __fastcall ITEM_HandleAutoUnequip(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, 0, GAME_IsExpansion());
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0xAA7);

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, tItemSave.nBodyloc);
    D2_ASSERT(pItem, 0xAA9);

    GFX_RequeuePlayerMode(pUnit);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
    GFX_ClearGfxBytes(pUnit, pPacket->nComponent);
    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &pItem, tItemSave.nBodyloc);

    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
    D2_ASSERT(pRemoved, 0xAAF);
    D2_ASSERT(pRemoved == pItem, 0xAB0);

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
    {
        STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
    }

    ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
    ITEM_ClearUninterruptableState(pRemoved);
    sub_0063BE30(pInventory, tItemSave.nBodyloc);
    GFX_RefreshUnitGfx(pUnit, 0);

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(pItem, 0xABD);
        }
    }
    else
    {
        ITEM_PlaceItem(pItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }

    if (pUnit != sub_00463DD0_GetPlayerUnit())
    {
        return;
    }

    INV_ResetHover();
    if (tItemSave.nBodyloc == 4)
    {
        gwRightHandWeaponClass = 0;
    }
    else if (tItemSave.nBodyloc == 5)
    {
        gwLeftHandWeaponClass = 0;
    }

    if (sub_0063BCC0_PlaceItem(pInventory, pItem, tItemSave.nX, tItemSave.nY, nRecordId, 1, 0))
    {
        if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
        {
            return;
        }

        ITEMS_SetBodyLocation(pItem, 0);
        INVENTORY_SetCursorItem(pInventory, NULL);
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        ITEM_RefreshEquippedItems(pUnit);
        ITEM_RefreshEquippedItems(pUnit);
        ITEM_ClearUninterruptableState(pItem);
    }
    else
    {
        D2_ASSERT(0, 0xADF);
    }
}

// 0x004C4990
void __fastcall ITEM_HandleItemToSocket(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
    if (pItem)
    {
        ITEM_PlaceItem(pItem, tItemSave.nX, tItemSave.nY, tItemSave.bMode, 0, tItemSave.nStorePage);
    }
    else
    {
        pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2_ASSERT(pInventory, 0xB34);

    if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
        if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 8))
        {
            D2InventoryStrc* pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
            D2_ASSERT(pPlayerInventory, 0xB3A);
            INVENTORY_SetCursorItem(pPlayerInventory, NULL);
            CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pPlayerInventory));
        }

        ITEM_ApplyItemStats(pItem, pUnit, 0);
    }

    ITEM_ClearUninterruptableState(pItem);
}


// 0x004C4AA0
void __fastcall ITEM_HandleGridItemToBody(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 0xB77);

    D2UnitStrc* hGridItem = NULL;
    if (pUnit == pPlayer)
    {
        hGridItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
        if (!hGridItem)
        {
            return;
        }

        D2_ASSERT(hGridItem == INVENTORY_RemoveItemFromInventory(hInventory, hGridItem), 0xB83);

        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, 0, GAME_IsExpansion());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0xB85, hInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, 0);
        INV_ResetHover();
        UI_SendMouseMove();
    }

    if (sub_006287A0_TestFlags(tItemSave.dwFlags, 1))
    {
        CUNIT_RemoveClientSideUnit(pPacket->nItemId, 4);
        hGridItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(hGridItem, 0xB8D);
    }
    else if (!hGridItem)
    {
        hGridItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
        D2_ASSERT(hGridItem, 0xB93);
    }
    else
    {
        ITEM_PlaceItem(hGridItem, 0, 0, tItemSave.bMode, 0, tItemSave.nStorePage);
    }

    ITEMS_SetBodyLocation(hGridItem, tItemSave.nBodyloc);

    int nPage = 3;
    if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
    {
        nPage = 4;
    }

    if (!INVENTORY_PlaceItemInSocket(hInventory, hGridItem, nPage))
    {
        return;
    }

    if (!ITEM_PlaceBodyItem(hInventory, hGridItem, tItemSave.nBodyloc))
    {
        return;
    }

    GFX_RequeuePlayerMode(pUnit);
    INVENTORY_UpdateWeaponGUIDOnInsert(hInventory, hGridItem);
    GFX_RefreshUnitGfx(pUnit, 0);
    ITEM_ApplyItemStats(hGridItem, pUnit, 0);
    ITEM_RefreshEquippedItems(pUnit);
    ITEM_RefreshEquippedItems(pUnit);
    ITEM_ClearUninterruptableState(hGridItem);
}

// 0x004C4C70
D2UnitStrc* __fastcall ITEM_HandleBodyGridSwap(D2GSPacketSrv9D* pPacket)
{
    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstreamDefault(pPacket->pBitstream, pPacket->nPacketSize - 0x0D, 0, &tItemSave);

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return NULL;
    }

    D2InventoryStrc* hInventory = pUnit->pInventory;
    if (!hInventory)
    {
        return NULL;
    }

    D2UnitStrc* pItem = NULL;
    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return NULL;
    }

    const unsigned char nMode = tItemSave.bMode;
    if (pUnit == pPlayer && nMode == 0)
    {
        pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
        if (pItem)
        {
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(hInventory, pItem);
            D2_ASSERT(pRemoved == pItem, 0xBF5);

            if (pUnit->dwUnitType == UNIT_PLAYER)
            {
                INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
            }

            if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
            {
                STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
            }

            CUNIT_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
        }

        INV_ResetHover();
        const int nRecordId = UNITS_GetInventoryRecordId(pUnit, tItemSave.nStorePage, GAME_IsExpansion());
        INVENTORY_Return(".\\UNIT\\Item.cpp", 0xBFC, hInventory, tItemSave.nX, tItemSave.nY, nRecordId, 1, tItemSave.nStorePage);
        if (tItemSave.nStorePage == 0xFF)
        {
            return NULL;
        }

        pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
        ITEM_PlaceItemAt(tItemSave.nY, tItemSave.nStorePage, pUnit, pItem, tItemSave.nX);
        if (ITEMS_IsCharmUsable(pItem, pUnit))
        {
            ITEM_ApplyItemStats(pItem, pUnit, 0);
        }

        UI_SendMouseMove();
    }
    else if (nMode == 1)
    {
        D2UnitStrc* pBodyItem = INVENTORY_GetItemFromBodyLoc(hInventory, tItemSave.nBodyloc);
        GFX_RequeuePlayerMode(pUnit);
        if (!pBodyItem)
        {
            return NULL;
        }

        INVENTORY_UpdateWeaponGUIDOnRemoval(hInventory, pBodyItem);
        GFX_ClearGfxBytes(pUnit, pPacket->nComponent);
        INVENTORY_GetSecondWieldingWeapon(pUnit, hInventory, &pBodyItem, tItemSave.nBodyloc);

        D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(hInventory, pBodyItem);
        D2_ASSERT(pRemoved == pBodyItem, 0xC1E);

        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        }

        if (!ITEMS_CheckItemFlag(pRemoved, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pRemoved);
        }

        ITEMS_UpdateSets(pUnit, pRemoved, 1, 1);
        sub_0063BE30(hInventory, tItemSave.nBodyloc);
        GFX_RefreshUnitGfx(pUnit, 0);
        CUNIT_RemoveClientSideUnit(!pBodyItem ? -1 : pBodyItem->dwUnitId, !pBodyItem ? 6 : pBodyItem->dwUnitType);
        pBodyItem = NULL;

        if (pUnit == pPlayer)
        {
            INV_ResetHover();
            if (tItemSave.nBodyloc == 4)
            {
                gwRightHandWeaponClass = 0;
            }
            else if (tItemSave.nBodyloc == 5)
            {
                gwLeftHandWeaponClass = 0;
            }
        }

        pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
        ITEMS_SetBodyLocation(pItem, tItemSave.nBodyloc);

        int nPage = 3;
        if (tItemSave.nBodyloc == 0x0B || tItemSave.nBodyloc == 0x0C)
        {
            nPage = 4;
        }

        if (!INVENTORY_PlaceItemInSocket(hInventory, pItem, nPage))
        {
            return NULL;
        }

        if (!ITEM_PlaceBodyItem(hInventory, pItem, tItemSave.nBodyloc))
        {
            return NULL;
        }

        INVENTORY_UpdateWeaponGUIDOnInsert(hInventory, pItem);
        GFX_FillGfxEntries(pUnit, 0);

        const unsigned char nComponent = pPacket->nComponent;
        if (nComponent == 0 || nComponent == 1)
        {
            GFX_ClearGfxBytes(pUnit, nComponent);
        }

        GFX_RefreshUnitGfx(pUnit, 0);
        if (pUnit == pPlayer)
        {
            ITEM_StoreHandWeaponClass(pItem, tItemSave.nBodyloc);
            if (!sub_006287A0_TestFlags(tItemSave.dwFlags, 8))
            {
                INVENTORY_SetCursorItem(hInventory, NULL);
                CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(hInventory));
            }
        }

        ITEM_ApplyItemStats(pItem, pUnit, 0);
        ITEM_RefreshEquippedItems(pUnit);
        ITEM_RefreshEquippedItems(pUnit);
        UI_SendMouseMove();
    }
    else if (pUnit == pPlayer)
    {
        if (nMode == 2)
        {
            pItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
            if (pItem)
            {
                D2_ASSERT(INVENTORY_RemoveItemFromInventory(hInventory, pItem) == pItem, 0xC5E);
                D2COMMON_10267_Return(hInventory, CLIENTS_GetUnitX(pItem));
                VIEW_SetBeltSlotValue(CLIENTS_GetUnitX(pItem), 0);
                if (pUnit->dwUnitType == UNIT_PLAYER)
                {
                    INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
                }

                if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x96, ".\\UNIT\\Item.cpp"))
                {
                    STATLIST_ExpireUnitStatlist(pUnit, pItem);
                }

                CUNIT_RemoveClientSideUnit(pItem->dwUnitId, pItem->dwUnitType);
            }

            VIEW_ResetBeltHover();
            pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
            D2_ASSERT(tItemSave.bMode == 2, 0xC69);

            UNITS_SetXForStaticUnit(pItem, tItemSave.nX);
            UNITS_SetYForStaticUnit(pItem, tItemSave.nY);
            if (INVENTORY_PlaceItemInSocket(hInventory, pItem, 2))
            {
                if (!INVENTORY_PlaceItemInBeltSlot(hInventory, pItem, CLIENTS_GetUnitX(pItem)))
                {
                    sub_00477EE0();
                    WINMAIN_SetExitApplication(0);
                    GAME_SetCinematicExit(1);
                    GAME_RequestExit();
                }

                if (ITEMS_IsCharmUsable(pItem, pUnit))
                {
                    ITEM_ApplyItemStats(pItem, pUnit, 0);
                }

                VIEW_SetBeltSlotValue(CLIENTS_GetUnitX(pItem), 1);
                UI_SendMouseMove();
                if (sub_006287A0_TestFlags(tItemSave.dwFlags, 0x400))
                {
                    GFX_AddUnitOverlay(pItem, 0x46, 2, 0, 0, 0, 0, 0);
                }
            }
            else
            {
                D2_ASSERT(0, 0xC89);
            }
        }
        else if (nMode == 4)
        {
            VIEW_ResetBeltHover();
            D2UnitStrc* pOldItem = CUNIT_FindClientUnit(pPacket->nItemId, 4);
            if (pOldItem)
            {
                CUNIT_RemoveClientSideUnit(!pOldItem ? -1 : pOldItem->dwUnitId, !pOldItem ? 6 : pOldItem->dwUnitType);
            }

            pItem = ITEM_CreateOwnedItem(0, 0, 0, pPacket, &tItemSave);
            UNITS_SetXForStaticUnit(pItem, tItemSave.nX);
            UNITS_SetYForStaticUnit(pItem, tItemSave.nY);
            INVENTORY_SetCursorItem(hInventory, pItem);
            CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(hInventory));
            UI_SendMouseMove();
        }
    }

    if (pItem)
    {
        ITEM_ClearUninterruptableState(pItem);
    }

    return pItem;
}

// 0x004C51E0
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

// 0x004C52E0
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






// 0x004DF630
int __fastcall ITEM_QueryCacheAddress(D2AddressQueryStrc* pQuery)
{
    D2_ASSERT(*(int*)pQuery->nState == 2, 0x5D);

    D2AddressInfoStrc tInfo;
    int nParam = pQuery->nParam;
    int nResult = D2SOUNDSMP_ReadWaveHeader(pQuery->nSocket, &nParam, &tInfo);
    if (nResult && tInfo.nVersion == 0x10 && tInfo.nMagic == 0x5622)
    {
        pQuery->nResult = nResult;
        pQuery->nParamOut = nParam;
        pQuery->bFamilyMatch = tInfo.f_2 == 2;
        return 1;
    }

    pQuery->f_81 = 1;
    return 0;
}

#include "gen/data/Source/D2Client/UNIT/Item.inc"
