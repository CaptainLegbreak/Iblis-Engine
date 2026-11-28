#include "D2CMP.h"
#include "D2DrlgMaps.h"
#include "D2CmpTileLib.h"
#include "D2CmpTypes.h"
#include "D2CmpTiles.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TileRecordStrc;

struct D2CmpTileNodeStrc;

struct D2CmpTileStrc;

struct D2CmpTileListStrc;

struct D2CmpSubTileRecordStrc;

struct D2CmpTileBlockStrc;

struct D2CmpTileLibraryStrc;

struct D2TileLibraryEntryStrc;



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);



extern const unsigned char gaDirection8To4[]; // 0x006E5DA0

extern const unsigned char gaDirection16To8[]; // 0x006E5DA8

extern const unsigned char gaDirection8To4Alt[]; // 0x006E5DB8

extern const unsigned char gaDirection16To8Alt[]; // 0x006E5DC0

struct D2TileRecordStrc
{
    int nFirst;
    int nSecond;
    int unk0x08;
    int unk0x0C;
};


extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

struct D2TileListHeaderStrc;

struct D2CmpColorStrc;

struct D2CmpSubTilePosStrc;

struct D2CmpTileInfoStrc;

D2TileListHeaderStrc* __cdecl TileAllocSubTile(); // 0x006094B0

void __fastcall sub_005179B3_ConvertCelPixels(void* pDst, void* pSrc, int nRows, unsigned int nSrcSize, unsigned int nWidth, int nRows2);

extern D2CmpSubTilePosStrc gatSubTilePositions[25]; // 0x00743500

struct D2Block0060A050Strc;

struct D2BlockSet0060A050Strc;

static void __stdcall TileExtractFloorSubTile(D2CmpTileNodeStrc* pSub, const unsigned char* pPixels, D2CmpColorStrc tColor, int nX, int nY);

struct D2Block0060A050Strc
{
    unsigned char unk_00[0x0A];
    unsigned short nSize;
    unsigned char unk_0C[0x04];
    unsigned int pData;
};

struct D2BlockSet0060A050Strc
{
    unsigned char unk_00[0x50];
    int nBlocks;
    D2Block0060A050Strc* pBlocks;
};

static int TileSerializeSubTiles(unsigned char* pOut, D2BlockSet0060A050Strc* pSet);

static int __stdcall TileHasNonKeyPixel(D2CmpColorStrc tColor, const unsigned char* pData);



#pragma function(memcpy)

typedef unsigned char (__stdcall* D2CmpMapColorFn)(unsigned char nRed, unsigned char nGreen, unsigned char nBlue);

void __fastcall SubTileConvert24To8(D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc, D2CmpColorStrc tTransparent, D2CmpMapColorFn pfnMapColor); // 0x0060D5B0

void __fastcall SubTileEncodeFloor(D2CmpSubTileRecordStrc* pRecord); // 0x0060DB20

void __stdcall TileProjectSerialize(D2CmpTileLibraryStrc* pLibrary, unsigned char** ppData, int* pnSize);

static void TileSplitFloorTile(D2CmpTileStrc* pTile, const unsigned char* pPixels);

void __stdcall TileAddAddFloorTile(D2CmpTileStrc* pTile, const unsigned char* pPixels);

static int TileProjectGetSerializedSize(D2CmpTileLibraryStrc* pLibrary);



void __stdcall TileProjectConvert24To8(D2CmpTileLibraryStrc* pSrc, D2CmpTileLibraryStrc** ppLibrary, D2CmpMapColorFn pfnMapColor);

// 0x00600CB0
int __stdcall CelConvertDir(unsigned int nDirection, unsigned int nDirections, int nNewDirections, int bAlt)
{
    D2_ASSERT(nDirection < nDirections, 0x1A0);

    if (nDirections == 8)
    {
        if (nNewDirections == 4)
        {
            if (bAlt)
            {
                return gaDirection8To4Alt[nDirection];
            }
            return gaDirection8To4[nDirection];
        }
    }
    else if (nDirections == 16)
    {
        if (nNewDirections == 8)
        {
            if (bAlt)
            {
                return gaDirection16To8Alt[nDirection];
            }
            return gaDirection16To8[nDirection];
        }
    }

    return 0;
}

// 0x00605D20
void __stdcall PaletteBuildTintTables(unsigned char* pData)
{
    for (int j = 0; j < 12; ++j)
    {
        for (int i = 0; i < 256; ++i)
        {
            const int nValue = pData[4 * i];
            pData[0x6B727 + 256 * j + i] = GetClosestColor(pData, 256,
                (unsigned char)(pData[0x6B603 + 3 * j] * nValue / 255),
                (unsigned char)(pData[0x6B604 + 3 * j] * nValue / 255),
                (unsigned char)(pData[0x6B605 + 3 * j] * nValue / 255));
        }
    }
}

