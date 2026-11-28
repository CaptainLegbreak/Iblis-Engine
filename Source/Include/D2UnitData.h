#pragma once
// Per-type unit data: what D2UnitStrc's data pointer refers to for players and monsters, and a quest's state.

#include "D2Check.h"
#include "D2Path.h"

struct Unicode;
struct D2UnitStrc;
struct D2GameStrc;
struct D2ClientStrc;
struct D2BitBufferStrc;
struct D2WaypointDataStrc;
struct D2ArenaUnitStrc;
struct D2PlayerListStrc;
struct D2PlayerPetStrc;
struct D2PlayerTradeStrc;
struct D2PlrIntroStrc;
struct D2LifeSyncStrc;
struct D2AiControlStrc;
struct D2AiParamStrc;
struct D2MonsterInteractStrc;
struct D2QuestDataStrc;
struct D2QuestArgStrc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

struct D2PlayerDataStrc
{
    char szName[16]; // 0x00
    D2BitBufferStrc* pQuestData[3]; // 0x10
    D2WaypointDataStrc* pWaypointData[3]; // 0x1C
    unsigned char unused0x28[4]; // 0x28
    int nPortalFlags; // 0x2C
    unsigned char unused0x30[4]; // 0x30
    D2ArenaUnitStrc* pArenaUnit; // 0x34
    D2PlayerListStrc* pPlayerList; // 0x38
    unsigned char unused0x3C[4]; // 0x3C
    int nNecropetFlag; // 0x40
    D2PlayerPetStrc* pPlayerPets; // 0x44
    int dwUniqueId; // 0x48
    int bBusy; // 0x4C
    int dwTradeState; // 0x50
    unsigned char dwLastTradeTick[0x4]; // 0x54
    int dwAcceptTradeTick; // 0x58
    D2PlayerTradeStrc* hTrade; // 0x5C
    D2PlrIntroStrc* pPlayerIntro[3]; // 0x60
    int dwBoughtItemId; // 0x6C
    int nRightSkillId; // 0x70
    int nLeftSkillId; // 0x74
    int nRightSkillFlags; // 0x78
    int nLeftSkillFlags; // 0x7C
    int nSwitchRightSkillId; // 0x80
    int nSwitchLeftSkillId; // 0x84
    int nSwitchRightSkillFlags; // 0x88
    int nSwitchLeftSkillFlags; // 0x8C
    int nWeaponGUID; // 0x90
    int unused0x94; // 0x94
    D2LifeSyncStrc* pPartyLifeList; // 0x98
    D2ClientStrc* pClient; // 0x9C
    unsigned char nPositionHistoryIndex; // 0xA0
    unsigned char pad0xA1[3]; // 0xA1
    unsigned int dwPositionHistoryTick; // 0xA4
    D2CoordStrc pPositionHistory[20]; // 0xA8
    int nSkillCooldown148; // 0x148
    int nSkillCooldown14C; // 0x14C
    int nState; // 0x150
    int nMode; // 0x154
    int nArg1; // 0x158
    int nArg2; // 0x15C
    unsigned int dwHostileDelay; // 0x160
    unsigned char unused0x164[4]; // 0x164
    int dwGameFrame; // 0x168
};

struct D2MonsterDataStrc
{
    void* pMonstatsTxt; // 0x00
    unsigned char nComponent[16]; // 0x04
    unsigned short wNameSeed; // 0x14
    unsigned short nTypeFlag; // 0x16
    unsigned int dwDurielFlag; // 0x18
    unsigned char nMonUmod[10]; // 0x1C
    short wBossHcIdx; // 0x26
    union
    {
        D2AiControlStrc* pAiControl; // 0x28
        unsigned short nClientFlags; // 0x28 (client side)
        unsigned char nClientFlagsLow; // 0x28 (client side, low byte)
    };
    union
    {
        D2AiParamStrc* pAiParam; // 0x2C
        Unicode* wszMonName; // 0x2C (client side)
    };
    D2MonsterInteractStrc* pMonInteract; // 0x30
    int nAiValue; // 0x34
    int nAiState; // 0x38
    union
    {
        unsigned char abLifeSync[0x10]; // 0x3C (server side: the life sync record)
        struct
        {
            int nOwnerGUID; // 0x3C (client side)
            int nMinionSpawnClassId; // 0x40 (client side)
        };
    };
    unsigned char unused0x4C[4]; // 0x4C
    int pVision; // 0x50
    unsigned int dwAiState; // 0x54
    int nLevelId; // 0x58
};

struct D2QuestGUIDStrc
{
    unsigned int nPlayerGUIDs[32]; // 0x00
    unsigned short nPlayerCount; // 0x80
    unsigned char pad0x82[2]; // 0x82
};

struct D2QuestDataStrc
{
    int nQuestNo; // 0x00
    D2GameStrc* pGame; // 0x04
    unsigned char nActNo; // 0x08
    unsigned char bNotIntro; // 0x09
    unsigned char bActive; // 0x0A
    unsigned char fLastState; // 0x0B
    unsigned char fState; // 0x0C
    char nInitNo; // 0x0D
    unsigned short pad0x0E; // 0x0E
    int nSeqId; // 0x10
    union
    {
        unsigned int dwFlags; // 0x14
        struct
        {
            unsigned int nStatusFlags : 8; // 0x14
            unsigned int nFlagsHigh : 24; // 0x15
        };
    };
    void* pQuestDataEx; // 0x18
    D2QuestGUIDStrc tPlayerGUIDs; // 0x1C
    QUESTCALLBACK pCallback[15]; // 0xA0
    void* pNPCMessages; // 0xDC
    int eFilter; // 0xE0
    int eFilter2; // 0xE4
    QUESTSTATUSFILTER pfStatusFilter; // 0xE8
    QUESTACTIVEFILTER pfActiveFilter; // 0xEC
    QUESTSEQFILTER pfSeqFilter; // 0xF0
    D2QuestDataStrc* pPrev; // 0xF4
};

D2_CHECK_SIZE(D2PlayerDataStrc, 0x16C);
D2_CHECK_OFFSET(D2PlayerDataStrc, pPositionHistory, 0xA8);
D2_CHECK_OFFSET(D2PlayerDataStrc, dwGameFrame, 0x168);
D2_CHECK_SIZE(D2MonsterDataStrc, 0x5C);
D2_CHECK_OFFSET(D2MonsterDataStrc, pAiControl, 0x28);
D2_CHECK_SIZE(D2QuestGUIDStrc, 0x84);
D2_CHECK_SIZE(D2QuestDataStrc, 0xF8);
D2_CHECK_OFFSET(D2QuestDataStrc, pCallback, 0xA0);
D2_CHECK_OFFSET(D2QuestDataStrc, pfSeqFilter, 0xF0);
