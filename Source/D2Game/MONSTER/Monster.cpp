#include "D2GameEvents.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2LanguageNames.h"
#include "D2StatIds.h"
#include "D2CommonApi.h"
#include "FogApi.h"
#include "D2MonStatsInit.h"
#include "D2Records.h"
#include "D2MonModes.h"
#include "D2ItemsWorld.h"

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"


struct D2AiParamStrc;


void __fastcall AIGENERAL_FreeAiControl(D2GameStrc* pGame, D2AiControlStrc* pAiControl);                   // 0x0058F810

void __fastcall D2GAME_MONSTERMODE_FreeParams(D2GameStrc* pGame, D2AiParamStrc* pAiParam);        // 0x005A64D0

void __fastcall MONSTERAI_FreeMonsterInteract(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract);     // 0x00572BC0




inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

struct D2MonStats2Txt;

struct Data00573540;

struct Unit00573540;

struct Data00573570;

struct Unit00573570;

struct Data00573540 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned short wFlags5C;
};

struct Unit00573540 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00573540* pData;
};

struct Data00573570 { unsigned char bUnknown00[0x5C]; unsigned short wFlags5C; };

struct Unit00573570 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00573570* pData; };

// 0x005734C0
void __fastcall MONSTER_SetAiState(D2UnitStrc* pUnit, int nAiState) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        pUnit->pMonsterData->dwAiState = nAiState;
    }
}

// 0x005734E0
int __fastcall MONSTER_GetAiState(D2UnitStrc* pUnit) {
    D2MonsterDataStrc* pData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pData) {
        return 1;
    }
    return pData->dwAiState;
}

// 0x00573500
void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        pUnit->pMonsterData->nLevelId = nLevelId;
    }
}

// 0x00573520
int __fastcall sub_00573520(D2UnitStrc* pUnit) {
    D2MonsterDataStrc* pData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pData) {
        return 0;
    }
    return pData->nLevelId;
}

// 0x00573540
extern "C" __declspec(dllexport) int __fastcall MONSTER_CheckSummonerFlag(Unit00573540* pUnit, unsigned short wMask) {
    Data00573540* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags5C & wMask) != 0;
}

// 0x00573570
extern "C" __declspec(dllexport) void __fastcall MONSTER_ToggleSummonerFlag(Unit00573570* pUnit, unsigned short wMask, int bSet) {
    if (pUnit && pUnit->nType == 1) {
        Data00573570* pData = pUnit->pData;
        if (pData) {
            if (bSet) {
                pData->wFlags5C |= wMask;
            } else {
                pData->wFlags5C &= ~wMask;
            }
        }
    }
}

// 0x005735A0
int __fastcall MONSTER_SetVelocityAndPosition(D2GameStrc* pGame, D2UnitStrc* pMonster, int nX, int nY, int bUnusedSkipRoomUpdate)
{
    int nAnimMode;
    D2MonStatsTxt* pMonStatsTxtRecord;
    if (!pMonster)
    {
        nAnimMode = 0;
        pMonStatsTxtRecord = 0;
    }
    else
    {
        nAnimMode = pMonster->dwAnimMode;
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pMonster->dwClassId);
    }

    PATH_SetVelocity(pMonster->pDynamicPath, pMonStatsTxtRecord->nVelocity << 8, ".\\MONSTER\\Monster.cpp", 383);
    UnitUpdateAnimRateAndVel(pMonster, ".\\MONSTER\\Monster.cpp", 384);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pMonster, nAnimMode, &modeChange);
    modeChange.nX = nX;
    modeChange.nY = nY;
    return D2GAME_ModeChange(pGame, &modeChange, 1);
}


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540


// 0x00573640
void __fastcall MONSTER_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pMonster = pGame->pUnitList[1][i];
        while (pMonster)
        {
            D2UnitStrc* pNext = SUNIT_GetNextUnitFromList(pMonster);
            pGame->pUnitList[1][i] = pNext;
            SUNIT_RemoveUnit(pGame, pMonster);
            pMonster = pNext;
        }
    }
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

