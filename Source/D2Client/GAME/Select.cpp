#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2Txt.h"
#include "D2ObjModes.h"
#include "D2StateIds.h"
#include "D2Drlg.h"
#include "D2ClientTypes.h"
#include "D2ClientUiRecords.h"
#include "D2WinSplitText.h"
struct D2ActiveRoomStrc;
struct D2SkillStrc;
struct D2UnitStrc;

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern D2ViewStrc* gpClientView;                                                                         // 0x007A0640
static int gbHoverLocked;                                                                              // 0x007A6A98
static int gbHasSelectedUnit;                                                                              // 0x007A6A94
static int gnSelectedUnitType;                                                                     // 0x007A6A8C
static unsigned int gnSelectedUnitId;                                                              // 0x007A6A78
extern int gnScreenWidth;                                                                               // 0x0071146C
int gbSelectionRectValid;                                                                   // 0x007A6A9C
int gnSelectionLeft;                                                                        // 0x007A6A7C
int gnSelectionRight;                                                                       // 0x007A6A84
int gnSelectionTop;                                                                         // 0x007A6A80
int gnSelectionBottom;                                                                      // 0x007A6A88
static int gbWarpTileHovered;                                                                              // 0x007A6AA0

int __cdecl TEXT_IsTextBoxOpen();                                                                                 // 0x004A0000
D2UnitStrc* __cdecl TEXT_GetTextUnit();                                                             // 0x0049E8B0
void __fastcall TEXT_SetHoverUnit(D2UnitStrc* pUnit);                                                            // 0x0049DA30
void __cdecl TEXT_ClearHoverUnit();                                                                      // 0x0049DA50
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType);                    // 0x00463990
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __fastcall VIEW_SetViewDirty(D2ViewStrc* pView);                                               // 0x00475FF0
void __fastcall MSG_SendDword(char nHeader, int nArg);                                           // 0x00478680
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                        // 0x00451FE0
int __fastcall CUNIT_IsPointInTileRect(D2UnitStrc* pUnit, int nX, int nY);                           // 0x00463EE0
int __cdecl GAME_IsLeftButtonHeld();                                                                                 // 0x0044BF30
int __cdecl GAME_GetCurrentTime(); // 0x0044DAA0
unsigned int __cdecl GAME_GetInteractDeadline(); // 0x0044DAC0
void __fastcall GAME_SetInteractDeadline(int nValue); // 0x0044DAD0
extern "C" int __cdecl PLAYER_GetScreenOffsetX();                                                          // 0x0045AFC0
extern "C" int __cdecl PLAYER_GetScreenOffsetY();                                                      // 0x0045AFD0
int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0
int __stdcall ITEMS_IsMetalItem(int nItemId);                                                               // 0x00629CC0
D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0
void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, D2UnitFindCallback pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950
int __fastcall SELECT_IsMetalItemUnit(D2UnitStrc* pUnit, void* pArg);                                    // 0x00467470
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill);                           // 0x00644140
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
void __fastcall ITEM_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY);                     // 0x004C51E0
extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY);                                                   // 0x00643260

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

static inline int CLIENT_GetUnitXInline(D2UnitStrc* pUnit)
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

static inline int CLIENT_GetUnitYInline(D2UnitStrc* pUnit)
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

struct D2HoverCoordStrc;

static inline unsigned int UNITS_GetUnitIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

struct D2SelectionRectStrc;

struct D2SelectionRectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

static inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x00466DC0
int __cdecl SELECT_GetHoverMonClassId()
{
// build: symbol ?gnHoverMonClassId@* 0x00711F90
    return gnHoverMonClassId;
}

// 0x00466DD0
int __cdecl SELECT_GetHoverClassId()
{
// build: symbol ?gnHoverClassId@* 0x00711F94
    return gnHoverClassId;
}

