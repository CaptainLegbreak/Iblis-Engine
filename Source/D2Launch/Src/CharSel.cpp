#include "D2Launch.h"

#include "D2ClientTypes.h"

#include "D2StormTypes.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Drlg.h"

#include "D2MultiTypes.h"

#include "D2LevelTxt.h"

#include "D2Unicode.h"
#include "D2LaunchRequest.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"
#include "D2GfxApi.h"
#include "D2MCPClientApi.h"
#include "D2WinApi.h"
#include "D2MultiApi.h"

static long BNDOWNLOAD_GetTime(long* pTime);

#pragma intrinsic(strlen)

struct D2UnitStrc;

struct D2ActiveRoomStrc;

struct D2InventoryStrc;

struct D2DynamicPathStrc;

struct D2StatListStrc;

struct SMSGHANDLER_PARAMS;

struct D2CharSelCacheStrc;

struct D2StatesTxt;

struct D2DataTablesStrc;

struct D2LaunchRequestStrc;

struct D2UnitDropItemsPacketStrc;

struct D2GridCellStrc;

struct D2CelFileStrc;

struct Unicode;

struct D2ComInterfaceStrc;

struct D2ConfigStrc;

struct D2FuncRecordStrc;

struct D2LaunchCharEntryStrc;

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900

extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460

static int gnCharEntryCount; // 0x00779DC4

extern int gdwGlobal_0070CC08; // 0x0070CC08

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0

void __fastcall CHARSEL_JoinSelectedWithDifficulty(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0

void __fastcall sub_004FC660_SetValue(D2WinControlStrc* pControl, int nValue); // 0x004FC660

D2WinControlStrc* gpControl_007795E0;                                                                       // 0x007795E0

D2WinControlStrc* gpControl_007795E4;                                                                       // 0x007795E4

D2LaunchSlotStrc** gppSlots;                                                                       // 0x00779988

int gnSlotCount;                                                                                     // 0x0077998C



int __cdecl MAINMENUS_FreeSlots(); // 0x00430A20

D2CharSelCacheStrc* gpCharSelCache; // 0x00779DE8

static int gbFlag_00779C6C;             // 0x00779C6C

extern char gszBaseName_00779B68[]; // 0x00779B68


struct D2UnitDropItemsPacketStrc
{
    char nHeader;
    char bActive;
    char nUnitId[4];
    char nOtherUnitId[4];
};

struct D2GridCellStrc
{
    int nFlag;
    unsigned char nValue[4];
};

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds); // 0x006CC258

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags); // 0x00413020

extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650

void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30



void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode); // 0x00649190

int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern int gnGlobal_007111CC; // 0x007111CC

extern int gnGlobal_007111D0; // 0x007111D0

extern int gnGlobal_007111D4; // 0x007111D4

extern int gnScreenWidth; // 0x0071146C

extern int gnScreenHeight; // 0x00711470

extern void* gpGlobal_007A0634; // 0x007A0634

extern void* gpAutomapContext; // 0x007A5164

extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

void __stdcall CHARSEL_AddToScrollValue(int nDelta); // 0x00439E60

int __stdcall CHARSEL_HandleListKey(SMSGHANDLER_PARAMS* pMsg); // 0x00439E90

static int gnTopRow; // 0x00779DC8



void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450


int gnBusy; // 0x00779DAC

extern "C" unsigned int __cdecl strlen(const char* sz);

int __stdcall sub_005041B0_Destroy(D2CelFileStrc* pCellFile, int nFlag); // 0x005041B0

extern D2LaunchCharEntryStrc* gpCharEntry_00779DC0; // 0x00779DC0

struct D2WinTextBoxStrc;

struct D2WinButtonStrc;

int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0

int __stdcall CHARSEL_OnScroll(SMSGHANDLER_PARAMS* pMsg);                                              // 0x00439DF0

int __cdecl CHARSEL_InitRealmScreen();                                                                 // 0x0043A2B0

void __fastcall CHARSEL_UseName(char* szName);                                                         // 0x0043ADB0


int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x004FC6E0

D2WinControlStrc* gpControl_007799F8;                                                                       // 0x007799F8

D2WinControlStrc* gapRowControls[8]; // 0x00779A20

char gszPreferredRealm[256]; // 0x00779A40

void* gapRowControlsX[8];                                                                          // 0x00779B40

D2WinControlStrc* gpControl_00779C84;                                                                       // 0x00779C84

static int gnSelected = -1;                                                                                 // 0x0070CC00

static D2WinControlStrc* gpCharSelectText; // 0x00779DD4

static D2WinControlStrc* gpControl_00779DD0;        // 0x00779DD0

static int gnLastValue;        // 0x00779DCC

int __stdcall CHARSEL_OnCreateAccountTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B8E0

int __stdcall CHARSEL_OnChangePasswordTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B940

D2RecordHandlerFn gpfnPrevHandler; // 0x007A2764

int gbOverlaysEnabled; // 0x007A289C

int gnOverlayStep; // 0x007A3138

int gnCellOriginX; // 0x007B0A54

int gnCellOriginY; // 0x007B0A58

struct D2ListMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
};

int __stdcall CHARSEL_OnCharSelectOk(D2ListMsgStrc* pMsg); // 0x00439840

struct D2CompositeUnitStrc;

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
        char cLevel;
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

struct D2CharSaveIdStrc
{
    unsigned char f_0[0x10];
};

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    char unk0x0C[0x08];
    char szName[0x10];
    unsigned int dwFlags;
    unsigned char nClass;
    unsigned char nUnk0x29;
    unsigned char nUnk0x2A;
    unsigned char nUnk0x2B;
    long nCreateTime;
    long nSaveTime;
    char unk0x34[0x54];
    D2CharSaveIdStrc tId;
    int anUnk0x98[4];
    char unk0xA8[0xA7];
};

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200


void __cdecl MAINMENUS_DestroyControls();                                                                // 0x0042F3F0



extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout(); // 0x00432EF0

int __stdcall MAINMENUS_PollCharDelete(int nArg);                                                                       // 0x00433020

int __stdcall MAINMENUS_PollCharUpgrade(int nArg);                                                                       // 0x00433060

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);           // 0x00433380

void __cdecl CHARSEL_UpdateButtons();                                                                                // 0x0043A730

int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox); // 0x004F91C0

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB);                                      // 0x004FB740

int __fastcall sub_004FB990_GetSelection(D2WinControlStrc* pControl);                                       // 0x004FB990


int __stdcall IMAGE_SetCoordinates(D2WinControlStrc* pControl, int nColor, int nValue);                    // 0x004FD0B0

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

int __stdcall SetCurGateway(D2FuncRecordStrc* pRecord, int nIndex);                                          // 0x00518150

D2ComInterfaceStrc* __cdecl sub_00518C00();                                                           // 0x00518C00

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800


static int gnSelectionA = -999;                                                                             // 0x0070CC04
#include "D2WinApi2.h"
#include "D2BNClientApi.h"

extern D2WinControlStrc* gpGatewayList;                                                                // 0x00779590


D2WinControlStrc* gpList_0077995C;                                                                          // 0x0077995C

D2WinControlStrc* gpList_00779960;                                                                          // 0x00779960

D2WinControlStrc* gpList_00779964;                                                                          // 0x00779964

extern int gnListPos;                                                                              // 0x0077996C

D2WinControlStrc* gpControl_007799EC;        // 0x007799EC

D2WinControlStrc* gpCharDescriptionText; // 0x007799F0

D2WinControlStrc* gpControl_007799F4;                                                                       // 0x007799F4


D2WinControlStrc* gpScrollUpButton; // 0x00779A1C

D2WinControlStrc* gpCharNameText;                                                                       // 0x00779B60

D2WinControlStrc* gpScrollDownButton; // 0x00779B64

D2WinControlStrc* gpControl_00779C68;                                                                       // 0x00779C68

D2WinControlStrc* gpControl_00779C70; // 0x00779C70

D2WinControlStrc* gpControl_00779C74;        // 0x00779C74

D2WinControlStrc* gpControl_00779C78; // 0x00779C78

D2WinControlStrc* gpControl_00779C7C;        // 0x00779C7C

D2WinControlStrc* gpControl_00779C80;                                                                       // 0x00779C80

extern char gszEnteredName[256]; // 0x00779C88

D2WinControlStrc* gpControl_00779D88;        // 0x00779D88

D2WinControlStrc* gpControl_00779D90;                                                                       // 0x00779D90

D2WinControlStrc* gpControl_00779D94;                                                                       // 0x00779D94

D2WinControlStrc* gpControl_00779D9C;        // 0x00779D9C

unsigned long gdwStartTick;                                                                        // 0x00779DB4

D2LaunchCharEntryStrc* gpCharList; // 0x00779DBC

extern D2CharSaveHeaderStrc gtCharSaveHeader;                                                      // 0x0077AC10

#define gdwFlags_0077AC34 (gtCharSaveHeader.dwFlags)

extern D2CriticalSectionStrc gtChatLock;                                                           // 0x0077AE28

D2WinControlStrc* gpChannelOkButton; // 0x0077BCEC

extern int gdwGlobal_0077BD50;                                                                              // 0x0077BD50

extern D2ChatMessageStrc* gpChatQueueHead;                                                         // 0x0077BDAC

D2ChatMessageStrc* gpChatQueueTail;                                                                // 0x0077BDB0

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6

void __fastcall sub_A15_UseText(const Unicode* pText);

void __cdecl sub_00439CC0_CreateControls(); // 0x00439CC0

void __cdecl CHARSEL_UpdateStatus(); // 0x0043A270

