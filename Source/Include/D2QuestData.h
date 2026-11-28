#pragma once
// Per-quest data blocks hung off D2QuestDataStrc::pQuestDataEx

#include "D2Check.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Path.h"

struct D2ActiveRoomStrc;
struct D2MapAIStrc;
struct D2UnitStrc;
struct D2Act1Quest1Strc;
struct D2Act1Quest2Strc;
struct D2Act1Quest3Strc;
struct D2Act1Quest4Strc;
struct D2Act1Quest5Strc;
struct D2Act1Quest6Strc;
struct D2Act2Quest0Strc;
struct D2Act2Quest1Strc;
struct D2Act2Quest2Strc;
struct D2Act2Quest3Strc;
struct D2Act2Quest4Strc;
struct D2Act2Quest5Strc;
struct D2Act2Quest6Strc;
struct D2Act2Quest7Strc;
struct D2Act2Quest8Strc;
struct D2Act3Quest0Strc;
struct D2Act3Quest1Strc;
struct D2Act3Quest2Strc;
struct D2Act3Quest3Strc;
struct D2Act3Quest4Strc;
struct D2Act3Quest5Strc;
struct D2Act3Quest6Strc;
struct D2Act3Quest7Strc;
struct D2Act4Quest1Strc;
struct D2Act4Quest2Strc;
struct D2Act4Quest3Strc;
struct D2Act5Quest1Strc;
struct D2Act5Quest2Strc;
struct D2Act5Quest3Strc;
struct D2Act5Quest4Strc;
struct D2Act5Quest5Strc;
struct D2Act5Quest6Strc;

struct D2Act1Quest1Strc
{
    D2QuestGUIDStrc pQuestGUID; // 0x00
    unsigned char bFinished; // 0x84
    unsigned char bEnteredDen; // 0x85
    unsigned char bAkaraActivated; // 0x86
    unsigned char bTimerActive; // 0x87
    int nMonstersLeft; // 0x88
};

struct D2Act1Quest2Strc
{
    union
    {
        unsigned short unused0x00; // 0x00
        struct
        {
            unsigned char bFinished; // 0x00
            unsigned char unused0x01; // 0x01
        };
    };
    unsigned char bBloodravenKilled; // 0x02
    unsigned char bKashyaActivated; // 0x03
    int unused0x04; // 0x04
    int nBloodravenGUID; // 0x08
};

struct D2Act1Quest3Strc
{
    unsigned char unused0x00; // 0x00
    unsigned char bMalusInitialized; // 0x01
    unsigned char bCharsiIntroActivated; // 0x02
    unsigned char bCharsiEndActivated; // 0x03
    int nMalusGUID; // 0x04
    unsigned char unused0x08; // 0x08
    unsigned char unused0x09; // 0x09
    unsigned short unused0x0A; // 0x0A
    int unused0x0C; // 0x0C
    unsigned char unused0x10; // 0x10
    unsigned char pad0x11; // 0x11
    unsigned short unused0x12; // 0x12
    D2QuestGUIDStrc tPlayerGUIDs; // 0x14
    int nMalusObjectMode; // 0x98
    int nMalusItemsInGame; // 0x9C
    unsigned char bMalusAcquired; // 0xA0
    unsigned char bStartingPlayerHasMalus; // 0xA1
    unsigned short pad0xA2; // 0xA2
};

