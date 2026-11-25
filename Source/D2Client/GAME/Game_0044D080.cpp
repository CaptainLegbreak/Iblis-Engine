#include "D2Client.h"
#include "D2StormTypes.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2LevelTxt.h"
#include "D2CelContext.h"
#include "D2MultiTypes.h"
#include "D2MsgRecord.h"
#include "D2ClientTimer.h"
#include "D2WinSplitText.h"

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

void __cdecl GAME_ResetLeftClick(); // 0x0044C060

void __cdecl SELECT_UnlockHover(); // 0x00466FF0

extern int gbStandStillHeld; // 0x007A0664

extern int gbRunKeyHeld; // 0x007A065C

static int gbRightButtonDown; // 0x007A0654

static int gbRightClickConsumed; // 0x007A0670

extern int gbClickHandled; // 0x007A0658

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct _RTL_CRITICAL_SECTION;

struct D2BetaScreenStrc;

struct Unicode;


#pragma pack(push, 1)

struct D2BetaScreenStrc
{
    unsigned long dwTick;
    D2CelFileStrc* pCelFile;
    unsigned char nAct;
    const char* szName;
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl strcmp(const char* s1, const char* s2);

extern int gnState_0070EF18; // 0x0070EF18

extern D2BetaScreenStrc gaBetaScreens[]; // 0x0070F238

extern int gnBetaScreenCount; // 0x0070F024

extern char gszServerIP_0070EF20[]; // 0x0070EF20

extern char gszMcpIP[]; // 0x0070F130

extern unsigned char gnCharClass; // 0x007A0522

void __fastcall WINMAIN_PushStateValue(int nValue); // 0x0044B440

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

int __fastcall D2Win_10177(unsigned char nAct); // 0x004FB480

void __cdecl VIEW_FreeLerpTables(); // 0x00475EF0

void __cdecl CURSOR_ShutdownCursor(); // 0x00468170

void __cdecl RECORD_FreeMsgRecordChunks(); // 0x00451850

void __cdecl ROSTER_FreeRosterLists(); // 0x004794B0

void __cdecl ROSTERPETS_FreeRosterPets(); // 0x00478A50

void __cdecl GAME_RegisterWindowHandlers(); // 0x00451F20

void __fastcall PLRSAVE_EnableSaveFileWriting(int nValue); // 0x00530F30

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

void __stdcall GAME_SetGlobalAct(int nAct); // 0x0052DFA0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

extern int gnScreenWidth; // 0x0071146C

extern "C" unsigned int __cdecl strlen(const char* s);

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION* pCriticalSection); // 0x006CC214

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

int __cdecl WINMAIN_PollMcpConnection(); // 0x00449B70

void __cdecl GAME_StartClick(); // 0x0044C000

void __cdecl GAME_StartRightClick(); // 0x0044C2C0

void __cdecl WINMAIN_DrainPacketQueues(); // 0x0044C6E0

void __cdecl GAME_UpdateGameState(); // 0x0044C790

int __fastcall sub_0044CCA0(unsigned int nFrames, unsigned int nRemainder, int nRate);

void __cdecl GAME_AverageFrameCounters(); // 0x0044CCE0

void __cdecl GAME_UpdateKeyState(); // 0x0044CE90

void __cdecl GAME_CheckConnectionTimeouts(); // 0x0044EEC0

void __cdecl RECORD_ReplayRecords(); // 0x004519C0

int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __cdecl PLAYER_ClearCommandPending(); // 0x00462920

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

void __cdecl SELECT_UpdateHoverUnit(); // 0x00467AC0

void __cdecl sub_00477DD0(); // 0x00477DD0

int __cdecl CHAT_HandleBnetChatMessage(); // 0x0047BDF0

void __fastcall WARDENCLIENT_TickModule(int nDelta); // 0x00480320

void __fastcall sub_00481600_RunPendingAction(D2UnitStrc* pPlayer); // 0x00481600

void __cdecl SOUNDHDR_TickSound(); // 0x00482C20

int __cdecl D2SOUND_IsStreamChannelPlaying(); // 0x00514840

void __cdecl D2SOUND_StopChannel(); // 0x00514930

void __fastcall D2SOUNDSMP_FadeOutMasterVolume(int nArg); // 0x00515F50

int __stdcall GAME_UpdateGamesProgress(int nArg); // 0x0052FC20

extern unsigned int gdwFrameTime; // 0x0070EF1C


extern _RTL_CRITICAL_SECTION gCriticalSection_007A0468; // 0x007A0468

extern unsigned int gdwLastCheck_007A04A0; // 0x007A04A0

extern unsigned int gdwFpsWindowStart; // 0x007A04B8

extern unsigned int gdwGlobal_007A04BC; // 0x007A04BC

extern int gbPositionalSound; // 0x007A061C

int gbLeavingGame; // 0x007A0620

extern int gnGlobal_007A0648; // 0x007A0648

