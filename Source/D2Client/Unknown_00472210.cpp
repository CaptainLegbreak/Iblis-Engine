#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2CelContext.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct CellResource;
union D2SeedStrc;
struct D2WeatherSplashStrc;
struct D2PeriodLightStrc;
struct D2B10EmitWeatherStrc;

extern "C" double __cdecl fabs(double x);

static int __stdcall sub_004726F0(int bForce);

D2WeatherStrc* __fastcall DATAARRAYS_Create(const char* szName, int nCount, int nRecordSize); // 0x006BCA10
void __fastcall DATAARRAYS_Destroy(void* pBlock); // 0x006BCA90
void __fastcall DATAARRAYS_Initialize(D2WeatherStrc* pArray); // 0x006BCCC0
int __stdcall sub_004726F0(int nArg); // 0x004726F0
extern int gnGlobal_007A8A0C; // 0x007A8A0C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
void __fastcall sub_00473D00_SetPhase(int nPhase); // 0x00473D00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __cdecl D2GFX_GetDisplayType(); // 0x004F5140
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634
extern const D2PeriodLightStrc gaPeriodLights[]; // 0x006D6E40

struct D2B10EmitWeatherStrc
{
    char unk0x00[0x10];
    int nValue;
    char unk0x14[0x10];
    unsigned char nOut2;
};

extern CellResource* gHelpBorder;
extern CellResource* gWhiteBullet;
extern CellResource* gYellowBullet;
int __cdecl sub_0045AE90(); // 0x0045AE90
extern "C" void __stdcall D2GFX_DrawBox(int x1, int y1, int x2, int y2, int color, int mode); // 0x004F6300
extern "C" int __cdecl ResolutionMode();
extern "C" void __fastcall ReleaseCell(CellResource* resource);
extern "C" CellResource* __fastcall LoadCell(const char* filename);
extern "C" const char gHelpBorder800File[];
extern "C" const char gHelpBorderFile[];
extern "C" const char gWhiteBulletFile[];
extern "C" const char gYellowBulletFile[];
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
void __cdecl sub_00472400_ResetPhaseState(); // 0x00472400
extern unsigned int gnPhaseMax; // 0x007A89C0
extern int gnPhase; // 0x007A8A24

inline unsigned __int64 SEED_RollRandomNumberInline_00472210(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

__forceinline unsigned int RNG_RollLimitedRef(D2SeedStrc* pSeed, const int& nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;
    const unsigned int nRoll = (unsigned int)SEED_RollRandomNumberInline(pSeed);
    const int nMask = nMax;
    return nRoll & (nMask - 1);
}

static D2WeatherStrc* gpWeatherParticles; // 0x007A8A04

static D2WeatherStrc* gpWeatherSplashes; // 0x007A89FC

static D2WeatherStrc* gpWeatherBubbles; // 0x007A8A00

int gnBaseWindAngleMin; // 0x007A89DC

int gnBaseWindAngleMax; // 0x007A899C

static int gbLightningEnabled; // 0x007A8A08

int gnViewDeltaX; // 0x007A0678

int gnViewDeltaY; // 0x007A067C

struct D2WeatherLayerStateStrc;

struct D2WeatherLayerStateStrc
{
    D2CelFileStrc* apCelFiles[4];
};

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

static int gbWeatherSplash; // 0x007A8A14

static int gbSnowWeather; // 0x007A8A18

int gbPhaseActive; // 0x007A8A1C

static inline unsigned __int64 CLIENT_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static void __stdcall sub_00472590_SetSplash(int bForce, int bValue);

void __fastcall sub_00473D00_SetPhase(int nPhase);

static inline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

unsigned char gabPeriodLightColors[12]; // 0x007A898C

static void __stdcall sub_00472FB0_GetPeriodLight(unsigned char* pOut2, int nValue, unsigned char* pOut1);

void __cdecl sub_B10_Emit_00472FB0(D2B10EmitWeatherStrc* pWeather, unsigned char* pOut1)
{
    if (pWeather->nValue < 8 && pWeather->nValue >= 0)
    {
        sub_00472FB0_GetPeriodLight(&pWeather->nOut2, pWeather->nValue, pOut1);
    }
}

unsigned int gnPhaseTotal; // 0x007A8A38

unsigned int gnPhaseLeft; // 0x007A8A3C

struct D2ActiveRoomStrc;

struct D2GfxLightStrc;

extern int gnScreenWidth; // 0x0071146C

int __fastcall DATAARRAYS_AllocateHandle(D2WeatherStrc* pArray);                                             // 0x006BCB40

static inline unsigned __int64 sub_U01_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline void sub_U01_StepSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
}

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);

static inline void sub_00473720_GetLevelWeather(int* pRain, int* pMud);

int __cdecl sub_M112_Emit_00473720()
{
    int nRain;
    int nMud;
    sub_00473720_GetLevelWeather(&nRain, &nMud);
    return nRain + nMud;
}

int gbPhaseBusy; // 0x007A8A20

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define M341_ROLL_SEED_LOW(pSeed, nOut)                                                                     \
    {                                                                                                       \
        const unsigned __int64 lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed;              \
        (pSeed)->nLowSeed = (unsigned int)lSeed;                                                            \
        (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32);                                                   \
        nOut = (unsigned int)lSeed;                                                                         \
    }
struct D2WeatherLayerStateStrc;
union D2SeedStrc;
struct D2WeatherSplashStrc;
struct D2WeatherParticleStrc;
struct D2WeatherLineStrc;
struct D2PeriodLightStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280
int __fastcall DATAARRAYS_AllocateHandle(D2WeatherStrc* pArray); // 0x006BCB40

struct D2WeatherLineStrc
{
    int nX1;
    int nY1;
    int nX2;
    int nY2;
};
int __cdecl sub_0045AE90(); // 0x0045AE90
int __cdecl D2GFX_CheckLowQuality(); // 0x004F5210
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
extern D2WeatherLineStrc gaWeatherLines[]; // 0x006D6E78
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
void __fastcall sub_00473A70(D2WeatherStrc* pWeather, D2WeatherLayerStateStrc* pState); // 0x00473A70
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
void __fastcall SOUNDINST_MoveSound(int a1, int a2, int a3, int a4); // 0x004B99A0
extern "C" void __cdecl sub_004736C0_DrawPanelShade(); // 0x004736C0
void __cdecl sub_00473470(); // 0x00473470
extern unsigned int gdwGlobal_007BB390; // 0x007BB390