// 0x006094B0
D2TileListHeaderStrc* __cdecl TileAllocSubTile()
{
    D2TileListHeaderStrc* pHeader = (D2TileListHeaderStrc*)FOG_Alloc(sizeof(D2TileListHeaderStrc), ".\\SRC\\Tilecmp.cpp", 0x23, 0);
    D2_ASSERT(pHeader, 0x24);
    memset(pHeader, 0, sizeof(D2TileListHeaderStrc));
    return pHeader;
}

// 0x00609500
static inline void TileFreeSubTile(D2CmpTileNodeStrc* pNode)
{
    D2_ASSERT(pNode, 0x31);
    if (pNode->pData)
    {
        FOG_Free(pNode->pData, ".\\SRC\\Tilecmp.cpp", 0x35, 0);
    }
    FOG_Free(pNode, ".\\SRC\\Tilecmp.cpp", 0x38, 0);
}

// 0x00609550
D2CmpTileStrc* __cdecl TileAlloc()
{
    D2CmpTileStrc* pTile = (D2CmpTileStrc*)FOG_Alloc(sizeof(D2CmpTileStrc), ".\\SRC\\Tilecmp.cpp", 0x45, 0);
    D2_ASSERT(pTile, 0x46);
    memset(pTile, 0, sizeof(D2CmpTileStrc));
    return pTile;
}

void __stdcall sub_M128_Emit_00609500(D2CmpTileNodeStrc* pNode)
{
    TileFreeSubTile(pNode);
}

// 0x006095A0
static void TileFree(D2CmpTileStrc* pTile)
{
    D2_ASSERT(pTile, 0x54);
    D2CmpTileNodeStrc* pNode = pTile->pNodes;
    while (pNode)
    {
        D2CmpTileNodeStrc* pNext = pNode->pNext;
        if (pNode->pData)
        {
            FOG_Free(pNode->pData, ".\\SRC\\Tilecmp.cpp", 0x35, 0);
        }
        FOG_Free(pNode, ".\\SRC\\Tilecmp.cpp", 0x38, 0);
        pNode = pNext;
    }
    FOG_Free(pTile, ".\\SRC\\Tilecmp.cpp", 0x60, 0);
}

// 0x00609620
D2TileRecordStrc* __stdcall TileListCreate(int nFirst, int nSecond)
{
    D2TileRecordStrc* pRecord = (D2TileRecordStrc*)FOG_Alloc(sizeof(D2TileRecordStrc), ".\\SRC\\Tilecmp.cpp", 0x6D, 0);
    D2_ASSERT(pRecord, 0x6E);
    memset(pRecord, 0, sizeof(D2TileRecordStrc));
    pRecord->nFirst = nFirst;
    pRecord->nSecond = nSecond;
    return pRecord;
}

