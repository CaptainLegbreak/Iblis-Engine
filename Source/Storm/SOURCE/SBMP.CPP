#include "Storm.h"
#include "StormApi.h"

#define STORM_MIN(a, b) (((a) < (b)) ? (a) : (b))





struct D2TargaHeaderStrc;

struct D2TgaFieldsStrc;

struct D2BitOutputStrc;

struct D2BitmapFileHeader;

struct D2BitmapInfoHeader;

struct D2PaletteEntry;

struct D2BitmapColor;

struct D2CopyStackArg;

#pragma pack(push, 1)

struct D2TargaHeaderStrc
{
    union
    {
        unsigned char bytes[18];
        struct
        {
            unsigned char nIdLength;
            unsigned char nColorMapType;
            unsigned char nImageType;
            unsigned short nColorMapFirst;
            unsigned short nColorMapLength;
            unsigned char nColorMapDepth;
            unsigned short nOriginXY[2];
            unsigned short nWidth;
            unsigned short nHeight;
            unsigned char nPixelDepth;
            unsigned char nAttributeBits : 4;
            unsigned char nOrigin : 2;
            unsigned char nInterleave : 2;
        };
    };
};

#pragma pack(pop)

struct D2PaletteColorStrc { unsigned char red, green, blue, alpha; };

void __stdcall SMemZero(void* destination, unsigned int size); // 0x0041D300

#pragma pack(push, 1)

struct D2TgaFieldsStrc
{
    unsigned char nIdLength;
    unsigned char nColorMapType;
    unsigned char nImageType;
    unsigned short nColorMapFirst;
    unsigned short nColorMapLength;
    unsigned char nColorMapDepth;
    unsigned short nXOrigin;
    unsigned short nYOrigin;
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned char nPixelDepth;
    unsigned char nDescriptor;
};

#pragma pack(pop)

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340

struct D2BitOutputStrc
{
    int nCodeWidth;
    int nCodeMask;
    int nInitialCodeWidth;
    int nBits;
    int nBitCount;
    int unknown14[2];
    int nClearCode;
    int unknown20;
    int nNextCode;
    void* pHashTable;
    int unknown2C;
    int nBlockLength;
    unsigned char pBlock[256];
};

typedef unsigned char BYTE;

typedef unsigned short WORD;

typedef unsigned int DWORD;

#pragma pack(push, 2)

struct D2BitmapFileHeader { WORD type; DWORD size; WORD reserved1; WORD reserved2; DWORD offset; };

struct D2BitmapInfoHeader {
    DWORD size; int width; int height; WORD planes; WORD bits;
    DWORD compression; DWORD imageSize; int xppm; int yppm; DWORD colorsUsed; DWORD colorsImportant;
};

struct D2PaletteEntry { BYTE red, green, blue, flags; };

struct D2BitmapColor { BYTE blue, green, red, reserved; };



struct D2CopyStackArg { unsigned int value; };

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0

struct D2BmpRgbQuadStrc
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

struct D2BmpFileHeaderStrc
{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
};

struct D2BmpInfoHeaderStrc
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
};

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                   // 0x00412650



static int IsSupportedTgaHeader(const D2TgaFieldsStrc* pHeader); // 0x006C50D0

static int __stdcall DecodeTgaMem(const D2TgaFieldsStrc* pHeader, unsigned int nSize, D2PaletteColorStrc* pPalette, unsigned char* pDst, int nDstSize, int* pWidth, int* pHeight, int* pDepth);

static void __stdcall FlipImage(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride);

static int __stdcall DecodeBmpMem(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize);

static void FlushOutputBlock(D2BitOutputStrc* pState, unsigned char** ppOutput); // 0x006C5A60

static void __fastcall Output(D2BitOutputStrc* pState, unsigned char** ppOutput, int nCode);

static void __stdcall ClearBlock(unsigned char** ppOutput, D2BitOutputStrc* pState);

static const char* FindFileExtension(const char* szPath); // 0x006C5EE0

static int GetImageType(unsigned short signature); // 0x006C5F40

static void __stdcall UncompressPcxImage(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nSrcSize, int nWidth, int nBytesPerLine, int nPlanes);

static int __stdcall DecodeBmpFile(unsigned char* pPalette, void* hFile, int* pWidth, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth);

static void __stdcall AddOutputChar(unsigned char** ppOutput, int nChar, D2BitOutputStrc* pState); // 0x006C6370

static int __stdcall DecodePcxMem(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth);

static int __fastcall DecodeTgaPixels(const D2TargaHeaderStrc* pHeader, const unsigned char* pSrc, int nSrcSize, unsigned char* pDst, int nDstSize); // 0x006C5210

static int __stdcall EncodeBmp256File(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height);

static unsigned int __stdcall sub_006C59C0_CopyPixels(BYTE* out, D2CopyStackArg src, D2CopyStackArg size, D2CopyStackArg pitch, D2CopyStackArg width, unsigned int rows);




int __stdcall SFileGetFileSize(void* hFile, unsigned int* pdwFileSizeHigh); // 0x00416370

int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped); // 0x0041B050

static void __cdecl CompressPcxRow(unsigned char** ppDest, unsigned char** ppSource, int nCount);




struct D2TgaSourceColorStrc;

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nBytes, unsigned long* pWritten, void* pOverlapped); // 0x006CC1A8

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char*, unsigned int, unsigned int, void*, unsigned int, unsigned int, void*);

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9

extern const char gszTga[]; // 0x006FCC7C

extern const char gszPcx[]; // 0x006FCC74

extern const char gszGif[]; // 0x006FCC6C

struct D2TgaSourceColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nReserved;
};

static int __stdcall EncodeTgaFile(void* hFile, const unsigned char* pPixels, const D2TgaSourceColorStrc* pPalette, int nWidth, int nHeight, int nPixelDepth, int nPitch);

int __stdcall SBmpSaveImageEx(char* szFile, unsigned char* pPalette, unsigned char* pPixels, int nWidth, int nHeight, int nBits, int nPitch); // 0x006C6CB0

typedef void* (__stdcall* SBMPALLOCPROC)(unsigned int nSize);

int __stdcall SFileCloseFile(void* pArg); // 0x004198D0

int __stdcall SFileOpenFile(const char* szFileName, void** phFile); // 0x00419980


// build: base-profile

#pragma pack(push,1)

struct D2PcxHeaderStrc {
 unsigned short id;
 unsigned char encoding,bits;
 unsigned short xmin,ymin,xmax,ymax,hres,vres;
 unsigned char colorMap[48];
 unsigned char reserved,planes;
 unsigned short bytesPerLine;
 unsigned char rest[60];
};

struct D2PaletteStrc {unsigned char red,green,blue,flags;};

struct D2PcxRgbStrc {unsigned char red,green,blue;};

struct D2PcxPaletteBlockStrc {unsigned char marker; D2PcxRgbStrc colors[256];};




static int __fastcall EncodePcx256File(int width,int height,void* file,D2PaletteStrc* colors,unsigned char* pixels);

