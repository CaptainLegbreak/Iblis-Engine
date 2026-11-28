#include "D2BNClient.h"
#include "D2BnCryptTypes.h"
#include "FogApi.h"
#include "StormApi.h"
#include "StormApi.h"
#include "StormApi2.h"

struct D2BnHashCtxStrc;

typedef unsigned char Byte;

typedef unsigned int UInt;

void* __stdcall sub_00413020_Allocate(UInt size, const char* file, int line, UInt flags); // 0x00413020

void* __cdecl sub_006829C0_CopyBuffer(void* dest, const void* source, UInt size); // 0x006829C0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0






extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0

extern const char gszGrid[]; // 0x006E0200

extern int gdwGlobal_00730190; // 0x00730190

void __fastcall BNDOWNLOAD_FillRandomBytes(char* szBuffer, int nSize); // 0x00522BC0

unsigned int __fastcall BNDOWNLOAD_DecryptData(unsigned char* pBuffer, unsigned int nSize, const char* pKey); // 0x00522E10

static int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize);

static void __cdecl GRID_CopyDecodedKeys(Byte** first, Byte** second); // 0x00523350

static void* GRID_LoadKeyFile(const char* szFileName, unsigned int* pSize); // 0x00523480

// build: base-profile

extern "C" void __fastcall __security_check_cookie(unsigned int cookie); // 0x00681A48

unsigned int gnGidFileSize; // 0x00882740

static void* gpGidFileData; // 0x00882744

unsigned int gnClhFileSize; // 0x00882748

void* gpKeyFile3Data; // 0x0088274C

static void* gpClhFileData; // 0x00882750

unsigned int gnKeyFile3Size; // 0x00882754

static inline unsigned int sub_GetTerminatedLength(const unsigned char* pString, unsigned int nSize)
{
    unsigned int nMax = 0x80;
    unsigned int nLength = 0;
    if (nSize <= nMax)
    {
        nMax = nSize;
    }

    if (!nMax)
    {
        return 0;
    }

    do
    {
        --nMax;
        ++nLength;
        if (!*pString++)
        {
            return nLength;
        }
    }
    while (nMax);

    return 0;
}

// 0x005232B0
static int __cdecl sub_005232B0_DecodeAndValidate(unsigned char* pBuffer, unsigned int nSize)
{
    char aKey[20];
    BNDOWNLOAD_FillRandomBytes(aKey, sizeof(aKey));
    unsigned int nLength = BNDOWNLOAD_DecryptData(pBuffer, nSize, aKey);
    if (!nLength)
    {
        return 0;
    }

    if (nLength >= nSize)
    {
        return 0;
    }

    pBuffer[nLength] = 0;
    ++nLength;
    if (!sub_GetTerminatedLength(pBuffer, nLength))
    {
        return 0;
    }

    return 1;
}

// 0x00523350
static void __cdecl GRID_CopyDecodedKeys(Byte** first, Byte** second)
{
    if (first)
    {
        Byte* allocated = (Byte*)sub_00413020_Allocate(gnGidFileSize, gszGrid, 0x199, 0);
        *first = allocated;
        sub_006829C0_CopyBuffer(allocated, gpGidFileData, gnGidFileSize);
    }
    if (second)
    {
        Byte* allocated = (Byte*)sub_00413020_Allocate(gnClhFileSize, gszGrid, 0x19e, 0);
        *second = allocated;
        sub_006829C0_CopyBuffer(allocated, gpClhFileData, gnClhFileSize);
    }
    if (first && !sub_005232B0_DecodeAndValidate(*first, gnGidFileSize))
    {
        SMemFree(*first, gszGrid, 0x1a6, 0);
        *first = 0;
    }
    if (second && !sub_005232B0_DecodeAndValidate(*second, gnClhFileSize))
    {
        SMemFree(*second, gszGrid, 0x1aa, 0);
        *second = 0;
    }
}

// calling-convention shim (not game code)
void __cdecl sub_00523350_Shim(Byte** first, Byte** second)
{
    GRID_CopyDecodedKeys(first, second);
}

// 0x00523420
static inline void GRID_FreeKeyStrings(char* szFirst, char* szSecond)
{
    if (szFirst)
    {
        memset(szFirst, 0, SStrLen(szFirst));
        SMemFree(szFirst, ".\\grid.cpp", 0x1B8, 0);
    }
    if (szSecond)
    {
        memset(szSecond, 0, SStrLen(szSecond));
        SMemFree(szSecond, ".\\grid.cpp", 0x1BE, 0);
    }
}

// 0x00523480
static void* GRID_LoadKeyFile(const char* szFileName, unsigned int* pSize)
{
    void* pBuffer;
    *pSize = 0x400;
    SFileLoadFile(szFileName, &pBuffer, pSize, 1, 0);
    if (pBuffer && *pSize)
    {
        if (sub_005232B0_DecodeAndValidate((unsigned char*)pBuffer, *pSize))
            return pBuffer;
        if (pBuffer)
            SFileUnloadFile(pBuffer);
    }
    return 0;
}


