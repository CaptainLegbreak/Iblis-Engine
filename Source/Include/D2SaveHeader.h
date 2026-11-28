#pragma once
// Game: the header of a character save (.d2s), as the server reads, checks and rewrites it.

#include "D2Check.h"

struct D2SaveSkillKeyStrc
{
    unsigned short nSkill; // 0x00
    unsigned short nKey; // 0x02
};

#pragma pack(push, 1)
struct D2SaveHeaderStrc
{
    unsigned int dwHeaderMagic; // 0x00
    unsigned int dwVersion; // 0x04
    unsigned int dwSize; // 0x08
    unsigned int dwChecksum; // 0x0C
    unsigned int dwWeaponSwitch; // 0x10
    char szName[16]; // 0x14
    unsigned int dwSaveFlags; // 0x24
    unsigned char nClass; // 0x28
    unsigned char nStats; // 0x29
    unsigned char nSkills; // 0x2A
    unsigned char nLevel; // 0x2B
    unsigned int dwCreateTime; // 0x2C
    unsigned int dwLasTime; // 0x30
    unsigned int dwPlayTime; // 0x34
    D2SaveSkillKeyStrc SkillKeys[16]; // 0x38
    unsigned short nLeftSkillId; // 0x78
    unsigned short nLeftSkillItemIndex; // 0x7A
    unsigned short nRightSkillId; // 0x7C
    unsigned short nRightSkillItemIndex; // 0x7E
    unsigned short nSwitchLeftSkillId; // 0x80
    unsigned short nSwitchLeftSkillItemIndex; // 0x82
    unsigned short nSwitchRightSkillId; // 0x84
    unsigned short nSwitchRightSkillItemIndex; // 0x86
    unsigned char nComponent[16]; // 0x88
    unsigned char nCompColor[16]; // 0x98
    unsigned char nTown[3]; // 0xA8
    unsigned int dwMapSeed; // 0xAB
    unsigned char MercSaveData[0x10]; // 0xAF
    char unused0xBF[0x10]; // 0xBF
    unsigned char nGuildEmblemBgColor; // 0xCF
    char dwLastLevel[0x7F]; // 0xD0
};
#pragma pack(pop)

D2_CHECK_SIZE(D2SaveSkillKeyStrc, 0x04);
D2_CHECK_SIZE(D2SaveHeaderStrc, 0x14F);
