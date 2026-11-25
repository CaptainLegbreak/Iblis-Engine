#include "D2LanguageNames.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
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

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int unk0x2C;
    int unk0x30;
    int n34;
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
    unsigned char unk0x7C;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
    char unk0x80[4];
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2GfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10

void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius); // 0x00474290

int __fastcall GFXUTIL_GetOverlayFrameCount(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay); // 0x004DBE20

int __stdcall UNITS_GetOverlayHeight(D2UnitStrc* pUnit); // 0x006223A0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

extern int gnScreenWidth; // 0x0071146C

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

int __cdecl sub_0045AE90(); // 0x0045AE90

int __fastcall GFX_IsUnitOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0

void __stdcall TEXTURE_CelDrawHilight(D2CelContextStrc* pContext, int nX, int nY, unsigned char nColor); // 0x004F6570

int __stdcall PARTICLE_GetGfxClientY(D2UnitStrc* pUnit); // 0x004DA0D0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0

void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80

void* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode); // 0x0046E570

D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040

void __fastcall GFXUTIL_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0

int __fastcall GFXUTIL_UpdateUnitGfx(D2UnitStrc* pUnit, int nLayer); // 0x004DB670

int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0

int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __stdcall GFX_DrawUnitOverlays(D2UnitStrc* pUnit, unsigned int nColor, int bFront, int nX, int nY, int bLift); // 0x0046E300

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __fastcall PLAYER_ApplyUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int bForce); // 0x00461250

extern D2UnitStrc* gapAiTargets[]; // 0x007A7470

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

int __stdcall GFXUTIL_GetMotionAX(D2UnitStrc* pUnit); // 0x004DA110

int __stdcall GFXUTIL_GetMotionAY(D2UnitStrc* pUnit); // 0x004DA130

void __stdcall sub_004F6540(D2CelContextStrc* pContext, int nX, int nY); // 0x004F6540

#define GFX_MODE_KEEP 0x11

struct D2MsgHandlerEntryStrc;

struct D2GfxLayerStrc;

struct D2MonGfxCacheStrc;

struct D2RosterPetStrc;

struct D2RosterUnitStrc;

struct D2MonStats2Txt;

struct D2GfxBoundsStrc;

void __stdcall GFX_RemoveStateOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay); // 0x0046E040

int __cdecl D2Win_10185_CheckCharMpq(); // 0x004FAC90

void __cdecl GFXUTIL_InitModeTokens(); // 0x004DA790

extern char gData_007A7490[0x460]; // 0x007A7490

extern int gdwLastPreloadTick; // 0x007A8910

extern int gnCofMemoryLimit; // 0x007A891C

struct D2RosterUnitStrc
{
    char szName[16];
    unsigned int dwUnitId;
    char unk0x14[0x14];
    int nXPos;
    int nYPos;
    char unk0x30[0x50];
    D2RosterUnitStrc* pNext;
};

extern "C" int __cdecl strcmp(const char* szA, const char* szB);

extern "C" HIMC__* __stdcall ImmGetContext(int hWnd); // 0x006B00C6

extern "C" int __stdcall ImmReleaseContext(int hWnd, HIMC__* hImc); // 0x006B00B4

extern "C" int __stdcall ImmGetConversionStatus(HIMC__* hImc, unsigned long* pConversion, unsigned long* pSentence); // 0x006B00DE

void* __stdcall SMemAlloc(int nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280

void __cdecl sub_00472400_ResetPhaseState(); // 0x00472400

void __fastcall sub_00473D00_SetPhase(int nPhase); // 0x00473D00

int __fastcall ROSTERPETS_IsPetFriendly(D2UnitStrc* pPlayer, D2UnitStrc* pUnit); // 0x00478E70

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

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

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790

extern D2MonGfxCacheStrc gaPlayerGfxCache[7]; // 0x007A7490

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern int gbPreloadForce; // 0x007A8920

int gbCharArchiveLoaded; // 0x007A8928

static void GFX_PreloadPlayerModes(int bAsync, D2UnitStrc* pUnit); // 0x00470040

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

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

static inline int UNITS_IsShapeshifted_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & UNITFLAGEX_ISSHAPESHIFTED) != 0;
    }

    return 0;
}

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

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

