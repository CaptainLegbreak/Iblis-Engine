#include "D2MonsterIds.h"
#include "D2CmpTileRecord.h"
#include "D2GameTypes.h"
#include "D2DrlgMaps.h"
#include "D2CmpTypes.h"
#include "D2LRUNode.h"

#include "D2StatIds.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2LevelTxt.h"

#include "D2Unicode.h"

#include "D2Path.h"

#include "D2UnitData.h"

#include "D2MonModes.h"

#define CHECK(p,line) if (!(p)) { FOG_DisplayHalt(text_006CC837,sub_00408090(),line); sub_00681E09(-1); }

struct Unicode;

struct D2MonsterDataStrc;

struct D2MonStatsTxt;

struct D2LevelsTxt;

struct Coord;

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[]; // 0x006CE268

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0


struct Coord { int x,y; };

extern Coord gaMonsterChainDirections[4]; // 0x006EA9D0

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char*,const char*,int); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int); // 0x00681E09

extern "C" const char text_006CC837[]; // 0x006CC837

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

#define MONSTATSFLAGINDEX_PRIMEEVIL 7

#define MONSTATSFLAGINDEX_LUNDEAD 11

#define MONSTATSFLAGINDEX_HUNDEAD 12

#define MONSTATSFLAGINDEX_DEMON 13

struct D2ItemsTxt;

struct D2DifficultyStatStrc;

union D2SeedStrc;

struct D2CoordStrc;

struct D2StaticPathStrc;

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent); // 0x00664860

struct D2DifficultyStatStrc { int stat; int numerator1; int denominator1; int numerator2; int denominator2; };

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int monsterId); // 0x00451F80

int __fastcall DATATBLS_ApplyRatio(int value, int numerator, int denominator); // 0x00483360

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* unit, int stat, int layer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* unit, int stat, int value, int layer); // 0x00627260

extern const D2DifficultyStatStrc gaClassicStatAdjustments[3]; // 0x006EA9F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall SKILLS_GetMonsterClassFromChain(int nMonsterId, int nChainSteps); // 0x0054DA60

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId); // 0x0063EC70

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

// 0x0063E810
void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pMonster, const Unicode* wszName)
{
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER && pMonster->pMonsterData)
    {
        if (wszName)
        {
            const int nLength = sub_00526800(wszName);
            pMonster->pMonsterData->wszMonName = (Unicode*)FOG_Alloc((nLength + 1) * sizeof(Unicode), ".\\Monsters\\MONSTERS.CPP", 195, 0);
            sub_005267E0(pMonster->pMonsterData->wszMonName, wszName);
        }
    }
}

static inline void MONSTERS_GetFlagEx31(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = pUnit ? (pUnit->dwFlags >> 31) & 1 : 0;
}

// 0x0063E860
int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return 0;
    }

    const int nMonsterId = pMonster->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[8 >> 3] & gdwBitMasks[8 & 7])
    {
        return 1;
    }

    if (pMonStatsTxtRecord->nMonStatsFlags[10 >> 3] & gdwBitMasks[10 & 7])
    {
        return 1;
    }

    int bFlag;
    MONSTERS_GetFlagEx31(pMonster, &bFlag);
    return bFlag != 0;
}

__forceinline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline D2SkillsTxt* __fastcall DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0063E8D0
int __stdcall MONSTERS_IsSandLeaper(D2UnitStrc* pMonster, int bAlwaysReturnFalse)
{
    int nClassId;
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        nClassId = pMonster->dwClassId;
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nClassId))
        {
            nClassId = pMonStatsTxtRecord->nBaseId;
        }
    }
    else
    {
        nClassId = -1;
    }

    if (nClassId == (sgptDataTables->nMonStatsTxtRecordCount <= MONSTER_SANDLEAPER1 ? -1 : MONSTER_SANDLEAPER1) && !bAlwaysReturnFalse)
    {
        return 1;
    }

    return 0;
}

