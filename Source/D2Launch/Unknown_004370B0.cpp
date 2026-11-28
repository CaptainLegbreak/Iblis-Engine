#include "D2Launch.h"

#include "D2FogTypes.h"

#include "D2StormTypes.h"

#include "D2Unicode.h"

#include "D2MultiTypes.h"
#include "D2LangApi.h"
#include "D2WinApi.h"

struct D2ComInterfaceStrc;

void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330


extern int gnStatusDots; // 0x007799B4

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100

void __cdecl MAINMENUS_CreateEmailScreen(); // 0x00436F30

void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0


void __cdecl MAINMENUS_CreatePasswordScreen(); // 0x004372B0

int __cdecl sub_0043B830_IsCancelled(); // 0x0043B830


void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0



int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

extern D2ConfigStrc* gpLaunchRecord; // 0x007795D4


int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0

void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0

void __cdecl CHARSEL_SetCancelled(); // 0x0043B810


int __stdcall MAINMENUS_FilterRestrictedChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0

int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20

int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0

void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0

extern D2WinControlStrc* gpPasswordOk; // 0x007799A4

extern D2WinControlStrc* gpStatusText; // 0x007799A8

extern D2WinControlStrc* gpCounterText; // 0x007799AC

extern int gnStatusStringId; // 0x007799B0

extern unsigned long gdwStatusStart; // 0x007799B8

extern D2WinControlStrc* gpButton; // 0x007799E4

extern D2WinControlStrc* gpChangePwAccountEdit; // 0x007799BC

extern D2WinControlStrc* gpOldPasswordEdit; // 0x007799C0

extern D2WinControlStrc* gpNewPasswordConfirmEdit; // 0x007799C4

extern D2WinControlStrc* gpNewPasswordEdit; // 0x007799C8

extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0










void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0


int __stdcall MAINMENUS_FilterRestrictedChar(void* pControl, int nUnused, const char* pChar); // 0x0042FEF0

void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100

void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330


static int MAINMENUS_CheckAtAndDot(const char* szText); // 0x00436C10

void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0

int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20

extern int gnStatusDots; // 0x007799B4




extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4

void __cdecl MAINMENUS_UpdateTwoEditOk(); // 0x00436CF0


const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinControlStrc*); // 0x004FDD90



extern int gfConnectCancelled; // 0x007799D8

void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540

// 0x00436AC0
void __cdecl MAINMENUS_ClearStatusTexts()
{
    gpStatusText = 0;
    gpCounterText = 0;
}

// 0x00436AD0
void __cdecl MAINMENUS_UpdateStatus()
{
    char szText[0x100];
    int nState;
    if (!gpStatusText)
        return;
    gpFuncTable->pfnSlot80(&nState);
    switch (nState)
    {
    case 0:
        gnStatusStringId = 0x1433;
        break;
    case 1:
        gnStatusStringId = 0x1434;
        break;
    case 2:
        gnStatusStringId = 0x1435;
        break;
    case 3:
        gnStatusStringId = 0x1436;
        break;
    case 4:
        gnStatusStringId = 0x1437;
        break;
    case 5:
        gnStatusStringId = 0x1438;
        break;
    case 6:
        gnStatusStringId = 0x1439;
        break;
    default:
        gnStatusStringId = -1;
        break;
    }
    sub_004FB6A0_ClearText(gpStatusText);
    if (gnStatusStringId >= 0)
        sub_004FC9B0_SetText(gpStatusText, D2LANG_GetStringFromTblIndex(gnStatusStringId), 0, 0, 0);
    const unsigned long nCounter = (GetTickCount() - gdwStatusStart) / 250 % 20 + 1;
    sprintf(szText, "%.*s", nCounter, "....................");
    sub_004FB6A0_ClearText(gpCounterText);
    D2Win_10045(gpCounterText, szText);
}

