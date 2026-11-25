#include "D2MissileIds.h"
#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2ClientTypes.h"
#include "D2Drlg.h"
#include "D2ItemsWorld.h"
#include "D2ClientGame.h"
#include "D2CelContext.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2ClientSound.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2QuestLookupEntry.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientListNodeStrc;

struct D2StaticPathStrc;

struct D2MapAIStrc;

struct D2ClientListLinkStrc;

struct D2PlayerDataStrc;

struct D2ClientRecordStrc;

struct D2ClientEntryStrc;

struct D2ClientTimedBoxStrc;

struct D2ClientViewStrc;

struct D2PalShiftEntryStrc;

struct D2DrlgCoordsStrc;

struct D2MissileStrc;

struct D2RosterPetStrc;

struct D2TimedHintNodeStrc;

struct D2PalShiftNodeStrc;

union D2SeedStrc;

struct D2CelContextStrc;

struct D2DataTablesStrc;

struct D2UnitStrc;

struct D2ActiveRoomStrc;

struct D2PresetUnitStrc;

struct D2ViewStrc;

struct D2ClientListLinkStrc
{
    D2ClientListLinkStrc* pPrevLink;
    D2ClientListNodeStrc* pNext;
};

struct D2ClientListNodeStrc : D2ClientListLinkStrc
{
    int nData;
};

struct D2ClientRecordStrc
{
    int unk0x00[3];
    int nKey;
};

struct D2ClientViewStrc
{
    unsigned int dwFlags;
    union
    {
        struct
        {
            tagRECT tViewRect;
        };
        struct
        {
            int nValue04;
            int nValue08;
            int nValue0C;
            int nValue10;
        };
    };
    tagRECT tClipRect;
    int nPosX;
    int nPosY;
};

