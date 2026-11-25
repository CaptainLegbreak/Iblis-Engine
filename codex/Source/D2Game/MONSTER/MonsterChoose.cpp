#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2GameStrc.h"
#include "D2ItemsWorld.h"
struct D2MonPresetStrc { short nMonsterId; unsigned char nUnk02; unsigned char nCount; unsigned char nComponents[3][16]; };
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(expr,line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C390
static inline unsigned int RollRandom(D2SeedStrc* pSeed)
{
 unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
 pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
 pSeed->nLowSeed = (unsigned int)nSeed;
 return (unsigned int)nSeed;
}
static inline unsigned int RollLimited(D2SeedStrc* pSeed, int nMax)
{
 if (nMax <= 0) return 0;
 if ((nMax - 1) & nMax) return RollRandom(pSeed) % nMax;
 return RollRandom(pSeed) & (nMax - 1);
}
// 0x005BDB20
void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc* pSeed, D2MonPresetStrc* pPreset, int nCount)
{
 D2_ASSERT(pSeed, 0xa0);
 D2_ASSERT(pPreset, 0xa1);
 D2MonStats2Txt* pMonStats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(pPreset->nMonsterId);
 if (!pMonStats2Txt) return;
 const int nRemaining = (1 << pMonStats2Txt->nExtraComponentChoices) - pPreset->nCount;
 if (nCount > nRemaining) nCount = nRemaining;
 if (nCount <= 0) return;
 if (pPreset->nCount + nCount > 3) nCount = 3 - pPreset->nCount;
 if (nCount <= 0) return;
 unsigned char* pComponentCount = pMonStats2Txt->nComponentChoiceCounts;
 unsigned char* pNewComponents = pPreset->nComponents[pPreset->nCount];
 unsigned char* pBaseComponents = pPreset->nComponents[0];
 if (!pPreset->nCount)
 {
  for (int i=0; i<16; ++i)
  {
   if (pComponentCount[i] <= 1) pBaseComponents[i] = 0;
   else pBaseComponents[i] = (unsigned char)SEED_RollLimitedRandomNumber(pSeed, pComponentCount[i]);
  }
  ++pPreset->nCount;
  --nCount;
  pNewComponents += 16;
 }
 if (!nCount) return;
 unsigned char nIndices[16];
 int nParts = 0;
 for (unsigned char i = 0; i<16; ++i)
 {
  if (pComponentCount[i] > 1) nIndices[nParts++] = i;
 }
 unsigned char nFirst, nSecond;
 if (nParts == 1) nFirst = nSecond = nIndices[0];
 else if (nParts > 1)
 {
  int nIndex = SEED_RollLimitedRandomNumber(pSeed, nParts);
  nFirst = nIndices[nIndex];
  nIndices[nIndex] = nIndices[--nParts];
  nSecond = nIndices[SEED_RollLimitedRandomNumber(pSeed, nParts)];
 }
 else return;
 if (nCount > 0)
 {
 const int nFirstIndex = nFirst;
 int nLeft = nCount;
 do
 {
  memcpy(pNewComponents, pBaseComponents, 16);
  int nTries=3;
  int bDuplicate;
  do
  {
   pNewComponents[nFirstIndex] = (unsigned char)RollLimited(pSeed, pComponentCount[nFirstIndex]);
   if (nFirst != nSecond) pNewComponents[nSecond] = (unsigned char)RollLimited(pSeed, pComponentCount[nSecond]);
   bDuplicate=0;
   for (int j=0; j<pPreset->nCount; ++j)
   {
    if (!memcmp(pNewComponents, pPreset->nComponents[j], 16))
    {
     --nTries;
     bDuplicate=1;
    }
   }
  } while (bDuplicate && nTries);
  ++pPreset->nCount;
  pNewComponents += 16;
 } while (--nLeft);
 }
}

#define MONSTATSFLAGINDEX_PLACESPAWN 23

struct D2MonRegDataStrc;

struct D2LevelsTxt;

