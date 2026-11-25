#include "D2Client.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2StormLink.h"
#include "D2SysTypes.h"
#include "D2ClientTypes.h"
#include "D2CelContext.h"
#include "D2LevelTxt.h"
#include "D2MultiTypes.h"
#include "D2ClientTimer.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;


struct D2StormLinkStrc;

struct D2StormListStrc;

struct D2Storm4167B0Strc;

struct D2Storm4168F0Strc;

struct D2Storm416A90Strc;

struct D2FlagWordStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

struct D2ClientNotifyStrc;


void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc* pSystem, int bFreePoolAlloc); // 0x00409FF0

int __stdcall WINMAIN_ProcessCommandLine(void* pArg); // 0x0044B6B0

int __cdecl GAME_LoadLngModule(); // 0x00451330

int __fastcall D2Win_10015(); // 0x004F8FE0

int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc); // 0x004F8FC0

int __stdcall SCMD_WindowProc(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam); // 0x00451B30

void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80

void __stdcall DATATBLS_LoadAllTxts(void* pArg, int bArg); // 0x00619300

void __stdcall DATATBLS_UnloadAllBins(); // 0x00619140

void __cdecl GAME_FreeLngModule(); // 0x00451290

void __cdecl PROFCORE_WriteProfileCounters(); // 0x006116B0

extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80


extern int (__cdecl* gpfnLaunchStates[])(); // 0x0070EE54

extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

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

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

#pragma intrinsic(memset)

#pragma pack(push,1)

struct D2CharInfo { char pad[0xbd]; char name[0x132]; unsigned short flags; };

#pragma pack(pop)

D2CharInfo* __cdecl WINMAIN_GetClientInfo(); // 0x0044B7A0

int __fastcall D2Win_10121_GetTextWidth(const Unicode*); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode*,int,int,int,int); // 0x00502320

const char* __stdcall D2Win_10161(int nClass, int nLevel, int bExpansion, int bSoftCore); // 0x005068A0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

extern int gnScreenWidth; // 0x0071146C

extern int gbExpansion; // 0x007A04F4

extern unsigned char gnClass; // 0x007A0522

extern unsigned char gnDifficulty; // 0x007A060C

extern "C" char* __cdecl strcpy(char*,const char*);

extern "C" char* __cdecl strcat(char*,const char*);

struct D2TileLibraryHeaderStrc;

struct D2CelFileStrc;

struct Unicode;

struct D2QuestScreenStrc;

struct D2LoadingTimerStrc;

struct D2MsgHandlerEntryStrc;

struct D2MessageStrc;

struct D2CriticalSectionStrc;

struct D2VersionInfoStrc;

struct D2ComInterfaceStrc;

struct D2QuestScreenStrc
{
    char nLevelId[4];
    char nQuest[4];
    char szName[5];
};


extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

int __stdcall DATATBLS_CheckActInLevelTypesTxt(int nLevelType, unsigned char nAct); // 0x0061EAE0

void __stdcall DATATBLS_GetFileNameFromLevelTypeAndFileId(int nLevelType, int nFile, char* szFile); // 0x0061EB40

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0

int __fastcall ROSTER_GetKillCount(D2StoredUnitRecordStrc* pEntry); // 0x00479B80

int __cdecl CHAT_IsNumberDisplayEnabled(); // 0x0047A980

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

void __cdecl GAME_DrawEndGameTitle(); // 0x0044D3E0

void __cdecl GAME_DrawEndGameCharInfo(); // 0x0044E5A0

int __fastcall GAME_GetCenteredTextX(unsigned short nStringIndex, int nCenterX); // 0x0044D390

void __cdecl CURSOR_DrawCursor(); // 0x004684C0

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

void __stdcall D2CMPLoadProjectRecord(D2TileLibraryHeaderStrc** ppLibrary, const char* szFilePath); // 0x00600790

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szPath, int nType); // 0x004788B0

int __stdcall D2Win_10028(const char* pszPalDatFilename, const char* pszPalPL2Filename); // 0x004FB500