struct D2Act1Quest4Strc
{
    unsigned short nStoneOrder[5]; // 0x00
    unsigned short unused0x0A; // 0x0A
    unsigned short nStoneCount; // 0x0C
    unsigned short pad0x0E; // 0x0E
    int nMonolithGUIDs[5]; // 0x10
    int unused0x24; // 0x24
    int nInvisibleObjectGUID; // 0x28
    short nCairnStoneInteractions; // 0x2C
    unsigned short pad0x2E; // 0x2E
    int nInifussTreeGUID; // 0x30
    int nCainGibbetGUID; // 0x34
    int nDecipheredScrollGUID; // 0x38
    int nPlayerGUID; // 0x3C
    int nCairnStoneAlphaGUID; // 0x40
    unsigned char bOpenPortalTimerActive; // 0x44
    unsigned char bPortalToTristramOpened; // 0x45
    unsigned char bTimerActive; // 0x46
    unsigned char bInifussTreeInitialized; // 0x47
    unsigned char bCageModeChanged; // 0x48
    unsigned char bInvisbleObjectInitialized; // 0x49
    unsigned char bMonolithStonesOrdered; // 0x4A
    unsigned char unused0x4B; // 0x4B
    unsigned char bStonesActive; // 0x4C
    unsigned char bActivateCairnStones; // 0x4D
    unsigned char bDecipheredScrollAcquired; // 0x4E
    unsigned char bOperatedWithLastCairnStone; // 0x4F
    unsigned char bCompleted; // 0x50
    unsigned char bCainInTownSpawned; // 0x51
    unsigned char bCainInTownSpawnPending; // 0x52
    unsigned char bAkaraIntroActivated; // 0x53
    int nCainGibbetObjectMode; // 0x54
    int nInifussTreeObjectMode; // 0x58
    unsigned char bCairnStonesActive[5]; // 0x5C
    unsigned char bCainRemovedFromTristram; // 0x61
    unsigned char bCainNotCreated; // 0x62
    unsigned char bQuestCompleteBefore; // 0x63
    unsigned char bAkaraActivatedForScroll; // 0x64
    unsigned char bCainRemovalStarted; // 0x65
    unsigned char bPortalFromTristramToTownSpawned; // 0x66
    unsigned char bCainPortalCoordsInitialized; // 0x67
    int nCainMonsterInTownGUID; // 0x68
    int nCainObjectGUID; // 0x6C
    unsigned char bCainObjectInitialized; // 0x70
    unsigned char pad0x71; // 0x71
    unsigned short pad0x72; // 0x72
    D2UnitStrc* pPlayerInTristram; // 0x74
    unsigned char bScrollAcquired; // 0x78
    unsigned char pad0x79; // 0x79
    unsigned short pad0x7A; // 0x7A
    int nScrollsInGame; // 0x7C
    int nObjectUpdateInvocations; // 0x80
    D2CoordStrc pCainStartPositionCoords; // 0x84
    int nGoldPilesToDropFromWirtsBody; // 0x8C
    unsigned char bWirtsBodyInitialized; // 0x90
    unsigned char bChangePortalOutsideTownToSpecialMode; // 0x91
    unsigned char bChangePortalInTownToSpecialMode; // 0x92
    unsigned char bCainInTristramDeactivated; // 0x93
    unsigned char unused0x94; // 0x94
    unsigned char bCainPortalOutsideTownSpawned; // 0x95
    unsigned char bCainPortalInTownSpawned; // 0x96
    unsigned char pad0x97; // 0x97
    int nCainPortalOutsideTownGUID; // 0x98
    D2CoordStrc pCainPortalOutsideTownCoords; // 0x9C
    int nCainPortalInTownGUID; // 0xA4
    D2CoordStrc pCainPortalInTownCoords; // 0xA8
    int unused0xB0; // 0xB0
    D2QuestGUIDStrc pQuestGUID; // 0xB4
    D2QuestGUIDStrc tPlayerGUIDs; // 0x138
};

struct D2Act1Quest5Strc
{
    int nUnitGUIDs1[12]; // 0x00
    unsigned short nUnitCount1; // 0x30
    unsigned short pad0x32; // 0x32
    int nUnitGUIDs2[12]; // 0x34
    unsigned short nUnitCount2; // 0x64
    unsigned short pad0x66; // 0x66
    int nObjectGUIDs[8]; // 0x68
    unsigned short nCountessChestCount; // 0x88
    unsigned short pad0x8A; // 0x8A
    D2QuestGUIDStrc tPlayerGUIDs; // 0x8C
    D2CoordStrc pCoord; // 0x110
    unsigned char bCountessKilled; // 0x118
    unsigned char bDeathMissilesCreated; // 0x119
    unsigned char bTriggerSeqFilter; // 0x11A
    unsigned char bTowerTomeActivated; // 0x11B
    unsigned char bTimerActive; // 0x11C
    unsigned char pad0x11D[3]; // 0x11D
};

struct D2Act1Quest6Strc
{
    D2QuestGUIDStrc pGUID1; // 0x00
    D2QuestGUIDStrc pGUID2; // 0x84
    D2QuestGUIDStrc pGUID3; // 0x108
    int nAndarielGUID; // 0x18C
    unsigned short unused0x190; // 0x190
    unsigned short nTimerInvocations; // 0x192
    unsigned char bAndarielKilled; // 0x194
    unsigned char bCainActivated; // 0x195
    unsigned short pad0x196; // 0x196
};

struct D2Act2Quest0Strc
{
    D2QuestGUIDStrc tPlayerGUIDs; // 0x00
};

struct D2Act2Quest1Strc
{
    unsigned char bRadamentKilled; // 0x00
    unsigned char pad0x01; // 0x01
    unsigned short pad0x02; // 0x02
    D2ActiveRoomStrc* pRoom; // 0x04
    unsigned char bAtmaActivated; // 0x08
    unsigned char bRadamentStatusIterated; // 0x09
    unsigned char bStatusTimerStarted; // 0x0A
    unsigned char pad0x0B; // 0x0B
    int nSkillBookDropCount; // 0x0C
    unsigned char rewardPending; // 0x10
    unsigned char pad0x11; // 0x11
    unsigned short pad0x12; // 0x12
};

