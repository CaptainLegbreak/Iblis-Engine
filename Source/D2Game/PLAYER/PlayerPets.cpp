#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2LevelTxt.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x007328C8

#define PETTYPE_SINGLE 1

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_MONSTER 1

struct D2PetDataStrc;

struct D2PetUpdateStrc;

struct D2PetListStrc;

struct D2PlayerPetStrc;

struct D2PlayerDataStrc;

struct D2PetArgStrc;

struct D2StaticPathStrc;

struct D2ModeChangeStrc;

struct D2PetInfoStrc;

struct D2PetTypeTxt;

struct D2MonStatsTxt;

struct D2PetUpdateStrc
{
    int nUnitId;
    int nClassId;
    unsigned short nPetType;
    unsigned short unk_0A;
    int nParam;
};

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x7A_6FC3E100(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass); // 0x0053CB30

extern const char gszPlayerPetsSourceFile[]; // 0x006E15D8

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int bKillPet); // 0x005750E0

static int PLAYERPETS_GetFirstPetGUID(D2UnitStrc* pPlayer, int nPetType);

void __fastcall D2GAME_PACKETS_SendPacket0x81_6FC3E160(D2ClientStrc* pClient, char a2, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass, int nSeed, int nName); // 0x0053CB80

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

extern const unsigned int gdwBitMasks[]; // 0x006CE268

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3); // 0x0053E0E0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

void __fastcall SUNIT_SynchronizeRoomClients(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

void __fastcall PLAYERPETS_PlayerIterate_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x00574410

void __fastcall PLAYERPETS_PlayerIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x00574930

int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID); // 0x00574A20

void __fastcall PLAYERPETS_SetPetLimit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax); // 0x00575850

void __fastcall PLAYERPETS_UpdatePetLimits(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575900

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2); // 0x00620FA0

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling); // 0x006637B0

D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);

struct D2UnitStrc;

#define UNIT_PLAYER 0

struct D2SkillListStrc;

struct D2SkillsTxt;

extern "C" D2PetTypeTxt* __fastcall sub_00478A20_GetPetTypeTxtRecord(int nPetType);

D2SkillStrc* __stdcall SKILLS_GetNextSkill(D2SkillStrc* pSkill); // 0x006438F0

D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList); // 0x00643910

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

struct D2ClientStrc;

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __fastcall GAME_GetUnitGUID(D2UnitStrc*); // 0x00451F50

typedef int (__stdcall* FARPROC)();

typedef void(__fastcall* PetCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005746D0

void __fastcall PLAYERPETS_InitPetTypeMax(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575A80

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053CDF0

#define PETFLAG_DEAD 1


static void __stdcall PLAYERPETS_RemovePetFromList(D2PetListStrc* pPetList, int bKillPet, D2GameStrc* pGame, int nUnitGUID);

static void PLAYERPETS_KillPet(D2GameStrc* pGame, int nPetGUID);

static D2PetListStrc* __stdcall PLAYERPETS_GetPetListByType(D2PlayerPetStrc* pPlayerPets, int nPetType);

static void __stdcall PLAYERPETS_ClearPetList(D2UnitStrc* pPlayer, D2PetListStrc* pPetList, int bIsHirelingList, int bKeepHireling, D2GameStrc* pGame);

void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005746D0


static void __stdcall PLAYERPETS_KillPetList(D2PetListStrc* pPetList, D2GameStrc* pGame);

static void __stdcall PLAYERPETS_RelocatePet(D2GameStrc* pGame, D2UnitStrc* pPet, D2ActiveRoomStrc* pRoom, int nX, int nY);

static void __stdcall PLAYERPETS_RelocatePetList(D2GameStrc* pGame, D2PetListStrc* pPetList, D2ActiveRoomStrc* pRoom, int nX, int nY);

static void __stdcall PLAYERPETS_RemoveDistantPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMaxDistance, D2PetListStrc* pPetList);

void __fastcall PLAYERPETS_UpdatePetsForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nX, int nY);

static void __stdcall PLAYERPETS_RemoveGroupPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType);

void __fastcall D2GAME_KillPlayerPets(D2GameStrc* pGame, D2UnitStrc* pPlayer);


void __fastcall PLAYERPETS_AddSummonedPet(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, int nPetMax);

void __fastcall PLAYERPETS_AddPetWithInfo(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, D2PetInfoStrc* pPetInfo);

