#pragma once
// D2CMP tile nodes and lists, gfx hash table and block tables

#include "D2Check.h"

struct D2CmpGfxHashEntryStrc;
struct D2CmpTileStrc;
struct D2CmpTileNodeStrc;
struct D2CmpTileListStrc;
struct D2CmpGfxHashStrc;
struct D2CmpBlockTableBStrc;
struct D2Dc6FrameStrc;

struct D2CmpTileNodeStrc
{
    unsigned short nX; // 0x00
    unsigned short nY; // 0x02
    unsigned char nGridX; // 0x04
    unsigned char nGridY; // 0x05
    unsigned short nFormat; // 0x06
    unsigned short nLength; // 0x08
    unsigned short unk0x0A; // 0x0A
    unsigned char* pData; // 0x0C
    D2CmpTileNodeStrc* pNext; // 0x10
};

struct D2CmpTileListStrc
{
    int bFlag; // 0x00
    int nId; // 0x04
    int nCount; // 0x08
    D2CmpTileStrc* pFirst; // 0x0C
};

struct D2CmpGfxHashStrc
{
    int unk0x00[8192]; // 0x00
    D2CmpGfxHashEntryStrc* pBuckets[8192]; // 0x8000
};

struct D2CmpBlockTableBStrc
{
    unsigned char data[65536]; // 0x00

    void GfxHashDumpStats(); // 0x0060AB70
};

struct D2Dc6FrameStrc
{
    int nFlip; // 0x00
    int nWidth; // 0x04
    int nHeight; // 0x08
    int nXOffset; // 0x0C
    int nYOffset; // 0x10
    int unk0x14; // 0x14
    int nNextBlock; // 0x18
    int nLength; // 0x1C
    unsigned char abData[1]; // 0x20
    unsigned char unk0x21; // 0x21
    unsigned short unk0x22; // 0x22
};

D2_CHECK_SIZE(D2CmpTileNodeStrc, 0x14);
D2_CHECK_SIZE(D2CmpTileListStrc, 0x10);
D2_CHECK_SIZE(D2CmpGfxHashStrc, 0x10000);
D2_CHECK_SIZE(D2CmpBlockTableBStrc, 0x10000);
D2_CHECK_SIZE(D2Dc6FrameStrc, 0x24);