// 0x00609670
void __stdcall TileListDestroy(D2CmpTileListStrc* pList)
{
    D2_ASSERT(pList, 0x80);
    D2CmpTileStrc* pTile = pList->pFirst;
    while (pTile)
    {
        D2CmpTileStrc* pNext = pTile->pNext;
        TileFree(pTile);
        pTile = pNext;
    }
    FOG_Free(pList, ".\\SRC\\Tilecmp.cpp", 0x8C, 0);
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

// 0x00609770
static int __stdcall TileIsSubTileBlank(D2CmpTileStrc* pTile, const unsigned char* pPixels, int nPitch)
{
    const unsigned char nFlags = pTile->nType;
    if (nFlags & 2)
    {
        const int nSkip = nPitch - 0x60;
        const unsigned int nColor = (((pTile->tColor.nBlue << 8) + pTile->tColor.nGreen) << 8) + pTile->tColor.nRed;
        for (int y = 0; y < 0x20; y++)
        {
            for (int x = 0; x < 0x20; x++)
            {
                const unsigned int nPixel = *(const unsigned int*)pPixels & 0xFFFFFF;
                pPixels += 3;
                if (nPixel != nColor)
                    return 0;
            }
            pPixels += nSkip;
        }
    }
    if (nFlags & 1)
    {
        const int nSkip = nPitch - 0x20;
        for (int y = 0; y < 0x20; y++)
        {
            for (int x = 0; x < 0x20; x++)
            {
                if (*pPixels++)
                    return 0;
            }
            pPixels += nSkip;
        }
    }
    return 1;
}

// 0x00609810
void __stdcall TileAddAddSubTile(D2CmpTileStrc* pTile, unsigned char* pPixels, int nPitch, int nX, int nY)
{
    D2_ASSERT(pTile, 0x100);
    D2_ASSERT(pPixels, 0x101);
    if (TileIsSubTileBlank(pTile, pPixels, nPitch))
        return;
    D2CmpTileNodeStrc* pNode = (D2CmpTileNodeStrc*)TileAllocSubTile();
    D2_ASSERT(pNode, 0x109);
    pNode->pNext = pTile->pNodes;
    pTile->nCount++;
    pTile->pNodes = pNode;
    D2_ASSERT(nX < 0x10000 && nY < 0x10000, 0x112);
    pNode->nX = nX;
    pNode->nY = nY;
    unsigned char* ptData = (unsigned char*)FOG_Alloc(0xC00, ".\\SRC\\Tilecmp.cpp", 0x119, 0);
    D2_ASSERT(ptData, 0x11A);
    memset(ptData, 0, 0xC00);
    pNode->nLength = 0xC00;
    pNode->pData = ptData;
    pNode->nFormat = 0x1001;
    sub_005179B3_ConvertCelPixels(ptData, pPixels, 0x60, nPitch, 0x20, 0x60);
    if (nX < pTile->nMinX)
        pTile->nMinX = nX;
    if (nX + 0x20 > pTile->nMaxX)
        pTile->nMaxX = nX + 0x20;
    if (nY > pTile->nMaxY)
        pTile->nMaxY = nY;
    if (nY - 0x20 < pTile->nMinY)
        pTile->nMinY = nY - 0x20;
}

// Kept noinline: a static that takes its arguments in registers; TileExtractFloorSubTile (0x609980) calls it out of line in the image (the #368 case).
// 0x00609940
static __declspec(noinline) int __stdcall TileHasNonKeyPixel(D2CmpColorStrc tColor, const unsigned char* pData)
{
    for (int i = 0; i < 0x200; i++)
    {
        if (pData[0] != tColor.nRed || pData[1] != tColor.nGreen || pData[2] != tColor.nBlue)
        {
            return 1;
        }
        pData += 3;
    }
    return 0;
}

// 0x00609980
static void __stdcall TileExtractFloorSubTile(D2CmpTileNodeStrc* pSub, const unsigned char* pPixels, D2CmpColorStrc tColor, int nX, int nY)
{
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(0x600, ".\\SRC\\Tilecmp.cpp", 0x154, 0);
    D2_ASSERT(pBuffer, 0x155);
    memset(pBuffer, 0, 0x600);
    unsigned char* pFill = pBuffer;
    for (int i = 0; i < 0x200; i++)
    {
        pFill[0] = tColor.nRed;
        pFill[1] = tColor.nGreen;
        pFill[2] = tColor.nBlue;
        pFill += 3;
    }
    int nRow = 0;
    const unsigned char* pSrc = pPixels + 3 * (nY * 160 + nX);
    unsigned char* pDst = pBuffer;
    int nStart = 0x2A;
    int nWidth = 0x0C;
    for (; nRow < 15; nRow++)
    {
        memcpy(pDst + nStart, pSrc + nStart, nWidth);
        if (nRow < 7)
        {
            nStart -= 6;
            nWidth += 0x0C;
        }
        else
        {
            nStart += 6;
            nWidth -= 0x0C;
        }
        pDst += 0x60;
        pSrc += 0x1E0;
    }
    if (TileHasNonKeyPixel(tColor, pBuffer))
    {
        pSub->nFormat |= 0x2001;
        pSub->pData = pBuffer;
        pSub->nLength = 0x600;
    }
    else
    {
        FOG_Free(pBuffer, ".\\SRC\\Tilecmp.cpp", 0x186, 0);
    }
}

// 0x00609AA0
static void TileSplitFloorTile(D2CmpTileStrc* pTile, const unsigned char* pPixels)
{
    for (int i = 0; i < 25; i++)
    {
        D2CmpTileNodeStrc tSub;
        memset(&tSub, 0, sizeof(tSub));
        TileExtractFloorSubTile(&tSub, pPixels, pTile->tColor, gatSubTilePositions[i].nX, gatSubTilePositions[i].nY);
        tSub.nGridX = i % 5;
        tSub.nGridY = i / 5;
        if (tSub.nFormat & 1)
        {
            D2CmpTileNodeStrc* pNode = (D2CmpTileNodeStrc*)FOG_Alloc(sizeof(D2CmpTileNodeStrc), ".\\SRC\\Tilecmp.cpp", 0x1A7, 0);
            D2_ASSERT(pNode, 0x1A8);
            *pNode = tSub;
            pNode->pNext = pTile->pNodes;
            pTile->nCount++;
            pTile->pNodes = pNode;
            pNode->nX = gatSubTilePositions[i].nX;
            pNode->nY = gatSubTilePositions[i].nY;
        }
    }
}

// 0x00609B90
void __stdcall TileAddAddFloorTile(D2CmpTileStrc* pTile, const unsigned char* pPixels)
{
    D2_ASSERT(pTile, 0x1C3);
    D2_ASSERT(pPixels, 0x1C4);
    TileSplitFloorTile(pTile, pPixels);
    pTile->nMaxY = 0;
    pTile->nMinY = -0x80;
    pTile->nMinX = 0;
    pTile->nMaxX = 0xA0;
}

// 0x00609BF0
static void TileCopySubTile(D2CmpSubTileRecordStrc* pSub, D2CmpTileNodeStrc* pNode)
{
    pSub->nX = pNode->nX;
    pSub->nY = pNode->nY;
    pSub->nGridX = pNode->nGridX;
    pSub->nGridY = pNode->nGridY;
    pSub->nFlags = pNode->nFormat;
    pSub->nLength = pNode->nLength;
    pSub->ptData = pNode->pData;
    pNode->pData = 0;
}

void __fastcall sub_M289_Emit_00609BF0(D2CmpSubTileRecordStrc* pSub, D2CmpTileNodeStrc* pNode)
{
    TileCopySubTile(pSub, pNode);
}

// 0x00609C30
static void __stdcall TileConvertToProjectTile(D2CmpTileStrc* pSrc, D2CmpTileBlockStrc* ptTile)
{
    ptTile->nLightDirection = pSrc->nLightDirection;
    ptTile->nRoofHeight = pSrc->nRoofHeight;
    ptTile->nMaterialFlags = pSrc->nMaterialFlags;
    ptTile->nWidth = pSrc->nMaxX - pSrc->nMinX;
    ptTile->nHeight = pSrc->nMinY - pSrc->nMaxY;
    ptTile->nOrientation = pSrc->nOrientation;
    ptTile->nIndex = pSrc->nIndex;
    ptTile->nSubIndex = pSrc->nSubIndex;
    ptTile->nRarity = pSrc->nRarity;
    ptTile->nOwnerId = pSrc->nOwnerId;
    ptTile->nSubs = pSrc->nCount;
    ptTile->tInfo = pSrc->tInfo;
    const int nSize = ptTile->nSubs * sizeof(D2CmpSubTileRecordStrc);
    if (nSize)
    {
        ptTile->pSubs = (D2CmpSubTileRecordStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x201, 0);
        D2_ASSERT(ptTile->pSubs, 0x202);
        memset(ptTile->pSubs, 0, nSize);
    }
    else
    {
        ptTile->pSubs = 0;
    }
    int i = 0;
    for (D2CmpTileNodeStrc* pNode = pSrc->pNodes; pNode; pNode = pNode->pNext)
    {
        D2CmpSubTileRecordStrc* pSub = &ptTile->pSubs[i];
        pSub->nX = pNode->nX;
        pSub->nY = pNode->nY;
        pSub->nGridX = pNode->nGridX;
        pSub->nGridY = pNode->nGridY;
        pSub->nFlags = pNode->nFormat;
        pSub->nLength = pNode->nLength;
        pSub->ptData = pNode->pData;
        pNode->pData = 0;
        i++;
    }
    D2_ASSERT(i == ptTile->nSubs, 0x213);
}

// 0x00609D60
int __stdcall TileListCreateProject(D2CmpTileListStrc* pList, D2CmpTileLibraryStrc** ppLibrary)
{
    D2_ASSERT(pList, 0x224);
    if (!pList->nCount)
    {
        *ppLibrary = 0;
        return 0x85200004;
    }
    D2CmpTileLibraryStrc* pLibrary = (D2CmpTileLibraryStrc*)FOG_Alloc(sizeof(D2CmpTileLibraryStrc), ".\\SRC\\Tilecmp.cpp", 0x22C, 0);
    D2_ASSERT(pLibrary, 0x22D);
    memset(pLibrary, 0, sizeof(D2CmpTileLibraryStrc));
    pLibrary->dwVersion = 7;
    if (pList->bFlag)
    {
        pLibrary->dwFlags = 1;
    }
    const int nBlocks = pList->nCount;
    const int nSize = nBlocks * sizeof(D2CmpTileBlockStrc);
    pLibrary->nBlocks = nBlocks;
    pLibrary->pBlocks = (D2CmpTileBlockStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x238, 0);
    D2_ASSERT(pLibrary->pBlocks, 0x239);
    memset(pLibrary->pBlocks, 0, nSize);
    int i = 0;
    for (D2CmpTileStrc* pTile = pList->pFirst; pTile; pTile = pTile->pNext)
    {
        TileConvertToProjectTile(pTile, &pLibrary->pBlocks[i]);
        i++;
    }
    D2_ASSERT(i == pLibrary->nBlocks, 0x247);
    *ppLibrary = pLibrary;
    return 0;
}

// 0x00609E90
void __stdcall TileProjectDestroy(D2CmpTileLibraryStrc* pLibrary, int bKeep)
{
    if (bKeep)
        return;
    D2_ASSERT(pLibrary, 0x25A);
    D2CMPTileCacheFreeProject(pLibrary);
    if (pLibrary->dwFlags & 4)
    {
        FOG_Free(pLibrary, ".\\SRC\\Tilecmp.cpp", 0x262, 0);
        return;
    }
    D2_ASSERT(!(pLibrary->dwFlags & 8), 0x267);
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        for (int j = 0; j < pBlock->nSubs; j++)
        {
            D2CmpSubTileRecordStrc* pSub = &pBlock->pSubs[j];
            if (pSub->ptData)
                FOG_Free(pSub->ptData, ".\\SRC\\Tilecmp.cpp", 0x274, 0);
            pSub->nLength = 0;
            pSub->ptData = 0;
        }
        if (pBlock->pSubs)
            FOG_Free(pBlock->pSubs, ".\\SRC\\Tilecmp.cpp", 0x27B, 0);
        pBlock->pSubs = 0;
        pBlock->nSubs = 0;
    }
    FOG_Free(pLibrary->pBlocks, ".\\SRC\\Tilecmp.cpp", 0x281, 0);
    pLibrary->pBlocks = 0;
    pLibrary->nBlocks = 0;
    FOG_Free(pLibrary, ".\\SRC\\Tilecmp.cpp", 0x285, 0);
}

