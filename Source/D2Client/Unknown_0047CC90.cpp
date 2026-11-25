#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2ClientGame.h"
#include "D2StormTypes.h"
#include "D2Win32Types.h"
#include "D2ItemsWorld.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"
#include "D2WinSplitText.h"
#include "D2ClientChatCommand.h"

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2ClientFlagsLowStrc;

struct D2ClientFlagsStrc;

struct D2ClientFlagsLowStrc
{
    unsigned char bFlag0 : 1;
    unsigned char bNumberDisplay : 1;
    unsigned char bFlags2 : 6;
};

struct D2ClientFlagsStrc
{
    unsigned int bFlags0 : 8;
    unsigned int bClassOverride : 1;
    unsigned int bFlags9 : 23;
};

extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID(); // 0x006CC354

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern D2ClientFlagsLowStrc gtClientFlagsLow_00712EFC; // 0x00712EFC

extern D2ClientFlagsStrc gtClientFlags_00712EFC; // 0x00712EFC

extern int gnLanguageId;        // 0x007BB5DC

extern int gnChatHistoryCursor; // 0x007BB5D8


extern int gnChatDrawCount; // 0x007BB5EC

extern Unicode gwszChatLine_007BB638[0x101]; // 0x007BB638

void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

bool __cdecl CHAT_IsImeLanguage(); // 0x0047B010

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern "C" int __stdcall ImmSimulateHotKey(int hWnd, unsigned long nHotKey); // 0x006B00E4

extern D2MsgHandlerEntryStrc gaChatHandlers[]; // 0x00712F4C

extern D2MsgHandlerEntryStrc gaChatInputHandlers[]; // 0x00712FA8




struct HKL__;

typedef HIMC__* HIMC;

struct CANDIDATELIST
{
    unsigned long dwSize;
    unsigned long dwStyle;
    unsigned long dwCount;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

extern "C" int __stdcall ImmReleaseContext(int hWnd, HIMC hImc); // 0x006B00B4

extern "C" int __stdcall ImmGetOpenStatus(HIMC hImc); // 0x006B00BA

extern "C" HIMC __stdcall ImmGetContext(int hWnd); // 0x006B00C6

extern "C" unsigned long __stdcall ImmGetCandidateListA(HIMC hImc, unsigned long dwIndex, CANDIDATELIST* pCandList, unsigned long dwBufLen); // 0x006B00CC

extern "C" unsigned long __stdcall ImmGetCandidateListCountA(HIMC hImc, unsigned long* pListCount); // 0x006B00D2

extern "C" int __stdcall ImmIsIME(HKL__* hKl); // 0x006B00D8

extern "C" int __stdcall ImmGetConversionStatus(HIMC hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE

extern "C" __declspec(dllimport) HKL__* __stdcall GetKeyboardLayout(unsigned long idThread); // 0x006CC4C0




extern unsigned char gbChatInputOpen; // 0x007BB5E1

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10




extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C

extern "C" long __stdcall ImmGetCompositionStringA(HIMC__* hImc, unsigned long dwIndex, void* pBuf, unsigned long dwBufLen); // 0x006B00C0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0









const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260



#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2MenuItemStrc;

typedef void(__fastcall* MENUSELECT)(D2MenuItemStrc*, SMSGHANDLER_PARAMS*);

typedef void(__fastcall* MENUOPTION)(D2MenuItemStrc*, int);

typedef void(__fastcall* MENUUPDATE)(D2MenuItemStrc*, int);

struct D2MenuItemStrc
{
    unsigned int dwType;
    int bExpansion;
    int nHeight;
    char szImage[260];
    MENUENABLED pfEnabled;
    MENUSELECT pfSelect;
    MENUOPTION pfOption;
    MENUUPDATE pfUpdate;
    unsigned int dwCount;
    unsigned int dwMoveCount;
    unsigned int dwSliderType;
    char szChoices[4][260];
    D2CelFileStrc* pImage;
    D2CelFileStrc* pChoices[4];
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __cdecl sub_004DF880();

int __cdecl sub_004DF980_IsSoundMode1Or2();

void __fastcall sub_004776C0(void* pArg);

int __cdecl D2GFX_GetDisplayType(); // 0x004F5140

int __cdecl sub_004DF940(); // 0x004DF940

int __cdecl sub_004DF960(); // 0x004DF960

int __cdecl sub_004E00D0_ToggleSoundMode01(); // 0x004E00D0

int __cdecl sub_004E0140_ToggleSoundMode12(); // 0x004E0140

void __stdcall D2GFX_SetPerspective(int bPerspective); // 0x004F51E0

void __stdcall D2GFX_SetBlendShadows(int bBlendedShadows); // 0x004F5200

void __fastcall GAME_SetResolution(int nResolution); // 0x0044BA20

void __fastcall AUTOMAP_SetAutomapMode(int nMode); // 0x0045A720

int __fastcall AUTOMAP_SetAutomapFade(int nFade); // 0x004576F0

int __cdecl AUTOMAP_GetAutomapCenters(); // 0x00457740

int __fastcall AUTOMAP_SaveAutomapCenters(int nValue); // 0x00457750

int __cdecl AUTOMAP_GetAutomapParty(); // 0x004577B0

int __cdecl AUTOMAP_GetAutomapPartyNames(); // 0x004577E0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern D2ViewStrc* gpClientView; // 0x007A0640

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth; // 0x007A5220

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall GAME_SetAlwaysRun(int bAlwaysRun); // 0x0044BE80

int __cdecl AUTOMAP_GetAutomapFade(); // 0x004576C0

int __cdecl UI_GetAutomapMode(); // 0x0045A710

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

extern int gbSmallPanel; // 0x007BC978

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __cdecl UI_DisableUIVarDelay(); // 0x00453AC0

void __cdecl UI_EnableUIVarDelay(); // 0x00453AD0

void __cdecl UI_StartUIVarDelay(); // 0x00453AE0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __cdecl sub_00468830(); // 0x00468830

void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0

int __cdecl HIREABLES_GetBeltRowCount(); // 0x004979F0

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

static int gbSlotClicked; // 0x007BC97C

extern int gdwGlobal_007BC974; // 0x007BC974

extern int gbAnyLeftPanelOpen; // 0x007BC968

extern int gbAnyPanelOpen; // 0x007BC96C

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860

void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200

static inline int sub_0047D500(D2OptionEntryStrc* pEntry);

void __fastcall sub_0047F310_ShowPage2(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);

void __fastcall sub_0047F340_ShowPage3(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);

void __fastcall sub_0047F3A0_ShowPage4(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);

void __fastcall sub_0047F400_OpenPanel(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);

void __fastcall sub_0047F430_ShowPage0(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg);


unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted); // 0x00413B80

extern D2ChatCommandStrc gaChatCommands[3]; // 0x00712F7C

extern D2CelFileStrc* gpSliderDisabledCell_007BC950; // 0x007BC950

extern D2CelFileStrc* gpSliderEnabledCell_007BC954; // 0x007BC954

extern D2CelFileStrc* gpSliderKnob_007BC958; // 0x007BC958

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nStyle); // 0x0046EFD0

void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCellFile, int nX, int nY, int nFrame, int nColor, int nArg6); // 0x00502680

int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nColor, int nArg6); // 0x004F6480

extern void* gpSlotCells; // 0x007BC964

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590


extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD



Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20

int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30

extern unsigned char gbGlobal_007BB5E0;                                                                     // 0x007BB5E0

extern int gnImeLanguage_007BB5F0;                                                                          // 0x007BB5F0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

extern int gnScreenWidth;                                                                               // 0x0071146C


D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth);       // 0x00502970





struct D2BnetChatPacketStrc;

extern "C" int __cdecl strcmp(const char* a, const char* b);

Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40

int __cdecl UI_TickElapsed(); // 0x00454850

extern int gnOptionArrowFrame; // 0x007BC944

extern int gnOptionLastX; // 0x007BC980

extern int gnOptionLastY; // 0x007BC984

static int gbOptionPressed; // 0x007BC948

static int gbOptionDragging; // 0x007BC94C

int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0

int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0

int __cdecl D2SOUND_GetPositionalBiasOption(); // 0x00514D20

int __cdecl D2SOUND_GetNpcSpeechOption(); // 0x00514D50

int __fastcall D2SOUND_SetMasterVolumeOption(int nValue); // 0x00514CD0

int __fastcall D2SOUND_SetMusicVolumeOption(int nValue); // 0x00514D00

