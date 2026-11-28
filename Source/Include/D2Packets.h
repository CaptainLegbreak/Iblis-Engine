#pragma once
// Network packet records: the game server's messages to the client (D2GSPacketSrv*) and the client's commands to the server (D2GSPacketClt*).

#include "D2Check.h"

#pragma pack(push, 1)

struct D2GSPacketSrvB1
{
    unsigned char nHeader; // 0x00
    char szGameName[48]; // 0x01
    unsigned short nClientCount; // 0x31
    unsigned short nGameId; // 0x33
};

struct D2UnitUpdateEntry
{
    int nFirst; // 0x00
    int nSecond; // 0x04
    unsigned char nType; // 0x08
};

#pragma pack(pop)

struct D2GSPacketSrvB0
{
    unsigned char nHeader; // 0x00
};

struct D2GSPacketSrv06
{
    unsigned char nHeader; // 0x00
};

#pragma pack(push, 1)

struct D2PacketHeaderOnlyStrc
{
    unsigned char nHeader; // 0x00
};

struct D2PacketSize06Strc
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
};

struct D2PacketSize05Strc
{
    unsigned char nHeader; // 0x00
    int nValue; // 0x01
};

struct D2GSPacketSrv01
{
    unsigned char nHeader; // 0x00
    unsigned char nDifficulty; // 0x01
    unsigned int dwArenaFlags; // 0x02
    unsigned char nExpansion; // 0x06
    unsigned char nLadder; // 0x07
};

struct D2GSPacketSrv1A
{
    unsigned char nHeader; // 0x00
    unsigned char nExperience; // 0x01
};

struct D2GSPacketSrv1B
{
    unsigned char nHeader; // 0x00
    unsigned short nExperience; // 0x01
};

struct D2GSPacketSrv1C
{
    unsigned char nHeader; // 0x00
    unsigned int nExperience; // 0x01
};

struct D2GSPacketSrv1D
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned char nValue; // 0x02
};

struct D2GSPacketSrv1E
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned short nValue; // 0x02
};

struct D2GSPacketSrv1F
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned int nValue; // 0x02
};

struct D2GSPacketSrv69
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitGUID; // 0x01
    unsigned char nMessage; // 0x05
    unsigned short nX; // 0x06
    unsigned short nY; // 0x08
    unsigned char nUnitLife; // 0x0A
    unsigned char nHitClass; // 0x0B
};

struct D2GSPacketSrv6A
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitGUID; // 0x01
    unsigned char nMessage; // 0x05
    unsigned char nTargetUnitType; // 0x06
    unsigned int nTargetUnitGuid; // 0x07
    unsigned char nDirection; // 0x0B
};

struct D2GSPacketSrv6B
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitGUID; // 0x01
    unsigned char nMessage; // 0x05
    unsigned short nTargetX; // 0x06
    unsigned short nTargetY; // 0x08
    unsigned char nUnitLife; // 0x0A
    unsigned char nHitClass; // 0x0B
    unsigned short nX; // 0x0C
    unsigned short nY; // 0x0E
};

struct D2GSPacketSrv6C
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitGUID; // 0x01
    unsigned char nMessage; // 0x05
    unsigned char nTargetUnitType; // 0x06
    unsigned int nTargetUnitGUID; // 0x07
    unsigned char nUnitLife; // 0x0B
    unsigned short nX; // 0x0C
    unsigned short nY; // 0x0E
};

struct D2GSPacketSrv6D
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitGUID; // 0x01
    unsigned short nX; // 0x05
    unsigned short nY; // 0x07
    unsigned char nLife; // 0x09
};

struct D2GSPacketSrv67
{
    unsigned char nHeader; // 0x00
    int nUnitGUID; // 0x01
    unsigned char nMessage; // 0x05
    unsigned short nX; // 0x06
    unsigned short nY; // 0x08
    unsigned char nUnitLife; // 0x0A
    unsigned char nHitClass; // 0x0B
    unsigned char nPathType; // 0x0C
    short nVelocity; // 0x0D
    unsigned char nMaxDistance; // 0x0F
};

struct D2GSPacketSrv68
{
    unsigned char nHeader; // 0x00
    int nUnitGUID; // 0x01
    unsigned char nMessage; // 0x05
    unsigned short nX; // 0x06
    unsigned short nY; // 0x08
    unsigned char nTargetUnitType; // 0x0A
    int nTargetUnitGUID; // 0x0B
    unsigned char nUnitLife; // 0x0F
    unsigned char nHitClass; // 0x10
    unsigned char nPathType; // 0x11
    short nVelocity; // 0x12
    unsigned char nMaxDistance; // 0x14
};

struct D2GSPacketSrv9E
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned int dwGUID; // 0x02
    unsigned char nValue; // 0x06
};

