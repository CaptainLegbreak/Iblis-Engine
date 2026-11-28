#include "D2Hell.h"
#include "D2Win32System.h"
#include "D2Win32StartupInfo.h"
#include "D2StormLink.h"
#include "D2SysTypes.h"
#include "StormApi2.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) int __stdcall CreateProcessA(const char* szApplicationName, char* szCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const char* szCurrentDirectory, D2StartupInfoAStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC33C
// 0x00516D8B
bool __fastcall sub_00516D8B_RunSurvey(const char* szExePath) {
 D2ProcessInformationStrc process;
 D2StartupInfoAStrc startup;
 startup.cb=sizeof(startup);
 memset((char*)&startup+4,0,sizeof(startup)-4);
 if(!CreateProcessA(szExePath,0,0,0,0,0,0,0,&startup,&process)) return false;
 CloseHandle(process.hProcess);
 CloseHandle(process.hThread);
 return true;
}

int __fastcall sub_00517AD6_Check(void* pContext); // 0x00517AD6
bool __fastcall sub_00517C30_Read(void* pContext, char* pBuffer, int nSize); // 0x00517C30
int __cdecl sub_00686040_Compare(const void* pA, const void* pB, unsigned int nSize); // 0x00686040
extern const char* gpReference; // 0x0072F9F0

// 0x00516DE1
bool __fastcall sub_00516DE1_Verify(void* pContext)
{
    char szBuffer[0x200];
    if (sub_00517AD6_Check(pContext))
    {
        return false;
    }
    bool bResult = sub_00517C30_Read(pContext, szBuffer, sizeof(szBuffer));
    if (bResult)
    {
        bResult = sub_00686040_Compare(szBuffer, gpReference, sizeof(szBuffer)) == 0;
    }
    return bResult;
}

typedef void (__stdcall* B27RecordHandler)(int, int, int);
typedef int (__cdecl* B27UIAction)();
extern "C" int __cdecl NPCMENU_ResurrectMercWait(); // 0x004B1DD0
extern "C" int __cdecl NPCMENU_IdentifyItemsWait(); // 0x004B2020
extern "C" unsigned int gnImbueMenuState;
extern "C" unsigned short gB27_00726CCB;
extern "C" unsigned int gB27_00726CDB;
extern "C" unsigned int gnHireMenuState;
extern "C" unsigned short gB27_00726E01;
extern "C" unsigned int gB27_00726E0F;
extern "C" unsigned int gnTravelLutGholeinState;
extern "C" unsigned short gB27_00726E4F;
extern "C" unsigned int gB27_00726E5D;
extern "C" unsigned int gnTravelKurastDocksState;
extern "C" unsigned short gB27_00726E9D;
extern "C" unsigned int gB27_00726EAB;
extern "C" unsigned int gnIdentifyMenu1State;
extern "C" unsigned short gwIdentifyMenu1StringId;
extern "C" B27UIAction gpfnIdentifyMenu1Handler;
extern "C" unsigned int gnIdentifyMenu2State;
extern "C" unsigned short gwIdentifyMenu2StringId;
extern "C" B27UIAction gpfnIdentifyMenu2Handler;
extern "C" unsigned int gnIdentifyMenu3State;
extern "C" unsigned short gwIdentifyMenu3StringId;
extern "C" B27UIAction gpfnIdentifyMenu3Handler;
extern "C" unsigned int gnIdentifyMenu4State;
extern "C" unsigned short gwIdentifyMenu4StringId;
extern "C" B27UIAction gpfnIdentifyMenu4Handler;
extern "C" unsigned int gnTravelHarrogathState;
extern "C" unsigned short gwTravelHarrogathStringId;
extern "C" unsigned short gB27_00726F87;
extern "C" unsigned int gpfnTravelHarrogathHandler;
extern "C" unsigned int gB27_00726F95;
extern "C" unsigned int gnIdentifyMenu5State;
extern "C" unsigned short gwIdentifyMenu5StringId;
extern "C" B27UIAction gpfnIdentifyMenu5Handler;
extern "C" unsigned int gnSocketMenuState;
extern "C" unsigned short gB27_00727247;
extern "C" unsigned int gB27_00727257;
extern "C" unsigned int gnPersonalizeMenuState;
extern "C" unsigned short gB27_00727297;
extern "C" unsigned int gB27_007272A9;
extern "C" unsigned int gnResurrectMenuState;
extern "C" unsigned short gB27_007272E1;
extern "C" B27UIAction gpfnResurrectMenuHandler;
extern "C" unsigned int gB27_007272EF;
extern "C" int gB27_007BCBF0;
extern "C" { B27RecordHandler gpfnRecordHandler; } // 0x00881834
extern "C" unsigned int gnVirtualPlayerCount;

// build: symbol _CUNIT_IsInvPanelTradeMode 0x00489840
extern "C" int __cdecl INV_IsInvPanelTradeMode()
{
    int mode = gB27_007BCBF0;
    if (mode == 1 || mode == 2 || mode == 3)
        return 1;
    return 0;
}

extern "C" void __cdecl QUESTLOG_ResetQuestButtonState(); // 0x004A3000

extern "C" void __fastcall QUESTLOG_SetQuestPacketValue(unsigned int value); // 0x004A3100

