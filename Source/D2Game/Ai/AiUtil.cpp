#include "D2GameEvents.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2Game.h"
#include "D2Drlg.h"
#include "D2UnitData.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameAux.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2ObjModes.h"
#include "D2GameCallbackArgs.h"
#include "D2LanguageNames.h"
#include "FogApi.h"

#define D2_ASSERT(expr,line) if(!(expr)) { FOG_DisplayHalt("",sub_00408090(),line);exit(-1); }

struct D2MonsterDataStrc;

struct D2StaticPathStrc;

struct D2NearestRecord005DC870Strc;

struct UnkAiStrc5;

union D2SeedStrc;

struct D2UnkAiCallbackArgStrc2;

struct D2AiCallback7ArgStrc;

struct D2AiCallback11ArgStrc;

struct D2UbersAiCallbackArgStrc;

struct Obj005DD220;

struct Obj005DD230;

struct D2MonStatsTxt;

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2CommonApi.h"
#include "D2CommonApi3.h"
#include "D2ClientApi.h"

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380

struct D2NearestRecord005DC870Strc
{
    D2UnitStrc* pNearest;
    int nBestDistance;
    int nCount;
    int nMaxDistance;
};


struct UnkAiStrc5
{
    unsigned int nMaxDistance;
};

struct D2UnkAiCallbackArgStrc2
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* pAlternativeTarget;
    int nAlternativeDistance;
};

struct D2AiCallback7ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* pExcludedUnit;
};

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __fastcall AIUTIL_GetThreat(D2UnitStrc* pUnit); // 0x005DC920

struct D2AiCallback11ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* pExcludedUnit;
};


struct D2UbersAiCallbackArgStrc
{
    int nUberMephisto;
    int nUberDiablo;
    int nUberBaal;
    int nDistance;
    int nOtherMonsters;
    int nDiabloSpawner;
    int nBaalMinions;
    int nDiabloMinions;
};

struct Obj005DD220
{
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned short wFlags08;
};

struct Obj005DD230 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned short wFlags08;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

struct D2UnitStrc;

struct D2AiTargetSearchArgsStrc;

struct D2MonStats2Txt;

struct D2AiCmdStrc;

struct D2MapAIPathPositionStrc;

struct D2FallenShamanAiCallbackArgStrc;

struct D2AiTargetArgsStrc;

struct D2AiTargetSearchArgsStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int bCheckTargetCollision;
    int nMaxDistance;
    int nAreaTile;
    D2UnitStrc* pAlternativeTarget;
    int nAlternativeDistance;
};

extern "C" unsigned int __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

enum D2C_J07AiConstants
{
    UNITFLAG_NOTC = 0x20000,
    MONTYPEFLAG_UNIQUE_CHAMPION = 0xE,
    MONSTATSFLAGINDEX_BYTE1_BIT0 = 0,
    MONSTATSFLAGINDEX_BYTE1_BIT7 = 7,
    TRAPMISSILE_AI_PARAM_DISTANCE = 0,
    TRAPMISSILE_AI_PARAM_NUM_TO_SHOOT = 1,
    TRAPMISSILE_AI_PARAM_DELAY = 2,
};

struct D2FallenShamanAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nDistance;
    int nMaxDistance;
};

extern unsigned int gdwBitMasks[]; // 0x006CE268


unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* pUnit, int nX, int nY); // 0x005DC5C0



int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180


int __fastcall sub_00451F30_HasFlags(D2UnitStrc* pUnit, unsigned int nFlags); // 0x00451F30

int __fastcall sub_005A0180_HasMask(D2UnitStrc* pUnit, unsigned short wMask); // 0x005A0180

int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiMode, int bCheckIfSuperUnique); // 0x005B0DA0

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
            int nAreaTile;
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tSearch;
        struct
        {
            D2UnitStrc* pAlternativeTarget;
            int nAlternativeDistance;
        } tEligible;
        D2UnitStrc* pIgnoredTarget;
    };
    int unk0x1C[3];
};

typedef D2UnitStrc* (__fastcall* AIUTIL_TargetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg);

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfFallbackCallback, int nCallbackId); // 0x005DD0B0

int __fastcall MONSTERAI_GetTargetOverrideType(D2UnitStrc* pUnit); // 0x005730E0

int __fastcall MONSTERAI_GetTargetOverrideGUID(D2UnitStrc* pUnit); // 0x00573100


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

