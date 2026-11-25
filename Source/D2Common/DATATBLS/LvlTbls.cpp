#include "D2Common.h"

#include "D2DataTbls.h"

#include "D2Path.h"

#include "D2Drlg.h"

#include "D2DrlgMaps.h"

#include "D2DrlgTiles.h"

#include "D2LevelTxt.h"

#include "D2Records.h"

#include "D2Skills.h"

#include "D2TxtTables.h"

#include "D2LevelIds.h"

#include "D2Unicode.h"

#pragma intrinsic(strcpy)

#define LVL_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

union D2SeedStrc;

struct D2SkillsTxt;

struct D2AutomapRecordStrc;

struct D2DrlgStrc;

struct D2LevelDefBin;

struct D2BinFieldStrc;

struct D2AutomapTxt;

struct D2AutomapIndexStrc;

struct D2DataTablesStrc;

struct D2LvlTypesTxt;

struct D2SkillStrc;

struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc;

struct D2LevelsTxt;

struct D2LvlPrestTxt;

struct D2LvlWarpTxt;

struct D2LvlMazeTxt;

struct D2LvlSubTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2LevelDefBin* gpLevelDefBin; // 0x0096C890

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

extern "C" const char gszTxtField_end_006D9060[]; // 0x006D9060

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" unsigned int __cdecl strlen(const char* sz);

extern void* gpLvlwarpTxt; // 0x0096CA00

extern void* gpLvlmazeTxt; // 0x0096CA08

struct D2LvlTypesTxt
{
    char szFile[32][60];
    unsigned char nAct;
    unsigned char pad0x781[3];
    unsigned int dwExpansion;
};

extern "C" int __cdecl strcmp(const char* s1, const char* s2);

extern const char gszAutomapLevelNames[36][16]; // 0x006E7D50

extern const char gszAutomapTileNames[20][8]; // 0x006E7F90

struct D2AutomapTxt
{
    char szLevelName[0x10];
    char szTileName[0x08];
    char nStyle;
    char nStartSequence;
    char nEndSequence;
    char pad0x1B;
    int nCel[4];
};

struct D2AutomapRecordStrc
{
    int nLevelNo;
    int nTileType;
    unsigned char nStyle;
    unsigned char nStartSequence;
    unsigned char nEndSequence;
    unsigned char pad0x0B;
    int nCel[4];
    int nCels;
};

struct D2AutomapIndexStrc
{
    int nStart;
    int nEnd;
};

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0

extern D2SeedStrc* gpAutomapSeed; // 0x00744504

D2AutomapRecordStrc* gpAutomapRecords; // 0x0096CA28

int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040

int gnLvlwarpTxtRecordCount; // 0x0096CA04

int gnLvlmazeTxtRecordCount; // 0x0096CA0C

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile); // 0x00668300

void __fastcall DRLGTILESUB_FreeDrlgFile(D2LvlSubTxt* pLvlSubTxtRecord); // 0x00670630

D2LvlPrestTxt* gpLvlPrestTxt; // 0x0096C894

int* gpPortalLevels; // 0x0096C9F4

int gnPortalLevels; // 0x0096C9F8

D2LvlTypesTxt* gpLvlTypesTxt; // 0x0096C9F0

D2LvlWarpTxt* gpLvlWarpTxt; // 0x0096CA00

D2LvlMazeTxt* gpLvlMazeTxt; // 0x0096CA08

D2LvlSubTxt* gpLvlSubTxt; // 0x0096CA10

int gnLvlSubTxtRecordCount; // 0x0096CA14

int* gpLvlSubTypeStartIds; // 0x0096CA18

void* gppTileLibraryHash; // 0x0096CA1C

D2DrlgFileStrc** gppLvlPrestDrlgFiles; // 0x0096CA20

D2DrlgFileStrc** gppLvlSubDrlgFiles; // 0x0096CA24

extern const char gszLvlTblsSourceFile[]; // 0x006E84DC

extern const char gszTilesDirectory[]; // 0x006E867C

extern const char gszPathFormat_006D4124[]; // 0x006D4124

extern const char gszLvlSubTableName[]; // 0x006E8928

void* __fastcall FOG_Alloc(int,const char*,int,int); // 0x0040B380

int __cdecl FOG_IsExpansion(); // 0x00408F20

void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc**,void*,const char*); // 0x00665F40

__declspec(noreturn) void __cdecl sub_00681E09_Exit(int);

extern const char gszField_Type[]; // 0x006E89A4

extern const char gszField_File[]; // 0x006E899C

extern const char gszField_CheckAll[]; // 0x006E8990

extern const char gszField_BordType[]; // 0x006E8984

extern const char gszField_GridSize[]; // 0x006E8978

extern const char gszField_Dt1Mask[]; // 0x006E879C

extern const char gszField_Prob0[]; // 0x006E8970

extern const char gszField_Trials0[]; // 0x006E8968

extern const char gszField_Max0[]; // 0x006E8960

extern const char gszField_Prob1[]; // 0x006E8958

extern const char gszField_Trials1[]; // 0x006E8950

extern const char gszField_Max1[]; // 0x006E8948

extern const char gszField_Prob2[]; // 0x006E8940

extern const char gszField_Trials2[]; // 0x006E8938

extern const char gszField_Max2[]; // 0x006E8930

extern const char gszField_Prob3[]; // 0x006E8920

extern const char gszField_Trials3[]; // 0x006E8918

extern const char gszField_Max3[]; // 0x006E8910

extern const char gszField_Prob4[]; // 0x006E8908

extern const char gszField_Trials4[]; // 0x006E8900

extern const char gszField_Max4[]; // 0x006E88F8

extern const char gszField_Expansion[]; // 0x006DCF44

extern const char gszField_end[]; // 0x006D9060

static int* gpPortalLevels_0096C9F4; // 0x0096C9F4

static int gnPortalLevels_0096C9F8; // 0x0096C9F8

static D2LvlTypesTxt* gpLvlTypesTxt_0096C9F0; // 0x0096C9F0

static int gnLvlTypesTxtRecordCount; // 0x0096C9FC

static D2TileLibraryHeaderStrc** gppTileLibraryHash_0096CA1C; // 0x0096CA1C

int gnAutomapRecordCount; // 0x0096CA2C

D2AutomapIndexStrc gaAutomapIndex[36]; // 0x0096C8D0

extern D2DataTablesStrc sgtDataTables; // 0x0096BC30

void __fastcall DATATBLS_LoadLevelTypesTxt(void* hArchive);

void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles);

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct Act;

struct D2DrlgActStrc;

struct Environment;

struct D2DrlgEnvironmentStrc;

struct D2EnvironmentCycleStrc;

struct Unicode;

struct Environment { char pad[0x28]; int timeFields[2]; };

Environment* __fastcall sub_0061AA60(Act*); // 0x0061AA60

enum { TIME_RATE_FIELD = 0 };

struct D2DrlgEnvironmentStrc
{
    int nCycleIndex;
    int nPeriodOfDay;
    int nTicks;
    int nIntensity;
    unsigned int dwInitTick;
    int unk0x14;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char unk0x1B;
    float fCos;
    float fLast;
    float fSin;
    int nTimeRate;
    int nTimeRateIndex;
    int bEclipse;
    int nPrev;
};

