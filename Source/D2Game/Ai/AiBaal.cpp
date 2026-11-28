#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2GameStrc.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2GameAux.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SkillsTxt;

struct D2MonStatsTxt;

struct D2MonsterDataStrc;


union D2SeedStrc;


extern D2DataTablesStrc* sgptDataTables; // 0x00744304


int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC480


#include "D2GameFuncs.h"


extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20


static int __stdcall AI_GetRandomArrayIndex(int* pArray, int nArraySize, D2UnitStrc* pUnit);

#define PATHTYPE_TOWARD 2

struct D2StaticPathStrc;

struct D2TargetNodeStrc;


struct D2AiCmdStrc;

static int __stdcall AIBAAL_GetUberTargetScore(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiCmdStrc* pArgs);


static D2UnitStrc* __stdcall AIBAAL_GetUberTarget(D2GameStrc* pGame, int* pMax, int* pCount, D2AiCmdStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*), D2UnitStrc* pUnit); // 0x005FBDD0


int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005DC380


static int AIBAAL_IsDangerousSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill);

static int AI_CheckSpecialSkillsOnPrimeEvil(D2UnitStrc* pUnit);

static int __stdcall AIBAAL_RollRandomAiParamForNonCollidingUnit(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, int bInCloseRange, int nMax); // 0x005FC450

static int __stdcall AIBAAL_RollRangedAiParam(D2GameStrc*, D2UnitStrc*, int, int, int, D2UnitStrc*);

int __stdcall PATH_GetY(void* pPath); // 0x00648900

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nId); // 0x00552F60



static int __stdcall AIBAAL_RollRandomAiParam(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, D2UnitStrc*, int, int, D2AiCmdStrc*);


struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;


unsigned int __stdcall UNITS_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

struct D2SpawnAreaStrc;

struct D2UnitStrc;

extern const char gszAiBaal[]; // 0x006E3580




int __fastcall MONSTERREGION_FindSpawnLocation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2SpawnAreaStrc* pArea, int nClassId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc*,D2UnitStrc*); // 0x00553540

void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,int); // 0x00553380

void __fastcall AIBAAL_CountLivingMinions(D2UnitStrc*,void*,void*); // 0x005FC830

void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc*,void*,void*,void(__fastcall*)(D2UnitStrc*,void*,void*)); // 0x0058F380


void __fastcall AIGENERAL_AllocMinionList(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0058F100

void __stdcall MONSTERS_GetMinionSpawnInfo(D2UnitStrc*,int*,int*,int*,int*,int,int(__fastcall*)(D2UnitStrc*)); // 0x0063EFA0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*,int,int); // 0x00463740

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

static bool __stdcall AIBAAL_SummonClone(D2GameStrc*,D2UnitStrc*,D2AiControlStrc*); // 0x005FC860

struct D2GameStrc;

static int __stdcall AIBAAL_RollRangedAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, D2UnitStrc* pUnit);



static int __stdcall AIBAAL_RollMeleeAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int bNotCollidingWithWall, D2UnitStrc* pUnit);

static int __stdcall AIBAAL_RollRandomAiParam(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nMax, int nCount, D2AiCmdStrc* pAiCmd);