static int __stdcall AIUTIL_ResolveTargetOverride(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005DD610

struct D2VileMotherAiCallbackArgStrc;

struct D2PartyCallbackArgStrc;

struct D2CurseStrc;

struct D2UnkAiTableStrc;

enum D2C_F41AiUtilConstants
{
    UNITFLAG_CANBEATTACKED = 4,
    MONTYPEFLAG_UNIQUE_SUPERUNIQUE = 10,
    AISPECIALSTATE_TERROR = 11,
};

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2VileMotherAiCallbackArgStrc
{
    int nLastInClass;
    int nMaxDistance;
    int nCounter;
};

struct D2PartyCallbackArgStrc
{
    AIUTIL_TargetCallback pfCallback;
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    void* pCallbackArg;
};

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790


struct D2UnkAiTableStrc
{
    int nType;
    AIUTIL_TargetCallback pfCallback;
};

extern const D2UnkAiTableStrc gaAiTargetSearchTable[]; // 0x006E3300

void __fastcall AIGENERAL_ExecuteCallbackOnMinions(D2UnitStrc* pUnit, void* pCallbackArg1, void* pCallbackArg2, void(__fastcall* pfnParty)(D2UnitStrc*, void*, void*)); // 0x0058F380

void __fastcall AIUTIL_MinionCallback_FindTarget(D2UnitStrc* pUnit, void* pArg, void* ppUnit); // 0x005DD020

D2UnitStrc* __stdcall AIUTIL_FindPlayerTargetInAdjacentRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback); // 0x005DCEE0





struct D2GameStrc;

#define ROOM_HAS_CLIENTS(pRoom) ((pRoom)->nNumClients & (pRoom)->nNumClients)

static D2UnitStrc* __stdcall AIUTIL_FindTargetInAdjacentRooms(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit);

static D2UnitStrc* __stdcall AIUTIL_FindTargetAmongMinions(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit);

static int __stdcall AIUTIL_ShouldUseAlternativeTarget(D2UnitStrc** ppTarget, int* pTargetDistance, D2UnitStrc* pAlternativeTarget, int nAlternativeDistance, D2UnitStrc* pUnit);

D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pDistance, int* pInMeleeRange);

// 0x005DC360
int __fastcall AIUTIL_GetMonsterVision(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pVision;
    }
    return 0;
}

static __forceinline int MISSMODE_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int MISSMODE_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DC380
int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource)
{
    int nXDiff = MISSMODE_GetUnitX(pTarget) - MISSMODE_GetUnitX(pSource);
    int nYDiff = MISSMODE_GetUnitY(pTarget) - MISSMODE_GetUnitY(pSource);
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    const int nSize = UNITS_GetUnitSizeX(pTarget);
    nXDiff -= nSize;
    nYDiff -= nSize;
    if (nXDiff < 0)
    {
        nXDiff = 0;
    }
    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

struct SynCoord;

struct SynStatic;

struct SynUnit;

struct SynCoord
{
    int nX;
    int nY;
};

struct SynStatic
{
    char unk0[0x0C];
    SynCoord tGameCoords;
};

struct SynUnit { int dwUnitType; char unk4[0x28]; union { SynStatic* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; };

int __stdcall sub_00620510_UNITS_GetUnitSizeX(SynUnit* pUnit); // 0x00620510

static inline int synh_GetUnitX(SynUnit* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int synh_GetUnitY(SynUnit* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static __forceinline int DistanceWithSize(int nX, int nY, SynUnit* pUnit)
{
    int nXDiff = synh_GetUnitX(pUnit) - nX;
    int nYDiff = synh_GetUnitY(pUnit) - nY;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    const int nSize = ((unsigned int)sub_00620510_UNITS_GetUnitSizeX(pUnit) >> 1) + 1;
    nXDiff -= nSize;
    nYDiff -= nSize;
    if (nXDiff < 0)
    {
        nXDiff = 0;
    }
    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

// 0x005DC480
int __fastcall AIUTIL_GetDistanceToCoordinates_HalfUnitSize(SynUnit* pUnit, int nX, int nY)
{
    return DistanceWithSize(nX, nY, pUnit);
}

inline int CLIENTS_GetUnitX_Local(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitY_Local(D2UnitStrc* pUnit)
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

// 0x005DC530
int __fastcall AIUTIL_GetDistanceToCoordinates_NoUnitSize(D2UnitStrc* pUnit, int nX, int nY)
{
    int nXDiff = CLIENTS_GetUnitX_Local(pUnit) - nX;
    int nYDiff = CLIENTS_GetUnitY_Local(pUnit) - nY;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }
    else
    {
        return (nXDiff + 2 * nYDiff) / 2;
    }
}

// 0x005DC5C0
unsigned int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* hUnit, int nX, int nY)
{
    D2_ASSERT(hUnit, 267);
    D2DynamicPathStrc* hPath = hUnit->pDynamicPath;
    D2_ASSERT(hPath, 270);

    int nXDiff = PATH_GetXPosition(hPath) - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    int nYDiff = PATH_GetYPosition(hPath) - nY;
    if (nYDiff < 0)
    {
        nYDiff = -nYDiff;
    }

    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005DC640
int __fastcall AIUTIL_HasClearApproachToTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || !pTarget)
    {
        return 0;
    }

    unsigned char aSteps[25] = { 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    int nStep;
    if (nDistance >= 25)
    {
        nStep = 3;
    }
    else
    {
        nStep = aSteps[nDistance];
    }

    const unsigned int nTargetX = CLIENTS_GetUnitXInline(pTarget);
    const unsigned int nTargetY = CLIENTS_GetUnitYInline(pTarget);
    int nX = CLIENTS_GetUnitXInline(pUnit) - nTargetX;
    int nY = CLIENTS_GetUnitYInline(pUnit) - nTargetY;

    if (nX < 0)
    {
        nX = -nStep;
    }
    else if (nX > 0)
    {
        nX = nStep;
    }

    if (nY < 0)
    {
        nY = -nStep;
    }
    else if (nY > 0)
    {
        nY = nStep;
    }

    if (!UNITS_TestCollisionByCoordinates(pUnit, nTargetX, nTargetY, 0x805))
    {
        return 1;
    }

    if (!UNITS_TestCollisionByCoordinates(pUnit, nTargetX - nY, nTargetY + nX, 0x805))
    {
        return 1;
    }

    return !UNITS_TestCollisionByCoordinates(pUnit, nTargetX + nY, nTargetY - nX, 0x805);
}

// 0x005DC840
int __fastcall AIUTIL_IsActiveUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
        return !SUNIT_IsDead(pUnit);
    case UNIT_MISSILE:
        return 1;
    }
    return 0;
}

// 0x005DC870
int __fastcall AIUTIL_TargetCallback_CountAndFindFriendlyMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2NearestRecord005DC870Strc* pRecord)
{
    if (pUnit == pTarget)
    {
        return 0;
    }
    if (!pTarget)
    {
        return 0;
    }
    const int nUnitType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return 0;
    }
    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance >= pRecord->nMaxDistance)
    {
        return 0;
    }
    if (SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        return 0;
    }
    ++pRecord->nCount;
    if (nDistance < pRecord->nBestDistance)
    {
        pRecord->nBestDistance = nDistance;
        pRecord->pNearest = pTarget;
    }
    return 0;
}