// build: symbol _NPCMENU_ResetHandlers 0x004B2250
extern "C" void __cdecl NPCMENU_ResetHandlers()
{
    bool oldAction = (gpfnResurrectMenuHandler == NPCMENU_ResurrectMercWait);
    gnHireMenuState = 2;
    gB27_00726E01 = 0;
    gB27_00726E0F = 0;
    gnTravelLutGholeinState = 2;
    gB27_00726E4F = 0;
    gB27_00726E5D = 0;
    gnTravelKurastDocksState = 2;
    gB27_00726E9D = 0;
    gB27_00726EAB = 0;
    gnImbueMenuState = 3;
    gB27_00726CCB = 0;
    gB27_00726CDB = 0;
    gnResurrectMenuState = 2;
    gB27_007272E1 = 0;
    gB27_007272EF = 0;
    if (oldAction)
        gnResurrectMenuState = 3;
    gB27_00727247 = 0;
    gB27_00727257 = 0;
    gB27_00727297 = 0;
    gB27_007272A9 = 0;
    gnTravelHarrogathState = 2;
    gB27_00726F87 = 0;
    gB27_00726F95 = 0;
    gwTravelHarrogathStringId = 0;
    gpfnTravelHarrogathHandler = 0;
    gnSocketMenuState = 3;
    gnPersonalizeMenuState = 4;
    gwIdentifyMenu1StringId = 0xfb4;
    gpfnIdentifyMenu1Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu1State = 3;
    gwIdentifyMenu2StringId = 0xfb4;
    gpfnIdentifyMenu2Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu2State = 3;
    gwIdentifyMenu3StringId = 0xfb4;
    gpfnIdentifyMenu3Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu3State = 3;
    gwIdentifyMenu4StringId = 0xfb4;
    gpfnIdentifyMenu4Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu4State = 3;
    gwIdentifyMenu5StringId = 0xfb4;
    gpfnIdentifyMenu5Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu5State = 3;
}

// 0x005173D3
extern "C" B27RecordHandler __fastcall sub_005173D3_ExchangeRecordHandler(B27RecordHandler handler)
{
    B27RecordHandler previous = gpfnRecordHandler;
    gpfnRecordHandler = handler;
    return previous;
}

// build: symbol @PLAYER_SetVirtualPlayerCount@* 0x00535780
extern "C" void __fastcall PLAYER_SetVirtualPlayerCount(unsigned int count)
{
    if (count <= 8)
        gnVirtualPlayerCount = count;
}

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* process, unsigned int exitCode); // 0x006CC274

// 0x005173DF
void __cdecl sub_005173DF_TerminateCurrentProcess()
{
    TerminateProcess(GetCurrentProcess(), (unsigned int)-1);
}

// 0x005174AA
int D2StormLinkStrc::sub_005174AA_Next()
{
    int nNext = (int)m_next;
    if (nNext <= 0)
    {
        nNext = 0;
    }
    return nNext;
}

// 0x005174B4
int D2StormLinkStrc::sub_005174B4_RawNext()
{
    return (int)m_next;
}

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*,const char*,const char*,unsigned int); // 0x006CC464

#define D2_IMPORT __declspec(dllimport)

extern "C" D2_IMPORT int __stdcall MessageBoxA(void* window, const char* text, const char* caption, unsigned int flags);
extern "C" D2_IMPORT int __cdecl wsprintfA(char* buffer, const char* format, ...);

typedef void (__stdcall* FaultAssertHandler)(const char*, unsigned int, const char*);

extern FaultAssertHandler sgpfnAssertHandler; // 0x00881834
extern const char* const gpszModuleName; // 0x006CC848
extern const char sgszAssertFormatString[]; // 0x006DEBE8
void __cdecl sub_005173DF_TerminateCurrentProcess(); // 0x005173DF
extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

struct CERT_CONTEXT;

struct GUID;

struct TRUSTFILEINFO;

struct TRUSTDATA;

struct CRYPT_INTEGER_BLOB;

struct CRYPT_ALGORITHM_IDENTIFIER;

struct CRYPT_BIT_BLOB;

struct FILETIME;

struct CERT_PUBLIC_KEY_INFO;

struct CERT_INFO;

struct CMSG_SIGNER_INFO;

void __fastcall sub_00517804_GetText(unsigned int, char*, unsigned int); // 0x00517804

void __cdecl sub_005173DF_TerminateCurrentProcess(); // 0x005173DF

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char*, const char*, char*); // 0x006CC4AC

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void*, const char*, const char*, unsigned int); // 0x006CC464

void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

typedef unsigned long DWORD;

typedef long LONG;

typedef void* HANDLE;

typedef void* HWND;

struct GUID { unsigned long Data1; unsigned short Data2; unsigned short Data3; unsigned char Data4[8]; };

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int CodePage, DWORD dwFlags, const char* lpMultiByteStr, int cbMultiByte, wchar_t* lpWideCharStr, int cchWideChar); // 0x006CC29C

extern "C" __declspec(dllimport) DWORD __stdcall GetLastError(void); // 0x006CC1B4

void* __cdecl operator new(unsigned int nSize); // 0x00405410

void __cdecl operator delete(void* pMemory); // 0x004053F0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct TRUSTFILEINFO
{
    DWORD cbStruct;
    const wchar_t* pcwszFilePath;
    HANDLE hFile;
    GUID* pgKnownSubject;
};

