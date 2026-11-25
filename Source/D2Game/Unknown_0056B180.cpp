#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"
#include "D2Txt.h"
#include "D2SaveHeader.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x007320C0

#define STAT_HITPOINTS 6
#define STAT_MANA 8
struct D2PlayerDataStrc;
struct D2SaveHeaderStrc;



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gnPlrSave2ErrorRemap[PLRSAVE2ERROR_COUNT]; // 0x006E1208
int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient); // 0x005385F0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
void __fastcall PLRSAVE2_InitPlayerFromClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient); // 0x00569F20
void __fastcall sub_005385D0(D2ClientStrc* pClient, int a2, int a3); // 0x005385D0
void __fastcall SUNITMSG_SendUnitToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0
void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct); // 0x005706D0
void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char nAct); // 0x00534F10
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0
void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3); // 0x00546270
int __fastcall PLRSAVE2_ReadSaveHeader(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char** ppSection, unsigned char* pEnd, D2UnitStrc** ppPlayer); // 0x0056A090
int __fastcall PLRSAVE2_ReadQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A370
int __fastcall PLRSAVE2_ReadWaypointData(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A3E0
int __fastcall PLRSAVE2_ReadStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nStats); // 0x0056A620
int __fastcall PLRSAVE2_ReadSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nSkills); // 0x0056A710
int __fastcall PLRSAVE2_ReadItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError); // 0x0056A7E0
int __fastcall PLRSAVE2_ReadCorpses(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int* a6); // 0x0056A830
int __fastcall PLRSAVE2_ReadPetSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion, int* a6); // 0x0056AC10
void __fastcall MONSTERAI_SendMercStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3); // 0x005726C0
int __fastcall PLRSAVE2_ReadIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion); // 0x0056AE50
void __fastcall PLRSAVE2_InitializeStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nHitpoints, int nMana); // 0x0056AF80
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x005378E0


typedef char M195_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];

typedef char M195_CheckUnitMode[(int)&((D2UnitStrc*)0)->dwAnimMode == 0x10 ? 1 : -1];

typedef char M195_CheckMonStatsFlags[(int)&((D2MonStatsTxt*)0)->nMonStatsFlags == 0x0C ? 1 : -1];

typedef char M195_CheckMissilesFlags[(int)&((D2MissilesTxt*)0)->nMissileFlags == 0x04 ? 1 : -1];

enum
{
    UNITFLAG_CANBEATTACKED = 0x00000004,
    UNITFLAG_ISVALIDTARGET = 0x00000008,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus); // 0x00622C40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
int __fastcall sub_00554200(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00554DE0

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// build: symbol ?PLRSAVE2_CreateNewbiePlayer@* 0x00569F80
static int __stdcall PLRSAVE2_CreateNewbiePlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer)
{
    sub_6FC32220(pClient);
    const int nClassId = CLIENTS_GetClassId(pClient);
    D2UnitStrc* pPlayer = SUNIT_AllocUnitData(UNIT_PLAYER, nClassId, 0, 0, pGame, 0, 0, 0, 0);
    PLRSAVE2_InitPlayerFromClient(pGame, pPlayer, pClient);
    sub_005385D0(pClient, 0, 1);
    SUNITMSG_SendUnitToClient(pGame, pPlayer, pClient);

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    PLAYERSTATS_SetStatsForStartingAct(pGame, pPlayer, nAct);
    PLAYER_CreateStartItemsFromCharStatsTxt(pPlayer, pGame, nAct);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = 0;
    pPlayerData->nRightSkillId = 0;

    if (nAct == ACT_I && pPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
        if (pCharStatsTxtRecord && pCharStatsTxtRecord->wStartSkill && SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, pCharStatsTxtRecord->wStartSkill))
        {
            D2GAME_AssignSkill_6FD13800(pPlayer, 0, pCharStatsTxtRecord->wStartSkill, -1);
            pPlayerData->nRightSkillId = pCharStatsTxtRecord->wStartSkill;
        }
    }

    QUESTS_SequenceCycler(pGame, pPlayer, 1);
    *ppPlayer = pPlayer;
    return 0;
}

