#include "D2Client.h"
#include "D2ClientFuncs.h"
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
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2GfxApi.h"
#include "D2WinApi.h"
#include "D2CMPApi.h"
#include "D2SoundApi.h"
#include "D2WinApi2.h"

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

struct HKL__;

extern "C" __declspec(dllimport) HKL__* __stdcall GetKeyboardLayout(unsigned long idThread); // 0x006CC4C0








































































































































































































extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

extern D2ClientFlagsLowStrc gtClientFlagsLow_00712EFC; // 0x00712EFC

extern D2ClientFlagsStrc gtClientFlags_00712EFC; // 0x00712EFC

int gnLanguageId;        // 0x007BB5DC

extern int gnChatHistoryCursor; // 0x007BB5D8

unsigned int gnChatCaret; // 0x007BB5E8

extern int gnChatDrawCount; // 0x007BB5EC

Unicode gwszChatLine_007BB638[0x101]; // 0x007BB638

void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0


extern "C" int __stdcall ImmSimulateHotKey(void* hWnd, unsigned long nHotKey); // 0x006B00E4

extern D2MsgHandlerEntryStrc gaChatHandlers[]; // 0x00712F4C

extern D2MsgHandlerEntryStrc gaChatInputHandlers[]; // 0x00712FA8

Unicode gwszImeResult[32]; // 0x007BB5F8

Unicode gwszImeComposition[32]; // 0x007BC850

Unicode gawszChatHistory[8][0x101]; // 0x007BB840

struct HKL__;

typedef HIMC__* HIMC;

struct CANDIDATELIST
{
    unsigned long dwSize;
    unsigned long dwStyle;
    unsigned long dwCount;
};




extern "C" int __stdcall ImmReleaseContext(void* hWnd, HIMC hImc); // 0x006B00B4

extern "C" int __stdcall ImmGetOpenStatus(HIMC hImc); // 0x006B00BA

extern "C" HIMC __stdcall ImmGetContext(void* hWnd); // 0x006B00C6

extern "C" unsigned long __stdcall ImmGetCandidateListA(HIMC hImc, unsigned long dwIndex, CANDIDATELIST* pCandList, unsigned long dwBufLen); // 0x006B00CC

extern "C" unsigned long __stdcall ImmGetCandidateListCountA(HIMC hImc, unsigned long* pListCount); // 0x006B00D2

extern "C" int __stdcall ImmIsIME(HKL__* hKl); // 0x006B00D8

