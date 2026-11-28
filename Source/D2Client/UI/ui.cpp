#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2ClientGame.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2ItemTypes.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Path.h"
#include "D2Win32Types.h"
#include "D2GameObjs.h"
#include "D2LevelTxt.h"
#include "D2ItemsWorld.h"
#include "D2ClientUiRecords.h"
#include "D2WinSplitText.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
#include "D2WinApi.h"
#include "D2CMPApi.h"
#include "StormApi2.h"
#include "D2CommonApi3.h"
#include "D2WinApi2.h"
#include "D2LaunchApi.h"

struct D2CelFileStrc;

struct Unicode;

struct D2UiControlAStrc;

struct D2UiControlBStrc;

struct D2UiControlCStrc;


struct D2RectStrc;

struct D2SlotStrc;

struct D2SlotOwnerStrc;

struct D2MsgHandlerEntryStrc;

struct D2PanelHotkeysStrc;

struct D2ClientEntryStrc;

struct D2RosterPetStrc;

struct D2GfxDataStrc;

struct D2UnitStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2DataTablesStrc;

struct D2ImmunityTextStrc;

extern int gbPlaybackRequested; // 0x007A277C

extern int gnRecordPos; // 0x007A2784

extern int gbRecordPlaying; // 0x007A2788

extern int gdwGlobal_007A2878; // 0x007A2878

extern int gdwGlobal_007A2880; // 0x007A2880

int gnLoadingAct; // 0x007A288C

extern int gbAutomapLeft; // 0x007A51E0

extern int gbAutomapPartyNames; // 0x007113E8

extern int gnAutomapMode; // 0x007A5150

extern int gnAutomapOriginX; // 0x007A520C

extern int gnAutomapOriginY; // 0x007A5208


extern int gnCofMemoryUsed; // 0x007A8918

D2CelFileStrc* gpBoxPiecesCel; // 0x007A2798

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

struct D2SlotStrc
{
    int unk0x00;
    int nClass;
    int unk0x08;
};

struct D2SlotOwnerStrc
{
    char unk0x00[0x20];
    D2SlotStrc* pSlots;
};


void __fastcall CUNIT_ForEachPlayer(void (__fastcall* pfnCallback)(D2UnitStrc*)); // 0x00464950

void __fastcall UI_DrawPartyMemberText(D2UnitStrc* pUnit); // 0x00453330




struct D2PanelHotkeysStrc
{
    int nIndex26Sec;
    int nIndex16Sec;
    int nIndex26;
    int nIndex16;
    int nIndex29Sec;
    int nIndex29;
    int nIndex2CSec;
    int nIndex2C;
    D2MsgHandlerEntryStrc* f_20;
};

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl CHAT_InitChatIme(); // 0x0047B090

void __cdecl sub_0047B4D0_Nop(); // 0x0047B4D0




void __cdecl TEXT_ResetNpcPanel(); // 0x00491940


void __cdecl INV_ClearPanelPage(); // 0x0048A680

void __cdecl INV_LoadStashPanelCels(); // 0x00489E50

void __cdecl INV_LoadCubePanelCel(); // 0x0048A4B0



extern D2MsgHandlerEntryStrc gaGameUIHandlers[]; // 0x006D5F28

extern D2MsgHandlerEntryStrc gaInventoryHandlers[]; // 0x006D5F58

extern D2MsgHandlerEntryStrc gaSkillTreeHandlers[]; // 0x006D5FAC

extern D2MsgHandlerEntryStrc gaMiniSkillHandlers[]; // 0x006D5FC4

extern D2MsgHandlerEntryStrc gaStatScreenHandlers[]; // 0x006D5FD0

extern D2MsgHandlerEntryStrc gaNewStatsHandlers[]; // 0x006D5FE8

extern D2MsgHandlerEntryStrc gaPetIconHandlers[]; // 0x006D6000

extern D2MsgHandlerEntryStrc gaNewSkillsHandlers[]; // 0x006D600C

extern D2MsgHandlerEntryStrc gaEscMenuHandlers[]; // 0x006D6030

extern D2MsgHandlerEntryStrc gaAutomapHandlers[]; // 0x006D6084

extern D2MsgHandlerEntryStrc gaQuestLogHandlers[]; // 0x006D615C

extern D2MsgHandlerEntryStrc gaIniScrollHandlers[]; // 0x006D61B0

extern D2MsgHandlerEntryStrc gaWaypointHandlers[]; // 0x006D61C8

extern D2MsgHandlerEntryStrc gaMiniPanelHandlers[]; // 0x006D6204

extern D2MsgHandlerEntryStrc gaPartyScreenHandlers[]; // 0x006D621C

extern D2MsgHandlerEntryStrc gaHelpScreenHandlers[]; // 0x006D62C4

extern D2MsgHandlerEntryStrc gaHelpButtonHandlers[]; // 0x006D6300

extern D2MsgHandlerEntryStrc gaHireIconHandlers[]; // 0x006D6318

extern D2MsgHandlerEntryStrc gaMercInvHandlers[]; // 0x006D633C

extern D2MsgHandlerEntryStrc gaRecipeScrollHandlers[]; // 0x006D6360

extern D2MsgHandlerEntryStrc gaNpcShopHandlers[]; // 0x0070F878

extern D2MsgHandlerEntryStrc gaQuestScreenHandlers[]; // 0x0070F8D8

extern D2MsgHandlerEntryStrc gaMpTradeHandlers[]; // 0x0070F930

extern D2MsgHandlerEntryStrc gaStashHandlers[]; // 0x0070F9D0

extern D2MsgHandlerEntryStrc gaCubeHandlers[]; // 0x0070FA30

extern D2MsgHandlerEntryStrc gaBeltRowsHandlers[]; // 0x0070FA84

extern const D2PanelHotkeysStrc gtNpcShopHotkeys; // 0x006D5F88

extern const D2PanelHotkeysStrc gtQuestScreenHotkeys; // 0x006D618C

extern const D2PanelHotkeysStrc gtMpTradeHotkeys; // 0x006D6234

extern const D2PanelHotkeysStrc gtStashHotkeys; // 0x006D6258

extern const D2PanelHotkeysStrc gtCubeHotkeys; // 0x006D627C

extern const D2PanelHotkeysStrc gtBeltRowsHotkeys; // 0x006D62A0




void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080


const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30


unsigned long gdwUIVarTick;                                                                        // 0x007A2790



extern int gbCinematicExpansion; // 0x007A5238

extern void* gpPopupOkCelA; // 0x007A523C

extern void* gpOkCancelButtonCel; // 0x007A5240

extern void* gpPopupOkCelB; // 0x007A5244

extern int gnViewEffectMagnitude; // 0x007B9534

extern D2RosterPetStrc* gpRosterPets; // 0x007BB5BC

void __cdecl INV_ReturnToStashState(); // 0x00489880

void __cdecl INV_ClearGoldDialogFlag(); // 0x004A7A80



void __cdecl UI_CloseGoldDialog(); // 0x00453EE0





int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall DIALOG_DrawDialog(void* pObj); // 0x004B8100



D2UiControlAStrc* gpGoldControlA; // 0x007A27A4

D2UiControlBStrc* gpGoldControlB; // 0x007A27A8

D2UiControlCStrc* gpGoldControlC; // 0x007A27AC

D2UiControlCStrc* gpGoldControlD; // 0x007A27B0

int gbGoldPanelFlag; // 0x007A27B4

#pragma pack(push, 2)

struct D2ImmunityTextStrc
{
    int nStat;
    unsigned short wString;
    int nColor;
};

#pragma pack(pop)

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0


D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60



void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20


int __fastcall UI_GetHoverRect(D2RectStrc* pRect); // 0x00454880

int __fastcall AUTOMAP_GetHoverMonsterName(D2UnitStrc* pUnit, unsigned short nArg); // 0x00452580

void __fastcall GAME_SetHoverLine(const Unicode* pText, int nColor); // 0x00452520



extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const D2ImmunityTextStrc gaImmunityTexts[6]; // 0x006D6418

extern Unicode gwszHoverText[]; // 0x007A2A78

extern int gnHoverTextState; // 0x007A2C78

extern Unicode gwszHoverName[]; // 0x007A2F38


int gbLoadingScreenActive; // 0x007A2868

int gnGfxMemory; // 0x007A8914

int gnCofMemoryLimit; // 0x007A891C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C


extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" const char gszFmtInt_006D6454[]; // 0x006D6454

extern "C" const char gszUiCpp[]; // 0x006D6458

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0



extern "C" const char gszFormatD[]; // 0x006D57BC



int __fastcall ROSTER_GetKillCount(D2StoredUnitRecordStrc* pRecord); // 0x00479B80

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    unsigned int nWidth;
    unsigned int nHeight;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

extern "C" unsigned int __cdecl strlen(const char* szString);


extern "C" int __cdecl PLAYER_GetScreenOffsetX();                                                          // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY();                                                      // 0x0045AFD0

const Unicode* __fastcall UI_GetLevelName(int nLevelId); // 0x00453E70

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30

void __fastcall UI_DrawUnitHoverName(D2UnitStrc* pUnit);                                          // 0x00454AD0


void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070





const char* __fastcall ROSTER_GetPortalOwnerName(int nUnitId);                                              // 0x0047A290


const Unicode* __fastcall D2LANG_GetStringByReferenceString(const char* szKey);                                       // 0x00524E20

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0



extern D2ViewStrc* gpClientView;                                                                         // 0x007A0640

// The state of each UI variable, by UIVAR index.
#define UIVAR_PANEL 0x0A
#define UIVAR_MINIPANEL 0x15
int gaUIVarStates[0x26]; // 0x007A27C0

extern Unicode gwszPopUpText[80];                                                                       // 0x007A2C80

extern int gnPopUpTextX;                                                                              // 0x007A2D20

extern int gnPopUpTextY;                                                                              // 0x007A2D24

extern int gnPopUpTextMode;                                                                              // 0x007A2D28

Unicode gwszPopUpText[80]; // 0x007A2C80

Unicode gwszHoverLine[256]; // 0x007A2D30

Unicode gwszHoverText[256]; // 0x007A2A78

Unicode gwszHoverName[256]; // 0x007A2F38

extern D2MsgHandlerEntryStrc gaKeyConfigWheelHandlers[];                                                    // 0x006D6024

extern D2MsgHandlerEntryStrc gaKeyConfigHandlers[];                                                    // 0x006D60C0

struct D2Block0xA0Strc;

struct D2Block0xA0Strc
{
    unsigned short wData[0x50];
};




void __cdecl CHAT_CloseChatInput(); // 0x0047B2E0

void __cdecl sub_0047B4E0_Nop(); // 0x0047B4E0


void __cdecl INV_CloseStashPanel(); // 0x00489EE0

void __cdecl INV_ShutdownCubePanel(); // 0x0048A500



void __cdecl sub_0049CF50_SendWaypointClose(); // 0x0049CF50

void __cdecl sub_0049FF00_Nop(); // 0x0049FF00



extern "C" void __cdecl QUESTLOG_ResetQuestButtonState(); // 0x004A3000






void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __cdecl DLIGHTMAP_GetProgress(); // 0x00478150

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __cdecl GAME_ResetMouseState(); // 0x0044DA40










int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

void __fastcall UI_DrawUnitHover(D2UnitStrc* pUnit); // 0x00454F30



void __cdecl ESCMENU_DrawOptions(); // 0x0047E3D0


void __cdecl UI_DrawPetHover(); // 0x00452D20


void __cdecl PANEL_DrawQuantityWarningIcons(); // 0x00497E00

void __cdecl PLAYER_DrawAutomap(); // 0x0045AD60

void __cdecl GAME_DrawLevelLoadingScreen(); // 0x00455510

void __cdecl HIREABLES_UpdateHirelingPanel(); // 0x00493340

void __cdecl HIREABLES_DrawPetIcons(); // 0x00494020

void __cdecl INV_DrawMercPanel(); // 0x004929F0

void __stdcall INV_DrawRecipeScroll(); // 0x0048BC10


void __cdecl INV_DrawInventoryPanel(); // 0x0048EDF0





void __cdecl PANEL_DrawPartyPanel(); // 0x0049C3D0

void __cdecl TEXT_DispatchTextData(); // 0x0049FF10

void __cdecl TEXT_DrawWaypointPanel(); // 0x0049C9C0

void __cdecl HIREABLES_LoadHelpCels(); // 0x00494320

void __cdecl sub_00494EB0_DrawHelpShade(); // 0x00494EB0

void __cdecl PANEL_DrawControlPanel(); // 0x00499450


void __cdecl PANEL_SetBeltExpandedMode(); // 0x00498E90


void __cdecl VIEW_DrawHelpButtons(); // 0x00495180






void __cdecl PANEL_DrawLifeManaText(); // 0x00498120

void __cdecl MINIPANEL_UpdateSlotBar(); // 0x0047F710

void __cdecl CHAT_DrawChatPanel(); // 0x0047B720

void __cdecl INV_DrawHelpScreen(); // 0x004966C0




void __cdecl WARDENCLIENT_DrawHostileIcon(); // 0x00496B10

void __cdecl UI_DrawHoverText(); // 0x00454A70


void __cdecl UI_DrawHoverName(); // 0x004554B0

void __cdecl UI_DrawStoredUnitNumber(); // 0x00453B30

void __cdecl UI_DrawDeathScreen(); // 0x00453100

void __cdecl VIEW_DrawCountdown(); // 0x0046C130

D2CelFileStrc* gpLoadingScreen; // 0x007A2888

int gnLoadingFrame; // 0x007A2A6C

int gbLoadingAfterUnload; // 0x007A27B8

unsigned char gnLoadingBarColor; // 0x007A2A70

unsigned char gnLoadingBoxColor; // 0x007A2A71


int gnPanelFlag; // 0x007A2864

unsigned short gwDialogAmountHigh; // 0x007A2A6A

int gnGoldPanelMode; // 0x007A279C

int __cdecl WINMAIN_IsHardcore();                                                                      // 0x0044B850


D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType);                             // 0x004788B0

void __cdecl sub_005269D0_FormatText(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...);                  // 0x005269D0

int gbDeathScreenShown;                                                                            // 0x007A2890

D2CelFileStrc* gpYouDiedHardcoreCel;                                                              // 0x007A2894

D2CelFileStrc* gpYouDiedInstCel;                                                                  // 0x007A2898


static void __stdcall UI_GetPlayerHoverName(D2UnitStrc* pUnit, Unicode* pDst, int nMaxLength, int* pValue, int* pFlag);

static void __stdcall UI_ShowUnitHoverName(D2UnitStrc* pUnit, int bSet);

static int __stdcall UI_GetRosterHoverName(D2UnitStrc* pUnit, Unicode* pDst, int* pValue, int* pFlag);

static __forceinline int SetHoverPositionFromUnit(D2UnitStrc* pUnit);




#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

void __cdecl WINMAIN_SetCharDiedFlag();                                                                                // 0x0044B860

void __fastcall WINMAIN_SetExitApplication(int nValue);                                                          // 0x0044B880


void __fastcall UI_SetPanelHandlers(int nUIVar);                                                         // 0x00455720

void __fastcall CURSOR_SetCursorPosition(int nA, int nB);                                                               // 0x00468770


void __cdecl CHAT_ClearChatLine();                                                                                // 0x0047BDC0


extern const int gaUIVarDefaults[];                                                                // 0x006D6378

extern int gbGameServerReady;                                                                              // 0x007A0618



void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10


void __cdecl AUTOMAP_FreeAutomap(); // 0x0045A5C0




void __cdecl CMDTBL_DisableHotkeyHandlers(); // 0x0046ACB0

void __fastcall sub_00472890(D2DrlgActStrc* pAct); // 0x00472890

void __cdecl ESCMENU_FreeOptionMenus(); // 0x0047DFD0

void __cdecl ESCMENU_LoadAlwaysRun(); // 0x0047E720

void __cdecl ESCMENU_SaveAlwaysRun(); // 0x0047E750

void __cdecl MINIPANEL_SaveMiniPanel(); // 0x0047F130


void __cdecl INV_FreeInvPanelCels(); // 0x00486980

void __cdecl INV_FreeNpcCels(); // 0x004892F0

void __cdecl INV_FreeHoradricCel(); // 0x0048A600

void __cdecl HIREABLES_FreeHirelingIcons(); // 0x00492EC0

void __cdecl VIEW_ResetLifeColors(); // 0x00492F90


void __cdecl HIREABLES_FreeHelpCels(); // 0x00494EE0

void __cdecl HIREABLES_FreePanelCels(); // 0x00496990

void __cdecl PANEL_ClearPair(); // 0x00498E80


void __cdecl PANEL_LoadPartyCels(); // 0x0049C0A0

void __cdecl PANEL_FreePartyCels(); // 0x0049C0F0

void __cdecl TEXT_CloseWaypointPanel(); // 0x0049C700





















extern D2DrlgActStrc* gnTownLevelId; // 0x007A063C

extern D2CelFileStrc* gpLoadingCell; // 0x007A2794

extern D2CelFileStrc* gpBuySellButton; // 0x007A287C

D2CelFileStrc* gpPentspinCel; // 0x007A2878

D2CelFileStrc* gpFocus16Cel; // 0x007A2880

int gdwGlobal_007A2884; // 0x007A2884

unsigned long gdwUILastTick; // 0x007A313C

#pragma function(memset)

struct D2InventoryStrc;

extern "C" const char gszNew[];                                                                    // 0x006CC82C

struct D2UiControlBaseStrc
{
    static void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, gszNew, -1, 0);
    }
};

struct D2UiControlAStrc : D2UiControlBaseStrc
{
    int unk0x04[2];