struct TRUSTDATA
{
    DWORD cbStruct;
    void* pPolicyCallbackData;
    void* pSIPClientData;
    DWORD dwUIChoice;
    DWORD fdwRevocationChecks;
    DWORD dwUnionChoice;
    TRUSTFILEINFO* pFile;
    DWORD dwStateAction;
    HANDLE hWVTStateData;
    wchar_t* pwszURLReference;
    DWORD dwProvFlags;
    DWORD dwUIContext;
};

extern "C" LONG __stdcall BNCLIENT_WinVerifyTrust(HWND hWnd, GUID* pgActionID, void* pWVTData); // 0x006B00F6

typedef void* HCERTSTORE;

typedef void* HCRYPTMSG;

struct CRYPT_INTEGER_BLOB { DWORD cbData; unsigned char* pbData; };

struct CRYPT_ALGORITHM_IDENTIFIER { char* pszObjId; CRYPT_INTEGER_BLOB Parameters; };

struct CRYPT_BIT_BLOB { DWORD cbData; unsigned char* pbData; DWORD cUnusedBits; };

struct FILETIME { DWORD dwLowDateTime; DWORD dwHighDateTime; };

struct CERT_PUBLIC_KEY_INFO { CRYPT_ALGORITHM_IDENTIFIER Algorithm; CRYPT_BIT_BLOB PublicKey; };

struct CERT_INFO
{
    DWORD dwVersion;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CRYPT_INTEGER_BLOB Issuer;
    FILETIME NotBefore;
    FILETIME NotAfter;
    CRYPT_INTEGER_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    CRYPT_BIT_BLOB IssuerUniqueId;
    CRYPT_BIT_BLOB SubjectUniqueId;
    DWORD cExtension;
    void* rgExtension;
};

struct CMSG_SIGNER_INFO
{
    DWORD dwVersion;
    CRYPT_INTEGER_BLOB Issuer;
    CRYPT_INTEGER_BLOB SerialNumber;
};

extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int CodePage, DWORD dwFlags, const wchar_t* lpWideCharStr, int cchWideChar, char* lpMultiByteStr, int cbMultiByte, const char* lpDefaultChar, int* lpUsedDefaultChar); // 0x006CC194

extern "C" __declspec(dllimport) void* __stdcall LocalAlloc(unsigned int uFlags, unsigned int uBytes); // 0x006CC380

extern "C" __declspec(dllimport) void* __stdcall LocalFree(void* hMem); // 0x006CC37C

extern "C" __declspec(dllimport) int __stdcall CryptQueryObject(DWORD dwObjectType, const void* pvObject, DWORD dwExpectedContentTypeFlags, DWORD dwExpectedFormatTypeFlags, DWORD dwFlags, DWORD* pdwMsgAndCertEncodingType, DWORD* pdwContentType, DWORD* pdwFormatType, HCERTSTORE* phCertStore, HCRYPTMSG* phMsg, const void** ppvContext); // 0x006CC064

extern "C" __declspec(dllimport) int __stdcall CryptMsgGetParam(HCRYPTMSG hCryptMsg, DWORD dwParamType, DWORD dwIndex, void* pvData, DWORD* pcbData); // 0x006CC060

extern "C" __declspec(dllimport) const CERT_CONTEXT* __stdcall CertFindCertificateInStore(HCERTSTORE hCertStore, DWORD dwCertEncodingType, DWORD dwFindFlags, DWORD dwFindType, const void* pvFindPara, const CERT_CONTEXT* pPrevCertContext); // 0x006CC05C

extern "C" __declspec(dllimport) DWORD __stdcall CertGetNameStringW(const CERT_CONTEXT* pCertContext, DWORD dwType, DWORD dwFlags, void* pvTypePara, wchar_t* pszNameString, DWORD cchNameString); // 0x006CC070

extern "C" __declspec(dllimport) int __stdcall CertFreeCertificateContext(const CERT_CONTEXT* pCertContext); // 0x006CC058

extern "C" __declspec(dllimport) int __stdcall CertCloseStore(HCERTSTORE hCertStore, DWORD dwFlags); // 0x006CC068

extern "C" __declspec(dllimport) int __stdcall CryptMsgClose(HCRYPTMSG hCryptMsg); // 0x006CC06C

// 0x005173EF
int __fastcall sub_005173EF_FatalBox(const char* text) {
 MessageBoxA(0,text,gpszModuleName,0x2010);
 sub_005173DF_TerminateCurrentProcess();
 return 0;
}

// 0x0051740B
int __fastcall sub_0051740B_ErrorBox(const char* text) {
 MessageBoxA(0,text,gpszModuleName,0x2010);
 return 1;
}
// 0x00517423
int __fastcall FaultDoAssert(const char* szFile, unsigned int nLine, const char* szExpression)
{
    char Text[512];

    if (sgpfnAssertHandler)
        sgpfnAssertHandler(szFile, nLine, szExpression);
    wsprintfA(Text, sgszAssertFormatString, szFile, nLine, szExpression);
    const int buttonID = MessageBoxA(0, Text, gpszModuleName, 0x52212);
    if (buttonID == 3) {
        sub_005173DF_TerminateCurrentProcess();
        return 1;
    }
    return buttonID == 4;
}

