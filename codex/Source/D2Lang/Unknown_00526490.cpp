#include "D2Lang.h"
#include "D2LangTypes.h"
#include "D2Unicode.h"

#include "gen/data/Source/D2Lang/Unknown_00526490.inc"

struct D2LangByteRangeStrc;
struct D2UtfConvertSpecStrc;
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605
extern "C" int __cdecl isspace(int c); // 0x00687006

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
Unicode* __fastcall sub_00526740(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526740
Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pSubstring); // 0x00526940
int __stdcall SUniConvertUTF8to16(unsigned short* pDst, unsigned int nDstMax, const unsigned char* pSrc, unsigned int nSrcMax, unsigned int* pnDstWritten, unsigned int* pnSrcRead); // 0x006C7410


// 0x00526740
Unicode* __fastcall Unicode::strncat(Unicode* dest, const Unicode* src, int count)
{
    Unicode* pEnd = dest;
    while (pEnd->wChar)
    {
        ++pEnd;
    }

    unsigned short wChar;
    while (count-- && (wChar = src->wChar) != 0)
    {
        pEnd->wChar = wChar;
        ++pEnd;
        ++src;
    }

    pEnd->wChar = 0;
    return dest;
}

// 0x00526490
int __fastcall Unicode::compare(Unicode lhs, Unicode rhs)
{
    return lhs.toUpper().wChar == rhs.toUpper().wChar;
}

// 0x005264F0
int __fastcall Unicode::strcmp(const Unicode* str1, const Unicode* str2)
{
    while (str1->wChar && str2->wChar && str1->wChar == str2->wChar)
    {
        ++str1;
        ++str2;
    }
    if (str1->wChar < str2->wChar)
        return -1;
    return str1->wChar > str2->wChar;
}

// 0x00526700
Unicode* __fastcall Unicode::strcat(Unicode* dest, const Unicode* src)
{
    Unicode* pEnd = dest;
    while (pEnd->wChar)
        ++pEnd;
    do
    {
        pEnd->wChar = src->wChar;
        ++pEnd;
    }
    while ((src++)->wChar);
    return dest;
}

// 0x00526540
int __fastcall Unicode::strncmp(const Unicode* str1, const Unicode* str2, unsigned int count)
{
    while (str1->wChar && str2->wChar && count--)
    {
        const Unicode tChar1 = *str1++;
        const Unicode tChar2 = *str2++;
        if (tChar1.wChar != tChar2.wChar)
            return tChar1.wChar < tChar2.wChar ? -1 : 1;
    }
    return 0;
}

// 0x00526590
int __fastcall Unicode::stricmp(const Unicode* str1, const Unicode* str2)
{
    while (str1->wChar && str2->wChar)
    {
// build: symbol ?gawToUpperTable@* 0x00730578
        const unsigned short ch1 = str1->wChar < 0x100 ? gawToUpperTable[str1->wChar] : str1->wChar;
        const unsigned short ch2 = str2->wChar < 0x100 ? gawToUpperTable[str2->wChar] : str2->wChar;
        if (ch1 != ch2)
            return ch1 < ch2 ? -1 : 1;
        ++str1;
        ++str2;
    }
    if (str1->wChar)
        return 1;
    return str2->wChar ? -1 : 0;
}

// 0x00526610
int __fastcall Unicode::strnicmp(const Unicode* str1, const Unicode* str2, size_t count)
{
    Unicode ch1 = str1->toUpper();
    Unicode ch2 = str2->toUpper();
    while (str1->wChar && str2->wChar && count-- && ch1.wChar == ch2.wChar)
    {
        ch1 = (str1++)->toUpper();
        ch2 = (str2++)->toUpper();
    }
    if (ch1.wChar < ch2.wChar)
    {
        return -1;
    }
    return ch1.wChar > ch2.wChar;
}

// 0x005266C0
Unicode* __fastcall Unicode::strchr(const Unicode* str, Unicode ch)
{
    while (str->wChar && str->wChar != ch.wChar)
        ++str;
    if (str->wChar)
        return (Unicode*)str;
    return 0;
}

// 0x00526790
Unicode* __fastcall Unicode::strncpy(Unicode* dest, const Unicode* src, int count)
{
    Unicode* current_dest = dest;
    for (; (count--) != 0 && src->wChar != 0; ++current_dest, ++src)
    {
        current_dest->wChar = src->wChar;
    }

    for (; count != -1; ++current_dest, --count)
    {
        current_dest->wChar = 0;
    }

    return dest;
}

// 0x005267E0
Unicode* __fastcall Unicode::strcpy(Unicode* dest, const Unicode* src)
{
    Unicode* p = dest;
    do
    {
        *p++ = *src;
    } while ((src++)->wChar);
    return dest;
}

// 0x00526800
extern "C" __declspec(dllexport) int __fastcall sub_00526800(const unsigned short* pText) {
    int nLength = 0;
    if (!pText) {
        return 0;
    }
    while (*pText) {
        pText++;
        nLength++;
    }
    return nLength;
}

