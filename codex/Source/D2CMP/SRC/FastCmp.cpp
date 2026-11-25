#include "D2CMP.h"

#include "D2CmpTypes.h"

#include "D2CmpTiles.h"

#include "D2CelDataHash.h"

#include "D2ColorBlock.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2GfxCellStrc;

struct D2CmpTileInfoStrc;

struct D2CmpTileStrc;

struct D2CmpTileListStrc;

struct D2CelDataHashEntryStrc;

struct D2CelDataHashStrc;

struct D2CmpBitCursorStrc;

struct D2CmpStringStrc;

struct D2CelStrc;

struct D2CellFileStrc;

struct D2CmpColorStrc;

struct D2CmpCellNodeStrc;

struct D2CmpCellListStrc;

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __stdcall D2CMPGetFindTile(void* pData); // 0x00600760

void __fastcall sub_005179A4_FreeVirtualMemory(void* pMemory); // 0x005179A4

void __stdcall PaletteBuildAdditiveTable(unsigned char* pData); // 0x006059B0

extern unsigned int gdwSwappedColor; // 0x008E9D38

extern int gbPaletteTestBackground; // 0x008E9028

extern int gnGlobal_008E9D3C; // 0x008E9D3C

extern unsigned char gabPaletteMask[0x100]; // 0x008E9830

extern int gbTableSet; // 0x008E9D40

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590

D2CmpTileStrc* __cdecl TileAlloc(); // 0x00609550

struct D2CmpStringStrc
{
    const char* szText;

    int EqualsNoCase(const D2CmpStringStrc* pOther); // 0x0060DD20
};

int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0

extern "C" void __cdecl _chkstk(); // 0x006831B0

extern "C" void __cdecl _ftol2_sse(); // 0x00682FD0

int ganRemapStart[80]; // 0x008E9D48

int ganRemapEnd[80]; // 0x008E9E88

int ganRemapOffsets[80 * 80]; // 0x008E9FC8

struct D2CelStrc { unsigned int flags,width,height; unsigned char unknown0C[0x14]; unsigned char pixels[1]; };

extern const char gszEmptyAssert[]; // 0x006CC837

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall sub_0060D280_ScanSameRun(const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D280

int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd); // 0x0060D3A0

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

struct D2CmpCellNodeStrc
{
    D2CmpCellNodeStrc* pPrev;
    D2CmpCellNodeStrc* pNext;
    unsigned int dwFlags;
    unsigned int dwWidth;
    unsigned int dwHeight;
    unsigned int unk0x14;
    int nXOffset;
    int nYOffset;
    const unsigned char* pPixels;
};

struct D2CmpCellListStrc
{
    char unk0x00[0x18];
    unsigned int dwFlags;
    char unk0x1C[0x08];
    unsigned int nCells;
    unsigned int nDirections;
    char unk0x2C[0x08];
    D2CmpCellNodeStrc* pHead;
};

int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections); // 0x00600C90

#define BLEND_PIXEL(i) pDst[i] = pBlend[(pDst[i] << 8) + pTrans[pSrc[i]]]

typedef unsigned char BYTE;

extern int gnGenericRle_008F03C8; // 0x008F03C8

const unsigned char* __fastcall CelSkipRleLines(const unsigned char*,int); // 0x00606D10

void __fastcall CelDrawRleCopy(const unsigned char*,unsigned char*,int,int); // 0x00606D40

void __fastcall CelDrawRleCopyClipped(const unsigned char*,unsigned char*,int,int,int,int,int); // 0x00606DA0

void __fastcall CelDrawRleLightBlend(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00606E40

void __fastcall CelDrawRleLightBlendClipped(const unsigned char*,unsigned char*,int,int,int,int,int,const unsigned char*,const unsigned char*); // 0x00607060

void __fastcall CelDrawRleLightShift(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x006072F0

void __fastcall CelDrawRleLightShiftClipped(const unsigned char* source, unsigned char* destination, int rows, int pitch, int x, int left, int right, const unsigned char* outer, const unsigned char* inner); // 0x00607480

void __fastcall CelDrawRleLight(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607680

void __fastcall CelDrawRleLightClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable); // 0x006077C0

void __fastcall CelDrawRleShiftBlend(const unsigned char*,unsigned char*,int,int,const unsigned char*,const unsigned char*); // 0x00607970

void __fastcall CelDrawRleShiftBlendClipped(const BYTE* pSrc, BYTE* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const BYTE* pTrans, const BYTE* pBlend); // 0x00607B90

void __fastcall CelDrawRleShift(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00607E20

void __fastcall CelDrawRleShiftClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable); // 0x00607F60

void __fastcall CelDrawRleBlend(const unsigned char*,unsigned char*,int,int,const unsigned char*); // 0x00608110

void __fastcall CelDrawRleBlendClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pBlend); // 0x006082E0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

int gnGenericRle; // 0x008F03C8

static void __stdcall CelEncodeRle(const unsigned char* pSrc, unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize);

#define PAL_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2HslStrc;

struct D2PalRgbaStrc;

struct D2ColorBlockStrc;

extern unsigned char gaPcxPalette[256 * 4]; // 0x008E9938

typedef unsigned char (__stdcall* MapFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

unsigned char __stdcall Palette24BitTo8BitPixel(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x006056D0

extern int gbPaletteLoaded; // 0x008E9934

unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210

extern const D2ColorBlockStrc gtColorBlock; // 0x007434D8

double __stdcall PaletteHueToRgb(double n1, double n2, double hue); // 0x00604FE0

void __stdcall PaletteBuildTintTables(unsigned char* pData); // 0x00605D20

void __stdcall sub_00605DE0_BuildDarkenTables(unsigned char* pData); // 0x00605DE0

void __stdcall sub_00605E60_BuildLightenTables(unsigned char* pData); // 0x00605E60

void* __fastcall sub_00517993_VirtualAlloc(unsigned int nSize);

void __stdcall PaletteBuildAlphaTables(unsigned char* pTables); // 0x00605880

void __stdcall PaletteBuildAdditiveTable(unsigned char* pData); // 0x006059B0

void __stdcall sub_00605AA0_BuildTablesC(unsigned char* pTables);

void __stdcall sub_00605B70_BuildTablesD(unsigned char* pTables);

void __stdcall sub_00605F00_BuildTablesE(unsigned char* pTables, D2HslStrc* pHsl);

extern unsigned int gnPaletteStart; // 0x008E9930

extern unsigned int gnPaletteEnd; // 0x008E902C

extern int ganSquareTable[511]; // 0x008E9034

extern int gbDarkTest; // 0x008E9D3C

void __stdcall sub_00605AA0_BuildMultiplyTable(unsigned char* pTables); // 0x00605AA0

void __stdcall sub_00605B70_BuildBlendTables(unsigned char* pData); // 0x00605B70

void* __stdcall CreateD2Palette(void* pSource); // 0x00606930

#define PAL_SATURATE(x) ((unsigned int)(x) < 255 ? (x) : 255)

extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC

struct D2PcxRgbStrc
{
    unsigned char nR;
    unsigned char nG;
    unsigned char nB;
};

struct D2PcxPaletteStrc
{
    unsigned char f_0;
    D2PcxRgbStrc aColors[256];
};

unsigned int gnPaletteStart; // 0x008E9930

unsigned int gnPaletteEnd; // 0x008E902C

int gbTableSet; // 0x008E9D40

unsigned char gabPaletteMask[0x100]; // 0x008E9830

int gbPaletteTestBackground; // 0x008E9028

unsigned int gdwSwappedColor; // 0x008E9D38

int ganSquareTable[511]; // 0x008E9034

int gbDarkTest; // 0x008E9D3C

static void sub_00604DF0_RgbToHsl(const unsigned char* pRgb, D2HslStrc* pHsl)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        const double dRed = pRgb[0] / 255.0;
        const double dGreen = pRgb[1] / 255.0;
        const double dBlue = pRgb[2] / 255.0;
        double dMax = dRed > dGreen ? dRed : dGreen;
        if (dBlue > dMax)
        {
            dMax = dBlue;
        }

        double dMin = dRed < dGreen ? dRed : dGreen;
        if (dBlue < dMin)
        {
            dMin = dBlue;
        }

        const double dLightness = (dMax + dMin) * 0.5;
        double dHue = 0.0;
        double dSaturation = 0.0;
        if (dMax != dMin)
        {
            const double dDelta = dMax - dMin;
            dSaturation = dLightness <= 0.5 ? dDelta / (dMax + dMin) : dDelta / (2.0 - dMax - dMin);
            if (dRed == dMax)
            {
                dHue = (dGreen - dBlue) / dDelta;
            }
            else if (dGreen == dMax)
            {
                dHue = (dBlue - dRed) / dDelta + 2.0;
            }
            else
            {
                dHue = (dRed - dGreen) / dDelta + 4.0;
            }

            dHue *= 60.0;
            if (dHue < 0.0)
            {
                dHue += 360.0;
            }
        }

        pHsl->dHue = dHue;
        pHsl->dSaturation = dSaturation;
        pHsl->dLightness = dLightness;
        pRgb += 4;
        ++pHsl;
    }
}

// 0x00604DB0
double __stdcall PaletteMaxComponent(double a, double b)
{
    return a > b ? a : b;
}

// 0x00604DD0
double __stdcall PaletteMinComponent(double a, double b)
{
    return a < b ? a : b;
}

// 0x00604DF0
void __fastcall sub_00604DF0_PaletteToHSL(D2HslStrc* pHSL, const unsigned char* pPalette)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        double dLightness;
        const double dRed = pPalette[0] / 255.0;
        const double dGreen = pPalette[1] / 255.0;
        const double dBlue = pPalette[2] / 255.0;
        const double dMax = PaletteMaxComponent(dRed, PaletteMaxComponent(dGreen, dBlue));
        const double dMin = PaletteMinComponent(dRed, PaletteMinComponent(dGreen, dBlue));
        dLightness = (dMax + dMin) / 2.0;
        D2_ASSERT(dLightness >= 0.0 && dLightness <= 1.0, 63);

        if (dMax == dMin)
        {
            pHSL->dHue = 0.0;
            pHSL->dSaturation = 0.0;
            pHSL->dLightness = dLightness;
        }
        else
        {
            const double dDelta = dMax - dMin;
            double dSaturation;
            if (dLightness <= 0.5)
            {
                dSaturation = dDelta / (dMax + dMin);
            }
            else
            {
                dSaturation = dDelta / (2.0 - (dMax + dMin));
            }

            D2_ASSERT(dSaturation >= 0.0 && dSaturation <= 1.0, 77);

            double dHue;
            if (dRed == dMax)
            {
                dHue = (dGreen - dBlue) / dDelta;
            }
            else if (dGreen == dMax)
            {
                dHue = 2.0 + (dBlue - dRed) / dDelta;
            }
            else
            {
                dHue = 4.0 + (dRed - dGreen) / dDelta;
            }

            dHue *= 60.0;
            if (dHue < 0.0)
            {
                dHue += 360.0;
            }

            D2_ASSERT(dHue >= 0.0 && dHue < 360.0, 92);
            pHSL->dHue = dHue;
            pHSL->dSaturation = dSaturation;
            pHSL->dLightness = dLightness;
        }

        pPalette += 4;
        ++pHSL;
    }
}