struct D2GSPacketSrv9F
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned int dwGUID; // 0x02
    unsigned short nValue; // 0x06
};

struct D2GSPacketSrvA0
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned int dwGUID; // 0x02
    unsigned int nValue; // 0x06
};

struct D2GSPacketSrvA1
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned int dwGUID; // 0x02
    unsigned char nValue; // 0x06
};

struct D2GSPacketSrvA2
{
    unsigned char nHeader; // 0x00
    unsigned char nStat; // 0x01
    unsigned int dwGUID; // 0x02
    unsigned short nValue; // 0x06
};

struct D2GSPacketSrv03Strc
{
    unsigned char nHeader; // 0x00
    unsigned char nAct; // 0x01
    unsigned int dwGameSeed; // 0x02
    unsigned short nTownLevelId; // 0x06
    unsigned int nObjectSeed; // 0x08
};

struct D2GSPacketSrv0C
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
    unsigned char nMessage; // 0x06
    unsigned char nHitClass; // 0x07
    unsigned char nLife; // 0x08
};

struct D2GSPacketSrv0D
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
    unsigned char nHitClass; // 0x06
    unsigned short nX; // 0x07
    unsigned short nY; // 0x09
    unsigned char nHitType; // 0x0B
    unsigned char nUnitLifePct; // 0x0C
};

struct D2GSPacketSrv15
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
    unsigned short nPosX; // 0x06
    unsigned short nPosY; // 0x08
    unsigned char bReassign; // 0x0A
};

struct D2GSPacketSrv07
{
    unsigned char nHeader; // 0x00
    unsigned short nX; // 0x01
    unsigned short nY; // 0x03
    unsigned char nLevelId; // 0x05
};

struct D2GSPacketSrv21
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned char bRemove; // 0x02
    unsigned int nUnitGUID; // 0x03
    unsigned short nSkillId; // 0x07
    unsigned char nSkillLevel; // 0x09
    unsigned char nBonusSkillLevel; // 0x0A
    unsigned char unused0x0B; // 0x0B
};

struct D2GSPacketSrv23
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
    unsigned char nPosition; // 0x06
    unsigned short nSkill; // 0x07
    unsigned int nOwnerGUID; // 0x09
};

struct D2GSPacketSrv3F
{
    unsigned char nHeader; // 0x00
    unsigned char nCursor; // 0x01
    unsigned int dwItemId; // 0x02
    unsigned short nSkill; // 0x06
};

struct D2GSPacketSrv57
{
    unsigned char nHeader; // 0x00
    unsigned int dwUnitGUID; // 0x01
    unsigned char nUnitType; // 0x05
    unsigned short nNameSeed; // 0x06
    unsigned short nUMods01; // 0x08
    unsigned short nUMods23; // 0x0A
    unsigned short bChampion; // 0x0C
};

struct D2GSPacketSrv99
{
    unsigned char nHeader; // 0x00
    unsigned char nSourceUnitType; // 0x01
    unsigned int nSourceUnitGUID; // 0x02
    unsigned short nSkillId; // 0x06
    unsigned char nSkillLevel; // 0x08
    unsigned char nUnitType; // 0x09
    int nUnitGUID; // 0x0A
    unsigned short nItemEffect; // 0x0E
};

struct D2GSPacketSrv9A
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int nUnitGUID; // 0x02
    unsigned int nSkillId; // 0x06
    unsigned char nSkillLevel; // 0x0A
    unsigned short nX; // 0x0B
    unsigned short nY; // 0x0D
    unsigned short nItemEffect; // 0x0F
};

struct D2GSPacketSrv0EStrc
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    unsigned char nEvent; // 0x06
    unsigned char bTargetable; // 0x07
    int nAnimMode; // 0x08
};

struct D2GSPacketSrv10Strc
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    unsigned char nFlags; // 0x06
    unsigned char nTargetType; // 0x07
    int nTargetGUID; // 0x08
    unsigned short nCurrentPosX; // 0x0C
    unsigned short nCurrentPosY; // 0x0E
};

struct D2GSPacketSrv0FStrc
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    unsigned char nFlags; // 0x06
    unsigned short nDestPosX; // 0x07
    unsigned short nDestPosY; // 0x09
    unsigned char nHitClass; // 0x0B
    unsigned short nCurrentPosX; // 0x0C
    unsigned short nCurrentPosY; // 0x0E
};

#pragma pack(pop)

struct FieldStrc_005A6220
{
    int unk0x00[4]; // 0x00
    int unk0x10; // 0x10
};

#pragma pack(push, 1)

struct D2GSPacketSrv08
{
    unsigned char nHeader; // 0x00
    unsigned short nX; // 0x01
    unsigned short nY; // 0x03
    unsigned char nLevelId; // 0x05
};

struct D2GSPacketSrv09
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
    unsigned char nClassId; // 0x06
    unsigned short nPosX; // 0x07
    unsigned short nPosY; // 0x09
};

