#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"







int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                          // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                          // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                           // 0x0045C390
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                 // 0x00552F60
D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                          // 0x0058F0D0
D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nRange); // 0x005D2F80
int __fastcall AIUTIL_HasClearApproachToTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);                                         // 0x005DC640
D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat); // 0x005DD7F0
D2UnitStrc* __fastcall AITACTICS_FindTargetInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat, int nMaxDistance); // 0x005DDE50
int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTargetUnit); // 0x005DDF90
void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);               // 0x005DE080
void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames);                            // 0x005DE0F0
void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190
int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200
int __fastcall AITACTICS_UseSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMode, int nSkillId, D2UnitStrc* pTarget, int nX, int nY); // 0x005DEAD0
int __fastcall AITACTICS_RunToTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);      // 0x005DED20
int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int a4, int bRun, int nVelocity, int a7); // 0x005E3EA0
int __fastcall AITHINK_TryPetFollowOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2UnitStrc* pOwner, int a5, D2AiTickParamStrc* pAiTickParam, int a7, int a8); // 0x005E45D0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                  // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                                // 0x00620BB0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);                 // 0x00622C40
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                               // 0x00639DF0
int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x006416D0

#define AI_PARAM(pGame, pMonStatsTxt, nParamId) ((pMonStatsTxt)->wAiParam[nParamId][(pGame)->nDifficulty])
// 0x005ED2A0
void __fastcall AITHINK_Fn108_Fenris(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    D2MonStatsTxt* pMonStatsTxtRecord = pAiTickParam->pMonstatsTxt;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (pAiControl->dwAiParam[2])
        {
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pAiControl->dwAiParam[2]);
            if (pMonStatsTxtRecord->nSkill[1] >= 0 && pPlayer)
            {
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[1], pMonStatsTxtRecord->nSkill[1], 0, CLIENTS_GetUnitX(pPlayer), CLIENTS_GetUnitY(pPlayer));
                EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 6, 0, 0);
                AITACTICS_Idle(pGame, pUnit, 8);
                return;
            }
        }

        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }

    pAiControl->dwAiParam[2] = !pOwner ? -1 : pOwner->dwUnitId;

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        if (!AITHINK_TryPetFollowOwner(pGame, pUnit, 0, pOwner, 0, pAiTickParam, 0, 6))
        {
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 33);
        }
        return;
    }

    int nDistance;
    int bCombat;
    int nOwnerTargetDistance;
    int bOwnerTargetCombat;
    const int nMaxDistance = AI_PARAM(pGame, pMonStatsTxtRecord, 3);
    D2UnitStrc* pTarget = AITACTICS_FindTargetInRange(pGame, pUnit, pAiControl, &nDistance, &bCombat, nMaxDistance);
    D2UnitStrc* pOwnerTarget = sub_6FCF2110(pGame, pOwner, pAiControl, &nOwnerTargetDistance, &bOwnerTargetCombat);

    if (pTarget && !AIUTIL_HasClearApproachToTarget(pUnit, pTarget))
    {
        pTarget = 0;
    }

    if (!pTarget && pOwnerTarget && nOwnerTargetDistance < nMaxDistance && AIUTIL_HasClearApproachToTarget(pUnit, pOwnerTarget))
    {
        pTarget = pOwnerTarget;
        nDistance = nOwnerTargetDistance;
    }

    const int nOwnerDistance = DRLG_UnitEdgeDistance(pOwner, pUnit);
    if (pTarget && nOwnerDistance > nMaxDistance && DRLG_UnitEdgeDistance(pOwner, pTarget) > nMaxDistance)
    {
        pTarget = 0;
    }

    int nVelocityBonus;
    if (pMonStatsTxtRecord->nVelocity <= 0 || (nVelocityBonus = 100 * pMonStatsTxtRecord->nRun / pMonStatsTxtRecord->nVelocity - 100) >= 100)
    {
        nVelocityBonus = 100;
    }

    if (pMonStatsTxtRecord->nSkill[1] >= 0 && nOwnerDistance > 50)
    {
        AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[1], pMonStatsTxtRecord->nSkill[1], 0, CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 2, 0, 0);
        AITACTICS_Idle(pGame, pUnit, 10);
        return;
    }

    if (nOwnerDistance > AI_PARAM(pGame, pMonStatsTxtRecord, 4))
    {
        D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 1, 100, 0);
        return;
    }

    const int nAnimMode = pOwner->dwAnimMode;
    if (nOwnerDistance > nMaxDistance)
    {
        if (nAnimMode == 3)
        {
            D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 1, 100, 0);
            return;
        }

        if (nAnimMode == 2 || nAnimMode == 6)
        {
            D2GAME_AI_PetMove_6FCE2BA0(pGame, pOwner, pUnit, 0, 0, 0, 0);
            return;
        }
    }

    if (AITHINK_TryPetFollowOwner(pGame, pUnit, pTarget, pOwner, bCombat, pAiTickParam, 1, 6))
    {
        return;
    }

    const int bState = STATES_CheckState(pUnit, STATE_FENRIS_RAGE);
    if (pMonStatsTxtRecord->nSkill[0] >= 0 && !bState
        && ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStatsTxtRecord, 2) || !pTarget || pAiTickParam->pAiControl->dwAiParam[0]))
    {
        D2UnitStrc* pCorpse = SKILLS_FindUseableCorpse(pGame, pUnit, pOwner, 10);
        if (pCorpse && DRLG_UnitEdgeDistance(pCorpse, pUnit) < nMaxDistance / 2)
        {
            if (UNITS_IsInMeleeRange(pUnit, pCorpse, 0))
            {
                pAiTickParam->pAiControl->dwAiParam[0] = 0;
                AITACTICS_UseSkill(pGame, pUnit, pMonStatsTxtRecord->nSkillMode[0], pMonStatsTxtRecord->nSkill[0], pCorpse, 0, 0);
                return;
            }

            if (!bCombat)
            {
                AITACTICS_RunToTargetUnit(pGame, pUnit, pCorpse);
                pAiTickParam->pAiControl->dwAiParam[0] = 1;
                pAiTickParam->pAiControl->dwAiParam[1] = !pCorpse ? -1 : pCorpse->dwUnitId;
                return;
            }
        }
    }
    else
    {
        pAiTickParam->pAiControl->dwAiParam[0] = 0;
    }

    if (bCombat)
    {
        AITACTICS_ChangeModeAndTargetUnit(pGame, pUnit, 4, pTarget);
        AITACTICS_Idle(pGame, pUnit, AI_PARAM(pGame, pMonStatsTxtRecord, 0));
        return;
    }

    if (pTarget)
    {
        AITACTICS_SetAiParam(pUnit, 0, nVelocityBonus, 0);
        AITACTICS_RunToTargetUnit(pGame, pUnit, pTarget);
        return;
    }

    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < AI_PARAM(pGame, pMonStatsTxtRecord, 1))
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 10);
        return;
    }

    AITACTICS_IdleInNeutralMode(pGame, pUnit, 15);
}
