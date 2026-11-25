#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2GameAux.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00732850

#define STAT_DEXTERITY 2

#define STAT_HITPOINTS 6

#define STAT_MAXHP 7

#define STAT_LEVEL 12

#define STAT_ARMORCLASS 31

#define STAT_MINDAMAGE 21

#define STAT_MAXDAMAGE 22

#define STAT_SECONDARY_MINDAMAGE 23

#define STAT_SECONDARY_MAXDAMAGE 24

#define STAT_FIRERESIST 39

#define STAT_LIGHTRESIST 41

#define STAT_COLDRESIST 43

#define STAT_POISONRESIST 45

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_MONSTER 1

#define UNIT_INVALID 6

#define MONSTATSFLAGINDEX_SWITCHAI 16


struct D2PetInfoStrc;

struct D2SkillsTxt;

struct Node00572DA0;

struct List00572DA0;

struct Node00572DC0;

struct List00572DC0;

struct Node00572DE0;

struct List00572DE0;

struct D2MonsterDataStrc;

struct D2PackedGuidStrc;

struct D2MessageStrc;

struct D2MessageListStrc;

struct D2GSPacketSrv27;

struct D2MonStatsTxt;

struct D2MercDataStrc;

struct D2HirelingInitStrc;

struct D2GameStrc;


struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2HirelingTxt;


void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc* pUnit, unsigned short nStatId, int nValue); // 0x005718C0

D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void __fastcall AITACTICS_AddMessage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScrollTarget, unsigned short wMessage, int bScrollMessage); // 0x005DE330

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID); // 0x00574BD0

int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0


void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

struct Node00572DA0 {
    unsigned int dwValue00;
    unsigned int dwUnknown04;
    Node00572DA0* pNext;
};

struct List00572DA0 {
    Node00572DA0* pHead;
};

struct Node00572DC0 {
    unsigned int dwValue00;
    unsigned int dwUnknown04;
    Node00572DC0* pNext;
};

struct List00572DC0 {
    Node00572DC0* pHead;
};

struct Node00572DE0 { int nId; unsigned int dwUnknown04; Node00572DE0* pNext; };

struct List00572DE0 { Node00572DE0* pHead; };

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

void __fastcall SCMD_SendInteractionTarget(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int a5); // 0x0053D6D0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall D2GAME_NPC_Heal_6FCCB220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00578E70

void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00543D50

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00537190

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    D2MessageListStrc messageList;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x00681CE0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0

void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0

void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520

void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl); // 0x00543D10

void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00544520

void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bNoInteractInfo); // 0x00576770

int __fastcall ACT1Q4_IsCainInTristramDeactivated(D2GameStrc* pGame); // 0x00594610

void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMsgList); // 0x00661480

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" const char gszMonsterAISourceFile[]; // 0x006E1560

static int __stdcall MONSTERAI_TryStartNpcInteraction(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract, char nQuestFlags, D2UnitStrc* pTarget, D2UnitStrc* pUnit);

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int unk0x34[2];
};

void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short a2, int a3); // 0x0053E0E0

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignment, int a3); // 0x005543B0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3); // 0x005726C0

void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMerc, int nLevel); // 0x00572840

void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitGUID, int a4); // 0x005750E0

void __fastcall PLAYERPETS_AddPetWithInfo(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, D2PetInfoStrc* pPetInfo); // 0x00575E90

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bGuard, int a6); // 0x0058F030

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int a4); // 0x005A4850

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nVersion, unsigned short nMercName); // 0x00663750

int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0

static int MONSTERAI_CanSwitchAi(D2UnitStrc* pUnit);

int __fastcall MONSTERAI_SetTargetOverride(D2UnitStrc* pUnit, int nState, int nValue);