// 0x005174B8
void D2StormLinkStrc::sub_005174B8_Clear()
{
    m_prevlink = 0;
    m_next = 0;
}

// 0x00517874
int __cdecl sub_00517874_ShowError(unsigned int message, ...)
{
 char format[512];
 char text[512];
 sub_00517804_GetText(message, format, sizeof(format));
 wvsprintfA(text, format, (char*)(&message+1));
 int result;
 if(MessageBoxA(0,text,gpszModuleName,0x2215)==4) result=1;
 else {sub_005173DF_TerminateCurrentProcess();result=0;}
 return result;
}

// 0x005179B3
void __fastcall sub_005179B3_CopyRect(unsigned char* pDest, const unsigned char* pSource, int nDestPitch, int nSourcePitch, int nRows, int nWidth)
{
    int nSourceSkip = nSourcePitch - nWidth;
    int nDestSkip = nDestPitch - nWidth;
    __asm
    {
        mov edi, pDest
        mov esi, pSource
        mov ebx, nRows
    nextrow:
        mov edx, nWidth
        mov ecx, edx
        and edx, 3
        je dwords
        cmp edx, 1
        je one
        cmp edx, 2
        je two
        mov al, [esi]
        mov [edi], al
        mov al, [esi + 1]
        mov [edi + 1], al
        mov al, [esi + 2]
        mov [edi + 2], al
        add edi, 3
        add esi, 3
        jmp dwords
    two:
        mov al, [esi]
        mov [edi], al
        mov al, [esi + 1]
        mov [edi + 1], al
        add edi, 2
        add esi, 2
        jmp dwords
    one:
        mov al, [esi]
        mov [edi], al
        inc edi
        inc esi
    dwords:
        shr ecx, 2
        rep movsd
        add esi, nSourceSkip
        add edi, nDestSkip
        dec ebx
        jne nextrow
    }
}

// 0x00517A36
int __fastcall sub_00517A36_CompareMemory(const void* pFirst, const void* pSecond, unsigned int nSize)
{
    __asm
    {
        mov edi, pFirst
        mov esi, pSecond
        mov edx, nSize
        mov ecx, edx
        and edx, 3
        je dwords
        cmp edx, 1
        je one
        cmp edx, 2
        je two
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        mov al, [esi + 1]
        mov bl, [edi + 1]
        cmp al, bl
        jne different
        mov al, [esi + 2]
        mov bl, [edi + 2]
        cmp al, bl
        jne different
        add edi, 3
        add esi, 3
        jmp dwords
    two:
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        mov al, [esi + 1]
        mov bl, [edi + 1]
        cmp al, bl
        jne different
        add edi, 2
        add esi, 2
        jmp dwords
    one:
        mov al, [esi]
        mov bl, [edi]
        cmp al, bl
        jne different
        inc edi
        inc esi
    dwords:
        shr ecx, 2
        repe cmpsd
        jne different
    }
    return 1;
different:
    return 0;
}

// 0x00517ABB
int __cdecl sub_00517ABB_FindLowestSetBit(unsigned int dwMask)
{
    int nIndex;
    if (!dwMask)
        return 0;
    __asm
    {
        bsf eax, dwMask
        inc eax
        mov nIndex, eax
    }
    return nIndex;
}

// 0x00517AD6
int __fastcall sub_00517AD6_VerifyFileTrust(const char* szPath)
{
    if (!szPath || !*szPath)
        return 4;

    int nLen = MultiByteToWideChar(0, 0, szPath, -1, 0, 0);
    if (nLen <= 0)
        return 4;

    wchar_t* wszPath = new wchar_t[nLen];
    MultiByteToWideChar(0, 0, szPath, -1, wszPath, nLen);

    TRUSTFILEINFO tFile;
    memset(&tFile, 0, sizeof(tFile));
    tFile.cbStruct = sizeof(tFile);
    tFile.pcwszFilePath = wszPath;
    tFile.hFile = 0;
    tFile.pgKnownSubject = 0;

    GUID tAction = { 0x00AAC56B, 0xCD44, 0x11D0, { 0x8C, 0xC2, 0x00, 0xC0, 0x4F, 0xC2, 0x95, 0xEE } };

    TRUSTDATA tData;
    memset(&tData, 0, sizeof(tData));
    tData.cbStruct = sizeof(tData);
    tData.pPolicyCallbackData = 0;
    tData.pSIPClientData = 0;
    tData.dwUIChoice = 2;
    tData.fdwRevocationChecks = 0;
    tData.dwUnionChoice = 1;
    tData.pFile = &tFile;
    tData.dwStateAction = 0;
    tData.hWVTStateData = 0;
    tData.pwszURLReference = 0;
    tData.dwUIContext = 0;

    LONG nResult = BNCLIENT_WinVerifyTrust(0, &tAction, &tData);
    int nRet;
    switch (nResult)
    {
    case 0x80092026:
    case 0x800B0004:
    case 0x800B0111:
        nRet = 3;
        break;
    case 0x800B0100:
        nRet = (GetLastError() != 0x800B0100) + 1;
        break;
    default:
        nRet = nResult ? 4 : 0;
        break;
    }

    delete wszPath;
    return nRet;
}

