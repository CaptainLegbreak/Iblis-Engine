#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ObjectIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2ObjModes.h"
#include "D2ItemModes.h"
#include "D2Packets.h"
#include "D2QuestData.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "D2CommonApi.h"
// build: symbol _gaszLanguageNames 0x00731968

struct D2DifficultyLevelsTxt;

struct D2MonsterRegionStrc;

union D2SeedStrc;

struct D2MonRegDataStrc;

struct D2LevelsTxt;

struct D2MonStatsTxt;

struct D2DataTablesStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const char gszMonsterRegion[]; // 0x006E0CF8

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0

void* __fastcall FOG_AllocPool(void*,int,const char*,int,int); // 0x0040B430


D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int); // 0x0061DB70

void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc*,D2MonRegDataStrc*,int); // 0x005BDB20

static void __stdcall MONSTERREGION_SelectMonsters(D2SeedStrc* pSeed, int bHigher, D2LevelsTxt* pLevels, D2MonsterRegionStrc* pRegion); // 0x005475E0

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QUEST_A2Q3_TAINTEDSUN 10

#define QUEST_A2Q4_HORAZONTOME 11

#define QUEST_A3Q1_LAMESENTOME 15

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_OBJECT 2

#define UNIT_MISSILE 3

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define UNIT_INVALID 6

#define STRCOLOR_DARK_GOLD 4

#define OBJRGN_WELL_DISTANCE 100

#define OBJRGN_SHRINE_DISTANCE 50

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_NEUTRAL 1

#define UNIT_ALIGNMENT_GOOD 2

#define MONTYPEFLAG_OTHER 1

#define ACT_III 2

#define MONSTATSFLAGINDEX_FLYING 14

#define NUM_QUEST_PLAYER_GUIDS 32

#define LEVEL_FIRST_COUNCIL_LIMIT 108

#define QUEST_LOG_FLAGS 2

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_PRIMARYGOALDONE 13

#define UNITFLAG_TARGETABLE 0x00000002


struct D2QuestInfoStrc;

struct D2ObjectControlStrc;

struct D2PlayerDataStrc;

struct D2SuperUniquesTxt;

struct D2ObjInitFnStrc;


struct D2StaticPathStrc;

struct D2QuestTimerStrc;

struct D2ItemsTxt;


struct D2PackedGuidStrc;

struct D2MessageStrc;

struct D2GSPacketSrv27;


struct D2UnkPlrMsgStrc;

struct D2QuestGUIDStrc;

struct D2QuestInitTableStrc;


struct D2GSPacketSrv91;

struct Obj00545290;

struct Obj005452C0;

struct D2DrlgCoordsStrc;

struct D2ObjOperateFnStrc;


struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    D2QuestTimerStrc* pTimer;
    unsigned int dwTick;
    D2SeedStrc pSeed;
    unsigned char unk0x20;
    unsigned char unk_21[0x3];
};

#include "D2GameFuncs.h"




typedef int (__stdcall* FARPROC)();




int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180


#pragma pack(push, 1)

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    D2MessageListStrc tMessageList;
};

#pragma pack(pop)




extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4

int gbQuestDebug; // 0x008846DC

extern const D2UnkPlrMsgStrc gaUnitModeMessages[]; // 0x007319E8







void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId); // 0x00573500


extern unsigned int gdwBitMasks[]; // 0x006CE268






extern "C" const char gszObjRgnSourceFile[]; // 0x006E0C40

extern "C" const char gszPlrMsgSourceFile[]; // 0x006E1050




extern D2QuestInitTableStrc sgQuestInit[]; // 0x00731510






struct Obj00545290 { unsigned int dwValues[32]; unsigned short wCount80; };

struct Obj005452C0 { unsigned char bUnknown00[0x1C]; unsigned int dwValues1C[32]; unsigned short wCount9C; };








struct D2QuestDataStrc;

#define QUEST_A1Q4_CAIN 4

#define QUEST_A2Q1_RADAMENT 8

#define QUEST_A2Q5_SUMMONER 12

