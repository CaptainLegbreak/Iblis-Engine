#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Win32System.h"


void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x00477620
int __fastcall sub_00477620_RollUnitValue(D2UnitStrc* pUnit, unsigned short nOffset)
{
    if (!pUnit)
    {
        return 9;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    SEED_InitLowSeed(pSeed, UNITS_GetWeaponClass(pUnit) + nOffset);
    return (unsigned int)SEED_RollRandomNumber(pSeed) % 30 + 9;
}

extern int gdwGlobal_007BB384; // 0x007BB384

// 0x00477680
int __cdecl DLIGHTMAP_GetLocalBloodPalette()
{
    return gdwGlobal_007BB384;
}

int __stdcall D2GFX_TogglePerspective();                                                                    // 0x004F54B0

// 0x00477690
int __cdecl sub_00477690_TogglePerspective()
{
    return D2GFX_TogglePerspective();
}

int __stdcall D2GFX_ToggleBlendedShadows();                                                                 // 0x004F54D0

// 0x004776A0
int __cdecl sub_004776A0_ToggleBlendedShadows()
{
    return D2GFX_ToggleBlendedShadows();
}

int __stdcall D2GFX_ToggleLowQuality();                                                                     // 0x004F54F0

// 0x004776B0
int __cdecl sub_004776B0_ToggleLowQuality()
{
    return D2GFX_ToggleLowQuality();
}

void __stdcall D2GFX_SetGamma(void* pArg); // 0x004F5230

// 0x004776C0
void __fastcall sub_004776C0(void* pArg)
{
    D2GFX_SetGamma(pArg);
}


extern "C" int gnLightmapRenderMode; // 0x00712CCC

extern "C" { int gnFlag_007BB3A8; }                                                                         // 0x007BB3A8

extern int gdwGlobal_007BB38C; // 0x007BB38C

// 0x004776D0
void __fastcall sub_004776D0_SetModeValues(int nModeValue, int nValue)
{
    gnLightmapRenderMode = nModeValue;
    gdwGlobal_007BB38C = nValue;
}

// 0x004776E0
void __cdecl sub_004776E0_SetModeValuesOne()
{
    gnLightmapRenderMode = 1;
    gdwGlobal_007BB38C = 1;
}

// 0x004776F0
extern "C" void __cdecl INV_SetRenderModeGlide()
{
    gnLightmapRenderMode = 4;
}

// 0x00477700
extern "C" void __cdecl INV_SetRenderModeOpenGL()
{
    gnLightmapRenderMode = 5;
}

// 0x00477710
extern "C" void __cdecl INV_SetRenderModeDirect3D()
{
    gnLightmapRenderMode = 6;
}

// 0x00477720
extern "C" void __cdecl INV_SetRenderModeRave()
{
    gnLightmapRenderMode = 7;
}

// 0x00477730
int __cdecl DLIGHTMAP_GetRenderMode()
{
    return gnLightmapRenderMode;
}


// 0x00477740
int __cdecl sub_00477740()
{
    return gdwGlobal_007BB38C;
}


struct D2CacheStatsStrc;


struct D2CacheStatsStrc
{
    unsigned int nFloorSize;
    int unk0x04;
    int nFloorMisses;
    unsigned int nSubtileSize;
    int unk0x10;
    int nSubtileMisses;
    unsigned int nSpriteSize[3];
    int unk0x24[3];
    int nSpriteMisses[3];
    int unk0x3C[3];
    int nSpriteAccesses[3];
    int unk0x54[3];
    int unk0x60[3];
};

// 0x00477750
int __cdecl VIEW_IsAcceleratedRenderMode()
{
    return gnLightmapRenderMode >= 4;
}

void __cdecl VIEW_ToggleCacheStats();                                                               // 0x00477C00

extern int gbCacheStats;                                                                           // 0x007BB3A4

int gbCacheStatsChecked;                                                                                      // 0x007BB3AC

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

void __stdcall D2CMPGetTileCacheHits(unsigned int* pSize, int* pMisses, int* pTotal, int* pUtilized); // 0x005FE010

// 0x00477760
void __cdecl sub_00477760_DrawCacheStats()
{
    char szText[0x400];
    int nTotal;
    int nMisses;
    int nUtilized;
    unsigned int nSize;
    D2CMPGetTileCacheHits(&nSize, &nMisses, &nTotal, &nUtilized);
    if (nTotal > 0)
    {
        const float fPercent = (float)(nMisses * 100.0 / nTotal);
        sprintf(szText, "Tile Cache: (%.2fK) %3.2f%%, Misses: %d, %d percent utilized\n", (float)nSize * 0.0009765625, fPercent, nMisses, nUtilized);
        D2GFX_OutputString(10, 0x30, szText);
    }
// build: symbol ?D2GFX_GetCacheResults@* 0x004F5290
    D2CacheStatsStrc* pStats = D2GFX_GetCacheResults();
    if (!pStats)
        return;
    if (pStats->nFloorSize)
    {
        sprintf(szText, "Floor Cache: (%.2fK) Misses: %d\n", (float)pStats->nFloorSize * 0.0009765625, pStats->nFloorMisses);
        D2GFX_OutputString(10, 0x3C, szText);
    }
    if (pStats->nSubtileSize)
    {
        sprintf(szText, "Subtile Cache: (%.2fK) Misses: %d\n", (float)pStats->nSubtileSize * 0.0009765625, pStats->nSubtileMisses);
        D2GFX_OutputString(10, 0x48, szText);
    }
    if (pStats->nSpriteSize[0])
    {
        sprintf(szText, "Sprite Cache 1: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSpriteSize[0] * 0.0009765625, pStats->nSpriteMisses[0], pStats->nSpriteAccesses[0]);
        D2GFX_OutputString(10, 0x54, szText);
    }
    if (pStats->nSpriteSize[1])
    {
        sprintf(szText, "Sprite Cache 2: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSpriteSize[1] * 0.0009765625, pStats->nSpriteMisses[1], pStats->nSpriteAccesses[1]);
        D2GFX_OutputString(10, 0x60, szText);
    }
    if (pStats->nSpriteSize[2])
    {
        sprintf(szText, "Sprite Cache 3: (%.2fK) Misses: %d, Accesses Per Frame: %d\n", (float)pStats->nSpriteSize[2] * 0.0009765625, pStats->nSpriteMisses[2], pStats->nSpriteAccesses[2]);
        D2GFX_OutputString(10, 0x6C, szText);
    }
}

// 0x00477970
void __cdecl sub_00477970_Empty()
{
}


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


extern "C" void __cdecl D2CMPResetTileCacheHits(); // 0x005FE060

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pStatus);            // 0x006CC1F4









































































































































































































int __stdcall GAME_GetPing(); // 0x0044CE60

int __cdecl GAME_GetSkippedFrames(); // 0x0044DAF0

int __cdecl UI_GetGfxMemory(); // 0x0046F980

int __cdecl UI_GetCofMemoryUsed(); // 0x0046F990

int __cdecl UI_GetCofMemoryLimit(); // 0x0046F9A0

int __cdecl D2CMPSpriteCacheGetMaxMemory(); // 0x005FEE40

int __cdecl D2CMPCelDataCacheGetUsedMemory(); // 0x005FEE60

int __cdecl D2CMPCelDataCacheGetMaxMemory(); // 0x005FEE70

int __stdcall sub_0040ABE0(); // 0x0040ABE0

void __cdecl sub_00481850(); // 0x00481850

unsigned int __cdecl D2CMPSpriteCacheGetUsedMemory(); // 0x005FEE10

int __cdecl D2GFX_GetDisplayType(); // 0x004F5140

extern "C" const char gszUnknownText[]; // 0x006CC780

unsigned int gnDisplayFps;        // 0x007BB390

unsigned int gdwFpsCounterTick;        // 0x007BB394

unsigned int gnFpsCounterFrames;        // 0x007BB398

unsigned int gnCacheStatsFrames;        // 0x007BB39C

unsigned int gdwCacheStatsStart;        // 0x007BB3A0

extern int g_007BB3A4; // 0x007BB3A4

extern int g_007BB3AC; // 0x007BB3AC

#define FRAME_INTERVAL 1000

#define SCREEN_X 10

#define SCREEN_RIGHT 160

#define MEMORY_SHIFT 20

// 0x00477980
void __fastcall sub_00477980()
{
    unsigned int nNow=GetTickCount();
    unsigned int nElapsed=nNow-gdwFpsCounterTick;
    if(g_007BB3A4 && !gdwCacheStatsStart){gdwCacheStatsStart=nNow;gnCacheStatsFrames=0;}
    if(nElapsed<=FRAME_INTERVAL){++gnFpsCounterFrames;++gnCacheStatsFrames;}
    else {gdwFpsCounterTick=nNow;gnDisplayFps=gnFpsCounterFrames;gnFpsCounterFrames=0;}
    if(!g_007BB3A4){gdwCacheStatsStart=0;return;}
    D2GFX_OutputString(SCREEN_X,2,"%d FPS  %d Skip",gnDisplayFps,GAME_GetSkippedFrames());
    D2GFX_OutputString(SCREEN_RIGHT,2,"Ping: %d",GAME_GetPing());
    D2MemoryStatusStrc memory;
    memory.dwLength=sizeof(memory);
    GlobalMemoryStatus(&memory);
    D2GFX_OutputString(SCREEN_X,16,"Phys:%d/%dm",((memory.dwTotalPhys-memory.dwAvailPhys)>>MEMORY_SHIFT)+1,(memory.dwTotalPhys>>MEMORY_SHIFT)+1);
    D2GFX_OutputString(SCREEN_RIGHT,16,"Page:%d/%dm",((memory.dwTotalPageFile-memory.dwAvailPageFile)>>MEMORY_SHIFT)+1,(memory.dwTotalPageFile>>MEMORY_SHIFT)+1);
    char text[32];
    switch(D2GFX_GetDisplayType()){
    case 1:sprintf(text,"Software");break;
    case 3:sprintf(text,"DirectDraw");break;
    case 4:sprintf(text,"Glide");break;
    case 5:sprintf(text,"OpenGL");break;
    case 6:sprintf(text,"Direct3D");break;
    case 2:sprintf(text,"Software");break;
    case 7:sprintf(text,"RAVE");break;
    default:sprintf(text,gszUnknownText);break;
    }
    D2GFX_OutputString(500,2,"Video: %s",text);
    if(!g_007BB3AC){
        D2GFX_OutputString(SCREEN_X,120,"GFX Memory->%i",UI_GetGfxMemory());
        D2GFX_OutputString(SCREEN_X,132,"COF Memory->%i of %i",UI_GetCofMemoryUsed(),UI_GetCofMemoryLimit());
        D2GFX_OutputString(SCREEN_X,144,"Sprite Cache Memory->%i of %i",D2CMPSpriteCacheGetUsedMemory(),D2CMPSpriteCacheGetMaxMemory());
        D2GFX_OutputString(SCREEN_X,156,"Async Files->%i",sub_0040ABE0());
        D2GFX_OutputString(SCREEN_X,168,"CelData Cache Memory->%i of %i",D2CMPCelDataCacheGetUsedMemory(),D2CMPCelDataCacheGetMaxMemory());
        sub_00481850();
        sub_00477760_DrawCacheStats();
    }
}

// 0x00477BE0
void __cdecl sub_00477BE0_ToggleFlag7BB3A8()
{
    gnFlag_007BB3A8 = gnFlag_007BB3A8 == 0;
}

// 0x00477C00
void __cdecl VIEW_ToggleCacheStats()
{
    gbCacheStatsChecked = 0;
    gbCacheStats = !gbCacheStats;
    if (!gbCacheStats)
        return;

// build: symbol ?D2GFX_GetCacheResults@* 0x004F5290
    D2CacheStatsStrc* pStats = D2GFX_GetCacheResults();
    if (pStats)
    {
        pStats->unk0x04 = 0;
        pStats->nFloorMisses = 0;
        pStats->unk0x10 = 0;
        pStats->nSubtileMisses = 0;
        memset(pStats->unk0x24, 0, sizeof(pStats->unk0x24));
        memset(pStats->nSpriteMisses, 0, sizeof(pStats->nSpriteMisses));
        memset(pStats->nSpriteAccesses, 0, sizeof(pStats->nSpriteAccesses));
        memset(pStats->unk0x60, 0, sizeof(pStats->unk0x60));
    }
    D2CMPResetTileCacheHits();
}

// 0x00477C60
void __cdecl sub_00477C60_CheckCacheStats()
{
    if (gbCacheStatsChecked || !gbCacheStats)
        VIEW_ToggleCacheStats();
    gbCacheStatsChecked = 1;
}

int gdwGlobal_007BB388; // 0x007BB388

// 0x00477C90
int __cdecl sub_00477C90()
{
    return gdwGlobal_007BB388;
}

#include "gen/data/Source/D2Client/Unknown_00477620.inc"