// 0x00466DE0
static void SELECT_SetHoverUnit(D2UnitStrc* pUnit)
{
    char szBuffer[0x200];

    if (gbHoverLocked)
    {
        return;
    }

    if (TEXT_IsTextBoxOpen() && TEXT_GetTextUnit() == pUnit)
    {
        TEXT_SetHoverUnit(pUnit);
        return;
    }

    TEXT_ClearHoverUnit();

    int bSame = 0;
    int nHoverType;
    unsigned int nHoverId;
    if (pUnit)
    {
        D2_ASSERT(sub_00466870(pUnit, 0, 0, 0), 0x4F);
        nHoverType = pUnit->dwUnitType;
        nHoverId = pUnit->dwUnitId;
    }

    if (pUnit && gbHasSelectedUnit && nHoverType == gnSelectedUnitType && nHoverId == gnSelectedUnitId)
    {
        bSame = 1;
    }

    if (!bSame && gbHasSelectedUnit && gnSelectedUnitType == 5)
    {
        D2UnitStrc* pOld = CUNIT_FindClientUnit(gnSelectedUnitId, 5);
        if (pOld)
        {
            DUNGEON_UpdateWarpRoomDeselect(UNITS_GetRoom(pOld), pOld->dwClassId);
            VIEW_SetViewDirty(gpClientView);
        }
    }

    if (!pUnit)
    {
        gbHasSelectedUnit = 0;
        return;
    }

    nHoverType = pUnit->dwUnitType;
    nHoverId = UNITS_GetUnitIdInline(pUnit);
    gnSelectedUnitType = nHoverType;
    gnSelectedUnitId = nHoverId;
    gbHasSelectedUnit = 1;

    switch (gnSelectedUnitType)
    {
    case 5:
        if (!bSame)
        {
            DUNGEON_UpdateWarpRoomSelect(UNITS_GetRoom(pUnit), !pUnit ? -1 : pUnit->dwClassId);
            VIEW_SetViewDirty(gpClientView);
        }
        break;

    case 2:
        if (!UnitIsDoor(pUnit) || pUnit->dwAnimMode == 4)
        {
            break;
        }

    {
        const unsigned int dwTick = GetTickCount();
        if (dwTick - pUnit->dwTickCount <= 0x1F4)
        {
            break;
        }

        sprintf(szBuffer, "msg at %d\n", dwTick);
        OutputDebugStringA(szBuffer);
        pUnit->dwTickCount = dwTick;
        MSG_SendDword(0x3D, gnSelectedUnitId);
        break;
    }

    case 1:
        if (!bSame)
        {
            const int nClassId = pUnit->dwClassId;
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
            if (pMonStatsTxtRecord)
            {
                D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
                if (pMonStats2TxtRecord
                    && !(pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
                    && pMonStatsTxtRecord->nAlign != 1
                    && (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[1]))
                {
                    if (!(pMonStats2TxtRecord->nFlags[2] & gdwBitMasks[1]))
                    {
// build: symbol ?gnHoverClassId@* 0x00711F94
                        gnHoverClassId = nClassId;
                    }
// build: symbol ?gnHoverMonClassId@* 0x00711F90
                    gnHoverMonClassId = nClassId;
                }
            }
        }
        break;
    }
}

// 0x00466FE0
void __cdecl SELECT_ClearSelection()
{
    gbHoverLocked = 0;
    gbHasSelectedUnit = 0;
}

// 0x00466FF0
void __cdecl SELECT_UnlockHover()
{
    gbHoverLocked = 0;
}

// 0x00467000
static int __stdcall SELECT_CheckWarpTileHover(D2UnitStrc* pPlayer, D2HoverCoordStrc tY1, int nX2, int nY2, D2UnitStrc* pUnit, int nX1, int* pnFlag)
{
    if (pUnit && pUnit->dwUnitType == UNIT_TILE
        && CUNIT_IsPointInTileRect(pUnit, nX1, tY1.nValue)
        && CUNIT_IsPointInTileRect(pUnit, nX2, nY2)
        && UNITS_IsInMovingMode(pPlayer)
        && GAME_IsLeftButtonHeld())
    {
        if (GAME_GetCurrentTime() < GAME_GetInteractDeadline())
        {
            GAME_SetInteractDeadline(GAME_GetCurrentTime() + 0x1F4);
            return 1;
        }

        if (!*pnFlag)
        {
            GAME_SetInteractDeadline(GAME_GetCurrentTime() + 0x1F4);
            *pnFlag = 1;
        }
    }

    return 0;
}

int __stdcall sub_662F_Emit_00467AC0(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nPX, int nPY, int nX, int nY)
{
    D2HoverCoordStrc tY1;
    tY1.nValue = nPY;
    return SELECT_CheckWarpTileHover(pPlayer, tY1, nX, nY, pUnit, nPX, &gbWarpTileHovered);
}

// 0x004670A0
static void __stdcall SELECT_AdjustCursorPerspective(int* pnX, int* pnY)
{
    if (sub_004F51D0_IsPerspective())
    {
        *pnY -= *pnY / 40;
        const int nHalfWidth = gnScreenWidth / 2;
        *pnX += (40 - *pnY / 4) * (*pnX - nHalfWidth) / nHalfWidth;
    }

    *pnX += PLAYER_GetScreenOffsetX();
    *pnY += PLAYER_GetScreenOffsetY();
}

static inline void HOVER_ClearHoverUnit()
{
    if (gbHoverLocked)
    {
        return;
    }

    if (TEXT_IsTextBoxOpen() && !TEXT_GetTextUnit())
    {
        TEXT_SetHoverUnit(0);
        return;
    }

    TEXT_ClearHoverUnit();
    if (gbHasSelectedUnit && gnSelectedUnitType == 5)
    {
        D2UnitStrc* pOld = CUNIT_FindClientUnit(gnSelectedUnitId, 5);
        if (pOld)
        {
            DUNGEON_UpdateWarpRoomDeselect(UNITS_GetRoom(pOld), pOld->dwClassId);
            VIEW_SetViewDirty(gpClientView);
        }
    }
    gbHasSelectedUnit = 0;
}

// 0x00467130
static int SELECT_GetHoverCursorPos(int* pnX, int* pnY)
{
    const int nMode = sub_0045AE90();
    if (nMode == 3)
    {
        if (gbHoverLocked)
        {
            goto Done;
        }

        if (TEXT_IsTextBoxOpen() && !TEXT_GetTextUnit())
        {
            TEXT_SetHoverUnit(0);
            return 1;
        }

        TEXT_ClearHoverUnit();
        if (gbHasSelectedUnit && gnSelectedUnitType == 5)
        {
            D2UnitStrc* pOld = CUNIT_FindClientUnit(gnSelectedUnitId, 5);
            if (pOld)
            {
                DUNGEON_UpdateWarpRoomDeselect(UNITS_GetRoom(pOld), !pOld ? -1 : pOld->dwClassId);
                VIEW_SetViewDirty(gpClientView);
            }
        }
        gbHasSelectedUnit = 0;
    Done:
        return 1;
    }

    *pnX = sub_00468730();
    *pnY = sub_00468740();
    const int nMaxY = gnScreenHeight - 0x31;
    if (*pnY > nMaxY)
    {
        SELECT_SetHoverUnit(0);
        return 1;
    }

    if (gbSelectionRectValid && *pnX > gnSelectionLeft && *pnX < gnSelectionRight
        && *pnY > gnSelectionTop && *pnY < gnSelectionBottom)
    {
        SELECT_SetHoverUnit(0);
        return 1;
    }

    switch (nMode)
    {
    case 2:
        if (*pnX < gnScreenWidth / 2)
        {
            SELECT_SetHoverUnit(0);
            return 1;
        }
        break;

    case 1:
        if (*pnX >= gnScreenWidth / 2)
        {
            SELECT_SetHoverUnit(0);
            return 1;
        }
        break;
    }

    SELECT_AdjustCursorPerspective(pnX, pnY);
    return 0;
}


// 0x00467250
static int __stdcall SELECT_CheckDoorSideA(D2UnitStrc* pOther, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode)
    {
        return 0;
    }

    D2CoordStrc tPlayer;
    D2CoordStrc tOther;
    D2CoordStrc tUnit;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        UNITS_GetCoords(pPlayer, &tPlayer);
    }
    else
    {
        tPlayer.nX = 0;
        tPlayer.nY = 0;
    }
    UNITS_GetCoords(pOther, &tOther);
    UNITS_GetCoords(pUnit, &tUnit);

    if (UNITS_GetObjectTxtRecordFromObject(pUnit)->nSide == 1)
    {
        if (!(((unsigned int)tUnit.nY > tOther.nY && (unsigned int)tUnit.nY < tPlayer.nY) || ((unsigned int)tUnit.nY < tOther.nY && (unsigned int)tUnit.nY > tPlayer.nY)))
        {
            return 1;
        }
    }
    else
    {
        if (!(((unsigned int)tUnit.nX < tOther.nX && (unsigned int)tUnit.nX > tPlayer.nX) || ((unsigned int)tUnit.nX > tOther.nX && (unsigned int)tUnit.nX < tPlayer.nX)))
        {
            return 1;
        }
    }
    return 0;
}