typedef void* HANDLE;

struct RGBQuad { unsigned char r, g, b, a; };

int __fastcall CompressGifImage(int nCount, const unsigned char* pPixels, unsigned char* pOut); // 0x006C6470

struct RGBTriple { unsigned char r, g, b; };

static int __stdcall EncodeGif256File(HANDLE hFile, const RGBQuad* pPalette, const unsigned char* pPixels, int nWidth, int nHeight);

struct PcxHeaderStrc
{
    unsigned char nManufacturer;
    unsigned char nVersion;
    unsigned char nEncoding;
    unsigned char nBitsPerPixel;
    unsigned short nXMin;
    unsigned short nYMin;
    unsigned short nXMax;
    unsigned short nYMax;
    unsigned short nHDpi;
    unsigned short nVDpi;
    unsigned char pColorMap[48];
    unsigned char nReserved;
    unsigned char nPlanes;
    unsigned short nBytesPerLine;
    unsigned short nPaletteInfo;
    unsigned short nHScreenSize;
    unsigned short nVScreenSize;
    unsigned char pFiller[54];
};

struct PcxRgbStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};


static int __stdcall DecodePcxFile(void* hFile, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth);


static int __stdcall DecodeTgaFile(void* hFile, D2PaletteColorStrc* pPalette, unsigned char* pBuffer, unsigned int* pWidth, int nBufferSize, unsigned int* pHeight, unsigned int* pBitDepth);












// 0x006C50D0
static int IsSupportedTgaHeader(const D2TgaFieldsStrc* pHeader)
{
    const unsigned char nType = pHeader->nImageType;
    if (nType == 1 || nType == 2 || nType == 9 || nType == 10)
    {
        if ((pHeader->nColorMapType == 0
                && ((pHeader->nPixelDepth == 24 && !(pHeader->nDescriptor & 0x0F))
                    || (pHeader->nPixelDepth == 32 && (pHeader->nDescriptor & 0x0F) == 8)))
            || (pHeader->nColorMapType == 1 && pHeader->nPixelDepth == 8
                && pHeader->nColorMapLength + pHeader->nColorMapFirst <= 0x100
                && (pHeader->nColorMapDepth == 24 || pHeader->nColorMapDepth == 32)))
        {
            if (!(pHeader->nDescriptor & 0xC0))
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x006C5150
static int __stdcall ReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, D2PaletteColorStrc* palette)
{
    int bytesPerColor = (header->bytes[7] + 7) / 8;
    int index = *(const unsigned short*)&header->bytes[3];
    int end = index + *(const unsigned short*)&header->bytes[5];
    if ((end - index) * bytesPerColor != size)
        return 0;
    SMemZero(palette, index * sizeof(D2PaletteColorStrc));
    for (; index < end; ++index)
    {
        palette[index].red = source[2];
        palette[index].green = source[1];
        palette[index].blue = source[0];
        palette[index].alpha = bytesPerColor > 3 ? source[3] : 0;
        source += bytesPerColor;
    }
    SMemZero(palette + index, (256 - index) * sizeof(D2PaletteColorStrc));
    return 1;
}

// 0x006C5210
static int __fastcall DecodeTgaPixels(const D2TargaHeaderStrc* pHeader, const unsigned char* pSrc, int nSrcSize, unsigned char* pDst, int nDstSize)
{
    unsigned char* pOut = pDst;
    const int nWidth = *(const unsigned short*)&pHeader->bytes[12];
    const int nHeight = *(const unsigned short*)&pHeader->bytes[14];
    const int nBytes = (pHeader->bytes[16] + 7) / 8;
    const int nImageSize = nBytes * nHeight * nWidth;
    int nSize = STORM_MIN(nDstSize, nImageSize);

    const unsigned char nDescriptor = pHeader->bytes[17];
    const unsigned char bRightToLeft = (nDescriptor >> 4) & 1;
    const int nStepX = bRightToLeft ? -nBytes : nBytes;

    const unsigned char bTopToBottom = (nDescriptor >> 5) & 1;
    int nRowStep;
    if (bTopToBottom)
    {
        nRowStep = (nBytes - nStepX) * nWidth;
    }
    else
    {
        nRowStep = -((nStepX + nBytes) * nWidth);
    }

    if (bRightToLeft)
    {
        pOut = pDst + (nWidth - 1) * nBytes;
    }

    if (!bTopToBottom)
    {
        pOut += (nHeight - 1) * nBytes * nWidth;
    }

    switch (pHeader->bytes[2])
    {
    case 1:
    case 2:
    {
        if (nSrcSize < nSize)
        {
            return 0;
        }

        if (!bRightToLeft && bTopToBottom)
        {
            SMemCopy(pOut, pSrc, nSize);
            break;
        }

        int nCount = nSize / nBytes;
        int nColumn = nWidth;
        while (nCount--)
        {
            switch (nBytes)
            {
            case 4:
                *(unsigned int*)pOut = *(const unsigned int*)pSrc;
                break;
            case 3:
                pOut[2] = pSrc[2];
            case 2:
                pOut[1] = pSrc[1];
            case 1:
                pOut[0] = pSrc[0];
            }

            pOut += nStepX;
            if (!--nColumn)
            {
                nColumn = nWidth;
                pOut += nRowStep;
            }

            pSrc += nBytes;
        }

        break;
    }

    case 9:
    case 10:
    {
        int nPixels = nSize / nBytes;
        int nColumn = nWidth;
        const unsigned char* pSrcEnd = pSrc + nSrcSize;
        while (nPixels)
        {
            if (pSrc >= pSrcEnd)
            {
                return 1;
            }

            int nRun = *pSrc++;
            if (nRun & 0x80)
            {
                nRun = (nRun & 0x7F) + 1;
                if (nRun >= nPixels)
                {
                    nRun = nPixels;
                }

                nPixels -= nRun;
                if (pSrc + nBytes > pSrcEnd)
                {
                    return 0;
                }

                while (nRun--)
                {
                    switch (nBytes)
                    {
                    case 4:
                        *(unsigned int*)pOut = *(const unsigned int*)pSrc;
                        break;
                    case 3:
                        pOut[2] = pSrc[2];
                    case 2:
                        pOut[1] = pSrc[1];
                    case 1:
                        pOut[0] = pSrc[0];
                    }

                    pOut += nStepX;
                    if (!--nColumn)
                    {
                        nColumn = nWidth;
                        pOut += nRowStep;
                    }
                }

                pSrc += nBytes;
            }
            else
            {
                int nRaw = nRun + 1;
                if (nRaw >= nPixels)
                {
                    nRaw = nPixels;
                }

                nPixels -= nRaw;
                if (pSrc + nRaw * nBytes > pSrcEnd)
                {
                    return 0;
                }

                while (nRaw--)
                {
                    switch (nBytes)
                    {
                    case 4:
                        *(unsigned int*)pOut = *(const unsigned int*)pSrc;
                        break;
                    case 3:
                        pOut[2] = pSrc[2];
                    case 2:
                        pOut[1] = pSrc[1];
                    case 1:
                        pOut[0] = pSrc[0];
                    }

                    pOut += nStepX;
                    if (!--nColumn)
                    {
                        nColumn = nWidth;
                        pOut += nRowStep;
                    }

                    pSrc += nBytes;
                }
            }
        }

        break;
    }

    default:
        return 0;
    }

    return 1;
}



// 0x006C54D0
static int __stdcall DecodeTgaFile(void* hFile, D2PaletteColorStrc* pPalette, unsigned char* pBuffer, unsigned int* pWidth, int nBufferSize, unsigned int* pHeight, unsigned int* pBitDepth)
{
    D2TargaHeaderStrc tHeader;
    int nRead;
    if (!SFileReadFile(hFile, &tHeader, sizeof(tHeader), &nRead, 0) || nRead != sizeof(tHeader))
    {
        return 0;
    }
    if (!IsSupportedTgaHeader((const D2TgaFieldsStrc*)&tHeader))
    {
        return 0;
    }

    const unsigned int nWidth = *(unsigned short*)&tHeader.bytes[12];
    const unsigned int nHeight = *(unsigned short*)&tHeader.bytes[14];
    const unsigned int nBitDepth = tHeader.bytes[16];

    int nPaletteSize;
    if (tHeader.bytes[1])
    {
        nPaletteSize = (tHeader.bytes[7] + 7) / 8 * *(unsigned short*)&tHeader.bytes[5];
    }
    else
    {
        nPaletteSize = 0;
    }

    int nImageSize;
    if (tHeader.bytes[2] >= 9)
    {
        nImageSize = 1;
    }
    else
    {
        nImageSize = ((int)nBitDepth + 7) / 8 * nHeight * nWidth;
    }

    const unsigned int nIdLength = tHeader.bytes[0];
    if (nIdLength + nImageSize + nPaletteSize + sizeof(tHeader) > SFileGetFileSize(hFile, 0))
    {
        return 0;
    }

    if (pWidth)
    {
        *pWidth = nWidth;
    }
    if (pHeight)
    {
        *pHeight = nHeight;
    }
    if (pBitDepth)
    {
        *pBitDepth = nBitDepth;
    }

    SFileSetFilePointer(hFile, nIdLength, 0, 1);

    if (pPalette && tHeader.bytes[1])
    {
        unsigned char aPaletteData[0x400];
        SFileReadFile(hFile, aPaletteData, nPaletteSize, 0, 0);
        if (!ReadTgaPalette(&tHeader, aPaletteData, nPaletteSize, pPalette))
        {
            return 0;
        }
    }

    if (pBuffer)
    {
        const int nDataSize = SFileGetFileSize(hFile, 0) - sizeof(tHeader) - tHeader.bytes[0] - nPaletteSize;
        unsigned char* pData = (unsigned char*)SMemAlloc(nDataSize, ".\\SOURCE\\SBMP.CPP", 0x116, 0);
        SFileReadFile(hFile, pData, nDataSize, 0, 0);
        if (!DecodeTgaPixels(&tHeader, pData, nDataSize, pBuffer, nBufferSize))
        {
            SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 0x11D, 0);
            return 0;
        }
        SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 0x120, 0);
    }

    return 1;
}

