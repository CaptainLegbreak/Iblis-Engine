#include "D2Launch.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct SMSGHANDLER_PARAMS;
struct D2LaunchCharEntryStrc;
struct D2LaunchCharSelectStrc;
struct D2LaunchGameRecStrc;
struct D2CompositeUnitStrc;
struct D2CelFileStrc;
struct D2LaunchCharEntryStrc
{
    char szName[0x100];                                     // 0x000
    Unicode wszName[0x100];                                 // 0x100
    unsigned char aFlags[16];                               // 0x300
    unsigned char aColors[16];                              // 0x310
    unsigned char nType;                                    // 0x320
    unsigned char unk0x321;                                 // 0x321
    union
    {
        unsigned short nLevel;                              // 0x322
        short nWord322;
    };
    union
    {
        struct
        {
            union
            {
                unsigned short wFlags;                      // 0x324
                short nWord324;
            };
            short nWord326;                                 // 0x326
        };
        int nFlags;                                         // 0x324
    };
    short nWord328;                                         // 0x328
    char szCode32A[4];                                      // 0x32A
    union
    {
        unsigned char nByte32E;                             // 0x32E
        char cByte32E;
    };
    union
    {
        unsigned char nByte32F;                             // 0x32F
        char cByte32F;
    };
    union
    {
        unsigned char nByte330;                             // 0x330
        char cByte330;
    };
    char unk0x331[3];                                       // 0x331
    int nState;                                             // 0x334
    union
    {
        D2CompositeUnitStrc* pCompositeUnit;                // 0x338
        D2CelFileStrc* pCellFile;
        void* pAnim;
    };
    int unk0x33C;                                           // 0x33C
    unsigned int nKeyLow;                                   // 0x340
    unsigned int nKeyHigh;                                  // 0x344
    union
    {
        unsigned int nExpireTime;                           // 0x348
        int nFlag348;
    };
    D2LaunchCharEntryStrc* pNext;                           // 0x34C
};
struct D2LaunchCharSelectStrc
{
    char unk0x000[0x210];
    char nMode;
};
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605
extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
void __stdcall sub_00411320_CapitalizeWords(char* szText); // 0x00411320
char* __fastcall FOG_inet_ntoa(int nAddress); // 0x0040E080
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl); // 0x004FBD20
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int nLineNum, int nColumn); // 0x004FCD40
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
void __fastcall EDITBOX_SetText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __fastcall sub_00500960_IsPressed(D2WinControlStrc* pButton); // 0x00500960
void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __fastcall MAINMENUS_JoinGame(D2LaunchCharEntryStrc* pEntry, unsigned short wFlags, int nType, char* szName); // 0x00434A00
int __fastcall MAINMENUS_DeleteCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x00434960
int __fastcall MAINMENUS_UpgradeCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x004349B0
void __fastcall MAINMENUS_ShowExpansionMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00435180
int __stdcall sub_004370B0_ShowLoginScreen(int nArg); // 0x004370B0
void __cdecl CHARSEL_InitCharSelectScreen(); // 0x0043B080
void __fastcall MAINMENUS_DeleteCharFiles(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x0043C750
int __fastcall CHATDLG_UpdateSaveFlags(const char* szName); // 0x0043CAA0
int __stdcall sub_0043E6C0_OnError(int nArg); // 0x0043E6C0
int __cdecl CHATDLG_PostClearMessage(); // 0x0043E570
int __fastcall CHATDLG_WriteUserData(int nA, int nB, int nC, int nD); // 0x0043F5F0
void __cdecl CHATDLG_CreateChatScreen(); // 0x0043FC20
int __fastcall CHATDLG_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37); // 0x0043FFA0
void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140
void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0
void __fastcall CHATDLG_JoinChannel(const char* szText); // 0x004411E0
int __fastcall CHATDLG_SendChatText(char* szText, int bWhisper); // 0x004428D0
int __fastcall CHATDLG_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord); // 0x004438E0
extern char gszLevelDiffText[]; // 0x0070EBD0
extern char gszMaxPlayersText[]; // 0x0070EBD4
extern D2LaunchCharSelectStrc* gpCharSelect_007795D4; // 0x007795D4
extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0
extern D2WinControlStrc* gpControl_00779C80; // 0x00779C80
extern int gnCounter_00779DDC; // 0x00779DDC
extern D2LaunchGameRecStrc gaNewGames[]; // 0x0077BDC8
extern D2LaunchGameRecStrc gaGames[]; // 0x0078A440
extern D2WinControlStrc* gpGameText_00798BC4; // 0x00798BC4
extern D2WinControlStrc* gpJoinName; // 0x00798BD4
extern D2WinControlStrc* gpJoinPassword_00798BD8; // 0x00798BD8
extern D2WinControlStrc* gpCreateButton; // 0x00798C28
extern D2WinControlStrc* gpCreateName; // 0x00798C2C
extern D2WinControlStrc* gpEditBox_00798C3C; // 0x00798C3C
extern D2WinControlStrc* gpLevelDiffCheck; // 0x00798C40
extern D2WinControlStrc* gpSubmitEditA; // 0x00798C80
extern D2WinControlStrc* gpSubmitEditB; // 0x00798C84
extern D2WinControlStrc* gpSubmitEditC; // 0x00798C88
extern int gnSubmitMode; // 0x00798CAC
char* __fastcall MAINMENUS_GetSlotName(int nIndex); // 0x00430B50
void __cdecl CHARSEL_UpdateStatus(); // 0x0043A270
extern int gbFlag_00779C6C; // 0x00779C6C
extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90
extern int gnBusy; // 0x00779DAC
extern char* gpszName; // 0x00779DB0
extern unsigned long gdwStartTick; // 0x00779DB4
static void CHARSEL_SelectNamedSlot(const char* szName); // 0x00437CB0
extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4
extern int gbCharSelBusy; // 0x00779DA0
extern D2LaunchCharEntryStrc* gpCharList; // 0x00779DBC
extern D2WinControlStrc* gpChannelOkButton; // 0x0077BCEC
extern D2WinControlStrc* gpGameList; // 0x00798BC0
extern D2WinControlStrc* gpJoinButton; // 0x00798BCC
extern int gnLastGameCount; // 0x00798CC8
extern char gbRealmNamesInit;                                                             // 0x00779DA8
extern Unicode gwszRealmNames[7][0x100];                                                  // 0x00779DF0
#pragma intrinsic(strcpy)
extern "C" char* __cdecl strcat(char* szDest, const char* szSource);
#pragma intrinsic(strcat, strlen)
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0
void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB);                                      // 0x004FB740
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall D2Win_10046(D2WinControlStrc* pControl, const char* szText, int nArg);            // 0x004FCFF0
void __stdcall D2Win_10152(D2CompositeUnitStrc* pCompositeUnit, int nX);                              // 0x005052B0
void __stdcall D2Win_10153(D2CompositeUnitStrc* pCompositeUnit, int nY);                              // 0x005052F0
void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags);                                // 0x00505360
const char* __stdcall D2Win_10161(int nA, int nB, int nC, int nD);                                         // 0x005068A0
int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0
extern const int gnFlagSet0_006CE278;                                                                       // 0x006CE278
extern const int gdwBitMask5;                                                                       // 0x006CE27C
extern const int gnFlagClear0;                                                                     // 0x006CE2F8
extern const int gnFlagClear1;                                                                     // 0x006CE2FC
extern int gnVisibleRows;                                                                          // 0x0070CC0C
extern int gnLaunchMode;                                                                           // 0x007795EC
extern int gnListTop_007799FC;                                                                                     // 0x007799FC
extern D2WinControlStrc* gapRowControls[];                                                         // 0x00779A20
extern int gnTopRow;                                                                               // 0x00779DC8
extern D2WinControlStrc* gpControl_00779DD0;                                                                // 0x00779DD0
static Unicode* CHARSEL_GetClassName(Unicode* pBuffer, int nClass); // 0x00437F60
static int CHARSEL_IsTestRealm(const Unicode* pName); // 0x00437D20
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
extern int gnGlobal_00779DC4;                                                                               // 0x00779DC4
int __cdecl FOG_IsExpansion();                                                                 // 0x00408F20
extern "C" const char gszCharSelFile[];                                                            // 0x006D4DBC
extern int gdwGlobal_00779DA4;                                                                              // 0x00779DA4
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
void __cdecl CHARSEL_RefreshCharList();                                                                        // 0x00438560
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode);                                // 0x005042F0
void __stdcall D2Win_10149(D2CompositeUnitStrc* pCompositeUnit, unsigned char nValue);                     // 0x005051A0
void __stdcall D2Win_10151(D2CompositeUnitStrc* pCompositeUnit, int nFrame);                               // 0x00505260
D2CompositeUnitStrc* __stdcall D2COMP_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors); // 0x005066C0
unsigned short __stdcall FOG_Decode14BitsFromString(const unsigned char* pData);                           // 0x006BBF20
static int __stdcall CHARSEL_AddCharEntry(const char* szName, const char* szStats, int nFlag, unsigned int nKeyLow, unsigned int nKeyHigh, const char* szRealm); // 0x00438AD0
#pragma intrinsic(strlen)
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);
int __fastcall FOG_GetSavePath(char* szPath, int nSize);                                           // 0x00407050
int __fastcall sub_0043C8A0(const char* szName, char* szPath);                                              // 0x0043C8A0
extern char gszCharName[256];                                                                             // 0x00779B68
extern int gnCharCount;                                                                                   // 0x00779DE0
static int CHARSEL_IsNotListedCode(int nValue); // 0x00438030
extern int gnSelected; // 0x0070CC00
extern int gnSelectionA; // 0x0070CC04
extern int gnSelectionB; // 0x0070CC08
extern int gnCount_00779DC4; // 0x00779DC4
extern int gbFlag_00779DD8; // 0x00779DD8
static D2LaunchCharEntryStrc* gpCurrentCharEntry; // 0x00779DC0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwInverseMasks[]; // 0x006CE2E8
extern "C" const char gszCharSelFile[]; // 0x006D4DBC
extern "C" const char gszNameTagFormat[]; // 0x006D4E34
extern "C" const char gszLevelFormat[]; // 0x006D4E24
int __cdecl CHARSEL_UpdateSelection(); // 0x004390A0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall SMemCopy(void*,const void*,unsigned int); // 0x0041D2A0
void __fastcall CONTROL_SetEnabled(D2WinControlStrc*,int); // 0x004F96F0
void __fastcall CONTROL_SetVisible(D2WinControlStrc*,int); // 0x004F9740
void __stdcall IMAGE_SetCoordinates(D2WinControlStrc*,int,void*); // 0x004FD0B0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc*,const Unicode*,int,int,int); // 0x004FC9B0
void __stdcall sub_005041B0_FreeAnim(void*,int); // 0x005041B0
void __stdcall sub_005051A0_SetAnimField(void*,int); // 0x005051A0
void __stdcall sub_00505260_SetAnimField(void*,int); // 0x00505260
void __fastcall sub_005042F0_SetAnimMode(void*,int); // 0x005042F0
void __stdcall sub_005052B0_SetAnimX(void*,int); // 0x005052B0
void __stdcall sub_005052F0_SetAnimY(void*,int); // 0x005052F0
void __stdcall sub_00505360_SetAnimFlags(void*,unsigned int); // 0x00505360
extern D2WinControlStrc* gpCharDescriptionText; // 0x007799F0
extern D2WinControlStrc* gpControl_007799F4; // 0x007799F4
extern D2WinControlStrc* gpScrollUpButton; // 0x00779A1C
extern D2WinControlStrc* gpCharNameText; // 0x00779B60
extern D2WinControlStrc* gpScrollDownButton; // 0x00779B64
extern D2WinControlStrc* gpControl_00779C68; // 0x00779C68
extern D2WinControlStrc* gpControl_00779C70; // 0x00779C70
extern D2WinControlStrc* gpControl_00779C78; // 0x00779C78
extern D2WinControlStrc* gpControl_00779D94; // 0x00779D94
extern void* ganSlotY[]; // 0x007799FC
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile);                                  // 0x006CC1D8
extern int gnGlobal_007795EC;                                                                               // 0x007795EC
extern int gnGlobal_0070CC04;                                                                               // 0x0070CC04
extern int gnGlobal_0070CC08;                                                                               // 0x0070CC08
extern int gnGlobal_00779DD8;                                                                               // 0x00779DD8
void __fastcall CHARSEL_CacheStore(const char* szKey, const void* pData, unsigned int nSize); // 0x00437AB0
void __cdecl CHARSEL_FreeCache();                                                                      // 0x00437B90
int __cdecl CHARSEL_Redraw(); // 0x00439210
extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId);                                           // 0x0042F430
void __cdecl CHARSEL_DisconnectBattleNet();                                                                                // 0x0043B9A0
static int CHARSEL_FindSlotByName(const char* szName); // 0x00437A20
struct D2WinTextBoxStrc;
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
int __cdecl GAME_GetSlotNameCount(); // 0x00430B40
void __cdecl CHARSEL_CreateCharInfoControls(); // 0x00437BF0
void __cdecl CHARSEL_RefreshCharEntry(); // 0x0043A650
int __stdcall D2Win_10033(D2WinControlStrc* a1, int a2); // 0x004FA470
int __fastcall D2Win_10062(D2WinTextBoxStrc* pTextBox, int nWrappedLineGap, int nLineGap); // 0x004FB740
void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FB9D0
extern D2WinControlStrc* gpNameControl;        // 0x007799E8
extern D2WinControlStrc* gpControl_007799EC;        // 0x007799EC
extern char gszPreferredRealm[]; // 0x00779A40
extern D2WinControlStrc* gpControl_00779C74;        // 0x00779C74
extern D2WinControlStrc* gpControl_00779C7C;        // 0x00779C7C
extern D2WinControlStrc* gpControl_00779D88;        // 0x00779D88
extern D2WinControlStrc* gpControl_00779D9C;        // 0x00779D9C
void __cdecl CHATDLG_UpdateCreateButton(); // 0x00443630
struct Unicode;
struct D2FileTimeStrc;
struct D2StatusStrc;
// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);
void __fastcall MAINMENUS_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone); // 0x00433130
void __fastcall MAINMENUS_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone); // 0x004331C0
void __fastcall MAINMENUS_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone); // 0x004332B0
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330
void __fastcall MAINMENUS_SetValue(int nValue); // 0x0042FF10
extern D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern int gnLogonRetries; // 0x0070CC4C
void __stdcall CHARSEL_HandleCharList(const char* szName, unsigned char* pPacket, int bFlag); // 0x0043AAB0
extern char gszLastAccount[16]; // 0x0077ABF4
// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00437A20
static int CHARSEL_FindSlotByName(const char* szName)
{
    for (int i = 0; ; ++i)
    {
        char* szSlot = i < GAME_GetSlotNameCount() ? MAINMENUS_GetSlotName(i) : 0;
        if (!szSlot)
        {
            break;
        }

        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
        {
            return 1;
        }
    }

    return 0;
}
struct D2WinControlStrc;
// 0x00437CB0
static void CHARSEL_SelectNamedSlot(const char* szName)
{
    if (!gbFlag_00779C6C)
        return;

    int i = 0;
    char* szSlot;
    while ((szSlot = (i < GAME_GetSlotNameCount() ? MAINMENUS_GetSlotName(i) : 0)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            D2Win_10188(gpNameControl, i, 1);
        ++i;
    }
}
// build: symbol ?CHARSEL_ShowConnectError@* 0x0043A1F0
static void CHARSEL_ShowConnectError(int nError)
{
    int nStringId;
    switch (nError)
    {
    case 0x7E:
        nStringId = 0x2B99;
        break;
    case 0x7F:
        nStringId = 0x2B9A;
        break;
    default:
        nStringId = 0x2B3A;
        break;
    }

    gdwGlobal_00779DB8 = 1;
    gnBusy = 0;
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(nStringId), 4, 0, 0);
    CONTROL_SetEnabled(gpControl_00779D90, 0);
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl, -1, 4);
}
// build: symbol ?CHARSEL_PollConnect@* 0x0043AC00
int __stdcall CHARSEL_PollConnect(int nUnused)
{
    switch (gnBusy)
    {
    case 1:
        if (gbFlag_00779C6C)
            D2Win_10188(gpNameControl, -1, 4);
        CHARSEL_SelectNamedSlot(gpszName);
// build: symbol ?MAINMENUS_ConnectToRealm@* 0x00432480
        MAINMENUS_ConnectToRealm(gpszName, 1);
        gnBusy = 2;
        gdwStartTick = GetTickCount();
        break;

    case 2:
        CHARSEL_UpdateStatus();
        switch (sub_00432400_GetStatus())
        {
        case 0:
// build: symbol ?MCPCONNECT_SetPacket@* 0x00449E70
            MCPCONNECT_SetPacket(0, 0);
            gnBusy = 3;
// build: symbol ?VIEW_SendMcpCharListRequest@* 0x0044AAB0
            if (!VIEW_SendMcpCharListRequest())
// build: symbol ?GAME_GetConnectError@* 0x00449C00
                CHARSEL_ShowConnectError(GAME_GetConnectError());
            break;
        case 2:
            CHARSEL_ShowConnectError(GAME_GetConnectError());
            break;
        }
        break;

    case 3:
    {
        CHARSEL_UpdateStatus();
        sub_00449B70_Receive();
        int pPacket = sub_00449E60();
        if (pPacket)
        {
            gnBusy = 0;
            if (gbFlag_00779C6C)
                D2Win_10188(gpNameControl, -1, 4);
            CHARSEL_HandleCharList(gpszName, pPacket, 1);
        }
        break;
    }
    }

    return 1;
}
// build: symbol ?CHARSEL_IsTestRealm@* 0x00437D20
static int CHARSEL_IsTestRealm(const Unicode* pName)
{
    if (!gbRealmNamesInit)
    {
        char szBuffer[0x100];
        gbRealmNamesInit = 1;
        strcpy(szBuffer, "Testv104");
        Unicode::win2Unicode(gwszRealmNames[0], szBuffer, 255);
        strcpy(szBuffer, "FatRealm");
        Unicode::win2Unicode(gwszRealmNames[1], szBuffer, 255);
        strcpy(szBuffer, "BetaWest");
        Unicode::win2Unicode(gwszRealmNames[2], szBuffer, 255);
        strcpy(szBuffer, "BetaEurope");
        Unicode::win2Unicode(gwszRealmNames[3], szBuffer, 255);
        strcpy(szBuffer, "BetaUSWest");
        Unicode::win2Unicode(gwszRealmNames[4], szBuffer, 255);
        strcpy(szBuffer, "BetaUSEast");
        Unicode::win2Unicode(gwszRealmNames[5], szBuffer, 255);
        strcpy(szBuffer, "BetaAsia");
        Unicode::win2Unicode(gwszRealmNames[6], szBuffer, 255);
    }

    for (int i = 0; i < 7; ++i)
    {
        if (!Unicode::strcmp(pName, gwszRealmNames[i]))
        {
            return 1;
        }
    }
    return 0;
}
int __stdcall sub_M216_Emit_00437D20(const Unicode* pName, int n)
{
    return CHARSEL_IsTestRealm(pName) + n;
}
static Unicode* CHARSEL_GetClassName(Unicode* pBuffer, int nClass)
{
    switch (nClass)
    {
    case 0:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAB));
    case 1:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAA));
    case 2:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA9));
    case 3:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA8));
    case 4:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA7));
    case 5:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2771));
    case 6:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2772));
    }

    return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x1507));
}
// build: symbol ?CHARSEL_GetDaysLeft@* 0x004380B0
static inline unsigned int CHARSEL_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}
void __cdecl CHARSEL_UpdateCharList(); // 0x004380F0
static inline int sub_F4B0_IsMaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}
// build: symbol ?CHARSEL_AddCharEntry@* 0x00438AD0
static int __stdcall CHARSEL_AddCharEntry(const char* szName, const char* szStats, int nFlag, unsigned int nKeyLow, unsigned int nKeyHigh, const char* szRealm)
{
    D2LaunchCharEntryStrc* pEntry = (D2LaunchCharEntryStrc*)FOG_Alloc(sizeof(D2LaunchCharEntryStrc), gszCharSelFile, 0x414, 0);
    pEntry->nKeyLow = nKeyLow;
    pEntry->nKeyHigh = nKeyHigh;
    pEntry->nFlag348 = nFlag;
    SStrCopy(pEntry->szName, szName, 0x7FFFFFFF);

    Unicode* pText = pEntry->wszName;
    if (szRealm)
    {
        Unicode::win2Unicode(pText, szRealm, 255);
    }
    else
    {
        pText->wChar = 0;
    }

    const unsigned char* pData = (const unsigned char*)szStats;
    pEntry->nWord326 = FOG_Decode14BitsFromString(pData);
    pData += 2;
    if (CHARSEL_IsTestRealm(pText))
    {
        char szText[0x100];
        Unicode::unicode2Win(szText, pText, 255);
        MAINMENUS_DeleteCharFiles(pEntry, szText);
        return 0;
    }

    {
        int i;
        for (i = 0; i < 11; ++i)
        {
            pEntry->aFlags[i] = *pData++;
        }

        for (; i < 16; ++i)
        {
            pEntry->aFlags[i] = 0xFF;
        }
    }

    pEntry->nType = *pData - 1;
    ++pData;
    {
        int i;
        for (i = 0; i < 11; ++i)
        {
            pEntry->aColors[i] = *pData++;
        }

        for (; i < 16; ++i)
        {
            pEntry->aColors[i] = 0xFF;
        }
    }

    pEntry->pNext = 0;
    pEntry->nWord322 = *pData++;
    pEntry->nWord324 = FOG_Decode14BitsFromString(pData);
    pData += 2;
    pEntry->nWord328 = FOG_Decode14BitsFromString(pData);
    pData += 2;
    pEntry->nByte32E = *pData++;
    pEntry->nByte32E = pEntry->nByte32E == 0xFF ? 0 : pEntry->nByte32E;
    pEntry->nByte32F = *pData++;
    pEntry->nByte32F = pEntry->nByte32F == 0xFF ? 0 : pEntry->nByte32F;
    pEntry->nByte330 = *pData++;
    pEntry->nByte330 = pEntry->nByte330 == 0xFF ? 0 : pEntry->nByte330;
    strncpy(pEntry->szCode32A, (const char*)pData, 3);

    unsigned char nSel = pEntry->nType;
    int nMode = 5;
    if (pEntry->nWord324 & 4)
    {
        if (pEntry->nWord324 & 8)
        {
            nSel = sub_F4B0_IsMaleClass(nSel) ? 9 : 8;
        }
        else if (FOG_IsExpansion() || pEntry->nType < 5)
        {
            nMode = 1;
        }
    }

    pEntry->pCompositeUnit = D2COMP_CreateCompositeUnit(nSel, nMode, pEntry->aFlags, pEntry->aColors);
    if (!pEntry->pCompositeUnit)
    {
        for (int j = 0; j < 16; ++j)
        {
            pEntry->aFlags[j] = 0;
            pEntry->aColors[j] = 0xFF;
        }

        pEntry->aFlags[1] = 1;
        pEntry->pCompositeUnit = D2COMP_CreateCompositeUnit(7, 5, pEntry->aFlags, pEntry->aColors);
    }

    D2_ASSERT(pEntry->pCompositeUnit, 0x4BE);
    pEntry->nState = 0;
    D2Win_10149(pEntry->pCompositeUnit, 0);
    D2Win_10151(pEntry->pCompositeUnit, 0);
    D2Win_10143(pEntry->pCompositeUnit, 5);

    if (gpCharList)
    {
        D2LaunchCharEntryStrc* pPrev = 0;
        D2LaunchCharEntryStrc* pCur = gpCharList;
        if (FOG_IsExpansion())
        {
            while (pCur)
            {
                if (nKeyHigh > pCur->nKeyHigh || (nKeyHigh == pCur->nKeyHigh && nKeyLow > pCur->nKeyLow))
                {
                    break;
                }

                pPrev = pCur;
                pCur = pCur->pNext;
            }

            if (pPrev)
            {
                pEntry->pNext = pPrev->pNext;
                pPrev->pNext = pEntry;
            }
            else
            {
                pEntry->pNext = gpCharList;
                gpCharList = pEntry;
            }
        }
        else
        {
            while (pCur->pNext)
            {
                pCur = pCur->pNext;
            }

            pCur->pNext = pEntry;
        }
    }
    else
    {
        gpCharList = pEntry;
    }

    gnGlobal_00779DC4 += 1;
    CHARSEL_RefreshCharList();
    gdwGlobal_00779DA4 = 1;
    return 1;
}
static inline int CharSel_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}
int __cdecl CHARSEL_ScanCharFiles(); // 0x00438F70
void __cdecl sub_LEG_Emit_00438F70()
{
    CHARSEL_ScanCharFiles();
}
void __stdcall sub_LEG_Emit_00438AD0(const char* szName, char* szPath, int nArg3, unsigned int nTimeLow, unsigned int nTimeHigh, int nMode)
{
    CHARSEL_AddCharEntry(szName, szPath, nArg3, nTimeLow, nTimeHigh, (const char*)nMode);
}
static int CHARSEL_IsNotListedCode(int nValue)
{
    switch (nValue)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}