// build: symbol __SEH_prolog4 0x00687FB0
// build: symbol __SEH_epilog4 0x00687FF5
// 0x00517C30
bool __fastcall sub_00517C30_GetSignerOrganization(const char* szFilePath, char* szName, int nNameSize)
{
    bool bResult;
    int nLen;
    HCRYPTMSG hMsg;
    const CERT_CONTEXT* pCertContext;
    CMSG_SIGNER_INFO* pSignerInfo;
    HCERTSTORE hStore;
    wchar_t* wszFilePath;
    DWORD dwSignerInfo;

    if (!szFilePath || !*szFilePath)
        return false;

    nLen = MultiByteToWideChar(0xFDE9, 0, szFilePath, -1, 0, 0);
    if (nLen <= 0)
        return false;

    wszFilePath = new wchar_t[nLen];
    MultiByteToWideChar(0xFDE9, 0, szFilePath, -1, wszFilePath, nLen);

    bResult = false;
    hStore = 0;
    hMsg = 0;
    pCertContext = 0;
    pSignerInfo = 0;
    __try
    {
        int bOk = CryptQueryObject(1, wszFilePath, 0x400, 2, 0, 0, 0, 0, &hStore, &hMsg, 0);
        if (!bOk)
            __leave;

        bOk = CryptMsgGetParam(hMsg, 6, 0, 0, &dwSignerInfo);
        if (!bOk)
            __leave;

        pSignerInfo = (CMSG_SIGNER_INFO*)LocalAlloc(0x40, dwSignerInfo);
        if (!pSignerInfo)
            __leave;

        bOk = CryptMsgGetParam(hMsg, 6, 0, pSignerInfo, &dwSignerInfo);
        if (!bOk)
            __leave;

        CERT_INFO tCertInfo;
        tCertInfo.Issuer = pSignerInfo->Issuer;
        tCertInfo.SerialNumber = pSignerInfo->SerialNumber;
        pCertContext = CertFindCertificateInStore(hStore, 0x10001, 0, 0xB0000, &tCertInfo, 0);
        if (!pCertContext)
            __leave;

        DWORD dwNameLen = CertGetNameStringW(pCertContext, 3, 0, "2.5.4.10", 0, 0);
        if (!dwNameLen)
            __leave;

        wchar_t* wszName = new wchar_t[dwNameLen];
        if (CertGetNameStringW(pCertContext, 3, 0, "2.5.4.10", wszName, dwNameLen))
        {
            int nSize = WideCharToMultiByte(0xFDE9, 0, wszName, -1, 0, 0, 0, 0);
            if (nSize > 0)
            {
                WideCharToMultiByte(0xFDE9, 0, wszName, -1, szName, nNameSize, 0, 0);
                bResult = true;
            }
        }
        delete wszName;
    }
    __finally
    {
        if (pSignerInfo)
            LocalFree(pSignerInfo);
        if (pCertContext)
            CertFreeCertificateContext(pCertContext);
        if (hStore)
            CertCloseStore(hStore, 0);
        if (hMsg)
            CryptMsgClose(hMsg);
    }
    return bResult;
}

// 0x005174C0
D2StormLinkStrc* __thiscall D2StormLinkStrc::sub_005174C0(int nLinkOffset)
{
    int nNextLink = (int)m_next;
    if (nNextLink < 0)
    {
        return (D2StormLinkStrc*)~nNextLink;
    }

    if (nLinkOffset < 0)
    {
        nLinkOffset = (int)this - (int)m_prevlink->m_next;
    }

    return (D2StormLinkStrc*)(nNextLink + nLinkOffset);
}

struct TSLink
{
    TSLink* m_prevlink;
    void* m_next;

    TSLink* NextLink(int nLinkOffset);  // 0x005174C0
    void Unlink();
    TSLink* sub_005176B4_DeletingDtor(unsigned int nFlags);
};

// 0x005174E2
void TSLink::Unlink()
{
    TSLink* pPrev = m_prevlink;
    if (pPrev)
    {
        NextLink(-1)->m_prevlink = pPrev;
        m_prevlink->m_next = m_next;
        m_prevlink = 0;
        m_next = 0;
    }
}

struct D2StormListStrc;
struct D2PositiveCountStrc;

struct D2StormListStrc {
 int m_linkoffset;
 D2StormLinkStrc m_terminator;
 D2StormLinkStrc* sub_0051752F_GetLink(char* node);
 void sub_00517546_Initialize(int offset);
 void sub_0051755C_LinkNode(char* node,unsigned int linkType,char* existing);
 char* sub_005175CB_Next(char* node);
 char* sub_00517607_RawNext(char* node);
 char* sub_00517669_NewNode(unsigned int linkType,unsigned int extraBytes,unsigned int flags);
 char* sub_0051772A_DeleteNode(char* node);
};

struct D2PositiveCountStrc {
    int unknown00;
    int unknown04;
    int count;
};

// 0x00517507
void __fastcall sub_00517507_InitList(D2StormListStrc* pList)
{
    D2StormLinkStrc* pTerminator = &pList->m_terminator;
    pTerminator->m_prevlink = pTerminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)pTerminator;
}

// 0x00517512
unsigned int __fastcall sub_00517512_Add(unsigned int first, unsigned int second)
{
    return first + second;
}