extern "C" int __stdcall ImmGetConversionStatus(HIMC hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE


unsigned char gbImeOpen;        // 0x007BB5E0

extern int gnImeState; // 0x007BB5F0

static CANDIDATELIST* gpImeCandidateList; // 0x007BB5F4

unsigned char gbChatInputOpen; // 0x007BB5E1

void __fastcall sub_00451E10_RegisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10





extern int gdwGlobal_00712F04; // 0x00712F04








extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C

extern "C" long __stdcall ImmGetCompositionStringA(HIMC__* hImc, unsigned long dwIndex, void* pBuf, unsigned long dwBufLen); // 0x006B00C0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

// 0x0047AA60
void __stdcall CHAT_OnImeComposition(SMSGHANDLER_PARAMS* pMsg)
{
    char szComp[200];
    memset(szComp, 0, sizeof(szComp));
    HIMC__* hImc = ImmGetContext(WINDOW_GetWindow());
    if (hImc)
    {
        Unicode wszText[32];
        for (int i = 0; i < 32; ++i)
            wszText[i].wChar = 0;
        if (pMsg->lParam & 0x800)
        {
            unsigned long nLength = ImmGetCompositionStringA(hImc, 0x800, 0, 0);
            if (nLength > 199)
                nLength = 199;
            ImmGetCompositionStringA(hImc, 0x800, szComp, nLength);
            szComp[199] = 0;
            MultiByteToWideChar(0, 1, szComp, -1, (wchar_t*)wszText, 32);
            wszText[31].wChar = 0;
            const int nTextLength = UNICODE_StrLen(wszText);
            if (UNICODE_StrLen(gwszChatLine_007BB638) + UNICODE_StrLen(gwszImeResult) < 0x7F)
            {
                sub_00526700(gwszChatLine_007BB638, gwszImeResult);
                gnChatCaret += UNICODE_StrLen(gwszImeResult);
            }
            if (UNICODE_StrLen(gwszChatLine_007BB638) + nTextLength < 0x7F)
            {
                sub_00526700(gwszChatLine_007BB638, wszText);
                gnChatCaret += nTextLength;
            }
            gwszImeResult[0].wChar = 0;
            gwszImeComposition[0].wChar = 0;
        }
        if ((pMsg->lParam & 8) && ImmGetOpenStatus(hImc))
        {
            unsigned long nLength = ImmGetCompositionStringA(hImc, 8, 0, 0);
            if (nLength > 0)
            {
                memset(szComp, 0, sizeof(szComp));
                memset(wszText, 0, sizeof(wszText));
                if (nLength > 199)
                    nLength = 199;
                if (ImmGetCompositionStringA(hImc, 8, szComp, nLength) > 0)
                {
                    szComp[199] = 0;
                    MultiByteToWideChar(0, 1, szComp, -1, (wchar_t*)wszText, 32);
                    const int nCount = UNICODE_StrLen(wszText);
                    if (nCount < 31)
                        wszText[nCount].wChar = 0;
                    else
                        wszText[31].wChar = 0;
                    if (nCount >= 32)
                    {
                        Unicode::strncpy(gwszImeComposition, wszText, 31);
                        gwszImeComposition[31].wChar = 0;
                        sub_004B9A00(1, 0, 0, 0, 0);
                    }
                    else
                    {
                        sub_005267E0(gwszImeComposition, wszText);
                    }
                }
            }
        }
        ImmReleaseContext(WINDOW_GetWindow(), hImc);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}


void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

extern int gdwGlobal_007BB5DC; // 0x007BB5DC


extern int gnGlobal_007BB5DC;                                                                               // 0x007BB5DC

static int gnImeState;                                                                               // 0x007BB5F0

// 0x0047ACA0
void __stdcall CHAT_HandleImeStartComposition(SMSGHANDLER_PARAMS* pMsg)
{
    gbImeOpen = 1;
    gwGlobal_007BC850 = 0;
    gwGlobal_007BB5F8 = 0;
    if (gnGlobal_007BB5DC == 9)
        gnImeState = 4;
    else if (gnGlobal_007BB5DC == 8)
        gnImeState = 5;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0047AD10
void __stdcall CHAT_ResetImeCompositionMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gwGlobal_007BC850 = 0;
    gwGlobal_007BB5F8 = 0;
    gnChatDrawCount = -2;
    if (gdwGlobal_007BB5DC == 6)
        gbImeOpen = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047AD60
static void CHAT_RefreshCandidates(HIMC hImc)
{
    unsigned long nListCount;
    unsigned long nSize = ImmGetCandidateListCountA(hImc, &nListCount);
    if (ImmGetCandidateListA(hImc, 0, 0, 0) && nSize)
    {
        if (gpImeCandidateList)
        {
            FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 235, 0);
        }

        gpImeCandidateList = (CANDIDATELIST*)FOG_Alloc(nSize, ".\\UI\\chat.cpp", 237, 0);
        ImmGetCandidateListA(hImc, 0, gpImeCandidateList, nSize);

        if (gpImeCandidateList->dwStyle == 2 && gpImeCandidateList->dwCount == 1)
        {
            FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 242, 0);
            gpImeCandidateList = 0;
        }
    }
}

// 0x0047AE00
void __stdcall CHAT_ImeNotifyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    unsigned long nSentence;

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);

    HIMC hImc = ImmGetContext(WINDOW_GetWindow());
    if (!hImc)
    {
        return;
    }

    switch (pMsg->wParam)
    {
    case 8:
        switch (gnLanguageId)
        {
        case 6:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen = 1;
                gnImeState = 3;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
            break;

        case 8:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen = 1;
                gnImeState = 5;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
            break;

        case 9:
            if (ImmGetOpenStatus(hImc))
            {
                gbImeOpen = 1;
                gnImeState = 4;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
            break;
        }
        break;

    case 6:
    {
        unsigned long nConversion;
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        if (gnLanguageId == 7 || gnLanguageId == 12)
        {
            if (nConversion & 1)
            {
                gnImeState = 1;
                gbImeOpen = 1;
            }
            else
            {
                gbImeOpen = 0;
                gnImeState = 0;
            }
        }
        break;
    }

    case 5:
        if (gnLanguageId == 9)
        {
            CHAT_RefreshCandidates(hImc);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId == 8)
        {
            CHAT_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 4:
        if (gnLanguageId == 9)
        {
            if (gpImeCandidateList)
            {
                FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 352, 0);
                gpImeCandidateList = 0;
            }
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        if (gnLanguageId == 8)
        {
            if (gpImeCandidateList)
            {
                FOG_Free(gpImeCandidateList, ".\\UI\\chat.cpp", 363, 0);
                gpImeCandidateList = 0;
            }
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 3:
        if (gnLanguageId == 9)
        {
            CHAT_RefreshCandidates(hImc);
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
        }
        break;

    case 2:
        if (gnLanguageId == 9)
        {
            gnImeState = ImmIsIME(GetKeyboardLayout(0)) ? 0 : 4;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
        }
        break;
    }

    ImmReleaseContext(WINDOW_GetWindow(), hImc);
}

// 0x0047B010
bool __cdecl CHAT_IsImeLanguage()
{
    if (gnLanguageId == 9)
    {
        const unsigned short nLangId = GetSystemDefaultLangID();
        if (nLangId == 0x404 || nLangId == 0xC04)
            return true;
        return false;
    }
    if (gnLanguageId == 8)
    {
        const unsigned short nLangId = GetSystemDefaultLangID();
        if (nLangId == 0x804 || nLangId == 0x1004)
            return true;
        return false;
    }
    return ImmIsIME(GetKeyboardLayout(0));
}

// 0x0047B070
void __stdcall CHAT_SetMsgHandled(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x0047B090
void __cdecl CHAT_InitChatIme()
{
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatHandlers, 4);
    gnLanguageId = STRTABLE_GetLanguage();
    if (gnLanguageId != 6 && gnLanguageId != 9 && gnLanguageId != 8 && gnLanguageId != 7 && gnLanguageId != 12)
        return;

    gbChatInputOpen = 0;
    if (!CHAT_IsImeLanguage())
        return;

    const unsigned short nLangId = GetSystemDefaultLangID();
    HIMC hImc = ImmGetContext(WINDOW_GetWindow());
    if (!hImc)
        return;

    gwszImeComposition[0].wChar = 0;
    gwszImeResult[0].wChar = 0;
    switch (gnLanguageId)
    {
    case 6:
        if (nLangId != 0x411)
            break;
        gbChatInputOpen = 1;
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        if (ImmSetOpenStatus(hImc, 1))
        {
            gbImeOpen = 1;
            gnImeState = 3;
        }
        else
        {
            gbImeOpen = 0;
            gnImeState = 0;
        }
        ImmReleaseContext(WINDOW_GetWindow(), hImc);
        return;

    case 7:
    case 12:
    {
        if (nLangId != 0x412 && nLangId != 0x812)
            break;
        ImmSetOpenStatus(hImc, 1);
        unsigned long nConversion, nSentence;
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        ImmSetConversionStatus(hImc, 1, nSentence);
        ImmGetConversionStatus(hImc, &nConversion, &nSentence);
        if (nConversion & 1)
        {
            gnImeState = 1;
            gbImeOpen = 1;
        }
        else
        {
            gnImeState = 0;
        }
        gbChatInputOpen = 1;
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        break;
    }

    case 9:
        gbImeOpen = 0;
        gbChatInputOpen = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(WINDOW_GetWindow(), 0x70);
        ImmSetOpenStatus(hImc, 1);
        gnImeState = 4;
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        break;

    case 8:
        gbImeOpen = 0;
        gbChatInputOpen = 1;
        if (!ImmIsIME(GetKeyboardLayout(0)))
            ImmSimulateHotKey(WINDOW_GetWindow(), 0x10);
        ImmSetOpenStatus(hImc, 1);
        gnImeState = 5;
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        break;
    }
    ImmReleaseContext(WINDOW_GetWindow(), hImc);
}


// 0x0047B2E0
void __cdecl CHAT_CloseChatInput()
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaChatHandlers, 4);
    if (gbChatInputOpen)
    {
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaChatInputHandlers, 7);
        HIMC__* hImc = ImmGetContext(WINDOW_GetWindow());
        if (hImc)
        {
            ImmSetOpenStatus(hImc, 0);
            if (gnLanguageId == 7 || gnLanguageId == 12)
            {
                unsigned long nConversion;
                unsigned long nSentence;
                ImmGetConversionStatus(hImc, &nConversion, &nSentence);
                ImmSetConversionStatus(hImc, 0, nSentence);
            }
            ImmReleaseContext(WINDOW_GetWindow(), hImc);
        }
        gwszImeResult[0].wChar = 0;
        gwszImeComposition[0].wChar = 0;
        if (gpChatBuffer_007BB5F4)
        {
            FOG_Free(gpChatBuffer_007BB5F4, ".\\UI\\chat.cpp", 0x29D, 0);
            gpChatBuffer_007BB5F4 = 0;
        }
    }
}


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

