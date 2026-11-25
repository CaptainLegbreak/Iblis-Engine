#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DrlgTiles.h"
#include "D2Drlg.h"

#define LVLPREST_ACT3_JUNGLE_HEAD 573
#define LVLPREST_ACT3_JUNGLE_TAIL 574

union D2SeedStrc;
struct D2DrlgStrc;
struct D2LevelDefBin;
struct D2DrlgOutdoorInfoStrc;





extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0
extern const int gnJungleDefOffsets[3]; // 0x006F2370
extern const int gnJungleFiles[18]; // 0x006F2328
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770
void __fastcall DRLGOUTJUNG_BuildJungle(D2DrlgLevelStrc* pLevel); // 0x0067E910
void __fastcall DRLGOUTJUNG_SpawnRandomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nMaxSpawns); // 0x0067EED0


void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480
int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, int nFlags); // 0x00674230

// 0x0067E910
void __fastcall DRLGOUTJUNG_BuildJungle(D2DrlgLevelStrc* ptDrlgLevel)
{
    switch (ptDrlgLevel->eLevelId)
    {
    case LEVEL_SPIDERFOREST:
    case LEVEL_GREATMARSH:
    case LEVEL_FLAYERJUNGLE:
    {
        D2LevelDefBin* pLevelDefBin = DATATBLS_GetLevelDefRecord(LEVEL_SPIDERFOREST);
        const int nSizeX = pLevelDefBin->dwSizeX[ptDrlgLevel->pDrlg->nDifficulty] / 32;
        const int nSizeY = pLevelDefBin->dwSizeY[ptDrlgLevel->pDrlg->nDifficulty] / 32;
        int nDefId = 0;

        const int nRand = SEED_RollLimitedRandomNumber(&ptDrlgLevel->pSeed, 4 * (ptDrlgLevel->nJungleDefs == 3) + 2);
        int nFileIndex = 0;

        D2_ASSERT(ptDrlgLevel->pnJungleDefs, 0x27);

        for (int i = 0; i < nSizeY; ++i)
        {
            if (ptDrlgLevel->eLevelId == LEVEL_SPIDERFOREST && i == nSizeY - 1)
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(ptDrlgLevel, 0, 4 * i, LVLPREST_ACT3_JUNGLE_HEAD, ptDrlgLevel->pnJungleDefs[nSizeX * nSizeY - 1] == 0, 0);
                nDefId += 2;
            }
            else if (ptDrlgLevel->eLevelId == LEVEL_FLAYERJUNGLE && i == 0)
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(ptDrlgLevel, 0, 0, LVLPREST_ACT3_JUNGLE_TAIL, ptDrlgLevel->pnJungleDefs[1] == 0, 0);
                nDefId += 2;
            }
            else
            {
                for (int j = 0; j < nSizeX; ++j)
                {
                    int nJungleDef = ptDrlgLevel->pnJungleDefs[nDefId++];
                    int nPickedFile = -1;
                    if (nJungleDef > LVLPREST_ACT3_JUNGLE_TAIL)
                    {
                        D2_ASSERT(nFileIndex < 3, 0x47);

                        nJungleDef += gnJungleDefOffsets[ptDrlgLevel->eLevelId - LEVEL_SPIDERFOREST];
                        nPickedFile = gnJungleFiles[nFileIndex + 3 * nRand];
                        ++nFileIndex;
                    }

                    if (nJungleDef)
                    {
                        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(ptDrlgLevel, 4 * j, 4 * i, nJungleDef, nPickedFile, 0);
                    }
                }
            }
        }
        break;
    }
    }
}

#include "gen/data/Source/D2Common/DRLG/OutJung.inc"

// 0x0067EAD0
void __fastcall DRLGOUTJUNG_BuildLowerKurast(D2DrlgLevelStrc* pLevel)
{
    int nWidth = pLevel->nWidth / 8 - 1;
    int nHeight = pLevel->nHeight / 8 - 1;
    int nMiddle = nWidth / 2;
    int nGate = 0;

    if (pLevel->pDrlg->bJungleInterlink)
    {
        nGate = 1;
    }
    else
    {
        nGate = nWidth - 1;
    }

    for (int i = 1; i < nWidth; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, 0, (i == nGate) ? 0x25D + 8 : 0x25D, -1, 0);
    }

    for (int i = 1; i < nWidth; i += (i == nMiddle) + 1)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, nHeight, (i == nMiddle) ? 0x25E + 8 : 0x25E, -1, 0);
    }

    for (int i = 1; i < nHeight; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, i, 0x25F, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, i, 0x260, -1, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x262, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, 0, 0x261, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nHeight, 0x264, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, nHeight, 0x263, -1, 0);
}

// 0x0067EC30
void __fastcall DRLGOUTJUNG_BuildKurastBazaar(D2DrlgLevelStrc* pLevel)
{
    int nWidth = pLevel->nWidth / 8 - 1;
    int nHeight = pLevel->nHeight / 8 - 1;
    int nGateS = pLevel->pDrlg->bJungleInterlink ? 1 : nWidth - 1;
    int nGateN = pLevel->pDrlg->bJungleInterlink ? nWidth - 1 : 1;

    for (int i = 1; i < nWidth; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, 0, (i == nGateN) ? 0x26B + 8 : 0x26B, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, nHeight, (i == nGateS) ? 0x26C + 8 : 0x26C, -1, 0);
    }

    for (int i = 1; i < nHeight; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, i, 0x26D, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, i, 0x26E, -1, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x270, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, 0, 0x26F, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nHeight, 0x272, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, nHeight, 0x271, -1, 0);
}

