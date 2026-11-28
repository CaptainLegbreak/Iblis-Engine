#include "D2FogTypes.h"
typedef unsigned int size_t;
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);
#include "D2MultiTypes.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi.h"
#include "FogApi2.h"
#include "D2GfxApi.h"
#include "D2WinApi.h"
#include "D2SoundApi.h"
#include "D2MCPClientApi.h"
#include "D2LangApi.h"
#include "D2CommonApi2.h"
#include "D2LaunchApi.h"

struct D2ConfigStrc;

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, size_t nCount); // 0x00682591
void __fastcall SaveCmdLine(const char** argv); // 0x00405F00
void __cdecl MoveBetaSettingsToRelease(); // 0x00406040
void __fastcall ParseCmdLine(D2ConfigStrc* pCfg, const char* argv); // 0x004059A0
int __fastcall GameStart(void* hInstance, D2ConfigStrc* pCfg, int nModType); // 0x00405C30
int __stdcall ERRORMANAGER_RunModeInterface(D2ConfigStrc* pCfg); // 0x004059D0
void __stdcall sub_00405A70_WriteSurveyLocale(); // 0x00405A70
int __cdecl sub_00405EF0_AllowExpansion(); // 0x00405EF0
extern "C" __declspec(dllimport) void* __stdcall OpenEventA(unsigned long dwDesiredAccess, int bInheritHandle, const char* szName); // 0x006CC12C
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" const char gszDash[]; // 0x006CCA2C
extern const char* gaszModuleTypes[6]; // 0x007065C4
extern void* ghCurrentProcess; // 0x0074C718
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0
typedef void* HKEY;
extern "C" __declspec(dllimport) long __stdcall RegOpenKeyA(HKEY hKey, const char* szSubKey, HKEY* phResult); // 0x006CC040
extern "C" __declspec(dllimport) long __stdcall RegCreateKeyA(HKEY hKey, const char* szSubKey, HKEY* phResult); // 0x006CC03C
extern "C" __declspec(dllimport) long __stdcall RegEnumValueA(HKEY hKey, unsigned long dwIndex, char* szValueName, unsigned long* pcchValueName, unsigned long* pReserved, unsigned long* pType, unsigned char* pData, unsigned long* pcbData); // 0x006CC038
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(HKEY hKey, const char* szValueName, unsigned long dwReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) long __stdcall RegCloseKey(HKEY hKey); // 0x006CC030
extern "C" __declspec(dllimport) long __stdcall RegDeleteKeyA(HKEY hKey, const char* szSubKey); // 0x006CC02C
extern "C" __declspec(dllimport) int __stdcall SetCurrentDirectoryA(const char* szPath); // 0x006CC140
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) void* __stdcall FreeSid(void* pSid); // 0x006CC044
typedef int (__stdcall* D2AllocateAndInitializeSidFn)(D2SidAuthorityStrc* pAuthority, unsigned char nSubAuthorityCount, unsigned long dwSub0, unsigned long dwSub1, unsigned long dwSub2, unsigned long dwSub3, unsigned long dwSub4, unsigned long dwSub5, unsigned long dwSub6, unsigned long dwSub7, void** ppSid);
typedef int (__stdcall* D2InitializeAclFn)(void* pAcl, unsigned long nAclLength, unsigned long dwAclRevision);
typedef int (__stdcall* D2AddAccessDeniedAceFn)(void* pAcl, unsigned long dwAceRevision, unsigned long dwAccessMask, void* pSid);
typedef unsigned long (__stdcall* D2SetSecurityInfoFn)(void* hObject, int nObjectType, unsigned long dwSecurityInfo, void* pOwner, void* pGroup, void* pDacl, void* pSacl);
extern "C" __declspec(dllimport) unsigned long __stdcall GetVersion(); // 0x006CC138
extern "C" __declspec(dllimport) void* __stdcall OpenSCManagerA(const char* szMachineName, const char* szDatabaseName, unsigned long dwDesiredAccess); // 0x006CC028
extern "C" __declspec(dllimport) void* __stdcall OpenServiceA(void* hSCManager, const char* szServiceName, unsigned long dwDesiredAccess); // 0x006CC04C
extern "C" __declspec(dllimport) int __stdcall CloseServiceHandle(void* hSCObject); // 0x006CC01C
extern "C" __declspec(dllimport) int __stdcall StartServiceCtrlDispatcherA(const D2ServiceTableEntryStrc* pServiceTable); // 0x006CC020
extern "C" __declspec(dllimport) int __stdcall SetServiceStatus(void* hServiceStatus, D2ServiceStatusStrc* pStatus); // 0x006CC048
extern "C" __declspec(dllimport) void* __stdcall RegisterServiceCtrlHandlerA(const char* szServiceName, void (__stdcall* pfnHandler)(unsigned long dwCtrlCode)); // 0x006CC024
extern int gbD2ServerStopEvent; // 0x007065C0
extern char gszServiceName[32]; // 0x007065DC
extern D2ServiceStatusStrc gD2ServerServiceStatus; // 0x007065FC
extern void* ghD2ServerServiceStatus; // 0x0074C714

