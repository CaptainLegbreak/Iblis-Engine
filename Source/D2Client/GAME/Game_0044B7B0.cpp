#include "D2Client.h"
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

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientNotifyStrc;

struct D2RangeStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" unsigned int __cdecl strlen(const char* pString);

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall PLAYER_SetPanelSlide(int nMode); // 0x0045AEA0

void __fastcall AUTOMAP_ResetBaseOffset(int nValue); // 0x00457640

void __fastcall sub_00457440_Nop(int nResolution); // 0x00457440

void __fastcall UI_ToggleListDialog(int nResolution); // 0x004549B0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __cdecl SELECT_UnlockHover(); // 0x00466FF0

void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom); // 0x0046C460

void __fastcall VIEW_SpawnRoomPresets(D2ActiveRoomStrc* pRoom); // 0x00466820

void __fastcall sub_0046BE60_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom); // 0x0046BE60

extern D2McpPacketHandler gpfnMcpPacketHandlers[]; // 0x0070ED00

extern int gnScreenWidth; // 0x0071146C

extern int gnSavedScreenWidth; // 0x00711474

extern void (__fastcall* gpfnMcpMotdCallback)(void* pArg); // 0x00799308

int gaStateStack[1]; // 0x007A0424

int gnStateStackCount; // 0x007A044C

extern int gbPositionalSound; // 0x007A061C

extern D2DrlgActStrc* gpAct; // 0x007A0634

extern int gbLeftButtonDown; // 0x007A0650

extern int gbRightButtonDown; // 0x007A0654

extern int gbClickHandled; // 0x007A0658

int gbRightClickConsumed;                                                                                     // 0x007A0670

extern int gbCinematicExit; // 0x007A0674

extern int gnBeltUiRecordRow; // 0x007A5218

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth; // 0x007A5220

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __stdcall WINDOW_ShowAll(); // 0x004F5F60

void __stdcall CLIENT_Initialize(int nArg, const char* szAddress); // 0x0052A750

int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int)); // 0x00451BB0

int __stdcall WINMAIN_WaitConnect(int nUnused); // 0x0044BBB0

extern D2McpCallbackFn gpfnMcpPacket08Callback; // 0x007992F8

extern D2McpCallbackFn gpfnMcpPacket09Callback; // 0x007992FC

D2ConfigStrc* gpClientConfig; // 0x007A0438

int gbRunKeyHeld; // 0x007A065C

int gbAlwaysRun; // 0x007A0660

int gbStandStillHeld; // 0x007A0664

int gbLeftClickRepeating; // 0x007A066C

struct D2AutomapRecordStrc;

struct D2PoolSystemStrc;

#pragma pack(push, 1)

struct D2ClientInfoStrc
{
    char unk0x00[0x1EF];
    union
    {
        unsigned short wFlags;
        struct
        {
            unsigned char lowFlags;
            unsigned char progress;
        };
    };
    char unk0x1F1[0x33];
    unsigned char nSoundArg;
};

#pragma pack(pop)

typedef void (__fastcall* D2InitHandlerFn)(void* pArg);

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

typedef int (__stdcall* D2LoadStringFn)(int nId, char* szBuffer, unsigned int nSize);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryExA(const char* szFileName, void* hFile, unsigned long dwFlags); // 0x006CC348

extern "C" __declspec(dllimport) void* __stdcall LoadAcceleratorsA(void* hInstance, const char* szTableName); // 0x006CC4A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80

int __cdecl FOG_CreateNewPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused); // 0x00409DD0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0);                        // 0x0040B3C0

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

int __stdcall SErrRegisterMessageSource(unsigned short wFacility, void* hModule, void* pReserved);     // 0x0041C2F0

int __cdecl GAME_GetConnectFailed();                                                                                 // 0x0044BBA0

void __stdcall GAME_DestroyWindowAndGfx(int nArg1, int nArg2, int nArg3);                                               // 0x0044C850

void __fastcall GAME_DrawGameView(void* pArg);                                                                   // 0x0044C990

void __cdecl GAME_ReadColorFlag();                                                                  // 0x0044DBE0

int __stdcall COMCALLBACK_LoadLngString(int nId, char* szBuffer, unsigned int nSize);                         // 0x004512C0

void __stdcall RECORD_RecordHandler(int nArg1, int nArg2, int nArg3);                                 // 0x00451920

void __cdecl GAME_LoadLoadingScreen();                                                              // 0x00456550

