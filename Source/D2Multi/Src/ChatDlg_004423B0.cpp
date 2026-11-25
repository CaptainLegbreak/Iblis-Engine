#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530

class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int GetPersist();
    virtual void SetPersist(int bPersist);
};
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" size_t __cdecl strlen(const char* szString);
const char* __stdcall SStrChr(const char* szString, char nChar);                                            // 0x00413490
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit); // 0x004135D0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone);                     // 0x00440140
void __fastcall CHATDLG_JoinChannel(const char* szText);                                                       // 0x004411E0
int __fastcall CHATDLG_PrintMessage(const Unicode* pText, int nColor); // 0x0043E5F0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

extern char gaszHistory[10][0x100];                                                                // 0x0077B1D8
extern int gnHistoryCount;                                                                         // 0x0077BD50
extern int gbShowJoinLeave;                                                                        // 0x0077BD54
extern D2WinControlStrc* gpChatTextBox;                                                            // 0x0077BD8C
extern char gszLastWhisperer[];                                                                    // 0x0077B0D0
extern D2LaunchFuncsStrc* gpLaunchFuncs;                                                           // 0x0077B09C
extern D2ConfigStrc* gpCharInfo;                                                           // 0x0077BBD8
extern "C" const char gszCmdIgnorePersist[];                                                       // 0x006D56B0
extern "C" const char gszCmdIgnore[];                                                              // 0x006D56A4
extern "C" const char gszCmdUnignore[];                                                            // 0x006D568C
extern "C" const char gszCmdFilter[];                                                              // 0x006D5674
extern "C" const char gszCmdUnfilter[];                                                            // 0x006D5664

// 0x0043E6E0
static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand)
{
    if (strlen(szText) < strlen(szCommand))
        return -1;

    unsigned int nLength = strlen(szCommand);
    while (nLength--)
    {
        const int nDiff = toupper(*szText) - toupper(*szCommand);
        if (nDiff)
            return nDiff > 0 ? 1 : -1;
        ++szText;
        ++szCommand;
    }
    return 0;
}

// @ref 0x0043E780
// 0x0043E780
static int CHATDLG_NotifyCommand(const char* szText, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!CHATDLG_CompareCommand(szText, szCommand) && (szText[nLength] == ' ' || !szText[nLength]))
    {
        if (!CHATDLG_CompareCommand(szText, szCommand))
        {
            char szMessage[0x100];
            unsigned short wszMessage[0x100];
            gbShowJoinLeave = !gbShowJoinLeave;
            for (int i = 0; i < 0x100; ++i)
                wszMessage[i] = 0;
            if (gbShowJoinLeave)
                strcpy(szMessage, "Player entering/leaving notifications are enabled.");
            else
                strcpy(szMessage, "Player entering/leaving notifications are disabled.");
            sub_00526320_ToUnicode((Unicode*)wszMessage, szMessage, 0x200);
            if (gpChatTextBox)
                sub_004FC9B0_SetText(gpChatTextBox, (Unicode*)wszMessage, 3, 0, 1);
        }
        return 1;
    }
    return 0;
}

// 0x0043F510
static void CHATDLG_PushHistory(const char* szText)
{
    memmove(gaszHistory[1], gaszHistory[0], 0x900);
    strcpy(gaszHistory[0], szText);
    if (++gnHistoryCount >= 10)
        gnHistoryCount = 10;
}

// 0x0043F870
static void __stdcall CHATDLG_GetArgument(int nSize, const char* szText, char* szDest)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

static int CHATDLG_ReplyCommand(const char* szText, const char* szCommand); // 0x00442180

static __forceinline int CONSOLE_FindSecondTokenInline(const char* szText, char* szCopy, const char** ppArg)
{
    strcpy(szCopy, szText);
    char szDelim[2] = " ";
    char* pToken = strtok(szCopy, szDelim);
    int nCount = 0;
    while (pToken)
    {
        if (++nCount == 2)
        {
            *ppArg = szText + (pToken - szCopy);
            return 1;
        }
        pToken = strtok(0, szDelim);
    }
    return 0;
}

// 0x00442180
static int CHATDLG_ReplyCommand(const char* szText, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!CHATDLG_CompareCommand(szText, szCommand))
    {
        if (szText[nLength] == ' ' || !szText[nLength])
        {
            char szMessage[260];
            if (!strlen(gszLastWhisperer))
            {
                Unicode wszMessage[0x100] = {};
// build: symbol ?gszNobodyToReply@* 0x006D561C
                sprintf(szMessage, gszNobodyToReply);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox)
                    sub_004FC9B0_SetText(gpChatTextBox, wszMessage, 1, 0, 1);
                return 1;
            }

            char szPrefix[0x100];
// build: symbol ?gszCommandSpace@* 0x006D5618
            sprintf(szPrefix, gszCommandSpace, szCommand);
            char szCopy[0x100];
            const char* pMessage;
            if (!CONSOLE_FindSecondTokenInline(szText, szCopy, &pMessage))
            {
                Unicode wszMessage[0x100];
// build: symbol ?gszCorrectUsage@* 0x006D55F8
                sprintf(szMessage, gszCorrectUsage, szCommand);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox)
                    sub_004FC9B0_SetText(gpChatTextBox, wszMessage, 1, 0, 1);
                return 1;
            }
            if (!gpLaunchFuncs->pfnIsSocketConnected())
            {
                CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
                return 1;
            }