void __fastcall AIBAAL_MainSkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nParam, D2AiCmdStrc* pAiCmd);

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005FBB00
static int __stdcall AIBAAL_GetUberTargetScore(D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiCmdStrc* pArgs)
{
    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);

    int nDistanceWeight = 0;
    if (pArgs && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pUnit, pArgs->nCmdParam[1], pArgs->nCmdParam[2]) > 75 && AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pArgs->nCmdParam[1], pArgs->nCmdParam[2]) < 75)
    {
        nDistanceWeight = 100;
    }

    const int nDamageResist = STATLIST_UnitGetStatValue(pTarget, STAT_DAMAGERESIST, 0);
    const int nFireResist = STATLIST_UnitGetStatValue(pTarget, STAT_FIRERESIST, 0);
    const int nLightningResist = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTRESIST, 0);
    const int nMagicResist = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICRESIST, 0);
    const int nColdResist = STATLIST_UnitGetStatValue(pTarget, STAT_COLDRESIST, 0);
    const int nResistWeight = (nFireResist + nColdResist + nLightningResist + 4 * (nDamageResist + 2 * nMagicResist)) / 15;

    const int nMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAXDAMAGE, 0);
    const int nFireMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_FIREMAXDAM, 0);
    const int nLightningMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_LIGHTMAXDAM, 0);
    const int nMagicMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_MAGICMAXDAM, 0);
    const int nColdMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_COLDMAXDAM, 0);
    const int nPoisonMaxDamage = STATLIST_UnitGetStatValue(pTarget, STAT_POISONMAXDAM, 0) >> 8;
    const int nDamageWeight = (nMaxDamage + nFireMaxDamage + nLightningMaxDamage + nMagicMaxDamage + nColdMaxDamage + nPoisonMaxDamage) / 2;

    const int nColdStateWeight = STATES_CheckState(pTarget, STATE_COLD) ? 100 : 0;
    const int nLifePercentageWeight = UNITS_GetCurrentLifePercentage(pTarget) < 20 ? 100 : 0;

    int nLeftSkillLevel;
    int nRightSkillLevel;
    int nLeftSkillAttackRank;
    int nRightSkillAttackRank;
    nLeftSkillLevel = 0;
    nRightSkillLevel = 0;
    nLeftSkillAttackRank = 0;
    nRightSkillAttackRank = 0;

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pTarget);
    if (pLeftSkill)
    {
        nLeftSkillLevel = SKILLS_GetSkillLevel(pTarget, pLeftSkill, 1);
        nLeftSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\Ai\\AiBaal.cpp", 0x75))->nAttackRank;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pTarget);
    if (pRightSkill)
    {
        nRightSkillLevel = SKILLS_GetSkillLevel(pTarget, pRightSkill, 1);
        nRightSkillAttackRank = SKILLS_GetSkillsTxtRecord(SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\Ai\\AiBaal.cpp", 0x7B))->nAttackRank;
    }

    const int nAttackRankWeight = (nLeftSkillLevel * nLeftSkillAttackRank + nRightSkillLevel * nRightSkillAttackRank) / 4;

    int nCollisionRangeWeight = 0;
    if (bInMeleeRange)
    {
        nCollisionRangeWeight = 100;
    }
    else if (AIUTIL_HasClearMissilePath(pUnit, pTarget))
    {
        nCollisionRangeWeight = 75;
    }

    if (pTarget && pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pTarget->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        if (pMonStatsTxtRecord->nThreat <= 1)
        {
            return 0;
        }
    }

    int nTotalScore = (nResistWeight + 5 * (nCollisionRangeWeight + nDistanceWeight) + 2 * (nDamageWeight + nAttackRankWeight + 2 * nColdStateWeight) + 3 * nLifePercentageWeight) / 22;
    if (!nTotalScore)
    {
        nTotalScore = 1;
    }

    return nTotalScore;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005FBDD0
static D2UnitStrc* __stdcall AIBAAL_GetUberTarget(D2GameStrc* pGame, int* pMax, int* pCount, D2AiCmdStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*), D2UnitStrc* pUnit)
{
    D2_ASSERT(pfCull, 0x9E);

    D2UnitStrc* pTarget = 0;
    int nMax = 0;
    int nCount = 0;
    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* ptTargetNode = *ppTargetNode;
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    const unsigned char nAct = pUnit->nAct;

    for (int i = 0; i < 8; ++i)
    {
        if (ptTargetNode)
        {
            D2_ASSERT(ptTargetNode->hUnit && ptTargetNode->hUnit->dwUnitType == UNIT_PLAYER, 0xB3);
            D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
                }
                else
                {
                    nCurrent = 0;
                }

                while (1)
                {
                    if (nMax < nCurrent)
                    {
                        nMax = nCurrent;
                        pTarget = pTargetUnit;
                    }

                    ptTargetNode = ptTargetNode->pNext;
                    ++nCount;

                    if (!ptTargetNode)
                    {
                        break;
                    }

                    pTargetUnit = ptTargetNode->hUnit;
                    nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
                }
            }
        }

        ptTargetNode = *++ppTargetNode;
    }

    while (ptTargetNode)
    {
        D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
            if (nMax < nCurrent)
            {
                nMax = nCurrent;
                pTarget = pTargetUnit;
            }
            ++nCount;
        }

        ptTargetNode = ptTargetNode->pNext;
    }

    ptTargetNode = ppTargetNode[1];

    D2UnitStrc* pTemp = 0;
    int nTemp = 0;
    if (ptTargetNode)
    {
        do
        {
            D2UnitStrc* pTargetUnit = ptTargetNode->hUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = AIBAAL_GetUberTargetScore(pUnit, pTargetUnit, pArgs);
                if (nTemp < nCurrent)
                {
                    nTemp = nCurrent;
                    pTemp = pTargetUnit;
                }
            }

            ptTargetNode = ptTargetNode->pNext;
        }
        while (ptTargetNode);

        if (pTemp && AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTemp, nX, nY) < 5 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            PATH_SetPathTarget(pPath, pTarget);
            PATH_SetType(pPath, PATHTYPE_TOWARD);
            D2Common_10142(pPath, pUnit, 0);

            if (!PATH_GetNumberOfPathPoints(pPath))
            {
                pTarget = pTemp;
                nMax = nTemp;
            }
        }
    }

    *pCount = nCount;
    *pMax = nMax;

    return pTarget;
}

