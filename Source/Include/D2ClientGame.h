#pragma once
// Client: party roster pets, groups and corpses, player and monster commands, unit sound effects, weather, sound nodes and stored unit records.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"

struct D2RosterInfoStrc;
struct D2SkillStrc;
struct D2UnitStrc;
struct D2WeatherSplashStrc;
struct D2WeatherParticleStrc;
struct Unicode;
struct D2ClientSoundStrc;
struct SMSGHANDLER_PARAMS;
struct D2RosterPetStrc;
struct D2RosterGroupStrc;
struct D2RosterCorpseStrc;
struct D2PlayerCmdStrc;
struct D2MonCommandStrc;
struct D2UnitSfxNodeStrc;
struct D2WeatherStrc;
struct D2SoundNodeStrc;
struct D2StoredUnitRecordStrc;

struct D2RosterPetStrc
{
    int nClassId; // 0x00
    int nType; // 0x04
    int dwUnitId; // 0x08
    int dwOwnerId; // 0x0C
    int nArg10; // 0x10
    int unused0x14[2]; // 0x14
    int nLifePercent; // 0x1C
    int bDead; // 0x20
    D2ClientEntryStrc tEntry; // 0x24
    D2RosterPetStrc* pNext; // 0x30
};

struct D2RosterGroupStrc
{
    unsigned short wPartyId; // 0x00
    unsigned short unused0x02; // 0x02
    D2StoredUnitRecordStrc* pFirst; // 0x04
    D2RosterGroupStrc* pNext; // 0x08
};

struct D2RosterCorpseStrc
{
    int dwCorpseId; // 0x00
    D2RosterCorpseStrc* pNext; // 0x04
};

struct D2PlayerCmdStrc
{
    unsigned int dwFlags; // 0x00
    D2UnitStrc* pPlayer; // 0x04
    D2UnitStrc* pTarget; // 0x08
    int nX; // 0x0C
    int nY; // 0x10
    int nArg; // 0x14
    int nMode; // 0x18
    D2SkillStrc* pSkill; // 0x1C
};

struct D2MonCommandStrc
{
    int nX; // 0x00
    int nY; // 0x04
    int nZero; // 0x08
    int nPathValue; // 0x0C
    int nArg; // 0x10
    int nPathByte; // 0x14
    int nParam18; // 0x18
};

struct D2UnitSfxNodeStrc
{
    void* pUnitSfx; // 0x00
    D2UnitSfxNodeStrc* pNext; // 0x04
};

struct D2WeatherStrc
{
    int unused0x00[68]; // 0x00
    int nLastParticle; // 0x110
    int nCount; // 0x114
    int unused0x118; // 0x118
    union
    {
        D2WeatherSplashStrc* pRecords; // 0x11C
        D2WeatherParticleStrc* pParticles; // 0x11C
    };
};

struct D2SoundNodeStrc
{
    D2ClientSoundStrc* pSound; // 0x00
    D2SoundNodeStrc* pNext; // 0x04
};

struct D2StoredUnitRecordStrc
{
    char szName[16]; // 0x00
    int dwUnitId; // 0x10
    int dwPartyLife; // 0x14
    int dwKillCount; // 0x18
    int dwClassId; // 0x1C
    unsigned short wLevel; // 0x20
    unsigned short wPartyId; // 0x22
    int dwLevelId; // 0x24
    int dwPosX; // 0x28
    int dwPosY; // 0x2C
    int dwPartyFlags; // 0x30
    D2RosterInfoStrc** pRosterInfo; // 0x34
    D2RosterCorpseStrc* pCorpse; // 0x38
    int dwPortalA; // 0x3C
    int dwPortalB; // 0x40
    unsigned short wGuildFlags; // 0x44
    char szGuildTag[4]; // 0x46
    char szGuildName[28]; // 0x4A
    char szNameEx[26]; // 0x66
    D2StoredUnitRecordStrc* pNext; // 0x80
};

D2_CHECK_SIZE(D2RosterPetStrc, 0x34);
D2_CHECK_SIZE(D2RosterGroupStrc, 0xC);
D2_CHECK_SIZE(D2RosterCorpseStrc, 0x8);
D2_CHECK_SIZE(D2PlayerCmdStrc, 0x20);
D2_CHECK_SIZE(D2MonCommandStrc, 0x1C);
D2_CHECK_SIZE(D2UnitSfxNodeStrc, 0x8);
D2_CHECK_SIZE(D2WeatherStrc, 0x120);
D2_CHECK_SIZE(D2SoundNodeStrc, 0x8);
D2_CHECK_SIZE(D2StoredUnitRecordStrc, 0x84);