// 0x005736A0
void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    SUNITDMG_FreeAttackerCombatList(pGame, pMonster);

    if (!pMonster || !sub_E09_CheckMonStatsFlag(pMonster->dwClassId, 9))
    {
        SUNIT_RemoveAllItemsFromInventory(pGame, pMonster);
        INVENTORY_FreeInventory(pMonster->pInventory);
    }

    if (pMonster->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pMonster->pHoverText);
    }

    if (pMonster->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
        if (pMonsterData)
        {
            AIGENERAL_FreeAiControl(pGame, pMonsterData->pAiControl);
            D2GAME_MONSTERMODE_FreeParams(pGame, pMonsterData->pAiParam);
            MONSTERAI_FreeMonsterInteract(pGame, pMonsterData->pMonInteract);
        }
    }

    EVENT_FreeUnitTimers(pGame, pMonster);
}

// 0x00573750
void __fastcall MONSTER_ClearTargetIfMatches(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget == SUNIT_GetTargetUnit(pGame, pUnit))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        PATH_SetTargetUnit(pUnit->pDynamicPath, 0);
    }
}

union D2SeedStrc;

struct D2MonsterDataStrc;

struct D2ComponentVariantStrc;

struct D2MonRegDataStrc;

static inline int GetValidMonsterClass(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return nClassId;
    return -1;
}

// 0x00573780
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete(pGame, pUnit, 2, 0);
    if (!pUnit) return;
    if (pUnit->dwAnimMode == 1)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
    }
    else if (pUnit->dwAnimMode == 12 || pUnit->dwAnimMode == 0)
    {
        return;
    }
    switch (GetValidMonsterClass(CUNIT_GetMonsterBaseId(pUnit)))
    {
    case 110:
    case 118:
    case 136:
    case 247:
        D2GAME_EVENTS_Delete(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
        break;
    }
}

// 0x005738D0
void __fastcall MONSTER_DeleteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_STATREGEN, 0);
}

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

#pragma intrinsic(memset)


struct D2ActiveRoomStrc;

extern const int gnHpBonusTable[9]; // 0x006E1590

extern const int gnExperienceBonusTable[9]; // 0x006E15B4


#define UNIT_MONSTER 1

#define BONUS_TABLE_SIZE 9

#define HP_BONUS_STEP 50

#define HP_BONUS_BASE 2

#define XP_BONUS_BASE 130

#define MONALIGN_EVIL 0

int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

// noinline: MONSTER_GetPlayerCountBonus (0x00573930) calls MONSTER_GetHpBonus (0x005738F0); the image calls it out of line there.
// 0x005738F0
__declspec(noinline) int __fastcall MONSTER_GetHpBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnHpBonusTable[nPlayerCount];
    }

    return (nPlayerCount - HP_BONUS_BASE) * HP_BONUS_STEP;
}

int __fastcall MONSTER_GetExperienceBonus(int nPlayerCount); // 0x00573910

// noinline: MONSTER_GetPlayerCountBonus (0x00573930) calls MONSTER_GetExperienceBonus (0x00573910); the image calls it out of line there.
// 0x00573910
__declspec(noinline) int __fastcall MONSTER_GetExperienceBonus(int nPlayerCount)
{
    if (nPlayerCount < BONUS_TABLE_SIZE)
    {
        return gnExperienceBonusTable[nPlayerCount];
    }

    return 2 * (5 * nPlayerCount + XP_BONUS_BASE);
}

static inline D2MonsterDataStrc* MONSTER_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