// 0x00436C10
static int MAINMENUS_CheckAtAndDot(const char* szText)
{
    if (!szText)
        return 0;
    int bValid = 0;
    const char* pAt = SStrChr(szText, '@');
    if (pAt)
    {
        const char* pDot = SStrChr(pAt, '.');
        if (pDot && pAt > szText && pDot > pAt + 1 && (int)SStrLen(szText) > pDot - szText + 1)
            bValid = 1;
    }
    return bValid;
}

// 0x00436C70
int __stdcall MAINMENUS_DeclineEmail(int nArg)
{
    gpFuncTable->pfnSlotB8((char*)&gszEmptyAssertText);
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00436C90
int __stdcall MAINMENUS_AskEmailRegistration(int nArg)
{
    MAINMENUS_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B5E), 0x2B61, 0x13EF, MAINMENUS_DeclineEmail, MAINMENUS_OnCloseBox, 0, 1);
    return 1;
}

// 0x00436CD0
int __stdcall MAINMENUS_OnConnectCancel(int nArg)
{
    gfConnectCancelled = 1;
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00436CF0
void __cdecl MAINMENUS_UpdateTwoEditOk()
{
 const Unicode* pText1=D2Win_10077_EDITBOX_GetText(gpEdit_007799CC);
 const Unicode* pText2=D2Win_10077_EDITBOX_GetText(gpEdit_007799D0);
 int bOk=UNICODE_StrLen(pText1)>0;
 bOk|=UNICODE_StrLen(pText2)>0;
 CONTROL_SetEnabled(gpControl_007799D4,bOk);
}

// 0x00436D40
int __stdcall MAINMENUS_OnTwoEditChange(int nArg)
{
    MAINMENUS_UpdateTwoEditOk();
    return 1;
}

// 0x00436D50
void __cdecl CHARSEL_CreateConnectScreen()
{
    gfConnectCancelled = 0;
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x122);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B55), 0, 0, 0);
    pControl = MAINMENUS_CreateControl(0x123);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B56), 0, 0, 0);
    MAINMENUS_CreateControl(0x120);
    pControl = MAINMENUS_CreateControl(0x124);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799CC = MAINMENUS_CreateControl(0x126);
    sub_004FDB00_SetEnterCallback(gpEdit_007799CC, MAINMENUS_OnTwoEditChange);
    MAINMENUS_CreateControl(0x121);
    pControl = MAINMENUS_CreateControl(0x125);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B58));
    gpEdit_007799D0 = MAINMENUS_CreateControl(0x127);
    sub_004FDB00_SetEnterCallback(gpEdit_007799D0, MAINMENUS_OnTwoEditChange);
    gpControl_007799D4 = MAINMENUS_CreateControl(0x128);
    MAINMENUS_CreateControl(0x129);
    MAINMENUS_CreateControl(0x12A);
    CONTROL_SetFocusedEditBox(gpEdit_007799CC);
    sub_004FDDD0_LinkTab(gpEdit_007799CC, gpEdit_007799D0);
    sub_004FDDD0_LinkTab(gpEdit_007799D0, gpEdit_007799CC);
    MAINMENUS_UpdateTwoEditOk();
}

// 0x00436E90
int __stdcall sub_00436E90_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00436EA0
int __cdecl sub_00436EA0_IsCancelled()
{
    return gfConnectCancelled;
}

// 0x00436EB0
void __cdecl MAINMENUS_UpdateEmailOk()
{
    char szText[0x100];
    int bOk = UNICODE_StrLen(sub_004FDD90_GetEditText(gpEdit_007799DC)) > 0;
    if (bOk)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(gpEdit_007799E0);
        UNICODE_ToUtf8(szText, pText, 0x100);
        bOk = MAINMENUS_CheckAtAndDot(szText);
    }
    CONTROL_SetEnabled(gpButton, bOk);
}

// 0x00436F20
int __stdcall MAINMENUS_OnEditChange(int nArg)
{
    MAINMENUS_UpdateEmailOk();
    return 1;
}