extern "C" double __cdecl fabs(double x);
int __cdecl D2GFX_GetDisplayType(); // 0x004F5140
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
int __cdecl sub_0044DB00(); // 0x0044DB00
void __fastcall sub_00472C80_StepSplashes(int nUnused); // 0x00472C80
void __fastcall sub_00472D10_StepBubbles(int nUnused); // 0x00472D10
void __stdcall GFX_StepWeatherPhase(D2SeedStrc* pSeed); // 0x00473E50

int gnGlobal_007A8A10; // 0x007A8A10

int gnLightningCountdown; // 0x007A8968

int gbLightningFlash; // 0x007A896C

int gnLightningFlashFrames; // 0x007A89E8

unsigned int gnWeatherLastTick; // 0x007A8A0C

int gbRainActive; // 0x007A8A44

int gbMudActive; // 0x007A8A40

static void sub_00473090_InitParticle(D2SeedStrc* pSeed);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __cdecl D2GFX_GetDisplayType();                                                                                 // 0x004F5140
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __fastcall DATAARRAYS_AllocateHandle(D2WeatherStrc* pArray);                                             // 0x006BCB40
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __cdecl sub_0044DB00(); // 0x0044DB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall sub_00472C80_StepSplashes(int nUnused);                                                     // 0x00472C80
void __fastcall sub_00472D10_StepBubbles(int nUnused);                                                      // 0x00472D10
void __stdcall GFX_StepWeatherPhase(D2SeedStrc* pSeed);                                                   // 0x00473E50
unsigned char gabParticleColorsTwilight[12];                                                                 // 0x007A894C
unsigned char gabParticleColorsDay[12];                                                                 // 0x007A8980
unsigned char gabParticleColorsNight[12];                                                                 // 0x007A89A4
unsigned int gnWeatherTick;                                                                        // 0x007A8A34

static void sub_00473090_InitParticle(D2SeedStrc* pSeed);

void __stdcall sub_004732C0_StepParticles(D2SeedStrc* pSeed);                                              // 0x004732C0

int __cdecl D2GFX_GetDisplayType();                                                                                 // 0x004F5140
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __fastcall DATAARRAYS_AllocateHandle(D2WeatherStrc* pArray);                                             // 0x006BCB40
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __cdecl sub_0044DB00(); // 0x0044DB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall sub_00472C80_StepSplashes(int nUnused);                                                     // 0x00472C80
void __fastcall sub_00472D10_StepBubbles(int nUnused);                                                      // 0x00472D10
void __stdcall GFX_StepWeatherPhase(D2SeedStrc* pSeed);                                                   // 0x00473E50

void __fastcall sub_00472C80_StepSplashes(int nUnused);

void __fastcall sub_00472D10_StepBubbles(int nUnused);

void __stdcall sub_004732C0_StepParticles(D2SeedStrc* pSeed);

static void sub_004737B0_StepWind(D2SeedStrc* pSeed);

void __stdcall GFX_StepWeatherPhase(D2SeedStrc* pSeed);

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
void __fastcall sub_00473D00_SetPhase(int nPhase);                                                          // 0x00473D00
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0

static void __stdcall sub_00472590_SetSplash(int bForce, int bValue); // 0x00472590

void __cdecl sub_00473DC0_ToggleWeather(); // 0x00473DC0

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);          // 0x006CC468
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType); // 0x00478950
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0
void __cdecl sub_00472610_InitWindAngle();                                                                  // 0x00472610

extern "C" const char gszDataGlobalPath[];                                                                  // 0x006D4118

void __fastcall sub_00472890_InitWeather(int nLevelId); // 0x00472890

struct D2CelFileStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);          // 0x006CC468
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType); // 0x00478950
unsigned char __stdcall PALETTE_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                             // 0x006427F0
int __stdcall sub_004726F0(int nArg);                                                                       // 0x004726F0
void __cdecl sub_00472610_InitWindAngle();                                                                  // 0x00472610

extern "C" const char gszDataGlobalPath[];                                                                  // 0x006D4118
int gbWeatherResetDone;                                                                            // 0x007A8A30
int gaWeatherPhaseOffset[1];                                                                              // 0x007A8970
int gaWeatherPhaseRange[1];                                                                               // 0x007A8958
unsigned char gabOutdoorLightColors[12];                                                                  // 0x007A89EC
D2WeatherLayerStateStrc gtSplashCels;                                                            // 0x007A89B0
D2WeatherLayerStateStrc gtBubbleCels;                                                            // 0x007A893C
int gaSplashFrames[4];                                                                             // 0x007A89C8
int gaBubbleFrames[4];                                                                             // 0x007A892C
float gfPhaseLevel;                                                                                // 0x007A89A0

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

int __stdcall SCALE_CheckPerspectivePosition(int nXPos, int nYPos); // 0x004F66E0

void __stdcall SCALE_AdjustPerspectivePosition(int nXPos, int nYPos, int nBias, int* pXAdjust, int* pYAdjust); // 0x004F6760

typedef int (__stdcall* D2CelDrawRetFn)(D2CelContextStrc*, int, int, unsigned int, int, unsigned char*);

static inline unsigned int sub_00472400_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00472210
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollRandomNumberInline_00472210(pSeed) & (nMax - 1);
}

// 0x00472240
int __fastcall sub_00472240_RollMaskOffset(D2SeedStrc* pSeed, int nOffset, int nRange)
{
    return (SEED_RollRandomNumberInline(pSeed) & (nRange - 1)) + nOffset;
}

// 0x00472280
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange)
{
    return nOffset + RNG_RollLimitedRef(pSeed, nRange);
}

// 0x004722F0
float __stdcall sub_004722F0_AbsFloatStd(float fValue)
{
    return (float)fabs(fValue);
}

// 0x00472310
float __cdecl sub_00472310_AbsFloat(float fValue)
{
    return (float)fabs(fValue);
}