// 0x005FC000
int __fastcall AIBAAL_CullPotentialTargets(D2UnitStrc* pBaal, D2UnitStrc* pTarget)
{
    D2_ASSERT(pBaal, 285);
    D2_ASSERT(pTarget, 286);

    if (pBaal->nAct != pTarget->nAct)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pTarget, CLIENTS_GetUnitX(pBaal), CLIENTS_GetUnitY(pBaal)) < 1020;
}

// 0x005FC070
static int AIBAAL_IsDangerousSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\Ai\\AiBaal.cpp", 0x131);
    if (nSkillId == SKILL_BLIZZARD || nSkillId == SKILL_METEOR)
    {
        return 1;
    }

    if (nSkillId == SKILL_FIREWALL)
    {
        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 3)
        {
            return 1;
        }
    }
    else if (nSkillId == SKILL_IMMOLATIONARROW)
    {
        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 7)
        {
            return 1;
        }
    }

    return 0;
}

static inline int AIBAAL_GetSkillId_Inline(D2SkillStrc* pSkill)
{
    return SKILLS_GetSkillIdFromSkill(pSkill, ".\\Ai\\AiBaal.cpp", 0x131);
}

// 0x005FC0C0
static int AI_CheckSpecialSkillsOnPrimeEvil(D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetRightSkill(pUnit);
    if (pSkill)
    {
        const int nSkillId = AIBAAL_GetSkillId_Inline(pSkill);
        if (nSkillId == SKILL_BLIZZARD || nSkillId == SKILL_METEOR)
        {
            return 1;
        }

        if (nSkillId == SKILL_FIREWALL)
        {
            if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 3)
            {
                return 1;
            }
        }
        else if (nSkillId == SKILL_IMMOLATIONARROW)
        {
            if (SKILLS_GetSkillLevel(pUnit, pSkill, 1) > 7)
            {
                return 1;
            }
        }
    }

    return AIBAAL_IsDangerousSkill(pUnit, UNITS_GetLeftSkill(pUnit));
}

static inline unsigned int AIBAAL_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int AIBAAL_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    int nResult;
    if (nMax <= 0)
        nResult = 0;
    else if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        nResult = AIBAAL_RollSeed_Inline(pSeed) % nMax;
    else
        nResult = AIBAAL_RollSeed_Inline(pSeed) & (nMax - 1);
    return nResult;
}

static inline int AIBAAL_GetRandomArrayIndex_Inline(int* pArray, int nArraySize, D2UnitStrc* pUnit, int nDefaultValue)
{
    int nSum = 0;
    int* pWeight = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nSum += *pWeight;
        ++pWeight;
    }

    const int nRand = AIBAAL_RollLimited_Inline(&pUnit->pSeed, nSum);

    int nThreshold = 0;
    pWeight = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nThreshold += *pWeight;
        if (nRand < nThreshold)
        {
            return i;
        }
        ++pWeight;
    }

    return nDefaultValue;
}

static inline unsigned __int64 AIBAAL_RollSeed_M282Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

static inline unsigned int AIBAAL_RollLimited_M282Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return (unsigned int)AIBAAL_RollSeed_M282Inline(pSeed) % nMax;
    }

    return AIBAAL_RollSeed_M282Inline(pSeed) & (nMax - 1);
}

