#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
struct D2StaticPathStrc;
union D2SeedStrc;
struct D2SkillsTxt;
struct D2UnitFindArgStrc;
struct D2MissileStrc;








extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);


unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710
void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_PROGRESSIVE = 2,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __fastcall SKILLSMON_StartStateList(D2UnitStrc* pUnit, int nSkillId, int nArg); // 0x004F2450
extern int gaMissileRingX[]; // 0x006DBFE8
extern int gaMissileRingY[]; // 0x006DC0E8
void __fastcall SKILLDESC_MissileInit(D2UnitStrc* pMissile, int nArg); // 0x004F2AC0
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40
int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20
int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
extern int gaMissileRing2X[]; // 0x006DC228
extern int gaMissileRing2Y[]; // 0x006DC328
void __fastcall SKILLDESC_InitCurvingMissilePath(D2UnitStrc* pMissile, int nArg); // 0x004F2BE0
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed); // 0x00650E50
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 nValue = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5u;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    return (unsigned int)nValue;
}

// 0x004F1430
int __fastcall sub_004F1430_MissilesOnUnitsInRadius(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_BAALCORPSEEXPLODE);
    int nSize;
    if (!pSkillsTxtRecord)
    {
        nSize = 0;
    }
    else if (nSkillLevel <= 0)
    {
        nSize = 0;
    }
    else
    {
        nSize = (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5] + pSkillsTxtRecord->dwParam[4];
    }

    const int nX = UNITS_GetUnitXPosition(pUnit);
    const int nY = UNITS_GetUnitYPosition(pUnit);

    D2UnitFindArgStrc tUnitFindArg;
    memset(&tUnitFindArg, 0, sizeof(tUnitFindArg));
    tUnitFindArg.nFlags = 0x3002;
    tUnitFindArg.pUnit = pUnit;
    tUnitFindArg.nX = nX;
    tUnitFindArg.nY = nY;
    tUnitFindArg.nSize = nSize;

    D2UnitFindDataStrc tUnitFindData;
    UNITFINDS_InitializeUnitFindData(0, &tUnitFindData, UNITS_GetRoom(pUnit), nX, nY, nSize, 0, &tUnitFindArg);
    tUnitFindData.nFlags = tUnitFindArg.nFlags;
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&tUnitFindData);

    for (int i = 0; i < tUnitFindData.nIndex; ++i)
    {
        D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, 0x24B, UNITS_GetUnitXPosition(tUnitFindData.pUnitsArray[i]), UNITS_GetUnitYPosition(tUnitFindData.pUnitsArray[i]), nSkillId, nSkillLevel);
        if (pMissile)
        {
            int nFrames = MISSILE_GetTotalFrames(pMissile);
            nFrames += SEED_RollRandomNumber(&pUnit->pSeed) % 20 - 10;
            MISSILE_SetTotalFrames(pMissile, nFrames);
            MISSILE_SetCurrentFrame(pMissile, nFrames);
        }
    }

    UNITFINDS_FreeUnitFindData(&tUnitFindData);
    return 1;
}

// 0x004F1640
int __fastcall sub_004F1640_AuraStateOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wCltOverlayA < 0 || pSkillsTxtRecord->wCltOverlayA >= sgptDataTables->nOverlayTxtRecordCount)
    {
        return 0;
    }

    int nOverlay = pSkillsTxtRecord->wCltOverlayA;
    if (pSkillsTxtRecord->wCltOverlayB >= 0 && pSkillsTxtRecord->wCltOverlayB < sgptDataTables->nOverlayTxtRecordCount
        && STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        nOverlay = pSkillsTxtRecord->wCltOverlayB;
    }

    GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    return 1;
}

