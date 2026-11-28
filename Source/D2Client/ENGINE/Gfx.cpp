#include "D2LanguageNames.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2CelContext.h"
#include "D2ClientGfx.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"
#include "D2Path.h"
#include "D2LevelIds.h"
#include "D2ClientGfxState.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
#include "FogApi2.h"
#include "D2Constants.h"
#include "StormApi.h"
#include "D2GfxApi.h"
#include "D2WinApi.h"
#include "D2CMPApi.h"
#include "StormApi2.h"
#include "D2CommonApi3.h"
#include "D2ClientApi.h"

struct D2PoolSystemStrc;
struct D2UnitStrc;

struct D2UnitTargetStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_OBJECT 2

#define UNIT_INVALID 6

#define STAT_HITPOINTS 6

#define MONSTATSFLAGINDEX_INTERACT 9

struct D2GfxLightStrc;

union D2SeedStrc;

struct D2OverlayTxt;

struct D2StateNodeStrc;

struct D2StateOwnerStrc;

struct D2GfxListNodeStrc;

struct D2MonStatsTxt;

struct D2PlayerDataStrc;

struct D2GfxNodeTargetStrc;

struct D2UnitOverlayStrc;

struct D2GfxEntryStrc;

struct D2HashedFileEntryStrc;

struct D2HashedFileStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    int nCurrent;
    int nNextOverlay;
    int nNextState;
    int nSpeed;
    int nFrame;
    int nFrames;
    int nXOffset;
    int nYOffset;
    unsigned int dwDelay;
    unsigned int dwStamp;
    unsigned int dwDelayStart;
    int bFront;
    int nState;
    int nActive;
    union
    {
        D2GfxLightStrc* pLight;
        void* pResource;
    };
    char unk0x44[0x60];
    D2UnitOverlayStrc* pNext;
};

struct D2OverlayTxt
{
    char unk0x00[0x42];
    short wPreDraw;
    char unk0x44[4];
    unsigned char nByte48;
    char unk0x49[0x0B];
    int n54;
    int n58;
    int n5C;
    int n60;
    int n64;
    int n68;
    int n6C;
    int n70;
    int n74;
    int n78;
    unsigned char nTrans;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    unsigned char nNumDirections;
    unsigned char nLocalBlood;
    unsigned short pad0x82;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


D2UnitGfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10


D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius); // 0x00474290

int __fastcall GFXUTIL_GetOverlayFrameCount(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay); // 0x004DBE20




void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268




extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0


int __fastcall GFX_IsUnitOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0





void* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode); // 0x0046E570

D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040

void __fastcall GFXUTIL_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0



int __stdcall D2CMPSpriteValidate(D2GfxDataStrc* pContext, int nArg2, int nArg3); // 0x006001F0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480



int __fastcall PLAYER_ApplyUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce); // 0x00461250

extern D2UnitStrc* gapAiTargets[]; // 0x007A7470

int __fastcall FOG_FreePool(D2PoolSystemStrc* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480



void __stdcall TEXTURE_CelDrawShadow(D2GfxDataStrc* pContext, int nX, int nY); // 0x004F6540

#define GFX_MODE_KEEP 0x11

struct D2MsgHandlerEntryStrc;

struct D2GfxLayerStrc;

struct D2MonGfxCacheStrc;

struct D2RosterPetStrc;

struct D2MonStats2Txt;

struct D2GfxBoundsStrc;

static void __stdcall GFX_RemoveStateOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay); // 0x0046E040



extern int gdwLastPreloadTick; // 0x007A8910

extern int gnCofMemoryLimit; // 0x007A891C

extern "C" int __cdecl strcmp(const char* szA, const char* szB);

extern "C" HIMC__* __stdcall ImmGetContext(int hWnd); // 0x006B00C6

extern "C" int __stdcall ImmReleaseContext(int hWnd, HIMC__* hImc); // 0x006B00B4

extern "C" int __stdcall ImmGetConversionStatus(HIMC__* hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE

int __fastcall sub_00472280_RollInRange(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280

void __cdecl sub_00472400_ResetPhaseState(); // 0x00472400


int __fastcall ROSTERPETS_IsPetFriendly(D2UnitStrc* pPlayer, D2UnitStrc* pUnit); // 0x00478E70

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

extern int gbPhaseActive; // 0x007A8A1C

extern int gbPhaseBusy; // 0x007A8A20

extern int gaWeatherPhaseRange[]; // 0x007A8958

extern int gaWeatherPhaseOffset[]; // 0x007A8970

extern D2RosterPetStrc* gpRosterPets; // 0x007BB5BC

extern D2MsgHandlerEntryStrc gaChatHandlers[]; // 0x00712F4C

extern D2MsgHandlerEntryStrc gaChatInputHandlers[]; // 0x00712FA8

extern unsigned char gbChatInputOpen; // 0x007BB5E1

extern int gnLanguageId; // 0x007BB5DC

extern unsigned short gwszImeResult; // 0x007BB5F8

extern unsigned short gwszImeComposition; // 0x007BC850

extern unsigned short gwChatCount_007BB5E4; // 0x007BB5E4

extern int gaSlotFrame[]; // 0x007BC918

extern int gaSlotX[]; // 0x007BC898

extern int gaSlotY[]; // 0x007BC8B8

extern void* gpSlotCells; // 0x007BC964

extern void* gpWardenBuffer; // 0x007BC988

extern unsigned int gnWardenBufferSize; // 0x007BC98C

typedef unsigned long DWORD;

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260



extern D2MonGfxCacheStrc gaPlayerGfxCache[7]; // 0x007A7490

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern int gbPreloadForce; // 0x007A8920

int gbCharArchiveLoaded; // 0x007A8928

static void GFX_PreloadPlayerModes(int bAsync, D2UnitStrc* pUnit); // 0x00470040

struct D2GfxBoundsStrc
{
    char unk0x00[0x08];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

extern "C" void* __fastcall GFXUTIL_identity(void* pointer); // 0x004DB040

int gbHealthBarColorsInit; // 0x007A8924

unsigned char gabHealthBarColors[4]; // 0x007A890C

void __stdcall sub_0047E9A0_DrawSlots(int bDraw); // 0x0047E9A0

D2HashedFileStrc gtUnitGfxHashedFile; // 0x007A8100

D2HashedFileStrc gtGlobalHashedFile; // 0x007A78F0

int gnCofMemoryUsed; // 0x007A8918

D2MonGfxCacheStrc* gpPoolBlock; // 0x007A80FC

void __stdcall GFX_PreloadMonsterModes(int bAsync, D2UnitStrc* pUnit); // 0x0046FEB0

int gnPhase; // 0x007A8A24

unsigned int gnPhaseTotal; // 0x007A8A38

unsigned int gnPhaseLeft; // 0x007A8A3C

unsigned int gnPhaseMax; // 0x007A89C0

unsigned char gabRowTable[49][0x100]; // 0x007B5C10

int gnChatHistoryCursor; // 0x007BB5D8

#define UNIT_TYPES_COUNT 6

#define UNITFLAGEX_ISSHAPESHIFTED 0x00000008

#define LINE_ENGINE_TYPE 242

#define LINE_ENGINE_CLASS 278

#define LINE_ENGINE_MODE 260

struct D2InventoryStrc;
extern const char gszGfxFile[];                                                                    // 0x006D6C1C
extern int gnScreenWidth;                                                                               // 0x0071146C
int __cdecl GAME_GetColorFlag();                                                                                 // 0x0044DC60
int __cdecl sub_0045AE90_GetPanelSlideMode();                                                                         // 0x0045AE90
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall CUNIT_TickDrawDelay(D2UnitStrc* pUnit);                                          // 0x00464C40
D2UnitStrc* __cdecl SELECT_GetSelectedUnit();                                                             // 0x00467A10
D2MissilesTxt* __fastcall sub_0046ACE0_GetMissilesTxtRecord(int nMissileId);                                    // 0x0046ACE0
void __stdcall GFX_DrawUnitOverlays(D2UnitStrc* pUnit, unsigned int dwColor, int bFront, int nX, int nY, int bLift); // 0x0046E300
unsigned char* __cdecl DLIGHTMAP_GetLocalBloodPalette();                                                                      // 0x00477680
extern "C" int __stdcall PARTICLE_GetGfxOffsetX(D2UnitStrc* pUnit);                                     // 0x004DA0B0
int __stdcall PARTICLE_GetGfxClientY(D2UnitStrc* pUnit);                                          // 0x004DA0D0
int __stdcall PARTICLE_GetGfxClientZ(D2UnitStrc* pUnit);                                          // 0x004DA0F0
int __fastcall GFXUTIL_IsPlayerMonsterOrObject(D2UnitStrc* pUnit);                                               // 0x004DB180
int __fastcall GFXUTIL_InitUnitCelContext(D2GfxDataStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50
static int __stdcall GFX_DrawGfxUnit(unsigned int dwColor, int nArg, int bOverlay, D2UnitStrc* pUnit, int nX, int nY); // 0x00470EC0
#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))
int __fastcall GAME_GetUnitClassId(D2UnitStrc*); // 0x00451F60
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int); // 0x00451FE0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc*); // 0x004639D0
int __fastcall CUNIT_IsSelectedUnit(D2UnitStrc*); // 0x00464370
D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc*, int, int); // 0x0046FA80
unsigned char* __fastcall PALSHIFT_GetPalShift(D2UnitStrc*); // 0x00477530
int __cdecl VIEW_IsAcceleratedRenderMode(); // 0x00477750
int __fastcall GFXUTIL_GetCofLayerOverrideTransLvl(void*, int); // 0x004DB050
unsigned char* __fastcall GFXUTIL_GetLayerOrder(void*, int, int); // 0x004DB110
int __fastcall GFXUTIL_GetCofLayerNewTransLvl(void*, int); // 0x004DB140
int __fastcall GFXUTIL_GetCompTransparency(D2UnitStrc*, int, int*, int); // 0x004DB360
unsigned char* __fastcall GFXUTIL_GetBodyLocItemShift(D2UnitStrc*, int, unsigned char*); // 0x004DB570
void __fastcall sub_004DC7B0_DrawUnitByType(D2UnitStrc* pUnit, int nColor, int bForce); // 0x004DC7B0

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);
extern "C" char* __cdecl _strlwr(char* szString);
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine);
void __stdcall sub_M274_EmitBuildPath(char* szPath, int nMode);

static unsigned int GFX_HashName(const char* szName)
{
    D2_ASSERT(strlen(szName) < 8, 0x79);
    const unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nBucket = (nHash >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    return nBucket & 0x1FF;
}

static D2HashedFileEntryStrc* __stdcall GFX_LoadHashedEntry(D2HashedFileStrc* pTable, const char* szPath); // 0x0046DCC0

int __stdcall sub_M274_Emit_0046DCC0(int nMode, int nUnused)
{
    char szPath[0x110];
    sub_M274_EmitBuildPath(szPath, nMode);
    D2HashedFileStrc* const pTable = &gtGlobalHashedFile;
    if (!GFX_FindHashedEntry(pTable, szPath))
    {
        if (!GFX_LoadHashedEntry(pTable, szPath))
            return 0;
    }
    return 3;
}

static inline int UNITS_IsShapeshifted_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & UNITFLAGEX_ISSHAPESHIFTED) != 0;
    }

    return 0;
}


unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390

static inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

int* __fastcall MONSTER_GetAiValuePtr(D2UnitStrc* pUnit); // 0x004AE170

void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pTarget); // 0x004AFF60




static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

