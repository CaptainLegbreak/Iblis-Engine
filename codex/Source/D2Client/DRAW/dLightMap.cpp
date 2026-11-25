#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2Path.h"

#pragma intrinsic(abs)

#define LIGHT_MAX_SIZE 18

#define LIGHT_SIZE_SHIFT 3

#define LIGHT_TYPE_2 2

#define INDICATOR_HOLD_MS 2000

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define LIGHT_MIN(a, b) ((a) < (b) ? (a) : (b))

#define LIGHT_ABS(x) ((x) >= 0 ? (x) : -(x))

#define LIGHT_CELL(v, r, c) { v = gadwLightOverrideRows[r][c]; if (!v) { v = gadwLightMapRows[r][c]; } }

struct D2UnitRefStrc;

struct D2LightCellStrc;

struct D2P08LightSourceStrc;

struct D2R01LightStrc;

struct D2GridCellStrc;

struct D2UnitStrc;

struct D2DrlgCoordsStrc;

struct D2UnitRefStrc
{
    int nType;
    unsigned int nUnitId;
    unsigned char f_8;
};

struct D2LightCellStrc
{
    union
    {
        int nFlags;
        unsigned char f_0;
    };
    unsigned char nIntensity;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

extern int gbBlendLightColor; // 0x00712B8C

extern int gnCellOriginX_007B0A54; // 0x007B0A54

extern int gnCellOriginY_007B0A58; // 0x007B0A58

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __cdecl D2GFX_CheckLowQuality(); // 0x004F5210

int __cdecl MISSILE_GetMissileLights(); // 0x004CCF30

int __cdecl GAME_GetFramesPerSecond(); // 0x0044DAE0

void __stdcall D2GFX_DebugDraw(unsigned int* pLight, unsigned int* pPlayerLight, int nXPos, int nYPos); // 0x004F68B0

void __stdcall DUNGEON_SetActCallbackFunc(D2DrlgActStrc* pAct, ACTCALLBACKFN pActCallbackFunction); // 0x0061AF60

void __fastcall DLIGHTMAP_ActRoomCallback(D2ActiveRoomStrc* pRoom); // 0x00475930

void __fastcall D2Win_10178_CopyGammaTable(unsigned char (*pRows)[0x100]); // 0x004FB1C0

unsigned char* __stdcall GFX_BuildLerpTable(unsigned int nCount, int nSteps); // 0x00475B80

unsigned char** __stdcall GFX_BuildLerpRowTable(unsigned int nCount, int nSteps); // 0x00475C40

unsigned char** __stdcall SCMD_BuildRampTable(unsigned int nSize, int nSteps); // 0x00475D30

extern unsigned int gdwLightMap_007A8A50[]; // 0x007A8A50

extern unsigned int gdwLightGrid_007B0E68[]; // 0x007B0E68

extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634

extern unsigned char gabRowTable[][0x100]; // 0x007B5C10

extern unsigned char** gppLerpRows; // 0x007B953C

extern unsigned char* gpLerpTable16; // 0x007B9540

extern unsigned char* gpLerpTable32; // 0x007B9544

extern unsigned char** gppRampTable_007B954C; // 0x007B954C

extern unsigned char* gpLerpTable40; // 0x007B9550

extern int gdwGlobal_007BB384; // 0x007BB384

void __stdcall D2GFX_SetGamma(void* pArg); // 0x004F5230

extern int gdwGlobal_00712CCC; // 0x00712CCC

extern int gdwGlobal_007BB38C; // 0x007BB38C

extern int gdwGlobal_007BB3B4; // 0x007BB3B4

extern int gdwGlobal_00712F04; // 0x00712F04

extern int gdwGlobal_007BC9B0; // 0x007BC9B0

extern int gdwGlobal_007BC9B4; // 0x007BC9B4

extern int gdwGlobal_007BC99C; // 0x007BC99C

extern int gdwSoundTick; // 0x007BC9BC

extern int gdwGlobal_007BF024; // 0x007BF024

extern int gdwGlobal_007BF1F6; // 0x007BF1F6

struct D2GridCellStrc
{
    unsigned int nFlag;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
};

struct D2P08LightSourceStrc
{
    unsigned char unk0x00[0x25];
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

unsigned int gadwReciprocals[0x100]; // 0x007B0A68

extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

D2LightCellStrc gaLightGrid[0x30][0x30]; // 0x007B0E68

unsigned int gadwLightOverrideRows[64][64]; // 0x007ACA50

static D2R01LightStrc* gpLights; // 0x007B5668

extern "C" int __cdecl abs(int nValue);

int gnPathStepSignX; // 0x007B0A50

int gnPathStepSignY; // 0x007A8A48

static inline unsigned char DLIGHTMAP_IsCellBlocked(int nX, int nY); // 0x00474A30

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int gnCellLimitX;                                                                                      // 0x007B0A5C

int gnCellLimitY;                                                                                      // 0x007B0A60

int gnPathStepMode; // 0x007B0A64

int gnPathStepRatio; // 0x007A8A4C

static void __stdcall DLIGHTMAP_SetupStepDirection(int nX, int nY, D2R01LightStrc* pPoint); // 0x00474B50

extern D2LightCellStrc gLightGrid_007B0E68[][48]; // 0x007B0E68

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

void __fastcall SCMD_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int a6); // 0x00474550

static void DLIGHTMAP_BlendLightCell(int nCol, int nRow); // 0x00474C00

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

unsigned int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

unsigned int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int gnLightsAllocated; // 0x007B566C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern int gnGlobal_00712B8C;                                                                               // 0x00712B8C

static void __stdcall DLIGHTMAP_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX); // 0x004747C0

static void DLIGHTMAP_BuildOverrideWindow(D2R01LightStrc* pLight); // 0x00474A70


static void DLIGHTMAP_AddBlendedAreaLight(D2R01LightStrc* pLight); // 0x00474D70

#pragma function(memset)

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

int __fastcall DLIGHTMAP_GetDistance(int nDX, int nDY);                                                  // 0x00474080

void __fastcall DLIGHTMAP_ReleaseLight(void* pResource);                                       // 0x004743D0

void __stdcall DLIGHTMAP_UpdateLightGrid(int nArg);                                                                      // 0x00474610

void __cdecl DLIGHTMAP_ScanGridCollision();                                                              // 0x004756D0

