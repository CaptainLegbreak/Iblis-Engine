#include "D2CMP.h"
#include "D2GfxTypes.h"
#include "D2CmpTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define GetRValue(rgb) ((unsigned char)(rgb))

#define GetGValue(rgb) ((unsigned char)(((unsigned short)(rgb)) >> 8))

#define GetBValue(rgb) ((unsigned char)((rgb) >> 16))

struct D2CmpSubTileHeaderStrc;

struct D2CmpSubTileRecordStrc;

struct D2CmpColorStrc;

struct D2CmpTileBlockStrc;

struct D2RgbKeyStrc;

struct D2CmpRGBStrc;

struct D2CmpPaletteStrc;

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall CmpScanRun(unsigned char nValue, const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D310

int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D3A0

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

int __fastcall FOG_Free(void*, const char*, int, int); // 0x0040B3C0

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int); // 0x006829C0

unsigned char* __stdcall SubTileConvertPixels24To8(const unsigned char*, int, D2CmpColorStrc, D2CmpMapColorFn); // 0x0060D6F0

void __stdcall SubTilePackFloor(D2CmpSubTileRecordStrc*, const unsigned char*); // 0x0060D9C0

static void __stdcall SubTileCompressFloor(D2CmpSubTileRecordStrc* pDst, const unsigned char* pSrc);

static int SubTileHasTransparentPixel(const unsigned char* pData);

static void __stdcall SubTileConvertFloor24To8(D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap, D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc);

struct D2RgbKeyStrc { unsigned char bytes[4]; };

typedef char D2RgbKeyMustBeFourBytes[(sizeof(D2RgbKeyStrc) == 4) ? 1 : -1];

typedef unsigned char (__stdcall* D2PaletteFn)(unsigned char, unsigned char, unsigned char);

static unsigned char* __stdcall SubTileConvertPixels24To8(unsigned char* pPixels, int nBytes, D2RgbKeyStrc tKey, D2PaletteFn pConvert);

struct D2CmpPaletteStrc
{
    char unk0x00[0x10];
    D2CmpRGBStrc* pColors;
};

void __stdcall sub_M92_EmitSinkA(D2CmpSubTileRecordStrc* pRecord);

void __stdcall sub_M92_EmitSinkB(unsigned char* pData, D2CmpSubTileRecordStrc* pRecord);

struct D2CmpSubTileBlockStrc
{
    char unk0x00[0x08];
    short nValue08;
    short nSize;
    int unk0x0C;
    unsigned char* pData;
};



void __fastcall SubTileMapBlock(D2CmpTileBlockStrc* pSrc, D2CmpTileBlockStrc* pDst, D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap); // 0x0060DB60

// 0x0060D430
unsigned char* __fastcall SubTileCompress(const unsigned char* pData, unsigned int* pSize)
{
    unsigned char* pBuffer;
    unsigned char* pOut;
    unsigned int nRow;
    const unsigned char* pNextRow;
    const unsigned char* pEnd;
    unsigned int nOpaque;
    unsigned int nTransparent;
    int bRunEnd;
    int bRestEnd;
    unsigned int i;
    unsigned int nSize;

// build: symbol ?gszSubTileFile@* 0x006E61F8
    pBuffer = (unsigned char*)FOG_Alloc(0xC20, gszSubTileFile, 0x1C, 0);
    pOut = pBuffer;
    nRow = 0;
    pNextRow = pData + 32;
    pEnd = pData + 32;
    while (nRow < 32)
    {
        nTransparent = CmpScanRun(0, pData, pEnd, 127, &bRunEnd, &bRestEnd);
        pData += nTransparent;
        if (bRunEnd || bRestEnd)
        {
            *pOut++ = 0;
            *pOut++ = 0;
            pData = pNextRow;
            pNextRow += 32;
            pEnd += 32;
            ++nRow;
        }
        else if (nTransparent == 127)
        {
            *pOut++ = (unsigned char)nTransparent;
        }
        else
        {
            nOpaque = sub_0060D3A0_ScanOtherRun(pData, pEnd, 0, 127, &bRunEnd, &bRestEnd);
            *pOut++ = (unsigned char)nTransparent;
            *pOut++ = (unsigned char)nOpaque;
            for (i = 0; i < nOpaque; ++i)
            {
                *pOut++ = *pData++;
            }
            if (bRunEnd || bRestEnd)
            {
                *pOut++ = 0;
                *pOut++ = 0;
                pData = pNextRow;
                pNextRow += 32;
                pEnd += 32;
                ++nRow;
            }
        }
    }
    nSize = pOut - pBuffer;
    *pSize = nSize;
    return pBuffer;
}