void __fastcall CUNIT_RemoveServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465F00

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

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

static void __stdcall sub_0046CA60_CommandToXY(int nCommand, D2UnitStrc* pUnit, int nX, int nArg, int nY);



static void GFX_AiType3(D2UnitStrc* pUnit); // 0x0046CE40

void __fastcall sub_E19_Emit_0046CE40(D2UnitStrc* pUnit, int nClassId)
{
    switch (nClassId)
    {
    case 0x9D:
    case 0x9E:
    case 0x13F:
        GFX_AiType3(pUnit);
        return;
    }
}

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0

int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490

D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB);// 0x004CDB40

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200

void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0

void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0

void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* pUnit);                                                // 0x004DA350

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760

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



static void sub_0046CBD0_SetAiTimerClamped(D2UnitStrc* pUnit, int nTicks);


static int __stdcall sub_0046C7D0_StepAwayFromUnit(D2UnitStrc* pUnit, unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pTarget);

static void __stdcall GFX_StepRandom(unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pUnit); // 0x0046C960



static void sub_0046CAB0_CommandMode8(D2UnitStrc* pUnit);

static void sub_0046CB40_CommandMode7(D2UnitStrc* pUnit);

static int sub_0046CBF0_IsSamePosition(D2UnitStrc* pTarget, D2UnitStrc* pUnit);




static void __stdcall GFX_CommandOnUnit(int nCommand, int nArg, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0046C770


static void __stdcall GFX_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode);

void __stdcall sub_P09_Emit_0046DF40(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode, D2StateNodeStrc* pOther)
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

inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

static inline D2GfxLayerStrc* GetNodeLayer(D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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

// build: symbol ?GFX_LoadUnitLayers@* 0x0046FB60
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
// build: symbol ?gszAsyncLoadFailed@* 0x006D6CC8
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
    unsigned char* pOrder = sub_004DB110_GetLayerOrder(pLayer, tArg.nA, 0);
    D2_ASSERT(pOrder, 0x6D6);
    tArg.nIndex = 0;
    while (tArg.nIndex < pHeader->nLayers)
    {
        const int nLayer = pOrder[tArg.nIndex];
        D2_ASSERT(nLayer < 0x10, 0x6DD);
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        int nItemId;
        if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), 0, &nItemId, nLayer, nMode))
        {
            if (!sub_006001F0(&tContext, bAsync, bAsync))
            {
                tContext.nArg34 = 0;
                if (!sub_006004E0_LoadSprite(&tContext))
                {
                    return -1;
                }
                if (!(tContext.nFlags44 & 4))
                {
                    nResult = 0;
                }
            }
        }
        ++tArg.nIndex;
    }
    return nResult;
}

// build: symbol ?GFX_PreloadMonsterMode@* 0x0046FDA0
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

// build: symbol ?GFX_PreloadPlayerMode@* 0x0046FF50
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

int __stdcall sub_M389_Emit_0046FEB0(int bAsync, D2UnitStrc* pUnit)
{
    GFX_PreloadMonsterModes(bAsync, pUnit);
    return 0x3B;
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

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

extern int gnBaseWindAngleMax; // 0x007A899C

extern int gnBaseWindAngleMin; // 0x007A89DC

extern int gbWeatherSplash; // 0x007A8A14

int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

int __stdcall SCALE_CheckPerspectivePosition(int nXPos, int nYPos); // 0x004F66E0

void __stdcall SCALE_AdjustPerspectivePosition(int nXPos, int nYPos, int nBias, int* pXAdjust, int* pYAdjust); // 0x004F6760

typedef int (__stdcall* D2CelDrawRetFn)(D2CelContextStrc*, int, int, unsigned int, int, unsigned char*);

static int gbLightningEnabled; // 0x007A8A08

static inline unsigned int sub_00472400_SeedStep(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

void __cdecl sub_00472400_ResetPhaseState(); // 0x00472400

static inline void GFX_SetPhaseActive(int bValue); // 0x00472530

void __fastcall sub_M110_Emit_00472530(int bValue)
{
    GFX_SetPhaseActive(bValue - 1);
}

extern "C" double __cdecl fabs(double x);

int __cdecl D2GFX_GetDisplayType();                                                                                 // 0x004F5140

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);                       // 0x0061C100

int __fastcall DATAARRAYS_AllocateHandle(D2WeatherStrc* pArray);                                             // 0x006BCB40

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
    sub_U01_StepSeedInline(pSeed);
    pParticle->nFrame = pSeed->nLowSeed & 0x1FF;

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

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
int* __fastcall MONSTER_GetAiValuePtr(D2UnitStrc* pUnit);                                                 // 0x004AE170
void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2MonCommandStrc* pTarget);    // 0x004AFF60
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag);                                   // 0x00457490
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB);// 0x004CDB40
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ);                    // 0x004DA1D0
void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA200
void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift);        // 0x004DA2A0
void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet);                                  // 0x004DA6E0
void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* pUnit);                                                // 0x004DA350
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY);                                      // 0x0064A760