unsigned long gdwBlinkTick; // 0x007BC890

// 0x0047B450
static void CHAT_DrawBlinkingCaret(int nY, int nColor, int nX)
{
    if (gnBlinkOn == 1)
    {
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xD4C), nX + 0x83, nY, nColor, 0);
    }

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwBlinkTick > gwBlinkDelay)
    {
        gdwBlinkTick = dwTick;
        if (gnBlinkOn)
        {
            gwBlinkDelay = 100;
            gnBlinkOn = 0;
        }
        else
        {
            gwBlinkDelay = 500;
            gnBlinkOn = 1;
        }
    }
}

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




int __cdecl sub_004DF980_IsSoundMode1Or2();

void __fastcall sub_004776C0_SetGamma(void* pArg);






void __fastcall AUTOMAP_SetAutomapMode(int nMode); // 0x0045A720






int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern D2ViewStrc* gpClientView; // 0x007A0640



extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09




void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00


extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200













void __cdecl GAME_ResetMouseState(); // 0x0044DA40



extern int gdwGlobal_007BC974; // 0x007BC974

extern int gbAnyLeftPanelOpen; // 0x007BC968

extern int gbAnyPanelOpen; // 0x007BC96C

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880



static inline int sub_0047D500_IsOptionEnabled(D2OptionEntryStrc* pEntry);









extern D2ChatCommandStrc gaChatCommands[3]; // 0x00712F7C

extern D2CelFileStrc* gpSliderDisabledCell_007BC950; // 0x007BC950

extern D2CelFileStrc* gpSliderEnabledCell_007BC954; // 0x007BC954

extern D2CelFileStrc* gpSliderKnob_007BC958; // 0x007BC958

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

extern void* gpSlotCells; // 0x007BC964



extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330


