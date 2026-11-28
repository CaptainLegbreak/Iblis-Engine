#include "D2CMP.h"

#include "D2CmpTypes.h"

#include "D2CmpCache.h"

#include "D2GameTypes.h"

#include "D2CmpTiles.h"
#include "FogApi.h"
#include "FogApi.h"
#include "FogApi2.h"

struct D2PoolSystemStrc;
static int DccTestBit(const unsigned int* pBits, int nBit);

static unsigned int __stdcall CodecReadBits(int nNumBits, D2CmpBitCursorStrc* pBitState); // 0x0060B200

static int CodecDccFirstCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt); // 0x0060B480

struct D2CmpBitCursorStrc;

struct D2CmpByteMapStrc;

struct D2CmpByteRunStrc;

struct D2DccFrameStrc;

struct D2DccDirStrc;

struct D2DccIterStrc;

struct D2SpritePixelsStrc;

struct D2SpriteCelStrc;

struct D2CmpTileFileHeaderStrc;

struct D2CmpTileHeaderTargetStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2SpritePixelsStrc { int unknown00,width,height; char unknown0C[0x14]; unsigned char* pixels; int pitch; int topDown; };

struct D2SpriteCelStrc { int unknown00[7]; unsigned int dataSize; };


void* __cdecl sub_006829C0_Copy(void* dest,const void* source,unsigned int size); // 0x006829C0

#pragma pack(push, 1)

struct D2CmpTileFileHeaderStrc
{
    unsigned char nType;
    unsigned char nByte1;
    unsigned char nCount;
    int nDword3;
    int nDword7;
    int nUnk0x0B;
};

#pragma pack(pop)

struct D2CmpTileHeaderTargetStrc
{
    unsigned char bFlags;
    char pad0x01[3];
    int nByte1;
    int nDword7;
    int nZero0C;
    int f_10;
    int nCount;
    int nDword3;
    unsigned int adwData[33];
};


static int CodecDccNextCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt); // 0x0060B2B0




extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC214


int __fastcall CodecEncodeSprite(D2DccFrameStrc* pFrame, D2Dc6FrameStrc* pHeader, unsigned char* pDst); // 0x0060BDB0

extern D2CriticalSectionStrc gtCodecLock;                                                          // 0x008F03CC

extern unsigned char gabDccPixels[];                                                               // 0x008F03E8

extern unsigned char gabDccRunBuffer[];                                                            // 0x0090D8A8

extern D2DccCellStrc gatDccCells[5625];                                                             // 0x0094D8A8

extern D2DccFrameStrc gatDccFrames[];                                                               // 0x00969020

extern const int ganDccFieldWidths[16];                                                             // 0x006E5F70

extern const unsigned int gadwDccSignBits[32];                                                      // 0x006E5FB0

extern const unsigned int gadwDccSignExtend[33];                                                    // 0x006E60B8

extern "C" const unsigned int gData_006E6030[33]; // 0x006E6030


void __stdcall CodecDccDecodeCells(D2DccDirStrc* pDir, D2DccCellStrc* pCells, D2CmpBitCursorStrc* pEqual, D2CmpBitCursorStrc* pMask, D2CmpBitCursorStrc* pEncoding, D2CmpBitCursorStrc* pRaw, D2CmpBitCursorStrc* pCode, D2CmpByteRunStrc* pRun, int* pnBitsUsed); // 0x0060B9A0

static inline int DccGetBitPos(D2CmpBitCursorStrc* pCursor)
{
    return (int)(pCursor->pData - pCursor->pStart) * 32 + pCursor->nBitPos;
}

// 0x0060B200
static unsigned int __stdcall CodecReadBits(int nNumBits, D2CmpBitCursorStrc* pBitState)
{
    if (!nNumBits)
        return 0;

    const int nRemain = 32 - pBitState->nBitPos;
    unsigned int nBits;
    if (nNumBits <= nRemain)
    {
        nBits = gData_006E6030[nNumBits] & (*pBitState->pData >> pBitState->nBitPos);
        pBitState->nBitPos += nNumBits;
        if (pBitState->nBitPos == 32)
        {
            ++pBitState->pData;
            pBitState->nBitPos = 0;
        }
    }
    else
    {
        nBits = gData_006E6030[nRemain] & (*pBitState->pData++ >> pBitState->nBitPos);
        pBitState->nBitPos = nNumBits - nRemain;
        nBits |= (gData_006E6030[pBitState->nBitPos] & *pBitState->pData) << nRemain;
    }
    return nBits;
}