// 0x00609FD0
static int TileProjectGetSerializedSize(D2CmpTileLibraryStrc* pLibrary)
{
    D2_ASSERT(pLibrary, 0x293);
    int nSize = pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc) + sizeof(D2CmpTileLibraryStrc);
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        nSize += pBlock->nSubs * sizeof(D2CmpSubTileRecordStrc);
        for (int j = 0; j < pBlock->nSubs; j++)
        {
            nSize += pBlock->pSubs[j].nLength;
        }
    }
    return nSize;
}

static int sub_0060A050_PackBlockSubs(unsigned char* pDst, D2CmpTileBlockStrc* pBlock)
{
    unsigned char* pWrite = pDst;
    int nSize = pBlock->nSubs * sizeof(D2CmpSubTileRecordStrc);
    memcpy(pWrite, pBlock->pSubs, nSize);
    D2CmpSubTileRecordStrc* pDstSubs = (D2CmpSubTileRecordStrc*)pWrite;
    pWrite += nSize;
    for (int i = 0; i < pBlock->nSubs; i++)
    {
        memcpy(pWrite, pBlock->pSubs[i].ptData, pBlock->pSubs[i].nLength);
        pDstSubs[i].ptData = (unsigned char*)(pWrite - pDst);
        nSize += pBlock->pSubs[i].nLength;
        pWrite += pBlock->pSubs[i].nLength;
    }
    return nSize;
}

