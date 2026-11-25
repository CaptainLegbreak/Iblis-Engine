#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"

struct D2ClientListEntryStrc
{
    unsigned char nId[4];
    unsigned char unk0x04[6];
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg);                                     // 0x00420290
int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __cdecl UI_RegisterKeyConfigHandlers();                                                                                // 0x00454980
int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, int* pKey);                          // 0x00469C20
int __cdecl WINDOW_GetWindow();                                                                                // 0x004F59A0
extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[];                                                      // 0x0072472C
extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[];                                                      // 0x00724738
extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[];                                                      // 0x00724780
extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[];                                                      // 0x0072478C
extern int gnKeyConfigSelected;                                                                               // 0x007C02B0
extern int gbKeyCaptureActive;                                                                               // 0x007C02B8
extern unsigned long gdwMessageTick;                                                                     // 0x007C02C8


// 0x004A5D70
static inline void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset)
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
    if (bReset)
    {
        UI_RegisterKeyConfigHandlers();
        gbKeyCaptureActive = 0;
    }
}

static void sub_004A6260_UpdateKeyState(int nCommand);

// 0x004A6260
static void sub_004A6260_UpdateKeyState(int nCommand)
{
    int nKey = 0;
// build: symbol ?gpListEntries@* 0x00724264
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
    if (CMDTBL_QueryKey(*(int*)gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, nCommand, &nKey))
    {
        TEXT_UnregisterKeyConfigHandlers(1);
    }
    else if ((unsigned short)nKey)
    {
        gwGlobal_007C02C4 = nKey;
        gdwMessageTick = GetTickCount();
    }
}

// 0x004A6310
void __stdcall TEXT_WheelCaptureMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    sub_004A6260_UpdateKeyState(0x100);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6350
void __stdcall TEXT_ButtonCaptureMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    switch (pMsg->wParamHigh)
    {
    case 1:
        sub_004A6260_UpdateKeyState(0x101);
        break;
    case 2:
        sub_004A6260_UpdateKeyState(0x102);
        break;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A63B0
void __stdcall sub_004A63B0_WheelMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    int nSteps = (short)pMsg->wParamHigh / 120;
    if (nSteps)
    {
        int nKey = 0;
// build: symbol ?gpListEntries@* 0x00724264
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
        if (CMDTBL_QueryKey(*(int*)gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (nSteps < 0) + 0x103, &nKey))
        {
            TEXT_UnregisterKeyConfigHandlers(1);
        }
        else if ((unsigned short)nKey)
        {
            gwGlobal_007C02C4 = nKey;
            gdwMessageTick = GetTickCount();
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}





#include "gen/data/Source/D2Client/Unknown_004A6260.inc"