int __fastcall D2SOUND_SetPositionalBiasOption(int nValue); // 0x00514D30

int __fastcall sub_00514D60_SetNpcSpeech(int nValue); // 0x00514D60

int __cdecl sub_004DF9B0_IsSoundMode2(); // 0x004DF9B0

void __fastcall sub_004E0690_SetSoundTableFlag(int nValue); // 0x004E0690

void __fastcall TEXT_SaveTextDisplaySetting(unsigned long nValue); // 0x0049D570

void __stdcall D2GFX_SetLowQuality(int bLowQuality); // 0x004F5220

void __fastcall MISSILE_SetMissileLights(int nValue); // 0x004CCF20

extern int gaSlotX_007BC898[]; // 0x007BC898

static void sub_0047D5C0_ActivateOption(SMSGHANDLER_PARAMS* pMsg);

int gaSlotState[8]; // 0x007BC8F8

// 0x0047CD00
static unsigned int sub_0047CD00_SliderToValue(D2MenuItemStrc* pItem, unsigned int nMin, unsigned int nMax)
{
    return (unsigned int)((float)(nMax - nMin) / (float)(pItem->dwCount - 1) * (float)pItem->dwMoveCount + (float)nMin);
}

// 0x0047CDA0
void __fastcall sub_0047CDA0_MasterVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetMasterVolumeOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CC90
static unsigned int __stdcall sub_0047CC90_ValueToSlider(D2MenuItemStrc* pItem, unsigned int nValue, unsigned int nMin, unsigned int nMax)
{
    float fSteps = (float)(pItem->dwCount - 1);
    return (unsigned int)(fSteps * (float)(nValue - nMin + 1) / (float)(nMax - nMin));
}

// 0x0047CDC0
void __fastcall sub_0047CDC0_MasterVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMasterVolumeOption(), 0, 100);
}

// 0x0047CDE0
int __fastcall sub_0047CDE0()
{
    return sub_004DF880();
}

// 0x0047CDF0
void __fastcall sub_0047CDF0_MusicVolumeSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetMusicVolumeOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CE10
void __fastcall sub_0047CE10_MusicVolumeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetMusicVolumeOption(), 0, 100);
}

// 0x0047CE50
void __fastcall sub_0047CE50_SoundModeOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF980_IsSoundMode1Or2();
}

// 0x0047CE70
void __fastcall sub_0047CE70_PositionalBiasSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    D2SOUND_SetPositionalBiasOption(sub_0047CD00_SliderToValue(pItem, 0, 100));
}

// 0x0047CE90
void __fastcall sub_0047CE90_PositionalBiasOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, D2SOUND_GetPositionalBiasOption(), 0, 100);
}

// 0x0047CED0
void __fastcall sub_0047CED0_SoundMode2Option(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = sub_004DF9B0_IsSoundMode2();
}

// 0x0047CEE0
int __fastcall sub_0047CEE0()
{
    return sub_004DF880();
}

// 0x0047CEF0
void __fastcall sub_0047CEF0_NpcSpeechSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_00514D60_SetNpcSpeech(pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        sub_004E0690_SetSoundTableFlag(1);
        TEXT_SaveTextDisplaySetting(0);
        break;
    case 1:
        sub_004E0690_SetSoundTableFlag(0);
        TEXT_SaveTextDisplaySetting(1);
        break;
    case 2:
        sub_004E0690_SetSoundTableFlag(1);
        TEXT_SaveTextDisplaySetting(1);
        break;
    }
}

// 0x0047CF50
void __fastcall sub_0047CF50_NpcSpeechOption(D2MenuItemStrc* pItem, int nArg)
{
    pItem->dwMoveCount = D2SOUND_GetNpcSpeechOption();
    if (sub_004DF880())
    {
        sub_0047CEF0_NpcSpeechSelect(pItem, (SMSGHANDLER_PARAMS*)nArg);
    }
}

// 0x0047CF80
void __fastcall sub_0047CF80_LightQualitySelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Light Quality", 0, pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        D2GFX_SetLowQuality(1);
        MISSILE_SetMissileLights(0);
        break;
    case 1:
        D2GFX_SetLowQuality(0);
        MISSILE_SetMissileLights(0);
        break;
    case 2:
        D2GFX_SetLowQuality(0);
        MISSILE_SetMissileLights(1);
        break;
    }
}

// 0x0047CFE0
void __fastcall sub_0047CFE0_LightQualityOption(D2MenuItemStrc* pItem, int nArg)
{
    SRegLoadValue("Diablo II", "Light Quality", 0, (unsigned long*)&pItem->dwMoveCount);
    switch (pItem->dwMoveCount)
    {
    case 0:
        D2GFX_SetLowQuality(1);
        MISSILE_SetMissileLights(0);
        break;
    case 1:
        D2GFX_SetLowQuality(0);
        MISSILE_SetMissileLights(0);
        break;
    case 2:
        D2GFX_SetLowQuality(0);
        MISSILE_SetMissileLights(1);
        break;
    }
}

static D2OptionEntryStrc* gpOptionEntries; // 0x007BC940

D2OptionHeaderStrc* gpOptionHeader; // 0x007BC93C

// 0x0047D520
static int sub_0047D520_FindOptionAtY(int nY)
{
    const int nCount = gpOptionHeader->nCount;
    const int nHalf = gpOptionHeader->nHeight * nCount / 2;
    const int nCenter = (gnScreenHeight - 0x50) / 2;
    int nResult = -1;

    if (nY > nCenter - nHalf && nY < nCenter + nHalf)
    {
        for (int i = 0; i < nCount; ++i)
        {
            if (gpOptionEntries[i].nY && nY >= gpOptionEntries[i].nY + nCount)
            {
                nResult = i;
            }
        }

        if (nResult >= 0)
        {
            if (gpOptionEntries[nResult].nKind != -1 && sub_0047D500(&gpOptionEntries[nResult]))
            {
                return nResult;
            }

            nResult = -1;
        }
    }

    return nResult;
}

static int gnOptionSelected; // 0x007BC938

// 0x0047D5B0
static void sub_0047D5B0_SelectOptionAtY(int nY)
{
    const int nIndex = sub_0047D520_FindOptionAtY(nY);
    if (nIndex != -1)
    {
        gnOptionSelected = nIndex;
    }
}

extern int gnScreenWidth; // 0x0071146C

// 0x0047D670
static void sub_0047D670_UpdateOptionSlider(int nX, int nY)
{
    if (!gbOptionDragging && sub_0047D520_FindOptionAtY(nY) != gnOptionSelected)
    {
        return;
    }

    const unsigned int nOldValue = gpOptionEntries[gnOptionSelected].nValue;
    if (sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        switch (gpOptionEntries[gnOptionSelected].nKind)
        {
        case 2:
        {
            const int nHalfWidth = gnScreenWidth / 2;
            int nLeft = nHalfWidth - 0x3B;
            int nBar = nHalfWidth - 0x3C;
            if (!gpOptionEntries[gnOptionSelected].pCel)
            {
                nLeft = nHalfWidth - 0x90;
                nBar = nHalfWidth - 0x91;
            }

            if (gbOptionDragging || nX > nLeft && nX < nLeft + 0x121)
            {
                const int nStart = nBar + 0xC;
                if (nX < nStart)
                {
                    gpOptionEntries[gnOptionSelected].nValue = 0;
                }
                else if (nX > nStart + 0x109)
                {
                    gpOptionEntries[gnOptionSelected].nValue = gpOptionEntries[gnOptionSelected].nValues - 1;
                }
                else
                {
                    gpOptionEntries[gnOptionSelected].nValue = (int)((nX - nStart) / (float)(265.0 / (float)(gpOptionEntries[gnOptionSelected].nValues - 1) * 0.5) + 1.0) / 2;
                }
                gbOptionDragging = 1;
            }
            break;
        }
        }
    }

    if (nOldValue != gpOptionEntries[gnOptionSelected].nValue)
    {
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
}


void __fastcall TEXT_PrintChatLine(const Unicode* pText, char nColor); // 0x0049E3A0



Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

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
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);








struct D2OptionHeaderStrc;

struct D2OptionEntryStrc;

struct D2EscMenuUIStateStrc;

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0


int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

void __stdcall CHAT_StepChatIndex(int nDelta); // 0x0047BA80


extern D2OptionHeaderStrc gtMainOptionHeader; // 0x00713044

extern D2EscMenuUIStateStrc gaEscMenuUIState[38]; // 0x00713058

extern D2OptionEntryStrc gaMainOptionEntries[]; // 0x00713220