void __cdecl UI_ShutdownUI();                                                                                // 0x00456D80

void __fastcall SKILLS_InitGfxCaches(void* pMemPool, int bCelPool);                                   // 0x00457300

void __fastcall AUTOMAP_FreeCaches(int nArg);                                                                     // 0x00457420

void __cdecl CUNIT_ClearUnitTables();                                                                                // 0x00463C70

void __fastcall CUNIT_SetPlayerUnit(D2UnitStrc* pUnit); // 0x00463D90

void __cdecl CUNIT_FreeAllUnits();                                                                                // 0x004659C0

void __cdecl SELECT_ClearSelection();                                                                                // 0x00466FE0

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB);                                                     // 0x00469AA0

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB);                                                                // 0x00469D90

void __cdecl sub_0046BF90_ResetLevelEffects();                                                                                // 0x0046BF90

void __cdecl CUNIT_ClearAiTargets();                                                                                // 0x0046D750

void __cdecl sub_00472320();                                                                                // 0x00472320

void __cdecl sub_004723C0();                                                                                // 0x004723C0

void __cdecl sub_00472BD0();                                                                                // 0x00472BD0

void __cdecl sub_00473CE0_Nop();                                                                                // 0x00473CE0

void __cdecl sub_00473CF0_Nop();                                                                                // 0x00473CF0

void __cdecl DLIGHTMAP_ClearLightGrid();                                                                                // 0x00474790

void __cdecl DLIGHTMAP_FreeAllLights();                                                                                // 0x004758D0

void __fastcall VIEW_FreeView(D2ViewStrc* pView);                                                            // 0x00475FD0

void __fastcall VIEW_SetViewPos(D2ViewStrc* pView, int nX, int nY);                                 // 0x004760A0

D2ViewStrc* __cdecl VIEW_CreateView();                                                                         // 0x00476B10

void __cdecl PALSHIFT_AllocPalShiftEntries();                                                                   // 0x00476EA0

void __cdecl PALSHIFT_FreePalShifts();                                                                                // 0x00476FB0

void __cdecl sub_00477DD0();                                                                                // 0x00477DD0

void __fastcall MSG_UploadSaveFile(int bAnimate);                                                    // 0x004781D0

void __cdecl CHAT_ResetChatHistory();                                                                                // 0x0047BD30

void __cdecl sub_0047F1D0_LoadResolution();                                                                 // 0x0047F1D0

void __cdecl INV_InitColorTable();                                                                                // 0x00483960

void __cdecl PANEL_SetBlackColour();                                                                                // 0x00499E30

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);         // 0x00502320

D2RecordHandlerFn __fastcall sub_005173D3_SetRecordHandler(D2RecordHandlerFn pfnHandler);                  // 0x005173D3

int __fastcall sub_0051740B_ErrorBox(const char* szText);                                                   // 0x0051740B

void __fastcall sub_005177B2_SetLoadStringFn(void* pfnLoadString); // 0x005177B2

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

void __cdecl D2CMPTileFreeAsyncLoads();                                                                                // 0x005FE070

void __cdecl D2CMPSpriteFreeAsyncLoads();                                                                                // 0x005FF3A0

void __cdecl sub_00600B80();                                                                                // 0x00600B80

extern "C" const char gszLngFileName[];                                                            // 0x006D5EE0

extern int gbInitHandlersResult;                                                                              // 0x0070F414

extern D2InitHandlerFn gpfnInitHandlers[52];                                                       // 0x0070F488

extern unsigned short gawToUpperTable[0x100];                                                       // 0x00730578

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern char gaClientState_007A0480[0x80];                                                                   // 0x007A0480

extern D2ClientCallbackFn gpfnClientCallback;                                                      // 0x007A0484

D2PoolSystemStrc* gpMemPool;                                                                       // 0x007A0488

extern int gdwTickCount;                                                                              // 0x007A048C

extern int gnTickCounter;                                                                              // 0x007A0498

extern unsigned long gdwNextTick_007A049C;                                                                  // 0x007A049C

extern unsigned long gdwLastPingTick;                                                                  // 0x007A04A0

extern int gnFramesPerSecond;                                                                              // 0x007A04A8

int gdwFpsWindowStart;                                                                                     // 0x007A04B8

extern unsigned long gdwDelayEnd;                                                                  // 0x007A04BC

extern int gnInteractDeadline;                                                                              // 0x007A04C8

extern int gbExpansion;                                                                              // 0x007A04F4

int gbLadder;                                                                                     // 0x007A04F8