extern unsigned int gaCodecBitWidthTable_006E5F70[48]; // 0x006E5F70

extern unsigned int gaCodecSignExtendTable_006E60B8[32]; // 0x006E60B8

static unsigned int __fastcall CodecReadBitsSigned(int nBitWidthCode, D2CmpBitCursorStrc* pBitState, int bSigned); // 0x0060B280

// 0x0060B280
static unsigned int __fastcall CodecReadBitsSigned(int nBitWidthCode, D2CmpBitCursorStrc* pBitState, int bSigned)
{
    const int nNumBits = gaCodecBitWidthTable_006E5F70[nBitWidthCode];
    unsigned int nBitsRead = CodecReadBits(nNumBits, pBitState);
    if (nNumBits && bSigned && (gaCodecBitWidthTable_006E5F70[nNumBits + 15] & nBitsRead))
        nBitsRead |= gaCodecSignExtendTable_006E60B8[nNumBits];

    return nBitsRead;
}

// calling-convention shim (not game code)
unsigned int __fastcall sub_0060B280_Shim(int nBitWidthCode, D2CmpBitCursorStrc* pBitState, int bSigned)
{
    return CodecReadBitsSigned(nBitWidthCode, pBitState, bSigned);
}

struct D2DccDirIndexStrc
{
    int nDir;
};

// 0x0060B2B0
static int CodecDccNextCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt)
{
    pIt->nX += pIt->nStepX;
    if (pIt->nX < pIt->nWidth)
    {
        pIt->nPixel += pIt->nStepX;
        ++pIt->nCell;
        pIt->nStepX = pIt->nX + 5 < pIt->nWidth ? 4 : pIt->nWidth - pIt->nX;
        return 1;
    }

    pIt->nY += pIt->nStepY;
    if (pIt->nY < pIt->nHeight)
    {
        const int nRemX = -(pIt->nX0 % 4);
        pIt->nX = 0;
        pIt->nStepX = nRemX + 5 < pIt->nWidth ? nRemX + 4 : pIt->nWidth;
        pIt->nPixelRow += pIt->nCellsY * pIt->nStepY;
        pIt->nPixel = pIt->nPixelRow;
        pIt->nCellRow += pDir->nCellsPerRow;
        pIt->nCell = pIt->nCellRow;
        pIt->nStepY = pIt->nY + 5 < pIt->nHeight ? 4 : pIt->nHeight - pIt->nY;
        return 1;
    }

    ++pIt->nFrame;
    D2DccFrameStrc* pFrame = &pDir->pFrames[pIt->nFrame];
    for (; pIt->nFrame < pDir->nFrames; ++pIt->nFrame, ++pFrame)
    {
        if (pFrame->nWidth && pFrame->nHeight)
        {
            pIt->nWidth = pFrame->nWidth;
            pIt->nHeight = pFrame->nHeight;
            pIt->nX0 = pFrame->nXOffset - pDir->nMinX;
            pIt->nY0 = pFrame->nYOffset - pDir->nMinY - (pFrame->bBottomUp ? 0 : pFrame->nHeight);
            pIt->nCellsX = pFrame->nCellsX;
            pIt->nCellsY = pFrame->nCellsY;
            pIt->nCellRow = pIt->nY0 / 4 * pDir->nCellsPerRow + pIt->nX0 / 4;
            pIt->nCell = pIt->nCellRow;
            pIt->nX = 0;
            pIt->nY = 0;
            pIt->nPixelRow = 0;
            pIt->nPixel = 0;
            const int nRemX = -(pIt->nX0 % 4);
            const int nRemY = -(pIt->nY0 % 4);
            pIt->nStepX = nRemX + 5 < pIt->nWidth ? nRemX + 4 : pIt->nWidth;
            pIt->nStepY = nRemY + 5 < pIt->nHeight ? nRemY + 4 : pIt->nHeight;
            return 1;
        }
    }

    return 0;
}

// 0x0060B480
static inline int CodecDccFirstCell(D2DccDirStrc* pDir, D2DccIterStrc* pIt)
{
    if (!pDir->nFrames)
    {
        return 0;
    }
    memset(pIt, 0, sizeof(*pIt));
    pIt->nFrame = -1;
    return CodecDccNextCell(pDir, pIt);
}