extern int gnGlobal_007A0650; // 0x007A0650

extern int gnGlobal_007A0654; // 0x007A0654

unsigned char gnBetaScreenIndex; // 0x007A060D

char gszGameName[20]; // 0x007A05DC

unsigned short gwJoinId; // 0x007A0520

int gnServerHash; // 0x007A05C0

int gbExpansion; // 0x007A04F4

char gszClientCharName[4]; // 0x007A05C4

D2ClientCallbackFn gpfnClientCallback; // 0x007A0484

unsigned int gdwTickCount; // 0x007A048C

unsigned int gdwLastFrame; // 0x007A0490

int gnFrameCount; // 0x007A0494

unsigned int gdwNextKeepAliveTick; // 0x007A049C

int gnFramesPerSecond; // 0x007A04A8

int gnFpsFrameCount; // 0x007A04AC

int gnSkippedFrames; // 0x007A04B0

int gnFpsSkipCount; // 0x007A04B4

void* ghQServerThread; // 0x007A05BC

int gnGameType; // 0x007A0610

int gnSkipped; // 0x007A0704

struct D2ActInfoStrc;

struct D2RectStrc;


struct D2PongDataStrc;

struct D2GSPacketSrv8F;

struct D2MsgHandlerEntryStrc;

struct D2ChatStormLinkStrc;

struct D2ChatStormLinkAStrc;

struct D2ChatStormLinkBStrc;

struct D2ChatStormNodeStrc;

struct D2ChatStormBaseArrayAStrc;

struct D2ChatStormBaseArrayBStrc;

struct D2ChatStormListAStrc;

struct D2ChatStormListBStrc;

struct D2ChatStormHashTableStrc;

struct D2ChatStormCtorLinkStrc;

struct D2ChatStormListCStrc;

struct D2ChatStormListDStrc;

struct D2ChatStormListEStrc;

struct D2CommonStormSlotLinkStrc;

struct D2CommonStormSlotListAStrc;

struct D2CommonStormSlotListBStrc;

struct D2CommonMappingEntryNodeBaseStrc;

struct D2CommonMappingEntryNodeStrc;

struct D2CommonStringEntryNodeStrc;

struct D2CommonStormHashTableAStrc;

struct D2LoadingTimerStrc;

extern int gnLastViewX; // 0x0070F55C

extern int gnLastViewY; // 0x0070F558

extern int gnViewDeltaX; // 0x007A0678

extern int gnViewDeltaY; // 0x007A067C

extern void* gpGlobal_007A0634; // 0x007A0634

void __fastcall UI_FreeLoadingScreen(); // 0x004547B0

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

void __fastcall VIEW_AdjustViewPos(int* pX, int* pY); // 0x00476D40

void __fastcall VIEW_SetViewPos(D2ViewStrc* pView, int nX, int nY); // 0x004760A0

void __fastcall VIEW_PrepareView(D2ViewStrc* pView, int nArg); // 0x00476140

void __cdecl sub_00473F50_UpdateWeather(); // 0x00473F50

