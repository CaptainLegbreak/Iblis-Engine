#pragma once
// Data tables: the field descriptors of the .bin compiler, and the skill description and set item records.

#include "D2Check.h"
#include "D2Structs.h"

struct D2BinFieldStrc;
struct D2SkillDescTxt;
struct D2SetItemsTxt;

struct D2PropertyStrc
{
    int nProperty; // 0x00
    int nLayer; // 0x04
    int nMin; // 0x08
    int nMax; // 0x0C
};

struct D2BinFieldStrc
{
    const char* szFieldName; // 0x00
    int nFieldType; // 0x04
    int nFieldLength; // 0x08
    int nFieldOffset; // 0x0C
    void* pLinker; // 0x10
};

struct D2SkillDescTxt
{
    unsigned short wSkillDesc; // 0x00
    char nSkillPage; // 0x02
    unsigned char nSkillRow; // 0x03
    unsigned char nSkillColumn; // 0x04
    unsigned char nListRow; // 0x05
    unsigned char nListPool; // 0x06
    unsigned char nIconCel; // 0x07
    unsigned short wStrName; // 0x08
    unsigned short wStrShort; // 0x0A
    unsigned short wStrLong; // 0x0C
    unsigned short wStrAlt; // 0x0E
    unsigned short wStrMana; // 0x10
    unsigned short wDescDam; // 0x12
    unsigned short wDescFunc; // 0x14
    unsigned short pad0x16; // 0x16
    unsigned int dwDamCalc[2]; // 0x18
    unsigned char nPrgDamElem[3]; // 0x20
    unsigned char pad0x23; // 0x23
    int dwProgDmgMin[3]; // 0x24
    int dwProgDmgMax[3]; // 0x30
    short wDescMissile[3]; // 0x3C
    unsigned char nDescLine[17]; // 0x42
    unsigned char pad0x53; // 0x53
    unsigned short wDescTextA[17]; // 0x54
    unsigned short wDescTextB[17]; // 0x76
    int dwDescCalcA[17]; // 0x98
    int dwDescCalcB[17]; // 0xDC
};

struct D2SetItemsTxt
{
    short wSetItemId; // 0x00
    char szName[32]; // 0x02
    unsigned short wVersion; // 0x22
    unsigned short wTblIndex; // 0x24
    unsigned short pad0x26; // 0x26
    unsigned int dwItemCode; // 0x28
    short nSetId; // 0x2C
    short nSetItems; // 0x2E
    short wLvl; // 0x30
    unsigned short wLvlReq; // 0x32
    unsigned int dwRarity; // 0x34
    int dwCostMult; // 0x38
    int dwCostAdd; // 0x3C
    char nChrTransform; // 0x40
    char nInvTransform; // 0x41
    char szFlippyFile[32]; // 0x42
    char szInvFile[32]; // 0x62
    short wDropSound; // 0x82
    short wUseSound; // 0x84
    unsigned char nDropSfxFrame; // 0x86
    unsigned char nAddFunc; // 0x87
    D2PropertyStrc pProperties[9]; // 0x88
    D2PropertyStrc pPartialBoni[10]; // 0x118
};

D2_CHECK_SIZE(D2PropertyStrc, 0x10);
D2_CHECK_SIZE(D2BinFieldStrc, 0x14);
D2_CHECK_SIZE(D2SkillDescTxt, 0x120);
D2_CHECK_SIZE(D2SetItemsTxt, 0x1B8);
