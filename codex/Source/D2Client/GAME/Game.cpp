#include "SGAMEDATA.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2Drlg.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MultiTypes.h"
#include "D2ClientTypes.h"
#include "D2TxtTables.h"
#include "D2MsgRecord.h"
#include "D2ClientTimer.h"
#include "D2ClientRange.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct PairStrc_0044BE20;

struct PairStrc_0044DE50;

struct PairStrc_0044DEE0;

struct D2McpInfoStrc;

struct D2ClientNotifyStrc;

struct Unicode;

struct D2TickValueStrc;

struct D2StormLinkStrc;

struct D2StormListAStrc;

struct D2StormListBStrc;

struct D2StormListArrayStrc;

struct D2StormListStrc;

struct D2TickTimerStrc;

struct sub_0040F7D0;

struct sub_00417810;

struct sub_00417860;

struct sub_004178C0;

struct sub_00417900;

struct sub_00417950;

struct sub_004179B0;

struct sub_004183F0;

struct sub_00418430;

struct sub_00418780;

struct sub_004187C0;

struct sub_00418800;

struct sub_00418840;

struct sub_00418880;

struct sub_004188C0;

struct sub_00418BA0;

struct sub_00418BE0;

struct sub_00418C20;

struct sub_00418E10;

struct sub_0041C3D0;

struct sub_0041C500;

struct sub_0041C730;

struct sub_0041C800;

struct sub_00420430;

struct sub_004204B0;

struct sub_00420710;

struct sub_004207E0;

struct sub_00426960;

struct sub_00426A80;

struct sub_00426CB0;

struct sub_00426D80;

struct sub_0044DDD0;

struct sub_0044DE90;

struct sub_0044ECC0;

struct sub_0044ED50;

struct sub_00601BF0;

struct sub_00601C70;

struct sub_00601D60;

struct sub_00601F20;

struct sub_00601F60;

struct sub_006020D0;

struct sub_00602140;

struct sub_006024A0;

struct sub_00602760;

struct sub_00417780;

struct sub_00417850;

struct sub_004178B0;

struct sub_00417940;

struct sub_00417990;

struct sub_00418760;

struct sub_00418770;

struct sub_00418A40;

struct sub_00418DE0;

struct sub_00418DF0;

struct sub_00418E00;

struct sub_00418E50;

struct sub_00418FF0;

struct sub_00419060;

struct sub_0041C4F0;

struct sub_0041C720;

struct sub_0041C7F0;

struct sub_004204A0;

struct sub_00420700;

struct sub_004207D0;

struct sub_00426CA0;

struct sub_00426D70;

struct sub_0044BDE0;

struct sub_0044ED40;

struct sub_0044ED90;

struct sub_00601F10;

struct sub_00602130;

struct sub_00602180;

struct sub_00602420;

struct sub_00602750;

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

struct SMSGHANDLER_PARAMS;

struct D2UnitStrc;

struct D2LevelsTxt;

struct D2ConfigStrc;

struct D2ClientInfoStrc;

class WardenModule;

struct D2Warden47F930Strc;

struct D2WardenModuleHolderAStrc;

struct D2WardenModuleHolderBStrc;

struct D2GameStrc;

struct D2AutomapRecordStrc;

extern int gbStopMainLoop; // 0x0077932C

extern int gdwGlobal_007799D8; // 0x007799D8

extern char gszPreferredRealm[]; // 0x00779A40

extern int gdwGlobal_0077AC04; // 0x0077AC04

extern int gdwGlobal_0077BBF8; // 0x0077BBF8

extern char gszChannelName[]; // 0x00798D30

extern int gdwGlobal_007992A4; // 0x007992A4

extern char gszMcpGameServerIP[]; // 0x007992CC

extern int gnMcpGameToken; // 0x00798FB0

extern int gdwGlobal_0079929C; // 0x0079929C

extern int gdwMcpGameHash; // 0x00798F88

extern int gdwGlobal_007992F4; // 0x007992F4

extern int gbConnectFailed; // 0x007A0460

struct PairStrc_0044BE20
{
    int nFirst;
    int nSecond;
};

int gbRunKeyHeld; // 0x007A065C

int gbAlwaysRun; // 0x007A0660

int gbStandStillHeld; // 0x007A0664

int gbRightButtonDown; // 0x007A0654

int gbLeftButtonDown; // 0x007A0650

int gbCinematicExit; // 0x007A0674

int gnSkillDelayUntil;                                                                                     // 0x007A04FC

extern int gdwGlobal_007A04A4; // 0x007A04A4

extern int gdwGlobal_007A04D0; // 0x007A04D0

extern char gData_007A04D4[]; // 0x007A04D4

extern int gdwGlobal_007A05F4; // 0x007A05F4

extern int gbLeavingGame; // 0x007A0620

extern int gdwTickCount; // 0x007A048C

extern int gnFramesPerSecond; // 0x007A04A8

extern int gdwGlobal_007A0488; // 0x007A0488

int gbColorFlag; // 0x007A05FC

extern int gbExpansion; // 0x007A04F4

struct PairStrc_0044DE50
{
    int nFirst;
    int nSecond;
};

struct PairStrc_0044DEE0
{
    int nFirst;
    int nSecond;
};

extern "C" char* __cdecl strcpy(char* pDest, const char* pSource);

extern "C" unsigned int __cdecl strlen(const char* pString);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214


extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* lpOutputString); // 0x006CC200

struct D2McpInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int unk0x04;
    int nValue;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nByte0E;
    unsigned char unk0x0F;
    int nCount;
    int nToken;
    char unk0x18[0x10];
    char szName[0x20];
    unsigned short aFirst[16];
    unsigned short aSecond[16];
    char aNames[16][0x10];
};

int __stdcall GAME_GetPlayerUnitsCount(unsigned short nGameId); // 0x0052EFF0

void* __stdcall GAME_UpdateGamesProgress(int nArg); // 0x0052FC20

extern unsigned short gwMcpRequestId; // 0x00798F8C

D2ConfigStrc* gpClientConfig; // 0x007A0438

extern int gnQServerThreshold; // 0x0070F560

struct D2TickValueStrc
{
    unsigned int dwTickCount;
    int nValue;

    void Set(int nValue); // 0x0044BDF0
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" int __cdecl abs(int nValue);

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pPattern); // 0x00526940

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl SELECT_UnlockHover(); // 0x00466FF0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __fastcall CUNIT_DispatchMouseWheel(int nSteps); // 0x004693B0

void __cdecl sub_00469270(); // 0x00469270

void __cdecl sub_00469230(); // 0x00469230

void __cdecl sub_004692B0(); // 0x004692B0

void __cdecl sub_00469330(); // 0x00469330

void __cdecl sub_004692F0(); // 0x004692F0

void __cdecl CMDTBL_CallBoundCommand(); // 0x00469370

int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30

void __cdecl UI_FreePlayerUI(); // 0x00453DE0

void __cdecl SELECT_ResetHoverClassIds(); // 0x00467A00

extern unsigned char gnBetaScreenIndex; // 0x007A060D

int gbRightClickConsumed;                                                                                     // 0x007A0670

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern D2ClientCallbackFn gpfnClientCallback; // 0x007A0484

extern D2ClientCallbackFn gpfnClientCallbacks[3]; // 0x0070EF0C

extern int gbPlaybackRequested; // 0x007A277C

extern int gnScreenWidth; // 0x0071146C

int gdwFpsWindowStart;                                                                                     // 0x007A04B8

int gbPositionalSound; // 0x007A061C

int gbClickHandled; // 0x007A0658

extern int gnAutomapHeight_007A521C; // 0x007A521C

int __cdecl sub_0045AE90(); // 0x0045AE90

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __fastcall AUTOMAP_ResetBaseOffset(int bForce); // 0x00457640

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __stdcall sub_00420290_BreakHandlerChain(void* pMsg); // 0x00420290

extern int gnGlobal_007A0608; // 0x007A0608

void __fastcall ROSTER_SetPrimaryClientFlag(int bClear); // 0x0047A9B0

extern char gszRealm_007A0500[]; // 0x007A0500

void __cdecl sub_004776E0_SetModeValuesOne(); // 0x004776E0

void __cdecl D2GFX_DisableFixedAspectRatio(); // 0x004F5280

void __cdecl INV_SetRenderModeGlide(); // 0x004776F0

void __cdecl INV_SetRenderModeOpenGL(); // 0x00477700

void __cdecl INV_SetRenderModeDirect3D(); // 0x00477710

void __cdecl INV_SetRenderModeRave(); // 0x00477720

void __fastcall sub_004776C0(int nGamma); // 0x004776C0

void __cdecl D2GFX_EnableVSync(); // 0x004F5270

void __fastcall LOGGING_SetLoggingEnabled(int nValue); // 0x00624B50

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

void __fastcall ROSTER_SetCTemp(int nValue); // 0x0047AA10

void __stdcall D2CMPSetNoCompress(int bCompress); // 0x005FE280

void __stdcall DATATBLS_ToggleCompileTxtFlag(int bValue); // 0x006125A0

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    D2StormLinkStrc* sub_0044DD90_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0044DE60_NextLink(int nLinkOffset);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListAStrc(const D2StormListAStrc& source);
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044DF90_CopyLinkOffset(const D2StormListAStrc* pSource);
    D2StormLinkStrc* sub_0044ED20_Link(char* pNode);
    void sub_0044EDC0_UnlinkNode(char* pNode);
    void sub_0044EE10_InitLinkField(int nLinkOffset);
    void sub_0044F980_ChangeLinkOffset(int nLinkOffset); // 0x0044F980
};

struct D2StormListBStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormListBStrc(const D2StormListBStrc& source);
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* sub_0044EDA0_Link(char* pNode);
    void sub_0044EE30_InitLinkField(int nLinkOffset);
    void sub_0044F890_UnlinkNode(char* pNode);
};

struct D2StormListArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;

    D2StormListAStrc* sub_0044DE10_At(unsigned int nIndex);
};

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2TickTimerStrc
{
    unsigned int dwStart;
    unsigned int dwDuration;

    unsigned int GetRemaining(); // 0x0044DFB0
};

struct sub_0040F7D0
{
    D2StormLinkStrc f_0;
    ~sub_0040F7D0();
};

struct sub_00417810
{
    D2StormLinkStrc f_0;
    ~sub_00417810();
};

struct sub_00417860
{
    D2StormLinkStrc f_0;
    ~sub_00417860();
};

struct sub_004178C0
{
    D2StormLinkStrc f_0;
    ~sub_004178C0();
};

struct sub_00417900
{
    D2StormLinkStrc f_0;
    ~sub_00417900();
};