static inline unsigned int SEED_RollRandomNumber_Spray(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Spray(int nSkillId)
{
    return (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
}

static inline int CLIENTS_GetUnitX_Spray(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitY_Spray(D2UnitStrc* pUnit)
{
    int nResult;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nResult = pUnit->pStaticPath->nYPos;
        break;
    default:
        if (pUnit->pDynamicPath)
            nResult = PATH_GetYPosition(pUnit->pDynamicPath);
        else
            nResult = 0;
        break;
    }
    return nResult;
}

// 0x004F1A30
static void __stdcall SKILLDESC_CreateSprayMissile(D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    const int nIndex = SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 7;
    const int nUnitX = CLIENTS_GetUnitX_Spray(pUnit);
    const int nUnitY = CLIENTS_GetUnitY_Spray(pUnit);
// build: symbol ?gaSprayOffsetX@* 0x006DBFA8
    const int nOffsetX = gaSprayOffsetX[nIndex];
// build: symbol ?gaSprayOffsetY@* 0x006DBFC8
    const int nOffsetY = gaSprayOffsetY[nIndex];
    const int nX = nUnitX + nOffsetX;
    const int nY = nUnitY + nOffsetY;

    int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0)
    {
        return;
    }

    if (pSkillsTxt->wCltMissileB >= 0)
    {
        if (pSkillsTxt->wCltMissileC >= 0)
        {
            switch (SEED_RollRandomNumber_Spray(&pUnit->pSeed) % 3)
            {
            case 0:
                nMissile = pSkillsTxt->wCltMissileB;
                break;

            case 1:
                nMissile = pSkillsTxt->wCltMissileC;
                break;
            }
        }
        else if (!(SEED_RollRandomNumber_Spray(&pUnit->pSeed) & 1))
        {
            nMissile = pSkillsTxt->wCltMissileB;
        }
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    tMissile.pOwner = pUnit;
    tMissile.nMissile = nMissile;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nTargetX = nOffsetY;
    tMissile.nTargetY = -nOffsetX;

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissile);
    if (!pMissile)
    {
        return;
    }

    const int nSpread = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[1], nSkillId, nSkillLevel);
    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, SEED_RollLimitedRandomNumber(&pUnit->pSeed, nSpread));
    MISSILE_SetTargetX(pMissile, CLIENTS_GetUnitX_Spray(pUnit));
    MISSILE_SetTargetY(pMissile, CLIENTS_GetUnitY_Spray(pUnit));
}

// 0x004F1C80
int __fastcall sub_004F1C80_SkillCltDoSpray(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord_Spray(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int bInTown = !pRoom || DUNGEON_IsRoomInTown(pRoom);
    if (pSkillsTxt->wPrgSound > 0)
    {
        void* pUnitSfx = UNITSND_FindUnitSfxInRange(pUnit, pSkillsTxt->wPrgSound);
        if (bInTown)
        {
            if (pUnitSfx)
            {
                sub_004BA790_ReleaseUnitSfx(pUnitSfx, pUnit, 1);
            }
        }
        else if (!pUnitSfx)
        {
            sub_004B9A00(pSkillsTxt->wPrgSound, pUnit, 0, 0, 0);
        }
    }

    if (bInTown)
    {
        return 0;
    }

    const int nSkill = nSkillId;
    const int nPasses = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[0], nSkill, nSkillLevel);
    for (int i = 0; i < nPasses; ++i)
    {
        SKILLDESC_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        SKILLDESC_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
        SKILLDESC_CreateSprayMissile(pSkillsTxt, nSkill, nSkillLevel, pUnit);
    }

    return 1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_J03(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F1F20
int __fastcall sub_004F1F20_FireTwinCltMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_J03(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 1;
    tMissile.pOwner = pUnit;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;

    if (pSkillsTxtRecord->wCltMissileA >= 0 && pSkillsTxtRecord->wCltMissileA < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissile.nMissile = pSkillsTxtRecord->wCltMissileA;
        MISSILE_CreateClientMissile(&tMissile);
    }

    if (pSkillsTxtRecord->wCltMissileB >= 0 && pSkillsTxtRecord->wCltMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissile.nMissile = pSkillsTxtRecord->wCltMissileB;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissile);
        if (pMissile)
        {
            MISSILE_SetTargetX(pMissile, pUnit->dwInitSeed);
        }
    }

    return 1;
}

// 0x004F2060
int __fastcall sub_004F2060_CheckTargetSetFlag(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int bOk = 0;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        switch (pTarget->dwUnitType)
        {
        case UNIT_PLAYER:
        case UNIT_MONSTER:
            bOk = CUNIT_IsHostileTo(pUnit, pTarget);
            break;
        }
    }

    if (!bOk)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return 1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F2260
int __fastcall sub_004F2260_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PROGRESSIVE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE & 7]))
    {
        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
    }

    if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
        }

        int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        nIndex = D2_MIN(D2_MAX(nIndex, 1), 3);
        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[nIndex - 1], nSkillId, nSkillLevel);
    }

    return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
}

