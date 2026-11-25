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

extern "C" const unsigned int gData_006FCC88[6]; // 0x006FCC88
extern "C" const unsigned char gData_006FCCA0[256]; // 0x006FCCA0
extern "C" const unsigned int gData_006FCDA0[8]; // 0x006FCDA0
extern "C" const unsigned short gData_006FCDC0[256]; // 0x006FCDC0
extern "C" const unsigned short gData_006FCFC0[256]; // 0x006FCFC0
extern "C" const unsigned short gData_006FD1C0[256]; // 0x006FD1C0

extern "C" const unsigned int gData_006FCC88[6] = { 0, 0x3080, 0xE2080, 0x3C82080, 0xFA082080, 0x82082080 }; // 0x006FCC88
#pragma comment(linker, "/alternatename:?gnUtf8Offsets_006FCC88@@3PAIA=_gData_006FCC88")

extern "C" const unsigned char gData_006FCCA0[256] = {
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
}; // 0x006FCCA0
#pragma comment(linker, "/alternatename:?gnUtf8Trailing_006FCCA0@@3PAEA=_gData_006FCCA0")

extern "C" const unsigned int gData_006FCDA0[8] = { 0, 0, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC }; // 0x006FCDA0
#pragma comment(linker, "/alternatename:?gdwUtf8FirstByteMark_006FCDA0@@3QBIB=_gData_006FCDA0")

extern "C" const unsigned short gData_006FCDC0[256] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0x20AC, 0xFFFF, 0x201A, 0x192, 0x201E, 0x2026, 0x2020, 0x2021, 0x2C6, 0x2030, 0x160, 0x2039, 0x152, 0xFFFF, 0x17D, 0xFFFF,
    0xFFFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014, 0x2DC, 0x2122, 0x161, 0x203A, 0x153, 0xFFFF, 0x17E, 0x178,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
}; // 0x006FCDC0
#pragma comment(linker, "/alternatename:?gWideTable_006FCDC0@@3QBGB=_gData_006FCDC0")

extern "C" const unsigned short gData_006FCFC0[256] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0xC4, 0xC5, 0xC7, 0xC9, 0xD1, 0xD6, 0xDC, 0xE1, 0xE0, 0xE2, 0xE4, 0xE3, 0xE5, 0xE7, 0xE9, 0xE8,
    0xEA, 0xEB, 0xED, 0xEC, 0xEE, 0xEF, 0xF1, 0xF3, 0xF2, 0xF4, 0xF6, 0xF5, 0xFA, 0xF9, 0xFB, 0xFC,
    0x2020, 0xB0, 0xA2, 0xA3, 0xA7, 0x2022, 0xB6, 0xDF, 0xAE, 0xA9, 0x2122, 0xB4, 0xA8, 0x2260, 0xC6, 0xD8,
    0x221E, 0xB1, 0x2264, 0x2265, 0xA5, 0xB5, 0x2202, 0x2211, 0x220F, 0x3C0, 0x222B, 0xAA, 0xBA, 0x2126, 0xE6, 0xF8,
    0xBF, 0xA1, 0xAC, 0x221A, 0x192, 0x2248, 0x2206, 0xAB, 0xBB, 0x2026, 0xA0, 0xC0, 0xC3, 0xD5, 0x152, 0x153,
    0x2013, 0x2014, 0x201C, 0x201D, 0x2018, 0x2019, 0xF7, 0x25CA, 0xFF, 0x178, 0x2044, 0xA4, 0x2039, 0x203A, 0xFB01, 0xFB02,
    0x2021, 0xB7, 0x201A, 0x201E, 0x2030, 0xC2, 0xCA, 0xC1, 0xCB, 0xC8, 0xCD, 0xCE, 0xCF, 0xCC, 0xD3, 0xD4,
    0xFFFF, 0xD2, 0xDA, 0xDB, 0xD9, 0x131, 0x2C6, 0x2DC, 0xAF, 0x2D8, 0x2D9, 0x2DA, 0xB8, 0x2DD, 0x2DB, 0x2C7
}; // 0x006FCFC0
#pragma comment(linker, "/alternatename:?gWideTable_006FCFC0@@3QBGB=_gData_006FCFC0")

extern "C" const unsigned short gData_006FD1C0[256] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0xC7, 0xFC, 0xE9, 0xE2, 0xE4, 0xE0, 0xE5, 0xE7, 0xEA, 0xEB, 0xE8, 0xEF, 0xEE, 0xEC, 0xC4, 0xC5,
    0xC9, 0xE6, 0xC6, 0xF4, 0xF6, 0xF2, 0xFB, 0xF9, 0xFF, 0xD6, 0xDC, 0xA2, 0xA3, 0xA5, 0x20A7, 0x192,
    0xE1, 0xED, 0xF3, 0xFA, 0xF1, 0xD1, 0xAA, 0xBA, 0xBF, 0x2310, 0xAC, 0xBD, 0xBC, 0xA1, 0xAB, 0xBB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556, 0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B, 0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580,
    0x3B1, 0xDF, 0x393, 0x3C0, 0x3A3, 0x3C3, 0xB5, 0x3C4, 0x3A6, 0x398, 0x3A9, 0x3B4, 0x221E, 0x3C6, 0x3B5, 0x2229,
    0x2261, 0xB1, 0x2265, 0x2264, 0x2320, 0x2321, 0xF7, 0x2248, 0xB0, 0x2219, 0xB7, 0x221A, 0x207F, 0xB2, 0x25A0, 0xA0
}; // 0x006FD1C0
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
