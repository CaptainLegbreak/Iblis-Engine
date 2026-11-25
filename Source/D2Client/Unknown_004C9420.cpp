#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Records.h"
#include "D2AnimData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

#pragma pack(push, 1)

#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900

void __fastcall sub_004BA840(void* pUnitSfx); // 0x004BA840

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

#define SKILLSFLAGINDEX_LOB 1

#define SKILLSFLAGINDEX_PRGSTACK 7

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc*,unsigned int,int,int); // 0x00646CA0

int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C390

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                  // 0x0045C3E0

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, int nDirection);                          // 0x006488A0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

extern const int gaMissileAroundOffsetX[8]; // 0x006DAEA8

extern const int gaMissileAroundOffsetY[8]; // 0x006DAE88

// 0x004C9420
void __fastcall SKILLS_EndLoopSoundSkill(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (pSkill)
    {
        int nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 1)
            SKILLS_SetFlags(pSkill, nFlags | 2);
    }
    sub_004BA840(UNITSND_FindUnitSfxInRange(pUnit, 0x9E3));
}

// 0x004C9460
int __fastcall SKILLS_GetFirstSkillParam(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = DATATBLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    return pSkillsTxt->dwParam[0];
}

// 0x004C9490
int __fastcall sub_004C9490_MissileAroundUnit(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!CUNIT_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    int nDirection;
    if (PATH_GetVelocity(pUnit->pDynamicPath))
    {
        nDirection = UNITS_GetDirection(pUnit) >> 3;
    }
    else
    {
        nDirection = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 8);
    }

    nDirection = (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) + (nDirection + 4) % 8 - 1) & 7;
    const int nX = CLIENTS_GetUnitX(pUnit) + gaMissileAroundOffsetX[nDirection];
    const int nY = CLIENTS_GetUnitY(pUnit) + gaMissileAroundOffsetY[nDirection];
    const int nBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nBonus > 0)
    {
        nMissile += SEED_RollLimitedRandomNumber(&pUnit->pSeed, nBonus);
    }

    MISSILE_SubmitOwnerRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    return 1;
}

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

// 0x004C95E0
int __fastcall MISSILE_SkillStartAtTargetPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = nX;
    tMissileParams.nTargetY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    PATH_SetType(pPath, 0xE);
    D2Common_10142(pPath, pMissile, 0);
    return 1;
}

// 0x004C96D0
int __fastcall sub_004C96D0(D2UnitStrc* pUnit,int nSkillId,int nSkillLevel)
{
 if(!SKILLS_GetSkillsTxtRecord(nSkillId)) return 0;
 const int nMissile=SKILLDESC_GetCltMissileId(pUnit,nSkillId);
 if(nMissile<0 || nMissile>=sgptDataTables->nMissilesTxtRecordCount) return 0;
 if(pUnit) pUnit->dwFlags|=0x40;
 D2UnitStrc* pTarget=CUNIT_GetPathTargetUnit(pUnit);
 if(!pTarget) return 0;
 D2MissileStrc params;
 memset(&params,0,sizeof(params));
 params.dwFlags=1;
 params.pOwner=pUnit;
 params.nX=CLIENTS_GetUnitX(pTarget);
 params.nY=CLIENTS_GetUnitY(pTarget);
 params.nSkill=nSkillId;
 params.nSkillLevel=nSkillLevel;
 params.nMissile=nMissile;
 D2UnitStrc* pMissile=MISSILE_CreateClientMissile(&params);
 if(!pMissile) return 0;
 MISSILE_SetTargetX(pMissile,!pTarget ? 6 : pTarget->dwUnitType);
 MISSILE_SetTargetY(pMissile,!pTarget ? -1 : pTarget->dwUnitId);
 return 1;
}

// 0x004C97C0
int __fastcall SKILLS_SpawnScatterMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nRadius = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    if (nRadius <= 0)
    {
        return 0;
    }

    const int nSpacing = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, 1);
    if (nSpacing <= 0)
    {
        return 0;
    }

    const int nRadiusSq = nRadius * nRadius;
    const int nRange = 2 * nRadius + 1;
    const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 18);
    const int nCount = nRadiusSq / (nSpacing * nSpacing) / (nRoll + 1);
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x2001;
    tParams.pOwner = pUnit;
    tParams.nMissile = nMissileId;
    tParams.nSkill = nSkillId;
    tParams.nSkillLevel = nSkillLevel;

    for (int i = 0; i < nCount; ++i)
    {
        const int nOffsetX = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRadius;
        const int nOffsetY = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nRange) - nRadius;
        if (nOffsetY * nOffsetY + nOffsetX * nOffsetX < nRadiusSq)
        {
            tParams.nX = nOffsetX + nX + 2;
            tParams.nY = nOffsetY + nY + 2;
            D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tParams);
            if (pMissile)
            {
                PATH_SetDirection(pMissile->pDynamicPath, SEED_RollLimitedRandomNumber(&pUnit->pSeed, 0x40));
            }
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004C9420.inc"