struct D2EnvironmentCycleStrc
{
    int nTicksBegin;
    int nPeriodOfDay;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char unk0x0B;
};

extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount(); // 0x006CC260

D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct); // 0x0061AA60

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

extern D2EnvironmentCycleStrc gNormalEnvironmentCycle[]; // 0x007443F0

extern D2EnvironmentCycleStrc gAct4EnvironmentCycle[]; // 0x00744438

extern D2EnvironmentCycleStrc gEclipseEnvironmentCycle[]; // 0x00744480

static void ENVIRONMENT_UpdateLightIntensity(D2DrlgEnvironmentStrc* pEnvironment, int nLevelId, int nAct); // 0x0061BB80

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_ASCII = 1,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_NAMETOWORD = 20,
};

const wchar_t* __fastcall D2LANG_GetStringByReferenceString(const char* szKey); // 0x00524E20

// 0x0061DB70
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return &sgptDataTables->pLevelsTxt[nLevelId];
    }

    return 0;
}

// 0x0061DBA0
unsigned char __stdcall DATATBLS_GetRainFromLevelsTxt(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return sgptDataTables->pLevelsTxt[nLevelId].nRain;
    }

    return 0;
}

// 0x0061DBE0
unsigned char __stdcall DATATBLS_GetNoPerFromLevelsTxt(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return sgptDataTables->pLevelsTxt[nLevelId].nNoPer;
    }

    return 0;
}

// 0x0061DC20
unsigned char __stdcall DATATBLS_GetMudFromLevelsTxt(int nLevelId)
{
    if (nLevelId > 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return sgptDataTables->pLevelsTxt[nLevelId].nMud;
    }

    return 0;
}

// 0x0061DC60
void __fastcall DATATBLS_UnloadLevelsTxt()
{
    if (sgptDataTables->pLevelsTxt)
    {
        DATATBLS_UnloadBin(sgptDataTables->pLevelsTxt);
    }
    sgptDataTables->nLevelsTxtRecordCount = 0;
}

// 0x0061DCA0
int __stdcall DATATBLS_GetMonsterLevelInArea(int nLevelId, unsigned char nDifficulty, int bExpansion)
{
    if (nDifficulty >= 3)
    {
        return 1;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (!pLevelsTxtRecord)
    {
        return 1;
    }

    if (bExpansion)
    {
        return pLevelsTxtRecord->wMonLvlEx[nDifficulty];
    }

    return (short)pLevelsTxtRecord->wMonLvl[nDifficulty];
}

// 0x0061DD00
static void DATATBLS_InitPortalLevels(D2LevelDefBin* pLevelDefBin)
{
    gnPortalLevels_0096C9F8 = 0;
    for (int i = 0; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
    {
        if (pLevelDefBin[i].dwPortal)
        {
            ++gnPortalLevels_0096C9F8;
        }
    }
    if (gnPortalLevels_0096C9F8)
    {
        gpPortalLevels_0096C9F4 = (int*)FOG_AllocPool(0, sizeof(int) * gnPortalLevels_0096C9F8, ".\\DATATBLS\\LvlTbls.cpp", 0x16C, 0);
        memset(gpPortalLevels_0096C9F4, 0, sizeof(int) * gnPortalLevels_0096C9F8);
    }
    int nPortalIndex = 0;
    for (int i = 0; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
    {
        if (pLevelDefBin[i].dwPortal)
        {
            D2_ASSERT(nPortalIndex < gnPortalLevels_0096C9F8, 0x177);
            gpPortalLevels_0096C9F4[nPortalIndex] = i;
            ++nPortalIndex;
        }
    }
}

// 0x0061DDF0
int* __fastcall DATATBLS_GetPortalLevels(int* pnPortalLevels)
{
    *pnPortalLevels = gnPortalLevels;
    return gpPortalLevels;
}

void __stdcall sub_M13_Emit_0061DD00(D2LevelDefBin* pLevelDefBin)
{
    gpLevelDefBin = pLevelDefBin;
    DATATBLS_InitPortalLevels(pLevelDefBin);
}

// 0x0061DE00
void __fastcall DATATBLS_LoadLevelDefsBin(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "QuestFlag", 2, 0, 0, 0 },
        { "QuestFlagEx", 2, 0, 4, 0 },
        { "Layer", 2, 0, 8, 0 },
        { "SizeX", 2, 0, 12, 0 },
        { "SizeY", 2, 0, 24, 0 },
        { "SizeX(N)", 2, 0, 16, 0 },
        { "SizeY(N)", 2, 0, 28, 0 },
        { "SizeX(H)", 2, 0, 20, 0 },
        { "SizeY(H)", 2, 0, 32, 0 },
        { "OffsetX", 2, 0, 36, 0 },
        { "OffsetY", 2, 0, 40, 0 },
        { "Depend", 2, 0, 44, 0 },
        { "DrlgType", 2, 0, 48, 0 },
        { "LevelType", 2, 0, 52, 0 },
        { "SubType", 2, 0, 56, 0 },
        { "SubTheme", 2, 0, 60, 0 },
        { "SubWaypoint", 2, 0, 64, 0 },
        { "SubShrine", 2, 0, 68, 0 },
        { "Vis0", 2, 0, 72, 0 },
        { "Vis1", 2, 0, 76, 0 },
        { "Vis2", 2, 0, 80, 0 },
        { "Vis3", 2, 0, 84, 0 },
        { "Vis4", 2, 0, 88, 0 },
        { "Vis5", 2, 0, 92, 0 },
        { "Vis6", 2, 0, 96, 0 },
        { "Vis7", 2, 0, 100, 0 },
        { "Warp0", 2, 0, 104, 0 },
        { "Warp1", 2, 0, 108, 0 },
        { "Warp2", 2, 0, 112, 0 },
        { "Warp3", 2, 0, 116, 0 },
        { "Warp4", 2, 0, 120, 0 },
        { "Warp5", 2, 0, 124, 0 },
        { "Warp6", 2, 0, 128, 0 },
        { "Warp7", 2, 0, 132, 0 },
        { "Intensity", 4, 0, 136, 0 },
        { "Red", 4, 0, 137, 0 },
        { "Green", 4, 0, 138, 0 },
        { "Blue", 4, 0, 139, 0 },
        { "Portal", 2, 0, 140, 0 },
        { "Position", 2, 0, 144, 0 },
        { "SaveMonsters", 2, 0, 148, 0 },
        { "LOSDraw", 2, 0, 152, 0 },
        { gszTxtField_end_006D9060, 0, 0, 0, 0 },
    };

    gpLevelDefBin = (D2LevelDefBin*)DATATBLS_CompileTxt(hArchive, "leveldefs", pTbl, 0, 0x9C);
    DATATBLS_InitPortalLevels(gpLevelDefBin);
}

// 0x0061E440
void __fastcall DATATBLS_UnloadLevelDefsBin()
{
    if (gpLevelDefBin)
    {
        DATATBLS_UnloadBin(gpLevelDefBin);
    }

    if (gpPortalLevels)
    {
        sub_0040B480(0, gpPortalLevels, ".\\DATATBLS\\LvlTbls.cpp", 473, 0);
    }
}

// 0x0061E470
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId)
{
    if (nLevelId >= 0 && nLevelId < sgptDataTables->nLevelsTxtRecordCount)
    {
        return &gpLevelDefBin[nLevelId];
    }

    return 0;
}

