#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Primitives.h"
#include "D2DataTbls.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientMenus.h"
#include "D2UnitData.h"
#include "D2Txt.h"
#include "D2MonsterIds.h"
#include "D2MonModes.h"
#include "D2GameTypes.h"
#include "D2NpcIndex.h"

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
#include <D2UnitData.h>

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define CHECK(c,line) if(!(c)) { FOG_DisplayHalt(&empty,sub_00408090(),line); exit(-1); }

struct D2StaticPathStrc;

struct D2MonStatsTxt;

struct D2ClientItemSlotStrc;

struct D2MonsterDataStrc;

struct D2PacketRecord6Strc;

struct D2StringMapStrc;

struct D2ClientStringListStrc;

struct D2PartyRecordStrc;

struct D2ClientObjectStrc;

struct D2NpcQuestHandlerStrc;

struct D2NpcIndexStrc;

struct Unicode;

struct D2NpcMenuSlotStrc;

struct D2NpcMenuEntryStrc;

struct D2NpcPacketStrc;

struct D2ClientValueBlockStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2CoordStrc;

struct D2NpcEntryStrc;

class D2NpcTradeObjStrc;

union D2SeedStrc;

struct D2ClientItemSlotStrc
{
    unsigned short wId;
    char unk0x02[0x06];
    int nUnitId;
    char unk0x0C[0x04];
};

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

int __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

void __stdcall D2COMMON_10251_Return(D2InventoryStrc* pInventory); // 0x0063BD00

void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory); // 0x0063CB70

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2ClientItemSlotStrc gaNpcItemSlots[10]; // 0x007C0C85

#pragma pack(push, 1)

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
};

#pragma pack(pop)

struct D2StringMapStrc
{
    unsigned short f_0;
    unsigned short wValue;
    char unk0x04[0x4];
};

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

struct D2PartyRecordStrc
{
    unsigned char nFlag0;
    unsigned char nFlag1;
    char unk0x02[0x14];
};

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern int gnStringMapCount; // 0x00725C04

extern D2StringMapStrc gaStringMap[]; // 0x0072739C

extern int gnPartyCount_0072554C; // 0x0072554C

extern D2PartyRecordStrc gaNpcEntryFlags[]; // 0x00726861

extern unsigned char gbNpcEntriesProcessed; // 0x007C0C6A

extern void* gpRes_007C0D63; // 0x007C0D63

extern void* gpRes_007C0D67; // 0x007C0D67

extern void* gpRes_007C0D73; // 0x007C0D73

extern void* gpRes_007C0D7B; // 0x007C0D7B

extern D2ClientStringListStrc gtStringList; // 0x007C0D9A

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall CUNIT_ForEachObject(UNITFN pfnCallback); // 0x004649D0

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __cdecl INV_ResetHover(); // 0x00487990

void __cdecl INV_SetRequest(); // 0x00487B70

D2TextHeaderStrc* __cdecl DLIGHTMAP_GetTextHeader(); // 0x0049F900

int __fastcall MONSTER_GetOwnerGUID(D2UnitStrc* pUnit); // 0x004AE130

D2UnitStrc* __cdecl NPCMENU_GetInteractNpc(); // 0x004B1620

void __cdecl TEXT_InitNpcMenu(); // 0x004B23E0

void __cdecl NPCMENU_FreeNpcMenu(); // 0x004B24A0

void __cdecl NPCMENU_FinishTransaction(); // 0x004B2940

void __fastcall NPCMENU_CheckObjectFound(D2UnitStrc* pUnit); // 0x004B3360

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

struct D2ClientObjectStrc
{
    virtual void Destroy(int bFree) = 0;
};

extern D2ClientObjectStrc* gpObject_007C0D83; // 0x007C0D83

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490

extern D2NpcQuestHandlerStrc gaNpcHandlers[]; // 0x007253E0

extern D2NpcIndexStrc gaNpcIndex[]; // 0x00726C48

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

class D2NpcTradeObjStrc
{
public:
    virtual ~D2NpcTradeObjStrc();
    virtual void Draw(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05();
    virtual void Slot06(); virtual void Slot07(); virtual void Slot08(); virtual void Slot09(); virtual void Slot10();
    virtual int GetCount();
    virtual void sub_004BBFB0();
    virtual unsigned int GetAt(int nIndex);
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, long* pLeft, long* pTop, long* pRight, long* pBottom); // 0x00476070

void __fastcall VIEW_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0

void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

const Unicode* __fastcall TEXT_GetTextString(unsigned short nStringId); // 0x0049F910

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

// build: symbol ?DIALOG_CreateDialog@* 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0

void __fastcall ROSTER_SetCtrlState(void* pPanel, int nValue); // 0x004B8370

// build: symbol ?DIALOG_AddTextLine@* 0x004B85F0
void __fastcall DIALOG_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8); // 0x004B85F0

int __cdecl sub_004B1DC0(); // 0x004B1DC0

int __cdecl NPCMENU_CloseSubMenuToMain(); // 0x004B5810

int __cdecl sub_004B5850(); // 0x004B5850

extern D2ViewStrc* gpClientView; // 0x007A0640

int gnHireMercIndex; // 0x007C0C60

int gnHireMercNpcId; // 0x007C0C64

extern D2NpcMenuSlotStrc gaSlots_007C0C85[]; // 0x007C0C85

extern D2ClientDialogStrc* gpNpcWaitDialog; // 0x007C0D67

extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

D2UnitStrc* __stdcall sub_Z12_EmitNext(D2UnitStrc* pItem);

void __stdcall sub_Z12_EmitUseItem(D2UnitStrc* pItem);

#pragma pack(push, 1)

struct D2NpcMenuEntryStrc
{
    int nType;
    char unk0x04[2];
    short wStringId;
    short wSlot[3];
    char unk0x0E[4];
    int (__cdecl* pfnHandler)();
    int nSlot[3];
    char unk0x22[5];
};

struct D2NpcPacketStrc
{
    unsigned char nHeader;
    unsigned short wSubId;
};

#pragma pack(pop)

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

void __cdecl INV_SelectFirstButton(); // 0x00487CC0

int __cdecl NPCMENU_IdentifyItemsWait(); // 0x004B2020

extern D2NpcMenuEntryStrc gaNpcMenuEntries[]; // 0x00726C4C

extern int gnGlobal_007C0D39; // 0x007C0D39

extern short gwGlobal_007C0D3D; // 0x007C0D3D

unsigned char g007C0D89; // 0x007C0D89

int __cdecl NPCMENU_ResurrectMercWait(); // 0x004B1DD0

void __fastcall MSG_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

extern short gwGlobal_00726E01; // 0x00726E01

extern int gnGlobal_00726E0F; // 0x00726E0F

extern short gwGlobal_00726E4F; // 0x00726E4F

extern int gnGlobal_00726E5D; // 0x00726E5D

extern short gwGlobal_00726E9D; // 0x00726E9D

extern int gnGlobal_00726EAB; // 0x00726EAB

extern short gwGlobal_00726CCB; // 0x00726CCB

extern int gnGlobal_00726CDB; // 0x00726CDB

extern short gwGlobal_007272E1; // 0x007272E1

extern int gnGlobal_007272EF; // 0x007272EF

extern short gwGlobal_00727247; // 0x00727247

extern int gnGlobal_00727257; // 0x00727257

extern short gwGlobal_00727297; // 0x00727297

extern int gnGlobal_007272A9; // 0x007272A9

extern short gwGlobal_00726F87; // 0x00726F87

extern int gnGlobal_00726F95; // 0x00726F95

extern short gwGlobal_00726EC2; // 0x00726EC2

extern int (__cdecl* gpfnGlobal_00726ECE)(); // 0x00726ECE

extern short gwGlobal_00726EE9; // 0x00726EE9

extern int (__cdecl* gpfnGlobal_00726EF5)(); // 0x00726EF5

extern short gwGlobal_00726F10; // 0x00726F10

extern int (__cdecl* gpfnGlobal_00726F1C)(); // 0x00726F1C

extern short gwGlobal_00726F37; // 0x00726F37

extern int (__cdecl* gpfnGlobal_00726F43)(); // 0x00726F43

extern short gwGlobal_0072721C; // 0x0072721C

extern int (__cdecl* gpfnGlobal_00727228)(); // 0x00727228

#pragma pack(push, 1)

struct D2ClientValueBlockStrc
{
    char unk0x00[0x15];
    int anValues[20];
    D2ClientValueBlockStrc();
};

#pragma pack(pop)

void __cdecl TEXT_LoadPopupHireling(); // 0x004939B0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall NPCMENU_EndNpcInteraction(int nValue); // 0x004B3C20

void __cdecl NPCMENU_ShowTradeDialog(); // 0x004B2F50

extern "C" D2UnitStrc* __fastcall CUNIT_FindClientUnit(int nUnitId, int nUnitType); // 0x00463990

void __fastcall NPCMENU_RemoveInventoryClientUnits(D2UnitStrc* pUnit); // 0x004B3790

void __fastcall sub_004BA840(int nHandle);                                                                  // 0x004BA840

#include "gen/data/Source/D2Client/UI/npcmenu/gnHandlerCount.inc"

int gnNpcSoundActive; // 0x007C0DB4

int gnNpcSoundHandle; // 0x007C0DB8

char gbNpcMessageShown; // 0x007C0C69

void __cdecl NPCMENU_CloseNpc(); // 0x004B3DE0

void __cdecl NPCMENU_CloseNpcShop(); // 0x004B3ED0

void __cdecl NPCMENU_FreeDialogs(); // 0x004B2110

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

int __cdecl sub_004C0440_Thunk(); // 0x004C0440

void __cdecl INV_ResetNpcCursor(); // 0x0048A6A0

typedef int (__cdecl* Callback)();

void __cdecl INV_SetNpcStateMenuReturn(); // 0x00487D30

int __cdecl NPCMENU_NpcMenuReturn(); // 0x004B4CF0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __cdecl CURSOR_GetCursorItem(); // 0x004680A0

void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

extern const char empty; // 0x006CC837

extern int g007C0C6B; // 0x007C0C6B

extern int g007C0D31; // 0x007C0D31

extern int g007C0D3F; // 0x007C0D3F

extern int g007C0D5B; // 0x007C0D5B

extern void* g007C0D67; // 0x007C0D67

extern int g007C0D8E; // 0x007C0D8E

extern int g007C0D96; // 0x007C0D96

extern int g007C0DE1; // 0x007C0DE1

extern int g007C0DE5; // 0x007C0DE5

static int NPCMENU_FindNpcIndex(D2UnitStrc* pRecord); // 0x004B2E30

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" const char gszFormatD[]; // 0x006D57BC

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int bService, int* pCost, Unicode* pText, int nMaxLength); // 0x004B2AD0

int __cdecl NPCMENU_MenuBack(); // 0x004B2E70

int __cdecl NPCMENU_MenuClose(); // 0x004B2F00

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

// build: symbol ??__EgwszCost_007C0DF5@@YAXXZ 0x006CAD10
Unicode gwszCost_007C0DF5[40]; // 0x007C0DF5

typedef char sub_I16_AssertUnitSeed[(int)&((D2UnitStrc*)0)->pSeed == 0x20 ? 1 : -1];

typedef char sub_I16_AssertUnitInventory[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60

void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0

int __cdecl NPCMENU_NpcMenuCancelText(); // 0x004B4670

int __cdecl NPCMENU_NpcMenuCancelTextB(); // 0x004B46D0

int __cdecl NPCMENU_NpcMenuTalk(); // 0x004B4730

void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

unsigned short __fastcall NPCMENU_GetFreeStringId(unsigned short wStringId); // 0x004B1830

int __cdecl sub_004B5BC0_SelectNpcEntry(); // 0x004B5BC0

int __fastcall sub_004B8580(D2ClientDialogStrc* pDialog); // 0x004B8580

int __fastcall NPCMENU_NpcMessageCallback(void* pContext, int nArg, int nValue); // 0x004B18C0

void __fastcall sub_004B8370(void* pPanel, int nValue); // 0x004B8370

struct D2NpcMonListPacketStrc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned short nMonIds[12];
};

void __cdecl TEXT_ClearTextPanel();                                                                     // 0x004A1730

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg);                                         // 0x00480E70

int __cdecl NPCMENU_ShowMainMenu();                                                                         // 0x004B5C60

extern D2ClientDialogStrc* gpNpcSubMenuDialog;                                                               // 0x007C0D63

extern int (__cdecl* gpfnGlobal_00726E0B)();                                                                // 0x00726E0B

extern short gwGlobal_00726DFF;                                                                             // 0x00726DFF

typedef char check_size_npcindex[(sizeof(D2NpcIndexStrc) == 0x27) ? 1 : -1];

void __cdecl GAME_ResetMouseState();                                                                                // 0x0044DA40

int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490

void __fastcall CUNIT_TurnTowardPlayer(D2UnitStrc* pUnit);                                                 // 0x00464420

void __fastcall CUNIT_PlayerFaceUnit(D2UnitStrc* pUnit);                                             // 0x004644E0

void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback);                                                           // 0x00464990

void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0

void __cdecl NPCMENU_ResetHandlers();                                                                  // 0x004B2250

void __fastcall NPCMENU_ClearInteractOverlay(D2UnitStrc* pUnit);                                          // 0x004B2390

extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830

void __cdecl NPCMENU_OpenGreetingDialog();                                                             // 0x004B4DB0

int __cdecl sub_004B1D70_FindNpcEntry(); // 0x004B1D70

void __stdcall NPCMENU_OpenNpcWindow(D2UnitStrc* pUnit); // 0x004B4FD0

int __cdecl NPCMENU_InitHireHandler();                                                                     // 0x004B6410

void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc* pUnit);                                            // 0x004CB190

int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType);                                     // 0x004E0590

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath);                                             // 0x00648730

short __stdcall TEXT_GetStringIdOfMenuType1Node(D2TextHeaderStrc* pTextHeader, int nNodeId); // 0x00661440

extern char gabNpcMenuState[];                                                                            // 0x007C0C68

int gbGambleShop; // 0x007C0DB0

int gnNpcMenuValue;        // 0x007C0DD0

void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry);

D2UnitStrc* gpNpcPlayerUnit; // 0x007C0DD4

unsigned short gwGlobal_007C0DD8; // 0x007C0DD8

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860

void __cdecl GAME_RequestExit(); // 0x0044D520

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __cdecl INV_SendLeaveGame(); // 0x00477EE0

void __cdecl INV_EnterNpcMenuState(); // 0x0048A630

void __cdecl NPCMENU_CloseWaitDialog(); // 0x004B2900

void __fastcall sub_004B8100(void* pObj);

int gbWaitSoundPlayed; // 0x007C0DBC

int gbWaitSoundScheduled; // 0x007C0DC0

unsigned long gdwWaitSoundTick; // 0x007C0DC4

struct D2BitBufferStrc;

struct D2GameStrc;

struct D2StoredMsgPacketStrc;

struct D2StoredMsgStrc;

void __cdecl INV_ResetNpcButtonsFromPending(); // 0x00487C20

void __cdecl INV_AdvancePendingNpcState(); // 0x00487C60

int __cdecl VIEW_SetNpcMenuMode(); // 0x00487CA0

int __cdecl sub_00489870(); // 0x00489870

void __cdecl INV_EnterNpcMenuState(); // 0x0048A630