struct sub_00417950
{
    D2StormLinkStrc f_0;
    ~sub_00417950();
};

struct sub_004179B0
{
    D2StormLinkStrc f_0;
    ~sub_004179B0();
};

struct sub_004183F0
{
    D2StormLinkStrc f_0;
    ~sub_004183F0();
};

struct sub_00418430
{
    D2StormLinkStrc f_0;
    ~sub_00418430();
};

struct sub_00418780
{
    D2StormLinkStrc f_0;
    ~sub_00418780();
};

struct sub_004187C0
{
    D2StormLinkStrc f_0;
    ~sub_004187C0();
};

struct sub_00418800
{
    D2StormLinkStrc f_0;
    ~sub_00418800();
};

struct sub_00418840
{
    D2StormLinkStrc f_0;
    ~sub_00418840();
};

struct sub_00418880
{
    D2StormLinkStrc f_0;
    ~sub_00418880();
};

struct sub_004188C0
{
    D2StormLinkStrc f_0;
    ~sub_004188C0();
};

struct sub_00418BA0
{
    D2StormLinkStrc f_0;
    ~sub_00418BA0();
};

struct sub_00418BE0
{
    D2StormLinkStrc f_0;
    ~sub_00418BE0();
};

struct sub_00418C20
{
    D2StormLinkStrc f_0;
    ~sub_00418C20();
};

struct sub_00418E10
{
    D2StormLinkStrc f_0;
    ~sub_00418E10();
};

struct sub_0041C3D0
{
    D2StormLinkStrc f_0;
    ~sub_0041C3D0();
};

struct sub_0041C500
{
    D2StormLinkStrc f_0;
    ~sub_0041C500();
};

struct sub_0041C730
{
    D2StormLinkStrc f_0;
    ~sub_0041C730();
};

struct sub_0041C800
{
    D2StormLinkStrc f_0;
    ~sub_0041C800();
};

struct sub_00420430
{
    D2StormLinkStrc f_0;
    ~sub_00420430();
};

struct sub_004204B0
{
    D2StormLinkStrc f_0;
    ~sub_004204B0();
};

struct sub_00420710
{
    D2StormLinkStrc f_0;
    ~sub_00420710();
};

struct sub_004207E0
{
    D2StormLinkStrc f_0;
    ~sub_004207E0();
};

struct sub_00426960
{
    D2StormLinkStrc f_0;
    ~sub_00426960();
};

struct sub_00426A80
{
    D2StormLinkStrc f_0;
    ~sub_00426A80();
};

struct sub_00426CB0
{
    D2StormLinkStrc f_0;
    ~sub_00426CB0();
};

struct sub_00426D80
{
    D2StormLinkStrc f_0;
    ~sub_00426D80();
};

struct sub_0044DDD0
{
    D2StormLinkStrc f_0;
    ~sub_0044DDD0();
};

struct sub_0044DE90
{
    D2StormLinkStrc f_0;
    ~sub_0044DE90();
};

struct sub_0044ECC0
{
    D2StormLinkStrc f_0;
    ~sub_0044ECC0();
};

struct sub_0044ED50
{
    D2StormLinkStrc f_0;
    ~sub_0044ED50();
};

struct sub_00601BF0
{
    D2StormLinkStrc f_0;
    ~sub_00601BF0();
};

struct sub_00601C70
{
    D2StormLinkStrc f_0;
    ~sub_00601C70();
};

struct sub_00601D60
{
    D2StormLinkStrc f_0;
    ~sub_00601D60();
};

struct sub_00601F20
{
    D2StormLinkStrc f_0;
    ~sub_00601F20();
};

struct sub_00601F60
{
    D2StormLinkStrc f_0;
    ~sub_00601F60();
};

struct sub_006020D0
{
    D2StormLinkStrc f_0;
    ~sub_006020D0();
};

struct sub_00602140
{
    D2StormLinkStrc f_0;
    ~sub_00602140();
};

struct sub_006024A0
{
    D2StormLinkStrc f_0;
    ~sub_006024A0();
};

struct sub_00602760
{
    D2StormLinkStrc f_0;
    ~sub_00602760();
};

struct sub_00417780
{
    D2StormLinkStrc f_0;
    sub_00417780();
};

struct sub_00417850
{
    D2StormLinkStrc f_0;
    sub_00417850();
};

struct sub_004178B0
{
    D2StormLinkStrc f_0;
    sub_004178B0();
};

struct sub_00417940
{
    D2StormLinkStrc f_0;
    sub_00417940();
};

struct sub_00417990
{
    D2StormLinkStrc f_0;
    sub_00417990();
};

struct sub_00418760
{
    D2StormLinkStrc f_0;
    sub_00418760();
};

struct sub_00418770
{
    D2StormLinkStrc f_0;
    sub_00418770();
};

struct sub_00418A40
{
    D2StormLinkStrc f_0;
    sub_00418A40();
};

struct sub_00418DE0
{
    D2StormLinkStrc f_0;
    sub_00418DE0();
};

struct sub_00418DF0
{
    D2StormLinkStrc f_0;
    sub_00418DF0();
};

struct sub_00418E00
{
    D2StormLinkStrc f_0;
    sub_00418E00();
};

struct sub_00418E50
{
    D2StormLinkStrc f_0;
    sub_00418E50();
};

struct sub_00418FF0
{
    D2StormLinkStrc f_0;
    sub_00418FF0();
};

struct sub_00419060
{
    D2StormLinkStrc f_0;
    sub_00419060();
};

struct sub_0041C4F0
{
    D2StormLinkStrc f_0;
    sub_0041C4F0();
};

struct sub_0041C720
{
    D2StormLinkStrc f_0;
    sub_0041C720();
};

struct sub_0041C7F0
{
    D2StormLinkStrc f_0;
    sub_0041C7F0();
};

struct sub_004204A0
{
    D2StormLinkStrc f_0;
    sub_004204A0();
};

struct sub_00420700
{
    D2StormLinkStrc f_0;
    sub_00420700();
};

struct sub_004207D0
{
    D2StormLinkStrc f_0;
    sub_004207D0();
};

struct sub_00426CA0
{
    D2StormLinkStrc f_0;
    sub_00426CA0();
};

struct sub_00426D70
{
    D2StormLinkStrc f_0;
    sub_00426D70();
};

struct sub_0044BDE0
{
    D2StormLinkStrc f_0;
    sub_0044BDE0();
};

struct sub_0044ED40
{
    D2StormLinkStrc f_0;
    sub_0044ED40();
};

struct sub_0044ED90
{
    D2StormLinkStrc f_0;
    sub_0044ED90();
};

struct sub_00601F10
{
    D2StormLinkStrc f_0;
    sub_00601F10();
};

struct sub_00602130
{
    D2StormLinkStrc f_0;
    sub_00602130();
};

struct sub_00602180
{
    D2StormLinkStrc f_0;
    sub_00602180();
};

struct sub_00602420
{
    D2StormLinkStrc f_0;
    sub_00602420();
};

struct sub_00602750
{
    D2StormLinkStrc f_0;
    sub_00602750();
};

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);

extern "C" const char gszIgnoreListSourceFile_006E6290[];

unsigned char gnClientDifficulty;                                                                        // 0x007A060C

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);

extern "C" const char szWardenClientFile_006D8E18[];

class WardenModule
{
public:
    WardenModule();
    ~WardenModule();

    void* pImage;
    int unk0x04;
    int nImports;
    int unk0x0C;
    void* f_10;
};

struct D2Warden47F930Strc
{
    int n00;
    int n04;
    int n08;

    D2Warden47F930Strc();
};

struct D2WardenModuleHolderAStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderAStrc();
};

struct D2WardenModuleHolderBStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderBStrc();
};

typedef void (__stdcall* AUTOMAPFN)(void* pRoom);

typedef void (__stdcall* TOWNAUTOMAPFN)(int nLevelId, int nPickedFile, int nX, int nY);

void __stdcall GAME_PreloadActTiles(unsigned char nAct); // 0x0044DB60

void __cdecl GAME_InitColors(); // 0x00452130

void __fastcall UI_SetLoadingAct(int nValue); // 0x00454790

void __fastcall UI_DrawLoadingScreen(int bAdvanceFrame); // 0x004565E0

void __stdcall AUTOMAP_RevealRoomCallback(D2ActiveRoomStrc* pRoom); // 0x00459150

void __stdcall AUTOMAP_AddTownCelsCallback(int nLevelId, int nPickedFile, int nX, int nY); // 0x004591A0

void __cdecl AUTOMAP_InitAutomapColors(); // 0x0045A620

void __fastcall GFX_LoadGlobalHashedFile(unsigned char nIndex); // 0x0046F310

void __cdecl GFX_FreeActHashedFile(); // 0x0046F440

void __cdecl DLIGHTMAP_InitLightTables(); // 0x00475B40

D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x006194A0

int gdwGlobal_0077AC08; // 0x0077AC08

int gbMcpCharCreateReceived; // 0x007992E8

int gbMcpCharLogonReceived; // 0x007992E0

int gbMcpCharDeleteReceived; // 0x00799298

int gbMcpCharUpgradeReceived; // 0x007992F0

int gbMcpPacket0BReceived; // 0x00799100

int gbMcpPacket0CReceived; // 0x007992A0

char gabMcpReply[4]; // 0x00799108

int gbMcpPacket0DReceived; // 0x007992A8

int gbMcpPacket0FReceived; // 0x00798F5C

int gbMcpServerAddressReceived; // 0x00798F84

int gnMcpCreateQueuePosition; // 0x00799104

int gbMcpCreateQueued; // 0x00798F7C

int gnTickCounter; // 0x007A0498

int gnInteractDeadline; // 0x007A04C8

int gnPathFrame; // 0x007A04C4

struct D2RangeStrc;

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall PLAYER_SetPanelSlide(int nMode); // 0x0045AEA0

void __fastcall sub_00457440_Nop(int nResolution); // 0x00457440

void __fastcall UI_ToggleListDialog(int nResolution); // 0x004549B0

void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom); // 0x0046C460

void __fastcall VIEW_SpawnRoomPresets(D2ActiveRoomStrc* pRoom); // 0x00466820

void __fastcall sub_0046BE60_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom); // 0x0046BE60

extern D2McpPacketHandler gpfnMcpPacketHandlers[]; // 0x0070ED00

extern int gnSavedScreenWidth; // 0x00711474

extern void (__fastcall* gpfnMcpMotdCallback)(void* pArg); // 0x00799308

int gaStateStack[1]; // 0x007A0424

int gnStateStackCount; // 0x007A044C

extern int gnBeltUiRecordRow; // 0x007A5218