    D2UiControlAStrc(int nX, int nY, int nFlag, int (__cdecl* pfnCallback)());                              // 0x004BC480
    virtual ~D2UiControlAStrc();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual int GetDirection();
    virtual unsigned int GetStep(int nArg);
};

struct D2UiControlBStrc : D2UiControlBaseStrc
{
    int unk0x04[2];

    D2UiControlBStrc(int nX, int nY, int nWidth, int nArg4, int nValue, int nArg6, int (__cdecl* pfnCallback)(), int nArg8); // 0x004BBD80
    virtual ~D2UiControlBStrc();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual unsigned int GetValue();
    virtual void sub_Virtual30();
    virtual void sub_Virtual34();
    virtual void SetValue(int nValue);
    virtual void sub_Virtual3C();
    virtual void sub_Virtual40();
    virtual void SetActive(int bActive);
};

struct D2UiControlCStrc : D2UiControlBaseStrc
{
    int unk0x04[2];

    D2UiControlCStrc(int nX, int nY, int nFlag, int (__cdecl* pfnCallback)());                              // 0x004BB0F0
    virtual ~D2UiControlCStrc();
    virtual void sub_Virtual04();
    virtual void sub_Virtual08();
    virtual void sub_Virtual0C();
    virtual void sub_Virtual10();
    virtual void sub_Virtual14();
    virtual void sub_Virtual18();
    virtual void sub_Virtual1C();
    virtual void sub_Virtual20();
    virtual void sub_Virtual24();
    virtual void sub_Virtual28();
    virtual void sub_Virtual2C();
    virtual void SetActive(int bActive);
};




void __fastcall CUNIT_DisableGoldButton(int nMode);                                                                    // 0x004898A0

D2ClientDialogStrc* __fastcall DIALOG_CreateDialogFromFile(int nX, int nY, int (__cdecl* pfnCallback)(), int nArg4, int nArg5, int nArg6); // 0x004B7CD0

void __fastcall ROSTER_SetCtrlState(void* pPanel, int nValue);                                                     // 0x004B8370

void __fastcall DIALOG_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nHeight, int nArg4, int nType, int nFont, int (__cdecl* pfnCallback)(), int bEnabled); // 0x004B85F0

void __fastcall DIALOG_AddWidget(void* pPanel, void* pControl, int nArg3, int nArg4);                // 0x004B7C00

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

int __cdecl UI_GoldPanelCloseCallback();                                                                                 // 0x00453FC0

int __cdecl UI_GoldSpinnerDefaultCallback();                                                                                 // 0x00453FD0

int __cdecl UI_GoldSpinnerChanged();                                                                                 // 0x00453FE0

int __cdecl UI_ConfirmGoldDialog();                                                                                 // 0x00454080

int __cdecl UI_CancelGoldDialog();                                                                                 // 0x00454140


D2ClientDialogStrc* gpGoldPanel;                                                                                    // 0x007A27A0

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)


extern "C" __declspec(dllimport) __declspec(noalias) int __stdcall GetWindowRect(void* hWindow, tagRECT* pRect);

extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex);

extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY);

int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30

void* __cdecl sub_004F59A0_GetWindow(); // 0x004F59A0


typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);



// 0x004525F0
int __fastcall UI_GetMonsterLifeFraction(D2UnitStrc* pUnit)
{
    if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == 1 && !CUNIT_IsDeadOrDying(pUnit))
    {
        int bPaired;
        if ((!pUnit ? 0 : (pUnit->dwFlags >> 2) & 1) && CUNIT_IsHostileTo(CUNIT_GetPlayerUnit(), pUnit))
        {
            bPaired = 1;
        }
        else
        {
            bPaired = 0;
        }

        const int nLife = ROSTER_GetPetLife(pUnit->dwUnitId);
        int nResult;
        if (!bPaired && nLife > 0)
        {
            nResult = D2_MIN(D2_MAX((nLife << 7) / 100, 2), 0x80);
        }
        else
        {
            const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (!nMaxLife)
            {
                nResult = 0x80;
            }
            else
            {
                const int nCurrentLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
                nResult = D2_MIN(D2_MAX((nCurrentLife << 7) / nMaxLife, 2), 0x80);
            }
        }
        return nResult;
    }
    return 0;
}

// 0x004526C0
static void UI_BuildImmunityText(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0x2C0 && pUnit->dwClassId <= 0x2C5)
    {
        return;
    }
    const Unicode* pNewLine = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pComma = D2LANG_GetStringFromTblIndex(0xF0C);
    unsigned short wszText[0x100];
    for (int i = 0; i < 0x100; i++)
        wszText[i] = 0;
    wszText[0] = 0;
    for (int n = 0; n < 6; n++)
    {
        if (STATLIST_UnitGetStatValue(pUnit, gaImmunityTexts[n].nStat, 0) >= 100)
        {
            unsigned short wszItem[0x100];
            for (int i = 0; i < 0x100; i++)
                wszItem[i] = 0;
            if (wszText[0])
            {
                sub_00526700((Unicode*)wszText, pComma);
                sub_00526700((Unicode*)wszText, pNewLine);
            }
            sub_005267E0((Unicode*)wszItem, D2LANG_GetStringFromTblIndex(gaImmunityTexts[n].wString));
            INV_PrefixColorCode((Unicode*)wszItem, gaImmunityTexts[n].nColor);
            sub_00526700((Unicode*)wszText, (Unicode*)wszItem);
        }
    }
    sub_005267E0(gwszHoverText, (Unicode*)wszText);
    gnHoverTextState = 4;
}

// 0x004527D0
void __fastcall UI_BuildItemHoverName(D2UnitStrc* pUnit, Unicode* pOut, int nMaxLength)
{
    gnHoverY -= 0x10;
    if (!pUnit)
        return;

    const Unicode* pName = CUNIT_GetUnitName(pUnit);
    int nColor = 0;
    switch (ITEMS_GetItemQuality(pUnit))
    {
    case ITEMQUAL_RARE:
        nColor = 9;
        break;
    case ITEMQUAL_CRAFT:
        nColor = 8;
        break;
    case ITEMQUAL_TEMPERED:
        nColor = 10;
        break;
    case ITEMQUAL_MAGIC:
        nColor = 3;
        break;
    case ITEMQUAL_SET:
        nColor = 2;
        break;
    case ITEMQUAL_UNIQUE:
        nColor = 4;
        break;
    default:
        if (ITEMS_CheckItemFlag(pUnit, 0x800, 0x5AA, gszUiCpp))
            nColor = 5;
        else if (ITEMS_CheckItemFlag(pUnit, 0x400000, 0x5AE, gszUiCpp))
            nColor = 5;
        break;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
    if (pItemsTxtRecord->nQuest && pItemsTxtRecord->dwCode != 0x2067656C)
        nColor = 4;

    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    if (dwCode == 0x20686563 || dwCode == 0x20746562 || dwCode == 0x20736574 || dwCode == 0x20646566
        || dwCode == 0x20616F74 || dwCode == 0x206E6864 || dwCode == 0x20796562 || dwCode == 0x2072626D
        || dwCode == 0x20316B70 || dwCode == 0x20326B70 || dwCode == 0x20336B70 || ITEMSIsA(pUnit, 0x4A))
        nColor = 8;

    Unicode wszText[0x80] = { 0 };
    if (ITEMS_GetItemType(pUnit) == ITEMTYPE_GOLD)
    {
        char szGold[10];
        const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
        Unicode wszGold[10];
        wsprintfA(szGold, gszFmtInt_006D6454, nGold);
        sub_00526F20(wszGold, szGold, 9);
        sub_005267E0(wszText, wszGold);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, pName);
        if (!pOut)
        {
            D2Win_10129_DrawFramedText(wszText, gnHoverX, gnHoverY, nColor, 1);
            return;
        }

        INV_PrefixColorCode(wszText, nColor);
        D2_ASSERT(UNICODE_StrLen(wszText) < nMaxLength, 0x5E0);
        sub_005267E0(pOut, wszText);
        return;
    }
    else if (pUnit)
    {
        Unicode wszItem[0x80] = { 0 };
        INV_BuildItemName(pUnit, (Unicode*)wszItem, 0x100);
        if (!pOut)
        {
            D2Win_10129_DrawFramedText((Unicode*)wszItem, gnHoverX, gnHoverY, nColor, 1);
            return;
        }

        INV_PrefixColorCode((Unicode*)wszItem, nColor);
        D2_ASSERT(UNICODE_StrLen((Unicode*)wszItem) < nMaxLength, 0x5EB);
        sub_005267E0(pOut, (Unicode*)wszItem);
    }
}

// 0x00452AF0
static void __stdcall UI_GetPlayerHoverName(D2UnitStrc* pUnit, Unicode* pDst, int nMaxLength, int* pValue, int* pFlag)
{
    const char* szName = sub_0047A210_GetPartyName(pUnit);
    if (pUnit && pUnit->dwAnimMode == 0x11)
    {
        *pValue = 0;
        unsigned short wszName[0x80];
        for (int i = 0; i < 0x80; i++)
            wszName[i] = 0;
        sub_00526F20_ToUnicode((Unicode*)wszName, szName, 0x80);
        sub_005272B0_FormatText(pDst, (Unicode*)wszName, D2LANG_GetStringFromTblIndex(0x90B), nMaxLength, STRTABLE_GetLanguage());
        *pFlag = 1;
        return;
    }
    *pValue = ROSTER_GetOtherPartyLife(!pUnit ? -1 : pUnit->dwUnitId) * 128 / 100;
    *pFlag = 0;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (ROSTER_IsHostileRelation(!pPlayer ? -1 : pPlayer->dwUnitId, nUnitId))
    {
        *pFlag = 1;
    }
    sub_00526F20_ToUnicode(pDst, szName, 0x80);
}

// 0x00452BE0
static void __stdcall UI_ShowUnitHoverName(D2UnitStrc* pUnit, int bSet)
{
    int nValues[2];
    if (NPCMENU_GetInteractNpcId(&nValues[0]))
    {
        return;
    }
    nValues[1] = UI_GetMonsterLifeFraction(pUnit);
    const int nY = gnHoverY - 0x48;
    const int nX = gnHoverX;
    const Unicode* pName = CUNIT_GetUnitName(pUnit);
    if (bSet)
    {
        gwszPopUpText[0].wChar = 0;
        if (pName)
        {
            sub_005267E0(gwszPopUpText, pName);
            gnPopUpTextY = nY;
            gnPopUpTextX = nX;
            gnPopUpTextMode = nValues[1];
        }
    }
    else
    {
        D2Win_10130_DrawFramedTextEx(pName, nX, nY, 0, 1, nValues[1]);
    }
}

// 0x00452C70
static int __stdcall UI_GetRosterHoverName(D2UnitStrc* pUnit, Unicode* pDst, int* pValue, int* pFlag)
{
    const int nIndex = ROSTERPETS_FindRosterIndex(!pUnit ? -1 : pUnit->dwUnitId);
    if (nIndex == -1)
    {
        return 0;
    }
    if (!pUnit || !pUnit->dwAnimMode || pUnit->dwAnimMode == 0x0C)
    {
        return 1;
    }
    const char* szName = sub_0047A1F0(nIndex);
    if (!szName)
    {
        return 0;
    }
    sub_00526320_ToUnicode(pDst, szName, 0x80);
    *pValue = ROSTER_GetOtherPartyLife(nIndex) * 128 / 100;
    *pFlag = 0;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (ROSTER_IsHostileRelation(!pPlayer ? -1 : pPlayer->dwUnitId, nIndex))
    {
        *pFlag = 1;
    }
    return 1;
}

// 0x00452D20
void __cdecl UI_DrawPetHover()
{
    if (UI_GetPanelSlideMode() == 3)
    {
        return;
    }
    const int nPetId = ROSTERPETS_FindPetIdByOwner(CUNIT_GetPlayerUnit(), 7, 0);
    if (nPetId == -1)
    {
        return;
    }
    if (ROSTERPETS_FindEntry(nPetId)->nValue != 1)
    {
        return;
    }
    D2UnitStrc* pPet = CUNIT_FindClientUnit(nPetId, 1);
    if (!pPet)
    {
        return;
    }
    if (!SetHoverPositionFromUnit(pPet))
    {
        return;
    }
    UI_ShowUnitHoverName(pPet, 1);
}

// 0x00452E50
void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect)
{
    int nWidth = pRect->nRight - pRect->nLeft;
    int nLeft = pRect->nLeft;
    int nRight = nLeft + nWidth + 1;
    int nHeight = pRect->nBottom - pRect->nTop;
    int nTop = pRect->nTop;
    int nBottom = nTop + nHeight + 1;
    D2GfxDataStrc context;
    int nPiece = 0;
    memset(&context, 0, sizeof(context));
    context.pCelFile = gpBoxPiecesCel;
    context.nDirection = 0;

    const int nRightCorner = nRight - 12;
    const int nHorizontalStart = nLeft + 12;
    for (int nX = nHorizontalStart; nX < nRightCorner - 1; nX += 12)
    {
        context.nFrame = ++nPiece % 6 + 2;
        sub_004F6480(&context, nX, nTop + 12, -1, 5, 0);
    }
    for (int nX = nHorizontalStart + 1; nX < nRightCorner - 1; nX += 12)
    {
        context.nFrame = ++nPiece % 6 + 16;
        sub_004F6480(&context, nX, nBottom + 10, -1, 5, 0);
    }
    const int nVerticalStart = nTop + 12;
    for (int nY = nVerticalStart + 10; nY < nBottom - 1; nY += 12)
    {
        context.nFrame = ++nPiece % 3 + 10;
        sub_004F6480(&context, nLeft - 4, nY, -1, 5, 0);
    }
    for (int nY = nVerticalStart + 12; nY < nBottom - 1; nY += 12)
    {
        context.nFrame = ++nPiece % 3 + 13;
        sub_004F6480(&context, nRight - 7, nY, -1, 5, 0);
    }
    context.nFrame = 0;
    sub_004F6480(&context, nLeft, nVerticalStart, -1, 5, 0);
    context.nFrame = 1;
    sub_004F6480(&context, nRightCorner, nVerticalStart, -1, 5, 0);
    context.nFrame = 8;
    sub_004F6480(&context, nLeft, nBottom + 1, -1, 5, 0);
    context.nFrame = 9;
    sub_004F6480(&context, nRightCorner, nBottom + 1, -1, 5, 0);
}

// 0x00453100
void __cdecl UI_DrawDeathScreen()
{
    char szPath[0x104];
    char szLanguage[4];
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (!pPlayer)
        return;

    if (CUNIT_IsDeadOrDying(pPlayer))
    {
        int nY = gnScreenHeight / 2 - 0x5E;
        STRTABLE_GetLanguageInfoField(szLanguage, 0);
        if (!gpYouDiedHardcoreCel)
        {
            sprintf(szPath, "%s\\UI\\%s\\youdiedhardcore", szDataLocal_006D41A8, szLanguage);
            gpYouDiedHardcoreCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
        if (gpYouDiedHardcoreCel)
            D2Win_10134_DrawCellFile(gpYouDiedHardcoreCel, gnScreenWidth / 2, nY, 1, 5, 1);

        nY += 0x30;
        gbDeathScreenShown = 1;
        if (!gpYouDiedInstCel)
        {
            sprintf(szPath, "%s\\UI\\%s\\youdiedinst", szDataLocal_006D41A8, szLanguage);
            gpYouDiedInstCel = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
        if (gpYouDiedInstCel)
            D2Win_10134_DrawCellFile(gpYouDiedInstCel, gnScreenWidth / 2, nY, 1, 5, 1);

        Unicode wszText[0x100];
        if (WINMAIN_IsHardcore())
        {
            sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x13E8));
        }
        else
        {
            if (!STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDLOST, 0))
                goto second_text;
            sub_005269D0_FormatText(0x100, wszText, D2LANG_GetStringFromTblIndex(0x13E6), STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDLOST, 0));
        }
        nY += 0x30;
        D2Win_10127_SetFont(2);
        {
            const int nWidth = D2Win_10121_GetTextWidth(wszText);
            const int nX = gnAutomapWidth / 2 - nWidth / 2;
            D2Win_10117_DrawText(wszText, nX, nY, 1, 1);
        }

second_text:
        if (GAME_GetDifficulty() > 0 && !WINMAIN_IsHardcore())
        {
            D2Win_10127_SetFont(2);
            const int nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0x13E7));
            const int nX = gnAutomapWidth / 2 - nWidth / 2;
            nY += 0x30;
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x13E7), nX, nY, 1, 1);
        }
    }
    else
    {
        gbDeathScreenShown = 0;
    }
}

// 0x00453330
void __fastcall UI_DrawPartyMemberText(D2UnitStrc* pUnit)
{
    const int nBorder = UI_GetPanelSlideMode();
    if (nBorder == 3)
    {
        return;
    }
    if (pUnit == CUNIT_GetPlayerUnit())
    {
        return;
    }
    D2RectStrc tView;
    sub_00476070_GetViewRect(gpClientView, &tView.nLeft, &tView.nTop, &tView.nRight, &tView.nBottom);
    int nOffsetX;
    int nOffsetY;
    VIEW_GetViewOffset(gpClientView, &nOffsetX, &nOffsetY);
    tagRECT tRect;
    SetRect(&tRect, nOffsetX, nOffsetY, tView.nRight - tView.nLeft + nOffsetX, tView.nBottom - tView.nTop + nOffsetY);
    D2CoordStrc tCoords;
    UNITS_GetClientCoords(pUnit, &tCoords);
    tCoords.nY = tCoords.nY - tRect.top - 0x46;
    tCoords.nX -= tRect.left;
    switch (nBorder)
    {
    case 1:
        tCoords.nX -= gnScreenWidth / 4;
        if (tCoords.nX > gnScreenWidth / 2)
        {
            return;
        }
        break;
    case 2:
        tCoords.nX += gnScreenWidth / 4;
        if (tCoords.nX < gnScreenWidth / 2)
        {
            return;
        }
        break;
    }
    if (tCoords.nY <= 0 || tCoords.nY >= gnScreenWidth || tCoords.nX <= -0x32 || tCoords.nX >= gnScreenHeight + 0x32)
    {
        return;
    }
    Unicode wszName[0x80];
    int nPercent;
    int bFlag;
    UI_GetPlayerHoverName(pUnit, wszName, 0x80, &nPercent, &bFlag);
}