// 0x005726C0
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3)
{
    D2UnitStrc* pMerc = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, PETTYPE_HIREABLE, 0);
    if (!pMerc)
    {
        return;
    }

    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_LEVEL, STATLIST_UnitGetStatValue(pMerc, STAT_LEVEL, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_STRENGTH, STATLIST_GetUnitBaseStat(pMerc, STAT_STRENGTH, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_DEXTERITY, STATLIST_GetUnitBaseStat(pMerc, STAT_DEXTERITY, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MAXHP, STATLIST_GetUnitBaseStat(pMerc, STAT_MAXHP, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_HITPOINTS, STATLIST_UnitGetStatValue(pMerc, STAT_HITPOINTS, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_ARMORCLASS, STATLIST_GetUnitBaseStat(pMerc, STAT_ARMORCLASS, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_EXPERIENCE, STATLIST_UnitGetStatValue(pMerc, STAT_EXPERIENCE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_NEXTEXP, STATLIST_UnitGetStatValue(pMerc, STAT_NEXTEXP, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MINDAMAGE, STATLIST_GetUnitBaseStat(pMerc, STAT_SECONDARY_MINDAMAGE, 0) + STATLIST_GetUnitBaseStat(pMerc, STAT_MINDAMAGE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_MAXDAMAGE, STATLIST_GetUnitBaseStat(pMerc, STAT_SECONDARY_MAXDAMAGE, 0) + STATLIST_GetUnitBaseStat(pMerc, STAT_MAXDAMAGE, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_FIRERESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_FIRERESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_LIGHTRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_LIGHTRESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_COLDRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_COLDRESIST, 0));
    D2GAME_MERCS_SendStat_6FCC61D0(pMerc, STAT_POISONRESIST, STATLIST_GetUnitBaseStat(pMerc, STAT_POISONRESIST, 0));
}

// 0x00572840
void __fastcall MONSTERAI_UpdateMercStatsAndSkills(D2GameStrc* ptGame, D2UnitStrc* hPlayer, D2UnitStrc* pMerc, int nLevel)
{
    D2_ASSERT(ptGame, 0xE0);
    D2_ASSERT(hPlayer, 0xE1);
    D2_ASSERT(hPlayer->dwUnitType == UNIT_PLAYER, 0xE2);

    D2UnitStrc* pHireling = pMerc;
    if (!pHireling)
    {
        pHireling = PLAYERPETS_GetFirstPetByType(ptGame, hPlayer, 7, 0);
        if (!pHireling)
        {
            return;
        }
    }

    STATLIST_UnitGetStatValue(hPlayer, STAT_LEVEL, 0);
    const int nHirelingLevel = STATLIST_UnitGetStatValue(pHireling, STAT_LEVEL, 0);
    if (!nLevel)
    {
        nLevel = nHirelingLevel + 1;
    }

    AITACTICS_AddMessage(ptGame, pHireling, hPlayer, 0xD7C, 1);
    STATLIST_SetUnitStat(pHireling, STAT_LEVEL, nLevel, 0);

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(hPlayer, pHireling->dwUnitId);
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(ptGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    const int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;

    const int nNextExp = nLevel >= DATATBLS_GetMaxLevel(0) - 1 ? 0 : MONSTERS_GetHirelingExpForNextLevel(nLevel + 1, pHirelingTxtRecord->dwExpPerLvl);
    STATLIST_SetUnitStat(pHireling, STAT_NEXTEXP, nNextExp, 0);

    const int nExperience = MONSTERS_GetHirelingExpForNextLevel(nLevel, pHirelingTxtRecord->dwExpPerLvl);
    if (STATLIST_UnitGetStatValue(pHireling, STAT_EXPERIENCE, 0) < nExperience)
    {
        STATLIST_SetUnitStat(pHireling, STAT_EXPERIENCE, nExperience, 0);
    }

    int nStrength = pHirelingTxtRecord->nStr + nLevelUps * pHirelingTxtRecord->nStrPerLvl / 8;
    nStrength = nStrength < 10 ? 10 : nStrength;
    STATLIST_SetUnitStat(pHireling, STAT_STRENGTH, nStrength, 0);

    int nDexterity = pHirelingTxtRecord->nDex + nLevelUps * pHirelingTxtRecord->nDexPerLvl / 8;
    nDexterity = nDexterity < 10 ? 10 : nDexterity;
    STATLIST_SetUnitStat(pHireling, STAT_DEXTERITY, nDexterity, 0);

    int nHitpoints = (pHirelingTxtRecord->dwHitpoints << 8) + nLevelUps * (pHirelingTxtRecord->dwHitpointsPerLvl << 8);
    nHitpoints = nHitpoints < 0x2800 ? 0x2800 : nHitpoints;
    STATLIST_SetUnitStat(pHireling, STAT_MAXHP, nHitpoints, 0);
    STATLIST_SetUnitStat(pHireling, STAT_HITPOINTS, nHitpoints, 0);

    int nDefense = pHirelingTxtRecord->dwDefense + nLevelUps * pHirelingTxtRecord->dwDefensePerLvl;
    nDefense = nDefense < 0 ? 0 : nDefense;
    STATLIST_SetUnitStat(pHireling, STAT_ARMORCLASS, nDefense, 0);

    int nMinDamage = pHirelingTxtRecord->nDmgMin + nLevelUps * pHirelingTxtRecord->nDmgPerLvl / 8;
    nMinDamage = nMinDamage < 0 ? 0 : nMinDamage;
    STATLIST_SetUnitStat(pHireling, STAT_SECONDARY_MINDAMAGE, nMinDamage, 0);

    int nMaxDamage = pHirelingTxtRecord->nDmgMax + nLevelUps * pHirelingTxtRecord->nDmgPerLvl / 8;
    nMaxDamage = nMaxDamage < 1 ? 1 : nMaxDamage;
    STATLIST_SetUnitStat(pHireling, STAT_SECONDARY_MAXDAMAGE, nMaxDamage, 0);

    int nAttackRate = pHirelingTxtRecord->dwAttackRate + nLevelUps * pHirelingTxtRecord->dwAttackRatePerLvl;
    nAttackRate = nAttackRate < 0 ? 0 : nAttackRate;
    STATLIST_SetUnitStat(pHireling, STAT_TOHIT, nAttackRate, 0);

    int nResist = pHirelingTxtRecord->dwResist + nLevelUps * pHirelingTxtRecord->dwResistPerLvl / 4;
    nResist = nResist < 0 ? 0 : nResist;
    STATLIST_SetUnitStat(pHireling, STAT_FIRERESIST, nResist, 0);
    STATLIST_SetUnitStat(pHireling, STAT_LIGHTRESIST, nResist, 0);
    STATLIST_SetUnitStat(pHireling, STAT_COLDRESIST, nResist, 0);
    STATLIST_SetUnitStat(pHireling, STAT_POISONRESIST, nResist, 0);

    int nHpRegen = STATLIST_GetUnitBaseStat(pHireling, STAT_MAXHP, 0) / 2000;
    nHpRegen = nHpRegen < 0 ? 0 : nHpRegen;
    STATLIST_SetUnitStat(pHireling, STAT_HPREGEN, nHpRegen, 0);

    for (int i = 0; i < 6; ++i)
    {
        if (pHirelingTxtRecord->dwSkill[i] <= 0 || pHirelingTxtRecord->dwSkill[i] >= sgptDataTables->nSkillsTxtRecordCount || pHirelingTxtRecord->nMode[i] >= 16)
        {
            return;
        }

        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(pHirelingTxtRecord->dwSkill[i]);
        if (pSkillsTxtRecord && nLevel >= pSkillsTxtRecord->wReqLevel)
        {
            int nSkillLevel = pHirelingTxtRecord->nLevel[i] + (nLevelUps * pHirelingTxtRecord->nSLvlPerLvl[i] >> 5);
            nSkillLevel = nSkillLevel > 0 ? nSkillLevel : 0;
            nSkillLevel = nSkillLevel < 32 ? nSkillLevel : 32;
            if (nSkillLevel > 0)
            {
                D2GAME_SetSkills_6FD14C60(pHireling, pHirelingTxtRecord->dwSkill[i], nSkillLevel, 0);
            }
        }
    }
}

// 0x00572BA0
D2MonsterInteractStrc* __fastcall MONSTERAI_AllocMonsterInteract(D2GameStrc* pGame)
{
    D2MonsterInteractStrc* pMonInteract = (D2MonsterInteractStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2MonsterInteractStrc), ".\\MONSTER\\MonsterAI.cpp", 379, 0);
    pMonInteract->pInteractInfo = 0;
    return pMonInteract;
}

// 0x00572BC0
void __fastcall MONSTERAI_FreeMonsterInteract(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract)
{
    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;
    while (pInteractInfo)
    {
        D2InteractInfoStrc* pNext = pInteractInfo->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 392, 0);
        pInteractInfo = pNext;
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pMonInteract, ".\\MONSTER\\MonsterAI.cpp", 395, 0);
}

// 0x00572C10
static int __stdcall MONSTERAI_TryStartNpcInteraction(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract, char nQuestFlags, D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;

    if (SUNIT_GetInteractUnit(pGame, pUnit))
    {
        return 0;
    }

    if (!pTarget || !pTarget->dwAnimMode || pTarget->dwAnimMode == 0xC || PLAYER_IsBusy(pUnit) == 1)
    {
        return 0;
    }

// build: symbol ?MONSTERUNIQUE_CheckMonStatsFlag@* 0x00457490
    if (!MONSTERUNIQUE_CheckMonStatsFlag(pTarget->dwClassId, 9))
    {
        return 1;
    }

    if (pTarget->dwClassId == 0x92 && ACT1Q4_IsCainInTristramDeactivated(pGame))
    {
        return 0;
    }

    for (; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pUnit)
        {
            return 1;
        }
    }

    D2ClientStrc* pClient = UnitGetClient(pUnit, gszMonsterAISourceFile, 0x1C4);
    D2InteractInfoStrc* pNewInteractInfo = (D2InteractInfoStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2InteractInfoStrc), gszMonsterAISourceFile, 0x1C7, 0);
    pNewInteractInfo->pUnit = pUnit;

    D2InteractInfoStrc* pFirstInteractInfo = pMonInteract->pInteractInfo;
    int bNoInteractInfo;
    if (!pFirstInteractInfo)
    {
        bNoInteractInfo = 1;
        pNewInteractInfo->pNext = pFirstInteractInfo;
    }
    else
    {
        bNoInteractInfo = 0;
        pNewInteractInfo->pNext = pFirstInteractInfo;
    }

    pMonInteract->pInteractInfo = pNewInteractInfo;

    D2GAME_NPC_BuildHirelingList_6FCC6FF0(CLIENTS_GetGame(pClient), pClient, pTarget, bNoInteractInfo);
    SUNIT_SetInteractInfo(pUnit, 1, !pTarget ? -1 : pTarget->dwUnitId);
    pNewInteractInfo->nInteract = 0;

    const D2GameStrc* pGame_v157 = pGame;
    D2TextHeaderStrc* pTextHeader = TEXT_AllocTextHeader(pGame_v157->pMemoryPool);
    QUESTS_NPCActivate(pClient, pUnit, pTarget, pTextHeader);

    D2GSPacketSrv27 packet27;
    memcpy(&packet27.dwUnitGUID, &pTarget->dwUnitId, sizeof(pTarget->dwUnitId));
    packet27.nHeader = 0x27;
    int nValue;
    if (!pTarget)
        nValue = 6;
    else
        nValue = pTarget->dwUnitType;
    packet27.nUnitType = nValue;
    TEXT_CreateMessageListFromTextHeader(pTextHeader, &packet27.messageList);
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
    TEXT_FreeTextHeader(pTextHeader);

    QUESTS_SendCurrentFlags(pGame, pClient);
    const int nTargetGUID = !pTarget ? -1 : pTarget->dwUnitId;
    D2GAME_SendPacket0x28_6FC3F2F0(pClient, 0x28, 1, nTargetGUID, sub_00543520(pGame, pUnit), nQuestFlags);
    return 0;
}

// 0x00572DA0
extern "C" __declspec(dllexport) int __fastcall MONSTERAI_GetInteractUnitCount(List00572DA0* pList) {
    int nCount = 0;
    for (Node00572DA0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->dwValue00) {
            nCount++;
        }
    }
    return nCount;
}

// 0x00572DC0
extern "C" __declspec(dllexport) int __fastcall MONSTERAI_HasInteractUnit(List00572DC0* pList) {
    for (Node00572DC0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->dwValue00) {
            return 1;
        }
    }
    return 0;
}

// 0x00572DE0
extern "C" __declspec(dllexport) int __fastcall MONSTERAI_IsInteractingWith(List00572DE0* pList, int nId) {
    for (Node00572DE0* pNode = pList->pHead; pNode; pNode = pNode->pNext) {
        if (pNode->nId == nId) {
            return 1;
        }
    }
    return 0;
}

// 0x00572E00
void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract)
{
    if (!pMonInteract)
    {
        return;
    }

    D2InteractInfoStrc* pPrevious = 0;
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pMonster)
        {
            if (pInteractInfo == pMonInteract->pInteractInfo)
            {
                pMonInteract->pInteractInfo = pInteractInfo->pNext;
            }
            else
            {
                pPrevious->pNext = pInteractInfo->pNext;
            }
            FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 553, 0);
            return;
        }

        pPrevious = pInteractInfo;
    }
}