// 0x00436F30
void __cdecl MAINMENUS_CreateEmailScreen()
{
    if (!gpFuncTable->pfnSlot68())
    {
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x12B);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6A), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x12E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B5F), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x12F);
    pControl = MAINMENUS_CreateControl(0x130);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpEdit_007799DC = MAINMENUS_CreateControl(0x131);
    sub_004FDD50_SetMaxLength(gpEdit_007799DC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpEdit_007799DC, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpEdit_007799DC, MAINMENUS_OnEditChange);
    MAINMENUS_CreateControl(0x132);
    pControl = MAINMENUS_CreateControl(0x133);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799E0 = MAINMENUS_CreateControl(0x134);
    sub_004FDB00_SetEnterCallback(gpEdit_007799E0, MAINMENUS_OnEditChange);
    sub_004FFE10_SetTextA(gpEdit_007799DC, gpLaunchRecord->szAccount);
    CONTROL_SetFocusedEditBox(gpEdit_007799DC);
    sub_004FDDD0_LinkTab(gpEdit_007799DC, gpEdit_007799E0);
    sub_004FDDD0_LinkTab(gpEdit_007799E0, gpEdit_007799DC);
    gpButton = MAINMENUS_CreateControl(0x12C);
    MAINMENUS_CreateControl(0x12D);
    MAINMENUS_UpdateEmailOk();
}

// 0x004370B0
int __stdcall sub_004370B0_ShowLoginScreen(int unused)
{
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x004370C0
void __cdecl MAINMENUS_CreateInfoScreen()
{
    if (!gpFuncTable->pfnSlot68())
    {
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x135);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B65), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x136);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B66), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x137);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B67), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x138);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B68), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x139);
    MAINMENUS_CreateControl(0x13A);
    MAINMENUS_CreateControl(0x13B);
    MAINMENUS_CreateControl(0x13C);
}

// 0x004371B0
int __stdcall sub_004371B0_OnLoginScreen(int nArg)
{
    MAINMENUS_CreateLoginScreen();
    return 1;
}

// 0x004371C0
int __stdcall sub_004371C0_OnEmailScreen(int nArg)
{
    MAINMENUS_CreateEmailScreen();
    return 1;
}

// 0x004371D0
int __stdcall sub_004371D0_OnShowLogin(int nArg)
{
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x004371E0
void __cdecl MAINMENUS_UpdatePasswordOk()
{
    char szText3[0x100];
    char szText1[0x100];
    char szText2[0x100];
    int bOk = UNICODE_StrLen(sub_004FDD90_GetEditText(gpChangePwAccountEdit)) > 2;
    if (bOk)
    {
        const Unicode* pText1 = sub_004FDD90_GetEditText(gpOldPasswordEdit);
            UNICODE_ToUtf8(szText1, pText1, 0x100);
        bOk = MAINMENUS_CheckAtAndDot(szText1);
        if (bOk)
        {
            const Unicode* pText2 = sub_004FDD90_GetEditText(gpNewPasswordEdit);
            UNICODE_ToUtf8(szText2, pText2, 0x100);
            bOk = MAINMENUS_CheckAtAndDot(szText2);
            if (bOk)
            {
                const Unicode* pText3 = sub_004FDD90_GetEditText(gpNewPasswordConfirmEdit);
            UNICODE_ToUtf8(szText3, pText3, 0x100);
                bOk = MAINMENUS_CheckAtAndDot(szText3);
            }
        }
    }
    CONTROL_SetEnabled(gpPasswordOk, bOk);
}

// 0x004372A0
int __stdcall sub_004372A0_OnEnter(int nArg)
{
    MAINMENUS_UpdatePasswordOk();
    return 1;
}

// 0x004372B0
void __cdecl MAINMENUS_CreatePasswordScreen()
{
    if (!gpFuncTable->pfnSlot68())
    {
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x13D);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6C), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x13E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B70), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x13F);
    pControl = MAINMENUS_CreateControl(0x140);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpChangePwAccountEdit = MAINMENUS_CreateControl(0x141);
    sub_004FFE10_SetTextA(gpChangePwAccountEdit, gpLaunchRecord->szAccount);
    sub_004FDD50_SetMaxLength(gpChangePwAccountEdit, 0x10);
    sub_004FDAD0_SetKeyCallback(gpChangePwAccountEdit, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpChangePwAccountEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x142);
    pControl = MAINMENUS_CreateControl(0x143);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6D));
    gpOldPasswordEdit = MAINMENUS_CreateControl(0x144);
    sub_004FDB00_SetEnterCallback(gpOldPasswordEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x145);
    pControl = MAINMENUS_CreateControl(0x146);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6E));
    gpNewPasswordEdit = MAINMENUS_CreateControl(0x147);
    sub_004FDB00_SetEnterCallback(gpNewPasswordEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x148);
    pControl = MAINMENUS_CreateControl(0x149);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B6F));
    gpNewPasswordConfirmEdit = MAINMENUS_CreateControl(0x14A);
    sub_004FDB00_SetEnterCallback(gpNewPasswordConfirmEdit, sub_004372A0_OnEnter);
    gpPasswordOk = MAINMENUS_CreateControl(0x14B);
    MAINMENUS_CreateControl(0x14C);
    CONTROL_SetFocusedEditBox(gpChangePwAccountEdit);
    sub_004FDDD0_LinkTab(gpChangePwAccountEdit, gpOldPasswordEdit);
    sub_004FDDD0_LinkTab(gpOldPasswordEdit, gpNewPasswordEdit);
    sub_004FDDD0_LinkTab(gpNewPasswordEdit, gpNewPasswordConfirmEdit);
    sub_004FDDD0_LinkTab(gpNewPasswordConfirmEdit, gpChangePwAccountEdit);
    MAINMENUS_UpdatePasswordOk();
}

