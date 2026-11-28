#include "Fog.h"
#include "D2StormLink.h"
#include "D2GameTypes.h"
#include "D2Primitives.h"
#include "D2StormTypes.h"
#include "D2NetTypes.h"
#include "D2FogTypes.h"
#include "FogApi.h"
#include "StormApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern int ganByteTable[256]; // 0x006CE398

extern int ganLowBitTable[256]; // 0x006CE798

extern char gszLowerTable[256]; // 0x006CEB98

extern "C" long __cdecl _time32(long* pTime);

extern "C" int __cdecl tolower(int nChar);

// build: symbol ?gacCDKeyMap@* 0x006DF238
extern const char gacCDKeyMap[];

struct D2BitBufferStrc;

struct D2BitCodeStrc;

struct D2TimedRecordStrc;

struct D2BitCodeStrc
{
    int nValue;
    int nBits;
};

extern unsigned int gadwLowMasks[]; // 0x006CE368

unsigned int __stdcall sub_00410F60_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00410F60

struct D2TimedRecordStrc
{
    char unk0x00[0x08];
    __int64 qwValue;
    char unk0x10[0x08];
};

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency); // 0x006CC254

D2TimedRecordStrc gaTimerTable[0x1000]; // 0x0075E8A0

int gnTimerTicksPerMs; // 0x0075E89C

int gnTimerTicksPerUs; // 0x0075E898

unsigned int gnRecordCount; // 0x007768A4

int gnTickAtReset; // 0x007768A0

extern "C" void* __cdecl memset(void*, int, unsigned int);

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

static void __stdcall ReportHeapError(const char* szFile, int nLine, unsigned int nError); // 0x004117A0

static void FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock); // 0x00411AA0

void __cdecl sub_00411280_ResetRecords(); // 0x00411280

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385

D2PoolDirectoryStrc gtPoolManager;                                                                   // 0x0074F0E8

extern const unsigned char gabOffsetMasks[9]; // 0x006CE38C

extern unsigned short gawStringCrcTable[256]; // 0x00708140

// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// build: symbol ?BNSEND_NibbleToHex@* 0x0051DD10
static unsigned int BNSEND_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

// build: symbol ?BNSEND_HexToNibble@* 0x0051DD20
static int BNSEND_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// build: symbol ?BNSEND_MapKeyChar@* 0x0051DD40
static int BNSEND_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

// 0x00410B10
void __stdcall sub_00410B10(unsigned char* pBits, int nBit)
{
    pBits[nBit >> 3] |= gdwBitMasks[nBit & 7];
}

// 0x00410B30
int __stdcall sub_00410B30(unsigned char* pBits, int nBit)
{
    return pBits[nBit >> 3] & gdwBitMasks[nBit & 7];
}

// 0x00410B50
void __stdcall sub_00410B50(unsigned char* pBits, int nBit)
{
    pBits[nBit >> 3] &= gdwInvBitMasks[nBit & 7];
}

// 0x00410B70
void __stdcall sub_00410B70(unsigned char* pBits, int nBit)
{
    pBits[nBit >> 3] ^= gdwBitMasks[nBit & 7];
}

// 0x00410B90
void __stdcall sub_00410B90(const unsigned char* pA, const unsigned char* pB, unsigned char* pOut, int nBits)
{
    nBits = (nBits + 7) / 8;
    const int nAligned = 4 * (nBits / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = *(const int*)&pA[i] & *(const int*)&pB[i];
    }
    switch (nBits - nAligned)
    {
    case 3:
        pOut[i + 2] = pA[i + 2] & pB[i + 2];
    case 2:
        pOut[i + 1] = pA[i + 1] & pB[i + 1];
    case 1:
        pOut[i] = pA[i] & pB[i];
    }
}

// 0x00410C40
void __stdcall BITMANIP_OrBits(const unsigned char* pA, const unsigned char* pB, unsigned char* pOut, int nBits)
{
    nBits = (nBits + 7) / 8;
    const int nAligned = 4 * (nBits / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = *(const int*)&pA[i] | *(const int*)&pB[i];
    }
    switch (nBits - nAligned)
    {
    case 3:
        pOut[i + 2] = pA[i + 2] | pB[i + 2];
    case 2:
        pOut[i + 1] = pA[i + 1] | pB[i + 1];
    case 1:
        pOut[i] = pA[i] | pB[i];
    }
}