struct D2PalShiftEntryStrc
{
    int nId;
    int nValue;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

D2ClientEntryStrc* __fastcall ROSTERPETS_FindEntry(int nKey); // 0x00478E40

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall MSG_SendTwoWords(char nHeader, short nArg1, short nArg2); // 0x004785D0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __cdecl GAME_GetAlwaysRun(); // 0x0044BE90

void __cdecl sub_00497300(); // 0x00497300

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __cdecl HIREABLES_GetHelpMenuSetting(); // 0x004942D0

void __cdecl HIREABLES_DrawKeyHelp(); // 0x00495030

extern void* gpGlobal_00798FB4; // 0x00798FB4

extern void* gpOkCancelButtonCel; // 0x007A5240

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern D2ClientTimedBoxStrc gtTimedBox; // 0x007A742C

extern void* gpGlobal_007BC964; // 0x007BC964

extern void* gpHelpBorderCel; // 0x007BEEEC

extern int gbRunButtonDown; // 0x007BEFD8

extern void* gpLevelCel; // 0x007C02DC

extern void* gpLevelSocketCel; // 0x007C02E0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2PalShiftEntryStrc* gpPalShiftEntries; // 0x007B9578

extern int gnGlobal_007B957C; // 0x007B957C

extern void* gpHelpWhiteBulletCel; // 0x007BEEF0

extern int gnScreenWidth; // 0x0071146C

enum D2C_W10Constants
{
    STAT_HITPOINTS = 6,
    PET_TYPE_LIFE = 7,
    DRAW_MODE_5 = 5,
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern int gnAutomapOriginX; // 0x007A520C

extern int gnAutomapOriginY; // 0x007A5208

extern D2TimedHintNodeStrc* gpClientSoundList; // 0x007C5458

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730

D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall ITEM_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

void __stdcall DUNGEON_ClientSubileDrawPositionToGameCoords(int nX, int nY, int* pX, int* pY); // 0x00643400

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

struct D2ViewStrc
{
    unsigned int dwFlags;
    tagRECT tRect;
    unsigned char unk_14[0x10];
    int nPosX;
    int nPosY;
    void* pLerpData;
    void* pLerpTable;
    void* pLerpRows;
    unsigned int dwDrawFlags;
};

struct D2PalShiftNodeStrc
{
    int nId;
    char unk0x04[0x1000];
    D2PalShiftNodeStrc* pNext;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __cdecl VIEW_FreeCels(); // 0x00475EB0

void __fastcall WALL2_FreeViewCells(D2ViewStrc* pView); // 0x004DCF30

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall WALL2_PrepareWallCells(D2ViewStrc* pView, int nValue); // 0x004DDB70

extern "C" void __cdecl D2CMPResetTileCacheHits(); // 0x005FE060

extern "C" int gnLightmapRenderMode; // 0x00712CCC

int ghShakeSound; // 0x007B8D2C

static int gnViewEffectMagnitude;                                                                               // 0x007B9534

unsigned char** gppLerpRows;        // 0x007B953C

extern int gbCacheStatsChecked; // 0x007BB3AC

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

extern D2CelFileStrc* sghPentagram; // 0x0087E96C

extern unsigned char gabBeltHotkey[]; // 0x007BEFB0

extern int gnBeltHover; // 0x007BEF94

extern D2UnitStrc* gpBeltItemA; // 0x007BEFA8

static int gnPetIconPopupState; // 0x007BEECC

extern unsigned char gnTextColorRed; // 0x007BEFBA

extern unsigned char gabBeltColors[4]; // 0x007BEF6C

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gbHoverInGrid; // 0x007BCBE4

extern int gbHoverInBodyLoc; // 0x007BCBE8

extern int gnInvPanelMode; // 0x007BCBF0

extern D2UnitStrc* gpHoverItem; // 0x007BCBF4

extern int gpLastHoverItem; // 0x007BCBF8

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall sub_004B9B20(int nHandle); // 0x004B9B20

void __fastcall SOUNDINST_SetValue(int nKey, int nValue); // 0x004B9B50

void __fastcall sub_004BA840(int nHandle); // 0x004BA840

int gdwViewEffectStartTick; // 0x007B8D10

static int gnViewEffectFadeIn;                                                                               // 0x007B8D14

static int gnViewEffectHold;                                                                               // 0x007B8D18

static int gnViewEffectFadeOut;                                                                               // 0x007B8D1C

static int gnViewShiftY; // 0x007B8D20

static int gnViewShiftX; // 0x007B9538

extern D2SeedStrc* gpClientSeed; // 0x00712C4C

extern int gnStarFieldHeight_007A521C; // 0x007A521C

extern int gnStarFieldWidth_007A5220; // 0x007A5220

unsigned char gaStarShades[8]; // 0x007B8D24

int gaStarX[256]; // 0x007B8D30

int gaStarY[256]; // 0x007B57E8

unsigned char gaStarColor[256]; // 0x007B5688

int gaStarSpeed[256]; // 0x007B9130

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

static void VIEW_UpdateShakeSound(int nIntensity); // 0x004769D0

int gnGlobal_007BEF04; // 0x007BEF04

int gbHelpButtonVisible; // 0x007BEF08

#define STARS_ROLL(pSeed, lSeed) ((lSeed) = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
    (pSeed)->nHighSeed = (unsigned int)((lSeed) >> 32), (pSeed)->nLowSeed = (unsigned int)(lSeed), (unsigned int)(lSeed))

struct D2QuestLookupEntryStrc;

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

int __fastcall SEED_GetRandomValue(int nValue); // 0x00650DE0

void __stdcall VIEW_ResetStar(int nStar, int bRespawn); // 0x00476190

extern D2QuestLookupEntryStrc gaQuestLookup_00723F38[0x29]; // 0x00723F38

int gbStarsInit; // 0x007B955C

unsigned long gdwStarTick; // 0x007B57E0

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType);                               // 0x004788B0

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

extern int gbLeavingGame;                                                                               // 0x007A0620

extern int gnAutomapWidth;                                                                          // 0x007A5220

extern D2SeedStrc* gpSkySeed;                                                                       // 0x00712C50

static int gnSummitScroll;                                                                          // 0x007B9568

static D2CelFileStrc* gpSummitCel;                                                                  // 0x007B9554

static D2CelFileStrc* gpCloudCel;                                                                   // 0x007B9558

static bool gbCloudsInit;                                                                           // 0x007B9560

static int gaCloudY[10];                                                                            // 0x007B5790

static int gaCloudSpeed[10];                                                                        // 0x007B57B8

static int gaCloudX[10];                                                                            // 0x007B5BE8

static int snBaseX; // 0x007B9570

static bool sbBaseSet; // 0x007B956C

static int gnBaseGuard; // 0x007B9574

static void VIEW_DrawSummitBackdrop(D2UnitStrc* pPlayer); // 0x00476460

struct Obj004DCF10
{
    unsigned int flags;
    tagRECT rect;
    unsigned char beforeRows[0x18];
    void* rows;
    void* data;
    void* table;
    unsigned char unusedTail[0xEABC - 0x38];
};

typedef char Obj004DCF10Size[(sizeof(Obj004DCF10) == 0xEABC) ? 1 : -1];

#define SYN_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_004DDDF0(void* rows, void* data); // 0x004DDDF0

extern "C" void __fastcall WALL2_ResetViewCells(Obj004DCF10*); // 0x004DCF10

int gdwLightTick;        // 0x007B9530

struct D2TileLightCtxStrc;

struct D2CellGridViewStrc
{
    void __thiscall sub_004DF510_DrawCellNodes();                                                            // 0x004DF510
};

int __stdcall D2GFX_CheckPerspective();                                                                      // 0x004F51D0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                        // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                        // 0x00620410

int __cdecl sub_0044DB00();                                                                                  // 0x0044DB00

void __cdecl WALL2_UpdateRoomColor();                                                                 // 0x004DED20

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                           // 0x0061A1B0

void __cdecl VIEW_DrawStarfield();                                                                   // 0x00476290

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel);                                                                    // 0x00478A00

void __fastcall sub_004DF480_UpdateAllTileLights(D2TileLightCtxStrc* pCtx);                                  // 0x004DF480

void __fastcall sub_004DED10(void* pArg);                                                                    // 0x004DED10

void __cdecl sub_00473C00_DrawWeatherLayers();                                                               // 0x00473C00

void __fastcall sub_004DF1C0(D2ViewStrc* pView);                                                             // 0x004DF1C0

