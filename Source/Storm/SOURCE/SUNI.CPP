#include "Storm.h"

extern const unsigned int gadwUtf8FirstByteMarks[]; // 0x006FCDA0
extern unsigned char gaTrailingBytesForUtf8[]; // 0x006FCCA0
extern unsigned int gaOffsetsFromUtf8[]; // 0x006FCC88
extern const unsigned char gaTrailingBytesForUtf8_006FCCA0[256]; // 0x006FCCA0
extern const unsigned int gaOffsetsFromUtf8_006FCC88[6]; // 0x006FCC88
extern const unsigned short gawWinTranslateTable[]; // 0x006FCDC0


// 0x006C7030
int __stdcall SUniConvertUTF16to8Len(const unsigned short* pSrc, unsigned int nSrcLength, unsigned int* pSrcRead)
{
    if (!nSrcLength || !pSrc)
    {
        if (pSrcRead)
        {
            *pSrcRead = 0;
        }
        return -1;
    }

    const unsigned short* pSrcStart = pSrc;
    const unsigned short* pSrcEnd = nSrcLength == 0x7FFFFFFF ? (const unsigned short*)-1 : pSrc + nSrcLength;
    int nResult = 0;

    for (;;)
    {
        if (pSrc >= pSrcEnd)
        {
            nResult = -1;
            break;
        }

        unsigned int ch = *pSrc++;
        if (ch - 0xD800 <= 0x3FF)
        {
            if (pSrc >= pSrcEnd)
            {
                nResult = -1;
                break;
            }

            const unsigned int ch2 = *pSrc;
            if (ch2 - 0xDC00 <= 0x3FF)
            {
                ch = ((ch - 0xD800) << 10) + (ch2 - 0xDC00) + 0x10000;
                ++pSrc;
            }
        }

        if (ch < 0x80)
        {
            ++nResult;
            if (!ch)
            {
                break;
            }
        }
        else if (ch < 0x800)
        {
            nResult += 2;
        }
        else if (ch < 0x10000)
        {
            nResult += 3;
        }
        else if (ch < 0x200000)
        {
            nResult += 4;
        }
        else if (ch < 0x4000000)
        {
            nResult += 5;
        }
        else if (ch <= 0x7FFFFFFF)
        {
            nResult += 6;
        }
        else
        {
            nResult += 2;
        }
    }

    if (pSrcRead)
    {
        *pSrcRead = pSrc - pSrcStart;
    }

    return nResult;
}

// 0x006C7130
int __stdcall SUniConvertUTF16to8(char* pDest, unsigned int nDestSize, const unsigned short* pSrc, unsigned int nSrcLength, unsigned int* pDestWritten, unsigned int* pSrcRead)
{
    const unsigned short* pSrcStart = pSrc;
    char* pDestStart = pDest;
    const unsigned short* pSrcEnd = nSrcLength == 0x7FFFFFFF ? (const unsigned short*)-1 : pSrc + nSrcLength;
    int nResult = 0;
    char* pDestEnd = pDest + nDestSize;

    for (;;)
    {
        if (pSrc >= pSrcEnd)
        {
            nResult = -1;
            break;
        }

        unsigned int ch = *pSrc;
        unsigned int nUnits = 1;
        if (ch - 0xD800 <= 0x3FF)
        {
            if (pSrc + 1 >= pSrcEnd)
            {
                nResult = -1;
                break;
            }

            const unsigned int ch2 = pSrc[1];
            if (ch2 - 0xDC00 <= 0x3FF)
            {
                ch = ((ch - 0xD800) << 10) + (ch2 - 0xDC00) + 0x10000;
                nUnits = 2;
            }
        }

        unsigned int nBytes;
        if (ch < 0x80)
        {
            nBytes = 1;
            if (!ch)
            {
                if (pDest >= pDestEnd)
                {
                    nResult = nBytes;
                    break;
                }

                *pDest = (char)ch;
                pDest += nBytes;
                break;
            }
        }
        else if (ch < 0x800)
        {
            nBytes = 2;
        }
        else if (ch < 0x10000)
        {
            nBytes = 3;
        }
        else if (ch < 0x200000)
        {
            nBytes = 4;
        }
        else if (ch < 0x4000000)
        {
            nBytes = 5;
        }
        else if (ch <= 0x7FFFFFFF)
        {
            nBytes = 6;
        }
        else
        {
            ch = 0xFFFD;
            nBytes = 2;
        }

        if (pDest + nBytes > pDestEnd)
        {
            nResult = nBytes;
            break;
        }

        pDest += nBytes;
        switch (nBytes)
        {
        case 6:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 5:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 4:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 3:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 2:
            *--pDest = (char)((ch & 0x3F) | 0x80);
            ch >>= 6;
        case 1:
            *--pDest = (char)(gadwUtf8FirstByteMarks[nBytes] | ch);
        }

        pSrc += nUnits;
        pDest += nBytes;
    }

    if (pSrcRead)
    {
        *pSrcRead = pSrc - pSrcStart;
    }

    if (pDestWritten)
    {
        *pDestWritten = pDest - pDestStart;
    }

    return nResult;
}

