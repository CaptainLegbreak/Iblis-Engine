#pragma once
// D2Glide: Glide texture info, sprite vertex, and the texture, tile and floor cache structs

#include "D2Check.h"
#include "D2Structs.h"

struct D2GfxDataStrc;
struct D2TileLibraryEntryStrc;
struct D2GlideTexSlotStrc;
struct D2GrTexInfoStrc;
struct D2GrLfbInfoStrc;
struct D2GlideSpriteVertexStrc;
struct D2GlideTexInfoStrc;
struct D2GlideTexCacheEntryStrc;
struct D2GlideTexCacheStrc;
struct D2GlideTileStrc;
struct D2GlideTileCacheEntryStrc;
struct D2GlideTileCacheStrc;
struct D2GlideFloorCacheEntryStrc;
struct D2GlideFloorCacheStrc;

struct D2GlideTexSlotStrc
{
    int nCache; // 0x00
    int nId; // 0x04
};

struct D2GrTexInfoStrc
{
    int nSmallLodLog2; // 0x00
    int nLargeLodLog2; // 0x04
    int nAspectRatioLog2; // 0x08
    int nFormat; // 0x0C
    void* pData; // 0x10
};

struct D2GrLfbInfoStrc
{
    int size; // 0x00
    void* lfbPtr; // 0x04
    unsigned int strideInBytes; // 0x08
    int writeMode; // 0x0C
    int origin; // 0x10
};

struct D2GlideSpriteVertexStrc
{
    float x; // 0x00
    float y; // 0x04
    unsigned int dwColor; // 0x08
    float oow; // 0x0C
    float sow; // 0x10
    float tow; // 0x14
    float unused0x18; // 0x18
};

struct D2GlideTexInfoStrc
{
    D2GfxDataStrc* pContext; // 0x00
    int nWidth; // 0x04
    int nHeight; // 0x08
    int nOffsetX; // 0x0C
    int nOffsetY; // 0x10
    int nTexWidth; // 0x14
    int nTexHeight; // 0x18
    int nTexSize; // 0x1C
    float fS0; // 0x20
    float fS1; // 0x24
    float fT0; // 0x28
    float fT1; // 0x2C
    int nLod; // 0x30
    int nAspect; // 0x34
};

struct D2GlideTexCacheEntryStrc
{
    int nId; // 0x00
    unsigned int nAddress; // 0x04
    D2GlideTexSlotStrc* pOwner; // 0x08
    int nOwnerIndex; // 0x0C
    int nPalette; // 0x10
    D2GlideTexCacheEntryStrc* pNext; // 0x14
    D2GlideTexCacheEntryStrc* pPrev; // 0x18
};

struct D2GlideTexCacheStrc
{
    unsigned int nBlockSize; // 0x00
    int nCount; // 0x04
    int nUsed; // 0x08
    D2GlideTexCacheEntryStrc* pHead; // 0x0C
    D2GlideTexCacheEntryStrc* pTail; // 0x10
    D2GlideTexCacheEntryStrc* pFreeHead; // 0x14
    D2GlideTexCacheEntryStrc* pFreeTail; // 0x18
    D2GlideTexCacheEntryStrc* pEntries; // 0x1C
};

struct D2GlideTileStrc
{
    short nPosX; // 0x00
    short nPosY; // 0x02
    short nCacheIndex; // 0x04
    short unused0x06; // 0x06
    unsigned short nFormat; // 0x08
    unsigned short nLength; // 0x0A
    int unused0x0C; // 0x0C
    unsigned char* pData; // 0x10
};

struct D2GlideTileCacheEntryStrc
{
    int nId; // 0x00
    unsigned int nAddress; // 0x04
    D2GlideTileStrc* pTile; // 0x08
    D2GlideTileCacheEntryStrc* pNext; // 0x0C
    D2GlideTileCacheEntryStrc* pPrev; // 0x10
};

struct D2GlideTileCacheStrc
{
    unsigned int nBlockSize; // 0x00
    int nCount; // 0x04
    int nUsed; // 0x08
    D2GlideTileCacheEntryStrc* pHead; // 0x0C
    D2GlideTileCacheEntryStrc* pTail; // 0x10
    D2GlideTileCacheEntryStrc* pFreeHead; // 0x14
    D2GlideTileCacheEntryStrc* pFreeTail; // 0x18
    D2GlideTileCacheEntryStrc* pEntries; // 0x1C
};

struct D2GlideFloorCacheEntryStrc
{
    int nId; // 0x00
    unsigned int nAddress; // 0x04
    D2TileLibraryEntryStrc* pTile; // 0x08
    D2GlideFloorCacheEntryStrc* pNext; // 0x0C
    D2GlideFloorCacheEntryStrc* pPrev; // 0x10
};

struct D2GlideFloorCacheStrc
{
    unsigned int nBlockSize; // 0x00
    int nCount; // 0x04
    int nUsed; // 0x08
    D2GlideFloorCacheEntryStrc* pHead; // 0x0C
    D2GlideFloorCacheEntryStrc* pTail; // 0x10
    D2GlideFloorCacheEntryStrc* pFreeHead; // 0x14
    D2GlideFloorCacheEntryStrc* pFreeTail; // 0x18
    D2GlideFloorCacheEntryStrc* pEntries; // 0x1C
};

D2_CHECK_SIZE(D2GlideTexSlotStrc, 0x8);
D2_CHECK_SIZE(D2GrTexInfoStrc, 0x14);
D2_CHECK_SIZE(D2GrLfbInfoStrc, 0x14);
D2_CHECK_SIZE(D2GlideSpriteVertexStrc, 0x1C);
D2_CHECK_SIZE(D2GlideTexInfoStrc, 0x38);
D2_CHECK_SIZE(D2GlideTexCacheEntryStrc, 0x1C);
D2_CHECK_SIZE(D2GlideTexCacheStrc, 0x20);
D2_CHECK_SIZE(D2GlideTileStrc, 0x14);
D2_CHECK_SIZE(D2GlideTileCacheEntryStrc, 0x14);
D2_CHECK_SIZE(D2GlideTileCacheStrc, 0x20);
D2_CHECK_SIZE(D2GlideFloorCacheEntryStrc, 0x14);
D2_CHECK_SIZE(D2GlideFloorCacheStrc, 0x20);
