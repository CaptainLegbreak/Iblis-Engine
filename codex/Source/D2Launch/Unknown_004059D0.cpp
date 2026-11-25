#include "D2MultiTypes.h"
#include "D2FogTypes.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
struct _iobuf;
typedef int BOOL;
int __fastcall FOG_CreatePathHierarchy(const char* szPath); // 0x00406A10
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" int __cdecl fputc(int nChar, _iobuf* pFile); // 0x00682058
void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField); // 0x00525260
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __fastcall ERRORMANAGER_GetBlizzardDataPath(char* szOutPath, int nSize); // 0x00406C40
bool __fastcall sub_00516DE1_Verify(void* pContext); // 0x00516DE1
bool __fastcall sub_00516D8B_RunSurvey(const char* szExePath); // 0x00516D8B
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __fastcall MAINMENUS_InitStorm(int nDirectFlags, int nValue); // 0x00406870
void __cdecl ERRORMANAGER_ForceCrash(); // 0x00407970
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem); // 0x00409C80
void __fastcall FOG_AsyncDataInitialize(int bEnable, int nUnused); // 0x0040A390
void __cdecl FOG_AsyncDataDestroy(); // 0x0040A440
void __cdecl FOG_10218(); // 0x0040B0C0
void __cdecl FOG_10082_Noop(); // 0x0040B320
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
int __stdcall D2GFX_Release(); // 0x004F5050
void __stdcall D2GFX_SetPerspective(int bPerspective); // 0x004F51E0
int __stdcall D2GFX_SetGamma(int nGamma); // 0x004F5230
void __cdecl D2GFX_EnableVSync(); // 0x004F5270
void __cdecl D2GFX_DisableFixedAspectRatio(); // 0x004F5280
int __stdcall D2GFX_ToggleLowQuality(); // 0x004F54F0
int __cdecl WINDOW_GetWindow(); // 0x004F59A0
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution); // 0x004F8F10
int __stdcall D2Win_CloseSpriteCache(); // 0x004F9030
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress); // 0x004FA520
int __cdecl ARCHIVE_ShowInsertExpansionDiscMessage(); // 0x004FAB00
int __cdecl ARCHIVE_ShowInsertPlayDiscMessage(); // 0x004FAB30
int __cdecl ARCHIVE_LoadArchives(); // 0x004FAB90
void __cdecl ARCHIVE_FreeArchives(); // 0x004FAE00
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
void __cdecl D2SOUND_CloseSoundSystem(); // 0x00514060
void __fastcall sub_00514530_InitSound(int bExpansion, int bSoundBackground); // 0x00514530
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
void __cdecl IGNORELIST_FreeIgnoreList(); // 0x0060DDB0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2ModeEntryStrc gaModeTable[6]; // 0x00706554
extern void* gpModeContext_0074C718; // 0x0074C718
D2ModeIfaceStrc* gpModeIface; // 0x0074C700
int gnMode_0074C704; // 0x0074C704
int gbUseKeyhook_0074C708; // 0x0074C708
void* ghModKeyhook_0074C70C; // 0x0074C70C

// 0x004059D0
int __stdcall ERRORMANAGER_RunModeInterface(D2ConfigStrc* pCfg)
{
    if (gnMode_0074C704 < 1 || gnMode_0074C704 > 5)
    {
        return 0;
    }
    D2_ASSERT(gaModeTable[gnMode_0074C704].pfnCreate, 307);
    D2_ASSERT(gaModeTable[gnMode_0074C704].pfnRelease, 308);
    gpModeIface = gaModeTable[gnMode_0074C704].pfnCreate(gpModeContext_0074C718);
    const int nResult = gpModeIface->pfnRun(pCfg);
    gaModeTable[gnMode_0074C704].pfnRelease();
    return nResult;
}

// 0x00405A50
void __cdecl sub_00405A50_Nop()
{
}