void __fastcall DFLOOR_UpdateFloorView(D2ViewStrc* pView);                                                             // 0x004DEA70

void __cdecl DLIGHTMAP_DebugDrawLights();                                                                 // 0x00475B20

void __cdecl sub_00473910_UpdateWeather();                                                                                 // 0x00473910

void __cdecl GFXUTIL_DrawFadeBox();                                                                     // 0x004DC000

extern const unsigned int gdwBitMasks[32];                                                                   // 0x006CE268

void __cdecl sub_00473910();

static D2RosterPetStrc* gpRosterPets; // 0x007BB5BC

void* gpLerpTable16; // 0x007B9540

void* gpLerpTable32; // 0x007B9544

void* gppRampTable; // 0x007B954C

void* gpLerpTable40; // 0x007B9550

D2PalShiftNodeStrc* gpPalShiftList; // 0x007B957C

int gbCacheStats; // 0x007BB3A4

int gpBeltItemB; // 0x007BEFAC

unsigned char gnLifeColorHigh; // 0x007BEED0

unsigned char gnLifeColorMid; // 0x007BEED1

unsigned char gnLifeColorLow; // 0x007BEED2

unsigned char gbLifeColorsInit; // 0x007BEED3

int gbDebugDrawLights; // 0x007B9564

void __fastcall VIEW_PrepareSceneLighting(D2ViewStrc* pView); // 0x00476BC0

static int gnPopupX; // 0x007BEED4

void __fastcall VIEW_AdjustViewPos(int* pX, int* pY); // 0x00476D40

void* gpCel_007B9554;                                                                                       // 0x007B9554
void* gpCel_007B9558;                                                                                       // 0x007B9558

static inline D2ClientListLinkStrc* ListNextLink(D2ClientListLinkStrc* pLink, int nLinkOffset)
{
    int nOffset = (int)pLink->pNext;
    if (nOffset < 0)
        return (D2ClientListLinkStrc*)~nOffset;
    if (nLinkOffset < 0)
        nLinkOffset = (int)pLink - (int)pLink->pPrevLink->pNext;
    return (D2ClientListLinkStrc*)(nOffset + nLinkOffset);
}

// 0x00466820
void __fastcall VIEW_SpawnRoomPresets(D2ActiveRoomStrc* pRoom)
{
    for (D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom); pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->bSpawned & 1)
        {
            D2DrlgCoordsStrc tCoords;
            DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
            CUNIT_SpawnPresetUnit(pPresetUnit->nIndex, pPresetUnit->nXpos + tCoords.nSubtileX, pPresetUnit->nYpos + tCoords.nSubtileY, pPresetUnit->nUnitType, pPresetUnit->nMode);
        }
    }
}

// 0x00467410
void __fastcall VIEW_SetPetEntryValue(void* pOwner, D2ClientRecordStrc* pRecord, int nValue)
{
    if (pOwner && pRecord)
    {
        ROSTERPETS_FindEntry(pRecord->nKey)->nValue = nValue;
    }
}

typedef void (__cdecl* LEVELEVENT_Fn)();

extern LEVELEVENT_Fn gpfnLevelEvents[];                                                            // 0x007129D8

unsigned int gdwLevelEventBits;                                                                    // 0x007A7458

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    default:
        if (pUnit->pDynamicPath) nResult = PATH_GetXPosition(pUnit->pDynamicPath); else nResult = 0;
        break;
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nXPos;
        break;
    }
    return nResult;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    default:
        if (pUnit->pDynamicPath) nResult = PATH_GetYPosition(pUnit->pDynamicPath); else nResult = 0;
        break;
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    }
    return nResult;
}

void __fastcall D2Win_10178_CopyGammaTable(unsigned char (*pRows)[0x100]); // 0x004FB1C0

unsigned char* __stdcall GFX_BuildLerpTable(unsigned int nCount, int nSteps); // 0x00475B80

unsigned char** __stdcall GFX_BuildLerpRowTable(unsigned int nCount, int nSteps); // 0x00475C40

unsigned char** __stdcall SCMD_BuildRampTable(unsigned int nSize, int nSteps); // 0x00475D30

extern unsigned char gabRowTable[][0x100]; // 0x007B5C10

extern unsigned char** gppRampTable_007B954C; // 0x007B954C

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

// 0x00475C30
void __fastcall VIEW_FreeIfSet(void* pMemory)
{
    if (pMemory)
    {
        sub_005179A4_VirtualFree(pMemory);
    }
}

// 0x00475DF0
void __cdecl DLIGHTMAP_BuildLerpTables()
{
    D2_ASSERT(!gppLerpRows, 0xCA);
    D2_ASSERT(!gpLerpTable16, 0xCB);
    D2_ASSERT(!gpLerpTable32, 0xCC);
    D2_ASSERT(!gppRampTable_007B954C, 0xCD);
    D2_ASSERT(!gpLerpTable40, 0xCE);
    D2Win_10178_CopyGammaTable(gabRowTable);
    gppLerpRows = GFX_BuildLerpRowTable(0x20, 8);
    gpLerpTable16 = GFX_BuildLerpTable(0x20, 0x10);
    gpLerpTable32 = GFX_BuildLerpTable(0x20, 0x20);
    gppRampTable_007B954C = SCMD_BuildRampTable(0x20, 0x20);
    gpLerpTable40 = GFX_BuildLerpTable(0x20, 0x28);
}

