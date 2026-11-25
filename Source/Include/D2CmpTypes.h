#pragma once
// D2CMP sprite, DC6, tile library and COF layouts

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelFileStrc;
struct D2CelStrc;
struct D2CmpDC6CelStrc;
struct D2CmpTileNodeStrc;
struct D2CofDataStrc;
struct D2SpriteCacheNodeStrc;
struct AsyncData;
struct D2CmpSpriteContextStrc;
struct D2CmpGfxHashEntryStrc;
struct D2CmpGfxInfoStrc;
struct D2CmpTileBlockStrc;
struct D2CmpSpriteEntryStrc;
struct D2CmpDC6FrameStrc;
struct D2CmpSpriteFileStrc;
struct D2CmpLoadDescStrc;
struct D2CmpDC6HeaderStrc;
struct D2CmpTileLibraryStrc;
struct D2CmpTileStrc;
struct D2CmpSubTileRecordStrc;
struct D2CmpCelContextStrc;
struct D2CmpBitCursorStrc;
struct D2CofNodeStrc;
struct D2CofInfoStrc;
struct D2CofLayerStrc;

struct D2CmpColorStrc
{
    unsigned char nRed; // 0x00
    unsigned char nGreen; // 0x01
    unsigned char nBlue; // 0x02
    unsigned char nPad; // 0x03
};

struct D2CmpTileInfoStrc
{
    char data[25]; // 0x00
};

struct D2CmpSubTileHeaderStrc
{
    int unk0x00; // 0x00
    int unk0x04; // 0x04
    unsigned short nFlags; // 0x08
    unsigned short nLength; // 0x0A
    int unk0x0C; // 0x0C
};

struct D2CmpSpriteContextStrc
{
    int nFrame; // 0x00
    unsigned int dwFlags; // 0x04
    int nType; // 0x08
    int nIndex; // 0x0C
    int nMode; // 0x10
    int nOverlay; // 0x14
    union
    {
        struct
        {
            char szToken[4]; // 0x18
            char szComponent[4]; // 0x1C
            char szArmorType[4]; // 0x20
            char szMode[4]; // 0x24
            char szHitClass[4]; // 0x28
        };
        unsigned int dwName[5]; // 0x18
    };
    const char* pName; // 0x2C
    int nFrames; // 0x30
    void* pCel; // 0x34
    int unk0x38; // 0x38
    void* pFrame; // 0x3C
    int nDirection; // 0x40
    unsigned int dwGfxFlags; // 0x44
};

struct D2CmpGfxHashEntryStrc
{
    unsigned int nIndex; // 0x00
    int nSub; // 0x04
    int nKey1; // 0x08
    int nKey2; // 0x0C
    int nKey3; // 0x10
    int nKey4; // 0x14
    int nKey5; // 0x18
    unsigned int nValue; // 0x1C
    union
    {
        int nArg; // 0x20
        D2CmpGfxInfoStrc* pInfo; // 0x20
    };
    D2SpriteCacheNodeStrc* pHolder; // 0x24
    D2CmpGfxHashEntryStrc* pPrev; // 0x28
    D2CmpGfxHashEntryStrc* pNext; // 0x2C
};

struct D2CmpTileBlockStrc
{
    int nLightDirection; // 0x00
    short nRoofHeight; // 0x04
    unsigned short nMaterialFlags; // 0x06
    int nHeight; // 0x08
    int nWidth; // 0x0C
    int nHeightToBottom; // 0x10
    int nOrientation; // 0x14
    int nIndex; // 0x18
    int nSubIndex; // 0x1C
    int nRarity; // 0x20
    union
    {
        int nOwnerId; // 0x24
        D2CmpColorStrc tColor; // 0x24
    };
    union
    {
        int unk0x28[7]; // 0x28
        D2CmpTileInfoStrc tInfo; // 0x28
    };
    unsigned short unk0x44; // 0x44
    unsigned char nFlags; // 0x46
    unsigned char unk0x47; // 0x47
    int nSubsOffset; // 0x48
    int nSubBytes; // 0x4C
    int nSubs; // 0x50
    D2CmpSubTileRecordStrc* pSubs; // 0x54
    char* pName; // 0x58
    void* pExtra; // 0x5C
};