// 0x0056B180
int __fastcall PlayerCreate(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    D2SaveHeaderStrc* pSaveHeader = (D2SaveHeaderStrc*)pSaveFile;
    unsigned char* pSection = pSaveFile;
    unsigned char* pSaveFileEnd = &pSaveFile[nSize];
    D2UnitStrc* pPlayer = 0;
    int nHitpoints;
    int nMana;
    int nErrorCode;
    int bLoaded = 0;

    *ppPlayer = 0;

    if (!pClient)
    {
        nErrorCode = PLRSAVE2ERROR_NO_CLIENT;
    }
    else
    {
        nErrorCode = PLRSAVE2_ReadSaveHeader(pGame, pClient, &pSection, pSaveFileEnd, ppPlayer);
        if (nErrorCode)
        {
            if (nErrorCode == PLRSAVE2ERROR_NEWBIE_SAVE && pSection == pSaveFileEnd)
            {
                return PLRSAVE2_CreateNewbiePlayer(pGame, pClient, ppPlayer);
            }
        }
        else
        {
            pPlayer = *ppPlayer;
            const unsigned int nVersion = pSaveHeader->dwVersion;
            nErrorCode = PLRSAVE2_ReadQuestSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
            if (!nErrorCode)
            {
                nErrorCode = PLRSAVE2_ReadWaypointData(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                if (!nErrorCode)
                {
                    nErrorCode = sub_0056A470_ReadPlrIntroSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                    if (!nErrorCode)
                    {
                        nErrorCode = PLRSAVE2_ReadStats(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, pSaveHeader->nStats);
                        if (!nErrorCode)
                        {
                            nHitpoints = STATLIST_UnitGetStatValue(pPlayer, STAT_HITPOINTS, 0);
                            nMana = STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0);

                            nErrorCode = PLRSAVE2_ReadSkills(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, pSaveHeader->nSkills);
                            if (!nErrorCode)
                            {
                                int nItemSize;
                                nErrorCode = PLRSAVE2_ReadItemSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, 0, &nItemSize);
                                if (!nErrorCode)
                                {
                                    nErrorCode = PLRSAVE2_ReadCorpses(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, &nItemSize);
                                    if (!nErrorCode)
                                    {
                                        D2UnitStrc* pMerc = PLRSAVE2_ReadMercData(pGame, pPlayer, pSaveHeader->MercSaveData, nVersion);
                                        nErrorCode = PLRSAVE2_ReadPetSection(pGame, pPlayer, pMerc, &pSection, pSaveFileEnd, nVersion, &nItemSize);
                                        if (!nErrorCode)
                                        {
                                            if (pMerc)
                                            {
                                                MONSTERAI_SendMercStats(pGame, pPlayer, 1);
                                            }

                                            nErrorCode = PLRSAVE2_ReadIronGolemSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                                            if (!nErrorCode)
                                            {
                                                bLoaded = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!bLoaded)
    {
        if (nErrorCode < 0 || nErrorCode >= PLRSAVE2ERROR_COUNT)
        {
            nErrorCode = PLRSAVE2ERROR_UNKNOWN;
        }

        if (pPlayer)
        {
            if (UNITS_GetRoom(pPlayer))
            {
                const int nUnitGUID = pPlayer->dwUnitId;
                const int nUnitType = pPlayer->dwUnitType;
                DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPlayer), nUnitType, nUnitGUID);
            }

            SUNIT_RemoveUnit(pGame, pPlayer);
        }

        CLIENTS_SetPlayerInClient(pClient, 0);
        return gnPlrSave2ErrorRemap[nErrorCode];
    }

    PLRSAVE2_InitializeStats(pGame, pPlayer, nHitpoints, nMana);
    return 0;
}

#include "gen/data/Source/D2Game/Unknown_0056B180.inc"
struct D2SkillStrc;
struct D2UnitStrc;

static __forceinline int UNIT_HasFlag_M195(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056B3E0
int __fastcall SKILLS_CheckAuraTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nAuraFilter)
{
    D2UnitStrc* pAttacker = pUnit;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;

    switch (nType)
    {
    case 0:
    {
        if (!(nAuraFilter & 1))
        {
            return 0;
        }

        const int nMode = pTarget->dwAnimMode;
        if (nAuraFilter & 0x1000)
        {
            if (nMode != 0x11)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x11 || nMode == 0)
            {
                return 0;
            }
        }
        break;
    }
    case 1:
    {
        if (!(nAuraFilter & 2))
        {
            return 0;
        }

        const int nMode = pTarget->dwAnimMode;
        if (nAuraFilter & 0x1000)
        {
            if (nMode != 0x0C)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x0C || nMode == 0)
            {
                return 0;
            }
        }

        if (nAuraFilter & 4 && !MONSTERS_IsUndead(pTarget) || nAuraFilter & 0x4000 && MONSTERS_IsBoss(0, pTarget) || nAuraFilter & 0x40000 && MONSTERS_IsPrimeEvil(pTarget))
        {
            return 0;
        }
        break;
    }
    case 2:
    {
        if (!(nAuraFilter & 0x10))
        {
            return 0;
        }
        break;
    }
    case 3:
    {
        if (!(nAuraFilter & 8))
        {
            return 0;
        }

        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pTarget->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[0] & gdwBitMasks[1])
        {
            return 0;
        }
        break;
    }
    case 4:
    {
        if (!(nAuraFilter & 0x20))
        {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }

    if (nAuraFilter & 0x80 && !UNIT_HasFlag_M195(pTarget, UNITFLAG_CANBEATTACKED))
    {
        return 0;
    }

    if (nAuraFilter & 0x400 && !UNIT_HasFlag_M195(pTarget, UNITFLAG_ISVALIDTARGET))
    {
        return 0;
    }

    if (nAuraFilter & 0x100 && DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    if (nAuraFilter & 0x10000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!SUNIT_AreUnitsAligned(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pTarget))
        {
            return 0;
        }

        if (pTarget->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
            if (!pMonStatsTxtRecord || pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
            {
                return 0;
            }
        }
    }

    if (nAuraFilter & 0x8000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!sub_00554200(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pTarget))
        {
            return 0;
        }
    }

    if (nAuraFilter & 0x20000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!UNITS_IsInMeleeRange(pAttacker, pTarget, 0))
        {
            return 0;
        }
    }

    if (nAuraFilter & 0x80000 && STATES_CheckState(pTarget, STATE_JUSTHIT))
    {
        return 0;
    }

    if (nAuraFilter & 0x200)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pAttacker);
        if (!pRoom || !UNITS_GetRoom(pTarget))
        {
            return 0;
        }

        D2CoordStrc coords;
        coords.nX = CLIENTS_GetUnitX(pAttacker);
        coords.nY = CLIENTS_GetUnitY(pAttacker);

        D2CoordStrc targetCoords;
        targetCoords.nX = CLIENTS_GetUnitX(pTarget);
        targetCoords.nY = CLIENTS_GetUnitY(pTarget);

        if (COLLISION_RayTrace(pRoom, &coords, &targetCoords, 4))
        {
            return 0;
        }
    }

    return 1;
}