// 0x00472320
void __cdecl sub_00472320()
{
    gpWeatherParticles = DATAARRAYS_Create("Environment Particles", 0x100, 0x28);
    DATAARRAYS_Initialize(gpWeatherParticles);
// build: symbol ?gnPhaseLevel@* 0x007A89E0
    gnPhaseLevel = 0;
    gpWeatherSplashes = DATAARRAYS_Create("Environment Splashes", 0x200, 0x18);
    DATAARRAYS_Initialize(gpWeatherSplashes);
    gpWeatherBubbles = DATAARRAYS_Create("Environment Bubbles", 0x80, 0x18);
    DATAARRAYS_Initialize(gpWeatherBubbles);
    gnBaseWindAngleMin = 0x2A;
// build: symbol ?gnWindAngleMin@* 0x007A89D8
    gnWindAngleMin = 0x2A;
    gbLightningFlash = 0;
    gbLightningEnabled = 0;
    gnGlobal_007A8A0C = 0;
    gnBaseWindAngleMax = 0xAA;
// build: symbol ?gnWindAngleMax@* 0x007A8998
    gnWindAngleMax = 0xAA;
}

// 0x004723C0
void __cdecl sub_004723C0()
{
    DATAARRAYS_Destroy(gpWeatherParticles);
    DATAARRAYS_Destroy(gpWeatherSplashes);
    DATAARRAYS_Destroy(gpWeatherBubbles);
}

// 0x004723F0
int __cdecl sub_004723F0_GetPhase()
{
    return gnPhase;
}

// 0x00472400
void __cdecl sub_00472400_ResetPhaseState()
{
    int nLevelId = DUNGEON_GetLevelIdFromRoom(CUNIT_GetPlayerRoom());
    D2SeedStrc* pSeed = &sub_00463DE0_GetPlayerUnit()->pSeed;

    switch (nLevelId)
    {
    case LEVEL_HARROGATH:
    case LEVEL_BLOODYFOOTHILLS:
    case LEVEL_ID_ACT5_BARRICADE_1:
    case LEVEL_ARREATPLATEAU:
        gnBaseWindAngleMin = 42;
// build: symbol ?gnWindAngleMin@* 0x007A89D8
        gnWindAngleMin = 42;
        gnBaseWindAngleMax = 170;
// build: symbol ?gnWindAngleMax@* 0x007A8998
        gnWindAngleMax = 170;
// build: symbol ?gnPhaseLevel@* 0x007A89E0
        gnPhaseLevel = gnPhaseMax = sub_00472280(pSeed, 0x20, 0x38);
        return;

    case LEVEL_TUNDRAWASTELANDS:
        gnWindAngleMin = 170;
        gnWindAngleMax = 56;
        gnBaseWindAngleMin = 28;
        gnBaseWindAngleMax = 56;
        gnPhaseLevel = gnPhaseMax = sub_00472280(pSeed, 0x20, 0x70);
        return;

    case LEVEL_ROCKYSUMMIT:
    case LEVEL_NIHLATHAKSTEMPLE:
        gnWindAngleMin = 28;
        gnWindAngleMax = 28;
        gnBaseWindAngleMin = 28;
        gnBaseWindAngleMax = 28;
// build: symbol ?gnTargetAngle@* 0x007A89F8
        gnTargetAngle = 28;
// build: symbol ?gnWeatherAngle@* 0x007A89C4
        gnWeatherAngle = 28;
        gnPhaseMax = 0x100;
        gnPhaseLevel = 0x100;
        return;
    }

    gnPhaseLevel = gnPhaseMax;
    if (!gbWeatherSplash)
    {
        sub_00472400_SeedStep(pSeed);
        gbLightningEnabled = 0;
    }
    else
    {
        gbLightningEnabled = 0;
    }
}

// 0x00472550
void __cdecl sub_00472550_ResetWeather()
{
// build: symbol ?DATAARRAYS_Reset@* 0x006BCAC0
    DATAARRAYS_Reset(gpWeatherParticles);
    D2_ASSERT(!gpWeatherParticles->nCount, 0x15B);
}

// 0x00472590
static void __stdcall sub_00472590_SetSplash(int bForce, int bValue)
{
    if (gbLightningEnabled && bValue)
        gbLightningEnabled = 0;
    if (gbPhaseActive && !bValue)
        gbPhaseActive = bValue;
    if (bValue != gbWeatherSplash || bForce)
    {
        DATAARRAYS_Reset(gpWeatherParticles);
        D2_ASSERT(!gpWeatherParticles->nCount, 0x15B);
    }
    gbWeatherSplash = bValue;
}

// 0x00472610
void __cdecl sub_00472610_InitWindAngle()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2SeedStrc tSeed;
// build: symbol ?gnWindCountdown@* 0x007A89E4
        gnWindCountdown = SEED_RollFromInline(&pPlayer->pSeed, &tSeed) % 375 + 125;
        gnLightningCountdown = SEED_RollLowInline(&tSeed) % 1500 + 500;
        const unsigned int nRoll = SEED_RollLowInline(&tSeed);
        pPlayer->pSeed.nHighSeed = tSeed.nHighSeed;
        pPlayer->pSeed.nLowSeed = tSeed.nLowSeed;
        const int nAngle = nRoll % 71 + 92;
// build: symbol ?gnWeatherAngle@* 0x007A89C4
        gnWeatherAngle = nAngle;
// build: symbol ?gnTargetAngle@* 0x007A89F8
        gnTargetAngle = nAngle;
    }
    else
    {
        gnWindCountdown = 0x138;
        gnLightningCountdown = 0x4E2;
        gnWeatherAngle = 0x7F;
        gnTargetAngle = 0x7F;
    }
}

// 0x004726F0
static int __stdcall sub_004726F0(int bForce)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (!pRoom)
        return 0;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        sub_00472590_SetSplash(0, 0);
        sub_00472610();
        return 0;
    }

    sub_00472610();
    int bFlag = 0;
    int nChance = 0;
    switch (nLevelId)
    {
    case LEVEL_HARROGATH:
    case LEVEL_BLOODYFOOTHILLS:
    case LEVEL_ID_ACT5_BARRICADE_1:
    case LEVEL_ARREATPLATEAU:
        gbSnowWeather = 0;
        nChance = 0x19;
        break;
    case LEVEL_ROCKYSUMMIT:
    case LEVEL_NIHLATHAKSTEMPLE:
        bFlag = 1;
        gbSnowWeather = 1;
        nChance = 0;
        break;
    case LEVEL_TUNDRAWASTELANDS:
        gbSnowWeather = 1;
        nChance = 0;
        break;
    }

    const int nRoll = (unsigned int)CLIENT_RollRandomNumberForceInline(&pPlayer->pSeed) % 100;
    if (nRoll < nChance && !bForce)
    {
        sub_00472590_SetSplash(0, 0);
        return 0;
    }

    gbPhaseActive = bFlag;
    if (bFlag)
        sub_00473D00_SetPhase(2);
    sub_00472590_SetSplash(bForce, 1);
    return 0;
}