static inline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 2) & 1;
    return bResult;
}

// 0x005DC8E0
D2UnitStrc* __fastcall AIUTIL_TargetCallback_FindMonsterInDeathMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    UnkAiStrc5* pArg = (UnkAiStrc5*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != MONMODE_DEATH)
    {
        return 0;
    }

    return (unsigned int)AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit) < pArg->nMaxDistance ? pTarget : 0;
}

// 0x005DC920
int __fastcall AIUTIL_GetThreat(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return 14;

    case UNIT_MONSTER:
    {
        const int nClassId = pUnit->dwClassId;
        D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nThreat;
        }
        break;
    }

    default:
        break;
    }

    return 0;
}

// 0x005DC970
static int __stdcall AIUTIL_CanSelectHostileTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1 || !pTarget || pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) || !sub_00451F30_TestUnitFlag(pTarget, 4))
    {
        return 0;
    }

    if (STATES_CheckState(pTarget, STATE_INVIS))
    {
        switch (pTarget->dwUnitType)
        {
        case UNIT_PLAYER:
            if ((int)SEED_RollLimitedRandomNumber(&pTarget->pSeed, 100) < 80 && !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                return 0;
            }
            break;
        case UNIT_MONSTER:
            if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                return 0;
            }
            break;
        }
    }

    return SUNIT_AreUnitsHostile(pGame, pUnit, pTarget);
}

// 0x005DCA20
static inline int __stdcall AIUTIL_IsHostileTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || !UNITS_CanBeAttackedInline(pTarget))
    {
        return 0;
    }

    return SUNIT_AreUnitsHostile(pGame, pUnit, pTarget);
}

// 0x005DCA70
D2UnitStrc* __fastcall AIUTIL_TargetCallback_SelectHostileTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiTargetSearchArgsStrc* pArg = (D2AiTargetSearchArgsStrc*)pCallbackArg;

    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType < 0 || pTarget->dwUnitType > 1 || SUNIT_IsDead(pTarget) || !UNITS_CanBeAttackedInline(pTarget) || !SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        if (pTarget->dwUnitType == UNIT_MONSTER && (!pUnit || pUnit->dwUnitType != UNIT_PLAYER) && !STATLIST_GetUnitAlignment(pUnit) && pArg->bCheckTargetCollision && !MONSTERS_IsDead(pTarget))
        {
            D2AiControlStrc* pAiControl = (D2AiControlStrc*)AIGENERAL_GetAiControlFromUnit(pTarget);
            if ((pAiControl->nAiFlags & 8) && pArg->nAreaTile == D2Common_10095(UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget)))
            {
                pAiControl->nAiFlags |= 8;
                pArg->bCheckTargetCollision = 0;
            }
        }

        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > pArg->nMaxDistance)
    {
        return 0;
    }

    const int nThreat = AIUTIL_GetThreat(pTarget);
    if (nThreat > 1)
    {
        if (nDistance >= pArg->nDistance)
        {
            return 0;
        }
    }
    else if (nDistance >= pArg->nAlternativeDistance)
    {
        return 0;
    }

    if (pArg->bCheckTargetCollision && UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        return 0;
    }

    if (nThreat > 1)
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }
    else
    {
        pArg->pAlternativeTarget = pTarget;
        pArg->nAlternativeDistance = nDistance;
    }

    return 0;
}