// 0x00467310
static int __stdcall SELECT_CheckDoorSideB(D2UnitStrc* pOther, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode)
    {
        return 0;
    }

    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pUnit);
    D2CoordStrc tPlayer;
    D2CoordStrc tUnit;
    D2CoordStrc tOther;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        UNITS_GetCoords(pPlayer, &tPlayer);
    }
    else
    {
        tPlayer.nX = 0;
        tPlayer.nY = 0;
    }
    UNITS_GetCoords(pUnit, &tUnit);
    UNITS_GetCoords(pOther, &tOther);

    if (pObjectsTxtRecord->nSide == 1)
    {
        if ((tOther.nY > (unsigned int)tUnit.nY && (unsigned int)tUnit.nY > tPlayer.nY) || (tOther.nY < (unsigned int)tUnit.nY && (unsigned int)tUnit.nY < tPlayer.nY))
        {
            return 1;
        }
    }
    else
    {
        if ((tOther.nX < (unsigned int)tUnit.nX && (unsigned int)tUnit.nX < tPlayer.nX) || (tOther.nX > (unsigned int)tUnit.nX && (unsigned int)tUnit.nX > tPlayer.nX))
        {
            return 1;
        }
    }
    return 0;
}

// 0x004673C0
static int SELECT_GetDistanceSquared(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    const int nDX = UNITS_GetClientCoordX(pUnit) - UNITS_GetClientCoordX(pOther);
    const int nDY = UNITS_GetClientCoordY(pUnit) - UNITS_GetClientCoordY(pOther);
    return nDY * nDY + nDX * nDX;
}