// 0x00472890
void __fastcall sub_00472890_InitWeather(int nLevelId)
{
    sub_004726F0(1);
    if (!gbWeatherResetDone)
    {
        sub_00472610_InitWindAngle();
        gbWeatherResetDone = 1;
    }

    gaWeatherPhaseOffset[0] = 7500;
    gaWeatherPhaseOffset[1] = 250;
    gaWeatherPhaseOffset[2] = 3000;
    gaWeatherPhaseOffset[3] = 125;
    if (DRLG_GetActNoFromLevelId(nLevelId) == 2)
        gaWeatherPhaseOffset[2] *= 3;
    if (DRLG_GetActNoFromLevelId(nLevelId) == 4)
        gaWeatherPhaseOffset[2] *= 3;

    gaWeatherPhaseRange[0] = 7500;
    gaWeatherPhaseRange[1] = 250;
    gaWeatherPhaseRange[2] = 3000;
    gaWeatherPhaseRange[3] = 50;

    unsigned char nColor;
    int i = 0;
    int n80 = 0;
    int n24 = 0;
    for (; i < 12; ++i)
    {
        const int nStep = n80 / 12;
        nColor = 0x62 - nStep;
        gabParticleColorsDay[i] = PALETTE_FindPaletteIndex(nColor, nColor + 0x19, nColor);
        nColor = 0x2D - i * 40 / 12;
        gabParticleColorsTwilight[i] = PALETTE_FindPaletteIndex(nColor, nColor + 10, nColor);
        nColor = 0x19 - n24 / 12;
        gabParticleColorsNight[i] = PALETTE_FindPaletteIndex(nColor, nColor + 5, nColor);
        nColor = nStep + 0x78;
        gabPeriodLightColors[i] = PALETTE_FindPaletteIndex(nColor, nColor, nColor);
        nColor = nStep + 0xAA;
        gabOutdoorLightColors[i] = PALETTE_FindPaletteIndex(nColor, nColor, nColor);
        n24 += 24;
        n80 += 80;
    }

    char szPath[0x104];
    unsigned int nFileSize;
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain1", gszDataGlobalPath);
    gtSplashCels.apCelFiles[0] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain2", gszDataGlobalPath);
    gtSplashCels.apCelFiles[1] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain3", gszDataGlobalPath);
    gtSplashCels.apCelFiles[2] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\Rain4", gszDataGlobalPath);
    gtSplashCels.apCelFiles[3] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    for (int i = 0; i < 4; ++i)
        gaSplashFrames[i] = CelFileGetCelsPerDirection(gtSplashCels.apCelFiles[i]);

    wsprintfA(szPath, "%s\\UncompOverlays\\bubble1", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[0] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble2", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[1] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble3", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[2] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\bubble4", gszDataGlobalPath);
    gtBubbleCels.apCelFiles[3] = ARCHIVE_LoadCellFileWithFileSize(szPath, &nFileSize, 0);
    for (int i = 0; i < 4; ++i)
        gaBubbleFrames[i] = CelFileGetCelsPerDirection(gtBubbleCels.apCelFiles[i]);

    gfPhaseLevel = 0.0f;
}

// 0x00472BD0
void __cdecl sub_00472BD0()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gtSplashCels.apCelFiles[i])
        {
            ARCHIVE_FreeClientCellFile(gtSplashCels.apCelFiles[i]);
            gtSplashCels.apCelFiles[i] = 0;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (gtBubbleCels.apCelFiles[i])
        {
            ARCHIVE_FreeClientCellFile(gtBubbleCels.apCelFiles[i]);
            gtBubbleCels.apCelFiles[i] = 0;
        }
    }
}

// 0x00472C20
void __fastcall sub_00472C20_PlayerMoved(int nArg)
{
// build: symbol ?DATAARRAYS_Reset@* 0x006BCAC0
    DATAARRAYS_Reset(gpWeatherSplashes);
    DATAARRAYS_Reset(gpWeatherBubbles);
    if (nArg)
        sub_004726F0(nArg);
}

// 0x00472C50
void __fastcall sub_00472C50(int nArg)
{
    if (!gbLightningEnabled)
    {
        gbLightningEnabled = 1;
        gnLightningFlashFrames = 1;
        gbLightningFlash = 0;
// build: symbol ?gbPlayThunderSound@* 0x00712B4C
        gbPlayThunderSound = nArg;
    }
}

// 0x00472C80
void __fastcall sub_00472C80_StepSplashes(int nUnused)
{
    const int bPerspective = sub_004F51D0_IsPerspective();
    D2WeatherSplashStrc* pSplash = gpWeatherSplashes->pRecords;
    for (int i = 0; i <= gpWeatherSplashes->nLastParticle; i += 1, ++pSplash)
    {
        if (!pSplash->bActive)
            continue;

        if (!bPerspective)
        {
            pSplash->nX -= gnViewDeltaX;
            pSplash->nY -= gnViewDeltaY;
        }

        pSplash->nFrameDelay -= 1;
        if (pSplash->nFrameDelay <= 0)
        {
            pSplash->nFrame += 1;
            pSplash->nFrameDelay = 2;
            if (pSplash->nFrame >= gaSplashFrames[pSplash->nType])
                sub_006BCCD0_FreeDataArraySlot(gpWeatherSplashes, i << 16);
        }
    }
}

// 0x00472D10
void __fastcall sub_00472D10_StepBubbles(int nUnused)
{
    const int bPerspective = sub_004F51D0_IsPerspective();
    D2WeatherSplashStrc* pSplash = gpWeatherBubbles->pRecords;
    for (int i = 0; i <= gpWeatherBubbles->nLastParticle; i += 1, ++pSplash)
    {
        if (!pSplash->bActive)
            continue;

        if (!bPerspective)
        {
            pSplash->nX -= gnViewDeltaX;
            pSplash->nY -= gnViewDeltaY;
        }

        pSplash->nFrameDelay -= 1;
        if (pSplash->nFrameDelay <= 0)
        {
            pSplash->nFrame += 1;
            pSplash->nFrameDelay = 2;
            if (pSplash->nFrame >= gaBubbleFrames[pSplash->nType])
                sub_006BCCD0_FreeDataArraySlot(gpWeatherBubbles, i << 16);
        }
    }
}