void __fastcall UI_FreeLoadingScreen(); // 0x004547B0

void __fastcall MSG_SetProgress(int nValue, int nDivisor); // 0x00478130

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall INV_GetTableByte(int nUnused, int nIndex); // 0x004B92E0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall VIEW_InitLifeColors(int nMode); // 0x00492F40

int __fastcall GAME_IsTimerExpired(D2LoadingTimerStrc* pTimer); // 0x0044DFF0

void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nA, int nB, int nC); // 0x00502680

extern "C" const char gszFormatD[]; // 0x006D57BC

extern int gnLineHeight; // 0x007111C8

extern int gbExpansion; // 0x007A04F4

extern D2QuestScreenStrc gaQuestScreens[]; // 0x0070F85C

extern int gnQuestScreens; // 0x0070F92C

extern int gnScreenWidth; // 0x0071146C

extern D2CelFileStrc* gpLoadingScreen; // 0x007A2888

extern int gnLoadingFrame; // 0x007A2A6C

extern int gbLoadingScreenActive; // 0x007A2868

extern int gbLoadingAfterUnload; // 0x007A27B8

extern int gbActUnloaded; // 0x007A0624

struct D2MessageStrc { void* hWnd; unsigned int uMessage,wParam,lParam,time; int x,y; };

struct D2VersionInfoStrc { unsigned long dwSize; char unknown04[144]; };



typedef int (__stdcall* D2IdleHandler)(int);

typedef unsigned long (__stdcall* D2ThreadProc)(void*);

extern "C" __declspec(dllimport) int __stdcall GetVersionExA(D2VersionInfoStrc*); // 0x006CC1F8

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc*); // 0x006CC210

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void*,unsigned long,D2ThreadProc,void*,unsigned long,unsigned long*); // 0x006CC250

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2MessageStrc*,void*,unsigned int,unsigned int,unsigned int); // 0x006CC480

extern D2MsgHandlerEntryStrc gaGameWheelHandlers[1]; // 0x0070F2C4

extern D2MsgHandlerEntryStrc gaGameMouseHandlers[10]; // 0x0070F2D0

extern D2MsgHandlerEntryStrc gaMiddleButtonHandlers[2]; // 0x0070F348

extern D2MsgHandlerEntryStrc gaXButtonHandlers[2]; // 0x0070F360

extern D2MsgHandlerEntryStrc gaBetaScreenHandlers[7]; // 0x0070F3C0

extern D2MsgHandlerEntryStrc gaEndScreenHandlers[9]; // 0x0070F418

extern D2CriticalSectionStrc gtCriticalSection_007A0468; // 0x007A0468

extern int gnServerToken_007A0520; // 0x007A0520

extern D2VersionInfoStrc gtVersionInfo; // 0x007A0528

extern void* ghThread_007A05BC; // 0x007A05BC

extern int gnServerHash_007A05C0; // 0x007A05C0

extern const char gszGameName[]; // 0x007A05DC

extern unsigned long gnThreadId; // 0x007A05F0

extern D2ComInterfaceStrc* gpComInterface; // 0x007A05F4

extern int gnBetaScreens_007A0600; // 0x007A0600

extern int gnDifficultyDirty_007A0604; // 0x007A0604

extern unsigned char gnClientDifficulty; // 0x007A060C

extern int gnMode_007A0610; // 0x007A0610

extern int gnPlayCinematic_007A0628; // 0x007A0628

extern int gnCinematicPlayed_007A062C; // 0x007A062C

extern int gnVersionValid; // 0x007A0644

extern int gnThreadStop_007A0648; // 0x007A0648

extern int gnThreadReady_007A064C; // 0x007A064C

extern D2LoadingTimerStrc gtLoadingTimer_007A0684; // 0x007A0684

void __fastcall WINMAIN_PushStateValue(int); // 0x0044B440

void __fastcall GAME_SetResolution(int); // 0x0044BA20

void __cdecl GAME_ReleaseGameState(); // 0x0044C890

unsigned long __stdcall GAME_RunQServerThread(void*); // 0x0044CF20

