#include "SGAMEDATA.h"
#include "D2Client.h"
#include "D2PongData.h"
#include "D2ClientFuncs.h"
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
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2SysTypes.h"
#include "D2CelContext.h"
#include "D2CommonApi2.h"
#include "FogApi2.h"
#include "D2WinSplitText.h"
#include "D2WinApi.h"
#include "D2CMPApi.h"
#include "D2SoundApi.h"
#include "D2NetApi.h"
#include "D2HellApi.h"
#include "D2MCPClientApi2.h"
#include "D2WinApi2.h"
#include "D2LaunchApi.h"
#include "D2MultiApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
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

struct HANDLER;

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

extern int gfCharSelCancelled; // 0x0077AC04

extern int gdwGlobal_0077BBF8; // 0x0077BBF8

extern char gszMcpGameServerIP[]; // 0x007992CC

extern int gnMcpGameToken; // 0x00798FB0

extern int gdwGlobal_0079929C; // 0x0079929C

extern int gdwMcpGameHash; // 0x00798F88

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

unsigned long gdwPing; // 0x007A04A4

unsigned long gdwPingAverage; // 0x007A04D0


extern int gdwGlobal_007A05F4; // 0x007A05F4

int gbLeavingGame; // 0x007A0620

unsigned int gdwTickCount; // 0x007A048C

int gnFramesPerSecond; // 0x007A04A8

extern int gdwGlobal_007A0488; // 0x007A0488

int gbColorFlag; // 0x007A05FC

int gbExpansion; // 0x007A04F4

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

int __stdcall GAME_UpdateGamesProgress(int bLimitCatchUp); // 0x0052FC20
void __cdecl GAME_RegisterWindowHandlers(); // 0x00451F20

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



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" int __cdecl abs(int nValue);

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800







void __fastcall CUNIT_DispatchMouseWheel(int nSteps); // 0x004693B0

void __cdecl sub_00469270_RunMButtonUp(); // 0x00469270

void __cdecl sub_00469230_RunMButtonDown(); // 0x00469230

void __cdecl sub_004692B0_RunXButton1Down(); // 0x004692B0

void __cdecl sub_00469330_RunXButton2Down(); // 0x00469330

void __cdecl sub_004692F0_RunXButton1Up(); // 0x004692F0

void __cdecl CMDTBL_CallBoundCommand(); // 0x00469370

int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30


void __cdecl SELECT_ResetHoverClassIds(); // 0x00467A00

unsigned char gnBetaScreenIndex; // 0x007A060D

int gbRightClickConsumed;                                                                                     // 0x007A0670

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

D2ClientCallbackFn gpfnClientCallback; // 0x007A0484

extern D2ClientCallbackFn gpfnClientCallbacks[3]; // 0x0070EF0C

extern int gbPlaybackRequested; // 0x007A277C


int gdwFpsWindowStart;                                                                                     // 0x007A04B8

int gbPositionalSound; // 0x007A061C

int gbClickHandled; // 0x007A0658









int __stdcall sub_00420290_BreakHandlerChain(void* pMsg); // 0x00420290

int gbEndScreenDismissed; // 0x007A0608

void __fastcall ROSTER_SetPrimaryClientFlag(int bClear); // 0x0047A9B0

extern char gszRealm[]; // 0x007A0500

void __cdecl sub_004776E0_SetModeValuesOne(); // 0x004776E0

void __cdecl D2GFX_DisableFixedAspectRatio(); // 0x004F5280

void __cdecl INV_SetRenderModeGlide(); // 0x004776F0

void __cdecl INV_SetRenderModeOpenGL(); // 0x00477700

void __cdecl INV_SetRenderModeDirect3D(); // 0x00477710

void __cdecl INV_SetRenderModeRave(); // 0x00477720

void __fastcall sub_004776C0_SetGamma(int nGamma); // 0x004776C0

void __cdecl D2GFX_EnableVSync(); // 0x004F5270


void __fastcall ROSTER_SetCTemp(int nValue); // 0x0047AA10

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

struct HANDLER
{
    D2StormLinkStrc f_0;
    HANDLER();
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

extern "C" const char szWardenClientFile[];

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


void __stdcall AUTOMAP_RevealRoomCallback(D2ActiveRoomStrc* pRoom); // 0x00459150

void __stdcall AUTOMAP_AddTownCelsCallback(int nLevelId, int nPickedFile, int nX, int nY); // 0x004591A0



void __cdecl GFX_FreeActHashedFile(); // 0x0046F440

void __cdecl DLIGHTMAP_InitLightTables(); // 0x00475B40

D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, D2PoolSystemStrc* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x006194A0

int gbBattleNetConnected; // 0x0077AC08

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



void __fastcall UI_ToggleListDialog(int nResolution); // 0x004549B0




extern D2McpPacketHandler gpfnMcpPacketHandlers[]; // 0x0070ED00

extern int gnSavedScreenWidth; // 0x00711474

extern void (__fastcall* gpfnMcpMotdCallback)(void* pArg); // 0x00799308

int gaStateStack[4]; // 0x007A0424

int gnStateStackCount; // 0x007A044C

extern int gnBeltUiRecordRow; // 0x007A5218


void __stdcall WINDOW_ShowAll(); // 0x004F5F60



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

int __cdecl FOG_CreateNewPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused); // 0x00409DD0






void __fastcall GAME_DrawGameView(void* pArg);                                                                   // 0x0044C990









void __fastcall CUNIT_SetPlayerUnit(D2UnitStrc* pUnit); // 0x00463D90












void __cdecl DLIGHTMAP_ClearLightGrid();                                                                                // 0x00474790



void __fastcall VIEW_SetViewPos(D2ViewStrc* pView, int nX, int nY);                                 // 0x004760A0

D2ViewStrc* __cdecl VIEW_CreateView();                                                                         // 0x00476B10



void __cdecl sub_00477DD0();                                                                                // 0x00477DD0

void __fastcall MSG_UploadSaveFile(int bAnimate);                                                    // 0x004781D0

void __cdecl CHAT_ResetChatHistory();                                                                                // 0x0047BD30




D2RecordHandlerFn __fastcall sub_005173D3_SetRecordHandler(D2RecordHandlerFn pfnHandler);                  // 0x005173D3

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0

extern "C" const char gszLngFileName[];                                                            // 0x006D5EE0

extern int gbInitHandlersResult;                                                                              // 0x0070F414

extern D2InitHandlerFn gpfnInitHandlers[52];                                                       // 0x0070F488


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern char gaClientState_007A0480[0x80];                                                                   // 0x007A0480

D2PoolSystemStrc* gpMemPool;                                                                       // 0x007A0488

unsigned int gdwNextKeepAliveTick; // 0x007A049C

unsigned long gdwLastPingTick; // 0x007A04A0

int gbLadder;                                                                                     // 0x007A04F8

extern int gdwUnloadCompleteTick;                                                                              // 0x007A0524

int gdwGameStartTick; // 0x007A05F8

extern int gbEndScreenDismissed;                                                                              // 0x007A0608

int gbActUnloaded; // 0x007A0624

int gnPlayCinematic;                                                                                     // 0x007A0628

int gnCinematicPlayed;                                                                                     // 0x007A062C

D2ViewStrc* gpClientView; // 0x007A0640

D2LoadingTimerStrc gtLoadingTimer;                                                                                     // 0x007A0684


extern void* ghAccelerators;                                                                             // 0x007A0708

extern D2RecordHandlerFn gpfnPrevHandler;                                                          // 0x007A2764

extern int gbRecordHandlerInstalled;                                                                              // 0x007A2780

extern int gbRecordPlaying;                                                                              // 0x007A2788

extern int gaUIVarStates[];                                                                        // 0x007A27C0

Unicode gwszPopUpText[80];                                                                              // 0x007A2C80

extern int gnPopUpTextX;                                                                              // 0x007A2D20

extern int gnPopUpTextY;                                                                              // 0x007A2D24

extern Unicode gwszHoverLine[];                                                                    // 0x007A2D30

extern int gnHoverTextColor;                                                                       // 0x007A2F30


int __stdcall D2GFX_Release(); // 0x004F5050

int __stdcall WINDOW_Destroy(); // 0x004F5900

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

extern "C" void __stdcall ENVIRONMENT_InitializeEnvironment(Context* context,Auxiliary* auxiliary,int mode,int angle,int flag); // 0x0061C240


extern "C" void __stdcall TEXT_FreeTextHeader(Allocation* allocation); // 0x006612A0


extern "C" Context* gContext; // 0x007A0634

extern "C" unsigned char gDeferred; // 0x007A060E

extern "C" unsigned int gCleanupState;

extern "C" Allocation* gAllocation;

extern "C" int gCoordinateBase;

extern "C" int gCoordinateOffset;

D2SGameDataSyncTable gtGameDataTable; // 0x007A0690

int __stdcall GAME_Shutdown(); // 0x0052C030

D2McpInfoStrc gtMcpInfo; // 0x0079910C

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);           // 0x006CC468
D2CriticalSectionStrc gtQServerLock; // 0x007A0468

int gbQServerStop; // 0x007A0648

int gbQServerRestart; // 0x007A064C

int gnWheelDelta; // 0x007A06F8

int gnClientState; // 0x007A0480

void __cdecl GAME_FreeLngModule(); // 0x00451290