// 0x005DCBD0
D2UnitStrc* __fastcall AIUTIL_TargetCallback_SelectEligibleHostileTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2UnkAiCallbackArgStrc2* pArg = (D2UnkAiCallbackArgStrc2*)pCallbackArg;

    if (!AIUTIL_CanSelectHostileTarget(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    const int nThreat = AIUTIL_GetThreat(pTarget);
    if (nThreat > 1)
    {
        if (nDistance >= pArg->nDistance)
        {
            return 0;
        }
    }
    else if (nDistance >= pArg->nAlternativeDistance)
    {
        return 0;
    }

    if (!UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        if (nThreat > 1)
        {
            pArg->pTarget = pTarget;
            pArg->nDistance = nDistance;
        }
        else
        {
            pArg->pAlternativeTarget = pTarget;
            pArg->nAlternativeDistance = nDistance;
        }
    }

    return 0;
}

// 0x005DCC60
D2UnitStrc* __fastcall AIUTIL_TargetCallback_SelectHighThreatTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiCallback7ArgStrc* pArg = (D2AiCallback7ArgStrc*)pCallbackArg;

    if (pTarget == pArg->pExcludedUnit)
    {
        return 0;
    }

    if (!AIUTIL_CanSelectHostileTarget(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    if (AIUTIL_GetThreat(pTarget) > 1 && nDistance < pArg->nDistance && !UNITS_TestCollisionWithUnit(pTarget, pUnit, 4))
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }

    return 0;
}

// 0x005DCCC0
D2UnitStrc* __fastcall AIUTIL_TargetCallback_SelectHighThreatTargetWithClearApproach(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2AiCallback11ArgStrc* pArg = (D2AiCallback11ArgStrc*)pCallbackArg;

    if (pTarget == pArg->pExcludedUnit || !AIUTIL_IsHostileTarget(pGame, pUnit, pTarget))
    {
        return 0;
    }

    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pTarget, pUnit);
    if (nDistance > 48)
    {
        return 0;
    }

    if (AIUTIL_GetThreat(pTarget) > 1 && nDistance < pArg->nDistance && AIUTIL_HasClearApproachToTarget(pUnit, pTarget))
    {
        pArg->pTarget = pTarget;
        pArg->nDistance = nDistance;
    }

    return 0;
}

struct D2DoorObjectAiCallbackArgStrc;



// 0x005DCD50
D2UnitStrc* __fastcall AIUTIL_TargetCallback_FindClosestClosedDoor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2DoorObjectAiCallbackArgStrc* pArg = (D2DoorObjectAiCallbackArgStrc*)pCallbackArg;

    if (!pTarget || pTarget->dwUnitType != UNIT_OBJECT || !UnitIsDoor(pTarget) || pTarget->dwAnimMode != OBJMODE_NEUTRAL)
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pTarget, pUnit);
    if (nDistance >= pArg->nDistance)
    {
        return 0;
    }

    pArg->pDoor = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005DCDA0
D2UnitStrc* __fastcall AIUTIL_TargetCallback_CountDeadMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2FallenShamanAiCallbackArgStrc* pArg = (D2FallenShamanAiCallbackArgStrc*)pCallbackArg;
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
    if (nDistance <= pArg->nMaxDistance)
    {
        const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
        if (nType == UNIT_MONSTER && pTarget->dwAnimMode == MONMODE_DEAD)
        {
            const int bTargetable = pTarget ? (pTarget->dwFlags >> 1) & 1 : 0;
            if (bTargetable && !STATES_CheckStateMaskUdeadOnUnit(pTarget) && AIGENERAL_GetMinionOwner(pTarget) == pUnit)
            {
                ++pArg->nCounter;
                pArg->pTarget = pTarget;
                pArg->nDistance = nDistance;
            }
        }
    }

    return 0;
}

// 0x005DCE10
D2UnitStrc* __fastcall AIUTIL_TargetCallback_CountLivingMonstersOfClass(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2VileMotherAiCallbackArgStrc* pArg = (D2VileMotherAiCallbackArgStrc*)pCallbackArg;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pTarget->dwClassId != pArg->nLastInClass)
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    if (AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget) > pArg->nMaxDistance)
    {
        return 0;
    }

    pArg->nCounter += 1;
    return 0;
}

// 0x005DCE60
static D2UnitStrc* __stdcall AIUTIL_FindTargetInAdjacentRooms(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
        {
            D2UnitStrc* pResult = pfCallback(pGame, pUnit, pTarget, pCallbackArg);
            if (pResult)
            {
                return pResult;
            }
        }
    }

    return 0;
}

// 0x005DCEE0
D2UnitStrc* __stdcall AIUTIL_FindPlayerTargetInAdjacentRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        const unsigned int nNumClients = ppRoomList[i]->nNumClients;
        D2ClientStrc** ppClients = ppRoomList[i]->ppClients;
        for (unsigned int j = 0; j < nNumClients; ++j)
        {
            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(ppClients[j], 0);
            if (pPlayer)
            {
                D2UnitStrc* pTarget = pfCallback(pGame, pUnit, pPlayer, pCallbackArg);
                if (pTarget)
                {
                    return pTarget;
                }
            }
        }
    }

    return 0;
}

