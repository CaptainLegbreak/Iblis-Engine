#include "D2Hell.h"

// 0x006C9A38
int __fastcall sub_006C9A38_StringLength(char* pString)
{
    int nLength = 0;
    while (*pString)
    {
        ++pString;
        ++nLength;
    }
    return nLength;
}

const char* __fastcall sub_006C9AFF_FindLastCharacter(const char* text, char character); // 0x006C9AFF

// 0x006C9A46
int __fastcall sub_006C9A46_StringEquals(const char* szA, const char* szB)
{
    while (*szA)
    {
        if (!*szB || *szA != *szB)
        {
            break;
        }
        ++szA;
        ++szB;
    }
    return *szA == *szB;
}

// 0x006C9A68
int __fastcall sub_006C9A68_GetDigitClass(signed char character)
{
    return gCharacterClass[character] & 2;
}

// 0x006C9A76
int __fastcall sub_006C9A76_ParseNumber(const char* szText, const char** pszEnd, int* pnValue)
{
    if (!(gCharacterClass[*szText] & 2))
    {
        *pszEnd = szText;
        return 0;
    }
    int nValue = 0;
    while (*szText && (gCharacterClass[*szText] & 2))
    {
        nValue = nValue * 10 + *szText - '0';
        ++szText;
    }
    *pnValue = nValue;
    *pszEnd = szText;
    return 1;
}

// 0x006C9AB9
int __fastcall sub_006C9AB9_GetSpaceClass(signed char character)
{
    return gCharacterClass[character] & 1;
}

// 0x006C9AC7
const char* __fastcall sub_006C9AC7_SkipSpaces(const char* szText)
{
    while (*szText && (gCharacterClass[*szText] & 1))
    {
        ++szText;
    }
    return szText;
}

// 0x006C9ADF
const char* __fastcall sub_006C9ADF_CopyWord(char* szDest, const char* szSource)
{
    while (*szSource && !(gCharacterClass[*szSource] & 1))
    {
        *szDest = *szSource;
        ++szDest;
        ++szSource;
    }
    *szDest = 0;
    return szSource;
}

// 0x006C9AFF
const char* __fastcall sub_006C9AFF_FindLastCharacter(const char* text, char character)
{
    const char* result = 0;
    for (const char* p = text; *p; ++p)
    {
        if (*p == character)
            result = p;
    }
    return result;
}

// 0x006C9B17
char* __fastcall sub_006C9B17_StripFileName(char* szPath)
{
    char* pSlash = (char*)sub_006C9AFF_FindLastCharacter(szPath, '\\');
    if (!pSlash)
    {
        *szPath = 0;
    }
    else
    {
        *pSlash = 0;
    }
    return szPath;
}

// 0x006C9B30
const char* __fastcall sub_006C9B30_GetFileName(const char* szPath)
{
    const char* pSlash = sub_006C9AFF_FindLastCharacter(szPath, '\\');
    if (!pSlash)
    {
        return szPath;
    }
    return pSlash + 1;
}

extern "C" __declspec(dllimport) char* __stdcall CharNextA(const char*); // 0x006CC450

// 0x006C9B45
char* __fastcall sub_006C9B45_TrimTrailingBackslash(char* s)
{
    char* r = (char*)sub_006C9AFF_FindLastCharacter(s, 0x5C);
    if (!r)
        return s;
    if (*CharNextA(r) != 0)
        return s;
    *r = 0;
    return s;
}

extern "C" const unsigned char gData_0074C5C8[256] = { // 0x0074C5C8
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2
};
#pragma comment(linker, "/alternatename:?gCharacterClass_0074C5C8@@3QBEB=_gData_0074C5C8")
