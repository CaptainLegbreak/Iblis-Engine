#include "D2Lang.h"
#include "D2LangTypes.h"
#include "D2Unicode.h"

#include "gen/data/Source/D2Lang/Unknown_00527090.inc"

struct UnicodeZ;
struct UnicodeChar;
struct D2LangCharSetStrc;

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0

struct UnicodeZ
{
    unsigned short wChar;

    UnicodeZ() : wChar(0) {}
};

struct UnicodeChar
{
    unsigned short wChar;

    UnicodeChar();                                                                                          // 0x0042F530
};

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" unsigned int __cdecl strlen(const char* szString);
static bool sub_005271A0_EndsWithCharOf(const char* szChars, const Unicode* pText); // 0x005271A0

// 0x00527090
bool D2LangCharSetStrc::ContainsChar(const Unicode* pChar) const
{
    Unicode wszChars[20] = {};
    int i;
    for (i = 0; i < 20 && szChars[i] != '\0'; ++i)
    {
        wszChars[i].wChar = (unsigned char)szChars[i];
    }
    if (szChars[i] != '\0')
    {
        wszChars[i - 1].wChar = 0;
    }
    else
    {
        wszChars[i].wChar = 0;
    }
    const int nLength = sub_00526800(wszChars);
    for (int j = 0; j < nLength; ++j)
    {
        if (pChar->wChar == wszChars[j].wChar)
        {
            return true;
        }
    }
    return false;
}

// 0x005271A0
static bool sub_005271A0_EndsWithCharOf(const char* szChars, const Unicode* pText)
{
    Unicode wszChars[20] = {};
    int i;
    for (i = 0; i < 20 && szChars[i] != '\0'; ++i)
    {
        wszChars[i].wChar = (unsigned char)szChars[i];
    }
    if (szChars[i] != '\0')
    {
        wszChars[i - 1].wChar = 0;
    }
    else
    {
        wszChars[i].wChar = 0;
    }
    const int nLength = sub_00526800(wszChars);
    const int nTextLength = sub_00526800(pText);
    for (int j = 0; j < nLength; ++j)
    {
        if (pText[nTextLength - 1].wChar == wszChars[j].wChar)
        {
            return true;
        }
    }
    return false;
}

static inline void win2UnicodeInline(Unicode* pDst, const char* szSrc, int nMaxLength)
{
    int i;
    for (i = 0; i < nMaxLength && szSrc[i] != '\0'; ++i)
    {
        pDst[i].wChar = (unsigned char)szSrc[i];
    }
    if (szSrc[i] != '\0')
    {
        pDst[i - 1].wChar = 0;
    }
    else
    {
        pDst[i].wChar = 0;
    }
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x005272B0
void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pOwner, const Unicode* pItem, int nMaxLength, int nLanguage)
{
    const int nOwnerLength = sub_00526800(pOwner);
    const int nItemLength = sub_00526800(pItem);
    if (nItemLength + nOwnerLength + 5 > nMaxLength)
    {
        if (nItemLength < nMaxLength)
            sub_005267E0(pDst, pItem);
        return;
    }

    UnicodeZ wszSuffix[10];
    char szSuffix[10];
    switch (nLanguage)
    {
    case 0:
    case 12:
        sub_005267E0(pDst, pOwner);
        if (sub_005271A0_EndsWithCharOf("s", pOwner))
            strcpy(szSuffix, "' ");
        else
            strcpy(szSuffix, "'s ");
        sub_00526F20((Unicode*)wszSuffix, szSuffix, strlen(szSuffix));
        sub_00526700(pDst, (Unicode*)wszSuffix);
        sub_00526700(pDst, pItem);
        break;

    case 1:
        sub_005267E0(pDst, pItem);
        strcpy(szSuffix, " de ");
        sub_00526F20((Unicode*)wszSuffix, szSuffix, strlen(szSuffix));
        sub_00526700(pDst, (Unicode*)wszSuffix);
        sub_00526700(pDst, pOwner);
        break;

    case 2:
        sub_005267E0(pDst, pOwner);
        if (sub_005271A0_EndsWithCharOf("sz", pOwner))
            strcpy(szSuffix, "' ");
        else
            strcpy(szSuffix, "s ");
        sub_00526F20((Unicode*)wszSuffix, szSuffix, strlen(szSuffix));
        sub_00526700(pDst, (Unicode*)wszSuffix);
        sub_00526700(pDst, pItem);
        break;

    case 3:
        sub_005267E0(pDst, pItem);
        if (((const D2LangCharSetStrc*)"aeiou")->ContainsChar(pOwner))
            strcpy(szSuffix, " d'");
        else
            strcpy(szSuffix, " de ");
        sub_00526F20((Unicode*)wszSuffix, szSuffix, strlen(szSuffix));
        sub_00526700(pDst, (Unicode*)wszSuffix);
        sub_00526700(pDst, pOwner);
        break;

    case 5:
        sub_005267E0(pDst, pItem);
        strcpy(szSuffix, " di ");
        sub_00526F20((Unicode*)wszSuffix, szSuffix, strlen(szSuffix));
        sub_00526700(pDst, (Unicode*)wszSuffix);
        sub_00526700(pDst, pOwner);
        break;

    case 10:
    {
        UnicodeChar wszChar[2];
        char szChar[2];
        sub_005267E0(pDst, pItem);
        strcpy(szChar, "(");
        sub_00526F20((Unicode*)wszChar, szChar, 2);
        sub_00526700(pDst, (Unicode*)wszChar);
        sub_00526700(pDst, pOwner);
        strcpy(szChar, ")");
        sub_00526F20((Unicode*)wszChar, szChar, 2);
        sub_00526700(pDst, (Unicode*)wszChar);
        strcpy(szChar, " ");
        sub_00526F20((Unicode*)wszChar, szChar, 2);
        sub_00526700(pDst, (Unicode*)wszChar);
        break;
    }

    default:
    {
        UnicodeZ wszChar[2];
        char szChar[2];
        strcpy(szChar, "(");
        win2UnicodeInline((Unicode*)wszChar, szChar, 2);
        sub_005267E0(pDst, (Unicode*)wszChar);
        sub_00526700(pDst, pOwner);
        strcpy(szChar, ")");
        win2UnicodeInline((Unicode*)wszChar, szChar, 2);
        sub_00526700(pDst, (Unicode*)wszChar);
        strcpy(szChar, " ");
        win2UnicodeInline((Unicode*)wszChar, szChar, 2);
        sub_00526700(pDst, (Unicode*)wszChar);
        sub_00526700(pDst, pItem);
        break;
    }
    }
}