// 0x00410CF0
void __stdcall sub_00410CF0_NotBits(const unsigned char* pIn, unsigned char* pOut, int nBits)
{
    const int nBytes = (nBits + 7) / 8;
    const int nAligned = 4 * (nBytes / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = ~*(const int*)&pIn[i];
    }
    switch (nBytes - nAligned)
    {
    case 3:
        pOut[i + 2] = ~pIn[i + 2];
    case 2:
        pOut[i + 1] = ~pIn[i + 1];
    case 1:
        pOut[i] = ~pIn[i];
    }
}

// 0x00410D90
void __stdcall sub_00410D90_XorBits(const unsigned char* pA, const unsigned char* pB, unsigned char* pOut, int nBits)
{
    nBits = (nBits + 7) / 8;
    int nAligned = 4 * (nBits / 4);
    int i;
    for (i = 0; i < nAligned; i += 4)
    {
        *(int*)&pOut[i] = *(const int*)&pA[i] ^ *(const int*)&pB[i];
    }
    switch (nBits - nAligned)
    {
    case 3:
        pOut[i + 2] = pA[i + 2] ^ pB[i + 2];
    case 2:
        pOut[i + 1] = pA[i + 1] ^ pB[i + 1];
    case 1:
        pOut[i] = pA[i] ^ pB[i];
    }
}

// 0x00410E40
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize)
{
    D2_ASSERT(pBuffer, 316);
    pBuffer->pBuffer = pBitStream;
    pBuffer->nBits = 8 * nSize;
    pBuffer->nPos = 0;
    pBuffer->nPosBits = 0;
    pBuffer->bFull = 0;
}

// 0x00410E90
extern "C" int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer)
{
    return pBuffer->nPosBits ? pBuffer->nPos + 1 : pBuffer->nPos;
}

// 0x00410EB0
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits)
{
    if (pBuffer->nPosBits + 8 * pBuffer->nPos + nBits > pBuffer->nBits)
    {
        pBuffer->bFull = 1;
        pBuffer->nPos = pBuffer->nBits / 8;
        pBuffer->nPosBits = 0;
        return;
    }
    if (!pBuffer->nPosBits)
    {
        *pBuffer->pBuffer = 0;
    }
    while (nBits > 0)
    {
        int n = 8 - pBuffer->nPosBits;
        if (n > nBits)
        {
            n = nBits;
        }
        *pBuffer->pBuffer |= (unsigned char)(gadwLowMasks[n] & nValue) << pBuffer->nPosBits;
        pBuffer->nPosBits += n;
        if (pBuffer->nPosBits != 8)
        {
            break;
        }
        ++pBuffer->nPos;
        ++pBuffer->pBuffer;
        pBuffer->nPosBits = 0;
        if (8 * pBuffer->nPos < pBuffer->nBits)
        {
            *pBuffer->pBuffer = 0;
        }
        nValue >>= n;
        nBits -= n;
    }
}

// 0x00410F60
unsigned int __stdcall sub_00410F60_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    int n = pBuffer->nPosBits + nBits + 8 * pBuffer->nPos - pBuffer->nBits;

    if (n < 0)
    {
        n = 0;
    }

    nBits -= n;
    if (n)
    {
        pBuffer->bFull = 1;
    }

    unsigned int dwValue = 0;
    unsigned int dw = 0;
    int dwBitsLeft = nBits;

    if (dwBitsLeft > 0)
    {
        do
        {
            int i = 8 - pBuffer->nPosBits;
            if (i > dwBitsLeft)
            {
                i = dwBitsLeft;
            }
            const int nPosBits = pBuffer->nPosBits;

            dwValue += (gadwLowMasks[i] & ((unsigned char)(*pBuffer->pBuffer & gabOffsetMasks[nPosBits]) >> nPosBits)) << dw;
            dwBitsLeft -= i;
            dw += i;
            pBuffer->nPosBits += i;

            if (pBuffer->nPosBits == 8)
            {
                pBuffer->pBuffer = pBuffer->pBuffer + 1;
                ++pBuffer->nPos;
                pBuffer->nPosBits = 0;
            }
        }
        while (dwBitsLeft > 0);
    }

    return dwValue;
}

