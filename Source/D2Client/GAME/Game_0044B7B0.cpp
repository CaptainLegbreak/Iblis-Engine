// These six functions (0x0044E200 GAME_InitGameState, the Lng module functions 0x00451260-0x00451330 and
// 0x00452130 GAME_InitColors) stay out of Game.cpp. This object's data starts with its own copy of the
// language-name table (0x0070F728, the marker below), past the end of Game.cpp's data (0x0070F564), so the two are
// separate objects. Joined into Game.cpp, the copy goes and its bytes have no source, and GAME_LoadAct (0x0044E100)
// expands GAME_InitColors, which the image calls out of line.
#include "D2LanguageNames.h"

#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2GameTypes.h"
#include "D2MultiTypes.h"
#include "D2MsgRecord.h"
#include "D2ClientTimer.h"
#include "D2ClientRange.h"
#include "D2ClientUiRecords.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "StormApi.h"
#include "FogApi2.h"
#include "D2GfxApi.h"
#include "D2CMPApi.h"
#include "D2NetApi.h"
#include "D2HellApi.h"
#include "D2MCPClientApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientNotifyStrc;

struct D2RangeStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" unsigned int __cdecl strlen(const char* pString);





void __fastcall UI_ToggleListDialog(int nResolution); // 0x004549B0








extern D2McpPacketHandler gpfnMcpPacketHandlers[]; // 0x0070ED00


extern int gnSavedScreenWidth; // 0x00711474

extern void (__fastcall* gpfnMcpMotdCallback)(void* pArg); // 0x00799308

int gaStateStack[4]; // 0x007A0424

int gnStateStackCount; // 0x007A044C



extern int gbLeftButtonDown; // 0x007A0650

extern int gbRightButtonDown; // 0x007A0654

extern int gbClickHandled; // 0x007A0658

int gbRightClickConsumed;                                                                                     // 0x007A0670

extern int gbCinematicExit; // 0x007A0674

extern int gnBeltUiRecordRow; // 0x007A5218





extern D2McpCallbackFn gpfnMcpPacket08Callback; // 0x007992F8

extern D2McpCallbackFn gpfnMcpPacket09Callback; // 0x007992FC

D2ConfigStrc* gpClientConfig; // 0x007A0438

int gbRunKeyHeld; // 0x007A065C

int gbAlwaysRun; // 0x007A0660

extern int gbStandStillHeld; // 0x007A0664

int gbLeftClickRepeating; // 0x007A066C

struct D2AutomapRecordStrc;

struct D2PoolSystemStrc;

#pragma pack(push, 1)

#pragma pack(pop)

typedef void (__fastcall* D2InitHandlerFn)(void* pArg);

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

typedef int (__stdcall* D2LoadStringFn)(int nId, char* szBuffer, unsigned int nSize);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryExA(const char* szFileName, void* hFile, unsigned long dwFlags); // 0x006CC348

extern "C" __declspec(dllimport) void* __stdcall LoadAcceleratorsA(void* hInstance, const char* szTableName); // 0x006CC4A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __cdecl FOG_CreateNewPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused); // 0x00409DD0







void __fastcall GAME_DrawGameView(void* pArg);                                                                   // 0x0044C990









void __fastcall CUNIT_SetPlayerUnit(D2UnitStrc* pUnit); // 0x00463D90












void __cdecl DLIGHTMAP_ClearLightGrid();                                                                                // 0x00474790



void __fastcall VIEW_SetViewPos(D2ViewStrc* pView, int nX, int nY);                                 // 0x004760A0

D2ViewStrc* __cdecl VIEW_CreateView();                                                                         // 0x00476B10



void __cdecl sub_00477DD0();                                                                                // 0x00477DD0

void __fastcall MSG_UploadSaveFile(int bAnimate);                                                    // 0x004781D0

void __cdecl CHAT_ResetChatHistory();                                                                                // 0x0047BD30




int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);         // 0x00502320

