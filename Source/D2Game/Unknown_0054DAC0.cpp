#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2ItemsWorld.h"
#include "D2Win32Types.h"

#include "D2GameStrc.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2LanguageNames.h"
struct D2ActiveRoomStrc;
struct D2RoomCoordListStrc;
struct D2UnitStrc;

struct D2DrlgCoordsStrc;
union D2SeedStrc;
struct D2MonStatsTxt;
struct D2MonsterRegionStrc;

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall sub_M96_UseBounds_0054DAC0(int nX, int nY, int nWidth, int nHeight);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags); // 0x005B3040
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a6, short nFlags); // 0x005B2F70
int __stdcall sub_0054DDC0_FindPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int nClassId, D2UnkMonCreateStrc2* pCreate, int* pX, int* pY); // 0x0054DDC0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
void __fastcall MONSTERUNIQUE_PromoteToChampion(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nUMod); // 0x005A48C0
D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps); // 0x005A43E0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId); // 0x005444B0
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0
static int MONSTERREGION_CanRetryPresetSpawn(int nMonsterId); // 0x0054E3A0

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x0054DA60
int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nNoInChain)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return -1;
    }

    int nClassId = pMonStatsTxtRecord->nBaseId;
    for (int i = 0; i < nNoInChain; ++i)
    {
        nClassId = pMonStatsTxtRecord->nNextInClass;
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            break;
        }
    }

    return nClassId;
}

// 0x0054DAC0
static void __stdcall sub_0054DAC0_GetSpawnBounds(D2ActiveRoomStrc* pRoom, int* pWidth, D2RoomCoordListStrc* pArea, int* pX, int* pY, int* pHeight)
{
    if (!pArea)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom, &coords);
        *pX = coords.nSubtileX + 1;
        *pY = coords.nSubtileY + 1;
        *pWidth = coords.nSubtileWidth - 1;
        *pHeight = coords.nSubtileHeight - 1;
    }
    else
    {
        tagRECT rect;
        CopyRect(&rect, &pArea->pBox[1]);
        DUNGEON_GameTileToSubtileCoords(&rect.left, &rect.top);
        DUNGEON_GameTileToSubtileCoords(&rect.right, &rect.bottom);
        *pX = rect.left + 1;
        *pY = rect.top + 1;
        *pWidth = rect.right - *pX;
        *pHeight = rect.bottom - *pY;
    }
}

struct D2GameActsViewStrc;

struct D2RoomWarpCoordsStrc;

struct D2LevelsTxt;

struct D2GameActsViewStrc
{
    char unk0x00[0xBC];
    D2DrlgActStrc* pAct[5];
};

struct D2RoomWarpCoordsStrc
{
    int nX[9];
    int nY[9];
    int nCount;
};

D2RoomWarpCoordsStrc* __stdcall DUNGEON_GetWarpCoordinatesFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AC10

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __stdcall SKILLS_GameTileToSubtileCoords(int* pX, int* pY); // 0x00643560

static int __stdcall sub_0054DB50_IsNearWarpOrSpawn(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom);

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY);                                       // 0x0061B130