// 0x005FC130
static int __stdcall AI_GetRandomArrayIndex(int* pArray, int nArraySize, D2UnitStrc* pUnit)
{
    int nSum = 0;
    int* pSum = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nSum += *pSum;
        ++pSum;
    }

    const int nRand = AIBAAL_RollLimited_M282Inline(&pUnit->pSeed, nSum);

    int nThreshold = 0;
    int* pPick = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nThreshold += *pPick;
        if (nRand < nThreshold)
        {
            return i;
        }
        ++pPick;
    }

    return 1;
}

int __fastcall GetRandomArrayIndexContext(D2UnitStrc* pUnit, int nArraySize, int* pArray)
{
    return AI_GetRandomArrayIndex(pArray, nArraySize, pUnit);
}

static inline int AIBAAL_GetRandomArrayIndex_M282Inline(int* pArray, int nArraySize, D2UnitStrc* pUnit, int nDefaultValue)
{
    int nSum = 0;
    int* pSum = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nSum += *pSum;
        ++pSum;
    }

    const int nRand = AIBAAL_RollLimited_M282Inline(&pUnit->pSeed, nSum);

    int nThreshold = 0;
    int* pPick = pArray;
    for (int i = 0; i < nArraySize; ++i)
    {
        nThreshold += *pPick;
        if (nRand < nThreshold)
        {
            return i;
        }
        ++pPick;
    }

    return nDefaultValue;
}

// 0x005FC1C0
static int __stdcall AIBAAL_RollMeleeAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int bNotCollidingWithWall, D2UnitStrc* pUnit)
{
    int aiParams[16] = { 0, 50, 0, 0, 0, 0, 0, 0, 20, 30, 150, 10, 10, 70, 40, 0 };

    if (!pGame->nDifficulty)
    {
        aiParams[1] = 75;
        aiParams[13] = 45;
    }

    if (UNITS_GetCurrentLifePercentage(pTarget) < 33)
    {
        aiParams[10] += 50;
    }

    aiParams[1] += 100 - UNITS_GetCurrentLifePercentage(pUnit);

    if (STATES_CheckState(pTarget, STATE_COLD))
    {
        aiParams[8] = 0;
        aiParams[13] = 0;
        aiParams[11] = 0;
    }

    if (!bNotCollidingWithWall)
    {
        aiParams[11] = 0;
        aiParams[13] = 0;
        aiParams[12] = 0;
    }

    return AIBAAL_GetRandomArrayIndex_M282Inline(aiParams, 16, pUnit, 1);
}

// 0x005FC300
static int __stdcall AIBAAL_RollRangedAiParam(D2GameStrc* pGame, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, D2UnitStrc* pUnit)
{
    int aiParams[16] = { 0, 100, 20, 20, 20, 0, 20, 0, 80, 70, 0, 0, 0, 0, 0, 0 };
    if (!pGame->nDifficulty)
    {
        aiParams[1] = 125;
    }

    if (nCount < 2)
    {
        aiParams[2] = 45;
        aiParams[10] = 25;
    }

    aiParams[1] += 100 - UNITS_GetCurrentLifePercentage(pUnit);

    if (AI_CheckSpecialSkillsOnPrimeEvil(pTarget) && !bInMediumRange)
    {
        aiParams[14] = 50;
        aiParams[13] = 50;
    }
    else if (bInMediumRange)
    {
        aiParams[2] = 0;
        aiParams[6] = 0;
        aiParams[3] = 35;
        aiParams[11] = 25;
        aiParams[13] = 25;
    }

    if (bInFarRange)
    {
        aiParams[5] = 60;
    }

    return AIBAAL_GetRandomArrayIndex_Inline(aiParams, 16, pUnit, 1);
}

