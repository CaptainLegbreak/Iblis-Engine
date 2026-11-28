// A piece of MissileTbls.cpp (0x006617B0-0x00663270), kept as its own file because the join doesn't build equal. In
// MissileTbls.cpp, DATATBLS_LoadMissilesTxt (0x00661B20) changes register choice whenever that unit's D2MissilesTxt
// view changes shape: adding the two velocity fields this function reads (under any names, in any split of the
// padding) or taking D2Txt.h's record in place of the view. This function also reads the tables record directly
// (sgtDataTables at 0x0096BC30), where MissileTbls.cpp's own record getter reads through sgptDataTables. The one
// joined form that keeps every function equal reads the two fields through casts at raw offsets, so the piece stays
// until the loader's declaration sensitivity is understood.

#include "D2DataTbls.h"
#include "D2Txt.h"

extern D2DataTablesStrc sgtDataTables; // 0x0096BC30


static D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgtDataTables.nMissilesTxtRecordCount)
    {
        return &sgtDataTables.pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x00663270
int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel)
{
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nMissileId);
    if (pMissilesTxtRecord)
    {
        return pMissilesTxtRecord->nVel + nLevel * pMissilesTxtRecord->nVelLev / 8;
    }

    return 0;
}