// 0x006C5730
static int __stdcall DecodeTgaMem(const D2TgaFieldsStrc* pHeader, unsigned int nSize, D2PaletteColorStrc* pPalette, unsigned char* pDst, int nDstSize, int* pWidth, int* pHeight, int* pDepth)
{
    if (nSize < 18)
    {
        return 0;
    }

    if (!IsSupportedTgaHeader(pHeader))
    {
        return 0;
    }

    const int nDepth = pHeader->nPixelDepth;
    const int nWidth = pHeader->nWidth;
    const int nHeight = pHeader->nHeight;

    int nColorMapSize;
    if (pHeader->nColorMapType)
    {
        nColorMapSize = (pHeader->nColorMapDepth + 7) / 8 * pHeader->nColorMapLength;
    }
    else
    {
        nColorMapSize = 0;
    }

    int nImageSize;
    if (pHeader->nImageType >= 9)
    {
        nImageSize = 1;
    }
    else
    {
        nImageSize = (nDepth + 7) / 8 * nHeight * nWidth;
    }

    if (pHeader->nIdLength + nImageSize + nColorMapSize + 18 > nSize)
    {
        return 0;
    }

    if (pWidth)
    {
        *pWidth = nWidth;
    }
    if (pHeight)
    {
        *pHeight = nHeight;
    }
    if (pDepth)
    {
        *pDepth = nDepth;
    }

    if (pPalette && pHeader->nColorMapType)
    {
        const unsigned char* pColorMap = (const unsigned char*)pHeader + pHeader->nIdLength + 18;
        if (!ReadTgaPalette((const D2TargaHeaderStrc*)pHeader, pColorMap, nColorMapSize, pPalette))
        {
            return 0;
        }
    }

    if (pDst)
    {
        const unsigned char* pSrc = (const unsigned char*)pHeader + pHeader->nIdLength + nColorMapSize + 18;
        if (!DecodeTgaPixels((const D2TargaHeaderStrc*)pHeader, pSrc, (const unsigned char*)pHeader - pSrc + nSize, pDst, nDstSize))
        {
            return 0;
        }
    }

    return 1;
}

// 0x006C5830
static int __stdcall EncodeTgaFile(void* hFile, const unsigned char* pPixels, const D2TgaSourceColorStrc* pPalette, int nWidth, int nHeight, int nPixelDepth, int nPitch)
{
    unsigned long nWritten;
    D2TargaHeaderStrc header;
    unsigned char colorMap[256][3];

    header.nIdLength = 0;
    if (nPixelDepth == 8)
    {
        header.nColorMapType = 1;
        header.nImageType = 1;
        header.nColorMapFirst = 0;
        header.nColorMapLength = 256;
        header.nColorMapDepth = 24;
    }
    else
    {
        header.nColorMapType = 0;
        header.nImageType = 2;
        header.nColorMapFirst = 0;
        header.nColorMapLength = 0;
        header.nColorMapDepth = 0;
    }
    header.nOriginXY[0] = 0;
    header.nOriginXY[1] = 0;
    header.nWidth = (unsigned short)nWidth;
    header.nHeight = (unsigned short)nHeight;
    header.nPixelDepth = (unsigned char)nPixelDepth;
    header.nAttributeBits = nPixelDepth == 32 ? 8 : 0;
    header.nOrigin = 2;
    header.nInterleave = 0;
    WriteFile(hFile, &header, sizeof(header), &nWritten, 0);

    if (nPixelDepth == 8)
    {
        for (int i = 0; i < 256; ++i)
        {
            colorMap[i][0] = pPalette[i].nBlue;
            colorMap[i][1] = pPalette[i].nGreen;
            colorMap[i][2] = pPalette[i].nRed;
        }
        WriteFile(hFile, colorMap, sizeof(colorMap), &nWritten, 0);
    }

    int nRowBytes = ((nPixelDepth + 7) / 8) * nWidth;
    if (nPitch == nRowBytes)
    {
        WriteFile(hFile, pPixels, nRowBytes * nHeight, &nWritten, 0);
    }
    else
    {
        const unsigned char* pSrc = pPixels;
        for (; nHeight; --nHeight)
        {
            WriteFile(hFile, pSrc, nRowBytes, &nWritten, 0);
            pSrc += nPitch;
        }
    }
    return 1;
}

