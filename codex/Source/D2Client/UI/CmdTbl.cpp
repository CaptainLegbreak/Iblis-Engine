#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2ClientKeyConfig.h"
#include "D2Structs.h"
#include "D2PlayerModes.h"

#pragma intrinsic(memcpy)

#define NUM_HOTKEYS 114

#define NUM_HOTKEY_COMMANDS 0x39

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HotkeyCommandStrc;

struct D2HotkeyStrc;

struct D2MsgHandlerEntryStrc;

typedef void (__cdecl* HOTKEYCOMMANDFN)();

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);
















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































struct D2HotkeyCommandStrc
{
    HOTKEYCOMMANDFN pfnCommand;
    HOTKEYCOMMANDFN pfnUnk0x04;
    int nModeFlag;
};


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" int __cdecl isalpha(int c); // 0x00686DA5

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl CMDTBL_LoadHotkeyFile(); // 0x0046AAE0

extern D2HotkeyCommandStrc gaHotkeyCommands[]; // 0x00712698

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7404; // 0x007A7404

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7408; // 0x007A7408

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A6B10; // 0x007A6B10

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A740C; // 0x007A740C

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7414; // 0x007A7414

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A6B14; // 0x007A6B14

extern HOTKEYCOMMANDFN gpfnBoundCommand_007A7410; // 0x007A7410

extern D2MsgHandlerEntryStrc gaHotkeyHandlers[4]; // 0x00712944

extern D2MsgHandlerEntryStrc gaHotkeyUpHandlers[2]; // 0x00712974

void __cdecl CMDTBL_SaveHotkeyFile(); // 0x00469780

void __cdecl CMDTBL_BindMouseHotkeys(); // 0x004694A0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __cdecl GAME_CloseAllPanels(); // 0x0044C6B0

void __cdecl TEXT_ClearListFlags(); // 0x004A01E0

void __fastcall GAME_SetStandStillHeld(int nValue); // 0x0044BEA0

void __stdcall CMDTBL_LoadKeyConfig(int bInstallDir); // 0x004698D0

extern D2HotkeyStrc gaHotkeysSaved[NUM_HOTKEYS]; // 0x007A6B18

#define HOTKEY_COMMAND_LIMIT 0x38

struct D2KeyBindingStrc;

int __fastcall CMDTBL_IsValidKey(unsigned short nKey); // 0x00469AE0


#pragma pack(push, 1)

struct D2KeyBindingStrc { int nAction; unsigned short nKey; char unk_06[4]; };

#pragma pack(pop)

extern int gnMode_007A7418; // 0x007A7418

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

struct Unicode;

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

// build: symbol ??__EgwszKeyText_007A741C@@YAXXZ 0x006CAAD0
Unicode gwszKeyText_007A741C[4]; // 0x007A741C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960
int __fastcall FOG_CloseFile(void* hFile); // 0x004069A0

int __fastcall FOG_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x004069B0

enum D2C_CmdTblConstants
{
    VK_MENU = 0x12,
    VK_F4 = 0x73,
};

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

#define BODYLOC_BELT 8

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

int __cdecl GAME_IsExitPending(); // 0x0044DA30

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0

void __fastcall AUTOMAP_ResetBaseOffset(int bForce); // 0x00457640

int __cdecl AUTOMAP_GetAutomapFade(); // 0x004576C0

int __fastcall AUTOMAP_SetAutomapFade(int nFade); // 0x004576F0

int __cdecl AUTOMAP_GetAutomapParty(); // 0x004577B0

int __cdecl AUTOMAP_GetAutomapPartyNames(); // 0x004577E0

int __cdecl AUTOMAP_GetAutomapLeft(); // 0x00457770

int __fastcall AUTOMAP_SaveAutomapLeft(int nValue); // 0x00457780

void __fastcall SPELLSEL_SetSkillSelectRight(int nValue); // 0x004A8CE0

void __fastcall SPELLSEL_AssignHotkey(int nHotkey); // 0x004A9E60

void __fastcall SPELLSEL_SelectHotkey(int nSlot); // 0x004AA030

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

void __fastcall GAME_SetRunKeyHeld(int nValue); // 0x0044BE60

int __cdecl GAME_GetAlwaysRun(); // 0x0044BE90

void __fastcall GAME_SetAlwaysRun(int bAlwaysRun); // 0x0044BE80

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nMode); // 0x00480E70

void __fastcall MSG_SendHeaderOnly(char nValue); // 0x00478590

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __cdecl NPCMENU_IsAnyDialogOpen(); // 0x004B34A0

int __cdecl TEXT_IsTextBoxOpen(); // 0x004A0000

void __fastcall sub_0047E200_CloseMenus(int nArg); // 0x0047E200

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __fastcall WARDENCLIENT_ToggleEscMenuUIState(int bSaveState, int nMenu); // 0x0047E090

void __fastcall SPELLSEL_CycleHotkey(int nDelta); // 0x004AA740

void __cdecl INV_ResetEquipSounds(); // 0x0048A730

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

void (__cdecl* gpfnMButtonDownCommand)(); // 0x007A6B10

void (__cdecl* gpfnMButtonUpCommand)(); // 0x007A740C

void (__cdecl* gpfnXButton1DownCommand)(); // 0x007A7414

void (__cdecl* gpfnXButton1UpCommand)(); // 0x007A6B14

void (__cdecl* gpfnXButton2DownCommand)(); // 0x007A7410

// 0x00468940
void __cdecl CMDTBL_SetUIVar2()
{
    UI_SetUIVar(2, 2, 1);
}

// 0x00468950
void __cdecl CMDTBL_SetUIVar1()
{
    UI_SetUIVar(1, 2, 1);
}

// 0x00468960
void __cdecl CMDTBL_SetUIVar22()
{
    if (GAME_GetConnectionType())
        UI_SetUIVar(0x16, 2, 1);
}

// 0x00468980
void __cdecl CMDTBL_SetUIVar24()
{
    UI_SetUIVar(0x18, 2, 0);
}

// 0x00468990
void __cdecl CMDTBL_OpenMode1()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
        QUESTLOG_ToggleQuestLog(1);
}

// 0x004689B0
void __cdecl CMDTBL_SetUIVar5()
{
    if (!GAME_IsExitPending())
        UI_SetUIVar(5, 2, 0);
}