// 0x0060D510
D2CmpSubTileRecordStrc* __fastcall SubTileCreateRecord(const void* pSrc, int bRaw)
{
    void* pData;
    int nSize;
    if (bRaw)
    {
        pData = FOG_Alloc(0xC00, szSubTileFile, 0x66, 0);
        memcpy(pData, pSrc, 0xC00);
        nSize = 0xC00;
    }
    else
    {
        int nLength;
        pData = sub_0060D430_Compress(pSrc, &nLength);
        nSize = nLength;
    }
    D2CmpSubTileRecordStrc* pRecord = (D2CmpSubTileRecordStrc*)FOG_Alloc(sizeof(D2CmpSubTileRecordStrc), szSubTileFile, 0x6E, 0);
    memset(pRecord, 0, sizeof(D2CmpSubTileRecordStrc));
    D2_ASSERT(nSize > 0xFFFF, 0x70);
    pRecord->ptData = (unsigned char*)pData;
    pRecord->nLength = (unsigned short)nSize;
    return pRecord;
}

// 0x0060D5B0
void __fastcall SubTileConvert24To8(D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc, D2CmpColorStrc bColor, D2CmpMapColorFn pfnMapColor)
{
    D2_ASSERT(pDst, 0x82);
    D2_ASSERT(pSrc, 0x83);
    D2_ASSERT(pSrc->ptData, 0x84);
    pDst->tHeader = pSrc->tHeader;
    pDst->tHeader.nFlags &= 0xFFFE;
    pDst->ptData = 0;
    pDst->tHeader.nLength = 0;
    int nCount = pSrc->tHeader.nLength / 3;
    D2_ASSERT(nCount, 0x8E);
    D2_ASSERT(nCount < 0x10000, 0x8F);
    pDst->ptData = (unsigned char*)FOG_Alloc(nCount, szSubTileFile, 0x90, 0);
    D2_ASSERT(pDst->ptData, 0x91);
    memset(pDst->ptData, 0, nCount);
    pDst->tHeader.nFlags |= 1;
    pDst->tHeader.nLength = (unsigned short)nCount;
    const unsigned char* pIn = pSrc->ptData;
    unsigned char* pOut = pDst->ptData;
    for (int i = 0; i < nCount; i++)
    {
        unsigned char nIndex = 0;
        if (pIn[0] != bColor.nRed || pIn[1] != bColor.nGreen || pIn[2] != bColor.nBlue)
        {
            nIndex = pfnMapColor(pIn[0], pIn[1], pIn[2]);
            D2_ASSERT(nIndex, 0xA1);
        }
        *pOut++ = nIndex;
        pIn += 3;
    }
}


// 0x0060D6F0
static unsigned char* __stdcall SubTileConvertPixels24To8(unsigned char* pPixels, int nBytes, D2RgbKeyStrc tKey, D2PaletteFn pConvert)
{
    const int nCount = nBytes / 3;
    unsigned char* pResult = (unsigned char*)FOG_Alloc(nCount, gszSubTileFile, 0xD8, 0);
    unsigned char* pBase = pResult;
    D2_ASSERT(pResult, 0xD9);
    memset(pResult, 0, nCount);
    int i = 0;
    if (nCount > 0)
    {
        do
        {
            unsigned char nColor;
            if (pPixels[i * 3] == tKey.bytes[0] && pPixels[i * 3 + 1] == tKey.bytes[1] && pPixels[i * 3 + 2] == tKey.bytes[2])
                nColor = 0;
            else
            {
                nColor = pConvert(pPixels[i * 3], pPixels[i * 3 + 1], pPixels[i * 3 + 2]);
                D2_ASSERT(nColor, 0xE4);
            }
            *pResult++ = nColor;
            ++i;
        } while (i < nCount);
        pResult = pBase;
    }
    return pResult;
}

// calling-convention shim (not game code)
unsigned char* __stdcall sub_0060D6F0_Shim(unsigned char* pPixels, int nBytes, unsigned int nKey, D2PaletteFn pConvert)
{
    D2RgbKeyStrc tKey = { { (unsigned char)nKey, (unsigned char)(nKey >> 8), (unsigned char)(nKey >> 16), (unsigned char)(nKey >> 24) } };
    return SubTileConvertPixels24To8(pPixels, nBytes, tKey, pConvert);
}