// 0x00573930
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc* pGame, D2PlayerCountBonusStrc* pPlayerCountBonus, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster)
{
    if (!pPlayerCountBonus)
    {
        return;
    }

    memset(pPlayerCountBonus, 0x00, sizeof(*pPlayerCountBonus));
    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterDataInline(pMonster);
    if (!pMonsterData)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = (D2MonStatsTxt*)pMonsterData->pMonstatsTxt;
    if (!pMonStatsTxt)
    {
        return;
    }

    if (pMonStatsTxt->nAlign == MONALIGN_EVIL)
    {
        int nPlayerCount = PLAYER_GetPlayerCount(pGame);
        if (nPlayerCount < 1)
        {
            nPlayerCount = 1;
        }
        pPlayerCountBonus->nHp = MONSTER_GetHpBonus(nPlayerCount);
        pPlayerCountBonus->nExperience = MONSTER_GetExperienceBonus(nPlayerCount);
        pPlayerCountBonus->nPlayerCount = nPlayerCount;
    }
    else
    {
        pPlayerCountBonus->nPlayerCount = 1;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (pGame->nDifficulty >= 3)
    {
        pGame->nDifficulty = 2;
    }

    pPlayerCountBonus->nMonsterSkillBonus = pDifficultyLevelsTxtRecord->dwMonsterSkillBonus;
    pPlayerCountBonus->nDifficulty = pGame->nDifficulty;
}

static inline unsigned char* sub_00573AE0_GetComponents(D2UnitStrc* pUnit)
{
	if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
	{
		return 0;
	}

	D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
	if (!pMonsterData)
	{
		return 0;
	}

	return pMonsterData->nComponent;
}

struct D2ComponentVariantStrc
{
    unsigned char nComponent[16];
};

static inline unsigned int MONSTER_RollComponentSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int MONSTER_RollLimitedComponent(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return MONSTER_RollComponentSeed(pSeed) % nMax;
    }
    return MONSTER_RollComponentSeed(pSeed) & (nMax - 1);
}

// 0x005739D0
void __fastcall MONSTER_SetComponents(D2MonRegDataStrc* pMonRegData, D2UnitStrc* pUnit)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
        return;
    }

    if (pMonRegData && pMonRegData->nComponentVariantsMax > 0)
    {
        const D2ComponentVariantStrc* pVariants = (const D2ComponentVariantStrc*)pMonRegData->nComponentVariants;
        const D2ComponentVariantStrc* pVariant = &pVariants[ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMonRegData->nComponentVariantsMax)];
        D2ComponentVariantStrc* pComponents = (D2ComponentVariantStrc*)sub_00573AE0_GetComponents(pUnit);
        if (pComponents)
        {
            *pComponents = *pVariant;
        }
    }
    else
    {
        unsigned char* pComponents = sub_00573AE0_GetComponents(pUnit);
        int i = 0;
        int nCount = 16;
        do
        {
            pComponents[i] = MONSTER_RollLimitedComponent(&pUnit->pSeed, D2COMMON_11068_GetCompInfo(pUnit, i));
            ++i;
        }
        while (--nCount);
    }
}

// 0x00573AE0
int __fastcall MONSTER_HasComponents(D2UnitStrc* pUnit)
{
	const unsigned char* pComponents = sub_00573AE0_GetComponents(pUnit);
	int i = 0;
	do
	{
		if (*pComponents)
		{
			return 1;
		}
		++i;
		++pComponents;
	}
	while (i < 16);

	return 0;
}

struct D2ItemsTxt;

struct D2MonsterItemCodeStrc;

struct D2MonsterItemCodeStrc
{
    unsigned int nItemCode;
    unsigned char nBodyLoc;
};