D2ComInterfaceStrc* gpComInterface; // 0x007A05F4

unsigned long gdwDelayEnd; // 0x007A04BC

unsigned char gbEnvironmentPending; // 0x007A060E

D2DrlgActStrc* gpAct; // 0x007A0634

D2AutomapRecordStrc* gpAutomapRecord; // 0x007A0638

int gnTownLevelId; // 0x007A063C

int gnBetaScreens; // 0x007A0600

static int gnDifficultyDirty; // 0x007A0604

struct D2Storm4167B0Strc;
struct D2Storm4168F0Strc;
struct D2Storm416A90Strc;
struct D2FlagWordStrc;
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

int __stdcall WINMAIN_ProcessCommandLine(void* pArg); // 0x0044B6B0

int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc); // 0x004F8FC0

int __stdcall SCMD_WindowProc(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam); // 0x00451B30

void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80

extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80

extern int (__cdecl* gpfnLaunchStates[])(); // 0x0070EE54

extern unsigned short gwValue_0077905C;
struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};
struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};
struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};
struct D2FlagWordStrc
{
    unsigned short wFlags;
};
void* ghLaunchInstance; // 0x007A043C

char gszModulePath[260]; // 0x007A0320

int gnLaunchResult; // 0x007A0440

#pragma intrinsic(memset)
#pragma pack(push,1)
struct D2CharInfo { char pad[0xbd]; char name[0x132]; unsigned short flags; };
#pragma pack(pop)
D2CharInfo* __cdecl WINMAIN_GetClientInfo(); // 0x0044B7A0

extern unsigned char gnClass; // 0x007A0522

extern unsigned char gnDifficulty; // 0x007A060C

extern "C" char* __cdecl strcat(char*,const char*);
struct D2TileLibraryHeaderStrc;
struct D2QuestScreenStrc;
struct D2LoadingTimerStrc;
struct D2MsgHandlerEntryStrc;
struct D2MessageStrc;
struct D2CriticalSectionStrc;
struct D2VersionInfoStrc;
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
struct D2ComInterfaceStrc;
struct D2QuestScreenStrc
{
    char nLevelId[4];
    char nQuest[4];
    char szName[5];
};
extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

int __fastcall ROSTER_GetKillCount(D2StoredUnitRecordStrc* pEntry); // 0x00479B80

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __cdecl GAME_DrawEndGameTitle(); // 0x0044D3E0

void __cdecl GAME_DrawEndGameCharInfo(); // 0x0044E5A0

int __fastcall GAME_GetCenteredTextX(unsigned short nStringIndex, int nCenterX); // 0x0044D390

void __stdcall D2CMPLoadProjectRecord(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath); // 0x00600790

void __fastcall MSG_SetProgress(int nValue, int nDivisor); // 0x00478130

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall VIEW_InitLifeColors(int nMode); // 0x00492F40

extern "C" const char gszFormatD[]; // 0x006D57BC

extern int gnLineHeight; // 0x007111C8

extern D2QuestScreenStrc gaQuestScreens[]; // 0x0070F85C

extern int gnQuestScreens; // 0x0070F92C

extern D2CelFileStrc* gpLoadingScreen; // 0x007A2888

extern int gnLoadingFrame; // 0x007A2A6C

extern int gbLoadingScreenActive; // 0x007A2868

extern int gbLoadingAfterUnload; // 0x007A27B8

struct D2MessageStrc { void* hWnd; unsigned int uMessage,wParam,lParam,time; int x,y; };
struct D2VersionInfoStrc { unsigned long dwSize; char unknown04[144]; };
typedef int (__stdcall* D2IdleHandler)(int);
typedef unsigned long (__stdcall* D2ThreadProc)(void*);
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2VersionInfoStrc*); // 0x006CC1F8

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc*); // 0x006CC210

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void*,unsigned long,D2ThreadProc,void*,unsigned long,unsigned long*); // 0x006CC250

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2MessageStrc*,void*,unsigned int,unsigned int,unsigned int); // 0x006CC480

extern D2MsgHandlerEntryStrc gaGameWheelHandlers[1]; // 0x0070F2C4

extern D2MsgHandlerEntryStrc gaGameMouseHandlers[10]; // 0x0070F2D0

extern D2MsgHandlerEntryStrc gaMiddleButtonHandlers[2]; // 0x0070F348

extern D2MsgHandlerEntryStrc gaXButtonHandlers[2]; // 0x0070F360

extern D2MsgHandlerEntryStrc gaBetaScreenHandlers[7]; // 0x0070F3C0

extern D2MsgHandlerEntryStrc gaEndScreenHandlers[9]; // 0x0070F418

unsigned short gwJoinId; // 0x007A0520

extern D2VersionInfoStrc gtVersionInfo; // 0x007A0528

void* ghQServerThread; // 0x007A05BC

int gnServerHash; // 0x007A05C0

char gszGameName[20]; // 0x007A05DC

extern unsigned long gnThreadId; // 0x007A05F0

extern int gnGameType; // 0x007A0610

extern int gnVersionValid; // 0x007A0644

extern int gbQServerStop; // 0x007A0648

void __fastcall WINMAIN_PushStateValue(int); // 0x0044B440

int __stdcall GAME_ShowBetaScreens(int); // 0x0044D100

extern "C" void __cdecl GAME_UnregisterMouseHandlers(); // 0x0044DCE0

int __stdcall GAME_LoadingTimerCallback(int); // 0x0044E400

int __stdcall GAME_DrawEndGameScreen(int); // 0x0044E770

int __stdcall GAME_RunGameFrame(int); // 0x0044EFA0

int __cdecl RECORD_IsRecordingEnabled(); // 0x00451910

int __cdecl RECORD_IsPlaybackEnabled(); // 0x00451980

void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10

int __fastcall CURSOR_InitCursor(int); // 0x004680B0

void __cdecl DLIGHTMAP_BuildLerpTables(); // 0x00475DF0

void __fastcall sub_00477CA0_SendPacket67(const char*,int); // 0x00477CA0

void __fastcall INV_SendGameLogon(unsigned short wJoinId, int nServerHash); // 0x00477F70

int __cdecl DLIGHTMAP_GetClientFlags(); // 0x0047A990

void __fastcall SOUNDHDR_UpdateSoundSystem(int); // 0x00482260

void __cdecl SOUNDHDR_ShutdownSound(); // 0x00482940

void __fastcall INV_PlayCinematic(int); // 0x00482EF0

void __cdecl INV_ResetCinematicFlags(); // 0x00483310

int gbEndScreenButtonPressed; // 0x007A0680

D2CelFileStrc* gpLoadingCell; // 0x007A2794

D2CelFileStrc* gpBuySellButton; // 0x007A287C

static D2CelFileStrc* s_pEndGameCell; // 0x007A0700

static D2CelFileStrc* s_pEndGameOkCell; // 0x007A06FC

union D2SeedStrc;
struct D2SaveHeaderStrc;
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449

struct D2SaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
};
#pragma pack(push, 1)
#pragma pack(pop)
char gszClientCharName[16]; // 0x007A05C4

unsigned char* gpSaveBuffer; // 0x007A5224

unsigned int gnSaveBufferSize; // 0x007A5228

struct D2StoredUnitRecordStrc;

