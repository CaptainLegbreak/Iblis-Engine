#include "Fog.h"
#include "D2StormLink.h"
#include "D2GameTypes.h"
#include "D2Primitives.h"
#include "D2StormTypes.h"
#include "D2NetTypes.h"
#include "D2FogTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct D2LogMsgListStrc;

struct D2LogMsgListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* sub_0040FF40_NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags); // 0x0040FF40
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

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

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern unsigned int gdwLowMasks_006CE368[]; // 0x006CE368

unsigned int __stdcall sub_00410F60_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00410F60

struct D2TimedRecordStrc
{
    char unk0x00[0x08];
    __int64 qwValue;
    char unk0x10[0x08];
};

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency); // 0x006CC254

D2TimedRecordStrc gaTimerTable_0075E8A0[0x1000]; // 0x0075E8A0

int gnTimerTicksPerMs_0075E89C; // 0x0075E89C

int gnTimerTicksPerUs_0075E898; // 0x0075E898

unsigned int gnRecordCount_007768A4; // 0x007768A4

int gnTickAtReset_007768A0; // 0x007768A0

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

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

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return BNSEND_NibbleToHex(tolower(n)) + BNSEND_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return BNSEND_HexToNibble((char)tolower(n)) * 16 + BNSEND_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return BNSEND_MapKeyChar((unsigned char)tolower(n)) * 24 + BNSEND_MapKeyChar((unsigned char)tolower(n + 1));
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
        *pBuffer->pBuffer |= (unsigned char)(gdwLowMasks_006CE368[n] & nValue) << pBuffer->nPosBits;
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

            dwValue += (gdwLowMasks_006CE368[i] & ((unsigned char)(*pBuffer->pBuffer & gabOffsetMasks[nPosBits]) >> nPosBits)) << dw;
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
    gnTimerTicksPerMs_0075E89C = (int)(nFrequency / 1000);
    gnTimerTicksPerUs_0075E898 = (int)(nFrequency / 1000000);
    memset(gaTimerTable_0075E8A0, 0, sizeof(gaTimerTable_0075E8A0));
    gnTickAtReset_007768A0 = GetTickCount();
}

// 0x00411280
void __cdecl sub_00411280_ResetRecords()
{
    for (unsigned int i = 0; i < gnRecordCount_007768A4; ++i)
    {
        gaTimerTable_0075E8A0[i].qwValue = 0;
    }
    gnTickAtReset_007768A0 = GetTickCount();
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

#include "gen/data/Source/Fog/Unknown_00410790.inc"
