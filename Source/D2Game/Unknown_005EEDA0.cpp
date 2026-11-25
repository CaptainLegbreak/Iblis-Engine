#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2GameAux.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"

int __fastcall ACT5Q5_IsNotActivatable(D2GameStrc* pGame);                                                  // 0x0058CF90
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);            // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                         // 0x005DE0F0
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_WalkToTargetUnitWithSteps(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char bStep); // 0x005DEF80
int __fastcall AITACTICS_WalkAwayFromTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance, int bDeleteAiEventCallback); // 0x005DEFE0
#define UNIT_PLAYER 0

#define PATHTYPE_TOWARD 2

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY);               // 0x005DC530
int __fastcall AIBAAL_GetTargetScore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2AiCmdStrc* pArgs); // 0x005E8530
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);              // 0x00622C40
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900
extern "C" void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget);        // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nType);                                    // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, int bAllowInTown);                   // 0x00649970

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

// 0x005E8F20
D2UnitStrc* __fastcall AIBAAL_GetTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pMax, int* pCount, D2AiCmdStrc* pArgs, int (__fastcall* pfCull)(D2UnitStrc*, D2UnitStrc*))
{
    D2_ASSERT(pfCull, 890);

    UNITS_GetRoom(pUnit);

    D2UnitStrc* pTarget = 0;
    int nCount = 0;
    int nMax = 0;
    D2TargetNodeStrc** ppTargetNode = pGame->pTargetNodes;
    D2TargetNodeStrc* pTargetNode = *ppTargetNode;
    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    const unsigned char nAct = pUnit->nAct;

    for (int i = 0; i < 8; ++i)
    {
        if (pTargetNode)
        {
            D2_ASSERT(pTargetNode->hUnit && pTargetNode->hUnit->dwUnitType == UNIT_PLAYER, 917);
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;

            if (pfCull(pUnit, pTargetUnit))
            {
                int nCurrent;
                if (pTargetUnit && pTargetUnit->dwAnimMode != PLRMODE_DEAD && pTargetUnit->dwAnimMode != PLRMODE_DEATH)
                {
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
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

                    pTargetNode = pTargetNode->pNext;
                    ++nCount;

                    if (!pTargetNode)
                    {
                        break;
                    }

                    pTargetUnit = pTargetNode->hUnit;
                    nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                }
            }
        }

        pTargetNode = *++ppTargetNode;
    }

    while (pTargetNode)
    {
        D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
        if (nAct == pTargetUnit->nAct)
        {
            const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
            if (nMax < nCurrent)
            {
                nMax = nCurrent;
                pTarget = pTargetUnit;
            }
            ++nCount;
        }

        pTargetNode = pTargetNode->pNext;
    }

    pTargetNode = ppTargetNode[1];

    D2UnitStrc* pTemp = 0;
    int nTemp = 0;
    if (pTargetNode)
    {
        do
        {
            D2UnitStrc* pTargetUnit = pTargetNode->hUnit;
            if (nAct == pTargetUnit->nAct)
            {
                const int nCurrent = AIBAAL_GetTargetScore(pGame, pUnit, pTargetUnit, pArgs);
                if (nTemp < nCurrent)
                {
                    nTemp = nCurrent;
                    pTemp = pTargetUnit;
                }
            }

            pTargetNode = pTargetNode->pNext;
        }
        while (pTargetNode);

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

int __fastcall AITHINK_AreUnitsInSameLevel(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                        // 0x005EEB10
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pTarget);                        // 0x006416D0

enum D2C_AncientBarb2AIParams
{
    ANCIENTBARB2_AI_PARAM_ATTACK_DISTANCE = 0,
    ANCIENTBARB2_AI_PARAM_ATTACK_CHANCE_PCT = 1,
    ANCIENTBARB2_AI_PARAM_SHOUT_CHANCE_PCT = 2,
    ANCIENTBARB2_AI_PARAM_WALK_AWAY_CHANCE_PCT = 3,
    ANCIENTBARB2_AI_PARAM_WALK_AWAY_MAX_DISTANCE = 4,
};

static __forceinline int AI_RollPercentage(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    *(unsigned __int64*)&pUnit->pSeed = lSeed;
    return (unsigned int)lSeed % 100;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTable->nSkillsTxtRecordCount)
    {
        return &sgptDataTable->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005EEDA0
void __fastcall AITHINK_AncientBarb2SkillHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2MonStatsTxt* pMonStatsTxt = pAiTickParam->pMonstatsTxt;

    if (ACT5Q5_IsNotActivatable(pGame))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    int nDistance;
    int nSkillId;
    D2UnitStrc* pTarget = AIBAAL_GetTarget(pGame, pUnit, &nDistance, &nSkillId, 0, AITHINK_AreUnitsInSameLevel);
    if (!pTarget)
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 25);
        return;
    }

    const int bInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    nDistance = DRLG_UnitEdgeDistance(pUnit, pTarget);
    if (bInMeleeRange && AI_RollPercentage(pUnit) < pMonStatsTxt->wAiParam[ANCIENTBARB2_AI_PARAM_WALK_AWAY_CHANCE_PCT][pGame->nDifficulty])
    {
        if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pTarget, (unsigned char)pMonStatsTxt->wAiParam[ANCIENTBARB2_AI_PARAM_WALK_AWAY_MAX_DISTANCE][pGame->nDifficulty], 1))
        {
            AITACTICS_Idle(pGame, pUnit, 25);
            return;
        }
    }

    nSkillId = pMonStatsTxt->nSkill[0];
    if (nSkillId > 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            if (pSkillsTxtRecord->nAuraState <= 0 || pSkillsTxtRecord->nAuraState > sgptDataTable->nStatesTxtRecordCount || !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
            {
                if (pSkillsTxtRecord->wAuraTargetState <= 0 || pSkillsTxtRecord->wAuraTargetState > sgptDataTable->nStatesTxtRecordCount || !STATES_CheckState(pTarget, pSkillsTxtRecord->wAuraTargetState))
                {
                    if (AI_RollPercentage(pUnit) < pMonStatsTxt->wAiParam[ANCIENTBARB2_AI_PARAM_SHOUT_CHANCE_PCT][pGame->nDifficulty]
                        && AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxt->nSkillMode[0], nSkillId, 0, 0, 0))
                    {
                        return;
                    }
                }
            }
        }
    }

    if (nDistance < pMonStatsTxt->wAiParam[ANCIENTBARB2_AI_PARAM_ATTACK_DISTANCE][pGame->nDifficulty])
    {
        if (AI_RollPercentage(pUnit) < pMonStatsTxt->wAiParam[ANCIENTBARB2_AI_PARAM_ATTACK_CHANCE_PCT][pGame->nDifficulty]
            && AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, MONMODE_ATTACK1, pTarget))
        {
            return;
        }
    }

    const short* pAttackDistance = &pMonStatsTxt->wAiParam[ANCIENTBARB2_AI_PARAM_ATTACK_DISTANCE][pGame->nDifficulty];
    if (nDistance >= *pAttackDistance && AITACTICS_WalkToTargetUnitWithSteps(pGame, pUnit, pTarget, (unsigned char)(nDistance - *pAttackDistance)))
    {
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}