struct _RTL_CRITICAL_SECTION;
struct D2BetaScreenStrc;
#pragma pack(push, 1)
struct D2BetaScreenStrc
{
    unsigned long dwTick;
    D2CelFileStrc* pCelFile;
    unsigned char nAct;
    const char* szName;
};
#pragma pack(pop)
extern "C" int __cdecl strcmp(const char* s1, const char* s2);
extern int gnGameState; // 0x0070EF18
extern D2BetaScreenStrc gaBetaScreens[]; // 0x0070F238
extern int gnBetaScreenCount; // 0x0070F024
extern char gszServerIP[]; // 0x0070EF20
extern char gszMcpIP[]; // 0x0070F130
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
void __cdecl RECORD_FreeMsgRecordChunks(); // 0x00451850
void __cdecl ROSTER_FreeRosterLists(); // 0x004794B0
void __cdecl ROSTERPETS_FreeRosterPets(); // 0x00478A50
void __fastcall PLRSAVE_EnableSaveFileWriting(int nValue); // 0x00530F30
void __stdcall GAME_SetGlobalAct(int nAct); // 0x0052DFA0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
void __cdecl WINMAIN_DrainPacketQueues(); // 0x0044C6E0
int __fastcall sub_0044CCA0(unsigned int nFrames, unsigned int nRemainder, int nRate);
void __cdecl GAME_CheckConnectionTimeouts(); // 0x0044EEC0
void __cdecl RECORD_ReplayRecords(); // 0x004519C0
void __cdecl PLAYER_ClearCommandPending(); // 0x00462920
void __cdecl SELECT_UpdateHoverUnit(); // 0x00467AC0
int __cdecl CHAT_HandleBnetChatMessage(); // 0x0047BDF0
void __fastcall WARDENCLIENT_TickModule(int nDelta); // 0x00480320
void __fastcall UNITMODE_RunPendingAction(D2UnitStrc* pPlayer); // 0x00481600
extern unsigned int gdwFrameTime; // 0x0070EF1C
extern unsigned int gdwLastCheck_007A04A0; // 0x007A04A0
unsigned int gdwLastFrame; // 0x007A0490
int gnFrameCount; // 0x007A0494
int gnFpsFrameCount; // 0x007A04AC
int gnSkippedFrames; // 0x007A04B0
int gnFpsSkipCount; // 0x007A04B4
int gnGameType; // 0x007A0610
int gnSkipped; // 0x007A0704
struct D2ActInfoStrc;
struct D2RectStrc;
struct D2GSPacketSrv8F;
extern int gnLastViewX; // 0x0070F55C
extern int gnLastViewY; // 0x0070F558
extern int gnViewDeltaX; // 0x007A0678
extern int gnViewDeltaY; // 0x007A067C
extern void* gpGlobal_007A0634; // 0x007A0634
void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070
void __fastcall VIEW_AdjustViewPos(int* pX, int* pY); // 0x00476D40
void __fastcall VIEW_PrepareView(D2ViewStrc* pView, int nArg); // 0x00476140
void __cdecl sub_00473F50_UpdateWeather(); // 0x00473F50
void __stdcall ENVIRONMENT_GetLightColorFromAct(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0
void __stdcall D2GFX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x004F6430
void __cdecl AUTOMAP_UpdateAutomapOrigin(); // 0x0045B440
void __fastcall UI_DrawUIPanels(D2ViewStrc* pView); // 0x00456EE0
void __fastcall sub_00468820_Nop(int nArg1, int nArg2); // 0x00468820
void __fastcall sub_00477980_DrawFpsStats(); // 0x00477980
#pragma pack(push, 1)
#pragma pack(pop)
extern unsigned short gawLoadingStrings[]; // 0x0070F384
int gnLoadingIndex; // 0x007A05D4
D2PongDataStrc gtPongData; // 0x007A04D4
#pragma pack(push, 1)
struct D2GSPacketSrv8F
{
    unsigned char nHeader;
    D2PongDataStrc tData;
};
#pragma pack(pop)
typedef char D2MsgHandlerEntrySize[(sizeof(D2MsgHandlerEntryStrc) == 12) ? 1 : -1];
extern int gbGameServerReady; // 0x007A0618
void __cdecl GAME_DrawLoadingText(); // 0x0044CB60
unsigned long gdwPingSamples; // 0x007A04CC
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

static int GetRoomBlankScreen(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
        return 0;
    D2LevelsTxt* pTxt = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pTxt, 1502);
    return pTxt->dwBlankScreen;
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

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
}

static inline int TimerExpired(D2LoadingTimerStrc* pTimer)
{
    if(pTimer->dwLength)
    {
        unsigned long dwNow=GetTickCount();
        unsigned long dwLeft;
        if(dwNow>=pTimer->dwStart+pTimer->dwLength)
        {
            pTimer->dwStart=0;
            pTimer->dwLength=0;
            dwLeft=0;
        }
        else dwLeft=pTimer->dwLength-(dwNow-pTimer->dwStart);
        return dwLeft==0;
    }
    return 1;
}

static inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

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

HANDLER::HANDLER()
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
int __cdecl sub_0042F6D0_GetMenusDone()
{
    return gfMenusDone;
}

// 0x0042FA30
int __cdecl GAME_GetStopMainLoop()
{
    return gbStopMainLoop;
}

// 0x0043DB10
int __cdecl GAME_IsLaunchExpansion()
{
    return gdwGlobal_0077BBF8;
}

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


// 0x0044BDD0
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

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
void __fastcall sub_0044BE20_ClearPair(PairStrc_0044BE20* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0044BE30
unsigned short __fastcall GAME_SetFlagWordField(D2FlagWordStrc* pFlags, unsigned short nValue)
{
    pFlags->wFlags = (pFlags->wFlags & 0xE0FF) | (nValue << 8);
    return pFlags->wFlags;
}

// 0x0044BE50
int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    return nUnitType;
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
    return gnLeftClickState;
}

