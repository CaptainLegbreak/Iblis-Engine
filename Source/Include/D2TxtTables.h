#pragma once
// Records of the level maze/sub/warp, item type, book, overlay and unique-monster-mod tables

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Drlg.h"

struct D2DrlgFileStrc;
struct D2LvlMazeTxt;
struct D2LvlSubTxt;
struct D2LvlWarpTxt;
struct D2ItemTypesTxt;
struct D2BooksTxt;
struct D2OverlayTxt;
struct D2MonUModTxt;

struct D2LvlMazeTxt
{
    int dwLevelId; // 0x00
    int dwRooms[3]; // 0x04
    int dwSizeX; // 0x10
    int dwSizeY; // 0x14
    int dwMerge; // 0x18
};

struct D2LvlSubTxt
{
    int dwType; // 0x00
    char szFile[60]; // 0x04
    int dwCheckAll; // 0x40
    int dwBordType; // 0x44
    int dwDt1Mask; // 0x48
    int dwGridSize; // 0x4C
    D2DrlgFileStrc* pDrlgFile; // 0x50
    D2DrlgGridStrc pTileTypeGrid[4]; // 0x54
    D2DrlgGridStrc pWallGrid[4]; // 0xA4
    D2DrlgGridStrc pFloorGrid; // 0xF4
    D2DrlgGridStrc pShadowGrid; // 0x108
    int nProb[5]; // 0x11C
    int nTrials[5]; // 0x130
    int nMax[5]; // 0x144
    int dwExpansion; // 0x158
};

struct D2LvlWarpTxt
{
    int dwLevelId; // 0x00
    int dwSelectX; // 0x04
    int dwSelectY; // 0x08
    int dwSelectDX; // 0x0C
    int dwSelectDY; // 0x10
    int dwExitWalkX; // 0x14
    int dwExitWalkY; // 0x18
    int dwOffsetX; // 0x1C
    int dwOffsetY; // 0x20
    int dwLitVersion; // 0x24
    int dwTiles; // 0x28
    char szDirection[4]; // 0x2C
};

struct D2ItemTypesTxt
{
    char szCode[4]; // 0x00
    short nEquiv1; // 0x04
    short nEquiv2; // 0x06
    unsigned char nRepair; // 0x08
    unsigned char nBody; // 0x09
    unsigned char nBodyLoc1; // 0x0A
    unsigned char nBodyLoc2; // 0x0B
    short wShoots; // 0x0C
    short wQuiver; // 0x0E
    unsigned char nThrowable; // 0x10
    unsigned char nReload; // 0x11
    unsigned char nReEquip; // 0x12
    unsigned char nAutoStack; // 0x13
    unsigned char nMagic; // 0x14
    unsigned char nRare; // 0x15
    unsigned char nNormal; // 0x16
    unsigned char nCharm; // 0x17
    unsigned char nGem; // 0x18
    unsigned char nBeltable; // 0x19
    unsigned char nMaxSock1; // 0x1A
    unsigned char nMaxSock25; // 0x1B
    unsigned char nMaxSock40; // 0x1C
    unsigned char nTreasureClass; // 0x1D
    unsigned char nRarity; // 0x1E
    unsigned char nStaffMods; // 0x1F
    unsigned char nCostFormula; // 0x20
    unsigned char nClass; // 0x21
    unsigned char nStorePage; // 0x22
    unsigned char nVarInvGfx; // 0x23
    char szInvGfx[6][32]; // 0x24
};

struct D2BooksTxt
{
    unsigned short wStr; // 0x00
    unsigned char nSpellIcon; // 0x02
    unsigned char pad0x03; // 0x03
    int dwPSpell; // 0x04
    int dwScrollSkillId; // 0x08
    int dwBookSkillId; // 0x0C
    unsigned int dwBaseCost; // 0x10
    int dwCostPerCharge; // 0x14
    int dwScrollSpellCode; // 0x18
    int dwBookSpellCode; // 0x1C
};

struct D2OverlayTxt
{
    unsigned short wOverlay; // 0x00
    char szFilename[64]; // 0x02
    unsigned short wVersion; // 0x42
    unsigned int dwFrames; // 0x44
    unsigned char nPreDraw; // 0x48
    unsigned int dw1ofN; // 0x4C
    unsigned char nDir; // 0x50
    unsigned char nOpen; // 0x51
    unsigned char nBeta; // 0x52
    unsigned int dwOffsetX; // 0x54
    unsigned int dwOffsetY; // 0x58
    unsigned int dwHeight[4]; // 0x5C
    unsigned int dwAnimRate; // 0x6C
    unsigned int dwInitRadius; // 0x70
    unsigned int dwRadius; // 0x74
    unsigned int dwLoopWaitTime; // 0x78
    unsigned char nTrans; // 0x7C
    unsigned char nRed; // 0x7D
    unsigned char nGreen; // 0x7E
    unsigned char nBlue; // 0x7F
    unsigned char nNumDirections; // 0x80
    unsigned char nLocalBlood; // 0x81
    unsigned short pad0x82; // 0x82
};

struct D2MonUModTxt
{
    unsigned int dwUniqueMod; // 0x00
    unsigned short wVersion; // 0x04
    unsigned char nEnabled; // 0x06
    unsigned char nXfer; // 0x07
    unsigned char nChampion; // 0x08
    unsigned char nFPick; // 0x09
    short wExclude[2]; // 0x0A
    unsigned short wCPick[3]; // 0x0E
    unsigned short wUPick[3]; // 0x14
    unsigned short pad0x1A; // 0x1A
    unsigned int dwConstants; // 0x1C
};

D2_CHECK_SIZE(D2LvlMazeTxt, 0x1C);
D2_CHECK_SIZE(D2LvlSubTxt, 0x15C);
D2_CHECK_SIZE(D2LvlWarpTxt, 0x30);
D2_CHECK_SIZE(D2ItemTypesTxt, 0xE4);
D2_CHECK_SIZE(D2BooksTxt, 0x20);
D2_CHECK_SIZE(D2OverlayTxt, 0x84);
D2_CHECK_SIZE(D2MonUModTxt, 0x20);

struct D2UniqueNameTxt
{
    unsigned short wStringId; // 0x00
};

D2_CHECK_SIZE(D2UniqueNameTxt, 0x2);
