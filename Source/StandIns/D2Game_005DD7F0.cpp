// Functional replacement for the function at 0x005DD7F0, not the original code: only the ordinary build (tools/link.py) uses it.
// The other functions in this file are copies that give it its callees and their calling conventions; the build links their verified definitions instead.

struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2DynamicPathStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2MonStatsTxt { char unk00[0x52]; unsigned char nThreat[3]; };
struct D2SpecialAiStrc { int unk00[9]; int nToggle; };
struct D2MonsterDataStrc { D2MonStatsTxt* pMonStats; char unk04[0x4C]; D2SpecialAiStrc* pSpecialAi; };
struct D2UnitStrc
{
    int dwUnitType;
    char unk04[0x10];
    D2MonsterDataStrc* pMonsterData;
    unsigned char nAct;
    char unk19[7];
    D2SeedStrc pSeed;
    char unk0x28[0x04];
    D2DynamicPathStrc* pDynamicPath;
};

struct D2AiTargetArgsStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    union
    {
        struct
        {
            int bCheckTargetCollision;
            int nMaxDistance;
            int unk0x10;
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tSearch;
        struct
        {
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tEligible;
        D2UnitStrc* pSkipTarget;
    };
    int unk0x1C[3];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

int __stdcall sub_00648E30_GetPathValue(D2DynamicPathStrc* pPath); // 0x00648E30
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pPath); // 0x00648780
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
D2UnitStrc* __fastcall sub_6FCF1E80(D2GameStrc* pGame, D2UnitStrc* pUnit, void* a3, AIUTIL_TargetCallback a4, int nCallbackId); // 0x005DD0B0
int __fastcall MONSTERAI_GetTargetOverrideType(D2UnitStrc* pUnit); // 0x005730E0
int __fastcall MONSTERAI_GetTargetOverrideGUID(D2UnitStrc* pUnit); // 0x00573100
void __fastcall MONSTERAI_ClearTargetOverride(D2UnitStrc* pUnit); // 0x00573120
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380
int __stdcall UNITS_TestCollisionWithUnit(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nCollisionMask); // 0x00622AA0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0
int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax); // 0x00472210
void __fastcall sub_6FCBDD30(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall sub_0061B130_GetCollision(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0061B130
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

// 0x005DD510
static int __stdcall AIUTIL_ShouldUseAlternativeTarget(D2UnitStrc** ppTarget, int* pTargetDistance, D2UnitStrc* pAlternativeTarget, int nAlternativeDistance, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 0)
    {
        return 0;
    }

    if (!pAlternativeTarget)
    {
        return 0;
    }

    D2UnitStrc* pCurrentTarget = *ppTarget;
    if (!pCurrentTarget)
    {
        return 1;
    }

    if (nAlternativeDistance > 5)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nPathType = sub_00648E30_GetPathValue(pPath);
    D2UnitStrc* pPathTarget = PATH_GetTargetUnit(pPath);
    const int nX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    PATH_SetTargetUnit(pPath, pCurrentTarget);
    PATH_SetType(pPath, 2);
    D2Common_10142(pPath, pUnit, 0);
    PATH_SetTargetUnit(pPath, pPathTarget);
    D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
    PATH_SetType(pPath, nPathType);

    if (PATH_GetNumberOfPathPoints(pPath))
    {
        return 0;
    }

    D2AiTargetArgsStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.pSkipTarget = pCurrentTarget;
    sub_6FCF1E80(SUNIT_GetGameFromUnit(pUnit), pUnit, &arg, 0, 7);

    if (!arg.pTarget || arg.nDistance >= 20)
    {
        return 1;
    }

    *ppTarget = arg.pTarget;
    *pTargetDistance = arg.nDistance;
    return 0;
}

static __forceinline int AIUTIL_IsOverrideTargetValid_Inline(D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case 0:
    case 1:
        return !SUNIT_IsDead(pTarget);
    case 3:
        return 1;
    }
    return 0;
}