extern D2OptionHeaderStrc gtOptionsHeader; // 0x00714210

extern D2OptionHeaderStrc gtSoundOptionHeader; // 0x00714224

extern D2OptionEntryStrc gaOptionsEntries[]; // 0x00714238

extern D2OptionEntryStrc gaSoundOptionEntries[]; // 0x00715CC8

extern D2OptionHeaderStrc gtVideoOptionHeader; // 0x00718748

extern D2OptionHeaderStrc gtVideoResOptionHeader; // 0x0071875C

extern D2OptionEntryStrc gaVideoOptionEntries[]; // 0x00718770

extern D2OptionEntryStrc gaVideoResOptionEntries[]; // 0x0071ACA0

extern D2OptionHeaderStrc gtAutomapOptionHeader; // 0x0071D720

extern D2OptionHeaderStrc gtAutomapModeOptionHeader; // 0x0071D734

extern D2OptionEntryStrc gaAutomapOptionEntries[]; // 0x0071D748

extern D2OptionEntryStrc gaAutomapModeOptionEntries[]; // 0x0071F728


unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD







extern "C" size_t __cdecl strlen(const char* sz);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB



void __cdecl sub_00477C60_CheckCacheStats();                                                                // 0x00477C60

void __cdecl VIEW_ToggleCacheStats();                                                               // 0x00477C00

int __cdecl GAME_GetConnectionType();                                                                                 // 0x0044DB30

void __cdecl SOUNDINST_ToggleHints();                                                                    // 0x004BABC0

int __stdcall CHAT_ParseChatCommand(char** ppText, char* pCode, char* szArgument);                  // 0x0047BAD0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

void __fastcall TEXT_PrintChatLine(const Unicode* pText, char nColor);                              // 0x0049E3A0

void __fastcall MSG_SendStrings(const unsigned char* pData);                                       // 0x004787B0

unsigned int __fastcall D2Win_10128(unsigned char nChar);                                                   // 0x00502550

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(Unicode* pText, unsigned int* pLineCount, int nWidth);    // 0x00502970

extern int gbNoPickup;                                                                             // 0x007A6A90

extern unsigned short gwChatHistoryCount;                                                          // 0x007BB5E4

extern Unicode gawszChatHistory_007BB840[8][257];                                                           // 0x007BB840



#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))


extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

void __fastcall sub_0047DBB0_LoadOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries); // 0x0047DBB0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

D2CelFileStrc* __cdecl UI_GetPentspinCel(); // 0x00453AA0

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile); // 0x006019F0

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

extern D2CelFileStrc* gpSliderDisabledCel; // 0x007BC950

extern D2CelFileStrc* gpSliderEnabledCel; // 0x007BC954

extern D2CelFileStrc* gpSliderKnobCel; // 0x007BC958

struct D2StoredUnitRecordStrc;

int gnOptionMaxWidth; // 0x007BC95C




Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __stdcall sub_0047E9A0_DrawSlots(int bDraw); // 0x0047E9A0

int __cdecl sub_0047EA60_IsAnyPanelOpen(); // 0x0047EA60

int __cdecl sub_0047EB50_IsAnyLeftPanelOpen(); // 0x0047EB50

extern void* gpMiniPanelCel; // 0x007BC960

extern int gbSlotBarBlocked; // 0x007BC970

extern int gaSlotX[]; // 0x007BC898

extern int gaSlotY[]; // 0x007BC8B8

extern int gaSlotKind[]; // 0x007BC8D8

extern int gaSlotFrame[]; // 0x007BC918

int gaSlotX[8]; // 0x007BC898

int gaSlotY[8]; // 0x007BC8B8

int gaSlotKind[8]; // 0x007BC8D8

int gaSlotFrame[8]; // 0x007BC918

int gbSlotBarBlocked; // 0x007BC970

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))









// 0x0047CD80
int __fastcall sub_0047CD80_IsSoundEnabled()
{
    return sub_004DF880();
}

// 0x0047CD90
int __fastcall sub_0047CD90_IsSoundEnabled()
{
    return sub_004DF880();
}

// 0x0047CE30
int __fastcall sub_0047CE30_Is3DSoundEnabled()
{
    return sub_004DF940();
}

// 0x0047CE40
void __fastcall sub_0047CE40_3DSoundSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004E00D0_ToggleSoundMode01();
}

// 0x0047CE60
int __fastcall sub_0047CE60_Is3DBiasEnabled()
{
    return sub_004DF980_IsSoundMode1Or2();
}

// 0x0047CEB0
int __fastcall sub_0047CEB0_IsEAXEnabled()
{
    return sub_004DF960();
}

// 0x0047CEC0
void __fastcall sub_0047CEC0_EAXSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004E0140_ToggleSoundMode12();
}

// 0x0047D040
void __fastcall sub_0047D040_BlendShadowsChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Blended Shadows", 0, pEntry->nValue);
    D2GFX_SetBlendShadows(pEntry->nValue);
}

// 0x0047D070
void __fastcall sub_0047D070_BlendShadowsLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    SRegLoadValue("Diablo II", "Blended Shadows", 0, (unsigned long*)&pEntry->nValue);
    D2GFX_SetBlendShadows(pEntry->nValue);
}

// 0x0047D0A0
void __fastcall sub_0047D0A0_ResolutionChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Resolution", 0, pEntry->nValue);
    int nResolution = 2;
    if (!pEntry->nValue)
    {
        nResolution = 0;
    }
    GAME_SetResolution(nResolution);
}

// 0x0047D0E0
void __fastcall sub_0047D0E0_ResolutionLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    if (!SRegLoadValue("Diablo II", "Resolution", 0, (unsigned long*)&pEntry->nValue))
    {
        pEntry->nValue = 1;
    }
    int nResolution = 2;
    if (!pEntry->nValue)
    {
        nResolution = 0;
    }
    GAME_SetResolution(nResolution);
}

// 0x0047D120
int __cdecl sub_0047D120_PerspectiveEnabled()
{
    return D2GFX_CheckUnitPerspective();
}

// 0x0047D130
void __fastcall sub_0047D130_PerspectiveChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Perspective", 0, pEntry->nValue);
    D2GFX_SetPerspective(pEntry->nValue);
    sub_00476000_SetViewRect(gpClientView, 0, 0, gnAutomapWidth, gnAutomapHeight_007A521C);
}

// 0x0047D180
void __fastcall sub_0047D180_PerspectiveLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    SRegLoadValue("Diablo II", "Perspective", 0, (unsigned long*)&pEntry->nValue);
// build: symbol ?D2GFX_CheckUnitPerspective@* 0x004F5170
    if (D2GFX_CheckUnitPerspective())
    {
        sub_0047D130_PerspectiveChanged(pEntry, 0);
    }
    else
    {
        pEntry->nValue = 0;
    }
}

// 0x0047D1F0
int __cdecl sub_0047D1F0_GammaEnabled()
{
    return D2GFX_GammaCanBeControlled();
}

// 0x0047D200
void __fastcall sub_0047D200_GammaSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nGamma = sub_0047CD00_SliderToValue(pItem, 0x37, 0xFF);
    SRegSaveValue("Diablo II", "Gamma", 0, nGamma);
    sub_004776C0((void*)nGamma);
}

// 0x0047D230
void __fastcall sub_0047D230_GammaOption(D2MenuItemStrc* pItem, int nArg)
{
    unsigned long nGamma = 0x9B;
    SRegLoadValue("Diablo II", "Gamma", 0, &nGamma);
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nGamma, 0x37, 0xFF);
    if (D2GFX_GammaCanBeControlled())
    {
        sub_0047D200_GammaSelect(pItem, 0);
    }
}

// 0x0047D2B0
void __fastcall sub_0047D2B0_ContrastSelect(D2MenuItemStrc* pItem, SMSGHANDLER_PARAMS* pMsg)
{
    SRegSaveValue("Diablo II", "Contrast", 0, sub_0047CD00_SliderToValue(pItem, 0, 100));
    D2GFX_SetOption(0x0B, pItem->dwMoveCount);
    D2GFX_SetGamma(0);
}

// 0x0047D2F0
void __fastcall sub_0047D2F0_ContrastOption(D2MenuItemStrc* pItem, int nArg)
{
    unsigned long nContrast = (D2GFX_GetDisplayType() != 4) ? 100 : 0;
    SRegLoadValue("Diablo II", "Contrast", 0, &nContrast);
    pItem->dwMoveCount = sub_0047CC90_ValueToSlider(pItem, nContrast, 0, 100);
    sub_0047D2B0_ContrastSelect(pItem, 0);
}