// 0x0067ED70
void __fastcall DRLGOUTJUNG_BuildUpperKurast(D2DrlgLevelStrc* pLevel)
{
    int nWidth = pLevel->nWidth / 8 - 1;
    int nHeight = pLevel->nHeight / 8 - 1;
    int nGate = 0;

    if (pLevel->pDrlg->bJungleInterlink)
    {
        nGate = nWidth - 1;
    }
    else
    {
        nGate = 1;
    }

    int nHalf = nWidth / 2;
    for (int i = 1; i < nWidth; i += (i == nHalf) + 1)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, 0, (i == nHalf) ? 0x27C + 8 : 0x27C, -1, 0);
    }

    for (int i = 1; i < nWidth; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, i, nHeight, (i == nGate) ? 0x27D + 8 : 0x27D, -1, 0);
    }

    for (int i = 1; i < nHeight; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, i, 0x27E, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, i, 0x27F, -1, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x281, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, 0, 0x280, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nHeight, 0x283, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nWidth, nHeight, 0x282, -1, 0);
}

// 0x0067F190
void __fastcall DRLGOUTPLACE_BuildKurast(D2DrlgLevelStrc* pLevel)
{
    switch (pLevel->eLevelId)
    {
    case 79:
        DRLGOUTJUNG_BuildLowerKurast(pLevel);
        break;

    case 80:
        DRLGOUTJUNG_BuildKurastBazaar(pLevel);
        break;

    case 81:
        DRLGOUTJUNG_BuildUpperKurast(pLevel);
        break;

    default:
        break;
    }

    const int nRight = pLevel->nWidth / 8 - 4;
    const int nBottom = pLevel->nHeight / 8 - 4;

    switch (pLevel->eLevelId)
    {
    case 79:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x277, 0, 0, 15);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x26A, 0x26A, 4);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x268, 0x269, 0);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x267, 0x267, 0);
        break;

    case 80:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 3, 3, 0x275, 0, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nRight, 3, 0x275, 1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x276, 0, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x276, 1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x277, 0, 0, 15);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x27B, 0x27B, 4);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x279, 0x27A, 0);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x278, 0x278, 0);
        break;

    case 81:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 3, nBottom, 0x286, 0, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nRight, nBottom, 0x286, 1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x287, 0, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x287, 1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x277, 0, 0, 15);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x28B, 0x28B, 4);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x289, 0x28A, 0);
        DRLGOUTJUNG_SpawnRandomPreset(pLevel, 0x288, 0x288, 0);
        break;

    case 82:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x28C, 0, 0);
        break;

    default:
        return;
    }
}

// 0x0067F3B0
void __fastcall DRLGOUTJUNG_PlaceTravincalPresets(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_TRAVINCAL)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 0x28D, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 2, 0, 0x28E, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 6, 0, 0x28F, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 4, 0x290, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 2, 4, 0x291, -1, 0);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 6, 4, 0x292, -1, 0);
    }
}

// 0x0067F450
void __fastcall DRLGOUTPLACE_InitAct3OutdoorLevel(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    DRLGOUTJUNG_BuildJungle(pLevel);
    DRLGOUTPLACE_BuildKurast(pLevel);
    DRLGOUTJUNG_PlaceTravincalPresets(pLevel);
}

static inline unsigned int OUTJUNG_SeedStepInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int OUTJUNG_RollLimitedInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return OUTJUNG_SeedStepInline(pSeed) % nMax;
    }

    return OUTJUNG_SeedStepInline(pSeed) & (nMax - 1);
}

// 0x0067EED0
void __fastcall DRLGOUTJUNG_SpawnRandomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nMaxSpawns)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nVariants = nLevelPrestId2 - nLevelPrestId1 + 1;
    int nSpawned = 0;
    int nWidth = pOutdoors->nGridWidth;
    int nCount = pOutdoors->nGridHeight * nWidth;

    if (nCount)
    {
        D2CoordStrc* pCoords = (D2CoordStrc*)FOG_AllocPool(pMemPool, 8 * nCount, ".\\DRLG\\OutJung.cpp", 0xCB, 0);

        for (int i = 0; i < nCount; ++i)
        {
            pCoords[i].nX = i % nWidth;
            pCoords[i].nY = i / nWidth;
        }

        for (int i = 0; i < nCount; ++i)
        {
            const unsigned int nA = OUTJUNG_RollLimitedInline(&pLevel->pSeed, nCount);
            const unsigned int nB = OUTJUNG_RollLimitedInline(&pLevel->pSeed, nCount);
            const D2CoordStrc tTemp = pCoords[nA];
            pCoords[nA] = pCoords[nB];
            pCoords[nB] = tTemp;
        }

        for (int i = 0; i < nCount; ++i)
        {
            const int nX = pCoords[i].nX;
            const int nY = pCoords[i].nY;
            const int nPreset = nLevelPrestId1 + OUTJUNG_RollLimitedInline(&pLevel->pSeed, nVariants);

            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nPreset, 0, 15))
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPreset, -1, 0);
                ++nSpawned;

                if (nMaxSpawns > 0 && nSpawned >= nMaxSpawns)
                {
                    FOG_FreePool(pMemPool, pCoords, ".\\DRLG\\OutJung.cpp", 0xEB, 0);
                    return;
                }
            }
        }

        FOG_FreePool(pMemPool, pCoords, ".\\DRLG\\OutJung.cpp", 0xF2, 0);
    }
}
