#include "D2LanguageNames.h"
#include "D2Unicode.h"
#include "D2ObjectIds.h"
#include "D2MissileIds.h"
#include "D2LevelIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2ClientUiRecords.h"
#include "D2WinSplitText.h"

#define LEVEL_EFFECT_TICKS 30
#define THRONE_MISSILE 0x27F
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MissilesTxt;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2ClientTimedBoxStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;
union D2SeedStrc;
struct D2DrlgCoordsStrc;





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);



D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
void __fastcall SCMD_GetRoomLight(D2ActiveRoomStrc* pRoom, int* pLight, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue, int nFlag); // 0x00474550
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0


int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
void __fastcall VIEW_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce); // 0x0046AE50
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620


D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA2A0
void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet); // 0x004DA6E0
void __fastcall ITEM_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
int gbPulseDone; // 0x007A745C

// build: symbol ?gnPulseTick@* 0x007129CC
#include "gen/data/Source/D2Client/Unknown_0046ACE0/gnPulseTick.inc"
extern int gbChaosLightEvent; // 0x007A7460
extern int gnTimerEnd; // 0x007A7464
extern int gbThroneEventPending; // 0x007A7468
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall sub_0046AF70(D2ActiveRoomStrc* pRoom); // 0x0046AF70
void __cdecl sub_0046AD10_UpdateTimedBox(); // 0x0046AD10
void __cdecl CUNIT_DrawCountdown(); // 0x0046C060
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
extern D2ClientTimedBoxStrc gtTimedBox; // 0x007A742C



unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nClassId, int nX, int nY, int nUnitType, int nArg); // 0x00466730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

// 0x0046ACE0
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static inline D2MonStats2Txt* CLIENT_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
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





// 0x0046AE50
void __fastcall VIEW_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce)
{
    if (gtTimedBox.bLocked && !bForce)
    {
        return;
    }
    memset(&gtTimedBox, 0, sizeof(gtTimedBox));
    gtTimedBox.bActive = 1;
    D2_ASSERT(nFadeIn, 0x67);
    gtTimedBox.nFadeIn = nFadeIn;
    gtTimedBox.nHold = nHold;
    if (!nFadeOut)
    {
        nFadeOut = 0x19;
    }
    gtTimedBox.nFadeOut = nFadeOut;
    gtTimedBox.nTotal = nFadeIn + nHold + nFadeOut;
    gtTimedBox.nLevelId = nLevelId;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }
    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static inline D2MonStats2Txt* MONSTATS2_GetRecordInline(int nMonStatsEx)
{
    return (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount) ? &sgptDataTables->pMonStats2Txt[nMonStatsEx] : 0;
}

// 0x0046AF70
void __stdcall sub_0046AF70(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (pPlayer)
    {
        D2MissileStrc tMissile;
        D2DrlgCoordsStrc tCoords;
        memset(&tMissile, 0, sizeof(tMissile));
        tMissile.dwFlags = 0x2003;
        tMissile.pOwner = pPlayer;
        tMissile.nSkill = 0;
        tMissile.nSkillLevel = 1;
        tMissile.nMissile = MISSILE_DENOFEVILLIGHT;
        DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
        int nCount = 0;
        int i = 0;
        for (; nCount < 3; ++i)
        {
            if (i >= 25) break;
            int nX = tCoords.nSubtileX + SEED_RollLimitedRandomNumber(&pPlayer->pSeed, tCoords.nSubtileWidth);
            int nY = tCoords.nSubtileY + SEED_RollLimitedRandomNumber(&pPlayer->pSeed, tCoords.nSubtileHeight);
            tMissile.nX = nX;
            if (!COLLISION_CheckMask(pRoom, nX, tMissile.nY = nY, 5)) { MISSILE_CreateClientMissile(&tMissile); } else { --nCount; }
            ++nCount;
        }
    }
}

