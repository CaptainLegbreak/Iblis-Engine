#include "D2Client.h"
#include "D2DataTbls.h"


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

// 0x004C51D0
int __cdecl sub_004C51D0_GetStatesTxtRecordCount()
{
    return sgptDataTables->nStatesTxtRecordCount;
}

// 0x004C53D0
void __fastcall sub_004C53D0_ScaleDownDirection(int* pX, int* pY)
{
    int nY = *pY;
    int nX = -*pX;
    while (nX * nX + nY * nY > 3)
    {
        nY /= 2;
        nX /= 2;
    }

    *pX = nY;
    *pY = nX;
}