// 0x0054DB50
static int __stdcall sub_0054DB50_IsNearWarpOrSpawn(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
    {
        return 0;
    }

    D2RoomWarpCoordsStrc* pWarps = DUNGEON_GetWarpCoordinatesFromRoom(pRoom);
    if (!pWarps)
    {
        return 0;
    }

    const int nDistSq = DATATBLS_GetLevelsTxtRecord(nLevelId)->dwWarpDist;
    for (int i = 0; i < pWarps->nCount; ++i)
    {
        const int nDX = nX - pWarps->nX[i];
        const int nDY = nY - pWarps->nY[i];
        if (nDY * nDY + nDX * nDX < nDistSq)
        {
            return 1;
        }
    }

    int nSpawnX;
    int nSpawnY;
    DUNGEON_FindActSpawnLocation(((D2GameActsViewStrc*)pGame)->pAct[DRLG_GetActNoFromLevelId(nLevelId)], nLevelId, 11, &nSpawnX, &nSpawnY);
    if (nSpawnX > 0 && nSpawnY > 0)
    {
        SKILLS_GameTileToSubtileCoords(&nSpawnX, &nSpawnY);
        const int nDX = nX - nSpawnX;
        const int nDY = nY - nSpawnY;
        if (nDY * nDY + nDX * nDX < nDistSq)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0054DC40
int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pArea, int nClassId, int* pX, int* pY, int bAvoidWarps)
{
    int nX, nY, nWidth, nHeight;
    sub_0054DAC0_GetSpawnBounds(pRoom, &nWidth, pArea, &nX, &nY, &nHeight);

    int bHasArea = 0;
    int nAreaIndex = 0;
    if (pArea)
    {
        nAreaIndex = pArea->nIndex;
        bHasArea = 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int nTry = 0; nTry < 20; ++nTry)
    {
        const int nPosX = SEED_RollLimitedRandomNumber_Inline(pSeed, nWidth) + nX;
        const int nPosY = SEED_RollLimitedRandomNumber_Inline(pSeed, nHeight) + nY;

        if (bAvoidWarps && sub_0054DB50_IsNearWarpOrSpawn(pGame, nPosX, nPosY, pRoom))
        {
            continue;
        }

        D2UnitStrc* pMonster;
        if (bHasArea)
        {
            if (D2Common_10095(pRoom, nPosX, nPosY) != nAreaIndex)
            {
                continue;
            }

            pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pArea, nPosX, nPosY, nClassId, 1, -1, 1);
        }
        else
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nPosX, nPosY, nClassId, 1, -1, 1);
        }

        if (pMonster)
        {
            *pX = nPosX;
            *pY = nPosY;
            return 1;
        }
    }

    return 0;
}

struct D2ActiveRoomViewStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

struct D2FormationOffsetStrc
{
    int nX;
    int nY;
    int unk0x08;
};




// 0x0054DDC0
int __stdcall sub_0054DDC0_FindPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pArea, int nClassId, int* pFormation, int* pX, int* pY)
{
    int nX, nY, nWidth, nHeight;
    sub_0054DAC0_GetSpawnBounds(pRoom, &nWidth, pArea, &nX, &nY, &nHeight);

    int bHasArea = 0;
    int nAreaIndex = 0;
    if (pArea)
    {
        nAreaIndex = pArea->nIndex;
        bHasArea = 1;
    }

    D2SeedStrc* pSeed = pRoom ? &((D2ActiveRoomViewStrc*)pRoom)->pSeed : 0;
    const int nCount = pFormation[0];
    pFormation += 3;
    for (int nTry = 0; nTry < 20; ++nTry)
    {
        const int nPosX = SEED_RollLimitedRandomNumber_Inline(pSeed, nWidth) + nX;
        const int nPosY = SEED_RollLimitedRandomNumber_Inline(pSeed, nHeight) + nY;

        D2FormationOffsetStrc* pOffset = (D2FormationOffsetStrc*)pFormation;
        int bPlaced = 1;
        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pMonster;
            if (bHasArea)
            {
                if (D2Common_10095(pRoom, pOffset->nX + nPosX, pOffset->nY) != nAreaIndex)
                {
                    bPlaced = 0;
                    break;
                }

                pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pArea, pOffset->nX + nPosX, pOffset->nY + nPosY, nClassId, 1, -1, 1);
            }
            else
            {
                pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, pOffset->nX + nPosX, pOffset->nY + nPosY, nClassId, 1, -1, 1);
            }

            if (!pMonster)
            {
                bPlaced = 0;
                break;
            }

            ++pOffset;
        }

        if (bPlaced)
        {
            *pX = nPosX;
            *pY = nPosY;
            return 1;
        }
    }

    return 0;
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

// 0x0054DF80
static D2UnitStrc* __stdcall sub_0054DF80_SpawnGroupInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, unsigned char nMin, unsigned char nMax, int nMonsterId)
{
    if (!nMin || !nMax || nMax < nMin)
        return 0;

    int nX;
    int nY;
    if (!MONSTERREGION_FindSpawnLocation(pGame, pRoom, pCoordList, nMonsterId, &nX, &nY, 1))
        return 0;

    D2UnitStrc* pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pCoordList, nX, nY, nMonsterId, 1, -1, 0);
    if (!pMonster)
        return 0;

    --nMin;
    --nMax;
// build: symbol ?MONSTERREGION_CheckMonStats2Flag@* 0x004638A0
    if (MONSTERREGION_CheckMonStats2Flag(nMonsterId, 0x12) && CUNIT_ValidateMonsterId(nMonsterId) == 0x210)
        SUNIT_AllocUnitData(2, 0x232, CLIENTS_GetUnitX(pMonster), CLIENTS_GetUnitY(pMonster), pGame, pRoom, 1, 0, 0);

    for (int nCount = nMin + ITEMS_RollLimitedRandomNumber(&pMonster->pSeed, nMax - nMin + 1); nCount > 0; --nCount)
        MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pCoordList, pMonster, nMonsterId, 1, 3, 0);

    return pMonster;
}