int __cdecl DLIGHTMAP_GetIndicatorLevel();                                                               // 0x00475780

extern int gnCellOriginX;                                                                               // 0x007B0A54

extern int gnCellOriginY;                                                                               // 0x007B0A58

int gnLightCount;                                                                                  // 0x007B5674

static unsigned int __stdcall DLIGHTMAP_ApproxDistance(int nB, int nA); // 0x004740D0

static void __stdcall DLIGHTMAP_AddAreaLight(D2R01LightStrc* pLight, int bNoClamp); // 0x004748D0

static void DLIGHTMAP_BuildLightMask(D2R01LightStrc* pLight); // 0x004750F0

static void DLIGHTMAP_AddMaskedAreaLight(D2R01LightStrc* pLight); // 0x00475420

int gnLightsReleased; // 0x007B5670

int gnIndicatorLevel; // 0x007B567C

unsigned long gdwIndicatorTick; // 0x007B5678

int gdwGlobal_007BB388; // 0x007BB388

int gdwGlobal_007BCC48; // 0x007BCC48

unsigned int gadwLightMapRows[64][64]; // 0x007A8A50

static void __stdcall DLIGHTMAP_UpdateLight(int nLevel, D2R01LightStrc* pLight); // 0x004755A0

void __cdecl DLIGHTMAP_RunLightPass(); // 0x00475800

enum D2C_DLightMapConstants
{
    GRID_SIZE = 48,
};

// 0x00474080
int __fastcall DLIGHTMAP_GetDistance(int nDX, int nDY)
{
    const int nAbsX = abs(nDX);
    const int nAbsY = abs(nDY);
    if (nAbsX >= nAbsY)
        return (unsigned int)(nAbsX * 0x3D7 + nAbsY * 0x197) >> 10;
    return (unsigned int)(nAbsY * 0x3D7 + nAbsX * 0x197) >> 10;
}

// 0x004740D0
static __declspec(noinline) unsigned int __stdcall DLIGHTMAP_ApproxDistance(int nB, int nA)
{
    const int nAbsA = abs(nA);
    const int nAbsB = abs(nB);
    if (nAbsA >= nAbsB)
    {
        return (unsigned int)(nAbsA * 0x3D7 + nAbsB * 0x197) >> 10;
    }

    return (unsigned int)(nAbsB * 0x3D7 + nAbsA * 0x197) >> 10;
}

// 0x00474120
static inline D2UnitStrc* DLIGHTMAP_FindUnitFromRef(D2UnitRefStrc* pRef)
{
    if (pRef->nType == 6)
    {
        return 0;
    }
    if (pRef->f_8)
    {
        return CUNIT_FindServerSideUnit(pRef->nUnitId, pRef->nType);
    }
    return CUNIT_FindClientUnit(pRef->nUnitId, pRef->nType);
}

// 0x00474140
void __cdecl DLIGHTMAP_ToggleBlendLightColor()
{
    gbBlendLightColor = !gbBlendLightColor;
}

static inline int UNITS_IsServerSide(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlags >> 21) & 1;
    }
    return 0;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x00474160
D2R01LightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nMode, int nRadius, unsigned char nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (nRadius > 0)
    {
        if (nRadius >= 18)
        {
            nRadius = 18;
        }

        ++gnLightsAllocated;

        D2R01LightStrc* pLight = (D2R01LightStrc*)FOG_Alloc(sizeof(D2R01LightStrc), ".\\DRAW\\dLightMap.cpp", 255, 0);
        pLight->nUnitType = sub_0044BE50(pUnit);
        pLight->nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
        if (UNITS_IsServerSide(pUnit))
        {
            pLight->f_8 = 1;
        }
        else
        {
            pLight->f_8 = 0;
        }
        pLight->nX = (UNITS_GetPrecisionX(pUnit) >> 13) + 4;
        unsigned int nPrecisionY = UNITS_GetPrecisionY(pUnit);
        // volatile: the original reads both arguments from their stack slots here
        unsigned char nNativeIntensity = *(volatile unsigned char*)&nIntensity;
        int nNativeMode = *(volatile int*)&nMode;
        pLight->nY = (nPrecisionY >> 13) + 4;
        pLight->nRadius = nRadius << 3;
        pLight->nTargetRadius = nRadius << 3;
        pLight->nIntensity = nNativeIntensity;
        pLight->nRed = nRed;
        pLight->nGreen = nGreen;
        pLight->nMode = nNativeMode;
        pLight->bFixed = 0;
        pLight->nBlue = nBlue;
        pLight->pNext = gpLights;
        pLight->bMaskReady = 0;
        if (nNativeMode == 2)
        {
            pLight->pMask = (unsigned int*)FOG_Alloc(((2 * nRadius + 1) * (2 * nRadius + 1)) << 2, ".\\DRAW\\dLightMap.cpp", 278, 0);
        }
        else
        {
            pLight->pMask = 0;
        }
        gpLights = pLight;
        return pLight;
    }
    return 0;
}

int __fastcall sub_M119_Emit_00474120(D2UnitRefStrc* pRef, int nX, int nY)
{
    int n = (int)DLIGHTMAP_FindUnitFromRef(pRef);
    n += DLIGHTMAP_IsCellBlocked(nX, nY);
    return n;
}

// 0x00474290
void __fastcall DLIGHTMAP_SetLightSize(D2R01LightStrc* pLight, int nSize)
{
    if (nSize > 0)
    {
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        D2_ASSERT(pLight, 0x131);
        pLight->nTargetRadius = nSize * 8;
    }
}

// 0x004742D0
void __fastcall DLIGHTMAP_ResetLightSize(D2R01LightStrc* pLight, int nSize)
{
    if (nSize > 0)
    {
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        D2_ASSERT(pLight, 0x141);
        if (nSize >= LIGHT_MAX_SIZE)
        {
            nSize = LIGHT_MAX_SIZE;
        }
        pLight->nRadius = nSize * 8;
        pLight->nTargetRadius = nSize * 8;
        if (pLight->nMode == LIGHT_TYPE_2)
        {
            pLight->bMaskReady = 0;
            if (pLight->pMask)
            {
                FOG_Free(pLight->pMask, ".\\DRAW\\dLightMap.cpp", 0x14A, 0);
            }
            pLight->pMask = 0;
        }
    }
}