extern "C" const unsigned int gData_006FCC88[6] = { 0, 12416, 925824, 0x3C82080, 0xFA082080, 0x82082080 }; // 0x006FCC88
#pragma comment(linker, "/alternatename:?gnUtf8Offsets_006FCC88@@3PAIA=_gData_006FCC88")

extern "C" const unsigned char gData_006FCCA0[256] = { // 0x006FCCA0
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5
};
#pragma comment(linker, "/alternatename:?gnUtf8Trailing_006FCCA0@@3PAEA=_gData_006FCCA0")

extern "C" const unsigned int gData_006FCDA0[8] = { 0, 0, 192, 224, 240, 248, 252, 0 }; // 0x006FCDA0
#pragma comment(linker, "/alternatename:?gdwUtf8FirstByteMark_006FCDA0@@3QBIB=_gData_006FCDA0")

extern "C" const unsigned short gData_006FCDC0[256] = { // 0x006FCDC0
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    8364, 65535, 8218, 402, 8222, 8230, 8224, 8225, 710, 8240, 352, 8249, 338, 65535, 381, 65535,
    65535, 8216, 8217, 8220, 8221, 8226, 8211, 8212, 732, 8482, 353, 8250, 339, 65535, 382, 376,
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175,
    176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
    192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
    208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
    224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};
#pragma comment(linker, "/alternatename:?gWideTable_006FCDC0@@3QBGB=_gData_006FCDC0")

extern "C" const unsigned short gData_006FCFC0[256] = { // 0x006FCFC0
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    196, 197, 199, 201, 209, 214, 220, 225, 224, 226, 228, 227, 229, 231, 233, 232,
    234, 235, 237, 236, 238, 239, 241, 243, 242, 244, 246, 245, 250, 249, 251, 252,
    8224, 176, 162, 163, 167, 8226, 182, 223, 174, 169, 8482, 180, 168, 8800, 198, 216,
    8734, 177, 8804, 8805, 165, 181, 8706, 8721, 8719, 960, 8747, 170, 186, 8486, 230, 248,
    191, 161, 172, 8730, 402, 8776, 8710, 171, 187, 8230, 160, 192, 195, 213, 338, 339,
    8211, 8212, 8220, 8221, 8216, 8217, 247, 9674, 255, 376, 8260, 164, 8249, 8250, 64257, 64258,
    8225, 183, 8218, 8222, 8240, 194, 202, 193, 203, 200, 205, 206, 207, 204, 211, 212,
    65535, 210, 218, 219, 217, 305, 710, 732, 175, 728, 729, 730, 184, 733, 731, 711
};
#pragma comment(linker, "/alternatename:?gWideTable_006FCFC0@@3QBGB=_gData_006FCFC0")

extern "C" const unsigned short gData_006FD1C0[256] = { // 0x006FD1C0
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
    199, 252, 233, 226, 228, 224, 229, 231, 234, 235, 232, 239, 238, 236, 196, 197,
    201, 230, 198, 244, 246, 242, 251, 249, 255, 214, 220, 162, 163, 165, 8359, 402,
    225, 237, 243, 250, 241, 209, 170, 186, 191, 8976, 172, 189, 188, 161, 171, 187,
    9617, 9618, 9619, 9474, 9508, 9569, 9570, 9558, 9557, 9571, 9553, 9559, 9565, 9564, 9563, 9488,
    9492, 9524, 9516, 9500, 9472, 9532, 9566, 9567, 9562, 9556, 9577, 9574, 9568, 9552, 9580, 9575,
    9576, 9572, 9573, 9561, 9560, 9554, 9555, 9579, 9578, 9496, 9484, 9608, 9604, 9612, 9616, 9600,
    945, 223, 915, 960, 931, 963, 181, 964, 934, 920, 937, 948, 8734, 966, 949, 8745,
    8801, 177, 8805, 8804, 8992, 8993, 247, 8776, 176, 8729, 183, 8730, 8319, 178, 9632, 160
};
#pragma comment(linker, "/alternatename:?gWideTable_006FD1C0@@3QBGB=_gData_006FD1C0")