// 0x00526820
Unicode* __fastcall sub_00526820_StrStrI(const Unicode* str, const Unicode* substr)
{
    if (!str || !substr)
    {
        return 0;
    }

    Unicode c = *str;
    for (;;)
    {
        const Unicode first = *substr;
        for (;;)
        {
            const unsigned short ch1 = c.wChar < 0x100 ? gawToUpperTable[c.wChar] : c.wChar;
            const unsigned short ch2 = first.wChar < 0x100 ? gawToUpperTable[first.wChar] : first.wChar;
            if (ch1 == ch2)
            {
                break;
            }

            c = *++str;
            if (!c.wChar)
            {
                return 0;
            }
        }

        int n = 0;
        for (;;)
        {
            const unsigned short s1 = str->wChar;
            const unsigned short s2 = substr->wChar;
            const unsigned short ch1 = s1 < 0x100 ? gawToUpperTable[s1] : s1;
            const unsigned short ch2 = s2 < 0x100 ? gawToUpperTable[s2] : s2;
            if (ch1 != ch2 || !s1)
            {
                break;
            }

            if (!s2)
            {
                goto found;
            }

            ++str;
            ++substr;
            ++n;
        }

        if (!substr->wChar)
        {
found:
            return (Unicode*)(str - n);
        }

        if (!str->wChar)
        {
            return 0;
        }

        str = str - n + 1;
        substr -= n;
    }
}

// 0x00526940
Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* str, const Unicode* substr)
{
    if (!str || !substr) return 0;
    for (;;) {
        const Unicode first = *substr;
        const unsigned short wFirst = first.wChar;
        while (str->wChar != wFirst) {
            if (!str->wChar) return 0;
            ++str;
        }
        if (!str->wChar) return 0;
        int n = 0;
        for (;;) {
            if (str->wChar != substr->wChar || !str->wChar) break;
            if (!substr->wChar) goto found;
            ++str; ++substr; ++n;
        }
        if (!substr->wChar) {
found:
            return (Unicode*)(str - n);
        }
        if (!str->wChar) return 0;
        str = str - n + 1;
        substr -= n;
    }
}

static inline int Unicode_strlen_Inline(const Unicode* pString)
{
    int nLength = 0;
    if (pString)
    {
        while (pString->wChar)
        {
            ++pString;
            ++nLength;
        }
    }
    return nLength;
}

static __forceinline void Unicode_strcpy_Inline(Unicode* pDest, const Unicode* pSource)
{
    do
    {
        *pDest++ = *pSource;
    }
    while (pSource++->wChar);
}

// 0x005269D0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...)
{
    if (!pFormat)
    {
        return;
    }

    int nArg = *(const int*)(&pFormat + 1);
    pBuffer->wChar = 0;
    int nPos = 0;
    const Unicode* pFound = 0;
    if (!pFormat->wChar)
    {
        return;
    }

    Unicode szPercent[2];
    szPercent[0].wChar = '%';
    szPercent[1].wChar = 0;
    Unicode wSpec;
    const int* pArgs = (const int*)(&pFormat + 1);

    do
    {
        wSpec.wChar = 0;
        const Unicode* pNext = sub_00526940_FindSubstring(pFormat, szPercent);
        if (pNext)
        {
            pFound = pNext;
            wSpec = pNext[1];
        }

        while (pFormat != pFound && pFormat->wChar)
        {
            if (nPos >= nBufferSize)
            {
                pBuffer[-1].wChar = 0;
                return;
            }
            *pBuffer++ = *pFormat++;
            ++nPos;
        }

        if (nPos >= nBufferSize)
        {
            pBuffer[-1].wChar = 0;
            return;
        }

        if (!pFormat->wChar)
        {
            pBuffer->wChar = 0;
            return;
        }

        D2_ASSERT(pFound, 0x10D);

        switch (wSpec.wChar)
        {
        case 'd':
        case 'u':
        {
            Unicode wszNumber[15];
            char szNumber[16];
            memset(wszNumber, 0, sizeof(wszNumber));
            if (wSpec.wChar == 'd')
            {
                _itoa(nArg, szNumber, 10);
            }
            else
            {
                _ultoa(nArg, szNumber, 10);
            }
            sub_00526320_ToUnicode(wszNumber, szNumber, 15);
            const int nLength = Unicode_strlen_Inline(wszNumber);
            if (nLength + nPos + 1 >= nBufferSize)
            {
                return;
            }
            Unicode_strcpy_Inline(pBuffer, wszNumber);
            nPos += nLength;
            pBuffer += nLength;
            break;
        }

        case 's':
        {
            const Unicode* pString = (const Unicode*)nArg;
            const int nLength = Unicode_strlen_Inline(pString);
            if (!nLength || nLength + nPos + 1 >= nBufferSize)
            {
                sub_00526740(pBuffer, pString, nBufferSize - nPos - 1);
                return;
            }
            Unicode_strcpy_Inline(pBuffer, pString);
            pBuffer += nLength;
            nPos += nLength;
            break;
        }

        case '%':
            if (nPos + 1 >= nBufferSize)
            {
                return;
            }
            Unicode_strcpy_Inline(pBuffer, szPercent);
            ++pBuffer;
            ++nPos;
            break;

        case 0:
            Unicode::strcpy(pBuffer, szPercent);
            return;

        default:
            D2_ASSERT(0, 0x154);
            break;
        }

        pFormat += 2;
        ++pArgs;
        nArg = *pArgs;
    }
    while (pFormat->wChar);
}