static inline unsigned int SEED_RollUnitHL_0046CE40(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline int AI_GetUnitMode_Inline(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

static void __stdcall GFX_CommandToXY(int nCommand, D2UnitStrc* pUnit, int nX, int nArg, int nY); // 0x0046CA60



static void GFX_AiType3(D2UnitStrc* pUnit); // 0x0046CE40




D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40







static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned __int64 SEED_RollFrom_Inline(D2SeedStrc* pSeed, unsigned int nLow, unsigned int nHigh)
{
    const unsigned __int64 lSeed = nHigh + 0x6AC690C5i64 * nLow;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return lSeed;
}

static inline unsigned __int64 SEED_RollFromHL_Inline(D2SeedStrc* pSeed, unsigned int nLow, unsigned int nHigh)
{
    const unsigned __int64 lSeed = nHigh + 0x6AC690C5i64 * nLow;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollRandomNumberHL_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int SEED_RollPercentage_Inline(D2SeedStrc* pSeed)
{
    return SEED_RollRandomNumber_Inline(pSeed) % 100;
}

static inline void AI_SetTimer_Inline(D2UnitStrc* pUnit, int nTicks)
{
    int* pTimer = sub_004AE110_GetAiTimer(pUnit);
    if (pTimer)
    {
        *pTimer = nTicks;
    }
}


static inline unsigned int SEED_RollUnitHL_0046C960(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollUnitLH_0046C960(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}



static void GFX_SetAiTimerClamped(D2UnitStrc* pUnit, int nTicks); // 0x0046CBD0


static int __stdcall GFX_StepAwayFromUnit(D2UnitStrc* pUnit, unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pTarget); // 0x0046C7D0

static void __stdcall GFX_StepRandom(unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pUnit); // 0x0046C960



static void sub_0046CAB0_CommandMode8(D2UnitStrc* pUnit);

static void sub_0046CB40_CommandMode7(D2UnitStrc* pUnit);

static int GFX_IsSamePosition(D2UnitStrc* pTarget, D2UnitStrc* pUnit); // 0x0046CBF0




static void __stdcall GFX_CommandOnUnit(int nCommand, int nArg, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0046C770


static void __stdcall GFX_RecalcStateOverlays(D2UnitGfxDataStrc* pOwner, D2UnitStrc* pUnit, D2UnitOverlayStrc* pNode);

void __stdcall sub_P09_Emit_0046DF40(D2UnitGfxDataStrc* pOwner, D2UnitStrc* pUnit, D2UnitOverlayStrc* pNode, D2UnitOverlayStrc* pOther)
{
    GFX_RecalcStateOverlays(pOwner, pUnit, pNode);
    GFX_RecalcStateOverlays(pOwner, pUnit, pOther);
}

static inline void GFX_ResetGfxBytes20(D2UnitStrc* pUnit); // 0x0046EA80

static inline void GFX_ResetGfxBytes16(D2UnitStrc* pUnit); // 0x0046EAA0

static inline void GFX_ResetGfxBytes8(D2UnitStrc* pUnit); // 0x0046EB50

void __fastcall sub_M113_Emit_0046EA80(D2UnitStrc* pUnit)
{
    GFX_ResetGfxBytes20(pUnit);
    GFX_ResetGfxBytes16(pUnit);
    GFX_ResetGfxBytes8(pUnit);
}

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

inline int sub_M449_IsUnitTypeInl(D2UnitStrc* pUnit, int nType)
{
    if (!pUnit)
    {
        return 0;
    }
    if (pUnit->dwUnitType != nType)
    {
        return 0;
    }
    return 1;
}

static int GFX_IsNotMonsterOrNoFlag2(D2UnitStrc* pUnit); // 0x0046F090

int __cdecl sub_M449_Emit_0046F090(D2UnitStrc* pUnit)
{
    return GFX_IsNotMonsterOrNoFlag2(pUnit) + 0x55;
}

static inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

static inline D2GfxLayerStrc* GetNodeLayer(D2UnitStrc* pUnit, int nMode)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (pGfxData)
    {
        for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode)
            {
                return pNode->pTarget->pLayer;
            }
        }
    }
    return 0;
}

static int __stdcall GFX_LoadUnitLayers(int bAsync, int nMode, D2UnitStrc* pUnit)
{
    int nResult = 1;
    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }
    int nWeaponClass;
    const int nToken = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClass, nMode, 0);
    if (!GFXUTIL_FindGfxListNode(pUnit, nToken, nMode) && !GFX_LoadUnitGfxNode(pUnit, nToken, nMode))
    {
        char szBuffer[256];
        const int nClassArg = pUnit ? pUnit->dwClassId : -1;
        const int nTypeArg = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        sprintf(szBuffer, gszAsyncLoadFailed, bAsync, nTypeArg, nClassArg, nMode, nWeaponClass, nToken);
        return 0;
    }

    D2GfxLayerStrc* pLayer = GetNodeLayer(pUnit, nMode);
    if (!pLayer)
    {
        return 0;
    }

    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pLayer);
    D2_ASSERT(pHeader, 0x6C3);
    struct
    {
        int nA;
        int nIndex;
    } tArg;
    tArg.nIndex = pHeader->nArg;
    tArg.nA = 0;
    int nDirection = UNITS_GetDirection(pUnit);
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x6CD);
    int nB;
    GFXUTIL_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &tArg.nA, &nB, tArg.nIndex, 0);
    unsigned char* pOrder = GFXUTIL_GetLayerOrder(pLayer, tArg.nA, 0);
    D2_ASSERT(pOrder, 0x6D6);
    tArg.nIndex = 0;
    while (tArg.nIndex < pHeader->nLayers)
    {
        const int nLayer = pOrder[tArg.nIndex];
        D2_ASSERT(nLayer < 0x10, 0x6DD);
        D2GfxDataStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        int nItemId;
        if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), 0, &nItemId, nLayer, nMode))
        {
            if (!D2CMPSpriteValidate(&tContext, bAsync, bAsync))
            {
                tContext.nArg34 = 0;
                if (!D2CMPSpriteRequest(&tContext))
                {
                    return -1;
                }
                if (!(tContext.dwFlags & 4))
                {
                    nResult = 0;
                }
            }
        }
        ++tArg.nIndex;
    }
    return nResult;
}

static void __stdcall GFX_PreloadMonsterMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x70A);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount || gpPoolBlock[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gpPoolBlock[nClass].aPending[nMode])
    {
        if (GFX_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gpPoolBlock[nClass].aPending[nMode] = 0;
            gpPoolBlock[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gpPoolBlock[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gpPoolBlock[nClass].nModeFlags[nMode] = 1;
    }
}

static void __stdcall GFX_PreloadPlayerMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x751);
    if (gaPlayerGfxCache[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gaPlayerGfxCache[nClass].aPending[nMode])
    {
        if (GFX_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gaPlayerGfxCache[nClass].aPending[nMode] = 0;
            gaPlayerGfxCache[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gaPlayerGfxCache[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gaPlayerGfxCache[nClass].nModeFlags[nMode] = 1;
    }
}


static void GFX_PreloadPlayerModes(int bAsync, D2UnitStrc* pUnit);

void __stdcall sub_Emit_00470040(int bAsync, D2UnitStrc* pUnit)
{
    GFX_PreloadPlayerModes(bAsync, pUnit);
}

inline int UNITS_IsFlag5SetInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 5) & 1;
}

static D2WeatherStrc* gpWeatherParticles;                                                                   // 0x007A8A04

struct D2WeatherSplashStrc;



extern int gnBaseWindAngleMax; // 0x007A899C

extern int gnBaseWindAngleMin; // 0x007A89DC

extern int gbWeatherSplash; // 0x007A8A14



typedef int (__stdcall* D2CelDrawRetFn)(D2GfxDataStrc*, int, int, unsigned int, int, unsigned char*);

static int gbLightningEnabled; // 0x007A8A08

void __cdecl sub_00472400_ResetPhaseState(); // 0x00472400

static inline void GFX_SetPhaseActive(int bValue); // 0x00472530

void __fastcall sub_M110_Emit_00472530(int bValue)
{
    GFX_SetPhaseActive(bValue - 1);
}

extern "C" double __cdecl fabs(double x);

extern D2DrlgActStrc* gpDrlgAct_007A0634;                                                                   // 0x007A0634

extern const D2PeriodLightStrc gaPeriodLights[];                                                    // 0x006D6E40

extern unsigned char gabOutdoorLightColors[];                                                             // 0x007A89EC

extern unsigned char gabPeriodLightColors[];                                                              // 0x007A898C

extern unsigned char gabParticleColorsTwilight[];                                                            // 0x007A894C

extern unsigned char gabParticleColorsDay[];                                                            // 0x007A8980

extern unsigned char gabParticleColorsNight[];                                                            // 0x007A89A4

static int gbSnowWeather;                                                                               // 0x007A8A18

extern int gnViewDeltaX;                                                                           // 0x007A0678

extern int gnViewDeltaY;                                                                           // 0x007A067C

extern unsigned int gnWeatherTick;                                                                 // 0x007A8A34

int* __fastcall MONSTER_GetAiValuePtr(D2UnitStrc* pUnit);                                                 // 0x004AE170
void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pTarget);    // 0x004AFF60
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
static D2UnitStrc* __stdcall GFX_FindNearestTarget(D2UnitStrc* pUnit, int* pDistance); // 0x0046C720





static void __stdcall GFX_AiType5(unsigned int nDistance, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0046D110



static void sub_0046CCD0_AiType1(D2UnitStrc* pUnit);

static void __stdcall sub_0046CDC0_AiType2(D2UnitStrc* pTarget, unsigned int nDistance, D2UnitStrc* pUnit);

static void __stdcall sub_0046D070_AiType4(D2UnitStrc* pTarget, D2UnitStrc* pUnit);

static void __stdcall sub_0046D280_AiType6(unsigned int nDistance, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

static void sub_0046D310_AiType7(D2UnitStrc* pUnit);

static void GFX_AiType8(D2UnitStrc* pUnit); // 0x0046D450

static void sub_0046D660_AiFlagged(D2UnitStrc* pTarget, D2UnitStrc* pUnit);


// 0x0045C470
void __fastcall GFX_ClearPendingAction(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        pUnit->pPlayerData->nState = 0;
        pUnit->pPlayerData->nMode = 0;
        pUnit->pPlayerData->nArg1 = 0;
        pUnit->pPlayerData->nArg2 = 0;
    }
}

// 0x0046C660
int __fastcall GFX_FindCorpseCallback(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc** ppTarget, int* pDistance)
{
    if (!pTarget)
        return 0;

    const int nType = pTarget->dwUnitType;
    if (nType != UNIT_PLAYER && nType != UNIT_MONSTER)
        return 0;

    const int nMode = pTarget->dwAnimMode;
    if (nType == UNIT_PLAYER)
    {
        if (nMode != PLRMODE_DEATH && nMode != PLRMODE_DEAD)
            return 0;
    }
    else
    {
        if (nMode != MONMODE_DEATH && nMode != MONMODE_DEAD)
            return 0;
    }

    const int nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);
    if (nDistance >= 3 && nDistance <= 25 && DRLG_UnitEdgeDistance(pTarget, sub_00463DD0_GetPlayerUnit()) > 7 && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
    {
        *pDistance = nDistance;
        *ppTarget = pTarget;
    }

    return 0;
}

// 0x0046C6E0
void __fastcall GFX_AddAiTargetUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc** ppSlot = gapAiTargets;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        if (!*ppSlot)
        {
            *ppSlot = pUnit;
            return;
        }
    }
}

// 0x0046C700
void __fastcall GFX_RemoveAiTargetUnit(D2UnitStrc* pUnit)
{
    D2UnitStrc** ppSlot = gapAiTargets;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        if (*ppSlot == pUnit)
        {
            *ppSlot = 0;
            return;
        }
    }
}

// 0x0046C720
static D2UnitStrc* __stdcall GFX_FindNearestTarget(D2UnitStrc* pUnit, int* pDistance)
{
    D2UnitStrc* pNearest = 0;
    D2UnitStrc** ppSlot = gapAiTargets;
    for (int i = 0; i < 8; ++i, ++ppSlot)
    {
        D2UnitStrc* pTarget = *ppSlot;
        if (pTarget && pTarget->dwAnimMode && pTarget->dwAnimMode != 12)
        {
            const int nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);
            if (nDistance < *pDistance)
            {
                pNearest = *ppSlot;
                *pDistance = nDistance;
            }
        }
    }

    return pNearest;
}

