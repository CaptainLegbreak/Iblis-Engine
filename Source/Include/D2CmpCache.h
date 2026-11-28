#pragma once
// D2CMP sprite cache, tile records, DCC decoder and Storm container records

#include "D2Check.h"
#include "D2Structs.h"
#include "D2StormLink.h"
#include "D2SysTypes.h"
#include "D2LRUNode.h"
#include "D2CmpTileRecord.h"
#include "D2SpriteCache.h"

struct D2SpriteCacheNodeStrc;
struct D2TileLibraryEntryStrc;
struct D2TileLibraryHashStrc;
struct D2SpriteCacheStrc;
struct D2StormSlotListStrc;
struct D2StormSlotArrayStrc;
struct D2StormListEStrc;
struct D2GameHashTableStrc;
struct D2TileRecordStrc;
struct D2StormEntryArrayStrc;
struct D2DccIterStrc;
struct D2DccFrameStrc;
struct D2DccDirStrc;
struct D2CmpByteRunStrc;
struct D2DccOutTableStrc;
struct D2DccHeaderStrc;
struct D2DccFileStrc;
struct D2DccCellStrc;
struct D2TileLibraryHeaderStrc;
struct D2LRUNodeStrc;

struct D2StormSlotListStrc
{
    int m_linkoffset; // 0x00
    int unused0x04[2]; // 0x04
};

struct D2StormSlotArrayStrc
{
    int unused0x00[4]; // 0x00
};

struct D2StormListEStrc
{
    int m_linkoffset; // 0x00
    D2StormLinkStrc m_terminator; // 0x04
};

struct D2GameHashTableStrc
{
    int unused0x00; // 0x00
    D2StormSlotListStrc m_fulllist; // 0x04
    unsigned int m_fullnessIndicator; // 0x10
    D2StormSlotArrayStrc m_slotlistarray; // 0x14
    unsigned int m_slotmask; // 0x24
};

struct D2StormEntryArrayStrc
{
    int unused0x00[4]; // 0x00
};

struct D2DccIterStrc
{
    int nFrame; // 0x00
    int nWidth; // 0x04
    int nHeight; // 0x08
    int nX0; // 0x0C
    int nY0; // 0x10
    int nCellsX; // 0x14
    int nCellsY; // 0x18
    int nCellRow; // 0x1C
    int nCell; // 0x20
    int nX; // 0x24
    int nY; // 0x28
    int nPixelRow; // 0x2C
    int nPixel; // 0x30
    int nStepX; // 0x34
    int nStepY; // 0x38
};

struct D2DccFrameStrc
{
    int nVar0; // 0x00
    int nWidth; // 0x04
    int nHeight; // 0x08
    int nXOffset; // 0x0C
    int nYOffset; // 0x10
    int nOptBytes; // 0x14
    unsigned char* pOptData; // 0x18
    int nCodedBytes; // 0x1C
    int nCellsX; // 0x20
    int nCellsY; // 0x24
    int bBottomUp; // 0x28
};

struct D2DccDirStrc
{
    D2DccHeaderStrc* pHeader; // 0x00
    D2DccFrameStrc* pFrames; // 0x04
    int nMinX; // 0x08
    int nMinY; // 0x0C
    int nBoxWidth; // 0x10
    int nBoxHeight; // 0x14
    int nDir; // 0x18
    int nFrames; // 0x1C
    int nCells; // 0x20
    int nCellsTotal; // 0x24
    int nCellsPerRow; // 0x28
};

struct D2CmpByteRunStrc
{
    unsigned char* pData; // 0x00
    int nCount; // 0x04
};

struct D2DccOutTableStrc
{
    int unused0x00[3]; // 0x00
    int dwDirOffsets[1]; // 0x0C
};

struct D2DccHeaderStrc
{
    int n04; // 0x00
    int n08; // 0x04
    int n14; // 0x08
    int nFrames; // 0x0C
    int unused0x10; // 0x10
};

struct D2DccFileStrc
{
    int unused0x00; // 0x00
    int n04; // 0x04
    int n08; // 0x08
    int unused0x0C[2]; // 0x0C
    int n14; // 0x14
    int nFrames; // 0x18
    int dwDirOffsets[1]; // 0x1C
};

struct D2DccCellStrc
{
    unsigned char* pColors; // 0x00
    unsigned char* pDst; // 0x04
    int nPitch; // 0x08
    int nWidth; // 0x0C
    int nHeight; // 0x10
};


D2_CHECK_SIZE(D2SpriteCacheStrc, 0x50);
D2_CHECK_SIZE(D2StormSlotListStrc, 0xC);
D2_CHECK_SIZE(D2StormSlotArrayStrc, 0x10);
D2_CHECK_SIZE(D2StormListEStrc, 0xC);
D2_CHECK_SIZE(D2GameHashTableStrc, 0x28);
D2_CHECK_SIZE(D2TileRecordStrc, 0x110);
D2_CHECK_SIZE(D2StormEntryArrayStrc, 0x10);
D2_CHECK_SIZE(D2DccIterStrc, 0x3C);
D2_CHECK_SIZE(D2DccFrameStrc, 0x2C);
D2_CHECK_SIZE(D2DccDirStrc, 0x2C);
D2_CHECK_SIZE(D2CmpByteRunStrc, 0x8);
D2_CHECK_SIZE(D2DccOutTableStrc, 0x10);
D2_CHECK_SIZE(D2DccHeaderStrc, 0x14);
D2_CHECK_SIZE(D2DccFileStrc, 0x20);
D2_CHECK_SIZE(D2DccCellStrc, 0x14);
D2_CHECK_SIZE(D2TileLibraryHeaderStrc, 0x114);