struct D2GSPacketSrv51
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
    unsigned short nObject; // 0x06
    unsigned short nPosX; // 0x08
    unsigned short nPosY; // 0x0A
    unsigned char nObjectParam; // 0x0C
    unsigned char nInteractType; // 0x0D
};

struct PacketA1
{
    unsigned char header,stat;
    int guid;
    unsigned char value;
};

struct PacketA2
{
    unsigned char header,stat;
    int guid;
    unsigned short value;
};

struct PacketA0
{
    unsigned char header,stat;
    int guid;
    unsigned int value;
};

struct D2GSPacketSrvA3
{
    unsigned char nHeader; // 0x00
    unsigned char nSeed; // 0x01
    unsigned short nSkillId; // 0x02
    unsigned short nSkillLevel; // 0x04
    unsigned char nUnitType; // 0x06
    unsigned int nUnitGUID; // 0x07
    unsigned char nTargetType; // 0x0B
    unsigned int nTargetGUID; // 0x0C
    unsigned int nX; // 0x10
    unsigned int nY; // 0x14
};

struct D2GSPacketSrvAB
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
    unsigned char nLife; // 0x06
};

struct D2GSPacketSrvA5
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    unsigned short nSkillId; // 0x06
};

struct D2GSPacketSrv22
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned char unused0x02; // 0x02
    int nUnitGUID; // 0x03
    unsigned short nSkillId; // 0x07
    unsigned char nQuantity; // 0x09
    unsigned char unused0x0A; // 0x0A
    unsigned char bIsCorpse; // 0x0B
};

struct D2GSPacketSrv5C
{
    unsigned char nHeader; // 0x00
    unsigned int dwPlayerGUID; // 0x01
};

struct D2GSPacketSrv77
{
    unsigned char nHeader; // 0x00
    unsigned char nAction; // 0x01
};

struct D2GSPacketSrv78
{
    unsigned char nHeader; // 0x00
    char szName[16]; // 0x01
    unsigned int dwPlayerGUID; // 0x11
};

struct D2GSPacketSrv7A
{
    unsigned char nHeader; // 0x00
    unsigned char bAdd; // 0x01
    unsigned char nPetType; // 0x02
    unsigned short nPetClass; // 0x03
    unsigned int nUnitGUID; // 0x05
    unsigned int nPetGUID; // 0x09
};

struct D2GSPacketSrv81
{
    unsigned char nHeader; // 0x00
    unsigned char nPetType; // 0x01
    unsigned short nPetClass; // 0x02
    unsigned int nUnitGUID; // 0x04
    unsigned int nPetGUID; // 0x08
    unsigned int nSeed; // 0x0C
    unsigned int nName; // 0x10
};

struct D2GSPacketSrv53
{
    unsigned char nHeader; // 0x00
    int nCycleIndex; // 0x01
    int nTicks; // 0x05
    unsigned char nEclipse; // 0x09
};

struct D2GSPacketSrv5A
{
    unsigned char nHeader; // 0x00
    unsigned char nType; // 0x01
    unsigned char nColor; // 0x02
    unsigned int dwParam; // 0x03
    unsigned char nParam; // 0x07
    char szText[32]; // 0x08
};

#pragma pack(pop)

struct D2GSPacketSrv26
{
    unsigned char nHeader; // 0x00
    unsigned char nMessageType; // 0x01
    unsigned char nLang; // 0x02
    unsigned char nUnitType; // 0x03
    unsigned int dwUnitGUID; // 0x04
    unsigned char nMessageColor; // 0x08
    unsigned char nNameColor; // 0x09
    char szName[16]; // 0x0A
    char szMessage[256]; // 0x1A
};

#pragma pack(push, 1)

struct D2GSPacketSrv20Strc
{
    unsigned char nHeader; // 0x00
    int dwUnitGUID; // 0x01
    unsigned char nStat; // 0x05
    int nValue; // 0x06
};

struct D2GSPacketSrv23Strc
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    unsigned char nPosition; // 0x06
    unsigned short nSkill; // 0x07
    int nOwnerGUID; // 0x09
};

struct D2GSPacketSrv93Strc
{
    unsigned char nHeader; // 0x00
    int dwUnitGUID; // 0x01
    unsigned char nBonus; // 0x05
    unsigned char nCharClass; // 0x06
    unsigned char nSkillTab; // 0x07
};

struct D2GSPacketSrv79
{
    unsigned char nHeader; // 0x00
    unsigned char bOwnGold; // 0x01
    unsigned int dwGold; // 0x02
};

struct D2GSPacketSrv7F
{
    unsigned char nHeader; // 0x00
    unsigned char bIsPlayer; // 0x01
    unsigned short nLifePercentage; // 0x02
    int nUnitGUID; // 0x04
    unsigned short nLevelId; // 0x08
};