// 0x0047D370
void __fastcall sub_0047D370_AutoMapModeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 2)
    {
        pEntry->nValue = 0;
    }
    AUTOMAP_SetAutomapMode(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapMode", 0, pEntry->nValue);
}

// 0x0047D3B0
void __fastcall sub_0047D3B0_LoadAutoMapMode(D2OptionEntryStrc* pEntry, int nArg)
{
    unsigned long dwValue;
    SRegLoadValue("Diablo II", "AutoMapMode", 0, &dwValue);
    if (dwValue > 2)
    {
        dwValue = 0;
    }
    AUTOMAP_SetAutomapMode(dwValue);
    pEntry->nValue = UI_GetAutomapMode();
}

// 0x0047D3F0
void __fastcall sub_0047D3F0_AutoMapFadeChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (pEntry->nValue > 4)
    {
        pEntry->nValue = 0;
    }
    AUTOMAP_SetAutomapFade(pEntry->nValue);
    SRegSaveValue("Diablo II", "AutoMapFade", 0, pEntry->nValue);
}

// 0x0047D430
void __fastcall sub_0047D430_LoadAutoMapFade(D2OptionEntryStrc* pEntry, int nArg)
{
    unsigned long dwValue;
    SRegLoadValue("Diablo II", "AutoMapFade", 0, &dwValue);
    if (dwValue > 4)
    {
        dwValue = 0;
        AUTOMAP_SetAutomapFade(dwValue);
    }
    pEntry->nValue = AUTOMAP_GetAutomapFade();
}

// 0x0047D470
void __fastcall sub_0047D470_AutoMapCentersChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    AUTOMAP_SaveAutomapCenters(pEntry->nValue);
}

// 0x0047D480
void __fastcall sub_0047D480_AutoMapCentersLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = AUTOMAP_GetAutomapCenters();
}

// 0x0047D490
void __fastcall sub_0047D490_AutoMapPartyChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577C0_SetValue(pEntry->nValue);
}

// 0x0047D4A0
void __fastcall sub_0047D4A0_AutoMapPartyLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = AUTOMAP_GetAutomapParty();
}

// 0x0047D4B0
int __cdecl sub_0047D4B0_PartyNamesEnabled()
{
    return AUTOMAP_GetAutomapParty();
}

// 0x0047D4C0
void __fastcall sub_0047D4C0_AutoMapPartyNamesChanged(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_004577F0_SetValue(pEntry->nValue);
}

// 0x0047D4D0
void __fastcall sub_0047D4D0_AutoMapPartyNamesLoad(D2OptionEntryStrc* pEntry, int nArg)
{
    pEntry->nValue = AUTOMAP_GetAutomapParty() && AUTOMAP_GetAutomapPartyNames();
}

// 0x0047D500
static inline int sub_0047D500(D2OptionEntryStrc* pEntry)
{
    return !pEntry->pfnEnabled || pEntry->pfnEnabled();
}

// 0x0047D5C0
static void sub_0047D5C0_ActivateOption(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        return;
    }

    switch (gpOptionEntries[gnOptionSelected].nKind)
    {
    case 1:
        gpOptionEntries[gnOptionSelected].nValue++;
        if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
        {
            gpOptionEntries[gnOptionSelected].nValue = 0;
        }
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], pMsg);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
        break;

    case 0:
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], pMsg);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
        break;
    }
}

// 0x0047D7F0
void __stdcall sub_0047D7F0_OptionMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    sub_0047D5B0_SelectOptionAtY(nY);
    sub_0047D670_UpdateOptionSlider(nX, nY);
    gbOptionPressed = 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047D840
void __stdcall sub_0047D840_OptionMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    if (gbOptionPressed && sub_0047D520_FindOptionAtY(nY) == gnOptionSelected)
    {
        sub_0047D5C0_ActivateOption(pMsg);
    }
    GAME_ResetMouseState();
    gbOptionPressed = 0;
    gbOptionDragging = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

int __cdecl GAME_GetAlwaysRun(); // 0x0044BE90

void* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0

extern int gbPanelFlag; // 0x0071315C

// 0x0047D8A0
void __stdcall sub_0047D8A0_SelectNextOption(SMSGHANDLER_PARAMS* pMsg)
{
    do
    {
        ++gnOptionSelected;
        if (gnOptionSelected > gpOptionHeader->nCount - 1)
        {
            gnOptionSelected = 0;
        }
    }
    while (gpOptionEntries[gnOptionSelected].nKind == -1
        || gpOptionEntries[gnOptionSelected].pfnEnabled && !gpOptionEntries[gnOptionSelected].pfnEnabled());
    sub_004B9A00(1, 0, 0, 0, 0);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047D920
void __stdcall sub_0047D920_SelectPreviousOption(SMSGHANDLER_PARAMS* pMsg)
{
    do
    {
        --gnOptionSelected;
        if (gnOptionSelected < 0)
        {
            gnOptionSelected = gpOptionHeader->nCount - 1;
        }
    }
    while (gpOptionEntries[gnOptionSelected].nKind == -1
        || gpOptionEntries[gnOptionSelected].pfnEnabled && !gpOptionEntries[gnOptionSelected].pfnEnabled());
    sub_004B9A00(1, 0, 0, 0, 0);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047D9A0
void __stdcall sub_0047D9A0_OptionKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries[gnOptionSelected].nValue;
    if (sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        switch (gpOptionEntries[gnOptionSelected].nKind)
        {
        case 1:
            --gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = gpOptionEntries[gnOptionSelected].nValues - 1;
            }
            break;
        case 2:
            --gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = 0;
            }
            break;
        }
    }

    if (nOldValue != gpOptionEntries[gnOptionSelected].nValue)
    {
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047DA90
void __stdcall sub_0047DA90_OptionKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nOldValue = gpOptionEntries[gnOptionSelected].nValue;
    if (sub_0047D500(&gpOptionEntries[gnOptionSelected]))
    {
        switch (gpOptionEntries[gnOptionSelected].nKind)
        {
        case 1:
            ++gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = 0;
            }
            break;
        case 2:
            ++gpOptionEntries[gnOptionSelected].nValue;
            if (gpOptionEntries[gnOptionSelected].nValue > gpOptionEntries[gnOptionSelected].nValues - 1)
            {
                gpOptionEntries[gnOptionSelected].nValue = gpOptionEntries[gnOptionSelected].nValues - 1;
            }
            break;
        }
    }

    if (nOldValue != gpOptionEntries[gnOptionSelected].nValue)
    {
        if (gpOptionEntries[gnOptionSelected].pfnChanged)
        {
            gpOptionEntries[gnOptionSelected].pfnChanged(&gpOptionEntries[gnOptionSelected], 0);
        }
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047DB80
void __stdcall sub_0047DB80_OptionActivate(SMSGHANDLER_PARAMS* pMsg)
{
    sub_0047D5C0_ActivateOption(pMsg);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}


// 0x0047DBB0
void __fastcall sub_0047DBB0_LoadOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries)
{
    D2_ASSERT(pHeader, 0x4E8);
    D2_ASSERT(pEntries, 0x4E9);
    char szPath[260] = {0};
    char szLang[4] = {0};
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
    STRTABLE_GetLanguageInfoField(szLang, 0);
    for (int i = 0; i < pHeader->nCount; ++i)
    {
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (pEntries[i].bExpansionOnly && !FOG_IsExpansion())
            continue;
        if (pEntries[i].szCelName[0])
        {
            sprintf(szPath, "%s\\UI\\%s\\%s", szDataLocal_006D41A8, szLang, pEntries[i].szCelName);
            pEntries[i].pCel = ARCHIVE_LoadClientCellFile(szPath, 0);
            if (pEntries[i].nKind == 1)
            {
                D2_ASSERT(pEntries[i].nValues > 0 && pEntries[i].nValues <= 4, 0x4FE);
                for (unsigned int j = 0; j < pEntries[i].nValues; ++j)
                {
                    D2_ASSERT(pEntries[i].szValueCels[j][0], 0x501);
                    sprintf(szPath, "%s\\UI\\%s\\%s", szDataLocal_006D41A8, szLang, pEntries[i].szValueCels[j]);
                    pEntries[i].pValueCels[j] = ARCHIVE_LoadClientCellFile(szPath, 0);
                }
            }
        }
        if (pEntries[i].pfnLoad)
            pEntries[i].pfnLoad(&pEntries[i], 0);
    }
}