// 0x00604FE0
double __stdcall PaletteHueToRgb(double n1, double n2, double hue)
{
    if (hue > 360.0)
        hue -= 360.0;
    if (hue < 0.0)
        hue += 360.0;
    if (hue < 60.0)
        return n1 + (n2 - n1) * hue / 60.0;
    if (hue < 180.0)
        return n2;
    if (hue < 240.0)
        return n1 + (n2 - n1) * (240.0 - hue) / 60.0;
    return n1;
}

// 0x00605080
static void sub_00605080_HslToRgb(const D2HslStrc* pHsl, D2PalRgbaStrc* pRgb)
{
    for (int i = 0; i < 256; ++i)
    {
        unsigned char nRed, nGreen, nBlue;
        if (pHsl->dSaturation == 0.0)
        {
            nRed = (unsigned char)(pHsl->dLightness * 255.0);
            nGreen = nRed;
            nBlue = nRed;
        }
        else
        {
            double dM2;
            if (pHsl->dLightness <= 0.5)
            {
                dM2 = (pHsl->dSaturation + 1.0) * pHsl->dLightness;
            }
            else
            {
                dM2 = pHsl->dLightness + pHsl->dSaturation - pHsl->dLightness * pHsl->dSaturation;
            }

            const double dM1 = pHsl->dLightness + pHsl->dLightness - dM2;
            nRed = (unsigned char)(PaletteHueToRgb(dM1, dM2, pHsl->dHue + 120.0) * 255.0);
            nGreen = (unsigned char)(PaletteHueToRgb(dM1, dM2, pHsl->dHue) * 255.0);
            nBlue = (unsigned char)(PaletteHueToRgb(dM1, dM2, pHsl->dHue - 120.0) * 255.0);
        }

        pRgb->nRed = nRed;
        pRgb->nGreen = nGreen;
        pRgb->nBlue = nBlue;
        ++pRgb;
        ++pHsl;
    }
}

// 0x006051F0
void __stdcall DestroyD2Palette(void* pMemory)
{
    if (pMemory)
        sub_005179A4_FreeVirtualMemory(pMemory);
}

// 0x00605210
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2)
{
    unsigned int nBestDistance = 0xFFFFFFFF;
    unsigned int nBest = 0;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        const int nDelta0 = pPalette[i * 4 + 0] - nC0;
        const int nDelta1 = pPalette[i * 4 + 1] - nC1;
        const int nDelta2 = pPalette[i * 4 + 2] - nC2;
        const unsigned int nDistance = nDelta2 * nDelta2 + nDelta1 * nDelta1 + nDelta0 * nDelta0;
        if (nDistance < nBestDistance)
        {
            nBest = i;
            nBestDistance = nDistance;
        }
    }
    return (unsigned char)nBest;
}

// 0x00605280
unsigned char __stdcall GetFurthestColor(unsigned char* pPalette, unsigned int nCount, int nRed, int nGreen, int nBlue)
{
    unsigned int nBest = 0;
    unsigned int nBestIndex = 0;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        const int d0 = pPalette[i * 4 + 0] - nRed;
        const int d1 = pPalette[i * 4 + 1] - nGreen;
        const int d2 = pPalette[i * 4 + 2] - nBlue;
        const unsigned int nDist = d0 * d0 + d1 * d1 + d2 * d2;
        if (nDist > nBest)
        {
            nBestIndex = i;
            nBest = nDist;
        }
    }
    return (unsigned char)nBestIndex;
}

// 0x006052F0
void __cdecl sub_006052F0_InitSquareTable()
{
    for (int i = -256; i < 256; ++i)
        gnSquareTableCenter_008E9430[i] = i * i;
}

// 0x00605320
void __stdcall PaletteSetTransparency(unsigned int nColor)
{
    unsigned char nLow = (unsigned char)nColor;
    unsigned char nMid = (unsigned char)(nColor >> 8);
    unsigned char nHigh = (unsigned char)(nColor >> 16);
    gdwSwappedColor = (((nLow << 8) | nMid) << 8) | nHigh;
}

// 0x00605340
int __fastcall sub_00605340_LoadPcxPalette(const char* szFileName)
{
    void* hFile = CreateFileA(szFileName, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        OutputDebugStringA("Unable to open ");
        OutputDebugStringA(szFileName);
// build: symbol ?gszNewline@* 0x006FFCB0
        OutputDebugStringA(gszNewline);
        return 0;
    }

    unsigned char header[128];
    memset(header, 0, sizeof(header));
    unsigned long nRead = 0;
    ReadFile(hFile, header, sizeof(header), &nRead, 0);
    if (nRead != sizeof(header) || header[0] != 0x0A || header[1] != 5 || header[3] != 8)
    {
        OutputDebugStringA("File is not a valid 256-color PCX file.\n");
        CloseHandle(hFile);
        return 0;
    }

    D2PcxPaletteStrc palette;
    memset(&palette, 0, sizeof(palette));
    SetFilePointer(hFile, -(long)sizeof(palette), 0, 2);
    ReadFile(hFile, &palette, sizeof(palette), &nRead, 0);
    if (nRead != sizeof(palette) || palette.f_0 != 0x0C)
    {
        OutputDebugStringA("Unable to extract palette from\n");
        CloseHandle(hFile);
        return 0;
    }

    for (unsigned int i = 0; i < 256; ++i)
    {
        gaPcxPalette[i * 4 + 0] = palette.aColors[i].nR;
        gaPcxPalette[i * 4 + 1] = palette.aColors[i].nG;
        gaPcxPalette[i * 4 + 2] = palette.aColors[i].nB;
    }

    CloseHandle(hFile);
    return 1;
}

// 0x006056C0
void __stdcall PaletteTestBackground(int nValue)
{
    gbPaletteTestBackground = nValue;
}

// 0x006056D0
unsigned char __stdcall Palette24BitTo8BitPixel(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    unsigned int nBestDistance = 0x7FFFFFFF;
    unsigned int nBestIndex = 0;
    for (unsigned int i = gnPaletteStart; i <= gnPaletteEnd; ++i)
    {
        if (gbTableSet && !gabPaletteMask[i])
        {
            continue;
        }

        if (gbPaletteTestBackground && gdwSwappedColor == ((((nRed << 8) | nGreen) << 8) | nBlue))
        {
            nBestIndex = 0;
            break;
        }

        unsigned int nDistance = ganSquareTable[nRed - gaPcxPalette[i * 4 + 2] + 255]
            + ganSquareTable[nGreen - gaPcxPalette[i * 4 + 1] + 255]
            + ganSquareTable[nBlue - gaPcxPalette[i * 4] + 255];
        if (nDistance < nBestDistance)
        {
            nBestDistance = nDistance;
            nBestIndex = i;
        }
    }

    return (unsigned char)nBestIndex;
}