// 0x0046C770
static void __stdcall GFX_CommandOnUnit(int nCommand, int nArg, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nTargetType = 6;
    if (pTarget)
    {
        nTargetType = pTarget->dwUnitType;
    }

    D2MonCommandStrc tCommand;
    tCommand.nX = nTargetType;
    const int nTargetId = !pTarget ? -1 : pTarget->dwUnitId;
    tCommand.nY = nTargetId;
    tCommand.nZero = 0;
    tCommand.nPathValue = PATH_GetType(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = PATH_GetMaxDistance(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046C7D0
static int __stdcall GFX_StepAwayFromUnit(D2UnitStrc* pUnit, unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pTarget)
{
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    const int nTargetX = CLIENTS_GetUnitXInline(pTarget);
    const int nTargetY = CLIENTS_GetUnitYInline(pTarget);

    int nDirY = 0;
    int nDirX = 0;
    if ((unsigned int)nTargetX > (unsigned int)nUnitX)
    {
        nDirX = -1;
    }
    if ((unsigned int)nTargetX < (unsigned int)nUnitX)
    {
        nDirX = 1;
    }
    if ((unsigned int)nTargetY > (unsigned int)nUnitY)
    {
        nDirY = -1;
    }
    if ((unsigned int)nTargetY < (unsigned int)nUnitY)
    {
        nDirY = 1;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (COLLISION_CheckMaskWithSize(UNITS_GetRoom(pUnit), nDirX + nUnitX, nDirY + nUnitY, 1, PATH_GetFootprintCollisionMask(pPath)))
    {
        return 0;
    }

    D2MonCommandStrc tCommand;
    tCommand.nX = nUnitX + nScale * nDirX;
    tCommand.nY = nUnitY + nScale * nDirY;
    tCommand.nZero = 0;
    tCommand.nPathValue = PATH_GetType(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = PATH_GetMaxDistance(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
    return 1;
}

// 0x0046C960
static void __stdcall GFX_StepRandom(unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pUnit)
{
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);

    int nOffsetX = nScale;
    int nOffsetY = nScale;
    if (SEED_RollUnitHL_0046C960(pUnit) & 1)
    {
        nOffsetX = -nOffsetX;
    }

    if (SEED_RollUnitLH_0046C960(pUnit) & 1)
    {
        nOffsetY = -nOffsetY;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2MonCommandStrc tCommand;
    tCommand.nX = nUnitX + nOffsetX;
    tCommand.nY = nUnitY + nOffsetY;
    tCommand.nZero = 0;
    tCommand.nPathValue = PATH_GetType(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = PATH_GetMaxDistance(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046CA60
static void __stdcall GFX_CommandToXY(int nCommand, D2UnitStrc* pUnit, int nX, int nArg, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2MonCommandStrc tCommand;
    tCommand.nX = nX;
    tCommand.nY = nY;
    tCommand.nZero = 0;
    tCommand.nPathValue = PATH_GetType(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = PATH_GetMaxDistance(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046CAB0
static void sub_0046CAB0_CommandMode8(D2UnitStrc* pUnit)
{
    D2MonCommandStrc tCommand = {};
    tCommand.nX = CLIENTS_GetUnitXInline(pUnit);
    tCommand.nY = CLIENTS_GetUnitYInline(pUnit);
    MONSTER_HandleMonsterCommand(8, pUnit, &tCommand);
}

// 0x0046CB40
static void sub_0046CB40_CommandMode7(D2UnitStrc* pUnit)
{
    D2MonCommandStrc tCommand = {};
    tCommand.nX = CLIENTS_GetUnitXInline(pUnit);
    tCommand.nY = CLIENTS_GetUnitYInline(pUnit);
    MONSTER_HandleMonsterCommand(7, pUnit, &tCommand);
}

// 0x0046CBD0
// Kept out of line: the original calls it from 0x0046D780 with its arguments in ecx/eax, a convention only a
// static of this unit gets, so it is this unit's function; with /Ob2 it would otherwise be inlined there.
// noinline: the original calls this; without it the compiler expands it into 0x0046D780.
static __declspec(noinline) void GFX_SetAiTimerClamped(D2UnitStrc* pUnit, int nTicks)
{
    if (nTicks >= 200)
    {
        nTicks = 200;
    }

    int* pTimer = sub_004AE110_GetAiTimer(pUnit);
    if (pTimer)
    {
        *pTimer = nTicks;
    }
}

// 0x0046CBF0
static int GFX_IsSamePosition(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    const int nTargetX = CLIENTS_GetUnitXInline(pTarget);
    const int nTargetY = CLIENTS_GetUnitYInline(pTarget);
    if (nUnitX == nTargetX && nUnitY == nTargetY)
    {
        return 1;
    }

    return 0;
}

// 0x0046CCD0
static void sub_0046CCD0_AiType1(D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        D2UnitStrc* pFound = 0;
        int nDistance = 0x7FFFFFFF;
        GFXUTIL_ForEachUnitInAdjacentRooms(pUnit, &pFound, &nDistance, GFXUTIL_FindNearestUnitCallback);
        if (pFound)
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetFootprintCollisionMask(pPath, 0x3C01);
            if (nDistance < 4)
            {
                PATH_SetFootprintCollisionMask(pPath, 0xC01);
                if (!GFX_StepAwayFromUnit(pUnit, 4, 0xC, 0x78, pFound))
                {
                    GFX_StepRandom(4, 0xC, 0x78, pUnit);
                }
                return;
            }

            if (SEED_RollPercentage_Inline(&pUnit->pSeed) < 30)
            {
                GFX_StepRandom(2, 1, 0, pUnit);
                return;
            }

            AI_SetTimer_Inline(pUnit, 5);
        }
    }
}

// 0x0046CDC0
static void __stdcall sub_0046CDC0_AiType2(D2UnitStrc* pTarget, unsigned int nDistance, D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        if (nDistance < 5)
        {
            if (SEED_RollPercentage_Inline(&pUnit->pSeed) < 66)
            {
                GFX_StepAwayFromUnit(pUnit, 8, 1, 30, pTarget);
            }
            else
            {
                GFX_StepRandom(12, 1, 30, pUnit);
            }
        }
        else
        {
            GFX_StepRandom(9, 1, 0, pUnit);
        }
    }
}

// 0x0046CE40
static void GFX_AiType3(D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        int* pState = MONSTER_GetAiValuePtr(pUnit);
        if (pState)
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            const int nDistance = DRLG_UnitEdgeDistance(pUnit, pPlayer);
            if (*pState && nDistance > 25)
            {
                CUNIT_RemoveServerSideUnit(UNITS_GetUnitIdInline(pUnit), 1);
                return;
            }

            *pState = 1;

            int nOffsetY;
            int nOffsetX;
            if (SEED_RollUnitHL_0046CE40(pUnit) & 1)
            {
                nOffsetX = 40;
                nOffsetY = SEED_RollUnitHL_0046CE40(pUnit) % 40;
            }
            else
            {
                nOffsetX = SEED_RollUnitHL_0046CE40(pUnit) % 40;
                nOffsetY = 40;
            }

            if (SEED_RollUnitHL_0046CE40(pUnit) & 1)
            {
                nOffsetX = -nOffsetX;
            }

            if (SEED_RollUnitHL_0046CE40(pUnit) & 1)
            {
                nOffsetY = -nOffsetY;
            }

            int nTargetX = CLIENTS_GetUnitXInline(pPlayer);
            int nTargetY = CLIENTS_GetUnitYInline(pPlayer);
            nTargetX += nOffsetX;
            nTargetY += nOffsetY;
            const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
            const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
            PATH_SetNewDistance(pUnit->pDynamicPath, 90);
            GFX_CommandToXY(1, pUnit, 3 * nTargetX - 2 * nUnitX, 0, 3 * nTargetY - 2 * nUnitY);
        }
    }
}

// 0x0046D070
static void __stdcall sub_0046D070_AiType4(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    const int nMode = AI_GetUnitMode_Inline(pUnit);
    if (MONSTERS_IsDead(pUnit))
    {
        return;
    }

    if (GFX_IsSamePosition(pTarget, pUnit))
    {
        sub_0046CAB0_CommandMode8(pUnit);
        return;
    }

    if (nMode == 1)
    {
        if (SEED_RollPercentage_Inline(&pUnit->pSeed) < 40)
        {
            AI_SetTimer_Inline(pUnit, 20);
            sub_0046CB40_CommandMode7(pUnit);
            return;
        }

        GFX_StepRandom(4, 1, 0, pUnit);
    }
}

// 0x0046D110
static void __stdcall GFX_AiType5(unsigned int nDistance, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit)
    {
        return;
    }

    const int nMode = pUnit->dwAnimMode;
    if (nMode == 12 || nMode == 0)
    {
        return;
    }

    if (nDistance < 2 && GFX_IsSamePosition(pTarget, pUnit))
    {
        sub_0046CAB0_CommandMode8(pUnit);
        return;
    }

    if (nMode != 1)
    {
        return;
    }

    if (nDistance < 4)
    {
        GFX_StepAwayFromUnit(pUnit, 6, 1, 0, pTarget);
        return;
    }

    D2UnitStrc* pFound = 0;
    int nFoundDistance = 0;
    if (nDistance > 7)
    {
        GFXUTIL_ForEachUnitInAdjacentRooms(pUnit, &pFound, &nFoundDistance, GFX_FindCorpseCallback);
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    int* pState = MONSTER_GetAiValuePtr(pUnit);
    if (!pState)
    {
        AI_SetTimer_Inline(pUnit, 32);
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    int bDone = 0;
    if (!pFound || nDistance <= 7)
    {
        if (*pState)
        {
        Busy:
            const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (nRoll < 20)
            {
                *pState = 0;
            }

            AI_SetTimer_Inline(pUnit, 32);
            sub_0046CB40_CommandMode7(pUnit);
            bDone = 1;
        }
        else
        {
            const int nRoll = SEED_RollLimitedRandomNumber(pSeed, 100);
            if (nRoll < 75)
            {
                AI_SetTimer_Inline(pUnit, 30);
                sub_0046CB40_CommandMode7(pUnit);
                return;
            }

            GFX_StepRandom(5, 1, 0, pUnit);
            return;
        }
    }

    if (!bDone)
    {
        if (*pState)
            goto Busy;
        GFX_CommandOnUnit(0, 6, pUnit, pFound);
        *pState = 1;
    }
}

// 0x0046D280
static void __stdcall sub_0046D280_AiType6(unsigned int nDistance, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (MONSTERS_IsDead(pUnit))
    {
        return;
    }

    if (GFX_IsSamePosition(pTarget, pUnit))
    {
        sub_0046CAB0_CommandMode8(pUnit);
        return;
    }

    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        if (nDistance <= 1)
        {
            GFX_StepAwayFromUnit(pUnit, 4, 1, 0, pTarget);
            return;
        }

        const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
        if (nRoll < 75)
        {
            AI_SetTimer_Inline(pUnit, 32);
            sub_0046CB40_CommandMode7(pUnit);
            return;
        }

        GFX_StepRandom(4, 1, 0, pUnit);
    }
}

// 0x0046D310
static void sub_0046D310_AiType7(D2UnitStrc* pUnit)
{
    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        if (COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0x1C0))
        {
            sub_0046CAB0_CommandMode8(pUnit);
            return;
        }

        D2UnitStrc* pFound = 0;
        int nDistance = 0x7FFFFFFF;
        GFXUTIL_ForEachUnitInAdjacentRooms(pUnit, &pFound, &nDistance, GFXUTIL_FindNearestUnitCallback);
        if (pFound)
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetFootprintCollisionMask(pPath, 0x3C01);
            if (nDistance < 6)
            {
                PATH_SetFootprintCollisionMask(pPath, 0xC01);
                if (!GFX_StepAwayFromUnit(pUnit, 6, 1, 0x78, pFound))
                {
                    GFX_StepRandom(6, 1, 0x78, pUnit);
                }
                return;
            }

            const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100);
            if (nRoll < 30)
            {
                GFX_StepRandom(2, 1, 0, pUnit);
                return;
            }

            AI_SetTimer_Inline(pUnit, 5);
        }
    }
}

// 0x0046D450
static void GFX_AiType8(D2UnitStrc* pUnit)
{
    if (!sub_00463DE0_GetPlayerUnit())
    {
        AI_SetTimer_Inline(pUnit, 5);
        return;
    }

    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned __int64 lSeed = SEED_RollFromHL_Inline(pSeed, pSeed->nLowSeed, pSeed->nHighSeed);
    if ((int)((unsigned int)lSeed % 100) < 5)
    {
        lSeed = SEED_RollFrom_Inline(pSeed, (unsigned int)lSeed, (unsigned int)(lSeed >> 32));
        const int nMissileId = ((unsigned int)lSeed & 3) + 0x23A;
        const int nX = CLIENTS_GetUnitXInline(pUnit) + SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 60 - 30;
        const int nY = CLIENTS_GetUnitYInline(pUnit) + SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 60 - 30;
        D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, nMissileId, nX, nY, 0, 1);
        if (pMissile)
        {
            int bFlag;
            if (SEED_RollRandomNumberHL_Inline(&pUnit->pSeed) & 1)
            {
                GFXUTIL_SetMotionVectorA(pMissile, 0, 0, -100);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 6, 1);
                GFXUTIL_SetMotionVectorC(pMissile, 0, 0, 300, 1);
                bFlag = 1;
            }
            else
            {
                GFXUTIL_SetMotionVectorA(pMissile, 0, 0, 300);
                GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -6, 1);
                GFXUTIL_SetMotionVectorC(pMissile, 0, 0, -100, 1);
                bFlag = 0;
            }

            GFXUTIL_SetMotionFlagMask(pMissile, bFlag);
            GFXUTIL_UpdateMotion(pMissile);
            MISSILE_SetTotalFrames(pMissile, 60);
            MISSILE_SetCurrentFrame(pMissile, 60);
            MISSILE_SetTargetX(pMissile, 100);
            MISSILE_SetTargetY(pMissile, 300);
        }
    }
}