int gnSkillDelayUntil;                                                                                     // 0x007A04FC

extern int gdwUnloadCompleteTick;                                                                              // 0x007A0524

extern int gdwGameStartTick;                                                                              // 0x007A05F8

extern int gbEndScreenDismissed;                                                                              // 0x007A0608

unsigned char gnClientDifficulty;                                                                        // 0x007A060C

extern int gbLeavingGame;                                                                              // 0x007A0620

extern int gbActUnloaded;                                                                                // 0x007A0624

int gnPlayCinematic;                                                                                     // 0x007A0628

int gnCinematicPlayed;                                                                                     // 0x007A062C

extern D2AutomapRecordStrc* gpAutomapRecord;                                                       // 0x007A0638

extern D2ViewStrc* gpClientView;                                                                         // 0x007A0640

int gtLoadingTimer;                                                                                     // 0x007A0684

int gdwGlobal_007A0688;                                                                                     // 0x007A0688

extern void* ghAccelerators;                                                                             // 0x007A0708

void* ghLngModule;                                                                                 // 0x007A070C

char gszLngPath[0x104];                                                                            // 0x007A0710

extern D2RecordHandlerFn gpfnPrevHandler;                                                          // 0x007A2764

extern int gbRecordHandlerInstalled;                                                                              // 0x007A2780

extern int gbRecordPlaying;                                                                              // 0x007A2788

extern int gaUIVarStates[];                                                                        // 0x007A27C0

Unicode gwszPopUpText[80];                                                                              // 0x007A2C80

extern int gnPopUpTextX;                                                                              // 0x007A2D20

extern int gnPopUpTextY;                                                                              // 0x007A2D24

extern Unicode gwszHoverLine_007A2D30[];                                                                    // 0x007A2D30

extern int gnHoverTextColor;                                                                       // 0x007A2F30

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl GAME_ResetLeftClick(); // 0x0044C060

int __stdcall D2GFX_Release(); // 0x004F5050

int __stdcall WINDOW_Destroy(); // 0x004F5900

#define OFFSET(T,m) ((unsigned int)&(((T*)0)->m))

struct D2DrlgStrc;

struct Context;

struct Auxiliary;

struct Allocation;

struct UnitPrefix;

void __cdecl GAME_InitRooms(); // 0x0044C750

void __cdecl CUNIT_ResetUnitTables(); // 0x00465AA0

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

void __stdcall DUNGEON_AnimateTiles(D2ActiveRoomStrc* pRoom); // 0x0061AEF0

void __cdecl sub_0046BEB0_UpdateTimers(); // 0x0046BEB0

void __fastcall GFX_PreloadTick(int nValue); // 0x00470350

int __stdcall ENVIRONMENT_UpdatePeriodOfDay(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom); // 0x0061BFC0

void __cdecl CUNIT_UpdateObjectsForPeriod(); // 0x004646C0

D2DrlgStrc* __stdcall DUNGEON_GetDrlgFromAct(D2DrlgActStrc* pAct); // 0x0061AA90

void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg); // 0x0061B920

void __cdecl AUTOMAP_UpdateAutomapReveal(); // 0x00459020

void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct); // 0x0061AA20

extern unsigned long gdwTickCount_007A048C; // 0x007A048C

extern unsigned int gnTickCounter_007A0498; // 0x007A0498

struct UnitPrefix { unsigned int prefix0; unsigned int prefix4; unsigned int prefix8; unsigned int identifier; };

typedef char check_UnitPrefix_identifier[OFFSET(UnitPrefix,identifier)==12?1:-1];

extern "C" UnitPrefix* __cdecl CURSOR_GetCursorItem(); // 0x004680A0

extern "C" void __fastcall MSG_SendTwoDwords(unsigned char command,unsigned int first,unsigned int second); // 0x004786A0

extern "C" Auxiliary* __cdecl sub_004646A0_GetAuxiliary();

extern "C" void __stdcall ENVIRONMENT_InitializeEnvironment(Context* context,Auxiliary* auxiliary,int mode,int angle,int flag); // 0x0061C240

extern "C" void __cdecl TEXT_ResetTextBox(); // 0x0049F960

extern "C" void __stdcall TEXT_FreeTextHeader(Allocation* allocation); // 0x006612A0

extern "C" int __cdecl GAME_IsExpansion(); // 0x0044DCC0

extern "C" Context* gContext; // 0x007A0634

extern "C" unsigned char gDeferred; // 0x007A060E

