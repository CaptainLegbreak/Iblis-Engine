#include "D2MultiTypes.h"
#include "D2FogTypes.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "D2CommonApi2.h"
#include "FogApi2.h"
#include "D2GfxApi.h"
#include "D2WinApi.h"
#include "D2SoundApi.h"
#include "D2HellApi.h"
#include "D2MCPClientApi.h"
#include "D2LaunchApi.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
struct _iobuf;
typedef int BOOL;
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" int __cdecl fputc(int nChar, _iobuf* pFile); // 0x00682058
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

extern D2ModeEntryStrc gaModeTable[6]; // 0x00706554
extern void* gpModeContext_0074C718; // 0x0074C718
extern D2ModeIfaceStrc* gpModeIface; // 0x0074C700
extern int gnMode; // 0x0074C704
int gbUseKeyhook; // 0x0074C708
void* ghModKeyhook; // 0x0074C70C

// 0x004059D0
int __stdcall ERRORMANAGER_RunModeInterface(D2ConfigStrc* pCfg)
{
    if (gnMode < 1 || gnMode > 5)
    {
        return 0;
    }
    D2_ASSERT(gaModeTable[gnMode].pfnCreate, 307);
    D2_ASSERT(gaModeTable[gnMode].pfnRelease, 308);
    gpModeIface = gaModeTable[gnMode].pfnCreate(gpModeContext_0074C718);
    const int nResult = gpModeIface->pfnRun(pCfg);
    gaModeTable[gnMode].pfnRelease();
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


extern "C" void __cdecl sub_0042E590_SetOwner(); // 0x0042E590
extern "C" void __cdecl sub_0042E5A0_Nop(); // 0x0042E5A0
extern "C" void __cdecl CHATDLG_GetModuleInterface(); // 0x0043CBE0
extern "C" void __cdecl sub_0043CBF0_Nop(); // 0x0043CBF0
extern "C" void __cdecl WINMAIN_InitInterface(); // 0x0044B400
extern "C" void __cdecl WINMAIN_ShutdownInterface(); // 0x0044B420

extern "C" const char* gData_00706518[15] = { // 0x00706518
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

extern "C" void __cdecl sub_0042E590_SetOwner(); // 0x0042E590
extern "C" void __cdecl sub_0042E5A0_Nop(); // 0x0042E5A0
extern "C" void __cdecl CHATDLG_GetModuleInterface(); // 0x0043CBE0
extern "C" void __cdecl sub_0043CBF0_Nop(); // 0x0043CBF0
extern "C" void __cdecl WINMAIN_InitInterface(); // 0x0044B400
extern "C" void __cdecl WINMAIN_ShutdownInterface(); // 0x0044B420

extern D2ModeEntryStrc gaModeTable[6] = {
    { 0 },
    { (D2ModeIfaceStrc *(__fastcall *)(void*))&WINMAIN_InitInterface, (void (__cdecl *)())&WINMAIN_ShutdownInterface },
    { 0 },
    { (D2ModeIfaceStrc *(__fastcall *)(void*))&CHATDLG_GetModuleInterface, (void (__cdecl *)())&sub_0043CBF0_Nop },
    { (D2ModeIfaceStrc *(__fastcall *)(void*))&sub_0042E590_SetOwner, (void (__cdecl *)())&sub_0042E5A0_Nop },
    { (D2ModeIfaceStrc *(__fastcall *)(void*))&WINMAIN_InitInterface, (void (__cdecl *)())&WINMAIN_ShutdownInterface }
}; // 0x00706554