#pragma intrinsic(memset)



D2CompositeUnitStrc* __stdcall sub_005066C0_CreateComposite(int nSel, int nMode, unsigned char* pFlags, unsigned char* pColors);

char* gpszName; // 0x00779DB0

unsigned long gdwLastClick; // 0x00779DEC

extern "C" int __cdecl tolower(int nChar);

extern const char gacCDKeyMap[];

void __cdecl MAINMENUS_ShowLocalAddress();                                                                                // 0x0042FF20

void __cdecl MAINMENUS_UpdateTwoEditOk();                                                                                // 0x00436CF0

int __stdcall MAINMENUS_OnTwoEditChange(int nArg);                                                                       // 0x00436D40


int __cdecl CHATDLG_DestroyGameListControls();                                                                                 // 0x00444E20

extern D2WinControlStrc* gpControl_00779338;                                                                // 0x00779338

extern D2WinControlStrc* gpControl_00779344;                                                                // 0x00779344

extern D2WinControlStrc* gpControl_00779588;                                                                // 0x00779588

extern D2WinControlStrc* gpControl_007795A0;                                                                // 0x007795A0

extern D2WinControlStrc* gpControl_007795A4;                                                                // 0x007795A4

extern int gbGatewayFlag;                                                                          // 0x00779954

D2WinControlStrc* gpEdit_007799CC;                                                                          // 0x007799CC

D2WinControlStrc* gpEdit_007799D0;                                                                          // 0x007799D0

D2WinControlStrc* gpControl_007799D4;                                                                       // 0x007799D4

extern int gdwGlobal_007799D8;                                                                              // 0x007799D8

extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C

D2WinControlStrc* gpControl_0077BD90;                                                                       // 0x0077BD90

extern D2WinControlStrc* gpWaitText_0077BD9C;                                                               // 0x0077BD9C

extern int gdwGlobal_00798CC0;                                                                              // 0x00798CC0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinTimerStrc;

class BNGatewayAccess;


void __cdecl CHARSEL_CreateCharListControls(); // 0x0043A800




void __cdecl CHARSEL_FreeCharList(); // 0x00438EA0

void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nColor); // 0x004FCFF0

void __cdecl CHARSEL_ShowMessage(); // 0x0043A5D0

void __cdecl sub_00438F70();

extern D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0

int gdwGlobal_00779DB8; // 0x00779DB8


class BNGatewayAccess
{
public:
    const char* __stdcall Realm(int nGateway);                                                                 // 0x005180E0

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
};




void __cdecl CHARSEL_InitCharList(); // 0x0043AE30

int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

extern D2CelFileStrc* gpCharSelectBckgCelFile; // 0x00779768

D2WinControlStrc* gpControl_00779D8C; // 0x00779D8C

void __cdecl MAINMENUS_UpdateProgress(); // 0x0042F990

extern int gdwGlobal_0077AC04; // 0x0077AC04

D2WinControlStrc* gpControl_00779D98; // 0x00779D98

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2LaunchCharSelectStrc;

struct D2LaunchGameRecStrc;

#pragma pack(push, 1)

struct D2LaunchCharSelectStrc
{
    char unk0x000[0x19];
    int nState;                                             // 0x019
    char unk0x01D[0x1F3];
    char nMode;                                             // 0x210
    char unk0x211[0x190];
    unsigned char aFlags[16];                               // 0x3A1
    unsigned char aColors[16];                              // 0x3B1
    char nLevel;                                            // 0x3C1
    char nByte0x3C2;                                        // 0x3C2
    char unk0x3C3[0x08];
    unsigned short wFlags;                                  // 0x3CB
};

#pragma pack(pop)

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB

extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605

extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl); // 0x004FBD20

void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0

int __fastcall D2Win_10053(D2WinTextBoxStrc* ptTextData, int nLine); // 0x004FBA30

int __fastcall sub_00500960_IsPressed(D2WinControlStrc* pButton); // 0x00500960

void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540

void __fastcall MAINMENUS_JoinGame(D2LaunchCharEntryStrc* pEntry, unsigned short wFlags, int nType, char* szName); // 0x00434A00

int __fastcall MAINMENUS_DeleteCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x00434960

int __fastcall MAINMENUS_UpgradeCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x004349B0

void __fastcall MAINMENUS_ShowExpansionMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00435180

int __stdcall sub_004370B0_ShowLoginScreen(int nArg); // 0x004370B0


void __fastcall MAINMENUS_DeleteCharFiles(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x0043C750

int __stdcall sub_0043E6C0_OnError(int nArg); // 0x0043E6C0

int __fastcall CHATDLG_WriteUserData(int nA, int nB, int nC, int nD); // 0x0043F5F0

void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140

void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0

extern char gszLevelDiffText[]; // 0x0070EBD0

extern char gszMaxPlayersText[]; // 0x0070EBD4

extern D2LaunchCharSelectStrc* gpCharSelect_007795D4; // 0x007795D4

extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

extern int gnCounter_00779DDC; // 0x00779DDC

extern D2LaunchGameRecStrc gaNewGames[]; // 0x0077BDC8

extern D2LaunchGameRecStrc gaGames[]; // 0x0078A440

extern D2WinControlStrc* gpGameText_00798BC4; // 0x00798BC4

extern D2WinControlStrc* gpJoinPassword_00798BD8; // 0x00798BD8

extern D2WinControlStrc* gpEditBox_00798C3C; // 0x00798C3C

extern D2WinControlStrc* gpLevelDiffCheck; // 0x00798C40

static void CHARSEL_SelectNamedSlot(const char* szName); // 0x00437CB0

D2WinControlStrc* gpButton_007799E4; // 0x007799E4

int gbCharSelBusy; // 0x00779DA0

D2WinControlStrc* gpGameList; // 0x00798BC0

D2WinControlStrc* gpJoinButton; // 0x00798BCC

int gnLastGameCount; // 0x00798CC8

char gbRealmNamesInit;                                                             // 0x00779DA8

Unicode gwszRealmNames[7][0x100];                                                  // 0x00779DF0

#pragma intrinsic(strcpy)

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

#pragma intrinsic(strcat, strlen)



void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags);                                // 0x00505360

const char* __stdcall D2Win_10161(int nA, int nB, int nC, int nD);                                         // 0x005068A0


Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

extern const int gnFlagSet0_006CE278;                                                                       // 0x006CE278

extern const int gdwBitMask5;                                                                       // 0x006CE27C

extern const int gnFlagClear0;                                                                     // 0x006CE2F8

extern const int gnFlagClear1;                                                                     // 0x006CE2FC


int ganRowValues_007799FC[8];                                                                                   // 0x007799FC

static Unicode* CHARSEL_GetClassName(Unicode* pBuffer, int nClass); // 0x00437F60

static int CHARSEL_IsTestRealm(const Unicode* pName); // 0x00437D20


extern int gnGlobal_00779DC4;                                                                               // 0x00779DC4


extern "C" const char gszCharSelFile[];                                                            // 0x006D4DBC

extern int gdwGlobal_00779DA4;                                                                              // 0x00779DA4

D2CompositeUnitStrc* __stdcall D2COMP_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors); // 0x005066C0

int __stdcall FOG_Decode14BitsFromString(const unsigned char* pBuffer); // 0x006BBF20

static int __stdcall CHARSEL_AddCharEntry(const char* szName, const char* szStats, int nFlag, unsigned int nKeyLow, unsigned int nKeyHigh, const char* szRealm); // 0x00438AD0

#pragma intrinsic(strlen)


extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);


int __fastcall sub_0043C8A0(const char* szName, char* szPath);                                              // 0x0043C8A0

char gszCharName[256];                                                                             // 0x00779B68

int gnCharCount;                                                                                   // 0x00779DE0

static int CHARSEL_IsNotListedCode(int nValue); // 0x00438030

static int gnSelectionB = -999;                                                                             // 0x0070CC08

extern int gnCount_00779DC4; // 0x00779DC4

static D2LaunchCharEntryStrc* gpCurrentCharEntry; // 0x00779DC0

extern unsigned int gdwInverseMasks[]; // 0x006CE2E8

extern "C" const char gszNameTagFormat[]; // 0x006D4E34

extern "C" const char gszLevelFormat[]; // 0x006D4E24

int __cdecl CHARSEL_UpdateSelection(); // 0x004390A0


void __stdcall IMAGE_SetCoordinates(D2WinControlStrc*,int,void*); // 0x004FD0B0


void __stdcall sub_005041B0_FreeAnim(void*,int); // 0x005041B0

void __stdcall sub_005051A0_SetAnimField(void*,int); // 0x005051A0

void __stdcall sub_00505260_SetAnimField(void*,int); // 0x00505260

void __fastcall sub_005042F0_SetAnimMode(void*,int); // 0x005042F0

void __stdcall sub_005052B0_SetAnimX(void*,int); // 0x005052B0

void __stdcall sub_005052F0_SetAnimY(void*,int); // 0x005052F0

void __stdcall sub_00505360_SetAnimFlags(void*,unsigned int); // 0x00505360

extern void* ganSlotY[]; // 0x007799FC


extern int gnGlobal_007795EC;                                                                               // 0x007795EC

extern int gnGlobal_0070CC04;                                                                               // 0x0070CC04

extern int gnGlobal_0070CC08;                                                                               // 0x0070CC08

extern int gnGlobal_00779DD8;                                                                               // 0x00779DD8

void __fastcall CHARSEL_CacheStore(const char* szKey, const void* pData, unsigned int nSize); // 0x00437AB0

void __cdecl CHARSEL_FreeCache();                                                                      // 0x00437B90