struct D2StatListStrc;

struct D2StatesTxt;

extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId); // 0x00452040




extern unsigned int gdwBitMasks[]; // 0x006CE268

extern int gnProgressiveStatesBottomWide; // 0x007111CC

extern int gnProgressiveStatesRight; // 0x007111D0

extern int gnProgressiveStatesBottom; // 0x007111D4

extern void* gpGlobal_007A0634; // 0x007A0634

// 0x00453470
void __cdecl UI_DrawProgressiveStates()
{
    if (!gpGlobal_007A0634)
        return;
    if (!CUNIT_GetPlayerUnit2())
        return;
    if (!UNITS_GetRoom(CUNIT_GetPlayerUnit2()))
        return;
    if (!gbOverlaysEnabled)
        return;
    int nY = gnScreenHeight - gnProgressiveStatesBottom;
    int nX = gnScreenWidth - gnProgressiveStatesRight;
    if (D2GFX_GetResolutionMode() == 2)
        nY = gnScreenHeight - gnProgressiveStatesBottomWide;
    D2UnitStrc* pUnit = CUNIT_GetPlayerUnit2();
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        const int nState = sgptDataTables->pProgressiveStates[i];
        if (!STATES_CheckState(pUnit, nState))
            continue;
        if (!STATLIST_GetStatListFromUnitAndState(pUnit, nState))
            continue;
        D2StatesTxt* pStatesTxtRecord = GAME_GetStatesTxtRecord(nState);
        if (!pStatesTxtRecord)
            continue;
        if (!(pStatesTxtRecord->nStateFlags[0] & gdwBitMasks[4]))
            continue;
        if (pStatesTxtRecord->wPrgOverlay <= 0 || pStatesTxtRecord->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount)
            continue;
        if (pStatesTxtRecord->wStat < 0 || pStatesTxtRecord->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
            continue;
        const int nCharges = STATLIST_UnitGetStatValue(pUnit, pStatesTxtRecord->wStat, 0);
        if (nCharges < 1 || nCharges > 3)
            continue;
        GFX_DrawProgressiveStateOverlays(pUnit, pStatesTxtRecord->wPrgOverlay + nCharges - 1, nX, nY);
        nX -= gnOverlayStep;
    }
}

// 0x004535D0
void __cdecl UI_DrawPartyTexts()
{
    if (GAME_GetConnectionType())
    {
        CUNIT_ForEachPlayer(UI_DrawPartyMemberText);
    }
}

// 0x004535F0
static inline void __stdcall UI_SetSlotClass(D2SlotOwnerStrc* pOwner, unsigned short wDefault, int nIndex, int nA, int nB)
{
    if (nIndex == -1)
    {
        return;
    }

    int nValue;
    unsigned short wClass;
    if (CUNIT_HasHotkeyBinding(nA, nB) && (wClass = CUNIT_GetHotkeyBinding(nA, nB)) != 0xFFFF && wClass <= 0xDF)
    {
        nValue = wClass;
    }
    else
    {
        nValue = wDefault;
    }

    pOwner->pSlots[nIndex].nClass = nValue;
}

static inline void SetHotkey(const D2PanelHotkeysStrc* pDesc, int nIndex, int nKeyFunc, int bSecondary, int nDefault)
{
    if (nIndex == -1)
        return;

    if (CUNIT_HasHotkeyBinding(nKeyFunc, bSecondary))
    {
        const unsigned short nKey = CUNIT_GetHotkeyBinding(nKeyFunc, bSecondary);
        if (nKey != 0xFFFF && nKey <= 0xDF)
        {
            pDesc->f_20[nIndex].nId = nKey;
            return;
        }
    }

    pDesc->f_20[nIndex].nId = nDefault;
}

// 0x00453640
static void UI_SetPanelHotkeys(const D2PanelHotkeysStrc* pDesc)
{
    SetHotkey(pDesc, pDesc->nIndex16Sec, 0x16, 0x1, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26Sec, 0x26, 0x1, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29Sec, 0x29, 0x1, 0x4E);
    if (FOG_IsExpansion())
        SetHotkey(pDesc, pDesc->nIndex2CSec, 0x2C, 0x1, 0x57);
    SetHotkey(pDesc, pDesc->nIndex16, 0x16, 0x0, 0xC0);
    SetHotkey(pDesc, pDesc->nIndex26, 0x26, 0x0, 0x1B);
    SetHotkey(pDesc, pDesc->nIndex29, 0x29, 0x0, 0x4E);
    if (FOG_IsExpansion())
        SetHotkey(pDesc, pDesc->nIndex2C, 0x2C, 0x0, 0x57);
}

void __fastcall sub_M117_Emit_004535F0(D2SlotOwnerStrc* pOwner, int nIndex, int nA, int nB)
{
    UI_SetSlotClass(pOwner, 0x1234, nIndex, nA, nB);
}

// 0x00453900
int __cdecl UI_IsDialogOpen()
{
    return DIALOG_GetDialogCount() != 0;
}

// 0x00453910
static int UI_CanSetUIVar(int nUIVar, int nState)
{
    D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
    if (nState == 0 || (nState == 2 && !gaUIVarStates[nUIVar]))
    {
        if (nUIVar == 0x05 || nUIVar == 0x09)
        {
            if (DIALOG_GetDialogCount() && nUIVar == 0x05 && !gaUIVarStates[0x18])
            {
                return 0;
            }
            if (gdwUIVarTick > GetTickCount())
            {
                return 0;
            }
            if (nUIVar == 0x09)
            {
                D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
                if (!pPlayer)
                {
                    return 0;
                }
                if (pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->dwAnimMode == 0x11)
                {
                    CUNIT_UpdateAttackableFlag(pPlayer);
                    MSG_SendHeaderOnly(0x41);
                    if (WINMAIN_IsHardcore())
                    {
                        sub_00477EE0();
                        gbPositionalSound = 0;
                        gbGameServerReady = 0;
                        WINMAIN_SetCharDiedFlag();
                        WINMAIN_SetExitApplication(0);
                        GAME_RequestExit();
                    }
                    return 0;
                }
            }
        }
        if (TEXT_IsTextBoxOpen() && nUIVar != 0x0A && nUIVar != 0x13 && nUIVar != 0x11 && nUIVar != 0x06 && nUIVar != 0x07)
        {
            return 0;
        }
        for (int i = 0; i < gnUIVarCount; i++)
        {
            if (gaUIVarStates[i] == 1)
            {
                switch (gapUIVarRecords[i]->anCloseKind[nUIVar])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (NPCMENU_GetInteractNpcId(&nLow))
                    {
                        NPCMENU_EndNpcInteraction(nLow);
                    }
                    break;
                }
                case 1:
                    UI_SetUIVar(i, 1, 0);
                    break;
                case 2:
                    return 0;
                default:
                    D2_ASSERT(nUIVar, 0x13E6);
                    return 0;
                }
            }
        }
    }
    return 1;
}

// 0x00453A90
int __fastcall UI_GetUIVarUnchecked(int nUIVar)
{
    return gaUIVarStates[nUIVar];
}

// 0x00453AA0
int __cdecl UI_GetPentspinCel()
{
    return gdwGlobal_007A2878;
}

// 0x00453AB0
int __cdecl UI_GetFocusCel()
{
    return gdwGlobal_007A2880;
}

// 0x00453AC0
void __cdecl UI_DisableUIVarDelay()
{
    gbUIVarDelayEnabled = 0;
    gdwUIVarTick = 0;
}

static inline int IsGoldPanelMode(int nMode)
{
    if (nMode <= 0)
    {
        return 0;
    }

    if (nMode > 4)
    {
        return 0;
    }

    return 1;
}

// 0x00453AD0
void __cdecl UI_EnableUIVarDelay()
{
    gbUIVarDelayEnabled = 1;
}

// 0x00453AE0
void __cdecl UI_StartUIVarDelay()
{
    if (gbUIVarDelayEnabled)
    {
        gdwUIVarTick = GetTickCount() + 0x64;
    }
}

// 0x00453B00
void __cdecl UI_SendMouseMove()
{
    SendMessageA(WINDOW_GetWindow(), 0x200, 0, ((unsigned short)sub_00468740() << 16) | (unsigned short)sub_00468730());
}

// 0x00453B30
void __cdecl UI_DrawStoredUnitNumber()
{
    if (!CHAT_IsNumberDisplayEnabled())
    {
        return;
    }

    D2UnitStrc* pUnit = CUNIT_GetPlayerUnit2();
    if (!pUnit)
    {
        return;
    }

    D2StoredUnitRecordStrc* pRecord = ROSTER_FindRosterUnitById(pUnit->dwUnitId);
    if (!pRecord)
    {
        return;
    }

    const int nValue = ROSTER_GetKillCount(pRecord);
    char szText[12];
    Unicode wszText[12];
    wsprintfA(szText, gszFormatD, nValue);
    sub_00526F20_ToUnicode(wszText, szText, 12);
    D2Win_10117_DrawText(wszText, 600, 25, 4, 0);
}

// 0x00453D90
void __cdecl UI_LoadPlayerUI()
{
    PANEL_LoadPartyCels();
    TEXT_InitTextEntryLengths();
    sub_004AA920_LoadPanelCel();
    SPELLSEL_InitSkillIcons();
    MONSTER_ResetTradeState();
    INV_ResetHover();
    PANEL_ClearPair();
    INV_FreeHoradricCel();
    QUESTLOG_ResetQuestPages();
    TEXT_LoadPopupHireling();
    AUTOMAP_ResetBaseOffset(1);
    ESCMENU_LoadAlwaysRun();
}

// 0x00453DE0
void __cdecl UI_FreePlayerUI()
{
    PANEL_FreePartyCels();
    sub_004A7AD0_Nop();
    sub_004AA980_FreePanelCel();
    SPELLSEL_FreeSkillIcons();
    TEXT_ClearQuestFlags();
    NPCMENU_ResetNpcMenu();
    sub_004B91F0_CloseWait();
    TEXT_FreeTextLists();
    VIEW_ResetLifeColors();
    if (gpLoadingCell)
    {
        ARCHIVE_FreeClientCellFile(gpLoadingCell);
        gpLoadingCell = 0;
    }
    if (gpYouDiedHardcoreCel)
    {
        ARCHIVE_FreeClientCellFile(gpYouDiedHardcoreCel);
        gpYouDiedHardcoreCel = 0;
    }
    if (gpYouDiedInstCel)
    {
        ARCHIVE_FreeClientCellFile(gpYouDiedInstCel);
        gpYouDiedInstCel = 0;
    }
    ESCMENU_SaveAlwaysRun();
    CURSOR_SetCursorItemState(0);
}

// 0x00453E70
const Unicode* __fastcall UI_GetLevelName(int nLevelId)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (pLevelsTxtRecord)
    {
        if (nLevelId == LEVEL_DENOFEVIL)
        {
            if (INV_GetTableByte(0, 1))
            {
                return D2LANG_GetStringFromTblIndex(0x13B8);
            }
            return D2LANG_GetStringFromTblIndex(0x13B7);
        }
        return (const Unicode*)pLevelsTxtRecord->wszLevelName;
    }
    return D2LANG_GetStringFromTblIndex(0x150D);
}

// 0x00453EC0
void __cdecl UI_CancelCursorItemUse()
{
    D2UnitStrc* pUnit = (D2UnitStrc*)CURSOR_GetCursorItem();
    if (pUnit)
    {
        MSG_SendTwoDwords(0x27, pUnit->dwUnitId, pUnit->dwUnitId);
    }
}

// 0x00453EE0
void __cdecl UI_CloseGoldDialog()
{
    if (gbGoldPanelFlag)
    {
        CMDTBL_SetHotkeyHandlers(1, 1);
        gbGoldPanelFlag = 0;
    }

    if (gpGoldControlB)
    {
        gnGoldPanelValue = gpGoldControlB->GetValue();
    }

    if (gpGoldPanel)
    {
        DIALOG_DestroyDialog(gpGoldPanel);
        gpGoldPanel = 0;
    }

    if (gpGoldControlA)
    {
        delete gpGoldControlA;
        gpGoldControlA = 0;
    }

    if (gpGoldControlB)
    {
        delete gpGoldControlB;
        gpGoldControlB = 0;
    }

    if (gpGoldControlC)
    {
        delete gpGoldControlC;
        gpGoldControlC = 0;
    }

    if (gpGoldControlD)
    {
        delete gpGoldControlD;
        gpGoldControlD = 0;
    }

    if (gnGoldPanelMode != 0)
    {
        if (IsGoldPanelMode(gnGoldPanelMode))
        {
            INV_ReturnToStashState();
        }
    }
    else
    {
        INV_ClearGoldDialogFlag();
    }
}

// 0x00453FC0
int __cdecl UI_GoldPanelCloseCallback()
{
    UI_CloseGoldDialog();
    return 0;
}

// 0x00453FD0
int __cdecl UI_GoldSpinnerDefaultCallback()
{
    return 0;
}

// 0x00453FE0
int __cdecl UI_GoldSpinnerChanged()
{
    const int nDirection = gpGoldControlA->GetDirection();
    const unsigned int nStep = gpGoldControlA->GetStep(0);
    if (gpGoldControlB)
    {
        gnGoldPanelValue = gpGoldControlB->GetValue();
    }
    unsigned int nValue = gnGoldPanelValue;
    unsigned int nMax;
    if (gnGoldPanelMode == 4)
    {
        nMax = STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLDBANK, 0);
    }
    else
    {
        nMax = STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLD, 0);
    }
    if (nDirection == 1)
    {
        nValue += nStep;
        if (nValue > nMax)
        {
            nValue = nMax;
        }
    }
    else if (nDirection == 2)
    {
        if (nStep > nValue)
        {
            nValue = 0;
        }
        else if (nValue)
        {
            nValue -= nStep;
        }
    }
    gnGoldPanelValue = nValue;
    if (gpGoldControlB)
    {
        gpGoldControlB->SetValue(nValue);
    }
    return 0;
}

static inline int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// 0x00454080
int __cdecl UI_ConfirmGoldDialog()
{
    UI_CloseGoldDialog();
    if (!gnGoldPanelValue)
    {
        if (gnGoldPanelMode == 2)
            MONSTER_SendGoldRequest(gnGoldPanelValue);
        return 1;
    }
    switch (gnGoldPanelMode)
    {
    case 0:
    case 1:
    {
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        int nId = GetUnitId(pPlayer);
        MSG_SendTwoDwords(0x50, nId, gnGoldPanelValue);
        return 1;
    }
    case 2:
        MONSTER_SendGoldRequest(gnGoldPanelValue);
        break;
    case 4:
        MSG_SendShorts(0x4F, 0x13, gwDialogAmountHigh, gnGoldPanelValue);
        break;
    case 3:
        MSG_SendShorts(0x4F, 0x14, gwDialogAmountHigh, gnGoldPanelValue);
        break;
    default:
        return 1;
    }
    sub_004B9A00(0xDD, 0, 0, 0, 0);
    return 1;
}

// 0x00454140
int __cdecl UI_CancelGoldDialog()
{
    UI_CloseGoldDialog();
    return 1;
}

// 0x00454150
void __fastcall UI_OpenGoldPanel(int nMode)
{
    if (!CUNIT_GetPlayerUnit())
    {
        UI_CloseGoldDialog();
        return;
    }
    if (INVENTORY_GetCursorItem(CUNIT_GetPlayerUnit()->pInventory))
    {
        UI_CloseGoldDialog();
        return;
    }
    if (gpGoldPanel)
    {
        return;
    }
    if (!gbGoldPanelFlag)
    {
        CMDTBL_SetHotkeyHandlers(0, 1);
        gbGoldPanelFlag = 1;
    }
    gnGoldPanelValue = 0;

    int nStringId;
    int nGold;
    switch (nMode)
    {
    case 0:
        TEXT_SetGoldDialogFlag();
        nStringId = 0xFC1;
        nGold = STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 1:
        nStringId = 0xFC1;
        CUNIT_DisableGoldButton(1);
        nGold = STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 2:
        nStringId = 0xFCE;
        CUNIT_DisableGoldButton(2);
        nGold = STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 3:
        nStringId = 0xFD1;
        CUNIT_DisableGoldButton(3);
        nGold = STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLD, 0);
        break;
    case 4:
        nStringId = 0xFD2;
        CUNIT_DisableGoldButton(4);
        nGold = STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLDBANK, 0);
        break;
    default:
        UI_CloseGoldDialog();
        return;
    }

    gnGoldPanelMode = nMode;
    gpGoldPanel = DIALOG_CreateDialogFromFile(0xD7, 0x8C, UI_GoldPanelCloseCallback, 0, 0, 1);
    ROSTER_SetCtrlState(gpGoldPanel, 1);
    D2Win_10127_SetFont(1);

    Unicode wszText[0x100];
    memset(wszText, 0, sizeof(wszText));
    if (nMode == 5)
    {
        sub_005269D0_FormatText(0x100, wszText, D2LANG_GetStringFromTblIndex(nStringId), STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLDBANK, 0) + STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_GOLD, 0));
    }
    else
    {
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringId));
    }

    int nLineCount;
    D2SplittedTextStrc* pLine = D2WINFONT_SplitText(wszText, &nLineCount, 0xC8);
    while (pLine)
    {
        DIALOG_AddTextLine(gpGoldPanel, pLine->wszLine, 0x18, 0, 4, 1, 0, 0);
        D2SplittedTextStrc* pNext = pLine->pNextLine;
        FOG_Free(pLine->wszLine, ".\\UI\\ui.cpp", 0x1827, 0);
        FOG_Free(pLine, ".\\UI\\ui.cpp", 0x1828, 0);
        pLine = pNext;
    }

    gpGoldControlA = new D2UiControlAStrc(0xDF, 0xDB, 0, UI_GoldSpinnerChanged);
    DIALOG_AddWidget(gpGoldPanel, gpGoldControlA, 0, 0);
    gpGoldControlB = new D2UiControlBStrc(0x102, 0xE4, 0x64, 1, nGold, 0xA, UI_GoldSpinnerDefaultCallback, 1);
    DIALOG_AddWidget(gpGoldPanel, gpGoldControlB, 0, 0);
    if (gpGoldControlB)
    {
        gpGoldControlB->SetActive(1);
    }
    gpGoldControlC = new D2UiControlCStrc(0xFA, 0x11F, 0, UI_ConfirmGoldDialog);
    DIALOG_AddWidget(gpGoldPanel, gpGoldControlC, 0, 0);
    gpGoldControlC->SetActive(1);
    gpGoldControlD = new D2UiControlCStrc(0x163, 0x11F, 1, UI_CancelGoldDialog);
    DIALOG_AddWidget(gpGoldPanel, gpGoldControlD, 0, 0);

    if (nMode == 2)
    {
        sub_004B90B0_SendState();
        return;
    }
    if (nMode == 3 || nMode == 7 || nMode == 6)
    {
        if (gpGoldControlB)
        {
            gpGoldControlB->SetValue(nGold);
        }
    }
}