// 0x005DCF70
static D2UnitStrc* __stdcall sub_005DCF70_FindTargetInAdjacentActiveRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback)
{
    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1)
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if (!DUNGEON_IsRoomInTown(ppRoomList[i]) && ROOM_HAS_CLIENTS(ppRoomList[i]))
        {
            for (D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
            {
                D2UnitStrc* pResult = pfCallback(pGame, pUnit, pTarget, pCallbackArg);
                if (pResult)
                {
                    return pResult;
                }
            }
        }
    }

    return 0;
}

static D2UnitStrc* __stdcall AIUTIL_FindTargetInAdjacentActiveRooms(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfCallback)
{
    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1)
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    unsigned int nNumRooms;
    D2ActiveRoomStrc** ppRoomList;
    unsigned int i;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (i = 0; i < nNumRooms; ++i)
    {
        if (!DUNGEON_IsRoomInTown(ppRoomList[i]))
        {
            D2ActiveRoomStrc* pAdjacentRoom = ppRoomList[i];
            if (pAdjacentRoom->nNumClients)
            {
                for (D2UnitStrc* pTarget = pAdjacentRoom->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
                {
                    D2UnitStrc* pResult = pfCallback(pGame, pUnit, pTarget, pCallbackArg);
                    if (pResult)
                    {
                        return pResult;
                    }
                }
            }
        }
    }

    return 0;
}

// 0x005DD020
void __fastcall AIUTIL_MinionCallback_FindTarget(D2UnitStrc* pUnit, void* pArg, void* ppUnit)
{
    D2PartyCallbackArgStrc* pPartyCallbackArg = (D2PartyCallbackArgStrc*)pArg;
    D2UnitStrc** ppResult = (D2UnitStrc**)ppUnit;
    if (*ppResult)
    {
        return;
    }

    D2GameStrc* pGame = pPartyCallbackArg->pGame;
    D2UnitStrc* pOwner = pPartyCallbackArg->pUnit;
    AIUTIL_TargetCallback pfCallback = pPartyCallbackArg->pfCallback;
    void* pCallbackArg = pPartyCallbackArg->pCallbackArg;
    D2UnitStrc* pResult = pfCallback(pGame, pOwner, pUnit, pCallbackArg);
    if (pResult)
    {
        *ppResult = pResult;
    }
}

// 0x005DD050
static D2UnitStrc* __stdcall AIUTIL_FindTargetAmongMinions(D2GameStrc* pGame, void* pCallbackArg, AIUTIL_TargetCallback pfCallback, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (pOwner->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2UnitStrc* pTarget = 0;
    D2PartyCallbackArgStrc partyCallbackArg;
    partyCallbackArg.pfCallback = pfCallback;
    partyCallbackArg.pGame = pGame;
    partyCallbackArg.pUnit = pUnit;
    partyCallbackArg.pCallbackArg = pCallbackArg;

    AIGENERAL_ExecuteCallbackOnMinions(pOwner, &partyCallbackArg, &pTarget, AIUTIL_MinionCallback_FindTarget);
    return pTarget;
}

// 0x005DD0B0
D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pCallbackArg, AIUTIL_TargetCallback pfFallbackCallback, int nCallbackId)
{
    const int nType = gaAiTargetSearchTable[nCallbackId].nType;
    AIUTIL_TargetCallback pfCallback = gaAiTargetSearchTable[nCallbackId].pfCallback ? gaAiTargetSearchTable[nCallbackId].pfCallback : pfFallbackCallback;
    if (!pfCallback)
    {
        return 0;
    }

    switch (nType)
    {
    case 1:
        return AIUTIL_FindPlayerTargetInAdjacentRooms(pGame, pUnit, pCallbackArg, pfCallback);
    case 2:
        return sub_005DCF70_FindTargetInAdjacentActiveRooms(pGame, pUnit, pCallbackArg, pfCallback);
    case 3:
        return AIUTIL_FindTargetAmongMinions(pGame, pCallbackArg, pfCallback, pUnit);
    default:
        return AIUTIL_FindTargetInAdjacentRooms(pGame, pCallbackArg, pfCallback, pUnit);
    }
}

static inline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
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

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return MONSTERREGION_GetMonStats2TxtRecord(pUnit->dwClassId);
}

static inline void AITHINK_DieInline(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }
    AITACTICS_ChangeModeAndTargetCoordinates(pGame, pUnit, MONMODE_DEATH, 0, 0);
}