// 0x0044BF10
int __cdecl GAME_GetRightClickState()
{
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
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        int nFlags = 0;
        if (gbRunKeyHeld)
            nFlags = 8;
        if (gbAlwaysRun)
            nFlags |= 8;
        if (gbStandStillHeld)
            nFlags |= 4;
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            gbLeftButtonDown = PLAYER_PlayerCommand(0, pMsg->nXpos, pMsg->nYpos, nFlags);
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
    gnLeftClickState = 8;
    if (gbPositionalSound && gbLeftButtonDown && !gbClickHandled)
    {
        gbLeftClickRepeating = 1;
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        const int nFlags = sub_0044BEC0_GetClickFlags_static();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            PLAYER_PlayerCommand(1, sub_00468730(), sub_00468740(), nFlags);
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
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
            PLAYER_PlayerCommand(2, sub_00468730(), sub_00468740(), CLIENT_GetClickFlags_inl());
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
    if (sub_0045AE90_GetPanelSlideMode() == 2 && nX > 0 && nX < gnScreenWidth / 2 && nY > 0 && nY < gnScreenHeight - 0x2F)
    {
        bLeftPanel = 1;
    }
    return bLeftPanel;
}

// 0x0044C140
static inline int GAME_IsInRightPanel(int nX, int nY)
{
    int bRightPanel = 0;
    if (sub_0045AE90_GetPanelSlideMode() == 1 && nX > gnScreenWidth / 2 && nX < gnScreenWidth && nY > 0 && nY < gnAutomapHeight_007A521C)
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
    if (!gbPositionalSound || sub_0045AE90_GetPanelSlideMode() == 3)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    int bLeftPanel = 0;
    if (sub_0045AE90_GetPanelSlideMode() == 2 && nX > 0 && nX < gnScreenWidth / 2 && nY > 0 && nY < gnScreenHeight - 0x2F)
    {
        bLeftPanel = 1;
    }
    int bRightPanel = 0;
    if (sub_0045AE90_GetPanelSlideMode() == 1 && nX > gnScreenWidth / 2 && nX < gnScreenWidth && nY > 0 && nY < gnAutomapHeight_007A521C)
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
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    const int nFlags = sub_0044BEC0_GetClickFlags_static();
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        gbRightButtonDown = PLAYER_PlayerCommand(3, pMsg->nXpos, pMsg->nYpos, nFlags);
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
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        const int nFlags = CLIENT_GetClickFlags_inl();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
            PLAYER_PlayerCommand(4, sub_00468730(), sub_00468740(), nFlags);
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
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
        {
            gbRightButtonDown = PLAYER_PlayerCommand(5, pMsg->nXpos, pMsg->nYpos, pMsg->wParamLow);
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
        sub_00469270_RunMButtonUp();
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
        sub_00469230_RunMButtonDown();
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
            sub_004692B0_RunXButton1Down();
        else if (nCode == 2)
            sub_00469330_RunXButton2Down();
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
            sub_004692F0_RunXButton1Up();
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

// 0x0044C5E0
void __stdcall GAME_HandleActivateApp(SMSGHANDLER_PARAMS* pMessage)
{
    gbClientAppActive = pMessage->wParam;
    if (pMessage->wParam)
    {
        UI_SetUIVar(0xD, 1, 0);
        gbStandStillHeld = 0;
        SELECT_ClearSelection();
        D2Win_10176_StartPaletteFlash(0);
        pMessage->bReturn = 0;
        return;
    }

    if (CUNIT_HasHotkeyBinding(0x22, 1) && (static_cast<unsigned short>(GetAsyncKeyState(CUNIT_GetHotkeyBinding(0x22, 1))) & 0x8000) == 0)
    {
        gbRunKeyHeld = 0;
    }

    if (gnLeftClickState != 0x10)
    {
        GAME_ResetLeftClick();
    }

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
            VIEW_PopulateRoom(pRoom);
            VIEW_SpawnRoomPresets(pRoom);
            VIEW_ApplyDenOfEvilRoom(pRoom);
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
    VIEW_UpdateTimers();
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
    sub_00472BD0_FreeWeatherCels();
}

// 0x0044C890
void __cdecl GAME_ReleaseGameState()
{
    sub_00472BD0_FreeWeatherCels();
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
    sub_004723C0_FreeWeather();
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

// 0x0044C990
void __fastcall GAME_DrawGameView(int bNoCursor)
{
    UI_FreeLoadingScreen();
    if (WINDOW_GetState())
        return;

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
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

    D2Win_10179_UpdatePaletteFlash();
    AUTOMAP_UpdateAutomapOrigin();
    if (sub_0045AE90_GetPanelSlideMode() != 3)
        VIEW_PrepareSceneLighting(gpClientView);
    UI_DrawUIPanels(gpClientView);
    D2Win_UpdateAndDraw();
    sub_00468820_Nop(10, 10);
    if (!bNoCursor)
        CURSOR_DrawCursor();
    sub_00477980_DrawFpsStats();
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
        D2Win_10200(pLines);
    }
    D2Win_UpdateAndDraw();
    D2GFX_EndScene();
}

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

// 0x0044CCE0
void __cdecl GAME_AverageFrameCounters()
{
    const int nNow = gdwTickCount;
    if ((unsigned int)(nNow - gdwFpsWindowStart) > 3000)
    {
        gnFramesPerSecond = gnFpsFrameCount / 3;
        gnSkippedFrames = gnFpsSkipCount / 3;
        gdwFpsWindowStart = nNow;
        gnFpsFrameCount = 0;
        gnFpsSkipCount = 0;
    }
}

// 0x0044CD40
void __cdecl GAME_ResetFrameTimer()
{
    gdwFpsWindowStart = gdwTickCount;
    gnFramesPerSecond = 0x19;
    gnSkippedFrames = 0;
    gnFpsFrameCount = 0;
    gnFpsSkipCount = 0;
}

// 0x0044CD70
void __cdecl GAME_TickKeepAlive()
{
    const unsigned long dwNow = GetTickCount();
    if (gdwNextKeepAliveTick < dwNow)
    {
        sub_00477DD0();
        gdwLastPingTick = dwNow;
        // Both arms set the same interval, but the original still tests the config flag: its code reads
        // gpClientConfig and tests 0x1EF bit 2 with nothing depending on the result.
        if (gpClientConfig->wFlags1EF & 4)
            gdwNextKeepAliveTick = dwNow + 5000;
        else
            gdwNextKeepAliveTick = dwNow + 5000;
    }
}

// 0x0044CDB0
void __fastcall GAME_StorePong(const D2GSPacketSrv8F* pPacket)
{
    gtPongData.dwData0 = pPacket->tData.dwData0;
    gtPongData.dwData1 = pPacket->tData.dwData1;
    gtPongData.dwData2 = pPacket->tData.dwData2;
    gtPongData.dwData3 = pPacket->tData.dwData3;
    gtPongData.dwTick = pPacket->tData.dwTick;
    gtPongData.dwEncodedName0 = pPacket->tData.dwEncodedName0;
    gtPongData.dwEncodedName1 = pPacket->tData.dwEncodedName1;
    gtPongData.dwEncodedOffset = pPacket->tData.dwEncodedOffset;
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
    return gdwPing;
}

// 0x0044CE70
int __cdecl sub_0044CE70_GetPingAverage()
{
    return gdwPingAverage;
}

// 0x0044CE80
void* __cdecl sub_0044CE80_GetPongData()
{
    return &gtPongData;
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
    int bProgressed = 0;
    EnterCriticalSection(&gtQServerLock);
    int bStop = gbQServerStop;
    int bRestart = gbQServerRestart;
    LeaveCriticalSection(&gtQServerLock);
    while (!bStop)
    {
        if (bRestart)
        {
            GAME_ProcessNetworkMessages();
            bProgressed = GAME_UpdateGamesProgress(1);
            if (bProgressed)
                GAME_UpdateClients(0, 0);
        }
        if (bProgressed)
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
    GAME_CloseAllGames();
    GAME_UpdateClients(0, 1);
    DeleteCriticalSection(&gtQServerLock);
    OutputDebugStringA("Open server thread shut down\n");
    return 1;
}

// 0x0044D080
int __cdecl GAME_PushState()
{
    if (gnGameState == 5)
        WINMAIN_PushStateValue(gnGameState - 3);
    return gnGameState;
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

// 0x0044D100
int __stdcall GAME_ShowBetaScreens(int nArg)
{
    char szPath[0x104];
    D2GfxDataStrc tData;
    if (!WINDOW_GetState())
    {
        if (!D2GFX_StartDraw(1, 0, 0, 0))
            return 0;
        if (gnBetaScreenIndex < gnBetaScreenCount)
        {
            if (!gaBetaScreens[gnBetaScreenIndex].pCelFile)
            {
                wsprintfA(szPath, "%s\\ui\\betascreens\\%s", gszDataGlobal, gaBetaScreens[gnBetaScreenIndex].szName);
                gaBetaScreens[gnBetaScreenIndex].pCelFile = ARCHIVE_LoadClientCellFile(szPath, 0);
                gaBetaScreens[gnBetaScreenIndex].dwTick = GetTickCount();
                D2Win_10177(gaBetaScreens[gnBetaScreenIndex].nAct);
            }
            memset(&tData, 0, sizeof(tData));
            tData.pCelFile = gaBetaScreens[gnBetaScreenIndex].pCelFile;
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
void __stdcall GAME_HandleKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nOne = 1;
    if ((pMsg->lParam & 0x40000000) == 0)
        gbEndScreenDismissed = nOne;
    pMsg->bReturn = nOne;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

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
        SStrCopy(gszServerIP, pConfig->szServerIP, 0x7FFFFFFF);
    SStrCopy(gszGameName, pConfig->szGameName, 0x7FFFFFFF);
    gnGameType = pConfig->dwGameType;
    gwJoinId = pConfig->wJoinID;
    gnServerHash = pConfig->dwGameHash;
}

// 0x0044D650
void __fastcall GAME_ApplyConfigBattleNetIP(D2ConfigStrc* pConfig)
{
    if (strcmp(pConfig->szBattleNetIP, "0"))
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
        sub_004776C0_SetGamma(pConfig->dwGamma);
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

// 0x0044D900
void __fastcall GAME_ApplyConfigRealm(D2ConfigStrc* pConfig)
{
    SStrCopy(gszRealm, pConfig->szRealm, 0x20);
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
int __cdecl sub_0044DA90_GetTickCounter()
{
    return gnTickCounter;
}

// 0x0044DAA0
int __cdecl GAME_GetCurrentTime()
{
    return gdwTickCount;
}

// 0x0044DAB0
int __cdecl sub_0044DAB0_GetFrameCount()
{
    return gnFrameCount;
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
    return gnSkippedFrames;
}

// 0x0044DB00
int __cdecl sub_0044DB00_GetTickCounter()
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
    return gnGameType;
}

// 0x0044DB40
void __fastcall GAME_ExtendDelay(int nDelay)
{
    const unsigned long dwEnd = GetTickCount() + nDelay;
    if (dwEnd > gdwDelayEnd)
        gdwDelayEnd = dwEnd;
}

// 0x0044DB60
void __stdcall GAME_PreloadActTiles(unsigned char nAct)
{
    char szFile[60];
    ++nAct;
    for (int nLevelType = 0; nLevelType < 36; ++nLevelType)
    {
        if (DATATBLS_CheckActInLevelTypesTxt(nLevelType, nAct))
        {
            for (int nFile = 0; nFile < 32; ++nFile)
            {
                DATATBLS_GetFileNameFromLevelTypeAndFileId(nLevelType, nFile, szFile);
                if (szFile[0] != '0' && szFile[0])
                {
                    D2TileLibraryHeaderStrc* pLibrary;
                    D2CMPLoadProjectRecord(&pLibrary, szFile);
                }
            }
        }
    }

    {
        D2TileLibraryHeaderStrc* pLibrary;
        D2CMPLoadProjectRecord(&pLibrary, "data\\global\\tiles\\act1\\barracks\\warp.dt1");
        D2CMPLoadProjectRecord(&pLibrary, "data\\global\\tiles\\act1\\outdoors\\blank.dt1");
    }
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
    return (gnGameType >= 2 && gnGameType <= 3) ? gbLadder : 1;
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

// 0x0044DCE0
extern "C" void __cdecl GAME_UnregisterMouseHandlers()
{
    AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaGameWheelHandlers, 1);
    AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaMiddleButtonHandlers, 2);
    AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaXButtonHandlers, 2);
}

// 0x0044DD20
extern "C" void __cdecl GAME_RegisterMouseHandlers()
{
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaGameWheelHandlers, 1);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaMiddleButtonHandlers, 2);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaXButtonHandlers, 2);
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
int __cdecl sub_0044DE40_Return4()
{
    return 4;
}

// 0x0044DE50
void __fastcall sub_0044DE50_ClearPair(PairStrc_0044DE50* pPair)
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
void __fastcall sub_0044DEE0_ClearPair(PairStrc_0044DEE0* pPair)
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

void* __fastcall WARDENCLIENT_AllocLoaderMemory(unsigned int nSize)
{
    return SMemAlloc(nSize, szWardenClientFile, 0x10D, 0);
}

void __fastcall WARDENCLIENT_FreeLoaderMemory(void* pMemory)
{
    SMemFree(pMemory, szWardenClientFile, 0x117, 0);
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
    gnClearScreenCount = 1;

    const unsigned long dwEnd = GetTickCount() + 10000;
    if (dwEnd > gdwDelayEnd)
        gdwDelayEnd = dwEnd;
}


// 0x0044DEF0
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

// 0x0044E380
void __fastcall GAME_ShowLoadingMessage(int nIndex)
{
    if (GAME_IsTimerRunning(&gtLoadingTimer))
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
    gtLoadingTimer.dwStart = GetTickCount();
    gtLoadingTimer.dwLength = 2500;
    gbLeavingGame = 1;
    gbPositionalSound = 0;
    gbGameServerReady = 0;
    WINMAIN_SetExitApplication(0);
}

// 0x0044E400
int __stdcall GAME_LoadingTimerCallback(void* pArg)
{
    int bResult = 0;
    if (GAME_IsTimerExpired(&gtLoadingTimer))
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


// 0x0044E5A0
void __cdecl GAME_DrawEndGameCharInfo() {
 D2CharInfo* info=WINMAIN_GetClientInfo();
 Unicode nameText[100];
 char name[100];
 strcpy(name,info->name);
 sub_00526320_ToUnicode(nameText,name,64);
 int halfNameWidth=D2Win_10121_GetTextWidth(nameText)/2;
 D2Win_10117_DrawText(nameText,gnScreenWidth/2-halfNameWidth,187,4,0);
 int hardcore=info->flags&4;
 int expansion=info->flags&0x20;
 unsigned char classId=gnClass;
 Unicode titleText[100];
 char title[100];
 const char* text;
 int difficulty=gnDifficulty;
 if(difficulty==0) {
  int level=expansion?5:4;
  if(hardcore)text=D2Win_10161(classId,level,hardcore,expansion);
  else text=D2Win_10161(classId,level,0,expansion);
 } else if(difficulty==1) {
  int level=expansion?10:8;
  if(hardcore)text=D2Win_10161(classId,level,hardcore,expansion);
  else text=D2Win_10161(classId,level,0,expansion);
 } else if(difficulty==2) {
  int level=expansion?15:12;
  if(hardcore)text=D2Win_10161(classId,level,hardcore,expansion);
  else text=D2Win_10161(classId,level,0,expansion);
 } else return;
 if(text) {
  strcpy(title,text);strcat(title,name);
  sub_00526320_ToUnicode(titleText,title,64);
  int x=gnScreenWidth/2-D2Win_10121_GetTextWidth(titleText)/2;
  int y=277; if(gbExpansion)y=357;
  D2Win_10117_DrawText(titleText,x,y,4,0);
 }
}

// 0x0044E770
int __stdcall GAME_DrawEndGameScreen(int nUnused)
{
    D2GfxDataStrc tContext;
    char szName[0x104];
    char szPalette[0x104];
    char szPath[0x104];
    char szPl2[0x104];
    if (!WINDOW_GetState())
    {
        if (D2GFX_StartDraw(1, 0, 0, 0))
        {
            if (!s_pEndGameCell)
            {
                if (!gbExpansion)
                {
                    strcpy(szName, "endgame");
                }
                else
                {
                    strcpy(szName, "endgame2");
                }
                sprintf(szPath, "%s\\ui\\menu\\%s", gszDataGlobal, szName);
                s_pEndGameCell = ARCHIVE_LoadClientCellFile(szPath, 0);
                sprintf(szPalette, "%s\\Palette\\%s\\pal.dat", gszDataGlobal, szName);
                sprintf(szPl2, "%s\\Palette\\%s\\pal.pl2", gszDataGlobal, szName);
                D2Win_10028(szPalette, szPl2);
            }

            if (!s_pEndGameOkCell)
            {
                sprintf(szPalette, "%s\\ui\\menu\\endgameok", gszDataGlobal);
                s_pEndGameOkCell = ARCHIVE_LoadClientCellFile(szPalette, 0);
            }

            memset(&tContext, 0, sizeof(tContext));
            tContext.pCelFile = s_pEndGameCell;
            tContext.nDirection = 0;
            D2Win_10179_UpdatePaletteFlash();
            if (!gbExpansion)
            {
                tContext.nFrame = 0;
                sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
                tContext.nFrame = 1;
                sub_004F6480(&tContext, 0x100, 0x100, -1, 5, 0);
                tContext.nFrame = 2;
                sub_004F6480(&tContext, 0, gnScreenHeight - 1, -1, 5, 0);
                tContext.nFrame = 3;
                sub_004F6480(&tContext, 0x100, gnScreenHeight - 1, -1, 5, 0);
                tContext.nFrame = 4;
                sub_004F6480(&tContext, gnScreenWidth / 2, 0x100, -1, 5, 0);
                tContext.nFrame = 5;
                sub_004F6480(&tContext, gnScreenWidth / 2 + 0x100, 0x100, -1, 5, 0);
                tContext.nFrame = 6;
                sub_004F6480(&tContext, gnScreenWidth / 2, gnScreenHeight, -1, 5, 0);
                tContext.nFrame = 7;
                sub_004F6480(&tContext, gnScreenWidth / 2 + 0x100, gnScreenHeight, -1, 5, 0);
            }
            else
            {
                tContext.nFrame = 0;
                sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
                tContext.nFrame = 1;
                sub_004F6480(&tContext, 0x100, 0x100, -1, 5, 0);
                tContext.nFrame = 2;
                sub_004F6480(&tContext, 0x200, 0x100, -1, 5, 0);
                tContext.nFrame = 3;
                sub_004F6480(&tContext, 0x300, 0x100, -1, 5, 0);
                tContext.nFrame = 4;
                sub_004F6480(&tContext, 0, 0x200, -1, 5, 0);
                tContext.nFrame = 5;
                sub_004F6480(&tContext, 0x100, 0x200, -1, 5, 0);
                tContext.nFrame = 6;
                sub_004F6480(&tContext, 0x200, 0x200, -1, 5, 0);
                tContext.nFrame = 7;
                sub_004F6480(&tContext, 0x300, 0x200, -1, 5, 0);
                tContext.nFrame = 8;
                sub_004F6480(&tContext, 0, 0x258, -1, 5, 0);
                tContext.nFrame = 9;
                sub_004F6480(&tContext, 0x100, 0x258, -1, 5, 0);
                tContext.nFrame = 10;
                sub_004F6480(&tContext, 0x200, 0x258, -1, 5, 0);
                tContext.nFrame = 11;
                sub_004F6480(&tContext, 0x300, 0x258, -1, 5, 0);
            }

            D2Win_10127_SetFont(3);
            GAME_DrawEndGameTitle();
            GAME_DrawEndGameCharInfo();
            D2Win_10127_SetFont(1);
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCelFile = s_pEndGameOkCell;
            tContext.nDirection = 0;
            tContext.nFrame = gbEndScreenButtonPressed != 0;
            sub_004F6480(&tContext, gnScreenWidth / 2 - 0x30, gnScreenHeight - 0x50, -1, 5, 0);
            const int nX = GAME_GetCenteredTextX(0x13EE, gnScreenWidth / 2);
            int nOffset = 0;
            if (gbEndScreenButtonPressed)
            {
                nOffset = 2;
            }
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x13EE), nX - nOffset, gnScreenHeight + nOffset - 0x58, 0, 0);
            CURSOR_DrawCursor();
            D2GFX_EndScene();
        }
        else
        {
            return 0;
        }
    }

    if (!gbEndScreenDismissed)
    {
        return 0;
    }

    if (s_pEndGameCell)
    {
        ARCHIVE_FreeClientCellFile(s_pEndGameCell);
        s_pEndGameCell = 0;
    }
    if (s_pEndGameOkCell)
    {
        ARCHIVE_FreeClientCellFile(s_pEndGameOkCell);
        s_pEndGameOkCell = 0;
    }
    WINMAIN_SetExitApplication(0);
    return 1;
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

// 0x0044ED10
char* D2ChatStormListBStrc::IGNORELIST_GetMappingListHead()
{
    return m_terminator.MaskNext();
}

// 0x0044EE70
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
template unsigned int TSGrowableArray<SGAMEDATA>::RoundUp(unsigned int, unsigned int);
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

// 0x0044EEC0
void __cdecl GAME_CheckConnectionTimeouts()
{
    if (!gnGameType || gnGameType == 1)
    {
        return;
    }

    unsigned long dwNow = GetTickCount();
    if (!CLIENT_IsConnected() && !gbLeavingGame && gbPositionalSound)
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
        && (gnGameType == 9 || gnGameType == 7))
    {
        GAME_ShowLoadingMessage(6);
    }
}

// 0x0044EFA0
int __stdcall GAME_RunGameFrame(int nUnused)
{
    int bFrame = 0;
    int bDrawn = 0;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
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
    if (gbLeftButtonDown)
    {
        GAME_StartClick();
    }

    if (gbRightButtonDown)
    {
        GAME_StartRightClick();
    }

    GAME_UpdateKeyState();

    unsigned int dwNow = GetTickCount();
    if (gdwNextKeepAliveTick < dwNow)
    {
        sub_00477DD0();
        gdwLastCheck_007A04A0 = dwNow;
        // Same keep-alive step as GAME_TickKeepAlive (0x44CD70): both arms set the same interval, and the original
        // still reads gpClientConfig and tests 0x1EF bit 2 with nothing depending on the result.
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
        if (gdwTickCount < gdwDelayEnd)
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
            UNITMODE_RunPendingAction(pPlayer);
        }
    }

    int bReady = 0;
    if (gnGameType == 0)
    {
        GAME_ProcessNetworkMessages();
        bReady = GAME_UpdateGamesProgress(1);
        if (bReady)
        {
            GAME_UpdateClients(1, 0);
        }
    }
    else if (gnGameType == 1)
    {
        GAME_ProcessNetworkMessages();
        bReady = GAME_UpdateGamesProgress(1);
        GAME_UpdateClients(0, 0);
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
        GAME_CloseAllGames();
    }

    if (gnGameType == 6 || gnGameType == 8)
    {
        EnterCriticalSection(&gtQServerLock);
        gbQServerStop = 1;
        LeaveCriticalSection(&gtQServerLock);
        WaitForSingleObject(ghQServerThread, 10000);
        ghQServerThread = 0;
    }

    return 1;
}

// 0x0044F360
int __cdecl GAME_RunGameSession()
{
    if(TimerExpired(&gtLoadingTimer))WINMAIN_SetExitApplication(1);
    GetTickCount();
    gtVersionInfo.dwSize=sizeof(gtVersionInfo);
    if(GetVersionExA(&gtVersionInfo))gnVersionValid=1;
    DLIGHTMAP_BuildLerpTables();
    INV_ResetCinematicFlags();
    GAME_PushRegisterState();
    CURSOR_InitCursor(0);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaGameMouseHandlers,10);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaGameWheelHandlers,1);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaMiddleButtonHandlers,2);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaXButtonHandlers,2);
    if(gnGameType!=3 && gnGameType!=7 && gnGameType!=9)
    {
        sub_00477CA0_SendPacket67(gszGameName,DLIGHTMAP_GetClientFlags());
        if(gnGameType==6 || gnGameType==8)
        {
            gbQServerStop=0;
            gbQServerRestart=0;
            InitializeCriticalSection(&gtQServerLock);
            ghQServerThread=CreateThread(0,0,GAME_RunQServerThread,0,0,&gnThreadId);
        }
    }
    else
    {
        INV_SendGameLogon(gwJoinId,gnServerHash);
        if(gnGameType==2 || gnGameType==3)WARDENCLIENT_InitWarden(gnServerHash);
    }
    SOUNDHDR_UpdateSoundSystem(gpClientConfig->bSoundBackground);
    GAME_InitGameState();
    if(RECORD_IsRecordingEnabled() || RECORD_IsPlaybackEnabled())
    {
        D2MessageStrc tMessage;
        while(PeekMessageA(&tMessage,0,0,0,1)){}
        if(RECORD_IsPlaybackEnabled())RECORD_SetRecordPlaying();
        else if(RECORD_IsRecordingEnabled())RECORD_InstallRecordHandler();
    }
    FOG_SetMemoryPoolSystemMode(0,0);
    if(gnGameType==6 || gnGameType==8)
    {
        EnterCriticalSection(&gtQServerLock);
        gbQServerRestart=1;
        LeaveCriticalSection(&gtQServerLock);
    }
    SCMD_RunMessageLoop(GAME_RunGameFrame);
    GetTickCount();
    D2SOUNDSMP_FadeOutMasterVolume(180);
    UNITMODE_StopAllSounds();
    if(GAME_IsTimerRunning(&gtLoadingTimer) && !gnDifficultyDirty && !gnCinematicPlayed)SCMD_RunMessageLoop(GAME_LoadingTimerCallback);
    if(RECORD_IsRecordingEnabled())RECORD_WriteRecordFile();
    if(gnBetaScreens)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaGameMouseHandlers,10);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaGameWheelHandlers,1);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaMiddleButtonHandlers,2);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaXButtonHandlers,2);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaBetaScreenHandlers,7);
        SCMD_RunMessageLoop(GAME_ShowBetaScreens);
    }
    else if(gnDifficultyDirty)
    {
        INV_PlayCinematic(5);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaGameMouseHandlers,10);
        GAME_UnregisterMouseHandlers();
        GAME_SetResolution(0);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaEndScreenHandlers,9);
        SCMD_RunMessageLoop(GAME_DrawEndGameScreen);
    }
    else if(gnPlayCinematic)
    {
        INV_PlayCinematic(7);
        gnCinematicPlayed=1;
    }
    unsigned char bEndGame=1;
    if(gnCinematicPlayed)
    {
        int nDifficulty=gnClientDifficulty;
        int nProgress=gpClientConfig->aFlags1EF[1]&31;
        D2ConfigStrc* pClientInfo=gpClientConfig;
        switch(nDifficulty)
        {
        case 0:
            if(nProgress==8)bEndGame=0;
            else if(nProgress==12)bEndGame=0;
            break;
        case 1:
            if(nProgress==12)bEndGame=0;
            break;
        }
        pClientInfo->wFlags1EF=((nDifficulty<<10)+0x500)|(pClientInfo->wFlags1EF&0xE0FF);
        if(bEndGame)
        {
            AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaGameMouseHandlers,10);
            GAME_UnregisterMouseHandlers();
            GAME_SetResolution(2);
            SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaEndScreenHandlers,9);
            SCMD_RunMessageLoop(GAME_DrawEndGameScreen);
        }
    }
    GAME_ReleaseGameState();
    SOUNDHDR_ShutdownSound();
    VIEW_FreeLerpTables();
    CURSOR_ShutdownCursor();
    D2Win_10006_ClearDrawCaches();
    WINMAIN_PushStateValue(4);
    if(gnBetaScreens)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaBetaScreenHandlers,7);
        gnBetaScreens=0;
    }
    else if(gnDifficultyDirty)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaEndScreenHandlers,9);
        gnDifficultyDirty=0;
    }
    else if(bEndGame && gnCinematicPlayed)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaEndScreenHandlers,9);
        gnCinematicPlayed=0;
    }
    else
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(),gaGameMouseHandlers,10);
        GAME_UnregisterMouseHandlers();
    }
    if(gnGameType==2 || gnGameType==6 || gnGameType==3 || gnGameType==7)
        if(gpComInterface)gpComInterface->pfnLeaveGame();
    return 6;
}

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
// noinline: GAME_RunGameSession (0x44F360) calls GAME_PushRegisterState (0x451F10); the image calls it out of line, and without this the compiler expands it there.
__declspec(noinline) int __cdecl GAME_PushRegisterState()
{
    return SMsgPushRegisterState((int)WINDOW_GetWindow());
}