// 0x00411020
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits)
{
    return sub_00410F60_ReadBits(pBuffer, nBits);
}

// 0x00411030
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits)
{
    int nValue = sub_00410F60_ReadBits(pBuffer, nBits);
    if (nBits < 32 && ((1 << (nBits - 1)) & nValue))
    {
        nValue |= ~((1 << nBits) - 1);
    }
    return nValue;
}

// 0x00411070
void __stdcall BITMANIP_GoToNextByte(D2BitBufferStrc* pBuffer)
{
    if (pBuffer->nPosBits)
    {
        ++pBuffer->nPos;
        ++pBuffer->pBuffer;
        pBuffer->nPosBits = 0;
        if (8 * pBuffer->nPos < pBuffer->nBits)
        {
            *pBuffer->pBuffer = 0;
        }
    }
}

// 0x004110B0
void __stdcall sub_004110B0_WriteCode(D2BitBufferStrc* pBuffer, D2BitCodeStrc* pCodes, int nIndex)
{
    BITMANIP_Write(pBuffer, pCodes[nIndex].nValue, pCodes[nIndex].nBits);
}

// 0x004110D0
int __stdcall sub_004110D0_ReadTreeCode(D2BitBufferStrc* pBuffer, int* pTree)
{
    int nNode = 0;
    for (;;)
    {
        int nBit = (gdwBitMasks[pBuffer->nPosBits] & *pBuffer->pBuffer) >> pBuffer->nPosBits;
        ++pBuffer->nPosBits;
        if (pBuffer->nPosBits == 8)
        {
            ++pBuffer->pBuffer;
            ++pBuffer->nPos;
            pBuffer->nPosBits = 0;
        }
        if (pTree[nBit + nNode] >= 0)
        {
            return pTree[nBit + nNode];
        }
        nNode = 2 * (nBit + nNode) + 2;
    }
}

// 0x00411130
int __stdcall FOG_ComputeChecksum(unsigned char* pData, int nSize)
{
    int nChecksum = 0;
    for (int i = 0; i < nSize; ++i)
    {
        nChecksum = pData[i] + (nChecksum < 0) + 2 * nChecksum;
    }
    return nChecksum;
}

// 0x00411170
int __stdcall sub_00411170_SumByteTable(unsigned char* pData, int nSize)
{
    int nTotal = 0;
    for (unsigned char* pEnd = pData + nSize; pData < pEnd; ++pData)
    {
        nTotal += ganByteTable[*pData];
    }
    return nTotal;
}

// 0x004111A0
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue)
{
    if (nValue)
    {
        unsigned char* pBytes = (unsigned char*)&nValue;
        if (pBytes[0] > 0) return ganLowBitTable[pBytes[0]];
        if (pBytes[1] > 0) return ganLowBitTable[pBytes[1]] + 8;
        if (pBytes[2] > 0) return ganLowBitTable[pBytes[2]] + 16;
        if (pBytes[3] > 0) return ganLowBitTable[pBytes[3]] + 24;
    }
    return -1;
}

// 0x00411210
void __cdecl sub_00411210_InitTimer()
{
    __int64 nFrequency;
    QueryPerformanceFrequency(&nFrequency);
    gnTimerTicksPerMs = (int)(nFrequency / 1000);
    gnTimerTicksPerUs = (int)(nFrequency / 1000000);
    memset(gaTimerTable, 0, sizeof(gaTimerTable));
    gnTickAtReset = GetTickCount();
}

// 0x00411280
void __cdecl sub_00411280_ResetRecords()
{
    for (unsigned int i = 0; i < gnRecordCount; ++i)
    {
        gaTimerTable[i].qwValue = 0;
    }
    gnTickAtReset = GetTickCount();
}

// 0x004112B0
unsigned long __cdecl sub_004112B0_GetTickCount()
{
    return GetTickCount();
}