// 0x006057A0
int __stdcall Palette24BitTo8BitImage(const unsigned char* pSource, unsigned char* pDest, unsigned int nCount, MapFn pfnMap)
{
    const unsigned char* pSrc = pSource;
    unsigned char* pDst = pDest;
    if (gbPaletteLoaded)
    {
        MapFn pfn = !pfnMap ? Palette24BitTo8BitPixel : pfnMap;

        for (unsigned int i = 0; i < nCount; ++i)
        {
            unsigned char nRed = *pSrc++;
            unsigned char nGreen = *pSrc++;
            unsigned char nBlue = *pSrc++;
            if (gbDarkTest && nRed <= 10 && nGreen <= 10 && nBlue <= 10)
            {
                nRed = 4;
                nBlue = 0;
                nGreen = 0;
            }

            *pDst++ = pfn(nRed, nGreen, nBlue);
        }
    }

    return 0;
}

// 0x00605840
void __stdcall PaletteFixBlack(int nValue)
{
    gnGlobal_008E9D3C = nValue;
}

// 0x00605850
void __stdcall PaletteSetMask(const unsigned char* pTable)
{
    memcpy(gabPaletteMask, pTable, 0x100);
    gbTableSet = 1;
}

// 0x00605880
void __stdcall PaletteBuildAlphaTables(unsigned char* pTables)
{
    unsigned int n = 0;
    if (3 > n)
    {
        do
        {
            int i = 0;
            int nAlpha;
            switch (n)
            {
            case 0:
                nAlpha = 0xBF;
                break;

            case 1:
                nAlpha = 0x7F;
                break;

            default:
                nAlpha = 0x3F;
                break;
            }

            const int nInverse = 0xFF - nAlpha;
            while (i < 256)
            {
                for (int j = 0; 256 > j; ++j)
                {
                    pTables[0x3500 + (n << 16) + j * 256 + i] = GetClosestColor(pTables, 256,
                        (unsigned char)((unsigned int)(pTables[j * 4 + 0] * nInverse + pTables[i * 4 + 0] * nAlpha) / 255),
                        (unsigned char)((unsigned int)(pTables[j * 4 + 1] * nInverse + pTables[i * 4 + 1] * nAlpha) / 255),
                        (unsigned char)((unsigned int)(pTables[j * 4 + 2] * nInverse + pTables[i * 4 + 2] * nAlpha) / 255));
                }
                ++i;
            }
            ++n;
        } while (n < 3);
    }
}

// 0x006059B0
void __stdcall PaletteBuildAdditiveTable(unsigned char* pTables)
{
    const D2PalRgbaStrc* pPalette = (const D2PalRgbaStrc*)pTables;
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            const unsigned char nR = (unsigned char)PAL_SATURATE(pPalette[j].nRed + pPalette[i].nRed);
            const unsigned char nG = (unsigned char)PAL_SATURATE(pPalette[j].nGreen + pPalette[i].nGreen);
            const unsigned char nB = (unsigned char)PAL_SATURATE(pPalette[j].nBlue + pPalette[i].nBlue);
            pTables[0x33500 + j * 256 + i] = GetClosestColor(pTables, 256, nR, nG, nB);
        }
    }
}

// 0x00605A90
void __stdcall UpdateD2TransparencyTable(unsigned char* pData, int nUnused)
{
    PaletteBuildAdditiveTable(pData);
}

// 0x00605AA0
void __stdcall sub_00605AA0_BuildMultiplyTable(unsigned char* pTables)
{
    const D2PalRgbaStrc* pPalette = (const D2PalRgbaStrc*)pTables;
    for (int i = 0; i < 256; ++i)
    {
        for (int j = 0; j < 256; ++j)
        {
            pTables[0x43500 + j * 256 + i] = GetClosestColor(pTables, 256,
                (unsigned char)((unsigned int)(pPalette[j].nRed * pPalette[i].nRed) / 255),
                (unsigned char)((unsigned int)(pPalette[j].nGreen * pPalette[i].nGreen) / 255),
                (unsigned char)((unsigned int)(pPalette[j].nBlue * pPalette[i].nBlue) / 255));
        }
    }
}

// 0x00605B70
void __stdcall sub_00605B70_BuildBlendTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        unsigned char nC0 = pData[i * 4 + 0];
        unsigned char nC1 = pData[i * 4 + 1];
        unsigned char nC2 = pData[i * 4 + 2];

        if (nC0 > 0)
        {
            nC0 += nC0 / -3;
        }

        if (nC2 > 0)
        {
            nC2 += nC2 / -3;
        }

        if (nC1 > 0)
        {
            nC1 += nC1 / -3;
        }

        pData[0x6B500 + i] = GetClosestColor(pData, 256, nC0, nC1, nC2);
    }

    for (unsigned int j = 0; j < 256; ++j)
    {
        const unsigned int nMax = PAL_MAX(PAL_MAX(pData[j * 4 + 0], pData[j * 4 + 1]), pData[j * 4 + 2]);
        const unsigned int nInv = 255 - nMax;
        for (unsigned int k = 0; k < 256; ++k)
        {
            pData[0x5B500 + k * 256 + j] = GetClosestColor(pData, 256,
                (unsigned char)((pData[j * 4 + 0] * nMax + pData[k * 4 + 0] * nInv) / 255),
                (unsigned char)((pData[j * 4 + 1] * nMax + pData[k * 4 + 1] * nInv) / 255),
                (unsigned char)((pData[j * 4 + 2] * nMax + pData[k * 4 + 2] * nInv) / 255));
        }
    }
}

// 0x00605DE0
void __stdcall sub_00605DE0_BuildDarkenTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 32; ++i)
    {
        for (unsigned int j = 0; j < 256; ++j)
        {
            pData[0x400 + i * 256 + j] = GetClosestColor(pData, 256,
                pData[j * 4 + 0] * (i + 1) >> 5,
                pData[j * 4 + 1] * (i + 1) >> 5,
                pData[j * 4 + 2] * (i + 1) >> 5);
        }
    }
}

// 0x00605E60
void __stdcall sub_00605E60_BuildLightenTables(unsigned char* pData)
{
    for (unsigned int i = 0; i < 16; ++i)
    {
        for (unsigned int j = 0; j < 256; ++j)
        {
            pData[0x2400 + i * 256 + j] = GetClosestColor(pData, 256,
                pData[j * 4 + 0] + ((0xFF - pData[j * 4 + 0]) * (i + 1) >> 4),
                pData[j * 4 + 1] + ((0xFF - pData[j * 4 + 1]) * (i + 1) >> 4),
                pData[j * 4 + 2] + ((0xFF - pData[j * 4 + 2]) * (i + 1) >> 4));
        }
    }
}

