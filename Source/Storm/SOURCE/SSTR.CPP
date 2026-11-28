#include "SValidate.h"
#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "StormApi.h"

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

double __cdecl sub_00414260_PowInt(double x, int nExp);

extern "C" int __cdecl strncmp(const char* szLeft, const char* szRight, unsigned int nCount);

extern "C" int __cdecl _strnicmp(const char* szString1, const char* szString2, unsigned int nCount); // 0x00686040

unsigned int gdwSStrScanWord; // 0x007788D8

extern "C" const unsigned __int64 gqwSStrHash64Table[16]; // 0x006CEE70

struct D2CriticalSectionStrc;

struct SMEMHEAPDETAILS;

enum D2SMemBlockFlags
{
    SMEM_BLOCK_SENTINEL = 0x01,
    SMEM_BLOCK_FREE = 0x02,
    SMEM_BLOCK_LARGE = 0x04,
    SMEM_BLOCK_INDIRECT = 0x08,
    SMEM_BLOCK_PREVFREE = 0x10,
    SMEM_BLOCK_NOREPORT = 0x40,
    SMEM_BLOCK_KEEP = 0x80,
};

extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0

int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0

static void FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock); // 0x00411AA0

static int CheckPointer(void* pMemory, int bReport, const char* szFile, int nLine); // 0x00411910

typedef void (__stdcall* SMEMDUMPCALLBACK)(void* pParam, const char* szText);

extern "C" const unsigned int gadwSStrHashTable[16]; // 0x006CEE30

extern double gadPowTable_007788E0[20][10]; // 0x007788E0

// 0x00413550
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars)
{
    VALIDATEBEGIN;
    VALIDATE(szString1);
    VALIDATE(szString2);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return (int)(szString1 - szString2);
    }
    return nValid ? strncmp(szString1, szString2, nMaxChars) : 0;
}

// 0x00413590
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars)
{
    VALIDATEBEGIN;
    VALIDATE(szString1);
    VALIDATE(szString2);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return szString1 - szString2;
    }
    return nValid ? _strnicmp(szString1, szString2, nMaxChars) : 0;
}

// 0x00414310
char* __stdcall SStrDup(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const unsigned int nSize = SStrLen(szString) + 1;
    char* szResult = (char*)SMemAlloc(nSize, ".\\SOURCE\\SSTR.CPP", 0x1F2, 0);
    SMemCopy(szResult, szString, nSize);
    return nValid ? szResult : 0;
}

// 0x00413740
void __cdecl sub_00413740_Nop()
{
}

// 0x00413750
unsigned int __stdcall SStrLen(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    unsigned int dwOnes = 0xFFFFFFFF;
    const char* p = szString;
    while ((unsigned int)p & 3)
    {
        if (!*p)
        {
            goto done;
        }
        ++p;
    }
    for (;;)
    {
        const unsigned int w = *(const unsigned int*)p;
        dwOnes -= w;
        unsigned int dwTest = (w + 0x7EFEFEFF) ^ dwOnes;
        p += 4;
        dwOnes |= w;
        dwTest &= 0x81010101;
        if (dwTest)
        {
            if (!(char)w)
            {
                p -= 4;
                break;
            }
            if (!(char)(w >> 8))
            {
                p -= 3;
                break;
            }
            if (!(w & 0xFF0000))
            {
                p -= 2;
                break;
            }
            if (!(w & 0xFF000000))
            {
                p -= 1;
                break;
            }
            gdwSStrScanWord = dwTest;
        }
    }
done:
    return nValid ? p - szString : 0;
}