// 0x00475EB0
void __cdecl VIEW_FreeCels()
{
    if (gpCel_007B9554)
    {
        ARCHIVE_FreeClientCellFile(gpCel_007B9554);
        gpCel_007B9554 = 0;
    }
    if (gpCel_007B9558)
    {
        ARCHIVE_FreeClientCellFile(gpCel_007B9558);
        gpCel_007B9558 = 0;
    }
}

// 0x00475EF0
void __cdecl VIEW_FreeLerpTables()
{
    if (!gppLerpRows)
        return;

    D2_ASSERT(gpLerpTable16, 0xFB);
    D2_ASSERT(gpLerpTable32, 0xFC);
    D2_ASSERT(gppRampTable, 0xFD);
    D2_ASSERT(gpLerpTable40, 0xFE);
    sub_005179A4_VirtualFree(gppLerpRows);
    if (gpLerpTable16)
        sub_005179A4_VirtualFree(gpLerpTable16);
    if (gpLerpTable32)
        sub_005179A4_VirtualFree(gpLerpTable32);
    if (gppRampTable)
        sub_005179A4_VirtualFree(gppRampTable);
    if (gpLerpTable40)
        sub_005179A4_VirtualFree(gpLerpTable40);
    gppLerpRows = 0;
    gpLerpTable16 = 0;
    gpLerpTable32 = 0;
    gppRampTable = 0;
    gpLerpTable40 = 0;
    ghShakeSound = 0;
    VIEW_FreeCels();
}

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

// 0x00476A80
void __fastcall SCMD_StartTimedEffect(int nArg0, int nArg1, int nArg2, int nArg3)
{
    if (nArg2)
    {
        gdwViewEffectStartTick = GetTickCount();
        gnViewEffectFadeIn = nArg1;
        gnViewEffectHold = nArg2;
        gnViewEffectFadeOut = nArg3;
        gnViewEffectMagnitude = nArg0;
    }
}

// 0x00476B10
Obj004DCF10* __cdecl VIEW_CreateView()
{
    SYN_ASSERT(gppLerpRows, 0x119);
    SYN_ASSERT(gpLerpTable16, 0x11A);
    SYN_ASSERT(gpLerpTable32, 0x11B);

    Obj004DCF10* view = static_cast<Obj004DCF10*>(FOG_Alloc(sizeof(Obj004DCF10), ".\\GAME\\View.cpp", 0x11D, 0));
    SetRect(&view->rect, 0, 0, 0, 0);

    void* const rows = gppLerpRows;
    void* const data = gpLerpTable16;
    void* const table = gpLerpTable32;

    view->flags = 0;
    view->rows = rows;
    view->data = data;
    view->table = table;
    sub_004DDDF0(rows, data);
    WALL2_ResetViewCells(view);
    view->flags |= 1;
    gdwLightTick = 0;
    return view;
}

// 0x00476BC0
void __fastcall VIEW_PrepareSceneLighting(D2ViewStrc* pView)
{
    if (!pView->tRect.right && !pView->tRect.bottom)
    {
        return;
    }

    SCALE_UpdateFactor();
// build: symbol ?SCALE_GetFactor@* 0x004F65E0
    gdwGlobal_007B57E4 = SCALE_GetFactor();
    if (D2GFX_CheckPerspective())
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nX = UNITS_GetPrecisionX(pPlayer);
        int nY = UNITS_GetPrecisionY(pPlayer);
        int nOffsetX = 0;
        int nOffsetY = 0;
        if (gnViewEffectMagnitude)
        {
            nOffsetX = gnViewShiftX << 16;
            nOffsetY = gnViewShiftY << 16;
            DUNGEON_ClientToGameSubtileCoords(&nOffsetX, &nOffsetY);
            nX += nOffsetX;
            nY += nOffsetY;
        }
        SCALE_SetPerspectiveScale(nX, nY);
    }

    const int nTick = sub_0044DB00();
    if (nTick > gdwLightTick_007B9530)
    {
        gdwLightTick_007B9530 = nTick;
// build: symbol ?DLIGHTMAP_RunLightPass@* 0x00475800
        DLIGHTMAP_RunLightPass();
    }

    WALL2_UpdateRoomColor();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_ARCANESANCTUARY)
    {
        VIEW_DrawStarfield();
    }

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_ROCKYSUMMIT)
    {
        VIEW_DrawSummitBackdrop(pPlayer);
    }
    else
    {
        if (gpSummitCel)
        {
            ARCHIVE_FreeClientCellFile(gpSummitCel);
            gpSummitCel = 0;
        }
        if (gpCloudCel)
        {
            ARCHIVE_FreeClientCellFile(gpCloudCel);
            gpCloudCel = 0;
        }
    }

    if (pView->dwDrawFlags & gdwBitMasks[0])
    {
        sub_004DF480_UpdateAllTileLights((D2TileLightCtxStrc*)pView);
    }
    sub_004DED10(pView);
    sub_00473C00_DrawWeatherLayers();
    if (pView->dwDrawFlags & gdwBitMasks[3])
    {
        ((D2CellGridViewStrc*)pView)->sub_004DF510_DrawCellNodes();
    }
    sub_004DF1C0(pView);
    if (pView->dwDrawFlags & gdwBitMasks[1])
    {
        DFLOOR_UpdateFloorView(pView);
    }
    if (gbDebugDrawLights)
    {
        DLIGHTMAP_DebugDrawLights();
    }
    SCALE_SetDefaultFactor();
    sub_00473910();
    GFXUTIL_DrawFadeBox();
}