// 0x00454570
void __cdecl UI_ClearGoldPanel()
{
    gpGoldPanel = 0;
    gpGoldControlA = 0;
    gpGoldControlB = 0;
    gpGoldControlD = 0;
    gpGoldControlC = 0;
    gbGoldPanelFlag = 0;
}

// 0x004545A0
void __cdecl UI_CloseGoldPanel()
{
    UI_CloseGoldDialog();
}

// 0x004545B0
void __cdecl UI_DrawGoldPanel()
{
    if (gpGoldPanel)
        DIALOG_DrawDialog(gpGoldPanel);
}

// 0x004545C0
void __fastcall UI_TogglePanelHandlers(int bRegister)
{
    if (bRegister)
    {
        if (gaUIVarStates[UIVAR_PANEL])
        {
            SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaAutomapHandlers, 5);
        }
    }
    else
    {
        if (gaUIVarStates[UIVAR_PANEL])
        {
            sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaAutomapHandlers, 5);
        }
    }
}

// 0x00454650
void* __fastcall UI_ReadWholeFile(const char* szName, unsigned long* pSize)
{
    unsigned long nRead;
    char szPath[0x104];
    strcpy(szPath, szName);
    strcat(szPath, D2CMPGetGfxFileExtension(0));
    void* hFile = CreateFileA(szName, 0x80000000, 0, 0, 3, 0x80, 0);
    if (hFile == (void*)-1)
    {
        return 0;
    }

    *pSize = GetFileSize(hFile, 0);
    void* pBuffer = FOG_Alloc(*pSize, ".\\UI\\ui.cpp", 0x18AD, 0);
    memset(pBuffer, 0, *pSize);
    ReadFile(hFile, pBuffer, *pSize, &nRead, 0);
    CloseHandle(hFile);
    return pBuffer;
}

// 0x00454790
void __fastcall UI_SetLoadingAct(int nValue)
{
    gnLoadingAct = nValue;
}

// 0x004547A0
int __cdecl UI_GetLoadingAct()
{
    return gnLoadingAct;
}

// 0x004547B0
void __fastcall UI_FreeLoadingScreen()
{
    if (gpLoadingScreen)
    {
        ARCHIVE_FreeClientCellFile(gpLoadingScreen);
        gpLoadingScreen = 0;
        sub_004FB480_SetActA(gnLoadingAct);
        D2CMPPalShiftSetAct(gnLoadingAct);
        AUTOMAP_InitAutomapColors();
        INV_InitColorTable();
        PANEL_SetRedColour();
        PANEL_SetBlackColour();
        sub_004AB2F0();
        VIEW_InitTextColorRed();
        HIREABLES_InitTextColorA();
        VIEW_InitBeltColors();
        HIREABLES_InitTextColorB();
        sub_00472890(gnTownLevelId);
        GAME_ExtendDelay(0x7D0);
    }
    gdwGlobal_007A2884 = 0;
    gpLoadingScreen = 0;
    gbLoadingScreenActive = 0;
}

// 0x00454840
int __cdecl UI_IsLoadingScreenActive()
{
    return gbLoadingScreenActive;
}

// 0x00454850
int __cdecl UI_TickElapsed()
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwUILastTick > 0x32)
    {
        gdwUILastTick = dwTick;
        return 1;
    }
    return 0;
}

// 0x00454880
int __fastcall UI_GetHoverRect(D2RectStrc* pRect)
{
    pRect->nLeft = 0;
    pRect->nRight = gnScreenWidth;
    pRect->nTop = 0;
    pRect->nBottom = gnScreenWidth;
    if (gaUIVarStates[0x17] || gaUIVarStates[0x19] || gaUIVarStates[0x1A]
        || gaUIVarStates[0x0C] || gaUIVarStates[0x1C] || gaUIVarStates[0x1B])
    {
        return 0;
    }
    if (gaUIVarStates[0x1D] || gaUIVarStates[0x16] || gaUIVarStates[0x02]
        || gaUIVarStates[0x0F] || gaUIVarStates[0x24] || gaUIVarStates[0x25]
        || gaUIVarStates[0x14])
    {
        pRect->nLeft = gnScreenWidth / 2;
    }
    if (gaUIVarStates[0x01] || gaUIVarStates[0x04])
    {
        pRect->nRight = gnScreenWidth / 2;
    }
    return pRect->nLeft != pRect->nRight;
}

// 0x00454980
void __cdecl UI_RegisterKeyConfigHandlers()
{
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyConfigHandlers, 13);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyConfigWheelHandlers, 1);
}

// 0x004549B0
void __cdecl UI_ToggleListDialog()
{
    TEXT_ToggleListDialogUI();
    NPCMENU_CloseTrade();
}

// 0x004549C0
int __cdecl UI_IsGoldPanelOpen()
{
    return gpGoldPanel != 0;
}

// 0x004549D0
D2Block0xA0Strc* __fastcall UI_ClearTextBlock(D2Block0xA0Strc* pBlock)
{
    for (int i = 0; i < 0x50; ++i)
        pBlock->wData[i] = 0;
    return pBlock;
}

static __forceinline int SetHoverPositionFromUnit(D2UnitStrc* pUnit)
{
    if (sub_004F51D0_IsPerspective())
    {
        const int nPrecisionX = UNITS_GetPrecisionX(pUnit);
        const int nPrecisionY = UNITS_GetPrecisionY(pUnit);
        if (!SCALE_CheckPerspectivePosition(nPrecisionX, nPrecisionY))
        {
            return 0;
        }
        int nX;
        int nY;
        SCALE_AdjustPerspectivePosition(nPrecisionX, nPrecisionY, 0, &nX, &nY);
        switch (UI_GetPanelSlideMode())
        {
        case 1:
            nX -= gnScreenWidth / 4;
            break;
        case 2:
            nX += gnScreenWidth / 4;
            break;
        }
        gnHoverX = nX;
        gnHoverY = nY + 0x10;
    }
    else
    {
        gnHoverX = UNITS_GetClientCoordX(pUnit) - PLAYER_GetScreenOffsetX();
        gnHoverY = UNITS_GetClientCoordY(pUnit) - PLAYER_GetScreenOffsetY();
    }
    return 1;
}

int gnHoverTextColor; // 0x007A2F30

void __cdecl AUTOMAP_InitAutomap(); // 0x0045A4C0

void __cdecl CMDTBL_EnableHotkeyHandlers(); // 0x0046AC70

void __cdecl ESCMENU_LoadOptionMenus(); // 0x0047DD70

void __cdecl MINIPANEL_LoadMiniPanel(); // 0x0047F0C0

void __cdecl INV_LoadInvPanelCels(); // 0x004868B0

void __cdecl INV_LoadShopPanelCels(); // 0x00489220

void __cdecl HIREABLES_LoadHirelingIcons(); // 0x00492C20

void __cdecl INV_LoadPanelCels(); // 0x004967F0

void __cdecl TEXT_InitWaypointData(); // 0x0049C6A0

void __cdecl TEXT_LoadTextSettings(); // 0x0049D440








// 0x004549F0
static void __stdcall UI_DrawHoverCenteredText(const Unicode* wszText, int nFont, int nY, int nColor)
{
    Unicode wszBuffer[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        wszBuffer[i].wChar = 0;
    }
    D2RectStrc tRect;
    if (!UI_GetHoverRect(&tRect) || !wszText)
    {
        return;
    }
    const int nOldFont = D2Win_10127_SetFont(nFont);
    sub_005267E0(wszBuffer, wszText);
    const int nWidth = D2Win_10121_GetTextWidth(wszBuffer);
    const int nX = ((tRect.nLeft + tRect.nRight) >> 1) - (nWidth >> 1);
    D2Win_10117_DrawText(wszBuffer, nX, nY, nColor, 1);
    D2Win_10127_SetFont(nOldFont);
}

// 0x00454A70
void __cdecl UI_DrawHoverText()
{
    D2UnitStrc* pUnit = SELECT_GetSelectedUnit();
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }
    int nY = D2Win_10125() + 0x27;
    UI_DrawHoverCenteredText(gwszHoverLine, 6, nY, gnHoverTextColor);
    if (gwszHoverLine[0].wChar || gwszHoverName[0].wChar)
    {
        nY += D2Win_10125();
    }
    UI_DrawHoverCenteredText(gwszHoverText, 6, nY, gnHoverTextState);
}

// 0x00454F30
void __fastcall UI_DrawUnitHover(D2UnitStrc* pUnit)
{
    if (UI_GetPanelSlideMode() == 3)
    {
        return;
    }
    if (!pUnit)
    {
        return;
    }
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 5 && DRLG_UnitEdgeDistance(pUnit, CUNIT_GetPlayerUnit()) > 100)
    {
        return;
    }
    if (!SetHoverPositionFromUnit(pUnit))
    {
        return;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    {
        Unicode wszName[0x80];
        int nPercent;
        int bFlag;
        UI_GetPlayerHoverName(pUnit, wszName, 0x80, &nPercent, &bFlag);
        D2Win_10130_DrawFramedTextEx(wszName, gnHoverX, gnHoverY - 0x48, bFlag, 1, nPercent);
        return;
    }
    case UNIT_ITEM:
        if (gaUIVarStates[13])
        {
            return;
        }
        UI_BuildItemHoverName(pUnit, 0, 0);
        return;
    case UNIT_MONSTER:
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId != 0x1A1 && nClassId != 0x1A2)
        {
            if (!sub_00451F30_TestUnitFlag(pUnit, 0x200))
            {
                if (nClassId == 0x164)
                {
                    int bFlag = 3;
                    Unicode wszName[0x80];
                    int nPercent = 0;
                    if (UI_GetRosterHoverName(pUnit, wszName, &nPercent, &bFlag))
                    {
                        if (bFlag == 3)
                        {
                            return;
                        }
                        D2Win_10130_DrawFramedTextEx(wszName, gnHoverX, gnHoverY - 0x48, bFlag, 1, nPercent);
                        return;
                    }
                }
                UI_DrawUnitHoverName(pUnit);
                return;
            }
            UI_ShowUnitHoverName(pUnit, 0);
        }
        else
        {
            D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pRecord)
            {
                MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(pRecord->wNameStr));
                UI_ShowUnitHoverName(pUnit, 0);
            }
        }
        gwszHoverLine[0].wChar = 0;
        gwszHoverText[0] = 0;
        gwszHoverName[0].wChar = 0;
        return;
    }
    case UNIT_OBJECT:
    {
        Unicode wszUnused[0x80];
        Unicode wszLine[0x100];
        Unicode wszText[0x80] = { 0 };
        int nLow;
        if (NPCMENU_GetInteractNpcId(&nLow))
        {
            return;
        }
        if (TEXT_IsTextBoxOpen() == 1)
        {
            return;
        }
        const Unicode* pName = CUNIT_GetUnitName(pUnit);
        const int nClassId = pUnit->dwClassId;
        const int nOffset = UNITS_GetNameOffsetFromObject(pUnit);
        const unsigned char nFlags = DATATBLS_GetObjectsTxtRecord((unsigned short)nClassId)->nSubClass;
        if (nFlags & 4)
        {
            Unicode wszOwner[0x80];
            sub_005267E0(wszText, UI_GetLevelName(pUnit->pObjectData->InteractType));
            if (gnGameType != 0 && gnGameType != 1)
            {
                char szOwner[0x80];
                const char* szName = ROSTER_GetPortalOwnerName(pUnit->dwUnitId);
                if (szName)
                {
                    sprintf(szOwner, " (%s) ", szName);
                    sub_00526F20_ToUnicode(wszOwner, szOwner, 0x80);
                    sub_00526700(wszText, wszOwner);
                }
                else if (strlen(sub_004BDFD0_GetObjectText(pUnit)))
                {
                    sprintf(szOwner, " (%s) ", sub_004BDFD0_GetObjectText(pUnit));
                    sub_00526F20_ToUnicode(wszOwner, szOwner, 0x80);
                    sub_00526700(wszText, wszOwner);
                }
            }
            D2Win_10129_DrawFramedText(wszText, gnHoverX, gnHoverY + nOffset, 0, 1);
            return;
        }
        if (nFlags & 0x80)
        {
            return;
        }
        if (nFlags & 0x40)
        {
            const Unicode* pObjectName = CUNIT_GetUnitName(pUnit);
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom)
            {
                return;
            }
            D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
            sub_005267E0(wszLine, pObjectName);
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9B));
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszLine, D2LANG_GetStringByReferenceString(pLevelsTxt->szLevelName));
            D2Win_10129_DrawFramedText(wszLine, gnHoverX, gnHoverY + nOffset, 0, 1);
            return;
        }
        D2Win_10129_DrawFramedText(pName, gnHoverX, gnHoverY + nOffset, 0, 1);
        return;
    }
    case UNIT_TILE:
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nClassId = pUnit->dwClassId;
        const int nLevelId = DUNGEON_GetWarpDestinationLevel(pRoom, nClassId);
        D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(nLevelId);
        if (!pLevelsTxt)
        {
            return;
        }
        D2TileRectStrc* pRect = DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit(pRoom, pUnit);
        if (!pRect)
        {
            return;
        }
        const int nX = (pRect->nWidth >> 1) + pRect->nX + gnHoverX;
        const int nY = (pRect->nHeight >> 1) + pRect->nY + gnHoverY;
        Unicode wszText[0xC8] = { 0 };
        const Unicode* pText = (const Unicode*)pLevelsTxt->wszLevelWarp;
        if (nLevelId == LEVEL_DENOFEVIL)
        {
            if (INV_GetTableByte(0, 1))
            {
                pText = D2LANG_GetStringFromTblIndex(0x13DE);
            }
            else
            {
                pText = D2LANG_GetStringFromTblIndex(0x13DD);
            }
        }
        sub_00526790(wszText, pText, 0xC7);
        D2Win_10129_DrawFramedText(wszText, nX, nY, 0, 1);
        return;
    }
    }
}

// 0x004554B0
void __cdecl UI_DrawHoverName()
{
    if (!UNICODE_StrLen(gwszHoverName))
    {
        return;
    }
    D2UnitStrc* pUnit = SELECT_GetSelectedUnit();
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return;
    }
    int nColor = 0;
    if (MONSTER_IsUniqueMonster(pUnit))
    {
        nColor = 4;
    }
    if (MONSTER_IsChampionMonster(pUnit))
    {
        nColor = 3;
    }
    const int nY = D2Win_10125() + 0x27;
    UI_DrawHoverCenteredText(gwszHoverName, 6, nY, nColor);
}