static int CHARSEL_FindSlotByName(const char* szName); // 0x00437A20

void __cdecl CHARSEL_CreateCharInfoControls(); // 0x00437BF0

void __cdecl CHARSEL_RefreshCharEntry(); // 0x0043A650


D2WinControlStrc* gpNameControl;        // 0x007799E8

struct D2FileTimeStrc;

struct D2StatusStrc;

void __fastcall MAINMENUS_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone); // 0x00433130

void __fastcall MAINMENUS_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone); // 0x004331C0

void __fastcall MAINMENUS_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone); // 0x004332B0

void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330

void __fastcall MAINMENUS_SetValue(int nValue); // 0x0042FF10

extern int gnLogonRetries; // 0x0070CC4C

char gszLastAccount[16]; // 0x0077ABF4

static void CHARSEL_ShowConnectError(int nError);

int __stdcall CHARSEL_PollConnect(int nUnused);

static void CHARSEL_SelectNamedSlot(const char* szName);

static int CHARSEL_FindSlotByName(const char* szName);

// 0x0042E5B0
char* __cdecl CHARSEL_StrStr(char* szString, const char* szSubString)
{
    return strstr(szString, szSubString);
}

extern "C" unsigned short __cdecl _rotl16(unsigned short nValue, unsigned char nShift);

// 0x0042E5C0
unsigned short __fastcall CHARSEL_SwapBytes(unsigned short wValue)
{
    return _rotl16(wValue, 8);
}

// 0x0042E5D0
extern "C" __declspec(dllexport) void __fastcall CHARSEL_SwapUnicodeBytes(unsigned short* pValues, unsigned int nCount) {
    for (unsigned int i = 0; i < nCount; i++) {
        pValues[i] = (unsigned short)((pValues[i] << 8) | (pValues[i] >> 8));
    }
}

// 0x004379C0
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// 0x004379D0
int __fastcall CHARSEL_IsExpansionFlag(int nValue)
{
    return nValue & 0x20;
}

// 0x004379E0
unsigned int __fastcall CHARSEL_GetProgression(unsigned int nValue)
{
    return (nValue >> 8) & 0x1F;
}

// 0x004379F0
void __cdecl CHARSEL_RefreshRealmList()
{
    MAINMENUS_BuildRealmList();
}

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

// 0x00437A60
int __cdecl CHARSEL_FreeSlots()
{
    return MAINMENUS_FreeSlots();
}

// 0x00437A70
void* __fastcall CHARSEL_CacheFind(const char* szKey)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    const int nTick = GetTickCount();
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}

// 0x00437AB0
void __fastcall CHARSEL_CacheStore(const char* szKey, const void* pData, unsigned int nSize)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash)
        {
            SMemFree(pEntry->pData, ".\\Src\\CharSel.cpp", 0xF1, 0);
            pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xF2, 0);
            memcpy(pEntry->pData, pData, nSize);
            pEntry->dwExpireTick = GetTickCount() + 300000;
            return;
        }
    }
    D2CharSelCacheStrc* pEntry = (D2CharSelCacheStrc*)SMemAlloc(sizeof(D2CharSelCacheStrc), ".\\Src\\CharSel.cpp", 0xFA, 0);
    pEntry->dwHash = dwHash;
    pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xFC, 0);
    memcpy(pEntry->pData, pData, nSize);
    pEntry->dwExpireTick = GetTickCount() + 300000;
    pEntry->pNext = gpCharSelCache;
    gpCharSelCache = pEntry;
}

// 0x00437B90
void __cdecl CHARSEL_FreeCache()
{
    D2CharSelCacheStrc* pEntry = gpCharSelCache;
    while (pEntry)
    {
        D2CharSelCacheStrc* pNext = pEntry->pNext;
        SMemFree(pEntry->pData, ".\\Src\\CharSel.cpp", 0x10C, 0);
        SMemFree(pEntry, ".\\Src\\CharSel.cpp", 0x10D, 0);
        pEntry = pNext;
    }
    gpCharSelCache = 0;
    MAINMENUS_FreeSlots();
}

// 0x00437BF0
void __cdecl CHARSEL_CreateCharInfoControls()
{
    gpControl_007799EC = MAINMENUS_CreateFromTemplate(0x6D);
    D2Win_10033(gpControl_007799EC, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_007799EC, 1);
    gpControl_00779C7C = MAINMENUS_CreateFromTemplate(0x6E);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C7C, 1);
    gpControl_00779D9C = MAINMENUS_CreateFromTemplate(0x6F);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D9C, 1);
    gpNameControl = MAINMENUS_CreateFromTemplate(0x70);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpNameControl, 1);
    gpControl_00779D88 = MAINMENUS_CreateFromTemplate(0x71);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D88, 1);
    gpControl_00779C74 = MAINMENUS_CreateFromTemplate(0x72);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C74, 1);
}

// 0x00437C90
void __cdecl CHARSEL_ScrollNameControl()
{
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl, -1, 4);
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

// 0x00437D00
void* __cdecl GAME_GetPreferredRealm()
{
    return gszPreferredRealm;
}

// 0x00437D10
int __cdecl sub_00437D10_AlwaysZero()
{
    return 0;
}

// 0x00437D20
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

// 0x00437F30
void __fastcall CHARSEL_CopyBaseName(const char* szName)
{
    char* pDest = gszBaseName_00779B68;
    while (*szName && *szName != '.')
        *pDest++ = *szName++;
    *pDest = 0;
}

// 0x00437F60
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

// 0x00438030
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

// 0x00438060
void __cdecl CHARSEL_FreeCharEntry()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// Kept noinline: CHARSEL_RefreshCharList (0x438560) calls this out of line in the image; without it the compiler inlines it there.
// 0x004380B0
__declspec(noinline) static unsigned int CHARSEL_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}

// 0x004380F0
void __cdecl CHARSEL_UpdateCharList()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList;
    int nY = ganRowValues_007799FC[0] - 13;
    int nX = 0x25;
    int nIndex = 0;

    for (int i = 0; i < gnVisibleRows; ++i)
    {
        sub_004FB6A0_ClearText(gapRowControls[i]);
        switch (STRTABLE_GetLanguage())
        {
        case 7:
            sub_004FB740(gapRowControls[i], -1, -7);
            break;
        case 6:
        case 9:
        case 10:
            sub_004FB740(gapRowControls[i], -1, -2);
            break;
        }
    }

    if (gpControl_00779DD0)
    {
        sub_004FB6A0_ClearText(gpControl_00779DD0);
    }

    if (gnLaunchMode == 1 && gnBusy)
    {
        return;
    }

    while (pEntry)
    {
        if (nIndex >= gnTopRow && nIndex < gnTopRow + gnVisibleRows)
        {
            const int nRow = nIndex - gnTopRow;
            D2Win_10152(pEntry->pCompositeUnit, nX + 30);
            D2Win_10153(pEntry->pCompositeUnit, nY);

            const int bHardcore = pEntry->wFlags & 4;
            int nFlags = 1;
            if (pEntry->wFlags & 8)
            {
                nFlags |= gnFlagSet0_006CE278;
            }
            else
            {
                nFlags &= gnFlagClear0;
            }
            if (bHardcore)
            {
                nFlags |= gdwBitMask5;
            }
            else
            {
                nFlags &= gnFlagClear1;
            }
            D2Win_10156(pEntry->pCompositeUnit, nFlags);

            if (pEntry->nState == 2)
            {
                D2Win_10051(gapRowControls[nRow], D2LANG_GetStringFromTblIndex(0x2B3B), 1, 0, 0);
            }
            else if (!pEntry->nState)
            {
                const int nClass = pEntry->nType;
                char szName[100];
                Unicode wszClass[100];
                szName[0] = 0;
                for (int j = 0; j < 100; ++j)
                {
                    wszClass[j].wChar = 0;
                }

                const char* szTitle = D2Win_10161(nClass, (pEntry->wFlags >> 8) & 0x1F, bHardcore, pEntry->wFlags & 0x20);
                if (szTitle)
                {
                    int nColor;
                    if (bHardcore)
                    {
                        nColor = 1;
                    }
                    else
                    {
                        nColor = 4;
                    }
                    D2Win_10046(gapRowControls[nRow], szTitle, nColor);
                }

                strcat(szName, pEntry->szName);
                if (strlen(pEntry->szCode32A))
                {
                    sprintf(&szName[strlen(szName)], " {%s}", pEntry->szCode32A);
                }
                D2Win_10046(gapRowControls[nRow], szName, bHardcore ? 1 : 4);

                CHARSEL_GetClassName(wszClass, pEntry->nType);

                Unicode wszText[100];
                for (int j = 0; j < 100; ++j)
                {
                    wszText[j].wChar = 0;
                }
                Unicode wszLevel[10];
                wszLevel[0].wChar = 0;
                wszLevel[1].wChar = 0;
                wszLevel[2].wChar = 0;
                wszLevel[3].wChar = 0;
                wszLevel[4].wChar = 0;
                wszLevel[5].wChar = 0;
                wszLevel[6].wChar = 0;
                wszLevel[7].wChar = 0;
                wszLevel[8].wChar = 0;
                wszLevel[9].wChar = 0;
                sprintf(szName, " %d ", pEntry->nLevel);
                sub_00526F20_ToUnicode(wszLevel, szName, 9);
                sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xFD9));
                sub_00526700(wszText, wszLevel);
                sub_00526700(wszText, wszClass);
                D2Win_10051(gapRowControls[nRow], wszText, 0, 0, 0);

                if (pEntry->wFlags & 0x20)
                {
                    D2Win_10051(gapRowControls[nRow], D2LANG_GetStringFromTblIndex(0x58CB), 2, 0, 0);
                }
                if (pEntry->nByte32E)
                {
                    D2Win_10051(gapRowControls[nRow], D2LANG_GetStringFromTblIndex(0x2AAF), 4, 0, 0);
                }

                const unsigned int nExpireTime = pEntry->nExpireTime;
                long nNow;
                const unsigned int nTime = _time32(&nNow);
                const unsigned int nDays = nExpireTime <= nTime ? 0 : (nExpireTime - nTime) / 86400;
                if (gnLaunchMode == 1 && nDays <= 60)
                {
                    int nColor = 1;
                    unsigned short nString;
                    if (!nDays)
                    {
                        nString = 0x2B7E;
                    }
                    else if (nDays < 2)
                    {
                        nString = 0x2B7C;
                    }
                    else
                    {
                        nString = 0x2B7D;
                        if (nDays >= 15)
                        {
                            nColor = 0;
                        }
                    }
                    sub_005269D0_FormatText(100, wszText, D2LANG_GetStringFromTblIndex(nString), nDays);
                    D2Win_10051(gapRowControls[nRow], wszText, nColor, 0, 0);
                }
            }

            if (nX == 0x25)
            {
                nX = 0x135;
            }
            else
            {
                nY += 0x5D;
                nX = 0x25;
            }
        }
        else
        {
            D2Win_10156(pEntry->pCompositeUnit, 0);
        }

        pEntry = pEntry->pNext;
        ++nIndex;
    }
}

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

