#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2TxtTables.h"

struct D2MonStatsTxt;
struct D2MonStats2CompStrc;
struct D2MonStats2Txt;


extern D2DataTablesStrc sgtDataTables; // 0x0096BC30
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0


D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
unsigned int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nCompCode); // 0x006117D0

static D2OverlayTxt* DATATBLS_GetOverlayTxtRecord(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }

    return 0;
}

// 0x00664530
void __fastcall DATATBLS_UnloadOverlayTxt()
{
    FOG_FreeLinker(sgtDataTables.pOverlayLinker);
    DATATBLS_UnloadBin(sgtDataTables.pOverlayTxt);
    sgtDataTables.pOverlayTxt = 0;
}

// 0x00664560
unsigned int __stdcall DATATBLS_GetFramesFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dwFrames;
}

// 0x006645A0
int __stdcall DATABLS_GetPreDrawFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->nPreDraw;
}

// 0x006645E0
unsigned int __stdcall DATATBLS_GetOffsetXFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dwOffsetX;
}

// 0x00664620
unsigned int __stdcall DATATBLS_GetOffsetYFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dwOffsetY;
}

// 0x00664660
int __stdcall DATATBLS_GetTransFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->nTrans;
}

// 0x006646A0
int __stdcall DATATBLS_GetRadiusAndColorFromOverlayTxt(int nOverlayId, int* pInitRadius, int* pRadius, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        *pInitRadius = 0;
        *pRadius = 0;
        *pRed = 0;
        *pGreen = 0;
        *pBlue = 0;
        return 0;
    }

    {
        *pInitRadius = pOverlayTxt->dwInitRadius;
        *pRadius = pOverlayTxt->dwRadius;
        *pRed = pOverlayTxt->nRed;
        *pGreen = pOverlayTxt->nGreen;
        *pBlue = pOverlayTxt->nBlue;
        return *pRadius || *pInitRadius;
    }
}

// 0x00664740
unsigned int __stdcall DATATBLS_Get1OfNFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->dw1ofN;
}

// 0x00664780
int __stdcall DATATBLS_GetDirFromOverlayTxt(int nOverlayId)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecord(nOverlayId);
    if (!pOverlayTxt)
    {
        return 0;
    }

    return pOverlayTxt->nDir;
}

#include "gen/data/Source/D2Common/Unknown_00664530.inc"