// 0x0047DD70
void __cdecl sub_0047DD70_LoadOptionMenus()
{
    D2CelContextStrc tContext;
    sub_0047DBB0_LoadOptionCels(&gtMainOptionHeader, gaMainOptionEntries);
    sub_0047DBB0_LoadOptionCels(&gtOptionsHeader, gaOptionsEntries);
    sub_0047DBB0_LoadOptionCels(&gtSoundOptionHeader, gaSoundOptionEntries);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        sub_0047DBB0_LoadOptionCels(&gtVideoResOptionHeader, gaVideoResOptionEntries);
        sub_0047DBB0_LoadOptionCels(&gtAutomapModeOptionHeader, gaAutomapModeOptionEntries);
    }
    else
    {
        sub_0047DBB0_LoadOptionCels(&gtVideoOptionHeader, gaVideoOptionEntries);
        sub_0047DBB0_LoadOptionCels(&gtAutomapOptionHeader, gaAutomapOptionEntries);
    }
    gpOptionHeader = &gtMainOptionHeader;
    gpOptionEntries = gaMainOptionEntries;
    char szPath[260] = {0};
// build: symbol ?gszDataGlobal@* 0x006D4118
    sprintf(szPath, "%s\\UI\\Widgets\\OptBar", gszDataGlobal);
    gpSliderDisabledCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\Widgets\\OptBarC", gszDataGlobal);
    gpSliderEnabledCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\Widgets\\OptSkull", gszDataGlobal);
    gpSliderKnobCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = UI_GetPentspinCel();
    const unsigned int nFrames = CelFileGetCelsPerDirection((D2CelFileStrc*)tContext.pCellFile);
    int nMax = 0;
    for (tContext.nFrame = 0; tContext.nFrame < nFrames; ++tContext.nFrame)
        nMax = D2_MAX(nMax, CelGetWidth(CelGetHandle(&tContext)));
    gnOptionMaxWidth = nMax;
}


// 0x0047DF00
void __fastcall sub_0047DF00_FreeOptionCels(D2OptionHeaderStrc* pHeader, D2OptionEntryStrc* pEntries)
{
    D2_ASSERT(pHeader, 0x558);
    D2_ASSERT(pEntries, 0x559);
    for (int i = 0; i < pHeader->nCount; ++i)
    {
        D2OptionEntryStrc* pEntry = &pEntries[i];
        if (pEntry->pCel)
        {
            ARCHIVE_FreeClientCellFile(pEntry->pCel);
            pEntry->pCel = 0;
        }
        if (pEntry->nKind == 1)
        {
            D2_ASSERT(pEntry->nValues > 0 && pEntry->nValues <= 4, 0x565);
            for (unsigned int j = 0; j < pEntry->nValues; ++j)
            {
                if (pEntry->pValueCels[j])
                {
                    ARCHIVE_FreeClientCellFile(pEntry->pValueCels[j]);
                    pEntry->pValueCels[j] = 0;
                }
            }
        }
    }
}

// 0x0047DFD0
void __cdecl sub_0047DFD0_FreeOptionMenus()
{
    gpOptionHeader = 0;
    gpOptionEntries = 0;
    sub_0047DF00_FreeOptionCels(&gtSoundOptionHeader, gaSoundOptionEntries);
    sub_0047DF00_FreeOptionCels(&gtOptionsHeader, gaOptionsEntries);
    sub_0047DF00_FreeOptionCels(&gtMainOptionHeader, gaMainOptionEntries);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        sub_0047DF00_FreeOptionCels(&gtVideoResOptionHeader, gaVideoResOptionEntries);
        sub_0047DF00_FreeOptionCels(&gtAutomapModeOptionHeader, gaAutomapModeOptionEntries);
    }
    else
    {
        sub_0047DF00_FreeOptionCels(&gtVideoOptionHeader, gaVideoOptionEntries);
        sub_0047DF00_FreeOptionCels(&gtAutomapOptionHeader, gaAutomapOptionEntries);
    }
    if (gpSliderDisabledCel)
    {
        ARCHIVE_FreeClientCellFile(gpSliderDisabledCel);
        gpSliderDisabledCel = 0;
    }
    if (gpSliderEnabledCel)
    {
        ARCHIVE_FreeClientCellFile(gpSliderEnabledCel);
        gpSliderEnabledCel = 0;
    }
    if (gpSliderKnobCel)
    {
        ARCHIVE_FreeClientCellFile(gpSliderKnobCel);
        gpSliderKnobCel = 0;
    }
}

// 0x0047E090
void __fastcall WARDENCLIENT_ToggleEscMenuUIState(int bSaveState, int nMenu)
{
    if (bSaveState)
    {
        for (unsigned int i = 0; i < 38; ++i)
        {
            gaEscMenuUIState[i].nSaved = 0;
            if (gaEscMenuUIState[i].bCheck)
            {
                if (gaEscMenuUIState[i].bSave)
                {
                    gaEscMenuUIState[i].nSaved = GAME_GetUIVarState(i);
                }
                if (GAME_GetUIVarState(i))
                {
                    UI_SetUIVar(i, 1, 0);
                }
            }
        }
    }
    UI_SetUIVar(9, 0, 0);
    switch (nMenu)
    {
    case 0:
        gpOptionHeader = &gtMainOptionHeader;
        gpOptionEntries = gaMainOptionEntries;
        break;
    case 1:
        gpOptionHeader = &gtOptionsHeader;
        gpOptionEntries = gaOptionsEntries;
        break;
    case 2:
        gpOptionHeader = &gtSoundOptionHeader;
        gpOptionEntries = gaSoundOptionEntries;
        break;
    case 3:
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (FOG_IsExpansion())
        {
            gpOptionHeader = &gtVideoResOptionHeader;
            gpOptionEntries = gaVideoResOptionEntries;
        }
        else
        {
            gpOptionHeader = &gtVideoOptionHeader;
            gpOptionEntries = gaVideoOptionEntries;
        }
        break;
    case 4:
        if (FOG_IsExpansion())
        {
            gpOptionHeader = &gtAutomapModeOptionHeader;
            gpOptionEntries = gaAutomapModeOptionEntries;
        }
        else
        {
            gpOptionHeader = &gtAutomapOptionHeader;
            gpOptionEntries = gaAutomapOptionEntries;
        }
        break;
    }
    gnOptionSelected = gpOptionHeader->nCount - 1;
    if (nMenu == 5)
    {
        gnOptionSelected = 1;
    }
}

// 0x0047E200
void __fastcall sub_0047E200_CloseMenus(int bRestore)
{
    if (GAME_GetUIVarState(9))
    {
        UI_SetUIVar(9, 1, 0);
    }
    if (bRestore)
    {
        for (unsigned int i = 0; i < 38; ++i)
        {
            if (gaEscMenuUIState[i].nSaved)
            {
                UI_SetUIVar(i, 0, 0);
            }
        }
    }
}

// 0x0047E260
void __stdcall sub_0047E260_DrawOptionSlider(D2OptionEntryStrc* pEntry, int nY, int nColor, int bSmall)
{
    const int* pbEnabled = &pEntry->bEnabled;
    int nScreenY = gpOptionHeader->nY + nY;
    nY = bSmall ? (gnScreenWidth_0071146C / 2) - 145 : (gnScreenWidth_0071146C / 2) - 60;
    int nKnobX = nY - (int)(-265.0 / (float)(pEntry->nValues - 1) * (float)pEntry->nValue);
    int nKnobY = nScreenY - !*pbEnabled - 1;
    int nWidth = nKnobX - nY + 12;
    const int nBoxY = nScreenY - 30;
    int nBoxX = bSmall ? (gnScreenWidth_0071146C / 2) - 144 : (gnScreenWidth_0071146C / 2) - 59;
    AUTOMAP_DrawFramedBox(nBoxX, nBoxY, nWidth, 30, 0, *pbEnabled ? 1 : 2);
    AUTOMAP_DrawFramedBox(nBoxX + nWidth, nBoxY, 289 - nWidth, 30, 0, *pbEnabled != 0);

    int nCellX = gnScreenWidth_0071146C / 2 + 230;
    int nFrame = 2;
    if (bSmall)
    {
        nCellX = gnScreenWidth_0071146C / 2;
        nFrame = 1;
    }

    D2Win_10134_DrawCellFile(*pbEnabled ? gpSliderEnabledCell_007BC954 : gpSliderDisabledCell_007BC950, nCellX, nScreenY, nFrame, nColor, -1);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpSliderKnob_007BC958;
    TEXTURE_CelDraw(&tContext, nKnobX, nKnobY, -1, nColor, 0);
}

