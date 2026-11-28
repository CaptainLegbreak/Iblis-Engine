#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "StormApi.h"
#include "D2LangApi.h"
#include "FogApi.h"

struct D2LaunchResultStrc
{
    int nResult;
};

struct D2LaunchLoginStrc
{
    char szText0x00[0x10];
    char szText0x10[0x10];
    char szText0x20[0x20];
    unsigned int nValue0x40;
    char nValue0x44;
    unsigned char nValue0x45;
    char nValue0x46;
};

extern "C" int __cdecl atoi(const char* szString);
extern "C" size_t __cdecl strlen(const char* szString);

int __fastcall CHATDLG_SetupLogin(D2LaunchLoginStrc* pLogin, const char* szText0x37); // 0x0043FE40
void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0
int __stdcall CHATDLG_CheckStartAdvResult(int nUnused); // 0x00443840
void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
extern "C" const char gszMaxPlayer[]; // 0x006D57C0
extern "C" const char gszLvlRest[]; // 0x006D57CC
extern "C" const char gszDiffLevel[]; // 0x006D57DC
extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C
extern D2ConfigStrc* gpCharInfo; // 0x0077BBD8
extern D2WinControlStrc* gpCreateName; // 0x00798C2C
extern D2WinControlStrc* gpCreatePassword; // 0x00798C30
extern D2WinControlStrc* gpCreateDesc; // 0x00798C34
extern D2WinControlStrc* gpEditBox_00798C3C; // 0x00798C3C
extern D2WinControlStrc* gpLevelDiffCheck; // 0x00798C40
extern int gfCreateGameCancelled; // 0x00798CC4
extern int gnDiffSelect; // 0x00798CD0

// 0x004456D0
int __stdcall sub_004456D0_SubmitCreateGame(int nArg)
{
    char szName[0x100];
    D2LaunchLoginStrc tLogin;
    char szNumber[8];
    char szDesc[0x200];
    const Unicode* pName;
    const Unicode* pPassword;
    const Unicode* pDesc;

    if (!sub_004F9710_TestFlag(gpCreateButton))
        return 0;

    pName = sub_004FDD90_GetEditText(gpCreateName);
    if (pName)
    {
        UNICODE_ToAscii(szName, pName, 0xFF);
        if (strlen(szName) < 1)
            return 0;

        pPassword = sub_004FDD90_GetEditText(gpCreatePassword);
        pDesc = sub_004FDD90_GetEditText(gpCreateDesc);
// build: symbol ?MCPCONNECT_QueryAddress@* 0x00449B30
        if (MCPCONNECT_QueryAddress())
        {
            const Unicode* pMaxPlayers = sub_004FDD90_GetEditText(gpMaxPlayerControl);
            tLogin.nValue0x44 = 1;
            if (sub_00500960_IsPressed(gpLevelDiffCheck))
            {
                const Unicode* pLevel = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
                UNICODE_ToAscii(szNumber, pLevel, 3);
                tLogin.nValue0x45 = atoi(szNumber);
            }
            else
            {
                tLogin.nValue0x45 = -1;
            }
            UNICODE_ToAscii(szNumber, pMaxPlayers, 3);
            tLogin.nValue0x46 = atoi(szNumber);
        }

        UNICODE_ToAscii(tLogin.szText0x00, pName, 0x10);
        UNICODE_ToAscii(tLogin.szText0x10, pPassword, 0x10);
        UNICODE_ToAscii(tLogin.szText0x20, pDesc, 0x20);
        tLogin.nValue0x40 = 0;
        sub_00411320_CapitalizeWords(tLogin.szText0x00);
        sub_00411320_CapitalizeWords(tLogin.szText0x10);
        tLogin.nValue0x40 = tLogin.nValue0x40 & 0xFFFF8FFF | (gnDiffSelect << 12);

        if (strlen(tLogin.szText0x00) < 1)
            return 0;

        if (!MCPCONNECT_QueryAddress())
        {
            int bExpansion = (gpCharInfo->wFlags1EF) & 4;
            int bLadder = (gpCharInfo->wFlags1EF) & 0x20;
            if (bExpansion)
                gpCharInfo->dwFlags209 |= 0x800;
            if (bLadder)
                gpCharInfo->dwFlags209 |= 0x100000;

            szDesc[0] = (bExpansion ? 3 : 0) + gnDiffSelect + '1';
            SStrCopy(&szDesc[1], tLogin.szText0x20, 0x7FFFFFFF);

            int nFlags = 0;
            if (gpCharInfo->nByte210 == 1)
                nFlags = 1;
            if (gpCharInfo->nByte210 == 2)
                nFlags |= 2;
            if ((gpCharInfo->wFlags1EF) & 4)
                nFlags |= 4;
            if ((gpCharInfo->wFlags1EF) & 0x20)
                nFlags |= 8;

            gpLaunchFuncs->pfnRefreshGame(tLogin.szText0x00, tLogin.szText0x10, szDesc, nFlags);
            CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
            sub_004FA590_RunLoop(CHATDLG_CheckStartAdvResult);
// build: symbol ?CHATDLG_DestroyPopupControls@* 0x0043EA20
            CHATDLG_DestroyPopupControls();

            D2LaunchResultStrc tResult;
            gpLaunchFuncs->pfnGetCreateGameResult((int*)&tResult);
            if (!tResult.nResult)
            {
                CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x1412), 0);
                return 1;
            }
        }
        else
        {
            char szValue[5];
            const Unicode* pValue = sub_004FDD90_GetEditText(gpMaxPlayerControl);
            UNICODE_ToUtf8(szValue, pValue, 5);
// build: symbol ?gszDiabloII@* 0x006CC8B8
            SRegSaveValue(gszDiabloII, gszMaxPlayer, 0, atoi(szValue));
            SRegSaveValue(gszDiabloII, gszDiffLevel, 0, gnDiffSelect);
            if (!sub_00500960_IsPressed(gpLevelDiffCheck))
            {
                SRegSaveValue(gszDiabloII, gszLvlRest, 0, 666);
            }
            else
            {
                pValue = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
                UNICODE_ToUtf8(szValue, pValue, 5);
                SRegSaveValue(gszDiabloII, gszLvlRest, 0, atoi(szValue));
            }
        }

        CHATDLG_SetupLogin(&tLogin, FOG_GetHostIPAddress());
        if (!MCPCONNECT_QueryAddress())
        {
            CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
            CHATDLG_DestroyCreateControls();
            return 1;
        }

        gfCreateGameCancelled = 0;
        CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), CHATDLG_SetCancel);
        sub_004FA590_RunLoop(CHATDLG_PollMcp);
        CHATDLG_DestroyPopupControls();
        if (gfCreateGameCancelled)
// build: symbol ?CHARSEL_CancelGameCreate@* 0x0043F850
            CHARSEL_CancelGameCreate();
        CHATDLG_DestroyCreateControls();
// build: symbol ?GAME_IsMcpCreateQueued@* 0x00449E40
        if (GAME_IsMcpCreateQueued())
            COMCALLBACK_BuildCreateGamePanel();
    }

    return 1;
}