// 0x0046B4A0
void __cdecl SCMD_TriggerNearbyMonsterEffect()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;
    D2UnitStrc* pMonster = UNITFINDS_FindUnitInNeighboredRooms(pRoom, UNIT_MONSTER, 0x20E);
    if (!pMonster)
        return;

    const int nX = CLIENTS_GetUnitX(pMonster);
    const int nY = CLIENTS_GetUnitY(pMonster);
    MISSILE_SubmitMissileRequest(pPlayer, 0x25E, nX, nY, 0, 1);
    MISSILE_SubmitMissileRequest(pPlayer, 0x25B, nX, nY, 0, 1);
    pMonster->dwFlagEx |= 0x40000;
}

struct Unicode;




typedef void (__cdecl* LEVELEVENT_Fn)();

extern LEVELEVENT_Fn gpfnLevelEvents[];                                                            // 0x007129D8

unsigned int gdwLevelEventBits;                                                                    // 0x007A7458

// 0x0046B630
void __fastcall sub_0046B630_FireLevelEvent(int nIndex)
{
    D2_ASSERT(nIndex < 0x20, 0x1D9);
    D2_ASSERT(nIndex < 0x14, 0x1DA);
    gdwLevelEventBits |= 1 << nIndex;
    if (gpfnLevelEvents[nIndex])
    {
        gpfnLevelEvents[nIndex]();
    }
}



// 0x0046B680
void __fastcall VIEW_SpawnBrDeathControl(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = MISSILE_BRDEATHCONTROL;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
        MISSILE_SetTargetX(pMissile, 0x32);

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = MISSILE_BRDEATHSPIRITS1;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&tMissileParams);
    tMissileParams.nMissile = MISSILE_BRDEATHSMOKES1;
    MISSILE_CreateClientMissile(&tMissileParams);
}



static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->nXPos;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->nYPos;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x0046B710
void __fastcall sub_0046B710_SpawnMissileAtObject173(D2UnitStrc* pUnit)
{
    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pUnit), 2, 0x173);
    int nX;
    int nY;
    if (pObject)
    {
        nX = CLIENTS_GetUnitXInline(pObject);
        nY = CLIENTS_GetUnitYInline(pObject);
    }
    else
    {
        nX = CLIENTS_GetUnitXInline(pUnit) - 15;
        nY = CLIENTS_GetUnitYInline(pUnit) - 15;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x420;
    tMissileParams.nMissile = MISSILE_TOWERMIST;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = nX;
    tMissileParams.nTargetY = nY;
    tMissileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&tMissileParams);

    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, 0x14C, nX, nY, 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetY(pMissile, 0);
    }
}


// 0x0046B850
void __fastcall VIEW_SpawnMissileNearObject(D2UnitStrc* unit)
{
 D2UnitStrc* object=UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(unit),2,0x182);
 int x,y;
 if(object) {
  ITEM_ShowTimedHint((void*)0x124F,0,0x15E,0,0,0,0);
  x=CLIENTS_GetUnitXInline(object);
  y=CLIENTS_GetUnitYInline(object);
 } else {
  x=CLIENTS_GetUnitXInline(unit)-15;
  y=CLIENTS_GetUnitYInline(unit)-15;
 }
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.dwFlags=0x420;
 params.nMissile=MISSILE_ORBMIST;
 params.pOwner=unit;
 params.pOrigin=unit;
 params.nTargetX=x;
 params.nTargetY=y;
 params.nSkillLevel=1;
 D2UnitStrc* missile=MISSILE_CreateClientMissile(&params);
 if(missile&&object)MISSILE_SetTargetX(missile,object->dwUnitId);
}

// 0x0046B9A0
void __fastcall VIEW_SpawnMephistoDeath(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = MISSILE_MEPHISTODEATHCONTROL;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, 0x4B);
        MISSILE_SetTargetY(pMissile, 0x4B);
    }

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pUnit;
    tMissileParams.nSkillLevel = 1;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nMissile = MISSILE_MEPHISTOHOLEDELAY;
    MISSILE_CreateClientMissile(&tMissileParams);

    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = MISSILE_MEPHISTODONOTDRAW;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&tMissileParams);
}