// 0x006C59C0
static void __stdcall FlipImage(unsigned char* pDst, int nRows, const unsigned char* pSrc, int nDstSize, int nRowWidth, int nStride)
{
    VALIDATEBEGIN;
    VALIDATE(pDst);
    VALIDATE(pSrc);
    VALIDATE(nDstSize);
    VALIDATE(nRowWidth);
    VALIDATE(nStride);
    VALIDATE(nRows);
    VALIDATEENDVOID;

    {
    pSrc += (nRows - 1) * nStride;
    unsigned char* pEnd = pDst + nDstSize;
    while (nRows--)
    {
        const int nCopy = nRowWidth < pEnd - pDst ? nRowWidth : pEnd - pDst;
        if (!nCopy)
            break;
        SMemCopy(pDst, pSrc, nCopy);
        pDst += nCopy;
        pSrc -= nStride;
    }
    }
}


// 0x006C5A60
static void FlushOutputBlock(D2BitOutputStrc* pState, unsigned char** ppOutput)
{
    if (pState->nBlockLength)
    {
        pState->pBlock[0] = (unsigned char)pState->nBlockLength;
        ++pState->nBlockLength;
        SMemCopy(*ppOutput, pState->pBlock, pState->nBlockLength);
        *ppOutput += pState->nBlockLength;
        pState->nBlockLength = 0;
    }
}

void __fastcall EmitCodeContext(unsigned char** ppOutput, D2BitOutputStrc* pState, int nCode)
{
    pState->nBits |= nCode << pState->nBitCount;
    pState->nBitCount += pState->nCodeWidth;
    while (pState->nBitCount >= 8)
    {
        ++pState->nBlockLength;
        pState->pBlock[pState->nBlockLength] = (unsigned char)pState->nBits;
        if (pState->nBlockLength >= 255)
            FlushOutputBlock(pState, ppOutput);
        pState->nBits >>= 8;
        pState->nBitCount -= 8;
    }
    if (pState->nNextCode > pState->nCodeMask)
    {
        ++pState->nCodeWidth;
        pState->nCodeMask = pState->nCodeWidth == 12 ? 4096 : (1 << pState->nCodeWidth) - 1;
    }
}

// 0x006C5A90
static void __fastcall Output(D2BitOutputStrc* pState, unsigned char** ppOutput, int nCode)
{
    pState->nBits |= nCode << pState->nBitCount;
    pState->nBitCount += pState->nCodeWidth;
    while (pState->nBitCount >= 8)
    {
        ++pState->nBlockLength;
        pState->pBlock[pState->nBlockLength] = (unsigned char)pState->nBits;
        if (pState->nBlockLength >= 255)
            FlushOutputBlock(pState, ppOutput);
        pState->nBits >>= 8;
        pState->nBitCount -= 8;
    }
    if (pState->nNextCode > pState->nCodeMask)
    {
        ++pState->nCodeWidth;
        if (pState->nCodeWidth == 12)
            pState->nCodeMask = 4096;
        else
            pState->nCodeMask = (1 << pState->nCodeWidth) - 1;
    }
}

// 0x006C5B10
static void __cdecl CompressPcxRow(unsigned char** ppDest, unsigned char** ppSource, int nCount)
{
    do
    {
        const unsigned char nByte = **ppSource;
        ++*ppSource;
        int nRun = 1;
        --nCount;
        while (nCount && nByte == **ppSource && nRun < 63)
        {
            --nCount;
            ++*ppSource;
            ++nRun;
        }

        if (nRun > 1 || nByte >= 0xC0)
        {
            **ppDest = (unsigned char)(nRun | 0xC0);
            ++*ppDest;
        }
        **ppDest = nByte;
        ++*ppDest;
    }
    while (nCount);
}

// 0x006C5B60
static int __fastcall EncodePcx256File(int width,int height,void* file,D2PaletteStrc* colors,unsigned char* pixels)
{
 const int nWidth=width;
 D2PcxHeaderStrc header;
 SMemZero(&header,sizeof(header));
 header.xmax=(unsigned short)(nWidth-1);
 header.ymax=(unsigned short)(height-1);
 header.id=0x050a;
 header.encoding=1;
 header.bits=8;
 header.hres=72;
 header.vres=72;
 header.planes=1;
 header.bytesPerLine=(unsigned short)nWidth;
 {
  unsigned long written;
  WriteFile(file,&header,128,&written,0);
 }
 unsigned long writtenData;
 unsigned char* encoded=(unsigned char*)SMemAlloc(height*nWidth*2,".\\SOURCE\\SBMP.CPP",0x4eb,0);
 unsigned char* source=pixels;
 unsigned char* dest=encoded;
 for(int row=0;row<height;++row) CompressPcxRow(&dest,&source,nWidth);
 WriteFile(file,encoded,(unsigned)(dest-encoded),&writtenData,0);
 SMemFree(encoded,".\\SOURCE\\SBMP.CPP",0x4f2,0);
 D2PcxPaletteBlockStrc palette;
 palette.marker=12;
 for(int i=0;i<256;++i) {
  palette.colors[i].red=colors[i].red;
  palette.colors[i].green=colors[i].green;
  palette.colors[i].blue=colors[i].blue;
 }
 WriteFile(file,&palette,sizeof(palette),&writtenData,0);
 return 1;
}

