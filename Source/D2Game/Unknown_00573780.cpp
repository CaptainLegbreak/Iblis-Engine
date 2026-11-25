#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"

#define UNIT_MONSTER 1
union D2SeedStrc;
struct D2MonsterDataStrc;
struct D2ComponentVariantStrc;
struct D2MonRegDataStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nParam); // 0x00540E60
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nType, int nFrame, int nParam1, int nParam2); // 0x005417D0

struct D2ComponentVariantStrc
{
    unsigned char nComponent[16];
};

struct D2MonRegDataStrc
{
    char unk0x00[3];
    unsigned char nComponentVariantsMax;
    D2ComponentVariantStrc nComponentVariants[1];
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

static inline int GetValidMonsterClass(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        return nClassId;
    return -1;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
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

static inline unsigned char* MONSTER_GetComponents(D2UnitStrc* pUnit)
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

// 0x005739D0
void __fastcall MONSTER_SetComponents(D2MonRegDataStrc* pMonRegData, D2UnitStrc* pUnit)
{
    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER)
    {
        return;
    }

    if (pMonRegData && pMonRegData->nComponentVariantsMax > 0)
    {
        const D2ComponentVariantStrc* pVariant = &pMonRegData->nComponentVariants[ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMonRegData->nComponentVariantsMax)];
        D2ComponentVariantStrc* pComponents = (D2ComponentVariantStrc*)MONSTER_GetComponents(pUnit);
        if (pComponents)
        {
            *pComponents = *pVariant;
        }
    }
    else
    {
        unsigned char* pComponents = MONSTER_GetComponents(pUnit);
        int i = 0;
        int nCount = 16;
        do
        {
            pComponents[i] = SEED_RollLimitedRandomNumber(&pUnit->pSeed, D2COMMON_11068_GetCompInfo(pUnit, i));
            ++i;
        }
        while (--nCount);
    }
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

int __fastcall MONSTER_HasComponents(D2UnitStrc* pUnit); // 0x00573AE0