// 0x00474350
int __fastcall DLIGHTMAP_GetLightSize(D2R01LightStrc* pLight)
{
    D2_ASSERT(pLight, 0x155);
    return pLight->nRadius >> LIGHT_SIZE_SHIFT;
}

// 0x00474380
int __cdecl sub_00474380()
{
    return 32;
}

// 0x004743D0
void __fastcall DLIGHTMAP_ReleaseLight(D2R01LightStrc* pLight)
{
    if (!pLight)
    {
        return;
    }
    D2R01LightStrc* pPrev = 0;
    D2R01LightStrc* pCurrent = gpLights;
    while (pCurrent)
    {
        if (pCurrent == pLight)
        {
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    D2_ASSERT(pCurrent, 0x17A);
    if (pPrev)
    {
        pPrev->pNext = pCurrent->pNext;
    }
    else
    {
        gpLights = pCurrent->pNext;
    }
    if (pLight->pMask)
    {
        FOG_Free(pLight->pMask, ".\\DRAW\\dLightMap.cpp", 0x181, 0);
    }
    FOG_Free(pLight, ".\\DRAW\\dLightMap.cpp", 0x183, 0);
    gnLightsReleased += 1;
}

// 0x00474470
void __fastcall DLIGHTMAP_FadeOutLight(D2R01LightStrc* pLight)
{
    D2_ASSERT(pLight, 0x18D);
    pLight->bFixed = 1;
    pLight->nTargetRadius = 0;
    D2_ASSERT(pLight->nMode != LIGHT_TYPE_2, 0x190);
}

void __stdcall sub_R01_Emit_00474C00(int nRow, int nColA, int nColB)
{
    DLIGHTMAP_BlendLightCell(nColA, nRow);
    DLIGHTMAP_BlendLightCell(nColB, nRow);
}

// 0x004744B0
static void __stdcall DLIGHTMAP_FillLightGrid(int nX0, int nY0, int nX1, unsigned int nColor, int nY1)
{
    for (int nY = nY0; nY <= nY1; ++nY)
    {
        D2LightCellStrc* pCell = &gLightGrid_007B0E68[nY][nX0];
        for (int nX = nX0; nX <= nX1; ++nX)
        {
            pCell->nFlags = 0;
            pCell->nIntensity = (unsigned char)nColor;
            pCell->nRed = (unsigned char)(nColor >> 8);
            pCell->nGreen = (unsigned char)(nColor >> 16);
            pCell->nBlue = (unsigned char)(nColor >> 24);
            ++pCell;
        }
    }
}

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

#define gnGlobal_007A7430 (gtTimedBox.nValue)

#define gnGlobal_007A7434 (gtTimedBox.nColor[0])

#define gnGlobal_007A7435 (gtTimedBox.nColor[1])

#define gnGlobal_007A7436 (gtTimedBox.nColor[2])

struct D2ClientTimedBoxStrc;



int __stdcall ROSTERPETS_GetPulseColor(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0046BD50

void __stdcall ENVIRONMENT_GetLightColorFromAct(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0

int __stdcall ENVIRONMENT_GetIntensityFromAct(void* pAct); // 0x0061C0E0

extern int gbChaosLightEvent; // 0x007A7460

extern D2ClientTimedBoxStrc gtTimedBox; // 0x007A742C

extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

int __fastcall SCMD_GetLevelLight(D2ActiveRoomStrc* pRoom, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0046BDD0

// 0x00474550
void __fastcall SCMD_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int bLevelLight)
{
    unsigned char nRed = 0;
    unsigned char nGreen = 0;
    unsigned char nBlue = 0;
    int nIntensity;

    if (bLevelLight)
    {
        nIntensity = SCMD_GetLevelLight(pRoom, &nRed, &nGreen, &nBlue);
        if (nRed || nGreen || nBlue)
        {
            goto out;
        }
    }

    unsigned char nRoomIntensity;
    sub_00619D70(pRoom, &nRoomIntensity, &nRed, &nGreen, &nBlue);
    nIntensity = nRoomIntensity;
    if (!nRed && !nGreen && !nBlue)
    {
        ENVIRONMENT_GetLightColorFromAct(gpDrlgAct_007A0634, &nRed, &nGreen, &nBlue);
        nIntensity = ENVIRONMENT_GetIntensityFromAct(gpDrlgAct_007A0634);
    }

out:
    *pIntensity = nIntensity;
    *pRed = nRed;
    *pGreen = nGreen;
    *pBlue = nBlue;
}

// 0x00474610
void __stdcall DLIGHTMAP_UpdateLightGrid(int bClear)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc* pRoom;
    if (!pPlayer || (pRoom = UNITS_GetRoom(pPlayer)) == 0 || bClear)
    {
        DLIGHTMAP_FillLightGrid(0, 0, 47, 0, 47);
        return;
    }

    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

        unsigned char nRed = 0;
        unsigned char nGreen = 0;
        unsigned char nBlue = 0;
        int nIntensity = 0;
        SCMD_GetRoomLight(pRoom, &nIntensity, &nRed, &nGreen, &nBlue, 1);
        DLIGHTMAP_FillLightGrid(0, 0, 47, nIntensity | (nRed << 8) | (nGreen << 16) | (nBlue << 24), 47);

        for (int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pRoom)
            {
                continue;
            }

            SCMD_GetRoomLight(ppRoomList[i], &nIntensity, &nRed, &nGreen, &nBlue, 1);
            const unsigned int nColor = nIntensity | (nRed << 8) | (nGreen << 16) | (nBlue << 24);

            D2DrlgCoordsStrc tCoords;
            DUNGEON_GetRoomCoordinates(ppRoomList[i], &tCoords);

            int nX0 = tCoords.nSubtileX - gnCellOriginX_007B0A54;
            int nX1 = nX0 + tCoords.nSubtileWidth;
            if (nX0 > 48 || nX1 < 0)
            {
                continue;
            }

            int nY0 = tCoords.nSubtileY - gnCellOriginY_007B0A58;
            int nY1 = nY0 + tCoords.nSubtileHeight;
            if (nY0 > 48 || nY1 < 0)
            {
                continue;
            }

            if (nX0 < 0)
            {
                nX0 = 0;
            }
            if (nX1 >= 48)
            {
                nX1 = 47;
            }
            if (nY0 < 0)
            {
                nY0 = 0;
            }
            if (nY1 >= 48)
            {
                nY1 = 47;
            }

            DLIGHTMAP_FillLightGrid(nX0, nY0, nX1, nColor, nY1);
        }
    }
}

// 0x00474790
void __cdecl DLIGHTMAP_ClearLightGrid()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
        UNITS_GetRoom(pPlayer);

    DLIGHTMAP_FillLightGrid(0, 0, 0x2F, 0, 0x2F);
}