// 0x0054E090
static D2UnitStrc* __stdcall sub_0054E090_SpawnGroupAtPoint(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nMonsterId, int nX, int nY)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    unsigned char nMinGrp = pMonStatsTxtRecord->nMinGrp;
    const unsigned char nMaxGrp = pMonStatsTxtRecord->nMaxGrp;
    if (!nMinGrp || !nMaxGrp || nMaxGrp < nMinGrp)
        return 0;

    D2RoomCoordListStrc* pCoordList = D2Common_10096(pRoom, nX, nY);
    if (!pCoordList)
        return 0;

    D2UnitStrc* pMonster = MONSTERSPAWN_SpawnInCoordList(pGame, pRoom, pCoordList, nX, nY, nMonsterId, 1, -1, 0);
    if (!pMonster)
        return 0;

    --nMinGrp;
    for (int nCount = nMinGrp + ITEMS_RollLimitedRandomNumber(&pMonster->pSeed, (unsigned char)(nMaxGrp - 1) - nMinGrp + 1); nCount > 0; --nCount)
        MONSTERSPAWN_SpawnAtUnitInCoordList(pGame, pCoordList, pMonster, nMonsterId, 1, 3, 0);

    return pMonster;
}

// 0x0054E190
static int __stdcall sub_0054E190_SpawnMonsterAtFreePosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate)
{
    int nX;
    int nY;
    if (!sub_0054DDC0_FindPosition(pGame, pRoom, 0, nClassId, pCreate, &nX, &nY))
        return 0;

    return sub_005B3270(pGame, pRoom, nX, nY, 0, nClassId, 1, pCreate, 0);
}

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

// 0x0054E260
static int __stdcall sub_0054E260_SpawnMonsterWithMinions(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId)
{
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueGroup(pGame, pRoom, pCoordList, nMonsterId, 1, 0, 0, 1);
    if (!pMonster)
        return 0;

    sub_0054E1E0_SpawnChampionMinions(pCoordList, nMonsterId, pGame, pMonster);
    return 1;
}

// 0x0054E2A0
static int sub_0054E2A0_GetFallenVariantForLevel(int nLevelId, int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    const int nBaseId = !pMonStatsTxtRecord ? nMonsterId : pMonStatsTxtRecord->nBaseId;

    switch (MONSTERREGION_SanitizeMonsterId_Inline(nBaseId))
    {
    case 0x13:
        switch (nLevelId)
        {
        case LEVEL_BLACKMARSH:
            return MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_FALLEN2);
        case LEVEL_TAMOEHIGHLAND:
        case LEVEL_PITLEV1:
        case LEVEL_PITLEV2:
            return MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_FALLEN3);
        }
        break;

    case 0x3A:
        switch (nLevelId)
        {
        case LEVEL_BLACKMARSH:
        case LEVEL_TAMOEHIGHLAND:
            return MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_FALLENSHAMAN2);
        case LEVEL_PITLEV1:
        case LEVEL_PITLEV2:
            return MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_FALLENSHAMAN3);
        }
        break;
    }

    return nMonsterId;
}

// 0x0054E490
static D2UnitStrc* __stdcall sub_0054E490_SpawnRegularPresetMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMode, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nClassId);
    if (!pMonStatsTxtRecord)
        return 0;

    if (nClassId == 0x1B2)
    {
        --nX;
        if (!QUESTS_CheckNotIntroQuest(pGame, 0x20))
            nMode = 0xC;
    }

    if (MONSTERREGION_CheckMonStats2Flag(nClassId, 0xD))
        return 0;

    int nFlags = 0;
    if (pMonStatsTxtRecord->nMonStatsFlags[0x12 >> 3] & gdwBitMasks[0x12 & 7])
        nFlags = 8;

    D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, nMode, -1, nFlags);
    if (!pMonster)
    {
        if (!MONSTERREGION_CanRetryPresetSpawn(nClassId))
            return 0;

        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, nMode, 4, nFlags);
        if (!pMonster)
            return 0;
    }

    if (MONSTERREGION_CheckMonStats2Flag(nClassId, 0x12))
    {
        if (nClassId < sgptDataTables->nMonStatsTxtRecordCount && nClassId == 0x1B0)
            SUNIT_AllocUnitData(2, 0x23B, CLIENTS_GetUnitX(pMonster), CLIENTS_GetUnitY(pMonster), pGame, pRoom, 1, 0, 0);
        else if (CUNIT_ValidateMonsterId(nClassId) == 0x1B1)
            SUNIT_AllocUnitData(2, 0x23C, CLIENTS_GetUnitX(pMonster), CLIENTS_GetUnitY(pMonster), pGame, pRoom, 1, 0, 0);
    }

    return pMonster;
}

