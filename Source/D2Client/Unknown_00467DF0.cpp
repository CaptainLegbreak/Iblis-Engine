#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2StormTypes.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2CursorAnimStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2CursorAnimStrc gaCursorAnim[CURSOR_ANIM_COUNT]; // 0x00712010



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