// 0x004747C0
static void __stdcall DLIGHTMAP_AddGridLight(int nIntensity, unsigned char nRed, unsigned char nGreen, unsigned char nBlue, int nY, int nX)
{
    const int nGridX = (nX >> 3) - gnCellOriginX_007B0A54;
    if ((unsigned int)nGridX > 0x2F)
    {
        return;
    }

    const int nGridY = (nY >> 3) - gnCellOriginY_007B0A58;
    if ((unsigned int)nGridY > 0x2F)
    {
        return;
    }

    D2GridCellStrc* pCell = &gtGridCells_007B0E68[nGridY * 48 + nGridX];
    const int nOld = pCell->nValue0;
    const unsigned int nNew = LIGHT_MIN((unsigned int)(nOld + nIntensity), 0xFFu);

    if (gbBlendLightColor)
    {
        const unsigned int nRecip = gadwReciprocals[nNew];
        int nR = (pCell->nValue1 * nOld + nRed * nIntensity) * nRecip >> 0x10;
        if (nR > 0xFF)
        {
            nR = 0xFF;
        }
        int nG = (pCell->f_6 * nOld + nGreen * nIntensity) * nRecip >> 0x10;
        if (nG > 0xFF)
        {
            nG = 0xFF;
        }
        int nB = (pCell->nValue3 * nOld + nBlue * nIntensity) * nRecip >> 0x10;
        if (nB > 0xFF)
        {
            nB = 0xFF;
        }
        pCell->nValue0 = (unsigned char)nNew;
        pCell->nValue1 = (unsigned char)nR;
        pCell->f_6 = (unsigned char)nG;
        pCell->nValue3 = (unsigned char)nB;
    }
    else
    {
        pCell->nValue1 = 0;
        pCell->f_6 = 0;
        pCell->nValue3 = 0;
        pCell->nValue0 = (unsigned char)nNew;
    }
}

int __stdcall sub_W04_Emit_004740D0(int nX, int nY, int nDx, int nDy)
{
    int nA = nX - nDx;
    if (nA < 0) nA = -nA;
    int nB = nY - nDy;
    if (nB < 0) nB = -nB;
    return DLIGHTMAP_ApproxDistance(nB, nA) + nX;
}

void __stdcall sub_W04_Emit_00474B50(D2R01LightStrc* pPoint, int nX, int nY)
{
    DLIGHTMAP_SetupStepDirection(nX, nY, pPoint);
    DLIGHTMAP_SetupStepDirection(nY, nX, pPoint);
}

// 0x004748D0
static void __stdcall DLIGHTMAP_AddAreaLight(D2R01LightStrc* pLight, int bNoClamp)
{
    int nRadius = pLight->nRadius;
    if ((unsigned int)(nRadius - 1) > 0xFE)
    {
        return;
    }

    if (!bNoClamp)
    {
        switch (pLight->nUnitType)
        {
        case 0:
        {
            D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
            if (pLight->nUnitId != (!pPlayer ? -1 : pPlayer->dwUnitId) && nRadius >= 0x10)
            {
                nRadius = 0x10;
            }
            break;
        }
        case 1:
            nRadius = 8;
            break;
        case 3:
            return;
        }
    }

    const int nStartX = pLight->nX - (pLight->nX & 7) - nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - nRadius;
    const int nSpan = (nRadius * 2) >> 3;
    if ((nStartX >> 3) > gnCellLimitX || (nStartX >> 3) + nSpan + 1 < gnCellOriginX_007B0A54
        || (nStartY >> 3) > gnCellLimitY || (nStartY >> 3) + nSpan + 1 < gnCellOriginY_007B0A58)
    {
        return;
    }

    const int nScale = (pLight->nIntensity << 0x10) / nRadius;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        const int nDiffY = pLight->nY - nY;
        const int nDy = LIGHT_ABS(nDiffY);
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            const int nDiffX = pLight->nX - nX;
            const int nDx = LIGHT_ABS(nDiffX);
            const int nValue = (int)(nRadius - DLIGHTMAP_ApproxDistance(nDy, nDx)) * nScale >> 0x10;
            if (nValue > 0)
            {
                DLIGHTMAP_AddGridLight(nValue, pLight->nRed, pLight->nGreen, pLight->nBlue, nY, nX);
            }
            nX += 8;
        }
    }
}

// 0x00474A30
static inline unsigned char DLIGHTMAP_IsCellBlocked(int nX, int nY)
{
    nX = (nX >> 3) - gnCellOriginX_007B0A54;
    if (nX < 0)
    {
        return 1;
    }
    if (nX >= 0x30)
    {
        return 1;
    }
    nY = (nY >> 3) - gnCellOriginY_007B0A58;
    if (nY < 0)
    {
        return 1;
    }
    if (nY >= 0x30)
    {
        return 1;
    }
    return gaLightGrid[nY][nX].f_0;
}

void __stdcall sub_P08_Emit_004747C0(D2P08LightSourceStrc* pSource, int nX, int nY, int nIntensity)
{
    if (nIntensity > 0)
    {
        DLIGHTMAP_AddGridLight(nIntensity, pSource->nRed, pSource->nGreen, pSource->nBlue, nY, nX);
    }
}

// 0x00474A70
static void DLIGHTMAP_BuildOverrideWindow(D2R01LightStrc* pLight)
{
    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    const int nSpan = (pLight->nRadius * 2) >> 3;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        unsigned int* pCell = &gadwLightOverrideRows[nOffset + j][nOffset];
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            *pCell++ = DLIGHTMAP_IsCellBlocked(nX, nY) << 4;
            nX += 8;
        }
    }
}

