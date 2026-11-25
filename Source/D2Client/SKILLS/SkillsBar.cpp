#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

struct D2UnitStrc;

#define UNIT_MONSTER 1

#define UNIT_INVALID 6

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2MonStatsTxt;

struct D2CharStatsTxt;

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_INTOWN = 8,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

void __fastcall SKILLS_AttachMoveSkillEndList(D2UnitStrc* pUnit); // 0x004C7950

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

int __stdcall D2Common_11025(int nX1, int nY1, int nX2, int nY2, D2ActiveRoomStrc* pRoom, int nMask); // 0x00645910

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

static int __stdcall SKILLSBAR_CanTargetRoom(int nSkillId, D2UnitStrc* pUnit, int nX, int nY); // 0x004C8350

static int __stdcall SKILLS_AdjustTargetPosition(int nSkillId, D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY); // 0x004C80D0

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pDynamicPath); // 0x00650590

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

void __stdcall PATH_SetTargetUnit(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, int nArg); // 0x00649F70

int __stdcall GFXUTIL_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall CUNIT_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags); // 0x004654C0

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20

int __fastcall UNITSND_GetDirectionRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA4C0

int __fastcall SKILLSBAR_SetRunPath(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004C85B0

void __fastcall SKILLSBAR_SetLobVelocity(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004C8670

int __stdcall SKILLS_CheckIfCanLeapTo(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int* pX, int* pY); // 0x00645CA0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nRangeBonus); // 0x00622C40

int __fastcall SKILLS_RaiseTargetUnitEvent(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x004C7630

static void __stdcall SKILLSBAR_LeapBounceFromTarget(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY); // 0x004C8750

static void __stdcall SKILLSBAR_EndLeapPath(D2UnitStrc* pUnit, int nX, int nY); // 0x004C8890

inline int UNITS_GetXInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYInline(D2UnitStrc* pUnit)
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

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

int __fastcall GFX_DrawUnit(D2UnitStrc* pUnit, unsigned int dwColor, int nX, int nY, int nArg, int bOverlay); // 0x00471EC0

void __fastcall GFXUTIL_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames); // 0x004DA5B0

struct D2LobBracketStrc
{
    int nMaxDistance;
    int nMultiplier;
    int nAddend;
};

extern D2LobBracketStrc gaLobBrackets[2]; // 0x006DAE70

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

// 0x004C8350
static int __stdcall SKILLSBAR_CanTargetRoom(int nSkillId, D2UnitStrc* pUnit, int nX, int nY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    D2ActiveRoomStrc* pTarget = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pTarget)
        return 0;
    if (!(pSkillsTxt->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]) && DUNGEON_IsRoomInTown(pTarget))
        return 0;
    return 1;
}

// 0x004C80D0
static int __stdcall SKILLS_AdjustTargetPosition(int nSkillId, D2UnitStrc* pUnit, int nSkillLevel, int* pX, int* pY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;

    const int nUnitX = UNITS_GetXInline(pUnit);
    const int nUnitY = UNITS_GetYInline(pUnit);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nDistance = DRLG_GetDistanceToXY(pUnit, *pX, *pY);
    if (nDistance <= 1)
        nDistance = 1;
    if (nDistance > nRange)
    {
        const int nDeltaX = *pX - nUnitX;
        const int nDeltaY = *pY - nUnitY;
        *pX = nUnitX + nDeltaX * nRange / nDistance;
        *pY = nUnitY + nDeltaY * nRange / nDistance;
    }

    nSkillLevel = *pY - nUnitY;
    nSkillLevel = D2_MIN(D2_MAX(nSkillLevel, -2), 2);
    int nOffsetY = nUnitX - *pX;
    nOffsetY = D2_MIN(D2_MAX(nOffsetY, -2), 2);

    D2CoordStrc tCoord;
    tCoord.nX = *pX;
    tCoord.nY = *pY;
    int nTries = 3;
    while (nTries)
    {
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), tCoord.nX, tCoord.nY);
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &tCoord, UNITS_GetUnitSizeX(pUnit), 0x1C09, 1);
        const int nAdjustedX = tCoord.nX;
        const int nAdjustedY = tCoord.nY;
        if (pRoom
            && !COLLISION_CheckAnyCollisionWithPattern(pRoom, nAdjustedX, nAdjustedY, PATH_GetUnitCollisionPattern(pUnit), 0x1C09)
            && D2Common_11025(nUnitX, nUnitY, nAdjustedX, nAdjustedY, pRoom, 0x804)
            && DRLG_GetDistanceToXY(pUnit, nAdjustedX, nAdjustedY) <= nRange)
        {
            *pX = nAdjustedX;
            *pY = nAdjustedY;
            return 1;
        }

        --nTries;
        if (nTries == 2)
        {
            tCoord.nX = *pX + nSkillLevel;
            tCoord.nY = *pY + nOffsetY;
        }
        else if (nTries == 1)
        {
            tCoord.nX = *pX - nSkillLevel;
            tCoord.nY = *pY - nOffsetY;
        }
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
        UNITSND_PlayPlayerSpeech(pUnit, 19);
    return 0;
}