// 0x00517516
int __fastcall sub_00517516_GetPositiveCount(D2PositiveCountStrc* data)
{
    int value = data->count;
    if (value <= 0) value = 0;
    return value;
}

void* __stdcall SMemAlloc(unsigned int,const char*,int,unsigned int);
int __stdcall SMemFree(void*,const char*,int,unsigned int);
// build: symbol ?gszRecordType@* 0x0072F9FC
extern const char gszRecordType[];
struct D2StormRecordStrc {
 D2StormLinkStrc tLink;
 int unk0x08;
// 0x00517520
 D2StormRecordStrc() {tLink.m_prevlink=0;tLink.m_next=0;}
 void sub_005176B4_Release(unsigned int flags);
};
inline void* operator new(unsigned int,void* p) throw() {return p;}


// 0x0051752A
void D2StormLinkStrc::sub_0051752A_ForwardUnlink()
{
    sub_005174E2_Unlink();
}

// 0x0051752F
D2StormLinkStrc* D2StormListStrc::sub_0051752F_GetLink(char* node) {
 if(node) return (D2StormLinkStrc*)(node+m_linkoffset);
 return &m_terminator;
}

// 0x00517546
void D2StormListStrc::sub_00517546_Initialize(int offset) {
 m_linkoffset=offset;
 m_terminator.m_prevlink=&m_terminator;
 m_terminator.m_next=(char*)~(unsigned int)&m_terminator;
}

struct D2Node0051755CStrc;

struct D2Link0051755CStrc
{
    D2Link0051755CStrc* m_prevlink;
    D2Node0051755CStrc* m_next;

    D2Link0051755CStrc* sub_005174C0_NextLink(int nLinkOffset); // 0x005174C0
    void sub_005174E2_Unlink(); // 0x005174E2
};

struct D2List0051755CStrc
{
    int m_linkoffset;
    D2Link0051755CStrc m_terminator;

    D2Link0051755CStrc* sub_0051752F_Link(D2Node0051755CStrc* pNode); // 0x0051752F
    void sub_0051755C_LinkNode(D2Node0051755CStrc* pNode, int nLinkType, D2Node0051755CStrc* pExisting);
};

// 0x0051755C
void D2List0051755CStrc::sub_0051755C_LinkNode(D2Node0051755CStrc* pNode, int nLinkType, D2Node0051755CStrc* pExisting)
{
    D2Link0051755CStrc* pLink = sub_0051752F_Link(pNode);
    if (pLink->m_prevlink)
    {
        pLink->sub_005174E2_Unlink();
    }

    D2Link0051755CStrc* pExistingLink = pExisting ? sub_0051752F_Link(pExisting) : &m_terminator;

    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->sub_005174C0_NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
    {
        D2Link0051755CStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
    }
        break;
    }
}

struct D2StormListStrc;


// 0x005175CB
char* D2StormListStrc::sub_005175CB_Next(char* node) {
 char* next=sub_0051752F_GetLink(node)->m_next;
 return (int)next<=0?0:next;
}

// 0x00517607
char* D2StormListStrc::sub_00517607_RawNext(char* node) {
 return sub_0051752F_GetLink(node)->m_next;
}

struct D2HellStormListStrc;
struct S;

struct D2HellStormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_005175E3_Initialize();
};

struct S { int a; int b; S(); };

// 0x005175E3
void D2HellStormListStrc::sub_005175E3_Initialize()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00517619
S::S() { a = 0; b = 0; }

struct D2StormFaultLinkStrc;

struct D2StormLinkFieldStrc
{
    void __thiscall sub_005174E2_Unlink(); // 0x005174E2
};

struct D2StormListHeadStrc
{
    D2StormLinkFieldStrc* __thiscall sub_0051752F_GetLink(D2StormFaultLinkStrc* pNode); // 0x0051752F
    void __thiscall sub_005175F1_UnlinkNode(D2StormFaultLinkStrc* pNode);
};

// 0x005175F1
void D2StormListHeadStrc::sub_005175F1_UnlinkNode(D2StormFaultLinkStrc* pNode)
{
    sub_0051752F_GetLink(pNode)->sub_005174E2_Unlink();
}

struct D2ListStrc {
    int nLinkOffset;
    TSLink tTerminator;
    void __thiscall sub_005175F1_UnlinkEntry(int offset); // 0x005175F1
    void __thiscall sub_0051763C_UnlinkAll();
    D2ListStrc()
    {
        nLinkOffset = 0;
        tTerminator.m_prevlink = &tTerminator;
        tTerminator.m_next = (void*)~(unsigned int)&tTerminator;
    }
    ~D2ListStrc()
    {
        sub_0051763C_UnlinkAll();
        tTerminator.Unlink();
    }
};
// 0x0051763C
void __thiscall D2ListStrc::sub_0051763C_UnlinkAll()
{
    for (;;) {
        int first = (int)tTerminator.m_next > 0 ? (int)tTerminator.m_next : 0;
        if (!first) return;
        sub_005175F1_UnlinkEntry(first);
    }
}