// 0x00574570
static void __stdcall PLAYERPETS_ClearPetList(D2UnitStrc* pPlayer, D2PetListStrc* pPetList, int bIsHirelingList, int bKeepHireling, D2GameStrc* pGame)
{
    D2PetArgStrc arg;
    D2ModeChangeStrc modeChange;
    D2PetDataStrc* pPetData = pPetList->pPetData;
    while (pPetData)
    {
        D2PetDataStrc* pNext = pPetData->pNext;
        if (bIsHirelingList)
        {
            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet)
            {
                memset(&arg, 0, sizeof(arg));
                arg.nPetGUID = pPetData->nUnitGUID;
                SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
                DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPet), 1, !pPet ? -1 : pPet->dwUnitId);

                if (!bKeepHireling)
                {
                    SUNIT_RemoveUnit(pGame, pPet);
                }
                else if (!(pPetData->nFlags & 1))
                {
                    pPetData->nFlags |= 1;
                    pPetList->pPetData = pPetData;
                    if (UNITS_GetRoom(pPet))
                    {
                        MONSTERMODE_GetModeChangeInfo(pPet, 0, &modeChange);
                        modeChange.pTargetUnit = SUNIT_GetOwner(pGame, pPet);
                        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
                    }

                    D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 0xDB), (unsigned short)pPetData->petInfo.nName, MONSTERS_GetHirelingResurrectionCost(pPet));
                }
            }
        }
        else
        {
            PLAYERPETS_KillPet(pGame, pPetData->nUnitGUID);
        }

        if (!bIsHirelingList || !bKeepHireling)
        {
            --pPetList->nCurrent;
            --pPetList->nMax;
            FOG_FreeServerMemory(pGame->pMemoryPool, pPetData, gszPlayerPetsSourceFile, 0xE8, 0);
        }

        pPetData = pNext;
    }

    if (!pPetList->nCurrent)
    {
        pPetList->pPetData = 0;
    }
}

static inline int sub_E09_UnitHasBeenDeleted(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 8) & 1;
}

static inline int sub_E09_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x00574410
void __fastcall PLAYERPETS_PlayerIterate_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2PetUpdateStrc* pData)
{
    D2GAME_PACKETS_SendPacket0x7A_6FC3E100(UnitGetClient(pUnit, gszPlayerPetsSourceFile, 0x43), 0, pData->nParam, pData->nUnitId, pData->nClassId, pData->nPetType);
}

// 0x00574450
static void PLAYERPETS_KillPet(D2GameStrc* pGame, int nPetGUID)
{
    D2UnitStrc* hPet = SUNIT_GetServerUnit(pGame, 1, nPetGUID);
    if (!hPet)
    {
        return;
    }

    D2_ASSERT(!sub_E09_UnitHasBeenDeleted(hPet), 0x5A);

    hPet->dwFlags |= 0x4000000;

    if (sub_E09_CheckMonStatsFlag(hPet->dwClassId, 15))
    {
        SUNITDMG_KillMonster(pGame, hPet, 0, 0);
    }
    else
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(hPet, 0, &modeChange);
        modeChange.pTargetUnit = SUNIT_GetOwner(pGame, hPet);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    }

    D2PetArgStrc arg = {};
    arg.nPetGUID = nPetGUID;
    SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
}

// 0x00574540
static D2PetListStrc* __stdcall PLAYERPETS_GetPetListByType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &pPlayerPets->pPetList[nPetType];
    }

    return 0;
}

// 0x00574850
static void __stdcall PLAYERPETS_RemovePetFromList(D2PetListStrc* pPetList, int bKillPet, D2GameStrc* pGame, int nUnitGUID)
{
    D2PetDataStrc* pPrevious = 0;
    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nUnitGUID)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pPetData->pNext;
            }
            else
            {
                pPetList->pPetData = pPetData->pNext;
            }

            D2PetArgStrc arg = {};
            arg.nPetGUID = nUnitGUID;
            SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);

            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet)
            {
                if (bKillPet)
                {
                    PLAYERPETS_KillPet(pGame, pPetData->nUnitGUID);
                }
                else
                {
                    pPet->dwFlags &= 0x7FFFFFFF;
                }
            }

            FOG_FreeServerMemory(pGame->pMemoryPool, pPetData, gszPlayerPetsSourceFile, 0x25C, 0);

            --pPetList->nCurrent;
            D2_ASSERT(pPetList->nCurrent >= 0, 0x260);
            return;
        }

        pPrevious = pPetData;
    }
}