// 0x00475FD0
void __fastcall VIEW_FreeView(D2ViewStrc* pView)
{
    WALL2_FreeViewCells(pView);
    FOG_Free(pView, ".\\GAME\\View.cpp", 0x141, 0);
}

// 0x00475FF0
void __fastcall VIEW_SetViewDirty(D2ViewStrc* pView)
{
    pView->dwFlags |= 1;
}

// 0x00476000
void __fastcall VIEW_SetViewRects(D2ClientViewStrc* pView, int nLeft, int nTop, int nRight, int nBottom)
{
    if (!pView)
        return;

    SetRect(&pView->tViewRect, nLeft, nTop, nRight, nBottom);
    nBottom = sub_004F51D0_IsPerspective();
    SetRect(&pView->tClipRect, -0x50, -0x50, gnScreenWidth + 0x50, gnScreenHeight - 0x2F);
    if (nBottom)
    {
        pView->tClipRect.top -= 30;
        pView->tClipRect.left -= 45;
        pView->tClipRect.right += 30;
    }
    pView->dwFlags |= 1;
}

// 0x00476070
void __fastcall VIEW_GetViewRect(D2ClientViewStrc* pView, int* pValue04, int* pValue08, int* pValue0C, int* pValue10)
{
    *pValue04 = pView->nValue04;
    *pValue08 = pView->nValue08;
    *pValue0C = pView->nValue0C;
    *pValue10 = pView->nValue10;
}

// 0x004760A0
void __fastcall VIEW_SetViewPos(D2ClientViewStrc* pView, int nX, int nY)
{
    if (pView->nPosX != nX || pView->nPosY != nY)
    {
        pView->dwFlags |= 1;
        pView->nPosX = nX;
        pView->nPosY = nY;
    }
}

// 0x004760C0
void __fastcall VIEW_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY)
{
    *pX = pView->nPosX;
    *pY = pView->nPosY;
}

// 0x004760E0
void __fastcall VIEW_ViewToGameCoords(D2ClientViewStrc* pView, int nX, int nY, int* pX, int* pY)
{
    D2_ASSERT(pView, 0x1CD);
    D2_ASSERT(pX, 0x1CE);
    D2_ASSERT(pY, 0x1CF);
    DUNGEON_ClientSubileDrawPositionToGameCoords(pView->nPosX + nX, pView->nPosY + nY, pX, pY);
}

// 0x00476140
void __fastcall VIEW_PrepareView(D2ViewStrc* pView, int nArg)
{
    D2_ASSERT(pView, 0x1DD);
    if (pView->tRect.right || pView->tRect.bottom)
    {
        if (sub_0045AE90() != 3)
            WALL2_PrepareWallCells(pView, nArg);
        pView->dwFlags &= ~1;
    }
}

// 0x004769B0
void __cdecl VIEW_ToggleDebugDrawLights()
{
    gbDebugDrawLights = gbDebugDrawLights == 0;
}

// 0x004769D0
static void VIEW_UpdateShakeSound(int nIntensity)
{
    int nVolume = nIntensity * 0xFF / 20;
    nVolume = nVolume > 0 ? nVolume : 0;
    if (nVolume >= 0xFF)
    {
        nVolume = 0xFF;
    }

    if (nVolume && !ghShakeSound)
    {
        ghShakeSound = sub_004B9A00(0x1C4, 0, 0, 0, 0);
        if (!ghShakeSound)
        {
            return;
        }
        SOUNDINST_SetValue(ghShakeSound, 0);
    }

    if (!ghShakeSound)
    {
        return;
    }

    const int nCurrent = sub_004B9B20(ghShakeSound);
    if (nVolume == nCurrent)
    {
        return;
    }

    int nNew;
    if (nVolume > nCurrent)
    {
        nNew = nCurrent + 6;
        if (nVolume < nNew)
        {
            nNew = nVolume;
        }
    }
    else
    {
        nNew = nCurrent - 6;
        if (nVolume > nNew)
        {
            nNew = nVolume;
        }
    }

    if (nNew)
    {
        SOUNDINST_SetValue(ghShakeSound, nNew);
        return;
    }

    sub_004BA840(ghShakeSound);
    ghShakeSound = 0;
}

// 0x00476AC0
int __fastcall VIEW_GetViewShift(int* pX, int* pY)
{
    if (!gnViewEffectMagnitude)
        return 0;

    *pX = gnViewShiftX;
    *pY = gnViewShiftY;
    return 1;
}

