#include "SValidate.h"
#include "Storm.h"
#include "StormApi.h"

void __stdcall SErrSetLastError(unsigned int dwErrCode); // 0x0041C340

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern "C" __declspec(dllimport) long __stdcall RegCreateKeyExA(void* hKey, const char* szSubKey, unsigned long nReserved, char* szClass, unsigned long nOptions, unsigned long samDesired, void* pSecurity, void** phkResult, unsigned long* pDisposition); // 0x006CC004

extern "C" __declspec(dllimport) long __stdcall RegDeleteValueA(void* hKey, const char* szValueName); // 0x006CC018

extern "C" __declspec(dllimport) long __stdcall RegFlushKey(void* hKey); // 0x006CC008

extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010

extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C

int __stdcall SRegGetBaseKey(unsigned int nFlags, char* szDest, unsigned int nMaxLength); // 0x00414930

extern "C" __declspec(dllimport) void __stdcall SetLastError(unsigned long dwErrCode); // 0x006CC2E4

extern "C" const char gszEmptyString_006CC837; // 0x006CC837

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

extern "C" const char gszFmtUnsigned[]; // 0x006CEF68

static int __stdcall LoadRegistryEntry(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pType, unsigned char* pData, unsigned long nSize, unsigned long* pcbData); // 0x00414B00

// 0x00414930
int __stdcall SRegGetBaseKey(unsigned int nFlags, char* szDest, unsigned int nMaxLength)
{
    VALIDATEBEGIN;
    VALIDATE(szDest);
    VALIDATE(nMaxLength);
    VALIDATEEND;
    if (nFlags & 2)
        SStrCopy(szDest, "Software\\Battle.net\\", nMaxLength);
    else
        SStrCopy(szDest, "Software\\Blizzard Entertainment\\", nMaxLength);
    return nValid ? 1 : 0;
}

// 0x00414990
int __fastcall InternalDeleteEntry(unsigned int nFlags, const char* szKeyName, const char* szValueName)
{
    const char* szValue = szValueName;
    int bResult = 0;
    char szKey[0x104];
    void* hKey;
    szKey[0] = 0;
    if (!(nFlags & 0x10))
    {
        SRegGetBaseKey(nFlags, szKey, 0x104);
    }
    SStrPack(szKey, szKeyName, 0x104);

    long nUserError = 0;
    if ((nFlags & 5) != 4)
    {
        long nError = RegOpenKeyExA((void*)0x80000001, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            nError = RegDeleteValueA(hKey, szValue);
            if (nError)
            {
                nUserError = nError;
            }
            nError = RegCloseKey(hKey);
        }
        if (nError)
        {
            nUserError = nError;
        }
        if (!nUserError)
        {
            bResult = 1;
        }
    }

    long nMachineError = 0;
    if ((nFlags & 5) != 1)
    {
        long nError = RegOpenKeyExA((void*)0x80000002, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            nError = RegDeleteValueA(hKey, szValue);
            if (nError)
            {
                nMachineError = nError;
            }
            nError = RegCloseKey(hKey);
        }
        if (nError)
        {
            nMachineError = nError;
        }
        if (!nMachineError)
        {
            bResult = 1;
        }
    }

    if (!bResult)
    {
        if (nUserError)
        {
            SetLastError(nUserError);
        }
        else
        {
            SetLastError(nMachineError);
        }
    }
    return bResult;
}

// 0x00414B00
static int __stdcall LoadRegistryEntry(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pType, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    *pcbData = 0;
    char szKey[0x104];
    void* hKey = 0;
    long nError = 0x3F3;
    szKey[0] = 0;
    if (!(nFlags & 0x10))
    {
        SRegGetBaseKey(nFlags, szKey, 0x104);
    }
    SStrPack(szKey, szKeyName, 0x104);
    if (!(nFlags & 4))
    {
        nError = RegOpenKeyExA((void*)0x80000001, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            *pcbData = nSize;
            nError = RegQueryValueExA(hKey, szValueName, 0, pType, pData, pcbData);
            RegCloseKey(hKey);
        }
    }
    if (nError && !(nFlags & 1))
    {
        nError = RegOpenKeyExA((void*)0x80000002, szKey, 0, 0x20019, &hKey);
        if (!nError)
        {
            *pcbData = nSize;
            nError = RegQueryValueExA(hKey, szValueName, 0, pType, pData, pcbData);
            RegCloseKey(hKey);
        }
    }
    if (!nError)
    {
        return 1;
    }
    SetLastError(nError);
    return 0;
}