// 0x0061E4A0
static void DATATBLS_PrefixPathWithDirectory(const char* szDirectory, char* szPath)
{
    char szBuffer[60];
    const int nLength = strlen(szPath);
    if (nLength)
    {
        for (int i = 0; i < nLength; ++i)
        {
            if (szPath[i] == '/')
                szPath[i] = '\\';
        }
    }
    if (nLength > 1)
    {
        wsprintfA(szBuffer, gszPathFormat_006D4124, szDirectory, szPath);
        strcpy(szPath, szBuffer);
    }
}

// 0x0061E520
void __fastcall DATATBLS_LoadLevelTypesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "File 1", 1, 0x3B, 0, 0 },
        { "File 2", 1, 0x3B, 0x3C, 0 },
        { "File 3", 1, 0x3B, 0x78, 0 },
        { "File 4", 1, 0x3B, 0xB4, 0 },
        { "File 5", 1, 0x3B, 0xF0, 0 },
        { "File 6", 1, 0x3B, 0x12C, 0 },
        { "File 7", 1, 0x3B, 0x168, 0 },
        { "File 8", 1, 0x3B, 0x1A4, 0 },
        { "File 9", 1, 0x3B, 0x1E0, 0 },
        { "File 10", 1, 0x3B, 0x21C, 0 },
        { "File 11", 1, 0x3B, 0x258, 0 },
        { "File 12", 1, 0x3B, 0x294, 0 },
        { "File 13", 1, 0x3B, 0x2D0, 0 },
        { "File 14", 1, 0x3B, 0x30C, 0 },
        { "File 15", 1, 0x3B, 0x348, 0 },
        { "File 16", 1, 0x3B, 0x384, 0 },
        { "File 17", 1, 0x3B, 0x3C0, 0 },
        { "File 18", 1, 0x3B, 0x3FC, 0 },
        { "File 19", 1, 0x3B, 0x438, 0 },
        { "File 20", 1, 0x3B, 0x474, 0 },
        { "File 21", 1, 0x3B, 0x4B0, 0 },
        { "File 22", 1, 0x3B, 0x4EC, 0 },
        { "File 23", 1, 0x3B, 0x528, 0 },
        { "File 24", 1, 0x3B, 0x564, 0 },
        { "File 25", 1, 0x3B, 0x5A0, 0 },
        { "File 26", 1, 0x3B, 0x5DC, 0 },
        { "File 27", 1, 0x3B, 0x618, 0 },
        { "File 28", 1, 0x3B, 0x654, 0 },
        { "File 29", 1, 0x3B, 0x690, 0 },
        { "File 30", 1, 0x3B, 0x6CC, 0 },
        { "File 31", 1, 0x3B, 0x708, 0 },
        { "File 32", 1, 0x3B, 0x744, 0 },
        { "Act", 4, 0, 0x780, 0 },
        { gszTxtField_Expansion, 2, 0, 0x784, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    D2LvlTypesTxt* pLvlTypesTxt = (D2LvlTypesTxt*)DATATBLS_CompileTxt(hArchive, "lvltypes", pTbl, &sgtDataTables.nLvlTypesTxtRecordCount, sizeof(D2LvlTypesTxt));
    sgtDataTables.pLvlTypesTxt = pLvlTypesTxt;
    D2LvlTypesTxt* pRecord = pLvlTypesTxt;
    for (int i = 0; i < sgtDataTables.nLvlTypesTxtRecordCount; ++i)
    {
        for (int j = 0; j < 0x20; ++j)
        {
            DATATBLS_PrefixPathWithDirectory(gszTilesDirectory, pRecord->szFile[j]);
        }
        ++pRecord;
    }
}

// 0x0061EA90
void __fastcall DATATBLS_UnloadLevelTypesTxt()
{
    DATATBLS_UnloadBin(gpLvlTypesTxt);
}

// 0x0061EAA0
D2LvlTypesTxt* __stdcall DATATBLS_GetLevelTypesTxtRecord(int nLevelType)
{
    LVL_ASSERT(gpLvlTypesTxt, 593);
    return &gpLvlTypesTxt[nLevelType];
}

// 0x0061EAE0
int __stdcall DATATBLS_CheckActInLevelTypesTxt(int nLevelType, unsigned char nAct)
{
    D2LvlTypesTxt* pLevelTypesTxtRecord = DATATBLS_GetLevelTypesTxtRecord(nLevelType);

    return pLevelTypesTxtRecord != 0 && pLevelTypesTxtRecord->nAct == nAct;
}

// 0x0061EB40
void __stdcall DATATBLS_GetFileNameFromLevelTypeAndFileId(int nLevelType, int nFile, char* szFile)
{
    D2LvlTypesTxt* pLevelTypesTxtRecord = DATATBLS_GetLevelTypesTxtRecord(nLevelType);

    *szFile = 0;

    if (pLevelTypesTxtRecord && nFile < 32)
    {
        strcpy(szFile, pLevelTypesTxtRecord->szFile[nFile]);
    }
}

// 0x0061EBB0
void __fastcall DATATBLS_LoadLvlPrestTxt(void* hArchive, int bLoadFiles)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Def", 2, 0, 0, 0 },
        { "LevelId", 2, 0, 4, 0 },
        { "Populate", 2, 0, 8, 0 },
        { "Logicals", 2, 0, 0xC, 0 },
        { "Outdoors", 2, 0, 0x10, 0 },
        { "Animate", 2, 0, 0x14, 0 },
        { "KillEdge", 2, 0, 0x18, 0 },
        { "FillBlanks", 2, 0, 0x1C, 0 },
        { "SizeX", 2, 0, 0x28, 0 },
        { "SizeY", 2, 0, 0x2C, 0 },
        { "AutoMap", 2, 0, 0x30, 0 },
        { "Scan", 2, 0, 0x34, 0 },
        { "Pops", 2, 0, 0x38, 0 },
        { "PopPad", 2, 0, 0x3C, 0 },
        { "Files", 2, 0, 0x40, 0 },
        { "File1", 1, 0x3B, 0x44, 0 },
        { "File2", 1, 0x3B, 0x80, 0 },
        { "File3", 1, 0x3B, 0xBC, 0 },
        { "File4", 1, 0x3B, 0xF8, 0 },
        { "File5", 1, 0x3B, 0x134, 0 },
        { "File6", 1, 0x3B, 0x170, 0 },
        { "Dt1Mask", 2, 0, 0x1AC, 0 },
        { gszTxtField_Expansion, 2, 0, 0x20, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };
    sgtDataTables.pLvlPrestTxt = (D2LvlPrestTxt*)DATATBLS_CompileTxt(hArchive, "lvlprest", pTbl, &sgtDataTables.nLvlPrestTxtRecordCount, sizeof(D2LvlPrestTxt));
    if (bLoadFiles)
    {
        const int nSize = sizeof(D2DrlgFileStrc*) * 6 * sgptDataTables->nLvlPrestTxtRecordCount;
        sgtDataTables.ppLvlPrestFiles = (D2DrlgFileStrc**)FOG_Alloc(nSize, ".\\DATATBLS\\LvlTbls.cpp", 0x2A7, 0);
        memset(sgtDataTables.ppLvlPrestFiles, 0, nSize);
    }
    D2LvlPrestTxt* pRecord = sgtDataTables.pLvlPrestTxt;
    const int bExpansion = FOG_IsExpansion();
    for (int i = 0; i < sgptDataTables->nLvlPrestTxtRecordCount; ++i, ++pRecord)
    {
        if (bExpansion || !pRecord->dwExpansion)
        {
            for (unsigned int j = 0; j < 6; ++j)
            {
                DATATBLS_PrefixPathWithDirectory(gszTilesDirectory, pRecord->szFile[j]);
                if (bLoadFiles && strlen(pRecord->szFile[j]) > 1)
                    DRLGPRESET_LoadDrlgFile(&sgtDataTables.ppLvlPrestFiles[j + 6 * i], 0, pRecord->szFile[j]);
            }
        }
    }
}