// 0x005FC450
static int __stdcall AIBAAL_RollRandomAiParamForNonCollidingUnit(D2GameStrc* pGame, D2AiControlStrc* pAiControl, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nCount, int bInMediumRange, int bInFarRange, int bInCloseRange, int nMax)
{
    int aiParams[16] = { 0, 100, 5, 5, 5, 0, 5, 0, 40, 40, 0, 70, 80, 60, 20, 0 };
    if (!pGame->nDifficulty)
    {
        aiParams[1] = 125;
        aiParams[13] = 40;
    }

    aiParams[15] = 10 * (2 - pAiControl->dwAiParam[1]);
    if (aiParams[15] < 0)
    {
        aiParams[15] = 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance > 35)
    {
        aiParams[6] = 15;
        aiParams[13] = 0;
    }

    aiParams[1] += 100 - UNITS_GetCurrentLifePercentage(pUnit);
    if (nDistance > 25)
    {
        aiParams[14] = 30;
        aiParams[11] = 0;
    }

    if (nCount < 2)
    {
        aiParams[11] -= 10;
    }

    if (nCount > 3)
    {
        aiParams[13] += 25;
    }

    if (nMax > 60)
    {
        aiParams[8] = 70;
    }

    D2PlayerCountBonusStrc playerCountBonus;
    MONSTER_GetPlayerCountBonus(pGame, &playerCountBonus, UNITS_GetRoom(pUnit), pUnit);

    if (nCount < 2 && playerCountBonus.nDifficulty < 2)
    {
        aiParams[8] = 0;
    }

    if (AI_CheckSpecialSkillsOnPrimeEvil(pTarget) && !bInMediumRange)
    {
        aiParams[6] += 30;
        aiParams[11] += 10;
        aiParams[14] += 15;
    }
    else if (bInMediumRange)
    {
        aiParams[6] += 25;
        aiParams[14] += 35;
        aiParams[2] = 0;
        aiParams[3] = 25;
    }

    if (bInFarRange)
    {
        aiParams[5] = 60;
    }

    if (bInCloseRange)
    {
        aiParams[7] = 0;
    }

    return AIBAAL_GetRandomArrayIndex_M282Inline(aiParams, 16, pUnit, 1);
}

static inline int AIBAAL_GetUnitX_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return ((int*)pUnit->pDynamicPath)[3];
    default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int AIBAAL_GetUnitY_Inline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return ((int*)pUnit->pDynamicPath)[4];
    default: return pUnit->pDynamicPath ? PATH_GetY(pUnit->pDynamicPath) : 0;
    }
}


// 0x005FC630
static int __stdcall AIBAAL_RollRandomAiParam(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nMax, int nCount, D2AiCmdStrc* pAiCmd)
{
    if (pAiControl->dwAiParam[0]) return pAiControl->dwAiParam[0];
    if (!pTarget)
    {
        if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), AIBAAL_GetUnitX_Inline(pUnit), AIBAAL_GetUnitY_Inline(pUnit), 2, 64))
            return 4;
        return 8 * ((int)(AIBAAL_RollSeed_Inline(&pUnit->pSeed) % 100) < 8) + 1;
    }
// build: symbol ?SUNIT_GetGameFromUnit@* 0x00554010
    if (!pGame) pGame = SUNIT_GetGameFromUnit(pUnit);
    int bInCloseRange = 0;
    if ((!pTarget ? 6 : pTarget->dwUnitType) == 0)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, PLAYER_GetUniqueIdFromPlayerData(pTarget));
        if (pObject && DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject)) == LEVEL_THEWORLDSTONECHAMBER)
        {
            if (!pAiCmd || UNITS_GetDistanceToCoordinates(pObject, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]) < 75)
                bInCloseRange = 1;
        }
    }
    int bInMediumRange = 0;
    int bInFarRange = 0;
    if (pAiCmd)
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_HalfUnitSize(pTarget, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]);
        if (nDistance > 75) bInMediumRange = 1;
        if (nDistance > 100) bInFarRange = 1;
    }
    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    const int bNotCollidingWithWall = AIUTIL_HasClearMissilePath(pUnit, pTarget);
    if (bInMeleeRange)
        return AIBAAL_RollMeleeAiParam(pGame, pTarget, bNotCollidingWithWall, pUnit);
    if (bNotCollidingWithWall)
        return AIBAAL_RollRandomAiParamForNonCollidingUnit(pGame, pAiControl, pUnit, pTarget, nCount, bInMediumRange, bInFarRange, bInCloseRange, nMax);
    return AIBAAL_RollRangedAiParam(pGame, pTarget, nCount, bInMediumRange, bInFarRange, pUnit);
}