void __fastcall MSG_SendFourDwords(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700

int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

extern int gnGlobal_007C0D3F; // 0x007C0D3F

extern int gnGlobal_007C0D5B; // 0x007C0D5B

extern int gnGlobal_007C0DB0; // 0x007C0DB0

extern D2UnitStrc* gpPlayer_007C0DD4; // 0x007C0DD4

extern unsigned long gdwGlobal_007C0DE9; // 0x007C0DE9

extern unsigned long gdwGlobal_007C0DF1; // 0x007C0DF1

extern unsigned long gdwTradeThrottleTick; // 0x007C0E48

static int NPCMENU_GetNpcDialogPos(D2CoordStrc* pCoords); // 0x004B1C80

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __stdcall ITEMS_GetAllRepairCosts(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void (__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*)); // 0x0062FE60

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

#pragma pack(push, 1)

struct D2StoredMsgPacketStrc
{
    unsigned char nHeader;
    unsigned short wValue;
    unsigned int dwValue;
};

#pragma pack(pop)

struct D2StoredMsgStrc
{
    unsigned short wValue;
    unsigned short unk0x02;
    unsigned int dwValue;
    int bUsed;
    int unk0x0C;
};

extern D2StoredMsgStrc gaStoredMsgs_007C0C85[10]; // 0x007C0C85

unsigned char gbObjectFound; // 0x007C0DDA

void* gpBuySellCel; // 0x007C0DC8

void* gpGoldBtnCel; // 0x007C0DCC

int __fastcall NPCMENU_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

static int NPCMENU_ItemNeedsRepair(D2UnitStrc* pItem);

void __cdecl NPCMENU_HireMercWait();

void __stdcall NPCMENU_OpenNpcPanel(int nStringIndex, int nEntryIndex);

void __stdcall NPCMENU_OpenConfirmDialog(int nStringIndex);

unsigned char g007C0DE0; // 0x007C0DE0

void __cdecl NPCMENU_BuildNpcMenu(); // 0x004B4830

void __cdecl sub_004B5140(); // 0x004B5140

extern void (__cdecl* gpfnCallback_00726E59)(); // 0x00726E59

extern unsigned short gwGlobal_00726E4D; // 0x00726E4D

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0

int __cdecl NPCMENU_TravelToKurastDocks();                                                                                 // 0x004B51A0

int __cdecl NPCMENU_TravelToHarrogath();                                                                                 // 0x004B5200

extern short gwGlobal_00726E9B;                                                                             // 0x00726E9B

extern int (__cdecl* gpfnGlobal_00726EA7)();                                                                // 0x00726EA7

static void NPCMENU_SetNpcInteract(D2UnitStrc* pRecord);

void __fastcall NPCMENU_AddUsedString(unsigned short wStringId);

static int __stdcall NPCMENU_RunNpcQuestHandlers(int nNpcId, D2BitBufferStrc* pQuestFlags, D2NpcQuestHandlerStrc* pTable, int nCount);

static bool NPCMENU_IsSpecialNpc(int nClassId);

#define UNIT_MONSTER 1

#define FIELD_OFFSET(T,F) ((unsigned long)&(((T*)0)->F))

struct D2MissileStrc;

struct D2MissilesTxt;

struct RecordView;

struct PayloadView;

struct UnitView;

struct TablesView;

void __fastcall GFX_RemoveOverlays(D2UnitStrc* pUnit); // 0x0046F170

void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount); // 0x0046C320

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

extern "C" int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wMask); // 0x004AC7E0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath); // 0x00648A10

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210

extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

struct RecordView
{
    char opaque[0x1a8];
};

struct PayloadView
{
    RecordView* record;
    char unused4[0x24];
    unsigned short flags28;
    char unusedAfterFlags[0x12];
    int value3c;
};

struct UnitView
{
    int type;
    int classId;
    char unusedAfterClass[0x0c];
    PayloadView* payload;
};

struct TablesView
{
    char unused0[0xa78];
    RecordView* records;
    int unusedAfterRecords;
    int count;
};

extern "C" TablesView* gTables_00744304;

typedef char RecordView_size[(sizeof(RecordView)==0x1a8)?1:-1];

typedef char PayloadView_size[(sizeof(PayloadView)==0x40)?1:-1];

typedef char PayloadView_record_offset[(FIELD_OFFSET(PayloadView,record)==0)?1:-1];

typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags28)==0x28)?1:-1];

typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value3c)==0x3c)?1:-1];

typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];

typedef char UnitView_class_offset[(FIELD_OFFSET(UnitView,classId)==0x4)?1:-1];

typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];

typedef char TablesView_size[(sizeof(TablesView)==0xa84)?1:-1];

typedef char TablesView_records_offset[(FIELD_OFFSET(TablesView,records)==0xa78)?1:-1];

typedef char TablesView_count_offset[(FIELD_OFFSET(TablesView,count)==0xa80)?1:-1];

void __cdecl INV_ResetNpcButtonsFromPending(); // 0x00487C20

void __cdecl UI_StartUIVarDelay(); // 0x00453AE0

void __fastcall USEITEM_OpenNpcItemPanel(int nArg); // 0x004C0620

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20

int __fastcall ROSTERPETS_CountPets(D2UnitStrc* pOwner, int nPetType); // 0x00478EE0

void __cdecl NPCMENU_CloseTradeDialog(); // 0x004B3610

extern int (__cdecl* gpfnGlobal_00726CD7)(); // 0x00726CD7

extern short gwGlobal_00726CC9; // 0x00726CC9

extern int (__cdecl* gpfnGlobal_00727253)(); // 0x00727253

extern short gwGlobal_00727245; // 0x00727245

extern int (__cdecl* gpfnGlobal_007272A5)(); // 0x007272A5

extern short gwGlobal_00727295; // 0x00727295

extern unsigned char gnPendingNpcActionType; // 0x007C0D89

int __fastcall NPCMENU_NpcTextCallback(void* pContext, int nArg, int nValue); // 0x004B6A30

void __cdecl INV_ResetButtonsFromMenuReturn(); // 0x00487D40

void __cdecl sub_004B17A0();

struct D2ClientDialogStrc;

typedef int (__cdecl* D2MenuHandler)();

typedef char CheckNpcIndexSize[sizeof(D2NpcIndexStrc)==39?1:-1];

extern int gnGlobal_007C0D2D; // 0x007C0D2D

extern unsigned int gnHirelingName_00725494; // 0x00725494

int __cdecl NPCMENU_NpcMenuCancel(); // 0x004B45D0

int __cdecl NPCMENU_NpcMenuCancelB(); // 0x004B4620

void __cdecl sub_005269D0(int,Unicode*,const Unicode*,...); // 0x005269D0

unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit); // 0x00622DE0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10

int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc*); // 0x0062A530

extern D2NpcChoiceStrc gaNpcChoices[];                                                             // 0x00725CB0

extern "C" const char gszNpcMenuFile[];                                                            // 0x006DA630

struct D2InventoryStrc;
struct D2DynamicPathStrc;

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

int __cdecl FOG_IsExpansion();                                                                 // 0x00408F20
void __fastcall TEXT_ShowNpcMessage(D2UnitStrc* pUnit, unsigned short nMessage, int nArg);                         // 0x004A10E0
void __stdcall QUESTRECORD_CopyBufferToRecord(D2BitBufferStrc* pQuestRecord, unsigned char* pBuffer, unsigned short nBufferSize, int bResetStates); // 0x0065C4D0

static inline int NPC_GetUnitClassId(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwClassId : -1;
}

static int GetUnitPathX(D2UnitStrc* pUnit)
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

static int GetUnitPathY(D2UnitStrc* pUnit)
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

static D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530

extern int gnGlobal_00726C4C;                                                                               // 0x00726C4C

extern int (__cdecl* gpfnGlobal_00726C62)();                                                                // 0x00726C62

extern short gwGlobal_00726C54;                                                                             // 0x00726C54

D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool); // 0x0065C430

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern void* gpGlobal_007C0D43; // 0x007C0D43

void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit);                                             // 0x0046B3C0

void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit);                                       // 0x0046B530

void __fastcall VIEW_SpawnBrDeathControl(D2UnitStrc* pUnit);                                           // 0x0046B680

void __fastcall sub_0046B710_SpawnMissileAtObject173(D2UnitStrc* pUnit);                                                            // 0x0046B710

void __fastcall VIEW_SpawnMissileNearObject(D2UnitStrc* pUnit);                                                            // 0x0046B850

void __fastcall VIEW_SpawnMephistoDeath(D2UnitStrc* pUnit);                                          // 0x0046B9A0

void __fastcall VIEW_SpawnAndarielDeath(D2UnitStrc* pUnit);                                               // 0x0046BA50

void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit);                                     // 0x0046BA90

void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit);                                     // 0x0046BB10

void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit);                                     // 0x0046BB90

void __fastcall VIEW_SpawnIzualDeath(D2UnitStrc* pUnit);                                             // 0x0046BC10

int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit);                                              // 0x0046BC70

void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit);                                        // 0x0046BC90

static inline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static void __stdcall NPCMENU_StateMissileBurst(int nSkillLevel, D2UnitStrc* pUnit, int nMissile); // 0x004AD6E0

__forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

void __fastcall NPCMENU_StateRequests(D2UnitStrc* pUnit); // 0x004ADCE0

// 0x004B1620
D2UnitStrc* __cdecl NPCMENU_GetInteractNpc()
{
// build: symbol ?gbNpcInteracting@* 0x007C0D29
    if (gbNpcInteracting)
    {
// build: symbol ?gnInteractNpcId@* 0x007C0D25
        return CUNIT_FindClientUnit(gnInteractNpcId, 1);
    }
    return 0;
}

// 0x004B1640
static void NPCMENU_SetNpcInteract(D2UnitStrc* pRecord)
{
    if (pRecord)
    {
        gbNpcInteracting = 1;
        gnInteractNpcId = pRecord->dwUnitId;
// build: symbol ?gnInteractNpcClassId@* 0x007C0D2D
        gnInteractNpcClassId = pRecord->dwClassId;
    }
    else
    {
        gbNpcInteracting = 0;
    }
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

// 0x004B1670
int __cdecl NPCMENU_GetUseItemMode()
{
// build: symbol ?gnInteractNpcClassId@* 0x007C0D2D
    return gnInteractNpcClassId;
}

// 0x004B1680
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry)
{
    int* const pnSelected = &pEntry->nSelected;
    int nTries = 10;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;

    do
    {
        --nTries;
        *pnSelected = SEED_RollLimitedRandomNumber(&pPlayer->pSeed, pEntry->nChoices);
        if (*pnSelected >= 2)
        {
            if (pEntry->pChoices[*pnSelected].nClass == nClass || pEntry->pChoices[*pnSelected].nClass == 7)
            {
                if (!pEntry->pChoices[*pnSelected].bQuest)
                {
                    return;
                }

// build: symbol ?gpPlayerQuestFlags@* 0x007C0D43
                if (QUESTRECORD_GetQuestState(gpPlayerQuestFlags, pEntry->pChoices[*pnSelected].nQuestId, 0) == pEntry->pChoices[*pnSelected].nQuestState)
                {
                    if (pEntry->pChoices == gaNpcChoices && pEntry->pChoices[*pnSelected].wId == 0xFF
// build: symbol ?gpGameQuestFlags@* 0x007C0D47
                        && QUESTRECORD_GetQuestState(gpGameQuestFlags, 12, 13) == 1)
                    {
                        *pnSelected = 2;
                    }
                    return;
                }
            }
        }
    }
    while (nTries);

    *pnSelected = 2;
}

static int CLIENT_IsStringUsed(unsigned short wString)
{
    for (int i = 0; i < gtStringList.wCount; ++i)
    {
        if (gtStringList.awStrings[i] == wString)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B1830
unsigned short __fastcall NPCMENU_GetFreeStringId(unsigned short wStringId)
{
    for (int i = 0; i < gnStringMapCount; ++i)
    {
        if (gaStringMap[i].f_0 == wStringId)
        {
            return gaStringMap[i].wValue;
        }
    }

    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    int nNode = 0;
    unsigned short wNode = TEXT_GetStringIdOfMenuType0Node(pTextHeader, nNode);
    while (wNode != 0xFFFF)
    {
        if (wNode != wStringId && !CLIENT_IsStringUsed(wNode))
        {
            return wNode;
        }
        ++nNode;
        wNode = TEXT_GetStringIdOfMenuType0Node(pTextHeader, nNode);
    }
    return 0xFFFF;
}

// 0x004B18C0
int __fastcall NPCMENU_NpcMessageCallback(void* pContext, int nArg, int nValue)
{
    if (gbNpcMessageShown == 1)
    {
// build: symbol ?gwNpcLastString@* 0x007C0C7B
        const unsigned short wStringId = NPCMENU_GetFreeStringId(gwNpcLastString);
// build: symbol ?gnInteractNpcId@* 0x007C0D25
// build: symbol ?gbNpcInteracting@* 0x007C0D29
        if (wStringId != 0xFFFF && gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1))
        {
            gwNpcLastString = wStringId;
            D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
// build: symbol ?TEXT_ShowNpcMessage@* 0x004A10E0
            TEXT_ShowNpcMessage(pNpc, wStringId, 0);
            TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
            return 1;
        }
    }

    gbNpcMessageShown = 0;
    TEXT_SetTextCallback(0, pContext);
    sub_004B5BC0_SelectNpcEntry();
    return 1;
}

// 0x004B1970
void __cdecl NPCMENU_ResetUsedStrings()
{
    gtStringList.wCount = 0;
}

// 0x004B1980
void __fastcall NPCMENU_AddUsedString(unsigned short wStringId)
{
    if (gtStringList.wCount < 9)
    {
        gtStringList.awStrings[gtStringList.wCount] = wStringId;
        gtStringList.wCount++;
    }
}

// 0x004B19A0
static int __stdcall NPCMENU_RunNpcQuestHandlers(int nNpcId, D2BitBufferStrc* pQuestFlags, D2NpcQuestHandlerStrc* pTable, int nCount)
{
    int nResult = 1;
    for (int i = 0; i < nCount; ++i)
    {
        if (pTable[i].nNpcId == nNpcId)
        {
            if (pTable[i].bSet)
            {
                if (QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
            else
            {
                if (!QUESTRECORD_GetQuestState(pQuestFlags, pTable[i].nQuestId, pTable[i].nState))
                    nResult = pTable[i].pfHandler();
            }
        }
    }
    return nResult;
}

// 0x004B1A10
static bool NPCMENU_IsSpecialNpc(int nClassId)
{
    if (nClassId == 0x92 || nClassId == 0x20F || nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B
        || nClassId == 0x209 || nClassId == 0x10A || nClassId == 0x17A || nClassId == 0xFB || nClassId == 0x179
        || nClassId == 0x14B || nClassId == 0x196 || nClassId == 0x198)
        return true;
    return false;
}

// 0x004B1A80
int __cdecl NPCMENU_OnSelectMessage()
{
// build: symbol ?gpNpcMessageDialog@* 0x007C0D6F
    const int nSelected = sub_004B8580(gpNpcMessageDialog);
// build: symbol ?gnNpcEntryIndex@* 0x007C0C81
    const int nFirstLine = gaNpcEntries[gnNpcEntryIndex].bFlag14 ? 2 : 3;
    if (nSelected < nFirstLine)
    {
        return 0;
    }

    if (!gbNpcInteracting || !CUNIT_FindClientUnit(gnInteractNpcId, 1))
    {
        return 0;
    }

    const int nNodeId = sub_004B8580(gpNpcMessageDialog) - nFirstLine;
    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    D2_ASSERT(pTextHeader, 0x710);
    const unsigned short wStringId = TEXT_GetStringIdOfMenuType2Node(pTextHeader, nNodeId);
    gwNpcLastString = wStringId;
    D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    TEXT_ShowNpcMessage(pNpc, wStringId, 0);
    gbNpcMessageShown = 1;
    TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
    DIALOG_DestroyDialog(gpNpcMessageDialog);
    gpNpcMessageDialog = 0;
    return 1;
}

// 0x004B1B80
int __cdecl NPCMENU_PlayIntroMessage()
{
    if (gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1))
    {
        D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
        TEXT_ShowNpcMessage(pNpc, 0xFE, 0);
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
        DIALOG_DestroyDialog(gpNpcMessageDialog);
        gpNpcMessageDialog = 0;
    }
    return 1;
}

// 0x004B1C00
int __cdecl NPCMENU_PlayGossipMessage()
{
    if (gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1))
    {
        D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
        TEXT_ShowNpcMessage(pNpc, 0x152, 0);
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
        DIALOG_DestroyDialog(gpNpcMessageDialog);
        gpNpcMessageDialog = 0;
    }
    return 1;
}

static inline int UNITS_GetClassIdInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

static inline D2UnitStrc* NPC_GetInteractUnit_Inline()
{
    return gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
}

// 0x004B1C80
static int NPCMENU_GetNpcDialogPos(D2CoordStrc* pCoords)
{
    if (NPC_GetInteractUnit_Inline())
    {
        UNITS_GetClientCoords(NPC_GetInteractUnit_Inline(), pCoords);

        tagRECT tView;
        sub_00476070_GetViewRect(gpClientView, &tView.left, &tView.top, &tView.right, &tView.bottom);

        D2CoordStrc tOffset;
        VIEW_GetViewOffset(gpClientView, &tOffset.nX, &tOffset.nY);

        tagRECT tRect;
        SetRect(&tRect, tOffset.nX, tOffset.nY, tOffset.nX + (tView.right - tView.left), tOffset.nY + (tView.bottom - tView.top));
        pCoords->nY += -150 - tRect.top;
        pCoords->nX -= tRect.left;
        if (pCoords->nY < 20)
        {
            pCoords->nY = 20;
        }

        return 1;
    }

    return 0;
}

void __cdecl sub_F03_Emit_004B1640(D2UnitStrc* pRecord)
{
    NPCMENU_SetNpcInteract(pRecord);
}

int __cdecl sub_F03_Emit_004B19A0(int nNpcId)
{
// build: symbol ?gnHandlerCount@* 0x007253DC
// build: symbol ?gpPlayerQuestFlags@* 0x007C0D43
    return NPCMENU_RunNpcQuestHandlers(nNpcId, gpPlayerQuestFlags, gaNpcHandlers, gnHandlerCount);
}

void __cdecl sub_F03_Emit_004B1A10(int nClassId)
{
    if (NPCMENU_IsSpecialNpc(nClassId))
        gbNpcInteracting = 1;
}

int __cdecl sub_F03_Emit_004B2E30(D2UnitStrc* pRecord)
{
    return NPCMENU_FindNpcIndex(pRecord);
}

// 0x004B1DD0
int __cdecl NPCMENU_ResurrectMercWait()
{
// build: symbol ?gpNpcMainMenuDialog@* 0x007C0D6B
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    MSG_SendDword(0x62, gnInteractNpcId);
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    gnNpcMenuState = 10;

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
// build: symbol ?gdwNpcRequestTimeout@* 0x007C0D53
    gdwNpcRequestTimeout = GetTickCount() + 60000;
// build: symbol ?gdwNpcTransactionTick@* 0x007C0D57
    gdwNpcTransactionTick = 0;
    ROSTER_SetCtrlState(gpNpcWaitDialog, 0);
    DIALOG_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    return 1;
}

// 0x004B1E80
void __cdecl NPCMENU_HireMercWait()
{
    MSG_SendTwoDwords(0x36, gnHireMercNpcId, gaSlots_007C0C85[gnHireMercIndex].wId);

// build: symbol ?gpNpcHireDialog@* 0x007C0D77
    if (gpNpcHireDialog)
    {
        DIALOG_DestroyDialog(gpNpcHireDialog);
// build: symbol ?gpNpcTradeObj@* 0x007C0D83
        delete gpNpcTradeObj;
        gpNpcTradeObj = 0;
        gpNpcHireDialog = 0;
    }

    gnNpcMenuState = 10;

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwNpcRequestTimeout = GetTickCount() + 60000;
    gdwNpcTransactionTick = 0;
    ROSTER_SetCtrlState(gpNpcWaitDialog, 0);
    DIALOG_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
}

// 0x004B1F60
static inline int NPCMENU_IsItemIdentified(D2UnitStrc* pItem)
{
    return ITEMS_CheckItemFlag(pItem, 0x10, 0x999, ".\\UI\\npcmenu.cpp");
}

// 0x004B1F80
static int NPCMENU_ItemNeedsRepair(D2UnitStrc* pItem)
{
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        return 0;
    if (!sub_0062E660(pItem))
        return 0;
    if (ITEMS_HasDurability(pItem))
    {
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability && STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) < nMaxDurability)
            return 1;
    }
    if (ITEMS_CheckIfStackable(pItem) && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < ITEMS_GetTotalMaxStack(pItem))
        return 1;
    int bHasChargedSkills;
    if (ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) && !bHasChargedSkills)
        return 1;
    return 0;
}