// 0x00405A60
void __cdecl sub_00405A60_Nop()
{
}

// 0x00405A70
void __stdcall sub_00405A70_WriteSurveyLocale()
{
    unsigned int nLanguage;
    char szPath[0x104];
    char szExe[0x400];
    STRTABLE_GetLanguageInfoField(&nLanguage, 3);
    if (ERRORMANAGER_GetBlizzardDataPath(szPath, 0x104))
    {
        SStrPack(szPath, "System Survey\\ProductData\\", 0x104);
        char* pEnd = szPath + SStrLen(szPath);
        unsigned int nRemain = szPath + sizeof(szPath) - pEnd;
        SStrCopy(pEnd, "D2DV\\locale", nRemain);
// build: symbol ?FOG_CreatePathHierarchy@* 0x00406A10
        FOG_CreatePathHierarchy(szPath);
        _iobuf* pFile = fopen(szPath, "w");
        if (pFile)
        {
            fputc(nLanguage >> 24, pFile);
            fputc((nLanguage >> 16) & 0xFF, pFile);
            fputc((nLanguage >> 8) & 0xFF, pFile);
            fputc(nLanguage & 0xFF, pFile);
            fclose(pFile);
        }
        if (FOG_IsExpansion())
        {
            SStrCopy(pEnd, "D2XP\\locale", nRemain);
            FOG_CreatePathHierarchy(szPath);
            pFile = fopen(szPath, "w");
            if (pFile)
            {
                fputc(nLanguage >> 24, pFile);
                fputc((nLanguage >> 16) & 0xFF, pFile);
                fputc((nLanguage >> 8) & 0xFF, pFile);
                fputc(nLanguage & 0xFF, pFile);
                fclose(pFile);
            }
        }
    }
    ERRORMANAGER_GetModuleDirectory(szExe, 0x400);
    SStrPack(szExe, "SystemSurvey.exe", 0x400);
    if (sub_00516DE1_Verify(szExe))
        sub_00516D8B_RunSurvey(szExe);
}


// 0x00405C30
int __fastcall GameStart(void* hInstance, D2ConfigStrc* pCfg, int nModType)
{
    if (pCfg->bCrashApp == 1)
    {
        ERRORMANAGER_ForceCrash();
    }

    gnMode_0074C704 = nModType;

    BOOL bSoundStarted = 0;
    BOOL bGfxStarted = 0;

    MAINMENUS_InitStorm(pCfg->bDirect, 0);
    FOG_AsyncDataInitialize(1, 0);
    FOG_10082_Noop();
    FOG_10218();

    if (gnMode_0074C704 != 2)
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

    if (gnMode_0074C704 != 2)
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

        if (gbUseKeyhook_0074C708)
        {
            ghModKeyhook_0074C70C = LoadLibraryA("Keyhook.dll");
        }

        if (ghModKeyhook_0074C70C)
        {
            void (__stdcall* pfnInstall)(int) = (void (__stdcall*)(int))GetProcAddress(ghModKeyhook_0074C70C, "InstallKeyboardHook");
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

    if (!pCfg->bNoSound && gnMode_0074C704 != 2)
    {
        sub_00514530_InitSound(pCfg->bIsExpansion, pCfg->bSoundBackground);
        bSoundStarted = 1;
    }

    while (gnMode_0074C704 != 0)
    {
        if (gnMode_0074C704 == 2)
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

        gnMode_0074C704 = ERRORMANAGER_RunModeInterface(pCfg);
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

    if (ghModKeyhook_0074C70C)
    {
        void (__stdcall* pfnUninstall)() = (void (__stdcall*)())GetProcAddress(ghModKeyhook_0074C70C, "UninstallKeyboardHook");
        if (pfnUninstall)
        {
            pfnUninstall();
        }
        FreeLibrary(ghModKeyhook_0074C70C);
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


#include "gen/data/Source/D2Launch/Unknown_004059D0.inc"