// 0x006C72F0
int __stdcall SUniConvertUTF8to16Len(const char* source, int maxLength, int* consumed)
{
 if (!maxLength || !source) { if(consumed) *consumed=0; return -1; }
 const char* start=source;
 const char* end=maxLength==0x7FFFFFFF ? (const char*)-1 : source+maxLength;
 int length=0;
 for(;;) {
  if(source>=end) { length=-1; break; }
  unsigned int trailing=gaTrailingBytesForUtf8[*source];
  if(source+trailing>=end) { length=-1-trailing; break; }
  unsigned int ch=0;
  switch(trailing) {
   case 5: ch+=*source++; ch<<=6;
   case 4: ch+=*source++; ch<<=6;
   case 3: ch+=*source++; ch<<=6;
   case 2: ch+=*source++; ch<<=6;
   case 1: ch+=*source++; ch<<=6;
   case 0: ch+=*source++;
  }
  ch-=gaOffsetsFromUtf8[trailing];
  if(ch<=0xFFFF) { ++length; if(!ch) break; }
  else if(ch>0x10FFFF) ++length;
  else length+=2;
 }
 if(consumed) *consumed=source-start;
 return length;
}

// 0x006C7410
int __stdcall SUniConvertUTF8to16(unsigned short* pDst, unsigned int nDstMax, const unsigned char* pSrc, unsigned int nSrcMax, unsigned int* pnDstWritten, unsigned int* pnSrcRead)
{
    const unsigned char* pSrcStart = pSrc;
    unsigned short* pDstStart = pDst;
    const unsigned char* pSrcEnd;
    if (nSrcMax == 0x7FFFFFFF)
    {
        pSrcEnd = (const unsigned char*)0xFFFFFFFF;
    }
    else
    {
        pSrcEnd = pSrc + nSrcMax;
    }
    unsigned short* pDstEnd = pDst + nDstMax;
    int nResult = 0;
    while (pSrc < pSrcEnd)
    {
        unsigned int nExtra = gaTrailingBytesForUtf8_006FCCA0[*pSrc];
        if (pSrc + nExtra >= pSrcEnd)
        {
            nResult = -1 - (int)nExtra;
            goto done;
        }
        int i = 0;
        unsigned int ch = 0;
        switch (nExtra)
        {
        case 5: ch += pSrc[i++]; ch <<= 6;
        case 4: ch += pSrc[i++]; ch <<= 6;
        case 3: ch += pSrc[i++]; ch <<= 6;
        case 2: ch += pSrc[i++]; ch <<= 6;
        case 1: ch += pSrc[i++]; ch <<= 6;
        case 0: ch += pSrc[i++];
        }
        ch -= gaOffsetsFromUtf8_006FCC88[nExtra];
        if (pDst >= pDstEnd)
        {
            nResult = 1;
            goto done;
        }
        if (ch <= 0xFFFF)
        {
            *pDst++ = (unsigned short)ch;
            if (!ch)
            {
                goto done;
            }
        }
        else if (ch > 0x10FFFF)
        {
            *pDst++ = 0xFFFD;
        }
        else
        {
            if (pDst + 1 >= pDstEnd)
            {
                nResult = 1;
                goto done;
            }
            ch -= 0x10000;
            *pDst++ = (unsigned short)((ch >> 10) + 0xD800);
            *pDst++ = (unsigned short)((ch & 0x3FF) + 0xDC00);
        }
        pSrc += i;
    }
    nResult = -1;
done:
    if (pnSrcRead)
    {
        *pnSrcRead = pSrc - pSrcStart;
    }
    if (pnDstWritten)
    {
        *pnDstWritten = pDst - pDstStart;
    }
    return nResult;
}

// 0x006C75B0
int __stdcall SUniSGetUTF8(const unsigned char* str, int* pLength)
{
    if (pLength)
        *pLength = 0;
    if (!str)
        return -1;

    unsigned int c = *str++;
    if (!c)
        return -1;
    if (pLength)
        ++*pLength;

    int nExtra;
    if ((c & 0xFE) == 0xFC)
    {
        c &= 1;
        nExtra = 5;
    }
    else if ((c & 0xFC) == 0xF8)
    {
        c &= 3;
        nExtra = 4;
    }
    else if ((c & 0xF8) == 0xF0)
    {
        c &= 7;
        nExtra = 3;
    }
    else if ((c & 0xF0) == 0xE0)
    {
        c &= 0xF;
        nExtra = 2;
    }
    else if ((c & 0xE0) == 0xC0)
    {
        c &= 0x1F;
        nExtra = 1;
    }
    else
    {
        if (c & 0x80)
            return 0x80000000;
        return c;
    }

    for (int i = 0; i < nExtra; ++i)
    {
        unsigned char b = *str++;
        if (!b)
            return -1;
        if (pLength)
            ++*pLength;
        if ((b & 0xC0) != 0x80)
            return 0x80000000;
        c = (c << 6) | (b & 0x3F);
    }
    return c;
}