// 0x0060D7C0
int __fastcall SubTileIsEmpty(const unsigned char* pData)
{
    for (int i = 0; i < 0x200; ++i, ++pData)
    {
        if (*pData)
            return 0;
    }
    return 1;
}

// 0x0060D7E0
static int SubTileHasTransparentPixel(const unsigned char* pData)
{
    int y = 0;
    int nOffset = 14;
    int nWidth = 4;
    for (; y < 15; ++y)
    {
        for (int x = 0; x < nWidth; ++x)
        {
            if (pData[nOffset + x] == 0)
            {
                return 1;
            }
        }

        pData += 32;
        if (y < 7)
        {
            nOffset -= 2;
            nWidth += 4;
        }
        else
        {
            nOffset += 2;
            nWidth -= 4;
        }
    }

    return 0;
}

// 0x0060D840
static void __stdcall SubTileCompressFloor(D2CmpSubTileRecordStrc* pDst, const unsigned char* pSrc)
{
    int nSize;
    unsigned char* ptDestBuffer;
    unsigned char* pOut;
    unsigned int nRow;
    const unsigned char* pNextRow;
    const unsigned char* pEnd;
    int nOpaque;
    int nTransparent;
    int i;
    int bRunEnd;
    int bRestEnd;
    int nLength;
    unsigned char* ptNewData;

    nSize = 0x5AF;
    ptDestBuffer = (unsigned char*)FOG_Alloc(nSize, szTileCodecFile, 0x128, 0);
    D2_ASSERT(ptDestBuffer, 0x129);
    memset(ptDestBuffer, 0, nSize);
    pOut = ptDestBuffer;
    nRow = 0;
    pNextRow = pSrc + 32;
    pEnd = pSrc + 32;
    while (nRow < 15)
    {
        nTransparent = CmpScanRun(0, pSrc, pEnd, 0x7F, &bRunEnd, &bRestEnd);
        pSrc += nTransparent;
        if (bRunEnd || bRestEnd)
        {
            *pOut++ = 0;
            *pOut++ = 0;
            pSrc = pNextRow;
            pNextRow += 32;
            pEnd += 32;
            ++nRow;
        }
        else if (nTransparent == 0x7F)
        {
            *pOut++ = (unsigned char)nTransparent;
        }
        else
        {
            nOpaque = sub_0060D3A0_ScanOtherRun(pSrc, pEnd, 0, 0x7F, &bRunEnd, &bRestEnd);
            *pOut++ = (unsigned char)nTransparent;
            *pOut++ = (unsigned char)nOpaque;
            for (i = 0; i < nOpaque; ++i)
            {
                *pOut++ = *pSrc++;
            }
            if (bRunEnd || bRestEnd)
            {
                *pOut++ = 0;
                *pOut++ = 0;
                pSrc = pNextRow;
                pNextRow += 32;
                pEnd += 32;
                ++nRow;
            }
        }
    }
    nLength = pOut - ptDestBuffer;
    ptNewData = 0;
    nSize = nLength;
    D2_ASSERT(nSize < 0x10000, 0x166);
    ptNewData = (unsigned char*)FOG_Alloc(nSize, szTileCodecFile, 0x169, 0);
    D2_ASSERT(ptNewData, 0x16A);
    memset(ptNewData, 0, nSize);
    memcpy(ptNewData, ptDestBuffer, nSize);
    pDst->ptData = ptNewData;
    pDst->tHeader.nLength = (unsigned short)nSize;
    pDst->tHeader.nFlags |= 5;
    FOG_Free(ptDestBuffer, szTileCodecFile, 0x176, 0);
}

// 0x0060D9C0
void __stdcall SubTilePackFloor(D2CmpSubTileBlockStrc* pBlock, const unsigned char* pSrc)
{
    unsigned char* pDst = (unsigned char*)FOG_Alloc(0x100, szSubTileFile, 0x185, 0);
    D2_ASSERT(pDst, 0x186);
    unsigned char* pData = pDst;
    memset(pDst, 0, 0x100);
    int i = 0;
    int nOffset = 0xE;
    int nWidth = 4;
    for (; i < 15; i++)
    {
        memcpy(pDst, pSrc + nOffset, nWidth);
        pSrc += 0x20;
        pDst += nWidth;
        if (i < 7)
        {
            nOffset -= 2;
            nWidth += 4;
        }
        else
        {
            nOffset += 2;
            nWidth -= 4;
        }
    }
    pBlock->nValue08 = 1;
    pBlock->nSize = 0x100;
    pBlock->pData = pData;
}