int __fastcall DATATBLS_GetSuperUniquesTxtRecordCount();                                                    // 0x00655710

D2UnitStrc* __fastcall D2GAME_SpawnSuperUnique_6FC6F690(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSuperUniqueId); // 0x005A49B0

int __fastcall MONSTERCHOOSE_GetPresetMonsterId(D2GameStrc* pGame, D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom, D2MonStatsTxt** ppMonStatsTxtRecord, unsigned char nChance, int bSpawnUMon); // 0x005BDE80

int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nChainIncrements);                      // 0x0054DA60

int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId);                                     // 0x0063EC70

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                   // 0x00451F80

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C390

// 0x0054E600
D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId < 0)
        return 0;

    D2UnitStrc* pMonster = 0;
    int bRegularId = 1;
    if (nClassId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nClassId -= sgptDataTables->nMonStatsTxtRecordCount;
        const int nSuperUniques = DATATBLS_GetSuperUniquesTxtRecordCount();
        if (nClassId >= nSuperUniques)
        {
            nClassId -= nSuperUniques;
            bRegularId = 0;
        }
        else
        {
            return D2GAME_SpawnSuperUnique_6FC6F690(pGame, pRoom, nX, nY, nClassId);
        }
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);

    if (bRegularId == 1)
    {
        switch (MONSTERREGION_SanitizeMonsterId_Inline(nClassId))
        {
        case 0x1F2:
            if (QUESTS_CheckNotIntroQuest(pGame, 0x1F) && DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_BLOODYFOOTHILLS)
                nClassId = MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_CATAPULT3);
            break;
        case 0x205:
            if (QUESTS_CheckNotIntroQuest(pGame, 0x1F) && DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_BLOODYFOOTHILLS)
                nClassId = MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_CATAPULTSPOTTER3);
            break;
        }

        if (pGame->nDifficulty > 0)
        {
            switch (MONSTERREGION_SanitizeMonsterId_Inline(nClassId))
            {
            case 0x1C5:
            case 0x211:
                if (nLevelId == LEVEL_BLOODYFOOTHILLS)
                    return 0;
                break;
            }
        }

        return sub_0054E490_SpawnRegularPresetMonster(pGame, pRoom, nX, nY, nMode, nClassId);
    }

    switch (nClassId)
    {
    case 10:
    case 11:
    {
        int nFlags = 0;
        if (nClassId == 10)
            nFlags = 4;

        int nChainIncrements = 0;
        switch (nLevelId)
        {
        case LEVEL_SPIDERFOREST:
        case LEVEL_GREATMARSH:
        case LEVEL_FLAYERJUNGLE:
            nChainIncrements = 1;
            break;
        case LEVEL_SEWERSA3LEV1:
        case LEVEL_SEWERSA3LEV2:
            nChainIncrements = 2;
            break;
        case LEVEL_SWAMPYPITLEV1:
        case LEVEL_SWAMPYPITLEV2:
        case LEVEL_FLAYERDUNGEONLEV1:
        case LEVEL_FLAYERDUNGEONLEV2:
        case LEVEL_SWAMPYPITLEV3:
        case LEVEL_FLAYERDUNGEONLEV3:
            nChainIncrements = 0;
            break;
        }

        const int nMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_TENTACLEHEAD1), nChainIncrements);
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nMode, -1, nFlags);
        break;
    }
    case 5:
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, MONSTERREGION_SanitizeMonsterId_Inline(MONSTER_BLOODRAVEN), nMode, -1, 0);
        break;
    case 2:
    {
        D2MonStatsTxt* pMonStatsTxtRecord;
        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        const int nMonsterId = MONSTERCHOOSE_GetPresetMonsterId(pGame, pMonsterRegion, pRoom, &pMonStatsTxtRecord, 0, 1);
        if (!pMonStatsTxtRecord)
            return 0;

        MONSTERUNIQUE_SpawnUniqueGroup(pGame, pRoom, 0, nMonsterId, 0, 0, 0, 1);
        break;
    }
    case 3:
    {
        D2MonStatsTxt* pMonStatsTxtRecord;
        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        nClassId = MONSTERCHOOSE_GetPresetMonsterId(pGame, pMonsterRegion, pRoom, &pMonStatsTxtRecord, 0, 1);
        if (!pMonStatsTxtRecord)
            return 0;

        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nClassId, nMode, -1, 0);
        if (!pMonster)
            break;

        MONSTERUNIQUE_PromoteToChampion(pGame, pMonster, 0x10);
        sub_0054E1E0_SpawnChampionMinions(0, nClassId, pGame, pMonster);
        break;
    }
    case 4:
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, MONSTER_NAVI, nMode, -1, 0);
        break;
    case 8:
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, MONSTER_MAGGOTQUEEN1, nMode, -1, 8);
        break;
    case 17:
    case 18:
    case 22:
    case 23:
    case 25:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    {
        int nAnimMode = nMode;
        int nMonsterId = 0;
        switch (nClassId)
        {
        case 17:
            nMonsterId = MONSTER_FALLEN1;
            break;
        case 18:
            nMonsterId = MONSTER_FALLENSHAMAN1;
            break;
        case 22:
            nMonsterId = MONSTER_FETISH1;
            break;
        case 23:
            nMonsterId = MONSTER_FETISHSHAMAN1;
            break;
        case 29:
            nMonsterId = MONSTER_MINION1;
            nAnimMode = 12;
            break;
        case 30:
            nMonsterId = nLevelId == LEVEL_BLOODYFOOTHILLS ? 0x211 : 0x1EC;
            nAnimMode = 12;
            break;
        case 31:
            nMonsterId = MONSTER_ACT5BARB1;
            nAnimMode = 12;
            break;
        case 32:
            nMonsterId = MONSTER_REANIMATEDHORDE3;
            nAnimMode = 12;
            break;
        case 25:
        case 27:
        case 28:
            return 0;
        }

        nMonsterId = sub_0054E2A0_GetFallenVariantForLevel(nLevelId, D2Common_11063(pRoom, SKILLDESC_ValidateMonsterId(nMonsterId)));

        int nFlags = 0;
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
        if (pMonStatsTxtRecord->nMonStatsFlags[0x12 >> 3] & gdwBitMasks[0x12 & 7])
            nFlags = 8;

        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, -1, nFlags);
        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, 4, nFlags);
            if (!pMonster)
                break;
        }

        if (CUNIT_ValidateMonsterId(nMonsterId) == 0x1B6)
        {
            const int nExpireFrame = SEED_RollLimitedRandomNumber(&pMonster->pSeed, 50) + pGame->dwGameFrame + 250;
            EVENT_SetEvent(pGame, pMonster, 7, nExpireFrame, 0, 0);
        }

        if (pMonster && nAnimMode == 12)
            pMonster->dwFlags |= 0x2000000;
        break;
    }
    case 24:
    case 26:
    {
        if (pGame->nDifficulty > 0)
            return 0;

        int nMonsterId = 0;
        switch (nClassId)
        {
        case 24:
            nMonsterId = nLevelId == LEVEL_BLOODYFOOTHILLS ? 0x211 : 0x1EC;
            break;
        case 26:
            nMonsterId = MONSTER_MINION1;
            break;
        }

        nMonsterId = D2Common_11063(pRoom, SKILLDESC_ValidateMonsterId(nMonsterId));
        sub_0054E090_SpawnGroupAtPoint(pGame, pRoom, nMonsterId, nX, nY);
        break;
    }
    }

    return pMonster;
}