inline D2PetListStrc* PLAYERPETS_GetPetListFromPetType(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return 0;
    }
    return &pPlayerPets->pPetList[nPetType];
}

// 0x005747B0
static int PLAYERPETS_GetFirstPetGUID(D2UnitStrc* pPlayer, int nPetType)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x171);

    if (!pPlayerData->pPlayerPets)
    {
        return -1;
    }

    D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerData->pPlayerPets, nPetType);
    if (!pPetList)
    {
        return -1;
    }

    if (!pPetList->pPetData)
    {
        return -1;
    }

    return pPetList->pPetData->nUnitGUID;
}

// 0x00574810
int __fastcall PLAYERPETS_GetPetMaxFromPetType(D2UnitStrc* pPlayer, int nPetType)
{
    int nMax = 0;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData && pPlayerData->pPlayerPets && nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        D2PetListStrc* pPetList = &pPlayerData->pPlayerPets->pPetList[nPetType];
        if (pPetList)
        {
            nMax = pPetList->nMax;
        }
    }
    return nMax;
}

// 0x00574930
void __fastcall PLAYERPETS_PlayerIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2PetArgStrc* pPetArg = (D2PetArgStrc*)pArg;

    if (!pPetArg->nSeed && !pPetArg->nName)
    {
        D2GAME_PACKETS_SendPacket0x7A_6FC3E100(UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 830), 1, pPetArg->nPetType, pPetArg->nPetGUID, pPetArg->nUnitGUID, pPetArg->nPetClass);
    }
    else
    {
        D2GAME_PACKETS_SendPacket0x81_6FC3E160(UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 837), 1, pPetArg->nPetType, pPetArg->nPetGUID, pPetArg->nUnitGUID, pPetArg->nPetClass, pPetArg->nSeed, pPetArg->nName);
    }
}

// 0x005749B0
void __fastcall PLAYERPETS_UpdatePetInfo(D2UnitStrc* pUnit, int nPetType, int nUnitGUID, D2PetInfoStrc* pPetInfo)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pUnit)->pPlayerPets;
    if (!pPlayerPets || nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    D2PetListStrc* pPetList = &pPlayerPets->pPetList[nPetType];
    if (!pPetList)
    {
        return;
    }

    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nUnitGUID)
        {
            pPetData->petInfo = *pPetInfo;
        }
    }
}

// 0x00574BD0
D2PetInfoStrc* __fastcall PLAYERPETS_GetPetInfoFromPetGUID(D2UnitStrc* pUnit, int nUnitGUID)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(pPlayerData, 1077);

    if (!pPlayerData->pPlayerPets)
    {
        return 0;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerData->pPlayerPets, nPetType);
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (pPetData->nUnitGUID == nUnitGUID)
                {
                    return &pPetData->petInfo;
                }
            }
        }
    }

    return 0;
}

// 0x00574C60
static void __stdcall PLAYERPETS_KillPetList(D2PetListStrc* pPetList, D2GameStrc* pGame)
{
    D2PetDataStrc* pPetData = pPetList->pPetData;
    while (pPetData)
    {
        D2PetDataStrc* pNext = pPetData->pNext;
        PLAYERPETS_KillPet(pGame, pPetData->nUnitGUID);
        FOG_FreeServerMemory(pGame->pMemoryPool, pPetData, gszPlayerPetsSourceFile, 0x4A5, 0);
        pPetData = pNext;
    }

    pPetList->pPetData = 0;
    pPetList->nCurrent = 0;
}

static inline D2PetListStrc* GetPetList(D2PlayerPetStrc* pPets, int nType, int nCount)
{
    if (nType >= 0 && nType < nCount)
        return &pPets->pPetList[nType];
    return 0;
}

static inline int GetUnitClassId(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwClassId;
}

static inline int GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return -1;
    return pUnit->dwUnitId;
}