int __stdcall SMemFree(void*,const char*,int,unsigned int);
extern const char gszRecordType[];  // 0x0072F9FC
// 0x00517669
char* D2StormListStrc::sub_00517669_NewNode(unsigned int linkType,unsigned int extraBytes,unsigned int flags) {
 const unsigned int mask=8;
 void* memory=SMemAlloc(sizeof(D2StormRecordStrc)+extraBytes,gszRecordType,-2,flags|mask);
 D2StormRecordStrc* record=memory?new(memory) D2StormRecordStrc:0;
 if(linkType) sub_0051755C_LinkNode((char*)record,linkType,0);
 return (char*)record;
}


void __cdecl operator delete(void* pMemory);
// build: symbol ??3@YAXPAX@Z 0x004053F0

// 0x005176B4
TSLink* TSLink::sub_005176B4_DeletingDtor(unsigned int nFlags)
{
    Unlink();
    if (nFlags & 1)
        operator delete(this);
    return this;
}

struct TMESSAGESOURCE {
    int unk0;
    int unk4;
    int nHead;
    void __thiscall sub_005176B4_Destroy(int bFree); // 0x005176B4
    void __thiscall Clear();
};

extern const char gszTMESSAGESOURCE[]; // 0x0072F9FC

// 0x005176F8
void __thiscall TMESSAGESOURCE::Clear()
{
    for (;;) {
        TMESSAGESOURCE* pNode = nHead > 0 ? (TMESSAGESOURCE*)nHead : 0;
        if (!pNode) return;
        pNode->sub_005176B4_Destroy(0);
        SMemFree(pNode, gszTMESSAGESOURCE, -2, 0);
    }
}

void* __stdcall SMemAlloc(unsigned int,const char*,int,unsigned int);
extern const char gszRecordType[];  // 0x0072F9FC
// 0x0051772A
char* D2StormListStrc::sub_0051772A_DeleteNode(char* node) {
 char* next=sub_005175CB_Next(node);
 ((D2StormRecordStrc*)node)->sub_005176B4_Release(0);
 SMemFree(node,gszRecordType,-2,0);
 return next;
}

struct D2CriticalSectionStrc;
struct TMESSAGESOURCE;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC


extern TMESSAGESOURCE gFaultHandlerList_0072FA14; // 0x0072FA14
// The fault handler list's lock, and whether it has been initialised.
struct D2FaultHandlerLockStrc
{
    D2CriticalSectionStrc tLock; // 0x00
    int bInitialized; // 0x18
};

D2FaultHandlerLockStrc gtFaultHandlerLock; // 0x00881818
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
void sub_0051775A_FreeFaultHandlerList(); // 0x0051775A

// 0x0051775A
void sub_0051775A_FreeFaultHandlerList()
{
    EnterCriticalSection(&gtFaultHandlerLock.tLock);
    gFaultHandlerList_0072FA14.Clear();
    LeaveCriticalSection(&gtFaultHandlerLock.tLock);
    DeleteCriticalSection(&gtFaultHandlerLock.tLock);
    gtFaultHandlerLock.bInitialized = 0;
}


// Body of 0x00517788; 0x005177B2 carries it inlined.
static __forceinline void InitFaultHandlerListInline()
{
    if (!gtFaultHandlerLock.bInitialized) {
        InitializeCriticalSection(&gtFaultHandlerLock.tLock);
        atexit(sub_0051775A_FreeFaultHandlerList);
        gtFaultHandlerLock.bInitialized = 1;
    }
}

// 0x00517788
void sub_00517788_InitFaultHandlerList()
{
    InitFaultHandlerListInline();
}

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824


void sub_0051775A_FreeFaultHandlerList(); // 0x0051775A

extern D2StormListStrc gtFaultHandlerRecords_0072FA14; // 0x0072FA14


// 0x005177B2
void __fastcall sub_005177B2_SetLoadStringFn(void* pfnLoadString)
{
    InitFaultHandlerListInline();
    EnterCriticalSection(&gtFaultHandlerLock.tLock);
    char* pNode = gtFaultHandlerRecords_0072FA14.sub_00517669_NewNode(1, 0, 0);
    *(void**)(pNode + 8) = pfnLoadString;
    LeaveCriticalSection(&gtFaultHandlerLock.tLock);
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

struct D2MessageNode;
struct D2MessageLink {
 D2MessageLink* m_prevlink; D2MessageNode* m_next;
 D2MessageNode* Next() {return (int)m_next>0?m_next:0;}
};
struct D2MessageNode {
 D2MessageLink link;
 int (__stdcall* callback)(unsigned int,char*,unsigned int);
};
struct D2MessageList {
 int m_linkoffset;
 D2MessageLink m_terminator;
 D2MessageLink* Link(char* node) {return node?(D2MessageLink*)(node+m_linkoffset):&m_terminator;}
 D2MessageNode* Head(){return m_terminator.Next();}
};
extern D2MessageList gtMessages;  // 0x0072FA14
extern "C" const char gszFaultError[];  // 0x006DEBCC
// 0x00517804
void __fastcall sub_00517804_GetMessage(unsigned int id,char* dest,unsigned int size) {
 if(gtFaultHandlerLock.bInitialized) {
  EnterCriticalSection(&gtFaultHandlerLock.tLock);
  D2MessageNode* p=gtMessages.Head();
  for(; (int)p>0; p=gtMessages.Link((char*)p)->m_next) {
   if(p->callback(id,dest,size)) {
    LeaveCriticalSection(&gtFaultHandlerLock.tLock);
    return;
   }
  }
  LeaveCriticalSection(&gtFaultHandlerLock.tLock);
 }
 SStrCopy(dest,gszFaultError,size);
}

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char*,const char*,char*);  // 0x006CC4AC
void __fastcall sub_00517804_GetMessage(unsigned int,char*,unsigned int);
void __fastcall sub_005173EF_Display(const char*);
#define BUFFER_SIZE 512
// 0x005178E9
void __cdecl sub_005178E9_Format(unsigned int id,...) {
 char formatted[BUFFER_SIZE];
 char format[BUFFER_SIZE];
 sub_00517804_GetMessage(id,format,BUFFER_SIZE);
 wvsprintfA(formatted,format,(char*)(&id+1));
 sub_005173EF_Display(formatted);
}

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* pArgs);
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
void __fastcall sub_00517804_GetMessage(unsigned int id,char* dest,unsigned int size); // 0x00517804
int __fastcall sub_0051740B_ErrorBox(const char* szText); // 0x0051740B