void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** lpszArgv); // 0x004065E0
void __stdcall D2ServerServiceHandlerProc(unsigned long dwCtrlCode); // 0x00406410

typedef int BOOL;
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
int gnMode; // 0x0074C704
int gbUseKeyhook; // 0x0074C708
void* ghModKeyhook; // 0x0074C70C

// Kept noinline: GameInit (0x4064C0) calls this out of line in the image; without it the compiler inlines it there.
// 0x00405C30
__declspec(noinline) int __fastcall GameStart(void* hInstance, D2ConfigStrc* pCfg, int nModType)
{
    if (pCfg->bCrashApp == 1)
    {
        ERRORMANAGER_ForceCrash();
    }

    gnMode = nModType;

    BOOL bSoundStarted = 0;
    BOOL bGfxStarted = 0;

    MAINMENUS_InitStorm(pCfg->bDirect, 0);
    FOG_AsyncDataInitialize(1, 0);
    FOG_10082_Noop();
    FOG_10218();

    if (gnMode != 2)
    {
        if (!ARCHIVE_LoadArchives() || !ARCHIVE_LoadExpansionArchives(ARCHIVE_ShowInsertPlayDiscMessage, ARCHIVE_ShowInsertExpansionDiscMessage, 0, pCfg))
        {
            ARCHIVE_FreeArchives();
            return 0;
        }
        pCfg->bIsExpansion = FOG_IsExpansion();
        sub_00405A70_WriteSurveyLocale();
    }

    STRTABLE_GetLanguage();

    if (pCfg->b3DFX)
    {
        nModType = 4;
    }
    else if (pCfg->bWindow)
    {
        nModType = 1;
    }
    else
    {
        nModType = pCfg->bD3D ? 6 : 3;
    }

    const BOOL bWindowed = pCfg->bWindow != 0;
    const int nResolution = pCfg->bIsExpansion ? 2 : 0;

    if (gnMode != 2)
    {
        if (!D2Win_CreateWindow(hInstance, nModType, bWindowed, !pCfg->bNoCompress))
        {
            return 0;
        }

        if (pCfg->bPerspective && nModType >= 4)
        {
            D2GFX_SetPerspective(1);
        }

        if (!D2Win_InitializeSpriteCache(bWindowed, nResolution))
        {
            D2GFX_Release();
            return 0;
        }

        if (gbUseKeyhook)
        {
            ghModKeyhook = LoadLibraryA("Keyhook.dll");
        }

        if (ghModKeyhook)
        {
            void (__stdcall* pfnInstall)(void*) = (void (__stdcall*)(void*))GetProcAddress(ghModKeyhook, "InstallKeyboardHook");
            if (pfnInstall)
            {
                pfnInstall(WINDOW_GetWindow());
            }
        }

        bGfxStarted = 1;
    }

    if (pCfg->bQuality)
    {
        D2GFX_ToggleLowQuality();
    }

    if (pCfg->dwGamma)
    {
        D2GFX_SetGamma(pCfg->dwGamma);
    }

    if (pCfg->bVSync)
    {
        D2GFX_EnableVSync();
    }

    unsigned long bFixedAspect = 1;
    SRegLoadValue("Diablo II", "Fixed Aspect Ratio", 0, &bFixedAspect);
    if (pCfg->bNoFixedAspect || bFixedAspect != 1)
    {
        D2GFX_DisableFixedAspectRatio();
    }

    if (!pCfg->bIsExpansion)
    {
        SRegSaveValue("Diablo II", "Resolution", 0, 0);
    }

    if (!pCfg->bNoSound && gnMode != 2)
    {
        sub_00514530_InitSound(pCfg->bIsExpansion, pCfg->bSoundBackground);
        bSoundStarted = 1;
    }

    while (gnMode != 0)
    {
        if (gnMode == 2)
        {
            if (bSoundStarted)
            {
                D2SOUND_CloseSoundSystem();
                bSoundStarted = 0;
            }

            if (bGfxStarted)
            {
                D2Win_CloseSpriteCache();
                D2GFX_Release();
                bGfxStarted = 0;
            }
        }

        gnMode = ERRORMANAGER_RunModeInterface(pCfg);
    }

    if (bSoundStarted)
    {
        D2SOUND_CloseSoundSystem();
    }

    if (bGfxStarted)
    {
        D2Win_CloseSpriteCache();
        D2GFX_Release();
    }

    ARCHIVE_FreeArchives();

    if (ghModKeyhook)
    {
        void (__stdcall* pfnUninstall)() = (void (__stdcall*)())GetProcAddress(ghModKeyhook, "UninstallKeyboardHook");
        if (pfnUninstall)
        {
            pfnUninstall();
        }
        FreeLibrary(ghModKeyhook);
    }

    FOG_AsyncDataDestroy();
    D2MCPClientCloseMCP();

    D2ComInterfaceStrc* pComInterface = pCfg->pComInterface;
    if (pComInterface)
    {
        pComInterface->pfnSlot10();
    }

    IGNORELIST_FreeIgnoreList();
    FOG_DestroyMemoryPoolSystem(0);
    return 0;
}