// 0x00455720
void __fastcall UI_SetPanelHandlers(int nPanel)
{
    switch (nPanel)
    {
    case 0xA:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaAutomapHandlers, 0x5);
        gnPanelFlag = 0x1;
        return;
    case 0x0:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaGameUIHandlers, 0x4);
        return;
    case 0x3:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaMiniSkillHandlers, 0x1);
        return;
    case 0x4:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaSkillTreeHandlers, 0x2);
        return;
    case 0x2:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaStatScreenHandlers, 0x2);
        return;
    case 0x1:
        INV_ResetNpcState();
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaInventoryHandlers, 0x4);
        return;
    case 0x5:
        CHAT_InitChatIme();
        CMDTBL_SetHotkeyHandlers(0, 0x1);
        if (gaUIVarStates[UIVAR_PANEL])
            sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaAutomapHandlers, 0x5);
        sub_0047B4D0_Nop();
        return;
    case 0x6:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaNewStatsHandlers, 0x2);
        return;
    case 0x13:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaPetIconHandlers, 0x1);
        return;
    case 0x7:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaNewSkillsHandlers, 0x2);
        return;
    case 0x9:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaEscMenuHandlers, 0x7);
        SELECT_RefreshHoverUnit(0);
        return;
    case 0xB:
        TEXT_ToggleKeyConfigPanel(0x1);
        UI_RegisterKeyConfigHandlers();
        return;
    case 0xC:
        CMDTBL_SetHotkeyHandlers(0x2, 0x1);
        TEXT_ResetNpcPanel();
        UI_SetPanelHotkeys(&gtNpcShopHotkeys);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaNpcShopHandlers, 0x8);
        return;
    case 0xF:
        UI_SetPanelHotkeys(&gtQuestScreenHotkeys);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaQuestScreenHandlers, 0x7);
        return;
    case 0x11:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaQuestLogHandlers, 0x4);
        return;
    case 0x10:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaIniScrollHandlers, 0x2);
        return;
    case 0x14:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaWaypointHandlers, 0x5);
        return;
    case 0x15:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaMiniPanelHandlers, 0x2);
        return;
    case 0x16:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaPartyScreenHandlers, 0x2);
        PARTY_RebuildRosterUnits();
        return;
    case 0x17:
        CMDTBL_SetHotkeyHandlers(0, 0x1);
        MONSTER_ClearTradeGold();
        INV_ClearPanelPage();
        UI_SetPanelHotkeys(&gtMpTradeHotkeys);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaMpTradeHandlers, 0xD);
        return;
    case 0x19:
        CMDTBL_SetHotkeyHandlers(0x2, 0x1);
        INV_LoadStashPanelCels();
        UI_SetPanelHotkeys(&gtStashHotkeys);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaStashHandlers, 0x8);
        return;
    case 0x1A:
        CMDTBL_SetHotkeyHandlers(0x2, 0x1);
        INV_LoadCubePanelCel();
        UI_SetPanelHotkeys(&gtCubeHotkeys);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaCubeHandlers, 0x7);
        return;
    case 0x18:
        TEXT_OpenMessageLogDialog();
        return;
    case 0x1F:
        UI_SetPanelHotkeys(&gtBeltRowsHotkeys);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaBeltRowsHandlers, 0x2);
        return;
    case 0x21:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHelpScreenHandlers, 0x5);
        return;
    case 0x22:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHelpButtonHandlers, 0x2);
        return;
    case 0x23:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHireIconHandlers, 0x3);
        return;
    case 0x24:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaMercInvHandlers, 0x3);
        return;
    case 0x25:
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaRecipeScrollHandlers, 0x2);
        return;
    }
}

// 0x00455AE0
void __fastcall UI_ClearPanelHandlers(int nPanel)
{
    switch (nPanel)
    {
    case 0xA:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaAutomapHandlers, 0x5);
        gnPanelFlag = 0x0;
        return;
    case 0x0:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaGameUIHandlers, 0x4);
        return;
    case 0x3:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMiniSkillHandlers, 0x1);
        return;
    case 0x4:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaSkillTreeHandlers, 0x2);
        UI_StartUIVarDelay();
        sub_004ABF10_ClearSkillStates();
        return;
    case 0x2:
        UI_CloseGoldDialog();
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaStatScreenHandlers, 0x2);
    case 0x12:
        UI_StartUIVarDelay();
        return;
    case 0x1:
        UI_CloseGoldDialog();
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaInventoryHandlers, 0x4);
        UI_StartUIVarDelay();
        return;
    case 0x5:
        CHAT_CloseChatInput();
        sub_0047B4E0_Nop();
        if (!gaUIVarStates[0xC] && !gaUIVarStates[0x17] && !gaUIVarStates[0x19]
            && !gaUIVarStates[0x1A] && !gaUIVarStates[0x1B] && !gaUIVarStates[0x1C]
            && !gaUIVarStates[0x1D] && !gaUIVarStates[0x1E] && !gaUIVarStates[0x20])
            CMDTBL_SetHotkeyHandlers(0x1, 0x1);
        if (gaUIVarStates[0xA])
            SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaAutomapHandlers, 0x5);
        return;
    case 0x6:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaNewStatsHandlers, 0x2);
        return;
    case 0x13:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaPetIconHandlers, 0x1);
        return;
    case 0x7:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaNewSkillsHandlers, 0x2);
        return;
    case 0x8:
    case 0xE:
        UI_StartUIVarDelay();
        NPCMENU_CloseByState();
        return;
    case 0x9:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaEscMenuHandlers, 0x7);
        SELECT_ClearSelection();
        return;
    case 0xB:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyConfigWheelHandlers, 0x1);
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyConfigHandlers, 0xD);
        TEXT_ToggleKeyConfigPanel(0);
        return;
    case 0xC:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaNpcShopHandlers, 0x8);
        NPCMENU_CloseByState();
        CMDTBL_SetHotkeyHandlers(0x1, 0x1);
        return;
    case 0xF:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaQuestScreenHandlers, 0x7);
        QUESTLOG_ResetQuestButton();
        UI_StartUIVarDelay();
        return;
    case 0x11:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaQuestLogHandlers, 0x4);
        QUESTLOG_ResetQuestButtonState();
        return;
    case 0x10:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaIniScrollHandlers, 0x2);
        sub_0049FF00_Nop();
        UI_StartUIVarDelay();
        return;
    case 0x14:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaWaypointHandlers, 0x5);
        sub_0049CF50_SendWaypointClose();
        UI_StartUIVarDelay();
        return;
    case 0x15:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMiniPanelHandlers, 0x2);
        return;
    case 0x16:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaPartyScreenHandlers, 0x2);
        PARTY_FreeRosterUnits();
        UI_StartUIVarDelay();
        return;
    case 0x17:
        if (sub_004B9180())
            return;
        PLAYER_SetPanelSlide(0);
        UI_CloseGoldDialog();
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMpTradeHandlers, 0xD);
        UI_StartUIVarDelay();
        MONSTER_CloseWait(0);
        CMDTBL_SetHotkeyHandlers(0x1, 0x1);
        return;
    case 0x19:
        UI_CloseGoldDialog();
        PLAYER_SetPanelSlide(0);
        INV_CloseStashPanel();
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaStashHandlers, 0x8);
        UI_StartUIVarDelay();
        CMDTBL_SetHotkeyHandlers(0x1, 0x1);
        return;
    case 0x1A:
        PLAYER_SetPanelSlide(0);
        INV_ShutdownCubePanel();
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaCubeHandlers, 0x7);
        UI_StartUIVarDelay();
        CMDTBL_SetHotkeyHandlers(0x1, 0x1);
        return;
    case 0x18:
        TEXT_CloseMessageLogDialog();
        return;
    case 0x1F:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaBeltRowsHandlers, 0x2);
        return;
    case 0x21:
        HIREABLES_CloseHelpUi();
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHelpScreenHandlers, 0x5);
        return;
    case 0x22:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHelpButtonHandlers, 0x2);
        return;
    case 0x23:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHireIconHandlers, 0x3);
        return;
    case 0x24:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMercInvHandlers, 0x3);
        INV_ResetHover();
        return;
    case 0x25:
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaRecipeScrollHandlers, 0x2);
        return;
    }
}

// 0x00455F20
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg)
{
    D2_ASSERT(nUIVar < 0x26, 0x13FB);
    D2_ASSERT(nState <= 2, 0x13FC);
    const int nOldState = gaUIVarStates[nUIVar];
    if (!FOG_IsExpansion() || !GAME_IsExpansion())
    {
        if (nUIVar == 0x23 || nUIVar == 0x24 || nUIVar == 0x25)
        {
            return 0;
        }
    }
    if (!UI_CanSetUIVar(nUIVar, nState))
    {
        return 0;
    }
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    switch (nState)
    {
    case 0:
        if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
        {
            gaUIVarStates[nUIVar] = 1;
        }
        break;
    case 1:
        gaUIVarStates[nUIVar] = 0;
        break;
    case 2:
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer))
            {
                gaUIVarStates[nUIVar] = !gaUIVarStates[nUIVar];
            }
            else if (nUIVar == 0x05)
            {
                gaUIVarStates[0x05] = !gaUIVarStates[0x05];
            }
        }
        else
        {
            gaUIVarStates[nUIVar] = !gaUIVarStates[nUIVar];
        }
        break;
    }

    const int nNewState = gaUIVarStates[nUIVar];
    if (!nOldState)
    {
        if (nNewState)
        {
            UI_SetPanelHandlers(nUIVar);
            if (nUIVar == 0x05)
            {
                CHAT_ClearChatLine();
            }
        }
    }
    else if (!nNewState)
    {
        UI_ClearPanelHandlers(nUIVar);
    }

    const int nA = sub_00468730();
    const int nB = sub_00468740();
    switch (nUIVar)
    {
    case 14:
        if (nNewState)
        {
            PLAYER_SetPanelSlide(1);
        }
        else
        {
            PLAYER_SetPanelSlide(0);
        }
        break;
    case 12:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 32:
        if (nNewState)
        {
            PLAYER_SetPanelSlide(3);
        }
        else
        {
            PLAYER_SetPanelSlide(0);
        }
        break;
    case 11:
        if (!nNewState)
        {
            TEXT_CloseKeyCaptureHandlers();
        }
        break;
    case 1:
        INV_ResetHover();

    case 4:
        if (!gaUIVarStates[2] && !gaUIVarStates[0x14] && !gaUIVarStates[0xF] && !gaUIVarStates[0x10]
            && !gaUIVarStates[0x24] && !gaUIVarStates[0x25] && !gaUIVarStates[0x16])
        {
            if (nNewState)
            {
                PLAYER_SetPanelSlide(1);
                if (nArg && nA > gnScreenWidth / 4)
                {
                    CURSOR_SetCursorPosition(nA - gnScreenWidth / 4, nB);
                }
            }
            else
            {
                PLAYER_SetPanelSlide(0);
                if (nArg && nA < gnScreenWidth / 2)
                {
                    CURSOR_SetCursorPosition(gnScreenWidth / 4 + nA, nB);
                }
            }
        }
        else if (nNewState)
        {
            PLAYER_SetPanelSlide(3);
        }
        else
        {
            PLAYER_SetPanelSlide(2);
        }
        break;
    case 2:
    case 15:
    case 16:
    case 20:
    case 22:
    case 36:
    case 37:
        if (!gaUIVarStates[1] && !gaUIVarStates[4])
        {
            if (nNewState)
            {
                PLAYER_SetPanelSlide(2);
                if (nArg && nA < gnScreenWidth - gnScreenWidth / 4)
                {
                    CURSOR_SetCursorPosition(gnScreenWidth / 4 + nA, nB);
                }
            }
            else
            {
                PLAYER_SetPanelSlide(0);
                if (nArg && nA > gnScreenWidth / 2)
                {
                    CURSOR_SetCursorPosition(nA - gnScreenWidth / 4, nB);
                }
            }
        }
        else if (nNewState)
        {
            PLAYER_SetPanelSlide(3);
        }
        else
        {
            PLAYER_SetPanelSlide(1);
        }
        break;
    }
    return 1;
}

// 0x00456300
int __fastcall UI_CloseUIVars(int bArg1, int nArg2)
{
    int bResult = 0;
    for (int i = 0; i < 0x26; i++)
    {
        if (gaUIVarStates[i] == 1 && (gaUIVarDefaults[i] == 1 || (bArg1 && i == 0x0A)))
        {
            UI_SetUIVar(i, 1, nArg2);
            bResult = 1;
            if (i == 0x19 || i == 1)
            {
                INV_ResetHover();
            }
        }
    }
    return bResult;
}

// 0x004565E0
void __fastcall UI_DrawLoadingScreen(int bAdvanceFrame)
{
    if (!WINDOW_GetState())
    {
        D2GFX_ClearScreen(0);
    }

    const int nLoadState = GAME_GetConnectionType();
    GAME_TickKeepAlive();

    if (WINDOW_GetState())
    {
        if (bAdvanceFrame)
        {
            ++gnLoadingFrame;
        }
        return;
    }

    D2Win_10179_UpdatePaletteFlash();
    if (!D2GFX_StartDraw(1, 0, 0, 0))
    {
        if (bAdvanceFrame)
        {
            ++gnLoadingFrame;
        }
        return;
    }

    if (!gpLoadingScreen)
    {
        GAME_LoadLoadingScreen();
        D2_ASSERT(gpLoadingScreen, 6594);
    }

    if (nLoadState == 6 || nLoadState == 8 || nLoadState == 7 || nLoadState == 9)
    {
        if (!gnLoadingBarColor)
        {
            gnLoadingBarColor = D2Win_10034_MixRGB(0x60, 0, 0);
            gnLoadingBoxColor = D2Win_10034_MixRGB(0xFF, 0xFF, 0);
        }

        if (!gbLoadingAfterUnload)
        {
            D2GFX_DrawBox(gnScreenWidth / 2 - 0x82, gnScreenHeight / 2 + 0x9E, gnScreenWidth / 2 + 0x82, gnScreenHeight / 2 + 0xB2, gnLoadingBoxColor, 1);
            D2GFX_DrawBox(gnScreenWidth / 2 - 0x80, gnScreenHeight / 2 + 0xA0, gnScreenWidth / 2 + 0x80, gnScreenHeight / 2 + 0xB0, 0, 5);

            const int nWidth = DLIGHTMAP_GetProgress();
            if (nWidth)
            {
                AUTOMAP_DrawFramedBox(gnScreenWidth / 2 - 0x80, gnScreenHeight / 2 + 0xA0, nWidth, 0x10, gnLoadingBarColor, 5);
            }
        }
    }

    const int nFrames = CelFileGetCelsPerDirection(gpLoadingScreen);
    if (gnLoadingFrame >= nFrames)
    {
        gnLoadingFrame = nFrames - 1;
    }

    D2GfxDataStrc tContext;
    tContext.pCelFile = gpLoadingScreen;
    tContext.nFrame = gnLoadingFrame;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnScreenWidth / 2 - 0x80, gnScreenHeight / 2 + 0x80, -1, 5, 0);
    D2GFX_EndScene();
    GAME_ResetMouseState();
    GAME_ResetMouseButtons();

    if (bAdvanceFrame)
    {
        ++gnLoadingFrame;
    }
}

// 0x004567F0
void __cdecl UI_ToggleMiniPanel()
{
    unsigned long dwValue;
    if (SRegLoadValue("Diablo II", "Mini Panel", 1, &dwValue) && dwValue)
        return;
    const int bWasOn = gaUIVarStates[UIVAR_MINIPANEL];
    if (FOG_IsExpansion())
        GAME_IsExpansion();
    D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
    if (!gaUIVarStates[UIVAR_MINIPANEL])
    {
        if (TEXT_IsTextBoxOpen())
            return;
        for (int i = 0; i < gnUIVarCount; ++i)
        {
            if (gaUIVarStates[i] == 1)
            {
                bool bClose = true;
                switch (gapUIVarRecords[i]->anCloseKind[0x15])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (NPCMENU_GetInteractNpcId(&nLow))
                        NPCMENU_EndNpcInteraction(nLow);
                    break;
                }
                case 1:
                    UI_SetUIVar(i, 1, 0);
                    break;
                case 2:
                case 3:
                    bClose = false;
                    break;
                default:
                    return;
                }
                if (!bClose)
                    return;
            }
        }
    }
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
        gaUIVarStates[UIVAR_MINIPANEL] = gaUIVarStates[UIVAR_MINIPANEL] == 0;
    if (!bWasOn)
    {
        if (gaUIVarStates[UIVAR_MINIPANEL])
            SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaMiniPanelHandlers, 2);
    }
    else
    {
        if (!gaUIVarStates[UIVAR_MINIPANEL])
            sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMiniPanelHandlers, 2);
    }
    sub_00468730();
    sub_00468740();
}

// 0x00456970
void __cdecl UI_InitUI()
{
    char szPath[0x104];
    INV_LoadPanelCels();
    MINIPANEL_LoadMiniPanel();
    TEXT_LoadTextSettings();
    TEXT_LoadLevelCels();
    HIREABLES_LoadHirelingIcons();
    TEXT_InitNpcMenu();
    AUTOMAP_InitAutomap();
    TEXT_InitWaypointData();
    MONSTER_ResetTradeState();
    gpGoldPanel = 0;
    gpGoldControlA = 0;
    gpGoldControlB = 0;
    gpGoldControlD = 0;
    gpGoldControlC = 0;
    gbGoldPanelFlag = 0;
    INV_LoadInvPanelCels();
    for (int i = 0; i < 0x26; i++)
        gaUIVarStates[i] = 0;

    {
        const int bWasOn = gaUIVarStates[0];
        if (FOG_IsExpansion())
            GAME_IsExpansion();
        D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
        if (TEXT_IsTextBoxOpen())
            goto mini_panel;
        for (int i = 0; i < gnUIVarCount; ++i)
        {
            if (gaUIVarStates[i] == 1)
            {
                switch (gapUIVarRecords[i]->anCloseKind[0])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (NPCMENU_GetInteractNpcId(&nLow))
                        NPCMENU_EndNpcInteraction(nLow);
                    break;
                }
                case 1:
                    UI_SetUIVar(i, 1, 0);
                    break;
                case 2:
                    goto mini_panel;
                default:
                    D2_ASSERT(false, 0x13E6);
                }
            }
        }
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
            gaUIVarStates[0] = 1;
        if (!bWasOn)
        {
            if (gaUIVarStates[0])
                SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaGameUIHandlers, 4);
        }
        else
        {
            if (!gaUIVarStates[0])
                sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaGameUIHandlers, 4);
        }
        sub_00468730();
        sub_00468740();
    }

mini_panel:
    UI_ToggleMiniPanel();
    {
        const int bWasOn = gaUIVarStates[0x22];
        if (FOG_IsExpansion())
            GAME_IsExpansion();
        D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
        if (TEXT_IsTextBoxOpen())
            goto load_cels;
        for (int i = 0; i < gnUIVarCount; ++i)
        {
            if (gaUIVarStates[i] == 1)
            {
                bool bClose = true;
                switch (gapUIVarRecords[i]->anCloseKind[0x22])
                {
                case 0:
                    break;
                case 4:
                {
                    int nLow;
                    if (NPCMENU_GetInteractNpcId(&nLow))
                        NPCMENU_EndNpcInteraction(nLow);
                    break;
                }
                case 1:
                    UI_SetUIVar(i, 1, 0);
                    break;
                case 2:
                case 3:
                    bClose = false;
                    break;
                default:
                    goto load_cels;
                }
                if (!bClose)
                    goto load_cels;
            }
        }
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
            gaUIVarStates[0x22] = 1;
        if (!bWasOn)
        {
            if (gaUIVarStates[0x22])
                SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHelpButtonHandlers, 2);
        }
        else
        {
            if (!gaUIVarStates[0x22])
                sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHelpButtonHandlers, 2);
        }
        sub_00468730();
        sub_00468740();
    }