extern int gnAutomapWidth; // 0x007A5220

void __stdcall WINDOW_ShowAll(); // 0x004F5F60

void __stdcall CLIENT_Initialize(int nArg, const char* szAddress); // 0x0052A750

int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int)); // 0x00451BB0

int __stdcall WINMAIN_WaitConnect(int nUnused); // 0x0044BBB0

extern D2McpCallbackFn gpfnMcpPacket08Callback; // 0x007992F8

extern D2McpCallbackFn gpfnMcpPacket09Callback; // 0x007992FC

int gbLeftClickRepeating; // 0x007A066C

struct D2PoolSystemStrc;

typedef void (__fastcall* D2InitHandlerFn)(void* pArg);

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

typedef int (__stdcall* D2LoadStringFn)(int nId, char* szBuffer, unsigned int nSize);

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryExA(const char* szFileName, void* hFile, unsigned long dwFlags); // 0x006CC348

extern "C" __declspec(dllimport) void* __stdcall LoadAcceleratorsA(void* hInstance, const char* szTableName); // 0x006CC4A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80

int __cdecl FOG_CreateNewPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused); // 0x00409DD0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

int __fastcall FOG_Free(void* pMemory, const char* szFile, int nLine, int n0);                        // 0x0040B3C0

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

void __cdecl D2CMPTileFreeAsyncLoads();                                                                                // 0x005FE070

void __cdecl D2CMPSpriteFreeAsyncLoads();                                                                                // 0x005FF3A0

void __cdecl sub_00600B80();                                                                                // 0x00600B80

extern "C" const char gszLngFileName[];                                                            // 0x006D5EE0

extern int gbInitHandlersResult;                                                                              // 0x0070F414

extern D2InitHandlerFn gpfnInitHandlers[52];                                                       // 0x0070F488

extern unsigned short gawToUpperTable[0x100];                                                       // 0x00730578

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern char gaClientState_007A0480[0x80];                                                                   // 0x007A0480

D2PoolSystemStrc* gpMemPool;                                                                       // 0x007A0488

extern unsigned long gdwNextTick_007A049C;                                                                  // 0x007A049C

extern unsigned long gdwLastPingTick;                                                                  // 0x007A04A0

int gbLadder;                                                                                     // 0x007A04F8

extern int gdwUnloadCompleteTick;                                                                              // 0x007A0524

extern int gdwGameStartTick;                                                                              // 0x007A05F8

extern int gbEndScreenDismissed;                                                                              // 0x007A0608

extern int gbActUnloaded;                                                                                // 0x007A0624

int gnPlayCinematic;                                                                                     // 0x007A0628

int gnCinematicPlayed;                                                                                     // 0x007A062C

extern D2ViewStrc* gpClientView;                                                                         // 0x007A0640

int gtLoadingTimer;                                                                                     // 0x007A0684

int gdwGlobal_007A0688;                                                                                     // 0x007A0688

extern void* ghAccelerators;                                                                             // 0x007A0708

extern D2RecordHandlerFn gpfnPrevHandler;                                                          // 0x007A2764

extern int gbRecordHandlerInstalled;                                                                              // 0x007A2780

extern int gbRecordPlaying;                                                                              // 0x007A2788

extern int gaUIVarStates[];                                                                        // 0x007A27C0

Unicode gwszPopUpText[80];                                                                              // 0x007A2C80

extern int gnPopUpTextX;                                                                              // 0x007A2D20

extern int gnPopUpTextY;                                                                              // 0x007A2D24

extern Unicode gwszHoverLine_007A2D30[];                                                                    // 0x007A2D30

extern int gnHoverTextColor;                                                                       // 0x007A2F30

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

// build: symbol ??__EgtGameDataTable@@YAXXZ 0x006CA9C0
// build: symbol ??__FgtGameDataTable@@YAXXZ 0x006CB3E0
// build: symbol ??0?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@QAE@XZ 0x00451100
// build: symbol ??1?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAE@XZ 0x00450760
D2SGameDataSyncTable gtGameDataTable; // 0x007A0690

int __stdcall GAME_Shutdown(); // 0x0052C030

D2McpInfoStrc gtMcpInfo; // 0x0079910C

D2CriticalSectionStrc gtQServerLock; // 0x007A0468

int gbQServerStop; // 0x007A0648

int gbQServerRestart; // 0x007A064C

int gnWheelDelta; // 0x007A06F8

int gnClientState; // 0x007A0480

void __cdecl sub_00451290(); // 0x00451290

void* gpComInterface; // 0x007A05F4

unsigned long gdwDelayEnd; // 0x007A04BC

unsigned char gbEnvironmentPending; // 0x007A060E

D2DrlgActStrc* gpAct; // 0x007A0634

D2AutomapRecordStrc* gpAutomapRecord; // 0x007A0638

int gnTownLevelId; // 0x007A063C

int gnBetaScreens; // 0x007A0600

static int gnDifficultyDirty; // 0x007A0604

sub_0040F7D0::~sub_0040F7D0()
{
    f_0.Unlink();
}

sub_00417780::sub_00417780()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00417810::~sub_00417810()
{
    f_0.Unlink();
}

sub_00417850::sub_00417850()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00417860::~sub_00417860()
{
    f_0.Unlink();
}

sub_004178B0::sub_004178B0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004178C0::~sub_004178C0()
{
    f_0.Unlink();
}

sub_00417900::~sub_00417900()
{
    f_0.Unlink();
}

sub_00417940::sub_00417940()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00417950::~sub_00417950()
{
    f_0.Unlink();
}

sub_00417990::sub_00417990()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004179B0::~sub_004179B0()
{
    f_0.Unlink();
}

sub_004183F0::~sub_004183F0()
{
    f_0.Unlink();
}

sub_00418430::~sub_00418430()
{
    f_0.Unlink();
}

sub_00418760::sub_00418760()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418770::sub_00418770()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418780::~sub_00418780()
{
    f_0.Unlink();
}

sub_004187C0::~sub_004187C0()
{
    f_0.Unlink();
}

sub_00418800::~sub_00418800()
{
    f_0.Unlink();
}

sub_00418840::~sub_00418840()
{
    f_0.Unlink();
}

sub_00418880::~sub_00418880()
{
    f_0.Unlink();
}

sub_004188C0::~sub_004188C0()
{
    f_0.Unlink();
}

sub_00418A40::sub_00418A40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418BA0::~sub_00418BA0()
{
    f_0.Unlink();
}

sub_00418BE0::~sub_00418BE0()
{
    f_0.Unlink();
}

sub_00418C20::~sub_00418C20()
{
    f_0.Unlink();
}

sub_00418DE0::sub_00418DE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418DF0::sub_00418DF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418E00::sub_00418E00()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418E10::~sub_00418E10()
{
    f_0.Unlink();
}

sub_00418E50::sub_00418E50()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00418FF0::sub_00418FF0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00419060::sub_00419060()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C3D0::~sub_0041C3D0()
{
    f_0.Unlink();
}

sub_0041C4F0::sub_0041C4F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C500::~sub_0041C500()
{
    f_0.Unlink();
}

sub_0041C720::sub_0041C720()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C730::~sub_0041C730()
{
    f_0.Unlink();
}

sub_0041C7F0::sub_0041C7F0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_0041C800::~sub_0041C800()
{
    f_0.Unlink();
}

sub_00420430::~sub_00420430()
{
    f_0.Unlink();
}

sub_004204A0::sub_004204A0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004204B0::~sub_004204B0()
{
    f_0.Unlink();
}

sub_00420700::sub_00420700()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00420710::~sub_00420710()
{
    f_0.Unlink();
}

sub_004207D0::sub_004207D0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_004207E0::~sub_004207E0()
{
    f_0.Unlink();
}

sub_00426960::~sub_00426960()
{
    f_0.Unlink();
}

sub_00426A80::~sub_00426A80()
{
    f_0.Unlink();
}

sub_00426CA0::sub_00426CA0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00426CB0::~sub_00426CB0()
{
    f_0.Unlink();
}

sub_00426D70::sub_00426D70()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00426D80::~sub_00426D80()
{
    f_0.Unlink();
}

// 0x0042F6D0
int __cdecl sub_0042F6D0()
{
    return gdwGlobal_00779974;
}

// 0x0042FA30
int __cdecl GAME_GetStopMainLoop()
{
    return gbStopMainLoop;
}

// 0x00430B40
int __cdecl GAME_GetSlotNameCount()
{
// build: symbol ?gnSlotCount@* 0x0077998C
    return gnSlotCount;
}

// 0x00437D00
void* __cdecl GAME_GetPreferredRealm()
{
    return gszPreferredRealm;
}

// 0x00437D10
int __cdecl sub_00437D10()
{
    return 0;
}

// 0x0043DB10
int __cdecl GAME_IsLaunchExpansion()
{
    return gdwGlobal_0077BBF8;
}

// 0x0043F840
int __cdecl sub_0043F840()
{
    return 1;
}

// 0x00446CF0
void* __cdecl GAME_GetChannelName()
{
    return gszChannelName;
}

// 0x004473F0
int __cdecl sub_004473F0()
{
    return 1;
}

// 0x004476F0
int __cdecl sub_004476F0()
{
    return 1;
}

// 0x00447730
int __stdcall sub_00447730(int nUnused1, int nUnused2)
{
    return 0;
}

// build: symbol ?COMCALLBACK_NibbleToHex@* 0x00449840
unsigned int __fastcall COMCALLBACK_NibbleToHex(unsigned int nValue)
{
    unsigned int nResult = nValue & 0xF;
    if (nResult >= 10)
        nResult += 0x37;
    else
        nResult += 0x30;
    return nResult;
}

// 0x00449890
void __fastcall GAME_CalcCdKeyChecksum(char* szKey, unsigned int* pChecksum)
{
    unsigned int nBit = 1;
    *pChecksum = 0;
    for (int i = 0; i < 16; i += 2, nBit <<= 1)
    {
// build: symbol ?gabCdKeyMap@* 0x006D59F0
        unsigned int nValue = (char)gabCdKeyMap[(unsigned char)szKey[i]] * 3;
        nValue = (char)gabCdKeyMap[(unsigned char)szKey[i + 1]] + nValue * 8;
        if (nValue >= 0x100)
        {
            nValue -= 0x100;
            *pChecksum |= nBit;
        }
        szKey[i] = (char)COMCALLBACK_NibbleToHex(nValue >> 4);
        szKey[i + 1] = (char)COMCALLBACK_NibbleToHex(nValue);
    }
}

struct D2ActiveRoomStrc;

extern "C" { unsigned int gSlotFirst; } // 0x00799300

extern "C" { unsigned int gSlotSecond; } // 0x00799304

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

