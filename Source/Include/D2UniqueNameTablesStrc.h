#pragma once
// The four name tables a unique monster's name is built from, and their record counts.

struct D2UniqueNameTablesStrc
{
    void* pTables[4]; // 0x00
    int nCounts[4]; // 0x10
};
