#include "Fog.h"
#include "D2FogTypes.h"

struct D2CrashGuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct D2CvRsdsStrc
{
    unsigned long dwCvSignature;
    D2CrashGuidStrc tGuid;
    unsigned long dwAge;
    char szPdbName[4];
};

struct D2CrashModuleStrc
{
    void* pBase;
    unsigned long nSize;
    char szName[0x100];
    char szPath[0x100];
    unsigned long nTimeStamp;
    D2CrashGuidStrc tGuid;
    unsigned long nAge;
    unsigned long nTimeDateStamp;
    unsigned long nVersion;

    D2CrashModuleStrc()
    {
        pBase = 0;
        nSize = 0;
        nTimeStamp = 0;
        tGuid.Data1 = 0;
        tGuid.Data2 = 0;
        tGuid.Data3 = 0;
        *(unsigned long*)&tGuid.Data4[0] = 0;
        *(unsigned long*)&tGuid.Data4[4] = 0;
        nAge = 0;
        nTimeDateStamp = 0;
        nVersion = 0;
        szName[0] = 0;
        szPath[0] = 0;
    }
};

struct D2CrashModuleListStrc
{
    unsigned int nCount;
    D2CrashModuleStrc aModules[0x100];
};


static bool __stdcall sub_00404AB0_VisitModule(void* pContext, const D2ImageDosHeaderStrc* pImage, const wchar_t* wszName, int nNameLength);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);

BOOLEAN __stdcall AUTOMAP_IsDebugDirectorySizeValid(unsigned int nValue);
static bool __stdcall sub_004049A0_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage); // 0x004049A0

int sub_00404730_GetImageKind(const D2ImageOptionalHeaderStrc* pHeader); // 0x00404730
bool sub_00404760_IsDosHeaderValid(const D2ImageDosHeaderStrc* pImage); // 0x00404760

// 0x00404780
static inline bool sub_00404780_IsNtHeaderValid(const D2ImageNtHeadersStrc* pNt)
{
    if (IsBadReadPtr(pNt, 4))
    {
        return false;
    }
    if (pNt->Signature != 0x4550)
    {
        return false;
    }
    if (IsBadReadPtr(&pNt->FileHeader, 0x14))
    {
        return false;
    }
    if (IsBadReadPtr(&pNt->OptionalHeader, pNt->FileHeader.SizeOfOptionalHeader))
    {
        return false;
    }
    if (!sub_00404730_GetImageKind(&pNt->OptionalHeader))
    {
        return false;
    }
    return true;
}

bool sub_004047D0_GetDebugDirectory(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeaderStrc* pHeader); // 0x004047D0

BOOLEAN __stdcall AUTOMAP_IsDebugDirectorySizeValid(unsigned int nValue); // 0x00404850

// 0x00404860
static void sub_00404860_SetNb10Info(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv)
{
    pModule->nTimeStamp = pCv->dwSignature;
    memset(&pModule->tGuid, 0, sizeof(pModule->tGuid));
}

// 0x00404890
static void sub_00404890_CopyRsdsGuid(D2CrashModuleStrc* pModule, const D2CvRsdsStrc* pCv)
{
    pModule->tGuid = pCv->tGuid;
}

bool __stdcall sub_00404900_FindCodeView(const D2ImageDosHeaderStrc* pImage, const D2ImageDebugDirStrc* pDirs, D2CrashModuleStrc* pModule, unsigned long nSize); // 0x00404900

static bool __stdcall sub_004049A0_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage)
{
    pModule->pBase = (void*)pImage;
    if (!sub_00404760_IsDosHeaderValid(pImage))
    {
        return false;
    }
    const D2ImageNtHeadersStrc* pNt = (const D2ImageNtHeadersStrc*)((const char*)pImage + pImage->e_lfanew);
    if (!sub_00404780_IsNtHeaderValid(pNt))
    {
        return false;
    }
    pModule->nSize = pNt->OptionalHeader.SizeOfImage;
    pModule->nTimeDateStamp = pNt->FileHeader.TimeDateStamp;
    if (pImage->e_res2[2] == 0xB74F && pImage->e_res2[3] == 0x2D98)
    {
        pModule->nVersion = (pImage->e_res2[1] << 16) + pImage->e_res2[0];
        if (pModule->nVersion)
        {
            pModule->nVersion *= 0xFDCA75BB;
        }
    }
    unsigned long nRva = 0;
    unsigned long nSize = 0;
    if (sub_004047D0_GetDebugDirectory(&nSize, &nRva, &pNt->OptionalHeader) && nRva && nSize)
    {
        const D2ImageDebugDirStrc* pDirs = (const D2ImageDebugDirStrc*)((const char*)pImage + nRva);
        if (!IsBadReadPtr(pDirs, nSize) && AUTOMAP_IsDebugDirectorySizeValid(nSize))
        {
            sub_00404900_FindCodeView(pImage, pDirs, pModule, nSize);
        }
    }
    return true;
}

static inline void CrashModule_ToUtf8(D2CrashModuleStrc* pModule, const wchar_t* wszSource, int nSourceLength)
{
    const int nLength = WideCharToMultiByte(0xFDE9, 0, wszSource, nSourceLength, pModule->szName, sizeof(pModule->szName), 0, 0);
    if (nLength < 0)
    {
        pModule->szName[0] = 0;
    }
    else if (nLength > sizeof(pModule->szName) - 1)
    {
        pModule->szName[sizeof(pModule->szName) - 1] = 0;
    }
    else
    {
        pModule->szName[nLength] = 0;
    }
}

// 0x00404AB0
static bool __stdcall sub_00404AB0_VisitModule(void* pContext, const D2ImageDosHeaderStrc* pImage, const wchar_t* wszName, int nNameLength)
{
    __declspec(align(8)) D2CrashModuleStrc tModule;
    CrashModule_ToUtf8(&tModule, wszName, nNameLength);
    char* pName = 0;
    char* pSep = strrchr(tModule.szName, '/');
    if (pSep > pName)
    {
        pName = pSep;
    }
    pSep = strrchr(tModule.szName, '\\');
    if (pSep && pSep > pName)
    {
        pName = pSep;
    }
    pSep = strrchr(tModule.szName, ':');
    if (pSep && pSep > pName)
    {
        pName = pSep;
    }
    pName = pName ? pName + 1 : tModule.szName;
    memcpy(tModule.szName, pName, sizeof(tModule.szName));
    if (!sub_004049A0_ReadImageInfo(&tModule, pImage))
    {
        return true;
    }
    D2CrashModuleListStrc* pList = (D2CrashModuleListStrc*)pContext;
    if (!pList)
    {
        return false;
    }
    pList->aModules[pList->nCount] = tModule;
    ++pList->nCount;
    return pList->nCount < 0x100 ? true : false;
}







extern void* gahPsapiModules[0x400]; // 0x00992B20

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
                    if (!sub_00404AB0_VisitModule(pContext, (const D2ImageDosHeaderStrc*)tInfo.lpBaseOfDll, wszName, -1))
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