// 0x004F2590
int __fastcall sub_004F2590_StartStateListEntry(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    return SKILLSMON_StartStateList(pUnit, nSkillId, nArg);
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004F2B20
static void __stdcall sub_004F2B20_CreateMissileRing(D2UnitStrc* pUnit, int nMissile, int nX, int nY, int nSkillLevel, int nCount, unsigned int nInitSeed, int nSkillId)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nInitSeed);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 3;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pInitFunc = SKILLDESC_MissileInit;
    for (int i = 0; i < 64; i += nCount)
    {
        tMissileParams.nTargetX = gaMissileRingX[i];
        tMissileParams.nTargetY = gaMissileRingY[i];
        tMissileParams.nInitArg = SEED_RollRandomNumberInline(&tSeed);
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        MISSILE_SetTargetX(pMissile, SKILLDESC_GetSkillParamTwo(nSkillId) + 1);
    }
}

// 0x004F2F20
int __fastcall sub_004F2F20_CltSkillMissileRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    const unsigned int nInitSeed = pUnit->dwInitSeed;
    const int nX = CLIENTS_GetUnitX(pTarget);
    const int nY = CLIENTS_GetUnitY(pTarget);
    sub_004F2B20_CreateMissileRing(pUnit, nMissile, nX, nY, nSkillLevel, nCount, nInitSeed, nSkillId);
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004F1430.inc"

// 0x004F2DD0
static void __stdcall sub_004F2DD0_CreateMissileRing2(D2UnitStrc* pUnit, int nMissile, int nX, int nY, int nSkillLevel, int nCount, unsigned int nInitSeed, int nSkillId)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nInitSeed);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 3;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pInitFunc = SKILLDESC_InitCurvingMissilePath;
    for (int i = 0; i < 64; i += nCount)
    {
        tMissileParams.nTargetX = gaMissileRing2X[i];
        tMissileParams.nTargetY = gaMissileRing2Y[i];
        tMissileParams.nInitArg = SEED_RollRandomNumberInline(&tSeed);
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        MISSILE_SetTargetX(pMissile, SKILLDESC_GetSkillParamTwo(nSkillId) + 1);
    }
}

// 0x004F2FE0
int __fastcall sub_004F2FE0_CltSkillMissileRing2(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    const unsigned int nInitSeed = pUnit->dwInitSeed;
    const int nX = CLIENTS_GetUnitX(pTarget);
    const int nY = CLIENTS_GetUnitY(pTarget);
    sub_004F2DD0_CreateMissileRing2(pUnit, nMissile, nX, nY, nSkillLevel, nCount, nInitSeed, nSkillId);
    return 1;
}

// 0x004F3290
static void __stdcall sub_004F3290_CreateMissileBurst(D2UnitStrc* pUnit, int nX, int nY, int nSkillId, int nSkillLevel, int nMissile, unsigned int nSeed, int nCount)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nSeed);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.pOwner = pUnit;
    tMissileParams.dwFlags = 3;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetX = SEED_RollRandomNumberInline(&tSeed) % 40 - 20;
        tMissileParams.nTargetY = SEED_RollRandomNumberInline(&tSeed) % 40 - 20;
        if (!tMissileParams.nTargetX && !tMissileParams.nTargetY)
        {
            tMissileParams.nTargetX = 20;
        }

        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(&tSeed));
            MISSILE_SetTargetY(pMissile, ((unsigned short)tMissileParams.nTargetY << 16) + (unsigned short)tMissileParams.nTargetX);
        }
    }
}

// 0x004F3430
int __fastcall sub_004F3430_CltSkillMissileBurst(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecordInline(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (!nCount)
    {
        return 0;
    }

    sub_004F3290_CreateMissileBurst(pUnit, nX, nY, nSkillId, nSkillLevel, nMissile, nX, nCount);
    return 1;
}

// 0x004F3870
int __fastcall sub_004F3870_SetTargetPosParams(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, CLIENTS_GetUnitX(pTarget));
    SKILLS_SetParam2(pSkill, CLIENTS_GetUnitY(pTarget));
    return 1;
}