// 0x00451F20
// noinline: GAME_ShutdownClient (0x0044D550) calls GAME_RegisterWindowHandlers (0x00451F20); the image calls it out of line, and without this the compiler expands it there.
__declspec(noinline) void __cdecl GAME_RegisterWindowHandlers()
{
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
Unicode* __fastcall sub_00452170_ReturnText(Unicode* pText)
{
    return pText;
}

// 0x00452180
void __fastcall GAME_StrToUpper(Unicode* pText)
{
    if (!pText)
        return;
    const int nLength = UNICODE_StrLen(pText);
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
        gwszHoverLine[0].wChar = 0;
        return;
    }
    sub_005267E0(gwszHoverLine, pText);
    gnHoverTextColor = nColor;
}

// 0x00453060
void __cdecl GAME_DrawPopUpText()
{
    if (!UNICODE_StrLen(gwszPopUpText))
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

extern "C" void __cdecl sub_0045FDE0_DrawLoadingScreen(); // 0x0045FDE0
extern "C" void __cdecl UI_DrawFrame(); // 0x00460190
extern "C" void __cdecl sub_0044AB70_McpIncomingIgnore(); // 0x0044AB70
extern "C" void __cdecl sub_0044ABA0_McpIncoming02(); // 0x0044ABA0
extern "C" void __cdecl sub_0044ABC0_McpIncoming07(); // 0x0044ABC0
extern "C" void __cdecl sub_0044ABE0_McpIncoming03(); // 0x0044ABE0
extern "C" void __cdecl sub_0044AC20_McpIncoming04(); // 0x0044AC20
extern "C" void __cdecl sub_0044ADF0_McpIncoming08(); // 0x0044ADF0
extern "C" void __cdecl sub_0044AE10_McpIncoming09(); // 0x0044AE10
extern "C" void __cdecl sub_0044AE30_McpIncoming0A(); // 0x0044AE30
extern "C" void __cdecl sub_0044AE60_McpIncoming18(); // 0x0044AE60
extern "C" void __cdecl sub_0044AE80_McpIncoming0B(); // 0x0044AE80
extern "C" void __cdecl sub_0044AEA0_McpIncoming0C(); // 0x0044AEA0
extern "C" void __cdecl sub_0044AEC0_McpIncoming0E(); // 0x0044AEC0
extern "C" void __cdecl sub_0044AEF0_McpIncoming0D(); // 0x0044AEF0
extern "C" void __cdecl sub_0044AF10_McpIncoming0F(); // 0x0044AF10
extern "C" void __cdecl WINMAIN_HandleMcpServerAddress(); // 0x0044AF30
extern "C" void __cdecl sub_0044AFC0(); // 0x0044AFC0
extern "C" void __cdecl WINMAIN_HandleMcpMotd(); // 0x0044B120
extern "C" void __cdecl WINMAIN_HandleMcpCreateQueue(); // 0x0044B150
extern "C" void __cdecl WINMAIN_HandleMcpCharList(); // 0x0044B170
extern "C" void __cdecl WINMAIN_HandleMcpCharListExpanded(); // 0x0044B180
extern "C" void __cdecl WINMAIN_HandleMcpGameList(); // 0x0044B2D0
extern "C" char gData_006F28F8[]; // 0x006F28F8
extern "C" void __cdecl GAME_HandleEndScreenButtonDown(); // 0x0044E460
extern "C" void __cdecl GAME_HandleEndScreenButtonUp(); // 0x0044E4F0
extern "C" void __cdecl WINMAIN_StartSession(); // 0x0044BC30
extern "C" void __cdecl WINMAIN_StopSession(); // 0x0044BD90

#pragma pack(push, 1)
struct d2data_006D5EE0_t
{
    unsigned char b0[8];
    const void* p1;
    const void* p2;
    const void* p3;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EED0_t
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
struct d2data_0070F2D0_t
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
    unsigned char b14[8];
    const void* p15;
    unsigned char b16[8];
    const void* p17;
    unsigned char b18[8];
    const void* p19;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070F378_t
{
    unsigned char b0[8];
    const void* p1;
};
#pragma pack(pop)

extern "C" const struct d2data_006D5EE0_t gData_006D5EE0; // 0x006D5EE0
extern "C" struct d2data_0070EED0_t gData_0070EED0; // 0x0070EED0
extern "C" struct d2data_0070F2D0_t gData_0070F2D0; // 0x0070F2D0
extern "C" struct d2data_0070F378_t gData_0070F378; // 0x0070F378

extern "C" const char gszDataGlobal[12] = "DATA\\GLOBAL"; // 0x006D4118

extern "C" const char gszDataLocal[11] = "DATA\\LOCAL"; // 0x006D41A8

extern "C" const char gszFormatD[3] = "%d"; // 0x006D57BC

extern int gnLeftClickState = 16; // 0x0070F234

extern int gnQServerThreshold = 4; // 0x0070F560

extern D2ClientCallbackFn gpfnClientCallbacks[3] = { (D2ClientCallbackFn)&GAME_DrawGameView, (D2ClientCallbackFn)&sub_0045FDE0_DrawLoadingScreen, (D2ClientCallbackFn)&UI_DrawFrame }; // 0x0070EF0C

extern int gnRightClickState = 16; // 0x0070F2BC

extern "C" const struct d2data_006D5EE0_t gData_006D5EE0 = {
    { 0x44, 0x32, 0x2E, 0x4C, 0x4E, 0x47 },
    (const void*)&gszLngFileName,
    (const void*)"Unable to start LNG manager.",
    (const void*)"Stupid Lng.cpp error."
}; // 0x006D5EE0
#pragma comment(linker, "/alternatename:_gszLngFileName=_gData_006D5EE0")

extern int gbInitHandlersResult = 1; // 0x0070F414

extern D2InitHandlerFn gpfnInitHandlers[52] = {
    (D2InitHandlerFn)&GAME_ApplyConfigWindow, (D2InitHandlerFn)&GAME_ApplyConfigWindow, (D2InitHandlerFn)&GAME_ApplyConfigWindow, (D2InitHandlerFn)&GAME_ApplyConfigNoFixAspect, (D2InitHandlerFn)&GAME_ApplyConfigGlide, (D2InitHandlerFn)&GAME_ApplyConfigOpenGL, (D2InitHandlerFn)&GAME_ApplyConfigDirectX, (D2InitHandlerFn)&GAME_ApplyConfigRave, (D2InitHandlerFn)&sub_0044D7C0_ApplyConfigNop, (D2InitHandlerFn)&GAME_ApplyConfigGamma, (D2InitHandlerFn)&GAME_ApplyConfigVSync, (D2InitHandlerFn)&sub_0044D810_ApplyConfigNop, (D2InitHandlerFn)&GAME_ApplyConfigGame, (D2InitHandlerFn)&GAME_ApplyConfigGame, (D2InitHandlerFn)&GAME_ApplyConfigGame, (D2InitHandlerFn)&GAME_ApplyConfigGame,
    (D2InitHandlerFn)&GAME_ApplyConfigGame, (D2InitHandlerFn)&GAME_ApplyConfigBattleNetIP, (D2InitHandlerFn)&GAME_ApplyConfigMcpIP, (D2InitHandlerFn)&GAME_ApplyConfigClass, (D2InitHandlerFn)&GAME_ApplyConfigClass, (D2InitHandlerFn)&GAME_ApplyConfigClass, (D2InitHandlerFn)&GAME_ApplyConfigClass, (D2InitHandlerFn)&GAME_ApplyConfigClass, (D2InitHandlerFn)&sub_0044D750_ApplyConfigNop, (D2InitHandlerFn)&GAME_ApplyConfigName, (D2InitHandlerFn)&GAME_ApplyConfigRealm, (D2InitHandlerFn)&GAME_ApplyConfigCTemp, (D2InitHandlerFn)&sub_0044D730_ApplyConfigNop, (D2InitHandlerFn)&sub_0044D740_ApplyConfigNop, (D2InitHandlerFn)&sub_0044D7F0_ApplyConfigNop, (D2InitHandlerFn)&sub_0044D820_ApplyConfigNop,
    (D2InitHandlerFn)&sub_0044D830_ApplyConfigNop, (D2InitHandlerFn)&GAME_ApplyConfigAct, (D2InitHandlerFn)&GAME_ApplyConfigLog, (D2InitHandlerFn)&sub_0044D880_ApplyConfigNop, (D2InitHandlerFn)&GAME_ApplyConfigNoSave, (D2InitHandlerFn)&GAME_ApplyConfigSeed, (D2InitHandlerFn)&GAME_ApplyConfigSetClientFlag, (D2InitHandlerFn)&sub_0044D930_ApplyConfigNop, (D2InitHandlerFn)&sub_0044D940_ApplyConfigNop, (D2InitHandlerFn)&sub_0044D800_ApplyConfigNop, (D2InitHandlerFn)&sub_0044D980_ApplyConfigNop, 0, (D2InitHandlerFn)&sub_0044D990_ApplyConfigNop, (D2InitHandlerFn)&sub_0044D950_ApplyConfigNop, (D2InitHandlerFn)&GAME_ApplyConfigComInterface, (D2InitHandlerFn)&GAME_ApplyConfigGame,
    0, (D2InitHandlerFn)&GAME_ApplyConfigNoCompress, (D2InitHandlerFn)&GAME_ApplyConfigTxt, (D2InitHandlerFn)&sub_0044D9E0_ApplyConfigNop
}; // 0x0070F488

extern "C" struct d2data_0070EED0_t gData_0070EED0 = {
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
}; // 0x0070EED0

extern int gnClearScreenCount = 1; // 0x0070F2C0

extern int gnLastViewY = -1; // 0x0070F558

extern int gnLastViewX = -1; // 0x0070F55C

extern unsigned short gawLoadingStrings[30] = {
    0x14F5, 0x14F6, 0x14F7, 0x14F8, 0x14F9, 0x14FB, 0x14FA, 0x14ED, 0x14EE, 0x14FC, 0x14FD, 0x14FE, 0x14FF, 0x1500, 0x1501, 0x1502,
    0x1503, 0x1504, 0x1505, 0x14F0, 0x14F4, 0x14F3, 0x14F2, 0x14F1, 0x14EF, 0x2775, 0x2776, 0x14FA, 0x14FB
}; // 0x0070F384

extern "C" D2MsgHandlerEntryStrc gaGameWheelHandlers[1] = { { 0, 522, (void*)(unsigned int)&GAME_HandleMouseWheel } }; // 0x0070F2C4

extern "C" struct d2data_0070F2D0_t gData_0070F2D0 = {
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x02 },
    (const void*)(unsigned int)&GAME_HandleLeftButtonDown,
    { 0x00, 0x00, 0x00, 0x00, 0x02, 0x02 },
    (const void*)(unsigned int)&GAME_HandleLeftButtonUp,
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x02 },
    (const void*)(unsigned int)&GAME_HandleRightButtonDown,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x02 },
    (const void*)(unsigned int)&GAME_HandleRightButtonUp,
    { 0x03, 0x00, 0x00, 0x00, 0x5B },
    (const void*)(unsigned int)&GAME_SwallowMessage,
    { 0x03, 0x00, 0x00, 0x00, 0x5C },
    (const void*)(unsigned int)&GAME_SwallowMessage,
    { 0x03, 0x00, 0x00, 0x00, 0x5D },
    (const void*)(unsigned int)&GAME_SwallowMessage,
    { 0x00, 0x00, 0x00, 0x00, 0x12, 0x01 },
    (const void*)(unsigned int)&GAME_HandleSysCommand,
    { 0x00, 0x00, 0x00, 0x00, 0x10 },
    (const void*)(unsigned int)&GAME_HandleCloseMessage,
    { 0x00, 0x00, 0x00, 0x00, 0x1C },
    (const void*)(unsigned int)&GAME_HandleActivateApp
}; // 0x0070F2D0

