#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" unsigned int __cdecl strlen(const char* szString);
int __stdcall CONTROL_SetFocusedEditBox(void* pEditBox);                                                                  // 0x004F91C0
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl);                                 // 0x004FBB30
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
void __fastcall EDITBOX_SetText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0
int __stdcall CHATDLG_JoinByName(int nArg);                                                            // 0x004439F0
void __fastcall CHATDLG_SetPendingText(const char* szText, unsigned short wRequestId);                 // 0x00442DD0

extern D2LaunchGameRecStrc gaNewGames[];                                                           // 0x0077BDC8
extern D2WinControlStrc* gpJoinName;                                                               // 0x00798BD4
unsigned long gdwGameListLastClickTick;                                                                    // 0x00798CEC

// 0x00442E30
static void CHATDLG_ShowGameInfo(int nIndex)
{
    if (!gpGameText_00798BC4)
        return;

    D2LaunchGameRecStrc* pGame = &gaNewGames[nIndex];
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    if (strlen(&pGame->szName[0x10]))
    {
        sub_004FCF80_SetTextA(gpGameText_00798BC4, &pGame->szName[0x10]);
        sub_004FCF80_SetTextA(gpGameText_00798BC4, &gszEmptyAssertText);
    }
    D2Win_10053(gpGameText_00798BC4, 0);
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
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
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
                sub_00526F70(szText, pText, 0x100);
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

#include "gen/data/Source/D2Multi/Unknown_004450D0.inc"