// 0x006C5CF0
static void __stdcall UncompressPcxImage(unsigned char* pDst, unsigned int nLimit, const unsigned char* pSrc, int nSrcSize, int nWidth, int nBytesPerLine, int nPlanes)
{
    unsigned char* pDstEnd = pDst + nLimit;
    const unsigned char* pSrcEnd = pSrc + nSrcSize;
    const int nRowBytes = nWidth * nPlanes;
    unsigned int nColumn = 0;
    int nPlane = nPlanes - 1;

    while (pDst + nColumn < pDstEnd && pSrc < pSrcEnd)
    {
        unsigned char nToken = *pSrc++;
        if (nToken >= 0xC0)
        {
            unsigned int nCount = nToken & 0x3F;
            nCount = STORM_MIN(nCount, (unsigned int)(pDstEnd - pDst));

            nToken = *pSrc++;
            do
            {
                if (nColumn >= nWidth)
                {
                    unsigned int nSkip = STORM_MIN(nCount, nBytesPerLine - nColumn);
                    nColumn += nSkip;
                    if (nColumn >= nBytesPerLine)
                    {
                        nColumn -= nBytesPerLine;
                        if (--nPlane < 0)
                        {
                            pDst += nRowBytes;
                            nPlane = nPlanes - 1;
                        }
                    }

                    nCount -= nSkip;
                    if (!nCount)
                    {
                        break;
                    }
                }

                int nRun = STORM_MIN(nCount, nWidth - nColumn);

                switch (nPlanes)
                {
                case 1:
                    memset(pDst + nColumn, nToken, nRun);
                    break;

                case 3:
                {
                    int nOffset = nColumn * 3 + nPlane;
                    int nEnd = nOffset + STORM_MIN(pDstEnd - pDst, nRun * 3);
                    for (; nOffset < nEnd; nOffset += 3)
                    {
                        pDst[nOffset] = nToken;
                    }
                    break;
                }

                default:
                {
                    int nOffset = nColumn * nPlanes + nPlane;
                    int nEnd = nOffset + STORM_MIN(pDstEnd - pDst, nRun * nPlanes);
                    for (; nOffset < nEnd; nOffset += nPlanes)
                    {
                        pDst[nOffset] = nToken;
                    }
                    break;
                }
                }

                nColumn += nRun;
                if (nColumn >= nBytesPerLine)
                {
                    nColumn -= nBytesPerLine;
                    if (--nPlane < 0)
                    {
                        pDst += nRowBytes;
                        nPlane = nPlanes - 1;
                    }
                }

                nCount -= nRun;
            }
            while (nCount > 0);
        }
        else
        {
            if (nColumn < nWidth)
            {
                switch (nPlanes)
                {
                case 1:
                    pDst[nColumn] = nToken;
                    break;

                case 3:
                    if (pDst + (nColumn * 3 + nPlane) < pDstEnd)
                    {
                        pDst[nColumn * 3 + nPlane] = nToken;
                    }
                    break;

                default:
                    if (pDst + (nColumn * nPlanes + nPlane) < pDstEnd)
                    {
                        pDst[nColumn * nPlanes + nPlane] = nToken;
                    }
                    break;
                }
            }

            ++nColumn;
            if (nColumn >= nBytesPerLine)
            {
                nColumn -= nBytesPerLine;
                if (--nPlane < 0)
                {
                    pDst += nRowBytes;
                    nPlane = nPlanes - 1;
                }
            }
        }
    }
}


void __fastcall ResetDictionaryContext(D2BitOutputStrc* pState, unsigned char** ppOutput)
{
    ClearBlock(ppOutput, pState);
}

// 0x006C5EE0
static const char* FindFileExtension(const char* szPath)
{
    const char* szName = szPath;
    while (SStrChr(szName, '\\'))
        szName = SStrChr(szName, '\\') + 1;
    while (SStrChr(szName + 1, '.'))
        szName = SStrChr(szName + 1, '.');
    return szName;
}

// 0x006C5F40
static int GetImageType(unsigned short signature)
{
    switch (signature)
    {
    case 0x050A:
        return 2;
    case 0x4D42:
        return 1;
    default:
        return 3;
    }
}

// 0x006C5F70
static int __stdcall DecodeBmpFile(unsigned char* pPalette, void* hFile, int* pWidth, unsigned char* pBuffer, unsigned int nBufferSize, int* pHeight, int* pBitDepth)
{
    D2BmpRgbQuadStrc aColors[256];
    D2BmpFileHeaderStrc tFileHeader;
    D2BmpInfoHeaderStrc tInfoHeader;

    if (!SFileReadFile(hFile, &tFileHeader, sizeof(tFileHeader), 0, 0))
    {
        return 0;
    }

    if (!SFileReadFile(hFile, &tInfoHeader, sizeof(tInfoHeader), 0, 0))
    {
        return 0;
    }

    if (pWidth)
    {
        *pWidth = tInfoHeader.biWidth;
    }

    if (pHeight)
    {
        *pHeight = tInfoHeader.biHeight;
    }

    if (pBitDepth)
    {
        *pBitDepth = tInfoHeader.biBitCount;
    }

    if (tInfoHeader.biBitCount > 8)
    {
        pPalette = 0;
    }
    else if (pPalette)
    {
        if (!SFileReadFile(hFile, aColors, sizeof(aColors), 0, 0))
        {
            return 0;
        }

        for (int i = 0; i < 256; ++i)
        {
            pPalette[4 * i + 0] = aColors[i].rgbRed;
            pPalette[4 * i + 1] = aColors[i].rgbGreen;
            pPalette[4 * i + 2] = aColors[i].rgbBlue;
            pPalette[4 * i + 3] = 0;
        }
    }

    if (pBuffer)
    {
        SFileSetFilePointer(hFile, tFileHeader.bfOffBits - (pPalette ? 0x400 : 0) - 0x36, 0, 1);

        int& nRead = *(int*)&pHeight;
        nRead = 0;
        unsigned char* pData = (unsigned char*)SMemAlloc(tInfoHeader.biSizeImage, ".\\SOURCE\\SBMP.CPP", 0x1FF, 0);
        SFileReadFile(hFile, pData, tInfoHeader.biSizeImage, &nRead, 0);

        const int nRowBytes = (int)(tInfoHeader.biBitCount * tInfoHeader.biWidth) >> 3;
        int nStride = nRowBytes;
        if (nRowBytes & 3)
        {
            nStride = nRowBytes - (nRowBytes & 3) + 4;
        }

        FlipImage(pBuffer, tInfoHeader.biHeight, pData, nBufferSize, nRowBytes, nStride);
        SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 0x20B, 0);
        if (nRead < tInfoHeader.biSizeImage)
        {
            return 0;
        }
    }

    return 1;
}

// 0x006C60F0
static int __stdcall DecodeBmpMem(int* pWidth, int* pHeight, unsigned int* pBitCount, const unsigned char* pData, unsigned char* pPalette, unsigned char* pPixels, int nPixelsSize)
{
    unsigned char* pOut = pPalette;
    if (pWidth)
    {
        *pWidth = *(const int*)(pData + 0x12);
    }

    if (pHeight)
    {
        *pHeight = *(const int*)(pData + 0x16);
    }

    if (pBitCount)
    {
        *pBitCount = *(const unsigned short*)(pData + 0x1C);
    }

    {
        if (*(const unsigned short*)(pData + 0x1C) > 8)
        {
            pOut = 0;
        }
        else if (pOut)
        {

            const unsigned char* pColors = pData + 0x36;
            for (pPalette = 0; (int)pPalette < 256; ++pPalette)
            {
                pOut[4 * (int)pPalette + 0] = pColors[4 * (int)pPalette + 2];
                pOut[4 * (int)pPalette + 1] = pColors[4 * (int)pPalette + 1];
                pOut[4 * (int)pPalette + 2] = pColors[4 * (int)pPalette + 0];
                pOut[4 * (int)pPalette + 3] = 0;
            }
        }

        if (pPixels)
        {
            const int nBitCount = *(const unsigned short*)(pData + 0x1C);
            const int nOffset = *(const int*)(pData + 0x0A) - (pOut ? 0x400 : 0) - 0x36;
            const int nRowWidth = (nBitCount * *(const int*)(pData + 0x12)) >> 3;
            int nStride = nRowWidth;
            if (nRowWidth & 3)
            {
                nStride = nRowWidth - (nRowWidth & 3) + 4;
            }

            FlipImage(pPixels, *(const int*)(pData + 0x16), pData + nOffset, nPixelsSize, nRowWidth, nStride);
        }
    }

    return 1;
}