// 0x0063E940
int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pMonster->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_DEMON >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_DEMON & 7]) != 0;
}

// 0x0063E990
int __stdcall MONSTERS_IsUndead(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pMonster->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_LUNDEAD >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_LUNDEAD & 7]
        || pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_HUNDEAD >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_HUNDEAD & 7];
}

// 0x0063E9F0
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster)
{
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        if (!pMonStatsTxtRecord)
        {
            pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pMonster->dwClassId);
        }

        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7];
        }
    }

    return 0;
}

// 0x0063EA40
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    return pMonster->dwAnimMode == MONMODE_DEATH || pMonster->dwAnimMode == MONMODE_DEAD;
}

// 0x0063EA70
int __stdcall MONSTERS_GetSpawnMode_XY(D2UnitStrc* pMonster, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY)
{
    if (bFromMonster && pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        if (D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pMonster->dwClassId))
        {
            const int nSpawn = pMonStatsTxtRecord->wSpawn;
            if (pX)
            {
                *pX = UNITS_GetXPosition(pMonster) + pMonStatsTxtRecord->nSpawnX;
            }

            if (pY)
            {
                *pY = CLIENTS_GetUnitY(pMonster) + pMonStatsTxtRecord->nSpawnY;
            }

            if (pSpawnMode)
            {
                *pSpawnMode = pMonStatsTxtRecord->nSpawnMode;
                if (*pSpawnMode < 0 || *pSpawnMode >= 16)
                {
                    *pSpawnMode = MONMODE_NEUTRAL;
                }
            }

            return nSpawn;
        }
    }
    else
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord && pSkillsTxtRecord->wSummon >= 0 && pSkillsTxtRecord->wSummon < sgptDataTables->nMonStatsTxtRecordCount)
        {
            if (pX)
            {
                *pX = UNITS_GetXPosition(pMonster);
            }

            if (pY)
            {
                *pY = CLIENTS_GetUnitY(pMonster);
            }

            if (pSpawnMode)
            {
                *pSpawnMode = (signed char)pSkillsTxtRecord->nSumMode;
                if (*pSpawnMode < 0 || *pSpawnMode >= 16)
                {
                    *pSpawnMode = MONMODE_NEUTRAL;
                }
            }

            return pSkillsTxtRecord->wSummon;
        }
    }

    return -1;
}

// 0x0063EBC0
void __stdcall sub_0063EBC0(int nUnused1, int nUnused2)
{
}

// 0x0063EBD0
unsigned char __stdcall MONSTERS_GetMaximalLightRadius(D2UnitStrc* pMonster)
{
    if (pMonster && (!pMonster ? 6 : pMonster->dwUnitType) == 1)
    {
        unsigned char nMaxLightRadius = 0;
        unsigned char* pComponents = pMonster && pMonster->dwUnitType == UNIT_MONSTER && pMonster->pMonsterData ? pMonster->pMonsterData->nComponent : 0;
        if (!pComponents)
            return 0;
        for (int i = 0; i < 16; ++i)
        {
            unsigned int nCode = D2Common_11069(pMonster, i, pComponents[i]);
            if (nCode && nCode != ' til' && nCode != ' dem' && nCode != ' yvh')
            {
                int nItemId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(nCode, &nItemId);
                if (pItemsTxtRecord && pItemsTxtRecord->nLightRadius > nMaxLightRadius)
                    nMaxLightRadius = pItemsTxtRecord->nLightRadius;
            }
        }
        return nMaxLightRadius;
    }
    return 0;
}

inline int MONSTERS_GetBaseIdFromMonsterIdInline(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }
    return pMonStatsTxtRecord->nBaseId;
}

