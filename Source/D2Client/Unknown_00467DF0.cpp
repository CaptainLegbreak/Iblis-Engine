#include "D2Client.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CursorAnimStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2CursorAnimStrc gaCursorAnim[CURSOR_ANIM_COUNT]; // 0x00712010

int __cdecl GAME_IsExitPending(); // 0x0044DA30
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
void __fastcall SPELLSEL_AssignHotkey(int nHotkey); // 0x004A9E60
void __fastcall SPELLSEL_SelectHotkey(int nSlot); // 0x004AA030
void __cdecl PANEL_BeltHotkeyFirst(); // 0x00498C50
void __cdecl PANEL_BeltHotkeySecond(); // 0x00498C90
void __cdecl PANEL_BeltHotkeyThird(); // 0x00498CD0
void __cdecl PANEL_BeltHotkeyFourth(); // 0x00498D10


// 0x00468B20
static inline void sub_00468B20_HandleHotkey(int nHotkey)
{
    if (GAME_IsExitPending())
        return;
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    if (nHotkey > 8 && !GAME_IsExpansion())
        return;
    D2_ASSERT(nHotkey >= 0 || nHotkey <= 15, 0xFC);
    if (GAME_GetUIVarState(3))
        SPELLSEL_AssignHotkey(nHotkey);
    else
        SPELLSEL_SelectHotkey(nHotkey);
}

void __fastcall sub_M115_Emit_00468B20(int nHotkey)
{
    sub_00468B20_HandleHotkey(nHotkey);
}