// 0x0061F030
void __fastcall DATATBLS_UnloadLvlPrestTxt()
{
    D2DrlgFileStrc** ppLvlPrestFiles = gppLvlPrestDrlgFiles;

    if (gppLvlPrestDrlgFiles)
    {
        for (int i = 0; i < 6 * sgptDataTables->nLvlPrestTxtRecordCount; ++i)
        {
            if (ppLvlPrestFiles[i])
            {
                DRLGPRESET_FreeDrlgFile(&ppLvlPrestFiles[i]);
                ppLvlPrestFiles = gppLvlPrestDrlgFiles;
            }
        }

        FOG_Free(ppLvlPrestFiles, ".\\DATATBLS\\LvlTbls.cpp", 722, 0);
        gppLvlPrestDrlgFiles = 0;
    }

    if (gpLvlPrestTxt)
    {
        DATATBLS_UnloadBin(gpLvlPrestTxt);
    }
}

// 0x0061F0B0
D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nLvlPrestTxtRecordCount)
    {
        return &gpLvlPrestTxt[nId];
    }

    return 0;
}

// 0x0061F0E0
D2LvlPrestTxt* __fastcall DATATBLS_GetLvlPrestTxtRecordFromLevelId(int nLevelId)
{
    for (int i = 0; i < sgptDataTables->nLvlPrestTxtRecordCount; ++i)
    {
        if (gpLvlPrestTxt[i].dwLevelId == nLevelId)
        {
            return &gpLvlPrestTxt[i];
        }
    }

    return 0;
}

void __fastcall sub_Z16_EmitFixPathSlashes(char* pRecords, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        DATATBLS_PrefixPathWithDirectory("DATA\\GLOBAL\\TILES", pRecords);
        pRecords += 0x3C;
    }
}

// 0x0061F130
void __fastcall DATATBLS_LoadLvlWarpTxt(void* hArchive)
{
    int nRecordCount;
    D2BinFieldStrc pTbl[] =
    {
        { "Id", 2, 0, 0, 0 },
        { "SelectX", 2, 0, 4, 0 },
        { "SelectY", 2, 0, 8, 0 },
        { "SelectDX", 2, 0, 12, 0 },
        { "SelectDY", 2, 0, 16, 0 },
        { "ExitWalkX", 2, 0, 20, 0 },
        { "ExitWalkY", 2, 0, 24, 0 },
        { "OffsetX", 2, 0, 28, 0 },
        { "OffsetY", 2, 0, 32, 0 },
        { "LitVersion", 2, 0, 36, 0 },
        { "Tiles", 2, 0, 40, 0 },
        { "Direction", 1, 1, 44, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpLvlwarpTxt = DATATBLS_CompileTxt(hArchive, "lvlwarp", pTbl, &nRecordCount, 48);
    gnLvlwarpTxtRecordCount = nRecordCount;
}

// 0x0061F300
void __fastcall DATATBLS_UnloadLvlWarpTxt()
{
    DATATBLS_UnloadBin(gpLvlWarpTxt);
}

// 0x0061F310
D2LvlWarpTxt* __fastcall DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(int nLevelId, char szDirection)
{
    D2LvlWarpTxt* pLvlWarpTxtRecord = gpLvlWarpTxt;
    LVL_ASSERT(pLvlWarpTxtRecord, 811);

    for (int i = 0; i < gnLvlwarpTxtRecordCount; ++i)
    {
        if (pLvlWarpTxtRecord->dwLevelId == nLevelId)
        {
            if (szDirection == 'b' || pLvlWarpTxtRecord->szDirection[0] == 'b' || pLvlWarpTxtRecord->szDirection[0] == szDirection)
            {
                return pLvlWarpTxtRecord;
            }
        }
        ++pLvlWarpTxtRecord;
    }

    LVL_ASSERT(0, 826);
}

// 0x0061F380
void __fastcall DATATBLS_LoadLvlMazeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Level", 2, 0, 0, 0 },
        { "Rooms", 2, 0, 4, 0 },
        { "Rooms(N)", 2, 0, 8, 0 },
        { "Rooms(H)", 2, 0, 12, 0 },
        { "SizeX", 2, 0, 16, 0 },
        { "SizeY", 2, 0, 20, 0 },
        { "Merge", 2, 0, 24, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpLvlmazeTxt = DATATBLS_CompileTxt(hArchive, "lvlmaze", pTbl, &gnLvlmazeTxtRecordCount, 28);
}

// 0x0061F480
void __fastcall DATATBLS_UnloadLvlMazeTxt()
{
    DATATBLS_UnloadBin(gpLvlMazeTxt);
}

// 0x0061F490
D2LvlMazeTxt* __fastcall DATATBLS_GetLvlMazeTxtRecordFromLevelId(int nLevelId)
{
    LVL_ASSERT(gpLvlMazeTxt, 867);

    for (int i = 0; i < gnLvlmazeTxtRecordCount; ++i)
    {
        if (gpLvlMazeTxt[i].dwLevelId == nLevelId)
        {
            return &gpLvlMazeTxt[i];
        }
    }

    LVL_ASSERT(0, 876);
}

// 0x0061F500
void __fastcall DATATBLS_LoadLvlSubTxt(void* archive,int loadFiles,int extra)
{
 D2BinFieldStrc fields[]={
  {gszField_Type,2,0,0x0,0},
  {gszField_File,1,59,0x4,0},
  {gszField_CheckAll,2,0,0x40,0},
  {gszField_BordType,2,0,0x44,0},
  {gszField_GridSize,2,0,0x4c,0},
  {gszField_Dt1Mask,2,0,0x48,0},
  {gszField_Prob0,2,0,0x11c,0},
  {gszField_Trials0,2,0,0x130,0},
  {gszField_Max0,2,0,0x144,0},
  {gszField_Prob1,2,0,0x120,0},
  {gszField_Trials1,2,0,0x134,0},
  {gszField_Max1,2,0,0x148,0},
  {gszField_Prob2,2,0,0x124,0},
  {gszField_Trials2,2,0,0x138,0},
  {gszField_Max2,2,0,0x14c,0},
  {gszField_Prob3,2,0,0x128,0},
  {gszField_Trials3,2,0,0x13c,0},
  {gszField_Max3,2,0,0x150,0},
  {gszField_Prob4,2,0,0x12c,0},
  {gszField_Trials4,2,0,0x140,0},
  {gszField_Max4,2,0,0x154,0},
  {gszField_Expansion,2,0,0x158,0},
  {gszField_end,0,0,0x0,0},
 };
  int maxType=0;
 D2LvlSubTxt* rows=(D2LvlSubTxt*)DATATBLS_CompileTxt(archive,gszLvlSubTableName,fields,&gnLvlSubTxtRecordCount,sizeof(D2LvlSubTxt));
 gpLvlSubTxt=rows;
 if(gnLvlSubTxtRecordCount>0) {
  for(int i=0;i<gnLvlSubTxtRecordCount;++i) { if(rows[i].dwType>maxType)maxType=rows[i].dwType; }
  if(maxType) {
   int size=sizeof(int)*(maxType+1);
   gpLvlSubTypeStartIds=(int*)FOG_AllocPool(0,size,gszLvlTblsSourceFile,0x3a6,0);
   memset(gpLvlSubTypeStartIds,0,size);
   int lastType=0;
   D2LvlSubTxt* txt=gpLvlSubTxt;
   int i=0;
   while(i<gnLvlSubTxtRecordCount) {
    if(txt[i].dwType!=lastType) {

     if(txt[i].dwType>lastType) { lastType=txt[i].dwType;gpLvlSubTypeStartIds[lastType]=i; }
     else { lastType=txt[i].dwType;gpLvlSubTypeStartIds[lastType]=i; }
     ++i; continue;
    }
    ++i;
   }
  }
 }
 if(loadFiles||extra) {
  gppLvlSubDrlgFiles=(D2DrlgFileStrc**)FOG_Alloc(sizeof(D2DrlgFileStrc*)*gnLvlSubTxtRecordCount,gszLvlTblsSourceFile,0x3b6,0);
  memset(gppLvlSubDrlgFiles,0,sizeof(D2DrlgFileStrc*)*gnLvlSubTxtRecordCount);
 }
 D2LvlSubTxt* row=gpLvlSubTxt;
 int expansion=FOG_IsExpansion();
 for(int i=0;i<gnLvlSubTxtRecordCount;++i,++row) {
  DATATBLS_PrefixPathWithDirectory(gszTilesDirectory,row->szFile);
  if((expansion||!row->dwExpansion)&&(loadFiles||extra)) {
   DRLGPRESET_LoadDrlgFile(&gppLvlSubDrlgFiles[i],0,row->szFile);
   if(!gppLvlSubDrlgFiles[i]->nSubstGroups) {
    FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x3c8);sub_00681E09_Exit(-1);
   }
  }
 }
}

// 0x0061F9C0
void __fastcall DATATBLS_UnloadLvlSubTxt()
{
    D2DrlgFileStrc** ppFiles = gppLvlSubDrlgFiles;

    if (gppLvlSubDrlgFiles)
    {
        for (int i = 0; i < gnLvlSubTxtRecordCount; ++i)
        {
            if (ppFiles[i])
            {
                DRLGPRESET_FreeDrlgFile(&ppFiles[i]);
                ppFiles = gppLvlSubDrlgFiles;
            }
        }

        FOG_Free(ppFiles, ".\\DATATBLS\\LvlTbls.cpp", 984, 0);
        gppLvlSubDrlgFiles = 0;
    }

    if (gpLvlSubTxt)
    {
        for (int i = 0; i < gnLvlSubTxtRecordCount; ++i)
        {
            DRLGTILESUB_FreeDrlgFile(&gpLvlSubTxt[i]);
        }

        DATATBLS_UnloadBin(gpLvlSubTxt);
        gpLvlSubTxt = 0;
    }

    if (gpLvlSubTypeStartIds)
    {
        sub_0040B480(0, gpLvlSubTypeStartIds, ".\\DATATBLS\\LvlTbls.cpp", 1000, 0);
        gpLvlSubTypeStartIds = 0;
    }
}

// 0x0061FA90
D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nSubType)
{
    LVL_ASSERT(nSubType >= 0, 1009);
    LVL_ASSERT(gpLvlSubTxt, 1010);
    LVL_ASSERT(gpLvlSubTypeStartIds, 1011);

    return &gpLvlSubTxt[gpLvlSubTypeStartIds[nSubType]];
}