// 0x004112C0
unsigned short __stdcall FOG_ComputeStringCRC16(const char* szString)
{
    unsigned short wCrc = 0xFFFF;
    char c;
    while ((c = (char)tolower((unsigned char)*szString++)) != 0)
    {
        wCrc = (wCrc >> 2) ^ gawStringCrcTable[(c ^ wCrc) & 0xFF];
    }
    return wCrc;
}

// 0x00411320
void __stdcall sub_00411320_CapitalizeWords(char* szText)
{
    int bNewWord = 1;
    if (!szText)
    {
        return;
    }
    int i = 0;
    const int nLength = strlen(szText);
    while (i < nLength)
    {
        D2_ASSERT(i < 0x400, 120);
        const char c = szText[i];
        if (c == ' ')
        {
            bNewWord = 1;
            ++i;
            continue;
        }
        if (bNewWord)
        {
            bNewWord = 0;
            szText[i] = toupper(c);
        }
        else
        {
            szText[i] = tolower(c);
        }
        ++i;
    }
}

// 0x004113C0
void __fastcall sub_004113C0(char* szString, int nLength)
{
    for (char* pEnd = szString + nLength; *szString && szString < pEnd; ++szString)
    {
        *szString = gszLowerTable[*szString];
    }
}

// 0x004113E0
char* __fastcall sub_004113E0_EscapeString(char* szDst, const char* szSrc, int nSize, char cQuote)
{
    const char* pSrc = szSrc;

    D2_ASSERT(szDst, 0xC0);

    if (!szSrc)
    {
        SStrPrintf(szDst, nSize, "<NULL>");
        return szDst;
    }

    int nLeft = nSize - 1;
    if (nSize)
    {
        char* p = szDst;
        if (cQuote && nLeft > 0)
        {
            *p++ = cQuote;
            --nLeft;
        }

        while (nLeft > 0)
        {
            const char c = *pSrc;
            if (!c)
            {
                break;
            }
            ++pSrc;
            --nLeft;

            if (c >= 0x20)
            {
                *p++ = c;
                continue;
            }

            *p++ = '\\';
            if (!nLeft)
            {
                break;
            }
            --nLeft;

            if (c == '\r')
            {
                *p++ = 'r';
            }
            else if (c == '\n')
            {
                *p++ = 'n';
            }
            else if (c == '\t')
            {
                *p++ = 't';
            }
            else
            {
                if (nLeft < 2)
                {
                    break;
                }
                *p++ = 'x';
                *p++ = ((c & 0xF0) < 0xA0) ? ((unsigned char)c >> 4) + '0' : ((unsigned char)c >> 4) + ('A' - 10);
                *p++ = ((c & 0x0F) < 0x0A) ? (c & 0x0F) + '0' : (c & 0x0F) + ('A' - 10);
                nLeft -= 2;
            }
        }

        if (cQuote && nLeft > 0)
        {
            *p++ = cQuote;
            --nLeft;
        }

        *p = 0;
        D2_ASSERT(nLeft >= 0, 0x100);
        D2_ASSERT(p - szDst + 1 <= nSize, 0x101);
    }

    return szDst;
}

// 0x00411540
char* __fastcall Int64ToString(char* szBuffer, unsigned int nBufferSize, __int64 nValue)
{
    char digits[32];
    if (nBufferSize > 32)
        nBufferSize = 32;
    char* pDigit = digits;
    unsigned int nGroup = 0;
    while (nValue)
    {
        if (pDigit >= digits + nBufferSize - 1)
        {
            memset(szBuffer, '*', nBufferSize - 1);
            szBuffer[nBufferSize - 1] = 0;
            return szBuffer;
        }
        *pDigit++ = (char)('0' + nValue % 10);
        nValue /= 10;
        ++nGroup;
        if (nGroup == 3 && nValue)
        {
            *pDigit++ = ',';
            nGroup = 0;
        }
    }
    char* pOut = szBuffer;
    while (pDigit >= digits)
        *pOut++ = *--pDigit;
    *pOut = 0;
    return szBuffer;
}

