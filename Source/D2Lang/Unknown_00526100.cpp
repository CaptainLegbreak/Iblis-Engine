#include "D2Lang.h"
#include "D2LangTypes.h"
#include "D2Unicode.h"

struct D2UtfConvertSpecStrc;

extern "C" unsigned int __cdecl strlen(const char* sz);


extern D2UtfConvertSpecStrc gaUtf8ConvertTable[7]; // 0x007309B8


// 0x00526100
static int __stdcall sub_00526100_Utf8ToUnicodeChar(Unicode* pDest, int nCount, const char* pSrc)
{
    int n = 0;
    if (nCount <= 0)
        return -1;

    const unsigned short c = (unsigned char)*pSrc;
    int nCode = (short)c;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable; pSpec->nMask; ++pSpec)
    {
        const short nLead = pSpec->nMask & c;
        ++n;
        if (nLead == pSpec->nLeading)
        {
            nCode &= pSpec->nLast;
            if (nCode < pSpec->nFirst)
                return -1;
            pDest->wChar = nCode;
            return n;
        }

        if (nCount <= n)
            return -1;

        const unsigned short t = (unsigned char)(*++pSrc ^ 0x80);
        if (t & 0xC0)
            return -1;
        nCode = (nCode << 6) | (short)t;
    }
    return -1;
}

// 0x00526190
static int __stdcall sub_00526190_UnicodeCharToUtf8(char* pDest, Unicode ch)
{
    const int nCode = ch.wChar;
    int n = 0;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable; pSpec->nMask; ++pSpec)
    {
        ++n;
        if (nCode <= pSpec->nLast)
        {
            int nBits = pSpec->nTrailingBits;
            *pDest = (nCode >> nBits) | (unsigned char)pSpec->nLeading;
            while (nBits > 0)
            {
                nBits -= 6;
                *++pDest = ((nCode >> nBits) & 0x3F) | 0x80;
            }
            return n;
        }
    }
    return -1;
}

// 0x00526200
static int __stdcall sub_00526200_Utf8CharLength(int nCount, const char* pSrc)
{
    int n = 0;
    if (nCount <= 0)
        return -1;

    const int c = (unsigned char)*pSrc;
    int nCode = c;
    for (const D2UtfConvertSpecStrc* pSpec = gaUtf8ConvertTable; pSpec->nMask; ++pSpec)
    {
        ++n;
        if (((short)pSpec->nMask & c) == pSpec->nLeading)
        {
            if ((pSpec->nLast & nCode) < pSpec->nFirst)
                return -1;
            return n;
        }

        if (nCount <= n)
            return -1;

        const int t = (unsigned char)*++pSrc ^ 0x80;
        if (t & 0xC0)
            return -1;
        nCode = (nCode << 6) | t;
    }
    return -1;
}

// 0x005262A0
int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount)
{
    int n = 0;
    while (nCount > 0)
    {
        if (!*pSrc)
            break;
        const int nUnits = sub_00526200_Utf8CharLength(nCount, pSrc);
        if (nUnits != -1)
        {
            for (int j = 0; j < nUnits; ++j)
            {
                if (!*pSrc++)
                    return n;
            }
            ++n;
            nCount -= nUnits;
        }
        else
        {
            ++pSrc;
            --nCount;
        }
    }
    return n;
}

int __fastcall sub_005262F0_UnicodeCharUtf8Length(const Unicode* pChar)
{
    char szBuffer[8];
    return sub_00526190_UnicodeCharToUtf8(szBuffer, *pChar);
}


// 0x00526320
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength)
{
    int nDest = 0;
    const int nSourceLength = strlen(szSource);
    int nSrc = 0;
    for (;;)
    {
        if (!(szSource[nSrc] && nDest < nLength - 1))
            break;
        const int nUnits = sub_00526100_Utf8ToUnicodeChar(&pDest[nDest], nSourceLength - nSrc, &szSource[nSrc]);
        ++nDest;
        if (nUnits == -1)
            break;
        nSrc += nUnits;
    }
    pDest[nDest].wChar = 0;
    return pDest;
}

// 0x005263E0
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength)
{
    int nLength = 0;
    for (int i = 0; pSource[i].wChar; ++i)
    {
        if (nLength >= nMaxLength - 1)
            break;
        const int nUnits = sub_00526190_UnicodeCharToUtf8(&szDest[nLength], pSource[i]);
        if (nUnits == -1)
            break;
        nLength += nUnits;
    }
    szDest[nLength] = 0;
    return szDest;
}

// 0x00526430
int __fastcall sub_00526430_UnicodeUtf8Length(const Unicode* pSource, int nCount)
{
    char szBuffer[12];
    int nLength = 0;
    for (int i = 0; pSource[i].wChar; ++i)
    {
        if (i >= nCount)
            break;
        const int nUnits = sub_00526190_UnicodeCharToUtf8(szBuffer, pSource[i]);
        if (nUnits == -1)
            break;
        nLength += nUnits;
    }
    return nLength;
}

#pragma pack(push, 1)
struct d2data_00730978_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007309B4_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00730AA0_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00730978_t gData_00730978; // 0x00730978
extern "C" struct d2data_007309B4_t gData_007309B4; // 0x007309B4
extern "C" struct d2data_00730AA0_t gData_00730AA0; // 0x00730AA0

extern "C" struct d2data_00730978_t gData_00730978 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00730978

extern "C" struct d2data_007309B4_t gData_007309B4 = {
    { 0x00 }
}; // 0x007309B4

extern D2UtfConvertSpecStrc gaUtf8ConvertTable[7] = {
    { 0x80, 0, 0, 0, 127 },
    { 0xE0, 192, 6, 0, 2047, 128 },
    { 0xF0, 224, 12, 0, 65535, 2048 },
    { 0xF8, 240, 18, 0, 2097151, 65536 },
    { 0xFC, 248, 24, 0, 67108863, 2097152 },
    { 0xFE, 252, 30, 0, 2147483647, 67108864 }
}; // 0x007309B8

extern "C" struct d2data_00730AA0_t gData_00730AA0 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00730AA0