// 0x0063EC70
int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId)
{
    int nMonstersInChain;

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    const unsigned char nNumNormalMonsters = pLevelsTxtRecord->nNumNormalMonsters;
    if (!nNumNormalMonsters)
    {
        return nMonsterId;
    }

    const int nClassId = MONSTERS_GetBaseIdFromMonsterIdInline(nMonsterId);
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }

    for (int i = 0; i < nNumNormalMonsters; ++i)
    {
        const int nMonster = pLevelsTxtRecord->wNormalMonsters[i];
        if (MONSTERS_GetBaseIdFromMonsterIdInline(nMonster) == nClassId)
        {
            return nMonster;
        }
    }

    int nNextInClass = pMonStatsTxtRecord->nNextInClass;
    DATATBLS_GetMonsterChainInfo(nMonsterId, &nMonstersInChain, 0);

    for (int i = 0; i < nMonstersInChain; ++i)
    {
        pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nNextInClass);
        if (!pMonStatsTxtRecord)
        {
            break;
        }
        if (pMonStatsTxtRecord->nLevel[0] > pLevelsTxtRecord->wMonLvlEx[0] + 1)
        {
            return nMonsterId;
        }
        nMonsterId = nNextInClass;
        nNextInClass = pMonStatsTxtRecord->nNextInClass;
    }

    return nMonsterId;
}

// 0x0063EDC0
int __stdcall MONSTERS_IsPrimeEvil(D2UnitStrc* pMonster)
{
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(pMonster->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_PRIMEEVIL >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_PRIMEEVIL & 7];
}

// 0x0063EE10
void __stdcall MONSTERS_GetChainDirectionDelta(D2UnitStrc* unit,int* x,int* y)
{
    const int type=unit?unit->dwUnitType:6;
    CHECK(type==1,0x2bc);
    int index;
    const int classId=unit?unit->dwClassId:-1;
    DATATBLS_GetMonsterChainInfo(classId,0,&index);
    CHECK(index<4,0x2c8);
    CHECK(index>=0,0x2c9);
    *x=gaMonsterChainDirections[index].x;
    *y=gaMonsterChainDirections[index].y;
}

// 0x0063EE90
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling)
{
    const unsigned int nUnitType = pHireling ? pHireling->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        const unsigned int nClassId = pHireling->dwClassId;
        switch (nClassId)
        {
        case MONSTER_ROGUEHIRE:
            return 1;

        case MONSTER_ACT2HIRE:
            return 2;

        case MONSTER_ACT3HIRE:
            return 3;

        case MONSTER_ACT5HIRE1:
        case MONSTER_ACT5HIRE2:
            return 4;

        default:
            break;
        }
    }

    return 0;
}

// 0x0063EEF0
void __stdcall MONSTERS_ApplyClassicScaling(D2UnitStrc* unit, int mode, unsigned char difficulty)
{
    if (mode || !difficulty)
        return;
    const int nType = unit ? unit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return;
    D2MonStatsTxt* record = DATATBLS_GetMonStatsTxtRecord(unit->dwClassId);
    if (!record || record->nAlign == 1)
        return;
    const D2DifficultyStatStrc* p = gaClassicStatAdjustments;
    for (int i = 0; i < 3; ++i, ++p)
    {
        int value = STATLIST_UnitGetStatValue(unit, p->stat, 0);
        int numerator;
        int denominator;
        if (difficulty == 1)
        {
            numerator = p->numerator1;
            denominator = p->denominator1;
        }
        else
        {
            numerator = p->numerator2;
            denominator = p->denominator2;
        }
        STATLIST_SetUnitStat(unit, p->stat, DATATBLS_ApplyRatio(value, numerator, denominator), 0);
    }
    STATLIST_SetUnitStat(unit, STAT_LEVEL, record->nLevel[0] + 25 * difficulty, 0);
}