extern "C" const char gszTagFormat[]; // 0x006D4E2C
static inline int GetCharType(D2LaunchCharEntryStrc* entry)
{
    return entry ? entry->nType : 0;
}
// 0x00438560
void __cdecl CHARSEL_RefreshCharList()
{
    if(FOG_IsExpansion()) {CHARSEL_UpdateCharList();return;}
    D2LaunchCharEntryStrc* entry=gpCharList;
    int y=ganRowValues_007799FC[0]-13;
    int index=0;
    char unusedText[256];
    UNICODE_ToUtf8(unusedText,D2LANG_GetStringFromTblIndex(0x1419),256);
    CONTROL_SetVisible(gpControl_00779D90,0);
    for(int i=0;i<gnVisibleRows;++i) {
        sub_004FB6A0_ClearText(gapRowControls[i]);
        if(STRTABLE_GetLanguage()==7) sub_004FB740(gapRowControls[i],-1,-5);
    }
    if(gpControl_00779DD0) sub_004FB6A0_ClearText(gpControl_00779DD0);
    if(gnLaunchMode==1 && gnBusy) return;
    for(;entry;entry=entry->pNext,++index) {
        if(index>=gnTopRow && index<gnTopRow+gnVisibleRows) {
            int row=index-gnTopRow;
            sub_005052B0_SetAnimX(entry->pAnim,0x221);
            sub_005052F0_SetAnimY(entry->pAnim,y);
            if(entry->nState==1) {
                sub_00505360_SetAnimFlags(entry->pAnim,0);
                IMAGE_SetCoordinates(gpControl_00779D90,0x200,(void*)(ganRowValues_007799FC[row]-3));
                CONTROL_SetVisible(gpControl_00779D90,1);
                sub_004FC9B0_SetText(gapRowControls[row],D2LANG_GetStringFromTblIndex(0x1419),1,0,0);
                if(gnLaunchMode==1 && gbFlag_00779DD8) {
                    sub_004FC9B0_SetText(gapRowControls[row],D2LANG_GetStringFromTblIndex(0x1416),0,0,0);
                    sub_004FC9B0_SetText(gapRowControls[row],D2LANG_GetStringFromTblIndex(0x1417),0,0,0);
                } else {
                    sub_004FC9B0_SetText(gapRowControls[row],D2LANG_GetStringFromTblIndex(0x1418),0,0,0);
                    sub_004FC9B0_SetText(gapRowControls[row],entry->wszName,0,0,0);
                }
                goto VISIBLE_END;
            }
            const int hardcore=entry->wFlags&4;
            unsigned int flags=1;
            if(entry->wFlags&8) flags|=gdwBitMasks[4];else flags&=gdwInverseMasks[4];
            if(hardcore) flags|=gdwBitMasks[5];else flags&=gdwInverseMasks[5];
            sub_00505360_SetAnimFlags(entry->pAnim,flags);
            if(entry->nState==2) {
                sub_004FC9B0_SetText(gapRowControls[row],D2LANG_GetStringFromTblIndex(0x2B3B),1,0,0);
                goto VISIBLE_END;
            }
            if(entry->nState!=0) {FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x3B0);exit(-1);}
            char text[100];text[0]=0;
            Unicode className[100];
            const int bExpansion=entry->wFlags&32;
            const char* title=D2Win_10161(GetCharType(entry),(entry->wFlags>>8)&31,hardcore,bExpansion);
            if(title) strcat(text,title);
            strcat(text,entry->szName);
            if(strlen(entry->szCode32A)) {
                int length=strlen(text);
                char* end=text+length;
                sprintf(end,gszTagFormat,entry->szCode32A);
            }
            D2Win_10046(gapRowControls[row],text,hardcore?1:4);
            CHARSEL_GetClassName(className,entry->nType);
            Unicode description[100];
            Unicode level[10];
            sprintf(text,gszLevelFormat,entry->nLevel);
            sub_00526F20_ToUnicode(level,text,9);
            sub_005267E0(description,D2LANG_GetStringFromTblIndex(0xFD9));
            sub_00526700(description,level);
            sub_00526700(description,className);
            sub_004FC9B0_SetText(gapRowControls[row],description,0,0,0);
            if(entry->wFlags&32) sub_004FC9B0_SetText(gapRowControls[row],D2LANG_GetStringFromTblIndex(0x2B45),2,0,0);
            if(entry->nByte32E) sub_004FC9B0_SetText(gapRowControls[row],D2LANG_GetStringFromTblIndex(0x2AAF),4,0,0);
            unsigned int days=CHARSEL_GetDaysLeft(entry->nExpireTime);
            if(gnLaunchMode==1 && days<=60) {
                int color=1;unsigned short str;
                if(days==0) str=0x2B7E;
                else if(days<2) str=0x2B7C;
                else {str=0x2B7D;if(days>=15) color=0;}
                sub_005269D0_FormatText(100,description,D2LANG_GetStringFromTblIndex(str),days);
                sub_004FC9B0_SetText(gapRowControls[row],description,color,0,0);
            }
VISIBLE_END:
            y+=93;
        } else sub_00505360_SetAnimFlags(entry->pAnim,0);
    }
}

// 0x00438AD0
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

// 0x00438EA0
void __cdecl CHARSEL_FreeCharList()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList;
    while (pEntry)
    {
        D2LaunchCharEntryStrc* pNext = pEntry->pNext;
        sub_005041B0_Destroy(pEntry->pCellFile, 1);
        sub_0040B3C0(pEntry, ".\\Src\\CharSel.cpp", 0x518, 0);
        pEntry = pNext;
    }
    gpCharList = 0;
    gnCharEntryCount = 0;
    gnTopRow = 0;
    gbFlag_00779DD8 = 0;
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// 0x00438F40
int __fastcall CHARSEL_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}

static inline int CharSel_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}

// 0x00438F70
int __cdecl CHARSEL_ScanCharFiles()
{
    D2FindDataStrc tFindData;
    char szPath[0x100];
    char szDir[0x400];
    char szPattern[0x400];

    gnCharCount = 0;
    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPattern, "%s*.d2s", szDir);
    void* hFind = FindFirstFileA(szPattern, &tFindData);
    if (hFind == (void*)-1)
    {
        return 1;
    }

    do
    {
        const char* pSrc = tFindData.cFileName;
        char* pDst = gszCharName;
        while (*pSrc && *pSrc != '.')
        {
            *pDst++ = *pSrc++;
        }
        *pDst = 0;

        if (CharSel_IsValidCharName(gszCharName) && sub_0043C8A0(gszCharName, szPath))
        {
            CHARSEL_AddCharEntry(gszCharName, szPath, 0, tFindData.ftLastWriteTime.dwLowDateTime, tFindData.ftLastWriteTime.dwHighDateTime, 0);
            ++gnCharCount;
        }
    }
    while (FindNextFileA(hFind, &tFindData));

    FindClose(hFind);
    return 1;
}

// 0x004390A0
int __cdecl CHARSEL_UpdateSelection()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList;
    int n = 0;
    if (!gnCharEntryCount)
        gnSelected = 0;
    int nRow = gnSelected - gnTopRow;
    int bShow;
    if (nRow >= 0 && nRow < gnVisibleRows)
    {
        IMAGE_SetCoordinates(gpControl_00779D94, (nRow % 2) ? 0x135 : 0x25, ganRowValues_007799FC[nRow]);
        bShow = 1;
    }
    else
    {
        bShow = 0;
    }
    sub_004F9740_ControlSetState(gpControl_00779D94, bShow);
    for (; pEntry && gnSelected != n; n++)
        pEntry = pEntry->pNext;
    CONTROL_SetEnabled(gpControl_007799F4, 1);
    CONTROL_SetEnabled(gpControl_00779C68, 1);
    if (!pEntry)
    {
        CONTROL_SetEnabled(gpControl_00779C80, 0);
        CONTROL_SetEnabled(gpControl_007799F4, 0);
        CONTROL_SetEnabled(gpControl_00779C68, 0);
        sub_004F9740_ControlSetState(gpControl_00779D94, 0);
        return 1;
    }
    CONTROL_SetEnabled(gpControl_00779C80, 1);
    if (pEntry->nFlags & 0x20)
        CONTROL_SetEnabled(gpControl_00779C80, 0);
    CONTROL_SetEnabled(gpControl_00779D90, gdwGlobal_00779DB8 == 0);
    if (gnLaunchMode == 1 && gbFlag_00779DD8)
        CONTROL_SetEnabled(gpControl_00779D90, 0);
    sub_004FB6A0_ClearText(gpCharNameText);
    sub_004FCFF0_SetTextA(gpCharNameText, pEntry->szName, 0);
    return 1;
}