extern "C" D2MsgHandlerEntryStrc gaMiddleButtonHandlers[2] = {
    { 0, 520, (void*)(unsigned int)&GAME_HandleMiddleButtonUp },
    { 0, 519, (void*)(unsigned int)&GAME_HandleMiddleButtonDown }
}; // 0x0070F348

extern "C" D2MsgHandlerEntryStrc gaXButtonHandlers[2] = {
    { 0, 523, (void*)(unsigned int)&GAME_HandleXButtonDown },
    { 0, 524, (void*)(unsigned int)&GAME_HandleXButtonUp }
}; // 0x0070F360

extern "C" struct d2data_0070F378_t gData_0070F378 = {
    { 0x00 },
    (const void*)(unsigned int)&GAME_HandleMouseWheel
}; // 0x0070F378

extern int gnState_0070EF18 = 5; // 0x0070EF18

extern int gnBetaScreenCount = 10; // 0x0070F024

extern char gszMcpIP[260] = "207.82.87.133"; // 0x0070F130

extern D2BetaScreenStrc gaBetaScreens[10] = {
    { 0, 0, 0, (const char *)"screen01" },
    { 0, 0, 0, (const char *)"screen02" },
    { 0, 0, 0, (const char *)"screen03" },
    { 0, 0, 0, (const char *)"screen04" },
    { 0, 0, 0, (const char *)"screen05" },
    { 0, 0, 0, (const char *)"screen06" },
    { 0, 0, 0, (const char *)"screen07" },
    { 0, 0, 0, (const char *)"screen08" },
    { 0, 0, 0, (const char *)"screen09" },
    { 0, 0, 0, (const char *)"screen10" }
}; // 0x0070F238