// 0x00605F00
void __stdcall sub_00605F00_BuildTablesE(unsigned char* pTables, D2HslStrc* pHsl)
{
    D2PalRgbaStrc tRgb[256];
    D2HslStrc aHsl[256];
    unsigned int i;
    unsigned int j;
    unsigned int k;

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].dHue += dShift;
            if (aHsl[j].dHue > 360.0)
                aHsl[j].dHue -= 360.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x53500 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].dHue += dShift;
            if (aHsl[j].dHue > 360.0)
                aHsl[j].dHue -= 360.0;
            aHsl[j].dSaturation = 0.5;
            aHsl[j].dLightness -= 0.1f;
            if (aHsl[j].dLightness < 0.0)
                aHsl[j].dLightness = 0.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (k = 0; k < 256; ++k)
            pTables[0x54D00 + 0x100 * i + k] = GetClosestColor(pTables, 256, tRgb[k].nRed, tRgb[k].nGreen, tRgb[k].nBlue);
    }

    for (i = 0; i < 24; ++i)
    {
        const double dShift = (float)i * 15.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].dHue += dShift;
            if (aHsl[j].dHue > 360.0)
                aHsl[j].dHue -= 360.0;
            aHsl[j].dSaturation = 0.5;
            aHsl[j].dLightness += 0.2f;
            if (aHsl[j].dLightness > 1.0)
                aHsl[j].dLightness = 1.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x56500 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (j = 0; j < 256; ++j)
    {
        aHsl[j] = pHsl[j];
        aHsl[j].dSaturation = 0.0;
        aHsl[j].dLightness *= 0.5;
    }
    sub_00605080_HslToRgb(aHsl, tRgb);
    for (j = 0; j < 256; ++j)
        pTables[0x57D00 + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);

    for (j = 0; j < 256; ++j)
    {
        aHsl[j] = pHsl[j];
        aHsl[j].dSaturation = 0.0;
        aHsl[j].dLightness = (aHsl[j].dLightness + 0.2f) / 1.2f;
    }
    sub_00605080_HslToRgb(aHsl, tRgb);
    for (j = 0; j < 256; ++j)
        pTables[0x57E00 + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);

    for (i = 0; i < 24; ++i)
    {
        for (j = 0; j < 256; ++j)
        {
            if (pHsl[j].dHue > 45.0 && pHsl[j].dHue < 315.0)
            {
                aHsl[j] = pHsl[j];
                aHsl[j].dHue += (float)i * 15.0;
                if (aHsl[j].dHue > 360.0)
                    aHsl[j].dHue -= 360.0;
            }
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x57F00 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (i = 0; i < 12; ++i)
    {
        const double dHue = (float)i * 30.0;
        for (j = 0; j < 256; ++j)
        {
            aHsl[j] = pHsl[j];
            aHsl[j].dHue = dHue;
            aHsl[j].dSaturation = 1.0;
        }
        sub_00605080_HslToRgb(aHsl, tRgb);
        for (j = 0; j < 256; ++j)
            pTables[0x59800 + 0x100 * i + j] = GetClosestColor(pTables, 256, tRgb[j].nRed, tRgb[j].nGreen, tRgb[j].nBlue);
    }

    for (k = 0; k < 256; ++k)
    {
        const unsigned char nGrey = (unsigned char)sqrt((double)(pTables[4 * k + 1] * pTables[4 * k + 1] + pTables[4 * k] * pTables[4 * k] + pTables[4 * k + 2] * pTables[4 * k + 2]));
        pTables[0x5A400 + k] = GetClosestColor(pTables, 256, nGrey, 0, 0);
        pTables[0x5A500 + k] = GetClosestColor(pTables, 256, 0, nGrey, 0);
        pTables[0x5A600 + k] = GetClosestColor(pTables, 256, 0, 0, nGrey);
    }
}

// 0x00606890
static void sub_00606890_BuildBrightnessTable(unsigned char* pTables, D2HslStrc* pHsl)
{
    D2PalRgbaStrc tRgb[256];

    for (int i = 0; i < 256; ++i)
    {
        if (pHsl[i].dLightness != 0.0)
        {
            pHsl[i].dLightness += 0.2f;
            if (pHsl[i].dLightness > 1.0)
            {
                pHsl[i].dLightness = 1.0;
            }
        }
    }

    sub_00605080_HslToRgb(pHsl, tRgb);
    for (unsigned int i = 0; i < 256; ++i)
    {
        pTables[0x3400 + i] = GetClosestColor(pTables, 256, tRgb[i].nRed, tRgb[i].nGreen, tRgb[i].nBlue);
    }
}

// 0x00606930
void* __stdcall CreateD2Palette(void* pSource)
{
    D2HslStrc tHsl[256];

    D2_ASSERT(pSource, 683);
    unsigned char* pTables = (unsigned char*)sub_00517993_VirtualAlloc(0x6C327);
    memcpy(pTables, pSource, 0x400);
    sub_00604DF0_RgbToHsl(pTables, tHsl);
    PaletteBuildAlphaTables(pTables);
    sub_00605DE0_BuildDarkenTables(pTables);
    sub_00605E60_BuildLightenTables(pTables);
    PaletteBuildAdditiveTable(pTables);
    sub_00605AA0_BuildTablesC(pTables);
    sub_00605F00_BuildTablesE(pTables, tHsl);
    sub_00606890_BuildBrightnessTable(pTables, tHsl);
    sub_00605B70_BuildTablesD(pTables);
    *(D2ColorBlockStrc*)(pTables + 0x6B600) = gtColorBlock;
    PaletteBuildTintTables(pTables);
    return pTables;
}

// 0x00606A10
static void __stdcall CelEncodeRle(const unsigned char* pSrc, unsigned int nWidth, unsigned int nHeight, unsigned int dwFlags, unsigned char** ppOut, unsigned int* pnSize)
{
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc((2 * nWidth + 1) * nHeight, szFastCmpFile, 37, 0);
    int nStride;
    unsigned char* pOut = pBuffer;
    int nRestReachedEnd;
    int nRunReachedEnd;
    unsigned int nRow = 0;
    if (!(dwFlags & 1))
    {
        pSrc += (nHeight - 1) * nWidth;
        nStride = -(int)nWidth;
    }
    else
    {
        nStride = nWidth;
    }

    const unsigned char* pNextRow = pSrc + nStride;
    const unsigned char* pRowEnd = pSrc + nWidth;
    while (nRow < nHeight)
    {
        if (*pSrc == 0)
        {
            const int nRun = sub_0060D280_ScanSameRun(pSrc, pRowEnd, 0x7F, &nRunReachedEnd, &nRestReachedEnd);
            if (!nRestReachedEnd && !nRunReachedEnd)
            {
                *pOut++ = (unsigned char)(nRun | 0x80);
                pSrc += nRun;
            }
            else
            {
                pSrc = pNextRow;
                pNextRow += nStride;
                pRowEnd += nStride;
                *pOut++ = 0x80;
                ++nRow;
            }
        }
        else
        {
            const unsigned int nRun = sub_0060D3A0_ScanOtherRun(pSrc, pRowEnd, 0, 0x7F, &nRunReachedEnd, &nRestReachedEnd);
            *pOut++ = (unsigned char)nRun;
            for (unsigned int i = 0; i < nRun; ++i)
            {
                *pOut++ = *pSrc++;
            }

            if (nRunReachedEnd)
            {
                pSrc = pNextRow;
                pNextRow += nStride;
                pRowEnd += nStride;
                *pOut++ = 0x80;
                ++nRow;
            }
        }
    }

    *ppOut = pBuffer;
    *pnSize = pOut - pBuffer;
}

// 0x00606B00
void __fastcall CelRemapRlePixels(D2GfxCellStrc* pCell, const unsigned char* pRemap)
{
    int nRows = pCell->dwHeight;
    unsigned char* pData = pCell->pPixels;
    for (;;)
    {
        const char nCode = *pData++;
        if (nCode < 0)
        {
            if (!(nCode & 0x7F))
            {
                if (!--nRows)
                {
                    return;
                }
            }
        }
        else
        {
            for (int i = 0; i < nCode; ++i)
            {
                *pData = pRemap[*pData];
                ++pData;
            }
        }
    }
}

#pragma function(memcpy)

// 0x00606B50
void __fastcall CelFileConvertRle24To8(D2CellFileStrc* pSrcFile, D2CellFileStrc* pDstFile, D2CmpMapColorFn pfnMapColor, D2CmpColorStrc tTransparent)
{
    D2_ASSERT(pSrcFile->dwFlags & 4, 206);
    for (unsigned int i = 0; i < pSrcFile->nDirections * pSrcFile->nFrames; ++i)
    {
        const unsigned int nPixels = pSrcFile->pGfxCells[i]->dwHeight * pSrcFile->pGfxCells[i]->dwWidth;
        unsigned char* pIndexed = (unsigned char*)FOG_Alloc(nPixels, ".\\SRC\\FastCmp.cpp", 212, 0);
        const unsigned char* pRgb = pSrcFile->pGfxCells[i]->pPixels;
        unsigned char* pWrite = pIndexed;
        for (unsigned int j = 0; j < nPixels; ++j)
        {
            if (pRgb[0] == tTransparent.nRed && pRgb[1] == tTransparent.nGreen && pRgb[2] == tTransparent.nBlue)
            {
                *pWrite++ = 0;
            }
            else
            {
                const unsigned char nIndex = pfnMapColor(pRgb[0], pRgb[1], pRgb[2]);
                D2_ASSERT(nIndex, 224);
                *pWrite++ = nIndex;
            }

            pRgb += 3;
        }

        unsigned char* pRle;
        unsigned int nRleSize;
        CelEncodeRle(pIndexed, pSrcFile->pGfxCells[i]->dwWidth, pSrcFile->pGfxCells[i]->dwHeight, pSrcFile->pGfxCells[i]->dwFlags, &pRle, &nRleSize);
        FOG_Free(pIndexed, ".\\SRC\\FastCmp.cpp", 240, 0);

        D2GfxCellStrc* pNew = (D2GfxCellStrc*)FOG_Alloc(nRleSize + sizeof(D2GfxCellStrc) - 1, ".\\SRC\\FastCmp.cpp", 242, 0);
        pNew->dwFlags = pSrcFile->pGfxCells[i]->dwFlags;
        pNew->dwWidth = pSrcFile->pGfxCells[i]->dwWidth;
        pNew->dwHeight = pSrcFile->pGfxCells[i]->dwHeight;
        pNew->nXOffset = pSrcFile->pGfxCells[i]->nXOffset;
        pNew->nYOffset = pSrcFile->pGfxCells[i]->nYOffset;
        pNew->unk0x14 = 0;
        pNew->dwParent = 0;
        pNew->dwLength = nRleSize;
        memcpy(pNew->pPixels, pRle, nRleSize);
        FOG_Free(pRle, ".\\SRC\\FastCmp.cpp", 253, 0);
        pDstFile->pGfxCells[i] = pNew;
    }
}

#pragma intrinsic(memcpy)

// 0x00606D40
void __fastcall CelDrawRleCopy(const char* pSrc, char* pDst, int nLines, int nPitch)
{
    char* pNextLine = pDst + nPitch;
    while (1)
    {
        char nRun = *pSrc++;
        if (nRun < 0)
        {
            nRun &= 0x7F;
            if (!nRun)
            {
                if (--nLines == 0)
                    return;
                pDst = pNextLine;
                pNextLine += nPitch;
            }
            else
            {
                pDst += nRun;
            }
        }
        else
        {
            memcpy(pDst, pSrc, nRun);
            pSrc += nRun;
            pDst += nRun;
        }
    }
}

// 0x00606DA0
void __fastcall CelDrawRleCopyClipped(const char* pSrc, char* pDst, int nLines, int nPitch, int nX, int nClipLeft, int nClipRight)
{
    int nLineX = nX;
    char* pNextLine = pDst + nPitch;
    while (1)
    {
        char nRun = *pSrc++;
        if (nRun < 0)
        {
            nRun &= 0x7F;
            if (!nRun)
            {
                if (--nLines == 0)
                    return;
                pDst = pNextLine;
                nX = nLineX;
                pNextLine += nPitch;
            }
            else
            {
                nX += nRun;
                pDst += nRun;
            }
        }
        else
        {
            int nSkip = nClipLeft - nX;
            if (nSkip < 0)
                nSkip = 0;
            int nEnd = nClipRight - nX;
            if (nEnd > nRun)
                nEnd = nRun;
            int nCount = nEnd - nSkip;
            if (nCount > 0)
                memcpy(pDst + nSkip, pSrc + nSkip, nCount);
            pSrc += nRun;
            nX += nRun;
            pDst += nRun;
        }
    }
}

// 0x00606E40
void __fastcall CelDrawRleLightBlend(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pMap, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pMap[pSrc[7]]];
                pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
                pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
                pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
                pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
                pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
                pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
                pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607060
void __fastcall CelDrawRleLightBlendClipped(const unsigned char* source,unsigned char* destination,int rows,int pitch,int x,int left,int right,const unsigned char* map,const unsigned char* blend)
{
 int initialX=x;
 unsigned char* next=destination+pitch;
 for(;;){
  char code=*source++;
  if(code<0){
   code&=0x7f;
   if(!code){
    if(!--rows)return;
    x=initialX;destination=next;next+=pitch;
   }else{x+=code;destination+=code;}
   continue;
  }
  int skip=left-x;
  if(skip<0)skip=0;
  int end=right-x;
  if(end>code)end=code;
  int count=end-skip;
  if(count>0){
   const unsigned char* savedSource=source;
   unsigned char* savedDestination=destination;
   source+=skip;destination+=skip;
   count>>=3;
   int rest=(end-skip)&7;
   switch(rest){
    case 7: destination[6]=blend[(destination[6]<<8)+map[source[6]]];
    case 6: destination[5]=blend[(destination[5]<<8)+map[source[5]]];
    case 5: destination[4]=blend[(destination[4]<<8)+map[source[4]]];
    case 4: destination[3]=blend[(destination[3]<<8)+map[source[3]]];
    case 3: destination[2]=blend[(destination[2]<<8)+map[source[2]]];
    case 2: destination[1]=blend[(destination[1]<<8)+map[source[1]]];
    case 1: destination[0]=blend[(destination[0]<<8)+map[source[0]]];
    case 0:
     destination+=rest;source+=rest;
     while(count--){
      destination[7]=blend[(destination[7]<<8)+map[source[7]]];
      destination[6]=blend[(destination[6]<<8)+map[source[6]]];
      destination[5]=blend[(destination[5]<<8)+map[source[5]]];
      destination[4]=blend[(destination[4]<<8)+map[source[4]]];
      destination[3]=blend[(destination[3]<<8)+map[source[3]]];
      destination[2]=blend[(destination[2]<<8)+map[source[2]]];
      destination[1]=blend[(destination[1]<<8)+map[source[1]]];
      destination[0]=blend[(destination[0]<<8)+map[source[0]]];
      destination+=8;source+=8;
     }
   }
   x+=code;source=savedSource+code;destination=savedDestination+code;
  }else{
   x+=code;source+=code;destination+=code;
  }
 }
}

// 0x006072F0
void __fastcall CelDrawRleLightShift(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pOuter, const unsigned char* pInner)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pOuter[pInner[pSrc[6]]];
        case 6: pDst[5] = pOuter[pInner[pSrc[5]]];
        case 5: pDst[4] = pOuter[pInner[pSrc[4]]];
        case 4: pDst[3] = pOuter[pInner[pSrc[3]]];
        case 3: pDst[2] = pOuter[pInner[pSrc[2]]];
        case 2: pDst[1] = pOuter[pInner[pSrc[1]]];
        case 1: pDst[0] = pOuter[pInner[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pOuter[pInner[pSrc[7]]];
                pDst[6] = pOuter[pInner[pSrc[6]]];
                pDst[5] = pOuter[pInner[pSrc[5]]];
                pDst[4] = pOuter[pInner[pSrc[4]]];
                pDst[3] = pOuter[pInner[pSrc[3]]];
                pDst[2] = pOuter[pInner[pSrc[2]]];
                pDst[1] = pOuter[pInner[pSrc[1]]];
                pDst[0] = pOuter[pInner[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607480
void __fastcall CelDrawRleLightShiftClipped(const unsigned char* source, unsigned char* destination, int rows, int pitch, int x, int left, int right, const unsigned char* outer, const unsigned char* inner)
{
 int initialX=x;
 unsigned char* next=destination+pitch;
 for(;;){
  char code=*source++;
  if(code<0){
   code&=0x7f;
   if(!code){
    if(!--rows)return;
    x=initialX;destination=next;next+=pitch;
   }else{x+=code;destination+=code;}
   continue;
  }
  int skip=left-x;
  if(skip<0)skip=0;
  int end=right-x;
  if(end>code)end=code;
  int count=end-skip;
  if(count>0){
   const unsigned char* savedSource=source;
   unsigned char* savedDestination=destination;
   source+=skip;destination+=skip;
   count>>=3;
   switch((end-skip)&7){
    case 7: destination[6]=outer[inner[source[6]]];
    case 6: destination[5]=outer[inner[source[5]]];
    case 5: destination[4]=outer[inner[source[4]]];
    case 4: destination[3]=outer[inner[source[3]]];
    case 3: destination[2]=outer[inner[source[2]]];
    case 2: destination[1]=outer[inner[source[1]]];
    case 1: destination[0]=outer[inner[source[0]]];
    case 0:
     destination+=(end-skip)&7;source+=(end-skip)&7;
     if(count){
      do{
       destination[7]=outer[inner[source[7]]];
       destination[6]=outer[inner[source[6]]];
       destination[5]=outer[inner[source[5]]];
       destination[4]=outer[inner[source[4]]];
       destination[3]=outer[inner[source[3]]];
       destination[2]=outer[inner[source[2]]];
       destination[1]=outer[inner[source[1]]];
       destination[0]=outer[inner[source[0]]];
       --count;
       destination+=8;source+=8;
      }while(count);
     }
   }
   x+=code;source=savedSource+code;destination=savedDestination+code;
  }else{
   x+=code;source+=code;destination+=code;
  }
 }
}

// 0x00607680
void __fastcall CelDrawRleLight(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pTable)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pTable[pSrc[6]];
        case 6: pDst[5] = pTable[pSrc[5]];
        case 5: pDst[4] = pTable[pSrc[4]];
        case 4: pDst[3] = pTable[pSrc[3]];
        case 3: pDst[2] = pTable[pSrc[2]];
        case 2: pDst[1] = pTable[pSrc[1]];
        case 1: pDst[0] = pTable[pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pTable[pSrc[7]];
                pDst[6] = pTable[pSrc[6]];
                pDst[5] = pTable[pSrc[5]];
                pDst[4] = pTable[pSrc[4]];
                pDst[3] = pTable[pSrc[3]];
                pDst[2] = pTable[pSrc[2]];
                pDst[1] = pTable[pSrc[1]];
                pDst[0] = pTable[pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x006077C0
void __fastcall CelDrawRleLightClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable)
{
    const int nStartX = nX;
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                nX = nStartX;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
            continue;
        }
        int nSkip = nClipLeft - nX;
        if (nSkip < 0)
            nSkip = 0;
        int nCount = nClipRight - nX;
        if (nCount > nCode)
            nCount = nCode;
        nCount -= nSkip;
        if (nCount > 0)
        {
            int nBlocks = nCount >> 3;
            const unsigned char* pRunSource = pSrc;
            unsigned char* pRunDestination = pDst;
            pSrc += nSkip;
            pDst += nSkip;
            nCount &= 7;
            switch (nCount)
            {
            case 7: pDst[6] = pTable[pSrc[6]];
            case 6: pDst[5] = pTable[pSrc[5]];
            case 5: pDst[4] = pTable[pSrc[4]];
            case 4: pDst[3] = pTable[pSrc[3]];
            case 3: pDst[2] = pTable[pSrc[2]];
            case 2: pDst[1] = pTable[pSrc[1]];
            case 1: pDst[0] = pTable[pSrc[0]];
            case 0:
                pDst += nCount;
                pSrc += nCount;
                if (nBlocks)
                {
                    do
                    {
                        pDst[7] = pTable[pSrc[7]];
                        pDst[6] = pTable[pSrc[6]];
                        pDst[5] = pTable[pSrc[5]];
                        pDst[4] = pTable[pSrc[4]];
                        pDst[3] = pTable[pSrc[3]];
                        pDst[2] = pTable[pSrc[2]];
                        pDst[1] = pTable[pSrc[1]];
                        pDst[0] = pTable[pSrc[0]];
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    } while (nBlocks);
                }
            }
            nX += nCode;
            pSrc = pRunSource + nCode;
            pDst = pRunDestination + nCode;
            continue;
        }
        nX += nCode;
        pSrc += nCode;
        pDst += nCode;
    }
}

// 0x00607970
void __fastcall CelDrawRleShiftBlend(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pMap, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pMap[pSrc[7]]];
                pDst[6] = pBlend[(pDst[6] << 8) + pMap[pSrc[6]]];
                pDst[5] = pBlend[(pDst[5] << 8) + pMap[pSrc[5]]];
                pDst[4] = pBlend[(pDst[4] << 8) + pMap[pSrc[4]]];
                pDst[3] = pBlend[(pDst[3] << 8) + pMap[pSrc[3]]];
                pDst[2] = pBlend[(pDst[2] << 8) + pMap[pSrc[2]]];
                pDst[1] = pBlend[(pDst[1] << 8) + pMap[pSrc[1]]];
                pDst[0] = pBlend[(pDst[0] << 8) + pMap[pSrc[0]]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607B90
void __fastcall CelDrawRleShiftBlendClipped(const BYTE* pSrc, BYTE* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const BYTE* pTrans, const BYTE* pBlend)
{
    int nStartX = nX;
    BYTE* pLine = pDst + nPitch;

    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (--nRows == 0)
                {
                    return;
                }
                nX = nStartX;
                pDst = pLine;
                pLine += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
        }
        else
        {
            int nStart = nClipLeft - nX;
            if (nStart < 0)
            {
                nStart = 0;
            }
            int nEnd = nClipRight - nX;
            if (nEnd > nCode)
            {
                nEnd = nCode;
            }
            int nCount = nEnd - nStart;

            if (nCount > 0)
            {
                int nBlocks = nCount >> 3;
                const BYTE* pRunSrc = pSrc;
                BYTE* pRunDst = pDst;
                pSrc += nStart;
                pDst += nStart;
                int nRem = nCount & 7;
                switch (nRem)
                {
                case 7: BLEND_PIXEL(6);
                case 6: BLEND_PIXEL(5);
                case 5: BLEND_PIXEL(4);
                case 4: BLEND_PIXEL(3);
                case 3: BLEND_PIXEL(2);
                case 2: BLEND_PIXEL(1);
                case 1: BLEND_PIXEL(0);
                case 0:
                    pDst += nRem;
                    pSrc += nRem;
                    while (nBlocks)
                    {
                        BLEND_PIXEL(7);
                        BLEND_PIXEL(6);
                        BLEND_PIXEL(5);
                        BLEND_PIXEL(4);
                        BLEND_PIXEL(3);
                        BLEND_PIXEL(2);
                        BLEND_PIXEL(1);
                        BLEND_PIXEL(0);
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    }
                }
                nX += nCode;
                pSrc = pRunSrc + nCode;
                pDst = pRunDst + nCode;
            }
            else
            {
                nX += nCode;
                pSrc += nCode;
                pDst += nCode;
            }

        }
    }
}

// 0x00607E20
void __fastcall CelDrawRleShift(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pTable)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pTable[pSrc[6]];
        case 6: pDst[5] = pTable[pSrc[5]];
        case 5: pDst[4] = pTable[pSrc[4]];
        case 4: pDst[3] = pTable[pSrc[3]];
        case 3: pDst[2] = pTable[pSrc[2]];
        case 2: pDst[1] = pTable[pSrc[1]];
        case 1: pDst[0] = pTable[pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pTable[pSrc[7]];
                pDst[6] = pTable[pSrc[6]];
                pDst[5] = pTable[pSrc[5]];
                pDst[4] = pTable[pSrc[4]];
                pDst[3] = pTable[pSrc[3]];
                pDst[2] = pTable[pSrc[2]];
                pDst[1] = pTable[pSrc[1]];
                pDst[0] = pTable[pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x00607F60
void __fastcall CelDrawRleShiftClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pTable)
{
    const int nStartX = nX;
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                nX = nStartX;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
            continue;
        }
        int nSkip = nClipLeft - nX;
        if (nSkip < 0)
            nSkip = 0;
        int nCount = nClipRight - nX;
        if (nCount > nCode)
            nCount = nCode;
        nCount -= nSkip;
        if (nCount > 0)
        {
            int nBlocks = nCount >> 3;
            const unsigned char* pRunSource = pSrc;
            unsigned char* pRunDestination = pDst;
            pSrc += nSkip;
            pDst += nSkip;
            nCount &= 7;
            switch (nCount)
            {
            case 7: pDst[6] = pTable[pSrc[6]];
            case 6: pDst[5] = pTable[pSrc[5]];
            case 5: pDst[4] = pTable[pSrc[4]];
            case 4: pDst[3] = pTable[pSrc[3]];
            case 3: pDst[2] = pTable[pSrc[2]];
            case 2: pDst[1] = pTable[pSrc[1]];
            case 1: pDst[0] = pTable[pSrc[0]];
            case 0:
                pDst += nCount;
                pSrc += nCount;
                if (nBlocks)
                {
                    do
                    {
                        pDst[7] = pTable[pSrc[7]];
                        pDst[6] = pTable[pSrc[6]];
                        pDst[5] = pTable[pSrc[5]];
                        pDst[4] = pTable[pSrc[4]];
                        pDst[3] = pTable[pSrc[3]];
                        pDst[2] = pTable[pSrc[2]];
                        pDst[1] = pTable[pSrc[1]];
                        pDst[0] = pTable[pSrc[0]];
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    } while (nBlocks);
                }
            }
            nX += nCode;
            pSrc = pRunSource + nCode;
            pDst = pRunDestination + nCode;
            continue;
        }
        nX += nCode;
        pSrc += nCode;
        pDst += nCode;
    }
}

// 0x00608110
void __fastcall CelDrawRleBlend(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, const unsigned char* pBlend)
{
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                pDst += nCode;
            }
            continue;
        }
        int nCount = nCode;
        int nBlocks = nCount >> 3;
        int nRest = nCount & 7;
        switch (nRest)
        {
        case 7: pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
        case 6: pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
        case 5: pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
        case 4: pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
        case 3: pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
        case 2: pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
        case 1: pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
        case 0:
            pDst += nRest;
            pSrc += nRest;
            while (nBlocks)
            {
                pDst[7] = pBlend[(pDst[7] << 8) + pSrc[7]];
                pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
                pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
                pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
                pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
                pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
                pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
                pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
                --nBlocks;
                pDst += 8;
                pSrc += 8;
            }
        }
    }
}