int __cdecl EmitGetImageType(unsigned short signature)
{
    return GetImageType(signature);
}

static unsigned int __stdcall sub_006C59C0_CopyPixels(BYTE* out, D2CopyStackArg src, D2CopyStackArg size, D2CopyStackArg pitch, D2CopyStackArg width, unsigned int rows)
{
    rows += src.value + size.value + pitch.value + width.value;
    out[0] = (BYTE)rows;
    out[1] = (BYTE)(rows >> 8);
    return rows;
}

// 0x006C61C0
static int __stdcall EncodeBmp256File(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height)
{
    D2BitmapFileHeader header;
    D2BitmapInfoHeader info;
    D2BitmapColor colors[256];
    unsigned long pixelWritten;
    {
        unsigned long written;
        SMemZero(&header, sizeof(header));
        int imageSize = width * height;
        header.size = imageSize + 1078;
        header.type = 0x4D42;
        header.offset = 1078;
        WriteFile(file, &header, sizeof(header), &written, 0);
        SMemZero(&info, sizeof(info));
        info.size = 40;
        info.width = width;
        info.height = height;
        info.planes = 1;
        info.bits = 8;
        info.compression = 0;
        info.imageSize = imageSize;
        info.colorsUsed = 256;
        info.colorsImportant = 256;
        WriteFile(file, &info, sizeof(info), &written, 0);
        for (int i = 0; i < 256; ++i)
        {
            colors[i].red = palette[i].red;
            colors[i].green = palette[i].green;
            colors[i].blue = palette[i].blue;
            colors[i].reserved = 0;
        }
        WriteFile(file, colors, sizeof(colors), &written, 0);
    }
    unsigned int nPitch = width;
    if ((width & 3))
        nPitch = width - (width & 3) + 4;
    int bufferSize = nPitch * height;
    BYTE* buffer = (BYTE*)SMemAlloc(bufferSize, ".\\SOURCE\\SBMP.CPP", 660, 0);
    D2CopyStackArg copySource = { (unsigned int)pixels };
    D2CopyStackArg copySize = { (unsigned int)bufferSize };
    D2CopyStackArg copyPitch = { nPitch };
    D2CopyStackArg copyWidth = { (unsigned int)width };
    sub_006C59C0_CopyPixels(buffer, copySource, copySize, copyPitch, copyWidth, height);
    WriteFile(file, buffer, bufferSize, &pixelWritten, 0);
    SMemFree(buffer, ".\\SOURCE\\SBMP.CPP", 668, 0);
    return 1;
}


// 0x006C6330
static void __stdcall ClearBlock(unsigned char** ppOutput, D2BitOutputStrc* pState)
{
    SMemZero(pState->pHashTable, 0x4E2C);
    int nCode = pState->nClearCode;
    pState->nNextCode = nCode + 2;
    Output(pState, ppOutput, nCode);
    int nWidth = pState->nInitialCodeWidth;
    pState->nCodeWidth = nWidth;
    pState->nCodeMask = (1 << nWidth) - 1;
}

// 0x006C6370
static void __stdcall AddOutputChar(unsigned char** ppOutput, int nChar, D2BitOutputStrc* pState)
{
    if (pState->unknown14[1])
    {
        pState->unknown14[0] = nChar;
        pState->unknown14[1] = 0;
        return;
    }

    const int nPrefix = pState->unknown14[0];
    int nIndex = (nChar << 4) + nPrefix;
    if (nIndex >= 5003)
    {
        nIndex -= 5003;
    }

    const int nKey = (nPrefix << 8) | nChar;
    if (((int*)pState->pHashTable)[nIndex])
    {
        if (((int*)pState->unknown2C)[nIndex] == nKey)
        {
            pState->unknown14[0] = ((int*)pState->pHashTable)[nIndex];
            return;
        }

        const int nStep = !nIndex ? 1 : 5003 - nIndex;
        do
        {
            nIndex -= nStep;
            if (nIndex < 0)
            {
                nIndex += 5003;
            }

            if (!((int*)pState->pHashTable)[nIndex])
            {
                goto lNotFound;
            }
        }
        while (((int*)pState->unknown2C)[nIndex] != nKey);

        pState->unknown14[0] = ((int*)pState->pHashTable)[nIndex];
        return;
    }

lNotFound:
    Output(pState, ppOutput, pState->unknown14[0]);
    if (pState->nNextCode < 4096)
    {
        ((int*)pState->pHashTable)[nIndex] = pState->nNextCode;
        ++pState->nNextCode;
        ((int*)pState->unknown2C)[nIndex] = nKey;
    }
    else
    {
        ClearBlock(ppOutput, pState);
    }

    pState->unknown14[0] = nChar;
}



// 0x006C6470
int __fastcall CompressGifImage(int nSize, const unsigned char* pData, unsigned char* pOutput)
{
    int nCount = nSize;
    const unsigned char* pIn = pData;
    unsigned char* pStart = pOutput;
    D2BitOutputStrc tState;
    SMemZero(&tState, sizeof(tState));
    tState.nCodeWidth = 9;
    tState.nInitialCodeWidth = 9;
    tState.nCodeMask = 0x1FF;
    tState.nClearCode = 0x100;
    tState.unknown20 = 0x101;
    tState.nNextCode = 0x102;
    tState.unknown14[1] = 1;
    tState.pHashTable = SMemAlloc(0x4E2C, ".\\SOURCE\\SBMP.CPP", 0x388, 8);
    tState.unknown2C = (int)SMemAlloc(0x4E2C, ".\\SOURCE\\SBMP.CPP", 0x389, 8);
    Output(&tState, &pOutput, tState.nClearCode);

    while (nCount)
    {
        --nCount;
        AddOutputChar(&pOutput, *pIn, &tState);
        ++pIn;
    }

    if (!tState.unknown14[1])
    {
        Output(&tState, &pOutput, tState.unknown14[0]);
    }

    Output(&tState, &pOutput, tState.unknown20);
    if (tState.nBitCount > 0)
    {
        ++tState.nBlockLength;
        tState.pBlock[tState.nBlockLength] = (unsigned char)tState.nBits;
    }

    FlushOutputBlock(&tState, &pOutput);
    SMemFree(tState.pHashTable, ".\\SOURCE\\SBMP.CPP", 0x3A4, 0);
    SMemFree((void*)tState.unknown2C, ".\\SOURCE\\SBMP.CPP", 0x3A5, 0);
    return pOutput - pStart;
}