// 0x0054EBC0
static int sub_0054EBC0_CanPopulateRoom(D2ActiveRoomStrc* pRoom, D2GameStrc* pGame)
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

static inline D2MonStatsTxt* GetMonStatsRecord(D2DataTablesStrc* pDataTables, int nClassId)
{
    D2MonStatsTxt* pRecord = 0;
    if (nClassId >= 0 && nClassId < pDataTables->nMonStatsTxtRecordCount)
    {
        pRecord = &pDataTables->pMonStatsTxt[nClassId];
    }
    return pRecord;
}

// 0x0054EC40
int __fastcall sub_0054EC40_IsSpecialBaseMonster(int nClassId)
{
    D2DataTablesStrc* pDataTables = sgptDataTables;
    if (nClassId < 0)
    {
        goto fail;
    }

    D2MonStatsTxt* pRecord = GetMonStatsRecord(pDataTables, nClassId);
    if (pRecord)
    {
        nClassId = pRecord->nBaseId;
    }

    if (nClassId < 0)
    {
        goto fail;
    }
    if (nClassId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        goto fail;
    }
    if (nClassId == 19 || nClassId == 91)
    {
        return 1;
    }
fail:
    return 0;
}

struct D2WanderingRange
{
    unsigned char nBase;
    unsigned char nCount;
};

