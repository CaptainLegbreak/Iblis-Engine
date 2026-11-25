#include "D2LevelIds.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2GameStrc.h"
struct D2MonStatsTxt;
struct D2UnitStrc;
struct D2RoomCoordListStrc;
struct D2ActiveRoomStrc;
struct D2UnkMonCreateStrc2;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, int* pX, int* pY, int a7); // 0x0054DC40
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags); // 0x005B3040
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId);                                             // 0x00463900
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                        // 0x0045C3E0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a6, short nFlags); // 0x005B2F70
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc* pRoom, int nX, int nY);                    // 0x0061AD30
int __stdcall sub_0054DDC0_FindPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int nClassId, D2UnkMonCreateStrc2* pCreate, int* pX, int* pY); // 0x0054DDC0
int __fastcall MONSTERSPAWN_SpawnFormation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pOwner, int nClassId, int nAnimMode, D2UnkMonCreateStrc2* a8, short nFlags); // 0x005B3270
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag);                                // 0x005A0180
void __fastcall MONSTERUNIQUE_PromoteToChampion(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nUMod); // 0x005A48C0
D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps); // 0x005A43E0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId);                                  // 0x005444B0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom);                                 // 0x0061A1F0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
int __stdcall DUNGEON_GetNumberOfPopulatedRoomsInLevel(D2DrlgActStrc* pAct, int nLevelId); // 0x0061ABF0
int __fastcall sub_005B5210(D2GameStrc* pGame);                                                             // 0x005B5210

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static inline int MONSTERREGION_SanitizeMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

static D2UnitStrc* __stdcall sub_0054DF80_SpawnGroupInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, unsigned char nMin, unsigned char nMax, int nMonsterId);
static D2UnitStrc* __stdcall sub_0054DF80_SpawnGroupInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, unsigned char nMin, unsigned char nMax, int nMonsterId); // 0x0054DF80
// 0x0054DF80
static D2UnitStrc* __stdcall sub_0054DF80_SpawnGroupInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, unsigned char nMin, unsigned char nMax, int nMonsterId)
{
    if (!nMin || !nMax || nMax < nMin)
        return 0;

    int nX;
    int nY;
    if (!sub_0054DC40_FindSpawnPosition(pGame, pRoom, pCoordList, nMonsterId, &nX, &nY, 1))
        return 0;

    D2UnitStrc* pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pCoordList, nX, nY, nMonsterId, 1, -1, 0);
    if (!pMonster)
        return 0;

    --nMin;
    --nMax;
    if (MONSTERREGION_CheckMonStats2Flag(nMonsterId, 0x12) && CUNIT_ValidateMonsterId(nMonsterId) == 0x210)
        SUNIT_AllocUnitData(2, 0x232, CLIENTS_GetUnitX(pMonster), CLIENTS_GetUnitY(pMonster), pGame, pRoom, 1, 0, 0);

    for (int nCount = nMin + ITEMS_RollLimitedRandomNumber(&pMonster->pSeed, nMax - nMin + 1); nCount > 0; --nCount)
        MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pCoordList, pMonster, nMonsterId, 1, 3, 0);

    return pMonster;
}

static __declspec(noinline) int __stdcall sub_0054E190_SpawnMonsterAtFreePosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate);
static int __stdcall sub_0054E190_SpawnMonsterAtFreePosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate); // 0x0054E190
// 0x0054E190
static int __stdcall sub_0054E190_SpawnMonsterAtFreePosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate)
{
    int nX;
    int nY;
    if (!sub_0054DDC0_FindPosition(pGame, pRoom, 0, nClassId, pCreate, &nX, &nY))
        return 0;

    return MONSTERSPAWN_SpawnFormation(pGame, pRoom, nX, nY, 0, nClassId, 1, pCreate, 0);
}

static void __stdcall sub_0054E1E0_SpawnChampionMinions(D2RoomCoordListStrc* pCoordList, int nMonsterId, D2GameStrc* pGame, D2UnitStrc* pMonster); // 0x0054E1E0
// 0x0054E1E0
static void __stdcall sub_0054E1E0_SpawnChampionMinions(D2RoomCoordListStrc* pCoordList, int nMonsterId, D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    if (!MONSTERUNIQUE_CheckMonTypeFlag(pMonster, 4))
        return;

    const int nMinions = SEED_RollRandomNumber(&pMonster->pSeed) % 3 + 1;
    for (int i = 0; i < nMinions; ++i)
    {
        D2UnitStrc* pMinion = MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pCoordList, pMonster, nMonsterId, 1, 4, 0);
        if (pMinion)
            MONSTERUNIQUE_PromoteToChampion(pGame, pMinion, 0x10);
    }
}

static int sub_0054EBC0_CanPopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);
static int sub_0054EBC0_CanPopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0054EBC0
// 0x0054EBC0
static int sub_0054EBC0_CanPopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2MonsterRegionStrc* pRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pRegion)
        return 0;

    ++pRegion->nCount;
    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    if (!nLevelId)
        return 0;

    if (pRegion->nMonsterRegionLevel < 0)
        pRegion->nMonsterRegionLevel = DUNGEON_GetNumberOfPopulatedRoomsInLevel(pGame->pAct[pRegion->nAct], nLevelId);

    if (!pRegion->nMonsterCount)
        return 0;

    if (!pRegion->nMonsterRegionLevel)
        return 0;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_CHAOSSANCTUM)
    {
        if (sub_005B5210(pGame))
            return 0;
    }

    return 1;
}