extern unsigned int gdwFrameTime = 0x28; // 0x0070EF1C

extern D2QuestScreenStrc gaQuestScreens[2] = {
    { { 8 }, { 1 }, "A1Q1" },
    { { 20 }, { 5 }, "A1Q5" }
}; // 0x0070F85C

extern int gnQuestScreens = 2; // 0x0070F92C

extern int gnLineHeight = 19; // 0x007111C8

extern D2MsgHandlerEntryStrc gaBetaScreenHandlers[7] = {
    { 0, 513, (void*)(unsigned int)&GAME_AdvanceBetaScreen },
    { 0, 516, (void*)(unsigned int)&GAME_AdvanceBetaScreen },
    { 0, 256, (void*)(unsigned int)&GAME_AdvanceBetaScreenNoRepeat },
    { 0, 28, (void*)(unsigned int)&GAME_HandleActivateApp },
    { 3, 91, (void*)(unsigned int)&GAME_SwallowMessage },
    { 3, 92, (void*)(unsigned int)&GAME_SwallowMessage },
    { 3, 93, (void*)(unsigned int)&GAME_SwallowMessage }
}; // 0x0070F3C0

extern D2MsgHandlerEntryStrc gaEndScreenHandlers[9] = {
    { 0, 513, (void*)(unsigned int)&GAME_HandleEndScreenButtonDown },
    { 0, 516, (void*)(unsigned int)&GAME_HandleEndScreenButtonDown },
    { 0, 514, (void*)(unsigned int)&GAME_HandleEndScreenButtonUp },
    { 0, 517, (void*)(unsigned int)&GAME_HandleEndScreenButtonUp },
    { 0, 256, (void*)(unsigned int)&GAME_HandleKeyDown },
    { 0, 28, (void*)(unsigned int)&GAME_HandleActivateApp },
    { 3, 91, (void*)(unsigned int)&GAME_SwallowMessage },
    { 3, 92, (void*)(unsigned int)&GAME_SwallowMessage },
    { 3, 93, (void*)(unsigned int)&GAME_SwallowMessage }
}; // 0x0070F418
// 0x00453BB0
void __cdecl GAME_DrawEntryList()
{
    AUTOMAP_DrawFramedBox(0x78, 0x1E, 0x190, 0x15E, 0, 0);
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xFA4), 0x96, 0x37, 4, 0);
    int nY = 2 * gnLineHeight + 0x1E;
    while (pEntry)
    {
        const char* szName = ROSTER_GetEntryName(pEntry);
        Unicode wszName[16] = {};
        sub_00526F20_ToUnicode(wszName, szName, 16);
        const int nRowY = nY + 0x19;
        wszName[15].wChar = 0;
        D2Win_10117_DrawText(wszName, 0x96, nRowY, 0, 0);

        Unicode wszLine[20] = {};
        const Unicode* pText;
        if (ROSTER_GetEntryIndex(pEntry) == 0xFFFF)
        {
            pText = D2LANG_GetStringFromTblIndex(0xFAF);
        }
        else
        {
            Unicode wszNumber[3];
            char szNumber[20];
            wszNumber[0].wChar = 0;
            wszNumber[1].wChar = 0;
            wszNumber[2].wChar = 0;
            wsprintfA(szNumber, gszFormatD, ROSTER_GetEntryIndex(pEntry));
            sub_00526F20_ToUnicode(wszNumber, szNumber, 2);
            sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xFB0));
            sub_00526700(wszLine, wszNumber);
            wszLine[19].wChar = 0;
            pText = wszLine;
        }
        D2Win_10117_DrawText(pText, 0x140, nRowY, 0, 0);

        if (CHAT_IsNumberDisplayEnabled())
        {
            Unicode wszValue[12] = {};
            char szValue[12];
            wsprintfA(szValue, gszFormatD, ROSTER_GetKillCount(pEntry));
            sub_00526F20_ToUnicode(wszValue, szValue, 12);
            D2Win_10117_DrawText(wszValue, 0x82, nRowY, 4, 0);
        }

        pEntry = ROSTER_GetNextStoredUnit(pEntry);
        nY += gnLineHeight;
        if (nY > 0x145 - gnLineHeight)
        {
            break;
        }
    }
}