int __cdecl GAME_GetConnectFailed(); // 0x0044BBA0

// 0x0044BDE0
sub_0044BDE0::sub_0044BDE0()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044BDF0
void D2TickValueStrc::Set(int nValue)
{
    dwTickCount = GetTickCount();
    this->nValue = nValue;
}

// 0x0044BE10
int __fastcall GAME_GetRangeEnd(D2RangeStrc* pRange)
{
    return pRange->nLength + pRange->nStart;
}

// 0x0044BE20
void __fastcall sub_0044BE20(PairStrc_0044BE20* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0044BE60
void __fastcall GAME_SetRunKeyHeld(int nValue)
{
    gbRunKeyHeld = nValue;
}

// 0x0044BE70
int __cdecl GAME_IsRunKeyHeld()
{
    return gbRunKeyHeld;
}

// 0x0044BE80
void __fastcall GAME_SetAlwaysRun(int bAlwaysRun)
{
    gbAlwaysRun = bAlwaysRun;
}

// 0x0044BE90
int __cdecl GAME_GetAlwaysRun()
{
    return gbAlwaysRun;
}

// 0x0044BEA0
void __fastcall GAME_SetStandStillHeld(int nValue)
{
    gbStandStillHeld = nValue;
}

// 0x0044BEB0
int __cdecl GAME_IsStandStillHeld()
{
    return gbStandStillHeld;
}

// 0x0044BEC0
unsigned short __cdecl GAME_GetClickFlags()
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

// 0x0044BEF0
void __cdecl GAME_SetClickHandled()
{
    gbClickHandled = 1;
}

// 0x0044BF00
int __cdecl GAME_GetLeftClickState()
{
// build: symbol ?gnLeftClickState@* 0x0070F234
    return gnLeftClickState;
}

// 0x0044BF10
int __cdecl GAME_GetRightClickState()
{
// build: symbol ?gnRightClickState@* 0x0070F2BC
    return gnRightClickState;
}

// 0x0044BF20
int __cdecl GAME_IsRightButtonHeld()
{
    return gbRightButtonDown;
}

// 0x0044BF30
int __cdecl GAME_IsLeftButtonHeld()
{
    return gbLeftButtonDown;
}

// 0x0044BF40
void __stdcall GAME_HandleLeftButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    gnLeftClickState = 4;
    gbClickHandled = 0;
    SELECT_UnlockHover();
    if (gbPositionalSound)
    {
        gbLeftButtonDown = 1;
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nFlags = 0;
        if (gbRunKeyHeld)
            nFlags = 8;
        if (gbAlwaysRun)
            nFlags |= 8;
        if (gbStandStillHeld)
            nFlags |= 4;
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            gbLeftButtonDown = sub_00462D00(0, pMsg->nXpos, pMsg->nYpos, nFlags);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044BFE0
int __cdecl GAME_IsLeftClickRepeating()
{
    return gbLeftClickRepeating != 0;
}

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

// 0x0044C000
void __cdecl GAME_StartClick()
{
// build: symbol ?gnLeftClickState@* 0x0070F234
    gnLeftClickState = 8;
    if (gbPositionalSound && gbLeftButtonDown && !gbClickHandled)
    {
        gbLeftClickRepeating = 1;
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        const int nFlags = sub_0044BEC0_GetClickFlags_static();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            sub_00462D00(1, sub_00468730(), sub_00468740(), nFlags);
        }
    }
}

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

// 0x0044C060
void __cdecl GAME_ResetLeftClick()
{
    gnLeftClickState = 0x10;
    gbLeftButtonDown = 0;
    gbLeftClickRepeating = 0;
    gbClickHandled = 0;
    SELECT_UnlockHover();
    if (gbPositionalSound)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
            sub_00462D00(2, sub_00468730(), sub_00468740(), CLIENT_GetClickFlags_inl());
    }
}

// 0x0044C0F0
void __stdcall GAME_HandleLeftButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    GAME_ResetLeftClick();
}

// 0x0044C100
static inline int GAME_IsInLeftPanel(int nX, int nY)
{
    int bLeftPanel = 0;
    if (sub_0045AE90() == 2 && nX > 0 && nX < gnScreenWidth / 2 && nY > 0 && nY < gnScreenHeight - 0x2F)
    {
        bLeftPanel = 1;
    }
    return bLeftPanel;
}

// 0x0044C140
static inline int GAME_IsInRightPanel(int nX, int nY)
{
    int bRightPanel = 0;
    if (sub_0045AE90() == 1 && nX > gnScreenWidth / 2 && nX < gnScreenWidth && nY > 0 && nY < gnAutomapHeight_007A521C)
    {
        bRightPanel = 1;
    }
    return bRightPanel;
}