// 0x004B2010
int __cdecl sub_004B2010()
{
    return 0;
}

// 0x004B2020
int __cdecl NPCMENU_IdentifyItemsWait()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    D2_ASSERT(!gpNpcWaitDialog, 0xA2D);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
    gdwNpcRequestTimeout = GetTickCount() + 60000;
    gdwNpcTransactionTick = 0;
    ROSTER_SetCtrlState(gpNpcWaitDialog, 0);
    DIALOG_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0xF, 0, 0, 1, 0, 0);
    gnNpcMenuState = 10;
// build: symbol ?gnNpcTradeMode@* 0x007C0D31
    gnNpcTradeMode = 4;
// build: symbol ?gbNpcActionPending@* 0x007C0D96
    gbNpcActionPending = 0;
    MSG_SendDword(0x34, gnInteractNpcId);
    return 1;
}

// 0x004B2110
void __cdecl NPCMENU_FreeDialogs()
{
    if (gpRes_007C0D6F) { DIALOG_DestroyDialog(gpRes_007C0D6F); gpRes_007C0D6F = 0; }
    if (gpRes_007C0D73) { DIALOG_DestroyDialog(gpRes_007C0D73); gpRes_007C0D73 = 0; }
    if (gpRes_007C0D6B) { DIALOG_DestroyDialog(gpRes_007C0D6B); gpRes_007C0D6B = 0; }
    if (gpRes_007C0D7B) { DIALOG_DestroyDialog(gpRes_007C0D7B); gpRes_007C0D7B = 0; }
    if (gpRes_007C0D5F) { DIALOG_DestroyDialog(gpRes_007C0D5F); gpRes_007C0D5F = 0; }
    if (gpRes_007C0D63) { DIALOG_DestroyDialog(gpRes_007C0D63); gpRes_007C0D63 = 0; }
    if (gpRes_007C0D67) { DIALOG_DestroyDialog(gpRes_007C0D67); gpRes_007C0D67 = 0; }
    if (gpRes_007C0D77) { DIALOG_DestroyDialog(gpRes_007C0D77); gpRes_007C0D77 = 0; }
}

void __fastcall sub_Z12_EmitItemNeedsRepair(D2UnitStrc* pItem)
{
    for (; pItem; pItem = sub_Z12_EmitNext(pItem))
        if (NPCMENU_ItemNeedsRepair(pItem))
            sub_Z12_EmitUseItem(pItem);
}

// 0x004B21C0
static inline void NPCMENU_SetEntryType2(int nIndex)
{
    gaNpcMenuEntries[nIndex].nType = 2;
    gaNpcMenuEntries[nIndex].wSlot[0] = 0;
    gaNpcMenuEntries[nIndex].nSlot[0] = 0;
}

// 0x004B21E0
static inline void NPCMENU_SetEntryType3(int nIndex)
{
    gaNpcMenuEntries[nIndex].nType = 3;
    gaNpcMenuEntries[nIndex].wSlot[1] = 0;
    gaNpcMenuEntries[nIndex].nSlot[1] = 0;
}

// 0x004B2200
static inline void NPCMENU_SetEntryType4(int nIndex)
{
    gaNpcMenuEntries[nIndex].nType = 4;
    gaNpcMenuEntries[nIndex].wSlot[2] = 0;
    gaNpcMenuEntries[nIndex].nSlot[2] = 0;
}

// 0x004B2220
static inline void NPCMENU_SetIdentifyEntry(int nIndex)
{
    gaNpcMenuEntries[nIndex].wStringId = 0xFB4;
    gaNpcMenuEntries[nIndex].pfnHandler = NPCMENU_IdentifyItemsWait;
    gaNpcMenuEntries[nIndex].nType = 3;
}

// 0x004B2250
void __cdecl NPCMENU_ResetHandlers()
{
    gnGlobal_00726DF9 = 2; gwGlobal_00726E01 = 0; gnGlobal_00726E0F = 0;
    gnGlobal_00726E47 = 2; gwGlobal_00726E4F = 0; gnGlobal_00726E5D = 0;
    gnGlobal_00726E95 = 2; gwGlobal_00726E9D = 0; gnGlobal_00726EAB = 0;
    gnGlobal_00726CC1 = 3; gwGlobal_00726CCB = 0; gnGlobal_00726CDB = 0;
    gnGlobal_007272D9 = 2; gwGlobal_007272E1 = 0; gnGlobal_007272EF = 0;
    if (gpfnGlobal_007272EB == NPCMENU_ResurrectMercWait)
    {
        gnGlobal_007272D9 = 3;
    }
    gwGlobal_00727247 = 0; gnGlobal_00727257 = 0;
    gwGlobal_00727297 = 0; gnGlobal_007272A9 = 0;
    gnGlobal_00726F7F = 2; gwGlobal_00726F87 = 0; gnGlobal_00726F95 = 0;
    gwGlobal_00726F85 = 0; gpfnGlobal_00726F91 = 0;
    gnGlobal_0072723D = 3;
    gnGlobal_0072728B = 4;
    gwGlobal_00726EC2 = 0xFB4; gpfnGlobal_00726ECE = NPCMENU_IdentifyItemsWait; gnGlobal_00726EBC = 3;
    gwGlobal_00726EE9 = 0xFB4; gpfnGlobal_00726EF5 = NPCMENU_IdentifyItemsWait; gnGlobal_00726EE3 = 3;
    gwGlobal_00726F10 = 0xFB4; gpfnGlobal_00726F1C = NPCMENU_IdentifyItemsWait; gnGlobal_00726F0A = 3;
    gwGlobal_00726F37 = 0xFB4; gpfnGlobal_00726F43 = NPCMENU_IdentifyItemsWait; gnGlobal_00726F31 = 3;
    gwGlobal_0072721C = 0xFB4; gpfnGlobal_00727228 = NPCMENU_IdentifyItemsWait; gnGlobal_00727216 = 3;
}

// 0x004B2370
void __fastcall NPCMENU_SendNpcAction(int nArg)
{
    gbNpcActionPending = 0;
    MSG_SendDwords3(0x38, 0, gnInteractNpcId, nArg);
}

// 0x004B2390
void __fastcall NPCMENU_ClearInteractOverlay(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit->dwClassId);
    int bFlag = 0;
    if (pMonStatsTxtRecord)
    {
        bFlag = pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0];
    }
    if (bFlag)
    {
        AUTOMAP_RemoveUnitOverlay(pUnit, 0, 0x48);
    }
}

// 0x004B23E0
void __cdecl TEXT_InitNpcMenu()
{
    char szPath[0x104];
    gbWaitSoundScheduled = 0;
    gbWaitSoundPlayed = 0;
    GetTickCount();
    memset(gabNpcMenuState, 0, 0x160);
    gpGlobal_007C0D43 = QUESTRECORD_AllocRecord(0);
    gpGlobal_007C0D47 = QUESTRECORD_AllocRecord(0);
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    gnNpcMenuState = 0;
    sprintf(szPath, "%s\\ui\\panel\\buysell", gszDataGlobal);
    gpBuySellCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    sprintf(szPath, "%s\\ui\\menu\\goldbtn", gszDataGlobal);
    gpGoldBtnCel = ARCHIVE_LoadClientCellFile(szPath, 0);
// build: symbol ?gnTradeRequestFailCount@* 0x007C0DED
    gnTradeRequestFailCount = 0;
// build: symbol ?gbTradeClickPending@* 0x007C0DE0
    gbTradeClickPending = 0;
// build: symbol ?gdwLastTradeSendTick@* 0x007C0DF1
    gdwLastTradeSendTick = 0;
// build: symbol ?gdwTradeRequestTick@* 0x007C0DE9
    gdwTradeRequestTick = 0;
}

// 0x004B24A0
void __cdecl NPCMENU_FreeNpcMenu()
{
    QUESTRECORD_FreeRecord(0, gpPlayerQuestFlags);
// build: symbol ?gpGameQuestFlags@* 0x007C0D47
    QUESTRECORD_FreeRecord(0, gpGameQuestFlags);
    gpPlayerQuestFlags = 0;
    gpGameQuestFlags = 0;

    if (gpBuySellCel)
    {
        ARCHIVE_FreeClientCellFile(gpBuySellCel);
        gpBuySellCel = 0;
    }
    if (gpGoldBtnCel)
    {
        ARCHIVE_FreeClientCellFile(gpGoldBtnCel);
        gpGoldBtnCel = 0;
    }
    if (gpObject_007C0D83)
    {
        gpObject_007C0D83->Destroy(1);
        gpObject_007C0D83 = 0;
    }
    if (gpRes_007C0D5F) { DIALOG_DestroyDialog(gpRes_007C0D5F); gpRes_007C0D5F = 0; }
    if (gpRes_007C0D63) { DIALOG_DestroyDialog(gpRes_007C0D63); gpRes_007C0D63 = 0; }
    if (gpRes_007C0D67) { DIALOG_DestroyDialog(gpRes_007C0D67); gpRes_007C0D67 = 0; }
    if (gpRes_007C0D6B) { DIALOG_DestroyDialog(gpRes_007C0D6B); gpRes_007C0D6B = 0; }
    if (gpRes_007C0D77) { DIALOG_DestroyDialog(gpRes_007C0D77); gpRes_007C0D77 = 0; }
    if (gpRes_007C0D7B) { DIALOG_DestroyDialog(gpRes_007C0D7B); gpRes_007C0D7B = 0; }
    if (gpRes_007C0D6F) { DIALOG_DestroyDialog(gpRes_007C0D6F); gpRes_007C0D6F = 0; }
    if (gpRes_007C0D73) { DIALOG_DestroyDialog(gpRes_007C0D73); gpRes_007C0D73 = 0; }
}

void __stdcall sub_M129_Emit_004B21C0(int a, int b, int c, int d)
{
    NPCMENU_SetEntryType2(a);
    NPCMENU_SetEntryType3(b);
    NPCMENU_SetEntryType4(c);
    NPCMENU_SetIdentifyEntry(d);
}

// 0x004B25C0
void __fastcall NPCMENU_OnNpcPacketStoreSubId(D2NpcPacketStrc* pPacket)
{
    D2_ASSERT(pPacket, 0xFC6);
    if (pPacket->wSubId == 3 && gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1))
    {
        gnGlobal_007C0D39 = 1;
        gwGlobal_007C0D3D = pPacket->wSubId;
    }
}

// 0x004B2620
void __fastcall NPCMENU_CopyQuestBuffer(unsigned char* pBuffer)
{
    QUESTRECORD_CopyBufferToRecord((D2BitBufferStrc*)gpGlobal_007C0D47, pBuffer, 0x60, 0);
}

// 0x004B2640
void __fastcall sub_004B2640(int nUnused)
{
    INV_SetRequest();
}

static inline D2UnitStrc* GetInteractNpc_Inline()
{
    if (!gbNpcInteracting)
        return 0;
    return CUNIT_FindClientUnit(gnInteractNpcId, 1);
}

static int GetUnitIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