#define MAX_QUEST_STATUS 41

#define QUESTSTATEFLAG_A1Q1 1

#define QUESTSTATEFLAG_A2Q4 12

#define QUEST_A1Q1_DENOFEVIL 1

#define ACT_II 1

#define PACKET_QUESTSTATUS 0x52

#define PACKET_QUESTPROGRESS 0x50

#define LINE_UPDATEFLAGS_CLIENT 0xCA7

#define LINE_STATUS_CLIENT 0x49A

#define LINE_STATUS_QUESTNO 0x4B3

#define LINE_STATUS_FILTER 0x4CB


typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);









struct D2MessageListStrc;






struct D2ActiveRoomStrc;

struct D2RoomStrc;



struct D2BitBufferStrc;

typedef char QUESTINIT_check_data[sizeof(D2QuestDataStrc) == 0xF8 ? 1 : -1];

typedef char QUESTINIT_check_info[sizeof(D2QuestInfoStrc) == 0x24 ? 1 : -1];

typedef void (__fastcall* QUESTINIT)(D2QuestDataStrc* pQuestData);

struct D2QuestIntroTableStrc
{
    QUESTINIT pfInit;
    unsigned char nAct;
    unsigned char pad0x05[3];
};


extern D2QuestIntroTableStrc sgQuestIntro[];                                                  // 0x0073188C


void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30


#define QUESTS_SEED_STEP_HIGH_FIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }



struct D2CoordStrc;












#define SUMMONER_FLAG 2



void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00573570


extern const unsigned char gnSpawnMask; // 0x006CE268

extern const unsigned char gnRangedMask; // 0x006CE278

extern "C" void* __cdecl memmove(void*,const void*,unsigned int); // 0x00683840

static inline unsigned __int64 Roll(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    return (unsigned int)((((unsigned int)nMax - 1) & (unsigned int)nMax) ? (unsigned int)Roll(pSeed) % nMax : Roll(pSeed) & (nMax - 1));
}

static inline D2MonStatsTxt* MonStats(int id) {
 if(id<0||id>=sgptDataTables->nMonStatsTxtRecordCount)return 0;
 return &sgptDataTables->pMonStatsTxt[id];
}

// 0x005475E0
static void __stdcall MONSTERREGION_SelectMonsters(D2SeedStrc* pSeed, int bHigher, D2LevelsTxt* pLevels, D2MonsterRegionStrc* pRegion)
{
    int nToSpawn = pLevels->nNumMon;
    if (nToSpawn > 13)
        nToSpawn = 13;

    int nAvailable = pLevels->nNumNormalMonsters;
    if (bHigher)
        nAvailable = pLevels->nNumNightmareHellMonsters;

    if (nToSpawn > nAvailable)
        nToSpawn = nAvailable;

    short nMonsterIds[25];
    D2MonRegDataStrc* pMonData = pRegion->pMonData;
    if (bHigher)
    {
        for (int i = 0; i < pLevels->nNumNightmareHellMonsters; ++i)
            nMonsterIds[i] = pLevels->wNightmareHellMonsters[i];
    }
    else
    {
        for (int i = 0; i < pLevels->nNumNormalMonsters; ++i)
            nMonsterIds[i] = pLevels->wNormalMonsters[i];
    }

    for (int i = 0; i < nToSpawn && nAvailable > 0; ++i)
    {
        int nIndex = RollLimited(pSeed, nAvailable);
        short nMonsterId = nMonsterIds[nIndex];
        if (!i && pLevels->nRangedSpawn)
        {
            for (int j = 0; j < 20; ++j)
            {
                D2MonStatsTxt* pMonStatsTxtRecord = MonStats(nMonsterId);
                if (pMonStatsTxtRecord && (pMonStatsTxtRecord->nMonStatsFlags[3] & gnRangedMask))
                    break;

                nIndex = RollLimited(pSeed, nAvailable);
                nMonsterId = nMonsterIds[nIndex];
            }
        }

        --nAvailable;
        if (nIndex < nAvailable)
            memmove(&nMonsterIds[nIndex], &nMonsterIds[nIndex + 1], 2 * (nAvailable - nIndex));

        D2MonStatsTxt* pMonStatsTxtRecord = MonStats(nMonsterId);
        if (pMonStatsTxtRecord && (pMonStatsTxtRecord->nMonStatsFlags[0] & gnSpawnMask))
        {
            pMonData->nMonHcIdx = nMonsterId;
            pMonData->nRarity = pMonStatsTxtRecord->rarity;
            pRegion->nTotalRarity += pMonStatsTxtRecord->rarity;
            ++pRegion->nSpawnCount;
            ++pRegion->nMonCount;
            ++pMonData;
        }
    }
}