// 0x00474B50
static void __stdcall DLIGHTMAP_SetupStepDirection(int nX, int nY, D2R01LightStrc* pPoint)
{
    int nDx = pPoint->nX - nX;
    int nDy = pPoint->nY - nY;
    if (!nDx && !nDy)
    {
        gnPathStepMode = 0;
        return;
    }

    if (nDx < 0)
    {
        gnPathStepSignX = -1;
        nDx = -nDx;
    }
    else
    {
        gnPathStepSignX = 1;
    }

    if (nDy < 0)
    {
        gnPathStepSignY = -1;
        nDy = -nDy;
    }
    else
    {
        gnPathStepSignY = 1;
    }

    if (!nDx)
    {
        gnPathStepMode = 4;
        return;
    }

    if (!nDy)
    {
        gnPathStepMode = 1;
        return;
    }

    if (nDx >= nDy)
    {
        gnPathStepMode = 2;
        gnPathStepRatio = (nDy << 8) / nDx;
    }
    else
    {
        gnPathStepMode = 3;
        gnPathStepRatio = (nDx << 8) / nDy;
    }
}

void __stdcall sub_R01_Emit_004748D0(D2R01LightStrc* pLight, int nMode)
{
    if (pLight->nUnitType != 6)
    {
        DLIGHTMAP_AddAreaLight(pLight, nMode);
    }
    pLight->nRadius = 0;
}

// 0x00474C00
static void DLIGHTMAP_BlendLightCell(int nCol, int nRow)
{
    int nValue1;
    int nValue2;
    switch (gnPathStepMode)
    {
    case 0:
        return;

    case 2:
        LIGHT_CELL(nValue1, nRow, gnPathStepSignX + nCol);
        LIGHT_CELL(nValue2, nRow + gnPathStepSignY, gnPathStepSignX + nCol);
        gadwLightMapRows[nRow][nCol] = ((0x100 - gnPathStepRatio) * nValue1 + gnPathStepRatio * nValue2) >> 8;
        break;

    case 3:
        LIGHT_CELL(nValue1, nRow + gnPathStepSignY, nCol);
        LIGHT_CELL(nValue2, nRow + gnPathStepSignY, gnPathStepSignX + nCol);
        gadwLightMapRows[nRow][nCol] = ((0x100 - gnPathStepRatio) * nValue1 + gnPathStepRatio * nValue2) >> 8;
        break;

    case 1:
        LIGHT_CELL(nValue1, nRow, gnPathStepSignX + nCol);
        gadwLightMapRows[nRow][nCol] = nValue1;
        break;

    case 4:
        LIGHT_CELL(nValue1, nRow + gnPathStepSignY, nCol);
        gadwLightMapRows[nRow][nCol] = nValue1;
        break;
    }
}

static unsigned int __stdcall sub_004740D0_ApproxDistanceInl(int nB, int nA)
{
    const int nAbsA = abs(nA);
    const int nAbsB = abs(nB);
    if (nAbsA >= nAbsB)
    {
        return (unsigned int)(nAbsA * 0x3D7 + nAbsB * 0x197) >> 10;
    }

    return (unsigned int)(nAbsB * 0x3D7 + nAbsA * 0x197) >> 10;
}

// 0x00474D70
static void DLIGHTMAP_AddBlendedAreaLight(D2R01LightStrc* pLight)
{
    if (pLight->nRadius <= 0 || pLight->nRadius >= 0x100)
    {
        return;
    }

    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nSpan = (pLight->nRadius * 2) >> 3;
    const int nCellStartX = nStartX >> 3;
    if (nCellStartX > gnCellLimitX || nCellStartX + nSpan + 1 < gnCellOriginX_007B0A54)
    {
        return;
    }

    const int nCellStartY = nStartY >> 3;
    if (nCellStartY > gnCellLimitY || nCellStartY + nSpan + 1 < gnCellOriginY_007B0A58)
    {
        return;
    }

    memset(gadwLightMapRows, 0, 0x1000);
    const int nRadCells = pLight->nRadius >> 3;
    const int nCellX = pLight->nX >> 3;
    const int nCellY = pLight->nY >> 3;
    DLIGHTMAP_BuildOverrideWindow(pLight);

    int nHi = 0x20 + 2;
    for (int k = 2; k <= nRadCells; ++k, ++nHi)
    {
        const int nLo = 0x20 - k;
        const int nTopX = (nCellX + k) * 8 + 4;
        const int nTopY = (nCellY + k) * 8 + 4;
        const int nBotX = (nCellX - k) * 8 + 4;
        const int nBotY = (nCellY - k) * 8 + 4;
        for (int m = 0; m <= k; ++m)
        {
            const int nUpX = (nCellX + m) * 8 + 4;
            const int nUpY = (nCellY + m) * 8 + 4;
            const int nDnX = (nCellX - m) * 8 + 4;
            const int nDnY = (nCellY - m) * 8 + 4;
            DLIGHTMAP_SetupStepDirection(nDnX, nBotY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 - m, nLo);
            DLIGHTMAP_SetupStepDirection(nUpX, nBotY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 + m, nLo);
            DLIGHTMAP_SetupStepDirection(nDnX, nTopY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 - m, nHi);
            DLIGHTMAP_SetupStepDirection(nUpX, nTopY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 + m, nHi);
            DLIGHTMAP_SetupStepDirection(nTopX, nDnY, pLight);
            DLIGHTMAP_BlendLightCell(nHi, 0x20 - m);
            DLIGHTMAP_SetupStepDirection(nTopX, nUpY, pLight);
            DLIGHTMAP_BlendLightCell(nHi, 0x20 + m);
            DLIGHTMAP_SetupStepDirection(nBotX, nDnY, pLight);
            DLIGHTMAP_BlendLightCell(nLo, 0x20 - m);
            DLIGHTMAP_SetupStepDirection(nBotX, nUpY, pLight);
            DLIGHTMAP_BlendLightCell(nLo, 0x20 + m);
        }
    }

    const int nScale = (pLight->nIntensity << 0x10) / pLight->nRadius;
    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + j * 8;
        const int nDiffY = pLight->nY - nY;
        const int nDy = LIGHT_ABS(nDiffY);
        int nX = nStartX;
        for (int i = 0; i <= nSpan; ++i)
        {
            const int nMask = gadwLightMapRows[nOffset + j][nOffset + i];
            if (nMask < 0x10)
            {
                const int nDiffX = pLight->nX - nX;
                const int nDx = LIGHT_ABS(nDiffX);
                int nValue = (int)(pLight->nRadius - sub_004740D0_ApproxDistanceInl(nDy, nDx)) * nScale >> 0x10;
                nValue = nValue * (8 - (nMask >> 1)) >> 3;
                if (nValue > 0)
                {
                    DLIGHTMAP_AddGridLight(nValue, pLight->nRed, pLight->nGreen, pLight->nBlue, nY, nX);
                }
            }
            nX += 8;
        }
    }
}