extern D2WanderingRange gaWanderingRanges[]; // 0x00731B30

extern int gnWanderingIds[]; // 0x00731B2C


void __fastcall TARGETS_InsertUnitNode(D2GameStrc*, D2UnitStrc*, int, int); // 0x005B1990

// 0x0054EF50
static void __stdcall sub_0054EF50_SpawnWandering(
    D2MonsterRegionStrc* pRegion, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2LevelsTxt* pLevels)
{
    unsigned char nAct = pLevels->nAct;
    if (nAct >= 5)
        return;
    int nCount = gaWanderingRanges[nAct].nCount;
    int nBase = gaWanderingRanges[nAct].nBase;
    if (!nCount)
        return;
    int nMonster = gnWanderingIds[SEED_RollLimitedRandomNumber(pRoom ? &pRoom->pSeed : 0, nCount) + nBase];
    int nX;
    int nY;
    if (!MONSTERREGION_FindSpawnLocation(pGame, pRoom, 0, nMonster, &nX, &nY, 0))
        return;
    D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonster, 1, -1, 0);
    if (pMonster)
    {
        TARGETS_InsertUnitNode(pGame, pMonster, 0, 8);
        ++pRegion->nWanderingCount;
    }
}

// 0x0054EFF0
static void __stdcall sub_0054EFF0_CheckWandering(
    D2GameStrc* pGame, int nLevel, D2LevelsTxt* pLevels, D2ActiveRoomStrc* pRoom)
{
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    if ((int)(SEED_RollRandomNumber(pSeed) % 100) < 3)
    {
        D2MonsterRegionStrc* pRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pGame->pMonReg, nLevel);
        if (pRegion->nWanderingCount < 3)
            sub_0054EF50_SpawnWandering(pRegion, pGame, pRoom, pLevels);
    }
}

// 0x0054F060
void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    if ((SEED_RollRandomNumber(pRoom ? &pRoom->pSeed : 0) & 0x7FFF) == 0 && !pRoom->nNumClients)
    {
        int nLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
        D2LevelsTxt* pLevels = DATATBLS_GetLevelsTxtRecord(nLevel);
        if (pLevels->nWandering && pLevels->dwMonDen)
            sub_0054EFF0_CheckWandering(pGame, nLevel, pLevels, pRoom);
    }
}

// 0x0054E3A0
static int MONSTERREGION_CanRetryPresetSpawn(int nMonsterId)
{
    switch (MONSTERREGION_SanitizeMonsterId_Inline(nMonsterId))
    {
    case 0xE5:
    case 0x11C:
    case 0x11D:
    case 0x11E:
    case 0x11F:
    case 0x120:
    case 0x188:
    case 0x189:
        return 0;
    }
    return 1;
}

D2UnitStrc* __fastcall sub_H05_Emit_0054DF80(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, unsigned char nMin, unsigned char nMax)
{
    return sub_0054DF80_SpawnGroupInCoordList(pGame, pRoom, pCoordList, nMin, nMax, nMonsterId);
}

int __fastcall sub_H05_Emit_0054E190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, D2UnkMonCreateStrc2* pCreate)
{
    return sub_0054E190_SpawnMonsterAtFreePosition(pGame, pRoom, nClassId, pCreate);
}

int __fastcall sub_H05_Emit_0054E260(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId)
{
    return sub_0054E260_SpawnMonsterWithMinions(pGame, pRoom, pCoordList, nMonsterId);
}

int __fastcall sub_H05_Emit_0054EBC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    return sub_0054EBC0_CanPopulateRoom(pRoom, pGame);
}

#include "gen/data/Source/D2Game/Unknown_0054DAC0.inc"