static inline unsigned int STARS_Roll(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int STARS_RollLH(D2SeedStrc* pSeed, unsigned int nLow, unsigned int nHigh)
{
    const unsigned __int64 lSeed = nHigh + 0x6AC690C5i64 * nLow;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int STARS_RollUpTo(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    const unsigned int nLow = pSeed->nLowSeed;
    const unsigned int nHigh = pSeed->nHighSeed;
    if ((nMax - 1) & nMax)
    {
        return STARS_RollLH(pSeed, nLow, nHigh) % nMax;
    }

    return STARS_RollLH(pSeed, nLow, nHigh) & (nMax - 1);
}

// 0x00476190
void __stdcall VIEW_ResetStar(int nStar, int bRespawn)
{
    int* const pX = &gaStarX[nStar];
    D2SeedStrc* pSeed = gpClientSeed;
    const int nX = bRespawn ? (STARS_Roll(pSeed) & 7) + gnStarFieldWidth_007A5220 - 1 : SEED_RollLimitedRandomNumber(pSeed, gnStarFieldWidth_007A5220);
    const int nHeight = gnStarFieldHeight_007A521C;
    *pX = nX;
    gaStarY[nStar] = STARS_RollUpTo(pSeed, nHeight);
    gaStarSpeed[nStar] = -(int)(STARS_Roll(pSeed) % 5) - 1;
    gaStarColor[nStar] = gaStarShades[STARS_Roll(pSeed) & 7];
}

// 0x00476290
void __cdecl VIEW_DrawStarfield()
{
    if (!gbStarsInit)
    {
        SEED_InitSeed(gpClientSeed);
        SEED_InitLowSeed(gpClientSeed, SEED_GetRandomValue(gdwViewEffectStartTick));

        for (int nShade = 0; nShade < 8; ++nShade)
        {
            const int nBase = nShade * 0x80 / 7 + 0x80;
            D2SeedStrc* pSeed = gpClientSeed;
            unsigned __int64 lSeed;
            int nRed = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nRed > 0xFF)
                nRed = 0xFF;
            int nGreen = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nGreen > 0xFF)
                nGreen = 0xFF;
            int nBlue = (STARS_ROLL(pSeed, lSeed) & 0x3F) + nBase - 0x20;
            if (nBlue > 0xFF)
                nBlue = 0xFF;
// build: symbol ?PALETTE_FindPaletteIndex@* 0x004FB180
            gaStarShades[nShade] = PALETTE_FindPaletteIndex(nRed, nGreen, nBlue);
        }

        for (int i = 0; i < 256; ++i)
            VIEW_ResetStar(i, 0);

        gbStarsInit = 1;
    }

    for (int i = 0; i < 256; ++i)
        D2GFX_DrawLine(gaStarX[i], gaStarY[i], gaStarX[i], gaStarY[i], gaStarColor[i], 0xFF);

    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwStarTick > 40)
    {
        for (int i = 0; i < 256; ++i)
        {
            gaStarX[i] += gaStarSpeed[i];
            if (gaStarX[i] < 0)
                VIEW_ResetStar(i, 1);
        }
        gdwStarTick = dwTick;
    }
}