// 0x00574AB0
int __fastcall PLAYERPETS_MarkPetAlive(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x402);
    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
        return 0;
    const int nPetTypes = sgptDataTables->nPetTypeTxtRecordCount;
    for (int nPetType = 1; nPetType < nPetTypes; ++nPetType)
    {
        D2PetListStrc* pPetList = GetPetList(pPlayerPets, nPetType, nPetTypes);
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (pPetData->nUnitGUID == GAME_GetUnitGUID(pPet))
                {
                    pPetData->nFlags &= ~1;
                    D2PetArgStrc arg = {};
                    arg.nPetType = nPetType;
                    arg.nPetGUID = pPetData->nUnitGUID;
                    arg.nPetClass = GetUnitClassId(pPet);
                    arg.nUnitGUID = GetUnitGUID(pPlayer);
                    arg.nSeed = pPetData->petInfo.nSeed;
                    arg.nName = pPetData->petInfo.nName;
                    SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_UpdateClient, &arg);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// 0x00574CC0
static void __stdcall PLAYERPETS_RelocatePet(D2GameStrc* pGame, D2UnitStrc* pPet, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2ActiveRoomStrc* pPetRoom = UNITS_GetRoom(pPet);
    if (pRoom)
    {
        if (pPet->nAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
        {
            sub_00650BE0_PlaceUnit(pPet->pDynamicPath, pPet, 0, 0, 0);
        }
    }

    sub_00650BE0_PlaceUnit(pPet->pDynamicPath, pPet, pRoom, nX, nY);

    if (pRoom != pPetRoom)
    {
        UNITS_SetCurrentRoomInvalid(pPet, 1);
        SUNIT_SynchronizeRoomClients(pGame, pPet, pPetRoom);
    }

    pPet->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPet)));
    pPet->pDrlgAct = pGame->pAct[pPet->nAct];
    UNITROOM_RefreshUnit(pPet);

    pPet->dwFlagEx |= 0x10000;
    UNITROOM_RefreshUnit(pPet);

    MONSTER_UpdateAiCallbackEvent(pGame, pPet);
    if (!MONSTERS_IsDead(pPet) && pPet->pDynamicPath)
    {
        PATH_SetFootprintCollisionMask(pPet->pDynamicPath, 0x100);
    }
}

static inline int sub_F05_UnitHasBeenDeleted(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 8) & 1;
}

static inline int sub_F05_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static inline int sub_F05_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline int sub_F05_GetClassId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

static inline D2PetListStrc* sub_F05_GetPetListInl(D2PlayerDataStrc* pPlayerData, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
        if (pPlayerPets)
        {
            return &pPlayerPets->pPetList[nPetType];
        }
    }
    return 0;
}

// 0x00575AF0
void __fastcall PLAYERPETS_AllocPetList(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 154);

    if (pPlayerData->pPlayerPets)
    {
        PLAYERPETS_FreePetsFromPlayerData(pGame, pPlayer);
    }

    D2PlayerPetStrc* pPlayerPets = (D2PlayerPetStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PlayerPetStrc), gszPlayerPetsSourceFile, 162, 0);
    pPlayerPets->pPetList = 0;
    pPlayerData->pPlayerPets = pPlayerPets;
    pPlayerPets->pPetList = (D2PetListStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PetListStrc) * sgptDataTables->nPetTypeTxtRecordCount, gszPlayerPetsSourceFile, 166, 0);
    memset(pPlayerPets->pPetList, 0, sizeof(D2PetListStrc) * sgptDataTables->nPetTypeTxtRecordCount);
    PLAYERPETS_InitPetTypeMax(pGame, pPlayer);
}

// 0x005746D0
void __fastcall PLAYERPETS_FreePetsFromPlayerData(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(pPlayerData, 0x14F);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListByType(pPlayerPets, nPetType);
        PLAYERPETS_ClearPetList(pUnit, pPetList, nPetType == 7, 0, pGame);
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerPets->pPetList, gszPlayerPetsSourceFile, 0x161, 0);
    FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerPets, gszPlayerPetsSourceFile, 0x162, 0);
    pPlayerData->pPlayerPets = 0;
}

// 0x00574D90
static void __stdcall PLAYERPETS_RelocatePetList(D2GameStrc* pGame, D2PetListStrc* pPetList, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (!(pPetData->nFlags & 1))
        {
            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet)
            {
                PLAYERPETS_RelocatePet(pGame, pPet, pRoom, nX, nY);
            }
        }
    }
}

// 0x00574DE0
void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetCallback pCallback, void* a4)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);

    D2_ASSERT(!IsBadCodePtr((FARPROC)pCallback), 1461);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (!(pPetData->nFlags & 1))
                {
                    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
                    if (pPet)
                    {
                        pCallback(pGame, pPlayer, pPet, a4);
                    }
                }
            }
        }
    }
}

static inline D2UnitStrc* sub_F05_GetFirstPetInl(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int bIncludeDead)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2PetListStrc* pPetList = sub_F05_GetPetListInl(pPlayerData, nPetType);
        if (pPetList)
        {
            D2PetDataStrc* pPetData;
            for (pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (bIncludeDead || !(pPetData->nFlags & 1))
                {
                    break;
                }
            }

            if (pPetData)
            {
                return SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            }
        }
    }

    return 0;
}