void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900

void __fastcall sub_004BA840(void* pUnitSfx); // 0x004BA840

// 0x004C83C0
int __fastcall SKILLSBAR_SkillCltStartPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
            return 0;
        if (SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillsBar.cpp", 442) == nSkillId && (SKILLS_GetFlags(pSkill) & 1))
            return 0;
    }

    const int bMonster = (!pUnit ? 6 : pUnit->dwUnitType) == 1;
    int nX;
    int nY;
    if (bMonster)
    {
        D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
        if (!pTarget)
        {
            if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
                return 0;
            SKILLS_SetParam4(pSkill, -1);
        }
        else
        {
            nX = CLIENTS_GetUnitX(pTarget);
            nY = CLIENTS_GetUnitY(pTarget);
            nX = 2 * nX - CLIENTS_GetUnitX(pUnit);
            nY = 2 * nY - CLIENTS_GetUnitY(pUnit);
        }

        D2CoordStrc tCoord;
        tCoord.nX = nX;
        tCoord.nY = nY;
        if (!COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0))
            return 0;
        nX = tCoord.nX;
        nY = tCoord.nY;
    }
    else
    {
        if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
            return 0;
        if (!SKILLSBAR_CanTargetRoom(nSkillId, pUnit, nX, nY))
            return 0;
        if (!SKILLS_AdjustTargetPosition(nSkillId, pUnit, nSkillLevel, &nX, &nY))
            return 0;
    }

    D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    if (bMonster)
    {
        D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
        if (pTarget)
        {
            SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
            SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
    }
    SKILLS_SetFlags(pSkill, 0x1080);
    SKILLS_AttachMoveSkillEndList(pUnit);
    return 1;
}

// 0x004C85B0
int __fastcall SKILLSBAR_SetRunPath(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0x1101);
    PATH_SetMoveTestCollisionMask(pDynamicPath, 0);
    PATH_SetFootprintCollisionMask(pDynamicPath, 0);
    D2COMMON_10170_PathSetTargetPos(pDynamicPath, nX, nY);
    PATH_SetType(pDynamicPath, 9);

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int nClassId = pUnit->dwClassId;
    int nVelocity;
    if (nType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        nVelocity = pMonStatsTxtRecord->nRun << 8;
    }
    else
    {
        nVelocity = sub_004833E0_GetCharStatsTxtRecord(nClassId)->nRunSpeed << 8;
    }

// build: symbol ?gszSkillsBarSourceFile@* 0x006DAE58
    PATH_SetVelocity(pDynamicPath, nVelocity, gszSkillsBarSourceFile, 567);
    D2Common_10142(pDynamicPath, pUnit, 0);
    return 1;
}

// 0x004C8670
void __fastcall SKILLSBAR_SetLobVelocity(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    const int nSpeed = PATH_GetVelocity(pDynamicPath) >> 8;
    if (!nSpeed)
    {
        return;
    }

    int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nX, nY);
    if (nDistance < 1)
    {
        nDistance = 1;
    }

    int nFrames = (nDistance << 0x10) / (nSpeed << 0x0C);
    if (nFrames > 1)
    {
        nFrames -= 1;
    }

    int i = 0;
    for (; i < 1; i++)
    {
        if (nDistance < gaLobBrackets[i].nMaxDistance)
        {
            break;
        }
    }

    int nVelocity = gaLobBrackets[i].nMultiplier * nDistance + gaLobBrackets[i].nAddend;
    if (nVelocity < 0x1F4)
    {
        nVelocity = 0x1F4;
    }

    sub_004DA000(pUnit);
    sub_004DA250(pUnit, 0, 0, -nVelocity, 0);
    GFXUTIL_SetBallistic(pUnit, 0, nFrames);
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