// 0x0046BA50
void __fastcall VIEW_SpawnAndarielDeath(D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = MISSILE_ANDYCONTROL0;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&tMissileParams);
}



// 0x0046BC10
void __fastcall VIEW_SpawnIzualDeath(D2UnitStrc* pUnit)
{
    ITEM_ShowTimedHint((void*)0x1253, 0, 0xFA, 0, 0, 0, 0);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = MISSILE_IZUAL_CONTROL;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&tMissileParams);
}

// 0x0046BC70
int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit)
{
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
// build: symbol ?gnTimerUnitId@* 0x007129D4
    gnTimerUnitId = nUnitId;
    return nUnitId;
}

int __stdcall INV_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0

// 0x0046BD50
int __stdcall ROSTERPETS_GetPulseColor(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    if (gbPulseDone || !INV_GetTableByte(0, 1))
    {
        return 0;
    }
    *pRed = 0xFF;
    *pGreen = 0x40;
    *pBlue = 0x30;
    if (gnPulseTick == -1)
    {
        return 0x50;
    }
// build: symbol ?FOG_10083_Cos_LUT@* 0x0040B330
    return (int)(FOG_10083_Cos_LUT(gnPulseTick * 128 / 30) * 80.0);
}

#define gnGlobal_007A7430 (gtTimedBox.nValue)

#define gnGlobal_007A7434 (gtTimedBox.nColor[0])

#define gnGlobal_007A7435 (gtTimedBox.nColor[1])

#define gnGlobal_007A7436 (gtTimedBox.nColor[2])

// 0x0046BDD0
int __fastcall SCMD_GetLevelLight(D2ActiveRoomStrc* pRoom, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    switch (DUNGEON_GetLevelIdFromRoom(pRoom))
    {
    case LEVEL_DENOFEVIL:
        return ROSTERPETS_GetPulseColor(pRed, pGreen, pBlue);

    case LEVEL_RIVEROFFLAME:
    case LEVEL_CHAOSSANCTUM:
// build: symbol ?gnLevelEffectTick@* 0x007129D0
        if (gbChaosLightEvent && gnLevelEffectTick == -1)
        {
            *pRed = 0xFF;
            *pGreen = 0x40;
            *pBlue = 0x30;
            return 0xA0;
        }
        return 0;

    default:
        *pRed = gnGlobal_007A7434;
        *pGreen = gnGlobal_007A7435;
        *pBlue = gnGlobal_007A7436;
        return gnGlobal_007A7430;
    }
}

// 0x0046BFD0
void __fastcall sub_0046BFD0_StartTimer(int nDelay)
{
    if (nDelay > 0 && gnTimerEnd == 0)
    {
        gnTimerEnd = sub_00410A80_GetTime() + nDelay;
    }
}

void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom); // 0x0046BF30

// 0x0046BFF0
void __fastcall sub_0046BFF0_UnitEventMissile271(D2UnitStrc* pUnit)
{
    D2UnitStrc* pMissile = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pUnit), 3, 0x271);
    if (!pMissile)
    {
        return;
    }

    sub_004DA000(pUnit);
    GFXUTIL_SetMotionVectorA(pUnit, 0, 0, 0x12C);
    GFXUTIL_SetMotionVectorB(pUnit, 0, 0, -2, 1);
    GFXUTIL_SetMotionVectorC(pUnit, 0, 0, 5, 0);
    GFXUTIL_SetMotionFlagMask(pUnit, 0);
    MISSILE_SetTargetY(pMissile, 1);
    sub_0046BF30_CheckThroneLevel(CUNIT_GetPlayerRoom());
}

extern int gnScreenWidth; // 0x0071146C

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

