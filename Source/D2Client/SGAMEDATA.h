#pragma once
// D2Client's game list record (SGAMEDATA, 0x1DF4 B, named by its type descriptor at 0x70F564) and the Storm
// hash-table types the client's game list is built from.

#include "stplhash.h"
#include "CCritSect.h"

struct HSGAMEDATA__;
struct HSGAMEDATALOCK__;

struct SGAMEDATA : TSHashObject<SGAMEDATA, HASHKEY_NONE>
{
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
    unsigned short wUnk0x28;
    char szUnk0x2A[0x10];
    char szUnk0x3A[0x10];
    char szUnk0x4A[0x20];
    char nUnk0x6A;
    char nUnk0x6B;
    char nUnk0x6C;
    char nUnk0x6D;
    char nUnk0x6E;
    int nUnk0x70;
    int nUnk0x74;
    unsigned short wUnk0x78;
    int nUnk0x7C;
    int nUnk0x80;
    int nUnk0x84;
    int nUnk0x88;
    int nUnk0x8C;
    int nUnk0x90;
    int nUnk0x94;
    int nUnk0x98;
    int nUnk0x9C;
    int nUnk0xA0;
    int nUnk0xA4;
    int nUnk0xA8;
    int nUnk0xAC;
    int nUnk0xB0;
    int nUnk0xB4;
    int nUnk0xB8;
    int nUnk0xBC;
    int nUnk0xC0;
    int nUnk0xC4;
    int nUnk0xC8;
    int nUnk0xCC;
    int nUnk0xD0;
    int nUnk0xD4;
    int nUnk0xD8;
    int nUnk0xDC;
    int nUnk0xE0;
    int nUnk0xE4;
    int nUnk0xE8;
    int nUnk0xEC;
    char aUnk0xF0[0x1000];
    int nUnk0x10F0;
    int nUnk0x10F4;
    char aUnk0x10F8[0x28];
    int aUnk0x1120[0x80];
    int aUnk0x1320[0x80];
    int aUnk0x1520[0x80];
    int aUnk0x1720[0x80];
    int aUnk0x1920[0x80];
    int nUnk0x1B20;
    int aUnk0x1B24[0x80];
    int nUnk0x1D24;
    int nUnk0x1D28;
    int nUnk0x1D2C;
    int aUnk0x1D30[0x10];
    int aUnk0x1D70[0x12];
    int nUnk0x1DB8;
    int nUnk0x1DBC;
    int nUnk0x1DC0;
    int nUnk0x1DC4;
    int nUnk0x1DC8;
    int nUnk0x1DCC;
    int nUnk0x1DD0;
    int nUnk0x1DD4;
    int nUnk0x1DD8;
    int nUnk0x1DDC;
    int nUnk0x1DE0;
    int nUnk0x1DE4;
    int nUnk0x1DE8;
    int nUnk0x1DEC;
    int nUnk0x1DF0;
};

typedef TSExplicitList<SGAMEDATA, STORM_EXPLICIT_LIST_UNSET> D2SGameDataList;
typedef TSHashObjectChunk<SGAMEDATA, HASHKEY_NONE> D2SGameDataChunk;
typedef TSHashTable<SGAMEDATA, HASHKEY_NONE> D2SGameDataTable;
typedef TSHashTableReuse<SGAMEDATA, HASHKEY_NONE, 0> D2SGameDataReuseTable;
typedef TSExportTableSimple<SGAMEDATA, HSGAMEDATA__*, 0> D2SGameDataExportTable;
typedef TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> D2SGameDataSyncTable;
