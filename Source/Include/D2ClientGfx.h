#pragma once
// Client: unit graphics lists, layers, motion, monster graphics caches and hashed files.

#include "D2Check.h"
#include "D2Structs.h"

struct D2GfxLayerStrc;
struct D2MotionVectorStrc;
struct Unicode;
struct D2GfxMotionStrc;
struct D2GfxListNodeStrc;
struct D2GfxLayerHeaderStrc;
struct D2GfxNodeTargetStrc;
struct D2MonGfxCacheStrc;
struct D2HashedFileStrc;
struct D2HashedFileEntryStrc;

struct D2MotionVectorStrc
{
    int nX; // 0x00
    int nY; // 0x04
    int nZ; // 0x08
};

struct D2GfxMotionStrc
{
    union
    {
        unsigned int dwFlags; // 0x00
        struct
        {
            unsigned char nFlags0 : 5; // 0x00
            unsigned char bFlag5 : 1; // 0x00
        };
    };
    D2MotionVectorStrc tA; // 0x04
    D2MotionVectorStrc tB; // 0x10
    D2MotionVectorStrc tD; // 0x1C
    D2MotionVectorStrc tC; // 0x28
    int nClientX; // 0x34
    int nClientY; // 0x38
    int nClientZ; // 0x3C
    int nParam0; // 0x40
    int nParam1; // 0x44
    int nFrames; // 0x48
};

struct D2GfxListNodeStrc
{
    int nMode; // 0x00
    int nId; // 0x04
    union
    {
        D2GfxNodeTargetStrc* pTarget; // 0x08
        D2HashedFileEntryStrc* pFileEntry; // 0x08
    };
    int unused0x0C; // 0x0C
    D2GfxListNodeStrc* pNext; // 0x10
};

struct D2GfxLayerHeaderStrc
{
    unsigned char nLayers; // 0x00
    unsigned char unused0x01; // 0x01
    unsigned char nArg; // 0x02
};

struct D2MonGfxCacheStrc
{
    int nModeFlags[20]; // 0x00
    int aPending[20]; // 0x50
};

struct D2HashedFileStrc
{
    int bLoaded; // 0x00
    unsigned char* pData; // 0x04
    unsigned int nSize; // 0x08
    D2HashedFileEntryStrc* pEntries[512]; // 0x0C
};

struct D2HashedFileEntryStrc
{
    D2HashedFileEntryStrc* pNext; // 0x00
    unsigned int nFlags; // 0x04
    int nSize; // 0x08
    union
    {
        char szName[8]; // 0x0C
        unsigned int dwName[2]; // 0x0C
    };
    unsigned char* pData; // 0x14
    unsigned char aHeader[2]; // 0x18
    unsigned char nCheck; // 0x1A
    unsigned char pad0x1B; // 0x1B
};

D2_CHECK_SIZE(D2MotionVectorStrc, 0xC);
D2_CHECK_SIZE(D2GfxMotionStrc, 0x4C);
D2_CHECK_SIZE(D2GfxListNodeStrc, 0x14);
D2_CHECK_SIZE(D2GfxLayerHeaderStrc, 0x3);
D2_CHECK_SIZE(D2MonGfxCacheStrc, 0xA0);
D2_CHECK_SIZE(D2HashedFileStrc, 0x80C);
D2_CHECK_SIZE(D2HashedFileEntryStrc, 0x1C);
