#include "Storm.h"

extern const unsigned int gdwUtf8FirstByteMark_006FCDA0[]; // 0x006FCDA0
extern unsigned char gnUtf8Trailing_006FCCA0[]; // 0x006FCCA0
extern unsigned int gnUtf8Offsets_006FCC88[]; // 0x006FCC88
extern const unsigned char gaTrailingBytesForUtf8_006FCCA0[256]; // 0x006FCCA0
extern const unsigned int gaOffsetsFromUtf8_006FCC88[6]; // 0x006FCC88
extern const unsigned short gWideTable_006FCDC0[]; // 0x006FCDC0


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
            *--pDest = (char)(gdwUtf8FirstByteMark_006FCDA0[nBytes] | ch);
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

#include "gen/data/Source/Storm/SOURCE/SUNI.inc"

// 0x006C72F0
int __stdcall SUniConvertUTF8to16Len(const char* source, int maxLength, int* consumed)
{
 if (!maxLength || !source) { if(consumed) *consumed=0; return -1; }
 const char* start=source;
 const char* end=maxLength==0x7FFFFFFF ? (const char*)-1 : source+maxLength;
 int length=0;
 for(;;) {
  if(source>=end) { length=-1; break; }
  unsigned int trailing=gnUtf8Trailing_006FCCA0[*source];
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
  ch-=gnUtf8Offsets_006FCC88[trailing];
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

// table stands for the original's register choice (count, source and the index in ebx/edi/esi); with a plain parameter they rotate
// 0x006C77F0
static int __stdcall SUniConvertUTF16ToCP(const unsigned short* source, unsigned int count, const unsigned short* volatile table, char* destination)
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
            *out = (char)*source;
        }
        else
        {
            int i = 255;
            const unsigned short* p = &table[253];
            do
            {
                if (ch == p[2])
                {
                    break;
                }
                if (ch == p[1])
                {
                    i -= 1;
                    break;
                }
                if (ch == p[0])
                {
                    i -= 2;
                    break;
                }
                if (ch == p[-1])
                {
                    i -= 3;
                    break;
                }
                if (ch == p[-2])
                {
                    i -= 4;
                    break;
                }
                i -= 5;
                p -= 5;
            }
            while (i > 0);
            *out = (char)(i ? i : '?');
        }
        ch = *++source;
        ++out;
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
    return SUniConvertUTF16ToCP(pSource, nCount, gWideTable_006FCDC0, pDest);
}

// 0x006C7920
int __stdcall SUniConvertUTF16ToMac(char* pDest, const unsigned short* pSource, unsigned int nCount)
{
    return SUniConvertUTF16ToCP(pSource, nCount, gWideTable_006FCFC0, pDest);
}

// 0x006C7940
int __stdcall SUniConvertUTF16ToDos(char* pDest, const unsigned short* pSource, unsigned int nCount)
{
    return SUniConvertUTF16ToCP(pSource, nCount, gWideTable_006FD1C0, pDest);
}

// 0x006C7960
int __stdcall SUniConvertWinToUTF16(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount)
{
    return TranslateToUnicode(pDest, pSource, nCount, gWideTable_006FCDC0);
}

// 0x006C7980
int __stdcall SUniConvertMacToUTF16(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount)
{
    return TranslateToUnicode(pDest, pSource, nCount, gWideTable_006FCFC0);
}

// 0x006C79A0
int __stdcall SUniConvertDosToUTF16(unsigned short* pDest, const unsigned char* pSource, unsigned int nCount)
{
    return TranslateToUnicode(pDest, pSource, nCount, gWideTable_006FD1C0);
}