struct D2CmpSpriteEntryStrc
{
    int nType; // 0x00
    int nArg04; // 0x04
    int nArg08; // 0x08
    int nArg0C; // 0x0C
    int nArg10; // 0x10
    int nArg14; // 0x14
    int nArg18; // 0x18
    int nArg1C; // 0x1C
    unsigned char nFlags; // 0x20
    unsigned char nFrames; // 0x21
    unsigned char nFirstFrame; // 0x22
    unsigned char nDirections; // 0x23
    unsigned char nFramesPerDirection; // 0x24
    unsigned char unk0x25; // 0x25
    unsigned short unk0x26; // 0x26
    int bFramesInitialized; // 0x28
    int aOffsets[33]; // 0x2C
    AsyncData* pAsync; // 0xB0
    D2SpriteCacheNodeStrc* pHolder; // 0xB4
};

struct D2CmpDC6FrameStrc
{
    int nFlip; // 0x00
    unsigned int nWidth; // 0x04
    unsigned int nHeight; // 0x08
    int nOffsetX; // 0x0C
    int nOffsetY_10; // 0x10
    int nOffsetY_14; // 0x14
    D2CmpDC6CelStrc* pCel; // 0x18
    int nLength; // 0x1C
    unsigned char pPixels[4]; // 0x20
};

struct D2CmpSpriteFileStrc
{
    unsigned int dwFlags; // 0x00
    int unk0x04[4]; // 0x04
    int nDirections; // 0x14
    int nFramesPerDirection; // 0x18
    unsigned int aOffsets[1]; // 0x1C
};

struct D2CmpLoadDescStrc
{
    void* pfnCallback; // 0x00
    D2CmpSpriteFileStrc* pFile; // 0x04
    unsigned char* pFlags; // 0x08
    int nFirstFrame; // 0x0C
    int nFrames; // 0x10
    int unk0x14[2]; // 0x14
};

struct D2CmpDC6HeaderStrc
{
    unsigned char nFlags; // 0x00
    unsigned char unk0x01; // 0x01
    unsigned char unk0x02; // 0x02
    unsigned char nDirections; // 0x03
    unsigned char nFrames; // 0x04
    unsigned char unk0x05; // 0x05
    unsigned short unk0x06; // 0x06
    int bFramesReady; // 0x08
    int aOffsets[1]; // 0x0C
    int unk0x10[2]; // 0x10
    D2CmpDC6FrameStrc* pFrames[1]; // 0x18
    int unk0x1C[29]; // 0x1C
    AsyncData* pAsync; // 0x90
};

struct D2CmpTileLibraryStrc
{
    int dwVersion; // 0x00
    unsigned int dwFlags; // 0x04
    char szName[260]; // 0x08
    int nBlocks; // 0x10C
    D2CmpTileBlockStrc* pBlocks; // 0x110
};

struct D2CmpTileStrc
{
    int nMinX; // 0x00
    int nMaxY; // 0x04
    int nMaxX; // 0x08
    int nMinY; // 0x0C
    int nLightDirection; // 0x10
    short nRoofHeight; // 0x14
    unsigned short nMaterialFlags; // 0x16
    int unk0x18[3]; // 0x18
    int nOrientation; // 0x24
    int nIndex; // 0x28
    int nSubIndex; // 0x2C
    int nRarity; // 0x30
    union
    {
        int nOwnerId; // 0x34
        D2CmpColorStrc tColor; // 0x34
    };
    union
    {
        struct
        {
            int unk0x38[6]; // 0x38
            unsigned char unk0x50; // 0x50
            unsigned char nType; // 0x51
            unsigned short unk0x52; // 0x52
        };
        D2CmpTileInfoStrc tInfo; // 0x38
    };
    int nCount; // 0x54
    D2CmpTileNodeStrc* pNodes; // 0x58
    D2CmpTileStrc* pNext; // 0x5C
};

struct D2CmpSubTileRecordStrc
{
    union
    {
        struct
        {
            unsigned short nX; // 0x00
            unsigned short nY; // 0x02
            short unk0x04; // 0x04
            unsigned char nGridX; // 0x06
            unsigned char nGridY; // 0x07
            unsigned short nFlags; // 0x08
            unsigned short nLength; // 0x0A
            int unk0x0C; // 0x0C
        };
        D2CmpSubTileHeaderStrc tHeader; // 0x00
    };
    unsigned char* ptData; // 0x10
};

struct D2CmpCelContextStrc
{
    unsigned int nFrame; // 0x00
    int unk0x04[12]; // 0x04
    D2CelFileStrc* pCelFile; // 0x34
    int unk0x38; // 0x38
    D2CelStrc* pCel; // 0x3C
    unsigned int nDirection; // 0x40
};

struct D2CmpBitCursorStrc
{
    unsigned int* pStart; // 0x00
    unsigned int* pData; // 0x04
    int nBits; // 0x08
    int nBitPos; // 0x0C