// 0x00405EF0
int __cdecl sub_00405EF0_AllowExpansion()
{
    return 1;
}

// 0x00405F00
void __fastcall SaveCmdLine(const char** argv)
{
    char szSRegWriteBuf[0x800];
    unsigned long bUseCmdLine = 0;
    if (*argv && strlen(*argv))
    {
        sprintf(szSRegWriteBuf, "%s -skiptobnet", *argv);
        SRegSaveString("Diablo II", "CmdLine", 0, szSRegWriteBuf);
    }
    else
    {
        SRegLoadValue("Diablo II", "UseCmdLine", 0, &bUseCmdLine);
        if (bUseCmdLine)
        {
            SRegLoadString("Diablo II", "CmdLine", 0, szSRegReadBuf, 0x400);
            *argv = szSRegReadBuf;
        }
        else
        {
            memcpy(szSRegWriteBuf, "-skiptobnet", sizeof("-skiptobnet"));
            SRegSaveString("Diablo II", "CmdLine", 0, szSRegWriteBuf);
        }
    }
    bUseCmdLine = 0;
    SRegSaveValue("Diablo II", "UseCmdLine", 0, 0);
    if (gbRunningAsService)
    {
        SRegLoadString("Diablo II", "SvcCmdLine", 0, szSRegReadBuf, 0x400);
        *argv = szSRegReadBuf;
    }
}

// 0x00406040
void __cdecl MoveBetaSettingsToRelease()
{
    HKEY hBeta;
    if (0 == RegOpenKeyA((HKEY)0x80000002, "SOFTWARE\\Blizzard Entertainment\\Diablo II Beta", &hBeta))
    {
        HKEY hKey;
        RegCreateKeyA((HKEY)0x80000002, "SOFTWARE\\Blizzard Entertainment\\Diablo II", &hKey);
        int i = 0;
        unsigned long cchValue;
        unsigned long cbData;
        char szValue[0x104];
        unsigned char bData[0x400];
        unsigned long dwRegType;
        do
        {
            cchValue = 0x104;
            cbData = 0x400;
            if (0 != RegEnumValueA(hBeta, i++, szValue, &cchValue, 0, &dwRegType, bData, &cbData))
            {
                break;
            }
        }
        while (0 == RegSetValueExA(hKey, szValue, 0, dwRegType, bData, cbData));
        RegCloseKey(hKey);
        RegCloseKey(hBeta);
        RegDeleteKeyA((HKEY)0x80000002, "SOFTWARE\\Blizzard Entertainment\\Diablo II Beta");
    }
    char szPath[0x104] = { 0 };
    FOG_GetInstallPath(szPath, 0x104);
    if (gbRunningAsService)
    {
        SetCurrentDirectoryA(szPath);
    }
}