// 0x00414C70
static int __stdcall InternalSaveEntry(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwType, const unsigned char* pData, unsigned long cbData)
{
    char szKey[0x104];
    szKey[0] = 0;
    if (!(nFlags & 0x10))
    {
        SRegGetBaseKey(nFlags, szKey, 0x104);
    }
    SStrPack(szKey, szKeyName, 0x104);
    void* hKey;
    unsigned long nDisposition;
    long nError = RegCreateKeyExA((nFlags & 4) ? (void*)0x80000002 : (void*)0x80000001, szKey, 0, 0, 0, 0x20006, 0, &hKey, &nDisposition);
    if (!nError)
    {
        nError = RegSetValueExA(hKey, szValueName, 0, dwType, pData, cbData);
        if (!nError)
        {
            if (nFlags & 8)
            {
                nError = RegFlushKey(hKey);
            }
            if (!nError)
            {
                nError = RegCloseKey(hKey);
                if (!nError)
                {
                    return 1;
                }
            }
        }
        RegCloseKey(hKey);
    }
    SetLastError(nError);
    return 0;
}

// 0x00414D90
int __stdcall SRegDeleteValue(const char* szKeyName, const char* szValueName, unsigned int nFlags)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*szValueName);
    VALIDATEEND;
    return InternalDeleteEntry(nFlags, szKeyName, szValueName);
}

// 0x00414DE0
int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*szValueName);
    VALIDATEEND;

    unsigned long dwType;
    unsigned long dwBytesRead;
    if (!pcbData)
        pcbData = &dwBytesRead;
    return LoadRegistryEntry(szKeyName, szValueName, nFlags, &dwType, pData, nSize, pcbData);
}

// 0x00414E50
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*szValueName);
    VALIDATE(szBuffer);
    VALIDATE(nBufferSize);
    VALIDATEEND;

    unsigned long nType;
    unsigned long cbData;
    if (!LoadRegistryEntry(szKeyName, szValueName, nFlags, &nType, (unsigned char*)szBuffer, nBufferSize, &cbData))
    {
        return 0;
    }
    switch (nType)
    {
    case 4:
        wsprintfA(szBuffer, gszFmtUnsigned, *(unsigned long*)szBuffer);
        return 1;
    case 1:
    {
        unsigned long nEnd = nBufferSize - 1;
        if (nEnd >= cbData)
        {
            nEnd = cbData;
        }
        szBuffer[nEnd] = 0;
        break;
    }
    }
    return 1;
}

// 0x00414F10
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*szValueName);
    VALIDATE(pValue);
    VALIDATEEND;

    unsigned long nType;
    unsigned long cbData;
    char szData[0x100];
    szData[0] = 0;
    if (!LoadRegistryEntry(szKeyName, szValueName, nFlags, &nType, (unsigned char*)szData, 0x100, &cbData))
    {
        return 0;
    }
    switch (nType)
    {
    case 4:
        *pValue = *(unsigned long*)szData;
        break;
    case 1:
        *pValue = strtoul(szData, 0, 0);
        break;
    }
    return nValid ? 1 : 0;
}

// 0x00415000
int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned long nSize)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*szValueName);
    VALIDATEEND;
    if (!pData)
    {
        pData = "";
    }
    return InternalSaveEntry(szKeyName, szValueName, nFlags, ((nFlags & 0x80) | 0x60) >> 5, (const unsigned char*)pData, nSize);
}

// 0x00415070
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*szValueName);
    VALIDATE(szString);
    VALIDATEEND;
    return nValid ? InternalSaveEntry(szKeyName, szValueName, nFlags, 1, (const unsigned char*)szString, SStrLen(szString) + 1) : 0;
}

// 0x004150E0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue)
{
    VALIDATEBEGIN;
    VALIDATE(szKeyName);
    VALIDATE(*szKeyName);
    VALIDATE(szValueName);
    VALIDATE(*szValueName);
    VALIDATEEND;
    return InternalSaveEntry(szKeyName, szValueName, nFlags, 4, (const unsigned char*)&dwValue, 4);
}

extern "C" const char gData_006CEF68[4] = "%u"; // 0x006CEF68
#pragma comment(linker, "/alternatename:_gszFmtUnsigned_006CEF68=_gData_006CEF68")