// 0x00468A30
void __cdecl CMDTBL_SetUIVar10()
{
    UI_SetUIVar(0xA, 2, 0);
    if (!GAME_GetUIVarState(0xA))
        AUTOMAP_ResetBaseOffset(0);
}

// 0x00468A60
void __cdecl CMDTBL_Force()
{
    AUTOMAP_ResetBaseOffset(1);
}

// 0x00468A70
void __cdecl CMDTBL_CycleSetting()
{
    AUTOMAP_SetAutomapFade((AUTOMAP_GetAutomapFade() + 1) % 4);
}

// 0x00468A90
void __cdecl sub_00468A90_ToggleSetting()
{
    sub_004577C0_SetValue(!AUTOMAP_GetAutomapParty());
}

// 0x00468AB0
void __cdecl sub_00468AB0_ToggleSetting()
{
    sub_004577F0_SetValue(!AUTOMAP_GetAutomapPartyNames());
}

// 0x00468AD0
void __cdecl sub_00468AD0_ToggleSetting()
{
    AUTOMAP_SaveAutomapLeft(!AUTOMAP_GetAutomapLeft());
}

// 0x00468AF0
void __cdecl CMDTBL_SetUIVar4()
{
    UI_SetUIVar(4, 2, 1);
}

// 0x00468B00
void __cdecl CMDTBL_SetUIVar3()
{
    UI_SetUIVar(3, 2, 0);
    SPELLSEL_SetSkillSelectRight(0);
}

// 0x00468B90
void __cdecl CMDTBL_Hotkey0()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(0);
        else
            SPELLSEL_SelectHotkey(0);
    }
}

// 0x00468BC0
void __cdecl CMDTBL_Hotkey1()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(1);
        else
            SPELLSEL_SelectHotkey(1);
    }
}

// 0x00468BF0
void __cdecl CMDTBL_Hotkey2()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(2);
        else
            SPELLSEL_SelectHotkey(2);
    }
}

// 0x00468C20
void __cdecl CMDTBL_Hotkey3()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(3);
        else
            SPELLSEL_SelectHotkey(3);
    }
}

// 0x00468C50
void __cdecl CMDTBL_Hotkey4()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(4);
        else
            SPELLSEL_SelectHotkey(4);
    }
}

// 0x00468C80
void __cdecl CMDTBL_Hotkey5()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(5);
        else
            SPELLSEL_SelectHotkey(5);
    }
}

// 0x00468CB0
void __cdecl CMDTBL_Hotkey6()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(6);
        else
            SPELLSEL_SelectHotkey(6);
    }
}

// 0x00468CE0
void __cdecl CMDTBL_Hotkey7()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(7);
        else
            SPELLSEL_SelectHotkey(7);
    }
}

// 0x00468D10
void __cdecl CMDTBL_Hotkey8()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(8);
        else
            SPELLSEL_SelectHotkey(8);
    }
}

// 0x00468D40
void __cdecl CMDTBL_Hotkey9()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing() && GAME_IsExpansion())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(9);
        else
            SPELLSEL_SelectHotkey(9);
    }
}

// 0x00468D80
void __cdecl CMDTBL_Hotkey10()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing() && GAME_IsExpansion())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(10);
        else
            SPELLSEL_SelectHotkey(10);
    }
}

// 0x00468DC0
void __cdecl CMDTBL_Hotkey11()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing() && GAME_IsExpansion())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(11);
        else
            SPELLSEL_SelectHotkey(11);
    }
}

// 0x00468E00
void __cdecl CMDTBL_Hotkey12()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing() && GAME_IsExpansion())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(12);
        else
            SPELLSEL_SelectHotkey(12);
    }
}

// 0x00468E40
void __cdecl CMDTBL_Hotkey13()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing() && GAME_IsExpansion())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(13);
        else
            SPELLSEL_SelectHotkey(13);
    }
}

// 0x00468E80
void __cdecl CMDTBL_Hotkey14()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing() && GAME_IsExpansion())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(14);
        else
            SPELLSEL_SelectHotkey(14);
    }
}

// 0x00468EC0
void __cdecl CMDTBL_Hotkey15()
{
    if (!GAME_IsExitPending() && !CUNIT_IsPlayerDeadOrMissing() && GAME_IsExpansion())
    {
        if (GAME_GetUIVarState(3))
            SPELLSEL_AssignHotkey(15);
        else
            SPELLSEL_SelectHotkey(15);
    }
}

// 0x00468F00
void __cdecl sub_00468F00()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, BODYLOC_BELT);
        if (pItem && ITEMSIsA(pItem, ITEMTYPE_BELT))
        {
            UI_SetUIVar(0x1F, 2, 0);
        }
    }
}

void __cdecl PANEL_BeltHotkeyFirst(); // 0x00498C50

void __cdecl PANEL_BeltHotkeySecond(); // 0x00498C90

void __cdecl PANEL_BeltHotkeyThird(); // 0x00498CD0

void __cdecl PANEL_BeltHotkeyFourth(); // 0x00498D10

// 0x00468F40
void __cdecl CMDTBL_BeltHotkey0()
{
    PANEL_BeltHotkeyFirst();
}

// 0x00468F50
void __cdecl CMDTBL_BeltHotkey1()
{
    PANEL_BeltHotkeySecond();
}

// 0x00468F60
void __cdecl CMDTBL_BeltHotkey2()
{
    PANEL_BeltHotkeyThird();
}

// 0x00468F70
void __cdecl CMDTBL_BeltHotkey3()
{
    PANEL_BeltHotkeyFourth();
}

// 0x00468F80
void __cdecl CMDTBL_Phrase19()
{
    MSG_SendWord(0x3F, 0x19);
}

// 0x00468F90
void __cdecl CMDTBL_Phrase1A()
{
    MSG_SendWord(0x3F, 0x1A);
}

// 0x00468FA0
void __cdecl CMDTBL_Phrase1B()
{
    MSG_SendWord(0x3F, 0x1B);
}

// 0x00468FB0
void __cdecl CMDTBL_Phrase1C()
{
    MSG_SendWord(0x3F, 0x1C);
}

// 0x00468FC0
void __cdecl CMDTBL_Phrase1D()
{
    MSG_SendWord(0x3F, 0x1D);
}