// 0x005DD140
D2UnitStrc* __fastcall AIUTIL_TargetCallback_Ubers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2UbersAiCallbackArgStrc* pArg = (D2UbersAiCallbackArgStrc*)pCallbackArg;

    if (pTarget
        && (!pTarget ? 6 : pTarget->dwUnitType) == 1
        && !SUNIT_IsDead(pTarget))
    {
        const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pTarget);
        if (nDistance > pArg->nDistance)
        {
            return 0;
        }

        const int nClassId = pTarget->dwClassId;
        if (nClassId == 704)
        {
            pArg->nUberMephisto++;
            return 0;
        }
        if (nClassId == 705)
        {
            pArg->nUberDiablo++;
            return 0;
        }
        if (nClassId == 709)
        {
            pArg->nUberBaal++;
            return 0;
        }
        if (nClassId == 711)
        {
            pArg->nDiabloSpawner++;
            return 0;
        }
        if (nClassId == 712)
        {
            pArg->nDiabloMinions++;
            return 0;
        }
        if (nClassId == 732 || nClassId == 731 || nClassId == 733)
        {
            pArg->nBaalMinions++;
            return 0;
        }
        pArg->nOtherMonsters++;
    }

    return 0;
}

// 0x005DD220
extern "C" __declspec(dllexport) int __fastcall AIUTIL_CheckAiControlFlag(Obj005DD220* pObj, unsigned short wMask) {
    if (pObj->wFlags08 & wMask)
        return 1;
    return 0;
}

// 0x005DD230
extern "C" __declspec(dllexport) void __fastcall AIUTIL_ToggleAiControlFlag(Obj005DD230* pObj, unsigned short wMask, int bSet) {
    if (bSet) {
        pObj->wFlags08 |= wMask;
    } else {
        pObj->wFlags08 &= ~wMask;
    }
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005DD250
void __fastcall AIUTIL_ToggleAiControlFlag0x20(D2UnitStrc* pUnit, int bSet)
{
    D2AiControlStrc* pAiControl;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER) {
        D2MonsterDataStrc* m = pUnit->pMonsterData;
        if (m) { pAiControl = m->pAiControl; }
        else pAiControl = 0;
    } else pAiControl = 0;
    if (bSet)
        pAiControl->nAiFlags |= 0x20;
    else
        pAiControl->nAiFlags &= ~0x20;
}

// 0x005DD280
int __fastcall AIUTIL_GetLifePercentage(D2UnitStrc* pArg)
{
    return UNITS_GetCurrentLifePercentage(pArg);
}

// 0x005DD290
int __fastcall AIUTIL_HasClearMissilePath(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return UNITS_TestCollisionWithUnit(pUnit, pTarget, 4) == 0;
}

// 0x005DD2B0
int __fastcall AIUTIL_IsGettingHit(D2UnitStrc* pUnit)
{
    const unsigned int nAiState = MONSTER_GetAiState(pUnit);
    return nAiState == 3 || nAiState == 19;
}

static inline D2AiControlStrc* GetAiControl(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == 1 && pUnit->pMonsterData)
        return pUnit->pMonsterData->pAiControl;
    return 0;
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    return nUnitType;
}

// 0x005DD2D0
int __fastcall AIUTIL_CheckIfMonsterUsesSkill(D2UnitStrc* pUnit, int nSkillId)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nType == UNIT_MONSTER)
    {
        pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] == nSkillId)
        {
            return 1;
        }
    }

    return 0;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline int MONSTERS_GetBaseIdFromMonsterId(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return nMonsterId;
    }

    return pMonStatsTxtRecord->nBaseId;
}

static inline int CLIENTS_GetUnitXForceInline(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYForceInline(D2UnitStrc* pUnit)
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

// 0x005DD330
void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return;
    D2AiControlStrc* pAi = GetAiControl(pUnit);
    if (pOwner)
    {
        pAi->dwOwnerGUID = pOwner->dwUnitId;
        pAi->dwOwnerType = GetUnitType(pOwner);
    }
    else
    {
        pAi->dwOwnerGUID = -1;
        pAi->dwOwnerType = 1;
    }
}

// 0x005DD370
D2UnitStrc* __fastcall AIUTIL_FindMonsterAtCoords(D2GameStrc* game,D2ActiveRoomStrc* room,int x,int y,int baseId)
{
 D2_ASSERT(room,1954);
 room=sub_00463740_FindRoomAtPoint(room,x,y);
 D2_ASSERT(room,1956);
 for(D2UnitStrc* unit=room->pUnitFirst;unit;unit=unit->ptRoomNext) {
  if((!unit ? 6 : unit->dwUnitType)!=1) continue;
  int nBase = MONSTERS_GetBaseIdFromMonsterId(unit->dwClassId);

  if (unit->dwClassId) { if (nBase != baseId) continue; } else { if (nBase != baseId) continue; }
  if (CLIENTS_GetUnitXForceInline(unit)==x && CLIENTS_GetUnitYForceInline(unit)==y) return unit;
 }
 return 0;
}

// 0x005DD480
int __fastcall AIUTIL_CanUnitSwitchAi(D2UnitStrc* pUnit, int nAiMode)
{
    if (!pUnit)
    {
        return 0;
    }
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return 0;
    }
    if (nAiMode > 0x13)
    {
        return 0;
    }
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }
    if (!UNITS_CanSwitchAI(pUnit->dwClassId))
    {
        return 0;
    }
    if (!sub_00451F30_HasFlags(pUnit, 4) && !SUNIT_IsDead(pUnit))
    {
        return 0;
    }
    if (sub_005A0180_HasMask(pUnit, 10))
    {
        return 0;
    }
    if (nAiMode != 0x13)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!AITHINK_CanUnitSwitchAi(pUnit, pMonStatsTxtRecord, nAiMode, 1))
        {
            return 0;
        }
    }
    return 1;
}