// 0x00439210
int __cdecl CHARSEL_Redraw()
{
    if(FOG_IsExpansion()) {CHARSEL_UpdateSelection();return 1;}
    if(!gnCount_00779DC4) gnSelected=0;
    int row=gnSelected-gnTopRow;
    CONTROL_SetEnabled(gpControl_007799F4,gnCount_00779DC4>0 && gnSelected>gnSelectionA && gnSelected!=gnSelectionB ? 1:0);
    CONTROL_SetEnabled(gpControl_00779C68,1);
    if(row>=0 && row<gnVisibleRows) {
        if(gnSelected==gnSelectionA && gbFlag_00779DD8) {
            IMAGE_SetCoordinates(gpControl_00779C78,0x202,ganSlotY[row]);
            CONTROL_SetVisible(gpControl_00779C78,1);
            CONTROL_SetVisible(gpControl_00779D94,0);
        } else {
            IMAGE_SetCoordinates(gpControl_00779D94,0x202,ganSlotY[row]);
            CONTROL_SetVisible(gpControl_00779D94,1);
            CONTROL_SetVisible(gpControl_00779C78,0);
        }
    } else {
        CONTROL_SetVisible(gpControl_00779D94,0);
        CONTROL_SetVisible(gpControl_00779C78,0);
    }
    if(gnTopRow>0) CONTROL_SetVisible(gpScrollUpButton,1);
    else CONTROL_SetVisible(gpScrollUpButton,0); // 0x004F9740
    if(gnTopRow+gnVisibleRows<gnCount_00779DC4) CONTROL_SetVisible(gpScrollDownButton,1);
    else CONTROL_SetVisible(gpScrollDownButton,0); // 0x004F9740
    int index=0;
    D2LaunchCharEntryStrc* entry=gpCharList;
    if(!gpCharList) return 1;
    do {
        if(gnSelected==index) break;
        entry=entry->pNext;
        ++index;
    } while(entry);
    if(!entry) return 1;
    if(gpCurrentCharEntry) {
        if(!gpCurrentCharEntry->nState) sub_005041B0_FreeAnim(gpCurrentCharEntry->pAnim,1);
        FOG_Free(gpCurrentCharEntry,gszCharSelFile,0x5DE,0);
        gpCurrentCharEntry=0;
    }
    gpCurrentCharEntry=(D2LaunchCharEntryStrc*)FOG_Alloc(0x350,gszCharSelFile,0x5E2,0);
    SMemCopy(gpCurrentCharEntry,entry,0x350);
    gpCurrentCharEntry->pNext=0;
    unsigned short statusText;
    if(entry->nState==1) {
        sub_004FB6A0_ClearText(gpCharNameText);
        statusText=0x1419;
    } else if(entry->nState==2) {
        sub_004FB6A0_ClearText(gpCharNameText);
        statusText=0x2B3B;
    } else goto BUILD_MODEL;
    sub_004FC9B0_SetText(gpCharNameText,D2LANG_GetStringFromTblIndex(statusText),1,0,0);
    sub_004FB6A0_ClearText(gpCharDescriptionText);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    return 1;
BUILD_MODEL:
    unsigned char type=gpCurrentCharEntry->nType;
    int mode=5;
    if(gpCurrentCharEntry->wFlags&4) {
        if(gpCurrentCharEntry->wFlags&8) type=8+(CHARSEL_IsNotListedCode(type)!=0);
        else if(FOG_IsExpansion() || gpCurrentCharEntry->nType<5) mode=1;
    }
    gpCurrentCharEntry->pAnim=D2COMP_CreateCompositeUnit(type,mode,gpCurrentCharEntry->aFlags,gpCurrentCharEntry->aColors);
    if(!gpCurrentCharEntry->pAnim) {
        for(int i=0;i<16;++i) {gpCurrentCharEntry->aFlags[i]=0;gpCurrentCharEntry->aColors[i]=255;}
        gpCurrentCharEntry->aFlags[1]=1;
        gpCurrentCharEntry->pAnim=D2COMP_CreateCompositeUnit(7,5,gpCurrentCharEntry->aFlags,gpCurrentCharEntry->aColors);
    }
    if(!gpCurrentCharEntry->pAnim) {FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x619);exit(-1);}
    sub_005051A0_SetAnimField(gpCurrentCharEntry->pAnim,0);
    sub_00505260_SetAnimField(gpCurrentCharEntry->pAnim,0);
    sub_005042F0_SetAnimMode(gpCurrentCharEntry->pAnim,5);
    sub_005052B0_SetAnimX(gpCurrentCharEntry->pAnim,0x118);
    sub_005052F0_SetAnimY(gpCurrentCharEntry->pAnim,0x172);
    unsigned int flags=5;
    if(gpCurrentCharEntry->wFlags&8) flags|=gdwBitMasks[4];else flags&=gdwInverseMasks[4];
    if(gpCurrentCharEntry->wFlags&4) flags|=gdwBitMasks[5];else flags&=gdwInverseMasks[5];
    if(gpCurrentCharEntry->wFlags&32) flags|=gdwBitMasks[12];else flags&=gdwInverseMasks[12];
    sub_00505360_SetAnimFlags(gpCurrentCharEntry->pAnim,flags);
    Unicode className[100];
    char text[100];
    sub_004FB6A0_ClearText(gpCharNameText);
    if(strlen(gpCurrentCharEntry->szCode32A)) {
        sprintf(text,gszNameTagFormat,gpCurrentCharEntry->szName,gpCurrentCharEntry->szCode32A);
        D2Win_10046(gpCharNameText,text,0);
    } else D2Win_10046(gpCharNameText,gpCurrentCharEntry->szName,0);
    sub_004FB6A0_ClearText(gpCharDescriptionText);
    CHARSEL_GetClassName(className,gpCurrentCharEntry->nType);
    Unicode description[100];
    Unicode level[10];
    sprintf(text,gszLevelFormat,entry->nLevel);
    sub_00526F20_ToUnicode(level,text,9);
    sub_005267E0(description,D2LANG_GetStringFromTblIndex(0xFD9));
    sub_00526700(description,level);
    sub_00526700(description,className);
    sub_004FC9B0_SetText(gpCharDescriptionText,description,0,0,0);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    if(gpCurrentCharEntry->wszName[0].wChar) sub_004FC9B0_SetText(gpControl_00779C70,gpCurrentCharEntry->wszName,0,0,0);
    else sub_004FC9B0_SetText(gpControl_00779C70,D2LANG_GetStringFromTblIndex(0x142C),0,0,0);
    if(entry->wFlags&32) CONTROL_SetEnabled(gpControl_00779C68,0);
    return 1;
}

// 0x00439780
void __fastcall CHARSEL_PickClass(int nClass, int bExpansion)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xAC);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xAB);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2723), 7, 0, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xA8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xA9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xAA);
    CONTROL_SetEnabled(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    if ((!bExpansion && nClass >= 8) || nClass >= 10)
        CONTROL_SetEnabled(pControl, 1);
    MAINMENUS_CreateFromTemplate(0xAD);
}

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

int __stdcall MAINMENUS_Back(int nArg); // 0x00435E00


int gbFlag_00779DD8; // 0x00779DD8

int gnCounter_00779DDC; // 0x00779DDC

// 0x00439840
int __stdcall CHARSEL_OnCharSelectOk(int nArg)
{
    char szName[0x100];

    if (gbCharSelBusy)
        return 1;

    gpCharSelect_007795D4->nMode = 0;
    if (gnSelected == gnSelectionA)
    {
        if (gnLaunchMode != 1 || !gbFlag_00779DD8)
        {
            MAINMENUS_Back(nArg);
            gnCounter_00779DDC -= 1;
            if (gnCounter_00779DDC <= 0)
            {
                gbFlag_00779DD8 = 1;
                return 1;
            }
        }
    }
    else if (gnSelected == gnSelectionB)
    {
        sub_004FB6A0_ClearText(gpCharSelectText);
        sub_004FC9B0_SetText(gpCharSelectText, D2LANG_GetStringFromTblIndex(0x2B3C), 0, 0, 0);
        sub_004FC9B0_SetText(gpCharSelectText, D2LANG_GetStringFromTblIndex(0x2B3D), 0, 0, 0);
        return 1;
    }
    else if (gnSelected != -1)
    {
        D2LaunchCharEntryStrc* pEntry = gpCharList;
        for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
        {
            if (gnSelected == i)
                break;
        }

        if (!pEntry)
            return 1;

        if (gnLaunchMode == 1 || gnLaunchMode == 3)
        {
            memcpy(gpCharSelect_007795D4->aFlags, pEntry->aFlags, 0x10);
            memcpy(gpCharSelect_007795D4->aColors, pEntry->aColors, 0x10);
            gpCharSelect_007795D4->nLevel = pEntry->cLevel;
            gpCharSelect_007795D4->nByte0x3C2 = pEntry->cByte32E;
            gpCharSelect_007795D4->wFlags = pEntry->wFlags;
        }

        if (pEntry->wFlags & 0x20)
        {
            if (!FOG_IsExpansion())
                return 0;
        }

        if ((pEntry->wFlags & 4) && (pEntry->wFlags & 8) && (gnLaunchMode == 0 || gnLaunchMode == 2))
        {
            MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14B8), MAINMENUS_DestroyControls);
            return 1;
        }

        if (gnLaunchMode == 0 || (gnLaunchMode == 2 && gpCharSelect_007795D4->nState == 8))
        {
            int nClass = (pEntry->wFlags >> 8) & 0x1F;
            if ((!(pEntry->wFlags & 0x20) && nClass >= 4) || nClass >= 5)
            {
                CHARSEL_PickClass(nClass, pEntry->wFlags & 0x20);
                return 1;
            }
        }

        UNICODE_ToAscii(szName, pEntry->wszName, 0xFF);
        MAINMENUS_JoinGame(pEntry, pEntry->wFlags, pEntry->nType, szName);
    }

    return 1;
}

