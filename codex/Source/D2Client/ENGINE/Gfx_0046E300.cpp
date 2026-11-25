#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2TxtTables.h"
#include "D2ClientTypes.h"
#include "D2CelContext.h"

struct D2UnitOverlayStrc;


struct D2UnitOverlayStrc
{
    int dwType;
    int nOverlay;
    int f08;
    char unk0x0C[0xC];
    int nFrame;
    int f_1C;
    int nXOffset;
    int nYOffset;
    char unk0x28[0xC];
    int bFront;
    int unk0x38;
    int f3C;
    char unk0x40[0x64];
    D2UnitOverlayStrc* pNext;
};



extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnScreenWidth;                                                                               // 0x0071146C

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

int __cdecl GAME_GetColorFlag();                                                                                 // 0x0044DC60
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
extern "C" int __cdecl PLAYER_GetScreenOffsetX();                                                          // 0x0045AFC0
extern "C" int __cdecl PLAYER_GetScreenOffsetY();                                                      // 0x0045AFD0
D2GfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit);                                       // 0x00463E10
int __cdecl DLIGHTMAP_GetLocalBloodPalette();                                                                                 // 0x00477680
extern "C" int __stdcall PARTICLE_GetGfxOffsetX(D2UnitStrc* pUnit);                                     // 0x004DA0B0
int __stdcall PARTICLE_GetGfxClientY(D2UnitStrc* pUnit);                                          // 0x004DA0D0
int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit);                                          // 0x004DA0F0
int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pCel, D2UnitStrc* pUnit, int a3, int nDirection, int nFrame, int* pOut, unsigned char a7, int a8); // 0x004DBB50
int __stdcall D2GFX_CheckPerspective();                                                                     // 0x004F51D0
void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nX, int nY, unsigned int nColor, int nDrawMode, unsigned char* pPalette); // 0x004F6480
void __stdcall SCALE_AdjustPerspectivePosition(int nX, int nY, int nBias, int* pX, int* pY);               // 0x004F6760
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190

// 0x0046E300
void __stdcall GFX_DrawUnitOverlays(D2UnitStrc* pUnit, unsigned int nColor, int bFront, int nX, int nY, int bLift)
{
    D2GfxDataStrc* pGfx = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfx, 625);

    const int bPerspective = D2GFX_CheckPerspective();
    D2UnitOverlayStrc* pOverlay = pGfx->pOverlays;
    if (!pOverlay)
    {
        return;
    }

    int nDrawX;
    int nDrawY;
    if (bPerspective && (!pUnit || pUnit->dwUnitType != UNIT_ITEM || UNITS_GetAnimOrSeqMode(pUnit) == 3))
    {
        SCALE_AdjustPerspectivePosition(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0, &nX, &nY);
        switch (sub_0045AE90())
        {
        case 1:
            nX -= gnScreenWidth / 4;
            break;
        case 2:
            nX += gnScreenWidth / 4;
            break;
        }
        nDrawX = nX;
        nDrawY = nY + 16;
    }
    else
    {
        nDrawX = UNITS_GetClientCoordX(pUnit) - PLAYER_GetScreenOffsetX();
        nDrawY = UNITS_GetClientCoordY(pUnit) - PLAYER_GetScreenOffsetY();
        if (pUnit && pUnit->dwUnitType == UNIT_ITEM && nX != -1 && nY != -1)
        {
            nDrawX = nX;
            nDrawY = nY;
        }
    }

    nDrawX += PARTICLE_GetGfxOffsetX(pUnit);
    nDrawY += PARTICLE_GetGfxClientY(pUnit);
    nDrawY += PARTICLE_GetGfxClientZ(pUnit);
    if (bLift)
    {
        nDrawY -= 8;
    }

    do
    {
        int bDraw = 1;
        if (pOverlay->bFront && !bFront)
        {
            bDraw = 0;
        }
        if (!pOverlay->bFront && bFront)
        {
            bDraw = 0;
        }
        if (pOverlay->dwType == 6 && !pOverlay->f08)
        {
            bDraw = 0;
        }
        if (pOverlay->dwType == 8 && !pOverlay->f3C)
        {
            bDraw = 0;
        }

        if (bDraw)
        {
            const int nFrame = pOverlay->nFrame >> 8;
            const int nOverlayId = pOverlay->nOverlay;
            D2OverlayTxt* pOverlayTxtRecord = 0;
            if (nOverlayId >= 0 && nOverlayId < sgptDataTables->nOverlayTxtRecordCount)
            {
                pOverlayTxtRecord = &sgptDataTables->pOverlayTxt[nOverlayId];
            }
            D2_ASSERT(pOverlayTxtRecord, 721);

            D2CelContextStrc tCel;
            memset(&tCel, 0, sizeof(tCel));
            tCel.nOverlay = nOverlayId;
            if (!GFXUTIL_InitUnitCelContext(&tCel, 0, 0, UNITS_GetDirection(pUnit), nFrame, &nX, 1, -1))
            {
                return;
            }

            if (nFrame < pOverlay->f_1C >> 8)
            {
                if (pOverlayTxtRecord->nLocalBlood && GAME_GetColorFlag())
                {
                    DLIGHTMAP_GetLocalBloodPalette();
                }
                TEXTURE_CelDraw(&tCel, pOverlay->nXOffset + nDrawX, pOverlay->nYOffset + nDrawY, nColor, pOverlayTxtRecord->nTrans, 0);
            }
        }

        pOverlay = pOverlay->pNext;
    }
    while (pOverlay);
}