// 0x0046C060
void __cdecl CUNIT_DrawCountdown()
{
    unsigned short wszTextBuf[256];
    Unicode* wszText = (Unicode*)wszTextBuf;
    const int nNow = sub_00410A80_GetTime();
    if (!gnTimerEnd || gnTimerEnd <= nNow)
        return;
// build: symbol ?gnTimerUnitId@* 0x007129D4
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnTimerUnitId, 1);
    if (pUnit && pUnit->dwAnimMode != 12 && gnTimerEnd - 0x46 > nNow)
        return;
    for (int i = 0; i < 256; ++i)
        wszText[i].wChar = 0;
    sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x13E9), gnTimerEnd - nNow);
    const int nOldFont = D2Win_10127_SetFont(13);
    const int nWidth = D2Win_10121_GetTextWidth(wszText);
    D2Win_10117_DrawText(wszText, gnScreenWidth / 2 - nWidth / 2, 0x177, 9, 1);
    D2Win_10127_SetFont(nOldFont);
}

// 0x0046C140
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode)
{
    D2MonStats2Txt* pMonStats2TxtRecord = CLIENT_GetMonStats2TxtRecord(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }
    return pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7];
}

D2ClientTimedBoxStrc gtTimedBox; // 0x007A742C

// 0x0046AD10
void __cdecl sub_0046AD10_UpdateTimedBox()
{
    unsigned int nLight = 0;
    SCMD_GetRoomLight(CUNIT_GetPlayerRoom(), (int*)&nLight, &gtTimedBox.nColor[0], &gtTimedBox.nColor[1], &gtTimedBox.nColor[2], 0);

    if (gtTimedBox.nTick < gtTimedBox.nFadeIn)
    {
// build: symbol ?FOG_10083_Cos_LUT@* 0x0040B330
        gtTimedBox.nValue = (int)(FOG_10083_Cos_LUT(gtTimedBox.nAngle) * nLight);
        gtTimedBox.nAngle = (gtTimedBox.nTick << 7) / gtTimedBox.nFadeIn;
    }
    else if (gtTimedBox.nTick >= gtTimedBox.nTotal - gtTimedBox.nFadeOut)
    {
        gtTimedBox.nValue = (int)(FOG_10083_Cos_LUT(gtTimedBox.nAngle) * nLight);
        const int nElapsed = gtTimedBox.nFadeOut - gtTimedBox.nTotal + gtTimedBox.nTick;
        if (!gtTimedBox.nFadeOut)
        {
            gtTimedBox.nFadeOut = 0x19;
        }
        gtTimedBox.nAngle = 0x80 - (nElapsed << 7) / gtTimedBox.nFadeOut;
    }
    else
    {
        gtTimedBox.nValue = 0;
    }

    ++gtTimedBox.nTick;
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    int nLevelId = 0;
    if (pRoom)
    {
        nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }
    if (gtTimedBox.nTick > gtTimedBox.nTotal || nLevelId != gtTimedBox.nLevelId)
    {
        memset(&gtTimedBox, 0, sizeof(gtTimedBox));
    }
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

// 0x0046B0D0
void __cdecl sub_0046B0D0_ApplyDenOfEvilRooms()
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(gpGlobal_007A0634); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_DENOFEVIL)
        {
            sub_0046AF70(pRoom);
        }
    }
}

inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x0046B530
void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    int nObjectId;
    switch (pUnit->dwClassId)
    {
    case 0x21C:
        nObjectId = OBJECT_ANCIENTSTATUE1;
        break;
    case 0x21D:
        nObjectId = OBJECT_ANCIENTSTATUE2;
        break;
    case 0x21E:
        nObjectId = OBJECT_ANCIENTSTATUE3;
        break;
    default:
        return;
    }

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pUnit), 2, nObjectId);
    if (!pObject)
        return;

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x420;
    tMissileParams.nMissile = MISSILE_ANCIENT_DEATH_CENTER;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = CLIENTS_GetUnitXInline(pObject);
    tMissileParams.nTargetY = CLIENTS_GetUnitYInline(pObject);
    tMissileParams.nSkillLevel = 1;
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, sub_00451F50(pObject));
    }
}