struct Unicode;


// 0x00467400
int __cdecl SELECT_HasSelectedUnit()
{
    return gbHasSelectedUnit;
}

// 0x00467430
void __fastcall SELECT_SetSelectionRect(const D2SelectionRectStrc* pRect)
{
    if (pRect)
    {
        gnSelectionLeft = pRect->nLeft;
        gnSelectionTop = pRect->nTop;
        gnSelectionRight = pRect->nRight;
        gnSelectionBottom = pRect->nBottom;
        gbSelectionRectValid = 1;
    }
    else
    {
        gbSelectionRectValid = 0;
    }
}

// 0x00467470
int __fastcall SELECT_IsMetalItemUnit(D2UnitStrc* pUnit, void* pArg)
{
    if (pUnit && pUnit->dwUnitType == UNIT_ITEM
        && ITEMS_IsMetalItem(UNITS_GetClassIdInline(pUnit)))
    {
        return 1;
    }
    return 0;
}

// 0x00467490
static D2UnitStrc* __stdcall SELECT_FindSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pUnit, int* pnX, int* pnY, D2SkillsTxt* pSkillsTxtRecord)
{
    if (pUnit)
    {
        if ((pSkillsTxtRecord->nFlags[3] & gdwBitMasks[0]) && CUNIT_IsDeadOrDying(pUnit))
        {
            return pUnit;
        }

        *pnX = CLIENT_GetUnitXInline(pUnit);
        *pnY = CLIENT_GetUnitYInline(pUnit);
    }

    int nFlags = (pSkillsTxtRecord->nFlags[3] & gdwBitMasks[0]) ? 0x3002 : 0x2003;
    D2UnitFindCallback pfnTest = 0;
    if (SKILLS_GetSkillIdFromSkill(pSkill, ".\\GAME\\Select.cpp", 0x301) == SKILL_IRONGOLEM)
    {
        if (pUnit && pUnit->dwUnitType == UNIT_ITEM)
        {
            const int nClassId = pUnit->dwClassId;
            if (ITEMS_IsMetalItem(nClassId))
            {
                return pUnit;
            }
        }
        nFlags = 0x20;
        pfnTest = SELECT_IsMetalItemUnit;
    }

    D2UnitFindArgStrc tArg;
    memset(&tArg, 0, sizeof(tArg));
    tArg.nFlags = nFlags;
    tArg.pUnit = sub_00463DE0_GetPlayerUnit();
    tArg.nX = *pnX;
    tArg.nY = *pnY;
    tArg.nSize = 9;

    D2UnitFindDataStrc tFindData;
    UNITFINDS_InitializeUnitFindData(0, &tFindData, CUNIT_GetPlayerRoom(), tArg.nX, tArg.nY, tArg.nSize, pfnTest, &tArg);
    tFindData.nFlags = nFlags;
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&tFindData);

    int nBestDistance = 10;
    for (int i = 0; i < tFindData.nIndex; ++i)
    {
        D2UnitStrc* pCandidate = tFindData.pUnitsArray[i];
        const int nDistance = UNITS_GetDistanceToCoordinates(pCandidate, *pnX, *pnY);
        if (sub_00466870(pCandidate, 0, 0, 0) && nDistance < nBestDistance)
        {
            pUnit = pCandidate;
            nBestDistance = nDistance;
        }
    }

    UNITFINDS_FreeUnitFindData(&tFindData);
    return pUnit;
}