// 0x0046D660
static void sub_0046D660_AiFlagged(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    const int nMode = AI_GetUnitMode_Inline(pUnit);
    if (MONSTERS_IsDead(pUnit) || nMode != 1)
    {
        return;
    }

    if (!sub_0046C140_CheckMonStats2ModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
    {
        AI_SetTimer_Inline(pUnit, 20);
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    const int nRoll = SEED_RollPercentage_Inline(&pUnit->pSeed);
    if (nRoll < 40)
    {
        AI_SetTimer_Inline(pUnit, 20);
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    if (nRoll < 60 && pTarget)
    {
        GFX_CommandOnUnit(0, 6, pUnit, pTarget);
        return;
    }

    if (nRoll < 80 && pTarget)
    {
        GFX_StepAwayFromUnit(pUnit, 8, 1, 4, pTarget);
        return;
    }

    GFX_StepRandom(8, 1, 4, pUnit);
}

// 0x0046D780
void __fastcall GFX_RunClientAi(D2UnitStrc* pUnit)
{
    int* pTimer = sub_004AE110_GetAiTimer(pUnit);
    if (!pTimer)
    {
        return;
    }

    if (*pTimer > 0)
    {
        *pTimer += -1;
        return;
    }

    int nDistance = 0x7FFFFFFF;
    D2UnitStrc* pTarget = GFX_FindNearestTarget(pUnit, &nDistance);
    if (!pTarget)
    {
        pTarget = sub_00463DD0_GetPlayerUnit();
        if (!pTarget)
        {
            AI_SetTimer_Inline(pUnit, 25);
            sub_0046CB40_CommandMode7(pUnit);
            return;
        }
    }

    if (nDistance > 30)
    {
        GFX_SetAiTimerClamped(pUnit, nDistance - 15);
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    if (MONSTERUNIQUE_CheckMonStatsFlag(pUnit->dwClassId, 22))
    {
        sub_0046D660_AiFlagged(pTarget, pUnit);
        return;
    }

    switch (pUnit->dwClassId)
    {
    case 0x95:
    case 0x10C:
        sub_0046CCD0_AiType1(pUnit);
        return;

    case 0x9F:
        sub_0046CDC0_AiType2(pTarget, nDistance, pUnit);
        return;

    case 0x9D:
    case 0x9E:
    case 0x13F:
        GFX_AiType3(pUnit);
        return;

    case 0xE3:
        sub_0046D070_AiType4(pTarget, pUnit);
        return;

    case 0x97:
    case 0x10D:
    case 0x11B:
    case 0x153:
        GFX_AiType5(nDistance, pUnit, pTarget);
        return;

    case 0x13E:
        sub_0046D280_AiType6(nDistance, pUnit, pTarget);
        return;

    case 0x22C:
        sub_0046D310_AiType7(pUnit);
        return;

    case 0x23E:
        GFX_AiType8(pUnit);
        return;

    case 0x116:
    case 0x117:
    case 0x118:
    case 0x119:
    case 0x11A:
        return;

    case 0x140:
        sub_0046CB40_CommandMode7(pUnit);
        return;
    }

    sub_0046CB40_CommandMode7(pUnit);
}

// 0x0046D9C0
D2OverlayTxt* __fastcall GFX_GetTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nIndex];
    }
    return 0;
}

// 0x0046D9F0
int __fastcall GFX_GetConvertedUnitType(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
        return pUnit->dwUnitType;
    }

    if (!pUnit)
    {
        return UNIT_TYPES_COUNT;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_TYPE);
    return nType;
}

// 0x0046DA60
int __fastcall GFX_GetConvertedUnitMode(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
    lDefault:
        return UNITS_GetAnimOrSeqMode(pUnit);
    }

    if (!pUnit)
    {
        goto lDefault;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_MODE);
    return nMode;
}

// 0x0046DAC0
int __fastcall GFX_GetConvertedClassId(D2UnitStrc* pUnit)
{
    if (pUnit && !UNITS_IsShapeshifted_Inline(pUnit))
    {
        return pUnit->dwClassId;
    }

    if (!pUnit)
    {
        return -1;
    }

    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, "d:\\diablo2\\Diablo2\\Source\\D2Client/Engine.h", LINE_ENGINE_CLASS);
    return nClass;
}

// 0x0046DB30
D2InventoryStrc* __fastcall GFX_GetCompInventory(D2UnitStrc* pUnit, int* pOut)
{
    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        if (STATES_CheckStateMaskOnUnit(pUnit, 0x25))
        {
            D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
            if (pOwner)
            {
                if (pOut)
                    *pOut = 1;
                return pOwner->pInventory;
            }

            if (pOut)
                *pOut = 0;
            return pUnit->pInventory;
        }

        if (pOut)
            *pOut = 0;
        return pUnit->pInventory;
    }

    if (pOut)
        *pOut = 0;
    return pUnit->pInventory;
}

// 0x0046DBF0
static void __fastcall GFX_GetBaseName(const char* szPath, char* szDest)
{
    const int nPathLength = strlen(szPath);
    if (szPath[nPathLength - 4] == 0x2E)
    {
        const char* pExt = szPath + nPathLength - 4;
        int nLength = 0;
        while (*pExt != 0x5C)
        {
            --pExt;
            ++nLength;
        }
        --nLength;
        strncpy(szDest, pExt + 1, nLength);
        szDest[nLength] = 0;
    }
}

// 0x0046DCC0
static D2HashedFileEntryStrc* __stdcall GFX_LoadHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    char* pName = szName;
    GFX_GetBaseName(szPath, pName);
    _strlwr(pName);
    if (!GFX_FindHashedEntry(pTable, pName))
    {
        D2HashedFileEntryStrc* pEntry = (D2HashedFileEntryStrc*)FOG_Alloc(sizeof(D2HashedFileEntryStrc), ".\\ENGINE\\Gfx.cpp", 0xDC, 0);
        memset(pEntry, 0, sizeof(D2HashedFileEntryStrc));
        pEntry->nFlags |= 1;
        strcpy(pEntry->szName, szName);
        pEntry->pData = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szPath, (unsigned int*)&pEntry->nSize, ".\\ENGINE\\Gfx.cpp", 0xE0);
        if (!pEntry->pData)
        {
            return 0;
        }

        D2_ASSERT(pEntry->pData[2] <= 0x40, 0xEC);
        const unsigned int nBucket = GFX_HashName(szName);
        pEntry->pNext = pTable->pEntries[nBucket];
        pTable->pEntries[nBucket] = pEntry;
        gnCofMemoryUsed += pEntry->nSize + sizeof(D2HashedFileEntryStrc);
        return pEntry;
    }
    return 0;
}

// 0x0046DEF0
static void GFX_SyncStateOverlay(D2UnitOverlayStrc* pOverlay, D2UnitGfxDataStrc* pGfx)
{
    for (D2UnitOverlayStrc* pOther = pGfx->pOverlays; pOther; pOther = pOther->pNext)
    {
        if (pOther->nType == 8 && pOther != pOverlay)
        {
            if (pOther->nState == pOverlay->nState)
            {
                pOverlay->nActive = pOther->nActive;
                pOverlay->nCurrent = pOther->nCurrent;
                return;
            }
            if (pOther->nActive)
            {
                pOverlay->nActive = 0;
                return;
            }
        }
    }
    pOverlay->nActive = 1;
    pOverlay->nCurrent = 0;
}

// 0x0046DF40
static void __stdcall GFX_RecalcStateOverlays(D2UnitGfxDataStrc* pOwner, D2UnitStrc* pUnit, D2UnitOverlayStrc* pNode)
{
    const int nStateId = pNode->nState;
    const int bHasState = STATES_CheckState(pUnit, nStateId);
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 0);
    }
    if (!STATES_CheckStateMaskAuraOnUnit(pUnit))
    {
        pNode->nCurrent = 0;
        if (bHasState)
        {
            STATES_ToggleState(pUnit, nStateId, 1);
        }
    }
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 1);
    }

    for (D2UnitOverlayStrc* pEntry = pOwner->pOverlays; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nState == nStateId && pEntry->nType == 8)
        {
            pEntry->nActive = 0;
            pEntry->nCurrent = -1;
        }
    }

    int nNext = 0;
    int nLowest = 0;
    for (D2UnitOverlayStrc* pEntry = pOwner->pOverlays; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nType == 8)
        {
            if ((!nNext || pEntry->nState < nNext) && pEntry->nState > nStateId)
            {
                nNext = pEntry->nState;
            }
            if (!nLowest || pEntry->nState < nLowest)
            {
                nLowest = pEntry->nState;
            }
        }
    }
    if (!nNext)
    {
        nNext = nLowest;
    }

    for (D2UnitOverlayStrc* pEntry = pOwner->pOverlays; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nState == nNext && pEntry->nType == 8)
        {
            pEntry->nActive = 1;
            pEntry->nCurrent = 0;
        }
    }
}

// 0x0046E040
static void __stdcall GFX_RemoveStateOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay)
{
    D2UnitGfxDataStrc* ptGfxInfo = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(ptGfxInfo, 0x1BF);

    D2UnitOverlayStrc* pPrevious = 0;
    D2UnitOverlayStrc* pNode = ptGfxInfo->pOverlays;
AdvanceToNextNode:
    if (pNode && pNode != pOverlay)
    {
        pPrevious = pNode;
        pNode = pNode->pNext;
        goto AdvanceToNextNode;
    }

    if (!pNode)
    {
        return;
    }

    if (pNode->pResource)
    {
        DLIGHTMAP_ReleaseLight(pNode->pResource);
        pNode->pResource = 0;
    }

    if (pPrevious)
    {
        pPrevious->pNext = pNode->pNext;
    }
    else
    {
        ptGfxInfo->pOverlays = pNode->pNext;
    }

    if (pNode->nType == 8)
    {
        GFX_RecalcStateOverlays(ptGfxInfo, pUnit, pNode);
    }

    FOG_Free(pNode, gszGfxFile, 0x1E1, 0);
}

// 0x0046E100
int __fastcall GFX_HasOverlay(D2UnitStrc* pUnit, int nOverlay)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x1EA);
    for (D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays; pOverlay; pOverlay = pOverlay->pNext)
    {
        if (pOverlay->nOverlay == nOverlay)
        {
            return 1;
        }
    }
    return 0;
}

// 0x0046E1B0
void __fastcall GFX_DrawProgressiveStateOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return;
    }
    D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays;
    if (!pOverlay)
    {
        return;
    }
    for (int nPass = 0; nPass < 2; ++nPass)
    {
        for (; pOverlay; pOverlay = pOverlay->pNext)
        {
            int bDraw = 1;
            if (pOverlay->bFront && !nPass)
            {
                bDraw = 0;
            }
            if (!pOverlay->bFront && nPass)
            {
                bDraw = 0;
            }
            if (pOverlay->nType == 6 && !pOverlay->nCurrent)
            {
                bDraw = 0;
            }
            if (pOverlay->nType == 8 && !pOverlay->nActive)
            {
                bDraw = 0;
            }
            if (pOverlay->nOverlay == nOverlay && bDraw)
            {
                int nFrame = pOverlay->nFrame >> 8;
                int nId = pOverlay->nOverlay;
                if (nId < 0 || nId >= sgptDataTables->nOverlayTxtRecordCount)
                {
                    return;
                }
                D2OverlayTxt* pOverlayTxt = &sgptDataTables->pOverlayTxt[nId];
                if (!pOverlayTxt)
                {
                    return;
                }
                D2GfxDataStrc tContext;
                memset(&tContext, 0, sizeof(tContext));
                tContext.nOverlay = nOverlay;
                int nOut;
                if (!GFXUTIL_InitUnitCelContext(&tContext, 0, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, 1, -1))
                {
                    return;
                }
                if (nFrame < pOverlay->nFrames >> 8)
                {
                    sub_004F6480(&tContext, pOverlay->nXOffset + nX, pOverlay->nYOffset + nY, -0x80, pOverlayTxt->nTrans, 0);
                }
            }
        }
    }
}