    unsigned char* GetBytePtr()
    {
        return (unsigned char*)pData + (nBitPos + 7) / 8;
    }

    void AlignToByte()
    {
        const unsigned int nPos = (nBitPos + 7) & ~7u;
        nBitPos = nPos & 0x1F;
        pData += nPos / 32;
    }

    void AlignToByteEnd()
    {
        const unsigned int nPos = (nBitPos + 7) & ~7u;
        pData += nPos / 32;
        nBitPos = nPos & 0x1F;
    }

    void AdvanceBits(int nCount)
    {
        int nPos = nBitPos + nCount;
        nBitPos = nPos & 0x1F;
        pData += nPos / 32;
    }

    unsigned char* sub_0060B180_GetBytePtr();
    void CodecSkipBits(int nBits);
    void sub_0060B1D0_AlignToByte();
    int sub_0060B1F0_GetBitPos();
};

struct D2CofNodeStrc
{
    int nRefCount; // 0x00
    unsigned int nMode; // 0x04
    unsigned int nClass; // 0x08
    unsigned int dwWeaponClass; // 0x0C
    unsigned int dwCofSize; // 0x10
    D2CofDataStrc* pCofData; // 0x14
    D2CofNodeStrc* pNext; // 0x18
    D2CofNodeStrc* pPrev; // 0x1C
};

struct D2CofInfoStrc
{
    D2CofNodeStrc* pCofNode; // 0x00
    D2CofInfoStrc* pNext; // 0x04
};

struct D2CofLayerStrc
{
    unsigned char nComponent; // 0x00
    unsigned char bShadow; // 0x01
    unsigned char bSelectable; // 0x02
    unsigned char nOverrideTransLvl; // 0x03
    unsigned char nNewTransLvl; // 0x04
    char szWeaponClass[4]; // 0x05
};

struct D2CofDataStrc
{
    unsigned char nLayers; // 0x00
    unsigned char nFramesPerDirection; // 0x01
    unsigned char nDirections; // 0x02
    unsigned char nVersion; // 0x03
    unsigned int unk0x04; // 0x04
    unsigned int nBoxLeft; // 0x08
    unsigned int nBoxRight; // 0x0C
    unsigned int nBoxTop; // 0x10
    unsigned int nBoxBottom; // 0x14
    unsigned int nAnimSpeed; // 0x18
    D2CofLayerStrc pLayers[1]; // 0x1C
};

struct D2CmpFindTilesSubStrc
{
    int unk0x00; // 0x00
    D2CmpFindTilesSubStrc* pNext; // 0x04
};

struct D2CmpFindTilesNodeStrc
{
    int unk0x00[3]; // 0x00
    D2CmpFindTilesSubStrc* pSubs; // 0x0C
    D2CmpFindTilesNodeStrc* pNext; // 0x10
};

D2_CHECK_SIZE(D2CmpColorStrc, 0x4);
D2_CHECK_SIZE(D2CmpTileInfoStrc, 0x19);
D2_CHECK_SIZE(D2CmpSubTileHeaderStrc, 0x10);
D2_CHECK_SIZE(D2CmpSpriteContextStrc, 0x48);
D2_CHECK_SIZE(D2CmpGfxHashEntryStrc, 0x30);
D2_CHECK_SIZE(D2CmpTileBlockStrc, 0x60);
D2_CHECK_SIZE(D2CmpSpriteEntryStrc, 0xB8);
D2_CHECK_SIZE(D2CmpDC6FrameStrc, 0x24);
D2_CHECK_SIZE(D2CmpSpriteFileStrc, 0x20);
D2_CHECK_SIZE(D2CmpLoadDescStrc, 0x1C);
D2_CHECK_SIZE(D2CmpDC6HeaderStrc, 0x94);
D2_CHECK_SIZE(D2CmpTileLibraryStrc, 0x114);
D2_CHECK_SIZE(D2CmpTileStrc, 0x60);
D2_CHECK_SIZE(D2CmpSubTileRecordStrc, 0x14);
D2_CHECK_SIZE(D2CmpCelContextStrc, 0x44);
D2_CHECK_SIZE(D2CmpBitCursorStrc, 0x10);
D2_CHECK_SIZE(D2CofNodeStrc, 0x20);
D2_CHECK_SIZE(D2CofInfoStrc, 0x8);
D2_CHECK_SIZE(D2CofLayerStrc, 0x9);
D2_CHECK_SIZE(D2CofDataStrc, 0x28);