// 0x00439AF0
void __fastcall CHARSEL_JoinSelectedWithDifficulty(SMSGHANDLER_PARAMS* pMsg, int nMode)
{
    char szName[0x100];

    if (gnSelected == -1)
        return;

    D2LaunchCharEntryStrc* pEntry = gpCharList;
    for (int i = 0; pEntry; pEntry = pEntry->pNext, ++i)
    {
        if (gnSelected == i)
            break;
    }

    if (!pEntry)
        return;

    gpCharSelect_007795D4->nMode = nMode;
    MAINMENUS_DestroyControls();
    UNICODE_ToAscii(szName, pEntry->wszName, 0xFF);
    MAINMENUS_JoinGame(pEntry, pEntry->wFlags, pEntry->nType, szName);
}

// 0x00439B80
int __stdcall CHARSEL_OnNormalDifficulty(SMSGHANDLER_PARAMS* pMsg)
{
    CHARSEL_JoinSelectedWithDifficulty(pMsg, 0);
    return 1;
}

// 0x00439BA0
int __stdcall CHARSEL_OnNightmareDifficulty(SMSGHANDLER_PARAMS* pMsg)
{
    CHARSEL_JoinSelectedWithDifficulty(pMsg, 1);
    return 1;
}

// 0x00439BC0
int __stdcall CHARSEL_OnHellDifficulty(SMSGHANDLER_PARAMS* pMsg)
{
    CHARSEL_JoinSelectedWithDifficulty(pMsg, 2);
    return 1;
}

// 0x00439BE0
int __stdcall CHARSEL_CreateExpansionControls(SMSGHANDLER_PARAMS* pMsg)
{
    if (FOG_IsExpansion())
    {
        MAINMENUS_DestroyControls();
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDA);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xDB);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
        D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xDC);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
        pControl = MAINMENUS_CreateFromTemplate(0xDD);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CE), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CF), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58D0), 0, 0, 0);
    }
    return 1;
}

// 0x00439CA0
int __stdcall CHARSEL_DestroyIfExpansion(SMSGHANDLER_PARAMS* pMsg)
{
    if (FOG_IsExpansion())
        MAINMENUS_DestroyControls();
    return 1;
}

// 0x00439CC0
void __cdecl sub_00439CC0_CreateControls()
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xD7);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xD8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x142B), 0, 0, 0);
}

// 0x00439D40
int __stdcall CHARSEL_OnClosePopup(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_DestroyControls();
    return 1;
}

// 0x00439D50
int __stdcall sub_00439D50_CreateControls(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439CC0_CreateControls();
    return 1;
}

// 0x00439D60
int __stdcall CHARSEL_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow > 0)
        gnTopRow -= 1;
    if (gnSelected > 0)
        gnSelected -= 1;
    CHARSEL_RefreshCharList();
    CHARSEL_Redraw();
    return 1;
}

// 0x00439DA0
int __stdcall CHARSEL_ScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow + gnVisibleRows < gnCharEntryCount)
    {
        if (gnSelected < gnCharEntryCount - 1)
            gnSelected += 1;
        gnTopRow += 1;
        CHARSEL_RefreshCharList();
        CHARSEL_Redraw();
    }
    return 1;
}

// 0x00439DF0
int __stdcall CHARSEL_OnScroll(SMSGHANDLER_PARAMS* pMsg)
{
    const int nValue = sub_004FC620_GetValue(gpControl_00779C84);
    if (gnLastValue == nValue)
        return 0;
    gnTopRow += 2 * (nValue - gnLastValue);
    if (gnTopRow < 0)
        gnTopRow = 0;
    if (gnTopRow >= gnCharEntryCount)
        gnTopRow = gnCharEntryCount - 1;
    gnLastValue = nValue;
    CHARSEL_RefreshCharList();
    CHARSEL_Redraw();
    return 1;
}

// 0x00439E60
void __stdcall CHARSEL_AddToScrollValue(int nDelta)
{
    sub_004FC660_SetValue(gpControl_00779C84, sub_004FC620_GetValue(gpControl_00779C84) + nDelta);
}

// 0x00439E90
int __stdcall CHARSEL_HandleListKey(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->uMessage != 0x102)
    {
    switch (pMsg->wParam)
    {
    case 0x28:
        if (gnSelected < gnCharEntryCount - 1)
        {
            gnSelected += 2;
            if (gnSelected > gnCharEntryCount - 1)
            {
                gnSelected -= 2;
            }
            else if (gnSelected < gnTopRow)
            {
                gnTopRow = gnSelected;
            }
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                if (gnSelected % 2 == 0)
                {
                    gnTopRow = gnSelected - gnVisibleRows + 2;
                }
                else
                {
                    gnTopRow = gnSelected - gnVisibleRows + 1;
                }
                CHARSEL_AddToScrollValue(1);
            }
        }
        break;

    case 0x26:
        if (gnSelected > 0)
        {
            gnSelected -= 2;
            if (gnSelected < 0)
            {
                gnSelected += 2;
            }
            else if (gnSelected < gnTopRow)
            {
                if (gnSelected % 2 != 0)
                {
                    gnTopRow = gnSelected - 1;
                }
                else
                {
                    gnTopRow = gnSelected;
                }
                CHARSEL_AddToScrollValue(-1);
            }
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                gnTopRow = gnSelected - gnVisibleRows + 2;
            }
        }
        break;

    case 0x27:
        if (gnSelected < gnCharEntryCount - 1 && gnSelected % 2 == 0)
        {
            gnSelected += 1;
            if (gnSelected < gnTopRow)
            {
                gnTopRow = gnSelected;
            }
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                gnTopRow = gnSelected - gnVisibleRows + 1;
            }
        }
        break;

    case 0x25:
        if (gnSelected > 0 && gnSelected % 2 != 0)
        {
            gnSelected -= 1;
            if (gnSelected < gnTopRow)
            {
                gnTopRow = gnSelected;
            }
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                gnTopRow = gnSelected - gnVisibleRows + 1;
            }
        }
        break;

    case 0x24:
        gnTopRow = 0;
        gnSelected = 0;
        break;

    case 0x23:
        if (gnCharEntryCount > gnVisibleRows)
        {
            gnTopRow = gnCharEntryCount - gnVisibleRows;
        }
        gnSelected = gnCharEntryCount - 1;
        break;
    }

    CHARSEL_RefreshCharList();
    CHARSEL_Redraw();
    return 1;
    }

    return 0;
}

// 0x0043A0D0
int __stdcall CHARSEL_OnListKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (FOG_IsExpansion())
        return CHARSEL_HandleListKey(pMsg);

    if (pMsg->uMessage != 0x102)
    {
        switch (pMsg->wParam)
        {
        case 0x28:
            if (gnSelected < gnCharEntryCount - 1)
            {
                gnSelected += 1;
                if (gnSelected < gnTopRow)
                    gnTopRow = gnSelected;
                else if (gnSelected > gnTopRow + gnVisibleRows - 1)
                    gnTopRow = gnSelected - gnVisibleRows + 1;
            }
            break;

        case 0x26:
            if (gnSelected > 0)
            {
                gnSelected -= 1;
                if (gnSelected < gnTopRow)
                    gnTopRow = gnSelected;
                else if (gnSelected > gnTopRow + gnVisibleRows - 1)
                    gnTopRow = gnSelected - gnVisibleRows + 1;
            }
            break;

        case 0x24:
            gnTopRow = 0;
            gnSelected = 0;
            break;

        case 0x23:
            if (gnCharEntryCount > gnVisibleRows)
                gnTopRow = gnCharEntryCount - gnVisibleRows;
            gnSelected = gnCharEntryCount - 1;
            break;
        }

        CHARSEL_RefreshCharList();
        CHARSEL_Redraw();
        return 1;
    }

    return 0;
}

// 0x0043A1F0
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

// 0x0043A270
void __cdecl CHARSEL_UpdateStatus()
{
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    if (GetTickCount() - gdwStartTick > 1000)
        sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(0x2B39), 4, 0, 0);
}