// 0x0046E300
void __stdcall GFX_DrawUnitOverlays(D2UnitStrc* pUnit, unsigned int nColor, int bFront, int nX, int nY, int bLift)
{
    D2UnitGfxDataStrc* pGfx = CUNIT_GetGfxData(pUnit);
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
        switch (sub_0045AE90_GetPanelSlideMode())
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
        if (pOverlay->nType == 6 && !pOverlay->nCurrent)
        {
            bDraw = 0;
        }
        if (pOverlay->nType == 8 && !pOverlay->nActive)
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

            D2GfxDataStrc tCel;
            memset(&tCel, 0, sizeof(tCel));
            tCel.nOverlay = nOverlayId;
            if (!GFXUTIL_InitUnitCelContext(&tCel, 0, 0, UNITS_GetDirection(pUnit), nFrame, &nX, 1, -1))
            {
                return;
            }

            if (nFrame < pOverlay->nFrames >> 8)
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

// 0x0046E570
int __fastcall GFX_GetNodeValue(D2UnitStrc* pUnit, int nMode)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (pGfxData)
    {
        for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode)
            {
                return pNode->pTarget->nValue;
            }
        }
    }
    return 0;
}

// 0x0046EA80
static inline void GFX_ResetGfxBytes20(D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < 20; ++i)
    {
        GFXUTIL_SetGfxEntryByte(pUnit, i, 0);
    }
}

// 0x0046EAA0
static inline void GFX_ResetGfxBytes16(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 16; ++i)
    {
        GFXUTIL_SetGfxEntryByte(pUnit, i, 0);
    }
}

// 0x0046EAC0
static void __stdcall GFX_ResetGfxIndex(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(nIndex < GFX_INDEX_COUNT, 0x65F);
    for (int i = 0; i < GFX_INDEX_COUNT; ++i)
    {
        GFXUTIL_SetGfxEntryByte(pUnit, i, 0);
    }
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x668);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x66D, 0);
        pNode = pNext;
    }
    pGfxData->pList = 0;
}

// 0x0046EB50
static inline void GFX_ResetGfxBytes8(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 8; ++i)
    {
        GFXUTIL_SetGfxEntryByte(pUnit, i, 0);
    }
}

// 0x0046EB70
static void GFX_FreeOverlays(D2UnitGfxDataStrc* pGfxData)
{
    D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays;
    while (pOverlay)
    {
        D2UnitOverlayStrc* pNext = pOverlay->pNext;
        if (pOverlay->pResource)
        {
            DLIGHTMAP_ReleaseLight(pOverlay->pResource);
        }
        FOG_Free(pOverlay, ".\\ENGINE\\Gfx.cpp", 0x690, 0);
        pOverlay = pNext;
    }
}

// 0x0046EBB0
D2UnitGfxDataStrc* __cdecl GFX_AllocGfxData()
{
    D2UnitGfxDataStrc* pGfxData = (D2UnitGfxDataStrc*)FOG_Alloc(sizeof(D2UnitGfxDataStrc), ".\\ENGINE\\Gfx.cpp", 0x804, 0);
    D2_ASSERT(pGfxData, 0x805);
    memset(pGfxData, 0, sizeof(D2UnitGfxDataStrc));
    pGfxData->nBasePalShift = 2;
    pGfxData->nPalShift = 2;
    return pGfxData;
}

// 0x0046EC10
void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x814);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x81A, 0);
        pNode = pNext;
    }
    GFX_FreeOverlays(pGfxData);
    FOG_Free(pGfxData, ".\\ENGINE\\Gfx.cpp", 0x820, 0);
}

// 0x0046EC80
void __fastcall GFX_FreeGfxNodes(D2UnitStrc* pUnit)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x82A);
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x830, 0);
        pNode = pNext;
    }
    pGfxData->pList = 0;
}

// 0x0046ECE0
void __fastcall GFX_PruneGfxNodes(D2UnitStrc* pUnit)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x83D);
    D2GfxListNodeStrc* pPrev = 0;
    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode)
    {
        D2GfxListNodeStrc* pNext = pNode->pNext;
        if (pNode->nMode && pNode->nMode != GFX_MODE_KEEP)
        {
            FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x847, 0);
            if (!pPrev)
            {
                pGfxData->pList = pNext;
            }
            else
            {
                pPrev->pNext = pNext;
            }
        }
        else
        {
            pPrev = pNode;
        }
        pNode = pNext;
    }
}

// 0x0046ED50
static unsigned char GFX_GetHealthBarColor(D2UnitStrc* pUnit)
{
    if (!gbHealthBarColorsInit)
    {
        gabHealthBarColors[0] = D2Win_10034_MixRGB(0, 0xC0, 0);
        gabHealthBarColors[1] = D2Win_10034_MixRGB(0xE0, 0xE0, 0);
        gabHealthBarColors[2] = D2Win_10034_MixRGB(0xE0, 0, 0);
        gabHealthBarColors[3] = D2Win_10034_MixRGB(0, 0, 0xC0);
        gbHealthBarColorsInit = 1;
    }
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x991);
    if (nType != UNIT_MONSTER)
    {
        return gabHealthBarColors[0];
    }
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nClass);
    if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks_006CE268[MONSTATSFLAGINDEX_INTERACT & 7])
    {
        return gabHealthBarColors[3];
    }
    int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (!nMaxLife)
    {
        return gabHealthBarColors[0];
    }
    int nPercent = 100 * STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) / nMaxLife;
    if (nPercent < 33)
    {
        return gabHealthBarColors[2];
    }
    if (nPercent < 66)
    {
        return gabHealthBarColors[1];
    }
    return gabHealthBarColors[0];
}

// 0x0046EE80
int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != 4)
    {
        return 0;
    }
    int nSize = 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        unsigned int nGold = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
        if (nGold >= 0x64)
        {
            if (nGold < 0x1F4)
            {
                nSize = 1;
            }
            else
            {
                nSize = nGold < 0x1388 ? 2 : 3;
            }
        }
    }
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    const int bReady = GFXUTIL_InitUnitCelContext(&tContext, pItem, 0, nSize, 0, &nOut, 1, -1)
        && D2CMPSpriteValidate(&tContext, 0, 1)
        && GFXUTIL_IsCelOnScreen(tContext.pCel, nX, nY + CelGetHeight(tContext.pCel), 0);
    if (!bReady)
    {
        return 0;
    }
    unsigned char nShift;
    const int nPalette = ITEMS_GetColor(0, pItem, &nShift, 1);
    int nDrawMode = 5;
    if (ITEMS_CheckItemFlag(pItem, 0x400000, 0xAC2, ".\\ENGINE\\Gfx.cpp"))
    {
        nDrawMode = 1;
    }
    sub_004F6480(&tContext, nX, nY + CelGetHeight(tContext.pCel), -1, nDrawMode, nPalette);
    GFX_DrawUnitOverlays(pItem, 0xFF, 0, nX + ((unsigned int)CelGetWidth(tContext.pCel) >> 1), nY + ((unsigned int)CelGetHeight(tContext.pCel) >> 1), 0);
    return 1;
}

// 0x0046F000
void __fastcall GFX_ResetGfx(D2UnitStrc* pUnit)
{
    for (int i = 0; i < GFX_INDEX_COUNT; ++i)
    {
        GFX_ResetGfxIndex(pUnit, i);
    }
}

// 0x0046F020
void __fastcall GFX_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0xBBA);
    for (int i = 0; i < GFX_ENTRY_COUNT; ++i)
    {
        pGfxData->aEntries[i][0] = nValue;
    }
}

// 0x0046F060
D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (pGfxData)
        return pGfxData->pMotion;
    return 0;
}

// 0x0046F070
void __fastcall GFX_SetGfxMotionFlag(D2UnitStrc* pUnit, D2GfxMotionStrc* pMotion)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (pGfxData)
    {
        pGfxData->pMotion = pMotion;
    }
}

// 0x0046F090
static int GFX_IsNotMonsterOrNoFlag2(D2UnitStrc* pUnit)
{
    if (!sub_M449_IsUnitTypeInl(pUnit, 1))
    {
        return 1;
    }

    const int nClassId = pUnit->dwClassId;
    return !MONSTERREGION_CheckMonStats2Flag(nClassId, 2);
}

// 0x0046F170
void __fastcall GFX_RemoveOverlays(D2UnitStrc* pUnit)
{
    D2UnitGfxDataStrc* ptGfxInfo = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(ptGfxInfo, 0xCCF);
    D2UnitOverlayStrc* pOverlay = ptGfxInfo->pOverlays;
    while (pOverlay)
    {
        D2UnitOverlayStrc* pNext = pOverlay->pNext;
        GFX_RemoveStateOverlay(pUnit, pOverlay);
        pOverlay = pNext;
    }
}

// 0x0046F1C0
void __fastcall GFX_SetGfxBasePalShift(D2UnitGfxDataStrc* pGfxData, int nValue)
{
    D2_ASSERT(pGfxData, 0xCE4);
    pGfxData->nBasePalShift = nValue;
}

// 0x0046F1F0
int __fastcall GFX_GetGfxBasePalShift(D2UnitGfxDataStrc* pGfxData)
{
    D2_ASSERT(pGfxData, 0xCF1);
    return pGfxData->nBasePalShift;
}

// 0x0046F220
void __fastcall GFX_SetGfxPalShift(D2UnitGfxDataStrc* pGfxData, int nValue)
{
    D2_ASSERT(pGfxData, 0xCFD);
    pGfxData->nPalShift = nValue;
}

// 0x0046F250
int __fastcall GFX_GetGfxPalShift(D2UnitGfxDataStrc* pGfxData)
{
    D2_ASSERT(pGfxData, 0xD0A);
    return pGfxData->nPalShift;
}

// 0x0046F280
void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nIndex)
{
    if (nIndex >= GFX_INDEX_COUNT)
    {
        return;
    }
    switch (GFX_GetConvertedUnitType(pUnit))
    {
    case 0:
        for (unsigned int i = 0; i < GFX_ENTRY_COUNT; ++i)
        {
            GFXUTIL_SetGfxEntryByte(pUnit, i, 0);
        }
        break;
    case 1:
        for (int i = 0; i < GFX_INDEX_COUNT; ++i)
        {
            GFXUTIL_SetGfxEntryByte(pUnit, i, 0);
        }
        break;
    case 2:
        for (int i = 0; i < 8; ++i)
        {
            GFXUTIL_SetGfxEntryByte(pUnit, i, 0);
        }
        break;
    default:
        D2_ASSERT(0, 0xD3E);
        break;
    }
}

// 0x0046F360
void __cdecl sub_0046F360_Empty()
{
}

// 0x0046F370
static void GFX_FreeHashedEntries(D2HashedFileStrc* pTable)
{
    for (int i = 0; i < 0x200; ++i)
    {
        D2HashedFileEntryStrc* pEntry = pTable->pEntries[i];
        while (pEntry)
        {
            D2HashedFileEntryStrc* pNext = pEntry->pNext;
            if (pEntry->nFlags & 1)
            {
                unsigned char* pData = pEntry->pData;
                gnCofMemoryUsed -= pEntry->nSize + sizeof(D2HashedFileEntryStrc);
                FOG_Free(pData, ".\\ENGINE\\Gfx.cpp", 0xE3C, 0);
                FOG_Free(pEntry, ".\\ENGINE\\Gfx.cpp", 0xE3D, 0);
            }
            pEntry = pNext;
        }
    }
}

// 0x0046F3F0
void __cdecl GFX_FreeGlobalHashedFile()
{
    GFX_FreeHashedEntries(&gtUnitGfxHashedFile);
    gnCofMemoryUsed -= gtUnitGfxHashedFile.nSize;
    if (gtUnitGfxHashedFile.pData)
    {
        FOG_Free(gtUnitGfxHashedFile.pData, ".\\ENGINE\\Gfx.cpp", 0xE50, 0);
    }
    memset(&gtUnitGfxHashedFile, 0, sizeof(gtUnitGfxHashedFile));
}

// 0x0046F440
void __cdecl GFX_FreeActHashedFile()
{
    GFX_FreeHashedEntries(&gtGlobalHashedFile);
    gnCofMemoryUsed -= gtGlobalHashedFile.nSize;
    if (gtGlobalHashedFile.pData)
    {
        FOG_Free(gtGlobalHashedFile.pData, ".\\ENGINE\\Gfx.cpp", 0xE61, 0);
    }
    memset(&gtGlobalHashedFile, 0, sizeof(gtGlobalHashedFile));
}