static int GetClassIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004B2650
void __stdcall NPCMENU_SendTradeRequest(int bAlternate, int nFlags)
{
// build: symbol ?gbTradeClickPending@* 0x007C0DE0
    if (!gbTradeClickPending)
    {
        INV_ResetNpcButtonsFromPending();
        return;
    }

    char nCommand;
// build: symbol ?gnNpcTradeMode@* 0x007C0D31
    switch (gnNpcTradeMode)
    {
    case 1:
        nCommand = 0x32;
        break;
    case 2:
        nCommand = 0x33;
        break;
    case 3:
        nCommand = 0x35;
        sub_004B9A00(0x0F, 0, 0, 0, 0);
        break;
    default:
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
        gnNpcMenuState = 3;
        INV_ResetNpcButtonsFromPending();
        return;
    }

    unsigned int nMode = 0;
// build: symbol ?gbNpcActionPending@* 0x007C0D96
    gbNpcActionPending = 0;
    D2UnitStrc* pUnit = 0;
    if (sub_00489870())
    {
        if (GetTickCount() - gdwTradeThrottleTick < 2000)
        {
            INV_ResetNpcButtonsFromPending();
            return;
        }
        gdwTradeThrottleTick = GetTickCount();
    }
    else
    {
// build: symbol ?gnTradeItemUnitId@* 0x007C0DE5
        pUnit = CUNIT_FindClientUnit(gnTradeItemUnitId, 4);
        if (pUnit)
        {
            nMode = (unsigned short)pUnit->dwAnimMode;
            if (gnNpcTradeMode == 2)
            {
                D2InventoryStrc* const pInventory = gpPlayer_007C0DD4->pInventory;
                gnGlobal_007C0D3F = INVENTORY_GetCursorItem(pInventory) == pUnit;
            }
        }
        else
        {
            gnNpcMenuState = 3;
            INV_EnterNpcMenuState();
            gdwGlobal_007C0DE9 = GetTickCount();
// build: symbol ?gnTradeRequestFailCount@* 0x007C0DED
            ++gnTradeRequestFailCount;
            gbTradeClickPending = 0;
            return;
        }
    }

    if (bAlternate)
    {
        VIEW_SetNpcMenuMode();
    }
    else
    {
        INV_AdvancePendingNpcState();
    }

    gnNpcMenuState = 5;
    gdwGlobal_007C0DF1 = GetTickCount();
    if (nCommand == 0x32)
    {
        if (gnGlobal_007C0DB0)
            nMode = ((unsigned int)(unsigned short)nMode << 16) | 2;
        else
            nMode = (unsigned int)(unsigned short)nMode << 16;
        if (nFlags & 4)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInl(pUnit));
            if (pItemsTxtRecord && pItemsTxtRecord->nField1A5)
            {
                nMode |= 0x80000000;
            }
        }
// build: symbol ?gnNpcTransactionCost@* 0x007C0D7F
        MSG_SendFourDwords(0x32, gnInteractNpcId, gnTradeItemUnitId, nMode, gnNpcTransactionCost);
        gnGlobal_007C0D5B = ITEM_GetDropSound(pUnit);
    }
    else if (nCommand == 0x35)
    {
        if (sub_00489870()) { MSG_SendFourDwords(nCommand, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, 0x80000000); }
        else if (pUnit) { MSG_SendFourDwords(0x35, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, STATLIST_UnitGetStatValue(pUnit, STAT_DURABILITY, 0)); }
        else { MSG_SendFourDwords(0x35, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, 0); }
    }
    else { MSG_SendFourDwords(nCommand, gnInteractNpcId, gnTradeItemUnitId, (unsigned short)nMode, gnNpcTransactionCost); }

    D2_ASSERT(!gpNpcWaitDialog, 0x11B6);
    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);
    gpNpcWaitDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B1DC0, 0, 0, 0, 1, 0, 0, 0, 1);
// build: symbol ?gdwNpcRequestTimeout@* 0x007C0D53
    gdwNpcRequestTimeout = GetTickCount() + 60000;
// build: symbol ?gdwNpcTransactionTick@* 0x007C0D57
    gdwNpcTransactionTick = 0;
    sub_004B8370(gpNpcWaitDialog, 0);
    DIALOG_AddTextLine(gpNpcWaitDialog, D2LANG_GetStringFromTblIndex(0xD19), 0x0F, 0, 0, 1, 0, 0);
}

// 0x004B2900
void __cdecl NPCMENU_CloseWaitDialog()
{
    if (gpRes_007C0D67)
    {
        DIALOG_DestroyDialog(gpRes_007C0D67);
        gpRes_007C0D67 = 0;
    }
    gnNpcMenuState = 3;
    INV_SelectFirstButton();
    sub_00488F10();
    SELECT_ClearSelection();
}

// 0x004B2940
void __cdecl NPCMENU_FinishTransaction()
{
    const unsigned int nTick = GetTickCount();
// build: symbol ?gdwTradeRequestTick@* 0x007C0DE9
    if (nTick - gdwTradeRequestTick > 1000)
    {
        gdwNpcTransactionTick = nTick + 100;
    }
    else
    {
// build: symbol ?gnTradeRequestFailCount@* 0x007C0DED
        unsigned int nCount = gnTradeRequestFailCount;
        if (nCount >= 10)
            nCount = 10;
        gdwNpcTransactionTick = (nCount + 30) * 500 + nTick;
    }
    gbNpcActionPending = 0;
// build: symbol ?gbTradeClickPending@* 0x007C0DE0
    gbTradeClickPending = 0;
// build: symbol ?gnTradeItemClassId@* 0x007C0DE1
    gnTradeItemClassId = 0;
// build: symbol ?gnTradeItemUnitId@* 0x007C0DE5
    gnTradeItemUnitId = 0;
    if (!GAME_GetConnectionType())
        NPCMENU_CloseWaitDialog();
}

// 0x004B29E0
void __fastcall sub_004B29E0(int nUnitId)
{
// build: symbol ?gnPendingNpcActionUnitId@* 0x007C0D8E
    if (gbNpcActionPending && g007C0D89 == 1 && nUnitId == gnPendingNpcActionUnitId)
    {
        NPCMENU_FinishTransaction();
    }
}

// 0x004B2A00
void __fastcall sub_004B2A00(int nUnitId)
{
    if (gbNpcActionPending && g007C0D89 == 1 && nUnitId == gnPendingNpcActionUnitId)
    {
        NPCMENU_FinishTransaction();
    }
}

// 0x004B2A20
void __fastcall sub_004B2A20(int nUnitId)
{
    if (gbNpcActionPending && g007C0D89 == 1 && nUnitId == gnPendingNpcActionUnitId)
    {
        NPCMENU_FinishTransaction();
    }
}

// 0x004B2A40
void __fastcall sub_004B2A40(int nUnitId)
{
    if (gbNpcActionPending && g007C0D89 == 0 && nUnitId == gnPendingNpcActionUnitId)
    {
        NPCMENU_FinishTransaction();
    }
}

// 0x004B2A60
void __fastcall sub_004B2A60(int nUnitId)
{
    if (gbNpcActionPending && g007C0D89 == 0 && nUnitId == gnPendingNpcActionUnitId)
    {
        NPCMENU_FinishTransaction();
    }
}

// 0x004B2A80
void __fastcall NPCMENU_ResetHoverForItem(int nUnitId)
{
    D2UnitStrc* pSelected = SELECT_GetSelectedUnit();
    if (pSelected && gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1)
        && pSelected->dwUnitType == UNIT_ITEM && pSelected->dwUnitId == nUnitId)
    {
        SELECT_ClearSelection();
        INV_ResetHover();
    }
}

// 0x004B2AD0
int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int bService, int* pCost, Unicode* pText, int nMaxLength)
{
    *pCost = 0;
    if (!pItem)
        return 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        return 0;
    int nStringId = 0;
    if (bService)
    {
        const unsigned int nClassId = pItem->dwClassId;
        if (!gbNpcInteracting)
            return 0;
        if (!CUNIT_FindClientUnit(gnInteractNpcId, 1))
            return 0;
        D2UnitStrc* pNpc = NPCMENU_GetInteractNpc();
        const unsigned int nNpcClass = !pNpc ? -1 : pNpc->dwClassId;
        DATATBLS_GetItemsTxtRecord(nClassId);
        switch (nNpcClass)
        {
        case 0xF4:
        case 0xF5:
        case 0x109:
            if (NPCMENU_IsItemIdentified(pItem) == 1)
            {
                *(int*)pText = 0;
                return 1;
            }
// build: symbol ?gpPlayerQuestFlags@* 0x007C0D43
            *pCost = QUESTRECORD_GetQuestState(gpPlayerQuestFlags, 4, 0) ? 0 : 100;
            nStringId = 0xD04;
            break;
        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
        {
            if (sub_00489860())
            {
                if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x147B, ".\\UI\\npcmenu.cpp"))
                {
                    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xFB6));
                    INV_PrefixColorCode(pText, 1);
                    return 1;
                }
                if (!NPCMENU_ItemNeedsRepair(pItem))
                    return 0;
                D2UnitStrc* pVendor = NPCMENU_GetInteractNpc();
                *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, !pVendor ? -1 : pVendor->dwClassId, 3);
                nStringId = 0xD02;
                break;
            }
        }
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xF6:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
        case 0x202:
        {
            if (!sub_0062A130(pItem))
                return 0;
            D2UnitStrc* pVendor = NPCMENU_GetInteractNpc();
            *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, !pVendor ? -1 : pVendor->dwClassId, 1);
            nStringId = 0xD03;
            break;
        }
        }
    }
    else
    {
        int nType = 0;
        if (gnGlobal_007C0DB0)
            nType = 2;
        D2UnitStrc* pVendor = GetInteractNpc_Inline();
        const int nVendorId = !pVendor ? -1 : pVendor->dwClassId;
        *pCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, nVendorId, nType);
        nStringId = 0xD01;
    }
    if (!nStringId)
        return 0;
    const Unicode* pString = D2LANG_GetStringFromTblIndex(nStringId);
    if (sub_00526800(pString) + 10 > nMaxLength)
        return 0;
    sub_005267E0(pText, pString);
    Unicode wszCost[20];
    char szCost[20];
    wsprintfA(szCost, gszFormatD, *pCost);
    sub_00526F20_ToUnicode(wszCost, szCost, 19);
    sub_00526700(pText, wszCost);
    return 1;
}

// 0x004B2E20
int __cdecl NPCMENU_IsNpcMenuActive()
{
    return gnNpcMenuState != 0;
}

// 0x004B2E30
static int NPCMENU_FindNpcIndex(D2UnitStrc* pRecord)
{
    if (!pRecord)
        return -1;

    const int nId = pRecord->dwClassId;
// build: symbol ?gnNpcIndexCount@* 0x00725A74
    for (int i = 0; i < gnNpcIndexCount; ++i)
    {
        if (gaNpcIndex[i].nId == nId)
            return i;
    }
    return 0;
}

// 0x004B2E70
int __cdecl NPCMENU_MenuBack()
{
    if (gnNpcTradeMode == 5)
    {
        if (gpRes_007C0D5F)
        {
            DIALOG_DestroyDialog(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        NPCMENU_HireMercWait();
        return 1;
    }
    if (gnNpcMenuState == 4)
    {
        if (gpRes_007C0D5F)
        {
            DIALOG_DestroyDialog(gpRes_007C0D5F);
            gpRes_007C0D5F = 0;
        }
        sub_004B2650(0, 0);
        return 1;
    }
    SELECT_ClearSelection();
    D2_ASSERT(gnNpcMenuState != 4, 0x14F9);
    return 1;
}

// 0x004B2F00
int __cdecl NPCMENU_MenuClose()
{
    DIALOG_DestroyDialog(gpRes_007C0D5F);
    gpRes_007C0D5F = 0;
    if (gnNpcTradeMode == 5)
    {
        NPCMENU_ShowMainMenu();
        return 1;
    }
    INV_ResetNpcButtonsFromPending();
    gnNpcMenuState = 3;
    SELECT_ClearSelection();
    return 1;
}

// 0x004B2F50
void __cdecl NPCMENU_ShowTradeDialog()
{
// build: symbol ?gpTradeDialog@* 0x007C0D5F
    D2_ASSERT(!gpTradeDialog, 0x151B);

    gnNpcMenuState = 4;
    gpTradeDialog = DIALOG_CreateDialog(sub_00468730(), sub_00468740(), NPCMENU_MenuClose, 0, 0, 1, 1, 0, 0, 0, 1);
    ROSTER_SetCtrlState(gpTradeDialog, 1);

    D2UnitStrc* pItem;
    int bService;
    int bShowItem = 1;
    switch (gnNpcTradeMode)
    {
    case 1:
        DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD14), 0x15, 0, 4, 1, 0, 0);
        bService = 0;
        break;

    case 2:
        DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD13), 0x15, 0, 4, 1, 0, 0);
        bService = 1;
        break;

    case 3:
        bService = 1;
        DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD17), 0x15, 0, 4, 1, 0, 0);
        break;

    case 4:
        bService = 1;
        DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD16), 0x15, 0, 4, 1, 0, 0);
        break;

    case 5:
        DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD18), 0x15, 0, 4, 1, 0, 0);
        bShowItem = 0;
        break;

    default:
        D2_ASSERT(0, 0x1550);
    }

    if (bShowItem)
    {
        pItem = CUNIT_FindClientUnit(gnTradeItemUnitId, 4);
        if (!pItem)
        {
            return;
        }

        Unicode wszName[0xC0];
        INV_BuildItemName(pItem, wszName, 0xBF);
        const int nLength = sub_00526800(wszName);
        int i = 0;
        int bDone = 0;
        while (!bDone)
        {
            if (i >= nLength)
            {
                bDone = 1;
            }
            else if (wszName[i].wChar == '\n')
            {
                wszName[i].wChar = 0;
                bDone = 1;
            }
            else
            {
                ++i;
            }
        }

        DIALOG_AddTextLine(gpTradeDialog, wszName, 0xF, 0, 4, 1, NPCMENU_MenuBack, 0);

        int nCost;
        gwszCost_007C0DF5[0].wChar = 0;
        NPCMENU_GetTradeCostText(pItem, bService, &nCost, gwszCost_007C0DF5, 0x28);

        {
            Unicode wszCost[10];
            char szCost[12];
            wsprintfA(szCost, gszFormatD, nCost);
            sub_00526F20_ToUnicode(wszCost, szCost, 9);
            sub_005267E0(gwszCost_007C0DF5, wszCost);
        }

        DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD12), 0xF, 0, 4, 1, NPCMENU_MenuBack, 0);
        DIALOG_AddTextLine(gpTradeDialog, gwszCost_007C0DF5, 0xF, 0, 4, 1, NPCMENU_MenuBack, 0);
    }

    DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD10), 0xF, 0, 0, 1, NPCMENU_MenuBack, 1);
    DIALOG_AddTextLine(gpTradeDialog, D2LANG_GetStringFromTblIndex(0xD11), 0xF, 0, 0, 1, NPCMENU_MenuClose, 1);
}

// 0x004B3230
int __fastcall NPCMENU_GetInteractNpcId(int* pLow)
{
    *pLow = gnInteractNpcId;
    return gbNpcInteracting;
}

// 0x004B3240
void __fastcall NPCMENU_StoreMessage(const D2StoredMsgPacketStrc* pPacket)
{
    if (!pPacket)
    {
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (!gaStoredMsgs_007C0C85[i].bUsed)
        {
            D2StoredMsgStrc* pEntry = &gaStoredMsgs_007C0C85[i];
            pEntry->wValue = pPacket->wValue;
            pEntry->dwValue = pPacket->dwValue;
            pEntry->bUsed = 1;
            return;
        }
    }
}

// 0x004B3290
void __cdecl NPCMENU_ResetSlots()
{
    for (int i = 0; i < 10; ++i)
    {
        gaNpcItemSlots[i].nUnitId = 0;
    }
}

// 0x004B32D0
int __cdecl MONSTER_GetQuestFlags()
{
    return (int)gpGlobal_007C0D43;
}

// 0x004B32E0
int __cdecl MONSTER_GetGameQuestFlags()
{
    return (int)gpGlobal_007C0D47;
}

// 0x004B32F0
void __cdecl NPCMENU_ResetNpcMenu()
{
// build: symbol ?gnHirelingName@* 0x00725494
    gnHirelingName = 0xFFFF;
    NPCMENU_FreeNpcMenu();
    TEXT_InitNpcMenu();
    gbNpcEntriesProcessed = 0;
    for (int i = 0; i < gnPartyCount_0072554C; ++i)
    {
        gaNpcEntryFlags[i].nFlag0 = 0;
        gaNpcEntryFlags[i].nFlag1 = 0;
    }
}

// 0x004B3330
void __cdecl sub_004B3330_Empty()
{
}