// 0x0060B4B0
static void CodecDccCountCells(D2DccDirStrc* pDir)
{
    const int nCellsX = (pDir->nBoxWidth + 3) / 4;
    const int nCellsY = (pDir->nBoxHeight + 3) / 4;
    pDir->nCellsPerRow = nCellsX;
    pDir->nCellsTotal = nCellsY * nCellsX;
    pDir->nCells = 0;
    if (pDir->nFrames)
    {
        D2DccIterStrc iter;
        memset(&iter, 0, sizeof(iter));
        iter.nFrame = -1;
        if (CodecDccNextCell(pDir, &iter))
        {
            do
            {
                ++pDir->nCells;
            }
            while (CodecDccNextCell(pDir, &iter));
        }
    }
}

// 0x0060B530
static void __stdcall CodecDccInitDir(D2DccHeaderStrc* pHeader, D2DccFrameStrc* pFrames, D2DccDirStrc* pDir, D2DccDirIndexStrc tDirIndex)
{
    pDir->pHeader = pHeader;
    pDir->pFrames = pFrames;
    pDir->nFrames = pHeader->nFrames;
    pDir->nDir = tDirIndex.nDir;

    int nMinX = 0x7FFFFFFF;
    int nMaxX = (int)0x80000000;
    int nMinY = 0x7FFFFFFF;
    int nMaxY = (int)0x80000000;

    D2DccFrameStrc* pEnd = &pFrames[pDir->nFrames];
    for (D2DccFrameStrc* pFrame = pFrames; pFrame < pEnd; ++pFrame)
    {
        int nX = pFrame->nXOffset;
        int nY = pFrame->nYOffset - (pFrame->bBottomUp ? 0 : pFrame->nHeight);
        if (nX < nMinX)
        {
            nMinX = nX;
        }
        if (nX + pFrame->nWidth > nMaxX)
        {
            nMaxX = nX + pFrame->nWidth;
        }
        if (nY < nMinY)
        {
            nMinY = nY;
        }
        if (nY + pFrame->nHeight > nMaxY)
        {
            nMaxY = nY + pFrame->nHeight;
        }
    }

    pDir->nMinY = nMinY;
    pDir->nMinX = nMinX;
    pDir->nBoxWidth = nMaxX - nMinX;
    pDir->nBoxHeight = nMaxY - nMinY;
}

struct D2CmpByteMapArgStrc
{
    D2CmpByteMapStrc* p;
};

// 0x0060B5F0
static void __stdcall CodecBuildColorMaps(D2CmpByteMapArgStrc tInverse, const unsigned char* pFlags, D2CmpByteMapStrc* pForward)
{
    int i;
    int n;
    for (i = 0, n = 0; i < 0x100; ++i)
    {
        if (pFlags[i])
        {
            pForward->ab[i] = (unsigned char)n;
            tInverse.p->ab[n] = (unsigned char)i;
            ++n;
        }
    }
    pForward->nCount = 0x100;
    tInverse.p->nCount = n;
}

// 0x0060B640
static void __fastcall CodecBuildColorMapsFromBits(D2CmpByteMapStrc* pForward, const unsigned int* pBits, D2CmpByteMapStrc* pInverse)
{
    unsigned char abFlags[0x100];
    for (int i = 0; i < 0x100; ++i)
    {
        abFlags[i] = (pBits[i >> 5] & gdwBitMasks_006CE268[i & 0x1F]) != 0;
    }
    CodecBuildColorMaps(*(D2CmpByteMapArgStrc*)&pInverse, abFlags, pForward);
}

// 0x0060B780
static inline int CodecGetRunBits(const unsigned char* pBytes)
{
    int nBits;
    for (nBits = 0; (1 << nBits) + 1 <= 4 && pBytes[1 << nBits] != pBytes[(1 << nBits) - 1]; ++nBits)
    {
    }
    return nBits;
}

