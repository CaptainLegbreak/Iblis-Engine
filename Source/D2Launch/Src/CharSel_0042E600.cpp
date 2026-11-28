#include "D2Launch.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2MultiTypes.h"
#include "D2LevelTxt.h"
#include "D2LaunchRequest.h"
#include "D2UnitDropPacket.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "D2CommonApi2.h"
#include "D2GfxApi.h"
#include "D2WinApi.h"
#include "D2MCPClientApi.h"
#include "StormApi2.h"
#pragma intrinsic(strlen)
struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2InventoryStrc;
struct D2DynamicPathStrc;
struct D2StatListStrc;
struct SMSGHANDLER_PARAMS;
struct D2CharSelCacheStrc;
struct D2StatesTxt;
struct D2DataTablesStrc;
struct D2LaunchRequestStrc;
struct D2UnitDropItemsPacketStrc;
struct D2GridCellStrc;
struct D2CelFileStrc;
struct Unicode;
struct D2ComInterfaceStrc;
struct D2ConfigStrc;
struct D2FuncRecordStrc;
struct D2LaunchCharEntryStrc;
struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue);
};
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900
extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460
static int gnCharEntryCount; // 0x00779DC4
extern int gnSelectionB; // 0x0070CC08
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
void __fastcall CHARSEL_JoinSelectedWithDifficulty(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0
void __fastcall sub_004FC660_SetValue(D2WinControlStrc* pControl, int nValue); // 0x004FC660
int __cdecl sub_0042F6D0_GetMenusDone(); // 0x0042F6D0
extern D2WinControlStrc* gpControl_007795E0; // 0x007795E0
extern D2WinControlStrc* gpControl_007795E4; // 0x007795E4
extern void** gppSlots; // 0x00779988
extern int gnSlotCount; // 0x0077998C
int __cdecl MAINMENUS_FreeSlots(); // 0x00430A20
extern D2CharSelCacheStrc* gpCharSelCache; // 0x00779DE8
static int gbFlag_00779C6C;             // 0x00779C6C
extern char gszCharName[]; // 0x00779B68
struct D2GridCellStrc
{
    int nFlag;
    unsigned char nValue[4];
};
typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds); // 0x006CC258
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __cdecl CHATDLG_FillGameList(); // 0x00444E70
void __cdecl RECORD_WriteRecordFile(); // 0x00451620
extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId); // 0x00452040
void __cdecl AUTOMAP_SaveAutomapLayer(); // 0x004584C0
void __cdecl AUTOMAP_ResetAutomapCells(); // 0x00458680
void __cdecl AUTOMAP_LoadAutomapLayer(); // 0x00458750
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
void __fastcall UI_DrawLoadingScreen(int nArg); // 0x004565E0
unsigned char __stdcall AUTOMAP_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0
void __fastcall GFX_DrawProgressiveStateOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY); // 0x0046E1B0
void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280
void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0
void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30
void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode); // 0x00649190
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned short gwRequestId; // 0x0070CD60
extern int gnProgressiveStatesBottomWide; // 0x007111CC
extern int gnProgressiveStatesRight; // 0x007111D0
extern int gnProgressiveStatesBottom; // 0x007111D4
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern unsigned short gwSavedRequestId; // 0x0077BBDC
extern void* gpGlobal_007A0634; // 0x007A0634
extern void* gpAutomapContext; // 0x007A5164
extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68
extern int gnProgress; // 0x007BB3B4
void __stdcall CHARSEL_AddToScrollValue(int nDelta); // 0x00439E60
int __stdcall CHARSEL_HandleListKey(SMSGHANDLER_PARAMS* pMsg); // 0x00439E90
static int gnTopRow; // 0x00779DC8
void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
extern int gnBusy; // 0x00779DAC
extern "C" unsigned int __cdecl strlen(const char* sz);
struct D2LaunchCharEntryStrc
{
    char szName[0x324];
    int nFlags;
    char unk0x328[0x0C];
    int bShared;
    D2CelFileStrc* pCellFile;
    char unk0x33C[0x10];
    D2LaunchCharEntryStrc* pNext;
};
int __stdcall sub_005041B0_Destroy(D2CelFileStrc* pCellFile, int nFlag); // 0x005041B0
extern D2LaunchCharEntryStrc* gpCharEntry_00779DC0; // 0x00779DC0
struct D2WinTextBoxStrc;
struct D2WinButtonStrc;
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0
int __stdcall CHARSEL_OnScroll(SMSGHANDLER_PARAMS* pMsg);                                              // 0x00439DF0
int __cdecl CHARSEL_InitRealmScreen();                                                                 // 0x0043A2B0
void __fastcall CHARSEL_UseName(char* szName);                                                         // 0x0043ADB0
int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x004FC6E0
extern D2WinControlStrc* gpControl_007799F8;                                                                       // 0x007799F8
extern void* gapRowControls[];                                                                     // 0x00779A20
extern void* gapRowControlsX[8];                                                                          // 0x00779B40
static int gnSelected;         // 0x0070CC00
static D2WinControlStrc* gpCharSelectText; // 0x00779DD4
static D2WinControlStrc* gpControl_00779DD0;        // 0x00779DD0
static int gnLastValue;        // 0x00779DCC
int __stdcall CHARSEL_OnCreateAccountTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B8E0
int __stdcall CHARSEL_OnChangePasswordTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B940
extern D2RecordHandlerFn gpfnPrevHandler; // 0x007A2764
extern int gbOverlaysEnabled; // 0x007A289C
extern int gnOverlayStep; // 0x007A3138
extern int gnCellOriginX; // 0x007B0A54
extern int gnCellOriginY; // 0x007B0A58
void __fastcall SCMD_DropUnitItems(D2UnitDropItemsPacketStrc* pPacket); // 0x00462F60
struct D2ListMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
};
int __stdcall CHARSEL_OnCharSelectOk(D2ListMsgStrc* pMsg); // 0x00439840
char* __cdecl CHARSEL_StrStr(char* szString, const char* szSubString); // 0x0042E5B0
// This piece stays apart from CharSel.cpp. It supplies the out-of-line Unicode::Unicode(unsigned short)
// at 0x42E600, a COMDAT the linker takes from the first unit that emits it; CharSel.cpp inlines that
// constructor at every use and emits no copy. It joins the unit that emits the constructor once that is found.
// build: symbol ??0Unicode@@QAE@G@Z 0x0042E600
Unicode::Unicode(unsigned short wValue)
{
    wChar = wValue;
}
int __stdcall MAINMENUS_IsRestrictedChar(void* pControl, int nUnused, const char* pChar); // 0x0042FDE0
int __stdcall MAINMENUS_FilterLoginChar(void* pControl, int nUnused, const char* pChar); // 0x0042FE70
int __stdcall sub_00430120_OnToggle(SMSGHANDLER_PARAMS* pMsg); // 0x00430120
int __stdcall sub_00430160_OnToggle(SMSGHANDLER_PARAMS* pMsg); // 0x00430160
bool __stdcall MAINMENUS_IsLineBreak(Unicode wc); // 0x004303E0
int __stdcall MAINMENUS_OnHoverSorceress(SMSGHANDLER_PARAMS* pMsg); // 0x00430840
int __stdcall MAINMENUS_OnHoverAmazon(SMSGHANDLER_PARAMS* pMsg); // 0x00430870
int __stdcall MAINMENUS_OnHoverNecromancer(SMSGHANDLER_PARAMS* pMsg); // 0x00430920
int __stdcall MAINMENUS_OnHoverBarbarian(SMSGHANDLER_PARAMS* pMsg); // 0x00430950
int __stdcall MAINMENUS_OnHoverPaladin(SMSGHANDLER_PARAMS* pMsg); // 0x00430980
int __stdcall MAINMENUS_AddToSlots(void* pEntry); // 0x004309C0
int __cdecl MAINMENUS_CompareNames(const void* pEntry1, const void* pEntry2); // 0x00430B00
int __fastcall CHARSEL_IsExpansionFlag(int nValue); // 0x004379D0
unsigned int __fastcall CHARSEL_GetProgression(unsigned int nValue); // 0x004379E0
void __cdecl CHARSEL_RefreshRealmList(); // 0x004379F0
// 0x00437A00
static inline char* CHARSEL_GetSlotNameChecked(int nIndex)
{
// build: symbol ?GAME_GetSlotNameCount@* 0x00430B40
    if (nIndex < GAME_GetSlotNameCount())
        return MAINMENUS_GetSlotName(nIndex);
    return 0;
}
int __cdecl CHARSEL_FreeSlots(); // 0x00437A60
void* __fastcall CHARSEL_CacheFind(const char* szKey); // 0x00437A70
int __fastcall sub_M110_Emit_00437A00(int nIndex)
{
    return CHARSEL_GetSlotNameChecked(nIndex + 1) != 0;
}
void __fastcall CHARSEL_CacheStore(const char* szKey, const void* pData, unsigned int nSize); // 0x00437AB0
void __cdecl CHARSEL_ScrollNameControl(); // 0x00437C90
void __fastcall CHARSEL_CopyBaseName(const char* szName); // 0x00437F30
void __cdecl CHARSEL_FreeCharEntry(); // 0x00438060
int __fastcall CHARSEL_IsValidCharName(const char* szName); // 0x00438F40
int __stdcall CHARSEL_OnNormalDifficulty(SMSGHANDLER_PARAMS* pMsg); // 0x00439B80
int __stdcall CHARSEL_OnNightmareDifficulty(SMSGHANDLER_PARAMS* pMsg); // 0x00439BA0
int __stdcall CHARSEL_OnHellDifficulty(SMSGHANDLER_PARAMS* pMsg); // 0x00439BC0
void __stdcall CHARSEL_AddToScrollValue(int nDelta); // 0x00439E60
int __stdcall CHARSEL_HandleListKey(SMSGHANDLER_PARAMS* pMsg); // 0x00439E90
int __stdcall CHARSEL_OnListKeyDown(SMSGHANDLER_PARAMS* pMsg); // 0x0043A0D0
// build: symbol ?CHARSEL_FindSlotByName@* 0x00437A20
static int CHARSEL_FindSlotByName(const char* szName)
{
    int i = 0;
    char* szSlot;
    while (i < GAME_GetSlotNameCount() && (szSlot = MAINMENUS_GetSlotName(i)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            return 1;
        ++i;
    }
    return 0;
}
void __stdcall RECORD_RecordHandler(int nArg1, int nArg2, int nArg3); // 0x00451920
void __stdcall AUTOMAP_SetAutomapContext(void* pContext); // 0x00458CD0
extern unsigned long gdwLastClick; // 0x00779DEC
int __stdcall CHARSEL_OnListClick(D2ListMsgStrc* pMsg); // 0x0043A9D0
void __cdecl CHARSEL_InitCharList(); // 0x0043AE30
void __cdecl CHARSEL_RequestGameList(); // 0x00445020
void __cdecl UI_DrawProgressiveStates(); // 0x00453470
void __cdecl DLIGHTMAP_ScanGridCollision(); // 0x004756D0
void __fastcall MSG_ShowProgressSteps(int nDone, int nTotal); // 0x00478160
void __cdecl CHARSEL_ShowString(); // 0x0043A610
