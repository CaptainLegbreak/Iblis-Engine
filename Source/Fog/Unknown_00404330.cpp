#include "Fog.h"

struct D2FindDataWStrc
{
    unsigned long dwFileAttributes;
    unsigned long ftTimes[6];
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    wchar_t cFileName[260];
    wchar_t cAlternateFileName[14];
};

struct D2CrashModuleListStrc;
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileW(const wchar_t* wszFileName, D2FindDataWStrc* pFindData); // 0x006CC2C0
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

void* gahPsapiModules[0x400];                                                                      // 0x00992B20

bool __stdcall sub_00404C60_EnumModulesPsapi(void* pContext);

// 0x00404330
bool __stdcall sub_00404330_FileExistsUtf8(const char* szPath)
{
    __declspec(align(8)) wchar_t wszPath[0x104];
    if (!MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104))
    {
        return false;
    }
    D2FindDataWStrc tFindData;
    void* hFind = FindFirstFileW(wszPath, &tFindData);
    if (hFind == (void*)-1)
    {
        return false;
    }
    FindClose(hFind);
    return true;
}

// 0x00404C60
bool __stdcall sub_00404C60_EnumModulesPsapi(void* pContext)
{
    void* hProcess = GetCurrentProcess();
    void* hPsapi = LoadLibraryW(L"psapi.dll");
    if (!hPsapi)
    {
        return false;
    }

    EnumProcessModulesFn pfnEnumProcessModules = (EnumProcessModulesFn)GetProcAddress(hPsapi, "EnumProcessModules");
    GetModuleInformationFn pfnGetModuleInformation = (GetModuleInformationFn)GetProcAddress(hPsapi, "GetModuleInformation");
    GetModuleBaseNameWFn pfnGetModuleBaseNameW = (GetModuleBaseNameWFn)GetProcAddress(hPsapi, "GetModuleBaseNameW");
    if (pfnEnumProcessModules && pfnGetModuleInformation && pfnGetModuleBaseNameW)
    {
        unsigned long cbNeeded;
        if (pfnEnumProcessModules(hProcess, gahPsapiModules, sizeof(gahPsapiModules), &cbNeeded))
        {
            const unsigned int nCount = cbNeeded / sizeof(void*);
            for (unsigned int i = 0; i < nCount; ++i)
            {
                D2PsapiModuleInfoStrc tInfo;
                if (pfnGetModuleInformation(hProcess, gahPsapiModules[i], &tInfo, 0xC))
                {
                    __declspec(align(8)) wchar_t wszName[0x104];
                    if (!pfnGetModuleBaseNameW(hProcess, gahPsapiModules[i], wszName, 0x104))
                    {
                        wszName[0] = 0;
                    }
                    if (!tInfo.lpBaseOfDll->sub_00404AB0_VisitModule(pContext, wszName, -1))
                    {
                        break;
                    }
                }
            }
            FreeLibrary(hPsapi);
            return true;
        }
    }

    FreeLibrary(hPsapi);
    return false;
}

// 0x00404DC0
static bool sub_00404DC0_EnumModulesToolhelp(void* pContext)
{
    void* hSnapshot = CreateToolhelp32Snapshot(8, 0);
    if (hSnapshot == (void*)-1)
    {
        return false;
    }
    __declspec(align(8)) D2ModuleEntry32Strc tEntry;
    tEntry.dwSize = 0x428;
    if (Module32FirstW(hSnapshot, &tEntry))
    {
        do
        {
            if (!tEntry.modBaseAddr->sub_00404AB0_VisitModule(pContext, tEntry.szModule, -1))
            {
                break;
            }
            tEntry.dwSize = 0x428;
        } while (Module32NextW(hSnapshot, &tEntry));
    }
    CloseHandle(hSnapshot);
    return true;
}

static bool sub_00404F20_EnumModules(D2CrashModuleListStrc* pList)
{
    bool bResult = sub_00404C60_EnumModulesPsapi(pList);
    if (!bResult)
    {
        bResult = sub_00404DC0_EnumModulesToolhelp(pList);
        if (!bResult)
        {
// build: symbol ?ERRORMANAGER_EnumLoadedModules@* 0x00404E60
            return ERRORMANAGER_EnumLoadedModules(pList);
        }
    }
    return bResult;
}

bool __stdcall sub_M321_Emit_00404F20(D2CrashModuleListStrc* pList)
{
    return sub_00404F20_EnumModules(pList);
}