// 0x0044C180
void __stdcall GAME_HandleRightButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    gnRightClickState = 4;
    gbClickHandled = 0;
    SELECT_UnlockHover();
    if (!gbPositionalSound || sub_0045AE90() == 3)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    int bLeftPanel = 0;
    if (sub_0045AE90() == 2 && nX > 0 && nX < gnScreenWidth / 2 && nY > 0 && nY < gnScreenHeight - 0x2F)
    {
        bLeftPanel = 1;
    }
    int bRightPanel = 0;
    if (sub_0045AE90() == 1 && nX > gnScreenWidth / 2 && nX < gnScreenWidth && nY > 0 && nY < gnAutomapHeight_007A521C)
    {
        bRightPanel = 1;
    }
    if (bLeftPanel || bRightPanel)
    {
        pMsg->bReturn = 0;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gbRightButtonDown = 1;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nFlags = sub_0044BEC0_GetClickFlags_static();
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        gbRightButtonDown = sub_00462D00(3, pMsg->nXpos, pMsg->nYpos, nFlags);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044C2C0
void __cdecl GAME_StartRightClick()
{
    gnRightClickState = 8;
    if (gbPositionalSound && gbRightButtonDown)
    {
        gbRightClickConsumed = 1;
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        const int nFlags = CLIENT_GetClickFlags_inl();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
            sub_00462D00(4, sub_00468730(), sub_00468740(), nFlags);
    }
}

// 0x0044C340
void __cdecl GAME_ResetRightClickState()
{
    gnRightClickState = 0x10;
    gbRightButtonDown = 0;
    gbRightClickConsumed = 1;
    gbClickHandled = 0;
    SELECT_UnlockHover();
}

// 0x0044C370
void __stdcall GAME_HandleRightButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    gnRightClickState = 0x10;
    gbRightButtonDown = 0;
    gbRightClickConsumed = 1;
    gbClickHandled = 0;
    SELECT_UnlockHover();
    if (gbPositionalSound)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            gbRightButtonDown = sub_00462D00(5, pMsg->nXpos, pMsg->nYpos, pMsg->wParamLow);
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044C400
void __stdcall GAME_HandleMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbPositionalSound)
    {
        gnWheelDelta += (short)pMsg->wParamHigh;
        if (abs(gnWheelDelta) >= 120)
        {
            CUNIT_DispatchMouseWheel(gnWheelDelta / 120);
            gnWheelDelta = 0;
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044C470
void __stdcall GAME_HandleMiddleButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbPositionalSound)
    {
        sub_00469270();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044C4A0
void __stdcall GAME_HandleMiddleButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbPositionalSound)
    {
        sub_00469230();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044C4D0
void __stdcall GAME_HandleXButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbPositionalSound)
    {
        unsigned short nCode = pMsg->wParamHigh;
        if (nCode == 1)
            sub_004692B0();
        else if (nCode == 2)
            sub_00469330();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044C520
void __stdcall GAME_HandleXButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbPositionalSound)
    {
        unsigned short nCode = pMsg->wParamHigh;
        if (nCode == 1)
            sub_004692F0();
        else if (nCode == 2)
            CMDTBL_CallBoundCommand();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044C570
void __stdcall GAME_HandleSysCommand(SMSGHANDLER_PARAMS* pMsg)
{
    unsigned short nCommand = pMsg->wParamLow & 0xFFF0;
    if (nCommand == 0xF130 || nCommand == 0xF100 || (nCommand == 0xF010 && WINDOW_IsFullScreen()))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x0044C5C0
void __stdcall GAME_SwallowMessage(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044C6A0
void __cdecl sub_0044C6A0_Nothing()
{
}

// 0x0044C6B0
void __cdecl GAME_CloseAllPanels()
{
    if (gbPositionalSound && !UI_CloseUIVars(0, 1))
    {
        AUTOMAP_ResetBaseOffset(0);
        UI_CloseUIVars(1, 0);
    }
}

// 0x0044C750
void __cdecl GAME_InitRooms()
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(gpAct); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (!(pRoom->dwFlags & 1))
        {
            sub_0046C460_PopulateRoom(pRoom);
            VIEW_SpawnRoomPresets(pRoom);
            sub_0046BE60_ApplyDenOfEvilRoom(pRoom);
            pRoom->dwFlags |= 1;
        }
    }
}

// 0x0044C790
void __cdecl GAME_UpdateGameState()
{
    gdwTickCount_007A048C = GetTickCount();
    GAME_InitRooms();
    CUNIT_ResetUnitTables();
    DUNGEON_AnimateTiles(CUNIT_GetPlayerRoom());
    sub_0046BEB0_UpdateTimers();
    GFX_PreloadTick(1);
    if (ENVIRONMENT_UpdatePeriodOfDay(gpAct, CUNIT_GetPlayerRoom()))
        CUNIT_UpdateObjectsForPeriod();
    DRLGACTIVATE_Update(DUNGEON_GetDrlgFromAct(gpAct));
    AUTOMAP_UpdateAutomapReveal();
    if (++gnTickCounter_007A0498 % 13 == 0)
        DUNGEON_UpdateAndFreeInactiveRooms(gpAct);
}

// 0x0044C820
extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer()
{
    if(gContext != (Context*)0)
        ENVIRONMENT_InitializeEnvironment(gContext,sub_004646A0_GetAuxiliary(),5,0,1);
    else
        gDeferred=1;
}

// 0x0044C850
void __stdcall GAME_DestroyWindowAndGfx(int nArg1, int nArg2, int nArg3)
{
    WINDOW_Destroy();
    D2GFX_Release();
}

// 0x0044C860
void __fastcall GAME_SetCinematicExit(int nValue)
{
    gbCinematicExit = nValue;
}

// 0x0044C870
int __cdecl GAME_IsCinematicExit()
{
    return gbCinematicExit;
}

// 0x0044C880
void __cdecl GAME_FreeWeather()
{
    sub_00472BD0();
}

// 0x0044C890
void __cdecl GAME_ReleaseGameState()
{
    sub_00472BD0();
    PALSHIFT_FreePalShifts();
    CUNIT_FreeAllUnits();
    if (gpAct)
        DUNGEON_FreeAct(gpAct);
    gpAct = 0;
    D2CMPSpriteFreeAsyncLoads();
    D2CMPTileFreeAsyncLoads();
    AUTOMAP_FreeCaches(0);
    VIEW_FreeView(gpClientView);
    gpClientView = 0;
    UI_ShutdownUI();
    sub_00473CF0_Nop();
    DLIGHTMAP_FreeAllLights();
    sub_004723C0();
    FOG_DestroyMemoryPoolSystem(gpMemPool);
    memset(gaClientState_007A0480, 0, sizeof(gaClientState_007A0480));
    FOG_Free(gpAutomapRecord, ".\\GAME\\Game.cpp", 0x599, 0);
}

// 0x0044C930
void __fastcall GAME_SetClientState(int nState)
{
    gnClientState = nState;
    gpfnClientCallback = gpfnClientCallbacks[nState];
}

// 0x0044C950
unsigned int __cdecl GAME_GetLevelBlankScreen()
{
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (!pRoom)
    {
        return 0;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord, 0x5DE);
    return pLevelsTxtRecord->dwBlankScreen;
}

// build: symbol ??_7?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@6B@ 0x006D5E84
// build: symbol ??_7?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@6B@ 0x006D5E98
// 0x0044CCE0
void __cdecl GAME_AverageFrameCounters()
{
    const int nNow = gdwTickCount;
    if ((unsigned int)(nNow - gdwFpsWindowStart) > 3000)
    {
        gnFramesPerSecond = gdwGlobal_007A04AC / 3;
        gdwGlobal_007A04B0 = gdwGlobal_007A04B4 / 3;
        gdwFpsWindowStart = nNow;
        gdwGlobal_007A04AC = 0;
        gdwGlobal_007A04B4 = 0;
    }
}

// 0x0044CD40
void __cdecl GAME_ResetFrameTimer()
{
    gdwFpsWindowStart = gdwTickCount;
    gnFramesPerSecond = 0x19;
    gdwGlobal_007A04B0 = 0;
    gdwGlobal_007A04AC = 0;
    gdwGlobal_007A04B4 = 0;
}

// 0x0044CD70
void __cdecl GAME_TickKeepAlive()
{
    const unsigned long dwNow = GetTickCount();
    if (gdwNextTick_007A049C < dwNow)
    {
        sub_00477DD0();
        gdwLastPingTick = dwNow;
        if (gpClientConfig->wFlags1EF & 4)
            gdwNextTick_007A049C = dwNow + 5000;
        else
            gdwNextTick_007A049C = dwNow + 5000;
    }
}

// 0x0044CE40
void __fastcall GAME_SetSkillDelayUntil(int nValue)
{
    gnSkillDelayUntil = nValue;
}

// 0x0044CE50
int __cdecl GAME_GetSkillDelayUntil()
{
    return gnSkillDelayUntil;
}

// 0x0044CE60
int __cdecl GAME_GetPing()
{
    return gdwGlobal_007A04A4;
}

// 0x0044CE70
int __cdecl sub_0044CE70()
{
    return gdwGlobal_007A04D0;
}

// 0x0044CE80
void* __cdecl sub_0044CE80()
{
    return gData_007A04D4;
}

// 0x0044CE90
void __cdecl GAME_UpdateKeyState()
{
    if (CUNIT_HasHotkeyBinding(0x24, 1))
    {
        const unsigned short wKey = CUNIT_GetHotkeyBinding(0x24, 1);
        if (wKey != 0xFFFF && (GetAsyncKeyState(wKey) & 0x8000))
        {
            gbStandStillHeld = 1;
            return;
        }
    }
    if (CUNIT_HasHotkeyBinding(0x24, 0))
    {
        const unsigned short wKey = CUNIT_GetHotkeyBinding(0x24, 0);
        if (wKey != 0xFFFF && (GetAsyncKeyState(wKey) & 0x8000))
        {
            gbStandStillHeld = 1;
            return;
        }
    }
    gbStandStillHeld = 0;
}

// 0x0044CF20
unsigned long __stdcall GAME_RunQServerThread(void* pArg)
{
    int nLast = 0;
    void* pSession = 0;
    EnterCriticalSection(&gtQServerLock);
    int bStop = gbQServerStop;
    int bRestart = gbQServerRestart;
    LeaveCriticalSection(&gtQServerLock);
    while (!bStop)
    {
        if (bRestart)
        {
            sub_0052CFE0();
            pSession = GAME_UpdateGamesProgress(1);
            if (pSession)
                sub_0052FD90(0, 0);
        }
        if (pSession)
        {
            Sleep(30);
            D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
            if (pNotify)
            {
                const int nLevel = GAME_GetPlayerUnitsCount(1);
                if (nLevel != nLast)
                {
                    if (nLast < gnQServerThreshold)
                    {
                        if (nLevel >= gnQServerThreshold)
                            pNotify->pfnNotify();
                    }
                    else if (nLevel < gnQServerThreshold)
                    {
                        int nFlags = 0;
                        if (gpClientConfig->nByte210 == 1)
                            nFlags = 1;
                        if (gpClientConfig->nByte210 == 2)
                            nFlags |= 2;
                        const unsigned short wFlags = gpClientConfig->wFlags1EF;
                        if (wFlags & 4)
                            nFlags |= 4;
                        if (wFlags & 0x20)
                            nFlags |= 8;
                        pNotify->pfnCharUpdate(gpClientConfig->szGameName, gpClientConfig->szText0x245, gpClientConfig->szText0x25D, nFlags);
                    }
                    nLast = nLevel;
                }
            }
        }
        else
        {
            Sleep(10);
        }
        EnterCriticalSection(&gtQServerLock);
        bStop = gbQServerStop;
        bRestart = gbQServerRestart;
        LeaveCriticalSection(&gtQServerLock);
    }
    sub_0052E9C0();
    sub_0052FD90(0, 1);
    DeleteCriticalSection(&gtQServerLock);
    OutputDebugStringA("Open server thread shut down\n");
    return 1;
}

// 0x0044D0A0
void __stdcall GAME_AdvanceBetaScreen(SMSGHANDLER_PARAMS* pMsg)
{
    gnBetaScreenIndex += 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044D0D0
void __stdcall GAME_AdvanceBetaScreenNoRepeat(SMSGHANDLER_PARAMS* pMsg)
{
    if (!(pMsg->lParam & 0x40000000))
        gnBetaScreenIndex += 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

int __fastcall sub_M118_Emit_0044C100(int nX, int nY)
{
    const int bLeftPanel = GAME_IsInLeftPanel(nX, nY);
    const int bRightPanel = GAME_IsInRightPanel(nX, nY);
    return bLeftPanel || bRightPanel;
}

// 0x0044D320
static int __stdcall GAME_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX < nX || nMouseX > nX + nWidth || nMouseY < nY - nHeight || nMouseY > nY)
    {
        return 0;
    }
    return 1;
}

int __stdcall sub_K02_EmitIsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    return GAME_IsMouseInRect(nX, nY, nWidth, nHeight);
}

// 0x0044D360
void __stdcall GAME_HandleKeyDown(void* pMsg)
{
    int nOne = 1;
    if ((*(int*)((char*)pMsg + 0x0C) & 0x40000000) == 0)
        gnGlobal_007A0608 = nOne;
    *(int*)((char*)pMsg + 0x18) = nOne;
    *(int*)((char*)pMsg + 0x1C) = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0044D510
void __cdecl GAME_SetCinematicPlayed()
{
    gnCinematicPlayed = 1;
}

// 0x0044D520
void __cdecl GAME_RequestExit()
{
    gbLeavingGame = 1;
}

// 0x0044D530
void __fastcall GAME_SetPlayCinematic(int nValue)
{
    gnPlayCinematic = nValue;
}

// 0x0044D540
int __cdecl GAME_GetComInterface()
{
    return gdwGlobal_007A05F4;
}

// 0x0044D730
void __fastcall sub_0044D730_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D740
void __fastcall sub_0044D740_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D750
void __fastcall sub_0044D750_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D760
void __fastcall GAME_ApplyConfigWindow(D2ConfigStrc* pConfig)
{
    if (pConfig->bWindow)
        sub_004776E0_SetModeValuesOne();
}

// 0x0044D770
void __fastcall GAME_ApplyConfigNoFixAspect(D2ConfigStrc* pConfig)
{
    if (pConfig->bNoFixedAspect)
        D2GFX_DisableFixedAspectRatio();
}

// 0x0044D780
void __fastcall GAME_ApplyConfigGlide(D2ConfigStrc* pConfig)
{
    if (pConfig->b3DFX)
        INV_SetRenderModeGlide();
}

// 0x0044D790
void __fastcall GAME_ApplyConfigOpenGL(D2ConfigStrc* pConfig)
{
    if (pConfig->bOpenGL)
        INV_SetRenderModeOpenGL();
}

// 0x0044D7A0
void __fastcall GAME_ApplyConfigDirectX(D2ConfigStrc* pConfig)
{
    if (pConfig->bD3D)
        INV_SetRenderModeDirect3D();
}

// 0x0044D7B0
void __fastcall GAME_ApplyConfigRave(D2ConfigStrc* pConfig)
{
    if (pConfig->bRave)
        INV_SetRenderModeRave();
}

// 0x0044D7C0
void __fastcall sub_0044D7C0_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D7D0
void __fastcall GAME_ApplyConfigGamma(D2ConfigStrc* pConfig)
{
    if (pConfig->dwGamma)
        sub_004776C0(pConfig->dwGamma);
}

// 0x0044D7E0
void __fastcall GAME_ApplyConfigVSync(D2ConfigStrc* pConfig)
{
    if (pConfig->bVSync)
        D2GFX_EnableVSync();
}

// 0x0044D7F0
void __fastcall sub_0044D7F0_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D800
void __fastcall sub_0044D800_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D810
void __fastcall sub_0044D810_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D820
void __fastcall sub_0044D820_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D830
void __fastcall sub_0044D830_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D840
void __fastcall GAME_ApplyConfigLog(D2ConfigStrc* pConfig)
{
    if (pConfig->bLog)
        LOGGING_SetLoggingEnabled(1);
}

// 0x0044D860
void __fastcall GAME_ApplyConfigSeed(D2ConfigStrc* pConfig)
{
    if (pConfig->dwSeed)
        GAME_SetInitSeed(pConfig->dwSeed);
}

// 0x0044D880
void __fastcall sub_0044D880_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D900
void __fastcall GAME_ApplyConfigRealm(D2ConfigStrc* pConfig)
{
    SStrCopy(gszRealm_007A0500, pConfig->szRealm, 0x20);
}

// 0x0044D920
void __fastcall GAME_ApplyConfigSetClientFlag(D2ConfigStrc* pConfig)
{
    ROSTER_SetPrimaryClientFlag(0);
}

// 0x0044D930
void __fastcall sub_0044D930_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D940
void __fastcall sub_0044D940_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D950
void __fastcall sub_0044D950_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D960
void __fastcall GAME_ApplyConfigCTemp(D2ConfigStrc* pConfig)
{
    ROSTER_SetCTemp(pConfig->nCTemp);
}

// 0x0044D970
void __fastcall GAME_ApplyConfigComInterface(D2ConfigStrc* pConfig)
{
    if (pConfig->pComInterface)
        gpComInterface = pConfig->pComInterface;
}

// 0x0044D980
void __fastcall sub_0044D980_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D990
void __fastcall sub_0044D990_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D9A0
void __fastcall GAME_ApplyConfigNoCompress(D2ConfigStrc* pConfig)
{
    if (pConfig->bNoCompress)
        D2CMPSetNoCompress(pConfig->bNoCompress);
}

// 0x0044D9C0
void __fastcall GAME_ApplyConfigTxt(D2ConfigStrc* pConfig)
{
    DATATBLS_ToggleCompileTxtFlag(!pConfig->bTxt);
}

// 0x0044D9E0
void __fastcall sub_0044D9E0_ApplyConfigNop(D2ConfigStrc* pConfig)
{
}

// 0x0044D9F0
int __fastcall GAME_RunInitHandlers(void* pArg)
{
    gbInitHandlersResult = 1;
    for (unsigned int i = 0; i < 52; i++)
    {
        if (gpfnInitHandlers[i])
            gpfnInitHandlers[i](pArg);
    }
    return gbInitHandlersResult;
}

// 0x0044DA30
int __cdecl GAME_IsExitPending()
{
    return gbLeavingGame;
}

// 0x0044DA40
void __cdecl GAME_ResetMouseState()
{
// build: symbol ?gnRightClickState@* 0x0070F2BC
    gnRightClickState = 0x10;
    gnLeftClickState = 0x10;
    gbLeftButtonDown = 0;
    gbRightButtonDown = 0;
    gbLeftClickRepeating = 0;
    gbRightClickConsumed = 0;
    SELECT_ClearSelection();
}

// 0x0044DA70
void __cdecl GAME_ResetMouseButtons()
{
    gbLeftButtonDown = 0;
    gbRightButtonDown = 0;
    gbLeftClickRepeating = 0;
    gbRightClickConsumed = 0;
}

// 0x0044DA90
int __cdecl sub_0044DA90()
{
    return gnTickCounter;
}

// 0x0044DAA0
int __cdecl GAME_GetCurrentTime()
{
    return gdwTickCount;
}

// 0x0044DAB0
int __cdecl sub_0044DAB0()
{
    return gdwGlobal_007A0494;
}

// 0x0044DAC0
int __cdecl GAME_GetInteractDeadline()
{
    return gnInteractDeadline;
}

// 0x0044DAD0
void __fastcall GAME_SetInteractDeadline(int nValue)
{
    gnInteractDeadline = nValue;
}

// 0x0044DAE0
int __cdecl GAME_GetFramesPerSecond()
{
    return gnFramesPerSecond;
}

// 0x0044DAF0
int __cdecl GAME_GetSkippedFrames()
{
    return gdwGlobal_007A04B0;
}

// 0x0044DB00
int __cdecl sub_0044DB00()
{
    return gnTickCounter;
}

// 0x0044DB10
int __cdecl GAME_GetPathFrame()
{
    return gnPathFrame;
}

// 0x0044DB20
int __cdecl sub_0044DB20()
{
    return gdwGlobal_007A0488;
}

// 0x0044DB30
int __cdecl GAME_GetConnectionType()
{
    return gdwGlobal_007A0610;
}

// 0x0044DB40
void __fastcall GAME_ExtendDelay(int nDelay)
{
    const unsigned long dwEnd = GetTickCount() + nDelay;
    if (dwEnd > gdwDelayEnd)
        gdwDelayEnd = dwEnd;
}

// 0x0044DBE0
void __cdecl GAME_ReadColorFlag()
{
    if (gbColorFlag == 0)
    {
        void* hFile;
        if (ARCHIVE_OpenFile(0, "Data\\Local\\Color.txt", &hFile, 1))
        {
            char nFlag;
            ARCHIVE_ReadFileToBuffer(0, hFile, &nFlag, 1);
            ARCHIVE_CloseFile(0, hFile);
            if (nFlag == '1')
                gbColorFlag = 1;
        }
    }
}

// 0x0044DC40
void __cdecl GAME_ToggleColorFlag()
{
    gbColorFlag = !gbColorFlag;
}

// 0x0044DC60
int __cdecl GAME_GetColorFlag()
{
    return gbColorFlag;
}

// 0x0044DC70
void __fastcall GAME_SetDifficulty(unsigned char nDifficulty)
{
    gnClientDifficulty = nDifficulty;
}

// 0x0044DC80
void __fastcall GAME_SetExpansion(unsigned char nValue)
{
    gbExpansion = nValue;
}

// 0x0044DC90
void __fastcall GAME_SetLadderFlag(int nValue)
{
    gbLadder = nValue;
}

// 0x0044DCA0
int __cdecl GAME_GetLadderFlag()
{
    return (gdwGlobal_007A0610 >= 2 && gdwGlobal_007A0610 <= 3) ? gbLadder : 1;
}

// 0x0044DCC0
int __cdecl GAME_IsExpansion()
{
    return gbExpansion;
}

// 0x0044DCD0
unsigned char __cdecl GAME_GetDifficulty()
{
    return gnClientDifficulty;
}

// 0x0044DD60
void __cdecl GAME_ExitForCinematic()
{
    WINMAIN_SetExitApplication(0);
    gbCinematicExit = 1;
    sub_00477EE0();
    gbLeavingGame = 1;
}

// 0x0044DD90
D2StormLinkStrc* D2StormLinkStrc::sub_0044DD90_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0044DDC0
char* __fastcall sub_0044DDC0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0044DDD0
sub_0044DDD0::~sub_0044DDD0()
{
    f_0.Unlink();
}

// 0x0044DE10
D2StormListAStrc* D2StormListArrayStrc::sub_0044DE10_At(unsigned int nIndex)
{
    return &m_data[nIndex];
}

// 0x0044DE30
char* __fastcall sub_0044DE30_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x0044DE40
int __cdecl sub_0044DE40()
{
    return 4;
}

// 0x0044DE50
void __fastcall sub_0044DE50(PairStrc_0044DE50* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0044DE60
D2StormLinkStrc* D2StormLinkStrc::sub_0044DE60_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0044DE90
sub_0044DE90::~sub_0044DE90()
{
    f_0.Unlink();
}

// 0x0044DED0
char* __fastcall sub_0060E280_AddLinkOffset(char* pNode, int nLinkOffset)
{
    return pNode + nLinkOffset;
}

// 0x0044DEE0
void __fastcall sub_0044DEE0(PairStrc_0044DEE0* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0044DF00
void __fastcall sub_0044DF00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0044DF10
D2Warden47F930Strc::D2Warden47F930Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
}

// 0x0044DF20
void __fastcall sub_0044DF20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

// 0x0044DF70
unsigned int __stdcall GAME_RoundUpToMultiple(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

// 0x0044DF90
void D2StormListAStrc::sub_0044DF90_CopyLinkOffset(const D2StormListAStrc* pSource)
{
    m_linkoffset = pSource->m_linkoffset;
    InitializeTerminator();
}

// 0x0044DFB0
unsigned int D2TickTimerStrc::GetRemaining()
{
    unsigned int dwNow = GetTickCount();
    if (dwNow >= dwStart + dwDuration)
    {
        dwStart = 0;
        dwDuration = 0;
        return 0;
    }
    return dwStart + dwDuration - dwNow;
}

// 0x0044DFF0
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

// 0x0044E040
int __fastcall GAME_IsTimerRunning(D2LoadingTimerStrc* pTimer)
{
    return !GAME_IsTimerExpired(pTimer);
}

// 0x0044E0B0
void __stdcall GAME_HandleCloseMessage(SMSGHANDLER_PARAMS* pMsg)
{
    gbRunKeyHeld = 0;
    if (gbLeavingGame)
    {
        UI_FreePlayerUI();
        SELECT_ResetHoverClassIds();
        pMsg->bReturn = 0;
        return;
    }
    sub_00477EE0();
    gbCinematicExit = 1;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

D2WardenModuleHolderAStrc::~D2WardenModuleHolderAStrc()
{
}

WardenModule::WardenModule()
{
    pImage = 0;
    unk0x04 = 0;
    nImports = 0;
    unk0x0C = 0;
    f_10 = 0;
}

D2WardenModuleHolderBStrc::~D2WardenModuleHolderBStrc()
{
}

// build: symbol ?WARDENCLIENT_AllocLoaderMemory@* 0x0047FBF0
void* __fastcall WARDENCLIENT_AllocLoaderMemory(unsigned int nSize)
{
    return SMemAlloc(nSize, szWardenClientFile_006D8E18, 0x10D, 0);
}

// build: symbol ?WARDENCLIENT_FreeLoaderMemory@* 0x0047FC10
void __fastcall WARDENCLIENT_FreeLoaderMemory(void* pMemory)
{
    SMemFree(pMemory, szWardenClientFile_006D8E18, 0x117, 0);
}

namespace NWardenClient
{
struct Library
{
    Library();
    virtual void Slot00() = 0;
    virtual void Draw() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
};
}

NWardenClient::Library::Library()
{
}

// 0x0044E100
void __fastcall GAME_LoadAct(unsigned char nAct, unsigned int dwGameSeed, unsigned int dwObjectSeed, int nTownLevelId)
{
    GAME_PreloadActTiles(nAct);
    if (gpAct)
        DUNGEON_FreeAct(gpAct);

    gpAct = DUNGEON_AllocAct(nAct, dwGameSeed, 1, 0, gnClientDifficulty, 0, nTownLevelId,
        (AUTOMAPFN)AUTOMAP_RevealRoomCallback, AUTOMAP_AddTownCelsCallback);

    if (gbEnvironmentPending && nAct == 1 && gpAct)
        ENVIRONMENT_InitializeEnvironment(gpAct, CUNIT_GetPlayerRoom(), 5, 0, 1);

    gbEnvironmentPending = 0;
    UI_SetLoadingAct(nAct);
    UI_DrawLoadingScreen(1);

    *gpAutomapRecord = D2AutomapRecordStrc();
    gpAutomapRecord->nGameSeed = dwGameSeed;
    gpAutomapRecord->nValue = dwObjectSeed;

    AUTOMAP_InitAutomapColors();
    DLIGHTMAP_InitLightTables();
    GAME_InitColors();
    gnTownLevelId = nTownLevelId;
    GFX_FreeActHashedFile();
    GFX_LoadGlobalHashedFile(nAct);
// build: symbol ?gnClearScreenCount@* 0x0070F2C0
    gnClearScreenCount = 1;

    const unsigned long dwEnd = GetTickCount() + 10000;
    if (dwEnd > gdwDelayEnd)
        gdwDelayEnd = dwEnd;
}

void __cdecl GAME_InitGameState(); // 0x0044E200

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

// 0x0044EC50
void __cdecl GAME_ResetBetaScreen()
{
    gnBetaScreens = 1;
    gnBetaScreenIndex = 0;
    sub_00477EE0();
    gbLeavingGame = 1;
}

// 0x0044EC80
void __cdecl GAME_SetDifficultyFlags()
{
    gnDifficultyDirty = 1;
    gpClientConfig->wFlags1EF = ((gnClientDifficulty + 1) << 10) | (gpClientConfig->wFlags1EF & 0xE0FF);
}

sub_00601BF0::~sub_00601BF0()
{
    f_0.Unlink();
}

sub_00601C70::~sub_00601C70()
{
    f_0.Unlink();
}

sub_00601D60::~sub_00601D60()
{
    f_0.Unlink();
}

sub_00601F10::sub_00601F10()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00601F20::~sub_00601F20()
{
    f_0.Unlink();
}

sub_00601F60::~sub_00601F60()
{
    f_0.Unlink();
}

sub_006020D0::~sub_006020D0()
{
    f_0.Unlink();
}

sub_00602130::sub_00602130()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00602140::~sub_00602140()
{
    f_0.Unlink();
}

sub_00602180::sub_00602180()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00602420::sub_00602420()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_006024A0::~sub_006024A0()
{
    f_0.Unlink();
}

sub_00602750::sub_00602750()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

sub_00602760::~sub_00602760()
{
    f_0.Unlink();
}

// 0x0044ECC0
sub_0044ECC0::~sub_0044ECC0()
{
    f_0.Unlink();
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

// 0x0044ED00
char* D2ChatStormListAStrc::IGNORELIST_GetStringListHead()
{
    return m_terminator.MaskNext();
}

// 0x0044ED20
D2StormLinkStrc* D2StormListAStrc::sub_0044ED20_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x0044ED40
sub_0044ED40::sub_0044ED40()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044ED50
sub_0044ED50::~sub_0044ED50()
{
    f_0.Unlink();
}

// 0x0044ED90
sub_0044ED90::sub_0044ED90()
{
    f_0.m_prevlink = 0;
    f_0.m_next = 0;
}

// 0x0044EDA0
D2StormLinkStrc* D2StormListBStrc::sub_0044EDA0_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
}

// 0x0044EDC0
void D2StormListAStrc::sub_0044EDC0_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0044EE10
void D2StormListAStrc::sub_0044EE10_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0044EE30
void D2StormListBStrc::sub_0044EE30_InitLinkField(int nLinkOffset)
{
    m_linkoffset = nLinkOffset;
    InitializeTerminator();
}

// 0x0044EE50
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0044EE90
D2StormListAStrc::D2StormListAStrc(const D2StormListAStrc& source)
{
    m_linkoffset = source.m_linkoffset;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

inline void* __cdecl operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// build: symbol ?WARDENCLIENT_SwapBytes@* 0x0047F8B0
void __fastcall WARDENCLIENT_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

inline void __cdecl operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// The game list's Storm template members (D2Client keeps its games in a TSExportTableSync over
// TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0>), in the order the object has them.
// build: symbol ??1?$TSHashObject@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x0044F820
// build: symbol ?UnlinkNode@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXPAUSGAMEDATA@@@Z 0x0044F890
// build: symbol ?UnlinkAll@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXXZ 0x0044F8E0
// build: symbol ?UnlinkAll@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEXXZ 0x0044F930
// build: symbol ?ChangeLinkOffset@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXH@Z 0x0044F980
// build: symbol ??0?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAE@XZ 0x0044F9B0
// build: symbol ??0?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAE@XZ 0x0044F9D0
// build: symbol ??1SGAMEDATA@@QAE@XZ 0x0044F9F0
// build: symbol ?InternalClear@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAEXH@Z 0x0044FA00
// build: symbol ??1?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAE@XZ 0x0044FA90
// build: symbol ??1?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAE@XZ 0x0044FAD0
// build: symbol ??0?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@QAE@XZ 0x0044FB10
// build: symbol ??0?$TSExplicitList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@$0BA@@@QAE@XZ 0x0044FB30
// build: symbol ??0?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAE@ABU0@@Z 0x0044FB80
// build: symbol ??_GSGAMEDATA@@QAEPAXI@Z 0x0044FBB0
// build: symbol ??1?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@QAE@XZ 0x0044FBE0
// build: symbol ??1?$TSExplicitList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@$0BA@@@QAE@XZ 0x0044FC20
// build: symbol ?Clear@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXXZ 0x0044FC60
// build: symbol ??_G?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@QAEPAXI@Z 0x0044FCF0
// build: symbol ?Destruct@?$TSCD@USGAMEDATA@@@@SIXPAUSGAMEDATA@@@Z 0x0044FD50
// build: symbol ?Construct@?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@SIXPAV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@Z 0x0044FB50
// build: symbol ?CopyConstruct@?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@SIXPAV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@ABV2@@Z 0x0044FD60
// build: symbol ?Construct@?$TSCD@USGAMEDATA@@@@SIXPAUSGAMEDATA@@@Z 0x00450D30
// build: symbol ?CopyConstruct@?$TSCD@USGAMEDATA@@@@SIXPAUSGAMEDATA@@ABU2@@Z 0x00450D50
// build: symbol ??1?$TSFixedArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAE@XZ 0x0044FD80
// build: symbol ?Destruct@?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@SIXPAV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@Z 0x0044FDD0
// build: symbol ?ReallocData@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXI@Z 0x0044FE10
// build: symbol ??1?$TSFixedArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x0044FF60
// build: symbol ??1?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAE@XZ 0x0044FFE0
// build: symbol ??1?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x0044FFF0
// build: symbol ??0?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x00450030
// build: symbol ?Reserve@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXIH@Z 0x00450040
// build: symbol ??1?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAE@XZ 0x00450090
// build: symbol ??_G?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@QAEPAXI@Z 0x004500A0
// build: symbol ?SetCount@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXI@Z 0x00450110
// build: symbol ??1?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAE@XZ 0x00450210
// build: symbol ?LinkNode@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEXPAUSGAMEDATA@@I0@Z 0x004502A0
// build: symbol ??0?$TSHashObject@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x00450350
// build: symbol ??0SGAMEDATA@@QAE@XZ 0x00450370
// build: symbol ?NewNode@?$TSList@USGAMEDATA@@U?$TSGetExplicitLink@USGAMEDATA@@@@@@QAEPAUSGAMEDATA@@III@Z 0x00450390
// build: symbol ?InternalDelete@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEXPAUSGAMEDATA@@@Z 0x004503F0
// build: symbol ?InternalNew@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEPAUSGAMEDATA@@PAV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@II@Z 0x00450420
// build: symbol ??_G?$TSFixedArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEPAXI@Z 0x004504D0
// build: symbol ?Clear@?$TSFixedArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEXXZ 0x00450500
// build: symbol ?Destroy@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEXXZ 0x00450520
// build: symbol ??_G?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@UAEPAXI@Z 0x00450550
// build: symbol ?Clear@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEXXZ 0x00450580
// build: symbol ?DeleteChunksAndReuse@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@QAEXXZ 0x00450690
// build: symbol ??0?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x004506B0
// build: symbol ?CalcChunkSize@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEII@Z 0x00450810
// build: symbol ?RoundUp@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@SGIII@Z 0x00450850
// build: symbol ??0?$TSBaseArray@USGAMEDATA@@@@QAE@XZ 0x00450870
// build: symbol ?LinkNode@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEXPAV?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@I0@Z 0x004508A0
// build: symbol ??0SGAMEDATA@@QAE@ABU0@@Z 0x00450950
// build: symbol ?Clear@?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@QAEXXZ 0x00450D20
// build: symbol ?InternalDelete@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEXPAUSGAMEDATA@@@Z 0x00450D60
// build: symbol ?ReallocData@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEXI@Z 0x00450D90
// build: symbol ?Reserve@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEXIH@Z 0x00450E70
// build: symbol ??0?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAE@XZ 0x00450EC0
// build: symbol ?New@?$TSGrowableArray@USGAMEDATA@@U?$TSCD@USGAMEDATA@@@@@@QAEPAUSGAMEDATA@@XZ 0x00450ED0
// build: symbol ??0?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@QAE@XZ 0x00450F80
// build: symbol ?NewNode@?$TSList@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@U?$TSGetExplicitLink@V?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@@@@QAEPAV?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@III@Z 0x00450FA0
// build: symbol ?InternalNew@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEPAUSGAMEDATA@@PAV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@II@Z 0x00451000
// build: symbol ?Destroy@?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEXXZ 0x004510B0
// build: symbol ??_G?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@UAEPAXI@Z 0x004510D0
// build: symbol ??1?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@UAE@XZ 0x00451160
// build: symbol ??0?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@QAE@XZ 0x00451170
// build: symbol ??_G?$TSExportTableSimple@USGAMEDATA@@PAUHSGAMEDATA__@@$0A@@@UAEPAXI@Z 0x004511A0
// build: symbol ??1?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@UAE@XZ 0x004511D0
// build: symbol ??0?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@QAE@XZ 0x004511F0
// build: symbol ??_G?$TSExportTableSync@USGAMEDATA@@PAUHSGAMEDATA__@@PAUHSGAMEDATALOCK__@@VCCritSect@@$0A@@@UAEPAXI@Z 0x00451220
// build: symbol __imp__InitializeCriticalSection@4 0x006CC210
// build: symbol __imp__DeleteCriticalSection@4 0x006CC1FC
// build: symbol ??_7?$TSHashTable@USGAMEDATA@@VHASHKEY_NONE@@@@6B@ 0x006D5E5C
// build: symbol ??_7?$TSHashTableReuse@USGAMEDATA@@VHASHKEY_NONE@@$0A@@@6B@ 0x006D5E70
// build: symbol ??_R0?AUSGAMEDATA@@@8 0x0070F564
// build: symbol ??_R0?AV?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@8 0x0070F57C
// build: symbol ??_R0?AV?$TSHashObjectChunk@USGAMEDATA@@VHASHKEY_NONE@@@@@8 0x0070F5EC
// build: symbol ?CalcChunkSize@?$TSGrowableArray@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@U?$TSCD@V?$TSExplicitList@USGAMEDATA@@$0?CCCCCCCD@@@@@@@QAEII@Z 0x0044DF30
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol _SMemReAlloc@20 0x004133D0
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::UnlinkNode(SGAMEDATA*);
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::UnlinkAll();
template void TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::UnlinkAll();
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::ChangeLinkOffset(int);
template TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::TSList();
template TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::TSList();
template void D2SGameDataTable::InternalClear(int);
template TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::~TSList();
template TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::~TSList();
template TSExplicitList<SGAMEDATA, STORM_EXPLICIT_LIST_UNSET>::TSExplicitList();
template TSExplicitList<D2SGameDataChunk, 0x10>::TSExplicitList();
template TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::TSList(const TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >&);
template TSExplicitList<SGAMEDATA, STORM_EXPLICIT_LIST_UNSET>::~TSExplicitList();
template TSExplicitList<D2SGameDataChunk, 0x10>::~TSExplicitList();
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::Clear();
template TSGrowableArray<D2SGameDataList>::TSGrowableArray();
template void TSGrowableArray<D2SGameDataList>::ReallocData(unsigned int);
template void TSGrowableArray<D2SGameDataList>::Reserve(unsigned int, int);
template TSGrowableArray<D2SGameDataList>::~TSGrowableArray();
template void TSGrowableArray<D2SGameDataList>::SetCount(unsigned int);
template TSGrowableArray<SGAMEDATA>::~TSGrowableArray();
template D2SGameDataChunk::~TSHashObjectChunk();
template void TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::LinkNode(SGAMEDATA*, unsigned int, SGAMEDATA*);
template TSHashObject<SGAMEDATA, HASHKEY_NONE>::TSHashObject();
template SGAMEDATA* TSList<SGAMEDATA, TSGetExplicitLink<SGAMEDATA> >::NewNode(unsigned int, unsigned int, unsigned int);
template void TSFixedArray<D2SGameDataList>::Clear();
template void TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::Clear();
template void D2SGameDataReuseTable::DeleteChunksAndReuse();
template D2SGameDataTable::TSHashTable();
template D2SGameDataReuseTable::~TSHashTableReuse();
template unsigned int TSGrowableArray<SGAMEDATA>::CalcChunkSize(unsigned int);
template unsigned int __stdcall TSGrowableArray<SGAMEDATA>::RoundUp(unsigned int, unsigned int);
template TSBaseArray<SGAMEDATA>::TSBaseArray();
template void TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::LinkNode(D2SGameDataChunk*, unsigned int, D2SGameDataChunk*);
template void D2SGameDataTable::Clear();
template void TSGrowableArray<SGAMEDATA>::ReallocData(unsigned int);
template void TSGrowableArray<SGAMEDATA>::Reserve(unsigned int, int);
template TSGrowableArray<SGAMEDATA>::TSGrowableArray();
template SGAMEDATA* TSGrowableArray<SGAMEDATA>::New();
template void __fastcall TSCD<D2SGameDataList>::Construct(D2SGameDataList*);
template void __fastcall TSCD<D2SGameDataList>::CopyConstruct(D2SGameDataList*, const D2SGameDataList&);
template void __fastcall TSCD<D2SGameDataList>::Destruct(D2SGameDataList*);
template void __fastcall TSCD<SGAMEDATA>::Construct(SGAMEDATA*);
template void __fastcall TSCD<SGAMEDATA>::CopyConstruct(SGAMEDATA*, const SGAMEDATA&);
template void __fastcall TSCD<SGAMEDATA>::Destruct(SGAMEDATA*);
template D2SGameDataChunk* TSList<D2SGameDataChunk, TSGetExplicitLink<D2SGameDataChunk> >::NewNode(unsigned int, unsigned int, unsigned int);
template D2SGameDataReuseTable::TSHashTableReuse();
template D2SGameDataExportTable::TSExportTableSimple();
template D2SGameDataSyncTable::TSExportTableSync();

// Helpers of the table's types whose template form isn't settled keep their own names.
struct D2SGameDataArrayHolderStrc
{
    TSGrowableArray<SGAMEDATA> m_array;

    SGAMEDATA* sub_00450F70_New();
    void sub_00450F50_ReserveExact(unsigned int nCount);
};

// 0x00450F50
void D2SGameDataArrayHolderStrc::sub_00450F50_ReserveExact(unsigned int nCount)
{
    unsigned int nTotal = m_array.m_count + nCount;
    if (nTotal > m_array.m_alloc)
        m_array.ReallocData(nTotal);
}

// 0x00450F70
SGAMEDATA* D2SGameDataArrayHolderStrc::sub_00450F70_New()
{
    return m_array.New();
}

struct D2SGameDataListArrayHolderStrc
{
    TSGrowableArray<D2SGameDataList> m_array;

    void sub_00450680_SetCount(unsigned int nCount);
};

struct D2SGameDataPairStrc
{
    unsigned int nFirst;
    unsigned int nSecond;

    unsigned int sub_00450800_GetDifference();
};

struct D2SGameDataArrayOwnerStrc
{
    unsigned int unk0x00;
    TSGrowableArray<SGAMEDATA> m_array;

    D2SGameDataArrayOwnerStrc(int nUnused);
};

// 0x00450680
void D2SGameDataListArrayHolderStrc::sub_00450680_SetCount(unsigned int nCount)
{
    m_array.SetCount(nCount);
}

// 0x00450800
unsigned int D2SGameDataPairStrc::sub_00450800_GetDifference()
{
    return nFirst - nSecond;
}

// 0x00450880
D2SGameDataArrayOwnerStrc::D2SGameDataArrayOwnerStrc(int nUnused)
{
}

// 0x00451F10
int __cdecl GAME_PushRegisterState()
{
    return SMsgPushRegisterState((int)WINDOW_GetWindow());
}

// 0x00451F20
void __cdecl GAME_RegisterWindowHandlers()
{
// build: symbol ?SMsgPopRegisterState@* 0x00420320
    SMsgPopRegisterState(WINDOW_GetWindow());
}

struct Pad40_00451F30;

struct Obj00451F30;

struct Obj00451F70;

struct D2MonStats2Txt;

struct D2StatesTxt;

struct Pad40_00451F30 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00451F30 {
    Pad40_00451F30 tPad000;
    Pad40_00451F30 tPad040;
    Pad40_00451F30 tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwFlagsC4;
};

struct Obj00451F70 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int dwValue10;
};

// 0x00451F30
extern "C" __declspec(dllexport) int __fastcall sub_00451F30(Obj00451F30* pObj, unsigned int dwMask) {
    if (!pObj) {
        return 0;
    }
    return (pObj->dwFlagsC4 & dwMask) != 0;
}

// 0x00451F50
int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// 0x00451F60
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

// 0x00451F70
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00451F70(Obj00451F70* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue10;
}

// 0x00451F80
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

void __cdecl GAME_InitColors(); // 0x00452130

struct D2CelFileStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

// 0x00451FB0
D2MonStats2Txt* __fastcall GAME_GetMonStats2TxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nId];
    }
    return 0;
}

// 0x00451FE0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nId = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nId >= 0 && nId < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nId];
        }
    }
    return 0;
}

