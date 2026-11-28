// A game in progress on the server: its clients, acts, units, seeds and controllers.
#pragma once
struct D2PoolSystemStrc;

#include "D2Structs.h"

struct D2ArenaStrc;
struct D2ClientInfoStrc;
struct D2ClientStrc;
struct D2CriticalSectionStrc;
struct D2DrlgActStrc;
struct D2EventTimerQueueStrc;
struct D2InactiveUnitListStrc;
struct D2MonsterRegionStrc;
struct D2NpcControlStrc;
struct D2ObjectControlStrc;
struct D2PartyControlStrc;
struct D2QuestInfoStrc;
struct D2TargetNodeStrc;
struct D2GameStrc;

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink; // 0x00
    D2GameStrc* pNext; // 0x04
};

struct D2GameStrc
{
    unsigned int dwHashValue; // 0x00
    D2GameLinkStrc tLinkToSlot; // 0x04
    D2GameLinkStrc tLinkToFull; // 0x0C
    unsigned char unk0x14[0x4]; // 0x14
    D2CriticalSectionStrc* lpCriticalSection; // 0x18
    D2PoolSystemStrc* pMemoryPool; // 0x1C
    D2ClientInfoStrc* pClientInfo; // 0x20
    int unk0x24; // 0x24
    unsigned short nGameId; // 0x28
    char szGameName[16]; // 0x2A
    char szGamePassword[16]; // 0x3A
    char szGameDesc[32]; // 0x4A
    unsigned char nGameType; // 0x6A
    unsigned char nArenaTemplate; // 0x6B
    unsigned char nMaxLevelDifference; // 0x6C
    unsigned char nDifficulty; // 0x6D
    unsigned char nMaxPlayers; // 0x6E
    unsigned char unk0x6F[0x1]; // 0x6F
    int bExpansion; // 0x70
    int dwGameType; // 0x74
    unsigned short wItemFormat; // 0x78
    unsigned char unk0x7A[0x2]; // 0x7A
    unsigned int dwInitSeed; // 0x7C
    int dwObjSeed; // 0x80
    int InitSeed; // 0x84
    D2ClientStrc* pClientList; // 0x88
    int nClients; // 0x8C
    int dwLastUsedUnitGUID[6]; // 0x90
    int dwGameFrame; // 0xA8
    unsigned int nFrameRate; // 0xAC
    unsigned int nFramesSinceLastFrameRateUpdate; // 0xB0
    unsigned int nPreviousUpdateTickCount; // 0xB4
    D2EventTimerQueueStrc* pTimerQueue; // 0xB8
    D2DrlgActStrc* pAct[5]; // 0xBC
    D2SeedStrc pGameSeed; // 0xD0
    D2InactiveUnitListStrc* pInactiveUnitList[5]; // 0xD8
    unsigned int dwMonSeed; // 0xEC
    D2MonsterRegionStrc* pMonReg[1024]; // 0xF0
    D2ObjectControlStrc* pObjectControl; // 0x10F0
    D2QuestInfoStrc* pQuestControl; // 0x10F4
    D2TargetNodeStrc* pTargetNodes[10]; // 0x10F8
    D2UnitStrc* pUnitList[5][128]; // 0x1120
    D2UnitStrc* pTileList; // 0x1B20
    unsigned int dwUniqueFlags[128]; // 0x1B24
    D2NpcControlStrc* pNpcControl; // 0x1D24
    D2ArenaStrc* pArenaCtrl; // 0x1D28
    D2PartyControlStrc* hParty; // 0x1D2C
    unsigned char nBossFlagList[64]; // 0x1D30
    int dwPathTypesCount[17]; // 0x1D70
    int nTotalPathTypesCount; // 0x1DB4
    unsigned int nLastUpdateSystemTimeMs; // 0x1DB8
    unsigned int nCreationTimeMs_Or_CPUTargetRatioFP10; // 0x1DBC
    int nTickCountSinceNoClients; // 0x1DC0
    unsigned int nSyncTimer; // 0x1DC4
    int nDebugBreakTrigger; // 0x1DC8
    unsigned char unk0x1DCC[0x8]; // 0x1DCC
    union // 0x1DD4
    {
        int nUberFields[8];
        struct
        {
            int unk0x1DD4[4]; // 0x1DD4
            unsigned int dwUberSandsCounter; // 0x1DE4
            int bUberBaalKilled; // 0x1DE8
            int bUberDiabloKilled; // 0x1DEC
            int bUberMephistoKilled; // 0x1DF0
        };
    };

    void OBJRGN_BroadcastServerText(const char* szText); // 0x00546FF0
};

D2_CHECK_SIZE(D2GameLinkStrc, 0x8);
D2_CHECK_SIZE(D2GameStrc, 0x1DF4);
D2_CHECK_OFFSET(D2GameStrc, lpCriticalSection, 0x18);
D2_CHECK_OFFSET(D2GameStrc, nGameId, 0x28);
D2_CHECK_OFFSET(D2GameStrc, pClientList, 0x88);
D2_CHECK_OFFSET(D2GameStrc, dwGameFrame, 0xA8);
D2_CHECK_OFFSET(D2GameStrc, pAct, 0xBC);
D2_CHECK_OFFSET(D2GameStrc, pGameSeed, 0xD0);
D2_CHECK_OFFSET(D2GameStrc, pMonReg, 0xF0);
D2_CHECK_OFFSET(D2GameStrc, pUnitList, 0x1120);
D2_CHECK_OFFSET(D2GameStrc, pNpcControl, 0x1D24);
D2_CHECK_OFFSET(D2GameStrc, hParty, 0x1D2C);
D2_CHECK_OFFSET(D2GameStrc, nUberFields, 0x1DD4);