D2RecordHandlerFn __fastcall sub_005173D3_SetRecordHandler(D2RecordHandlerFn pfnHandler);                  // 0x005173D3

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0

int __fastcall UNICODE_StrLen(const Unicode* pString);                                                      // 0x00526800

extern "C" const char gszLngFileName[];                                                            // 0x006D5EE0

extern int gbInitHandlersResult;                                                                              // 0x0070F414

extern D2InitHandlerFn gpfnInitHandlers[52];                                                       // 0x0070F488


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern char gaClientState_007A0480[0x80];                                                                   // 0x007A0480

extern D2ClientCallbackFn gpfnClientCallback;                                                      // 0x007A0484

extern D2PoolSystemStrc* gpMemPool; // 0x007A0488

extern int gdwTickCount;                                                                              // 0x007A048C

extern int gnTickCounter;                                                                              // 0x007A0498

extern unsigned long gdwNextKeepAliveTick;                                                                  // 0x007A049C

extern unsigned long gdwLastPingTick;                                                                  // 0x007A04A0

extern int gnFramesPerSecond;                                                                              // 0x007A04A8

int gdwFpsWindowStart;                                                                                     // 0x007A04B8

extern unsigned long gdwDelayEnd;                                                                  // 0x007A04BC

extern int gnInteractDeadline;                                                                              // 0x007A04C8

extern int gbExpansion;                                                                              // 0x007A04F4

int gbLadder;                                                                                     // 0x007A04F8

extern int gnSkillDelayUntil; // 0x007A04FC

extern int gdwUnloadCompleteTick;                                                                              // 0x007A0524

extern int gdwGameStartTick;                                                                              // 0x007A05F8

extern int gbEndScreenDismissed;                                                                              // 0x007A0608

unsigned char gnClientDifficulty;                                                                        // 0x007A060C

extern int gbLeavingGame;                                                                              // 0x007A0620

extern int gbActUnloaded;                                                                                // 0x007A0624

extern int gnPlayCinematic; // 0x007A0628

extern int gnCinematicPlayed; // 0x007A062C

extern D2AutomapRecordStrc* gpAutomapRecord;                                                       // 0x007A0638

extern D2ViewStrc* gpClientView;                                                                         // 0x007A0640

extern D2LoadingTimerStrc gtLoadingTimer;                                                                                     // 0x007A0684

extern void* ghAccelerators;                                                                             // 0x007A0708

void* ghLngModule;                                                                                 // 0x007A070C

char gszLngPath[0x104];                                                                            // 0x007A0710

extern D2RecordHandlerFn gpfnPrevHandler;                                                          // 0x007A2764

extern int gbRecordHandlerInstalled;                                                                              // 0x007A2780

extern int gbRecordPlaying;                                                                              // 0x007A2788

extern int gaUIVarStates[];                                                                        // 0x007A27C0

extern Unicode gwszPopUpText[80]; // 0x007A2C80

extern int gnPopUpTextX;                                                                              // 0x007A2D20

extern int gnPopUpTextY;                                                                              // 0x007A2D24

extern Unicode gwszHoverLine[];                                                                    // 0x007A2D30

extern int gnHoverTextColor;                                                                       // 0x007A2F30



#define OFFSET(T,m) ((unsigned int)&(((T*)0)->m))

struct D2DrlgStrc;

struct Context;

struct Auxiliary;

struct Allocation;

struct UnitPrefix;













extern unsigned long gdwTickCount_007A048C; // 0x007A048C

extern unsigned int gnTickCounter_007A0498; // 0x007A0498

struct UnitPrefix { unsigned int prefix0; unsigned int prefix4; unsigned int prefix8; unsigned int identifier; };

typedef char check_UnitPrefix_identifier[OFFSET(UnitPrefix,identifier)==12?1:-1];



extern "C" Auxiliary* __cdecl sub_004646A0_GetAuxiliary();

extern "C" void __stdcall TEXT_FreeTextHeader(Allocation* allocation); // 0x006612A0