static inline D2PetListStrc* sub_00574EC0_GetPetList(D2PlayerDataStrc* pPlayerData, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
        if (pPlayerPets)
        {
            return &pPlayerPets->pPetList[nPetType];
        }
    }
    return 0;
}

// 0x00575A80
void __fastcall PLAYERPETS_InitPetTypeMax(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    for (int nPetType = 0; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetTypeTxt* pPetTypeTxtRecord = 0;
        if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
        {
            pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
        }

        if (pPetTypeTxtRecord)
        {
            PLAYERPETS_SetPetLimit(pGame, pPlayer, nPetType, pPetTypeTxtRecord->wBaseMax);
        }
    }
}

// 0x00575BC0
void __fastcall D2GAME_KillPlayerPets(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x12F);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListByType(pPlayerPets, nPetType);
        PLAYERPETS_ClearPetList(pPlayer, pPetList, nPetType == 7, nPetType == 7, pGame);
    }

    PLAYERPETS_UpdatePetLimits(pGame, pPlayer);
}

// 0x00575C70
static int __stdcall PLAYERPETS_AppendPet(D2UnitStrc* pPet, D2PetInfoStrc* pPetInfo, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2PetListStrc* ptPet)
{
    if (!ptPet->nMax)
    {
        PLAYERPETS_UpdatePetLimits(pGame, pPlayer);
        if (!ptPet->nMax)
        {
            PLAYERPETS_KillPet(pGame, sub_F05_GetUnitId(pPet));
            return 0;
        }
    }

    if (ptPet->nCurrent == ptPet->nMax)
    {
        D2_ASSERT(ptPet->pPetData, 0x312);

        PLAYERPETS_RemovePetFromList(ptPet, 1, pGame, ptPet->pPetData->nUnitGUID);
        D2_ASSERT(ptPet->nCurrent != ptPet->nMax, 0x316);
    }

    D2PetDataStrc* pPrevious = ptPet->pPetData;
    if (pPrevious)
    {
        while (pPrevious->pNext)
        {
            pPrevious = pPrevious->pNext;
        }
    }

    D2PetDataStrc* pPetData = (D2PetDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PetDataStrc), gszPlayerPetsSourceFile, 0x322, 0);
    memset(pPetData, 0, sizeof(D2PetDataStrc));

    pPetData->nUnitGUID = sub_F05_GetUnitId(pPet);

    pPetData->petInfo = *pPetInfo;

    if (pPrevious)
    {
        pPrevious->pNext = pPetData;
    }
    else
    {
        ptPet->pPetData = pPetData;
    }

    ++ptPet->nCurrent;
    D2_ASSERT(ptPet->nCurrent <= ptPet->nMax, 0x330);
    return 1;
}

// 0x005751A0
void __fastcall PLAYERPETS_HandlePetDeath(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 672);

    const int nPetGUID = !pPet ? -1 : pPet->dwUnitId;

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    const int nPetType = PLAYERPETS_GetPetTypeFromPetGUID(pPlayer, nPetGUID);

    if (nPetType != PETTYPE_HIREABLE)
    {
        PLAYERPETS_RemovePet(pGame, pPlayer, nPetGUID, 0);
    }

    D2PetListStrc* pPetList = PLAYERPETS_GetPetListByType(pPlayerPets, nPetType);
    if (!pPetList)
    {
        return;
    }

    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nPetGUID)
        {
            pPetData->nFlags |= PETFLAG_DEAD;
            D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 698), pPetData->petInfo.nName, MONSTERS_GetHirelingResurrectionCost(pPet));
            break;
        }
    }

    D2PetArgStrc arg = {};
    arg.nPetGUID = nPetGUID;
    SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
}

// 0x00575380
static void __stdcall PLAYERPETS_RemoveDistantPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMaxDistance, D2PetListStrc* pPetList)
{
    D2PetDataStrc* pPetData = pPetList->pPetData;
    while (pPetData)
    {
        D2PetDataStrc* pNext = pPetData->pNext;
        if (!(pPetData->nFlags & 1))
        {
            D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
            if (pPet && PATH_ComputeSquaredDistance(sub_F05_GetUnitX(pPlayer), sub_F05_GetUnitY(pPlayer), sub_F05_GetUnitX(pPet), sub_F05_GetUnitY(pPet)) > nMaxDistance)
            {
                PLAYERPETS_RemovePet(pGame, pPlayer, pPetData->nUnitGUID, 1);
            }
        }

        pPetData = pNext;
    }
}

