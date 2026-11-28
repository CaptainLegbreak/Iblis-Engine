#include "Fog.h"
#include "D2CrashTypes.h"

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);

BOOLEAN __stdcall AUTOMAP_IsDebugDirectorySizeValid(unsigned int nValue);
static bool __stdcall ERRORMANAGER_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage); // 0x004049A0
bool ERRORMANAGER_ReadNb10(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv); // 0x00404F80
bool ERRORMANAGER_ReadRsds(const D2CvRsdsStrc* pCv, D2CrashModuleStrc* pModule); // 0x00404FF0

static int ERRORMANAGER_GetImageKind(const D2ImageOptionalHeaderStrc* pHeader)
{
    if (pHeader->Magic == 0x10B)
    {
        return 1;
    }
    if (pHeader->Magic == 0x20B)
    {
        return 2;
    }
    return 0;
}

static bool ERRORMANAGER_IsDosHeaderValid(const D2ImageDosHeaderStrc* pImage)
{
    if (IsBadReadPtr(pImage, 0x40))
    {
        return false;
    }
    if (pImage->e_magic != 0x5A4D)
    {
        return false;
    }
    return true;
}

static inline bool ERRORMANAGER_IsNtHeaderValid(const D2ImageNtHeadersStrc* pNt)
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
    if (!ERRORMANAGER_GetImageKind(&pNt->OptionalHeader))
    {
        return false;
    }
    return true;
}
static inline bool GetDebugDirectoryEntry(const D2ImageDataDirStrc* pDir, unsigned long* pRva, unsigned long* pSize)
{
    const D2ImageDataDirStrc tDir = *pDir;
    *pSize = tDir.Size;
    *pRva = tDir.VirtualAddress;
    return (!tDir.VirtualAddress && !tDir.Size) || (tDir.VirtualAddress && AUTOMAP_IsDebugDirectorySizeValid(*pSize));
}

static bool ERRORMANAGER_GetDebugDirectory(const D2ImageOptionalHeaderStrc* pHeader, unsigned long* pRva, unsigned long* pSize); // 0x004047D0
// 0x004047D0
static bool ERRORMANAGER_GetDebugDirectory(const D2ImageOptionalHeaderStrc* pHeader, unsigned long* pRva, unsigned long* pSize)
{
    const int nKind = ERRORMANAGER_GetImageKind(pHeader);
    if (!nKind)
    {
        return false;
    }
    *pRva = 0;
    *pSize = -1;
    if (nKind == 2)
    {
        const D2ImageOptionalHeader64Strc* pHeader64 = (const D2ImageOptionalHeader64Strc*)pHeader;
        return pHeader64->NumberOfRvaAndSizes > 6 && GetDebugDirectoryEntry(&pHeader64->DataDirectory[6], pRva, pSize);
    }
    return pHeader->NumberOfRvaAndSizes > 6 && GetDebugDirectoryEntry(&pHeader->DataDirectory[6], pRva, pSize);
}

BOOLEAN __stdcall AUTOMAP_IsDebugDirectorySizeValid(unsigned int nValue)
{
    return nValue >= 0x1C;
}

static void ERRORMANAGER_SetNb10Info(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv)
{
    pModule->nTimeStamp = pCv->dwSignature;
    memset(&pModule->tGuid, 0, sizeof(pModule->tGuid));
}

static void ERRORMANAGER_CopyRsdsGuid(D2CrashModuleStrc* pModule, const D2CvRsdsStrc* pCv)
{
    pModule->tGuid = pCv->tGuid;
}

static bool ERRORMANAGER_ReadCodeView(const unsigned long* pCv, D2CrashModuleStrc* pModule, unsigned int nSize)
{
    if (nSize < 4)
    {
        return false;
    }
    if (IsBadReadPtr(pCv, nSize))
    {
        return false;
    }
    if (*pCv == 0x3031424E)
    {
        return ERRORMANAGER_ReadNb10(pModule, (const D2CvNb10Strc*)pCv);
    }
    if (*pCv == 0x53445352)
    {
        return ERRORMANAGER_ReadRsds((const D2CvRsdsStrc*)pCv, pModule);
    }
    return false;
}

static bool __stdcall ERRORMANAGER_FindCodeView(const D2ImageDosHeaderStrc* pImage, const D2ImageDebugDirStrc* pDirs, D2CrashModuleStrc* pModule, unsigned long nSize)
{
    const unsigned int nCount = nSize / sizeof(D2ImageDebugDirStrc);
    for (unsigned int i = 0; i < nCount; i++)
    {
        const unsigned long* pData = (const unsigned long*)((const char*)pImage + pDirs[i].AddressOfRawData);
        if (pDirs[i].Type == 2 && ERRORMANAGER_ReadCodeView(pData, pModule, pDirs[i].SizeOfData))
        {
            return true;
        }
    }
    return false;
}

// 0x004049A0
static bool __stdcall ERRORMANAGER_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage)
{
    pModule->pBase = (void*)pImage;
    if (!ERRORMANAGER_IsDosHeaderValid(pImage))
    {
        return false;
    }
    const D2ImageNtHeadersStrc* pNt = (const D2ImageNtHeadersStrc*)((const char*)pImage + pImage->e_lfanew);
    if (!ERRORMANAGER_IsNtHeaderValid(pNt))
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
    if (ERRORMANAGER_GetDebugDirectory(&pNt->OptionalHeader, &nRva, &nSize) && nRva && nSize)
    {
        const D2ImageDebugDirStrc* pDirs = (const D2ImageDebugDirStrc*)((const char*)pImage + nRva);
        if (!IsBadReadPtr(pDirs, nSize) && AUTOMAP_IsDebugDirectorySizeValid(nSize))
        {
            ERRORMANAGER_FindCodeView(pImage, pDirs, pModule, nSize);
        }
    }
    return true;
}

bool D2ModuleStrc::ERRORMANAGER_VisitModule(void* pContext, const wchar_t* wszName, int nNameLength)
{
    D2CrashModuleStrc tModule;
    tModule.pBase = 0;
    tModule.nSize = 0;
    tModule.nTimeStamp = 0;
    memset(&tModule.tGuid, 0, sizeof(tModule.tGuid));
    tModule.nAge = 0;
    tModule.nTimeDateStamp = 0;
    tModule.nVersion = 0;
    tModule.szName[0] = 0;
    tModule.szPath[0] = 0;
    const int nLength = WideCharToMultiByte(0xFDE9, 0, wszName, nNameLength, tModule.szName, sizeof(tModule.szName), 0, 0);
    if (nLength < 0)
    {
        tModule.szName[0] = 0;
    }
    else if (nLength > sizeof(tModule.szName) - 1)
    {
        tModule.szName[sizeof(tModule.szName) - 1] = 0;
    }
    else
    {
        tModule.szName[nLength] = 0;
    }
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
    if (!ERRORMANAGER_ReadImageInfo(&tModule, (const D2ImageDosHeaderStrc*)this))
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
    return pList->nCount < 0x100;
}