// 0x00572E60
void __fastcall MONSTERAI_ActivateNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract)
{
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pUnit)
        {
            if (!pInteractInfo->nInteract)
            {
                pInteractInfo->nInteract = 1;
                D2GAME_NPC_Heal_6FCCB220(pGame, pUnit, pNpc);
            }
            return;
        }
    }
}

static inline int GetUnitType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

inline D2MonsterInteractStrc* GetInteractions(D2UnitStrc* pUnit)
{
    if (GetUnitType(pUnit) == 1)
    {
        D2MonsterDataStrc* pData = pUnit->pMonsterData;
        return !pData ? 0 : pData->pMonInteract;
    }
    return 0;
}

// 0x00572EA0
void __fastcall MONSTERAI_SetInteractTrading(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2MonsterInteractStrc* pList = GetInteractions(pUnit);
    D2InteractInfoStrc* pEntry = pList->pInteractInfo;
    while (pEntry)
    {
        if (pEntry->pUnit == pTarget)
        {
            if (pEntry->nInteract == 1)
                pEntry->nInteract = 2;
            return;
        }
        pEntry = pEntry->pNext;
    }
}

// 0x00572EE0
int __fastcall MONSTERAI_IsTrading(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2MonsterInteractStrc* pList = GetInteractions(pUnit);
    D2InteractInfoStrc* pEntry = pList->pInteractInfo;
    while (pEntry)
    {
        if (pEntry->pUnit == pTarget)
            return pEntry->nInteract == 2;
        pEntry = pEntry->pNext;
    }
    return 0;
}