// 0x006C76C0
unsigned char* __stdcall SUniSPutUTF8(unsigned int code,unsigned char* out)
{
 if (out) {
 unsigned char finalByte=(unsigned char)code;
 unsigned char lead;
 if (code<0x80) goto last;
 if (code<0x800) { lead=(unsigned char)(code>>6)|0xc0; goto two; }
 if (code<0x10000) { lead=(unsigned char)(code>>12)|0xe0; goto three; }
 if (code<0x200000) { lead=(unsigned char)(code>>18)|0xf0; goto four; }
 if (code<0x400000) { lead=(unsigned char)(code>>24)|0xf8; goto five; }
 if (code>=0x80000000) goto done;
 lead=(unsigned char)(code>>30)|0xfc;
 *out++=lead;
 lead=((unsigned char)(code>>24)&0x3f)|0x80;
five:
 *out++=lead;
 lead=((unsigned char)(code>>18)&0x3f)|0x80;
four:
 *out++=lead;
 lead=((unsigned char)(code>>12)&0x3f)|0x80;
three:
 *out++=lead;
 lead=((unsigned char)(code>>6)&0x3f)|0x80;
two:
 *out++=lead;
 finalByte=((unsigned char)code&0x3f)|0x80;
last:
 *out++=finalByte;
done:
 *out=0;
 }
 return out;
}

// 0x006C7790
static int SkipUtf8Continuation(const unsigned char* text, int index, int step)
{
    while (index > 0)
    {
        unsigned char ch = text[index];
        if (!ch || (ch & 0xC0) != 0x80)
            break;
        index += step;
    }
    return index;
}

// 0x006C77B0
int __stdcall SUniFindUTF8ChrStart(const unsigned char* text, int index)
{
    return SkipUtf8Continuation(text, index, -1);
}

// 0x006C77D0
int __stdcall SUniFindAfterUTF8Chr(const unsigned char* text, int index)
{
    return SkipUtf8Continuation(text, index + 1, 1);
}

// 0x006C77F0
static int __stdcall SUniConvertUTF16ToCP(const unsigned short* source, unsigned int count, const unsigned short* table, char* destination)
{
    if (!count)
    {
        return 0;
    }

    char* out = destination;
    unsigned short ch = *source;
    while (ch && count)
    {
        if (ch < 0x100 && ch == table[ch])
        {
            *out++ = (char)*source;
            ++source;
        }
        else
        {
            int i;
            for (i = 255; i > 0; --i)
            {
                if (ch == table[i])
                {
                    break;
                }
            }
            *out++ = (char)(i ? i : '?');
            ++source;
        }
        ch = *source;
        --count;
    }

    if (count)
    {
        *out++ = 0;
    }

    return out - destination;
}

// 0x006C78C0
static int TranslateToUnicode(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount, const unsigned short* pTable)
{
    if (!nCount)
    {
        return 0;
    }

    unsigned short* pWrite = pDest;
    while (*pSource)
    {
        if (!nCount)
        {
            return pWrite - pDest;
        }
        *pWrite = pTable[*pSource];
        ++pSource;
        ++pWrite;
        --nCount;
    }

    if (nCount)
    {
        *pWrite = 0;
        ++pWrite;
    }
    return pWrite - pDest;
}

// 0x006C7900
int __stdcall SUniConvertUTF16ToWin(char* pDest, const unsigned short* pSource, unsigned int nCount)
{
    return SUniConvertUTF16ToCP(pSource, nCount, gawWinTranslateTable, pDest);
}

// 0x006C7920
int __stdcall SUniConvertUTF16ToMac(char* pDest, const unsigned short* pSource, unsigned int nCount)
{
    return SUniConvertUTF16ToCP(pSource, nCount, gawTranslateTable, pDest);
}

// 0x006C7940
int __stdcall SUniConvertUTF16ToDos(char* pDest, const unsigned short* pSource, unsigned int nCount)
{
    return SUniConvertUTF16ToCP(pSource, nCount, gawDosTranslateTable, pDest);
}

// 0x006C7960
int __stdcall SUniConvertWinToUTF16(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount)
{
    return TranslateToUnicode(pDest, pSource, nCount, gawWinTranslateTable);
}

// 0x006C7980
int __stdcall SUniConvertMacToUTF16(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount)
{
    return TranslateToUnicode(pDest, pSource, nCount, gawTranslateTable);
}

// 0x006C79A0
int __stdcall SUniConvertDosToUTF16(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount)
{
    return TranslateToUnicode(pDest, pSource, nCount, gawDosTranslateTable);
}