// 0x005754B0
void __fastcall PLAYERPETS_UpdatePetsForOwnerMove(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nX, int nY)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pPlayer)->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListByType(pPlayerPets, nPetType);
        if (pPetList)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
            if (pPetTypeTxtRecord)
            {
                if (pPetTypeTxtRecord->nPetFlags[0] & gdwBitMasks[0])
                {
                    PLAYERPETS_RelocatePetList(pGame, pPetList, pRoom, nX, nY);
                }
                else if (pPetTypeTxtRecord->nPetFlags[0] & gdwBitMasks[1])
                {
                    PLAYERPETS_RemoveDistantPets(pGame, pPlayer, 0x640, pPetList);
                }
                else
                {
                    PLAYERPETS_KillPetList(pPetList, pGame);
                }
            }
        }
    }
}

static inline D2PetListStrc* sub_005752B0_GetPetList(D2PlayerPetStrc* pPlayerPets, int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &pPlayerPets->pPetList[nPetType];
    }

    return 0;
}

// 0x005752B0
int __fastcall PLAYERPETS_HandlePetDeactivation(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 723);

    const int nPetGUID = !pPet ? -1 : pPet->dwUnitId;
    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return 0;
    }

    const int nPetType = PLAYERPETS_GetPetTypeFromPetGUID(pPlayer, nPetGUID);
    if (nPetType != PETTYPE_HIREABLE)
    {
        PLAYERPETS_RemovePet(pGame, pPlayer, nPetGUID, 0);
    }

    D2PetListStrc* pPetList = sub_005752B0_GetPetList(pPlayerPets, nPetType);
    if (!pPetList)
    {
        return 0;
    }

    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nPetGUID)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00575590
static void __stdcall PLAYERPETS_RemoveDeadPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2PlayerPetStrc* pPlayerPets)
{
    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList && nPetType != PETTYPE_HIREABLE)
        {
            D2PetDataStrc* pPetData = pPetList->pPetData;
            while (pPetData)
            {
                D2PetDataStrc* pNext = pPetData->pNext;
                D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
                if (!pPet || SUNIT_IsDead(pPet))
                {
                    PLAYERPETS_RemovePet(pGame, pPlayer, pPetData->nUnitGUID, 0);
                }
                pPetData = pNext;
            }
        }
    }
}

// 0x00575850
void __fastcall PLAYERPETS_SetPetLimit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int nBaseMax)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 512);

    if (nPetType == PETTYPE_SINGLE && nBaseMax != 1 || !pPlayerData->pPlayerPets)
    {
        return;
    }

    D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerData->pPlayerPets, nPetType);
    if (!pPetList)
    {
        return;
    }

    pPetList->nMax = nBaseMax;

    while (pPetList->nCurrent > nBaseMax && pPetList->nCurrent > 0 && nPetType != PETTYPE_HIREABLE)
    {
        PLAYERPETS_RemovePet(pGame, pPlayer, PLAYERPETS_GetFirstPetGUID(pPlayer, nPetType), 1);
    }
}

// 0x005750E0
void __fastcall PLAYERPETS_RemovePet(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetGUID, int bKillPet)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x276);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    const int nPetType = PLAYERPETS_GetPetTypeFromPetGUID(pPlayer, nPetGUID);
    if (nPetType == 0 && bKillPet)
    {
        PLAYERPETS_KillPet(pGame, nPetGUID);
    }

    D2PetListStrc* pPetList = PLAYERPETS_GetPetListByType(pPlayerPets, nPetType);
    if (pPetList)
    {
        PLAYERPETS_RemovePetFromList(pPetList, bKillPet, pGame, nPetGUID);

        D2PetArgStrc arg = {};
        arg.nPetGUID = nPetGUID;
        SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_SynchronizeWithClient, &arg);
    }
}

// 0x00574A20
int __fastcall PLAYERPETS_GetPetTypeFromPetGUID(D2UnitStrc* pPlayer, int nPetGUID)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 988);

    if (!pPlayerData->pPlayerPets)
    {
        return 0;
    }

    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerData->pPlayerPets, nPetType);
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (pPetData->nUnitGUID == nPetGUID)
                {
                    return nPetType;
                }
            }
        }
    }

    return 0;
}