// 0x004135D0
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit)
{
 int valid=-1;
 valid&=dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int end=(unsigned int)dest+limit-1;
 int offset=(unsigned int)dest-end;
 while((unsigned int)source&3) {
  if(!offset) break;
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 offset+=3;
 if(offset<0) {
  end-=3;
  unsigned int word=*(const unsigned int*)source;
  source+=4;
  unsigned int ones=0xFFFFFFFF;
  ones-=word;
  unsigned int check=(word+0x7EFEFEFF)^ones;
  ones|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   ones-=word;
   check=(word+0x7EFEFEFF)^ones;
   ones|=word;
   check&=0x81010101;
  }
  for(;;) {
   if(!(unsigned char)word) {
    ((char*)end)[offset]=(char)word;
    goto Done;
   }
   if(!(unsigned char)(word>>8)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    offset+=1;
    goto Done;
   }
   if(!(word&0xFF0000)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    ((char*)end)[offset+2]=0;
    offset+=2;
    goto Done;
   }
   *(unsigned int*)(end+offset)=word;
   if(!(word&0xFF000000)) { offset+=3; goto Done; }
   offset+=4;
   gdwSStrScanWord=check;
   if(offset>=0) break;
   word=*(const unsigned int*)source;
   source+=4;
  }
Tail:
  end+=3;
 }
 offset-=3;
 while(offset) {
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 *(char*)end=0;
Done:
 return valid ? offset-(unsigned int)dest+end : 0;
}

// 0x00414370
__int64 __stdcall SStrToInt64(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const int bNegative = *szString == '-';
    if (bNegative)
    {
        ++szString;
    }
    unsigned int nAccum = *szString - '0';
    __int64 nResult = 0;
    const char* pStart = szString;
    if (nAccum < 10)
    {
        ++szString;
        unsigned int nDigit;
        while ((nDigit = *szString - '0') < 10)
        {
            nAccum = nAccum * 10 + nDigit;
            ++szString;
            if (nAccum >= 0x19999999)
            {
                double dPow;
                double x = 10.0;
                const int nExp = (int)(szString - pStart);
                unsigned int nBits;
                if (nExp >= 0)
                {
                    nBits = (unsigned int)nExp;
                }
                else
                {
                    nBits = (unsigned int)-nExp;
                }
                for (double z = 1.0; ; x *= x)
                {
                    if ((nBits & 1) != 0)
                    {
                        z *= x;
                    }
                    if ((nBits >>= 1) == 0)
                    {
                        dPow = nExp < 0 ? 1.0 / z : z;
                        break;
                    }
                }
                nResult = (__int64)(dPow + 0.5) * nResult + nAccum;
                nAccum = 0;
                pStart = szString;
            }
        }
    }
    else
    {
        nAccum = 0;
    }
    if (nResult)
    {
        nResult = (__int64)(sub_00414260_PowInt(10.0, (int)(szString - pStart)) + 0.5) * nResult + nAccum;
    }
    else
    {
        nResult = nAccum;
    }
    return nValid ? (bNegative ? -nResult : nResult) : 0;
}

// 0x00413800
unsigned int __stdcall SStrPack(char* dest, const char* source, unsigned int limit)
{
 int valid=(__int64)dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int dwOnes = 0xFFFFFFFF;
 const char* p = dest;
 unsigned int end=(unsigned int)dest+limit-1;
 if(limit!=0x7FFFFFFF) *(char*)end=0;
 while ((unsigned int)p & 3)
 {
  if (!*p) goto scanned;
  ++p;
 }
 for (;;)
 {
  const unsigned int w = *(const unsigned int*)p;
  dwOnes -= w;
  unsigned int dwTest = (w + 0x7EFEFEFF) ^ dwOnes;
  p += 4;
  dwOnes |= w;
  dwTest &= 0x81010101;
  if (dwTest)
  {
   if (!(char)w) { p -= 4; break; }
   if (!(char)(w >> 8)) { p -= 3; break; }
   if (!(w & 0xFF0000)) { p -= 2; break; }
   if (!(w & 0xFF000000)) { p -= 1; break; }
   gdwSStrScanWord = dwTest;
  }
 }
scanned:
 int offset=(unsigned int)p-end;
 while((unsigned int)source&3) {
  if(!offset) break;
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 offset+=3;
 if(offset<0) {
  end-=3;
  unsigned int word=*(const unsigned int*)source;
  source+=4;
  dwOnes-=word;
  unsigned int check=(word+0x7EFEFEFF)^dwOnes;
  dwOnes|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   dwOnes-=word;
   check=(word+0x7EFEFEFF)^dwOnes;
   dwOnes|=word;
   check&=0x81010101;
  }
  for(;;) {
   if(!(unsigned char)word) {
    ((char*)end)[offset]=(char)word;
    goto Done;
   }
   if(!(unsigned char)(word>>8)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    offset+=1;
    goto Done;
   }
   if(!(word&0xFF0000)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    ((char*)end)[offset+2]=0;
    offset+=2;
    goto Done;
   }
   *(unsigned int*)(end+offset)=word;
   if(!(word&0xFF000000)) { offset+=3; goto Done; }
   offset+=4;
   gdwSStrScanWord=check;
   if(offset>=0) break;
   word=*(const unsigned int*)source;
   source+=4;
  }
Tail:
  end+=3;
 }
 offset-=3;
 while(offset) {
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 *(char*)end=0;
Done:
 return valid ? offset-(unsigned int)dest+end : 0;
}

typedef unsigned int size_t;

typedef char* va_list;

extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1

static int InternalVPrintf(char* szDest, size_t nSize, const char* szFormat, va_list args); // 0x00413A00

// 0x00413490
const char* __stdcall SStrChr(const char* szString, char nChar)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    for (; *szString; ++szString)
    {
        if (*szString == nChar)
            return nValid ? szString : 0;
    }
    return 0;
}

// 0x00413510
const char* __stdcall SStrChrDir(const char* szString, char nChar, int bReverse)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    if (bReverse)
        return SStrChrR(szString, nChar);
    return nValid ? SStrChr(szString, nChar) : 0;
}