// 0x00573B20
void __fastcall MONSTERAI_CreateAndEquipItem(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterItemCodeStrc* pItemCode, int dwILvl, int dwQuality)
{
    const int nType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    if (!pMonster->pInventory)
    {
        INVENTORY_AllocInventory(0, pMonster);
    }

    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(pItemCode->nItemCode, &nItemId))
    {
        return;
    }

    D2UnitStrc* pItem = D2GAME_CreateItemUnit(pMonster, nItemId, pGame, 4, dwQuality, 1, 1, dwILvl, 0, 0, 0);
    if (!pItem)
    {
        return;
    }

    ITEMS_SetItemFlag(pItem, 0x1000, 1);
    ITEMS_SetBodyLocation(pItem, pItemCode->nBodyLoc);
    if (pItemCode->nBodyLoc == 0)
    {
        return;
    }

    {
        const int nItemGUID = pItem->dwUnitId;
        int nUnused;
        if (!ITEMMODE_EquipCursorItem(pGame, pMonster, nItemGUID, ITEMS_GetBodyLocation(pItem), 1, &nUnused))
        {
            SUNIT_RemoveUnit(pGame, pItem);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pItem), 0);
        }
    }
}

// 0x00573C00
void __fastcall MONSTER_ResetMonsterModesInLevel(D2GameStrc* pGame, int nClassId1, int nClassId2, int nLevelId)
{
    D2DrlgActStrc* pAct = pGame->pAct[DRLG_GetActNoFromLevelId(nLevelId)];
    if (!pAct)
    {
        return;
    }

    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (nLevelId && DUNGEON_GetLevelIdFromRoom(pRoom) != nLevelId)
        {
            continue;
        }

        D2UnitStrc* pNext;
        for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
        {
            pNext = pUnit->ptRoomNext;
            if (pUnit->dwUnitType == UNIT_MONSTER && (pUnit->dwClassId == nClassId1 || pUnit->dwClassId == nClassId2) && !SUNIT_IsDead(pUnit) && !STATLIST_GetUnitAlignment(pUnit))
            {
                D2ModeChangeStrc modeChange;
                MONSTERMODE_GetModeChangeInfo(pUnit, 0, &modeChange);
                D2GAME_ModeChange(pGame, &modeChange, 1);
            }
        }
    }
}

struct D2MonsterModeDataStrc;

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2MonPropTxt
{
    int nId; // 0x00
    D2PropertyStrc pProperties[3][6]; // 0x04
    unsigned char nChance[3][6]; // 0x124
};

void __fastcall MONSTER_SetComponents(D2MonRegDataStrc* pMonRegData, D2UnitStrc* pUnit);                   // 0x005739D0
D2MonStats2Txt* __fastcall sub_00573470_GetMonStats2Record(int nMonsterId);                                                    // 0x00573470
D2InventoryStrc* __fastcall SUNITPROXY_GetNpcInventory(D2GameStrc* pGame, int nNpc);                        // 0x00536B20
void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOther, int nLayerStatId, int nPreviousValue, int nNewValue); // 0x0055B800
void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove);            // 0x0056DEB0
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }
D2AiControlStrc* __fastcall AIGENERAL_AllocAiControl(D2GameStrc* pGame);                                    // 0x0058EBC0
D2MonsterModeDataStrc* __fastcall MONSTERMODE_AllocParams(D2GameStrc* pGame);                               // 0x005A6490
D2MonsterInteractStrc* __fastcall MONSTERAI_AllocMonsterInteract(D2GameStrc* pGame);                        // 0x00572BA0
D2MonRegDataStrc* __fastcall MONSTERREGION_GetMonsterComponentData(D2MonsterRegionStrc** ppMonsterRegion, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit); // 0x00547BC0

static inline void MONSTER_SetComponent(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        pUnit->pMonsterData->nComponent[nComponent] = nValue;
    }
}

static __forceinline D2MonStats2Txt* MONSTER_GetMonStats2TxtRecord(int nMonsterId)
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

static __forceinline int MONSTER_GetRegeneration(int nLife, int nRegen)
{
    D2_ASSERT(nRegen >= 0, 222);
    D2_ASSERT(!(nRegen & 0xFFFFF000), 223);
    int nResult = 0;
    if (nRegen)
    {
        if (nLife > 0x7FFFFFFF / nRegen)
        {
            nResult = (nLife >> 12) * nRegen;
        }
        else
        {
            nResult = (nLife * nRegen) >> 12;
        }
    }
    return nResult;
}