// 0x00468FD0
void __cdecl CMDTBL_Phrase1E()
{
    MSG_SendWord(0x3F, 0x1E);
}

// 0x00468FE0
void __cdecl CMDTBL_Phrase1F()
{
    MSG_SendWord(0x3F, 0x1F);
}

// 0x00468FF0
void __cdecl CMDTBL_Phrase20()
{
    MSG_SendWord(0x3F, 0x20);
}

// 0x00469000
void __cdecl CMDTBL_HotkeyRunOn()
{
    GAME_SetRunKeyHeld(1);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    if (GAME_IsExitPending())
        return;
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    if (pPlayer->dwUnitType != UNIT_PLAYER)
        return;
    if (pPlayer->dwAnimMode != PLRMODE_WALK)
        return;
    if (!STATLIST_UnitGetStatValue(pPlayer, STAT_STAMINA, 0))
        return;
    UNITMODE_SetUnitMode(pPlayer, 3);
    MSG_SendHeaderOnly(0x53);
}

// 0x00469060
void __cdecl CMDTBL_ToggleAlwaysRun()
{
    GAME_SetAlwaysRun(!GAME_GetAlwaysRun());
}

// 0x00469080
void __cdecl CMDTBL_HotkeySetValue()
{
    GAME_SetStandStillHeld(1);
}

// 0x00469090
void __cdecl CMDTBL_HotkeyUiVarOff()
{
    UI_SetUIVar(0xD, 0, 0);
}

// 0x004690A0
void __cdecl CMDTBL_HotkeyClearScreen()
{
    GAME_CloseAllPanels();
}

// 0x004690B0
void __cdecl CMDTBL_HotkeyEscape()
{
    if (NPCMENU_IsAnyDialogOpen())
        return;
    if (TEXT_IsTextBoxOpen())
        return;
    if (GAME_GetUIVarState(9))
    {
        sub_0047E200_CloseMenus(1);
        return;
    }
    if (UI_CloseUIVars(0, 1))
        return;
    WARDENCLIENT_ToggleEscMenuUIState(1, 0);
}

// 0x00469100
void __cdecl CMDTBL_HotkeyPrevSkill()
{
    if (GAME_IsExitPending())
        return;
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    SPELLSEL_CycleHotkey(-1);
}

// 0x00469120
void __cdecl CMDTBL_HotkeyNextSkill()
{
    if (GAME_IsExitPending())
        return;
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    SPELLSEL_CycleHotkey(1);
}

// 0x00469140
void __cdecl CMDTBL_HotkeyResetSounds()
{
    if (GAME_GetUIVarState(0xC))
        return;
    if (GAME_GetUIVarState(0x17))
        return;
    if (GAME_GetUIVarState(0x19))
        return;
    INV_ResetEquipSounds();
}

// 0x00469170
void __cdecl CMDTBL_HotkeyPetUi()
{
    if (!GAME_IsExpansion())
        return;
    if (ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) == -1)
        return;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (!FOG_IsExpansion())
        return;
    UI_SetUIVar(0x24, 2, 1);
}

// 0x004691B0
void __cdecl CMDTBL_HotkeyClearMessages()
{
    TEXT_ClearListFlags();
}

// 0x004691C0
void __cdecl CMDTBL_HotkeyRunOff()
{
    GAME_SetRunKeyHeld(0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    if (GAME_GetAlwaysRun())
        return;
    if (pPlayer->dwUnitType != UNIT_PLAYER)
        return;
    if (pPlayer->dwAnimMode != PLRMODE_RUN)
        return;
    UNITMODE_SetUnitMode(pPlayer, 2);
    MSG_SendHeaderOnly(0x54);
}

// 0x00469200
void __cdecl CMDTBL_HotkeyStandStillRelease()
{
    GAME_SetStandStillHeld(0);
}

HOTKEYCOMMANDFN gpfnXButton2UpCommand; // 0x007A6F8C

int gnHotkeyMode; // 0x007A7418

int gbHotkeyUpHandlersSet; // 0x007A7424

int gbHotkeyHandlersRegistered; // 0x007A7428

// 0x00469210
void __cdecl CMDTBL_HotkeyUiVarOn()
{
    UI_SetUIVar(0xD, 1, 0);
    SELECT_ClearSelection();
}

// 0x00469230
void __cdecl sub_00469230()
{
    if (gpfnMButtonDownCommand)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnMButtonDownCommand), 0x339);
        gpfnMButtonDownCommand();
    }
}

// 0x00469270
void __cdecl sub_00469270()
{
    if (gpfnMButtonUpCommand)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnMButtonUpCommand), 0x345);
        gpfnMButtonUpCommand();
    }
}

// 0x004692B0
void __cdecl sub_004692B0()
{
    if (gpfnXButton1DownCommand)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnXButton1DownCommand), 0x350);
        gpfnXButton1DownCommand();
    }
}

// 0x004692F0
void __cdecl sub_004692F0()
{
    if (gpfnXButton1UpCommand)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnXButton1UpCommand), 0x35D);
        gpfnXButton1UpCommand();
    }
}

// 0x00469330
void __cdecl sub_00469330()
{
    if (gpfnXButton2DownCommand)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnXButton2DownCommand), 0x369);
        gpfnXButton2DownCommand();
    }
}

// 0x00469370
void __cdecl CMDTBL_CallBoundCommand()
{
    if (gpfnXButton2UpCommand)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnXButton2UpCommand), 0x375);
        gpfnXButton2UpCommand();
    }
}

static inline int HOTKEY_CheckWheelKey(int nCommand, int nKey)
{
    switch (nKey)
    {
    case KEY_WHEEL_UP:
    case KEY_WHEEL_DOWN:
        if (gaHotkeyCommands[nCommand].pfnUnk0x04)
        {
            return 0;
        }
        break;
    }
    return 1;
}

D2WheelCallbackFn gpfnWheelUp; // 0x007A7404

D2WheelCallbackFn gpfnWheelDown; // 0x007A7408

typedef int (__stdcall* D2FarProcFn)();


// 0x004693B0
void __fastcall CUNIT_DispatchMouseWheel(int nSteps)
{
    if (nSteps > 0)
    {
        if (gpfnWheelUp)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelUp), 0x383);
            gpfnWheelUp();
        }
    }
    else if (nSteps < 0)
    {
        if (gpfnWheelDown)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelDown), 0x38B);
            gpfnWheelDown();
        }
    }
}