struct D2GSPacketSrv90
{
    unsigned char nHeader; // 0x00
    int dwGUID; // 0x01
    int dwPosX; // 0x05
    int dwPosY; // 0x09
};

#pragma pack(pop)

struct D2GSPacketSrv3E
{
    unsigned char nHeader; // 0x00
    unsigned char nSize; // 0x01
    unsigned char pBuffer[32]; // 0x02
};

#pragma pack(push, 1)

struct D2GSPacketSrv42
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned int dwUnitGUID; // 0x02
};

struct D2GSPacketSrv47
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned char unused0x02; // 0x02
    unsigned int nUnitGUID; // 0x03
    unsigned int unused0x07; // 0x07
};

struct D2GSPacketSrv48
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    unsigned char unused0x02; // 0x02
    unsigned int nUnitGUID; // 0x03
    unsigned int unused0x07; // 0x07
};

struct D2GSPacketSrv7D
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID1; // 0x02
    int nUnitGUID2; // 0x06
    int nItemFlag; // 0x0A
    int bSet; // 0x0E
};

struct D2GSPacketSrv28
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    unsigned char nTerminateType; // 0x06
    unsigned char pData[96]; // 0x07
};

struct D2GSPacketSrv29
{
    unsigned char nHeader; // 0x00
    unsigned char pData[96]; // 0x01
};

struct D2GSPacketSrv5D
{
    unsigned char nHeader; // 0x00
    unsigned char nQuestId; // 0x01
    unsigned char nFlags; // 0x02
    unsigned char nState; // 0x03
    unsigned short field_4; // 0x04
};

struct D2GSPacketSrv2C
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int dwUnitGUID; // 0x02
    unsigned short nSoundEvent; // 0x06
};

struct D2GSPacketSrv4E
{
    unsigned char nHeader; // 0x00
    unsigned short nMercName; // 0x01
    int nSeed; // 0x03
};

// Quest progress values. A quest's own update fills nParams[0] (cairn stone order: [0..4]); the quest log refresh
// (sent as QUEST_A1Q1_DENOFEVIL) sends [0] monsters left in the Den of Evil, [1] the true tomb's level offset, [2] barbarians left to rescue.
struct D2GSPacketSrv50
{
    unsigned char nHeader; // 0x00
    unsigned short nQuestId; // 0x01
    unsigned short nParams[6]; // 0x03
};

struct D2GSPacketSrv5E
{
    unsigned char nHeader; // 0x00
    unsigned char nQuestIntroFlags[37]; // 0x01
};

struct D2GSPacketSrv52
{
    unsigned char nHeader; // 0x00
    unsigned char pQuestList[41]; // 0x01
};

struct D2GSPacketSrv11
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int dwUnitGUID; // 0x02
    unsigned short wOverlay; // 0x06
};

struct D2GSPacketSrv58
{
    unsigned char nHeader; // 0x00
    int nUnitId; // 0x01
    unsigned char nAction; // 0x05
    unsigned char nResult; // 0x06
};

struct D2GSPacketSrv60
{
    unsigned char nHeader; // 0x00
    unsigned char nFlags; // 0x01
    unsigned char nLevel; // 0x02
    int dwUnitGUID; // 0x03
};

struct D2GSPacketSrv61
{
    unsigned char nHeader; // 0x00
    unsigned char nCinematic; // 0x01
};

struct D2GSPacketSrv73
{
    unsigned char nHeader; // 0x00
    int unused0x01; // 0x01
    unsigned short nMissileId; // 0x05
    int nX; // 0x07
    int nY; // 0x0B
    int nFirstX; // 0x0F
    int nFirstY; // 0x13
    unsigned short nCurrentFrame; // 0x17
    unsigned char nUnitType; // 0x19
    int nUnitGUID; // 0x1A
    unsigned char nLevel; // 0x1E
    unsigned char nPierce; // 0x1F
};

struct D2GSPacketSrv75
{
    unsigned char nHeader; // 0x00
    int nUnitGUID; // 0x01
    unsigned short nPartyId; // 0x05
    unsigned short nLevel; // 0x07
    unsigned short nFlags; // 0x09
    unsigned short nPartyFlags; // 0x0B
};

struct D2GSPacketSrv7B
{
    unsigned char nHeader; // 0x00
    unsigned char nSlot; // 0x01
    unsigned short nSkill; // 0x02
    int nItemGUID; // 0x04
};

struct D2GSPacketSrv7E
{
    unsigned char nHeader; // 0x00
    unsigned int unused0x01; // 0x01
};

struct D2GSPacketSrv82
{
    unsigned char nHeader; // 0x00
    int dwOwnerGUID; // 0x01
    char szOwnerName[16]; // 0x05
    int dwPortalGUID0; // 0x15
    int dwPortalGUID1; // 0x19
};