// 0x00472DA0
void __fastcall sub_00472DA0_CreateSplash(int nX, int nY, int nFixX, int nFixY)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x2D2);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    const int nRecord = DATAARRAYS_AllocateHandle(gpWeatherSplashes);
    if (nRecord == -1)
        return;

    D2WeatherSplashStrc* pSplash = &gpWeatherSplashes->pRecords[(short)(nRecord >> 16)];
    if (D2GFX_CheckPerspective())
    {
        pSplash->nX = (sub_00472280(pSeed, 0, 5) << 16) + nFixX;
        pSplash->nY = (sub_00472280(pSeed, 0, 5) << 16) + nFixY;
    }
    else
    {
        const int nRoll = sub_00472280(pSeed, 0, 0x50);
        int nDist = nRoll - 0x28;
        if (nDist < 0)
            nDist = -nDist;
        const int nSpread = 0x50 - (nDist << 1);
        pSplash->nX = sub_00472280(pSeed, -nSpread, 2 * nSpread) + nX;
        pSplash->nY = nRoll + nY;
    }

    unsigned int nLow;
    M341_ROLL_SEED_LOW(pSeed, nLow);
    pSplash->nType = (nLow & 1) + 2;
    D2_ASSERT(pSplash->nType >= 0 && pSplash->nType < 4, 0x2EA);
    pSplash->nFrame = 0;
    pSplash->nFrameDelay = 2;
}

// 0x00472EC0
void __fastcall sub_00472EC0_CreateBubble(int nX, int nY, int nFixX, int nFixY)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x2FC);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    const int nRecord = DATAARRAYS_AllocateHandle(gpWeatherBubbles);
    if (nRecord == -1)
        return;

    D2WeatherSplashStrc* pBubble = &gpWeatherBubbles->pRecords[(short)(nRecord >> 16)];
    int nNewY;
    if (D2GFX_CheckPerspective())
    {
        pBubble->nX = ((sub_00472280(pSeed, 0, 5) - 2) << 16) + nFixX;
        nNewY = ((sub_00472280(pSeed, 0, 5) - 2) << 16) + nFixY;
    }
    else
    {
        const int nRoll = sub_00472280(pSeed, 0, 0x50);
        int nDist = nRoll - 0x28;
        if (nDist < 0)
            nDist = -nDist;
        const int nSpread = 0x50 - (nDist << 1);
        pBubble->nX = sub_00472280(pSeed, -nSpread, 2 * nSpread) + nX;
        nNewY = nRoll + nY - 0x1E;
    }
    pBubble->nY = nNewY;

    pBubble->nType = 2;
    pBubble->nFrame = 0;
    pBubble->nFrameDelay = 2;
}

// 0x00472FB0
static void __stdcall sub_00472FB0_GetPeriodLight(unsigned char* pOut2, int nValue, unsigned char* pOut1)
{
    int n = D2GFX_GetDisplayType();
    int bFlag;
    if (n > 0 && (n <= 3 || n == 6))
    {
        bFlag = 0;
    }
    else
    {
        bFlag = 1;
    }

    DUNGEON_GetLevelIdFromRoom(CUNIT_GetPlayerRoom());
    int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0);
    D2_ASSERT(nPeriod >= 0 && nPeriod <= 3, 0x356);

    if (pOut1)
    {
        *pOut1 = gaPeriodLights[nPeriod].nLight;
    }

    if (pOut2)
    {
        int nIndex = nValue * 12 / 8;
        if (bFlag)
        {
            *pOut2 = gabOutdoorLightColors[nIndex];
            return;
        }

        switch (nPeriod)
        {
        case 1:
        case 3:
            nIndex /= 2;
            break;
        case 2:
            nIndex /= 4;
            break;
        }
        *pOut2 = gabPeriodLightColors[nIndex];
    }
}

// 0x00473090
static void sub_00473090_InitParticle(D2SeedStrc* pSeed)
{
    const int nRecord = DATAARRAYS_AllocateHandle(gpWeatherParticles);
    if (nRecord == -1)
    {
        return;
    }

    D2WeatherParticleStrc* pParticle = &gpWeatherParticles->pParticles[(short)(nRecord >> 0x10)];
    pParticle->bDrop = 0;
    pParticle->nX = sub_00472280(pSeed, 0, gnScreenWidth);
    pParticle->nYEnd = sub_00472280(pSeed, 0x28, gnScreenHeight - 0x57);
    pParticle->nY = sub_00472280(pSeed, -0x14, pParticle->nYEnd + 0x14);
    pParticle->nFrame = (unsigned int)sub_U01_RollSeedInline(pSeed) & 0x1FF;

    const float fRatio = (float)(pParticle->nYEnd - 0x28) / (gnScreenHeight - 0x57);
    if (gbWeatherSplash)
    {
        pParticle->nAlpha = 0xFF;
        unsigned char* pAlpha = &pParticle->nAlpha;
        sub_U01_RollSeedInline(pSeed);
        pParticle->nType = 1;
        pParticle->nParam2 = 8 - (int)(fRatio * -28.0);
        pParticle->nParam = 7 * (pParticle->nYEnd - 0x28) / (gnScreenHeight - 0x57);
        if (gbSnowWeather)
        {
            ++pParticle->nParam;
        }

        D2_ASSERT(pParticle->nParam < 8 && pParticle->nParam >= 0, 0x390);
        sub_00472FB0_GetPeriodLight(&pParticle->nColor, pParticle->nParam, pAlpha);
        return;
    }

    const unsigned int nColor = (unsigned int)sub_U01_RollSeedInline(pSeed) % 12;
    switch (ENVIRONMENT_GetPeriodOfDayFromAct(gpDrlgAct_007A0634, 0))
    {
    case 2:
        pParticle->nColor = gabParticleColorsNight[nColor];
        pParticle->nAlpha = 0xFF;
        break;

    case 1:
    case 3:
        pParticle->nColor = gabParticleColorsTwilight[nColor];
        pParticle->nAlpha = 0xFF;
        break;

    case 0:
        pParticle->nColor = gabParticleColorsDay[nColor];
        pParticle->nAlpha = 0x7F;
        break;
    }

    pParticle->nParam = 4 - (int)(fRatio * -8.0);
    pParticle->nParam2 = 0xF - (int)(fRatio * -15.0);
    pParticle->nType = 3;
}