// 0x0061FAE0
void __fastcall DATATBLS_AllocGlobalTileLibraryHash()
{
    D2_ASSERT(gpLvlTypesTxt_0096C9F0, 1040);

    const int nSize = sizeof(D2TileLibraryHeaderStrc*[1024]) * gnLvlTypesTxtRecordCount;
    gppTileLibraryHash_0096CA1C = (D2TileLibraryHeaderStrc**)FOG_AllocPool(0, nSize, ".\\DATATBLS\\LvlTbls.cpp", 1043, 0);
    memset(gppTileLibraryHash_0096CA1C, 0, nSize);

    D2TileLibraryHeaderStrc** ppTileLibraryHash = gppTileLibraryHash_0096CA1C;
    const int bExpansion = FOG_IsExpansion();
    for (int i = 0; i < gnLvlTypesTxtRecordCount; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            if (!strcmp(gpLvlTypesTxt_0096C9F0[i].szFile[j], "0"))
            {
                break;
            }

            if (bExpansion || !gpLvlTypesTxt_0096C9F0[i].dwExpansion)
            {
                TileLibraryAddProject(ppTileLibraryHash, gpLvlTypesTxt_0096C9F0[i].szFile[j]);
            }
        }
        ppTileLibraryHash += 1024;
    }
}

// 0x0061FBF0
void __fastcall DATATBLS_FreeGlobalTileLibraryHash()
{
    if (gppTileLibraryHash)
    {
        sub_0040B480(0, gppTileLibraryHash, ".\\DATATBLS\\LvlTbls.cpp", 1082, 0);
    }
}

void sub_W12_EmitLvlTypesTxtWrites(D2LvlTypesTxt* pLvlTypesTxt, int nRecordCount)
{
    gpLvlTypesTxt_0096C9F0 = pLvlTypesTxt;
    gnLvlTypesTxtRecordCount = nRecordCount;
}

// 0x0061FC10
static int DATATBLS_GetAutomapLevelType(const char* szLevelName)
{
    if (szLevelName[0] != '0')
    {
        for (int nLevelType = 0; nLevelType < 36; ++nLevelType)
        {
            if (!strcmp(szLevelName, gszAutomapLevelNames[nLevelType]))
            {
                return nLevelType;
            }
        }

        D2_ASSERT(0, 0x4A5);
    }

    return 0;
}

// 0x0061FC80
static int DATATBLS_GetAutomapTileType(const char* szTileName)
{
    if (szTileName[0] != '0')
    {
        for (int nTileType = 0; nTileType < 20; ++nTileType)
        {
            if (!strcmp(szTileName, gszAutomapTileNames[nTileType]))
            {
                return nTileType;
            }
        }

        D2_ASSERT(0, 0x4D0);
    }

    return 0;
}

void __stdcall sub_M14_EmitAutomapLookups(const char* pAutomapRecord, int* pTypes)
{
    pTypes[0] = DATATBLS_GetAutomapLevelType(pAutomapRecord);
    pTypes[1] = DATATBLS_GetAutomapTileType(pAutomapRecord + 16);
}