extern "C" const unsigned int gData_006CE268[32] = { // 0x006CE268
    0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000010, 0x00000020, 0x00000040, 0x00000080,
    0x00000100, 0x00000200, 0x00000400, 0x00000800, 0x00001000, 0x00002000, 0x00004000, 0x00008000,
    0x00010000, 0x00020000, 0x00040000, 0x00080000, 0x00100000, 0x00200000, 0x00400000, 0x00800000,
    0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000
};
#pragma comment(linker, "/alternatename:?gdwBitMasks@@3PAIA=_gData_006CE268")

extern "C" const unsigned int gData_006CE2E8[32] = { // 0x006CE2E8
    0xFFFFFFFE, 0xFFFFFFFD, 0xFFFFFFFB, 0xFFFFFFF7, 0xFFFFFFEF, 0xFFFFFFDF, 0xFFFFFFBF, 0xFFFFFF7F,
    0xFFFFFEFF, 0xFFFFFDFF, 0xFFFFFBFF, 0xFFFFF7FF, 0xFFFFEFFF, 0xFFFFDFFF, 0xFFFFBFFF, 0xFFFF7FFF,
    0xFFFEFFFF, 0xFFFDFFFF, 0xFFFBFFFF, 0xFFF7FFFF, 0xFFEFFFFF, 0xFFDFFFFF, 0xFFBFFFFF, 0xFF7FFFFF,
    0xFEFFFFFF, 0xFDFFFFFF, 0xFBFFFFFF, 0xF7FFFFFF, 0xEFFFFFFF, 0xDFFFFFFF, 0xBFFFFFFF, 0x7FFFFFFF
};
#pragma comment(linker, "/alternatename:?gdwInvBitMasks@@3PAIA=_gData_006CE2E8")

extern "C" const unsigned int gData_006CE368[9] = { // 0x006CE368
    0x00000000, 0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F, 0x0000003F, 0x0000007F,
    0x000000FF
};
#pragma comment(linker, "/alternatename:?gdwLowMasks_006CE368@@3PAIA=_gData_006CE368")

extern "C" const unsigned char gData_006CE38C[9] = { 0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00 }; // 0x006CE38C
#pragma comment(linker, "/alternatename:?gabOffsetMasks@@3QBEB=_gData_006CE38C")

extern "C" const int gData_006CE398[256] = { // 0x006CE398
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};
#pragma comment(linker, "/alternatename:?ganByteTable@@3PAHA=_gData_006CE398")

extern "C" const int gData_006CE798[256] = { // 0x006CE798
    -1, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};
#pragma comment(linker, "/alternatename:?ganLowBitTable@@3PAHA=_gData_006CE798")

extern "C" const char gData_006CEB98[256] = { // 0x006CEB98
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    '@', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', 127,
    -128, -127, -126, -125, -124, -123, -122, -121, -120, -119, -118, -117, -116, -115, -114, -113,
    -112, -111, -110, -109, -108, -107, -106, -105, -104, -103, -102, -101, -100, -99, -98, -97,
    -96, -95, -94, -93, -92, -91, -90, -89, -88, -87, -86, -85, -84, -83, -82, -81,
    -80, -79, -78, -77, -76, -75, -74, -73, -72, -71, -70, -69, -68, -67, -66, -65,
    -64, -63, -62, -61, -60, -59, -58, -57, -56, -55, -54, -53, -52, -51, -50, -49,
    -48, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33,
    -32, -31, -30, -29, -28, -27, -26, -25, -24, -23, -22, -21, -20, -19, -18, -17,
    -16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1
};
#pragma comment(linker, "/alternatename:?gszLowerTable@@3PADA=_gData_006CEB98")

extern "C" unsigned char gData_00708018[260] = { 0x44, 0x32 }; // 0x00708018
#pragma comment(linker, "/alternatename:?gszLogPrefix@@3PADA=_gData_00708018")

unsigned short gawStringCrcTable[256] = { // 0x00708140
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7, 0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6, 0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485, 0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4, 0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823, 0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12, 0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41, 0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70, 0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F, 0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E, 0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D, 0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C, 0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB, 0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A, 0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9, 0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8, 0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

int gbCallerFirst_00708340 = 1; // 0x00708340