struct D2CandidateListStrc
{
    unsigned int dwSize;
    unsigned int dwStyle;
    unsigned int dwCount;
    unsigned int dwSelection;
    unsigned int dwPageStart;
    unsigned int dwPageSize;
    unsigned int dwOffset[1];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

// 0x0047B5C0
void __cdecl CHAT_DrawImeCandidates()
{
    if (gpChatBuffer_007BB5F4)
    {
        D2CandidateListStrc* const pList = (D2CandidateListStrc*)gpChatBuffer_007BB5F4;
        int nFirst;
        int nLast;
        if (pList->dwPageSize)
        {
            nFirst = pList->dwPageStart;
            if (pList->dwCount < pList->dwPageStart + pList->dwPageSize)
                nLast = pList->dwCount;
            else
                nLast = pList->dwPageStart + pList->dwPageSize;
        }
        else
        {
            nFirst = 0;
            nLast = pList->dwCount;
            if (pList->dwCount >= 20)
                nLast = 20;
        }

        int nIndex = 0;
        const int nLineHeight = D2Win_10125();
        for (int i = nFirst; i < nLast; i++)
        {
            const char* szCandidate = (const char*)pList + pList->dwOffset[i];
            ++nIndex;
            const int nY = nIndex * nLineHeight;

            Unicode wszIndex[20];
            memset(wszIndex, 0, sizeof(wszIndex));
            char szIndex[20];
            sprintf(szIndex, "%d: ", nIndex);
            Unicode::win2Unicode(wszIndex, szIndex, 20);
            D2Win_10117_DrawText(wszIndex, 20, nY + gnScreenHeight - 0x170, 0, 0);

            Unicode wszText[256];
            for (int j = 0; j < 256; j++)
                wszText[j].wChar = 0;
            if (MultiByteToWideChar(0, 1, szCandidate, -1, (wchar_t*)wszText, 0x101))
                D2Win_10117_DrawText(wszText, 0x1E, nY + gnScreenHeight - 0x170, 0, 0);

            if (nY > 0x118)
                break;
        }
    }
}


Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20



extern int gnImeState;                                                                          // 0x007BB5F0

// 0x0047B4F0
void __stdcall CHAT_DrawImeText(int nX, int nY)
{
    int nWidth = 0;
    int nTextX = nX;
    int nTextY = nY;
    if (UNICODE_StrLen(gwszImeResult))
    {
        nWidth = D2Win_10121_GetTextWidth(gwszImeResult);
        if (nWidth + nTextX - 0x83 > gnScreenWidth - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        D2Win_10117_DrawText(gwszImeResult, nTextX, nTextY, 4, 0);
    }

    const int nWidth2 = D2Win_10121_GetTextWidth(gwszImeComposition);
    if (UNICODE_StrLen(gwszImeComposition))
    {
        if (nWidth2 + nTextX + nWidth - 0x83 > gnScreenWidth - 0x109)
        {
            nTextX = 0x83;
            nTextY += 0xF;
        }
        D2Win_10117_DrawText(gwszImeComposition, nTextX + nWidth, nTextY, 4, 0);
    }

    CHAT_DrawBlinkingCaret(nTextY, 4, nWidth2 + nTextX + nWidth - 0x83);
}

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth);       // 0x00502970

// 0x0047B720
void __cdecl CHAT_DrawChatPanel()
{
    const int nOldFont = D2Win_10127_SetFont(13);
    if (gbChatInputOpen)
    {
        Unicode wszLanguage[20];
        memset(wszLanguage, 0, sizeof(wszLanguage));
        switch (gnImeState)
        {
        case 0:
            sub_00526F20_ToUnicode(wszLanguage, "Alphanumeric", 20);
            D2Win_10117_DrawText(wszLanguage, 0x14, gnScreenHeight - 0x80, 0, 0);
            break;

        case 4:
        case 5:
            wszLanguage[1].wChar = 0x6F22;
            wszLanguage[2].wChar = 0;
            D2Win_10117_DrawText(wszLanguage, 0x14, gnScreenHeight - 0x80, 0, 0);
            CHAT_DrawImeCandidates();
            break;

        case 1:
            wszLanguage[0].wChar = 0xD55C;
            wszLanguage[1].wChar = 0xAE00;
            wszLanguage[2].wChar = 0;
            D2Win_10117_DrawText(wszLanguage, 0x14, gnScreenHeight - 0x80, 0, 0);
            break;

        case 2:
        case 3:
            wszLanguage[0].wChar = 0x65E5;
            wszLanguage[1].wChar = 0x672C;
            wszLanguage[2].wChar = 0x8A9E;
            wszLanguage[3].wChar = 0;
            D2Win_10117_DrawText(wszLanguage, 0x14, gnScreenHeight - 0x80, 0, 0);
            break;
        }
    }

    gnChatDrawCount += 1;
    AUTOMAP_DrawFramedBox(0x7F, gnScreenHeight - 0x67, gnScreenWidth - 0xFF, 0x2F, 0, 1);

    int nWidth = 0;
    if (GAME_IsExitPending())
    {
        UI_SetUIVar(5, 1, 0);
    }

    int nRow = 0;
    if (UNICODE_StrLen(gwszChatLine_007BB638) > 0)
    {
        Unicode wszText[0x101];
        for (int i = 0; i < 0x101; ++i)
        {
            wszText[i].wChar = 0;
        }
        sub_00526790(wszText, gwszChatLine_007BB638, 0x100);

        int nLineCount;
        D2SplittedTextStrc* pLines = D2WINFONT_SplitText(wszText, &nLineCount, gnScreenWidth - 0x109);
        D2SplittedTextStrc* pLine = pLines;
        int nLine = 0;
        while (pLine)
        {
            nRow = nLine;
            if (nLine < 3)
            {
                D2Win_10117_DrawText(pLine->wszLine, 0x83, 15 * nLine + gnScreenHeight - 0x58, 0, 0);
                nWidth = D2Win_10121_GetTextWidth(pLine->wszLine);
            }

            D2SplittedTextStrc* pNext = pLine->pNextLine;
            if (!pNext && gbChatInputOpen && gbImeOpen)
            {
                CHAT_DrawImeText(D2Win_10121_GetTextWidth(pLine->wszLine) + 0x83, 15 * nLine + gnScreenHeight - 0x58);
            }

            nLine += 1;
            pLine = pNext;
        }
        D2Win_10200(pLines);

        if (nLine > 0)
        {
            nRow = (nLine - 1 > 2) ? 2 : nLine - 1;
        }
    }
    else if (gbChatInputOpen && gbImeOpen)
    {
        CHAT_DrawImeText(0x83, gnScreenHeight - 0x58);
    }

    if (!gbChatInputOpen || !gbImeOpen)
    {
        CHAT_DrawBlinkingCaret(15 * nRow + gnScreenHeight - 0x58, 0, nWidth);
    }

    D2Win_10127_SetFont(nOldFont);
}


struct D2GfxLightStrc;

extern unsigned short gwChatCount_007BB5E4; // 0x007BB5E4

// 0x0047BA80
void __stdcall CHAT_StepChatIndex(int nDelta)
{
    int nOld = gnChatHistoryCursor;
    gnChatHistoryCursor += nDelta;
    if (gnChatHistoryCursor >= 8)
    {
        gnChatHistoryCursor = 0;
    }
    else if (gnChatHistoryCursor < 0)
    {
        gnChatHistoryCursor = 7;
    }
    if (gwChatCount_007BB5E4 < 7 && 8 - gnChatHistoryCursor > gwChatCount_007BB5E4)
    {
        gnChatHistoryCursor = nOld;
    }
}

// 0x0047BAD0
int __stdcall CHAT_ParseChatCommand(const char** ppText, char* pCode, char* szArgument)
{
    char szText[0x100];
    char szToken[0x104];
    const char* pText = szText;
    *szArgument = 0;
    strncpy(szText, *ppText, 0x100);
    const int nTextLen = SStrLen(pText);
    for (int i = 0; i < 3; i++)
    {
        const int nNameLen = SStrLen(gaChatCommands[i].szName);
        if (!gaChatCommands[i].bAlways && !GAME_GetConnectionType())
            continue;

        if (gaChatCommands[i].nCode == 3)
        {
            if (nTextLen < nNameLen)
                continue;
            if (SStrCmpI(pText, gaChatCommands[i].szName, nNameLen))
                continue;
            *pCode = gaChatCommands[i].nCode;
            return 1;
        }

        if (nTextLen <= nNameLen)
            continue;
        if (SStrCmpI(pText, gaChatCommands[i].szName, nNameLen))
            continue;
        if (!pText[nNameLen])
            continue;

        pText += nNameLen;
        if (gaChatCommands[i].bArgument)
        {
            SStrTokenize(&pText, szToken, 0x100, gszSpace, 0);
            if (!strlen(pText))
                return 0;
            if (strlen(szToken) >= 0x32)
                return 0;
            SStrCopy(szArgument, szToken, 0x7FFFFFFF);
            *ppText += strlen(szToken) + nNameLen + 1;
        }
        else
        {
            *ppText += nNameLen;
        }
        *pCode = gaChatCommands[i].nCode;
        return 1;
    }
    return 0;
}

// 0x0047BC70
void __stdcall CHAT_CloseChatOnPanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nYpos > gnScreenHeight - 0x31)
        UI_SetUIVar(5, 1, 0);
}

// 0x0047BD60
static const char* CHAT_GetAccountPart(const char* szName)
{
    const char* p = SStrChr(szName, 0x2A);
    if (p && *++p)
        return p;
    return szName;
}

struct D2BnetChatPacketStrc;

extern "C" int __cdecl strcmp(const char* a, const char* b);



extern int gnOptionArrowFrame; // 0x007BC944

extern int gnOptionLastX; // 0x007BC980

extern int gnOptionLastY; // 0x007BC984