static inline unsigned int SEED_RollRandomNumber64_Inline(D2SeedStrc* pSeed)
{
    pSeed->lSeed = (pSeed->lSeed >> 32) + 0x6AC690C5i64 * (unsigned int)pSeed->lSeed;
    return (unsigned int)pSeed->lSeed;
}

static inline int SEED_RollPercentage64_Inline(D2SeedStrc* pSeed)
{
    return SEED_RollRandomNumber64_Inline(pSeed) % 100;
}

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
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046C7D0
static int __stdcall sub_0046C7D0_StepAwayFromUnit(D2UnitStrc* pUnit, unsigned char nScale, int nCommand, int nArg, D2UnitStrc* pTarget)
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
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
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
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
    MONSTER_HandleMonsterCommand(nCommand, pUnit, &tCommand);
}

// 0x0046CA60
static void __stdcall sub_0046CA60_CommandToXY(int nCommand, D2UnitStrc* pUnit, int nX, int nArg, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2MonCommandStrc tCommand;
    tCommand.nX = nX;
    tCommand.nY = nY;
    tCommand.nZero = 0;
    tCommand.nPathValue = sub_00648E30_GetPathValue(pPath);
    tCommand.nArg = nArg;
    tCommand.nPathByte = sub_00648EA0_GetPathByte(pPath);
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
static __declspec(noinline) void sub_0046CBD0_SetAiTimerClamped(D2UnitStrc* pUnit, int nTicks)
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
static int sub_0046CBF0_IsSamePosition(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
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
        sub_0046C570_FindRoomUnit(pUnit, &pFound, &nDistance, sub_0046C600_CheckTarget);
        if (pFound)
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetFootprintCollisionMask(pPath, 0x3C01);
            if (nDistance < 4)
            {
                PATH_SetFootprintCollisionMask(pPath, 0xC01);
                if (!sub_0046C7D0_StepAwayFromUnit(pUnit, 4, 0xC, 0x78, pFound))
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
                sub_0046C7D0_StepAwayFromUnit(pUnit, 8, 1, 30, pTarget);
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
            sub_0046CA60_CommandToXY(1, pUnit, 3 * nTargetX - 2 * nUnitX, 0, 3 * nTargetY - 2 * nUnitY);
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

    if (sub_0046CBF0_IsSamePosition(pTarget, pUnit))
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

    if (nDistance < 2 && sub_0046CBF0_IsSamePosition(pTarget, pUnit))
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
        sub_0046C7D0_StepAwayFromUnit(pUnit, 6, 1, 0, pTarget);
        return;
    }

    D2UnitStrc* pFound = 0;
    int nFoundDistance = 0;
    if (nDistance > 7)
    {
        sub_0046C570_FindRoomUnit(pUnit, &pFound, &nFoundDistance, sub_0046C660_CheckTarget2);
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

    if (sub_0046CBF0_IsSamePosition(pTarget, pUnit))
    {
        sub_0046CAB0_CommandMode8(pUnit);
        return;
    }

    if (AI_GetUnitMode_Inline(pUnit) == 1)
    {
        if (nDistance <= 1)
        {
            sub_0046C7D0_StepAwayFromUnit(pUnit, 4, 1, 0, pTarget);
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
        sub_0046C570_FindRoomUnit(pUnit, &pFound, &nDistance, sub_0046C600_CheckTarget);
        if (pFound)
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetFootprintCollisionMask(pPath, 0x3C01);
            if (nDistance < 6)
            {
                PATH_SetFootprintCollisionMask(pPath, 0xC01);
                if (!sub_0046C7D0_StepAwayFromUnit(pUnit, 6, 1, 0x78, pFound))
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
        sub_0046C7D0_StepAwayFromUnit(pUnit, 8, 1, 4, pTarget);
        return;
    }

    GFX_StepRandom(8, 1, 4, pUnit);
}

// 0x0046D780
void __fastcall sub_0046D780(D2UnitStrc* pUnit)
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
        sub_0046CBD0_SetAiTimerClamped(pUnit, nDistance - 15);
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

// 0x0046DEF0
static void GFX_SyncStateOverlay(D2UnitOverlayStrc* pOverlay, D2GfxDataStrc* pGfx)
{
    for (D2UnitOverlayStrc* pOther = pGfx->pOverlays; pOther; pOther = pOther->pNext)
    {
        if (pOther->nType == 8 && pOther != pOverlay)
        {
            if (pOther->nState == pOverlay->nState)
            {
                pOverlay->nActive = pOther->nActive;
                pOverlay->n08 = pOther->n08;
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
    pOverlay->n08 = 0;
}

// 0x0046DF40
static void __stdcall GFX_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode)
{
    const int nStateId = pNode->nStateId;
    const int bHasState = STATES_CheckState(pUnit, nStateId);
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 0);
    }
    if (!sub_0063A250(pUnit))
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

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nStateId && pEntry->dwType == 8)
        {
            pEntry->bSelected = 0;
            pEntry->nCurrent = -1;
        }
    }

    int nNext = 0;
    int nLowest = 0;
    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwType == 8)
        {
            if ((!nNext || pEntry->nStateId < nNext) && pEntry->nStateId > nStateId)
            {
                nNext = pEntry->nStateId;
            }
            if (!nLowest || pEntry->nStateId < nLowest)
            {
                nLowest = pEntry->nStateId;
            }
        }
    }
    if (!nNext)
    {
        nNext = nLowest;
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nNext && pEntry->dwType == 8)
        {
            pEntry->bSelected = 1;
            pEntry->nCurrent = 0;
        }
    }
}