load_cels:
    wsprintfA(szPath, "%s\\UI\\CURSOR\\Pentspin", gszDataGlobal);
    gpPentspinCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\focus16", gszDataGlobal);
    gpFocus16Cel = ARCHIVE_LoadClientCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\menu\\boxpieces", gszDataGlobal);
    gpBoxPiecesCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    USEITEM_InitUseItemPanel();
    DIALOG_InitDialogs();
    INV_LoadShopPanelCels();
    TEXT_LoadTextSliderCel();
    TEXT_ResetQuestPanel();
    CMDTBL_EnableHotkeyHandlers();
    ESCMENU_LoadOptionMenus();
    TEXT_InitTextSlider();
}

// 0x00456D80
void __cdecl UI_ShutdownUI()
{
    const int nPrevState = gaUIVarStates[0];
    if (FOG_IsExpansion())
    {
        GAME_IsExpansion();
    }
    D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
    CUNIT_GetPlayerUnit();
    gaUIVarStates[0] = 0;
    if (nPrevState)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaGameUIHandlers, 4);
    }
    sub_00468730();
    sub_00468740();
    HIREABLES_FreePanelCels();
    if (CUNIT_GetPlayerUnit())
    {
        SPELLSEL_FreeSkillIcons();
        sub_004AA980_FreePanelCel();
    }
    D2Win_10116();
    TEXT_FreeTextResources();
    MINIPANEL_SaveMiniPanel();
    HIREABLES_FreeHelpCels();
    TEXT_FreeLevelCels();
    HIREABLES_FreeHirelingIcons();
    NPCMENU_FreeNpcMenu();
    AUTOMAP_FreeAutomap();
    TEXT_CloseWaypointPanel();
    sub_004B91F0_CloseWait();
    UI_CloseGoldDialog();
    INV_FreeInvPanelCels();
    USEITEM_FreeUseItemPanel();
    QUESTLOG_FreeQuestPanel();
    INV_FreeNpcCels();
    DIALOG_FreeDialogs();
    sub_004BE060_FreeSliderCel();
    if (gpPentspinCel)
    {
        ARCHIVE_FreeClientCellFile(gpPentspinCel);
        gpPentspinCel = 0;
    }
    if (gpFocus16Cel)
    {
        ARCHIVE_FreeClientCellFile(gpFocus16Cel);
        gpFocus16Cel = 0;
    }
    if (gpBoxPiecesCel)
    {
        ARCHIVE_FreeClientCellFile(gpBoxPiecesCel);
        gpBoxPiecesCel = 0;
    }
    if (gpBuySellButton)
    {
        ARCHIVE_FreeClientCellFile(gpBuySellButton);
        gpBuySellButton = 0;
    }
    if (gpLoadingCell)
    {
        ARCHIVE_FreeClientCellFile(gpLoadingCell);
        gpLoadingCell = 0;
    }
    CMDTBL_DisableHotkeyHandlers();
    ESCMENU_FreeOptionMenus();
    TEXT_FreeTextSliderCel();
}

// 0x00456EE0
void __fastcall UI_DrawUIPanels(D2ViewStrc* pView)
{
    if (gaUIVarStates[18])
        return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        gnPanelOffsetX = 0x50;
        gnPanelOffsetY = -0x3C;
    }
    else
    {
        gnPanelOffsetX = 0;
        gnPanelOffsetY = 0;
    }
    sub_00502280_SetPopUpText(0, 0, 0, 0, 0);
    gwszHoverLine[0].wChar = 0;
    gwszHoverText[0] = 0;
    if (gaUIVarStates[9])
        ESCMENU_DrawOptions();
    if (gaUIVarStates[11])
        TEXT_DrawKeyConfigPanel();
    UI_DrawUnitHover(SELECT_GetSelectedUnit());
    if (gaUIVarStates[35])
        UI_DrawPetHover();
    if (!gaUIVarStates[1] && !gaUIVarStates[12] && !gaUIVarStates[14])
    {
        PANEL_DrawDurabilityIcons();
        PANEL_DrawQuantityWarningIcons();
    }
    if (gaUIVarStates[10] && UI_GetPanelSlideMode() != 3)
        PLAYER_DrawAutomap();
    GAME_DrawLevelLoadingScreen();
    HIREABLES_UpdateHirelingPanel();
    if (gaUIVarStates[19])
        HIREABLES_DrawPetIcons();
    if (gaUIVarStates[36])
        INV_DrawMercPanel();
    if (gaUIVarStates[37])
        INV_DrawRecipeScroll();
    if (gaUIVarStates[15])
        QUESTLOG_DrawQuestPage();
    if (gaUIVarStates[1] || gaUIVarStates[12] || gaUIVarStates[14] || gaUIVarStates[25]
        || gaUIVarStates[26] || gaUIVarStates[28] || gaUIVarStates[29])
        INV_DrawInventoryPanel();
    if (gaUIVarStates[23])
    {
        MONSTER_DrawDialogHover();
        INV_DrawInventoryPanel();
    }
    UI_DrawProgressiveStates();
    if (gaUIVarStates[4])
        sub_004AC690_DrawSkillPanel();
    if (gaUIVarStates[2])
        TEXT_DrawCharStats();
    if (gaUIVarStates[22])
        PANEL_DrawPartyPanel();
    if (gpGoldPanel)
        DIALOG_DrawDialog(gpGoldPanel);
    if (gaUIVarStates[16])
        TEXT_DispatchTextData();
    if (gaUIVarStates[20])
        TEXT_DrawWaypointPanel();
    if (gaUIVarStates[33])
    {
        HIREABLES_LoadHelpCels();
        sub_00494EB0_DrawHelpShade();
    }
    PANEL_DrawControlPanel();
    if (gaUIVarStates[3])
        SPELLSEL_ResetSkillIcons();
    if (gaUIVarStates[31])
        PANEL_SetBeltExpandedMode();
    TEXT_UpdateLevelUpButtons();
    if (gaUIVarStates[34])
        VIEW_DrawHelpButtons();
    if (gaUIVarStates[6])
        TEXT_DrawStatButton();
    else
        TEXT_DrawLeftPanelButton();
    if (gaUIVarStates[7])
        TEXT_DrawSkillButton();
    else
        TEXT_DrawRightPanelButton();
    if (gaUIVarStates[17])
        QUESTLOG_DrawQuestButton();
    PANEL_DrawLifeManaText();
    if (gaUIVarStates[21])
        MINIPANEL_UpdateSlotBar();
    if (gaUIVarStates[5])
        CHAT_DrawChatPanel();
    if (gaUIVarStates[33])
    {
        UI_CloseUIVars(0, 0);
        const int bWasOn = gaUIVarStates[33];
        if (FOG_IsExpansion())
            GAME_IsExpansion();
        D2_ASSERT(gnUIVarCount == 0x26, 0x1397);
        if (!gaUIVarStates[33])
        {
            if (TEXT_IsTextBoxOpen())
                goto done;
            for (int i = 0; i < gnUIVarCount; ++i)
            {
                if (gaUIVarStates[i] == 1)
                {
                    bool bClose = true;
                    switch (gapUIVarRecords[i]->anCloseKind[0x21])
                    {
                    case 0:
                        break;
                    case 4:
                    {
                        int nLow;
                        if (NPCMENU_GetInteractNpcId(&nLow))
                            NPCMENU_EndNpcInteraction(nLow);
                        break;
                    }
                    case 1:
                        UI_SetUIVar(i, 1, 0);
                        break;
                    case 2:
                    case 3:
                        bClose = false;
                        break;
                    default:
                        goto done;
                    }
                    if (!bClose)
                        goto done;
                }
            }
        }
        {
            D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
            if (!pPlayer || (pPlayer->dwUnitType == UNIT_PLAYER && !CUNIT_IsDeadOrDying(pPlayer)))
                gaUIVarStates[33] = gaUIVarStates[33] == 0;
            if (!bWasOn)
            {
                if (gaUIVarStates[33])
                    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHelpScreenHandlers, 5);
            }
            else
            {
                if (!gaUIVarStates[33])
                {
                    HIREABLES_CloseHelpUi();
                    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHelpScreenHandlers, 5);
                }
            }
            sub_00468730();
            sub_00468740();
        }
done:
        INV_DrawHelpScreen();
    }
    if (gaUIVarStates[13] && UI_GetPanelSlideMode() != 3)
    {
        SHOWITEMS_DrawUnitNames();
        if (GAME_GetConnectionType())
            CUNIT_ForEachPlayer(UI_DrawPartyMemberText);
    }
    if (gaUIVarStates[8])
        NPCMENU_UpdateNpcInteract();
    if (gaUIVarStates[14])
        USEITEM_DrawPanelUnit();
    WARDENCLIENT_DrawHostileIcon();
    TEXT_UpdateTexts(pView);
    D2Win_10124();
    UI_DrawHoverText();
    GAME_DrawPopUpText();
    UI_DrawHoverName();
    UI_DrawStoredUnitNumber();
    UI_DrawDeathScreen();
    VIEW_DrawCountdown();
}




extern int gbAutomapLeftPrev; // 0x007A51E4

int gbAutomapLeftSaved; // 0x007A51E8












void __fastcall CURSOR_SetCursorPosition(int nX, int nY); // 0x00468770


// 0x0046F980
int __cdecl UI_GetGfxMemory()
{
    return gnGfxMemory;
}

// 0x0046F990
int __cdecl UI_GetCofMemoryUsed()
{
    return gnCofMemoryUsed;
}

// 0x0046F9A0
int __cdecl UI_GetCofMemoryLimit()
{
    return gnCofMemoryLimit;
}

// 0x00454AD0
void __fastcall UI_DrawUnitHoverName(D2UnitStrc* pUnit)
{
    const int nOld = D2Win_10127_SetFont(1);
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxt = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    int bDead = 0;
    D2MonStats2Txt* pMonStats2Txt;
    unsigned short wszText[0x800];
    for (int i = 0; i < 0x800; i++)
        wszText[i] = 0;
    if (!(gdwBitMasks[1] & pMonStatsTxt->nMonStatsFlags[1]) && (gdwBitMasks[7] & pMonStatsTxt->nMonStatsFlags[1]) && pMonStatsTxt->wNameStr)
    {
        pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (pMonStats2Txt)
        {
            gnHoverY -= pMonStats2Txt->nPixHeight;
        }
        sub_005267E0((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700((Unicode*)wszText, CUNIT_GetUnitName(pUnit));
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        if (pUnit && pUnit->dwAnimMode == 12)
        {
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
            {
                return;
            }
            bDead = 1;
            if (!STRTABLE_GetLanguage())
            {
                sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0x90B));
            }
            else
            {
                Unicode wszParen[2];
                char szParen[] = "(";
                sub_00526F20_ToUnicode(wszParen, szParen, 2);
                sub_00526700((Unicode*)wszText, wszParen);
                sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0x90B));
                strcpy(szParen, ")");
                sub_00526F20_ToUnicode(wszParen, szParen, 2);
                sub_00526700((Unicode*)wszText, wszParen);
            }
            sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        }
        sub_00526700((Unicode*)wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        const int nY = UI_GetMonsterLifeFraction(pUnit);
        int nColor = 0;
        if (MONSTER_IsUniqueMonster(pUnit))
        {
            nColor = 4;
        }
        if (MONSTER_IsChampionMonster(pUnit))
        {
            nColor = 3;
        }
        if (bDead)
        {
            nColor = 1;
        }
        if (nClassId == 0xF3 || nClassId == 0x14D || nClassId == 0xF2 || nClassId == 0xD3 || nClassId == 0x220
            || nClassId == 0x23A || nClassId == 0xE5 || nClassId == 0x2C4 || nClassId == 0x2C3 || nClassId == 0x2C2
            || nClassId == 0x2C1 || nClassId == 0x2C5 || nClassId == 0x2C0)
        {
            nColor = 4;
        }
        D2RectStrc tRect;
        if (UI_GetHoverRect(&tRect))
        {
            const int nX = ((tRect.nRight + tRect.nLeft) >> 1) - (D2Win_10121_GetTextWidth((Unicode*)wszText) >> 1);
            D2Win_10130_DrawFramedTextEx((Unicode*)wszText, nX, 0x20, nColor, 0, nY);
            if (!bDead)
            {
                D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(!pUnit ? -1 : pUnit->dwClassId);
                unsigned short nTypeString = 0;
                if (MONSTERS_IsDemon(pUnit))
                {
                    nTypeString = 0x275E;
                }
                else if (MONSTERS_IsUndead(pUnit))
                {
                    nTypeString = 0x275D;
                }
                if (!AUTOMAP_GetHoverMonsterName(pUnit, nTypeString))
                {
                    if (nTypeString)
                    {
                        Unicode wszLine[0x200];
                        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(nTypeString));
                        sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(0xF9B));
                        if (pRecord->wDescStr != 0x1506)
                        {
                            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(pRecord->wDescStr));
                        }
                        GAME_SetHoverLine(wszLine, nColor);
                    }
                    else if (pRecord->wDescStr != 0x1506)
                    {
                        GAME_SetHoverLine(D2LANG_GetStringFromTblIndex(pRecord->wDescStr), nColor);
                    }
                }
                UI_BuildImmunityText(pUnit);
            }
            else
            {
                gwszHoverName[0].wChar = 0;
            }
        }
    }
    else
    {
        gwszHoverName[0].wChar = 0;
        int nTickLow;
        if (!NPCMENU_GetInteractNpcId(&nTickLow) && !TEXT_IsTextBoxOpen())
        {
            pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
            if (pMonStats2Txt)
            {
                gnHoverY -= pMonStats2Txt->nPixHeight;
            }
            D2Win_10129_DrawFramedText(CUNIT_GetUnitName(pUnit), gnHoverX, gnHoverY, 0, 1);
        }
    }
    D2Win_10127_SetFont(nOld);
}