static inline int SBmpWrite(HANDLE hFile, const void* pData, unsigned long nBytes)
{
    unsigned long written;
    return WriteFile(hFile, pData, nBytes, &written, 0);
}

// 0x006C6620
static int __stdcall EncodeGif256File(HANDLE hFile, const RGBQuad* pPalette, const unsigned char* pPixels, int nWidth, int nHeight)
{
    unsigned char header[13];
    unsigned char marker;
    RGBTriple palette[256];
    unsigned long written;

    header[0] = 'G';
    header[1] = 'I';
    header[2] = 'F';
    header[3] = '8';
    header[4] = '7';
    header[5] = 'a';
    *(unsigned short*)(header + 6) = (unsigned short)nWidth;
    *(unsigned short*)(header + 8) = (unsigned short)nHeight;
    header[10] = 0xF7;
    header[11] = 0;
    header[12] = 0;
    SBmpWrite(hFile, header, 13);

    for (int i = 0; i < 256; ++i)
    {
        palette[i].r = pPalette[i].r;
        palette[i].g = pPalette[i].g;
        palette[i].b = pPalette[i].b;
    }
    SBmpWrite(hFile, palette, 768);

    marker = ',';
    SBmpWrite(hFile, &marker, 1);

    *(unsigned short*)(header + 0) = 0;
    *(unsigned short*)(header + 2) = 0;
    *(unsigned short*)(header + 4) = (unsigned short)nWidth;
    *(unsigned short*)(header + 6) = (unsigned short)nHeight;
    header[8] = 0;
    header[9] = 8;
    SBmpWrite(hFile, header, 10);

    unsigned char* pData = (unsigned char*)SMemAlloc(nWidth * nHeight * 2, ".\\SOURCE\\SBMP.CPP", 1000, 0);
    int nLength = CompressGifImage(nWidth * nHeight, pPixels, pData);
    WriteFile(hFile, pData, nLength, &written, 0);
    SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 1006, 0);

    marker = 0;
    SBmpWrite(hFile, &marker, 1);
    marker = ';';
    SBmpWrite(hFile, &marker, 1);
    return 1;
}

// 0x006C6790
static int __stdcall DecodePcxFile(void* hFile, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    PcxHeaderStrc header;
    if (!SFileReadFile(hFile, &header, sizeof(header), 0, 0))
    {
        return 0;
    }

    const int nWidth = header.nXMax - header.nXMin + 1;
    const int nHeight = header.nYMax - header.nYMin + 1;
    const int nBits = header.nBitsPerPixel * header.nPlanes;

    if (pWidth)
    {
        *pWidth = nWidth;
    }

    if (pHeight)
    {
        *pHeight = nHeight;
    }

    if (pBitDepth)
    {
        *pBitDepth = nBits;
    }

    const int bPalette = pPalette && nBits == 8;

    if (pPixels)
    {
        const int nDataSize = SFileGetFileSize(hFile, 0) - (nBits == 8 ? 0x300 : 0) - SFileSetFilePointer(hFile, 0, 0, 1);
        unsigned char* pData = (unsigned char*)SMemAlloc(nDataSize, ".\\SOURCE\\SBMP.CPP", 1131, 0);
        SFileReadFile(hFile, pData, nDataSize, 0, 0);
        UncompressPcxImage(pPixels, nPixelsSize, pData, nDataSize - (nBits == 8 ? 1 : 0), nWidth, header.nBytesPerLine, header.nPlanes);
        SMemFree(pData, ".\\SOURCE\\SBMP.CPP", 1140, 0);
    }
    else if (bPalette)
    {
        SFileSetFilePointer(hFile, -0x300, 0, 2);
    }

    if (bPalette)
    {
        PcxRgbStrc pColors[256];
        SFileReadFile(hFile, pColors, sizeof(pColors), 0, 0);
        for (int i = 0; i < 256; ++i)
        {
            pPalette[4 * i + 0] = pColors[i].nRed;
            pPalette[4 * i + 1] = pColors[i].nGreen;
            pPalette[4 * i + 2] = pColors[i].nBlue;
            pPalette[4 * i + 3] = 0;
        }
    }

    return 1;
}


// 0x006C6990
static int __stdcall DecodePcxMem(int* pWidth, const unsigned char* pData, int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pHeight, int* pBitDepth)
{
    const int nWidth = *(const unsigned short*)(pData + 8) - *(const unsigned short*)(pData + 4) + 1;
    const int nHeight = *(const unsigned short*)(pData + 0x0A) - *(const unsigned short*)(pData + 6) + 1;
    const int nBits = pData[3] * pData[0x41];

    if (pWidth)
    {
        *pWidth = nWidth;
    }

    if (pHeight)
    {
        *pHeight = nHeight;
    }

    if (pBitDepth)
    {
        *pBitDepth = nBits;
    }

    if (pPixels)
    {
        unsigned int nLimit = (nBits + 7) / 8 * nHeight * nWidth;
        if (nPixelsSize < nLimit)
        {
            nLimit = nPixelsSize;
        }

        UncompressPcxImage(pPixels, nLimit, pData + 0x80, nDataSize - (nBits == 8 ? 0x301 : 0) - 0x80, nWidth, *(const unsigned short*)(pData + 0x42), pData[0x41]);
    }

    if (pPalette && nBits == 8)
    {
        const unsigned char* pColors = pData + nDataSize - 0x300;
        for (int i = 0; i < 256; ++i)
        {
            pPalette[4 * i + 0] = pColors[3 * i + 0];
            pPalette[4 * i + 1] = pColors[3 * i + 1];
            pPalette[4 * i + 2] = pColors[3 * i + 2];
            pPalette[4 * i + 3] = 0;
        }
    }

    return 1;
}

// 0x006C6A80
int __stdcall SBmpDecodeImage(int nType, const unsigned char* pData, unsigned int nDataSize, unsigned char* pPalette, unsigned char* pPixels, unsigned int nPixelsSize, int* pWidth, int* pHeight, int* pBitDepth)
{
    if (pWidth)
        *pWidth = 0;
    if (pHeight)
        *pHeight = 0;
    if (pBitDepth)
        *pBitDepth = 0;

    VALIDATEBEGIN;
    VALIDATE(pData);
    VALIDATE(nDataSize);
    VALIDATE(nPixelsSize || !pPixels);
    VALIDATEEND;

    if (!nType && nDataSize >= 2)
    {
        nType = GetImageType(*(const unsigned short*)pData);
    }

    switch (nType)
    {
    case 1:
        return DecodeBmpMem(pWidth, pHeight, (unsigned int*)pBitDepth, pData, pPalette, pPixels, nPixelsSize);
    case 2:
        return DecodePcxMem(pWidth, pData, nDataSize, pPalette, pPixels, nPixelsSize, pHeight, pBitDepth);
    case 3:
        return DecodeTgaMem((const D2TgaFieldsStrc*)pData, nDataSize, (D2PaletteColorStrc*)pPalette, pPixels, nPixelsSize, pWidth, pHeight, pBitDepth);
    }

    return 0;
}