int __stdcall GAME_ShowBetaScreens(int); // 0x0044D100

extern "C" void __cdecl GAME_UnregisterMouseHandlers(); // 0x0044DCE0

int __fastcall GAME_IsTimerRunning(D2LoadingTimerStrc*); // 0x0044E040

void __cdecl GAME_InitGameState(); // 0x0044E200

int __stdcall GAME_LoadingTimerCallback(int); // 0x0044E400

int __stdcall GAME_DrawEndGameScreen(int); // 0x0044E770

int __stdcall GAME_RunGameFrame(int); // 0x0044EFA0

void __cdecl RECORD_WriteRecordFile(); // 0x00451620

int __cdecl RECORD_IsRecordingEnabled(); // 0x00451910

void __cdecl RECORD_InstallRecordHandler(); // 0x00451940

void __cdecl RECORD_SetRecordPlaying(); // 0x00451970

int __cdecl RECORD_IsPlaybackEnabled(); // 0x00451980

int __fastcall SCMD_RunMessageLoop(D2IdleHandler); // 0x00451BB0

extern "C" void __fastcall SCMD_RegisterMsgHandlers(int hwnd, D2MsgHandlerEntryStrc* table, unsigned int count); // 0x00451DB0

void __fastcall sub_00451E10_UnregisterMsgHandlers(int,D2MsgHandlerEntryStrc*,int); // 0x00451E10

int __cdecl GAME_PushRegisterState(); // 0x00451F10

int __fastcall CURSOR_InitCursor(int); // 0x004680B0

void __cdecl CURSOR_ShutdownCursor(); // 0x00468170

void __cdecl DLIGHTMAP_BuildLerpTables(); // 0x00475DF0

void __cdecl VIEW_FreeLerpTables(); // 0x00475EF0

void __fastcall sub_00477CA0_SendPacket67(const char*,int); // 0x00477CA0

void __fastcall INV_SendGameLogon(int,int); // 0x00477F70

int __cdecl DLIGHTMAP_GetClientFlags(); // 0x0047A990

int __fastcall WARDENCLIENT_InitWarden(int); // 0x004803C0

void __cdecl sub_00481830(); // 0x00481830

void __fastcall SOUNDHDR_UpdateSoundSystem(int); // 0x00482260

void __cdecl SOUNDHDR_ShutdownSound(); // 0x00482940

void __fastcall INV_PlayCinematic(int); // 0x00482EF0

void __cdecl INV_ResetCinematicFlags(); // 0x00483310

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __stdcall D2Win_10006_ClearDrawCaches(); // 0x004F9130

void __fastcall D2SOUNDSMP_FadeOutMasterVolume(int); // 0x00515F50

int gbEndScreenButtonPressed; // 0x007A0680

int gbEndScreenDismissed; // 0x007A0608

D2CelFileStrc* gpLoadingCell; // 0x007A2794

D2CelFileStrc* gpBuySellButton; // 0x007A287C

static D2CelFileStrc* s_pEndGameCell; // 0x007A0700

static D2CelFileStrc* s_pEndGameOkCell; // 0x007A06FC

union D2SeedStrc;

struct D2SaveHeaderStrc;

extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449

int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050

struct D2SaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
};

#pragma pack(push, 1)


#pragma pack(pop)

extern char gszClientCharName[]; // 0x007A05C4

unsigned char* gpSaveBuffer; // 0x007A5224

unsigned int gnSaveBufferSize; // 0x007A5228


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

// 0x0044BDD0
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
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

// build: symbol ?$S4@?7??GAME_DrawLevelLoadingScreen@@YAXXZ@4IA 0x007A314C
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

struct D2ActiveRoomStrc;

struct D2StoredUnitRecordStrc;

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