// 0x0060A050
static int TileSerializeSubTiles(unsigned char* pOut, D2BlockSet0060A050Strc* pSet)
{
    unsigned char* pStart = pOut;
    int nTotal = pSet->nBlocks * sizeof(D2Block0060A050Strc);
    memcpy(pOut, pSet->pBlocks, nTotal);
    D2Block0060A050Strc* pOutBlocks = (D2Block0060A050Strc*)pOut;
    pOut += nTotal;
    for (int i = 0; i < pSet->nBlocks; ++i)
    {
        D2Block0060A050Strc* pBlock = &pSet->pBlocks[i];
        memcpy(pOut, (const void*)pBlock->pData, pBlock->nSize);
        pOutBlocks[i].pData = pOut - pStart;
        nTotal += pBlock->nSize;
        pOut += pBlock->nSize;
    }
    return nTotal;
}

// calling-convention shim (not game code)
int __stdcall shim_5(unsigned char* pOut, D2BlockSet0060A050Strc* pSet)
{
    return TileSerializeSubTiles(pOut, pSet);
}

static unsigned int sub_0060A050(unsigned char * pDstBuf, D2CmpTileBlockStrc * pTileSetEntry) {
    unsigned char* pBase = pDstBuf;
    unsigned int nNodeSize;
    int* pFixupPtr;
    unsigned int nCumSize = pTileSetEntry->nSubs * 0x14;
    memcpy(pDstBuf, pTileSetEntry->pSubs, nCumSize);
    pFixupPtr = (int*)pDstBuf;
    pDstBuf += nCumSize;
    int iNode = 0;
    if (pTileSetEntry->nSubs > 0) {
      D2CmpSubTileRecordStrc* pDVar1;
      int nSubOffset = 0;
      pFixupPtr += 4;
      do {
        pDVar1 = (D2CmpSubTileRecordStrc*)((char*)pTileSetEntry->pSubs + nSubOffset);
        memcpy(pDstBuf, (void*)pDVar1->ptData, (unsigned int)pDVar1->nLength);
        *pFixupPtr = pDstBuf - pBase;
        nNodeSize = (unsigned int)pDVar1->nLength;
        nCumSize += nNodeSize;
        pDstBuf += nNodeSize;
        nSubOffset += 0x14;
        iNode++;
        pFixupPtr += 5;
      } while (iNode < pTileSetEntry->nSubs);

      return nCumSize;
    }

    return nCumSize;
}