// 0x004732C0
void __stdcall sub_004732C0_StepParticles(D2SeedStrc* pSeed)
{
    float fScale;
    if (gbWeatherSplash)
    {
// build: symbol ?gnWeatherAngle@* 0x007A89C4
// build: symbol ?FOG_10083_Cos_LUT@* 0x0040B330
        const double dAbs = sub_00472310_AbsFloat(FOG_10083_Cos_LUT(gnWeatherAngle));
        fScale = (float)dAbs;
        fScale = fScale < 0.25f ? 0.25f : fScale;
    }
    else
    {
// build: symbol ?gfPhaseLevel@* 0x007A89A0
        fScale = (float)(gfPhaseLevel * (double)0.15f + (double)0.85f);
    }

    D2WeatherParticleStrc* pParticle = gpWeatherParticles->pParticles;
    for (int i = 0; i <= gpWeatherParticles->nLastParticle; ++i, ++pParticle)
    {
        if (!pParticle->bActive)
        {
            continue;
        }

        const int nSpeed = (int)(pParticle->nParam2 * fScale);
        const float fSpeed = (float)nSpeed;
        int nDeltaX = (int)(FOG_10083_Cos_LUT(gnWeatherAngle) * fSpeed);
// build: symbol ?FOG_10084_Sin_LUT@* 0x0040B350
        const int nDeltaY = (int)(FOG_10084_Sin_LUT(gnWeatherAngle) * fSpeed);
        pParticle->nY += nDeltaY - gnViewDeltaY;
        if (pParticle->nY > pParticle->nYEnd)
        {
            pParticle->bDrop = 1;
        }

        if (pParticle->bDrop)
        {
            if (!pParticle->nType)
            {
                sub_006BCCD0_FreeDataArraySlot(gpWeatherParticles, i << 16);
// build: symbol ?gnPhaseLevel@* 0x007A89E0
                if (gpWeatherParticles->nCount < gnPhaseLevel)
                {
                    sub_00473090_InitParticle(pSeed);
                }
            }
            else
            {
                pParticle->nParam2 = 0;
                nDeltaX = 0;
                --pParticle->nType;
            }
        }

        if (!pParticle->bActive)
        {
            continue;
        }

        if (gbWeatherSplash && !pParticle->bDrop)
        {
            nDeltaX += (int)(2 * FOG_10084_Sin_LUT((pParticle->nFrame + (gnWeatherTick << 9) / 25) & 0x1FF));
        }

        pParticle->nX += nDeltaX - gnViewDeltaX;
        if (pParticle->nX >= gnScreenWidth)
        {
            pParticle->nX -= gnScreenWidth;
        }

        if (pParticle->nX < 0)
        {
            pParticle->nX += gnScreenWidth;
        }
    }

    ++gnWeatherTick;
}

// 0x00473470
void __cdecl sub_00473470()
{
    if (D2GFX_CheckLowQuality())
        return;

    int nLeft = 0;
    int nRight = gnScreenWidth;
    int nBottom = gnScreenHeight - 47;
    switch (sub_0045AE90())
    {
    case 1:
        nRight -= gnScreenWidth / 4 * 2;
        break;
    case 2:
        nLeft = gnScreenWidth / 4 * 2;
        break;
    }

    D2WeatherParticleStrc* pParticle = gpWeatherParticles->pParticles;
    for (int i = 0; i <= gpWeatherParticles->nLastParticle; ++i, ++pParticle)
    {
        if (!pParticle->bActive)
            continue;

        if (gbWeatherSplash)
        {
            if (pParticle->nX >= nLeft && pParticle->nX < nRight && pParticle->nY >= 0 && pParticle->nY < nBottom && pParticle->nParam < 8 && pParticle->nParam >= 0)
            {
                const D2WeatherLineStrc* pLine = &gaWeatherLines[pParticle->nParam];
                D2GFX_DrawLine(pParticle->nX + pLine->nX1, pParticle->nY + pLine->nY1, pParticle->nX + pLine->nX2, pParticle->nY + pLine->nY2, pParticle->nColor, pParticle->nAlpha);
                pLine = &gaWeatherLines[pParticle->nParam + 1];
                D2GFX_DrawLine(pParticle->nX + pLine->nX1, pParticle->nY + pLine->nY1, pParticle->nX + pLine->nX2, pParticle->nY + pLine->nY2, pParticle->nColor, pParticle->nAlpha);
            }
        }
        else if (pParticle->bDrop)
        {
            if (pParticle->nX >= nLeft && pParticle->nX < nRight && pParticle->nY >= 0 && pParticle->nY < nBottom)
                D2GFX_DrawLine(pParticle->nX, pParticle->nY, pParticle->nX, pParticle->nY, pParticle->nColor, pParticle->nAlpha);
        }
        else
        {
// build: symbol ?gnWeatherAngle@* 0x007A89C4
// build: symbol ?FOG_10083_Cos_LUT@* 0x0040B330
            int nDX = (int)(FOG_10083_Cos_LUT(gnWeatherAngle) * pParticle->nParam);
// build: symbol ?FOG_10084_Sin_LUT@* 0x0040B350
            int nDY = (int)(FOG_10084_Sin_LUT(gnWeatherAngle) * pParticle->nParam);
            const int nY0 = pParticle->nY;
            const int nRange = pParticle->nYEnd - nY0;
            if (nDY > nRange)
            {
                nDX = nRange * nDX / nDY;
                nDY = nRange;
            }
            const int nX1 = pParticle->nX + nDX;
            const int nY1 = nY0 + nDY;
            if ((pParticle->nX >= nLeft && pParticle->nX < nRight && nY0 >= 0 && nY0 < nBottom)
                || (nX1 >= nLeft && nX1 < nRight && nY1 >= 0 && nY1 < nBottom))
                D2GFX_DrawLine(pParticle->nX, nY0, nX1, nY1, pParticle->nColor, pParticle->nAlpha);
        }
    }
}