// 0x004374E0
int __stdcall sub_004374E0_OnInfoScreen(int nArg)
{
    MAINMENUS_CreateInfoScreen();
    return 1;
}

// 0x004374F0
int __stdcall sub_004374F0_UpdateStatusWait(int nArg)
{
    MAINMENUS_UpdateStatus();
    if (!gnStatusDots)
    {
        CHARSEL_ClearCancelled();
        gnStatusDots = (int)gpFuncTable->pfnSlot04();
        if (!gnStatusDots)
        {
            D2Win_StopMessageLoop();
            return 1;
        }
    }

    if (WaitForSingleObject((void*)gnStatusDots, 0) == 0)
    {
        D2Win_StopMessageLoop();
    }

    if (sub_0043B830_IsCancelled())
    {
        gpFuncTable->pfnSlot10();
        D2Win_StopMessageLoop();
    }

    return 1;
}

// 0x00437550
void __cdecl MAINMENUS_CreateStatusScreen()
{
    gdwStatusStart = GetTickCount();
    MAINMENUS_DestroyControls();
    sub_0042E6B0(0x1);
    D2WinControlStrc* pFrame = MAINMENUS_CreateFromTemplate(0xE2);
    D2Win_10033(pFrame, 0x0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 0x1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xE3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 0x1);
    D2WinControlStrc* pText = MAINMENUS_CreateFromTemplate(0xE4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pText, 0x1);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x1433), 0x0, 0x0, 0x0);
    gpStatusText = MAINMENUS_CreateFromTemplate(0xE5);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpStatusText, 0x1);
    gpCounterText = MAINMENUS_CreateFromTemplate(0xE6);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpCounterText, 0x1);
    gnStatusStringId = -1;
    gnStatusDots = 0x0;
    sub_0042E6A0(CHARSEL_SetCancelled);
    MAINMENUS_UpdateStatus();
}

int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2); // 0x005264F0

// 0x00437620
int __stdcall MAINMENUS_ConfirmText(int nArg)
{
    char szText[0x100];
    const Unicode* pText1 = sub_004FDD90_GetEditText(gpEdit_007799CC);
    const Unicode* pText2 = sub_004FDD90_GetEditText(gpEdit_007799D0);
    if (!sub_005264F0_Compare(pText1, pText2))
    {
        UNICODE_ToUtf8(szText, pText1, 0x100);
        if (!MAINMENUS_CheckAtAndDot(szText))
        {
            MAINMENUS_ShowMessageBox(D2LANG_GetStringFromTblIndex(0x2B5C), D2LANG_GetStringFromTblIndex(0x2B5D), 0x13EE, 0, MAINMENUS_OnCloseBox, 0, 1, 0);
            return 1;
        }
        gpFuncTable->pfnSlotB8(szText);
        D2Win_StopMessageLoop();
        return 1;
    }
    MAINMENUS_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B5B), 0x13EE, 0, MAINMENUS_OnCloseBox, 0, 1, 0);
    return 1;
}