struct D2SortEntryStrc;


struct D2SortEntryStrc
{
    int nKey;
    unsigned char unk0x04[2];
    unsigned char nFlag[4];
};


extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C


class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

// 0x00469420
// Kept out of line: 0x00469C20 calls it with its arguments in eax/edx/ecx, a convention only a static of this unit
// gets, so it is this unit's function; with /Ob2 it would otherwise be inlined there.
static __declspec(noinline) int sub_00469420_CheckWheelKey(int nId, unsigned short nKey, unsigned short* pKey)
{
    switch (nKey)
    {
    case KEY_WHEEL_UP:
    case KEY_WHEEL_DOWN:
        if (gaHotkeyCommands[nId].pfnUnk0x04)
        {
            if (pKey)
            {
                *pKey = 0xF8A;
            }
            return 0;
        }
        break;
    }
    return 1;
}

// 0x00469450
int __cdecl SCMD_CompareSortEntries(const void* pA, const void* pB)
{
    const D2SortEntryStrc* pLeft = (const D2SortEntryStrc*)pA;
    const D2SortEntryStrc* pRight = (const D2SortEntryStrc*)pB;
    if (pLeft->nKey < pRight->nKey)
    {
        return -1;
    }
    if (pLeft->nKey > pRight->nKey)
    {
        return 1;
    }
    if (*(const int*)pLeft->nFlag)
    {
        return *(const int*)pRight->nFlag ? 0 : -1;
    }
    return *(const int*)pRight->nFlag ? 1 : 0;
}

// 0x004694A0
void __cdecl CMDTBL_BindMouseHotkeys()
{
    gpfnBoundCommand_007A7404 = 0;
    gpfnBoundCommand_007A7408 = 0;
    gpfnBoundCommand_007A6B10 = 0;
    gpfnBoundCommand_007A740C = 0;
    gpfnBoundCommand_007A7414 = 0;
    gpfnBoundCommand_007A6B14 = 0;
    gpfnBoundCommand_007A7410 = 0;
    gpfnXButton2UpCommand = 0;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey > 0xDF && gtHotkeys_007A6F90[i].nCommand < NUM_HOTKEY_COMMANDS)
        {
            switch (gtHotkeys_007A6F90[i].nKey)
            {
            case 0x100:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A6B10 = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A740C = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case 0x101:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7414 = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnBoundCommand_007A6B14 = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case 0x102:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7410 = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    gpfnXButton2UpCommand = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnUnk0x04;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case KEY_WHEEL_UP:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7404 = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            case KEY_WHEEL_DOWN:
                if (HOTKEY_CheckWheelKey(gtHotkeys_007A6F90[i].nCommand, gtHotkeys_007A6F90[i].nKey))
                {
                    gpfnBoundCommand_007A7408 = gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand;
                    break;
                }
                gtHotkeys_007A6F90[i].nKey = 0xFFFF;
                break;
            }
        }
    }
}


struct D2HotkeyFileStrc
{
    unsigned short nVersion;
    D2HotkeyStrc aKeys[114];
};

struct D2KeyConfigHeaderStrc
{
    unsigned short f_0;
    unsigned short nVersion;
    unsigned short nSize;
};

#define HOTKEY_FILE_VERSION 0x25

#define HOTKEY_NUM_COMMANDS 0x39

#define INVALID_HANDLE_VALUE ((void*)-1)

#define GENERIC_READ 0x80000000

#define OPEN_EXISTING 3

#define FILE_ATTRIBUTE_NORMAL 0x80

int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050

int __fastcall FOG_CreatePathHierarchy(const char* szPath);                                        // 0x00406A10

int __fastcall FOG_WriteFile(void* hFile, const void* pBuffer, unsigned long nSize, unsigned long* pWritten, void* pOverlapped); // 0x004069D0

extern char gszRealm[];                                                                    // 0x007A0500

extern char gszClientCharName[];                                                                         // 0x007A05C4

// 0x00469650
static void* CMDTBL_OpenKeyFile(unsigned long dwDesiredAccess, unsigned long dwCreationDisposition)
{
    char szSavePath[0x104] = { 0 };
    char szFileName[0x104] = { 0 };
    char szDir[0x104] = { 0 };
    FOG_GetSavePath(szSavePath, sizeof(szSavePath));
    if (gszRealm[0])
    {
        SStrPrintf(szDir, sizeof(szDir), "%s%s\\", szSavePath, gszRealm);
        FOG_CreatePathHierarchy(szDir);
        SStrPrintf(szFileName, sizeof(szFileName), "%s%s.key", szDir, gszClientCharName);
        void* hFile = FOG_CreateFileA(szFileName, dwDesiredAccess, 0, 0, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, 0);
        if (hFile != INVALID_HANDLE_VALUE)
        {
            return hFile;
        }
    }

    SStrPrintf(szFileName, sizeof(szFileName), "%s%s.key", szSavePath, gszClientCharName);
    return FOG_CreateFileA(szFileName, dwDesiredAccess, 0, 0, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, 0);
}

// 0x00469780
void __cdecl CMDTBL_SaveHotkeyFile()
{
    void* hFile = CMDTBL_OpenKeyFile(GENERIC_WRITE, CREATE_ALWAYS);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return;
    }

    D2HotkeyFileStrc tFile = { 0 };
    unsigned long nWritten = 0;
    tFile.nVersion = HOTKEY_FILE_VERSION;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        tFile.aKeys[i].nKey = HOTKEY_UNBOUND;
    }
    memcpy(tFile.aKeys, gtHotkeys_007A6F90, sizeof(tFile.aKeys));
    FOG_WriteFile(hFile, &tFile, sizeof(tFile), &nWritten, 0);
    FOG_CloseFile(hFile);

    char szPath[0x104];
    FOG_GetInstallPath(szPath, 0xDC);
    strcat(szPath, "default.key");
    hFile = FOG_CreateFileA(szPath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return;
    }

    D2KeyConfigHeaderStrc tHeader;
    tHeader.f_0 = 0x5357;
    tHeader.nVersion = HOTKEY_FILE_VERSION;
    tHeader.nSize = 0x47A;
    FOG_WriteFile(hFile, &tHeader, sizeof(tHeader), &nWritten, 0);
    FOG_WriteFile(hFile, gtHotkeys_007A6F90, sizeof(gtHotkeys_007A6F90), &nWritten, 0);
    FOG_CloseFile(hFile);
}