// 0x006082E0
void __fastcall CelDrawRleBlendClipped(const unsigned char* pSrc, unsigned char* pDst, int nRows, int nPitch, int nX, int nClipLeft, int nClipRight, const unsigned char* pBlend)
{
    const int nStartX = nX;
    unsigned char* pNext = pDst + nPitch;
    for (;;)
    {
        char nCode = *pSrc++;
        if (nCode < 0)
        {
            nCode &= 0x7F;
            if (!nCode)
            {
                if (!--nRows)
                    return;
                nX = nStartX;
                pDst = pNext;
                pNext += nPitch;
            }
            else
            {
                nX += nCode;
                pDst += nCode;
            }
            continue;
        }
        int nSkip = nClipLeft - nX;
        if (nSkip < 0)
            nSkip = 0;
        int nCount = nClipRight - nX;
        if (nCount > nCode)
            nCount = nCode;
        nCount -= nSkip;
        if (nCount > 0)
        {
            int nBlocks = nCount >> 3;
            const unsigned char* pRunSource = pSrc;
            unsigned char* pRunDestination = pDst;
            pSrc += nSkip;
            pDst += nSkip;
            nCount &= 7;
            switch (nCount)
            {
            case 7: pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
            case 6: pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
            case 5: pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
            case 4: pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
            case 3: pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
            case 2: pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
            case 1: pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
            case 0:
                if (nBlocks)
                {
                    pDst += nCount;
                    pSrc += nCount;
                    do
                    {
                        pDst[7] = pBlend[(pDst[7] << 8) + pSrc[7]];
                        pDst[6] = pBlend[(pDst[6] << 8) + pSrc[6]];
                        pDst[5] = pBlend[(pDst[5] << 8) + pSrc[5]];
                        pDst[4] = pBlend[(pDst[4] << 8) + pSrc[4]];
                        pDst[3] = pBlend[(pDst[3] << 8) + pSrc[3]];
                        pDst[2] = pBlend[(pDst[2] << 8) + pSrc[2]];
                        pDst[1] = pBlend[(pDst[1] << 8) + pSrc[1]];
                        pDst[0] = pBlend[(pDst[0] << 8) + pSrc[0]];
                        --nBlocks;
                        pDst += 8;
                        pSrc += 8;
                    } while (nBlocks);
                }
            }
            nX += nCode;
            pSrc = pRunSource + nCode;
            pDst = pRunDestination + nCode;
            continue;
        }
        nX += nCode;
        pSrc += nCode;
        pDst += nCode;
    }
}