// 0x00572F20
void __fastcall MONSTERAI_EndNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract)
{
    QUESTS_NPCDeactivate(pGame, pPlayer, pNpc);

    D2InteractInfoStrc* pPrevious = 0;
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pPlayer)
        {
            if (pInteractInfo->nInteract >= 1)
            {
                if (!pPrevious)
                {
                    pMonInteract->pInteractInfo = pInteractInfo->pNext;
                }
                else
                {
                    pPrevious->pNext = pInteractInfo->pNext;
                }

                int nUnitType;
                int nUnitGUID;
                if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 1)
                {
                    SUNIT_ResetInteractInfo(pPlayer);
                }

                FOG_FreePool(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 651, 0);
                if (!pMonInteract->pInteractInfo)
                {
                    SUNITPROXY_FreeNpcGamble(pGame, pNpc, pPlayer);
                }
                return;
            }

            if (pInteractInfo->nInteract == 0)
            {
                if (!pPrevious)
                {
                    pMonInteract->pInteractInfo = pInteractInfo->pNext;
                }
                else
                {
                    pPrevious->pNext = pInteractInfo->pNext;
                }

                int nUnitType;
                int nUnitGUID;
                if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 1)
                {
                    SUNIT_ResetInteractInfo(pPlayer);
                }

                FOG_FreePool(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 686, 0);
                return;
            }
        }

        pPrevious = pInteractInfo;
    }
}