struct D2Act2Quest2Strc
{
    int unused0x00[5]; // 0x00
    int nItemDropCount; // 0x14
    int nBaseStaffs; // 0x18
    int nCubedStaffs; // 0x1C
    int nHoradricCubes; // 0x20
    int nAmulets; // 0x24
    unsigned char bHoradricScrollDropped; // 0x28
    unsigned char bCubeDropped; // 0x29
    unsigned char bStaffCubed; // 0x2A
    unsigned char bStaffMissingDetected; // 0x2B
    int nPlayerGUID; // 0x2C
};

struct D2Act2Quest3Strc
{
    unsigned char unused0x00; // 0x00
    unsigned char bDarkenTimerCreated; // 0x01
    unsigned char bDarknessApplied; // 0x02
    unsigned char bDarknessPending; // 0x03
    unsigned char bAltarDestroyed; // 0x04
    unsigned char bAltarInitialized; // 0x05
    unsigned char bTimerActive; // 0x06
    unsigned char pad0x07; // 0x07
    int nAltarMode; // 0x08
    int nAltarGUID; // 0x0C
    D2ActiveRoomStrc* pRoom; // 0x10
    D2QuestGUIDStrc tPlayerGUIDs; // 0x14
    int nAltarLevelId; // 0x98
    int nViperAmuletDropCount; // 0x9C
};

struct D2Act2Quest4Strc
{
    unsigned char unused0x00; // 0x00
    unsigned char unused0x01; // 0x01
    unsigned char unused0x02; // 0x02
    unsigned char unused0x03; // 0x03
    unsigned char bDrognanActivated; // 0x04
    unsigned char pad0x05; // 0x05
    unsigned short pad0x06; // 0x06
    D2ActiveRoomStrc* pRoom; // 0x08
    unsigned char bJerhynStartInitialized; // 0x0C
    unsigned char bJerhynPalaceInitialized; // 0x0D
    unsigned char bPalaceOpen; // 0x0E
    unsigned char bJerhynTeleportedToPalace; // 0x0F
    unsigned char bGuardMoveStarted; // 0x10
    unsigned char bHaremBlockerInitialized; // 0x11
    unsigned short unused0x12; // 0x12
    unsigned char bJerhynInPalace; // 0x14
    unsigned char bJerhynCoordinatesStored; // 0x15
    unsigned char bPortalToCanyonOpen; // 0x16
    unsigned char unused0x17; // 0x17
    unsigned char bGuardAtPost; // 0x18
    unsigned char bGuardSteppedAside; // 0x19
    unsigned char bPlayerCloseToHaremBlocker; // 0x1A
    unsigned char pad0x1B; // 0x1B
    int nPlayerCloseToHaremBlockerGUID; // 0x1C
    D2CoordStrc pHaremBlockerCoords; // 0x20
    D2CoordStrc pJerhynCoords; // 0x28
    D2CoordStrc pGuardCoords; // 0x30
    int nHaremBlockerGUID; // 0x38
    int nJerhynGUID; // 0x3C
    unsigned short nHaremBlockerObjectMode; // 0x40
    unsigned short nPortalModeInSanctuary; // 0x42
    unsigned short nPortalModeInCellar; // 0x44
    unsigned char bIsHaremBlockerNeutral; // 0x46
    unsigned char pad0x47; // 0x47
};

struct D2Act2Quest5Strc
{
    unsigned char bSummonerKilled; // 0x00
    unsigned char bSummonerActivated; // 0x01
    unsigned short pad0x02; // 0x02
    D2ActiveRoomStrc* pRoom; // 0x04
    unsigned char bStatusTimerStarted; // 0x08
    unsigned char bCompletionSoundAttached; // 0x09
    unsigned short pad0x0A; // 0x0A
};