// 0x004698D0
void __stdcall CMDTBL_LoadKeyConfig(int bInstallDir)
{
    char szLang[4];
    char szPath[0x104];
    D2KeyConfigFileStrc tFile;
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
    STRTABLE_GetLanguageInfoField(szLang, 0);
    void* pData;
    int bLoaded = 0;
    if (bInstallDir)
    {
        FOG_GetInstallPath(szPath, 0xDC);
        strcat(szPath, "default.key");
        void* hFile = FOG_CreateFileA(szPath, 0x80000000, 0, 0, 3, 0x80, 0);
        if (hFile != (void*)-1)
        {
            unsigned long nRead;
            FOG_ReadFile(hFile, &tFile, sizeof(tFile), &nRead, 0);
            FOG_CloseFile(hFile);
            if (nRead == sizeof(tFile))
            {
                pData = FOG_AllocPool(0, sizeof(tFile), ".\\UI\\CmdTbl.cpp", 0x50F, 0);
                memcpy(pData, &tFile, sizeof(tFile));
                bLoaded = 1;
            }
        }
    }
    if (!bLoaded)
    {
        sprintf(szPath, "%s\\CMD\\%s\\default.key", szDataLocal_006D41A8, szLang);
        pData = ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szPath, 0, ".\\UI\\CmdTbl.cpp", 0x51E);
    }
    if (!pData)
        return;
    D2KeyConfigFileStrc* pFile = (D2KeyConfigFileStrc*)pData;
    if (pFile->wTag == 0x5357 && pFile->wVersion == 0x25 && pFile->wSize == sizeof(D2KeyConfigFileStrc))
    {
// build: symbol ?gaKeyTable@* 0x00712220
        memcpy(gaKeyTable, pFile->aBody, sizeof(gaKeyTable));
        FOG_Free(pData, ".\\UI\\CmdTbl.cpp", 0x52C, 0);
        return;
    }
    FOG_Free(pData, ".\\UI\\CmdTbl.cpp", 0x531, 0);
}

// 0x00469A50
static inline void CMDTBL_LoadKeyConfigInline(int bInstallDir)
{
    CMDTBL_LoadKeyConfig(bInstallDir);
}

// 0x00469A60
void __fastcall CMDTBL_ResetKeyConfig(int bInstallDir)
{
    CMDTBL_LoadKeyConfig(bInstallDir);
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        gtHotkeys_007A6F90[i].nKey = HOTKEY_UNBOUND;
    }
    memcpy(gtHotkeys_007A6F90, gaKeyTable, sizeof(gtHotkeys_007A6F90));
    CMDTBL_BindMouseHotkeys();
}

// 0x00469AE0
int __fastcall CMDTBL_IsValidKey(unsigned short nKey)
{
    switch (nKey)
    {
    case 0x08: case 0x09: case 0x0C: case 0x0D: case 0x10: case 0x11:
    case 0x12: case 0x13: case 0x14: case 0x20: case 0x21: case 0x22:
    case 0x23: case 0x24: case 0x2A: case 0x2C: case 0x2D: case 0x2E:
    case 0x2F: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64:
    case 0x65: case 0x66: case 0x67: case 0x68: case 0x69: case 0x6A:
    case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: case 0x70:
    case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76:
    case 0x77: case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C:
    case 0x7D: case 0x7E: case 0x7F: case 0x80: case 0x81: case 0x82:
    case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x91:
    case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF:
    case 0xC0: case 0xDB: case 0xDC: case 0xDD: case 0xDE: case 0x100:
    case 0x101: case 0x102: case 0x103: case 0x104:
        return 1;
    case 0x01: case 0x02: case 0x03: case 0x04: case 0x15: case 0x17:
    case 0x18: case 0x19: case 0x1B: case 0x1C: case 0x1D: case 0x1E:
    case 0x1F: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29:
    case 0x2B: case 0x5B: case 0x5C: case 0x5D: case 0x90:
        return 0;
    }
    if (isalpha(nKey) || isdigit(nKey))
    {
        return 1;
    }
    return 0;
}

// 0x00469C20
int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey)
{
    const unsigned short nKey = (unsigned short)nCommand;
    if (pKey)
    {
        *pKey = 0;
    }
    if (nId > HOTKEY_COMMAND_LIMIT || nId == HOTKEY_COMMAND_LIMIT)
    {
        return 0;
    }

    int bError = 1;
    if (CMDTBL_IsValidKey(nKey))
    {
        if (!sub_00469420_CheckWheelKey(nId, nKey, pKey))
        {
            return 0;
        }
        bError = nKey == 0x2C && gaHotkeyCommands[nId].pfnCommand;
    }
    if (bError)
    {
        if (pKey)
        {
            *pKey = 0xF8B;
        }
        return 0;
    }

    int nFree = NUM_HOTKEYS;
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey == nKey)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
            nFree = i;
            break;
        }
    }
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nId && gtHotkeys_007A6F90[i].nMode == nMode)
        {
            gtHotkeys_007A6F90[i].nKey = nKey;
            return 1;
        }
    }
    if (nFree != NUM_HOTKEYS)
    {
        gtHotkeys_007A6F90[nFree].nKey = nKey;
    }
    return 0;
}

void __fastcall sub_M110_Emit_00469A50(int bInstallDir)
{
    CMDTBL_LoadKeyConfigInline(bInstallDir + 1);
}

// 0x00469D20
void __cdecl CMDTBL_SaveHotkeys()
{
    memcpy(gaHotkeysSaved, gtHotkeys_007A6F90, sizeof(gtHotkeys_007A6F90));
    CMDTBL_BindMouseHotkeys();
}

// 0x00469D70
void __fastcall CUNIT_ClearHotkeyBinding(int nId, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (nId == gtHotkeys_007A6F90[i].nCommand && nB == gtHotkeys_007A6F90[i].nMode)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
        }
    }
}

// 0x00469D90
int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB)
{
    return CUNIT_GetHotkeyBinding(nA, nB) != 0xFFFF;
}

