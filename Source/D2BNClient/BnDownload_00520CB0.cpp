#include "D2Primitives.h"

#include "D2BNClient.h"

#include "D2BnCryptTypes.h"
#include "D2BnMessages.h"

typedef unsigned int size_t;

extern "C" size_t __cdecl strlen(const char* szString);

#pragma intrinsic(strlen)



int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl BNDOWNLOAD_ConfigureLog(int nMode, int nValue);                                               // 0x00518C70

void __cdecl BNDOWNLOAD_LogPrintf(const char* szFormat, ...);                                                   // 0x00518D40

void __fastcall sub_0051A540_SetValue(int nValue);                                                          // 0x0051A540

int __fastcall BNDOWNLOAD_SetCheckRevisionValue(const char* szValue);                                    // 0x0051E3B0

void __fastcall BNDOWNLOAD_RequestDownload(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910

extern "C" const char gszConfiguration[];                                                           // 0x006DEC7C

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

struct D2BnAuthInfoStrc;


void __fastcall sub_0051A560_SetValue(int nValue); // 0x0051A560

int __fastcall BNDOWNLOAD_SetArchiveName(const char* szName); // 0x0051EA80

unsigned int __fastcall BNDOWNLOAD_MulAddWords(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry); // 0x005225E0

void __fastcall BNDOWNLOAD_DecodeKeyDigits(const char* szKey, unsigned char* pOut); // 0x00522650

void __stdcall BNDOWNLOAD_SubstituteKeyNibbles(unsigned int* pKey); // 0x00522980

// build: symbol ?BNDOWNLOAD_PermuteKeyBits@* 0x005226D0
__declspec(noinline) static unsigned int __fastcall BNDOWNLOAD_PermuteKeyBits(int nUnused, unsigned int* pKey);

// 0x00520CB0
int __fastcall BNDOWNLOAD_HandleClientId(const D2BnClientIdReplyStrc* pData, unsigned int nSize)
{
    if (!pData || nSize < 0x10)
    {
        BNDOWNLOAD_LogPrintf("ERROR BDClientId: invalid response");
        return 0;
    }

    unsigned int nRegistrationVersion = pData->dwRegistrationVersion;
    unsigned int nRegistrationAuthority = pData->dwRegistrationAuthority;
    unsigned int nClientId = pData->dwClientId;
    unsigned int nClientToken = pData->dwRegistrationToken;
    SRegSaveValue(gszConfiguration, "Registration Version", 2, nRegistrationVersion);
    SRegSaveValue(gszConfiguration, "Registration Authority", 2, nRegistrationAuthority);
    SRegSaveValue(gszConfiguration, "Client ID", 2, nClientId);
    SRegSaveValue(gszConfiguration, "Client Token", 2, nClientToken);
    BNDOWNLOAD_ConfigureLog(2, 4);
    BNDOWNLOAD_LogPrintf("client acknowledged");
    BNDOWNLOAD_ConfigureLog(2, -4);
    return 1;
}

// 0x00520D70
int __fastcall BNDOWNLOAD_HandleLogonChallengeEx(const int* pData, unsigned int nSize)
{
    sub_0051A540_SetValue(pData[1]);
    BNDOWNLOAD_ConfigureLog(2, 4);
    BNDOWNLOAD_LogPrintf("logon acknowledged");
    BNDOWNLOAD_ConfigureLog(2, -4);
    return 1;
}

// 0x00520F60
int __fastcall BNDOWNLOAD_HandleStartVersioning(const D2BnStartVersioningStrc* pData, unsigned int nSize)
{
    const char* szFileName = pData->szFileName;
    if (sizeof(D2FileTimeStrc) + strlen(szFileName) + 1 < nSize)
        BNDOWNLOAD_SetCheckRevisionValue(szFileName + strlen(szFileName) + 1);
    BNDOWNLOAD_RequestDownload(0x80000001, 3, 0, 0, &pData->tFileTime, szFileName, 0);
    return 1;
}

static int BNAUTH_IsValidAuthInfo(const unsigned char* pData, unsigned int nSize)
{
    if (nSize < 0x16)
        return 0;
    if (pData[nSize - 1])
        return 0;
    unsigned int nCount = 0;
    for (unsigned int i = 0x14; i < nSize - 1; ++i)
    {
        if (!pData[i])
            ++nCount;
    }
    if (nCount != 1)
        return 0;
    return 1;
}

// 0x00521220
int __fastcall BNDOWNLOAD_HandleAuthInfo(const unsigned char* pData, unsigned int nSize)
{
    if (!BNAUTH_IsValidAuthInfo(pData, nSize))
        return 0;

    const D2BnAuthInfoStrc* pInfo = (const D2BnAuthInfoStrc*)pData;
    D2FileTimeStrc tFileTime = pInfo->tFileTime;
    unsigned int nLogonType = pInfo->dwLogonType;
    unsigned int nServerToken = pInfo->dwServerToken;
    const char* szFileName = pInfo->szFileName;
    const char* szValue = szFileName + SStrLen(szFileName) + 1;
    sub_0051A540_SetValue(nServerToken);
    sub_0051A560_SetValue(nLogonType);
    BNDOWNLOAD_SetCheckRevisionValue(szValue);
    BNDOWNLOAD_SetArchiveName(&gszEmptyAssertText);
    BNDOWNLOAD_RequestDownload(0x80000001, 3, 0, 0, &tFileTime, szFileName, 0);
    return 1;
}

static unsigned int __fastcall BNDOWNLOAD_PermuteKeyBits(int nUnused, unsigned int* pKey)
{
    const unsigned int nResult = pKey[0] >> (pKey[1] & 0x1F);
    pKey[2] ^= nResult;
    return nResult;
}

// 0x00522AE0
void __fastcall BNDOWNLOAD_DecodeCDKey(const char* szKey, unsigned int* pProduct, unsigned int* pPublic, unsigned char* pPrivate)
{
    if (!szKey || !pPrivate)
    {
        return;
    }

    unsigned char aDigits[52];
    BNDOWNLOAD_DecodeKeyDigits(szKey, aDigits);

    unsigned int aKey[4] = { 0 };
    for (int i = 52; i > 0; --i)
    {
        BNDOWNLOAD_MulAddWords(4, 5, aKey, aKey, aDigits[i - 1]);
    }

    BNDOWNLOAD_SubstituteKeyNibbles(aKey);
    BNDOWNLOAD_PermuteKeyBits(0, aKey);

    *pProduct = aKey[0] >> 10;
    *pPublic = ((aKey[0] & 0x3FF) << 16) | (aKey[1] >> 16);
    *(unsigned short*)pPrivate = (unsigned short)aKey[1];
    *(unsigned int*)(pPrivate + 2) = aKey[2];
    *(unsigned int*)(pPrivate + 6) = aKey[3];
}