int __cdecl CHARSEL_Redraw(); // 0x00439210
// build: symbol ?MAINMENUS_CreateMultiplayerScreen@* 0x004301A0
// build: symbol ?gpLaunchRecord@* 0x007795D4
void __cdecl CHATDLG_UpdateOkEnabled(); // 0x0043E660
int __stdcall CHATDLG_UseEditText(int nArg); // 0x00441240
int __stdcall CHATDLG_UseRegistryChannel(int nArg); // 0x004412A0
int __stdcall CHATDLG_OnChatLine(const Unicode* pText); // 0x004429A0
void __cdecl CHATDLG_FillGameListControl(); // 0x00442C20
int __cdecl CHATDLG_GetMaxPlayers(); // 0x00443360
int __cdecl CHATDLG_GetLevelRange(); // 0x00443390
int __stdcall CHATDLG_IncrementMaxPlayers(int nArg); // 0x004433C0
int __stdcall CHATDLG_DecrementMaxPlayers(int nArg); // 0x00443420
int __stdcall CHATDLG_IncrementLevelRange(int nArg); // 0x00443480
int __stdcall CHATDLG_DecrementLevelRange(int nArg); // 0x004434E0
void __cdecl CHATDLG_UpdateJoinButtonState(); // 0x004437E0
int __stdcall CHATDLG_JoinByName(int nArg); // 0x004439F0
int __stdcall CHARSEL_SubmitProfile(int nArg); // 0x00443F80
int __stdcall CHARSEL_SendChatLine(int nArg); // 0x00446890
// 0x0043A800
void __cdecl CHARSEL_CreateCharListControls()
{
    if (gnLaunchMode == 1)
    {
        if (FOG_IsExpansion())
        {
            CHARSEL_CreateCharInfoControls();
        }
        else
        {
// build: symbol ?MAINMENUS_CreateFromTemplate@* 0x0042F3A0
            gpControl_007799EC = MAINMENUS_CreateFromTemplate(0x73);
            D2Win_10033(gpControl_007799EC, 1);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_007799EC, 1);
            gpControl_00779C7C = MAINMENUS_CreateFromTemplate(0x74);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C7C, 1);
            gpControl_00779D9C = MAINMENUS_CreateFromTemplate(0x75);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D9C, 1);
            gpNameControl = MAINMENUS_CreateFromTemplate(0x76);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpNameControl, 1);
            gpControl_00779D88 = MAINMENUS_CreateFromTemplate(0x77);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D88, 1);
            gpControl_00779C74 = MAINMENUS_CreateFromTemplate(0x78);
            D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C74, 1);
        }

        sub_004FC9B0_SetText(gpControl_00779C7C, D2LANG_GetStringFromTblIndex(0x2B31), 0, 0, 0);
        D2Win_10062((D2WinTextBoxStrc*)gpControl_00779D9C, -6, 0);
        for (int i = 0; ; ++i)
        {
            char* szName = i < GAME_GetSlotNameCount() ? MAINMENUS_GetSlotName(i) : 0;
            if (!szName) { break; }
            D2Win_10045(gpNameControl, szName);
            if (!SStrCmpI(gszPreferredRealm, szName, 0x7FFFFFFF))
            {
                D2Win_10050_TEXTBOX_SetLine((D2WinTextBoxStrc*)gpNameControl, i);
            }
        }
        CHARSEL_RefreshCharEntry();
    }
    gbFlag_00779C6C = 1;
}
void __stdcall CHARSEL_HandleCharList(const char* szName, unsigned char* pPacket, int bFlag); // 0x0043AAB0
void __fastcall CHARSEL_JoinSelectedWithDifficulty(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0
// 0x0043B520
int __stdcall CHARSEL_OnCharSelect(int nArg)
{
    char szName[0x100];

    if (FOG_IsExpansion())
    {
        D2LaunchCharEntryStrc* pEntry = gpCharList;
        for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
        {
            if (gnSelected == i)
                break;
        }

        if (pEntry)
        {
            if (pEntry->wFlags & 0x20)
                return 1;

            int bOk;
            const Unicode* pwszName = pEntry->wszName;
            if (pwszName && pwszName->wChar)
            {
                sub_00526F70(szName, pwszName, 0xFF);
                bOk = MAINMENUS_UpgradeCharacter(pEntry, szName);
                if (!bOk)
                {
                    if (GAME_GetConnectError() != 0x7B)
                    {
                        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x145B), CHARSEL_InitCharSelectScreen);
                    }
                    else
                    {
                        Unicode wszText[0x100];
                        Unicode wszArg[0x100];
                        sub_00526F20_ToUnicode(wszArg, pEntry->szName, 0x100);
                        sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszArg);
                        MAINMENUS_ShowText(wszText, CHARSEL_InitCharSelectScreen);
                    }
                    gbCharSelBusy = 0;
                    return 1;
                }
            }
            else
            {
                bOk = CHATDLG_UpdateSaveFlags(pEntry->szName);
            }

            if (bOk)
            {
                pEntry->wFlags |= 0x20;
                CHARSEL_RefreshCharList();
                MAINMENUS_DestroyControls();
            }
            else
            {
                MAINMENUS_ShowExpansionMessage(D2LANG_GetStringFromTblIndex(0x5570), CHARSEL_InitCharSelectScreen, 1);
            }
        }

        CONTROL_SetEnabled(gpControl_00779C80, 0);
    }
    return 1;
}
// 0x0043B6B0
int __stdcall CHARSEL_JoinSelected(int nArg)
{
    char szName[0x100];

    D2LaunchCharEntryStrc* pEntry = gpCharList;
    for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
    {
        if (gnSelected == i)
            break;
    }

    if (pEntry)
    {
        gbCharSelBusy = 1;

        const Unicode* pwszName = pEntry->wszName;
        if (pwszName && pwszName->wChar)
        {
            sub_00526F70(szName, pwszName, 0xFF);
            if (MAINMENUS_DeleteCharacter(pEntry, szName))
            {
                ++gnCounter_00779DDC;
                gbFlag_00779DD8 = 0;
                MAINMENUS_DeleteCharFiles(pEntry, szName);
            }
            else
            {
                MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x145B), CHARSEL_InitCharSelectScreen);
                gbCharSelBusy = 0;
                return 1;
            }
        }
        else
        {
            MAINMENUS_DeleteCharFiles(pEntry, &gszEmptyAssertText);
        }

        CHARSEL_InitCharSelectScreen();
        gbCharSelBusy = 0;
        return 1;
    }

    return 0;
}
// build: symbol ?CHARSEL_InitRealmScreen@* 0x0043A2B0
int __cdecl CHARSEL_InitRealmScreen()
{
    unsigned short nStringId;
    gnBusy = 0;
    if (gnLaunchMode == 1)
    {
        sub_00434060();
        const int nCount = GAME_GetSlotNameCount();
        if (nCount != -1)
        {
            if (nCount != 0)
            {
                D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x7A);
                sub_004FD830(pControl);
                sub_004FDA50(pControl);
                gpControl_00779DD0 = MAINMENUS_CreateControl(0x94);
// build: symbol ?gpCharSelectText@* 0x00779DD4
                gpCharSelectText = MAINMENUS_CreateControl(0x95);
                MAINMENUS_CreateControl(0x69);
                gpControl_00779D98 = MAINMENUS_CreateControl(0x6B);
                gpControl_00779D8C = MAINMENUS_CreateControl(0x6C);
                sub_004FC9B0_SetText(MAINMENUS_CreateControl(0x6A), D2LANG_GetStringFromTblIndex(0x2B32), 4, 0, 0);

                if (!SRegLoadString("Diablo II", "Preferred Realm", 0, gszPreferredRealm, 0x100) || !CHARSEL_FindSlotByName(gszPreferredRealm))
                {
                    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
                    const int nIndex = pRecord->nIndex;
                    SStrCopy(gszPreferredRealm, sub_005180E0(pRecord, nIndex), 0x7FFFFFFF);
                    SRegSaveString("Diablo II", "Preferred Realm", 0, gszPreferredRealm);
                    if (!CHARSEL_FindSlotByName(gszPreferredRealm))
                    {
                        const char* szFirst = GAME_GetSlotNameCount() > 0 ? MAINMENUS_GetSlotName(0) : 0;
                        SStrCopy(gszPreferredRealm, szFirst, 0x7FFFFFFF);
                        SRegSaveString("Diablo II", "Preferred Realm", 0, gszPreferredRealm);
                    }
                }
            }
            else
            {
                CHARSEL_DisconnectBattleNet();
                nStringId = 0x14AA;
                goto fail;
            }
        }
        else
        {
            CHARSEL_DisconnectBattleNet();
            nStringId = 0x14E3;
            goto fail;
        }
    }
    return 1;

fail:
    MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(nStringId), sub_004336C0);
    return 0;
}