static inline int AIUTIL_IsOverrideTargetValid_Inline(D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
        return !SUNIT_IsDead(pTarget);
    case UNIT_MISSILE:
        return 1;
    }
    return 0;
}

// 0x005DD510
static int __stdcall AIUTIL_ShouldUseAlternativeTarget(D2UnitStrc** ppTarget, int* pTargetDistance, D2UnitStrc* pAlternativeTarget, int nAlternativeDistance, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
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
    const int nPathType = PATH_GetType(pPath);
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
    arg.pIgnoredTarget = pCurrentTarget;
    AIUTIL_FindTargetWithCallback(SUNIT_GetGameFromUnit(pUnit), pUnit, &arg, 0, 7);

    if (!arg.pTarget || arg.nDistance >= 20)
    {
        return 1;
    }

    *ppTarget = arg.pTarget;
    *pTargetDistance = arg.nDistance;
    return 0;
}

// 0x005DD610
static int __stdcall AIUTIL_ResolveTargetOverride(int bCheckCollision, int bUseEligibilityCheck, D2UnitStrc** ppUnit, int* pDistance, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = 0;
    int nDistance = 0;

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
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
                SUNIT_SetAlignment(pUnit, 2, 1);
            }
            else
            {
                SUNIT_SetAlignment(pUnit, 0, 1);
            }
        }
        else if (sub_00472210_SeedRollMasked(&pUnit->pSeed, 2))
        {
            if (nAlignment == 0)
            {
                SUNIT_SetAlignment(pUnit, 2, 1);
            }
            else if (nAlignment == 2)
            {
                SUNIT_SetAlignment(pUnit, 0, 1);
            }
        }

        D2AiTargetArgsStrc arg;
        if (!bUseEligibilityCheck)
        {
            arg.pTarget = 0;
            arg.nDistance = 0x7FFFFFFF;
            const int nAreaTile = D2Common_10095(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            arg.tSearch.bCheckTargetCollision = bCheckCollision;
            arg.tSearch.nMaxDistance = 35;
            arg.tSearch.nAreaTile = nAreaTile;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 5);
        }
        else
        {
            arg.pTarget = 0;
            arg.nDistance = 0x7FFFFFFF;
            arg.tEligible.pAlternativeTarget = 0;
            arg.tEligible.nAlternativeDistance = 0x7FFFFFFF;
            AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 6);
        }

        pTarget = arg.pTarget;
        nDistance = arg.nDistance;
        SUNIT_SetAlignment(pUnit, nAlignment, 1);
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

static inline int AIUTIL_GetMonsterVisionInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        if (pUnit->pMonsterData)
        {
            return pUnit->pMonsterData->pVision;
        }
        return 0;
    }
    return 0;
}