struct D2RoomRectStrc { int left, top, right, bottom; };
struct D2RoomCoordListStrc {
    D2RoomRectStrc boxes[2]; int bNode; int unknown24; int index; D2RoomCoordListStrc* next;
};
extern "C" __declspec(dllimport) int __stdcall CopyRect(D2RoomRectStrc*, const D2RoomRectStrc*);
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc*); // 0x0061AD50
void __stdcall SKILLS_GameTileToSubtileCoords(int*,int*); // 0x00643560
int __fastcall MONSTERCHOOSE_GetPresetMonsterId(D2GameStrc* pGame, D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom, D2MonStatsTxt** ppMonStatsTxtRecord, unsigned char nChance, int bSpawnUMon); // 0x005BDE80
int __fastcall MONSTERCHOOSE_GetBossSpawnType(D2MonsterRegionStrc*,D2ActiveRoomStrc*); // 0x005BE020
int __fastcall sub_0054EC40_IsSpecialBaseMonster(int); // 0x0054EC40
D2UnkMonCreateStrc2* __fastcall MONSTERCHOOSE_RollFormation(D2ActiveRoomStrc*); // 0x005BDFF0
// 0x0054EC90
void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    if (!sub_0054EBC0_CanPopulateRoom(pGame, pRoom))
    {
        return;
    }

    D2RoomCoordListStrc* pRoomCoordList = DUNGEON_GetRoomCoordList(pRoom);
    if (!pRoomCoordList)
    {
        return;
    }

    D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
    pMonsterRegion->nMonsterCount = pMonsterRegion->nMonsterCount > 10000 ? 10000 : pMonsterRegion->nMonsterCount;

    int bIncrease = 0;
    while (pRoomCoordList)
    {
        if (pRoomCoordList->index && !pRoomCoordList->bNode)
        {
            D2RoomRectStrc tRect;
            CopyRect(&tRect, &pRoomCoordList->boxes[1]);
            if (tRect.left || tRect.right)
            {
                SKILLS_GameTileToSubtileCoords(&tRect.left, &tRect.top);
                SKILLS_GameTileToSubtileCoords(&tRect.right, &tRect.bottom);

                for (int i = (tRect.right - tRect.left) / 3 * ((tRect.bottom - tRect.top) / 3); i > 0; )
                {
                    if ((int)(SEED_RollRandomNumber(&pGame->pGameSeed) % 100000) <= pMonsterRegion->nMonsterCount)
                    {
                        D2MonStatsTxt* pMonStatsTxtRecord;
                        const int nMonsterId = MONSTERCHOOSE_GetPresetMonsterId(pGame, pMonsterRegion, pRoom, &pMonStatsTxtRecord, 20, 0);
                        if (!pMonStatsTxtRecord)
                        {
                            return;
                        }

                        int nType = MONSTERCHOOSE_GetBossSpawnType(pMonsterRegion, pRoom);
                        if (nType == 1)
                        {
                            nType = 2;
                        }

                        int bSpawned = 0;
                        switch (nType)
                        {
                        case 0:
                        {
                            const int nChampionId = MONSTERCHOOSE_GetPresetMonsterId(pGame, pMonsterRegion, pRoom, &pMonStatsTxtRecord, 0, 1);
                            D2UnitStrc* pChampion = MONSTERUNIQUE_SpawnUniqueGroup(pGame, pRoom, pRoomCoordList, nChampionId, 1, 0, 0, 1);
                            if (pChampion)
                            {
                                sub_0054E1E0_SpawnChampionMinions(pRoomCoordList, nChampionId, pGame, pChampion);
                                bSpawned = 1;
                            }
                            break;
                        }
                        case 1:
                            bSpawned = sub_0054E190_SpawnMonsterAtFreePosition(pGame, pRoom, nMonsterId, MONSTERCHOOSE_RollFormation(pRoom));
                            break;
                        default:
                        {
                            unsigned char nMinGrp = 1;
                            unsigned char nMaxGrp = 1;
                            if (!sub_0054EC40_IsSpecialBaseMonster(nMonsterId))
                            {
                                nMinGrp = pMonStatsTxtRecord->nMinGrp;
                                nMaxGrp = pMonStatsTxtRecord->nMaxGrp;
                            }
                            if ((!pMonStatsTxtRecord->nSparsePopulate || (int)(SEED_RollRandomNumber(&pGame->pGameSeed) % 100) <= pMonStatsTxtRecord->nSparsePopulate))
                            {
                                bSpawned = (int)sub_0054DF80_SpawnGroupInCoordList(pGame, pRoom, pRoomCoordList, nMinGrp, nMaxGrp, nMonsterId);
                            }
                            break;
                        }
                        }

                        if (bSpawned)
                        {
                            bIncrease = 1;
                        }
                        --i;
                    }
                    else
                    {
                        --i;
                    }
                }
            }
        }
        pRoomCoordList = pRoomCoordList->next;
    }

    if (bIncrease)
    {
        ++pMonsterRegion->nPopulated;
    }
}