extern "C" void __cdecl TEXT_QuestButtonDownMsg(); // 0x004A2A20
extern "C" void __cdecl SCMD_HandleResetMessage(); // 0x00452090
extern "C" void __cdecl ESCMENU_OptionMouseDown(); // 0x0047D7F0
extern "C" void __cdecl ESCMENU_OptionMouseUp(); // 0x0047D840
extern "C" void __cdecl ESCMENU_SelectNextOption(); // 0x0047D8A0
extern "C" void __cdecl ESCMENU_SelectPreviousOption(); // 0x0047D920
extern "C" void __cdecl ESCMENU_OptionKeyLeft(); // 0x0047D9A0
extern "C" void __cdecl ESCMENU_OptionKeyRight(); // 0x0047DA90
extern "C" void __cdecl ESCMENU_OptionActivate(); // 0x0047DB80
extern "C" void __cdecl INV_NpcPanelMouseMove(); // 0x00486EF0
extern "C" void __cdecl INV_UpdateInventoryHover(); // 0x004873A0
extern "C" void __cdecl INV_ResetShopCursorMsg(); // 0x00488910
extern "C" void __cdecl INV_NpcShopMouseMoveMsg(); // 0x004889D0
extern "C" void __cdecl sub_00488B00(); // 0x00488B00
extern "C" void __cdecl INV_ConsumeMsg(); // 0x00488DF0
extern "C" void __cdecl INV_OpenChatKeyMsg(); // 0x00488E70
extern "C" void __cdecl INV_TradeMouseMoveMsg(); // 0x004894D0
extern "C" void __cdecl INV_TradePanelMsg(); // 0x00489580
extern "C" void __cdecl INV_TradeCancelMsg(); // 0x004897A0
extern "C" void __cdecl INV_StashMouseMoveMsg(); // 0x00489A30
extern "C" void __cdecl INV_StashClickMsg(); // 0x00489AC0
extern "C" void __cdecl INV_StashCloseMsg(); // 0x00489CE0
extern "C" void __cdecl INV_KeyNoRepeatMsg(); // 0x00489D70
extern "C" void __cdecl INV_CubeMouseMoveMsg(); // 0x0048A0F0
extern "C" void __cdecl INV_CubeClickMsg(); // 0x0048A190
extern "C" void __cdecl INV_CubeCloseMsg(); // 0x0048A3E0
extern "C" void __cdecl INV_MercPanelClickMsg(); // 0x0048B680
extern "C" void __cdecl INV_MercInvClickMsg(); // 0x0048B7C0
extern "C" void __cdecl INV_MercPanelHoverMsg(); // 0x0048BA50
extern "C" void __cdecl INV_CloseRecipeScrollClickMsg(); // 0x0048BD80
extern "C" void __cdecl INV_HandlePanelClick(); // 0x004912A0
extern "C" void __cdecl INV_GridClickMsg(); // 0x004917C0
extern "C" void __cdecl INV_InventoryClickMsg(); // 0x00491AD0
extern "C" void __cdecl sub_00491D20(); // 0x00491D20
extern "C" void __cdecl sub_00492310(); // 0x00492310
extern "C" void __cdecl INV_StashButtonDownMsg(); // 0x00492510
extern "C" void __cdecl INV_WeaponSwapKeyMsg(); // 0x00492770
extern "C" void __cdecl INV_CubeButtonUpMsg(); // 0x004927C0
extern "C" void __cdecl HIREABLES_PetIconClickMsg(); // 0x00493430
extern "C" void __cdecl WARDENCLIENT_HandlePetIconClick(); // 0x004936E0
extern "C" void __cdecl PANEL_CloseUIVarsMsg(); // 0x00498C00
extern "C" void __cdecl TEXT_OnRosterMouseDown(); // 0x0049BB60
extern "C" void __cdecl sub_0049BDD0(); // 0x0049BDD0
extern "C" void __cdecl TEXT_WaypointKeyMsg(); // 0x0049CEC0
extern "C" void __cdecl TEXT_WaypointMouseDown(); // 0x0049D160
extern "C" void __cdecl TEXT_PanelClickMsg(); // 0x0049FEA0
extern "C" void __cdecl TEXT_CloseQuestPanelMsg(); // 0x004A2840
extern "C" void __cdecl sub_004A3E40(); // 0x004A3E40
extern "C" void __cdecl TEXT_QuestButtonUpMsg(); // 0x004A4110
extern "C" void __cdecl TEXT_QuestLButtonUpMsg(); // 0x004A42A0
extern "C" void __cdecl sub_004A66E0(); // 0x004A66E0
extern "C" void __cdecl sub_004A6790(); // 0x004A6790
extern "C" void __cdecl TEXT_StatButtonUpMsg(); // 0x004A6840
extern "C" void __cdecl TEXT_SkillButtonUpMsg(); // 0x004A6920
extern "C" void __cdecl TEXT_OnLButtonDown(); // 0x004A7720
extern "C" void __cdecl TEXT_OnLButtonUp(); // 0x004A78C0
extern "C" void __cdecl SPELLSEL_SkillSelectClickMsg(); // 0x004A9BD0
extern "C" void __cdecl sub_004AB7E0_SkillTreeLButtonDown(); // 0x004AB7E0
extern "C" void __cdecl sub_004ABC30(); // 0x004ABC30
extern "C" void __cdecl ROSTERPETS_HandlePanelButtonDown(); // 0x004A5980
extern "C" void __cdecl TEXT_KeyConfigWheelMsg(); // 0x004A59D0
extern "C" void __cdecl TEXT_PrevEntryMsg(); // 0x004A5A40
extern "C" void __cdecl TEXT_NextEntryMsg(); // 0x004A5AB0
extern "C" void __cdecl TEXT_SelectSecondaryColumnMsg(); // 0x004A5B30
extern "C" void __cdecl TEXT_SelectPrimaryColumnMsg(); // 0x004A5B90
extern "C" void __cdecl TEXT_ClearEntryKeyMsg(); // 0x004A5BF0
extern "C" void __cdecl TEXT_KeyConfigButtonUpMsg(); // 0x004A5F10
extern "C" void __cdecl TEXT_ApplyEntryMsg(); // 0x004A5F70
extern "C" void __cdecl TEXT_CancelKeyConfigMsg(); // 0x004A5C70
extern "C" void __cdecl MINIPANEL_SlotsClickMsg(); // 0x0047ED90
extern "C" void __cdecl MINIPANEL_SlotsClick(); // 0x0047EF30
extern "C" void __cdecl ROSTERPETS_HandleHelpButtonDown(); // 0x00494F30
extern "C" void __cdecl INV_HelpCloseButtonMsg(); // 0x00496720
extern "C" char gData_007A28A0[]; // 0x007A28A0
extern "C" char gData_007A2938[]; // 0x007A2938
extern "C" char gData_007A29D0[]; // 0x007A29D0
extern "C" void __cdecl PANEL_BeltMouseReleaseMsg(); // 0x004996A0
extern "C" void __cdecl PANEL_BeltMouseMove(); // 0x00499BB0
extern "C" void __cdecl PANEL_BeltClickMsg(); // 0x00499D10
extern "C" void __cdecl TEXT_OnWaypointMouseUp(); // 0x0049D010
extern "C" void __cdecl INV_OnKeyCloseHelp(); // 0x004967A0
extern "C" void __cdecl PANEL_OnMouseClick(); // 0x00499500
extern "C" void __cdecl sub_0049D010_WaypointMouseUp(); // 0x0049D010
extern "C" void __cdecl AUTOMAP_IncreaseBaseY(); // 0x004574D0
extern "C" void __cdecl AUTOMAP_DecreaseBaseY(); // 0x004574E0
extern "C" void __cdecl AUTOMAP_DecreaseBaseX(); // 0x004574F0
extern "C" void __cdecl AUTOMAP_IncreaseBaseX(); // 0x00457500
extern "C" void __cdecl sub_004967A0_KeyCloseHelp(); // 0x004967A0
extern "C" void __cdecl sub_00499500_Click(); // 0x00499500
extern "C" void __cdecl HIREABLES_HirelingIconHoverMsg(); // 0x00493760
extern "C" void __cdecl HIREABLES_HirelingIconClickMsg(); // 0x004938E0
extern "C" void __cdecl HIREABLES_ButtonDownMsg(); // 0x004952B0
extern "C" void __cdecl HIREABLES_ButtonUpMsg(); // 0x00495320
extern "C" void __cdecl sub_0048BDF0_Nop(); // 0x0048BDF0
extern "C" void __cdecl sub_00494FB0_Nop(); // 0x00494FB0
extern "C" void __cdecl sub_00457510_Nop(); // 0x00457510

#pragma pack(push, 1)
struct d2data_006D6204_t
{
    unsigned char b0[8];
    const void* p1;
    unsigned char b2[8];
    const void* p3;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006D62C4_t
{
    unsigned char b0[8];
    const void* p1;
    unsigned char b2[8];
    const void* p3;
    unsigned char b4[8];
    const void* p5;
    unsigned char b6[8];
    const void* p7;
    unsigned char b8[8];
    const void* p9;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006D5F28_t
{
    unsigned char b0[8];
    const void* p1;
    unsigned char b2[8];
    const void* p3;
    unsigned char b4[8];
    const void* p5;
    unsigned char b6[8];
    const void* p7;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006D6300_t
{
    unsigned char b0[8];
    const void* p1;
    unsigned char b2[8];
    const void* p3;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FAA0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FB38_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FBD0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FC68_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FD00_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FD98_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FE30_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FEC8_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FF60_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070FFF8_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710090_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710128_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007101C0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710258_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007102F0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710388_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710420_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007104B8_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710550_t
{
    unsigned char b0[608];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007107B0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710848_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007108E0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710978_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710A10_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710AA8_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710B40_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710BD8_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710C70_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710D08_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710DA0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710E38_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710ED0_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00710F68_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00711000_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00711098_t
{
    unsigned char b0[152];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070F818_t
{
    const void* p0;
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
};
#pragma pack(pop)

extern "C" const D2MsgHandlerEntryStrc gData_006D5F58[4]; // 0x006D5F58
extern "C" const D2MsgHandlerEntryStrc gData_006D5FAC[2]; // 0x006D5FAC
extern "C" const D2MsgHandlerEntryStrc gData_006D5FC4[1]; // 0x006D5FC4
extern "C" const D2MsgHandlerEntryStrc gData_006D5FD0[2]; // 0x006D5FD0
extern "C" const D2MsgHandlerEntryStrc gData_006D5FE8[2]; // 0x006D5FE8
extern "C" const D2MsgHandlerEntryStrc gData_006D6000[1]; // 0x006D6000
extern "C" const D2MsgHandlerEntryStrc gData_006D600C[2]; // 0x006D600C
extern "C" const D2MsgHandlerEntryStrc gData_006D6030[7]; // 0x006D6030
extern "C" const D2MsgHandlerEntryStrc gData_006D615C[4]; // 0x006D615C
extern "C" const D2MsgHandlerEntryStrc gData_006D61B0[2]; // 0x006D61B0
extern "C" const D2MsgHandlerEntryStrc gData_006D61C8[5]; // 0x006D61C8
extern "C" const D2MsgHandlerEntryStrc gData_006D621C[2]; // 0x006D621C
extern "C" const D2MsgHandlerEntryStrc gData_006D6318[3]; // 0x006D6318
extern "C" const D2MsgHandlerEntryStrc gData_006D633C[3]; // 0x006D633C
extern "C" const D2MsgHandlerEntryStrc gData_006D6360[2]; // 0x006D6360
extern "C" const D2MsgHandlerEntryStrc gData_006D6024[1]; // 0x006D6024
extern "C" const D2MsgHandlerEntryStrc gData_006D6084[5]; // 0x006D6084
extern "C" const D2MsgHandlerEntryStrc gData_006D60C0[13]; // 0x006D60C0
extern "C" const struct d2data_006D6204_t gData_006D6204; // 0x006D6204
extern "C" const struct d2data_006D62C4_t gData_006D62C4; // 0x006D62C4
extern "C" const struct d2data_006D5F28_t gData_006D5F28; // 0x006D5F28
extern "C" const struct d2data_006D6300_t gData_006D6300; // 0x006D6300
extern "C" struct d2data_0070FAA0_t gData_0070FAA0; // 0x0070FAA0
extern "C" struct d2data_0070FB38_t gData_0070FB38; // 0x0070FB38
extern "C" struct d2data_0070FBD0_t gData_0070FBD0; // 0x0070FBD0
extern "C" struct d2data_0070FC68_t gData_0070FC68; // 0x0070FC68
extern "C" struct d2data_0070FD00_t gData_0070FD00; // 0x0070FD00
extern "C" struct d2data_0070FD98_t gData_0070FD98; // 0x0070FD98
extern "C" struct d2data_0070FE30_t gData_0070FE30; // 0x0070FE30
extern "C" struct d2data_0070FEC8_t gData_0070FEC8; // 0x0070FEC8
extern "C" struct d2data_0070FF60_t gData_0070FF60; // 0x0070FF60
extern "C" struct d2data_0070FFF8_t gData_0070FFF8; // 0x0070FFF8
extern "C" struct d2data_00710090_t gData_00710090; // 0x00710090
extern "C" struct d2data_00710128_t gData_00710128; // 0x00710128
extern "C" struct d2data_007101C0_t gData_007101C0; // 0x007101C0
extern "C" struct d2data_00710258_t gData_00710258; // 0x00710258
extern "C" struct d2data_007102F0_t gData_007102F0; // 0x007102F0
extern "C" struct d2data_00710388_t gData_00710388; // 0x00710388
extern "C" struct d2data_00710420_t gData_00710420; // 0x00710420
extern "C" struct d2data_007104B8_t gData_007104B8; // 0x007104B8
extern "C" struct d2data_00710550_t gData_00710550; // 0x00710550
extern "C" struct d2data_007107B0_t gData_007107B0; // 0x007107B0
extern "C" struct d2data_00710848_t gData_00710848; // 0x00710848
extern "C" struct d2data_007108E0_t gData_007108E0; // 0x007108E0
extern "C" struct d2data_00710978_t gData_00710978; // 0x00710978
extern "C" struct d2data_00710A10_t gData_00710A10; // 0x00710A10
extern "C" struct d2data_00710AA8_t gData_00710AA8; // 0x00710AA8
extern "C" struct d2data_00710B40_t gData_00710B40; // 0x00710B40
extern "C" struct d2data_00710BD8_t gData_00710BD8; // 0x00710BD8
extern "C" struct d2data_00710C70_t gData_00710C70; // 0x00710C70
extern "C" struct d2data_00710D08_t gData_00710D08; // 0x00710D08
extern "C" struct d2data_00710DA0_t gData_00710DA0; // 0x00710DA0
extern "C" struct d2data_00710E38_t gData_00710E38; // 0x00710E38
extern "C" struct d2data_00710ED0_t gData_00710ED0; // 0x00710ED0
extern "C" struct d2data_00710F68_t gData_00710F68; // 0x00710F68
extern "C" struct d2data_00711000_t gData_00711000; // 0x00711000
extern "C" struct d2data_00711098_t gData_00711098; // 0x00711098
extern "C" struct d2data_0070F818_t gData_0070F818; // 0x0070F818

extern "C" const D2MsgHandlerEntryStrc gData_006D5F58[4] = {
    { 0, 513, (void*)(unsigned int)&INV_HandlePanelClick },
    { 0, 514, (void*)(unsigned int)&INV_NpcPanelMouseMove },
    { 0, 516, (void*)(unsigned int)&INV_GridClickMsg },
    { 0, 512, (void*)(unsigned int)&INV_UpdateInventoryHover }
}; // 0x006D5F58
#pragma comment(linker, "/alternatename:?gaInventoryHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D5F58")

extern const D2PanelHotkeysStrc gtNpcShopHotkeys = { 4, -1, 5, -1, -1, -1, 7, -1, (D2MsgHandlerEntryStrc *)&gaNpcShopHandlers }; // 0x006D5F88

extern "C" const D2MsgHandlerEntryStrc gData_006D5FAC[2] = {
    { 0, 513, (void*)(unsigned int)&sub_004AB7E0_SkillTreeLButtonDown },
    { 0, 514, (void*)(unsigned int)&sub_004ABC30 }
}; // 0x006D5FAC
#pragma comment(linker, "/alternatename:?gaSkillTreeHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D5FAC")

extern "C" const D2MsgHandlerEntryStrc gData_006D5FC4[1] = { { 0, 513, (void*)(unsigned int)&SPELLSEL_SkillSelectClickMsg } }; // 0x006D5FC4
#pragma comment(linker, "/alternatename:?gaMiniSkillHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D5FC4")

extern "C" const D2MsgHandlerEntryStrc gData_006D5FD0[2] = {
    { 0, 513, (void*)(unsigned int)&TEXT_OnLButtonDown },
    { 0, 514, (void*)(unsigned int)&TEXT_OnLButtonUp }
}; // 0x006D5FD0
#pragma comment(linker, "/alternatename:?gaStatScreenHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D5FD0")

extern "C" const D2MsgHandlerEntryStrc gData_006D5FE8[2] = {
    { 0, 513, (void*)(unsigned int)&sub_004A66E0 },
    { 0, 514, (void*)(unsigned int)&TEXT_StatButtonUpMsg }
}; // 0x006D5FE8
#pragma comment(linker, "/alternatename:?gaNewStatsHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D5FE8")

extern "C" const D2MsgHandlerEntryStrc gData_006D6000[1] = { { 3, 122, (void*)(unsigned int)&HIREABLES_PetIconClickMsg } }; // 0x006D6000
#pragma comment(linker, "/alternatename:?gaPetIconHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6000")

extern "C" const D2MsgHandlerEntryStrc gData_006D600C[2] = {
    { 0, 513, (void*)(unsigned int)&sub_004A6790 },
    { 0, 514, (void*)(unsigned int)&TEXT_SkillButtonUpMsg }
}; // 0x006D600C
#pragma comment(linker, "/alternatename:?gaNewSkillsHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D600C")

extern "C" const D2MsgHandlerEntryStrc gData_006D6030[7] = {
    { 0, 513, (void*)(unsigned int)&ESCMENU_OptionMouseDown },
    { 0, 514, (void*)(unsigned int)&ESCMENU_OptionMouseUp },
    { 3, 40, (void*)(unsigned int)&ESCMENU_SelectNextOption },
    { 3, 38, (void*)(unsigned int)&ESCMENU_SelectPreviousOption },
    { 3, 37, (void*)(unsigned int)&ESCMENU_OptionKeyLeft },
    { 3, 39, (void*)(unsigned int)&ESCMENU_OptionKeyRight },
    { 3, 13, (void*)(unsigned int)&ESCMENU_OptionActivate }
}; // 0x006D6030
#pragma comment(linker, "/alternatename:?gaEscMenuHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6030")

extern "C" const D2MsgHandlerEntryStrc gData_006D615C[4] = {
    { 0, 516, (void*)(unsigned int)&TEXT_QuestButtonDownMsg },
    { 0, 517, (void*)(unsigned int)&TEXT_QuestButtonUpMsg },
    { 0, 513, (void*)(unsigned int)&TEXT_QuestButtonDownMsg },
    { 0, 514, (void*)(unsigned int)&TEXT_QuestButtonUpMsg }
}; // 0x006D615C
#pragma comment(linker, "/alternatename:?gaQuestLogHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D615C")

extern const D2PanelHotkeysStrc gtQuestScreenHotkeys = { 5, -1, 6, -1, -1, -1, -1, -1, (D2MsgHandlerEntryStrc *)&gaQuestScreenHandlers }; // 0x006D618C

extern "C" const D2MsgHandlerEntryStrc gData_006D61B0[2] = {
    { 0, 513, (void*)(unsigned int)&TEXT_PanelClickMsg },
    { 0, 516, (void*)(unsigned int)&TEXT_PanelClickMsg }
}; // 0x006D61B0
#pragma comment(linker, "/alternatename:?gaIniScrollHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D61B0")

extern "C" const D2MsgHandlerEntryStrc gData_006D61C8[5] = {
    { 0, 513, (void*)(unsigned int)&TEXT_WaypointMouseDown },
    { 0, 514, (void*)(unsigned int)&TEXT_OnWaypointMouseUp },
    { 0, 516, (void*)(unsigned int)&TEXT_WaypointMouseDown },
    { 0, 517, (void*)(unsigned int)&TEXT_OnWaypointMouseUp },
    { 0, 258, (void*)(unsigned int)&TEXT_WaypointKeyMsg }
}; // 0x006D61C8
#pragma comment(linker, "/alternatename:?gaWaypointHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D61C8")

extern "C" const D2MsgHandlerEntryStrc gData_006D621C[2] = {
    { 0, 513, (void*)(unsigned int)&TEXT_OnRosterMouseDown },
    { 0, 514, (void*)(unsigned int)&sub_0049BDD0 }
}; // 0x006D621C
#pragma comment(linker, "/alternatename:?gaPartyScreenHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D621C")

extern const D2PanelHotkeysStrc gtMpTradeHotkeys = { 5, 7, 6, 10, 11, -1, 12, -1, (D2MsgHandlerEntryStrc *)&gaMpTradeHandlers }; // 0x006D6234

extern const D2PanelHotkeysStrc gtStashHotkeys = { 4, -1, 5, -1, -1, -1, 7, -1, (D2MsgHandlerEntryStrc *)&gaStashHandlers }; // 0x006D6258

extern const D2PanelHotkeysStrc gtCubeHotkeys = { 4, -1, 5, -1, -1, -1, -1, -1, (D2MsgHandlerEntryStrc *)&gaCubeHandlers }; // 0x006D627C

extern const D2PanelHotkeysStrc gtBeltRowsHotkeys = { 0, -1, 1, -1, -1, -1, -1, -1, (D2MsgHandlerEntryStrc *)&gaBeltRowsHandlers }; // 0x006D62A0

extern "C" const D2MsgHandlerEntryStrc gData_006D6318[3] = {
    { 0, 513, (void*)(unsigned int)&WARDENCLIENT_HandlePetIconClick },
    { 0, 512, (void*)(unsigned int)&HIREABLES_HirelingIconHoverMsg },
    { 0, 516, (void*)(unsigned int)&HIREABLES_HirelingIconClickMsg }
}; // 0x006D6318
#pragma comment(linker, "/alternatename:?gaHireIconHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6318")

extern "C" const D2MsgHandlerEntryStrc gData_006D633C[3] = {
    { 0, 513, (void*)(unsigned int)&INV_MercPanelClickMsg },
    { 0, 514, (void*)(unsigned int)&INV_MercInvClickMsg },
    { 0, 512, (void*)(unsigned int)&INV_MercPanelHoverMsg }
}; // 0x006D633C
#pragma comment(linker, "/alternatename:?gaMercInvHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D633C")

extern "C" const D2MsgHandlerEntryStrc gData_006D6360[2] = {
    { 0, 513, (void*)(unsigned int)&INV_CloseRecipeScrollClickMsg },
    { 0, 512, (void*)(unsigned int)&sub_0048BDF0_Nop }
}; // 0x006D6360
#pragma comment(linker, "/alternatename:?gaRecipeScrollHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6360")

extern D2MsgHandlerEntryStrc gaNpcShopHandlers[8] = {
    { 0, 516, (void*)(unsigned int)&INV_InventoryClickMsg },
    { 0, 513, (void*)(unsigned int)&sub_00491D20 },
    { 0, 514, (void*)(unsigned int)&sub_00488B00 },
    { 0, 512, (void*)(unsigned int)&INV_NpcShopMouseMoveMsg },
    { 3, 27, (void*)(unsigned int)&INV_ResetShopCursorMsg },
    { 3, 32, (void*)(unsigned int)&INV_ResetShopCursorMsg },
    { 3, 13, (void*)(unsigned int)&INV_OpenChatKeyMsg },
    { 3, 87, (void*)(unsigned int)&INV_WeaponSwapKeyMsg }
}; // 0x0070F878

extern D2MsgHandlerEntryStrc gaQuestScreenHandlers[7] = {
    { 0, 516, (void*)(unsigned int)&sub_004A3E40 },
    { 0, 517, (void*)(unsigned int)&TEXT_QuestLButtonUpMsg },
    { 0, 513, (void*)(unsigned int)&sub_004A3E40 },
    { 0, 514, (void*)(unsigned int)&TEXT_QuestLButtonUpMsg },
    { 3, 27, (void*)(unsigned int)&TEXT_CloseQuestPanelMsg },
    { 3, 27, (void*)(unsigned int)&TEXT_CloseQuestPanelMsg },
    { 3, 27, (void*)(unsigned int)&TEXT_CloseQuestPanelMsg }
}; // 0x0070F8D8

extern D2MsgHandlerEntryStrc gaMpTradeHandlers[13] = {
    { 0, 516, (void*)(unsigned int)&INV_ConsumeMsg },
    { 0, 517, (void*)(unsigned int)&INV_ConsumeMsg },
    { 0, 513, (void*)(unsigned int)&sub_00492310 },
    { 0, 514, (void*)(unsigned int)&INV_TradePanelMsg },
    { 0, 512, (void*)(unsigned int)&INV_TradeMouseMoveMsg },
    { 3, 27, (void*)(unsigned int)&INV_TradeCancelMsg },
    { 3, 32, (void*)(unsigned int)&INV_TradeCancelMsg },
    { 3, 192, (void*)(unsigned int)&INV_KeyNoRepeatMsg },
    { 3, 13, (void*)(unsigned int)&INV_OpenChatKeyMsg },
    { 3, 32, (void*)(unsigned int)&INV_TradeCancelMsg },
    { 3, 192, (void*)(unsigned int)&INV_KeyNoRepeatMsg },
    { 3, 78, (void*)(unsigned int)&SCMD_HandleResetMessage },
    { 3, 87, (void*)(unsigned int)&INV_WeaponSwapKeyMsg }
}; // 0x0070F930

extern D2MsgHandlerEntryStrc gaStashHandlers[8] = {
    { 0, 516, (void*)(unsigned int)&INV_InventoryClickMsg },
    { 0, 513, (void*)(unsigned int)&INV_StashButtonDownMsg },
    { 0, 514, (void*)(unsigned int)&INV_StashClickMsg },
    { 0, 512, (void*)(unsigned int)&INV_StashMouseMoveMsg },
    { 3, 27, (void*)(unsigned int)&INV_StashCloseMsg },
    { 3, 32, (void*)(unsigned int)&INV_StashCloseMsg },
    { 3, 13, (void*)(unsigned int)&INV_OpenChatKeyMsg },
    { 3, 87, (void*)(unsigned int)&INV_WeaponSwapKeyMsg }
}; // 0x0070F9D0

extern D2MsgHandlerEntryStrc gaCubeHandlers[7] = {
    { 0, 516, (void*)(unsigned int)&INV_InventoryClickMsg },
    { 0, 513, (void*)(unsigned int)&INV_CubeButtonUpMsg },
    { 0, 514, (void*)(unsigned int)&INV_CubeClickMsg },
    { 0, 512, (void*)(unsigned int)&INV_CubeMouseMoveMsg },
    { 3, 27, (void*)(unsigned int)&INV_CubeCloseMsg },
    { 3, 32, (void*)(unsigned int)&INV_CubeCloseMsg },
    { 3, 13, (void*)(unsigned int)&INV_OpenChatKeyMsg }
}; // 0x0070FA30

extern D2MsgHandlerEntryStrc gaBeltRowsHandlers[2] = {
    { 3, 32, (void*)(unsigned int)&PANEL_CloseUIVarsMsg },
    { 3, 32, (void*)(unsigned int)&PANEL_CloseUIVarsMsg }
}; // 0x0070FA84

extern int gbUIVarDelayEnabled = 1; // 0x0070FA9C

extern const D2ImmunityTextStrc gaImmunityTexts[6] = {
    { 36, 0x2765, 4 },
    { 37, 0x2766, 8 },
    { 39, 0x2761, 1 },
    { 41, 0x2763, 9 },
    { 43, 0x2762, 3 },
    { 45, 0x2764, 2 }
}; // 0x006D6418

extern const int gaUIVarDefaults[38] = {
    0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 1, 1
}; // 0x006D6378

extern "C" const D2MsgHandlerEntryStrc gData_006D6024[1] = { { 0, 522, (void*)(unsigned int)&TEXT_KeyConfigWheelMsg } }; // 0x006D6024
#pragma comment(linker, "/alternatename:?gaKeyConfigWheelHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6024")

extern "C" const D2MsgHandlerEntryStrc gData_006D6084[5] = {
    { 3, 38, (void*)(unsigned int)&AUTOMAP_DecreaseBaseY },
    { 3, 40, (void*)(unsigned int)&AUTOMAP_IncreaseBaseY },
    { 3, 39, (void*)(unsigned int)&AUTOMAP_IncreaseBaseX },
    { 3, 37, (void*)(unsigned int)&AUTOMAP_DecreaseBaseX },
    { 3, 35, (void*)(unsigned int)&sub_00457510_Nop }
}; // 0x006D6084
#pragma comment(linker, "/alternatename:?gaAutomapHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6084")

extern "C" const D2MsgHandlerEntryStrc gData_006D60C0[13] = {
    { 0, 513, (void*)(unsigned int)&ROSTERPETS_HandlePanelButtonDown },
    { 0, 514, (void*)(unsigned int)&TEXT_KeyConfigButtonUpMsg },
    { 0, 516, (void*)(unsigned int)&ROSTERPETS_HandlePanelButtonDown },
    { 0, 517, (void*)(unsigned int)&TEXT_KeyConfigButtonUpMsg },
    { 3, 40, (void*)(unsigned int)&TEXT_NextEntryMsg },
    { 3, 38, (void*)(unsigned int)&TEXT_PrevEntryMsg },
    { 3, 37, (void*)(unsigned int)&TEXT_SelectSecondaryColumnMsg },
    { 3, 39, (void*)(unsigned int)&TEXT_SelectPrimaryColumnMsg },
    { 3, 13, (void*)(unsigned int)&TEXT_ApplyEntryMsg },
    { 3, 46, (void*)(unsigned int)&TEXT_ClearEntryKeyMsg },
    { 3, 8, (void*)(unsigned int)&TEXT_ClearEntryKeyMsg },
    { 3, 27, (void*)(unsigned int)&TEXT_CancelKeyConfigMsg },
    { 3, 32, (void*)(unsigned int)&TEXT_CancelKeyConfigMsg }
}; // 0x006D60C0
#pragma comment(linker, "/alternatename:?gaKeyConfigHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D60C0")

extern "C" const struct d2data_006D6204_t gData_006D6204 = {
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02 },
    (const void*)(unsigned int)&MINIPANEL_SlotsClick,
    { 0x00, 0x00, 0x00, 0x00, 0x02, 0x02 },
    (const void*)(unsigned int)&MINIPANEL_SlotsClickMsg
}; // 0x006D6204
#pragma comment(linker, "/alternatename:?gtMiniPanelHandlers_006D6204@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6204")

extern "C" const struct d2data_006D62C4_t gData_006D62C4 = {
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02 },
    (const void*)(unsigned int)&ROSTERPETS_HandleHelpButtonDown,
    { 0x00, 0x00, 0x00, 0x00, 0x02, 0x02 },
    (const void*)(unsigned int)&INV_HelpCloseButtonMsg,
    { 0x03, 0x00, 0x00, 0x00, 0x20 },
    (const void*)(unsigned int)&INV_OnKeyCloseHelp,
    { 0x03, 0x00, 0x00, 0x00, 0x1B },
    (const void*)(unsigned int)&INV_OnKeyCloseHelp,
    { 0x00, 0x00, 0x00, 0x00, 0x02, 0x01 },
    (const void*)(unsigned int)&sub_00494FB0_Nop
}; // 0x006D62C4
#pragma comment(linker, "/alternatename:?gtUIVar33Handlers_006D62C4@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D62C4")

extern "C" const struct d2data_006D5F28_t gData_006D5F28 = {
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02 },
    (const void*)(unsigned int)&PANEL_OnMouseClick,
    { 0x00, 0x00, 0x00, 0x00, 0x02, 0x02 },
    (const void*)(unsigned int)&PANEL_BeltMouseReleaseMsg,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x02 },
    (const void*)(unsigned int)&PANEL_BeltMouseMove,
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x02 },
    (const void*)(unsigned int)&PANEL_BeltClickMsg
}; // 0x006D5F28
#pragma comment(linker, "/alternatename:?gaGameUIHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D5F28")

extern "C" const struct d2data_006D6300_t gData_006D6300 = {
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02 },
    (const void*)(unsigned int)&HIREABLES_ButtonDownMsg,
    { 0x00, 0x00, 0x00, 0x00, 0x02, 0x02 },
    (const void*)(unsigned int)&HIREABLES_ButtonUpMsg
}; // 0x006D6300
#pragma comment(linker, "/alternatename:?gaHelpButtonHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_006D6300")