// 0x005479C0
void __fastcall MONSTERREGION_InitializeAll(void* pool,D2MonsterRegionStrc** regions,D2SeedStrc* seed,unsigned int lowSeed,unsigned char difficulty,int expansion)
{
 SEED_InitLowSeed(seed,lowSeed);
 ++regions;
 if(!DATATBLS_GetDifficultyLevelsTxtRecord(difficulty)) {
  FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x83);exit(-1);
 }
 for(int level=1;level<sgptDataTables->nLevelsTxtRecordCount;++level) {
  D2MonsterRegionStrc* region=(D2MonsterRegionStrc*)FOG_AllocPool(pool,sizeof(D2MonsterRegionStrc),gszMonsterRegion,0x87,0);
  memset(region,0,sizeof(D2MonsterRegionStrc));
  D2LevelsTxt* levels=DATATBLS_GetLevelsTxtRecord(level);
  region->nAct=levels->nAct;region->dwlevel=level;
  region->nMonsterCount=levels->dwMonDen[difficulty];region->nBossMin=levels->nMonUMin[difficulty];region->nBossMax=levels->nMonUMax[difficulty];
  region->nMonWander=levels->nWandering;region->nQuest=levels->nQuest;region->nTrapVariant=-1;region->nMonsterRegionLevel=-1;
  if(expansion) {region->nDungeonLevel=levels->wMonLvlEx[difficulty];region->nDungeonLevelEx=levels->wMonLvlEx[difficulty];}
  else {region->nDungeonLevel=(short)levels->wMonLvl[difficulty];region->nDungeonLevelEx=(short)levels->wMonLvl[difficulty];}
  MONSTERREGION_SelectMonsters(seed,difficulty>0,levels,region);
  D2MonRegDataStrc* entry=region->pMonData;
  for(int i=0;i<region->nMonCount;++i){MONSTERCHOOSE_GenerateComponentVariants(seed,entry,3);++entry;}
  *regions=region;++regions;
 }
}

// 0x00547B50
void __fastcall MONSTERREGION_FreeAll(void* pMemPool, D2MonsterRegionStrc** ppMonsterRegion)
{
    ++ppMonsterRegion;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; ++i, ++ppMonsterRegion)
    {
        if (*ppMonsterRegion)
        {
            FOG_FreeServerMemory(pMemPool, *ppMonsterRegion, ".\\MONSTER\\MonsterRegion.cpp", 197, 0);
        }
    }
}

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00547BB0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId)
{
    return ppMonsterRegion[nLevelId];
}

void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc* pSeed, D2MonRegDataStrc* pMonRegData, int nCount); // 0x005BDB20

static inline int MONSTERREGION_SanitizeMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x00547BC0
D2MonRegDataStrc* __fastcall MONSTERREGION_GetMonsterComponentData(D2MonsterRegionStrc** ppMonsterRegion, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    const short nClassId = UNITS_GetWeaponClass(pUnit);

    switch (MONSTERREGION_SanitizeMonsterId(nClassId))
    {
    case 195:
    case 196:
    case 294:
    case 296:
        return 0;
    default:
        break;
    }

    D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(ppMonsterRegion, DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pMonsterRegion)
    {
        return 0;
    }

    D2MonRegDataStrc* pMonsterRegionData = pMonsterRegion->pMonData;
    int nCounter = 0;
    while (nCounter < pMonsterRegion->nSpawnCount)
    {
        if ((unsigned short)pMonsterRegionData->nMonHcIdx == (unsigned short)nClassId)
        {
            return pMonsterRegionData;
        }

        ++pMonsterRegionData;
        ++nCounter;
    }

    if (nCounter >= 13)
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(nClassId);
    if (pMonStats2TxtRecord && pMonStats2TxtRecord->nTotalPieces > 2u)
    {
        pMonsterRegionData->nMonHcIdx = nClassId;
        ++pMonsterRegion->nSpawnCount;
        MONSTERCHOOSE_GenerateComponentVariants(&pUnit->pSeed, pMonsterRegionData, 3);
    }

    return pMonsterRegionData;
}