// 0x00413AC0
int __stdcall SStrToInt(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const int bNegative = (*szString == '-');
    if (bNegative)
    {
        ++szString;
    }
    int nResult = *szString - '0';
    if ((unsigned int)nResult < 10)
    {
        unsigned int nDigit = *++szString - '0';
        while (nDigit < 10)
        {
            ++szString;
            nResult = nResult * 10 + nDigit;
            nDigit = *szString - '0';
        }
    }
    else
    {
        nResult = 0;
    }
    return nValid ? (bNegative ? -nResult : nResult) : 0;
}

// 0x00413B80
void __stdcall SStrTokenize(const char** pszString, char* szBuffer, unsigned int nBufferChars, const char* szWhitespace, int* pQuoted)
{
    VALIDATEBEGIN;
    VALIDATE(pszString);
    VALIDATE(*pszString);
    VALIDATE(szBuffer || !nBufferChars);
    VALIDATE(szWhitespace);
    VALIDATEENDVOID;

    const int bQuotesAllowed = SStrChr(szWhitespace, '"') != 0;
    const char* pCurr = *pszString;
    int bInQuotes = 0;
    int bUsedQuotes = 0;
    while (*pCurr && SStrChr(szWhitespace, *pCurr))
    {
        if (bQuotesAllowed && *pCurr == '"')
        {
            bUsedQuotes = 1;
            bInQuotes = 1;
            ++pCurr;
            break;
        }
        ++pCurr;
    }

    unsigned int nLength = 0;
    char nChar;
    while ((nChar = *pCurr) != 0)
    {
        if (bQuotesAllowed && nChar == '"')
        {
            if (nLength && !bInQuotes)
            {
                break;
            }
            bInQuotes = !bInQuotes;
            ++pCurr;
            bUsedQuotes = 1;
            if (!bInQuotes)
            {
                break;
            }
            continue;
        }
        if (!bInQuotes && SStrChr(szWhitespace, nChar))
        {
            ++pCurr;
            break;
        }
        if (nLength + 1 < nBufferChars)
        {
            szBuffer[nLength++] = nChar;
        }
        ++pCurr;
    }

    if (nLength < nBufferChars)
    {
        szBuffer[nLength] = 0;
    }
    *pszString = pCurr;
    if (nValid && pQuoted)
    {
        *pQuoted = bUsedQuotes;
    }
}