struct D2GSPacketSrv8E
{
    unsigned char nHeader; // 0x00
    unsigned char nType; // 0x01
    int dwPlayerGUID; // 0x02
    int dwCorpseGUID; // 0x06
};

struct D2GSPacketSrv89
{
    unsigned char nHeader; // 0x00
    unsigned char nEvent; // 0x01
};

struct D2GSPacketSrv8A
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int dwUnitGUID; // 0x02
};

struct D2PacketInteractStrc
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    unsigned char unused0x06; // 0x06
};

struct D2PacketSrv2AStrc
{
    unsigned char nHeader; // 0x00
    unsigned char nTransactionType; // 0x01
    unsigned char nResult; // 0x02
    unsigned int unused0x03; // 0x03
    int nUnitGUID; // 0x07
    int nGold; // 0x0B
};

struct D2GSPacketSrv65Strc
{
    unsigned char nHeader; // 0x00
    unsigned int dwUnitId; // 0x01
    unsigned short nKillCount; // 0x05
};

struct D2GSPacketSrv74
{
    unsigned char nHeader; // 0x00
    unsigned char bAssign; // 0x01
    int nPlayerGUID; // 0x02
    int nCorpseGUID; // 0x06
};

struct D2GSPacketSrv8BStrc
{
    unsigned char nHeader; // 0x00
    int nUnitGUID; // 0x01
    unsigned char bParty; // 0x05
};

struct D2GSPacketSrv8F
{
    unsigned char nHeader; // 0x00
    unsigned int pPongData[8]; // 0x01
};

struct D2GSPacketSrv98
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitGUID; // 0x01
    unsigned short nMinionSpawnClassId; // 0x05
};

struct D2GSPacketSrv9B
{
    unsigned char nHeader; // 0x00
    unsigned short nMercNameStringId; // 0x01
    int nReviveCost; // 0x03
};

struct D2GSPacketSrv97
{
    unsigned char nHeader; // 0x00
};

struct D2GSPacketSrvA4
{
    unsigned char nHeader; // 0x00
    short nMonStatsId; // 0x01
};

struct D2GSPacketSrvA7
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitId; // 0x02
    unsigned char nState; // 0x06
};

struct D2GSPacketSrvA9
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitId; // 0x02
    unsigned char nState; // 0x06
};

struct D2GSPacketSrv59
{
    unsigned char nHeader; // 0x00
    unsigned int dwGUID; // 0x01
    unsigned char nClass; // 0x05
    char szName[16]; // 0x06
    unsigned short nPosX; // 0x16
    unsigned short nPosY; // 0x18
};

struct D2GSPacketSrv19
{
    unsigned char nHeader; // 0x00
    unsigned char nGold; // 0x01
};

struct D2GSPacketSrv9C
{
    unsigned char nHeader; // 0x00
    unsigned char nAction; // 0x01
    unsigned char nPacketSize; // 0x02
    unsigned char nComponent; // 0x03
    int nItemId; // 0x04
    unsigned char pBitstream[244]; // 0x08
};

struct D2GSPacketSrv16
{
    unsigned char nHeader;
    unsigned short nSize;
    unsigned char nCount;
    D2UnitUpdateEntry entries[1];
};

#pragma pack(pop)

struct D2GSPacketSrvA6
{
    unsigned char nHeader; // 0x00
    unsigned char nType; // 0x01
    unsigned short nPacketSize; // 0x02
    unsigned short wArg; // 0x04
    unsigned char data[0x1000]; // 0x06
};

#pragma pack(push, 1)

struct D2GSPacketSrvAE
{
    unsigned char nHeader; // 0x00
    unsigned short nSize; // 0x01
    unsigned char data[0x1FD]; // 0x03
};

struct D2PacketTarget3FStrc
{
    unsigned char nHeader; // 0x00
    unsigned char nType; // 0x01
    int nUnitGUID; // 0x02
    unsigned short nValue; // 0x06
};

struct D2SkillPacketEntryStrc
{
    unsigned short nSkill; // 0x00
    unsigned char nLevel; // 0x02
};

struct D2GSPacketSrv94
{
    unsigned char nHeader; // 0x00
    unsigned char nCount; // 0x01
    int nGUID; // 0x02
};

struct D2GSPacketSrv5B
{
    unsigned char nHeader; // 0x00
    unsigned short nPacketLen; // 0x01
    unsigned int nUnitGUID; // 0x03
    unsigned char nClass; // 0x07
    char szName[16]; // 0x08
    unsigned short nLevel; // 0x18
    unsigned short nPartyId; // 0x1A
    unsigned short unused0x1C; // 0x1C
    unsigned short nPartyFlags; // 0x1E
    unsigned short nGuildFlags; // 0x20
    char szGuildTag[0x100]; // 0x22
};