// 0x0060B9A0
void __stdcall CodecDccDecodeCells(D2DccDirStrc* pDir, D2DccCellStrc* pCells, D2CmpBitCursorStrc* pEqual, D2CmpBitCursorStrc* pMask, D2CmpBitCursorStrc* pEncoding, D2CmpBitCursorStrc* pRaw, D2CmpBitCursorStrc* pCode, D2CmpByteRunStrc* pRun, int* pnBitsUsed)
{
    D2DccIterStrc tIt;
    unsigned char* pData = pRun->pData;
    const int nStart = DccGetBitPos(pCode);
    if (CodecDccFirstCell(pDir, &tIt))
    {
        do
        {
            unsigned int dwMask = 0xF;
            unsigned char* pPrev = pCells[tIt.nCell].pColors;
            if (pPrev)
            {
                if (pEqual && CodecReadBits(1, pEqual))
                {
                    continue;
                }
                dwMask = CodecReadBits(4, pMask);
            }

            int bRaw = 0;
            if (dwMask && pEncoding)
            {
                bRaw = CodecReadBits(1, pEncoding);
            }

            dwMask |= 0xFFFFFFF0;
            int i = 4;
            unsigned char nLast = 0;
            while (i--)
            {
                if (DccTestBit(&dwMask, i))
                {
                    unsigned char nColor;
                    if (bRaw)
                    {
                        nColor = (unsigned char)CodecReadBits(8, pRaw);
                        pData[i] = nColor;
                    }
                    else
                    {
                        nColor = nLast;
                        unsigned int nStep = 0xF;
                        while (nStep == 0xF)
                        {
                            nStep = CodecReadBits(4, pCode);
                            nColor += nStep;
                        }
                        pData[i] = nColor;
                    }

                    if (nLast == nColor)
                    {
                        int nSrc = i;
                        int nDst = -1;
                        for (;;)
                        {
                            ++nSrc;
                            while (!DccTestBit(&dwMask, nSrc))
                            {
                                ++nSrc;
                            }
                            if (nSrc >= 4)
                            {
                                break;
                            }
                            ++nDst;
                            while (!DccTestBit(&dwMask, nDst))
                            {
                                ++nDst;
                            }
                            pData[nDst] = pData[nSrc];
                        }
                        for (;;)
                        {
                            ++nDst;
                            while (!DccTestBit(&dwMask, nDst))
                            {
                                ++nDst;
                            }
                            if (nDst >= 4)
                            {
                                break;
                            }
                            pData[nDst] = 0;
                        }
                        while (i--)
                        {
                            if (!DccTestBit(&dwMask, i))
                            {
                                pData[i] = pPrev[i];
                            }
                        }
                        break;
                    }
                    nLast = nColor;
                }
                else
                {
                    pData[i] = pPrev[i];
                }
            }

            pCells[tIt.nCell].pColors = pData;
            pData += 4;
        }
        while (CodecDccNextCell(pDir, &tIt));
    }
    *pnBitsUsed = DccGetBitPos(pCode) - nStart;
    pRun->nCount = (int)(pData - pRun->pData);
}

// 0x0060BD90
static inline void CodecRemapRun(D2CmpByteRunStrc* pRun, const unsigned char* pTable)
{
    for (int i = 0; i < pRun->nCount; ++i)
    {
        pRun->pData[i] = pTable[pRun->pData[i]];
    }
}

// emits the static RemapRun (not game code)
void sub_M123_Emit_0060BD90(D2CmpByteRunStrc* pRun, const unsigned char* pTable)
{
    CodecRemapRun(pRun, pTable);
}

// 0x0060BDB0
int __fastcall CodecEncodeSprite(D2SpritePixelsStrc* sprite,D2SpriteCelStrc* cel,unsigned char* output)
{
 unsigned char* dest=output;
 unsigned char* row=sprite->pixels;
 int y;
 int step=sprite->topDown?sprite->pitch:-sprite->pitch;
 if(!sprite->topDown) row+=(sprite->height-1)*sprite->pitch;
 for(y=0;y<sprite->height;) {
  int x=0;
  while(x<sprite->width) {
   int start=x;
   while(x<sprite->width && !row[x]) ++x;
   if(x>=sprite->width) break;
   if(x>start) do {
    int count=x-start;
    if(count>127) count=127;
    *dest++=(unsigned char)(count|0x80);
    start+=count;
   } while(start<x);
   start=x;
   while(x<sprite->width && row[x]) ++x;
   if(x>start) do {
    int count=x-start;
    if(count>127) count=127;
    *dest++=(unsigned char)count;
    sub_006829C0_Copy(dest,row+start,count);
    dest+=count;
    start+=count;
   } while(start<x);
  }
  *dest++=0x80;
  ++y;
  row+=step;
 }
 if(dest!=(unsigned char*)cel+32+cel->dataSize) {
  LOGMANAGER_WriteLogLine("Sprite Decompression Error");
  return 0;
 }
 return 1;
}

