#include "FogApi.h"
#include "D2GfxApi.h"
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GridCellStrc
{
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    int nX;
    int nY;
};

struct D2GridRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

struct D2GridInfoStrc
{
    char pad0x00[0x4];
    unsigned short wZ;
};

struct D2LightObjStrc
{
    int nX;
    int nY;
    char pad0x08[0xC];
    unsigned int dwFlags;
    D2GridInfoStrc* pInfo;
    char pad0x1C[0x8];
    unsigned int dwLightFlags;
    unsigned char nAlpha;
    unsigned char nAlphaFrom;
    unsigned char nAlphaTo;
    unsigned char pad0x2B;
    unsigned int dwFadeEnd;
};

struct D2LightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2LightObjStrc* pObj;
    D2LightNodeStrc* pNext;
};

struct D2LightCellStrc
{
    char pad0x00[0x1C];
    D2LightNodeStrc* pHead;
    int unk0x20;
};

struct D2ViewStrc
{
    char pad0x00[0x14];
    D2GridRectStrc tRect;
    int nOffX;
    int nOffY;
    char pad0x2C[0xEAA8 - 0x2C];
    D2LightCellStrc* pCells;
    int unk0xEAAC;
    int nSize;
};

extern void* gpGlobal_007A0634;                                                                             // 0x007A0634
unsigned char __stdcall ENVIRONMENT_GetIntensityFromAct(void* pAct);                                                           // 0x0061C0E0
void __stdcall ENVIRONMENT_GetLightColorFromAct(void* pAct, unsigned char* pR, unsigned char* pG, unsigned char* pB);           // 0x0061C0B0
void __fastcall SCMD_ReadGridCell(int nX, int nY, unsigned char* pB0, unsigned char* pB1, unsigned char* pB2, unsigned char* pB3); // 0x00475AA0
int __cdecl DLIGHTMAP_GetRenderMode(); // 0x00477730
int __cdecl sub_0045AE90_GetPanelSlideMode();                                                                         // 0x0045AE90
void __stdcall D2GFX_FloorTileDraw(D2GridInfoStrc* pInfo, D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int nAlpha, int nMode, int nArg); // 0x004F68E0
void __stdcall WALL2_FillGridLight(D2GridCellStrc* pCells, int nX, int nY, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE070
void __stdcall WALL2_FillCellLights(D2GridCellStrc* pCells, int nSubX, int nSubY, int nZ, int nMode, int bCorners); // 0x004DE260

static void __stdcall WALL2_BuildLargeGrid(int nX, int nY, int bFlat, D2GridCellStrc* pCells); // 0x004DDEF0

extern int gnScreenWidth; // 0x0071146C

// 0x004DDEF0
static void __stdcall WALL2_BuildLargeGrid(int nX, int nY, int bFlat, D2GridCellStrc* pCells)
{
    if (bFlat)
    {
        const unsigned char nB0 = ENVIRONMENT_GetIntensityFromAct(gpGlobal_007A0634);
        unsigned char nB1, nB2, nB3;
        ENVIRONMENT_GetLightColorFromAct(gpGlobal_007A0634, &nB1, &nB2, &nB3);
        for (int j = 0; j < 8; ++j)
        {
            for (int i = 0; i < 8; ++i)
            {
                pCells->nRed = nB1;
                pCells->nIntensity = nB0;
                pCells->nBlue = nB3;
                pCells->nGreen = nB2;
                ++pCells;
            }
        }
        return;
    }

    for (int j = 0; j < 8; ++j)
    {
        for (int i = 0; i < 8; ++i)
        {
            SCMD_ReadGridCell(8 * (nX + i - 1), 8 * (nY + j - 1), &pCells->nIntensity, &pCells->nRed, &pCells->nGreen, &pCells->nBlue);
            ++pCells;
        }
    }
}


// 0x004DEA70
void __fastcall DFLOOR_UpdateFloorView(D2ViewStrc* pView)
{
    const unsigned int nTick = GetTickCount();
    const int nDetail = DLIGHTMAP_GetRenderMode();
    const int bPerspective = D2GFX_CheckPerspective();
    const int nCorners = D2GFX_CheckLowQuality();
    const int nOffX = 0x50 - pView->nOffX;
    const int nOffY = -0x50 - pView->nOffY;
    const unsigned int nCount = pView->nSize * pView->nSize;
    const int nMode = sub_0045AE90_GetPanelSlideMode();
    D2GridCellStrc tLarge[8 * 8];
    D2GridCellStrc tSmall[6 * 6];

    for (unsigned int nLayer = 1; nLayer <= 4; ++nLayer)
    {
        const unsigned int nMask = nLayer << 14;
        D2LightCellStrc* pCell = pView->pCells;
        unsigned int nLeft = nCount;
        while (nLeft--)
        {
            for (D2LightNodeStrc* pNode = pCell->pHead; pNode; pNode = pNode->pNext)
            {
                D2LightObjStrc* pObj = pNode->pObj;
                const unsigned int dwFlags = pObj->dwFlags;
                if ((dwFlags & nMask) != nMask)
                {
                    continue;
                }

                const unsigned int dwLightFlags = pObj->dwLightFlags;
                if (dwLightFlags & 2)
                {
                    if (!(nDetail < 4))
                    {
                        if (nTick >= pObj->dwFadeEnd)
                        {
                            const unsigned char nAlphaTo = pObj->nAlphaTo;
                            pObj->nAlpha = nAlphaTo;
                            pObj->dwLightFlags = dwLightFlags & ~2u;
                        }
                        else
                        {
                            pObj->nAlpha = pObj->nAlphaFrom + (pObj->nAlphaTo - pObj->nAlphaFrom) * (int)(nTick - pObj->dwFadeEnd + 500) / 500;
                        }
                    }
                    else
                    {
                        const unsigned char nAlphaTo = pObj->nAlphaTo;
                        pObj->dwLightFlags = dwLightFlags & ~2u;
                        pObj->nAlpha = nAlphaTo;
                    }

                    if (pObj->nAlpha == 0)
                    {
                        pObj->dwFlags = dwFlags | 0x400;
                    }
                    else
                    {
                        pObj->dwFlags = dwFlags & ~0x400u;
                    }
                }

                if (pObj->dwFlags & 0x408)
                {
                    continue;
                }

                D2GridInfoStrc* pInfo = pObj->pInfo;
                const int nX = pObj->nX + nOffX;
                const int nY = pObj->nY - pInfo->wZ + nOffY;
                D2GridRectStrc* ptRect = &pView->tRect;
                D2_ASSERT(ptRect, 0x76);
                if (nX < ptRect->nLeft || nX >= ptRect->nRight || nY < ptRect->nTop || nY >= ptRect->nBottom)
                {
                    continue;
                }

                const int nSubX = pNode->nX >> 3;
                const int nSubY = pNode->nY >> 3;
                if (DLIGHTMAP_GetRenderMode() < 4)
                {
                    WALL2_BuildLargeGrid(nSubX, nSubY, pInfo->wZ, tLarge);
                    D2GFX_FloorTileDraw(pObj->pInfo, tLarge, nX, nY, nSubX, nSubY, pObj->nAlpha, nMode, 0);
                }
                else
                {
                    if (bPerspective)
                    {
                        WALL2_FillCellLights(tSmall, nSubX, nSubY, pInfo->wZ, nMode, nCorners);
                    }
                    else
                    {
                        WALL2_FillGridLight(tSmall, nX, nY, nSubX, nSubY, pInfo->wZ, nMode, nCorners);
                    }
                    D2GFX_FloorTileDraw(pObj->pInfo, tSmall, nX, nY, nSubX, nSubY, pObj->nAlpha, nMode, 0);
                }
                pObj->dwFlags |= 0x20000;
            }
            ++pCell;
        }
    }
}