void __stdcall ENVIRONMENT_GetLightColorFromAct(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0

void __stdcall D2GFX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x004F6430

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __cdecl AUTOMAP_UpdateAutomapOrigin(); // 0x0045B440

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall VIEW_PrepareSceneLighting(D2ViewStrc* pView); // 0x00476BC0

void __fastcall UI_DrawUIPanels(D2ViewStrc* pView); // 0x00456EE0

void __stdcall D2Win_UpdateAndDraw(); // 0x004F98E0

void __fastcall sub_00468820(int nArg1, int nArg2); // 0x00468820

void __cdecl CURSOR_DrawCursor(); // 0x004684C0

void __fastcall sub_00477980(); // 0x00477980

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

#pragma pack(push, 1)

struct D2ClientNotifyStrc;

#pragma pack(pop)

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

extern unsigned short gawLoadingStrings[]; // 0x0070F384

int gnLoadingIndex; // 0x007A05D4


extern int gnAutomapWidth; // 0x007A5220


struct D2PongDataStrc
{
    unsigned long dwData0;
    unsigned long dwData1;
    unsigned long dwData2;
    unsigned long dwData3;
    unsigned long dwTick;
    unsigned long dwData5;
    unsigned long dwData6;
    unsigned long dwData7;
};

#pragma pack(push, 1)

struct D2GSPacketSrv8F
{
    unsigned char nHeader;
    D2PongDataStrc tData;
};

#pragma pack(pop)

extern D2PongDataStrc gtPongData; // 0x007A04D4

typedef char D2MsgHandlerEntrySize[(sizeof(D2MsgHandlerEntryStrc) == 12) ? 1 : -1];

extern "C" D2MsgHandlerEntryStrc gaGameWheelHandlers[1]; // 0x0070F2C4

extern "C" D2MsgHandlerEntryStrc gaMiddleButtonHandlers[2]; // 0x0070F348

extern "C" D2MsgHandlerEntryStrc gaXButtonHandlers[2]; // 0x0070F360

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern "C" void __fastcall SCMD_RegisterMsgHandlers(int hwnd, D2MsgHandlerEntryStrc* table, unsigned int count); // 0x00451DB0

extern "C" void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

extern "C" const char gszIgnoreListSourceFile_006E6290[];


extern int gdwUnloadCompleteTick; // 0x007A0524

extern int gbGameServerReady; // 0x007A0618

extern int gnCinematicPlayed; // 0x007A062C

extern D2LoadingTimerStrc gtLoadingTimer_007A0684; // 0x007A0684

void __cdecl GAME_DrawLoadingText(); // 0x0044CB60

int __fastcall GAME_IsTimerRunning(D2LoadingTimerStrc* pTimer); // 0x0044E040

D2ViewStrc* gpClientView; // 0x007A0640

static int gbEndScreenDismissed; // 0x007A0608

static int gbLeftButtonDown; // 0x007A0650

static int gbLeftClickRepeating; // 0x007A066C

static int gbEndScreenButtonPressed; // 0x007A0680

unsigned long gdwLastPingTick; // 0x007A04A0

unsigned long gdwPing; // 0x007A04A4

unsigned long gdwPingSamples; // 0x007A04CC

unsigned long gdwPingAverage; // 0x007A04D0

int gdwGameStartTick; // 0x007A05F8

int gnDifficultyDirty; // 0x007A0604

int gbActUnloaded; // 0x007A0624

// 0x0044C5E0
void __stdcall GAME_HandleActivateApp(SMSGHANDLER_PARAMS* pMessage)
{
// build: symbol ?gbClientAppActive@* 0x0070F7E0
    gbClientAppActive = pMessage->wParam;
    if (pMessage->wParam)
    {
        UI_SetUIVar(0xD, 1, 0);
        gbStandStillHeld = 0;
        SELECT_ClearSelection();
// build: symbol ?D2Win_10176_StartPaletteFlash@* 0x004FB130
        D2Win_10176_StartPaletteFlash(0);
        pMessage->bReturn = 0;
        return;
    }

    if (CUNIT_HasHotkeyBinding(0x22, 1) && (static_cast<unsigned short>(GetAsyncKeyState(CUNIT_GetHotkeyBinding(0x22, 1))) & 0x8000) == 0)
    {
        gbRunKeyHeld = 0;
    }

// build: symbol ?gnLeftClickState@* 0x0070F234
    if (gnLeftClickState != 0x10)
    {
        GAME_ResetLeftClick();
    }

// build: symbol ?gnRightClickState@* 0x0070F2BC
    if (gnRightClickState != 0x10)
    {
        gnRightClickState = 0x10;
        gbRightButtonDown = 0;
        gbRightClickConsumed = 1;
        gbClickHandled = 0;
        SELECT_UnlockHover();
        pMessage->bReturn = 0;
        return;
    }

    pMessage->bReturn = 0;
}

static int GetRoomBlankScreen(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    D2LevelsTxt* pTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pTxt, 1502);
    return pTxt->dwBlankScreen;
}

// 0x0044C990
void __fastcall GAME_DrawGameView(int bNoCursor)
{
    UI_FreeLoadingScreen();
    if (WINDOW_GetState())
        return;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2RectStrc tRect;
    sub_00476070_GetViewRect(gpClientView, &tRect.nLeft, &tRect.nTop, &tRect.nRight, &tRect.nBottom);
    int nY;
    int nX;
    nX = UNITS_GetClientCoordX(pPlayer) - (tRect.nRight - tRect.nLeft) / 2;
    nY = UNITS_GetClientCoordY(pPlayer) - (tRect.nBottom - tRect.nTop) / 2;
    VIEW_AdjustViewPos(&nX, &nY);
    if (gnLastViewX != -1 || gnLastViewY != -1)
    {
        gnViewDeltaX = nX - gnLastViewX;
        gnViewDeltaY = nY - gnLastViewY;
    }
    gnLastViewX = nX;
    gnLastViewY = nY;
    VIEW_SetViewPos(gpClientView, nX, nY);
    VIEW_PrepareView(gpClientView, 0);
    sub_00473F50_UpdateWeather();

    unsigned char nRed, nGreen, nBlue;
    ENVIRONMENT_GetLightColorFromAct(gpGlobal_007A0634, &nRed, &nGreen, &nBlue);
    D2GFX_SetAmbientColor(nRed, nGreen, nBlue);

    if (!D2GFX_StartDraw(GetRoomBlankScreen(CUNIT_GetPlayerRoom()), 0, 0, 0))
        return;

// build: symbol ?D2Win_10179_UpdatePaletteFlash@* 0x004FB0D0
    D2Win_10179_UpdatePaletteFlash();
    AUTOMAP_UpdateAutomapOrigin();
    if (sub_0045AE90() != 3)
        VIEW_PrepareSceneLighting(gpClientView);
    UI_DrawUIPanels(gpClientView);
    D2Win_UpdateAndDraw();
    sub_00468820(10, 10);
    if (!bNoCursor)
        CURSOR_DrawCursor();
    sub_00477980();
// build: symbol ?gnClearScreenCount@* 0x0070F2C0
    if (gnClearScreenCount)
    {
        D2GFX_ClearScreen(0);
        if (--gnClearScreenCount < 0)
            gnClearScreenCount = 0;
    }
    D2GFX_EndScene();
}