// 0x005DD610
static int __stdcall AIUTIL_ResolveTargetOverride(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = 0;
    int nDistance = 0;

    const int nType = pUnit ? pUnit->dwUnitType : 6;
    if (nType != 1)
    {
        return 0;
    }

    const int nOverride = MONSTERAI_GetTargetOverrideType(pUnit);
    if (!nOverride)
    {
        return 0;
    }

    switch (nOverride)
    {
    case 1:
        pTarget = SUNIT_GetServerUnit(pGame, 0, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            MONSTERAI_ClearTargetOverride(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            MONSTERAI_ClearTargetOverride(pUnit);
            return 0;
        }
        break;

    case 2:
        pTarget = SUNIT_GetServerUnit(pGame, 1, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            MONSTERAI_ClearTargetOverride(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            MONSTERAI_ClearTargetOverride(pUnit);
            return 0;
        }
        break;

    case 4:
        pTarget = SUNIT_GetServerUnit(pGame, 3, MONSTERAI_GetTargetOverrideGUID(pUnit));
        if (!pTarget)
        {
            MONSTERAI_ClearTargetOverride(pUnit);
            return 0;
        }
        nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
        if (bUseEligibilityCheck && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
        {
            MONSTERAI_ClearTargetOverride(pUnit);
            return 0;
        }
        break;

    case 3:
    {
        const int nAlignment = STATLIST_GetUnitAlignment(pUnit);
        if (nAlignment == 1)
        {
            if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2))
            {
                sub_6FCBDD30(pUnit, 2, 1);
            }
            else
            {
                sub_6FCBDD30(pUnit, 0, 1);
            }
        }
        else if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2))
        {
            if (nAlignment == 0)
            {
                sub_6FCBDD30(pUnit, 2, 1);
            }
            else if (nAlignment == 2)
            {
                sub_6FCBDD30(pUnit, 0, 1);
            }
        }

        D2AiTargetArgsStrc arg;
        if (!bUseEligibilityCheck)
        {
            arg.pTarget = 0;
            arg.nDistance = 0x7FFFFFFF;
            const int nUnk = sub_0061B130_GetCollision(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            arg.tSearch.bCheckTargetCollision = bCheckCollision;
            arg.tSearch.nMaxDistance = 35;
            arg.tSearch.unk0x10 = nUnk;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 5);
        }
        else
        {
            arg.pTarget = 0;
            arg.nDistance = 0x7FFFFFFF;
            arg.tEligible.pAlternativeTarget = 0;
            arg.tEligible.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 6);
        }

        pTarget = arg.pTarget;
        nDistance = arg.nDistance;
        sub_6FCBDD30(pUnit, nAlignment, 1);
        break;
    }

    default:
        MONSTERAI_ClearTargetOverride(pUnit);
        return 0;
    }

    if (AIUTIL_IsOverrideTargetValid_Inline(pTarget))
    {
        *ppUnit = pTarget;
        *pDistance = nDistance;
        return 1;
    }

    MONSTERAI_ClearTargetOverride(pUnit);
    return 0;
}

// 0x005DDC30
D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange)
{
    D2UnitStrc* pTarget;
    int nDistance;

    if (!AIUTIL_ResolveTargetOverride(0, 1, &pTarget, &nDistance, pGame, pUnit))
    {
        D2AiTargetArgsStrc arg;
        arg.pTarget = 0;
        arg.nDistance = 0x7FFFFFFF;
        arg.tEligible.pAlternativeTarget = 0;
        arg.tEligible.nAlternativeDistance = 0x7FFFFFFF;
        sub_6FCF1E80(pGame, pUnit, &arg, 0, 6);

        if (AIUTIL_ShouldUseAlternativeTarget(&arg.pTarget, &arg.nDistance, arg.tEligible.pAlternativeTarget, arg.tEligible.nAlternativeDistance, pUnit))
        {
            pTarget = arg.tEligible.pAlternativeTarget;
            nDistance = arg.tEligible.nAlternativeDistance;
        }
        else
        {
            pTarget = arg.pTarget;
            nDistance = arg.nDistance;
        }
    }

    if (!pTarget)
    {
        if (pInMeleeRange)
        {
            *pInMeleeRange = 0;
        }

        if (pDistance)
        {
            *pDistance = 0x7FFFFFFF;
        }

        return 0;
    }

    if (pInMeleeRange)
    {
        *pInMeleeRange = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    }

    if (pDistance)
    {
        *pDistance = nDistance;
    }

    return pTarget;
}