// 0x0060BF20
int __fastcall CodecLoadTileHeader(const char* szFile, D2CmpTileHeaderTargetStrc* pTarget)
{
    void* hFile;
    FOG_FOpenFile(szFile, &hFile);
    if (!hFile)
    {
        return 0;
    }

    D2CmpTileFileHeaderStrc tHeader;
    int nRead;
    int bLoaded = 0;
    if (FOG_FReadFile(hFile, &tHeader, sizeof(tHeader), &nRead, 0, 0, 0) && nRead == sizeof(tHeader) && tHeader.nType == 't')
    {
        pTarget->nByte1 = tHeader.nByte1;
        pTarget->nDword7 = tHeader.nDword7;
        pTarget->nZero0C = 0;
        pTarget->nCount = tHeader.nCount;
        pTarget->nDword3 = tHeader.nDword3;
        if (tHeader.nCount > 32)
        {
            tHeader.nCount = 32;
        }

        const int nSize = tHeader.nCount * sizeof(unsigned int);
        if (FOG_FReadFile(hFile, pTarget->adwData, nSize, &nRead, 0, 0, 0) && nRead == nSize)
        {
            bLoaded = 1;
        }
    }

    if (!bLoaded)
    {
        FOG_FCloseFile(hFile);
        return 0;
    }

    pTarget->adwData[tHeader.nCount] = FOG_FGetFileSize(hFile, 0);
    FOG_FCloseFile(hFile);
    pTarget->bFlags |= 2;
    return 1;
}

static inline unsigned int DccReadBits(D2CmpBitCursorStrc* pCursor, int nCount)
{
    unsigned int nValue;
    const int nLeft = 32 - pCursor->nBitPos;
    if (nLeft >= nCount)
    {
        nValue = (*pCursor->pData >> pCursor->nBitPos) & gData_006E6030[nCount];
        pCursor->nBitPos += nCount;
        if (pCursor->nBitPos == 32)
        {
            ++pCursor->pData;
            pCursor->nBitPos = 0;
        }
    }
    else
    {
        nValue = (*pCursor->pData >> pCursor->nBitPos) & gData_006E6030[nLeft];
        ++pCursor->pData;
        pCursor->nBitPos = nCount - nLeft;
        nValue |= (*pCursor->pData & gData_006E6030[pCursor->nBitPos]) << nLeft;
    }
    return nValue;
}

static inline int DccReadSigned(int nCount, D2CmpBitCursorStrc* pCursor)
{
    int nValue = CodecReadBits(nCount, pCursor);
    if (nCount && (nValue & gadwDccSignBits[nCount - 1]))
    {
        nValue |= gadwDccSignExtend[nCount];
    }
    return nValue;
}

// 0x0060B7B0
static void __stdcall CODEC_DecodeCell(D2CmpBitCursorStrc* pCursor, D2CmpBitCursorStrc* pEqual, D2DccCellStrc* pPrev, D2DccCellStrc* pCell, unsigned char** ppRun)
{
    if (pEqual && pPrev->pColors && CodecReadBits(1, pEqual))
    {
        if (pCell->nWidth == pPrev->nWidth && pCell->nHeight == pPrev->nHeight)
        {
            if (pCell->pDst != pPrev->pDst)
            {
                unsigned char abTemp[5][5];
                unsigned char* pSrc = pPrev->pDst;
                unsigned char* pTempIn = abTemp[0];
                for (int y = 0; y < pCell->nHeight; ++y)
                {
                    memcpy(pTempIn, pSrc, pCell->nWidth);
                    pTempIn += 5;
                    pSrc += pPrev->nPitch;
                }

                unsigned char* pDst = pCell->pDst;
                const unsigned char* pTempOut = abTemp[0];
                for (int y = 0; y < pCell->nHeight; ++y, pTempOut += 5)
                {
                    memcpy(pDst, pTempOut, pCell->nWidth);
                    pDst += pCell->nPitch;
                }
            }
        }
        else
        {
            unsigned char* pDst = pCell->pDst;
            for (int y = 0; y < pCell->nHeight; ++y)
            {
                memset(pDst, 0, pCell->nWidth);
                pDst += pCell->nPitch;
            }
        }
        return;
    }

    unsigned char* pRow = pCell->pDst;
    const int nBits = CodecGetRunBits(pCell->pColors);
    if (!nBits)
    {
        const int nColor = **ppRun;
        for (int y = 0; y < pCell->nHeight; ++y)
        {
            memset(pRow, nColor, pCell->nWidth);
            pRow += pCell->nPitch;
        }
    }
    else
    {
        for (int y = 0; y < pCell->nHeight; ++y)
        {
            for (int x = 0; x < pCell->nWidth; ++x)
            {
                pRow[x] = (*ppRun)[CodecReadBits(nBits, pCursor)];
            }
            pRow += pCell->nPitch;
        }
    }
    *ppRun += 4;
}