// build: symbol ?ERRORMANAGER_SetBasePathToCurrent@* 0x004067C0
int __cdecl ERRORMANAGER_SetBasePathToCurrent()
{
    return SFileSetBasePath(".\\");
}

void __cdecl sub_00413740_Nop()
{
}

// 0x00608520
int __cdecl D2CMPToggleCelDrawMode()
{
    return gnGenericRle = (gnGenericRle == 0);
}

// 0x00608540
void __fastcall CelDrawRle(D2CelStrc* pCel, unsigned char* pDest, int nX, int nLeft, int nRight, int nPitch, int nSkipRows, int nRows, const unsigned char* pMapA, const unsigned char* pBlend, const unsigned char* pMapB)
{
    const int nStartX = nX;
    const int nWidth = pCel->width;
    if ((unsigned int)nPitch < (unsigned int)nWidth)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1514);
        exit(-1);
    }
    if ((unsigned int)(nSkipRows + nRows) > pCel->height)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1515);
        exit(-1);
    }

    const unsigned char* pSrc = CelSkipRleLines(pCel->pixels, nSkipRows);
    const int nStride = (pCel->flags & 1) ? nPitch : -nPitch;

    if (gnGenericRle_008F03C8)
    {
        unsigned char* pNextRow = pDest + nStride;
        for (;;)
        {
            char nCode = *pSrc++;
            if (nCode < 0)
            {
                nCode &= 0x7F;
                if (!nCode)
                {
                    nX = nStartX;
                    pDest = pNextRow;
                    pNextRow += nStride;
                    if (!--nRows)
                        return;
                }
                else
                {
                    nX += nCode;
                    pDest += nCode;
                }
                continue;
            }

            const int nRun = nCode;
            const unsigned char* pSrcEnd = pSrc + nRun;
            unsigned char* pDestEnd = pDest + nRun;
            int nCount = nRun;
            if (nLeft || nRight)
            {
                const int nSkip = D2_MAX(nLeft - nX, 0);
                int nEnd = D2_MAX(nRight - nX, 0);
                nEnd = D2_MIN(nEnd, nRun);
                nCount = nEnd - nSkip;
                if (nCount <= 0)
                {
                    nCount = 0;
                }
                else
                {
                    pDest += nSkip;
                    pSrc += nSkip;
                }
            }

            const unsigned char* pSrcStop = pSrc + nCount;
            if (pMapA)
            {
                if (pBlend)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pBlend[pMapA[*pSrc] + (*pDest << 8)];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else if (pMapB)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapA[pMapB[*pSrc]];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapA[*pSrc];
                        ++pSrc;
                        ++pDest;
                    }
                }
            }
            else if (pMapB)
            {
                if (pBlend)
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pBlend[pMapB[*pSrc] + (*pDest << 8)];
                        ++pSrc;
                        ++pDest;
                    }
                }
                else
                {
                    while (pSrc < pSrcStop)
                    {
                        *pDest = pMapB[*pSrc];
                        ++pSrc;
                        ++pDest;
                    }
                }
            }
            else if (pBlend)
            {
                while (pSrc < pSrcStop)
                {
                    *pDest = pBlend[*pSrc + (*pDest << 8)];
                    ++pSrc;
                    ++pDest;
                }
            }
            else
            {
                while (pSrc < pSrcStop)
                {
                    *pDest = *pSrc;
                    ++pSrc;
                    ++pDest;
                }
            }

            nX += nRun;
            pSrc = pSrcEnd;
            pDest = pDestEnd;
        }
    }

    const int bUnclipped = (!nLeft && !nRight) || (nX >= nLeft && nX + nWidth < nRight);
    if (pMapA)
    {
        if (pBlend)
        {
            if (bUnclipped)
                CelDrawRleLightBlend(pSrc, pDest, nRows, nStride, pMapA, pBlend);
            else
                CelDrawRleLightBlendClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA, pBlend);
        }
        else if (pMapB)
        {
            if (bUnclipped)
                CelDrawRleLightShift(pSrc, pDest, nRows, nStride, pMapA, pMapB);
            else
                CelDrawRleLightShiftClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA, pMapB);
        }
        else
        {
            if (bUnclipped)
                CelDrawRleLight(pSrc, pDest, nRows, nStride, pMapA);
            else
                CelDrawRleLightClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapA);
        }
    }
    else if (pMapB)
    {
        if (pBlend)
        {
            if (bUnclipped)
                CelDrawRleShiftBlend(pSrc, pDest, nRows, nStride, pMapB, pBlend);
            else
                CelDrawRleShiftBlendClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB, pBlend);
        }
        else
        {
            if (bUnclipped)
                CelDrawRleShift(pSrc, pDest, nRows, nStride, pMapB);
            else
                CelDrawRleShiftClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pMapB);
        }
    }
    else if (pBlend)
    {
        if (bUnclipped)
            CelDrawRleBlend(pSrc, pDest, nRows, nStride, pBlend);
        else
            CelDrawRleBlendClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight, pBlend);
    }
    else
    {
        if (bUnclipped)
            CelDrawRleCopy(pSrc, pDest, nRows, nStride);
        else
            CelDrawRleCopyClipped(pSrc, pDest, nRows, nStride, nX, nLeft, nRight);
    }
}