// 0x0046E100
int __fastcall GFX_HasOverlay(D2UnitStrc* pUnit, int nOverlay)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
            if (pOverlay->n34 && !nPass)
            {
                bDraw = 0;
            }
            if (!pOverlay->n34 && nPass)
            {
                bDraw = 0;
            }
            if (pOverlay->nType == 6 && !pOverlay->n08)
            {
                bDraw = 0;
            }
            if (pOverlay->nType == 8 && !pOverlay->nActive)
            {
                bDraw = 0;
            }
            if (pOverlay->nOverlay == nOverlay && bDraw)
            {
                int nFrame = pOverlay->n18 >> 8;
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
                D2CelContextStrc tContext;
                memset(&tContext, 0, sizeof(tContext));
                tContext.nOverlay = nOverlay;
                int nOut;
                if (!sub_004DBB50_InitCelContext(&tContext, 0, 0, UNITS_GetDirection(pUnit), nFrame, &nOut, 1, -1))
                {
                    return;
                }
                if (nFrame < pOverlay->n1C >> 8)
                {
                    sub_004F6480(&tContext, pOverlay->n20 + nX, pOverlay->n24 + nY, -0x80, pOverlayTxt->unk0x7C, 0);
                }
            }
        }
    }
}

// 0x0046E570
int __fastcall GFX_GetNodeValue(D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

// 0x0046EAA0
static inline void GFX_ResetGfxBytes16(D2UnitStrc* pUnit)
{
    for (int i = 0; i < 16; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

// 0x0046EAC0
static void __stdcall GFX_ResetGfxIndex(D2UnitStrc* pUnit, int nIndex)
{
    D2_ASSERT(nIndex < GFX_INDEX_COUNT, 0x65F);
    for (int i = 0; i < GFX_INDEX_COUNT; ++i)
    {
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
        sub_004DB1C0_SetGfxByte(pUnit, i, 0);
    }
}

// 0x0046EB70
static void GFX_FreeOverlays(D2GfxDataStrc* pGfxData)
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
D2GfxDataStrc* __cdecl GFX_AllocGfxData()
{
    D2GfxDataStrc* pGfxData = (D2GfxDataStrc*)FOG_Alloc(sizeof(D2GfxDataStrc), ".\\ENGINE\\Gfx.cpp", 0x804, 0);
    D2_ASSERT(pGfxData, 0x805);
    memset(pGfxData, 0, sizeof(D2GfxDataStrc));
    pGfxData->nBasePalShift = 2;
    pGfxData->nPalShift = 2;
    return pGfxData;
}

// 0x0046EC10
void __fastcall GFX_FreeGfxData(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    const int bReady = GFXUTIL_InitUnitCelContext(&tContext, pItem, 0, nSize, 0, &nOut, 1, -1)
        && sub_006001F0(&tContext, 0, 1)
        && sub_004DAB40_CheckCel(tContext.pCel, nX, nY + CelGetHeight(tContext.pCel), 0);
    if (!bReady)
    {
        return 0;
    }
    unsigned char nShift;
    const int nPalette = sub_0062C100(0, pItem, &nShift, 1);
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
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0xBBA);
    for (int i = 0; i < GFX_ENTRY_COUNT; ++i)
    {
        pGfxData->aEntries[i][0] = nValue;
    }
}

// 0x0046F060
D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (pGfxData)
        return pGfxData->pMotion;
    return 0;
}

// 0x0046F070
void __fastcall GFX_SetGfxMotionFlag(D2UnitStrc* pUnit, D2GfxMotionStrc* pMotion)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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
    D2GfxDataStrc* ptGfxInfo = CUNIT_GetGfxData(pUnit);
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
void __fastcall GFX_SetGfxBasePalShift(D2GfxDataStrc* pGfxData, int nValue)
{
    D2_ASSERT(pGfxData, 0xCE4);
    pGfxData->nBasePalShift = nValue;
}

// 0x0046F1F0
int __fastcall GFX_GetGfxBasePalShift(D2GfxDataStrc* pGfxData)
{
    D2_ASSERT(pGfxData, 0xCF1);
    return pGfxData->nBasePalShift;
}

// 0x0046F220
void __fastcall GFX_SetGfxPalShift(D2GfxDataStrc* pGfxData, int nValue)
{
    D2_ASSERT(pGfxData, 0xCFD);
    pGfxData->nPalShift = nValue;
}

// 0x0046F250
int __fastcall GFX_GetGfxPalShift(D2GfxDataStrc* pGfxData)
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
    switch (sub_0046D9F0_TestUnit(pUnit))
    {
    case 0:
        for (unsigned int i = 0; i < GFX_ENTRY_COUNT; ++i)
        {
            sub_004DB1C0_SetGfxByte(pUnit, i, 0);
        }
        break;
    case 1:
        for (int i = 0; i < GFX_INDEX_COUNT; ++i)
        {
            sub_004DB1C0_SetGfxByte(pUnit, i, 0);
        }
        break;
    case 2:
        for (int i = 0; i < 8; ++i)
        {
            sub_004DB1C0_SetGfxByte(pUnit, i, 0);
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
// build: symbol ?gnPlayerModeCount@* 0x00712AC0
    for (unsigned int i = 0; i < gnPlayerModeCount; ++i)
    {
// build: symbol ?gaPlayerModes@* 0x00712AA0
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
    memset(gData_007A7490, 0, sizeof(gData_007A7490));
    const int nSize = sgptDataTables->nMonStatsTxtRecordCount * sizeof(D2MonGfxCacheStrc);
    gpPoolBlock = (D2MonGfxCacheStrc*)sub_0040B430(0, nSize, ".\\ENGINE\\Gfx.cpp", 0x7E1, 0);
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

// build: symbol ?FOG_IsExpansion@* 0x00408F20
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
    pNew->n1C = GFXUTIL_GetOverlayFrameCount(pUnit, pNew);
    switch (nType)
    {
    case 2:
        pNew->n08 = 1;
        break;
    case 6:
        pNew->n18 = ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, pNew->n1C);
        break;
    default:
        pNew->n08 = nArg5;
        pNew->n0C = nArg6;
        pNew->n10 = nArg7;
        break;
    }

    pNew->n20 = pTxt->n54;
    pNew->n24 = pTxt->n58;
    switch (UNITS_GetOverlayHeight(pUnit))
    {
    case -1:
        pNew->n24 += 0x4B;
        break;
    case 0:
        pNew->n24 += pTxt->n5C;
        break;
    case 1:
        pNew->n24 += pTxt->n60;
        break;
    case 2:
        pNew->n24 += pTxt->n64;
        break;
    case 3:
        pNew->n24 += pTxt->n68;
        break;
    }

    if (pTxt->n74)
    {
        pNew->pLight = DLIGHTMAP_MakeLightEntry(pUnit, 1, pTxt->n70, 0xFF, pTxt->nRed, pTxt->nGreen, pTxt->nBlue);
        if (pTxt->n74 != pTxt->n70)
            sub_00474290(pNew->pLight, pTxt->n74);
    }

    D2GfxDataStrc* pGfx = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfx, 0xC7A);
    pNew->n34 = pTxt->nByte48;
    pNew->pNext = pGfx->pOverlays;
    pGfx->pOverlays = pNew;
    if (pNew->nType == 8)
    {
        pNew->nState = nArg5;
        GFX_SyncStateOverlay(pNew, pGfx);
    }

    if (nArg4)
        pNew->n18 = ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, nArg4 << 8);

    pNew->n14 = pTxt->n6C << 4;
    if (nArg8)
        pNew->n14 += ITEMS_RollLimitedRandomNumber(&pPlayer->pSeed, nArg8 << 4);

    pNew->n28 = pTxt->n78;
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
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));

    int nOut;
    if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, PATH_GetDirection(pPath), pUnit->nSeqCurrentFramePrecise >> 8, &nOut, nComponent, -1) && sub_006001F0(&tContext, 0, 1))
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
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
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