// 0x0060A0F0
void __stdcall TileProjectSerialize(D2CmpTileLibraryStrc* pLibrary, unsigned char** ppData, int* pnSize)
{
    D2_ASSERT(pLibrary, 0x2D9);
    D2_ASSERT(ppData, 0x2DA);
    D2_ASSERT(pnSize, 0x2DB);
    D2_ASSERT(pLibrary->nBlocks, 0x2DC);
    const int nSize = TileProjectGetSerializedSize(pLibrary);
    D2_ASSERT(nSize, 0x2E0);
    unsigned char* pData = (unsigned char*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x2E3, 0);
    D2_ASSERT(pData, 0x2E4);
    memset(pData, 0, nSize);
    *ppData = pData;
    *pnSize = nSize;
    unsigned char* pBase = pData;
    unsigned int nHeaderSize = sizeof(D2CmpTileLibraryStrc);
    memcpy(pData, pLibrary, nHeaderSize);
    D2CmpTileLibraryStrc* pHeader = (D2CmpTileLibraryStrc*)pData;
    pData += sizeof(D2CmpTileLibraryStrc);
    const int nBlockBytes = pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc);
    memcpy(pData, pLibrary->pBlocks, nBlockBytes);
    pHeader->pBlocks = (D2CmpTileBlockStrc*)(pData - pBase);
    D2CmpTileBlockStrc* pDstBlocks = (D2CmpTileBlockStrc*)pData;
    pData += nBlockBytes;
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        pDstBlocks[i].pSubs = 0;
        const int nBytes = sub_0060A050(pData, pBlock);
        pDstBlocks[i].nSubsOffset = pData - pBase;
        pDstBlocks[i].nSubBytes = nBytes;
        pData += nBytes;
    }
    pLibrary->dwFlags |= 2;
    pHeader->dwFlags |= 6;
}

// 0x0060A260
static inline int TileProjectNormalizeSubTiles(D2CmpTileBlockStrc* pBlock, unsigned char* pData)
{
    int nSize = pBlock->nSubs * sizeof(D2CmpSubTileRecordStrc);
    for (int j = 0; j < pBlock->nSubs; j++)
    {
        D2CmpSubTileRecordStrc* pSub = &pBlock->pSubs[j];
        pSub->ptData += (int)pData;
        nSize += pSub->tHeader.nLength;
    }
    return nSize;
}

// 0x0060A290
void __stdcall TileProjectNormalize(D2CmpTileLibraryStrc* pLibrary, D2CmpTileLibraryStrc** ppLibrary, const char* szName)
{
    D2_ASSERT(pLibrary->dwVersion == 7, 0x348);
    if (pLibrary->dwFlags & 3)
    {
        pLibrary->pBlocks = (D2CmpTileBlockStrc*)((char*)pLibrary + (int)pLibrary->pBlocks);
        if (szName)
            strcpy(pLibrary->szName, szName);
        char* pData = (char*)pLibrary + sizeof(D2CmpTileLibraryStrc) + pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc);
        for (int i = 0; i < pLibrary->nBlocks; i++)
        {
            D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
            pBlock->pName = pLibrary->szName;
            pBlock->pSubs = (D2CmpSubTileRecordStrc*)((char*)pLibrary + pBlock->nSubsOffset);
            int nSize = pBlock->nSubs * sizeof(D2CmpSubTileRecordStrc);
            for (int j = 0; j < pBlock->nSubs; j++)
            {
                D2CmpSubTileRecordStrc* pSub = &pBlock->pSubs[j];
                pSub->ptData += (int)pData;
                nSize += pSub->nLength;
            }
            pData += nSize;
        }
        pLibrary->dwFlags = (pLibrary->dwFlags & ~2) | 4;
        *ppLibrary = pLibrary;
    }
}

// 0x0060A390
void __stdcall TileProjectNormalizeHeaders(D2CmpTileLibraryStrc* pLibrary, D2CmpTileLibraryStrc** ppLibrary, const char* szName)
{
    D2_ASSERT(pLibrary->dwVersion == 7, 0x37F);
    if (pLibrary->dwFlags & 2)
    {
        pLibrary->pBlocks = (D2CmpTileBlockStrc*)((char*)pLibrary + (int)pLibrary->pBlocks);
        strcpy(pLibrary->szName, szName);
        for (int i = 0; i < pLibrary->nBlocks; i++)
        {
            D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
            pBlock->pName = pLibrary->szName;
            D2_ASSERT(!pBlock->pSubs, 0x3A2);
            D2_ASSERT(!pBlock->pExtra, 0x3A3);
        }
        pLibrary->dwFlags = (pLibrary->dwFlags & ~2) | 4;
        *ppLibrary = pLibrary;
    }
}

// 0x0060A440
D2TileLibraryHashStrc* __fastcall TileProjectBuildFindTable(D2CmpTileLibraryStrc* pLibrary)
{
    D2TileLibraryHashStrc* pHash = sub_0060CDB0_AllocTileHash();
    D2_ASSERT(pHash, 0x3B9);
    D2_ASSERT(pLibrary, 0x3BA);

    for (int i = 0; i < pLibrary->nBlocks; ++i)
    {
        FindTileAddTile(pHash, &pLibrary->pBlocks[i]);
    }

    return pHash;
}