extern "C" const char gszUiCpp[12] = ".\\UI\\ui.cpp"; // 0x006D6458

extern int gnUIVarCount = 38; // 0x0070F9CC

extern "C" struct d2data_0070FAA0_t gData_0070FAA0 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x0070FAA0

extern "C" struct d2data_0070FB38_t gData_0070FB38 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x0070FB38

extern "C" struct d2data_0070FBD0_t gData_0070FBD0 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x0070FBD0

extern "C" struct d2data_0070FC68_t gData_0070FC68 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x0070FC68

extern "C" struct d2data_0070FD00_t gData_0070FD00 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01
    }
}; // 0x0070FD00

extern "C" struct d2data_0070FD98_t gData_0070FD98 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x0070FD98

extern "C" struct d2data_0070FE30_t gData_0070FE30 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x0070FE30

extern "C" struct d2data_0070FEC8_t gData_0070FEC8 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02
    }
}; // 0x0070FEC8

extern "C" struct d2data_0070FF60_t gData_0070FF60 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01
    }
}; // 0x0070FF60

extern "C" struct d2data_0070FFF8_t gData_0070FFF8 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x0070FFF8

extern "C" struct d2data_00710090_t gData_00710090 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710090

extern "C" struct d2data_00710128_t gData_00710128 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01
    }
}; // 0x00710128

extern "C" struct d2data_007101C0_t gData_007101C0 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02
    }
}; // 0x007101C0

extern "C" struct d2data_00710258_t gData_00710258 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710258

extern "C" struct d2data_007102F0_t gData_007102F0 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x007102F0

extern "C" struct d2data_00710388_t gData_00710388 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01
    }
}; // 0x00710388

extern "C" struct d2data_00710420_t gData_00710420 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710420

extern "C" struct d2data_007104B8_t gData_007104B8 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x007104B8

extern "C" struct d2data_00710550_t gData_00710550 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710550

extern "C" struct d2data_007107B0_t gData_007107B0 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01
    }
}; // 0x007107B0

extern "C" struct d2data_00710848_t gData_00710848 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710848

extern "C" struct d2data_007108E0_t gData_007108E0 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02
    }
}; // 0x007108E0

extern "C" struct d2data_00710978_t gData_00710978 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710978

extern "C" struct d2data_00710A10_t gData_00710A10 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710A10

extern "C" struct d2data_00710AA8_t gData_00710AA8 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710AA8

extern "C" struct d2data_00710B40_t gData_00710B40 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710B40

extern "C" struct d2data_00710BD8_t gData_00710BD8 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710BD8

extern "C" struct d2data_00710C70_t gData_00710C70 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710C70

extern "C" struct d2data_00710D08_t gData_00710D08 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710D08

extern "C" struct d2data_00710DA0_t gData_00710DA0 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x01
    }
}; // 0x00710DA0

extern "C" struct d2data_00710E38_t gData_00710E38 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710E38

extern "C" struct d2data_00710ED0_t gData_00710ED0 = {
    {
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00710ED0

extern "C" struct d2data_00710F68_t gData_00710F68 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02
    }
}; // 0x00710F68

extern "C" struct d2data_00711000_t gData_00711000 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x01
    }
}; // 0x00711000

extern "C" struct d2data_00711098_t gData_00711098 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x02
    }
}; // 0x00711098

extern D2UIVarRecordStrc* gapUIVarRecords[38] = {
    (D2UIVarRecordStrc*)&gData_007A28A0, (D2UIVarRecordStrc*)&gData_0070FAA0, (D2UIVarRecordStrc*)&gData_0070FB38, (D2UIVarRecordStrc*)&gData_0070FBD0, (D2UIVarRecordStrc*)&gData_0070FC68, (D2UIVarRecordStrc*)&gData_0070FD00, (D2UIVarRecordStrc*)&gData_0070FD98, (D2UIVarRecordStrc*)&gData_0070FE30, (D2UIVarRecordStrc*)&gData_0070FEC8, (D2UIVarRecordStrc*)&gData_00710550, (D2UIVarRecordStrc*)&gData_0070FF60, (D2UIVarRecordStrc*)&gData_0070FFF8, (D2UIVarRecordStrc*)&gData_00710090, (D2UIVarRecordStrc*)&gData_00710128, (D2UIVarRecordStrc*)&gData_007101C0, (D2UIVarRecordStrc*)&gData_00710258,
    (D2UIVarRecordStrc*)&gData_007102F0, (D2UIVarRecordStrc*)&gData_00710388, (D2UIVarRecordStrc*)&gData_00710420, (D2UIVarRecordStrc*)&gData_007A2938, (D2UIVarRecordStrc*)&gData_007104B8, (D2UIVarRecordStrc*)&gData_007107B0, (D2UIVarRecordStrc*)&gData_00710848, (D2UIVarRecordStrc*)&gData_007108E0, (D2UIVarRecordStrc*)&gData_00710978, (D2UIVarRecordStrc*)&gData_00710A10, (D2UIVarRecordStrc*)&gData_00710AA8, (D2UIVarRecordStrc*)&gData_00710B40, (D2UIVarRecordStrc*)&gData_00710BD8, (D2UIVarRecordStrc*)&gData_00710C70, (D2UIVarRecordStrc*)&gData_00710D08, (D2UIVarRecordStrc*)&gData_00710DA0,
    (D2UIVarRecordStrc*)&gData_00710E38, (D2UIVarRecordStrc*)&gData_00710ED0, (D2UIVarRecordStrc*)&gData_00710F68, (D2UIVarRecordStrc*)&gData_007A29D0, (D2UIVarRecordStrc*)&gData_00711000, (D2UIVarRecordStrc*)&gData_00711098
}; // 0x00711130

extern int gnHoverX = -1; // 0x0070F854

extern int gnHoverY = -1; // 0x0070F858

extern "C" struct d2data_0070F818_t gData_0070F818 = {
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
    (const void*)"14"
}; // 0x0070F818