struct D2MonStatsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005BDE80
int __fastcall MONSTERCHOOSE_GetPresetMonsterId(D2GameStrc* pGame, D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom, D2MonStatsTxt** ppMonStatsTxtRecord, unsigned char nChance, int bSpawnUMon)
{
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    if (bSpawnUMon && pGame->nDifficulty == 0)
    {
        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(pMonsterRegion->dwlevel);
        if (pLevelsTxtRecord->nNumUniqueMonsters)
        {
            const int nMonsterId = pLevelsTxtRecord->wUniqueMonsters[ITEMS_RollLimitedRandomNumber(pSeed, pLevelsTxtRecord->nNumUniqueMonsters)];
            *ppMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
            return nMonsterId;
        }

        *ppMonStatsTxtRecord = 0;
        return 0;
    }

    if (!pMonsterRegion->nMonCount)
    {
        *ppMonStatsTxtRecord = 0;
        return 0;
    }

    int nRarityRoll = ITEMS_RollLimitedRandomNumber(pSeed, pMonsterRegion->nTotalRarity) + 1;
    D2MonRegDataStrc* pMonRegData = pMonsterRegion->pMonData;
    for (int i = 0; i < pMonsterRegion->nMonCount; ++i)
    {
        nRarityRoll -= pMonRegData->nRarity;
        if (nRarityRoll <= 0)
        {
            break;
        }

        ++pMonRegData;
    }

    short nMonsterId = pMonRegData->nMonHcIdx;
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    if (pMonStatsTxtRecord && pMonStatsTxtRecord->wSpawn >= 0 && pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_PLACESPAWN >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_PLACESPAWN & 7])
    {
        const unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        pSeed->nLowSeed = (unsigned int)lSeed;
        if ((int)((unsigned int)lSeed % 100) > nChance)
        {
            nMonsterId = pMonStatsTxtRecord->wSpawn;
        }
    }

    *ppMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nMonsterId);
    return nMonsterId;
}

struct D2SeedOwnerStrc;

struct D2SeedOwnerStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

extern void* gpDiamondMonsterFormation; // 0x007415F0

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BDFF0
void* __fastcall MONSTERCHOOSE_RollFormation(D2SeedOwnerStrc* pOwner)
{
    D2SeedStrc* pSeed = pOwner ? &pOwner->pSeed : 0;
    SEED_RollRandomNumber(pSeed);
    return gpDiamondMonsterFormation;
}

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    return (unsigned int)SEED_RollRandomNumber(pSeed);
}

static inline D2SeedStrc* DUNGEON_GetRoomSeed(D2ActiveRoomStrc* pRoom)
{
    return pRoom ? &pRoom->pSeed : 0;
}

// 0x005BE020
int __fastcall MONSTERCHOOSE_GetBossSpawnType(D2MonsterRegionStrc* pMonsterRegion, D2ActiveRoomStrc* pRoom)
{
    const unsigned char nBossMax = pMonsterRegion->nBossMax;
    const unsigned char nUniqueCount = pMonsterRegion->dwUniqueCount;
    if (nUniqueCount < pMonsterRegion->nBossMin)
    {
        const int nDivisor = pMonsterRegion->nMonsterRegionLevel;
        if (nDivisor)
        {
            const int nFactor = pMonsterRegion->nCount;
            if ((int)(ITEMS_RollRandomNumber(DUNGEON_GetRoomSeed(pRoom)) % 100) < 100 * nFactor / nDivisor)
            {
                return 0;
            }
        }
    }

    if (nUniqueCount < nBossMax && (int)(ITEMS_RollRandomNumber(DUNGEON_GetRoomSeed(pRoom)) % 100) <= 5)
    {
        return 0;
    }

    if ((int)(ITEMS_RollRandomNumber(DUNGEON_GetRoomSeed(pRoom)) % 100) > 35)
    {
        return 2;
    }

    return 1;
}

#include "gen/data/Source/D2Game/MONSTER/MonsterChoose.inc"