// 0x0060A4C0
void __stdcall TileNormalizeSubTiles(D2CmpTileBlockStrc* pBlock)
{
    D2_ASSERT(pBlock, 0x3C9);
    char* pBase = (char*)pBlock->pSubs;
    for (int i = 0; i < pBlock->nSubs; i++)
    {
        D2CmpSubTileRecordStrc* pSub = &pBlock->pSubs[i];
        pSub->ptData += (int)pBase;
    }
}

// 0x0060A520
static void TileIterateSubTilePixels(D2CmpColorCallback pfnColor, const unsigned char* pData, int nSize)
{
    for (int i = 0; i < nSize; i += 3)
    {
        pfnColor((((pData[2] << 8) + pData[1]) << 8) + pData[0]);
        pData += 3;
    }
}

// 0x0060A570
void __stdcall TileProjectIteratePixels(D2CmpTileLibraryStrc* pLibrary, D2CmpColorCallback pfnColor)
{
    D2_ASSERT(pLibrary, 0x3EA);
    D2_ASSERT(pLibrary->dwFlags & 1, 0x3EB);
    for (int i = 0; i < pLibrary->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pBlock = &pLibrary->pBlocks[i];
        for (int j = 0; j < pBlock->nSubs; j++)
        {
            D2CmpSubTileRecordStrc* pSub = &pBlock->pSubs[j];
            TileIterateSubTilePixels(pfnColor, pSub->ptData, pSub->nLength);
        }
    }
}

// 0x0060A620
static inline int SubTileRecordIsEmpty(const D2CmpSubTileRecordStrc* pRecord)
{
    const unsigned char* pData = pRecord->ptData;
    for (int i = 0; i < pRecord->tHeader.nLength; i++)
    {
        if (*pData)
        {
            return 0;
        }
        pData++;
    }
    return 1;
}

int __stdcall sub_M213_Emit_0060A260(D2CmpTileBlockStrc* pBlock, unsigned char* pData)
{
    return TileProjectNormalizeSubTiles(pBlock, pData);
}

void __fastcall sub_M213_Emit_0060A620(const D2CmpSubTileRecordStrc* pRecord, int* pResult)
{
    *pResult = SubTileRecordIsEmpty(pRecord);
}

static int IsSubTileDataEmpty(const D2CmpSubTileRecordStrc* pRecord, const unsigned char* pData)
{
    for (int i = 0; i < pRecord->tHeader.nLength; i++)
    {
        if (*pData)
        {
            return 0;
        }
        pData++;
    }
    return 1;
}

// 0x0060A650
static void __stdcall TileConvertSubTile24To8(D2CmpSubTileRecordStrc* pDst, const D2CmpSubTileRecordStrc* pSrc, D2CmpMapColorFn pfnMapColor, D2CmpColorStrc tTransparent)
{
    if (!pSrc->ptData)
    {
        pDst->tHeader.nFlags &= ~1;
        pDst->tHeader.nLength = 0;
        pDst->ptData = 0;
        return;
    }
    SubTileConvert24To8(pDst, pSrc, tTransparent, pfnMapColor);
    unsigned char* pMapped = pDst->ptData;
    if (IsSubTileDataEmpty(pDst, pMapped))
    {
        FOG_Free(pMapped, ".\\SRC\\Tilecmp.cpp", 0x429, 0);
        pDst->tHeader.nFlags &= ~1;
        pDst->tHeader.nLength = 0;
        pDst->ptData = 0;
        return;
    }
    if (pDst->tHeader.nFlags & 0x1000)
    {
        int nLength;
// build: symbol ?SubTileCompress@* 0x0060D430
        unsigned char* pData = (unsigned char*)SubTileCompress(pMapped, &nLength);
        D2_ASSERT(pData, 0x434);
        D2_ASSERT(nLength < 0x10000, 0x435);
        FOG_Free(pDst->ptData, ".\\SRC\\Tilecmp.cpp", 0x436, 0);
        pDst->ptData = pData;
        pDst->tHeader.nLength = nLength;
    }
    else
    {
        D2_ASSERT(pDst->tHeader.nFlags & 0x2000, 0x43B);
        SubTileEncodeFloor(pDst);
    }
}