void __stdcall sub_E4F1_Emit_00474D70(int nLevel, D2R01LightStrc* pLight)
{
    if (!pLight->nMode && nLevel > 1)
    {
        DLIGHTMAP_AddBlendedAreaLight(pLight);
        return;
    }

    pLight->nRadius = 0;
}

static inline unsigned char sub_K01_GetGridCellByte(int nX, int nY)
{
    const int nGridX = (nX >> 3) - gnCellOriginX;
    if (nGridX < 0)
    {
        return 1;
    }
    if (nGridX >= 0x30)
    {
        return 1;
    }

    const int nGridY = (nY >> 3) - gnCellOriginY;
    if (nGridY < 0)
    {
        return 1;
    }
    if (nGridY >= 0x30)
    {
        return 1;
    }

    return (unsigned char)gtGridCells_007B0E68[nGridY * 48 + nGridX].nFlag;
}

// 0x004750F0
static void DLIGHTMAP_BuildLightMask(D2R01LightStrc* pLight)
{
    if (pLight->nRadius <= 0 || pLight->nRadius >= 0x100)
    {
        return;
    }

    const int nSpan = (pLight->nRadius * 2) >> 3;
    memset(gadwLightMapRows, 0, 0x1000);
    const int nRadCells = pLight->nRadius >> 3;
    const int nCellX = pLight->nX >> 3;
    const int nCellY = pLight->nY >> 3;
    if (pLight->nUnitType == 6)
    {
        return;
    }

    D2UnitStrc* pUnit = pLight->f_8 ? CUNIT_FindServerSideUnit(pLight->nUnitId, pLight->nUnitType)
                                            : CUNIT_FindClientUnit(pLight->nUnitId, pLight->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(pRoom, 0x414);

    const int nBaseX = CLIENTS_GetUnitX(pUnit) - 0x20;
    const int nBaseY = CLIENTS_GetUnitY(pUnit) - 0x20;
    for (int j = 0; j < 0x40; ++j)
    {
        for (int i = 0; i < 0x40; ++i)
        {
            gadwLightOverrideRows[j][i] = COLLISION_CheckMask(pRoom, i + nBaseX, j + nBaseY, 0x22) ? 0x10 : 0;
        }
    }

    int nHi = 0x20 + 2;
    for (int k = 2; k <= nRadCells; ++k, ++nHi)
    {
        const int nLo = 0x20 - k;
        const int nTopX = (nCellX + k) * 8 + 4;
        const int nTopY = (nCellY + k) * 8 + 4;
        const int nBotX = (nCellX - k) * 8 + 4;
        const int nBotY = (nCellY - k) * 8 + 4;
        for (int m = 0; m <= k; ++m)
        {
            const int nUpX = (nCellX + m) * 8 + 4;
            const int nUpY = (nCellY + m) * 8 + 4;
            const int nDnX = (nCellX - m) * 8 + 4;
            const int nDnY = (nCellY - m) * 8 + 4;
            DLIGHTMAP_SetupStepDirection(nDnX, nBotY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 - m, nLo);
            DLIGHTMAP_SetupStepDirection(nUpX, nBotY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 + m, nLo);
            DLIGHTMAP_SetupStepDirection(nDnX, nTopY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 - m, nHi);
            DLIGHTMAP_SetupStepDirection(nUpX, nTopY, pLight);
            DLIGHTMAP_BlendLightCell(0x20 + m, nHi);
            DLIGHTMAP_SetupStepDirection(nTopX, nDnY, pLight);
            DLIGHTMAP_BlendLightCell(nHi, 0x20 - m);
            DLIGHTMAP_SetupStepDirection(nTopX, nUpY, pLight);
            DLIGHTMAP_BlendLightCell(nHi, 0x20 + m);
            DLIGHTMAP_SetupStepDirection(nBotX, nDnY, pLight);
            DLIGHTMAP_BlendLightCell(nLo, 0x20 - m);
            DLIGHTMAP_SetupStepDirection(nBotX, nUpY, pLight);
            DLIGHTMAP_BlendLightCell(nLo, 0x20 + m);
        }
    }

    D2_ASSERT(!pLight->bMaskReady, 0x454);
    D2_ASSERT(pLight->pMask, 0x455);

    const int nOffset = 0x20 - (pLight->nRadius >> 3);
    unsigned int* pDst = pLight->pMask;
    for (int y = 0; y <= nSpan; ++y)
    {
        for (int x = 0; x <= nSpan; ++x)
        {
            *pDst++ = gadwLightMapRows[nOffset + y][nOffset + x];
        }
    }

    pLight->bMaskReady = 1;
}

// 0x00475420
static void DLIGHTMAP_AddMaskedAreaLight(D2R01LightStrc* pLight)
{
    if (pLight->nRadius <= 0 || pLight->nRadius >= 0x100)
    {
        return;
    }

    const int nStartX = pLight->nX - (pLight->nX & 7) - pLight->nRadius;
    const int nStartY = pLight->nY - (pLight->nY & 7) - pLight->nRadius;
    const int nSpan = (pLight->nRadius * 2) >> 3;
    int nCell = nStartX >> 3;
    if (nCell > gnCellLimitX || nCell + nSpan + 1 < gnCellOriginX)
    {
        return;
    }

    nCell = nStartY >> 3;
    if (nCell > gnCellLimitY || nCell + nSpan + 1 < gnCellOriginY)
    {
        return;
    }

    D2_ASSERT(pLight->pMask, 0x47E);
    D2_ASSERT(pLight->bMaskReady, 0x47F);

    const int nScale = (pLight->nIntensity << 0x10) / pLight->nRadius;
    int* pMask = (int*)pLight->pMask;
    for (int j = 0; j <= nSpan; ++j)
    {
        const int nY = nStartY + 8 * j;
        const int nDiffY = pLight->nY - nY;
        const int nDy = LIGHT_ABS(nDiffY);
        for (int i = 0; i <= nSpan; ++i)
        {
            const int nX = nStartX + 8 * i;
            const int nMaskValue = *pMask;
            if (nMaskValue < 0x10)
            {
                const int nDiffX = pLight->nX - nX;
                const int nDx = LIGHT_ABS(nDiffX);
                int nValue = (pLight->nRadius - DLIGHTMAP_GetDistance(nDx, nDy)) * nScale >> 0x10;
                nValue = nValue * (8 - (nMaskValue >> 1)) >> 3;
                if (nValue > 0)
                {
                    DLIGHTMAP_AddGridLight(nValue, pLight->nRed, pLight->nGreen, pLight->nBlue, nY, nX);
                }
            }
            ++pMask;
        }
    }
}

// 0x004755A0
static void __stdcall DLIGHTMAP_UpdateLight(int nLevel, D2R01LightStrc* pLight)
{
    if (!pLight->bFixed && pLight->nUnitType != 6)
    {
        D2UnitStrc* pUnit = pLight->f_8 ? CUNIT_FindServerSideUnit(pLight->nUnitId, pLight->nUnitType)
                                                : CUNIT_FindClientUnit(pLight->nUnitId, pLight->nUnitType);
        if (pUnit)
        {
            const int nPrecX = UNITS_GetPrecisionX(pUnit);
            const int nPrecY = UNITS_GetPrecisionY(pUnit);
            pLight->nX = (nPrecX >> 0xD) + 4;
            pLight->nY = (nPrecY >> 0xD) + 4;
        }
    }

    if (pLight->nTargetRadius != pLight->nRadius)
    {
        if (pLight->nMode == 2)
        {
            pLight->bMaskReady = 0;
            if (pLight->pMask)
            {
                FOG_Free(pLight->pMask, ".\\DRAW\\dLightMap.cpp", 0x4CC, 0);
            }
            pLight->pMask = 0;
        }

        if (pLight->nTargetRadius > pLight->nRadius)
        {
            pLight->nRadius += 8;
        }
        else
        {
            pLight->nRadius -= 8;
        }
    }

    if (pLight->nRadius >= 0x100)
    {
        pLight->nRadius = 0xF8;
    }

    if (pLight->bFixed && pLight->nRadius <= 0)
    {
        DLIGHTMAP_ReleaseLight(pLight);
        return;
    }

    if (!pLight->nMode && nLevel > 1)
    {
        DLIGHTMAP_AddBlendedAreaLight(pLight);
        return;
    }

    if (pLight->nMode == 2)
    {
        if (!pLight->bMaskReady)
        {
            if (!pLight->pMask)
            {
                const int nSide = 2 * (pLight->nRadius >> 3) + 1;
                pLight->pMask = (unsigned int*)FOG_Alloc(nSide * nSide * sizeof(unsigned int), ".\\DRAW\\dLightMap.cpp", 0x4F1, 0);
            }
            DLIGHTMAP_BuildLightMask(pLight);
        }
        DLIGHTMAP_AddMaskedAreaLight(pLight);
        return;
    }

    DLIGHTMAP_AddAreaLight(pLight, nLevel);
}

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740


// 0x004756D0
void __cdecl DLIGHTMAP_ScanGridCollision()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;
    for (int nY = 0; nY < 0x30; ++nY)
    {
        for (int nX = 0; nX < 0x30; ++nX)
        {
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, gnCellOriginX + nX, gnCellOriginY + nY);
            if (!pRoom)
                pRoom = UNITS_GetRoom(pPlayer);
            if (COLLISION_CheckMask(pRoom, gnCellOriginX + nX, gnCellOriginY + nY, 0x22))
                gtGridCells_007B0E68[nY * 0x30 + nX].nFlag = 1;
        }
    }
}