// 0x0046F950
void __fastcall GFX_RequeuePlayerMode(D2UnitStrc* pUnit)
{
    if (!CUNIT_IsDeadOrDying(pUnit) && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        PLAYER_ApplyUnitCommand(7, pUnit, 0, 1);
}

// 0x0046F9B0
void __cdecl sub_0046F9B0_Empty()
{
}

// 0x0046F9C0
void __cdecl sub_0046F9C0_Empty()
{
}

// 0x0046F9D0
D2MonGfxCacheStrc* __fastcall GFX_GetMonGfxCache(int nMonsterId)
{
    return &gpPoolBlock[nMonsterId];
}

// 0x00470040
static void GFX_PreloadPlayerModes(int bAsync, D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < gnPlayerModeCount; ++i)
    {
        GFX_PreloadPlayerMode(bAsync, pUnit, gaPlayerModes[i]);
    }
}

// 0x00470200
void __fastcall GFX_InitGfxTables(int nValue)
{
    gdwLastPreloadTick = 0;
    gnCofMemoryLimit = nValue;
    memset(&gtUnitGfxHashedFile, 0, sizeof(gtUnitGfxHashedFile));
    memset(&gtGlobalHashedFile, 0, sizeof(gtGlobalHashedFile));
    memset(gaPlayerGfxCache, 0, sizeof(gaPlayerGfxCache));
    const int nSize = sgptDataTables->nMonStatsTxtRecordCount * sizeof(D2MonGfxCacheStrc);
    gpPoolBlock = (D2MonGfxCacheStrc*)FOG_AllocPool(0, nSize, ".\\ENGINE\\Gfx.cpp", 0x7E1, 0);
    memset(gpPoolBlock, 0, nSize);
    gbCharArchiveLoaded = D2Win_10185_CheckCharMpq();
    GFXUTIL_InitModeTokens();
}

// 0x00470290
void __cdecl GFX_FreeHashedFiles()
{
    GFX_FreeGlobalHashedFile();
    GFX_FreeActHashedFile();
    if (gpPoolBlock)
    {
        FOG_FreePool(0, gpPoolBlock, ".\\ENGINE\\Gfx.cpp", 0x7F9, 0);
        gpPoolBlock = 0;
    }
}

// 0x00470390
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nType, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8)
{
    if (nOverlay < 0 || nOverlay >= sgptDataTables->nOverlayTxtRecordCount)
        return;

    D2OverlayTxt* pTxt = &sgptDataTables->pOverlayTxt[nOverlay];
    if (!pTxt)
        return;

    if (!FOG_IsExpansion() && pTxt->wPreDraw >= 0x64)
        return;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pUnit)
    {
        if (UNIT_HasFlagEx(pUnit, 0x40000))
            return;

        if (pUnit->dwUnitType == UNIT_MONSTER && MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, 2))
            return;
    }

    if (nType == 8 && sub_0046E100(pUnit, nOverlay))
        return;

    if (nOverlay < 0x8C || nOverlay > 0x8E && nOverlay != 0x9E)
        AUTOMAP_RemoveUnitOverlay(pUnit, pTxt->nByte48, nOverlay);

    D2UnitOverlayStrc* pNew = (D2UnitOverlayStrc*)FOG_Alloc(sizeof(D2UnitOverlayStrc), ".\\ENGINE\\Gfx.cpp", 0xC48, 0);
    D2_ASSERT(pNew, 0xC49);
    memset(pNew, 0, sizeof(D2UnitOverlayStrc));
    pNew->nType = nType;
    pNew->nOverlay = nOverlay;
    pNew->nFrames = GFXUTIL_GetOverlayFrameCount(pUnit, pNew);
    switch (nType)
    {
    case 2:
        pNew->nCurrent = 1;
        break;
    case 6:
        pNew->nFrame = ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, pNew->nFrames);
        break;
    default:
        pNew->nCurrent = nArg5;
        pNew->nNextOverlay = nArg6;
        pNew->nNextState = nArg7;
        break;
    }

    pNew->nXOffset = pTxt->n54;
    pNew->nYOffset = pTxt->n58;
    switch (UNITS_GetOverlayHeight(pUnit))
    {
    case -1:
        pNew->nYOffset += 0x4B;
        break;
    case 0:
        pNew->nYOffset += pTxt->n5C;
        break;
    case 1:
        pNew->nYOffset += pTxt->n60;
        break;
    case 2:
        pNew->nYOffset += pTxt->n64;
        break;
    case 3:
        pNew->nYOffset += pTxt->n68;
        break;
    }

    if (pTxt->n74)
    {
        pNew->pLight = DLIGHTMAP_MakeLightEntry(pUnit, 1, pTxt->n70, 0xFF, pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
        if (pTxt->n74 != pTxt->n70)
            sub_00474290(pNew->pLight, pTxt->n74);
    }

    D2UnitGfxDataStrc* pGfx = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfx, 0xC7A);
    pNew->bFront = pTxt->nByte48;
    pNew->pNext = pGfx->pOverlays;
    pGfx->pOverlays = pNew;
    if (pNew->nType == 8)
    {
        pNew->nState = nArg5;
        GFX_SyncStateOverlay(pNew, pGfx);
    }

    if (nArg4)
        pNew->nFrame = ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, nArg4 << 8);

    pNew->nSpeed = pTxt->n6C << 4;
    if (nArg8)
        pNew->nSpeed += ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, nArg8 << 4);

    pNew->dwDelay = pTxt->n78;
}

// 0x004706E0
void __fastcall GFX_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nUnitType = pUnit->dwUnitType;
    int nClassId = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0xD4D);

    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    int nWeaponClassCode;
    const int nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassCode, nMode, 0);
    if (!GFXUTIL_FindGfxListNode(pUnit, nWeaponClass, -1) && !GFX_LoadUnitGfxNode(pUnit, nWeaponClass, -1))
    {
        return;
    }

    const int nGfxMode = nMode;
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return;
    }

    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode && pNode->nMode != nGfxMode)
    {
        pNode = pNode->pNext;
    }

    if (!pNode || !pNode->pFileEntry->pData)
    {
        return;
    }

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));

    int nOut;
    if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, PATH_GetDirection(pPath), pUnit->nSeqCurrentFramePrecise >> 8, &nOut, nComponent, -1) && D2CMPSpriteValidate(&tContext, 0, 1))
    {
        D2_ASSERT(tContext.pCel, 0xD7A);
        *pOffsetX = CelGetOffsetX(tContext.pCel);
        *pOffsetY = CelGetOffsetY(tContext.pCel);
    }
}

// 0x00470860
int __fastcall GFX_HitTestUnitGfx(D2UnitStrc* pUnit, int nOriginX, int nOriginY, int nX, int nY)
{
    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    int nWeaponClassCode;
    const int nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassCode, -1, 1);
    if (!GFXUTIL_FindGfxListNode(pUnit, nWeaponClass, -1))
    {
        GFX_LoadUnitGfxNode(pUnit, nWeaponClass, -1);
    }

    int nUnitType = pUnit->dwUnitType;
    int nClassId = pUnit->dwClassId;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0xD90);

    const int nGfxMode = nMode;
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return 0;
    }

    D2GfxListNodeStrc* pNode = pGfxData->pList;
    while (pNode && pNode->nMode != nGfxMode)
    {
        pNode = pNode->pNext;
    }

    if (!pNode || !pNode->pFileEntry->pData)
    {
        return 0;
    }

    D2GfxBoundsStrc* ptGfxInfo = (D2GfxBoundsStrc*)GFXUTIL_identity(pNode->pFileEntry->pData);
    D2_ASSERT(ptGfxInfo, 0xDA4);

    if (nX < ptGfxInfo->nLeft + nOriginX - 16 || nX >= ptGfxInfo->nRight + nOriginX + 16)
    {
        return 0;
    }

    if (nY < ptGfxInfo->nTop + nOriginY - 16 || nY >= ptGfxInfo->nBottom + nOriginY + 16)
    {
        return 0;
    }

    return 1;
}

// 0x00470C30
void __fastcall GFX_UpdateStateOverlays(D2UnitStrc* pUnit)
{
    D2UnitOverlayStrc* pNode;
    int nNextOverlay;
    D2UnitGfxDataStrc* pOwner = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pOwner, 0x2FE);

    const unsigned int dwTick = GetTickCount();
    int nOverlay;
    int nState;
    for (;;)
    {
        for (pNode = pOwner->pOverlays; pNode; pNode = pNode->pNext)
        {
            if (pNode->dwStamp != dwTick)
            {
                break;
            }
        }
        if (!pNode)
        {
            return;
        }

        pNode->dwStamp = dwTick;
        int bRemove = 0;
        switch (pNode->nType)
        {
        case 0:
            if (GFX_GetConvertedUnitMode(pUnit) != pNode->nCurrent)
            {
                bRemove = 1;
            }
            break;

        case 2:
            if (!pNode->nCurrent)
            {
                bRemove = 1;
            }
            break;

        case 1:
            if (!pNode->nCurrent)
            {
                bRemove = 1;
            }
            --pNode->nCurrent;
            break;

        case 6:
            if (!pNode->nCurrent)
            {
                if (GetTickCount() - pNode->dwDelayStart < pNode->dwDelay)
                {
                    continue;
                }
                pNode->nCurrent = 1;
            }
            break;

        case 8:
            if (!STATES_CheckState(pUnit, pNode->nState))
            {
                bRemove = 1;
            }
            else if (pNode->nActive)
            {
                if (pNode->nCurrent >= 50)
                {
                    GFX_RecalcStateOverlays(pOwner, pUnit, pNode);
                }
                else
                {
                    ++pNode->nCurrent;
                }
            }
            break;
        }

        if (bRemove)
        {
            GFX_RemoveStateOverlay(pUnit, pNode);
            continue;
        }

        pNode->nFrame += pNode->nSpeed;
        if (pNode->nFrame < pNode->nFrames)
        {
            continue;
        }

        switch (pNode->nType)
        {
        case 5:
            pNode->nSpeed = 0;
            pNode->nFrame = pNode->nFrames - 1;
            pNode->nCurrent = 1;
            break;

        case 2:
            pNode->nCurrent = 0;
            break;

        case 4:
            nOverlay = pNode->nCurrent;
            nNextOverlay = pNode->nNextOverlay;
            GFX_RemoveStateOverlay(pUnit, pNode);
            if (nOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nOverlay, 3, 0, 0, 0, 0, 0);
            }
            if (nNextOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nNextOverlay, 3, 0, 0, 0, 0, 0);
            }
            break;

        case 9:
            nOverlay = pNode->nCurrent;
            nNextOverlay = pNode->nNextOverlay;
            nState = pNode->nNextState;
            GFX_RemoveStateOverlay(pUnit, pNode);
            if (!STATES_CheckState(pUnit, nState))
            {
                break;
            }
            if (nOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nOverlay, 8, 0, nState, 0, 0, 0);
            }
            if (nNextOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nNextOverlay, 8, 0, nState, 0, 0, 0);
            }
            break;

        case 1:
        case 3:
        case 8:
            pNode->nFrame -= pNode->nFrames;
            break;

        case 6:
            pNode->nFrame -= pNode->nFrames;
            pNode->nCurrent = 0;
            pNode->dwDelayStart = GetTickCount();
            break;

        case 7:
            GFX_RemoveStateOverlay(pUnit, pNode);
            GFX_AddUnitOverlay(pUnit, 0x8C, 4, 0, 0x8D, 0x8E, 0, 0);
            break;
        }
    }
}