struct D2Act2Quest6Strc
{
    unsigned char bStatusTimerActive; // 0x00
    unsigned char bDurielKilled; // 0x01
    unsigned char unused0x02; // 0x02
    unsigned char bTimerActive; // 0x03
    unsigned char bHoradricOrificeInitialized; // 0x04
    unsigned char bTyraelsDoorInitialized; // 0x05
    unsigned char bUnusedObjectInitialized; // 0x06
    unsigned char unused0x07; // 0x07
    unsigned char bInitJerhynActivated; // 0x08
    unsigned char bTyraelActivated; // 0x09
    unsigned char bEndJerhynActivated; // 0x0A
    unsigned char bDurielLairTombOpen; // 0x0B
    unsigned char bDurielLairPortalNeedsToOpen; // 0x0C
    unsigned char bObjectsNeedUpdate; // 0x0D
    unsigned char bStaffItemsRemoved; // 0x0E
    unsigned char bPortalToLutGholeinOpened; // 0x0F
    unsigned char bHoradricStaffIsMissing; // 0x10
    unsigned char pad0x11; // 0x11
    unsigned short pad0x12; // 0x12
    int nQuestStatus; // 0x14
    int nTyraelsDoorObjectMode; // 0x18
    int unused0x1C; // 0x1C
    int nHoradricOrificeGUID; // 0x20
    int unused0x24; // 0x24
    int nUnusedObjectGUID; // 0x28
    int nTyraelsDoorGUID; // 0x2C
    int unused0x30; // 0x30
    int nStaffTombLevelId; // 0x34
    unsigned char bObjectIdsInitialized; // 0x38
    unsigned char pad0x39; // 0x39
    unsigned short nArcaneThings; // 0x3A
    unsigned char bPortalIsOpening; // 0x3C
    unsigned char bRewardedOrCompletedBefore; // 0x3D
    unsigned short pad0x3E; // 0x3E
    D2UnitStrc* pTyrael; // 0x40
    unsigned char bCloseToTyrael; // 0x44
    unsigned char pad0x45; // 0x45
    unsigned short pad0x46; // 0x46
    int nArcaneThingObjectIds[6]; // 0x48
    D2ActiveRoomStrc* pDurielRoom; // 0x60
};

struct D2Act2Quest7Strc
{
    unsigned char bGuardActivated; // 0x00
};

struct D2Act2Quest8Strc
{
    unsigned char unused0x00; // 0x00
    unsigned char unused0x01; // 0x01
};

struct D2Act3Quest0Strc
{
    unsigned char bHratliStartCreated; // 0x00
    unsigned char bHratliEndCreated; // 0x01
    unsigned char bHratliEndObjectInitialized; // 0x02
    unsigned char bHratliStartIsPresent; // 0x03
    int nHratliX; // 0x04
    int nHratliY; // 0x08
    int nHratliGUID; // 0x0C
    unsigned char bHratliMapAIChanged; // 0x10
    unsigned char unused0x11; // 0x11
    unsigned short unused0x12; // 0x12
    int unused0x14; // 0x14
    D2MapAIStrc* pHratliMapAI; // 0x18
};

struct D2Act3Quest1Strc
{
    unsigned char bCanGetReward; // 0x00
    unsigned char bTomeDropped; // 0x01
    unsigned char bTomeActive; // 0x02
    unsigned char unused0x03; // 0x03
    unsigned char bTomeAcquired; // 0x04
    unsigned char bPlayerWithTomeDropped; // 0x05
    unsigned short pad0x06; // 0x06
    int nTomesInGame; // 0x08
    unsigned char bTomeBroughtToAlkor; // 0x0C
    unsigned char pad0x0D; // 0x0D
    unsigned short pad0x0E; // 0x0E
    int nPlayerWithTomeGUID; // 0x10
    int nTomeGUID; // 0x14
    int nTomeObjectMode; // 0x18
    D2QuestGUIDStrc tPlayerGUIDs; // 0x1C
};

struct D2Act3Quest2Strc
{
    unsigned char bSewerStairsInitialized; // 0x00
    unsigned char bInitiallyTalkedToCain; // 0x01
    unsigned short pad0x02; // 0x02
    int nSewerStairsObjectGUID; // 0x04
    int nSewerStairsObjectMode; // 0x08
    int nItemDropCount; // 0x0C
    int nEyesDropped; // 0x10
    int nBrainsDropped; // 0x14
    int nHeartsDropped; // 0x18
    int nFlailsDropped; // 0x1C
    int nCubedFlails; // 0x20
    unsigned char bEyeDropped; // 0x24
    unsigned char bBrainDropped; // 0x25
    unsigned char bHeartDropped; // 0x26
    unsigned char bFlailDropped; // 0x27
    int unused0x28; // 0x28
    D2QuestGUIDStrc tPlayerGUIDs; // 0x2C
};

struct D2Act3Quest3Strc
{
    unsigned char bGidbinnDropped; // 0x00
    unsigned char bHratliActivated; // 0x01
    unsigned char bBossHasSpawned; // 0x02
    unsigned char bGidbinnObjectActivated; // 0x03
    unsigned char bBossIsSpawning; // 0x04
    unsigned char bSpawnTimerStarted; // 0x05
    unsigned char bAltarCanBeActivated; // 0x06
    unsigned char bGidbinnBroughtToOrmus; // 0x07
    int nGidbinnX; // 0x08
    int nGidbinnY; // 0x0C
    int nAltarX; // 0x10
    int nAltarY; // 0x14
    unsigned char bGidbinnObjectInitialized; // 0x18
    unsigned char pad0x19; // 0x19
    unsigned short pad0x1A; // 0x1A
    int nGidbinnsInGame; // 0x1C
    unsigned char bPlayerWithGidbinnDropped; // 0x20
    unsigned char pad0x21; // 0x21
    unsigned short pad0x22; // 0x22
    int nFetishBossGUID; // 0x24
    int nAltarGUID; // 0x28
    int nAltarObjectMode; // 0x2C
};