// 0x0046A840
void __stdcall SCMD_HandleHotkeyMessage(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam & 0x40000000)
    {
        return;
    }

    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nKey == pMsg->wParam && gtHotkeys_007A6F90[i].nCommand != 0xFFFF
            && gtHotkeys_007A6F90[i].nCommand < NUM_HOTKEY_COMMANDS && gtHotkeys_007A6F90[i].nCommand <= 0xDF
            && gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand)
        {
            if (gtHotkeys_007A6F90[i].nKey == VK_F4 && (GetKeyState(VK_MENU) & 0x8000))
            {
                return;
            }

            if (gnHotkeyMode == 2 && !gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].nModeFlag)
            {
                return;
            }

            D2_ASSERT(!IsBadCodePtr((FARPROC)gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand), 2038);
            gaHotkeyCommands[gtHotkeys_007A6F90[i].nCommand].pfnCommand();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}

// 0x0046AA20
void __fastcall CMDTBL_SetHotkeyHandlers(int bEnable, int bFlag)
{
    gnHotkeyMode = bEnable;
    if (bEnable)
    {
        if (gbHotkeyHandlersRegistered == 0)
        {
            gbHotkeyHandlersRegistered = 1;
            if (bFlag && gbHotkeyUpHandlersSet != 0)
            {
                sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHotkeyUpHandlers, 2);
                gbHotkeyUpHandlersSet = 0;
            }
            SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHotkeyHandlers, 4);
        }
    }
    else
    {
        if (gbHotkeyHandlersRegistered == 1)
        {
            gbHotkeyHandlersRegistered = 0;
            sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHotkeyHandlers, 4);
            if (bFlag && gbHotkeyUpHandlersSet == 0)
            {
                SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHotkeyUpHandlers, 2);
                gbHotkeyUpHandlersSet = 1;
            }
        }
    }
}

// 0x0046AAE0
void __cdecl CMDTBL_LoadHotkeyFile()
{
    void* hFile = CMDTBL_OpenKeyFile(GENERIC_READ, OPEN_EXISTING);
    if (hFile != INVALID_HANDLE_VALUE)
    {
        D2HotkeyFileStrc tFile = { 0 };
        unsigned long nRead = 0;
        FOG_ReadFile(hFile, &tFile, sizeof(tFile), &nRead, 0);
        FOG_CloseFile(hFile);
        if (nRead != sizeof(tFile) || tFile.nVersion != HOTKEY_FILE_VERSION)
        {
            goto LOAD_DEFAULT;
        }

        for (int nCommand = 0; nCommand < HOTKEY_NUM_COMMANDS; ++nCommand)
        {
            int bFound = 0;
            for (int i = 0; i < NUM_HOTKEYS && !bFound; ++i)
            {
                if (tFile.aKeys[i].nCommand == nCommand)
                {
                    bFound = 1;
                }
            }

            if (!bFound)
            {
                goto LOAD_DEFAULT;
            }
        }

        for (int i = 0; i < NUM_HOTKEYS; ++i)
        {
            for (int j = 0; j < NUM_HOTKEYS; ++j)
            {
                if (tFile.aKeys[i].nKey != HOTKEY_UNBOUND && i != j && tFile.aKeys[i].nKey == tFile.aKeys[j].nKey)
                {
                    goto LOAD_DEFAULT;
                }
            }
        }

        for (int i = 0; i < NUM_HOTKEYS; ++i)
        {
            gtHotkeys_007A6F90[i].nKey = HOTKEY_UNBOUND;
        }
        memcpy(gtHotkeys_007A6F90, tFile.aKeys, sizeof(gtHotkeys_007A6F90));
        CMDTBL_BindMouseHotkeys();
        return;
    }

LOAD_DEFAULT:
    CMDTBL_LoadKeyConfig(1);
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        gtHotkeys_007A6F90[i].nKey = HOTKEY_UNBOUND;
    }
// build: symbol ?gaKeyTable@* 0x00712220
    memcpy(gtHotkeys_007A6F90, gaKeyTable, sizeof(gtHotkeys_007A6F90));
    CMDTBL_BindMouseHotkeys();
    CMDTBL_SaveHotkeyFile();
}

// 0x0046AC70
void __cdecl CMDTBL_EnableHotkeyHandlers()
{
    CMDTBL_LoadHotkeyFile();
    gnHotkeyMode = 1;
    if (gbHotkeyHandlersRegistered == 0)
    {
        gbHotkeyHandlersRegistered = 1;
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaHotkeyHandlers, 4);
    }
}

// 0x00469AA0
unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// 0x0046ACB0
void __cdecl CMDTBL_DisableHotkeyHandlers()
{
    gnHotkeyMode = 0;
    if (gbHotkeyHandlersRegistered == 1)
    {
        gbHotkeyHandlersRegistered = 0;
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaHotkeyHandlers, 4);
    }
}

static inline unsigned short FindHotkeyKey_Inline(int nId, int nMode)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nId && gtHotkeys_007A6F90[i].nMode == nMode)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }
    return 0xFFFF;
}

// 0x00469D40
void __cdecl CMDTBL_SaveAndBindHotkeys()
{
    CMDTBL_SaveHotkeyFile();
    CMDTBL_BindMouseHotkeys();
}

D2KeyBindingStrc gaHotkeys[114]; // 0x007A6F90

// 0x00469D50
void __cdecl CMDTBL_RestoreHotkeys()
{
    memcpy(gtHotkeys_007A6F90, gaHotkeysSaved, sizeof(gtHotkeys_007A6F90));
    CMDTBL_BindMouseHotkeys();
}