static void sub_0047D5C0_ActivateOption(SMSGHANDLER_PARAMS* pMsg);























extern int gnScreenWidth; // 0x0071146C



void __fastcall TEXT_PrintChatLine(const Unicode* pText, char nColor); // 0x0049E3A0


static void CHAT_CopyCharacterPart(const char* szSource, char* szDest)
{
    if (*szSource != 0x2A)
    {
        const char* p = SStrChr(szSource, 0x2A);
        if (p)
        {
            memcpy(szDest, szSource, p - szSource);
            szDest[p - szSource] = 0;
            return;
        }
        SStrCopy(szDest, szSource, 0x7FFFFFFF);
        return;
    }
    SStrCopy(szDest, szSource, 0x7FFFFFFF);
}

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700


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

// 0x0047BDF0
int __cdecl CHAT_HandleBnetChatMessage()
{
    D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
    if (!pNotify)
        return 0;

    int nResult;
    D2BnetChatPacketStrc tPacket;
    if (!pNotify->pfnGetMessage(&nResult, &tPacket))
        return 0;

    if (nResult == 0)
    {
        Unicode wszLine[0x154];
        Unicode wszText[0x154];
        Unicode wszOut[0x154];
        const int nType = tPacket.nType;
        const char* szSender = tPacket.szName;
        const char* szText = szSender + strlen(szSender) + 1;
        if (sub_00611560_GetSquelchList()->IsSquelched(szSender))
            return 1;
        if (sub_00611560_GetSquelchList()->IsFiltered(szText))
            return 1;

        switch (nType)
        {
        case 4:
        case 6:
        case 10:
        {
            char szName[0x154];
            char szFormatted[0x154];
            CHAT_CopyCharacterPart(szSender, szName);
            if (szName[0] && (szName[0] != 0x2A || strcmp(CHAT_GetAccountPart(szName), CHAT_GetAccountPart(szSender))))
                sprintf(szFormatted, gszNameAccountFormat, szName, CHAT_GetAccountPart(szSender));
            else
                sprintf(szFormatted, gszStringFormat, szName);
            sub_00526E40_Utf8ToUnicode(wszLine, szFormatted, 0x154);
            sub_00526E40_Utf8ToUnicode(wszText, szText, 0x154);
            wszLine[0x153].wChar = 0;
            wszText[0x153].wChar = 0;
            if (nType == 10)
                sub_005269D0_FormatText(0x153, wszOut, D2LANG_GetStringFromTblIndex(0x14D5), wszLine, wszText);
            else
                sub_005269D0_FormatText(0x153, wszOut, D2LANG_GetStringFromTblIndex(0x14D4), wszLine, wszText);
            wszOut[0x153].wChar = 0;
            TEXT_PrintChatLine(wszOut, 2);
            break;
        }
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 9:
        case 21:
        case 22:
        case 23:
            break;
        default:
        {
            char szPrefix[20];
            strcpy(szPrefix, "<BattleNet>: ");
            sub_00526E40_Utf8ToUnicode(wszLine, szPrefix, 0x154);
            sub_00526E40_Utf8ToUnicode(wszText, szText, 0x154);
            wszLine[0x153].wChar = 0;
            wszText[0x153].wChar = 0;
            if (UNICODE_StrLen(wszText) + UNICODE_StrLen(wszLine) >= 0x154)
            {
                const int nLength = UNICODE_StrLen(wszLine);
                if (nLength < 0x153)
                    wszText[0x153 - nLength].wChar = 0;
                else
                    wszText[0].wChar = 0;
            }
            sub_00526700(wszLine, wszText);
            wszLine[0x153].wChar = 0;
            TEXT_PrintChatLine(wszLine, 3);
            break;
        }
        }
    }
    return 1;
}


// 0x0047B4D0
void __cdecl sub_0047B4D0_Nop()
{
}

// 0x0047B4E0
void __cdecl sub_0047B4E0_Nop()
{
}



// 0x0047B9C0
void __cdecl CHAT_RecallChatLine()
{
    memcpy(gwszChatLine_007BB638, gawszChatHistory[gnChatHistoryCursor], sizeof(gawszChatHistory[0]));
    gnChatCaret = UNICODE_StrLen(gawszChatHistory[gnChatHistoryCursor]);
}

struct D2OptionHeaderStrc;

struct D2OptionEntryStrc;

struct D2EscMenuUIStateStrc;

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480






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



extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD




struct D2ChatMessageStrc
{
    unsigned char unk0x00;
    unsigned char nType;
    unsigned char unk0x02[6];
    unsigned char nColor;
    unsigned char unk0x09[0x11];
    D2ChatTextStrc tText;
};


extern "C" size_t __cdecl strlen(const char* sz);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB







int __stdcall CHAT_ParseChatCommand(char** ppText, char* pCode, char* szArgument);                  // 0x0047BAD0


Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700


void __fastcall TEXT_PrintChatLine(const Unicode* pText, char nColor);                              // 0x0049E3A0


D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(Unicode* pText, unsigned int* pLineCount, int nWidth);    // 0x00502970


extern unsigned short gwChatHistoryCount;                                                          // 0x007BB5E4

extern Unicode gawszChatHistory_007BB840[8][257];                                                           // 0x007BB840

// 0x0047B3B0
static int __stdcall CHAT_CompareCommand(const char* szText, const char* szCommand)
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

// 0x0047BA00
static void CHAT_PushChatHistory(const Unicode* pText)
{
    int nIndex;
    if (gwChatHistoryCount != 8)
    {
        if (gwChatHistoryCount)
        {
            if (--gnChatHistoryHead < 0)
                gnChatHistoryHead = 7;
        }
        nIndex = gnChatHistoryHead;
        ++gwChatHistoryCount;
    }
    else
    {
        nIndex = gnChatHistoryTail;
        gnChatHistoryHead = nIndex;
        if (--gnChatHistoryTail < 0)
            gnChatHistoryTail = 7;
    }
    gnChatHistoryCursor = nIndex;
    memcpy(gawszChatHistory_007BB840[nIndex], pText, sizeof(gawszChatHistory_007BB840[0]));
}

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))


extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330


extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0


D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

D2CelFileStrc* __cdecl UI_GetPentspinCel(); // 0x00453AA0

extern D2CelFileStrc* gpSliderDisabledCel; // 0x007BC950