struct D2UnitLinkStrc { D2UnitStrc* pUnit; int unk04; D2UnitLinkStrc* pNext; };
struct D2GameStrc { char unk00[0x6D]; unsigned char nDifficulty; char unk6E[0x108A]; D2UnitLinkStrc* pUnitNodes[10]; };
struct D2AiControlStrc { int unk00[2]; union { unsigned short nFlags; struct { unsigned short unkFlags:3; unsigned short bHadTarget:1; }; }; };
int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom); // 0x0061AA40
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC530
extern "C" const char* __cdecl ASSERT_GetSourceFile(); // 0x00408090
extern "C" void __cdecl ASSERT_Report(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
extern const char gszPlayerAssertion[]; // 0x006CC837

// 0x005DD7F0
D2UnitStrc* __fastcall AIUTIL_FindAiTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    D2SpecialAiStrc* pSpecialAi = 0;
    int nOldToggle = 0;
    int bCheckCollision;
    if (pAiControl->nFlags & 0x40)
    {
        bCheckCollision = 1;
        pAiControl->nFlags &= ~0x40;
    }
    else if (DUNGEON_CheckLOSDraw(pRoom))
        bCheckCollision = 0;
    else
    {
        bCheckCollision = pAiControl->bHadTarget == 0;
        if (pUnit && pUnit->dwUnitType == 1)
        {
            pSpecialAi = pUnit->pMonsterData ? pUnit->pMonsterData->pSpecialAi : 0;
            if (bCheckCollision && pSpecialAi)
            {
                nOldToggle = pSpecialAi->nToggle;
                bCheckCollision = nOldToggle == 0;
            }
        }
    }

    D2UnitStrc* pTarget = 0;
    int nDistance;
    unsigned int nMinDistance = 0x7FFFFFFF;
    if (!AIUTIL_ResolveTargetOverride(bCheckCollision, 0, &pTarget, &nDistance, pGame, pUnit))
    {
        if (STATLIST_GetUnitAlignment(pUnit) == 0)
        {
            D2UnitLinkStrc** ppNode = pGame->pUnitNodes;
            D2UnitLinkStrc* pNode = *ppNode;
            pTarget = 0;
            nDistance = 35;
            D2MonStatsTxt* pMonStats = 0;
            if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
                pMonStats = pUnit->pMonsterData->pMonStats;
            if (pMonStats)
            {
                unsigned char nThreat = pMonStats->nThreat[pGame->nDifficulty];
                if (nThreat)
                    nDistance = nThreat;
            }
            const unsigned char nAct = pUnit->nAct;
            const int nX = CLIENTS_GetUnitX(pUnit);
            const int nY = CLIENTS_GetUnitY(pUnit);
            for (int i = 0; i < 8; ++i)
            {
                if (pNode)
                {
                    D2UnitStrc* pCurrent = pNode->pUnit;
                    if (!pCurrent || pCurrent->dwUnitType != 0)
                    {
                        ASSERT_Report(gszPlayerAssertion, ASSERT_GetSourceFile(), 0x5F6);
                        exit(-1);
                    }
                    if (nAct == pCurrent->nAct && UNITS_GetRoom(pCurrent) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pCurrent)))
                    {
                        unsigned int nCurrentDistance = AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                        if (nCurrentDistance < nMinDistance)
                            nMinDistance = nCurrentDistance;
                        if (nCurrentDistance < 55)
                        {
                            if (SUNIT_IsDead(pCurrent))
                                nCurrentDistance = 0x7FFFFFFF;
                            for (;;)
                            {
                                if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
                                {
                                    nDistance = nCurrentDistance;
                                    pTarget = pCurrent;
                                }
                                pNode = pNode->pNext;
                                if (!pNode)
                                    break;
                                pCurrent = pNode->pUnit;
                                nCurrentDistance = AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                            }
                        }
                    }
                }
                pNode = *++ppNode;
            }
            while (pNode)
            {
                D2UnitStrc* pCurrent = pNode->pUnit;
                if (nAct == pCurrent->nAct)
                {
                    const unsigned int nCurrentDistance = AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                    if (nCurrentDistance < (unsigned int)nDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
                    {
                        nDistance = nCurrentDistance;
                        pTarget = pCurrent;
                    }
                }
                pNode = pNode->pNext;
            }
            pNode = ppNode[1];
            D2UnitStrc* pAlternative = 0;
            unsigned int nAlternativeDistance = 0x7FFFFFFF;
            while (pNode)
            {
                D2UnitStrc* pCurrent = pNode->pUnit;
                if (nAct == pCurrent->nAct)
                {
                    const unsigned int nCurrentDistance = AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                    if (nCurrentDistance < nAlternativeDistance && (!bCheckCollision || !UNITS_TestCollisionWithUnit(pUnit, pCurrent, 4)))
                    {
                        nAlternativeDistance = nCurrentDistance;
                        pAlternative = pCurrent;
                    }
                }
                pNode = pNode->pNext;
            }
            if (pAlternative && AIUTIL_ShouldUseAlternativeTarget(&pTarget, &nDistance, pAlternative, nAlternativeDistance, pUnit))
            {
                pTarget = pAlternative;
                nDistance = nAlternativeDistance;
            }
        }
        else
        {
            const int nCollision = sub_0061B130_GetCollision(pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            D2AiTargetArgsStrc arg;
            arg.pTarget = 0;
            arg.nDistance = 0x7FFFFFFF;
            arg.tSearch.bCheckTargetCollision = bCheckCollision;
            arg.tSearch.nMaxDistance = 35;
            arg.tSearch.unk0x10 = nCollision;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            sub_6FCF1E80(pGame, pUnit, &arg, 0, 5);
            if (arg.tSearch.pAlternativeTarget && AIUTIL_ShouldUseAlternativeTarget(&arg.pTarget, &arg.nDistance, arg.tSearch.pAlternativeTarget, arg.tSearch.nAlternativeDistance, pUnit))
            {
                pTarget = arg.tSearch.pAlternativeTarget;
                nDistance = arg.tSearch.nAlternativeDistance;
            }
            else
            {
                pTarget = arg.pTarget;
                nDistance = arg.nDistance;
            }
        }
    }
    if (!pTarget)
    {
        *pCombat = 0;
        *pDistance = nMinDistance;
        return 0;
    }
    if (STATLIST_GetUnitAlignment(pUnit) != 2)
    {
        pAiControl->nFlags |= 8;
        if (pSpecialAi)
            pSpecialAi->nToggle = nOldToggle == 0;
    }
    *pCombat = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    *pDistance = nDistance;
    return pTarget;
}
