#pragma once
// D2Win: the window control header, fonts and their glyphs, the font and sprite caches, and composite units.

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelFileStrc;
struct D2CharStrc;
struct D2CmpGfxHashEntryStrc;
struct D2FontStrc;
struct D2WinControlStrc;
struct D2FontCacheStrc;
struct D2CmpSpriteEntryStrc;
struct D2SpriteCacheNodeStrc;
struct SMSGHANDLER_PARAMS;
struct D2CofInfoStrc;
struct D2GfxInfoStrc;
struct D2CompositeUnitStrc;
struct D2CompItemStrc;

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);
typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

struct D2WinControlStrc
{
    int eType; // 0x00
    D2CelFileStrc* pCellFile; // 0x04
    unsigned int dwFlags; // 0x08
    int nImageX; // 0x0C
    int nImageY; // 0x10
    int nWidth; // 0x14
    int nHeight; // 0x18
    D2WinControlFn pfDraw; // 0x1C
    D2WinControlFn pfInitialize; // 0x20
    D2WinMsgHandler pfHandleMouseDown; // 0x24
    D2WinMsgHandler pfHandleMouseUp; // 0x28
    D2WinMsgHandler pfHandleCharInput; // 0x2C
    D2WinMsgHandler pfHandleVirtualKeyInput; // 0x30
    D2WinMsgHandler field_34; // 0x34
    D2WinControlFn pfShouldMouseInputBeHandled; // 0x38
    D2WinControlStrc* pNext; // 0x3C
};

struct D2FontCacheStrc
{
    D2CelFileStrc* pCellFile; // 0x00
    D2FontStrc* pFontInfo[2]; // 0x04
    D2CharStrc* pCharInfo; // 0x0C
    unsigned int dwShiftedTickCount; // 0x10
};

struct D2SpriteCacheNodeStrc
{
    union
    {
        void* pData; // 0x00
        D2CmpSpriteEntryStrc* pEntry; // 0x00
    };
    unsigned int nSize; // 0x04
    union
    {
        D2CmpGfxHashEntryStrc* pRecord; // 0x08
        unsigned int nKey; // 0x08
    };
    unsigned int dwFlags; // 0x0C
    unsigned int dwTick; // 0x10
    D2SpriteCacheNodeStrc* pNext; // 0x14
    D2SpriteCacheNodeStrc* pPrev; // 0x18
};

D2_CHECK_SIZE(D2WinControlStrc, 0x40);
D2_CHECK_SIZE(D2FontCacheStrc, 0x14);
D2_CHECK_SIZE(D2SpriteCacheNodeStrc, 0x1C);

struct D2CharStrc
{
    unsigned short wChar; // 0x00
    unsigned char unused0x02; // 0x02
    unsigned char nWidth; // 0x03
    unsigned char nHeight; // 0x04
    unsigned char unused0x05; // 0x05
    unsigned short unused0x06; // 0x06
    unsigned short nImageIndex; // 0x08
    unsigned short unused0x0A; // 0x0A
    unsigned short unused0x0C; // 0x0C
};

struct D2FontStrc
{
    unsigned int dwHeader; // 0x00
    unsigned short unused0x04; // 0x04
    unsigned short unused0x06; // 0x06
    unsigned short nCharCount; // 0x08
    unsigned char nHeight; // 0x0A
    unsigned char nWidth; // 0x0B
    D2CharStrc aChars[1]; // 0x0C
};

struct D2GfxInfoStrc
{
    D2CofInfoStrc* pCofInfo; // 0x00
};

struct D2CompositeUnitStrc
{
    unsigned int dwFlags; // 0x00
    unsigned char nDirection; // 0x04
    unsigned char nDirections; // 0x05
    unsigned char pad0x06; // 0x06
    unsigned char pad0x07; // 0x07
    int nFrame; // 0x08
    int nFrameCount; // 0x0C
    int nAnimSpeed; // 0x10
    int nX; // 0x14
    int nY; // 0x18
    unsigned int nUnitIndex; // 0x1C
    unsigned int nMode; // 0x20
    unsigned int nWClassTokenIndex; // 0x24
    unsigned char nComponentColors[16]; // 0x28
    unsigned int dwArmorType[16]; // 0x38
    int nItemTypes[16]; // 0x78
    D2GfxInfoStrc* pGfxInfo; // 0xB8
    D2CelFileStrc* pEmblemCellFile; // 0xBC
    unsigned char nEmblemColor1; // 0xC0
    unsigned char nEmblemColor2; // 0xC1
    unsigned char pad0xC2; // 0xC2
    unsigned char pad0xC3; // 0xC3
    D2CompositeUnitStrc* pNext; // 0xC4
    D2CompositeUnitStrc* pPrev; // 0xC8
    unsigned short wszAccountName[64]; // 0xCC
    unsigned short wszCharName[64]; // 0x14C
    unsigned short wszGuildTag[16]; // 0x1CC
    unsigned short wszRealmName[32]; // 0x1EC
    int nCharLevel; // 0x22C
    unsigned int dwProductCode; // 0x230
};

struct D2CompItemStrc
{
    unsigned int dwCode; // 0x00
    int nWeaponClass; // 0x04
    int nItemType; // 0x08
};

D2_CHECK_SIZE(D2CharStrc, 0xE);
D2_CHECK_SIZE(D2FontStrc, 0x1C);
D2_CHECK_SIZE(D2GfxInfoStrc, 0x4);
D2_CHECK_SIZE(D2CompositeUnitStrc, 0x234);
D2_CHECK_SIZE(D2CompItemStrc, 0xC);
