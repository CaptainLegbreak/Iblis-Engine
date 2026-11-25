#include "D2LangTypes.h"
struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(const Unicode& other) : wChar(other.wChar) {}
};

extern D2UtfConvertSpecStrc gaUtf8ConvertTable[7]; // 0x007309B8

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

// 0x005262F0
int __fastcall sub_005262F0_UnicodeCharUtf8Length(const Unicode* pChar)
{
    char szBuffer[8];
    return sub_00526190_UnicodeCharToUtf8(szBuffer, *pChar);
}