struct D2Act3Quest4Strc
{
    unsigned char bGoldenBirdBroughtToAlkor; // 0x00
    unsigned char bWaitingForBoss; // 0x01
    unsigned char bBossAssigned; // 0x02
    unsigned char pad0x03; // 0x03
    int nBossGUID; // 0x04
    unsigned char bTalkedToAlkor; // 0x08
    unsigned char bTalkedToCainOnce; // 0x09
    unsigned char bTalkedToCainTwice; // 0x0A
    unsigned char bTalkedToMeshif; // 0x0B
    unsigned char bJadeFigurineDropPending; // 0x0C
    unsigned char pad0x0D; // 0x0D
    unsigned short pad0x0E; // 0x0E
    int nGoldenBirdsInGame; // 0x10
    unsigned char bJadeFigurineDropped; // 0x14
    unsigned char bPlayerDroppedWithItem; // 0x15
    unsigned short pad0x16; // 0x16
    int nCurrentQuestFlag; // 0x18
};

struct D2Act3Quest5Strc
{
    int nLastKilledMonsterGUID; // 0x00
    unsigned char bOrmusActivated; // 0x04
    unsigned char bMonstersSpawned; // 0x05
    unsigned short pad0x06; // 0x06
    int bQuest1RewardGranted; // 0x08
    unsigned char bOrbSmashed; // 0x0C
    unsigned char bFlailDropped; // 0x0D
    unsigned char bCubeDropped; // 0x0E
    unsigned char pad0x0F; // 0x0F
    int nMonsterGUIDs[6]; // 0x10
    unsigned char bCompellingOrbSpawned; // 0x28
    unsigned char pad0x29; // 0x29
    unsigned short pad0x2A; // 0x2A
    int nCompellingOrbGUID; // 0x2C
    int nSpawnCount; // 0x30
    int nMonstersLeftToKill; // 0x34
    int nHits; // 0x38
    int nFlailsMissing; // 0x3C
    int nHoradricCubesMissing; // 0x40
    int unused0x44[3]; // 0x44
};

struct D2Act3Quest6Strc
{
    unsigned char bTimerStarted; // 0x00
    unsigned char bHellGatePortalInitialized; // 0x01
    unsigned char bMephistoBridgeInitialized; // 0x02
    unsigned char bOrmusActivated; // 0x03
    int nHellGatePortalGUID; // 0x04
    int nMephistoBridgeGUID; // 0x08
    int nHellGatePortalObjectMode; // 0x0C
    int nMephistoBridgeObjectMode; // 0x10
    int nSoulStonesDropped; // 0x14
    unsigned char bSoulStoneDropped; // 0x18
    unsigned char pad0x19; // 0x19
    unsigned short pad0x1A; // 0x1A
    int nSoulstonesToDrop; // 0x1C
    unsigned char bNatalyaSpawned; // 0x20
    unsigned char pad0x21; // 0x21
    unsigned short pad0x22; // 0x22
    D2MapAIStrc* pNatalyaMapAI; // 0x24
    int nSavedStatus; // 0x28
    int nNatalyaGUID; // 0x2C
    unsigned char bNatalyaMapAIChanged; // 0x30
    unsigned char pad0x31; // 0x31
    unsigned short pad0x32; // 0x32
};

struct D2Act3Quest7Strc
{
    unsigned char bDarkWandererInitialized; // 0x00
    unsigned char bPrimaryGoalOpen; // 0x01
    unsigned char bWandererCoordsCalculated; // 0x02
    unsigned char pad0x03; // 0x03
    int nDarkWandererX; // 0x04
    int nDarkWandererY; // 0x08
    unsigned char bVileDogsSpawned; // 0x0C
    unsigned char bVileDogSpawnTimerCreated; // 0x0D
    unsigned short pad0x0E; // 0x0E
    int nUnitGUID; // 0x10
};