// 0x0061C540
void __fastcall DATATBLS_LoadLevelsTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Id", TXTFIELD_BYTE, 0, 0, 0 },
        { "Pal", TXTFIELD_BYTE, 0, 2, 0 },
        { "Act", TXTFIELD_BYTE, 0, 3, 0 },
        { "Teleport", TXTFIELD_BYTE, 0, 4, 0 },
        { "Rain", TXTFIELD_BYTE, 0, 5, 0 },
        { "Mud", TXTFIELD_BYTE, 0, 6, 0 },
        { "NoPer", TXTFIELD_BYTE, 0, 7, 0 },
        { "IsInside", TXTFIELD_BYTE, 0, 8, 0 },
        { "DrawEdges", TXTFIELD_BYTE, 0, 9, 0 },
        { "WarpDist", TXTFIELD_DWORD, 0, 12, 0 },
        { "MonLvl1", TXTFIELD_WORD, 0, 16, 0 },
        { "MonLvl2", TXTFIELD_WORD, 0, 18, 0 },
        { "MonLvl3", TXTFIELD_WORD, 0, 20, 0 },
        { "MonLvl1Ex", TXTFIELD_WORD, 0, 22, 0 },
        { "MonLvl2Ex", TXTFIELD_WORD, 0, 24, 0 },
        { "MonLvl3Ex", TXTFIELD_WORD, 0, 26, 0 },
        { "MonDen", TXTFIELD_DWORD, 0, 28, 0 },
        { "MonDen(N)", TXTFIELD_DWORD, 0, 32, 0 },
        { "MonDen(H)", TXTFIELD_DWORD, 0, 36, 0 },
        { "MonUMin", TXTFIELD_BYTE, 0, 40, 0 },
        { "MonUMax", TXTFIELD_BYTE, 0, 43, 0 },
        { "MonUMin(N)", TXTFIELD_BYTE, 0, 41, 0 },
        { "MonUMax(N)", TXTFIELD_BYTE, 0, 44, 0 },
        { "MonUMin(H)", TXTFIELD_BYTE, 0, 42, 0 },
        { "MonUMax(H)", TXTFIELD_BYTE, 0, 45, 0 },
        { "MonWndr", TXTFIELD_BYTE, 0, 46, 0 },
        { "MonSpcWalk", TXTFIELD_BYTE, 0, 47, 0 },
        { "ObjGrp0", TXTFIELD_BYTE, 0, 229, 0 },
        { "ObjGrp1", TXTFIELD_BYTE, 0, 230, 0 },
        { "ObjGrp2", TXTFIELD_BYTE, 0, 231, 0 },
        { "ObjGrp3", TXTFIELD_BYTE, 0, 232, 0 },
        { "ObjGrp4", TXTFIELD_BYTE, 0, 233, 0 },
        { "ObjGrp5", TXTFIELD_BYTE, 0, 234, 0 },
        { "ObjGrp6", TXTFIELD_BYTE, 0, 235, 0 },
        { "ObjGrp7", TXTFIELD_BYTE, 0, 236, 0 },
        { "ObjPrb0", TXTFIELD_BYTE, 0, 237, 0 },
        { "ObjPrb1", TXTFIELD_BYTE, 0, 238, 0 },
        { "ObjPrb2", TXTFIELD_BYTE, 0, 239, 0 },
        { "ObjPrb3", TXTFIELD_BYTE, 0, 240, 0 },
        { "ObjPrb4", TXTFIELD_BYTE, 0, 241, 0 },
        { "ObjPrb5", TXTFIELD_BYTE, 0, 242, 0 },
        { "ObjPrb6", TXTFIELD_BYTE, 0, 243, 0 },
        { "ObjPrb7", TXTFIELD_BYTE, 0, 244, 0 },
        { "Quest", TXTFIELD_BYTE, 0, 48, 0 },
        { "NumMon", TXTFIELD_BYTE, 0, 50, 0 },
        { "mon1", TXTFIELD_NAMETOWORD, 0, 54, &sgtDataTables.pMonStatsLinker },
        { "mon2", TXTFIELD_NAMETOWORD, 0, 56, &sgtDataTables.pMonStatsLinker },
        { "mon3", TXTFIELD_NAMETOWORD, 0, 58, &sgtDataTables.pMonStatsLinker },
        { "mon4", TXTFIELD_NAMETOWORD, 0, 60, &sgtDataTables.pMonStatsLinker },
        { "mon5", TXTFIELD_NAMETOWORD, 0, 62, &sgtDataTables.pMonStatsLinker },
        { "mon6", TXTFIELD_NAMETOWORD, 0, 64, &sgtDataTables.pMonStatsLinker },
        { "mon7", TXTFIELD_NAMETOWORD, 0, 66, &sgtDataTables.pMonStatsLinker },
        { "mon8", TXTFIELD_NAMETOWORD, 0, 68, &sgtDataTables.pMonStatsLinker },
        { "mon9", TXTFIELD_NAMETOWORD, 0, 70, &sgtDataTables.pMonStatsLinker },
        { "mon10", TXTFIELD_NAMETOWORD, 0, 72, &sgtDataTables.pMonStatsLinker },
        { "mon11", TXTFIELD_NAMETOWORD, 0, 74, &sgtDataTables.pMonStatsLinker },
        { "mon12", TXTFIELD_NAMETOWORD, 0, 76, &sgtDataTables.pMonStatsLinker },
        { "mon13", TXTFIELD_NAMETOWORD, 0, 78, &sgtDataTables.pMonStatsLinker },
        { "mon14", TXTFIELD_NAMETOWORD, 0, 80, &sgtDataTables.pMonStatsLinker },
        { "mon15", TXTFIELD_NAMETOWORD, 0, 82, &sgtDataTables.pMonStatsLinker },
        { "mon16", TXTFIELD_NAMETOWORD, 0, 84, &sgtDataTables.pMonStatsLinker },
        { "mon17", TXTFIELD_NAMETOWORD, 0, 86, &sgtDataTables.pMonStatsLinker },
        { "mon18", TXTFIELD_NAMETOWORD, 0, 88, &sgtDataTables.pMonStatsLinker },
        { "mon19", TXTFIELD_NAMETOWORD, 0, 90, &sgtDataTables.pMonStatsLinker },
        { "mon20", TXTFIELD_NAMETOWORD, 0, 92, &sgtDataTables.pMonStatsLinker },
        { "mon21", TXTFIELD_NAMETOWORD, 0, 94, &sgtDataTables.pMonStatsLinker },
        { "mon22", TXTFIELD_NAMETOWORD, 0, 96, &sgtDataTables.pMonStatsLinker },
        { "mon23", TXTFIELD_NAMETOWORD, 0, 98, &sgtDataTables.pMonStatsLinker },
        { "mon24", TXTFIELD_NAMETOWORD, 0, 100, &sgtDataTables.pMonStatsLinker },
        { "mon25", TXTFIELD_NAMETOWORD, 0, 102, &sgtDataTables.pMonStatsLinker },
        { "rangedspawn", TXTFIELD_BYTE, 0, 49, 0 },
        { "nmon1", TXTFIELD_NAMETOWORD, 0, 104, &sgtDataTables.pMonStatsLinker },
        { "nmon2", TXTFIELD_NAMETOWORD, 0, 106, &sgtDataTables.pMonStatsLinker },
        { "nmon3", TXTFIELD_NAMETOWORD, 0, 108, &sgtDataTables.pMonStatsLinker },
        { "nmon4", TXTFIELD_NAMETOWORD, 0, 110, &sgtDataTables.pMonStatsLinker },
        { "nmon5", TXTFIELD_NAMETOWORD, 0, 112, &sgtDataTables.pMonStatsLinker },
        { "nmon6", TXTFIELD_NAMETOWORD, 0, 114, &sgtDataTables.pMonStatsLinker },
        { "nmon7", TXTFIELD_NAMETOWORD, 0, 116, &sgtDataTables.pMonStatsLinker },
        { "nmon8", TXTFIELD_NAMETOWORD, 0, 118, &sgtDataTables.pMonStatsLinker },
        { "nmon9", TXTFIELD_NAMETOWORD, 0, 120, &sgtDataTables.pMonStatsLinker },
        { "nmon10", TXTFIELD_NAMETOWORD, 0, 122, &sgtDataTables.pMonStatsLinker },
        { "nmon11", TXTFIELD_NAMETOWORD, 0, 124, &sgtDataTables.pMonStatsLinker },
        { "nmon12", TXTFIELD_NAMETOWORD, 0, 126, &sgtDataTables.pMonStatsLinker },
        { "nmon13", TXTFIELD_NAMETOWORD, 0, 128, &sgtDataTables.pMonStatsLinker },
        { "nmon14", TXTFIELD_NAMETOWORD, 0, 130, &sgtDataTables.pMonStatsLinker },
        { "nmon15", TXTFIELD_NAMETOWORD, 0, 132, &sgtDataTables.pMonStatsLinker },
        { "nmon16", TXTFIELD_NAMETOWORD, 0, 134, &sgtDataTables.pMonStatsLinker },
        { "nmon17", TXTFIELD_NAMETOWORD, 0, 136, &sgtDataTables.pMonStatsLinker },
        { "nmon18", TXTFIELD_NAMETOWORD, 0, 138, &sgtDataTables.pMonStatsLinker },
        { "nmon19", TXTFIELD_NAMETOWORD, 0, 140, &sgtDataTables.pMonStatsLinker },
        { "nmon20", TXTFIELD_NAMETOWORD, 0, 142, &sgtDataTables.pMonStatsLinker },
        { "nmon21", TXTFIELD_NAMETOWORD, 0, 144, &sgtDataTables.pMonStatsLinker },
        { "nmon22", TXTFIELD_NAMETOWORD, 0, 146, &sgtDataTables.pMonStatsLinker },
        { "nmon23", TXTFIELD_NAMETOWORD, 0, 148, &sgtDataTables.pMonStatsLinker },
        { "nmon24", TXTFIELD_NAMETOWORD, 0, 150, &sgtDataTables.pMonStatsLinker },
        { "nmon25", TXTFIELD_NAMETOWORD, 0, 152, &sgtDataTables.pMonStatsLinker },
        { "umon1", TXTFIELD_NAMETOWORD, 0, 154, &sgtDataTables.pMonStatsLinker },
        { "umon2", TXTFIELD_NAMETOWORD, 0, 156, &sgtDataTables.pMonStatsLinker },
        { "umon3", TXTFIELD_NAMETOWORD, 0, 158, &sgtDataTables.pMonStatsLinker },
        { "umon4", TXTFIELD_NAMETOWORD, 0, 160, &sgtDataTables.pMonStatsLinker },
        { "umon5", TXTFIELD_NAMETOWORD, 0, 162, &sgtDataTables.pMonStatsLinker },
        { "umon6", TXTFIELD_NAMETOWORD, 0, 164, &sgtDataTables.pMonStatsLinker },
        { "umon7", TXTFIELD_NAMETOWORD, 0, 166, &sgtDataTables.pMonStatsLinker },
        { "umon8", TXTFIELD_NAMETOWORD, 0, 168, &sgtDataTables.pMonStatsLinker },
        { "umon9", TXTFIELD_NAMETOWORD, 0, 170, &sgtDataTables.pMonStatsLinker },
        { "umon10", TXTFIELD_NAMETOWORD, 0, 172, &sgtDataTables.pMonStatsLinker },
        { "umon11", TXTFIELD_NAMETOWORD, 0, 174, &sgtDataTables.pMonStatsLinker },
        { "umon12", TXTFIELD_NAMETOWORD, 0, 176, &sgtDataTables.pMonStatsLinker },
        { "umon13", TXTFIELD_NAMETOWORD, 0, 178, &sgtDataTables.pMonStatsLinker },
        { "umon14", TXTFIELD_NAMETOWORD, 0, 180, &sgtDataTables.pMonStatsLinker },
        { "umon15", TXTFIELD_NAMETOWORD, 0, 182, &sgtDataTables.pMonStatsLinker },
        { "umon16", TXTFIELD_NAMETOWORD, 0, 184, &sgtDataTables.pMonStatsLinker },
        { "umon17", TXTFIELD_NAMETOWORD, 0, 186, &sgtDataTables.pMonStatsLinker },
        { "umon18", TXTFIELD_NAMETOWORD, 0, 188, &sgtDataTables.pMonStatsLinker },
        { "umon19", TXTFIELD_NAMETOWORD, 0, 190, &sgtDataTables.pMonStatsLinker },
        { "umon20", TXTFIELD_NAMETOWORD, 0, 192, &sgtDataTables.pMonStatsLinker },
        { "umon21", TXTFIELD_NAMETOWORD, 0, 194, &sgtDataTables.pMonStatsLinker },
        { "umon22", TXTFIELD_NAMETOWORD, 0, 196, &sgtDataTables.pMonStatsLinker },
        { "umon23", TXTFIELD_NAMETOWORD, 0, 198, &sgtDataTables.pMonStatsLinker },
        { "umon24", TXTFIELD_NAMETOWORD, 0, 200, &sgtDataTables.pMonStatsLinker },
        { "umon25", TXTFIELD_NAMETOWORD, 0, 202, &sgtDataTables.pMonStatsLinker },
        { "cmon1", TXTFIELD_NAMETOWORD, 0, 204, &sgtDataTables.pMonStatsLinker },
        { "cmon2", TXTFIELD_NAMETOWORD, 0, 206, &sgtDataTables.pMonStatsLinker },
        { "cmon3", TXTFIELD_NAMETOWORD, 0, 208, &sgtDataTables.pMonStatsLinker },
        { "cmon4", TXTFIELD_NAMETOWORD, 0, 210, &sgtDataTables.pMonStatsLinker },
        { "cpct1", TXTFIELD_WORD, 0, 212, 0 },
        { "cpct2", TXTFIELD_WORD, 0, 214, 0 },
        { "cpct3", TXTFIELD_WORD, 0, 216, 0 },
        { "cpct4", TXTFIELD_WORD, 0, 218, 0 },
        { "camt1", TXTFIELD_WORD, 0, 220, 0 },
        { "camt2", TXTFIELD_WORD, 0, 220, 0 },
        { "camt3", TXTFIELD_WORD, 0, 220, 0 },
        { "camt4", TXTFIELD_WORD, 0, 220, 0 },
        { "Themes", TXTFIELD_DWORD, 0, 528, 0 },
        { "FloorFilter", TXTFIELD_DWORD, 0, 532, 0 },
        { "BlankScreen", TXTFIELD_DWORD, 0, 536, 0 },
        { "SoundEnv", TXTFIELD_BYTE, 0, 540, 0 },
        { "Waypoint", TXTFIELD_BYTE, 0, 228, 0 },
        { "LevelName", TXTFIELD_ASCII, 39, 245, 0 },
        { "LevelWarp", TXTFIELD_ASCII, 39, 285, 0 },
        { "EntryFile", TXTFIELD_ASCII, 39, 325, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    sgtDataTables.pLevelsTxt = (D2LevelsTxt*)DATATBLS_CompileTxt(hArchive, "levels", pTbl, &sgtDataTables.nLevelsTxtRecordCount, sizeof(D2LevelsTxt));

    D2_ASSERT(sgtDataTables.nLevelsTxtRecordCount < 1024, 199);

    for (int i = 0; i < sgtDataTables.nLevelsTxtRecordCount; ++i)
    {
        D2LevelsTxt* pLevelsTxtRecord = &sgtDataTables.pLevelsTxt[i];

        memset(pLevelsTxtRecord->wszLevelName, 0, 80);
        memset(pLevelsTxtRecord->wszLevelWarp, 0, 80);

        Unicode::strncpy((Unicode*)pLevelsTxtRecord->wszLevelName, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelName), 40);
        pLevelsTxtRecord->wszLevelName[39] = 0;

        Unicode::strncpy((Unicode*)pLevelsTxtRecord->wszLevelWarp, (const Unicode*)D2LANG_GetStringByReferenceString(pLevelsTxtRecord->szLevelWarp), 40);
        pLevelsTxtRecord->wszLevelWarp[39] = 0;

        for (int j = 0; j < sgtDataTables.nLevelsTxtRecordCount; ++j)
        {
            int nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wNormalMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumNormalMonsters = nMonsterCounter;

            nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wNightmareHellMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumNightmareHellMonsters = nMonsterCounter;

            nMonsterCounter = 0;
            do
            {
                if (pLevelsTxtRecord->wUniqueMonsters[nMonsterCounter] < 0)
                {
                    break;
                }
                ++nMonsterCounter;
            }
            while (nMonsterCounter < 25);
            pLevelsTxtRecord->nNumUniqueMonsters = nMonsterCounter;
        }
    }
}