// 0x00526D00
int Unicode::isLeftToRight() const
{
    if ((wChar >= 0x590 && wChar <= 0x5FF) || (wChar >= 0x600 && wChar <= 0x6FF))
        return 0;
    return 1;
}

// 0x00526D30
int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex)
{
    if (!nIndex)
    {
        return 1;
    }

    switch (sub_00525150())
    {
    case 6:
    case 8:
    case 9:
    {
#define wChar pText[nIndex].wChar
        if (wChar == 0x2026 || wChar == 0x3001 || wChar == 0x3002 || wChar == 0xFF01 || wChar == 0xFF0C
            || wChar == 0xFF0E || wChar == 0xFF1F || wChar == 0xFF61 || wChar == 0xFF64)
        {
            return 0;
        }
        if (wChar >= 'a' && wChar <= 'z')
        {
            return 0;
        }
        if (wChar >= 0xFF41 && wChar <= 0xFF5A)
        {
            return 0;
        }
        if (wChar >= 'A' && wChar <= 'Z')
        {
            return 0;
        }
        if (wChar >= 0xFF21 && wChar <= 0xFF3A)
        {
            return 0;
        }
        if (wChar >= '0' && wChar <= '9')
        {
            return 0;
        }
        if (wChar >= 0xFF10 && wChar <= 0xFF19)
        {
            return 0;
        }
        return 1;
#undef wChar
    }
    }

    if (pText[nIndex].isWhitespace())
    {
        return 0;
    }
    return pText[nIndex - 1].isWhitespace();
}

// 0x00526E40
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength)
{
    unsigned int nWritten;
    unsigned short wszBuffer[0x400];

    if (SUniConvertUTF8to16(wszBuffer, 0x3FF, (const unsigned char*)szSrc, strlen(szSrc) + 1, &nWritten, 0))
    {
        nWritten = 0;
    }
    wszBuffer[nWritten] = 0;

    int i = 0;
    for (; i < nMaxLength; ++i)
    {
        if (!wszBuffer[i])
        {
            break;
        }
        pDst[i].wChar = wszBuffer[i];
    }

    if (wszBuffer[i])
    {
        pDst[i - 1].wChar = 0;
    }
    else
    {
        pDst[i].wChar = 0;
    }

    return pDst;
}

// 0x00526F20
Unicode* __fastcall Unicode::win2Unicode(Unicode* dest, const char* src, int count)
{
    int i;
    for (i = 0; i < count; ++i)
    {
        unsigned char src_ch = src[i];
        if (src_ch == '\0')
        {
            break;
        }
        dest[i].wChar = src_ch;
    }

    if (src[i] != '\0')
    {
        dest[i - 1].wChar = 0;
        return dest;
    }

    dest[i].wChar = 0;
    return dest;
}

// 0x00526F70
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount)
{
    char* pCurrentDest = szDest;
    while (nCount > 1 && pSource->wChar != 0)
    {
        const Unicode* pCurrentSource = pSource++;
        *pCurrentDest = (char)pCurrentSource->wChar;
        --nCount;
        ++pCurrentDest;
    }
    *pCurrentDest = '\0';
    return szDest;
}

// 0x00526FB0
Unicode::Direction Unicode::directionality()
{
    if (this->wChar >= 0x590 && this->wChar <= 0x8FF)
        return DIR_RIGHT_TO_LEFT;
    if (this->wChar >= L'a' && this->wChar <= L'z')
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= L'@' && this->wChar <= L'Z')
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= L'0' && this->wChar <= L'9')
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar <= L'\?')
        return (this->wChar == L'&') ? DIR_LEFT_TO_RIGHT : DIR_NEUTRAL;
    if (this->wChar >= 0x3040 && this->wChar <= 0x8BFF)
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= 0xC0 && this->wChar <= 0x58F && this->wChar != 0xD7 && this->wChar != 0xF7)
        return DIR_LEFT_TO_RIGHT;
    if (this->wChar >= 0x900 && this->wChar <= 0x10FF)
        return DIR_LEFT_TO_RIGHT;
    if ((this->wChar & 0xFE00) == 0x2000)
    {
        if (this->wChar >= 0x2160 && this->wChar <= 0x2182)
            return DIR_LEFT_TO_RIGHT;
        if (this->wChar >= 0x20D0 && this->wChar <= 0x20FF)
            return DIR_LEFT_TO_RIGHT;
        if (this->wChar == 0x200E)
            return DIR_LEFT_TO_RIGHT;
        if (this->wChar == 0x200F)
            return DIR_RIGHT_TO_LEFT;
    }
    return DIR_NEUTRAL;
}