// 0x004B3340
void __fastcall NPCMENU_ReloadHirelingPopup(unsigned short nArg)
{
    for (int i = 0; i < 10; ++i)
    {
        if (gaNpcItemSlots[i].wId == nArg)
            break;
    }
    TEXT_LoadPopupHireling();
}

// 0x004B3360
void __fastcall NPCMENU_CheckObjectFound(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x13E && pUnit->dwAnimMode == 2)
        gbObjectFound = 1;
}

// 0x004B3380
void __fastcall NPCMENU_OnNpcWantsInteract(D2PacketRecord6Strc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    if (pUnit->dwClassId == 0x216)
    {
        if (MONSTER_GetOwnerGUID(pUnit) != -1)
        {
            sub_004B9A00(0x11FB, pUnit, 0, 0, 0);
        }
        else
        {
            sub_004B9A00(0x11FF, pUnit, 0, 0, 0);
        }
        return;
    }

    D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    if (pUnit == pNpc)
    {
        return;
    }

    GFX_AddUnitOverlay(pUnit, 0x48, 3, 0, 0, 0, 0, 0);
    if (pUnit->dwClassId != 0x14B || NPCMENU_GetInteractNpc() || !gpPlayerQuestFlags)
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(gpPlayerQuestFlags, 12, 8) || QUESTRECORD_GetQuestState(gpPlayerQuestFlags, 12, 1))
    {
        return;
    }

    gbObjectFound = 0;
    CUNIT_ForEachObject(NPCMENU_CheckObjectFound);
    if (!gbObjectFound)
    {
        sub_004B9A00(0xF8F, pUnit, 0, 0, 0);
    }
}

// 0x004B3470
int __cdecl NPCMENU_IsNpcTalkActive()
{
    if (gbNpcInteracting && CUNIT_FindClientUnit(gnInteractNpcId, 1) && gnNpcMenuState == 1)
    {
        return 1;
    }
    return 0;
}

// 0x004B34A0
int __cdecl NPCMENU_IsAnyDialogOpen()
{
    if (gpTradeDialog || gpNpcSubMenuDialog || gpNpcWaitDialog || gpNpcMainMenuDialog || gpNpcMessageDialog
        || gpNpcConfirmDialog || gpNpcHireDialog || gpNpcGreetingDialog)
    {
        return 1;
    }

    return 0;
}

// 0x004B3500
int __cdecl NPCMENU_IsGambleShop()
{
    return gbGambleShop;
}

// 0x004B3510
void __fastcall NPCMENU_FlagNpcEntries(D2NpcMonListPacketStrc* pPacket)
{
    for (int i = 0; i < 12; ++i)
    {
        if (pPacket->nMonIds[i] < sgptDataTables->nMonStatsTxtRecordCount)
        {
            for (int j = 0; j < gnNpcEntryCount; ++j)
            {
                if (gaNpcEntries[j].nId == pPacket->nMonIds[i])
                {
                    gaNpcEntries[j].bFlag = 1;
                }
            }
        }
    }
}

// 0x004B3560
D2ClientValueBlockStrc::D2ClientValueBlockStrc()
{
    for (int i = 0; i < 20; ++i)
        anValues[i] = 0;
}

// 0x004B35B0
int __cdecl NPCMENU_OpenItemServicePanel()
{
// build: symbol ?gpNpcMainMenuDialog@* 0x007C0D6B
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    UI_SetUIVar(8, 1, 0);
    UI_StartUIVarDelay();
    INV_ResetHover();
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    gnNpcMenuState = 7;
// build: symbol ?gnNpcTradeMode@* 0x007C0D31
    gnNpcTradeMode = 0;
    USEITEM_OpenNpcItemPanel(gnInteractNpcId);
    return 1;
}

// 0x004B3610
void __cdecl NPCMENU_CloseTradeDialog()
{
    if (gpNpcHireDialog)
    {
        DIALOG_DestroyDialog(gpNpcHireDialog);
        delete gpNpcTradeObj;
        gpNpcTradeObj = 0;
        gpNpcHireDialog = 0;
    }

    gnNpcTradeMode = 5;
    NPCMENU_ShowTradeDialog();
}

extern "C" int __fastcall MONSTER_GetOwnerGUID(UnitView* unit)
{
    PayloadView* data = (unit && unit->type == 1) ? unit->payload : 0;
    if (!data)
        return -1;
    return data->value3c;
}

// 0x004B3660
int __cdecl NPCMENU_HireMercHandler()
{
    sub_004B9A00(2, 0, 0, 0, 0);
// build: symbol ?gpNpcTradeObj@* 0x007C0D83
    const int nCount = gpNpcTradeObj->GetCount();
    gnHireMercIndex = nCount;
// build: symbol ?gnInteractNpcId@* 0x007C0D25
    gnHireMercNpcId = gnInteractNpcId;
    if (nCount < 10 && gpNpcTradeObj->GetAt(nCount) < 10)
    {
        if (ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) == -1
// build: symbol ?gnHirelingName@* 0x00725494
            && (!GAME_IsExpansion() || (!ROSTERPETS_CountPets(sub_00463DD0_GetPlayerUnit(), 7) && gnHirelingName == 0xFFFF)))
        {
            NPCMENU_HireMercWait();
            return 0;
        }
        NPCMENU_CloseTradeDialog();
    }
    return 0;
}

// 0x004B3700
int __cdecl NPCMENU_InitImbueHandler()
{
    gnGlobal_00726CC1 = 4;
    gpfnGlobal_00726CD7 = NPCMENU_OpenItemServicePanel;
    gwGlobal_00726CC9 = 0xFB1;
    return 1;
}

// 0x004B3730
int __cdecl NPCMENU_InitSocketHandler()
{
    gnGlobal_0072723D = 4;
    gpfnGlobal_00727253 = NPCMENU_OpenItemServicePanel;
    gwGlobal_00727245 = 0x58DC;
    return 1;
}

// 0x004B3760
int __cdecl NPCMENU_InitPersonalizeHandler()
{
    gnGlobal_0072728B = 5;
    gpfnGlobal_007272A5 = NPCMENU_OpenItemServicePanel;
    gwGlobal_00727295 = 0x58DD;
    return 1;
}

// 0x004B3790
void __fastcall NPCMENU_RemoveInventoryClientUnits(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 10; ++i)
    {
        gaNpcItemSlots[i].nUnitId = 0;
    }

    if (!pUnit)
    {
        return;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pItemUnit = INVENTORY_UnitIsItem(pItem);
        if (pItemUnit)
        {
            const int nUnitType = pItemUnit ? pItemUnit->dwUnitType : UNIT_INVALID;
            const int nUnitId = pItemUnit ? pItemUnit->dwUnitId : -1;
            CUNIT_RemoveClientSideUnit(nUnitId, nUnitType);
        }
    }
    INVENTORY_RemoveInventoryItems(pInventory);
    D2COMMON_10251_Return(pInventory);
}

// 0x004B3830
extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (pUnit)
    {
        NPCMENU_RemoveInventoryClientUnits(pUnit);
    }
    if (gnNpcSoundActive)
    {
        sub_004BA840(gnNpcSoundHandle);
    }
    gnNpcSoundActive = 0;
    gnNpcSoundHandle = 0;
}

// 0x004B3870
int __fastcall NPCMENU_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll)
{
    D2UnitStrc* pNpc = GetInteractNpc_Inline();
    if (!pNpc)
        return 0;
    const int nNpcClass = pNpc->dwClassId;
    if (bRepairAll)
    {
        switch (nNpcClass)
        {
        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            break;
        default:
            return 0;
        }
        if (!sub_00489870())
            return 1;
// build: symbol ?gnNpcTransactionCost@* 0x007C0D7F
        gnNpcTransactionCost = ITEMS_GetAllRepairCosts(0, pPlayer, nNpcClass, GAME_GetDifficulty(), gpPlayerQuestFlags, 0);
// build: symbol ?gnNpcTradeMode@* 0x007C0D31
        gnNpcTradeMode = 3;
// build: symbol ?gbTradeClickPending@* 0x007C0DE0
        gbTradeClickPending = 1;
// build: symbol ?gnTradeItemUnitId@* 0x007C0DE5
        gnTradeItemUnitId = 0;
        SELECT_RefreshHoverUnit(0);
        gnGlobal_007C0D4B = nX;
        gnGlobal_007C0D4F = nY;
    }
    else
    {
        if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
            return 0;
// build: symbol ?gdwLastTradeSendTick@* 0x007C0DF1
        if (bCheckTick && GetTickCount() - gdwLastTradeSendTick < 0x1F4)
            return 0;
        gnGlobal_007C0D4B = nX;
        gnGlobal_007C0D4F = nY;
        if (nMode == 1)
        {
            switch (nNpcClass)
            {
            case 0x9A:
            case 0xB2:
            case 0xFD:
            case 0x101:
            case 0x1FF:
                if (sub_00489860())
                {
                    if (!NPCMENU_ItemNeedsRepair(pItem))
                        return 0;
                    gnNpcTradeMode = 3;
                    gnNpcTransactionCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, nNpcClass, 3);
                    break;
                }
                gnNpcTransactionCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, nNpcClass, 1);
                if (!sub_0062A130(pItem))
                    return 0;
                gnNpcTradeMode = 2;
                break;
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
            case 0x202:
                gnNpcTransactionCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, nNpcClass, 1);
                if (!sub_0062A130(pItem))
                    return 0;
                gnNpcTradeMode = 2;
                break;
            case 0xF4:
            case 0xF5:
            case 0xF6:
            case 0x109:
            case 0x208:
                if (ITEMS_CheckItemFlag(pItem, 0x10, 0x999, gszNpcMenuFile) == 1)
                    return 0;
                gnNpcTradeMode = 4;
                break;
            default:
                return 0;
            }
        }
        else
        {
            D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
            if (INVENTORY_GetCursorItem(pInventory))
                return 0;
            gnNpcTradeMode = 1;
            int nType = 0;
            if (gbGambleShop)
                nType = 2;
            gnNpcTransactionCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pItem, GAME_GetDifficulty(), gpPlayerQuestFlags, nNpcClass, nType);
        }
        gbTradeClickPending = 1;
        gnTradeItemUnitId = GetUnitIdOrNone(pItem);
// build: symbol ?gnTradeItemClassId@* 0x007C0DE1
        gnTradeItemClassId = GetClassIdOrNone(pItem);
        SELECT_RefreshHoverUnit(0);
        if (!((gnNpcTradeMode == 2 && bCheckTick) || (gnNpcTradeMode == 1 && bCheckTick)))
        {
            sub_004B9A00(1, 0, 0, 0, 0);
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
            gnNpcMenuState = 4;
            sub_004B2F50();
            return 1;
        }
    }
    sub_004B2650(1, nArg);
    return 1;
}

// 0x004B3C00
void __fastcall sub_004B3C00(int nUnitId)
{
// build: symbol ?gnPendingNpcActionUnitId@* 0x007C0D8E
// build: symbol ?gbNpcActionPending@* 0x007C0D96
    if (gbNpcActionPending && gnPendingNpcActionType == 0 && nUnitId == gnPendingNpcActionUnitId)
    {
        NPCMENU_FinishTransaction();
    }
}

// 0x004B3C20
void __fastcall NPCMENU_EndNpcInteraction(int nValue)
{
    if (sub_00463DD0_GetPlayerUnit())
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
    }

    D2UnitStrc* pNpc = CUNIT_FindClientUnit(nValue, 1);
    if (pNpc)
    {
        NPCMENU_RemoveInventoryClientUnits(pNpc);
    }

    if (gnNpcSoundActive)
    {
        sub_004BA840(gnNpcSoundHandle);
    }

    gnNpcSoundActive = 0;
    gnNpcSoundHandle = 0;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nValue, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
    }

    MSG_SendTwoDwords(0x30, 1, nValue);
    TEXT_ClearTextPanel();
    gbNpcInteracting = 0;
    UI_SetUIVar(8, 1, 0);

    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            pUnit->pMonsterData->nClientFlags &= ~1;
        }

        UNITMODE_SetUnitMode(pUnit, 1);
    }
}

// 0x004B3D10
void __fastcall NPCMENU_CancelNpcAndFlag(int nUnitId)
{
    NPCMENU_EndNpcInteraction(nUnitId);
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
    }
}

// 0x004B3D40
int __cdecl NPCMENU_OpenGambleShop()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnInteractNpcId, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        return 1;
    }

    gnNpcMenuState = 3;
    gbGambleShop = 1;
    UI_SetUIVar(0xC, 0, 0);
    MSG_SendDwords3(0x38, 2, gnInteractNpcId, 0);
    gpNpcPlayerUnit = sub_00463DD0_GetPlayerUnit();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B3DE0
void __cdecl NPCMENU_CloseNpc()
{
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
}

// 0x004B3E10
void __fastcall NPCMENU_RefreshNpcEntries(D2UnitStrc* pUnit)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
        return;

// build: symbol ?gnNpcEntryCount@* 0x0072554C
    for (int i = 0; i < gnNpcEntryCount; ++i)
    {
        if (gaNpcEntries[i].bSelected == 1)
        {
            gaNpcEntries[i].bSelected = 0;
            D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0xFAB);
            sub_004B1680(&gaNpcEntries[i]);
        }
        gaNpcEntries[i].bRefreshed = 1;
    }

    if (!(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        return;

    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    gbNpcInteracting = 0;
}

// 0x004B3ED0
void __cdecl NPCMENU_CloseNpcShop()
{
    UI_SetUIVar(12, 1, 0);
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
}

// 0x004B3F10
void __cdecl NPCMENU_CloseByState()
{
    if (gnNpcMenuState == 1)
    {
        gbNpcMessageShown = 0;
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
    }
    else if (gnNpcMenuState >= 3 && gnNpcMenuState <= 6)
    {
        NPCMENU_CloseNpcShop();
        sub_0048A6A0_ClearHover();
    }
    else if (gnNpcMenuState == 7)
    {
        sub_004C0440();
    }
    else if (gbNpcMessageShown)
    {
        gbNpcMessageShown = 0;
        NPCMENU_CloseNpc();
    }

    NPCMENU_FreeDialogs();
    gnNpcMenuState = 0;
}

// 0x004B3FB0
void __cdecl NPCMENU_CloseNpc2()
{
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
}

// 0x004B3FE0
void __cdecl sub_004B3FE0()
{
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
}

// 0x004B4010
int __cdecl NPCMENU_CloseSubMenuDialog()
{
    if (gbNpcMessageShown)
        return 0;

// build: symbol ?gpNpcMessageDialog@* 0x007C0D6F
    if (gpNpcMessageDialog)
    {
        DIALOG_DestroyDialog(gpNpcMessageDialog);
        gpNpcMessageDialog = 0;
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
    }
    return 1;
}

// 0x004B4070
int __cdecl NPCMENU_CloseConfirmDialog()
{
    if (gbNpcMessageShown)
    {
        return 0;
    }

// build: symbol ?gpNpcConfirmDialog@* 0x007C0D73
    if (gpNpcConfirmDialog)
    {
        DIALOG_DestroyDialog(gpNpcConfirmDialog);
        gpNpcConfirmDialog = 0;
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
    }

    return 1;
}

// 0x004B40D0
static void __stdcall NPCMENU_ShowNpcMessage(char bFlag, int nIndex)
{
// build: symbol ?gbNpcInteracting@* 0x007C0D29
    D2UnitStrc* pNpc = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    if (!pNpc)
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

    gbNpcMessageShown = 1;
    TEXT_SetTextCallback(NPCMENU_NpcMessageCallback, 0);
    DIALOG_DestroyDialog(gpRes_007C0D6F);
    gpRes_007C0D6F = 0;
// build: symbol ?gpNpcEntry@* 0x007C0C7D
    gpNpcEntry->bSelected = 1;
    if (!gbNpcEntriesProcessed)
    {
        sub_004B17A0();
        if (bFlag)
            nIndex = gpNpcEntry->nSelected;
    }
    D2UnitStrc* pUnit = gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    TEXT_ShowNpcMessage(pUnit, gpNpcEntry->pChoices[nIndex % gpNpcEntry->nChoices].wId, 0);
}

// 0x004B41C0
int __cdecl NPCMENU_NextNpcMessage()
{
    NPCMENU_ShowNpcMessage(1, gpNpcEntry->nSelected);
    return 1;
}

// 0x004B41E0
int __cdecl NPCMENU_GreetNpcMessage()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    if (gbNpcInteracting)
    {
        D2UnitStrc* pNpc = CUNIT_FindClientUnit(gnInteractNpcId, 1);
        if (pNpc)
        {
            switch (pNpc->dwClassId)
            {
            case MONSTER_MALAH:
                if (nClass == 4)
                {
                    NPCMENU_ShowNpcMessage(0, 0xF);
                    return 1;
                }
                break;
            case MONSTER_NIHLATHAK:
                if (nClass == 2)
                {
                    NPCMENU_ShowNpcMessage(0, 0xB);
                    return 1;
                }
                break;
            case MONSTER_QUAL_KEHK:
                if (nClass == 3)
                {
                    NPCMENU_ShowNpcMessage(0, 0xA);
                    return 1;
                }
                break;
            }
        }
    }
    if (nClass == gpNpcEntry->pChoices[1].nClass)
        NPCMENU_ShowNpcMessage(0, 1);
    else
        NPCMENU_ShowNpcMessage(0, 0);
    return 1;
}

