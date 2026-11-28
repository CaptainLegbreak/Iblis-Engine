#pragma once
// Records of the shrine, rune, gem, monster sound, belt and cube recipe tables

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Records.h"
#include "D2ClientTypes.h"

struct D2ShrinesTxt;
struct D2RunesTxt;
struct D2GemsTxt;
struct D2MonSoundsTxt;
struct D2BeltsTxt;
struct D2CubeInputItem;
struct D2CubeParam;
struct D2CubeOutputItem;
struct D2CubeMainTxt;

struct D2ShrinesTxt
{
    unsigned char bCode; // 0x00
    unsigned char pad0x01; // 0x01
    unsigned short pad0x02; // 0x02
    int dwArg0; // 0x04
    int dwArg1; // 0x08
    int dwDurationInFrames; // 0x0C
    unsigned char nResetTimeInMins; // 0x10
    unsigned char nRarity; // 0x11
    unsigned short szViewname; // 0x12
    unsigned char unused0x14[30]; // 0x14
    char szNiftyphrase[128]; // 0x32
    unsigned char nEffectClass; // 0xB2
    unsigned char pad0xB3; // 0xB3
    unsigned int dwLevelMin; // 0xB4
};

struct D2RunesTxt
{
    char szName[64]; // 0x00
    char szRuneName[64]; // 0x40
    unsigned char nComplete; // 0x80
    unsigned char nServer; // 0x81
    unsigned short wStringId; // 0x82
    unsigned short unused0x84; // 0x84
    short wIType[6]; // 0x86
    short wEType[3]; // 0x92
    int nRune[6]; // 0x98
    D2PropertyStrc pProperties[7]; // 0xB0
};

struct D2GemsTxt
{
    char szName[32]; // 0x00
    char szLetter[6]; // 0x20
    unsigned short pad0x26; // 0x26
    union
    {
        unsigned char szItemCode[4]; // 0x28
        int dwItemCode; // 0x28
    };
    unsigned short wStringId; // 0x2C
    unsigned char nNumMods; // 0x2E
    unsigned char nTransform; // 0x2F
    D2PropertyStrc pProperties[3][3]; // 0x30
};

struct D2MonSoundsTxt
{
    unsigned int dwId; // 0x00
    unsigned int dwAttack1; // 0x04
    unsigned int dwAtt1Del; // 0x08
    unsigned int dwAtt1Prb; // 0x0C
    unsigned int dwAttack2; // 0x10
    unsigned int dwAtt2Del; // 0x14
    unsigned int dwAtt2Prb; // 0x18
    unsigned int dwWeapon1; // 0x1C
    unsigned int dwWea1Del; // 0x20
    unsigned int dwWea1Vol; // 0x24
    unsigned int dwWeapon2; // 0x28
    unsigned int dwWea2Del; // 0x2C
    unsigned int dwWea2Vol; // 0x30
    unsigned int dwHitSound; // 0x34
    unsigned int dwHitDelay; // 0x38
    unsigned int dwDeathSound; // 0x3C
    unsigned int dwDeaDelay; // 0x40
    unsigned int dwSkill[4]; // 0x44
    unsigned int dwFootstep; // 0x54
    unsigned int dwFootstepLayer; // 0x58
    unsigned int dwFsCnt; // 0x5C
    unsigned int dwFsOff; // 0x60
    unsigned int dwFsPrb; // 0x64
    unsigned int dwNeutral; // 0x68
    unsigned int dwNeuTime; // 0x6C
    unsigned int dwInit; // 0x70
    unsigned int dwTaunt; // 0x74
    unsigned int dwFlee; // 0x78
    unsigned char nCvtMo1; // 0x7C
    unsigned char nCvtTgt1; // 0x7D
    unsigned short pad0x7E; // 0x7E
    int dwCvtSk1; // 0x80
    unsigned char nCvtMo2; // 0x84
    unsigned char nCvtTgt2; // 0x85
    unsigned short pad0x86; // 0x86
    int dwCvtSk2; // 0x88
    unsigned char nCvtMo3; // 0x8C
    unsigned char nCvtTgt3; // 0x8D
    unsigned short pad0x8E; // 0x8E
    int dwCvtSk3; // 0x90
};

struct D2BeltsTxt
{
    unsigned char nIndex; // 0x00
    unsigned char pad0x01; // 0x01
    unsigned short pad0x02; // 0x02
    int nBoxes; // 0x04
    D2InvRectStrc beltBoxes[16]; // 0x08
};

struct D2CubeInputItem
{
    unsigned short wInputFlags; // 0x00
    unsigned short wItem; // 0x02
    unsigned short wItemID; // 0x04
    unsigned char nQuality; // 0x06
    unsigned char nQuantity; // 0x07
};

struct D2CubeParam
{
    int nMod; // 0x00
    short nModParam; // 0x04
    short nModMin; // 0x06
    short nModMax; // 0x08
    unsigned char nModChance; // 0x0A
    unsigned char pad0x0B; // 0x0B
};

struct D2CubeOutputItem
{
    unsigned short wItemFlags; // 0x00
    unsigned short wBaseItemId; // 0x02
    unsigned short wItemID; // 0x04
    unsigned char nQuality; // 0x06
    unsigned char nQuantity; // 0x07
    unsigned char nType; // 0x08
    unsigned char nLvl; // 0x09
    unsigned char nPLvl; // 0x0A
    unsigned char nILvl; // 0x0B
    unsigned short wPrefixId[3]; // 0x0C
    unsigned short wSuffixId[3]; // 0x12
    D2CubeParam pParam[5]; // 0x18
};

struct D2CubeMainTxt
{
    unsigned char nEnabled; // 0x00
    unsigned char nLadder; // 0x01
    unsigned char nMinDiff; // 0x02
    unsigned char nClass; // 0x03
    unsigned char nOp; // 0x04
    unsigned char pad0x05; // 0x05
    unsigned short pad0x06; // 0x06
    int nParam; // 0x08
    int nValue; // 0x0C
    unsigned char nNumInputs; // 0x10
    unsigned char pad0x11; // 0x11
    unsigned short wVersion; // 0x12
    D2CubeInputItem pInputItem[7]; // 0x14
    D2CubeOutputItem pOutputItem[3]; // 0x4C
};

D2_CHECK_SIZE(D2ShrinesTxt, 0xB8);
D2_CHECK_SIZE(D2RunesTxt, 0x120);
D2_CHECK_SIZE(D2GemsTxt, 0xC0);
D2_CHECK_SIZE(D2MonSoundsTxt, 0x94);
D2_CHECK_SIZE(D2BeltsTxt, 0x108);
D2_CHECK_SIZE(D2CubeInputItem, 0x08);
D2_CHECK_SIZE(D2CubeParam, 0x0C);
D2_CHECK_SIZE(D2CubeOutputItem, 0x54);
D2_CHECK_SIZE(D2CubeMainTxt, 0x148);
