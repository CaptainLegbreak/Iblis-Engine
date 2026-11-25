#include "Fog.h"
#include "D2CrashTypes.h"


extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
bool __stdcall sub_00404C60_EnumModulesPsapi(void* pContext); // 0x00404C60

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*)); // 0x00685B50
int __cdecl ERRORMANAGER_CompareUInt(const void* p1, const void* p2); // 0x00402C10
static void sub_00402FE0_InitModuleList(D2CrashModuleListStrc* pList);
static bool sub_00404DC0_EnumModulesToolhelp(void* pContext);
static bool sub_00404F20_EnumModules(D2CrashModuleListStrc* pList);

// 0x00402C60
static void sub_00402C60_FormatModule(char* szOut, const D2CrashModuleStrc* pModule)
{
    char szGuid[0x28];
    char szVersion[0x10];
    *szOut = 0;
    szVersion[0] = 0;
    if (pModule->nVersion > 0)
    {
        _snprintf_s(szVersion, 0x10, -1, " %8x", pModule->nVersion);
    }
    _snprintf_s(szGuid, 0x28, -1, "{%08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x}", pModule->tGuid.Data1, pModule->tGuid.Data2, pModule->tGuid.Data3,
        pModule->tGuid.Data4[0], pModule->tGuid.Data4[1], pModule->tGuid.Data4[2], pModule->tGuid.Data4[3],
        pModule->tGuid.Data4[4], pModule->tGuid.Data4[5], pModule->tGuid.Data4[6], pModule->tGuid.Data4[7]);
    _snprintf_s(szOut, 0x400, -1, "DBG-MODULE<%p %08x \"%s\" \"%s\" %u %s %u %u%s>", pModule->pBase, pModule->nSize, pModule->szName, pModule->szPath,
        pModule->nTimeStamp, szGuid, pModule->nAge, pModule->nTimeDateStamp, szVersion);
}

static bool sub_00404DC0_EnumModulesToolhelp(void* pContext)
{
    void* hSnapshot = CreateToolhelp32Snapshot(8, 0);
    if (hSnapshot == (void*)-1)
    {
        return false;
    }
    D2ModuleEntry32Strc tEntry;
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

// 0x00404F20
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

void __stdcall sub_M01_Emit_00402C60(char* szOut, const D2CrashModuleStrc* pModule)
{
    sub_00402C60_FormatModule(szOut, pModule);
}

bool __stdcall sub_M01_Emit_00404F20(D2CrashModuleListStrc* pList)
{
    return sub_00404F20_EnumModules(pList);
}

// 0x00402EE0
void __fastcall sub_00402EE0_DumpModules(D2CrashPrintFn pfnPrint, void* pContext)
{
    D2CrashModuleListStrc tList;
    char szLine[0x400];
    sub_00402FE0_InitModuleList(&tList);
    tList.nCount = 0;
    sub_00404F20_EnumModules(&tList);
    qsort(tList.aModules, tList.nCount, sizeof(D2CrashModuleStrc), ERRORMANAGER_CompareUInt);
    for (unsigned int i = 0; i < tList.nCount; i++)
    {
        sub_00402C60_FormatModule(szLine, &tList.aModules[i]);
        const size_t nLength = strlen(szLine);
        if (nLength >= 0x3FF)
        {
            szLine[0x3FE] = '\n';
            szLine[0x3FF] = 0;
        }
        else
        {
            szLine[nLength] = '\n';
            szLine[nLength + 1] = 0;
        }
        pfnPrint(pContext, szLine);
    }
}

static void sub_00402FE0_InitModuleList(D2CrashModuleListStrc* pList)
{
    D2CrashModuleStrc* pModule = pList->aModules;
    for (int i = 0xFF; i >= 0; i--)
    {
        pModule->pBase = 0;
        pModule->nSize = 0;
        pModule->nTimeStamp = 0;
        pModule->tGuid.Data1 = 0;
        pModule->tGuid.Data2 = 0;
        pModule->tGuid.Data3 = 0;
        *(unsigned long*)&pModule->tGuid.Data4[0] = 0;
        *(unsigned long*)&pModule->tGuid.Data4[4] = 0;
        pModule->nAge = 0;
        pModule->nTimeDateStamp = 0;
        pModule->nVersion = 0;
        pModule->szName[0] = 0;
        pModule->szPath[0] = 0;
        pModule++;
    }
}