struct D2Act4Quest1Strc
{
    int unused0x00; // 0x00
    D2CoordStrc pCoords; // 0x04
    unsigned char bPlayerStartedGame; // 0x0C
    unsigned char bIzualGhostIsSpawning; // 0x0D
    unsigned char unused0x0E; // 0x0E
    unsigned char bGhostActivated; // 0x0F
    unsigned char bNeedToSpawnIzualGhost; // 0x10
    unsigned char bTyraelActivated; // 0x11
    unsigned char bIzualGhostActivated; // 0x12
    unsigned char pad0x13; // 0x13
    D2UnitStrc* pTargetUnit; // 0x14
    unsigned char bCloseToIzualGhost; // 0x18
    unsigned char pad0x19; // 0x19
    unsigned short pad0x1A; // 0x1A
};

struct D2Act4Quest2Strc
{
    unsigned char bTalkedToTyrael; // 0x00
    unsigned char bTimerCreated; // 0x01
    unsigned char bNeedToSpawnDiablo; // 0x02
    unsigned char bEndGameTimerActive; // 0x03
    unsigned char bNeedToEndGame; // 0x04
    unsigned char bNeedToWarpPlayers; // 0x05
    unsigned char bDiabloStartPointInitialized; // 0x06
    unsigned char pad0x07; // 0x07
    int nDiabloStartPointObjectGUID; // 0x08
    unsigned char bSealActivated[5]; // 0x0C
    unsigned char bDiabloSpawned; // 0x11
    unsigned char unused0x12; // 0x12
    unsigned char bSanctumCleared; // 0x13
    unsigned char bDiabloKilled; // 0x14
    unsigned char bClientsSaved; // 0x15
    unsigned short pad0x16; // 0x16
    unsigned int dwTickCount; // 0x18
    int nPlayerCount; // 0x1C
    D2UnitStrc* pWarpedPlayer; // 0x20
    D2CoordStrc pSealCoords[3]; // 0x24
    D2ActiveRoomStrc* pRoom; // 0x3C
    int nLastLastPortalObjectMode; // 0x40
    unsigned char bSpawnPortalToAct5Pending; // 0x44
    unsigned char bPortalToAct5Spawned; // 0x45
    unsigned short pad0x46; // 0x46
    int nBossesKilled; // 0x48
};

struct D2Act4Quest3Strc
{
    unsigned short nHellforgeMode; // 0x00
    unsigned char bCainActivated; // 0x02
    unsigned char bRewardDropsPending; // 0x03
    unsigned char bRewardPending; // 0x04
    unsigned char pad0x05; // 0x05
    unsigned short pad0x06; // 0x06
    int nRewardState; // 0x08
    int nHammerHits; // 0x0C
    int nHellforgeHammersInGame; // 0x10
    int nPlayersInAct; // 0x14
    int unused0x18; // 0x18
    unsigned char bSoulstoneAcquired; // 0x1C
    unsigned char pad0x1D; // 0x1D
    unsigned short pad0x1E; // 0x1E
};

struct D2Act5Quest1Strc
{
    D2MapAIStrc* pLarzukMapAI; // 0x00
    D2ActiveRoomStrc* pRoom; // 0x04
    unsigned char bLarzukStartActivated; // 0x08
    unsigned char unused0x09; // 0x09
    unsigned short unused0x0A; // 0x0A
    int unused0x0C; // 0x0C
    int nLarzukGUID; // 0x10
    unsigned char unused0x14; // 0x14
    unsigned char bLarzukSpawned; // 0x15
    unsigned char bLarzukEndActivated; // 0x16
    unsigned char bLarzukMapAIChanged; // 0x17
};

struct D2Act5Quest2Strc
{
    char tPlayerGUIDs[132]; // 0x00
    unsigned char bQualKehkActivated; // 0x84
    unsigned char unused0x85; // 0x85
    unsigned char bWussiesSpawned[3]; // 0x86
    unsigned char pad0x89; // 0x89
    unsigned short pad0x8A; // 0x8A
    D2CoordStrc pWussieCoords[3]; // 0x8C
    int nSpawnedWussies; // 0xA4
    int nKilledWussies; // 0xA8
    int nFreedWussies; // 0xAC
    int nWussieGUIDs[3][5]; // 0xB0
    int nPortalGUIDs[3]; // 0xEC
    unsigned char bPortalSpawned[3]; // 0xF8
    unsigned char pad0xFB; // 0xFB
    int nPortalUpdateInvocations[3]; // 0xFC
    unsigned char bGroupDone[3]; // 0x108
    unsigned char bChangeToSpecialObjectMode[3]; // 0x10B
    unsigned char bPortalAttempted[3]; // 0x10E
    unsigned char pad0x111; // 0x111
    unsigned short pad0x112; // 0x112
    int nGroupKills[3]; // 0x114
    int nFreedWussieUnitGUIDs[15]; // 0x120
    int nWussiesInRangeToDoor; // 0x15C
};

