#include "D2MonsterIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"


enum
{
    ANIMSEQ_EVENT_MELEE_ATTACK = 1,
    ANIMSEQ_EVENT_MISSILE_ATTACK = 2,
};

enum
{
    ACT_II = 1,
};


extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnMonStatsMissileOffsets[];                                                             // 0x006EA938
extern const unsigned int* gpSkeletonComponentCodes[16];                                           // 0x007489A8
extern const unsigned int* gpArcherComponentCodes[16];                                             // 0x00748A18

void __stdcall UNITS_GetFrameMetrics(D2UnitStrc* pUnit, int* pFrame, int* pFrameCount);                    // 0x00621870
int __stdcall UNITS_GetEventFrameInfo(D2UnitStrc* pUnit, int nFrame);                                       // 0x00621920
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
unsigned int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nCompCode);                                      // 0x006117D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return pUnit->dwAnimMode;
}

inline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nClassId];
        }
    }
    return 0;
}

static D2MonStats2Txt* MONSTERS_GetMonStats2TxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x006647C0
int __stdcall D2COMMON_11068_GetCompInfo(D2UnitStrc* pMonster, int nComponent)
{
    if (!pMonster || pMonster->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pMonster->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    return pMonStats2TxtRecord->nComponentChoiceCounts[nComponent];
}

// 0x00664800
int __fastcall sub_00664800_GetCompChoiceCount(int nMonsterId, unsigned int nComponent)
{
    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERS_GetMonStats2TxtRecordInline(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    return pMonStats2TxtRecord->nComponentChoiceCounts[nComponent];
}

// 0x00664860
unsigned int __stdcall D2Common_11069(D2UnitStrc* pMonster, unsigned int nIndex, unsigned int nComponent)
{
    const int nType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        if (nIndex >= 16)
        {
            return 0;
        }

        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pMonster->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return 0;
        }

        if (pMonStats2TxtRecord->nComponentChoiceCounts[nIndex] <= nComponent)
        {
            return 0;
        }

        unsigned int dwCode = DATATBLS_GetCodeFromCompCodeTxt(pMonStats2TxtRecord->pComponents[nIndex].nComposit[nComponent]);

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMonster);
        if (pRoom && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == ACT_II)
        {
// build: symbol ?CUNIT_GetMonsterBaseId@* 0x00463860
            switch (MONSTERS_GetBaseIdFromMonsterId(CUNIT_GetMonsterBaseId(pMonster)))
            {
            case MONSTER_SK_ARCHER1:
            {
                const unsigned int* pCode = gpArcherComponentCodes[nIndex];
                if (pCode)
                {
                    dwCode = pCode[nComponent];
                }
                break;
            }

            case MONSTER_SKELETON1:
            {
                const unsigned int* pCode = gpSkeletonComponentCodes[nIndex];
                if (pCode)
                {
                    dwCode = pCode[nComponent];
                }
                break;
            }
            }
        }

        return dwCode;
    }

    return 0;
}

// 0x00664930
int __stdcall D2Common_11070(int nMonsterId, unsigned int nComponent, unsigned int nIndex)
{
    if (nComponent >= sizeof(((D2MonStats2Txt*)0)->nComponentChoiceCounts))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERS_GetMonStats2TxtRecordInline(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pMonStats2TxtRecord->nComponentChoiceCounts[nComponent] <= nIndex)
    {
        return 0;
    }

    return DATATBLS_GetCodeFromCompCodeTxt(pMonStats2TxtRecord->pComponents[nComponent].nComposit[nIndex]);
}

#include "gen/data/Source/D2Common/Unknown_006647C0.inc"
