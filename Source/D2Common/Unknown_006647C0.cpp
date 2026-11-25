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

#pragma pack(push, 1)
struct d2data_007488C0_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007488FC_t
{
    unsigned char b0[28];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00748918_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00748924_t
{
    unsigned char b0[40];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0074894C_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00748960_t
{
    unsigned char b0[48];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00748990_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0074899C_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007489E8_t
{
    unsigned char b0[44];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00748A14_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

extern "C" const int gData_006EA938[16]; // 0x006EA938
extern "C" struct d2data_007488C0_t gData_007488C0; // 0x007488C0
extern "C" struct d2data_007488FC_t gdwSkeletonHeadCodes; // 0x007488FC
extern "C" struct d2data_00748918_t gdwSkeletonLimbCodes; // 0x00748918
extern "C" struct d2data_00748924_t gdwSkeletonWeaponCodes; // 0x00748924
extern "C" struct d2data_0074894C_t gdwSkeletonShieldCodes; // 0x0074894C
extern "C" struct d2data_00748960_t gdwSkeletonSpecialCodes; // 0x00748960
extern "C" struct d2data_00748990_t gdwSkeletonTorsoCodes; // 0x00748990
extern "C" struct d2data_0074899C_t gdwArcherArmorCodes; // 0x0074899C
extern "C" struct d2data_007489E8_t gdwArcherSpecialCodes; // 0x007489E8
extern "C" struct d2data_00748A14_t gdwArcherBowCodes; // 0x00748A14

extern "C" const int gData_006EA938[16] = { 0, 0, 0, 0, 58, 60, 0, 70, 62, 64, 66, 68, 0, 0, 72 }; // 0x006EA938
#pragma comment(linker, "/alternatename:?gnMonStatsMissileOffsets@@3PAHA=_gData_006EA938")

extern "C" struct d2data_007488C0_t gData_007488C0 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x007488C0

extern "C" struct d2data_007488FC_t gdwSkeletonHeadCodes = {
    {
        0x6C, 0x69, 0x74, 0x20, 0x6C, 0x69, 0x74, 0x20, 0x64, 0x65, 0x73, 0x20, 0x64, 0x65, 0x73, 0x20,
        0x68, 0x76, 0x79, 0x20, 0x68, 0x76, 0x79, 0x20, 0x68, 0x76, 0x79, 0x20
    }
}; // 0x007488FC

extern "C" struct d2data_00748918_t gdwSkeletonLimbCodes = {
    { 0x6C, 0x69, 0x74, 0x20, 0x64, 0x65, 0x73, 0x20, 0x68, 0x76, 0x79, 0x20 }
}; // 0x00748918

extern "C" struct d2data_00748924_t gdwSkeletonWeaponCodes = {
    {
        0x61, 0x78, 0x65, 0x20, 0x61, 0x78, 0x65, 0x20, 0x66, 0x6C, 0x61, 0x20, 0x66, 0x6C, 0x61, 0x20,
        0x68, 0x61, 0x78, 0x20, 0x68, 0x61, 0x78, 0x20, 0x6D, 0x61, 0x63, 0x20, 0x6D, 0x61, 0x63, 0x20,
        0x73, 0x63, 0x6D, 0x20, 0x73, 0x63, 0x6D, 0x20
    }
}; // 0x00748924

extern "C" struct d2data_0074894C_t gdwSkeletonShieldCodes = {
    {
        0x00, 0x00, 0x00, 0x00, 0x62, 0x75, 0x63, 0x20, 0x6C, 0x72, 0x67, 0x20, 0x6B, 0x69, 0x74, 0x20,
        0x73, 0x6D, 0x6C, 0x20
    }
}; // 0x0074894C

extern "C" struct d2data_00748960_t gdwSkeletonSpecialCodes = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x6C, 0x69, 0x74, 0x20, 0x64, 0x65, 0x73, 0x20, 0x68, 0x76, 0x79, 0x20
    }
}; // 0x00748960

extern "C" struct d2data_00748990_t gdwSkeletonTorsoCodes = {
    { 0x6C, 0x69, 0x74, 0x20, 0x6D, 0x65, 0x64, 0x20, 0x68, 0x76, 0x79, 0x20 }
}; // 0x00748990

extern "C" struct d2data_0074899C_t gdwArcherArmorCodes = {
    { 0x6C, 0x69, 0x74, 0x20, 0x64, 0x65, 0x73, 0x20, 0x68, 0x76, 0x79, 0x20 }
}; // 0x0074899C

extern const unsigned int* gpSkeletonComponentCodes[16] = { (const unsigned int*)&gdwSkeletonHeadCodes, (const unsigned int*)&gdwSkeletonTorsoCodes, (const unsigned int*)&gdwSkeletonLimbCodes, (const unsigned int*)&gdwSkeletonLimbCodes, (const unsigned int*)&gdwSkeletonLimbCodes, (const unsigned int*)&gdwSkeletonWeaponCodes, 0, (const unsigned int*)&gdwSkeletonShieldCodes, (const unsigned int*)&gdwSkeletonSpecialCodes, (const unsigned int*)&gdwSkeletonSpecialCodes }; // 0x007489A8

extern "C" struct d2data_007489E8_t gdwArcherSpecialCodes = {
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x6C, 0x69, 0x74, 0x20, 0x64, 0x65, 0x73, 0x20, 0x68, 0x76, 0x79, 0x20
    }
}; // 0x007489E8

extern "C" struct d2data_00748A14_t gdwArcherBowCodes = {
    { 0x73, 0x62, 0x77, 0x20 }
}; // 0x00748A14

extern const unsigned int* gpArcherComponentCodes[16] = { (const unsigned int*)&gdwArcherArmorCodes, (const unsigned int*)&gdwSkeletonTorsoCodes, (const unsigned int*)&gdwArcherArmorCodes, (const unsigned int*)&gdwArcherArmorCodes, (const unsigned int*)&gdwArcherArmorCodes, 0, (const unsigned int*)&gdwArcherBowCodes, 0, (const unsigned int*)&gdwArcherSpecialCodes, (const unsigned int*)&gdwArcherSpecialCodes }; // 0x00748A18