// 0x00413DC0
unsigned __int64 __stdcall SStrHash64(const char* szString, unsigned int nFlags, unsigned __int64 nSeed)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    unsigned __int64 nResult = nSeed ? nSeed : 0x7FED7FED7FED7FEDui64;
    unsigned __int64 nAdjust = 0xEEEEEEEEEEEEEEEEui64;
    unsigned int nChar;
    if (nFlags & 1)
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            nResult = (gqwSStrHash64Table[nChar >> 4] - gqwSStrHash64Table[nChar & 0xF]) ^ (nAdjust + nResult);
            nAdjust = nAdjust * 0x21 + nChar + nResult + 3;
        }
    }
    else
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            if (nChar >= 'a' && nChar <= 'z')
            {
                nChar -= 0x20;
            }
            if (nChar == '/')
            {
                nChar = '\\';
            }
            nResult = (gqwSStrHash64Table[nChar >> 4] - gqwSStrHash64Table[nChar & 0xF]) ^ (nAdjust + nResult);
            nAdjust = nAdjust * 0x21 + nChar + nResult + 3;
        }
    }
    if (!nResult)
    {
        nResult = 1;
    }
    return nValid ? nResult : 0;
}

// 0x00413A40
extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...)
{
    VALIDATEBEGIN;
    VALIDATE(szDest);
    VALIDATE(szFormat);
    VALIDATEEND;
    return nValid ? InternalVPrintf(szDest, nMaxCount, szFormat, (va_list)(&szFormat + 1)) : 0;
}

// 0x00413A80
extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list args)
{
    VALIDATEBEGIN;
    VALIDATE(szDest);
    VALIDATE(szFormat);
    VALIDATEEND;
    return nValid ? InternalVPrintf(szDest, nMaxCount, szFormat, args) : 0;
}

extern "C" { int gfSStrInitialized; }                                                                         // 0x007788DC

extern "C" void __cdecl SStrInitialize();                                                     // 0x00414360

double gadDigitScale[20][10];                                                                      // 0x007788E0

template <class T>
inline T StormPowInt(T x, int nExp)
{
    unsigned int nBits;
    if (nExp >= 0)
        nBits = (unsigned int)nExp;
    else
        nBits = (unsigned int)-nExp;
    for (T z = T(1); ; x *= x)
    {
        if ((nBits & 1) != 0)
            z *= x;
        if ((nBits >>= 1) == 0)
            return nExp < 0 ? T(1) / z : z;
    }
}

// 0x004144B0
extern "C" inline void __cdecl EnsureSStrInitialized()
{
    if (!gfSStrInitialized)
        SStrInitialize();
}

// 0x004144C0
double __stdcall SStrToDouble(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    EnsureSStrInitialized();
    const int bNegative = *szString == '-';
    if (bNegative)
    {
        ++szString;
    }
    double dResult = 0.0;
    unsigned int nAccum = *szString - '0';
    const char* pStart = szString;
    if (nAccum < 10)
    {
        ++szString;
        unsigned int nDigit;
        while ((nDigit = *szString - '0') < 10)
        {
            nAccum = nAccum * 10 + nDigit;
            ++szString;
            if (nAccum >= 0x19999999)
            {
                dResult = StormPowInt(10.0, (int)(szString - pStart)) * dResult + nAccum;
                nAccum = 0;
                pStart = szString;
            }
        }
    }
    else
    {
        nAccum = 0;
    }
    if (dResult != 0.0)
    {
        dResult = sub_00414260_PowInt(10.0, (int)(szString - pStart)) * dResult + nAccum;
    }
    else
    {
        dResult = nAccum;
    }
    if (*szString == '.')
    {
        ++szString;
        unsigned int nDigit;
        for (int i = 0; (nDigit = *szString - '0') < 10; ++i)
        {
            ++szString;
            if (i >= 20)
                dResult += StormPowInt(10.0, -1 - i) * nDigit;
            else
                dResult += gadDigitScale[i][nDigit];
        }
    }
    if (*szString == 'e' || *szString == 'E')
    {
        ++szString;
        if (*szString == '+')
        {
            ++szString;
        }
        dResult *= StormPowInt(10.0, SStrToInt(szString));
    }
    return nValid ? (bNegative ? -dResult : dResult) : 0;
}