extern "C" unsigned int gCleanupState;

extern "C" Allocation* gAllocation;

extern "C" int gCoordinateBase;

extern "C" int gCoordinateOffset;

int __stdcall GAME_Shutdown(); // 0x0052C030

int __fastcall GAME_DispatchMcpPacket(const unsigned char* pPacket, unsigned int nSize); // 0x0044B190

void __fastcall GAME_SetMcpCallbackA(D2McpCallbackFn pfnCallback); // 0x0044B1F0

void __fastcall GAME_SetMcpCallbackB(D2McpCallbackFn pfnCallback); // 0x0044B200

extern "C" { unsigned int gSlotFirst; } // 0x00799300

extern "C" { unsigned int gSlotSecond; } // 0x00799304

extern "C" void __fastcall sub_0044B210_StoreSlots(unsigned int first, unsigned int second); // 0x0044B210

void __fastcall GAME_SetMcpChatCallback(void (__fastcall* pfnCallback)(void* pArg)); // 0x0044B220

void __fastcall WINMAIN_PushStateValue(int nValue); // 0x0044B440

int __cdecl WINMAIN_PopStateValue(); // 0x0044B480

void __cdecl WINMAIN_RaiseGameWindow(); // 0x0044B780

const char* __cdecl WINMAIN_GetGameName(); // 0x0044B7C0

const char* __cdecl WINMAIN_GetGameDescription(); // 0x0044B7F0

const char* __cdecl WINMAIN_GetGamePassword(); // 0x0044B820

int __cdecl WINMAIN_IsHardcore(); // 0x0044B850

void __cdecl WINMAIN_SetCharDiedFlag(); // 0x0044B860

void __cdecl WINMAIN_SetLaunchStateOne(); // 0x0044B870

void __fastcall GAME_SetResolution(int nResolution); // 0x0044BA20

int __stdcall GAME_StartSubsystem(); // 0x0044BB70

extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80

int __fastcall GAME_RunClient(int nArg, const char* szAddress); // 0x0044BC10

int __fastcall GAME_GetRangeEnd(D2RangeStrc* pRange); // 0x0044BE10

void __fastcall GAME_SetAlwaysRun(int bAlwaysRun); // 0x0044BE80

void __fastcall GAME_SetStandStillHeld(int nValue); // 0x0044BEA0

unsigned short __cdecl GAME_GetClickFlags(); // 0x0044BEC0

void __cdecl GAME_SetClickHandled(); // 0x0044BEF0

int __cdecl GAME_IsLeftClickRepeating(); // 0x0044BFE0

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

struct D2TileRectStrc
{
    int unk0x00;
    int nX;
    int nY;
    unsigned int nWidth;
    unsigned int nHeight;
};

struct D2GridCellStrc;

struct D2GridCellStrc
{
    int nFlag;
    unsigned char nValue[4];
};

struct D2MonLvlTxt;

struct D2MonLvlTxt
{
    char unk0x00[0x78];
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size); // 0x0041C430

extern int gbStringsLoaded_007A070C; // 0x007A070C

static unsigned short __cdecl sub_0044BEC0_GetClickFlags_static()
{
    int nFlags = 0;
    if (gbRunKeyHeld)
        nFlags = 8;
    if (gbAlwaysRun)
        nFlags |= 8;
    if (gbStandStillHeld)
        nFlags |= 4;
    return nFlags;
}

void __cdecl GAME_StartClick(); // 0x0044C000

static __forceinline int CLIENT_GetClickFlags_inl()
{
    int nFlags = 0;
    if (gbRunKeyHeld)
        nFlags = 8;
    if (gbAlwaysRun)
        nFlags |= 8;
    if (gbStandStillHeld)
        nFlags |= 4;
    return nFlags;
}

void __cdecl GAME_ResetLeftClick(); // 0x0044C060

void __stdcall GAME_HandleLeftButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x0044C0F0

extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __fastcall GAME_IsTimerExpired(D2LoadingTimerStrc* pTimer); // 0x0044DFF0

int __fastcall GAME_IsTimerRunning(D2LoadingTimerStrc* pTimer); // 0x0044E040

void __fastcall GAME_ExtendDelay(int nDelay); // 0x0044DB40

void __fastcall GAME_SetDifficulty(unsigned char nDifficulty); // 0x0044DC70

void __fastcall GAME_SetExpansion(unsigned char nValue); // 0x0044DC80