// 0x0051793E
void __cdecl sub_0051793E_FormatAndRaise(unsigned long dwError, ...)
{
    char szText[512];
    char szFormat[512];

    sub_00517804_GetMessage(dwError, szFormat, sizeof(szFormat));
    char* pArgs = (char*)&dwError + sizeof(dwError);
    wvsprintfA(szText, szFormat, pArgs);
    sub_0051740B_ErrorBox(szText);
}

#define D2_IMPORT __declspec(dllimport)

extern "C" D2_IMPORT void* __stdcall VirtualAlloc(void* address, unsigned int size, unsigned int allocationType, unsigned int protection); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, unsigned int size, unsigned int freeType); // 0x006CC220

// 0x00517993
void* __fastcall sub_00517993_AllocateVirtualMemory(unsigned int size)
{
    return VirtualAlloc(0, size, 0x3000, 0x40);
}

// 0x005179A4
void __fastcall sub_005179A4_FreeVirtualMemory(void* address)
{
    VirtualFree(address, 0, 0x8000);
}



// The fault-handler list: its constructor's constant stores are static data, the
// terminator mark is set by the initializer 0x006CAE5F, and 0x006CB401 is its atexit destructor.
// build: symbol ??__EgFaultHandlerList@@YAXXZ 0x006CAE5F
// build: symbol ??__FgFaultHandlerList@@YAXXZ 0x006CB401
D2ListStrc gFaultHandlerList; // 0x0072FA14

#pragma pack(push, 1)
struct d2data_006DEBE8_t
{
    unsigned char b0[112];
    const void* p1;
    const void* p2;
};
#pragma pack(pop)

extern "C" const char* const gData_006CC848 = "Diablo 2.EXE"; // 0x006CC848
#pragma comment(linker, "/alternatename:?gpszModuleName@@3QBDB=_gData_006CC848")

extern "C" const struct d2data_006DEBE8_t gData_006DEBE8 = { // 0x006DEBE8
    {
        0x41, 0x6E, 0x20, 0x61, 0x73, 0x73, 0x65, 0x72, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x68, 0x61, 0x73,
        0x20, 0x66, 0x61, 0x69, 0x6C, 0x65, 0x64, 0x2E, 0x0A, 0x0A, 0x46, 0x69, 0x6C, 0x65, 0x3A, 0x09,
        0x09, 0x25, 0x73, 0x0A, 0x4C, 0x69, 0x6E, 0x65, 0x3A, 0x09, 0x09, 0x25, 0x64, 0x0A, 0x45, 0x78,
        0x70, 0x72, 0x65, 0x73, 0x73, 0x69, 0x6F, 0x6E, 0x3A, 0x09, 0x25, 0x73, 0x0A, 0x0A, 0x41, 0x62,
        0x6F, 0x72, 0x74, 0x20, 0x74, 0x6F, 0x20, 0x65, 0x78, 0x69, 0x74, 0x2C, 0x20, 0x52, 0x65, 0x74,
        0x72, 0x79, 0x20, 0x74, 0x6F, 0x20, 0x62, 0x72, 0x65, 0x61, 0x6B, 0x2C, 0x20, 0x49, 0x67, 0x6E,
        0x6F, 0x72, 0x65, 0x20, 0x74, 0x6F, 0x20, 0x63, 0x6F, 0x6E, 0x74, 0x69, 0x6E, 0x75, 0x65, 0x00
    },
    sgszAssertFormatString,
    "D2Hell Fault.cpp error."
};
#pragma comment(linker, "/alternatename:?sgszAssertFormatString@@3QBDB=_gData_006DEBE8")

extern const char* gpReference = "Blizzard Entertainment, Inc."; // 0x0072F9F0

extern "C" const char* gData_0072F9F4[2] = { "~Nh", 0 }; // 0x0072F9F4

extern "C" const char gData_0072F9FC[24] = ".?AUTMESSAGESOURCE@@"; // 0x0072F9FC
#pragma comment(linker, "/alternatename:?gszRecordType@@3QBDB=_gData_0072F9FC")

extern "C" const char* gData_0072FA20[32] = { // 0x0072FA20
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
    "14",
    0,
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
    "14",
    0
};