// 0x005FC830
void __fastcall AIBAAL_CountLivingMinions(D2UnitStrc* pUnit, void* ppUnitArg, void* pCounterArg)
{
    D2UnitStrc** ppUnit = (D2UnitStrc**)ppUnitArg;
    int* pCounter = (int*)pCounterArg;

    if (pUnit != *ppUnit && pUnit && pUnit->dwAnimMode != MONMODE_DEATH && pUnit->dwAnimMode != MONMODE_DEAD)
    {
        ++*pCounter;
    }
}

static inline int UnitX(D2UnitStrc* u) {
 switch(u->dwUnitType) {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return ((D2StaticPathStrc*)u->pDynamicPath)->nXPos;}
 if (u->pDynamicPath)
     return PATH_GetXPosition((D2DynamicPathStrc*)u->pDynamicPath);
 return 0;
}

static inline int UnitY(D2UnitStrc* u) {
 switch(u->dwUnitType) {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return ((D2StaticPathStrc*)u->pDynamicPath)->nYPos;}
 return u->pDynamicPath?PATH_GetYPosition((D2DynamicPathStrc*)u->pDynamicPath):0;
}

static inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed) {
 unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
 pSeed->lSeed = lSeed;
 return lSeed;
}

static inline unsigned __int64 SEED_RollNextHL_Inline(D2SeedStrc* pSeed, unsigned __int64 lPrev) {
 const unsigned __int64 lSeed = (lPrev >> 32) + 0x6AC690C5i64 * (unsigned int)lPrev;
 pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
 pSeed->nLowSeed = (unsigned int)lSeed;
 return lSeed;
}

// build: symbol ?CUNIT_ValidateMonsterId@* 0x00463900
int __fastcall CUNIT_ValidateMonsterId(int nMonsterId)
{
 if(nMonsterId<0 || nMonsterId>=sgptDataTables->nMonStatsTxtRecordCount) return -1;
 return nMonsterId;
}

// 0x005FC860
static bool __stdcall AIBAAL_SummonClone(D2GameStrc* game,D2UnitStrc* unit,D2AiControlStrc* control)
{
 int living=0;
 D2UnitStrc* temp=unit;
 AIGENERAL_ExecuteCallbackOnMinions(unit,&temp,&living,AIBAAL_CountLivingMinions);
 if(living)return false;
 D2UnitStrc* owner=SUNIT_GetOwner(game,unit);
 if(!owner || SUNIT_IsDead(owner)) {
 int monsterId=CUNIT_ValidateMonsterId(570);
 int x,y;
 int mode=1;
 MONSTERS_GetMinionSpawnInfo(unit,&monsterId,&x,&y,&mode,game->nDifficulty,0);
 D2UnitStrc* target=SUNIT_GetTargetUnit(game,unit);
 int baseX=target?UnitX(target):UnitX(unit);
 int baseY;
 if(target) baseY=UnitY(target); else baseY=UnitY(unit);
 D2SeedStrc* seed=&unit->pSeed;
 unsigned __int64 lSeed=SEED_RollRandomNumber(seed);
 x=baseX+(unsigned int)lSeed%24-12;
 lSeed=SEED_RollNextHL_Inline(seed,lSeed);
 y=baseY+(unsigned int)lSeed%24-12;
 D2ActiveRoomStrc* room=sub_00463740_FindRoomAtPoint(UNITS_GetRoom(unit),x,y);
 if(room) {

 sub_00463740_FindRoomAtPoint(UNITS_GetRoom(unit),x,y);
 D2UnitStrc* clone=D2GAME_SpawnMonster(game,room,x,y,monsterId,mode,-1,0);
 if(clone) {
 clone->dwFlags|=0x04020000;
 AITACTICS_Idle(game,clone,15);
 AIGENERAL_SetOwnerData(game,unit,!unit?-1:unit->dwUnitId,!unit?6:unit->dwUnitType,1,0);
 AIGENERAL_AllocMinionList(game,unit,clone);
 AIGENERAL_SetOwnerData(game,clone,!unit?-1:unit->dwUnitId,!unit?6:unit->dwUnitType,1,0);
 STATLIST_SetUnitStat(clone,STAT_MAXHP,STATLIST_GetMaxLifeFromUnit(unit)/3,0);
 STATLIST_SetUnitStat(clone,STAT_HITPOINTS,STATLIST_UnitGetStatValue(unit,STAT_HITPOINTS,0)/3,0);
 STATLIST_SetUnitStat(clone,STAT_HPREGEN,0,0);
 UNITS_StoreOwner(clone,unit);UNITS_StoreOwner(unit,clone);
 SUNIT_AttachSound(unit,16,0);
 ++control->dwAiParam[1];return true;
 }
 }
 }
 return false;
}