// 0x00471450
int __fastcall GFX_DrawSimpleUnitShadow(D2UnitStrc* pUnit)
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
        switch (sub_0045AE90())
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
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
    {
        return 0;
    }
    sub_004F6540(&tContext, nX, nY);
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
        switch (sub_0045AE90())
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
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    if (!sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, 1, -1))
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
            int nZ = sub_004DA0F0_GetUnitGfxOffsetZ(pUnit);
            sub_004F6760_PrecisionToScreen(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), nZ, &nX, &nY);
            switch (sub_0045AE90())
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
            nY += sub_004DA0F0_GetUnitGfxOffsetZ(pUnit);
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
        unsigned char* pLayers = sub_004DB110_GetLayerOrder(pGfx, nA, nFrameNo);
        D2_ASSERT(pLayers, 0xA56);
        int nVisible = 0;
        if (sub_004DBD30_CountVisibleLayers(pUnit, pHeader, pLayers, &nVisible, nDirection, nFrameNo) > 0)
        {
            for (unsigned int i = 0; i < pHeader->nLayers; ++i)
            {
                int nLayer = pLayers[i];
                if (GFXUTIL_UpdateUnitGfx(pUnit, nLayer))
                {
                    D2CelContextStrc tContext;
                    memset(&tContext, 0, sizeof(tContext));
                    int nOut;
                    if (sub_004DBB50_InitCelContext(&tContext, pUnit, 0, nDirection, nFrameNo, &nOut, nLayer, -1))
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
D2RosterUnitStrc* __stdcall GFX_SortRosterByName(D2RosterUnitStrc* pList)
{
    D2RosterUnitStrc* pSorted = 0;
    D2RosterUnitStrc* pCurrent = pList;
    while (pCurrent)
    {
        pList = pCurrent->pNext;
        D2RosterUnitStrc* pPrevious = 0;
        for (D2RosterUnitStrc* pRoster = pSorted; pRoster; pRoster = pRoster->pNext)
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

#include "gen/data/Source/D2Client/ENGINE/Gfx.inc"