extern D2CelFileStrc* gpSliderEnabledCel; // 0x007BC954

extern D2CelFileStrc* gpSliderKnobCel; // 0x007BC958

struct D2StoredUnitRecordStrc;


// 0x0047BD30
void __cdecl CHAT_ResetChatHistory()
{
    gnChatHistoryHead = 7;
    gnChatHistoryTail = 7;
    gnChatHistoryCursor = 0;
    gwChatHistoryCount = 0;
    gnChatCaret = 0;
}

// 0x0047BD80
static void CHAT_CopyCharacterPart(const char* szSource, char* szDest); // 0x0047BD80


// 0x0047C100
static int CHAT_HandleHelpCommand(char* szInput, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!CHAT_CompareCommand(szInput, szCommand))
    {
        const char c = szInput[nLength];
        if (c == 0x20 || !c)
        {
            char szDelim[] = " ";
            int nTokens = 0;
            if (strtok(szInput, szDelim))
            {
                do
                {
                    if (nTokens >= 2)
                    {
                        break;
                    }
                    nTokens += 1;
                }
                while (strtok(0, szDelim));
            }
            if (nTokens != 1)
            {
                D2ChatMessageStrc tMessage;
                tMessage.nType = 4;
                tMessage.nColor = 3;
                D2ChatTextStrc tBuffer;
                sprintf(tBuffer.sz, "<BattleNet>: Correct usage is: %s", szCommand);
                tMessage.tText = tBuffer;
                TEXT_HandleChatPacket(&tMessage);
                return 1;
            }
            D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
            if (pNotify)
                pNotify->pfnResign(szInput);
            return 1;
        }
    }
    return 0;
}


Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0



void __stdcall sub_0047E9A0_DrawSlots(int bDraw); // 0x0047E9A0



extern void* gpMiniPanelCel; // 0x007BC960











#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

// 0x0047BD00
bool __fastcall CHAT_IsNarrowText(const Unicode* pText)
{
    const int nLength = UNICODE_StrLen(pText);
    for (int i = 0; i < nLength; i++)
    {
        if (pText[nLength].wChar > 0xFF)
            return false;
    }
    return true;
}

// 0x0047C3F0
static void __stdcall CHAT_CopyCommandArgs(const char* szSource, char* szDest, unsigned int nSize)
{
    const char* pArgs = SStrChr(szSource, ' ');
    if (pArgs)
        SStrCopy(szDest, pArgs + 1, nSize);
    else
        *szDest = 0;
}

// 0x0047C1F0
static int __stdcall CHAT_HandleWhisperCommand(int bCheckStored, char* szInput, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!CHAT_CompareCommand(szInput, szCommand))
    {
        const char c = szInput[nLength];
        if (c == ' ' || !c)
        {
            D2ChatMessageStrc tMessage;
            char szName[0x100];
            char szMessage[0x100];
            {
                char szCopy[0x104];
                strcpy(szCopy, szInput);
                char* pToken = strtok(szInput, gszTokenSeparator);
                int nTokens = 0;
                for (; pToken; pToken = strtok(0, gszTokenSeparator))
                {
                    ++nTokens;
                    if (nTokens == 2)
                    {
                        strcpy(szName, pToken);
                    }
                    else if (nTokens == 3)
                    {
                        strcpy(szMessage, &szCopy[pToken - szInput]);
                        break;
                    }
                }
                if (nTokens != 3)
                {
                    tMessage.nType = 4;
                    tMessage.nColor = 3;
                    sprintf(szCopy, "<BattleNet>: Correct usage is: %s (name) (message)", szCommand);
                    memcpy(&tMessage.tText, szCopy, sizeof(tMessage.tText));
                    TEXT_HandleChatPacket(&tMessage);
                    return 1;
                }
            }
            if (bCheckStored)
            {
                for (D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0); pEntry; pEntry = ROSTER_GetNextStoredUnit(pEntry))
                {
                    if (!_stricmp(ROSTER_GetEntryName(pEntry), szName))
                    {
                        D2ChatSendStrc tSend;
                        strncpy(tSend.szText, szMessage, sizeof(tSend.szText) - 1);
                        tSend.szText[sizeof(tSend.szText) - 1] = 0;
                        strcpy(tSend.szArgument, szName);
                        tSend.nLang = gnLanguageId;
                        tSend.nCode = 2;
                        tSend.nType = 0x15;
                        MSG_SendStrings((const unsigned char*)&tSend);
                        return 1;
                    }
                }
            }
            sprintf(szInput, "%s %s %s", szCommand, szName, szMessage);
            D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
            if (pNotify)
                pNotify->pfnResign(szInput);
            return 1;
        }
    }
    return 0;
}