#include "gen/data/Source/D2Common/DATATBLS/LvlTbls.inc"

// 0x0061FCF0
void __fastcall DATATBLS_LoadAutomapTxt(void* hArchive)
{
    D2AutomapRecordStrc* pAutomap = 0;
    D2AutomapTxt* pAutomapTxt;
    int nRecordCount;

    SEED_InitSeed(gpAutomapSeed);
    SEED_InitLowSeed(gpAutomapSeed, 0);

    D2BinFieldStrc pTbl[] =
    {
        { "LevelName", 1, 15, 0x00, 0 },
        { "TileName", 1, 7, 0x10, 0 },
        { "Style", 4, 0, 0x18, 0 },
        { "StartSequence", 4, 0, 0x19, 0 },
        { "EndSequence", 4, 0, 0x1A, 0 },
        { "Cel1", 2, 0, 0x1C, 0 },
        { "Cel2", 2, 0, 0x20, 0 },
        { "Cel3", 2, 0, 0x24, 0 },
        { "Cel4", 2, 0, 0x28, 0 },
        { gszTxtField_end_006D9060, 0, 0, 0, 0 },
    };

    pAutomapTxt = (D2AutomapTxt*)DATATBLS_CompileTxt(hArchive, "automap", pTbl, &nRecordCount, sizeof(D2AutomapTxt));
    pAutomap = (D2AutomapRecordStrc*)FOG_AllocPool(0, sizeof(D2AutomapRecordStrc) * nRecordCount, ".\\DATATBLS\\LvlTbls.cpp", 0x4F7, 0);
    memset(pAutomap, 0, sizeof(D2AutomapRecordStrc) * nRecordCount);

    for (int i = 0; i < nRecordCount; ++i)
    {
        pAutomap[i].nLevelNo = DATATBLS_GetAutomapLevelType(pAutomapTxt[i].szLevelName);
        pAutomap[i].nTileType = DATATBLS_GetAutomapTileType(pAutomapTxt[i].szTileName);
        pAutomap[i].nStyle = pAutomapTxt[i].nStyle;
        pAutomap[i].nStartSequence = pAutomapTxt[i].nStartSequence;
        pAutomap[i].nEndSequence = pAutomapTxt[i].nEndSequence;
        pAutomap[i].nCel[0] = pAutomapTxt[i].nCel[0];
        pAutomap[i].nCel[1] = pAutomapTxt[i].nCel[1];
        pAutomap[i].nCel[2] = pAutomapTxt[i].nCel[2];
        pAutomap[i].nCel[3] = pAutomapTxt[i].nCel[3];
        pAutomap[i].nCels = 0;

        for (int j = 0; j < 4; ++j)
        {
            if (pAutomap[i].nCel[j] == -1)
            {
                break;
            }
            ++pAutomap[i].nCels;
        }

        D2_ASSERT(pAutomap[i].nCels, 0x50D);
    }

    DATATBLS_UnloadBin(pAutomapTxt);

    gpAutomapRecords = pAutomap;
    gnAutomapRecordCount = nRecordCount;

    for (int i = 0; i < 36; ++i)
    {
        gaAutomapIndex[i].nStart = -1;
        gaAutomapIndex[i].nEnd = -1;
    }

    int nCounter = 0;
    while (nCounter < nRecordCount)
    {
        const int nLevelType = pAutomap[nCounter].nLevelNo;
        gaAutomapIndex[nLevelType].nStart = nCounter;
        while (nCounter + 1 < nRecordCount && nLevelType == pAutomap[nCounter + 1].nLevelNo)
        {
            ++nCounter;
        }
        ++nCounter;
        gaAutomapIndex[nLevelType].nEnd = nCounter;
    }

    D2_ASSERT(nCounter <= nRecordCount, 0x528);
}