// 0x00476460
static void VIEW_DrawSummitBackdrop(D2UnitStrc* pPlayer)
{
    if (gbLeavingGame)
    {
        return;
    }

    if (!(gnBaseGuard & 1)) {
        gnBaseGuard |= 1;
        snBaseX = UNITS_GetClientCoordX(pPlayer);
    }
    if (!sbBaseSet)
    {
        sbBaseSet = true;
        snBaseX = 0x274F;
    }

    gnSummitScroll = UNITS_GetClientCoordX(pPlayer) - snBaseX;
    const int nPos = gnSummitScroll / 8;
    const int nOffset = nPos % 256;
    int nFrame = nPos / 256 % 4;
    while (nFrame < 0)
    {
        nFrame += 4;
    }
    nFrame %= 4;
    const int nX = -nOffset;

    if (!gpSummitCel)
    {
        char szPath[260];
        strcpy(szPath, "data\\global\\ui\\summit01");
        gpSummitCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }

    if (!gpCloudCel)
    {
        char szPath[260];
        strcpy(szPath, "data\\global\\ui\\cloud01");
        gpCloudCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }

    D2CelContextStrc tGfxData = {};
    if (gpSummitCel)
    {
        tGfxData.pCellFile = gpSummitCel;
        tGfxData.nFrame = nFrame;
        TEXTURE_CelDraw(&tGfxData, nX, 0x100, -1, 5, 0);
        const int nFrame1 = (nFrame + 1) % 4;
        tGfxData.nFrame = nFrame1;
        TEXTURE_CelDraw(&tGfxData, nX + 0x100, 0x100, -1, 5, 0);
        const int nFrame2 = (nFrame + 2) % 4;
        tGfxData.nFrame = nFrame2;
        TEXTURE_CelDraw(&tGfxData, nX + 0x200, 0x100, -1, 5, 0);
        const int nFrame3 = (nFrame + 3) % 4;
        tGfxData.nFrame = nFrame3;
        TEXTURE_CelDraw(&tGfxData, nX + 0x300, 0x100, -1, 5, 0);
        if (nX > 0)
        {
            tGfxData.nFrame = nFrame3;
            TEXTURE_CelDraw(&tGfxData, nX - 0x100, 0x100, -1, 5, 0);
        }

        tGfxData.nFrame = nFrame + 4;
        TEXTURE_CelDraw(&tGfxData, nX, 0x200, -1, 5, 0);
        tGfxData.nFrame = nFrame1 + 4;
        TEXTURE_CelDraw(&tGfxData, nX + 0x100, 0x200, -1, 5, 0);
        tGfxData.nFrame = nFrame2 + 4;
        TEXTURE_CelDraw(&tGfxData, nX + 0x200, 0x200, -1, 5, 0);
        tGfxData.nFrame = nFrame3 + 4;
        TEXTURE_CelDraw(&tGfxData, nX + 0x300, 0x200, -1, 5, 0);
        if (nX > 0)
        {
            tGfxData.nFrame = nFrame3 + 4;
            TEXTURE_CelDraw(&tGfxData, nX - 0x100, 0x200, -1, 5, 0);
        }

        if (D2GFX_GetResolutionMode() == 2)
        {
            tGfxData.nFrame = nFrame + 8;
            TEXTURE_CelDraw(&tGfxData, nX, 0x300, -1, 5, 0);
            tGfxData.nFrame = nFrame1 + 8;
            TEXTURE_CelDraw(&tGfxData, nX + 0x100, 0x300, -1, 5, 0);
            tGfxData.nFrame = nFrame2 + 8;
            TEXTURE_CelDraw(&tGfxData, nX + 0x200, 0x300, -1, 5, 0);
            tGfxData.nFrame = nFrame3 + 8;
            TEXTURE_CelDraw(&tGfxData, nX + 0x300, 0x300, -1, 5, 0);
            if (nX > 0)
            {
                tGfxData.nFrame = nFrame3 + 8;
                TEXTURE_CelDraw(&tGfxData, nX - 0x100, 0x300, -1, 5, 0);
            }
        }
    }

    if (gpCloudCel)
    {
        D2SeedStrc* pSeed;
        unsigned __int64 lSeed;
        int i;
        if (!gbCloudsInit)
        {
            SEED_InitSeed(gpSkySeed);
            SEED_InitLowSeed(gpSkySeed, SEED_GetRandomValue(GetTickCount()));
            pSeed = gpSkySeed;
            for (i = 0; i < 10; ++i)
            {
                gaCloudX[i] = SEED_RollLimitedRandomNumber(pSeed, gnAutomapWidth << 4);
                gaCloudY[i] = SUMMIT_ROLL(pSeed, lSeed) % 250;
                gaCloudSpeed[i] = (SUMMIT_ROLL(pSeed, lSeed) & 0xF) + 8;
            }
            gbCloudsInit = true;
        }
        else
        {
            pSeed = gpSkySeed;
        }

        for (i = 0; i < 10; ++i)
        {
            gaCloudX[i] += gaCloudSpeed[i];
            if (gaCloudX[i] > (gnAutomapWidth + 0x170) << 4)
            {
                gaCloudX[i] = -0x1700;
                gaCloudY[i] = SUMMIT_ROLL(pSeed, lSeed) % 300;
            }
        }

        for (i = 0; i < 10; ++i)
        {
            tGfxData.pCellFile = gpCloudCel;
            tGfxData.nFrame = 0;
            nFrame = gaCloudX[i] / 16;
            TEXTURE_CelDraw(&tGfxData, nFrame, gaCloudY[i], 0xDDDDDDDD, 3, 0);
            tGfxData.nFrame = 1;
            TEXTURE_CelDraw(&tGfxData, nFrame + 0x100, gaCloudY[i], 0xDDDDDDDD, 3, 0);
        }
    }
}

// 0x00476AF0
void __cdecl VIEW_ClearGlobals()
{
    gnViewEffectMagnitude = 0;
    gnViewShiftX = 0;
    gnViewShiftY = 0;
}

// 0x00476D40
void __fastcall VIEW_AdjustViewPos(int* pX, int* pY)
{
    const unsigned int nTick = GetTickCount();
    const unsigned int nElapsed = nTick - gdwViewEffectStartTick;
    const unsigned int nFadeIn = gnViewEffectFadeIn;
    const unsigned int nHold = gnViewEffectHold;
    const unsigned int nFadeOut = gnViewEffectFadeOut;
    int nMagnitude = 0;
    if (nElapsed > nFadeOut + nHold + nFadeIn)
    {
        VIEW_UpdateShakeSound(nMagnitude);
        gnViewEffectMagnitude = 0;
        gnViewShiftX = 0;
        gnViewShiftY = 0;
        return;
    }

    if (nElapsed < nFadeIn)
    {
        if (nFadeIn)
        {
            nMagnitude = gnViewEffectMagnitude * nElapsed / nFadeIn;
        }
    }
    else if (nElapsed < nHold + nFadeIn)
    {
        nMagnitude = gnViewEffectMagnitude;
    }
    else if (nFadeOut)
    {
        nMagnitude = (nFadeOut - nElapsed + nHold + nFadeIn) * gnViewEffectMagnitude / nFadeOut;
    }

    if (nMagnitude)
    {
        D2SeedStrc* pSeed = &sub_00463DD0_GetPlayerUnit()->pSeed;
        gnViewShiftX = sub_00472280(pSeed, -nMagnitude, 2 * nMagnitude);
        const int nOffsetY = sub_00472280(pSeed, -nMagnitude, 2 * nMagnitude);
        *pX += gnViewShiftX;
        *pY += nOffsetY;
        gnViewShiftY = nOffsetY;
    }
    VIEW_UpdateShakeSound(nMagnitude);
}

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...);                           // 0x004F6890

