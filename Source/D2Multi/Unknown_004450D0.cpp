#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
#include "D2LangApi.h"
#include "D2WinApi.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" unsigned int __cdecl strlen(const char* szString);
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl);                                 // 0x004FBB30
void __fastcall EDITBOX_SetText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0

extern D2LaunchGameRecStrc gaNewGames[];                                                           // 0x0077BDC8
extern D2WinControlStrc* gpJoinName;                                                               // 0x00798BD4
unsigned long gdwGameListLastClickTick;                                                                    // 0x00798CEC

// 0x00442E30
static void CHATDLG_ShowGameInfo(int nIndex)
{
    if (!gpGameInfoText)
        return;

    D2LaunchGameRecStrc* pGame = &gaNewGames[nIndex];
    sub_004FB6A0_ClearText(gpGameInfoText);
    if (strlen(&pGame->szName[0x10]))
    {
        sub_004FCF80_SetTextA(gpGameInfoText, &pGame->szName[0x10]);
        sub_004FCF80_SetTextA(gpGameInfoText, &gszEmptyAssertText);
    }
    D2Win_10053(gpGameInfoText, 0);
    if (pGame->szName)
    {
        sub_004FFE10_SetTextA(gpJoinName, pGame->szName);
        CONTROL_SetFocusedEditBox(0);
    }
}

static inline int sub_004450D0_IsDoubleClick(int nSelection)
{
    const unsigned long dwTick = GetTickCount();
// build: symbol ?gnGameListLastSelection@* 0x0070EBDC
    if (nSelection == gnGameListLastSelection && dwTick - gdwGameListLastClickTick <= 500)
        return 1;

    gnGameListLastSelection = nSelection;
    gdwGameListLastClickTick = dwTick;
    return 0;
}

// 0x004450D0
int __stdcall sub_004450D0_OnGameListEvent(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gpGameList@* 0x00798BC0
    const int nSelection = sub_004FB990_GetSelection(gpGameList);
    sub_004FB6A0_ClearText(gpGameInfoText);
    if (nSelection != -1)
    {
        if (pMsg->uMessage == 0x201 && sub_004450D0_IsDoubleClick(nSelection))
        {
            CHATDLG_JoinByName(0);
            return 0;
        }

// build: symbol ?MCPCONNECT_QueryAddress@* 0x00449B30
        if (MCPCONNECT_QueryAddress())
        {
            const Unicode* pText = sub_004FBB30_GetText(gpGameList);
            if (pText)
            {
                char szText[0x100];
                UNICODE_ToAscii(szText, pText, 0x100);
// build: symbol ?gwRequestId@* 0x0070CD60
                while (++gwRequestId == 0)
                {
                }
                CHATDLG_SetPendingText(szText, gwRequestId);
                EDITBOX_SetText(gpJoinName, pText);
                CONTROL_SetFocusedEditBox(0);
            }
        }
        else
        {
            CHATDLG_ShowGameInfo(nSelection);
        }
    }
    return 0;
}

int gnGameListLastSelection = -2; // 0x0070EBDC