// 0x0061FFF0
int __fastcall DATATBLS_GetAutomapCellId(int nLevelNo, int nTileType, int nStyle, int nSequence)
{
    if (!nLevelNo)
        return -1;

    int nStart = gaAutomapIndex[nLevelNo].nStart;
    int nEnd = gaAutomapIndex[nLevelNo].nEnd;
    if (nStart == -1)
        return -1;

    D2_ASSERT(gaAutomapIndex[nLevelNo].nEnd != -1, 0x53B);

    for (int i = nStart; i < nEnd; ++i)
    {
        if (gpAutomapRecords[i].nLevelNo == nLevelNo && gpAutomapRecords[i].nTileType == nTileType
            && (gpAutomapRecords[i].nStyle == 0xFF || gpAutomapRecords[i].nStyle == nStyle)
            && (gpAutomapRecords[i].nStartSequence == 0xFF
                || (gpAutomapRecords[i].nStartSequence <= nSequence && gpAutomapRecords[i].nEndSequence >= nSequence)))
        {
            D2AutomapRecordStrc* pRecords = gpAutomapRecords;
            return pRecords[i].nCel[ITEMS_RollLimitedRandomNumber(gpAutomapSeed, gpAutomapRecords[i].nCels)];
        }
    }
    return -1;
}

// 0x006200D0
void __fastcall DATATBLS_FreeAutomap()
{
    if (gpAutomapRecords)
    {
        FOG_FreeServerMemory(0, gpAutomapRecords, ".\\DATATBLS\\LvlTbls.cpp", 0x551, 0);
    }

    gpAutomapRecords = 0;
}