static inline unsigned int RollSeed(D2SeedStrc* s) {
 unsigned __int64 value=(unsigned __int64)0x6AC690C5*s->nLowSeed+s->nHighSeed;
 s->nHighSeed=(unsigned int)(value>>32);s->nLowSeed=(unsigned int)value;return s->nLowSeed;
}

// 0x005FCB60
void __fastcall AIBAAL_MainSkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, D2UnitStrc* pTarget, int nParam, D2AiCmdStrc* pAiCmd)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (pUnit)
    {
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    }
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    switch (nParam)
    {
    case 5:
        if (!pAiCmd)
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
            return;
        }

        AITACTICS_WalkToTargetCoordinates(pGame, pUnit, pAiCmd->nCmdParam[1], pAiCmd->nCmdParam[2]);
        return;
    case 4:
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 16);
        return;
    case 3:
        AITACTICS_WalkToTargetWithRandomPathType(pGame, pUnit, pTarget, 6, 1);
        return;
    case 2:
    case 6:
        D2GAME_AICORE_Escape(pGame, pUnit, pTarget, 12, 0);
        return;
    case 9:
        AITACTICS_UseSkill(pGame, pUnit, 9, SKILL_BAALTENTACLE, pTarget, 0, 0);
        return;
    case 11:
        SKILLS_AssignSkill(pUnit, SKILL_BAALNOVA, 1, 0, gszAiBaal, 0x452);
        AITACTICS_UseSkill(pGame, pUnit, 10, SKILL_BAALNOVA, pTarget, 0, 0);
        return;
    case 13:
        AITACTICS_UseSkill(pGame, pUnit, 4, SKILL_BAALCOLDMISSILES, pTarget, 0, 0);
        return;
    case 10:
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 5, pTarget);
        return;
    case 12:
        AITACTICS_UseSkill(pGame, pUnit, 8, SKILL_BAALINFERNO, pTarget, 0, 0);
        return;
    case 8:
        if (!pTarget)
        {
            AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, 0, pAiCmd);
            return;
        }

        if (pMonStatsTxtRecord->nSkill[5] > 0 && (STATLIST_GetMaxLifeFromUnit(pTarget) > STATLIST_GetMaxManaFromUnit(pTarget) || pTarget->dwUnitType != UNIT_PLAYER))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[5], pMonStatsTxtRecord->nSkill[5], pTarget, 0, 0);
        }
        else if (pMonStatsTxtRecord->nSkill[6] > 0 && pTarget->dwUnitType == UNIT_PLAYER)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[6], pMonStatsTxtRecord->nSkill[6], pTarget, 0, 0);
        }
        return;
    case 14:
    {
        if (!pTarget)
        {
            AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, 0, 0, pAiCmd);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pUnit);
        const int nY = CLIENTS_GetUnitY(pUnit);
        const int nTargetX = CLIENTS_GetUnitX(pTarget);
        const int nTargetY = CLIENTS_GetUnitY(pTarget);
        int nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);
        if (!nDistance)
        {
            nDistance = 1;
        }
        int nFinalX = nX + 25 * (nX - nTargetX) / nDistance;
        int nFinalY = nY + 25 * (nY - nTargetY) / nDistance;

        if (pUnit->dwClassId == 709)
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[4], pMonStatsTxtRecord->nSkill[4], 0, nTargetX, nTargetY);
            return;
        }

        if (MONSTERREGION_FindSpawnLocation(pGame, UNITS_GetRoom(pUnit), 0, pUnit->dwClassId, &nFinalX, &nFinalY, 0))
        {
            AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[4], pMonStatsTxtRecord->nSkill[4], 0, nFinalX, nFinalY);
        }
        else
        {
            AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, 0, pAiCmd);
        }
        return;
    }
    case 15:
        AIBAAL_SummonClone(pGame, pUnit, pAiControl);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    default:
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;

    case 1:
    {
        int nDelay = 35;
        switch (pGame->nDifficulty)
        {
        case 1:
            nDelay = 15;
            break;
        case 2:
            nDelay = 5;
            break;
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, nDelay);
        return;
    }
    }
}