// 0x0043A2B0
int __cdecl CHARSEL_InitRealmScreen()
{
    unsigned short nStringId;
    gnBusy = 0;
    if (gnLaunchMode == 1)
    {
        MAINMENUS_BuildRealmList();
        const int nCount = GAME_GetSlotNameCount();
        if (nCount != -1)
        {
            if (nCount != 0)
            {
                D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x7A);
                sub_004FD830(pControl);
                sub_004FDA50(pControl);
                gpControl_00779DD0 = MAINMENUS_CreateControl(0x94);
                gpCharSelectText = MAINMENUS_CreateControl(0x95);
                MAINMENUS_CreateControl(0x69);
                gpControl_00779D98 = MAINMENUS_CreateControl(0x6B);
                gpControl_00779D8C = MAINMENUS_CreateControl(0x6C);
                sub_004FC9B0_SetText(MAINMENUS_CreateControl(0x6A), D2LANG_GetStringFromTblIndex(0x2B32), 4, 0, 0);

                if (!SRegLoadString("Diablo II", "Preferred Realm", 0, gszPreferredRealm, 0x100) || !CHARSEL_FindSlotByName(gszPreferredRealm))
                {
                    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetBnGatewayAccess();
                    const int nIndex = pRecord->nIndex;
                    SStrCopy(gszPreferredRealm, Realm(pRecord, nIndex), 0x7FFFFFFF);
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
    MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(nStringId), MAINMENUS_ShowMainMenu);
    return 0;
}

// 0x0043A460
extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel)
{
    D2LaunchCharEntryStrc* pEntry = (D2LaunchCharEntryStrc*)FOG_Alloc(sizeof(D2LaunchCharEntryStrc), ".\\Src\\CharSel.cpp", 0xBAF, 0);
    UNICODE_ToUtf8(pEntry->szName, pTitle, 0x100);
    sub_005267E0(pEntry->wszName, pText);
    memset(pEntry->aFlags, 0, sizeof(pEntry->aFlags));
    memset(pEntry->aColors, 0, sizeof(pEntry->aColors));
    pEntry->nType = nSel;
    pEntry->nWord322 = 0;
    pEntry->nWord324 = 0;
    pEntry->nWord326 = 0;
    pEntry->nWord328 = 0;
    pEntry->nByte32E = 0;
    pEntry->nByte32F = 0;
    pEntry->nByte330 = 0;
    pEntry->pCompositeUnit = 0;
    pEntry->pNext = 0;
    for (int i = 0; i < 16; ++i)
    {
        pEntry->aFlags[i] = 0;
        pEntry->aColors[i] = 0xFF;
    }
    pEntry->aFlags[1] = 1;
    pEntry->pCompositeUnit = sub_005066C0_CreateComposite(pEntry->nType, 5, pEntry->aFlags, pEntry->aColors);
    pEntry->nState = nState;
    D2Win_10149(pEntry->pCompositeUnit, 0);
    D2Win_10151(pEntry->pCompositeUnit, 0);
    D2Win_10143(pEntry->pCompositeUnit, 5);
    if (!gpCharList)
    {
        gpCharList = pEntry;
    }
    else
    {
        D2LaunchCharEntryStrc* pLast = gpCharList;
        D2LaunchCharEntryStrc** ppNext = &gpCharList->pNext;
        while (pLast->pNext)
        {
            pLast = *ppNext;
            ppNext = &pLast->pNext;
        }
        pLast->pNext = pEntry;
    }
    ++gnCharEntryCount;
    CHARSEL_RefreshCharList();
    return 1;
}

// 0x0043A5D0
void __cdecl CHARSEL_ShowMessage()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x1419);
    const Unicode* pText;
    if (gnLaunchMode == 1)
        pText = D2LANG_GetStringFromTblIndex(0x141B);
    else
        pText = D2LANG_GetStringFromTblIndex(0x141A);
    gnSelectionA = gnCharEntryCount;
    CHARSEL_CreateNotice(pTitle, pText, 1, 0xC);
}

// 0x0043A610
void __cdecl CHARSEL_ShowString()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x2B3B);
    Unicode wEmpty;
    wEmpty.wChar = 0;
    gdwGlobal_0070CC08 = gnCharEntryCount;
    CHARSEL_CreateNotice(pTitle, &wEmpty, 2, 0x12);
}

// 0x0043A650
void __cdecl CHARSEL_RefreshCharEntry()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
    sub_004FB6A0_ClearText(gpCharNameText);
    sub_004FB6A0_ClearText(gpCharDescriptionText);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    CONTROL_SetEnabled(gpControl_007799F4, 0);
    CONTROL_SetEnabled(gpControl_00779C68, 0);
    CONTROL_SetEnabled(gpControl_007799F8, 0);
    CONTROL_SetEnabled(gpScrollUpButton, 0);
    CONTROL_SetEnabled(gpScrollDownButton, 0);
    sub_004F9740_ControlSetState(gpControl_00779D94, 0);
    if (FOG_IsExpansion())
    {
        CONTROL_SetEnabled(gpControl_00779C80, 0);
        CONTROL_SetEnabled(gpControl_00779D90, 0);
    }
    else
    {
        sub_004F9740_ControlSetState(gpControl_00779C78, 0);
    }
}

// 0x0043A730
void __cdecl CHARSEL_UpdateButtons()
{
    CONTROL_SetEnabled(gpControl_007799F4, (gnCharEntryCount > 0 && gnSelected > gnSelectionA) ? 1 : 0);
    CONTROL_SetEnabled(gpControl_00779C68, gnCharEntryCount > 0);
    CONTROL_SetEnabled(gpControl_007799F8, 1);
    CONTROL_SetEnabled(gpScrollUpButton, 1);
    CONTROL_SetEnabled(gpScrollDownButton, 1);
    if (FOG_IsExpansion())
    {
        CONTROL_SetEnabled(gpControl_00779C80, 1);
        CONTROL_SetEnabled(gpControl_00779D90, gdwGlobal_00779DB8 == 0);
    }
    gnSelected = 0;
    CHARSEL_Redraw();
}