// 0x00573020
void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags)
{
    MONSTERAI_TryStartNpcInteraction(pGame, pMonInteract, nQuestFlags, pTarget, pUnit);
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline unsigned int MONSTERS_CheckMonStatsFlag(D2MonStatsTxt* pMonStatsTxtRecord, int nFlag)
{
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static inline D2MonsterDataStrc* MONSTERS_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x00573040
static int MONSTERAI_CanSwitchAi(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        if (MONSTERS_CheckMonStatsFlag(DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId), MONSTATSFLAGINDEX_SWITCHAI))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00573090
int __fastcall MONSTERAI_SetTargetOverride(D2UnitStrc* pUnit, int nState, int nValue)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && nState < 5 && MONSTERAI_CanSwitchAi(pUnit))
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterData(pUnit);
        if (pMonsterData)
        {
            pMonsterData->nAiState = nState;
            pMonsterData->nAiValue = nValue;
            return 1;
        }
    }
    return 0;
}

static inline D2MonsterDataStrc* MONSTERS_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005730E0
int __fastcall MONSTERAI_GetTargetOverrideType(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            return pMonsterData->nAiState;
        }
    }

    return 0;
}

// 0x00573100
int __fastcall MONSTERAI_GetTargetOverrideGUID(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            return pMonsterData->nAiValue;
        }
    }

    return 0;
}

// 0x00573120
void __fastcall MONSTERAI_ClearTargetOverride(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pUnit);
        if (pMonsterData)
        {
            pMonsterData->nAiState = 0;
            pMonsterData->nAiValue = 0;
        }
    }
}

static inline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecordFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
    }

    return 0;
}