// 0x00437710
int __stdcall sub_00437710_OnInfoScreen(int nArg)
{
    MAINMENUS_CreateInfoScreen();
    return 1;
}

int __stdcall sub_004374F0_UpdateStatusWait(int nArg); // 0x004374F0

// 0x00437720
int __stdcall sub_00437720_OnPasswordScreen(int nArg)
{
    MAINMENUS_CreatePasswordScreen();
    return 1;
}

struct Unicode;

D2WinControlStrc* gpPasswordOk; // 0x007799A4

// 0x00437730
int __stdcall sub_00437730_ChangePassword(int bOk)
{
    char szOld[0x100];
    char szNew[0x100];
    char szName[0x100];
    if (!bOk)
    {
        MAINMENUS_CreateInfoScreen();
        return 1;
    }
    if (!sub_004F9710_TestFlag(gpPasswordOk))
        return 1;
    const Unicode* pName = sub_004FDD90_GetEditText(gpChangePwAccountEdit);
    const Unicode* pOld = sub_004FDD90_GetEditText(gpOldPasswordEdit);
    const Unicode* pNew = sub_004FDD90_GetEditText(gpNewPasswordEdit);
    if (!sub_005264F0_Compare(pNew, sub_004FDD90_GetEditText(gpNewPasswordConfirmEdit)))
    {
        if (sub_005264F0_Compare(pOld, pNew))
        {
            UNICODE_ToUtf8(szName, pName, 0x100);
            UNICODE_ToUtf8(szOld, pOld, 0x100);
            UNICODE_ToUtf8(szNew, pNew, 0x100);
            {
                char szConfirm[0x100];
                UNICODE_ToUtf8(szConfirm, pNew, 0x100);
            }
            if (gpFuncTable->pfnSlot68() && gpFuncTable->pfnSlotC0(szName, szOld, szNew))
            {
                MAINMENUS_ShowLoginScreen();
                return 1;
            }
            MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
            return 0;
        }
        else
        {
            Unicode aText[0x100];
            MAINMENUS_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B71), 0x13EE, 0, MAINMENUS_OnCloseBox, 0, 1, 0);
        }
    }
    else
    {
        Unicode aText[0x100];
        MAINMENUS_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B72), 0x13EE, 0, MAINMENUS_OnCloseBox, 0, 1, 0);
    }
    return 1;
}

// 0x004378D0
int __stdcall CHARSEL_SubmitPasswordReset(int nArg)
{
    char szA[0x100];
    char szB[0x100];

    if (!nArg)
    {
        MAINMENUS_CreateInfoScreen();
        return 1;
    }

    if (!sub_004F9710_TestFlag(gpButton))
        return 1;

    const Unicode* pTextA = sub_004FDD90_GetEditText(gpEdit_007799DC);
    const Unicode* pTextB = sub_004FDD90_GetEditText(gpEdit_007799E0);
    UNICODE_ToUtf8(szA, pTextA, 0x100);
    UNICODE_ToUtf8(szB, pTextB, 0x100);

    if (gpFuncTable->pfnSlot68() && gpFuncTable->pfnSlotBC(szA, szB))
    {
        MAINMENUS_ShowMessageBox(0, D2LANG_GetStringFromTblIndex(0x2B60), 0x13EE, 0, sub_004370B0_ShowLoginScreen, 0, 1, 0);
        return 1;
    }

    MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
    return 0;
}

#pragma pack(push, 1)
struct d2data_0070CB88_t
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

extern "C" struct d2data_0070CB88_t gData_0070CB88; // 0x0070CB88

extern "C" struct d2data_0070CB88_t gData_0070CB88 = {
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
}; // 0x0070CB88