// 0x0047C420
static void __stdcall sub_0047C420_HandleChatCommand(const Unicode* pLine, char* szText, int nSkip)
{
    D2ChatSendStrc tSend;
    memset(tSend.szText, 0, sizeof(tSend.szText));
    tSend.nLang = gnLanguageId;
    char* pText = nSkip + szText;
    char* pCommand = pText;
    if (!_stricmp(pText, "/fps"))
    {
        sub_00477C60_CheckCacheStats();
        UI_SetUIVar(5, 1, 0);
        return;
    }
    if (!_stricmp(pText, "/framerate"))
    {
        VIEW_ToggleCacheStats();
        UI_SetUIVar(5, 1, 0);
        return;
    }
    if (!_strnicmp(pText, "/players", 8))
    {
        if (!GAME_GetConnectionType() || GAME_GetConnectionType() == 1 || GAME_GetConnectionType() == 6 || GAME_GetConnectionType() == 8)
        {
            int nPlayers = atoi(pText + 8);
            nPlayers = D2_MIN(D2_MAX(nPlayers, 1), 8);
            PLAYER_SetVirtualPlayerCount(nPlayers);
            sprintf(pText, "players set to %d", nPlayers);
        }
    }
    if (!_stricmp(pText, "/nopickup"))
    {
        gbNoPickup = !gbNoPickup;
    }
    else if (!_stricmp(pText, "soundchaosdebug"))
    {
        SOUNDINST_ToggleHints();
    }
    else
    {
        tSend.nCode = 1;
        tSend.nType = 0x15;
        tSend.nLang = gnLanguageId;
        if (!gbChatInputOpen || CHAT_IsNarrowText(pLine))
        {
            if (CHAT_ParseChatCommand(&pCommand, &tSend.nCode, tSend.szArgument) && !tSend.nCode)
                tSend.nType = 0x14;
            pText = pCommand;
        }
        if (!CHAT_CompareCommand(pText, "/ignorepersist"))
        {
            sub_00611560_GetSquelchList()->SetPersistent(!sub_00611560_GetSquelchList()->IsPersistent());
            Unicode wszText[0x104];
            sub_00526320_ToUnicode(wszText, gszBattleNetPrefix, 0x208);
            if (sub_00611560_GetSquelchList()->IsPersistent())
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA1));
            else
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA2));
            TEXT_PrintChatLine(wszText, 3);
        }
        else if (!CHAT_CompareCommand(pText, "/ignore ") || !CHAT_CompareCommand(pText, gszCmdSquelch))
        {
            Unicode wszText[0x208];
            Unicode wszLine[0x208];
            Unicode wszName[0x22];
            char szName[0x11];
            CHAT_CopyCommandArgs(pText, szName, sizeof(szName));
            if (SStrCmpI(&szName[1], gpClientConfig->szAccount, 0x7FFFFFFF))
            {
                sub_00526320_ToUnicode(wszLine, gszBattleNetPrefix, 0x208);
                sub_00526320_ToUnicode(wszName, szName, 0x22);
                if (sub_00611560_GetSquelchList()->Squelch(szName))
                    sub_005269D0_FormatText(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA3), wszName);
                else
                    sub_005269D0_FormatText(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA4), wszName);
                sub_00526700(wszLine, wszText);
            }
            TEXT_PrintChatLine(wszLine, 3);
        }
        else if (!CHAT_CompareCommand(pText, "/unignore ") || !CHAT_CompareCommand(pText, gszCmdUnsquelch))
        {
            Unicode wszText[0x208];
            Unicode wszLine[0x208];
            Unicode wszName[0x22];
            char szName[0x11];
            CHAT_CopyCommandArgs(pText, szName, sizeof(szName));
            sub_00526320_ToUnicode(wszLine, gszBattleNetPrefix, 0x208);
            sub_00526320_ToUnicode(wszName, szName, 0x22);
            if (sub_00611560_GetSquelchList()->Unsquelch(szName))
                sub_005269D0_FormatText(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA5), wszName);
            else
                sub_005269D0_FormatText(0x208, wszText, D2LANG_GetStringFromTblIndex(0x2BA6), wszName);
            sub_00526700(wszLine, wszText);
            TEXT_PrintChatLine(wszLine, 3);
        }
        else if (!CHAT_CompareCommand(pText, "/filtermsg "))
        {
            Unicode wszText[0x208];
            char szFilter[0x104];
            CHAT_CopyCommandArgs(pText, szFilter, sizeof(szFilter));
            sub_00526320_ToUnicode(wszText, gszBattleNetPrefix, 0x208);
            if (sub_00611560_GetSquelchList()->AddFilter(szFilter))
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA7));
            else
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA8));
            TEXT_PrintChatLine(wszText, 3);
        }
        else if (!CHAT_CompareCommand(pText, "/unfiltermsg "))
        {
            Unicode wszText[0x104];
            char szFilter[0x104];
            CHAT_CopyCommandArgs(pText, szFilter, sizeof(szFilter));
            sub_00526320_ToUnicode(wszText, gszBattleNetPrefix, 0x208);
            if (sub_00611560_GetSquelchList()->RemoveFilter(szFilter))
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BA9));
            else
                sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2BAA));
            TEXT_PrintChatLine(wszText, 3);
        }
        else if (tSend.nCode == 3 && (!gbChatInputOpen || CHAT_IsNarrowText(pLine)))
        {
            if (!CHAT_HandleWhisperCommand(1, pText, "/msg")
                && !CHAT_HandleWhisperCommand(1, pText, "/m")
                && !CHAT_HandleWhisperCommand(1, pText, "/whisper")
                && !CHAT_HandleWhisperCommand(1, pText, "/w")
                && !CHAT_HandleHelpCommand(pText, "/help")
                && !CHAT_HandleHelpCommand(pText, "/?"))
            {
                D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
                if (pNotify)
                    pNotify->pfnResign(pText);
            }
        }
        else if (UNICODE_StrLen(pLine) > 0)
        {
            memcpy(tSend.szText, pText, sizeof(tSend.szText) - 1);
            tSend.szText[sizeof(tSend.szText) - 1] = 0;
            MSG_SendStrings((const unsigned char*)&tSend);
        }
    }
    UI_SetUIVar(5, 1, 0);
}


// 0x0047BCA0
void __stdcall CHAT_HandleChatKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (pMsg->lParam & 0x40000000)
    {
        return;
    }
    int nKey = pMsg->wParam;
    switch (nKey)
    {
    case 0x26:
        CHAT_RecallChatLine();
        CHAT_StepChatIndex(1);
        break;
    case 0x28:
        CHAT_StepChatIndex(-1);
        CHAT_RecallChatLine();
        break;
    }
}

// 0x0047BDC0
void __cdecl CHAT_ClearChatLine()
{
    memset(gwszChatLine_007BB638, 0, 0x202);
    gnChatCaret = 0;
    gnChatDrawCount = 0;
}