// 0x004B4290
int __cdecl NPCMENU_ConfirmNpcAction()
{
    sub_004B4070();
    MSG_SendDwords3(0x38, 0, gnInteractNpcId, 0);
    return 1;
}

// 0x004B42B0
int __cdecl NPCMENU_OpenTradeShop()
{
    if (gnNpcSoundActive)
    {
        if (gnNpcSoundHandle)
        {
            sub_004BA840(gnNpcSoundHandle);
            gnNpcSoundHandle = 0;
        }
        gnNpcSoundActive = 0;
    }

    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnInteractNpcId, 1);
    if (!(pUnit ? pUnit->pInventory : 0))
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return 1;
    }

    gnNpcMenuState = 3;
    gbGambleShop = 0;
    UI_SetUIVar(0xC, 0, 0);
    MSG_SendDwords3(0x38, 1, gnInteractNpcId, 0);
    gpNpcPlayerUnit = sub_00463DD0_GetPlayerUnit();
    gwGlobal_007C0DD8 = 0;
    return 1;
}

// 0x004B4380
void __cdecl NPCMENU_UpdateNpcInteract()
{
    D2UnitStrc* pNpc;
    if (CUNIT_IsPlayerDeadOrMissing() || (NPC_GET_INTERACT_UNIT() && (pNpc = NPC_GET_INTERACT_UNIT()) != 0 && pNpc->dwAnimMode == 12) || !NPC_GET_INTERACT_UNIT())
    {
        NPCMENU_FreeDialogs();
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
    }

    if (gpNpcMessageDialog)
    {
        sub_004B8100(gpNpcMessageDialog);
        return;
    }

    if (gpNpcConfirmDialog)
    {
        sub_004B8100(gpNpcConfirmDialog);
        return;
    }

    if (gpNpcMainMenuDialog)
    {
        GAME_ResetMouseState();
        sub_004B8100(gpNpcMainMenuDialog);
        return;
    }

    if (gpNpcSubMenuDialog)
    {
        sub_004B8100(gpNpcSubMenuDialog);
        return;
    }

    if (gpNpcWaitDialog)
    {
        D2UnitStrc* pInteract;
        if (NPCMENU_GetInteractNpc() && (pInteract = NPCMENU_GetInteractNpc()) != 0 && pInteract->dwClassId == 0x202 && !gbWaitSoundPlayed)
        {
            if (!gbWaitSoundScheduled)
            {
                gbWaitSoundScheduled = 1;
                gdwWaitSoundTick = (ITEMS_RollLimitedRandomNumber(&sub_00463DD0_GetPlayerUnit()->pSeed, 30) + 120) * 1000 + GetTickCount();
            }

            if (gdwWaitSoundTick > GetTickCount())
            {
                gbWaitSoundPlayed = 1;
                sub_004B9A00(0x11D0, 0, 0, 0, 0);
            }
        }

        if (GAME_GetConnectionType() && gdwNpcTransactionTick && gdwNpcTransactionTick < GetTickCount())
        {
            NPCMENU_CloseWaitDialog();
            return;
        }

        if (gdwNpcRequestTimeout < GetTickCount())
        {
            INV_SendLeaveGame();
            WINMAIN_SetExitApplication(0);
            GAME_SetCinematicExit(1);
            GAME_RequestExit();
        }
        return;
    }

// build: symbol ?gpTradeDialog@* 0x007C0D5F
    if (gpTradeDialog)
    {
        if (!INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory) && !CURSOR_GetCursorItem())
        {
            sub_004B8100(gpTradeDialog);
            return;
        }

        gnNpcMenuState = 3;
        INV_EnterNpcMenuState();
// build: symbol ?gdwTradeRequestTick@* 0x007C0DE9
        gdwTradeRequestTick = GetTickCount();
        gnTradeRequestFailCount += 1;
        DIALOG_DestroyDialog(gpTradeDialog);
        gpTradeDialog = 0;
        return;
    }

    if (gpNpcHireDialog)
    {
        sub_004B8100(gpNpcHireDialog);
        return;
    }

// build: symbol ?gpNpcGreetingDialog@* 0x007C0D7B
    if (gpNpcGreetingDialog)
    {
        sub_004B8100(gpNpcGreetingDialog);
    }
}

// 0x004B45D0
int __cdecl NPCMENU_NpcMenuCancel()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    return 1;
}

// 0x004B4620
int __cdecl NPCMENU_NpcMenuCancelB()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    return 1;
}

// 0x004B4670
int __cdecl NPCMENU_NpcMenuCancelText()
{
// build: symbol ?gpNpcGreetingDialog@* 0x007C0D7B
    if (gpNpcGreetingDialog)
    {
        DIALOG_DestroyDialog(gpNpcGreetingDialog);
        gpNpcGreetingDialog = 0;
// build: symbol ?gwNpcGreetingString@* 0x007C0C77
        MSG_SendTwoDwords(0x31, gnInteractNpcId, gwNpcGreetingString);
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    return 1;
}

// 0x004B46D0
int __cdecl NPCMENU_NpcMenuCancelTextB()
{
    if (gpNpcGreetingDialog)
    {
        DIALOG_DestroyDialog(gpNpcGreetingDialog);
        gpNpcGreetingDialog = 0;
        MSG_SendTwoDwords(0x31, gnInteractNpcId, gwNpcGreetingString);
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    return 1;
}

// 0x004B4730
int __cdecl NPCMENU_NpcMenuTalk()
{
    if (gpNpcGreetingDialog)
    {
        DIALOG_DestroyDialog(gpNpcGreetingDialog);
        gpNpcGreetingDialog = 0;
    }

    if (!(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return 1;
    }

    TEXT_ShowNpcMessage(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0, gwNpcGreetingString, 0);
    NPCMENU_AddUsedString(gwNpcGreetingString);
// build: symbol ?gwNpcMessageString@* 0x007C0C79
    if (gwNpcMessageString == 0xFFFF)
    {
        gnNpcMenuState = 0;
    }
    else
    {
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcTextCallback, 0);
    }
    MSG_SendTwoDwords(0x31, gnInteractNpcId, gwNpcGreetingString);
    return 1;
}

static __forceinline int NPC_FindIndex_Inline(D2UnitStrc* pNpc)
{
    if(!pNpc)return -1;
    const int nId=pNpc->dwClassId;
// build: symbol ?gnNpcIndexCount@* 0x00725A74
    for(int i=0;i<gnNpcIndexCount;++i)
        if(gaNpcIndex[i].nId==nId)return i;
    return 0;
}

// 0x004B4830
void __cdecl NPCMENU_BuildNpcMenu()
{
    if(gpNpcMainMenuDialog){FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0xC74);exit(-1);}
    if(!NPC_GetInteractUnit_Inline())
    {
        gnNpcMenuState=0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8,1,0);
        return;
    }
    if(gnGlobal_007C0D2D==252 || gnGlobal_007C0D2D==198 || gnGlobal_007C0D2D==515 || gnGlobal_007C0D2D==150)
    {
        D2UnitStrc* pPlayer=sub_00463DD0_GetPlayerUnit();
        MSG_SendDwords3(0x38,3,gnInteractNpcId,!pPlayer?-1:pPlayer->dwUnitId);
    }
    D2CoordStrc tCoords;
    tCoords.nX=0;
    tCoords.nY=0;
    NPCMENU_GetNpcDialogPos(&tCoords);
    gpNpcMainMenuDialog=DIALOG_CreateDialog(tCoords.nX,tCoords.nY,NPCMENU_NpcMenuCancel,NPCMENU_NpcMenuCancelB,0,0,1,0,0,0,1);
    sub_004B8370(gpNpcMainMenuDialog,1);
    Unicode wszName[80];
    sub_005267E0(wszName,CUNIT_GetUnitName(NPC_GetInteractUnit_Inline()));
    sub_00526800(wszName);
    DIALOG_AddTextLine(gpNpcMainMenuDialog,wszName,21,0,4,1,0,0);
    int nIndex=NPC_FindIndex_Inline(NPC_GetInteractUnit_Inline());
    if(nIndex<0 || nIndex>=gnNpcIndexCount)return;
    gnNpcMenuState=1;
    for(int i=0;i<gaNpcIndex[nIndex].nCount-1;++i)
    {
        Unicode wszLine[512];
        unsigned short nStringId=gaNpcIndex[nIndex].awIds[i];
        int bEnabled=1;
        if(nStringId==0x1507)
        {
            const Unicode* wszHireling=D2LANG_GetStringFromTblIndex(0x2B0D);
            if((unsigned short)gnHirelingName_00725494!=0x421)wszHireling=D2LANG_GetStringFromTblIndex((unsigned short)gnHirelingName_00725494);
            sub_005269D0(512,wszLine,D2LANG_GetStringFromTblIndex(0x58A8),wszHireling,gnNpcMenuValue);
        }
        else if(nStringId==0xD09)
        {
            int nLife=STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(),STAT_HITPOINTS,0);
            if(nLife>=STATLIST_GetMaxLifeFromUnit(sub_00463DD0_GetPlayerUnit()))continue;
            int nCost=UNITS_GetHealingCost(sub_00463DD0_GetPlayerUnit());
            if(!nCost)nCost=1;
            sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(gaNpcIndex[nIndex].awIds[i]));
            Unicode wszNumber[10] = {0,0,0,0,0,0,0,0,0,0};
            char szNumber[12];
            wsprintfA(szNumber,gszFormatD,nCost);
            sub_00526F20_ToUnicode(wszNumber,szNumber,9);
            sub_00526700(wszLine,wszNumber);
            if(!nCost)bEnabled=0;
        }
        else if(nStringId==0xFB4)
        {
            int bCharge=0;
// build: symbol ?gpPlayerQuestFlags@* 0x007C0D43
            if(!QUESTRECORD_GetQuestState(gpPlayerQuestFlags,4,0) && !QUESTRECORD_GetQuestState(gpPlayerQuestFlags,4,1))bCharge=1;
            int nCount=ITEMS_GetNoOfUnidItems(sub_00463DD0_GetPlayerUnit());
            if(nCount)
            {
            gaNpcIndex[nIndex].nCount=3;
            if(bCharge)
            {
                sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(0xFB5));
                Unicode wszNumber[10];
                char szNumber[12];
                nCount*=100;
                wsprintfA(szNumber,gszFormatD,nCount);
                sub_00526F20_ToUnicode(wszNumber,szNumber,9);
                sub_00526700(wszLine,wszNumber);
            }
            else sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(0xFB4));
            }
            else {gaNpcIndex[nIndex].nCount=2;continue;}
        }
        else if(nStringId==0x2BA0)
        {
            if(QUESTRECORD_GetQuestState(gpPlayerQuestFlags,41,0))continue;
            if(QUESTRECORD_GetQuestState(gpPlayerQuestFlags,41,1)!=1)
            {
                if(GAME_GetDifficulty()!=2 || QUESTRECORD_GetQuestState(gpPlayerQuestFlags,41,1))continue;
            }
            sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(gaNpcIndex[nIndex].awIds[i]));
        }
        else sub_005267E0(wszLine,D2LANG_GetStringFromTblIndex(nStringId));
        DIALOG_AddTextLine(gpNpcMainMenuDialog,wszLine,15,0,0,1,gaNpcIndex[nIndex].apfHandlers[i],bEnabled);
    }
    DIALOG_AddTextLine(gpNpcMainMenuDialog,D2LANG_GetStringFromTblIndex(0x102E),15,0,0,1,NPCMENU_NpcMenuCancel,1);
}

// 0x004B4CF0
int __cdecl NPCMENU_NpcMenuReturn()
{
    SELECT_ClearSelection();
    sub_004B9A00(1, 0, 0, 0, 0);
    DIALOG_DestroyDialog(gpNpcSubMenuDialog);
    gpNpcSubMenuDialog = 0;
    if (gnNpcMenuState == 0xC)
    {
        if (gnNpcTradeMode == 5)
        {
            NPCMENU_EndNpcInteraction(gnInteractNpcId);
            UI_SetUIVar(8, 1, 0);
            return 1;
        }
        NPCMENU_BuildNpcMenu();
        return 1;
    }

    D2_ASSERT(gnNpcTradeMode != 6, 0xD55);
    D2_ASSERT(gnNpcMenuState != 8, 0xD56);
    gnNpcMenuState = 3;
    INV_ResetButtonsFromMenuReturn();
    return 1;
}

static inline unsigned int NPCDLG_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004B4DB0
void __cdecl NPCMENU_OpenGreetingDialog()
{
    if (!NPC_GetInteractUnit_Inline())
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

// build: symbol ?gpNpcGreetingDialog@* 0x007C0D7B
    D2_ASSERT(!gpNpcGreetingDialog, 0xD69);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcGreetingDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, NPCMENU_NpcMenuCancelText, NPCMENU_NpcMenuCancelTextB, 0, 0, 1, 0, 0, 0, 1);
    ROSTER_SetCtrlState(gpNpcGreetingDialog, 1);

    Unicode wszName[80];
    for (int i = 0; i < 80; ++i)
    {
        wszName[i].wChar = 0;
    }

    sub_005267E0(wszName, CUNIT_GetUnitName(NPC_GetInteractUnit_Inline()));
    const int nLength = sub_00526800(wszName);
    for (int i = 0; i < nLength; ++i)
    {
        const unsigned short wChar = wszName[i].wChar;
// build: symbol ?gaCaseTable@* 0x00730778
        wszName[i].wChar = wChar < 0x100 ? gaCaseTable[wChar] : wChar;
    }

    DIALOG_AddTextLine(gpNpcGreetingDialog, wszName, 0x15, 0, 4, 1, 0, 0);
    gnNpcMenuState = 1;

    unsigned short aStrings[5];
    int nStrings = 0;
    aStrings[nStrings++] = 0xD3A;
    aStrings[nStrings++] = 0xD3B;
    aStrings[nStrings++] = 0xD3C;
    aStrings[nStrings++] = 0xD3D;
    aStrings[nStrings++] = 0xD3E;
    D2UnitStrc* pPlayer = sub_00463DD0();
    const unsigned int nRoll = NPCDLG_RollSeed_Inline(&pPlayer->pSeed) % nStrings;
    DIALOG_AddTextLine(gpNpcGreetingDialog, D2LANG_GetStringFromTblIndex(aStrings[nRoll]), 0xF, 0, 0, 1, NPCMENU_NpcMenuTalk, 1);
    DIALOG_AddTextLine(gpNpcGreetingDialog, D2LANG_GetStringFromTblIndex(0x102E), 0xF, 0, 0, 1, NPCMENU_NpcMenuCancelText, 1);
    sub_004B82F0_Select(gpNpcGreetingDialog, 1);
}