// 0x00452020
int __fastcall GAME_GetOverlayTxtRecordCount()
{
    return sgptDataTables->nOverlayTxtRecordCount;
}

// 0x00452030
int __fastcall GAME_GetItemStatCostTxtRecordCount()
{
    return sgptDataTables->nItemStatCostTxtRecordCount;
}

// 0x00452040
extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x00452070
int* __fastcall GAME_ClearBlock(int* pData)
{
    for (int i = 0; i < 0x80; ++i)
    {
        pData[i] = 0;
    }

    return pData;
}

// 0x004520C0
void* __fastcall GAME_LoadUiCelFile(const char* szFile)
{
    char szPath[0x104];
// build: symbol ?gszDataGlobal@* 0x006D4118
    wsprintfA(szPath, "%s\\UI\\", gszDataGlobal);
    char* pDest = &szPath[SStrLen(szPath)];
    const char* pSrc = szFile;
    while (*pSrc)
        *pDest++ = *pSrc++;
    *pDest = 0;
    return ARCHIVE_LoadClientCellFile(szPath, 0);
}

// 0x00452160
void __cdecl sub_00452160_Nop()
{
}

// 0x00452170
Unicode* __fastcall sub_00452170(Unicode* pText)
{
    return pText;
}

// 0x00452180
void __fastcall GAME_StrToUpper(Unicode* pText)
{
    if (!pText)
        return;
    const int nLength = sub_00526800(pText);
    for (int i = 0; i < nLength; i++)
    {
        const unsigned short wChar = pText[i].wChar;
        pText[i].wChar = wChar >= 0x100 ? wChar : gawToUpperTable[wChar];
    }
}