// 0x0046BA90
void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    MISSILE_SubmitMissileRequest(pPlayer, 0x15B, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BB10
void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    MISSILE_SubmitMissileRequest(pPlayer, 0x161, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BB90
void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    MISSILE_SubmitMissileRequest(pPlayer, 0x16B, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
}

// 0x0046BC90
void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit)
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    D2UnitStrc* pMonster = UNITFINDS_FindUnitInNeighboredRooms(UNITS_GetRoom(pPlayer), 1, 0x220);
    if (pMonster)
    {
        MISSILE_SubmitMissileRequest(pPlayer, 0x271, CLIENTS_GetUnitXInline(pMonster), CLIENTS_GetUnitYInline(pMonster), 0, 1);
    }
}

// 0x0046C130
void __cdecl sub_0046C130_DrawCountdown()
{
    CUNIT_DrawCountdown();
}

// 0x0046AEE0
void __cdecl sub_0046AEE0_ObjectMissileTimedBox()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x11);
    if (!pObject)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pObject);
    const int nY = CLIENTS_GetUnitY(pObject);
    MISSILE_SubmitMissileRequest(pPlayer, 0x120, nX, nY, 0, 1);

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(MISSILE_CAIRNSTONES);
    VIEW_StartTimedBox(pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->wRange - 2 * pMissilesTxtRecord->dwParam[0], pMissilesTxtRecord->dwParam[0], 4, 1);
}

// 0x0046B0C0
void __cdecl sub_0046B0C0_ResetPulseTick()
{
    gnPulseTick = 0;
}

// 0x0046B100
void __cdecl sub_0046B100_EventObject98Request()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x98);
    if (!pObject)
        return;

    ITEM_ShowTimedHint((void*)0x1252, 0, 0x2D5, 1, 0, 0, 0);
    const int nX = CLIENTS_GetUnitX(pObject);
    const int nY = CLIENTS_GetUnitY(pObject);
    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pPlayer, 0x152, nX, nY, 0, 1);
    if (pMissile)
    {
        GFXUTIL_SetMotionVectorA(pMissile, 0, 0, 0x28);
        GFXUTIL_SetMotionVectorB(pMissile, 0, 0, 0x200, 0);
        GFXUTIL_SetMotionVectorC(pMissile, 0, 0, 0x46, 0);
        GFXUTIL_SetMotionFlagMask(pMissile, 1);
    }
    GFX_AddUnitOverlay(pObject, 0xB5, 2, 0, 0, 0, 0, 0);
// build: symbol ?GFX_LoadMonsterCofs@* 0x0046F870
    GFX_LoadMonsterCofs(0xD3, 1);
}

// 0x0046B290
void __cdecl sub_0046B290_EventLevel108Request()
{
    gbChaosLightEvent = 1;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_CHAOSSANCTUM)
        return;

    const int nX = CLIENTS_GetUnitX(pPlayer);
    const int nY = CLIENTS_GetUnitY(pPlayer);
    MISSILE_SubmitMissileRequest(pPlayer, 0x174, nX, nY, 0, 1);
    GFX_LoadMonsterCofs(0xF3, 1);
}

// 0x0046B300
void __cdecl sub_0046B300_EventObject178Request()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x178);
    if (!pObject)
        return;

    ITEM_ShowTimedHint((void*)0x1251, 0, 0x15E, 0, 0, 0, 0);
    sub_004B9A00(0x23, pObject, 0, 0, 0);
    const int nX = CLIENTS_GetUnitX(pObject);
    const int nY = CLIENTS_GetUnitY(pObject);
    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pPlayer, 0x175, nX, nY, 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, sub_00451F50(pObject));
        MISSILE_SetTargetY(pMissile, 0);
    }
}