inline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }

    return nMonsterId;
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x0063EFA0
void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc* pMonster, int* pMonsterId, int* pX, int* pY, int* pSpawnMode, int nChainSteps, int (__fastcall* pfnGetClassId)(D2UnitStrc*))
{
    int nChainId;
    D2DynamicPathStrc* pPath;
    D2SeedStrc* pSeed;
    int nBaseId = -1;

    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        nBaseId = MONSTERS_GetBaseIdFromMonsterIdInline(pMonster->dwClassId);
    }

    switch (MONSTERS_ValidateMonsterIdInline(nBaseId))
    {
    case 206:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(MONSTER_FOULCROW1), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 3;
        *pSpawnMode = 1;
        return;

    case 228:
        *pMonsterId = D2Common_11063(UNITS_GetRoom(pMonster), MONSTERS_ValidateMonsterIdInline(MONSTER_MUMMY1));
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 2;
        *pSpawnMode = 1;
        return;

    case 267:
        *pMonsterId = MONSTERS_ValidateMonsterIdInline(MONSTER_ZOMBIE2);
        pPath = pMonster->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pPath);
        *pSpawnMode = 8;
        return;

    case 284:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(MONSTER_SANDMAGGOT1), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster) + 8;
        *pY = CLIENTS_GetUnitY(pMonster);
        *pSpawnMode = 8;
        return;

    case 321:
        if (pMonster && pMonster->dwClassId == MONSTER_DEMONHOLE)
        {
            *pMonsterId = MONSTERS_ValidateMonsterIdInline(MONSTER_MEGADEMON6);
        }
        else
        {
            *pMonsterId = MONSTERS_ValidateMonsterIdInline(MONSTER_FALLEN1);
        }
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster);
        *pSpawnMode = 1;
        return;

    case 298:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(MONSTER_VILECHILD1), nChainId);
        pPath = pMonster->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pPath);
        *pSpawnMode = 1;
        return;

    case 334:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(MONSTER_MOSQUITO1), nChainId);
        *pX = UNITS_GetXPositionInline(pMonster) - 2;
        *pY = UNITS_GetYPositionInline(pMonster) - 2;
        *pSpawnMode = 1;
        return;

    case 484:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(MONSTER_MINION1), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 3;
        *pSpawnMode = 1;
        return;

    case 526:
    case 528:
        if (pfnGetClassId)
        {
            *pMonsterId = pfnGetClassId(pMonster);
        }
        else
        {
            *pMonsterId = MONSTERS_ValidateMonsterIdInline(0);
            D2_ASSERT(pfnGetClassId, 508);
        }
        *pX = CLIENTS_GetUnitX(pMonster) + 2;
        *pY = CLIENTS_GetUnitY(pMonster) + 2;
        *pSpawnMode = 1;
        return;

    case 537:
        DATATBLS_GetMonsterChainInfo(!pMonster ? -1 : pMonster->dwClassId, 0, &nChainId);
        *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(MONSTER_ANCIENTBARB1), nChainId);
        *pX = CLIENTS_GetUnitX(pMonster);
        *pY = CLIENTS_GetUnitY(pMonster) + 2;
        *pSpawnMode = 1;
        STATES_ToggleState(pMonster, 146, 1);
        return;

    case 544:
        pSeed = &pMonster->pSeed;
        if (*pMonsterId != MONSTERS_ValidateMonsterIdInline(MONSTER_BAALCLONE))
        {
            *pMonsterId = SKILLS_GetMonsterClassFromChain(MONSTERS_ValidateMonsterIdInline(MONSTER_BAALTENTACLE1), SEED_RollLimitedRandomNumber(pSeed, 2) + nChainSteps);
            *pX = CLIENTS_GetUnitX(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
            *pY = CLIENTS_GetUnitY(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
            *pSpawnMode = 4;
            return;
        }

        *pX = CLIENTS_GetUnitX(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
        *pY = CLIENTS_GetUnitY(pMonster) + SEED_RollLimitedRandomNumber(pSeed, 24) - 12;
        *pSpawnMode = 1;
        return;

    default:
        *pMonsterId = MONSTERS_ValidateMonsterIdInline(0);
        *pX = 0;
        *pY = 0;
        *pSpawnMode = 1;
        return;
    }
}

#include "gen/data/Source/D2Common/Monsters/MONSTERS.inc"