// 0x004146F0
float __stdcall SStrToFloat(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    EnsureSStrInitialized();
    const int bNegative = *szString == '-';
    if (bNegative)
    {
        ++szString;
    }
    double dResult = 0.0;
    unsigned int nAccum = *szString - '0';
    const char* pStart = szString;
    if (nAccum < 10)
    {
        ++szString;
        unsigned int nDigit;
        while ((nDigit = *szString - '0') < 10)
        {
            nAccum = nAccum * 10 + nDigit;
            ++szString;
            if (nAccum >= 0x19999999)
            {
                dResult = StormPowInt(10.0, (int)(szString - pStart)) * dResult + nAccum;
                nAccum = 0;
                pStart = szString;
            }
        }
    }
    else
    {
        nAccum = 0;
    }
    if (dResult != 0.0)
    {
        dResult = sub_00414260_PowInt(10.0, (int)(szString - pStart)) * dResult + nAccum;
    }
    else
    {
        dResult = nAccum;
    }
    if (*szString == '.')
    {
        ++szString;
        unsigned int nDigit;
        for (int i = 0; (nDigit = *szString - '0') < 10; ++i)
        {
            ++szString;
            if (i >= 20)
                dResult += StormPowInt(10.0, -1 - i) * nDigit;
            else
                dResult += gadDigitScale[i][nDigit];
        }
    }
    if (*szString == 'e' || *szString == 'E')
    {
        ++szString;
        if (*szString == '+')
        {
            ++szString;
        }
        dResult *= StormPowInt(10.0, SStrToInt(szString));
    }
    if (!nValid) return 0;
    if (bNegative) return (float)-dResult;
    return (float)dResult;
}

// build: symbol ?FatalMemoryError@* 0x00411620
static __declspec(noreturn) void FatalMemoryError(unsigned int nError, const char* szFile, int nLine)
{
    SErrDisplayError(nError, szFile, nLine, 0, 0, 1);
    ExitProcess(1);
}

// 0x004134D0
const char* __stdcall SStrChrR(const char* szString, char nChar)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    const char* pLast = 0;
    for (const char* pString = szString; *pString; ++pString)
    {
        if (*pString == nChar)
            pLast = pString;
    }
    return nValid ? pLast : 0;
}

// 0x00413A00
static int InternalVPrintf(char* szDest, size_t nSize, const char* szFormat, va_list args)
{
    if (nSize)
    {
        if (nSize != 0x7FFFFFFF)
        {
            size_t nResult = _vsnprintf(szDest, nSize, szFormat, args);
            if (nResult >= nSize)
            {
                nResult = nSize - 1;
                szDest[nResult] = 0;
            }
            return nResult;
        }
        return vsprintf(szDest, szFormat, args);
    }
    return 0;
}

extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list args);

// 0x00413B30
int __stdcall SStrToUnsigned(const char* szString)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    int nResult = *szString - '0';
    if ((unsigned int)nResult < 10)
    {
        unsigned int nDigit = *++szString - '0';
        while (nDigit < 10)
        {
            ++szString;
            nResult = nResult * 10 + nDigit;
            nDigit = *szString - '0';
        }
    }
    else
    {
        nResult = 0;
    }
    return nValid ? nResult : 0;
}

// 0x00413CE0
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed)
{
    VALIDATEBEGIN;
    VALIDATE(szString);
    VALIDATEEND;
    unsigned int nResult = nSeed ? nSeed : 0x7FED7FED;
    unsigned int nAdjust = 0xEEEEEEEE;
    unsigned int nChar;
    if (nFlags & 1)
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            nResult = (gadwSStrHashTable[nChar >> 4] - gadwSStrHashTable[nChar & 0xF]) ^ (nResult + nAdjust);
            nAdjust = (nAdjust << 5) + nChar + nAdjust + nResult + 3;
        }
    }
    else
    {
        while ((nChar = (unsigned char)*szString) != 0)
        {
            ++szString;
            if (nChar >= 'a' && nChar <= 'z')
            {
                nChar -= 0x20;
            }
            if (nChar == '/')
            {
                nChar = '\\';
            }
            nResult = (gadwSStrHashTable[nChar >> 4] - gadwSStrHashTable[nChar & 0xF]) ^ (nResult + nAdjust);
            nAdjust = (nAdjust << 5) + nChar + nAdjust + nResult + 3;
        }
    }
    if (!nResult)
    {
        nResult = 1;
    }
    return nValid ? nResult : 0;
}