// 0x0046B3A0
void __cdecl sub_0046B3A0_StartTimer()
{
    gnTimerEnd = sub_00410A80_GetTime() + 0x5A;
// build: symbol ?gnLevelEffectTick@* 0x007129D0
    gnLevelEffectTick = 0;
}

// 0x0046B3C0
void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, 0x25A, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit), 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, 0x19);
    }
}


int gbChaosLightEvent; // 0x007A7460

int gbThroneEventPending; // 0x007A7468

int gbThroneEventActive; // 0x007A746C

// 0x0046BE60
void __fastcall sub_0046BE60_ApplyDenOfEvilRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 0x344);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_DENOFEVIL && gbPulseDone != 0)
    {
        sub_0046AF70(pRoom);
    }
}

// 0x0046BEB0
void __cdecl sub_0046BEB0_UpdateTimers()
{
    if (gtTimedBox.bActive)
    {
        sub_0046AD10_UpdateTimedBox();
    }
    if (!gbPulseDone && gnPulseTick != -1)
    {
        gnPulseTick += 1;
        if (gnPulseTick >= LEVEL_EFFECT_TICKS)
        {
            gbPulseDone = 1;
            sub_0046B0D0_ApplyDenOfEvilRooms();
        }
    }
    if (gbChaosLightEvent && gnLevelEffectTick != -1)
    {
        gnLevelEffectTick += 1;
        if (gnLevelEffectTick >= LEVEL_EFFECT_TICKS)
        {
            gbChaosLightEvent = 0;
            gnLevelEffectTick = -1;
        }
    }
}

// 0x0046BF30
void __fastcall sub_0046BF30_CheckThroneLevel(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return;
    }
    switch (DUNGEON_GetLevelIdFromRoom(pRoom))
    {
    case LEVEL_THRONEOFDESTRUCTION:
    case LEVEL_THEWORLDSTONECHAMBER:
        if (!gbThroneEventActive && gbThroneEventPending)
        {
            D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
            if (pUnit)
            {
                sub_004C5420_CreateFirstMissile(pUnit, THRONE_MISSILE, 0, 1);
                gbThroneEventActive = 1;
            }
        }
        break;
    default:
        gbThroneEventActive = 0;
        break;
    }
}

// 0x0046BF90
void __cdecl sub_0046BF90_ResetLevelEffects()
{
    gbPulseDone = 0;
    gnPulseTick = -1;
    gbChaosLightEvent = 0;
    gnTimerEnd = 0;
// build: symbol ?gnTimerUnitId@* 0x007129D4
    gnTimerUnitId = -1;
    gbThroneEventPending = 0;
    memset(&gtTimedBox, 0, sizeof(gtTimedBox));
}

// 0x0046B440
void __cdecl sub_0046B440_EventObject1CCRequest()
{
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;

    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x1CC);
    if (!pObject)
        return;

    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pPlayer, 0x210, CLIENTS_GetUnitX(pObject), CLIENTS_GetUnitY(pObject), 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, 0x19);
    }
}

// 0x0046B520
void __cdecl sub_0046B520_SetFlag7A7468()
{
    gbThroneEventPending = 1;
}

struct D2UnitStrc;

// 0x0046B1E0
void __cdecl sub_0046B1E0_EventObject95Request()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    D2UnitStrc* pObject = UNITFINDS_FindUnitInNeighboredRooms(pRoom, 2, 0x95);
    if (!pObject)
        return;

    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pPlayer, 0x15E, CLIENTS_GetUnitXInline(pObject), CLIENTS_GetUnitYInline(pObject), 0, 1);
    if (pMissile)
    {
        MISSILE_SetTargetY(pMissile, sub_00451F50(pObject));
    }
}

// 0x0046BD20
static inline int sub_0046BD20_GetChaosLevelLight(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    if (gbChaosLightEvent && gnLevelEffectTick == -1)
    {
        *pRed = 0xFF;
        *pGreen = 0x40;
        *pBlue = 0x30;
        return 0xA0;
    }
    return 0;
}