// 0x00475AA0
void __fastcall SCMD_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3)
{
// build: symbol ?gnCellOriginX@* 0x007B0A54
    int nCellX = (nX >> 3) - gnCellOriginX;
// build: symbol ?gnCellOriginY@* 0x007B0A58
    int nCellY = (nY >> 3) - gnCellOriginY;

    if (nCellX < 0)
    {
        nCellX = 0;
    }
    else if (nCellX > GRID_SIZE - 1)
    {
        nCellX = GRID_SIZE - 1;
    }

    if (nCellY < 0)
    {
        nCellY = 0;
    }
    else if (nCellY > GRID_SIZE - 1)
    {
        nCellY = GRID_SIZE - 1;
    }

    D2GridCellStrc* pCell = &gtGridCells_007B0E68[nCellY * GRID_SIZE + nCellX];
    *pValue0 = pCell->nValue0;
    if (gnGlobal_00712B8C)
    {
        *pValue1 = pCell->nValue1;
        *pValue2 = pCell->f_6;
        *pValue3 = pCell->nValue3;
    }
}

// 0x00475B20
void __cdecl DLIGHTMAP_DebugDrawLights()
{
    D2R01LightStrc* pLight = gpLights;
    D2GFX_DebugDraw(gdwLightMap_007A8A50, gdwLightGrid_007B0E68, pLight->nX, pLight->nY);
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00475930
void __fastcall DLIGHTMAP_ActRoomCallback(D2ActiveRoomStrc* pRoom)
{
    for (D2R01LightStrc* pLight = gpLights; pLight; pLight = pLight->pNext)
    {
        if (pLight->nMode == 2)
        {
            D2UnitStrc* pUnit = 0;
            if (pLight->nUnitType != 6)
            {
                unsigned int const tNUnitId = pLight->nUnitId;
                pUnit = pLight->f_8 ? CUNIT_FindServerSideUnit(tNUnitId, pLight->nUnitType)
                                    : CUNIT_FindClientUnit(tNUnitId, pLight->nUnitType);
            }
            D2_ASSERT(pUnit, 1425);

            D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
            if (pUnitRoom != pRoom)
            {
                const unsigned int nX = CLIENTS_GetUnitXInline(pUnit);
                const unsigned int nY = CLIENTS_GetUnitYInline(pUnit);
                const int nRadius = pLight->nRadius >> 3;
                if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX + nRadius, nY) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
                else if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX - nRadius, nY) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
                else if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX, nY + nRadius) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
                else if (COLLISION_GetRoomBySubTileCoordinates(pUnitRoom, nX, nY - nRadius) == pRoom)
                {
                    pLight->bMaskReady = 0;
                }
            }
        }
    }
}

void sub_M241_Emit_00474D70(D2R01LightStrc* pLight)
{
    DLIGHTMAP_BuildOverrideWindow(pLight);
}