void __fastcall GAME_SetLadderFlag(int nValue); // 0x0044DC90

int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

void __stdcall GAME_DestroyWindowAndGfx(int nArg1, int nArg2, int nArg3); // 0x0044C850

void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860

void __cdecl GAME_FreeWeather(); // 0x0044C880

// 0x0044E200
void __cdecl GAME_InitGameState()
{
    gtLoadingTimer = 0;
    gdwGlobal_007A0688 = 0;
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
    sub_004565E0_Redraw(1);
    if (gdwGlobal_007A0610 == 7 || gdwGlobal_007A0610 == 9 || gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 8)
        MSG_UploadSaveFile(1);
    sub_005173D3_SetRecordHandler(GAME_DestroyWindowAndGfx);
    PALSHIFT_AllocPalShiftEntries();
    sub_00600B80();
    SKILLS_InitGfxCaches(gpMemPool, 1);
    gbLeavingGame = GAME_GetConnectFailed() != 0;
    gdwUnloadCompleteTick = GetTickCount();
    gdwGameStartTick = GetTickCount();
    gpfnClientCallback = GAME_DrawGameView;
    gnTickCounter = 0;
    gdwGlobal_007A0494 = 0;
    VIEW_SetViewPos(gpClientView, 0, 0);
    PLAYER_SetPanelSlide(0);
    gnSkillDelayUntil = 0;
    CUNIT_ClearAiTargets();
    sub_00473CE0_Nop();
    sub_0046BF90_ResetLevelEffects();
    gpAutomapRecord = (D2AutomapRecordStrc*)FOG_Alloc(8, ".\\GAME\\Game.cpp", 0x546, 0);
    CUNIT_ClearUnitTables();
    DLIGHTMAP_ClearLightGrid();
    sub_00472320();
    CHAT_ResetChatHistory();
    gbCinematicExit = 0;
    gbPositionalSound = 0;
}

int __cdecl GAME_LoadLngModule(); // 0x00451330

void __cdecl RECORD_InstallRecordHandler(); // 0x00451940

void __cdecl RECORD_SetRecordPlaying(); // 0x00451970

int __cdecl GAME_PushRegisterState(); // 0x00451F10

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

#include "gen/data/Source/D2Client/GAME/Game_0044B7B0.inc"
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
    D2_ASSERT(gbStringsLoaded_007A070C, 0x81);
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
    sub_00499E10();
    PANEL_SetBlackColour();
    sub_004AB2F0();
    sub_00497250();
    sub_00497270();
    sub_004972B0();
    sub_00497290();
}

Unicode* __fastcall sub_00452170(Unicode* pText); // 0x00452170

void __fastcall GAME_StrToUpper(Unicode* pText); // 0x00452180

void __fastcall GAME_SetHoverLine(const Unicode* pText, int nColor); // 0x00452520

void __cdecl GAME_DrawPopUpText(); // 0x00453060

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

void __cdecl GAME_ReleaseGameState(); // 0x0044C890

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

void __cdecl GAME_AverageFrameCounters(); // 0x0044CCE0

void __cdecl GAME_TickKeepAlive(); // 0x0044CD70

void __cdecl sub_00451290(); // 0x00451290

void __fastcall GAME_SetSkillDelayUntil(int nValue); // 0x0044CE40

void __cdecl GAME_UpdateKeyState(); // 0x0044CE90

void __cdecl GAME_SetCinematicPlayed(); // 0x0044D510

void __cdecl GAME_RequestExit(); // 0x0044D520

void __fastcall GAME_SetPlayCinematic(int nValue); // 0x0044D530

int __fastcall GAME_RunInitHandlers(void* pArg); // 0x0044D9F0

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

void __fastcall GAME_SetInteractDeadline(int nValue); // 0x0044DAD0

void __stdcall GAME_HandleRightButtonDown(SMSGHANDLER_PARAMS* pMsg); // 0x0044C180

void __cdecl GAME_StartRightClick(); // 0x0044C2C0

void __cdecl GAME_InitRooms(); // 0x0044C750

void __cdecl GAME_UpdateGameState(); // 0x0044C790

struct D2UnitStrc;

// build: symbol _CUNIT_ClearTextPanel 0x004A1730
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

// build: symbol _INV_GetPanelY 0x00486B00
extern "C" int __cdecl INV_GetPanelY()
{
    if(!GAME_IsExpansion())
        return gCoordinateOffset+gCoordinateBase-65;
    return gCoordinateOffset+gCoordinateBase-64;
}