// 0x005DD7F0
D2UnitStrc* __fastcall AIUTIL_FindAiTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int* pDistance, int* pCombat)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    int* pVision = 0;
    int nOldVisionToggle = 0;
    int bCheckCollision;
    int bHadFlag = AIUTIL_CheckAiControlFlag((Obj005DD220*)pAiControl, 0x40);
    if (bHadFlag)
    {
        bCheckCollision = 1;
    }
    else if (DUNGEON_CheckLOSDraw(pRoom))
        bCheckCollision = 0;
    else
    {
        bCheckCollision = !AIUTIL_CheckAiControlFlag((Obj005DD220*)pAiControl, 8);
        const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (nType == UNIT_MONSTER)
        {
            pVision = (int*)AIUTIL_GetMonsterVisionInline(pUnit);
            if (bCheckCollision && pVision)
            {
                nOldVisionToggle = pVision[9];
                bCheckCollision = nOldVisionToggle == 0;
            }
        }
    }
    if (bCheckCollision && bHadFlag)
        AIUTIL_ToggleAiControlFlag((Obj005DD230*)pAiControl, 0x40, 0);

    D2UnitStrc* pTarget = 0;
    int nDistance;
    unsigned int nMinDistance = 0x7FFFFFFF;
    if (!AIUTIL_ResolveTargetOverride(bCheckCollision, 0, &pTarget, &nDistance, pGame, pUnit))
    {
        if (STATLIST_GetUnitAlignment(pUnit) == 0)
        {
            D2TargetNodeStrc** ppNode = pGame->pTargetNodes;
            D2TargetNodeStrc* pNode = *ppNode;
            pTarget = 0;
            nDistance = 35;
            D2MonStatsTxt* pMonStats = 0;
            if (pUnit && pUnit->dwUnitType == 1 && pUnit->pMonsterData)
                pMonStats = (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
            if (pMonStats)
            {
                unsigned char nThreat = pMonStats->nAiDist[pGame->nDifficulty];
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
                    D2UnitStrc* pCurrent = pNode->hUnit;
                    D2_ASSERT(pCurrent && pCurrent->dwUnitType == 0, 0x5F6);
                    if (nAct == pCurrent->nAct && UNITS_GetRoom(pCurrent) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pCurrent)))
                    {
                        unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
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
                                pCurrent = pNode->hUnit;
                                nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
                            }
                        }
                    }
                }
                pNode = *++ppNode;
            }
            while (pNode)
            {
                D2UnitStrc* pCurrent = pNode->hUnit;
                if (nAct == pCurrent->nAct)
                {
                    const unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
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
                D2UnitStrc* pCurrent = pNode->hUnit;
                if (nAct == pCurrent->nAct)
                {
                    const unsigned int nCurrentDistance = (unsigned int)AIUTIL_GetDistanceToCoordinates_NoUnitSize(pCurrent, nX, nY);
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
            const int nCollision = D2Common_10095(pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
            D2AiTargetArgsStrc arg;
            arg.pTarget = 0;
            arg.nDistance = 0x7FFFFFFF;
            arg.tSearch.bCheckTargetCollision = bCheckCollision;
            arg.tSearch.nMaxDistance = 35;
            arg.tSearch.nAreaTile = nCollision;
            arg.tSearch.pAlternativeTarget = 0;
            arg.tSearch.nAlternativeDistance = 0x7FFFFFFF;
            AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 5);
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
        pAiControl->nAiFlags |= 8;
        if (pVision)
            pVision[9] = nOldVisionToggle == 0;
    }
    *pCombat = UNITS_IsInMeleeRange(pUnit, pTarget, 0);
    *pDistance = nDistance;
    return pTarget;
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
        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 6);

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

// 0x005DDD00
void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nParam1, int nDuration)
{
    if (SUNIT_IsDead(pTarget))
    {
        return;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    if (STATES_CheckState(pTarget, STATE_UNINTERRUPTABLE))
    {
        return;
    }

    if (!UNITS_CanSwitchAI(pTarget->dwClassId))
    {
        return;
    }

    if (!sub_00451F30_TestUnitFlag(pTarget, UNITFLAG_CANBEATTACKED) && !SUNIT_IsDead(pTarget))
    {
        return;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pTarget, MONTYPEFLAG_UNIQUE_SUPERUNIQUE))
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
    if (!AITHINK_CanUnitSwitchAi(pTarget, pMonStatsTxtRecord, AISPECIALSTATE_TERROR, 1))
    {
        return;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkillLevel = 1;
    curse.nDuration = nDuration;
    curse.nStat = -1;
    curse.nSkill = SKILL_TERROR;
    curse.nState = STATE_TERROR;
    SKILLS_ApplyStateEffect(&curse);

    UNITS_SetTargetUnitForDynamicUnit(pTarget, pUnit);

    D2AiControlStrc* pAiControl = (pTarget->dwUnitType == UNIT_MONSTER && pTarget->pMonsterData) ? pTarget->pMonsterData->pAiControl : 0;
    AITHINK_ExecuteAiFn(pGame, pTarget, pAiControl, AISPECIALSTATE_TERROR);
    D2GAME_EVENTS_Delete(pGame, pTarget, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pTarget, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
}

// 0x005FD7B0
int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int bUseResurrectConfig)
{
    if (bUseResurrectConfig)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecordFromUnit(pUnit);
        if (pMonStats2TxtRecord)
        {
            const unsigned short nSkillId = pMonStats2TxtRecord->nResurrectSkill;
            if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
            {
                UNITS_SetUsedSkill(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId));
            }

            if (pMonStats2TxtRecord->nResurrectMode < 16)
            {
                return pMonStats2TxtRecord->nResurrectMode;
            }
        }
        return MONMODE_NEUTRAL;
    }

    return MONMODE_NEUTRAL;
}

extern "C" void __cdecl sub_005DC8E0(); // 0x005DC8E0
extern "C" void __cdecl sub_005DCBD0(); // 0x005DCBD0
extern "C" void __cdecl sub_005DCC60(); // 0x005DCC60
extern "C" void __cdecl sub_005DCCC0(); // 0x005DCCC0
extern "C" void __cdecl sub_005DCE10(); // 0x005DCE10

extern const D2UnkAiTableStrc gaAiTargetSearchTable[13] = {
    { 0 },
    { 0 },
    { 1 },
    { 0, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&AIUTIL_TargetCallback_CountAndFindFriendlyMonster },
    { 0, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&sub_005DC8E0 },
    { 2, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&AIUTIL_TargetCallback_SelectHostileTarget },
    { 0, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&sub_005DCBD0 },
    { 0, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&sub_005DCC60 },
    { 0, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&AIUTIL_TargetCallback_FindClosestClosedDoor },
    { 3, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&AIUTIL_TargetCallback_CountDeadMinions },
    { 3 },
    { 2, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&sub_005DCCC0 },
    { 0, (D2UnitStrc *(__fastcall *)(D2GameStrc *, D2UnitStrc *, D2UnitStrc *, void*))&sub_005DCE10 }
}; // 0x006E3300