// 0x00575630
void __fastcall PLAYERPETS_UpdatePetStates(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pPlayer)->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    PLAYERPETS_RemoveDeadPets(pGame, pPlayer, pPlayerPets);

    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszPlayerPetsSourceFile, 1411);
    for (int nPetType = 1; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, nPetType);
        if (pPetList)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
            if (pPetTypeTxtRecord && pPetTypeTxtRecord->nPetFlags[0] & gdwBitMasks[2])
            {
                for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
                {
                    if (!(pPetData->nFlags & 1))
                    {
                        D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
                        if (pPet)
                        {
                            sub_6FC3E200(pClient, pPet);
                        }
                    }
                }
            }
        }
    }
}

// 0x00575720
static void __stdcall PLAYERPETS_RemoveGroupPets(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2PetTypeTxt* pPetTypeTxtRecord = 0;
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        pPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nPetType];
    }

    if (!pPetTypeTxtRecord)
    {
        return;
    }

    const int nGroup = pPetTypeTxtRecord->wGroup;
    if (nGroup <= 0)
    {
        return;
    }

    for (int nOtherPetType = 0; nOtherPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nOtherPetType)
    {
        if (nOtherPetType != nPetType)
        {
            D2PetTypeTxt* pOtherPetTypeTxtRecord = 0;
            if (nOtherPetType >= 0 && nOtherPetType < sgptDataTables->nPetTypeTxtRecordCount)
            {
                pOtherPetTypeTxtRecord = &sgptDataTables->pPetTypeTxt[nOtherPetType];
            }

            if (pOtherPetTypeTxtRecord && pOtherPetTypeTxtRecord->wGroup == nGroup)
            {
                for (D2UnitStrc* pOtherPet = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, nOtherPetType, 1); pOtherPet; pOtherPet = sub_F05_GetFirstPetInl(pGame, pPlayer, nOtherPetType, 1))
                {
                    PLAYERPETS_RemovePet(pGame, pPlayer, sub_F05_GetUnitId(pOtherPet), 1);
                }
            }
        }
    }
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x00575900
void __fastcall PLAYERPETS_UpdatePetLimits(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData || !pPlayerData->pPlayerPets || !pPlayer->pSkills)
    {
        return;
    }

    int nPetCounters[256];
    memset(nPetCounters, 0, sizeof(nPetCounters));

    D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(pPlayer->pSkills);
    while (pSkill)
    {
        D2SkillStrc* pNextSkill = SKILLS_GetNextSkill(pSkill);

        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszPlayerPetsSourceFile, 1139);
        const int nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
        pSkill = pNextSkill;

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            if ((char)pSkillsTxtRecord->nPetType > 0 && (char)pSkillsTxtRecord->nPetType < sgptDataTables->nPetTypeTxtRecordCount)
            {
                int nPetMax = SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxtRecord->dwPetMax, nSkillId, nLevel);
                if (nPetMax < 1)
                {
                    nPetMax = 1;
                }

                if (nPetMax > nPetCounters[(char)pSkillsTxtRecord->nPetType])
                {
                    nPetCounters[(char)pSkillsTxtRecord->nPetType] = nPetMax;
                    PLAYERPETS_SetPetLimit(pGame, pPlayer, (char)pSkillsTxtRecord->nPetType, nPetMax);
                }
            }
        }
    }

    for (int nPetType = 0; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        if (nPetCounters[nPetType] <= 0)
        {
            D2PetTypeTxt* pPetTypeTxtRecord = sub_00478A20_GetPetTypeTxtRecord(nPetType);
            if (pPetTypeTxtRecord)
            {
                PLAYERPETS_SetPetLimit(pGame, pPlayer, nPetType, pPetTypeTxtRecord->wBaseMax);
            }
        }
    }
}

// 0x00574EC0
D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2PetListStrc* pPetList = sub_00574EC0_GetPetList(pPlayerData, nPetType);
        if (pPetList)
        {
            D2PetDataStrc* pPetData;
            for (pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (a4 || !(pPetData->nFlags & 1))
                {
                    break;
                }
            }

            if (pPetData)
            {
                return SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pPetData->nUnitGUID);
            }
        }
    }

    return 0;
}

// 0x00574F40
int __fastcall PLAYERPETS_GetTotalPetCount(D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    int nPets = 0;
    if (!pPlayerData)
    {
        return 0;
    }

    if (!pPlayerData->pPlayerPets)
    {
        return 0;
    }

    for (int i = 0; i < sgptDataTables->nPetTypeTxtRecordCount; ++i)
    {
        nPets += pPlayerData->pPlayerPets->pPetList[i].nCurrent;
    }

    return nPets;
}