static inline int DccTestBit(const unsigned int* pBits, int nBit)
{
    return pBits[nBit >> 5] & gdwBitMasks_006CE268[nBit & 0x1F];
}

static inline const D2DccFileStrc* DccGetFile(unsigned int dwFile)
{
    return (const D2DccFileStrc*)dwFile;
}

static inline void DccCopyHeader(D2DccHeaderStrc* pHeader, const D2DccFileStrc* pFile)
{
    pHeader->n04 = pFile->n04;
    pHeader->n14 = pFile->n14;
    pHeader->nFrames = pFile->nFrames;
    pHeader->n08 = pFile->n08;
}

static inline void __stdcall sub_0060B140_BitBufferInit(int nSize, unsigned int* pBuffer, D2CmpBitCursorStrc* pBitBuf)
{
    pBitBuf->pStart = pBuffer;
    pBitBuf->pData = pBuffer;
    pBitBuf->nBits = nSize * 8;
    pBitBuf->nBitPos = 0;
}

// 0x0060BFF0
int __fastcall CodecDecodeDccData(unsigned char* pData, D2PoolSystemStrc* pMemPool, int nSize, unsigned int dwFile, D2DccOutTableStrc* pTable, int nFirstDir, int nDirs, int* pnOutSize, const char* szFile)
{
    D2CmpBitCursorStrc tCursor;
    D2CmpBitCursorStrc tEqual;
    D2CmpByteRunStrc tRun;
    D2DccDirStrc tDir;
    D2DccHeaderStrc tHeader;
    D2CmpBitCursorStrc tEqual1;
    D2CmpBitCursorStrc tEncoding;
    D2CmpBitCursorStrc tMask;
    D2CmpBitCursorStrc tRaw;
    D2CmpBitCursorStrc tCode;
    D2DccIterStrc tIt;
    D2CmpByteMapStrc tInverse;

    EnterCriticalSection(&gtCodecLock);

    DccCopyHeader(&tHeader, DccGetFile(dwFile));
    sub_0060B140_BitBufferInit(nSize, (unsigned int*)pData, &tCursor);

    *pnOutSize = 0;
    const int nEnd = nFirstDir + nDirs;
    for (int i = nFirstDir; i < nEnd; ++i)
    {
        const int nDirSize = *(int*)(pData - DccGetFile(dwFile)->dwDirOffsets[nFirstDir] + DccGetFile(dwFile)->dwDirOffsets[i]);
        pTable->dwDirOffsets[i] = *pnOutSize;
        *pnOutSize += nDirSize;
    }

    unsigned char* pResult = (unsigned char*)FOG_AllocPool(pMemPool, *pnOutSize, ".\\SRC\\Codec.cpp", 0x561, 0);
    unsigned char* pOut = pResult;
    for (int nDir = nFirstDir; nDir < nEnd; ++nDir)
    {
        DccReadBits(&tCursor, 32);
        const int nFlags = DccReadBits(&tCursor, 2);
        const unsigned int nWidths = DccReadBits(&tCursor, 28);
        D2DccFrameStrc* pFramesEnd = &gatDccFrames[tHeader.nFrames];
        const int nVar0Bits = nWidths & 0xF;
        const int nWidthBits = (nWidths >> 4) & 0xF;
        const int nHeightBits = (nWidths >> 8) & 0xF;
        const int nXBits = (nWidths >> 12) & 0xF;
        const int nYBits = (nWidths >> 16) & 0xF;
        const int nOptBits = (nWidths >> 20) & 0xF;
        const int nCodedBits = (nWidths >> 24) & 0xF;

        int nOptSum = 0;
        D2DccFrameStrc* pFrame;
        for (pFrame = gatDccFrames; pFrame < pFramesEnd; ++pFrame)
        {
            pFrame->nVar0 = CodecReadBits(ganDccFieldWidths[nVar0Bits], &tCursor);
            pFrame->nWidth = CodecReadBits(ganDccFieldWidths[nWidthBits], &tCursor);
            pFrame->nHeight = CodecReadBits(ganDccFieldWidths[nHeightBits], &tCursor);
            pFrame->nXOffset = DccReadSigned(ganDccFieldWidths[nXBits], &tCursor);
            pFrame->nYOffset = DccReadSigned(ganDccFieldWidths[nYBits], &tCursor);
            const int nOpt = CodecReadBits(ganDccFieldWidths[nOptBits], &tCursor);
            pFrame->nOptBytes = nOpt;
            pFrame->pOptData = 0;
            pFrame->nCodedBytes = CodecReadBits(ganDccFieldWidths[nCodedBits], &tCursor);
            pFrame->nCellsX = 0;
            pFrame->nCellsY = 0;
            pFrame->bBottomUp = DccReadBits(&tCursor, 1);
            nOptSum += nOpt;
        }

        if (nOptSum)
        {
            tCursor.AlignToByte();
            unsigned char* pOpt = tCursor.GetBytePtr();
            for (D2DccFrameStrc* pOptFrame = gatDccFrames; pOptFrame < pFramesEnd; ++pOptFrame)
            {
                if (pOptFrame->nOptBytes)
                {
                    pOptFrame->pOptData = pOpt;
                    pOpt += pOptFrame->nOptBytes;
                }
            }
            tCursor.AdvanceBits(nOptSum * 8);
        }

        CodecDccInitDir(&tHeader, gatDccFrames, &tDir, *(D2DccDirIndexStrc*)&nDir);
        CodecDccCountCells(&tDir);
        memset(gatDccCells, 0, tDir.nCellsTotal * sizeof(D2DccCellStrc));

        int nEqualSize = 0;
        int nEncodingSize = 0;
        int nRawSize = 0;
        if (nFlags & 2)
        {
            nEqualSize = DccReadBits(&tCursor, 20);
        }
        const int nMaskSize = DccReadBits(&tCursor, 20);
        if (nFlags & 1)
        {
            nEncodingSize = DccReadBits(&tCursor, 20);
            nRawSize = DccReadBits(&tCursor, 20);
        }

        {
            unsigned int adwColors[8];
            for (int j = 0; j < 8; ++j)
            {
                adwColors[j] = DccReadBits(&tCursor, 32);
            }
            D2CmpByteMapStrc tForward;
            CodecBuildColorMapsFromBits(&tForward, adwColors, &tInverse);
        }

        tEqual = tCursor;
        tCursor.AdvanceBits(nEqualSize);
        tMask = tCursor;
        tCursor.AdvanceBits(nMaskSize);
        tEncoding = tCursor;
        tCursor.AdvanceBits(nEncodingSize);
        tRaw = tCursor;
        tCursor.AdvanceBits(nRawSize);
        tCode = tCursor;

        {
            int nBitsUsed = 0;
            tRun.pData = gabDccRunBuffer;
            tRun.nCount = 0;
            tEqual1 = tEqual;
            CodecDccDecodeCells(&tDir, gatDccCells, nEqualSize ? &tEqual1 : 0, &tMask, nEncodingSize ? &tEncoding : 0, nRawSize ? &tRaw : 0, &tCode, &tRun, &nBitsUsed);
            tCursor.AdvanceBits(nBitsUsed);
        }

        for (int k = 0; k < tRun.nCount; ++k)
        {
            tRun.pData[k] = tInverse.ab[tRun.pData[k]];
        }

        for (D2DccFrameStrc* pPosFrame = gatDccFrames; pPosFrame < pFramesEnd; ++pPosFrame)
        {
            const int nX = pPosFrame->nXOffset - tDir.nMinX;
            const int nY = pPosFrame->nYOffset - (pPosFrame->bBottomUp ? 0 : pPosFrame->nHeight) - tDir.nMinY;
            pPosFrame->nCellsX = (int)&gabDccPixels[nY * tDir.nBoxWidth + nX];
            pPosFrame->nCellsY = tDir.nBoxWidth;
        }

        {
            unsigned char* pRun = tRun.pData;
            if (CodecDccFirstCell(&tDir, &tIt))
            {
                int nPrevFrame = 0;
                memset(gatDccCells, 0, sizeof(gatDccCells));
                D2CmpBitCursorStrc* pEqual = nEqualSize ? &tEqual : 0;
                int bMore;
                do
                {
                    D2DccCellStrc tCell;
                    tCell.pColors = pRun;
                    tCell.pDst = (unsigned char*)(tIt.nCellsX + tIt.nPixel);
                    tCell.nPitch = tIt.nCellsY;
                    tCell.nWidth = tIt.nStepX;
                    tCell.nHeight = tIt.nStepY;
                    CODEC_DecodeCell(&tCursor, pEqual, &gatDccCells[tIt.nCell], &tCell, &pRun);
                    gatDccCells[tIt.nCell] = tCell;

                    bMore = CodecDccNextCell(&tDir, &tIt);
                    if (tIt.nFrame != nPrevFrame)
                    {
                        D2DccFrameStrc* pDone = &gatDccFrames[nPrevFrame];
                        D2Dc6FrameStrc* pHeader = (D2Dc6FrameStrc*)pOut;
                        pHeader->nFlip = pDone->nVar0;
                        pHeader->nWidth = pDone->nWidth;
                        pHeader->nHeight = pDone->nHeight;
                        pHeader->nXOffset = pDone->nXOffset;
                        pHeader->nYOffset = pDone->nYOffset;
                        pHeader->nLength = pDone->nCodedBytes;
                        pHeader->unk0x14 = 0;
                        pHeader->nNextBlock = 0;
                        if (!CodecEncodeSprite(pDone, pHeader, pHeader->abData))
                        {
                            char szError[0x200];
                            LOGMANAGER_WriteLogLine("Sprite Decompression Error -- File:%s", szFile);
                            sprintf(szError, "Error decompressing sprite - Possible corruption in data file: %s", szFile);
                            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x660);
                            exit(-1);
                        }
                        pOut += pHeader->nLength + pHeader->unk0x14 + 0x23;
                        nPrevFrame = tIt.nFrame;
                    }
                }
                while (bMore);
            }
        }

        tCursor.AlignToByte();
    }

    LeaveCriticalSection(&gtCodecLock);
    return (int)pResult;
}