// 0x00573140
int __fastcall MONSTERAI_IsInteractionReady(D2UnitStrc* pNpc, D2UnitStrc* pPlayer)
{
    if (!pNpc)
    {
        return 0;
    }

    const int nUnitType = pNpc ? pNpc->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonsterDataStrc* pMonsterData = MONSTERS_GetMonsterDataInline(pNpc);
    if (!pMonsterData)
    {
        return 0;
    }

    if (!pMonsterData->pMonInteract)
    {
        return 0;
    }

    for (D2InteractInfoStrc* pInteractInfo = pMonsterData->pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pPlayer)
        {
            return pInteractInfo->nInteract >= 1;
        }
    }

    return 1;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline void MONSTER_SetComponent(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    if (sub_0044BE50(pUnit) == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nComponent[nComponent] = nValue;
        }
    }
}

// 0x00573270
void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nSaveVersion, D2MercDataStrc* pMercData, int bDead)
{
    if (!pPlayer || !pUnit || !pMercData || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    pUnit->dwFlags |= 0x4020200;

    SUNIT_SetAlignment(pUnit, 2, 0);

    if (!bDead)
    {
        D2GAME_UpdateSummonAI_6FC401F0(pGame, pUnit, 0, pPlayer->dwNodeIndex);
    }

    D2UnitStrc* pPet = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 1);
    if (pPet)
    {
        D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszMonsterAISourceFile, 0x52), 0xFFFF, 0);

        AIGENERAL_SetOwnerData(pGame, pPet, -1, 1, 0, 0);
        PLAYERPETS_RemovePet(pGame, pPlayer, UNITS_GetUnitId(pPet), 0);
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPet), 1, UNITS_GetUnitId(pPet));
        SUNIT_RemoveUnit(pGame, pPet);
    }

    D2HirelingInitStrc hirelingInit;
    D2PetInfoStrc petInfo;
    petInfo.nSeed = pMercData->dwSeed;
    petInfo.nName = pMercData->nMercName;
    const int nAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, pMercData->nMercName);
    const int nDifficulty = pGame->nDifficulty;
    if (!MONSTERS_HirelingInit(pGame->bExpansion, pPlayer, pMercData->dwSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    petInfo.nHirelingId = hirelingInit.nId;
    PLAYERPETS_AddPetWithInfo(pGame, pPlayer, pUnit, 7, &petInfo);

    pUnit->dwFlags |= 0x80000000;
    AIGENERAL_SetOwnerData(pGame, pUnit, pPlayer->dwUnitId, sub_0044BE50(pPlayer), 0, 0);

    if (nSaveVersion == 0xFFFF)
    {
        const int nLevel = hirelingInit.nLevel;
        const int nHirelingId = (unsigned short)hirelingInit.nId;
        if (!DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, hirelingInit.nLevel))
        {
            return;
        }

        STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, hirelingInit.nExperience, 0);
        MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pUnit, nLevel);
        MONSTERAI_SendMercStats(pGame, pPlayer, 1);
    }

    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x13, 0);

    MONSTER_SetComponent(pUnit, 0, 0);
    MONSTER_SetComponent(pUnit, 5, 0);
    MONSTER_SetComponent(pUnit, 6, 0);
    MONSTER_SetComponent(pUnit, 7, 0);
    MONSTER_SetComponent(pUnit, 1, 0);
}

// 0x00573180
void __fastcall MONSTERAI_CloseNpcInteractions(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide)
{
    if (!pMonster)
    {
        return;
    }

    const int nType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    if (!pMonster->pMonsterData)
    {
        return;
    }

    D2MonsterInteractStrc* pMonInteract = pMonster->pMonsterData->pMonInteract;
    if (!pMonInteract)
    {
        return;
    }

    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;
    while (pInteractInfo)
    {
        D2InteractInfoStrc* pNext = pInteractInfo->pNext;
        SCMD_SendInteractionTarget(UnitGetClient(pInteractInfo->pUnit, ".\\MONSTER\\MonsterAI.cpp", 860), 0x62, UNIT_MONSTER, GAME_GetUnitGUID(pMonster), 0);

        int nInteractType;
        int nInteractGUID;
        if (!bClientSide || (SUNIT_GetInteractInfo(pInteractInfo->pUnit, &nInteractType, &nInteractGUID) && nInteractType == UNIT_MONSTER && nInteractGUID == GAME_GetUnitGUID(pMonster)))
        {
            SUNIT_ResetInteractInfo(pInteractInfo->pUnit);
        }

        if (pCallback)
        {
            pCallback(pInteractInfo->pUnit);
        }

        FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 875, 0);
        pInteractInfo = pNext;
    }

    pMonInteract->pInteractInfo = 0;
}