// 0x0044CB60
void __cdecl GAME_DrawLoadingText()
{
    if (WINDOW_GetState())
    {
        return;
    }
    if (!D2GFX_StartDraw(1, 0, 0, 0))
    {
        return;
    }
    D2GFX_ClearScreen(0);
    D2Win_10127_SetFont(3);
    const Unicode* pText = D2LANG_GetStringFromTblIndex(gawLoadingStrings[gnLoadingIndex]);
    if (gpClientConfig->aFlags1EF[0] & 0x20)
    {
        if (gnLoadingIndex == 0x14)
        {
            pText = D2LANG_GetStringFromTblIndex(0x5522);
        }
        else if (gnLoadingIndex == 0x15)
        {
            pText = D2LANG_GetStringFromTblIndex(0x5521);
        }
    }
    const int nWidth = D2Win_10121_GetTextWidth(pText);
    if (nWidth < gnAutomapWidth - 0x28)
    {
        D2Win_10117_DrawText(pText, (gnAutomapWidth - nWidth) >> 1, 0xC8, 0, 0);
    }
    else
    {
        D2Win_10127_SetFont(2);
        int nLines;
        D2SplittedTextStrc* pLines = D2WINFONT_SplitText(pText, &nLines, 0x258);
        D2SplittedTextStrc* pLine = pLines;
        for (unsigned int i = 0; i < nLines; ++i)
        {
            const int nX = (gnAutomapWidth - D2Win_10121_GetTextWidth(pLine->wszLine)) >> 1;
            D2Win_10117_DrawText(pLine->wszLine, nX, 2 * (D2Win_10125() * i) + 0xC8, 0, 0);
            pLine = pLine->pNextLine;
        }
// build: symbol ?D2Win_10200@* 0x005028A0
        D2Win_10200(pLines);
    }
    D2Win_UpdateAndDraw();
    D2GFX_EndScene();
}

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

struct D2LaunchMsgStrc;


struct D2MsgRecordStrc;

struct D2MsgRecordChunkStrc;



struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };

// 0x0044CCA0
int __fastcall GAME_CountLevelThresholds(int nValue, int nUnused, int nLimit)
{
    int nCount = 0;
    if (nLimit < 7)
        nCount = 1;
    if (nValue > 1)
        nCount++;
    if (nValue > 9)
        nCount++;
    if (nValue > 0x13)
        nCount++;
    if (nValue > 0x1D)
        nCount++;
    return nCount;
}

// 0x0044CDB0
void __fastcall GAME_StorePong(const D2GSPacketSrv8F* pPacket)
{
    gtPongData.dwData0 = pPacket->tData.dwData0;
    gtPongData.dwData1 = pPacket->tData.dwData1;
    gtPongData.dwData2 = pPacket->tData.dwData2;
    gtPongData.dwData3 = pPacket->tData.dwData3;
    gtPongData.dwTick = pPacket->tData.dwTick;
    gtPongData.dwData5 = pPacket->tData.dwData5;
    gtPongData.dwData6 = pPacket->tData.dwData6;
    gtPongData.dwData7 = pPacket->tData.dwData7;
    gtPongData.dwTick = GetTickCount();
    unsigned long dwPing = GetTickCount() - gdwLastPingTick;
    gdwPing = dwPing;
    if (gdwPingSamples < 10)
    {
        dwPing += gdwPingAverage * gdwPingSamples;
        ++gdwPingSamples;
        gdwPingAverage = dwPing / gdwPingSamples;
    }
}

// 0x0044D080
int __cdecl GAME_PushState()
{
    if (gnState_0070EF18 == 5)
        WINMAIN_PushStateValue(gnState_0070EF18 - 3);
    return gnState_0070EF18;
}