extern "C" Context* gContext; // 0x007A0634

extern "C" unsigned char gDeferred; // 0x007A060E

extern "C" unsigned int gCleanupState;

extern "C" Allocation* gAllocation;

extern "C" int gCoordinateBase;

extern "C" int gCoordinateOffset;

int __stdcall GAME_Shutdown(); // 0x0052C030


void __fastcall GAME_SetMcpCallbackA(D2McpCallbackFn pfnCallback); // 0x0044B1F0

void __fastcall GAME_SetMcpCallbackB(D2McpCallbackFn pfnCallback); // 0x0044B200

extern "C" { unsigned int gSlotFirst; } // 0x00799300

extern "C" { unsigned int gSlotSecond; } // 0x00799304


void __fastcall WINMAIN_PushStateValue(int nValue); // 0x0044B440

int __cdecl WINMAIN_PopStateValue(); // 0x0044B480

void __cdecl WINMAIN_RaiseGameWindow(); // 0x0044B780

const char* __cdecl WINMAIN_GetGameName(); // 0x0044B7C0

const char* __cdecl WINMAIN_GetGameDescription(); // 0x0044B7F0

const char* __cdecl WINMAIN_GetGamePassword(); // 0x0044B820

int __cdecl WINMAIN_IsHardcore(); // 0x0044B850

void __cdecl WINMAIN_SetCharDiedFlag(); // 0x0044B860

void __cdecl WINMAIN_SetLaunchStateOne(); // 0x0044B870


int __stdcall GAME_StartSubsystem(); // 0x0044BB70

extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80

int __fastcall GAME_RunClient(int nArg, const char* szAddress); // 0x0044BC10

int __fastcall GAME_GetRangeEnd(D2RangeStrc* pRange); // 0x0044BE10






void* ghAccelerators;                                                                                    // 0x007A0708

int __stdcall SCmdRegisterArgument(unsigned int dwFlags, unsigned int dwId, const char* szName, void* pVariable, unsigned int nBytes, int bSet, void* pfnCallback, void* pParam); // 0x006C4580

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

struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };

struct Unicode;








void __stdcall GAME_HandleLeftButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x0044C0F0

extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820








int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0




// 0x0044E200
void __cdecl GAME_InitGameState()
{
    gtLoadingTimer.dwStart = 0;
    gtLoadingTimer.dwLength = 0;
    gnCinematicPlayed = 0;
    gnPlayCinematic = 0;
    gbEndScreenDismissed = 0;
    gbActUnloaded = 0;
    gbStandStillHeld = 0;
    memset(gaClientState_007A0480, 0, sizeof(gaClientState_007A0480));
    FOG_CreateNewPoolSystem(&gpMemPool, "Client Pool System", 0x40000, 0x1000);
    CUNIT_SetPlayerUnit(0);
    GAME_ReadColorFlag();
    if (!gpClientView)
        gpClientView = VIEW_CreateView();
    sub_0047F1D0_LoadResolution();
    GAME_LoadLoadingScreen();
    UI_DrawLoadingScreen(1);
    if (gnGameType == 7 || gnGameType == 9 || gnGameType == 6 || gnGameType == 8)
        MSG_UploadSaveFile(1);
    sub_005173D3_SetRecordHandler(GAME_DestroyWindowAndGfx);
    PALSHIFT_AllocPalShiftEntries();
    D2CMP_LoadItemPalShifts();
    SKILLS_InitGfxCaches(gpMemPool, 1);
    gbLeavingGame = GAME_GetConnectFailed() != 0;
    gdwUnloadCompleteTick = GetTickCount();
    gdwGameStartTick = GetTickCount();
    gpfnClientCallback = GAME_DrawGameView;
    gnTickCounter = 0;
    gnFrameCount = 0;
    VIEW_SetViewPos(gpClientView, 0, 0);
    PLAYER_SetPanelSlide(0);
    gnSkillDelayUntil = 0;
    CUNIT_ClearAiTargets();
    sub_00473CE0_Nop();
    sub_0046BF90_ResetLevelEffects();
    gpAutomapRecord = (D2AutomapRecordStrc*)FOG_Alloc(8, ".\\GAME\\Game.cpp", 0x546, 0);
    CUNIT_ClearUnitTables();
    DLIGHTMAP_ClearLightGrid();
    sub_00472320_InitWeather();
    CHAT_ResetChatHistory();
    gbCinematicExit = 0;
    gbPositionalSound = 0;
}