// 0x0060A750
void __stdcall TileProjectConvert24To8(D2CmpTileLibraryStrc* pSrc, D2CmpTileLibraryStrc** ppLibrary, D2CmpMapColorFn pfnMapColor)
{
    D2_ASSERT(pSrc, 0x44F);
    D2_ASSERT(pSrc->dwFlags & 1, 0x450);
    D2CmpTileLibraryStrc* pLibrary = (D2CmpTileLibraryStrc*)FOG_Alloc(sizeof(D2CmpTileLibraryStrc), ".\\SRC\\Tilecmp.cpp", 0x453, 0);
    D2_ASSERT(pLibrary, 0x454);
    memset(pLibrary, 0, sizeof(D2CmpTileLibraryStrc));
    *pLibrary = *pSrc;
    pLibrary->dwFlags &= ~1;
    pLibrary->pBlocks = 0;
    const int nSize = pLibrary->nBlocks * sizeof(D2CmpTileBlockStrc);
    pLibrary->pBlocks = (D2CmpTileBlockStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 0x45E, 0);
    D2_ASSERT(pLibrary->pBlocks, 0x45F);
    memset(pLibrary->pBlocks, 0, nSize);
    for (int i = 0; i < pSrc->nBlocks; i++)
    {
        D2CmpTileBlockStrc* pDstBlock = &pLibrary->pBlocks[i];
        D2CmpTileBlockStrc* pSrcBlock = &pSrc->pBlocks[i];
        *pDstBlock = *pSrcBlock;
        pDstBlock->pSubs = 0;
        if (pDstBlock->nSubs)
        {
            const int nSubSize = pDstBlock->nSubs * sizeof(D2CmpSubTileRecordStrc);
            D2_ASSERT(nSubSize, 0x470);
            pDstBlock->pSubs = (D2CmpSubTileRecordStrc*)FOG_Alloc(nSubSize, ".\\SRC\\Tilecmp.cpp", 0x472, 0);
            D2_ASSERT(pDstBlock->pSubs, 0x473);
            memset(pDstBlock->pSubs, 0, nSubSize);
            for (int j = 0; j < pSrcBlock->nSubs; j++)
            {
                TileConvertSubTile24To8(&pDstBlock->pSubs[j], &pSrcBlock->pSubs[j], pfnMapColor, pSrcBlock->tColor);
            }
        }
    }
    *ppLibrary = pLibrary;
}

// 0x0060A910
void __stdcall TileLibraryCopyHeaders(D2TileLibraryHeaderStrc* pSource, D2TileLibraryHeaderStrc** ppCopy, int* pnSize)
{
    D2_ASSERT(pSource, 1171);

    int nSize = sizeof(D2TileLibraryHeaderStrc) + pSource->nTiles * sizeof(D2TileLibraryEntryStrc);
    D2TileLibraryHeaderStrc* pCopy = (D2TileLibraryHeaderStrc*)FOG_Alloc(nSize, ".\\SRC\\Tilecmp.cpp", 1178, 0);
    D2_ASSERT(pCopy, 1179);

    memset(pCopy, 0, nSize);
    memcpy(pCopy, pSource, nSize);
    D2TileLibraryEntryStrc* pEntries = (D2TileLibraryEntryStrc*)(pCopy + 1);
    pCopy->pFirst = pEntries;
    for (int i = 0; i < pCopy->nTiles; ++i)
    {
        pEntries[i].pBlocks = 0;
        pEntries[i].nBlocks = 0;
    }
    pCopy->dwFlags &= 4;

    *ppCopy = pCopy;
    *pnSize = nSize;
}

extern "C" const unsigned char gData_006E5DA0[8] = { 1, 1, 3, 3, 5, 5, 7, 7 }; // 0x006E5DA0
#pragma comment(linker, "/alternatename:?gaDirection8To4@@3QBEB=_gData_006E5DA0")

extern "C" const unsigned char gData_006E5DA8[16] = { 0, 0, 2, 2, 4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14, 14 }; // 0x006E5DA8
#pragma comment(linker, "/alternatename:?gaDirection16To8@@3QBEB=_gData_006E5DA8")

extern "C" const unsigned char gData_006E5DB8[8] = { 3, 3, 5, 5, 7, 7, 1, 1 }; // 0x006E5DB8
#pragma comment(linker, "/alternatename:?gaDirection8To4Alt@@3QBEB=_gData_006E5DB8")

extern "C" const unsigned char gData_006E5DC0[16] = { 2, 2, 4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14, 14, 0, 0 }; // 0x006E5DC0
#pragma comment(linker, "/alternatename:?gaDirection16To8Alt@@3QBEB=_gData_006E5DC0")

D2CmpSubTilePosStrc gatSubTilePositions[25] = { // 0x00743500
    { 64, 0 },
    { 80, 8 },
    { 96, 16 },
    { 112, 24 },
    { 128, 32 },
    { 48, 8 },
    { 64, 16 },
    { 80, 24 },
    { 96, 32 },
    { 112, 40 },
    { 32, 16 },
    { 48, 24 },
    { 64, 32 },
    { 80, 40 },
    { 96, 48 },
    { 16, 24 },
    { 32, 32 },
    { 48, 40 },
    { 64, 48 },
    { 80, 56 },
    { 0, 32 },
    { 16, 40 },
    { 32, 48 },
    { 48, 56 },
    { 64, 64 }
};

extern "C" const char* gData_007435C8[15] = { // 0x007435C8
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};