// 0x004C8750
static void __stdcall SKILLSBAR_LeapBounceFromTarget(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
        return;

    D2UnitStrc* pTarget = CUNIT_FindClientUnit(SKILLS_GetParam4(pSkill), SKILLS_GetParam3(pSkill));
    if (!pTarget)
        return;

    SKILLS_SetFlags(pSkill, 1);
    UNITS_SetAnimationFrame(pUnit, 12);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    D2COMMON_10212_PATH_SetMoveFlags(pUnit, 0);
    PATH_RecacheRoomIfNeeded(pPath);
    PATH_SetNewDistance(pPath, 5);
    PATH_SetStepNum(pPath, 1);
    PATH_SetTargetUnit(pPath, 0);

    nX = 3 * nX - 2 * CLIENTS_GetUnitXInline(pTarget);
    nY = 3 * nY - 2 * CLIENTS_GetUnitYInline(pTarget);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
    {
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        PATH_SetType(pPath, 11);
        D2COMMON_10190_PATH_SetDistance(pPath, 5);
        D2Common_10142(pPath, pUnit, 0);
    }
}

// 0x004C8890
static void __stdcall SKILLSBAR_EndLeapPath(D2UnitStrc* pUnit, int nX, int nY)
{
    int nUnitType;
    if (!pUnit)
        nUnitType = UNIT_INVALID;
    else
        nUnitType = pUnit->dwUnitType;

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pPath || !pRoom)
        return;

    if (nUnitType == UNIT_MONSTER)
    {
        if (nX && nY)
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
        PATH_SetFootprintCollisionMask(pPath, 0x100);
        PATH_SetMoveTestCollisionMask(pPath, 0x3C01);
        PATH_SetType(pPath, 2);
    }
    else
    {
        if (nX && nY)
            COLLISION_ResetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x80);
        PATH_SetFootprintCollisionMask(pPath, 0x80);
        PATH_SetMoveTestCollisionMask(pPath, 0x1C09);
        PATH_SetType(pPath, 7);
    }

    if (CUNIT_IsDeadOrDying(pUnit))
        PATH_SetUnitDeadCollision(pUnit, 0);
}

static inline D2MonStatsTxt* MONSTATS_GetRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static inline int MONSTATS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
        return nClassId;
    return pMonStatsTxtRecord->nBaseId;
}

static inline int MONSTERS_GetBaseIdInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return MONSTATS_GetBaseIdInline(pUnit->dwClassId);
    return -1;
}

// 0x004C8970
static int __stdcall SKILLSBAR_UpdateLeap(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bOverlay)
{
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    const int nMotion = GFXUTIL_GetMotionAZ(pUnit);
    int nUnitType = UNIT_INVALID;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    const int bMonster = nUnitType == UNIT_MONSTER;

    int nBaseId;
    if (bMonster)
    {
        const int nId = MONSTERS_GetBaseIdInline(pUnit);
        nBaseId = (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount) ? -1 : nId;
    }
    else
    {
        nBaseId = -1;
    }

    if (nMotion && (CLIENTS_GetUnitXInline(pUnit) != nX || CLIENTS_GetUnitYInline(pUnit) != nY))
    {
        if (bMonster)
        {
            int nFrame = 0;
            if (nBaseId == MONSTER_SANDLEAPER1)
                nFrame = 8;
            else if (nBaseId == MONSTER_ANCIENTBARB1)
                nFrame = (unsigned int)UNITS_GetDistanceToCoordinates(pUnit, nX, nY) < 2 ? 12 : 10;

            UNITS_SetAnimationFrame(pUnit, nFrame);
            pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
            return 0;
        }

        UNITS_SetAnimationFrame(pUnit, 10);
        pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
        return 0;
    }

    SKILLSBAR_EndLeapPath(pUnit, nX, nY);
    GFXUTIL_SetMotionVectorA(pUnit, 0, 0, 0);
    if (bOverlay)
        GFX_AddUnitOverlay(pUnit, 0x50, 2, 0, 0, 0, 0, 0);

    if (bMonster)
    {
        sub_004B9A00(sub_004CAEB0(pUnit, 1), pUnit, 0, 0, 0);
        if (nBaseId == MONSTER_SANDLEAPER1)
            SKILLSBAR_LeapBounceFromTarget(pUnit, pSkill, nX, nY);
        return 1;
    }

    sub_004B9A00(sub_004CAEB0(pUnit, 1), pUnit, 0, 0, 0);
    sub_004B9A00(0x9D5, pUnit, 0, 0, 0);
    return 1;
}