int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80


// 0x00451260
int __cdecl RECORD_RegisterLngArgument()
{
    SCmdRegisterArgument(0x20000, -1, "lng", gszLngPath, sizeof(gszLngPath), 0, 0, 0);
    return 1;
}

// 0x00451290
void __cdecl GAME_FreeLngModule()
{
    if (ghLngModule)
        FreeLibrary(ghLngModule);
    ghLngModule = 0;
    ghAccelerators = 0;
}

// 0x004512C0
int __stdcall COMCALLBACK_LoadLngString(int nId, char* szBuffer, unsigned int nSize)
{
    D2_ASSERT(ghLngModule, 0x81);
    if (!SErrGetErrorStr(nId, szBuffer, nSize))
    {
        SStrCopy(szBuffer, "Stupid Lng.cpp error.", nSize);
        return 0;
    }
    return 1;
}

// 0x00451330
int __cdecl GAME_LoadLngModule()
{
    if (gszLngPath[0])
    {
        ghLngModule = LoadLibraryExA(gszLngPath, 0, 2);
        SRegSaveString("Diablo II", "LNG File", 0, gszLngPath);
    }
    if (!ghLngModule)
    {
        if (SRegLoadString("Diablo II", "LNG File", 0, gszLngPath, sizeof(gszLngPath)))
            ghLngModule = LoadLibraryExA(gszLngPath, 0, 2);
        if (!ghLngModule)
        {
            ghLngModule = LoadLibraryExA(gszLngFileName, 0, 2);
            if (!ghLngModule)
            {
                sub_0051740B_ErrorBox("Unable to start LNG manager.");
                return 0;
            }
        }
    }
    ghAccelerators = LoadAcceleratorsA(ghLngModule, (const char*)0x64);
    SErrRegisterMessageSource(0xFFF, ghLngModule, 0);
    sub_005177B2_SetLoadStringFn(COMCALLBACK_LoadLngString);
    return 1;
}

// 0x00452130
void __cdecl GAME_InitColors()
{
    INV_InitColorTable();
    PANEL_SetRedColour();
    PANEL_SetBlackColour();
    sub_004AB2F0();
    VIEW_InitTextColorRed();
    HIREABLES_InitTextColorA();
    VIEW_InitBeltColors();
    HIREABLES_InitTextColorB();
}

Unicode* __fastcall sub_00452170_ReturnText(Unicode* pText); // 0x00452170

void __fastcall GAME_StrToUpper(Unicode* pText); // 0x00452180

void __fastcall GAME_SetHoverLine(const Unicode* pText, int nColor); // 0x00452520




inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}



void __cdecl GAME_FreeLngModule(); // 0x00451290







void __cdecl GAME_ResetMouseState(); // 0x0044DA40



void __stdcall GAME_HandleRightButtonDown(SMSGHANDLER_PARAMS* pMsg); // 0x0044C180




struct D2UnitStrc;

extern "C" void __cdecl TEXT_ClearTextPanel()
{
    TEXT_ResetTextBox();
    Allocation* allocation=gAllocation;
    gCleanupState=0;
    if(allocation) {
        TEXT_FreeTextHeader(allocation);
        gAllocation=(Allocation*)0;
    }
}

extern "C" int __cdecl INV_GetPanelY()
{
    if(!GAME_IsExpansion())
        return gCoordinateOffset+gCoordinateBase-65;
    return gCoordinateOffset+gCoordinateBase-64;
}