// 0x006089F0
void __fastcall CmpBuildLensRemap(int nPitch)
{
    int aInside[80][80];

    for (int y = 0; y < 80; ++y)
    {
        for (int x = 0; x < 80; ++x)
        {
            int nDX = x - 40;
            int nNewX = nDX;
            int nDY = y - 40;
            int nDist = nDX * nDX + nDY * nDY;
            aInside[x][y] = nDist < 1600;
            if (aInside[x][y])
            {
                int nScaled = nDist * nDist / 1600;
                nDist = (int)(float)sqrt((double)nDist);
                nScaled = (int)(float)sqrt((double)nScaled);
                if (nScaled < nDist / 2)
                    nScaled = nDist / 2;

                if (nDist)
                {
                    nNewX = nDX * nScaled / nDist;
                    nDY = nScaled * nDY / nDist;
                }

                int nSrcX = nNewX + 40;
                nDY += 40;
                nSrcX = ((nSrcX <= 0) - 1) & nSrcX;
                const int nClampX = D2_MIN(nSrcX, 79);
                int nSrcY = ((nDY <= 0) - 1) & nDY;
                nSrcY = D2_MIN(nSrcY, 79);
                ganRemapOffsets[y * 80 + x] = (nSrcY - y) * nPitch - x + nClampX;
            }
        }
    }

    for (int y = 0; y < 80; ++y)
    {
        ganRemapStart[y] = 0;
        ganRemapEnd[y] = 0;

        int x;
        for (x = 0; x < 80; ++x)
        {
            if (aInside[x][y])
                break;
        }

        if (x < 80)
        {
            ganRemapStart[y] = x;
            while (aInside[x][y])
                ++x;
            ganRemapEnd[y] = x;
        }
    }
}

// 0x00608C00
void __stdcall CmpDoLensEffect(unsigned char* pBuffer, int nPitch)
{
    unsigned char* pRow = pBuffer;
    int nBase = 0;
    for (int y = 0; y < 40; y++)
    {
        int nIndex = ganRemapStart[y] + nBase;
        unsigned char* p = pRow + ganRemapStart[y];
        unsigned char* pEnd = pRow + (ganRemapEnd[y] < 41 ? ganRemapEnd[y] : 41);
        for (; p < pEnd; p++, nIndex++)
            *p = p[ganRemapOffsets[nIndex]];

        nIndex = ganRemapEnd[y] + nBase;
        p = pRow + ganRemapEnd[y];
        pEnd = pRow + (ganRemapStart[y] >= 40 ? ganRemapStart[y] : 40);
        for (; p > pEnd; p--, nIndex--)
            *p = p[ganRemapOffsets[nIndex]];

        nBase += 80;
        pRow += nPitch;
    }

    pRow = pBuffer + 79 * nPitch;
    nBase = 79 * 80;
    for (int y = 79; y >= 40; y--)
    {
        int nIndex = ganRemapStart[y] + nBase;
        unsigned char* p = pRow + ganRemapStart[y];
        unsigned char* pEnd = pRow + (ganRemapEnd[y] < 41 ? ganRemapEnd[y] : 41);
        for (; p < pEnd; p++, nIndex++)
            *p = p[ganRemapOffsets[nIndex]];

        nIndex = ganRemapEnd[y] + nBase;
        p = pRow + ganRemapEnd[y];
        pEnd = pRow + (ganRemapStart[y] >= 40 ? ganRemapStart[y] : 40);
        for (; p > pEnd; p--, nIndex--)
            *p = p[ganRemapOffsets[nIndex]];

        nBase -= 80;
        pRow -= nPitch;
    }
}