// 0x005234D0
void __cdecl GRID_LockCDKeys()
{
    char szPath[260];
    int i;

    if (gpGidFileData || gpClhFileData)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x213);
        exit(-1);
    }

    sprintf(szPath, "%s\\%s.gid", "font", "font");
    gpGidFileData = GRID_LoadKeyFile(szPath, &gnGidFileSize);
    if (!gpGidFileData)
    {
        char szKey[] = "vwaxdnirosucflbgt\\.";
        char aIndex[] = { 4, 2, 16, 2, 17, 15, 13, 8, 14, 2, 13, 17, 9, 12, 3, 17, 11, 10, 7, 9, 8, 7, 17, 1, 2, 0, 6, 5, 4, 3, 18, 1, 2, 0, 19 };

        for (i = 0; aIndex[i] < 19; i++)
        {
            szPath[i] = szKey[aIndex[i]];
        }
        szPath[i] = 0;

        gpGidFileData = GRID_LoadKeyFile(szPath, &gnGidFileSize);
    }

    sprintf(szPath, "%s\\%s.clh", "font", "font");
    gpClhFileData = GRID_LoadKeyFile(szPath, &gnClhFileSize);
    if (!gpClhFileData)
    {
        char szKey[] = "vwaxdnirosucflbgt\\.";
        char aIndex[] = { 4, 2, 16, 2, 17, 15, 13, 8, 14, 2, 13, 17, 9, 12, 3, 17, 11, 10, 7, 9, 8, 7, 17, 11, 10, 7, 6, 5, 4, 3, 18, 1, 2, 0, 19 };

        for (i = 0; aIndex[i] < 19; i++)
        {
            szPath[i] = szKey[aIndex[i]];
        }
        szPath[i] = 0;

        gpClhFileData = GRID_LoadKeyFile(szPath, &gnClhFileSize);
    }

    if (sub_0051BEC0_IsExpansion())
    {
        char szKey[] = "vwaxdnirosucflbgt\\.mpyeh8";
        char aIndex[] = { 4, 2, 16, 2, 17, 15, 13, 8, 14, 2, 13, 17, 11, 23, 2, 7, 9, 17, 2, 19, 17, 11, 8, 12, 17, 2, 19, 14, 13, 3, 14, 8, 1, 18, 11, 8, 12, 39 };

        for (i = 0; aIndex[i] < sizeof(szKey); i++)
        {
            szPath[i] = szKey[aIndex[i]];
        }
        szPath[i] = 0;

        gpKeyFile3Data = GRID_LoadKeyFile(szPath, &gnKeyFile3Size);
    }

    gdwGlobal_00730190 = 0;

    if (szPath[0])
    {
        char* p = szPath;
        do
        {
            *p++ = 0;
        }
        while (*p);
    }
}

// 0x005239C0
void __cdecl GRID_UnlockCDKeys()
{
    if (gpGidFileData)
    {
        SFileUnloadFile(gpGidFileData);
        gpGidFileData = 0;
    }

    if (gpClhFileData)
    {
        SFileUnloadFile(gpClhFileData);
        gpClhFileData = 0;
    }
}

// 0x00523A00
int __cdecl GAME_GetExeHash()
{
    return gdwGlobal_00730190;
}

// 0x00523A10
unsigned int __cdecl GRID_HashCDKey()
{
    char* szKey = (char*)SMemAlloc(gnGidFileSize, ".\\grid.cpp", 0x199, 0);
    memcpy(szKey, gpGidFileData, gnGidFileSize);
    if (!sub_005232B0_DecodeAndValidate((unsigned char*)szKey, gnGidFileSize))
    {
        SMemFree(szKey, ".\\grid.cpp", 0x1A6, 0);
        szKey = 0;
    }
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    if (szKey)
    {
        memset(szKey, 0, SStrLen(szKey));
        SMemFree(szKey, ".\\grid.cpp", 0x1B8, 0);
    }
    return dwHash;
}

extern int gdwGlobal_00882750; // 0x00882750
// 0x00523AA0
int __cdecl GAME_GetExeInfo()
{
    return gdwGlobal_00882750;
}

// 0x00523AB0
const char* __fastcall GRID_GetCDKey(int nSlot)
{
    return nSlot ? (const char*)gpKeyFile3Data : (const char*)gpGidFileData;
}

// 0x00523AC0
static inline void GRID_InitShaContext(D2BnHashCtxStrc* pCtx)
{
    pCtx->aState[0] = 0x67452301;
    pCtx->aState[1] = 0xEFCDAB89;
    pCtx->aState[2] = 0x98BADCFE;
    pCtx->aState[3] = 0x10325476;
    pCtx->aState[4] = 0xC3D2E1F0;
    pCtx->nBitCountLo = 0;
    pCtx->nBitCountHi = 0;
}

void __fastcall sub_M103_Emit_00523420(char* szFirst, char* szSecond, D2BnHashCtxStrc* pCtx)
{
    GRID_InitShaContext(pCtx);
    GRID_FreeKeyStrings(szFirst, szSecond);
}

int gdwGlobal_00730190 = 1; // 0x00730190

extern "C" unsigned char gData_00730194[4] = { 0 }; // 0x00730194