void __cdecl sub_00477760_DrawCacheStats(); // 0x00477760

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

// 0x0047E860
void __stdcall VIEW_DrawCelFrame(int nFrame, int nX, int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpGlobal_007BC964;
    tContext.nFrame = nFrame;
    sub_004F6480(&tContext, nX, nY, -1, 5, 0);
}

// 0x00480400
int __fastcall VIEW_GetPlayerInteractState(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->pPlayerData)
    {
        return pUnit->pPlayerData->nState;
    }
    return 0;
}

// 0x004804D0
unsigned int __cdecl VIEW_GetPingScaled()
{
    return (sub_0044CE60_GetPing() + 0x32) >> 7;
}

// 0x004879D0
void __fastcall VIEW_ResetSelectionForUnit(D2UnitStrc* pUnit)
{
    if (gpHoverItem == pUnit)
    {
        gnHoverTopX = -1;
        gnHoverTopY = -1;
        gnHoverBottomX = -1;
        gnHoverBottomY = -1;
        gnHoverCellX = -1;
        gnHoverCellY = -1;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
    }
}

// 0x00487CA0
int __cdecl VIEW_SetNpcMenuMode()
{
    if (gnInvPanelMode == 6)
        return 0;
    gnInvPanelMode = 6;
    return 1;
}

void __cdecl sub_00499E30();

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

unsigned char gnHelpShadeColor; // 0x007BEEF8

static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

void __stdcall sub_M114_Emit_00492BD0(int nMode, int nPopupX)
{
    gnPetIconPopupState = nMode;
    gnPopupX = nPopupX;
}

static int ButtonHitTest_00497480(int nX, int nY)
{
    int nHeight = gnScreenHeight;
    int nWidth = gnScreenWidth;
    return nX >= nWidth / 2 - 0x91 && nX <= nWidth / 2 - 0x80 && nY >= nHeight - 0x1C && nY <= nHeight - 8;
}

// 0x004D1640
D2UnitStrc* __fastcall VIEW_SpawnDirectionalMissile(D2UnitStrc* pUnit, int nFrame)
{
    D2UnitStrc* pMissile = 0;
    if (pUnit->pDynamicPath)
    {
        unsigned char nDirection = PATH_GetDirection(pUnit->pDynamicPath);
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.pOwner = pUnit;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nMissile = MISSILE_FOOTPRINT;
        tMissileParams.nSkillLevel = 1;
        pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            pMissile->nSeqCurrentFramePrecise = nFrame << 8;
            if (pMissile->pDynamicPath)
                D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, nDirection);
            CUNIT_MarkUnitDead(pMissile);
        }
    }
    return pMissile;
}

// 0x004DC580
void __fastcall VIEW_DrawUnitClickCross(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x61);
    int nX = pUnit->nLastClickX;
    int nY = pUnit->nLastClickY;
    DUNGEON_GameSubtileToClientCoords(&nX, &nY);
    D2GFX_DrawLine(nX - PLAYER_GetScreenOffsetX(), nY - PLAYER_GetScreenOffsetY(), nX - PLAYER_GetScreenOffsetX() + 0x10, nY - PLAYER_GetScreenOffsetY() + 8, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - PLAYER_GetScreenOffsetX(), nY - PLAYER_GetScreenOffsetY(), nX - PLAYER_GetScreenOffsetX() - 0x10, nY - PLAYER_GetScreenOffsetY() + 8, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - PLAYER_GetScreenOffsetX() - 0x10, nY - PLAYER_GetScreenOffsetY() + 8, nX - PLAYER_GetScreenOffsetX(), nY - PLAYER_GetScreenOffsetY() + 0x10, 0xFF, 0xFF);
    D2GFX_DrawLine(nX - PLAYER_GetScreenOffsetX() + 0x10, nY - PLAYER_GetScreenOffsetY() + 8, nX - PLAYER_GetScreenOffsetX(), nY - PLAYER_GetScreenOffsetY() + 0x10, 0xFF, 0xFF);
    const int nBoxX = UNITS_GetClientCoordX(pUnit) - PLAYER_GetScreenOffsetX();
    const int nBoxY = UNITS_GetClientCoordY(pUnit) - PLAYER_GetScreenOffsetY();
    D2GFX_DrawBox(nBoxX, nBoxY, nBoxX + 4, nBoxY + 4, 0xFF, DRAW_MODE_5);
}

void __stdcall LIST_UnloadPentspinCellfile()
{
    ARCHIVE_FreeCellFile(sghPentagram);
    sghPentagram = 0;
}

#include "gen/data/Source/D2Client/GAME/View.inc"