template <class T>
inline T PowIntT(T x, int nExp)
{
    unsigned int n;
    if (nExp >= 0)
        n = (unsigned int)nExp;
    else
        n = (unsigned int)(-nExp);
    for (T z = T(1); ; x *= x)
    {
        if ((n & 1) != 0)
            z *= x;
        if ((n >>= 1) == 0)
            return (nExp < 0 ? T(1) / z : z);
    }
}

// 0x004142A0
void __cdecl InitPowTable()
{
    for (int nExp = 0; nExp < 20; ++nExp)
    {
        for (int i = 0; i < 10; ++i)
        {
            gadPowTable_007788E0[nExp][i] = PowIntT(10.0, -(nExp + 1)) * i;
        }
    }
}

// 0x00414360
extern "C" void __cdecl SStrInitialize()
{
    InitPowTable();
    gfSStrInitialized = 1;
}

extern "C" char* __cdecl _strupr(char* szString); // 0x006862A2
extern "C" char* __cdecl _strlwr(char* szString); // 0x006864E1

#define STORM_LOOKUP2_MIX(a, b, c) \
{ \
    a -= b; a -= c; a ^= (c >> 13); \
    b -= c; b -= a; b ^= (a << 8); \
    c -= a; c -= b; c ^= (b >> 13); \
    a -= b; a -= c; a ^= (c >> 12); \
    b -= c; b -= a; b ^= (a << 16); \
    c -= a; c -= b; c ^= (b >> 5); \
    a -= b; a -= c; a ^= (c >> 3); \
    b -= c; b -= a; b ^= (a << 10); \
    c -= a; c -= b; c ^= (b >> 15); \
}

// 0x00413F30
unsigned int __fastcall bjhash(const unsigned char* k, unsigned int nLength, unsigned int nInitVal)
{
    unsigned int a, b, c, len;
    len = nLength;
    a = b = 0x9E3779B9;
    c = nInitVal;
    while (len >= 12)
    {
        a += (k[0] + ((unsigned int)k[1] << 8) + ((unsigned int)k[2] << 16) + ((unsigned int)k[3] << 24));
        b += (k[4] + ((unsigned int)k[5] << 8) + ((unsigned int)k[6] << 16) + ((unsigned int)k[7] << 24));
        c += (k[8] + ((unsigned int)k[9] << 8) + ((unsigned int)k[10] << 16) + ((unsigned int)k[11] << 24));
        STORM_LOOKUP2_MIX(a, b, c);
        k += 12;
        len -= 12;
    }
    c += nLength;
    switch (len)
    {
    case 11: c += ((unsigned int)k[10] << 24);
    case 10: c += ((unsigned int)k[9] << 16);
    case 9: c += ((unsigned int)k[8] << 8);
    case 8: b += ((unsigned int)k[7] << 24);
    case 7: b += ((unsigned int)k[6] << 16);
    case 6: b += ((unsigned int)k[5] << 8);
    case 5: b += k[4];
    case 4: a += ((unsigned int)k[3] << 24);
    case 3: a += ((unsigned int)k[2] << 16);
    case 2: a += ((unsigned int)k[1] << 8);
    case 1: a += k[0];
    }
    STORM_LOOKUP2_MIX(a, b, c);
    return c;
}

// 0x00414150
unsigned int __stdcall SStrHashHT(const char* szPath)
{
    char szBuffer[0x400];
    char* p = szBuffer;
    unsigned int nLength = 0;
    unsigned int c;
    while ((c = (unsigned char)*szPath) != 0)
    {
        ++szPath;
        if (nLength >= 0x3FF)
            break;
        if (c - 'a' <= 25)
            c -= 0x20;
        else if (c == '/')
            c = '\\';
        *p++ = (char)c;
        ++nLength;
    }
    *p = 0;
    return bjhash((const unsigned char*)szBuffer, nLength, 0);
}

// 0x004141E0
char* __stdcall SStrUpper(char* szString)
{
    return _strupr(szString);
}

// 0x00414200
char* __stdcall SStrLower(char* szString)
{
    return _strlwr(szString);
}