// 0x004736C0
extern "C" void __cdecl sub_004736C0_DrawPanelShade()
{
    int left = 0;
    int bottom = gnScreenHeight - 47;
    int right = gnScreenWidth;
    switch (sub_0045AE90())
    {
    case 1:
        right -= (gnScreenWidth / 4) * 2;
        break;
    case 2:
        left = (gnScreenWidth / 4) * 2;
        break;
    }
    D2GFX_DrawBox(left, 0, right, bottom, 255, 5);
}

// 0x00473720
static inline void sub_00473720_GetLevelWeather(int* pRain, int* pMud)
{
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    *pRain = 0;
    *pMud = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        *pRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        *pMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }
}

// 0x00473770
int __cdecl sub_00473770_IsMudLevel()
{
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    int bMud = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        DATATBLS_GetRainFromLevelsTxt(nLevelId);
        bMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }
    return bMud;
}

// 0x004737B0
static void sub_004737B0_StepWind(D2SeedStrc* pSeed)
{
// build: symbol ?gnPhaseLevel@* 0x007A89E0
    while (gpWeatherParticles->nCount < gnPhaseLevel)
    {
        sub_00473090_InitParticle(pSeed);
    }

// build: symbol ?gnTargetAngle@* 0x007A89F8
    const int nTarget = gnTargetAngle;
// build: symbol ?gnWeatherAngle@* 0x007A89C4
    int nAngle = gnWeatherAngle;
    const int bSplash = gbWeatherSplash;
    const int nStep = bSplash ? 1 : 2;
    if (nTarget < nAngle)
    {
        nAngle -= nStep;
        if (nTarget > nAngle)
            gnWeatherAngle = nTarget;
        else
            gnWeatherAngle = nAngle;
    }
    else if (nTarget > nAngle)
    {
        const int nNew = nAngle + nStep;
        gnWeatherAngle = nTarget;
        if (nTarget >= nNew)
            gnWeatherAngle = nNew;
    }

// build: symbol ?gnWindCountdown@* 0x007A89E4
    if (!--gnWindCountdown)
    {
        if (bSplash)
        {
            gnWindCountdown = (unsigned int)sub_U01_RollSeedInline(pSeed) % 875 + 250;
// build: symbol ?gnWindAngleMax@* 0x007A8998
// build: symbol ?gnWindAngleMin@* 0x007A89D8
            gnTargetAngle = sub_00472280(pSeed, gnWindAngleMin, gnWindAngleMax);
        }
        else
        {
            unsigned __int64 lSeed1 = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
            gnWindCountdown = (unsigned int)lSeed1 % 375 + 125;
            unsigned __int64 lSeed2 = (lSeed1 >> 32) + 0x6AC690C5i64 * (unsigned int)lSeed1;
            pSeed->nHighSeed = (unsigned int)(lSeed2 >> 32);
            pSeed->nLowSeed = (unsigned int)lSeed2;
            gnTargetAngle = (unsigned int)lSeed2 % 71 + 92;
        }
    }

    if (gbLightningEnabled && !--gnLightningCountdown)
    {
        gnLightningFlashFrames = 1;
    }
}

// 0x00473910
void __cdecl sub_00473910_UpdateWeather()
{
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    int bRain = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        DATATBLS_GetMudFromLevelsTxt(nLevelId);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x573);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    if (gbLightningEnabled && gnLightningFlashFrames)
    {
        gnLightningFlashFrames -= 1;
        if (!gnLightningFlashFrames)
        {
            if (!gbLightningFlash)
            {
                gnLightningCountdown = 3;
                gbLightningFlash = 1;
            }
            else
            {
                gnLightningCountdown = sub_00472280(pSeed, 500, 1500);
                gbLightningFlash = 0;
// build: symbol ?gbPlayThunderSound@* 0x00712B4C
                if (gbPlayThunderSound)
                {
                    const int nDelay = sub_00472280(pSeed, 25, 50);
                    const int hSound = sub_004B9A00(0xCA, 0, nDelay, 0, 0);
                    if (hSound)
                    {
                        SOUNDINST_MoveSound(hSound, sub_00472280(pSeed, -200, 400), sub_00472280(pSeed, -200, 400), 0);
                    }
                }
                else
                {
                    gbPlayThunderSound = 1;
                }
            }
        }

        if (gdwGlobal_007BB390 >= 10)
        {
            sub_004736C0_DrawPanelShade();
            return;
        }
    }

    if (bRain && gpWeatherParticles->nCount)
    {
        sub_00473470();
    }
}

// 0x00473A70
void __fastcall sub_00473A70(D2WeatherStrc* pWeather, D2WeatherLayerStateStrc* pState)
{
    const int bPerspective = D2GFX_CheckPerspective();
    int nOffset = 0;
    int nLeft = 0;
    int nRight = gnScreenWidth;
    int nBottom = gnScreenHeight - 47;
    switch (sub_0045AE90())
    {
    case 1:
    {
        const int nQuarter = gnScreenWidth / 4;
        nOffset = -nQuarter;
        nRight -= nQuarter * 2;
        break;
    }
    case 2:
        nOffset = gnScreenWidth / 4;
        nLeft = gnScreenWidth / 4 * 2;
        break;
    }

    D2CelContextStrc tGfxData = {};
    D2WeatherSplashStrc* pRecord = pWeather->pRecords;
    for (int i = 0; i <= pWeather->nLastParticle; ++i, ++pRecord)
    {
        if (!pRecord->bActive)
        {
            continue;
        }

        if (bPerspective)
        {
            if (SCALE_CheckPerspectivePosition(pRecord->nX, pRecord->nY))
            {
                int nX;
                int nY;
                SCALE_AdjustPerspectivePosition(pRecord->nX, pRecord->nY, 0, &nX, &nY);
                nX += nOffset;
                if (nX >= nLeft && nX < nRight && nY >= 0 && nY < nBottom)
                {
                    tGfxData.pCellFile = pState->apCelFiles[pRecord->nType];
                    tGfxData.nFrame = pRecord->nFrame;
                    if (((D2CelDrawRetFn)&TEXTURE_CelDraw)(&tGfxData, nX, nY, -1, 3, 0))
                    {
                        continue;
                    }
                }
            }
            sub_006BCCD0_FreeDataArraySlot(pWeather, i << 16);
        }
        else
        {
            const int nX = pRecord->nX + nOffset;
            const int nY = pRecord->nY;
            if (nX >= nLeft && nX < nRight && nY >= 0 && nY < nBottom)
            {
                tGfxData.pCellFile = pState->apCelFiles[pRecord->nType];
                tGfxData.nFrame = pRecord->nFrame;
                TEXTURE_CelDraw(&tGfxData, nX, nY, -1, 3, 0);
            }
        }
    }
}