// 0x00574F80
void __fastcall PLAYERPETS_SendPetsToClient(D2ClientStrc* pClient, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pPlayer);
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (!pPlayerData || !pGame || !pPlayerData->pPlayerPets)
        return;

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    for (int nPetType = 0; nPetType < sgptDataTables->nPetTypeTxtRecordCount; ++nPetType)
    {
        D2PetListStrc* pPetList = &pPlayerPets->pPetList[nPetType];
        if (pPetList)
        {
            for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
            {
                if (!(pPetData->nFlags & 1))
                {
                    D2UnitStrc* pPet = SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID);
                    if (pPet)
                    {
                        const int nClassId = pPet->dwClassId;
                        switch (nPetType)
                        {
                        case 7:
                            D2GAME_PACKETS_SendPacket0x81_6FC3E160(pClient, 1, 7, pPetData->nUnitGUID, nPlayerId, nClassId, pPetData->petInfo.nSeed, pPetData->petInfo.nName);
                            break;
                        default:
                            D2GAME_PACKETS_SendPacket0x7A_6FC3E100(pClient, 1, nPetType, pPetData->nUnitGUID, nPlayerId, nClassId);
                            break;
                        }
                    }
                }
            }
        }
    }
}

static inline int sub_I16_GetUnitIdRet(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static inline int sub_I16_GetClassIdRet(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x00575D90
void __fastcall PLAYERPETS_AddSummonedPet(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, int nPetMax)
{
    if ((!pPlayer ? 6 : pPlayer->dwUnitType) != 0)
    {
        return;
    }

    if (nPetType <= 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    PLAYERPETS_RemoveGroupPets(pGame, pPlayer, nPetType);
    PLAYERPETS_SetPetLimit(pGame, pPlayer, nPetType, nPetMax);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData || !pPlayerData->pPlayerPets)
    {
        return;
    }

    D2PetListStrc* pPetList = PLAYERPETS_GetPetListByType(pPlayerData->pPlayerPets, nPetType);
    if (!pPetList)
    {
        return;
    }

    D2PetInfoStrc petInfo;
    petInfo.nSeed = 0;
    petInfo.nName = 0;
    petInfo.nHirelingId = 0;
    if (PLAYERPETS_AppendPet(pPet, &petInfo, pPlayer, pGame, pPetList))
    {
        D2PetArgStrc arg = {};
        arg.nPetType = nPetType;
        arg.nPetGUID = sub_I16_GetUnitIdRet(pPet);
        arg.nPetClass = sub_I16_GetClassIdRet(pPet);
        arg.nUnitGUID = pPlayer->dwUnitId;
        SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_UpdateClient, &arg);
    }
}

// 0x00575E90
void __fastcall PLAYERPETS_AddPetWithInfo(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, int nPetType, D2PetInfoStrc* pPetInfo)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x3B5);

    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerPets)
    {
        return;
    }

    D2PetListStrc* pPetList = PLAYERPETS_GetPetListByType(pPlayerPets, nPetType);
    if (!pPetList)
    {
        return;
    }

    D2PetInfoStrc petInfo = *pPetInfo;
    if (PLAYERPETS_AppendPet(pPet, &petInfo, pPlayer, pGame, pPetList))
    {
        D2PetArgStrc arg = {};
        arg.nPetType = nPetType;
        arg.nPetGUID = sub_I16_GetUnitIdRet(pPet);
        arg.nUnitGUID = sub_I16_GetUnitIdRet(pPlayer);
        arg.nPetClass = sub_I16_GetClassIdRet(pPet);
        arg.nSeed = pPetInfo->nSeed;
        arg.nName = pPetInfo->nName;
        SUNIT_IterateLivingPlayers(pGame, PLAYERPETS_PlayerIterate_UpdateClient, &arg);
    }
}

// 0x00575070
int __fastcall PLAYERPETS_HasLivingHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2PlayerPetStrc* pPlayerPets = pPlayerData->pPlayerPets;
    if (!pPlayerData->pPlayerPets)
    {
        return 0;
    }

    UnitGetClient(pPlayer, ".\\PLAYER\\PlayerPets.cpp", 0x66E);
    D2PetListStrc* pPetList = PLAYERPETS_GetPetListFromPetType(pPlayerPets, 7);
    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (SUNIT_GetServerUnit(pGame, 1, pPetData->nUnitGUID))
        {
            return 1;
        }
    }
    return 0;
}