// 0x0044D100
int __stdcall GAME_ShowBetaScreens(int nArg)
{
    char szPath[0x104];
    D2CelContextStrc tData;
    if (!WINDOW_GetState())
    {
        if (!D2GFX_StartDraw(1, 0, 0, 0))
            return 0;
        if (gnBetaScreenIndex < gnBetaScreenCount)
        {
            if (!gaBetaScreens[gnBetaScreenIndex].pCelFile)
            {
// build: symbol ?gszDataGlobal@* 0x006D4118
                wsprintfA(szPath, "%s\\ui\\betascreens\\%s", gszDataGlobal, gaBetaScreens[gnBetaScreenIndex].szName);
                gaBetaScreens[gnBetaScreenIndex].pCelFile = ARCHIVE_LoadClientCellFile(szPath, 0);
                gaBetaScreens[gnBetaScreenIndex].dwTick = GetTickCount();
                D2Win_10177(gaBetaScreens[gnBetaScreenIndex].nAct);
            }
            memset(&tData, 0, sizeof(tData));
            tData.pCellFile = gaBetaScreens[gnBetaScreenIndex].pCelFile;
            tData.nDirection = 0;
            tData.nFrame = 0;
            TEXTURE_CelDraw(&tData, 0, 0x100, -1, 5, 0);
            tData.nFrame = 1;
            TEXTURE_CelDraw(&tData, 0x100, 0x100, -1, 5, 0);
            tData.nFrame = 2;
            TEXTURE_CelDraw(&tData, 0x200, 0x100, -1, 5, 0);
            tData.nFrame = 3;
            TEXTURE_CelDraw(&tData, 0, 0x1E0, -1, 5, 0);
            tData.nFrame = 4;
            TEXTURE_CelDraw(&tData, 0x100, 0x1E0, -1, 5, 0);
            tData.nFrame = 5;
            TEXTURE_CelDraw(&tData, 0x200, 0x1E0, -1, 5, 0);
        }
        D2GFX_EndScene();
    }
    if (gnBetaScreenIndex >= gnBetaScreenCount || GetTickCount() > gaBetaScreens[gnBetaScreenIndex].dwTick + 10000)
    {
        gnBetaScreenIndex += 1;
        if (gnBetaScreenIndex >= gnBetaScreenCount)
        {
            for (int i = 0; i < gnBetaScreenCount; i += 1)
            {
                if (gaBetaScreens[i].pCelFile)
                {
                    ARCHIVE_FreeClientCellFile(gaBetaScreens[i].pCelFile);
                    gaBetaScreens[i].pCelFile = 0;
                    gaBetaScreens[i].dwTick = 0;
                }
            }
            WINMAIN_SetExitApplication(0);
            return 1;
        }
    }
    return 0;
}

struct D2ActiveRoomStrc;

// 0x0044D390
int __fastcall GAME_GetCenteredTextX(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - D2Win_10121_GetTextWidth(wszText) / 2;
}

// 0x0044D3E0
void __cdecl GAME_DrawEndGameTitle()
{
    int nX = GAME_GetCenteredTextX(0x13EA, gnScreenWidth / 2);
    int nY = 0x3E;
    if (gbExpansion)
        nY = 0x64;
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x13EA), nX, nY, 4, 0);
    if (!gbExpansion)
    {
        nX = GAME_GetCenteredTextX(0x13EB, gnScreenWidth / 2);
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x13EB), nX, 0x6B, 4, 0);
    }
    nY = 0xE8;
    if (gbExpansion)
        nY = 0x110;
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x13EC), GAME_GetCenteredTextX(0x13EC, gnScreenWidth / 2), nY, 4, 0);
}

// 0x0044D550
int __cdecl GAME_ShutdownClient()
{
    VIEW_FreeLerpTables();
    CURSOR_ShutdownCursor();
    RECORD_FreeMsgRecordChunks();
    ROSTER_FreeRosterLists();
    ROSTERPETS_FreeRosterPets();
    GAME_RegisterWindowHandlers();
    return 1;
}

// 0x0044D580
void __fastcall GAME_ApplyConfigNoSave(D2ConfigStrc* pConfig)
{
    if (pConfig->bFlag219)
        PLRSAVE_EnableSaveFileWriting(0);
}

// 0x0044D5A0
void __fastcall GAME_ApplyConfigAct(D2ConfigStrc* pConfig)
{
    if (pConfig->dwAct)
    {
        D2_ASSERT(pConfig->dwAct < 6, 3366);
        D2_ASSERT(pConfig->dwAct > 0, 3367);
        GAME_SetGlobalAct(pConfig->dwAct - 1);
    }
}

// 0x0044D5F0
void __fastcall GAME_ApplyConfigGame(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szServerIP, "0"))
        SStrCopy(gszServerIP_0070EF20, pConfig->szServerIP, 0x7FFFFFFF);
    SStrCopy(gszGameName, pConfig->szGameName, 0x7FFFFFFF);
    gdwGlobal_007A0610 = pConfig->dwGameType;
    gwJoinId = pConfig->wJoinID;
    gnServerHash = pConfig->dwGameHash;
}

// 0x0044D650
void __fastcall GAME_ApplyConfigBattleNetIP(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szBattleNetIP, "0"))
// build: symbol ?gszBattleNetIP@* 0x0070F028
        SStrCopy(gszBattleNetIP, pConfig->szServerIP, 0x7FFFFFFF);
}

// 0x0044D680
void __fastcall GAME_ApplyConfigMcpIP(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szMCPIP, "0"))
        SStrCopy(gszMcpIP, pConfig->szMCPIP, 0x7FFFFFFF);
}

