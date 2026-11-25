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
// build: symbol _gaszLanguageNames 0x0073288C

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);       // 0x005A7C20

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                            // 0x006427F0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                         // 0x0061A1B0

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit);                                                 // 0x006259B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster);                                     // 0x005736A0

void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int nUnitGUID); // 0x00574250

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                         // 0x00624690

struct D2AiParamStrc;

void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);                    // 0x00555AE0

void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit);                      // 0x0057C980

void __fastcall AIGENERAL_FreeAiControl(D2GameStrc* pGame, D2AiControlStrc* pAiControl);                   // 0x0058F810

void __fastcall D2GAME_MONSTERMODE_FreeParams_6FC63020(D2GameStrc* pGame, D2AiParamStrc* pAiParam);        // 0x005A64D0

void __fastcall MONSTERAI_FreeMonsterInteract(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract);     // 0x00572BC0

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x00540EE0

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nParam); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nFrame, int nParam1, int nParam2); // 0x005417D0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

struct D2MonStats2Txt;

struct Data005734C0;

struct Unit005734C0;

struct Data005734E0;

struct Unit005734E0;

struct Data00573500;

struct Unit00573500;

struct Data00573520;

struct Unit00573520;

struct Data00573540;

struct Unit00573540;

struct Data00573570;

struct Unit00573570;

struct Data005734C0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };

struct Unit005734C0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005734C0* pData;
};

struct Data005734E0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };

struct Unit005734E0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data005734E0* pData; };

struct Data00573500 { unsigned char bUnknown00[0x58]; unsigned int dwValue58; };

struct Unit00573500 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00573500* pData;
};

struct Data00573520 {
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
    unsigned int dwValue58;
};

struct Unit00573520 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00573520* pData;
};

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
extern "C" __declspec(dllexport) void __fastcall sub_005734C0(Unit005734C0* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue54 = dwValue;
    }
}

// 0x005734E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_005734E0(Unit005734E0* pUnit) {
    Data005734E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 1;
    }
    return pData->dwValue54;
}

// 0x00573500
extern "C" __declspec(dllexport) void __fastcall sub_00573500(Unit00573500* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue58 = dwValue;
    }
}

// 0x00573520
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00573520(Unit00573520* pUnit) {
    Data00573520* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return pData->dwValue58;
}

// 0x00573540
extern "C" __declspec(dllexport) int __fastcall sub_00573540(Unit00573540* pUnit, unsigned short wMask) {
    Data00573540* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return 0;
    }
    return (unsigned short)(pData->wFlags5C & wMask) != 0;
}

// 0x00573570
extern "C" __declspec(dllexport) void __fastcall sub_00573570(Unit00573570* pUnit, unsigned short wMask, int bSet) {
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
int __fastcall MONSTER_SetVelocityAndPosition(D2GameStrc* pGame, D2UnitStrc* pMonster, int nX, int nY, int a5)
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
    return D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
}

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

#define EVENTTYPE_AITHINK 2
#define EVENTTYPE_STATREGEN 3

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
            D2GAME_MONSTERMODE_FreeParams_6FC63020(pGame, pMonsterData->pAiParam);
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
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    if (!pUnit) return;
    if (pUnit->dwAnimMode == 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
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
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 2, 0, 0);
        break;
    }
}

// 0x005738D0
void __fastcall MONSTER_DeleteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_AITHINK, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_STATREGEN, 0);
}

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

#pragma intrinsic(memset)


struct D2ActiveRoomStrc;

extern const int gnHpBonusTable[9]; // 0x006E1590

extern const int gnExperienceBonusTable[9]; // 0x006E15B4

int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame);                                                    // 0x00535790

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                    // 0x00611D30

#define UNIT_MONSTER 1

#define BONUS_TABLE_SIZE 9

#define HP_BONUS_STEP 50

#define HP_BONUS_BASE 2

#define XP_BONUS_BASE 130

#define MONALIGN_EVIL 0

int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

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

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

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

    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pMonster, nItemId, pGame, 4, dwQuality, 1, 1, dwILvl, 0, 0, 0);
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
                D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
            }
        }
    }
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

#include "gen/data/Source/D2Game/MONSTER/Monster.inc"