// 0x00406190
static int __stdcall MAIN_GetProc(void* hModule, const char* szName, void** ppProc)
{
    void* pProc = GetProcAddress(hModule, szName);
    if (!pProc)
    {
        return 0;
    }
    *ppProc = pProc;
    return 1;
}

int __stdcall sub_K01_Emit_00406190(void* hModule, const char* szName, void** ppProc)
{
    return MAIN_GetProc(hModule, szName, ppProc);
}

// 0x004061C0
int __cdecl MAIN_DenyProcessAccess()
{
    D2SidAuthorityStrc tAuthority = { { 0, 0, 0, 0, 0, 1 } };
    void* hProcess = GetCurrentProcess();
    void* pSid = 0;
    int bResult = 0;
    unsigned char aAcl[0x200];
    void* hAdvapi = LoadLibraryA("advapi32.dll");
    if (hAdvapi)
    {
        D2AllocateAndInitializeSidFn pfnAllocSid = (D2AllocateAndInitializeSidFn)GetProcAddress(hAdvapi, "AllocateAndInitializeSid");
        if (pfnAllocSid)
        {
            D2InitializeAclFn pfnInitAcl = (D2InitializeAclFn)GetProcAddress(hAdvapi, "InitializeAcl");
            if (pfnInitAcl)
            {
                D2AddAccessDeniedAceFn pfnAddDenied = (D2AddAccessDeniedAceFn)GetProcAddress(hAdvapi, "AddAccessDeniedAce");
                if (pfnAddDenied)
                {
                    D2SetSecurityInfoFn pfnSetSec = (D2SetSecurityInfoFn)GetProcAddress(hAdvapi, "SetSecurityInfo");
                    if (pfnSetSec)
                    {
                        if (pfnAllocSid(&tAuthority, 1, 0, 0, 0, 0, 0, 0, 0, 0, &pSid)
                            && pfnInitAcl(aAcl, sizeof(aAcl), 2)
                            && pfnAddDenied(aAcl, 2, 0xF01FFFFE, pSid)
                            && !pfnSetSec(hProcess, 6, 0x80000004, 0, 0, aAcl, 0))
                        {
                            bResult = 1;
                        }
                    }
                }
            }
        }
        FreeLibrary(hAdvapi);
    }
    if (pSid)
    {
        FreeSid(pSid);
    }
    return bResult;
}

// 0x00406340
static int __stdcall MAIN_SelectModule(const char* szArgvCmd, int* pChosenModule)
{
    const size_t nArgvLength = strlen(szArgvCmd) + 1;
    char* szArgvDupe = (char*)FOG_Alloc(nArgvLength, ".\\Main.cpp", 442, 0);
    SStrCopy(szArgvDupe, szArgvCmd, nArgvLength);
    for (char* pCurrentParam = strtok(szArgvDupe, gszDash); pCurrentParam; pCurrentParam = strtok(0, gszDash))
    {
        for (int i = 0; i < 6; i++)
        {
            if (0 == strncmp(pCurrentParam, gaszModuleTypes[i], strlen(gaszModuleTypes[i])) && i != 1)
            {
                *pChosenModule = i;
            }
        }
    }
    FOG_Free(szArgvDupe, ".\\Main.cpp", 480, 0);
    return 1;
}

// 0x00406410
void __stdcall D2ServerServiceHandlerProc(unsigned long dwCtrlCode)
{
    switch (dwCtrlCode)
    {
    case 1:
    case 5:
        gD2ServerServiceStatus.dwCurrentState = 3;
        SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
        gbD2ServerStopEvent = 1;
        return;
    case 4:
        SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
        return;
    default:
        break;
    }
}