// 0x004C8B80
void __fastcall SKILLSBAR_ResetLeapCollision(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* const pPath = pUnit->pDynamicPath;
    const int nFootprint = PATH_GetFootprintCollisionMask(pPath);
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int nMask = nUnitType == UNIT_MONSTER ? 0x100 : 0x80;
    if (nFootprint == nMask)
        return;

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    const int nX = pSkill ? SKILLS_GetParam1(pSkill) : CLIENTS_GetUnitXInline(pUnit);
    const int nY = pSkill ? SKILLS_GetParam2(pSkill) : CLIENTS_GetUnitYInline(pUnit);
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nMask);
    CUNIT_SetUnitPosition(pUnit, nX, nY, 0);
    SKILLSBAR_EndLeapPath(pUnit, nX, nY);
}

static int __stdcall SKILLSBAR_UpdateLeap(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bOverlay); // 0x004C8970

void __fastcall SKILLSBAR_ResetLeapCollision(D2UnitStrc* pUnit); // 0x004C8B80

// 0x004C8C60
int __fastcall SKILLSBAR_SkillCltDoLeap(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
        return 0;

    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 0x100)
    {
        if (!SKILLSBAR_UpdateLeap(pUnit, pSkill, 1) && !(nFlags & 2))
            return 0;
    }

    if (nFlags & 2)
    {
        SKILLSBAR_EndLeapPath(pUnit, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit));
        SKILLS_SetFlags(pSkill, 0);
        return 1;
    }

    if (nFlags & 0x80)
    {
        SKILLSBAR_SetRunPath(pUnit, pSkill);
        SKILLSBAR_SetLobVelocity(pUnit, pSkill);
        return 1;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_MONSTER)
        SKILLS_SetFlags(pSkill, 0x1000);

    return 1;
}

// 0x004C8D90
int __fastcall SKILLSBAR_SkillCltStartLeap(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
        return 0;

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
            return 0;

        if (SKILLS_GetSkillIdFromSkill(pSkill, gszSkillsBarSourceFile, 930) == nSkillId && (SKILLS_GetFlags(pSkill) & 1))
            return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    int nX = 0;
    int nY = 0;
    if (!SKILLS_CheckIfCanLeapTo(pUnit, pTarget, &nX, &nY))
    {
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            return SKILLS_RaiseTargetUnitEvent(pUnit, pTarget);

        if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
            UNITSND_PlayPlayerSpeech(pUnit, 0x13);

        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;

    const int nPattern = PATH_GetUnitCollisionPattern(pUnit);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, nPattern, 0x80);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    if (pTarget)
    {
        SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
        SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    }
    else
    {
        SKILLS_SetParam3(pSkill, 6);
    }
    SKILLS_SetFlags(pSkill, 0x1080);
    SKILLS_AttachMoveSkillEndList(pUnit);
    return 1;
}

// 0x004C8ED0
int __fastcall SKILLSBAR_SkillCltDoLeapAttack(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
        return 0;

    int nResult = 0;
    const int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 0x100)
    {
        if (!SKILLSBAR_UpdateLeap(pUnit, pSkill, 1))
        {
            if (!(nFlags & 2))
                return 0;
        }
        else
        {
            const int nTargetType = SKILLS_GetParam3(pSkill);
            const int nTargetId = SKILLS_GetParam4(pSkill);
            D2UnitStrc* pTarget = 0;
            if (nTargetType != UNIT_INVALID)
                pTarget = CUNIT_FindClientUnit(nTargetId, nTargetType);
            if (!pTarget)
                pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 0, -1, 0);

            if (pTarget)
            {
                UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
                sub_00465BF0(pUnit, 0);
                sub_004B9A00(UNITSND_GetDirectionRate(pUnit, UNITS_GetHitClass(pUnit)), pUnit, 0, 0, 0);
                nResult = 1;
            }
            else
            {
                pUnit->dwFrameCountPrecise = 0x400;
            }
        }
    }

    if (nFlags & 2)
    {
        SKILLSBAR_EndLeapPath(pUnit, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit));
        SKILLS_SetFlags(pSkill, 0);
        return 1;
    }

    if (nFlags & 0x80)
    {
        SKILLSBAR_SetRunPath(pUnit, pSkill);
        SKILLSBAR_SetLobVelocity(pUnit, pSkill);
        return 1;
    }

    SKILLS_SetFlags(pSkill, 0x1000);
    return nResult;
}