// 0x00469DE0
const Unicode* __fastcall CMDTBL_GetKeyText(int nA, int nB)
{
    const unsigned short nKey = CUNIT_GetHotkeyBinding(nA, nB);
    if (nKey == 0xFFFF)
    {
        return D2LANG_GetStringFromTblIndex(0xEB2);
    }

    if (nKey > 0xDF)
    {
        switch (nKey)
        {
        case 0x103:
            return D2LANG_GetStringFromTblIndex(0xEB9);

        case 0x104:
            return D2LANG_GetStringFromTblIndex(0xEBA);

        case 0x100:
            return D2LANG_GetStringFromTblIndex(0xEB6);

        case 0x101:
            return D2LANG_GetStringFromTblIndex(0xEB7);

        case 0x102:
            return D2LANG_GetStringFromTblIndex(0xEB8);
        }
    }
    else
    {
        switch (nKey)
        {
        case 0x1:
            return D2LANG_GetStringFromTblIndex(0xEB3);

        case 0x2:
            return D2LANG_GetStringFromTblIndex(0xEB4);

        case 0x3:
            return D2LANG_GetStringFromTblIndex(0xEB5);

        case 0x4:
            return D2LANG_GetStringFromTblIndex(0xEB6);

        case 0x15:
            return D2LANG_GetStringFromTblIndex(0xEBB);

        case 0x17:
            return D2LANG_GetStringFromTblIndex(0xEBC);

        case 0x18:
            return D2LANG_GetStringFromTblIndex(0xEBD);

        case 0x19:
            return D2LANG_GetStringFromTblIndex(0xEBE);

        case 0x1B:
            return D2LANG_GetStringFromTblIndex(0xEBF);

        case 0x1C:
            return D2LANG_GetStringFromTblIndex(0xEC0);

        case 0x1D:
            return D2LANG_GetStringFromTblIndex(0xEC1);

        case 0x1E:
            return D2LANG_GetStringFromTblIndex(0xEC2);

        case 0x1F:
            return D2LANG_GetStringFromTblIndex(0xEC3);

        case 0x25:
            return D2LANG_GetStringFromTblIndex(0xEC4);

        case 0x26:
            return D2LANG_GetStringFromTblIndex(0xEC5);

        case 0x27:
            return D2LANG_GetStringFromTblIndex(0xEC6);

        case 0x28:
            return D2LANG_GetStringFromTblIndex(0xEC7);

        case 0x29:
            return D2LANG_GetStringFromTblIndex(0xEC8);

        case 0x2B:
            return D2LANG_GetStringFromTblIndex(0xEC9);

        case 0x5B:
            return D2LANG_GetStringFromTblIndex(0xECA);

        case 0x5C:
            return D2LANG_GetStringFromTblIndex(0xECB);

        case 0x5D:
            return D2LANG_GetStringFromTblIndex(0xECC);

        case 0x90:
            return D2LANG_GetStringFromTblIndex(0xECD);

        case 0x8:
            return D2LANG_GetStringFromTblIndex(0xECE);

        case 0x9:
            return D2LANG_GetStringFromTblIndex(0xECF);

        case 0xC:
            return D2LANG_GetStringFromTblIndex(0xED0);

        case 0xD:
            return D2LANG_GetStringFromTblIndex(0xED1);

        case 0x10:
            return D2LANG_GetStringFromTblIndex(0xED2);

        case 0x11:
            return D2LANG_GetStringFromTblIndex(0xED3);

        case 0x12:
            return D2LANG_GetStringFromTblIndex(0xED4);

        case 0x13:
            return D2LANG_GetStringFromTblIndex(0xED5);

        case 0x14:
            return D2LANG_GetStringFromTblIndex(0xED6);

        case 0x20:
            return D2LANG_GetStringFromTblIndex(0xED7);

        case 0x21:
            return D2LANG_GetStringFromTblIndex(0xED8);

        case 0x22:
            return D2LANG_GetStringFromTblIndex(0xED9);

        case 0x23:
            return D2LANG_GetStringFromTblIndex(0xEDA);

        case 0x24:
            return D2LANG_GetStringFromTblIndex(0xEDB);

        case 0x2A:
            return D2LANG_GetStringFromTblIndex(0xEDC);

        case 0x2C:
            return D2LANG_GetStringFromTblIndex(0xEDD);

        case 0x2D:
            return D2LANG_GetStringFromTblIndex(0xEDE);

        case 0x2E:
            return D2LANG_GetStringFromTblIndex(0xEDF);

        case 0x2F:
            return D2LANG_GetStringFromTblIndex(0xEE0);

        case 0x60:
            return D2LANG_GetStringFromTblIndex(0xEE1);

        case 0x61:
            return D2LANG_GetStringFromTblIndex(0xEE2);

        case 0x62:
            return D2LANG_GetStringFromTblIndex(0xEE3);

        case 0x63:
            return D2LANG_GetStringFromTblIndex(0xEE4);

        case 0x64:
            return D2LANG_GetStringFromTblIndex(0xEE5);

        case 0x65:
            return D2LANG_GetStringFromTblIndex(0xEE6);

        case 0x66:
            return D2LANG_GetStringFromTblIndex(0xEE7);

        case 0x67:
            return D2LANG_GetStringFromTblIndex(0xEE8);

        case 0x68:
            return D2LANG_GetStringFromTblIndex(0xEE9);

        case 0x69:
            return D2LANG_GetStringFromTblIndex(0xEEA);

        case 0x6A:
            return D2LANG_GetStringFromTblIndex(0xEEB);

        case 0x6B:
            return D2LANG_GetStringFromTblIndex(0xEEC);

        case 0x6C:
            return D2LANG_GetStringFromTblIndex(0xEED);

        case 0x6D:
            return D2LANG_GetStringFromTblIndex(0xEEE);

        case 0x6E:
            return D2LANG_GetStringFromTblIndex(0xEEF);

        case 0x6F:
            return D2LANG_GetStringFromTblIndex(0xEF0);

        case 0x70:
            return D2LANG_GetStringFromTblIndex(0xEF1);

        case 0x71:
            return D2LANG_GetStringFromTblIndex(0xEF2);

        case 0x72:
            return D2LANG_GetStringFromTblIndex(0xEF3);

        case 0x73:
            return D2LANG_GetStringFromTblIndex(0xEF4);

        case 0x74:
            return D2LANG_GetStringFromTblIndex(0xEF5);

        case 0x75:
            return D2LANG_GetStringFromTblIndex(0xEF6);

        case 0x76:
            return D2LANG_GetStringFromTblIndex(0xEF7);

        case 0x77:
            return D2LANG_GetStringFromTblIndex(0xEF8);

        case 0x78:
            return D2LANG_GetStringFromTblIndex(0xEF9);

        case 0x79:
            return D2LANG_GetStringFromTblIndex(0xEFA);

        case 0x7A:
            return D2LANG_GetStringFromTblIndex(0xEFB);

        case 0x7B:
            return D2LANG_GetStringFromTblIndex(0xEFC);

        case 0x7C:
            return D2LANG_GetStringFromTblIndex(0xEFD);

        case 0x7D:
            return D2LANG_GetStringFromTblIndex(0xEFE);

        case 0x7E:
            return D2LANG_GetStringFromTblIndex(0xEFF);

        case 0x7F:
            return D2LANG_GetStringFromTblIndex(0xF00);

        case 0x80:
            return D2LANG_GetStringFromTblIndex(0xF01);

        case 0x81:
            return D2LANG_GetStringFromTblIndex(0xF02);

        case 0x82:
            return D2LANG_GetStringFromTblIndex(0xF03);

        case 0x83:
            return D2LANG_GetStringFromTblIndex(0xF04);

        case 0x84:
            return D2LANG_GetStringFromTblIndex(0xF05);

        case 0x85:
            return D2LANG_GetStringFromTblIndex(0xF06);

        case 0x86:
            return D2LANG_GetStringFromTblIndex(0xF07);

        case 0x87:
            return D2LANG_GetStringFromTblIndex(0xF08);

        case 0x91:
            return D2LANG_GetStringFromTblIndex(0xF09);

        case 0xBA:
            return D2LANG_GetStringFromTblIndex(0xF0A);

        case 0xBB:
            return D2LANG_GetStringFromTblIndex(0xF0B);

        case 0xBC:
            return D2LANG_GetStringFromTblIndex(0xF0C);

        case 0xBD:
            return D2LANG_GetStringFromTblIndex(0xF0D);

        case 0xBE:
            return D2LANG_GetStringFromTblIndex(0xF0E);

        case 0xBF:
            return D2LANG_GetStringFromTblIndex(0xF0F);

        case 0xC0:
            return D2LANG_GetStringFromTblIndex(0xF10);

        case 0xDB:
            return D2LANG_GetStringFromTblIndex(0xF11);

        case 0xDC:
            return D2LANG_GetStringFromTblIndex(0xF12);

        case 0xDD:
            return D2LANG_GetStringFromTblIndex(0xF13);

        case 0xDE:
            return D2LANG_GetStringFromTblIndex(0xF14);
        }
    }

    memset(gwszKeyText_007A741C, 0, sizeof(gwszKeyText_007A741C));
    gwszKeyText_007A741C[0].wChar = (unsigned char)nKey;
    return gwszKeyText_007A741C;
}