// 0x004B4FD0
void __stdcall NPCMENU_OpenNpcWindow(D2UnitStrc* pUnit)
{
    GAME_ResetMouseState();
    if (!pUnit)
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }
    if (NPC_GetInteractUnit_Inline())
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }
    gnNpcMenuState = 1;
    gnNpcTradeMode = 0;
    gnNpcGoldSnapshot = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
    UI_CloseUIVars(0, 0);
    GAME_ResetMouseState();
    D2_ASSERT(!NPC_GetInteractUnit_Inline(), 3529);
    NPCMENU_SetNpcInteract(pUnit);
    D2UnitStrc* pNpc = NPC_GetInteractUnit_Inline();
    if (pNpc)
        pNpc->dwFlags &= ~2;
    if (!UI_SetUIVar(8, 2, 0))
    {
        NPCMENU_CloseNpc();
        return;
    }
    NPCMENU_OpenGreetingDialog();
    const int nIndex = sub_004B1D70_FindNpcEntry();
    if (gaNpcEntries[nIndex].bRefreshed)
    {
        const int nSound = sub_004E0590_PickNpcSound(NPCMENU_GetInteractNpc(), 1);
        if (nSound)
        {
            UNITSND_ReleaseSkillSfx(pUnit);
            sub_004B9A00(nSound, sub_00463DD0_GetPlayerUnit(), 0, 1, 0);
        }
        gaNpcEntries[nIndex].bRefreshed = 0;
    }
}

// 0x004B5140
int __cdecl NPCMENU_NpcMenuAction28()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    MSG_SendDwords3(0x38, 0, gnInteractNpcId, 0x28);
    return 1;
}

// 0x004B51A0
int __cdecl NPCMENU_TravelToKurastDocks()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    MSG_SendDwords3(0x38, 0, gnInteractNpcId, 0x4B);
    return 1;
}

// 0x004B5200
int __cdecl NPCMENU_TravelToHarrogath()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    MSG_SendDwords3(0x38, 0, gnInteractNpcId, 0x6D);
    return 1;
}

// 0x004B5260
int __cdecl NPCMENU_NpcMenuAction28b()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    MSG_SendDwords3(0x38, 0, gnInteractNpcId, 0x28);
    return 1;
}

// 0x004B52C0
int __cdecl NPCMENU_TravelToRogueEncampment()
{
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }
    gnNpcMenuState = 0;
    INV_ResetHover();
    NPCMENU_EndNpcInteraction(gnInteractNpcId);
    UI_SetUIVar(8, 1, 0);
    MSG_SendDwords3(0x38, 0, gnInteractNpcId, 1);
    return 1;
}

// 0x004B5320
void __fastcall NPCMENU_OnUnitRemoved(unsigned char nUnitType, int nUnitId)
{
    D2UnitStrc* pUnit = 0;
    if (nUnitType < 6)
    {
        pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
    }

    switch (nUnitType)
    {
    case 1:
        if (pUnit)
        {
            pUnit->dwFlags |= 2;
        }

        if (gnNpcMenuState == 1)
        {
            gbNpcMessageShown = 0;
            NPCMENU_CloseNpc();
        }
        else if (gnNpcMenuState >= 3 && gnNpcMenuState <= 6)
        {
            NPCMENU_CloseNpcShop();
            INV_ResetNpcCursor();
        }
        else if (gnNpcMenuState == 7)
        {
            sub_004C0440_Thunk();
        }
        else if (gbNpcMessageShown)
        {
            gbNpcMessageShown = 0;
            NPCMENU_CloseNpc();
        }

        NPCMENU_FreeDialogs();
        gnNpcMenuState = 0;
        break;

    case 2:
    case 4:
    case 6:
        UI_CloseUIVars(1, 0);
        break;
    }
}

// 0x004B53F0
void __cdecl NPCMENU_OnTransactionResult()
{
 D2InventoryStrc* inv=sub_00463DD0_GetPlayerUnit()->pInventory;
 if(g007C0D89<=6) {
  switch(g007C0D89) {
   case 0:
    sub_004B9A00(g007C0D5B,0,0,0,0); g007C0D5B=0;
    if(!CUNIT_FindClientUnit(g007C0D8E,4)) { g007C0D96=1; return; }
    break;
   case 1:
    sub_004B9A00(0xdd,0,0,0,0);
    if(CUNIT_FindClientUnit(g007C0D8E,4)) { g007C0D96=1; return; }
    break;
   case 5: TEXT_LoadPopupHireling(); break;
  }
  g007C0D96=0;
  if(g007C0D67) { DIALOG_DestroyDialog(g007C0D67);g007C0D67=0; }
  SELECT_ClearSelection(); g007C0DE0=0;g007C0DE1=0;g007C0DE5=0;g007C0C6B=3;
  INV_SelectFirstButton();sub_00488F10();return;
 }
 if(g007C0D67) {DIALOG_DestroyDialog(g007C0D67);g007C0D67=0;}
 int text;
 switch(g007C0D89) {
 case 15:text=0xd23;break;
 case 16:text=0xd1d;break;
 case 12:text=0xd22;break;
 case 10:text=0xd1c;break;
 case 11:text=0xd20;break;
 case 7:case 8:text=0xd1e;break;
 default:text=0xd21;break;
 }
 if(g007C0C6B==5) {
 g007C0C6B=6;INV_SetNpcStateMenuReturn();
 CHECK(!gpRes_007C0D63,0x1399);
 if(g007C0D31==2) {
  D2UnitStrc* item=INVENTORY_GetCursorItem(inv);
  if(g007C0D3F==1 && item && !CURSOR_GetCursorItem()) CURSOR_SetCursorItemState(item);
 }
 gpRes_007C0D63=DIALOG_CreateDialog(sub_00468730(),sub_00468740(),NPCMENU_NpcMenuReturn,0,0,1,1,0,0,0,1);
 ROSTER_SetCtrlState(gpRes_007C0D63,1);
 DIALOG_AddTextLine(gpRes_007C0D63,D2LANG_GetStringFromTblIndex(text),0x15,0,1,1,0,0);
 DIALOG_AddTextLine(gpRes_007C0D63,D2LANG_GetStringFromTblIndex(0xd4b),0xf,0,0,1,NPCMENU_NpcMenuReturn,1);
 } else { FOG_DisplayHalt(&empty,sub_00408090(),0x13ad);exit(-1); }
}

static __forceinline void sub_004B5640_RefreshNpcMenu()
{
    if (gbNpcInteracting)
    {
        D2UnitStrc* pNpc = CUNIT_FindClientUnit(gnInteractNpcId, 1);
        if (pNpc)
        {
            switch ((unsigned int)pNpc->dwClassId)
            {
            case 0xF4:
            case 0xF5:
            case 0xF6:
            case 0x109:
            case 0x208:
                gnGlobal_00726EBC = 2;
                gnGlobal_00726EE3 = 2;
                gnGlobal_00726F0A = 2;
                gnGlobal_00726F31 = 2;
                gnGlobal_00727216 = 2;
                break;
            }
        }
    }

    NPCMENU_BuildNpcMenu();
}

// 0x004B5640
void __cdecl sub_004B5640_OpenNpcMenu()
{
    if (gpNpcWaitDialog)
    {
        DIALOG_DestroyDialog(gpNpcWaitDialog);
        gpNpcWaitDialog = 0;
    }

    const unsigned char nType = gnPendingNpcActionType;
    if (nType != 5)
    {
        if (nType != 6 && nType != 3)
        {
                int nStringId;
                switch (nType)
                {
                case 15:
                    nStringId = 0xD23;
                    break;
                case 16:
                    nStringId = 0xD1D;
                    break;
                case 12:
                    nStringId = 0xD22;
                    break;
                case 10:
                    nStringId = 0xD1C;
                    break;
                case 11:
                    nStringId = 0xD20;
                    break;
                case 7:
                case 8:
                    nStringId = 0xD1E;
                    break;
                default:
                    nStringId = 0xD21;
                    break;
                }

                gnNpcMenuState = 12;
                D2_ASSERT(!gpNpcSubMenuDialog, 0x1413);

                gpNpcSubMenuDialog = DIALOG_CreateDialog(sub_00468730(), sub_00468740(), NPCMENU_NpcMenuReturn, 0, 0, 1, 1, 0, 0, 0, 1);
                ROSTER_SetCtrlState(gpNpcSubMenuDialog, 1);
                DIALOG_AddTextLine(gpNpcSubMenuDialog, D2LANG_GetStringFromTblIndex(nStringId), 0x15, 0, 1, 1, 0, 0);
                DIALOG_AddTextLine(gpNpcSubMenuDialog, D2LANG_GetStringFromTblIndex(0xD4B), 0xF, 0, 0, 1, NPCMENU_NpcMenuReturn, 1);
            return;
        }
    }
    else
    {
        TEXT_LoadPopupHireling();
    }

    sub_004B5640_RefreshNpcMenu();
}

// 0x004B5810
int __cdecl NPCMENU_CloseSubMenuToMain()
{
    if (gbNpcMessageShown)
    {
        return 0;
    }

// build: symbol ?gpNpcMessageDialog@* 0x007C0D6F
    if (gpNpcMessageDialog)
    {
        DIALOG_DestroyDialog(gpNpcMessageDialog);
        sub_004B9A00(1, 0, 0, 0, 0);
        gpNpcMessageDialog = 0;
        NPCMENU_BuildNpcMenu();
    }

    return 1;
}

struct Handler;

struct HandlerNode;

struct SelectionEntry;

struct Message
{
    char pad00[10];
    short wheel;
    char padWheel[24-10-2];
    int handled;
    int result;
};

struct Handler
{
    virtual int unused0(Message*);
    virtual int unused1(Message*);
    virtual int wheel(Message*);
    virtual int unused3(Message*);
    virtual int unused4(Message*);
    virtual int unused5(Message*);
    virtual int unused6(Message*);
    virtual int previous2(Message*);
    virtual int next2(Message*);
    virtual int previous1(Message*);
    virtual int next1(Message*);
};

struct HandlerNode
{
    Handler* object;
    HandlerNode* next;
};

// 0x004B5850
int __cdecl sub_004B5850()
{
    if (gbNpcMessageShown)
    {
        return 0;
    }

// build: symbol ?gpNpcConfirmDialog@* 0x007C0D73
    if (gpNpcConfirmDialog)
    {
        DIALOG_DestroyDialog(gpNpcConfirmDialog);
        sub_004B9A00(1, 0, 0, 0, 0);
        gpNpcConfirmDialog = 0;
        NPCMENU_BuildNpcMenu();
    }

    return 1;
}

// 0x004B5890
void __stdcall NPCMENU_OpenNpcPanel(int nStringIndex, int nEntryIndex)
{
    D2_ASSERT(!gpNpcMessageDialog, 0x76F);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcMessageDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, NPCMENU_CloseSubMenuToMain, sub_004B4010, 0, 0, 1, 0, 0, 0, 1);
    ROSTER_SetCtrlState(gpNpcMessageDialog, 1);
    DIALOG_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(nStringIndex), 0x15, 0, 4, 1, 0, 0);

    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    if (!pTextHeader)
    {
        DIALOG_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, NPCMENU_CloseSubMenuToMain, 1);
        return;
    }

    const int nCount = TEXT_GetMenuType2NodeCount(pTextHeader);
// build: symbol ?gnNpcEntryIndex@* 0x007C0C81
    gnNpcEntryIndex = nEntryIndex;
    if (!gaNpcEntries[nEntryIndex].bFlag14)
    {
        DIALOG_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD47), 0xF, 0, 0, 1, sub_004B41E0, 1);
    }

    DIALOG_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD43), 0xF, 0, 0, 1, sub_004B41C0, 1);

    for (int i = 0; i < nCount; ++i)
    {
        const unsigned short nStringId = TEXT_GetStringIdOfMenuType2Node(pTextHeader, i);
        DIALOG_AddTextLine(gpNpcMessageDialog, TEXT_GetTextString(nStringId), 0xF, 0, 0, 1, sub_004B1A80, 1);
    }

    if (gnInteractNpcClassId == 0xC9)
    {
        DIALOG_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD40), 0xF, 0, 0, 1, sub_004B1B80, 1);
    }

    if (gnInteractNpcClassId == 0x109 || gnInteractNpcClassId == 0xF4 || gnInteractNpcClassId == 0xF5 || gnInteractNpcClassId == 0x208 || gnInteractNpcClassId == 0xF6)
    {
        D2UnitStrc* pPlayer = sub_00463DD0();
        if (pPlayer && pPlayer->pInventory)
        {
            for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pItem);
                if (pCheck && ITEMS_GetBaseCode(pCheck) == 0x20786F62)
                {
                    DIALOG_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0x8B7), 0xF, 0, 0, 1, sub_004B1C00, 1);
                    break;
                }
            }
        }
    }

    DIALOG_AddTextLine(gpNpcMessageDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, NPCMENU_CloseSubMenuToMain, 1);
}

// 0x004B5AD0
void __stdcall NPCMENU_OpenConfirmDialog(int nStringIndex)
{
    D2_ASSERT(!gpNpcConfirmDialog, 0x7D7);

    D2CoordStrc tCoords;
    tCoords.nX = 0;
    tCoords.nY = 0;
    NPCMENU_GetNpcDialogPos(&tCoords);

    gpNpcConfirmDialog = DIALOG_CreateDialog(tCoords.nX, tCoords.nY, sub_004B5850, sub_004B4070, 0, 0, 1, 0, 0, 0, 1);
    ROSTER_SetCtrlState(gpNpcConfirmDialog, 1);
    DIALOG_AddTextLine(gpNpcConfirmDialog, D2LANG_GetStringFromTblIndex(nStringIndex), 0x15, 0, 4, 1, 0, 0);
    DIALOG_AddTextLine(gpNpcConfirmDialog, D2LANG_GetStringFromTblIndex(0xD49), 0xF, 0, 0, 1, sub_004B4290, 1);
    DIALOG_AddTextLine(gpNpcConfirmDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B5850, 1);
}

// 0x004B5C00
int __cdecl NPCMENU_StartConfirm()
{
    gnNpcMenuState = 1;
    sub_004B1D70_FindNpcEntry();
    NPCMENU_OpenConfirmDialog(0x2BA0);
    return 1;
}

// 0x004B5C20
int __cdecl NPCMENU_CloseHireDialog()
{
    if (gpNpcHireDialog)
    {
        DIALOG_DestroyDialog(gpNpcHireDialog);
        delete gpNpcTradeObj;
        gpNpcTradeObj = 0;
        gpNpcHireDialog = 0;
    }

    NPCMENU_BuildNpcMenu();
    return 1;
}

#pragma pack(push, 1)
struct D2GSPacketSrv2A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned int unk0x03;
    unsigned int unk0x07;
    unsigned int unk0x0B;
};
#pragma pack(pop)

extern D2GSPacketSrv2A gtPacket2A;                                                                  // 0x007C0D87

// 0x004B6390
void __fastcall NPCMENU_HandleNpcTransaction(D2GSPacketSrv2A* pPacket)
{
    gtPacket2A = *pPacket;
// build: symbol ?gnNpcGoldSnapshot@* 0x007C0C73
    gnNpcGoldSnapshot = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    if (gnNpcMenuState == 5)
    {
        NPCMENU_OnTransactionResult();
        return;
    }
    if (gnNpcMenuState == 10)
    {
        sub_004B5640_OpenNpcMenu();
        return;
    }
    if (pPacket->unk0x02 == 1)
        sub_004B9A00(0xDD, 0, 0, 0, 0);
}

// 0x004B6410
int __cdecl NPCMENU_InitHireHandler()
{
    gnGlobal_00726DF9 = 3;
    gpfnGlobal_00726E0B = NPCMENU_ShowMainMenu;
    gwGlobal_00726DFF = 0xD45;
    return 1;
}