// 0x00406470
static int MAIN_OpenServiceHandles(void** phService, void** phManager)
{
    *phService = 0;
    *phManager = 0;
    if (GetVersion() & 0x80000000)
    {
        return 0;
    }
    void* hManager = OpenSCManagerA(0, 0, 0xF003F);
    *phManager = hManager;
    if (!hManager)
    {
        return 0;
    }
    *phService = OpenServiceA(hManager, gszServiceName, 0xF01FF);
    return 1;
}

int sub_M371_Emit_00406470(int nAdd)
{
    void* hService;
    void* hManager;
    return MAIN_OpenServiceHandles(&hService, &hManager) + nAdd;
}

// 0x004064C0
int __fastcall GameInit(int argc, const char** argv)
{
    const char* lpArgvCmd = &gszEmptyAssertText;
    if (argc > 1)
    {
        lpArgvCmd = argv[argc - 1];
    }
    char szVersion[0x104];
    SStrPrintf(szVersion, 0x104, "v%d.%02d", 1, 14);
    FOG_SetLogPrefix("D2");
    FOG_InitErrorMgr("Diablo II", szVersion, 1);
    if (void* hEvent = OpenEventA(2, 1, "DIABLO_II_OK"))
    {
        SetEvent(hEvent);
        CloseHandle(hEvent);
    }
    SaveCmdLine(&lpArgvCmd);
    MoveBetaSettingsToRelease();
    int nChosenModule = 4;
    MAIN_SelectModule(lpArgvCmd, &nChosenModule);
    D2ConfigStrc tCfg;
    ParseCmdLine(&tCfg, lpArgvCmd);
    tCfg.pfnAllowExpansion = sub_00405EF0_AllowExpansion;
    tCfg.bOpenGL = 0;
    if (!tCfg.b3DFX)
    {
        tCfg.bD3D = !tCfg.bWindow;
    }
    return GameStart(ghCurrentProcess, &tCfg, nChosenModule);
}

// 0x004065E0
void __stdcall D2ServerServiceMain(unsigned long dwArgc, char** lpszArgv)
{
    gbRunningAsService = 1;
    ghD2ServerServiceStatus = RegisterServiceCtrlHandlerA(gszServiceName, D2ServerServiceHandlerProc);
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    GameInit(dwArgc, (const char**)lpszArgv);
    gD2ServerServiceStatus.dwCurrentState = 1;
    SetServiceStatus(ghD2ServerServiceStatus, &gD2ServerServiceStatus);
    gbRunningAsService = 0;
}

// 0x00406650
int __cdecl MAIN_StartServiceDispatcher()
{
    if (!(GetVersion() & 0x80000000))
    {
        void* hManager = OpenSCManagerA(0, 0, 0xF003F);
        if (hManager)
        {
            void* hService = OpenServiceA(hManager, gszServiceName, 0xF01FF);
            if (hService)
            {
                CloseServiceHandle(hService);
            }
            CloseServiceHandle(hManager);
            if (hService)
            {
                D2ServiceTableEntryStrc aTable[] = {
                    { gszServiceName, D2ServerServiceMain },
                    { 0, 0 }
                };
                return StartServiceCtrlDispatcherA(aTable) != 0;
            }
        }
    }
    return 0;
}

int gnCmdShow; // 0x0074C71C

// 0x004066E0
extern "C" int __stdcall WinMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nShowCmd)
{
    ghCurrentProcess = hInstance;
    gnCmdShow = nShowCmd;
    if (!MAIN_StartServiceDispatcher())
    {
        const char* argv[2];
        argv[0] = "d2server";
        argv[1] = lpCmdLine;
        MAIN_DenyProcessAccess();
        GameInit(2, argv);
    }
    return 0;
}

extern "C" const char* gData_00706584[15] = { // 0x00706584
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};

int gbD2ServerStopEvent = 1; // 0x007065C0

extern const char* gaszModuleTypes_007065C4[6] = { "modstate0", "client", "server", "multiplayer", "launcher", "expand" }; // 0x007065C4

char gszServiceName[32] = "DIABLO2SRV\0\0Diablo II Server"; // 0x007065DC

D2ServiceStatusStrc gD2ServerServiceStatus = { 16, 4, 5, 0, 0, 0, 0 }; // 0x007065FC