extern const unsigned int gdwMask_006CE278;                                                                 // 0x006CE278

static inline int UNITS_IsSelectable(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 2) & 1;
    }
    return bResult;
}

struct SGAMEDATA;

// 0x00467640
int __fastcall SELECT_IsMonsterUnit(D2UnitStrc* pUnit, SGAMEDATA* pGame)
{
    if ((pUnit ? pUnit->dwUnitType : UNIT_INVALID) != 1)
    {
        return 0;
    }
    return 1;
}

// 0x00467660
static D2UnitStrc* __stdcall SELECT_FindAdjacentTarget(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit)
{
    const int nDirection = (unsigned char)UNITS_GetNewDirection(pUnit) >> 3;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    for (int i = 0; i < 5; ++i)
    {
        const int nIndex = (gaAdjacentDirOffsets[i] + nDirection) & 7;
        const int nX = gaDirectionDX[nIndex] + CLIENT_GetUnitXInline(pUnit);
        const int nY = gaDirectionDY[nIndex] + CLIENT_GetUnitYInline(pUnit);
        if (COLLISION_CheckMaskWithSize(pRoom, nX, nY, 1, 0x180))
        {
            D2UnitStrc* pTarget = D2Common_10407(pRoom, nX, nY, SELECT_IsMonsterUnit, 0, 1);
            if (UNITS_IsSelectable(pTarget))
            {
                if (!(pSkillsTxtRecord->nFlags[2] & gdwMask_006CE278)
                    || (pTarget->dwUnitType == UNIT_MONSTER && MONSTERREGION_CheckMonStats2Flag(pTarget->dwClassId, 6))
                    || CUNIT_IsHostileTo(pUnit, pTarget))
                {
                    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
                    return pTarget;
                }
            }
        }
    }

    return 0;
}

D2UnitStrc* __fastcall sub_807B_Emit_00467660(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pPlayer, int bArg)
{
    if (bArg && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        return SELECT_FindAdjacentTarget(pSkillsTxtRecord, pPlayer);
    }
    UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);
    return pPlayer;
}

// 0x004677B0
static D2UnitStrc* __stdcall SELECT_FindFreeTargetCoords(int* pnX, int* pnY, D2UnitStrc* pUnit)
{
    D2CoordStrc tCoord;
    if (pUnit)
    {
        tCoord.nX = CLIENT_GetUnitXInline(pUnit);
        tCoord.nY = CLIENT_GetUnitYInline(pUnit);
    }
    else
    {
        tCoord.nX = *pnX;
        tCoord.nY = *pnY;
    }

    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (pRoom && COLLISION_CheckMask(pRoom, tCoord.nX, tCoord.nY, 1)
        && COLLISION_GetFreeCoordinatesWithMaxDistance(pRoom, &tCoord, 1, 1, 0, 7))
    {
        *pnX = tCoord.nX;
        *pnY = tCoord.nY;
        return 0;
    }

    return pUnit;
}