// 0x00470EC0
static int __stdcall GFX_DrawGfxUnit(unsigned int dwColor, int nArg, int bOverlay, D2UnitStrc* pUnit, int nX, int nY)
{
    int nTypeValue = UNIT_INVALID;
    if (pUnit) nTypeValue = pUnit->dwUnitType;
    int nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    int nClassId = nClassValue;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, gszGfxFile, 0x52B);
    int nDrawX = nX - PLAYER_GetScreenOffsetX();
    int nDrawY = nY - PLAYER_GetScreenOffsetY();
    int bPerspective = D2GFX_CheckPerspective();
    int nBorder = sub_0045AE90_GetPanelSlideMode();
    if (bPerspective)
    {
        switch (nBorder)
        {
        case 1: nDrawX -= gnScreenWidth / 4; break;
        case 2: nDrawX += gnScreenWidth / 4; break;
        }
    }
    int bRestoreTown = 0;
    int nTown = D2GFX_CheckUnitPerspective();
    if (nTown && bPerspective && pUnit == sub_00463DD0_GetPlayerUnit() && nUnitType == 0)
    {
        D2GFX_SetTownMode(0);
        bRestoreTown = 1;
        bPerspective = 0;
    }
    if (!GFX_IsUnitOnScreen(pUnit, nDrawX, nDrawY, 1, 0))
    {
        if (bRestoreTown) D2GFX_SetTownMode(nTown);
        return 0;
    }
    if (bOverlay) GFX_DrawUnitOverlays(pUnit, dwColor, 1, -1, -1, bRestoreTown);
    int nFrame, nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    unsigned char* pPalShift = 0;
    if (pUnit->nPaletteIndex) pPalShift = D2Win_10175_GetPL2Shift(pUnit->nPaletteIndex - 1);
    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
        pInventory = pOwner->pInventory;
    else
        pInventory = pUnit->pInventory;
    int nWeaponClass;
    int nWeaponToken = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClass, nMode, 0);
    if (!GFXUTIL_FindGfxListNode(pUnit, nWeaponToken, -1))
    {
        if (!GFX_LoadUnitGfxNode(pUnit, nWeaponToken, -1)) return 0;
    }
    void* pLayer = GetNodeLayer(pUnit, nMode);
    if (!pLayer) return 0;
    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pLayer);
    if (!pPalShift) pPalShift = PALSHIFT_GetPalShift(pUnit);
    int bTransparent = CUNIT_IsSelectedUnit(pUnit);
    int nDirection = UNITS_GetDirection(pUnit);
    int nDirectionIndex, nDirectionCount;
    GFXUTIL_GetLayerInfo(pUnit, nUnitType, nClassId, nMode, &nDirection, &nDirectionIndex, &nDirectionCount, pHeader->nArg, 1);
    unsigned char* pLayerOrder = GFXUTIL_GetLayerOrder(pLayer, nDirectionIndex, nFrame);
    D2_ASSERT(pLayerOrder, 0x58E);
    int bObjectPerspective = 0;
    if (nUnitType == UNIT_OBJECT && DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nOrderFlag[nMode] == 1)
        bObjectPerspective = 1;
    int bUseItemShift = 1;
    if (STATES_CheckStateMaskGreenOnUnit(pUnit))
    {
        if (pUnit != sub_00463DD0_GetPlayerUnit())
        {
            bUseItemShift = 0;
        }
        else if (!VIEW_IsAcceleratedRenderMode())
        {
            bUseItemShift = 0;
        }
    }
    int nItemId;
    int nDrawMode;
    for (int nIndex = 0; nIndex < pHeader->nLayers; ++nIndex)
    {
        int nComponent = pLayerOrder[nIndex];
        unsigned char* pPalette = pPalShift;
        if (nComponent == 15)
        {
            pPalette = 0;
            if (nUnitType == 1)
            {
                D2MonStats2Txt* pRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(GAME_GetUnitClassId(pUnit));
                if (pRecord && pRecord->nLocalBlood && GAME_GetColorFlag()) pPalette = DLIGHTMAP_GetLocalBloodPalette();
            }
        }
        else if (nComponent == 14)
        {
            D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
            if (pOwner && (pOwner->dwUnitType == UNIT_MISSILE || STATES_CheckState(pOwner, STATE_ATTACHED)))
                sub_004DC7B0_DrawUnitByType(pOwner, dwColor, 1);
            continue;
        }
        D2GfxDataStrc tCel;
        memset(&tCel, 0, sizeof(tCel));
        nItemId = -1;
        if (!GFXUTIL_InitUnitCelContext(&tCel, pUnit, 0, nDirection, nFrame, &nItemId, nComponent, -1)) continue;
        nDrawMode = 5;
        int bCompTrans = GFXUTIL_GetCompTransparency(pUnit, nComponent, &nDrawMode, nItemId);
        if (bUseItemShift && (nUnitType != 0 || pUnit->nPaletteIndex != 0x6C))
            pPalette = GFXUTIL_GetBodyLocItemShift(pUnit, nComponent, pPalette);
        if (GFXUTIL_GetCofLayerOverrideTransLvl(pLayer, nComponent))
        {
            if (nArg) nDrawMode = 1;
            else if (!bCompTrans) nDrawMode = GFXUTIL_GetCofLayerNewTransLvl(pLayer, nComponent);
            if (bPerspective && bObjectPerspective)
            {
                int nPrecX = UNITS_GetPrecisionX(pUnit);
                int nPrecY = UNITS_GetPrecisionY(pUnit);
                TEXTURE_CelFlatSpriteDraw(&tCel, nPrecX, nPrecY, dwColor, nDrawMode, nBorder, pPalette);
            }
            else TEXTURE_CelDraw(&tCel, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
        }
        else if (!bTransparent && !bCompTrans && !nArg)
        {
            if (bPerspective && bObjectPerspective)
            {
                int nPrecX = UNITS_GetPrecisionX(pUnit);
                int nPrecY = UNITS_GetPrecisionY(pUnit);
                TEXTURE_CelFlatSpriteDraw(&tCel, nPrecX, nPrecY, dwColor, 5, nBorder, pPalette);
            }
            else TEXTURE_CelDraw(&tCel, nDrawX, nDrawY, dwColor, 5, pPalette);
        }
        else
        {
            if (nArg) nDrawMode = 1;
            else if (!bCompTrans && bTransparent)
            {
                unsigned int nAlpha = (dwColor & 0xFF) * 2;
                nDrawMode = 7;
                nAlpha = D2_MIN(D2_MAX(nAlpha, 0x40u), 0xFFu);
                dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
            }
            TEXTURE_CelDraw(&tCel, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
        }
    }
    if (bOverlay) GFX_DrawUnitOverlays(pUnit, dwColor, 0, -1, -1, bRestoreTown);
    if (bRestoreTown) D2GFX_SetTownMode(nTown);
    return 1;
}

// 0x00471450
// noinline: GFX_DrawUnitShadow (0x00471620) calls GFX_DrawSimpleUnitShadow (0x00471450); the image calls it out of line (0x00471662), and without this the compiler expands it there.
__declspec(noinline) int __fastcall GFX_DrawSimpleUnitShadow(D2UnitStrc* pUnit)
{
    if (UNITS_IsFlag5SetInl(pUnit) || STATES_CheckState(pUnit, STATE_INVIS))
    {
        return 0;
    }

    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x86F);
    int bPerspective = sub_004F51D0_IsPerspective();
    int nOffsetX = 0;
    int nOffsetY = 0;
    if (nType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClass);
        D2_ASSERT(pObjectsTxtRecord, 0x87A);
        if (!pObjectsTxtRecord->bDraw || !pObjectsTxtRecord->nBlocksLight[nMode])
        {
            return 0;
        }
        nOffsetX = pObjectsTxtRecord->nXOffset;
        nOffsetY = pObjectsTxtRecord->nYOffset;
    }
    int nX = nOffsetX - PLAYER_GetScreenOffsetX() + UNITS_GetClientCoordX(pUnit) + GFXUTIL_GetMotionAX(pUnit);
    int nY = nOffsetY - PLAYER_GetScreenOffsetY() + UNITS_GetClientCoordY(pUnit) + GFXUTIL_GetMotionAY(pUnit);
    if (bPerspective)
    {
        switch (sub_0045AE90_GetPanelSlideMode())
        {
        case 1:
            nX += -(gnScreenWidth / 4);
            break;
        case 2:
            nX += gnScreenWidth / 4;
            break;
        }
        nY += 16;
    }
    if (!GFX_IsUnitOnScreen(pUnit, nX, nY, 0, 1))
    {
        return 0;
    }
    unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
    {
        return 0;
    }
    TEXTURE_CelDrawShadow(&tContext, nX, nY);
    return 1;
}

// 0x00471620
int __fastcall GFX_DrawUnitShadow(D2UnitStrc* pUnit)
{
    if (UNITS_IsFlag5SetInl(pUnit) || STATES_CheckState(pUnit, STATE_INVIS))
        return 0;

    if (!GFXUTIL_IsPlayerMonsterOrObject(pUnit))
    {
        GFX_DrawSimpleUnitShadow(pUnit);
        return 1;
    }

    int nWeaponClass;
    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    int nWeaponClassId;
    int nUnused;
    int nFrameCount;
    int nVisible;
    int nComponent;
    int nClass;
    int nType;
    int nDrawY;
    unsigned char* pOrder;
    int bPerspective;
    int nFrame;
    void* pGfx;
    int nDirection;
    int nMode;
    D2GfxLayerHeaderStrc* pHeader;
    int nDrawX;
    int nPrevMode;
    int bTownMode;
    int nX;
    int nY;

    bTownMode = 0;
    nPrevMode = D2GFX_CheckUnitPerspective();
    if (nPrevMode && D2GFX_CheckPerspective() && pUnit == sub_00463DD0_GetPlayerUnit() && !GFX_GetConvertedUnitType(pUnit))
    {
        D2GFX_SetTownMode(0);
        bTownMode = 1;
    }

    bPerspective = D2GFX_CheckPerspective();
    if (bPerspective)
    {
        int nHalf = GFXUTIL_GetMotionRawAZ(pUnit) / 2;
        int nPrecX = UNITS_GetPrecisionX(pUnit) - nHalf;
        int nPrecY = UNITS_GetPrecisionY(pUnit) - nHalf;
        if (!SCALE_CheckPerspectivePosition(nPrecX, nPrecY))
        {
            if (bTownMode)
                D2GFX_SetTownMode(nPrevMode);
            return 0;
        }

        SCALE_AdjustPerspectivePosition(nPrecX, nPrecY, 0, &nX, &nY);
        nX += PLAYER_GetScreenOffsetX();
        nY += PLAYER_GetScreenOffsetY() + 16;
    }
    else
    {
        int nHalf = PARTICLE_GetGfxClientZ(pUnit) / 2;
        nX = UNITS_GetClientCoordX(pUnit) + nHalf;
        nY = UNITS_GetClientCoordY(pUnit) + nHalf;
    }

    if (bTownMode)
        nY -= 8;

    nX += PARTICLE_GetGfxOffsetX(pUnit);
    nY += PARTICLE_GetGfxClientY(pUnit);

    nDrawX = nX - PLAYER_GetScreenOffsetX() - 2;
    nDrawY = nY - PLAYER_GetScreenOffsetY();
    if (pUnit && pUnit->dwUnitType == UNIT_OBJECT)
    {
        const int nObjectId = pUnit->dwClassId;
        D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nObjectId);
        nDrawX += pObjectsTxt->nXOffset;
        nDrawY += pObjectsTxt->nYOffset;
    }

    if (bPerspective)
    {
        switch (sub_0045AE90_GetPanelSlideMode())
        {
        case 1:
            nDrawX += -(gnScreenWidth_0071146C / 4);
            break;
        case 2:
            nDrawX += gnScreenWidth_0071146C / 4;
            break;
        }
    }

    if (!GFX_IsUnitOnScreen(pUnit, nDrawX, nDrawY, 0, 1))
    {
        if (bTownMode)
            D2GFX_SetTownMode(nPrevMode);
        return 0;
    }

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x926);

    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);

    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
        pInventory = pOwner->pInventory;
    else
        pInventory = pUnit->pInventory;

    nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, nMode, 0);
    if (!GFXUTIL_FindGfxListNode(pUnit, nWeaponClass, -1) && !GFX_LoadUnitGfxNode(pUnit, nWeaponClass, -1))
        return 0;

    pGfx = (void*)GFX_GetNodeValue(pUnit, nMode);
    if (!pGfx)
        return 0;

    pHeader = sub_004DB040_GetLayerHeader(pGfx);
    nDirection = UNITS_GetDirection(pUnit);
    GFXUTIL_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &nComponent, &nUnused, pHeader->nArg, 1);
    pOrder = GFXUTIL_GetLayerOrder(pGfx, nComponent, nFrame);
    D2_ASSERT(pOrder, 0x94E);

    nVisible = 0;
    if (GFXUTIL_GetComponentsMaxHeight(pUnit, pHeader, pOrder, &nVisible, nDirection, nFrame) <= 0)
    {
        if (bTownMode)
            D2GFX_SetTownMode(nPrevMode);
        return 0;
    }

    for (unsigned int i = 0; i < pHeader->nLayers; i++)
    {
        int nLayer = pOrder[i];
        D2_ASSERT(nLayer < 16, 0x960);
        if (GFXUTIL_GetCofLayerShadow(pGfx, nLayer))
        {
            D2GfxDataStrc tContext;
            int nOut;
            memset(&tContext, 0, sizeof(tContext));
            if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, nDirection, nFrame, &nOut, nLayer, -1))
                TEXTURE_CelDrawShadow(&tContext, nDrawX, nDrawY);
        }
    }

    if (bTownMode)
        D2GFX_SetTownMode(nPrevMode);
    return 1;
}