// 0x0044E770
int __stdcall GAME_DrawEndGameScreen(int nUnused)
{
    D2CelContextStrc tContext;
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
// build: symbol ?gszDataGlobal@* 0x006D4118
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
            tContext.pCellFile = s_pEndGameCell;
            tContext.nDirection = 0;
// build: symbol ?D2Win_10179_UpdatePaletteFlash@* 0x004FB0D0
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
            tContext.pCellFile = s_pEndGameOkCell;
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

// 0x0044F360
int __cdecl GAME_RunGameSession()
{
    if(TimerExpired(&gtLoadingTimer_007A0684))WINMAIN_SetExitApplication(1);
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
    if(gnMode_007A0610!=3 && gnMode_007A0610!=7 && gnMode_007A0610!=9)
    {
        sub_00477CA0_SendPacket67(gszGameName,DLIGHTMAP_GetClientFlags());
        if(gnMode_007A0610==6 || gnMode_007A0610==8)
        {
            gnThreadStop_007A0648=0;
            gnThreadReady_007A064C=0;
            InitializeCriticalSection(&gtCriticalSection_007A0468);
            ghThread_007A05BC=CreateThread(0,0,GAME_RunQServerThread,0,0,&gnThreadId);
        }
    }
    else
    {
        INV_SendGameLogon(gnServerToken_007A0520,gnServerHash_007A05C0);
        if(gnMode_007A0610==2 || gnMode_007A0610==3)WARDENCLIENT_InitWarden(gnServerHash_007A05C0);
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
    if(gnMode_007A0610==6 || gnMode_007A0610==8)
    {
        EnterCriticalSection(&gtCriticalSection_007A0468);
        gnThreadReady_007A064C=1;
        LeaveCriticalSection(&gtCriticalSection_007A0468);
    }
    SCMD_RunMessageLoop(GAME_RunGameFrame);
    GetTickCount();
    D2SOUNDSMP_FadeOutMasterVolume(180);
    sub_00481830();
    if(GAME_IsTimerRunning(&gtLoadingTimer_007A0684) && !gnDifficultyDirty_007A0604 && !gnCinematicPlayed_007A062C)SCMD_RunMessageLoop(GAME_LoadingTimerCallback);
    if(RECORD_IsRecordingEnabled())RECORD_WriteRecordFile();
    if(gnBetaScreens_007A0600)
    {
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaGameMouseHandlers,10);
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaGameWheelHandlers,1);
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaMiddleButtonHandlers,2);
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaXButtonHandlers,2);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaBetaScreenHandlers,7);
        SCMD_RunMessageLoop(GAME_ShowBetaScreens);
    }
    else if(gnDifficultyDirty_007A0604)
    {
        INV_PlayCinematic(5);
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaGameMouseHandlers,10);
        GAME_UnregisterMouseHandlers();
        GAME_SetResolution(0);
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(),gaEndScreenHandlers,9);
        SCMD_RunMessageLoop(GAME_DrawEndGameScreen);
    }
    else if(gnPlayCinematic_007A0628)
    {
        INV_PlayCinematic(7);
        gnCinematicPlayed_007A062C=1;
    }
    unsigned char bEndGame=1;
    if(gnCinematicPlayed_007A062C)
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
            sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaGameMouseHandlers,10);
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
    if(gnBetaScreens_007A0600)
    {
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaBetaScreenHandlers,7);
        gnBetaScreens_007A0600=0;
    }
    else if(gnDifficultyDirty_007A0604)
    {
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaEndScreenHandlers,9);
        gnDifficultyDirty_007A0604=0;
    }
    else if(bEndGame && gnCinematicPlayed_007A062C)
    {
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaEndScreenHandlers,9);
        gnCinematicPlayed_007A062C=0;
    }
    else
    {
        sub_00451E10_UnregisterMsgHandlers(WINDOW_GetWindow(),gaGameMouseHandlers,10);
        GAME_UnregisterMouseHandlers();
    }
    if(gnMode_007A0610==2 || gnMode_007A0610==6 || gnMode_007A0610==3 || gnMode_007A0610==7)
        if(gpComInterface)gpComInterface->pfnClose();
    return 6;
}

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
// build: symbol ?gszDataLocal@* 0x006D41A8
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

#include "gen/data/Source/D2Client/GAME/Game_0044E5A0.inc"