// 0x00547D20
void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame)
{
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);

    const int nSeed = (unsigned int)ITEMS_RollRandomNumberInline(&pGame->pGameSeed);
    SEED_InitLowSeed(&tSeed, nSeed);
    pGame->dwMonSeed = nSeed;
    MONSTERREGION_InitializeAll(pGame->pMemoryPool, pGame->pMonReg, &tSeed, nSeed, pGame->nDifficulty, pGame->bExpansion);
}

// 0x00547D90
void __fastcall MONSTERREGION_RegisterSpawnedMonster(D2MonsterRegionStrc** ppMonsterRegion, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int bToggleFlag)
{
    if (bToggleFlag)
    {
        MONSTER_ToggleSummonerFlag(pUnit, SUMMONER_FLAG, 1);
    }
    else
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[DUNGEON_GetLevelIdFromRoom(pRoom)];
        ++pMonsterRegion->dwMonSpawnCount;
    }
}

// 0x00547DD0
void __fastcall MONSTERREGION_UpdateSpawnCountForAlignmentChange(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit, int nPreviousAlignment, int nNewAlignment)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && !SUNIT_IsDead(pUnit) && !MONSTER_CheckSummonerFlag(pUnit, 2))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (pMonsterRegion && !pMonsterRegion->nQuest && nPreviousAlignment != nNewAlignment)
        {
            if (nPreviousAlignment == UNIT_ALIGNMENT_EVIL && (nNewAlignment == UNIT_ALIGNMENT_NEUTRAL || nNewAlignment == UNIT_ALIGNMENT_GOOD))
            {
                --pMonsterRegion->dwMonSpawnCount;
            }

            if (nNewAlignment == UNIT_ALIGNMENT_EVIL && nPreviousAlignment != UNIT_ALIGNMENT_UNASSIGNED)
            {
                ++pMonsterRegion->dwMonSpawnCount;
            }
        }
    }
}

// 0x00547E50
void __fastcall MONSTERREGION_RecordMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, SUMMONER_FLAG))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            ++pMonsterRegion->dwMonKillCount;
        }
    }
}

// 0x00547E90
void __fastcall MONSTERREGION_UndoMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, SUMMONER_FLAG))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (!STATLIST_GetUnitAlignment(pUnit))
        {
            --pMonsterRegion->dwMonKillCount;
        }
    }
}

// 0x00547ED0
void __fastcall MONSTERREGION_AdjustCountsForInactiveMonster(D2MonsterRegionStrc** ppMonRegion, int nLevelId1, int nLevelId2, int nAlignment, int bDead, int bExcludeFromCount, D2UnitStrc* pUnit)
{
    D2MonsterRegionStrc* pMonsterRegion1 = ppMonRegion[nLevelId1];
    D2MonsterRegionStrc* pMonsterRegion2 = ppMonRegion[nLevelId2];
    if (pUnit)
    {
        if (pMonsterRegion2 != pMonsterRegion1)
        {
            MONSTER_SetLevelId(pUnit, nLevelId1);
        }

        if (!bExcludeFromCount && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion2->dwMonSpawnCount;

            if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_OTHER))
            {
                --pMonsterRegion2->dwUniqueCount;
            }
        }
    }
    else
    {
        if (!bExcludeFromCount && !bDead && nAlignment == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion1->dwMonSpawnCount;
        }
    }
}