// 0x0047E3D0
void __cdecl sub_0047E3D0_DrawOptions()
{
    D2_ASSERT(gpOptionHeader, 0x64B);
    D2_ASSERT(gpOptionEntries, 0x64C);

    const int nX = sub_00468730();
    const int nY = sub_00468740();
    const int nTop = (gnScreenHeight - 0x50) / 2 - gpOptionHeader->nHeight * gpOptionHeader->nCount / 2;

    if (gnOptionLastY != nY || gnOptionLastX != nX)
    {
        gnOptionLastY = nY;
        gnOptionLastX = nX;
        if (gbOptionPressed)
        {
            sub_0047D670_UpdateOptionSlider(nX, nY);
        }
        else
        {
            sub_0047D5B0_SelectOptionAtY(nY);
        }
    }

    int bEnabled;
    int nRow = 0;
    for (int i = 0; i < gpOptionHeader->nCount; ++i)
    {
        gpOptionEntries[i].nY = 0;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (gpOptionEntries[i].bExpansionOnly && !FOG_IsExpansion())
        {
            continue;
        }
        if (!gpOptionEntries[i].pfnEnabled || gpOptionEntries[i].pfnEnabled())
        {
            bEnabled = 1;
        }
        else
        {
            bEnabled = 0;
        }

        const int nColor = bEnabled ? 5 : 1;
        if (gpOptionEntries[i].pfnInit)
        {
            gpOptionEntries[i].pfnInit(&gpOptionEntries[i], 0);
        }

        const int nEntryY = gpOptionHeader->nHeight * nRow + nTop;
        const int nDrawY = gpOptionHeader->nTextOffset + nEntryY;
        gpOptionEntries[i].nY = nEntryY;
        switch (gpOptionEntries[i].nKind)
        {
        case -1:
        case 0:
            D2Win_10134_DrawCellFile(gpOptionEntries[i].pCel, gnScreenWidth / 2, nDrawY, 1, nColor, -1);
            break;

        case 1:
            D2Win_10134_DrawCellFile(gpOptionEntries[i].pCel, gnScreenWidth / 2 - 0xE6, nDrawY, 0, nColor, -1);
            D2Win_10134_DrawCellFile(gpOptionEntries[i].pValueCels[gpOptionEntries[i].nValue], gnScreenWidth / 2 + 0xE6, nDrawY, 2, nColor, -1);
            break;

        case 2:
            if (gpOptionEntries[i].pCel)
            {
                D2Win_10134_DrawCellFile(gpOptionEntries[i].pCel, gnScreenWidth / 2 - 0xE6, nDrawY, 0, nColor, -1);
            }
            sub_0047E260_DrawOptionSlider(&gpOptionEntries[i], nEntryY, nColor, gpOptionEntries[i].pCel == 0);
            break;
        }
        ++nRow;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = UI_GetPentspinCel();
    if (gnOptionArrowFrame)
    {
        tContext.nFrame = 8 - gnOptionArrowFrame;
    }
    else
    {
        tContext.nFrame = 0;
    }

    const int nArrowY = gpOptionEntries[gnOptionSelected].nY + gpOptionHeader->nArrowOffset;
    sub_004F6480(&tContext, gnScreenWidth / 2 - gnOptionMaxWidth - 0xF9, nArrowY, -1, 5, 0);
    tContext.nFrame = gnOptionArrowFrame;
    sub_004F6480(&tContext, gnScreenWidth / 2 + 0xF9, nArrowY, -1, 5, 0);
    if (UI_TickElapsed())
    {
        gnOptionArrowFrame = (gnOptionArrowFrame + 1) % 8;
    }
}


// 0x0047E720
void __cdecl sub_0047E720_LoadAlwaysRun()
{
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "Always Run", 0, &dwValue);
    GAME_SetAlwaysRun(dwValue);
}

// 0x0047E750
void __cdecl sub_0047E750_SaveAlwaysRun()
{
    SRegSaveValue("Diablo II", "Always Run", 0, GAME_GetAlwaysRun());
}

// 0x0047E770
static void sub_0047E770_DrawModeCel(int nMode)
{
    if (!nMode)
        return;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpMiniPanelCel;
    switch (nMode)
    {
    case 1:
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0xCD, gnScreenHeight - 0x2F, -1, 5, 0);
        break;
    case 2:
    {
        const int nX = gbSmallPanel ? gnScreenWidth / 2 - 0x4A : gnScreenWidth / 2 - 0x54;
        sub_004F6480(&tContext, nX - 3, gnScreenHeight - 0x2F, -1, 5, 0);
        break;
    }
    case 3:
    {
        const int nX = gbSmallPanel ? gnScreenWidth / 2 + 0x38 : gnScreenWidth / 2 + 0x23;
        sub_004F6480(&tContext, nX - 2, gnScreenHeight - 0x2F, -1, 5, 0);
        break;
    }
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0047E8B0
static void sub_0047E8B0_LayoutSlots(int nMode)
{
    int nSlots = 8;
    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }
    int nFrameAdd = 0;
    int nKindAdd = 0;
    if (!nMode)
    {
        return;
    }
    int nX = gnScreenWidth / 2 - 0x54;
    if (gbSmallPanel_007BC978)
    {
        nX = gnScreenWidth / 2 - 0x4A;
    }
    const int nY = gnScreenHeight - 0x32;
    if (nMode == 1)
    {
        nX = gnScreenWidth / 2 - 0xCA;
    }
    else if (nMode == 3)
    {
        nX = gnScreenWidth / 2 + 0x39;
        if (!gbSmallPanel_007BC978)
        {
            nX = gnScreenWidth / 2 + 0x23;
        }
    }
    gaSlotKind[0] = 0;
    gaSlotFrame[0] = 0;
    gaSlotX[0] = nX;
    gaSlotY[0] = nY;
    nX += 0x15;
    for (int i = 1; i < nSlots; ++i)
    {
        gaSlotX[i] = nX;
        gaSlotY[i] = nY;
        if (gbSmallPanel_007BC978)
        {
            if (i == 3)
            {
                nFrameAdd += 2;
                nKindAdd += 1;
            }
            gaSlotKind[i] = nKindAdd + i;
            gaSlotFrame[i] = nFrameAdd + i * 2;
        }
        else
        {
            gaSlotKind[i] = i;
            gaSlotFrame[i] = i * 2;
        }
        nX += 0x15;
    }
}

// 0x0047E9A0
void __stdcall sub_0047E9A0_DrawSlots(int bDraw)
{
    int nSlots = 8;
    if (!bDraw)
    {
        return;
    }

    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }

    int i = 0;
    if (nSlots > 0)
    {
        for (;;)
        {
            if (gnSlotState_007BC8F8[i] == 1)
            {
                D2CelContextStrc tContext = {};
                tContext.pCellFile = gpSlotCells;
                tContext.nFrame = gaSlotFrame[i] + 1;
                TEXTURE_CelDraw(&tContext, gaSlotX[i], gaSlotY[i], -1, 5, 0);
                if (++i >= nSlots)
                    break;
            }
            else
            {
                D2CelContextStrc tContext = {};
                tContext.pCellFile = gpSlotCells;
                tContext.nFrame = gaSlotFrame[i];
                TEXTURE_CelDraw(&tContext, gaSlotX[i], gaSlotY[i], -1, 5, 0);
                if (++i >= nSlots)
                    break;
            }
        }
    }
}


// 0x0047EA60
int __cdecl sub_0047EA60_IsAnyPanelOpen()
{
    int bResult = 0;
    if (GAME_GetUIVarState(0x17) || GAME_GetUIVarState(0x19) || GAME_GetUIVarState(0x1A) || GAME_GetUIVarState(0xC)
        || GAME_GetUIVarState(0x1C) || GAME_GetUIVarState(0x1D) || GAME_GetUIVarState(0x18) || GAME_GetUIVarState(3)
        || GAME_GetUIVarState(0x10) || GAME_GetUIVarState(0x16) || GAME_GetUIVarState(0x24) || GAME_GetUIVarState(2)
        || GAME_GetUIVarState(0xF) || GAME_GetUIVarState(0x14) || GAME_GetUIVarState(0x1B))
    {
        bResult = 1;
    }
    gbAnyPanelOpen = bResult;
    if (GAME_GetUIVarState(0x24))
    {
        bResult = 1;
        gbAnyPanelOpen = bResult;
    }
    return bResult;
}