static inline unsigned __int64 MONSTER_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

// 0x00573CB0
static void __stdcall MONSTER_InitializeStats(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2MonRegDataStrc* pMonRegData, D2UnitStrc* pMonster)
{
    if (!pMonster)
    {
        return;
    }

    const int nUnitType = !pMonster ? UNIT_INVALID : pMonster->dwUnitType;
    const int nClassId = pMonster->dwClassId;
    if (nUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pMonster->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = (D2MonStatsTxt*)pMonsterData->pMonstatsTxt;
    if (!pMonStatsTxt)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2Txt = MONSTER_GetMonStats2TxtRecord(pMonster->dwClassId);
    if (!pMonStats2Txt)
    {
        return;
    }

    MONSTER_SetComponents(pMonRegData, pMonster);
    switch (nClassId < sgptDataTables->nMonStatsTxtRecordCount ? nClassId : -1)
    {
    case 311:
        MONSTER_SetComponent(pMonster, 10, (unsigned char)SEED_RollLimitedRandomNumber(&pMonster->pSeed, 4));
        break;
    case 312:
    {
        const unsigned char nComponent = (unsigned char)SEED_RollLimitedRandomNumber(&pMonster->pSeed, 4);
        MONSTER_SetComponent(pMonster, 10, nComponent);
        MONSTER_SetComponent(pMonster, 11, nComponent);
        break;
    }
    }

    D2PlayerCountBonusStrc tBonus;
    MONSTER_GetPlayerCountBonus(pGame, &tBonus, pRoom, pMonster);

    int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    if (MONSTERS_GetHirelingTypeId(pMonster))
    {
        nDifficulty = 0;
    }

    int nPlayerCount = 1;
    if (tBonus.nPlayerCount >= 1)
    {
        nPlayerCount = tBonus.nPlayerCount;
    }

    int nLevel = pMonStatsTxt->nLevel[nDifficulty];
    if (pGame->bExpansion && nDifficulty > 0 && !(pMonStatsTxt->nMonStatsFlags[0] & gdwBitMasks[2]) && !(pMonStatsTxt->nMonStatsFlags[0] & gdwBitMasks[6]))
    {
        nLevel = DATATBLS_GetMonsterLevelInArea(DUNGEON_GetLevelIdFromRoom(pRoom), nDifficulty, pGame->bExpansion);
    }

    STATLIST_AllocStatListEx(pMonster, 0, D2GAME_ITEMMODE_ServerStatlistCallback, pGame);
    STATLIST_SetUnitStat(pMonster, STAT_LEVEL, nLevel, 0);
    STATLIST_SetUnitStat(pMonster, STAT_MONSTER_PLAYERCOUNT, nPlayerCount, 0);
    STATLIST_SetUnitStat(pMonster, STAT_DAMAGERESIST, pMonStatsTxt->wResDm[nDifficulty], 0);
    STATLIST_SetUnitStat(pMonster, STAT_MAGICRESIST, pMonStatsTxt->wResMa[nDifficulty], 0);
    STATLIST_SetUnitStat(pMonster, STAT_FIRERESIST, pMonStatsTxt->wResFi[nDifficulty], 0);
    STATLIST_SetUnitStat(pMonster, STAT_LIGHTRESIST, pMonStatsTxt->wResLi[nDifficulty], 0);
    STATLIST_SetUnitStat(pMonster, STAT_COLDRESIST, pMonStatsTxt->wResCo[nDifficulty], 0);
    STATLIST_SetUnitStat(pMonster, STAT_POISONRESIST, pMonStatsTxt->wResPo[nDifficulty], 0);
    STATLIST_SetUnitStat(pMonster, STAT_TOBLOCK, pMonStatsTxt->nBlock[nDifficulty], 0);
    STATLIST_SetUnitStat(pMonster, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pMonster, STAT_VELOCITYPERCENT, 75, 0);
    STATLIST_SetUnitStat(pMonster, STAT_OTHER_ANIMRATE, 100, 0);
    STATLIST_SetUnitStat(pMonster, STAT_LAST_SENT_HP_PCT, 128, 0);

    const int bGameType = pGame->nGameType || pGame->dwGameType;
    D2MonStatsInitStrc tMonStatsInit;
    memset(&tMonStatsInit, 0, sizeof(tMonStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(!pMonster ? -1 : pMonster->dwClassId, bGameType, nDifficulty, nLevel, 7, &tMonStatsInit);

    int nLife = ITEMS_RollLimitedRandomNumber(&pMonster->pSeed, tMonStatsInit.nMaxHP - tMonStatsInit.nMinHP + 1) + tMonStatsInit.nMinHP;
    nLife += DATATBLS_ApplyRatio(nLife, tBonus.nHp, 100);
    if (nLife >= 0x800000)
    {
        nLife = 0x7FFFFF;
    }

    const int nShiftedLife = nLife << 8;
    STATLIST_SetUnitStat(pMonster, STAT_MAXHP, nShiftedLife, 0);
    STATLIST_SetUnitStat(pMonster, STAT_HITPOINTS, nShiftedLife, 0);
    STATLIST_SetUnitStat(pMonster, STAT_ARMORCLASS, tMonStatsInit.nAC, 0);
    STATLIST_SetUnitStat(pMonster, STAT_EXPERIENCE, tMonStatsInit.nExp + DATATBLS_ApplyRatio(tMonStatsInit.nExp, tBonus.nExperience, 100), 0);
    STATLIST_SetUnitStat(pMonster, STAT_HPREGEN, MONSTER_GetRegeneration(nShiftedLife, pMonStatsTxt->nDamageRegen), 0);
    MONSTERS_ApplyClassicScaling(pMonster, pGame->bExpansion, pGame->nDifficulty);

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 1, 0, UNIT_MONSTER, !pMonster ? -1 : pMonster->dwUnitId);
    D2COMMON_10475_PostStatToStatList(pMonster, (D2StatListExStrc*)pStatList, 1);

    if (pMonStatsTxt->nMonStatsFlags[3] & (unsigned char)gdwBitMasks[0])
    {
        if (pMonStatsTxt->nMonStatsFlags[1] & (unsigned char)gdwBitMasks[1])
        {
            pMonster->pInventory = SUNITPROXY_GetNpcInventory(pGame, CUNIT_ValidateMonsterId(nClassId));
        }
        else
        {
            INVENTORY_AllocInventory(0, pMonster);
        }
    }

    pMonster->pSkills = SKILLS_AllocSkillList(pGame->pMemoryPool);
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxt->nSkill[i] >= 0)
        {
            const char nSkillLevel = pMonStatsTxt->nSkLvl[i];
            if (nSkillLevel > 0)
            {
                D2GAME_SetSkills(pMonster, pMonStatsTxt->nSkill[i], tBonus.nMonsterSkillBonus + nSkillLevel, 0);
                const signed char nSkillMode = pMonStatsTxt->nSkillMode[i];
                if (nSkillMode >= 0)
                {
                    SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pMonster, pMonStatsTxt->nSkill[i]), nSkillMode);
                }
            }
        }
    }

    D2COMMON_11062_Return((int)pMonster, tBonus.nMonsterSkillBonus);
    if (pMonStats2Txt->nFlags[1] & (unsigned char)gdwBitMasks[1])
    {
        pMonster->dwFlags |= 4;
    }
    if (pMonStatsTxt->nMonStatsFlags[2] & (unsigned char)gdwBitMasks[3])
    {
        pMonster->dwFlags |= 0x40000000;
    }

    D2MonPropTxt* pMonPropTxt = (D2MonPropTxt*)sub_00573470_GetMonStats2Record(pMonster->dwClassId);
    if (pMonPropTxt)
    {
        for (int i = 0; i < 6; ++i)
        {
            D2PropertyStrc* pProperty = &pMonPropTxt->pProperties[nDifficulty][i];
            if (pProperty->nProperty < 0)
            {
                break;
            }

            if (pMonPropTxt->nChance[nDifficulty][i] <= 0 || (int)((unsigned int)MONSTER_RollRandomNumber(&pMonster->pSeed) % 100) < pMonPropTxt->nChance[nDifficulty][i])
            {
                D2COMMON_11292_ItemAssignProperty(0, 0, pMonster, 0, 0, 0, pProperty, 0, 64, 0);
            }
        }
    }

    SKILLS_EquipMonsterFromTable(pGame, 0, pMonster, -1, nLevel, nLevel, 1);
}