union D2GSPacketSrv7F90
{
    D2GSPacketSrv7F packet7F;
    D2GSPacketSrv90 packet90;
};

struct D2GSPacketSrv9D
{
    unsigned char nHeader; // 0x00
    unsigned char nAction; // 0x01
    unsigned char nPacketSize; // 0x02
    unsigned char nComponent; // 0x03
    int nItemId; // 0x04
    unsigned char nUnitType; // 0x08
    int nUnitId; // 0x09
    unsigned char pBitstream[244]; // 0x0D
};

struct Packet40
{
    unsigned char header; // 0x00
    int guid; // 0x01
    int x; // 0x05
    int y; // 0x09
};

struct D2GSPacketSrv4D
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitGUID; // 0x02
    int nSkillId; // 0x06
    unsigned char nSkillLevel; // 0x0A
    unsigned short nX; // 0x0B
    unsigned short nY; // 0x0D
    unsigned short nItemEffect; // 0x0F
};

struct D2GSPacketSrv8C
{
    unsigned char nHeader; // 0x00
    int dwPlayerGUID1; // 0x01
    int dwPlayerGUID2; // 0x05
    unsigned short nFlags; // 0x09
};

struct D2GSPacketSrv8D
{
    unsigned char nHeader; // 0x00
    int dwPlayerGUID; // 0x01
    unsigned short nPartyGUID; // 0x05
};

struct D2GSPacketSrvAC
{
    unsigned char nHeader; // 0x00
    int dwUnitGUID; // 0x01
    unsigned short nUnitIndex; // 0x05
    unsigned short nPosX; // 0x07
    unsigned short nPosY; // 0x09
    unsigned char nLifePct; // 0x0B
    unsigned char nPacketLength; // 0x0C
    unsigned char bitstream[0xF4]; // 0x0D
};

struct D2GSPacketSrv4C
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int dwUnitGUID; // 0x02
    unsigned short wSkill; // 0x06
    unsigned char nSkillLevel; // 0x08
    unsigned char nTargetType; // 0x09
    int dwTargetGUID; // 0x0A
    unsigned short nItemEffect; // 0x0E
};

struct D2GSPacketSrv83
{
    unsigned char nHeader; // 0x00
    char szName[4]; // 0x01
    unsigned short f_5; // 0x05
    unsigned short wSize; // 0x07
    unsigned short f_9; // 0x09
    unsigned char pData[0x190]; // 0x0B
};

struct D2GSPacketSrv84
{
    unsigned char nHeader; // 0x00
    unsigned char nArg; // 0x01
    unsigned char pData[0x190]; // 0x02
};

struct D2GSPacketClt66
{
    unsigned char nHeader; // 0x00
    char szGameName[16]; // 0x01
    unsigned char nGameType; // 0x11
    unsigned char nPlayerClass; // 0x12
    unsigned char nTemplate; // 0x13
    unsigned char nDifficulty; // 0x14
    char szClientName[16]; // 0x15
    unsigned short wArena; // 0x25
    unsigned int nGameFlags; // 0x27
    unsigned char unused0x2B; // 0x2B
    unsigned char unused0x2C; // 0x2C
    unsigned char nLocale; // 0x2D
};

struct D2GSPacketClt67
{
    unsigned char nHeader; // 0x00
    int nTokenId; // 0x01
    unsigned short nGameId; // 0x05
    unsigned char nPlayerClass; // 0x07
    int dwVersion; // 0x08
    unsigned int dwProductConstant; // 0x0C
    unsigned int dwJoinConstant; // 0x10
    unsigned char nLocale; // 0x14
    char szClientName[16]; // 0x15
};

struct D2GSPacketClt6D
{
    unsigned char nHeader; // 0x00
    int nTick; // 0x01
    int nDelay; // 0x05
};

struct D2GSPacketClt6B
{
    unsigned char nHeader; // 0x00
    unsigned char nSize; // 0x01
    unsigned int dwTotalSize; // 0x02
    unsigned char saveData[8192]; // 0x06
};

struct D2GSPacketClt3B
{
    unsigned char nHeader; // 0x00
    unsigned short nSkill; // 0x01
};

struct D2GSPacketClt20
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
    int nPosX; // 0x05
    int nPosY; // 0x09
};

struct D2GSPacketClt5F
{
    unsigned char nHeader; // 0x00
    unsigned short nX; // 0x01
    unsigned short nY; // 0x03
};

struct D2GSPacketClt1F
{
    unsigned char nHeader; // 0x00
    int nCursorItemGUID; // 0x01
    int nInventoryItemGUID; // 0x05
    int nPosX; // 0x09
    int nPosY; // 0x0D
};

#pragma pack(pop)

struct D2GSPacketSrv63
{
    unsigned char nHeader; // 0x00
    unsigned char dwUnitId[4]; // 0x01
    unsigned char pData[16]; // 0x05
};