// 0x0043A7E0
void __cdecl CHARSEL_ResetRealmScreen()
{
    if (gnLaunchMode == 1)
    {
        MAINMENUS_DestroyControls();
        CHARSEL_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
}

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

// 0x0043A950
int __stdcall CHARSEL_OnRealmChosen(SMSGHANDLER_PARAMS* pMsg)
{
    SStrCopy(gszPreferredRealm, gszEnteredName, 0x7FFFFFFF);
    SRegSaveString("Diablo II", "Preferred Realm", 0, gszPreferredRealm);
    if (gnLaunchMode == 1)
    {
        MAINMENUS_DestroyControls();
        CHARSEL_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
    return 1;
}

// 0x0043A9A0
int __stdcall CHARSEL_CopyName(int nArg)
{
    SStrCopy(gszEnteredName, gszPreferredRealm, 0x7FFFFFFF);
    CHARSEL_CreateCharListControls();
    return 1;
}

// 0x0043A9D0
int __stdcall CHARSEL_OnListClick(D2ListMsgStrc* pMsg)
{
    if (!gbFlag_00779C6C)
    {
        const int nPrevious = gnSelected;
        void* hWnd = pMsg->hWnd;
        int nRow;
        for (nRow = 0; nRow < gnVisibleRows; nRow += 1)
        {
            if (FOG_IsExpansion() && hWnd == gapRowControlsX[nRow])
                break;
            if (hWnd == gapRowControls[nRow])
                break;
        }
        const int nIndex = gnTopRow + nRow;
        if (gnCharEntryCount < nIndex)
            return 0;
        gnSelected = nIndex;
        if (gnCharEntryCount <= 0)
            gnSelected = -1;
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
            if (gnSelected != -1 && gnSelected == nPrevious && dwTick - gdwLastClick < 500)
                return CHARSEL_OnCharSelectOk(pMsg);
            gdwLastClick = dwTick;
        }
        return CHARSEL_Redraw();
    }
    return 1;
}

// 0x0043AAB0
void __stdcall CHARSEL_HandleCharList(const char* szName, unsigned char* pPacket, int bFlag)
{
    const unsigned char nType = pPacket[0];
    const char* pCursor = (const char*)pPacket + 9;
    unsigned int nCount = *(unsigned short*)(pPacket + 7);

    if (!FOG_IsExpansion())
    {
        const Unicode* wszTitle = D2LANG_GetStringFromTblIndex(0x1419);
        unsigned short nText = 0x141B;
        if (gnGlobal_007795EC != 1)
            nText = 0x141A;
        const Unicode* wszText = D2LANG_GetStringFromTblIndex(nText);
        gnGlobal_0070CC04 = gnGlobal_00779DC4;
        CHARSEL_CreateNotice(wszTitle, wszText, 1, 0xC);
    }

    unsigned int nEntries = *(unsigned short*)(pPacket + 3);
    if (nCount < nEntries)
        nEntries = nCount;

    for (unsigned int i = 0; i < nEntries; ++i)
    {
        int nExpire = 0;
        if (nType == 0x19)
        {
            nExpire = *(const int*)pCursor;
            pCursor += 4;
        }

        const char* szCharName = pCursor;
        pCursor += strlen(pCursor) + 1;
        const char* szStats = pCursor;
        pCursor += strlen(pCursor) + 1;
        D2FileTimeStrc tTime = {};
        if (!CHARSEL_AddCharEntry(szCharName, szStats, nExpire, tTime.dwLowDateTime, tTime.dwHighDateTime, szName))
        {
            --nCount;
            CHARSEL_FreeCache();
            bFlag = 0;
        }
    }

    if (bFlag)
    {
        CHARSEL_CacheStore(szName, pPacket, (const unsigned char*)pCursor - pPacket);
    }

    if (nCount >= *(unsigned short*)(pPacket + 1))
    {
        gnGlobal_00779DD8 = 1;
    }

    if (*(unsigned short*)(pPacket + 3) > *(unsigned short*)(pPacket + 7))
    {
        const Unicode* wszTitle = D2LANG_GetStringFromTblIndex(0x2B3B);
        Unicode wszEmpty;
        wszEmpty.wChar = 0;
        gnGlobal_0070CC08 = gnGlobal_00779DC4;
        CHARSEL_CreateNotice(wszTitle, &wszEmpty, 2, 0x12);
    }

    CHARSEL_Redraw();
}

// 0x0043AC00
int __stdcall CHARSEL_PollConnect(int nUnused)
{
    switch (gnBusy)
    {
    case 1:
        if (gbFlag_00779C6C)
            D2Win_10188(gpNameControl, -1, 4);
        CHARSEL_SelectNamedSlot(gpszName);
        MAINMENUS_ConnectToRealm(gpszName, 1);
        gnBusy = 2;
        gdwStartTick = GetTickCount();
        break;

    case 2:
        CHARSEL_UpdateStatus();
        switch (sub_00432400_GetStatus())
        {
        case 0:
            MCPCONNECT_SetPacket(0, 0);
            gnBusy = 3;
            if (!VIEW_SendMcpCharListRequest())
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
        int pPacket = sub_00449E60_GetPacket();
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

static inline void* CharSelCache_FindData(unsigned int dwHash, int nTick)
{
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}

// 0x0043AD10
static void CHARSEL_RequestCharList(char* szName)
{
    CHARSEL_FreeCharList();
    gdwGlobal_00779DB8 = 0;
    CONTROL_SetEnabled(gpControl_00779D90, 1);
    const unsigned int dwHash = SStrHash(szName, 0, 0);
    const int nTick = GetTickCount();
    void* pData = CharSelCache_FindData(dwHash, nTick);
    if (!pData)
    {
        if (!gpFuncTable_0077ABF0->pfnIsSocketConnected())
        {
            MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
            return;
        }
        gnBusy = 1;
        gpszName = szName;
        return;
    }
    CHARSEL_HandleCharList(szName, (int)pData, 0);
}

// 0x0043ADB0
void __fastcall CHARSEL_UseName(char* szName)
{
    gbFlag_00779DD8 = 0;
    if (gnLaunchMode == 1)
    {
        D2Win_10047((D2WinTextBoxStrc*)gpControl_00779D8C);
        D2Win_10046(gpControl_00779D8C, szName, 0);
        CHARSEL_RequestCharList(szName);
    }
    else if (gnLaunchMode == 0 || gnLaunchMode == 3 || gnLaunchMode == 2)
    {
        CHARSEL_FreeCharList();
        if (!FOG_IsExpansion())
            CHARSEL_ShowMessage();
        sub_00438F70();
    }
    CHARSEL_Redraw();
    CHARSEL_RefreshCharList();
}

// 0x0043AE30
void __cdecl CHARSEL_InitCharList()
{
    MAINMENUS_Reset();
    MAINMENUS_ReadPaletteFiles(gapszSkyPalette[0], gapszSkyPalette[1]);
    gdwGlobal_00779DA4 = 1;
    gnCharEntryCount = 0;
    gnTopRow = 0;
    gnSelected = 0;
    gbFlag_00779C6C = 0;
    gpCharSelectText = 0;
    gpControl_00779DD0 = 0;
    gnLastValue = 0;
    gpLaunchRecord->nByte210 = 0;
    MAINMENUS_CreateControl(0xA1);
    gpControl_00779C68 = MAINMENUS_CreateControl(0xA2);
    gpControl_007799F8 = MAINMENUS_CreateControl(0xA3);
    gpControl_00779D90 = MAINMENUS_CreateControl(0xA4);
    gpControl_00779C80 = MAINMENUS_CreateControl(0xA5);
    gpControl_007799F4 = MAINMENUS_CreateControl(0xA6);
    gpCharNameText = MAINMENUS_CreateControl(0x9C);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779D90, 0x5524);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779C80, 0x58CA);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_007799F4, 0x5524);
    gpControl_00779C84 = MAINMENUS_CreateControl(0xA7);
    D2Win_10194((D2WinTextBoxStrc*)gpControl_00779C84, 0);
    D2Win_10195((D2WinTextBoxStrc*)gpControl_00779C84, (void(__stdcall*)(SMSGHANDLER_PARAMS*))CHARSEL_OnScroll);
    memset(gapRowControls, 0, 8 * sizeof(void*));
    gnVisibleRows = 8;
    for (int i = 0; i < gnVisibleRows; ++i)
    {
        if (FOG_IsExpansion())
        {
            gapRowControlsX[i] = MAINMENUS_CreateControl(i + 0x8C);
            D2Win_10045((D2WinControlStrc*)gapRowControlsX[i], gszSpace);
        }
        TEXTBOX_SetSmallGap(1);
        gapRowControls[i] = MAINMENUS_CreateControl(i + 0x84);
        TEXTBOX_SetSmallGap(0);
        ganRowValues_007799FC[i] = i / 2 * 0x5D + 0xB2;
    }
    gpControl_00779D94 = MAINMENUS_CreateControl(0x96);
    if (CHARSEL_InitRealmScreen())
    {
        CONTROL_SetEnabled(gpControl_007799F8, 0);
        CHARSEL_UseName(gszPreferredRealm);
        const int nExtra = gnCharEntryCount - gnVisibleRows;
        if (nExtra > 0)
            D2Win_10191((D2WinTextBoxStrc*)gpControl_00779C84, nExtra / 2 + (nExtra % 2 != 0));
        if (D2SOUND_GetOptionsMusicOption())
            D2SOUND_10034(1);
        CONTROL_SetEnabled(gpControl_007799F8, 1);
    }
}

// 0x0043B490
int __stdcall CHARSEL_OnName(SMSGHANDLER_PARAMS* pMsg)
{
    CHARSEL_UseName(gszPreferredRealm);
    if (gnLaunchMode == 1)
    {
        MAINMENUS_DestroyControls();
        CHARSEL_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
    return 1;
}

int gdwGlobal_0077AC04; // 0x0077AC04
static int gbBattleNetConnected; // 0x0077AC08
static int gbConnecting; // 0x0077AC0C

int __stdcall CHARSEL_OnDownloadTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B850

int __stdcall CHARSEL_OnLogonTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B890

void __cdecl sub_0042F880_DestroyControls(); // 0x0042F880

void __cdecl CHARSEL_CreateConnectScreen(); // 0x00436D50

int __stdcall sub_00436E90_AlwaysOne(int nArg); // 0x00436E90

int __cdecl sub_00436EA0_IsCancelled(); // 0x00436EA0

int __stdcall CHARSEL_OnLogonTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B890

int __stdcall CHARSEL_OnCreateAccountTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B8E0

int __stdcall CHARSEL_OnChangePasswordTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B940

int __fastcall CHARSEL_HandleStatus(D2StatusStrc* pStatus); // 0x0043B9F0

extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode); // 0x006CC274


void __cdecl MAINMENUS_ShowProgressScreen(); // 0x0042F890

void __cdecl sub_0042FA20_ClearStopMainLoop(); // 0x0042FA20

int __stdcall sub_004374F0_UpdateStatusWait(int nArg); // 0x004374F0

void __cdecl MAINMENUS_CreateStatusScreen(); // 0x00437550

int __stdcall CHARSEL_OnDownloadTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B850

void __stdcall Unload(int nValue); // 0x00517ED0

extern int gbConnectCancelled; // 0x007795F4

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
                UNICODE_ToAscii(szName, pwszName, 0xFF);
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
                        sub_005269D0_FormatText(0x100, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszArg);
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
            UNICODE_ToAscii(szName, pwszName, 0xFF);
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

// 0x0043C6A0
void __fastcall CHARSEL_SetFlagBit2(int bSet)
{
    if (bSet)
        gdwFlags_0077AC34 |= 2;
}

// 0x00446890
int __stdcall CHARSEL_SendChatLine(int nArg)
{
    char szText[0x100];

    const Unicode* pText = sub_004FDD90_GetEditText(gpChatEdit);
    if (pText && UNICODE_StrLen(pText))
    {
        UNICODE_ToAscii(szText, pText, 0x100);
        return CHATDLG_SendChatText(szText, 0);
    }
    return 1;
}

static unsigned int BNSEND_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

static int BNSEND_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

static int BNSEND_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

#pragma pack(push, 1)
struct d2data_007111D8_t
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
    unsigned char b15[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006D3A00_t
{
    const void* p0;
    const void* p1;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070CBC4_t
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

extern "C" struct d2data_007111D8_t gData_007111D8; // 0x007111D8
extern "C" const struct d2data_006D3A00_t gData_006D3A00; // 0x006D3A00
extern "C" const char* const gData_006D3A08[2]; // 0x006D3A08
extern "C" struct d2data_0070CBC4_t gData_0070CBC4; // 0x0070CBC4

extern int gnGlobal_007111CC = 64; // 0x007111CC

extern int gnGlobal_007111D0 = 148; // 0x007111D0

extern int gnGlobal_007111D4 = 64; // 0x007111D4

extern "C" struct d2data_007111D8_t gData_007111D8 = {
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
    (const void*)"14",
    { 0x00 }
}; // 0x007111D8

extern int gnVisibleRows = 5; // 0x0070CC0C

extern char gszLevelDiffText[4] = "4"; // 0x0070EBD0

extern char gszMaxPlayersText[4] = "4"; // 0x0070EBD4

extern "C" const struct d2data_006D3A00_t gData_006D3A00 = {
    (const void*)"palette\\fechar\\pal.dat",
    (const void*)"palette\\fechar\\pal.pl2"
}; // 0x006D3A00

extern "C" const char* const gData_006D3A08[2] = { (const char* const)"palette\\sky\\pal.dat", (const char* const)"palette\\sky\\pal.pl2" }; // 0x006D3A08
#pragma comment(linker, "/alternatename:_gapszSkyPalette=_gData_006D3A08")

extern "C" struct d2data_0070CBC4_t gData_0070CBC4 = {
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
}; // 0x0070CBC4
