#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
struct D2UnitStrc;






typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg);                                // 0x004E2ED0
int __fastcall SKILLDESC_IsVineBeastMissile(D2UnitStrc* pUnit, void* pArg);                                  // 0x004F0F10
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection);                       // 0x006488A0
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit);                                                            // 0x00464810
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);          // 0x006439F0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
    {
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
    {
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static void MISSILE_SetPathDirectionInline(D2UnitStrc* pMissile, unsigned char nDirection)
{
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    PATH_SetDirection(pPath, nDirection);
    D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
}

// 0x004F04F0
static int __stdcall SKILLSEMON_CreateMissileFan(int nMissile, int nSkillId, int nSkillLevel, int nCount, D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.dwFlags = 3;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pInitFunc = SKILLDESC_InitCappedChargedPath;
    if (!ITEM_GetTargetPosition(pUnit, &tMissileParams.nX, &tMissileParams.nY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
// build: symbol ?gaFanOffsetX@* 0x006DBF50
        tMissileParams.nTargetX = gaFanOffsetX[i & 7];
// build: symbol ?gaFanOffsetY@* 0x006DBF70
        tMissileParams.nTargetY = gaFanOffsetY[i & 7];
        tMissileParams.nInitArg = i;
        MISSILE_CreateClientMissile(&tMissileParams);
    }
    return 1;
}

// 0x004F0590
static int __stdcall SKILLSEMON_CreateMissileRequest(int nMissile, int nSkillId, int nSkillLevel, int bNotify, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, nMissile, UNITS_GetXPositionInline(pUnit), UNITS_GetYPositionInline(pUnit), nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetPathDirectionInline(pMissile, UNITS_GetDirection(pUnit));
    if (bNotify)
    {
        CUNIT_MarkUnitDead(pMissile);
    }
    return 1;
}

int __fastcall sub_004F0650_CltSkillMissileFan(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004F0650

// 0x004F0F30
int __fastcall SKILLSEMON_CltSkillMonMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_VINEATTACK);
    if (!pSkill)
    {
// build: symbol ?gszSkillsEMonCpp@* 0x006DBF90
        SKILLS_AssignSkill(pUnit, SKILL_VINEATTACK, 1, 0, gszSkillsEMonCpp, 0x35C);
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_VINEATTACK);
        if (!pSkill)
        {
            return 0;
        }
    }

    const int nSkill = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillsEMonCpp, 0x364);
    nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    struct { int nX; int nY; int nValue; } tLocals;
    tLocals.nValue = SKILLS_GetParam1(pSkill);
    SKILLS_SetParam1(pSkill, tLocals.nValue + 1);
    tLocals.nX = SKILLS_GetParam2(pSkill);
    tLocals.nY = SKILLS_GetParam3(pSkill);
    int bFire = 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (tLocals.nValue >= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkill, nSkillLevel))
    {
        bFire = 1;
    }

    tLocals.nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkill, nSkillLevel);
    if (UNITS_GetDistanceToCoordinates(pUnit, tLocals.nX, tLocals.nY) >= tLocals.nValue)
    {
        bFire = 1;
    }

    int nMissile;
    switch (pUnit->dwAnimMode)
    {
    case 1:
        if (bFire)
        {
            D2UnitStrc* pTarget = D2Common_10407(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), SKILLDESC_IsVineBeastMissile, 0, 1);
            if (pTarget)
            {
// build: symbol ?MISSILE_CltMissileHit@* 0x004D2D70
                MISSILE_CltMissileHit(pTarget, 0, 0);
            }
        }
        nMissile = pSkillsTxtRecord->wCltMissileD;
        break;

    case 2:
    {
        const int nRoll = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2);
        nMissile = pSkillsTxtRecord->wCltMissileC + nRoll;
        break;
    }

    default:
        return 1;
    }

    if (bFire && nMissile > 0)
    {
        SKILLS_SetParam1(pSkill, 0);
        SKILLS_SetParam2(pSkill, CLIENTS_GetUnitX(pUnit));
        SKILLS_SetParam3(pSkill, CLIENTS_GetUnitY(pUnit));
        SKILLSEMON_CreateMissileRequest(nMissile, nSkill, nSkillLevel, 1, pUnit);
    }
    return 1;
}