#pragma pack(push, 1)

struct D2GSPacketSrvA8
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitId; // 0x02
    unsigned char nSize; // 0x06
    unsigned char nState; // 0x07
    unsigned char pData[244]; // 0x08
};

struct D2GSPacketSrvAA
{
    unsigned char nHeader; // 0x00
    unsigned char nUnitType; // 0x01
    int nUnitId; // 0x02
    unsigned char nSize; // 0x06
    unsigned char pStream[244]; // 0x07
};

#pragma pack(pop)

D2_CHECK_SIZE(D2GSPacketSrvB1, 0x35);
D2_CHECK_SIZE(D2UnitUpdateEntry, 0x9);
D2_CHECK_SIZE(D2GSPacketSrvB0, 0x1);
D2_CHECK_SIZE(D2GSPacketSrv06, 0x1);
D2_CHECK_SIZE(D2PacketHeaderOnlyStrc, 0x1);
D2_CHECK_SIZE(D2PacketSize06Strc, 0x6);
D2_CHECK_SIZE(D2PacketSize05Strc, 0x5);
D2_CHECK_SIZE(D2GSPacketSrv01, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv1A, 0x2);
D2_CHECK_SIZE(D2GSPacketSrv1B, 0x3);
D2_CHECK_SIZE(D2GSPacketSrv1C, 0x5);
D2_CHECK_SIZE(D2GSPacketSrv1D, 0x3);
D2_CHECK_SIZE(D2GSPacketSrv1E, 0x4);
D2_CHECK_SIZE(D2GSPacketSrv1F, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv69, 0xC);
D2_CHECK_SIZE(D2GSPacketSrv6A, 0xC);
D2_CHECK_SIZE(D2GSPacketSrv6B, 0x10);
D2_CHECK_SIZE(D2GSPacketSrv6C, 0x10);
D2_CHECK_SIZE(D2GSPacketSrv6D, 0xA);
D2_CHECK_SIZE(D2GSPacketSrv67, 0x10);
D2_CHECK_SIZE(D2GSPacketSrv68, 0x15);
D2_CHECK_SIZE(D2GSPacketSrv9E, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv9F, 0x8);
D2_CHECK_SIZE(D2GSPacketSrvA0, 0xA);
D2_CHECK_SIZE(D2GSPacketSrvA1, 0x7);
D2_CHECK_SIZE(D2GSPacketSrvA2, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv03Strc, 0xC);
D2_CHECK_SIZE(D2GSPacketSrv0C, 0x9);
D2_CHECK_SIZE(D2GSPacketSrv0D, 0xD);
D2_CHECK_SIZE(D2GSPacketSrv15, 0xB);
D2_CHECK_SIZE(D2GSPacketSrv07, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv21, 0xC);
D2_CHECK_SIZE(D2GSPacketSrv23, 0xD);
D2_CHECK_SIZE(D2GSPacketSrv3F, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv57, 0xE);
D2_CHECK_SIZE(D2GSPacketSrv99, 0x10);
D2_CHECK_SIZE(D2GSPacketSrv9A, 0x11);
D2_CHECK_SIZE(D2GSPacketSrv0EStrc, 0xC);
D2_CHECK_SIZE(D2GSPacketSrv10Strc, 0x10);
D2_CHECK_SIZE(D2GSPacketSrv0FStrc, 0x10);
D2_CHECK_SIZE(FieldStrc_005A6220, 0x14);
D2_CHECK_SIZE(D2GSPacketSrv08, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv09, 0xB);
D2_CHECK_SIZE(D2GSPacketSrv51, 0xE);
D2_CHECK_SIZE(D2GSPacketSrvA3, 0x18);
D2_CHECK_SIZE(D2GSPacketSrvAB, 0x7);
D2_CHECK_SIZE(D2GSPacketSrvA5, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv22, 0xC);
D2_CHECK_SIZE(D2GSPacketSrv5C, 0x5);
D2_CHECK_SIZE(D2GSPacketSrv77, 0x2);
D2_CHECK_SIZE(D2GSPacketSrv78, 0x15);
D2_CHECK_SIZE(D2GSPacketSrv7A, 0xD);
D2_CHECK_SIZE(D2GSPacketSrv81, 0x14);
D2_CHECK_SIZE(D2GSPacketSrv53, 0xA);
D2_CHECK_SIZE(D2GSPacketSrv5A, 0x28);
D2_CHECK_SIZE(D2GSPacketSrv26, 0x11C);
D2_CHECK_SIZE(D2GSPacketSrv20Strc, 0xA);
D2_CHECK_SIZE(D2GSPacketSrv23Strc, 0xD);
D2_CHECK_SIZE(D2GSPacketSrv93Strc, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv79, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv7F, 0xA);
D2_CHECK_SIZE(D2GSPacketSrv90, 0xD);
D2_CHECK_SIZE(D2GSPacketSrv3E, 0x22);
D2_CHECK_SIZE(D2GSPacketSrv42, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv47, 0xB);
D2_CHECK_SIZE(D2GSPacketSrv48, 0xB);
D2_CHECK_SIZE(D2GSPacketSrv7D, 0x12);
D2_CHECK_SIZE(D2GSPacketSrv28, 0x67);
D2_CHECK_SIZE(D2GSPacketSrv29, 0x61);
D2_CHECK_SIZE(D2GSPacketSrv5D, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv2C, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv4E, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv50, 0xF);
D2_CHECK_SIZE(D2GSPacketSrv5E, 0x26);
D2_CHECK_SIZE(D2GSPacketSrv52, 0x2A);
D2_CHECK_SIZE(D2GSPacketSrv11, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv58, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv60, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv61, 0x2);
D2_CHECK_SIZE(D2GSPacketSrv73, 0x20);
D2_CHECK_SIZE(D2GSPacketSrv75, 0xD);
D2_CHECK_SIZE(D2GSPacketSrv7B, 0x8);
D2_CHECK_SIZE(D2GSPacketSrv7E, 0x5);
D2_CHECK_SIZE(D2GSPacketSrv82, 0x1D);
D2_CHECK_SIZE(D2GSPacketSrv8E, 0xA);
D2_CHECK_SIZE(D2GSPacketSrv89, 0x2);
D2_CHECK_SIZE(D2GSPacketSrv8A, 0x6);
D2_CHECK_SIZE(D2PacketInteractStrc, 0x7);
D2_CHECK_SIZE(D2PacketSrv2AStrc, 0xF);
D2_CHECK_SIZE(D2GSPacketSrv65Strc, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv74, 0xA);
D2_CHECK_SIZE(D2GSPacketSrv8BStrc, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv8F, 0x21);
D2_CHECK_SIZE(D2GSPacketSrv98, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv9B, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv97, 0x1);
D2_CHECK_SIZE(D2GSPacketSrvA4, 0x3);
D2_CHECK_SIZE(D2GSPacketSrvA7, 0x7);
D2_CHECK_SIZE(D2GSPacketSrvA9, 0x7);
D2_CHECK_SIZE(D2GSPacketSrv59, 0x1A);
D2_CHECK_SIZE(D2GSPacketSrv19, 0x2);
D2_CHECK_SIZE(D2GSPacketSrv9C, 0xFC);
D2_CHECK_SIZE(D2GSPacketSrvA6, 0x1006);
D2_CHECK_SIZE(D2GSPacketSrvAE, 0x200);
D2_CHECK_SIZE(D2PacketTarget3FStrc, 0x8);
D2_CHECK_SIZE(D2SkillPacketEntryStrc, 0x3);
D2_CHECK_SIZE(D2GSPacketSrv94, 0x6);
D2_CHECK_SIZE(D2GSPacketSrv5B, 0x122);
D2_CHECK_SIZE(D2GSPacketSrv9D, 0x101);
D2_CHECK_SIZE(Packet40, 0xD);
D2_CHECK_SIZE(D2GSPacketSrv4D, 0x11);
D2_CHECK_SIZE(D2GSPacketSrv8C, 0xB);
D2_CHECK_SIZE(D2GSPacketSrv8D, 0x7);
D2_CHECK_SIZE(D2GSPacketSrvAC, 0x101);
D2_CHECK_SIZE(D2GSPacketSrv4C, 0x10);
D2_CHECK_SIZE(D2GSPacketSrv83, 0x19B);
D2_CHECK_SIZE(D2GSPacketSrv84, 0x192);
D2_CHECK_SIZE(D2GSPacketClt66, 0x2E);
D2_CHECK_SIZE(D2GSPacketClt67, 0x25);
D2_CHECK_SIZE(D2GSPacketClt6D, 0x9);
D2_CHECK_SIZE(D2GSPacketClt6B, 0x2006);
D2_CHECK_SIZE(D2GSPacketClt3B, 0x3);
D2_CHECK_SIZE(D2GSPacketClt20, 0xD);
D2_CHECK_SIZE(D2GSPacketClt5F, 0x5);
D2_CHECK_SIZE(D2GSPacketClt1F, 0x11);
D2_CHECK_SIZE(D2GSPacketSrv63, 0x15);
D2_CHECK_SIZE(D2GSPacketSrvA8, 0xFC);
D2_CHECK_SIZE(D2GSPacketSrvAA, 0xFB);

struct D2GameLogonPacketStrc
{
    unsigned char nHeader;
    unsigned char nServerHash[4];
    unsigned char nServerToken[2];
    unsigned char nClass;
    unsigned char nVersion[4];
    unsigned char nKey1[4];
    unsigned char nKey2[4];
    unsigned char nLanguage;
    char szName[16];
};