// 0x00475B40
void __cdecl DLIGHTMAP_InitLightTables()
{
    DUNGEON_SetActCallbackFunc(gpGlobal_007A0634, DLIGHTMAP_ActRoomCallback);
    gadwReciprocals[0] = 0;
    for (int i = 1; i < 0x100; ++i)
    {
        gadwReciprocals[i] = 0x10000u / i;
    }
}

struct D2GfxLightStrc;


// 0x00475C40
unsigned char** __stdcall GFX_BuildLerpRowTable(unsigned int nCount, int nSteps)
{
    unsigned char** pTable = (unsigned char**)sub_00517993_VirtualAlloc((nSteps + 1) * nCount * nCount * sizeof(unsigned char*));
    unsigned char** pOut = pTable;
    unsigned char nIndex;
    for (int i = 0; i < nCount; ++i)
    {
        for (int j = 0; j < nCount; ++j)
        {
            int nStep = ((j - i) << 16) / nSteps;
            int nValue = i << 16;
            for (unsigned int k = 0; k < nSteps; ++k)
            {
                nIndex = nValue / 65536;
                *pOut++ = gabRowTable[nIndex];
                nValue += nStep;
            }
            *pOut++ = gabRowTable[nIndex];
        }
    }
    return pTable;
}

// 0x00475D20
void __fastcall sub_00475D20_FreeIfSet(void* pMemory)
{
    if (pMemory)
    {
        sub_005179A4_VirtualFree(pMemory);
    }
}



// 0x00475D30
unsigned char** __stdcall SCMD_BuildRampTable(unsigned int nSize, int nSteps)
{
    unsigned char** ppTable = (unsigned char**)sub_00517993_VirtualAlloc(nSize * nSize * nSteps * sizeof(unsigned char*));
    unsigned char** ppEntry = ppTable;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < nSize; ++j)
        {
            const int nStep = ((j - i) << 16) / nSteps;
            int nValue = i << 16;
            for (unsigned int k = 0; k < nSteps; ++k)
            {
                *ppEntry = gabRowTable[(unsigned char)(nValue / 0x10000)];
                ++ppEntry;
                nValue += nStep;
            }
        }
    }
    return ppTable;
}

// 0x00475DE0
void __fastcall sub_00475DE0_FreeIfSet(void* pMemory)
{
    if (pMemory)
    {
        sub_005179A4_VirtualFree(pMemory);
    }
}




int __stdcall D2GFX_TogglePerspective();                                                                    // 0x004F54B0

int __stdcall D2GFX_ToggleBlendedShadows();                                                                 // 0x004F54D0

int __stdcall D2GFX_ToggleLowQuality();                                                                     // 0x004F54F0








void __cdecl VIEW_ToggleCacheStats();                                                               // 0x00477C00

extern int gbCacheStats;                                                                           // 0x007BB3A4

int gbCacheStatsChecked;                                                                                      // 0x007BB3AC



// 0x00478150
int __cdecl sub_00478150()
{
    return gdwGlobal_007BB3B4;
}










// 0x00486E00
int __cdecl sub_00486E00()
{
    return 0;
}

// 0x00489870
int __cdecl sub_00489870()
{
    return gdwGlobal_007BCC48;
}

// 0x00489CD0
void __stdcall sub_00489CD0(int nUnused1)
{
}

// 0x0048BDF0
void __stdcall sub_0048BDF0(int nUnused1)
{
}



// 0x0049E8A0
int __cdecl sub_0049E8A0()
{
    return gdwGlobal_007BF1F6;
}

// 0x0049F900
int __cdecl DLIGHTMAP_GetTextHeader()
{
    return gdwGlobal_007BF250;
}

// 0x004A8A20
int __cdecl sub_004A8A20()
{
    return 7;
}

// 0x00475780
int __cdecl DLIGHTMAP_GetIndicatorLevel()
{
    int nValue;
    int nLevel = 2;
    if (D2GFX_CheckLowQuality())
    {
        if (!MISSILE_GetMissileLights())
        {
            goto low;
        }
        nLevel = 1;
    }
    nValue = GAME_GetFramesPerSecond();
    if (nValue <= 9)
    {
low:
        nLevel = 0;
    }
    else if (nValue <= 12)
    {
        nLevel = 1;
    }
    else if (nValue <= 15)
    {
        if (gnIndicatorLevel >= 1)
        {
            return gnIndicatorLevel;
        }
        nLevel = 1;
    }
    if (nLevel != gnIndicatorLevel)
    {
        const unsigned long dwTick = GetTickCount();
        if (dwTick - gdwIndicatorTick > INDICATOR_HOLD_MS)
        {
            gdwIndicatorTick = dwTick;
            gnIndicatorLevel = nLevel;
        }
        else
        {
            return gnIndicatorLevel;
        }
    }
    return nLevel;
}

// 0x00475800
void __cdecl DLIGHTMAP_RunLightPass()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nX = CLIENTS_GetUnitXInline(pPlayer);
    const int nY = CLIENTS_GetUnitYInline(pPlayer);
    gnCellOriginX = nX - 0x18;
    gnCellOriginY = nY - 0x18;
    gnCellLimitX = gnCellOriginX + 0x30;
    gnCellLimitY = gnCellOriginY + 0x30;
    DLIGHTMAP_UpdateLightGrid(0);
    DLIGHTMAP_ScanGridCollision();
    const int nLevel = DLIGHTMAP_GetIndicatorLevel();
    gnLightCount = 0;
    D2R01LightStrc* pLight = gpLights;
    while (pLight)
    {
        ++gnLightCount;
        D2R01LightStrc* pNext = pLight->pNext;
        DLIGHTMAP_UpdateLight(nLevel, pLight);
        pLight = pNext;
    }
}

// 0x004758D0
void __cdecl DLIGHTMAP_FreeAllLights()
{
    D2R01LightStrc* pLight = gpLights;
    while (pLight)
    {
        D2R01LightStrc* pNext = pLight->pNext;
        if (pLight->pMask)
        {
            FOG_Free(pLight->pMask, ".\\DRAW\\dLightMap.cpp", 1405, 0);
        }
        FOG_Free(pLight, ".\\DRAW\\dLightMap.cpp", 1407, 0);
        pLight = pNext;
    }

    gpLights = 0;
}

#include "gen/data/Source/D2Client/DRAW/dLightMap.inc"
