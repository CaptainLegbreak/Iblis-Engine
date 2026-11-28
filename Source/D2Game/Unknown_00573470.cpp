#include "D2Game.h"
#include "D2Structs.h"
#include "D2UnitData.h"

#define UNIT_MONSTER 1
#define BONUS_TABLE_SIZE 9
#define HP_BONUS_STEP 50
#define HP_BONUS_BASE 2
#define XP_BONUS_BASE 130

struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2MonsterDataStrc;
struct Data005734C0;
struct Data005734E0;
struct Unit005734E0;
struct Data00573500;
struct Data00573570;
struct Unit00573570;

struct D2MonStatsTxt
{
    char unk0x00[26];
    short wMonStatsEx;
    char unk0x1C[396];
};

struct D2MonStats2Txt
{
    char unk0x00[312];
};

struct D2DataTablesStrc
{
    char unk0x00[2680];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[428];
    D2MonStats2Txt* pMonStats2Txt;
    int nMonStats2TxtRecordCount;
};



extern D2DataTablesStrc* sgptDataTables; // 0x00744304

struct Data005734C0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };

struct Data005734E0 { unsigned char bUnknown00[0x54]; unsigned int dwValue54; };

struct Unit005734E0 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data005734E0* pData; };

struct Data00573500 { unsigned char bUnknown00[0x58]; unsigned int dwValue58; };

struct Data00573570 { unsigned char bUnknown00[0x5C]; unsigned short wFlags5C; };

struct Unit00573570 { int nType; unsigned int dwUnknown04; unsigned int dwUnknown08; unsigned int dwUnknown0C; unsigned int dwUnknown10; Data00573570* pData; };

// 0x00573470
D2MonStats2Txt* __fastcall sub_00573470_GetMonStats2Record(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (pMonStatsTxtRecord)
    {
        if (pMonStatsTxtRecord->wMonStatsEx >= 0 && pMonStatsTxtRecord->wMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[pMonStatsTxtRecord->wMonStatsEx];
        }
    }

    return 0;
}


