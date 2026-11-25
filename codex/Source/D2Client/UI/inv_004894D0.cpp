#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg); // 0x004873A0

void __cdecl INV_ResetHover(); // 0x00487990

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

extern D2InventoryGridInfoStrc gtTradePage2Grid; // 0x007BCA30

extern int gnInvMouseX; // 0x007BCA4C

extern D2InvRectStrc gtPlayerInvRect; // 0x007BCAA0

extern D2InventoryGridInfoStrc gtTradePage1Grid; // 0x007BCB18

extern int gnInvPanelMode; // 0x007BCBF0

extern int gnInvMouseY; // 0x007BCBD8

// 0x004894D0
void __stdcall INV_TradeMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xB)
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if ((nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
        || (nX > gtTradePage2Grid.nGridLeft && nX < gtTradePage2Grid.nGridRight && nY >= gtTradePage2Grid.nGridTop && nY <= gtTradePage2Grid.nGridBottom)
        || (nX > gtTradePage1Grid.nGridLeft && nX < gtTradePage1Grid.nGridRight && nY >= gtTradePage1Grid.nGridTop && nY <= gtTradePage1Grid.nGridBottom))
    {
        INV_UpdateInventoryHover(pMsg);
        return;
    }
    INV_ResetHover();
    D2Win_10129_DrawFramedText(0, -1, -1, 0, 0);
}