// 0x0047EB50
int __cdecl sub_0047EB50_IsAnyLeftPanelOpen()
{
    int bResult = 0;
    if (GAME_GetUIVarState(0x17) || GAME_GetUIVarState(0x19) || GAME_GetUIVarState(0x1C) || GAME_GetUIVarState(0x1A)
        || GAME_GetUIVarState(0xC) || GAME_GetUIVarState(0x18) || GAME_GetUIVarState(0x1B) || GAME_GetUIVarState(3))
    {
        bResult = 1;
        gbAnyLeftPanelOpen = bResult;
    }
    if ((GAME_GetUIVarState(0x1F) || HIREABLES_AreBeltRowsShown()) && HIREABLES_GetBeltRowCount() > 1)
    {
        bResult = 1;
        gbAnyLeftPanelOpen = bResult;
    }
    if (GAME_GetUIVarState(1) || GAME_GetUIVarState(4))
    {
        bResult = 1;
        gbAnyLeftPanelOpen = bResult;
    }
    else
    {
        gbAnyLeftPanelOpen = 0;
    }
    return bResult;
}

// 0x0047EC20
int __fastcall sub_0047EC20_IsPanelFreeForArg(int bArg)
{
    if (bArg && !GAME_GetUIVarState(0x17))
    {
        return 1;
    }
    return 0;
}


// 0x0047EC40
int __cdecl sub_0047EC40_IsSet()
{
    return gdwGlobal_007BC974 != 0;
}

// 0x0047EC50
static void sub_0047EC50_DoSlotAction(int nButton)
{
    switch (nButton)
    {
    case 0:
        if (GAME_GetUIVarState(2))
            UI_SetUIVar(2, 1, 0);
        else
            UI_SetUIVar(2, 2, 0);
        break;
    case 1:
        if (GAME_GetUIVarState(1))
            UI_SetUIVar(1, 1, 0);
        else
            UI_SetUIVar(1, 2, 0);
        break;
    case 2:
        if (GAME_GetUIVarState(4))
            UI_SetUIVar(4, 1, 0);
        else
            UI_SetUIVar(4, 2, 0);
        break;
    case 3:
        if (GAME_GetConnectionType())
        {
            if (GAME_GetUIVarState(0x16))
                UI_SetUIVar(0x16, 1, 0);
            else
                UI_SetUIVar(0x16, 2, 0);
        }
        break;
    case 4:
        if (GAME_GetUIVarState(0xA))
            UI_SetUIVar(0xA, 1, 0);
        else
            UI_SetUIVar(0xA, 2, 0);
        break;
    case 5:
        if (GAME_GetUIVarState(0x1F))
            UI_SetUIVar(0x1F, 1, 0);
        if (GAME_GetUIVarState(0x18))
            UI_SetUIVar(0x18, 1, 0);
        else
            UI_SetUIVar(0x18, 2, 0);
        break;
    case 6:
        OutputDebugStringA("Panel quest log toggle\n");
        QUESTLOG_ToggleQuestLog(0);
        break;
    case 7:
        UI_CloseUIVars(0, 0);
        UI_DisableUIVarDelay();
        WARDENCLIENT_ToggleEscMenuUIState(1, 0);
        UI_EnableUIVarDelay();
        UI_StartUIVarDelay();
        break;
    }
}

// 0x0047ED90
void __stdcall sub_0047ED90_SlotsClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!gbSlotClicked)
        return;
    gbSlotClicked = 0;
    if (!pPlayer)
        return;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pInventory)
        return;
    if (INVENTORY_GetCursorItem(pInventory))
        return;
    if (sub_00468830() != 7)
        CURSOR_SetCursorItemState(0);
    int nCount = 8;
    if (gbSmallPanel)
        nCount = 7;
    if (!gbSlotBarBlocked)
    {
        D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        int nOffset = 0;
        for (int i = 0; i < nCount; ++i)
            gnSlotState_007BC8F8[i] = 0;
        if (HIREABLES_AreBeltRowsShown() && HIREABLES_GetBeltRowCount() > 1)
            nOffset = -0x76;
        if (gbAnyLeftPanelOpen)
            nOffset -= 0x76;
        if (gbAnyPanelOpen)
            nOffset += 0x77;
        const int nCenter = gnScreenWidth / 2 + nOffset;
        if (nX > nCenter - 0x54 && nX < nCenter + 0x59 && nY > gnScreenHeight - 0x45 && nY < gnScreenHeight - 0x2F)
        {
            for (int i = 0; i < nCount; ++i)
            {
                if (nX <= gaSlotX[i])
                    continue;
                if (nX >= gaSlotX[i] + 0x14)
                    continue;
                const int nButton = gaSlotKind[i];
                if (nButton == 7)
                {
                    sub_0047EC50_DoSlotAction(nButton);
                }
                else if (!GAME_GetUnitTypeOrInvalid(pUnit) && sub_00451F70_GetUnitMode(pUnit) != 0x11)
                {
                    sub_0047EC50_DoSlotAction(nButton);
                }
            }
            GAME_ResetMouseState();
            GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        pMsg->bReturn = 0;
    }
    gdwGlobal_007BC974 = 0;
}