// 0x005FCF30
void __fastcall AIBAAL_RunSpecialAiState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam1 = 0;
    int nParam2 = 0;
    D2AiCmdStrc* pCurrentAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (pCurrentAiCmd)
    {
        nParam1 = pCurrentAiCmd->nCmdParam[1];
        nParam2 = pCurrentAiCmd->nCmdParam[2];
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    }

    AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, pAiControl->nAiSpecialState);

    if (!AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0) && nParam1 && nParam2)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = nParam1;
        aiCmd.nCmdParam[2] = nParam2;
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 1);
}

static inline int UNITS_GetXPos(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    if (pUnit->pDynamicPath)
    {
        return PATH_GetXPosition(pUnit->pDynamicPath);
    }

    return 0;
}

static inline int UNITS_GetYPos(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    if (pUnit->pDynamicPath)
    {
        return PATH_GetYPosition(pUnit->pDynamicPath);
    }

    return 0;
}

// 0x005FCFE0
void __fastcall AITHINK_Fn135_BaalCrab(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    int nMax = 0;
    int nCount = 0;

    D2UnitStrc* pTarget = AIBAAL_GetUberTarget(pGame, &nMax, &nCount, 0, AIBAAL_CullPotentialTargets, pUnit);
    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pAiCmd)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = UNITS_GetXPos(pUnit);
        aiCmd.nCmdParam[2] = UNITS_GetYPos(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
        pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    const int nParam = AIBAAL_RollRandomAiParam(pGame, pUnit, pAiControl, pTarget, nMax, nCount, pAiCmd);
    AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, nParam, pAiCmd);
    AITACTICS_Idle(pGame, pUnit, 25);
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x005FD0F0
void __fastcall AIBAAL_SpawnUberBaalMinion(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc coord;
    coord.nX = UNITS_GetUnitXPosition(pUnit);
    coord.nY = UNITS_GetUnitYPosition(pUnit);

    const int nMinionTypes[3] = { 0x2DC, 0x2DB, 0x2DD };
    const int nMinionModes[3] = { 1, 7, 8 };
    const int nChoice = (unsigned int)SEED_RollRandomNumber(&pUnit->pSeed) & 1;

    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &coord, 2, 0x100, 0);
    if (pRoom)
    {
        D2UnitStrc* pMinion = D2GAME_SpawnMonster(pGame, pRoom, coord.nX, coord.nY, nMinionTypes[nChoice], nMinionModes[nChoice], -1, 0);
        if (pMinion)
        {
            pMinion->dwFlags |= 0x4000000;
            STATES_ToggleState(pMinion, 0xB8, 1);
        }
    }
}

// 0x005FD200
void __fastcall AITHINK_Fn145_UberBaal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
}


// 0x005FD210
void __fastcall AITHINK_Fn140_BaalCrabClone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && SUNIT_IsDead(pOwner))
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        return;
    }

    int nMax = 0;
    int nCount = 0;
    D2UnitStrc* pTarget = AIBAAL_GetUberTarget(pGame, &nMax, &nCount, 0, AIBAAL_CullPotentialTargets, pUnit);

    D2AiCmdStrc* pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    if (!pAiCmd)
    {
        D2AiCmdStrc aiCmd;
        aiCmd.nCmdParam[0] = 10;
        aiCmd.nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
        aiCmd.nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
        AIGENERAL_CopyAiCommand(pGame, pUnit, &aiCmd);
        pAiCmd = AIGENERAL_GetAiCommandFromParam(pUnit, 10, 0);
    }

    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    int nParam = AIBAAL_RollRandomAiParam(pGame, pUnit, pAiControl, pTarget, nMax, nCount, pAiCmd);
    if (nParam == 7 || nParam == 9 || nParam == 14 || nParam == 15)
    {
        nParam = 2;
    }

    if (pTarget)
    {
        AIBAAL_MainSkillHandler(pGame, pUnit, pAiControl, pTarget, nParam, pAiCmd);
        AITACTICS_Idle(pGame, pUnit, 25);
    }
    else
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
    }
}