static inline D2MonStatsTxt* MONSTER_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

static inline D2AiControlStrc* MONSTER_GetAiControl(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterDataInline(pUnit);
    if (pMonsterData)
    {
        return pMonsterData->pAiControl;
    }
    return 0;
}

// 0x00574250
void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMonster, int nUnitGUID)
{
    if (pMonster)
    {
        pMonster->dwUnitId = nUnitGUID;
        pMonster->dwFlags |= 0x0A;
    }

    D2GAME_DeleteTimersOnUnit(pGame, pMonster);

    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterDataInline(pMonster);
    pMonsterData->pAiControl = AIGENERAL_AllocAiControl(pGame);
    pMonsterData->pAiParam = (D2AiParamStrc*)MONSTERMODE_AllocParams(pGame);
    pMonsterData->pMonInteract = MONSTERAI_AllocMonsterInteract(pGame);
    pMonsterData->pMonstatsTxt = MONSTER_GetMonStatsTxtRecord(pMonster);

    MONSTER_InitializeStats(pGame, pRoom, MONSTERREGION_GetMonsterComponentData(pGame->pMonReg, pRoom, pMonster), pMonster);
    AITHINK_ExecuteAiFn(pGame, pMonster, MONSTER_GetAiControl(pMonster), 0);

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nAnimMode;
    if (pMonster)
    {
        D2MonsterDataStrc* pData = MONSTER_GetMonsterDataInline(pMonster);
        if (pData)
        {
            pData->nLevelId = nLevelId;
        }

        nAnimMode = pMonster->dwAnimMode;
        if (nAnimMode != MONMODE_DEATH && nAnimMode != MONMODE_DEAD)
        {
            QUESTS_AttachLevelChainRecord(pGame, pMonster, pRoom, 1);
            SUNIT_InitializeAnimation(pMonster);
            return;
        }
    }
    else
    {
        nAnimMode = 0;
    }

    SUNIT_SetCombatMode(pGame, pMonster, nAnimMode);
    SUNIT_InitializeAnimation(pMonster);
}

// 0x00574370
int __fastcall MONSTER_Reinitialize(D2GameStrc* pGame, D2UnitStrc* pUnit, int nClassId, int nMode)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == 1)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        if (!(pMonStatsTxtRecord->nMonStatsFlags[25 >> 3] & gdwBitMasks[25 & 7]))
        {
            return 0;
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        const int nUnitGUID = pUnit->dwUnitId;
        MONSTER_Free(pGame, pUnit);

        pUnit->dwClassId = nClassId;
        MONSTER_Initialize(pGame, pRoom, pUnit, nUnitGUID);
        UNITS_ChangeAnimMode(pUnit, nMode);
        return 1;
    }

    return 0;
}

extern const int gnHpBonusTable[9] = { 0, 0, 50, 100, 150, 200, 250, 300, 350 }; // 0x006E1590

extern const int gnExperienceBonusTable[9] = { 0, 0, 50, 100, 150, 200, 250, 300, 350 }; // 0x006E15B4