struct D2Act5Quest3Strc
{
    D2QuestGUIDStrc tPlayerGUIDs; // 0x00
    int nDrehyaState; // 0x84
    int bNihlathakLeftTown; // 0x88
    int nTimerInvocations; // 0x8C
    unsigned char bDrehyaIcedMonsterSpawned; // 0x90
    unsigned char bDrehyaMonsterInTownSpawned; // 0x91
    unsigned char bNilathakOutsideTownSpawned; // 0x92
    unsigned char bNihlathakMonsterInTownSpawned; // 0x93
    int nDrehyaMonsterInTownGUID; // 0x94
    int nDrehyaIcedMonsterGUID; // 0x98
    int NihlathakMonsterInTownGUID; // 0x9C
    int nNihlathakOutsideTownGUID; // 0xA0
    unsigned char bFrozenAnyaObjectSpawned; // 0xA4
    unsigned char pad0xA5; // 0xA5
    unsigned short pad0xA6; // 0xA6
    int nFrozenDrehyaObjectGUID; // 0xA8
    unsigned char bMalahIntroActivated; // 0xAC
    unsigned char bChangeToSpecialObjectModeOutsideTown; // 0xAD
    unsigned char bChangeToSpecialObjectModeInTown; // 0xAE
    unsigned char unused0xAF; // 0xAF
    unsigned char unused0xB0; // 0xB0
    unsigned char bDrehyaPortalOutsideTownSpawned; // 0xB1
    unsigned char bDrehyaPortalInTownSpawned; // 0xB2
    unsigned char pad0xB3; // 0xB3
    int nDrehyaPortalInTownGUID; // 0xB4
    D2CoordStrc tDrehyaPortalInTownCoords; // 0xB8
    int nDrehyaPortalOutsideTownGUID; // 0xC0
    D2CoordStrc pDrehyaPortalCoords; // 0xC4
    int unused0xCC[3]; // 0xCC
    int nDefrostPotionsInGame; // 0xD8
    int nObjectUpdateInvocations; // 0xDC
    unsigned char bDrehyaPortalCoordsInitialized; // 0xE0
    unsigned char bDrehyaInTownInitialized; // 0xE1
    unsigned char bDefrostPotionAcquired; // 0xE2
    unsigned char bDrehyaIcedRemoved; // 0xE3
    int nDrehyaObjectInTownGUID; // 0xE4
    D2CoordStrc pDrehyaObjectInTownCoords; // 0xE8
    D2CoordStrc pDrehyaObjectOutsideTownCoords; // 0xF0
    int nDrehyaObjectOutsideTownGUID; // 0xF8
    int nFrozenAnyaObjectGUID; // 0xFC
    unsigned char bTimerActive; // 0x100
    unsigned char bMalahActivated; // 0x101
    unsigned char bRewarded; // 0x102
    unsigned char pad0x103; // 0x103
    D2MapAIStrc* pDrehyaMapAI; // 0x104
    D2MapAIStrc* pNilathakMapAI; // 0x108
    unsigned char bDrehyaMapAIChanged; // 0x10C
    unsigned char bNilathakMapAIChanged; // 0x10D
    unsigned short pad0x10E; // 0x10E
    int nNihlathakObjectInTownGUID; // 0x110
};

struct D2Act5Quest4Strc
{
    D2QuestGUIDStrc tPlayerGUIDs; // 0x00
    unsigned char unused0x84; // 0x84
    unsigned char bTimerActive; // 0x85
    unsigned char bDrehyaActivated; // 0x86
    unsigned char bNeedsToOpenPortal; // 0x87
    unsigned char bPortalCreated; // 0x88
    unsigned char bWaypointNotActivated; // 0x89
    unsigned short pad0x8A; // 0x8A
    D2ActiveRoomStrc* pRoom; // 0x8C
};

struct D2Act5Quest5Strc
{
    unsigned char bAncientsDefeated; // 0x00
    unsigned char bQualKehkActivated; // 0x01
    unsigned short unused0x02; // 0x02
    unsigned char bTimerActive; // 0x04
    unsigned char unused0x05; // 0x05
    unsigned short unused0x06; // 0x06
    int unused0x08; // 0x08
    int nActivePortalCount; // 0x0C
    unsigned char active; // 0x10
    unsigned char bActivatable; // 0x11
    unsigned short pad0x12; // 0x12
    int nAncientStatueGUID[3]; // 0x14
    int nAncientMonsterGUID[3]; // 0x20
    unsigned char bAncientMonsterSpawned[3]; // 0x2C
    unsigned char pad0x2F; // 0x2F
    int nAncientStatueObjectMode[3]; // 0x30
    unsigned char bAncienStatueRespawned[3]; // 0x3C
    unsigned char pad0x3F; // 0x3F
    int nAncientsSpawned; // 0x40
    int nAncientsAlive; // 0x44
    unsigned char bAncientsActivated; // 0x48
    unsigned char unused0x49; // 0x49
    unsigned char bQuestCompletedBefore; // 0x4A
    unsigned char pad0x4B; // 0x4B
    int nAltarObjectMode; // 0x4C
    int nAltarGUID; // 0x50
    int nLivingPlayersOnSummit; // 0x54
    unsigned char bSummitDoorInitialized; // 0x58
    unsigned char pad0x59; // 0x59
    unsigned short pad0x5A; // 0x5A
    int nSummitDoorGUID; // 0x5C
    int nSummitDoorObjectMode; // 0x60
};