int __stdcall sub_M212_Emit_0046BD20(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    return sub_0046BD20_GetChaosLevelLight(pRed, pGreen, pBlue);
}

static inline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        return (unsigned int)SEED_RollRandomNumberForceInline(pSeed) % nMax;

    return SEED_RollRandomNumberForceInline(pSeed) & (nMax - 1);
}

// 0x0046C1A0
static void __stdcall sub_0046C1A0_SpawnMonsterInRoom(D2ActiveRoomStrc* pRoom, int nMonsterId, D2SeedStrc* pSeed)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nX = tCoords.nSubtileX;
    const int nY = tCoords.nSubtileY;
    const int nWidth = tCoords.nSubtileWidth - 1;
    const int nHeight = tCoords.nSubtileHeight - 1;

    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return;

    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
    D2MonStats2Txt* pMonStats2 = MONSTATS2_GetRecordInline(nMonStatsEx);
    if (!pMonStats2)
        return;

    const int nSize = pMonStats2->nSizeX;
    int nTry;
    int nPosX;
    int nPosY;
    for (nTry = 0; nTry < 10; ++nTry)
    {
        nPosX = nX + SEED_RollLimitedRandomNumberInline(pSeed, nWidth);
        nPosY = nY + SEED_RollLimitedRandomNumberInline(pSeed, nHeight);
        if (!COLLISION_CheckMaskWithSize(pRoom, nPosX, nPosY, nSize, 0x3F11))
            break;
    }

    if (nTry < 10)
        CUNIT_SpawnPresetUnit(nMonsterId, nPosX, nPosY, 1, 0);
}

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* room, int x, int y); // 0x00463740

static inline D2MonStats2Txt* GetMonStats2(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nEx >= 0 && nEx < sgptDataTables->nMonStats2TxtRecordCount)
            return &sgptDataTables->pMonStats2Txt[nEx];
    }
    return 0;
}

// 0x0046C320
void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2MonStats2Txt* pTxt = GetMonStats2(nMonsterId);
    if (!pTxt)
        return;

    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);
    for (int i = 0; i < 10; ++i)
    {
        unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        const int nX = tCoord.nX + (unsigned int)lSeed % 5 - 2;
        lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        const int nY = tCoord.nY + (unsigned int)lSeed % 5 - 2;
        pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        if (!COLLISION_CheckMaskWithSize(pRoom, nX, nY, pTxt->nSizeX, 0x3F11))
        {
            CUNIT_SpawnPresetUnit(nMonsterId, nX, nY, 1, 0);
            --nCount;
        }
        if (nCount <= 0)
            break;
    }
}

// 0x0046C460
void __fastcall sub_0046C460_PopulateRoom(D2ActiveRoomStrc* pRoom)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
        return;

    D2LevelsTxt* pLevel = DATATBLS_GetLevelsTxtRecord(nLevelId);
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int i = 0; i < 4; ++i)
    {
        if (pLevel->wCMon[i] < 0)
            break;

        if ((unsigned int)SEED_RollRandomNumberForceInline(pSeed) % 100 < (unsigned int)pLevel->wCPct[i])
        {
            const int nMonsterId = pLevel->wCMon[i];
            D2MonStatsTxt* pMonStats = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
            int nCount = ITEMS_RollLimitedRandomNumber(pSeed, pMonStats->nMaxGrp - pMonStats->nMinGrp) + pMonStats->nMinGrp;
            if (pLevel->wCAmt[i])
                nCount *= pLevel->wCAmt[i];

            while (nCount > 0)
            {
                sub_0046C1A0_SpawnMonsterInRoom(pRoom, pLevel->wCMon[i], pSeed);
                --nCount;
            }
        }
    }
}

#include "gen/data/Source/D2Client/Unknown_0046ACE0.inc"
