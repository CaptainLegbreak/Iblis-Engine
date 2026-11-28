// The end-screen button handlers (0x0044E460, 0x0044E4F0) stay out of Game.cpp. In the image the call's push in
// GAME_HandleEndScreenButtonUp comes before all four button-state stores. That order comes out only when gbRightButtonDown
// and gbRightClickConsumed are static, as they are here. SCmd.cpp, inv.cpp, Unknown_00482C70.cpp and
// Unknown_00402820.cpp read them, so Game.cpp has to define them for those units, and there the push lands after the
// first two stores. GAME_HandleEndScreenButtonDown matches in Game.cpp only while the other handler is beside it.
#include "D2StormTypes.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "StormApi.h"

static int gbEndScreenButtonPressed; // 0x007A0680
static int gbEndScreenDismissed; // 0x007A0608
static int gbLeftButtonDown; // 0x007A0650
static int gbRightButtonDown; // 0x007A0654
static int gbLeftClickRepeating; // 0x007A066C
static int gbRightClickConsumed; // 0x007A0670

// 0x0044E460
void __stdcall GAME_HandleEndScreenButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nBottom = gnScreenHeight - 0x50;
    int nLeft = gnScreenWidth / 2 - 0x30;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gbEndScreenButtonPressed = 1;
        gbLeftButtonDown = 0;
        gbRightButtonDown = 0;
        gbLeftClickRepeating = 0;
        gbRightClickConsumed = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        SMsgBreakHandlerChain(pMsg);
        return;
    }

    gbLeftButtonDown = 0;
    gbRightButtonDown = 0;
    gbLeftClickRepeating = 0;
    gbRightClickConsumed = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    SMsgBreakHandlerChain(pMsg);
}

// 0x0044E4F0
void __stdcall GAME_HandleEndScreenButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    gbEndScreenButtonPressed = 0;
    const int nBottom = gnScreenHeight - 0x50;
    int nLeft = gnScreenWidth / 2 - 0x30;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gbEndScreenDismissed = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        SMsgBreakHandlerChain(pMsg);
        return;
    }
    gbLeftButtonDown = 0;
    gbRightButtonDown = 0;
    gbLeftClickRepeating = 0;
    gbRightClickConsumed = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    SMsgBreakHandlerChain(pMsg);
}


