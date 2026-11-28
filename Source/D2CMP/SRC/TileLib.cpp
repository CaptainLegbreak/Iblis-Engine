#include "D2CMP.h"
#include "D2CmpTypes.h"
#include "D2CelDataHash.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct D2CmpTileStrc;
struct D2CmpTileProjectStrc;
struct D2CmpTileBlockStrc;
struct D2CmpTileLibraryStrc;
struct D2CmpGfxHashEntryStrc;
struct D2CmpGfxHashStrc;
struct D2CelDataHashEntryStrc;
struct D2CelDataHashStrc;
struct D2CmpFindTilesSubStrc;
struct D2CmpFindTilesNodeStrc;
struct D2CmpRGBStrc;
struct D2CmpRGBImageStrc;
struct D2CmpSubTileRecordStrc;
struct D2TileLibraryEntryStrc;
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
int __fastcall FindTileGetTiles(D2CmpTileProjectStrc* pProject, D2CmpTileStrc** ppTiles, int nMaxTiles, int nOrientation, int nMainIndex, int nSubIndex); // 0x0060D040


struct D2CmpGfxHashStrc
{
    void GfxHashFreeEntry(D2PoolSystemStrc* pMemPool, D2CmpGfxHashEntryStrc* pEntry);                               // 0x0060A9D0
};



struct D2CmpRGBImageStrc
{
    int unk0x00;
    unsigned int nWidth;
    unsigned int nHeight;
    char unk0x0C[0x14];
    D2CmpRGBStrc aPixels[1];
};

struct D2TileLibraryEntryStrc
{
    int nDirection;
    short nRoofHeight;
    unsigned short wFlags16;
    int nHeight;
    int nWidth;
    int nHeightToBottom;
    int nOrientation;
    int nIndex;
    int nSubIndex;
    int nRarity;
    int transparentColorRGB24;
    unsigned char aSubtileFlags[25];
    char unk0x41[0x17];
    int szFilePath;
};

struct D2TileLibraryHeaderStrc;

// 0x00604A40
void __stdcall TileLibraryAddProject(D2TileLibraryHeaderStrc** ptTileLibrary, const char* szFilePath)
{
    D2_ASSERT(ptTileLibrary, 0x1C);
    D2_ASSERT(szFilePath, 0x1D);
    int i;
    for (i = 0; i < 32; ++i)
    {
        if (!ptTileLibrary[i])
        {
            D2CMPLoadProjectRecord(&ptTileLibrary[i], szFilePath);
            break;
        }
    }
    D2_ASSERT(i < 32, 0x2A);
}


// 0x00604AA0
void __stdcall TileLibraryReleaseProject(int* pSlots, char* pEntry)
{
    if (pEntry)
    {
        int nValue = D2CMPGetFindTile(pEntry + 8);
        if (nValue)
        {
            for (int i = 0; i < 0x20; i++)
            {
                if (pSlots[i] == nValue)
                {
                    pSlots[i] = 0;
                    return;
                }
            }
        }
    }
}

// 0x0060AB10
void __fastcall GfxHashRemove(D2PoolSystemStrc* pMemPool, D2CmpGfxHashStrc* pHash, D2CmpGfxHashEntryStrc* pEntry)
{
    D2_ASSERT(pEntry, 0x141);
    if (pEntry->pPrev)
        pEntry->pPrev->pNext = pEntry->pNext;
    if (pEntry->pNext)
        pEntry->pNext->pPrev = pEntry->pPrev;
    pHash->GfxHashFreeEntry(pMemPool, pEntry);
}

// 0x0060D110
void __fastcall CelIterateRgbPixels(D2CmpRGBImageStrc* pImage, D2CmpColorCallback pfnColor, unsigned int nKey)
{
    unsigned int nPacked = (((unsigned char)(nKey >> 16) << 8) + (unsigned char)(nKey >> 8) << 8) + (unsigned char)nKey;
    D2CmpRGBStrc* pPixel = pImage->aPixels;
    for (unsigned int i = 0; i < pImage->nWidth * pImage->nHeight; i++)
    {
        unsigned int nColor = ((pPixel->b2 << 8) + pPixel->b1 << 8) + pPixel->b0;
        pPixel++;
        if (nColor != nPacked)
            pfnColor(nColor);
    }
}

// 0x00604B60
int __stdcall TileGetType(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 121); return hTile->nOrientation; }




// 0x00604AE0
int __stdcall TileLibraryGetTiles(D2CmpTileProjectStrc** ppProjects, int nOrientation, int nMainIndex, int nSubIndex, D2CmpTileStrc** ppTiles, int nMaxTiles)
{
    D2_ASSERT(ppProjects, 0x5D);
    int nFound = 0;
    int nLeft = nMaxTiles;
    for (int i = 0; i < 0x20; i++)
    {
        if (!ppProjects[i])
            break;
        int n = FindTileGetTiles(ppProjects[i], &ppTiles[nFound], nLeft, nOrientation, nMainIndex, nSubIndex);
        nLeft -= n;
        nFound += n;
        if (!nLeft)
            return nMaxTiles;
    }
    return nMaxTiles - nLeft;
}

// 0x006069F0
void* __stdcall CreateD2PaletteByteStream(void* pSource, int* pSize)
{
    *pSize = 0x6C327;
    return CreateD2Palette(pSource);
}

// 0x00604B90
int __stdcall TileGetStyle(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 122); return pTile->nIndex; }

// 0x00604BC0
int __stdcall TileGetFlags(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 123); return hTile->wFlags16; }

// 0x00604BF0
int __stdcall TileGetWidth(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 124); return hTile->nWidth; }

// 0x00604C20
int __stdcall TileGetRarity(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 125); return hTile->nRarity; }

// 0x00604C50
int __stdcall TileGetSequence(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 126); return hTile->nSubIndex; }

// 0x00604C80
int __stdcall TileGetTileLight(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 127); return hTile->nDirection; }

// 0x00604CB0
int __stdcall TileGetTotalHeight(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 128); return hTile->nHeight; }

// 0x00604CE0
unsigned char* __stdcall TileGetCollisionInfo(D2TileLibraryEntryStrc* pTile) { D2_ASSERT(pTile, 129); return pTile->aSubtileFlags; }

// 0x00604D10
int __stdcall TileGetHeightToBottom(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 130); return hTile->nHeightToBottom; }

// 0x00604D40
short __stdcall TileGetRoofHeight(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 131); return hTile->nRoofHeight; }

// 0x00604D80
int __stdcall TileGetFilename(D2TileLibraryEntryStrc* hTile) { D2_ASSERT(hTile, 132); return hTile->szFilePath; }