extern "C" const int gData_006E5F70[16] = { 0, 1, 2, 4, 6, 8, 10, 12, 14, 16, 20, 24, 26, 28, 30, 32 }; // 0x006E5F70
#pragma comment(linker, "/alternatename:?ganDccFieldWidths@@3QBHB=_gData_006E5F70")

extern "C" const unsigned int gData_006E5FB0[32] = { // 0x006E5FB0
    0x00000001, 0x00000002, 0x00000004, 0x00000008, 0x00000010, 0x00000020, 0x00000040, 0x00000080,
    0x00000100, 0x00000200, 0x00000400, 0x00000800, 0x00001000, 0x00002000, 0x00004000, 0x00008000,
    0x00010000, 0x00020000, 0x00040000, 0x00080000, 0x00100000, 0x00200000, 0x00400000, 0x00800000,
    0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000
};
#pragma comment(linker, "/alternatename:?gadwDccSignBits@@3QBIB=_gData_006E5FB0")

extern "C" const unsigned int gData_006E6030[33] = { // 0x006E6030
    0x00000000, 0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F, 0x0000003F, 0x0000007F,
    0x000000FF, 0x000001FF, 0x000003FF, 0x000007FF, 0x00000FFF, 0x00001FFF, 0x00003FFF, 0x00007FFF,
    0x0000FFFF, 0x0001FFFF, 0x0003FFFF, 0x0007FFFF, 0x000FFFFF, 0x001FFFFF, 0x003FFFFF, 0x007FFFFF,
    0x00FFFFFF, 0x01FFFFFF, 0x03FFFFFF, 0x07FFFFFF, 0x0FFFFFFF, 0x1FFFFFFF, 0x3FFFFFFF, 0x7FFFFFFF,
    0xFFFFFFFF
};
#pragma comment(linker, "/alternatename:?gadwDccBitMasks@@3PAIA=_gData_006E6030")

extern "C" const unsigned char gData_006E60B8[128] = { // 0x006E60B8
    0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xF8, 0xFF, 0xFF, 0xFF,
    0xF0, 0xFF, 0xFF, 0xFF, 0xE0, 0xFF, 0xFF, 0xFF, 0xC0, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xFF,
    0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xFF, 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0xF8, 0xFF, 0xFF,
    0x00, 0xF0, 0xFF, 0xFF, 0x00, 0xE0, 0xFF, 0xFF, 0x00, 0xC0, 0xFF, 0xFF, 0x00, 0x80, 0xFF, 0xFF,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0xF8, 0xFF,
    0x00, 0x00, 0xF0, 0xFF, 0x00, 0x00, 0xE0, 0xFF, 0x00, 0x00, 0xC0, 0xFF, 0x00, 0x00, 0x80, 0xFF,
    0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0xF8,
    0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x80
};
#pragma comment(linker, "/alternatename:?gadwDccSignExtend@@3QBIB=_gData_006E60B8")