// 0x0044D6B0
void __fastcall GAME_ApplyConfigClass(D2ConfigStrc* pConfig)
{
    if (pConfig->bAmazon) gnCharClass = 0;
    if (pConfig->bPaladin) gnCharClass = 3;
    if (pConfig->bSorceress) gnCharClass = 1;
    if (pConfig->bNecromancer) gnCharClass = 2;
    if (pConfig->bBarbarian) gnCharClass = 4;
    if (pConfig->bDruid) gnCharClass = 5;
    if (pConfig->bAssassin) gnCharClass = 6;
}

// 0x0044D890
void __fastcall GAME_ApplyConfigName(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szCharName, "0"))
    {
        int nLength = strlen(pConfig->szCharName);
        memset(gszClientCharName, 0, 0x10);
        ++nLength;
        if (nLength > 0x10)
        {
            nLength = 0x10;
        }
        strncpy(gszClientCharName, pConfig->szCharName, nLength);
    }
}

// 0x0044DCE0
extern "C" void __cdecl GAME_UnregisterMouseHandlers()
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaGameWheelHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaMiddleButtonHandlers, 2);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaXButtonHandlers, 2);
}

// 0x0044DD20
extern "C" void __cdecl GAME_RegisterMouseHandlers()
{
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaGameWheelHandlers, 1);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaMiddleButtonHandlers, 2);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaXButtonHandlers, 2);
}

bool D2ChatStormLinkStrc::IGNORELIST_IsLinkLinked()
{
    return m_next != 0;
}

char* D2ChatStormLinkStrc::sub_0060E1A0_Next()
{
    return MaskNext();
}

char* D2ChatStormLinkStrc::sub_0060E240_Next()
{
    return MaskNext();
}

void D2ChatStormLinkStrc::sub_0060E3B0_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E400_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E690_Unlink()
{
    Unlink();
}

void D2ChatStormLinkStrc::sub_0060E760_Unlink()
{
    Unlink();
}

D2ChatStormLinkAStrc::D2ChatStormLinkAStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

D2ChatStormLinkBStrc::D2ChatStormLinkBStrc()
{
    m_prevlink = 0;
    m_next = 0;
}

char* D2ChatStormNodeStrc::IGNORELIST_GetStringEntryKey()
{
    return m_key;
}

D2ChatStormBaseArrayAStrc::D2ChatStormBaseArrayAStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayAStrc::IGNORELIST_GetStringSlotArrayCount()
{
    return m_count;
}

D2ChatStormBaseArrayBStrc::D2ChatStormBaseArrayBStrc()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
}

unsigned int D2ChatStormBaseArrayBStrc::IGNORELIST_GetMappingSlotArrayCount()
{
    return m_count;
}

void D2ChatStormListAStrc::IGNORELIST_InitStringListTerminator()
{
    InitializeTerminator();
}

void D2ChatStormListBStrc::IGNORELIST_InitMappingListTerminator()
{
    InitializeTerminator();
}

char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

void D2ChatStormListBStrc::IGNORELIST_ResetMappingList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0044DEF0
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* __fastcall sub_0060E360_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

char* D2ChatStormHashTableStrc::IGNORELIST_GetStringTableHead()
{
    return m_fulllist.m_terminator.MaskNext();
}