static inline int SUBTILE_IsBlank(const unsigned char* pPixels)
{
    for (int i = 0; i < 0x200; ++i)
    {
        if (*pPixels)
        {
            return 0;
        }

        ++pPixels;
    }

    return 1;
}

// 0x0060DA80
static void __stdcall SubTileConvertFloor24To8(D2CmpColorStrc tColor, D2CmpMapColorFn pfnMap, D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc)
{
    unsigned char* pPixels = SubTileConvertPixels24To8(pSrc->ptData, pSrc->tHeader.nLength, tColor, pfnMap);

    if (SUBTILE_IsBlank(pPixels))
    {
        pDst->tHeader.nFlags = 0;
        pDst->tHeader.nLength = 0;
        pDst->ptData = 0;
        FOG_Free(pPixels, szTileCodecFile, 0x1B8, 0);
        return;
    }

    if (SubTileHasTransparentPixel(pPixels))
    {
        SubTileCompressFloor(pDst, pPixels);
    }
    else
    {
        SubTilePackFloor(pDst, pPixels);
    }

    FOG_Free(pPixels, szTileCodecFile, 0x1C7, 0);
}

void __fastcall sub_M92_Emit_0060D7E0(D2CmpSubTileRecordStrc* pRecord)
{
    unsigned char* pData = pRecord->ptData;
    if (SubTileHasTransparentPixel(pData))
    {
        sub_M92_EmitSinkA(pRecord);
    }
    else
    {
        sub_M92_EmitSinkB(pData, pRecord);
    }
}

// @ref 0x0060D7E0
static int sub_0060D7E0_HasTransparent(const unsigned char* pData)
{
    int nOffset = 14;
    int nWidth = 4;
    for (int nRow = 0; nRow < 15; ++nRow)
    {
        for (int nPixel = 0; nPixel < nWidth; ++nPixel)
            if (!pData[nOffset + nPixel])
                return 1;
        pData += 32;
        if (nRow < 7)
        {
            nOffset -= 2;
            nWidth += 4;
        }
        else
        {
            nOffset += 2;
            nWidth -= 4;
        }
    }
    return 0;
}

// 0x0060DB20
void __fastcall SubTileEncodeFloor(D2CmpSubTileRecordStrc* pRecord)
{
    unsigned char* pData = pRecord->ptData;
    if (sub_0060D7E0_HasTransparent(pData))
        SubTileCompressFloor(pRecord, pData);
    else
        SubTilePackFloor(pRecord, pData);
    FOG_Free(pData, szTileCodecFile, 0x1DE, 0);
}

// 0x0060DB60
void __fastcall SubTileMapBlock(D2CmpTileBlockStrc* ptTile24, D2CmpTileBlockStrc* ptTile8, D2CmpColorStrc tColor, D2CmpMapColorFn pfnQuantize)
{
    D2_ASSERT(ptTile24, 0x1EC);
    D2_ASSERT(ptTile8, 0x1ED);
    D2_ASSERT(pfnQuantize, 0x1EE);
    D2_ASSERT(ptTile24->nFlags & 8, 0x1EF);

    for (int i = 0; i < ptTile24->nSubs; ++i)
    {
        D2CmpSubTileRecordStrc* pDst = &ptTile8->pSubs[i];
        const D2CmpSubTileRecordStrc* pSrc = &ptTile24->pSubs[i];

        *pDst = *pSrc;
        pDst->ptData = 0;
        if (pSrc->ptData)
        {
            SubTileConvertFloor24To8(tColor, pfnQuantize, pDst, pSrc);
            if (pDst->tHeader.nFlags & 4)
            {
                ptTile8->nFlags |= 0x10;
            }
        }
    }
}

// 0x0060DC30
void __fastcall SubTileIteratePixels(D2CmpPaletteStrc* pPalette, D2CmpColorCallback pfnColor)
{
    D2CmpRGBStrc* pColor = pPalette->pColors;
    for (int i = 0; i < 0x400; i++)
    {
        pfnColor(((pColor->b2 << 8) + pColor->b1 << 8) + pColor->b0);
        pColor++;
    }
}