// 0x004B6440
static int __stdcall NPCMENU_ToggleNpcHandler(int bAdd, int nIndex)
{
    if (!FOG_IsExpansion() || !GAME_IsExpansion())
    {
        return 0;
    }

#define NPC_ENTRY (gaNpcIndex[nIndex])
    if (bAdd)
    {
        for (int i = 0; i < NPC_ENTRY.nCount; ++i)
        {
            if (NPC_ENTRY.apfHandlers[i] == NPCMENU_ResurrectMercWait)
            {
                return 1;
            }
        }

        for (int i = 0; i < NPC_ENTRY.nCount; ++i)
        {
            if (NPC_ENTRY.apfHandlers[i] == NPCMENU_ShowMainMenu)
            {
                for (int j = NPC_ENTRY.nCount - 1; j >= i; --j)
                {
                    NPC_ENTRY.apfHandlers[j + 1] = NPC_ENTRY.apfHandlers[j];
                    NPC_ENTRY.awIds[j + 1] = NPC_ENTRY.awIds[j];
                }
                ++NPC_ENTRY.nCount;
                NPC_ENTRY.apfHandlers[i] = NPCMENU_ResurrectMercWait;
                NPC_ENTRY.awIds[i] = 0x1507;
                return 1;
            }
        }

        const int nPos = NPC_ENTRY.nCount - 1;
        for (int j = NPC_ENTRY.nCount - 1; j >= nPos; --j)
        {
            NPC_ENTRY.apfHandlers[j + 1] = NPC_ENTRY.apfHandlers[j];
            NPC_ENTRY.awIds[j + 1] = NPC_ENTRY.awIds[j];
        }
        ++NPC_ENTRY.nCount;
        NPC_ENTRY.apfHandlers[nPos] = NPCMENU_ResurrectMercWait;
        NPC_ENTRY.awIds[nPos] = 0x1507;
        return 1;
    }
    else
    {
    for (int i = 0; i < (NPC_ENTRY.nCount); ++i)
    {
        if (NPC_ENTRY.apfHandlers[i] == NPCMENU_ResurrectMercWait)
        {
            for (int j = i; j < NPC_ENTRY.nCount - 1; ++j)
            {
                NPC_ENTRY.apfHandlers[j] = NPC_ENTRY.apfHandlers[j + 1];
                NPC_ENTRY.awIds[j] = NPC_ENTRY.awIds[j + 1];
            }
            --NPC_ENTRY.nCount;
            return 1;
        }
    }
    }
    return 1;
}

// 0x004B65F0
int __cdecl NPCMENU_InitTravelLutGholeinHandler()
{
    gnGlobal_00726E47 = 3;
    gpfnCallback_00726E59 = sub_004B5140;
    gwGlobal_00726E4D = 0xD36;
    return 1;
}

// 0x004B6620
int __cdecl NPCMENU_InitTravelKurastDocksHandler()
{
    gnGlobal_00726E95 = 3;
    gpfnGlobal_00726EA7 = NPCMENU_TravelToKurastDocks;
    gwGlobal_00726E9B = 0xD38;
    return 1;
}

extern short gwGlobal_007272DF;                                                                             // 0x007272DF

// 0x004B6650
int __cdecl sub_004B6650_InitHandler()
{
    gnGlobal_007272D9 = 3;
    gpfnGlobal_007272EB = NPCMENU_ShowMainMenu;
    gwGlobal_007272DF = 0xD45;
    return 1;
}

// 0x004B6680
int __cdecl NPCMENU_InitTravelHarrogathHandler()
{
    if (GAME_IsExpansion())
    {
        gnGlobal_00726F7F = 3;
        gpfnGlobal_00726F91 = NPCMENU_TravelToHarrogath;
        gwGlobal_00726F85 = 0x58D2;
    }
    return 1;
}

// 0x004B66B0
static void __stdcall NPCMENU_OpenNpcInteract(D2UnitStrc* pUnit, int bReopen)
{
    GAME_ResetMouseState();
    if (!pUnit)
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

    gnNpcMenuState = 1;
    gnNpcTradeMode = 0;
    gnNpcGoldSnapshot = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
    UI_CloseUIVars(0, 0);

    if (!bReopen)
    {
        if (pUnit == (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        {
            return;
        }
        if (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0)
        {
            NPCMENU_CloseNpc();
            return;
        }
    }
    else
    {
        gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0;
    }

    gbNpcInteracting = 1;
    gnInteractNpcId = pUnit->dwUnitId;
    gnInteractNpcClassId = pUnit->dwClassId;
    pUnit->dwFlags &= ~2;

    const int nNpcId = pUnit->dwClassId;
    NPCMENU_RunNpcQuestHandlers(nNpcId, gpPlayerQuestFlags, gaNpcHandlers, gnHandlerCount);

    if (gnNpcSoundActive)
    {
        if (gnNpcSoundHandle)
        {
            sub_004BA840(gnNpcSoundHandle);
            gnNpcSoundHandle = 0;
        }
        gnNpcSoundActive = 0;
    }

    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0x96:
        if (STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_LEVEL, 0) >= 8)
        {
            NPCMENU_InitHireHandler();
        }
        NPCMENU_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0xB);
        break;

    case 0xC6:
        NPCMENU_ToggleNpcHandler(gnHirelingName != 0xFFFF, 8);
        break;

    case 0xFC:
        NPCMENU_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x18);
        break;

    case 0x16F:
        NPCMENU_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x15);
        break;

    case 0x203:
        NPCMENU_ToggleNpcHandler(gnHirelingName != 0xFFFF, 0x2B);
        break;
    }

    if (!UI_SetUIVar(8, 0, 0))
    {
        gnNpcMenuState = 0;
        pUnit->dwFlags |= 2;
        MSG_SendTwoDwords(0x30, 1, !pUnit ? -1 : pUnit->dwUnitId);
        gbNpcInteracting = 0;
        NPCMENU_ClearNpcInventoryAndSound(pUnit->dwUnitId);
        return;
    }

    NPCMENU_BuildNpcMenu();
    if (bReopen)
    {
        return;
    }

    int nType = 0;
    for (int i = 0; i < gnNpcEntryCount; ++i)
    {
        if (gaNpcEntries[i].nId == nNpcId)
        {
            if (gaNpcEntries[i].bFlag == 1)
            {
                gaNpcEntries[i].bFlag = 0;
                nType = 2;
            }
            if (gaNpcEntries[i].bRefreshed != 1)
            {
                return;
            }
            gaNpcEntries[i].bRefreshed = 0;
            break;
        }
    }

    const int nSound = sub_004E0590_PickNpcSound(pUnit, nType);
    if (!nSound)
    {
        return;
    }

    UNITSND_ReleaseSkillSfx(pUnit);
    gnNpcSoundHandle = sub_004B9A00(nSound, sub_00463DD0_GetPlayerUnit(), 0, 1, 0);
    if (nType == 2)
    {
        MSG_SendWord(0x4D, nNpcId);
        gnNpcSoundActive = 1;
        return;
    }
    gnNpcSoundHandle = 0;
}

#undef NPC_ENTRY

// 0x004B6980
void __fastcall NPCMENU_SetNpcMenuState(unsigned short wValue, int nValue)
{
    gnHirelingName = wValue;
    gnNpcMenuValue = nValue;
    if (wValue == 0xFFFF)
    {
        NPCMENU_ToggleNpcHandler(0, 0xB);
        NPCMENU_ToggleNpcHandler(0, 8);
        NPCMENU_ToggleNpcHandler(0, 0x18);
        NPCMENU_ToggleNpcHandler(0, 0x15);
        NPCMENU_ToggleNpcHandler(0, 0x2B);
    }
}

// 0x004B69E0
void __cdecl NPCMENU_CloseTrade()
{
// build: symbol ?gpNpcTradeObj@* 0x007C0D83
    if (gpNpcTradeObj)
    {
        if (gpRes_007C0D77)
        {
            DIALOG_DestroyDialog(gpRes_007C0D77);
            delete gpNpcTradeObj;
            gpNpcTradeObj = 0;
            gpRes_007C0D77 = 0;
        }
        NPCMENU_BuildNpcMenu();
    }
}

// 0x004B6A30
int __fastcall NPCMENU_NpcTextCallback(void* pContext, int nArg, int nValue)
{
// build: symbol ?gwNpcGreetingString@* 0x007C0C77
// build: symbol ?gwNpcMessageString@* 0x007C0C79
    gwNpcMessageString = NPCMENU_GetFreeStringId(gwNpcGreetingString);
    if (gwNpcGreetingString == 0x251)
    {
        sub_004B9A00(0xF1, 0, 0, 0, 0);
    }
    if (gwNpcGreetingString == 0x21A)
    {
        sub_004B9A00(0xED, 0, 0, 0, 0);
    }

    if (gbNpcMessageShown == 1)
    {
        if (gwNpcMessageString != 0xFFFF && (gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0))
        {
            gwNpcLastString = gwNpcMessageString;
            TEXT_ShowNpcMessage(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0, gwNpcLastString, 1);
            NPCMENU_AddUsedString(gwNpcLastString);
            TEXT_SetTextCallback(NPCMENU_NpcTextCallback, 0);
            gwNpcGreetingString = gwNpcLastString;
            MSG_SendTwoDwords(0x31, gnInteractNpcId, gwNpcLastString);
            gwNpcMessageString = NPCMENU_GetFreeStringId(gwNpcLastString);
            return 1;
        }

        gbNpcMessageShown = 0;
        TEXT_SetTextCallback(0, 0);
        const int nIndex = NPCMENU_FindNpcIndex(gbNpcInteracting ? CUNIT_FindClientUnit(gnInteractNpcId, 1) : 0);
        if ((!nArg || !nValue) && !NPCMENU_IsSpecialNpc(gnInteractNpcClassId) && nIndex >= 0 && NPCMENU_GetInteractNpc()
            && nIndex < gnNpcIndexCount && gaNpcIndex[nIndex].bEnabled)
        {
            gnNpcMenuState = 1;
            if (NPCMENU_GetInteractNpc())
            {
                NPCMENU_OpenNpcInteract(NPCMENU_GetInteractNpc(), 1);
                return 1;
            }
            NPCMENU_CloseNpc();
            return 0;
        }

        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return 0;
    }

    gbNpcMessageShown = 0;
    TEXT_SetTextCallback(0, pContext);
    gwNpcGreetingString = 0xFFFF;
    NPCMENU_OpenGreetingDialog();
    return 0;
}

void __fastcall NPCMENU_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg); // 0x004B6DD0
struct D2TextHeaderStrc;

// 0x004B6C70
int __cdecl sub_004B6C70_OpenNpcMenu()
{
    if (!NPC_GET_INTERACT_UNIT())
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
// build: symbol ?gnInteractNpcId@* 0x007C0D25
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return 0;
    }

// build: symbol ?gpNpcMainMenuDialog@* 0x007C0D6B
    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    gnNpcMenuState = 1;
    int nEntry = sub_004B1D70_FindNpcEntry();
// build: symbol ?gpNpcEntry@* 0x007C0C7D
    gpNpcEntry = &gaNpcEntries[nEntry];
    NPCMENU_OpenNpcPanel(0xD35, nEntry);
    return 1;
}

// 0x004B6D10
int __cdecl NPCMENU_OpenConfirm()
{
    if (!NPC_GET_INTERACT_UNIT())
    {
        gnNpcMenuState = 0;
        INV_ResetHover();
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return 0;
    }

    if (gpNpcMainMenuDialog)
    {
        DIALOG_DestroyDialog(gpNpcMainMenuDialog);
        gpNpcMainMenuDialog = 0;
    }

    gnNpcMenuState = 1;
    sub_004B1D70_FindNpcEntry();
    NPCMENU_OpenConfirmDialog(0x2BA0);
    return 1;
}

// 0x004B6DA0
int __cdecl sub_004B6DA0_InitHandler()
{
    gnGlobal_00726C4C = 4;
    gpfnGlobal_00726C62 = NPCMENU_OpenConfirm;
    gwGlobal_00726C54 = 0x2BA0;
    return 1;
}

#include "gen/data/Source/D2Client/UI/npcmenu.inc"
// 0x004B6DD0
void __fastcall NPCMENU_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg)
{
    if (nUnitType == 6)
    {
        QUESTRECORD_CopyBufferToRecord(gpPlayerQuestFlags, pBuffer, 0x60, 0);
        return;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
    if (!pUnit)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
        MSG_SendTwoDwords(0x30, nArg, nUnitId);
        NPCMENU_ClearNpcInventoryAndSound(nUnitId);
        return;
    }

    CUNIT_ForEachMonster(NPCMENU_ClearInteractOverlay);
    pUnit->dwFlags |= 2;
    QUESTRECORD_CopyBufferToRecord(gpPlayerQuestFlags, pBuffer, 0x60, 0);
    NPCMENU_ResetHandlers();
    MSG_SendTwoDwords(0x2F, nUnitType, nUnitId);
    GAME_ResetMouseState();

    if (gabNpcMenuState[0])
    {
        gbNpcMessageShown = 1;
        NPCMENU_SetNpcInteract(pUnit);
        pUnit->dwFlags &= ~2;
        return;
    }

    D2TextHeaderStrc* pTextHeader = DLIGHTMAP_GetTextHeader();
    D2_ASSERT(pTextHeader, 0x1060);

    const unsigned short wString = TEXT_GetStringIdOfMenuType0Node(pTextHeader, 0);
    const int nClassId = NPC_GetUnitClassId(pUnit);
    if (MONSTERUNIQUE_CheckMonStatsFlag(nClassId, 9) && nClassId != 0x219 && nClassId != 0x21A && nClassId != 0x21B
        && nClassId != 0x20F)
    {
        CUNIT_TurnTowardPlayer(pUnit);
    }

    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gbNpcInteracting = 1;
        gnInteractNpcId = pUnit->dwUnitId;
        gnInteractNpcClassId = pUnit->dwClassId;
        NPCMENU_EndNpcInteraction(gnInteractNpcId);
        UI_SetUIVar(8, 1, 0);
        return;
    }

    gtStringList.wCount = 0;
    if (wString != 0xFFFF)
    {
        UI_CloseUIVars(0, 0);
        gwNpcGreetingString = wString;
        TEXT_ShowNpcMessage(pUnit, wString, 1);
        NPCMENU_AddUsedString(wString);
        gwNpcMessageString = NPCMENU_GetFreeStringId(wString);
        MSG_SendTwoDwords(0x31, pUnit->dwUnitId, wString);
        gbNpcMessageShown = 1;
        TEXT_SetTextCallback(NPCMENU_NpcTextCallback, 0);
        NPCMENU_SetNpcInteract(pUnit);
    }
    else
    {
        const unsigned short wString2 = TEXT_GetStringIdOfMenuType1Node(pTextHeader, 0);
        if (pUnit->dwClassId != 0x20F)
        {
            CUNIT_PlayerFaceUnit(pUnit);
        }
        if (pUnit->pDynamicPath)
        {
            D2Common_10153(pUnit->pDynamicPath);
        }

        if (wString2 != 0xFFFF)
        {
            INV_ResetHover();
            UI_CloseUIVars(0, 0);
            gwNpcGreetingString = wString2;
            gwNpcMessageString = NPCMENU_GetFreeStringId(wString2);
            NPCMENU_OpenNpcWindow(pUnit);
        }
        else
        {
            const int nClass = pUnit->dwClassId;
            if (MONSTERUNIQUE_CheckMonStatsFlag(nClass, 9))
            {
                if (NPCMENU_IsSpecialNpc(nClass))
                {
                    gbNpcInteracting = 1;
                    gnInteractNpcId = pUnit->dwUnitId;
                    gnInteractNpcClassId = pUnit->dwClassId;
                    NPCMENU_EndNpcInteraction(gnInteractNpcId);
                    UI_SetUIVar(8, 1, 0);
                    return;
                }
                INV_ResetHover();
                UI_CloseUIVars(0, 0);
                NPCMENU_OpenNpcInteract(pUnit, 0);
            }
            else
            {
                NPCMENU_EndNpcInteraction(gnInteractNpcId);
                UI_SetUIVar(8, 1, 0);
            }
        }
    }
    gbGambleShop = 0;
}