// build: symbol ?gszReplyFormat@* 0x006D55EC
            sprintf(szMessage, gszReplyFormat, gszLastWhisperer, pMessage);
            gpLaunchFuncs->pfnChatCommand(szMessage);
            return 1;
        }
    }
    return 0;
}

// 0x004423B0
void __fastcall CHATDLG_RunCommand(char* szText)
{
    CHATDLG_PushHistory(szText);
// build: symbol ?gszCmdR@* 0x006D56D4
    if (CHATDLG_ReplyCommand(szText, gszCmdR))
        return;

// build: symbol ?gszCmdReply@* 0x006D56CC
    if (CHATDLG_ReplyCommand(szText, gszCmdReply))
        return;

// build: symbol ?gszCmdD2Notify@* 0x006D56C0
    if (CHATDLG_NotifyCommand(szText, gszCmdD2Notify))
        return;

    if (!CHATDLG_CompareCommand(szText, gszCmdIgnorePersist))
    {
        sub_00611560_GetSquelchList()->SetPersist(!sub_00611560_GetSquelchList()->GetPersist());
        if (sub_00611560_GetSquelchList()->GetPersist())
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA1), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA2), 3);
        return;
    }

// build: symbol ?gszCmdSquelch@* 0x006D5698
    if (!CHATDLG_CompareCommand(szText, gszCmdIgnore) || !CHATDLG_CompareCommand(szText, gszCmdSquelch))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        CHATDLG_GetArgument(0x11, szText, szName);
        if (!SStrCmpI(&szName[1], gpCharInfo->szAccount, 0x7FFFFFFF))
            return;

        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Squelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA3), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA4), wszName);
        sub_00526700(wszMessage, wszFormat);
        CHATDLG_PrintMessage(wszMessage, 3);
        return;
    }

// build: symbol ?gszCmdUnsquelch@* 0x006D5680
    if (!CHATDLG_CompareCommand(szText, gszCmdUnignore) || !CHATDLG_CompareCommand(szText, gszCmdUnsquelch))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        CHATDLG_GetArgument(0x11, szText, szName);
        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Unsquelch(szName))
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA5), wszName);
        else
            sub_005269D0(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA6), wszName);
        sub_00526700(wszMessage, wszFormat);
        CHATDLG_PrintMessage(wszMessage, 3);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, gszCmdFilter))
    {
        char szFilter[0x104];
        CHATDLG_GetArgument(0x104, szText, szFilter);
        if (sub_00611560_GetSquelchList()->AddFilter(szFilter))
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA7), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA8), 3);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, gszCmdUnfilter))
    {
        char szFilter[0x104];
        CHATDLG_GetArgument(0x104, szText, szFilter);
        if (sub_00611560_GetSquelchList()->RemoveFilter(szFilter))
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA9), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BAA), 3);
        return;
    }

// build: symbol ?gszCmdHomeSpace@* 0x006D5638
// build: symbol ?gszCmdDefaultChannel@* 0x006D5640
// build: symbol ?gszCmdHomeChannel@* 0x006D5654
    if (!CHATDLG_CompareCommand(szText, gszCmdHomeChannel) || !CHATDLG_CompareCommand(szText, gszCmdDefaultChannel) || !CHATDLG_CompareCommand(szText, gszCmdHomeSpace))
    {
        char szChannel[0x20];
        CHATDLG_GetArgument(0x20, szText, szChannel);
// build: symbol ?gszDiabloII@* 0x006CC8B8
// build: symbol ?gszDefaultChannel@* 0x006D5504
        SRegSaveString(gszDiabloII, gszDefaultChannel, 0, szChannel);
        return;
    }

// build: symbol ?gszCmdHome@* 0x006D5630
    if (!CHATDLG_CompareCommand(szText, gszCmdHome))
    {
        char szChannel[0x20];
        if (SRegLoadString(gszDiabloII, gszDefaultChannel, 0, szChannel, 0x20))
            CHATDLG_JoinChannel(szChannel);
        return;
    }

    if (!gpLaunchFuncs->pfnIsSocketConnected())
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return;
    }

    gpLaunchFuncs->pfnChatCommand(szText);
}