// 0x00471A30
int __fastcall GFX_GetHealthBarOffset(D2UnitStrc* pUnit)
{
    int nOffsetX = 0;
    int nOffsetY = 0;
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0x9B6);
    int bPerspective = sub_004F51D0_IsPerspective();
    if (nType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClass);
        D2_ASSERT(pObjectsTxtRecord, 0x9BE);
        if (!pObjectsTxtRecord->bDraw || !pObjectsTxtRecord->nBlocksLight[nMode])
        {
            return 0;
        }
        nOffsetY = pObjectsTxtRecord->nYOffset;
        nOffsetX = pObjectsTxtRecord->nXOffset;
    }
    int nX = nOffsetX - PLAYER_GetScreenOffsetX() + UNITS_GetClientCoordX(pUnit);
    int nY = nOffsetY - PLAYER_GetScreenOffsetY() + UNITS_GetClientCoordY(pUnit);
    if (bPerspective)
    {
        switch (sub_0045AE90_GetPanelSlideMode())
        {
        case 1:
            nX += -(gnScreenWidth / 4);
            break;
        case 2:
            nX += gnScreenWidth / 4;
            break;
        }
    }
    if (!GFX_IsUnitOnScreen(pUnit, nX, nY, 0, 0))
    {
        return 0;
    }
    unsigned char nColor = GFX_GetHealthBarColor(pUnit);
    unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
    {
        return 0;
    }
    TEXTURE_CelDrawHilight(&tContext, nX, nY, nColor);
    return 1;
}

// 0x00471BD0
int __fastcall GFX_DrawUnitHealthBar(D2UnitStrc* pUnit)
{
    int nX;
    int nY;
    int bPerspective = sub_004F51D0_IsPerspective();
    if (pUnit && pUnit->dwUnitType >= UNIT_PLAYER && pUnit->dwUnitType <= UNIT_OBJECT)
    {
        if (bPerspective)
        {
            int nZ = PARTICLE_GetGfxClientZ(pUnit);
            SCALE_AdjustPerspectivePosition(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), nZ, &nX, &nY);
            switch (sub_0045AE90_GetPanelSlideMode())
            {
            case 1:
                nX += -(gnScreenWidth / 4);
                break;
            case 2:
                nX += gnScreenWidth / 4;
                break;
            }
            nY += 0x10;
            nX += sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
            nY += PARTICLE_GetGfxClientY(pUnit);
        }
        else
        {
            nX = UNITS_GetClientCoordX(pUnit) - PLAYER_GetScreenOffsetX() + sub_004DA0B0_GetUnitGfxOffsetX(pUnit);
            nY = UNITS_GetClientCoordY(pUnit) - PLAYER_GetScreenOffsetY() + PARTICLE_GetGfxClientY(pUnit);
            nY += PARTICLE_GetGfxClientZ(pUnit);
        }
        if (!GFX_IsUnitOnScreen(pUnit, nX, nY, 0, 0))
        {
            return 0;
        }
        unsigned char nColor = GFX_GetHealthBarColor(pUnit);
        int nType = pUnit->dwUnitType;
        int nClass = pUnit->dwClassId;
        int nMode = UNITS_GetAnimOrSeqMode(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ENGINE\\Gfx.cpp", 0xA2F);
        int nDirection = UNITS_GetDirection(pUnit);
        int nFrameNo;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
        D2InventoryStrc* pInventory;
        D2UnitStrc* pOwner;
        if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
        {
            pInventory = pOwner->pInventory;
        }
        else
        {
            pInventory = pUnit->pInventory;
        }
        int nWeaponClassId;
        int nComponent = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, nMode, 0);
        if (!GFXUTIL_FindGfxListNode(pUnit, nComponent, -1) && !GFX_LoadUnitGfxNode(pUnit, nComponent, -1))
        {
            return 0;
        }
        void* pGfx = sub_0046E570_GetGfxEntry(pUnit, nMode);
        if (!pGfx)
        {
            return 0;
        }
        D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pGfx);
        int nA;
        int nB;
        GFXUTIL_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &nA, &nB, pHeader->nArg, 1);
        unsigned char* pLayers = GFXUTIL_GetLayerOrder(pGfx, nA, nFrameNo);
        D2_ASSERT(pLayers, 0xA56);
        int nVisible = 0;
        if (GFXUTIL_GetComponentsMaxHeight(pUnit, pHeader, pLayers, &nVisible, nDirection, nFrameNo) > 0)
        {
            for (unsigned int i = 0; i < pHeader->nLayers; ++i)
            {
                int nLayer = pLayers[i];
                if (GFXUTIL_UpdateUnitGfx(pUnit, nLayer))
                {
                    D2GfxDataStrc tContext;
                    memset(&tContext, 0, sizeof(tContext));
                    int nOut;
                    if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, nLayer, -1))
                    {
                        TEXTURE_CelDrawHilight(&tContext, nX, nY, nColor);
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    GFX_GetHealthBarOffset(pUnit);
    return 1;
}

// 0x00471EC0
int __fastcall GFX_DrawUnit(D2UnitStrc* pUnit, unsigned int dwColor, int nX, int nY, int nArg, int bOverlay)
{
    const int bPerspective = D2GFX_CheckPerspective();
    if (pUnit && pUnit->dwUnitType == UNIT_TILE)
    {
        return 0;
    }

    if (CUNIT_TickDrawDelay(pUnit))
    {
        GFX_DrawUnitHealthBar(pUnit);
    }

    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    int nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    int nClassId = nClassValue;
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, gszGfxFile, 0xAF0);

    int nOffsetX = 0;
    int nOffsetY = 0;
    nX += PARTICLE_GetGfxOffsetX(pUnit);
    nY += PARTICLE_GetGfxClientY(pUnit);
    nY += PARTICLE_GetGfxClientZ(pUnit);
    if (nUnitType == UNIT_OBJECT)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        D2_ASSERT(pObjectsTxtRecord, 0xAFD);
        if (!pObjectsTxtRecord->bDraw)
        {
            return 0;
        }

        nOffsetX = pObjectsTxtRecord->nXOffset;
        nOffsetY = pObjectsTxtRecord->nYOffset;
        nX += pObjectsTxtRecord->nXOffset;
        nY += pObjectsTxtRecord->nYOffset;
    }

    if (GFXUTIL_IsPlayerMonsterOrObject(pUnit))
    {
        return GFX_DrawGfxUnit(dwColor, nArg, bOverlay, pUnit, nX, nY);
    }

    const unsigned char nDirection = UNITS_GetDirection(pUnit);
    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);

    const int nPaletteShift = pUnit->nPaletteIndex;
    unsigned char* pPalShift = 0;
    if (nPaletteShift && pUnit != sub_00463DD0_GetPlayerUnit())
    {
        pPalShift = D2Win_10175_GetPL2Shift(nPaletteShift - 1);
    }

    int nCelDirection = nDirection;
    if (nUnitType == UNIT_ITEM && ITEMS_GetItemType(pUnit) == ITEMTYPE_GOLD)
    {
        const unsigned int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
        if (nGold < 100)
        {
            nCelDirection = 0;
        }
        else if (nGold < 500)
        {
            nCelDirection = 1;
        }
        else
        {
            nCelDirection = nGold < 5000 ? 2 : 3;
        }
    }

    D2GfxDataStrc tCelContext;
    memset(&tCelContext, 0, sizeof(tCelContext));
    int nCelOut;
    if (!GFXUTIL_InitUnitCelContext(&tCelContext, pUnit, 0, nCelDirection, nFrame, &nCelOut, 1, -1))
    {
        return 0;
    }

    if (!D2CMPSpriteValidate(&tCelContext, 0, 1))
    {
        return 0;
    }

    int nDrawX = nOffsetX + nX - PLAYER_GetScreenOffsetX();
    const int nDrawY = nOffsetY + nY - PLAYER_GetScreenOffsetY();
    if (bPerspective)
    {
        switch (sub_0045AE90_GetPanelSlideMode())
        {
        case 1:
            nDrawX -= gnScreenWidth / 4;
            break;
        case 2:
            nDrawX += gnScreenWidth / 4;
            break;
        }
    }

    const int bSelected = SELECT_GetSelectedUnit() == pUnit;
    if (bSelected)
    {
        unsigned int nAlpha = (dwColor & 0xFF) * 2;
        nAlpha = D2_MIN(D2_MAX(nAlpha, 0x40u), 0xFFu);

        dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
    }

    if (nUnitType == UNIT_MISSILE)
    {
        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0_GetMissilesTxtRecord(pUnit->dwClassId);
        int nDrawMode = 5;
        if (pMissilesTxtRecord->nTrans == 1)
        {
            nDrawMode = 3;
        }
        if (pMissilesTxtRecord->nTrans == 2)
        {
            nDrawMode = 4;
        }
        if (bSelected)
        {
            nDrawMode = 7;
        }

        unsigned char* pPalette;
        if (pMissilesTxtRecord->bAltPalette && GAME_GetColorFlag())
        {
            pPalette = DLIGHTMAP_GetLocalBloodPalette();
        }
        else
        {
            pPalette = pPalShift;
        }

        TEXTURE_CelDraw(&tCelContext, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
        return 1;
    }

    int nDrawMode = 5;
    if (bSelected)
    {
        nDrawMode = 7;
    }

    unsigned char* pPalette;
    {
        unsigned char nShift;
        if (nUnitType != UNIT_ITEM || (pPalette = (unsigned char*)ITEMS_GetColor(0, pUnit, &nShift, 0)) == 0)
        {
            pPalette = pPalShift;
        }
    }

    TEXTURE_CelDraw(&tCelContext, nDrawX, nDrawY, dwColor, nDrawMode, pPalette);
    if (bOverlay)
    {
        GFX_DrawUnitOverlays(pUnit, dwColor, 0, -1, -1, 0);
    }

    return 1;
}

// 0x00472530
static inline void GFX_SetPhaseActive(int bValue)
{
    gbPhaseActive = bValue;
    if (bValue)
        sub_00473D00_SetPhase(2);
}

// 0x00475B80
unsigned char* __stdcall GFX_BuildLerpTable(unsigned int nCount, int nSteps)
{
    unsigned char* pTable = (unsigned char*)sub_00517993_VirtualAlloc(nCount * nCount * nSteps + 3);
    unsigned char* pOut = pTable;
    for (int i = 0; i < nCount; ++i)
    {
        for (int j = 0; j < nCount; ++j)
        {
            int nStep = ((j - i) << 16) / nSteps;
            int nValue = i << 16;
            for (unsigned int k = 0; k < nSteps; ++k)
            {
                *pOut++ = nValue / 65536;
                nValue += nStep;
            }
        }
    }
    return pTable;
}

// 0x004795F0
D2StoredUnitRecordStrc* __stdcall GFX_SortRosterByName(D2StoredUnitRecordStrc* pList)
{
    D2StoredUnitRecordStrc* pSorted = 0;
    D2StoredUnitRecordStrc* pCurrent = pList;
    while (pCurrent)
    {
        pList = pCurrent->pNext;
        D2StoredUnitRecordStrc* pPrevious = 0;
        for (D2StoredUnitRecordStrc* pRoster = pSorted; pRoster; pRoster = pRoster->pNext)
        {
            if (strcmp(pCurrent->szName, pRoster->szName) < 0)
            {
                break;
            }
            pPrevious = pRoster;
        }
        if (pPrevious)
        {
            pCurrent->pNext = pPrevious->pNext;
            pPrevious->pNext = pCurrent;
        }
        else
        {
            pCurrent->pNext = pSorted;
            pSorted = pCurrent;
        }
        pCurrent = pList;
    }
    return pSorted;
}

// 0x00480420
void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x26);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 0x2A);
    if (PATH_GetTargetUnit(pPath))
    {
        int nUnitType;
        int nUnitGUID;
        PATH_GetTargetTypeAndGUID(pPath, &nUnitType, &nUnitGUID);
        D2UnitStrc* pTarget = CUNIT_FindClientUnit(nUnitGUID, nUnitType);
        if (pTarget != PATH_GetTargetUnit(pPath))
        {
            PATH_SetTargetUnit(pPath, 0);
        }
    }
}

extern int gaPlayerModes[8] = { 5, 6, 1, 2, 3, 7, 10, 4 }; // 0x00712AA0

extern unsigned int gnPlayerModeCount = 8; // 0x00712AC0