static inline const char* __fastcall SkipCelRows(const char* current,int rows)
{
 if(!rows) return current;
 for(;;) {
  const char code=*current++;
  if(code<0) {
   if(!(code&127) && !--rows) break;
  } else current+=code;
 }
 return current;
}

// 0x00608D60
void __fastcall CelDrawRleShadow(const D2CelStrc* cel,unsigned char* dst,int x,int clipLeft,int clipRight,unsigned int pitch,int skip,int rows,const unsigned char* table,int color)
{
 int startX=x;
 if(pitch<cel->width) { FOG_DisplayHalt(gszEmptyAssert,sub_00408090(),1871);exit(-1); }
 const char* src=SkipCelRows((const char*)cel+32,skip*2);
 int step=-(int)pitch;
 unsigned char* nextRow=dst+step;
 for(;;) {
  char code=*src++;
  if(code<0) {
   code&=127;
   if(!code) {
    dst=nextRow-1;
    nextRow+=step-1;
    --startX;
    x=startX;
    if(!--rows) return;
    do {
     code=*src++;
     if(code>0) src+=code;
     else code&=127;
    } while(code);
   } else {
    x+=code;
    dst+=code;
   }
   continue;
  }
  int count=code;
  unsigned char* next=dst+count;
  int length=count;
  if(clipLeft || clipRight) {
   int left=clipLeft-x>0?clipLeft-x:0;
   int right=clipRight-x>0?clipRight-x:0;
   length=(right<count?right:count)-left;
   if(length<=0) goto advance;
   dst+=left;
  }
  if(length) {
   if(table) {
    unsigned char* end=dst+length;
    while(dst<end) {
     *dst=table[(*dst<<8)+(unsigned char)color];
     ++dst;
    }
   } else memset(dst,(unsigned char)color,length);
  }
 advance:
  x+=count;
  dst=next;
  src+=count;
 }
}

// 0x00608EE0
void __fastcall CelCompressEncodeRleCels(D2CmpCellListStrc* pList, D2CellFileStrc* pDstFile)
{
    D2_ASSERT(!(pList->dwFlags & 4), 0x72);
    const unsigned int nFrames = pList->nCells / pList->nDirections;
    unsigned int i = 0;
    for (D2CmpCellNodeStrc* pNode = (D2CmpCellNodeStrc*)((((int)pList->pHead <= 0) - 1) & (int)pList->pHead); (int)pNode > 0; pNode = pNode->pNext)
    {
        unsigned char* pRle;
        unsigned int nRleSize;
        CelEncodeRle(pNode->pPixels, pNode->dwWidth, pNode->dwHeight, pNode->dwFlags, &pRle, &nRleSize);

        D2GfxCellStrc* pNew = (D2GfxCellStrc*)FOG_Alloc(nRleSize + sizeof(D2GfxCellStrc) - 1, ".\\SRC\\FastCmp.cpp", 0x82, 0);
        pNew->dwFlags = pNode->dwFlags;
        pNew->dwWidth = pNode->dwWidth;
        pNew->dwHeight = pNode->dwHeight;
        pNew->nXOffset = pNode->nXOffset;
        pNew->nYOffset = pNode->nYOffset;
        pNew->unk0x14 = 0;
        pNew->dwParent = 0;
        pNew->dwLength = nRleSize;
        memcpy(pNew->pPixels, pRle, nRleSize);
        FOG_Free(pRle, ".\\SRC\\FastCmp.cpp", 0x8D, 0);

        const unsigned int nDirections = pList->nDirections;
        const int nDirection = nDirections > 1 ? ((i / nFrames) << 6) / nDirections : 1;
        pDstFile->pGfxCells[CelGameDirToFileDir(nDirection, nDirections) * nFrames + i % nFrames] = pNew;
        ++i;
    }
}

// 0x006096D0
D2CmpTileStrc* __stdcall TileListAddTile(D2CmpTileListStrc* ptList, short nValue16, short nValue14, int nValue24, int nValue28, int nValue2C, int nValue30, int nValue10, const D2CmpTileInfoStrc* pInfo)
{
    D2_ASSERT(ptList, 0xA2);
    D2CmpTileStrc* pTile = TileAlloc();
    D2_ASSERT(pTile, 0xA6);
    pTile->pNext = ptList->pFirst;
    ptList->nCount++;
    ptList->pFirst = pTile;
    pTile->nMaterialFlags = nValue16;
    pTile->nRoofHeight = nValue14;
    pTile->nOrientation = nValue24;
    pTile->nIndex = nValue28;
    pTile->nSubIndex = nValue2C;
    pTile->nRarity = nValue30;
    pTile->nLightDirection = nValue10;
    pTile->nOwnerId = ptList->nId;
    pTile->nType = 2;
    pTile->tInfo = *pInfo;
    return pTile;
}

// 0x0060B1A0
void D2CmpBitCursorStrc::CodecSkipBits(int nBits)
{
    int nPos = nBitPos + nBits;
    nBitPos = nPos & 0x1F;
    pData += nPos / 32;
}

// 0x0060CD70
unsigned char __fastcall FindTileHash(unsigned char a, unsigned char b, unsigned char c)
{
    unsigned char nResult = (unsigned char)(2 * a - c + b) % 128;
    D2_ASSERT(nResult < 128, 0x1E);
    return nResult;
}

// 0x0060D280
int __fastcall sub_0060D280_ScanSameRun(const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd)
{
    D2_ASSERT(pData < pEnd, 0x19);
    unsigned char nValue = *pData;
    int nCount = 0;
    while (pData < pEnd && nValue == *pData && nCount < nMax)
    {
        ++pData;
        ++nCount;
    }
    if (pData == pEnd)
    {
        *pbRunReachedEnd = 1;
        *pbRestReachedEnd = 0;
        return nCount;
    }
    *pbRunReachedEnd = 0;
    while (pData < pEnd && nValue == *pData)
        ++pData;
    *pbRestReachedEnd = pData == pEnd;
    return nCount;
}

// 0x0060D310
int __fastcall CmpScanRun(unsigned char nValue, const unsigned char* pData, const unsigned char* pEnd, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd)
{
    D2_ASSERT(pData < pEnd, 0x45);
    int nCount = 0;
    while (pData < pEnd && nValue == *pData && nCount < nMax)
    {
        ++pData;
        ++nCount;
    }
    if (pData == pEnd)
    {
        *pbRunReachedEnd = 1;
        *pbRestReachedEnd = 0;
        return nCount;
    }
    *pbRunReachedEnd = 0;
    while (pData < pEnd && nValue == *pData)
        ++pData;
    *pbRestReachedEnd = pData == pEnd;
    return nCount;
}

// 0x0060D3A0
int __fastcall sub_0060D3A0_ScanOtherRun(const unsigned char* pData, const unsigned char* pEnd, unsigned char nValue, int nMax, int* pbRunReachedEnd, int* pbRestReachedEnd)
{
    D2_ASSERT(pData < pEnd, 0x6F);
    int nCount = 0;
    while (pData < pEnd && *pData != nValue && nCount < nMax)
    {
        ++pData;
        ++nCount;
    }
    if (pData == pEnd)
    {
        *pbRunReachedEnd = 1;
        *pbRestReachedEnd = 0;
        return nCount;
    }
    *pbRunReachedEnd = 0;
    while (pData < pEnd && *pData == nValue)
        ++pData;
    *pbRestReachedEnd = pData == pEnd;
    return nCount;
}

// 0x0060DD20
int D2CmpStringStrc::EqualsNoCase(const D2CmpStringStrc* pOther)
{
    return !SStrCmpI(szText, pOther->szText, 0x7FFFFFFF);
}

static void sub_00606890_BuildBrightnessTable(unsigned char* pTables, D2HslStrc* pHsl);
void __cdecl sub_M386_Emit_00606890(int nUnused, unsigned char* pTables, D2HslStrc* pHsl)
{
    sub_00606890_BuildBrightnessTable(pTables, pHsl);
}

#include "gen/data/Source/D2CMP/SRC/FastCmp.inc"