// 0x0047EF30
void __stdcall sub_0047EF30_SlotsClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nSlots = 8;
    if (gbSmallPanel)
    {
        nSlots = 7;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer || !pPlayer->pInventory || INVENTORY_GetCursorItem(pPlayer->pInventory) || gbSlotBarBlocked)
    {
        return;
    }
    D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
    if (!pUnit)
    {
        return;
    }
    int nY = pMsg->nYpos;
    int nX = pMsg->nXpos;
    int nOffset = 0;
    if (HIREABLES_AreBeltRowsShown() && HIREABLES_GetBeltRowCount() > 1)
    {
        nOffset = -0x76;
    }
    if (gbAnyLeftPanelOpen)
    {
        nOffset -= 0x76;
    }
    if (gbAnyPanelOpen)
    {
        nOffset += 0x77;
    }
    int nCenter = gnScreenWidth / 2 + nOffset;
    if (nX <= nCenter - 0x54 || nX >= nCenter + 0x59 || nY <= gnScreenHeight - 0x45 || nY >= gnScreenHeight - 0x2F)
    {
        return;
    }
    for (int i = 0; i < nSlots; ++i)
    {
        if (nX > gaSlotX_007BC898[i] && nX < gaSlotX_007BC898[i] + 0x14)
        {
            if (gaSlotKind[i] == 7)
            {
                gaSlotState[i] = 1;
            }
            else if (pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11)
            {
                if (!GAME_GetUIVarState(9))
                {
                    gaSlotState[i] = 1;
                }
                else if (!GAME_GetConnectionType())
                {
                    if (i >= 4)
                    {
                        gaSlotState[i] = 1;
                    }
                }
                else
                {
                    if (i >= 5)
                    {
                        gaSlotState[i] = 1;
                    }
                }
            }
            sub_004B9A00(4, 0, 0, 0, 0);
            gbSlotClicked = 1;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
}


// 0x0047F0C0
void __cdecl sub_0047F0C0_LoadMiniPanel()
{
    if (GAME_GetConnectionType())
    {
        gpMiniPanelCel = GAME_LoadUiCelFile("Panel\\minipanel");
        gbSmallPanel = 0;
    }
    else
    {
        gpMiniPanelCel = GAME_LoadUiCelFile("Panel\\minipanel_s");
        gbSmallPanel = 1;
    }
    gpSlotCells = GAME_LoadUiCelFile("Panel\\minipanelbtn");
    int nSlots = 8;
    if (gbSmallPanel)
        nSlots = 7;
    for (int i = 0; i < nSlots; i++)
        gaSlotState[i] = 0;
}

// 0x0047F130
void __cdecl sub_0047F130_SaveMiniPanel()
{
    int bValue = 0;
    if (!gbPanelFlag)
        bValue = 1;
    SRegSaveValue("Diablo II", "Mini Panel", 1, bValue);
    if (gpMiniPanelCel)
    {
        ARCHIVE_FreeClientCellFile(gpMiniPanelCel);
        gpMiniPanelCel = 0;
    }
    if (gpSlotCells)
    {
        ARCHIVE_FreeClientCellFile(gpSlotCells);
        gpSlotCells = 0;
    }
}

// 0x0047F190
int __fastcall sub_0047F190_IsInMiniPanelRect(int nX, int nY)
{
    const int nHalfWidth = gnScreenWidth / 2;
    if (nX > nHalfWidth - 0x4A && nX < nHalfWidth + 0x47 && nY < gnScreenHeight - 0x32 && nY > gnScreenHeight - 0x45)
        return 1;
    return 0;
}

// 0x0047F1D0
void __cdecl sub_0047F1D0_LoadResolution()
{
    unsigned long dwValue;
    if (!SRegLoadValue("Diablo II", "Resolution", 0, &dwValue))
    {
        dwValue = 1;
    }
    int nResolution = 2;
    if (!dwValue)
    {
        nResolution = 0;
    }
    GAME_SetResolution(nResolution);
}

// 0x0047F210
int __cdecl sub_0047F210_IsMouseInSlots()
{
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (GAME_GetUIVarState(0x14) && GAME_GetUIVarState(0x15))
    {
        const int bSmallPanel = gbSmallPanel;
        int nLeft = gnScreenWidth / 2;
        if (bSmallPanel)
            nLeft += 0x38;
        else
            nLeft += 0x23;
        const int nBottom = gnScreenHeight - 0x32;
        int nSlots = 8;
        if (bSmallPanel)
            nSlots = 7;
        if (nX > nLeft && nX < nLeft + nSlots * 20 && nY > nBottom - 0x1A && nY < nBottom)
            return 1;
    }
    return 0;
}


// 0x0047F2A0
void __fastcall sub_0047F2A0_ShowPage1(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtOptionsHeader;
    gpOptionEntries = gaOptionsEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F2D0
void __fastcall sub_0047F2D0_ExitGame(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    WINMAIN_SetExitApplication(0);
    SendMessageA(pMsg->hWnd, 0x10, 0, 0);
    GAME_SetCinematicExit(1);
    sub_0047E200_CloseMenus(1);
}

// 0x0047F300
void __fastcall sub_0047F300_CloseMenus(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    sub_0047E200_CloseMenus(1);
}

// 0x0047F310
void __fastcall sub_0047F310_ShowPage2(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtSoundOptionHeader;
    gpOptionEntries = gaSoundOptionEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F340
void __fastcall sub_0047F340_ShowPage3(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        gpOptionHeader = &gtVideoResOptionHeader;
        gpOptionEntries = gaVideoResOptionEntries;
    }
    else
    {
        gpOptionHeader = &gtVideoOptionHeader;
        gpOptionEntries = gaVideoOptionEntries;
    }
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F3A0
void __fastcall sub_0047F3A0_ShowPage4(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    if (FOG_IsExpansion())
    {
        gpOptionHeader = &gtAutomapModeOptionHeader;
        gpOptionEntries = gaAutomapModeOptionEntries;
    }
    else
    {
        gpOptionHeader = &gtAutomapOptionHeader;
        gpOptionEntries = gaAutomapOptionEntries;
    }
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F400
void __fastcall sub_0047F400_OpenPanel(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_GetUIVarState(9))
        UI_SetUIVar(9, 1, 0);
    UI_SetUIVar(0xB, 0, 0);
}

// 0x0047F430
void __fastcall sub_0047F430_ShowPage0(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtMainOptionHeader;
    gpOptionEntries = gaMainOptionEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F460
void __fastcall sub_0047F460_ShowPage1Twin(D2OptionEntryStrc* pEntry, SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(9, 0, 0);
    gpOptionHeader = &gtOptionsHeader;
    gpOptionEntries = gaOptionsEntries;
    gnOptionSelected = gpOptionHeader->nCount - 1;
}

// 0x0047F490
static void __stdcall sub_0047F490_ShowSlotTooltip(int nX, int nY, int nKind)
{
    int bHasKey = 0;
    int nHotKey = 0x39;
    int nString;
    switch (nKind)
    {
    case 0:
        nString = 0x1049;
        bHasKey = 1;
        nHotKey = 0;
        break;
    case 1:
        bHasKey = 1;
        nString = 0x104A;
        nHotKey = 1;
        break;
    case 2:
        bHasKey = 1;
        nString = 0x104B;
        nHotKey = 0xC;
        break;
    case 3:
        bHasKey = 1;
        nString = 0x104C;
        nHotKey = 2;
        break;
    case 4:
        bHasKey = 1;
        nString = 0x104D;
        nHotKey = 7;
        break;
    case 5:
        bHasKey = 1;
        nString = 0x104E;
        nHotKey = 3;
        break;
    case 6:
        bHasKey = 1;
        nString = 0x104F;
        nHotKey = 4;
        break;
    case 7:
        nString = 0x1050;
        break;
    default:
        return;
    }
    Unicode wszText[200];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    if (bHasKey && nHotKey != 0x39)
    {
        Unicode wszKey[30];
        if (CUNIT_GetHotkeyBinding(nHotKey, 1) != 0xFFFF)
        {
            memset(wszKey, 0, sizeof(wszKey));
            sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyText(nHotKey, 1));
            sub_00526700(wszText, wszKey);
        }
        if (CUNIT_GetHotkeyBinding(nHotKey, 0) != 0xFFFF)
        {
            memset(wszKey, 0, sizeof(wszKey));
            sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyText(nHotKey, 0));
            sub_00526700(wszText, wszKey);
        }
    }
    D2Win_10129_DrawFramedText(wszText, nX - 3, nY - 0x1A, 0, 1);
}

// 0x0047F650
static void sub_0047F650_UpdateSlotHover(int nMode)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    int nOffset = 0;
    int nSlots = 8;
    if (gbSmallPanel_007BC978)
    {
        nSlots = 7;
    }
    if (!nMode)
    {
        return;
    }
    if (nMode == 1)
    {
        nOffset = -0x76;
    }
    else if (nMode == 3)
    {
        nOffset = 0x77;
    }
    const int nCenter = gnScreenWidth / 2 + nOffset;
    if (nMouseX <= nCenter - 0x54 || nMouseX >= nCenter + 0x59)
    {
        return;
    }
    if (nMouseY <= gnScreenHeight - 0x45 || nMouseY >= gnScreenHeight - 0x2F)
    {
        return;
    }
    for (int i = 0; i < nSlots; ++i)
    {
        if (nMouseX > gaSlotX[i] && nMouseX < gaSlotX[i] + 0x14)
        {
            sub_0047F490_ShowSlotTooltip(gaSlotX[i], gaSlotY[i], gaSlotKind[i]);
        }
    }
}

// 0x0047F710
void __cdecl sub_0047F710_UpdateSlotBar()
{
    const int bAnyPanel = sub_0047EA60_IsAnyPanelOpen();
    const int bLeftPanel = sub_0047EB50_IsAnyLeftPanelOpen();
    D2CelContextStrc tContext;
    if (bAnyPanel && !bLeftPanel)
    {
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = gpMiniPanelCel;
        int nX = gnScreenWidth / 2;
        if (gbSmallPanel_007BC978)
        {
            nX += 0x38;
        }
        else
        {
            nX += 0x23;
        }
        sub_004F6480(&tContext, nX - 2, gnScreenHeight - 0x2F, -1, 5, 0);
        sub_0047E8B0_LayoutSlots(3);
        sub_0047E9A0_DrawSlots(1);
        sub_0047F650_UpdateSlotHover(3);
        gbSlotBarBlocked = 0;
        return;
    }

    if (!bAnyPanel && !bLeftPanel)
    {
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = gpMiniPanelCel;
        int nX = gnScreenWidth / 2;
        if (gbSmallPanel_007BC978)
        {
            nX -= 0x4A;
        }
        else
        {
            nX -= 0x54;
        }
        sub_004F6480(&tContext, nX - 3, gnScreenHeight - 0x2F, -1, 5, 0);
        sub_0047E8B0_LayoutSlots(2);
        sub_0047E9A0_DrawSlots(1);
        sub_0047F650_UpdateSlotHover(2);
        gbSlotBarBlocked = 0;
        return;
    }

    if (!bAnyPanel && bLeftPanel)
    {
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = gpMiniPanelCel;
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0xCD, gnScreenHeight - 0x2F, -1, 5, 0);
        sub_0047E8B0_LayoutSlots(1);
        sub_0047E9A0_DrawSlots(1);
        sub_0047F650_UpdateSlotHover(1);
        gbSlotBarBlocked = 0;
        return;
    }

    sub_00468730();
    sub_00468740();
    gbSlotBarBlocked = 1;
}




void __cdecl sub_K04_EmitUse(int nValue);

void __cdecl sub_K04_EmitDrawModeCel(int nMode)
{
    sub_0047E770_DrawModeCel(nMode);
    sub_K04_EmitUse(nMode);
}

#include "gen/data/Source/D2Client/Unknown_0047CC90.inc"