struct D2Act5Quest6Strc
{
    D2QuestGUIDStrc tPlayerGUIDs; // 0x00
    unsigned short unused0x84; // 0x84
    unsigned char bWorldStoneChamberOpen; // 0x86
    unsigned char pad0x87; // 0x87
    int nCompletions; // 0x88
    D2ActiveRoomStrc* pRoom; // 0x8C
    unsigned char bQuestStarted; // 0x90
    unsigned char pad0x91; // 0x91
    unsigned short pad0x92; // 0x92
    int nBaalPortalObjectMode; // 0x94
    unsigned char bLastPortalOpened; // 0x98
    unsigned char pad0x99; // 0x99
    unsigned short pad0x9A; // 0x9A
    int nLastPortalObjectMode; // 0x9C
    unsigned char bZooInitialized; // 0xA0
    unsigned char pad0xA1; // 0xA1
    unsigned short pad0xA2; // 0xA2
    int nZooMonsterId; // 0xA4
};

struct D2GameStrc;
struct D2QuestDataStrc;

typedef bool (__fastcall* QUESTUPDATE)(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);

struct D2QuestTimerStrc
{
    QUESTUPDATE pfUpdate; // 0x00
    D2QuestDataStrc* pQuest; // 0x04
    unsigned int dwTicks; // 0x08
    unsigned int dwTimeout; // 0x0C
    D2QuestTimerStrc* pNext; // 0x10
};

D2_CHECK_SIZE(D2Act1Quest1Strc, 0x8C);
D2_CHECK_SIZE(D2Act1Quest2Strc, 0xC);
D2_CHECK_SIZE(D2Act1Quest3Strc, 0xA4);
D2_CHECK_SIZE(D2Act1Quest4Strc, 0x1BC);
D2_CHECK_SIZE(D2Act1Quest5Strc, 0x120);
D2_CHECK_SIZE(D2Act1Quest6Strc, 0x198);
D2_CHECK_SIZE(D2Act2Quest0Strc, 0x84);
D2_CHECK_SIZE(D2Act2Quest1Strc, 0x14);
D2_CHECK_SIZE(D2Act2Quest2Strc, 0x30);
D2_CHECK_SIZE(D2Act2Quest3Strc, 0xA0);
D2_CHECK_SIZE(D2Act2Quest4Strc, 0x48);
D2_CHECK_SIZE(D2Act2Quest5Strc, 0xC);
D2_CHECK_SIZE(D2Act2Quest6Strc, 0x64);
D2_CHECK_SIZE(D2Act2Quest7Strc, 0x1);
D2_CHECK_SIZE(D2Act2Quest8Strc, 0x2);
D2_CHECK_SIZE(D2Act3Quest0Strc, 0x1C);
D2_CHECK_SIZE(D2Act3Quest1Strc, 0xA0);
D2_CHECK_SIZE(D2Act3Quest2Strc, 0xB0);
D2_CHECK_SIZE(D2Act3Quest3Strc, 0x30);
D2_CHECK_SIZE(D2Act3Quest4Strc, 0x1C);
D2_CHECK_SIZE(D2Act3Quest5Strc, 0x50);
D2_CHECK_SIZE(D2Act3Quest6Strc, 0x34);
D2_CHECK_SIZE(D2Act3Quest7Strc, 0x14);
D2_CHECK_SIZE(D2Act4Quest1Strc, 0x1C);
D2_CHECK_SIZE(D2Act4Quest2Strc, 0x4C);
D2_CHECK_SIZE(D2Act4Quest3Strc, 0x20);
D2_CHECK_SIZE(D2Act5Quest1Strc, 0x18);
D2_CHECK_SIZE(D2Act5Quest2Strc, 0x160);
D2_CHECK_SIZE(D2Act5Quest3Strc, 0x114);
D2_CHECK_SIZE(D2Act5Quest4Strc, 0x90);
D2_CHECK_SIZE(D2Act5Quest5Strc, 0x64);
D2_CHECK_SIZE(D2Act5Quest6Strc, 0xA8);
D2_CHECK_SIZE(D2QuestTimerStrc, 0x14);