// 0x00467880
D2UnitStrc* __fastcall SELECT_GetSkillTarget(D2SkillStrc* pSkill, D2UnitStrc* pUnit, int* pnX, int* pnY, unsigned char nFlags, int bArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER && CUNIT_IsDeadOrDying(pUnit))
        {
            return pUnit;
        }

        if ((pSkillsTxtRecord->nFlags[3] & gdwBitMasks[0]) || !CUNIT_IsDeadOrDying(pUnit))
        {
            goto skip;
        }

        SELECT_SetHoverUnit(0);
        *pnX = CLIENTS_GetUnitX(pUnit);
        *pnY = CLIENTS_GetUnitY(pUnit);
        pUnit = 0;
    }

    if (*pnX == CLIENT_GetUnitXInline(pPlayer) && *pnY == CLIENT_GetUnitYInline(pPlayer))
    {
        ITEM_GetAdjacentPosition(pPlayer, pnX, pnY);
    }

skip:
    if ((nFlags & 8) && (nFlags & 1) && !(nFlags & 0x20) && UNITS_IsInMovingMode(pPlayer))
    {
        return pUnit;
    }

    if (sub_004D9FC0(pPlayer, pSkill))
    {
        return pUnit;
    }

    const int nFlags6 = pSkillsTxtRecord->nFlags[2];
    if (nFlags6 & gdwBitMasks[6])
    {
        return SELECT_FindSkillTarget(pSkill, pUnit, pnX, pnY, pSkillsTxtRecord);
    }

    if (!pUnit && (nFlags6 & gdwBitMasks[5]) && bArg)
    {
        return SELECT_FindAdjacentTarget(pSkillsTxtRecord, pPlayer);
    }

    if (nFlags6 & gdwBitMasks[7])
    {
        return SELECT_FindFreeTargetCoords(pnX, pnY, pUnit);
    }

    return pUnit;
}


void __cdecl sub_E01_Emit_00467AC0(D2UnitStrc* pFirst)
{
    int nX = 0;
    int nY = 0;
    if (SELECT_GetHoverCursorPos(&nX, &nY))
    {
        return;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nPX = CLIENTS_GetUnitX(pPlayer);
    int nPY = CLIENTS_GetUnitY(pPlayer);
    DUNGEON_GameSubtileToClientCoords(&nPX, &nPY);
    D2UnitStrc* pBest = 0;
    for (D2UnitStrc* pUnit = pFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        D2HoverCoordStrc tPlayerY = { nPY };
        if (SELECT_CheckWarpTileHover(pPlayer, tPlayerY, nX, nY, pUnit, nPX, &gbWarpTileHovered))
        {
            continue;
        }
        if (!pBest)
        {
            pBest = pUnit;
            continue;
        }
        if (SELECT_CheckDoorSideA(pUnit, pBest))
        {
            pBest = pUnit;
        }
        else if (SELECT_CheckDoorSideB(pBest, pUnit))
        {
            pBest = pUnit;
        }
        else if (SELECT_GetDistanceSquared(pPlayer, pUnit) < SELECT_GetDistanceSquared(pPlayer, pBest))
        {
            pBest = pUnit;
        }
    }
    SELECT_SetHoverUnit(pBest);
}

// 0x00467A00
void __cdecl SELECT_ResetHoverClassIds()
{
    gnHoverMonClassId = 0x13;
// build: symbol ?gnHoverClassId@* 0x00711F94
    gnHoverClassId = 0x13;
}


// 0x00467A10
D2UnitStrc* __cdecl SELECT_GetSelectedUnit()
{
    if (gbHasSelectedUnit)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnSelectedUnitId, gnSelectedUnitType);
        if (pUnit && sub_00466870(pUnit, 0, 0, 0))
        {
            return pUnit;
        }
        gbHoverLocked = 0;
        gbHasSelectedUnit = 0;
        return 0;
    }

    return 0;
}


// 0x00467A70
void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        if (sub_00466870(pUnit, 0, 0, 0))
        {
            gbHoverLocked = 0;
            SELECT_SetHoverUnit(pUnit);
            gbHoverLocked = 1;
        }
        else
        {
            gbHoverLocked = 0;
            gbHasSelectedUnit = 0;
        }
    }
    else
    {
        gbHasSelectedUnit = 0;
        gbHoverLocked = 1;
    }
}


extern int gaUnitHoverPriority[];                                                                  // 0x00711F98

extern D2ActiveRoomStrc* gpHoverRoom;                                                             // 0x007A6AA4