D2ChatStormListCStrc::D2ChatStormListCStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListDStrc::D2ChatStormListDStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2ChatStormListEStrc::D2ChatStormListEStrc()
{
    m_linkoffset = 0xDDDDDDDD;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

D2CommonStormSlotListAStrc::~D2CommonStormSlotListAStrc()
{
    UnlinkAll();
}

D2CommonStormSlotListBStrc::~D2CommonStormSlotListBStrc()
{
    UnlinkAll();
}

D2CommonMappingEntryNodeStrc::~D2CommonMappingEntryNodeStrc()
{
    if (pMapped)
        SMemFree(pMapped, gszIgnoreListSourceFile_006E6290, 0x11, 0);
}

void D2CommonStringEntryNodeStrc::IGNORELIST_DestroyStringEntryNode()
{
    this->~D2CommonStringEntryNodeStrc();
}

void D2CommonStormHashTableAStrc::IGNORELIST_ClearStringTable()
{
    IGNORELIST_InternalClearStringTable(0);
}

// build: symbol ?GAME_IsTimerExpired@* 0x0044DFF0
int __fastcall GAME_IsTimerExpired(D2LoadingTimerStrc* pTimer)
{
    if (pTimer->dwLength)
    {
        unsigned long dwNow = GetTickCount();
        unsigned long dwLeft;
        if (dwNow >= pTimer->dwStart + pTimer->dwLength)
        {
            pTimer->dwStart = 0;
            pTimer->dwLength = 0;
            dwLeft = 0;
        }
        else
        {
            dwLeft = pTimer->dwLength - (dwNow - pTimer->dwStart);
        }
        return dwLeft == 0;
    }
    return 1;
}

// 0x0044E380
void __fastcall GAME_ShowLoadingMessage(int nIndex)
{
    if (GAME_IsTimerRunning(&gtLoadingTimer_007A0684))
    {
        return;
    }

    if (gnDifficultyDirty)
    {
        return;
    }

    if (gnCinematicPlayed)
    {
        return;
    }

    gnLoadingIndex = nIndex;
    if (nIndex >= 29)
    {
        gnLoadingIndex = 9;
    }

    UI_CloseUIVars(1, 0);
    gtLoadingTimer_007A0684.dwStart = GetTickCount();
    gtLoadingTimer_007A0684.dwLength = 2500;
    gbLeavingGame = 1;
    gbPositionalSound = 0;
    gbGameServerReady = 0;
    WINMAIN_SetExitApplication(0);
}

// 0x0044E400
int __stdcall GAME_LoadingTimerCallback(void* pArg)
{
    int bResult = 0;
    if (GAME_IsTimerExpired(&gtLoadingTimer_007A0684))
    {
        UI_FreeLoadingScreen();
        bResult = 1;
    }
    else
    {
        GAME_DrawLoadingText();
    }
    return bResult;
}

// 0x0044E460
void __stdcall GAME_HandleEndScreenButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nBottom = gnScreenHeight - 0x50;
    int nLeft = gnScreenWidth / 2 - 0x30;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gbEndScreenButtonPressed = 1;
        gbLeftButtonDown = 0;
        gbRightButtonDown = 0;
        gbLeftClickRepeating = 0;
        gbRightClickConsumed = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    gbLeftButtonDown = 0;
    gbRightButtonDown = 0;
    gbLeftClickRepeating = 0;
    gbRightClickConsumed = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044E4F0
void __stdcall GAME_HandleEndScreenButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    gbEndScreenButtonPressed = 0;
    const int nBottom = gnScreenHeight - 0x50;
    int nLeft = gnScreenWidth / 2 - 0x30;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gbEndScreenDismissed = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gbLeftButtonDown = 0;
    gbRightButtonDown = 0;
    gbLeftClickRepeating = 0;
    gbRightClickConsumed = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044ED10
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

// 0x0044EE70
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0044EEC0
void __cdecl GAME_CheckConnectionTimeouts()
{
    if (!gdwGlobal_007A0610 || gdwGlobal_007A0610 == 1)
    {
        return;
    }

    unsigned long dwNow = GetTickCount();
    if (!sub_0052A640_IsConnected() && !gbLeavingGame && gbPositionalSound)
    {
        GAME_ShowLoadingMessage(7);
    }

    if (gbActUnloaded && dwNow - gdwUnloadCompleteTick > 300000)
    {
        GAME_ShowLoadingMessage(7);
    }

    if (dwNow - gdwGameStartTick > 30000 && !gbPositionalSound && !gbLeavingGame && !gbActUnloaded)
    {
        GAME_ShowLoadingMessage(6);
    }

    if (!gbGameServerReady && !gbPositionalSound && !gbLeavingGame && !gbActUnloaded
        && (gdwGlobal_007A0610 == 9 || gdwGlobal_007A0610 == 7))
    {
        GAME_ShowLoadingMessage(6);
    }
}

int __fastcall sub_0044CCA0(unsigned int nValue, unsigned int nUnused, int nLimit)
{
    int nCount = 0;
    if (nLimit < 7)
        nCount = 1;
    if ((int)nValue > 1)
        nCount++;
    if ((int)nValue > 9)
        nCount++;
    if ((int)nValue > 0x13)
        nCount++;
    if ((int)nValue > 0x1D)
        nCount++;
    return nCount;
}

// 0x0044EFA0
int __stdcall GAME_RunGameFrame(int nUnused)
{
    int bFrame = 0;
    int bDrawn = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (gnGameType == 0 || gnGameType == 1)
    {
        if (WINDOW_GetState())
        {
            gdwLastFrame = GetTickCount();
            return 0;
        }

        if ((UI_GetUIVarUnchecked(9) || UI_GetUIVarUnchecked(11)) && pPlayer && CUNIT_GetPlayerRoom())
        {
            gdwLastFrame = GetTickCount();
            gpfnClientCallback(0);
            SOUNDHDR_TickSound();
            return 0;
        }
    }

    RECORD_ReplayRecords();
    if (gnGlobal_007A0650)
    {
        GAME_StartClick();
    }

    if (gnGlobal_007A0654)
    {
        GAME_StartRightClick();
    }

    GAME_UpdateKeyState();

    unsigned int dwNow = GetTickCount();
    if (gdwNextKeepAliveTick < dwNow)
    {
        sub_00477DD0();
        gdwLastCheck_007A04A0 = dwNow;
        if (gpClientConfig->aFlags1EF[0] & 4)
        {
            gdwNextKeepAliveTick = dwNow + 5000;
        }
        else
        {
            gdwNextKeepAliveTick = dwNow + 5000;
        }
    }

    gdwTickCount = GetTickCount();
    if (!gdwLastFrame)
    {
        gdwLastFrame = gdwTickCount - gdwFrameTime;
    }

    WARDENCLIENT_TickModule(gdwLastFrame - gdwTickCount);
    GAME_AverageFrameCounters();

    unsigned int nElapsed = gdwTickCount - gdwLastFrame;
    if (nElapsed >= gdwFrameTime)
    {
        gdwLastFrame = gdwTickCount;
        bFrame = 1;
        if (gdwTickCount < gdwGlobal_007A04BC)
        {
            nElapsed -= gdwFrameTime;
            unsigned int nLate = gdwFrameTime - 1;
            if (nElapsed < nLate)
            {
                nLate = nElapsed;
            }

            gdwLastFrame = gdwTickCount - nLate;
            gnSkipped = 0;
            nElapsed = gdwFrameTime;
            gdwFpsWindowStart = gdwTickCount;
            gnFramesPerSecond = 25;
            gnSkippedFrames = 0;
            gnFpsFrameCount = 0;
            gnFpsSkipCount = 0;
        }

        if (gbPositionalSound)
        {
            sub_00481600_RunPendingAction(pPlayer);
        }
    }

    int bReady = 0;
    if (gnGameType == 0)
    {
        sub_0052CFE0();
        bReady = GAME_UpdateGamesProgress(1);
        if (bReady)
        {
            sub_0052FD90(1, 0);
        }
    }
    else if (gnGameType == 1)
    {
        sub_0052CFE0();
        bReady = GAME_UpdateGamesProgress(1);
        sub_0052FD90(0, 0);
    }

    WINMAIN_DrainPacketQueues();
    CHAT_HandleBnetChatMessage();
    WINMAIN_PollMcpConnection();
    GAME_CheckConnectionTimeouts();

    if (gbPositionalSound)
    {
        if (gnGameType != 0 && gnGameType != 1)
        {
            if (bFrame)
            {
                GAME_UpdateGameState();
                gdwLastFrame += gdwFrameTime - nElapsed;
                bDrawn = 1;
                const int nRate = gnFramesPerSecond;
                const unsigned int nFrames = nElapsed / gdwFrameTime;
                const unsigned int nRest = nElapsed % gdwFrameTime;
                int nLimit = sub_0044CCA0(nFrames, nRest, nRate);
                if (nRate > 28)
                {
                    nLimit = 0;
                }

                if (gnSkipped > nLimit)
                {
                    gnSkipped = 0;
                }
            }
            else if (gnFramesPerSecond > 22)
            {
                gnSkipped = 0;
            }
        }
        else if (bReady)
        {
            GAME_UpdateGameState();
            bDrawn = 1;
            if (nElapsed <= gdwFrameTime)
            {
                gnSkipped = 0;
            }
            else if (nElapsed < 2 * gdwFrameTime)
            {
                gdwLastFrame += gdwFrameTime - nElapsed;
                gnSkipped = 0;
            }
            else
            {
                gnSkipped = gnSkipped <= 1;
                gdwLastFrame += 1 - gdwFrameTime;
            }
        }
    }

    if (gbPositionalSound)
    {
        PLAYER_ClearCommandPending();
        SELECT_UpdateHoverUnit();
        if (D2SOUND_IsStreamChannelPlaying())
        {
            D2SOUNDSMP_FadeOutMasterVolume(0xB4);
            D2SOUND_StopChannel();
// build: symbol ?D2SOUNDSMP_SetMasterVolume@* 0x00515CE0
            D2SOUNDSMP_SetMasterVolume(0xFF);
        }

        if (!gnSkipped)
        {
            if (CUNIT_GetPlayerRoom())
            {
                gpfnClientCallback(0);
                ++gnFrameCount;
                ++gnFpsFrameCount;
            }
        }
        else if (bFrame)
        {
            ++gnFpsSkipCount;
        }

        if (bDrawn)
        {
            SOUNDHDR_TickSound();
        }

        ++gnSkipped;
    }
    else
    {
        WINDOW_GetState();
    }

    if (!gbLeavingGame)
    {
        return 0;
    }

    sub_00480340();
    sub_004FB480_SetActA(0);
    UI_CloseUIVars(1, 0);
    if (gnGameType == 0 || gnGameType == 1)
    {
        sub_0052E9C0();
    }

    if (gnGameType == 6 || gnGameType == 8)
    {
        EnterCriticalSection(&gCriticalSection_007A0468);
        gnGlobal_007A0648 = 1;
        LeaveCriticalSection(&gCriticalSection_007A0468);
        WaitForSingleObject(ghQServerThread, 10000);
        ghQServerThread = 0;
    }

    return 1;
}

#include "gen/data/Source/D2Client/GAME/Game_0044D080.inc"