// 0x00473C00
void __cdecl sub_00473C00_DrawWeatherLayers()
{
    if (gpWeatherSplashes->nCount)
    {
        sub_00473A70(gpWeatherSplashes, &gtSplashCels);
    }
    if (gpWeatherBubbles->nCount)
    {
        sub_00473A70(gpWeatherBubbles, &gtBubbleCels);
    }
}

// 0x00473C40
int __cdecl sub_00473C40_IsRainLevel()
{
    if (gbWeatherSplash)
    {
        return 0;
    }
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    int bRain = 0;
    if (pUnit)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        DATATBLS_GetMudFromLevelsTxt(nLevelId);
    }
    return bRain;
}

// 0x00473C80
float __cdecl sub_00473C80_GetPhaseLevel()
{
// build: symbol ?gfPhaseLevel@* 0x007A89A0
    return gfPhaseLevel;
}

// 0x00473C90
void __fastcall sub_00473C90_SetGlobal(int nValue)
{
    gnGlobal_007A8A10 = nValue;
}

// 0x00473CA0
void __cdecl sub_00473CA0_Empty()
{
}

// 0x00473CB0
void __cdecl sub_00473CB0_Nop()
{
}

// 0x00473CC0
void __cdecl sub_00473CC0_Nop()
{
}

// 0x00473CD0
void __cdecl sub_00473CD0_Nop()
{
}

// 0x00473CE0
void __cdecl sub_00473CE0_Nop()
{
}

// 0x00473CF0
void __cdecl sub_00473CF0_Nop()
{
}

// 0x00473D00
void __fastcall sub_00473D00_SetPhase(int nPhase)
{
    D2_ASSERT(nPhase >= 0 && nPhase <= 3, 0x12A);

    if (gbPhaseBusy && nPhase != 0)
    {
        return;
    }

    if (gbPhaseActive && nPhase != 2)
    {
        return;
    }

    gnPhase = nPhase;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x137);

    switch (nPhase)
    {
    case 0:
        gnPhaseLevel = 0;
        break;

    case 1:
        sub_004726F0(0);
        gnPhaseMax = sub_00472280(&pPlayer->pSeed, 0x20, 0xE0);
        break;

    case 2:
        sub_00472400_ResetPhaseState();
        break;

    case 3:
        gbLightningEnabled = 0;
        break;
    }
}

// 0x00473DC0
void __cdecl sub_00473DC0_ToggleWeather()
{
    gbPhaseBusy = !gbPhaseBusy;
    if (gbPhaseBusy)
    {
        gbPhaseActive = 0;
        gnPhase = 0;
        D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0x137);
        gnGlobal_007A89E0 = 0;
        DATAARRAYS_Reset(gpWeatherParticles);
        D2_ASSERT(!gpWeatherParticles->nCount, 0x15B);
    }
    else
    {
        sub_004726F0(1);
    }
}

// 0x00473E50
void __stdcall GFX_StepWeatherPhase(D2SeedStrc* pSeed)
{
    int nPhase = gnPhase;
    if (gbPhaseActive && nPhase != 2)
    {
        if (!gbPhaseBusy)
        {
            gnPhase = 2;
            D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 0x137);
            sub_00472400_ResetPhaseState();
        }
        return;
    }
    if (!gnPhaseLeft)
    {
        ++nPhase;
        if (nPhase == 4)
        {
            nPhase = 0;
        }
        gnPhaseTotal = sub_00472280(pSeed, gaWeatherPhaseOffset[nPhase], gaWeatherPhaseRange[nPhase]);
        gnPhaseLeft = gnPhaseTotal;
        sub_00473D00_SetPhase(nPhase);
    }
    --gnPhaseLeft;
    if (nPhase == 1)
    {
// build: symbol ?gnPhaseLevel@* 0x007A89E0
        gnPhaseLevel = (gnPhaseTotal - gnPhaseLeft) * gnPhaseMax / gnPhaseTotal;
    }
    else if (nPhase == 3)
    {
        gnPhaseLevel = gnPhaseMax * gnPhaseLeft / gnPhaseTotal;
    }
// build: symbol ?gfPhaseLevel@* 0x007A89A0
    gfPhaseLevel = gnPhaseLevel * (1.0 / 256.0);
}

// 0x00473F50
void __cdecl sub_00473F50_UpdateWeather()
{
    int nLevelId;
    int bRain;
    int bMud;
    D2UnitStrc* pStoredUnit = sub_00463DE0_GetPlayerUnit();
    bRain = 0;
    bMud = 0;
    if (pStoredUnit)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pStoredUnit));
        bRain = DATATBLS_GetRainFromLevelsTxt(nLevelId) != 0;
        bMud = DATATBLS_GetMudFromLevelsTxt(nLevelId) != 0;
    }

    if (!bRain && gbRainActive)
    {
        if (gpWeatherParticles->nCount)
        {
// build: symbol ?DATAARRAYS_Reset@* 0x006BCAC0
            DATAARRAYS_Reset(gpWeatherParticles);
        }

        if (gpWeatherSplashes->nCount)
        {
            DATAARRAYS_Reset(gpWeatherSplashes);
        }
    }

    if (!bMud && gbMudActive)
    {
        if (gpWeatherBubbles->nCount)
        {
            DATAARRAYS_Reset(gpWeatherBubbles);
        }
    }

    gbRainActive = bRain;
    gbMudActive = bMud;

    const unsigned int nTick = sub_0044DB00();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x547);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    if (nTick <= gnWeatherLastTick)
    {
        return;
    }

    gnWeatherLastTick = nTick;
    if (bRain)
    {
        if (gpWeatherParticles->nCount)
        {
            sub_004732C0_StepParticles(pSeed);
        }

        sub_00472C80_StepSplashes((int)pSeed);
        GFX_StepWeatherPhase(pSeed);
        sub_004737B0_StepWind(pSeed);
    }
    else
    {
        gfPhaseLevel = 0.0f;
    }

    if (bMud)
    {
        sub_00472D10_StepBubbles((int)pSeed);
    }
}

#include "gen/data/Source/D2Client/Unknown_00472210.inc"
