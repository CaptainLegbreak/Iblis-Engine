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