// 0x0046A530
const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB)
{
    switch (FindHotkeyKey_Inline(nA, nB))
    {
    case 0x100:
        return D2LANG_GetStringFromTblIndex(0xF15);
    case 0x101:
        return D2LANG_GetStringFromTblIndex(0xF16);
    case 0x102:
        return D2LANG_GetStringFromTblIndex(0xF17);
    case 0x103:
        return D2LANG_GetStringFromTblIndex(0xF18);
    case 0x104:
        return D2LANG_GetStringFromTblIndex(0xF19);
    case 0x11:
        return D2LANG_GetStringFromTblIndex(0xF30);
    case 0x21:
        return D2LANG_GetStringFromTblIndex(0xF34);
    case 0x22:
        return D2LANG_GetStringFromTblIndex(0xF35);
    case 0x1B:
        return D2LANG_GetStringFromTblIndex(0xF1E);
    case 0x90:
        return D2LANG_GetStringFromTblIndex(0xF2B);
    case 0x8:
        return D2LANG_GetStringFromTblIndex(0xF2C);
    case 0x10:
        return D2LANG_GetStringFromTblIndex(0xF2F);
    case 0x60:
        return D2LANG_GetStringFromTblIndex(0xF3B);
    case 0x61:
        return D2LANG_GetStringFromTblIndex(0xF3C);
    case 0x62:
        return D2LANG_GetStringFromTblIndex(0xF3D);
    case 0x63:
        return D2LANG_GetStringFromTblIndex(0xF3E);
    case 0x64:
        return D2LANG_GetStringFromTblIndex(0xF3F);
    case 0x65:
        return D2LANG_GetStringFromTblIndex(0xF40);
    case 0x66:
        return D2LANG_GetStringFromTblIndex(0xF41);
    case 0x67:
        return D2LANG_GetStringFromTblIndex(0xF42);
    case 0x68:
        return D2LANG_GetStringFromTblIndex(0xF43);
    case 0x69:
        return D2LANG_GetStringFromTblIndex(0xF44);
    case 0x6A:
        return D2LANG_GetStringFromTblIndex(0xF45);
    case 0x6B:
        return D2LANG_GetStringFromTblIndex(0xF46);
    case 0x6C:
        return D2LANG_GetStringFromTblIndex(0xF48);
    case 0x6D:
        return D2LANG_GetStringFromTblIndex(0xF47);
    case 0x6F:
        return D2LANG_GetStringFromTblIndex(0xF49);
    case 0x91:
        return D2LANG_GetStringFromTblIndex(0xF4A);
    case 0x2C:
        return D2LANG_GetStringFromTblIndex(0xF37);
    case 0x2D:
        return D2LANG_GetStringFromTblIndex(0xF38);
    case 0x2E:
        return D2LANG_GetStringFromTblIndex(0xF39);
    }
    return CMDTBL_GetKeyText(nA, nB);
}

// 0x0046A940
void __stdcall CMDTBL_DispatchHotkey(SMSGHANDLER_PARAMS* pMsg)
{
    int nKey = pMsg->wParam;
    for (int i = 0; i < 114; ++i)
    {
        if (gaHotkeys[i].nKey != nKey)
            continue;
        int nAction = gaHotkeys[i].nAction;
        if (nAction != 0xFFFF && nAction < 0x39 && nAction <= 0xDF && gaHotkeyCommands[nAction].pfnUnk0x04)
        {
            if (gnMode_007A7418 == 2 && !gaHotkeyCommands[gaHotkeys[i].nAction].nModeFlag)
                return;
            D2_ASSERT(!IsBadCodePtr((FARPROC)gaHotkeyCommands[gaHotkeys[i].nAction].pfnUnk0x04), 0x81C);
            gaHotkeyCommands[gaHotkeys[i].nAction].pfnUnk0x04();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}

#include "gen/data/Source/D2Client/UI/CmdTbl.inc"