D2UnitStrc* __cdecl SELECT_GetSelectedUnit();                                                            // 0x00467A10

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                       // 0x0063EA40

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                            // 0x00639DF0

// 0x00467AC0
void __cdecl SELECT_UpdateHoverUnit()
{
    if (gbHoverLocked)
    {
        return;
    }

    int nX = 0;
    int nY = 0;
    if (SELECT_GetHoverCursorPos(&nX, &nY))
    {
        return;
    }

    D2UnitStrc* pSelected = SELECT_GetSelectedUnit();
    if (pSelected && sub_00466870(pSelected, nX, nY, 1) && (pSelected->dwUnitType != UNIT_ITEM || !gdwGlobal_007A6A90))
    {
        SELECT_SetHoverUnit(pSelected);
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    if (gpHoverRoom != pRoom)
    {
        gbWarpTileHovered = 1;
    }
    gpHoverRoom = pRoom;

    int nPlayerX = CLIENTS_GetUnitX(pPlayer);
    int nPlayerY = CLIENTS_GetUnitY(pPlayer);
    DUNGEON_GameSubtileToClientCoords(&nPlayerX, &nPlayerY);

    D2UnitStrc* pBest = 0;
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst;
        D2UnitStrc* pPrevious = 0;
        int nCount = 0;
        for (; pUnit; pUnit = pUnit->ptRoomNext)
        {
            const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
            if (nUnitType == 3)
            {
                continue;
            }

            if (pPrevious == pUnit)
            {
                break;
            }
            pPrevious = pUnit;

            D2_ASSERT(nCount++ <= 30000, 0x218);

            if (pUnit == pPlayer)
            {
                continue;
            }

            D2HoverCoordStrc tPlayerY = { nPlayerY };
            if (SELECT_CheckWarpTileHover(pPlayer, tPlayerY, nX, nY, pUnit, nPlayerX, &gbWarpTileHovered))
            {
                continue;
            }

            if (pUnit && pUnit->dwUnitType == UNIT_ITEM && gdwGlobal_007A6A90)
            {
                continue;
            }

            if (!sub_00466870(pUnit, nX, nY, 1))
            {
                continue;
            }

            if (pSelected == pUnit && !CUNIT_IsDeadOrDying(pUnit))
            {
                pBest = pUnit;
                break;
            }

            if (!pBest)
            {
                pBest = pUnit;
                continue;
            }

            const int nBestType = pBest->dwUnitType;
            int nPriority = gaUnitHoverPriority[nUnitType];
            int nBestPriority = gaUnitHoverPriority[nBestType];
            if (nUnitType == 0)
            {
                if (CUNIT_IsDeadOrDying(pUnit))
                {
                    nPriority = 1;
                }
            }
            else if (nUnitType == 1)
            {
                if (MONSTERS_IsDead(pUnit))
                {
                    nPriority = -8;
                }

                if (STATES_CheckState(pUnit, STATE_ATTACHED))
                {
                    continue;
                }
            }

            if (nBestType == 1 && MONSTERS_IsDead(pBest))
            {
                nBestPriority = -8;
            }

            if (nUnitType != 2)
            {
                if (nBestType == 2)
                {
                    if (UnitIsDoor(pBest))
                    {
                        if (SELECT_CheckDoorSideA(pUnit, pBest))
                        {
                            pBest = pUnit;
                        }
                        continue;
                    }
                    goto NonDoorA;
                }
            }
            else if (nBestType != 2)
            {
                if (UnitIsDoor(pUnit))
                {
                    if (SELECT_CheckDoorSideB(pBest, pUnit) && nBestPriority < nPriority)
                    {
                        pBest = pUnit;
                    }
                }
                else if (nBestPriority < nPriority)
                {
                    pBest = pUnit;
                }
                continue;
            }

            if (nBestPriority != nPriority)
            {
                if (nBestPriority < nPriority)
                {
                    pBest = pUnit;
                }
            }
            else if (SELECT_GetDistanceSquared(pPlayer, pUnit) < SELECT_GetDistanceSquared(pPlayer, pBest))
            {
                pBest = pUnit;
            }
            continue;

NonDoorA:
            if (nBestPriority < nPriority)
            {
                pBest = pUnit;
            }
        }
    }

    SELECT_SetHoverUnit(pBest);
}


#include "gen/data/Source/D2Client/GAME/Select.inc"