// 0x006C6B70
int __stdcall SBmpLoadImage(const char* filename,unsigned char* palette,unsigned char* pixels,unsigned int bufferSize,int* width,int* height,int* bits)
{
 if(width)*width=0;
 if(height)*height=0;
 if(bits)*bits=0;
 int valid=((__int64)filename)?-1:0;
 valid &= (*filename)?-1:0;
 const unsigned int capacity=bufferSize;
 valid &= (capacity||!pixels)?-1:0;
 if(!valid){sub_0041C340_SetLastError(87);return 0;}
 void* hFile;
 if(!SFileOpenFile(filename,&hFile))return 0;
 int type=0;
 if(SFileReadFile(hFile,&bufferSize,2,0,0))
 {
  SFileSetFilePointer(hFile,-2,0,1);
  type=GetImageType((unsigned short)bufferSize);
 }
 int result=0;
 switch(type)
 {
 case 1:result=DecodeBmpFile(palette,hFile,width,pixels,capacity,height,bits);break;
 case 2:result=DecodePcxFile(hFile,palette,pixels,capacity,width,height,bits);break;
 case 3:result=DecodeTgaFile(hFile,(D2PaletteColorStrc*)palette,pixels,(unsigned int*)width,capacity,(unsigned int*)height,(unsigned int*)bits);break;
 }
 SFileCloseFile(hFile);
 return result;
}

// 0x006C6CB0
int __stdcall SBmpSaveImageEx(char* szFile, unsigned char* pPalette, unsigned char* pPixels, int nWidth, int nHeight, int nBits, int nPitch)
{
    VALIDATEBEGIN;
    VALIDATE(szFile);
    VALIDATE(*szFile);
    VALIDATE(nBits != 8 || pPalette);
    VALIDATE(pPixels);
    VALIDATE(nWidth > 0);
    VALIDATE(nHeight > 0);
    VALIDATEEND;

    const char* pExtension = FindFileExtension(szFile);
    if (pExtension && !_stricmp(pExtension, gszTga))
    {
        if (nBits != 8 && nBits != 24 && nBits != 32)
        {
            return 0;
        }
    }
    else if (nBits != 8)
    {
        return 0;
    }

    if (!nPitch)
    {
        nPitch = (nBits + 7) / 8 * nWidth;
    }

    void* hFile = CreateFileA(szFile, 0x40000000, 0, 0, 2, 0x80, 0);
    if (hFile == (void*)-1)
    {
        return 0;
    }

    if (pExtension)
    {
        if (!_stricmp(pExtension, gszPcx))
        {
            const int nResult = EncodePcx256File(nWidth, nHeight, hFile, (D2PaletteStrc*)pPalette, pPixels);
            CloseHandle(hFile);
            return nResult;
        }

        if (!_stricmp(pExtension, gszGif))
        {
            const int nResult = EncodeGif256File(hFile, (const RGBQuad*)pPalette, pPixels, nWidth, nHeight);
            CloseHandle(hFile);
            return nResult;
        }

        if (!_stricmp(pExtension, gszTga))
        {
            const int nResult = EncodeTgaFile(hFile, pPixels, (const D2TgaSourceColorStrc*)pPalette, nWidth, nHeight, nBits, nPitch);
            CloseHandle(hFile);
            return nResult;
        }
    }

    const int nResult = EncodeBmp256File(hFile, (const D2PaletteEntry*)pPalette, pPixels, nWidth, nHeight);
    CloseHandle(hFile);
    return nResult;
}

// 0x006C6E70
int __stdcall SBmpAllocLoadImage(const char* szFileName, D2PaletteColorStrc* pPalette, unsigned char** ppBuffer, int* pWidth, int* pHeight, int* pBitDepth, int nRequestedBitDepth, SBMPALLOCPROC pfAlloc)
{
    if (ppBuffer)
        *ppBuffer = 0;
    if (pWidth)
        *pWidth = 0;
    if (pHeight)
        *pHeight = 0;
    if (pBitDepth)
        *pBitDepth = 0;

    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATE(*szFileName);
    VALIDATE(ppBuffer);
    VALIDATEEND;

    void* hFile;
    if (!nValid || !SFileOpenFile(szFileName, &hFile))
        return 0;

    unsigned int nFileSize = SFileGetFileSize(hFile, 0);
    unsigned char* pFileData = (unsigned char*)SMemAlloc(nFileSize, ".\\SOURCE\\SBMP.CPP", 0x5B6, 0);
    SFileReadFile(hFile, pFileData, nFileSize, 0, 0);
    SFileCloseFile(hFile);

    int bResult = 0;
    int nWidth;
    int nHeight;
    int nBitDepth;
    if (SBmpDecodeImage(0, pFileData, nFileSize, 0, 0, 0, &nWidth, &nHeight, &nBitDepth))
    {
        if (!nRequestedBitDepth)
            nRequestedBitDepth = nBitDepth;
        else if (nRequestedBitDepth != nBitDepth)
            goto done;

        int nBufferSize = nWidth * nHeight * nRequestedBitDepth / 8;
        if (pfAlloc)
            *ppBuffer = (unsigned char*)pfAlloc(nBufferSize);
        else
            *ppBuffer = (unsigned char*)SMemAlloc(nBufferSize, szFileName, -4, 0);

        if (*ppBuffer)
        {
            SBmpDecodeImage(0, pFileData, nFileSize, (unsigned char*)pPalette, *ppBuffer, nBufferSize, 0, 0, 0);
            if (pWidth)
                *pWidth = nWidth;
            if (pHeight)
                *pHeight = nHeight;
            if (pBitDepth)
                *pBitDepth = nRequestedBitDepth;
            bResult = 1;
        }
    }

done:
    SMemFree(pFileData, ".\\SOURCE\\SBMP.CPP", 0x5F3, 0);
    return bResult;
}

// 0x006C7000
int __stdcall SBmpSaveImage(char* szFile, unsigned char* pPalette, unsigned char* pPixels, int nWidth, int nHeight, int nBits)
{
    return SBmpSaveImageEx(szFile, pPalette, pPixels, nWidth, nHeight, nBits, 0);
}

extern "C" const char gData_006FCC6C[8] = ".gif"; // 0x006FCC6C
#pragma comment(linker, "/alternatename:?gszGif_006FCC6C@@3QBDB=_gData_006FCC6C")

extern "C" const char gData_006FCC74[8] = ".pcx"; // 0x006FCC74
#pragma comment(linker, "/alternatename:?gszPcx_006FCC74@@3QBDB=_gData_006FCC74")

extern "C" const char gData_006FCC7C[8] = ".tga"; // 0x006FCC7C
#pragma comment(linker, "/alternatename:?gszTga_006FCC7C@@3QBDB=_gData_006FCC7C")