// 0x00452520
void __fastcall GAME_SetHoverLine(const Unicode* pText, int nColor)
{
    if (!pText)
    {
        gwszHoverLine_007A2D30[0].wChar = 0;
        return;
    }
    sub_005267E0(gwszHoverLine_007A2D30, pText);
    gnHoverTextColor = nColor;
}

// 0x00453060
void __cdecl GAME_DrawPopUpText()
{
    if (!sub_00526800(gwszPopUpText))
        return;
    const int nWidth = D2Win_10121_GetTextWidth(gwszPopUpText) + 8;
    const int nHeight = D2Win_10125() + 7;
    int nX = gnPopUpTextX - (nWidth >> 1);
    int nY = gnPopUpTextY + 2;
    if (nX < 0)
        nX = 0;
    if (nX + nWidth > gnScreenWidth)
        nX = gnScreenWidth - nWidth;
    if (nY - nHeight < 0)
        nY = nHeight;
    if (nY > gnScreenHeight - 0x1F)
        nY = gnScreenHeight - 0x1F;
    D2Win_10117_DrawText(gwszPopUpText, nX, nY - 2, 0, 1);
    memset(gwszPopUpText, 0, sizeof(gwszPopUpText));
}

// 0x004538D0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar)
{
    D2_ASSERT(nUIVar < 0x26, 0xC34);
    return gaUIVarStates[nUIVar];
}

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

#include "gen/data/Source/D2Client/GAME/Game.inc"
// 0x006CB400
void __cdecl sub_006CB400_Nop()
{
}