// 0x0047CA70
void __stdcall CHAT_OnChatChar(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnChatDrawCount < 1)
        return;
    const int nLength = UNICODE_StrLen(gwszChatLine_007BB638);
    switch (pMsg->wParam)
    {
    case 8:
        if (gnChatCaret > 0)
        {
            --gnChatCaret;
            gwszChatLine_007BB638[gnChatCaret].wChar = 0;
        }
        break;
    case 0x1B:
        UI_SetUIVar(5, 1, 0);
        break;
    case 0xD:
    {
        int nSkip = 0;
        while (gwszChatLine_007BB638[nSkip].isWhitespace())
            ++nSkip;
        const Unicode* pText = &gwszChatLine_007BB638[nSkip];
        if (!UNICODE_StrLen(pText))
        {
            UI_SetUIVar(5, 1, 0);
            break;
        }
        CHAT_PushChatHistory(pText);
        char szText[0x104];
        WideCharToMultiByte(0, 0x250, (const wchar_t*)gwszChatLine_007BB638, -1, szText, 0x100, 0, 0);
        sub_0047C420_HandleChatCommand(gwszChatLine_007BB638, szText, nSkip);
        break;
    }
    default:
    {
        if (!gbChatInputOpen && !D2Win_10128(pMsg->wParam))
            break;
        if (gnChatCaret >= 0xFF || nLength >= 0xFF)
            break;
        const int nOldFont = D2Win_10127_SetFont(0xD);
        unsigned int nLines;
        D2SplittedTextStrc* pLines = D2WINFONT_SplitText(gwszChatLine_007BB638, &nLines, gnScreenWidth - 0x109);
        int nWidth = 0;
        for (D2SplittedTextStrc* pLine = pLines; pLine; )
        {
            D2SplittedTextStrc* pNext = pLine->pNextLine;
            nWidth = D2Win_10121_GetTextWidth(pLine->wszLine);
            pLine = pNext;
        }
        D2Win_10200(pLines);
        if (nLines <= 3 && (nLines != 3 || nWidth <= gnScreenWidth - 0x113))
        {
            gwszChatLine_007BB638[nLength].wChar = pMsg->wParam;
            pLines = D2WINFONT_SplitText(gwszChatLine_007BB638, &nLines, gnScreenWidth - 0x109);
            nWidth = 0;
            for (D2SplittedTextStrc* pLine = pLines; pLine; )
            {
                D2SplittedTextStrc* pNext = pLine->pNextLine;
                nWidth = D2Win_10121_GetTextWidth(pLine->wszLine);
                pLine = pNext;
            }
            D2Win_10200(pLines);
            if (nLines != 3 || nWidth < gnScreenWidth - 0x113)
                ++gnChatCaret;
        }
        D2Win_10127_SetFont(nOldFont);
        break;
    }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}






















































































// 0x004BF9C0
void __cdecl sub_004BF9C0_Nop()
{
}

extern const char gszM134CmdA[];

extern const char gszM134CmdB[];

void __stdcall sub_M134_Use(const char* szText);




extern "C" void __cdecl sub_0047CD80(); // 0x0047CD80
extern "C" char gData_006D7280[]; // 0x006D7280
extern "C" char gData_006D7284[]; // 0x006D7284

#pragma pack(push, 1)
struct d2data_00712F08_t
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

#pragma pack(push, 1)
struct d2data_00712F4C_t
{
    unsigned char b0[8];
    const void* p1;
    unsigned char b2[8];
    const void* p3;
    unsigned char b4[8];
    const void* p5;
    unsigned char b6[8];
    const void* p7;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00712FA8_t
{
    unsigned char b0[8];
    const void* p1;
    unsigned char b2[8];
    const void* p3;
    unsigned char b4[8];
    const void* p5;
    unsigned char b6[8];
    const void* p7;
    unsigned char b8[8];
    const void* p9;
    unsigned char b10[8];
    const void* p11;
    unsigned char b12[8];
    const void* p13;
};
#pragma pack(pop)

extern "C" struct d2data_00712F08_t gData_00712F08; // 0x00712F08
extern "C" struct d2data_00712F4C_t gData_00712F4C; // 0x00712F4C
extern "C" struct d2data_00712FA8_t gData_00712FA8; // 0x00712FA8
extern "C" char gData_00712FFC[4]; // 0x00712FFC

extern "C" struct d2data_00712F08_t gData_00712F08 = {
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
}; // 0x00712F08

extern "C" struct d2data_00712F4C_t gData_00712F4C = {
    { 0x00, 0x00, 0x00, 0x00, 0x02, 0x01 },
    (const void*)(unsigned int)&CHAT_OnChatChar,
    { 0x03, 0x00, 0x00, 0x00, 0x26 },
    (const void*)(unsigned int)&CHAT_HandleChatKeyDown,
    { 0x03, 0x00, 0x00, 0x00, 0x28 },
    (const void*)(unsigned int)&CHAT_HandleChatKeyDown,
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02 },
    (const void*)(unsigned int)&CHAT_CloseChatOnPanelClickMsg
}; // 0x00712F4C
#pragma comment(linker, "/alternatename:?gaChatHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_00712F4C")

extern "C" struct d2data_00712FA8_t gData_00712FA8 = {
    { 0x00, 0x00, 0x00, 0x00, 0x82, 0x02 },
    (const void*)(unsigned int)&CHAT_ImeNotifyMsg,
    { 0x00, 0x00, 0x00, 0x00, 0x0F, 0x01 },
    (const void*)(unsigned int)&CHAT_OnImeComposition,
    { 0x00, 0x00, 0x00, 0x00, 0x0D, 0x01 },
    (const void*)(unsigned int)&CHAT_HandleImeStartComposition,
    { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x01 },
    (const void*)(unsigned int)&CHAT_ResetImeCompositionMsg,
    { 0x00, 0x00, 0x00, 0x00, 0x84, 0x02 },
    (const void*)(unsigned int)&CHAT_SetMsgHandled,
    { 0x00, 0x00, 0x00, 0x00, 0x85, 0x02 },
    (const void*)(unsigned int)&CHAT_SetMsgHandled,
    { 0x00, 0x00, 0x00, 0x00, 0x83, 0x02 },
    (const void*)(unsigned int)&CHAT_SetMsgHandled
}; // 0x00712FA8
#pragma comment(linker, "/alternatename:?gaChatInputHandlers@@3PAUD2MsgHandlerEntryStrc@@A=_gData_00712FA8")

extern unsigned short gwBlinkDelay = 0x1F4; // 0x00713000

extern int gnBlinkOn = 1; // 0x00713004

extern int gnChatHistoryHead = 7; // 0x00712F44

extern int gnChatHistoryTail = 7; // 0x00712F48

extern D2ChatCommandStrc gaChatCommands[3] = {
    { (const char *)&gData_006D7284, 3 },
    { (const char *)&gData_006D7280, 0, 0, 1 },
    { (const char *)"@", 2, 1 }
}; // 0x00712F7C

extern "C" const char gszNameAccountFormat[12] = "%s (*%s)"; // 0x006D72C0

extern "C" char gData_00712FFC[4] = " "; // 0x00712FFC
#pragma comment(linker, "/alternatename:_gszTokenSeparator=_gData_00712FFC")

extern "C" const char gszBattleNetPrefix[14] = "<BattleNet>: "; // 0x006D72B0