// 0x004C9060
void __fastcall SKILLSBAR_RotateUnitDirection(D2UnitStrc* pUnit, int nArg, int bForward)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return;
    }

    const int nDirection = PATH_GetDirection(pPath);
    sub_006488A0_SetDirection(pPath, (bForward ? nDirection + 0x15 : nDirection + 0x2A) % 64);

    int nX;
    int nY;
    if (sub_004F51D0_IsPerspective())
    {
        SCALE_ScalePerspectivePosition(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0x60, &nX, &nY, 0);
        nX += PLAYER_GetScreenOffsetX();
        nY += PLAYER_GetScreenOffsetY();
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit);
        nY = UNITS_GetClientCoordY(pUnit);
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    GFX_DrawUnit(pUnit, nArg, nX, nY, nUnitType == 0, 0);
    sub_006488A0_SetDirection(pPath, nDirection);
}


int __fastcall SKILLSBAR_SkillCltDoLeap(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004C8C60

int __fastcall SKILLSBAR_SkillCltDoLeapAttack(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004C8ED0

static inline int UNITS_GetUnitType_C9120(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

// 0x004C9120
int __fastcall SKILLSBAR_SkillCltStartRun(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 0 && nUnitType != 1)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pSkill || !pPath)
    {
        return 0;
    }

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        if (SKILLS_GetSkillIdFromSkill(pSkill, gszSkillsBarSourceFile, 1129) == nSkillId && (SKILLS_GetFlags(pSkill) & 1))
        {
            return 0;
        }

        if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
        {
            return 0;
        }
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return SKILLS_RaiseTargetUnitEvent(pUnit, pTarget);
    }

    const int bPlayer = UNITS_GetUnitType_C9120(pUnit) == 0;
    const int nRestoreMask = bPlayer ? 0x1C09 : 0x3C01;
    const int nUnitMask = bPlayer ? 0x80 : 0x100;

    PATH_SetMoveTestCollisionMask(pPath, 0xC01);
    PATH_SetType(pPath, 7);
    if (!D2Common_10142(pPath, pUnit, 0))
    {
        PATH_SetMoveTestCollisionMask(pPath, nRestoreMask);
        return 0;
    }

    if (bPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = sub_004833E0_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            PATH_SetVelocity(pPath, pCharStatsTxtRecord->nWalkSpeed << 8, gszSkillsBarSourceFile, 1177);
        }
    }
    else
    {
        PATH_SetVelocity(pPath, DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId)->nVelocity << 8, gszSkillsBarSourceFile, 1183);
    }

    PATH_SetMoveTestCollisionMask(pPath, 0x401);

    D2PathPointStrc* pPathPoints;
    const int nPoints = PATH_GetPathPoints(pPath, &pPathPoints);
    if (!nPoints)
    {
        PATH_SetMoveTestCollisionMask(pPath, nRestoreMask);
        return 0;
    }

    nX = pPathPoints[nPoints - 1].X;
    nY = pPathPoints[nPoints - 1].Y;
    COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nUnitMask);
    SKILLS_SetFlags(pSkill, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    SKILLS_AttachMoveSkillEndList(pUnit);
    return 1;
}

// 0x004C9320
int __fastcall SKILLSBAR_SkillCltDoCollide(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill || !pDynamicPath)
        return 0;

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    const int bPlayer = nUnitType == 0;
    const int nMask = bPlayer ? 0x80 : 0x100;
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    const int nFlags = SKILLS_GetFlags(pSkill);
    if ((nFlags & 3) == 3)
    {
        COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), nMask);
        PATH_SetFootprintCollisionMask(pDynamicPath, nMask);
        PATH_SetMoveTestCollisionMask(pDynamicPath, bPlayer ? 0x1C09 : 0x3C01);
        SKILLS_SetFlags(pSkill, 0);
        sub_004BA840(UNITSND_FindUnitSfxInRange(pUnit, 0x9E3));
    }
    else if (nFlags & 1)
    {
        UNITS_SetAnimationFrame(pUnit, 3);
        pUnit->dwFrameCountPrecise = 0x500;
    }
    return 1;
}


#include "gen/data/Source/D2Client/SKILLS/SkillsBar.inc"