// 0x00454600
D2CelFileStrc* __cdecl GAME_GetBuySellButtonCells()
{
    if (!gpBuySellButton)
    {
        char szPath[0x104];
        wsprintfA(szPath, "%s\\ui\\panel\\buysellbtn", gszDataGlobal);
        gpBuySellButton = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    return gpBuySellButton;
}

// 0x00454740
void __cdecl GAME_LoadLoadingPalette()
{
    char szPl2[0x104];
    char szPalette[0x104];
    sprintf(szPalette, "%s\\Palette\\Loading\\pal.dat", gszDataGlobal);
    sprintf(szPl2, "%s\\Palette\\Loading\\pal.pl2", gszDataGlobal);
    D2Win_10028(szPalette, szPl2);
}

// 0x00455510
void __cdecl GAME_DrawLevelLoadingScreen()
{
    char szLanguage[4];
    char szAct[32];
    char szPath[0x104];
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (!pRoom)
    {
        if (gpLoadingCell)
        {
            ARCHIVE_FreeClientCellFile(gpLoadingCell);
            gpLoadingCell = 0;
        }
        return;
    }

    static D2LoadingTimerStrc s_tTimer; // 0x007A3144
    static int s_nLastLevelId; // 0x007A3140
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId != s_nLastLevelId)
    {
        VIEW_InitLifeColors(1);
        if (gpLoadingCell)
        {
            ARCHIVE_FreeClientCellFile(gpLoadingCell);
            gpLoadingCell = 0;
        }

        if (!s_nLastLevelId)
        {
            s_tTimer.dwStart = 0;
            s_tTimer.dwLength = 0;
        }
        else
        {
            s_tTimer.dwStart = GetTickCount();
            s_tTimer.dwLength = 2000;
        }
        s_nLastLevelId = nLevelId;
    }

    if (GAME_IsTimerExpired(&s_tTimer))
    {
        if (gpLoadingCell)
        {
            ARCHIVE_FreeClientCellFile(gpLoadingCell);
            gpLoadingCell = 0;
        }
        return;
    }

    D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (nLevelId >= 109)
    {
        strcpy(szAct, "EXPANSION");
    }
    else
    {
        sprintf(szAct, "ACT%d", DRLG_GetActNoFromLevelId(nLevelId) + 1);
    }
    STRTABLE_GetLanguageInfoField(szLanguage, 0);
    sprintf(szPath, "%s\\UI\\%s\\%s\\%s", gszDataLocal, szLanguage, szAct, pLevelsTxt->szEntryFile);
    for (int i = 0; i < gnQuestScreens; ++i)
    {
        if (nLevelId == *(int*)gaQuestScreens[i].nLevelId && INV_GetTableByte(0, *(int*)gaQuestScreens[i].nQuest))
        {
            sprintf(szPath, "%s\\UI\\%s\\ACT1\\%s", gszDataLocal, szLanguage, gaQuestScreens[i].szName);
            break;
        }
    }

    if (!gpLoadingCell)
    {
        gpLoadingCell = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    D2Win_10134_DrawCellFile(gpLoadingCell, gnScreenWidth / 2, gnScreenHeight / 2 - 140, 1, 5, 1);
}

// 0x00456550
void __cdecl GAME_LoadLoadingScreen()
{
    char szPath[0x104];
    UI_FreeLoadingScreen();
    GAME_LoadLoadingPalette();
    if (STRTABLE_GetLanguage())
    {
        sprintf(szPath, "%s\\UI\\LoadingScreen", gszDataLocal);
    }
    else
    {
        sprintf(szPath, "%s\\UI\\Loading\\Loadingscreen", gszDataGlobal);
    }
    gpLoadingScreen = ARCHIVE_LoadClientCellFile(szPath, 0);
    gnLoadingFrame = 0;
    gbLoadingScreenActive = 1;
    MSG_SetProgress(0, 0);
    gbLoadingAfterUnload = gbActUnloaded;
}

// 0x0045C3E0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInline(pSeed, nMax);
}

// 0x0045C520
void __cdecl GAME_SaveCharFile()
{
    char szPath[500];
    char szDir[0x400];

    D2_ASSERT(gszClientCharName[0], 0x25);

    const unsigned int nSize = gnSaveBufferSize;
    if (nSize < 8)
    {
        return;
    }

    unsigned char* pBuffer = gpSaveBuffer;
    const D2SaveHeaderStrc tHeader = *(D2SaveHeaderStrc*)pBuffer;
    if (tHeader.dwMagic != 0xAA55AA55)
    {
        return;
    }

    if (tHeader.dwVersion <= 0x5B)
    {
        if (nSize < 0x82)
        {
            return;
        }
        gpClientConfig->wFlags1EF = *(unsigned short*)(pBuffer + 0x18);
    }
    else
    {
        if (nSize < 0x14F)
        {
            return;
        }
        gpClientConfig->wFlags1EF = *(unsigned short*)(pBuffer + 0x24);
    }

    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPath, "%s%s.d2s", szDir, gszClientCharName);
    _iobuf* pFile = fopen(szPath, "wb");
    if (pFile)
    {
        fwrite(gpSaveBuffer, gnSaveBufferSize, 1, pFile);
        fclose(pFile);
    }
}

// 0x006CB400
void __cdecl sub_006CB400_Nop()
{
}

